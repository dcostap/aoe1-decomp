// GLOBAL FUNCTIONS PART 3400
// Function: FUN_0049cde3
// Address: 0049cde3
// XREFS: None
void FUN_0049cde3(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_0049ce35
// Address: 0049ce35
// XREFS: None
void __fastcall FUN_0049ce35(int *param_1)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar2 == 0) {
    piVar1 = (int *)param_1[0x15f];
    if (piVar1[0x1b] == 0) {
      (**(code **)(*piVar1 + 0x14))(1);
    }
    else {
      (**(code **)(*piVar1 + 0x14))(0);
    }
    iVar2 = *param_1;
    (**(code **)(iVar2 + 0x50))(param_1[5],param_1[6]);
    (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    (**(code **)(iVar2 + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049ce98
// Address: 0049ce98
// XREFS: None
void FUN_0049ce98(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0049cea1
// Address: 0049cea1
// XREFS: None
void FUN_0049cea1(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0049ceb3
// Address: 0049ceb3
// XREFS: None
// [HELPER] production_queues_is_use: ""
void __thiscall FUN_0049ceb3(int param_1,short param_2,short param_3)
{
  uchar uVar1;
  int iVar2;
  TRIBE_Player *pTVar3;
  short sVar4;
  short *psVar5;
  float fVar6;
  short asStack_202 [257];
  
  iVar2 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar2 == 0) {
    if (production_queues_is_use != '\0') {
      TRIBE_Command::command_queue
                (*(TRIBE_Command **)(*(int *)(param_1 + 0x5b4) + 0x58),
                 *(RGE_Static_Object **)(param_1 + 0x5c8),param_2,param_3);
      return;
    }
    iVar2 = 0;
    psVar5 = asStack_202;
    fVar6 = 1.0;
    sVar4 = param_2;
    pTVar3 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    uVar1 = TRIBE_Player::check_obj_cost(pTVar3,sVar4,psVar5,fVar6,iVar2);
    if (uVar1 != '\0') {
      rge_base_game->master_obj_id = param_2;
      pTVar3 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
      TRIBE_Player::command_building_make_obj(pTVar3,param_2);
      return;
    }
    (**(code **)(rge_base_game->_padding_ + 0x28))(0x67,1,(int)asStack_202[0]);
    TMessagePanel::show_message
              (*(TMessagePanel **)(param_1 + 0x544),BadMessage,&stack0xfffffdec,'V','\0',(void *)0x0
               ,0,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049cfe3
// Address: 0049cfe3
// XREFS: None
void __fastcall FUN_0049cfe3(TPanel *param_1)
{
  void *pvVar1;
  char *pcVar2;
  uchar uVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  
  pvVar1 = (void *)RGE_Base_Game::get_paused(rge_base_game);
  if (pvVar1 == (void *)0x0) {
    uVar3 = '2';
    pvVar4 = pvVar1;
    pvVar5 = pvVar1;
    pvVar6 = pvVar1;
    pcVar2 = TPanel::get_string(param_1,0xbed);
    TMessagePanel::show_message
              ((TMessagePanel *)param_1[5].handle_mouse_input,BadMessage,pcVar2,uVar3,(uchar)pvVar1,
               pvVar4,(long)pvVar5,(long)pvVar6);
    (**(code **)(rge_base_game->_padding_ + 0x10))(0x69,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d033
// Address: 0049d033
// XREFS: None
void __fastcall FUN_0049d033(int param_1)
{
  int iVar1;
  RGE_Player *pRVar2;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    pRVar2 = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::unselect_object(pRVar2);
    pRVar2 = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::unselect_area(pRVar2);
    (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d085
// Address: 0049d085
// XREFS: None
void FUN_0049d085(void)
{
  RGE_Static_Object *pRVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  RGE_Player *pRVar5;
  float fVar6;
  float fVar7;
  
  iVar4 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar4 == 0) {
    pRVar5 = RGE_Base_Game::get_player(rge_base_game);
    pRVar1 = pRVar5->selected_obj;
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      fVar7 = pRVar1->world_y;
      fVar6 = pRVar1->world_x;
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::set_view_loc(pRVar5,fVar6,fVar7);
      sVar2 = __ftol();
      sVar3 = __ftol();
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::set_map_loc(pRVar5,sVar3,sVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d0f5
// Address: 0049d0f5
// XREFS: None
void __fastcall FUN_0049d0f5(int param_1)
{
  short sVar1;
  short sVar2;
  RGE_Static_Object *pRVar3;
  TRIBE_Player *this;
  RGE_Player *pRVar4;
  float fVar5;
  RGE_Static_Object *pRVar6;
  float fVar7;
  
  pRVar3 = (RGE_Static_Object *)RGE_Base_Game::get_paused(rge_base_game);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    sVar1 = 0x6d;
    this = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    pRVar3 = TRIBE_Player::find_obj(this,sVar1,pRVar3);
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::unselect_object(pRVar4);
      pRVar6 = pRVar3;
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::select_object(pRVar4,pRVar6);
      fVar7 = pRVar3->world_y;
      fVar5 = pRVar3->world_x;
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::set_view_loc(pRVar4,fVar5,fVar7);
      sVar1 = __ftol();
      sVar2 = __ftol();
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::set_map_loc(pRVar4,sVar2,sVar1);
      (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d1a5
// Address: 0049d1a5
// XREFS: None
void __fastcall FUN_0049d1a5(int param_1)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::allowCheatCodes(rge_base_game);
  if (iVar1 != 0) {
    RGE_Base_Game::set_map_visible
              (rge_base_game,*(char *)(*(int *)(*(int *)(param_1 + 0x5b4) + 0x28) + 0x8db8) == '\0')
    ;
    (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(2);
    (**(code **)(**(int **)(param_1 + 0x4bc) + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d282
// Address: 0049d282
// XREFS: None
void FUN_0049d282(undefined4 param_1)
{
  int iVar1;
  RGE_Player *pRVar2;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    pRVar2 = RGE_Base_Game::get_player(rge_base_game);
    (**(code **)(pRVar2->_padding_ + 0xbc))(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d2bc
// Address: 0049d2bc
// XREFS: None
void FUN_0049d2bc(void)
{
  int iVar1;
  RGE_Player *pRVar2;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    pRVar2 = RGE_Base_Game::get_player(rge_base_game);
                    /* WARNING: Could not recover jumptable at 0x0049d2de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(pRVar2->_padding_ + 0xc0))();
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d2e5
// Address: 0049d2e5
// XREFS: None
void __fastcall FUN_0049d2e5(TPanel *param_1)
{
  void *pvVar1;
  char *pcVar2;
  uchar uVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  
  pvVar1 = (void *)RGE_Base_Game::get_paused(rge_base_game);
  if (pvVar1 == (void *)0x0) {
    uVar3 = '2';
    pvVar4 = pvVar1;
    pvVar5 = pvVar1;
    pvVar6 = pvVar1;
    pcVar2 = TPanel::get_string(param_1,0xbe5);
    TMessagePanel::show_message
              ((TMessagePanel *)param_1[5].handle_mouse_input,BadMessage,pcVar2,uVar3,(uchar)pvVar1,
               pvVar4,(long)pvVar5,(long)pvVar6);
    (**(code **)(rge_base_game->_padding_ + 0x10))(100,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d333
// Address: 0049d333
// XREFS: None
void FUN_0049d333(long param_1)
{
  int iVar1;
  TRIBE_Player *this;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    this = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    TRIBE_Player::command_trade_attribute(this,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d369
// Address: 0049d369
// XREFS: None
void FUN_0049d369(int param_1)
{
  short sVar1;
  bool bVar2;
  RGE_Player *pRVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  RGE_Static_Object *pRVar7;
  RGE_Static_Object *pRVar8;
  
  pRVar3 = RGE_Base_Game::get_player(rge_base_game);
  bVar2 = false;
  pRVar7 = (RGE_Static_Object *)0x0;
  iVar4 = RGE_Base_Game::get_paused(rge_base_game);
  if ((iVar4 == 0) && (sVar1 = pRVar3->sel_count, 1 < sVar1)) {
    if (param_1 == 0) {
      sVar5 = 0;
      sVar6 = 0;
      do {
        if (sVar1 <= sVar6) break;
        pRVar8 = pRVar3->sel_list[sVar5];
        if (pRVar8 != (RGE_Static_Object *)0x0) {
          if ((pRVar8 == pRVar3->selected_obj) &&
             (pRVar8 = pRVar7, pRVar7 != (RGE_Static_Object *)0x0)) goto LAB_0049d42a;
          sVar6 = sVar6 + 1;
          pRVar7 = pRVar8;
        }
        sVar5 = sVar5 + 1;
      } while (sVar5 < 0x19);
    }
    else {
      sVar5 = 0;
      sVar6 = 0;
      do {
        if (sVar1 <= sVar6) break;
        pRVar8 = pRVar3->sel_list[sVar5];
        if (pRVar8 != (RGE_Static_Object *)0x0) {
          if (pRVar8 == pRVar3->selected_obj) {
            bVar2 = true;
          }
          else {
            if (bVar2) {
              pRVar7 = pRVar3->sel_list[sVar5];
              break;
            }
            if (pRVar7 == (RGE_Static_Object *)0x0) {
              pRVar7 = pRVar8;
            }
          }
          sVar6 = sVar6 + 1;
        }
        sVar5 = sVar5 + 1;
      } while (sVar5 < 0x19);
    }
    if (pRVar7 != (RGE_Static_Object *)0x0) {
LAB_0049d42a:
      pRVar3->selected_obj = pRVar7;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049d437
// Address: 0049d437
// XREFS: None
undefined4 FUN_0049d437(void)
{
  byte bVar1;
  RGE_Action_Object *this;
  uchar uVar2;
  RGE_Player *pRVar3;
  int iVar4;
  RGE_Static_Object **ppRVar5;
  int iVar6;
  
  pRVar3 = RGE_Base_Game::get_player(rge_base_game);
  iVar6 = 0;
  iVar4 = 0;
  ppRVar5 = pRVar3->sel_list;
  do {
    if (pRVar3->sel_count <= iVar4) {
      return 0;
    }
    this = (RGE_Action_Object *)*ppRVar5;
    if (this != (RGE_Action_Object *)0x0) {
      bVar1 = *(byte *)(this->_padding_ + 4);
      if ((0x27 < bVar1) && (bVar1 < 0x51)) {
        uVar2 = RGE_Action_Object::have_action(this);
        if (uVar2 != '\0') {
          return 1;
        }
      }
      iVar4 = iVar4 + 1;
    }
    iVar6 = iVar6 + 1;
    ppRVar5 = ppRVar5 + 1;
  } while (iVar6 < 0x19);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0049d4a5
// Address: 0049d4a5
// XREFS: None
void __thiscall FUN_0049d4a5(TScreenPanel *param_1,int param_2)
{
  TScreenPanel::set_focus(param_1,param_2);
  if (*(int *)&param_1->field_0x78 != 0) {
    RGE_Base_Game::set_windows_mouse(rge_base_game,0);
    return;
  }
  RGE_Base_Game::set_windows_mouse(rge_base_game,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0049d4e6
// Address: 0049d4e6
// XREFS: None
void __fastcall FUN_0049d4e6(TPanel *param_1)
{
  TDigital *this;
  
  this = (TDigital *)param_1[8].pnl_hgt;
  if (this != (TDigital *)0x0) {
    TDigital::~TDigital(this);
    operator_delete(this);
    param_1[8].pnl_hgt = 0;
  }
  TPanel::stop_sound_system(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0049d522
// Address: 0049d522
// XREFS: None
undefined4 __fastcall FUN_0049d522(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  for (puVar1 = *(undefined4 **)(param_1 + 0x58); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[2]) {
    iVar2 = (**(code **)(*(int *)*puVar1 + 0xd4))();
    if (iVar2 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_0049d535
// Address: 0049d535
// XREFS: None
void FUN_0049d535(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0049d543
// Address: 0049d543
// XREFS: None
TScreenPanel * __thiscall
FUN_0049d543(TScreenPanel *param_1,char *param_2,char *param_3,long param_4,int param_5)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ef28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel(param_1,param_2);
  *(int *)&param_1[1].field_0x4 = param_5;
  uStack_4 = 0;
  *(undefined ***)param_1 = &TRIBE_Screen_Info::_vftable_;
  *(uint *)(param_1 + 1) = (uint)(param_5 != 0);
  *(undefined4 *)&param_1[1].field_0x8 = 0;
  lVar1 = TScreenPanel::setup(param_1,rge_base_game->draw_area,param_3,param_4,0);
  if (lVar1 == 0) {
    *(undefined4 *)&param_1->field_0xd8 = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049d5de
// Address: 0049d5de
// XREFS: None
TRIBE_Screen_Info * __thiscall FUN_0049d5de(TRIBE_Screen_Info *param_1,byte param_2)
{
  TRIBE_Screen_Info::~TRIBE_Screen_Info(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049d5fe
// Address: 0049d5fe
// XREFS: None
void __fastcall FUN_0049d5fe(TScreenPanel *param_1)
{
  *(undefined ***)param_1 = &TRIBE_Screen_Info::_vftable_;
  TScreenPanel::~TScreenPanel(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0049d60b
// Address: 0049d60b
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_info_c: "C:\msdev\work\age1_x1\scr_info.cpp"
long __fastcall FUN_0049d60b(TRIBE_Screen_Info *param_1)
{
  ulong uVar1;
  long lVar2;
  
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  if (param_1->auto_close != 0) {
    if (param_1->last_time == 0) {
      uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_info_c,0x48);
      param_1->last_time = uVar1;
      lVar2 = TPanel::handle_idle((TPanel *)param_1);
      return lVar2;
    }
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_info_c,0x4b);
    if (param_1->timer < uVar1 - param_1->last_time) {
      TRIBE_Screen_Info::close_screen(param_1);
      return 0;
    }
  }
  lVar2 = TPanel::handle_idle((TPanel *)param_1);
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_0049d68f
// Address: 0049d68f
// XREFS: None
undefined4 __thiscall FUN_0049d68f(TRIBE_Screen_Info *param_1,int param_2)
{
  if (((param_2 != 0x12) && (param_2 != 0x11)) && (param_2 != 0x10)) {
    TRIBE_Screen_Info::close_screen(param_1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0049d6ad
// Address: 0049d6ad
// XREFS: None
undefined4 __fastcall FUN_0049d6ad(TRIBE_Screen_Info *param_1)
{
  TRIBE_Screen_Info::close_screen(param_1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0049d6ba
// Address: 0049d6ba
// XREFS: None
void __thiscall
FUN_0049d6ba(TEasy_Panel *param_1,TPanel *param_2,long param_3,ulong param_4,ulong param_5)
{
  TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0049d6dc
// Address: 0049d6dc
// XREFS: None
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
void __fastcall FUN_0049d6dc(int param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  TribeSPMenuScreen *pTVar4;
  TRIBE_Screen_Info *pTVar5;
  TRIBE_Screen_Main_Menu *this;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 *unaff_FS_OFFSET;
  bool bVar8;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055efa3;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pbVar6 = *(byte **)(param_1 + 0x1c);
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
    uStack_4 = 0;
    if (pTVar4 != (TribeSPMenuScreen *)0x0) {
      TribeSPMenuScreen::TribeSPMenuScreen(pTVar4);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Single_Player_Menu,0);
    TPanelSystem::destroyPanel(&panel_system,&s_RandomMap);
    *unaff_FS_OFFSET = uStack_c;
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
    uStack_4 = 1;
    if (pTVar4 != (TribeSPMenuScreen *)0x0) {
      TribeSPMenuScreen::TribeSPMenuScreen(pTVar4);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Single_Player_Menu,0);
    TPanelSystem::destroyPanel(&panel_system,&s_DeathMatch);
    *unaff_FS_OFFSET = uStack_c;
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
    uStack_4 = 2;
    if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
      TRIBE_Screen_Info::TRIBE_Screen_Info(pTVar5,&s_Logo2Screen,s_scrlogo2,0xc392,2000);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,&s_Logo2Screen,0);
    *unaff_FS_OFFSET = uStack_c;
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
      uStack_4 = 3;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info::TRIBE_Screen_Info(pTVar5,&s_UnitInfo1,s_scrunit1,0xc394,0);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,&s_UnitInfo1,0);
      TPanelSystem::destroyPanel(&panel_system,&s_ScenarioEditorInfo);
      *unaff_FS_OFFSET = uStack_c;
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
      uStack_4 = 4;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info::TRIBE_Screen_Info(pTVar5,&s_UnitInfo2,s_scrunit2,0xc395,0);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,&s_UnitInfo2,0);
      TPanelSystem::destroyPanel(&panel_system,&s_UnitInfo1);
      *unaff_FS_OFFSET = uStack_c;
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
      uStack_4 = 5;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info::TRIBE_Screen_Info(pTVar5,&s_UnitInfo3,s_scrunit3,0xc396,0);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,&s_UnitInfo3,0);
      TPanelSystem::destroyPanel(&panel_system,&s_UnitInfo2);
      *unaff_FS_OFFSET = uStack_c;
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
      this = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
      uStack_4 = 6;
      if (this != (TRIBE_Screen_Main_Menu *)0x0) {
        TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
      TPanelSystem::destroyPanel(&panel_system,&s_UnitInfo3);
      *unaff_FS_OFFSET = uStack_c;
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
      uStack_4 = 7;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info::TRIBE_Screen_Info(pTVar5,&s_TechInfo,s_scrtech,0xc393,0);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,&s_TechInfo,0);
      TPanelSystem::destroyPanel(&panel_system,&s_FeaturesInfo);
      *unaff_FS_OFFSET = uStack_c;
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
      uStack_4 = 8;
      if (pTVar5 != (TRIBE_Screen_Info *)0x0) {
        TRIBE_Screen_Info::TRIBE_Screen_Info(pTVar5,s_QuotesInfo,s_scrinfqu,0xc38f,0);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_QuotesInfo,0);
      TPanelSystem::destroyPanel(&panel_system,&s_TechInfo);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
  }
  RGE_Base_Game::close(rge_base_game);
LAB_0049d922:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049dd3c
// Address: 0049dd3c
// XREFS: None
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
TribeLoadSavedGameScreen * __fastcall FUN_0049dd3c(TribeLoadSavedGameScreen *param_1)
{
  TListPanel **ppTVar1;
  TButtonPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  char cVar4;
  TDrawArea *pTVar5;
  TButtonPanel *pTVar6;
  TEasy_Panel *this;
  char *pcVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  int iVar12;
  TListPanel *pTStack_124;
  TButtonPanel *pTStack_120;
  TButtonPanel *pTStack_11c;
  TButtonPanel *pTStack_118;
  TribeLoadSavedGameScreen *pTStack_114;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055efbb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_114 = param_1;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Load_Saved_Game_Screen);
  ppTVar1 = &param_1->list;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeLoadSavedGameScreen::_vftable_;
  param_1->screenTitle = (TTextPanel *)0x0;
  param_1->listTitle = (TTextPanel *)0x0;
  *ppTVar1 = (TListPanel *)0x0;
  param_1->scrollbar = (TScrollBarPanel *)0x0;
  param_1->okButton = (TButtonPanel *)0x0;
  param_1->cancelButton = (TButtonPanel *)0x0;
  param_1->deleteButton = (TButtonPanel *)0x0;
  this = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  pcVar7 = TEasy_Panel::get_info_file(this);
  uVar9 = 0xffffffff;
  do {
    pcVar11 = pcVar7;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar11 = pcVar7 + 1;
    cVar4 = *pcVar7;
    pcVar7 = pcVar11;
  } while (cVar4 != '\0');
  uVar9 = ~uVar9;
  iVar12 = 1;
  pcVar7 = pcVar11 + -uVar9;
  pcVar11 = acStack_110;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar11 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar11 = pcVar11 + 1;
  }
  pTVar5 = rge_base_game->draw_area;
  lVar8 = TEasy_Panel::get_info_id(this);
  lVar8 = TScreenPanel::setup((TScreenPanel *)param_1,pTVar5,acStack_110,lVar8,iVar12);
  if (lVar8 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
    iVar12 = TEasy_Panel::create_text
                       ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->screenTitle,0x24ff,0x14,
                        10,600,0x1e,1,1,0,0);
    if (iVar12 != 0) {
      iVar12 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->listTitle,0x2502,0x14,
                          0x2d,600,0x14,4,0,0,0);
      if (iVar12 != 0) {
        iVar12 = TEasy_Panel::create_list
                           ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x14,0x41,600,0x160,0xb
                           );
        if (iVar12 != 0) {
          iVar12 = TEasy_Panel::create_auto_scrollbar
                             ((TEasy_Panel *)param_1,&param_1->scrollbar,(TTextPanel *)*ppTVar1,0x14
                             );
          if (iVar12 != 0) {
            TPanel::set_help_info((TPanel *)param_1->scrollbar,0x7670,-1);
            ppTVar2 = &param_1->okButton;
            iVar12 = TEasy_Panel::create_button
                               ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,0xfa1,0,0x1e,0x1b8,
                                0xb4,0x1e,0,0,0);
            if (iVar12 != 0) {
              iVar12 = TEasy_Panel::create_button
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->deleteButton,
                                  0x24c9,0,0xe6,0x1b8,0xb4,0x1e,0,0,0);
              if (iVar12 != 0) {
                ppTVar3 = &param_1->cancelButton;
                iVar12 = TEasy_Panel::create_button
                                   ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar3,0xfa2,0,0x1ae,
                                    0x1b8,0xb4,0x1e,0,0,0);
                if (iVar12 != 0) {
                  TPanel::set_help_info((TPanel *)*ppTVar2,0x7531,-1);
                  TPanel::set_help_info((TPanel *)*ppTVar3,0x7532,-1);
                  pTVar6 = *ppTVar3;
                  pTVar6->hotkey = 0x1b;
                  pTVar6->hotkey_shift = 0;
                  pTVar6 = param_1->deleteButton;
                  pTVar6->hotkey_shift = 0;
                  pTVar6->hotkey = 0x2e;
                  TribeLoadSavedGameScreen::fillList(param_1);
                  pcVar7 = TTextPanel::currentLine((TTextPanel *)*ppTVar1);
                  if (*pcVar7 == '\0') {
                    TButtonPanel::set_disabled(*ppTVar2,1);
                    TButtonPanel::set_disabled(param_1->deleteButton,1);
                  }
                  pcVar7 = TRIBE_Game::get_save_game_name((TRIBE_Game *)rge_base_game);
                  lVar8 = TTextPanel::get_line((TTextPanel *)*ppTVar1,pcVar7);
                  if (lVar8 != -1) {
                    TListPanel::scroll_cur_line(*ppTVar1,'\x01',(short)lVar8,1);
                  }
                  TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*ppTVar1);
                  pTStack_120 = *ppTVar2;
                  pTStack_124 = *ppTVar1;
                  pTStack_11c = param_1->deleteButton;
                  pTStack_118 = *ppTVar3;
                  TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_124,4);
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049e076
// Address: 0049e076
// XREFS: None
TribeLoadSavedGameScreen * __thiscall FUN_0049e076(TribeLoadSavedGameScreen *param_1,byte param_2)
{
  TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049e09e
// Address: 0049e09e
// XREFS: None
void __fastcall FUN_0049e09e(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055efd8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeLoadSavedGameScreen::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x10);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x18);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049e14a
// Address: 0049e14a
// XREFS: None
// [HELPER] s__s__gam: "%s*.gam"
// [HELPER] s__s__gmx: "%s*.gmx"
void __fastcall FUN_0049e14a(int param_1)
{
  char cVar1;
  TTextPanel *pTVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char acStack_21c [260];
  undefined1 auStack_118 [20];
  char acStack_104 [260];
  
  TTextPanel::empty_list(*(TTextPanel **)(param_1 + 0x480));
  *(undefined4 *)(*(int *)(param_1 + 0x480) + 0x15c) = 1;
  sprintf(acStack_21c,s__s__gam,rge_base_game->prog_info->save_dir);
  iVar3 = __findfirst(acStack_21c,auStack_118);
  iVar4 = iVar3;
  while (iVar4 != -1) {
    uVar5 = 0xffffffff;
    pcVar6 = acStack_104;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    strncpy(acStack_21c,acStack_104,~uVar5 - 5);
    pTVar2 = *(TTextPanel **)(param_1 + 0x480);
    acStack_21c[~uVar5 - 5] = '\0';
    TTextPanel::append_line(pTVar2,acStack_21c,0);
    iVar4 = __findnext(iVar3,auStack_118);
  }
  sprintf(acStack_21c,s__s__gmx,rge_base_game->prog_info->save_dir);
  iVar3 = __findfirst(acStack_21c,auStack_118);
  iVar4 = iVar3;
  do {
    if (iVar4 == -1) {
      return;
    }
    uVar5 = 0xffffffff;
    pcVar6 = acStack_104;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    strncpy(acStack_21c,acStack_104,~uVar5 - 5);
    pTVar2 = *(TTextPanel **)(param_1 + 0x480);
    acStack_21c[~uVar5 - 5] = '\0';
    TTextPanel::append_line(pTVar2,acStack_21c,0);
    iVar4 = __findnext(iVar3,auStack_118);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0049e2d1
// Address: 0049e2d1
// XREFS: None
// [HELPER] s_Cancel_Dialog: "Cancel Dialog"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s__s_gam: "%s.gam"
// [HELPER] s__s_gmx: "%s.gmx"
// [HELPER] s__s_s_gam: "%s%s.gam"
// [HELPER] s__s_s_gmx: "%s%s.gmx"
long __thiscall
FUN_0049e2d1(TEasy_Panel *param_1,TTextPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  char cVar1;
  byte bVar2;
  RGE_Prog_Info *pRVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  long lVar7;
  TPanel *pTVar8;
  TribeSPMenuScreen *this;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  bool bVar13;
  char acStack_440 [260];
  char acStack_33c [260];
  char acStack_238 [556];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055effe;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != (TTextPanel *)0x0) {
    pcVar4 = TPanel::panelName((TPanel *)param_2);
    if (pcVar4 != (char *)0x0) {
      pbVar11 = &s_Cancel_Dialog;
      pbVar5 = (byte *)TPanel::panelName((TPanel *)param_2);
      do {
        bVar2 = *pbVar5;
        bVar13 = bVar2 < *pbVar11;
        if (bVar2 != *pbVar11) {
LAB_0049e356:
          iVar6 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          goto LAB_0049e35b;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar13 = bVar2 < pbVar11[1];
        if (bVar2 != pbVar11[1]) goto LAB_0049e356;
        pbVar5 = pbVar5 + 2;
        pbVar11 = pbVar11 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_0049e35b:
      if (iVar6 != 0) goto LAB_0049e444;
      TPanelSystem::destroyPanel(&panel_system,&s_Cancel_Dialog);
      if (param_3 == 0) {
        pRVar3 = rge_base_game->prog_info;
        pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1[1]._padding_);
        sprintf(acStack_440,s__s_s_gam,pRVar3->save_dir,pcVar4);
        __unlink(acStack_440);
        pRVar3 = rge_base_game->prog_info;
        pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1[1]._padding_);
        sprintf(acStack_440,s__s_s_gmx,pRVar3->save_dir,pcVar4);
        __unlink(acStack_440);
        lVar7 = TTextPanel::get_line((TTextPanel *)param_1[1]._padding_);
        TTextPanel::delete_line((TTextPanel *)param_1[1]._padding_,lVar7);
        pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1[1]._padding_);
        if (*pcVar4 == '\0') {
          TButtonPanel::set_disabled((TButtonPanel *)param_1[1]._padding_,1);
          TButtonPanel::set_disabled((TButtonPanel *)param_1[1]._padding_,1);
          lVar7 = 1;
          goto LAB_0049e6b2;
        }
      }
      goto LAB_0049e692;
    }
LAB_0049e444:
    if ((param_2 == (TTextPanel *)param_1[1]._padding_) && (param_3 == 1)) {
      pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1[1]._padding_);
      if (*pcVar4 != '\0') {
        TPanel::get_string((TPanel *)param_1,0x24ca,acStack_440,0x100);
        pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1[1]._padding_);
        sprintf(acStack_238,acStack_440,pcVar4);
        TEasy_Panel::popupYesNoDialog(param_1,acStack_238,&s_Cancel_Dialog,0x1c2,100);
      }
    }
    if (param_2 != (TTextPanel *)param_1[1]._padding_) {
      if (param_2 == (TTextPanel *)param_1[1]._padding_) {
        if (param_3 != 1) goto LAB_0049e699;
        iVar6 = TTextPanel::numberLines((TTextPanel *)param_1[1]._padding_);
        if (0 < iVar6) {
          pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1[1]._padding_);
          uVar9 = 0xffffffff;
          do {
            pcVar12 = pcVar4;
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            pcVar12 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar12;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          pcVar4 = pcVar12 + -uVar9;
          pcVar12 = acStack_33c;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar12 = *(undefined4 *)pcVar4;
            pcVar4 = pcVar4 + 4;
            pcVar12 = pcVar12 + 4;
          }
          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar12 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            pcVar12 = pcVar12 + 1;
          }
          sprintf(acStack_440,s__s_s_gmx,rge_base_game->prog_info->save_dir,acStack_33c);
          iVar6 = __findfirst(acStack_440,acStack_238);
          if (iVar6 == -1) {
            pcVar4 = s__s_gam;
          }
          else {
            pcVar4 = s__s_gmx;
          }
          sprintf(acStack_440,pcVar4,acStack_33c);
          iVar6 = TRIBE_Game::load_game((TRIBE_Game *)rge_base_game,acStack_440);
          if (iVar6 == 0) {
            TEasy_Panel::popupOKDialog(param_1,0x2501,(char *)0x0,0x1c2,100);
            lVar7 = 1;
            goto LAB_0049e6b2;
          }
        }
      }
      else {
        if ((param_2 != (TTextPanel *)param_1[1]._padding_) || (param_3 != 1)) goto LAB_0049e699;
        pTVar8 = TPanelSystem::panel(&panel_system,s_Game_Screen);
        if (pTVar8 == (TPanel *)0x0) {
          RGE_Base_Game::disable_input(rge_base_game);
          this = (TribeSPMenuScreen *)operator_new(0x49c);
          uStack_4 = 0;
          if (this != (TribeSPMenuScreen *)0x0) {
            TribeSPMenuScreen::TribeSPMenuScreen(this);
          }
          uStack_4 = 0xffffffff;
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
    if (param_3 == 3) {
      (**(code **)(param_1->_padding_ + 0xb4))(param_1[1]._padding_,1,0,0);
      lVar7 = 1;
      goto LAB_0049e6b2;
    }
  }
LAB_0049e699:
  lVar7 = TEasy_Panel::action(param_1,(TPanel *)param_2,param_3,param_4,param_5);
LAB_0049e6b2:
  *unaff_FS_OFFSET = uStack_c;
  return lVar7;
}

// --------------------------------------------------

// Function: FUN_0049e6cd
// Address: 0049e6cd
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s__: "}"
// [HELPER] s_circlep2: "circlep2"
// [HELPER] s_scr1: "scr1"
TEasy_Panel * __fastcall FUN_0049e6cd(TEasy_Panel *param_1)
{
  char cVar1;
  long lVar2;
  int iVar3;
  TPicturePanel *pTVar4;
  long lVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int unaff_EDI;
  int *piVar11;
  char *pcVar12;
  char *pcVar13;
  TPanel **ppTVar14;
  undefined4 *unaff_FS_OFFSET;
  long lVar15;
  long lVar16;
  long lVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  tagRECT tStack_234;
  TEasy_Panel *pTStack_224;
  TPanel *apTStack_220 [5];
  char acStack_20c [512];
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f029;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_224 = param_1;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Main_Menu);
  piVar10 = &param_1[1]._padding_;
  param_1->_padding_ = (int)&TRIBE_Screen_Main_Menu::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  iStack_4 = 0;
  piVar11 = piVar10;
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar11 = 0;
    piVar11 = piVar11 + 1;
  }
  lVar2 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,s_scr1,0xc383,1);
  if (lVar2 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
    iVar7 = 0xb2;
    do {
      iVar3 = TEasy_Panel::create_button
                        (param_1,(TPanel *)param_1,(TButtonPanel **)piVar10,s_,(char *)0x0,0xaa,
                         iVar7,300,0x28,0,0,0);
      if (iVar3 == 0) goto LAB_0049ebb6;
      iVar7 = iVar7 + 0x32;
      piVar10 = piVar10 + 1;
    } while (iVar7 < 0x1ac);
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x23f2);
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x23f3);
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x23f5);
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x23f6);
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x23f7);
    TEasy_Panel::set_ideal_size(param_1,param_1->_padding_,param_1->_padding_);
    iVar7 = param_1->_padding_;
    TEasy_Panel::create_text
              (param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x2419,5,iVar7 + -0x3c
               ,param_1->_padding_ + -10,0x12,10,1,0,0);
    TPanel::get_string((TPanel *)param_1,0x2424,acStack_20c,0x200);
    if (acStack_20c[0] == '\0') {
      piVar10 = &param_1[1]._padding_;
      TEasy_Panel::create_text
                (param_1,(TPanel *)param_1,(TTextPanel **)piVar10,0x241b,5,iVar7 + -0x2a,0x32,0x12,
                 10,0,0,0);
      iVar3 = TTextPanel::get_text_rect((TTextPanel *)*piVar10,&tStack_234);
      if (iVar3 != 0) {
        pTVar4 = (TPicturePanel *)operator_new(0x11c);
        iStack_4._0_1_ = 1;
        if (pTVar4 == (TPicturePanel *)0x0) {
          pTVar4 = (TPicturePanel *)0x0;
        }
        else {
          pTVar4 = (TPicturePanel *)TPicturePanel::TPicturePanel(pTVar4);
        }
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        param_1[1]._padding_ = (int)pTVar4;
        if (pTVar4 != (TPicturePanel *)0x0) {
          TPicturePanel::setup
                    (pTVar4,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,
                     (tStack_234.right - param_1->_padding_) + 3,tStack_234.top + 1,0xf,0xe,
                     s_circlep2,0xc4e6,0,1);
          iVar20 = 0;
          iVar19 = 0;
          iVar18 = 0;
          lVar17 = 10;
          lVar16 = 0x12;
          lVar15 = 500;
          lVar2 = TPanel::xPosition((TPanel *)param_1[1]._padding_);
          iVar3 = param_1->_padding_;
          lVar5 = TPanel::width((TPanel *)param_1[1]._padding_);
          piVar11 = &param_1[1]._padding_;
          TEasy_Panel::create_text
                    (param_1,(TPanel *)param_1,(TTextPanel **)piVar11,0x241c,(lVar2 - iVar3) + lVar5
                     ,tStack_234.top,lVar15,lVar16,lVar17,iVar18,iVar19,iVar20);
          iVar3 = TTextPanel::get_text_rect((TTextPanel *)*piVar11,&tStack_234);
          if ((iVar3 != 0) &&
             (iVar3 = ((param_1->_padding_ - tStack_234.right) + -5) / 2, 0 < iVar3)) {
            iVar18 = ((TPanel *)*piVar10)->_padding_;
            lVar2 = TPanel::height((TPanel *)*piVar10);
            lVar5 = TPanel::width((TPanel *)param_1[1]._padding_);
            lVar15 = TPanel::yPosition((TPanel *)param_1[1]._padding_);
            lVar16 = TPanel::xPosition((TPanel *)param_1[1]._padding_);
            iVar3 = lVar16 + iVar3;
            (**(code **)(iVar18 + 0x1c))(iVar3,lVar15,lVar5,lVar2);
            iVar18 = ((TPanel *)param_1[1]._padding_)->_padding_;
            lVar2 = TPanel::height((TPanel *)param_1[1]._padding_);
            lVar5 = TPanel::width((TPanel *)param_1[1]._padding_);
            lVar15 = TPanel::yPosition((TPanel *)param_1[1]._padding_);
            lVar16 = TPanel::xPosition((TPanel *)param_1[1]._padding_);
            (**(code **)(iVar18 + 0x1c))(lVar16 + unaff_EDI,lVar15,lVar5,lVar2);
            iVar18 = ((TPanel *)*piVar11)->_padding_;
            lVar2 = TPanel::height((TPanel *)*piVar11);
            lVar5 = TPanel::width((TPanel *)*piVar11);
            lVar15 = TPanel::yPosition((TPanel *)*piVar11);
            lVar16 = TPanel::xPosition((TPanel *)*piVar11);
            (**(code **)(iVar18 + 0x1c))(lVar16 + iVar3,lVar15,lVar5,lVar2);
          }
        }
      }
    }
    else {
      pcVar6 = TPanel::get_string((TPanel *)param_1,0x241b);
      uVar8 = 0xffffffff;
      do {
        pcVar13 = pcVar6;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar13 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar13;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar6 = pcVar13 + -uVar8;
      pcVar13 = acStack_20c;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar13 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar13 = pcVar13 + 1;
      }
      pcVar6 = TPanel::get_string((TPanel *)param_1,0x2424);
      uVar8 = 0xffffffff;
      do {
        pcVar13 = pcVar6;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar13 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar13;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      iVar3 = -1;
      pcVar6 = acStack_20c;
      do {
        pcVar12 = pcVar6;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar12 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar12;
      } while (cVar1 != '\0');
      pcVar6 = pcVar13 + -uVar8;
      pcVar13 = pcVar12 + -1;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar13 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar13 = pcVar13 + 1;
      }
      uVar8 = 0xffffffff;
      pcVar6 = &s__;
      do {
        pcVar13 = pcVar6;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar13 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar13;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      iVar3 = -1;
      pcVar6 = acStack_20c;
      do {
        pcVar12 = pcVar6;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar12 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar12;
      } while (cVar1 != '\0');
      pcVar6 = pcVar13 + -uVar8;
      pcVar13 = pcVar12 + -1;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar13 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar13 = pcVar13 + 1;
      }
      pcVar6 = TPanel::get_string((TPanel *)param_1,0x241c);
      uVar8 = 0xffffffff;
      do {
        pcVar13 = pcVar6;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar13 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar13;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      iVar3 = -1;
      pcVar6 = acStack_20c;
      do {
        pcVar12 = pcVar6;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar12 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar12;
      } while (cVar1 != '\0');
      pcVar6 = pcVar13 + -uVar8;
      pcVar13 = pcVar12 + -1;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar13 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar13 = pcVar13 + 1;
      }
      TEasy_Panel::create_text
                (param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,acStack_20c,5,
                 iVar7 + -0x2a,param_1->_padding_ + -10,0x12,10,1,0,0);
    }
    TEasy_Panel::create_text
              (param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x2425,5,iVar7 + -0x18
               ,param_1->_padding_ + -10,0x12,10,1,0,0);
    TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
    piVar10 = &param_1[1]._padding_;
    ppTVar14 = apTStack_220;
    for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
      *ppTVar14 = (TPanel *)*piVar10;
      piVar10 = piVar10 + 1;
      ppTVar14 = ppTVar14 + 1;
    }
    TPanel::set_tab_order((TPanel *)param_1,apTStack_220,5);
    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
  }
LAB_0049ebb6:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049ebd1
// Address: 0049ebd1
// XREFS: None
TRIBE_Screen_Main_Menu * __thiscall FUN_0049ebd1(TRIBE_Screen_Main_Menu *param_1,byte param_2)
{
  TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049ebfe
// Address: 0049ebfe
// XREFS: None
void __fastcall FUN_0049ebfe(TScreenPanel *param_1)
{
  int iVar1;
  TPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f048;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Main_Menu::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x28);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x30);
  ppTVar2 = (TPanel **)&param_1[1].field_0x8;
  iVar1 = 7;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (*(undefined4 **)&param_1[1].field_0x34 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x34)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x24 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x24)(1);
  }
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049eccb
// Address: 0049eccb
// XREFS: None
void __fastcall FUN_0049eccb(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0049ecf1
// Address: 0049ecf1
// XREFS: None
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_Main_Menu: "Main Menu"
undefined4 __thiscall
FUN_0049ecf1(TEasy_Panel *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  int iVar1;
  TRIBE_Credits_Screen *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f06b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_5 != 0) {
    if (param_2 == 0x43) {
      this = (TRIBE_Credits_Screen *)operator_new(0x8b8);
      uStack_4 = 0;
      if (this != (TRIBE_Credits_Screen *)0x0) {
        TRIBE_Credits_Screen::TRIBE_Credits_Screen(this);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Credits_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Main_Menu);
    }
    else {
      if (param_2 != 0x4c) goto LAB_0049ede6;
      iVar1 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
      if (iVar1 != 0) {
        iVar1 = TRIBE_Game::load_db_files((TRIBE_Game *)rge_base_game);
        if (iVar1 == 0) {
          TEasy_Panel::popupOKDialog(param_1,0x7d7,(char *)0x0,0x1c2,100);
          *unaff_FS_OFFSET = uStack_c;
          return 1;
        }
      }
    }
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
LAB_0049ede6:
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0049edfa
// Address: 0049edfa
// XREFS: None
// [HELPER] s_Confirm_Dialog: "Confirm Dialog"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_empires_hlp: "empires.hlp"
long __thiscall
FUN_0049edfa(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  long lVar5;
  TribeSPMenuScreen *this;
  TribeMPStartupScreen *this_00;
  TRIBE_Screen_Sed_Menu *this_01;
  byte *pbVar6;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f0a1;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != (TPanel *)0x0) {
    pcVar2 = TPanel::panelName(param_2);
    if (pcVar2 != (char *)0x0) {
      pbVar6 = &s_Confirm_Dialog;
      pbVar3 = (byte *)TPanel::panelName(param_2);
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_0049ee66:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0049ee6b;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_0049ee66;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_0049ee6b:
      if ((iVar4 == 0) && (param_3 == 0)) {
        TPanelSystem::destroyPanel(&panel_system,&s_Confirm_Dialog);
        WinHelpA(rge_base_game->prog_window,s_empires_hlp,3,0);
        lVar5 = 1;
        goto LAB_0049f0b6;
      }
    }
    if (param_3 == 1) {
      if (param_2 == (TPanel *)param_1[1]._padding_) {
        if (rge_base_game->save_check_for_cd == 0) {
          iVar4 = RGE_Base_Game::check_for_cd(rge_base_game,0);
          if (iVar4 == 0) {
            TEasy_Panel::popupOKDialog(param_1,0x7d8,(char *)0x0,0x1c2,100);
            lVar5 = 1;
            goto LAB_0049f0b6;
          }
          rge_base_game->save_check_for_cd = 1;
        }
        RGE_Base_Game::disable_input(rge_base_game);
        this = (TribeSPMenuScreen *)operator_new(0x49c);
        uStack_4 = 0;
        if (this != (TribeSPMenuScreen *)0x0) {
          TribeSPMenuScreen::TribeSPMenuScreen(this);
        }
        uStack_4 = 0xffffffff;
        TPanelSystem::setCurrentPanel(&panel_system,s_Single_Player_Menu,0);
        TPanelSystem::destroyPanel(&panel_system,s_Main_Menu);
        lVar5 = 1;
        goto LAB_0049f0b6;
      }
      if (param_2 == (TPanel *)param_1[1]._padding_) {
        RGE_Base_Game::disable_input(rge_base_game);
        this_00 = (TribeMPStartupScreen *)operator_new(0x6a0);
        uStack_4 = 1;
        if (this_00 != (TribeMPStartupScreen *)0x0) {
          TribeMPStartupScreen::TribeMPStartupScreen(this_00);
        }
        uStack_4 = 0xffffffff;
        TPanelSystem::setCurrentPanel(&panel_system,s_MP_Startup_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Main_Menu);
        lVar5 = 1;
        goto LAB_0049f0b6;
      }
      if (param_2 == (TPanel *)param_1[1]._padding_) {
        TEasy_Panel::popupOKDialog(param_1,0x1d4f7,&s_Confirm_Dialog,0x1c2,100);
        lVar5 = 1;
        goto LAB_0049f0b6;
      }
      if (param_2 == (TPanel *)param_1[1]._padding_) {
        if (rge_base_game->save_check_for_cd == 0) {
          iVar4 = RGE_Base_Game::check_for_cd(rge_base_game,0);
          if (iVar4 == 0) {
            TEasy_Panel::popupOKDialog(param_1,0x7da,(char *)0x0,0x1c2,100);
            lVar5 = 1;
            goto LAB_0049f0b6;
          }
          rge_base_game->save_check_for_cd = 1;
        }
        RGE_Base_Game::disable_input(rge_base_game);
        this_01 = (TRIBE_Screen_Sed_Menu *)operator_new(0x490);
        uStack_4 = 2;
        if (this_01 != (TRIBE_Screen_Sed_Menu *)0x0) {
          TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu(this_01);
        }
        uStack_4 = 0xffffffff;
        TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Menu,0);
        TPanelSystem::destroyPanel(&panel_system,s_Main_Menu);
        lVar5 = 1;
        goto LAB_0049f0b6;
      }
      if (param_2 == (TPanel *)param_1[1]._padding_) {
        RGE_Base_Game::close(rge_base_game);
        lVar5 = 1;
        goto LAB_0049f0b6;
      }
    }
  }
  lVar5 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
LAB_0049f0b6:
  *unaff_FS_OFFSET = uStack_c;
  return lVar5;
}

// --------------------------------------------------

// Function: FUN_0049f0cb
// Address: 0049f0cb
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Main_Error_Screen: "Main Error Screen"
// [HELPER] s_scr1: "scr1"
TEasy_Panel * __fastcall FUN_0049f0cb(TEasy_Panel *param_1)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f0b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Main_Error_Screen);
  param_1->_padding_ = (int)&TRIBE_Screen_Main_Error::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  uStack_4 = 0;
  lVar2 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,s_scr1,0xc383,0);
  if (lVar2 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
  TEasy_Panel::create_text
            (param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),s_,0x28,0x28,0x230,400,4,1,1,1);
  TEasy_Panel::create_button
            (param_1,(TPanel *)param_1,(TButtonPanel **)&param_1[1]._padding_,0xfa1,0,200,0x1b8,0xf0
             ,0x1e,0,0,0);
  piVar1 = &param_1[1]._padding_;
  iVar3 = TEasy_Panel::create_button
                    (param_1,(TPanel *)param_1,(TButtonPanel **)piVar1,0x3ea,0,0,0,0,0,-1,-1,0);
  if (iVar3 != 0) {
    (**(code **)(*(int *)*piVar1 + 0x14))(1);
    (**(code **)(*(int *)*piVar1 + 0x18))(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049f21f
// Address: 0049f21f
// XREFS: None
TRIBE_Screen_Main_Error * __thiscall FUN_0049f21f(TRIBE_Screen_Main_Error *param_1,byte param_2)
{
  TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049f23e
// Address: 0049f23e
// XREFS: None
void __fastcall FUN_0049f23e(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f0d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Main_Error::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049f2a4
// Address: 0049f2a4
// XREFS: None
void __thiscall FUN_0049f2a4(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x478) + 0xe8))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0049f2c6
// Address: 0049f2c6
// XREFS: None
void __thiscall FUN_0049f2c6(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x478) + 0xe4))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0049f2e6
// Address: 0049f2e6
// XREFS: None
long __thiscall
FUN_0049f2e6(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  long lVar1;
  
  if ((param_2 != (TPanel *)0x0) &&
     (((param_2 == (TPanel *)param_1[1]._padding_ && (param_3 == 1)) ||
      ((param_2 == (TPanel *)param_1[1]._padding_ && (param_3 == 1)))))) {
    RGE_Base_Game::close(rge_base_game);
    return 1;
  }
  lVar1 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_0049f361
// Address: 0049f361
// XREFS: None
// [HELPER] s_Default_Age_Of_Empires_Player_Na: "Default Age Of Empires Player Name"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
// [HELPER] s_Zone: "Zone"
// [HELPER] s_http_shell_open_command: "http\shell\open\command"
// [HELPER] s_scr3: "scr3"
TribeMPStartupScreen * __fastcall FUN_0049f361(TribeMPStartupScreen *param_1)
{
  TButtonPanel **ppTVar1;
  TListPanel **ppTVar2;
  char cVar3;
  TButtonPanel *pTVar4;
  long lVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar12;
  undefined4 uStack_38c;
  undefined4 uStack_388;
  undefined1 *puStack_384;
  undefined1 *puStack_380;
  undefined4 uStack_37c;
  undefined4 uStack_378;
  int iStack_334;
  TEditPanel *pTStack_328;
  TListPanel *pTStack_324;
  TButtonPanel *pTStack_320;
  TButtonPanel *pTStack_31c;
  TButtonPanel *pTStack_318;
  TribeMPStartupScreen *pTStack_310;
  char acStack_30c [256];
  undefined1 auStack_20c [256];
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f0fb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_310 = param_1;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_MP_Startup_Screen);
  ppTVar1 = &param_1->cancelButton;
  param_1->_padding_ = (int)&TribeMPStartupScreen::_vftable_;
  param_1->help_button = (TButtonPanel *)0x0;
  param_1->okButton = (TButtonPanel *)0x0;
  *ppTVar1 = (TButtonPanel *)0x0;
  param_1->close_button = (TButtonPanel *)0x0;
  uStack_4 = 0;
  RGE_Base_Game::setMultiplayerGame(rge_base_game,0);
  lVar5 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,&s_scr3,0xc385,1);
  if (lVar5 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
    iVar6 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,0x258b,0x14,0x14,600
                       ,0x1e,1,1,0,0);
    if ((iVar6 != 0) &&
       (iVar6 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->inputTitle,0x258c,0x14
                           ,0x4b,500,0x14,4,0,0,0), iVar6 != 0)) {
      pcVar7 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_Player_Na);
      if (pcVar7 == (char *)0x0) {
        acStack_10c[0] = '\0';
      }
      else {
        pcVar7 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_Player_Na);
        uVar8 = 0xffffffff;
        do {
          pcVar11 = pcVar7;
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          pcVar11 = pcVar7 + 1;
          cVar3 = *pcVar7;
          pcVar7 = pcVar11;
        } while (cVar3 != '\0');
        uVar8 = ~uVar8;
        pcVar7 = pcVar11 + -uVar8;
        pcVar11 = acStack_10c;
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar11 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar11 = pcVar11 + 1;
        }
      }
      uStack_378 = 0x49f4fa;
      iVar6 = TEasy_Panel::create_edit
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->input,acStack_10c,0xf,
                         FormatText,0x14,100,600,0x17,0xb,1,0);
      if (iVar6 != 0) {
        TPanel::set_help_info((TPanel *)param_1->input,0x7595,-1);
        iVar6 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->connectionTitle,0x258d
                           ,0x14,0xa5,600,0x14,4,0,0,0);
        if (iVar6 != 0) {
          ppTVar2 = &param_1->list;
          iVar6 = TEasy_Panel::create_list
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,0x14,0xbe,600,0xd2,0xb
                            );
          if ((iVar6 != 0) &&
             (iVar6 = TEasy_Panel::create_auto_scrollbar
                                ((TEasy_Panel *)param_1,&param_1->scrollbar,(TTextPanel *)*ppTVar2,
                                 0x14), iVar6 != 0)) {
            TPanel::set_help_info((TPanel *)*ppTVar2,0x7596,0x25f08);
            iVar6 = TEasy_Panel::create_button
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->okButton,0xfa1,0,
                               0x46,0x1b8,0xf0,0x1e,0,0,0);
            if (iVar6 != 0) {
              TPanel::set_help_info((TPanel *)param_1->okButton,0x7531,-1);
              iVar6 = TEasy_Panel::create_button
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0xfa2,0,0x14a,
                                 0x1b8,0xf0,0x1e,0,0,0);
              if (iVar6 != 0) {
                TPanel::set_help_info((TPanel *)*ppTVar1,0x7532,-1);
                pTVar4 = *ppTVar1;
                pTVar4->hotkey = 0x1b;
                pTVar4->hotkey_shift = 0;
                iVar6 = TEasy_Panel::create_button
                                  ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->help_button,
                                   0xfa9,0,0x244,0x1b8,0x1e,0x1e,0,0,0);
                if (iVar6 != 0) {
                  ppTVar1 = &param_1->close_button;
                  iVar6 = TEasy_Panel::create_button
                                    ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x3ea,0,0,0,0,
                                     0,-1,-1,0);
                  if (iVar6 != 0) {
                    (**(code **)((*ppTVar1)->_padding_ + 0x14))();
                    uStack_378 = 4;
                    uStack_37c = 9;
                    puStack_380 = (undefined1 *)0x49f6b3;
                    (**(code **)((*ppTVar1)->_padding_ + 0x18))();
                    puStack_380 = &stack0xfffffcb4;
                    puStack_384 = &stack0xfffffc94;
                    uStack_388 = 0;
                    uStack_38c = 0xf003f;
                    uVar12 = 0;
                    param_1->zone_exec[0] = '\0';
                    param_1->browser_exec[0] = '\0';
                    RegCreateKeyExA(0x80000000,s_http_shell_open_command,0,0,0);
                    uStack_388 = 1;
                    uStack_38c = 0xff;
                    iVar6 = RegQueryValueExA(uVar12,0,0,&uStack_388,&stack0xfffffc98,&uStack_38c);
                    if (iStack_334 != 0) {
                      RegCloseKey();
                    }
                    if (iVar6 == 0) {
                      iVar6 = -1;
                      pcVar7 = acStack_30c;
                      do {
                        if (iVar6 == 0) break;
                        iVar6 = iVar6 + -1;
                        cVar3 = *pcVar7;
                        pcVar7 = pcVar7 + 1;
                      } while (cVar3 != '\0');
                      strncpy();
                      iVar6 = strchr();
                      if (iVar6 != 0) {
                        strncpy();
                        *(undefined1 *)((iVar6 - (int)auStack_20c) + 0x59f + (int)param_1) = 0;
                      }
                      pcVar7 = TRegistry::RegGetAscii(Regs,0,s_Zone);
                      if (pcVar7 != (char *)0x0) {
                        uVar8 = 0xffffffff;
                        do {
                          pcVar11 = pcVar7;
                          if (uVar8 == 0) break;
                          uVar8 = uVar8 - 1;
                          pcVar11 = pcVar7 + 1;
                          cVar3 = *pcVar7;
                          pcVar7 = pcVar11;
                        } while (cVar3 != '\0');
                        uVar8 = ~uVar8;
                        iVar6 = -1;
                        pcVar7 = acStack_30c;
                        do {
                          pcVar10 = pcVar7;
                          if (iVar6 == 0) break;
                          iVar6 = iVar6 + -1;
                          pcVar10 = pcVar7 + 1;
                          cVar3 = *pcVar7;
                          pcVar7 = pcVar10;
                        } while (cVar3 != '\0');
                        pcVar7 = pcVar11 + -uVar8;
                        pcVar11 = pcVar10 + -1;
                        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar7;
                          pcVar7 = pcVar7 + 4;
                          pcVar11 = pcVar11 + 4;
                        }
                        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                          *pcVar11 = *pcVar7;
                          pcVar7 = pcVar7 + 1;
                          pcVar11 = pcVar11 + 1;
                        }
                        uVar8 = 0xffffffff;
                        pcVar7 = acStack_30c;
                        do {
                          pcVar11 = pcVar7;
                          if (uVar8 == 0) break;
                          uVar8 = uVar8 - 1;
                          pcVar11 = pcVar7 + 1;
                          cVar3 = *pcVar7;
                          pcVar7 = pcVar11;
                        } while (cVar3 != '\0');
                        uVar8 = ~uVar8;
                        pcVar7 = pcVar11 + -uVar8;
                        pcVar11 = param_1->zone_exec;
                        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar7;
                          pcVar7 = pcVar7 + 4;
                          pcVar11 = pcVar11 + 4;
                        }
                        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                          *pcVar11 = *pcVar7;
                          pcVar7 = pcVar7 + 1;
                          pcVar11 = pcVar11 + 1;
                        }
                      }
                    }
                    TribeMPStartupScreen::fillList(param_1);
                    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->input);
                    pTStack_320 = param_1->okButton;
                    pTStack_328 = param_1->input;
                    pTStack_324 = param_1->list;
                    pTStack_31c = param_1->cancelButton;
                    pTStack_318 = param_1->help_button;
                    TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_328,5);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049f86e
// Address: 0049f86e
// XREFS: None
TribeMPStartupScreen * __thiscall FUN_0049f86e(TribeMPStartupScreen *param_1,byte param_2)
{
  TribeMPStartupScreen::~TribeMPStartupScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049f88e
// Address: 0049f88e
// XREFS: None
// [HELPER] s_Create_Dialog: "Create Dialog"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_YesNoDialog: "YesNoDialog"
void __fastcall FUN_0049f88e(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f118;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeMPStartupScreen::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x20);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x24);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x10);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x18);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1c);
  TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
  TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049f991
// Address: 0049f991
// XREFS: None
void __fastcall FUN_0049f991(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0049f9c1
// Address: 0049f9c1
// XREFS: None
// [HELPER] s_Default_Age_Of_Empires_Multiplay: "Default Age Of Empires Multiplayer Service"
// [HELPER] s_Default_Age_Of_Empires_Player_Na: "Default Age Of Empires Player Name"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_List_Error: "List Error"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Name_Error: "Name Error"
// [HELPER] s_Start_Zone: "Start Zone"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

long __thiscall
FUN_0049f9c1(TEasy_Panel *param_1,TPanel *param_2,long param_3,ulong param_4,ulong param_5)
{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  uchar *puVar6;
  _GUID *p_Var7;
  TribeJoinScreen *this;
  TRIBE_Screen_Main_Menu *this_00;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 *unaff_FS_OFFSET;
  bool bVar11;
  _GUID _Stack_25a0;
  TCommunications_Services TStack_2590;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f157;
  *unaff_FS_OFFSET = &uStack_c;
  TStack_2590.ServiceCount = 0x49f9ef;
  if (param_2 == (TPanel *)0x0) goto LAB_0049fe8e;
  if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 3)) {
    (**(code **)(param_1->_padding_ + 0xb4))(param_1[1]._padding_,1,0,0);
    param_3 = 1;
    goto LAB_0049fea7;
  }
  if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
LAB_0049fe75:
    RGE_Base_Game::close(rge_base_game);
LAB_0049fe80:
    param_3 = 1;
  }
  else {
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
      RGE_Base_Game::setMultiplayerGame(rge_base_game,1);
      pcVar3 = TEditPanel::get_text((TEditPanel *)param_1[1]._padding_);
      if (*pcVar3 == '\0') {
        TEasy_Panel::popupOKDialog(param_1,0x258f,&s_Name_Error,0x1c2,100);
      }
      else {
        iVar4 = TTextPanel::numberLines((TTextPanel *)param_1[1]._padding_);
        if (iVar4 == 0) {
          TEasy_Panel::popupOKDialog(param_1,0x2592,&s_List_Error,0x1c2,100);
          param_3 = 1;
        }
        else if (((char)param_1[1]._padding_ == '\0') ||
                (lVar5 = TTextPanel::get_id((TTextPanel *)param_1[1]._padding_), lVar5 != -1)) {
          RGE_Base_Game::disable_input(rge_base_game);
          pcVar3 = TEditPanel::currentLine((TEditPanel *)param_1[1]._padding_);
          uVar9 = 0xffffffff;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          puVar6 = (uchar *)TEditPanel::currentLine((TEditPanel *)param_1[1]._padding_);
          TRegistry::RegSetAscii(Regs,1,s_Default_Age_Of_Empires_Player_Na,puVar6,uVar9);
          pcVar3 = TTextPanel::get_text((TTextPanel *)param_1[1]._padding_);
          uVar9 = 0xffffffff;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          puVar6 = (uchar *)TTextPanel::get_text((TTextPanel *)param_1[1]._padding_);
          TRegistry::RegSetAscii(Regs,1,s_Default_Age_Of_Empires_Multiplay,puVar6,uVar9);
          pcVar3 = TEditPanel::currentLine((TEditPanel *)param_1[1]._padding_);
          TCommunications_Handler::SetMyPlayerName(comm,pcVar3);
          TCommunications_Services::TCommunications_Services(&TStack_2590);
          iStack_4 = 0;
          lVar5 = TTextPanel::get_id((TTextPanel *)param_1[1]._padding_);
          p_Var7 = TCommunications_Services::GetServiceGUID(&TStack_2590,&_Stack_25a0,lVar5);
          TCommunications_Handler::SetServiceGUID(comm,*p_Var7);
          TCommunications_Handler::InitJoinGame(comm);
          this = (TribeJoinScreen *)operator_new(0x4b0);
          iStack_4._0_1_ = 1;
          if (this != (TribeJoinScreen *)0x0) {
            TribeJoinScreen::TribeJoinScreen(this);
          }
          iStack_4 = (uint)iStack_4._1_3_ << 8;
          TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_MP_Startup_Screen);
          iStack_4 = 0xffffffff;
          TCommunications_Services::~TCommunications_Services(&TStack_2590);
          param_3 = 1;
        }
        else {
          TEasy_Panel::popupYesNoDialog(param_1,0x2593,&s_Start_Zone,0x1c2,100);
          param_3 = 1;
        }
      }
      goto LAB_0049fea7;
    }
    if (((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) ||
       ((param_2 == (TPanel *)param_1[1]._padding_ && (param_3 == 1)))) {
      RGE_Base_Game::disable_input(rge_base_game);
      TCommunications_Handler::UnlinkToLevel(comm,SINGLE_PLAYER);
      this_00 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
      iStack_4 = 2;
      if (this_00 != (TRIBE_Screen_Main_Menu *)0x0) {
        TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_00);
      }
      iStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
      TPanelSystem::destroyPanel(&panel_system,s_MP_Startup_Screen);
      param_3 = 1;
      goto LAB_0049fea7;
    }
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
      TEasy_Panel::setup_popup_help(param_1);
      goto LAB_0049fea7;
    }
    pcVar3 = TPanel::panelName(param_2);
    if (pcVar3 != (char *)0x0) {
      pbVar10 = &s_List_Error;
      pbVar8 = (byte *)TPanel::panelName(param_2);
      do {
        bVar2 = *pbVar8;
        bVar11 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0049fd42:
          iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0049fd47;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar11 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0049fd42;
        pbVar8 = pbVar8 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0049fd47:
      if (iVar4 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_List_Error);
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
        param_3 = 1;
        goto LAB_0049fea7;
      }
    }
    pcVar3 = TPanel::panelName(param_2);
    if (pcVar3 != (char *)0x0) {
      pbVar10 = &s_Name_Error;
      pbVar8 = (byte *)TPanel::panelName(param_2);
      do {
        bVar2 = *pbVar8;
        bVar11 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0049fdb4:
          iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0049fdb9;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar11 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0049fdb4;
        pbVar8 = pbVar8 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0049fdb9:
      if (iVar4 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_Name_Error);
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
        param_3 = 1;
        goto LAB_0049fea7;
      }
    }
    pcVar3 = TPanel::panelName(param_2);
    if (pcVar3 != (char *)0x0) {
      pbVar10 = &s_Start_Zone;
      pbVar8 = (byte *)TPanel::panelName(param_2);
      do {
        bVar2 = *pbVar8;
        bVar11 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0049fe2a:
          iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0049fe2f;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar11 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0049fe2a;
        pbVar8 = pbVar8 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0049fe2f:
      if (iVar4 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_Start_Zone);
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
        if (param_3 == 0) {
          RGE_Base_Game::disable_input(rge_base_game);
          WinExec(&param_1[1]._padding_,3);
          goto LAB_0049fe75;
        }
        goto LAB_0049fe80;
      }
    }
LAB_0049fe8e:
    param_3 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  }
LAB_0049fea7:
  *unaff_FS_OFFSET = uStack_c;
  return param_3;
}

// --------------------------------------------------

// Function: FUN_0049fec1
// Address: 0049fec1
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Default_Age_Of_Empires_Multiplay: "Default Age Of Empires Multiplayer Service"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __fastcall FUN_0049fec1(int param_1)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  byte *pbVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *unaff_FS_OFFSET;
  bool bVar13;
  int iStack_27ac;
  byte abStack_27a8 [256];
  undefined1 auStack_26a8 [280];
  TCommunications_Services TStack_2590;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055f17b;
  *unaff_FS_OFFSET = &uStack_c;
  TStack_2590.ServiceCount = 0x49feef;
  TTextPanel::empty_list(*(TTextPanel **)(param_1 + 0x498));
  TCommunications_Services::TCommunications_Services(&TStack_2590);
  uStack_4 = 0;
  iVar3 = TCommunications_Services::GetServiceCount(&TStack_2590);
  iStack_27ac = -1;
  pcVar4 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_Multiplay);
  if (pcVar4 == (char *)0x0) {
    pcVar4 = s_;
  }
  else {
    pcVar4 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_Multiplay);
  }
  uVar8 = 0xffffffff;
  do {
    pcVar11 = pcVar4;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar11 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar11;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  pbVar10 = (byte *)(pcVar11 + -uVar8);
  pbVar6 = abStack_27a8;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pbVar6 = *(undefined4 *)pbVar10;
    pbVar10 = pbVar10 + 4;
    pbVar6 = pbVar6 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pbVar6 = *pbVar10;
    pbVar10 = pbVar10 + 1;
    pbVar6 = pbVar6 + 1;
  }
  iVar12 = 0;
  if (0 < iVar3) {
    do {
      iVar5 = TCommunications_Services::GetServiceActive(&TStack_2590,iVar12);
      if (iVar5 != 0) {
        pcVar4 = TCommunications_Services::GetServiceName(&TStack_2590,iVar12);
        if (pcVar4 != (char *)0x0) {
          iVar5 = iVar12;
          pcVar4 = TCommunications_Services::GetServiceName(&TStack_2590,iVar12);
          TTextPanel::append_line(*(TTextPanel **)(param_1 + 0x498),pcVar4,iVar5);
          pbVar10 = abStack_27a8;
          pbVar6 = (byte *)TCommunications_Services::GetServiceName(&TStack_2590,iVar12);
          do {
            bVar2 = *pbVar6;
            bVar13 = bVar2 < *pbVar10;
            if (bVar2 != *pbVar10) {
LAB_0049fffe:
              iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
              goto LAB_004a0003;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar6[1];
            bVar13 = bVar2 < pbVar10[1];
            if (bVar2 != pbVar10[1]) goto LAB_0049fffe;
            pbVar6 = pbVar6 + 2;
            pbVar10 = pbVar10 + 2;
          } while (bVar2 != 0);
          iVar5 = 0;
LAB_004a0003:
          if (iVar5 == 0) {
            iStack_27ac = iVar12;
          }
        }
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < iVar3);
  }
  iVar3 = __findfirst(param_1 + 0x59f,auStack_26a8);
  if ((iVar3 != -1) && (*(char *)(param_1 + 0x4a0) != '\0')) {
    TTextPanel::append_line(*(TTextPanel **)(param_1 + 0x498),0x258e,-1);
  }
  if (iStack_27ac != -1) {
    lVar7 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x498),iStack_27ac);
    TTextPanel::set_line(*(TTextPanel **)(param_1 + 0x498),lVar7);
  }
  uStack_4 = 0xffffffff;
  TCommunications_Services::~TCommunications_Services(&TStack_2590);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a009d
// Address: 004a009d
// XREFS: None
undefined4 FUN_004a009d(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a00a8
// Address: 004a00a8
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_____CHAT_SCREEN__CONSTRUCTOR_BEG: "$$$ CHAT SCREEN: CONSTRUCTOR BEGIN"
// [HELPER] s_____CHAT_SCREEN__CONSTRUCTOR_DON: "$$$ CHAT SCREEN: CONSTRUCTOR DONE"
// [HELPER] s_____CHAT_SCREEN__UPDATE_SUMMARY: "$$$ CHAT SCREEN: UPDATE SUMMARY"
// [HELPER] s__d: "%d"
// [HELPER] s_scr2: "scr2"
// [HELPER] s_scr3: "scr3"
TribeMPSetupScreen * __fastcall FUN_004a00a8(TribeMPSetupScreen *param_1)
{
  TDropDownPanel **ppTVar1;
  TButtonPanel **ppTVar2;
  TDrawArea *pTVar3;
  TButtonPanel *pTVar4;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  char *pcVar5;
  TTextPanel **ppTVar6;
  int iVar7;
  TDropDownPanel **ppTVar8;
  undefined4 *unaff_FS_OFFSET;
  int iVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  short sVar14;
  long lVar15;
  int iVar16;
  int iVar17;
  int iStack_118;
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f19b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_MP_Setup_Screen);
  param_1->_padding_ = (int)&TribeMPSetupScreen::_vftable_;
  uStack_4 = 0;
  TDebuggingLog::Log(this,(char *)L,s_____CHAT_SCREEN__CONSTRUCTOR_BEG);
  TribeMPSetupScreen::init_vars(param_1);
  TChat::ClearChat(chat);
  iVar7 = 1;
  do {
    TChat::setInChatGroup(chat,iVar7,1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 9);
  iVar7 = RGE_Base_Game::multiplayerGame(rge_base_game);
  pcVar5 = &s_scr3;
  if (iVar7 == 0) {
    pcVar5 = &s_scr2;
  }
  iVar16 = 1;
  lVar15 = 0;
  lVar13 = 0;
  pTVar3 = rge_base_game->draw_area;
  lVar11 = 0;
  lVar10 = 0;
  iVar9 = 1;
  iVar7 = RGE_Base_Game::multiplayerGame(rge_base_game);
  lVar10 = TEasy_Panel::setup((TEasy_Panel *)param_1,pTVar3,(TPanel *)0x0,pcVar5,
                              (iVar7 != 0) + 0xc384,iVar9,lVar10,lVar11,lVar13,lVar15,iVar16);
  if (lVar10 == 0) {
    param_1->_padding_ = 1;
    goto LAB_004a0d3d;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
  iVar17 = 0;
  iVar16 = 0;
  iVar9 = 1;
  lVar12 = 1;
  lVar15 = 0x1e;
  lVar13 = 600;
  lVar11 = 6;
  lVar10 = 0x14;
  iVar7 = RGE_Base_Game::multiplayerGame(rge_base_game);
  iVar7 = TEasy_Panel::create_text
                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,
                     0x25cf - (uint)(iVar7 != 0),lVar10,lVar11,lVar13,lVar15,lVar12,iVar9,iVar16,
                     iVar17);
  if ((((iVar7 == 0) ||
       (iVar7 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->playerTitle,0x25d0,
                           0x1a,0x32,0xa0,0x1e,0,0,1,0), iVar7 == 0)) ||
      (iVar7 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->civTitle,0x25d1,0xbd,
                          0x32,0xa0,0x1e,0,0,1,0), iVar7 == 0)) ||
     (((iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar7 == 0 &&
       (iVar7 = TCommunications_Handler::IsHost(comm), iVar7 == 0)) &&
      (iVar7 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->settingsTitle,0x25d2,
                          0x1a4,0x32,0xd2,0x1e,0,0,1,0), iVar7 == 0)))) goto LAB_004a0d3d;
  iVar7 = TEasy_Panel::create_text
                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->colorTitle,0x25ae,0xf0,0x32,
                     100,0x1e,0,0,1,0);
  if (iVar7 == 0) goto LAB_004a0d3d;
  TTextPanel::set_alignment(param_1->colorTitle,AlignCenter,AlignRight);
  iVar7 = TEasy_Panel::create_text
                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->teamTitle,0x25af,0x136,0x32,
                     100,0x1e,0,0,1,0);
  if (iVar7 == 0) goto LAB_004a0d3d;
  TTextPanel::set_alignment(param_1->teamTitle,AlignCenter,AlignRight);
  iStack_118 = 0x55;
  ppTVar8 = param_1->playerCivDrop;
  do {
    iVar7 = iStack_118 + -1;
    ppTVar1 = ppTVar8 + -8;
    iVar9 = TEasy_Panel::create_drop_down
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x9e,100,7,iVar7,0x9e,0x18,
                       0xb);
    if (iVar9 == 0) goto LAB_004a0d3d;
    TDropDownPanel::set_draw_style(*ppTVar1,DrawStyleLeftButton);
    TDropDownPanel::set_draw_val_rect(*ppTVar1,0);
    TPanel::set_help_info((TPanel *)*ppTVar1,0x75f9,-1);
    TDropDownPanel::empty_list(*ppTVar1);
    iVar9 = RGE_Base_Game::multiplayerGame(rge_base_game);
    if (iVar9 == 0) {
      TDropDownPanel::append_line(*ppTVar1,0x25d3,4);
      lVar10 = 0x25d6;
    }
    else {
      TDropDownPanel::append_line(*ppTVar1,0x25d3,4);
      TDropDownPanel::append_line(*ppTVar1,0x25d4,1);
      lVar10 = 0x25d5;
    }
    TDropDownPanel::append_line(*ppTVar1,lVar10,0);
    iVar9 = TEasy_Panel::create_drop_down
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar8,0x80,100,0xaa,iVar7,0x80,
                       0x18,0xb);
    if (iVar9 == 0) goto LAB_004a0d3d;
    TDropDownPanel::set_draw_style(*ppTVar8,DrawStyleLeftButton);
    TDropDownPanel::set_draw_val_rect(*ppTVar8,0);
    TPanel::set_help_info((TPanel *)*ppTVar8,0x75fa,0x25f09);
    TDropDownPanel::empty_list(*ppTVar8);
    TDropDownPanel::append_line(*ppTVar8,0x27f7,1);
    TDropDownPanel::append_line(*ppTVar8,0x27f8,2);
    TDropDownPanel::append_line(*ppTVar8,0x27f9,3);
    TDropDownPanel::append_line(*ppTVar8,0x27fa,4);
    TDropDownPanel::append_line(*ppTVar8,0x27fb,5);
    TDropDownPanel::append_line(*ppTVar8,0x27fc,6);
    TDropDownPanel::append_line(*ppTVar8,0x27fd,7);
    TDropDownPanel::append_line(*ppTVar8,0x27fe,8);
    TDropDownPanel::append_line(*ppTVar8,0x27ff,9);
    TDropDownPanel::append_line(*ppTVar8,0x2800,10);
    TDropDownPanel::append_line(*ppTVar8,0x2801,0xb);
    TDropDownPanel::append_line(*ppTVar8,0x2802,0xc);
    TDropDownPanel::append_line(*ppTVar8,0x2806,0xd);
    TDropDownPanel::append_line(*ppTVar8,0x2807,0xe);
    TDropDownPanel::append_line(*ppTVar8,0x2809,0xf);
    TDropDownPanel::append_line(*ppTVar8,0x2808,0x10);
    TDropDownPanel::append_line(*ppTVar8,0x280a,0x11);
    ppTVar1 = ppTVar8 + 8;
    iVar7 = TEasy_Panel::create_drop_down
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x28,100,0x144,iVar7,0x28,
                       0x18,0xb);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TDropDownPanel::set_draw_style(*ppTVar1,DrawStyleLeftButton);
    TDropDownPanel::set_draw_val_rect(*ppTVar1,0);
    TPanel::set_help_info((TPanel *)*ppTVar1,0x75fb,-1);
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)(ppTVar8 + -0x18),
                       s_,(char *)0x0,0x136,iStack_118,0x1e,0x14,0xb,0,1);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)ppTVar8[-0x18],0x7604,-1);
    iVar7 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(ppTVar8 + -0x28),s_,
                       0x131,iStack_118,0x28,0x16,0xb,1,1,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    ppTVar2 = (TButtonPanel **)(ppTVar8 + -0x10);
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,0x25b0,0,0x17c,iStack_118,
                       0x1e,0x14,0xb,0,1);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)*ppTVar2,0x7603,-1);
    TButtonPanel::set_state_info(*ppTVar2,5);
    iVar7 = 1;
    do {
      sprintf(acStack_10c,&s__d,iVar7);
      sVar14 = (short)iVar7;
      TButtonPanel::set_text(*ppTVar2,sVar14,acStack_10c);
      iVar7 = iVar7 + 1;
      TButtonPanel::set_id(*ppTVar2,sVar14,iVar7,0);
    } while (iVar7 < 5);
    iVar7 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(ppTVar8 + -0x20),s_,
                       0x177,iStack_118,0x28,0x16,0xb,1,1,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    iVar7 = iStack_118 + 2;
    iVar9 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(ppTVar8 + -0x50),s_,
                       0x1c,iVar7,0x8b,0x16,0xb,0,0,0);
    if (((iVar9 == 0) ||
        (iVar9 = TEasy_Panel::create_text
                           ((TEasy_Panel *)param_1,(TPanel *)param_1,
                            (TTextPanel **)(ppTVar8 + -0x48),s_,0xbf,iVar7,0x6d,0x16,0xb,0,0,0),
        iVar9 == 0)) ||
       (iVar7 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(ppTVar8 + -0x40)
                           ,s_,0x159,iVar7,0x28,0x16,0xb,0,0,0), iVar7 == 0)) goto LAB_004a0d3d;
    iVar7 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(ppTVar8 + -0x38),
                       0x25df,0x151,iStack_118 + 3,0x14,0x16,6,0,0,0);
    if ((iVar7 == 0) ||
       (iVar7 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(ppTVar8 + -0x30)
                           ,s_,0x161,iStack_118 + 3,0x1d,0x16,6,0,0,0), iVar7 == 0))
    goto LAB_004a0d3d;
    (**(code **)(((TTextPanel *)ppTVar8[-0x38])->_padding_ + 0x14))(0);
    ppTVar8 = ppTVar8 + 1;
    iStack_118 = iStack_118 + 0x18;
  } while (iStack_118 < 0x115);
  iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if ((iVar7 != 0) || (iVar7 = TCommunications_Handler::IsHost(comm), iVar7 != 0)) {
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->gameSettingsButton,0x25d2,
                       0,0x1a4,0x32,0xd2,0x1e,0,0,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)param_1->gameSettingsButton,0x75fc,-1);
  }
  iVar7 = TEasy_Panel::create_text
                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->scenarioName,s_,0x1a4,0x54,
                     0xdc,0x44,0xb,0,0,1);
  if (iVar7 == 0) goto LAB_004a0d3d;
  iVar7 = 0x53;
  ppTVar6 = param_1->settingText;
  do {
    iVar9 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar6,s_,0x1a4,iVar7,0xdc,0x14,0xb
                       ,0,0,0);
    if (iVar9 == 0) goto LAB_004a0d3d;
    iVar7 = iVar7 + 0x18;
    ppTVar6 = ppTVar6 + 1;
  } while (iVar7 < 0x233);
  iVar7 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar7 != 0) {
    iVar7 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->chatTitle,0x25d7,10,0x118,
                       100,0x14,4,0,1,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    ppTVar6 = &param_1->chatBox;
    iVar7 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar6,s_,10,300,400,0x60,10,0,0,0)
    ;
    if ((iVar7 == 0) ||
       (iVar7 = TEasy_Panel::create_auto_scrollbar
                          ((TEasy_Panel *)param_1,&param_1->chatScrollbar,*ppTVar6,0x14), iVar7 == 0
       )) goto LAB_004a0d3d;
    iVar7 = TEasy_Panel::create_edit
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->chatInput,s_,0xf7,
                       FormatText,10,0x192,400,0x17,10,1,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)param_1->chatInput,0x75fe,-1);
    (**(code **)((*ppTVar6)->_padding_ + 0xec))
              (3,(char)param_1->_padding_,*(undefined1 *)((int)&param_1->_padding_ + 1),
               *(undefined1 *)((int)&param_1->_padding_ + 2),
               *(undefined1 *)((int)&param_1->_padding_ + 3),(char)param_1->_padding_,
               *(undefined1 *)((int)&param_1->_padding_ + 1));
    TPanel::set_help_info((TPanel *)*ppTVar6,0x75fd,-1);
    TTextPanel::empty_list(*ppTVar6);
  }
  iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar7 != 0) {
    iVar7 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->numberPlayersTitle,0x25d8,
                       0x1a,0x127,0x14f,0x14,0,0,1,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    iVar7 = TEasy_Panel::create_drop_down
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->numberPlayersDrop,0x46,100
                       ,0x1f,0x142,0x46,0x18,0xb);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)param_1->numberPlayersDrop,0x7600,-1);
  }
  param_1->i_am_ready = 0;
  iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar7 == 0) {
    iVar7 = TCommunications_Handler::IsHost(comm);
    ppTVar2 = &param_1->ready_button;
    if (iVar7 == 0) {
      iVar7 = TEasy_Panel::create_check_box
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,100,0x1b8,0x1e,0x1e,0,0);
      if ((iVar7 == 0) ||
         (iVar7 = TEasy_Panel::create_text
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->ready_button_label,
                             0x25bf,0x87,0x1b8,0x96,0x1e,0,0,1,0), iVar7 == 0)) goto LAB_004a0d3d;
      TPanel::set_help_info((TPanel *)*ppTVar2,0x7602,-1);
      iVar7 = TEasy_Panel::create_button
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->cancelButton,0xfa2,0,
                         0x14a,0x1b8,0xf0,0x1e,0,0,0);
      goto joined_r0x004a0c4b;
    }
    iVar7 = TEasy_Panel::create_check_box
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,10,0x1b8,0x1e,0x1e,0,0);
    if ((iVar7 == 0) ||
       (iVar7 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->ready_button_label,
                           0x25bf,0x2d,0x1b8,0x96,0x1e,0,0,1,0), iVar7 == 0)) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)*ppTVar2,0x7602,-1);
    ppTVar2 = &param_1->startButton;
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,s_,(char *)0x0,0xc3,0x1b8,
                       200,0x1e,0,0,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TButtonPanel::set_text(*ppTVar2,0,0x25ee);
    TPanel::set_help_info((TPanel *)*ppTVar2,0x75ff,-1);
    TButtonPanel::set_disabled(*ppTVar2,1);
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->cancelButton,0xfa2,0,0x195
                       ,0x1b8,0xb4,0x1e,0,0,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)param_1->cancelButton,0x7532,-1);
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->netInfoButton,0x25ef,0,600
                       ,400,0x1e,0x1e,0,0,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)param_1->netInfoButton,0x7601,-1);
    TCommunications_Handler::SetMyReadiness(comm,0,0,0,0,0,0,0,0);
  }
  else {
    ppTVar2 = &param_1->startButton;
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,s_,(char *)0x0,0x46,0x1b8,
                       0xf0,0x1e,0,0,0);
    if (iVar7 == 0) goto LAB_004a0d3d;
    TButtonPanel::set_text(*ppTVar2,0,0x25ee);
    TPanel::set_help_info((TPanel *)*ppTVar2,0x75ff,-1);
    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*ppTVar2);
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->cancelButton,0xfa2,0,0x14a
                       ,0x1b8,0xf0,0x1e,0,0,0);
joined_r0x004a0c4b:
    if (iVar7 == 0) goto LAB_004a0d3d;
    TPanel::set_help_info((TPanel *)param_1->cancelButton,0x7532,-1);
  }
  iVar7 = TEasy_Panel::create_button
                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->help_button,0xfa9,0,600,
                     0x1b8,0x1e,0x1e,0,0,0);
  if (iVar7 != 0) {
    ppTVar2 = &param_1->close_button;
    iVar7 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,0x3ea,0,0,0,0,0,-1,-1,0);
    if (iVar7 != 0) {
      (**(code **)((*ppTVar2)->_padding_ + 0x14))(1);
      (**(code **)((*ppTVar2)->_padding_ + 0x18))(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
      pTVar4 = param_1->cancelButton;
      pTVar4->hotkey = 0x1b;
      pTVar4->hotkey_shift = 0;
      TribeMPSetupScreen::setupTabOrder(param_1);
      TDebuggingLog::Log(this_00,(char *)L,s_____CHAT_SCREEN__UPDATE_SUMMARY);
      TribeMPSetupScreen::updateSummary(param_1);
      iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if (iVar7 != 0) {
        TribeMPSetupScreen::setupSinglePlayerPlayers(param_1);
        TribeMPSetupScreen::fillPlayers(param_1);
      }
      TDebuggingLog::Log(L,(char *)L,s_____CHAT_SCREEN__CONSTRUCTOR_DON);
    }
  }
LAB_004a0d3d:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a0d58
// Address: 004a0d58
// XREFS: None
TribeMPSetupScreen * __thiscall FUN_004a0d58(TribeMPSetupScreen *param_1,byte param_2)
{
  TribeMPSetupScreen::~TribeMPSetupScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a0d7e
// Address: 004a0d7e
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_scr_mps_cp: "C:\msdev\work\age1_x1\scr_mps.cpp"
void __fastcall FUN_004a0d7e(int param_1)
{
  undefined4 *puVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  MapType MVar6;
  
  *(undefined4 *)(param_1 + 0x478) = 0;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0;
  *(undefined4 *)(param_1 + 0x484) = 0;
  *(undefined4 *)(param_1 + 0x488) = 0;
  *(undefined4 *)(param_1 + 0x48c) = 0;
  puVar1 = (undefined4 *)(param_1 + 0x5d0);
  iVar4 = 8;
  do {
    puVar1[-8] = 0;
    *puVar1 = 0;
    puVar1[8] = 0;
    puVar1[-0x18] = 0;
    puVar1[-0x10] = 0;
    puVar1[-0x50] = 0;
    puVar1[-0x48] = 0;
    puVar1[-0x40] = 0;
    puVar1[-0x38] = 0;
    puVar1[-0x30] = 0;
    puVar1[-0x28] = 0;
    puVar1[-0x20] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(param_1 + 0x610) = 0;
  *(undefined4 *)(param_1 + 0x614) = 0;
  *(undefined4 *)(param_1 + 0x61c) = 0;
  *(undefined4 *)(param_1 + 0x618) = 0;
  *(undefined4 *)(param_1 + 0x620) = 0;
  *(undefined4 *)(param_1 + 0x624) = 0;
  *(undefined4 *)(param_1 + 0x628) = 0;
  puVar1 = (undefined4 *)(param_1 + 0x67c);
  iVar4 = 0x14;
  do {
    puVar1[-0x14] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(param_1 + 0x6cc) = 0;
  *(undefined4 *)(param_1 + 0x6d0) = 0;
  *(undefined4 *)(param_1 + 0x6d4) = 0;
  *(undefined4 *)(param_1 + 0x6d8) = 0;
  *(undefined4 *)(param_1 + 0x6dc) = 0;
  *(undefined4 *)(param_1 + 0x6e0) = 0;
  *(undefined4 *)(param_1 + 0x6e4) = 0;
  *(undefined4 *)(param_1 + 0x6e8) = 0;
  *(undefined4 *)(param_1 + 0x6ec) = 0;
  *(undefined4 *)(param_1 + 0x6f0) = 0;
  *(undefined4 *)(param_1 + 0x6f4) = 0;
  *(undefined4 *)(param_1 + 0x6f8) = 0;
  *(undefined4 *)(param_1 + 0x6fc) = 0;
  *(undefined4 *)(param_1 + 0x71c) = 0;
  *(undefined4 *)(param_1 + 0x700) = 0;
  *(undefined4 *)(param_1 + 0x704) = 0;
  *(undefined4 *)(param_1 + 0x708) = 0;
  *(undefined4 *)(param_1 + 0x70c) = 0;
  *(undefined4 *)(param_1 + 0x710) = 0;
  *(undefined4 *)(param_1 + 0x714) = 0;
  *(undefined4 *)(param_1 + 0x718) = 0;
  *(undefined4 *)(param_1 + 0x720) = 0;
  *(undefined4 *)(param_1 + 0x724) = 0;
  *(undefined4 *)(param_1 + 0x72c) = 0;
  *(undefined4 *)(param_1 + 0x730) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x734) = 0;
  *(undefined4 *)(param_1 + 0x738) = 0;
  *(undefined4 *)(param_1 + 0x73c) = 0;
  *(undefined1 *)(param_1 + 0x740) = 0;
  iVar4 = RGE_Base_Game::randomGame(rge_base_game);
  *(int *)(param_1 + 0x840) = iVar4;
  *(undefined4 *)(param_1 + 0x844) = 0;
  *(undefined4 *)(param_1 + 0x848) = 0;
  *(undefined4 *)(param_1 + 0x850) = 8;
  *(undefined4 *)(param_1 + 0x728) = 8;
  *(undefined4 *)(param_1 + 0x84c) = 0;
  *(undefined4 *)(param_1 + 0x854) = 0;
  *(undefined4 *)(param_1 + 0x858) = 0;
  *(undefined4 *)(param_1 + 0x85c) = 0;
  puVar1 = (undefined4 *)(param_1 + 0x868);
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  *(undefined4 *)(param_1 + 0x888) = 0;
  *(undefined4 *)(param_1 + 0x88c) = 0;
  iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar4 == 0) {
    iVar4 = RGE_Base_Game::scenarioGame(rge_base_game);
    if (iVar4 == 0) {
      TRIBE_Game::setMapSize((TRIBE_Game *)rge_base_game,Large);
      iVar4 = debug_rand(s_C__msdev_work_age1_x1_scr_mps_cp,0x26a);
      MVar6 = iVar4 % 10;
      if ((int)MVar6 < 2) {
        MVar6 = AllLand;
      }
      else if (MVar6 == WaterAndLand) {
        MVar6 = MostlyLand;
      }
      else if (MVar6 == MostlyLand) {
        MVar6 = WaterAndLand;
      }
      else if (MVar6 == AllLand) {
        MVar6 = MostlyWater;
      }
      else if (((MVar6 != Continental) && (MVar6 != Lake)) && (MVar6 != Hilly)) {
        MVar6 = (MVar6 != Isthmas) - MostlyWater & Isthmas;
      }
      TRIBE_Game::setMapType((TRIBE_Game *)rge_base_game,MVar6);
    }
    TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game,VictoryDefault,0);
    RGE_Base_Game::setNumberPlayers(rge_base_game,4);
    RGE_Base_Game::setCampaignGame(rge_base_game,0);
    RGE_Base_Game::setSavedGame(rge_base_game,0);
    TRIBE_Game::setAnimals((TRIBE_Game *)rge_base_game,1);
    TRIBE_Game::setPredators((TRIBE_Game *)rge_base_game,1);
    RGE_Base_Game::setFullVisibility(rge_base_game,0);
    RGE_Base_Game::setFogOfWar(rge_base_game,1);
    RGE_Base_Game::setAllowCheatCodes(rge_base_game,1);
    TRIBE_Game::setRandomizePositions((TRIBE_Game *)rge_base_game,0);
    TRIBE_Game::setLongCombat((TRIBE_Game *)rge_base_game,0);
    TRIBE_Game::setAllowTrading((TRIBE_Game *)rge_base_game,1);
    TRIBE_Game::setFullTechTree((TRIBE_Game *)rge_base_game,0);
    TRIBE_Game::setResourceLevel((TRIBE_Game *)rge_base_game,DefaultResources);
    TRIBE_Game::setStartingAge((TRIBE_Game *)rge_base_game,DefaultAge);
    TRIBE_Game::setStartingUnits((TRIBE_Game *)rge_base_game,0);
    iVar4 = RGE_Base_Game::get_single_player_difficulty(rge_base_game);
    RGE_Base_Game::setDifficulty(rge_base_game,iVar4);
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
  }
  else {
    RGE_Base_Game::setCampaignGame(rge_base_game,0);
    RGE_Base_Game::setSavedGame(rge_base_game,0);
    RGE_Base_Game::setScenarioGame(rge_base_game,0);
    RGE_Base_Game::setScenarioName(rge_base_game,s_);
    TRIBE_Game::setMapSize((TRIBE_Game *)rge_base_game,Large);
    TRIBE_Game::setMapType((TRIBE_Game *)rge_base_game,MostlyLand);
    TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game,VictoryDefault,0);
    TRIBE_Game::setAnimals((TRIBE_Game *)rge_base_game,1);
    TRIBE_Game::setPredators((TRIBE_Game *)rge_base_game,1);
    RGE_Base_Game::setNumberPlayers(rge_base_game,8);
    RGE_Base_Game::setFullVisibility(rge_base_game,0);
    RGE_Base_Game::setFogOfWar(rge_base_game,1);
    RGE_Base_Game::setAllowCheatCodes(rge_base_game,0);
    TRIBE_Game::setRandomizePositions((TRIBE_Game *)rge_base_game,0);
    TRIBE_Game::setLongCombat((TRIBE_Game *)rge_base_game,0);
    TRIBE_Game::setAllowTrading((TRIBE_Game *)rge_base_game,1);
    TRIBE_Game::setFullTechTree((TRIBE_Game *)rge_base_game,0);
    TRIBE_Game::setResourceLevel((TRIBE_Game *)rge_base_game,DefaultResources);
    TRIBE_Game::setStartingAge((TRIBE_Game *)rge_base_game,DefaultAge);
    TRIBE_Game::setStartingUnits((TRIBE_Game *)rge_base_game,0);
    iVar4 = RGE_Base_Game::get_single_player_difficulty(rge_base_game);
    RGE_Base_Game::setDifficulty(rge_base_game,iVar4);
    TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\0');
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp,0x243);
    debug_srand(s_C__msdev_work_age1_x1_scr_mps_cp,0x243,uVar2);
    iVar4 = 0;
    do {
      *(char *)(iVar4 + 0x860 + param_1) = (char)iVar4 + '\x01';
      uVar3 = debug_rand(s_C__msdev_work_age1_x1_scr_mps_cp,0x248);
      uVar5 = (int)uVar3 >> 0x1f;
      TRIBE_Game::setCivilization
                ((TRIBE_Game *)rge_base_game,iVar4,
                 (((uVar3 ^ uVar5) - uVar5 & 0xf ^ uVar5) - uVar5) + 1);
      TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,iVar4,iVar4);
      RGE_Base_Game::setPlayerHasCD(rge_base_game,iVar4,0);
      RGE_Base_Game::setPlayerVersion(rge_base_game,iVar4,'\0');
      TRIBE_Game::setPlayerColor
                ((TRIBE_Game *)rge_base_game,iVar4,(uint)*(byte *)(iVar4 + 0x860 + param_1));
      RGE_Base_Game::setPlayerTeam(rge_base_game,iVar4,1);
      TRIBE_Game::setComputerName((TRIBE_Game *)rge_base_game,iVar4,0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    iVar4 = TCommunications_Handler::IsHost(comm);
    if (iVar4 != 0) {
      RGE_Base_Game::setPlayerVersion(rge_base_game,0,'\x01');
      (**(code **)(rge_base_game->_padding_ + 0x48))();
      *(undefined4 *)(param_1 + 0x88c) = 0;
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004a12fb
// Address: 004a12fb
// XREFS: None
// [HELPER] s_Game_Settings_Screen: "Game Settings Screen"
// [HELPER] s_Kick_Dialog: "Kick Dialog"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_Select_Tribe_Screen: "Select Tribe Screen"
// [HELPER] s_YesNoDialog: "YesNoDialog"
void __fastcall FUN_004a12fb(TScreenPanel *param_1)
{
  int iVar1;
  TPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f1b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeMPSetupScreen::_vftable_;
  uStack_4 = 0;
  if (*(int **)&param_1[1].field_0x3d0 != (int *)0x0) {
    (**(code **)(**(int **)&param_1[1].field_0x3d0 + 4))(1);
    *(undefined4 *)&param_1[1].field_0x3d0 = 0;
  }
  TPanelSystem::destroyPanel(&panel_system,&s_Game_Settings_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Select_Tribe_Screen);
  TPanelSystem::destroyPanel(&panel_system,&s_Kick_Dialog);
  TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x10);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  ppTVar2 = (TPanel **)&param_1[1].field_0x158;
  iVar1 = 8;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -8);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + 8);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x18);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x10);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x50);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x48);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x40);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x38);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x30);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x28);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x20);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x198);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x19c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1a0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1a8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1ac);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1b0);
  ppTVar2 = (TPanel **)&param_1[1].field_0x204;
  iVar1 = 0x14;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar2 + -0x14);
    TPanel::delete_panel((TPanel *)param_1,ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x254);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x258);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x25c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x260);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x264);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x268);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x26c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x270);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x274);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x278);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x27c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x280);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x284);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x288);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x294);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2a0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x29c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2a4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x3e0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x298);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a163a
// Address: 004a163a
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_mps_cp: "C:\msdev\work\age1_x1\scr_mps.cpp"
void __fastcall FUN_004a163a(TPanel *param_1)
{
  int iVar1;
  ulong uVar2;
  
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  iVar1 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar1 != 0) {
    if (param_1[8].help_page_id == 0) {
      iVar1 = 0x2fe;
    }
    else {
      uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp,0x301);
      if (uVar2 == param_1[8].help_page_id) goto LAB_004a16b9;
      TCommunications_Handler::SendSharedData(comm,0);
      iVar1 = 0x304;
    }
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp,iVar1);
    param_1[8].help_page_id = uVar2;
  }
LAB_004a16b9:
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004a16c2
// Address: 004a16c2
// XREFS: None
undefined4 FUN_004a16c2(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004a16d5
// Address: 004a16d5
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Game_Settings_Screen: "Game Settings Screen"
// [HELPER] s_Kick_Dialog: "Kick Dialog"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_____SAVING_MYCIV___MYTEAM: "$$$ SAVING MYCIV & MYTEAM"
// [HELPER] s_____SELECTED_I_M_READY: "$$$ SELECTED I'M READY"
// [HELPER] s_____SELECTED_NOT_READY: "$$$ SELECTED NOT READY"
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
long __thiscall
FUN_004a16d5(TribeMPSetupScreen *param_1,TButtonPanel *param_2,long param_3,ulong param_4,
            ulong param_5)
{
  byte bVar1;
  TEditPanel *pTVar2;
  RGE_Prog_Info *pRVar3;
  uchar uVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  TPanel *pTVar8;
  TribeGameSettingsScreen *this;
  TButtonPanel **ppTVar9;
  byte *pbVar10;
  PLAYERHUMANITY PVar11;
  int iVar12;
  int iVar13;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TButtonPanel *this_02;
  byte *pbVar14;
  TDropDownPanel **ppTVar15;
  undefined4 *unaff_FS_OFFSET;
  bool bVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  ulong uVar22;
  char *pcVar23;
  ulong uVar24;
  char acStack_228 [260];
  undefined1 auStack_124 [280];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f1de;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != (TButtonPanel *)0x0) {
    if ((param_2 == param_1->startButton) && (param_3 == 1)) {
      pTVar2 = param_1->chatInput;
      if ((pTVar2 != (TEditPanel *)0x0) && (pTVar2->_padding_ != 0)) {
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)pTVar2);
      }
      TribeMPSetupScreen::startGame(param_1);
      param_3 = 1;
      goto LAB_004a1f92;
    }
    if ((param_2 == param_1->ready_button) && (param_3 == 1)) {
      iVar5 = TButtonPanel::get_state(param_1->ready_button);
      if (iVar5 == 0) {
        TDebuggingLog::Log(this_00,(char *)L,s_____SELECTED_NOT_READY);
        iVar5 = TCommunications_Handler::IsHost(comm);
        if (iVar5 == 0) {
          iVar5 = RGE_Base_Game::check_for_cd(rge_base_game,0);
          uVar24 = iVar5 + 1;
        }
        else {
          uVar24 = 0;
        }
        TCommunications_Handler::SetMyReadiness(comm,0,0,0,uVar24,0,0,0,0);
        pTVar2 = param_1->chatInput;
        if ((pTVar2 != (TEditPanel *)0x0) && (pTVar2->_padding_ != 0)) {
          TPanel::set_curr_child((TPanel *)param_1,(TPanel *)pTVar2);
        }
        param_1->i_am_ready = 0;
      }
      else {
        TDebuggingLog::Log(this_00,(char *)L,s_____SELECTED_I_M_READY);
        iVar5 = TCommunications_Handler::IsHost(comm);
        uVar24 = 0;
        if (iVar5 == 0) {
          uVar4 = RGE_Base_Game::playerVersion(rge_base_game,0);
          if (uVar4 != '\x01') {
            (**(code **)(param_1->ready_button->_padding_ + 0xe0))(0);
            TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x25e3,(char *)0x0,0x1c2,100);
            param_3 = 1;
            goto LAB_004a1f92;
          }
          iVar5 = TCommunications_Handler::WhoAmI(comm);
          TDebuggingLog::Log(this_01,(char *)L,s_____SAVING_MYCIV___MYTEAM);
          lVar6 = TDropDownPanel::get_id(param_1->playerNameDrop[iVar5 + 7]);
          param_1->myCivilization = lVar6;
          lVar6 = TDropDownPanel::get_id(param_1->playerCivDrop[iVar5 + 7]);
          param_1->myScenarioPlayer = lVar6;
          lVar6 = TButtonPanel::get_id((TButtonPanel *)param_1->playerTeamText[iVar5 + 7]);
          param_1->myPlayerColor = lVar6;
          iVar5 = TButtonPanel::get_state(param_1->playerColor[iVar5 + 7]);
          param_1->myPlayerTeam = iVar5 + 1;
          iVar5 = RGE_Base_Game::scenarioGame(rge_base_game);
          if (iVar5 == 0) {
            param_1->myScenarioChecksum = 0;
          }
          else {
            pRVar3 = rge_base_game->prog_info;
            pcVar7 = RGE_Base_Game::scenarioName(rge_base_game);
            sprintf(acStack_228,s__s_s_scn,pRVar3->scenario_dir,pcVar7);
            iVar5 = __findfirst(acStack_228,auStack_124);
            if (iVar5 == -1) {
              pcVar7 = RGE_Base_Game::scenarioName(rge_base_game);
              pcVar23 = s__s_scx;
            }
            else {
              pcVar7 = RGE_Base_Game::scenarioName(rge_base_game);
              pcVar23 = s__s_scn;
            }
            sprintf(acStack_228,pcVar23,pcVar7);
            lVar6 = RGE_Base_Game::get_scenario_checksum(rge_base_game,acStack_228);
            param_1->myScenarioChecksum = lVar6;
          }
          uVar22 = param_1->myScenarioChecksum;
          uVar21 = param_1->myPlayerTeam;
          uVar20 = param_1->myPlayerColor;
          uVar24 = 1;
          iVar5 = RGE_Base_Game::check_for_cd(rge_base_game,0);
          uVar17 = param_1->myCivilization;
          uVar19 = iVar5 + 1;
          uVar18 = param_1->myScenarioPlayer + 1;
        }
        else {
          uVar22 = 0;
          uVar21 = 0;
          uVar20 = 0;
          uVar19 = 0;
          uVar18 = 0;
          uVar17 = 0;
        }
        TCommunications_Handler::SetMyReadiness
                  (comm,1,uVar17,uVar18,uVar19,uVar20,uVar21,uVar22,uVar24);
        pTVar2 = param_1->chatInput;
        if ((pTVar2 != (TEditPanel *)0x0) && (pTVar2->_padding_ != 0)) {
          TPanel::set_curr_child((TPanel *)param_1,(TPanel *)pTVar2);
        }
        param_1->i_am_ready = 1;
      }
      TribeMPSetupScreen::fillPlayers(param_1);
      iVar5 = TCommunications_Handler::IsHost(comm);
      if (iVar5 != 0) {
        TButtonPanel::set_disabled(param_1->gameSettingsButton,param_1->i_am_ready);
        TButtonPanel::set_disabled(param_1->startButton,(uint)(param_1->i_am_ready == 0));
        (**(code **)(rge_base_game->_padding_ + 0x48))();
        param_1->resend_game_options = 0;
        TCommunications_Handler::SendSharedData(comm,1);
        param_3 = 1;
        goto LAB_004a1f92;
      }
      goto LAB_004a1f6b;
    }
    if ((param_2 == param_1->gameSettingsButton) && (param_3 == 1)) {
      pTVar2 = param_1->chatInput;
      if ((pTVar2 != (TEditPanel *)0x0) && (pTVar2->_padding_ != 0)) {
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)pTVar2);
      }
      pTVar8 = TPanelSystem::panel(&panel_system,&s_Game_Settings_Screen);
      if (pTVar8 == (TPanel *)0x0) {
        RGE_Base_Game::disable_input(rge_base_game);
        this = (TribeGameSettingsScreen *)operator_new(0x560);
        uStack_4 = 0;
        if (this != (TribeGameSettingsScreen *)0x0) {
          TribeGameSettingsScreen::TribeGameSettingsScreen(this);
        }
        uStack_4 = 0xffffffff;
      }
      TPanelSystem::setCurrentPanel(&panel_system,&s_Game_Settings_Screen,0);
      param_3 = 1;
      goto LAB_004a1f92;
    }
    if ((param_2 == param_1->help_button) && (param_3 == 1)) {
      TEasy_Panel::setup_popup_help((TEasy_Panel *)param_1);
      goto LAB_004a1f92;
    }
    if ((param_2 == param_1->close_button) && (param_3 == 1)) {
      RGE_Base_Game::close(rge_base_game);
      goto LAB_004a1f92;
    }
    if ((param_2 == param_1->cancelButton) && (param_3 == 1)) {
      pTVar2 = param_1->chatInput;
      if ((pTVar2 != (TEditPanel *)0x0) && (pTVar2->_padding_ != 0)) {
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)pTVar2);
      }
      TribeMPSetupScreen::cancelScreen(param_1,0);
      param_3 = 1;
      goto LAB_004a1f92;
    }
    if (param_2 == param_1->netInfoButton) {
      if (param_3 == 1) {
        TribeMPSetupScreen::showNetInfo(param_1);
        goto LAB_004a1f92;
      }
    }
    else if (param_3 == 1) {
      iVar5 = 0;
      ppTVar9 = param_1->playerTeam;
      do {
        if (param_2 == ppTVar9[-8]) {
          lVar6 = TButtonPanel::get_id(param_1->playerColor[iVar5]);
          TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,iVar5,lVar6);
          iVar12 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if ((iVar12 == 0) || (iVar12 = TCommunications_Handler::IsHost(comm), iVar12 != 0))
          goto LAB_004a1f6b;
          lVar6 = TButtonPanel::get_id(param_1->playerColor[iVar5]);
          param_1->myPlayerColor = lVar6;
          param_3 = 1;
          goto LAB_004a1f92;
        }
        if (param_2 == *ppTVar9) {
          iVar12 = TButtonPanel::get_state(param_1->playerTeam[iVar5]);
          RGE_Base_Game::setPlayerTeam(rge_base_game,iVar5,iVar12 + 1);
          iVar12 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if ((iVar12 == 0) || (iVar12 = TCommunications_Handler::IsHost(comm), iVar12 != 0))
          goto LAB_004a1f6b;
          iVar5 = TButtonPanel::get_state(param_1->playerTeam[iVar5]);
          param_1->myPlayerTeam = iVar5 + 1;
          param_3 = 1;
          goto LAB_004a1f92;
        }
        iVar5 = iVar5 + 1;
        ppTVar9 = ppTVar9 + 1;
      } while (iVar5 < 8);
    }
    if ((((param_2 == (TButtonPanel *)param_1->chatInput) && (param_3 == 0)) &&
        (pcVar7 = TEditPanel::currentLine(param_1->chatInput), pcVar7 != (char *)0x0)) &&
       (pcVar7 = TEditPanel::currentLine(param_1->chatInput), *pcVar7 != '\0')) {
      pcVar7 = TEditPanel::currentLine(param_1->chatInput);
      TCommunications_Handler::SendChatMsgAll(comm,pcVar7);
      TEditPanel::set_text(param_1->chatInput,s_);
      param_3 = 1;
      goto LAB_004a1f92;
    }
    if ((param_2 == (TButtonPanel *)param_1->numberPlayersDrop) && (param_3 == 0)) {
      lVar6 = TDropDownPanel::get_id(param_1->numberPlayersDrop);
      RGE_Base_Game::setNumberPlayers(rge_base_game,lVar6);
      TribeMPSetupScreen::updateSummary(param_1);
      param_3 = 1;
      goto LAB_004a1f92;
    }
    pcVar7 = TPanel::panelName((TPanel *)param_2);
    if (pcVar7 != (char *)0x0) {
      pbVar14 = &s_Game_Settings_Screen;
      pbVar10 = (byte *)TPanel::panelName((TPanel *)param_2);
      do {
        bVar1 = *pbVar10;
        bVar16 = bVar1 < *pbVar14;
        if (bVar1 != *pbVar14) {
LAB_004a1c56:
          iVar5 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
          goto LAB_004a1c5b;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar10[1];
        bVar16 = bVar1 < pbVar14[1];
        if (bVar1 != pbVar14[1]) goto LAB_004a1c56;
        pbVar10 = pbVar10 + 2;
        pbVar14 = pbVar14 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_004a1c5b:
      if (iVar5 == 0) {
        if (param_3 != 0) {
          TribeMPSetupScreen::updateSummary(param_1);
          iVar5 = RGE_Base_Game::singlePlayerGame(rge_base_game);
          if (iVar5 == 0) {
            (**(code **)(rge_base_game->_padding_ + 0x48))();
            param_1->resend_game_options = 0;
          }
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
        param_3 = 1;
        goto LAB_004a1f92;
      }
    }
    pcVar7 = TPanel::panelName((TPanel *)param_2);
    if (pcVar7 != (char *)0x0) {
      pbVar14 = &s_Kick_Dialog;
      pbVar10 = (byte *)TPanel::panelName((TPanel *)param_2);
      do {
        bVar1 = *pbVar10;
        bVar16 = bVar1 < *pbVar14;
        if (bVar1 != *pbVar14) {
LAB_004a1cf6:
          iVar5 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
          goto LAB_004a1cfb;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar10[1];
        bVar16 = bVar1 < pbVar14[1];
        if (bVar1 != pbVar14[1]) goto LAB_004a1cf6;
        pbVar10 = pbVar10 + 2;
        pbVar14 = pbVar14 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_004a1cfb:
      if (iVar5 == 0) {
        if (param_3 == 0) {
          PVar11 = TDropDownPanel::get_id
                             ((TDropDownPanel *)param_1->playerTeam[param_1->playerToKick + 7]);
          TCommunications_Handler::Kick(comm,param_1->playerToKick);
          TCommunications_Handler::SetPlayerHumanity(comm,param_1->playerToKick,PVar11);
          lVar6 = TDropDownPanel::get_line
                            ((TDropDownPanel *)param_1->playerTeam[param_1->playerToKick + 7],PVar11
                            );
          this_02 = param_1->playerTeam[param_1->playerToKick + 7];
        }
        else {
          lVar6 = 0;
          this_02 = param_1->playerTeam[param_1->playerToKick + 7];
        }
        TDropDownPanel::set_line((TDropDownPanel *)this_02,lVar6);
        (**(code **)param_2->_padding_)(1);
        param_3 = 1;
        goto LAB_004a1f92;
      }
    }
    if ((param_3 == 0) && (iVar5 = RGE_Base_Game::numberPlayers(rge_base_game), 0 < iVar5)) {
      ppTVar15 = param_1->playerCivDrop;
      iVar5 = 0;
      do {
        if (param_2 == (TButtonPanel *)ppTVar15[-8]) {
          iVar12 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if ((iVar12 != 0) &&
             (lVar6 = TDropDownPanel::get_line(param_1->playerNameDrop[iVar5]), 0 < lVar6)) {
            iVar12 = TCommunications_Handler::IsPlayerHuman(comm,iVar5 + 1U);
            if (iVar12 != 0) {
              TribeMPSetupScreen::kickPlayer(param_1,iVar5 + 1U);
              param_3 = 1;
              goto LAB_004a1f92;
            }
          }
          PVar11 = TDropDownPanel::get_id(param_1->playerNameDrop[iVar5]);
          TCommunications_Handler::SetPlayerHumanity(comm,iVar5 + 1,PVar11);
          param_3 = 1;
          goto LAB_004a1f92;
        }
        if (param_2 == (TButtonPanel *)*ppTVar15) {
          lVar6 = TDropDownPanel::get_id(param_1->playerCivDrop[iVar5]);
          TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,iVar5,lVar6);
          iVar12 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if ((iVar12 == 0) || (iVar12 = TCommunications_Handler::IsHost(comm), iVar12 != 0))
          goto LAB_004a1f6b;
          lVar6 = TDropDownPanel::get_id(param_1->playerCivDrop[iVar5]);
          param_1->myCivilization = lVar6;
          param_3 = 1;
          goto LAB_004a1f92;
        }
        if (param_2 == (TButtonPanel *)ppTVar15[8]) {
          iVar12 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if (iVar12 == 0) {
            lVar6 = TDropDownPanel::get_id(param_1->scenarioPlayerDrop[0]);
            TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,0,lVar6);
            iVar5 = 1;
            iVar12 = 0;
            goto LAB_004a1f20;
          }
          lVar6 = TDropDownPanel::get_id(param_1->scenarioPlayerDrop[iVar5]);
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,iVar5,lVar6);
          iVar12 = TCommunications_Handler::IsHost(comm);
          if (iVar12 != 0) goto LAB_004a1f6b;
          lVar6 = TDropDownPanel::get_id(param_1->scenarioPlayerDrop[iVar5]);
          param_1->myScenarioPlayer = lVar6;
          param_3 = 1;
          goto LAB_004a1f92;
        }
        iVar5 = iVar5 + 1;
        ppTVar15 = ppTVar15 + 1;
        iVar12 = RGE_Base_Game::numberPlayers(rge_base_game);
      } while (iVar5 < iVar12);
    }
  }
  param_3 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  goto LAB_004a1f92;
LAB_004a1f20:
  do {
    iVar13 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game,0);
    if ((iVar12 != iVar13) &&
       (iVar13 = RGE_Scenario::Get_player_Active((RGE_Scenario *)param_1->scenarioInfo,iVar12),
       iVar13 != 0)) {
      TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,iVar5,iVar12);
      iVar5 = iVar5 + 1;
      iVar13 = RGE_Base_Game::numberPlayers(rge_base_game);
      if (iVar13 <= iVar5) break;
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 < 8);
  TribeMPSetupScreen::fillPlayers(param_1);
LAB_004a1f6b:
  param_3 = 1;
LAB_004a1f92:
  *unaff_FS_OFFSET = uStack_c;
  return param_3;
}

// --------------------------------------------------

// Function: FUN_004a205a
// Address: 004a205a
// XREFS: None
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_____HOST_RESET2_CIV_50: "$$$ HOST RESET2 CIV+50"
// [HELPER] s_____HOST_RESET2_TEAM_50: "$$$ HOST RESET2 TEAM+50"
undefined4 __fastcall FUN_004a205a(TribeMPSetupScreen *param_1)
{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  long lVar8;
  char *pcVar9;
  int iVar10;
  TDebuggingLog *this;
  int *piVar11;
  uint uVar12;
  long *plVar13;
  int aiStack_560 [8];
  int aiStack_540 [8];
  int aiStack_520 [8];
  char acStack_500 [256];
  char acStack_400 [1024];
  
  bVar1 = false;
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar3 != 0) {
    iVar3 = TCommunications_Handler::IsHost(comm);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = TCommunications_Handler::AllPlayersReady(comm);
    if (iVar3 == 0) {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x25c1,(char *)0x0,0x1c2,100);
      return 0;
    }
    iVar3 = RGE_Base_Game::scenarioGame(rge_base_game);
    if (iVar3 != 0) {
      iVar3 = 0;
      uVar12 = 1;
      plVar13 = param_1->scenarioCheckSum;
      do {
        uVar4 = TCommunications_Handler::WhoAmI(comm);
        if (((uVar12 != uVar4) &&
            (iVar5 = TCommunications_Handler::GetPlayerHumanity(comm,uVar12), iVar5 == 2)) &&
           (*plVar13 != param_1->myScenarioChecksum)) {
          pcVar9 = TCommunications_Handler::GetPlayerName(comm,iVar3 + 1);
          pcVar7 = TPanel::get_string((TPanel *)param_1,0x25e1);
          sprintf(acStack_400,pcVar7,pcVar9);
          TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,acStack_400,(char *)0x0,0x1c2,100);
          return 0;
        }
        iVar3 = iVar3 + 1;
        plVar13 = plVar13 + 1;
        uVar12 = uVar12 + 1;
      } while ((int)uVar12 < 9);
    }
    uVar12 = 0;
    do {
      uVar4 = uVar12 + 1;
      uVar6 = TCommunications_Handler::WhoAmI(comm);
      if (((uVar4 != uVar6) &&
          (iVar3 = TCommunications_Handler::GetPlayerHumanity(comm,uVar4), iVar3 == 2)) &&
         (uVar2 = RGE_Base_Game::playerVersion(rge_base_game,uVar12), uVar2 != '\x01')) {
        pcVar9 = TCommunications_Handler::GetPlayerName(comm,uVar12 + 1);
        pcVar7 = TPanel::get_string((TPanel *)param_1,0x25e2);
        sprintf(acStack_400,pcVar7,pcVar9);
        TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,acStack_400,(char *)0x0,0x1c2,100);
        return 0;
      }
      uVar12 = uVar4;
    } while ((int)uVar4 < 8);
  }
  iVar3 = RGE_Base_Game::scenarioGame(rge_base_game);
  if ((iVar3 != 0) && (param_1->scenarioInfo == (T_Scenario *)0x0)) {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x25c2,(char *)0x0,0x1c2,100);
    return 0;
  }
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ((iVar3 != 0) && (iVar3 = RGE_Base_Game::scenarioGame(rge_base_game), iVar3 != 0)) {
    iVar3 = 0;
    uVar12 = 0;
    do {
      uVar4 = uVar12 + 1;
      iVar5 = TCommunications_Handler::GetPlayerHumanity(comm,uVar4);
      if ((iVar5 == 2) || (iVar5 == 4)) {
        lVar8 = TDropDownPanel::get_id(param_1->scenarioPlayerDrop[0],iVar3);
        TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,uVar12,lVar8);
        iVar3 = iVar3 + 1;
        iVar5 = TTextPanel::numberLines((TTextPanel *)param_1->scenarioPlayerDrop[0]->list_panel);
        if (iVar5 <= iVar3) {
          iVar3 = 0;
        }
      }
      uVar12 = uVar4;
    } while ((int)uVar4 < 8);
  }
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar3 != 0) {
    iVar5 = 0;
    piVar11 = aiStack_560;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar11 = 0;
      piVar11 = piVar11 + 1;
    }
    iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
    uVar12 = 0;
    if (0 < iVar3) {
      do {
        uVar4 = uVar12 + 1;
        iVar3 = TCommunications_Handler::GetPlayerHumanity(comm,uVar4);
        if (iVar3 == 2) {
          iVar3 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,uVar12);
          if (aiStack_560[iVar3 + -1] == 0) {
            iVar5 = iVar5 + 1;
            iVar3 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,uVar12);
            aiStack_560[iVar3 + -1] = 1;
          }
        }
        else if (iVar3 == 4) {
          iVar5 = iVar5 + 1;
        }
        iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
        uVar12 = uVar4;
      } while ((int)uVar4 < iVar3);
    }
    if (iVar5 < 2) {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x25c6,(char *)0x0,0x1c2,100);
      return 0;
    }
    iVar3 = RGE_Base_Game::scenarioGame(rge_base_game);
    if ((iVar3 != 0) && (iVar3 = param_1->scenarioPlayerCount, iVar3 < iVar5)) {
      pcVar9 = TPanel::get_string((TPanel *)param_1,0x25c3);
      sprintf(acStack_500,pcVar9,iVar3);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,acStack_500,(char *)0x0,0x1c2,100);
      return 0;
    }
    iVar3 = RGE_Base_Game::scenarioGame(rge_base_game);
    if (((iVar3 != 0) && (param_1->settingsFixed != 0)) &&
       (iVar3 = param_1->scenarioPlayerCount, iVar5 != iVar3)) {
      pcVar9 = TPanel::get_string((TPanel *)param_1,0x25c5);
      sprintf(acStack_500,pcVar9,iVar3);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,acStack_500,(char *)0x0,0x1c2,100);
      return 0;
    }
    iVar5 = 0;
    uVar12 = 0;
    iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
    if (0 < iVar3) {
      do {
        uVar12 = uVar12 + 1;
        iVar3 = TCommunications_Handler::GetPlayerHumanity(comm,uVar12);
        if (iVar3 == 2) {
          iVar5 = iVar5 + 1;
        }
        iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
      } while ((int)uVar12 < iVar3);
    }
    iVar3 = RGE_Base_Game::check_for_cd(rge_base_game,0);
    iVar10 = TCommunications_Handler::WhoAmI(comm);
    RGE_Base_Game::setPlayerHasCD(rge_base_game,iVar10 + -1,iVar3);
    iVar3 = RGE_Base_Game::check_for_cd(rge_base_game,iVar5);
    if (iVar3 == 0) {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x7d9,(char *)0x0,0x1c2,100);
      return 0;
    }
  }
  iVar3 = RGE_Base_Game::scenarioGame(rge_base_game);
  if ((iVar3 != 0) &&
     (iVar3 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game), iVar3 != 0)) {
    TribeMPSetupScreen::calcRandomPositions(param_1);
    iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
    if (iVar3 != 0) {
      bVar1 = true;
    }
  }
  iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if ((iVar3 != 0) && (iVar3 = RGE_Base_Game::numberPlayers(rge_base_game), iVar3 < 8)) {
    uVar12 = iVar3 + 1;
    do {
      TCommunications_Handler::SetPlayerHumanity(comm,uVar12,ME_ABSENT);
      uVar12 = uVar12 + 1;
    } while ((int)uVar12 < 9);
  }
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar3 != 0) {
    iVar5 = 0;
    iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
    if (0 < iVar3) {
      do {
        iVar3 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar5);
        if (0x31 < iVar3) {
          TDebuggingLog::Log(L,(char *)L,s_____HOST_RESET2_CIV_50);
          iVar3 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar5);
          TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,iVar5,iVar3 + -0x32);
          bVar1 = true;
        }
        iVar3 = RGE_Base_Game::playerTeam(rge_base_game,iVar5);
        if (0x31 < iVar3) {
          TDebuggingLog::Log(this,(char *)L,s_____HOST_RESET2_TEAM_50);
          iVar3 = RGE_Base_Game::playerTeam(rge_base_game,iVar5);
          RGE_Base_Game::setPlayerTeam(rge_base_game,iVar5,iVar3 + -0x32);
          bVar1 = true;
        }
        iVar5 = iVar5 + 1;
        iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
      } while (iVar5 < iVar3);
    }
  }
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar3 != 0) {
    piVar11 = aiStack_560;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar11 = 1;
      piVar11 = piVar11 + 1;
    }
    piVar11 = aiStack_520;
    for (iVar3 = 8; iVar5 = 0, iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar11 = 1;
      piVar11 = piVar11 + 1;
    }
    do {
      iVar3 = iVar5 + 1;
      aiStack_540[iVar5] = iVar3;
      iVar5 = iVar3;
    } while (iVar3 < 8);
    iVar3 = 0;
    uVar12 = 1;
    piVar11 = aiStack_560;
    do {
      iVar5 = TCommunications_Handler::GetPlayerHumanity(comm,uVar12);
      if ((iVar5 == 2) || (iVar5 == 4)) {
        iVar5 = uVar12 - 1;
        iVar10 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,iVar5);
        aiStack_540[iVar3] = iVar10;
        iVar10 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar5);
        aiStack_520[iVar3] = iVar10;
        iVar5 = RGE_Base_Game::playerTeam(rge_base_game,iVar5);
        *piVar11 = iVar5;
        iVar3 = iVar3 + 1;
        piVar11 = piVar11 + 1;
      }
      uVar12 = uVar12 + 1;
    } while ((int)uVar12 < 9);
    if (0 < iVar3) {
      iVar3 = 0;
      piVar11 = aiStack_560;
      do {
        TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,iVar3,aiStack_540[iVar3]);
        TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,iVar3,aiStack_520[iVar3]);
        RGE_Base_Game::setPlayerTeam(rge_base_game,iVar3,*piVar11);
        iVar3 = iVar3 + 1;
        piVar11 = piVar11 + 1;
      } while (iVar3 < 8);
      bVar1 = true;
    }
  }
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar3 != 0) {
    if ((bVar1) || (param_1->resend_game_options != 0)) {
      (**(code **)(rge_base_game->_padding_ + 0x48))();
      param_1->resend_game_options = 0;
    }
    TCommunications_Handler::LaunchMultiplayerGame(comm);
    TChat::setWindowHandle(chat,AppWnd);
    TCommunications_Handler::SetWindowHandle(comm,AppWnd);
  }
  iVar3 = TRIBE_Game::start_game((TRIBE_Game *)rge_base_game,0);
  if (iVar3 == 0) {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x961,(char *)0x0,0x1c2,100);
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a2797
// Address: 004a2797
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_mps_cp: "C:\msdev\work\age1_x1\scr_mps.cpp"
void __fastcall FUN_004a2797(int param_1)
{
  uint uVar1;
  int iVar2;
  long lVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iStack_28;
  uint auStack_20 [8];
  
  iVar5 = 0;
  uVar6 = 0;
  iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
  if (0 < iVar2) {
    do {
      uVar6 = uVar6 + 1;
      iVar2 = TCommunications_Handler::GetPlayerHumanity(comm,uVar6);
      if ((iVar2 == 2) || (iVar2 == 4)) {
        iVar5 = iVar5 + 1;
      }
      iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
    } while ((int)uVar6 < iVar2);
  }
  iVar2 = 0;
  iVar7 = 0;
  puVar4 = auStack_20;
  do {
    lVar3 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x5f0),iVar7);
    if (lVar3 == -1) {
      *puVar4 = 0xfffffffe;
    }
    else {
      *puVar4 = 0xffffffff;
      iVar2 = iVar2 + 1;
    }
    iVar7 = iVar7 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar7 < 8);
  if (iVar5 <= iVar2) {
    iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
    uVar6 = 0;
    if (0 < iVar2) {
      do {
        uVar1 = uVar6 + 1;
        iVar2 = TCommunications_Handler::GetPlayerHumanity(comm,uVar1);
        if ((iVar2 == 2) || (iVar2 == 4)) {
          iVar5 = 0;
          iVar2 = iStack_28;
          if (0 < *(int *)(param_1 + 0x728)) {
            puVar4 = auStack_20;
            do {
              iVar2 = iVar5;
              if (*puVar4 == 0xffffffff) break;
              iVar5 = iVar5 + 1;
              puVar4 = puVar4 + 1;
              iVar2 = iStack_28;
            } while (iVar5 < *(int *)(param_1 + 0x728));
          }
          iStack_28 = iVar2;
          iVar2 = 0;
          do {
            iVar7 = *(int *)(param_1 + 0x728);
            iVar5 = debug_rand(s_C__msdev_work_age1_x1_scr_mps_cp,0x5e4);
            iVar5 = (iVar5 * iVar7) / 0x7fff;
            if (iVar5 < iVar7) {
              if (iVar5 < 0) {
                iVar5 = 0;
              }
            }
            else {
              iVar5 = iVar7 + -1;
            }
          } while ((auStack_20[iVar5] != 0xffffffff) &&
                  (iVar2 = iVar2 + 1, iVar5 = iStack_28, iVar2 < 1000));
          iStack_28 = iVar5;
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,uVar6,iStack_28);
          auStack_20[iStack_28] = uVar6;
        }
        iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
        uVar6 = uVar1;
      } while ((int)uVar1 < iVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004a290e
// Address: 004a290e
// XREFS: None
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s__: "}"
// [HELPER] s___: "]\n"
void __fastcall FUN_004a290e(TEasy_Panel *param_1)
{
  char cVar1;
  uint uVar2;
  RGE_Communications_Addresses *pRVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 *unaff_FS_OFFSET;
  char acStack_50c [1024];
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f1fe;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar3 = (RGE_Communications_Addresses *)operator_new(0x224);
  uStack_4 = 0;
  if (pRVar3 == (RGE_Communications_Addresses *)0x0) {
    pRVar3 = (RGE_Communications_Addresses *)0x0;
  }
  else {
    pRVar3 = (RGE_Communications_Addresses *)
             RGE_Communications_Addresses::RGE_Communications_Addresses(pRVar3,comm);
  }
  uStack_4 = 0xffffffff;
  if (pRVar3 != (RGE_Communications_Addresses *)0x0) {
    uVar2 = pRVar3->AddressesAvailable;
    acStack_50c[0] = '\0';
    if (uVar2 == 0) {
      TEasy_Panel::popupOKDialog(param_1,0x238d,(char *)0x0,0x1c2,100);
    }
    else {
      uVar6 = 0xffffffff;
      pcVar4 = &s___;
      do {
        pcVar5 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar5 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar5;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar7 = -1;
      pcVar4 = acStack_50c;
      do {
        pcVar10 = pcVar4;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar5 + -uVar6;
      pcVar5 = pcVar10 + -1;
      for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar5 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      }
      pcVar4 = RGE_Communications_Addresses::GetHostName(pRVar3);
      pcVar5 = TPanel::get_string((TPanel *)param_1,0x238c);
      sprintf(acStack_10c,pcVar5,pcVar4);
      uVar6 = 0xffffffff;
      pcVar4 = acStack_10c;
      do {
        pcVar5 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar5 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar5;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar7 = -1;
      pcVar4 = acStack_50c;
      do {
        pcVar10 = pcVar4;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar5 + -uVar6;
      pcVar5 = pcVar10 + -1;
      for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar5 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar4 = &s__;
      do {
        pcVar5 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar5 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar5;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar7 = -1;
      pcVar4 = acStack_50c;
      do {
        pcVar10 = pcVar4;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar5 + -uVar6;
      pcVar5 = pcVar10 + -1;
      for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar5 = pcVar5 + 4;
      }
      uVar8 = 0;
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar5 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      }
      if (uVar2 != 0) {
        do {
          pcVar4 = RGE_Communications_Addresses::GetAddress(pRVar3,uVar8);
          if (pcVar4 != (char *)0x0) {
            pcVar4 = RGE_Communications_Addresses::GetAddress(pRVar3,uVar8);
            uVar6 = 0xffffffff;
            do {
              pcVar5 = pcVar4;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar5 = pcVar4 + 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar5;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            iVar7 = -1;
            pcVar4 = acStack_50c;
            do {
              pcVar10 = pcVar4;
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              pcVar10 = pcVar4 + 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar10;
            } while (cVar1 != '\0');
            pcVar4 = pcVar5 + -uVar6;
            pcVar5 = pcVar10 + -1;
            for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
              pcVar4 = pcVar4 + 4;
              pcVar5 = pcVar5 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar5 = *pcVar4;
              pcVar4 = pcVar4 + 1;
              pcVar5 = pcVar5 + 1;
            }
            uVar6 = 0xffffffff;
            pcVar4 = &s__;
            do {
              pcVar5 = pcVar4;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar5 = pcVar4 + 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar5;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            iVar7 = -1;
            pcVar4 = acStack_50c;
            do {
              pcVar10 = pcVar4;
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              pcVar10 = pcVar4 + 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar10;
            } while (cVar1 != '\0');
            pcVar4 = pcVar5 + -uVar6;
            pcVar5 = pcVar10 + -1;
            for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
              pcVar4 = pcVar4 + 4;
              pcVar5 = pcVar5 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar5 = *pcVar4;
              pcVar4 = pcVar4 + 1;
              pcVar5 = pcVar5 + 1;
            }
          }
          pcVar4 = RGE_Communications_Addresses::GetAlias(pRVar3,uVar8);
          if (pcVar4 != (char *)0x0) {
            pcVar4 = RGE_Communications_Addresses::GetAlias(pRVar3,uVar8);
            uVar6 = 0xffffffff;
            do {
              pcVar5 = pcVar4;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar5 = pcVar4 + 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar5;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            iVar7 = -1;
            pcVar4 = acStack_50c;
            do {
              pcVar10 = pcVar4;
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              pcVar10 = pcVar4 + 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar10;
            } while (cVar1 != '\0');
            pcVar4 = pcVar5 + -uVar6;
            pcVar5 = pcVar10 + -1;
            for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
              pcVar4 = pcVar4 + 4;
              pcVar5 = pcVar5 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar5 = *pcVar4;
              pcVar4 = pcVar4 + 1;
              pcVar5 = pcVar5 + 1;
            }
          }
          uVar6 = 0xffffffff;
          pcVar4 = &s__;
          do {
            pcVar5 = pcVar4;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar5 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar5;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar7 = -1;
          pcVar4 = acStack_50c;
          do {
            pcVar10 = pcVar4;
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            pcVar10 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar10;
          } while (cVar1 != '\0');
          pcVar4 = pcVar5 + -uVar6;
          pcVar5 = pcVar10 + -1;
          for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
            pcVar4 = pcVar4 + 4;
            pcVar5 = pcVar5 + 4;
          }
          uVar8 = uVar8 + 1;
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar5 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          }
        } while (uVar8 < uVar2);
      }
      TEasy_Panel::popupOKDialog(param_1,acStack_50c,&s_OKDialog,0x1c2,uVar2 * 0x12 + 100);
    }
    RGE_Communications_Addresses::~RGE_Communications_Addresses(pRVar3);
    operator_delete(pRVar3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a2b95
// Address: 004a2b95
// XREFS: None
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Main_Error_Screen: "Main Error Screen"
// [HELPER] s_Select_Scenario_Screen: "Select Scenario Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
void FUN_004a2b95(int param_1)
{
  RGE_Base_Game *this;
  int iVar1;
  TribeSelectScenarioScreen *this_00;
  TribeSPMenuScreen *this_01;
  TRIBE_Screen_Main_Error *pTVar2;
  TribeJoinScreen *this_02;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = rge_base_game;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f23c;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = RGE_Base_Game::singlePlayerGame(this);
  if (iVar1 == 0) {
    iVar1 = TCommunications_Handler::IsLobbyLaunched(comm);
    if (iVar1 != 0) {
      if (param_1 != 0) {
        pTVar2 = (TRIBE_Screen_Main_Error *)operator_new(0x484);
        uStack_4 = 2;
        if (pTVar2 == (TRIBE_Screen_Main_Error *)0x0) {
          pTVar2 = (TRIBE_Screen_Main_Error *)0x0;
        }
        else {
          pTVar2 = (TRIBE_Screen_Main_Error *)
                   TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error(pTVar2);
        }
        uStack_4 = 0xffffffff;
        if ((pTVar2 != (TRIBE_Screen_Main_Error *)0x0) && (pTVar2->_padding_ == 0)) {
          TRIBE_Screen_Main_Error::set_text(pTVar2,0x96a);
          pcVar3 = s_Main_Error_Screen;
          goto LAB_004a2d23;
        }
      }
      RGE_Base_Game::close(rge_base_game);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    RGE_Base_Game::disable_input(rge_base_game);
    TCommunications_Handler::UnlinkToLevel(comm,SERVICE_AVAILABLE);
    this_02 = (TribeJoinScreen *)operator_new(0x4b0);
    uStack_4 = 3;
    if (this_02 != (TribeJoinScreen *)0x0) {
      TribeJoinScreen::TribeJoinScreen(this_02);
    }
    uStack_4 = 0xffffffff;
    pcVar3 = s_Join_Screen;
  }
  else {
    RGE_Base_Game::disable_input(rge_base_game);
    iVar1 = RGE_Base_Game::scenarioGame(rge_base_game);
    if (iVar1 == 0) {
      this_01 = (TribeSPMenuScreen *)operator_new(0x49c);
      uStack_4 = 1;
      if (this_01 != (TribeSPMenuScreen *)0x0) {
        TribeSPMenuScreen::TribeSPMenuScreen(this_01);
      }
      uStack_4 = 0xffffffff;
      pcVar3 = s_Single_Player_Menu;
    }
    else {
      this_00 = (TribeSelectScenarioScreen *)operator_new(0x4d8);
      uStack_4 = 0;
      if (this_00 != (TribeSelectScenarioScreen *)0x0) {
        TribeSelectScenarioScreen::TribeSelectScenarioScreen(this_00);
      }
      uStack_4 = 0xffffffff;
      pcVar3 = s_Select_Scenario_Screen;
    }
  }
LAB_004a2d23:
  TPanelSystem::setCurrentPanel(&panel_system,pcVar3,0);
  TPanelSystem::destroyPanel(&panel_system,s_MP_Setup_Screen);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a2d4d
// Address: 004a2d4d
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_mps_cp: "C:\msdev\work\age1_x1\scr_mps.cpp"
// [HELPER] s_____HOST_RESET_CIV_50: "$$$ HOST RESET CIV+50"
// [HELPER] s_____HOST_RESET_TEAM_50: "$$$ HOST RESET TEAM+50"
// [HELPER] s_____RESETTING_MYCIV2: "$$$ RESETTING MYCIV2"
// [HELPER] s_____RESETTING_MYTEAM2: "$$$ RESETTING MYTEAM2"
// [HELPER] s_____USER_COMMAND__CHAT_RECEIVED_: "$$$ USER_COMMAND: CHAT_RECEIVED (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_BAD_VERSI: "$$$ USER_COMMAND: COMM_BAD_VERSION (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_CANCEL_GA: "$$$ USER_COMMAND: COMM_CANCEL_GAME (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_HOST_BUSY: "$$$ USER_COMMAND: COMM_HOST_BUSY (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_HOST_EXIT: "$$$ USER_COMMAND: COMM_HOST_EXITED (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_LAUNCH_GA: "$$$ USER_COMMAND: COMM_LAUNCH_GAME (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_NO_LINK__: "$$$ USER_COMMAND: COMM_NO_LINK (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_OTHER_PLA: "$$$ USER_COMMAND: COMM_OTHER_PLAYER_DROPPED (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_PLAYER_DR: "$$$ USER_COMMAND: COMM_PLAYER_DROPPED (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_PLAYER_KI: "$$$ USER_COMMAND: COMM_PLAYER_KICKED (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_PLAYER_SE: "$$$ USER_COMMAND: COMM_PLAYER_SERVICE_ERROR (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_SHARED_DA: "$$$ USER_COMMAND: COMM_SHARED_DATA_SENT (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_UPDATE_PA: "$$$ USER_COMMAND: COMM_UPDATE_PARAMS (%d,%d)"
// [HELPER] s_____USER_COMMAND__COMM_UPDATE_PL: "$$$ USER_COMMAND: COMM_UPDATE_PLAYERS (%d,%d)"
// [HELPER] s_____USER_COMMAND__UNKNOWN___d___: "$$$ USER_COMMAND: UNKNOWN (%d, %d)"
undefined4 __thiscall FUN_004a2d4d(TribeMPSetupScreen *param_1,int param_2,TDebuggingLog *param_3)
{
  uint uVar1;
  TDebuggingLog *this;
  byte bVar2;
  uchar uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  byte *pbVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  uint uVar11;
  int iVar12;
  bool bVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  long *plStack_128;
  ulong uStack_120;
  ulong uStack_11c;
  ulong uStack_118;
  ulong uStack_114;
  ulong uStack_110;
  ulong uStack_10c;
  ulong uStack_108;
  int iStack_104;
  char acStack_100 [256];
  
  iVar4 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar4 != 0) {
    return 1;
  }
  this = (TDebuggingLog *)(param_2 + -0x17a4);
  switch(param_2) {
  case 0x17a4:
    TDebuggingLog::Log(this,(char *)L,s_____USER_COMMAND__COMM_UPDATE_PL,param_2,param_3);
    bVar13 = false;
    iVar4 = TCommunications_Handler::IsHost(comm);
    if ((iVar4 != 0) && (param_1->sent_cd_status == 0)) {
      param_1->sent_cd_status = 1;
      iVar4 = RGE_Base_Game::check_for_cd(rge_base_game,0);
      if (iVar4 != 0) {
        iVar12 = 1;
        bVar13 = true;
        iVar4 = TCommunications_Handler::WhoAmI(comm);
        RGE_Base_Game::setPlayerHasCD(rge_base_game,iVar4 + -1,iVar12);
      }
    }
    iVar4 = TCommunications_Handler::IsHost(comm);
    if (iVar4 != 0) {
      plStack_128 = param_1->scenarioCheckSum;
      uVar8 = 0;
      do {
        uVar1 = uVar8 + 1;
        iVar4 = TCommunications_Handler::GetPlayerHumanity(comm,uVar1);
        uVar5 = TCommunications_Handler::WhoAmI(comm);
        if (uVar5 == uVar1) {
          if (iVar4 != 2) goto LAB_004a30af;
        }
        else if (iVar4 == 2) {
          TCommunications_Handler::GetClientReadiness
                    (comm,uVar1,&iStack_104,&uStack_118,&uStack_10c,&uStack_114,&uStack_11c,
                     &uStack_120,&uStack_108,&uStack_110);
          if ((uStack_118 != 0) &&
             (uVar6 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,uVar8),
             uStack_118 != uVar6)) {
            TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,uVar8,uStack_118);
            bVar13 = true;
          }
          if (uStack_10c != 0) {
            iVar4 = uStack_10c - 1;
            iVar12 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game,uVar8);
            if (iVar4 != iVar12) {
              TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,uVar8,iVar4);
              bVar13 = true;
            }
          }
          if (uStack_114 != 0) {
            if (uStack_114 == 1) {
              iVar4 = RGE_Base_Game::playerHasCD(rge_base_game,uVar8);
              if (iVar4 == 1) {
                iVar4 = 0;
LAB_004a3014:
                RGE_Base_Game::setPlayerHasCD(rge_base_game,uVar8,iVar4);
                bVar13 = true;
              }
            }
            else if ((uStack_114 == 2) &&
                    (iVar4 = RGE_Base_Game::playerHasCD(rge_base_game,uVar8), iVar4 == 0)) {
              iVar4 = 1;
              goto LAB_004a3014;
            }
          }
          if ((uStack_11c != 0) &&
             (uVar6 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,uVar8),
             uStack_11c != uVar6)) {
            TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,uVar8,uStack_11c);
            bVar13 = true;
          }
          if ((uStack_120 != 0) &&
             (uVar6 = RGE_Base_Game::playerTeam(rge_base_game,uVar8), uStack_120 != uVar6)) {
            RGE_Base_Game::setPlayerTeam(rge_base_game,uVar8,uStack_120);
            bVar13 = true;
          }
          if (uStack_108 != 0) {
            *plStack_128 = uStack_108;
          }
          if (uStack_110 != 0) {
            RGE_Base_Game::setPlayerVersion(rge_base_game,uVar8,(uchar)uStack_110);
            bVar13 = true;
          }
        }
        else {
LAB_004a30af:
          if (iVar4 != 4) {
            uVar5 = debug_rand(s_C__msdev_work_age1_x1_scr_mps_cp,0x6d6);
            uVar11 = (int)uVar5 >> 0x1f;
            iVar12 = (((uVar5 ^ uVar11) - uVar11 & 0xf ^ uVar11) - uVar11) + 1;
            iVar4 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,uVar8);
            if (iVar4 != iVar12) {
              TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,uVar8,iVar12);
              bVar13 = true;
            }
            uVar5 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game,uVar8);
            if (uVar5 != uVar8) {
              TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,uVar8,uVar8);
              bVar13 = true;
            }
            iVar4 = RGE_Base_Game::playerHasCD(rge_base_game,uVar8);
            if (iVar4 != 0) {
              RGE_Base_Game::setPlayerHasCD(rge_base_game,uVar8,0);
              bVar13 = true;
            }
            bVar2 = param_1->defaultColor[uVar8];
            uVar5 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,uVar8);
            if (uVar5 != bVar2) {
              TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,uVar8,(uint)bVar2);
              bVar13 = true;
            }
            iVar4 = RGE_Base_Game::playerTeam(rge_base_game,uVar8);
            if (iVar4 != 1) {
              RGE_Base_Game::setPlayerTeam(rge_base_game,uVar8,1);
              bVar13 = true;
            }
            uVar3 = RGE_Base_Game::playerVersion(rge_base_game,uVar8);
            if (uVar3 != '\0') {
              RGE_Base_Game::setPlayerVersion(rge_base_game,uVar8,'\0');
              bVar13 = true;
            }
            *plStack_128 = 0;
          }
        }
        plStack_128 = plStack_128 + 1;
        uVar8 = uVar1;
      } while ((int)uVar1 < 8);
      if (bVar13) {
        (**(code **)(rge_base_game->_padding_ + 0x48))();
        param_1->resend_game_options = 0;
      }
    }
    TribeMPSetupScreen::fillPlayers(param_1);
    (**(code **)(param_1->_padding_ + 0x20))(1);
    return 1;
  default:
    TDebuggingLog::Log(param_3,(char *)L,s_____USER_COMMAND__UNKNOWN___d___,param_2,param_3);
    return 1;
  case 0x17a6:
    TDebuggingLog::Log(param_3,(char *)L,s_____USER_COMMAND__COMM_UPDATE_PA,param_2,param_3);
    (**(code **)(rge_base_game->_padding_ + 0x4c))();
    iVar12 = 0;
    iVar4 = RGE_Base_Game::numberPlayers(rge_base_game);
    if (0 < iVar4) {
      do {
        iVar4 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar12);
        if (0x31 < iVar4) {
          TDebuggingLog::Log(L,(char *)L,s_____CIV2>50);
          iVar4 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar12);
          TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,iVar12,iVar4 + -0x32);
          iVar4 = TCommunications_Handler::WhoAmI(comm);
          if (iVar12 + 1 == iVar4) {
            param_1->myCivilization = 0;
            TDebuggingLog::Log(this_01,(char *)L,s_____RESETTING_MYCIV2);
          }
        }
        iVar4 = RGE_Base_Game::playerTeam(rge_base_game,iVar12);
        if (0x31 < iVar4) {
          TDebuggingLog::Log(L,(char *)L,s_____TEAM2>50);
          iVar4 = RGE_Base_Game::playerTeam(rge_base_game,iVar12);
          RGE_Base_Game::setPlayerTeam(rge_base_game,iVar12,iVar4 + -0x32);
          iVar4 = TCommunications_Handler::WhoAmI(comm);
          if (iVar12 + 1 == iVar4) {
            param_1->myPlayerTeam = 0;
            TDebuggingLog::Log(this_02,(char *)L,s_____RESETTING_MYTEAM2);
          }
        }
        iVar12 = iVar12 + 1;
        iVar4 = RGE_Base_Game::numberPlayers(rge_base_game);
      } while (iVar12 < iVar4);
    }
    if (param_1->myScenarioPlayer != 0) {
      pbVar7 = (byte *)RGE_Base_Game::scenarioName(rge_base_game);
      pcVar9 = param_1->saveScenarioName;
      do {
        bVar2 = *pcVar9;
        bVar13 = bVar2 < *pbVar7;
        if (bVar2 != *pbVar7) {
LAB_004a33a9:
          iVar4 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          goto LAB_004a33ae;
        }
        if (bVar2 == 0) break;
        bVar2 = pcVar9[1];
        bVar13 = bVar2 < pbVar7[1];
        if (bVar2 != pbVar7[1]) goto LAB_004a33a9;
        pcVar9 = pcVar9 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_004a33ae:
      if (iVar4 != 0) {
        param_1->myScenarioPlayer = -1;
      }
    }
    TribeMPSetupScreen::updateSummary(param_1);
    iVar4 = TCommunications_Handler::IsHost(comm);
    if (iVar4 == 0) {
      if ((param_1->sent_cd_status != 0) &&
         (param_1->myScenarioChecksum == param_1->saveScenarioChecksum)) {
        uVar8 = TCommunications_Handler::WhoAmI(comm);
        iVar4 = TCommunications_Handler::IsPlayerReady(comm,uVar8);
        if (iVar4 == param_1->i_am_ready) {
          return 1;
        }
      }
      uVar6 = param_1->myScenarioChecksum;
      uVar16 = 1;
      uVar15 = 0;
      param_1->sent_cd_status = 1;
      param_1->saveScenarioChecksum = uVar6;
      uVar14 = 0;
      iVar4 = RGE_Base_Game::check_for_cd(rge_base_game,0);
      TCommunications_Handler::SetMyReadiness
                (comm,param_1->i_am_ready,0,0,iVar4 + 1,uVar14,uVar15,uVar6,uVar16);
      return 1;
    }
    break;
  case 0x17a7:
    TDebuggingLog::Log(this,(char *)L,s_____USER_COMMAND__COMM_LAUNCH_GA,param_2,param_3);
    TChat::setWindowHandle(chat,AppWnd);
    TCommunications_Handler::SetWindowHandle(comm,AppWnd);
    TRIBE_Game::start_game((TRIBE_Game *)rge_base_game,0);
    return 1;
  case 0x17a8:
    pcVar9 = s_____USER_COMMAND__COMM_CANCEL_GA;
    goto LAB_004a34da;
  case 0x17a9:
    pcVar9 = s_____USER_COMMAND__COMM_HOST_EXIT;
LAB_004a34da:
    TDebuggingLog::Log(param_3,(char *)L,pcVar9,param_2,param_3);
    TribeMPSetupScreen::handleKickedPlayer(param_1,0);
    return 1;
  case 0x17aa:
    TDebuggingLog::Log(param_3,(char *)L,s_____USER_COMMAND__COMM_PLAYER_KI,param_2,param_3);
    TribeMPSetupScreen::handleKickedPlayer(param_1,1);
    return 1;
  case 0x17ae:
    TDebuggingLog::Log(param_3,(char *)L,s_____USER_COMMAND__COMM_NO_LINK__,param_2,param_3);
    TribeMPSetupScreen::cancelScreen(param_1,0);
    return 1;
  case 0x17b2:
    TDebuggingLog::Log(param_3,(char *)L,s_____USER_COMMAND__COMM_PLAYER_DR,param_2,param_3);
    TribeMPSetupScreen::handleKickedPlayer(param_1,1);
    return 1;
  case 0x17b3:
    TDebuggingLog::Log(param_3,(char *)L,s_____USER_COMMAND__COMM_OTHER_PLA,param_2,param_3);
    TribeMPSetupScreen::fillPlayers(param_1);
    return 1;
  case 0x17b6:
    TDebuggingLog::Log(this,(char *)L,s_____USER_COMMAND__COMM_BAD_VERSI,param_2,param_3);
    pcVar9 = TCommunications_Handler::GetPlayerName(comm,(uint)param_3);
    pcVar10 = TPanel::get_string((TPanel *)param_1,0x25dd);
    sprintf(acStack_100,pcVar10,pcVar9);
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,acStack_100,(char *)0x0,0x1c2,100);
    return 1;
  case 0x17b7:
    TDebuggingLog::Log(this,(char *)L,s_____USER_COMMAND__COMM_PLAYER_SE,param_2,param_3);
    pcVar9 = TCommunications_Handler::GetPlayerName(comm,(uint)param_3);
    pcVar10 = TPanel::get_string((TPanel *)param_1,0x25de);
    sprintf(acStack_100,pcVar10,pcVar9);
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,acStack_100,(char *)0x0,0x1c2,100);
    return 1;
  case 0x17b9:
    TDebuggingLog::Log(param_3,(char *)L,s_____USER_COMMAND__COMM_HOST_BUSY,param_2,param_3);
    iVar4 = TCommunications_Handler::IsLobbyLaunched(comm);
    if (iVar4 != 0) {
      TribeMPSetupScreen::cancelScreen(param_1,1);
      return 1;
    }
    TribeMPSetupScreen::handleKickedPlayer(param_1,0);
    break;
  case 0x17bb:
    TDebuggingLog::Log(param_3,(char *)L,s_____USER_COMMAND__COMM_SHARED_DA,param_2,param_3);
    iVar4 = TCommunications_Handler::IsHost(comm);
    if (iVar4 != 0) {
      iVar12 = 0;
      iVar4 = RGE_Base_Game::numberPlayers(rge_base_game);
      if (0 < iVar4) {
        do {
          iVar4 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar12);
          if (0x31 < iVar4) {
            TDebuggingLog::Log(this_00,(char *)L,s_____HOST_RESET_CIV_50);
            iVar4 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar12);
            TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,iVar12,iVar4 + -0x32);
            param_1->resend_game_options = 1;
          }
          iVar4 = RGE_Base_Game::playerTeam(rge_base_game,iVar12);
          if (0x31 < iVar4) {
            TDebuggingLog::Log(L,(char *)L,s_____HOST_RESET_TEAM_50);
            iVar4 = RGE_Base_Game::playerTeam(rge_base_game,iVar12);
            RGE_Base_Game::setPlayerTeam(rge_base_game,iVar12,iVar4 + -0x32);
            param_1->resend_game_options = 1;
          }
          iVar12 = iVar12 + 1;
          iVar4 = RGE_Base_Game::numberPlayers(rge_base_game);
        } while (iVar12 < iVar4);
        return 1;
      }
    }
    break;
  case 0x17d5:
    TDebuggingLog::Log(this,(char *)L,s_____USER_COMMAND__CHAT_RECEIVED_,param_2,param_3);
    TribeMPSetupScreen::fillChat(param_1,(int)param_3);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a3747
// Address: 004a3747
// XREFS: None
undefined4 __fastcall FUN_004a3747(undefined4 param_1,uint param_2)
{
  int in_EAX;
  char *pcVar1;
  byte bVar2;
  uint *puVar3;
  char cVar4;
  char *unaff_EBX;
  byte *unaff_ESI;
  char *unaff_EDI;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX + cVar4;
  bVar2 = *(byte *)(in_EAX + -1);
  pcVar1 = (char *)(param_2 ^ 0x4a);
  (&stack0x34cc004e)[(int)unaff_ESI] = (&stack0x34cc004e)[(int)unaff_ESI] + cVar4;
  cRame0004a35 = cRame0004a35 + cVar4;
  unaff_ESI[0x3576004a] = unaff_ESI[0x3576004a] + (char)pcVar1;
  *unaff_ESI = *unaff_ESI + (char)in_EAX + -4;
  unaff_ESI[unaff_retaddr + 0x3680004a] =
       unaff_ESI[unaff_retaddr + 0x3680004a] + (char)((uint)param_1 >> 8);
  pcVar1[0x5004a2d] = pcVar1[0x5004a2d] + (char)unaff_EBX;
  bVar2 = (byte)param_1 ^ bVar2 ^ *(byte *)(in_EAX + -6);
  *unaff_EDI = *unaff_EDI - (char)((uint)(in_EAX + -6) >> 8);
  puVar3 = (uint *)(in_EAX + -7);
  *pcVar1 = *pcVar1 + (char)pcVar1;
  *puVar3 = (uint)(pcVar1 + *puVar3);
  *unaff_ESI = *unaff_ESI | bVar2;
  *puVar3 = *puVar3 | CONCAT31((int3)((uint)param_1 >> 8),bVar2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a37c8
// Address: 004a37c8
// XREFS: None
// [HELPER] s_____SETTING_CIV_TEAM_50___d__d_: "$$$ SETTING CIV/TEAM+50 (%d,%d)"
void __fastcall FUN_004a37c8(TribeMPSetupScreen *param_1)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  long lVar6;
  TDropDownPanel *pTVar7;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 uVar8;
  ulong unaff_EBX;
  char *pcVar9;
  ulong uVar10;
  TDropDownPanel **ppTVar11;
  char *pcVar12;
  bool bVar13;
  undefined4 uVar14;
  TTextPanel **ppTStack_14;
  ulong uStack_10;
  char *apcStack_c [3];
  
  iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ((iVar2 != 0) && (iVar2 = TCommunications_Handler::IsHost(comm), iVar2 != 0)) {
    pcVar9 = (char *)0x0;
    uStack_10 = 0;
    iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
    if (0 < iVar2) {
      ppTStack_14 = param_1->playerNameText;
      do {
        pcVar5 = pcVar9 + 1;
        apcStack_c[0] = pcVar5;
        iVar2 = TCommunications_Handler::IsPlayerReady(comm,(uint)pcVar5);
        if ((iVar2 != 0) && ((*ppTStack_14)->text_color1 == 0xff)) {
          pcVar12 = (char *)0x0;
          iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
          if (0 < iVar2) {
            do {
              if ((pcVar9 != pcVar12) &&
                 (iVar2 = TCommunications_Handler::IsPlayerReady(comm,(uint)(pcVar12 + 1)),
                 iVar2 != 0)) {
                iVar2 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,(int)pcVar12);
                iVar3 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,(int)pcVar9);
                if (iVar2 == iVar3) {
                  TDebuggingLog::Log(L,(char *)L,s_____SETTING_CIV_TEAM_50___d__d_,pcVar9);
                  iVar2 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,(int)pcVar9);
                  TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,(int)pcVar12,iVar2 + 0x32)
                  ;
                  iVar2 = RGE_Base_Game::playerTeam(rge_base_game,(int)pcVar9);
                  RGE_Base_Game::setPlayerTeam(rge_base_game,(int)pcVar12,iVar2 + 0x32);
                  uStack_10 = 1;
                }
              }
              pcVar12 = pcVar12 + 1;
              iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
              pcVar5 = apcStack_c[0];
            } while ((int)pcVar12 < iVar2);
          }
        }
        pcVar9 = pcVar5;
        ppTStack_14 = ppTStack_14 + 1;
        iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
      } while ((int)pcVar9 < iVar2);
    }
    if (uStack_10 != 0) {
      (**(code **)(rge_base_game->_padding_ + 0x48))();
    }
  }
  iVar3 = 0;
  iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
  if (0 < iVar2) {
    do {
      iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (iVar2 == 0) {
        if (iVar3 == 0) {
          ppTStack_14 = (TTextPanel **)0x2;
          bVar13 = true;
        }
        else {
          ppTStack_14 = (TTextPanel **)TDropDownPanel::get_id(param_1->playerNameDrop[iVar3]);
          bVar13 = false;
        }
      }
      else {
        ppTStack_14 = (TTextPanel **)TCommunications_Handler::GetPlayerHumanity(comm,iVar3 + 1U);
        uVar4 = TCommunications_Handler::WhoAmI(comm);
        bVar13 = uVar4 == iVar3 + 1U;
      }
      iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if ((iVar2 == 0) || (ppTStack_14 != (TTextPanel **)0x2)) {
        pcVar9 = (char *)0x0;
        (**(code **)(param_1->playerCDText[iVar3]->_padding_ + 0x14))();
        uVar14 = 0;
        iVar2 = param_1->playerVersionText[iVar3]->_padding_;
LAB_004a3ae8:
        (**(code **)(iVar2 + 0x14))(uVar14);
      }
      else {
        iVar2 = param_1->playerCDText[iVar3]->_padding_;
        pcVar9 = (char *)RGE_Base_Game::playerHasCD(rge_base_game,iVar3);
        (**(code **)(iVar2 + 0x14))();
        iVar2 = TCommunications_Handler::IsHost(comm);
        if ((iVar2 != 0) || (uVar1 = RGE_Base_Game::playerVersion(rge_base_game,0), uVar1 != '\0'))
{
          iVar2 = param_1->playerVersionText[iVar3]->_padding_;
          pcVar5 = RGE_Base_Game::playerVersionString(rge_base_game,iVar3);
          (**(code **)(iVar2 + 0xe8))(pcVar5);
          uVar14 = 1;
          iVar2 = param_1->playerVersionText[iVar3]->_padding_;
          goto LAB_004a3ae8;
        }
        if (iVar3 == 0) {
          iVar2 = param_1->playerVersionText[0]->_padding_;
          pcVar5 = RGE_Base_Game::playerVersionString(rge_base_game,0);
          (**(code **)(iVar2 + 0xe8))(pcVar5);
          uVar14 = 1;
          iVar2 = param_1->playerVersionText[0]->_padding_;
          goto LAB_004a3ae8;
        }
        if (bVar13) {
          RGE_Base_Game::setPlayerVersion(rge_base_game,iVar3,'\x01');
          iVar2 = param_1->playerVersionText[iVar3]->_padding_;
          pcVar5 = RGE_Base_Game::playerVersionString(rge_base_game,iVar3);
          (**(code **)(iVar2 + 0xe8))(pcVar5);
          uVar14 = 1;
          iVar2 = param_1->playerVersionText[iVar3]->_padding_;
          goto LAB_004a3ae8;
        }
        (**(code **)(param_1->playerVersionText[iVar3]->_padding_ + 0x14))(0);
      }
      if ((!bVar13) || (iVar2 = param_1->myPlayerColor, iVar2 == 0)) {
        iVar2 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,iVar3);
      }
      TButtonPanel::set_state_by_id(param_1->playerColor[iVar3],iVar2);
      iVar2 = TButtonPanel::get_state(param_1->playerColor[iVar3]);
      TButtonPanel::get_text
                (param_1->playerColor[iVar3],(short)iVar2,(char **)&stack0xffffffe8,apcStack_c);
      TButtonPanel::get_text_color
                (param_1->playerColor[iVar3],(short)iVar2,&uStack_10,(ulong *)&ppTStack_14);
      (**(code **)(param_1->playerColorText[iVar3]->_padding_ + 0xe8))(unaff_EBX);
      TTextPanel::set_text_color(param_1->playerColorText[iVar3],(ulong)ppTStack_14,unaff_EBX);
      (**(code **)(param_1->playerColor[iVar3]->_padding_ + 0x14))(0);
      pcVar5 = (char *)0x0;
      (**(code **)(param_1->playerColorText[iVar3]->_padding_ + 0x14))();
      iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if ((((iVar2 != 0) && (bVar13)) && (param_1->i_am_ready == 0)) ||
         (((iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar2 != 0 && (bVar13)) &&
          (1 < param_1->numberAnyPlayers)))) {
        (**(code **)(param_1->playerColor[iVar3]->_padding_ + 0x14))(1);
        TButtonPanel::set_disabled(param_1->playerColor[iVar3],0);
        uVar8 = extraout_var_00;
        pcVar12 = pcVar9;
      }
      else {
        uVar8 = extraout_var;
        pcVar12 = pcVar9;
        if (pcVar9 == (char *)0x2) {
          (**(code **)(param_1->playerColorText[iVar3]->_padding_ + 0x14))(1);
          uVar8 = extraout_var_01;
        }
      }
      if ((bVar13) && (param_1->myPlayerTeam != 0)) {
        (**(code **)(param_1->playerTeam[iVar3]->_padding_ + 0xe0))
                  (CONCAT22(uVar8,(short)param_1->myPlayerTeam + -1));
      }
      else {
        iVar2 = RGE_Base_Game::playerTeam(rge_base_game,iVar3);
        if (0x31 < iVar2) {
          iVar2 = iVar2 + -0x32;
        }
        (**(code **)(param_1->playerTeam[iVar3]->_padding_ + 0xe0))(iVar2 + -1);
      }
      iVar2 = TButtonPanel::get_state(param_1->playerTeam[iVar3]);
      TButtonPanel::get_text
                (param_1->playerTeam[iVar3],(short)iVar2,(char **)&stack0xffffffd8,
                 (char **)&stack0xffffffe4);
      (**(code **)(param_1->playerTeamText[iVar3]->_padding_ + 0xe8))(pcVar12);
      (**(code **)(param_1->playerTeam[iVar3]->_padding_ + 0x14))(0);
      (**(code **)(param_1->playerTeamText[iVar3]->_padding_ + 0x14))(0);
      iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (((iVar2 != 0) &&
          (((bVar13 && (param_1->i_am_ready == 0)) ||
           ((iVar2 = TCommunications_Handler::IsHost(comm), iVar2 != 0 &&
            ((pcVar9 == (char *)0x4 && (param_1->i_am_ready == 0)))))))) ||
         ((iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar2 != 0 &&
          ((bVar13 || (pcVar9 == (char *)0x4)))))) {
        (**(code **)(param_1->playerTeam[iVar3]->_padding_ + 0x14))(1);
        TButtonPanel::set_disabled(param_1->playerTeam[iVar3],0);
      }
      else if ((pcVar9 == (char *)0x2) || (pcVar9 == (char *)0x4)) {
        (**(code **)(param_1->playerTeamText[iVar3]->_padding_ + 0x14))(1);
      }
      iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (iVar2 != 0) {
        if (pcVar9 == (char *)0x2) {
          iVar2 = TCommunications_Handler::IsPlayerReady(comm,iVar3 + 1);
          uVar10 = 0xff;
          pcVar9 = pcVar5;
          if (iVar2 != 0) goto LAB_004a3d5e;
        }
        else {
LAB_004a3d5e:
          uVar10 = 0xff00;
          pcVar9 = pcVar5;
        }
        TDropDownPanel::set_val_text_color(param_1->playerNameDrop[iVar3],uVar10,0);
        TTextPanel::set_text_color(param_1->playerNameText[iVar3],uVar10,0);
      }
      iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (iVar2 == 0) {
        if (!bVar13) {
          iVar2 = param_1->playerNameText[iVar3]->_padding_;
          goto LAB_004a3e1b;
        }
        (**(code **)(param_1->playerNameText[iVar3]->_padding_ + 0xe4))(0x25b3);
      }
      else {
        lVar6 = TDropDownPanel::get_id(param_1->playerNameDrop[iVar3],0);
        if (lVar6 == 2) {
          TDropDownPanel::delete_line(param_1->playerNameDrop[iVar3],0);
        }
        if (pcVar9 == (char *)0x2) {
          pcVar5 = pcVar9;
          pcVar12 = TCommunications_Handler::GetPlayerName(comm,iVar3 + 1);
          TDropDownPanel::insert_line(param_1->playerNameDrop[iVar3],0,pcVar12,(long)pcVar5);
        }
        lVar6 = TDropDownPanel::get_line(param_1->playerNameDrop[iVar3],(long)pcVar9);
        TDropDownPanel::set_line(param_1->playerNameDrop[iVar3],lVar6);
        iVar2 = param_1->playerNameText[iVar3]->_padding_;
LAB_004a3e1b:
        pcVar9 = TDropDownPanel::get_text(param_1->playerNameDrop[iVar3]);
        (**(code **)(iVar2 + 0xe8))(pcVar9);
      }
      pTVar7 = param_1->playerCivDrop[iVar3];
      if (pTVar7->mode != ModeList) {
        if ((!bVar13) || (iVar2 = param_1->myCivilization, iVar2 == 0)) {
          iVar2 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar3);
          if (0x31 < iVar2) {
            iVar2 = iVar2 + -0x32;
          }
          pTVar7 = param_1->playerCivDrop[iVar3];
        }
        lVar6 = TDropDownPanel::get_line(pTVar7,iVar2);
        TDropDownPanel::set_line(param_1->playerCivDrop[iVar3],lVar6);
      }
      iVar2 = param_1->playerCivText[iVar3]->_padding_;
      pcVar9 = TDropDownPanel::get_text(param_1->playerCivDrop[iVar3]);
      (**(code **)(iVar2 + 0xe8))(pcVar9);
      pTVar7 = param_1->scenarioPlayerDrop[iVar3];
      if (pTVar7->mode != ModeList) {
        if ((!bVar13) || (iVar2 = param_1->myScenarioPlayer, iVar2 == -1)) {
          iVar2 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game,iVar3);
          pTVar7 = param_1->scenarioPlayerDrop[iVar3];
        }
        lVar6 = TDropDownPanel::get_line(pTVar7,iVar2);
        TDropDownPanel::set_line(param_1->scenarioPlayerDrop[iVar3],lVar6);
      }
      iVar2 = param_1->scenarioPlayerText[iVar3]->_padding_;
      pcVar9 = TDropDownPanel::get_text(param_1->scenarioPlayerDrop[iVar3]);
      (**(code **)(iVar2 + 0xe8))();
      iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (((iVar2 == 0) || (iVar2 = TCommunications_Handler::IsHost(comm), iVar2 == 0)) || (bVar13))
{
        (**(code **)(param_1->playerNameDrop[iVar3]->_padding_ + 0x14))(0);
        uVar14 = 1;
        iVar2 = param_1->playerNameText[iVar3]->_padding_;
      }
      else {
        (**(code **)(param_1->playerNameDrop[iVar3]->_padding_ + 0x14))(1);
        iVar2 = param_1->playerNameText[iVar3]->_padding_;
        uVar14 = 0;
      }
      (**(code **)(iVar2 + 0x14))(uVar14);
      (**(code **)(param_1->playerCivDrop[iVar3]->_padding_ + 0x14))(0);
      (**(code **)(param_1->playerCivText[iVar3]->_padding_ + 0x14))(0);
      iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (((iVar2 != 0) &&
          (((bVar13 && (param_1->i_am_ready == 0)) ||
           ((iVar2 = TCommunications_Handler::IsHost(comm), iVar2 != 0 &&
            ((pcVar9 == (char *)0x4 && (param_1->i_am_ready == 0)))))))) ||
         ((iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar2 != 0 &&
          ((bVar13 || (pcVar9 == (char *)0x4)))))) {
        (**(code **)(param_1->playerCivDrop[iVar3]->_padding_ + 0x14))(1);
      }
      else if ((pcVar9 == (char *)0x2) || (pcVar9 == (char *)0x4)) {
        (**(code **)(param_1->playerCivText[iVar3]->_padding_ + 0x14))(1);
      }
      (**(code **)(param_1->scenarioPlayerDrop[iVar3]->_padding_ + 0x14))(0);
      (**(code **)(param_1->scenarioPlayerText[iVar3]->_padding_ + 0x14))(0);
      iVar3 = iVar3 + 1;
      iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
    } while (iVar3 < iVar2);
  }
  if (iVar3 < 8) {
    ppTVar11 = param_1->playerCivDrop + iVar3;
    iVar3 = 8 - iVar3;
    do {
      (**(code **)(ppTVar11[-8]->_padding_ + 0x14))();
      (**(code **)((*ppTVar11)->_padding_ + 0x14))(0);
      (**(code **)(ppTVar11[8]->_padding_ + 0x14))(0);
      (**(code **)(((TButtonPanel *)ppTVar11[-0x18])->_padding_ + 0x14))(0);
      (**(code **)(((TTextPanel *)ppTVar11[-0x28])->_padding_ + 0x14))(0);
      (**(code **)(((TButtonPanel *)ppTVar11[-0x10])->_padding_ + 0x14))(0);
      (**(code **)(((TTextPanel *)ppTVar11[-0x20])->_padding_ + 0x14))(0);
      (**(code **)(((TTextPanel *)ppTVar11[-0x50])->_padding_ + 0x14))(0);
      (**(code **)(((TTextPanel *)ppTVar11[-0x48])->_padding_ + 0x14))(0);
      (**(code **)(((TTextPanel *)ppTVar11[-0x40])->_padding_ + 0x14))(0);
      (**(code **)(((TTextPanel *)ppTVar11[-0x38])->_padding_ + 0x14))(0);
      (**(code **)(((TTextPanel *)ppTVar11[-0x30])->_padding_ + 0x14))(0);
      ppTVar11 = ppTVar11 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  TribeMPSetupScreen::fillPlayerColors(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004a40f6
// Address: 004a40f6
// XREFS: None
void __thiscall FUN_004a40f6(int param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar2 == 0) {
    iVar2 = TTextPanel::numberLines(*(TTextPanel **)(param_1 + 0x618));
    if ((iVar2 < 1) || ((int)*(short *)(*(int *)(param_1 + 0x618) + 0xfe) != iVar2 + -1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (99 < iVar2) {
      TTextPanel::delete_line(*(TTextPanel **)(param_1 + 0x618),0);
    }
    pcVar3 = TChat::GetChatMsg(chat,param_2);
    TTextPanel::word_wrap_append(*(TTextPanel **)(param_1 + 0x618),pcVar3);
    if (bVar1) {
      TTextPanel::scroll(*(TTextPanel **)(param_1 + 0x618),'\a',0,1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004a4187
// Address: 004a4187
// XREFS: None
void __fastcall FUN_004a4187(TribeMPSetupScreen *param_1)
{
  char cVar1;
  bool bVar2;
  uchar uVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  T_Scenario *pTVar8;
  long lVar9;
  MapSize MVar10;
  MapType MVar11;
  VictoryType VVar12;
  Age AVar13;
  ResourceLevel RVar14;
  uint uVar15;
  uint uVar16;
  char *pcVar17;
  TDropDownPanel **ppTVar18;
  TTextPanel **ppTVar19;
  int *piVar20;
  long *plVar21;
  int *piVar22;
  char *pcVar23;
  bool bVar24;
  undefined4 uVar25;
  undefined1 *puVar26;
  int iVar27;
  int iStack_534;
  char acStack_530 [180];
  undefined1 auStack_47c [8];
  undefined1 auStack_474 [8];
  undefined1 auStack_46c [8];
  undefined1 auStack_464 [8];
  undefined1 auStack_45c [8];
  char acStack_454 [36];
  char acStack_430 [256];
  char acStack_330 [816];
  
  bVar2 = false;
  iVar5 = RGE_Base_Game::scenarioGame(rge_base_game);
  iVar7 = param_1->saveRandomGame;
  if (iVar5 == 0) {
joined_r0x004a41fd:
    if (iVar7 == 0) goto LAB_004a41ff;
  }
  else {
    if (iVar7 == 0) {
      pcVar17 = param_1->saveScenarioName;
      pbVar6 = (byte *)RGE_Base_Game::scenarioName(rge_base_game);
      do {
        bVar4 = *pbVar6;
        bVar24 = bVar4 < (byte)*pcVar17;
        if (bVar4 != *pcVar17) {
LAB_004a41f0:
          iVar7 = (1 - (uint)bVar24) - (uint)(bVar24 != 0);
          goto joined_r0x004a41fd;
        }
        if (bVar4 == 0) break;
        bVar4 = pbVar6[1];
        bVar24 = bVar4 < (byte)pcVar17[1];
        if (bVar4 != pcVar17[1]) goto LAB_004a41f0;
        pbVar6 = pbVar6 + 2;
        pcVar17 = pcVar17 + 2;
      } while (bVar4 != 0);
      iVar7 = 0;
      goto joined_r0x004a41fd;
    }
LAB_004a41ff:
    bVar2 = true;
  }
  if (bVar2) {
    iVar7 = RGE_Base_Game::scenarioGame(rge_base_game);
    if (iVar7 != 0) {
      iVar7 = 0;
      if (param_1->scenarioInfo != (T_Scenario *)0x0) {
        (**(code **)(param_1->scenarioInfo->_padding_ + 4))();
        param_1->scenarioInfo = (T_Scenario *)0x0;
      }
      RGE_Base_Game::scenarioName(rge_base_game);
      sprintf();
      iVar5 = __findfirst();
      if (iVar5 == -1) {
        RGE_Base_Game::scenarioName(rge_base_game);
      }
      else {
        RGE_Base_Game::scenarioName(rge_base_game);
      }
      sprintf();
      if (acStack_530[0] != '.') {
        pTVar8 = (T_Scenario *)RGE_Base_Game::get_scenario_info(rge_base_game,acStack_530,0);
        param_1->scenarioInfo = pTVar8;
      }
      if (param_1->scenarioInfo == (T_Scenario *)0x0) {
        RGE_Base_Game::setScenarioGame(rge_base_game,0);
      }
      else {
        ppTVar18 = param_1->scenarioPlayerDrop;
        iVar5 = 8;
        do {
          TDropDownPanel::empty_list(*ppTVar18);
          ppTVar18 = ppTVar18 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar5 = T_Scenario::any_sp_victory(param_1->scenarioInfo);
        param_1->settingsFixed = iVar5;
        param_1->numberAnyPlayers = 0;
        param_1->scenarioPlayerCount = 0;
        do {
          iVar5 = RGE_Scenario::Get_player_Active((RGE_Scenario *)param_1->scenarioInfo,iVar7);
          if (iVar5 != 0) {
            param_1->scenarioPlayerCount = param_1->scenarioPlayerCount + 1;
            sprintf();
            iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
            if ((iVar5 != 0) ||
               ((iVar5 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar5 != 0 &&
                (iVar5 = RGE_Scenario::Get_player_Type((RGE_Scenario *)param_1->scenarioInfo,iVar7),
                iVar5 == 1)))) {
              ppTVar18 = param_1->scenarioPlayerDrop;
              iVar5 = 8;
              param_1->numberAnyPlayers = param_1->numberAnyPlayers + 1;
              do {
                TDropDownPanel::append_line(*ppTVar18,acStack_430,iVar7);
                ppTVar18 = ppTVar18 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 9);
        iVar7 = -1;
        iVar5 = 0;
        do {
          do {
            iVar7 = iVar7 + 1;
            if (iVar7 == 9) {
              iVar7 = 0;
            }
            iVar27 = RGE_Scenario::Get_player_Active((RGE_Scenario *)param_1->scenarioInfo,iVar7);
          } while (iVar27 == 0);
          param_1->defaultColor[iVar5] = (char)iVar7 + '\x01';
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,iVar5,iVar7);
          TRIBE_Game::setPlayerColor
                    ((TRIBE_Game *)rge_base_game,iVar5,(uint)param_1->defaultColor[iVar5]);
          RGE_Base_Game::setPlayerTeam(rge_base_game,iVar5,1);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 8);
      }
    }
    iVar7 = RGE_Base_Game::randomGame(rge_base_game);
    if (iVar7 != 0) {
      ppTVar18 = param_1->scenarioPlayerDrop;
      iVar7 = 8;
      do {
        TDropDownPanel::empty_list(*ppTVar18);
        ppTVar18 = ppTVar18 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      param_1->scenarioPlayerCount = 8;
      param_1->numberAnyPlayers = 8;
      iVar7 = 0;
      iStack_534 = 1 - (int)param_1->defaultColor;
      param_1->settingsFixed = 0;
      do {
        param_1->defaultColor[iVar7] = (char)iVar7 + 1;
        TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,iVar7,iVar7);
        TRIBE_Game::setPlayerColor
                  ((TRIBE_Game *)rge_base_game,iVar7,(uint)param_1->defaultColor[iVar7]);
        RGE_Base_Game::setPlayerTeam(rge_base_game,iVar7,1);
        sprintf();
        ppTVar18 = param_1->scenarioPlayerDrop;
        iVar5 = 8;
        do {
          TDropDownPanel::append_line(*ppTVar18,acStack_430,iVar7);
          ppTVar18 = ppTVar18 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 8);
    }
    iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if (iVar7 != 0) {
      TribeMPSetupScreen::setupSinglePlayerPlayers(param_1);
    }
    iVar7 = RGE_Base_Game::randomGame(rge_base_game);
    param_1->saveRandomGame = iVar7;
    if (iVar7 == 0) {
      pcVar17 = RGE_Base_Game::scenarioName(rge_base_game);
      uVar15 = 0xffffffff;
      do {
        pcVar23 = pcVar17;
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        pcVar23 = pcVar17 + 1;
        cVar1 = *pcVar17;
        pcVar17 = pcVar23;
      } while (cVar1 != '\0');
      uVar15 = ~uVar15;
      pcVar17 = pcVar23 + -uVar15;
      pcVar23 = param_1->saveScenarioName;
      for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(undefined4 *)pcVar23 = *(undefined4 *)pcVar17;
        pcVar17 = pcVar17 + 4;
        pcVar23 = pcVar23 + 4;
      }
      for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
        *pcVar23 = *pcVar17;
        pcVar17 = pcVar17 + 1;
        pcVar23 = pcVar23 + 1;
      }
    }
    else {
      param_1->saveScenarioName[0] = '\0';
    }
    plVar21 = param_1->scenarioCheckSum;
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *plVar21 = 0;
      plVar21 = plVar21 + 1;
    }
    iVar7 = RGE_Base_Game::scenarioGame(rge_base_game);
    if (iVar7 == 0) {
      param_1->myScenarioChecksum = 0;
    }
    else {
      RGE_Base_Game::scenarioName(rge_base_game);
      sprintf();
      iVar7 = __findfirst();
      if (iVar7 == -1) {
        RGE_Base_Game::scenarioName(rge_base_game);
      }
      else {
        RGE_Base_Game::scenarioName(rge_base_game);
      }
      sprintf();
      lVar9 = RGE_Base_Game::get_scenario_checksum(rge_base_game,acStack_330);
      param_1->myScenarioChecksum = lVar9;
    }
  }
  ppTVar19 = param_1->settingText;
  iVar7 = 0x14;
  do {
    (**(code **)((*ppTVar19)->_padding_ + 0x14))();
    ppTVar19 = ppTVar19 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar7 == 0) {
    uVar3 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
    if (uVar3 == '\0') {
      iVar7 = 0x25b5;
    }
    else {
      iVar7 = 0x2617;
    }
    TPanel::get_string((TPanel *)param_1,iVar7,acStack_530,0x100);
    TPanel::get_string((TPanel *)param_1,0x25ed);
    sprintf();
    (**(code **)(param_1->scenarioName->_padding_ + 0xe8))();
    iVar7 = 1;
  }
  else {
    RGE_Base_Game::scenarioName(rge_base_game);
    TPanel::get_string((TPanel *)param_1,0x25ed);
    sprintf();
    (**(code **)(param_1->scenarioName->_padding_ + 0xe8))();
    iVar7 = 3;
  }
  iVar5 = RGE_Base_Game::randomGame(rge_base_game);
  if (iVar5 != 0) {
    MVar10 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
    switch(MVar10) {
    case Tiny:
      iVar5 = 0x2973;
      break;
    case Small:
      iVar5 = 0x2974;
      break;
    case Medium:
      iVar5 = 0x2975;
      break;
    case Large:
      iVar5 = 0x2976;
      break;
    case Huge:
      iVar5 = 0x2977;
      break;
    case Humongous:
      iVar5 = 0x2978;
      break;
    default:
      goto switchD_004a470b_default;
    }
    pcVar17 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar15 = 0xffffffff;
    do {
      pcVar23 = pcVar17;
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      pcVar23 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar23;
    } while (cVar1 != '\0');
    uVar15 = ~uVar15;
    piVar20 = (int *)(pcVar23 + -uVar15);
    piVar22 = &iStack_534;
    for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
      *piVar22 = *piVar20;
      piVar20 = piVar20 + 1;
      piVar22 = piVar22 + 1;
    }
    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(char *)piVar22 = (char)*piVar20;
      piVar20 = (int *)((int)piVar20 + 1);
      piVar22 = (int *)((int)piVar22 + 1);
    }
switchD_004a470b_default:
    TPanel::get_string((TPanel *)param_1,0x25da);
    sprintf();
    (**(code **)(param_1->settingText[iVar7]->_padding_ + 0xe8))();
    (**(code **)(param_1->settingText[iVar7]->_padding_ + 0x14))();
    MVar11 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
    switch(MVar11) {
    case AllWater:
      iVar5 = 0x296a;
      break;
    case MostlyWater:
      iVar5 = 0x296b;
      break;
    case WaterAndLand:
      iVar5 = 0x296c;
      break;
    case MostlyLand:
      iVar5 = 0x296d;
      break;
    case AllLand:
      iVar5 = 0x296e;
      break;
    case Continental:
      iVar5 = 0x296f;
      break;
    case Lake:
      iVar5 = 0x2970;
      break;
    case Hilly:
      iVar5 = 0x2971;
      break;
    case Isthmas:
      iVar5 = 0x2972;
      break;
    default:
      goto switchD_004a47bc_default;
    }
    pcVar17 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar15 = 0xffffffff;
    do {
      pcVar23 = pcVar17;
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      pcVar23 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar23;
    } while (cVar1 != '\0');
    uVar15 = ~uVar15;
    pcVar17 = pcVar23 + -uVar15;
    pcVar23 = &stack0xfffffac4;
    for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(undefined4 *)pcVar23 = *(undefined4 *)pcVar17;
      pcVar17 = pcVar17 + 4;
      pcVar23 = pcVar23 + 4;
    }
    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *pcVar23 = *pcVar17;
      pcVar17 = pcVar17 + 1;
      pcVar23 = pcVar23 + 1;
    }
switchD_004a47bc_default:
    TPanel::get_string((TPanel *)param_1,0x25b6);
    sprintf();
    (**(code **)(param_1->settingText[iVar7 + 1]->_padding_ + 0xe8))();
    (**(code **)(param_1->settingText[iVar7 + 1]->_padding_ + 0x14))();
    iVar7 = iVar7 + 2;
  }
  iVar5 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar5 == 0) {
    TPanel::get_string((TPanel *)param_1,0x25b7);
    sprintf();
  }
  else if ((param_1->settingsFixed == 0) && (param_1->scenarioPlayerCount != 2)) {
    TPanel::get_string((TPanel *)param_1,0x25b7);
    sprintf();
  }
  else {
    TPanel::get_string((TPanel *)param_1,0x25b7);
    sprintf();
  }
  (**(code **)(param_1->settingText[iVar7]->_padding_ + 0xe8))();
  (**(code **)(param_1->settingText[iVar7]->_padding_ + 0x14))();
  VVar12 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  switch(VVar12) {
  case VictoryConquest:
    iVar5 = 0x10e1;
    break;
  default:
    iVar5 = RGE_Base_Game::randomGame(rge_base_game);
    if (iVar5 != 0) goto switchD_004a4941_caseD_9;
    iVar5 = 0x10e7;
    break;
  case VictoryTime:
    iVar5 = 0x10e9;
    goto LAB_004a495e;
  case VictoryScore:
    iVar5 = 0x10ea;
LAB_004a495e:
    pcVar17 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar15 = 0xffffffff;
    do {
      pcVar23 = pcVar17;
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      pcVar23 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar23;
    } while (cVar1 != '\0');
    uVar15 = ~uVar15;
    pcVar17 = pcVar23 + -uVar15;
    pcVar23 = &stack0xfffffac4;
    for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(undefined4 *)pcVar23 = *(undefined4 *)pcVar17;
      pcVar17 = pcVar17 + 4;
      pcVar23 = pcVar23 + 4;
    }
    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *pcVar23 = *pcVar17;
      pcVar17 = pcVar17 + 1;
      pcVar23 = pcVar23 + 1;
    }
    TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
    TPanel::get_string((TPanel *)param_1,0x25be);
    sprintf();
    goto LAB_004a4a1f;
  case VictoryStandard:
switchD_004a4941_caseD_9:
    iVar5 = 0x10ec;
  }
  pcVar17 = TPanel::get_string((TPanel *)param_1,iVar5);
  uVar15 = 0xffffffff;
  do {
    pcVar23 = pcVar17;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar23 = pcVar17 + 1;
    cVar1 = *pcVar17;
    pcVar17 = pcVar23;
  } while (cVar1 != '\0');
  uVar15 = ~uVar15;
  pcVar17 = pcVar23 + -uVar15;
  pcVar23 = &stack0xfffffac4;
  for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar23 = *(undefined4 *)pcVar17;
    pcVar17 = pcVar17 + 4;
    pcVar23 = pcVar23 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar23 = *pcVar17;
    pcVar17 = pcVar17 + 1;
    pcVar23 = pcVar23 + 1;
  }
  TPanel::get_string((TPanel *)param_1,0x25bc);
  sprintf();
LAB_004a4a1f:
  (**(code **)(param_1->settingText[iVar7 + 1]->_padding_ + 0xe8))();
  (**(code **)(param_1->settingText[iVar7 + 1]->_padding_ + 0x14))();
  AVar13 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar13 == DefaultAge) {
    iVar5 = 0x10e7;
  }
  else if (AVar13 == NomadAge) {
    iVar5 = 0x106e;
  }
  else {
    iVar5 = AVar13 + 0x1067;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffabc,0x100);
  TPanel::get_string((TPanel *)param_1,0x25e4);
  sprintf();
  (**(code **)(param_1->settingText[iVar7 + 2]->_padding_ + 0xe8))();
  (**(code **)(param_1->settingText[iVar7 + 2]->_padding_ + 0x14))();
  RVar14 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  if (RVar14 == DefaultResources) {
    iVar5 = 0x10e7;
  }
  else {
    iVar5 = RVar14 + 0x25e5;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffab4,0x100);
  TPanel::get_string((TPanel *)param_1,0x25e5);
  sprintf();
  (**(code **)(param_1->settingText[iVar7 + 3]->_padding_ + 0xe8))();
  (**(code **)(param_1->settingText[iVar7 + 3]->_padding_ + 0x14))();
  RGE_Base_Game::difficulty(rge_base_game);
  pcVar17 = &stack0xfffffaac;
  iVar27 = 0x100;
  iVar5 = RGE_Base_Game::difficulty(rge_base_game);
  TPanel::get_string((TPanel *)param_1,iVar5 + 0x2bd0,pcVar17,iVar27);
  TPanel::get_string((TPanel *)param_1,0x25e0,acStack_454,0x100);
  sprintf();
  (**(code **)(param_1->settingText[iVar7 + 4]->_padding_ + 0xe8))();
  (**(code **)(param_1->settingText[iVar7 + 4]->_padding_ + 0x14))();
  iVar5 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa3;
  }
  else {
    iVar5 = 0xfa4;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffaa4,0x100);
  pcVar17 = TPanel::get_string((TPanel *)param_1,0x25e9);
  sprintf(auStack_45c,pcVar17);
  (**(code **)(param_1->settingText[iVar7 + 5]->_padding_ + 0xe8))();
  (**(code **)(param_1->settingText[iVar7 + 5]->_padding_ + 0x14))(1);
  iVar5 = RGE_Base_Game::fullVisibility(rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa4;
  }
  else {
    iVar5 = 0xfa3;
  }
  pcVar17 = TPanel::get_string((TPanel *)param_1,iVar5);
  uVar15 = 0xffffffff;
  do {
    pcVar23 = pcVar17;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar23 = pcVar17 + 1;
    cVar1 = *pcVar17;
    pcVar17 = pcVar23;
  } while (cVar1 != '\0');
  uVar15 = ~uVar15;
  pcVar17 = pcVar23 + -uVar15;
  pcVar23 = &stack0xfffffa9c;
  for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar23 = *(undefined4 *)pcVar17;
    pcVar17 = pcVar17 + 4;
    pcVar23 = pcVar23 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar23 = *pcVar17;
    pcVar17 = pcVar17 + 1;
    pcVar23 = pcVar23 + 1;
  }
  puVar26 = &stack0xfffffa9c;
  pcVar17 = TPanel::get_string((TPanel *)param_1,0x25b8);
  sprintf(auStack_464,pcVar17,puVar26);
  (**(code **)(param_1->settingText[iVar7 + 6]->_padding_ + 0xe8))(auStack_464);
  (**(code **)(param_1->settingText[iVar7 + 6]->_padding_ + 0x14))(1);
  iVar5 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa4;
  }
  else {
    iVar5 = 0xfa3;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffa94,0x100);
  puVar26 = &stack0xfffffa94;
  pcVar17 = TPanel::get_string((TPanel *)param_1,0x25ec);
  sprintf(auStack_46c,pcVar17,puVar26);
  (**(code **)(param_1->settingText[iVar7 + 7]->_padding_ + 0xe8))(auStack_46c);
  (**(code **)(param_1->settingText[iVar7 + 7]->_padding_ + 0x14))(1);
  iVar27 = iVar7 + 8;
  iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar5 != 0) {
    iVar5 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    if (iVar5 == 0) {
      iVar5 = 0xfa4;
    }
    else {
      iVar5 = 0xfa3;
    }
    pcVar17 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar15 = 0xffffffff;
    do {
      pcVar23 = pcVar17;
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      pcVar23 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar23;
    } while (cVar1 != '\0');
    uVar15 = ~uVar15;
    pcVar17 = pcVar23 + -uVar15;
    pcVar23 = &stack0xfffffa8c;
    for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(undefined4 *)pcVar23 = *(undefined4 *)pcVar17;
      pcVar17 = pcVar17 + 4;
      pcVar23 = pcVar23 + 4;
    }
    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *pcVar23 = *pcVar17;
      pcVar17 = pcVar17 + 1;
      pcVar23 = pcVar23 + 1;
    }
    puVar26 = &stack0xfffffa8c;
    pcVar17 = TPanel::get_string((TPanel *)param_1,0x25bb);
    sprintf(auStack_474,pcVar17,puVar26);
    (**(code **)(param_1->settingText[iVar7 + 8]->_padding_ + 0xe8))(auStack_474);
    (**(code **)(param_1->settingText[iVar7 + 8]->_padding_ + 0x14))(1);
    iVar27 = iVar7 + 9;
  }
  iVar7 = RGE_Base_Game::multiplayerGame(rge_base_game);
  iVar5 = 0x100;
  if (iVar7 == 0) {
    pcVar17 = &stack0xfffffa8c;
    bVar4 = RGE_Base_Game::pathFinding(rge_base_game);
  }
  else {
    pcVar17 = &stack0xfffffa8c;
    bVar4 = RGE_Base_Game::mpPathFinding(rge_base_game);
  }
  TPanel::get_string((TPanel *)param_1,bVar4 + 0x260e,pcVar17,iVar5);
  puVar26 = &stack0xfffffa8c;
  pcVar17 = TPanel::get_string((TPanel *)param_1,0x25f1);
  sprintf(auStack_474,pcVar17,puVar26);
  (**(code **)(param_1->settingText[iVar27]->_padding_ + 0xe8))(auStack_474);
  (**(code **)(param_1->settingText[iVar27]->_padding_ + 0x14))(1);
  bVar4 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
  uVar15 = (uint)bVar4;
  pcVar17 = TPanel::get_string((TPanel *)param_1,0x25f0);
  sprintf(auStack_47c,pcVar17,uVar15);
  (**(code **)(param_1->settingText[iVar27 + 1]->_padding_ + 0xe8))(auStack_47c);
  (**(code **)(param_1->settingText[iVar27 + 1]->_padding_ + 0x14))(1);
  iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar7 != 0) {
    iVar7 = RGE_Base_Game::scenarioGame(rge_base_game);
    if ((iVar7 == 0) || ((param_1->settingsFixed == 0 && (2 < param_1->scenarioPlayerCount)))) {
      (**(code **)(param_1->numberPlayersTitle->_padding_ + 0x14))(1);
      uVar25 = 1;
      iVar7 = param_1->numberPlayersDrop->_padding_;
    }
    else {
      (**(code **)(param_1->numberPlayersTitle->_padding_ + 0x14))(0);
      uVar25 = 0;
      iVar7 = param_1->numberPlayersDrop->_padding_;
    }
    (**(code **)(iVar7 + 0x14))(uVar25);
  }
  TribeMPSetupScreen::fillPlayers(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004a4f52
// Address: 004a4f52
// XREFS: None
// [HELPER] s_Kick_Dialog: "Kick Dialog"
void __fastcall FUN_004a4f52(char *param_1,int param_2,uint param_3)
{
  char cVar1;
  char cVar4;
  undefined4 in_EAX;
  char *pcVar2;
  char *pcVar3;
  char cVar5;
  char cVar7;
  int iVar6;
  char cVar8;
  int iVar9;
  int iVar10;
  char unaff_BL;
  char unaff_BH;
  char cVar11;
  char *unaff_ESI;
  int unaff_EDI;
  char in_CF;
  char acStack_100 [256];
  
  cVar1 = (char)in_EAX + *(char *)(unaff_EDI + 0x4a) + in_CF;
  pcVar2 = (char *)CONCAT31((int3)((uint)in_EAX >> 8),cVar1);
  *param_1 = *param_1 + unaff_BL;
  cVar4 = (char)((uint)in_EAX >> 8);
  *pcVar2 = *pcVar2 + cVar4;
  *(char *)(unaff_EDI + 2) = *(char *)(unaff_EDI + 2) + cVar4;
  cVar7 = (char)((uint)param_1 >> 8);
  *unaff_ESI = *unaff_ESI + cVar7;
  cRamc3004a47 = cRamc3004a47 + (char)((uint)(param_2 + -4) >> 8);
  cVar8 = (char)(param_2 + -5) + (char)param_1;
  cVar5 = (char)param_1 + cVar8 + -1;
  cVar11 = unaff_BH + unaff_BL;
  iVar9 = CONCAT31((int3)((uint)(param_2 + -5) >> 8),cVar8) + -4;
  iVar6 = CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar7 * '\x02',cVar5));
  iVar10 = CONCAT11((char)((uint)iVar9 >> 8) + cVar4,(char)iVar9) - 2;
  iVar9 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   CONCAT11(cVar4 + (char)((uint)iVar10 >> 8),cVar1 + unaff_BL));
  *(char *)(iVar9 + 0x49) = *(char *)(iVar9 + 0x49) + cVar5;
  *(char *)(iVar9 + -0x47ffb5b7) = *(char *)(iVar9 + -0x47ffb5b7) + cVar11;
  *(char *)(iVar9 + -0x47ffb5b7) = *(char *)(iVar9 + -0x47ffb5b7) + cVar11;
  *(char *)(iVar9 + 0x52004a49) = *(char *)(iVar9 + 0x52004a49) + cVar11;
  *(char *)(iVar6 + 0x46) = *(char *)(iVar6 + 0x46) + unaff_BL + cVar11;
  *(char *)(iVar9 + -0x6f6f6f70) = *(char *)(iVar9 + -0x6f6f6f70) + (char)iVar10 + -8;
  *(uint *)(iVar6 + 0x720) = param_3;
  pcVar2 = TCommunications_Handler::GetPlayerName(comm,param_3);
  pcVar3 = TPanel::get_string((TPanel *)(iVar6 + -4),0x25c8);
  sprintf(acStack_100,pcVar3,pcVar2);
  TEasy_Panel::popupYesNoDialog((TEasy_Panel *)(iVar6 + -4),acStack_100,&s_Kick_Dialog,0x1c2,100);
  return;
}

// --------------------------------------------------

// Function: FUN_004a501c
// Address: 004a501c
// XREFS: None
void __thiscall FUN_004a501c(TribeMPSetupScreen *param_1,int param_2)
{
  TEasy_Panel *this;
  
  TribeMPSetupScreen::cancelScreen(param_1,0);
  this = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  if (this != (TEasy_Panel *)0x0) {
    TEasy_Panel::popupOKDialog(this,0x25ca - (uint)(param_2 != 0),(char *)0x0,0x1c2,100);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004a5057
// Address: 004a5057
// XREFS: None
void __fastcall FUN_004a5057(int param_1)
{
  long lVar1;
  
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x6f4));
  if ((lVar1 == 1) ||
     (lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x6f4)), lVar1 == 0)) {
    (**(code **)(**(int **)(param_1 + 0x6f8) + 0x14))(0);
    (**(code **)(**(int **)(param_1 + 0x6fc) + 0x14))(0);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x6f8) + 0x14))(1);
    (**(code **)(**(int **)(param_1 + 0x6fc) + 0x14))(1);
    lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x6f4));
    switch(lVar1) {
    case 2:
      (**(code **)(**(int **)(param_1 + 0x6f8) + 0xe4))(0x25cb);
      return;
    case 3:
    case 4:
    case 5:
      (**(code **)(**(int **)(param_1 + 0x6f8) + 0xe4))(0x25cc);
      return;
    case 6:
      (**(code **)(**(int **)(param_1 + 0x6f8) + 0xe4))(0x25cd);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004a5115
// Address: 004a5115
// XREFS: None
void FUN_004a5115(void)
{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 in_EAX;
  int unaff_ESI;
  
  pbVar1 = (byte *)(CONCAT22((short)((uint)in_EAX >> 0x10),
                             CONCAT11((char)((uint)in_EAX >> 8) * '\x02',(char)in_EAX)) +
                   -0x7c6f6f70);
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 + 0x4c;
  in(0x4a4c);
  *(char *)(unaff_ESI + -0x75) = *(char *)(unaff_ESI + -0x75) + 'L' + (0xb3 < bVar2);
  pcVar3 = (code *)swi(1);
  (*pcVar3)();
  return;
}

// --------------------------------------------------

// Function: FUN_004a520f
// Address: 004a520f
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_mps_cp: "C:\msdev\work\age1_x1\scr_mps.cpp"
void __fastcall FUN_004a520f(TribeMPSetupScreen *param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar1 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      uVar6 = debug_rand(s_C__msdev_work_age1_x1_scr_mps_cp,0xb31);
      uVar3 = (int)uVar6 >> 0x1f;
      TRIBE_Game::setCivilization
                ((TRIBE_Game *)rge_base_game,iVar1,
                 (((uVar6 ^ uVar3) - uVar3 & 0xf ^ uVar3) - uVar3) + 1);
      iVar4 = iVar1 + 1;
      TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,iVar1,iVar4);
      iVar1 = iVar4;
    } while (iVar4 < 8);
  }
  else {
    iVar1 = -1;
    iStack_c = -1;
    iStack_8 = -1;
    iStack_4 = -1;
    if (param_1->scenarioInfo != (T_Scenario *)0x0) {
      iVar4 = 0;
      iVar5 = 0;
      do {
        iVar2 = RGE_Scenario::Get_player_Active((RGE_Scenario *)param_1->scenarioInfo,iVar5);
        if (iVar2 != 0) {
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,iVar4,iVar5);
          iVar1 = RGE_Scenario::Get_player_Civ((RGE_Scenario *)param_1->scenarioInfo,iVar5);
          TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,iVar4,iVar1);
          TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,iVar4,iVar5 + 1);
          iVar1 = RGE_Scenario::Get_player_Type((RGE_Scenario *)param_1->scenarioInfo,iVar5);
          if ((iVar1 == 1) && (iStack_c == -1)) {
            iStack_8 = RGE_Scenario::Get_player_Civ((RGE_Scenario *)param_1->scenarioInfo,iVar5);
            iStack_c = iVar5;
            iStack_4 = iVar5 + 1;
          }
          iVar4 = iVar4 + 1;
          iVar1 = iStack_c;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
    }
    RGE_Base_Game::setNumberPlayers(rge_base_game,param_1->scenarioPlayerCount);
    if (iVar1 != -1) {
      iVar4 = 1;
      if (1 < param_1->scenarioPlayerCount) {
        do {
          iVar5 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game,iVar4);
          if (iVar5 == iVar1) {
            iVar5 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game,0);
            TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,iVar4,iVar5);
            iVar5 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,0);
            TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,iVar4,iVar5);
            iVar5 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,0);
            TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,iVar4,iVar5);
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_1->scenarioPlayerCount);
      }
      TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,0,iVar1);
      TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game,0,iStack_8);
      TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,0,iStack_4);
    }
  }
  iVar1 = 0;
  do {
    RGE_Base_Game::setPlayerTeam(rge_base_game,iVar1,1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  TCommunications_Handler::SetPlayerHumanity(comm,1,ME_HUMAN);
  uVar6 = 2;
  do {
    TCommunications_Handler::SetPlayerHumanity(comm,uVar6,ME_COMPUTER);
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 9);
  TCommunications_Handler::SetPlayerHumanity(comm,9,ME_ABSENT);
  TribeMPSetupScreen::fillNumberPlayers(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004a543c
// Address: 004a543c
// XREFS: None
// [HELPER] s__d: "%d"
void __fastcall FUN_004a543c(int param_1)
{
  long lVar1;
  int iVar2;
  char acStack_10 [16];
  
  TDropDownPanel::empty_list(*(TDropDownPanel **)(param_1 + 0x6e0));
  iVar2 = 2;
  if (1 < *(int *)(param_1 + 0x728)) {
    do {
      sprintf(acStack_10,&s__d,iVar2);
      TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x6e0),acStack_10,iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(param_1 + 0x728));
  }
  iVar2 = RGE_Base_Game::numberPlayers(rge_base_game);
  lVar1 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x6e0),iVar2);
  TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x6e0),lVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_004a54b9
// Address: 004a54b9
// XREFS: None
// [HELPER] s__d: "%d"
void __fastcall FUN_004a54b9(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  ulong uVar5;
  int iStack_18;
  char acStack_10 [16];
  
  puVar4 = (undefined4 *)(param_1 + 0x570);
  iStack_18 = 8;
  do {
    iVar2 = 0;
    iVar3 = 0;
    do {
      iVar1 = RGE_Base_Game::scenarioGame(rge_base_game);
      if (((iVar1 == 0) || (*(RGE_Scenario **)(param_1 + 0x848) == (RGE_Scenario *)0x0)) ||
         ((iVar1 = RGE_Scenario::Get_player_Active(*(RGE_Scenario **)(param_1 + 0x848),iVar2),
          iVar1 != 0 &&
          ((iVar1 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar1 == 0 ||
           (iVar1 = RGE_Scenario::Get_player_Type(*(RGE_Scenario **)(param_1 + 0x848),iVar2),
           iVar1 == 1)))))) {
        sprintf(acStack_10,&s__d,iVar2 + 1);
        TButtonPanel::set_text((TButtonPanel *)*puVar4,(short)iVar3,acStack_10);
        TButtonPanel::set_id((TButtonPanel *)*puVar4,(short)iVar3,iVar2 + 1,0);
        switch(iVar2) {
        case 0:
          uVar5 = 0xff0000;
          break;
        case 1:
          uVar5 = 0xff;
          break;
        case 2:
          uVar5 = 0xffff;
          break;
        case 3:
          uVar5 = 0x284673;
          break;
        case 4:
          uVar5 = 0x764f0;
          break;
        case 5:
          uVar5 = 0xff00;
          break;
        case 6:
          uVar5 = 0xb4b4b4;
          break;
        case 7:
          uVar5 = 0x93bf2b;
          break;
        default:
          goto switchD_004a555d_default;
        }
        TButtonPanel::set_text_color((TButtonPanel *)*puVar4,iVar3,uVar5,0);
switchD_004a555d_default:
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    TButtonPanel::set_state_info((TButtonPanel *)*puVar4,(short)iVar3);
    puVar4 = puVar4 + 1;
    iStack_18 = iStack_18 + -1;
    if (iStack_18 == 0) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004a55e3
// Address: 004a55e3
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s_scr3: "scr3"
TEasy_Panel * __fastcall FUN_004a55e3(TEasy_Panel *param_1,int param_2)
{
  char cVar1;
  uchar uVar2;
  byte bVar3;
  int in_EAX;
  long lVar4;
  int iVar5;
  MapSize MVar6;
  MapType MVar7;
  VictoryType VVar8;
  char *pcVar9;
  Age AVar10;
  ResourceLevel RVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *piVar15;
  int unaff_EDI;
  int *piVar16;
  TEasy_Panel **ppTVar17;
  char *pcVar18;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puVar19;
  int iVar20;
  TEasy_Panel *pTStack_31c;
  char acStack_318 [188];
  undefined1 auStack_25c [8];
  undefined1 auStack_254 [8];
  undefined1 auStack_24c [8];
  undefined1 auStack_244 [8];
  undefined1 auStack_23c [8];
  char acStack_234 [540];
  undefined4 uStack_18;
  code *pcStack_14;
  undefined4 uStack_10;
  
  *(char *)(unaff_EBP + 0x55) = *(char *)(unaff_EBP + 0x55) + (char)((uint)param_1 >> 8);
  *(char *)(unaff_ESI + 0x55) = *(char *)(unaff_ESI + 0x55) + (char)((uint)(param_2 + -2) >> 8);
  *(char *)(unaff_EDI + 0x55) = *(char *)(unaff_EDI + 0x55) + (char)((uint)unaff_EBX >> 8);
  *(char *)(in_EAX + -0x6effb5ab) = *(char *)(in_EAX + -0x6effb5ab) + (char)param_1;
  *(char *)(param_2 + -0x5cffb5b0) = *(char *)(param_2 + -0x5cffb5b0) + (char)unaff_EBX;
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + (char)(param_2 + -2) + -4;
  uStack_10 = 0xffffffff;
  pcStack_14 = FUN_0055f25b;
  uStack_18 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_18;
  pTStack_31c = param_1;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Multiplayer_Wait_Screen);
  piVar15 = &param_1[1]._padding_;
  param_1->_padding_ = (int)&TRIBE_Screen_Wait::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *piVar15 = 0;
  param_1[1]._padding_ = 0;
  piVar16 = &param_1[1]._padding_;
  for (iVar12 = 0x14; iVar12 != 0; iVar12 = iVar12 + -1) {
    *piVar16 = 0;
    piVar16 = piVar16 + 1;
  }
  uStack_10 = 0;
  lVar4 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,&s_scr3,0xc385,0);
  if (lVar4 == 0) {
    param_1->_padding_ = 1;
    goto LAB_004a5fb2;
  }
  TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
  TEasy_Panel::create_text
            (param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),s_,0x14,0x28,0x17c,400,4,1,1,1);
  iVar12 = TEasy_Panel::create_button
                     (param_1,(TPanel *)param_1,(TButtonPanel **)piVar15,0x3ea,0,0,0,0,0,-1,-1,0);
  if (iVar12 == 0) goto LAB_004a5fb2;
  (**(code **)(*(int *)*piVar15 + 0x14))();
  (**(code **)(*(int *)*piVar15 + 0x18))(9,4,4,4);
  iVar12 = TEasy_Panel::create_text
                     (param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,s_,0x1a4,0x54,
                      0xdc,0x44,0xb,0,0,1);
  if (iVar12 == 0) goto LAB_004a5fb2;
  iVar12 = 0x53;
  piVar15 = &param_1[1]._padding_;
  do {
    iVar5 = TEasy_Panel::create_text
                      (param_1,(TPanel *)param_1,(TTextPanel **)piVar15,s_,0x1a4,iVar12,0xdc,0x14,
                       0xb,0,0,0);
    if (iVar5 == 0) goto LAB_004a5fb2;
    iVar12 = iVar12 + 0x18;
    piVar15 = piVar15 + 1;
  } while (iVar12 < 0x233);
  piVar15 = &param_1[1]._padding_;
  iVar12 = 0x14;
  do {
    (**(code **)(*(int *)*piVar15 + 0x14))();
    piVar15 = piVar15 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar12 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar12 == 0) {
    uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
    if (uVar2 == '\0') {
      iVar12 = 0x25b5;
    }
    else {
      iVar12 = 0x2617;
    }
    TPanel::get_string((TPanel *)param_1,iVar12,acStack_318,0x100);
    TPanel::get_string((TPanel *)param_1,0x25ed);
    sprintf();
    (**(code **)(*(int *)param_1[1]._padding_ + 0xe8))();
    iVar12 = 1;
  }
  else {
    RGE_Base_Game::scenarioName(rge_base_game);
    TPanel::get_string((TPanel *)param_1,0x25ed);
    sprintf();
    (**(code **)(*(int *)param_1[1]._padding_ + 0xe8))();
    iVar12 = 3;
  }
  iVar5 = RGE_Base_Game::randomGame(rge_base_game);
  if (iVar5 != 0) {
    MVar6 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
    switch(MVar6) {
    case Tiny:
      iVar5 = 0x2973;
      break;
    case Small:
      iVar5 = 0x2974;
      break;
    case Medium:
      iVar5 = 0x2975;
      break;
    case Large:
      iVar5 = 0x2976;
      break;
    case Huge:
      iVar5 = 0x2977;
      break;
    case Humongous:
      iVar5 = 0x2978;
      break;
    default:
      goto switchD_004a589d_default;
    }
    pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar13 = 0xffffffff;
    do {
      pcVar18 = pcVar9;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar18 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar18;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar9 = pcVar18 + -uVar13;
    ppTVar17 = &pTStack_31c;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *ppTVar17 = *(TEasy_Panel **)pcVar9;
      pcVar9 = pcVar9 + 4;
      ppTVar17 = ppTVar17 + 1;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(char *)ppTVar17 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      ppTVar17 = (TEasy_Panel **)((int)ppTVar17 + 1);
    }
switchD_004a589d_default:
    TPanel::get_string((TPanel *)param_1,0x25da);
    sprintf();
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
    MVar7 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
    switch(MVar7) {
    case AllWater:
      iVar5 = 0x296a;
      break;
    case MostlyWater:
      iVar5 = 0x296b;
      break;
    case WaterAndLand:
      iVar5 = 0x296c;
      break;
    case MostlyLand:
      iVar5 = 0x296d;
      break;
    case AllLand:
      iVar5 = 0x296e;
      break;
    case Continental:
      iVar5 = 0x296f;
      break;
    case Lake:
      iVar5 = 0x2970;
      break;
    case Hilly:
      iVar5 = 0x2971;
      break;
    case Isthmas:
      iVar5 = 0x2972;
      break;
    default:
      goto switchD_004a594e_default;
    }
    pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar13 = 0xffffffff;
    do {
      pcVar18 = pcVar9;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar18 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar18;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar9 = pcVar18 + -uVar13;
    pcVar18 = &stack0xfffffcdc;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *(undefined4 *)pcVar18 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar18 = pcVar18 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar18 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar18 = pcVar18 + 1;
    }
switchD_004a594e_default:
    TPanel::get_string((TPanel *)param_1,0x25b6);
    sprintf();
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
    iVar12 = iVar12 + 2;
  }
  VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  switch(VVar8) {
  case VictoryConquest:
    iVar5 = 0x10e1;
    break;
  default:
    iVar5 = RGE_Base_Game::randomGame(rge_base_game);
    if (iVar5 != 0) goto switchD_004a5a16_caseD_9;
    iVar5 = 0x10e7;
    break;
  case VictoryTime:
    iVar5 = 0x10e9;
    goto LAB_004a5a33;
  case VictoryScore:
    iVar5 = 0x10ea;
LAB_004a5a33:
    pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar13 = 0xffffffff;
    do {
      pcVar18 = pcVar9;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar18 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar18;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar9 = pcVar18 + -uVar13;
    ppTVar17 = &pTStack_31c;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *ppTVar17 = *(TEasy_Panel **)pcVar9;
      pcVar9 = pcVar9 + 4;
      ppTVar17 = ppTVar17 + 1;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(char *)ppTVar17 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      ppTVar17 = (TEasy_Panel **)((int)ppTVar17 + 1);
    }
    TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
    TPanel::get_string((TPanel *)param_1,0x25be);
    sprintf();
    goto LAB_004a5af4;
  case VictoryStandard:
switchD_004a5a16_caseD_9:
    iVar5 = 0x10ec;
  }
  pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
  uVar13 = 0xffffffff;
  do {
    pcVar18 = pcVar9;
    if (uVar13 == 0) break;
    uVar13 = uVar13 - 1;
    pcVar18 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar18;
  } while (cVar1 != '\0');
  uVar13 = ~uVar13;
  pcVar9 = pcVar18 + -uVar13;
  ppTVar17 = &pTStack_31c;
  for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
    *ppTVar17 = *(TEasy_Panel **)pcVar9;
    pcVar9 = pcVar9 + 4;
    ppTVar17 = ppTVar17 + 1;
  }
  for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(char *)ppTVar17 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    ppTVar17 = (TEasy_Panel **)((int)ppTVar17 + 1);
  }
  TPanel::get_string((TPanel *)param_1,0x25bc);
  sprintf();
LAB_004a5af4:
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
  AVar10 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar10 == DefaultAge) {
    iVar5 = 0x10e7;
  }
  else if (AVar10 == NomadAge) {
    iVar5 = 0x106e;
  }
  else {
    iVar5 = AVar10 + 0x1067;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffcdc,0x100);
  TPanel::get_string((TPanel *)param_1,0x25e4);
  sprintf();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
  RVar11 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  if (RVar11 == DefaultResources) {
    iVar5 = 0x10e7;
  }
  else {
    iVar5 = RVar11 + 0x25e5;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffcd4,0x100);
  TPanel::get_string((TPanel *)param_1,0x25e5);
  sprintf();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
  RGE_Base_Game::difficulty(rge_base_game);
  pcVar9 = &stack0xfffffccc;
  iVar20 = 0x100;
  iVar5 = RGE_Base_Game::difficulty(rge_base_game);
  TPanel::get_string((TPanel *)param_1,iVar5 + 0x2bd0,pcVar9,iVar20);
  TPanel::get_string((TPanel *)param_1,0x25e0,acStack_234,0x100);
  sprintf();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))();
  iVar5 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa3;
  }
  else {
    iVar5 = 0xfa4;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffcc4,0x100);
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25e9);
  sprintf(auStack_23c,pcVar9);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))();
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))(1);
  iVar5 = RGE_Base_Game::fullVisibility(rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa4;
  }
  else {
    iVar5 = 0xfa3;
  }
  pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
  uVar13 = 0xffffffff;
  do {
    pcVar18 = pcVar9;
    if (uVar13 == 0) break;
    uVar13 = uVar13 - 1;
    pcVar18 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar18;
  } while (cVar1 != '\0');
  uVar13 = ~uVar13;
  pcVar9 = pcVar18 + -uVar13;
  pcVar18 = &stack0xfffffcbc;
  for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
    *(undefined4 *)pcVar18 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar18 = pcVar18 + 4;
  }
  for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
    *pcVar18 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar18 = pcVar18 + 1;
  }
  puVar19 = &stack0xfffffcbc;
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25b8);
  sprintf(auStack_244,pcVar9,puVar19);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))(auStack_244);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))(1);
  iVar5 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  if (iVar5 == 0) {
    iVar5 = 0xfa4;
  }
  else {
    iVar5 = 0xfa3;
  }
  TPanel::get_string((TPanel *)param_1,iVar5,&stack0xfffffcb4,0x100);
  puVar19 = &stack0xfffffcb4;
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25ec);
  sprintf(auStack_24c,pcVar9,puVar19);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))(auStack_24c);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))(1);
  iVar20 = iVar12 + 8;
  iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar5 != 0) {
    iVar5 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    if (iVar5 == 0) {
      iVar5 = 0xfa4;
    }
    else {
      iVar5 = 0xfa3;
    }
    pcVar9 = TPanel::get_string((TPanel *)param_1,iVar5);
    uVar13 = 0xffffffff;
    do {
      pcVar18 = pcVar9;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar18 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar18;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar9 = pcVar18 + -uVar13;
    pcVar18 = &stack0xfffffcac;
    for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      *(undefined4 *)pcVar18 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar18 = pcVar18 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar18 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar18 = pcVar18 + 1;
    }
    puVar19 = &stack0xfffffcac;
    pcVar9 = TPanel::get_string((TPanel *)param_1,0x25bb);
    sprintf(auStack_254,pcVar9,puVar19);
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0xe8))(auStack_254);
    (**(code **)(*(int *)(&param_1[1]._padding_)[iVar12] + 0x14))(1);
    iVar20 = iVar12 + 9;
  }
  iVar12 = RGE_Base_Game::multiplayerGame(rge_base_game);
  iVar5 = 0x100;
  if (iVar12 == 0) {
    pcVar9 = &stack0xfffffcac;
    bVar3 = RGE_Base_Game::pathFinding(rge_base_game);
  }
  else {
    pcVar9 = &stack0xfffffcac;
    bVar3 = RGE_Base_Game::mpPathFinding(rge_base_game);
  }
  TPanel::get_string((TPanel *)param_1,bVar3 + 0x260e,pcVar9,iVar5);
  puVar19 = &stack0xfffffcac;
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25f1);
  sprintf(auStack_254,pcVar9,puVar19);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar20] + 0xe8))(auStack_254);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar20] + 0x14))(1);
  bVar3 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
  uVar13 = (uint)bVar3;
  pcVar9 = TPanel::get_string((TPanel *)param_1,0x25f0);
  sprintf(auStack_25c,pcVar9,uVar13);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar20] + 0xe8))(auStack_25c);
  (**(code **)(*(int *)(&param_1[1]._padding_)[iVar20] + 0x14))(1);
LAB_004a5fb2:
  *unaff_FS_OFFSET = uStack_18;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a5fcd
// Address: 004a5fcd
// XREFS: None
void __fastcall
FUN_004a5fcd(int param_1,int param_2,undefined4 param_3,char param_4,int param_5,undefined4 param_6)
{
  char *pcVar1;
  code *pcVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar7;
  int unaff_EBX;
  int unaff_EBP;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  int in_stack_00000024;
  int iVar6;
  
  *unaff_EDI = *unaff_ESI;
  cVar4 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_EBX + -0x4dffb5a8) = *(char *)(unaff_EBX + -0x4dffb5a8) + cVar4;
  cVar7 = (char)((uint)unaff_EBX >> 8);
  *(char *)(param_1 + -0x3fffb5a8) = *(char *)(param_1 + -0x3fffb5a8) + cVar7;
  cVar5 = (char)unaff_EBX;
  cVar7 = cVar7 + param_4;
  iVar6 = CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar7,cVar5));
  *(char *)(unaff_EBP + 0x59) = *(char *)(unaff_EBP + 0x59) + (char)param_2 + -4;
  pcVar1 = (char *)(param_1 + 0x4a + iVar6 * 2);
  *pcVar1 = *pcVar1 + cVar5;
  cVar3 = (char)((uint)param_5 >> 8);
  *(char *)(iVar6 + 0x59) = *(char *)(iVar6 + 0x59) + cVar3;
  *(char *)(param_2 + 0x53) = *(char *)(param_2 + 0x53) + cVar4;
  *(char *)(param_1 + 0x59) = *(char *)(param_1 + 0x59) + (char)((uint)(param_2 + -7) >> 8);
  *(char *)(param_5 + 0x59) = *(char *)(param_5 + 0x59) + cVar7;
  unaff_EDI[0x5a] = unaff_EDI[0x5a] + cVar7;
  unaff_ESI[-0x72ffb5a6] = unaff_ESI[-0x72ffb5a6] + (char)param_5;
  cRam8d004a5a = cRam8d004a5a + cVar5;
  *(char *)(unaff_EBP + -0x72ffb5a6) = *(char *)(unaff_EBP + -0x72ffb5a6) + (char)param_6;
  *(char *)(unaff_EBP + -0x72ffb5a6) = *(char *)(unaff_EBP + -0x72ffb5a6) + (char)param_6;
  unaff_EDI[1] = unaff_EDI[1] + cVar3;
  unaff_ESI[1] = unaff_ESI[1] + (char)((uint)param_6 >> 8);
  pcVar1 = (char *)(in_stack_00000024 + -0x74a9ffb7 + iVar6 * 2);
  *pcVar1 = *pcVar1 + cVar5;
  pcVar2 = (code *)swi(1);
  (*pcVar2)();
  return;
}

// --------------------------------------------------

// Function: FUN_004a604e
// Address: 004a604e
// XREFS: None
void __fastcall FUN_004a604e(TScreenPanel *param_1)
{
  int iVar1;
  TPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f278;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Wait::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  ppTVar2 = (TPanel **)&param_1[1].field_0x10;
  iVar1 = 0x14;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a60df
// Address: 004a60df
// XREFS: None
void __thiscall FUN_004a60df(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x478) + 0xe8))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004a60f6
// Address: 004a60f6
// XREFS: None
void __thiscall FUN_004a60f6(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x478) + 0xe4))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004a6116
// Address: 004a6116
// XREFS: None
long __thiscall
FUN_004a6116(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  long lVar1;
  
  if (((param_2 != (TPanel *)0x0) && (param_2 == (TPanel *)param_1[1]._padding_)) && (param_3 == 1))
{
    RGE_Base_Game::close(rge_base_game);
    return 1;
  }
  lVar1 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_004a6163
// Address: 004a6163
// XREFS: None
void __fastcall FUN_004a6163(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004a6191
// Address: 004a6191
// XREFS: None
// [HELPER] s_Multiplayer_Disconnect_Screen: "Multiplayer Disconnect Screen"
// [HELPER] s_scr3: "scr3"
TEasy_Panel * __thiscall FUN_004a6191(TEasy_Panel *param_1,int param_2)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f298;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Multiplayer_Disconnect_Screen);
  param_1->_padding_ = (int)&TRIBE_Screen_Disconnect::_vftable_;
  param_1[1]._padding_ = param_2;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  uStack_4 = 0;
  lVar1 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,&s_scr3,0xc385,0);
  if (lVar1 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
    TEasy_Panel::create_text
              (param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x4c0,0x28,0x28,0x230,
               400,4,1,1,1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a6268
// Address: 004a6268
// XREFS: None
TRIBE_Screen_Disconnect * __thiscall FUN_004a6268(TRIBE_Screen_Disconnect *param_1,byte param_2)
{
  TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a628e
// Address: 004a628e
// XREFS: None
void __fastcall FUN_004a628e(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f2b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Disconnect::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a62e6
// Address: 004a62e6
// XREFS: None
void __thiscall FUN_004a62e6(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x47c) + 0xe8))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004a6306
// Address: 004a6306
// XREFS: None
void __thiscall FUN_004a6306(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x47c) + 0xe4))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004a6326
// Address: 004a6326
// XREFS: None
// [HELPER] s_Multiplayer_Disconnect_Screen: "Multiplayer Disconnect Screen"
// [HELPER] s_Status_Screen: "Status Screen"
long __thiscall
FUN_004a6326(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  long lVar1;
  
  if (param_2 != (TPanel *)0x0) {
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
      TRIBE_Game::quit_game((TRIBE_Game *)rge_base_game);
      TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Disconnect_Screen);
      TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
      return 1;
    }
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
      RGE_Base_Game::close(rge_base_game);
      return 1;
    }
  }
  lVar1 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_004a63b2
// Address: 004a63b2
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Panel_cpp: "C:\msdev\work\age1_x1\Panel.cpp"
int __fastcall FUN_004a63b2(int *param_1)
{
  undefined4 *puVar1;
  ulong uVar2;
  int iVar3;
  
  if (((param_1[0x1b] != 0) && ((char)param_1[0x3b] == '\x01')) &&
     (uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Panel_cpp,0x5fd),
     param_1[0x2f] <= (int)(uVar2 - param_1[0x35]))) {
    *(undefined1 *)(param_1 + 0x3b) = 2;
    if (*(char *)((int)param_1 + 0xed) == '\x01') {
      (**(code **)(*param_1 + 0x88))();
    }
    else {
      (**(code **)(*param_1 + 0x9c))(param_1[0x31],param_1[0x32],param_1[0x33],param_1[0x34]);
    }
  }
  puVar1 = (undefined4 *)param_1[0x17];
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    iVar3 = (**(code **)(*(int *)*puVar1 + 0x4c))();
    if (iVar3 != 0) break;
    puVar1 = (undefined4 *)puVar1[1];
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_004a63c5
// Address: 004a63c5
// XREFS: None
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_scr2: "scr2"
TRIBE_Screen_Name * __fastcall FUN_004a63c5(TRIBE_Screen_Name *param_1)
{
  TButtonPanel **ppTVar1;
  TButtonPanel *pTVar2;
  long lVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f2d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Name_Selection_Screen);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Screen_Name::_vftable_;
  TRIBE_Screen_Name::init_vars(param_1);
  lVar3 = TEasy_Panel::setup((TEasy_Panel *)param_1,rge_base_game->draw_area,(TPanel *)0x0,&s_scr2,
                             0xc384,1,0,0,0,0,1);
  if (lVar3 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
  iVar4 = TEasy_Panel::create_text
                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,0x29fe,0x14,0x14,600,
                     0x1e,1,1,0,0);
  if (iVar4 != 0) {
    iVar4 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->name_text,0x29ff,0x3c,0x50
                       ,0x8c,0x14,4,0,0,0);
    if (iVar4 != 0) {
      iVar4 = TEasy_Panel::create_list
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->name_list,0x3c,100,0x14a
                         ,300,0xb);
      if (iVar4 != 0) {
        iVar4 = TEasy_Panel::create_auto_scrollbar
                          ((TEasy_Panel *)param_1,&param_1->name_scrollbar,
                           (TTextPanel *)param_1->name_list,0x14);
        if (iVar4 != 0) {
          TPanel::set_help_info((TPanel *)param_1->name_scrollbar,0x765c,-1);
          iVar4 = TEasy_Panel::create_button
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->new_button,0x2a00,0,
                             400,100,0xb4,0x1e,0,0,0);
          if (iVar4 != 0) {
            TPanel::set_help_info((TPanel *)param_1->new_button,0x765d,-1);
            iVar4 = TEasy_Panel::create_button
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->remove_button,
                               0x2a01,0,400,0x8c,0xb4,0x1e,0,0,0);
            if (iVar4 != 0) {
              TPanel::set_help_info((TPanel *)param_1->remove_button,0x765e,-1);
              iVar4 = TEasy_Panel::create_button
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->ok_button,0xfa1,
                                 0,0x46,0x1b8,0xf0,0x1e,0,0,0);
              if (iVar4 != 0) {
                TPanel::set_help_info((TPanel *)param_1->ok_button,0x7531,-1);
                ppTVar1 = &param_1->cancel_button;
                iVar4 = TEasy_Panel::create_button
                                  ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0xfa2,0,0x14a,
                                   0x1b8,0xf0,0x1e,0,0,0);
                if (iVar4 != 0) {
                  TPanel::set_help_info((TPanel *)*ppTVar1,0x7532,-1);
                  pTVar2 = *ppTVar1;
                  pTVar2->hotkey = 0x1b;
                  pTVar2->hotkey_shift = 0;
                  iVar4 = TEasy_Panel::create_button
                                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->close_button
                                     ,0x3ea,0,0,0,0,0,-1,-1,0);
                  if (iVar4 != 0) {
                    (**(code **)(param_1->close_button->_padding_ + 0x18))
                              (9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                    TRIBE_Screen_Name::setup_tab_order(param_1);
                    TRIBE_Screen_Name::get_player_names(param_1);
                    param_1->started_input = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a66b1
// Address: 004a66b1
// XREFS: None
TRIBE_Screen_Name * __thiscall FUN_004a66b1(TRIBE_Screen_Name *param_1,byte param_2)
{
  TRIBE_Screen_Name::~TRIBE_Screen_Name(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a66de
// Address: 004a66de
// XREFS: None
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
void __fastcall FUN_004a66de(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f2f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Name::_vftable_;
  uStack_4 = 0;
  TPanelSystem::setCurrentPanel(&panel_system,&s_New_Name_Dialog,0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x10);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x18);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x20);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a67b9
// Address: 004a67b9
// XREFS: None
void __fastcall FUN_004a67b9(int param_1)
{
  *(undefined4 *)(param_1 + 0x478) = 0;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0;
  *(undefined4 *)(param_1 + 0x484) = 0;
  *(undefined4 *)(param_1 + 0x488) = 0;
  *(undefined4 *)(param_1 + 0x48c) = 0;
  *(undefined4 *)(param_1 + 0x490) = 0;
  *(undefined4 *)(param_1 + 0x494) = 0;
  *(undefined4 *)(param_1 + 0x498) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004a67f9
// Address: 004a67f9
// XREFS: None
void __fastcall FUN_004a67f9(int param_1)
{
  long lVar1;
  long lVar2;
  int iVar3;
  char **ppcStack_8;
  long lStack_4;
  
  TTextPanel::empty_list(*(TTextPanel **)(param_1 + 0x480));
  ppcStack_8 = (char **)0x0;
  lVar1 = RGE_Game_Info::get_people_list(rge_base_game->player_game_info,&ppcStack_8,&lStack_4);
  if (lVar1 != 0) {
    iVar3 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x480) + 0x15c) = 1;
    if (0 < lVar1) {
      do {
        TTextPanel::append_line(*(TTextPanel **)(param_1 + 0x480),ppcStack_8[iVar3],iVar3);
        iVar3 = iVar3 + 1;
      } while (iVar3 < lVar1);
    }
    lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x480),lStack_4);
    TTextPanel::set_line(*(TTextPanel **)(param_1 + 0x480),lVar2);
    iVar3 = 0;
    if (0 < lVar1) {
      do {
        free(ppcStack_8[iVar3]);
        iVar3 = iVar3 + 1;
      } while (iVar3 < lVar1);
    }
    free(ppcStack_8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004a68b2
// Address: 004a68b2
// XREFS: None
void __fastcall FUN_004a68b2(TPanel *param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  long alStack_14 [5];
  
  iVar2 = TTextPanel::numberLines((TTextPanel *)param_1[4].max_wid);
  uVar3 = (uint)(iVar2 == 0);
  TButtonPanel::set_disabled((TButtonPanel *)param_1[4].mouse_hold_interval,uVar3);
  TButtonPanel::set_disabled((TButtonPanel *)param_1[4].mouse_move_tolerance,uVar3);
  alStack_14[0] = param_1[4].max_wid;
  alStack_14[1] = param_1[4].max_hgt;
  iVar2 = 2;
  if (uVar3 == 0) {
    alStack_14[3] = param_1[4].mouse_move_tolerance;
    alStack_14[2] = param_1[4].mouse_hold_interval;
    iVar2 = 4;
  }
  iVar1 = param_1->_padding_;
  alStack_14[iVar2] = param_1[4].mouse_down_x;
  (**(code **)(iVar1 + 200))(alStack_14,iVar2 + 1);
  iVar2 = TTextPanel::numberLines((TTextPanel *)param_1[4].max_wid);
  if (iVar2 == 0) {
    TPanel::set_curr_child(param_1,(TPanel *)param_1[4].max_hgt);
    return;
  }
  TPanel::set_curr_child(param_1,(TPanel *)param_1[4].max_wid);
  return;
}

// --------------------------------------------------

// Function: FUN_004a697d
// Address: 004a697d
// XREFS: None
void __fastcall FUN_004a697d(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004a69a1
// Address: 004a69a1
// XREFS: None
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_YesNoDialog: "YesNoDialog"
long __thiscall
FUN_004a69a1(TRIBE_Screen_Name *param_1,TButtonPanel *param_2,long param_3,ulong param_4,
            ulong param_5)
{
  byte bVar1;
  RGE_Game_Info *pRVar2;
  long lVar3;
  TRIBE_Screen_Campaign_Selection *this;
  TribeSPMenuScreen *this_00;
  TRIBE_Dialog_Name *this_01;
  char *pcVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *unaff_FS_OFFSET;
  bool bVar9;
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f33a;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == (TButtonPanel *)0x0) goto LAB_004a6d0e;
  if ((param_2 == param_1->ok_button) && (param_3 == 1)) {
    lVar3 = TTextPanel::get_line((TTextPanel *)param_1->name_list);
    if (lVar3 != -1) {
      RGE_Base_Game::disable_input(rge_base_game);
      pRVar2 = rge_base_game->player_game_info;
      lVar3 = TTextPanel::get_id((TTextPanel *)param_1->name_list);
      RGE_Game_Info::set_current_person(pRVar2,lVar3);
      this = (TRIBE_Screen_Campaign_Selection *)operator_new(0x4cc);
      iStack_4 = 0;
      if (this != (TRIBE_Screen_Campaign_Selection *)0x0) {
        TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(this);
      }
      iStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Selection_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Name_Selection_Screen);
      param_3 = 1;
    }
    goto LAB_004a6d27;
  }
  if ((param_2 == param_1->cancel_button) && (param_3 == 1)) {
    RGE_Base_Game::disable_input(rge_base_game);
    this_00 = (TribeSPMenuScreen *)operator_new(0x49c);
    iStack_4 = param_3;
    if (this_00 != (TribeSPMenuScreen *)0x0) {
      TribeSPMenuScreen::TribeSPMenuScreen(this_00);
    }
    iStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Single_Player_Menu,0);
    TPanelSystem::destroyPanel(&panel_system,s_Name_Selection_Screen);
    param_3 = 1;
    goto LAB_004a6d27;
  }
  if (param_2 == param_1->close_button) {
    RGE_Base_Game::close(rge_base_game);
    param_3 = 1;
    goto LAB_004a6d27;
  }
  if ((param_2 == (TButtonPanel *)param_1->name_list) && (param_3 == 3)) {
    (**(code **)(param_1->_padding_ + 0xb4))(param_1->ok_button,1,0,0);
    param_3 = 1;
    goto LAB_004a6d27;
  }
  if ((param_2 == param_1->new_button) && (param_3 == 1)) {
    this_01 = (TRIBE_Dialog_Name *)operator_new(0x4a4);
    iStack_4 = 2;
    if (this_01 != (TRIBE_Dialog_Name *)0x0) {
      TRIBE_Dialog_Name::TRIBE_Dialog_Name(this_01,(TScreenPanel *)param_1);
    }
    iStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,&s_New_Name_Dialog,0);
    param_3 = 1;
    goto LAB_004a6d27;
  }
  if ((param_2 == param_1->remove_button) && (param_3 == 1)) {
    lVar3 = TTextPanel::get_line((TTextPanel *)param_1->name_list);
    if (lVar3 != -1) {
      pcVar4 = TTextPanel::get_text((TTextPanel *)param_1->name_list);
      pcVar5 = TPanel::get_string((TPanel *)param_1,0x2a02);
      sprintf(acStack_10c,pcVar5,pcVar4);
      TEasy_Panel::popupYesNoDialog((TEasy_Panel *)param_1,acStack_10c,(char *)0x0,0x1c2,100);
      goto LAB_004a6d27;
    }
  }
  else {
    pcVar4 = TPanel::panelName((TPanel *)param_2);
    if (pcVar4 == (char *)0x0) {
LAB_004a6c71:
      pcVar4 = TPanel::panelName((TPanel *)param_2);
      if (pcVar4 != (char *)0x0) {
        pbVar8 = &s_YesNoDialog;
        pbVar6 = (byte *)TPanel::panelName((TPanel *)param_2);
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
          if ((param_3 == 0) &&
             (lVar3 = TTextPanel::get_line((TTextPanel *)param_1->name_list), lVar3 != -1)) {
            pRVar2 = rge_base_game->player_game_info;
            lVar3 = TTextPanel::get_id((TTextPanel *)param_1->name_list,lVar3);
            RGE_Game_Info::remove_player(pRVar2,lVar3);
            TRIBE_Screen_Name::get_player_names(param_1);
          }
          pcVar4 = &s_YesNoDialog;
          goto LAB_004a6cf6;
        }
      }
LAB_004a6d0e:
      param_3 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5
                                   );
      goto LAB_004a6d27;
    }
    pbVar8 = &s_New_Name_Dialog;
    pbVar6 = (byte *)TPanel::panelName((TPanel *)param_2);
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
    if (param_3 == 1) {
      TRIBE_Screen_Name::get_player_names(param_1);
    }
    TPanelSystem::setCurrentPanel(&panel_system,s_Name_Selection_Screen,0);
    pcVar4 = &s_New_Name_Dialog;
LAB_004a6cf6:
    TPanelSystem::destroyPanel(&panel_system,pcVar4);
    TRIBE_Screen_Name::setup_tab_order(param_1);
  }
  param_3 = 1;
LAB_004a6d27:
  *unaff_FS_OFFSET = uStack_c;
  return param_3;
}

// --------------------------------------------------

// Function: FUN_004a6d42
// Address: 004a6d42
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
TDialogPanel * __thiscall FUN_004a6d42(TDialogPanel *param_1,TEasy_Panel *param_2)
{
  int *piVar1;
  int *piVar2;
  long lVar3;
  char *pcVar4;
  TDrawArea *pTVar5;
  undefined4 *unaff_FS_OFFSET;
  long lVar6;
  long lVar7;
  int iVar8;
  TEditPanel *pTStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f358;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel(param_1,&s_New_Name_Dialog);
  piVar1 = &param_1[1]._padding_;
  iVar8 = 1;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Dialog_Name::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *piVar1 = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  lVar3 = TEasy_Panel::get_popup_info_id(param_2);
  pcVar4 = TEasy_Panel::get_popup_info_file(param_2);
  lVar7 = 0xe6;
  lVar6 = 500;
  pTVar5 = TPanel::renderArea((TPanel *)param_2);
  iVar8 = TDialogPanel::setup(param_1,pTVar5,(TPanel *)param_2,lVar6,lVar7,pcVar4,lVar3,iVar8);
  if (iVar8 != 0) {
    iVar8 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),0x2a03,
                       0x14,0x14,0x1cc,0x1e,1,1,1,0);
    if (iVar8 != 0) {
      iVar8 = TEasy_Panel::create_text
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,
                         (TTextPanel **)&param_1[1]._padding_,0x2a04,0x28,0x55,0x1a4,0x14,4,0,1,0);
      if (iVar8 != 0) {
        iVar8 = TEasy_Panel::create_edit
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,(TEditPanel **)piVar1,s_,0xf,
                           FormatText,0x28,0x6e,0x1a4,0x17,0xb,1,1);
        if (iVar8 != 0) {
          iVar8 = TEasy_Panel::create_button
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,
                             (TButtonPanel **)&param_1[1]._padding_,0xfa1,0,0x3c,0xb4,0xb4,0x1e,0,0,
                             0);
          if (iVar8 != 0) {
            piVar2 = &param_1[1]._padding_;
            iVar8 = TEasy_Panel::create_button
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piVar2,
                               0xfa2,0,0x104,0xb4,0xb4,0x1e,0,0,0);
            if (iVar8 != 0) {
              iVar8 = *piVar2;
              *(undefined4 *)(iVar8 + 0x298) = 0x1b;
              *(undefined4 *)(iVar8 + 0x29c) = 0;
              pTStack_18 = (TEditPanel *)*piVar1;
              iStack_14 = param_1[1]._padding_;
              iStack_10 = *piVar2;
              TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_18,3);
              TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*piVar1);
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a6f33
// Address: 004a6f33
// XREFS: None
TRIBE_Dialog_Name * __thiscall FUN_004a6f33(TRIBE_Dialog_Name *param_1,byte param_2)
{
  TRIBE_Dialog_Name::~TRIBE_Dialog_Name(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a6f5e
// Address: 004a6f5e
// XREFS: None
void __fastcall FUN_004a6f5e(TDialogPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f378;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Dialog_Name::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a6fee
// Address: 004a6fee
// XREFS: None
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
long __thiscall
FUN_004a6fee(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  RGE_Game_Info *this;
  char *pcVar1;
  TRIBE_Screen_Campaign_Selection *this_00;
  TPanel *pTVar2;
  TribeSPMenuScreen *this_01;
  long lVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f3a6;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != (TPanel *)0x0) {
    if (((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) ||
       ((param_2 == (TPanel *)param_1[1]._padding_ && (param_3 == 0)))) {
      pcVar1 = TEditPanel::get_text((TEditPanel *)param_1[1]._padding_);
      if (*pcVar1 == '\0') {
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
      this = rge_base_game->player_game_info;
      pcVar1 = TEditPanel::get_text((TEditPanel *)param_1[1]._padding_);
      RGE_Game_Info::add_new_person(this,pcVar1);
      this_00 = (TRIBE_Screen_Campaign_Selection *)operator_new(0x4cc);
      uStack_4 = 0;
      if (this_00 != (TRIBE_Screen_Campaign_Selection *)0x0) {
        TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(this_00);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Selection_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,&s_New_Name_Dialog);
      TPanelSystem::destroyPanel(&panel_system,s_Name_Selection_Screen);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) ||
       ((param_2 == (TPanel *)param_1[1]._padding_ && (param_3 == 1)))) {
      pTVar2 = TPanelSystem::panel(&panel_system,s_Name_Selection_Screen);
      if (pTVar2 == (TPanel *)0x0) {
        this_01 = (TribeSPMenuScreen *)operator_new(0x49c);
        uStack_4 = 1;
        if (this_01 != (TribeSPMenuScreen *)0x0) {
          TribeSPMenuScreen::TribeSPMenuScreen(this_01);
        }
        uStack_4 = 0xffffffff;
        pcVar1 = s_Single_Player_Menu;
      }
      else {
        pcVar1 = s_Name_Selection_Screen;
      }
      TPanelSystem::setCurrentPanel(&panel_system,pcVar1,0);
      TPanelSystem::destroyPanel(&panel_system,&s_New_Name_Dialog);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
  }
  lVar3 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  *unaff_FS_OFFSET = uStack_c;
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_004a71c5
// Address: 004a71c5
// XREFS: None
void __thiscall FUN_004a71c5(TPanel *param_1,void *param_2,uint param_3,uint param_4,long param_5)
{
  TPanel::wnd_proc(param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_004a71ec
// Address: 004a71ec
// XREFS: None
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
TribeSaveGameScreen * __thiscall
FUN_004a71ec(TribeSaveGameScreen *param_1,Mode param_2,char *param_3,int param_4)
{
  TButtonPanel **ppTVar1;
  TButtonPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  char cVar4;
  TDrawArea *pTVar5;
  TButtonPanel *pTVar6;
  short sVar7;
  TEasy_Panel *this;
  char *pcVar8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  int iVar13;
  TEditPanel *pTStack_128;
  TListPanel *pTStack_124;
  TButtonPanel *pTStack_120;
  TButtonPanel *pTStack_11c;
  TButtonPanel *pTStack_118;
  TribeSaveGameScreen *pTStack_114;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f3bb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_114 = param_1;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Save_Game_Screen);
  param_1->quit_after_save = param_4;
  uStack_4 = 0;
  param_1->modeValue = param_2;
  param_1->_padding_ = (int)&TribeSaveGameScreen::_vftable_;
  param_1->title = (TTextPanel *)0x0;
  param_1->input = (TEditPanel *)0x0;
  param_1->list = (TListPanel *)0x0;
  param_1->scrollbar = (TScrollBarPanel *)0x0;
  param_1->okButton = (TButtonPanel *)0x0;
  param_1->cancelButton = (TButtonPanel *)0x0;
  param_1->deleteButton = (TButtonPanel *)0x0;
  if ((param_3 == (char *)0x0) && (param_2 == SaveGame)) {
    param_3 = TRIBE_Game::get_save_game_name((TRIBE_Game *)rge_base_game);
  }
  this = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  pcVar8 = TEasy_Panel::get_popup_info_file(this);
  uVar10 = 0xffffffff;
  do {
    pcVar12 = pcVar8;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar12 = pcVar8 + 1;
    cVar4 = *pcVar8;
    pcVar8 = pcVar12;
  } while (cVar4 != '\0');
  uVar10 = ~uVar10;
  iVar13 = 1;
  pcVar8 = pcVar12 + -uVar10;
  pcVar12 = acStack_110;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar12 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar12 = pcVar12 + 1;
  }
  pTVar5 = rge_base_game->draw_area;
  lVar9 = TEasy_Panel::get_popup_info_id(this);
  lVar9 = TScreenPanel::setup((TScreenPanel *)param_1,pTVar5,acStack_110,lVar9,iVar13);
  if (lVar9 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
    iVar13 = TEasy_Panel::create_text
                       ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,
                        (param_1->modeValue != SaveGame) + 0x24c3,0x14,0x14,600,0x1e,1,1,0,0);
    if (iVar13 != 0) {
      uVar10 = 0xffffffff;
      pcVar8 = rge_base_game->work_dir;
      do {
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        cVar4 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar4 != '\0');
      if (0x7a - (~uVar10 - 1) < 0x51) {
        iVar13 = -1;
        pcVar8 = rge_base_game->work_dir;
        do {
          if (iVar13 == 0) break;
          iVar13 = iVar13 + -1;
          cVar4 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar4 != '\0');
        sVar7 = 0x7a - (~(ushort)iVar13 - 1);
      }
      else {
        sVar7 = 0x50;
      }
      iVar13 = TEasy_Panel::create_edit
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->input,param_3,sVar7,
                          FormatFileNoExt,0x14,0x46,600,0x17,0xb,1,1);
      if (iVar13 != 0) {
        TPanel::set_help_info((TPanel *)param_1->input,0x7670,-1);
        iVar13 = TEasy_Panel::create_list
                           ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->list,0x14,0x6e,600,
                            300,0xb);
        if (iVar13 != 0) {
          iVar13 = TEasy_Panel::create_auto_scrollbar
                             ((TEasy_Panel *)param_1,&param_1->scrollbar,(TTextPanel *)param_1->list
                              ,0x14);
          if (iVar13 != 0) {
            TPanel::set_help_info((TPanel *)param_1->scrollbar,0x7671,-1);
            ppTVar1 = &param_1->okButton;
            iVar13 = TEasy_Panel::create_button
                               ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0xfa1,0,0x1e,0x1b8,
                                0xb4,0x1e,0,0,0);
            if (iVar13 != 0) {
              ppTVar2 = &param_1->deleteButton;
              iVar13 = TEasy_Panel::create_button
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,0x24c9,0,0xe6,
                                  0x1b8,0xb4,0x1e,0,0,0);
              if (iVar13 != 0) {
                ppTVar3 = &param_1->cancelButton;
                iVar13 = TEasy_Panel::create_button
                                   ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar3,0xfa2,0,0x1ae,
                                    0x1b8,0xb4,0x1e,0,0,0);
                if (iVar13 != 0) {
                  TPanel::set_help_info((TPanel *)*ppTVar1,0x7531,-1);
                  TPanel::set_help_info((TPanel *)*ppTVar3,0x7532,-1);
                  pTVar6 = *ppTVar3;
                  pTVar6->hotkey = 0x1b;
                  pTVar6->hotkey_shift = 0;
                  pTVar6 = *ppTVar2;
                  pTVar6->hotkey_shift = 0;
                  pTVar6->hotkey = 0x2e;
                  TribeSaveGameScreen::fillList(param_1);
                  pcVar8 = TTextPanel::currentLine((TTextPanel *)param_1->list);
                  if (*pcVar8 == '\0') {
                    TButtonPanel::set_disabled(*ppTVar2,1);
                  }
                  TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->input);
                  pTStack_128 = param_1->input;
                  pTStack_120 = *ppTVar1;
                  pTStack_124 = param_1->list;
                  pTStack_11c = *ppTVar2;
                  pTStack_118 = *ppTVar3;
                  TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_128,5);
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a759e
// Address: 004a759e
// XREFS: None
TribeSaveGameScreen * __thiscall FUN_004a759e(TribeSaveGameScreen *param_1,byte param_2)
{
  TribeSaveGameScreen::~TribeSaveGameScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a75be
// Address: 004a75be
// XREFS: None
void __fastcall FUN_004a75be(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f3d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeSaveGameScreen::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x10);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x18);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a766a
// Address: 004a766a
// XREFS: None
// [HELPER] s__s__gam: "%s*.gam"
// [HELPER] s__s__gmx: "%s*.gmx"
// [HELPER] s__s__scn: "%s*.scn"
// [HELPER] s__s__scx: "%s*.scx"
void __fastcall FUN_004a766a(int param_1)
{
  char cVar1;
  TTextPanel *this;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char acStack_21c [260];
  undefined1 auStack_118 [20];
  char acStack_104 [260];
  
  TTextPanel::empty_list(*(TTextPanel **)(param_1 + 0x480));
  *(undefined4 *)(*(int *)(param_1 + 0x480) + 0x15c) = 1;
  if (*(int *)(param_1 + 0x69c) == 0) {
    sprintf(acStack_21c,s__s__gam,rge_base_game->prog_info->save_dir);
  }
  else {
    sprintf(acStack_21c,s__s__scn,rge_base_game->prog_info->scenario_dir);
  }
  iVar2 = __findfirst(acStack_21c,auStack_118);
  iVar3 = iVar2;
  while (iVar3 != -1) {
    uVar4 = 0xffffffff;
    pcVar5 = acStack_104;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    strncpy(acStack_21c,acStack_104,~uVar4 - 5);
    acStack_21c[~uVar4 - 5] = '\0';
    TTextPanel::append_line(*(TTextPanel **)(param_1 + 0x480),acStack_21c,0);
    iVar3 = __findnext(iVar2,auStack_118);
  }
  if (*(int *)(param_1 + 0x69c) == 0) {
    sprintf(acStack_21c,s__s__gmx,rge_base_game->prog_info->save_dir);
  }
  else {
    sprintf(acStack_21c,s__s__scx,rge_base_game->prog_info->scenario_dir);
  }
  iVar2 = __findfirst(acStack_21c,auStack_118);
  iVar3 = iVar2;
  do {
    if (iVar3 == -1) {
      return;
    }
    uVar4 = 0xffffffff;
    pcVar5 = acStack_104;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    strncpy(acStack_21c,acStack_104,~uVar4 - 5);
    this = *(TTextPanel **)(param_1 + 0x480);
    acStack_21c[~uVar4 - 5] = '\0';
    TTextPanel::append_line(this,acStack_21c,0);
    iVar3 = __findnext(iVar2,auStack_118);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004a7843
// Address: 004a7843
// XREFS: None
// [HELPER] s_Cancel_Dialog: "Cancel Dialog"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_YesNoDialog: "YesNoDialog"
// [HELPER] s__s_gam: "%s.gam"
// [HELPER] s__s_gmx: "%s.gmx"
// [HELPER] s__s_s: "%s%s"
// [HELPER] s__s_s_gam: "%s%s.gam"
// [HELPER] s__s_s_gmx: "%s%s.gmx"
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_s_scx: "%s%s.scx"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
// [HELPER] s_rb: "rb"
long __thiscall
FUN_004a7843(TribeSaveGameScreen *param_1,TButtonPanel *param_2,int param_3,ulong param_4,
            ulong param_5)
{
  char cVar1;
  byte bVar2;
  TButtonPanel *this;
  Mode MVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  long lVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  char *pcVar11;
  char acStack_330 [260];
  char acStack_22c [556];
  
  if (param_2 != (TButtonPanel *)0x0) {
    pcVar4 = TPanel::panelName((TPanel *)param_2);
    if (pcVar4 != (char *)0x0) {
      pbVar8 = &s_Cancel_Dialog;
      pbVar5 = (byte *)TPanel::panelName((TPanel *)param_2);
      do {
        bVar2 = *pbVar5;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_004a78b1:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_004a78b6;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_004a78b1;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_004a78b6:
      if (iVar6 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_Cancel_Dialog);
        if (param_3 != 0) {
          return 1;
        }
        if (param_1->modeValue == SaveGame) {
          pcVar9 = rge_base_game->prog_info->save_dir;
          pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list);
          pcVar11 = s__s_s_gam;
        }
        else {
          pcVar9 = rge_base_game->prog_info->scenario_dir;
          pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list);
          pcVar11 = s__s_s_scn;
        }
        sprintf(acStack_330,pcVar11,pcVar9,pcVar4);
        __unlink(acStack_330);
        if (param_1->modeValue == SaveGame) {
          pcVar9 = rge_base_game->prog_info->save_dir;
          pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list);
          pcVar11 = s__s_s_gmx;
        }
        else {
          pcVar9 = rge_base_game->prog_info->scenario_dir;
          pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list);
          pcVar11 = s__s_s_scx;
        }
        sprintf(acStack_330,pcVar11,pcVar9,pcVar4);
        __unlink(acStack_330);
        lVar7 = TTextPanel::get_line((TTextPanel *)param_1->list);
        TTextPanel::delete_line((TTextPanel *)param_1->list,lVar7);
        pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list);
        TEditPanel::set_text(param_1->input,pcVar4);
        pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list);
        if (*pcVar4 != '\0') {
          return 1;
        }
        TButtonPanel::set_disabled(param_1->deleteButton,1);
        return 1;
      }
    }
    if (((param_2 == param_1->deleteButton) && (param_3 == 1)) &&
       (pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list), *pcVar4 != '\0')) {
      TPanel::get_string((TPanel *)param_1,0x24ca,acStack_330,0x100);
      pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list);
      sprintf(acStack_22c,acStack_330,pcVar4);
      TEasy_Panel::popupYesNoDialog((TEasy_Panel *)param_1,acStack_22c,&s_Cancel_Dialog,0x1c2,100);
    }
    this = (TButtonPanel *)param_1->list;
    if ((param_2 == this) && (param_3 == 1)) {
      pcVar4 = TTextPanel::currentLine((TTextPanel *)this);
      TEditPanel::set_text(param_1->input,pcVar4);
      return 1;
    }
    if ((((param_2 == param_1->okButton) && (param_3 == 1)) ||
        ((param_2 == (TButtonPanel *)param_1->input && (param_3 == 0)))) ||
       ((param_2 == this && (param_3 == 3)))) {
      pcVar4 = param_1->fileNameNoExt;
      TEditPanel::get_trimmed_str(param_1->input,pcVar4,0x104);
      iVar6 = -1;
      pcVar9 = pcVar4;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (iVar6 == -2) {
        if (param_1->modeValue != SaveGame) {
          TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x24c7,(char *)0x0,0x1c2,100);
          return 1;
        }
        TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x24c6,(char *)0x0,0x1c2,100);
        return 1;
      }
      pcVar9 = param_1->fileName;
      if (param_1->modeValue == SaveGame) {
        sprintf(pcVar9,s__s_gam,pcVar4);
        pcVar11 = rge_base_game->prog_info->save_dir;
      }
      else {
        sprintf(pcVar9,s__s_scn,pcVar4);
        pcVar11 = rge_base_game->prog_info->scenario_dir;
      }
      sprintf(acStack_330,s__s_s,pcVar11,pcVar9);
      iVar6 = fopen(acStack_330,s_rb);
      bVar10 = iVar6 != 0;
      if (bVar10) {
        fclose(iVar6);
      }
      if (param_1->modeValue == SaveGame) {
        sprintf(pcVar9,s__s_gmx,pcVar4);
        pcVar4 = rge_base_game->prog_info->save_dir;
      }
      else {
        sprintf(pcVar9,s__s_scx,pcVar4);
        pcVar4 = rge_base_game->prog_info->scenario_dir;
      }
      sprintf(acStack_330,s__s_s,pcVar4,pcVar9);
      if (!bVar10) {
        iVar6 = fopen(acStack_330,s_rb);
        if (iVar6 != 0) {
          fclose(iVar6);
        }
        if (iVar6 == 0 && !bVar10) {
          MVar3 = param_1->modeValue;
          if (MVar3 == SaveGame) {
            iVar6 = TRIBE_Game::save_game((TRIBE_Game *)rge_base_game,pcVar9);
            if (iVar6 == 0) {
              TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x962,(char *)0x0,0x1c2,100);
              return 1;
            }
          }
          else if (MVar3 == SaveScenario) {
            iVar6 = TRIBE_Game::save_scenario((TRIBE_Game *)rge_base_game,pcVar9);
            if (iVar6 == 0) {
              TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x963,(char *)0x0,0x1c2,100);
              return 1;
            }
          }
          else if (MVar3 == SaveScenarioEdit) {
            TribeSaveGameScreen::save_for_scenario_editor(param_1);
            return 1;
          }
          return 1;
        }
      }
      TEasy_Panel::popupYesNoDialog((TEasy_Panel *)param_1,0x24c8,(char *)0x0,0x1c2,100);
      return 1;
    }
    if (((param_2 == param_1->cancelButton) && (param_3 == 1)) ||
       ((param_2 == (TButtonPanel *)param_1->input && (param_3 == 1)))) {
      iVar6 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar6 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
      }
      if (param_1->modeValue == SaveScenarioEdit) {
        pcVar4 = s_Scenario_Editor_Screen;
      }
      else {
        pcVar4 = s_Game_Screen;
      }
      TPanelSystem::setCurrentPanel(&panel_system,pcVar4,0);
      TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
      return 1;
    }
    pcVar4 = TPanel::panelName((TPanel *)param_2);
    if (pcVar4 != (char *)0x0) {
      pbVar8 = &s_OKDialog;
      pbVar5 = (byte *)TPanel::panelName((TPanel *)param_2);
      do {
        bVar2 = *pbVar5;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_004a7df1:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_004a7df6;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_004a7df1;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_004a7df6:
      if (iVar6 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->input);
        return 1;
      }
    }
    pcVar4 = TPanel::panelName((TPanel *)param_2);
    if (pcVar4 != (char *)0x0) {
      pbVar8 = &s_YesNoDialog;
      pbVar5 = (byte *)TPanel::panelName((TPanel *)param_2);
      do {
        bVar2 = *pbVar5;
        bVar10 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_004a7e68:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_004a7e6d;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar10 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_004a7e68;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_004a7e6d:
      if (iVar6 == 0) {
        if (param_3 != 0) {
          TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
          TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->input);
          return 1;
        }
        TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
        MVar3 = param_1->modeValue;
        if (MVar3 == SaveGame) {
          TEditPanel::get_trimmed_str(param_1->input,param_1->fileNameNoExt,0x104);
          sprintf(acStack_330,s__s_s_gam,rge_base_game->prog_info->save_dir,param_1->fileNameNoExt);
          __unlink(acStack_330);
          iVar6 = TRIBE_Game::save_game((TRIBE_Game *)rge_base_game,param_1->fileName);
          if (iVar6 != 0) {
            return 1;
          }
          TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x962,(char *)0x0,0x1c2,100);
          return 1;
        }
        if (MVar3 != SaveScenario) {
          if (MVar3 != SaveScenarioEdit) {
            return 1;
          }
          TEditPanel::get_trimmed_str(param_1->input,param_1->fileNameNoExt,0x104);
          sprintf(acStack_330,s__s_s_scn,rge_base_game->prog_info->scenario_dir,
                  param_1->fileNameNoExt);
          __unlink(acStack_330);
          TribeSaveGameScreen::save_for_scenario_editor(param_1);
          return 1;
        }
        TEditPanel::get_trimmed_str(param_1->input,param_1->fileNameNoExt,0x104);
        sprintf(acStack_330,s__s_s_scn,rge_base_game->prog_info->scenario_dir,param_1->fileNameNoExt
               );
        __unlink(acStack_330);
        iVar6 = TRIBE_Game::save_scenario((TRIBE_Game *)rge_base_game,param_1->fileName);
        if (iVar6 != 0) {
          return 1;
        }
        TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x963,(char *)0x0,0x1c2,100);
        return 1;
      }
    }
  }
  lVar7 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  return lVar7;
}

// --------------------------------------------------

// Function: FUN_004a805f
// Address: 004a805f
// XREFS: None
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Status_Screen: "Status Screen"
void __fastcall FUN_004a805f(TEasy_Panel *param_1)
{
  char cVar1;
  TPanel *pTVar2;
  int iVar3;
  TRIBE_Screen_Sed_Open *this;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar4;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f3fb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x450,(char *)0x0,-1);
  RGE_Scenario::Set_scenario_name(rge_base_game->world->scenario,(char *)&param_1[1]._padding_);
  cVar1 = (**(code **)(rge_base_game->world->_padding_ + 0xe4))(&param_1[1]._padding_);
  if (cVar1 == '\0') {
    TEasy_Panel::popupOKDialog(param_1,0x963,(char *)0x0,0x1c2,100);
    *unaff_FS_OFFSET = param_1;
    return;
  }
  pTVar2 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Screen);
  if (pTVar2 != (TPanel *)0x0) {
    pTVar2[4].fill_in_background = '\0';
  }
  iVar3 = *(int *)(param_1[1].cursor_file + 0x18);
  if (iVar3 == 1) {
    iVar3 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
    if (iVar3 == 0) {
      RGE_Base_Game::close(rge_base_game);
      *unaff_FS_OFFSET = param_1;
      return;
    }
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  }
  else {
    if (iVar3 == 2) {
      this = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
      pcStack_8 = (code *)0x0;
      if (this != (TRIBE_Screen_Sed_Open *)0x0) {
        TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this);
      }
      pcStack_8 = (code *)0xffffffff;
      pcVar4 = s_Scenario_Editor_Open;
    }
    else {
      if (iVar3 == 3) {
        TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
        goto LAB_004a81a7;
      }
      pcVar4 = s_Scenario_Editor_Screen;
    }
    TPanelSystem::setCurrentPanel(&panel_system,pcVar4,0);
  }
LAB_004a81a7:
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  *unaff_FS_OFFSET = param_1;
  return;
}

// --------------------------------------------------

// Function: FUN_004a81d6
// Address: 004a81d6
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_sed_cp: "C:\msdev\work\age1_x1\scr_sed.cpp"
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s__SCN: ".SCN"
// [HELPER] s__s_scx: "%s.scx"
// [HELPER] s__scn: ".scn"
// [HELPER] s_bordline: "bordline"
// [HELPER] s_default_d_scx: "default%d.scx"
// [HELPER] s_map640_bmp: "map640.bmp"
// [HELPER] s_scr5: "scr5"
TRIBE_Screen_Sed * __thiscall FUN_004a81d6(TRIBE_Screen_Sed *param_1,int param_2)
{
  ulong uVar1;
  int iVar2;
  byte *pbVar3;
  long lVar4;
  RGE_Main_View *this;
  RGE_Diamond_Map_View *this_00;
  RGE_Diamond_Map *this_01;
  RGE_Font *pRVar5;
  TMessagePanel *pTVar6;
  TPanel *pTVar7;
  int iVar8;
  byte bVar9;
  byte *pbVar10;
  undefined4 *unaff_FS_OFFSET;
  bool bVar11;
  byte *unaff_retaddr;
  undefined4 uStack_218;
  byte abStack_114 [260];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f453;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_218 = param_1;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Scenario_Editor_Screen);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Screen_Sed::_vftable_;
  param_1->is_multi_player = 0;
  param_1->scenario_mode = ScenarioModeNone;
  param_1->map_type = MapTypeNone;
  param_1->mp_victory_type = VictoryTypeConquest;
  param_1->brush_size = BrushSizeNone;
  param_1->paint_type = PaintTypeNone;
  param_1->player_num = 1;
  param_1->message_type = MessageTypeNone;
  param_1->SelectedObject = (RGE_Static_Object *)0x0;
  param_1->DestinationObject = (RGE_Static_Object *)0x0;
  param_1->CurrentPlayer = 0;
  param_1->need_to_save_flag = '\0';
  param_1->valid_save_spot_flag = '\0';
  TRIBE_Screen_Sed::init_module_variables(param_1);
  param_1->update_interval = 200;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x117);
  param_1->last_update_time = uVar1;
  param_1->map_redraw_interval = 1000;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x11a);
  param_1->last_map_redraw_time = uVar1;
  param_1->save_text_color = 0;
  param_1->save_window_color = 0;
  param_1->changed_system_colors = 0;
  param_1->CurrentVictory = 0;
  (**(code **)(rge_base_game->_padding_ + 0xc))(7);
  iVar2 = TRIBE_Screen_Sed::command_new_map(param_1,(char *)unaff_retaddr,param_2,0,0x90,0x90,1);
  if (iVar2 == 0) {
    param_1->_padding_ = 1;
    goto LAB_004a8728;
  }
  iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
  sprintf(abStack_114,s_default_d_scx,iVar2);
  if (unaff_retaddr != (byte *)0x0) {
    pbVar10 = abStack_114;
    pbVar3 = unaff_retaddr;
    do {
      bVar9 = *pbVar3;
      bVar11 = bVar9 < *pbVar10;
      if (bVar9 != *pbVar10) {
LAB_004a8376:
        iVar2 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_004a837b;
      }
      if (bVar9 == 0) break;
      bVar9 = pbVar3[1];
      bVar11 = bVar9 < pbVar10[1];
      if (bVar9 != pbVar10[1]) goto LAB_004a8376;
      pbVar3 = pbVar3 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar9 != 0);
    iVar2 = 0;
LAB_004a837b:
    if (iVar2 == 0) {
      param_1->need_to_save_flag = '\x01';
    }
  }
  lVar4 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,s_scr5,0xc387,1);
  if (lVar4 != 0) {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
    this = (RGE_Main_View *)operator_new(0x380);
    pcStack_8._0_1_ = 1;
    if (this == (RGE_Main_View *)0x0) {
      this = (RGE_Main_View *)0x0;
    }
    else {
      RGE_Main_View::RGE_Main_View(this);
      this->_padding_ = (int)&TRIBE_Main_View::_vftable_;
    }
    pcStack_8._0_1_ = 0;
    param_1->main_view = (TRIBE_Main_View *)this;
    if ((this != (RGE_Main_View *)0x0) && (this->_padding_ == 0)) {
      lVar4 = RGE_View::setup((RGE_View *)this,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0,0
                              ,0,0,0xa1,0,s_bordline);
      if (lVar4 != 0) {
        this_00 = (RGE_Diamond_Map_View *)operator_new(0x16c);
        pcStack_8._0_1_ = 2;
        if (this_00 == (RGE_Diamond_Map_View *)0x0) {
          this_01 = (RGE_Diamond_Map *)0x0;
        }
        else {
          this_01 = (RGE_Diamond_Map *)RGE_Diamond_Map_View::RGE_Diamond_Map_View(this_00);
        }
        pcStack_8._0_1_ = 0;
        param_1->map_view = (RGE_Diamond_Map_View *)this_01;
        if ((this_01 != (RGE_Diamond_Map *)0x0) && (this_01->_padding_ == 0)) {
          lVar4 = RGE_Diamond_Map::setup
                            (this_01,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0,0,0,0,0xa1,
                             0,rge_base_game->map_save_area);
          if (lVar4 != 0) {
            RGE_Diamond_Map::set_bitmap((RGE_Diamond_Map *)param_1->map_view,s_map640_bmp,0xc4e1);
            *(TRIBE_Main_View **)&param_1->map_view->field_0x150 = param_1->main_view;
            *(RGE_Diamond_Map_View **)&param_1->main_view->field_0x360 = param_1->map_view;
            TPanel::set_help_info((TPanel *)param_1->main_view,-1,-1);
            pRVar5 = RGE_Base_Game::get_font(rge_base_game,0xb);
            pTVar6 = (TMessagePanel *)operator_new(0x380);
            pcStack_8._0_1_ = 3;
            if (pTVar6 == (TMessagePanel *)0x0) {
              pTVar6 = (TMessagePanel *)0x0;
            }
            else {
              pTVar6 = (TMessagePanel *)
                       TMessagePanel::TMessagePanel
                                 (pTVar6,pRVar5->font,pRVar5->font_wid,pRVar5->font_hgt);
            }
            pcStack_8._0_1_ = 0;
            param_1->message_panel = pTVar6;
            if ((pTVar6 != (TMessagePanel *)0x0) && (pTVar6->_padding_ == 0)) {
              iVar2 = (**(code **)(pTVar6->_padding_ + 4))
                                (param_1->_padding_,param_1->main_view,0,0,0,0,0);
              if (iVar2 != 0) {
                pTVar7 = (TPanel *)operator_new(0xf4);
                pcStack_8._0_1_ = 4;
                if (pTVar7 == (TPanel *)0x0) {
                  pTVar7 = (TPanel *)0x0;
                }
                else {
                  pTVar7 = (TPanel *)TPanel::TPanel(pTVar7);
                }
                pcStack_8 = (code *)((uint)pcStack_8._1_3_ << 8);
                param_1->bottom_panel = pTVar7;
                if ((pTVar7 != (TPanel *)0x0) && (pTVar7->error_code == 0)) {
                  iVar2 = (**(code **)(pTVar7->_padding_ + 4))(param_1->_padding_,param_1,0,0,0,0,0)
                  ;
                  if (iVar2 != 0) {
                    TRIBE_Screen_Sed::create_all_buttons_etc(param_1);
                    if ((unaff_retaddr == (byte *)0x0) || (*unaff_retaddr == 0)) {
                      TRIBE_Screen_Sed::set_player_active(param_1,0,1);
                      TRIBE_Screen_Sed::set_player_active(param_1,1,1);
                      iVar2 = 1;
                    }
                    else {
                      iVar2 = strstr(unaff_retaddr,s__scn);
                      if (iVar2 == 0) {
                        iVar2 = strstr(unaff_retaddr,s__SCN);
                        if (iVar2 != 0) goto LAB_004a8602;
                      }
                      else {
LAB_004a8602:
                        bVar9 = *unaff_retaddr;
                        pbVar10 = unaff_retaddr;
                        iVar2 = 0;
                        do {
                          iVar8 = iVar2;
                          pbVar10[(int)&uStack_218 - (int)unaff_retaddr] = bVar9;
                          bVar9 = pbVar10[1];
                          pbVar10 = pbVar10 + 1;
                          iVar2 = iVar8 + 1;
                        } while (bVar9 != 0x2e);
                        *(undefined1 *)((int)&uStack_218 + iVar8 + 1) = 0;
                        sprintf(unaff_retaddr,s__s_scx,&uStack_218);
                        RGE_Scenario::Set_scenario_name
                                  ((RGE_Scenario *)param_1->world->_padding_,(char *)unaff_retaddr);
                      }
                      iVar2 = 0;
                      do {
                        iVar8 = RGE_Scenario::Get_player_Active
                                          ((RGE_Scenario *)param_1->world->_padding_,iVar2);
                        if (iVar8 == 0) break;
                        iVar2 = iVar2 + 1;
                      } while (iVar2 < 8);
                      iVar2 = iVar2 + -1;
                    }
                    TDropDownPanel::set_line(param_1->player_number_list,iVar2);
                    TRIBE_Screen_Sed::SavePlayerActiveStatus(param_1);
                    TPanel::set_curr_child((TPanel *)param_1,param_1->bottom_panel);
                    TRIBE_Screen_Sed::position_panels(param_1);
                    TRIBE_Screen_Sed::set_panel_info(param_1);
                    TRIBE_Screen_Sed::set_map_type(param_1,MapTypeBlank,0);
                    TRIBE_Screen_Sed::set_mp_victory_type(param_1,VictoryTypeStandard,0);
                    TRIBE_Screen_Sed::set_brush_size(param_1,BrushSizeVerySmall);
                    TRIBE_Screen_Sed::set_paint_type(param_1,PaintTypeTerrain,0);
                    TRIBE_Screen_Sed::set_player(param_1,1,'\0','\0');
                    TRIBE_Screen_Sed::set_unit_player(param_1,1);
                    TRIBE_Screen_Sed::set_message_type(param_1,MessageTypeDescription,0);
                    TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeMap);
                    TRIBE_Screen_Sed::set_unit(param_1,-1);
                    RGE_Map::set_map_visible((RGE_Map *)param_1->world->_padding_,'\x01');
                    RGE_Map::set_map_fog((RGE_Map *)param_1->world->_padding_,'\0');
                    goto LAB_004a8728;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  param_1->_padding_ = 1;
LAB_004a8728:
  *unaff_FS_OFFSET = uStack_10;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a8745
// Address: 004a8745
// XREFS: None
TRIBE_Screen_Sed * __thiscall FUN_004a8745(TRIBE_Screen_Sed *param_1,byte param_2)
{
  TRIBE_Screen_Sed::~TRIBE_Screen_Sed(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004a876e
// Address: 004a876e
// XREFS: None
void __fastcall FUN_004a876e(int param_1)
{
  RGE_Player *pRVar1;
  
  RGE_View::set_world(*(RGE_View **)(param_1 + 0x4c8),*(RGE_Game_World **)(param_1 + 0x928));
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_View::set_player(*(RGE_View **)(param_1 + 0x4c8),pRVar1);
  RGE_Diamond_Map::set_world
            (*(RGE_Diamond_Map **)(param_1 + 0x4cc),*(RGE_Game_World **)(param_1 + 0x928));
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Diamond_Map::set_player(*(RGE_Diamond_Map **)(param_1 + 0x4cc),pRVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_004a87c7
// Address: 004a87c7
// XREFS: None
void __thiscall FUN_004a87c7(TPanel *param_1,char *param_2,int param_3,int param_4)
{
  TPanel::get_string(param_1,param_3,param_2,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_004a87e7
// Address: 004a87e7
// XREFS: None
void __thiscall
FUN_004a87e7(TRIBE_Screen_Sed *param_1,TPanel *param_2,TButtonPanel **param_3,int param_4)
{
  char acStack_78 [120];
  
  TPanel::get_string((TPanel *)param_1,param_4,acStack_78,0x78);
  TRIBE_Screen_Sed::create_button
            (param_1,param_2,param_3,acStack_78,(char *)0x0,(char *)0x0,(char *)0x0);
  return;
}

// --------------------------------------------------

// Function: FUN_004a8835
// Address: 004a8835
// XREFS: None
undefined4 __thiscall
FUN_004a8835(TEasy_Panel *param_1,TPanel *param_2,TButtonPanel **param_3,char *param_4,char *param_5
            ,char *param_6,char *param_7)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_button(param_1,param_2,param_3,param_4,param_5,0,0,0,0,10,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_6 != (char *)0x0) {
    TButtonPanel::set_text(*param_3,2,param_6);
  }
  if (param_7 != (char *)0x0) {
    TButtonPanel::set_text(*param_3,3,param_7);
  }
  TPanel::set_z_order((TPanel *)*param_3,'\x01',0);
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  if (param_1->use_bevels != 0) {
    TButtonPanel::set_bevel_info
              (*param_3,3,(uint)param_1->bevel_color1,(uint)param_1->bevel_color2,
               (uint)param_1->bevel_color3,(uint)param_1->bevel_color4,(uint)param_1->bevel_color5,
               (uint)param_1->bevel_color6);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a8901
// Address: 004a8901
// XREFS: None
undefined4 __thiscall
FUN_004a8901(TEasy_Panel *param_1,TPanel *param_2,TTextPanel **param_3,int param_4)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_text(param_1,param_2,param_3,param_4,0,0,0,0,10,0,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_3,'\x01',0);
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a895a
// Address: 004a895a
// XREFS: None
undefined4 __thiscall
FUN_004a895a(TEasy_Panel *param_1,TPanel *param_2,TTextPanel **param_3,char *param_4)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_text(param_1,param_2,param_3,param_4,0,0,0,0,10,0,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_3,'\x01',0);
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a89aa
// Address: 004a89aa
// XREFS: None
undefined4 __thiscall
FUN_004a89aa(TEasy_Panel *param_1,TPanel *param_2,TInputPanel **param_3,char *param_4,short param_5,
            FormatType param_6)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_input(param_1,param_2,param_3,param_4,param_5,param_6,0,0,0,0,10);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_3,'\x01',0);
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a89fe
// Address: 004a89fe
// XREFS: None
undefined4 __thiscall
FUN_004a89fe(TEasy_Panel *param_1,TPanel *param_2,TEditPanel **param_3,char *param_4,short param_5,
            FormatType param_6,int param_7,int param_8)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_edit
                    (param_1,param_2,param_3,param_4,param_5,param_6,0,0,0,0,10,param_7,param_8);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_3,'\x01',0);
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a8a58
// Address: 004a8a58
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s__ai: ".ai"
// [HELPER] s__avi: ".avi"
// [HELPER] s__bmp: ".bmp"
// [HELPER] s__cty: ".cty"
// [HELPER] s__per: ".per"
bool __thiscall FUN_004a8a58(TRIBE_Screen_Sed *param_1,TPanel *param_2,TDropDownPanel **param_3)
{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  TDropDownPanel **ppTVar7;
  uint uVar8;
  uint uVar9;
  TDropDownPanel *pTVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  uchar uVar14;
  uchar uVar15;
  char acStack_104 [260];
  
  if ((((((param_3 == &param_1->victory_object_list) ||
         (param_3 == &param_1->victory_attribute_list)) || (param_3 == &param_1->victory_ages_list))
       || ((param_3 == &param_1->victory_tech_list || (param_3 == &param_1->BuildList)))) ||
      (param_3 == &param_1->CityLayout)) ||
     ((param_3 == &param_1->AiRules || (param_3 == &param_1->victory_time)))) {
    lVar3 = 0xdc;
  }
  else if (param_3 == &param_1->victory_drop_down) {
    lVar3 = 0xb4;
  }
  else if ((((param_3 == param_1->cinematic_input) || (param_3 == param_1->cinematic_input + 1)) ||
           (param_3 == param_1->cinematic_input + 2)) ||
          (((param_3 == param_1->cinematic_input + 3 || (param_3 == &param_1->default_terrain_drop))
           || ((param_3 == &param_1->map_size_drop || (param_3 == &param_1->map_style_drop)))))) {
    lVar3 = 0xaa;
  }
  else if (((param_3 == &param_1->player_advance_civilization_drop) ||
           (param_3 == &param_1->player_list)) ||
          (((param_3 == &param_1->player_number_list ||
            (((param_3 == &param_1->unit_player_list || (param_3 == &param_1->victory_player_list))
             || (param_3 == &param_1->options_player_list)))) ||
           ((param_3 == &param_1->Diplomacy_player_list ||
            (param_3 == &param_1->victory_enemy_player_list)))))) {
    lVar3 = 0x96;
  }
  else {
    lVar3 = 0x82;
  }
  iVar4 = TEasy_Panel::create_drop_down
                    ((TEasy_Panel *)param_1,param_2,param_3,lVar3,100,0,0,lVar3,0x16,10);
  if (iVar4 == 0) {
    return false;
  }
  TPanel::set_z_order((TPanel *)*param_3,'\x01',0);
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  TDropDownPanel::empty_list(*param_3);
  ppTVar7 = &param_1->map_size_drop;
  if (param_3 == ppTVar7) {
    TDropDownPanel::append_line(*ppTVar7,0x2973,0);
    TDropDownPanel::append_line(*ppTVar7,0x2974,0);
    TDropDownPanel::append_line(*ppTVar7,0x2975,0);
    TDropDownPanel::append_line(*ppTVar7,0x2976,0);
    TDropDownPanel::append_line(*ppTVar7,0x2977,0);
    TDropDownPanel::append_line(*ppTVar7,0x2978,0);
    pTVar10 = *ppTVar7;
    lVar3 = 3;
  }
  else {
    ppTVar7 = &param_1->map_style_drop;
    if (param_3 == ppTVar7) {
      TDropDownPanel::append_line(*ppTVar7,0x296a,0);
      TDropDownPanel::append_line(*ppTVar7,0x296b,0);
      TDropDownPanel::append_line(*ppTVar7,0x296c,0);
      TDropDownPanel::append_line(*ppTVar7,0x296d,0);
      TDropDownPanel::append_line(*ppTVar7,0x296e,0);
      TDropDownPanel::append_line(*ppTVar7,0x296f,0);
      TDropDownPanel::append_line(*ppTVar7,0x2970,0);
      TDropDownPanel::append_line(*ppTVar7,0x2971,0);
      TDropDownPanel::append_line(*ppTVar7,0x2972,0);
      pTVar10 = *ppTVar7;
      lVar3 = 3;
    }
    else {
      ppTVar7 = &param_1->player_number_list;
      if (param_3 == ppTVar7) {
        iVar4 = 0;
        do {
          TDropDownPanel::append_line(*ppTVar7,iVar4 + 0x2877,0);
          iVar4 = iVar4 + 1;
        } while (iVar4 < 8);
        pTVar10 = *ppTVar7;
        lVar3 = 0;
      }
      else {
        ppTVar7 = &param_1->victory_enemy_player_list;
        if (param_3 == ppTVar7) {
          iVar4 = 0;
          do {
            TDropDownPanel::append_line(*ppTVar7,iVar4 + 0x2877,0);
            iVar4 = iVar4 + 1;
          } while (iVar4 < 8);
          pTVar10 = *ppTVar7;
          lVar3 = 0;
        }
        else {
          ppTVar7 = &param_1->victory_attribute_list;
          if (param_3 == ppTVar7) {
            TDropDownPanel::append_line(*ppTVar7,0x2882,0x2b);
            TDropDownPanel::append_line(*ppTVar7,0x2883,0x29);
            TDropDownPanel::append_line(*ppTVar7,0x2884,0x2c);
            TDropDownPanel::append_line(*ppTVar7,0x2886,0x28);
            TDropDownPanel::append_line(*ppTVar7,0x2887,0x15);
            TDropDownPanel::append_line(*ppTVar7,0x2888,0x14);
            TDropDownPanel::append_line(*ppTVar7,0x2889,0x25);
            pTVar10 = *ppTVar7;
            lVar3 = 0;
          }
          else {
            ppTVar7 = &param_1->default_terrain_drop;
            if (param_3 == ppTVar7) {
              TDropDownPanel::append_line(*ppTVar7,0x297d,0);
              TDropDownPanel::append_line(*ppTVar7,0x297e,0);
              TDropDownPanel::append_line(*ppTVar7,0x297f,0);
              TDropDownPanel::append_line(*ppTVar7,0x2980,0);
              TDropDownPanel::append_line(*ppTVar7,0x2981,0);
              TDropDownPanel::append_line(*ppTVar7,0x2982,0);
              TDropDownPanel::append_line(*ppTVar7,0x2983,0);
              TDropDownPanel::append_line(*ppTVar7,0x2984,0);
              TDropDownPanel::append_line(*ppTVar7,0x2985,0);
              pTVar10 = *ppTVar7;
              lVar3 = 0;
            }
            else {
              ppTVar7 = param_1->player_setting_drop;
              if (param_3 == ppTVar7) {
                TDropDownPanel::append_line(*ppTVar7,0x27e3,0);
                TDropDownPanel::append_line(*ppTVar7,0x27e4,0);
                pTVar10 = *ppTVar7;
                lVar3 = 0;
              }
              else {
                ppTVar7 = &param_1->victory_drop_down;
                if (param_3 == ppTVar7) {
                  TDropDownPanel::append_line(*ppTVar7,0x2851,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2852,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2853,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2854,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2855,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2856,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2857,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2858,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2859,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285a,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285b,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285c,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285d,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285e,0);
                  TDropDownPanel::append_line(*ppTVar7,0x285f,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2860,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2861,0);
                  TDropDownPanel::append_line(*ppTVar7,0x2862,0);
                  TDropDownPanel::append_line(*ppTVar7,0x284f,0);
                  pTVar10 = *ppTVar7;
                  lVar3 = 0;
                }
                else {
                  ppTVar7 = param_1->player_setting_drop + 1;
                  if (param_3 == ppTVar7) {
                    TDropDownPanel::append_line(*ppTVar7,0x27f7,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27f8,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27f9,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fa,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fb,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fc,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fd,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27fe,0);
                    TDropDownPanel::append_line(*ppTVar7,0x27ff,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2800,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2801,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2802,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2806,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2807,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2809,0);
                    TDropDownPanel::append_line(*ppTVar7,0x2808,0);
                    pTVar10 = *ppTVar7;
                    lVar3 = 0;
                  }
                  else {
                    ppTVar7 = &param_1->victory_ages_list;
                    if (param_3 == ppTVar7) {
                      TDropDownPanel::append_line(*ppTVar7,0x1069,0);
                      TDropDownPanel::append_line(*ppTVar7,0x106a,0);
                      TDropDownPanel::append_line(*ppTVar7,0x106b,0);
                      TDropDownPanel::append_line(*ppTVar7,0x106c,0);
                      pTVar10 = *ppTVar7;
                      lVar3 = 0;
                    }
                    else {
                      ppTVar7 = &param_1->victory_tech_list;
                      if (param_3 == ppTVar7) {
                        TDropDownPanel::set_sorted(*ppTVar7,1);
                        iVar4 = 0;
                        piVar5 = (int *)rge_base_game->world[1]._padding_;
                        if (0 < (short)piVar5[1]) {
                          iVar12 = 0;
                          do {
                            pcVar6 = TPanel::get_string((TPanel *)param_1,
                                                        (int)*(short *)(*piVar5 + 0x2a + iVar12));
                            if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
                              TDropDownPanel::append_line(*ppTVar7,pcVar6,iVar4);
                            }
                            iVar4 = iVar4 + 1;
                            iVar12 = iVar12 + 0x3c;
                            piVar5 = (int *)rge_base_game->world[1]._padding_;
                          } while (iVar4 < (short)piVar5[1]);
                        }
                        pTVar10 = *ppTVar7;
                        lVar3 = 0;
                      }
                      else {
                        if (param_3 == &param_1->AiRules) {
                          uVar15 = '\x01';
                          uVar14 = '\0';
                          pcVar13 = s__per;
                          pTVar10 = param_1->AiRules;
                          pcVar6 = rge_base_game->prog_info->ai_dir;
                        }
                        else {
                          ppTVar7 = &param_1->BuildList;
                          if (param_3 == ppTVar7) {
                            uVar15 = '\x01';
                            pcVar13 = s__ai;
                          }
                          else {
                            ppTVar7 = &param_1->CityLayout;
                            if (param_3 != ppTVar7) {
                              if (((param_3 == param_1->cinematic_input) ||
                                  (param_3 == param_1->cinematic_input + 1)) ||
                                 (param_3 == param_1->cinematic_input + 2)) {
                                pTVar10 = *param_3;
                                uVar15 = '\0';
                                uVar14 = '\x01';
                                pcVar13 = s__avi;
                                pcVar6 = rge_base_game->prog_info->avi_dir;
                              }
                              else {
                                if (param_3 != param_1->cinematic_input + 3) {
                                  ppTVar7 = &param_1->victory_object_list;
                                  if (param_3 != ppTVar7) goto LAB_004a9300;
                                  TDropDownPanel::set_sorted(*ppTVar7,1);
                                  TDropDownPanel::empty_list(*ppTVar7);
                                  iVar11 = 0;
                                  iVar4 = *(int *)(param_1->world->_padding_ + 4);
                                  iVar12 = (int)*(short *)(iVar4 + 0x22);
                                  if (0 < iVar12) {
                                    do {
                                      iVar2 = *(int *)(*(int *)(iVar4 + 0x24) + iVar11 * 4);
                                      if ((iVar2 != 0) && (*(char *)(iVar2 + 0x4e) == '\0')) {
                                        if (*(short *)(iVar2 + 0xc) < 1) {
                                          uVar8 = 0xffffffff;
                                          pcVar6 = *(char **)(iVar2 + 8);
                                          do {
                                            pcVar13 = pcVar6;
                                            if (uVar8 == 0) break;
                                            uVar8 = uVar8 - 1;
                                            pcVar13 = pcVar6 + 1;
                                            cVar1 = *pcVar6;
                                            pcVar6 = pcVar13;
                                          } while (cVar1 != '\0');
                                          uVar8 = ~uVar8;
                                          pcVar6 = pcVar13 + -uVar8;
                                          pcVar13 = acStack_104;
                                          for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                                            *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;
                                            pcVar6 = pcVar6 + 4;
                                            pcVar13 = pcVar13 + 4;
                                          }
                                          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                                            *pcVar13 = *pcVar6;
                                            pcVar6 = pcVar6 + 1;
                                            pcVar13 = pcVar13 + 1;
                                          }
                                        }
                                        else {
                                          (**(code **)(rge_base_game->_padding_ + 0x20))
                                                    ((int)*(short *)(iVar2 + 0xc),acStack_104,0x100)
                                          ;
                                        }
                                        TDropDownPanel::append_line
                                                  (param_1->victory_object_list,acStack_104,iVar11);
                                      }
                                      iVar11 = iVar11 + 1;
                                    } while (iVar11 < iVar12);
                                  }
                                  pTVar10 = param_1->victory_object_list;
                                  lVar3 = 0;
                                  goto LAB_004a92fb;
                                }
                                pTVar10 = *param_3;
                                uVar15 = '\0';
                                uVar14 = '\x01';
                                pcVar13 = s__bmp;
                                pcVar6 = s_;
                              }
                              goto LAB_004a92f0;
                            }
                            uVar15 = '\0';
                            pcVar13 = s__cty;
                          }
                          uVar14 = '\x01';
                          pTVar10 = *ppTVar7;
                          pcVar6 = rge_base_game->prog_info->ai_dir;
                        }
LAB_004a92f0:
                        TRIBE_Screen_Sed::MakeFileList(param_1,pTVar10,pcVar6,pcVar13,uVar14,uVar15)
                        ;
                        pTVar10 = *param_3;
                        lVar3 = 0;
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
LAB_004a92fb:
  TDropDownPanel::set_line(pTVar10,lVar3);
LAB_004a9300:
  return param_1->_padding_ == 0;
}

// --------------------------------------------------

// Function: FUN_004a931a
// Address: 004a931a
// XREFS: None
undefined4 FUN_004a931a(TTextPanel *param_1)
{
  TTextPanel::empty_list(param_1);
  TTextPanel::append_line(param_1,0x297d,0);
  TTextPanel::append_line(param_1,0x297e,0);
  TTextPanel::append_line(param_1,0x297f,0);
  TTextPanel::append_line(param_1,0x2980,0);
  TTextPanel::append_line(param_1,0x2981,0);
  TTextPanel::append_line(param_1,0x2982,0);
  TTextPanel::append_line(param_1,0x2983,0);
  TTextPanel::append_line(param_1,0x2984,0);
  TTextPanel::append_line(param_1,0x2985,0);
  return 8;
}

// --------------------------------------------------

// Function: FUN_004a93b3
// Address: 004a93b3
// XREFS: None
// [HELPER] s__s__d: "%s %d"
undefined4 __thiscall
FUN_004a93b3(TRIBE_Screen_Sed *param_1,TPanel *param_2,TScrollBarPanel **param_3)
{
  int iVar1;
  char acStack_40 [64];
  
  iVar1 = TEasy_Panel::create_list((TEasy_Panel *)param_1,param_2,(TListPanel **)param_3,0,0,0,0,10)
  ;
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  TTextPanel::empty_list((TTextPanel *)*param_3);
  iVar1 = TEasy_Panel::create_auto_scrollbar
                    ((TEasy_Panel *)param_1,param_3,(TTextPanel *)*param_3,0x14);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_3 == (TScrollBarPanel **)&param_1->paint_elevation_list) {
    TRIBE_Screen_Sed::set_string(param_1,&stack0xffffff8c,0x2987,0x32);
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      sprintf(acStack_40,s__s__d,&stack0xffffff8c,iVar1);
      TTextPanel::append_line((TTextPanel *)param_1->paint_elevation_list,acStack_40,0);
    } while (iVar1 < 7);
    return 1;
  }
  if (param_3 == (TScrollBarPanel **)&param_1->paint_terrain_list) {
    TRIBE_Screen_Sed::SetupListOfTerrain(param_1,param_1->paint_terrain_list);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004a949e
// Address: 004a949e
// XREFS: None
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Scenario_Menu_Dialog: "Scenario Menu Dialog"
void __fastcall FUN_004a949e(TScreenPanel *param_1)
{
  TShape *pTVar1;
  int iVar2;
  undefined4 *puVar3;
  TPanel **ppTVar4;
  TPanel **ppTVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f468;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Sed::_vftable_;
  uStack_4 = 0;
  TPanelSystem::destroyPanel(&panel_system,&s_QuitSaveDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_OpenSaveDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_NewSaveDialog);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xa8);
  ppTVar4 = (TPanel **)&param_1[1].field_0x9c;
  iVar2 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -3);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xac);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xb0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xb4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xb8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xbc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xd8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xcc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xd0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xd4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xdc);
  ppTVar4 = (TPanel **)&param_1[1].field_0xf4;
  iVar2 = 5;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -5);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x108);
  ppTVar4 = (TPanel **)&param_1[1].field_0x118;
  iVar2 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -3);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x124);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x128);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x12c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x130);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x134);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x144);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x138);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x17c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x194);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x198);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x19c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x13c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x140);
  ppTVar4 = (TPanel **)&param_1[1].field_0x160;
  iVar2 = 5;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -5);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar4 = (TPanel **)&param_1[1].field_0x180;
  iVar2 = 2;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -3);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x188);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x18c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x190);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1a0);
  ppTVar4 = (TPanel **)&param_1[1].field_0x1b4;
  iVar2 = 4;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -4);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1c4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1c8);
  if (*(int *)&param_1[1].field_0x1cc != 0) {
    free(*(int *)&param_1[1].field_0x1cc);
    *(undefined4 *)&param_1[1].field_0x1cc = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x1e8 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x1e8)(1);
    *(undefined4 *)&param_1[1].field_0x1e8 = 0;
  }
  pTVar1 = *(TShape **)&param_1[1].field_0x1d0;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0x1d0 = 0;
  }
  puVar3 = (undefined4 *)&param_1[1].field_0x1d4;
  iVar2 = 5;
  do {
    pTVar1 = (TShape *)*puVar3;
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
      *puVar3 = 0;
    }
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar4 = (TPanel **)&param_1[1].field_0x1f0;
  iVar2 = 6;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar4 = (TPanel **)&param_1[1].field_0x21c;
  iVar2 = 2;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -5);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x214);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x218);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x210);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x224);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x228);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x22c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x230);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x234);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x238);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x23c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x240);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x244);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x248);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x24c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x250);
  ppTVar4 = (TPanel **)&param_1[1].field_0x268;
  iVar2 = 5;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -5);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x27c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x280);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x284);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x288);
  ppTVar4 = (TPanel **)&param_1[1].field_0x28c;
  iVar2 = 0xc;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2bc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2c0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2c4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2d0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2d4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2d8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2dc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2e0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2e4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2e8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2ec);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2f4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2c8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2cc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2f0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2f8);
  ppTVar4 = (TPanel **)&param_1[1].field_0x314;
  iVar2 = 5;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -5);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2fc);
  ppTVar4 = (TPanel **)&param_1[1].field_0x33c;
  iVar2 = 4;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -4);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar4 = (TPanel **)&param_1[1].field_0x350;
  iVar2 = 1;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -1);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x354);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x358);
  ppTVar4 = (TPanel **)&param_1[1].field_0x39c;
  iVar2 = 0x10;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -0x10);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ppTVar4 = (TPanel **)&param_1[2].field_0x18;
  ppTVar5 = (TPanel **)&param_1[1].field_0x434;
  iVar2 = 8;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x41c);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4 + -0x25);
    TPanel::delete_panel((TPanel *)param_1,ppTVar5 + -1);
    TPanel::delete_panel((TPanel *)param_1,ppTVar5);
    TPanel::delete_panel((TPanel *)param_1,ppTVar5 + 1);
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    ppTVar5 = ppTVar5 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x420);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x424);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x428);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x42c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x88);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8c);
  ppTVar4 = (TPanel **)&param_1[1].field_0x60;
  iVar2 = 10;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar4);
    ppTVar4 = ppTVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x5c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x58);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x50);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x54);
  pTVar1 = *(TShape **)&param_1[1].field_0x4c;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0x4c = 0;
  }
  if (*(int **)&param_1[2].field_0x38 != (int *)0x0) {
    (**(code **)(**(int **)&param_1[2].field_0x38 + 0xb8))();
  }
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004a9cbe
// Address: 004a9cbe
// XREFS: None
void __thiscall FUN_004a9cbe(TRIBE_Screen_Sed *param_1,ScenarioMode param_2)
{
  short sVar1;
  TRIBE_Player *pTVar2;
  RGE_Player *pRVar3;
  char *pcVar4;
  long lVar5;
  int iVar6;
  TButtonPanel *pTVar7;
  TEditPanel **ppTVar8;
  TDropDownPanel **ppTVar9;
  TDropDownPanel **ppTVar10;
  TButtonPanel **ppTVar11;
  TButtonPanel **ppTVar12;
  TTextPanel **ppTVar13;
  int unaff_EBP;
  int iVar14;
  int iVar15;
  RGE_Master_Static_Object *pRVar16;
  int iStack_c;
  int iStack_8;
  ScenarioMode SStack_4;
  
  iStack_8 = 0;
  param_1->valid_save_spot_flag = '\0';
  do {
    if (iStack_8 == 0) {
      SStack_4 = param_1->scenario_mode;
      iVar15 = 0;
    }
    else {
      if (param_2 != ScenarioModeSave) {
        SStack_4 = param_2;
      }
      iVar15 = 1;
    }
    switch(SStack_4) {
    case ScenarioModeMap:
      (**(code **)(param_1->map_type_label->_padding_ + 0x14))(iVar15);
      ppTVar13 = param_1->map_type_text;
      iVar14 = 3;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-3])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      (**(code **)(param_1->generate_map_button->_padding_ + 0x14))(iVar15);
      if (iVar15 == 0) {
        TRIBE_Screen_Sed::set_map_type(param_1,MapTypeNone,0);
      }
      else {
        TRIBE_Screen_Sed::set_map_type(param_1,param_1->map_type,1);
      }
      break;
    case ScenarioModeTerrain:
      (**(code **)(param_1->brush_size_label->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->paint_type_label->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->paint_terrain_label->_padding_ + 0x14))(iVar15);
      ppTVar13 = param_1->brush_size_button_label;
      iVar14 = 5;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-5])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      ppTVar13 = param_1->paint_type_button_label;
      iVar14 = 3;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-3])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (iVar15 == 0) {
        TRIBE_Screen_Sed::set_brush_size(param_1,BrushSizeNone);
        TRIBE_Screen_Sed::set_paint_type(param_1,PaintTypeNone,0);
      }
      else {
        TRIBE_Screen_Sed::set_brush_size(param_1,param_1->brush_size);
        TRIBE_Screen_Sed::set_paint_type(param_1,param_1->paint_type,1);
      }
      break;
    case ScenarioModePlayers:
      (**(code **)(param_1->player_list->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->player_number_list->_padding_ + 0x14))(iVar15);
      ppTVar8 = param_1->player_inven_input;
      iVar14 = 5;
      do {
        (**(code **)(((TTextPanel *)ppTVar8[-5])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar8)->_padding_ + 0x14))(iVar15);
        ppTVar8 = ppTVar8 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      ppTVar9 = param_1->player_setting_drop;
      iVar14 = 2;
      do {
        (**(code **)(((TTextPanel *)ppTVar9[-3])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar9)->_padding_ + 0x14))(iVar15);
        ppTVar9 = ppTVar9 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (iVar15 == 0) {
        TRIBE_Screen_Sed::set_player(param_1,param_1->player_num,'\x01','\0');
        (**(code **)(*(int *)param_1->map_view + 0x14))(1);
        TRIBE_Screen_Sed::SavePlayerActiveStatus(param_1);
      }
      else {
        iVar14 = T_Scenario::GetPlayerAge
                           ((T_Scenario *)param_1->world->_padding_,param_1->player_num + -1);
        TDropDownPanel::setCurrentLineNumber(param_1->player_advance_civilization_drop,iVar14);
        TRIBE_Screen_Sed::set_player(param_1,param_1->player_num,'\0','\x01');
        TPanel::set_curr_child(param_1->bottom_panel,(TPanel *)0x0);
        (**(code **)(*(int *)param_1->map_view + 0x14))(0);
      }
      (**(code **)(param_1->player_advance_civilization_drop->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->player_label->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->player_starting_age_label->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->player_build_text->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->player_city_text->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->AiRules_text->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->BuildList->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->CityLayout->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->AiRules->_padding_ + 0x14))(iVar15);
      break;
    case ScenarioModeUnits:
      (**(code **)(param_1->unit_player_list->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->unit_list->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->object_panel->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->unit_mode_select[0]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->unit_mode_select[1]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->unit_mode_select[2]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->unit_mode_select[3]->_padding_ + 0x14))(iVar15);
      if (iVar15 != 0) {
        TButtonPanel::set_radio_button(param_1->unit_mode_select[0]);
      }
      (**(code **)(param_1->unit_mode_select_label[0]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->unit_mode_select_label[1]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->unit_mode_select_label[2]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->unit_mode_select_label[3]->_padding_ + 0x14))(iVar15);
      sVar1 = param_1->player_num;
      if (iVar15 == 0) {
        if ((sVar1 < 1) || (8 < sVar1)) {
          param_1->player_num = 1;
          TRIBE_Screen_Sed::set_player(param_1,1,'\0','\0');
        }
        (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
        TRIBE_Screen_Sed::set_unit(param_1,-1);
      }
      else {
        TRIBE_Screen_Sed::set_unit_player(param_1,sVar1);
        iVar15 = TTextPanel::currentLineNumber((TTextPanel *)param_1->unit_list);
        TRIBE_Screen_Sed::set_unit(param_1,(short)iVar15);
        TPanel::set_curr_child(param_1->bottom_panel,(TPanel *)param_1->unit_list);
        TRIBE_Screen_Sed::set_paint_object_mode(param_1);
        (**(code **)(rge_base_game->_padding_ + 0x10))(rge_base_game->game_mode,4);
        if ((rge_base_game->master_obj_id == -1) ||
           (pRVar3 = RGE_Base_Game::get_player(rge_base_game), pRVar3 == (RGE_Player *)0x0)) {
          pTVar2 = (TRIBE_Player *)0x0;
          pRVar16 = (RGE_Master_Static_Object *)0x0;
        }
        else {
          sVar1 = rge_base_game->master_obj_id;
          pTVar2 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
          pRVar3 = RGE_Base_Game::get_player(rge_base_game);
          pRVar16 = *(RGE_Master_Static_Object **)
                     (*(int *)(*(int *)(param_1->world->_padding_ + pRVar3->id * 4) + 0x24) +
                     sVar1 * 4);
        }
        TRIBE_Scenario_Editor_Panel_Object::set_master_info(param_1->object_panel,pRVar16,pTVar2);
        (**(code **)(param_1->object_panel->_padding_ + 0x20))(1);
      }
      break;
    case ScenarioModeDiplomacy:
      if (param_1->player_num < 1) {
        param_1->player_num = 1;
      }
      (**(code **)(param_1->Diplomacy_player_list->_padding_ + 0x14))(iVar15);
      iVar14 = 0;
      lVar5 = TDropDownPanel::get_line(param_1->player_number_list);
      if (-1 < lVar5) {
        ppTVar12 = param_1->Diplomacy_friend_box[0] + 1;
        ppTVar11 = param_1->Diplomacy_AlliedVictory;
        do {
          (**(code **)(((TTextPanel *)ppTVar11[-0x25])->_padding_ + 0x14))(iVar15);
          pTVar7 = *ppTVar11;
          if (unaff_EBP != param_1->player_num + -1) {
            (**(code **)(pTVar7->_padding_ + 0x14))(0);
            (**(code **)((*(TButtonPanel *(*) [3])(ppTVar12 + -1))[0]->_padding_ + 0x14))(iVar15);
            (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
            pTVar7 = ppTVar12[1];
          }
          (**(code **)(pTVar7->_padding_ + 0x14))(iVar15);
          ppTVar11 = ppTVar11 + 1;
          iVar14 = iVar14 + 1;
          ppTVar12 = ppTVar12 + 3;
          lVar5 = TDropDownPanel::get_line(param_1->player_number_list);
        } while (iVar14 <= lVar5);
      }
      (**(code **)(param_1->Diplomacy_status_label[0]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->Diplomacy_status_label[1]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->Diplomacy_status_label[2]->_padding_ + 0x14))(iVar15);
      (**(code **)(param_1->Diplomacy_status_label[3]->_padding_ + 0x14))(iVar15);
      if (iVar15 == 0) {
        TRIBE_Screen_Sed::save_diplomacy_in_scenario(param_1,param_1->player_num + -1);
      }
      else {
        TRIBE_Screen_Sed::load_diplomacy_from_scenario(param_1,param_1->player_num + -1);
      }
      break;
    case ScenarioModeVictory:
      TRIBE_Screen_Sed::activate_victory_panel(param_1,iVar15);
      if (iVar15 == 0) {
        TRIBE_Screen_Sed::save_victory_cond_in_scenario(param_1,param_1->CurrentVictory);
        iVar15 = 0;
        lVar5 = TDropDownPanel::get_line(param_1->victory_drop_down);
        TRIBE_Screen_Sed::activate_victory_proper_fields(param_1,lVar5,iVar15);
        param_1->SelectedObject = (RGE_Static_Object *)0x0;
        param_1->DestinationObject = (RGE_Static_Object *)0x0;
        pRVar3 = RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::unselect_object(pRVar3);
      }
      else {
        TRIBE_Screen_Sed::load_victory_cond_from_scenario(param_1,param_1->CurrentVictory);
        lVar5 = TDropDownPanel::get_line(param_1->victory_drop_down);
        TRIBE_Screen_Sed::activate_victory_proper_fields(param_1,lVar5,iVar15);
      }
      break;
    case ScenarioModeVictoryMulti:
      (**(code **)(param_1->victory_condition_label->_padding_ + 0x14))(iVar15);
      ppTVar12 = param_1->victory_cond_type;
      iVar14 = 5;
      do {
        (**(code **)(((TTextPanel *)ppTVar12[-5])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
        ppTVar12 = ppTVar12 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (iVar15 == 0) {
        TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario(param_1);
        (**(code **)(*(int *)param_1->map_view + 0x14))(1);
        TRIBE_Screen_Sed::set_mp_victory_type(param_1,VictoryTypeNone,0);
      }
      else {
        TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario(param_1);
        (**(code **)(*(int *)param_1->map_view + 0x14))(0);
        TRIBE_Screen_Sed::set_mp_victory_type(param_1,param_1->mp_victory_type,1);
      }
      break;
    case ScenarioModeOptions:
      if (iVar15 == 0) {
        (**(code **)(*(int *)param_1->map_view + 0x14))(1);
        TRIBE_Screen_Sed::SaveDisabledItemsInScenario(param_1);
      }
      else {
        (**(code **)(*(int *)param_1->map_view + 0x14))(0);
        iVar14 = param_1->options_button[0]->_padding_;
        iVar6 = T_Scenario::GetScenarioOption((T_Scenario *)param_1->world->_padding_,2);
        (**(code **)(iVar14 + 0xe0))(iVar6);
        TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(param_1);
        if (param_1->player_num == 0) {
          iVar14 = 0;
        }
        else {
          iVar14 = param_1->player_num + -1;
        }
        TDropDownPanel::setCurrentLineNumber(param_1->options_player_list,iVar14);
      }
      ppTVar12 = param_1->options_button;
      iVar14 = 1;
      do {
        (**(code **)(((TTextPanel *)ppTVar12[-1])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar12)->_padding_ + 0x14))(iVar15);
        ppTVar12 = ppTVar12 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      (**(code **)(param_1->options_player_list->_padding_ + 0x14))(iVar15);
      if (iVar15 == 0) {
        lVar5 = TDropDownPanel::get_line(param_1->options_player_list);
        param_1->player_num = (short)lVar5 + 1;
      }
      else {
        TDropDownPanel::set_line(param_1->options_player_list,param_1->player_num + -1);
      }
      (**(code **)(param_1->options_disable_tech_text->_padding_ + 0x14))(iVar15);
      ppTVar13 = param_1->options_disable_text;
      iVar14 = 0x10;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-0x10])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      break;
    case ScenarioModeMessages:
      ppTVar13 = param_1->message_button_label;
      iVar14 = 5;
      do {
        (**(code **)(((TButtonPanel *)ppTVar13[-5])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar13)->_padding_ + 0x14))(iVar15);
        ppTVar13 = ppTVar13 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      TButtonPanel::set_radio_button(param_1->message_button[param_1->current_message]);
      lVar5 = param_1->current_message;
      if (iVar15 == 0) {
        pcVar4 = TEditPanel::get_input_buffer(param_1->message_input);
        RGE_Scenario::Set_message((RGE_Scenario *)param_1->world->_padding_,pcVar4,lVar5);
        TRIBE_Screen_Sed::set_message_type(param_1,MessageTypeNone,0);
        (**(code **)(*(int *)param_1->map_view + 0x14))(1);
        TRIBE_Screen_Sed::save_info_in_scenario(param_1);
        break;
      }
      pcVar4 = RGE_Scenario::Get_message((RGE_Scenario *)param_1->world->_padding_,lVar5);
      TEditPanel::set_text(param_1->message_input,pcVar4);
      switch(param_1->current_message) {
      case 0:
        lVar5 = 0x7770;
        break;
      case 1:
        lVar5 = 0x7771;
        break;
      case 2:
        lVar5 = 0x7772;
        break;
      case 3:
        lVar5 = 0x7773;
        break;
      case 4:
        lVar5 = 0x7774;
        break;
      default:
        goto switchD_004aa268_default;
      }
      TPanel::set_help_info((TPanel *)param_1->message_input,lVar5,-1);
switchD_004aa268_default:
      TRIBE_Screen_Sed::set_message_type(param_1,param_1->message_type,1);
      (**(code **)(*(int *)param_1->map_view + 0x14))(0);
      TPanel::set_curr_child(param_1->bottom_panel,(TPanel *)param_1->message_input);
      break;
    case ScenarioModeCinematics:
      ppTVar9 = param_1->cinematic_input;
      iStack_c = 4;
      ppTVar10 = ppTVar9;
      do {
        (**(code **)(((TTextPanel *)ppTVar10[-4])->_padding_ + 0x14))(iVar15);
        (**(code **)((*ppTVar10)->_padding_ + 0x14))(iVar15);
        ppTVar10 = ppTVar10 + 1;
        iStack_c = iStack_c + -1;
      } while (iStack_c != 0);
      if (iVar15 == 0) {
        pcVar4 = TDropDownPanel::currentLine(*ppTVar9);
        RGE_Scenario::Set_Cine_PreGame((RGE_Scenario *)param_1->world->_padding_,pcVar4);
        pcVar4 = TDropDownPanel::currentLine(param_1->cinematic_input[1]);
        RGE_Scenario::Set_Cine_Victory((RGE_Scenario *)param_1->world->_padding_,pcVar4);
        pcVar4 = TDropDownPanel::currentLine(param_1->cinematic_input[2]);
        RGE_Scenario::Set_Cine_Loss((RGE_Scenario *)param_1->world->_padding_,pcVar4);
        pcVar4 = TDropDownPanel::currentLine(param_1->cinematic_input[3]);
        RGE_Scenario::Set_Mission_Bmp((RGE_Scenario *)param_1->world->_padding_,pcVar4);
      }
      else {
        TPanel::set_curr_child(param_1->bottom_panel,(TPanel *)*ppTVar9);
        pcVar4 = RGE_Scenario::Get_Cine_PreGame((RGE_Scenario *)param_1->world->_padding_);
        lVar5 = TDropDownPanel::get_line(*ppTVar9,pcVar4);
        TDropDownPanel::setCurrentLineNumber(*ppTVar9,lVar5);
        pcVar4 = RGE_Scenario::Get_Cine_Victory((RGE_Scenario *)param_1->world->_padding_);
        lVar5 = TDropDownPanel::get_line(param_1->cinematic_input[1],pcVar4);
        TDropDownPanel::setCurrentLineNumber(param_1->cinematic_input[1],lVar5);
        pcVar4 = RGE_Scenario::Get_Cine_Loss((RGE_Scenario *)param_1->world->_padding_);
        lVar5 = TDropDownPanel::get_line(param_1->cinematic_input[2],pcVar4);
        TDropDownPanel::setCurrentLineNumber(param_1->cinematic_input[2],lVar5);
        pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)param_1->world->_padding_);
        iVar15 = TDropDownPanel::get_line(param_1->cinematic_input[3],pcVar4);
        if (iVar15 == -1) {
          lVar5 = 0;
          pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)param_1->world->_padding_);
          TDropDownPanel::append_line(param_1->cinematic_input[3],pcVar4,lVar5);
          pcVar4 = RGE_Scenario::Get_Mission_Bmp((RGE_Scenario *)param_1->world->_padding_);
          iVar15 = TDropDownPanel::get_line(param_1->cinematic_input[3],pcVar4);
        }
        TDropDownPanel::setCurrentLineNumber(param_1->cinematic_input[3],iVar15);
      }
    }
    iStack_8 = iStack_8 + 1;
    if (1 < iStack_8) {
      if (param_2 != ScenarioModeSave) {
        param_1->scenario_mode = param_2;
        if (param_2 != ScenarioModeNone) {
          TButtonPanel::set_radio_button(param_1->scenario_mode_button[param_2 - ScenarioModeMap]);
        }
        iVar15 = param_1->_padding_;
        (**(code **)(iVar15 + 0x50))(param_1->_padding_,param_1->_padding_);
        (**(code **)(iVar15 + 0x20))(1);
      }
      param_1->valid_save_spot_flag = '\x01';
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004aa6e6
// Address: 004aa6e6
// XREFS: None
void __fastcall FUN_004aa6e6(int param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  undefined4 in_EAX;
  char cVar4;
  char cVar5;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  cVar5 = (char)((uint)unaff_EBX >> 8);
  *(char *)(param_2 + -100) = *(char *)(param_2 + -100) + cVar5;
  *(char *)(param_2 + -2) = *(char *)(param_2 + -2) + (char)((uint)in_EAX >> 8);
  pcVar1 = (char *)(unaff_EDI + 0x4a + unaff_EBX * 4);
  cVar4 = (char)((uint)param_1 >> 8);
  *pcVar1 = *pcVar1 + cVar4;
  *(char *)(unaff_ESI + 0x9004aa4) = *(char *)(unaff_ESI + 0x9004aa4) + (char)param_2 + -3;
  iVar2 = iRama183004a;
  *(char *)(iRama183004a + 0x4aa5) = *(char *)(iRama183004a + 0x4aa5) + (char)unaff_EBX;
  cRama293004a = (char)iVar2;
  cRama317004a = cRama293004a;
  *(char *)(unaff_EDI + -0x5e) = *(char *)(unaff_EDI + -0x5e) + cVar4;
  *(char *)(iVar2 + -0x5e) = *(char *)(iVar2 + -0x5e) + cVar5;
  *(char *)(param_1 + -0x75ffb55e) = *(char *)(param_1 + -0x75ffb55e) + cRama293004a;
  *(char *)(iVar2 + -0x6f6f6f70) = *(char *)(iVar2 + -0x6f6f6f70) + (char)param_2 + -8;
  bVar3 = false;
  if ((((rge_base_game->master_obj_id != -1) &&
       (iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x928) + 0x40) +
                                          *(short *)(param_1 + 0x4b8) * 4) + 0x24) +
                        rge_base_game->master_obj_id * 4), iVar2 != 0)) &&
      (*(char *)(iVar2 + 4) == 'P')) && (*(char *)(iVar2 + 0x16c) != '\0')) {
    bVar3 = true;
  }
  if (bVar3) {
    (**(code **)(rge_base_game->_padding_ + 0x10))(0x15,0);
    return;
  }
  (**(code **)(rge_base_game->_padding_ + 0x10))(8,rge_base_game->sub_game_mode);
  return;
}

// --------------------------------------------------

// Function: FUN_004aa79b
// Address: 004aa79b
// XREFS: None
void __thiscall FUN_004aa79b(int param_1,int param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  do {
    if (iVar3 == 0) {
      iVar4 = 0;
      iVar1 = *(int *)(param_1 + 0x4a8);
    }
    else {
      if (param_2 == 0) {
        return;
      }
      if (param_3 == 0) break;
      iVar4 = 1;
      iVar1 = param_2;
    }
    if (iVar1 == 1) {
      (**(code **)(**(int **)(param_1 + 0x52c) + 0x14))(iVar4);
      (**(code **)(**(int **)(param_1 + 0x530) + 0x14))(iVar4);
      (**(code **)(**(int **)(param_1 + 0x524) + 0x14))(iVar4);
      piVar2 = *(int **)(param_1 + 0x528);
LAB_004aa8b8:
      (**(code **)(*piVar2 + 0x14))(iVar4);
    }
    else {
      if (iVar1 == 2) {
        (**(code **)(**(int **)(param_1 + 0x52c) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x530) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x534) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x538) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x544) + 0x14))(iVar4);
        piVar2 = *(int **)(param_1 + 0x548);
        goto LAB_004aa8b8;
      }
      if (iVar1 == 3) {
        (**(code **)(**(int **)(param_1 + 0x52c) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x530) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x534) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x538) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x53c) + 0x14))(iVar4);
        (**(code **)(**(int **)(param_1 + 0x540) + 0x14))(iVar4);
        if (iVar4 != 0) {
          TPanel::set_curr_child(*(TPanel **)(param_1 + 0x4d4),*(TPanel **)(param_1 + 0x540));
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  *(int *)(param_1 + 0x4a8) = param_2;
  TButtonPanel::set_radio_button(*(TButtonPanel **)(param_1 + 0x504 + param_2 * 4));
  (**(code **)(**(int **)(param_1 + 0x4d4) + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_004aa8ee
// Address: 004aa8ee
// XREFS: None
void __thiscall FUN_004aa8ee(int param_1,int param_2,int param_3)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  iStack_4 = 0;
  do {
    if (iStack_4 == 0) {
      iVar3 = 0;
      iVar2 = *(int *)(param_1 + 0x4ac);
    }
    else {
      if (param_2 == 0) {
        return;
      }
      if (param_3 == 0) break;
      iVar3 = 1;
      iVar2 = param_2;
    }
    switch(iVar2) {
    case 3:
      (**(code **)(**(int **)(param_1 + 0x6f4) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6f8) + 0x14))(iVar3);
      break;
    case 4:
      (**(code **)(**(int **)(param_1 + 0x6fc) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x700) + 0x14))(iVar3);
      break;
    case 5:
      puVar1 = (undefined4 *)(param_1 + 0x668);
      iVar2 = 5;
      do {
        (**(code **)(*(int *)*puVar1 + 0x14))(iVar3);
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      puVar1 = (undefined4 *)(param_1 + 0x694);
      iVar2 = 2;
      do {
        (**(code **)(*(int *)puVar1[-5] + 0x14))(iVar3);
        (**(code **)(*(int *)*puVar1 + 0x14))(iVar3);
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      (**(code **)(**(int **)(param_1 + 0x68c) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x69c) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6a0) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6a8) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6ac) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6b0) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6b8) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6bc) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6c0) + 0x14))(iVar3);
      (**(code **)(**(int **)(param_1 + 0x6c4) + 0x14))(iVar3);
      if (iVar3 == 1) {
        TPanel::set_curr_child(*(TPanel **)(param_1 + 0x4d4),*(TPanel **)(param_1 + 0x6b8));
      }
    }
    iStack_4 = iStack_4 + 1;
  } while (iStack_4 < 2);
  *(int *)(param_1 + 0x4ac) = param_2;
  TButtonPanel::set_radio_button(*(TButtonPanel **)(param_1 + 0x6dc + param_2 * 4));
  (**(code **)(**(int **)(param_1 + 0x4d4) + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_004aab4a
// Address: 004aab4a
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void FUN_004aab4a(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_004aad46
// Address: 004aad46
// XREFS: None
void __thiscall FUN_004aad46(int param_1,short param_2)
{
  short sVar1;
  
  switch(param_2) {
  default:
    sVar1 = 0;
    break;
  case 1:
    sVar1 = 6;
    break;
  case 2:
    sVar1 = 10;
    break;
  case 3:
    sVar1 = 1;
    break;
  case 4:
    sVar1 = 0xd;
    break;
  case 5:
    sVar1 = 0x14;
    break;
  case 6:
    sVar1 = 4;
    break;
  case 7:
    sVar1 = 0x13;
    break;
  case 8:
    sVar1 = 0x16;
  }
  rge_base_game->terrain_id = sVar1;
  TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x5a0),'\x01',param_2,1);
  return;
}

// --------------------------------------------------

// Function: FUN_004aadbf
// Address: 004aadbf
// XREFS: None
void __fastcall FUN_004aadbf(int param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  short unaff_retaddr;
  
  iVar2 = *unaff_ESI;
  pcVar1 = (char *)(unaff_EBP * 5 + 0x4a);
  *pcVar1 = *pcVar1 + (char)((uint)iVar2 >> 8);
  *(char *)(unaff_EBX + -0x53) = *(char *)(unaff_EBX + -0x53) + (char)((uint)param_1 >> 8);
  *(char *)(param_2 + -0x55) = *(char *)(param_2 + -0x55) + (char)((uint)(param_2 + -2) >> 8);
  *(char *)(param_1 + -0x53) = *(char *)(param_1 + -0x53) + (char)((uint)unaff_EBX >> 8);
  *(char *)(iVar2 + -0x78ffb553) = *(char *)(iVar2 + -0x78ffb553) + (char)iVar2;
  *(char *)((int)unaff_ESI + -0x6affb54b) = *(char *)((int)unaff_ESI + -0x6affb54b) + (char)param_1;
  *(char *)(unaff_ESI[2] + -0x6f6f6f70) =
       *(char *)(unaff_ESI[2] + -0x6f6f6f70) + (char)(param_2 + -2) + -4;
  rge_base_game->elevation_height = unaff_retaddr;
  TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x5a8),'\x01',unaff_retaddr,1);
  return;
}

// --------------------------------------------------

// Function: FUN_004aae13
// Address: 004aae13
// XREFS: None
// [HELPER] s__d: "%d"
void __thiscall FUN_004aae13(int param_1,undefined4 param_2,int param_3)
{
  RGE_Player *this;
  char *pcVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  long lVar5;
  
  iVar4 = *(short *)(param_1 + 0x4b8) + -1;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  this = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_object(this);
  if ((char)param_3 != '\0') {
    pcVar1 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x5d8));
    iVar2 = atoi(pcVar1);
    T_Scenario::Set_player_Food(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,iVar2);
    **(float **)
      (*(int *)(*(int *)(*(int *)(param_1 + 0x928) + 0x40) + *(short *)(param_1 + 0x4b8) * 4) + 0x50
      ) = (float)iVar2;
    pcVar1 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x5dc));
    iVar2 = atoi(pcVar1);
    T_Scenario::Set_player_Wood(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,iVar2);
    *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x928) + 0x40) +
                                *(short *)(param_1 + 0x4b8) * 4) + 0x50) + 4) = (float)iVar2;
    pcVar1 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x5e0));
    iVar2 = atoi(pcVar1);
    T_Scenario::Set_player_Stone(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,iVar2);
    *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x928) + 0x40) +
                                *(short *)(param_1 + 0x4b8) * 4) + 0x50) + 8) = (float)iVar2;
    pcVar1 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x5e4));
    param_3 = atoi(pcVar1);
    T_Scenario::Set_player_Gold(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,param_3);
    *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x928) + 0x40) +
                                *(short *)(param_1 + 0x4b8) * 4) + 0x50) + 0xc) = (float)param_3;
    pcVar1 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x5e8));
    RGE_Scenario::SetPlayerName(*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,pcVar1);
    iVar2 = TDropDownPanel::currentLineNumber(*(TDropDownPanel **)(param_1 + 0x5f8));
    RGE_Scenario::Set_player_Type(*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,iVar2);
    iVar2 = TDropDownPanel::currentLineNumber(*(TDropDownPanel **)(param_1 + 0x5fc));
    RGE_Scenario::Set_player_Civ
              (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,iVar2 + 1);
    iVar2 = 0;
    pcVar1 = TDropDownPanel::currentLine(*(TDropDownPanel **)(param_1 + 0x608));
    RGE_Scenario::Set_player_AI
              (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,pcVar1,iVar2);
    iVar2 = 0;
    pcVar1 = TDropDownPanel::currentLine(*(TDropDownPanel **)(param_1 + 0x600));
    RGE_Scenario::Set_BuildList
              (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,pcVar1,iVar2);
    iVar2 = 0;
    pcVar1 = TDropDownPanel::currentLine(*(TDropDownPanel **)(param_1 + 0x604));
    RGE_Scenario::Set_CityPlan
              (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,pcVar1,iVar2);
  }
  sVar3 = (short)param_2;
  iVar4 = sVar3 + -1;
  *(short *)(param_1 + 0x4b8) = sVar3;
  if (sVar3 != 0) {
    TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x5b4),iVar4);
    (**(code **)(rge_base_game->_padding_ + 0x14))(param_2);
    if ((char)param_3 == '\x01') {
      iVar2 = T_Scenario::Get_player_Food(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4);
      sprintf(&stack0xffffffdc,&s__d,iVar2);
      TEditPanel::set_text(*(TEditPanel **)(param_1 + 0x5d8),&stack0xffffffdc);
      iVar2 = T_Scenario::Get_player_Wood(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4);
      sprintf(&stack0xffffffdc,&s__d,iVar2);
      TEditPanel::set_text(*(TEditPanel **)(param_1 + 0x5dc),&stack0xffffffdc);
      iVar2 = T_Scenario::Get_player_Stone(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4)
      ;
      sprintf(&stack0xffffffdc,&s__d,iVar2);
      TEditPanel::set_text(*(TEditPanel **)(param_1 + 0x5e0),&stack0xffffffdc);
      iVar2 = T_Scenario::Get_player_Gold(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4);
      sprintf(&stack0xffffffdc,&s__d,iVar2);
      TEditPanel::set_text(*(TEditPanel **)(param_1 + 0x5e4),&stack0xffffffdc);
      pcVar1 = RGE_Scenario::GetPlayerName
                         (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4);
      TEditPanel::set_text(*(TEditPanel **)(param_1 + 0x5e8),pcVar1);
      iVar2 = RGE_Scenario::Get_player_Type
                        (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4);
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(param_1 + 0x5f8),iVar2);
      iVar2 = RGE_Scenario::Get_player_Civ
                        (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4);
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(param_1 + 0x5fc),iVar2 + -1);
      pcVar1 = RGE_Scenario::Get_player_AI
                         (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
      iVar2 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x608),pcVar1);
      if (iVar2 == -1) {
        lVar5 = 0;
        pcVar1 = RGE_Scenario::Get_player_AI
                           (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
        TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x608),pcVar1,lVar5);
        pcVar1 = RGE_Scenario::Get_player_AI
                           (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
        iVar2 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x608),pcVar1);
      }
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(param_1 + 0x608),iVar2);
      pcVar1 = RGE_Scenario::Get_BuildList
                         (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
      iVar2 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x600),pcVar1);
      if (iVar2 == -1) {
        lVar5 = 0;
        pcVar1 = RGE_Scenario::Get_BuildList
                           (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
        TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x600),pcVar1,lVar5);
        pcVar1 = RGE_Scenario::Get_BuildList
                           (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
        iVar2 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x600),pcVar1);
      }
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(param_1 + 0x600),iVar2);
      pcVar1 = RGE_Scenario::Get_CityPlan
                         (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
      iVar2 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x604),pcVar1);
      if (iVar2 == -1) {
        lVar5 = 0;
        pcVar1 = RGE_Scenario::Get_CityPlan
                           (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
        TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x604),pcVar1,lVar5);
        pcVar1 = RGE_Scenario::Get_CityPlan
                           (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4,0);
        iVar2 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x604),pcVar1);
      }
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(param_1 + 0x604),iVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ab2aa
// Address: 004ab2aa
// XREFS: None
void __thiscall FUN_004ab2aa(int param_1,short param_2,int param_3)
{
  RGE_Scenario::Set_player_Active
            (*(RGE_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),(int)param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004ab2cc
// Address: 004ab2cc
// XREFS: None
uint FUN_004ab2cc(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = CompareStringA(0x400,1,param_1,0xffffffff,param_2,0xffffffff);
  if (iVar1 == 1) {
    return 0xffffffff;
  }
  return (uint)(iVar1 == 3);
}

// --------------------------------------------------

// Function: TRIBE_Screen_Sed_unit_list_compare
// Address: 004ab2d0
// XREFS: set_unit_player
/* int __cdecl TRIBE_Screen_Sed_unit_list_compare(void const *,void const *) */

int __cdecl TRIBE_Screen_Sed_unit_list_compare(void *param_1,void *param_2)
{
  int iVar1;
  
  iVar1 = CompareStringA(0x400,1,param_1,0xffffffff,param_2,0xffffffff);
  if (iVar1 == 1) {
    return -1;
  }
  return (uint)(iVar1 == 3);
}

// --------------------------------------------------

// Function: FUN_004ab2ff
// Address: 004ab2ff
// XREFS: None
void __thiscall FUN_004ab2ff(TRIBE_Screen_Sed *param_1,undefined4 param_2)
{
  char cVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  RGE_Player *pRVar6;
  List_Info *pLVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  short unaff_BX;
  short sVar13;
  char *pcVar14;
  undefined4 *puVar15;
  short sVar16;
  char *pcVar17;
  List_Info *pLVar18;
  short sVar19;
  float fStack_c;
  
  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
  fVar3 = pRVar6->view_x;
  sVar16 = pRVar6->map_x;
  fStack_c = (float)CONCAT22(fStack_c._2_2_,pRVar6->map_y);
  (**(code **)(rge_base_game->_padding_ + 0x14))(param_2);
  param_1->player_num = (short)param_2;
  pRVar6 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::set_view_loc(pRVar6,fStack_c,fVar3);
  RGE_Player::set_map_loc(pRVar6,sVar16,unaff_BX);
  RGE_View::set_player((RGE_View *)param_1->main_view,pRVar6);
  RGE_Diamond_Map::set_player((RGE_Diamond_Map *)param_1->map_view,pRVar6);
  TDropDownPanel::setCurrentLineNumber(param_1->unit_player_list,(int)(short)param_2);
  TTextPanel::empty_list((TTextPanel *)param_1->unit_list);
  if (param_1->unit_list_info != (List_Info *)0x0) {
    free(param_1->unit_list_info);
    param_1->unit_list_info = (List_Info *)0x0;
  }
  if (pRVar6 != (RGE_Player *)0x0) {
    param_1->unit_list_size = 1;
    sVar16 = pRVar6->master_object_num;
    if (0 < sVar16) {
      iVar9 = 0;
      iVar12 = (int)sVar16;
      do {
        iVar4 = *(int *)(iVar9 + (int)pRVar6->master_objects);
        if ((iVar4 != 0) && (*(char *)(iVar4 + 0x4e) == '\0')) {
          param_1->unit_list_size = param_1->unit_list_size + 1;
        }
        iVar9 = iVar9 + 4;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    if (param_1->unit_list_size != 0) {
      pLVar7 = (List_Info *)calloc((int)param_1->unit_list_size,0x66);
      param_1->unit_list_info = pLVar7;
      if (pLVar7 != (List_Info *)0x0) {
        pLVar7->id = -1;
        TRIBE_Screen_Sed::set_string(param_1,param_1->unit_list_info->text,0x2775,0x14);
        sVar19 = 1;
        sVar13 = 0;
        if (0 < sVar16) {
          fStack_c = 0.0;
          do {
            iVar9 = *(int *)((int)fStack_c + (int)pRVar6->master_objects);
            if ((iVar9 != 0) && (*(char *)(iVar9 + 0x4e) == '\0')) {
              param_1->unit_list_info[sVar19].id = sVar13;
              iVar9 = *(int *)((int)fStack_c + (int)pRVar6->master_objects);
              sVar2 = *(short *)(iVar9 + 0xc);
              if (sVar2 < 1) {
                uVar10 = 0xffffffff;
                pcVar14 = *(char **)(iVar9 + 8);
                do {
                  pcVar17 = pcVar14;
                  if (uVar10 == 0) break;
                  uVar10 = uVar10 - 1;
                  pcVar17 = pcVar14 + 1;
                  cVar1 = *pcVar14;
                  pcVar14 = pcVar17;
                } while (cVar1 != '\0');
                uVar10 = ~uVar10;
                pcVar14 = pcVar17 + -uVar10;
                pLVar7 = param_1->unit_list_info + sVar19;
                for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *(undefined4 *)pLVar7->text = *(undefined4 *)pcVar14;
                  pcVar14 = pcVar14 + 4;
                  pLVar7 = (List_Info *)(pLVar7->text + 4);
                }
                for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                  pLVar7->text[0] = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  pLVar7 = (List_Info *)(pLVar7->text + 1);
                }
              }
              else {
                (**(code **)(rge_base_game->_padding_ + 0x20))
                          ((int)sVar2,param_1->unit_list_info + sVar19,100);
              }
              sVar19 = sVar19 + 1;
            }
            sVar13 = sVar13 + 1;
            fStack_c = (float)((int)fStack_c + 4);
          } while (sVar13 < sVar16);
        }
        qsort(param_1->unit_list_info,(int)param_1->unit_list_size,0x66,
              TRIBE_Screen_Sed_unit_list_compare);
        iVar9 = calloc((int)param_1->unit_list_size,4);
        if (iVar9 != 0) {
          bVar5 = false;
          sVar16 = 0;
          sVar19 = 0;
          if (0 < param_1->unit_list_size) {
            do {
              puVar8 = (undefined4 *)calloc(100,1);
              iVar12 = (int)sVar19;
              *(undefined4 **)(iVar9 + iVar12 * 4) = puVar8;
              if (puVar8 == (undefined4 *)0x0) {
                bVar5 = true;
                break;
              }
              uVar10 = 0xffffffff;
              pLVar7 = param_1->unit_list_info + iVar12;
              do {
                pLVar18 = pLVar7;
                if (uVar10 == 0) break;
                uVar10 = uVar10 - 1;
                pLVar18 = (List_Info *)(pLVar7->text + 1);
                pcVar14 = pLVar7->text;
                pLVar7 = pLVar18;
              } while (*pcVar14 != '\0');
              uVar10 = ~uVar10;
              puVar15 = (undefined4 *)((int)pLVar18 - uVar10);
              for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar8 = *puVar15;
                puVar15 = puVar15 + 1;
                puVar8 = puVar8 + 1;
              }
              for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined1 *)puVar8 = *(undefined1 *)puVar15;
                puVar15 = (undefined4 *)((int)puVar15 + 1);
                puVar8 = (undefined4 *)((int)puVar8 + 1);
              }
              if (param_1->unit_list_info[iVar12].id == rge_base_game->master_obj_id) {
                sVar16 = sVar19;
              }
              sVar19 = sVar19 + 1;
            } while (sVar19 < param_1->unit_list_size);
          }
          if (!bVar5) {
            (**(code **)(param_1->unit_list->_padding_ + 0xe0))(iVar9,param_1->unit_list_size);
            TListPanel::scroll_cur_line(param_1->unit_list,'\x01',sVar16,1);
          }
          sVar16 = 0;
          if (0 < param_1->unit_list_size) {
            do {
              iVar12 = *(int *)(iVar9 + sVar16 * 4);
              if (iVar12 != 0) {
                free(iVar12);
              }
              sVar16 = sVar16 + 1;
            } while (sVar16 < param_1->unit_list_size);
          }
          free(iVar9);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ab66f
// Address: 004ab66f
// XREFS: None
void __thiscall FUN_004ab66f(int param_1,short param_2)
{
  if (param_2 == -1) {
    rge_base_game->master_obj_id = -1;
    TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x63c),'\x01',-1,1);
    return;
  }
  rge_base_game->master_obj_id = *(short *)(*(int *)(param_1 + 0x644) + 100 + param_2 * 0x66);
  TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x63c),'\x01',param_2,1);
  return;
}

// --------------------------------------------------

// Function: FUN_004ab6d6
// Address: 004ab6d6
// XREFS: None
void __thiscall FUN_004ab6d6(int param_1,undefined4 param_2,undefined4 param_3)
{
  (**(code **)(**(int **)(param_1 + 0x774) + 0x14))(param_3);
  (**(code **)(**(int **)(param_1 + 0x4d4) + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_004ab704
// Address: 004ab704
// XREFS: None
undefined4 __thiscall FUN_004ab704(TRIBE_Screen_Sed *param_1,long param_2,long param_3)
{
  TPanel::handle_size((TPanel *)param_1,param_2,param_3);
  TRIBE_Screen_Sed::position_panels(param_1);
  TPanel::handle_size((TPanel *)param_1,param_2,param_3);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ab73c
// Address: 004ab73c
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_sed_cp: "C:\msdev\work\age1_x1\scr_sed.cpp"
void __fastcall FUN_004ab73c(TPanel *param_1)
{
  ulong uVar1;
  TPanel *pTVar2;
  
  if (rge_base_game->prog_mode == 7) {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp,0x8b1);
    if ((uint)param_1[9].render_rect.bottom <= param_1[9].left_border - uVar1) {
      pTVar2 = TPanelSystem::modalPanel(&panel_system);
      if (pTVar2 == (TPanel *)0x0) {
        (**(code **)((param_1[5].previousPanelValue)->_padding_ + 0x20))(1);
        if ((uint)param_1[9].top_border <= param_1[9].right_border - uVar1) {
          (**(code **)((param_1[5].previousModalPanelValue)->_padding_ + 0x20))(1);
          param_1[9].right_border = uVar1;
        }
      }
    }
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004ab7c2
// Address: 004ab7c2
// XREFS: None
undefined4 __thiscall
FUN_004ab7c2(TRIBE_Screen_Sed *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5
            )
{
  ScenarioMode SVar1;
  RGE_Static_Object *pRVar2;
  uchar uVar3;
  TPanel *pTVar4;
  int iVar5;
  RGE_Player *pRVar6;
  short sVar7;
  
  pTVar4 = TPanelSystem::modalPanel(&panel_system);
  if (pTVar4 == (TPanel *)0x0) {
    if (param_5 != 0) {
      switch(param_2) {
      case 0x41:
        if (rge_base_game->outline_type != '\x03') {
          rge_base_game->outline_type = '\x03';
          return 1;
        }
        rge_base_game->outline_type = '\0';
        return 1;
      case 0x42:
        goto switchD_004ab80d_caseD_42;
      case 0x43:
        (**(code **)(param_1->scenario_mode_button[9]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeCinematics);
        return 0;
      case 0x44:
        (**(code **)(param_1->scenario_mode_button[4]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeDiplomacy);
        return 0;
      default:
        goto switchD_004ab80d_caseD_45;
      case 0x49:
        (**(code **)(param_1->scenario_mode_button[5]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeVictory);
        return 0;
      case 0x4d:
        (**(code **)(param_1->scenario_mode_button[0]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeMap);
        return 0;
      case 0x4f:
        (**(code **)(param_1->scenario_mode_button[7]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeOptions);
        return 0;
      case 0x50:
        (**(code **)(param_1->scenario_mode_button[2]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModePlayers);
        return 0;
      case 0x54:
        (**(code **)(param_1->scenario_mode_button[1]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeTerrain);
        return 0;
      case 0x55:
        (**(code **)(param_1->scenario_mode_button[3]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeUnits);
        return 0;
      case 0x56:
        (**(code **)(param_1->scenario_mode_button[6]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeVictoryMulti);
        return 0;
      case 0x57:
        (**(code **)(param_1->scenario_mode_button[8]->_padding_ + 0xe0))(1);
        TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeMessages);
        return 0;
      }
    }
    switch(param_2) {
    case 9:
      if (param_1->scenario_mode == ScenarioModePlayers) {
        if (param_1->bottom_panel->curr_child == (TPanel *)0x0) {
          TPanel::set_curr_child(param_1->bottom_panel,(TPanel *)param_1->player_inven_input[0]);
          return 0;
        }
      }
      else if (((param_1->scenario_mode == ScenarioModeVictory) &&
               (param_1->bottom_panel->curr_child == (TPanel *)0x0)) &&
              (param_1->victory_amount_input->_padding_ != 0)) {
        TPanel::set_curr_child(param_1->bottom_panel,(TPanel *)param_1->victory_amount_input);
        return 0;
      }
      break;
    case 0x1b:
      TRIBE_Screen_Sed::command_cancel(param_1);
      return 0;
    case 0x2e:
      if (param_1->scenario_mode == ScenarioModeUnits) {
        pRVar6 = RGE_Base_Game::get_player(rge_base_game);
        pRVar2 = pRVar6->selected_obj;
        if (pRVar2 != (RGE_Static_Object *)0x0) {
          if (pRVar2->sprite_list == (RGE_Active_Sprite_List *)0x0) {
            if (pRVar2->sprite == (RGE_Sprite *)0x0) {
              uVar3 = '\x14';
            }
            else {
              uVar3 = RGE_Sprite::get_lowest_draw_level(pRVar2->sprite);
            }
          }
          else {
            uVar3 = RGE_Active_Sprite_List::get_lowest_draw_level(pRVar2->sprite_list);
          }
          (**(code **)pRVar2->_padding_)(1);
          if (uVar3 == '\0') {
            (**(code **)(*(int *)param_1->main_view + 0x20))(2);
          }
        }
        return 1;
      }
      break;
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
      SVar1 = param_1->scenario_mode;
      iVar5 = param_2 + -0x30;
      sVar7 = (short)iVar5;
      if ((SVar1 == ScenarioModeOptions) && (0 < iVar5)) {
        TRIBE_Screen_Sed::SaveDisabledItemsInScenario(param_1);
        TDropDownPanel::setCurrentLineNumber(param_1->options_player_list,param_2 + -0x31);
        (**(code **)(param_1->_padding_ + 0xb4))(param_1->options_player_list,3,0,0);
        TRIBE_Screen_Sed::set_player(param_1,sVar7,'\0','\0');
        param_1->player_num = sVar7;
        TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(param_1);
        return 0;
      }
      if ((SVar1 == ScenarioModePlayers) && (0 < iVar5)) {
        if (param_1->bottom_panel->curr_child == (TPanel *)0x0) {
          TDropDownPanel::setCurrentLineNumber(param_1->player_list,param_2 + -0x31);
          (**(code **)(param_1->_padding_ + 0xb4))(param_1->player_list,0,0,0);
          return 0;
        }
      }
      else {
        if (SVar1 == ScenarioModeUnits) {
          TDropDownPanel::setCurrentLineNumber(param_1->unit_player_list,iVar5);
          (**(code **)(param_1->_padding_ + 0xb4))(param_1->unit_player_list,0,0,0);
          return 0;
        }
        if ((SVar1 == ScenarioModeVictory) && (0 < iVar5)) {
          if (param_1->bottom_panel->curr_child == (TPanel *)0x0) {
            TDropDownPanel::setCurrentLineNumber(param_1->victory_player_list,param_2 + -0x31);
            (**(code **)(param_1->_padding_ + 0xb4))(param_1->victory_player_list,1,0,0);
            return 0;
          }
        }
        else if (SVar1 == ScenarioModeDiplomacy) {
          if (0 < iVar5) {
            TDropDownPanel::setCurrentLineNumber(param_1->Diplomacy_player_list,param_2 + -0x31);
            (**(code **)(param_1->_padding_ + 0xb4))(param_1->Diplomacy_player_list,1,0,0);
            return 0;
          }
        }
        else if (0 < iVar5) {
          TRIBE_Screen_Sed::set_player(param_1,sVar7,'\0','\0');
          param_1->player_num = sVar7;
          return 0;
        }
      }
    }
  }
switchD_004ab80d_caseD_45:
  return 0;
switchD_004ab80d_caseD_42:
  View_Grid_Mode = View_Grid_Mode + 1;
  iVar5 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
  if (iVar5 == 0) {
    if (View_Grid_Mode < 2) goto LAB_004ab9ba;
  }
  else if (View_Grid_Mode < 5) goto LAB_004ab9ba;
  View_Grid_Mode = 0;
LAB_004ab9ba:
  (**(code **)(*(int *)param_1->main_view + 0x20))(2);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004abc31
// Address: 004abc31
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_sed_cp: "C:\msdev\work\age1_x1\scr_sed.cpp"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004abc31(void)
{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  TEditPanel *pTVar6;
  TRIBE_World *pTVar7;
  RGE_Scenario *pRVar8;
  TDropDownPanel *pTVar9;
  TPanel *pTVar10;
  TRIBE_Main_View *pTVar11;
  TTextPanel *pTVar12;
  MapType MVar13;
  undefined4 *puVar14;
  RGE_Map *pRVar15;
  TRIBE_Scenario_Editor_Panel_Object *pTVar16;
  TButtonPanel *pTVar17;
  code *pcVar18;
  TRIBE_Main_View *pTVar19;
  T_Scenario *pTVar20;
  float fVar21;
  RGE_Base_Game *pRVar22;
  char in_AL;
  byte bVar23;
  short sVar24;
  int iVar25;
  undefined4 uVar26;
  RGE_Player *pRVar27;
  int iVar28;
  char *pcVar29;
  byte *pbVar30;
  long lVar31;
  int extraout_EAX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar33;
  TButtonPanel **ppTVar32;
  TRIBE_Screen_Sed_Open *this;
  TRIBE_Screen_Sed *this_00;
  TEditPanel **ppTVar34;
  undefined2 extraout_var_01;
  char *unaff_EBX;
  undefined1 *puVar35;
  undefined4 *puVar36;
  undefined4 *puVar37;
  undefined4 *puVar38;
  undefined4 *puVar39;
  undefined1 *puVar40;
  undefined1 *puVar41;
  undefined1 *puVar42;
  undefined1 *puVar43;
  undefined4 *puVar44;
  undefined4 *puVar45;
  undefined1 *puVar46;
  undefined4 *puVar47;
  undefined4 *puVar48;
  undefined4 *puVar49;
  undefined4 *puVar50;
  undefined4 *puVar51;
  undefined1 *puVar52;
  undefined1 *puVar53;
  undefined1 *puVar54;
  undefined1 *puVar55;
  undefined1 *puVar56;
  undefined1 *puVar57;
  undefined1 *puVar58;
  undefined4 unaff_EBP;
  int unaff_ESI;
  RGE_Static_Object *pRVar59;
  int unaff_EDI;
  byte *pbVar60;
  undefined4 *unaff_FS_OFFSET;
  char in_CF;
  bool bVar61;
  
  *(char *)(unaff_EDI + 0x66004ab9) = *(char *)(unaff_EDI + 0x66004ab9) + in_AL + -0x48 + in_CF;
  puVar1 = (undefined1 *)(unaff_EDI * 4 + -0x473effb6);
  *puVar1 = *puVar1;
  *(char *)(unaff_EDI + -0x48) = *(char *)(unaff_EDI + -0x48) + (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_ESI + -0x48) = *(char *)(unaff_ESI + -0x48) + (char)unaff_EBX;
  iVar25 = (CONCAT31(0xb83d00,(*unaff_EBX + 0x4aU | 0xc) + 0xc) | 0xc) + 0xc07060c;
  bVar5 = (byte)iVar25;
  bVar23 = bVar5 | 0xc;
  bRamb945004a = bRamb945004a | 0x4a;
  this_00 = (TRIBE_Screen_Sed *)CONCAT22(0xb945,CONCAT11(bVar5,*unaff_EBX) | 0xc4a);
  pcRam01000046 = unaff_EBX;
  *(byte *)&this_00->_padding_ = (char)this_00->_padding_ + bVar23;
  iVar25 = CONCAT31((int3)((uint)iVar25 >> 8),bVar23 + 0x20);
  piVar2 = (int *)(iVar25 + 0x400004a);
  *piVar2 = *piVar2 + iVar25;
  uRam0400003e = *unaff_FS_OFFSET;
  uRam04000046 = 0xffffffff;
  pcRam04000042 = FUN_0055f48b;
  *unaff_FS_OFFSET = 0x400003e;
  pTVar11 = pTRam0400004e;
  uRam04000012 = 0xb9ee004a;
  puVar35 = (undefined1 *)0x4000006;
  iRam04000006 = unaff_EDI;
  iRam0400000a = unaff_ESI;
  uRam0400000e = unaff_EBP;
  if (pTRam0400004e == (TRIBE_Main_View *)0x0) {
    uVar26 = 0;
    goto LAB_004abe5f;
  }
  if (pTRam0400004e != this_00->main_view) {
    if (this_00->SelectedObject != (RGE_Static_Object *)0x0) {
      iRam04000002 = 0;
      uRam03fffffa = 0x4abd1d;
      pRRam03fffffe = this_00->SelectedObject;
      pRVar27 = RGE_Base_Game::get_player(rge_base_game);
      uRam03fffffa = 0x4abd24;
      RGE_Player::select_one_object(pRVar27,pRRam03fffffe,iRam04000002);
    }
    if (this_00->DestinationObject != (RGE_Static_Object *)0x0) {
      iRam04000002 = 0;
      uRam03fffffa = 0x4abd3c;
      pRRam03fffffe = this_00->DestinationObject;
      pRVar27 = RGE_Base_Game::get_player(rge_base_game);
      uRam03fffffa = 0x4abd43;
      RGE_Player::select_one_object(pRVar27,pRRam03fffffe,iRam04000002);
    }
  }
  iVar25 = iRam04000052;
  puVar35 = (undefined1 *)0x4000006;
  if ((iRam04000052 == 0) &&
     (((((((pTVar11 == (TRIBE_Main_View *)this_00->random_seed_input ||
           (pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[0])) ||
          (pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[1])) ||
         ((pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[2] ||
          (pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[3])))) ||
        (pTVar11 == (TRIBE_Main_View *)this_00->player_inven_input[4])) ||
       (((pTVar11 == (TRIBE_Main_View *)this_00->player_setting_label[0] ||
         (pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_explore)) ||
        ((pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_ruins ||
         (((pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_artifacts ||
           (pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_discoveries)) ||
          (pTVar11 == (TRIBE_Main_View *)this_00->victory_condition_gold)))))))) ||
      ((pTVar11 == (TRIBE_Main_View *)this_00->victory_amount_input ||
       (pTVar11 == (TRIBE_Main_View *)this_00->message_input)))))) {
    this_00->need_to_save_flag = '\x01';
  }
  if (pTVar11 == this_00->main_view) {
    if (iVar25 != 0x10) {
      if ((iVar25 == 0x11) && (rge_base_game->game_mode == 0x11)) {
        iRam04000002 = 0;
        pRRam03fffffe = (RGE_Static_Object *)0x0;
        puVar35 = (undefined1 *)0x3fffffa;
        uRam03fffffa = 0x4abe90;
        (**(code **)(rge_base_game->_padding_ + 0x10))();
      }
      goto LAB_004abe90;
    }
    iRam04000002 = 0x4abde2;
    pRVar27 = RGE_Base_Game::get_player(rge_base_game);
    iRam04000002 = 0x4abde9;
    RGE_Player::unselect_object(pRVar27);
    pRVar59 = pRRam04000056;
    if (this_00->SelectRegionFlag == SELECT_OBJECT) {
      this_00->SelectedObject = pRRam04000056;
    }
    if (this_00->SelectRegionFlag == SELECT_DEST_OBJECT) {
      this_00->DestinationObject = pRVar59;
    }
    pRRam03fffffe = this_00->SelectedObject;
    if (pRRam03fffffe != (RGE_Static_Object *)0x0) {
      iRam04000002 = 0;
      uRam03fffffa = 0x4abe25;
      pRVar27 = RGE_Base_Game::get_player(rge_base_game);
      uRam03fffffa = 0x4abe2c;
      RGE_Player::select_one_object(pRVar27,pRRam03fffffe,iRam04000002);
    }
    pRRam03fffffe = this_00->DestinationObject;
    if (pRRam03fffffe != (RGE_Static_Object *)0x0) {
      iRam04000002 = 0;
      uRam03fffffa = 0x4abe44;
      pRVar27 = RGE_Base_Game::get_player(rge_base_game);
      uRam03fffffa = 0x4abe4b;
      RGE_Player::select_one_object(pRVar27,pRRam03fffffe,iRam04000002);
    }
    iRam04000002 = 0;
    pRRam03fffffe = (RGE_Static_Object *)0x0;
    puVar35 = (undefined1 *)0x3fffffa;
    uRam03fffffa = 0x4abe5a;
    (**(code **)(rge_base_game->_padding_ + 0x10))();
  }
  else {
LAB_004abe90:
    if (iVar25 == 1) {
      iVar28 = 0;
      ppTVar32 = this_00->scenario_mode_button;
      do {
        if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
          *(int *)(puVar35 + -4) = iVar28 + 1;
          *(undefined4 *)(puVar35 + -8) = 0x4ad069;
          TRIBE_Screen_Sed::set_scenario_mode(this_00,*(ScenarioMode *)(puVar35 + -4));
          goto LAB_004abe5a;
        }
        iVar28 = iVar28 + 1;
        ppTVar32 = ppTVar32 + 1;
      } while (iVar28 < 10);
      if (pTVar11 == (TRIBE_Main_View *)this_00->menu_button) {
        *(undefined4 *)(puVar35 + -4) = 0x4abebd;
        TRIBE_Screen_Sed::command_menu(this_00);
      }
      else {
        if (pTVar11 != (TRIBE_Main_View *)this_00->help_button) goto LAB_004abf01;
        *(undefined4 *)(puVar35 + -4) = 0x4abece;
        TEasy_Panel::setup_popup_help((TEasy_Panel *)this_00);
      }
    }
    else {
      iVar28 = 0;
      ppTVar32 = this_00->scenario_mode_button;
      do {
        if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) goto LAB_004abe5a;
        iVar28 = iVar28 + 1;
        ppTVar32 = ppTVar32 + 1;
      } while (iVar28 < 10);
      if ((pTVar11 != (TRIBE_Main_View *)this_00->menu_button) &&
         (pTVar11 != (TRIBE_Main_View *)this_00->help_button)) {
LAB_004abf01:
        *(undefined4 *)(puVar35 + -4) = 0x4abf08;
        pcVar29 = TPanel::panelName((TPanel *)pTVar11);
        if (pcVar29 != (char *)0x0) {
          pbVar60 = &s_OKDialog;
          *(undefined4 *)(puVar35 + -4) = 0x4abf18;
          pbVar30 = (byte *)TPanel::panelName((TPanel *)pTVar11);
          do {
            bVar5 = *pbVar30;
            bVar61 = bVar5 < *pbVar60;
            if (bVar5 != *pbVar60) {
LAB_004abf3c:
              iVar28 = (1 - (uint)bVar61) - (uint)(bVar61 != 0);
              goto LAB_004abf41;
            }
            if (bVar5 == 0) break;
            bVar5 = pbVar30[1];
            bVar61 = bVar5 < pbVar60[1];
            if (bVar5 != pbVar60[1]) goto LAB_004abf3c;
            pbVar30 = pbVar30 + 2;
            pbVar60 = pbVar60 + 2;
          } while (bVar5 != 0);
          iVar28 = 0;
LAB_004abf41:
          if (iVar28 == 0) {
            if (iVar25 == 0) {
              *(undefined1 **)(puVar35 + -4) = &s_OKDialog;
              *(undefined4 *)(puVar35 + -8) = 0x4abf5c;
              TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
              *(undefined4 *)(puVar35 + -4) = 3;
              *(undefined4 *)(puVar35 + -8) = 0x4abf65;
              TRIBE_Screen_Sed::set_scenario_mode(this_00,*(ScenarioMode *)(puVar35 + -4));
            }
            goto LAB_004abe5a;
          }
        }
        switch(this_00->scenario_mode) {
        case ScenarioModeMap:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 1) {
            iVar28 = 0;
            ppTVar32 = this_00->map_type_button;
            do {
              if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                *(undefined4 *)(puVar35 + -4) = 1;
                *(int *)(puVar35 + -8) = iVar28 + 1;
                *(undefined4 *)(puVar35 + -0xc) = 0x4ac4f8;
                TRIBE_Screen_Sed::set_map_type
                          (this_00,*(MapType *)(puVar35 + -8),*(int *)(puVar35 + -4));
                goto LAB_004abe5a;
              }
              iVar28 = iVar28 + 1;
              ppTVar32 = ppTVar32 + 1;
            } while (iVar28 < 3);
            if (pTVar11 == (TRIBE_Main_View *)this_00->generate_map_button) {
              pTVar12 = this_00->map_generating_text;
              *(undefined4 *)(puVar35 + -4) = 1;
              pcVar18 = *(code **)(pTVar12->_padding_ + 0x14);
              puVar40 = puVar35 + -8;
              *(undefined4 *)(puVar35 + -8) = 0x4ac516;
              (*pcVar18)();
              iVar25 = this_00->_padding_;
              *(undefined4 *)(puVar40 + -4) = 2;
              pcVar18 = *(code **)(iVar25 + 0x20);
              puVar41 = puVar40 + -8;
              *(undefined4 *)(puVar40 + -8) = 0x4ac51f;
              (*pcVar18)();
              pRVar22 = rge_base_game;
              *(undefined4 *)(puVar41 + -4) = 0;
              *(undefined4 *)(puVar41 + -8) = 0;
              *(void **)(puVar41 + -0xc) = pRVar22->prog_window;
              puVar42 = puVar41 + -0x10;
              *(undefined4 *)(puVar41 + -0x10) = 0x4ac533;
              InvalidateRect();
              pRVar22 = rge_base_game;
              *(undefined4 *)(puVar42 + -4) = 0x4ac53e;
              RGE_Base_Game::draw_window(pRVar22);
              pTVar9 = this_00->map_size_drop;
              *(undefined4 *)(puVar42 + -4) = 0x4ac549;
              iVar25 = TDropDownPanel::currentLineNumber(pTVar9);
              pTVar9 = this_00->map_style_drop;
              *(undefined4 *)(puVar42 + -4) = 0x4ac556;
              iVar28 = TDropDownPanel::currentLineNumber(pTVar9);
              *(int *)(puVar42 + 0x4c) = iVar28;
              switch(iVar25) {
              case 0:
                iVar25 = 0x48;
                break;
              case 1:
                iVar25 = 0x60;
                break;
              case 2:
                iVar25 = 0x78;
                break;
              case 3:
                iVar25 = 0x90;
                break;
              case 4:
                iVar25 = 200;
                break;
              case 5:
                iVar25 = 0xfa;
                break;
              default:
                iVar25 = *(int *)(puVar42 + 0x4c);
              }
              pTVar9 = this_00->player_number_list;
              *(undefined4 *)(puVar42 + -4) = 0x4ac59f;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              pRVar22 = rge_base_game;
              MVar13 = this_00->map_type;
              if (MVar13 == MapTypeBlank) {
                pTVar9 = this_00->default_terrain_drop;
                *(undefined4 *)(puVar42 + -4) = 0x4ac5bc;
                iVar28 = TDropDownPanel::currentLineNumber(pTVar9);
                switch(iVar28) {
                case 0:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac5e5;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 1:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 6;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac603;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 2:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 10;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac621;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 3:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 1;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac63f;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 4:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0xd;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac65d;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 5:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0x14;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac67b;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 6:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 4;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac699;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 7:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0x13;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac6b7;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                  break;
                case 8:
                  pTVar7 = this_00->world;
                  *(int *)(puVar42 + -4) = iVar25;
                  *(int *)(puVar42 + -8) = iVar25;
                  *(undefined4 *)(puVar42 + -0xc) = 0x16;
                  puVar14 = (undefined4 *)pTVar7->_padding_;
                  *(TRIBE_World **)(puVar42 + -0x10) = pTVar7;
                  pRVar15 = (RGE_Map *)pTVar7->_padding_;
                  *(undefined4 *)(puVar42 + -0x14) = *puVar14;
                  *(undefined4 *)(puVar42 + -0x18) = 0x4ac6d5;
                  RGE_Map::clear_map(pRVar15,*(RGE_Player **)(puVar42 + -0x14),
                                     *(RGE_Game_World **)(puVar42 + -0x10),puVar42[-0xc],
                                     *(long *)(puVar42 + -8),*(long *)(puVar42 + -4));
                }
              }
              else {
                *(int *)(puVar42 + 0x48) = rge_base_game->random_map_seed;
                if (MVar13 == MapTypeSeed) {
                  pTVar6 = this_00->random_seed_input;
                  *(undefined4 *)(puVar42 + -4) = 0x4ac6f7;
                  pcVar29 = TEditPanel::currentLine(pTVar6);
                  *(char **)(puVar42 + -4) = pcVar29;
                  *(undefined4 *)(puVar42 + -8) = 0x4ac6fd;
                  iVar28 = atoi();
                  rge_base_game->random_map_seed = iVar28;
                }
                else {
                  pRVar22->random_map_seed = -1;
                }
                iVar28 = 0;
                do {
                  pRVar27 = *(RGE_Player **)(this_00->world->_padding_ + iVar28);
                  *(undefined4 *)(puVar42 + -4) = 0x4ac725;
                  RGE_Player::reset_selected(pRVar27);
                  iVar28 = iVar28 + 4;
                } while (iVar28 < 0x24);
                pTVar7 = this_00->world;
                *(long *)(puVar42 + -4) = lVar31 + 1;
                piVar2 = (int *)pTVar7->_padding_;
                *(undefined4 *)(puVar42 + -8) = *(undefined4 *)(puVar42 + 0x4c);
                *(int *)(puVar42 + -0xc) = iVar25;
                *(int *)(puVar42 + -0x10) = iVar25;
                iVar28 = *piVar2;
                *(TRIBE_World **)(puVar42 + -0x14) = pTVar7;
                pcVar18 = *(code **)(iVar28 + 0x28);
                puVar43 = puVar42 + -0x18;
                *(undefined4 *)(puVar42 + -0x18) = 0x4ac744;
                (*pcVar18)();
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar43 + -4) = 10;
                pRVar22->random_map_seed = *(int *)(puVar43 + 0x48);
                pRVar22 = rge_base_game;
                *(undefined1 **)(puVar43 + -8) = puVar43 + 0x20;
                *(int *)(puVar43 + -0xc) = pRVar22->save_random_map_seed;
                *(undefined4 *)(puVar43 + -0x10) = 0x4ac765;
                itoa();
                iVar28 = this_00->random_seed_used_text->_padding_;
                *(undefined1 **)(puVar43 + -4) = puVar43 + 0x20;
                pcVar18 = *(code **)(iVar28 + 0xe8);
                puVar42 = puVar43 + -8;
                *(undefined4 *)(puVar43 + -8) = 0x4ac77b;
                (*pcVar18)();
                *(undefined4 *)(puVar42 + -4) = 0xb58;
                *(char **)(puVar42 + -8) = s_C__msdev_work_age1_x1_scr_sed_cp;
                *(undefined4 *)(puVar42 + -0xc) = 0x4ac78a;
                debug_rand(*(char **)(puVar42 + -8),*(int *)(puVar42 + -4));
              }
              iVar25 = iVar25 / 2;
              *(int *)(puVar42 + 0x4c) = iVar25;
              iVar28 = 0;
              *(float *)(puVar42 + 0x4c) = (float)*(int *)(puVar42 + 0x4c);
              uVar26 = *(undefined4 *)(puVar42 + 0x4c);
              do {
                pTVar7 = this_00->world;
                *(int *)(puVar42 + -4) = iVar25;
                *(int *)(puVar42 + -8) = iVar25;
                pRVar27 = *(RGE_Player **)(pTVar7->_padding_ + iVar28);
                *(undefined4 *)(puVar42 + -0xc) = 0x4ac7bb;
                RGE_Player::set_map_loc(pRVar27,*(short *)(puVar42 + -8),*(short *)(puVar42 + -4));
                pTVar7 = this_00->world;
                *(undefined4 *)(puVar42 + -4) = uVar26;
                *(undefined4 *)(puVar42 + -8) = uVar26;
                pRVar27 = *(RGE_Player **)(pTVar7->_padding_ + iVar28);
                *(undefined4 *)(puVar42 + -0xc) = 0x4ac7ce;
                RGE_Player::set_view_loc(pRVar27,*(float *)(puVar42 + -8),*(float *)(puVar42 + -4));
                iVar28 = iVar28 + 4;
              } while (iVar28 < 0x20);
              iVar25 = 0;
              do {
                iVar28 = *(int *)(this_00->world->_padding_ + iVar25);
                *(undefined4 *)(puVar42 + -4) = 0x4ac7ec;
                RGE_Tile_List::del_list((RGE_Tile_List *)(iVar28 + 0x58));
                pRVar27 = *(RGE_Player **)(this_00->world->_padding_ + iVar25);
                *(undefined4 *)(puVar42 + -4) = 0x4ac7fd;
                RGE_Player::set_map_visible(pRVar27);
                iVar25 = iVar25 + 4;
              } while (iVar25 < 0x20);
              *(undefined4 *)(puVar42 + -4) = 0x4ac80c;
              TRIBE_Screen_Sed::set_panel_info(this_00);
              pTVar12 = this_00->map_generating_text;
              *(undefined4 *)(puVar42 + -4) = 0;
              pcVar18 = *(code **)(pTVar12->_padding_ + 0x14);
              puVar35 = puVar42 + -8;
              *(undefined4 *)(puVar42 + -8) = 0x4ac81b;
              (*pcVar18)();
              goto LAB_004abe5a;
            }
          }
          break;
        case ScenarioModeTerrain:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if ((iVar25 == 2) || (iVar25 == 1)) {
            pTVar19 = (TRIBE_Main_View *)this_00->paint_terrain_list;
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 0x4ac84e;
              iVar25 = TTextPanel::currentLineNumber((TTextPanel *)pTVar19);
              *(int *)(puVar35 + -4) = iVar25;
              *(undefined4 *)(puVar35 + -8) = 0x4ac856;
              TRIBE_Screen_Sed::set_terrain(this_00,*(short *)(puVar35 + -4));
              pTVar17 = this_00->brush_size_button[0];
              *(undefined4 *)(puVar35 + -4) = 1;
              pcVar18 = *(code **)(pTVar17->_padding_ + 0x14);
              puVar44 = (undefined4 *)(puVar35 + -8);
              puVar35 = puVar35 + -8;
              *puVar44 = 0x4ac865;
              (*pcVar18)();
            }
            else {
              pTVar19 = (TRIBE_Main_View *)this_00->paint_elevation_list;
              if (pTVar11 != pTVar19) {
                if (iVar25 == 1) {
                  if (this_00->valid_save_spot_flag != '\0') {
                    this_00->need_to_save_flag = '\x01';
                  }
                  iVar28 = 0;
                  ppTVar32 = this_00->brush_size_button;
                  do {
                    if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                      *(int *)(puVar35 + -4) = iVar28 + 1;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac8bf;
                      TRIBE_Screen_Sed::set_brush_size(this_00,*(BrushSize *)(puVar35 + -4));
                      goto LAB_004abe5a;
                    }
                    iVar28 = iVar28 + 1;
                    ppTVar32 = ppTVar32 + 1;
                  } while (iVar28 < 5);
                  iVar28 = 0;
                  ppTVar32 = this_00->paint_type_button;
                  do {
                    if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                      *(undefined4 *)(puVar35 + -4) = 1;
                      *(int *)(puVar35 + -8) = iVar28 + 1;
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac8e9;
                      TRIBE_Screen_Sed::set_paint_type
                                (this_00,*(PaintType *)(puVar35 + -8),*(int *)(puVar35 + -4));
                      goto LAB_004abe5a;
                    }
                    iVar28 = iVar28 + 1;
                    ppTVar32 = ppTVar32 + 1;
                  } while (iVar28 < 3);
                }
                break;
              }
              *(undefined4 *)(puVar35 + -4) = 0x4ac879;
              iVar25 = TTextPanel::currentLineNumber((TTextPanel *)pTVar19);
              *(int *)(puVar35 + -4) = iVar25;
              *(undefined4 *)(puVar35 + -8) = 0x4ac881;
              TRIBE_Screen_Sed::set_elevation(this_00,*(short *)(puVar35 + -4));
            }
            goto LAB_004abe5a;
          }
          break;
        case ScenarioModePlayers:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 0) {
            iVar28 = 0;
            ppTVar34 = this_00->player_inven_input;
            do {
              if (pTVar11 == (TRIBE_Main_View *)*ppTVar34) {
                pTVar10 = this_00->bottom_panel;
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0x4ac92b;
                TPanel::set_curr_child(pTVar10,*(TPanel **)(puVar35 + -4));
                iVar28 = extraout_EAX;
                break;
              }
              iVar28 = iVar28 + 1;
              ppTVar34 = ppTVar34 + 1;
            } while (iVar28 < 5);
            uVar33 = (undefined2)((uint)iVar28 >> 0x10);
            if (this_00->valid_save_spot_flag != '\0') {
              this_00->need_to_save_flag = '\x01';
            }
            pTVar19 = (TRIBE_Main_View *)this_00->player_advance_civilization_drop;
            if (pTVar11 == pTVar19) {
              if (this_00->valid_save_spot_flag != '\0') {
                this_00->need_to_save_flag = '\x01';
              }
              *(undefined4 *)(puVar35 + -4) = 0x4ac964;
              iVar28 = TDropDownPanel::currentLineNumber((TDropDownPanel *)pTVar19);
              pTVar7 = this_00->world;
              *(int *)(puVar35 + -4) = iVar28;
              pTVar20 = (T_Scenario *)pTVar7->_padding_;
              *(int *)(puVar35 + -8) = this_00->player_num + -1;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac97c;
              T_Scenario::SetPlayerAge(pTVar20,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
              uVar33 = extraout_var;
            }
            pTVar19 = (TRIBE_Main_View *)this_00->player_list;
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 1;
              *(undefined4 *)(puVar35 + -8) = 1;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac98f;
              lVar31 = TDropDownPanel::get_line((TDropDownPanel *)pTVar19);
              *(long *)(puVar35 + -0xc) = lVar31 + 1;
              *(undefined4 *)(puVar35 + -0x10) = 0x4ac998;
              TRIBE_Screen_Sed::set_player
                        (this_00,*(short *)(puVar35 + -0xc),puVar35[-8],puVar35[-4]);
              pTVar9 = this_00->player_list;
              *(undefined4 *)(puVar35 + -4) = 0x4ac9a3;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              pTVar7 = this_00->world;
              *(long *)(puVar35 + -4) = lVar31;
              pTVar20 = (T_Scenario *)pTVar7->_padding_;
              *(undefined4 *)(puVar35 + -8) = 0x4ac9b2;
              iVar28 = T_Scenario::GetPlayerAge(pTVar20,*(int *)(puVar35 + -4));
              pTVar9 = this_00->player_advance_civilization_drop;
              *(int *)(puVar35 + -4) = iVar28;
              *(undefined4 *)(puVar35 + -8) = 0x4ac9be;
              TDropDownPanel::setCurrentLineNumber(pTVar9,*(int *)(puVar35 + -4));
              uVar33 = extraout_var_00;
            }
            if (pTVar11 == (TRIBE_Main_View *)this_00->player_number_list) {
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar35 + -4) = 0;
              *(undefined4 *)(puVar35 + -8) = 1;
              *(uint *)(puVar35 + -0xc) = CONCAT22(uVar33,sVar24);
              *(undefined4 *)(puVar35 + -0x10) = 0x4ac9d9;
              TRIBE_Screen_Sed::set_player
                        (this_00,*(short *)(puVar35 + -0xc),puVar35[-8],puVar35[-4]);
              *(undefined4 *)(puVar35 + -4) = 0x4ac9e0;
              TRIBE_Screen_Sed::SavePlayerActiveStatus(this_00);
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar35 + -4) = 1;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(uint *)(puVar35 + -0xc) = CONCAT22(extraout_var_01,sVar24);
              *(undefined4 *)(puVar35 + -0x10) = 0x4ac9f3;
              TRIBE_Screen_Sed::set_player
                        (this_00,*(short *)(puVar35 + -0xc),puVar35[-8],puVar35[-4]);
            }
          }
          if ((iVar25 == 1) &&
             (pTVar19 = (TRIBE_Main_View *)this_00->player_advance_civilization_drop,
             pTVar11 == pTVar19)) {
            *(undefined4 *)(puVar35 + -4) = 0x4aca0f;
            iVar28 = TDropDownPanel::currentLineNumber((TDropDownPanel *)pTVar19);
            sVar24 = this_00->player_num;
            *(int *)(puVar35 + -4) = iVar28;
            pTVar20 = (T_Scenario *)this_00->world->_padding_;
            *(int *)(puVar35 + -8) = sVar24 + -1;
            *(undefined4 *)(puVar35 + -0xc) = 0x4aca27;
            T_Scenario::SetPlayerAge(pTVar20,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
          }
          break;
        case ScenarioModeUnits:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 0) {
            if (this_00->valid_save_spot_flag != '\0') {
              this_00->need_to_save_flag = '\x01';
            }
            pTVar19 = (TRIBE_Main_View *)this_00->unit_player_list;
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 0x4aca69;
              lVar31 = TDropDownPanel::get_line((TDropDownPanel *)pTVar19);
              *(long *)(puVar35 + -4) = lVar31;
              *(undefined4 *)(puVar35 + -8) = 0x4aca71;
              TRIBE_Screen_Sed::set_unit_player(this_00,*(short *)(puVar35 + -4));
              pTVar9 = this_00->unit_player_list;
              *(undefined4 *)(puVar35 + -4) = 0x4aca7c;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              iVar28 = rge_base_game->_padding_;
              if (lVar31 != 0) {
                iVar25 = rge_base_game->game_mode;
                *(undefined4 *)(puVar35 + -4) = 4;
                *(int *)(puVar35 + -8) = iVar25;
                pcVar18 = *(code **)(iVar28 + 0x10);
                puVar46 = puVar35 + -0xc;
                *(undefined4 *)(puVar35 + -0xc) = 0x4acaa5;
                (*pcVar18)();
                pRVar22 = rge_base_game;
                if (rge_base_game->master_obj_id == -1) {
LAB_004acaf8:
                  *(undefined4 *)(puVar46 + -4) = 0;
                  *(undefined4 *)(puVar46 + -8) = 0;
                }
                else {
                  *(undefined4 *)(puVar46 + -4) = 0x4acaba;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  pRVar22 = rge_base_game;
                  if (pRVar27 == (RGE_Player *)0x0) goto LAB_004acaf8;
                  sVar24 = rge_base_game->master_obj_id;
                  *(undefined4 *)(puVar46 + -4) = 0x4acad0;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  pRVar22 = rge_base_game;
                  *(RGE_Player **)(puVar46 + -4) = pRVar27;
                  *(undefined4 *)(puVar46 + -8) = 0x4acadc;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  *(undefined4 *)(puVar46 + -8) =
                       *(undefined4 *)
                        (*(int *)(*(int *)(this_00->world->_padding_ + pRVar27->id * 4) + 0x24) +
                        sVar24 * 4);
                }
                pTVar16 = this_00->object_panel;
                *(undefined4 *)(puVar46 + -0xc) = 0x4acb07;
                TRIBE_Scenario_Editor_Panel_Object::set_master_info
                          (pTVar16,*(RGE_Master_Static_Object **)(puVar46 + -8),
                           *(TRIBE_Player **)(puVar46 + -4));
                *(undefined4 *)(puVar46 + -4) = 0x4acb0e;
                TRIBE_Screen_Sed::set_paint_object_mode(this_00);
                pTVar16 = this_00->object_panel;
                *(undefined4 *)(puVar46 + -4) = 2;
                pcVar18 = *(code **)(pTVar16->_padding_ + 0x20);
                puVar35 = puVar46 + -8;
                *(undefined4 *)(puVar46 + -8) = 0x4acb1d;
                (*pcVar18)();
                goto LAB_004abe5a;
              }
              iVar3 = rge_base_game->game_mode;
              *(undefined4 *)(puVar35 + -4) = 3;
              *(int *)(puVar35 + -8) = iVar3;
              pcVar18 = *(code **)(iVar28 + 0x10);
              puVar45 = (undefined4 *)(puVar35 + -0xc);
              puVar35 = puVar35 + -0xc;
              *puVar45 = 0x4aca94;
              (*pcVar18)();
            }
          }
          pRVar22 = rge_base_game;
          if ((iVar25 == 2) || (iVar25 == 1)) {
            pTVar19 = (TRIBE_Main_View *)this_00->unit_list;
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 0x4acb43;
              iVar25 = TTextPanel::currentLineNumber((TTextPanel *)pTVar19);
              *(int *)(puVar35 + -4) = iVar25;
              *(undefined4 *)(puVar35 + -8) = 0x4acb4b;
              TRIBE_Screen_Sed::set_unit(this_00,*(short *)(puVar35 + -4));
              if ((rge_base_game->game_mode != 8) && (rge_base_game->game_mode != 0x15)) {
                pTVar17 = this_00->unit_mode_select[0];
                *(undefined4 *)(puVar35 + -4) = 0x4acb6c;
                TButtonPanel::set_radio_button(pTVar17);
              }
              pRVar22 = rge_base_game;
              if (rge_base_game->master_obj_id == -1) {
LAB_004acbbf:
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0;
              }
              else {
                *(undefined4 *)(puVar35 + -4) = 0x4acb81;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                pRVar22 = rge_base_game;
                if (pRVar27 == (RGE_Player *)0x0) goto LAB_004acbbf;
                sVar24 = rge_base_game->master_obj_id;
                *(undefined4 *)(puVar35 + -4) = 0x4acb97;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                pRVar22 = rge_base_game;
                *(RGE_Player **)(puVar35 + -4) = pRVar27;
                *(undefined4 *)(puVar35 + -8) = 0x4acba3;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -8) =
                     *(undefined4 *)
                      (*(int *)(*(int *)(this_00->world->_padding_ + pRVar27->id * 4) + 0x24) +
                      sVar24 * 4);
              }
              pTVar16 = this_00->object_panel;
              *(undefined4 *)(puVar35 + -0xc) = 0x4acbce;
              TRIBE_Scenario_Editor_Panel_Object::set_master_info
                        (pTVar16,*(RGE_Master_Static_Object **)(puVar35 + -8),
                         *(TRIBE_Player **)(puVar35 + -4));
              *(undefined4 *)(puVar35 + -4) = 0x4acbd5;
              TRIBE_Screen_Sed::set_paint_object_mode(this_00);
              pTVar16 = this_00->object_panel;
              *(undefined4 *)(puVar35 + -4) = 1;
              pcVar18 = *(code **)(pTVar16->_padding_ + 0x20);
              puVar47 = (undefined4 *)(puVar35 + -8);
              puVar35 = puVar35 + -8;
              *puVar47 = 0x4acbe4;
              (*pcVar18)();
              goto LAB_004abe5a;
            }
            if (iVar25 == 1) {
              if (pTVar11 == (TRIBE_Main_View *)this_00->unit_mode_select[0]) {
                *(undefined4 *)(puVar35 + -4) = 0x4acc01;
                TRIBE_Screen_Sed::set_paint_object_mode(this_00);
              }
              else if (pTVar11 == (TRIBE_Main_View *)this_00->unit_mode_select[1]) {
                *(undefined4 *)(puVar35 + -4) = 0x4acc19;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -4) = 0x4acc20;
                RGE_Player::unselect_object(pRVar27);
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0xe;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar48 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar48 = 0x4acc2f;
                (*pcVar18)();
              }
              else if (pTVar11 == (TRIBE_Main_View *)this_00->unit_mode_select[2]) {
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0xf;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar49 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar49 = 0x4acc4b;
                (*pcVar18)();
              }
              else if (pTVar11 == (TRIBE_Main_View *)this_00->unit_mode_select[3]) {
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0x14;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar50 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar50 = 0x4acc6b;
                (*pcVar18)();
              }
            }
          }
          break;
        case ScenarioModeDiplomacy:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if ((iVar25 == 0) || (iVar25 == 1)) {
            if (pTVar11 == (TRIBE_Main_View *)this_00->Diplomacy_player_list) {
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar35 + -4) = 1;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][0]->_padding_ + 0x14);
              puVar52 = puVar35 + -8;
              *(undefined4 *)(puVar35 + -8) = 0x4acd23;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar52 + -4) = 1;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][1]->_padding_ + 0x14);
              puVar53 = puVar52 + -8;
              *(undefined4 *)(puVar52 + -8) = 0x4acd3c;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar53 + -4) = 1;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][2]->_padding_ + 0x14);
              puVar54 = puVar53 + -8;
              *(undefined4 *)(puVar53 + -8) = 0x4acd54;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar54 + -4) = 0;
              pcVar18 = *(code **)(this_00->Diplomacy_AlliedVictory[sVar24 + -1]->_padding_ + 0x14);
              puVar55 = puVar54 + -8;
              *(undefined4 *)(puVar54 + -8) = 0x4acd69;
              (*pcVar18)();
              pTVar9 = this_00->Diplomacy_player_list;
              *(undefined4 *)(puVar55 + -4) = 0x4acd74;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              sVar24 = (short)lVar31 + 1;
              *(undefined4 *)(puVar55 + -4) = 0;
              this_00->player_num = sVar24;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][0]->_padding_ + 0x14);
              puVar56 = puVar55 + -8;
              *(undefined4 *)(puVar55 + -8) = 0x4acd90;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar56 + -4) = 0;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][1]->_padding_ + 0x14);
              puVar57 = puVar56 + -8;
              *(undefined4 *)(puVar56 + -8) = 0x4acda9;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar57 + -4) = 0;
              pcVar18 = *(code **)(this_00->Diplomacy_friend_box[sVar24 + -1][2]->_padding_ + 0x14);
              puVar58 = puVar57 + -8;
              *(undefined4 *)(puVar57 + -8) = 0x4acdc1;
              (*pcVar18)();
              sVar24 = this_00->player_num;
              *(undefined4 *)(puVar58 + -4) = 1;
              pcVar18 = *(code **)(this_00->Diplomacy_AlliedVictory[sVar24 + -1]->_padding_ + 0x14);
              puVar35 = puVar58 + -8;
              *(undefined4 *)(puVar58 + -8) = 0x4acdd6;
              (*pcVar18)();
              pTVar9 = this_00->Diplomacy_player_list;
              *(undefined4 *)(puVar35 + -4) = 0x4acde1;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              *(long *)(puVar35 + -4) = lVar31;
              *(undefined4 *)(puVar35 + -8) = 0x4acde9;
              TRIBE_Screen_Sed::load_diplomacy_from_scenario(this_00,*(int *)(puVar35 + -4));
            }
            if (iVar25 == 1) {
              *(int *)(puVar35 + -4) = this_00->player_num + -1;
              *(undefined4 *)(puVar35 + -8) = 0x4acdfe;
              TRIBE_Screen_Sed::save_diplomacy_in_scenario(this_00,*(int *)(puVar35 + -4));
              goto LAB_004abe5a;
            }
          }
          break;
        case ScenarioModeVictory:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (((iVar25 == 0) || (iVar25 == 1)) &&
             (pTVar11 == (TRIBE_Main_View *)this_00->victory_player_list)) {
            *(int *)(puVar35 + -4) = this_00->CurrentVictory;
            *(undefined4 *)(puVar35 + -8) = 0x4ac0b7;
            TRIBE_Screen_Sed::save_victory_cond_in_scenario(this_00,*(int *)(puVar35 + -4));
            *(undefined4 *)(puVar35 + -4) = 0;
            *(undefined4 *)(puVar35 + -8) = 0x4ac0c0;
            TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar35 + -4));
            *(undefined4 *)(puVar35 + -4) = 0;
            *(undefined4 *)(puVar35 + -8) = 0;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ac0cb;
            TRIBE_Screen_Sed::activate_victory_proper_fields
                      (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
            pTVar9 = this_00->victory_player_list;
            *(undefined4 *)(puVar35 + -4) = 0x4ac0d6;
            lVar31 = TDropDownPanel::get_line(pTVar9);
            sVar24 = (short)lVar31 + 1;
            this_00->player_num = sVar24;
            pTVar20 = (T_Scenario *)this_00->world->_padding_;
            *(int *)(puVar35 + -4) = sVar24 + -1;
            *(undefined4 *)(puVar35 + -8) = 0x4ac0f1;
            T_Scenario::SetSPWhich(pTVar20,*(int *)(puVar35 + -4));
            *(undefined4 *)(puVar35 + -4) = 0;
            this_00->CurrentVictory = 0;
            *(undefined4 *)(puVar35 + -8) = 0x4ac104;
            TRIBE_Screen_Sed::load_victory_cond_from_scenario(this_00,*(int *)(puVar35 + -4));
            *(undefined4 *)(puVar35 + -4) = 1;
            *(undefined4 *)(puVar35 + -8) = 0x4ac10d;
            TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar35 + -4));
            pTVar9 = this_00->victory_drop_down;
            *(undefined4 *)(puVar35 + -4) = 1;
            *(undefined4 *)(puVar35 + -8) = 0x4ac11a;
            lVar31 = TDropDownPanel::get_line(pTVar9);
            *(long *)(puVar35 + -8) = lVar31;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ac122;
            TRIBE_Screen_Sed::activate_victory_proper_fields
                      (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
          }
          if ((iVar25 == 0) && (pTVar11 == (TRIBE_Main_View *)this_00->victory_amount_input)) {
            pTVar10 = this_00->bottom_panel;
            *(undefined4 *)(puVar35 + -4) = 0;
            *(undefined4 *)(puVar35 + -8) = 0x4ac13a;
            TPanel::set_curr_child(pTVar10,*(TPanel **)(puVar35 + -4));
          }
          if ((iVar25 == 2) &&
             (pTVar19 = (TRIBE_Main_View *)this_00->victory_drop_down, pTVar11 == pTVar19)) {
            *(undefined4 *)(puVar35 + -4) = 1;
            *(undefined4 *)(puVar35 + -8) = 0x4ac150;
            lVar31 = TDropDownPanel::get_line((TDropDownPanel *)pTVar19);
            *(long *)(puVar35 + -8) = lVar31;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ac158;
            TRIBE_Screen_Sed::activate_victory_proper_fields
                      (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
          }
          if (iVar25 == 1) {
            if (pTVar11 != (TRIBE_Main_View *)this_00->victory_amount_input) {
              pTVar9 = this_00->victory_drop_down;
              *(undefined4 *)(puVar35 + -4) = 0x4ac178;
              lVar31 = TDropDownPanel::get_line(pTVar9);
              pRVar22 = rge_base_game;
              if (pTVar11 == (TRIBE_Main_View *)this_00->victory_drop_down) {
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar36 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar36 = 0x4ac193;
                (*pcVar18)();
                this_00->DestinationObject = (RGE_Static_Object *)0x0;
                this_00->SelectedObject = (RGE_Static_Object *)0x0;
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0x4ac1aa;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -4) = 0x4ac1b1;
                RGE_Player::unselect_object(pRVar27);
              }
              if (lVar31 == 2) {
                this_00->DestinationObject = (RGE_Static_Object *)0x0;
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0x4ac1cb;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -4) = 0x4ac1d2;
                RGE_Player::unselect_object(pRVar27);
              }
              if (pTVar11 == (TRIBE_Main_View *)this_00->victory_button_set_object) {
                this_00->SelectRegionFlag = SELECT_OBJECT;
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0;
                *(undefined4 *)(puVar35 + -8) = 0x10;
                pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                puVar37 = (undefined4 *)(puVar35 + -0xc);
                puVar35 = puVar35 + -0xc;
                *puVar37 = 0x4ac1f2;
                (*pcVar18)();
                pRVar22 = rge_base_game;
                *(undefined4 *)(puVar35 + -4) = 0x4ac1fd;
                pRVar27 = RGE_Base_Game::get_player(pRVar22);
                *(undefined4 *)(puVar35 + -4) = 0x4ac204;
                RGE_Player::unselect_object(pRVar27);
                pRVar59 = this_00->DestinationObject;
LAB_004ac2a8:
                pRVar22 = rge_base_game;
                if (pRVar59 != (RGE_Static_Object *)0x0) {
                  *(undefined4 *)(puVar35 + -4) = 0;
                  *(RGE_Static_Object **)(puVar35 + -8) = pRVar59;
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac2bd;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac2c4;
                  RGE_Player::select_one_object
                            (pRVar27,*(RGE_Static_Object **)(puVar35 + -8),*(int *)(puVar35 + -4));
                }
              }
              else {
                if (pTVar11 == (TRIBE_Main_View *)this_00->victory_button_set_destination) {
                  if (lVar31 != 1) {
                    this_00->SelectRegionFlag = SELECT_AREA;
                    pRVar22 = rge_base_game;
                    *(undefined4 *)(puVar35 + -4) = 0x4ac237;
                    pRVar27 = RGE_Base_Game::get_player(pRVar22);
                    *(undefined4 *)(puVar35 + -4) = 0x4ac23e;
                    RGE_Player::unselect_object(pRVar27);
                    pRVar22 = rge_base_game;
                    pRVar59 = this_00->SelectedObject;
                    if (pRVar59 != (RGE_Static_Object *)0x0) {
                      *(undefined4 *)(puVar35 + -4) = 0;
                      *(RGE_Static_Object **)(puVar35 + -8) = pRVar59;
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac255;
                      pRVar27 = RGE_Base_Game::get_player(pRVar22);
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac25c;
                      RGE_Player::select_one_object
                                (pRVar27,*(RGE_Static_Object **)(puVar35 + -8),
                                 *(int *)(puVar35 + -4));
                    }
                    pRVar22 = rge_base_game;
                    *(undefined4 *)(puVar35 + -4) = 0;
                    *(undefined4 *)(puVar35 + -8) = 0x11;
                    pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                    puVar38 = (undefined4 *)(puVar35 + -0xc);
                    puVar35 = puVar35 + -0xc;
                    *puVar38 = 0x4ac26a;
                    (*pcVar18)();
                    goto LAB_004abe5a;
                  }
                  if (pTVar11 == (TRIBE_Main_View *)this_00->victory_button_set_destination) {
                    this_00->SelectRegionFlag = SELECT_DEST_OBJECT;
                    pRVar22 = rge_base_game;
                    *(undefined4 *)(puVar35 + -4) = 0;
                    *(undefined4 *)(puVar35 + -8) = 0x10;
                    pcVar18 = *(code **)(pRVar22->_padding_ + 0x10);
                    puVar39 = (undefined4 *)(puVar35 + -0xc);
                    puVar35 = puVar35 + -0xc;
                    *puVar39 = 0x4ac290;
                    (*pcVar18)();
                    pRVar22 = rge_base_game;
                    *(undefined4 *)(puVar35 + -4) = 0x4ac29b;
                    pRVar27 = RGE_Base_Game::get_player(pRVar22);
                    *(undefined4 *)(puVar35 + -4) = 0x4ac2a2;
                    RGE_Player::unselect_object(pRVar27);
                    pRVar59 = this_00->SelectedObject;
                    goto LAB_004ac2a8;
                  }
                }
                if ((pTVar11 != (TRIBE_Main_View *)this_00->victory_button_go_to_dest) ||
                   (lVar31 == 1)) {
                  pTVar19 = (TRIBE_Main_View *)this_00->victory_drop_down;
                  if (pTVar11 == pTVar19) {
                    *(undefined4 *)(puVar35 + -4) = 0;
                    *(undefined4 *)(puVar35 + -8) = 0x4ac3da;
                    lVar31 = TDropDownPanel::get_line((TDropDownPanel *)pTVar19);
                    *(long *)(puVar35 + -8) = lVar31;
                    *(undefined4 *)(puVar35 + -0xc) = 0x4ac3e2;
                    TRIBE_Screen_Sed::activate_victory_proper_fields
                              (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
                  }
                  iVar25 = 0;
                  ppTVar32 = this_00->victory_button;
                  do {
                    if ((pTVar11 == (TRIBE_Main_View *)*ppTVar32) &&
                       (this_00->CurrentVictory != iVar25)) {
                      pTVar9 = this_00->victory_drop_down;
                      *(undefined4 *)(puVar35 + -4) = 0;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac40b;
                      lVar31 = TDropDownPanel::get_line(pTVar9);
                      *(long *)(puVar35 + -8) = lVar31;
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac413;
                      TRIBE_Screen_Sed::activate_victory_proper_fields
                                (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
                      *(int *)(puVar35 + -4) = this_00->CurrentVictory;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac421;
                      TRIBE_Screen_Sed::save_victory_cond_in_scenario
                                (this_00,*(int *)(puVar35 + -4));
                      *(undefined4 *)(puVar35 + -4) = 0;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac42a;
                      TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar35 + -4));
                      pRVar22 = rge_base_game;
                      *(undefined4 *)(puVar35 + -4) = 0x4ac435;
                      pRVar27 = RGE_Base_Game::get_player(pRVar22);
                      *(undefined4 *)(puVar35 + -4) = 0x4ac43c;
                      RGE_Player::unselect_object(pRVar27);
                      *(int *)(puVar35 + -4) = iVar25;
                      this_00->CurrentVictory = iVar25;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac44a;
                      TRIBE_Screen_Sed::load_victory_cond_from_scenario
                                (this_00,*(int *)(puVar35 + -4));
                      *(undefined4 *)(puVar35 + -4) = 1;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac453;
                      TRIBE_Screen_Sed::activate_victory_panel(this_00,*(int *)(puVar35 + -4));
                      pTVar9 = this_00->victory_drop_down;
                      *(undefined4 *)(puVar35 + -4) = 1;
                      *(undefined4 *)(puVar35 + -8) = 0x4ac460;
                      lVar31 = TDropDownPanel::get_line(pTVar9);
                      *(long *)(puVar35 + -8) = lVar31;
                      *(undefined4 *)(puVar35 + -0xc) = 0x4ac468;
                      TRIBE_Screen_Sed::activate_victory_proper_fields
                                (this_00,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
                      pRVar22 = rge_base_game;
                      pRVar59 = this_00->SelectedObject;
                      if (pRVar59 != (RGE_Static_Object *)0x0) {
                        *(undefined4 *)(puVar35 + -4) = 0;
                        *(RGE_Static_Object **)(puVar35 + -8) = pRVar59;
                        *(undefined4 *)(puVar35 + -0xc) = 0x4ac480;
                        pRVar27 = RGE_Base_Game::get_player(pRVar22);
                        *(undefined4 *)(puVar35 + -0xc) = 0x4ac487;
                        RGE_Player::select_one_object
                                  (pRVar27,*(RGE_Static_Object **)(puVar35 + -8),
                                   *(int *)(puVar35 + -4));
                      }
                      pRVar22 = rge_base_game;
                      pRVar59 = this_00->DestinationObject;
                      if (pRVar59 != (RGE_Static_Object *)0x0) {
                        *(undefined4 *)(puVar35 + -4) = 0;
                        *(RGE_Static_Object **)(puVar35 + -8) = pRVar59;
                        *(undefined4 *)(puVar35 + -0xc) = 4899999;
                        pRVar27 = RGE_Base_Game::get_player(pRVar22);
                        *(undefined4 *)(puVar35 + -0xc) = 0x4ac4a6;
                        RGE_Player::select_one_object
                                  (pRVar27,*(RGE_Static_Object **)(puVar35 + -8),
                                   *(int *)(puVar35 + -4));
                      }
                    }
                    iVar25 = iVar25 + 1;
                    ppTVar32 = ppTVar32 + 1;
                  } while (iVar25 < 0xc);
                  iVar25 = *(int *)(puVar35 + 0x4c);
                  break;
                }
                pTVar11 = this_00->main_view;
                *(undefined4 *)(puVar35 + -4) = 1;
                *(undefined1 **)(puVar35 + -8) = puVar35 + 0x1c;
                *(undefined1 **)(puVar35 + -0xc) = puVar35 + 0x10;
                *(undefined1 **)(puVar35 + -0x10) = puVar35 + 0x18;
                *(undefined1 **)(puVar35 + -0x14) = puVar35 + 0x14;
                *(undefined4 *)(puVar35 + -0x18) = 0x4ac2ff;
                RGE_View::get_selection_area
                          ((RGE_View *)pTVar11,*(long **)(puVar35 + -0x14),
                           *(long **)(puVar35 + -0x10),*(long **)(puVar35 + -0xc),
                           *(long **)(puVar35 + -8),*(int *)(puVar35 + -4));
                iVar25 = *(int *)(puVar35 + 0x10);
                fVar21 = (float)iVar25;
                iVar28 = *(int *)(puVar35 + 0x14);
                iVar3 = *(int *)(puVar35 + 0x18);
                bVar61 = fVar21 != _DAT_00573ae8;
                iVar4 = *(int *)(puVar35 + 0x1c);
                *(float *)(puVar35 + 0x48) = (float)iVar3;
                *(float *)(puVar35 + 0x4c) = (float)iVar4;
                this_00->px1 = (float)iVar28;
                this_00->py1 = (float)iVar3;
                this_00->SelectRegionFlag = SELECT_OFF;
                this_00->px2 = (float)iVar25;
                this_00->py2 = (float)iVar4;
                if (bVar61) {
                  *(float *)(puVar35 + 0x50) = fVar21 - (fVar21 - (float)iVar28) * _DAT_00573aec;
                  *(float *)(puVar35 + 0x4c) =
                       *(float *)(puVar35 + 0x4c) -
                       (*(float *)(puVar35 + 0x4c) - *(float *)(puVar35 + 0x48)) * _DAT_00573aec;
                  *(undefined4 *)(puVar35 + -4) = *(undefined4 *)(puVar35 + 0x4c);
                  pRVar22 = rge_base_game;
                  *(undefined4 *)(puVar35 + -8) = *(undefined4 *)(puVar35 + 0x50);
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac398;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac39f;
                  RGE_Player::set_view_loc
                            (pRVar27,*(float *)(puVar35 + -8),*(float *)(puVar35 + -4));
                  *(undefined4 *)(puVar35 + -4) = 0x4ac3a8;
                  uVar26 = __ftol();
                  *(undefined4 *)(puVar35 + -4) = uVar26;
                  *(undefined4 *)(puVar35 + -8) = 0x4ac3b2;
                  uVar26 = __ftol();
                  pRVar22 = rge_base_game;
                  *(undefined4 *)(puVar35 + -8) = uVar26;
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac3be;
                  pRVar27 = RGE_Base_Game::get_player(pRVar22);
                  *(undefined4 *)(puVar35 + -0xc) = 0x4ac3c5;
                  RGE_Player::set_map_loc(pRVar27,*(short *)(puVar35 + -8),*(short *)(puVar35 + -4))
                  ;
                }
              }
            }
            goto LAB_004abe5a;
          }
          break;
        case ScenarioModeVictoryMulti:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 1) {
            iVar28 = 0;
            ppTVar32 = this_00->victory_cond_type;
            do {
              if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                *(undefined4 *)(puVar35 + -4) = 1;
                *(int *)(puVar35 + -8) = iVar28 + 1;
                *(undefined4 *)(puVar35 + -0xc) = 0x4accb1;
                TRIBE_Screen_Sed::set_mp_victory_type
                          (this_00,*(VictoryType *)(puVar35 + -8),*(int *)(puVar35 + -4));
                if (iVar28 != 4) {
                  pTVar7 = this_00->world;
                  *(undefined4 *)(puVar35 + -4) = 1;
                  pTVar20 = (T_Scenario *)pTVar7->_padding_;
                  *(undefined4 *)(puVar35 + -8) = 0x4accca;
                  T_Scenario::Set_Multi_Conquest(pTVar20,*(int *)(puVar35 + -4));
                  pTVar17 = this_00->victory_cond_on[0];
                  *(undefined4 *)(puVar35 + -4) = 1;
                  pcVar18 = *(code **)(pTVar17->_padding_ + 0xe0);
                  puVar51 = (undefined4 *)(puVar35 + -8);
                  puVar35 = puVar35 + -8;
                  *puVar51 = 0x4accdc;
                  (*pcVar18)();
                }
                goto LAB_004abe5a;
              }
              iVar28 = iVar28 + 1;
              ppTVar32 = ppTVar32 + 1;
            } while (iVar28 < 5);
          }
          break;
        case ScenarioModeOptions:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 1) {
            *(undefined4 *)(puVar35 + -4) = 0x4ace20;
            TRIBE_Screen_Sed::SaveDisabledItemsInScenario(this_00);
            *(undefined4 *)(puVar35 + -4) = 0x4ace27;
            TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(this_00);
            pTVar19 = (TRIBE_Main_View *)this_00->options_button[0];
            if (pTVar11 == pTVar19) {
              *(undefined4 *)(puVar35 + -4) = 0x4ace36;
              iVar28 = TButtonPanel::get_state((TButtonPanel *)pTVar19);
              pTVar7 = this_00->world;
              *(int *)(puVar35 + -4) = iVar28;
              *(undefined4 *)(puVar35 + -8) = 2;
              pTVar20 = (T_Scenario *)pTVar7->_padding_;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ace47;
              T_Scenario::SetScenarioOption(pTVar20,*(int *)(puVar35 + -8),*(int *)(puVar35 + -4));
            }
          }
          break;
        case ScenarioModeMessages:
          if (this_00->valid_save_spot_flag != '\0') {
            this_00->need_to_save_flag = '\x01';
          }
          if (iVar25 == 1) {
            pTVar6 = this_00->message_input;
            *(long *)(puVar35 + -4) = this_00->current_message;
            *(undefined4 *)(puVar35 + -8) = 0x4abfad;
            pcVar29 = TEditPanel::get_input_buffer(pTVar6);
            pTVar7 = this_00->world;
            *(char **)(puVar35 + -8) = pcVar29;
            pRVar8 = (RGE_Scenario *)pTVar7->_padding_;
            *(undefined4 *)(puVar35 + -0xc) = 0x4abfbc;
            RGE_Scenario::Set_message(pRVar8,*(char **)(puVar35 + -8),*(long *)(puVar35 + -4));
            iVar28 = 0;
            ppTVar32 = this_00->message_button;
            do {
              if (pTVar11 == (TRIBE_Main_View *)*ppTVar32) {
                this_00->current_message = iVar28;
                break;
              }
              iVar28 = iVar28 + 1;
              ppTVar32 = ppTVar32 + 1;
            } while (iVar28 < 5);
            pTVar7 = this_00->world;
            *(long *)(puVar35 + -4) = this_00->current_message;
            pRVar8 = (RGE_Scenario *)pTVar7->_padding_;
            *(undefined4 *)(puVar35 + -8) = 0x4abfee;
            pcVar29 = RGE_Scenario::Get_message(pRVar8,*(long *)(puVar35 + -4));
            pTVar6 = this_00->message_input;
            *(char **)(puVar35 + -4) = pcVar29;
            *(undefined4 *)(puVar35 + -8) = 0x4abffa;
            TEditPanel::set_text(pTVar6,*(char **)(puVar35 + -4));
            switch(this_00->current_message) {
            case 0:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7770;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac022;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
              break;
            case 1:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7771;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac039;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
              break;
            case 2:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7772;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac050;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
              break;
            case 3:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7773;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac067;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
              break;
            case 4:
              pTVar6 = this_00->message_input;
              *(undefined4 *)(puVar35 + -4) = 0xffffffff;
              *(undefined4 *)(puVar35 + -8) = 0x7774;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ac07e;
              TPanel::set_help_info
                        ((TPanel *)pTVar6,*(long *)(puVar35 + -8),*(long *)(puVar35 + -4));
            }
          }
        }
        *(undefined4 *)(puVar35 + -4) = 0x4ace4e;
        pcVar29 = TPanel::panelName((TPanel *)pTVar11);
        if (pcVar29 != (char *)0x0) {
          pbVar60 = &s_QuitSaveDialog;
          *(undefined4 *)(puVar35 + -4) = 0x4ace62;
          pbVar30 = (byte *)TPanel::panelName((TPanel *)pTVar11);
          do {
            bVar5 = *pbVar30;
            bVar61 = bVar5 < *pbVar60;
            if (bVar5 != *pbVar60) {
LAB_004ace86:
              iVar28 = (1 - (uint)bVar61) - (uint)(bVar61 != 0);
              goto LAB_004ace8b;
            }
            if (bVar5 == 0) break;
            bVar5 = pbVar30[1];
            bVar61 = bVar5 < pbVar60[1];
            if (bVar5 != pbVar60[1]) goto LAB_004ace86;
            pbVar30 = pbVar30 + 2;
            pbVar60 = pbVar60 + 2;
          } while (bVar5 != 0);
          iVar28 = 0;
LAB_004ace8b:
          if (iVar28 == 0) {
            *(undefined4 *)(puVar35 + -4) = 0;
            *(char **)(puVar35 + -8) = s_Scenario_Editor_Screen;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ace9f;
            TPanelSystem::setCurrentPanel
                      (&panel_system,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            *(undefined **)(puVar35 + -4) = &s_QuitSaveDialog;
            *(undefined4 *)(puVar35 + -8) = 0x4aceae;
            TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
            pRVar22 = rge_base_game;
            if (iVar25 == 0) {
              *(undefined4 *)(puVar35 + -4) = 1;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(undefined4 *)(puVar35 + -0xc) = 0x4acebc;
              TRIBE_Screen_Sed::command_save(this_00,puVar35[-8],puVar35[-4]);
            }
            else if (iVar25 == 1) {
              *(undefined4 *)(puVar35 + -4) = 0x4aced5;
              iVar25 = TRIBE_Game::start_menu((TRIBE_Game *)pRVar22);
              pRVar22 = rge_base_game;
              if (iVar25 == 0) {
                *(undefined4 *)(puVar35 + -4) = 0x4acee4;
                RGE_Base_Game::close(pRVar22);
              }
              else {
                *(char **)(puVar35 + -4) = s_Scenario_Editor_Screen;
                *(undefined4 *)(puVar35 + -8) = 0x4acef8;
                TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
              }
            }
            goto LAB_004abe5a;
          }
        }
        *(undefined4 *)(puVar35 + -4) = 0x4acf04;
        pcVar29 = TPanel::panelName((TPanel *)pTVar11);
        if (pcVar29 != (char *)0x0) {
          pbVar60 = &s_OpenSaveDialog;
          *(undefined4 *)(puVar35 + -4) = 0x4acf18;
          pbVar30 = (byte *)TPanel::panelName((TPanel *)pTVar11);
          do {
            bVar5 = *pbVar30;
            bVar61 = bVar5 < *pbVar60;
            if (bVar5 != *pbVar60) {
LAB_004acf3c:
              iVar28 = (1 - (uint)bVar61) - (uint)(bVar61 != 0);
              goto LAB_004acf41;
            }
            if (bVar5 == 0) break;
            bVar5 = pbVar30[1];
            bVar61 = bVar5 < pbVar60[1];
            if (bVar5 != pbVar60[1]) goto LAB_004acf3c;
            pbVar30 = pbVar30 + 2;
            pbVar60 = pbVar60 + 2;
          } while (bVar5 != 0);
          iVar28 = 0;
LAB_004acf41:
          if (iVar28 == 0) {
            *(undefined4 *)(puVar35 + -4) = 0;
            *(char **)(puVar35 + -8) = s_Scenario_Editor_Screen;
            *(undefined4 *)(puVar35 + -0xc) = 0x4acf55;
            TPanelSystem::setCurrentPanel
                      (&panel_system,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            *(undefined **)(puVar35 + -4) = &s_OpenSaveDialog;
            *(undefined4 *)(puVar35 + -8) = 0x4acf64;
            TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
            if (iVar25 == 0) {
              *(undefined4 *)(puVar35 + -4) = 2;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(undefined4 *)(puVar35 + -0xc) = 0x4acf72;
              TRIBE_Screen_Sed::command_save(this_00,puVar35[-8],puVar35[-4]);
            }
            else if (iVar25 == 1) {
              *(undefined4 *)(puVar35 + -4) = 0x490;
              *(undefined4 *)(puVar35 + -8) = 0x4acf8a;
              this = (TRIBE_Screen_Sed_Open *)operator_new(*(uint *)(puVar35 + -4));
              *(TRIBE_Screen_Sed_Open **)(puVar35 + 0x4c) = this;
              *(undefined4 *)(puVar35 + 0x40) = 0;
              if (this != (TRIBE_Screen_Sed_Open *)0x0) {
                *(undefined4 *)(puVar35 + -4) = 0x4acfa4;
                TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this);
              }
              *(undefined4 *)(puVar35 + -4) = 0;
              *(char **)(puVar35 + -8) = s_Scenario_Editor_Open;
              *(undefined4 *)(puVar35 + 0x40) = 0xffffffff;
              *(undefined4 *)(puVar35 + -0xc) = 0x4acfbd;
              TPanelSystem::setCurrentPanel
                        (&panel_system,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            }
            goto LAB_004abe5a;
          }
        }
        *(undefined4 *)(puVar35 + -4) = 0x4acfc9;
        pcVar29 = TPanel::panelName((TPanel *)pTVar11);
        if (pcVar29 != (char *)0x0) {
          pbVar60 = &s_NewSaveDialog;
          *(undefined4 *)(puVar35 + -4) = 0x4acfdd;
          pbVar30 = (byte *)TPanel::panelName((TPanel *)pTVar11);
          do {
            bVar5 = *pbVar30;
            bVar61 = bVar5 < *pbVar60;
            if (bVar5 != *pbVar60) {
LAB_004ad001:
              iVar28 = (1 - (uint)bVar61) - (uint)(bVar61 != 0);
              goto LAB_004ad006;
            }
            if (bVar5 == 0) break;
            bVar5 = pbVar30[1];
            bVar61 = bVar5 < pbVar60[1];
            if (bVar5 != pbVar60[1]) goto LAB_004ad001;
            pbVar30 = pbVar30 + 2;
            pbVar60 = pbVar60 + 2;
          } while (bVar5 != 0);
          iVar28 = 0;
LAB_004ad006:
          if (iVar28 == 0) {
            *(undefined4 *)(puVar35 + -4) = 0;
            *(char **)(puVar35 + -8) = s_Scenario_Editor_Screen;
            *(undefined4 *)(puVar35 + -0xc) = 0x4ad01a;
            TPanelSystem::setCurrentPanel
                      (&panel_system,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            *(undefined **)(puVar35 + -4) = &s_NewSaveDialog;
            *(undefined4 *)(puVar35 + -8) = 0x4ad029;
            TPanelSystem::destroyPanel(&panel_system,*(char **)(puVar35 + -4));
            pRVar22 = rge_base_game;
            if (iVar25 == 0) {
              *(undefined4 *)(puVar35 + -4) = 3;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ad037;
              TRIBE_Screen_Sed::command_save(this_00,puVar35[-8],puVar35[-4]);
            }
            else if (iVar25 == 1) {
              *(undefined4 *)(puVar35 + -4) = 0;
              *(undefined4 *)(puVar35 + -8) = 0;
              *(undefined4 *)(puVar35 + -0xc) = 0x4ad054;
              TRIBE_Game::start_scenario_editor
                        ((TRIBE_Game *)pRVar22,*(char **)(puVar35 + -8),*(int *)(puVar35 + -4));
            }
            goto LAB_004abe5a;
          }
        }
        uVar26 = 0;
        goto LAB_004abe5f;
      }
    }
  }
LAB_004abe5a:
  uVar26 = 1;
LAB_004abe5f:
  *unaff_FS_OFFSET = *(undefined4 *)(puVar35 + 0x38);
  return uVar26;
}

// --------------------------------------------------

// Function: FUN_004ad06e
// Address: 004ad06e
// XREFS: None
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_004ad06e(void)
{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_EBP;
  
  puVar2 = (undefined4 *)0x20004ac0;
  cVar1 = '\r';
  puVar3 = puVar2;
  puRam20004ac0 = unaff_EBP;
  do {
    unaff_EBP = unaff_EBP + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *unaff_EBP;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  uRam20004a88 = 0x20004ac0;
  puVar3 = (undefined4 *)0x20004a3a;
  uRam20004a3a = 0x20004ac0;
  cVar1 = '\v';
  do {
    puVar2 = puVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *puVar2;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  uRam20004a0a = 0x20004a3a;
  return;
}

// --------------------------------------------------

// Function: FUN_004ad232
// Address: 004ad232
// XREFS: None
void FUN_004ad232(void)
{
  RGE_Player *pRVar1;
  
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_object(pRVar1);
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_area(pRVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_004ad264
// Address: 004ad264
// XREFS: None
undefined4 __fastcall FUN_004ad264(TRIBE_Screen_Sed *param_1)
{
  TRIBE_Dialog_Sed_Menu *this;
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f4ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Dialog_Sed_Menu *)operator_new(0x4b4);
  uStack_4 = 0;
  if (this == (TRIBE_Dialog_Sed_Menu *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(this,param_1);
  }
  uStack_4 = 0xffffffff;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[0x36] != 0)) {
    (**(code **)*puVar1)(1);
    *unaff_FS_OFFSET = this;
    return 0;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004ad2f7
// Address: 004ad2f7
// XREFS: None
void __fastcall FUN_004ad2f7(TRIBE_Screen_Sed *param_1)
{
  uchar uVar1;
  
  uVar1 = TRIBE_Screen_Sed::need_to_save(param_1);
  if (uVar1 != '\0') {
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)param_1,0x2447,&s_NewSaveDialog,0x1c2,100);
    return;
  }
  TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004ad337
// Address: 004ad337
// XREFS: None
char __thiscall
FUN_004ad337(TRIBE_Screen_Sed *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined2 param_6,int param_7)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined2 *puVar5;
  char *pcVar6;
  int iStack_7d4;
  char acStack_7cc [585];
  undefined1 auStack_583 [9];
  undefined1 auStack_57a [10];
  undefined2 auStack_570 [10];
  int aiStack_55c [9];
  undefined2 uStack_538;
  int iStack_534;
  undefined2 *puStack_530;
  undefined2 uStack_52a;
  undefined2 uStack_528;
  undefined2 uStack_526;
  undefined2 auStack_520 [656];
  
  param_1->need_to_save_flag = '\0';
  if (rge_base_game->world == (RGE_Game_World *)0x0) {
    if (param_7 != 0) {
      TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x44d,(char *)0x0,-1);
    }
    iVar2 = TRIBE_Game::load_game_data((TRIBE_Game *)rge_base_game);
    if (iVar2 == 0) {
      if (param_7 != 0) {
        TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
      }
      return '\0';
    }
  }
  param_1->world = (TRIBE_World *)rge_base_game->world;
  if (param_7 != 0) {
    if (param_2 == 0) {
      iVar2 = 0x44e;
    }
    else {
      iVar2 = 0x44f;
    }
    TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,iVar2,(char *)0x0,-1);
  }
  puStack_530 = auStack_520;
  uStack_52a = param_5;
  uStack_528 = param_6;
  iStack_534 = param_2;
  iVar2 = 0;
  uStack_526 = 0;
  uStack_538 = 8;
  iStack_7d4 = 0;
  piVar4 = aiStack_55c;
  puVar5 = auStack_570;
  pcVar6 = acStack_7cc;
  do {
    iStack_7d4 = iStack_7d4 + 1;
    if ((short)param_1->world->_padding_ <= iStack_7d4) {
      iStack_7d4 = 1;
    }
    TRIBE_Screen_Sed::set_string(param_1,pcVar6,iVar2 + 0x2865,0x41);
    auStack_583[iVar2] = 0;
    auStack_57a[iVar2] = (undefined1)iStack_7d4;
    *puVar5 = 0xffff;
    *piVar4 = iVar2;
    iVar2 = iVar2 + 1;
    pcVar6 = pcVar6 + 0x41;
    puVar5 = puVar5 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar2 < 8);
  aiStack_55c[iVar2] = iVar2;
  auStack_520[0] = 0;
  if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
    rge_base_game->sound_system->mute = '\x01';
  }
  cVar1 = (**(code **)(param_1->world->_padding_ + 0xd4))(acStack_7cc,param_4);
  if ((cVar1 != '\0') && ((short)param_1->world->_padding_ < 8)) {
    cVar1 = '\0';
    (**(code **)(param_1->world->_padding_ + 0xb8))();
  }
  if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
    rge_base_game->sound_system->mute = '\0';
  }
  if ((cVar1 != '\0') && (param_1->player_number_list != (TDropDownPanel *)0x0)) {
    iVar2 = 0;
    do {
      iVar3 = RGE_Scenario::Get_player_Active((RGE_Scenario *)param_1->world->_padding_,iVar2);
      if (iVar3 == 0) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    if ((iVar2 < 8) && (0 < iVar2)) {
      TDropDownPanel::set_line(param_1->player_number_list,iVar2 + -1);
    }
    TRIBE_Screen_Sed::SavePlayerActiveStatus(param_1);
  }
  return cVar1;
}

// --------------------------------------------------

// Function: FUN_004ad58e
// Address: 004ad58e
// XREFS: None
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
void __fastcall FUN_004ad58e(TRIBE_Screen_Sed *param_1)
{
  uchar uVar1;
  TRIBE_Screen_Sed_Open *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f4cb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar1 = TRIBE_Screen_Sed::need_to_save(param_1);
  if (uVar1 != '\0') {
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)param_1,0x2447,&s_OpenSaveDialog,0x1c2,100);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  this = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
  uStack_4 = 0;
  if (this != (TRIBE_Screen_Sed_Open *)0x0) {
    TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this);
  }
  uStack_4 = 0xffffffff;
  TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004ad627
// Address: 004ad627
// XREFS: None
void FUN_004ad627(void)
{
  uchar uVar1;
  
  uVar1 = rge_base_game->outline_type;
  switch(uVar1) {
  case '\0':
  case '\x03':
    rge_base_game->outline_type = '\x02';
    return;
  case '\x01':
    uVar1 = '\0';
    break;
  case '\x02':
    rge_base_game->outline_type = '\x01';
    return;
  }
  rge_base_game->outline_type = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_004ad693
// Address: 004ad693
// XREFS: None
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
void __fastcall FUN_004ad693(TRIBE_Screen_Sed *param_1)
{
  uchar uVar1;
  int iVar2;
  
  uVar1 = TRIBE_Screen_Sed::need_to_save(param_1);
  if (uVar1 != '\0') {
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)param_1,0x2447,&s_QuitSaveDialog,0x1c2,100);
    return;
  }
  iVar2 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
  if (iVar2 == 0) {
    RGE_Base_Game::close(rge_base_game);
    return;
  }
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  return;
}

// --------------------------------------------------

// Function: FUN_004ad6f3
// Address: 004ad6f3
// XREFS: None
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Scenario_Menu_Dialog: "Scenario Menu Dialog"
// [HELPER] s_default_d: "default%d"
void __thiscall FUN_004ad6f3(TRIBE_Screen_Sed *param_1,char param_2,uchar param_3)
{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  TRIBE_Screen_Sed_Open *this;
  byte *pbVar5;
  undefined4 *unaff_FS_OFFSET;
  bool bVar6;
  byte abStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f4ee;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)param_1->world->_padding_,1);
  iVar3 = RGE_Scenario::active_player_count((RGE_Scenario *)param_1->world->_padding_);
  if (iVar3 < 1) {
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x2742,(char *)0x0,0x1c2,100);
  }
  else {
    iVar3 = RGE_Scenario::any_player_count((RGE_Scenario *)param_1->world->_padding_);
    if (iVar3 < 1) {
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x2743,(char *)0x0,0x1c2,100);
    }
    else {
      pbVar4 = (byte *)RGE_Scenario::Get_scenario_name((RGE_Scenario *)param_1->world->_padding_);
      if (*pbVar4 == 0) {
        TRIBE_Screen_Sed::command_save_as(param_1,param_3);
      }
      else {
        TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x450,(char *)0x0,-1);
        if (param_2 != '\0') {
          TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
        }
        cVar2 = (**(code **)(param_1->world->_padding_ + 0xe4))(pbVar4);
        if (cVar2 == '\0') {
          TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
          TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x963,(char *)0x0,0x1c2,100);
        }
        else {
          TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
          iVar3 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
          sprintf(abStack_110,s_default_d,iVar3);
          pbVar5 = abStack_110;
          do {
            bVar1 = *pbVar4;
            bVar6 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_004ad897:
              iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_004ad89c;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar6 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_004ad897;
            pbVar4 = pbVar4 + 2;
            pbVar5 = pbVar5 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_004ad89c:
          if (iVar3 != 0) {
            param_1->need_to_save_flag = '\0';
          }
          if (param_3 == '\x01') {
            iVar3 = TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
            if (iVar3 == 0) {
              RGE_Base_Game::close(rge_base_game);
            }
            else {
              TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
            }
          }
          else if (param_3 == '\x02') {
            this = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
            uStack_4 = 0;
            if (this != (TRIBE_Screen_Sed_Open *)0x0) {
              TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this);
            }
            uStack_4 = 0xffffffff;
            TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
          }
          else if (param_3 == '\x03') {
            TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004ad955
// Address: 004ad955
// XREFS: None
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Scenario_Menu_Dialog: "Scenario Menu Dialog"
void __thiscall FUN_004ad955(TRIBE_Screen_Sed *param_1,uint param_2)
{
  int iVar1;
  TribeSaveGameScreen *this;
  undefined4 *unaff_FS_OFFSET;
  char acStack_ec [224];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f50e;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)param_1->world->_padding_,1);
  iVar1 = RGE_Scenario::active_player_count((RGE_Scenario *)param_1->world->_padding_);
  if (iVar1 < 1) {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x2742,(char *)0x0,0x1c2,100);
  }
  else {
    iVar1 = RGE_Scenario::any_player_count((RGE_Scenario *)param_1->world->_padding_);
    if (iVar1 < 1) {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x2743,(char *)0x0,0x1c2,100);
    }
    else {
      acStack_ec[0] = '\0';
      this = (TribeSaveGameScreen *)operator_new(0x6a4);
      uStack_4 = 0;
      if (this != (TribeSaveGameScreen *)0x0) {
        TribeSaveGameScreen::TribeSaveGameScreen(this,SaveScenarioEdit,acStack_ec,param_2 & 0xff);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Save_Game_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004adae4
// Address: 004adae4
// XREFS: None
void __fastcall FUN_004adae4(TRIBE_Screen_Sed *param_1)
{
  TRIBE_Screen_Sed::scenario_get_default_name(param_1);
  TRIBE_Screen_Sed::command_save(param_1,'\0','\0');
  return;
}

// --------------------------------------------------

// Function: FUN_004adb05
// Address: 004adb05
// XREFS: None
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_default_d: "default%d"
// [HELPER] s_default_d_scx: "default%d.scx"
undefined4 __fastcall FUN_004adb05(TRIBE_Screen_Sed *param_1)
{
  char cVar1;
  int iVar2;
  
  TRIBE_Screen_Sed::set_scenario_mode(param_1,ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)param_1->world->_padding_,1);
  iVar2 = RGE_Scenario::active_player_count((RGE_Scenario *)param_1->world->_padding_);
  if (iVar2 < 1) {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x2742,(char *)0x0,0x1c2,100);
    return 0;
  }
  iVar2 = RGE_Scenario::any_player_count((RGE_Scenario *)param_1->world->_padding_);
  if (iVar2 < 1) {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x2743,(char *)0x0,0x1c2,100);
    return 0;
  }
  TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,0x450,(char *)0x0,-1);
  iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
  sprintf(0x86bad8,s_default_d_scx,iVar2);
  cVar1 = (**(code **)(param_1->world->_padding_ + 0xe4))(0x86bad8);
  if (cVar1 == '\0') {
    TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
    TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x963,(char *)0x0,0x1c2,100);
    return 0;
  }
  iVar2 = TRegistry::RegGetInt(rge_base_game->registry,0,s_Game_File_Number);
  sprintf(0x86bad8,s_default_d,iVar2);
  return 0x86bad8;
}

// --------------------------------------------------

// Function: FUN_004adc2c
// Address: 004adc2c
// XREFS: None
undefined1 __fastcall FUN_004adc2c(int param_1)
{
  return *(undefined1 *)(param_1 + 0x4c0);
}

// --------------------------------------------------

// Function: FUN_004adc37
// Address: 004adc37
// XREFS: None
void __thiscall FUN_004adc37(TScreenPanel *param_1,int param_2)
{
  TScreenPanel::set_focus(param_1,param_2);
  if (*(int *)&param_1->field_0x78 != 0) {
    RGE_Base_Game::set_windows_mouse(rge_base_game,0);
    return;
  }
  RGE_Base_Game::set_windows_mouse(rge_base_game,1);
  return;
}

// --------------------------------------------------

// Function: FUN_004adc76
// Address: 004adc76
// XREFS: None
void __fastcall FUN_004adc76(int param_1)
{
  short sVar1;
  int iVar2;
  long lVar3;
  T_Scenario *this;
  undefined4 *puVar4;
  int iVar5;
  
  if (*(short *)(param_1 + 0x4b8) == 0) {
    *(undefined2 *)(param_1 + 0x4b8) = 1;
  }
  iVar5 = 0;
  puVar4 = (undefined4 *)(param_1 + 0x7d4);
  do {
    iVar2 = TButtonPanel::get_state((TButtonPanel *)*puVar4);
    if (iVar2 == 0) {
      sVar1 = *(short *)(param_1 + 0x4b8);
      this = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
    }
    else {
      sVar1 = *(short *)(param_1 + 0x4b8);
      this = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
    }
    T_Scenario::SetDisabledTechnology(this,sVar1 + -1,iVar5,(uint)(iVar2 == 0));
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar5 < 0x10);
  lVar3 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x7cc));
  *(short *)(param_1 + 0x4b8) = (short)lVar3 + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004adcfc
// Address: 004adcfc
// XREFS: None
void __fastcall FUN_004adcfc(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x7d4);
  do {
    iVar1 = T_Scenario::GetDisabledTechnology
                      (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),
                       *(short *)(param_1 + 0x4b8) + -1,iVar2);
    if (iVar1 == 0) {
      (**(code **)(*(int *)*puVar3 + 0xe0))(1);
    }
    else {
      (**(code **)(*(int *)*puVar3 + 0xe0))(0);
    }
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_004add4e
// Address: 004add4e
// XREFS: None
void FUN_004add4e(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004add51
// Address: 004add51
// XREFS: None
void __fastcall FUN_004add51(int param_1)
{
  long lVar1;
  char *pcVar2;
  int iVar3;
  T_Scenario *pTVar4;
  int iVar5;
  
  switch(*(undefined4 *)(param_1 + 0x4ac)) {
  case 1:
    iVar5 = 0;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
    break;
  case 2:
    iVar5 = 1;
    goto LAB_004adda4;
  case 3:
    iVar5 = 2;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
    break;
  case 4:
    iVar5 = 3;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
    break;
  default:
    iVar5 = 4;
LAB_004adda4:
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::SetMPVictory(pTVar4,iVar5);
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x6f8));
  T_Scenario::SetVictoryScore(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),lVar1);
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x700));
  T_Scenario::SetVictoryTime(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),lVar1);
  iVar5 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x6e0));
  if (iVar5 != 0) {
    iVar5 = 0;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
    goto LAB_004ade58;
  }
  iVar5 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x6e4));
  if (iVar5 == 0) {
    iVar5 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x6e8));
    if (iVar5 != 0) {
      iVar5 = 2;
      pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
      goto LAB_004ade58;
    }
    iVar5 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x6ec));
    if (iVar5 != 0) {
      iVar5 = 3;
      pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
      goto LAB_004ade58;
    }
    iVar5 = 4;
  }
  else {
    iVar5 = 1;
  }
  pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
LAB_004ade58:
  T_Scenario::SetMPVictory(pTVar4,iVar5);
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x6f8));
  T_Scenario::SetVictoryScore(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),lVar1);
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x700));
  T_Scenario::SetVictoryTime(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),lVar1);
  iVar5 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x684));
  if (iVar5 == 0) {
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_victory_all_flag(pTVar4,(uint)(iVar5 != 0));
  iVar5 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x668));
  if ((iVar5 == 0) &&
     (iVar5 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x6f0)), iVar5 != 0)) {
    iVar5 = 0;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    iVar5 = 1;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_Multi_Conquest(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x6b8));
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x66c));
  if (iVar3 == 0) {
    iVar5 = 0;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    if (iVar5 < 1) {
      iVar5 = 1;
    }
    if (100 < iVar5) {
      iVar5 = 100;
    }
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_Multi_Exploration(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x6bc));
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x670));
  if (iVar3 == 0) {
    iVar5 = 0;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_Multi_Ruins(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x6c0));
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x674));
  if (iVar3 == 0) {
    iVar5 = 0;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_Multi_Artifacts(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x6c4));
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x678));
  if (iVar3 == 0) {
    iVar5 = 0;
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    pTVar4 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_Multi_Discoveries(pTVar4,iVar5);
  pcVar2 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x6c8));
  iVar5 = atoi(pcVar2);
  iVar3 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x67c));
  if (iVar3 == 0) {
    T_Scenario::Set_Multi_Gold(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),0);
    return;
  }
  T_Scenario::Set_Multi_Gold(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar5);
  return;
}

// --------------------------------------------------

// Function: FUN_004ae05a
// Address: 004ae05a
// XREFS: None
void __fastcall FUN_004ae05a(int param_1,int param_2,int param_3)
{
  char in_AL;
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  T_Scenario *pTVar5;
  int unaff_EBX;
  int unaff_EBP;
  int iVar6;
  int unaff_EDI;
  bool in_CF;
  bool in_ZF;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  long lStack_8;
  
  if (!in_CF && !in_ZF) {
    lStack_8 = 0x4ae044;
    T_Scenario::Set_Multi_Gold(*(T_Scenario **)(param_2 + 0x5c),unaff_EDI);
    return;
  }
  pcVar2 = (char *)(unaff_EBP + -0x2277ffb6 + unaff_EBX * 8);
  *pcVar2 = *pcVar2 + in_AL;
  *(char *)(unaff_EBP + -0x6fffb523) = *(char *)(unaff_EBP + -0x6fffb523) + (char)param_2 + -2;
  iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x684));
  if (iVar1 == 0) {
    pTVar5 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    pTVar5 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_victory_all_flag(pTVar5,(uint)(iVar1 != 0));
  iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x668));
  if ((iVar1 == 0) &&
     (iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x6f0)), iVar1 != 0)) {
    iVar1 = 0;
    pTVar5 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  else {
    iVar1 = 1;
    pTVar5 = *(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c);
  }
  T_Scenario::Set_Multi_Conquest(pTVar5,iVar1);
  if (param_3 < 0) {
    return;
  }
  pcVar2 = TEditPanel::currentLine(*(TEditPanel **)(param_1 + 0x76c));
  iVar1 = atoi(pcVar2);
  lVar3 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x734));
  lVar4 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x740));
  iVar6 = lVar4 + 1;
  lVar4 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x738));
  RGE_View::get_selection_area
            (*(RGE_View **)(param_1 + 0x4c8),&iStack_14,&iStack_10,&iStack_c,&lStack_8,1);
  *(float *)(param_1 + 0x488) = (float)iStack_14;
  *(float *)(param_1 + 0x48c) = (float)iStack_10;
  *(float *)(param_1 + 0x490) = (float)iStack_c;
  *(float *)(param_1 + 0x494) = (float)lStack_8;
  T_Scenario::ClearSPVictoryCondition(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3);
  switch(lVar3) {
  case 1:
    if ((*(int *)(param_1 + 0x480) != 0) && (*(int *)(param_1 + 0x484) != 0)) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,3);
      T_Scenario::SetSPObject
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x480));
      T_Scenario::SetSPDestObjectID
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x484));
      return;
    }
    break;
  case 2:
    if (*(int *)(param_1 + 0x480) != 0) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,3);
      T_Scenario::SetSPObject
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x480));
      T_Scenario::SetSPRectangle
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(float *)(param_1 + 0x488),*(float *)(param_1 + 0x48c),*(float *)(param_1 + 0x490)
                 ,*(float *)(param_1 + 0x494));
      return;
    }
    break;
  case 3:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,2);
    T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar4);
    goto LAB_004ae57f;
  case 4:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,2);
    T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar4);
    T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar1);
    T_Scenario::SetSPRectangle
              (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
               *(float *)(param_1 + 0x488),*(float *)(param_1 + 0x48c),*(float *)(param_1 + 0x490),
               *(float *)(param_1 + 0x494));
    return;
  case 5:
    if (((0 < iVar6) && (iVar6 < 9)) && (iVar1 != 0)) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar6);
      T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar4);
      T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar1);
      return;
    }
    break;
  case 6:
    if (*(int *)(param_1 + 0x480) != 0) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      T_Scenario::SetSPObject
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x480));
      return;
    }
    break;
  case 7:
    if ((0 < iVar6) && (iVar6 < 9)) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar6);
      T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar4);
      T_Scenario::SetSPAllFlag(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      return;
    }
    break;
  case 8:
    if ((0 < iVar6) && (iVar6 < 9)) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,1);
      T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar6);
      return;
    }
    break;
  case 9:
    if (*(int *)(param_1 + 0x480) != 0) {
      T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,5);
      T_Scenario::SetSPObject
                (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,
                 *(RGE_Static_Object **)(param_1 + 0x480));
      return;
    }
    break;
  case 10:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 0;
    goto LAB_004ae570;
  case 0xb:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 3;
    goto LAB_004ae570;
  case 0xc:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 1;
    goto LAB_004ae570;
  case 0xd:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 2;
    goto LAB_004ae570;
  case 0xe:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 4;
    goto LAB_004ae570;
  case 0xf:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,5);
    lVar3 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x748));
    T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar3 + 1);
    return;
  case 0x10:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,4);
    lVar3 = 6;
    goto LAB_004ae570;
  case 0x11:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,6);
    lVar3 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x744));
LAB_004ae570:
    T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar3);
LAB_004ae57f:
    T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,iVar1);
    return;
  case 0x12:
    T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,7);
    lVar3 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x74c));
    T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_3,lVar3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ae5cf
// Address: 004ae5cf
// XREFS: None
/* WARNING: Instruction at (ram,0x004ae631) overlaps instruction at (ram,0x004ae62f)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ae5cf(void)
{
  float *pfVar1;
  char cVar2;
  char extraout_AH;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  RGE_Static_Object *pRVar7;
  RGE_Static_Object *pRVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  int extraout_ECX;
  int iVar12;
  int extraout_EDX;
  int unaff_EBX;
  char *unaff_ESI;
  int unaff_EDI;
  char acStack_34 [44];
  int iStack_8;
  
  iStack_8 = 0x4ae5db;
  func_0xfd004ae1();
  *(char *)(unaff_EDI + -0x1e) = *(char *)(unaff_EDI + -0x1e) + extraout_AH;
  *(char *)(extraout_ECX + -0x4ffb51e) =
       *(char *)(extraout_ECX + -0x4ffb51e) + (char)extraout_EDX + -1;
  *(char *)(unaff_EBX + 0x4a) = *(char *)(unaff_EBX + 0x4a) + extraout_AH;
  *(char *)(unaff_EBX + 0x5004ae3) = *(char *)(unaff_EBX + 0x5004ae3) + extraout_AH;
  cVar2 = in(0x4a);
  *(char *)(extraout_EDX + -0x1d) = *(char *)(extraout_EDX + -0x1d) + cVar2;
  *(char *)(extraout_ECX + -0x66ffb51d) = *(char *)(extraout_ECX + -0x66ffb51d) + cVar2;
  in(0x4a);
  *(char *)(extraout_ECX + -0x36ffb51d) =
       *(char *)(extraout_ECX + -0x36ffb51d) + (char)((uint)(extraout_EDX + -2) >> 8);
  in(0x4a);
  iVar12 = CONCAT31((int3)((uint)(extraout_ECX + -1) >> 8),(char)(extraout_ECX + -1) + extraout_AH);
  in(0x4a);
  in(0x4a);
  *unaff_ESI = *unaff_ESI + (char)((uint)unaff_EBX >> 8);
  in(0x4a);
  *(char *)(unaff_EBX + -0x1b) = *(char *)(unaff_EBX + -0x1b) + (char)(extraout_EDX + -2);
  *(char *)(iVar12 + -0x6fffb51b) = *(char *)(iVar12 + -0x6fffb51b) + (char)unaff_EBX;
  iVar3 = T_Scenario::Get_victory_all_flag(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c));
  if (iVar3 == 0) {
    (**(code **)(**(int **)(iVar12 + 0x680) + 0xe0))(1);
    iVar4 = **(int **)(iVar12 + 0x684);
  }
  else {
    (**(code **)(**(int **)(iVar12 + 0x680) + 0xe0))(0);
    iVar4 = **(int **)(iVar12 + 0x684);
  }
  (**(code **)(iVar4 + 0xe0))(iVar3 != 0);
  iVar3 = iStack_8;
  if (-1 < iStack_8) {
    *(undefined4 *)(iVar12 + 0x480) = 0;
    *(undefined4 *)(iVar12 + 0x484) = 0;
    (**(code **)(**(int **)(*(int *)(iVar12 + 0x928) + 0x5c) + 8))();
    T_Scenario::SetSPWhich
              (*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),*(short *)(iVar12 + 0x4b8) + -1);
    iVar4 = T_Scenario::GetSPAmount(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    itoa(iVar4,acStack_34,10);
    TEditPanel::set_text(*(TEditPanel **)(iVar12 + 0x76c),acStack_34);
    iVar5 = T_Scenario::GetSPPlayerID(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    TDropDownPanel::set_line(*(TDropDownPanel **)(iVar12 + 0x740),iVar5 + -1);
    iVar5 = T_Scenario::GetSPObjectType(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(iVar12 + 0x738),iVar5);
    TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x738),lVar6);
    pRVar7 = T_Scenario::GetSPObject(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    pRVar8 = T_Scenario::GetSPDestObjectID(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    *(RGE_Static_Object **)(iVar12 + 0x480) = pRVar7;
    *(RGE_Static_Object **)(iVar12 + 0x484) = pRVar8;
    iVar5 = T_Scenario::GetSPVictoryType(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    iStack_8 = T_Scenario::GetSPAttribType(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
    pfVar1 = (float *)(iVar12 + 0x490);
    T_Scenario::GetSPRectangle
              (*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3,(float *)(iVar12 + 0x488),
               (float *)(iVar12 + 0x48c),pfVar1,(float *)(iVar12 + 0x494));
    lVar6 = __ftol();
    lVar9 = __ftol();
    lVar10 = __ftol();
    lVar11 = __ftol();
    RGE_View::set_selection_area(*(RGE_View **)(iVar12 + 0x4c8),-1,-1,-1,-1);
    if (*pfVar1 != _DAT_00573af0) {
      RGE_View::set_selection_area(*(RGE_View **)(iVar12 + 0x4c8),lVar6,lVar9,lVar10,lVar11);
    }
    switch(iVar5) {
    case 0:
      iVar3 = 0;
      break;
    case 1:
      if (iVar4 == 0) {
        if (pRVar7 == (RGE_Static_Object *)0x0) {
          iVar3 = T_Scenario::GetSPAllFlag(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
          if (iVar3 == 0) {
            iVar3 = 8;
          }
          else {
            iVar3 = 7;
          }
        }
        else {
          iVar3 = 6;
        }
      }
      else {
        iVar3 = 5;
      }
      break;
    case 2:
      T_Scenario::GetSPRectangle
                (*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3,(float *)(iVar12 + 0x488),
                 (float *)(iVar12 + 0x48c),pfVar1,(float *)(iVar12 + 0x494));
      if (*pfVar1 <= (float)_DAT_00573af8) {
        iVar3 = 3;
      }
      else {
        iVar3 = 4;
      }
      break;
    case 3:
      if (pRVar8 == (RGE_Static_Object *)0x0) {
        iVar3 = 2;
      }
      else {
        iVar3 = 1;
      }
      break;
    case 4:
      switch(iStack_8) {
      case 0:
        iVar3 = 10;
        break;
      case 1:
        iVar3 = 0xc;
        break;
      case 2:
        iVar3 = 0xd;
        break;
      case 3:
        iVar3 = 0xb;
        break;
      case 4:
        iVar3 = 0xe;
        break;
      case 5:
        TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x734),0xf);
        iVar3 = T_Scenario::GetSPAmount(*(T_Scenario **)(*(int *)(iVar12 + 0x928) + 0x5c),iVar3);
        TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x748),iVar3 + -1);
        return;
      case 6:
        iVar3 = 0x10;
        break;
      default:
        goto switchD_004ae82a_default;
      }
      break;
    case 5:
      if (pRVar7 == (RGE_Static_Object *)0x0) {
        return;
      }
      iVar3 = 9;
      break;
    case 6:
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x734),0x11);
      TDropDownPanel::setCurrentLineId(*(TDropDownPanel **)(iVar12 + 0x744),iStack_8);
      return;
    case 7:
      TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x734),0x12);
      TDropDownPanel::setCurrentLineId(*(TDropDownPanel **)(iVar12 + 0x74c),iStack_8);
      return;
    default:
      goto switchD_004ae82a_default;
    }
    TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(iVar12 + 0x734),iVar3);
  }
switchD_004ae82a_default:
  return;
}

// --------------------------------------------------

// Function: FUN_004aec95
// Address: 004aec95
// XREFS: None
void FUN_004aec95(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_004aed4b
// Address: 004aed4b
// XREFS: None
void __thiscall FUN_004aed4b(int param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (-1 < param_2) {
    iVar4 = 0;
    puVar2 = (undefined4 *)(param_1 + 0x908);
    puVar3 = (undefined4 *)(param_1 + 0x8ac);
    do {
      iVar1 = T_Scenario::Get_player_attitude
                        (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_2,iVar4);
      if (iVar1 == 0) {
        TButtonPanel::set_radio_button((TButtonPanel *)puVar3[-1]);
      }
      if (iVar1 == 1) {
        TButtonPanel::set_radio_button((TButtonPanel *)*puVar3);
      }
      if (iVar1 == 3) {
        TButtonPanel::set_radio_button((TButtonPanel *)puVar3[1]);
      }
      (**(code **)(*(int *)*puVar2 + 0xe0))(0);
      iVar4 = iVar4 + 1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 3;
    } while (iVar4 < 8);
    iVar4 = **(int **)(param_1 + 0x908 + param_2 * 4);
    iVar1 = T_Scenario::GetPlayerAlliedVictory
                      (*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),param_2);
    (**(code **)(iVar4 + 0xe0))(iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004aee03
// Address: 004aee03
// XREFS: None
void __thiscall FUN_004aee03(int *param_1,undefined4 param_2,int param_3)
{
  param_1[0x128] = 0;
  if (param_3 == 0) {
    (**(code **)(*(int *)param_1[0x1ce] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d4] + 0x14))(0);
    (**(code **)(*(int *)param_1[0x1d5] + 0x14))(0);
    (**(code **)(*(int *)param_1[0x1d6] + 0x14))(0);
    (**(code **)(*(int *)param_1[0x1da] + 0x14))(0);
    (**(code **)(*(int *)param_1[0x1d0] + 0x14))(0);
    (**(code **)(*(int *)param_1[0x1d1] + 0x14))(0);
    (**(code **)(*(int *)param_1[0x1d2] + 0x14))(0);
    (**(code **)(*(int *)param_1[0x1d3] + 0x14))(0);
    return;
  }
  TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)0x0);
  switch(param_2) {
  default:
    return;
  case 1:
    (**(code **)(*(int *)param_1[0x1d4] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d5] + 0x14))();
    return;
  case 2:
    (**(code **)(*(int *)param_1[0x1d4] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d5] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d6] + 0x14))();
    return;
  case 3:
    (**(code **)(*(int *)param_1[0x1ce] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x7766,-1);
    break;
  case 4:
    (**(code **)(*(int *)param_1[0x1ce] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x7767,-1);
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1db]);
    (**(code **)(*(int *)param_1[0x1d5] + 0x14))(param_3);
    (**(code **)(*(int *)param_1[0x1d6] + 0x14))(param_3);
    return;
  case 5:
    (**(code **)(*(int *)param_1[0x1ce] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    (**(code **)(*(int *)param_1[0x1da] + 0x14))(param_3);
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x7768,-1);
    (**(code **)(*(int *)param_1[0x1d0] + 0x14))(param_3);
    (**(code **)(*param_1 + 200))(&stack0xffffffe4,2);
    goto LAB_004af094;
  case 6:
  case 9:
    (**(code **)(*(int *)param_1[0x1d4] + 0x14))();
    return;
  case 7:
    (**(code **)(*(int *)param_1[0x1ce] + 0x14))();
    (**(code **)(*(int *)param_1[0x1da] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d0] + 0x14))();
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1d0]);
    return;
  case 8:
    (**(code **)(*(int *)param_1[0x1da] + 0x14))();
    (**(code **)(*(int *)param_1[0x1d0] + 0x14))();
LAB_004af094:
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1d0]);
    return;
  case 10:
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x7769,-1);
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1db]);
    return;
  case 0xb:
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x776a,-1);
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1db]);
    return;
  case 0xc:
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x776b,-1);
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1db]);
    return;
  case 0xd:
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x776c,-1);
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1db]);
    return;
  case 0xe:
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x776d,-1);
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1db]);
    return;
  case 0xf:
    (**(code **)(*(int *)param_1[0x1d2] + 0x14))();
    return;
  case 0x10:
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x776e,-1);
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    break;
  case 0x11:
    (**(code **)(*(int *)param_1[0x1d9] + 0x14))();
    (**(code **)(*(int *)param_1[0x1db] + 0x14))();
    TPanel::set_help_info((TPanel *)param_1[0x1db],0x776f,-1);
    TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1db]);
    (**(code **)(*(int *)param_1[0x1d1] + 0x14))();
    return;
  case 0x12:
    (**(code **)(*(int *)param_1[0x1d3] + 0x14))();
    return;
  }
  TPanel::set_curr_child((TPanel *)param_1[0x135],(TPanel *)param_1[0x1db]);
  return;
}

// --------------------------------------------------

// Function: FUN_004af2d2
// Address: 004af2d2
// XREFS: None
void FUN_004af2d2(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004af6bd
// Address: 004af6bd
// XREFS: None
// [HELPER] s_0: "0"
// [HELPER] s_1200: "1200"
// [HELPER] s_1500: "1500"
// [HELPER] s_1800: "1800"
// [HELPER] s_2100: "2100"
// [HELPER] s_2400: "2400"
// [HELPER] s_2700: "2700"
// [HELPER] s_3000: "3000"
// [HELPER] s_300: "300"
// [HELPER] s_400: "400"
// [HELPER] s_500: "500"
// [HELPER] s_600: "600"
// [HELPER] s_700: "700"
// [HELPER] s_800: "800"
// [HELPER] s_900: "900"
// [HELPER] s_: ""
// [HELPER] s__: "}"
// [HELPER] s__d: "%d"
// [HELPER] s__d_: "%d "
// [HELPER] s_btnbldg_d_shp: "btnbldg%d.shp"
// [HELPER] s_btnunit_shp: "btnunit.shp"
void __fastcall FUN_004af6bd(TRIBE_Screen_Sed *param_1)
{
  TListPanel **ppTVar1;
  TEditPanel **ppTVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  TShape *pTVar7;
  RGE_Font *pRVar8;
  TRIBE_Scenario_Editor_Panel_Object *pTVar9;
  TButtonPanel **ppTVar10;
  TDropDownPanel **ppTVar11;
  TButtonPanel **ppTVar12;
  TTextPanel **ppTVar13;
  TEditPanel **ppTVar14;
  TButtonPanel *(*papTVar15) [3];
  undefined4 *unaff_FS_OFFSET;
  long lVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iStack_1c8;
  TButtonPanel **ppTStack_1c4;
  TEditPanel *pTStack_1c0;
  TEditPanel *pTStack_1bc;
  TEditPanel *pTStack_1b8;
  TEditPanel *pTStack_1b4;
  char acStack_1b0 [20];
  char acStack_19c [20];
  char acStack_188 [140];
  char acStack_fc [100];
  char acStack_98 [140];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f54a;
  *unaff_FS_OFFSET = &uStack_c;
  ppTVar12 = param_1->scenario_mode_button;
  iVar5 = TRIBE_Screen_Sed::create_button(param_1,(TPanel *)param_1,ppTVar12,0x271a,1);
  if (iVar5 != 0) {
    TPanel::set_help_info((TPanel *)*ppTVar12,0x76c0,-1);
    iVar5 = TRIBE_Screen_Sed::create_button
                      (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 1,0x271b,1);
    if (iVar5 != 0) {
      TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[1],0x76c1,-1);
      iVar5 = TRIBE_Screen_Sed::create_button
                        (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 2,0x271c,1);
      if (iVar5 != 0) {
        TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[2],0x76c2,-1);
        iVar5 = TRIBE_Screen_Sed::create_button
                          (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 3,0x271d,1);
        if (iVar5 != 0) {
          TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[3],0x76c3,-1);
          iVar5 = TRIBE_Screen_Sed::create_button
                            (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 4,0x2722,1);
          if (iVar5 != 0) {
            TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[4],0x76c8,-1);
            iVar5 = TRIBE_Screen_Sed::create_button
                              (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 5,0x271e,1)
            ;
            if (iVar5 != 0) {
              TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[5],0x76c4,-1);
              iVar5 = TRIBE_Screen_Sed::create_button
                                (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 6,0x2723,
                                 1);
              if (iVar5 != 0) {
                TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[6],0x76c9,-1);
                iVar5 = TRIBE_Screen_Sed::create_button
                                  (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 7,
                                   0x2721,1);
                if (iVar5 != 0) {
                  TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[7],0x76c7,-1);
                  iVar5 = TRIBE_Screen_Sed::create_button
                                    (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 8,
                                     0x271f,1);
                  if (iVar5 != 0) {
                    TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[8],0x76c5,-1);
                    iVar5 = TRIBE_Screen_Sed::create_button
                                      (param_1,(TPanel *)param_1,param_1->scenario_mode_button + 9,
                                       0x2720,1);
                    if (iVar5 != 0) {
                      TPanel::set_help_info((TPanel *)param_1->scenario_mode_button[9],0x76c6,-1);
                      iVar5 = 10;
                      ppTVar10 = ppTVar12;
                      do {
                        TButtonPanel::set_radio_info(*ppTVar10,ppTVar12,10);
                        (**(code **)((*ppTVar10)->_padding_ + 0x14))(1);
                        ppTVar10 = ppTVar10 + 1;
                        iVar5 = iVar5 + -1;
                      } while (iVar5 != 0);
                      ppTVar12 = &param_1->menu_button;
                      iVar5 = TRIBE_Screen_Sed::create_button
                                        (param_1,(TPanel *)param_1,ppTVar12,0x2724,0);
                      if (iVar5 != 0) {
                        TPanel::set_help_info((TPanel *)*ppTVar12,0x774c,-1);
                        (**(code **)((*ppTVar12)->_padding_ + 0x14))(1);
                        iVar5 = TRIBE_Screen_Sed::create_button
                                          (param_1,(TPanel *)param_1,&param_1->help_button,0xfa9,0);
                        if (iVar5 != 0) {
                          (**(code **)(param_1->help_button->_padding_ + 0x14))(1);
                          iVar5 = TRIBE_Screen_Sed::create_text
                                            (param_1,param_1->bottom_panel,&param_1->map_type_label,
                                             0x29a6);
                          if (iVar5 != 0) {
                            ppTVar12 = param_1->map_type_button;
                            iVar5 = TRIBE_Screen_Sed::create_radio_button
                                              (param_1,param_1->bottom_panel,ppTVar12);
                            if (iVar5 != 0) {
                              TPanel::set_help_info((TPanel *)*ppTVar12,0x76cf,-1);
                              iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                (param_1,param_1->bottom_panel,
                                                 param_1->map_type_button + 1);
                              if (iVar5 != 0) {
                                TPanel::set_help_info
                                          ((TPanel *)param_1->map_type_button[1],0x76d0,-1);
                                iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                  (param_1,param_1->bottom_panel,
                                                   param_1->map_type_button + 2);
                                if (iVar5 != 0) {
                                  TPanel::set_help_info
                                            ((TPanel *)param_1->map_type_button[2],0x76d1,-1);
                                  iVar5 = TRIBE_Screen_Sed::create_text
                                                    (param_1,param_1->bottom_panel,
                                                     param_1->map_type_text,0x299c);
                                  if (iVar5 != 0) {
                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                      (param_1,param_1->bottom_panel,
                                                       param_1->map_type_text + 1,0x299d);
                                    if (iVar5 != 0) {
                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                        (param_1,param_1->bottom_panel,
                                                         param_1->map_type_text + 2,0x299e);
                                      if (iVar5 != 0) {
                                        iVar5 = TRIBE_Screen_Sed::create_text
                                                          (param_1,param_1->bottom_panel,
                                                           &param_1->default_terrain_label,0x299f);
                                        if (iVar5 != 0) {
                                          iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                            (param_1,param_1->bottom_panel,
                                                             &param_1->default_terrain_drop);
                                          if (iVar5 != 0) {
                                            TPanel::set_help_info
                                                      ((TPanel *)param_1->default_terrain_drop,
                                                       0x76d6,-1);
                                            iVar19 = 0;
                                            iVar18 = 1;
                                            iVar17 = 1;
                                            lVar16 = 1;
                                            lVar6 = TPanel::height((TPanel *)param_1);
                                            iVar5 = lVar6 + -200;
                                            lVar6 = TPanel::width((TPanel *)param_1);
                                            iVar5 = TEasy_Panel::create_text
                                                              ((TEasy_Panel *)param_1,
                                                               (TPanel *)param_1->main_view,
                                                               &param_1->map_generating_text,0x29a5,
                                                               0,0,lVar6,iVar5,lVar16,iVar17,iVar18,
                                                               iVar19);
                                            if (iVar5 != 0) {
                                              (**(code **)(param_1->map_generating_text->_padding_ +
                                                          0x14))(0);
                                              iVar5 = TRIBE_Screen_Sed::create_text
                                                                (param_1,param_1->bottom_panel,
                                                                 &param_1->map_size_label,0x29a0);
                                              if (iVar5 != 0) {
                                                iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                  (param_1,param_1->bottom_panel,
                                                                   &param_1->map_size_drop);
                                                if (iVar5 != 0) {
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->map_size_drop,0x76d2
                                                             ,-1);
                                                  iVar5 = TRIBE_Screen_Sed::create_text
                                                                    (param_1,param_1->bottom_panel,
                                                                     &param_1->map_style_label,
                                                                     0x29a1);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->map_style_drop);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)param_1->map_style_drop,
                                                                 0x76d3,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->random_seed_label,0x29a2);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_edit
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->random_seed_input,
                                                                       s_0,5,FormatUnsignedInt,0,0);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->random_seed_input,0x76d4,
                                                                 -1);
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->random_seed_used_label,
                                                  0x29a3);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  random_seed_used_text,s_0);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  generate_map_button,0x29a4,0);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->generate_map_button,0x76d5,
                                                               -1);
                                                    iVar5 = 3;
                                                    ppTVar10 = ppTVar12;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar10,ppTVar12,3);
                                                      ppTVar10 = ppTVar10 + 1;
                                                      iVar5 = iVar5 + -1;
                                                    } while (iVar5 != 0);
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->brush_size_label,
                                                                       0x29af);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->paint_terrain_label,0x29bc)
                                                  ;
                                                  if (iVar5 != 0) {
                                                    ppTVar12 = param_1->brush_size_button;
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,ppTVar12);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar12,0x76d9,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->brush_size_button + 1);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->brush_size_button[1],0x76da,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->brush_size_button +
                                                                        2);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->brush_size_button[2],
                                                                 0x76db,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->brush_size_button + 3);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->brush_size_button[3],0x76dc,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->brush_size_button +
                                                                        4);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->brush_size_button[4],
                                                                 0x76dd,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->brush_size_button_label,
                                                  0x29b0);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  brush_size_button_label + 1,0x29b1);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  brush_size_button_label + 2,0x29b2);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  brush_size_button_label + 3,0x29b3);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  brush_size_button_label + 4,0x29b4);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->paint_type_label,
                                                                       0x29b9);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->paint_type_button);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->paint_type_button[0],0x76de,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->paint_type_button +
                                                                        1);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->paint_type_button[1],
                                                                 0x76df,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->paint_type_button + 2);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->paint_type_button[2],0x76e0,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  paint_type_button_label,0x271a);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  paint_type_button_label + 1,0x2987);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  paint_type_button_label + 2,0x29ba);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_list
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->paint_terrain_list
                                                                       ,&param_1->
                                                  paint_terrain_scrollbar);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->paint_terrain_list
                                                               ,0x76e1,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_list
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  paint_elevation_list,
                                                  &param_1->paint_elevation_scrollbar);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->paint_elevation_list,0x76e2,
                                                               -1);
                                                    iVar5 = 5;
                                                    ppTVar10 = ppTVar12;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar10,ppTVar12,5);
                                                      ppTVar10 = ppTVar10 + 1;
                                                      iVar5 = iVar5 + -1;
                                                    } while (iVar5 != 0);
                                                    iVar5 = 3;
                                                    ppTVar12 = param_1->paint_type_button;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar12,
                                                                 param_1->paint_type_button,3);
                                                      ppTVar12 = ppTVar12 + 1;
                                                      iVar5 = iVar5 + -1;
                                                    } while (iVar5 != 0);
                                                    ppTVar12 = param_1->unit_mode_select;
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,ppTVar12);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar12,0x76f8,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->unit_mode_select + 1);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->unit_mode_select[1],0x76f7,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->unit_mode_select +
                                                                        2);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->unit_mode_select[2],0x76f9
                                                                 ,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->unit_mode_select + 3);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->unit_mode_select[3],0x76fa,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  unit_mode_select_label,0x2777);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  unit_mode_select_label + 1,0x2778);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  unit_mode_select_label + 2,0x2779);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  unit_mode_select_label + 3,0x277a);
                                                  if (iVar5 != 0) {
                                                    iVar5 = 4;
                                                    ppTVar10 = ppTVar12;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar10,ppTVar12,4);
                                                      ppTVar10 = ppTVar10 + 1;
                                                      iVar5 = iVar5 + -1;
                                                    } while (iVar5 != 0);
                                                    TButtonPanel::set_radio_button(*ppTVar12);
                                                    ppTVar1 = &param_1->unit_list;
                                                    iVar5 = TRIBE_Screen_Sed::create_list
                                                                      (param_1,(TPanel *)param_1,
                                                                       ppTVar1,&param_1->
                                                  unit_scrollbar);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar1,0x76fb,-1);
                                                    TPanel::set_z_order((TPanel *)*ppTVar1,'\x02',0)
                                                    ;
                                                    pTVar7 = (TShape *)operator_new(0x20);
                                                    uStack_4 = 0;
                                                    if (pTVar7 == (TShape *)0x0) {
                                                      pTVar7 = (TShape *)0x0;
                                                    }
                                                    else {
                                                      pTVar7 = (TShape *)
                                                               TShape::TShape(pTVar7,s_btnunit_shp,
                                                                              0xc62a);
                                                    }
                                                    uStack_4 = 0xffffffff;
                                                    param_1->button_unit_pics = pTVar7;
                                                    if (pTVar7 != (TShape *)0x0) {
                                                      iVar5 = TShape::is_loaded(pTVar7);
                                                      if (iVar5 != 0) {
                                                        iVar5 = 0;
                                                        do {
                                                          iVar17 = iVar5;
                                                          if (iVar5 == 4) {
                                                            iVar17 = 1;
                                                          }
                                                          sprintf(acStack_fc,s_btnbldg_d_shp,iVar17)
                                                          ;
                                                          pTVar7 = (TShape *)operator_new(0x20);
                                                          uStack_4 = 1;
                                                          if (pTVar7 == (TShape *)0x0) {
                                                            pTVar7 = (TShape *)0x0;
                                                          }
                                                          else {
                                                            pTVar7 = (TShape *)
                                                                     TShape::TShape(pTVar7,
                                                  acStack_fc,iVar17 + 0xc610);
                                                  }
                                                  uStack_4 = 0xffffffff;
                                                  param_1->button_bldg_pics[iVar17] = pTVar7;
                                                  if (pTVar7 == (TShape *)0x0) goto LAB_004b1a1f;
                                                  iVar17 = TShape::is_loaded(pTVar7);
                                                  if (iVar17 == 0) goto LAB_004b1a1f;
                                                  iVar5 = iVar5 + 1;
                                                  } while (iVar5 < 5);
                                                  ppTVar11 = &param_1->unit_player_list;
                                                  iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                    (param_1,param_1->bottom_panel,
                                                                     ppTVar11);
                                                  if (iVar5 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar11,0x76fc,-1);
                                                  pRVar8 = RGE_Base_Game::get_font(rge_base_game,10)
                                                  ;
                                                  pTVar9 = (TRIBE_Scenario_Editor_Panel_Object *)
                                                           operator_new(0x21c);
                                                  uStack_4 = 2;
                                                  if (pTVar9 == (TRIBE_Scenario_Editor_Panel_Object
                                                                 *)0x0) {
                                                    pTVar9 = (TRIBE_Scenario_Editor_Panel_Object *)
                                                             0x0;
                                                  }
                                                  else {
                                                    pTVar9 = (TRIBE_Scenario_Editor_Panel_Object *)
                                                             TRIBE_Scenario_Editor_Panel_Object::
                                                             TRIBE_Scenario_Editor_Panel_Object
                                                                       (pTVar9,(TDrawArea *)
                                                                               param_1->_padding_,
                                                                        (TPanel *)param_1,
                                                                        pRVar8->font,
                                                                        pRVar8->font_wid,
                                                                        pRVar8->font_hgt,
                                                                        param_1->button_unit_pics,
                                                                        param_1->button_bldg_pics,
                                                                        (TRIBE_Player *)0x0);
                                                  }
                                                  uStack_4 = 0xffffffff;
                                                  param_1->object_panel = pTVar9;
                                                  if ((pTVar9 != (TRIBE_Scenario_Editor_Panel_Object
                                                                  *)0x0) && (pTVar9->_padding_ == 0)
                                                     ) {
                                                    (**(code **)(pTVar9->_padding_ + 0x14))(0);
                                                    TPanel::set_z_order((TPanel *)*ppTVar11,'\x01',0
                                                                       );
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->player_label,
                                                                       0x2864);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->player_starting_age_label,
                                                  0x2815);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  player_advance_civilization_drop);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->
                                                  player_advance_civilization_drop,0x7765,-1);
                                                  TRIBE_Screen_Sed::
                                                  Set_player_advance_civilization_text(param_1,0);
                                                  iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                    (param_1,param_1->bottom_panel,
                                                                     &param_1->player_list);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->player_list,0x76e6
                                                               ,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->player_number_list
                                                                      );
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->player_number_list,0x76e7,
                                                                 -1);
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->player_inven_label,0x280b);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->player_inven_label
                                                                        + 1,0x280c);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->player_inven_label + 2,
                                                  0x280d);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->player_inven_label
                                                                        + 3,0x280e);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->player_inven_label + 4,
                                                  0x2805);
                                                  if (iVar5 != 0) {
                                                    iVar5 = 0;
                                                    ppTVar14 = param_1->player_inven_input;
                                                    do {
                                                      iVar17 = TRIBE_Screen_Sed::create_edit
                                                                         (param_1,param_1->
                                                  bottom_panel,ppTVar14,s_0,5,FormatUnsignedInt,0,0)
                                                  ;
                                                  if (iVar17 == 0) goto LAB_004b1a29;
                                                  iVar5 = iVar5 + 1;
                                                  ppTVar14 = ppTVar14 + 1;
                                                  } while (iVar5 < 4);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->player_inven_input[0],0x76e8,1
                                                            );
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->player_inven_input[1],0x76e9,1
                                                            );
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->player_inven_input[2],0x76eb,1
                                                            );
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->player_inven_input[3],0x76ea,1
                                                            );
                                                  iVar5 = TRIBE_Screen_Sed::create_edit
                                                                    (param_1,param_1->bottom_panel,
                                                                     param_1->player_inven_input + 4
                                                                     ,s_,0x1c,FormatText,1,1);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->player_inven_input[4],0x76ec
                                                               ,1);
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  player_setting_label,0x2810);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  player_setting_label + 1,0x2811);
                                                  if (iVar5 != 0) {
                                                    iVar5 = 0;
                                                    ppTVar11 = param_1->player_setting_drop;
                                                    do {
                                                      iVar17 = TRIBE_Screen_Sed::create_drop_down
                                                                         (param_1,param_1->
                                                  bottom_panel,ppTVar11);
                                                  if (iVar17 == 0) goto LAB_004b1a29;
                                                  iVar5 = iVar5 + 1;
                                                  ppTVar11 = ppTVar11 + 1;
                                                  } while (iVar5 < 2);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->player_setting_drop[0],0x76ed,
                                                             -1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->player_setting_drop[1],0x76ee,
                                                             -1);
                                                  iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                    (param_1,param_1->bottom_panel,
                                                                     &param_1->BuildList);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->BuildList,0x76ef,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->CityLayout);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)param_1->CityLayout,
                                                                 0x76f0,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->AiRules);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->AiRules,0x76f1,-1)
                                                    ;
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->player_build_text,
                                                                       0x2813);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->player_city_text,0x2814);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->AiRules_text,
                                                                       0x2812);
                                                    if (iVar5 != 0) {
                                                      pcVar3 = *(code **)(param_1->_padding_ + 200);
                                                      (*pcVar3)(param_1->player_inven_input,5);
                                                      iVar5 = TRIBE_Screen_Sed::create_check_box
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->victory_cond_on);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->victory_cond_on[0]
                                                               ,0x7704,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_check_box
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->victory_cond_on + 1
                                                                      );
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->victory_cond_on[1],0x7706,
                                                                 -1);
                                                      iVar5 = TRIBE_Screen_Sed::create_check_box
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->victory_cond_on + 2);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->victory_cond_on[2]
                                                               ,0x7707,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_check_box
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->victory_cond_on + 3
                                                                      );
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->victory_cond_on[3],0x7708,
                                                                 -1);
                                                      iVar5 = TRIBE_Screen_Sed::create_check_box
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->victory_cond_on + 4);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->victory_cond_on[4]
                                                               ,0x7709,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_check_box
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->victory_cond_on + 5
                                                                      );
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->victory_cond_on[5],0x770a,
                                                                 -1);
                                                      ppTVar12 = param_1->victory_and_or;
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,ppTVar12);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar12,0x7701,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->victory_and_or + 1)
                                                    ;
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->victory_and_or[1],0x7703,
                                                                 -1);
                                                      iVar5 = 2;
                                                      ppTVar10 = ppTVar12;
                                                      do {
                                                        TButtonPanel::set_radio_info
                                                                  (*ppTVar10,ppTVar12,2);
                                                        ppTVar10 = ppTVar10 + 1;
                                                        iVar5 = iVar5 + -1;
                                                      } while (iVar5 != 0);
                                                      TButtonPanel::set_radio_button(*ppTVar12);
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->victory_text_and_or,0x28a2);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->victory_text_and_or
                                                                        + 1,0x28a3);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->victory_amount_label,0x28a4
                                                  );
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->victory_long_label
                                                                       ,0x28a5);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->victory_condition_label,
                                                  0x10e0);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_label_conquest,0x10e1);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_label_explore,0x10e2);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_label_explore_percent,0x10e7);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_label_ruins,0x10e3);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_label_artifacts,0x10e4);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_label_discoveries,0x10e5);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->victory_label_gold
                                                                       ,0x10e6);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_edit
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->victory_condition_explore,
                                                  &s__,3,FormatUnsignedInt,0,0);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_condition_explore,
                                                               0x770b,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_edit
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_condition_ruins,&s__,2,FormatUnsignedInt,0
                                                  ,0);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_condition_ruins,
                                                               0x770c,-1);
                                                    ppTVar14 = &param_1->victory_condition_artifacts
                                                    ;
                                                    iVar5 = TRIBE_Screen_Sed::create_edit
                                                                      (param_1,param_1->bottom_panel
                                                                       ,ppTVar14,&s__,2,
                                                                       FormatUnsignedInt,0,0);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar14,0x770d,-1);
                                                      ppTVar2 = &param_1->
                                                  victory_condition_discoveries;
                                                  iVar5 = TRIBE_Screen_Sed::create_edit
                                                                    (param_1,param_1->bottom_panel,
                                                                     ppTVar2,&s__,2,
                                                                     FormatUnsignedInt,0,0);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)*ppTVar2,0x770e,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_edit
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_condition_gold,&s__,5,FormatUnsignedInt,0,
                                                  0);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_condition_gold,
                                                               0x770f,-1);
                                                    pTStack_1bc = param_1->victory_condition_ruins;
                                                    pTStack_1c0 = param_1->victory_condition_explore
                                                    ;
                                                    pTStack_1b8 = *ppTVar14;
                                                    pTStack_1b4 = *ppTVar2;
                                                    (*pcVar3)(&pTStack_1c0,4);
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  victory_cond_type_label,0x10ec);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  victory_cond_type_label + 1,0x10e1);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  victory_cond_type_label + 2,0x10ea);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  victory_cond_type_label + 3,0x10e9);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  victory_cond_type_label + 4,0x10eb);
                                                  if (iVar5 != 0) {
                                                    ppTVar12 = param_1->victory_cond_type;
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,ppTVar12);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar12,0x7756,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->victory_cond_type + 1);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_cond_type[1],0x7757,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->victory_cond_type +
                                                                        2);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->victory_cond_type[2],
                                                                 0x7758,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->victory_cond_type + 3);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_cond_type[3],0x7759,
                                                               -1);
                                                    iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->victory_cond_type +
                                                                        4);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)
                                                                 param_1->victory_cond_type[4],
                                                                 0x775a,-1);
                                                      iVar5 = 5;
                                                      ppTVar10 = ppTVar12;
                                                      do {
                                                        TButtonPanel::set_radio_info
                                                                  (*ppTVar10,ppTVar12,5);
                                                        ppTVar10 = ppTVar10 + 1;
                                                        iVar5 = iVar5 + -1;
                                                      } while (iVar5 != 0);
                                                      TButtonPanel::set_radio_button
                                                                (param_1->victory_cond_type[1]);
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->victory_score_label,0x10ea)
                                                  ;
                                                  if (iVar5 != 0) {
                                                    ppTVar11 = &param_1->victory_score;
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,ppTVar11);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar11,0x775b,-1);
                                                      TDropDownPanel::empty_list(*ppTVar11);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_3000,3000);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_2700,0xa8c);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_2400,0x960);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_2100,0x834);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_1800,0x708);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_1500,0x5dc);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_1200,0x4b0);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_900,900);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_800,800);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_700,700);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_600,600);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_500,500);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_400,400);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,s_300,300);
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->victory_time_label,0x10e9);
                                                  if (iVar5 != 0) {
                                                    ppTVar11 = &param_1->victory_time;
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,ppTVar11);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)*ppTVar11,0x775c,-1);
                                                      TDropDownPanel::empty_list(*ppTVar11);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,0x2634,15000);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,0x2635,13000);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,0x2636,11000);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,0x2637,9000);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,0x2638,7000);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,0x2639,5000);
                                                      TDropDownPanel::append_line
                                                                (*ppTVar11,0x263a,3000);
                                                      ppTVar12 = param_1->victory_button;
                                                      iVar5 = 1;
                                                      do {
                                                        sprintf(acStack_188,&s__d,iVar5);
                                                        sprintf(acStack_98,s_<_d>,iVar5);
                                                        sprintf(acStack_19c,s__d_,iVar5);
                                                        sprintf(acStack_1b0,s_<_d*>,iVar5);
                                                        iVar17 = TRIBE_Screen_Sed::create_button
                                                                           (param_1,param_1->
                                                  bottom_panel,ppTVar12,acStack_188,acStack_98,
                                                  acStack_19c,acStack_1b0);
                                                  if (iVar17 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar12,0x7712,-1);
                                                  ppTVar12 = ppTVar12 + 1;
                                                  bVar4 = iVar5 < 0xc;
                                                  iVar5 = iVar5 + 1;
                                                  } while (bVar4);
                                                  iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                    (param_1,param_1->bottom_panel,
                                                                     &param_1->victory_drop_down);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_object_list);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_player_list);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_enemy_player_list);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_attribute_list);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->victory_ages_list)
                                                    ;
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                        (param_1,param_1->
                                                  bottom_panel,&param_1->victory_tech_list);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->victory_drop_down,
                                                               0x7716,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_object_list,0x7714,
                                                               -1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_player_list,0x7713,
                                                               -1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->victory_ages_list,
                                                               0x7715,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_enemy_player_list,
                                                               0x7760,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_attribute_list,
                                                               0x7761,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)param_1->victory_tech_list,
                                                               0x7762,-1);
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_condition_text,0x2870);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_condition_type,0x2871);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_button_set_object,0x2872,0);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_button_set_destination,0x2873,0);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_button
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_button_go_to_dest,0x2874,0);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->victory_button_set_object,
                                                               0x7717,-1);
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->
                                                  victory_button_set_destination,0x7718,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->victory_button_go_to_dest,
                                                             0x7719,-1);
                                                  iVar5 = TRIBE_Screen_Sed::create_text
                                                                    (param_1,param_1->bottom_panel,
                                                                     &param_1->victory_amount_text,
                                                                     0x2875);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_which_enemy_text,0x2876);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_edit
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  victory_amount_input,s_0,5,FormatUnsignedInt,0,0);
                                                  if (iVar5 != 0) {
                                                    ppTVar12 = param_1->message_button;
                                                    iVar5 = 0;
                                                    ppTVar10 = ppTVar12;
                                                    do {
                                                      iVar17 = TRIBE_Screen_Sed::create_radio_button
                                                                         (param_1,param_1->
                                                  bottom_panel,ppTVar10);
                                                  if (iVar17 == 0) goto LAB_004b1a29;
                                                  iVar5 = iVar5 + 1;
                                                  ppTVar10 = ppTVar10 + 1;
                                                  } while (iVar5 < 5);
                                                  param_1->current_message = 0;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar12,0x771c,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->message_button[1],
                                                             0x771d,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->message_button[2],
                                                             0x771e,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->message_button[3],
                                                             0x771f,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->message_button[4],
                                                             0x7720,-1);
                                                  iVar5 = TRIBE_Screen_Sed::create_text
                                                                    (param_1,param_1->bottom_panel,
                                                                     param_1->message_button_label,
                                                                     0x2a36);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  message_button_label + 1,0x2a37);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  message_button_label + 2,0x2a38);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  message_button_label + 3,0x2a39);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  message_button_label + 4,0x2a31);
                                                  if (iVar5 != 0) {
                                                    iVar5 = 5;
                                                    ppTVar10 = ppTVar12;
                                                    do {
                                                      TButtonPanel::set_radio_info
                                                                (*ppTVar10,ppTVar12,5);
                                                      ppTVar10 = ppTVar10 + 1;
                                                      iVar5 = iVar5 + -1;
                                                    } while (iVar5 != 0);
                                                    iVar5 = TRIBE_Screen_Sed::create_edit
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->message_input,s_,
                                                                       0xfff,FormatMultiLine,1,1);
                                                    if (iVar5 != 0) {
                                                      TPanel::set_help_info
                                                                ((TPanel *)param_1->message_input,-1
                                                                 ,-1);
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->cinematic_label,0x2af9);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->cinematic_label + 1
                                                                       ,0x2afa);
                                                    if (iVar5 != 0) {
                                                      iVar5 = TRIBE_Screen_Sed::create_text
                                                                        (param_1,param_1->
                                                  bottom_panel,param_1->cinematic_label + 2,0x2afb);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->cinematic_label + 3
                                                                       ,0x2afc);
                                                    if (iVar5 != 0) {
                                                      iVar5 = 0;
                                                      ppTVar11 = param_1->cinematic_input;
                                                      do {
                                                        iVar17 = TRIBE_Screen_Sed::create_drop_down
                                                                           (param_1,param_1->
                                                  bottom_panel,ppTVar11);
                                                  if (iVar17 == 0) goto LAB_004b1a29;
                                                  iVar5 = iVar5 + 1;
                                                  ppTVar11 = ppTVar11 + 1;
                                                  } while (iVar5 < 4);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->cinematic_input[0],
                                                             0x7724,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->cinematic_input[1],
                                                             0x7725,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->cinematic_input[2],
                                                             0x7726,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->cinematic_input[3],
                                                             0x7727,-1);
                                                  iVar5 = TRIBE_Screen_Sed::create_text
                                                                    (param_1,param_1->bottom_panel,
                                                                     param_1->options_label,0x2604);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,&param_1->
                                                  options_disable_tech_text,0x32d7);
                                                  if (iVar5 != 0) {
                                                    iVar5 = 0;
                                                    ppTVar12 = param_1->options_button;
                                                    do {
                                                      iVar17 = TRIBE_Screen_Sed::create_check_box
                                                                         (param_1,param_1->
                                                  bottom_panel,ppTVar12);
                                                  if (iVar17 == 0) goto LAB_004b1a29;
                                                  iVar5 = iVar5 + 1;
                                                  ppTVar12 = ppTVar12 + 1;
                                                  } while (iVar5 < 1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)param_1->options_button[0],
                                                             0x7729,-1);
                                                  iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                    (param_1,param_1->bottom_panel,
                                                                     &param_1->options_player_list);
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->options_player_list,0x772b,
                                                               -1);
                                                    iVar5 = 0;
                                                    ppTVar12 = param_1->options_disable_button;
                                                    do {
                                                      iVar17 = TRIBE_Screen_Sed::create_check_box
                                                                         (param_1,param_1->
                                                  bottom_panel,ppTVar12);
                                                  if (iVar17 == 0) goto LAB_004b1a29;
                                                  iVar5 = iVar5 + 1;
                                                  ppTVar12 = ppTVar12 + 1;
                                                  } while (iVar5 < 0x10);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[0],
                                                             0x772c,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[1],
                                                             0x772d,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[2],
                                                             0x772e,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[3],
                                                             0x772f,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[4],
                                                             0x7730,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[5],
                                                             0x7731,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[6],
                                                             0x7732,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[7],
                                                             0x7733,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[8],
                                                             0x7734,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[9],
                                                             0x7735,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[10],
                                                             0x7736,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[0xb],
                                                             0x7737,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[0xc],
                                                             0x7738,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[0xd],
                                                             0x7739,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[0xe],
                                                             0x773a,-1);
                                                  TPanel::set_help_info
                                                            ((TPanel *)
                                                             param_1->options_disable_button[0xf],
                                                             0x773b,-1);
                                                  iVar5 = TRIBE_Screen_Sed::create_text
                                                                    (param_1,param_1->bottom_panel,
                                                                     param_1->options_disable_text,
                                                                     0x32c9);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 1,0x32ca);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 2,0x32cb);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 3,0x32cc);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 4,0x32cd);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 5,0x32ce);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 6,0x32cf);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 7,0x32d0);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 8,0x32d1);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 9,0x32d2);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 10,0x32d3);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 0xb,0x32d4);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 0xc,0x32d5);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 0xd,0x32d6);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 0xe,0x32d8);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  options_disable_text + 0xf,0x32d9);
                                                  if (iVar5 != 0) {
                                                    iVar5 = 0;
                                                    ppTVar13 = param_1->Diplomacy_player_text;
                                                    do {
                                                      iVar5 = iVar5 + 1;
                                                      sprintf(acStack_188,&s__d,iVar5);
                                                      iVar17 = TRIBE_Screen_Sed::create_text
                                                                         (param_1,param_1->
                                                  bottom_panel,ppTVar13,acStack_188);
                                                  if (iVar17 == 0) goto LAB_004b1a29;
                                                  ppTVar13 = ppTVar13 + 1;
                                                  } while (iVar5 < 8);
                                                  iVar5 = TRIBE_Screen_Sed::create_drop_down
                                                                    (param_1,param_1->bottom_panel,
                                                                     &param_1->Diplomacy_player_list
                                                                    );
                                                  if (iVar5 != 0) {
                                                    TPanel::set_help_info
                                                              ((TPanel *)
                                                               param_1->Diplomacy_player_list,0x773d
                                                               ,-1);
                                                    ppTStack_1c4 = param_1->Diplomacy_AlliedVictory;
                                                    iStack_1c8 = 0;
                                                    papTVar15 = param_1->Diplomacy_friend_box;
                                                    do {
                                                      iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                        (param_1,param_1->
                                                  bottom_panel,*papTVar15);
                                                  if (iVar5 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)(*papTVar15)[0],0x773f,-1);
                                                  ppTVar12 = *papTVar15 + 1;
                                                  iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                    (param_1,param_1->bottom_panel,
                                                                     ppTVar12);
                                                  if (iVar5 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar12,0x7740,-1);
                                                  ppTVar10 = *papTVar15 + 2;
                                                  iVar5 = TRIBE_Screen_Sed::create_radio_button
                                                                    (param_1,param_1->bottom_panel,
                                                                     ppTVar10);
                                                  if (iVar5 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTVar10,0x7741,-1);
                                                  TButtonPanel::set_radio_info
                                                            ((*papTVar15)[0],*papTVar15,3);
                                                  TButtonPanel::set_radio_info
                                                            (*ppTVar12,*papTVar15,3);
                                                  TButtonPanel::set_radio_info
                                                            (*ppTVar10,*papTVar15,3);
                                                  TButtonPanel::set_radio_button(*ppTVar12);
                                                  iVar5 = TRIBE_Screen_Sed::create_check_box
                                                                    (param_1,param_1->bottom_panel,
                                                                     ppTStack_1c4);
                                                  if (iVar5 == 0) goto LAB_004b1a29;
                                                  TPanel::set_help_info
                                                            ((TPanel *)*ppTStack_1c4,0x773e,-1);
                                                  ppTStack_1c4 = ppTStack_1c4 + 1;
                                                  iStack_1c8 = iStack_1c8 + 1;
                                                  papTVar15 = papTVar15 + 1;
                                                  } while (iStack_1c8 < 8);
                                                  iVar5 = TRIBE_Screen_Sed::create_text
                                                                    (param_1,param_1->bottom_panel,
                                                                     param_1->Diplomacy_status_label
                                                                     ,0x29cd);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  Diplomacy_status_label + 1,0x29ce);
                                                  if (iVar5 != 0) {
                                                    iVar5 = TRIBE_Screen_Sed::create_text
                                                                      (param_1,param_1->bottom_panel
                                                                       ,param_1->
                                                  Diplomacy_status_label + 2,0x29cf);
                                                  if (iVar5 != 0) {
                                                    TRIBE_Screen_Sed::create_text
                                                              (param_1,param_1->bottom_panel,
                                                               param_1->Diplomacy_status_label + 3,
                                                               0x29d0);
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
                                                  goto LAB_004b1a29;
                                                  }
                                                  }
                                                  }
LAB_004b1a1f:
                                                  param_1->_padding_ = 1;
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
LAB_004b1a29:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004b1a42
// Address: 004b1a42
// XREFS: None
void __fastcall FUN_004b1a42(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  TTextPanel *this;
  uint uVar7;
  
  if (*(int *)(param_1 + 0x4c8) != 0) {
    iVar6 = 0;
    do {
      if (iVar6 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x4d4 + iVar6 * 4);
      }
      (**(code **)(**(int **)(param_1 + 0x4d8 + iVar6 * 4) + 0x18))
                (7,2,2,2,2,0x32,0x6d,0x16,0x16,uVar1,0,0,0);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 5);
    iVar6 = 5;
    do {
      if (iVar6 == 5) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x4d4 + iVar6 * 4);
      }
      (**(code **)(**(int **)(param_1 + 0x4d8 + iVar6 * 4) + 0x18))
                (7,2,2,2,2,0x32,0x6d,0x16,0x16,uVar1,*(undefined4 *)(param_1 + 0x4c4 + iVar6 * 4),0,
                 0);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 10);
    (**(code **)(**(int **)(param_1 + 0x500) + 0x18))(9,2,5,3,3,0x3a,0x3a,0x14,0x28,0,0,0,0);
    (**(code **)(**(int **)(param_1 + 0x504) + 0x18))(10,5,5,5,5,0x14,0x1e,0x14,0x1e,0,0,0,0);
    (**(code **)(**(int **)(param_1 + 0x4cc) + 0x18))(10,0,0,0,0,0xe6,0xe6,0x87,0x87,0,0,0,0);
    (**(code **)(**(int **)(param_1 + 0x4d4) + 0x18))
              (8,2,2,2,2,0,0,0x89,0x89,0,0,*(undefined4 *)(param_1 + 0x4cc),0);
    (**(code **)(**(int **)(param_1 + 0x63c) + 0x18))
              (7,0,6,0,4,0x7c,200,0,0,0,*(undefined4 *)(param_1 + 0x500),0,
               *(undefined4 *)(param_1 + 0x4d4));
    (**(code **)(**(int **)(param_1 + 0x660) + 0x18))(8,4,4,4,4,0x96,0x96,0x6c,0x6c,0,0,0,0);
    this = *(TTextPanel **)(param_1 + 0x63c);
    iVar6 = TTextPanel::numberLines(this);
    iVar2 = TTextPanel::numberDrawLines(this);
    if (iVar2 < iVar6) {
      (**(code **)(**(int **)(param_1 + 0x63c) + 0x18))
                (7,0,6,0,4,0x68,0xdc,0,0,0,*(undefined4 *)(param_1 + 0x500),0,
                 *(undefined4 *)(param_1 + 0x4d4));
      (**(code **)(**(int **)(param_1 + 0x640) + 0x18))
                (7,1,1,0,2,0x12,0x12,0,0,*(undefined4 *)(param_1 + 0x63c),
                 *(undefined4 *)(param_1 + 0x500),0,*(undefined4 *)(param_1 + 0x4d4));
      this = *(TTextPanel **)(param_1 + 0x640);
    }
    (**(code **)(**(int **)(param_1 + 0x4c8) + 0x18))
              (7,0,6,0,4,0,0,0,0,this,*(undefined4 *)(param_1 + 0x500),0,
               *(undefined4 *)(param_1 + 0x4d4));
    (**(code **)(**(int **)(param_1 + 0x4d0) + 0x18))(8,4,4,4,4,0,0,0x18,0x18,0,0,0,0);
    (**(code **)(**(int **)(param_1 + 0x520) + 0x1c))(4,4,0x78,0x16);
    (**(code **)(**(int **)(param_1 + 0x508) + 0x1c))(4,0x16,0x16,0x16);
    (**(code **)(**(int **)(param_1 + 0x50c) + 0x1c))(4,0x2c,0x16,0x16);
    (**(code **)(**(int **)(param_1 + 0x510) + 0x1c))(4,0x42,0x16,0x16);
    (**(code **)(**(int **)(param_1 + 0x514) + 0x1c))(0x24,0x16,0x73,0x16);
    (**(code **)(**(int **)(param_1 + 0x518) + 0x1c))(0x24,0x2c,0x73,0x16);
    (**(code **)(**(int **)(param_1 + 0x51c) + 0x1c))(0x24,0x42,0x73,0x16);
    (**(code **)(**(int **)(param_1 + 0x52c) + 0x1c))(0xaa,4,0x82,0x16);
    (**(code **)(**(int **)(param_1 + 0x530) + 0x1c))(0xaa,0x16,0xaa,0x16);
    (**(code **)(**(int **)(param_1 + 0x534) + 0x1c))(0xaa,0x30,0x82,0x16);
    (**(code **)(**(int **)(param_1 + 0x538) + 0x1c))(0xaa,0x42,0xaa,0x16);
    (**(code **)(**(int **)(param_1 + 0x524) + 0x1c))(0xaa,0x30,0x82,0x16);
    (**(code **)(**(int **)(param_1 + 0x528) + 0x1c))(0xaa,0x42,0xaa,0x16);
    (**(code **)(**(int **)(param_1 + 0x53c) + 0x1c))(0x24,0x5a,0x78,0x16);
    (**(code **)(**(int **)(param_1 + 0x540) + 0x1c))(0x24,0x70,0x37,0x16);
    (**(code **)(**(int **)(param_1 + 0x544) + 0x1c))(0x24,0x5a,0x78,0x16);
    (**(code **)(**(int **)(param_1 + 0x548) + 0x1c))(0x24,0x70,0x37,0x16);
    (**(code **)(**(int **)(param_1 + 0x54c) + 0x1c))(0xb4,0x60,0x82,0x26);
    (**(code **)(**(int **)(param_1 + 0x5a0) + 0x1c))(0x73,0x17,0xa5,0x6e);
    (**(code **)(**(int **)(param_1 + 0x59c) + 0x1c))(0x73,1,0x3c,0x16);
    (**(code **)(**(int **)(param_1 + 0x5a8) + 0x1c))(0x73,0x17,0xa5,0x6e);
    (**(code **)(**(int **)(param_1 + 0x580) + 0x1c))(2,1,0x6e,0x14);
    (**(code **)(**(int **)(param_1 + 0x584) + 0x1c))(2,0x17,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x588) + 0x1c))(2,0x2d,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x58c) + 0x1c))(2,0x43,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x590) + 0x1c))(0x21,0x17,0x51,0x16);
    (**(code **)(**(int **)(param_1 + 0x594) + 0x1c))(0x21,0x2d,0x51,0x16);
    (**(code **)(**(int **)(param_1 + 0x598) + 0x1c))(0x21,0x43,0x51,0x16);
    (**(code **)(**(int **)(param_1 + 0x554) + 0x1c))(0x118,4,0x6e,0x14);
    (**(code **)(**(int **)(param_1 + 0x558) + 0x1c))(0x11a,0x17,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x55c) + 0x1c))(0x11a,0x2d,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x560) + 0x1c))(0x11a,0x43,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x564) + 0x1c))(0x11a,0x59,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x568) + 0x1c))(0x11a,0x6f,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x56c) + 0x1c))(0x139,0x17,0x5a,0x16);
    (**(code **)(**(int **)(param_1 + 0x570) + 0x1c))(0x139,0x2d,0x5a,0x16);
    (**(code **)(**(int **)(param_1 + 0x574) + 0x1c))(0x139,0x43,0x5a,0x16);
    (**(code **)(**(int **)(param_1 + 0x578) + 0x1c))(0x139,0x59,0x5a,0x16);
    (**(code **)(**(int **)(param_1 + 0x57c) + 0x1c))(0x139,0x6f,0x5a,0x16);
    (**(code **)(**(int **)(param_1 + 0x5b0) + 0x1c))(4,4,0x50,0x12);
    (**(code **)(**(int **)(param_1 + 0x5f4) + 0x1c))(4,0x5c,0x5f,0x12);
    (**(code **)(**(int **)(param_1 + 0x5bc) + 0x1c))(4,0x6e,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x5b0) + 0x1c))(4,0x2a,0x96,0x12);
    (**(code **)(**(int **)(param_1 + 0x5b4) + 0x1c))(4,7,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x5b8) + 0x1c))(4,0x3e,0x96,0x16);
    iVar6 = 0xa6;
    puVar4 = (undefined4 *)(param_1 + 0x5d8);
    do {
      iVar2 = 0x19;
      do {
        (**(code **)(*(int *)puVar4[-5] + 0x1c))(iVar6,iVar2 + -0x12,0x37,0x12);
        (**(code **)(*(int *)*puVar4 + 0x1c))(iVar6,iVar2,0x37,0x16);
        iVar2 = iVar2 + 0x2c;
        puVar4 = puVar4 + 1;
      } while (iVar2 < 0x71);
      iVar6 = iVar6 + 0x44;
    } while (iVar6 < 0x12e);
    (**(code **)(**(int **)(param_1 + 0x5d4) + 0x1c))(0xa6,0x5c,100,0x12);
    (**(code **)(**(int **)(param_1 + 0x5e8) + 0x1c))(0xa6,0x6e,0x7d,0x16);
    iVar6 = 0x19;
    puVar4 = (undefined4 *)(param_1 + 0x5f8);
    do {
      (**(code **)(*(int *)puVar4[-3] + 0x1c))(500,iVar6 + -0x12,0x82,0x12);
      (**(code **)(*(int *)*puVar4 + 0x1c))(500,iVar6,0x82,0x16);
      iVar6 = iVar6 + 0x2c;
      puVar4 = puVar4 + 1;
    } while (iVar6 < 0x71);
    (**(code **)(**(int **)(param_1 + 0x600) + 0x1c))(300,0x45,0xbe,0x16);
    (**(code **)(**(int **)(param_1 + 0x604) + 0x1c))(300,0x19,0xbe,0x16);
    (**(code **)(**(int **)(param_1 + 0x60c) + 0x1c))(300,0x33,0x82,0x12);
    (**(code **)(**(int **)(param_1 + 0x610) + 0x1c))(300,7,0x82,0x12);
    (**(code **)(**(int **)(param_1 + 0x614) + 0x1c))(300,0x5c,0x82,0x12);
    (**(code **)(**(int **)(param_1 + 0x608) + 0x1c))(300,0x6e,0xbe,0x16);
    (**(code **)(**(int **)(param_1 + 0x618) + 0x1c))(4,4,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x61c) + 0x1c))(0xa0,0x16,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x620) + 0x1c))(0xa0,0x30,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x624) + 0x1c))(0xa0,0x4a,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x628) + 0x1c))(0xa0,0x62,0x1e,0x16);
    (**(code **)(**(int **)(param_1 + 0x62c) + 0x1c))(0xc0,0x16,0x6e,0x16);
    (**(code **)(**(int **)(param_1 + 0x630) + 0x1c))(0xc0,0x30,0x6e,0x16);
    (**(code **)(**(int **)(param_1 + 0x634) + 0x1c))(0xc0,0x4a,0x6e,0x16);
    (**(code **)(**(int **)(param_1 + 0x638) + 0x1c))(0xc0,0x62,0x6e,0x16);
    (**(code **)(**(int **)(param_1 + 0x688) + 0x1c))(0x22,0,0x78,0x12);
    (**(code **)(**(int **)(param_1 + 0x6e0) + 0x1c))(0xe,0x12,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x6e4) + 0x1c))(0xe,0x26,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x6e8) + 0x1c))(0xe,0x3a,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x6ec) + 0x1c))(0xe,0x4e,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x6f0) + 0x1c))(0xe,0x62,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x6cc) + 0x1c))(0x22,0x12,0x78,0x12);
    (**(code **)(**(int **)(param_1 + 0x6d0) + 0x1c))(0x22,0x26,0x78,0x12);
    (**(code **)(**(int **)(param_1 + 0x6d4) + 0x1c))(0x22,0x3a,0x78,0x12);
    (**(code **)(**(int **)(param_1 + 0x6d8) + 0x1c))(0x22,0x4e,0x78,0x12);
    (**(code **)(**(int **)(param_1 + 0x6dc) + 0x1c))(0x22,0x62,0x78,0x12);
    (**(code **)(**(int **)(param_1 + 0x6f4) + 0x1c))(0xa4,0x12,100,0x12);
    (**(code **)(**(int **)(param_1 + 0x6f8) + 0x1c))(0xa4,0x28,100,0x16);
    (**(code **)(**(int **)(param_1 + 0x6fc) + 0x1c))(0xa4,0x12,0xdc,0x12);
    (**(code **)(**(int **)(param_1 + 0x700) + 0x1c))(0xa4,0x28,0xdc,0x16);
    (**(code **)(**(int **)(param_1 + 0x668) + 0x1c))(0xa4,0x12,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x66c) + 0x1c))(0xa4,0x26,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x670) + 0x1c))(0xa4,0x3a,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x674) + 0x1c))(0xa4,0x4e,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x678) + 0x1c))(0xa4,0x62,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x67c) + 0x1c))(0xa4,0x76,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x69c) + 0x1c))(0xb8,0x12,0x82,0x12);
    (**(code **)(**(int **)(param_1 + 0x6a0) + 0x1c))(0xb8,0x26,0x82,0x12);
    (**(code **)(**(int **)(param_1 + 0x6a8) + 0x1c))(0xb8,0x3a,0x82,0x12);
    (**(code **)(**(int **)(param_1 + 0x6ac) + 0x1c))(0xb8,0x4e,0x82,0x12);
    (**(code **)(**(int **)(param_1 + 0x6b0) + 0x1c))(0xb8,0x62,0x82,0x12);
    (**(code **)(**(int **)(param_1 + 0x68c) + 0x1c))(0x126,0,0x5a,0x12);
    (**(code **)(**(int **)(param_1 + 0x6b8) + 0x1c))(0x126,0x26,0x3c,0x12);
    (**(code **)(**(int **)(param_1 + 0x6bc) + 0x1c))(0x126,0x3a,0x3c,0x12);
    (**(code **)(**(int **)(param_1 + 0x6c0) + 0x1c))(0x126,0x4e,0x3c,0x12);
    (**(code **)(**(int **)(param_1 + 0x6c4) + 0x1c))(0x126,0x62,0x3c,0x12);
    (**(code **)(**(int **)(param_1 + 0x680) + 0x1c))(0x180,0x12,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x684) + 0x1c))(0x180,0x26,0x14,0x12);
    (**(code **)(**(int **)(param_1 + 0x694) + 0x1c))(0x194,0x12,0x5a,0x12);
    (**(code **)(**(int **)(param_1 + 0x698) + 0x1c))(0x194,0x26,0x5a,0x12);
    uVar7 = 0;
    puVar4 = (undefined4 *)(param_1 + 0x704);
    do {
      uVar3 = (int)uVar7 >> 0x1f;
      (**(code **)(*(int *)*puVar4 + 0x1c))
                (((int)(uVar7 + (uVar3 & 3)) >> 2) * 0x30 + 0xdc,
                 (((uVar7 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3) * 0x1a + 0x1e,0x2c,0x16);
      uVar7 = uVar7 + 1;
      puVar4 = puVar4 + 1;
    } while ((int)uVar7 < 0xc);
    (**(code **)(**(int **)(param_1 + 0x73c) + 0x1c))(4,4,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x734) + 0x1c))(4,0x1c,0xb4,0x16);
    (**(code **)(**(int **)(param_1 + 0x75c) + 0x1c))(0xdc,4,0x8c,0x16);
    (**(code **)(**(int **)(param_1 + 0x750) + 0x1c))(4,0x38,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x754) + 0x1c))(4,0x52,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x758) + 0x1c))(4,0x6c,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x764) + 0x1c))(0xa0,0x50,0x3c,0x16);
    (**(code **)(**(int **)(param_1 + 0x76c) + 0x1c))(0xa0,0x66,0x32,0x16);
    (**(code **)(**(int **)(param_1 + 0x740) + 0x1c))(4,0x66,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x744) + 0x1c))(4,0x38,0xb4,0x16);
    (**(code **)(**(int **)(param_1 + 0x768) + 0x1c))(4,0x50,0x96,0x16);
    (**(code **)(**(int **)(param_1 + 0x738) + 0x1c))(4,0x38,0xb4,0x16);
    (**(code **)(**(int **)(param_1 + 0x748) + 0x1c))(4,0x38,0xb4,0x16);
    (**(code **)(**(int **)(param_1 + 0x74c) + 0x1c))(4,0x38,0xb4,0x16);
    iVar6 = 8;
    puVar4 = (undefined4 *)(param_1 + 0x78c);
    do {
      (**(code **)(*(int *)puVar4[-5] + 0x1c))(4,iVar6,0x1e,0x12);
      (**(code **)(*(int *)*puVar4 + 0x1c))(0x24,iVar6,0x82,0x12);
      iVar6 = iVar6 + 0x19;
      puVar4 = puVar4 + 1;
    } while (iVar6 < 0x85);
    (**(code **)(**(int **)(param_1 + 0x774) + 0x18))(7,0xaf,4,0x28,4,0,0,0,0,0,0,0,0);
    iVar6 = 0x16;
    puVar4 = (undefined4 *)(param_1 + 0x7b4);
    do {
      (**(code **)(*(int *)puVar4[-4] + 0x1c))(4,iVar6 + -0x12,0xaa,0x12);
      (**(code **)(*(int *)*puVar4 + 0x1c))(4,iVar6,0xaa,0x16);
      iVar6 = iVar6 + 0x2c;
      puVar4 = puVar4 + 1;
    } while (iVar6 < 0x9a);
    (**(code **)(**(int **)(param_1 + 0x7b0) + 0x1c))(0xb2,4,0xaa,0x12);
    (**(code **)(**(int **)(param_1 + 0x7c0) + 0x1c))(0xb2,0x16,0xaa,0x16);
    iVar6 = 0x2c;
    puVar4 = (undefined4 *)(param_1 + 0x7c4);
    do {
      (**(code **)(*(int *)puVar4[1] + 0x1c))(3,iVar6,0x14,0x14);
      (**(code **)(*(int *)*puVar4 + 0x1c))(0x16,iVar6,0x87,0x14);
      iVar6 = iVar6 + 0x1a;
      puVar4 = puVar4 + 1;
    } while (iVar6 < 0x46);
    (**(code **)(**(int **)(param_1 + 2000) + 0x1c))(0xa0,3,0xa0,0x16);
    (**(code **)(**(int **)(param_1 + 0x7cc) + 0x1c))(3,3,0x96,0x16);
    puVar4 = (undefined4 *)(param_1 + 0x814);
    iVar6 = 0x1a;
    do {
      (**(code **)(*(int *)puVar4[-0x10] + 0x1c))(0xa0,iVar6,0x14,0x14);
      (**(code **)(*(int *)*puVar4 + 0x1c))(0xb4,iVar6,0x87,0x14);
      iVar6 = iVar6 + 0x14;
      puVar4 = puVar4 + 1;
    } while (iVar6 < 0x7e);
    puVar4 = (undefined4 *)(param_1 + 0x828);
    iVar6 = 0x1a;
    do {
      (**(code **)(*(int *)puVar4[-0x10] + 0x1c))(0x13b,iVar6,0x14,0x14);
      (**(code **)(*(int *)*puVar4 + 0x1c))(0x14f,iVar6,0x87,0x14);
      iVar6 = iVar6 + 0x14;
      puVar4 = puVar4 + 1;
    } while (iVar6 < 0x7e);
    puVar4 = (undefined4 *)(param_1 + 0x83c);
    iVar6 = 6;
    do {
      (**(code **)(*(int *)puVar4[-0x10] + 0x1c))(0x1d6,iVar6,0x14,0x14);
      (**(code **)(*(int *)*puVar4 + 0x1c))(0x1ea,iVar6,0x87,0x14);
      iVar6 = iVar6 + 0x14;
      puVar4 = puVar4 + 1;
    } while (iVar6 < 0x7e);
    (**(code **)(**(int **)(param_1 + 0x894) + 0x1c))(4,4,0x96,0x16);
    iVar6 = 0x96;
    puVar4 = (undefined4 *)(param_1 + 0x908);
    puVar5 = (undefined4 *)(param_1 + 0x8ac);
    do {
      (**(code **)(*(int *)puVar4[-0x25] + 0x1c))(iVar6,0x1c,0x1e,0x16);
      (**(code **)(*(int *)puVar5[-1] + 0x1c))(iVar6,0x34,0x1a,0x12);
      (**(code **)(*(int *)*puVar5 + 0x1c))(iVar6,0x48,0x1a,0x12);
      (**(code **)(*(int *)puVar5[1] + 0x1c))(iVar6,0x5c,0x1a,0x12);
      (**(code **)(*(int *)*puVar4 + 0x1c))(iVar6,0x70,0x1a,0x12);
      iVar6 = iVar6 + 0x1f;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 3;
    } while (iVar6 < 0x18e);
    (**(code **)(**(int **)(param_1 + 0x898) + 0x1c))(2,0x34,0x91,0x16);
    (**(code **)(**(int **)(param_1 + 0x89c) + 0x1c))(2,0x48,0x91,0x16);
    (**(code **)(**(int **)(param_1 + 0x8a0) + 0x1c))(2,0x5c,0x91,0x16);
    (**(code **)(**(int **)(param_1 + 0x8a4) + 0x1c))(2,0x70,0x91,0x16);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004b29d1
// Address: 004b29d1
// XREFS: None
void __thiscall FUN_004b29d1(int param_1,int param_2)
{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x704);
  do {
    (**(code **)(*(int *)*puVar3 + 0x14))(param_2);
    iVar1 = T_Scenario::GetSPVictoryType(*(T_Scenario **)(*(int *)(param_1 + 0x928) + 0x5c),iVar4);
    if (param_2 != 0) {
      (**(code **)(*(int *)*puVar3 + 0xe0))
                ((-(iVar1 != 0) & 2U) + (*(int *)(param_1 + 0x498) == iVar4));
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar4 < 0xc);
  (**(code **)(**(int **)(param_1 + 0x734) + 0x14))(param_2);
  (**(code **)(**(int **)(param_1 + 0x75c) + 0x14))(param_2);
  (**(code **)(**(int **)(param_1 + 0x73c) + 0x14))(param_2);
  if (param_2 != 0) {
    TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x73c),*(short *)(param_1 + 0x4b8) + -1)
    ;
    return;
  }
  lVar2 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x73c));
  *(short *)(param_1 + 0x4b8) = (short)lVar2 + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004b2a96
// Address: 004b2a96
// XREFS: None
// [HELPER] s__s__s: "%s\n%s"
int FUN_004b2a96(TDropDownPanel *param_1,undefined4 param_2,char *param_3,char param_4,char param_5)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iStack_328;
  undefined1 auStack_320 [20];
  char acStack_30c [259];
  char acStack_209 [261];
  undefined1 auStack_104 [260];
  
  iStack_328 = 0;
  TDropDownPanel::empty_list(param_1);
  if (param_4 != '\0') {
    TDropDownPanel::append_line(param_1,0x2775,0);
  }
  if (param_5 != '\0') {
    TDropDownPanel::append_line(param_1,0x277b,0);
  }
  sprintf(auStack_104,s__s__s,param_2,param_3);
  iVar2 = __findfirst(auStack_104,auStack_320);
  uVar3 = 0xffffffff;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *param_3;
    param_3 = param_3 + 1;
  } while (cVar1 != '\0');
  iVar5 = iVar2;
  do {
    if (iVar5 == -1) {
      return iStack_328;
    }
    uVar4 = 0xffffffff;
    iStack_328 = iStack_328 + 1;
    pcVar6 = acStack_30c;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar5 = (~uVar4 - 1) - (~uVar3 - 1);
    strncpy(acStack_209 + 1,acStack_30c,iVar5);
    acStack_209[iVar5 + 1] = '\0';
    TDropDownPanel::append_line(param_1,acStack_209 + 1,0);
    iVar5 = __findnext(iVar2,auStack_320);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004b2bb3
// Address: 004b2bb3
// XREFS: None
undefined4 __fastcall FUN_004b2bb3(int param_1)
{
  TDropDownPanel::empty_list(*(TDropDownPanel **)(param_1 + 0x5bc));
  TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x5bc),0x1069,0);
  TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x5bc),0x106a,1);
  TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x5bc),0x106b,2);
  TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x5bc),0x106c,3);
  TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x5bc),0x106d,4);
  TDropDownPanel::setCurrentLineNumber(*(TDropDownPanel **)(param_1 + 0x5bc),0);
  (**(code **)(**(int **)(param_1 + 0x5bc) + 0x14))(0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b2c4b
// Address: 004b2c4b
// XREFS: None
void __fastcall FUN_004b2c4b(TRIBE_Screen_Sed *param_1)
{
  long lVar1;
  TRIBE_World *pTVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  lVar1 = TDropDownPanel::get_line(param_1->player_number_list);
  pTVar2 = param_1->world;
  iVar4 = lVar1 + 1;
  iVar5 = 0;
  iVar3 = (int)(short)pTVar2->_padding_;
  if (iVar3 != 1 && -1 < iVar3 + -1) {
    do {
      RGE_Scenario::Set_player_Active((RGE_Scenario *)pTVar2->_padding_,iVar5,(uint)(iVar5 < iVar4))
      ;
      pTVar2 = param_1->world;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (short)pTVar2->_padding_ + -1);
  }
  TDropDownPanel::empty_list(param_1->victory_player_list);
  TDropDownPanel::empty_list(param_1->victory_enemy_player_list);
  TDropDownPanel::empty_list(param_1->options_player_list);
  TDropDownPanel::empty_list(param_1->Diplomacy_player_list);
  TDropDownPanel::empty_list(param_1->player_list);
  TDropDownPanel::empty_list(param_1->unit_player_list);
  TDropDownPanel::append_line(param_1->unit_player_list,0x2776,0);
  if (0 < iVar4) {
    iVar3 = 0x2865;
    do {
      TDropDownPanel::append_line(param_1->unit_player_list,iVar3,0);
      TDropDownPanel::append_line(param_1->victory_player_list,iVar3,0);
      TDropDownPanel::append_line(param_1->victory_enemy_player_list,iVar3,0);
      TDropDownPanel::append_line(param_1->options_player_list,iVar3,0);
      TDropDownPanel::append_line(param_1->Diplomacy_player_list,iVar3,0);
      TDropDownPanel::append_line(param_1->player_list,iVar3,0);
      iVar5 = iVar3 + -0x2864;
      iVar3 = iVar3 + 1;
    } while (iVar5 < iVar4);
  }
  if (iVar4 <= param_1->player_num) {
    TRIBE_Screen_Sed::set_player(param_1,(short)iVar4,'\0','\0');
  }
  TDropDownPanel::set_line(param_1->victory_player_list,param_1->player_num + -1);
  TDropDownPanel::set_line(param_1->options_player_list,param_1->player_num + -1);
  TDropDownPanel::set_line(param_1->Diplomacy_player_list,param_1->player_num + -1);
  TDropDownPanel::set_line(param_1->player_list,param_1->player_num + -1);
  TDropDownPanel::set_line(param_1->unit_player_list,(int)param_1->player_num);
  return;
}

// --------------------------------------------------

// Function: FUN_004b2dcf
// Address: 004b2dcf
// XREFS: None
undefined4 __thiscall FUN_004b2dcf(TEasy_Panel *param_1,TPanel *param_2,TButtonPanel **param_3)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_check_box(param_1,param_2,param_3,0,0,0,0,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_3,'\x01',0);
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  if (param_1->use_bevels != 0) {
    TButtonPanel::set_bevel_info
              (*param_3,3,(uint)param_1->bevel_color1,(uint)param_1->bevel_color2,
               (uint)param_1->bevel_color3,(uint)param_1->bevel_color4,(uint)param_1->bevel_color5,
               (uint)param_1->bevel_color6);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b2e5f
// Address: 004b2e5f
// XREFS: None
undefined4 __thiscall FUN_004b2e5f(TEasy_Panel *param_1,TPanel *param_2,TButtonPanel **param_3)
{
  int iVar1;
  
  iVar1 = TEasy_Panel::create_radio_button(param_1,param_2,param_3,0,0,0,0,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  TPanel::set_z_order((TPanel *)*param_3,'\x01',0);
  (**(code **)((*param_3)->_padding_ + 0x14))(0);
  if (param_1->use_bevels != 0) {
    TButtonPanel::set_bevel_info
              (*param_3,3,(uint)param_1->bevel_color1,(uint)param_1->bevel_color2,
               (uint)param_1->bevel_color3,(uint)param_1->bevel_color4,(uint)param_1->bevel_color5,
               (uint)param_1->bevel_color6);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004b2eef
// Address: 004b2eef
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_scr4: "scr4"
TEasy_Panel * __fastcall FUN_004b2eef(TEasy_Panel *param_1)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f568;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Scenario_Editor_Menu);
  piVar1 = &param_1[1]._padding_;
  param_1->_padding_ = (int)&TRIBE_Screen_Sed_Menu::_vftable_;
  param_1[1]._padding_ = 0;
  *piVar1 = 0;
  param_1[1]._padding_ = 0;
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  lVar2 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,s_scr4,0xc386,1);
  if (lVar2 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
  iVar3 = TEasy_Panel::create_text
                    (param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),0x242d,0x14,0x14,600,
                     0x1e,1,1,0,0);
  if (iVar3 != 0) {
    iVar3 = 0xaa;
    piVar5 = piVar1;
    do {
      iVar4 = TEasy_Panel::create_button
                        (param_1,(TPanel *)param_1,(TButtonPanel **)piVar5,s_,(char *)0x0,0xaa,iVar3
                         ,300,0x28,0,0,0);
      if (iVar4 == 0) goto LAB_004b30d3;
      iVar3 = iVar3 + 0x32;
      piVar5 = piVar5 + 1;
    } while (iVar3 < 0x172);
    piVar5 = &param_1[1]._padding_;
    iVar3 = TEasy_Panel::create_button
                      (param_1,(TPanel *)param_1,(TButtonPanel **)piVar5,0x3ea,0,0,0,0,0,-1,-1,0);
    if (iVar3 != 0) {
      (**(code **)(*(int *)*piVar5 + 0x14))(1);
      (**(code **)(*(int *)*piVar5 + 0x18))(9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
      TButtonPanel::set_text((TButtonPanel *)*piVar1,0,0x242e);
      TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x242f);
      TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x2431);
      TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0x2430);
      iVar3 = param_1[1]._padding_;
      *(undefined4 *)(iVar3 + 0x298) = 0x1b;
      *(undefined4 *)(iVar3 + 0x29c) = 0;
      TPanel::set_tab_order((TPanel *)param_1,(TPanel **)piVar1,4);
      TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*piVar1);
    }
  }
LAB_004b30d3:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b30e8
// Address: 004b30e8
// XREFS: None
TRIBE_Screen_Sed_Menu * __thiscall FUN_004b30e8(TRIBE_Screen_Sed_Menu *param_1,byte param_2)
{
  TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b310e
// Address: 004b310e
// XREFS: None
void __fastcall FUN_004b310e(TScreenPanel *param_1)
{
  int iVar1;
  TPanel **ppTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f588;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Sed_Menu::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  ppTVar2 = (TPanel **)&param_1[1].field_0x4;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar2);
    ppTVar2 = ppTVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004b3191
// Address: 004b3191
// XREFS: None
void __fastcall FUN_004b3191(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004b31c1
// Address: 004b31c1
// XREFS: None
// [HELPER] s_Campaign_Editor_Screen: "Campaign Editor Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
long __thiscall
FUN_004b31c1(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  TRIBE_Screen_Sed_Open *this;
  TRIBE_Campaign_Editor_Screen *this_00;
  TRIBE_Screen_Main_Menu *this_01;
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f5c1;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_2 != (TPanel *)0x0) && (param_3 == 1)) {
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      this = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
      uStack_4 = 0;
      if (this != (TRIBE_Screen_Sed_Open *)0x0) {
        TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      this_00 = (TRIBE_Campaign_Editor_Screen *)operator_new(0x4c4);
      uStack_4 = 1;
      if (this_00 != (TRIBE_Campaign_Editor_Screen *)0x0) {
        TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen(this_00);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Editor_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      RGE_Base_Game::disable_input(rge_base_game);
      this_01 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
      uStack_4 = 2;
      if (this_01 != (TRIBE_Screen_Main_Menu *)0x0) {
        TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_01);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      RGE_Base_Game::close(rge_base_game);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
  }
  lVar1 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  *unaff_FS_OFFSET = uStack_c;
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_004b33c6
// Address: 004b33c6
// XREFS: None
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
TRIBE_Screen_Sed_Open * __fastcall FUN_004b33c6(TRIBE_Screen_Sed_Open *param_1)
{
  TListPanel **ppTVar1;
  TButtonPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  char cVar4;
  TDrawArea *pTVar5;
  TButtonPanel *pTVar6;
  TEasy_Panel *this;
  char *pcVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  int iVar12;
  TListPanel *pTStack_124;
  TButtonPanel *pTStack_120;
  TButtonPanel *pTStack_11c;
  TButtonPanel *pTStack_118;
  TRIBE_Screen_Sed_Open *pTStack_114;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f5db;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_114 = param_1;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Scenario_Editor_Open);
  ppTVar1 = &param_1->list;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Screen_Sed_Open::_vftable_;
  param_1->title = (TTextPanel *)0x0;
  *ppTVar1 = (TListPanel *)0x0;
  param_1->scrollbar = (TScrollBarPanel *)0x0;
  param_1->okButton = (TButtonPanel *)0x0;
  param_1->cancelButton = (TButtonPanel *)0x0;
  param_1->deleteButton = (TButtonPanel *)0x0;
  this = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  pcVar7 = TEasy_Panel::get_info_file(this);
  uVar9 = 0xffffffff;
  do {
    pcVar11 = pcVar7;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar11 = pcVar7 + 1;
    cVar4 = *pcVar7;
    pcVar7 = pcVar11;
  } while (cVar4 != '\0');
  uVar9 = ~uVar9;
  iVar12 = 1;
  pcVar7 = pcVar11 + -uVar9;
  pcVar11 = acStack_110;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar11 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar11 = pcVar11 + 1;
  }
  pTVar5 = rge_base_game->draw_area;
  lVar8 = TEasy_Panel::get_info_id(this);
  lVar8 = TScreenPanel::setup((TScreenPanel *)param_1,pTVar5,acStack_110,lVar8,iVar12);
  if (lVar8 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
    iVar12 = TEasy_Panel::create_text
                       ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,0x24cd,0x14,0x14,
                        600,0x1e,1,1,0,0);
    if (iVar12 != 0) {
      iVar12 = TEasy_Panel::create_list
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x14,0x46,600,0x154,0xb);
      if (iVar12 != 0) {
        iVar12 = TEasy_Panel::create_auto_scrollbar
                           ((TEasy_Panel *)param_1,&param_1->scrollbar,(TTextPanel *)*ppTVar1,0x14);
        if (iVar12 != 0) {
          iVar12 = TEasy_Panel::create_button
                             ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->okButton,0xfa1,0,
                              0x1e,0x1b8,0xb4,0x1e,0,0,0);
          if (iVar12 != 0) {
            ppTVar2 = &param_1->deleteButton;
            iVar12 = TEasy_Panel::create_button
                               ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,0x24c9,0,0xe6,0x1b8
                                ,0xb4,0x1e,0,0,0);
            if (iVar12 != 0) {
              ppTVar3 = &param_1->cancelButton;
              iVar12 = TEasy_Panel::create_button
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar3,0xfa2,0,0x1ae,
                                  0x1b8,0xb4,0x1e,0,0,0);
              if (iVar12 != 0) {
                pTVar6 = *ppTVar3;
                pTVar6->hotkey = 0x1b;
                pTVar6->hotkey_shift = 0;
                pTVar6 = *ppTVar2;
                pTVar6->hotkey_shift = 0;
                pTVar6->hotkey = 0x2e;
                TRIBE_Screen_Sed_Open::fillList(param_1);
                pcVar7 = TTextPanel::currentLine((TTextPanel *)*ppTVar1);
                if (*pcVar7 == '\0') {
                  TButtonPanel::set_disabled(param_1->okButton,1);
                  TButtonPanel::set_disabled(*ppTVar2,1);
                }
                TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*ppTVar1);
                pTStack_120 = param_1->okButton;
                pTStack_124 = *ppTVar1;
                pTStack_11c = *ppTVar2;
                pTStack_118 = *ppTVar3;
                TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_124,4);
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b367b
// Address: 004b367b
// XREFS: None
TRIBE_Screen_Sed_Open * __thiscall FUN_004b367b(TRIBE_Screen_Sed_Open *param_1,byte param_2)
{
  TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b369e
// Address: 004b369e
// XREFS: None
void __fastcall FUN_004b369e(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f5f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Sed_Open::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x10);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004b373c
// Address: 004b373c
// XREFS: None
// [HELPER] s__s__scn: "%s*.scn"
// [HELPER] s__s__scx: "%s*.scx"
void __fastcall FUN_004b373c(int param_1)
{
  char cVar1;
  TTextPanel *pTVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char acStack_21c [260];
  undefined1 auStack_118 [20];
  char acStack_104 [260];
  
  TTextPanel::empty_list(*(TTextPanel **)(param_1 + 0x47c));
  *(undefined4 *)(*(int *)(param_1 + 0x47c) + 0x15c) = 1;
  sprintf(acStack_21c,s__s__scn,rge_base_game->prog_info->scenario_dir);
  iVar3 = __findfirst(acStack_21c,auStack_118);
  iVar4 = iVar3;
  while (iVar4 != -1) {
    uVar5 = 0xffffffff;
    pcVar6 = acStack_104;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    strncpy(acStack_21c,acStack_104,~uVar5 - 5);
    pTVar2 = *(TTextPanel **)(param_1 + 0x47c);
    acStack_21c[~uVar5 - 5] = '\0';
    TTextPanel::append_line(pTVar2,acStack_21c,0);
    iVar4 = __findnext(iVar3,auStack_118);
  }
  sprintf(acStack_21c,s__s__scx,rge_base_game->prog_info->scenario_dir);
  iVar3 = __findfirst(acStack_21c,auStack_118);
  iVar4 = iVar3;
  do {
    if (iVar4 == -1) {
      return;
    }
    uVar5 = 0xffffffff;
    pcVar6 = acStack_104;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    strncpy(acStack_21c,acStack_104,~uVar5 - 5);
    pTVar2 = *(TTextPanel **)(param_1 + 0x47c);
    acStack_21c[~uVar5 - 5] = '\0';
    TTextPanel::append_line(pTVar2,acStack_21c,0);
    iVar4 = __findnext(iVar3,auStack_118);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004b3c8b
// Address: 004b3c8b
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Select_Scenario_Screen: "Select Scenario Screen"
// [HELPER] s_scr2: "scr2"
// [HELPER] s_scr3: "scr3"
TribeSelectScenarioScreen * __fastcall FUN_004b3c8b(TribeSelectScenarioScreen *param_1)
{
  TListPanel **ppTVar1;
  TTextPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  TDrawArea *pTVar4;
  TButtonPanel *pTVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *unaff_FS_OFFSET;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  int iVar13;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f638;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Select_Scenario_Screen);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeSelectScenarioScreen::_vftable_;
  TribeSelectScenarioScreen::init_vars(param_1);
  iVar6 = RGE_Base_Game::multiplayerGame(rge_base_game);
  pcVar7 = &s_scr3;
  if (iVar6 == 0) {
    pcVar7 = &s_scr2;
  }
  iVar13 = 1;
  lVar12 = 0;
  lVar11 = 0;
  pTVar4 = rge_base_game->draw_area;
  lVar10 = 0;
  lVar9 = 0;
  iVar8 = 1;
  iVar6 = RGE_Base_Game::multiplayerGame(rge_base_game);
  lVar9 = TEasy_Panel::setup((TEasy_Panel *)param_1,pTVar4,(TPanel *)0x0,pcVar7,
                             (iVar6 != 0) + 0xc384,iVar8,lVar9,lVar10,lVar11,lVar12,iVar13);
  if (lVar9 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
  iVar6 = TEasy_Panel::create_text
                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,0x25fa,0x14,10,600,
                     0x1e,1,1,0,0);
  if (iVar6 != 0) {
    ppTVar1 = &param_1->scenarioList;
    param_1->scenarioListX = 0x14;
    param_1->scenarioListY = 0x46;
    param_1->scenarioListWidth = 600;
    param_1->scenarioListHeight = 0x107;
    iVar6 = TEasy_Panel::create_list
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x14,0x46,600,0x107,0xb);
    if (iVar6 != 0) {
      TTextPanel::set_second_column_pos
                ((TTextPanel *)*ppTVar1,
                 (param_1->_padding_ * (param_1->scenarioListWidth + -0x3c)) / param_1->_padding_);
      (**(code **)((*ppTVar1)->_padding_ + 0xe4))(0x25fd);
      iVar6 = TEasy_Panel::create_auto_scrollbar
                        ((TEasy_Panel *)param_1,&param_1->scenarioScrollbar,(TTextPanel *)*ppTVar1,
                         0x14);
      if (iVar6 != 0) {
        TPanel::set_help_info((TPanel *)param_1->scenarioScrollbar,-1,-1);
        iVar6 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->scenarioTitle,0x25fe,
                           param_1->scenarioListX,param_1->scenarioListY + -0x14,300,0x14,4,0,0,0);
        if (iVar6 != 0) {
          iVar6 = TEasy_Panel::create_text
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->scenarioPlayersTitle
                             ,0x25ff,param_1->scenarioListWidth + -0xdc + param_1->scenarioListX,
                             param_1->scenarioListY + -0x14,200,0x14,4,0,0,0);
          if (iVar6 != 0) {
            TTextPanel::set_alignment(param_1->scenarioPlayersTitle,AlignTop,AlignRight);
            iVar6 = param_1->scenarioListHeight + 0x19 + param_1->scenarioListY;
            param_1->missionTextY = iVar6;
            param_1->missionTextX = param_1->scenarioListX;
            param_1->missionTextWidth = param_1->scenarioListWidth;
            param_1->missionTextHeight = 0x3c;
            iVar6 = TEasy_Panel::create_text
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->missionTitle,
                               0x2600,param_1->scenarioListX,iVar6 + -0x14,400,0x14,4,0,0,0);
            if (iVar6 != 0) {
              ppTVar2 = &param_1->missionText;
              iVar6 = TEasy_Panel::create_text
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,s_,
                                 param_1->missionTextX,param_1->missionTextY,
                                 param_1->missionTextWidth,param_1->missionTextHeight,0xb,0,0,1);
              if (iVar6 != 0) {
                (**(code **)((*ppTVar2)->_padding_ + 0xec))
                          (3,(char)param_1->_padding_,*(undefined1 *)((int)&param_1->_padding_ + 1),
                           *(undefined1 *)((int)&param_1->_padding_ + 2),
                           *(undefined1 *)((int)&param_1->_padding_ + 3),(char)param_1->_padding_,
                           *(undefined1 *)((int)&param_1->_padding_ + 1));
                iVar6 = TEasy_Panel::create_auto_scrollbar
                                  ((TEasy_Panel *)param_1,&param_1->missionScrollbar,*ppTVar2,0x14);
                if (iVar6 != 0) {
                  TPanel::set_help_info((TPanel *)param_1->missionScrollbar,0x7532,-1);
                  iVar6 = TEasy_Panel::create_button
                                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->okButton,
                                     0xfa1,0,0x46,0x1b8,0xf0,0x1e,0,0,0);
                  if (iVar6 != 0) {
                    TPanel::set_help_info((TPanel *)param_1->okButton,0x7531,-1);
                    ppTVar3 = &param_1->cancelButton;
                    iVar6 = TEasy_Panel::create_button
                                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar3,0xfa2,0,
                                       0x14a,0x1b8,0xf0,0x1e,0,0,0);
                    if (iVar6 != 0) {
                      TPanel::set_help_info((TPanel *)*ppTVar3,0x7532,-1);
                      pTVar5 = *ppTVar3;
                      pTVar5->hotkey = 0x1b;
                      pTVar5->hotkey_shift = 0;
                      ppTVar3 = &param_1->close_button;
                      iVar6 = TEasy_Panel::create_button
                                        ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar3,0x3ea,0,0,
                                         0,0,0,-1,-1,0);
                      if (iVar6 != 0) {
                        (**(code **)((*ppTVar3)->_padding_ + 0x14))(1);
                        (**(code **)((*ppTVar3)->_padding_ + 0x18))
                                  (9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                        TribeSelectScenarioScreen::fillScenarios(param_1);
                        param_1->scenariosLoaded = 1;
                        TribeSelectScenarioScreen::getSettings(param_1);
                        TribeSelectScenarioScreen::fillMissionText(param_1);
                        TribeSelectScenarioScreen::activatePanels(param_1);
                        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*ppTVar1);
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
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b40fe
// Address: 004b40fe
// XREFS: None
TribeSelectScenarioScreen * __thiscall FUN_004b40fe(TribeSelectScenarioScreen *param_1,byte param_2)
{
  TribeSelectScenarioScreen::~TribeSelectScenarioScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b411e
// Address: 004b411e
// XREFS: None
void __fastcall FUN_004b411e(int param_1)
{
  *(undefined4 *)(param_1 + 0x4d4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x478) = 0;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0;
  *(undefined4 *)(param_1 + 0x494) = 0;
  *(undefined4 *)(param_1 + 0x498) = 0;
  *(undefined4 *)(param_1 + 0x49c) = 0;
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(param_1 + 0x4a4) = 0;
  *(undefined4 *)(param_1 + 0x4a8) = 0;
  *(undefined4 *)(param_1 + 0x4ac) = 0;
  *(undefined4 *)(param_1 + 0x4c0) = 0;
  *(undefined4 *)(param_1 + 0x4c4) = 0;
  *(undefined4 *)(param_1 + 0x4c8) = 0;
  *(undefined4 *)(param_1 + 0x4cc) = 0;
  *(undefined4 *)(param_1 + 0x4d0) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004b4187
// Address: 004b4187
// XREFS: None
void __fastcall FUN_004b4187(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f658;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeSelectScenarioScreen::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x20);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x34);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x48);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x50);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x54);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x58);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004b4272
// Address: 004b4272
// XREFS: None
void __fastcall FUN_004b4272(TribeSelectScenarioScreen *param_1)
{
  if (param_1->scenariosLoaded == 0) {
    TribeSelectScenarioScreen::fillScenarios(param_1);
    TribeSelectScenarioScreen::fillMissionText(param_1);
    param_1->scenariosLoaded = 1;
    TribeSelectScenarioScreen::activatePanels(param_1);
    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->scenarioList);
  }
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle((TPanel *)param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004b42d6
// Address: 004b42d6
// XREFS: None
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Select_Scenario_Screen: "Select Scenario Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
long __thiscall
FUN_004b42d6(TribeSelectScenarioScreen *param_1,TButtonPanel *param_2,int param_3,ulong param_4,
            ulong param_5)
{
  TribeMPSetupScreen *this;
  TribeSPMenuScreen *this_00;
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar2;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055f686;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_2 != (TButtonPanel *)0x0) && (param_1->scenariosLoaded != 0)) {
    if ((param_2 == param_1->okButton) && (param_3 == 1)) {
      TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->scenarioList);
      TribeSelectScenarioScreen::sendSettings(param_1);
      RGE_Base_Game::disable_input(rge_base_game);
      this = (TribeMPSetupScreen *)operator_new(0x890);
      uStack_4 = 0;
      if (this != (TribeMPSetupScreen *)0x0) {
        TribeMPSetupScreen::TribeMPSetupScreen(this);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Select_Scenario_Screen);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if ((param_2 == param_1->cancelButton) && (param_3 == 1)) {
      TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->scenarioList);
      RGE_Base_Game::disable_input(rge_base_game);
      this_00 = (TribeSPMenuScreen *)operator_new(0x49c);
      uStack_4 = 1;
      if (this_00 != (TribeSPMenuScreen *)0x0) {
        TribeSPMenuScreen::TribeSPMenuScreen(this_00);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Single_Player_Menu,0);
      TPanelSystem::destroyPanel(&panel_system,s_Select_Scenario_Screen);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if ((param_2 == param_1->close_button) && (param_3 == 1)) {
      RGE_Base_Game::close(rge_base_game);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_2 == (TButtonPanel *)param_1->scenarioList) {
      if (param_3 == 3) {
        uVar2 = 1;
        (**(code **)(param_1->_padding_ + 0xb4))(param_1->okButton,1,0,0);
        *unaff_FS_OFFSET = uVar2;
        return 1;
      }
      if (param_3 == 1) {
        TribeSelectScenarioScreen::fillMissionText(param_1);
        TribeSelectScenarioScreen::activatePanels(param_1);
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
    }
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  *unaff_FS_OFFSET = uStack_c;
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_004b471a
// Address: 004b471a
// XREFS: None
// [HELPER] s_: ""
void __fastcall FUN_004b471a(int param_1)
{
  long lVar1;
  
  (**(code **)(**(int **)(param_1 + 0x4c0) + 0xe8))(s_);
  lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x494));
  if (-1 < lVar1) {
    (**(code **)(**(int **)(param_1 + 0x4c0) + 0xe8))
              (*(undefined4 *)(*(int *)(param_1 + 0x4a0) + lVar1 * 4));
  }
  *(long *)(param_1 + 0x4d4) = lVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_004b4769
// Address: 004b4769
// XREFS: None
void __fastcall FUN_004b4769(int param_1)
{
  char *pcVar1;
  long lVar2;
  
  *(undefined4 *)(param_1 + 0x4d4) = 0xffffffff;
  pcVar1 = RGE_Base_Game::scenarioName(rge_base_game);
  lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x494),pcVar1);
  if (lVar2 != -1) {
    TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x494),'\x01',(short)lVar2,1);
    *(long *)(param_1 + 0x4d4) = lVar2 + -1;
    return;
  }
  TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x494),'\x01',0,1);
  return;
}

// --------------------------------------------------

// Function: FUN_004b47c8
// Address: 004b47c8
// XREFS: None
void __fastcall FUN_004b47c8(int param_1)
{
  char *pcVar1;
  
  RGE_Base_Game::setScenarioGame(rge_base_game,1);
  pcVar1 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x494));
  RGE_Base_Game::setScenarioName(rge_base_game,pcVar1);
  TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_004b4806
// Address: 004b4806
// XREFS: None
void __fastcall FUN_004b4806(TPanel *param_1)
{
  long lStack_18;
  
  lStack_18 = 1;
  (**(code **)(*(int *)param_1[4].z_order + 0x14))();
  (**(code **)(**(int **)&param_1[4].fill_in_background + 0x14))(1);
  lStack_18 = param_1[4].mouse_down_x;
  (**(code **)(param_1->_padding_ + 200))(&lStack_18,3);
  if ((param_1->curr_child == (TPanel *)0x0) || (param_1->curr_child->active == 0)) {
    TPanel::set_curr_child(param_1,param_1[5].previousPanelValue);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004b57ed
// Address: 004b57ed
// XREFS: None
TribeGameSettingsScreen * __thiscall FUN_004b57ed(TribeGameSettingsScreen *param_1,byte param_2)
{
  TribeGameSettingsScreen::~TribeGameSettingsScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004b580e
// Address: 004b580e
// XREFS: None
void __fastcall FUN_004b580e(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x478) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0;
  *(undefined4 *)(param_1 + 0x484) = 0;
  *(undefined4 *)(param_1 + 0x488) = 0;
  *(undefined4 *)(param_1 + 0x48c) = 0;
  *(undefined4 *)(param_1 + 0x490) = 0;
  *(undefined4 *)(param_1 + 0x494) = 0;
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(param_1 + 0x4a4) = 0;
  *(undefined4 *)(param_1 + 0x4a8) = 0;
  *(undefined4 *)(param_1 + 0x4ac) = 0;
  *(undefined4 *)(param_1 + 0x498) = 0;
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  *(undefined4 *)(param_1 + 0x4bc) = 0;
  *(undefined4 *)(param_1 + 0x4d0) = 0;
  *(undefined4 *)(param_1 + 0x4d4) = 0;
  *(undefined4 *)(param_1 + 0x4c0) = 0;
  *(undefined4 *)(param_1 + 0x4c4) = 0;
  *(undefined4 *)(param_1 + 0x4c8) = 0;
  *(undefined4 *)(param_1 + 0x4cc) = 0;
  *(undefined4 *)(param_1 + 0x4d8) = 0;
  *(undefined4 *)(param_1 + 0x4dc) = 0;
  *(undefined4 *)(param_1 + 0x4f0) = 0;
  *(undefined4 *)(param_1 + 0x4f4) = 0;
  *(undefined4 *)(param_1 + 0x4f8) = 0;
  *(undefined4 *)(param_1 + 0x4fc) = 0;
  *(undefined4 *)(param_1 + 0x500) = 0;
  *(undefined4 *)(param_1 + 0x504) = 0;
  *(undefined4 *)(param_1 + 0x508) = 0;
  *(undefined4 *)(param_1 + 0x51c) = 0;
  *(undefined4 *)(param_1 + 0x520) = 0;
  puVar1 = (undefined4 *)(param_1 + 0x534);
  iVar2 = 4;
  do {
    puVar1[-4] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x544) = 0;
  *(undefined4 *)(param_1 + 0x548) = 0;
  *(undefined4 *)(param_1 + 0x54c) = 0;
  *(undefined4 *)(param_1 + 0x550) = 0;
  *(undefined4 *)(param_1 + 0x554) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x558) = 0;
  *(undefined4 *)(param_1 + 0x55c) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004b591f
// Address: 004b591f
// XREFS: None
void __fastcall FUN_004b591f(TScreenPanel *param_1)
{
  int iVar1;
  int iVar2;
  TPanel **ppTVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055f6b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeGameSettingsScreen::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x10);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x18);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x34);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x30);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x2c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x28);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x20);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x38);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x3c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x40);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x44);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x48);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x60);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x64);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x78);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x7c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x90);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xa4);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xa8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x50);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x54);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x58);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x5c);
  ppTVar3 = (TPanel **)&param_1[1].field_0xbc;
  iVar2 = 4;
  do {
    TPanel::delete_panel((TPanel *)param_1,ppTVar3 + -4);
    TPanel::delete_panel((TPanel *)param_1,ppTVar3);
    ppTVar3 = ppTVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xcc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xd0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xd4);
  if (*(int *)&param_1[1].field_0x84 != 0) {
    iVar2 = 0;
    if (0 < *(int *)&param_1[1].field_0x80) {
      do {
        iVar1 = *(int *)(*(int *)&param_1[1].field_0x84 + iVar2 * 4);
        if (iVar1 != 0) {
          free(iVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)&param_1[1].field_0x80);
    }
    free(*(undefined4 *)&param_1[1].field_0x84);
  }
  if (*(int *)&param_1[1].field_0x88 != 0) {
    free(*(int *)&param_1[1].field_0x88);
  }
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004b5ba9
// Address: 004b5ba9
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_set_cp: "C:\msdev\work\age1_x1\scr_set.cpp"
void __fastcall FUN_004b5ba9(TribeGameSettingsScreen *param_1)
{
  int iVar1;
  ulong uVar2;
  
  if (param_1->scenariosLoaded == 0) {
    TribeGameSettingsScreen::fillScenarios(param_1);
    TribeGameSettingsScreen::fillMissionText(param_1);
    param_1->scenariosLoaded = 1;
    TribeGameSettingsScreen::activatePanels(param_1);
    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->scenarioList);
  }
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  iVar1 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar1 != 0) {
    if (param_1->last_send_shared == 0) {
      iVar1 = 0x23a;
    }
    else {
      uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_set_cp,0x23d);
      if (uVar2 == param_1->last_send_shared) goto LAB_004b5c5e;
      TCommunications_Handler::SendSharedData(comm,0);
      iVar1 = 0x240;
    }
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_set_cp,iVar1);
    param_1->last_send_shared = uVar2;
  }
LAB_004b5c5e:
  TPanel::handle_idle((TPanel *)param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004b5c67
// Address: 004b5c67
// XREFS: None
void __thiscall FUN_004b5c67(TPanel *param_1,uint param_2,long param_3)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[5].render_rect.left;
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 100))(param_2,param_3), iVar2 != 0))
{
    return;
  }
  TPanel::handle_user_command(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004b5ca1
// Address: 004b5ca1
// XREFS: None
long __thiscall
FUN_004b5ca1(TribeGameSettingsScreen *param_1,TButtonPanel *param_2,int param_3,ulong param_4,
            ulong param_5)
{
  long lVar1;
  TDropDownPanel *this;
  
  if ((param_2 != (TButtonPanel *)0x0) && (param_1->scenariosLoaded != 0)) {
    if ((param_2 == param_1->okButton) && (param_3 == 1)) {
      TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->scenarioList);
      TribeGameSettingsScreen::sendSettings(param_1);
      (**(code **)(param_1->chat_scr->_padding_ + 0xb4))(param_1,1,0,0);
      return 1;
    }
    if ((param_2 == param_1->cancelButton) && (param_3 == 1)) {
      TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->scenarioList);
      TribeGameSettingsScreen::getSettings(param_1);
      (**(code **)(param_1->chat_scr->_padding_ + 0xb4))(param_1,0,0,0);
      return 1;
    }
    if ((param_2 == param_1->help_button) && (param_3 == 1)) {
      TEasy_Panel::setup_popup_help((TEasy_Panel *)param_1);
      return 1;
    }
    if ((param_2 == (TButtonPanel *)param_1->victoryTypeDrop) && (param_3 == 0)) {
      lVar1 = TDropDownPanel::get_id(param_1->victoryTypeDrop);
      if (lVar1 == 7) {
        this = param_1->timeDrop;
        lVar1 = 3;
      }
      else {
        if (lVar1 != 8) {
LAB_004b5dd2:
          TribeGameSettingsScreen::activatePanels(param_1);
          return 1;
        }
        this = param_1->scoreDrop;
        lVar1 = 7;
      }
      TDropDownPanel::set_line(this,lVar1);
      TribeGameSettingsScreen::activatePanels(param_1);
      return 1;
    }
    if (param_2 == (TButtonPanel *)param_1->scenarioList) {
      if (param_3 == 3) {
        return 1;
      }
      if (param_3 == 1) {
        TribeGameSettingsScreen::fillMissionText(param_1);
        goto LAB_004b5dd2;
      }
    }
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_004b5df9
// Address: 004b5df9
// XREFS: None
// [HELPER] s_2___8: "2 - 8"
// [HELPER] s__d: "%d"
// [HELPER] s__d____d: "%d - %d"
void __fastcall FUN_004b5df9(TPanel *param_1)
{
  long *plVar1;
  char cVar2;
  byte bVar3;
  RGE_Scenario_File_Info *this;
  uchar uVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  RedrawMode RVar8;
  TPanel *pTVar9;
  long lVar10;
  RGE_Scenario_Header *pRVar11;
  undefined4 uVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  char *pcVar16;
  bool bVar17;
  char *pcVar18;
  int iStack_224;
  char acStack_21c [15];
  undefined1 auStack_20d [5];
  byte abStack_208 [260];
  char acStack_104 [260];
  
  TTextPanel::empty_list((TTextPanel *)param_1[5].clip_rect.right);
  param_1[5].render_rect.right = 0;
  iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ((iVar5 != 0) || (iVar5 = RGE_Base_Game::scenarioGame(rge_base_game), iVar5 != 0)) {
    this = rge_base_game->scenario_info;
    RGE_Scenario_File_Info::reload_scenarios(this);
    iStack_224 = 0;
    *(undefined4 *)(param_1[5].clip_rect.right + 0x15c) = 1;
    param_1[5].position_mode = PositionFixed;
    while (pcVar6 = RGE_Scenario_File_Info::get_scenario_name(this,iStack_224),
          pcVar6 != (char *)0x0) {
      uVar13 = 0xffffffff;
      pcVar18 = pcVar6;
      do {
        if (uVar13 == 0) break;
        uVar13 = uVar13 - 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar18 + 1;
      } while (cVar2 != '\0');
      strncpy(abStack_208,pcVar6,~uVar13 - 5);
      auStack_20d[~uVar13] = 0;
      iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (iVar5 == 0) {
        pbVar7 = (byte *)RGE_Base_Game::scenarioName(rge_base_game);
        pbVar14 = abStack_208;
        do {
          bVar3 = *pbVar14;
          bVar17 = bVar3 < *pbVar7;
          if (bVar3 != *pbVar7) {
LAB_004b5eed:
            iVar5 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
            goto LAB_004b5ef2;
          }
          if (bVar3 == 0) break;
          bVar3 = pbVar14[1];
          bVar17 = bVar3 < pbVar7[1];
          if (bVar3 != pbVar7[1]) goto LAB_004b5eed;
          pbVar14 = pbVar14 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar3 != 0);
        iVar5 = 0;
LAB_004b5ef2:
        if (iVar5 == 0) goto LAB_004b5ef6;
      }
      else {
LAB_004b5ef6:
        TTextPanel::append_line
                  ((TTextPanel *)param_1[5].clip_rect.right,(char *)abStack_208,iStack_224);
        param_1[5].position_mode = param_1[5].position_mode + PositionVariable;
      }
      iStack_224 = iStack_224 + 1;
    }
    RVar8 = calloc(param_1[5].position_mode,4);
    param_1[5].need_redraw = RVar8;
    pTVar9 = (TPanel *)calloc(param_1[5].position_mode,4);
    param_1[5].curr_child = pTVar9;
    if (((param_1[5].need_redraw != RedrawNone) && (pTVar9 != (TPanel *)0x0)) &&
       (iStack_224 = 0, 0 < (int)param_1[5].position_mode)) {
      do {
        lVar10 = TTextPanel::get_id((TTextPanel *)param_1[5].clip_rect.right,iStack_224);
        pRVar11 = RGE_Scenario_File_Info::get_scenario_info(this,lVar10);
        if (pRVar11 != (RGE_Scenario_Header *)0x0) {
          uVar12 = calloc(0x1000,1);
          *(undefined4 *)(param_1[5].need_redraw + iStack_224 * 4) = uVar12;
          pcVar6 = *(char **)(param_1[5].need_redraw + iStack_224 * 4);
          if ((pcVar6 != (char *)0x0) && (pRVar11->description != (char *)0x0)) {
            uVar13 = 0xffffffff;
            pcVar18 = pRVar11->description;
            do {
              pcVar16 = pcVar18;
              if (uVar13 == 0) break;
              uVar13 = uVar13 - 1;
              pcVar16 = pcVar18 + 1;
              cVar2 = *pcVar18;
              pcVar18 = pcVar16;
            } while (cVar2 != '\0');
            uVar13 = ~uVar13;
            pcVar18 = pcVar16 + -uVar13;
            for (uVar15 = uVar13 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
              *(undefined4 *)pcVar6 = *(undefined4 *)pcVar18;
              pcVar18 = pcVar18 + 4;
              pcVar6 = pcVar6 + 4;
            }
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *pcVar6 = *pcVar18;
              pcVar18 = pcVar18 + 1;
              pcVar6 = pcVar6 + 1;
            }
          }
          (&(param_1[5].curr_child)->_padding_)[iStack_224] = pRVar11[1]._padding_;
          iVar5 = pRVar11[1].error_code;
          if (0 < iVar5) {
            if (((&(param_1[5].curr_child)->_padding_)[iStack_224] == 0) && (2 < iVar5)) {
              sprintf(acStack_21c,s__d____d,2,iVar5);
            }
            else {
              sprintf(acStack_21c,&s__d,iVar5);
            }
            pcVar6 = TTextPanel::get_text((TTextPanel *)param_1[5].clip_rect.right,iStack_224);
            uVar13 = 0xffffffff;
            do {
              pcVar18 = pcVar6;
              if (uVar13 == 0) break;
              uVar13 = uVar13 - 1;
              pcVar18 = pcVar6 + 1;
              cVar2 = *pcVar6;
              pcVar6 = pcVar18;
            } while (cVar2 != '\0');
            uVar13 = ~uVar13;
            pcVar6 = pcVar18 + -uVar13;
            pcVar18 = acStack_104;
            for (uVar15 = uVar13 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
              *(undefined4 *)pcVar18 = *(undefined4 *)pcVar6;
              pcVar6 = pcVar6 + 4;
              pcVar18 = pcVar18 + 4;
            }
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *pcVar18 = *pcVar6;
              pcVar6 = pcVar6 + 1;
              pcVar18 = pcVar18 + 1;
            }
            TTextPanel::change_line
                      ((TTextPanel *)param_1[5].clip_rect.right,iStack_224,acStack_104,acStack_21c,0
                      );
          }
        }
        iStack_224 = iStack_224 + 1;
      } while (iStack_224 < (int)param_1[5].position_mode);
    }
  }
  *(undefined4 *)(param_1[5].clip_rect.right + 0x15c) = 0;
  iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ((iVar5 != 0) ||
     ((iVar5 = RGE_Base_Game::randomGame(rge_base_game), iVar5 != 0 &&
      (uVar4 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game), uVar4 == '\0')))) {
    lVar10 = -2;
    pcVar18 = s_2___8;
    pcVar6 = TPanel::get_string(param_1,0x25b5);
    TTextPanel::insert_line((TTextPanel *)param_1[5].clip_rect.right,0,pcVar6,pcVar18,lVar10);
    plVar1 = &param_1[5].render_rect.right;
    *plVar1 = *plVar1 + -1;
  }
  iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ((iVar5 != 0) ||
     ((iVar5 = RGE_Base_Game::randomGame(rge_base_game), iVar5 != 0 &&
      (uVar4 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game), uVar4 != '\0')))) {
    lVar10 = -1;
    pcVar18 = s_2___8;
    pcVar6 = TPanel::get_string(param_1,0x2617);
    TTextPanel::insert_line((TTextPanel *)param_1[5].clip_rect.right,1,pcVar6,pcVar18,lVar10);
    plVar1 = &param_1[5].render_rect.right;
    *plVar1 = *plVar1 + -1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004b6225
// Address: 004b6225
// XREFS: None
void __fastcall FUN_004b6225(int param_1)
{
  uchar uVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  MapSize MVar5;
  long lVar6;
  MapType MVar7;
  VictoryType VVar8;
  int iVar9;
  ResourceLevel RVar10;
  Age AVar11;
  short sVar12;
  
  iVar3 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x47c) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x47c) = 0;
  }
  *(undefined4 *)(param_1 + 0x554) = 0;
  if (*(int *)(param_1 + 0x47c) == 1) {
    uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
    if (uVar1 == '\0') goto LAB_004b62b4;
    sVar12 = 1;
  }
  else {
    pcVar4 = RGE_Base_Game::scenarioName(rge_base_game);
    lVar6 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x4f0),pcVar4);
    if (lVar6 != -1) {
      TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x4f0),'\x01',(short)lVar6,1);
      *(long *)(param_1 + 0x554) = lVar6 + -1;
      goto LAB_004b62c3;
    }
LAB_004b62b4:
    sVar12 = 0;
  }
  TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x4f0),'\x01',sVar12,1);
LAB_004b62c3:
  MVar5 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
  lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x484),MVar5);
  TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x484),lVar6);
  MVar7 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
  lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x48c),MVar7);
  TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x48c),lVar6);
  VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x494),VVar8);
  TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x494),lVar6);
  if (*(int **)(param_1 + 0x530) != (int *)0x0) {
    iVar3 = **(int **)(param_1 + 0x530);
    iVar9 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    (**(code **)(iVar3 + 0xe0))(iVar9);
  }
  iVar3 = **(int **)(param_1 + 0x528);
  iVar9 = RGE_Base_Game::fullVisibility(rge_base_game);
  (**(code **)(iVar3 + 0xe0))(iVar9);
  iVar3 = **(int **)(param_1 + 0x524);
  iVar9 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  (**(code **)(iVar3 + 0xe0))(iVar9 == 0);
  iVar3 = **(int **)(param_1 + 0x52c);
  iVar9 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  (**(code **)(iVar3 + 0xe0))(iVar9);
  RVar10 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x4c4),RVar10);
  TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x4c4),lVar6);
  AVar11 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x4bc),AVar11);
  TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x4bc),lVar6);
  iVar3 = RGE_Base_Game::difficulty(rge_base_game);
  lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x4b4),iVar3);
  TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x4b4),lVar6);
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar3 == 0) {
    bVar2 = RGE_Base_Game::pathFinding(rge_base_game);
  }
  else {
    bVar2 = RGE_Base_Game::mpPathFinding(rge_base_game);
  }
  lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x4cc),(uint)bVar2);
  TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x4cc),lVar6);
  iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar3 != 0) {
    bVar2 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
    lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x4d4),(uint)bVar2);
    TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x4d4),lVar6);
  }
  VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  if (VVar8 == VictoryTime) {
    iVar3 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
    lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x4ac),iVar3);
    TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x4ac),lVar6);
    return;
  }
  VVar8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  if (VVar8 == VictoryScore) {
    iVar3 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
    lVar6 = TDropDownPanel::get_line(*(TDropDownPanel **)(param_1 + 0x4a4),iVar3);
    TDropDownPanel::set_line(*(TDropDownPanel **)(param_1 + 0x4a4),lVar6);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004b64f9
// Address: 004b64f9
// XREFS: None
// [HELPER] s_: ""
void __fastcall FUN_004b64f9(int param_1)
{
  long lVar1;
  char *pcVar2;
  VictoryType VVar3;
  int iVar4;
  MapSize MVar5;
  MapType MVar6;
  Age AVar7;
  ResourceLevel RVar8;
  
  lVar1 = TTextPanel::get_id(*(TTextPanel **)(param_1 + 0x4f0));
  if (lVar1 < 0) {
    RGE_Base_Game::setScenarioGame(rge_base_game,0);
    pcVar2 = s_;
  }
  else {
    RGE_Base_Game::setScenarioGame(rge_base_game,1);
    pcVar2 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x4f0));
  }
  RGE_Base_Game::setScenarioName(rge_base_game,pcVar2);
  lVar1 = TTextPanel::get_id(*(TTextPanel **)(param_1 + 0x4f0));
  TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,lVar1 == -1);
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x494));
  if (lVar1 == 7) {
    lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4ac));
    VVar3 = VictoryTime;
  }
  else if (lVar1 == 8) {
    lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4a4));
    VVar3 = VictoryScore;
  }
  else {
    lVar1 = 1;
    VVar3 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x494));
  }
  TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game,VVar3,lVar1);
  iVar4 = RGE_Base_Game::randomGame(rge_base_game);
  if (iVar4 != 0) {
    MVar5 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x484));
    TRIBE_Game::setMapSize((TRIBE_Game *)rge_base_game,MVar5);
    MVar6 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x48c));
    TRIBE_Game::setMapType((TRIBE_Game *)rge_base_game,MVar6);
  }
  if (*(TButtonPanel **)(param_1 + 0x530) != (TButtonPanel *)0x0) {
    iVar4 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x530));
    RGE_Base_Game::setAllowCheatCodes(rge_base_game,iVar4);
  }
  iVar4 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x528));
  RGE_Base_Game::setFullVisibility(rge_base_game,iVar4);
  iVar4 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x524));
  TRIBE_Game::setRandomizePositions((TRIBE_Game *)rge_base_game,(uint)(iVar4 == 0));
  iVar4 = TButtonPanel::get_state(*(TButtonPanel **)(param_1 + 0x52c));
  TRIBE_Game::setFullTechTree((TRIBE_Game *)rge_base_game,iVar4);
  lVar1 = TTextPanel::get_id(*(TTextPanel **)(param_1 + 0x4f0));
  if (lVar1 == -1) {
    RVar8 = DefaultResources;
  }
  else {
    RVar8 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4c4));
  }
  TRIBE_Game::setResourceLevel((TRIBE_Game *)rge_base_game,RVar8);
  iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar4 == 0) {
    lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4cc));
    RGE_Base_Game::setPathFinding(rge_base_game,(uchar)lVar1);
  }
  else {
    lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4cc));
    RGE_Base_Game::setMpPathFinding(rge_base_game,(uchar)lVar1);
  }
  iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar4 != 0) {
    lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4d4));
    TRIBE_Game::setPopLimit((TRIBE_Game *)rge_base_game,(uchar)lVar1);
  }
  AVar7 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4bc));
  TRIBE_Game::setStartingAge((TRIBE_Game *)rge_base_game,AVar7);
  lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4b4));
  RGE_Base_Game::setDifficulty(rge_base_game,lVar1);
  iVar4 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar4 != 0) {
    lVar1 = TDropDownPanel::get_id(*(TDropDownPanel **)(param_1 + 0x4b4));
    RGE_Base_Game::set_single_player_difficulty(rge_base_game,lVar1);
  }
  return;
}

// --------------------------------------------------

