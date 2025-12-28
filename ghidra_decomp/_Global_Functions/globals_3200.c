// GLOBAL FUNCTIONS PART 3200
// Function: FUN_0048902a
// Address: 0048902a
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_rmm_terr_c: "C:\msdev\work\age1_x1\rmm_terr.cpp"
undefined4 __thiscall
FUN_0048902a(RGE_RMM_Terrain_Generator *param_1,int param_2,undefined4 param_3,byte param_4,
            int param_5,long param_6,uint param_7,long param_8,int param_9)
{
  uchar uVar1;
  uchar uVar2;
  byte bVar3;
  Map_Stack *pMVar4;
  int iVar5;
  RGE_Terrain_Hot_Spots *pRVar6;
  Map_Stack *pMVar7;
  int iVar8;
  int iStack_a54;
  int iStack_a50;
  float fStack_a4c;
  char cStack_a45;
  int iStack_a44;
  uint uStack_a40;
  int iStack_a3c;
  int iStack_a38;
  float fStack_a34;
  int iStack_a30;
  int iStack_a2c;
  Map_Stack MStack_a28;
  char acStack_a10 [100];
  uchar auStack_9ac [100];
  Map_Stack aMStack_948 [99];
  
  iVar8 = 0;
  iStack_a2c = param_1->_padding_ + -1;
  iStack_a38 = 0;
  iStack_a30 = param_1->_padding_ + -1;
  fStack_a4c = 0.0;
  if ((param_9 == 2) && (0 < (param_1->info).hot_spot_num)) {
    pRVar6 = (param_1->info).hot_spots;
    do {
      uVar1 = RGE_Zone_Map::get_zone_info(param_1->map_zone,pRVar6->x,pRVar6->y);
      auStack_9ac[iVar8] = uVar1;
      iVar5 = (param_1->info).hot_spot_num;
      acStack_a10[iVar8] = '\0';
      iVar8 = iVar8 + 1;
      pRVar6 = pRVar6 + 1;
    } while (iVar8 < iVar5);
  }
  pMVar7 = aMStack_948;
  iVar8 = 99;
  do {
    RGE_Random_Map_Module::init_stack((RGE_Random_Map_Module *)param_1,pMVar7);
    pMVar7 = pMVar7 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  MStack_a28.next = (Map_Stack *)0x0;
  MStack_a28.prev = (Map_Stack *)0x0;
  uVar1 = (uchar)param_7;
  RGE_RMM_Terrain_Generator::link_stack_randomly(param_1,&MStack_a28,uVar1);
  iStack_a44 = __ftol();
  iStack_a44 = iStack_a44 * 2;
  if (iStack_a44 < 2) {
    iStack_a44 = 2;
  }
  iStack_a3c = 0;
  if (0 < param_5) {
    pMVar7 = aMStack_948;
    do {
      pMVar4 = RGE_Random_Map_Module::pop_stack
                         ((RGE_Random_Map_Module *)param_1,&MStack_a28,&iStack_a50,&iStack_a54,
                          &fStack_a34);
      if (pMVar4 == (Map_Stack *)0x0) break;
      if ((((*(byte *)(*(int *)(param_1->_padding_ + iStack_a54 * 4) + 5 + iStack_a50 * 0x18) & 0x1f
            ) == param_7) &&
          (uVar2 = RGE_RMM_Terrain_Generator::check_terrain
                             (param_1,param_4,iStack_a50,iStack_a54,param_6,uVar1), uVar2 != '\0'))
         && ((param_9 == 0 ||
             (*(char *)(*(int *)(param_1->_padding_ + iStack_a54 * 4) + iStack_a50) == '\0')))) {
        RGE_RMM_Terrain_Generator::remove_area_from_lists(param_1,iStack_a50,iStack_a54,iStack_a44);
        iVar8 = *(int *)(param_1->_padding_ + iStack_a54 * 4);
        bVar3 = *(byte *)(iVar8 + 5 + iStack_a50 * 0x18);
        *(byte *)(iVar8 + 5 + iStack_a50 * 0x18) = (param_4 ^ bVar3) & 0x1f ^ bVar3;
        if (0 < iStack_a50) {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50 + -1,iStack_a54,0.0,0.0);
        }
        if (0 < iStack_a54) {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50,iStack_a54 + -1,0.0,0.0);
        }
        if (iStack_a50 < param_1->_padding_ + -1) {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50 + 1,iStack_a54,0.0,0.0);
        }
        if (iStack_a54 < param_1->_padding_ + -1) {
          RGE_Random_Map_Module::push_stack
                    ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50,iStack_a54 + 1,0.0,0.0);
        }
        iStack_a38 = iStack_a38 + 1;
        iStack_a3c = iStack_a3c + 1;
        pMVar7 = pMVar7 + 1;
        uVar2 = RGE_Zone_Map::get_zone_info(param_1->map_zone,iStack_a50,iStack_a54);
        if (param_9 == 2) {
          iVar8 = (param_1->info).hot_spot_num;
          iVar5 = 0;
          if (0 < iVar8) {
            do {
              if ((auStack_9ac[iVar5] == uVar2) && (acStack_a10[iVar5] == '\0')) {
                acStack_a10[iVar5] = '\x01';
                fStack_a4c = (float)((int)fStack_a4c + 1);
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar8);
          }
        }
      }
    } while (iStack_a3c < param_5);
  }
  if ((param_9 == 2) && ((int)fStack_a4c < (param_1->info).hot_spot_num)) {
    pMVar7 = aMStack_948 + iStack_a3c;
    do {
      pMVar4 = RGE_Random_Map_Module::pop_stack
                         ((RGE_Random_Map_Module *)param_1,&MStack_a28,&iStack_a50,&iStack_a54,
                          &fStack_a34);
      if (pMVar4 == (Map_Stack *)0x0) break;
      if ((((*(byte *)(*(int *)(param_1->_padding_ + iStack_a54 * 4) + 5 + iStack_a50 * 0x18) & 0x1f
            ) == param_7) &&
          (uVar2 = RGE_RMM_Terrain_Generator::check_terrain
                             (param_1,param_4,iStack_a50,iStack_a54,param_6,uVar1), uVar2 != '\0'))
         && (*(byte *)(*(int *)(param_1->_padding_ + iStack_a54 * 4) + iStack_a50) < 0x1e)) {
        uVar2 = RGE_Zone_Map::get_zone_info(param_1->map_zone,iStack_a50,iStack_a54);
        iVar8 = (param_1->info).hot_spot_num;
        iVar5 = 0;
        if (0 < iVar8) {
          do {
            if ((auStack_9ac[iVar5] == uVar2) && (acStack_a10[iVar5] == '\0')) break;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar8);
        }
        if (iVar5 != iVar8) {
          fStack_a4c = (float)((int)fStack_a4c + 1);
          acStack_a10[iVar5] = '\x01';
          RGE_RMM_Terrain_Generator::remove_area_from_lists
                    (param_1,iStack_a50,iStack_a54,iStack_a44);
          iVar8 = *(int *)(param_1->_padding_ + iStack_a54 * 4);
          bVar3 = *(byte *)(iVar8 + 5 + iStack_a50 * 0x18);
          *(byte *)(iVar8 + 5 + iStack_a50 * 0x18) = (param_4 ^ bVar3) & 0x1f ^ bVar3;
          if (0 < iStack_a50) {
            RGE_Random_Map_Module::push_stack
                      ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50 + -1,iStack_a54,0.0,0.0);
          }
          if (0 < iStack_a54) {
            RGE_Random_Map_Module::push_stack
                      ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50,iStack_a54 + -1,0.0,0.0);
          }
          if (iStack_a50 < param_1->_padding_ + -1) {
            RGE_Random_Map_Module::push_stack
                      ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50 + 1,iStack_a54,0.0,0.0);
          }
          if (iStack_a54 < param_1->_padding_ + -1) {
            RGE_Random_Map_Module::push_stack
                      ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50,iStack_a54 + 1,0.0,0.0);
          }
          iStack_a38 = iStack_a38 + 1;
          iStack_a3c = iStack_a3c + 1;
          pMVar7 = pMVar7 + 1;
        }
      }
    } while ((int)fStack_a4c < (param_1->info).hot_spot_num);
  }
  do {
    cStack_a45 = '\x01';
    if (0 < iStack_a3c) {
      pMVar7 = aMStack_948;
      iStack_a44 = iStack_a3c;
      do {
        if (((iStack_a38 < param_2) &&
            (pMVar4 = RGE_Random_Map_Module::pop_stack
                                ((RGE_Random_Map_Module *)param_1,pMVar7,&iStack_a50,&iStack_a54,
                                 &fStack_a34), pMVar4 != (Map_Stack *)0x0)) &&
           ((cStack_a45 = '\0', param_9 == 0 ||
            (iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_terr_c,0x1c6),
            (int)(uint)*(byte *)(*(int *)(param_1->_padding_ + iStack_a54 * 4) + iStack_a50) <=
            (iVar8 * 100) / 0x7fff)))) {
          iVar8 = *(int *)(param_1->_padding_ + iStack_a54 * 4) + iStack_a50 * 0x18;
          bVar3 = RGE_RMM_Terrain_Generator::check_terrain
                            (param_1,param_4,iStack_a50,iStack_a54,param_6,uVar1);
          if (((*(byte *)(iVar8 + 5) & 0x1f) == param_7) && (bVar3 != 0)) {
            fStack_a4c = RGE_RMM_Terrain_Generator::fig_chance
                                   (param_1,(uint)bVar3,iStack_a50,iStack_a54,param_8);
            if (param_9 != 0) {
              uStack_a40 = (uint)*(byte *)(*(int *)(param_1->_padding_ + iStack_a54 * 4) +
                                          iStack_a50);
              fStack_a4c = (float)uStack_a40 + fStack_a4c;
            }
            *(byte *)(iVar8 + 5) = (param_4 ^ *(byte *)(iVar8 + 5)) & 0x1f ^ *(byte *)(iVar8 + 5);
            if ((0 < iStack_a50) && ((*(byte *)(iVar8 + -0x13) & 0x1f) == param_7)) {
              iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_terr_c,0x1d5);
              uStack_a40 = (iVar5 * 100) / 0x7fff;
              RGE_Random_Map_Module::push_stack
                        ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50 + -1,iStack_a54,0.0,
                         (float)(int)uStack_a40 + fStack_a4c);
            }
            if ((iStack_a50 < iStack_a2c) && ((*(byte *)(iVar8 + 0x1d) & 0x1f) == param_7)) {
              iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_terr_c,0x1d7);
              uStack_a40 = (iVar5 * 100) / 0x7fff;
              RGE_Random_Map_Module::push_stack
                        ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50 + 1,iStack_a54,0.0,
                         (float)(int)uStack_a40 + fStack_a4c);
            }
            if ((0 < iStack_a54) &&
               ((*(byte *)(iVar8 + param_1->_padding_ * -0x18 + 5) & 0x1f) == param_7)) {
              iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_terr_c,0x1d9);
              uStack_a40 = (iVar5 * 100) / 0x7fff;
              RGE_Random_Map_Module::push_stack
                        ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50,iStack_a54 + -1,0.0,
                         (float)(int)uStack_a40 + fStack_a4c);
            }
            if ((iStack_a54 < iStack_a30) &&
               ((*(byte *)(iVar8 + 5 + param_1->_padding_ * 0x18) & 0x1f) == param_7)) {
              iVar8 = debug_rand(s_C__msdev_work_age1_x1_rmm_terr_c,0x1db);
              uStack_a40 = (iVar8 * 100) / 0x7fff;
              RGE_Random_Map_Module::push_stack
                        ((RGE_Random_Map_Module *)param_1,pMVar7,iStack_a50,iStack_a54 + 1,0.0,
                         (float)(int)uStack_a40 + fStack_a4c);
            }
            iStack_a38 = iStack_a38 + 1;
          }
        }
        pMVar7 = pMVar7 + 1;
        iStack_a44 = iStack_a44 + -1;
      } while (iStack_a44 != 0);
    }
  } while (cStack_a45 == '\0');
  if (0 < param_5) {
    pMVar7 = aMStack_948;
    iStack_a44 = param_5;
    do {
      pMVar4 = RGE_Random_Map_Module::pop_stack
                         ((RGE_Random_Map_Module *)param_1,pMVar7,&iStack_a50,&iStack_a54,
                          &fStack_a34);
      while (pMVar4 != (Map_Stack *)0x0) {
        iVar8 = *(int *)(param_1->_padding_ + iStack_a54 * 4) + iStack_a50 * 0x18;
        if (((((0 < iStack_a50) && ((*(byte *)(iVar8 + -0x13) & 0x1f) == param_4)) &&
             (iStack_a50 < iStack_a2c)) && ((*(byte *)(iVar8 + 0x1d) & 0x1f) == param_4)) ||
           (((0 < iStack_a54 &&
             ((*(byte *)(iVar8 + param_1->_padding_ * -0x18 + 5) & 0x1f) == param_4)) &&
            ((iStack_a30 < iStack_a54 &&
             ((*(byte *)(iVar8 + 5 + param_1->_padding_ * 0x18) & 0x1f) == param_4)))))) {
          *(byte *)(iVar8 + 5) = (param_4 ^ *(byte *)(iVar8 + 5)) & 0x1f ^ *(byte *)(iVar8 + 5);
        }
        pMVar4 = RGE_Random_Map_Module::pop_stack
                           ((RGE_Random_Map_Module *)param_1,pMVar7,&iStack_a50,&iStack_a54,
                            &fStack_a34);
      }
      pMVar7 = pMVar7 + 1;
      iStack_a44 = iStack_a44 + -1;
    } while (iStack_a44 != 0);
  }
  pMVar7 = aMStack_948;
  iVar8 = 99;
  do {
    RGE_Random_Map_Module::deinit_stack((RGE_Random_Map_Module *)param_1,pMVar7);
    pMVar7 = pMVar7 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004898cc
// Address: 004898cc
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Cmd: "Cmd"
// [HELPER] s_Del: "Del"
// [HELPER] s_Elev: "Elev"
// [HELPER] s_Game: "Game"
// [HELPER] s_Move: "Move"
// [HELPER] s_Obj: "Obj"
// [HELPER] s_Terr: "Terr"
RGE_Panel_Tool_Box * __thiscall
FUN_004898cc(RGE_Panel_Tool_Box *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,
            long param_5,long param_6,long param_7,void *param_8,long param_9,long param_10,
            TDigital *param_11,TScreenPanel *param_12,RGE_View *param_13,RGE_Diamond_Map *param_14)
{
  long lVar1;
  TButtonPanel *pTVar2;
  undefined4 *unaff_FS_OFFSET;
  TButtonPanel *pTStack_24;
  TButtonPanel *pTStack_20;
  TButtonPanel *pTStack_1c;
  TButtonPanel *pTStack_18;
  TButtonPanel *pTStack_14;
  TButtonPanel *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e745;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel((TPanel *)param_1);
  param_1->screen_panel = param_12;
  param_1->view = param_13;
  param_1->map = param_14;
  iStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Panel_Tool_Box::_vftable_;
  param_1->game_mode_button = (TButtonPanel *)0x0;
  param_1->object_mode_button = (TButtonPanel *)0x0;
  param_1->delete_mode_button = (TButtonPanel *)0x0;
  param_1->move_mode_button = (TButtonPanel *)0x0;
  param_1->terrain_mode_button = (TButtonPanel *)0x0;
  param_1->elevation_mode_button = (TButtonPanel *)0x0;
  param_1->command_button = (TButtonPanel *)0x0;
  param_1->dialog = (TPanel *)0x0;
  lVar1 = TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6,param_7,'\0');
  if (lVar1 == 0) {
    param_1->_padding_ = 1;
  }
  if (param_1->view == (RGE_View *)0x0) {
    param_1->_padding_ = 1;
  }
  else {
    pTVar2 = (TButtonPanel *)operator_new(0x2b8);
    iStack_4._0_1_ = 1;
    if (pTVar2 == (TButtonPanel *)0x0) {
      pTVar2 = (TButtonPanel *)0x0;
    }
    else {
      pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
    }
    iStack_4._0_1_ = 0;
    param_1->game_mode_button = pTVar2;
    if (pTVar2 == (TButtonPanel *)0x0) {
      param_1->_padding_ = 1;
    }
    else {
      TButtonPanel::setup(pTVar2,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0,0,0x32,0x1e,
                          DrawTextA,param_11,NotifyAction,0);
      TButtonPanel::set_text_info(param_1->game_mode_button,s_Game,param_8,param_9,param_10,-1,-1);
      TButtonPanel::set_text(param_1->game_mode_button,1,s_<Game>);
      pTVar2 = (TButtonPanel *)operator_new(0x2b8);
      iStack_4._0_1_ = 2;
      if (pTVar2 == (TButtonPanel *)0x0) {
        pTVar2 = (TButtonPanel *)0x0;
      }
      else {
        pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
      }
      iStack_4._0_1_ = 0;
      param_1->object_mode_button = pTVar2;
      if (pTVar2 == (TButtonPanel *)0x0) {
        param_1->_padding_ = 1;
      }
      else {
        TButtonPanel::setup(pTVar2,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0x34,0,0x32,
                            0x1e,DrawTextA,param_11,NotifyAction,0);
        TButtonPanel::set_text_info
                  (param_1->object_mode_button,s_Obj,param_8,param_9,param_10,-1,-1);
        TButtonPanel::set_text(param_1->object_mode_button,1,s_<Obj>);
        pTVar2 = (TButtonPanel *)operator_new(0x2b8);
        iStack_4._0_1_ = 3;
        if (pTVar2 == (TButtonPanel *)0x0) {
          pTVar2 = (TButtonPanel *)0x0;
        }
        else {
          pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
        }
        iStack_4._0_1_ = 0;
        param_1->move_mode_button = pTVar2;
        if (pTVar2 == (TButtonPanel *)0x0) {
          param_1->_padding_ = 1;
        }
        else {
          TButtonPanel::setup(pTVar2,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0x68,0,0x32,
                              0x1e,DrawTextA,param_11,NotifyAction,0);
          TButtonPanel::set_text_info
                    (param_1->move_mode_button,&s_Move,param_8,param_9,param_10,-1,-1);
          TButtonPanel::set_text(param_1->move_mode_button,1,s_<Move>);
          pTVar2 = (TButtonPanel *)operator_new(0x2b8);
          iStack_4._0_1_ = 4;
          if (pTVar2 == (TButtonPanel *)0x0) {
            pTVar2 = (TButtonPanel *)0x0;
          }
          else {
            pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
          }
          iStack_4._0_1_ = 0;
          param_1->delete_mode_button = pTVar2;
          if (pTVar2 == (TButtonPanel *)0x0) {
            param_1->_padding_ = 1;
          }
          else {
            TButtonPanel::setup(pTVar2,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0x9c,0,0x32
                                ,0x1e,DrawTextA,param_11,NotifyAction,0);
            TButtonPanel::set_text_info
                      (param_1->delete_mode_button,s_Del,param_8,param_9,param_10,-1,-1);
            TButtonPanel::set_text(param_1->delete_mode_button,1,s_<Del>);
            pTVar2 = (TButtonPanel *)operator_new(0x2b8);
            iStack_4._0_1_ = 5;
            if (pTVar2 == (TButtonPanel *)0x0) {
              pTVar2 = (TButtonPanel *)0x0;
            }
            else {
              pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
            }
            iStack_4._0_1_ = 0;
            param_1->terrain_mode_button = pTVar2;
            if (pTVar2 == (TButtonPanel *)0x0) {
              param_1->_padding_ = 1;
            }
            else {
              TButtonPanel::setup(pTVar2,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0xd0,0,
                                  0x32,0x1e,DrawTextA,param_11,NotifyAction,0);
              TButtonPanel::set_text_info
                        (param_1->terrain_mode_button,s_Terr,param_8,param_9,param_10,-1,-1);
              TButtonPanel::set_text(param_1->terrain_mode_button,1,s_<Terr>);
              (**(code **)(param_1->terrain_mode_button->_padding_ + 0x14))(0);
              pTVar2 = (TButtonPanel *)operator_new(0x2b8);
              iStack_4._0_1_ = 6;
              if (pTVar2 == (TButtonPanel *)0x0) {
                pTVar2 = (TButtonPanel *)0x0;
              }
              else {
                pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
              }
              iStack_4._0_1_ = 0;
              param_1->elevation_mode_button = pTVar2;
              if (pTVar2 == (TButtonPanel *)0x0) {
                param_1->_padding_ = 1;
              }
              else {
                TButtonPanel::setup(pTVar2,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0x104,0
                                    ,0x32,0x1e,DrawTextA,param_11,NotifyAction,0);
                TButtonPanel::set_text_info
                          (param_1->elevation_mode_button,s_Elev,param_8,param_9,param_10,-1,-1);
                TButtonPanel::set_text(param_1->elevation_mode_button,1,s_<Elev>);
                (**(code **)(param_1->elevation_mode_button->_padding_ + 0x14))(0);
                pTStack_1c = param_1->move_mode_button;
                pTStack_20 = param_1->object_mode_button;
                pTStack_24 = param_1->game_mode_button;
                pTStack_14 = param_1->terrain_mode_button;
                pTStack_18 = param_1->delete_mode_button;
                pTStack_10 = param_1->elevation_mode_button;
                TButtonPanel::set_radio_info(pTStack_24,&pTStack_24,6);
                TButtonPanel::set_radio_info(param_1->object_mode_button,&pTStack_24,6);
                TButtonPanel::set_radio_info(param_1->move_mode_button,&pTStack_24,6);
                TButtonPanel::set_radio_info(param_1->delete_mode_button,&pTStack_24,6);
                TButtonPanel::set_radio_info(param_1->terrain_mode_button,&pTStack_24,6);
                TButtonPanel::set_radio_info(param_1->elevation_mode_button,&pTStack_24,6);
                pTVar2 = (TButtonPanel *)operator_new(0x2b8);
                iStack_4._0_1_ = 7;
                if (pTVar2 == (TButtonPanel *)0x0) {
                  pTVar2 = (TButtonPanel *)0x0;
                }
                else {
                  pTVar2 = (TButtonPanel *)TButtonPanel::TButtonPanel(pTVar2);
                }
                iStack_4 = (uint)iStack_4._1_3_ << 8;
                param_1->command_button = pTVar2;
                if (pTVar2 == (TButtonPanel *)0x0) {
                  param_1->_padding_ = 1;
                }
                else {
                  TButtonPanel::setup(pTVar2,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,0x13a
                                      ,0,0x32,0x1e,DrawTextA,param_11,NotifyAction,0);
                  TButtonPanel::set_text_info
                            (param_1->command_button,s_Cmd,param_8,param_9,param_10,-1,-1);
                  TButtonPanel::set_text(param_1->command_button,1,s_<Cmd>);
                  TButtonPanel::set_state_info(param_1->command_button,2);
                  RGE_Panel_Tool_Box::game_mode_changed
                            (param_1,rge_base_game->game_mode,rge_base_game->game_mode);
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

// Function: FUN_00489e67
// Address: 00489e67
// XREFS: None
RGE_Panel_Tool_Box * __thiscall FUN_00489e67(RGE_Panel_Tool_Box *param_1,byte param_2)
{
  RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00489e8e
// Address: 00489e8e
// XREFS: None
void __fastcall FUN_00489e8e(TPanel *param_1)
{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e758;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Panel_Tool_Box::_vftable_;
  uStack_4 = 0;
  if ((undefined4 *)param_1[1].pnl_x != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1].pnl_x)(1);
  }
  if ((undefined4 *)param_1[1].pnl_y != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1].pnl_y)(1);
  }
  if ((undefined4 *)param_1[1].pnl_hgt != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1].pnl_hgt)(1);
  }
  if ((undefined4 *)param_1[1].pnl_wid != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1].pnl_wid)(1);
  }
  if (param_1[1].panelNameValue != (char *)0x0) {
    (*(code *)**(undefined4 **)param_1[1].panelNameValue)(1);
  }
  if (param_1[1].render_area != (TDrawArea *)0x0) {
    (*(code *)(param_1[1].render_area)->DrawSystem->Inst)(1);
  }
  puVar1 = (undefined4 *)param_1[1].clip_rect.left;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00489f4a
// Address: 00489f4a
// XREFS: None
// [HELPER] s_Object_List_Dialog: "Object List Dialog"
// [HELPER] s_Terrain_List_Dialog: "Terrain List Dialog"
undefined4 __thiscall FUN_00489f4a(RGE_Panel_Tool_Box *param_1,TButtonPanel *param_2,int param_3)
{
  TPanel **ppTVar1;
  byte bVar2;
  short sVar3;
  RGE_Dialog_List *this;
  TPanel *pTVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  byte *pbVar8;
  RGE_Player *this_00;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  byte *pbVar9;
  undefined4 *unaff_FS_OFFSET;
  bool bVar10;
  int iVar11;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e77b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != (TButtonPanel *)0x0) {
    if ((param_2 == param_1->game_mode_button) && (param_3 == 1)) {
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
      *unaff_FS_OFFSET = unaff_ESI;
      return 1;
    }
    if ((param_2 == param_1->object_mode_button) && (param_3 == 1)) {
      this = (RGE_Dialog_List *)operator_new(0x4bc);
      uStack_4 = 0;
      if (this == (RGE_Dialog_List *)0x0) {
        pTVar4 = (TPanel *)0x0;
      }
      else {
        pTVar4 = (TPanel *)RGE_Dialog_List::RGE_Dialog_List(this,&s_Object_List_Dialog);
      }
      uStack_4 = 0xffffffff;
      param_1->dialog = pTVar4;
      if (pTVar4 != (TPanel *)0x0) {
        pcVar5 = TPanel::get_string((TPanel *)param_1,0x232a);
        iVar11 = 1;
        lVar6 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)param_1->screen_panel);
        pcVar7 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)param_1->screen_panel);
        iVar11 = RGE_Dialog_List::setup
                           ((RGE_Dialog_List *)param_1->dialog,param_1->screen_panel,pcVar7,lVar6,
                            iVar11,pcVar5);
        if (iVar11 == 0) {
          if (param_1->dialog != (TPanel *)0x0) {
            (**(code **)param_1->dialog->_padding_)(1);
          }
          param_1->dialog = (TPanel *)0x0;
          *unaff_FS_OFFSET = uStack_c;
          return 1;
        }
      }
    }
    else {
      if ((param_2 == param_1->move_mode_button) && (param_3 == 1)) {
        (**(code **)(rge_base_game->_padding_ + 0x10))(0x12,0);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
      if ((param_2 == param_1->delete_mode_button) && (param_3 == 1)) {
        (**(code **)(rge_base_game->_padding_ + 0x10))(0xe,0);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
      if ((param_2 == param_1->elevation_mode_button) && (param_3 == 1)) {
        (**(code **)(rge_base_game->_padding_ + 0x10))(3,0);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
      if ((param_2 == param_1->command_button) && (param_3 == 1)) {
        if (rge_base_game->prog_mode == 4) {
          (**(code **)(rge_base_game->_padding_ + 0xc))(6);
          rge_base_game->world->temp_pause = '\x01';
          *unaff_FS_OFFSET = unaff_EBP;
          return 1;
        }
        (**(code **)(rge_base_game->_padding_ + 0xc))(4);
        *unaff_FS_OFFSET = unaff_EBP;
        return 1;
      }
      ppTVar1 = &param_1->dialog;
      if (param_2 != (TButtonPanel *)param_1->dialog) goto LAB_0048a307;
      pbVar9 = &s_Object_List_Dialog;
      pbVar8 = (byte *)TPanel::panelName(param_1->dialog);
      do {
        bVar2 = *pbVar8;
        bVar10 = bVar2 < *pbVar9;
        if (bVar2 != *pbVar9) {
LAB_0048a1c9:
          iVar11 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0048a1ce;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar10 = bVar2 < pbVar9[1];
        if (bVar2 != pbVar9[1]) goto LAB_0048a1c9;
        pbVar8 = pbVar8 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar2 != 0);
      iVar11 = 0;
LAB_0048a1ce:
      if (iVar11 == 0) {
        if (param_3 == 1) {
          sVar3 = (**(code **)((*ppTVar1)->_padding_ + 0x130))();
          rge_base_game->master_obj_id = sVar3;
          RGE_Base_Game::delete_dialog(rge_base_game,ppTVar1);
          (**(code **)(rge_base_game->_padding_ + 0x10))(1,0);
          this_00 = RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::unselect_object(this_00);
          *unaff_FS_OFFSET = unaff_ESI;
          return 1;
        }
      }
      else {
        pbVar9 = &s_Terrain_List_Dialog;
        pbVar8 = (byte *)TPanel::panelName(*ppTVar1);
        do {
          bVar2 = *pbVar8;
          bVar10 = bVar2 < *pbVar9;
          if (bVar2 != *pbVar9) {
LAB_0048a26c:
            iVar11 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_0048a271;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar8[1];
          bVar10 = bVar2 < pbVar9[1];
          if (bVar2 != pbVar9[1]) goto LAB_0048a26c;
          pbVar8 = pbVar8 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar2 != 0);
        iVar11 = 0;
LAB_0048a271:
        if (iVar11 != 0) goto LAB_0048a2ee;
        if (param_3 == 1) {
          sVar3 = (**(code **)((*ppTVar1)->_padding_ + 0x130))();
          rge_base_game->terrain_id = sVar3;
          RGE_Base_Game::delete_dialog(rge_base_game,ppTVar1);
          (**(code **)(rge_base_game->_padding_ + 0x10))(2,0);
          *unaff_FS_OFFSET = unaff_ESI;
          return 1;
        }
      }
      if (param_3 == 2) {
        RGE_Base_Game::delete_dialog(rge_base_game,ppTVar1);
        RGE_Panel_Tool_Box::game_mode_changed
                  (param_1,rge_base_game->game_mode,rge_base_game->game_mode);
      }
    }
LAB_0048a2ee:
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
LAB_0048a307:
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048a31d
// Address: 0048a31d
// XREFS: None
undefined4 __thiscall FUN_0048a31d(int param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  uchar uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  RGE_Map *this;
  long lStack_10;
  long lStack_c;
  long lStack_8;
  long lStack_4;
  
  iVar3 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = rge_base_game->prog_mode;
  if (((iVar3 != 4) && (iVar3 != 6)) && (iVar3 != 7)) {
    return 0;
  }
  if (param_2 == 0x21) {
    if (rge_base_game->game_mode != 3) {
      return 0;
    }
    RGE_View::get_selection_area
              (*(RGE_View **)(param_1 + 0xf8),&lStack_4,&lStack_8,&lStack_c,&lStack_10,1);
    RGE_Map::set_elev(rge_base_game->world->map,(short)lStack_4,(short)lStack_8,(short)lStack_c,
                      (short)lStack_10,'\0',1,'\x01');
    this = rge_base_game->world->map;
  }
  else {
    if (param_2 != 0x22) {
      if (param_2 != 0x2e) {
        return 0;
      }
      if (rge_base_game->game_mode != 0x12) {
        return 0;
      }
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      pRVar1 = pRVar4->selected_obj;
      if (pRVar1 == (RGE_Static_Object *)0x0) {
        return 1;
      }
      if (pRVar1->sprite_list == (RGE_Active_Sprite_List *)0x0) {
        if (pRVar1->sprite == (RGE_Sprite *)0x0) {
          uVar2 = '\x14';
        }
        else {
          uVar2 = RGE_Sprite::get_lowest_draw_level(pRVar1->sprite);
        }
      }
      else {
        uVar2 = RGE_Active_Sprite_List::get_lowest_draw_level(pRVar1->sprite_list);
      }
      (**(code **)(pRVar1->_padding_ + 0x68))();
      if (uVar2 != '\0') {
        return 1;
      }
      (**(code **)(**(int **)(param_1 + 0xf8) + 0x20))(2);
      return 1;
    }
    if (rge_base_game->game_mode != 3) {
      return 0;
    }
    RGE_View::get_selection_area
              (*(RGE_View **)(param_1 + 0xf8),&lStack_4,&lStack_8,&lStack_c,&lStack_10,1);
    RGE_Map::set_elev(rge_base_game->world->map,(short)lStack_4,(short)lStack_8,(short)lStack_c,
                      (short)lStack_10,'\0',-1,'\x01');
    this = rge_base_game->world->map;
  }
  RGE_Map::clean_elevation(this,lStack_4,lStack_8,lStack_c,lStack_10,'\b');
  (**(code **)(**(int **)(param_1 + 0xf8) + 0x20))(2);
  if (*(int **)(param_1 + 0xfc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xfc) + 0x20))(2);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0048a51d
// Address: 0048a51d
// XREFS: None
void __thiscall FUN_0048a51d(int param_1,undefined4 param_2,undefined4 param_3)
{
  RGE_Player *pRVar1;
  TButtonPanel *this;
  
  switch(param_2) {
  case 1:
  case 0x12:
    pRVar1 = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::unselect_object(pRVar1);
    break;
  case 2:
  case 3:
    RGE_View::set_selection_area(*(RGE_View **)(param_1 + 0xf8),-1,-1,-1,-1);
  }
  switch(param_3) {
  case 1:
    TButtonPanel::set_radio_button(*(TButtonPanel **)(param_1 + 0x104));
    return;
  case 2:
    this = *(TButtonPanel **)(param_1 + 0x110);
    break;
  case 3:
    this = *(TButtonPanel **)(param_1 + 0x114);
    break;
  default:
    TButtonPanel::set_radio_button(*(TButtonPanel **)(param_1 + 0x100));
    return;
  case 0xe:
    TButtonPanel::set_radio_button(*(TButtonPanel **)(param_1 + 0x108));
    return;
  case 0x12:
    TButtonPanel::set_radio_button(*(TButtonPanel **)(param_1 + 0x10c));
    return;
  }
  TButtonPanel::set_radio_button(this);
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_object(pRVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_0048a5e3
// Address: 0048a5e3
// XREFS: None
void __fastcall FUN_0048a5e3(int *param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_EAX;
  char *pcVar8;
  int *piVar9;
  int *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *(char *)(in_EAX + -0x5c) = *(char *)(in_EAX + -0x5c) + (char)param_2;
  cRama5630048 = cRama5630048 + (char)((uint)unaff_EBX >> 8);
  pcVar8 = (char *)(in_EAX + -3);
  *pcVar8 = *pcVar8 + (char)pcVar8;
  *param_1 = (int)(pcVar8 + *param_1);
  iVar1 = *unaff_EBX;
  iVar2 = *unaff_EBX;
  iVar3 = *unaff_EBX;
  iVar4 = *unaff_EBX;
  iVar5 = *unaff_EBX;
  iVar6 = *unaff_EBX;
  iVar7 = *unaff_EBX;
  piVar9 = (int *)CONCAT31((int3)((uint)param_1 >> 8),
                           (char)param_1 + *(char *)((int)unaff_EBX + 0x48a57eff));
  *(char *)((int)unaff_EBX + -0x4cffb75b) =
       *(char *)((int)unaff_EBX + -0x4cffb75b) + (char)((uint)param_1 >> 8);
  *unaff_EDI = *unaff_ESI;
  *(char *)(unaff_EBP + -0x5a72ffb8) = *(char *)(unaff_EBP + -0x5a72ffb8) + (char)unaff_EBX;
  pcVar8 = pcVar8 + iVar7 + iVar6 + iVar5 + iVar4 + iVar3 + iVar2 + iVar1 + -2;
  unaff_EDI[1] = unaff_ESI[1];
  pcVar8 = (char *)(CONCAT22((short)((uint)pcVar8 >> 0x10),
                             CONCAT11((char)((uint)pcVar8 >> 8) + (char)param_2,(char)pcVar8)) + -1)
  ;
  *pcVar8 = *pcVar8 + (char)pcVar8;
  *param_2 = (int)(pcVar8 + *param_2);
  if (((piVar9[8] != 0) && (piVar9[0x1c] != 0)) && (piVar9[0x1b] != 0)) {
    iVar1 = *piVar9;
    (**(code **)(iVar1 + 0x28))(0,unaff_EDI + 2,unaff_ESI + 2);
    TDrawArea::Clear((TDrawArea *)piVar9[8],(tagRECT *)(piVar9 + 9),0);
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048a676
// Address: 0048a676
// XREFS: None
TPanel * __thiscall FUN_0048a676(TPanel *param_1,TDrawArea *param_2,TPanel *param_3,int param_4)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e798;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel(param_1);
  param_1[1]._padding_ = param_4;
  uStack_4 = 0;
  param_1->handle_mouse_input = 0;
  param_1[1].previousPanelValue = (TPanel *)0x0;
  param_1[1].previousModalPanelValue = (TPanel *)0x0;
  param_1->_padding_ = (int)&RGE_Panel_Time::_vftable_;
  param_1[1].pnl_x = -1;
  lVar1 = TPanel::setup(param_1,param_2,param_3,0,0,0,0,'\0');
  if (lVar1 == 0) {
    param_1->error_code = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048a70c
// Address: 0048a70c
// XREFS: None
RGE_Panel_Time * __thiscall FUN_0048a70c(RGE_Panel_Time *param_1,byte param_2)
{
  RGE_Panel_Time::~RGE_Panel_Time(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048a735
// Address: 0048a735
// XREFS: None
// [HELPER] s__02ld__02ld__02ld___3_1f_: "%02ld:%02ld:%02ld (%3.1f)"
// [HELPER] s_rpnl_tim__draw: "rpnl_tim::draw"
void __fastcall FUN_0048a735(TPanel *param_1)
{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int unaff_ESI;
  TPanel *pTVar10;
  int iStack_78;
  undefined1 uStack_70;
  undefined1 uStack_6f;
  ushort uStack_6e;
  char acStack_68 [104];
  
  if (((param_1->render_area != (TDrawArea *)0x0) && (param_1->visible != 0)) &&
     (param_1->active != 0)) {
    iVar8 = param_1->_padding_;
    (**(code **)(iVar8 + 0x28))(0);
    param_1->display_changed_count = param_1->display_changed_count + 1;
    pvVar2 = TDrawArea::GetDc(param_1->render_area,s_rpnl_tim__draw);
    if (pvVar2 != (void *)0x0) {
      SelectClipRgn(param_1->render_area->DrawDc,param_1->clip_rgn);
      uVar3 = SelectObject(param_1->render_area->DrawDc,param_1[1]._padding_);
      iVar4 = RGE_Base_Game::get_paused(rge_base_game);
      if (iVar4 == 0) {
        SetBkMode(param_1->render_area->DrawDc,1);
        SetTextColor(param_1->render_area->DrawDc,0xffffff);
        pTVar10 = param_1[1].previousPanelValue;
        iVar4 = 0;
        iVar9 = 0;
        if (0x3b < (int)pTVar10) {
          iVar4 = (int)pTVar10 / 0x3c;
          pTVar10 = (TPanel *)((int)pTVar10 % 0x3c);
          if (0x3b < iVar4) {
            iVar9 = iVar4 / 0x3c;
            iVar4 = iVar4 % 0x3c;
          }
        }
        sprintf(acStack_68,s__02ld__02ld__02ld___3_1f_,iVar9,iVar4,pTVar10,
                (double)rge_base_game->world->game_speed);
        uVar6 = 0xffffffff;
        pcVar5 = acStack_68;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        TextOutA(param_1->render_area->DrawDc,(param_1->render_rect).left,
                 (param_1->render_rect).top + -2,acStack_68,~uVar6 - 1);
        iVar4 = 1;
        iVar9 = (int)rge_base_game->world->player_num;
        if (1 < iVar9) {
          iVar7 = 0xd;
          do {
            RGE_Base_Game::get_countdown_timer(rge_base_game,iVar4,(long *)&stack0xffffff80);
            if (-1 < unaff_ESI) {
              GetPaletteEntries(rge_base_game->draw_system->Pal,
                                rge_base_game->world->players[iVar4]->color_table->map_color,1,
                                &uStack_70);
              SetTextColor(param_1->render_area->DrawDc,
                           ((uStack_6e & 0xff) << 8 | CONCAT21(uStack_6e,uStack_6f) & 0xff) << 8 |
                           CONCAT11(uStack_6f,uStack_70) & 0xff);
              pcVar5 = TPanel::get_string(param_1,0x2c24);
              sprintf(acStack_68,pcVar5);
              uVar6 = 0xffffffff;
              pcVar5 = acStack_68;
              do {
                if (uVar6 == 0) break;
                uVar6 = uVar6 - 1;
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + 1;
              } while (cVar1 != '\0');
              TextOutA(param_1->render_area->DrawDc,(param_1->render_rect).left,
                       iVar7 + (param_1->render_rect).top,acStack_68,~uVar6 - 1);
              iVar7 = iVar7 + 0xd;
            }
            iVar4 = iVar4 + 1;
            iVar8 = iStack_78;
          } while (iVar4 < iVar9);
        }
      }
      else {
        SetBkColor(param_1->render_area->DrawDc,0xffffff);
        SetBkMode(param_1->render_area->DrawDc,2);
        SetTextColor(param_1->render_area->DrawDc,0xff);
        sprintf(acStack_68);
        uVar6 = 0xffffffff;
        pcVar5 = acStack_68;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        TextOutA(param_1->render_area->DrawDc,(param_1->render_rect).left,
                 (param_1->render_rect).top + -2,acStack_68,~uVar6 - 1);
      }
      SelectObject(param_1->render_area->DrawDc,uVar3);
      SelectClipRgn(param_1->render_area->DrawDc,0);
      TDrawArea::ReleaseDc(param_1->render_area,s_rpnl_tim__draw);
    }
    (**(code **)(iVar8 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048aa65
// Address: 0048aa65
// XREFS: None
undefined4 __fastcall FUN_0048aa65(TPanel *param_1)
{
  uint uVar1;
  
  TPanel::handle_idle(param_1);
  param_1[1].previousPanelValue = (TPanel *)(rge_base_game->world->world_time / 1000);
  uVar1 = rge_base_game->world->old_time / 1000;
  if (uVar1 != 0) {
    if (param_1[1].pnl_x == -1) {
      param_1[1].pnl_x = uVar1;
      param_1[1].pnl_y = 0;
    }
    else {
      param_1[1].pnl_y = uVar1 - param_1[1].pnl_x;
    }
  }
  if (param_1[1].previousPanelValue != param_1[1].previousModalPanelValue) {
    (**(code **)(param_1->_padding_ + 0x20))(1);
    if (param_1->parent_panel != (TPanel *)0x0) {
      (**(code **)(param_1->parent_panel->_padding_ + 0x20))(1);
    }
    param_1[1].previousModalPanelValue = param_1[1].previousPanelValue;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048ab0b
// Address: 0048ab0b
// XREFS: None
undefined4 * __thiscall FUN_0048ab0b(undefined4 *param_1,RGE_Scenario *param_2)
{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  RGE_Scenario *pRVar6;
  char *pcVar7;
  
  *param_1 = &RGE_Scenario_Header::_vftable_;
  param_1[1] = 0;
  param_1[2] = 2;
  uVar2 = time(0);
  param_1[3] = uVar2;
  pcVar3 = RGE_Scenario::Get_description(param_2);
  if (pcVar3 == (char *)0x0) {
    param_1[4] = 0;
    pRVar6 = param_2;
  }
  else {
    pcVar3 = RGE_Scenario::Get_description(param_2);
    uVar4 = 0xffffffff;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar2 = malloc((RGE_Scenario *)~uVar4);
    param_1[4] = uVar2;
    pRVar6 = (RGE_Scenario *)~uVar4;
  }
  if (param_1[4] != 0) {
    pcVar3 = RGE_Scenario::Get_description(param_2);
    uVar4 = 0xffffffff;
    do {
      pcVar7 = pcVar3;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar3 = pcVar7 + -uVar4;
    pcVar7 = (char *)param_1[4];
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    }
    pRVar6->player_name[0].Name[param_1[4] + -0xe] = '\0';
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048abae
// Address: 0048abae
// XREFS: None
undefined4 * __thiscall FUN_0048abae(undefined4 *param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puStack_4;
  
  iVar2 = param_2;
  piVar1 = param_1 + 2;
  param_1[1] = 0;
  *piVar1 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = &RGE_Scenario_Header::_vftable_;
  puStack_4 = param_1;
  rge_read_uncompressed(param_2,&puStack_4,4);
  rge_read_uncompressed(iVar2,piVar1,4);
  if (1 < *piVar1) {
    rge_read_uncompressed(iVar2,param_1 + 3,4);
  }
  rge_read_uncompressed(iVar2,&param_2,4);
  if (0 < param_2) {
    pvVar3 = (void *)malloc(param_2);
    param_1[4] = pvVar3;
    if (pvVar3 == (void *)0x0) {
      param_1[1] = 1;
      return param_1;
    }
    rge_read_uncompressed(iVar2,pvVar3,param_2);
    return param_1;
  }
  param_1[4] = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048ac66
// Address: 0048ac66
// XREFS: None
void __fastcall FUN_0048ac66(undefined4 *param_1)
{
  *param_1 = &RGE_Scenario_Header::_vftable_;
  if (param_1[4] != 0) {
    free(param_1[4]);
    param_1[4] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048ac92
// Address: 0048ac92
// XREFS: None
int __fastcall FUN_0048ac92(int param_1)
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (*(char **)(param_1 + 0x10) == (char *)0x0) {
    return 0xc;
  }
  uVar2 = 0xffffffff;
  pcVar3 = *(char **)(param_1 + 0x10);
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return ~uVar2 + 0xc;
}

// --------------------------------------------------

// Function: FUN_0048acbd
// Address: 0048acbd
// XREFS: None
void __thiscall FUN_0048acbd(undefined4 *param_1,int param_2)
{
  char cVar1;
  char *pcVar2;
  uint uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = (**(code **)*param_1)();
  rge_write_uncompressed(param_2,&uStack_4,4);
  rge_write_uncompressed(param_2,param_1 + 2,4);
  if (1 < (int)param_1[2]) {
    rge_write_uncompressed(param_2,param_1 + 3,4);
  }
  if ((char *)param_1[4] == (char *)0x0) {
    uStack_8 = 0;
  }
  else {
    uStack_8 = 0xffffffff;
    pcVar2 = (char *)param_1[4];
    do {
      if (uStack_8 == 0) break;
      uStack_8 = uStack_8 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uStack_8 = ~uStack_8;
  }
  rge_write_uncompressed(param_2,&uStack_8,4);
  if ((void *)param_1[4] != (void *)0x0) {
    rge_write_uncompressed(param_2,(void *)param_1[4],uStack_8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048ad56
// Address: 0048ad56
// XREFS: None
RGE_Scenario * __thiscall FUN_0048ad56(RGE_Scenario *param_1,RGE_Game_World *param_2)
{
  RGE_Timeline *pRVar1;
  int iVar2;
  PlayerName *pPVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e7bb;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Scenario::_vftable_;
  param_1->world = param_2;
  pRVar1 = (RGE_Timeline *)operator_new(0x14);
  uStack_4 = 0;
  if (pRVar1 == (RGE_Timeline *)0x0) {
    pRVar1 = (RGE_Timeline *)0x0;
  }
  else {
    pRVar1 = (RGE_Timeline *)RGE_Timeline::RGE_Timeline(pRVar1,param_1->world);
  }
  uStack_4 = 0xffffffff;
  param_1->time_line = pRVar1;
  RGE_Scenario::InitializeTextValues(param_1);
  param_1->mission_picture = (TPicture *)0x0;
  param_1->victory_conquest = '\x01';
  pPVar3 = param_1->player_name;
  for (iVar2 = 0x400; iVar2 != 0; iVar2 = iVar2 + -1) {
    pPVar3->Name[0] = '\0';
    pPVar3->Name[1] = '\0';
    pPVar3->Name[2] = '\0';
    pPVar3->Name[3] = '\0';
    pPVar3 = (PlayerName *)(pPVar3->Name + 4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048adea
// Address: 0048adea
// XREFS: None
RGE_Scenario * __thiscall FUN_0048adea(RGE_Scenario *param_1,byte param_2)
{
  RGE_Scenario::~RGE_Scenario(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048ae0e
// Address: 0048ae0e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

RGE_Scenario * __thiscall FUN_0048ae0e(RGE_Scenario *param_1,int param_2,RGE_Game_World *param_3)
{
  int *piVar1;
  RGE_Timeline *pRVar2;
  char *pcVar3;
  TPicture *pTVar4;
  uchar *puVar5;
  int iVar6;
  PlayerName *pPVar7;
  char **ppcVar8;
  int *piVar9;
  undefined4 *unaff_FS_OFFSET;
  short sStack_f6;
  TPicture *pTStack_f4;
  undefined4 uStack_f0;
  undefined1 auStack_ec [224];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e7ec;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Scenario::_vftable_;
  param_1->world = param_3;
  RGE_Scenario::InitializeTextValues(param_1);
  rge_read(param_2,&param_1->Version,4);
  if (_DAT_00572138 < param_1->Version) {
    pPVar7 = param_1->player_name;
    iVar6 = 0x10;
    do {
      rge_read(param_2,pPVar7,0x100);
      pPVar7 = pPVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if ((float)_DAT_00572140 < param_1->Version) {
    piVar9 = param_1->PlType;
    iVar6 = 0x10;
    do {
      rge_read(param_2,piVar9 + 0x20,4);
      rge_read(param_2,piVar9,4);
      rge_read(param_2,piVar9 + 0x10,4);
      rge_read(param_2,piVar9 + -0x10,4);
      piVar9 = piVar9 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (param_1->Version < (float)_DAT_00572148) {
    param_1->victory_conquest = '\x01';
  }
  else {
    rge_read(param_2,&param_1->victory_conquest,1);
  }
  pTStack_f4 = (TPicture *)operator_new(0x14);
  uStack_4 = 0;
  if (pTStack_f4 == (TPicture *)0x0) {
    pRVar2 = (RGE_Timeline *)0x0;
  }
  else {
    pRVar2 = (RGE_Timeline *)
             RGE_Timeline::RGE_Timeline((RGE_Timeline *)pTStack_f4,param_2,param_1->world);
  }
  param_1->time_line = pRVar2;
  uStack_4 = 0xffffffff;
  rge_read(param_2,&sStack_f6,2);
  if (0 < sStack_f6) {
    rge_read(param_2,param_1->scenario_name,(int)sStack_f6);
  }
  param_1->scenario_name[sStack_f6] = '\0';
  rge_read(param_2,&sStack_f6,2);
  if (sStack_f6 < 1) {
    param_1->description = (char *)0x0;
  }
  else {
    pcVar3 = (char *)calloc((int)sStack_f6,1);
    param_1->description = pcVar3;
    rge_read(param_2,pcVar3,(int)sStack_f6);
    param_1->description[sStack_f6 + -1] = '\0';
  }
  if (param_1->Version < (float)_DAT_00572150) {
    param_1->hints = (char *)0x0;
    param_1->win_message = (char *)0x0;
    param_1->loss_message = (char *)0x0;
  }
  else {
    rge_read(param_2,&sStack_f6,2);
    if (sStack_f6 < 1) {
      param_1->hints = (char *)0x0;
    }
    else {
      pcVar3 = (char *)calloc((int)sStack_f6,1);
      param_1->hints = pcVar3;
      rge_read(param_2,pcVar3,(int)sStack_f6);
      param_1->hints[sStack_f6 + -1] = '\0';
    }
    rge_read(param_2,&sStack_f6,2);
    if (sStack_f6 < 1) {
      param_1->win_message = (char *)0x0;
    }
    else {
      pcVar3 = (char *)calloc((int)sStack_f6,1);
      param_1->win_message = pcVar3;
      rge_read(param_2,pcVar3,(int)sStack_f6);
      param_1->win_message[sStack_f6 + -1] = '\0';
    }
    rge_read(param_2,&sStack_f6,2);
    if (sStack_f6 < 1) {
      param_1->loss_message = (char *)0x0;
    }
    else {
      pcVar3 = (char *)calloc((int)sStack_f6,1);
      param_1->loss_message = pcVar3;
      rge_read(param_2,pcVar3,(int)sStack_f6);
      param_1->loss_message[sStack_f6 + -1] = '\0';
    }
    rge_read(param_2,&sStack_f6,2);
    if (0 < sStack_f6) {
      pcVar3 = (char *)calloc((int)sStack_f6,1);
      param_1->historicle_notes = pcVar3;
      rge_read(param_2,pcVar3,(int)sStack_f6);
      goto LAB_0048b152;
    }
  }
  param_1->historicle_notes = (char *)0x0;
LAB_0048b152:
  if (param_1->Version < _DAT_00572158) {
    rge_read(param_2,&sStack_f6,2);
    if (0 < sStack_f6) {
      rge_read(param_2,auStack_ec,(int)sStack_f6);
    }
    rge_read(param_2,&sStack_f6,2);
    if (0 < sStack_f6) {
      rge_read(param_2,auStack_ec,(int)sStack_f6);
    }
    rge_read(param_2,&sStack_f6,2);
    if (0 < sStack_f6) {
      rge_read(param_2,auStack_ec,(int)sStack_f6);
    }
  }
  rge_read(param_2,&sStack_f6,2);
  if (0 < sStack_f6) {
    rge_read(param_2,param_1->Cine_PreGame,(int)sStack_f6);
  }
  param_1->Cine_PreGame[sStack_f6] = '\0';
  rge_read(param_2,&sStack_f6,2);
  if (0 < sStack_f6) {
    rge_read(param_2,param_1->Cine_Victory,(int)sStack_f6);
  }
  param_1->Cine_Victory[sStack_f6] = '\0';
  rge_read(param_2,&sStack_f6,2);
  if (0 < sStack_f6) {
    rge_read(param_2,param_1->Cine_Loss,(int)sStack_f6);
  }
  param_1->Cine_Loss[sStack_f6] = '\0';
  if ((float)_DAT_00572160 <= param_1->Version) {
    rge_read(param_2,&sStack_f6,2);
    if (0 < sStack_f6) {
      rge_read(param_2,param_1->Mission_Bmp,(int)sStack_f6);
    }
    param_1->Mission_Bmp[sStack_f6] = '\0';
  }
  if (param_1->Version < (float)_DAT_00572168) {
    param_1->mission_picture = (TPicture *)0x0;
  }
  else {
    pTStack_f4 = (TPicture *)operator_new(0x20);
    uStack_4 = 1;
    if (pTStack_f4 == (TPicture *)0x0) {
      uStack_4 = 0xffffffff;
      param_1->mission_picture = (TPicture *)0x0;
    }
    else {
      pTVar4 = (TPicture *)TPicture::TPicture(pTStack_f4,param_2,1);
      uStack_4 = 0xffffffff;
      param_1->mission_picture = pTVar4;
    }
  }
  ppcVar8 = param_1->BuildList;
  iVar6 = 0x10;
  do {
    rge_read(param_2,&sStack_f6,2);
    if (0 < sStack_f6) {
      rge_read(param_2,*ppcVar8,(int)sStack_f6);
    }
    pcVar3 = *ppcVar8;
    ppcVar8 = ppcVar8 + 1;
    iVar6 = iVar6 + -1;
    pcVar3[sStack_f6] = '\0';
  } while (iVar6 != 0);
  ppcVar8 = param_1->CityPlan;
  iVar6 = 0x10;
  do {
    rge_read(param_2,&sStack_f6,2);
    if (0 < sStack_f6) {
      rge_read(param_2,*ppcVar8,(int)sStack_f6);
    }
    pcVar3 = *ppcVar8;
    ppcVar8 = ppcVar8 + 1;
    iVar6 = iVar6 + -1;
    pcVar3[sStack_f6] = '\0';
  } while (iVar6 != 0);
  if ((float)_DAT_00572170 <= param_1->Version) {
    ppcVar8 = param_1->AiRules;
    iVar6 = 0x10;
    do {
      rge_read(param_2,&sStack_f6,2);
      if (0 < sStack_f6) {
        rge_read(param_2,*ppcVar8,(int)sStack_f6);
      }
      pcVar3 = *ppcVar8;
      ppcVar8 = ppcVar8 + 1;
      iVar6 = iVar6 + -1;
      pcVar3[sStack_f6] = '\0';
    } while (iVar6 != 0);
  }
  piVar9 = param_1->BuildListFileSize;
  pTStack_f4 = (TPicture *)0x10;
  do {
    rge_read(param_2,piVar9,4);
    piVar1 = piVar9 + 0x10;
    rge_read(param_2,piVar1,4);
    if ((float)_DAT_00572170 <= param_1->Version) {
      rge_read(param_2,piVar9 + 0x20,4);
    }
    piVar9[-0x30] = 0;
    piVar9[-0x20] = 0;
    piVar9[-0x10] = 0;
    if (_DAT_00572178 <= param_1->Version) {
      if (0 < *piVar9) {
        puVar5 = (uchar *)calloc(*piVar9,1);
        piVar9[-0x30] = (int)puVar5;
        rge_read(param_2,puVar5,*piVar9);
      }
      if (0 < *piVar1) {
        puVar5 = (uchar *)calloc(*piVar1,1);
        piVar9[-0x20] = (int)puVar5;
        rge_read(param_2,puVar5,*piVar1);
      }
      if (0 < piVar9[0x20]) {
        puVar5 = (uchar *)calloc(piVar9[0x20],1);
        piVar9[-0x10] = (int)puVar5;
        rge_read(param_2,puVar5,piVar9[0x20]);
      }
    }
    piVar9 = piVar9 + 1;
    pTStack_f4 = (TPicture *)((int)pTStack_f4 + -1);
  } while (pTStack_f4 != (TPicture *)0x0);
  uStack_f0 = 0;
  if (_DAT_0057217c < param_1->Version) {
    rge_read(param_2,&uStack_f0,4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048b57f
// Address: 0048b57f
// XREFS: None
undefined4 FUN_0048b57f(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048b585
// Address: 0048b585
// XREFS: None
void FUN_0048b585(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0048b591
// Address: 0048b591
// XREFS: None
void __fastcall FUN_0048b591(undefined4 *param_1)
{
  TPicture *this;
  int iVar1;
  
  *param_1 = &RGE_Scenario::_vftable_;
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
    param_1[1] = 0;
  }
  if (param_1[0x405] != 0) {
    free(param_1[0x405]);
  }
  if (param_1[0x406] != 0) {
    free(param_1[0x406]);
  }
  if (param_1[0x407] != 0) {
    free(param_1[0x407]);
  }
  if (param_1[0x408] != 0) {
    free(param_1[0x408]);
  }
  if (param_1[0x409] != 0) {
    free(param_1[0x409]);
  }
  operator_delete((void *)param_1[0x404]);
  this = (TPicture *)param_1[0x663];
  if (this != (TPicture *)0x0) {
    TPicture::~TPicture(this);
    operator_delete(this);
    param_1[0x663] = 0;
  }
  param_1 = param_1 + 0x4c2;
  iVar1 = 0x10;
  do {
    operator_delete((void *)param_1[-0x10]);
    operator_delete((void *)*param_1);
    operator_delete((void *)param_1[0x10]);
    if (param_1[0x20] != 0) {
      free(param_1[0x20]);
    }
    if (param_1[0x30] != 0) {
      free(param_1[0x30]);
    }
    if (param_1[0x40] != 0) {
      free(param_1[0x40]);
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0048b908
// Address: 0048b908
// XREFS: None
void __thiscall FUN_0048b908(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    **(undefined1 **)(param_1 + 0x1010) = 0;
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = *(char **)(param_1 + 0x1010);
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

// Function: FUN_0048b94f
// Address: 0048b94f
// XREFS: None
void __thiscall FUN_0048b94f(RGE_Scenario *param_1,char *param_2)
{
  RGE_Scenario::Set_message(param_1,param_2,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0048b95f
// Address: 0048b95f
// XREFS: None
void __thiscall FUN_0048b95f(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0x1508) = 0;
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x1508);
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

// Function: FUN_0048b99d
// Address: 0048b99d
// XREFS: None
void __thiscall FUN_0048b99d(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0x15e8) = 0;
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x15e8);
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

// Function: FUN_0048b9dd
// Address: 0048b9dd
// XREFS: None
void __thiscall FUN_0048b9dd(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0x16c8) = 0;
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x16c8);
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

// Function: FUN_0048ba1d
// Address: 0048ba1d
// XREFS: None
void __thiscall FUN_0048ba1d(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0x17a8) = 0;
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x17a8);
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

// Function: FUN_0048ba5d
// Address: 0048ba5d
// XREFS: None
void __thiscall FUN_0048ba5d(int param_1,int param_2,char *param_3,int param_4)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_3 == (char *)0x0) {
    piVar4 = (int *)(param_1 + 0x12c8 + param_2 * 4);
    **(undefined1 **)(param_1 + 0x12c8 + param_2 * 4) = 0;
  }
  else {
    piVar4 = (int *)(param_1 + 0x12c8 + param_2 * 4);
    uVar2 = 0xffffffff;
    pcVar5 = param_3;
    do {
      pcVar6 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar6 + -uVar2;
    pcVar6 = (char *)*piVar4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  if (param_4 == 1) {
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *param_3;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    *(undefined1 *)((~uVar2 - 5) + *piVar4) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048bacb
// Address: 0048bacb
// XREFS: None
void __thiscall FUN_0048bacb(int param_1,int param_2,char *param_3,int param_4)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_3 == (char *)0x0) {
    piVar4 = (int *)(param_1 + 0x1308 + param_2 * 4);
    **(undefined1 **)(param_1 + 0x1308 + param_2 * 4) = 0;
  }
  else {
    piVar4 = (int *)(param_1 + 0x1308 + param_2 * 4);
    uVar2 = 0xffffffff;
    pcVar5 = param_3;
    do {
      pcVar6 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar6 + -uVar2;
    pcVar6 = (char *)*piVar4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  if (param_4 == 1) {
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *param_3;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    *(undefined1 *)((~uVar2 - 5) + *piVar4) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048bb3b
// Address: 0048bb3b
// XREFS: None
void __thiscall FUN_0048bb3b(int param_1,int param_2,char *param_3,int param_4)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_3 == (char *)0x0) {
    piVar4 = (int *)(param_1 + 0x1348 + param_2 * 4);
    **(undefined1 **)(param_1 + 0x1348 + param_2 * 4) = 0;
  }
  else {
    piVar4 = (int *)(param_1 + 0x1348 + param_2 * 4);
    uVar2 = 0xffffffff;
    pcVar5 = param_3;
    do {
      pcVar6 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar6 + -uVar2;
    pcVar6 = (char *)*piVar4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  if (param_4 == 1) {
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *param_3;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    *(undefined1 *)((~uVar2 - 5) + *piVar4) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048bbab
// Address: 0048bbab
// XREFS: None
void __thiscall FUN_0048bbab(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1888) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0048bbbd
// Address: 0048bbbd
// XREFS: None
void __thiscall FUN_0048bbbd(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    *(undefined4 *)(param_1 + 0x18cc + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048bbdb
// Address: 0048bbdb
// XREFS: None
void __thiscall FUN_0048bbdb(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    *(undefined4 *)(param_1 + 0x190c + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048bbfb
// Address: 0048bbfb
// XREFS: None
void __thiscall FUN_0048bbfb(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    *(undefined4 *)(param_1 + 0x194c + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048bc1b
// Address: 0048bc1b
// XREFS: None
void __thiscall FUN_0048bc1b(int param_1,int param_2,char *param_3)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar2 = 0xffffffff;
  pcVar4 = param_3;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar4 = (char *)(param_2 * 0x100 + 0xd + param_1);
  for (uVar3 = ~uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar4 = *(undefined4 *)param_3;
    param_3 = param_3 + 4;
    pcVar4 = pcVar4 + 4;
  }
  for (uVar2 = ~uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar4 = *param_3;
    param_3 = param_3 + 1;
    pcVar4 = pcVar4 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048bc51
// Address: 0048bc51
// XREFS: None
undefined4 __fastcall FUN_0048bc51(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1010);
}

// --------------------------------------------------

// Function: FUN_0048bc67
// Address: 0048bc67
// XREFS: None
undefined4 __fastcall FUN_0048bc67(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1014);
}

// --------------------------------------------------

// Function: FUN_0048bc77
// Address: 0048bc77
// XREFS: None
int __fastcall FUN_0048bc77(int param_1)
{
  return param_1 + 0x1508;
}

// --------------------------------------------------

// Function: FUN_0048bc87
// Address: 0048bc87
// XREFS: None
int __fastcall FUN_0048bc87(int param_1)
{
  return param_1 + 0x15e8;
}

// --------------------------------------------------

// Function: FUN_0048bc97
// Address: 0048bc97
// XREFS: None
int __fastcall FUN_0048bc97(int param_1)
{
  return param_1 + 0x16c8;
}

// --------------------------------------------------

// Function: FUN_0048bca7
// Address: 0048bca7
// XREFS: None
int __fastcall FUN_0048bca7(int param_1)
{
  return param_1 + 0x17a8;
}

// --------------------------------------------------

// Function: FUN_0048bcb7
// Address: 0048bcb7
// XREFS: None
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s__s_s_ai: "%s%s.ai"
// [HELPER] s__stemp_buildlist_d_tmp: "%stemp_buildlist%d.tmp"
int __fastcall FUN_0048bcb7(int param_1)
{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  bool bVar12;
  byte abStack_18c [8];
  undefined1 *puStack_184;
  undefined4 uStack_180;
  undefined1 auStack_16c [20];
  byte abStack_158 [20];
  undefined1 auStack_144 [32];
  char acStack_124 [8];
  undefined1 auStack_11c [256];
  int iStack_1c;
  int iStack_18;
  
  puStack_184 = auStack_16c;
  uStack_180 = 0x32;
  abStack_18c[4] = 0x7b;
  abStack_18c[5] = 0x27;
  abStack_18c[6] = 0;
  abStack_18c[7] = 0;
  iVar8 = -1;
  abStack_18c[0] = 0xe6;
  abStack_18c[1] = 0xbc;
  abStack_18c[2] = 0x48;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  abStack_18c[0] = 0x32;
  abStack_18c[1] = 0;
  abStack_18c[2] = 0;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,auStack_144);
  iVar4 = GetTempPathA(0x104,auStack_11c);
  if (iVar4 == 0) {
    uVar6 = 0xffffffff;
    pcVar9 = &s__;
    do {
      pcVar11 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar11;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar11 + -uVar6;
    pcVar11 = acStack_124;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar11 = pcVar11 + 1;
    }
  }
  if (((iStack_18 == 1) && (0 < *(int *)(param_1 + 0x1448 + iStack_1c * 4))) &&
     (*(int *)(param_1 + 5000 + iStack_1c * 4) != 0)) {
    sprintf(param_1 + 0x1028,s__stemp_buildlist_d_tmp,acStack_124,iStack_1c);
    iVar8 = __open(param_1 + 0x1028,0x8301,0x180);
  }
  if (iVar8 != -1) {
    write(iVar8,*(undefined4 *)(param_1 + 5000 + iStack_1c * 4),
          *(undefined4 *)(param_1 + 0x1448 + iStack_1c * 4));
    close(iVar8);
    return param_1 + 0x1028;
  }
  if (iStack_18 == 1) {
    pbVar3 = *(byte **)(param_1 + 0x12c8 + iStack_1c * 4);
    pbVar10 = abStack_158;
    pbVar5 = pbVar3;
    do {
      bVar2 = *pbVar5;
      bVar12 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_0048be0e:
        iVar4 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_0048be13;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar12 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_0048be0e;
      pbVar5 = pbVar5 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_0048be13:
    if (iVar4 != 0) {
      pbVar10 = abStack_18c;
      pbVar5 = pbVar3;
      do {
        bVar2 = *pbVar5;
        bVar12 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0048be45:
          iVar4 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_0048be4a;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar12 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0048be45;
        pbVar5 = pbVar5 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_0048be4a:
      if (iVar4 != 0) {
        sprintf(param_1 + 0x1028,s__s_s_ai,rge_base_game->prog_info->ai_dir,pbVar3);
        return param_1 + 0x1028;
      }
    }
  }
  sprintf(param_1 + 0x1028,s__s,*(undefined4 *)(param_1 + 0x12c8 + iStack_1c * 4));
  return param_1 + 0x1028;
}

// --------------------------------------------------

// Function: FUN_0048bebb
// Address: 0048bebb
// XREFS: None
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s__s_s_cty: "%s%s.cty"
// [HELPER] s__stemp_CityPlan_d_tmp: "%stemp_CityPlan%d.tmp"
int __fastcall FUN_0048bebb(int param_1)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  bool bVar12;
  byte abStack_18c [8];
  undefined1 *puStack_184;
  undefined4 uStack_180;
  undefined1 auStack_16c [20];
  byte abStack_158 [20];
  undefined1 auStack_144 [32];
  char acStack_124 [8];
  undefined1 auStack_11c [256];
  int iStack_1c;
  int iStack_18;
  
  puStack_184 = auStack_16c;
  uStack_180 = 0x32;
  abStack_18c[4] = 0x7b;
  abStack_18c[5] = 0x27;
  abStack_18c[6] = 0;
  abStack_18c[7] = 0;
  iVar8 = -1;
  abStack_18c[0] = 0xe6;
  abStack_18c[1] = 0xbe;
  abStack_18c[2] = 0x48;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  abStack_18c[0] = 0x32;
  abStack_18c[1] = 0;
  abStack_18c[2] = 0;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,auStack_144);
  iVar3 = GetTempPathA(0x104,auStack_11c);
  if (iVar3 == 0) {
    uVar6 = 0xffffffff;
    pcVar9 = &s__;
    do {
      pcVar11 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar11;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar11 + -uVar6;
    pcVar11 = acStack_124;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar11 = pcVar11 + 1;
    }
  }
  if (((iStack_18 == 1) && (0 < *(int *)(param_1 + 0x1488 + iStack_1c * 4))) &&
     (*(int *)(param_1 + 0x13c8 + iStack_1c * 4) != 0)) {
    sprintf(param_1 + 0x1108,s__stemp_CityPlan_d_tmp,acStack_124,iStack_1c);
    iVar8 = __open(param_1 + 0x1108,0x8301,0x180);
  }
  if (iVar8 != -1) {
    write(iVar8,*(undefined4 *)(param_1 + 0x13c8 + iStack_1c * 4),
          *(undefined4 *)(param_1 + 0x1488 + iStack_1c * 4));
    close(iVar8);
    return param_1 + 0x1108;
  }
  if (iStack_18 == 1) {
    pbVar5 = *(byte **)(param_1 + 0x12c8 + iStack_1c * 4);
    pbVar10 = abStack_158;
    pbVar4 = pbVar5;
    do {
      bVar2 = *pbVar4;
      bVar12 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_0048c00e:
        iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_0048c013;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar12 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_0048c00e;
      pbVar4 = pbVar4 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_0048c013:
    if (iVar3 != 0) {
      pbVar10 = abStack_18c;
      do {
        bVar2 = *pbVar5;
        bVar12 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0048c045:
          iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_0048c04a;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar12 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0048c045;
        pbVar5 = pbVar5 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar3 = 0;
LAB_0048c04a:
      if (iVar3 != 0) {
        sprintf(param_1 + 0x1108,s__s_s_cty,rge_base_game->prog_info->ai_dir,
                *(undefined4 *)(param_1 + 0x1308 + iStack_1c * 4));
        return param_1 + 0x1108;
      }
    }
  }
  sprintf(param_1 + 0x1108,s__s,*(undefined4 *)(param_1 + 0x1308 + iStack_1c * 4));
  return param_1 + 0x1108;
}

// --------------------------------------------------

// Function: FUN_0048c0c9
// Address: 0048c0c9
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0048c0c9(void)
{
  return (float10)_DAT_00572178;
}

// --------------------------------------------------

// Function: FUN_0048c0d7
// Address: 0048c0d7
// XREFS: None
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s__s_s_per: "%s%s.per"
// [HELPER] s__stemp_AiRules_d_tmp: "%stemp_AiRules%d.tmp"
int __fastcall FUN_0048c0d7(int param_1)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  bool bVar12;
  byte abStack_18c [8];
  undefined1 *puStack_184;
  undefined4 uStack_180;
  undefined1 auStack_16c [20];
  byte abStack_158 [20];
  undefined1 auStack_144 [32];
  char acStack_124 [8];
  undefined1 auStack_11c [256];
  int iStack_1c;
  int iStack_18;
  
  puStack_184 = auStack_16c;
  uStack_180 = 0x32;
  abStack_18c[4] = 0x7b;
  abStack_18c[5] = 0x27;
  abStack_18c[6] = 0;
  abStack_18c[7] = 0;
  iVar8 = -1;
  abStack_18c[0] = 6;
  abStack_18c[1] = 0xc1;
  abStack_18c[2] = 0x48;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  abStack_18c[0] = 0x32;
  abStack_18c[1] = 0;
  abStack_18c[2] = 0;
  abStack_18c[3] = 0;
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,auStack_144);
  iVar3 = GetTempPathA(0x104,auStack_11c);
  if (iVar3 == 0) {
    uVar6 = 0xffffffff;
    pcVar9 = &s__;
    do {
      pcVar11 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar11;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar11 + -uVar6;
    pcVar11 = acStack_124;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar11 = pcVar11 + 1;
    }
  }
  if (((iStack_18 == 1) && (0 < *(int *)(param_1 + 0x14c8 + iStack_1c * 4))) &&
     (*(int *)(param_1 + 0x1408 + iStack_1c * 4) != 0)) {
    sprintf(param_1 + 0x11e8,s__stemp_AiRules_d_tmp,acStack_124,iStack_1c);
    iVar8 = __open(param_1 + 0x11e8,0x8301,0x180);
  }
  if (iVar8 != -1) {
    write(iVar8,*(undefined4 *)(param_1 + 0x1408 + iStack_1c * 4),
          *(undefined4 *)(param_1 + 0x14c8 + iStack_1c * 4));
    close(iVar8);
    return param_1 + 0x11e8;
  }
  if (iStack_18 == 1) {
    pbVar5 = *(byte **)(param_1 + 0x12c8 + iStack_1c * 4);
    pbVar10 = abStack_158;
    pbVar4 = pbVar5;
    do {
      bVar2 = *pbVar4;
      bVar12 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_0048c22e:
        iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_0048c233;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar12 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_0048c22e;
      pbVar4 = pbVar4 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_0048c233:
    if (iVar3 != 0) {
      pbVar10 = abStack_18c;
      do {
        bVar2 = *pbVar5;
        bVar12 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_0048c265:
          iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_0048c26a;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar12 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_0048c265;
        pbVar5 = pbVar5 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar3 = 0;
LAB_0048c26a:
      if (iVar3 != 0) {
        sprintf(param_1 + 0x11e8,s__s_s_per,rge_base_game->prog_info->ai_dir,
                *(undefined4 *)(param_1 + 0x1348 + iStack_1c * 4));
        return param_1 + 0x11e8;
      }
    }
  }
  sprintf(param_1 + 0x11e8,s__s,*(undefined4 *)(param_1 + 0x1348 + iStack_1c * 4));
  return param_1 + 0x11e8;
}

// --------------------------------------------------

// Function: FUN_0048c2e9
// Address: 0048c2e9
// XREFS: None
undefined4 __thiscall FUN_0048c2e9(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 9)) {
    switch(*(undefined4 *)(param_1 + 0x188c + param_2 * 4)) {
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 3;
    case 4:
      return 4;
    case 5:
      return 5;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048c33d
// Address: 0048c33d
// XREFS: None
void __fastcall FUN_0048c33d(undefined4 param_1,char param_2)
{
  int in_EAX;
  
  *(char *)(in_EAX + -1) = *(char *)(in_EAX + -1) + param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0048c36e
// Address: 0048c36e
// XREFS: None
undefined4 __thiscall FUN_0048c36e(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x18cc + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048c38c
// Address: 0048c38c
// XREFS: None
undefined4 __thiscall FUN_0048c38c(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x190c + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048c3ac
// Address: 0048c3ac
// XREFS: None
undefined4 __thiscall FUN_0048c3ac(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x194c + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048c3cc
// Address: 0048c3cc
// XREFS: None
void __fastcall FUN_0048c3cc(int param_1)
{
  if (*(RGE_Timeline **)(param_1 + 4) != (RGE_Timeline *)0x0) {
    RGE_Timeline::update(*(RGE_Timeline **)(param_1 + 4));
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048c3dd
// Address: 0048c3dd
// XREFS: None
// [HELPER] s__s_bmp: "%s.bmp"
// [HELPER] s__s_s_ai: "%s%s.ai"
// [HELPER] s__s_s_cty: "%s%s.cty"
// [HELPER] s__s_s_per: "%s%s.per"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0048c3dd(RGE_Scenario *param_1,int param_2)
{
  float *pfVar1;
  char cVar2;
  TPicture *this;
  int iVar3;
  uchar *puVar4;
  uint uVar5;
  PlayerName *pPVar6;
  int *piVar7;
  char **ppcVar8;
  int iVar9;
  char *pcVar10;
  TPicture *pTVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  float fVar13;
  uint uStack_1e0;
  int iStack_1dc;
  TPicture *pTStack_1d8;
  float *pfStack_1d4;
  undefined4 uStack_1d0;
  undefined1 auStack_1cc [224];
  char acStack_ec [224];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e80e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pfVar1 = &param_1->Version;
  pfStack_1d4 = pfVar1;
  fVar13 = RGE_Scenario::Get_Version(param_1);
  *pfVar1 = fVar13;
  rge_write(param_2,pfVar1,4);
  pPVar6 = param_1->player_name;
  iVar9 = 0x10;
  do {
    rge_write(param_2,pPVar6,0x100);
    pPVar6 = pPVar6 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  piVar7 = param_1->PlType;
  iVar9 = 0x10;
  do {
    rge_write(param_2,piVar7 + 0x20,4);
    rge_write(param_2,piVar7,4);
    rge_write(param_2,piVar7 + 0x10,4);
    rge_write(param_2,piVar7 + -0x10,4);
    piVar7 = piVar7 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  rge_write(param_2,&param_1->victory_conquest,1);
  if (param_1->time_line != (RGE_Timeline *)0x0) {
    RGE_Timeline::save(param_1->time_line,param_2);
  }
  if (param_1->scenario_name == (char *)0x0) {
    uStack_1e0 = 0;
  }
  else {
    uVar5 = 0xffffffff;
    pcVar12 = param_1->scenario_name;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    uStack_1e0 = ~uVar5 - 1;
  }
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->scenario_name,(int)(short)uStack_1e0);
  }
  if (param_1->description == (char *)0x0) {
    uStack_1e0 = 0;
  }
  else {
    uStack_1e0 = 0xffffffff;
    pcVar12 = param_1->description;
    do {
      if (uStack_1e0 == 0) break;
      uStack_1e0 = uStack_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    uStack_1e0 = ~uStack_1e0;
  }
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->description,(int)(short)uStack_1e0);
  }
  if (param_1->hints == (char *)0x0) {
    uStack_1e0 = 0;
  }
  else {
    uStack_1e0 = 0xffffffff;
    pcVar12 = param_1->hints;
    do {
      if (uStack_1e0 == 0) break;
      uStack_1e0 = uStack_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    uStack_1e0 = ~uStack_1e0;
  }
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->hints,(int)(short)uStack_1e0);
  }
  if (param_1->win_message == (char *)0x0) {
    uStack_1e0 = 0;
  }
  else {
    uStack_1e0 = 0xffffffff;
    pcVar12 = param_1->win_message;
    do {
      if (uStack_1e0 == 0) break;
      uStack_1e0 = uStack_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    uStack_1e0 = ~uStack_1e0;
  }
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->win_message,(int)(short)uStack_1e0);
  }
  if (param_1->loss_message == (char *)0x0) {
    uStack_1e0 = 0;
  }
  else {
    uStack_1e0 = 0xffffffff;
    pcVar12 = param_1->loss_message;
    do {
      if (uStack_1e0 == 0) break;
      uStack_1e0 = uStack_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    uStack_1e0 = ~uStack_1e0;
  }
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->loss_message,(int)(short)uStack_1e0);
  }
  if (param_1->historicle_notes == (char *)0x0) {
    uStack_1e0 = 0;
  }
  else {
    uStack_1e0 = 0xffffffff;
    pcVar12 = param_1->historicle_notes;
    do {
      if (uStack_1e0 == 0) break;
      uStack_1e0 = uStack_1e0 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    uStack_1e0 = ~uStack_1e0;
  }
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->historicle_notes,(int)(short)uStack_1e0);
  }
  uVar5 = 0xffffffff;
  pcVar12 = param_1->Cine_PreGame;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  uStack_1e0 = ~uVar5 - 1;
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->Cine_PreGame,(int)(short)uStack_1e0);
  }
  uVar5 = 0xffffffff;
  pcVar12 = param_1->Cine_Victory;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  uStack_1e0 = ~uVar5 - 1;
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->Cine_Victory,(int)(short)uStack_1e0);
  }
  uVar5 = 0xffffffff;
  pcVar12 = param_1->Cine_Loss;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar2 != '\0');
  uStack_1e0 = ~uVar5 - 1;
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,param_1->Cine_Loss,(int)(short)uStack_1e0);
  }
  pcVar12 = param_1->Mission_Bmp;
  uVar5 = 0xffffffff;
  pcVar10 = pcVar12;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
  uStack_1e0 = ~uVar5 - 1;
  rge_write(param_2,&uStack_1e0,2);
  if (0 < (short)uStack_1e0) {
    rge_write(param_2,pcVar12,(int)(short)uStack_1e0);
  }
  sprintf(acStack_ec,s__s_bmp,pcVar12);
  pTStack_1d8 = (TPicture *)operator_new(0x20);
  pTVar11 = (TPicture *)0x0;
  uStack_4 = 0;
  if (pTStack_1d8 != (TPicture *)0x0) {
    pTVar11 = (TPicture *)TPicture::TPicture(pTStack_1d8,acStack_ec,-1,0,(void *)0x0,0);
  }
  this = param_1->mission_picture;
  uStack_4 = 0xffffffff;
  if (this != (TPicture *)0x0) {
    if (pTVar11->Dib == (tagBITMAPINFOHEADER *)0x0) {
      if (pTVar11 != (TPicture *)0x0) {
        TPicture::~TPicture(pTVar11);
        operator_delete(pTVar11);
      }
      goto LAB_0048c7f6;
    }
    if (this != (TPicture *)0x0) {
      TPicture::~TPicture(this);
      operator_delete(this);
    }
  }
  param_1->mission_picture = pTVar11;
LAB_0048c7f6:
  TPicture::Save(param_1->mission_picture,param_2);
  ppcVar8 = param_1->BuildList;
  iStack_1dc = 0x10;
  do {
    uVar5 = 0xffffffff;
    pcVar12 = *ppcVar8;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    uStack_1e0 = ~uVar5 - 1;
    rge_write(param_2,&uStack_1e0,2);
    if (0 < (short)uStack_1e0) {
      rge_write(param_2,*ppcVar8,(int)(short)uStack_1e0);
    }
    ppcVar8 = ppcVar8 + 1;
    iStack_1dc = iStack_1dc + -1;
  } while (iStack_1dc != 0);
  ppcVar8 = param_1->CityPlan;
  iStack_1dc = 0x10;
  pTStack_1d8 = (TPicture *)ppcVar8;
  do {
    uVar5 = 0xffffffff;
    pcVar12 = *ppcVar8;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    uStack_1e0 = ~uVar5 - 1;
    rge_write(param_2,&uStack_1e0,2);
    if (0 < (short)uStack_1e0) {
      rge_write(param_2,*ppcVar8,(int)(short)uStack_1e0);
    }
    ppcVar8 = ppcVar8 + 1;
    iStack_1dc = iStack_1dc + -1;
  } while (iStack_1dc != 0);
  if ((float)_DAT_00572170 <= *pfStack_1d4) {
    ppcVar8 = param_1->AiRules;
    iVar9 = 0x10;
    iStack_1dc = 0;
    do {
      uVar5 = 0xffffffff;
      pcVar12 = *ppcVar8;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar2 = *pcVar12;
        pcVar12 = pcVar12 + 1;
      } while (cVar2 != '\0');
      uStack_1e0 = ~uVar5 - 1;
      rge_write(param_2,&uStack_1e0,2);
      if (0 < (short)uStack_1e0) {
        rge_write(param_2,*ppcVar8,(int)(short)uStack_1e0);
      }
      ppcVar8 = ppcVar8 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iStack_1dc = 0x10;
  pTVar11 = pTStack_1d8;
  do {
    if (*(char **)((int)pTVar11 + -0x40) != (char *)0x0) {
      sprintf(auStack_1cc,s__s_s_ai,rge_base_game->prog_info->ai_dir,
              *(char **)((int)pTVar11 + -0x40));
      iVar9 = __open(auStack_1cc,0x8000);
      if (-1 < iVar9) {
        lseek(iVar9,0,2);
        iVar3 = __tell(iVar9);
        *(int *)((int)pTVar11 + 0x140) = iVar3;
        if (*(uchar **)((int)pTVar11 + 0x80) != (uchar *)0x0) {
          free(*(uchar **)((int)pTVar11 + 0x80));
        }
        puVar4 = (uchar *)calloc(*(int *)((int)pTVar11 + 0x140),1);
        *(uchar **)((int)pTVar11 + 0x80) = puVar4;
        lseek(iVar9,0,0);
        read(iVar9,*(uchar **)((int)pTVar11 + 0x80),*(int *)((int)pTVar11 + 0x140));
        close(iVar9);
      }
    }
    if (*(char **)pTVar11 != (char *)0x0) {
      sprintf(auStack_1cc,s__s_s_cty,rge_base_game->prog_info->ai_dir,*(char **)pTVar11);
      iVar9 = __open(auStack_1cc,0x8000);
      if (-1 < iVar9) {
        lseek(iVar9,0,2);
        iVar3 = __tell(iVar9);
        *(int *)((int)pTVar11 + 0x180) = iVar3;
        if (*(uchar **)((int)pTVar11 + 0xc0) != (uchar *)0x0) {
          free(*(uchar **)((int)pTVar11 + 0xc0));
        }
        puVar4 = (uchar *)calloc(*(int *)((int)pTVar11 + 0x180),1);
        *(uchar **)((int)pTVar11 + 0xc0) = puVar4;
        lseek(iVar9,0,0);
        read(iVar9,*(uchar **)((int)pTVar11 + 0xc0),*(int *)((int)pTVar11 + 0x180));
        close(iVar9);
      }
    }
    if (*(char **)((int)pTVar11 + 0x40) != (char *)0x0) {
      sprintf(auStack_1cc,s__s_s_per,rge_base_game->prog_info->ai_dir,
              *(char **)((int)pTVar11 + 0x40));
      iVar9 = __open(auStack_1cc,0x8000);
      if (-1 < iVar9) {
        lseek(iVar9,0,2);
        iVar3 = __tell(iVar9);
        *(int *)((int)pTVar11 + 0x1c0) = iVar3;
        if (*(uchar **)((int)pTVar11 + 0x100) != (uchar *)0x0) {
          free(*(uchar **)((int)pTVar11 + 0x100));
        }
        puVar4 = (uchar *)calloc(*(int *)((int)pTVar11 + 0x1c0),1);
        *(uchar **)((int)pTVar11 + 0x100) = puVar4;
        lseek(iVar9,0,0);
        read(iVar9,*(uchar **)((int)pTVar11 + 0x100),*(int *)((int)pTVar11 + 0x1c0));
        close(iVar9);
      }
    }
    rge_write(param_2,(int *)((int)pTVar11 + 0x140),4);
    rge_write(param_2,(int *)((int)pTVar11 + 0x180),4);
    if ((float)_DAT_00572170 <= *pfStack_1d4) {
      rge_write(param_2,(int *)((int)pTVar11 + 0x1c0),4);
    }
    if (*(uchar **)((int)pTVar11 + 0x80) != (uchar *)0x0) {
      rge_write(param_2,*(uchar **)((int)pTVar11 + 0x80),*(int *)((int)pTVar11 + 0x140));
    }
    if (*(uchar **)((int)pTVar11 + 0xc0) != (uchar *)0x0) {
      rge_write(param_2,*(uchar **)((int)pTVar11 + 0xc0),*(int *)((int)pTVar11 + 0x180));
    }
    if (*(uchar **)((int)pTVar11 + 0x100) != (uchar *)0x0) {
      rge_write(param_2,*(uchar **)((int)pTVar11 + 0x100),*(int *)((int)pTVar11 + 0x1c0));
    }
    pTVar11 = (TPicture *)((int)pTVar11 + 4);
    iStack_1dc = iStack_1dc + -1;
  } while (iStack_1dc != 0);
  uStack_1d0 = 0xffffff9d;
  rge_write(param_2,&uStack_1d0,4);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0048cc1c
// Address: 0048cc1c
// XREFS: None
int __fastcall FUN_0048cc1c(RGE_Scenario *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = RGE_Scenario::Get_player_Active(param_1,iVar3);
    if (iVar1 != 0) {
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0048cc42
// Address: 0048cc42
// XREFS: None
int __fastcall FUN_0048cc42(RGE_Scenario *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = RGE_Scenario::Get_player_Active(param_1,iVar3);
    if (iVar1 != 0) {
      iVar1 = RGE_Scenario::Get_player_Type(param_1,iVar3);
      if (iVar1 == 1) {
        iVar2 = iVar2 + 1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0048cc7f
// Address: 0048cc7f
// XREFS: None
int __fastcall FUN_0048cc7f(RGE_Scenario *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = RGE_Scenario::Get_player_Active(param_1,iVar3);
    if (iVar1 != 0) {
      iVar1 = RGE_Scenario::Get_player_Type(param_1,iVar3);
      if (iVar1 == 0) {
        iVar2 = iVar2 + 1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0048ccae
// Address: 0048ccae
// XREFS: None
void __thiscall FUN_0048ccae(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0048ccba
// Address: 0048ccba
// XREFS: None
undefined1 __fastcall FUN_0048ccba(int param_1)
{
  return *(undefined1 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_0048ccc4
// Address: 0048ccc4
// XREFS: None
void __thiscall FUN_0048ccc4(int param_1,char *param_2)
{
  if (*(char **)(param_1 + 0x1014) == (char *)0x0) {
    getstring((char **)(param_1 + 0x1014),param_2);
    return;
  }
  addstring((char **)(param_1 + 0x1014),*(char **)(param_1 + 0x1014),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0048cd03
// Address: 0048cd03
// XREFS: None
void __thiscall FUN_0048cd03(int param_1,char *param_2,undefined4 param_3)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar2 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
  }
  if ((int)uVar4 < 1) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = (char *)calloc(uVar4,1);
  }
  pcVar5 = pcVar2;
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar5 = *param_2;
    param_2 = param_2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  switch(param_3) {
  case 0:
    if (*(int *)(param_1 + 0x1014) != 0) {
      free(*(int *)(param_1 + 0x1014));
    }
    break;
  case 1:
    if (*(int *)(param_1 + 0x1018) != 0) {
      free(*(int *)(param_1 + 0x1018));
    }
    *(char **)(param_1 + 0x1018) = pcVar2;
    return;
  case 2:
    if (*(int *)(param_1 + 0x101c) == 0) {
      free(0);
    }
    *(char **)(param_1 + 0x101c) = pcVar2;
    return;
  case 3:
    if (*(int *)(param_1 + 0x1020) != 0) {
      free(*(int *)(param_1 + 0x1020));
    }
    *(char **)(param_1 + 0x1020) = pcVar2;
    return;
  case 4:
    if (*(int *)(param_1 + 0x1024) != 0) {
      free(*(int *)(param_1 + 0x1024));
    }
    *(char **)(param_1 + 0x1024) = pcVar2;
    return;
  default:
    if (pcVar2 != (char *)0x0) {
      free(pcVar2);
    }
    return;
  }
  *(char **)(param_1 + 0x1014) = pcVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_0048ce21
// Address: 0048ce21
// XREFS: None
undefined4 __fastcall FUN_0048ce21(undefined4 param_1,undefined2 param_2)
{
  char *pcVar1;
  undefined1 uVar2;
  code *pcVar3;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  char extraout_DL;
  int unaff_EBP;
  undefined1 *unaff_EDI;
  undefined4 in_stack_00000010;
  
  uVar2 = in(param_2);
  *unaff_EDI = uVar2;
  pcVar3 = (code *)swi(0x48);
  (*pcVar3)();
  pcVar1 = (char *)(unaff_EBP + -0x3253ffb8 + extraout_ECX * 8);
  *pcVar1 = *pcVar1 + (char)extraout_ECX;
  pcVar3 = (code *)swi(0x48);
  (*pcVar3)();
  pcVar3 = (code *)swi(0x48);
  iVar4 = (*pcVar3)();
  *(char *)(iVar4 + -0x6f6f6f70) = *(char *)(iVar4 + -0x6f6f6f70) + extraout_DL;
  switch(in_stack_00000010) {
  case 0:
    return *(undefined4 *)(extraout_ECX_00 + 0x1014);
  case 1:
    return *(undefined4 *)(extraout_ECX_00 + 0x1018);
  case 2:
    return *(undefined4 *)(extraout_ECX_00 + 0x101c);
  case 3:
    return *(undefined4 *)(extraout_ECX_00 + 0x1020);
  case 4:
    return *(undefined4 *)(extraout_ECX_00 + 0x1024);
  default:
    return 0;
  }
}

// --------------------------------------------------

// Function: FUN_0048ce82
// Address: 0048ce82
// XREFS: None
RGE_Scenario_File_Info * __fastcall FUN_0048ce82(RGE_Scenario_File_Info *param_1,undefined4 param_2)
{
  long *plVar1;
  char cVar2;
  code *pcVar3;
  undefined4 in_EAX;
  int iVar4;
  RGE_Scenario_File_Entry *pRVar5;
  undefined4 uVar6;
  RGE_Scenario_File_Info *extraout_ECX;
  uint uVar7;
  uint uVar8;
  int unaff_EBX;
  int iVar9;
  int unaff_ESI;
  char *pcVar10;
  int iVar11;
  RGE_Scenario_File_Info *pRVar12;
  char in_OF;
  undefined8 uVar13;
  char *unaff_retaddr;
  
  uVar13 = CONCAT44(param_2,in_EAX);
  pcVar3 = (code *)swi(4);
  if (in_OF == '\x01') {
    uVar13 = (*pcVar3)();
    param_1 = extraout_ECX;
  }
  param_1[-1].filename[0xda] = param_1[-1].filename[0xda] + (char)unaff_EBX;
  pcVar10 = (char *)((int)((ulonglong)uVar13 >> 0x20) + -0x32);
  *pcVar10 = *pcVar10 + (char)((uint)((int)uVar13 + -2) >> 8);
  *(char *)(unaff_EBX + -0x32) = *(char *)(unaff_EBX + -0x32) + (char)((uint)param_1 >> 8);
  pcVar10 = (char *)(unaff_ESI + 0x48 + (int)param_1 * 8);
  *pcVar10 = *pcVar10 + (char)((ulonglong)uVar13 >> 0x28);
  pcVar10 = (char *)((int)uVar13 + -0x6f6f6f74);
  *pcVar10 = *pcVar10 + (char)((ulonglong)uVar13 >> 0x20);
  uVar7 = 0xffffffff;
  do {
    pcVar10 = unaff_retaddr;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar10 = unaff_retaddr + 1;
    cVar2 = *unaff_retaddr;
    unaff_retaddr = pcVar10;
  } while (cVar2 != '\0');
  uVar7 = ~uVar7;
  pcVar10 = pcVar10 + -uVar7;
  pRVar12 = param_1;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pRVar12->filename = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pRVar12 = (RGE_Scenario_File_Info *)(pRVar12->filename + 4);
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    pRVar12->filename[0] = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pRVar12 = (RGE_Scenario_File_Info *)(pRVar12->filename + 1);
  }
  iVar4 = rge_open(param_1->filename,0x8000);
  if (iVar4 != -1) {
    plVar1 = &param_1->scenario_num;
    rge_read_uncompressed(iVar4,plVar1,4);
    iVar9 = 0;
    if (*plVar1 < 1) {
      param_1->scenarios = (RGE_Scenario_File_Entry *)0x0;
    }
    else {
      pRVar5 = (RGE_Scenario_File_Entry *)calloc(*plVar1,0x10c);
      param_1->scenarios = pRVar5;
      if (0 < *plVar1) {
        iVar11 = 0;
        do {
          rge_read_uncompressed(iVar4,param_1->scenarios->name + iVar11 + -8,4);
          rge_read_uncompressed(iVar4,param_1->scenarios->name + iVar11,0x104);
          uVar6 = (**(code **)(rge_base_game->_padding_ + 0x38))(iVar4);
          iVar9 = iVar9 + 1;
          *(undefined4 *)(param_1->scenarios->name + iVar11 + -4) = uVar6;
          iVar11 = iVar11 + 0x10c;
        } while (iVar9 < param_1->scenario_num);
        rge_close(iVar4);
        RGE_Scenario_File_Info::reload_scenarios(param_1);
        return param_1;
      }
    }
    rge_close(iVar4);
    RGE_Scenario_File_Info::reload_scenarios(param_1);
    return param_1;
  }
  param_1->scenario_num = 0;
  param_1->scenarios = (RGE_Scenario_File_Entry *)0x0;
  RGE_Scenario_File_Info::reload_scenarios(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048cfc4
// Address: 0048cfc4
// XREFS: None
void __fastcall FUN_0048cfc4(RGE_Scenario_File_Info *param_1)
{
  RGE_Scenario_Header *this;
  int iVar1;
  int iVar2;
  
  RGE_Scenario_File_Info::save(param_1);
  if (0 < param_1->scenario_num) {
    iVar2 = 0;
    if (0 < param_1->scenario_num) {
      iVar1 = 0;
      do {
        this = *(RGE_Scenario_Header **)(param_1->scenarios->name + iVar1 + -4);
        if (this != (RGE_Scenario_Header *)0x0) {
          RGE_Scenario_Header::~RGE_Scenario_Header(this);
          operator_delete(this);
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x10c;
      } while (iVar2 < param_1->scenario_num);
    }
    free(param_1->scenarios);
    param_1->scenarios = (RGE_Scenario_File_Entry *)0x0;
    param_1->scenario_num = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048d03e
// Address: 0048d03e
// XREFS: None
void __fastcall FUN_0048d03e(char *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = rge_open(param_1,0x8301,0x180);
  if (iVar1 != -1) {
    rge_write_uncompressed(iVar1,param_1 + 0x104,4);
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x104)) {
      iVar3 = 0;
      do {
        rge_write_uncompressed(iVar1,(void *)(*(int *)(param_1 + 0x108) + iVar3),4);
        rge_write_uncompressed(iVar1,(void *)(*(int *)(param_1 + 0x108) + 8 + iVar3),0x104);
        (**(code **)(**(int **)(*(int *)(param_1 + 0x108) + 4 + iVar3) + 4))(iVar1);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x10c;
      } while (iVar2 < *(int *)(param_1 + 0x104));
    }
    rge_close(iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048d0d8
// Address: 0048d0d8
// XREFS: None
// [HELPER] s__s__scn: "%s*.scn"
// [HELPER] s__s__scx: "%s*.scx"
// [HELPER] s__s_s: "%s%s"
void __fastcall FUN_0048d0d8(int param_1)
{
  char cVar1;
  byte bVar2;
  RGE_Scenario_Header *this;
  bool bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  char *pcVar15;
  char *pcVar16;
  bool bVar17;
  bool bVar18;
  int iStack_228;
  undefined1 auStack_21c [4];
  char acStack_218 [256];
  undefined1 auStack_118 [12];
  int iStack_10c;
  byte abStack_104 [260];
  
  iVar14 = 0;
  sprintf(acStack_218,s__s__scn,rge_base_game->prog_info->scenario_dir);
  iVar4 = __findfirst(acStack_218,auStack_118);
  iVar5 = iVar4;
  while (iVar5 != -1) {
    iVar14 = iVar14 + 1;
    iVar5 = __findnext(iVar4,auStack_118);
  }
  sprintf(acStack_218,s__s__scx,rge_base_game->prog_info->scenario_dir);
  iVar4 = __findfirst(acStack_218,auStack_118);
  iVar5 = iVar4;
  while (iVar5 != -1) {
    iVar14 = iVar14 + 1;
    iVar5 = __findnext(iVar4,auStack_118);
  }
  sprintf(acStack_218,s__s__scn,rge_base_game->prog_info->scenario_dir);
  if (0 < iVar14) {
    iStack_228 = __findfirst(acStack_218,auStack_118);
    bVar18 = iStack_228 == -1;
    if (bVar18) {
      sprintf(acStack_218,s__s__scx,rge_base_game->prog_info->scenario_dir);
      iStack_228 = __findfirst(acStack_218,auStack_118);
    }
    if (iStack_228 != -1) {
      iVar5 = calloc(iVar14,0x10c);
      pbVar12 = (byte *)(iVar5 + 4);
LAB_0048d24d:
      iVar4 = 0;
      bVar3 = false;
      if (0 < *(int *)(param_1 + 0x104)) {
        pbVar6 = (byte *)(*(int *)(param_1 + 0x108) + 8);
        do {
          pbVar13 = abStack_104;
          pbVar7 = pbVar6;
          do {
            bVar2 = *pbVar7;
            bVar17 = bVar2 < *pbVar13;
            if (bVar2 != *pbVar13) {
LAB_0048d29a:
              iVar8 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
              goto LAB_0048d29f;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar7[1];
            bVar17 = bVar2 < pbVar13[1];
            if (bVar2 != pbVar13[1]) goto LAB_0048d29a;
            pbVar7 = pbVar7 + 2;
            pbVar13 = pbVar13 + 2;
          } while (bVar2 != 0);
          iVar8 = 0;
LAB_0048d29f:
          if (iVar8 == 0) {
            iVar4 = iVar4 * 0x10c;
            if (iStack_10c <= *(int *)(*(int *)(param_1 + 0x108) + iVar4)) {
              uVar10 = 0xffffffff;
              pcVar15 = (char *)(*(int *)(param_1 + 0x108) + 8 + iVar4);
              goto code_r0x0048d2e8;
            }
            break;
          }
          iVar4 = iVar4 + 1;
          pbVar6 = pbVar6 + 0x10c;
        } while (iVar4 < *(int *)(param_1 + 0x104));
      }
      goto LAB_0048d332;
    }
  }
  return;
  while( true ) {
    uVar10 = uVar10 - 1;
    pcVar16 = pcVar15 + 1;
    cVar1 = *pcVar15;
    pcVar15 = pcVar16;
    if (cVar1 == '\0') break;
code_r0x0048d2e8:
    pcVar16 = pcVar15;
    if (uVar10 == 0) break;
  }
  uVar10 = ~uVar10;
  bVar3 = true;
  pbVar13 = (byte *)(pcVar16 + -uVar10);
  pbVar6 = pbVar12;
  for (uVar11 = uVar10 >> 2; pbVar6 = pbVar6 + 4, uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pbVar6 = *(undefined4 *)pbVar13;
    pbVar13 = pbVar13 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pbVar6 = *pbVar13;
    pbVar13 = pbVar13 + 1;
    pbVar6 = pbVar6 + 1;
  }
  *(undefined4 *)(pbVar12 + -4) = *(undefined4 *)(iVar4 + *(int *)(param_1 + 0x108));
  *(undefined4 *)pbVar12 = *(undefined4 *)(iVar4 + 4 + *(int *)(param_1 + 0x108));
  *(undefined4 *)(iVar4 + 4 + *(int *)(param_1 + 0x108)) = 0;
LAB_0048d332:
  if (!bVar3) {
    uVar10 = 0xffffffff;
    pbVar6 = abStack_104;
    do {
      pbVar13 = pbVar6;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pbVar13 = pbVar6 + 1;
      bVar2 = *pbVar6;
      pbVar6 = pbVar13;
    } while (bVar2 != 0);
    uVar10 = ~uVar10;
    pbVar13 = pbVar13 + -uVar10;
    pbVar6 = pbVar12;
    for (uVar11 = uVar10 >> 2; pbVar6 = pbVar6 + 4, uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pbVar6 = *(undefined4 *)pbVar13;
      pbVar13 = pbVar13 + 4;
    }
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pbVar6 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      pbVar6 = pbVar6 + 1;
    }
    *(int *)(pbVar12 + -4) = iStack_10c;
    sprintf(acStack_218,s__s_s,rge_base_game->prog_info->scenario_dir,abStack_104);
    iVar4 = rge_open(acStack_218,0x8000);
    if (-1 < iVar4) {
      rge_read_uncompressed(iVar4,auStack_21c,4);
      uVar9 = (**(code **)(rge_base_game->_padding_ + 0x38))(iVar4);
      *(undefined4 *)pbVar12 = uVar9;
      rge_close(iVar4);
    }
  }
  pbVar12 = pbVar12 + 0x10c;
  iVar4 = __findnext(iStack_228,auStack_118);
  if (iVar4 == -1) {
    if (bVar18) {
LAB_0048d44e:
      if (*(int *)(param_1 + 0x108) != 0) {
        iVar4 = 0;
        if (0 < *(int *)(param_1 + 0x104)) {
          iVar8 = 0;
          do {
            this = *(RGE_Scenario_Header **)(iVar8 + 4 + *(int *)(param_1 + 0x108));
            if (this != (RGE_Scenario_Header *)0x0) {
              RGE_Scenario_Header::~RGE_Scenario_Header(this);
              operator_delete(this);
            }
            iVar4 = iVar4 + 1;
            iVar8 = iVar8 + 0x10c;
          } while (iVar4 < *(int *)(param_1 + 0x104));
        }
        free(*(undefined4 *)(param_1 + 0x108));
      }
      *(int *)(param_1 + 0x108) = iVar5;
      *(int *)(param_1 + 0x104) = iVar14;
      return;
    }
    sprintf(acStack_218,s__s__scx,rge_base_game->prog_info->scenario_dir);
    iStack_228 = __findfirst(acStack_218,auStack_118);
    if (iStack_228 == -1) goto LAB_0048d44e;
    bVar18 = true;
  }
  goto LAB_0048d24d;
}

// --------------------------------------------------

// Function: FUN_0048d4c3
// Address: 0048d4c3
// XREFS: None
int __thiscall FUN_0048d4c3(int param_1,int param_2)
{
  if ((param_2 < *(int *)(param_1 + 0x104)) && (-1 < param_2)) {
    return *(int *)(param_1 + 0x108) + 8 + param_2 * 0x10c;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048d4fe
// Address: 0048d4fe
// XREFS: None
undefined4 __thiscall FUN_0048d4fe(int param_1,int param_2)
{
  if ((param_2 < *(int *)(param_1 + 0x104)) && (-1 < param_2)) {
    return *(undefined4 *)(*(int *)(param_1 + 0x108) + 4 + param_2 * 0x10c);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0048d52e
// Address: 0048d52e
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_defcheck_slp: "defcheck.slp"
// [HELPER] s_scr10: "scr10"
// [HELPER] s_scr7: "scr7"
// [HELPER] s_scr8: "scr8"
// [HELPER] s_timeline_slp: "timeline.slp"
// [HELPER] s_viccheck_slp: "viccheck.slp"
TribeAchievementsScreen * __thiscall
FUN_0048d52e(TribeAchievementsScreen *param_1,undefined4 param_2,int param_3)
{
  TButtonPanel **ppTVar1;
  Time_Line_Panel **ppTVar2;
  TButtonPanel **ppTVar3;
  char cVar4;
  TButtonPanel *pTVar5;
  bool bVar6;
  RGE_Player *pRVar7;
  long lVar8;
  char *pcVar9;
  TShape *pTVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  RGE_Scenario *this;
  TTextPanel **ppTVar14;
  TTextPanel **ppTVar15;
  TTextPanel *(*papTVar16) [7];
  int iVar17;
  TTextPanel *(*papTVar18) [7];
  char *pcVar19;
  TTextPanel **ppTVar20;
  undefined4 *unaff_FS_OFFSET;
  long lVar21;
  ulong uVar22;
  int iVar23;
  TPanel *pTVar24;
  int iStack_1dc;
  char acStack_174 [100];
  char acStack_110 [204];
  undefined1 uStack_44;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e847;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Achievements_Screen);
  ppTVar1 = &param_1->close_button;
  uStack_4 = 0;
  param_1->title = (TTextPanel *)0x0;
  param_1->time = (TTextPanel *)0x0;
  param_1->summary_text = (TTextPanel *)0x0;
  param_1->win_loss_text = (TTextPanel *)0x0;
  param_1->instruction = (TTextPanel *)0x0;
  param_1->time_line = (Time_Line_Panel *)0x0;
  param_1->okButton = (TButtonPanel *)0x0;
  param_1->timelineButton = (TButtonPanel *)0x0;
  param_1->restartButton = (TButtonPanel *)0x0;
  param_1->aftermathButton = (TButtonPanel *)0x0;
  param_1->backButton = (TButtonPanel *)0x0;
  param_1->backButton2 = (TButtonPanel *)0x0;
  param_1->win_decal = (TShape *)0x0;
  *ppTVar1 = (TButtonPanel *)0x0;
  param_1->instruction_bar = (TScrollBarPanel *)0x0;
  param_1->win_loss_text_bar = (TScrollBarPanel *)0x0;
  param_1->summary_text_bar = (TScrollBarPanel *)0x0;
  param_1->_padding_ = (int)&TribeAchievementsScreen::_vftable_;
  param_1->end_game_flag = param_3;
  param_1->achievement_choice[0] = (TTextPanel *)0x0;
  papTVar16 = param_1->statistics;
  param_1->achievement_choice[1] = (TTextPanel *)0x0;
  ppTVar14 = param_1->player_names;
  iStack_1dc = 8;
  param_1->achievement_choice[2] = (TTextPanel *)0x0;
  param_1->achievement_choice[3] = (TTextPanel *)0x0;
  param_1->achievement_choice[4] = (TTextPanel *)0x0;
  ppTVar20 = param_1->title_bar;
  for (iVar11 = 7; iVar11 != 0; iVar11 = iVar11 + -1) {
    *ppTVar20 = (TTextPanel *)0x0;
    ppTVar20 = ppTVar20 + 1;
  }
  do {
    *ppTVar14 = (TTextPanel *)0x0;
    papTVar18 = papTVar16;
    for (iVar11 = 7; iVar11 != 0; iVar11 = iVar11 + -1) {
      (*papTVar18)[0] = (TTextPanel *)0x0;
      papTVar18 = (TTextPanel *(*) [7])(*papTVar18 + 1);
    }
    ppTVar14 = ppTVar14 + 1;
    papTVar16 = papTVar16 + 1;
    iStack_1dc = iStack_1dc + -1;
  } while (iStack_1dc != 0);
  if (param_1->end_game_flag == 0) {
    uVar12 = 0xffffffff;
    pcVar9 = s_scr10;
    do {
      pcVar19 = pcVar9;
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      pcVar19 = pcVar9 + 1;
      cVar4 = *pcVar9;
      pcVar9 = pcVar19;
    } while (cVar4 != '\0');
    uVar12 = ~uVar12;
    pcVar9 = pcVar19 + -uVar12;
    pcVar19 = acStack_110;
    for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar19 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar19 = pcVar19 + 4;
    }
    lVar8 = 0xc38d;
    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar19 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar19 = pcVar19 + 1;
    }
  }
  else {
    pRVar7 = RGE_Base_Game::get_player(rge_base_game);
    if (pRVar7->game_status == '\x01') {
      uVar12 = 0xffffffff;
      pcVar9 = &s_scr7;
      do {
        pcVar19 = pcVar9;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar19 = pcVar9 + 1;
        cVar4 = *pcVar9;
        pcVar9 = pcVar19;
      } while (cVar4 != '\0');
      uVar12 = ~uVar12;
      pcVar9 = pcVar19 + -uVar12;
      pcVar19 = acStack_110;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar19 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar19 = pcVar19 + 4;
      }
      lVar8 = 0xc389;
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar19 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar19 = pcVar19 + 1;
      }
    }
    else {
      uVar12 = 0xffffffff;
      pcVar9 = &s_scr8;
      do {
        pcVar19 = pcVar9;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar19 = pcVar9 + 1;
        cVar4 = *pcVar9;
        pcVar9 = pcVar19;
      } while (cVar4 != '\0');
      uVar12 = ~uVar12;
      pcVar9 = pcVar19 + -uVar12;
      pcVar19 = acStack_110;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar19 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar19 = pcVar19 + 4;
      }
      lVar8 = 0xc38a;
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar19 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar19 = pcVar19 + 1;
      }
    }
  }
  lVar8 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,acStack_110,lVar8,1);
  if (lVar8 == 0) {
    param_1->_padding_ = 1;
    goto LAB_0048e1a9;
  }
  TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
  sprintf();
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->time,acStack_174,0x1e0,10,0x6e,0x14,
             0xb,0,0,0);
  TTextPanel::set_alignment(param_1->time,AlignTop,AlignRight);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,0x269e,0,5,0x280,0x1e,1,1,0,0)
  ;
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->summary_text,0,10,0x23,0x26c,0x1e,1,
             1,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->instruction,0x26db,10,0x19a,0x26c,
             0x14,0xb,1,0,0);
  if (param_1->end_game_flag != 0) {
    pRVar7 = RGE_Base_Game::get_player(rge_base_game);
    if (pRVar7->game_status == '\x01') {
      lVar8 = 2;
      this = rge_base_game->world->scenario;
    }
    else {
      lVar8 = 3;
      this = rge_base_game->world->scenario;
    }
    pcVar9 = RGE_Scenario::Get_message(this,lVar8);
    if ((pcVar9 != (char *)0x0) && (*pcVar9 != '\0')) {
      ppTVar14 = &param_1->win_loss_text;
      TEasy_Panel::create_text
                ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar14,s_,10,0x55,0x26c,0x14a,0xb,0,0,1)
      ;
      if (*ppTVar14 != (TTextPanel *)0x0) {
        TEasy_Panel::create_auto_scrollbar
                  ((TEasy_Panel *)param_1,&param_1->win_loss_text_bar,*ppTVar14,0x14);
        (**(code **)((*ppTVar14)->_padding_ + 0xec))(4);
        (**(code **)((*ppTVar14)->_padding_ + 0xe8))(pcVar9);
      }
    }
  }
  ppTVar2 = &param_1->time_line;
  Time_Line_Panel::create_timeline
            (param_1->time_line,(TPanel *)param_1,ppTVar2,10,0x55,0x26c,0x14a,0xb,9,0x280,0x1e0);
  Time_Line_Panel::set_bevel_info
            (*ppTVar2,3,(uint)(byte)param_1->_padding_,(uint)*(byte *)((int)&param_1->_padding_ + 1)
             ,(uint)*(byte *)((int)&param_1->_padding_ + 2),
             (uint)*(byte *)((int)&param_1->_padding_ + 3),(uint)(byte)param_1->_padding_,
             (uint)*(byte *)((int)&param_1->_padding_ + 1));
  Time_Line_Panel::set_special_events(*ppTVar2,s_timeline_slp);
  iVar11 = TEasy_Panel::create_button
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x3ea,0,0,0,0,0,-1,-1,0);
  if (iVar11 == 0) goto LAB_0048e1a9;
  (**(code **)((*ppTVar1)->_padding_ + 0x14))();
  (**(code **)((*ppTVar1)->_padding_ + 0x18))(9,4,4,4,4,0x11,0x11,0x11);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title_bar,0,0x62,0x97,200,0x1e,0xb,0,
             0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title_bar + 1,0,0x98,0x83,200,0x1e,
             0xb,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title_bar + 2,0,0xd4,0x6f,0x91,0x1e,
             0xb,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title_bar + 3,0,0x104,0x5b,200,0x1e,
             0xb,1,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title_bar + 4,0,0x16c,0x6f,0x91,0x1e,
             0xb,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title_bar + 5,0,0x172,0x83,200,0x1e,
             0xb,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title_bar + 6,0,0x1a8,0x97,200,0x1e,
             0xb,0,0,0);
  TTextPanel::set_alignment(param_1->title_bar[4],AlignTop,AlignRight);
  TTextPanel::set_alignment(param_1->title_bar[5],AlignTop,AlignRight);
  TTextPanel::set_alignment(param_1->title_bar[6],AlignTop,AlignRight);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->achievement_choice,0,100,0x97,0x82,
             0xfa,0xb,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->achievement_choice + 1,0,0x9a,0x83,
             0x80,0x112,0xb,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->achievement_choice + 2,0,0xd6,0x6f,
             0x79,0x121,0xb,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->achievement_choice + 3,0,0x11a,0x5b,
             0x9c,0x135,0xb,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->achievement_choice + 4,0,0x184,0x6f,
             0x79,0x121,0xb,0,0,0);
  ppTVar14 = param_1->player_names;
  pTVar24 = (TPanel *)0x4;
  iVar17 = 0xab;
  ppTVar20 = param_1->statistics[0] + 2;
  iVar11 = 1;
  do {
    if (iVar11 < rge_base_game->world->player_num) {
      pcVar9 = *(char **)(*(int *)((int)rge_base_game->world->players + (int)pTVar24) + 0x44);
    }
    else {
      pcVar9 = (char *)0x0;
    }
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar14,pcVar9,0x16,iVar17,0x96,0x1d,0xb,0,
               1,0);
    ppTVar15 = ppTVar20 + -2;
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar15,0,0xb2,iVar17,0x33,0x1d,0xb,1,1,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20 + -1,0,0xe7,iVar17,0x33,0x1d,0xb,1,
               1,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20,0,0x11b,iVar17,0x33,0x1d,0xb,1,1,0)
    ;
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20 + 1,0,0x150,iVar17,0x33,0x1d,0xb,1,
               1,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20 + 2,0,0x185,iVar17,0x33,0x1d,0xb,1,
               1,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20 + 3,0,0x1ba,iVar17,0x33,0x1d,0xb,1,
               1,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20 + 4,0,0x1ee,iVar17,0x33,0x1d,0xb,1,
               1,0);
    if (iVar11 < rge_base_game->world->player_num) {
      switch(*(undefined2 *)
              (*(int *)(*(int *)((int)rge_base_game->world->players + (int)pTVar24) + 0x108) + 0x26)
            ) {
      case 0:
        uVar22 = 0xc40000;
        break;
      case 1:
        uVar22 = 200;
        break;
      case 2:
        uVar22 = 0xeaea;
        break;
      case 3:
        uVar22 = 0x215a8c;
        break;
      case 4:
        uVar22 = 0x80ff;
        break;
      case 5:
        uVar22 = 0x8000;
        break;
      case 6:
        uVar22 = 0x808080;
        break;
      case 7:
        uVar22 = 0x808040;
        break;
      default:
        uVar22 = 0xffffff;
      }
      TTextPanel::set_text_color(*ppTVar14,uVar22,0);
      iVar23 = 7;
      do {
        TTextPanel::set_text_color(*ppTVar15,uVar22,0);
        ppTVar15 = ppTVar15 + 1;
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
    }
    iVar17 = iVar17 + 0x1e;
    pTVar24 = (TPanel *)&pTVar24->previousPanelValue;
    ppTVar14 = ppTVar14 + 1;
    ppTVar20 = ppTVar20 + 7;
    bVar6 = iVar11 < 8;
    iVar11 = iVar11 + 1;
  } while (bVar6);
  if ((param_1->end_game_flag == 0) ||
     (iVar11 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar11 == 0)) {
    TEasy_Panel::create_button
              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->timelineButton,0x26d8,0,100,0x1b9,
               200,0x1e,0,0,0);
    lVar21 = 200;
    lVar8 = 0x154;
  }
  else if (param_1->win_loss_text == (TTextPanel *)0x0) {
    TEasy_Panel::create_button
              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->timelineButton,0x26d8,0,0x14,0x1b9
               ,0xb4,0x1e,0,0,0);
    TEasy_Panel::create_button
              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->restartButton,0x269f,0,0xe6,0x1b9,
               0xb4,0x1e,0,0,0);
    lVar21 = 0xb4;
    lVar8 = 0x1b8;
  }
  else {
    TEasy_Panel::create_button
              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->aftermathButton,0x26b2,0,5,0x1b9,
               0x96,0x1e,0,0,0);
    TEasy_Panel::create_button
              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->timelineButton,0x26d8,0,0xa5,0x1b9
               ,0x96,0x1e,0,0,0);
    TEasy_Panel::create_button
              ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->restartButton,0x269f,0,0x145,0x1b9
               ,0x96,0x1e,0,0,0);
    lVar21 = 0x96;
    lVar8 = 0x1e5;
  }
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->okButton,0x269c,0,lVar8,0x1b9,lVar21
             ,0x1e,0,0,0);
  ppTVar1 = &param_1->backButton;
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x26da,0,200,0x1b9,0xf0,0x1e,0,0,0);
  (**(code **)((*ppTVar1)->_padding_ + 0x14))(0);
  pTVar5 = *ppTVar1;
  ppTVar3 = &param_1->backButton2;
  pTVar5->hotkey = 0x1b;
  pTVar5->hotkey_shift = 0;
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar3,0x269c,0,200,0x1b9,0xf0,0x1e,0,0,0);
  (**(code **)((*ppTVar3)->_padding_ + 0x14))(0);
  pTVar5 = *ppTVar3;
  pTVar5->hotkey = 0x1b;
  pTVar5->hotkey_shift = 0;
  pTVar5 = param_1->okButton;
  pTVar5->hotkey = 0x1b;
  pTVar5->hotkey_shift = 0;
  pRVar7 = RGE_Base_Game::get_player(rge_base_game);
  if (pRVar7->game_status == '\x01') {
    pTVar10 = (TShape *)operator_new(0x20);
    uStack_44 = 1;
    if (pTVar10 == (TShape *)0x0) {
LAB_0048e10d:
      pTVar10 = (TShape *)0x0;
    }
    else {
      pTVar10 = (TShape *)TShape::TShape(pTVar10,s_viccheck_slp,0xcb21);
    }
  }
  else {
    pTVar10 = (TShape *)operator_new(0x20);
    uStack_44 = 2;
    if (pTVar10 == (TShape *)0x0) goto LAB_0048e10d;
    pTVar10 = (TShape *)TShape::TShape(pTVar10,s_defcheck_slp,0xcb22);
  }
  param_1->win_decal = pTVar10;
  uStack_44 = 0;
  uVar12 = (uint)(param_1->aftermathButton != (TButtonPanel *)0x0);
  if (param_1->timelineButton != (TButtonPanel *)0x0) {
    *(TButtonPanel **)(&stack0xfffffdf8 + uVar12 * 4) = param_1->timelineButton;
    uVar12 = uVar12 + 1;
  }
  if (param_1->restartButton != (TButtonPanel *)0x0) {
    *(TButtonPanel **)(&stack0xfffffdf8 + uVar12 * 4) = param_1->restartButton;
    uVar12 = uVar12 + 1;
  }
  *(TButtonPanel **)(&stack0xfffffdf8 + uVar12 * 4) = param_1->okButton;
  TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&stack0xfffffdf8,(short)uVar12 + 1);
  TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->okButton);
  (**(code **)((*ppTVar1)->_padding_ + 0xc4))(0,0);
  (**(code **)((*ppTVar3)->_padding_ + 0xc4))(0,0);
  if (param_1->win_loss_text == (TTextPanel *)0x0) {
    lVar8 = 0;
  }
  else {
    lVar8 = 5;
  }
  TribeAchievementsScreen::set_mode(param_1,lVar8);
LAB_0048e1a9:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048e1c6
// Address: 0048e1c6
// XREFS: None
void FUN_0048e1c6(void)
{
  undefined4 in_EAX;
  longlong *plVar1;
  int iVar2;
  undefined1 *unaff_ESI;
  float10 in_ST0;
  float10 in_ST1;
  
  plVar1 = (longlong *)CONCAT31((int3)((uint)in_EAX >> 8),*unaff_ESI);
  *plVar1 = (longlong)in_ST0;
  iVar2 = (int)plVar1 + -1;
  *(longlong *)CONCAT31((int3)((uint)iVar2 >> 8),(char)iVar2 * '\x02') = (longlong)in_ST1;
  return;
}

// --------------------------------------------------

// Function: FUN_0048e20e
// Address: 0048e20e
// XREFS: None
// [HELPER] s_YesNoDialog: "YesNoDialog"
void __fastcall FUN_0048e20e(TScreenPanel *param_1)
{
  TShape *this;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e868;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeAchievementsScreen::_vftable_;
  uStack_4 = 0;
  TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
  this = *(TShape **)&param_1[1].field_0x178;
  if (this != (TShape *)0x0) {
    TShape::~TShape(this);
    operator_delete(this);
  }
  if (*(undefined4 **)&param_1[1].field_0xc != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xc)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x10 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x10)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x1c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x1c)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x18 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x18)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x14 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x14)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x170 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x170)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x15c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x15c)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x160 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x160)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x164 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x164)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x16c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x16c)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x168 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x168)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x17c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x17c)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x158 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x158)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x150 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x150)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x154 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x154)(1);
  }
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x174);
  piVar2 = (int *)&param_1[1].field_0x20;
  iVar3 = 7;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  piVar2 = (int *)&param_1[1].field_0x3c;
  iVar3 = 5;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  piVar2 = (int *)&param_1[1].field_0x50;
  piVar1 = (int *)&param_1[1].field_0x130;
  iVar3 = 8;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    iVar4 = 7;
    do {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0048e3fd
// Address: 0048e3fd
// XREFS: None
// [HELPER] s_: ""
// [HELPER] s__d__: "%d%%"
void __thiscall FUN_0048e3fd(TPanel *param_1,long param_2)
{
  TPanel *pTVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int unaff_ESI;
  int iVar6;
  long *plVar7;
  tagRECT *ptVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined3 uStack_8;
  undefined1 uStack_5;
  
  iVar6 = rge_base_game->world->player_num + -1;
  uStack_50 = 0x48e43e;
  RGE_Base_Game::disable_input(rge_base_game);
  if ((int *)param_1[4].mouse_move_tolerance != (int *)0x0) {
    uStack_50 = 0;
    uStack_54 = 0x48e450;
    (**(code **)(*(int *)param_1[4].mouse_move_tolerance + 0x14))();
  }
  pTVar1 = param_1[6].curr_child;
  uStack_50 = 0;
  param_1[4].min_wid = param_2;
  uStack_54 = 0x48e466;
  (**(code **)(pTVar1->_padding_ + 0x14))();
  uStack_54 = 0;
  uStack_58 = 0x48e472;
  (**(code **)(*(int *)param_1[4].mouse_hold_interval + 0x14))();
  uStack_58 = 1;
  (**(code **)(*(int *)param_1[4].mouse_down_x + 0x14))();
  piVar2 = (int *)param_1[6].clip_rect.bottom;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x14))();
  }
  if ((int *)param_1[6].panelNameValue != (int *)0x0) {
    (**(code **)(*(int *)param_1[6].panelNameValue + 0x14))();
  }
  piVar2 = (int *)param_1[6].clip_rect.right;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x14))();
  }
  piVar2 = (int *)param_1[6].clip_rect.top;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x14))();
  }
  if (param_1[6].render_area != (TDrawArea *)0x0) {
    (*(code *)(param_1[6].render_area)->DrawSystem->DrawAreaList)();
  }
  piVar2 = (int *)param_1[6].clip_rect.left;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x14))();
  }
  TPanel::set_curr_child(param_1,(TPanel *)param_1[6].render_area);
  uStack_5 = (undefined1)((uint)unaff_ESI >> 0x18);
  uStack_8 = (undefined3)unaff_ESI;
  switch(param_2) {
  case 0:
    pTVar1 = (TPanel *)param_1[6].panelNameValue;
    param_1[4].max_wid = 7;
    TPanel::set_curr_child(param_1,pTVar1);
    piVar2 = (int *)param_1[6].clip_rect.bottom;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
    }
    if ((int *)param_1[6].panelNameValue != (int *)0x0) {
      (**(code **)(*(int *)param_1[6].panelNameValue + 0x14))();
    }
    piVar2 = (int *)param_1[6].clip_rect.right;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
    }
    piVar2 = (int *)param_1[6].clip_rect.top;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
    }
    if (param_1[6].render_area != (TDrawArea *)0x0) {
      (*(code *)(param_1[6].render_area)->DrawSystem->DrawAreaList)();
    }
    (**(code **)(*(int *)param_1[4].mouse_hold_interval + 0x14))();
    (**(code **)(*(int *)param_1[4].max_hgt + 0xe4))(0x26d9);
    (**(code **)(*(int *)param_1[4].mouse_down_y + 0xe4))(0x26ac);
    (**(code **)(*(int *)param_1[4].mouse_down_ctrl + 0xe4))(0x26ad);
    (**(code **)(*(int *)param_1[4].mouse_down_shift + 0xe4))(0x26ae);
    (**(code **)(*(int *)param_1[4].mouse_down_time + 0xe4))(0x26af);
    (**(code **)(*(int *)param_1[4].error_code + 0xe4))(0x26d6);
    (**(code **)(*(int *)param_1[4].z_order + 0xe4))(0x26d7);
    (**(code **)(*(int *)param_1[4].display_changed_count + 0xe4))(0x26b1);
    if (0 < iVar6) {
      iVar5 = 4;
      ptVar8 = (tagRECT *)&param_1[5].previousModalPanelValue;
      uStack_8 = (undefined3)iVar6;
      uStack_5 = (undefined1)((uint)iVar6 >> 0x18);
      do {
        puVar10 = &stack0xffffffc0;
        iVar6 = *(int *)((int)rge_base_game->world->players + iVar5);
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)(iVar6 + 0x34),'\0');
        itoa(lVar4,puVar10);
        (*(code *)(*(TDrawArea **)((int)(ptVar8 + -1) + 0xc))->DrawSystem->palette[0x1c])();
        puVar10 = &stack0xffffffbc;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)(iVar6 + 0x34),'\x01');
        itoa(lVar4,puVar10,uVar11);
        (**(code **)(((TPanel *)ptVar8->left)->_padding_ + 0xe8))(&stack0xffffffbc);
        puVar10 = &stack0xffffffb8;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)(iVar6 + 0x34),'\x02');
        itoa(lVar4,puVar10,uVar11);
        (**(code **)(*(int *)ptVar8->top + 0xe8))(&stack0xffffffb8);
        puVar10 = &stack0xffffffb4;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)(iVar6 + 0x34),'\x03');
        itoa(lVar4,puVar10,uVar11);
        (**(code **)(*(int *)ptVar8->right + 0xe8))(&stack0xffffffb4);
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar6 + 0x34),'\x16');
        if (lVar4 < 1) {
          (**(code **)(*(int *)ptVar8->bottom + 0xe8))(s_);
        }
        else {
          (**(code **)(*(int *)ptVar8->bottom + 0xe4))(0xfa3);
        }
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar6 + 0x34),'\x17');
        if (lVar4 < 1) {
          (**(code **)(**(int **)(ptVar8 + 1) + 0xe8))(s_);
        }
        else {
          (**(code **)(**(int **)(ptVar8 + 1) + 0xe4))(0xfa3);
        }
        puVar9 = &uStack_58;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points
                          (*(RGE_Victory_Conditions **)(iVar6 + 0x34));
        itoa(lVar4,puVar9,uVar11);
        (**(code **)(**(int **)((int)(ptVar8 + 1) + 4) + 0xe8))(&uStack_58);
        iVar5 = iVar5 + 4;
        ptVar8 = (tagRECT *)((int)(ptVar8 + 1) + 0xc);
        iVar6 = CONCAT13(uStack_5,uStack_8) + -1;
        uStack_8 = (undefined3)iVar6;
        uStack_5 = (undefined1)((uint)iVar6 >> 0x18);
      } while (iVar6 != 0);
    }
    break;
  case 1:
    param_1[4].max_wid = 6;
    (**(code **)(*(int *)param_1[4].max_hgt + 0xe4))();
    (**(code **)(*(int *)param_1[4].mouse_down_y + 0xe4))(0x26b6);
    (**(code **)(*(int *)param_1[4].mouse_down_ctrl + 0xe4))(0x26b7);
    (**(code **)(*(int *)param_1[4].mouse_down_shift + 0xe4))(0x26b9);
    (**(code **)(*(int *)param_1[4].mouse_down_time + 0xe4))(0x26b8);
    (**(code **)(*(int *)param_1[4].error_code + 0xe4))(0x26ba);
    (**(code **)(*(int *)param_1[4].z_order + 0xe4))(0x26b5);
    if (0 < iVar6) {
      iVar6 = 4;
      ptVar8 = (tagRECT *)&param_1[5].previousModalPanelValue;
      do {
        puVar10 = &stack0xffffffc0;
        iVar5 = *(int *)((int)rge_base_game->world->players + iVar6);
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\0');
        itoa(lVar4,puVar10);
        (*(code *)(*(TDrawArea **)((int)(ptVar8 + -1) + 0xc))->DrawSystem->palette[0x1c])();
        puVar10 = &stack0xffffffbc;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x01');
        itoa(lVar4,puVar10,uVar11);
        (**(code **)(((TPanel *)ptVar8->left)->_padding_ + 0xe8))(&stack0xffffffbc);
        uVar11 = __ftol(&stack0xffffffb8,10);
        itoa(uVar11);
        (**(code **)(*(int *)ptVar8->top + 0xe8))(&stack0xffffffb8);
        puVar10 = &stack0xffffffb4;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x02');
        itoa(lVar4,puVar10,uVar11);
        (**(code **)(*(int *)ptVar8->right + 0xe8))(&stack0xffffffb4);
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x03');
        if (lVar4 < 1) {
          (**(code **)(*(int *)ptVar8->bottom + 0xe8))(s_);
        }
        else {
          (**(code **)(*(int *)ptVar8->bottom + 0xe4))(0xfa3);
        }
        puVar9 = &uStack_54;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\0');
        itoa(lVar4,puVar9,uVar11);
        (**(code **)(**(int **)(ptVar8 + 1) + 0xe8))(&uStack_54);
        iVar6 = iVar6 + 4;
        ptVar8 = (tagRECT *)((int)(ptVar8 + 1) + 0xc);
        iVar5 = CONCAT13(uStack_5,uStack_8) + -1;
        uStack_8 = (undefined3)iVar5;
        uStack_5 = (undefined1)((uint)iVar5 >> 0x18);
      } while (iVar5 != 0);
    }
    break;
  case 2:
    param_1[4].max_wid = 7;
    (**(code **)(*(int *)param_1[4].max_hgt + 0xe4))();
    (**(code **)(*(int *)param_1[4].mouse_down_y + 0xe4))(0x26be);
    (**(code **)(*(int *)param_1[4].mouse_down_ctrl + 0xe4))(0x26bf);
    (**(code **)(*(int *)param_1[4].mouse_down_shift + 0xe4))(0x26c0);
    (**(code **)(*(int *)param_1[4].mouse_down_time + 0xe4))(0x26c1);
    (**(code **)(*(int *)param_1[4].error_code + 0xe4))(0x26c2);
    (**(code **)(*(int *)param_1[4].z_order + 0xe4))(0x26c3);
    (**(code **)(*(int *)param_1[4].display_changed_count + 0xe4))(0x26b5);
    if (0 < iVar6) {
      iVar6 = 4;
      plVar7 = &param_1[5].pnl_x;
      do {
        puVar10 = &stack0xffffffc0;
        iVar5 = *(int *)((int)rge_base_game->world->players + iVar6);
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x04');
        itoa(lVar4,puVar10);
        (**(code **)(((TPanel *)plVar7[-2])->_padding_ + 0xe8))();
        puVar10 = &stack0xffffffbc;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x05');
        itoa(lVar4,puVar10,uVar11);
        (**(code **)(((TPanel *)plVar7[-1])->_padding_ + 0xe8))(&stack0xffffffbc);
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x06');
        if (lVar4 < 1) {
          (**(code **)(*(int *)*plVar7 + 0xe8))(s_);
        }
        else {
          (**(code **)(*(int *)*plVar7 + 0xe4))(0xfa3);
        }
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\a');
        sprintf(&stack0xffffffb4,s__d__,lVar4);
        (**(code **)(*(int *)plVar7[1] + 0xe8))(&stack0xffffffb4);
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\b');
        if (lVar4 < 1) {
          (**(code **)(*(int *)plVar7[2] + 0xe8))(s_);
        }
        else {
          (**(code **)(*(int *)plVar7[2] + 0xe4))(0xfa3);
        }
        puVar9 = &uStack_54;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\t');
        itoa(lVar4,puVar9,uVar11);
        (**(code **)(*(int *)plVar7[3] + 0xe8))(&uStack_54);
        puVar9 = &uStack_58;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x01');
        itoa(lVar4,puVar9,uVar11);
        (**(code **)(*(int *)plVar7[4] + 0xe8))(&uStack_58);
        iVar6 = iVar6 + 4;
        plVar7 = plVar7 + 7;
        iVar5 = CONCAT13(uStack_5,uStack_8) + -1;
        uStack_8 = (undefined3)iVar5;
        uStack_5 = (undefined1)((uint)iVar5 >> 0x18);
      } while (iVar5 != 0);
    }
    break;
  case 3:
    param_1[4].max_wid = 7;
    (**(code **)(*(int *)param_1[4].max_hgt + 0xe4))();
    (**(code **)(*(int *)param_1[4].mouse_down_y + 0xe4))(0x26c6);
    (**(code **)(*(int *)param_1[4].mouse_down_ctrl + 0xe4))(0x26c7);
    (**(code **)(*(int *)param_1[4].mouse_down_shift + 0xe4))(0x26c8);
    (**(code **)(*(int *)param_1[4].mouse_down_time + 0xe4))(0x26c9);
    (**(code **)(*(int *)param_1[4].error_code + 0xe4))(0x26ca);
    (**(code **)(*(int *)param_1[4].z_order + 0xe4))(0x26dc);
    (**(code **)(*(int *)param_1[4].display_changed_count + 0xe4))(0x26b5);
    if (0 < iVar6) {
      uStack_8 = 4;
      uStack_5 = 0;
      ptVar8 = (tagRECT *)&param_1[5].previousModalPanelValue;
      do {
        iVar5 = *(int *)((int)rge_base_game->world->players + CONCAT13(uStack_5,uStack_8));
        (**(code **)((param_1[6].curr_child)->_padding_ + 0x14))();
        puVar10 = &stack0xffffffbc;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\n');
        itoa(lVar4,puVar10,uVar11);
        (*(code *)(*(TDrawArea **)((int)(ptVar8 + -1) + 0xc))->DrawSystem->palette[0x1c])
                  (&stack0xffffffbc);
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\v');
        if (lVar4 < 1) {
          (**(code **)(((TPanel *)ptVar8->left)->_padding_ + 0xe8))(s_);
        }
        else {
          (**(code **)(((TPanel *)ptVar8->left)->_padding_ + 0xe4))(0xfa3);
        }
        puVar10 = &stack0xffffffb4;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\f');
        itoa(lVar4,puVar10,uVar11);
        (**(code **)(*(int *)ptVar8->top + 0xe8))(&stack0xffffffb4);
        puVar9 = &uStack_50;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\r');
        itoa(lVar4,puVar9,uVar11);
        (**(code **)(*(int *)ptVar8->right + 0xe8))(&uStack_50);
        puVar9 = &uStack_54;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x0e');
        itoa(lVar4,puVar9,uVar11);
        (**(code **)(*(int *)ptVar8->bottom + 0xe8))(&uStack_54);
        puVar9 = &uStack_58;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x10');
        lVar3 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x0f');
        itoa(lVar4 + lVar3,puVar9,uVar11);
        (**(code **)(**(int **)(ptVar8 + 1) + 0xe8))(&uStack_58);
        puVar10 = &stack0xffffffa4;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x02');
        itoa(lVar4,puVar10,uVar11);
        (**(code **)(**(int **)((int)(ptVar8 + 1) + 4) + 0xe8))(&stack0xffffffa4);
        iVar5 = CONCAT13(uStack_5,uStack_8) + 4;
        ptVar8 = (tagRECT *)((int)(ptVar8 + 1) + 0xc);
        uStack_8 = (undefined3)iVar5;
        uStack_5 = (undefined1)((uint)iVar5 >> 0x18);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    break;
  case 4:
    param_1[4].max_wid = 5;
    (**(code **)(*(int *)param_1[4].max_hgt + 0xe4))();
    (**(code **)(*(int *)param_1[4].mouse_down_y + 0xe4))(0x26ce);
    (**(code **)(*(int *)param_1[4].mouse_down_ctrl + 0xe4))(0x26d1);
    (**(code **)(*(int *)param_1[4].mouse_down_shift + 0xe4))(0x26cf);
    (**(code **)(*(int *)param_1[4].mouse_down_time + 0xe4))(0x26d0);
    (**(code **)(*(int *)param_1[4].error_code + 0xe4))(0x26b5);
    if (0 < iVar6) {
      iVar6 = 4;
      ptVar8 = (tagRECT *)&param_1[5].previousModalPanelValue;
      do {
        puVar10 = &stack0xffffffc0;
        iVar5 = *(int *)((int)rge_base_game->world->players + iVar6);
        lVar4 = RGE_Victory_Conditions::get_attribute_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x11');
        itoa(lVar4,puVar10);
        (*(code *)(*(TDrawArea **)((int)(ptVar8 + -1) + 0xc))->DrawSystem->palette[0x1c])();
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x12');
        if (lVar4 < 1) {
          (**(code **)(((TPanel *)ptVar8->left)->_padding_ + 0xe8))(s_);
        }
        else {
          (**(code **)(((TPanel *)ptVar8->left)->_padding_ + 0xe4))(0xfa3);
        }
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x13');
        if (lVar4 < 1) {
          (**(code **)(*(int *)ptVar8->top + 0xe8))(s_);
        }
        else {
          (**(code **)(*(int *)ptVar8->top + 0xe4))(0xfa3);
        }
        lVar4 = RGE_Victory_Conditions::get_victory_points_id
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x14');
        if (lVar4 < 1) {
          (**(code **)(*(int *)ptVar8->right + 0xe8))(s_);
        }
        else {
          (**(code **)(*(int *)ptVar8->right + 0xe4))(0xfa3);
        }
        puVar9 = &uStack_50;
        uVar11 = 10;
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)(iVar5 + 0x34),'\x03');
        itoa(lVar4,puVar9,uVar11);
        (**(code **)(*(int *)ptVar8->bottom + 0xe8))(&uStack_50);
        iVar6 = iVar6 + 4;
        ptVar8 = (tagRECT *)((int)(ptVar8 + 1) + 0xc);
        iVar5 = CONCAT13(uStack_5,uStack_8) + -1;
        uStack_8 = (undefined3)iVar5;
        uStack_5 = (undefined1)((uint)iVar5 >> 0x18);
      } while (iVar5 != 0);
    }
    break;
  case 5:
    param_1[4].max_wid = 0;
    (**(code **)(*(int *)param_1[4].max_hgt + 0xe4))();
    if ((int *)param_1[4].mouse_move_tolerance != (int *)0x0) {
      (**(code **)(*(int *)param_1[4].mouse_move_tolerance + 0x14))(1);
    }
    (**(code **)(*(int *)param_1[4].mouse_down_x + 0x14))(0);
    if (param_1[6].render_area != (TDrawArea *)0x0) {
      (*(code *)(param_1[6].render_area)->DrawSystem->DrawAreaList)();
    }
    piVar2 = (int *)param_1[6].clip_rect.left;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
      TPanel::set_curr_child(param_1,(TPanel *)param_1[6].clip_rect.left);
    }
    break;
  case 6:
    pTVar1 = param_1[6].curr_child;
    param_1[4].max_wid = 0;
    (**(code **)(pTVar1->_padding_ + 0x14))();
    (**(code **)(*(int *)param_1[4].max_hgt + 0xe4))(0x26d8);
    (**(code **)(*(int *)param_1[4].mouse_down_x + 0x14))(1);
  }
  if (param_1[4].max_wid == 0) {
    plVar7 = &param_1[5].help_string_id;
    iVar6 = 8;
    do {
      (**(code **)(*(int *)*plVar7 + 0x14))();
      plVar7 = plVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    iVar6 = 0;
    plVar7 = &param_1[5].help_string_id;
    do {
      (**(code **)(*(int *)*plVar7 + 0x14))();
      iVar6 = iVar6 + 1;
      plVar7 = plVar7 + 1;
    } while (iVar6 < 8);
  }
  iVar6 = 0;
  uStack_8 = SUB43(&param_1[4].mouse_down_y,0);
  uStack_5 = (undefined1)((uint)&param_1[4].mouse_down_y >> 0x18);
  do {
    (**(code **)(**(int **)CONCAT13(uStack_5,uStack_8) + 0x14))();
    if (0 < unaff_ESI) {
      puVar9 = (undefined4 *)(CONCAT13(uStack_5,uStack_8) + 0x30);
      iVar5 = unaff_ESI;
      do {
        (**(code **)(*(int *)*puVar9 + 0x14))();
        puVar9 = puVar9 + 7;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar6 = iVar6 + 1;
    iVar5 = CONCAT13(uStack_5,uStack_8) + 4;
    uStack_8 = (undefined3)iVar5;
    uStack_5 = (undefined1)((uint)iVar5 >> 0x18);
  } while (iVar6 < 7);
  return;
}

// --------------------------------------------------

// Function: FUN_0048f085
// Address: 0048f085
// XREFS: None
// [HELPER] s_scr_ach__draw: "scr_ach::draw"
/* WARNING: Unable to track spacebase fully for stack */

void __fastcall FUN_0048f085(TScreenPanel *param_1,int param_2)
{
  code *pcVar1;
  TDrawArea *pTVar2;
  RGE_Game_World *pRVar3;
  TPanel *pTVar4;
  TShape *this;
  int in_EAX;
  uchar *puVar5;
  int iVar6;
  long lVar7;
  undefined4 unaff_EBX;
  undefined1 *puVar8;
  int unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *puVar9;
  int iVar10;
  char *unaff_EDI;
  int aiStack_18 [6];
  
  unaff_EDI[0x48] = unaff_EDI[0x48] + (char)((uint)unaff_EBX >> 8);
  (&param_1->field_0x48)[unaff_EBP * 8] = (&param_1->field_0x48)[unaff_EBP * 8] + (char)param_2;
  unaff_EDI[-0x15] = unaff_EDI[-0x15] + (char)((uint)(in_EAX + -1) >> 8);
  *(char *)(param_2 + 0x6c0048ed) = *(char *)(param_2 + 0x6c0048ed) + (char)unaff_EBX;
  out((short)param_2,in_EAX + -2);
  *unaff_EDI = *unaff_EDI + (char)((uint)param_2 >> 8);
  out((short)param_2,in_EAX + -3);
  *(char *)(in_EAX + -0x6f6f6f74) = *(char *)(in_EAX + -0x6f6f6f74) + (char)param_2;
  *(char **)((int)aiStack_18 + unaff_EBP + 0xc) = unaff_EDI;
  *(undefined4 *)((int)aiStack_18 + unaff_EBP + 8) = 0x48f0bb;
  TScreenPanel::draw(param_1);
  if (*(int *)&param_1[1].field_0x4 < 5) {
    *(undefined4 *)((int)aiStack_18 + unaff_EBP + 8) = unaff_ESI;
    iVar10 = *(int *)param_1;
    *(undefined4 *)((int)aiStack_18 + unaff_EBP + 4) = 0;
    *(int *)((int)aiStack_18 + unaff_EBP + 0x14) = iVar10;
    pcVar1 = *(code **)(iVar10 + 0x28);
    puVar8 = (undefined1 *)((int)aiStack_18 + unaff_EBP);
    *(undefined4 *)((int)aiStack_18 + unaff_EBP) = 0x48f0d6;
    (*pcVar1)();
    if (*(int *)&param_1[1].field_0x178 != 0) {
      pTVar2 = *(TDrawArea **)&param_1->field_0x20;
      *(undefined4 *)(puVar8 + -4) = 1;
      *(char **)(puVar8 + -8) = s_scr_ach__draw;
      *(undefined4 *)(puVar8 + -0xc) = 0x48f0f3;
      puVar5 = TDrawArea::Lock(pTVar2,*(char **)(puVar8 + -8),*(int *)(puVar8 + -4));
      if (puVar5 != (uchar *)0x0) {
        *(undefined4 *)(puVar8 + -4) = unaff_EBX;
        pRVar3 = rge_base_game->world;
        iVar6 = pRVar3->player_num + -1;
        if (0 < iVar6) {
          *(int *)(puVar8 + -8) = unaff_EBP;
          puVar9 = (undefined4 *)&param_1[1].field_0x130;
          *(int *)(puVar8 + 8) = iVar6;
          do {
            if (*(char *)(*(int *)((int)pRVar3->players + (-0x5a4 - (int)param_1) + (int)puVar9) +
                         0x80) == '\x01') {
              pTVar4 = (TPanel *)*puVar9;
              *(undefined4 *)(puVar8 + -0xc) = 0;
              *(undefined4 *)(puVar8 + -0x10) = 0;
              *(undefined4 *)(puVar8 + -0x14) = 0;
              *(undefined4 *)(puVar8 + -0x18) = 0x48f140;
              lVar7 = TPanel::yPosition(pTVar4);
              pTVar4 = (TPanel *)*puVar9;
              *(long *)(puVar8 + -0x18) = lVar7;
              *(undefined4 *)(puVar8 + -0x1c) = 0x48f148;
              lVar7 = TPanel::xPosition(pTVar4);
              this = *(TShape **)&param_1[1].field_0x178;
              *(long *)(puVar8 + -0x1c) = lVar7 + -0x14;
              *(undefined4 *)(puVar8 + -0x20) = *(undefined4 *)&param_1->field_0x20;
              *(undefined4 *)(puVar8 + -0x24) = 0x48f15b;
              TShape::shape_draw(this,*(TDrawArea **)(puVar8 + -0x20),*(long *)(puVar8 + -0x1c),
                                 *(long *)(puVar8 + -0x18),*(long *)(puVar8 + -0x14),puVar8[-0x10],
                                 *(uchar **)(puVar8 + -0xc));
            }
            iVar10 = *(int *)(puVar8 + 8);
            puVar9 = puVar9 + 1;
            *(int *)(puVar8 + 8) = iVar10 + -1;
          } while (iVar10 + -1 != 0);
          iVar10 = *(int *)(puVar8 + 0xc);
        }
        pTVar2 = *(TDrawArea **)&param_1->field_0x20;
        *(char **)(puVar8 + -8) = s_scr_ach__draw;
        *(undefined4 *)(puVar8 + -0xc) = 0x48f17b;
        TDrawArea::Unlock(pTVar2,*(char **)(puVar8 + -8));
      }
    }
    pcVar1 = *(code **)(iVar10 + 0x2c);
    *(undefined4 *)(puVar8 + -4) = 0x48f181;
    (*pcVar1)();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0048f187
// Address: 0048f187
// XREFS: None
long __thiscall
FUN_0048f187(TribeAchievementsScreen *param_1,uchar param_2,long param_3,long param_4,int param_5,
            int param_6)
{
  long lVar1;
  int iVar2;
  
  lVar1 = TEasy_Panel::handle_mouse_down
                    ((TEasy_Panel *)param_1,param_2,param_3,param_4,param_5,param_6);
  if (param_1->current_mode == 0) {
    iVar2 = (**(code **)(param_1->achievement_choice[0]->_padding_ + 0xbc))(param_3,param_4);
    if (iVar2 != 0) {
      TribeAchievementsScreen::set_mode(param_1,1);
      return lVar1;
    }
    iVar2 = (**(code **)(param_1->achievement_choice[1]->_padding_ + 0xbc))(param_3,param_4);
    if (iVar2 != 0) {
      TribeAchievementsScreen::set_mode(param_1,2);
      return lVar1;
    }
    iVar2 = (**(code **)(param_1->achievement_choice[2]->_padding_ + 0xbc))(param_3,param_4);
    if (iVar2 != 0) {
      TribeAchievementsScreen::set_mode(param_1,3);
      return lVar1;
    }
    iVar2 = (**(code **)(param_1->achievement_choice[3]->_padding_ + 0xbc))(param_3,param_4);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(param_1->achievement_choice[4]->_padding_ + 0xbc))(param_3,param_4);
      if (iVar2 == 0) {
        TribeAchievementsScreen::set_mode(param_1,4);
      }
    }
  }
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_0048f272
// Address: 0048f272
// XREFS: None
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_YesNoDialog: "YesNoDialog"
long __thiscall
FUN_0048f272(TribeAchievementsScreen *param_1,TButtonPanel *param_2,int param_3,ulong param_4,
            ulong param_5)
{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  long lVar5;
  byte *pbVar6;
  bool bVar7;
  
  if ((param_2 == param_1->okButton) && (param_3 == 1)) {
    if (param_1->end_game_flag == 0) {
      iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
      }
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
    }
    else {
      TRIBE_Game::quit_game((TRIBE_Game *)rge_base_game);
    }
    TPanelSystem::destroyPanel(&panel_system,s_Achievements_Screen);
    return 1;
  }
  if ((param_2 == param_1->restartButton) && (param_3 == 1)) {
    TRIBE_Game::restart_game((TRIBE_Game *)rge_base_game);
    return 1;
  }
  if ((param_2 == param_1->timelineButton) && (param_3 == 1)) {
    TribeAchievementsScreen::set_mode(param_1,6);
    if (param_1->restartButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->restartButton->_padding_ + 0x14))(0);
    }
    if (param_1->okButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->okButton->_padding_ + 0x14))(0);
    }
    if (param_1->aftermathButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->aftermathButton->_padding_ + 0x14))(0);
    }
    if (param_1->timelineButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->timelineButton->_padding_ + 0x14))(0);
    }
    if (param_1->backButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->backButton->_padding_ + 0x14))(1);
      return 1;
    }
  }
  else {
    if ((param_2 != param_1->aftermathButton) || (param_3 != 1)) {
      if (((param_2 == param_1->backButton) || (param_2 == param_1->backButton2)) && (param_3 == 1))
{
        TribeAchievementsScreen::set_mode(param_1,0);
        return 1;
      }
      if ((param_2 == param_1->close_button) && (param_3 == 1)) {
        RGE_Base_Game::close(rge_base_game);
        return 1;
      }
      pcVar3 = TPanel::panelName((TPanel *)param_2);
      if (pcVar3 != (char *)0x0) {
        pbVar6 = &s_YesNoDialog;
        pbVar4 = (byte *)TPanel::panelName((TPanel *)param_2);
        do {
          bVar1 = *pbVar4;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_0048f49b:
            iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_0048f4a0;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_0048f49b;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar2 = 0;
LAB_0048f4a0:
        if (iVar2 == 0) {
          TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
          if (param_3 != 0) {
            confirmed_close = 0;
            return 1;
          }
          RGE_Base_Game::close(rge_base_game);
          return 1;
        }
      }
      lVar5 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
      return lVar5;
    }
    TribeAchievementsScreen::set_mode(param_1,5);
    if (param_1->restartButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->restartButton->_padding_ + 0x14))(0);
    }
    if (param_1->okButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->okButton->_padding_ + 0x14))(0);
    }
    if (param_1->aftermathButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->aftermathButton->_padding_ + 0x14))(0);
    }
    if (param_1->timelineButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->timelineButton->_padding_ + 0x14))(0);
    }
    if (param_1->backButton != (TButtonPanel *)0x0) {
      (**(code **)(param_1->backButton->_padding_ + 0x14))(1);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0048f4fe
// Address: 0048f4fe
// XREFS: None
void __fastcall FUN_0048f4fe(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0048f521
// Address: 0048f521
// XREFS: None
long __thiscall
FUN_0048f521(TEasy_Panel *param_1,void *param_2,uint param_3,uint param_4,long param_5)
{
  char *pcVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  if ((param_3 == 0x10) && (confirmed_close == 0)) {
    confirmed_close = 1;
    iVar4 = rge_base_game->prog_mode;
    if ((iVar4 == 5) || (((iVar4 == 4 || (iVar4 == 6)) || (iVar4 == 7)))) {
      pcVar1 = (char *)IsIconic(*(undefined4 *)(param_1->_padding_ + 4));
      if (pcVar1 == (char *)0x0) {
        iVar5 = 100;
        iVar4 = 0x1c2;
        pcVar2 = TPanel::get_string((TPanel *)param_1,0xc1d);
        TEasy_Panel::popupYesNoDialog(param_1,pcVar2,pcVar1,iVar4,iVar5);
        return 1;
      }
    }
  }
  lVar3 = TPanel::wnd_proc((TPanel *)param_1,param_2,param_3,param_4,param_5);
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_0048f5c2
// Address: 0048f5c2
// XREFS: None
// [HELPER] s_Campaign_Editor_Screen: "Campaign Editor Screen"
// [HELPER] s_scr4: "scr4"
TRIBE_Campaign_Editor_Screen * __fastcall FUN_0048f5c2(TRIBE_Campaign_Editor_Screen *param_1)
{
  TListPanel **ppTVar1;
  TListPanel **ppTVar2;
  TDropDownPanel **ppTVar3;
  TButtonPanel *pTVar4;
  long lVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  short sVar7;
  FormatType FVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  int iVar13;
  int iVar14;
  TDropDownPanel *pTStack_2c;
  TButtonPanel *pTStack_28;
  TListPanel *pTStack_24;
  TButtonPanel *pTStack_20;
  TButtonPanel *pTStack_1c;
  TListPanel *pTStack_18;
  TButtonPanel *pTStack_14;
  TButtonPanel *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e888;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Campaign_Editor_Screen);
  ppTVar1 = &param_1->scenarios;
  ppTVar2 = &param_1->campaign_scenarios;
  ppTVar3 = &param_1->filename_drop;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Campaign_Editor_Screen::_vftable_;
  param_1->title = (TTextPanel *)0x0;
  param_1->scenarios_title = (TTextPanel *)0x0;
  *ppTVar1 = (TListPanel *)0x0;
  param_1->scenarios_bar = (TScrollBarPanel *)0x0;
  param_1->campaign_scenarios_title = (TTextPanel *)0x0;
  *ppTVar2 = (TListPanel *)0x0;
  param_1->campaign_scenarios_bar = (TScrollBarPanel *)0x0;
  param_1->filename_title = (TTextPanel *)0x0;
  param_1->filename = (TEditPanel *)0x0;
  param_1->cancel_button = (TButtonPanel *)0x0;
  param_1->save_button = (TButtonPanel *)0x0;
  param_1->ok_button = (TButtonPanel *)0x0;
  param_1->campaign = (RGE_Campaign *)0x0;
  *ppTVar3 = (TDropDownPanel *)0x0;
  param_1->add_button = (TButtonPanel *)0x0;
  param_1->remove_button = (TButtonPanel *)0x0;
  param_1->move_scenario_up_button = (TButtonPanel *)0x0;
  param_1->move_scenario_down_button = (TButtonPanel *)0x0;
  lVar5 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,s_scr4,0xc386,1);
  if (lVar5 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,0x2bc1,10,10,0x26c,0x32,1,3,0,
             0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->filename_title,0x2bc2,0x14,0x28,
             0x104,0x14,4,0,0,0);
  TEasy_Panel::create_drop_down
            ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar3,0x17c,200,0x14,0x3c,0x17c,
             (param_1->_padding_ * 0x1e) / param_1->_padding_,0xb);
  iVar14 = 1;
  iVar13 = 1;
  lVar12 = 0xb;
  lVar11 = 0x1e;
  lVar10 = 0x168;
  lVar9 = 0;
  lVar5 = 0;
  FVar8 = FormatFileNoExt;
  sVar7 = 100;
  pcVar6 = TPanel::get_string((TPanel *)param_1,0x2bca);
  TEasy_Panel::create_edit
            ((TEasy_Panel *)param_1,(TPanel *)*ppTVar3,&param_1->filename,pcVar6,sVar7,FVar8,lVar5,
             lVar9,lVar10,lVar11,lVar12,iVar13,iVar14);
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->save_button,0x2bc4,0,0x1a4,0x3c,200,
             0x1e,0,0,0);
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->add_button,0x2bc5,0,0x118,0x104,0xa0
             ,0x1e,0,0,0);
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->remove_button,0x2bc6,0,0x1cc,0x104,
             0xa0,0x1e,0,0,0);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->scenarios_title,0x2bc7,0x14,100,200,
             0x14,4,0,0,0);
  TEasy_Panel::create_list((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x14,0x78,600,0x82,0xb);
  TEasy_Panel::create_auto_scrollbar
            ((TEasy_Panel *)param_1,&param_1->scenarios_bar,(TTextPanel *)*ppTVar1,0x14);
  TEasy_Panel::create_text
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->campaign_scenarios_title,0x2bc8,0x14
             ,0x118,200,0x14,4,0,0,0);
  TEasy_Panel::create_list((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,0x14,300,500,0x82,0xb);
  TEasy_Panel::create_auto_scrollbar
            ((TEasy_Panel *)param_1,&param_1->campaign_scenarios_bar,(TTextPanel *)*ppTVar2,0x14);
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->ok_button,0xfa1,0,0x14,0x1bd,0x118,
             0x1e,0,0,0);
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->cancel_button,0xfa2,0,0x154,0x1bd,
             0x118,0x1e,0,0,0);
  pTVar4 = param_1->cancel_button;
  pTVar4->hotkey = 0x1b;
  pTVar4->hotkey_shift = 0;
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->move_scenario_up_button,0x2bd5,0,
             0x212,300,0x5a,0x1e,0,0,0);
  TEasy_Panel::create_button
            ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->move_scenario_down_button,0x2bd6,0,
             0x212,0x154,0x5a,0x1e,0,0,0);
  pTStack_2c = *ppTVar3;
  pTStack_28 = param_1->save_button;
  pTStack_24 = *ppTVar1;
  pTStack_20 = param_1->add_button;
  pTStack_1c = param_1->remove_button;
  pTStack_18 = *ppTVar2;
  pTStack_14 = param_1->ok_button;
  pTStack_10 = param_1->cancel_button;
  TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_2c,8);
  TPanel::set_curr_child((TPanel *)*ppTVar3,(TPanel *)param_1->filename);
  TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*ppTVar3);
  TRIBE_Campaign_Editor_Screen::fill_scenario_list(param_1);
  TRIBE_Campaign_Editor_Screen::fill_campaign_drop(param_1);
  TTextPanel::empty_list((TTextPanel *)*ppTVar2);
  TRIBE_Campaign_Editor_Screen::load_campaign(param_1);
  param_1->need_to_save = '\0';
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0048fa3e
// Address: 0048fa3e
// XREFS: None
// [HELPER] s_Cancel_Dialog: "Cancel Dialog"
// [HELPER] s_Load_Dialog: "Load Dialog"
void __fastcall FUN_0048fa3e(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e8a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Campaign_Editor_Screen::_vftable_;
  uStack_4 = 0;
  TPanelSystem::destroyPanel(&panel_system,&s_Cancel_Dialog);
  TPanelSystem::destroyPanel(&panel_system,&s_Load_Dialog);
  if (*(undefined4 **)&param_1[1].field_0x4 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x4)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0xc != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xc)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x10 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x10)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x14 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x14)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x1c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x1c)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x18 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x18)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x20 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x20)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x8 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x8)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x24 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x24)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x44 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x44)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x2c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x2c)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x30 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x30)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x28 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x28)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x34 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x34)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x38 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x38)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x3c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x3c)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x40 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x40)(1);
  }
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0048fbb8
// Address: 0048fbb8
// XREFS: None
// [HELPER] s__s__cpn: "%s*.cpn"
// [HELPER] s__s__cpx: "%s*.cpx"
void __fastcall FUN_0048fbb8(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char acStack_218 [256];
  undefined1 auStack_118 [20];
  char acStack_104 [260];
  
  TDropDownPanel::set_sorted(*(TDropDownPanel **)(param_1 + 0x4bc),1);
  TDropDownPanel::empty_list(*(TDropDownPanel **)(param_1 + 0x4bc));
  sprintf(acStack_218,s__s__cpn,rge_base_game->prog_info->campaign_dir);
  iVar2 = __findfirst(acStack_218,auStack_118);
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
    strncpy(acStack_218,acStack_104,~uVar4 - 5);
    acStack_218[~uVar4 - 5] = '\0';
    TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x4bc),acStack_218,0);
    iVar3 = __findnext(iVar2,auStack_118);
  }
  sprintf(acStack_218,s__s__cpx,rge_base_game->prog_info->campaign_dir);
  iVar2 = __findfirst(acStack_218,auStack_118);
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
    strncpy(acStack_218,acStack_104,~uVar4 - 5);
    acStack_218[~uVar4 - 5] = '\0';
    TDropDownPanel::append_line(*(TDropDownPanel **)(param_1 + 0x4bc),acStack_218,0);
    iVar3 = __findnext(iVar2,auStack_118);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0048fd1b
// Address: 0048fd1b
// XREFS: None
// [HELPER] s__s__scn: "%s*.scn"
// [HELPER] s__s__scx: "%s*.scx"
void __fastcall FUN_0048fd1b(int param_1)
{
  char cVar1;
  TTextPanel *pTVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char acStack_218 [256];
  undefined1 auStack_118 [20];
  char acStack_104 [260];
  
  *(undefined4 *)(*(int *)(param_1 + 0x48c) + 0x15c) = 1;
  TTextPanel::empty_list(*(TTextPanel **)(param_1 + 0x48c));
  sprintf(acStack_218,s__s__scn,rge_base_game->prog_info->scenario_dir);
  iVar3 = __findfirst(acStack_218,auStack_118);
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
    strncpy(acStack_218,acStack_104,~uVar5 - 5);
    pTVar2 = *(TTextPanel **)(param_1 + 0x48c);
    acStack_218[~uVar5 - 5] = '\0';
    TTextPanel::append_line(pTVar2,acStack_218,0);
    iVar4 = __findnext(iVar3,auStack_118);
  }
  sprintf(acStack_218,s__s__scx,rge_base_game->prog_info->scenario_dir);
  iVar3 = __findfirst(acStack_218,auStack_118);
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
    strncpy(acStack_218,acStack_104,~uVar5 - 5);
    pTVar2 = *(TTextPanel **)(param_1 + 0x48c);
    acStack_218[~uVar5 - 5] = '\0';
    TTextPanel::append_line(pTVar2,acStack_218,0);
    iVar4 = __findnext(iVar3,auStack_118);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0048fef7
// Address: 0048fef7
// XREFS: None
undefined4 __fastcall FUN_0048fef7(int param_1)
{
  int iVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  
  iVar1 = TTextPanel::numberLines(*(TTextPanel **)(param_1 + 0x490));
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      pcVar2 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x490),iVar4);
      lVar3 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x48c),pcVar2);
      if (lVar3 == -1) {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      pcVar2 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x490),iVar4);
      lVar3 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x48c),pcVar2);
      TTextPanel::delete_line(*(TTextPanel **)(param_1 + 0x48c),lVar3);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0048ff75
// Address: 0048ff75
// XREFS: None
// [HELPER] s__cpn: ".cpn"
// [HELPER] s__cpx: ".cpx"
void __fastcall FUN_0048ff75(TRIBE_Campaign_Editor_Screen *param_1)
{
  uchar uVar1;
  char *pcVar2;
  int iVar3;
  RGE_Campaign *pRVar4;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar5;
  char *pcStack_130;
  char *pcStack_12c;
  RGE_Campaign *pRStack_128;
  undefined1 auStack_124 [280];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e8ce;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pcVar5 = s__cpn;
  pcStack_130 = (char *)0x0;
  pcStack_12c = (char *)0x0;
  pcVar2 = TEditPanel::get_text(param_1->filename);
  addstring(&pcStack_130,pcVar2,pcVar5);
  addstring(&pcStack_12c,rge_base_game->prog_info->campaign_dir,pcStack_130);
  iVar3 = __findfirst(pcStack_12c,auStack_124);
  if (iVar3 == -1) {
    pcVar5 = s__cpx;
    pcVar2 = TEditPanel::get_text(param_1->filename);
    addstring(&pcStack_130,pcVar2,pcVar5);
    addstring(&pcStack_12c,rge_base_game->prog_info->campaign_dir,pcStack_130);
    iVar3 = __findfirst(pcStack_12c,auStack_124);
    if (iVar3 == -1) {
      uVar1 = '\0';
      goto LAB_004900cf;
    }
  }
  pRStack_128 = (RGE_Campaign *)operator_new(0x20c);
  uStack_4 = 0;
  if (pRStack_128 == (RGE_Campaign *)0x0) {
    pRVar4 = (RGE_Campaign *)0x0;
  }
  else {
    pRVar4 = (RGE_Campaign *)RGE_Campaign::RGE_Campaign(pRStack_128,pcStack_130);
  }
  uStack_4 = 0xffffffff;
  param_1->campaign = pRVar4;
  TRIBE_Campaign_Editor_Screen::fill_scenario_list(param_1);
  TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list(param_1);
  uVar1 = TRIBE_Campaign_Editor_Screen::check_lists(param_1);
  pRVar4 = param_1->campaign;
  if (pRVar4 != (RGE_Campaign *)0x0) {
    RGE_Campaign::~RGE_Campaign(pRVar4);
    operator_delete(pRVar4);
  }
  param_1->campaign = (RGE_Campaign *)0x0;
LAB_004900cf:
  if (uVar1 == '\0') {
    TTextPanel::empty_list((TTextPanel *)param_1->campaign_scenarios);
  }
  free(pcStack_130);
  free(pcStack_12c);
  param_1->need_to_save = '\0';
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00490118
// Address: 00490118
// XREFS: None
// [HELPER] s__cpx: ".cpx"
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__scn: ".scn"
// [HELPER] s__scx: ".scx"
void __fastcall FUN_00490118(TRIBE_Campaign_Editor_Screen *param_1)
{
  char cVar1;
  RGE_Campaign *pRVar2;
  int iVar3;
  char **ppcVar4;
  char **ppcVar5;
  char *pcVar6;
  int iVar7;
  char **ppcVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar10;
  char *pcStack_234;
  RGE_Campaign *pRStack_230;
  int iStack_22c;
  undefined1 auStack_228 [260];
  undefined1 auStack_124 [280];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e8ee;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar9 = 0;
  pcStack_234 = (char *)0x0;
  pRVar2 = (RGE_Campaign *)TEditPanel::get_text(param_1->filename);
  if (pRVar2 != (RGE_Campaign *)0x0) {
    cVar1 = (char)(pRVar2->campaign_header).version;
    pRStack_230 = pRVar2;
    if ((cVar1 == '\0') || (cVar1 == ' ')) {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x2bcc,(char *)0x0,0x1c2,100);
      goto LAB_00490351;
    }
    addstring(&pcStack_234,(char *)pRVar2,s__cpx);
    iVar3 = TTextPanel::numberLines((TTextPanel *)param_1->campaign_scenarios);
    if (iVar3 < 1) {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x2bcb,(char *)0x0,0x1c2,100);
    }
    else {
      ppcVar4 = (char **)calloc(iVar3,4);
      ppcVar5 = (char **)calloc(iVar3,4);
      if (0 < iVar3) {
        iStack_22c = (int)ppcVar4 - (int)ppcVar5;
        ppcVar8 = ppcVar5;
        do {
          pcVar6 = TTextPanel::get_text((TTextPanel *)param_1->campaign_scenarios,iVar9);
          getstring((char **)(iStack_22c + (int)ppcVar8),pcVar6);
          pcVar6 = TTextPanel::get_text((TTextPanel *)param_1->campaign_scenarios,iVar9);
          getstring(ppcVar8,pcVar6);
          sprintf(auStack_228,s__s_s_scn,rge_base_game->prog_info->scenario_dir,*ppcVar8);
          iVar7 = __findfirst(auStack_228,auStack_124);
          if (iVar7 == -1) {
            pcVar6 = *ppcVar8;
            pcVar10 = s__scx;
          }
          else {
            pcVar6 = *ppcVar8;
            pcVar10 = s__scn;
          }
          addstring(ppcVar8,pcVar6,pcVar10);
          iVar9 = iVar9 + 1;
          ppcVar8 = ppcVar8 + 1;
          pRVar2 = pRStack_230;
        } while (iVar9 < iVar3);
      }
      pRStack_230 = (RGE_Campaign *)operator_new(0x20c);
      uStack_4 = 0;
      if (pRStack_230 == (RGE_Campaign *)0x0) {
        pRVar2 = (RGE_Campaign *)0x0;
      }
      else {
        pRVar2 = (RGE_Campaign *)
                 RGE_Campaign::RGE_Campaign
                           (pRStack_230,pcStack_234,(char *)pRVar2,iVar3,ppcVar5,ppcVar4);
      }
      uStack_4 = 0xffffffff;
      param_1->campaign = pRVar2;
      if (pRVar2 != (RGE_Campaign *)0x0) {
        RGE_Campaign::~RGE_Campaign(pRVar2);
        operator_delete(pRVar2);
      }
      param_1->campaign = (RGE_Campaign *)0x0;
      if (0 < iVar3) {
        ppcVar8 = ppcVar5;
        do {
          free(*(undefined4 *)((int)ppcVar8 + ((int)ppcVar4 - (int)ppcVar5)));
          free(*ppcVar8);
          ppcVar8 = ppcVar8 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      free(ppcVar4);
      free(ppcVar5);
    }
    free(pcStack_234);
    TRIBE_Campaign_Editor_Screen::fill_campaign_drop(param_1);
    RGE_Base_Game::find_campaigns(rge_base_game);
  }
  param_1->need_to_save = '\0';
LAB_00490351:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004903fc
// Address: 004903fc
// XREFS: None
void __fastcall FUN_004903fc(int param_1)
{
  char *pcVar1;
  long lVar2;
  int iVar3;
  
  pcVar1 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x490));
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    TTextPanel::append_line(*(TTextPanel **)(param_1 + 0x48c),pcVar1,0);
    lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x48c),pcVar1);
    TTextPanel::set_line(*(TTextPanel **)(param_1 + 0x48c),lVar2);
    lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
    TTextPanel::delete_line(*(TTextPanel **)(param_1 + 0x490),lVar2);
    iVar3 = 1;
    lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x48c));
    TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x48c),'\x01',(short)lVar2,iVar3);
  }
  *(undefined1 *)(param_1 + 0x478) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0049047c
// Address: 0049047c
// XREFS: None
void __fastcall FUN_0049047c(int param_1)
{
  long lVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  
  lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
  if (0 < lVar1) {
    pcVar2 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x490));
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      lVar3 = 0;
      lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
      TTextPanel::insert_line(*(TTextPanel **)(param_1 + 0x490),lVar1 + -1,pcVar2,lVar3);
      lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
      TTextPanel::delete_line(*(TTextPanel **)(param_1 + 0x490),lVar1 + 1);
      lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
      TTextPanel::set_line(*(TTextPanel **)(param_1 + 0x490),lVar1 + -1);
      iVar4 = 1;
      lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
      TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x490),'\x01',(short)lVar1,iVar4);
    }
    *(undefined1 *)(param_1 + 0x478) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00490519
// Address: 00490519
// XREFS: None
void __fastcall FUN_00490519(int param_1)
{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  iVar1 = TTextPanel::numberLines(*(TTextPanel **)(param_1 + 0x490));
  lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
  if (lVar2 < iVar1 + -1) {
    pcVar3 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x490));
    if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
      lVar4 = 0;
      lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
      TTextPanel::insert_line(*(TTextPanel **)(param_1 + 0x490),lVar2 + 2,pcVar3,lVar4);
      lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
      TTextPanel::delete_line(*(TTextPanel **)(param_1 + 0x490),lVar2);
      lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
      TTextPanel::set_line(*(TTextPanel **)(param_1 + 0x490),lVar2 + 1);
      iVar1 = 1;
      lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x490));
      TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x490),'\x01',(short)lVar2,iVar1);
    }
    *(undefined1 *)(param_1 + 0x478) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004905ca
// Address: 004905ca
// XREFS: None
// [HELPER] s_Campaign_Editor_Screen: "Campaign Editor Screen"
// [HELPER] s_Cancel_Dialog: "Cancel Dialog"
// [HELPER] s_Load_Dialog: "Load Dialog"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
long __thiscall
FUN_004905ca(TRIBE_Campaign_Editor_Screen *param_1,TButtonPanel *param_2,int param_3,ulong param_4,
            ulong param_5)
{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  TRIBE_Screen_Sed_Menu *this;
  long lVar5;
  byte *pbVar6;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;
  char acStack_238 [256];
  char acStack_138 [300];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e92a;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == (TButtonPanel *)0x0) goto LAB_004909a9;
  if ((param_2 == (TButtonPanel *)param_1->filename_drop) && (param_3 == 2)) {
    TPanel::set_curr_child((TPanel *)param_1->filename_drop,(TPanel *)param_1->filename);
    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->filename_drop);
  }
  if (param_3 == 3) {
    if (param_2 == (TButtonPanel *)param_1->scenarios) {
      TRIBE_Campaign_Editor_Screen::add_scenario(param_1);
    }
    else if (param_2 == (TButtonPanel *)param_1->campaign_scenarios) {
      TRIBE_Campaign_Editor_Screen::remove_scenario(param_1);
    }
  }
  if ((param_2 == (TButtonPanel *)param_1->filename_drop) && (param_3 == 0)) {
    if ((param_1->need_to_save == '\0') ||
       (iVar2 = TTextPanel::numberLines((TTextPanel *)param_1->campaign_scenarios), iVar2 < 1)) {
      pcVar3 = TDropDownPanel::get_text(param_1->filename_drop);
      TEditPanel::set_text(param_1->filename,pcVar3);
      TRIBE_Campaign_Editor_Screen::load_campaign(param_1);
    }
    else {
      TPanel::get_string((TPanel *)param_1,0x2bc9,acStack_238,0x100);
      pcVar3 = TEditPanel::get_text(param_1->filename);
      sprintf(acStack_138,acStack_238,pcVar3);
      TEasy_Panel::popupYesNoCancelDialog
                ((TEasy_Panel *)param_1,acStack_138,&s_Load_Dialog,0x1c2,100);
    }
  }
  if (param_3 == 1) {
    if (param_2 != param_1->ok_button) {
      if (param_2 == param_1->save_button) {
        TRIBE_Campaign_Editor_Screen::make_campaign(param_1);
      }
      else {
        if (param_2 == param_1->cancel_button) {
          this = (TRIBE_Screen_Sed_Menu *)operator_new(0x490);
          uStack_4 = 1;
          goto joined_r0x004908c9;
        }
        if (param_2 == param_1->add_button) {
          TRIBE_Campaign_Editor_Screen::add_scenario(param_1);
        }
        else if (param_2 == param_1->remove_button) {
          TRIBE_Campaign_Editor_Screen::remove_scenario(param_1);
        }
        else if (param_2 == param_1->move_scenario_up_button) {
          TRIBE_Campaign_Editor_Screen::move_scenario_up(param_1);
        }
        else if (param_2 == param_1->move_scenario_down_button) {
          TRIBE_Campaign_Editor_Screen::move_scenario_down(param_1);
        }
      }
      goto LAB_00490838;
    }
    if ((param_1->need_to_save != '\0') &&
       (iVar2 = TTextPanel::numberLines((TTextPanel *)param_1->campaign_scenarios), 0 < iVar2)) {
      TPanel::get_string((TPanel *)param_1,0x2bc9,acStack_238,0x100);
      pcVar3 = TEditPanel::get_text(param_1->filename);
      sprintf(acStack_138,acStack_238,pcVar3);
      TEasy_Panel::popupYesNoCancelDialog
                ((TEasy_Panel *)param_1,acStack_138,&s_Cancel_Dialog,0x1c2,100);
      goto LAB_00490838;
    }
    this = (TRIBE_Screen_Sed_Menu *)operator_new(0x490);
    uStack_4 = 0;
joined_r0x004908c9:
    if (this != (TRIBE_Screen_Sed_Menu *)0x0) {
      TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu(this);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Menu,0);
    TPanelSystem::destroyPanel(&panel_system,s_Campaign_Editor_Screen);
    lVar5 = 1;
    goto LAB_004909b0;
  }
LAB_00490838:
  pcVar3 = TPanel::panelName((TPanel *)param_2);
  if (pcVar3 == (char *)0x0) {
LAB_00490907:
    pcVar3 = TPanel::panelName((TPanel *)param_2);
    if (pcVar3 != (char *)0x0) {
      pbVar6 = &s_Load_Dialog;
      pbVar4 = (byte *)TPanel::panelName((TPanel *)param_2);
      do {
        bVar1 = *pbVar4;
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_00490946:
          iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0049094b;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar7 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_00490946;
        pbVar4 = pbVar4 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_0049094b:
      if (iVar2 == 0) {
        TPanelSystem::destroyPanel(&panel_system,&s_Load_Dialog);
        if (param_3 == 0) {
          TRIBE_Campaign_Editor_Screen::make_campaign(param_1);
        }
        else if (param_3 != 1) goto LAB_00490990;
        pcVar3 = TDropDownPanel::get_text(param_1->filename_drop);
        TEditPanel::set_text(param_1->filename,pcVar3);
        TRIBE_Campaign_Editor_Screen::load_campaign(param_1);
        goto LAB_00490990;
      }
    }
LAB_004909a9:
    lVar5 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  }
  else {
    pbVar6 = &s_Cancel_Dialog;
    pbVar4 = (byte *)TPanel::panelName((TPanel *)param_2);
    do {
      bVar1 = *pbVar4;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_00490877:
        iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_0049087c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_00490877;
      pbVar4 = pbVar4 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_0049087c:
    if (iVar2 != 0) goto LAB_00490907;
    TPanelSystem::destroyPanel(&panel_system,&s_Cancel_Dialog);
    if (param_3 == 0) {
      TRIBE_Campaign_Editor_Screen::make_campaign(param_1);
LAB_004908ab:
      this = (TRIBE_Screen_Sed_Menu *)operator_new(0x490);
      uStack_4 = 2;
      goto joined_r0x004908c9;
    }
    if (param_3 == 1) goto LAB_004908ab;
LAB_00490990:
    lVar5 = 1;
  }
LAB_004909b0:
  *unaff_FS_OFFSET = uStack_c;
  return lVar5;
}

// --------------------------------------------------

// Function: FUN_004909cb
// Address: 004909cb
// XREFS: None
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_scr2: "scr2"
TRIBE_Screen_Campaign_Selection * __fastcall FUN_004909cb(TRIBE_Screen_Campaign_Selection *param_1)
{
  TListPanel **ppTVar1;
  TDropDownPanel **ppTVar2;
  TButtonPanel **ppTVar3;
  TButtonPanel **ppTVar4;
  TButtonPanel *pTVar5;
  long lVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  TListPanel *pTStack_20;
  TListPanel *pTStack_1c;
  TDropDownPanel *pTStack_18;
  TButtonPanel *pTStack_14;
  TButtonPanel *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e948;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Campaign_Selection_Screen);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Screen_Campaign_Selection::_vftable_;
  TRIBE_Screen_Campaign_Selection::init_vars(param_1);
  lVar6 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,&s_scr2,0xc384,1);
  if (lVar6 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)param_1,0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)param_1,0x280,0x1e0);
  iVar7 = TEasy_Panel::create_text
                    ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->title,0x2bcd,0x14,10,600,
                     0x1e,1,1,0,0);
  if (iVar7 != 0) {
    ppTVar1 = &param_1->campaignList;
    param_1->campaignListX = 0x14;
    param_1->campaignListY = 0x46;
    param_1->campaignListWidth = 600;
    param_1->campaignListHeight = 0x82;
    iVar7 = TEasy_Panel::create_list
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x14,0x46,600,0x82,0xb);
    if (iVar7 != 0) {
      iVar7 = TEasy_Panel::create_auto_scrollbar
                        ((TEasy_Panel *)param_1,&param_1->campaignScrollbar,(TTextPanel *)*ppTVar1,
                         0x14);
      if (iVar7 != 0) {
        iVar7 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->campaignTitle,0x2bce,
                           param_1->campaignListX + -5,param_1->campaignListY + -0x14,200,0x14,4,0,0
                           ,0);
        if (iVar7 != 0) {
          (**(code **)((*ppTVar1)->_padding_ + 0xe4))(0x2b5d);
          iVar7 = param_1->campaignListHeight + 0x1e + param_1->campaignListY;
          ppTVar1 = &param_1->scenarioList;
          param_1->scenarioListX = 0x14;
          param_1->scenarioListY = iVar7;
          param_1->scenarioListWidth = 600;
          param_1->scenarioListHeight = 0x82;
          iVar7 = TEasy_Panel::create_list
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,0x14,iVar7,600,0x82,
                             0xb);
          if (iVar7 != 0) {
            iVar7 = TEasy_Panel::create_auto_scrollbar
                              ((TEasy_Panel *)param_1,&param_1->scenarioScrollbar,
                               (TTextPanel *)*ppTVar1,0x14);
            if (iVar7 != 0) {
              iVar7 = TEasy_Panel::create_text
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->scenarioTitle,
                                 0x25fe,param_1->scenarioListX + -5,param_1->scenarioListY + -0x14,
                                 200,0x14,4,0,0,0);
              if (iVar7 != 0) {
                (*ppTVar1)->_padding_ = 0;
                iVar7 = TEasy_Panel::create_text
                                  ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                   &param_1->difficultyTitle,0x2bcf,0xf,0x172,200,0x14,4,0,0,0);
                if (iVar7 != 0) {
                  ppTVar2 = &param_1->difficultyDrop;
                  iVar7 = TEasy_Panel::create_drop_down
                                    ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,0x82,100,0x14,
                                     0x186,0x82,0x18,0xb);
                  if (iVar7 != 0) {
                    TDropDownPanel::empty_list(*ppTVar2);
                    TDropDownPanel::append_line(*ppTVar2,0x2bd4,4);
                    TDropDownPanel::append_line(*ppTVar2,0x2bd3,3);
                    TDropDownPanel::append_line(*ppTVar2,0x2bd2,2);
                    TDropDownPanel::append_line(*ppTVar2,0x2bd1,1);
                    TDropDownPanel::append_line(*ppTVar2,0x2bd0,0);
                    iVar7 = RGE_Base_Game::difficulty(rge_base_game);
                    lVar6 = TDropDownPanel::get_line(*ppTVar2,iVar7);
                    TDropDownPanel::set_line(*ppTVar2,lVar6);
                    ppTVar3 = &param_1->okButton;
                    iVar7 = TEasy_Panel::create_button
                                      ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar3,0xfa1,0,0x46
                                       ,0x1b8,0xf0,0x1e,0,0,0);
                    if (iVar7 != 0) {
                      iVar7 = TEasy_Panel::create_button
                                        ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                         &param_1->cancelButton,0xfa2,0,0x14a,0x1b8,0xf0,0x1e,0,0,0)
                      ;
                      if (iVar7 != 0) {
                        pTVar5 = param_1->cancelButton;
                        pTVar5->hotkey = 0x1b;
                        pTVar5->hotkey_shift = 0;
                        ppTVar4 = &param_1->close_button;
                        iVar7 = TEasy_Panel::create_button
                                          ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar4,0x3ea,0,
                                           0,0,0,0,-1,-1,0);
                        if (iVar7 != 0) {
                          (**(code **)((*ppTVar4)->_padding_ + 0x14))(1);
                          (**(code **)((*ppTVar4)->_padding_ + 0x18))
                                    (9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                          pTStack_1c = param_1->scenarioList;
                          pTStack_18 = *ppTVar2;
                          pTStack_20 = param_1->campaignList;
                          pTStack_10 = param_1->cancelButton;
                          pTStack_14 = *ppTVar3;
                          TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_20,5);
                          TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*ppTVar3);
                          TRIBE_Screen_Campaign_Selection::fillCampaigns(param_1);
                          TRIBE_Screen_Campaign_Selection::fillScenarios(param_1);
                          TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->campaignList);
                          param_1->campaignsLoaded = 1;
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
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00490e0f
// Address: 00490e0f
// XREFS: None
TRIBE_Screen_Campaign_Selection * __thiscall
FUN_00490e0f(TRIBE_Screen_Campaign_Selection *param_1,byte param_2)
{
  TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00490e2e
// Address: 00490e2e
// XREFS: None
void __fastcall FUN_00490e2e(int param_1)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x478) = 0;
  *(undefined4 *)(param_1 + 0x48c) = 0;
  *(undefined4 *)(param_1 + 0x490) = 0;
  *(undefined4 *)(param_1 + 0x494) = 0;
  *(undefined4 *)(param_1 + 0x4a8) = 0;
  *(undefined4 *)(param_1 + 0x4ac) = 0;
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  *(undefined4 *)(param_1 + 0x4bc) = 0;
  *(undefined4 *)(param_1 + 0x4c0) = 0;
  *(undefined4 *)(param_1 + 0x4c4) = 0;
  *(undefined4 *)(param_1 + 0x4c8) = 0;
  iVar1 = RGE_Base_Game::get_single_player_difficulty(rge_base_game);
  RGE_Base_Game::setDifficulty(rge_base_game,iVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00490e98
// Address: 00490e98
// XREFS: None
void __fastcall FUN_00490e98(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e968;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Campaign_Selection::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x18);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x30);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x34);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x38);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x3c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x40);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x44);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x48);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x4c);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00490fe9
// Address: 00490fe9
// XREFS: None
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
long __thiscall
FUN_00490fe9(TRIBE_Screen_Campaign_Selection *param_1,TButtonPanel *param_2,int param_3,
            ulong param_4,ulong param_5)
{
  RGE_Game_Info *this;
  TRIBE_Screen_Name *this_00;
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar2;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e98b;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_2 != (TButtonPanel *)0x0) && (param_1->campaignsLoaded != 0)) {
    if ((param_2 == param_1->okButton) && (param_3 == 1)) {
      TRIBE_Screen_Campaign_Selection::startGame(param_1);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if ((param_2 == param_1->cancelButton) && (param_3 == 1)) {
      RGE_Base_Game::disable_input(rge_base_game);
      this_00 = (TRIBE_Screen_Name *)operator_new(0x4a0);
      uStack_4 = 0;
      if (this_00 != (TRIBE_Screen_Name *)0x0) {
        TRIBE_Screen_Name::TRIBE_Screen_Name(this_00);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Name_Selection_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Campaign_Selection_Screen);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if ((param_2 == param_1->close_button) && (param_3 == 1)) {
      RGE_Base_Game::close(rge_base_game);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if ((param_2 == (TButtonPanel *)param_1->campaignList) && (param_3 == 1)) {
      this = rge_base_game->player_game_info;
      lVar1 = TTextPanel::get_id((TTextPanel *)param_1->campaignList);
      RGE_Game_Info::set_current_campaign(this,lVar1);
      TRIBE_Screen_Campaign_Selection::fillScenarios(param_1);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if ((param_2 == (TButtonPanel *)param_1->scenarioList) && (param_3 == 3)) {
      uVar2 = 0;
      (**(code **)(param_1->_padding_ + 0xb4))(param_1->okButton,1,0,0);
      *unaff_FS_OFFSET = uVar2;
      return 1;
    }
  }
  lVar1 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  *unaff_FS_OFFSET = uStack_c;
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_00491282
// Address: 00491282
// XREFS: None
void __fastcall FUN_00491282(int param_1)
{
  long lVar1;
  long lVar2;
  int iVar3;
  char **ppcStack_8;
  long lStack_4;
  
  TTextPanel::empty_list(*(TTextPanel **)(param_1 + 0x4ac));
  ppcStack_8 = (char **)0x0;
  lVar1 = RGE_Game_Info::get_scenario_list(rge_base_game->player_game_info,&ppcStack_8,&lStack_4);
  if (lVar1 != 0) {
    iVar3 = 0;
    if (0 < lVar1) {
      do {
        TTextPanel::append_line(*(TTextPanel **)(param_1 + 0x4ac),ppcStack_8[iVar3],iVar3);
        iVar3 = iVar3 + 1;
      } while (iVar3 < lVar1);
    }
    lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0x4ac),lStack_4);
    TTextPanel::set_line(*(TTextPanel **)(param_1 + 0x4ac),lVar2);
    iVar3 = 0;
    if (0 < lVar1) {
      do {
        free(ppcStack_8[iVar3]);
        iVar3 = iVar3 + 1;
      } while (iVar3 < lVar1);
    }
    free(ppcStack_8);
    TListPanel::scroll_cur_line(*(TListPanel **)(param_1 + 0x4ac),'\a',0,1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00491343
// Address: 00491343
// XREFS: None
void __fastcall FUN_00491343(TEasy_Panel *param_1)
{
  RGE_Game_Info *this;
  long lVar1;
  RGE_Scenario *this_00;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  TEasy_Panel *pTStack_8;
  
  lVar1 = TTextPanel::get_line((TTextPanel *)param_1[1]._padding_);
  if (lVar1 != -1) {
    this = rge_base_game->player_game_info;
    lVar1 = TTextPanel::get_line((TTextPanel *)param_1[1]._padding_);
    RGE_Game_Info::set_current_scenario(this,lVar1);
    RGE_Base_Game::setScenarioGame(rge_base_game,1);
    RGE_Base_Game::setCampaignGame(rge_base_game,1);
    uVar5 = 0;
    RGE_Base_Game::setSavedGame(rge_base_game,0);
    TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game,VictoryDefault,0);
    lVar1 = TDropDownPanel::get_id((TDropDownPanel *)param_1[1]._padding_);
    RGE_Base_Game::setDifficulty(rge_base_game,lVar1);
    lVar1 = TDropDownPanel::get_id((TDropDownPanel *)param_1[1]._padding_);
    RGE_Base_Game::set_single_player_difficulty(rge_base_game,lVar1);
    TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game,'\0');
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game,'\0');
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
    iVar4 = -1;
    pTStack_8 = (TEasy_Panel *)0x0;
    this_00 = RGE_Base_Game::get_scenario_info(rge_base_game,(char *)0x0,1);
    if (this_00 == (RGE_Scenario *)0x0) {
      TEasy_Panel::popupOKDialog(param_1,0x9ca,(char *)0x0,0x1c2,100);
      return;
    }
    iVar6 = 0;
    do {
      iVar2 = RGE_Scenario::Get_player_Active(this_00,iVar6);
      if (iVar2 != 0) {
        TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,uVar5,iVar6);
        TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,uVar5,iVar6 + 1);
        RGE_Base_Game::setPlayerTeam(rge_base_game,uVar5,1);
        uVar5 = uVar5 + 1;
        if ((iVar4 == -1) && (iVar2 = RGE_Scenario::Get_player_Type(this_00,iVar6), iVar2 == 1)) {
          iVar4 = iVar6;
          pTStack_8 = (TEasy_Panel *)(iVar6 + 1);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    (**(code **)(this_00->_padding_ + 4))(1);
    if (uVar5 != 0) {
      RGE_Base_Game::setNumberPlayers(rge_base_game,uVar5);
      if (iVar4 != -1) {
        iVar6 = 1;
        if (1 < (int)uVar5) {
          do {
            iVar2 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game,iVar6);
            if (iVar2 == iVar4) {
              iVar2 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game,0);
              TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,iVar6,iVar2);
              iVar2 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,0);
              TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,iVar6,iVar2);
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < (int)uVar5);
        }
        TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game,0,iVar4);
        TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game,0,(int)this_00);
      }
      TCommunications_Handler::SetPlayerHumanity(comm,1,ME_HUMAN);
      uVar3 = 1;
      if (1 < (int)uVar5) {
        do {
          uVar3 = uVar3 + 1;
          TCommunications_Handler::SetPlayerHumanity(comm,uVar3,ME_COMPUTER);
        } while ((int)uVar3 < (int)uVar5);
      }
      while ((int)uVar5 < 9) {
        uVar5 = uVar5 + 1;
        TCommunications_Handler::SetPlayerHumanity(comm,uVar5,ME_ABSENT);
      }
      iVar4 = TRIBE_Game::start_game((TRIBE_Game *)rge_base_game,0);
      if (iVar4 == 0) {
        TEasy_Panel::popupOKDialog(pTStack_8,0x961,(char *)0x0,0x1c2,100);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049164a
// Address: 0049164a
// XREFS: None
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_scr3: "scr3"
TEasy_Panel * __fastcall FUN_0049164a(TEasy_Panel *param_1)
{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  undefined4 *unaff_FS_OFFSET;
  TListPanel *pTStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e9a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Join_Screen);
  param_1->_padding_ = (int)&TribeJoinScreen::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  Sess = (TCommunications_Sessions *)0x0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  uStack_4 = 0;
  TCommunications_Handler::SetPlayerHumanity(comm,1,ME_HUMAN);
  uVar6 = 2;
  do {
    TCommunications_Handler::SetPlayerHumanity(comm,uVar6,ME_ABSENT);
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 10);
  lVar4 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,&s_scr3,0xc385,1);
  if (lVar4 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TEasy_Panel::setup_shadow_area(param_1,0);
  TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
  iVar5 = TEasy_Panel::create_text
                    (param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x259f,0x14,0x14
                     ,600,0x1e,1,1,0,0);
  if (iVar5 != 0) {
    TEasy_Panel::create_text
              (param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x25a8,0x14,0x41,600,
               0x14,4,0,0,0);
    piVar1 = &param_1[1]._padding_;
    iVar5 = TEasy_Panel::create_list
                      (param_1,(TPanel *)param_1,(TListPanel **)piVar1,0x14,0x5a,600,0x10e,0xb);
    if (iVar5 != 0) {
      iVar5 = TEasy_Panel::create_auto_scrollbar
                        (param_1,(TScrollBarPanel **)&param_1[1]._padding_,(TTextPanel *)*piVar1,
                         0x14);
      if (iVar5 != 0) {
        param_1[1]._padding_ = 1;
        (**(code **)(*(int *)*piVar1 + 0xe4))(0x25ab);
        piVar2 = &param_1[1]._padding_;
        iVar5 = TEasy_Panel::create_button
                          (param_1,(TPanel *)param_1,(TButtonPanel **)piVar2,0x25a1,0,0xd2,0x172,
                           0xdc,0x1e,0,0,0);
        if (iVar5 != 0) {
          iVar5 = TEasy_Panel::create_button
                            (param_1,(TPanel *)param_1,(TButtonPanel **)&param_1[1]._padding_,0x25a0
                             ,0,10,0x1b8,200,0x1e,0,0,0);
          if (iVar5 != 0) {
            iVar5 = TEasy_Panel::create_button
                              (param_1,(TPanel *)param_1,(TButtonPanel **)&param_1[1]._padding_,
                               0x25a2,0,0xdc,0x1b8,200,0x1e,0,0,0);
            if (iVar5 != 0) {
              piVar3 = &param_1[1]._padding_;
              iVar5 = TEasy_Panel::create_button
                                (param_1,(TPanel *)param_1,(TButtonPanel **)piVar3,0xfa2,0,0x1ae,
                                 0x1b8,200,0x1e,0,0,0);
              if (iVar5 != 0) {
                iVar5 = *piVar3;
                *(undefined4 *)(iVar5 + 0x298) = 0x1b;
                *(undefined4 *)(iVar5 + 0x29c) = 0;
                iVar5 = TEasy_Panel::create_button
                                  (param_1,(TPanel *)param_1,(TButtonPanel **)&param_1[1]._padding_,
                                   0x3ea,0,0,0,0,0,-1,-1,0);
                if (iVar5 != 0) {
                  (**(code **)(*(int *)param_1[1]._padding_ + 0x14))(1);
                  (**(code **)(*(int *)param_1[1]._padding_ + 0x18))
                            (9,4,4,4,4,0x11,0x11,0x11,0x11,0,0,0,0);
                  TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*piVar2);
                  iStack_18 = param_1[1]._padding_;
                  pTStack_20 = (TListPanel *)*piVar1;
                  iStack_1c = *piVar2;
                  iStack_14 = param_1[1]._padding_;
                  iStack_10 = *piVar3;
                  TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_20,5);
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

// Function: FUN_0049196d
// Address: 0049196d
// XREFS: None
TribeJoinScreen * __thiscall FUN_0049196d(TribeJoinScreen *param_1,byte param_2)
{
  TribeJoinScreen::~TribeJoinScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049198e
// Address: 0049198e
// XREFS: None
void __fastcall FUN_0049198e(TScreenPanel *param_1)
{
  TCommunications_Sessions *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e9c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeJoinScreen::_vftable_;
  pTVar1 = Sess;
  uStack_4 = 0;
  if (Sess != (TCommunications_Sessions *)0x0) {
    TCommunications_Sessions::~TCommunications_Sessions(Sess);
    operator_delete(pTVar1);
  }
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x8);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0xc);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x10);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x14);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x24);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x18);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x1c);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x20);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1].field_0x28);
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00491a74
// Address: 00491a74
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_cj_cpp: "C:\msdev\work\age1_x1\scr_cj.cpp"
long __fastcall FUN_00491a74(TEasy_Panel *param_1)
{
  ulong uVar1;
  long lVar2;
  
  if (param_1[1]._padding_ == 0) {
    if ((param_1[1]._padding_ != 0) && (rge_base_game->input_enabled == 0)) {
      RGE_Base_Game::enable_input(rge_base_game);
    }
    if (param_1[1]._padding_ == 0) goto LAB_00491b15;
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cj_cpp,0xaa);
  if (10000 < uVar1 - param_1[1]._padding_) {
    TCommunications_Handler::UnlinkToLevel(comm,SERVICE_AVAILABLE);
    param_1[1]._padding_ = 0;
    RGE_Base_Game::enable_input(rge_base_game);
    TEasy_Panel::popupOKDialog(param_1,0x25a3,(char *)0x0,0x1c2,100);
    return 1;
  }
LAB_00491b15:
  lVar2 = TPanel::handle_idle((TPanel *)param_1);
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_00491b1e
// Address: 00491b1e
// XREFS: None
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
long __thiscall FUN_00491b1e(TEasy_Panel *param_1,uint param_2,long param_3)
{
  TribeMPSetupScreen *this;
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e9eb;
  *unaff_FS_OFFSET = &uStack_c;
  switch(param_2) {
  case 0x17a8:
  case 0x17a9:
  case 0x17aa:
  case 0x17b2:
    if (param_1[1]._padding_ != 0) {
      TCommunications_Handler::UnlinkToLevel(comm,SERVICE_AVAILABLE);
      param_1[1]._padding_ = 0;
      RGE_Base_Game::enable_input(rge_base_game);
      TEasy_Panel::popupOKDialog(param_1,0x25a3,(char *)0x0,0x1c2,100);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    break;
  case 0x17b8:
    if (param_1[1]._padding_ != 0) {
      this = (TribeMPSetupScreen *)operator_new(0x890);
      uStack_4 = 0;
      if (this != (TribeMPSetupScreen *)0x0) {
        TribeMPSetupScreen::TribeMPSetupScreen(this);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
  }
  lVar1 = TPanel::handle_user_command((TPanel *)param_1,param_2,param_3);
  *unaff_FS_OFFSET = uStack_c;
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_00491c42
// Address: 00491c42
// XREFS: None
void FUN_00491c42(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00491e1d
// Address: 00491e1d
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_cj_cpp: "C:\msdev\work\age1_x1\scr_cj.cpp"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
long __thiscall
FUN_00491e1d(TribeJoinScreen *param_1,TButtonPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  long lVar1;
  int iVar2;
  _GUID *p_Var3;
  char *pcVar4;
  ulong uVar5;
  TribeMPStartupScreen *this;
  TribeMPCreateDialog *this_00;
  undefined4 *unaff_FS_OFFSET;
  char acStack_20c [256];
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ea3c;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == (TButtonPanel *)0x0) {
LAB_0049208e:
    lVar1 = TEasy_Panel::action((TEasy_Panel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  }
  else {
    if (param_2 == (TButtonPanel *)param_1->list) {
      if ((param_3 == 3) && (0 < param_1->game_count)) {
        (**(code **)(param_1->_padding_ + 0xb4))(param_1->joinButton,1,0,0);
        lVar1 = 1;
        goto LAB_004920a7;
      }
    }
    else if (param_2 == param_1->joinButton) {
      if (param_3 == 1) {
        if (param_1->game_count < 1) {
          TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,0x25a4,(char *)0x0,0x1c2,100);
          lVar1 = 1;
        }
        else {
          iVar2 = TTextPanel::currentLineNumber((TTextPanel *)param_1->list);
          p_Var3 = TCommunications_Sessions::GetSessionGUID(Sess,iVar2);
          iVar2 = TCommunications_Handler::JoinMultiplayerGame(comm,p_Var3);
          if (iVar2 == 0) {
            TPanel::get_string((TPanel *)param_1,0x25a3,acStack_20c,0x100);
            pcVar4 = TTextPanel::currentLine((TTextPanel *)param_1->list);
            sprintf(acStack_10c,acStack_20c,pcVar4);
            TEasy_Panel::popupOKDialog((TEasy_Panel *)param_1,acStack_10c,(char *)0x0,0x1c2,100);
            lVar1 = 1;
          }
          else {
            RGE_Base_Game::disable_input(rge_base_game);
            param_1->waitingToStart = 1;
            uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cj_cpp,0x140);
            param_1->joinTime = uVar5;
            lVar1 = 1;
          }
        }
        goto LAB_004920a7;
      }
    }
    else if (param_2 == param_1->cancelButton) {
      if (param_3 == 1) {
        RGE_Base_Game::disable_input(rge_base_game);
        TCommunications_Handler::UnlinkToLevel(comm,SINGLE_PLAYER);
        this = (TribeMPStartupScreen *)operator_new(0x6a0);
        uStack_4 = 0;
        if (this != (TribeMPStartupScreen *)0x0) {
          TribeMPStartupScreen::TribeMPStartupScreen(this);
        }
        uStack_4 = 0xffffffff;
        TPanelSystem::setCurrentPanel(&panel_system,s_MP_Startup_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
        lVar1 = 1;
        goto LAB_004920a7;
      }
    }
    else if ((param_2 == param_1->createButton) && (param_3 == 1)) {
      this_00 = (TribeMPCreateDialog *)operator_new(0x4a4);
      uStack_4 = 1;
      if (this_00 != (TribeMPCreateDialog *)0x0) {
        TribeMPCreateDialog::TribeMPCreateDialog(this_00,(TPanel *)param_1);
        lVar1 = 1;
        goto LAB_004920a7;
      }
    }
    else if (param_2 == param_1->refreshButton) {
      if (param_3 == 1) {
        TribeJoinScreen::fillList(param_1);
        lVar1 = 1;
        goto LAB_004920a7;
      }
    }
    else {
      if ((param_2 != param_1->close_button) || (param_3 != 1)) goto LAB_0049208e;
      RGE_Base_Game::close(rge_base_game);
    }
    lVar1 = 1;
  }
LAB_004920a7:
  *unaff_FS_OFFSET = uStack_c;
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_004920bf
// Address: 004920bf
// XREFS: None
// [HELPER] s_Create_Dialog: "Create Dialog"
// [HELPER] s_Default_Age_Of_Empires_MP_Gamena: "Default Age Of Empires MP Gamename"
TDialogPanel * __thiscall FUN_004920bf(TDialogPanel *param_1,TEasy_Panel *param_2)
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  long lVar4;
  char *pcVar5;
  TDrawArea *pTVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 *unaff_FS_OFFSET;
  long lVar10;
  long lVar11;
  int iVar12;
  TEditPanel *pTStack_11c;
  int iStack_118;
  int iStack_114;
  TDialogPanel *pTStack_110;
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ea5b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_110 = param_1;
  TDialogPanel::TDialogPanel(param_1,s_Create_Dialog);
  piVar1 = &param_1[1]._padding_;
  iVar12 = 1;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TribeMPCreateDialog::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *piVar1 = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  lVar4 = TEasy_Panel::get_popup_info_id(param_2);
  pcVar5 = TEasy_Panel::get_popup_info_file(param_2);
  lVar11 = 0xe6;
  lVar10 = 500;
  pTVar6 = TPanel::renderArea((TPanel *)param_2);
  iVar12 = TDialogPanel::setup(param_1,pTVar6,(TPanel *)param_2,lVar10,lVar11,pcVar5,lVar4,iVar12);
  if (((iVar12 != 0) &&
      (iVar12 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),
                           0x25a6,0x14,0x14,0x1cc,0x1e,1,1,1,0), iVar12 != 0)) &&
     (iVar12 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,
                          (TTextPanel **)&param_1[1]._padding_,0x25aa,0x28,0x55,0x1a4,0x14,4,0,1,0),
     iVar12 != 0)) {
    pcVar5 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_MP_Gamena);
    if (pcVar5 == (char *)0x0) {
      acStack_10c[0] = '\0';
    }
    else {
      pcVar5 = TRegistry::RegGetAscii(Regs,1,s_Default_Age_Of_Empires_MP_Gamena);
      uVar7 = 0xffffffff;
      do {
        pcVar9 = pcVar5;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar9 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar9;
      } while (cVar3 != '\0');
      uVar7 = ~uVar7;
      pcVar5 = pcVar9 + -uVar7;
      pcVar9 = acStack_10c;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar9 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar9 = pcVar9 + 1;
      }
    }
    iVar12 = TEasy_Panel::create_edit
                       ((TEasy_Panel *)param_1,(TPanel *)param_1,(TEditPanel **)piVar1,acStack_10c,
                        0x28,FormatText,0x28,0x6e,0x1a4,0x17,0xb,1,0);
    if (iVar12 != 0) {
      iVar12 = TEasy_Panel::create_button
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,
                          (TButtonPanel **)&param_1[1]._padding_,0xfa1,0,0x3c,0xb4,0xb4,0x1e,0,0,0);
      if (iVar12 != 0) {
        piVar2 = &param_1[1]._padding_;
        iVar12 = TEasy_Panel::create_button
                           ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piVar2,0xfa2,0
                            ,0x104,0xb4,0xb4,0x1e,0,0,0);
        if (iVar12 != 0) {
          iVar12 = *piVar2;
          *(undefined4 *)(iVar12 + 0x298) = 0x1b;
          *(undefined4 *)(iVar12 + 0x29c) = 0;
          pTStack_11c = (TEditPanel *)*piVar1;
          iStack_114 = *piVar2;
          iStack_118 = param_1[1]._padding_;
          TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_11c,3);
          TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*piVar1);
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00492303
// Address: 00492303
// XREFS: None
TribeMPCreateDialog * __thiscall FUN_00492303(TribeMPCreateDialog *param_1,byte param_2)
{
  TribeMPCreateDialog::~TribeMPCreateDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049232e
// Address: 0049232e
// XREFS: None
void __fastcall FUN_0049232e(TDialogPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055ea78;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TribeMPCreateDialog::_vftable_;
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

// Function: FUN_004923be
// Address: 004923be
// XREFS: None
// [HELPER] s_Create_Dialog: "Create Dialog"
// [HELPER] s_Default_Age_Of_Empires_MP_Gamena: "Default Age Of Empires MP Gamename"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_____CALLING_CreateMultiplayerGam: "$$$ CALLING CreateMultiplayerGame"
// [HELPER] s_____RETURNED_FROM_CreateMultipla: "$$$ RETURNED FROM CreateMultiplayerGame"
// [HELPER] s_closedpw: "closedpw"
// [HELPER] s_data_closedpw_exe: "data\closedpw.exe"
// [HELPER] s_scr3: "scr3"
long __thiscall
FUN_004923be(TPanel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  char cVar1;
  TDrawArea *pTVar2;
  TDrawSystem *pTVar3;
  TEasy_Panel *this;
  int iVar4;
  long lVar5;
  char *pcVar6;
  uchar *puVar7;
  int iVar8;
  TribeMPSetupScreen *this_00;
  uint uVar9;
  ulong *puVar10;
  undefined4 *unaff_FS_OFFSET;
  bool bVar11;
  ulong uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ea9b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != (TPanel *)0x0) {
    if (((param_2 == (TPanel *)param_1[4].mouse_down_ctrl) && (param_3 == 1)) ||
       ((param_2 == (TPanel *)param_1[4].mouse_down_y && (param_3 == 0)))) {
      iVar4 = TEditPanel::is_blank((TEditPanel *)param_1[4].mouse_down_y);
      if (iVar4 == 0) {
        RGE_Base_Game::disable_input(rge_base_game);
        pcVar6 = TEditPanel::currentLine((TEditPanel *)param_1[4].mouse_down_y);
        uVar9 = 0xffffffff;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        uVar9 = ~uVar9;
        puVar7 = (uchar *)TEditPanel::currentLine((TEditPanel *)param_1[4].mouse_down_y);
        TRegistry::RegSetAscii(Regs,1,s_Default_Age_Of_Empires_MP_Gamena,puVar7,uVar9);
        pcVar6 = TEditPanel::currentLine((TEditPanel *)param_1[4].mouse_down_y);
        TCommunications_Handler::SetGameTitle(comm,pcVar6);
        pTVar2 = param_1->render_area;
        TDebuggingLog::Log(L,(char *)L,s_____CALLING_CreateMultiplayerGam);
        TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
        RGE_Base_Game::draw_window(rge_base_game);
        uStack_1c = (comm->ServiceGUID).Data1;
        uStack_18._0_2_ = (comm->ServiceGUID).Data2;
        uStack_18._2_2_ = (comm->ServiceGUID).Data3;
        uStack_14 = *(undefined4 *)(comm->ServiceGUID).Data4;
        bVar11 = true;
        uStack_10 = *(undefined4 *)((comm->ServiceGUID).Data4 + 4);
        iVar4 = 0x10;
        puVar10 = &uStack_1c;
        pcVar6 = &_DPSPGUID_TCPIP;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar11 = (char)*puVar10 == *pcVar6;
          puVar10 = (ulong *)((int)puVar10 + 1);
          pcVar6 = pcVar6 + 1;
        } while (bVar11);
        if (bVar11) {
          iVar4 = 0x4c3;
        }
        else {
          iVar4 = 0x4c2;
        }
        TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,iVar4,&s_scr3,0xc385);
        RGE_Base_Game::draw_window(rge_base_game);
        WinExec(s_data_closedpw_exe,0);
        pTVar3 = pTVar2->DrawSystem;
        if ((pTVar3->DrawType == '\x02') && (pTVar3->ScreenMode == '\x02')) {
          (**(code **)((int)*pTVar3->DirDraw + 0x28))(pTVar3->DirDraw);
        }
        puVar10 = comm->PlayerStopTurn;
        for (iVar4 = 9; puVar10 = puVar10 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = 0;
        }
        iVar4 = TCommunications_Handler::CreateMultiplayerGame(comm);
        TDebuggingLog::Log(L,(char *)L,s_____RETURNED_FROM_CreateMultipla);
        iVar8 = FindWindowA(s_closedpw,s_closedpw);
        if (iVar8 != 0) {
          SendMessageA(iVar8,0x10,0,0);
        }
        if (iVar4 == 0) {
          this = (TEasy_Panel *)param_1->parent_panel;
          TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
          TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
          TEasy_Panel::popupOKDialog(this,0x25ad,(char *)0x0,0x1c2,100);
          lVar5 = 1;
        }
        else {
          this_00 = (TribeMPSetupScreen *)operator_new(0x890);
          uStack_4 = 0;
          if (this_00 != (TribeMPSetupScreen *)0x0) {
            TribeMPSetupScreen::TribeMPSetupScreen(this_00);
          }
          uStack_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
          TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
          TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
          lVar5 = 1;
        }
      }
      else {
        TPanel::set_curr_child(param_1,(TPanel *)param_1[4].mouse_down_y);
        lVar5 = 1;
      }
      goto LAB_004926c1;
    }
    if (((param_2 == (TPanel *)param_1[4].mouse_down_shift) && (param_3 == 1)) ||
       ((param_2 == (TPanel *)param_1[4].mouse_down_y && (param_3 == 1)))) {
      TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
      lVar5 = 1;
      goto LAB_004926c1;
    }
  }
  lVar5 = TPanel::action(param_1,param_2,param_3,param_4,param_5);
LAB_004926c1:
  *unaff_FS_OFFSET = uStack_c;
  return lVar5;
}

// --------------------------------------------------

// Function: FUN_004926d6
// Address: 004926d6
// XREFS: None
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_credit_d: "credit%d"
// [HELPER] s_data2_list_cr: "data2\list.cr"
// [HELPER] s_scr_cred: "scr_cred"
TEasy_Panel * __fastcall FUN_004926d6(TEasy_Panel *param_1)
{
  TMusic_System *this;
  long lVar1;
  RGE_Font *pRVar2;
  int iVar3;
  TScrollTextPanel *this_00;
  TShape *this_01;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  char acStack_1c [16];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055eace;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Credits_Screen);
  param_1->_padding_ = (int)&TRIBE_Credits_Screen::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 1;
  param_1[1]._padding_ = 1;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 1;
  param_1[1].popup_info_file_name[0xf8] = '\x01';
  param_1[1].popup_info_file_name[0xf9] = '\0';
  param_1[1].popup_info_file_name[0xfa] = '\0';
  param_1[1].popup_info_file_name[0xfb] = '\0';
  param_1[1].popup_info_file_name[0xfc] = '\0';
  param_1[1].popup_info_file_name[0xfd] = '\0';
  param_1[1].popup_info_file_name[0xfe] = '\0';
  param_1[1].popup_info_file_name[0xff] = '\0';
  pcVar6 = param_1[1].popup_info_file_name + 0xdc;
  for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  uStack_4 = 0;
  lVar1 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,s_scr_cred,0xc38b,1);
  if (lVar1 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TEasy_Panel::set_ideal_size(param_1,0x280,0x1e0);
  pRVar2 = RGE_Base_Game::get_font(rge_base_game,4);
  pcVar6 = (char *)0x0;
  iVar5 = __open(s_data2_list_cr,0x8000);
  if (iVar5 != -1) {
    lseek(iVar5,0,2);
    iVar3 = __tell(iVar5);
    pcVar6 = (char *)calloc(iVar3 + 1,0x400);
    if (pcVar6 != (char *)0x0) {
      lseek(iVar5,0,0);
      read(iVar5,pcVar6,iVar3);
    }
    close(iVar5);
  }
  this_00 = (TScrollTextPanel *)operator_new(0x198);
  uStack_4._0_1_ = 1;
  if (this_00 == (TScrollTextPanel *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = TScrollTextPanel::TScrollTextPanel
                      (this_00,(TPanel *)param_1,(TDrawArea *)param_1->_padding_,
                       param_1->_padding_ / 2 + -0xfa,param_1->_padding_ / 2 + -0x96,500,300,0x1e,
                       pRVar2->font,pRVar2->font_wid,pRVar2->font_hgt,pcVar6);
  }
  uStack_4._0_1_ = 0;
  param_1[1]._padding_ = iVar5;
  if (pcVar6 != (char *)0x0) {
    free(pcVar6);
  }
  *(TShape **)(param_1[1].popup_info_file_name + 0xdc) = param_1->background_pic;
  pcVar6 = param_1[1].popup_info_file_name + 0xe0;
  iVar5 = 0xc3eb;
  do {
    sprintf(acStack_1c,s_credit_d,iVar5 + -0xc3e9);
    this_01 = (TShape *)operator_new(0x20);
    uStack_4._0_1_ = 2;
    if (this_01 == (TShape *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = TShape::TShape(this_01,acStack_1c,iVar5);
    }
    *(undefined4 *)pcVar6 = uVar4;
    pcVar6 = pcVar6 + 4;
    uStack_4._0_1_ = 0;
    iVar3 = iVar5 + -0xc3e9;
    iVar5 = iVar5 + 1;
  } while (iVar3 < 7);
  this = rge_base_game->music_system;
  if (((this != (TMusic_System *)0x0) && (this->music_type == '\x01')) && (this->track_count == 0xf)
     ) {
    TMusic_System::play_tracks(this,0xf,0xf,1,0,0);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049294b
// Address: 0049294b
// XREFS: None
TRIBE_Credits_Screen * __thiscall FUN_0049294b(TRIBE_Credits_Screen *param_1,byte param_2)
{
  TRIBE_Credits_Screen::~TRIBE_Credits_Screen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049296e
// Address: 0049296e
// XREFS: None
void __fastcall FUN_0049296e(TScreenPanel *param_1)
{
  TShape *this;
  TMusic_System *this_00;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055eae8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Credits_Screen::_vftable_;
  uStack_4 = 0;
  puVar2 = (undefined4 *)&param_1[1].field_0x41c;
  iVar1 = 7;
  do {
    this = (TShape *)*puVar2;
    if (this != (TShape *)0x0) {
      TShape::~TShape(this);
      operator_delete(this);
      *puVar2 = 0;
    }
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)&param_1->field_0x204 = 0;
  if (*(undefined4 **)(param_1 + 1) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 1))(1);
    *(undefined4 *)(param_1 + 1) = 0;
  }
  this_00 = rge_base_game->music_system;
  if (((this_00 != (TMusic_System *)0x0) && (this_00->music_type == '\x01')) &&
     (this_00->track_count == 0xf)) {
    TMusic_System::play_tracks(this_00,5,0xe,1,0,0);
  }
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00492a4d
// Address: 00492a4d
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
long __fastcall FUN_00492a4d(TRIBE_Credits_Screen *param_1)
{
  ScreenMode SVar1;
  TDrawArea *this;
  TDrawSystem *pTVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  
  SVar1 = param_1->mode;
  if (SVar1 == ModeNone) {
    if (param_1->last_picture_time != 0) {
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0xf5);
      if (9999 < uVar3 - param_1->last_picture_time) {
        this = (TDrawArea *)param_1->_padding_;
        pTVar2 = this->DrawSystem;
        if ((pTVar2->ScreenMode == '\x02') || (pTVar2->DrawType == '\x01')) {
          iVar5 = param_1->_padding_;
          param_1->mode = ModeFadeOut;
          (param_1->color).peRed = '\0';
          (param_1->color).peGreen = '\0';
          (param_1->color).peBlue = '\0';
          if (iVar5 == 0) {
            TDrawArea::GetPalette(this,param_1->color_table);
          }
          else {
            GetPaletteEntries(iVar5,0,0x100,param_1->color_table);
          }
          RGE_fade_palette_start
                    ((TDrawArea *)param_1->_padding_,param_1->color,0.5,'\x01',
                     (tagPALETTEENTRY *)0x0,0xff,-1);
        }
        else {
          param_1->mode = ModePause;
        }
      }
      goto LAB_00492c91;
    }
    iVar5 = 0xf1;
  }
  else {
    if (SVar1 == ModeFadeOut) {
      iVar5 = RGE_fade_palette_step();
      if (iVar5 != 0) {
        iVar5 = param_1->_padding_;
        param_1->mode = ModePause;
        param_1->last_pause_time = 0;
        (**(code **)(iVar5 + 0x20))(1);
        (**(code **)(iVar5 + 0x54))();
        TDrawSystem::Paint(*(TDrawSystem **)param_1->_padding_,(tagRECT *)0x0);
      }
      goto LAB_00492c91;
    }
    if (SVar1 == ModePause) {
      if (param_1->last_pause_time == 0) {
        uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x11a);
        param_1->last_pause_time = uVar3;
        goto LAB_00492c91;
      }
      debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x11e);
      iVar5 = param_1->picture_set + 1;
      param_1->mode = ModeFadeIn;
      param_1->picture_set = iVar5;
      if (7 < iVar5) {
        param_1->picture_set = 1;
      }
      iVar5 = param_1->_padding_;
      param_1->_padding_ = (int)param_1->back_pics[param_1->picture_set + -1];
      (**(code **)(iVar5 + 0x20))(1);
      (**(code **)(iVar5 + 0x54))();
      TDrawSystem::Paint(*(TDrawSystem **)param_1->_padding_,(tagRECT *)0x0);
      pTVar2 = ((TDrawArea *)param_1->_padding_)->DrawSystem;
      if ((pTVar2->ScreenMode == '\x02') || (pTVar2->DrawType == '\x01')) {
        RGE_fade_palette_start
                  ((TDrawArea *)param_1->_padding_,param_1->color,0.5,'\x02',param_1->color_table,
                   0xff,-1);
        goto LAB_00492c91;
      }
      param_1->mode = ModeNone;
      iVar5 = 0x138;
    }
    else {
      if (SVar1 != ModeFadeIn) goto LAB_00492c91;
      iVar5 = RGE_fade_palette_step();
      if (iVar5 == 0) goto LAB_00492c91;
      param_1->mode = ModeNone;
      iVar5 = 0x142;
    }
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,iVar5);
  param_1->last_picture_time = uVar3;
LAB_00492c91:
  if (param_1->text_done != 0) {
    TRIBE_Credits_Screen::close_screen(param_1);
    return 1;
  }
  lVar4 = TPanel::handle_idle((TPanel *)param_1);
  return lVar4;
}

// --------------------------------------------------

// Function: FUN_00492cb2
// Address: 00492cb2
// XREFS: None
void __fastcall FUN_00492cb2(TScreenPanel *param_1)
{
  TDrawSystem *pTVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(int *)&param_1[1].field_0x14 == 4) {
    pTVar1 = (*(TDrawArea **)&param_1->field_0x20)->DrawSystem;
    if ((pTVar1->ScreenMode == '\x02') || (pTVar1->DrawType == '\x01')) {
      TDrawArea::Clear(*(TDrawArea **)&param_1->field_0x20,(tagRECT *)&param_1->field_0x24,0);
      return;
    }
  }
  if (*(int *)&param_1[1].field_0x438 != 0) {
    iVar2 = 7;
    puVar3 = (undefined4 *)&param_1[1].field_0x41c;
    do {
      *(undefined4 *)&param_1->field_0x204 = *puVar3;
      TScreenPanel::draw(param_1);
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined4 *)&param_1[1].field_0x438 = 0;
    *(undefined4 *)&param_1->field_0x204 = *(undefined4 *)&param_1[1].field_0x41c;
  }
  TScreenPanel::draw(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00492d41
// Address: 00492d41
// XREFS: None
undefined4 __thiscall FUN_00492d41(TRIBE_Credits_Screen *param_1,int param_2)
{
  if ((param_2 != 0xd) && (param_2 != 0x1b)) {
    return 0;
  }
  TRIBE_Credits_Screen::close_screen(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00492dab
// Address: 00492dab
// XREFS: None
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Main_Menu: "Main Menu"
void FUN_00492dab(void)
{
  TPanel *pTVar1;
  int iVar2;
  TRIBE_Screen_Main_Menu *this;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055eb0b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = TPanelSystem::panel(&panel_system,s_Game_Screen);
  if (pTVar1 == (TPanel *)0x0) {
    this = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
    uStack_4 = 0;
    if (this != (TRIBE_Screen_Main_Menu *)0x0) {
      TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this);
    }
    uStack_4 = 0xffffffff;
    pcVar3 = s_Main_Menu;
  }
  else {
    iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
      RGE_Base_Game::set_paused(rge_base_game,0,0);
    }
    pcVar3 = s_Game_Screen;
  }
  TPanelSystem::setCurrentPanel(&panel_system,pcVar3,0);
  TPanelSystem::destroyPanel(&panel_system,s_Credits_Screen);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00492e66
// Address: 00492e66
// XREFS: None
TScrollTextPanel * __thiscall
FUN_00492e66(TScrollTextPanel *param_1,TPanel *param_2,TDrawArea *param_3,long param_4,long param_5,
            long param_6,long param_7,int param_8,void *param_9,long param_10,long param_11,
            char *param_12)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055eb28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TTextPanel::TTextPanel((TTextPanel *)param_1);
  param_1->speed = param_8;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TScrollTextPanel::_vftable_;
  param_1->scroll = 0;
  param_1->last_time = 0;
  param_1->done = 0;
  lVar1 = TTextPanel::setup((TTextPanel *)param_1,param_3,param_2,param_4,param_5,param_6,param_7,
                            param_9,param_10,param_11,(char *)0x0,0,'\0',0,'\0',0,(char *)0x0);
  if (lVar1 != 0) {
    TTextPanel::set_alignment((TTextPanel *)param_1,AlignTop,AlignCenter);
    TTextPanel::set_word_wrap((TTextPanel *)param_1,1);
    TScrollTextPanel::set_text(param_1,param_12);
    TTextPanel::set_text_color((TTextPanel *)param_1,param_1->_padding_,param_1->_padding_);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00492f43
// Address: 00492f43
// XREFS: None
TScrollTextPanel * __thiscall FUN_00492f43(TScrollTextPanel *param_1,byte param_2)
{
  TScrollTextPanel::~TScrollTextPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00492f6e
// Address: 00492f6e
// XREFS: None
void __fastcall FUN_00492f6e(TTextPanel *param_1)
{
  param_1->_padding_ = (int)&TScrollTextPanel::_vftable_;
  TTextPanel::~TTextPanel(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00492f7b
// Address: 00492f7b
// XREFS: None
void __thiscall FUN_00492f7b(TTextPanel *param_1,char *param_2)
{
  TTextPanel::set_text(param_1,param_2);
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00492fa5
// Address: 00492fa5
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
void __fastcall FUN_00492fa5(TPanel *param_1)
{
  int iVar1;
  ulong uVar2;
  int iVar3;
  
  if (param_1[1].render_rect.bottom == 0) {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x1dc);
    param_1[1].render_rect.bottom = uVar2;
  }
  else {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x1df);
    iVar3 = __ftol();
    if (0 < iVar3) {
      iVar1 = param_1->_padding_;
      param_1[1].render_rect.right = param_1[1].render_rect.right + iVar3;
      (**(code **)(iVar1 + 0x20))(1);
      param_1[1].render_rect.bottom = uVar2;
    }
  }
  if ((param_1[1].top_border != 0) && (param_1->parent_panel != (TPanel *)0x0)) {
    (**(code **)(param_1->parent_panel->_padding_ + 0xb4))(param_1,1,0,0);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00493068
// Address: 00493068
// XREFS: None
// [HELPER] s_scr_cred__draw: "scr_cred::draw"
void __fastcall FUN_00493068(TScrollTextPanel *param_1)
{
  void *pvVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iStack_8;
  
  param_1->_padding_ = 0;
  if (((param_1->_padding_ != 0) && (param_1->_padding_ != 0)) && (param_1->_padding_ != 0)) {
    TTextPanel::draw_background((TTextPanel *)param_1);
    iVar4 = param_1->_padding_;
    (**(code **)(iVar4 + 0x28))(0);
    pvVar1 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_scr_cred__draw);
    if (pvVar1 != (void *)0x0) {
      SelectClipRgn(pvVar1,param_1->_padding_);
      uVar2 = SelectObject(pvVar1,param_1->_padding_);
      SetBkMode(pvVar1,1);
      sVar3 = 0;
      if (0 < (short)param_1->_padding_) {
        do {
          TScrollTextPanel::draw_scrolled_line
                    (param_1,pvVar1,sVar3,sVar3,param_1->_padding_,param_1->_padding_);
          sVar3 = sVar3 + 1;
        } while (sVar3 < (short)param_1->_padding_);
      }
      SelectObject(pvVar1,uVar2);
      SelectClipRgn(pvVar1,0);
      TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_scr_cred__draw);
      iVar4 = iStack_8;
    }
    TTextPanel::draw_border((TTextPanel *)param_1);
    (**(code **)(iVar4 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00493154
// Address: 00493154
// XREFS: None
void __thiscall
FUN_00493154(TTextPanel *param_1,void *param_2,short param_3,short param_4,undefined4 param_5,
            undefined4 param_6)
{
  char cVar1;
  Style SVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  short sStack_24;
  short sStack_1c;
  tagRECT tStack_10;
  
  iVar6 = (int)param_4;
  sStack_24 = 0;
  sStack_1c = 0;
  pcVar3 = TTextPanel::get_text(param_1,iVar6);
  pcVar4 = TTextPanel::get_text2(param_1,iVar6);
  if (pcVar3 == (char *)0x0) {
    if (pcVar4 == (char *)0x0) {
      return;
    }
  }
  else {
    iVar5 = -1;
    pcVar7 = pcVar3;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    sStack_24 = ~(ushort)iVar5 - 1;
  }
  if (pcVar4 != (char *)0x0) {
    iVar5 = -1;
    pcVar7 = pcVar4;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    sStack_1c = ~(ushort)iVar5 - 1;
  }
  TTextPanel::calc_line_pos(param_1,param_2,param_3,param_4,&tStack_10,(long *)0x0);
  _param_4 = tStack_10.left;
  if ((param_1->horz_align != AlignCenter) && (param_1->horz_align != AlignWordwrap)) {
    _param_4 = tStack_10.left + 5;
  }
  iVar5 = param_1->second_column_pos + _param_4;
  iVar8 = (param_1->_padding_ - param_1[1]._padding_) + tStack_10.top;
  if ((iVar6 == param_1->num_lines + -1) && (param_1->font_hgt + iVar8 < param_1->_padding_)) {
    param_1[1]._padding_ = 1;
  }
  if (param_1->clip_rgn2 != (void *)0x0) {
    SelectClipRgn(param_2,param_1->clip_rgn2);
  }
  SVar2 = param_1->text_style;
  if (SVar2 == NormalStyle) {
    SetTextColor(param_2,param_5);
  }
  else if (SVar2 == BeveledStyle) {
    SetTextColor(param_2,param_5);
    if (pcVar3 != (char *)0x0) {
      TextOutA(param_2,_param_4 + -1,iVar8 + 1,pcVar3,(int)sStack_24);
    }
    SetTextColor(param_2,param_6);
  }
  else {
    if (SVar2 != ChiseledStyle) goto LAB_00493317;
    SetTextColor(param_2,param_6);
    if (pcVar3 != (char *)0x0) {
      TextOutA(param_2,_param_4 + -1,iVar8 + 1,pcVar3,(int)sStack_24);
    }
    SetTextColor(param_2,param_5);
  }
  if (pcVar3 != (char *)0x0) {
    TextOutA(param_2,_param_4,iVar8,pcVar3,(int)sStack_24);
  }
LAB_00493317:
  if (pcVar4 != (char *)0x0) {
    if (param_1->clip_rgn2 != (void *)0x0) {
      SelectClipRgn(param_2,param_1->_padding_);
    }
    SVar2 = param_1->text_style;
    if (SVar2 == NormalStyle) {
      SetTextColor(param_2,param_5);
      TextOutA(param_2,iVar5,iVar8,pcVar4,(int)sStack_1c);
    }
    else {
      if (SVar2 == BeveledStyle) {
        SetTextColor(param_2,param_5);
        TextOutA(param_2,iVar5 + -1,iVar8 + 1,pcVar4,(int)sStack_1c);
        SetTextColor(param_2,param_6);
        TextOutA(param_2,iVar5,iVar8,pcVar4,(int)sStack_1c);
        return;
      }
      if (SVar2 == ChiseledStyle) {
        SetTextColor(param_2,param_6);
        TextOutA(param_2,iVar5 + -1,iVar8 + 1,pcVar4,(int)sStack_1c);
        SetTextColor(param_2,param_5);
        TextOutA(param_2,iVar5,iVar8,pcVar4,(int)sStack_1c);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00493414
// Address: 00493414
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
void FUN_00493414(TDrawArea *param_1,undefined4 param_2,float param_3,char param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  DAT_0086b2a8 = param_2;
  UNK_0086b28c._4_4_ = param_3;
  DAT_0086b2a4 = param_4;
  DAT_0086b298 = param_6;
  DAT_0086b29c = param_7;
  DAT_0086bab0 = param_1;
  iVar1 = 0;
  do {
    (&DAT_0086b2b0)[iVar1] = 0;
    (&DAT_0086b6b0)[iVar1] = 0;
    (&DAT_0086b2b2)[iVar1] = 0;
    (&DAT_0086b6b2)[iVar1] = 0;
    (&DAT_0086b2b1)[iVar1] = 0;
    (&DAT_0086b6b1)[iVar1] = 0;
    (&DAT_0086b2b3)[iVar1] = 0;
    (&DAT_0086b6b3)[iVar1] = 0;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x400);
  if (param_5 == 0) {
    TDrawArea::GetPalette(param_1,(tagPALETTEENTRY *)&DAT_0086b2b0);
  }
  else {
    puVar4 = &DAT_0086b2b0;
    puVar2 = (undefined1 *)(param_5 + 1);
    do {
      puVar3 = puVar2 + 4;
      *puVar4 = puVar2[-1];
      puVar3[0x86b2ad - param_5] = puVar2[1];
      puVar3[(int)&DAT_0086b2ac - param_5] = *puVar2;
      puVar3[0x86b2ae - param_5] = puVar2[2];
      puVar4 = puVar4 + 4;
      puVar2 = puVar3;
    } while ((int)puVar4 < 0x86b6b0);
  }
  DAT_0086b294 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2b5);
  DAT_0086b2ac = UNK_0086b28c._4_4_ * UNK_0086b28c._4_4_;
  DAT_0086b2a0 = -(uint)(DAT_0086b2a4 != '\x01') & 100;
  return;
}

// --------------------------------------------------

// Function: RGE_fade_palette_start
// Address: 00493420
// XREFS: handle_idle
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
/* void __cdecl RGE_fade_palette_start(class TDrawArea *,struct tagPALETTEENTRY,float,unsigned
   char,struct tagPALETTEENTRY *,int,int) */

void __cdecl
RGE_fade_palette_start
          (TDrawArea *param_1,tagPALETTEENTRY param_2,float param_3,uchar param_4,
          tagPALETTEENTRY *param_5,int param_6,int param_7)
{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  DAT_0086b2a8 = param_2;
  UNK_0086b28c._4_4_ = param_3;
  DAT_0086b2a4 = param_4;
  DAT_0086b298 = param_6;
  DAT_0086b29c = param_7;
  DAT_0086bab0 = param_1;
  iVar1 = 0;
  do {
    (&DAT_0086b2b0)[iVar1] = 0;
    (&DAT_0086b6b0)[iVar1] = 0;
    (&DAT_0086b2b2)[iVar1] = 0;
    (&DAT_0086b6b2)[iVar1] = 0;
    (&DAT_0086b2b1)[iVar1] = 0;
    (&DAT_0086b6b1)[iVar1] = 0;
    (&DAT_0086b2b3)[iVar1] = 0;
    (&DAT_0086b6b3)[iVar1] = 0;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x400);
  if (param_5 == (tagPALETTEENTRY *)0x0) {
    TDrawArea::GetPalette(param_1,(tagPALETTEENTRY *)&DAT_0086b2b0);
  }
  else {
    puVar4 = &DAT_0086b2b0;
    puVar2 = &param_5->peGreen;
    do {
      puVar3 = puVar2 + 4;
      *puVar4 = ((tagPALETTEENTRY *)(puVar2 + -1))->peRed;
      puVar3[0x86b2ad - (int)param_5] = puVar2[1];
      puVar3[(int)&DAT_0086b2ac - (int)param_5] = *puVar2;
      puVar3[0x86b2ae - (int)param_5] = puVar2[2];
      puVar4 = puVar4 + 4;
      puVar2 = puVar3;
    } while ((int)puVar4 < 0x86b6b0);
  }
  DAT_0086b294 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2b5);
  DAT_0086b2ac = UNK_0086b28c._4_4_ * UNK_0086b28c._4_4_;
  DAT_0086b2a0 = -(uint)(DAT_0086b2a4 != '\x01') & 100;
  return;
}

// --------------------------------------------------

// Function: FUN_00493532
// Address: 00493532
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00493532(void)
{
  float fVar1;
  undefined1 uVar2;
  ulong uVar3;
  
  uVar2 = 0;
  if (DAT_0086b2a4 == '\x01') {
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2c8);
    fVar1 = (float)(int)(uVar3 - DAT_0086b294) * _DAT_00572968;
    if (((UNK_0086b28c._4_4_ <= (float)_DAT_00572970) || (UNK_0086b28c._4_4_ < fVar1)) ||
       (fVar1 < _DAT_00572978)) {
      DAT_0086b2a0 = 100;
    }
    else {
      DAT_0086b2a0 = __ftol();
    }
    if (DAT_0086b2a0 < 100) goto LAB_00493687;
    DAT_0086b2a0 = 100;
  }
  else {
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2dc);
    fVar1 = UNK_0086b28c._4_4_ - (float)(int)(uVar3 - DAT_0086b294) * _DAT_00572968;
    if (((UNK_0086b28c._4_4_ <= (float)_DAT_00572970) || (UNK_0086b28c._4_4_ < fVar1)) ||
       (fVar1 < _DAT_00572978)) {
      DAT_0086b2a0 = 0;
    }
    else {
      DAT_0086b2a0 = __ftol();
    }
    if (0 < DAT_0086b2a0) goto LAB_00493687;
    DAT_0086b2a0 = 0;
  }
  uVar2 = 1;
LAB_00493687:
  RGE_translate_palette
            ((tagPALETTEENTRY *)&DAT_0086b2b0,(tagPALETTEENTRY *)&DAT_0086b6b0,DAT_0086b2a8,
             DAT_0086b2a0,DAT_0086b298,DAT_0086b29c);
  TDrawArea::SetPalette(DAT_0086bab0,(tagPALETTEENTRY *)&DAT_0086b6b0);
  return uVar2;
}

// --------------------------------------------------

// Function: RGE_fade_palette_step
// Address: 00493540
// XREFS: handle_idle
// [HELPER] s_C__msdev_work_age1_x1_scr_cred_c: "C:\msdev\work\age1_x1\scr_cred.cpp"
/* WARNING: Variable defined which should be unmapped: delta_time */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* int __cdecl RGE_fade_palette_step(void) */

int __cdecl RGE_fade_palette_step(void)
{
  float fVar1;
  ulong uVar2;
  float delta_time;
  uchar done;
  int local_4;
  
  local_4 = 0;
  if (DAT_0086b2a4 == '\x01') {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2c8);
    fVar1 = (float)(int)(uVar2 - DAT_0086b294) * _DAT_00572968;
    if (((UNK_0086b28c._4_4_ <= (float)_DAT_00572970) || (UNK_0086b28c._4_4_ < fVar1)) ||
       (fVar1 < _DAT_00572978)) {
      DAT_0086b2a0 = 100;
    }
    else {
      DAT_0086b2a0 = __ftol();
    }
    if (DAT_0086b2a0 < 100) goto LAB_00493687;
    DAT_0086b2a0 = 100;
  }
  else {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_cred_c,0x2dc);
    fVar1 = UNK_0086b28c._4_4_ - (float)(int)(uVar2 - DAT_0086b294) * _DAT_00572968;
    if (((UNK_0086b28c._4_4_ <= (float)_DAT_00572970) || (UNK_0086b28c._4_4_ < fVar1)) ||
       (fVar1 < _DAT_00572978)) {
      DAT_0086b2a0 = 0;
    }
    else {
      DAT_0086b2a0 = __ftol();
    }
    if (0 < DAT_0086b2a0) goto LAB_00493687;
    DAT_0086b2a0 = 0;
  }
  local_4 = 1;
LAB_00493687:
  RGE_translate_palette
            ((tagPALETTEENTRY *)&DAT_0086b2b0,(tagPALETTEENTRY *)&DAT_0086b6b0,DAT_0086b2a8,
             DAT_0086b2a0,DAT_0086b298,DAT_0086b29c);
  TDrawArea::SetPalette(DAT_0086bab0,(tagPALETTEENTRY *)&DAT_0086b6b0);
  return local_4;
}

// --------------------------------------------------

// Function: FUN_004936cb
// Address: 004936cb
// XREFS: None
// [HELPER] s_End_Screen: "End Screen"
// [HELPER] s_OK: "OK"
// [HELPER] s_bgA1024: "bgA1024"
// [HELPER] s_bgA640: "bgA640"
// [HELPER] s_bgA800: "bgA800"
TScreenPanel * __thiscall
FUN_004936cb(TScreenPanel *param_1,TButtonPanel *param_2,undefined4 param_3,undefined4 param_4)
{
  char cVar1;
  int iVar2;
  long lVar3;
  TPicturePanel *pTVar4;
  RGE_Font *pRVar5;
  TTextPanel *pTVar6;
  int iVar7;
  TDigital *pTVar8;
  TButtonPanel *this;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  TTextPanel *pTStack_20;
  char acStack_18 [12];
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055eb74;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel(param_1,s_End_Screen);
  *(undefined ***)param_1 = &TribeEndScreen::_vftable_;
  iStack_4 = 0;
  lVar3 = TScreenPanel::setup(param_1,rge_base_game->draw_area,(char *)0x0,0,1);
  if (lVar3 == 0) {
    *(undefined4 *)&param_1->field_0xd8 = 1;
  }
  else {
    iVar7 = *(int *)(*(int *)&param_1->field_0x20 + 0x18);
    if (iVar7 < 800) {
      pcVar11 = &s_bgA640;
    }
    else {
      pcVar11 = s_bgA800;
      if (0x3ff < iVar7) {
        pcVar11 = s_bgA1024;
      }
    }
    uVar9 = 0xffffffff;
    do {
      pcVar12 = pcVar11;
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      pcVar12 = pcVar11 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar12;
    } while (cVar1 != '\0');
    uVar9 = ~uVar9;
    pcVar11 = pcVar12 + -uVar9;
    pcVar12 = acStack_18;
    for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
      pcVar11 = pcVar11 + 4;
      pcVar12 = pcVar12 + 4;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar12 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar12 = pcVar12 + 1;
    }
    pTVar4 = (TPicturePanel *)operator_new(0x11c);
    iStack_4._0_1_ = 1;
    if (pTVar4 == (TPicturePanel *)0x0) {
      pTVar4 = (TPicturePanel *)0x0;
    }
    else {
      pTVar4 = (TPicturePanel *)TPicturePanel::TPicturePanel(pTVar4);
    }
    iStack_4._0_1_ = 0;
    *(TPicturePanel **)(param_1 + 1) = pTVar4;
    if (pTVar4 == (TPicturePanel *)0x0) {
      *(undefined4 *)&param_1->field_0xd8 = 1;
    }
    else {
      lVar3 = TPicturePanel::setup
                        (pTVar4,*(TDrawArea **)&param_1->field_0x20,(TPanel *)param_1,0,0,0,0,
                         acStack_18,-1,0,1);
      if (lVar3 == 0) {
        *(undefined4 *)&param_1->field_0xd8 = 1;
      }
      else {
        iVar7 = (*(int *)&param_1->field_0x18 * 0x1e0) / 0x1e0;
        iVar2 = (*(int *)&param_1->field_0x14 * 0x280) / 0x280;
        (**(code **)(**(int **)(param_1 + 1) + 0x18))(2,0,0,0,0,iVar2,iVar2,iVar7,iVar7,0,0,0,0);
        pRVar5 = RGE_Base_Game::get_font(rge_base_game,1);
        pTVar6 = (TTextPanel *)operator_new(0x188);
        iStack_4._0_1_ = 2;
        if (pTVar6 == (TTextPanel *)0x0) {
          pTStack_20 = (TTextPanel *)0x0;
        }
        else {
          pTStack_20 = (TTextPanel *)TTextPanel::TTextPanel(pTVar6);
        }
        iStack_4._0_1_ = 0;
        *(TTextPanel **)&param_1[1].field_0x4 = pTStack_20;
        if (pTStack_20 == (TTextPanel *)0x0) {
          *(undefined4 *)&param_1->field_0xd8 = 1;
        }
        else {
          TTextPanel::setup(pTStack_20,*(TDrawArea **)&param_1->field_0x20,*(TPanel **)(param_1 + 1)
                            ,(*(int *)&param_1->field_0x14 * 0x14) / 0x280,
                            (*(int *)&param_1->field_0x18 * 0x14) / 0x1e0,
                            (*(int *)&param_1->field_0x14 * 600) / 0x280,
                            (*(int *)&param_1->field_0x18 * 0x1e) / 0x1e0,pRVar5->font,
                            pRVar5->font_wid,pRVar5->font_hgt,(char *)0x0,0,'\0',0,'\0',0,
                            (char *)param_2);
          pTVar6 = (TTextPanel *)operator_new(0x188);
          iStack_4._0_1_ = 3;
          if (pTVar6 == (TTextPanel *)0x0) {
            iVar7 = 0;
          }
          else {
            iVar7 = TTextPanel::TTextPanel(pTVar6);
          }
          iStack_4._0_1_ = 0;
          *(int *)&param_1[1].field_0x8 = iVar7;
          if (iVar7 == 0) {
            *(undefined4 *)&param_1->field_0xd8 = 1;
          }
          else {
            pRVar5 = RGE_Base_Game::get_font(rge_base_game,0xb);
            TTextPanel::setup(*(TTextPanel **)&param_1[1].field_0x8,
                              *(TDrawArea **)&param_1->field_0x20,*(TPanel **)(param_1 + 1),
                              (*(int *)&param_1->field_0x14 * 0x14) / 0x280,
                              (*(int *)&param_1->field_0x18 * 0x46) / 0x1e0,
                              (*(int *)&param_1->field_0x14 * 600) / 0x280,
                              (*(int *)&param_1->field_0x18 * 0x154) / 0x1e0,pRVar5->font,
                              pRVar5->font_wid,pRVar5->font_hgt,(char *)0x0,0,'\0',0,'\0',0,
                              (char *)0x0);
            (**(code **)(**(int **)&param_1[1].field_0x8 + 0xe0))(param_3,param_4);
            TTextPanel::set_alignment(*(TTextPanel **)&param_1[1].field_0x8,AlignCenter,AlignCenter)
            ;
            TTextPanel::scroll(*(TTextPanel **)&param_1[1].field_0x8,'\x06',0,1);
            pTVar8 = RGE_Base_Game::get_sound(rge_base_game,0);
            pRVar5 = RGE_Base_Game::get_font(rge_base_game,0);
            this = (TButtonPanel *)operator_new(0x2b8);
            iStack_4._0_1_ = 4;
            if (this == (TButtonPanel *)0x0) {
              param_2 = (TButtonPanel *)0x0;
            }
            else {
              param_2 = (TButtonPanel *)TButtonPanel::TButtonPanel(this);
            }
            iStack_4 = (uint)iStack_4._1_3_ << 8;
            *(TButtonPanel **)&param_1[1].field_0xc = param_2;
            if (param_2 == (TButtonPanel *)0x0) {
              *(undefined4 *)&param_1->field_0xd8 = 1;
            }
            else {
              TButtonPanel::setup(param_2,*(TDrawArea **)&param_1->field_0x20,
                                  *(TPanel **)(param_1 + 1),
                                  (*(int *)&param_1->field_0x14 * 0xaa) / 0x280,
                                  (*(int *)&param_1->field_0x18 * 0x1ae) / 0x1e0,
                                  (*(int *)&param_1->field_0x14 * 300) / 0x280,
                                  (*(int *)&param_1->field_0x18 * 0x28) / 0x1e0,DrawTextA,pTVar8,
                                  NotifyAction,0);
              TButtonPanel::set_text_info
                        (*(TButtonPanel **)&param_1[1].field_0xc,s_OK,pRVar5->font,pRVar5->font_wid,
                         pRVar5->font_hgt,-1,-1);
              TPanel::set_curr_child((TPanel *)param_1,*(TPanel **)(param_1 + 1));
              TPanel::set_curr_child(*(TPanel **)(param_1 + 1),*(TPanel **)&param_1[1].field_0x8);
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

// Function: FUN_00493bda
// Address: 00493bda
// XREFS: None
TribeEndScreen * __thiscall FUN_00493bda(TribeEndScreen *param_1,byte param_2)
{
  TribeEndScreen::~TribeEndScreen(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00493bfe
// Address: 00493bfe
// XREFS: None
void __fastcall FUN_00493bfe(TScreenPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055eb88;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeEndScreen::_vftable_;
  uStack_4 = 0;
  if (*(undefined4 **)&param_1[1].field_0x4 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x4)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0x8 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x8)(1);
  }
  if (*(undefined4 **)&param_1[1].field_0xc != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xc)(1);
  }
  if (*(undefined4 **)(param_1 + 1) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 1))(1);
  }
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00493c8a
// Address: 00493c8a
// XREFS: None
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_End_Screen: "End Screen"
long __thiscall
FUN_00493c8a(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  TribeAchievementsScreen *this;
  char *pcVar1;
  long lVar2;
  undefined4 *unaff_FS_OFFSET;
  int iVar3;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ebab;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_2 != (TPanel *)0x0) && (param_3 == 1)) {
    this = (TribeAchievementsScreen *)operator_new(0x5f8);
    uStack_4 = 0;
    if (this != (TribeAchievementsScreen *)0x0) {
      iVar3 = 1;
      pcVar1 = TPanel::get_string((TPanel *)param_1,0x269e);
      TribeAchievementsScreen::TribeAchievementsScreen(this,pcVar1,iVar3);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Achievements_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_End_Screen);
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
  lVar2 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  *unaff_FS_OFFSET = uStack_c;
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_00493d55
// Address: 00493d55
// XREFS: None
// [HELPER] die_die_die: " "
// [HELPER] do_color_log: " "
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_scr_game_c: "C:\msdev\work\age1_x1\scr_game.cpp"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_PAUSE: "PAUSE"
// [HELPER] s_bordline: "bordline"
// [HELPER] s_btnbldg_d_shp: "btnbldg%d.shp"
// [HELPER] s_btncmd_shp: "btncmd.shp"
// [HELPER] s_btntech_shp: "btntech.shp"
// [HELPER] s_btnunit_shp: "btnunit.shp"
// [HELPER] s_map_bmp: "map.bmp"
// [HELPER] s_scr6: "scr6"
TRIBE_Screen_Game * __fastcall FUN_00493d55(TRIBE_Screen_Game *param_1)
{
  TTextPanel **ppTVar1;
  TScrollBarPanel **ppTVar2;
  uchar uVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  TShape *pTVar7;
  int iVar8;
  RGE_Main_View *this;
  RGE_Player *pRVar9;
  TRIBE_Diamond_Map_View *this_00;
  RGE_Diamond_Map *this_01;
  RGE_Font *pRVar10;
  TRIBE_Panel_Inven *this_02;
  TRIBE_Player *pTVar11;
  TPanel *pTVar12;
  TRIBE_Panel_Object *this_03;
  TDigital *pTVar13;
  TRIBE_Panel_Button *this_04;
  TButtonPanel *this_05;
  TMessagePanel *pTVar14;
  int *piVar15;
  TRIBE_Panel_Time *pTVar16;
  TRIBE_Panel_Pop *this_06;
  TTextPanel *pTVar17;
  int *piVar18;
  RGE_Panel_Tool_Box *this_07;
  int iVar19;
  undefined4 *puVar20;
  uint uVar21;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar22;
  undefined4 uVar23;
  int iStack_21c;
  int iStack_214;
  char acStack_20c [512];
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ed29;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TScreenPanel::TScreenPanel((TScreenPanel *)param_1,s_Game_Screen);
  *(undefined ***)param_1 = &TRIBE_Screen_Game::_vftable_;
  displayPathingFlags = 0;
  allow_user_commands = (int)(do_fixed_update == 0);
  die_die_die = '\0';
  *(undefined4 *)((int)&param_1->game_screen_pic + 3) = 0;
  *(undefined4 *)((int)&param_1->button_border1_pic + 3) = 0;
  *(undefined4 *)((int)&param_1->button_other_pic + 3) = 0;
  *(undefined4 *)((int)&param_1->button_border2_pic + 3) = 0;
  *(undefined4 *)((int)&param_1->button_border3_pic + 3) = 0;
  *(undefined4 *)((int)&param_1->button_cmd_pic + 3) = 0;
  *(undefined4 *)((int)&param_1->button_tech_pic + 3) = 0;
  *(undefined4 *)((int)&param_1->button_unit_pic + 3) = 0;
  *(undefined4 *)((int)&param_1->more_cancel_pic + 3) = 0;
  *(undefined4 *)((int)param_1->button_bldg_pics + 3) = 0;
  *(undefined4 *)((int)param_1->button_bldg_pics + 7) = 0;
  uStack_4 = 0;
  *(undefined4 *)((int)param_1->button_bldg_pics + 0xb) = 0;
  *(undefined4 *)((int)param_1->button_bldg_pics + 0xf) = 0;
  *(undefined4 *)((int)param_1->button_bldg_pics + 0x13) = 0;
  *(undefined4 *)((int)&param_1->main_view + 3) = 0;
  *(undefined4 *)((int)&param_1->map_view + 3) = 0;
  *(undefined4 *)((int)&param_1->inven_panel + 3) = 0;
  *(undefined4 *)((int)&param_1->object_panel + 3) = 0;
  *(undefined4 *)((int)&param_1->age_panel + 3) = 0;
  *(undefined4 *)((int)&param_1->fps_panel + 3) = 0;
  puVar20 = (undefined4 *)((int)param_1->score_panel + 3);
  for (iVar19 = 8; iVar19 != 0; iVar19 = iVar19 + -1) {
    *puVar20 = 0;
    puVar20 = puVar20 + 1;
  }
  *(undefined4 *)((int)&param_1->log_text + 3) = 0;
  *(undefined4 *)((int)&param_1->log_scrollbar + 3) = 0;
  puVar20 = (undefined4 *)((int)param_1->button_panel + 3);
  for (iVar19 = 0x11; iVar19 != 0; iVar19 = iVar19 + -1) {
    *puVar20 = 0;
    puVar20 = puVar20 + 1;
  }
  *(undefined4 *)((int)&param_1->text_line_panel + 3) = 0;
  *(undefined4 *)((int)&param_1->quit_message_panel + 3) = 0;
  *(undefined4 *)((int)&param_1->time_panel + 3) = 0;
  *(undefined4 *)((int)&param_1->pop_panel + 3) = 0;
  puVar20 = (undefined4 *)((int)param_1->countdown_clock + 3);
  for (iVar19 = 10; iVar19 != 0; iVar19 = iVar19 + -1) {
    *puVar20 = 0;
    puVar20 = puVar20 + 1;
  }
  *(undefined4 *)((int)&param_1->message_panel + 3) = 0;
  *(undefined4 *)((int)&param_1->message_panel2 + 3) = 0;
  *(undefined4 *)((int)&param_1->message_panel3 + 3) = 0;
  *(undefined4 *)((int)&param_1->message_panel4 + 3) = 0;
  *(undefined4 *)((int)&param_1->message_panel5 + 3) = 0;
  *(undefined4 *)((int)&param_1->message_panel6 + 3) = 0;
  puVar20 = (undefined4 *)((int)param_1->chat_panel + 3);
  for (iVar19 = 8; iVar19 != 0; iVar19 = iVar19 + -1) {
    *puVar20 = 0;
    puVar20 = puVar20 + 1;
  }
  *(undefined4 *)((int)&param_1->tool_box + 3) = 0;
  param_1->field_0x45c = 0;
  *(undefined4 *)&param_1->field_0x734 = 0;
  param_1->field_0x738 = 0;
  *(RGE_Game_World **)((int)&param_1->world + 3) = rge_base_game->world;
  *(ulong *)((int)&param_1->update_interval + 3) = rge_base_game->prog_info->update_interval;
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x116);
  *(ulong *)((int)&param_1->last_update_time + 3) = uVar4;
  *(undefined4 *)((int)&param_1->map_redraw_interval + 3) = 0x14d;
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x119);
  *(ulong *)((int)&param_1->last_map_redraw_time + 3) = uVar4;
  *(undefined4 *)((int)&param_1->game_obj + 3) = 0;
  *(undefined4 *)((int)&param_1->tech_list + 3) = 0;
  *(undefined4 *)((int)&param_1->make_list + 3) = 0;
  *(undefined4 *)((int)&param_1->bldg_list + 3) = 0;
  *(undefined4 *)((int)&param_1->trade_list + 3) = 0;
  *(undefined2 *)((int)&param_1->start_item + 1) = 0;
  *(undefined2 *)((int)&param_1->last_item + 1) = 0;
  *(undefined2 *)&param_1->field_0x5e4 = 0xffff;
  *(undefined4 *)((int)&param_1->terrain_sound_interval + 3) = 0;
  *(undefined4 *)((int)&param_1->last_terrain_sound_time + 3) = 0;
  *(undefined4 *)((int)&param_1->terrain_sound + 3) = 0;
  *(undefined4 *)((int)&param_1->terrain_playing + 3) = 0;
  *(undefined4 *)((int)&param_1->terrain_sound_start_time + 3) = 0;
  *(undefined4 *)((int)&param_1->anim_pal + 3) = 1;
  *(undefined4 *)((int)&param_1->anim_pal_interval + 3) = 0;
  *(undefined4 *)((int)&param_1->last_anim_pal_time + 3) = 0;
  *(undefined2 *)((int)&param_1->last_anim_pal_index2 + 1) = 0;
  *(undefined2 *)((int)&param_1->last_anim_pal_index3 + 1) = 0;
  *(undefined2 *)((int)&param_1->anim_pal_table[0].player_id + 1) = 0;
  *(undefined4 *)((int)&param_1->anim_pal_table[6].money + 1) = 0xffffffff;
  *(undefined4 *)&param_1->field_0x70c = 0xffffffff;
  *(undefined4 *)&param_1->field_0x710 = 0;
  *(undefined4 *)&param_1->field_0x714 = 0xffffffff;
  *(undefined4 *)&param_1->field_0x718 = 0;
  *(undefined4 *)&param_1->field_0x71c = 0;
  *(undefined4 *)&param_1->field_0x720 = 0;
  *(undefined4 *)&param_1->field_0x724 = 0;
  *(undefined4 *)&param_1->field_0x728 = 100;
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x142);
  *(ulong *)&param_1->field_0x72c = uVar4;
  *(undefined4 *)&param_1->field_0x730 = 0;
  pcVar5 = TPanel::get_string((TPanel *)param_1,0x103f);
  *(int *)&param_1->field_0x76c = (int)*pcVar5;
  *(undefined4 *)&param_1->field_0x770 = 0;
  pcVar5 = TPanel::get_string((TPanel *)param_1,0x104a);
  *(int *)&param_1->field_0x774 = (int)*pcVar5;
  *(undefined4 *)&param_1->field_0x778 = 0;
  pcVar5 = TPanel::get_string((TPanel *)param_1,0x103a);
  *(int *)&param_1->field_0x77c = (int)*pcVar5;
  *(undefined4 *)&param_1->field_0x780 = 0x41;
  iVar19 = 0;
  piVar15 = (int *)&param_1->field_0x784;
  do {
    pcVar5 = TPanel::get_string((TPanel *)param_1,iVar19 + 0x1040);
    *piVar15 = (int)*pcVar5;
    iVar19 = iVar19 + 1;
    piVar15 = piVar15 + 1;
  } while (iVar19 < 8);
  *(undefined4 *)&param_1->field_0x7a4 = 1;
  *(undefined4 *)&param_1->field_0x7a8 = 3000;
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x154);
  *(ulong *)&param_1->field_0x7ac = uVar4;
  *(undefined4 *)&param_1->field_0x7b0 = 0;
  *(undefined4 *)&param_1->field_0x7b4 = 0;
  *(undefined4 *)&param_1->field_0x7b8 = 0;
  *(undefined4 *)&param_1->field_0x7bc = 0;
  *(undefined4 *)&param_1->field_0x7c0 = 0;
  lVar6 = TScreenPanel::setup((TScreenPanel *)param_1,rge_base_game->draw_area,s_scr6,0xc388,1);
  if (lVar6 != 0) {
    pTVar7 = (TShape *)operator_new(0x20);
    uStack_4._0_1_ = 1;
    if (pTVar7 == (TShape *)0x0) {
      pTVar7 = (TShape *)0x0;
    }
    else {
      pTVar7 = (TShape *)TShape::TShape(pTVar7,s_btnunit_shp,0xc62a);
    }
    uStack_4._0_1_ = 0;
    *(TShape **)((int)&param_1->button_unit_pic + 3) = pTVar7;
    if (pTVar7 != (TShape *)0x0) {
      iVar19 = TShape::is_loaded(pTVar7);
      if (iVar19 != 0) {
        pTVar7 = (TShape *)operator_new(0x20);
        uStack_4._0_1_ = 2;
        if (pTVar7 == (TShape *)0x0) {
          pTVar7 = (TShape *)0x0;
        }
        else {
          pTVar7 = (TShape *)TShape::TShape(pTVar7,s_btntech_shp,0xc629);
        }
        uStack_4._0_1_ = 0;
        *(TShape **)((int)&param_1->button_tech_pic + 3) = pTVar7;
        if (pTVar7 != (TShape *)0x0) {
          iVar19 = TShape::is_loaded(pTVar7);
          if (iVar19 != 0) {
            pTVar7 = (TShape *)operator_new(0x20);
            uStack_4._0_1_ = 3;
            if (pTVar7 == (TShape *)0x0) {
              pTVar7 = (TShape *)0x0;
            }
            else {
              pTVar7 = (TShape *)TShape::TShape(pTVar7,s_btncmd_shp,0xc621);
            }
            uStack_4 = (uint)uStack_4._1_3_ << 8;
            *(TShape **)((int)&param_1->button_cmd_pic + 3) = pTVar7;
            if (pTVar7 != (TShape *)0x0) {
              iVar19 = TShape::is_loaded(pTVar7);
              if (iVar19 != 0) {
                iVar19 = 0;
                puVar20 = (undefined4 *)((int)param_1->button_bldg_pics + 3);
                do {
                  sprintf(acStack_20c,s_btnbldg_d_shp,iVar19);
                  if (iVar19 < 4) {
                    pTVar7 = (TShape *)operator_new(0x20);
                    uStack_4 = CONCAT31(uStack_4._1_3_,4);
                    if (pTVar7 == (TShape *)0x0) {
LAB_00494255:
                      pTVar7 = (TShape *)0x0;
                    }
                    else {
                      pTVar7 = (TShape *)TShape::TShape(pTVar7,acStack_20c,iVar19 + 0xc610);
                    }
                  }
                  else {
                    pTVar7 = (TShape *)operator_new(0x20);
                    uStack_4 = CONCAT31(uStack_4._1_3_,5);
                    if (pTVar7 == (TShape *)0x0) goto LAB_00494255;
                    pTVar7 = (TShape *)TShape::TShape(pTVar7,acStack_20c,0xcf0d);
                  }
                  uStack_4 = uStack_4 & 0xffffff00;
                  *puVar20 = pTVar7;
                  if (pTVar7 == (TShape *)0x0) goto LAB_00495416;
                  iVar8 = TShape::is_loaded(pTVar7);
                  if (iVar8 == 0) goto LAB_00495416;
                  iVar19 = iVar19 + 1;
                  puVar20 = puVar20 + 1;
                } while (iVar19 < 5);
                this = (RGE_Main_View *)operator_new(0x380);
                uStack_4._0_1_ = 6;
                if (this == (RGE_Main_View *)0x0) {
                  this = (RGE_Main_View *)0x0;
                }
                else {
                  RGE_Main_View::RGE_Main_View(this);
                  this->_padding_ = (int)&TRIBE_Main_View::_vftable_;
                }
                uStack_4._0_1_ = 0;
                *(RGE_Main_View **)((int)&param_1->main_view + 3) = this;
                if ((this == (RGE_Main_View *)0x0) || (this->_padding_ != 0)) {
LAB_00495416:
                  *(undefined4 *)&param_1->field_0xd8 = 1;
                  goto LAB_00495428;
                }
                lVar6 = RGE_View::setup((RGE_View *)this,*(TDrawArea **)&param_1->field_0x20,
                                        (TPanel *)param_1,0,0,0,0,'\0',1,s_bordline);
                if (lVar6 != 0) {
                  RGE_View::set_world(*(RGE_View **)((int)&param_1->main_view + 3),
                                      *(RGE_Game_World **)((int)&param_1->world + 3));
                  pRVar9 = RGE_Base_Game::get_player(rge_base_game);
                  RGE_View::set_player(*(RGE_View **)((int)&param_1->main_view + 3),pRVar9);
                  this_00 = (TRIBE_Diamond_Map_View *)operator_new(0x174);
                  uStack_4._0_1_ = 7;
                  if (this_00 == (TRIBE_Diamond_Map_View *)0x0) {
                    this_01 = (RGE_Diamond_Map *)0x0;
                  }
                  else {
                    this_01 = (RGE_Diamond_Map *)
                              TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View(this_00);
                  }
                  uStack_4._0_1_ = 0;
                  *(RGE_Diamond_Map **)((int)&param_1->map_view + 3) = this_01;
                  if ((this_01 != (RGE_Diamond_Map *)0x0) && (this_01->_padding_ == 0)) {
                    lVar6 = RGE_Diamond_Map::setup
                                      (this_01,*(TDrawArea **)&param_1->field_0x20,(TPanel *)param_1
                                       ,0,0,0,0,'\0',0,rge_base_game->map_save_area);
                    if (lVar6 != 0) {
                      TPanel::set_help_info(*(TPanel **)((int)&param_1->map_view + 3),0x4e33,-1);
                      RGE_Diamond_Map::set_world
                                (*(RGE_Diamond_Map **)((int)&param_1->map_view + 3),
                                 *(RGE_Game_World **)((int)&param_1->world + 3));
                      RGE_Diamond_Map::set_bitmap
                                (*(RGE_Diamond_Map **)((int)&param_1->map_view + 3),s_map_bmp,0xc4e1
                                );
                      pRVar9 = RGE_Base_Game::get_player(rge_base_game);
                      RGE_Diamond_Map::set_player
                                (*(RGE_Diamond_Map **)((int)&param_1->map_view + 3),pRVar9);
                      *(undefined4 *)(*(int *)((int)&param_1->map_view + 3) + 0x150) =
                           *(undefined4 *)((int)&param_1->main_view + 3);
                      pRVar10 = RGE_Base_Game::get_font(rge_base_game,0xb);
                      this_02 = (TRIBE_Panel_Inven *)operator_new(0x118);
                      uStack_4._0_1_ = 8;
                      if (this_02 == (TRIBE_Panel_Inven *)0x0) {
                        pTVar12 = (TPanel *)0x0;
                      }
                      else {
                        pTVar11 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
                        pTVar12 = (TPanel *)
                                  TRIBE_Panel_Inven::TRIBE_Panel_Inven
                                            (this_02,*(TDrawArea **)&param_1->field_0x20,
                                             (TPanel *)param_1,pRVar10->font,pTVar11);
                      }
                      uStack_4._0_1_ = 0;
                      *(TPanel **)((int)&param_1->inven_panel + 3) = pTVar12;
                      if ((pTVar12 != (TPanel *)0x0) && (pTVar12->error_code == 0)) {
                        TPanel::set_help_info(pTVar12,0x4e25,-1);
                        pRVar10 = RGE_Base_Game::get_font(rge_base_game,7);
                        this_03 = (TRIBE_Panel_Object *)operator_new(0x214);
                        uStack_4._0_1_ = 9;
                        if (this_03 == (TRIBE_Panel_Object *)0x0) {
                          pTVar12 = (TPanel *)0x0;
                        }
                        else {
                          pTVar11 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
                          pTVar12 = (TPanel *)
                                    TRIBE_Panel_Object::TRIBE_Panel_Object
                                              (this_03,*(TDrawArea **)&param_1->field_0x20,
                                               (TPanel *)param_1,pRVar10->font,pRVar10->font_wid,
                                               pRVar10->font_hgt,
                                               *(TShape **)((int)&param_1->button_unit_pic + 3),
                                               (TShape **)((int)param_1->button_bldg_pics + 3),
                                               pTVar11);
                        }
                        uStack_4 = (uint)uStack_4._1_3_ << 8;
                        *(TPanel **)((int)&param_1->object_panel + 3) = pTVar12;
                        if ((pTVar12 != (TPanel *)0x0) && (pTVar12->error_code == 0)) {
                          TPanel::set_help_info(pTVar12,0x19bb8,0x265ac);
                          pRVar10 = RGE_Base_Game::get_font(rge_base_game,0xb);
                          pTVar13 = RGE_Base_Game::get_sound(rge_base_game,1);
                          iVar19 = 0;
                          puVar20 = (undefined4 *)((int)param_1->button_panel + 3);
                          do {
                            this_04 = (TRIBE_Panel_Button *)operator_new(0x3d4);
                            uStack_4._0_1_ = 10;
                            if (this_04 == (TRIBE_Panel_Button *)0x0) {
                              this_05 = (TButtonPanel *)0x0;
                            }
                            else {
                              if (iVar19 < 0xc) {
                                pTVar7 = *(TShape **)((int)&param_1->button_border1_pic + 3);
                              }
                              else {
                                pTVar7 = *(TShape **)((int)&param_1->button_border2_pic + 3);
                              }
                              this_05 = (TButtonPanel *)
                                        TRIBE_Panel_Button::TRIBE_Panel_Button
                                                  (this_04,*(TDrawArea **)&param_1->field_0x20,
                                                   (TPanel *)param_1,pTVar13,pRVar10->font,
                                                   pRVar10->font_wid,pRVar10->font_hgt,pTVar7);
                            }
                            uStack_4 = (uint)uStack_4._1_3_ << 8;
                            *puVar20 = this_05;
                            if ((this_05 == (TButtonPanel *)0x0) || (this_05->_padding_ != 0))
                            goto LAB_00495416;
                            TButtonPanel::set_text_color(this_05,0,0,0xffffff);
                            TButtonPanel::set_sound_number((TButtonPanel *)*puVar20,1);
                            iVar19 = iVar19 + 1;
                            puVar20 = puVar20 + 1;
                          } while (iVar19 < 0x11);
                          piVar15 = (int *)((int)param_1->button_panel + 0x33);
                          TButtonPanel::set_id
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x33),0,0xd,0);
                          TPanel::set_help_info((TPanel *)*piVar15,0x1d4cf,-1);
                          TButtonPanel::set_id
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x37),0,0xe,0);
                          TPanel::set_help_info
                                    (*(TPanel **)((int)param_1->button_panel + 0x37),0x1d4d1,-1);
                          TButtonPanel::set_id
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x3b),0,0xf,0);
                          TPanel::set_help_info
                                    (*(TPanel **)((int)param_1->button_panel + 0x3b),0x1d4cd,-1);
                          TButtonPanel::set_id
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x3f),0,0x15,0)
                          ;
                          TPanel::set_help_info
                                    (*(TPanel **)((int)param_1->button_panel + 0x3f),0x1d4db,-1);
                          TButtonPanel::set_id
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x43),0,0x18,0)
                          ;
                          TPanel::set_help_info
                                    (*(TPanel **)((int)param_1->button_panel + 0x43),0x1d4dc,-1);
                          iStack_21c = 3;
                          do {
                            TButtonPanel::setDrawType((TButtonPanel *)*piVar15,DrawTextA);
                            uVar23 = 0x200;
                            *(undefined1 *)(*piVar15 + 0x2c0) = 3;
                            pcVar5 = acStack_20c;
                            iVar19 = rge_base_game->_padding_;
                            uVar22 = 0;
                            lVar6 = TButtonPanel::get_id((TButtonPanel *)*piVar15);
                            pcVar5 = (char *)(**(code **)(iVar19 + 0x28))
                                                       (0x66,lVar6,uVar22,pcVar5,uVar23);
                            TButtonPanel::set_text((TButtonPanel *)*piVar15,0,pcVar5);
                            TButtonPanel::set_bevel_info
                                      ((TButtonPanel *)*piVar15,3,(uint)(byte)param_1->field_0x320,
                                       (uint)(byte)param_1->field_0x321,
                                       (uint)(byte)param_1->field_0x322,
                                       (uint)(byte)param_1->field_0x323,
                                       (uint)(byte)param_1->field_0x324,
                                       (uint)(byte)param_1->field_0x325);
                            piVar15 = piVar15 + 1;
                            iStack_21c = iStack_21c + -1;
                          } while (iStack_21c != 0);
                          iVar19 = RGE_Base_Game::singlePlayerGame(rge_base_game);
                          if (iVar19 == 1) {
                            (**(code **)(**(int **)((int)param_1->button_panel + 0x33) + 0x14))(0);
                          }
                          TButtonPanel::setDrawType
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x3f),DrawTextA
                                    );
                          TButtonPanel::set_bevel_info
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x3f),4,
                                     (uint)(byte)param_1->field_0x320,
                                     (uint)(byte)param_1->field_0x321,
                                     (uint)(byte)param_1->field_0x322,
                                     (uint)(byte)param_1->field_0x323,
                                     (uint)(byte)param_1->field_0x324,
                                     (uint)(byte)param_1->field_0x325);
                          *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x3f) + 0x2c0) = 3;
                          TButtonPanel::set_text
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x3f),0,0xfa9);
                          TButtonPanel::setDrawType
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x43),DrawTextA
                                    );
                          TButtonPanel::set_bevel_info
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x43),4,
                                     (uint)(byte)param_1->field_0x320,
                                     (uint)(byte)param_1->field_0x321,
                                     (uint)(byte)param_1->field_0x322,
                                     (uint)(byte)param_1->field_0x323,
                                     (uint)(byte)param_1->field_0x324,
                                     (uint)(byte)param_1->field_0x325);
                          *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x43) + 0x2c0) = 3;
                          TButtonPanel::set_text
                                    (*(TButtonPanel **)((int)param_1->button_panel + 0x43),0,0x1023)
                          ;
                          TPanel::get_string((TPanel *)param_1,0x1024,acStack_20c,0x200);
                          TRIBE_Panel_Button::set_text_msg
                                    (*(TRIBE_Panel_Button **)((int)param_1->button_panel + 0x43),
                                     acStack_20c);
                          pRVar10 = RGE_Base_Game::get_font(rge_base_game,0xb);
                          pTVar14 = (TMessagePanel *)operator_new(0x380);
                          uStack_4._0_1_ = 0xb;
                          if (pTVar14 == (TMessagePanel *)0x0) {
                            piVar15 = (int *)0x0;
                          }
                          else {
                            piVar15 = (int *)TMessagePanel::TMessagePanel
                                                       (pTVar14,pRVar10->font,pRVar10->font_wid,
                                                        pRVar10->font_hgt);
                          }
                          uStack_4 = (uint)uStack_4._1_3_ << 8;
                          *(int **)((int)&param_1->text_line_panel + 3) = piVar15;
                          if ((piVar15 != (int *)0x0) && (piVar15[0x36] == 0)) {
                            iVar19 = (**(code **)(*piVar15 + 4))
                                               (*(undefined4 *)&param_1->field_0x20,
                                                *(undefined4 *)((int)&param_1->main_view + 3),0,0,0,
                                                0,0);
                            if (iVar19 == 0) {
                              *(undefined4 *)&param_1->field_0xd8 = 1;
                              goto LAB_00495428;
                            }
                            TMessagePanel::set_justification
                                      (*(TMessagePanel **)((int)&param_1->text_line_panel + 3),
                                       LeftJust,BottomJust,1);
                            *(undefined4 *)(*(int *)((int)&param_1->main_view + 3) + 0x34c) =
                                 *(undefined4 *)((int)&param_1->text_line_panel + 3);
                            ppTVar1 = (TTextPanel **)((int)&param_1->quit_message_panel + 3);
                            TEasy_Panel::create_text
                                      ((TEasy_Panel *)param_1,
                                       *(TPanel **)((int)&param_1->main_view + 3),ppTVar1,0x232e,0,0
                                       ,600,0x3c,0xb,1,1,0);
                            if (*ppTVar1 != (TTextPanel *)0x0) {
                              TTextPanel::set_text_color(*ppTVar1,0xffffff,0);
                              (**(code **)((*ppTVar1)->_padding_ + 0x14))(0);
                            }
                            ppTVar1 = (TTextPanel **)((int)&param_1->pause_text + 3);
                            TEasy_Panel::create_text
                                      ((TEasy_Panel *)param_1,
                                       *(TPanel **)((int)&param_1->main_view + 3),ppTVar1,0x2329,0,0
                                       ,600,0x3c,1,1,1,0);
                            if (*ppTVar1 != (TTextPanel *)0x0) {
                              TTextPanel::set_text_color(*ppTVar1,0xffffff,0);
                              (**(code **)((*ppTVar1)->_padding_ + 0x14))(0);
                            }
                            pTVar16 = (TRIBE_Panel_Time *)operator_new(0x174);
                            uStack_4._0_1_ = 0xc;
                            if (pTVar16 == (TRIBE_Panel_Time *)0x0) {
                              piVar15 = (int *)0x0;
                            }
                            else {
                              piVar15 = (int *)TRIBE_Panel_Time::TRIBE_Panel_Time
                                                         (pTVar16,*(TDrawArea **)
                                                                   &param_1->field_0x20,
                                                          *(TPanel **)((int)&param_1->main_view + 3)
                                                         );
                            }
                            uStack_4._0_1_ = 0;
                            *(int **)((int)&param_1->time_panel + 3) = piVar15;
                            if ((piVar15 != (int *)0x0) && (piVar15[0x36] == 0)) {
                              (**(code **)(*piVar15 + 0x14))(0);
                              this_06 = (TRIBE_Panel_Pop *)operator_new(0x164);
                              uStack_4._0_1_ = 0xd;
                              if (this_06 == (TRIBE_Panel_Pop *)0x0) {
                                piVar15 = (int *)0x0;
                              }
                              else {
                                piVar15 = (int *)TRIBE_Panel_Pop::TRIBE_Panel_Pop
                                                           (this_06,*(TDrawArea **)
                                                                     &param_1->field_0x20,
                                                            *(TPanel **)
                                                             ((int)&param_1->main_view + 3));
                              }
                              uStack_4._0_1_ = 0;
                              *(int **)((int)&param_1->pop_panel + 3) = piVar15;
                              if ((piVar15 != (int *)0x0) && (piVar15[0x36] == 0)) {
                                (**(code **)(*piVar15 + 0x14))(0);
                                iVar19 = 0;
                                puVar20 = (undefined4 *)((int)param_1->countdown_clock + 3);
                                do {
                                  pTVar16 = (TRIBE_Panel_Time *)operator_new(0x174);
                                  uStack_4._0_1_ = 0xe;
                                  if (pTVar16 == (TRIBE_Panel_Time *)0x0) {
                                    piVar15 = (int *)0x0;
                                  }
                                  else {
                                    piVar15 = (int *)TRIBE_Panel_Time::TRIBE_Panel_Time
                                                               (pTVar16,*(TDrawArea **)
                                                                         &param_1->field_0x20,
                                                                *(TPanel **)
                                                                 ((int)&param_1->main_view + 3));
                                  }
                                  uStack_4._0_1_ = 0;
                                  *puVar20 = piVar15;
                                  if ((piVar15 == (int *)0x0) || (piVar15[0x36] != 0))
                                  goto LAB_00495416;
                                  (**(code **)(*piVar15 + 0x14))(0);
                                  iVar19 = iVar19 + 1;
                                  puVar20 = puVar20 + 1;
                                } while (iVar19 < 10);
                                RGE_Base_Game::get_sound(rge_base_game,1);
                                pRVar10 = RGE_Base_Game::get_font(rge_base_game,0xb);
                                pTVar14 = (TMessagePanel *)operator_new(0x380);
                                uStack_4._0_1_ = 0xf;
                                if (pTVar14 == (TMessagePanel *)0x0) {
                                  uVar22 = 0;
                                }
                                else {
                                  uVar22 = TMessagePanel::TMessagePanel
                                                     (pTVar14,pRVar10->font,pRVar10->font_wid,
                                                      pRVar10->font_hgt);
                                }
                                uStack_4._0_1_ = 0;
                                *(undefined4 *)((int)&param_1->message_panel + 3) = uVar22;
                                pTVar14 = (TMessagePanel *)operator_new(0x380);
                                uStack_4._0_1_ = 0x10;
                                if (pTVar14 == (TMessagePanel *)0x0) {
                                  uVar22 = 0;
                                }
                                else {
                                  uVar22 = TMessagePanel::TMessagePanel
                                                     (pTVar14,pRVar10->font,pRVar10->font_wid,
                                                      pRVar10->font_hgt);
                                }
                                uStack_4._0_1_ = 0;
                                *(undefined4 *)((int)&param_1->message_panel2 + 3) = uVar22;
                                pTVar14 = (TMessagePanel *)operator_new(0x380);
                                uStack_4._0_1_ = 0x11;
                                if (pTVar14 == (TMessagePanel *)0x0) {
                                  uVar22 = 0;
                                }
                                else {
                                  uVar22 = TMessagePanel::TMessagePanel
                                                     (pTVar14,pRVar10->font,pRVar10->font_wid,
                                                      pRVar10->font_hgt);
                                }
                                uStack_4._0_1_ = 0;
                                *(undefined4 *)((int)&param_1->message_panel3 + 3) = uVar22;
                                pTVar14 = (TMessagePanel *)operator_new(0x380);
                                uStack_4._0_1_ = 0x12;
                                if (pTVar14 == (TMessagePanel *)0x0) {
                                  uVar22 = 0;
                                }
                                else {
                                  uVar22 = TMessagePanel::TMessagePanel
                                                     (pTVar14,pRVar10->font,pRVar10->font_wid,
                                                      pRVar10->font_hgt);
                                }
                                uStack_4._0_1_ = 0;
                                *(undefined4 *)((int)&param_1->message_panel4 + 3) = uVar22;
                                pTVar14 = (TMessagePanel *)operator_new(0x380);
                                uStack_4._0_1_ = 0x13;
                                if (pTVar14 == (TMessagePanel *)0x0) {
                                  uVar22 = 0;
                                }
                                else {
                                  uVar22 = TMessagePanel::TMessagePanel
                                                     (pTVar14,pRVar10->font,pRVar10->font_wid,
                                                      pRVar10->font_hgt);
                                }
                                uStack_4._0_1_ = 0;
                                *(undefined4 *)((int)&param_1->message_panel5 + 3) = uVar22;
                                pTVar14 = (TMessagePanel *)operator_new(0x380);
                                uStack_4._0_1_ = 0x14;
                                if (pTVar14 == (TMessagePanel *)0x0) {
                                  iVar19 = 0;
                                }
                                else {
                                  iVar19 = TMessagePanel::TMessagePanel
                                                     (pTVar14,pRVar10->font,pRVar10->font_wid,
                                                      pRVar10->font_hgt);
                                }
                                *(int *)((int)&param_1->message_panel6 + 3) = iVar19;
                                piVar15 = *(int **)((int)&param_1->message_panel + 3);
                                uStack_4._0_1_ = 0;
                                if ((((((piVar15 != (int *)0x0) && (piVar15[0x36] == 0)) &&
                                      (iVar8 = *(int *)((int)&param_1->message_panel2 + 3),
                                      iVar8 != 0)) &&
                                     (((*(int *)(iVar8 + 0xd8) == 0 &&
                                       (iVar8 = *(int *)((int)&param_1->message_panel3 + 3),
                                       iVar8 != 0)) &&
                                      ((*(int *)(iVar8 + 0xd8) == 0 &&
                                       ((iVar8 = *(int *)((int)&param_1->message_panel4 + 3),
                                        iVar8 != 0 &&
                                        (*(int *)((int)&param_1->message_panel5 + 3) != 0)))))))) &&
                                    (iVar19 != 0)) && (*(int *)(iVar8 + 0xd8) == 0)) {
                                  iVar19 = (**(code **)(*piVar15 + 4))
                                                     (*(undefined4 *)&param_1->field_0x20,
                                                      *(undefined4 *)((int)&param_1->main_view + 3),
                                                      0,0,0,0,0);
                                  if (iVar19 != 0) {
                                    iVar19 = (**(code **)(**(int **)((int)&param_1->message_panel2 +
                                                                    3) + 4))
                                                       (*(undefined4 *)&param_1->field_0x20,
                                                        *(undefined4 *)
                                                         ((int)&param_1->main_view + 3),0,0,0,0,0);
                                    if (iVar19 != 0) {
                                      iVar19 = (**(code **)(**(int **)((int)&param_1->message_panel3
                                                                      + 3) + 4))
                                                         (*(undefined4 *)&param_1->field_0x20,
                                                          *(undefined4 *)
                                                           ((int)&param_1->main_view + 3),0,0,0,0,0)
                                      ;
                                      if (iVar19 != 0) {
                                        iVar19 = (**(code **)(**(int **)((int)&param_1->
                                                  message_panel4 + 3) + 4))
                                                           (*(undefined4 *)&param_1->field_0x20,
                                                            *(undefined4 *)
                                                             ((int)&param_1->main_view + 3),0,0,0,0,
                                                            0);
                                        if (iVar19 != 0) {
                                          iVar19 = (**(code **)(**(int **)((int)&param_1->
                                                  message_panel5 + 3) + 4))
                                                            (*(undefined4 *)&param_1->field_0x20,
                                                             *(undefined4 *)
                                                              ((int)&param_1->main_view + 3),0,0,0,0
                                                             ,0);
                                          if (iVar19 != 0) {
                                            iVar19 = (**(code **)(**(int **)((int)&param_1->
                                                  message_panel6 + 3) + 4))
                                                            (*(undefined4 *)&param_1->field_0x20,
                                                             *(undefined4 *)
                                                              ((int)&param_1->main_view + 3),0,0,0,0
                                                             ,0);
                                            if (iVar19 != 0) {
                                              pRVar10 = RGE_Base_Game::get_font(rge_base_game,0xb);
                                              puVar20 = (undefined4 *)((int)param_1->chat_panel + 3)
                                              ;
                                              iStack_21c = 0;
                                              do {
                                                pTVar14 = (TMessagePanel *)operator_new(0x380);
                                                uStack_4._0_1_ = 0x15;
                                                if (pTVar14 == (TMessagePanel *)0x0) {
                                                  piVar15 = (int *)0x0;
                                                }
                                                else {
                                                  piVar15 = (int *)TMessagePanel::TMessagePanel
                                                                             (pTVar14,pRVar10->font,
                                                                              pRVar10->font_wid,
                                                                              pRVar10->font_hgt);
                                                }
                                                uStack_4._0_1_ = 0;
                                                *puVar20 = piVar15;
                                                if ((piVar15 == (int *)0x0) || (piVar15[0x36] != 0))
                                                goto LAB_00495416;
                                                iVar19 = (**(code **)(*piVar15 + 4))
                                                                   (*(undefined4 *)
                                                                     &param_1->field_0x20,
                                                                    *(undefined4 *)
                                                                     ((int)&param_1->main_view + 3),
                                                                    0,0,0,0,0);
                                                if (iVar19 == 0) goto LAB_00495416;
                                                puVar20 = puVar20 + 1;
                                                iStack_21c = iStack_21c + 1;
                                              } while (iStack_21c < 8);
                                              pRVar10 = RGE_Base_Game::get_font(rge_base_game,0xb);
                                              pTVar17 = (TTextPanel *)operator_new(0x188);
                                              uStack_4._0_1_ = 0x16;
                                              if (pTVar17 == (TTextPanel *)0x0) {
                                                pTVar17 = (TTextPanel *)0x0;
                                              }
                                              else {
                                                pTVar17 = (TTextPanel *)
                                                          TTextPanel::TTextPanel(pTVar17);
                                              }
                                              uStack_4 = (uint)uStack_4._1_3_ << 8;
                                              *(TTextPanel **)((int)&param_1->age_panel + 3) =
                                                   pTVar17;
                                              if ((pTVar17 != (TTextPanel *)0x0) &&
                                                 (pTVar17->_padding_ == 0)) {
                                                lVar6 = TTextPanel::setup(pTVar17,*(TDrawArea **)
                                                                                   &param_1->
                                                  field_0x20,(TPanel *)param_1,0,0,0,0,pRVar10->font
                                                  ,pRVar10->font_wid,pRVar10->font_hgt,(char *)0x0,0
                                                  ,'\0',0,'\0',0,(char *)0x0);
                                                if (lVar6 == 0) {
                                                  *(undefined4 *)&param_1->field_0xd8 = 1;
                                                  goto LAB_00495428;
                                                }
                                                TTextPanel::set_alignment
                                                          (*(TTextPanel **)
                                                            ((int)&param_1->age_panel + 3),
                                                           AlignCenter,AlignCenter);
                                                TPanel::set_help_info
                                                          (*(TPanel **)
                                                            ((int)&param_1->age_panel + 3),0x4e35,-1
                                                          );
                                                if (do_color_log != '\0') {
                                                  (**(code **)(**(int **)((int)&param_1->age_panel +
                                                                         3) + 0x14))(0);
                                                }
                                                pRVar10 = RGE_Base_Game::get_font(rge_base_game,10);
                                                pTVar17 = (TTextPanel *)operator_new(0x188);
                                                uStack_4._0_1_ = 0x17;
                                                if (pTVar17 == (TTextPanel *)0x0) {
                                                  pTVar17 = (TTextPanel *)0x0;
                                                }
                                                else {
                                                  pTVar17 = (TTextPanel *)
                                                            TTextPanel::TTextPanel(pTVar17);
                                                }
                                                uStack_4 = (uint)uStack_4._1_3_ << 8;
                                                *(TTextPanel **)((int)&param_1->fps_panel + 3) =
                                                     pTVar17;
                                                if ((pTVar17 != (TTextPanel *)0x0) &&
                                                   (pTVar17->_padding_ == 0)) {
                                                  lVar6 = TTextPanel::setup(pTVar17,*(TDrawArea **)
                                                                                     &param_1->
                                                  field_0x20,(TPanel *)param_1,0,0,0,0,pRVar10->font
                                                  ,pRVar10->font_wid,pRVar10->font_hgt,(char *)0x0,1
                                                  ,'\0',0,'\0',0,(char *)0x0);
                                                  if (lVar6 == 0) {
                                                    *(undefined4 *)&param_1->field_0xd8 = 1;
                                                    goto LAB_00495428;
                                                  }
                                                  TTextPanel::set_alignment
                                                            (*(TTextPanel **)
                                                              ((int)&param_1->fps_panel + 3),
                                                             AlignCenter,AlignLeft);
                                                  piVar15 = *(int **)((int)&param_1->fps_panel + 3);
                                                  if (rge_base_game->do_show_timings == 0) {
                                                    (**(code **)(*piVar15 + 0x14))(0);
                                                    (**(code **)(**(int **)((int)&param_1->
                                                  inven_panel + 3) + 0x14))(1);
                                                  if (do_color_log == '\0') {
                                                    (**(code **)(**(int **)((int)&param_1->age_panel
                                                                           + 3) + 0x14))(1);
                                                  }
                                                  }
                                                  else {
                                                    (**(code **)(*piVar15 + 0x14))(1);
                                                    (**(code **)(**(int **)((int)&param_1->
                                                  inven_panel + 3) + 0x14))(0);
                                                  if (do_color_log == '\0') {
                                                    (**(code **)(**(int **)((int)&param_1->age_panel
                                                                           + 3) + 0x14))(0);
                                                  }
                                                  }
                                                  pRVar10 = RGE_Base_Game::get_font
                                                                      (rge_base_game,0xb);
                                                  iStack_214 = 0;
                                                  iVar19 = RGE_Base_Game::multiplayerGame
                                                                     (rge_base_game);
                                                  if (iVar19 == 0) {
                                                    iStack_214 = *(short *)(*(int *)((int)&param_1->
                                                  world + 3) + 0x3c) + -1;
                                                  }
                                                  else {
                                                    uVar21 = 1;
                                                    do {
                                                      iVar19 = TCommunications_Handler::
                                                               GetPlayerHumanity(comm,uVar21);
                                                      if (iVar19 == 2) {
LAB_00495012:
                                                        iStack_214 = iStack_214 + 1;
                                                      }
                                                      else {
                                                        iVar19 = TCommunications_Handler::
                                                                 GetPlayerHumanity(comm,uVar21);
                                                        if (iVar19 == 4) goto LAB_00495012;
                                                      }
                                                      uVar21 = uVar21 + 1;
                                                    } while ((int)uVar21 < 9);
                                                    if (iStack_214 == 0) {
                                                      iStack_214 = 1;
                                                    }
                                                  }
                                                  iVar19 = 0;
                                                  if (0 < iStack_214) {
                                                    piVar15 = (int *)((int)param_1->score_panel + 3)
                                                    ;
                                                    do {
                                                      pTVar14 = (TMessagePanel *)operator_new(0x380)
                                                      ;
                                                      uStack_4._0_1_ = 0x18;
                                                      if (pTVar14 == (TMessagePanel *)0x0) {
                                                        piVar18 = (int *)0x0;
                                                      }
                                                      else {
                                                        piVar18 = (int *)TMessagePanel::
                                                                         TMessagePanel(pTVar14,
                                                  pRVar10->font,pRVar10->font_wid,pRVar10->font_hgt)
                                                  ;
                                                  }
                                                  iVar8 = *piVar18;
                                                  *piVar15 = (int)piVar18;
                                                  uStack_4 = (uint)uStack_4._1_3_ << 8;
                                                  iVar8 = (**(code **)(iVar8 + 4))
                                                                    (*(undefined4 *)
                                                                      &param_1->field_0x20,
                                                                     *(undefined4 *)
                                                                      ((int)&param_1->main_view + 3)
                                                                     ,0,0,0,0,0);
                                                  if (((iVar8 == 0) || (*piVar15 == 0)) ||
                                                     (*(int *)(*piVar15 + 0xd8) != 0))
                                                  goto LAB_00495416;
                                                  iVar19 = iVar19 + 1;
                                                  piVar15 = piVar15 + 1;
                                                  } while (iVar19 < iStack_214);
                                                  }
                                                  ppTVar1 = (TTextPanel **)
                                                            ((int)&param_1->log_text + 3);
                                                  iVar19 = TEasy_Panel::create_text
                                                                     ((TEasy_Panel *)param_1,
                                                                      (TPanel *)param_1,ppTVar1,s_,
                                                                      10,300,400,0x60,7,0,0,0);
                                                  if (iVar19 == 0) {
                                                    *(undefined4 *)&param_1->field_0xd8 = 1;
                                                    goto LAB_00495428;
                                                  }
                                                  TTextPanel::set_back_pic(*ppTVar1,(char *)0x0);
                                                  TTextPanel::set_fill_back(*ppTVar1,1,'\0');
                                                  TTextPanel::set_style(*ppTVar1,NormalStyle);
                                                  TTextPanel::set_text_color(*ppTVar1,0xffffff,0);
                                                  ppTVar2 = (TScrollBarPanel **)
                                                            ((int)&param_1->log_scrollbar + 3);
                                                  iVar19 = TEasy_Panel::create_auto_scrollbar
                                                                     ((TEasy_Panel *)param_1,ppTVar2
                                                                      ,*ppTVar1,0x14);
                                                  if (iVar19 == 0) {
                                                    *(undefined4 *)&param_1->field_0xd8 = 1;
                                                    goto LAB_00495428;
                                                  }
                                                  TScrollBarPanel::set_bevel_info
                                                            (*ppTVar2,1,0xff,0xff,0xff,0xff,0xff,
                                                             0xff);
                                                  TTextPanel::empty_list(*ppTVar1);
                                                  (**(code **)((*ppTVar1)->_padding_ + 0x14))(0);
                                                  pRVar10 = RGE_Base_Game::get_font(rge_base_game,7)
                                                  ;
                                                  pTVar13 = RGE_Base_Game::get_sound
                                                                      (rge_base_game,1);
                                                  this_07 = (RGE_Panel_Tool_Box *)
                                                            operator_new(0x120);
                                                  uStack_4._0_1_ = 0x19;
                                                  if (this_07 == (RGE_Panel_Tool_Box *)0x0) {
                                                    piVar15 = (int *)0x0;
                                                  }
                                                  else {
                                                    piVar15 = (int *)RGE_Panel_Tool_Box::
                                                                     RGE_Panel_Tool_Box(this_07,*(
                                                  TDrawArea **)&param_1->field_0x20,
                                                  (TPanel *)param_1,0,0,0,0,pRVar10->font,
                                                  pRVar10->font_wid,pRVar10->font_hgt,pTVar13,
                                                  (TScreenPanel *)param_1,
                                                  *(RGE_View **)((int)&param_1->main_view + 3),
                                                  *(RGE_Diamond_Map **)((int)&param_1->map_view + 3)
                                                  );
                                                  }
                                                  uStack_4 = (uint)uStack_4._1_3_ << 8;
                                                  *(int **)((int)&param_1->tool_box + 3) = piVar15;
                                                  if ((piVar15 != (int *)0x0) &&
                                                     (piVar15[0x36] == 0)) {
                                                    (**(code **)(*piVar15 + 0x14))(0);
                                                    puVar20 = (undefined4 *)
                                                              ((int)param_1->button_panel + 3);
                                                    iVar19 = 0x11;
                                                    do {
                                                      TPanel::set_z_order((TPanel *)*puVar20,'\x01',
                                                                          0);
                                                      puVar20 = puVar20 + 1;
                                                      iVar19 = iVar19 + -1;
                                                    } while (iVar19 != 0);
                                                    TRIBE_Screen_Game::handle_size
                                                              (param_1,*(long *)&param_1->field_0x14
                                                               ,*(long *)&param_1->field_0x18);
                                                    TPanel::set_curr_child
                                                              ((TPanel *)param_1,
                                                               *(TPanel **)
                                                                ((int)&param_1->main_view + 3));
                                                    pRVar9 = RGE_Base_Game::get_player
                                                                       (rge_base_game);
                                                    iVar19 = (int)pRVar9->id;
                                                    pRVar9 = RGE_Base_Game::get_player
                                                                       (rge_base_game);
                                                    TRIBE_Screen_Game::player_changed
                                                              (param_1,(int)pRVar9->id,iVar19);
                                                    *(undefined4 *)
                                                     ((int)&param_1->terrain_sound_interval + 3) =
                                                         20000;
                                                    uVar4 = debug_timeGetTime(
                                                  s_C__msdev_work_age1_x1_scr_game_c,0x339);
                                                  *(ulong *)((int)&param_1->last_terrain_sound_time
                                                            + 3) = uVar4;
                                                  *(undefined4 *)
                                                   ((int)&param_1->anim_pal_interval + 3) = 200;
                                                  uVar4 = debug_timeGetTime(
                                                  s_C__msdev_work_age1_x1_scr_game_c,0x33f);
                                                  *(ulong *)((int)&param_1->last_anim_pal_time + 3)
                                                       = uVar4;
                                                  *(undefined2 *)
                                                   ((int)&param_1->last_anim_pal_index2 + 1) = 0;
                                                  *(undefined2 *)
                                                   ((int)&param_1->last_anim_pal_index3 + 1) = 0;
                                                  *(undefined2 *)
                                                   ((int)&param_1->anim_pal_table[0].player_id + 1)
                                                       = 0;
                                                  *(undefined1 *)&param_1->anim_pal_table[0].player
                                                       = 0x27;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[0].player + 2) =
                                                       0x27;
                                                  param_1->anim_pal_table[1].field_0x2 = 0x27;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[1].player + 2) =
                                                       0x27;
                                                  pTVar16 = *(TRIBE_Panel_Time **)
                                                             ((int)&param_1->time_panel + 3);
                                                  param_1->anim_pal_table[0].field_0x3 = 0x17;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[0].player + 1) =
                                                       0x7c;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[0].player + 3) =
                                                       0x3f;
                                                  *(undefined1 *)&param_1->anim_pal_table[0].port =
                                                       0x90;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[0].port + 1) =
                                                       0x3f;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[0].port + 2) =
                                                       0x5f;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[0].port + 3) =
                                                       0x9f;
                                                  *(undefined1 *)&param_1->anim_pal_table[0].money =
                                                       0x57;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[0].money + 1) =
                                                       0x7b;
                                                  param_1->anim_pal_table[0].field_0xe = 0xb4;
                                                  param_1->anim_pal_table[0].field_0xf = 0x3f;
                                                  *(undefined1 *)
                                                   &param_1->anim_pal_table[1].player_id = 0x5f;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[1].player_id + 1)
                                                       = 0xa0;
                                                  param_1->anim_pal_table[1].field_0x3 = 0x3f;
                                                  *(undefined1 *)&param_1->anim_pal_table[1].player
                                                       = 0x91;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[1].player + 1) =
                                                       0x17;
                                                  *(undefined1 *)
                                                   ((int)&param_1->anim_pal_table[1].player + 3) =
                                                       0x7b;
                                                  TRIBE_Panel_Time::startup(pTVar16);
                                                  TRIBE_Panel_Time::set_clock_type
                                                            (*(TRIBE_Panel_Time **)
                                                              ((int)&param_1->time_panel + 3),0,0);
                                                  puVar20 = (undefined4 *)
                                                            ((int)param_1->countdown_clock + 3);
                                                  iVar19 = 10;
                                                  do {
                                                    TRIBE_Panel_Time::startup
                                                              ((TRIBE_Panel_Time *)*puVar20);
                                                    TRIBE_Panel_Time::set_clock_type
                                                              ((TRIBE_Panel_Time *)*puVar20,0,0);
                                                    puVar20 = puVar20 + 1;
                                                    iVar19 = iVar19 + -1;
                                                  } while (iVar19 != 0);
                                                  TRIBE_Screen_Game::reset_clocks(param_1);
                                                  TRIBE_Panel_Pop::startup
                                                            (*(TRIBE_Panel_Pop **)
                                                              ((int)&param_1->pop_panel + 3));
                                                  TRIBE_Screen_Game::command_score
                                                            (param_1,(uint)*(byte *)(*(int *)((int)&
                                                  param_1->world + 3) + 0x11c));
                                                  confirmed_close = 0;
                                                  uVar3 = RGE_Base_Game::check_prog_argument
                                                                    (rge_base_game,s_PAUSE);
                                                  if (uVar3 != '\0') {
                                                    start_paused = 1;
                                                    (**(code **)(rge_base_game->_padding_ + 0xc))(6)
                                                    ;
                                                    rge_base_game->world->temp_pause = '\x01';
                                                  }
                                                  goto LAB_00495428;
                                                  }
                                                }
                                              }
                                              goto LAB_00495416;
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
                          *(undefined4 *)&param_1->field_0xd8 = 1;
                          goto LAB_00495428;
                        }
                      }
                      goto LAB_00495416;
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
  *(undefined4 *)&param_1->field_0xd8 = 1;
LAB_00495428:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00495443
// Address: 00495443
// XREFS: None
TRIBE_Screen_Game * __thiscall FUN_00495443(TRIBE_Screen_Game *param_1,byte param_2)
{
  TRIBE_Screen_Game::~TRIBE_Screen_Game(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0049546e
// Address: 0049546e
// XREFS: None
TRIBE_Main_View * __thiscall FUN_0049546e(TRIBE_Main_View *param_1,byte param_2)
{
  TRIBE_Main_View::~TRIBE_Main_View(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00495495
// Address: 00495495
// XREFS: None
// [HELPER] s_Config_Dialog: "Config Dialog"
void __fastcall FUN_00495495(TScreenPanel *param_1)
{
  TDigital *this;
  TShape *pTVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055ed48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TRIBE_Screen_Game::_vftable_;
  uStack_4 = 0;
  TPanelSystem::destroyPanel(&panel_system,s_Config_Dialog);
  if (*(TDigital **)&param_1[1].field_0x340 != (TDigital *)0x0) {
    iVar2 = TDigital::is_playing(*(TDigital **)&param_1[1].field_0x340);
    if (iVar2 != 0) {
      TDigital::stop(*(TDigital **)&param_1[1].field_0x340);
    }
    this = *(TDigital **)&param_1[1].field_0x340;
    if (this != (TDigital *)0x0) {
      TDigital::~TDigital(this);
      operator_delete(this);
    }
    *(undefined4 *)&param_1[1].field_0x340 = 0;
  }
  if (*(int *)&param_1[1].field_0x208 != 0) {
    if (*(int *)&param_1[1].field_0x20c != 0) {
      *(undefined4 *)&param_1[1].field_0x20c = 0;
      RGE_Sound::stop(*(RGE_Sound **)&param_1[1].field_0x208);
    }
    *(undefined4 *)&param_1[1].field_0x208 = 0;
  }
  pTVar1 = *(TShape **)(param_1 + 1);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 1) = 0;
  }
  pTVar1 = *(TShape **)&param_1[1].field_0x4;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0x4 = 0;
  }
  pTVar1 = *(TShape **)&param_1[1].field_0x8;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0x8 = 0;
  }
  pTVar1 = *(TShape **)&param_1[1].field_0xc;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0xc = 0;
  }
  pTVar1 = *(TShape **)&param_1[1].field_0x10;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0x10 = 0;
  }
  pTVar1 = *(TShape **)&param_1[1].field_0x14;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0x14 = 0;
  }
  pTVar1 = *(TShape **)&param_1[1].field_0x18;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0x18 = 0;
  }
  pTVar1 = *(TShape **)&param_1[1].field_0x1c;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)&param_1[1].field_0x1c = 0;
  }
  puVar3 = (undefined4 *)&param_1[1].field_0x20;
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
  if (*(int *)&param_1[1].field_0x158 != 0) {
    free(*(int *)&param_1[1].field_0x158);
    *(undefined4 *)&param_1[1].field_0x158 = 0;
  }
  if (*(int *)&param_1[1].field_0x15c != 0) {
    free(*(int *)&param_1[1].field_0x15c);
    *(undefined4 *)&param_1[1].field_0x15c = 0;
  }
  if (*(int *)&param_1[1].field_0x160 != 0) {
    free(*(int *)&param_1[1].field_0x160);
    *(undefined4 *)&param_1[1].field_0x160 = 0;
  }
  if (*(int *)&param_1[1].field_0x164 != 0) {
    free(*(int *)&param_1[1].field_0x164);
    *(undefined4 *)&param_1[1].field_0x164 = 0;
  }
  piVar4 = (int *)&param_1[1].field_0xe4;
  iVar2 = 8;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar4 = (int *)&param_1[1].field_0x50;
  iVar2 = 0x11;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(undefined4 **)&param_1[1].field_0x108 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x108)(1);
    *(undefined4 *)&param_1[1].field_0x108 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x110 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x110)(1);
    *(undefined4 *)&param_1[1].field_0x110 = 0;
  }
  piVar4 = (int *)&param_1[1].field_0x114;
  iVar2 = 8;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(undefined4 **)&param_1[1].field_0x134 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x134)(1);
    *(undefined4 *)&param_1[1].field_0x134 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x138 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x138)(1);
    *(undefined4 *)&param_1[1].field_0x138 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x48 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x48)(1);
    *(undefined4 *)&param_1[1].field_0x48 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x4c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x4c)(1);
    *(undefined4 *)&param_1[1].field_0x4c = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x98 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x98)(1);
    *(undefined4 *)&param_1[1].field_0x98 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x94 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x94)(1);
    *(undefined4 *)&param_1[1].field_0x94 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x9c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x9c)(1);
    *(undefined4 *)&param_1[1].field_0x9c = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0xc8 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xc8)(1);
    *(undefined4 *)&param_1[1].field_0xc8 = 0;
  }
  piVar4 = (int *)&param_1[1].field_0xa0;
  iVar2 = 10;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(undefined4 **)&param_1[1].field_0xe0 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xe0)(1);
    *(undefined4 *)&param_1[1].field_0xe0 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0xdc != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xdc)(1);
    *(undefined4 *)&param_1[1].field_0xdc = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0xd8 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xd8)(1);
    *(undefined4 *)&param_1[1].field_0xd8 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0xd4 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xd4)(1);
    *(undefined4 *)&param_1[1].field_0xd4 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0xd0 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xd0)(1);
    *(undefined4 *)&param_1[1].field_0xd0 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0xcc != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0xcc)(1);
    *(undefined4 *)&param_1[1].field_0xcc = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x104 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x104)(1);
    *(undefined4 *)&param_1[1].field_0x104 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x10c != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x10c)(1);
    *(undefined4 *)&param_1[1].field_0x10c = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x40 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x40)(1);
    *(undefined4 *)&param_1[1].field_0x40 = 0;
  }
  if (*(undefined4 **)&param_1[1].field_0x44 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&param_1[1].field_0x44)(1);
    *(undefined4 *)&param_1[1].field_0x44 = 0;
  }
  uStack_4 = 0xffffffff;
  TScreenPanel::~TScreenPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00495997
// Address: 00495997
// XREFS: None
void __thiscall FUN_00495997(TPanel *param_1,RedrawMode param_2)
{
  TPanel::set_redraw(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004959ad
// Address: 004959ad
// XREFS: None
void FUN_004959ad(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  TPanel *pTVar9;
  
  pTVar9 = TPanelSystem::modalPanel(&panel_system);
  if (pTVar9 != (TPanel *)0x0) {
    iVar1 = *(int *)(param_1 + 0x24);
    iVar2 = *(int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0x2c);
    iVar4 = *(int *)(param_1 + 0x30);
    iVar5 = (pTVar9->clip_rect).left;
    iVar6 = (pTVar9->clip_rect).top;
    iVar7 = (pTVar9->clip_rect).right;
    iVar8 = (pTVar9->clip_rect).bottom;
    if ((((((iVar1 <= iVar5) && (iVar5 <= iVar3)) || ((iVar1 <= iVar7 && (iVar7 <= iVar3)))) ||
         ((iVar5 < iVar1 && (iVar3 < iVar7)))) &&
        (((iVar2 <= iVar6 && (iVar6 <= iVar4)) ||
         (((iVar2 <= iVar8 && (iVar8 <= iVar4)) || ((iVar6 < iVar2 && (iVar4 < iVar8)))))))) ||
       (((((iVar5 <= iVar1 && (iVar1 <= iVar7)) || ((iVar5 <= iVar3 && (iVar3 <= iVar7)))) ||
         ((iVar1 < iVar5 && (iVar7 < iVar3)))) &&
        ((((iVar6 <= iVar2 && (iVar2 <= iVar8)) || ((iVar6 <= iVar4 && (iVar4 <= iVar8)))) ||
         ((iVar2 < iVar6 && (iVar8 < iVar4)))))))) {
      (**(code **)(pTVar9->_padding_ + 0x20))(param_3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00495a89
// Address: 00495a89
// XREFS: None
void __thiscall FUN_00495a89(int param_1,undefined4 param_2)
{
  if (*(int *)(param_1 + 0x14) < 800) {
    (**(code **)(**(int **)(param_1 + 0x4dc) + 0x20))(param_2);
    (**(code **)(**(int **)(param_1 + 0x4f4) + 0x20))(param_2);
  }
  (**(code **)(**(int **)(param_1 + 0x504) + 0x20))(param_2);
  (**(code **)(**(int **)(param_1 + 0x508) + 0x20))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00495ad6
// Address: 00495ad6
// XREFS: None
undefined4 __thiscall FUN_00495ad6(TRIBE_Screen_Game *param_1,long param_2,long param_3)
{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  long lVar4;
  RGE_Player *pRVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  undefined4 *puVar11;
  int aiStack_358 [83];
  undefined4 uStack_20c;
  int iStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  int iStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  int iStack_104;
  int iStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  int iStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int aiStack_40 [4];
  
  TPanel::handle_size((TPanel *)param_1,param_2,param_3);
  if (*(int *)((int)&param_1->main_view + 3) == 0) {
    return 0;
  }
  aiStack_40[3] = 0;
  aiStack_40[2] = 0x495b1a;
  (**(code **)(**(int **)((int)&param_1->log_text + 3) + 0x14))();
  aiStack_40[2] = 1;
  aiStack_40[1] = 0x495b27;
  (**(code **)(**(int **)((int)&param_1->text_line_panel + 3) + 0x14))();
  aiStack_40[1] = 1;
  aiStack_40[0] = 0x495b34;
  (**(code **)(**(int **)((int)&param_1->message_panel + 3) + 0x14))();
  aiStack_40[0] = 1;
  uStack_44 = 0x495b41;
  (**(code **)(**(int **)((int)&param_1->message_panel2 + 3) + 0x14))();
  uStack_44 = 1;
  uStack_48 = 0x495b4e;
  (**(code **)(**(int **)((int)&param_1->message_panel3 + 3) + 0x14))();
  uStack_48 = 1;
  uStack_4c = 0x495b5b;
  (**(code **)(**(int **)((int)&param_1->message_panel4 + 3) + 0x14))();
  uStack_4c = 1;
  uStack_50 = 0x495b68;
  (**(code **)(**(int **)((int)&param_1->message_panel5 + 3) + 0x14))();
  uStack_50 = 1;
  uStack_54 = 0x495b75;
  (**(code **)(**(int **)((int)&param_1->message_panel6 + 3) + 0x14))();
  piVar7 = aiStack_40;
  piVar6 = (int *)((int)param_1->score_panel + 3);
  iVar8 = 8;
  do {
    piVar1 = (int *)*piVar6;
    if (piVar1 != (int *)0x0) {
      iVar9 = *piVar1;
      uStack_54 = 1;
      *piVar7 = piVar1[0x1b];
      uStack_58 = 0x495b96;
      (**(code **)(iVar9 + 0x14))();
    }
    piVar7 = piVar7 + 1;
    piVar6 = piVar6 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if ((*(int *)&param_1->field_0x14 < 0x400) || (*(int *)&param_1->field_0x18 < 0x300)) {
    if ((*(int *)&param_1->field_0x14 < 800) || (*(int *)&param_1->field_0x18 < 600)) {
      uStack_54 = 0;
      uStack_58 = 0;
      uStack_5c = 0;
      uStack_60 = 0;
      uStack_64 = 0x14;
      uStack_68 = 0x14;
      uStack_6c = 0xa0;
      uStack_70 = 0xa0;
      uStack_74 = 4;
      uStack_78 = 4;
      uStack_7c = 4;
      uStack_80 = 0xf0;
      uStack_84 = 7;
      uStack_88 = 0x495fcf;
      (**(code **)(**(int **)((int)&param_1->pop_panel + 3) + 0x18))();
      piVar6 = *(int **)((int)&param_1->tool_box + 3);
      if (piVar6[0x1b] == 0) {
        uStack_88 = 0x14e;
        uStack_8c = 0x280;
        uStack_90 = 0x14;
        uStack_94 = 0;
        uStack_98 = 0x496020;
        (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x1c))();
      }
      else {
        uStack_88 = 0x1e;
        uStack_8c = 0x280;
        uStack_90 = 0x14;
        uStack_94 = 0;
        uStack_98 = 0x495fec;
        (**(code **)(*piVar6 + 0x1c))();
        uStack_98 = 0x130;
        uStack_9c = 0x280;
        uStack_a0 = 0x32;
        uStack_a4 = 0;
        uStack_a8 = 0x496005;
        (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x1c))();
      }
      uStack_a8 = 0x72;
      uStack_ac = 0xdc;
      uStack_b0 = 0x16a;
      uStack_b4 = 0x19b;
      uStack_b8 = 0x49603c;
      (**(code **)(**(int **)((int)&param_1->map_view + 3) + 0x1c))();
      uStack_b8 = 0x10;
      iStack_bc = 0x6a;
      iStack_c0 = 2;
      uStack_c4 = 0x10e;
      uStack_c8 = 0x496052;
      (**(code **)(**(int **)((int)&param_1->age_panel + 3) + 0x1c))();
      uStack_c8 = 0x10;
      uStack_cc = 0x118;
      uStack_d0 = 2;
      uStack_d4 = 2;
      uStack_d8 = 0x496068;
      (**(code **)(**(int **)((int)&param_1->fps_panel + 3) + 0x1c))();
      uStack_d8 = 0x14;
      uStack_dc = 0x10e;
      uStack_e0 = 0;
      uStack_e4 = 0;
      uStack_e8 = 0x49607e;
      (**(code **)(**(int **)((int)&param_1->inven_panel + 3) + 0x1c))();
      uStack_e8 = 0x72;
      uStack_ec = 0x7f;
      uStack_f0 = 0x169;
      uStack_f4 = 5;
      uStack_f8 = 0x496094;
      (**(code **)(**(int **)((int)&param_1->object_panel + 3) + 0x1c))();
      iStack_bc = 0x16a;
      piVar6 = (int *)((int)param_1->button_panel + 3);
      iStack_c0 = 2;
      do {
        iVar9 = 0x88;
        iVar8 = 6;
        do {
          uStack_f8 = 0x36;
          uStack_fc = 0x36;
          iStack_100 = iStack_bc;
          uStack_108 = 0x4960c5;
          iStack_104 = iVar9;
          (**(code **)(*(int *)*piVar6 + 0x1c))();
          iVar2 = *piVar6;
          piVar6 = piVar6 + 1;
          iVar9 = iVar9 + 0x36;
          iVar8 = iVar8 + -1;
          *(undefined1 *)(iVar2 + 0x2c0) = 0;
        } while (iVar8 != 0);
        iStack_bc = iStack_bc + 0x3a;
        iStack_c0 = iStack_c0 + -1;
      } while (iStack_c0 != 0);
      uStack_f8 = 0x35;
      uStack_fc = 0x66;
      iStack_100 = 0x16a;
      iStack_104 = 0x196;
      uStack_108 = 0x496106;
      (**(code **)(**(int **)((int)param_1->button_panel + 0x17) + 0x1c))();
      uStack_108 = 0x35;
      uStack_10c = 0x66;
      uStack_110 = 0x1bb;
      *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x17) + 0x2c0) = 2;
      uStack_114 = 0x196;
      uStack_118 = 0x49612c;
      (**(code **)(**(int **)((int)param_1->button_panel + 0x2f) + 0x1c))();
      uStack_118 = 0x13;
      uStack_11c = 0x48;
      uStack_120 = 0;
      *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x2f) + 0x2c0) = 2;
      uStack_124 = 0x184;
      uStack_128 = 0x49614f;
      (**(code **)(**(int **)((int)param_1->button_panel + 0x33) + 0x1c))();
      uStack_128 = 0x13;
      uStack_12c = 0x6c;
      uStack_130 = 0;
      uStack_134 = 0x1cc;
      uStack_138 = 0x496165;
      (**(code **)(**(int **)((int)param_1->button_panel + 0x37) + 0x1c))();
      uStack_138 = 0x13;
      uStack_13c = 0x48;
      uStack_140 = 0;
      uStack_144 = 0x238;
      uStack_148 = 0x49617b;
      (**(code **)(**(int **)((int)param_1->button_panel + 0x3b) + 0x1c))();
      uStack_148 = 0x1e;
      uStack_14c = 0x1e;
      uStack_150 = 0x1bc;
      uStack_154 = 0x25d;
      uStack_158 = 0x496194;
      (**(code **)(**(int **)((int)param_1->button_panel + 0x3f) + 0x1c))();
      uStack_158 = 0x1e;
      uStack_15c = 0x1e;
      *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x3f) + 0x2c0) = 3;
      uStack_160 = 0x16a;
      uStack_164 = 0x25d;
      uStack_168 = 0x4961bb;
      (**(code **)(**(int **)((int)param_1->button_panel + 0x43) + 0x1c))();
      *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x43) + 0x2c0) = 3;
      *(undefined4 *)((int)&param_1->more_cancel_pic + 3) =
           *(undefined4 *)((int)&param_1->button_other_pic + 3);
      *(undefined2 *)((int)&param_1->cancel_frame + 1) = 0;
      uVar3 = 2;
      goto LAB_004961e1;
    }
    uStack_54 = 0;
    uStack_58 = 0;
    uStack_5c = 0;
    uStack_60 = 0;
    uStack_64 = 0x14;
    uStack_68 = 0x14;
    uStack_6c = 0xa0;
    uStack_70 = 0xa0;
    uStack_74 = 4;
    uStack_78 = 4;
    uStack_7c = 4;
    uStack_80 = 0x140;
    uStack_84 = 7;
    uStack_88 = 0x495dd3;
    (**(code **)(**(int **)((int)&param_1->pop_panel + 3) + 0x18))();
    piVar6 = *(int **)((int)&param_1->tool_box + 3);
    if (piVar6[0x1b] == 0) {
      uStack_88 = 0x1c6;
      uStack_8c = 800;
      uStack_90 = 0x14;
      uStack_94 = 0;
      uStack_98 = 0x495e24;
      (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x1c))();
    }
    else {
      uStack_88 = 0x1e;
      uStack_8c = 800;
      uStack_90 = 0x14;
      uStack_94 = 0;
      uStack_98 = 0x495df0;
      (**(code **)(*piVar6 + 0x1c))();
      uStack_98 = 0x1a8;
      uStack_9c = 800;
      uStack_a0 = 0x32;
      uStack_a4 = 0;
      uStack_a8 = 0x495e09;
      (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x1c))();
    }
    uStack_a8 = 0x72;
    uStack_ac = 0xdc;
    uStack_b0 = 0x1e0;
    uStack_b4 = 0x23b;
    uStack_b8 = 0x495e40;
    (**(code **)(**(int **)((int)&param_1->map_view + 3) + 0x1c))();
    uStack_b8 = 0x10;
    iStack_bc = 0x10c;
    iStack_c0 = 2;
    uStack_c4 = 0x10e;
    uStack_c8 = 0x495e59;
    (**(code **)(**(int **)((int)&param_1->age_panel + 3) + 0x1c))();
    uStack_c8 = 0x10;
    uStack_cc = 0x118;
    uStack_d0 = 2;
    uStack_d4 = 2;
    uStack_d8 = 0x495e6f;
    (**(code **)(**(int **)((int)&param_1->fps_panel + 3) + 0x1c))();
    uStack_d8 = 0x14;
    uStack_dc = 0x10e;
    uStack_e0 = 0;
    uStack_e4 = 0;
    uStack_e8 = 0x495e85;
    (**(code **)(**(int **)((int)&param_1->inven_panel + 3) + 0x1c))();
    uStack_e8 = 0x72;
    uStack_ec = 0x7f;
    uStack_f0 = 0x1e1;
    uStack_f4 = 5;
    uStack_f8 = 0x495e9b;
    (**(code **)(**(int **)((int)&param_1->object_panel + 3) + 0x1c))();
    iStack_bc = 0x1e2;
    piVar6 = (int *)((int)param_1->button_panel + 3);
    iStack_c0 = 2;
    do {
      iVar9 = 0x88;
      iVar8 = 6;
      do {
        uStack_f8 = 0x36;
        uStack_fc = 0x36;
        iStack_100 = iStack_bc;
        uStack_108 = 0x495ecc;
        iStack_104 = iVar9;
        (**(code **)(*(int *)*piVar6 + 0x1c))();
        iVar2 = *piVar6;
        piVar6 = piVar6 + 1;
        iVar9 = iVar9 + 0x36;
        iVar8 = iVar8 + -1;
        *(undefined1 *)(iVar2 + 0x2c0) = 0;
      } while (iVar8 != 0);
      iStack_bc = iStack_bc + 0x3a;
      iStack_c0 = iStack_c0 + -1;
    } while (iStack_c0 != 0);
    uStack_f8 = 0x13;
    uStack_fc = 0x48;
    iStack_100 = 0;
    iStack_104 = 0x224;
    uStack_108 = 0x495f0a;
    (**(code **)(**(int **)((int)param_1->button_panel + 0x33) + 0x1c))();
    uStack_108 = 0x13;
    uStack_10c = 0x6c;
    uStack_110 = 0;
    uStack_114 = 0x26c;
    uStack_118 = 0x495f20;
    (**(code **)(**(int **)((int)param_1->button_panel + 0x37) + 0x1c))();
    uStack_118 = 0x13;
    uStack_11c = 0x48;
    uStack_120 = 0;
    uStack_124 = 0x2d8;
    uStack_128 = 0x495f36;
    (**(code **)(**(int **)((int)param_1->button_panel + 0x3b) + 0x1c))();
    uStack_128 = 0x1e;
    uStack_12c = 0x1e;
    uStack_130 = 0x234;
    uStack_134 = 0x2fd;
    uStack_138 = 0x495f4f;
    (**(code **)(**(int **)((int)param_1->button_panel + 0x3f) + 0x1c))();
    *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x3f) + 0x2c0) = 3;
    uStack_140 = 0x1e2;
    uStack_144 = 0x2fd;
    iVar8 = **(int **)((int)param_1->button_panel + 0x43);
  }
  else {
    uStack_54 = 0;
    uStack_58 = 0;
    uStack_5c = 0;
    uStack_60 = 0;
    uStack_64 = 0x14;
    uStack_68 = 0x14;
    uStack_6c = 0xa0;
    uStack_70 = 0xa0;
    uStack_74 = 4;
    uStack_78 = 4;
    uStack_7c = 4;
    uStack_80 = 0x1b0;
    uStack_84 = 7;
    uStack_88 = 0x495be8;
    (**(code **)(**(int **)((int)&param_1->pop_panel + 3) + 0x18))();
    piVar6 = *(int **)((int)&param_1->tool_box + 3);
    if (piVar6[0x1b] == 0) {
      uStack_88 = 0x26e;
      uStack_8c = 0x400;
      uStack_90 = 0x14;
      uStack_94 = 0;
      uStack_98 = 0x495c39;
      (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x1c))();
    }
    else {
      uStack_88 = 0x1e;
      uStack_8c = 0x400;
      uStack_90 = 0x14;
      uStack_94 = 0;
      uStack_98 = 0x495c05;
      (**(code **)(*piVar6 + 0x1c))();
      uStack_98 = 0x250;
      uStack_9c = 0x400;
      uStack_a0 = 0x32;
      uStack_a4 = 0;
      uStack_a8 = 0x495c1e;
      (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x1c))();
    }
    uStack_a8 = 0x72;
    uStack_ac = 0xdc;
    uStack_b0 = 0x288;
    uStack_b4 = 0x31b;
    uStack_b8 = 0x495c55;
    (**(code **)(**(int **)((int)&param_1->map_view + 3) + 0x1c))();
    uStack_b8 = 0x10;
    iStack_bc = 0x1ec;
    iStack_c0 = 2;
    uStack_c4 = 0x10e;
    uStack_c8 = 0x495c6e;
    (**(code **)(**(int **)((int)&param_1->age_panel + 3) + 0x1c))();
    uStack_c8 = 0x10;
    uStack_cc = 0x118;
    uStack_d0 = 2;
    uStack_d4 = 2;
    uStack_d8 = 0x495c84;
    (**(code **)(**(int **)((int)&param_1->fps_panel + 3) + 0x1c))();
    uStack_d8 = 0x14;
    uStack_dc = 0x10e;
    uStack_e0 = 0;
    uStack_e4 = 0;
    uStack_e8 = 0x495c9a;
    (**(code **)(**(int **)((int)&param_1->inven_panel + 3) + 0x1c))();
    uStack_e8 = 0x72;
    uStack_ec = 0x7f;
    uStack_f0 = 0x289;
    uStack_f4 = 5;
    uStack_f8 = 0x495cb0;
    (**(code **)(**(int **)((int)&param_1->object_panel + 3) + 0x1c))();
    iStack_bc = 0x28a;
    piVar6 = (int *)((int)param_1->button_panel + 3);
    iStack_c0 = 2;
    do {
      iVar9 = 0x88;
      iVar8 = 6;
      do {
        uStack_f8 = 0x36;
        uStack_fc = 0x36;
        iStack_100 = iStack_bc;
        uStack_108 = 0x495ce1;
        iStack_104 = iVar9;
        (**(code **)(*(int *)*piVar6 + 0x1c))();
        iVar2 = *piVar6;
        piVar6 = piVar6 + 1;
        iVar9 = iVar9 + 0x36;
        iVar8 = iVar8 + -1;
        *(undefined1 *)(iVar2 + 0x2c0) = 0;
      } while (iVar8 != 0);
      iStack_bc = iStack_bc + 0x3a;
      iStack_c0 = iStack_c0 + -1;
    } while (iStack_c0 != 0);
    uStack_f8 = 0x13;
    uStack_fc = 0x48;
    iStack_100 = 0;
    iStack_104 = 0x304;
    uStack_108 = 0x495d1f;
    (**(code **)(**(int **)((int)param_1->button_panel + 0x33) + 0x1c))();
    uStack_108 = 0x13;
    uStack_10c = 0x6c;
    uStack_110 = 0;
    uStack_114 = 0x34c;
    uStack_118 = 0x495d35;
    (**(code **)(**(int **)((int)param_1->button_panel + 0x37) + 0x1c))();
    uStack_118 = 0x13;
    uStack_11c = 0x48;
    uStack_120 = 0;
    uStack_124 = 0x3b8;
    uStack_128 = 0x495d4b;
    (**(code **)(**(int **)((int)param_1->button_panel + 0x3b) + 0x1c))();
    uStack_128 = 0x1e;
    uStack_12c = 0x1e;
    uStack_130 = 0x2dc;
    uStack_134 = 0x3dd;
    uStack_138 = 0x495d64;
    (**(code **)(**(int **)((int)param_1->button_panel + 0x3f) + 0x1c))();
    *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x3f) + 0x2c0) = 3;
    uStack_140 = 0x28a;
    uStack_144 = 0x3dd;
    iVar8 = **(int **)((int)param_1->button_panel + 0x43);
  }
  uStack_138 = 0x1e;
  uStack_13c = 0x1e;
  uStack_148 = 0x495f76;
  (**(code **)(iVar8 + 0x1c))();
  *(undefined1 *)(*(int *)((int)param_1->button_panel + 0x43) + 0x2c0) = 3;
  *(undefined4 *)((int)&param_1->more_cancel_pic + 3) =
       *(undefined4 *)((int)&param_1->button_cmd_pic + 3);
  *(undefined2 *)((int)&param_1->cancel_frame + 1) = 0xb;
  uVar3 = 10;
LAB_004961e1:
  uStack_148 = 0;
  uStack_14c = 0;
  uStack_150 = 0;
  iVar8 = **(int **)((int)&param_1->pause_text + 3);
  uStack_154 = 0;
  uStack_158 = 0x3c;
  uStack_15c = 0x3c;
  uStack_160 = 600;
  uStack_164 = 600;
  uStack_168 = 4;
  uStack_16c = 4;
  uStack_170 = 4;
  uStack_174 = 4;
  uStack_178 = 2;
  *(undefined2 *)((int)&param_1->unselect_frame + 1) = uVar3;
  *(undefined2 *)&param_1->field_0x4b4 = uVar3;
  uStack_17c = 0x49621a;
  (**(code **)(iVar8 + 0x18))();
  uStack_17c = 0;
  uStack_180 = 0;
  uStack_184 = 0;
  uStack_188 = 0;
  uStack_18c = 0x14;
  uStack_190 = 0x14;
  uStack_194 = 0x78;
  uStack_198 = 0x78;
  uStack_19c = 4;
  uStack_1a0 = 4;
  uStack_1a4 = 4;
  uStack_1a8 = 4;
  uStack_1ac = 7;
  uStack_1b0 = 0x49623f;
  (**(code **)(**(int **)((int)&param_1->time_panel + 3) + 0x18))();
  iVar8 = 4;
  puVar11 = (undefined4 *)((int)param_1->countdown_clock + 3);
  iVar9 = 10;
  do {
    uStack_1b0 = 0;
    uStack_1b4 = 0;
    uStack_1b8 = 0;
    uStack_1bc = 0;
    uStack_1c0 = 0x14;
    uStack_1c4 = 0x14;
    uStack_1c8 = 0xaa;
    uStack_1cc = 0xaa;
    uStack_1d0 = 4;
    uStack_1d4 = 4;
    uStack_1dc = 4;
    uStack_1e0 = 9;
    uStack_1e4 = 0x496275;
    iStack_1d8 = iVar8;
    (**(code **)(*(int *)*puVar11 + 0x18))();
    puVar11 = puVar11 + 1;
    iVar8 = iVar8 + 0x14;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  piVar6 = *(int **)((int)&param_1->text_line_panel + 3);
  if (*(char *)(*(int *)((int)&param_1->world + 3) + 0x11c) == '\0') {
    uStack_1b0 = 0;
    uStack_1b4 = 0;
    uStack_1b8 = 0;
    uStack_1bc = 0;
    uStack_1c0 = 0x22;
    uStack_1c4 = 0x22;
    uStack_1c8 = 0;
    uStack_1cc = 0;
    uStack_1d0 = 4;
    uStack_1d4 = 4;
    iStack_1d8 = 0;
    uStack_1dc = 4;
    uStack_1e0 = 8;
    uStack_1e4 = 0x4962d7;
    (**(code **)(*piVar6 + 0x18))();
  }
  else {
    uStack_1b0 = 0;
    uStack_1b4 = 0;
    uStack_1b8 = 0;
    uStack_1bc = 0;
    uStack_1c0 = 0x22;
    uStack_1c4 = 0x22;
    uStack_1c8 = 0;
    uStack_1cc = 0;
    uStack_1d0 = 4;
    uStack_1d4 = 0xb8;
    iStack_1d8 = 0;
    uStack_1dc = 4;
    uStack_1e0 = 8;
    uStack_1e4 = 0x4962b6;
    (**(code **)(*piVar6 + 0x18))();
  }
  uStack_1e4 = 0x4962e2;
  lVar4 = TPanel::width(*(TPanel **)((int)&param_1->main_view + 3));
  uStack_1e4 = 0;
  uStack_1e8 = 0;
  uStack_1ec = 0;
  uStack_1f0 = 0;
  uStack_1f4 = 0x14;
  uStack_1f8 = 0x14;
  uStack_1fc = 0;
  uStack_200 = 0;
  aiStack_358[0x52] = (lVar4 + -500) / 2;
  uStack_204 = 8;
  uStack_20c = 8;
  aiStack_358[0x51] = 7;
  aiStack_358[0x50] = 0x49630f;
  iStack_208 = aiStack_358[0x52];
  (**(code **)(**(int **)((int)&param_1->quit_message_panel + 3) + 0x18))();
  aiStack_358[0x50] = *(undefined4 *)((int)&param_1->text_line_panel + 3);
  aiStack_358[0x4f] = 0;
  aiStack_358[0x4e] = 0;
  aiStack_358[0x4d] = 0;
  aiStack_358[0x4c] = 0x14;
  aiStack_358[0x4b] = 0x14;
  aiStack_358[0x4a] = 0;
  aiStack_358[0x49] = 0;
  aiStack_358[0x48] = 0;
  aiStack_358[0x47] = 4;
  aiStack_358[0x46] = 0;
  aiStack_358[0x45] = 4;
  aiStack_358[0x44] = 8;
  aiStack_358[0x43] = 0x496339;
  (**(code **)(**(int **)((int)&param_1->message_panel + 3) + 0x18))();
  aiStack_358[0x43] = *(undefined4 *)((int)&param_1->message_panel + 3);
  aiStack_358[0x42] = 0;
  aiStack_358[0x41] = 0;
  aiStack_358[0x40] = 0;
  aiStack_358[0x3f] = 0x14;
  aiStack_358[0x3e] = 0x14;
  aiStack_358[0x3d] = 0;
  aiStack_358[0x3c] = 0;
  aiStack_358[0x3b] = 0;
  aiStack_358[0x3a] = 4;
  aiStack_358[0x39] = 0;
  aiStack_358[0x38] = 4;
  aiStack_358[0x37] = 8;
  aiStack_358[0x36] = 0x496363;
  (**(code **)(**(int **)((int)&param_1->message_panel2 + 3) + 0x18))();
  aiStack_358[0x36] = *(undefined4 *)((int)&param_1->message_panel2 + 3);
  aiStack_358[0x35] = 0;
  aiStack_358[0x34] = 0;
  aiStack_358[0x33] = 0;
  aiStack_358[0x32] = 0x14;
  aiStack_358[0x31] = 0x14;
  aiStack_358[0x30] = 0;
  aiStack_358[0x2f] = 0;
  aiStack_358[0x2e] = 0;
  aiStack_358[0x2d] = 4;
  aiStack_358[0x2c] = 0;
  aiStack_358[0x2b] = 4;
  aiStack_358[0x2a] = 8;
  aiStack_358[0x29] = 0x49638d;
  (**(code **)(**(int **)((int)&param_1->message_panel3 + 3) + 0x18))();
  aiStack_358[0x29] = *(undefined4 *)((int)&param_1->message_panel3 + 3);
  aiStack_358[0x28] = 0;
  aiStack_358[0x27] = 0;
  aiStack_358[0x26] = 0;
  aiStack_358[0x25] = 0x14;
  aiStack_358[0x24] = 0x14;
  aiStack_358[0x23] = 0;
  aiStack_358[0x22] = 0;
  aiStack_358[0x21] = 0;
  aiStack_358[0x20] = 4;
  aiStack_358[0x1f] = 0;
  aiStack_358[0x1e] = 4;
  aiStack_358[0x1d] = 8;
  aiStack_358[0x1c] = 0x4963b7;
  (**(code **)(**(int **)((int)&param_1->message_panel4 + 3) + 0x18))();
  aiStack_358[0x1c] = *(undefined4 *)((int)&param_1->message_panel4 + 3);
  aiStack_358[0x1b] = 0;
  aiStack_358[0x1a] = 0;
  aiStack_358[0x19] = 0;
  aiStack_358[0x18] = 0x14;
  aiStack_358[0x17] = 0x14;
  aiStack_358[0x16] = 0;
  aiStack_358[0x15] = 0;
  aiStack_358[0x14] = 0;
  aiStack_358[0x13] = 4;
  aiStack_358[0x12] = 0;
  aiStack_358[0x11] = 4;
  aiStack_358[0x10] = 8;
  aiStack_358[0xf] = 0x4963e1;
  (**(code **)(**(int **)((int)&param_1->message_panel5 + 3) + 0x18))();
  aiStack_358[0xf] = *(undefined4 *)((int)&param_1->message_panel5 + 3);
  aiStack_358[0xe] = 0;
  aiStack_358[0xd] = 0;
  aiStack_358[0xc] = 0;
  aiStack_358[0xb] = 0x14;
  aiStack_358[10] = 0x14;
  aiStack_358[9] = 0;
  aiStack_358[8] = 0;
  aiStack_358[7] = 0;
  aiStack_358[6] = 4;
  aiStack_358[5] = 0;
  aiStack_358[4] = 4;
  aiStack_358[3] = 8;
  aiStack_358[2] = 0x49640b;
  (**(code **)(**(int **)((int)&param_1->message_panel6 + 3) + 0x18))();
  iVar8 = 0x22;
  puVar11 = (undefined4 *)((int)param_1->chat_panel + 3);
  iVar9 = 8;
  do {
    aiStack_358[2] = 0x14;
    aiStack_358[1] = 0x26c;
    aiStack_358[0] = iVar8;
    (**(code **)(*(int *)*puVar11 + 0x1c))(4);
    puVar11 = puVar11 + 1;
    iVar8 = iVar8 + 0x14;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  sVar10 = 7;
  do {
    piVar6 = *(int **)((int)param_1->score_panel + sVar10 * 4 + 3);
    if (piVar6 != (int *)0x0) {
      if (sVar10 == 7) {
        aiStack_358[2] = 0;
      }
      else {
        aiStack_358[2] = *(undefined4 *)((int)param_1->score_panel + sVar10 * 4 + 7);
      }
      aiStack_358[1] = 0;
      aiStack_358[0] = 0;
      (**(code **)(*piVar6 + 0x18))(10,4,0,4,(sVar10 != 7) - 1U & 4,200,200,0x14,0x14,0);
    }
    sVar10 = sVar10 + -1;
  } while (-1 < sVar10);
  aiStack_358[2] = 0;
  aiStack_358[1] = 0x49649c;
  (**(code **)(**(int **)((int)&param_1->text_line_panel + 3) + 0x14))();
  aiStack_358[1] = 0;
  aiStack_358[0] = 0x4964a9;
  (**(code **)(**(int **)((int)&param_1->message_panel + 3) + 0x14))();
  aiStack_358[0] = 0;
  (**(code **)(**(int **)((int)&param_1->message_panel2 + 3) + 0x14))();
  (**(code **)(**(int **)((int)&param_1->message_panel3 + 3) + 0x14))(0);
  (**(code **)(**(int **)((int)&param_1->message_panel4 + 3) + 0x14))(0);
  (**(code **)(**(int **)((int)&param_1->message_panel5 + 3) + 0x14))(0);
  (**(code **)(**(int **)((int)&param_1->message_panel6 + 3) + 0x14))(0);
  piVar7 = aiStack_358;
  piVar6 = (int *)((int)param_1->score_panel + 3);
  iVar8 = 8;
  do {
    if ((int *)*piVar6 != (int *)0x0) {
      (**(code **)(*(int *)*piVar6 + 0x14))(*piVar7);
    }
    piVar7 = piVar7 + 1;
    piVar6 = piVar6 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  pRVar5 = RGE_Base_Game::get_player(rge_base_game);
  iVar8 = (int)pRVar5->id;
  pRVar5 = RGE_Base_Game::get_player(rge_base_game);
  TRIBE_Screen_Game::player_changed(param_1,(int)pRVar5->id,iVar8);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00496543
// Address: 00496543
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_game_c: "C:\msdev\work\age1_x1\scr_game.cpp"
// [HELPER] s_Help_Dialog: "Help Dialog"
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
undefined4 __fastcall FUN_00496543(int *param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  TPanel *pTVar7;
  ulong uVar8;
  ulong uStack_4;
  
  if (param_1[8] == 0) {
    return 0;
  }
  if (param_1[0x1c] == 0) {
    return 0;
  }
  if (param_1[0x1b] == 0) {
    return 0;
  }
  if (rge_base_game->prog_active == 0) {
    return 0;
  }
  iVar5 = IsIconic(*(undefined4 *)(param_1[8] + 4));
  if (iVar5 != 0) {
    return 0;
  }
  uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x5aa);
  if (((param_1[0xe] != 2) && (iVar5 = TPanel::get_focus((TPanel *)param_1[0x12e]), iVar5 == 0)) &&
     (pTVar7 = TPanelSystem::panel(&panel_system,s_Send_Quick_Message_Dialog),
     (TPanel *)param_1[0xf] != pTVar7)) {
    pTVar7 = TPanelSystem::panel(&panel_system,s_Help_Dialog);
    bVar4 = false;
    if ((TPanel *)param_1[0xf] != pTVar7) goto LAB_00496603;
  }
  bVar4 = true;
LAB_00496603:
  if (param_1[0xe] != 0) {
    if (bVar4) {
      for (puVar1 = (undefined4 *)param_1[0x16]; puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)puVar1[2]) {
        (**(code **)(*(int *)*puVar1 + 0x20))(param_1[0xe]);
      }
      piVar2 = (int *)param_1[0x10];
      if ((piVar2 != (int *)0x0) && (piVar2[0x1f] != 0)) {
        (**(code **)(*piVar2 + 0x24))(param_1,param_1,param_1[0xe]);
      }
      (**(code **)(*param_1 + 0x30))();
    }
    param_1[0xe] = 0;
    param_1[0x21] = 1;
  }
  uStack_4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x5c2);
  uStack_4 = uStack_4 - uVar6;
  for (piVar2 = (int *)param_1[0x16]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
    uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x5c9);
    piVar3 = (int *)*piVar2;
    if ((bVar4) || (piVar3 == (int *)param_1[0xf])) {
      (**(code **)(*piVar3 + 0x54))();
    }
    uVar8 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x5d0);
    if ((piVar3 != (int *)param_1[0x12e]) && (piVar3 != (int *)param_1[0x12f])) {
      uStack_4 = uStack_4 + (uVar8 - uVar6);
    }
  }
  RGE_Base_Game::add_to_timing(rge_base_game,0x11,uStack_4);
  param_1[0x21] = 0;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004966f9
// Address: 004966f9
// XREFS: None
long __fastcall FUN_004966f9(TRIBE_Screen_Game *param_1)
{
  int iVar1;
  TRIBE_Screen_Game *pTVar2;
  int iVar3;
  long lVar4;
  
  color_log('_','_',5);
  if (rge_base_game->input_enabled == 0) {
    color_log('_','L',5);
    RGE_Base_Game::enable_input(rge_base_game);
  }
  color_log('_','\x16',5);
  iVar1 = rge_base_game->prog_mode;
  if (((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 5)) {
    pTVar2 = (TRIBE_Screen_Game *)TPanelSystem::currentPanel(&panel_system);
    if (pTVar2 == param_1) {
      iVar3 = TPanel::get_focus(*(TPanel **)((int)&param_1->main_view + 3));
      if (iVar3 != 0) {
        color_log('_','E',5);
        TRIBE_Screen_Game::handle_anim_pal(param_1);
      }
    }
  }
  if ((iVar1 == 4) || (iVar1 == 6)) {
    color_log('_','2',5);
    TRIBE_Screen_Game::handle_terrain_sound(param_1);
    color_log('_',0xba,5);
    TRIBE_Screen_Game::handle_mouse_pointing_at(param_1);
  }
  color_log('_','$',5);
  lVar4 = TPanel::handle_idle((TPanel *)param_1);
  color_log('_','_',5);
  return lVar4;
}

// --------------------------------------------------

// Function: FUN_004967f6
// Address: 004967f6
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_game_c: "C:\msdev\work\age1_x1\scr_game.cpp"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Help_Dialog: "Help Dialog"
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
// [HELPER] s_lost_wav: "lost.wav"
// [HELPER] s_won_wav: "won.wav"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004967f6(TRIBE_Screen_Game *param_1)
{
  uint uVar1;
  char cVar2;
  char cVar3;
  ulong uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  RGE_Player *pRVar10;
  TPanel *pTVar11;
  TDigital *pTVar12;
  int *piVar13;
  TRIBE_Screen_Game *pTVar14;
  int iVar15;
  int iVar16;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar17;
  long lVar18;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ed76;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar16 = 0;
  iStack_20 = 0;
  color_log('$','$',5);
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x63f);
  if (uVar4 - *(int *)((int)&param_1->last_update_time + 3) <
      *(uint *)((int)&param_1->update_interval + 3)) goto LAB_00497038;
  cVar2 = (char)rge_base_game->prog_mode;
  if (cVar2 != '\x06') {
    color_log('$','2',5);
    iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
    if (iVar5 == 0) {
      iStack_24 = 1;
    }
    else {
      uVar4 = RGE_Base_Game::get_last_single_time(rge_base_game,2);
      uVar6 = RGE_Base_Game::get_last_single_time(rge_base_game,3);
      uVar7 = RGE_Base_Game::get_last_world_update_count(rge_base_game);
      if (uVar7 == 0) {
LAB_004968e3:
        uVar9 = 1;
      }
      else {
        uVar7 = RGE_Base_Game::get_last_world_update_count(rge_base_game);
        uVar8 = RGE_Base_Game::get_last_time(rge_base_game,1);
        uVar9 = uVar8 / uVar7;
        if (uVar9 == 0) goto LAB_004968e3;
      }
      iVar5 = TCommunications_Handler::WhoAmI(comm);
      uVar1 = comm->Speed->PlayerAvgFramesMsec[iVar5];
      if ((((multi_updates == 0) || (uVar1 < 0x43)) || (0x7d < uVar1)) ||
         (iStack_24 = 2, _DAT_00572ce0 < (float)uVar9 / (float)(int)(uVar4 + uVar6))) {
        iStack_24 = 1;
      }
      RGE_Base_Game::set_last_single_time(rge_base_game,2,0);
      RGE_Base_Game::set_last_single_time(rge_base_game,3,0);
    }
    iStack_1c = 0;
    if (iStack_24 != 0) {
      do {
        color_log('$','L',5);
        color_log('$','$',1);
        uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x692);
        if (start_paused == 0) {
          if (*(int *)&param_1->field_0x7b4 == 0) {
            cVar3 = (**(code **)(**(int **)((int)&param_1->world + 3) + 0xbc))();
            if (out_of_sync2 != 0) goto LAB_00497046;
            if (cVar3 == '\x01') {
              piVar13 = *(int **)((int)&param_1->main_view + 3);
              *(undefined4 *)&param_1->field_0x7b4 = 1;
              (**(code **)(*piVar13 + 0xf0))();
              RGE_View::set_selection_area(*(RGE_View **)((int)&param_1->main_view + 3),-1,-1,-1,-1)
              ;
              (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
              TRIBE_Screen_Game::command_unselect(param_1);
              iVar16 = RGE_Base_Game::multiplayerGame(rge_base_game);
              if (iVar16 != 0) {
                TRIBE_World::send_zone_score_info(*(TRIBE_World **)((int)&param_1->world + 3));
              }
            }
          }
          else {
            cVar3 = '\x01';
          }
        }
        else {
          cVar3 = '\0';
          (**(code **)(rge_base_game->_padding_ + 0xc))(6);
        }
        if (out_of_sync2 != 0) goto LAB_00497046;
        uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x6bb);
        *(ulong *)((int)&param_1->last_update_time + 3) = uVar6;
        if (*(int *)(*(int *)((int)&param_1->world + 3) + 0xc) != 0) {
          RGE_Base_Game::add_to_timing(rge_base_game,1,uVar6 - uVar4);
          RGE_Base_Game::increment_world_update_count(rge_base_game);
        }
        color_log('$',0xba,1);
        if (*(int *)&param_1->field_0x7a4 != 0) {
          TRIBE_Screen_Game::reset_clocks(param_1);
          *(undefined4 *)&param_1->field_0x7a4 = 0;
        }
        if (*(int *)&param_1->field_0x7b0 != 0) {
          TRIBE_Screen_Game::command_view_selected(param_1);
        }
        pRVar10 = RGE_Base_Game::get_player(rge_base_game);
        if ((*(RGE_Static_Object **)((int)&param_1->game_obj + 3) != pRVar10->selected_obj) ||
           (pRVar10 = RGE_Base_Game::get_player(rge_base_game),
           *(short *)&param_1->field_0x5cc != pRVar10->sel_count)) {
          pRVar10 = RGE_Base_Game::get_player(rge_base_game);
          TRIBE_Panel_Object::set_object
                    (*(TRIBE_Panel_Object **)((int)&param_1->object_panel + 3),pRVar10->selected_obj
                    );
          TRIBE_Screen_Game::object_changed(param_1);
        }
        color_log('$','T',5);
        if ((start_paused == 0) &&
           (((cVar3 == '\x01' ||
             (iVar16 = *(int *)((int)&param_1->world + 3),
             *(char *)(*(int *)(*(int *)(iVar16 + 0x40) + *(short *)(iVar16 + 0x7c) * 4) + 0x80) ==
             '\x02')) || (*(int *)&param_1->field_0x730 == 1)))) {
          if (cVar2 == '\x05') {
            if (*(int *)&param_1->field_0x720 == 0) {
              iVar16 = *(int *)((int)&param_1->world + 3);
              iVar5 = 1;
              iVar15 = (int)*(short *)(iVar16 + 0x3c);
              if (1 < iVar15) {
                piVar13 = *(int **)(iVar16 + 0x40);
                do {
                  piVar13 = piVar13 + 1;
                  if (*(char *)(*piVar13 + 0x80) == '\0') break;
                  iVar5 = iVar5 + 1;
                } while (iVar5 < iVar15);
              }
            }
            else {
              uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x734);
              if (5000 < uVar4 - *(int *)&param_1->field_0x71c) {
                color_log('$','\x16',5);
                *(undefined4 *)&param_1->field_0x720 = 0;
                iVar16 = RGE_Base_Game::multiplayerGame(rge_base_game);
                if (iVar16 == 0) {
                  (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0xf0))();
                  RGE_View::set_selection_area
                            (*(RGE_View **)((int)&param_1->main_view + 3),-1,-1,-1,-1);
                  (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
                  TRIBE_Screen_Game::command_unselect(param_1);
                  TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
                  goto LAB_00497038;
                }
                iVar16 = RGE_Base_Game::get_paused(rge_base_game);
                if (iVar16 == 0) {
                  (**(code **)(**(int **)((int)&param_1->pause_text + 3) + 0x14))(0);
                }
                RGE_Base_Game::set_map_visible(rge_base_game,'\x01');
                RGE_Base_Game::set_map_fog(rge_base_game,'\0');
                (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x20))(2);
                (**(code **)(**(int **)((int)&param_1->map_view + 3) + 0x20))(2);
                (**(code **)(**(int **)((int)&param_1->quit_message_panel + 3) + 0x14))(1);
                (**(code **)(**(int **)((int)&param_1->pop_panel + 3) + 0x14))(0);
              }
            }
          }
          else {
            color_log('$','E',5);
            TRIBE_Screen_Game::command_cancel(param_1);
            TRIBE_Screen_Game::command_unselect(param_1);
            TMessagePanel::remove_message(*(TMessagePanel **)((int)&param_1->text_line_panel + 3));
            TMessagePanel::remove_message(*(TMessagePanel **)((int)&param_1->message_panel + 3));
            TMessagePanel::remove_message(*(TMessagePanel **)((int)&param_1->message_panel2 + 3));
            TMessagePanel::remove_message(*(TMessagePanel **)((int)&param_1->message_panel3 + 3));
            TMessagePanel::remove_message(*(TMessagePanel **)((int)&param_1->message_panel4 + 3));
            TMessagePanel::remove_message(*(TMessagePanel **)((int)&param_1->message_panel5 + 3));
            TMessagePanel::remove_message(*(TMessagePanel **)((int)&param_1->message_panel6 + 3));
            (**(code **)(rge_base_game->_padding_ + 0xc))(5);
            pTVar11 = TPanelSystem::mouseOwner(&panel_system);
            if (pTVar11 != (TPanel *)0x0) {
              pTVar11 = TPanelSystem::mouseOwner(&panel_system);
              TPanel::release_mouse(pTVar11);
            }
            TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
            TPanel::set_curr_child((TPanel *)param_1,*(TPanel **)((int)&param_1->main_view + 3));
            TRIBE_Game::close_game_screens((TRIBE_Game *)rge_base_game,0);
            (**(code **)(**(int **)((int)&param_1->pause_text + 3) + 0x14))(1);
            pRVar10 = RGE_Base_Game::get_player(rge_base_game);
            piVar13 = *(int **)((int)&param_1->pause_text + 3);
            if (pRVar10->game_status == '\x01') {
              (**(code **)(*piVar13 + 0xe4))(0x232c);
            }
            else {
              (**(code **)(*piVar13 + 0xe4))(0x232d);
            }
            (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x20))(1);
            if ((rge_base_game->prog_info->use_sound != 0) &&
               (rge_base_game->sound_system != (TSound_Driver *)0x0)) {
              pTVar12 = *(TDigital **)&param_1->field_0x7b8;
              if (pTVar12 != (TDigital *)0x0) {
                TDigital::~TDigital(pTVar12);
                operator_delete(pTVar12);
              }
              pRVar10 = RGE_Base_Game::get_player(rge_base_game);
              if (pRVar10->game_status == '\x01') {
                pTVar12 = (TDigital *)operator_new(0x3c);
                uStack_4 = 0;
                if (pTVar12 == (TDigital *)0x0) goto LAB_00496d51;
                lVar18 = 0xc490;
                pcVar17 = s_won_wav;
LAB_00496d3e:
                pTVar12 = (TDigital *)
                          TDigital::TDigital(pTVar12,rge_base_game->sound_system,pcVar17,lVar18);
              }
              else {
                pTVar12 = (TDigital *)operator_new(0x3c);
                uStack_4 = 1;
                if (pTVar12 != (TDigital *)0x0) {
                  lVar18 = 0xc491;
                  pcVar17 = s_lost_wav;
                  goto LAB_00496d3e;
                }
LAB_00496d51:
                pTVar12 = (TDigital *)0x0;
              }
              uStack_4 = 0xffffffff;
              *(TDigital **)&param_1->field_0x7b8 = pTVar12;
              if (pTVar12 != (TDigital *)0x0) {
                TDigital::load(pTVar12,(char *)0x0,-1);
                TDigital::play(*(TDigital **)&param_1->field_0x7b8);
              }
            }
            uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x72c);
            *(ulong *)&param_1->field_0x71c = uVar4;
            *(undefined4 *)&param_1->field_0x720 = 1;
          }
        }
        iVar5 = *(int *)((int)&param_1->world + 3);
        iVar16 = *(int *)(iVar5 + 0xc);
        if (((iVar16 != 0) && (*(uint *)(rge_base_game[1].timing_text + 0x38) != 0)) &&
           (*(uint *)(rge_base_game[1].timing_text + 0x38) <= *(uint *)(iVar5 + 4))) {
          RGE_Base_Game::close(rge_base_game);
          goto LAB_00497038;
        }
        iVar16 = iStack_20 + iVar16;
        iStack_1c = iStack_1c + 1;
        iStack_20 = iVar16;
      } while (iStack_1c < iStack_24);
    }
  }
  pTVar14 = (TRIBE_Screen_Game *)TPanelSystem::currentPanel(&panel_system);
  if (pTVar14 == param_1) {
    color_log('\x16','L',5);
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x79c);
    if (iVar16 != 0) {
      RGE_Base_Game::get_player(rge_base_game);
      iVar5 = __ftol();
      if (iVar5 != *(int *)&param_1->field_0x710) {
        TRIBE_Screen_Game::age_changed(param_1);
      }
      iVar5 = *(int *)((int)param_1->score_panel + 3);
      if (((iVar5 != 0) && (*(int *)(iVar5 + 0x6c) != 0)) &&
         (*(uint *)&param_1->field_0x7a8 <= uVar4 - *(int *)&param_1->field_0x7ac)) {
        TRIBE_Screen_Game::reset_score_display(param_1);
        uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x7a8);
        *(ulong *)&param_1->field_0x7ac = uVar6;
      }
    }
    iVar5 = TPanel::get_focus(*(TPanel **)((int)&param_1->main_view + 3));
    if (((iVar5 != 0) ||
        (pTVar11 = TPanelSystem::panel(&panel_system,s_Send_Quick_Message_Dialog),
        *(TPanel **)&param_1->field_0x3c == pTVar11)) ||
       (pTVar11 = TPanelSystem::panel(&panel_system,s_Help_Dialog),
       *(TPanel **)&param_1->field_0x3c == pTVar11)) {
      color_log('\x16','T',5);
      if ((iVar16 != 0) || (*(uint *)&param_1->field_0x728 <= uVar4 - *(int *)&param_1->field_0x72c)
         ) {
        (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x20))(1);
        *(ulong *)&param_1->field_0x72c = uVar4;
      }
      if ((iVar16 != 0) &&
         (*(uint *)((int)&param_1->map_redraw_interval + 3) <=
          uVar4 - *(int *)((int)&param_1->last_map_redraw_time + 3))) {
        (**(code **)(**(int **)((int)&param_1->map_view + 3) + 0x20))(1);
        *(ulong *)((int)&param_1->last_map_redraw_time + 3) = uVar4;
      }
      color_log('\x16','$',5);
      if (*(int *)(*(int *)((int)&param_1->main_view + 3) + 0x38) != 0) {
        RGE_Base_Game::draw_window(rge_base_game);
      }
    }
  }
LAB_00497038:
  color_log('$','_',5);
LAB_00497046:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049709e
// Address: 0049709e
// XREFS: None
// [HELPER] s_CloseProgramDialog: "CloseProgramDialog"
long __thiscall
FUN_0049709e(TRIBE_Screen_Game *param_1,void *param_2,uint param_3,uint param_4,long param_5)
{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  long lVar5;
  
  if ((((param_3 == 0x104) && (param_4 == 0x79)) && (*(int *)&param_1->field_0x78 != 0)) &&
     (*(int *)&param_1->field_0x3c == *(int *)((int)&param_1->main_view + 3))) {
    TRIBE_Screen_Game::command_menu(param_1);
    return 1;
  }
  if (((param_3 == 0x101) && (*(int *)&param_1->field_0x78 != 0)) &&
     (iVar4 = TPanel::get_focus(*(TPanel **)((int)&param_1->main_view + 3)), iVar4 != 0)) {
    if ((param_4 == 0x72) || (param_4 == 0x13)) {
      sVar1 = GetKeyState(0x12);
      sVar2 = GetKeyState(0x11);
      sVar3 = GetKeyState(0x10);
      if ((-1 < sVar1) && ((-1 < sVar2 && (-1 < sVar3)))) {
        TRIBE_Screen_Game::command_pause(param_1);
      }
    }
  }
  else if (param_3 == 0x10) {
    if (confirmed_close == 0) {
      confirmed_close = 1;
      iVar4 = rge_base_game->prog_mode;
      if (((((iVar4 == 5) || (iVar4 == 4)) || (iVar4 == 6)) || (iVar4 == 7)) &&
         (iVar4 = IsIconic(*(undefined4 *)(*(int *)&param_1->field_0x20 + 4)), iVar4 == 0)) {
        TEasy_Panel::popupYesNoDialog((TEasy_Panel *)param_1,0xc1d,&s_CloseProgramDialog,0x1c2,100);
        return 1;
      }
    }
  }
  else if (param_3 == 0x208) {
    TRIBE_Game::goto_notification_loc((TRIBE_Game *)rge_base_game);
  }
  lVar5 = TPanel::wnd_proc((TPanel *)param_1,param_2,param_3,param_4,param_5);
  return lVar5;
}

// --------------------------------------------------

// Function: FUN_00497202
// Address: 00497202
// XREFS: None
void __thiscall
FUN_00497202(TEasy_Panel *param_1,uchar param_2,long param_3,long param_4,int param_5,int param_6)
{
  TMessagePanel::remove_message((TMessagePanel *)param_1[1]._padding_);
  TMessagePanel::remove_message((TMessagePanel *)param_1[1]._padding_);
  TMessagePanel::remove_message((TMessagePanel *)param_1[1]._padding_);
  TMessagePanel::remove_message((TMessagePanel *)param_1[1]._padding_);
  TMessagePanel::remove_message((TMessagePanel *)param_1[1]._padding_);
  TMessagePanel::remove_message((TMessagePanel *)param_1[1]._padding_);
  TEasy_Panel::handle_mouse_down(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_00497279
// Address: 00497279
// XREFS: None
void __thiscall FUN_00497279(TPanel *param_1,uint param_2,long param_3)
{
  TPanel::handle_user_command(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_00497292
// Address: 00497292
// XREFS: None
void __fastcall FUN_00497292(int param_1)
{
  (**(code **)(**(int **)(param_1 + 0x584) + 0xe4))(0x2329);
  if ((*(int **)(param_1 + 0x584))[0x1b] == 0) {
    (**(code **)(**(int **)(param_1 + 0x584) + 0x14))(1);
    (**(code **)(**(int **)(param_1 + 0x584) + 0x20))(1);
  }
  (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_004972e6
// Address: 004972e6
// XREFS: None
void __fastcall FUN_004972e6(int param_1)
{
  if ((*(int **)(param_1 + 0x584))[0x1b] != 0) {
    (**(code **)(**(int **)(param_1 + 0x584) + 0x14))(0);
    (**(code **)(**(int **)(param_1 + 0x584) + 0x20))(1);
    (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00497323
// Address: 00497323
// XREFS: None
// [HELPER] s_____RECEIVED_CHAT___u___s: "$$$ RECEIVED CHAT @%u: %s"
void __thiscall FUN_00497323(int param_1,int param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char acStack_100 [256];
  
  pcVar2 = TChat::GetChatMsg(chat,param_2);
  uVar3 = 0xffffffff;
  do {
    pcVar6 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar5 = *(int *)(param_1 + 0x5b4);
  pcVar2 = pcVar6 + -uVar3;
  pcVar6 = acStack_100;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  TDebuggingLog::Log(L,(char *)L,s_____RECEIVED_CHAT___u___s,*(undefined4 *)(iVar5 + 4),acStack_100)
  ;
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x55c + *(int *)(param_1 + 0x724) * 4),ChatMessage,
             acStack_100,0xff,'\0',(void *)0x0,0,0);
  iVar5 = *(int *)(param_1 + 0x724) + 1;
  *(int *)(param_1 + 0x724) = iVar5;
  if (7 < iVar5) {
    *(undefined4 *)(param_1 + 0x724) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004973e1
// Address: 004973e1
// XREFS: None
void __thiscall FUN_004973e1(int param_1,char *param_2)
{
  int iVar1;
  
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x55c + *(int *)(param_1 + 0x724) * 4),ChatMessage,
             param_2,0xff,'\0',(void *)0x0,0,0);
  iVar1 = *(int *)(param_1 + 0x724) + 1;
  *(int *)(param_1 + 0x724) = iVar1;
  if (7 < iVar1) {
    *(undefined4 *)(param_1 + 0x724) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049743b
// Address: 0049743b
// XREFS: None
// [HELPER] s_ALLOWCTRLU: "ALLOWCTRLU"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Writing_out_memory_info___d____: "Writing out memory info (%d)..."
// [HELPER] s_____________USER_PRESSED_CTRL_U_: "*** !!! %%% USER PRESSED CTRL-U TO FORCE OUT OF SYNC %%% !!! ***"
// [HELPER] s_c__mem_d_txt: "c:\mem%d.txt"
undefined4 __thiscall
FUN_0049743b(TRIBE_Screen_Game *param_1,int param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)
{
  uchar uVar1;
  TPanel *pTVar2;
  int iVar3;
  undefined4 uVar4;
  RGE_Player *pRVar5;
  char *pcVar6;
  TDigital *this;
  TribeSaveGameScreen *this_00;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *unaff_FS_OFFSET;
  bool bVar11;
  Mode MVar12;
  char acStack_20c [512];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ed9c;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar2 = TPanelSystem::modalPanel(&panel_system);
  if (pTVar2 != (TPanel *)0x0) goto switchD_004977a1_caseD_3a;
  piVar7 = *(int **)((int)&param_1->tool_box + 3);
  if ((piVar7[0x1b] != 0) &&
     (iVar3 = (**(code **)(*piVar7 + 0xac))(param_2,param_3,param_4,param_5,param_6), iVar3 != 0)) {
    uVar4 = 1;
    goto LAB_00497fff;
  }
  bVar11 = rge_base_game->prog_mode == 5;
  if (((param_5 != 0) && (param_6 != 0)) && (param_4 != 0)) {
    if (!bVar11) {
      if ((param_2 < 0x7b) && (0x60 < param_2)) {
        param_2 = param_2 + -0x20;
      }
      else if (((0x5a < param_2) || (param_2 < 0x41)) && ((param_2 < 0x30 || (0x39 < param_2)))) {
        param_2 = 0;
      }
      if (param_2 != 0) {
        if (*(int *)&param_1->field_0x734 == 0x32) {
          param_1->field_0x76a = (char)param_2;
          puVar8 = (undefined4 *)&param_1->field_0x739;
          puVar10 = (undefined4 *)&param_1->field_0x738;
          for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          *(undefined2 *)puVar10 = *(undefined2 *)puVar8;
          *(undefined1 *)((int)puVar10 + 2) = *(undefined1 *)((int)puVar8 + 2);
        }
        else {
          (&param_1->field_0x738)[*(int *)&param_1->field_0x734] = (char)param_2;
          iVar3 = *(int *)&param_1->field_0x734;
          *(int *)&param_1->field_0x734 = iVar3 + 1;
          (&param_1->field_0x739)[iVar3] = 0;
        }
        iVar3 = (**(code **)(rge_base_game->_padding_ + 0x54))
                          ((int)*(short *)(*(int *)((int)&param_1->world + 3) + 0x7c),
                           &param_1->field_0x738);
        if (iVar3 != 0) {
          *(undefined4 *)&param_1->field_0x734 = 0;
          param_1->field_0x738 = 0;
          uVar4 = 1;
          goto LAB_00497fff;
        }
      }
    }
    goto LAB_004979cf;
  }
  iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
  if ((iVar3 == 0) || (iVar3 = TCommunications_Handler::IsHost(comm), iVar3 == 0)) {
LAB_004975fc:
    if (((param_5 != 0) && (0x2f < param_2)) && (param_2 < 0x3a)) {
      TRIBE_Screen_Game::command_group_by_number(param_1,param_2 + -0x30);
      uVar4 = 1;
      goto LAB_00497fff;
    }
  }
  else if (param_5 != 0) {
    if (((param_6 != 0) && (0x31 < param_2)) && (param_2 < 0x39)) {
      TCommunications_Handler::Kick(comm,param_2 - 0x30);
      uVar4 = 1;
      goto LAB_00497fff;
    }
    goto LAB_004975fc;
  }
  if (param_6 != 0) {
    switch(param_2) {
    case 9:
      TRIBE_Screen_Game::command_tab_selected(param_1,0);
      uVar4 = 1;
      goto LAB_00497fff;
    default:
      goto switchD_0049763b_caseD_a;
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
      TRIBE_Screen_Game::command_select_group(param_1,param_2 + -0x30,0);
      uVar4 = 1;
      goto LAB_00497fff;
    case 0x70:
      TEasy_Panel::setup_popup_help((TEasy_Panel *)param_1);
      uVar4 = 1;
      goto LAB_00497fff;
    case 0x71:
      if ((!bVar11) && (allow_user_commands != 0)) {
        TRIBE_Screen_Game::command_formation(param_1,0);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x72:
      if ((!bVar11) && (allow_user_commands != 0)) {
        TRIBE_Screen_Game::command_formation(param_1,1);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x73:
      if ((!bVar11) && (allow_user_commands != 0)) {
        TRIBE_Screen_Game::command_formation(param_1,2);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x74:
      if ((!bVar11) && (allow_user_commands != 0)) {
        TRIBE_Screen_Game::command_formation(param_1,3);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x75:
      if ((!bVar11) && (allow_user_commands != 0)) {
        TRIBE_Screen_Game::command_formation(param_1,4);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x76:
      if ((!bVar11) && (allow_user_commands != 0)) {
        TRIBE_Screen_Game::command_formation(param_1,5);
        uVar4 = 1;
        goto LAB_00497fff;
      }
    }
LAB_004979cf:
    uVar4 = 1;
    goto LAB_00497fff;
  }
switchD_0049763b_caseD_a:
  if (param_4 != 0) {
    switch(param_2) {
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
      TRIBE_Screen_Game::command_select_group(param_1,param_2 + -0x30,1);
      TRIBE_Screen_Game::command_view_selected(param_1);
      uVar4 = 1;
      goto LAB_00497fff;
    default:
      goto switchD_004977a1_caseD_3a;
    case 0x41:
      iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
      if (iVar3 != 0) {
        view_debug_Objects = (int)(view_debug_Objects == 0);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x43:
      iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
      if (iVar3 != 0) {
        view_debug_redraw_all = 1;
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x49:
      iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
      if (iVar3 != 0) {
        rge_base_game->display_selected_ids = (uint)(rge_base_game->display_selected_ids == 0);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x4f:
      iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
      if (iVar3 != 0) {
        view_debug_ObstructionMap = (int)(view_debug_ObstructionMap == 0);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x50:
      iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
      if (iVar3 != 0) {
        MapPathsDisplay = (int)(MapPathsDisplay == 0);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x53:
      iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
      if (iVar3 != 0) {
        view_debug_spans = (int)(view_debug_spans == 0);
        uVar4 = 1;
        goto LAB_00497fff;
      }
      break;
    case 0x58:
      iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
      if (iVar3 != 0) {
        view_debug_palette = (int)(view_debug_palette == 0);
        uVar4 = 1;
        goto LAB_00497fff;
      }
    }
    goto LAB_004979cf;
  }
  if ((((param_5 == 0) && (iVar3 = RGE_Base_Game::get_paused(rge_base_game), iVar3 == 0)) &&
      (rge_base_game->game_mode == 6)) &&
     ((rge_base_game->sub_game_mode == 1 &&
      (iVar3 = 0, 0 < *(short *)((int)&param_1->start_item + 1))))) {
    iVar9 = 0;
    do {
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      pcVar6 = TPanel::get_string((TPanel *)param_1,
                                  pRVar5->master_objects
                                  [*(short *)(iVar9 + 4 + *(int *)((int)&param_1->bldg_list + 3))]->
                                  hotkey_id);
      if (param_2 == *pcVar6) {
        this = RGE_Base_Game::get_sound(rge_base_game,1);
        if (this != (TDigital *)0x0) {
          TDigital::play(this);
        }
        TRIBE_Screen_Game::command_building
                  (param_1,(int)*(short *)(*(int *)((int)&param_1->bldg_list + 3) + 4 + iVar3 * 0x28
                                          ));
        goto LAB_004979cf;
      }
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 0x28;
    } while (iVar3 < *(short *)((int)&param_1->start_item + 1));
  }
  uVar4 = 1;
  if (param_5 != 0) {
    iVar3 = 0;
    piVar7 = (int *)&param_1->field_0x784;
    do {
      if (param_2 == *piVar7) {
        TRIBE_Screen_Game::command_select_building(param_1,iVar3);
        goto LAB_00497fff;
      }
      iVar3 = iVar3 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar3 < 8);
  }
  if ((*(int *)&param_1->field_0x76c != 0) && (param_2 == *(int *)&param_1->field_0x76c)) {
    TRIBE_Screen_Game::command_select_building(param_1,0);
    goto switchD_004977a1_caseD_3a;
  }
  if (param_5 == 0) {
    if ((rge_base_game->game_mode == 6) && (rge_base_game->sub_game_mode == 1)) {
code_r0x00497eb3:
      switch(param_2) {
      case 9:
        TRIBE_Screen_Game::command_tab_selected(param_1,1);
        uVar4 = 1;
        goto LAB_00497fff;
      case 0xd:
        TRIBE_Screen_Game::command_quick_chat(param_1);
        break;
      case 0x20:
        TRIBE_Screen_Game::command_view_selected(param_1);
        break;
      case 0x24:
        TRIBE_Game::goto_notification_loc((TRIBE_Game *)rge_base_game);
        break;
      case 0x2e:
        if ((!bVar11) && (allow_user_commands != 0)) {
          TRIBE_Screen_Game::command_cancel_building(param_1);
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
      case 0x39:
        TRIBE_Screen_Game::command_select_group(param_1,param_2 + -0x30,1);
        break;
      case 0x73:
        TRIBE_Screen_Game::command_score
                  (param_1,(uint)(*(char *)(*(int *)((int)&param_1->world + 3) + 0x11c) == '\0'));
        break;
      case 0x74:
        TRIBE_Screen_Game::command_fps(param_1);
        break;
      case 0x75:
        iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
        if (iVar3 != 0) {
          TRIBE_Screen_Game::command_visibility(param_1);
        }
        break;
      case 0x76:
        iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
        if (iVar3 != 0) {
          TRIBE_Screen_Game::command_fog_of_war(param_1);
        }
        break;
      case 0x77:
        iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
        if (iVar3 != 0) {
          TRIBE_Screen_Game::command_comm_info(param_1);
        }
        break;
      case 0x78:
        iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
        if (iVar3 != 0) {
          TRIBE_Screen_Game::command_ai_info(param_1);
        }
        break;
      case 0x7a:
        iVar3 = TRIBE_Panel_Time::get_clock_type
                          (*(TRIBE_Panel_Time **)((int)&param_1->time_panel + 3));
        if (iVar3 == 0) {
          TRIBE_Panel_Time::set_clock_type
                    (*(TRIBE_Panel_Time **)((int)&param_1->time_panel + 3),2,0);
          (**(code **)(**(int **)((int)&param_1->pop_panel + 3) + 0x14))(1);
        }
        else {
          TRIBE_Panel_Time::set_clock_type
                    (*(TRIBE_Panel_Time **)((int)&param_1->time_panel + 3),0,0);
          (**(code **)(**(int **)((int)&param_1->pop_panel + 3) + 0x14))(0);
        }
        TRIBE_Screen_Game::reset_clocks(param_1);
        (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x20))(1);
      }
    }
    else if ((*(int *)&param_1->field_0x770 == 0) ||
            ((param_2 != *(int *)&param_1->field_0x770 || (bVar11)))) {
      if ((*(int *)&param_1->field_0x774 == 0) ||
         ((param_2 != *(int *)&param_1->field_0x774 || (bVar11)))) {
        if ((*(int *)&param_1->field_0x778 == 0) ||
           ((param_2 != *(int *)&param_1->field_0x778 || (bVar11)))) {
          if ((*(int *)&param_1->field_0x77c == 0) || (param_2 != *(int *)&param_1->field_0x77c))
          goto code_r0x00497eb3;
          TRIBE_Screen_Game::command_ungroup(param_1);
        }
        else if (allow_user_commands != 0) {
          TRIBE_Screen_Game::command_attack(param_1);
        }
      }
      else if (allow_user_commands != 0) {
        TRIBE_Screen_Game::command_move(param_1);
      }
    }
    else if (allow_user_commands != 0) {
      TRIBE_Screen_Game::command_work(param_1);
    }
    goto switchD_004977a1_caseD_3a;
  }
  iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
  if (iVar3 == 0) goto switchD_004977a1_caseD_3a;
  switch(param_2) {
  case 0x20:
    TRIBE_Screen_Game::command_view_selected(param_1);
    break;
  case 0x45:
    this_00 = (TribeSaveGameScreen *)operator_new(0x6a4);
    uStack_4 = 0;
    if (this_00 != (TribeSaveGameScreen *)0x0) {
      MVar12 = SaveGame;
LAB_00497d38:
      TribeSaveGameScreen::TribeSaveGameScreen(this_00,MVar12,(char *)0x0,0);
    }
    goto LAB_00497d3f;
  case 0x46:
    if (allow_user_commands != 0) {
      TRIBE_Screen_Game::command_add_attribute(param_1,0);
    }
    break;
  case 0x47:
    if (allow_user_commands != 0) {
      TRIBE_Screen_Game::command_add_attribute(param_1,3);
    }
    break;
  case 0x49:
    *(uint *)(rge_base_game[1].work_dir + 0x14) =
         (uint)(*(int *)(rge_base_game[1].work_dir + 0x14) == 0);
    (**(code **)(**(int **)((int)&param_1->object_panel + 3) + 0x20))(1);
    break;
  case 0x4a:
    TCommunications_Handler::TXDebugPing(comm);
    break;
  case 0x4d:
    DAT_0086bac8 = DAT_0086bac8 + 1;
    sprintf(acStack_20c,s_Writing_out_memory_info___d____,DAT_0086bac8);
    TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game,acStack_20c,(char *)0x0,-1);
    sprintf(acStack_20c,s_c__mem_d_txt,DAT_0086bac8);
    RGE_Base_Game::dump_memory_usage(rge_base_game,acStack_20c);
    TRIBE_Game::close_status_message((TRIBE_Game *)rge_base_game);
    break;
  case 0x4e:
    iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
    if (iVar3 == 0) {
      TRIBE_Game::restart_game((TRIBE_Game *)rge_base_game);
    }
    break;
  case 0x4f:
    if (rge_base_game->outline_type == '\x03') {
      rge_base_game->outline_type = '\x02';
      uVar4 = 1;
    }
    else {
      rge_base_game->outline_type = '\x03';
      uVar4 = 1;
    }
    goto LAB_00497fff;
  case 0x51:
    if (allow_user_commands != 0) {
      TRIBE_Screen_Game::command_quick_build(param_1);
    }
    break;
  case 0x52:
    View_Grid_Mode = View_Grid_Mode + 1;
    iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
    if (iVar3 == 0) {
      if (1 < View_Grid_Mode) goto LAB_00497c7e;
    }
    else if (4 < View_Grid_Mode) {
LAB_00497c7e:
      View_Grid_Mode = 0;
    }
    (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x20))(2);
    break;
  case 0x53:
    if (allow_user_commands != 0) {
      TRIBE_Screen_Game::command_add_attribute(param_1,2);
    }
    break;
  case 0x54:
    TRIBE_Screen_Game::command_tool_box(param_1);
    break;
  case 0x55:
    iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game);
    if ((iVar3 != 0) &&
       (uVar1 = RGE_Base_Game::check_prog_argument(rge_base_game,s_ALLOWCTRLU), uVar1 != '\0')) {
      TDebuggingLog::Log(L,(char *)L,s_____________USER_PRESSED_CTRL_U_);
      displayPathingFlags = (int)(displayPathingFlags == 0);
    }
    break;
  case 0x56:
    this_00 = (TribeSaveGameScreen *)operator_new(0x6a4);
    uStack_4 = 1;
    if (this_00 != (TribeSaveGameScreen *)0x0) {
      MVar12 = SaveScenario;
      goto LAB_00497d38;
    }
LAB_00497d3f:
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Save_Game_Screen,0);
    break;
  case 0x57:
    if (allow_user_commands != 0) {
      TRIBE_Screen_Game::command_add_attribute(param_1,1);
    }
    break;
  case 0x58:
    if (allow_user_commands != 0) {
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      (**(code **)(pRVar5->_padding_ + 0x38))(1);
    }
    break;
  case 0x59:
    if (allow_user_commands != 0) {
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      (**(code **)(pRVar5->_padding_ + 0x38))(2);
    }
    break;
  case 0x5a:
    if (allow_user_commands != 0) {
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      (**(code **)(pRVar5->_padding_ + 0x38))(3);
    }
    break;
  case 0x70:
    TRIBE_Screen_Game::command_player(param_1,1);
    uVar4 = 1;
    goto LAB_00497fff;
  case 0x71:
    TRIBE_Screen_Game::command_player(param_1,2);
    uVar4 = 1;
    goto LAB_00497fff;
  case 0x72:
    TRIBE_Screen_Game::command_player(param_1,3);
    uVar4 = 1;
    goto LAB_00497fff;
  case 0x73:
    TRIBE_Screen_Game::command_player(param_1,4);
    uVar4 = 1;
    goto LAB_00497fff;
  case 0x74:
    TRIBE_Screen_Game::command_player(param_1,5);
    uVar4 = 1;
    goto LAB_00497fff;
  case 0x75:
    TRIBE_Screen_Game::command_player(param_1,6);
    uVar4 = 1;
    goto LAB_00497fff;
  case 0x76:
    TRIBE_Screen_Game::command_player(param_1,7);
    uVar4 = 1;
    goto LAB_00497fff;
  case 0x77:
    TRIBE_Screen_Game::command_player(param_1,8);
    uVar4 = 1;
    goto LAB_00497fff;
  case 0x78:
    TRIBE_Screen_Game::command_player(param_1,0);
    uVar4 = 1;
    goto LAB_00497fff;
  }
switchD_004977a1_caseD_3a:
  uVar4 = 0;
LAB_00497fff:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}

// --------------------------------------------------

// Function: FUN_00498026
// Address: 00498026
// XREFS: None
/* WARNING: Instruction at (ram,0x00498260) overlaps instruction at (ram,0x0049825f)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined4 __fastcall FUN_00498026(uint *param_1,uint *param_2)
{
  byte *pbVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  uint in_EAX;
  undefined3 uVar11;
  undefined4 uVar8;
  int iVar9;
  byte bVar12;
  byte bVar13;
  char cVar14;
  char cVar18;
  byte *pbVar15;
  undefined2 uVar20;
  byte *pbVar16;
  byte *extraout_ECX;
  undefined3 uVar19;
  byte *pbVar17;
  TRIBE_Screen_Game *this;
  char cVar21;
  char cVar24;
  uint uVar22;
  char cVar25;
  char cVar26;
  char *unaff_EBX;
  byte *pbVar27;
  int unaff_EBP;
  char *unaff_ESI;
  char *pcVar28;
  byte *unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  bool in_CF;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  undefined1 uVar32;
  undefined8 uVar33;
  char *unaff_retaddr;
  undefined2 auStack_4 [2];
  char *pcVar10;
  uint *puVar23;
  
  cVar25 = (char)in_EAX;
  bVar6 = (byte)unaff_EBX;
  if (!in_CF) {
    *(byte *)((int)param_2 + 0x76) = *(byte *)((int)param_2 + 0x76) + cVar25;
    *(byte *)(param_1 + 0x1d) = (char)param_1[0x1d] + bVar6;
    *(byte *)((int)param_2 + 0x76) =
         *(byte *)((int)param_2 + 0x76) + (char)((uint)((int)param_1 + -3) >> 8);
    puVar23 = param_1 + -1;
    pbVar15 = (byte *)(unaff_ESI + -0x3dffb68a);
    bVar5 = *pbVar15;
    bVar12 = (byte)param_2;
    *pbVar15 = *pbVar15 + bVar12;
    if (CARRY1(bVar5,bVar12) || *pbVar15 == 0) {
      *puVar23 = *puVar23 | (uint)puVar23;
      *puVar23 = *puVar23 | (uint)puVar23;
    }
    else {
      bVar5 = (byte)((uint)puVar23 >> 8);
      bVar13 = (byte)((uint)param_2 >> 8);
      cVar24 = bVar13 + bVar5;
      param_2 = (uint *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(cVar24,bVar12));
      if (!CARRY1(bVar13,bVar5) && cVar24 != '\0') {
        uVar4 = *param_2;
        *(byte *)param_2 = (byte)*param_2 + bVar6;
        if (!CARRY1((byte)uVar4,bVar6) && (byte)*param_2 != 0) goto code_r0x00498090;
        unaff_ESI[0x77] = unaff_ESI[0x77] + cVar25;
        param_1 = (uint *)((int)param_1 + -5);
        *(char *)(unaff_EBP + 0x4977) = *(char *)(unaff_EBP + 0x4977) + cVar25;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 + in_EAX;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        *param_1 = *param_1 | (uint)param_1;
        goto code_r0x004980a1;
      }
    }
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
code_r0x00498090:
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *puVar23 = *puVar23 | (uint)puVar23;
    *param_2 = *param_2 | in_EAX;
                    /* WARNING: Could not recover jumptable at 0x004980bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar8 = (**(code **)(in_EAX + *(int *)(in_EAX + 0x8b080706) + -0x53ffb689))();
    return uVar8;
  }
code_r0x004980a1:
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  *param_1 = *param_1 | (uint)param_1;
  uVar11 = (undefined3)(in_EAX >> 8);
  bVar5 = cVar25 + *unaff_EBX + 5;
  pbVar17 = (byte *)CONCAT31(uVar11,bVar5);
  unaff_EBX[0x4977a8ff] = unaff_EBX[0x4977a8ff] | (byte)param_1;
  pbVar17[(int)unaff_EDI * 2 + 0x78560049] =
       pbVar17[(int)unaff_EDI * 2 + 0x78560049] + (char)((uint)param_1 >> 8);
  pbVar15 = (byte *)((int)param_1 + -1);
  uVar19 = (undefined3)((uint)unaff_EBX >> 8);
  cVar25 = bVar6 + bVar5;
  pbVar27 = (byte *)CONCAT31(uVar19,cVar25);
  auStack_4[0] = in_ES;
  if (CARRY1(bVar6,bVar5) || cVar25 == '\0') {
    bVar6 = (byte)((uint)unaff_EBX >> 8);
    *(char *)(unaff_EBP + 0x78) = *(char *)(unaff_EBP + 0x78) + bVar6;
    pbVar15 = (byte *)((int)param_1 + -2);
    cVar24 = bVar5 + bVar6;
    pbVar17 = (byte *)CONCAT31(uVar11,cVar24);
    if (!CARRY1(bVar5,bVar6) && cVar24 != '\0') {
      unaff_EDI = unaff_EDI + -1;
      if ((POPCOUNT((uint)unaff_EDI & 0xff) & 1U) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      goto code_r0x00498123;
    }
    bVar5 = (byte)(in_EAX >> 8);
    bVar29 = CARRY1(*unaff_EDI,bVar5);
    *unaff_EDI = *unaff_EDI + bVar5;
    if (-1 < (char)*unaff_EDI) {
      bVar5 = cVar25 * '\x02';
      pbVar27 = (byte *)CONCAT31(uVar19,bVar5);
      bVar12 = (byte)pbVar15;
      uVar20 = (undefined2)((uint)pbVar15 >> 0x10);
      bVar13 = (byte)((uint)pbVar15 >> 8);
      if ((char)bVar5 < '\0') {
        unaff_EDI = *(byte **)(pbVar27 + 0x49);
        bVar6 = (byte)((uint)param_2 >> 8);
        bVar5 = CARRY1(bVar13,bVar6);
        cVar25 = bVar13 + bVar6;
        pbVar15 = (byte *)CONCAT22(uVar20,CONCAT11(cVar25,bVar12));
        uVar32 = (POPCOUNT(cVar25) & 1U) == 0;
        goto code_r0x0049812d;
      }
      cVar25 = bVar13 + bVar6;
      pbVar15 = (byte *)CONCAT22(uVar20,CONCAT11(cVar25,bVar12));
      uVar32 = (POPCOUNT(cVar25) & 1U) == 0;
      if (cVar25 != '\0' && SCARRY1(bVar13,bVar6) == cVar25 < '\0') {
        bVar5 = !CARRY1(bVar13,bVar6);
        goto code_r0x0049812d;
      }
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + cVar24;
      *pbVar17 = *pbVar17 + bVar12;
      *pbVar17 = *pbVar17 | bVar12;
      *pbVar17 = *pbVar17 | bVar12;
      *pbVar17 = *pbVar17 | bVar12;
      *(byte **)pbVar17 = pbVar15 + *(int *)pbVar17;
      bVar12 = bVar12 + *pbVar17;
      *pbVar17 = *pbVar17 | bVar12;
      *pbVar17 = *pbVar17 | bVar12;
      pbVar15 = (byte *)(CONCAT31((int3)((uint)pbVar15 >> 8),bVar12) + *(int *)pbVar17);
      bVar6 = (byte)pbVar15;
      *pbVar17 = *pbVar17 | bVar6;
      *pbVar17 = *pbVar17 | bVar6;
      pbVar17 = (byte *)CONCAT31(uVar11,cVar24 + 5U);
      *pbVar17 = *pbVar17 | bVar6;
      *pbVar17 = *pbVar17 | bVar6;
      *pbVar17 = *pbVar17 | bVar6;
      bVar6 = (byte)((uint)pbVar15 >> 8);
      bVar30 = CARRY1((byte)param_2,bVar6);
      cVar25 = (byte)param_2 + bVar6;
      param_2 = (uint *)CONCAT31((int3)((uint)param_2 >> 8),cVar25);
      bVar29 = (POPCOUNT(cVar25) & 1U) == 0;
      if (bVar29) {
        unaff_ESI = unaff_retaddr;
        pcVar28 = unaff_retaddr;
        if (!bVar29) {
code_r0x00498163:
          pcVar28[0x7a] = pcVar28[0x7a] + (char)((uint)pbVar15 >> 8);
          pbVar15 = pbVar15 + -1;
          goto code_r0x00498167;
        }
        goto code_r0x004981ac;
      }
      bVar6 = *pbVar15;
      *pbVar15 = *pbVar15 + bVar5;
      bVar29 = (POPCOUNT(*pbVar15) & 1U) == 0;
      if (bVar29) goto code_r0x0049811b;
      pcVar28 = unaff_ESI + 1;
      out(*unaff_ESI,(short)param_2);
      if (bVar29) {
        bVar29 = (byte)(cVar24 + 5U) < 6 || (byte)(cVar24 - 1U) < CARRY1(bVar6,bVar5);
        pbVar17 = (byte *)CONCAT31(uVar11,(cVar24 - 1U) - CARRY1(bVar6,bVar5));
        unaff_ESI = pcVar28;
        goto code_r0x004981a1;
      }
code_r0x00498167:
      pcVar28[0x7a] = pcVar28[0x7a] + (char)((uint)pbVar27 >> 8);
      pbVar15 = pbVar15 + -1;
      pbVar16 = (byte *)(pcVar28 + -0x61ffb686);
      bVar6 = *pbVar16;
      bVar12 = (byte)pbVar15;
      *pbVar16 = *pbVar16 + bVar12;
      bVar13 = (byte)param_2;
      unaff_ESI = pcVar28;
      if ((POPCOUNT(*pbVar16) & 1U) == 0) {
        bVar29 = CARRY1(*pbVar15,bVar13) || CARRY1(*pbVar15 + bVar13,CARRY1(bVar6,bVar12));
        *pbVar15 = *pbVar15 + bVar13 + CARRY1(bVar6,bVar12);
        goto code_r0x004981a1;
      }
      pbVar16 = (byte *)(pcVar28 + -0x41ffb686);
      bVar6 = *pbVar16;
      bVar5 = (byte)((uint)pbVar15 >> 8);
      *pbVar16 = *pbVar16 + bVar5;
      if ((POPCOUNT(*pbVar16) & 1U) != 0) {
        bVar6 = (byte)((uint)param_2 >> 8);
        bVar5 = CARRY1(bVar6,bVar12);
        cVar25 = bVar6 + bVar12;
        uVar32 = (POPCOUNT(cVar25) & 1U) == 0;
        uVar33 = CONCAT44(CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(cVar25,bVar13)),pbVar17);
        goto code_r0x0049817d;
      }
      bVar12 = (byte)pbVar17 - 0x1c;
      bVar29 = (byte)pbVar17 < 0x1c || bVar12 < CARRY1(bVar6,bVar5);
      bVar12 = bVar12 - CARRY1(bVar6,bVar5);
      bVar6 = bVar12 - 0x1c;
      bVar5 = bVar12 < 0x1c || bVar6 < bVar29;
      uVar33 = CONCAT44(param_2,CONCAT31((int3)((uint)pbVar17 >> 8),bVar6 - bVar29));
      goto code_r0x004981c8;
    }
    if ((POPCOUNT(*unaff_EDI) & 1U) == 0) goto code_r0x00498126;
code_r0x004981a1:
    bVar6 = (byte)pbVar17 - 0x1c;
    bVar30 = (byte)pbVar17 < 0x1c || bVar6 < bVar29;
    bVar6 = bVar6 - bVar29;
    bVar5 = bVar6 - 0x1c;
    bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
    bVar5 = bVar5 - bVar30;
    bVar6 = bVar5 - 0x1c;
    iVar9 = CONCAT31((int3)((uint)pbVar17 >> 8),
                     ((bVar6 - bVar29) + -0x1c) - (bVar5 < 0x1c || bVar6 < bVar29));
    *param_2 = *param_2 + iVar9;
    pbVar27 = pbVar27 + *(int *)(&stack0x00000000 + iVar9);
    bVar6 = (byte)pbVar27;
    *(byte *)((int)pbVar15 * 2) = *(byte *)((int)pbVar15 * 2) | bVar6;
    pbVar15 = (byte *)CONCAT31((int3)((uint)pbVar15 >> 8),(byte)pbVar15 | *pbVar27);
    bVar12 = (byte)(iVar9 + 0x7061c1c) | 0xd;
    auStack_4[0] = in_CS;
    bVar29 = CARRY1(bVar6,*(byte *)((int)auStack_4 + (int)pbVar27));
    bVar6 = bVar6 + *(byte *)((int)auStack_4 + (int)pbVar27);
    pbVar27 = (byte *)CONCAT31((int3)((uint)pbVar27 >> 8),bVar6);
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    uVar11 = (undefined3)((uint)(iVar9 + 0x7061c1c) >> 8);
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 - 0x1c;
    bVar30 = bVar12 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar12 = bVar5 - 0x13;
    bVar29 = bVar5 < 0x13 || bVar12 < bVar30;
    bVar12 = bVar12 - bVar30;
    bVar5 = bVar12 + 0x15;
    bVar30 = 0xea < bVar12 || CARRY1(bVar5,bVar29);
    cVar25 = bVar5 + bVar29;
    bVar29 = *pbVar15 < bVar6 || (byte)(*pbVar15 - bVar6) < bVar30;
    *pbVar15 = (*pbVar15 - bVar6) - bVar30;
    pcVar28 = unaff_ESI;
  }
  else {
    *(uint *)(pbVar27 + 0x49) =
         (*(int *)(pbVar27 + 0x49) - (int)unaff_EDI) - (uint)CARRY1(bVar6,bVar5);
code_r0x0049811b:
    pbVar27[(int)unaff_EDI * 2] = pbVar27[(int)unaff_EDI * 2] + (char)((uint)param_2 >> 8);
    unaff_EDI[0x7b] = unaff_EDI[0x7b] + (char)pbVar15 + -1;
    pbVar15 = pbVar15 + -2;
code_r0x00498123:
    pbVar27[0x7b] = pbVar27[0x7b] + (char)((uint)pbVar27 >> 8);
code_r0x00498126:
    pbVar15 = pbVar15 + -1;
    pbVar16 = pbVar27 + -0xaffb685;
    bVar5 = CARRY1(*pbVar16,(byte)pbVar15);
    *pbVar16 = *pbVar16 + (byte)pbVar15;
    uVar32 = (POPCOUNT(*pbVar16) & 1U) == 0;
code_r0x0049812d:
    uVar33 = CONCAT44(param_2,pbVar17);
    if ((bool)uVar32) {
      bVar12 = (byte)pbVar27;
      bVar5 = CARRY1(*pbVar17,bVar12);
      bVar6 = *pbVar17;
      *pbVar17 = *pbVar17 + bVar12;
      uVar32 = (POPCOUNT(*pbVar17) & 1U) == 0;
      if (SCARRY1(bVar6,bVar12) != (char)*pbVar17 < '\0') {
        pcVar3 = (code *)swi(4);
        uVar33 = CONCAT44(param_2,pbVar17);
        if (SCARRY1(bVar6,bVar12)) {
          uVar33 = (*pcVar3)();
          pbVar15 = extraout_ECX;
        }
        goto code_r0x0049817d;
      }
      bVar6 = *pbVar15;
      cVar25 = (char)((uint)pbVar27 >> 8);
      *pbVar15 = *pbVar15 + cVar25;
      if (SCARRY1(bVar6,cVar25) == (char)*pbVar15 < '\0') {
        bVar5 = (byte)param_2;
        *(byte *)(param_2 + 0x1f) = (byte)param_2[0x1f] + bVar5;
        pbVar16 = pbVar15 + -1;
        puVar23 = param_2 + -0x12bfeda1;
        bVar29 = CARRY1((byte)*puVar23,bVar12);
        uVar4 = *puVar23;
        *(byte *)puVar23 = (byte)*puVar23 + bVar12;
        bVar6 = (byte)pbVar17;
        if (SCARRY1((byte)uVar4,bVar12) == (char)(byte)*puVar23 < '\0') {
          bVar13 = (byte)pbVar16;
          bVar29 = CARRY1(bVar13,bVar6);
          pbVar16 = (byte *)CONCAT31((int3)((uint)pbVar16 >> 8),bVar13 + bVar6);
          if (SCARRY1(bVar13,bVar6) != (char)(bVar13 + bVar6) < '\0') goto code_r0x00498190;
          bVar29 = CARRY1(*unaff_EDI,bVar5);
          bVar6 = *unaff_EDI;
          *unaff_EDI = *unaff_EDI + bVar5;
          pbVar15 = pbVar16;
          if (SCARRY1(bVar6,bVar5) == (char)*unaff_EDI < '\0') goto code_r0x00498194;
          pbVar17[0x7d] = pbVar17[0x7d] + (char)((uint)pbVar17 >> 8);
          *(byte *)((int)param_2 + 0x7d) = *(byte *)((int)param_2 + 0x7d) + cVar25;
          pbVar15 = pbVar16 + -2;
          pbVar1 = unaff_EDI + -0x3affb683;
          bVar29 = CARRY1(*pbVar1,bVar12);
          bVar6 = *pbVar1;
          *pbVar1 = *pbVar1 + bVar12;
          if (SCARRY1(bVar6,bVar12) != (char)*pbVar1 < '\0') {
            unaff_EDI[0x7a] = unaff_EDI[0x7a] + (char)pbVar15;
            unaff_ESI[0x7a] = unaff_ESI[0x7a] + bVar12;
            pbVar15 = pbVar16 + -4;
            pcVar28 = unaff_ESI;
            goto code_r0x00498163;
          }
        }
        else {
          bVar30 = bVar6 < 0x1c || (byte)(bVar6 - 0x1c) < bVar29;
          bVar5 = (bVar6 - 0x1c) - bVar29;
          bVar6 = bVar5 - 0x1c;
          bVar29 = bVar5 < 0x1c || bVar6 < bVar30;
          pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar6 - bVar30);
code_r0x00498190:
          bVar6 = (byte)pbVar17 - 0x1c;
          bVar30 = (byte)pbVar17 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar5 - bVar30);
          pbVar15 = pbVar16;
code_r0x00498194:
          bVar6 = (byte)pbVar17 - 0x1c;
          bVar30 = (byte)pbVar17 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          bVar5 = bVar5 - bVar30;
          bVar6 = bVar5 - 0x1c;
          bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          bVar5 = bVar5 - bVar30;
          bVar6 = bVar5 - 0x1c;
          bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          bVar5 = bVar5 - bVar30;
          bVar6 = bVar5 - 0x1c;
          bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
          bVar6 = bVar6 - bVar29;
          bVar5 = bVar6 - 0x1c;
          bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
          pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar5 - bVar30);
        }
        bVar6 = (byte)pbVar17 - 0x1c;
        bVar30 = (byte)pbVar17 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar6 = ((bVar5 - bVar30) + -1) - (bVar6 < 0x1c || bVar5 < bVar30);
        bVar30 = CARRY1(bVar6,*pbVar27);
        pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar6 + *pbVar27);
code_r0x004981ac:
        bVar6 = (byte)pbVar17 - 4;
        bVar29 = (byte)pbVar17 < 4 || bVar6 < bVar30;
        pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),bVar6 - bVar30);
        goto code_r0x004981a1;
      }
code_r0x0049817f:
      param_2 = (uint *)((ulonglong)uVar33 >> 0x20);
      pbVar17 = (byte *)uVar33;
      bVar6 = (byte)((uint)pbVar15 >> 8);
      bVar5 = (byte)((uint)pbVar27 >> 8);
      bVar30 = CARRY1(bVar6,bVar5);
      cVar25 = bVar6 + bVar5;
      pbVar15 = (byte *)CONCAT22((short)((uint)pbVar15 >> 0x10),CONCAT11(cVar25,(char)pbVar15));
      pcVar28 = unaff_ESI;
      if (cVar25 == '\0' || SCARRY1(bVar6,bVar5) != cVar25 < '\0') {
        bVar6 = *pbVar17;
        bVar5 = (byte)uVar33;
        *pbVar17 = *pbVar17 + bVar5;
        bVar29 = bVar5 < 0x1c || (byte)(bVar5 - 0x1c) < CARRY1(bVar6,bVar5);
        bVar5 = (bVar5 - 0x1c) - CARRY1(bVar6,bVar5);
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar29 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar30 = bVar5 < 0x1c || bVar6 < bVar29;
        bVar6 = bVar6 - bVar29;
        bVar5 = bVar6 - 0x1c;
        bVar31 = bVar6 < 0x1c || bVar5 < bVar30;
        bVar5 = bVar5 - bVar30;
        bVar6 = bVar5 - 0x1c;
        bVar29 = bVar5 < 0x1c || bVar6 < bVar31;
        pbVar17 = (byte *)CONCAT31((int3)((ulonglong)uVar33 >> 8),bVar6 - bVar31);
        goto code_r0x004981a1;
      }
    }
    else {
      unaff_ESI = (char *)0xce00497a;
code_r0x0049817d:
      pcVar28 = unaff_ESI;
      if (!(bool)uVar32) goto code_r0x0049817f;
code_r0x004981c8:
      bVar6 = (byte)uVar33 - 0x1c;
      bVar29 = (byte)uVar33 < 0x1c || bVar6 < bVar5;
      bVar6 = bVar6 - bVar5;
      bVar5 = bVar6 - 0x1c;
      bVar30 = bVar6 < 0x1c || bVar5 < bVar29;
      uVar33 = CONCAT44((int)((ulonglong)uVar33 >> 0x20),
                        CONCAT31((int3)((ulonglong)uVar33 >> 8),bVar5 - bVar29));
    }
    uVar22 = (uint)((ulonglong)uVar33 >> 0x20);
    bVar6 = (byte)uVar33 - 0x1c;
    bVar29 = (byte)uVar33 < 0x1c || bVar6 < bVar30;
    uVar11 = (undefined3)((ulonglong)uVar33 >> 8);
    bVar6 = bVar6 - bVar30;
    bVar5 = bVar6 - 0x1c;
    bVar30 = bVar6 < 0x1c || bVar5 < bVar29;
    bVar5 = bVar5 - bVar29;
    bVar6 = bVar5 - 0x1c;
    bVar29 = bVar5 < 0x1c || bVar6 < bVar30;
    bVar6 = bVar6 - bVar30;
    bVar5 = bVar6 - 0x1c;
    cVar25 = bVar5 - bVar29;
    uVar4 = (uint)(bVar6 < 0x1c || bVar5 < bVar29);
    uVar2 = uVar22 + *(uint *)(uVar22 + 0x19181716);
    bVar29 = CARRY4(uVar22,*(uint *)(uVar22 + 0x19181716)) || CARRY4(uVar2,uVar4);
    param_2 = (uint *)(uVar2 + uVar4);
  }
  cVar26 = ((char)pbVar27 - *pbVar27) - bVar29;
  bVar6 = (byte)pbVar15;
  *(int *)(pcVar28 + 0x49) = *(int *)(pcVar28 + 0x49) >> (bVar6 & 0x1f);
  uVar19 = (undefined3)((uint)pbVar15 >> 8);
  cVar24 = bVar6 + cVar26;
  pbVar17 = (byte *)CONCAT31(uVar19,cVar24);
  puVar23 = param_2;
  if (cVar24 != '\0' && SCARRY1(bVar6,cVar26) == cVar24 < '\0') {
code_r0x00498244:
    *puVar23 = *puVar23 | (uint)pbVar17;
    this = (TRIBE_Screen_Game *)((uint)pbVar17 | uRam9090900c);
    goto TRIBE_Screen_Game_char_action;
  }
  cVar14 = (char)param_2;
  cVar7 = cVar25 + cVar14;
  pcVar10 = (char *)CONCAT31(uVar11,cVar7);
  if (cVar7 != '\0' && SCARRY1(cVar25,cVar14) == cVar7 < '\0') goto code_r0x00498284;
  cVar25 = (char)uVar11;
  uVar11 = (undefined3)((uint)param_2 >> 8);
  cVar21 = cVar14 + cVar25;
  puVar23 = (uint *)CONCAT31(uVar11,cVar21);
  if (cVar21 != '\0' && SCARRY1(cVar14,cVar25) == cVar21 < '\0') goto code_r0x00498244;
  cVar18 = (char)((uint)pbVar15 >> 8);
  cVar14 = cVar24 + cVar18;
  pbVar17 = (byte *)CONCAT31(uVar19,cVar14);
  if (cVar14 == '\0' || SCARRY1(cVar24,cVar18) != cVar14 < '\0') {
    cVar24 = cVar21 + cVar7;
    if (cVar24 != '\0' && SCARRY1(cVar21,cVar7) == cVar24 < '\0') {
      cVar21 = cVar24 + cVar25;
      puVar23 = (uint *)CONCAT31(uVar11,cVar21);
      if (cVar21 == '\0' || SCARRY1(cVar24,cVar25) != cVar21 < '\0') goto code_r0x00498244;
      uVar4 = *puVar23;
      *(byte *)puVar23 = (byte)*puVar23 + cVar7;
      if ((((byte)*puVar23 == 0 || SCARRY1((byte)uVar4,cVar7) != (char)(byte)*puVar23 < '\0') &&
          (cVar24 = *pcVar28, *pcVar28 = *pcVar28 + cVar14,
          *pcVar28 == '\0' || SCARRY1(cVar24,cVar14) != *pcVar28 < '\0')) &&
         (bVar6 = *unaff_EDI, *unaff_EDI = *unaff_EDI + cVar25,
         *unaff_EDI == 0 || SCARRY1(bVar6,cVar25) != (char)*unaff_EDI < '\0')) {
        pcVar10[0x7f] = pcVar10[0x7f] + cVar7;
        pbVar17[0x7e] = pbVar17[0x7e] + cVar26;
        *(byte *)((int)puVar23 + 0x7f) = *(byte *)((int)puVar23 + 0x7f) + (char)((uint)param_2 >> 8)
        ;
        pbVar17 = pbVar17 + -3;
        cVar24 = (char)((uint)pbVar17 >> 8);
        cVar14 = (char)((uint)pbVar27 >> 8);
        cVar25 = cVar24 + cVar14;
        pbVar17 = (byte *)CONCAT22((short)((uint)pbVar17 >> 0x10),CONCAT11(cVar25,(char)pbVar17));
        if (cVar25 == '\0' || SCARRY1(cVar24,cVar14) != cVar25 < '\0') {
          *pcVar10 = *pcVar10 + cVar7;
        }
      }
      goto code_r0x00498284;
    }
  }
  else {
code_r0x00498284:
    *pbVar17 = *pbVar17 | (byte)pbVar17;
  }
  this = (TRIBE_Screen_Game *)
         CONCAT31((int3)((uint)pbVar17 >> 8),
                  (byte)pbVar17 | *(byte *)CONCAT31((int3)((uint)pbVar27 >> 8),cVar26));
TRIBE_Screen_Game_char_action:
  if (unaff_retaddr != (char *)0x2b) {
    if (unaff_retaddr == (char *)0x2d) {
      if (allow_user_commands == 0) {
        return 0;
      }
      TRIBE_Screen_Game::command_game_speed(this,0);
      return 0;
    }
    if (unaff_retaddr != (char *)0x3d) {
      return 0;
    }
  }
  if (allow_user_commands != 0) {
    TRIBE_Screen_Game::command_game_speed(this,1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004982d2
// Address: 004982d2
// XREFS: None
// [HELPER] s_CloseProgramDialog: "CloseProgramDialog"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_QuitAndLoadDialog: "QuitAndLoadDialog"
// [HELPER] s_QuitGameDialog: "QuitGameDialog"
// [HELPER] s_ResignDialog: "ResignDialog"
// [HELPER] s_RestartDialog: "RestartDialog"
long __thiscall
FUN_004982d2(TRIBE_Screen_Game *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  byte bVar1;
  TPanel *pTVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  RGE_Player *pRVar6;
  int iVar7;
  TribeLoadSavedGameScreen *this;
  long lVar8;
  int *piVar9;
  undefined4 unaff_EBP;
  byte *pbVar10;
  undefined4 *unaff_FS_OFFSET;
  bool bVar11;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055edbb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == (TPanel *)0x0) {
LAB_0049874d:
    lVar8 = TEasy_Panel::action((TEasy_Panel *)param_1,param_2,param_3,param_4,param_5);
    *unaff_FS_OFFSET = uStack_c;
    return lVar8;
  }
  pTVar2 = *(TPanel **)((int)&param_1->tool_box + 3);
  if (((param_2 != pTVar2) && (pTVar2->active != 0)) &&
     (iVar3 = (**(code **)(pTVar2->_padding_ + 0xb4))(param_2,param_3,param_4,param_5), iVar3 != 0))
{
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
  if ((param_3 == 1) || (param_3 == 4)) {
    iVar3 = 0;
    piVar9 = (int *)((int)param_1->button_panel + 3);
    do {
      if (param_2 == (TPanel *)*piVar9) {
        TRIBE_Screen_Game::do_button_action(param_1,param_4,param_5,(uint)(param_3 == 4));
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
      iVar3 = iVar3 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar3 < 0x11);
  }
  if ((param_2 == *(TPanel **)((int)&param_1->object_panel + 3)) && (param_3 == 1)) {
    TRIBE_Screen_Game::object_changed(param_1);
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
  pcVar4 = TPanel::panelName(param_2);
  if (pcVar4 == (char *)0x0) goto LAB_0049874d;
  pbVar10 = &s_RestartDialog;
  pbVar5 = (byte *)TPanel::panelName(param_2);
  do {
    bVar1 = *pbVar5;
    bVar11 = bVar1 < *pbVar10;
    if (bVar1 != *pbVar10) {
LAB_004983ee:
      iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_004983f3;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar11 = bVar1 < pbVar10[1];
    if (bVar1 != pbVar10[1]) goto LAB_004983ee;
    pbVar5 = pbVar5 + 2;
    pbVar10 = pbVar10 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004983f3:
  if (iVar3 == 0) {
    TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,&s_RestartDialog);
    if (param_3 == 0) {
      TRIBE_Game::restart_game((TRIBE_Game *)rge_base_game);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
LAB_00498701:
    iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if ((iVar3 == 1) && (rge_base_game->save_paused == 0)) {
      RGE_Base_Game::set_paused(rge_base_game,0,0);
    }
  }
  else {
    pbVar10 = &s_QuitGameDialog;
    pbVar5 = (byte *)TPanel::panelName(param_2);
    do {
      bVar1 = *pbVar5;
      bVar11 = bVar1 < *pbVar10;
      if (bVar1 != *pbVar10) {
LAB_00498472:
        iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_00498477;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar11 = bVar1 < pbVar10[1];
      if (bVar1 != pbVar10[1]) goto LAB_00498472;
      pbVar5 = pbVar5 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_00498477:
    if (iVar3 == 0) {
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,&s_QuitGameDialog);
      if (param_3 == 0) {
        TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
    }
    else {
      pbVar10 = &s_CloseProgramDialog;
      pbVar5 = (byte *)TPanel::panelName(param_2);
      do {
        bVar1 = *pbVar5;
        bVar11 = bVar1 < *pbVar10;
        if (bVar1 != *pbVar10) {
LAB_004984f6:
          iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_004984fb;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar11 = bVar1 < pbVar10[1];
        if (bVar1 != pbVar10[1]) goto LAB_004984f6;
        pbVar5 = pbVar5 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_004984fb:
      if (iVar3 != 0) {
        pbVar10 = &s_ResignDialog;
        pbVar5 = (byte *)TPanel::panelName(param_2);
        do {
          bVar1 = *pbVar5;
          bVar11 = bVar1 < *pbVar10;
          if (bVar1 != *pbVar10) {
LAB_004985ce:
            iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_004985d3;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar11 = bVar1 < pbVar10[1];
          if (bVar1 != pbVar10[1]) goto LAB_004985ce;
          pbVar5 = pbVar5 + 2;
          pbVar10 = pbVar10 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_004985d3:
        if (iVar3 == 0) {
          TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,&s_ResignDialog);
          if (param_3 == 0) {
            *(undefined4 *)&param_1->field_0x730 = 1;
            pRVar6 = RGE_Base_Game::get_player(rge_base_game);
            iVar3 = pRVar6->_padding_;
            iVar7 = TCommunications_Handler::WhoAmI(comm);
            (**(code **)(iVar3 + 0xd4))(iVar7,param_3);
            *unaff_FS_OFFSET = unaff_EBP;
            return 1;
          }
        }
        else {
          pbVar10 = &s_QuitAndLoadDialog;
          pbVar5 = (byte *)TPanel::panelName(param_2);
          do {
            bVar1 = *pbVar5;
            bVar11 = bVar1 < *pbVar10;
            if (bVar1 != *pbVar10) {
LAB_00498679:
              iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
              goto LAB_0049867e;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar5[1];
            bVar11 = bVar1 < pbVar10[1];
            if (bVar1 != pbVar10[1]) goto LAB_00498679;
            pbVar5 = pbVar5 + 2;
            pbVar10 = pbVar10 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_0049867e:
          if (iVar3 != 0) goto LAB_0049874d;
          TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,&s_QuitAndLoadDialog);
          if (param_3 == 0) {
            this = (TribeLoadSavedGameScreen *)operator_new(0x494);
            iStack_4 = param_3;
            if (this != (TribeLoadSavedGameScreen *)0x0) {
              TribeLoadSavedGameScreen::TribeLoadSavedGameScreen(this);
            }
            iStack_4 = 0xffffffff;
            TPanelSystem::setCurrentPanel(&panel_system,s_Load_Saved_Game_Screen,0);
            *unaff_FS_OFFSET = uStack_c;
            return 1;
          }
        }
        goto LAB_00498701;
      }
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,&s_CloseProgramDialog);
      if (param_3 == 0) {
        RGE_Base_Game::close(rge_base_game);
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
    }
    confirmed_close = 0;
    iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if ((iVar3 == 1) && (rge_base_game->save_paused == 0)) {
      RGE_Base_Game::set_paused(rge_base_game,0,0);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0049879b
// Address: 0049879b
// XREFS: None
void __thiscall FUN_0049879b(TRIBE_Screen_Game *param_1,undefined4 param_2,int param_3,int param_4)
{
  if (allow_user_commands == 0) {
    switch(param_2) {
    case 6:
      goto switchD_004987bc_caseD_6;
    default:
switchD_004987bc_caseD_a:
      return;
    case 8:
switchD_004987bc_caseD_8:
      TRIBE_Screen_Game::command_group(param_1);
      return;
    case 9:
switchD_004987bc_caseD_9:
      TRIBE_Screen_Game::command_ungroup(param_1);
      return;
    case 0xb:
switchD_004987bc_caseD_b:
      TRIBE_Screen_Game::command_cancel(param_1);
      return;
    case 0xc:
switchD_004987bc_caseD_c:
      TRIBE_Screen_Game::command_more(param_1);
      return;
    case 0xd:
switchD_004987bc_caseD_d:
      TRIBE_Screen_Game::command_chat(param_1);
      return;
    case 0xe:
switchD_004987bc_caseD_e:
      TRIBE_Screen_Game::command_diplomacy(param_1);
      return;
    case 0xf:
switchD_004987bc_caseD_f:
      TRIBE_Screen_Game::command_menu(param_1);
      return;
    case 0x15:
switchD_004987bc_caseD_15:
      TEasy_Panel::setup_popup_help((TEasy_Panel *)param_1);
      return;
    case 0x18:
switchD_004987bc_caseD_18:
      TRIBE_Screen_Game::command_score
                (param_1,(uint)(*(char *)(*(int *)((int)&param_1->world + 3) + 0x11c) == '\0'));
      return;
    }
  }
  switch(param_2) {
  case 1:
    TRIBE_Screen_Game::command_work(param_1);
    return;
  case 2:
    TRIBE_Screen_Game::command_move(param_1);
    return;
  case 3:
    TRIBE_Screen_Game::command_build(param_1);
    return;
  case 4:
    TRIBE_Screen_Game::command_trade(param_1);
    return;
  case 5:
    TRIBE_Screen_Game::command_stop(param_1);
    return;
  case 6:
switchD_004987bc_caseD_6:
    TRIBE_Screen_Game::command_unselect(param_1);
    return;
  case 7:
    TRIBE_Screen_Game::command_unload(param_1);
    return;
  case 8:
    goto switchD_004987bc_caseD_8;
  case 9:
    goto switchD_004987bc_caseD_9;
  default:
    goto switchD_004987bc_caseD_a;
  case 0xb:
    goto switchD_004987bc_caseD_b;
  case 0xc:
    goto switchD_004987bc_caseD_c;
  case 0xd:
    goto switchD_004987bc_caseD_d;
  case 0xe:
    goto switchD_004987bc_caseD_e;
  case 0xf:
    goto switchD_004987bc_caseD_f;
  case 0x10:
    TRIBE_Screen_Game::command_trade_with(param_1,param_3);
    return;
  case 0x11:
    TRIBE_Screen_Game::command_research(param_1,param_3);
    return;
  case 0x12:
    TRIBE_Screen_Game::command_train(param_1,param_3,(-(ushort)(param_4 != 0) & 0xfffe) + 1);
    return;
  case 0x13:
    TRIBE_Screen_Game::command_building(param_1,param_3);
    return;
  case 0x14:
    TRIBE_Screen_Game::command_cancel_building(param_1);
    return;
  case 0x15:
    goto switchD_004987bc_caseD_15;
  case 0x16:
    TRIBE_Screen_Game::command_stand_ground(param_1);
    return;
  case 0x17:
    TRIBE_Screen_Game::command_attack_ground(param_1);
    return;
  case 0x18:
    goto switchD_004987bc_caseD_18;
  case 0x19:
    TRIBE_Screen_Game::command_trade_attribute(param_1,0);
    return;
  case 0x1a:
    TRIBE_Screen_Game::command_trade_attribute(param_1,1);
    return;
  case 0x1b:
    TRIBE_Screen_Game::command_trade_attribute(param_1,2);
    return;
  case 0x1c:
    TRIBE_Screen_Game::command_heal(param_1);
    return;
  case 0x1d:
    TRIBE_Screen_Game::command_convert(param_1);
    return;
  case 0x1e:
    TRIBE_Screen_Game::command_attack(param_1);
    return;
  case 0x1f:
    TRIBE_Screen_Game::command_repair(param_1);
    return;
  case 0x20:
    TRIBE_Screen_Game::command_train(param_1,param_3,1);
    return;
  case 0x21:
    TRIBE_Screen_Game::command_train(param_1,param_3,-1);
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00498943
// Address: 00498943
// XREFS: None
void FUN_00498943(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00498a41
// Address: 00498a41
// XREFS: None
// [HELPER] s_btn6__d: "btn6_%d"
// [HELPER] s_btnbrda_d_shp: "btnbrda%d.shp"
// [HELPER] s_btnbrdb_d_shp: "btnbrdb%d.shp"
// [HELPER] s_btnbrdc_d_shp: "btnbrdc%d.shp"
// [HELPER] s_btnoth_d_shp: "btnoth%d.shp"
// [HELPER] s_dlg6__d: "dlg6_%d"
// [HELPER] s_gamea_d_shp: "gamea%d.shp"
// [HELPER] s_gameb_d_shp: "gameb%d.shp"
// [HELPER] s_gamec_d_shp: "gamec%d.shp"
void __fastcall FUN_00498a41(TRIBE_Screen_Game *param_1)
{
  byte bVar1;
  int iVar2;
  TRIBE_Player *pTVar3;
  TShape *pTVar4;
  undefined4 uVar5;
  long lVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *unaff_FS_OFFSET;
  uchar uVar9;
  uchar uVar10;
  uchar uVar11;
  uchar uVar12;
  uchar uVar13;
  ulong uVar14;
  uchar uVar15;
  short sVar16;
  int iVar17;
  ulong uVar18;
  char acStack_20c [508];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ee4e;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar3 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  RGE_View::set_player(*(RGE_View **)((int)&param_1->main_view + 3),(RGE_Player *)pTVar3);
  RGE_Diamond_Map::set_player
            (*(RGE_Diamond_Map **)((int)&param_1->map_view + 3),(RGE_Player *)pTVar3);
  TRIBE_Panel_Inven::set_player(*(TRIBE_Panel_Inven **)((int)&param_1->inven_panel + 3),pTVar3);
  TRIBE_Panel_Object::set_player(*(TRIBE_Panel_Object **)((int)&param_1->object_panel + 3),pTVar3);
  TRIBE_Screen_Game::game_mode_changed(param_1,rge_base_game->game_mode,rge_base_game->game_mode);
  TRIBE_Screen_Game::object_changed(param_1);
  TRIBE_Screen_Game::age_changed(param_1);
  if (*(short *)((int)&pTVar3->_padding_ + 2) == 0) goto LAB_0049929e;
  bVar1 = (byte)pTVar3->_padding_;
  uVar8 = (uint)bVar1;
  if ((uVar8 == *(uint *)&param_1->field_0x714) &&
     (*(int *)&param_1->field_0x14 == *(int *)&param_1->field_0x718)) goto LAB_0049929e;
  *(uint *)&param_1->field_0x714 = uVar8;
  *(undefined4 *)&param_1->field_0x718 = *(undefined4 *)&param_1->field_0x14;
  if (4 < bVar1) {
    uVar8 = 0;
  }
  sprintf(acStack_20c,s_dlg6__d,uVar8);
  if (uVar8 == 4) {
    TEasy_Panel::set_info_file((TEasy_Panel *)param_1,acStack_20c,53000);
    iVar17 = 53000;
  }
  else {
    iVar17 = uVar8 + 0xc356;
    TEasy_Panel::set_info_file((TEasy_Panel *)param_1,acStack_20c,iVar17);
  }
  TEasy_Panel::set_popup_info_file((TEasy_Panel *)param_1,acStack_20c,iVar17);
  sprintf(acStack_20c,s_btn6__d,uVar8);
  if (uVar8 == 4) {
    iVar17 = 0xcf0c;
  }
  else {
    iVar17 = uVar8 + 0xc5ad;
  }
  TEasy_Panel::set_button_pics((TEasy_Panel *)param_1,acStack_20c,iVar17);
  switch(uVar8) {
  case 0:
    uVar15 = '8';
    uVar13 = 0xee;
    uVar12 = 'o';
    uVar11 = 'o';
    uVar10 = 'm';
    uVar9 = '~';
    break;
  case 1:
    uVar15 = 0xb8;
    uVar13 = 0xb7;
    uVar12 = 't';
    uVar11 = 't';
    uVar10 = 's';
    uVar9 = 'r';
    break;
  case 2:
    uVar15 = 'y';
    uVar13 = 'x';
    uVar12 = 'x';
    uVar11 = 'x';
    uVar10 = 'w';
    uVar9 = 0xb9;
    break;
  case 3:
    uVar15 = 0x95;
    uVar13 = '8';
    uVar12 = 0xee;
    uVar11 = 0xee;
    uVar10 = 0xed;
    uVar9 = 0x8a;
    break;
  case 4:
    uVar15 = 'w';
    uVar13 = 'v';
    uVar12 = 'u';
    uVar11 = 'u';
    uVar10 = 't';
    uVar9 = 's';
    break;
  default:
    goto switchD_00498ba4_default;
  }
  TEasy_Panel::set_bevel_colors((TEasy_Panel *)param_1,uVar9,uVar10,uVar11,uVar12,uVar13,uVar15);
switchD_00498ba4_default:
  TButtonPanel::set_bevel_info
            (*(TButtonPanel **)((int)param_1->button_panel + 0x33),3,
             (uint)(byte)param_1->field_0x320,(uint)(byte)param_1->field_0x321,
             (uint)(byte)param_1->field_0x322,(uint)(byte)param_1->field_0x323,
             (uint)(byte)param_1->field_0x324,(uint)(byte)param_1->field_0x325);
  TButtonPanel::set_bevel_info
            (*(TButtonPanel **)((int)param_1->button_panel + 0x37),3,
             (uint)(byte)param_1->field_0x320,(uint)(byte)param_1->field_0x321,
             (uint)(byte)param_1->field_0x322,(uint)(byte)param_1->field_0x323,
             (uint)(byte)param_1->field_0x324,(uint)(byte)param_1->field_0x325);
  TButtonPanel::set_bevel_info
            (*(TButtonPanel **)((int)param_1->button_panel + 0x3b),3,
             (uint)(byte)param_1->field_0x320,(uint)(byte)param_1->field_0x321,
             (uint)(byte)param_1->field_0x322,(uint)(byte)param_1->field_0x323,
             (uint)(byte)param_1->field_0x324,(uint)(byte)param_1->field_0x325);
  TButtonPanel::set_bevel_info
            (*(TButtonPanel **)((int)param_1->button_panel + 0x3f),4,
             (uint)(byte)param_1->field_0x320,(uint)(byte)param_1->field_0x321,
             (uint)(byte)param_1->field_0x322,(uint)(byte)param_1->field_0x323,
             (uint)(byte)param_1->field_0x324,(uint)(byte)param_1->field_0x325);
  TButtonPanel::set_bevel_info
            (*(TButtonPanel **)((int)param_1->button_panel + 0x43),4,
             (uint)(byte)param_1->field_0x320,(uint)(byte)param_1->field_0x321,
             (uint)(byte)param_1->field_0x322,(uint)(byte)param_1->field_0x323,
             (uint)(byte)param_1->field_0x324,(uint)(byte)param_1->field_0x325);
  pTVar4 = *(TShape **)((int)&param_1->button_border1_pic + 3);
  if (pTVar4 != (TShape *)0x0) {
    TShape::~TShape(pTVar4);
    operator_delete(pTVar4);
  }
  sprintf(acStack_20c,s_btnbrda_d_shp,uVar8);
  if (uVar8 == 4) {
    pTVar4 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTVar4 == (TShape *)0x0) {
LAB_00498df2:
      uVar5 = 0;
    }
    else {
      uVar5 = TShape::TShape(pTVar4,acStack_20c,0xcf0e);
    }
  }
  else {
    pTVar4 = (TShape *)operator_new(0x20);
    uStack_4 = 1;
    if (pTVar4 == (TShape *)0x0) goto LAB_00498df2;
    uVar5 = TShape::TShape(pTVar4,acStack_20c,uVar8 + 0xc619);
  }
  pTVar4 = *(TShape **)((int)&param_1->button_other_pic + 3);
  uStack_4 = 0xffffffff;
  *(undefined4 *)((int)&param_1->button_border1_pic + 3) = uVar5;
  if (pTVar4 != (TShape *)0x0) {
    TShape::~TShape(pTVar4);
    operator_delete(pTVar4);
  }
  sprintf(acStack_20c,s_btnoth_d_shp,uVar8);
  if (uVar8 == 4) {
    pTVar4 = (TShape *)operator_new(0x20);
    uStack_4 = 2;
    if (pTVar4 == (TShape *)0x0) {
LAB_00498e96:
      uVar5 = 0;
    }
    else {
      uVar5 = TShape::TShape(pTVar4,acStack_20c,0xcf11);
    }
  }
  else {
    pTVar4 = (TShape *)operator_new(0x20);
    uStack_4 = 3;
    if (pTVar4 == (TShape *)0x0) goto LAB_00498e96;
    uVar5 = TShape::TShape(pTVar4,acStack_20c,uVar8 + 0xc625);
  }
  pTVar4 = *(TShape **)((int)&param_1->button_border2_pic + 3);
  uStack_4 = 0xffffffff;
  *(undefined4 *)((int)&param_1->button_other_pic + 3) = uVar5;
  if (pTVar4 != (TShape *)0x0) {
    TShape::~TShape(pTVar4);
    operator_delete(pTVar4);
  }
  sprintf(acStack_20c,s_btnbrdb_d_shp,uVar8);
  if (uVar8 == 4) {
    pTVar4 = (TShape *)operator_new(0x20);
    uStack_4 = 4;
    if (pTVar4 == (TShape *)0x0) {
LAB_00498f37:
      uVar5 = 0;
    }
    else {
      uVar5 = TShape::TShape(pTVar4,acStack_20c,0xcf0f);
    }
  }
  else {
    pTVar4 = (TShape *)operator_new(0x20);
    uStack_4 = 5;
    if (pTVar4 == (TShape *)0x0) goto LAB_00498f37;
    uVar5 = TShape::TShape(pTVar4,acStack_20c,uVar8 + 0xc61d);
  }
  pTVar4 = *(TShape **)((int)&param_1->button_border3_pic + 3);
  uStack_4 = 0xffffffff;
  *(undefined4 *)((int)&param_1->button_border2_pic + 3) = uVar5;
  if (pTVar4 != (TShape *)0x0) {
    TShape::~TShape(pTVar4);
    operator_delete(pTVar4);
  }
  sprintf(acStack_20c,s_btnbrdc_d_shp,uVar8);
  if (uVar8 == 4) {
    pTVar4 = (TShape *)operator_new(0x20);
    uStack_4 = 6;
    if (pTVar4 == (TShape *)0x0) {
LAB_00498fd8:
      uVar5 = 0;
    }
    else {
      uVar5 = TShape::TShape(pTVar4,acStack_20c,0xcf10);
    }
  }
  else {
    pTVar4 = (TShape *)operator_new(0x20);
    uStack_4 = 7;
    if (pTVar4 == (TShape *)0x0) goto LAB_00498fd8;
    uVar5 = TShape::TShape(pTVar4,acStack_20c,uVar8 + 0xc63b);
  }
  pTVar4 = *(TShape **)((int)&param_1->game_screen_pic + 3);
  uStack_4 = 0xffffffff;
  *(undefined4 *)((int)&param_1->button_border3_pic + 3) = uVar5;
  if (pTVar4 != (TShape *)0x0) {
    TShape::~TShape(pTVar4);
    operator_delete(pTVar4);
  }
  if ((*(int *)&param_1->field_0x14 < 0x400) || (*(int *)&param_1->field_0x18 < 0x300)) {
    if ((*(int *)&param_1->field_0x14 < 800) || (*(int *)&param_1->field_0x18 < 600)) {
      sprintf(acStack_20c,s_gamea_d_shp,uVar8);
      iVar17 = 0xcf12;
      if (uVar8 != 4) {
        iVar17 = uVar8 + 0xc62d;
      }
    }
    else {
      sprintf(acStack_20c,s_gameb_d_shp,uVar8);
      if (uVar8 == 4) {
        iVar17 = 0xcf13;
      }
      else {
        iVar17 = uVar8 + 0xc631;
      }
    }
  }
  else {
    sprintf(acStack_20c,s_gamec_d_shp,uVar8);
    if (uVar8 == 4) {
      iVar17 = 0xcf14;
    }
    else {
      iVar17 = uVar8 + 0xc635;
    }
  }
  pTVar4 = (TShape *)operator_new(0x20);
  uStack_4 = 8;
  if (pTVar4 == (TShape *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = TShape::TShape(pTVar4,acStack_20c,iVar17);
  }
  *(undefined4 *)((int)&param_1->game_screen_pic + 3) = uVar5;
  uStack_4 = 0xffffffff;
  iVar17 = 0;
  piVar7 = (int *)((int)param_1->button_panel + 3);
  do {
    if (iVar17 < 0xc) {
      uVar5 = *(undefined4 *)((int)&param_1->button_border1_pic + 3);
    }
    else {
      uVar5 = *(undefined4 *)((int)&param_1->button_border2_pic + 3);
    }
    iVar2 = *piVar7;
    iVar17 = iVar17 + 1;
    piVar7 = piVar7 + 1;
    *(undefined4 *)(iVar2 + 0x2c4) = uVar5;
  } while (iVar17 < 0x11);
  if ((*(int *)&param_1->field_0x14 < 800) || (*(int *)&param_1->field_0x18 < 600)) {
    *(undefined4 *)((int)&param_1->more_cancel_pic + 3) =
         *(undefined4 *)((int)&param_1->button_other_pic + 3);
  }
  else {
    *(undefined4 *)((int)&param_1->more_cancel_pic + 3) =
         *(undefined4 *)((int)&param_1->button_cmd_pic + 3);
  }
  TButtonPanel::set_picture
            (*(TButtonPanel **)((int)param_1->button_panel + 0x17),0,
             *(TShape **)((int)&param_1->more_cancel_pic + 3),
             *(short *)((int)&param_1->cancel_frame + 1));
  lVar6 = TButtonPanel::get_id(*(TButtonPanel **)((int)param_1->button_panel + 0x2f));
  if (lVar6 == 6) {
    sVar16 = *(short *)&param_1->field_0x4b4;
    pTVar4 = *(TShape **)((int)&param_1->more_cancel_pic + 3);
  }
  else {
    sVar16 = *(short *)((int)&param_1->unselect_frame + 1);
    pTVar4 = *(TShape **)((int)&param_1->more_cancel_pic + 3);
  }
  TButtonPanel::set_picture(*(TButtonPanel **)((int)param_1->button_panel + 0x2f),0,pTVar4,sVar16);
  if (((uVar8 == 2) || (uVar8 == 3)) || (uVar8 == 4)) {
    TRIBE_Panel_Inven::set_text_color
              (*(TRIBE_Panel_Inven **)((int)&param_1->inven_panel + 3),0xffffff,0);
    TTextPanel::set_text_color(*(TTextPanel **)((int)&param_1->age_panel + 3),0xffffff,0);
    TButtonPanel::set_text_color(*(TButtonPanel **)((int)param_1->button_panel + 0x33),0,0xffffff,0)
    ;
    TButtonPanel::set_text_color(*(TButtonPanel **)((int)param_1->button_panel + 0x37),0,0xffffff,0)
    ;
    TButtonPanel::set_text_color(*(TButtonPanel **)((int)param_1->button_panel + 0x3b),0,0xffffff,0)
    ;
    TButtonPanel::set_text_color(*(TButtonPanel **)((int)param_1->button_panel + 0x3f),0,0xffffff,0)
    ;
    uVar18 = 0;
    uVar14 = 0xffffff;
  }
  else {
    TRIBE_Panel_Inven::set_text_color
              (*(TRIBE_Panel_Inven **)((int)&param_1->inven_panel + 3),0,0xffffff);
    TTextPanel::set_text_color(*(TTextPanel **)((int)&param_1->age_panel + 3),0,0xffffff);
    TButtonPanel::set_text_color(*(TButtonPanel **)((int)param_1->button_panel + 0x33),0,0,0xffffff)
    ;
    TButtonPanel::set_text_color(*(TButtonPanel **)((int)param_1->button_panel + 0x37),0,0,0xffffff)
    ;
    TButtonPanel::set_text_color(*(TButtonPanel **)((int)param_1->button_panel + 0x3b),0,0,0xffffff)
    ;
    TButtonPanel::set_text_color(*(TButtonPanel **)((int)param_1->button_panel + 0x3f),0,0,0xffffff)
    ;
    uVar18 = 0xffffff;
    uVar14 = 0;
  }
  TButtonPanel::set_text_color
            (*(TButtonPanel **)((int)param_1->button_panel + 0x43),0,uVar14,uVar18);
LAB_0049929e:
  TRIBE_Screen_Game::setup_buttons(param_1);
  (**(code **)(*(int *)param_1 + 0x20))(1);
  *unaff_FS_OFFSET = uStack_10;
  return;
}

// --------------------------------------------------

// Function: FUN_004992c9
// Address: 004992c9
// XREFS: None
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */

void __fastcall FUN_004992c9(undefined4 *param_1)
{
  TRIBE_Screen_Game *this;
  RGE_Static_Object *pRVar1;
  RGE_Static_Object *pRVar2;
  RGE_View *this_00;
  int iVar3;
  code *pcVar4;
  char cVar5;
  undefined4 in_EAX;
  RGE_Player *pRVar6;
  TButtonPanel *this_01;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  TRIBE_Screen_Game *unaff_ESI;
  undefined4 *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  char in_ZF;
  
  puRamd0004983 = unaff_EDI + 1;
  *unaff_EDI = in_EAX;
  this_01 = (TButtonPanel *)(*(int *)*param_1 + -1);
  if (this_01 == (TButtonPanel *)0x0 || in_ZF == '\0') {
    this = *(TRIBE_Screen_Game **)(*(int *)*param_1 + -2);
    puVar8 = (undefined1 *)0xd0004983;
    uRamd000497f = 0x4992ef;
    pTRamd0004987 = unaff_ESI;
    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    pRVar1 = *(RGE_Static_Object **)((int)&this->game_obj + 3);
    pRVar2 = pRVar6->selected_obj;
    uRamd000497f = 0x49930f;
    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    *(RGE_Static_Object **)((int)&this->game_obj + 3) = pRVar6->selected_obj;
    uRamd000497f = 0x499326;
    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    *(short *)&this->field_0x5cc = pRVar6->sel_count;
    if (pRVar1 != pRVar2) {
      if (rge_base_game->game_mode == 0x15) {
        puVar8 = (undefined1 *)0xd000497f;
        uRamd000497f = 0x499355;
        (**(code **)(**(int **)((int)&this->main_view + 3) + 0xf0))();
        this_00 = *(RGE_View **)((int)&this->main_view + 3);
        *(undefined4 *)(puVar8 + -4) = 0xffffffff;
        *(undefined4 *)(puVar8 + -8) = 0xffffffff;
        *(undefined4 *)(puVar8 + -0xc) = 0xffffffff;
        *(undefined4 *)(puVar8 + -0x10) = 0xffffffff;
        *(undefined4 *)(puVar8 + -0x14) = 0x499368;
        RGE_View::set_selection_area
                  (this_00,*(long *)(puVar8 + -0x10),*(long *)(puVar8 + -0xc),*(long *)(puVar8 + -8)
                   ,*(long *)(puVar8 + -4));
      }
      cVar5 = (char)rge_base_game->game_mode;
      if (((((cVar5 != '\x01') && (cVar5 != '\x12')) && (cVar5 != '\x0e')) &&
          ((cVar5 != '\x02' && (cVar5 != '\x03')))) &&
         ((cVar5 != '\b' && ((cVar5 != '\t' && (cVar5 != '\n')))))) {
        iVar3 = rge_base_game->_padding_;
        *(undefined4 *)(puVar8 + -4) = 0;
        *(undefined4 *)(puVar8 + -8) = 0;
        pcVar4 = *(code **)(iVar3 + 0x10);
        puVar9 = (undefined4 *)(puVar8 + -0xc);
        puVar8 = puVar8 + -0xc;
        *puVar9 = 0x49939d;
        (*pcVar4)();
      }
    }
    *(undefined4 *)(puVar8 + -4) = 0x4993a4;
    TRIBE_Screen_Game::reset_buttons(this);
    return;
  }
  pTRamd0004987 = (TRIBE_Screen_Game *)0xffffff;
  puRamd0004983 = (undefined4 *)0x0;
  uRamd000497f = 0x499276;
  TButtonPanel::set_text_color(this_01,0,0xffffff,uRamd000498b);
  uRamd000498b = 0;
  pTRamd0004987 = (TRIBE_Screen_Game *)0xffffff;
  puRamd0004983 = (undefined4 *)0x0;
  uRamd000497f = 0x49928a;
  TButtonPanel::set_text_color(*(TButtonPanel **)((int)unaff_ESI->button_panel + 0x3f),0,0xffffff,0)
  ;
  uRamd000498b = 0;
  pTRamd0004987 = (TRIBE_Screen_Game *)0xffffff;
  puRamd0004983 = (undefined4 *)0x0;
  uRamd000497f = 0x49929e;
  TButtonPanel::set_text_color(*(TButtonPanel **)((int)unaff_ESI->button_panel + 0x43),0,0xffffff,0)
  ;
  uRamd000498b = 0x4992a5;
  TRIBE_Screen_Game::setup_buttons(unaff_ESI);
  uRamd000498b = 1;
  puVar7 = (undefined1 *)0xd0004987;
  pTRamd0004987 = (TRIBE_Screen_Game *)0x4992ae;
  (**(code **)(*(int *)unaff_ESI + 0x20))();
  *unaff_FS_OFFSET = *(undefined4 *)(puVar7 + 0x214);
  return;
}

// --------------------------------------------------

// Function: FUN_004993a7
// Address: 004993a7
// XREFS: None
void __fastcall FUN_004993a7(int param_1)
{
  undefined4 uVar1;
  undefined4 uStack_214;
  undefined1 *puStack_210;
  undefined4 uStack_20c;
  undefined1 auStack_200 [512];
  
  if (*(int *)(param_1 + 0x580) != 0) {
    uStack_20c = 0x4993d3;
    RGE_Base_Game::get_player(rge_base_game);
    uStack_20c = 0x4993de;
    uVar1 = __ftol();
    *(undefined4 *)(param_1 + 0x710) = uVar1;
    puStack_210 = auStack_200;
    uStack_20c = 0x200;
    uStack_214 = 0;
    (**(code **)(rge_base_game->_padding_ + 0x28))(0x65,uVar1);
    (**(code **)(**(int **)(param_1 + 0x580) + 0xe8))(&uStack_214);
    (**(code **)(**(int **)(param_1 + 0x580) + 0x20))(1);
    switch(*(undefined4 *)(param_1 + 0x710)) {
    case 1:
      TPanel::set_help_info(*(TPanel **)(param_1 + 0x580),0x1069,-1);
      return;
    case 2:
      TPanel::set_help_info(*(TPanel **)(param_1 + 0x580),0x106a,-1);
      return;
    case 3:
      TPanel::set_help_info(*(TPanel **)(param_1 + 0x580),0x106b,-1);
      return;
    case 4:
      TPanel::set_help_info(*(TPanel **)(param_1 + 0x580),0x106c,-1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049949d
// Address: 0049949d
// XREFS: None
void __fastcall
FUN_0049949d(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,byte *param_5)
{
  uint *puVar1;
  byte bVar2;
  undefined4 in_EAX;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int unaff_EDI;
  bool bVar6;
  
  puVar1 = (uint *)(param_1 * 3 + 0x49944c00);
  *puVar1 = *puVar1 ^ param_2;
  *(char *)(unaff_EDI + -0x6c) = *(char *)(unaff_EDI + -0x6c) + (char)((uint)in_EAX >> 8);
  *(char *)(param_2 + 0x53004994) = *(char *)(param_2 + 0x53004994) + (char)in_EAX;
  pbVar3 = (byte *)TTextPanel::get_text(*(TTextPanel **)(param_1 + 0x587));
  pbVar5 = param_5;
  if (pbVar3 != (byte *)0x0) {
    do {
      bVar2 = *pbVar3;
      bVar6 = bVar2 < *pbVar5;
      if (bVar2 != *pbVar5) {
LAB_004994f3:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_004994f8;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar6 = bVar2 < pbVar5[1];
      if (bVar2 != pbVar5[1]) goto LAB_004994f3;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_004994f8:
    if (iVar4 == 0) {
      return;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x587) + 0xe8))(param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_00499512
// Address: 00499512
// XREFS: None
void __thiscall
FUN_00499512(int param_1,char *param_2,char *param_3,char *param_4,char *param_5,char *param_6,
            char *param_7)
{
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x544),DebugMessage,param_2,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x548),DebugMessage,param_3,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x54c),DebugMessage,param_4,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x550),DebugMessage,param_5,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x554),DebugMessage,param_6,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x558),DebugMessage,param_7,'V','\0',(void *)0x0,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004995cf
// Address: 004995cf
// XREFS: None
void __thiscall
FUN_004995cf(int param_1,char *param_2,char *param_3,char *param_4,char *param_5,char *param_6,
            char *param_7)
{
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x544),DebugMessage,param_2,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x548),DebugMessage,param_3,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x54c),DebugMessage,param_4,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x550),DebugMessage,param_5,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x554),DebugMessage,param_6,'V','\0',(void *)0x0,0,0);
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x558),DebugMessage,param_7,'V','\0',(void *)0x0,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0049967f
// Address: 0049967f
// XREFS: None
void __thiscall
FUN_0049967f(int param_1,MessageType param_2,char *param_3,uchar param_4,uchar param_5)
{
  TMessagePanel::show_message
            (*(TMessagePanel **)(param_1 + 0x544),param_2,param_3,param_4,param_5,(void *)0x0,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004996a8
// Address: 004996a8
// XREFS: None
void __fastcall FUN_004996a8(TRIBE_Screen_Game *param_1)
{
  *(undefined2 *)((int)&param_1->last_item + 1) = 0;
  TRIBE_Screen_Game::setup_buttons(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004996be
// Address: 004996be
// XREFS: None
// [HELPER] production_queues_is_use: ""
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004996be(TRIBE_Screen_Game *param_1)
{
  Item_Avail **ppIVar1;
  byte bVar2;
  char cVar3;
  RGE_Action_Object *this;
  bool bVar4;
  uint uVar5;
  TRIBE_Building_Object *pTVar6;
  uchar uVar7;
  short sVar8;
  short sVar9;
  int *piVar10;
  TRIBE_Player *this_00;
  short *psVar11;
  Production_Queue_Record *pPVar12;
  undefined2 extraout_var;
  Item_Avail *pIVar13;
  undefined2 extraout_var_00;
  int iVar14;
  int iVar15;
  TRIBE_Building_Object *pTVar16;
  uchar *puVar17;
  ushort uVar18;
  TShape *pTVar19;
  long lVar20;
  char *pcVar21;
  char *pcVar22;
  undefined4 uVar23;
  int iStack_430;
  uint uStack_42c;
  int iStack_428;
  TRIBE_Building_Object *pTStack_424;
  TRIBE_Building_Object *pTStack_420;
  undefined4 uStack_41c;
  int iStack_418;
  uint uStack_414;
  short asStack_410 [3];
  short sStack_40a;
  undefined4 uStack_408;
  short sStack_402;
  char acStack_400 [512];
  char acStack_200 [512];
  
  *(undefined2 *)((int)&param_1->start_item + 1) = 0;
  *(undefined2 *)&param_1->field_0x5e4 = 0xffff;
  piVar10 = (int *)((int)param_1->button_panel + 3);
  iVar15 = 0xc;
  do {
    iVar14 = *piVar10;
    piVar10 = piVar10 + 1;
    iVar15 = iVar15 + -1;
    *(undefined4 *)(iVar14 + 0x3d0) = 0;
  } while (iVar15 != 0);
  iVar15 = *(int *)((int)&param_1->game_obj + 3);
  *(undefined4 *)((int)&param_1->anim_pal_table[6].money + 1) = 0xffffffff;
  *(undefined4 *)&param_1->field_0x70c = 0xffffffff;
  if (iVar15 == 0) goto LAB_0049a88c;
  this_00 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
  bVar2 = (byte)this_00->_padding_;
  uStack_42c = (uint)bVar2;
  if (5 < bVar2) {
    uStack_42c = 0;
  }
  if ((rge_base_game->game_mode == 6) && (rge_base_game->sub_game_mode == 1)) {
    psVar11 = (short *)((int)&param_1->start_item + 1);
    ppIVar1 = (Item_Avail **)((int)&param_1->bldg_list + 3);
    TRIBE_Player::interface_item_avail(this_00,ppIVar1,psVar11,0x76);
    sVar8 = *psVar11;
    iStack_430 = 0;
    pTStack_424 = (TRIBE_Building_Object *)0xffffffff;
    pTStack_420 = (TRIBE_Building_Object *)0xffffffff;
    if (0 < sVar8) {
      pTVar16 = (TRIBE_Building_Object *)0x0;
      psVar11 = &(*ppIVar1)->id;
      iVar15 = (int)sVar8;
      do {
        pTVar6 = pTVar16;
        if ((*psVar11 != 0x6d) && (pTVar6 = pTStack_424, *psVar11 == 0x57)) {
          pTStack_420 = pTVar16;
        }
        pTStack_424 = pTVar6;
        pTVar16 = (TRIBE_Building_Object *)((int)&pTVar16->_padding_ + 1);
        psVar11 = psVar11 + 0x14;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
    }
    iStack_428 = 0;
    if (0 < sVar8) {
      do {
        pTVar16 = (TRIBE_Building_Object *)(int)(short)iStack_428;
        iVar15 = *(int *)(this_00->_padding_ + (*ppIVar1)[(int)pTVar16].id * 4);
        uStack_414 = (uint)*(byte *)(iVar15 + 0x15e);
        if ((pTVar16 == pTStack_424) && (pTStack_420 == (TRIBE_Building_Object *)0xffffffff)) {
          uStack_414 = 6;
        }
        if (*(short *)((int)&param_1->last_item + 1) == 0) {
          if (uStack_414 < 0xb) {
LAB_00499837:
            (**(code **)(rge_base_game->_padding_ + 0x20))
                      ((int)*(short *)(iVar15 + 0xc),acStack_400,0x200);
            TRIBE_Screen_Game::calc_text_msg
                      (param_1,acStack_200,*ppIVar1 + (int)pTVar16,0x13,
                       (int)*(short *)(iVar15 + 0xe));
            sVar8 = TRIBE_Screen_Game::calc_button_loc(param_1,(uchar)uStack_414);
            pIVar13 = *ppIVar1;
            TRIBE_Screen_Game::set_button
                      (param_1,*(TShape **)((int)param_1->button_bldg_pics + uStack_42c * 4 + 3),
                       sVar8,*(short *)(iVar15 + 0x16e) + pIVar13[(int)pTVar16].pict,0x13,
                       (int)pIVar13[(int)pTVar16].id,*(short *)(iVar15 + 0xe) + 100000,
                       pIVar13[(int)pTVar16].help_page_id,*(long *)(iVar15 + 0xa0),
                       (uchar *)(this_00->_padding_ + 0x28),acStack_400,acStack_200,0);
          }
          else {
            iStack_430 = 1;
          }
        }
        else {
          if (10 < uStack_414) goto LAB_00499837;
          iStack_430 = 1;
        }
        iStack_428 = iStack_428 + 1;
      } while ((short)iStack_428 < *(short *)((int)&param_1->start_item + 1));
    }
    if (iStack_430 != 0) {
      TRIBE_Screen_Game::set_button
                (param_1,*(TShape **)((int)&param_1->more_cancel_pic + 3),5,
                 *(short *)((int)&param_1->cancel_frame + 1),0xc,0,0x1d4d7,-1,0,(uchar *)0x0,
                 (char *)0x0,(char *)0x0,0);
    }
    sVar8 = *(short *)((int)&param_1->unselect_frame + 1);
    pTVar19 = *(TShape **)((int)&param_1->more_cancel_pic + 3);
    lVar20 = 0xb;
  }
  else if ((rge_base_game->game_mode == 0) && (rge_base_game->prog_mode != 5)) {
    if (*(TRIBE_Player **)(*(int *)((int)&param_1->game_obj + 3) + 0xc) == this_00) {
      uVar7 = RGE_Player::unit_level_selected((RGE_Player *)this_00);
      if (uVar7 != '\x03') {
        if (uVar7 != '\t') {
          if (uVar7 != '\x04') {
            if (uVar7 == '\x06') {
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,0xd,0x1c,0,
                         0x1d4f1,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),1,0xe,0x1d,0,
                         0x1d4f2,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              iVar15 = TRIBE_Screen_Game::any_selected_have_action(param_1);
              if (iVar15 != 0) {
                TRIBE_Screen_Game::set_button
                          (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),2,3,5,0,0x1d4dd,
                           -1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              }
              if ((short)this_00->_padding_ < 2) {
LAB_00499e87:
                cVar3 = *(char *)(*(int *)((int)&param_1->game_obj + 3) + 0x37);
                goto joined_r0x00499e92;
              }
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,7,8,0,0x1d4e1,-1,
                         0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
              lVar20 = 0x4e43;
              sVar8 = 7;
              goto LAB_00499eae;
            }
            if (uVar7 == '\a') {
              uVar18 = 0;
              sVar8 = 0;
              sVar9 = 0;
              do {
                if ((short)this_00->_padding_ <= sVar9) break;
                if (((&this_00->_padding_)[sVar8] != 0) &&
                   (sVar9 = sVar9 + 1,
                   0 < *(short *)(*(int *)((&this_00->_padding_)[sVar8] + 0x24) + 8))) {
                  TRIBE_Screen_Game::set_button
                            (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,5,7,0,0x1d4e9
                             ,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
                  uVar18 = 1;
                  break;
                }
                sVar8 = sVar8 + 1;
              } while (sVar8 < 0x19);
              iVar15 = TRIBE_Screen_Game::any_selected_have_action(param_1);
              if (iVar15 != 0) {
LAB_0049a68a:
                TRIBE_Screen_Game::set_button
                          (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),uVar18,3,5,0,
                           0x1d4dd,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              }
LAB_0049a698:
              if ((short)this_00->_padding_ < 2) {
                if (*(char *)(*(int *)((int)&param_1->game_obj + 3) + 0x37) == '\0')
                goto LAB_0049a732;
                pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
                sVar8 = 6;
              }
              else {
                TRIBE_Screen_Game::set_button
                          (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,7,8,0,0x1d4e1,
                           -1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
                pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
                sVar8 = 7;
              }
              TRIBE_Screen_Game::set_button
                        (param_1,pTVar19,sVar8,8,9,0,0x1d4e3,-1,0,(uchar *)0x0,(char *)0x0,
                         (char *)0x0,0);
              goto LAB_0049a732;
            }
            if (uVar7 == '\x05') {
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_tech_pic + 3),1,0x57,0x19,0,
                         0x1a25c,0x265af,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_tech_pic + 3),2,0x56,0x1a,0,
                         0x1a25d,0x265af,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_tech_pic + 3),3,0x58,0x1b,0,
                         0x1a25e,0x265af,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              iVar15 = TRIBE_Screen_Game::any_selected_have_action(param_1);
              if (iVar15 != 0) {
                TRIBE_Screen_Game::set_button
                          (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,3,5,0,0x1d4dd,
                           -1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              }
              if ((short)this_00->_padding_ < 2) goto LAB_00499e87;
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,7,8,0,0x1d4e1,-1,
                         0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
              lVar20 = 0x1d4e3;
              sVar8 = 7;
              goto LAB_00499eae;
            }
            if ((uVar7 == '\x02') &&
               (pTVar16 = *(TRIBE_Building_Object **)((int)&param_1->game_obj + 3),
               pTStack_420 = pTVar16, *(char *)(pTVar16->_padding_ + 4) == 'P')) {
              TRIBE_Building_Object::work_status
                        (pTVar16,(short *)&uStack_408,&sStack_402,&sStack_40a,acStack_400,0x200);
              if (sStack_40a == 100) {
                uStack_408 = 0;
              }
              bVar2 = (byte)pTVar16->_padding_;
              if (bVar2 < 2) {
                TRIBE_Screen_Game::set_button
                          (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,3,0x14,0,
                           0x1d4e5,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
                sVar8 = *(short *)&param_1->field_0x4b4;
                pTVar19 = *(TShape **)((int)&param_1->more_cancel_pic + 3);
                lVar20 = 6;
                goto LAB_0049a885;
              }
              if (bVar2 == 2) {
                if (((short)uStack_408 != 0x67) &&
                   (((short)uStack_408 != 0x66 || (production_queues_is_use != '\0')))) {
                  ppIVar1 = (Item_Avail **)((int)&param_1->tech_list + 3);
                  TRIBE_Player::interface_tech_avail
                            (this_00,ppIVar1,(short *)&uStack_41c,
                             *(short *)(*(int *)(*(int *)((int)&param_1->game_obj + 3) + 8) + 0x10))
                  ;
                  TRIBE_Player::interface_item_avail
                            (this_00,(Item_Avail **)((int)&param_1->make_list + 3),asStack_410,
                             *(short *)(*(int *)(*(int *)((int)&param_1->game_obj + 3) + 8) + 0x10))
                  ;
                  uVar5 = uStack_42c;
                  uStack_42c = uStack_42c & 0xffffff00;
                  *(short *)((int)&param_1->start_item + 1) =
                       (short)asStack_410._0_4_ + (short)uStack_41c;
                  if ((production_queues_is_use != '\0') && (0 < pTVar16->production_queue_count)) {
                    uStack_42c._1_3_ = SUB43(uVar5,1);
                    uStack_42c = CONCAT31(uStack_42c._1_3_,1);
                    TRIBE_Screen_Game::set_button
                              (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,3,5,0,
                               0x1d4dd,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
                  }
                  iStack_428 = 0;
                  if (0 < asStack_410[0]) {
                    do {
                      iVar15 = (short)iStack_428 * 0x28;
                      pTVar16 = (TRIBE_Building_Object *)0x0;
                      pTStack_424 = (TRIBE_Building_Object *)0x0;
                      iVar14 = *(int *)(this_00->_padding_ +
                                       *(short *)(*(int *)((int)&param_1->make_list + 3) + 4 +
                                                 iVar15) * 4);
                      if ((char)uStack_42c == '\0') {
LAB_0049a110:
                        (**(code **)(rge_base_game->_padding_ + 0x20))
                                  ((int)*(short *)(iVar14 + 0xc),acStack_400,0x200);
                        TRIBE_Screen_Game::calc_text_msg
                                  (param_1,acStack_200,
                                   (Item_Avail *)(*(int *)((int)&param_1->make_list + 3) + iVar15),
                                   0x12,(int)*(short *)(iVar14 + 0xe));
                        sVar8 = TRIBE_Screen_Game::calc_button_loc
                                          (param_1,*(uchar *)(iVar14 + 0x15e));
                        iStack_430 = CONCAT22(extraout_var,sVar8);
                        iVar15 = *(int *)((int)&param_1->make_list + 3) + iVar15;
                        TRIBE_Screen_Game::set_button
                                  (param_1,*(TShape **)((int)&param_1->button_unit_pic + 3),sVar8,
                                   *(short *)(iVar15 + 6),0x12,(int)*(short *)(iVar15 + 4),
                                   *(short *)(iVar14 + 0xe) + 100000,*(long *)(iVar15 + 0x24),
                                   *(long *)(iVar14 + 0xa0),(uchar *)(this_00->_padding_ + 0x28),
                                   acStack_400,acStack_200,0);
                        if (((int)pTStack_424 < 1) || ((char)uStack_42c == '\0')) {
                          TRIBE_Panel_Button::set_display_garrison
                                    (*(TRIBE_Panel_Button **)
                                      ((int)param_1->button_panel + (short)iStack_430 * 4 + 3),0);
                        }
                        else {
                          iVar15 = (int)(short)iStack_430;
                          TRIBE_Panel_Button::set_display_garrison
                                    (*(TRIBE_Panel_Button **)
                                      ((int)param_1->button_panel + iVar15 * 4 + 3),1);
                          TRIBE_Panel_Button::set_garrison_number
                                    (*(TRIBE_Panel_Button **)
                                      ((int)param_1->button_panel + iVar15 * 4 + 3),(int)pTStack_424
                                    );
                        }
                      }
                      else {
                        if (0 < pTStack_420->production_queue_count) {
                          pPVar12 = pTStack_420->production_queue;
                          iStack_430 = (int)pTStack_420->production_queue_count;
                          do {
                            if (pPVar12->master_id == *(short *)(iVar14 + 0x10)) {
                              pTVar16 = (TRIBE_Building_Object *)
                                        ((int)&pTVar16->_padding_ + (int)pPVar12->unit_count);
                            }
                            pPVar12 = pPVar12 + 1;
                            iStack_430 = iStack_430 + -1;
                          } while (iStack_430 != 0);
                          iStack_430 = 0;
                          pTStack_424 = pTVar16;
                        }
                        if (((char)uStack_42c == '\0') || (0 < (int)pTStack_424)) goto LAB_0049a110;
                      }
                      iStack_428 = iStack_428 + 1;
                      pTVar16 = pTStack_420;
                    } while ((short)iStack_428 < asStack_410[0]);
                  }
                  pTStack_424 = (TRIBE_Building_Object *)0x0;
                  if ((char)uStack_42c != '\0') goto LAB_0049a88c;
                  if ((*(short *)(pTVar16->_padding_ + 0x10) == 0x6d) && ((short)uStack_41c == 0)) {
                    RGE_Base_Game::get_player(rge_base_game);
                    iVar15 = __ftol();
                    if (iVar15 < 4) {
                      RGE_Base_Game::get_player(rge_base_game);
                      sVar8 = __ftol();
                      sVar8 = sVar8 + 100;
                      sVar9 = TRIBE_Player_Tech::get_tech_state(this_00->tech_tree,sVar8);
                      if (sVar9 != -1) {
                        if (*ppIVar1 != (Item_Avail *)0x0) {
                          free(*ppIVar1);
                        }
                        pIVar13 = (Item_Avail *)calloc(1,0x28);
                        *ppIVar1 = pIVar13;
                        if (pIVar13 != (Item_Avail *)0x0) {
                          uStack_41c = 1;
                          TRIBE_Player_Tech::tech_cost
                                    (this_00->tech_tree,sVar8,(short *)&uStack_42c,
                                     (short *)&uStack_414,(short *)&pTStack_420,
                                     (short *)&pTStack_424,(short *)&iStack_430,(short *)&iStack_428
                                    );
                          (*ppIVar1)->id = sVar8;
                          (*ppIVar1)->name =
                               *(char **)(**(int **)(*(int *)((int)&param_1->world + 3) + 0x104) +
                                         sVar8 * 0x3c);
                          (*ppIVar1)->pict =
                               *(short *)(**(int **)(*(int *)((int)&param_1->world + 3) + 0x104) +
                                          0x24 + sVar8 * 0x3c);
                          (*ppIVar1)->inventory_item_1 = (short)uStack_42c;
                          (*ppIVar1)->inventory_cost_1 = (float)(int)(short)uStack_414;
                          (*ppIVar1)->inventory_item_2 = (short)pTStack_420;
                          (*ppIVar1)->inventory_cost_2 = (float)(int)(short)pTStack_424;
                          (*ppIVar1)->inventory_item_3 = (short)iStack_430;
                          iStack_418 = (int)(short)iStack_428;
                          (*ppIVar1)->inventory_cost_3 = (float)iStack_418;
                          lVar20 = TRIBE_Player_Tech::get_help_message(this_00->tech_tree,sVar8);
                          (*ppIVar1)->help_string_id = lVar20;
                          lVar20 = TRIBE_Player_Tech::get_help_page(this_00->tech_tree,sVar8);
                          (*ppIVar1)->help_page_id = lVar20;
                          pTStack_424 = (TRIBE_Building_Object *)0x1;
                        }
                      }
                    }
                  }
                  iStack_428 = 0;
                  if (0 < (short)uStack_41c) {
                    do {
                      pcVar21 = acStack_400;
                      sVar8 = (short)iStack_428;
                      uVar23 = 0x200;
                      iVar15 = rge_base_game->_padding_;
                      sVar9 = TRIBE_Player_Tech::get_string_id
                                        (this_00->tech_tree,(*ppIVar1)[sVar8].id);
                      (**(code **)(iVar15 + 0x20))((int)sVar9,pcVar21,uVar23);
                      sVar9 = TRIBE_Player_Tech::get_string_id2
                                        (this_00->tech_tree,(*ppIVar1)[sVar8].id);
                      TRIBE_Screen_Game::calc_text_msg
                                (param_1,acStack_200,*ppIVar1 + sVar8,0x11,(int)sVar9);
                      uVar7 = TRIBE_Player_Tech::get_button_location
                                        (this_00->tech_tree,(*ppIVar1)[sVar8].id);
                      sVar9 = TRIBE_Screen_Game::calc_button_loc(param_1,uVar7);
                      iStack_430 = CONCAT22(extraout_var_00,sVar9);
                      pIVar13 = *ppIVar1;
                      pcVar22 = acStack_200;
                      pcVar21 = acStack_400;
                      puVar17 = (uchar *)(this_00->_padding_ + 0x28);
                      pTVar16 = pTStack_424;
                      lVar20 = TRIBE_Player_Tech::get_hotkey
                                         (this_00->tech_tree,(*ppIVar1)[sVar8].id);
                      TRIBE_Screen_Game::set_button
                                (param_1,*(TShape **)((int)&param_1->button_tech_pic + 3),
                                 (short)iStack_430,pIVar13[sVar8].pict,0x11,(int)pIVar13[sVar8].id,
                                 pIVar13[sVar8].help_string_id,pIVar13[sVar8].help_page_id,lVar20,
                                 puVar17,pcVar21,pcVar22,(int)pTVar16);
                      iStack_428 = iStack_428 + 1;
                    } while ((short)iStack_428 < (short)uStack_41c);
                  }
                  if ((asStack_410[0] != 0) || ((short)uStack_41c != 0)) goto LAB_0049a581;
                  if ((short)this_00->_padding_ < 2) goto LAB_0049a54d;
                  TRIBE_Screen_Game::set_button
                            (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,7,8,0,0x1d4e1
                             ,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
                  pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
                  lVar20 = 0x4e43;
                  sVar8 = 7;
                  goto LAB_0049a57a;
                }
                TRIBE_Screen_Game::set_button
                          (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,3,5,0,0x1d4dd,
                           -1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              }
              sVar8 = *(short *)&param_1->field_0x4b4;
              pTVar19 = *(TShape **)((int)&param_1->more_cancel_pic + 3);
              lVar20 = 6;
              goto LAB_0049a885;
            }
            if ((uVar7 == '\0') && (1 < (short)this_00->_padding_)) {
              uVar7 = '\0';
              sVar9 = 0;
              uStack_42c = CONCAT31(uStack_42c._1_3_,1);
              sVar8 = 0;
              do {
                if ((short)this_00->_padding_ <= sVar8) break;
                this = (RGE_Action_Object *)(&this_00->_padding_)[sVar9];
                if (this != (RGE_Action_Object *)0x0) {
                  cVar3 = *(char *)(this->_padding_ + 0x8f);
                  if (((((cVar3 != '\x03') && (cVar3 != '\t')) && (cVar3 != '\x04')) &&
                      ((cVar3 != '\x05' && (cVar3 != '\x06')))) &&
                     ((cVar3 != '\a' && (cVar3 != '\b')))) {
                    uStack_42c = uStack_42c & 0xffffff00;
                    break;
                  }
                  if (uVar7 == '\0') {
                    uVar7 = RGE_Action_Object::have_action(this);
                  }
                  sVar8 = sVar8 + 1;
                }
                sVar9 = sVar9 + 1;
              } while (sVar9 < 0x19);
              if ((char)uStack_42c != '\0') {
                iVar15 = RGE_Player::is_group_selected((RGE_Player *)this_00,4);
                if (iVar15 != 0) {
                  TRIBE_Screen_Game::set_button
                            (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,2,3,0,0x1d4df
                             ,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
                }
                uVar18 = (ushort)(iVar15 != 0);
                if (uVar7 != '\0') goto LAB_0049a68a;
                goto LAB_0049a698;
              }
            }
            iVar15 = RGE_Player::is_group_selected((RGE_Player *)this_00,4);
            if (iVar15 != 0) {
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,2,3,0,0x1d4df,-1,
                         0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
            }
            iVar14 = TRIBE_Screen_Game::any_selected_have_action(param_1);
            if (iVar14 != 0) {
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),
                         (ushort)(iVar15 != 0),3,5,0,0x1d4dd,-1,0,(uchar *)0x0,(char *)0x0,
                         (char *)0x0,0);
            }
            if ((short)this_00->_padding_ < 2) {
              if (*(char *)(*(int *)((int)&param_1->game_obj + 3) + 0x37) != '\0') {
                pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
                lVar20 = 0x1d4e3;
                sVar8 = 6;
                goto LAB_0049a836;
              }
            }
            else {
              TRIBE_Screen_Game::set_button
                        (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,7,8,0,0x1d4e1,-1,
                         0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
              pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
              lVar20 = 0x4e43;
              sVar8 = 7;
LAB_0049a836:
              TRIBE_Screen_Game::set_button
                        (param_1,pTVar19,sVar8,8,9,0,lVar20,-1,0,(uchar *)0x0,(char *)0x0,
                         (char *)0x0,0);
            }
            sVar8 = *(short *)&param_1->field_0x4b4;
            pTVar19 = *(TShape **)((int)&param_1->more_cancel_pic + 3);
            lVar20 = 0xb;
            goto LAB_0049a885;
          }
          sVar8 = 0;
          bVar4 = true;
          sVar9 = 0;
          do {
            if (*(short *)&param_1->field_0x5cc <= sVar9) break;
            if ((&this_00->_padding_)[sVar8] != 0) {
              iVar15 = *(int *)((&this_00->_padding_)[sVar8] + 8);
              if ((*(short *)(iVar15 + 0x124) == -1) ||
                 (*(float *)(iVar15 + 0x118) == _DAT_00572ce4)) {
                bVar4 = false;
                break;
              }
              sVar9 = sVar9 + 1;
            }
            sVar8 = sVar8 + 1;
          } while (sVar8 < 0x19);
          TRIBE_Screen_Game::set_button
                    (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,4,0x16,0,0x1d4ea,-1,0
                     ,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
          sVar8 = 1;
          if (bVar4) {
            TRIBE_Screen_Game::set_button
                      (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),1,0xc,0x17,0,0x1d4eb,
                       -1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
            sVar8 = 2;
          }
          iVar15 = TRIBE_Screen_Game::any_selected_have_action(param_1);
          if (iVar15 != 0) {
            TRIBE_Screen_Game::set_button
                      (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),sVar8,3,5,0,0x1d4dd,
                       -1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
          }
          if ((short)this_00->_padding_ < 2) {
LAB_0049a54d:
            if (*(char *)(*(int *)((int)&param_1->game_obj + 3) + 0x37) != '\0') {
              pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
              lVar20 = 0x1d4e3;
              sVar8 = 6;
              goto LAB_0049a57a;
            }
          }
          else {
            TRIBE_Screen_Game::set_button
                      (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,7,8,0,0x1d4e1,-1,0,
                       (uchar *)0x0,(char *)0x0,(char *)0x0,0);
            pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
            lVar20 = 0x1d4e3;
            sVar8 = 7;
LAB_0049a57a:
            TRIBE_Screen_Game::set_button
                      (param_1,pTVar19,sVar8,8,9,0,lVar20,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,
                       0);
          }
LAB_0049a581:
          sVar8 = *(short *)&param_1->field_0x4b4;
          lVar20 = 6;
          goto LAB_0049a87b;
        }
        iVar15 = TRIBE_Screen_Game::any_selected_have_action(param_1);
        if (iVar15 != 0) {
          TRIBE_Screen_Game::set_button
                    (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,3,5,0,0x1d4dd,-1,0,
                     (uchar *)0x0,(char *)0x0,(char *)0x0,0);
        }
        if ((short)this_00->_padding_ < 2) {
          cVar3 = *(char *)(*(int *)((int)&param_1->game_obj + 3) + 0x37);
joined_r0x00499e92:
          if (cVar3 != '\0') {
            pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
            lVar20 = 0x1d4e3;
            sVar8 = 6;
            goto LAB_00499eae;
          }
        }
        else {
          TRIBE_Screen_Game::set_button
                    (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,7,8,0,0x1d4e1,-1,0,
                     (uchar *)0x0,(char *)0x0,(char *)0x0,0);
          pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
          lVar20 = 0x1d4e3;
          sVar8 = 7;
LAB_00499eae:
          TRIBE_Screen_Game::set_button
                    (param_1,pTVar19,sVar8,8,9,0,lVar20,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0)
          ;
        }
        sVar8 = *(short *)&param_1->field_0x4b4;
        lVar20 = 6;
        goto LAB_0049a87b;
      }
      TRIBE_Screen_Game::set_button
                (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),0,2,3,0,0x1d4df,-1,0,
                 (uchar *)0x0,(char *)0x0,(char *)0x0,0);
      TRIBE_Screen_Game::set_button
                (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),1,0,0x1f,0,0x1d4f6,-1,0,
                 (uchar *)0x0,(char *)0x0,(char *)0x0,0);
      iVar15 = TRIBE_Screen_Game::any_selected_have_action(param_1);
      if (iVar15 != 0) {
        TRIBE_Screen_Game::set_button
                  (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),2,3,5,0,0x1d4dd,-1,0,
                   (uchar *)0x0,(char *)0x0,(char *)0x0,0);
      }
      if ((short)this_00->_padding_ < 2) {
        if (*(char *)(*(int *)((int)&param_1->game_obj + 3) + 0x37) == '\0') goto LAB_0049a732;
        pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
        lVar20 = 0x1d4e3;
        sVar8 = 6;
      }
      else {
        TRIBE_Screen_Game::set_button
                  (param_1,*(TShape **)((int)&param_1->button_cmd_pic + 3),6,7,8,0,0x1d4e1,-1,0,
                   (uchar *)0x0,(char *)0x0,(char *)0x0,0);
        pTVar19 = *(TShape **)((int)&param_1->button_cmd_pic + 3);
        lVar20 = 0x4e43;
        sVar8 = 7;
      }
      TRIBE_Screen_Game::set_button
                (param_1,pTVar19,sVar8,8,9,0,lVar20,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0);
    }
LAB_0049a732:
    sVar8 = *(short *)&param_1->field_0x4b4;
    pTVar19 = *(TShape **)((int)&param_1->more_cancel_pic + 3);
    lVar20 = 6;
  }
  else {
    sVar8 = *(short *)((int)&param_1->unselect_frame + 1);
    lVar20 = 0xb;
LAB_0049a87b:
    pTVar19 = *(TShape **)((int)&param_1->more_cancel_pic + 3);
  }
LAB_0049a885:
  TRIBE_Screen_Game::set_button
            (param_1,pTVar19,0xb,sVar8,lVar20,0,0x1d4d9,-1,0,(uchar *)0x0,(char *)0x0,(char *)0x0,0)
  ;
LAB_0049a88c:
  TRIBE_Screen_Game::disable_unused_buttons(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0049a89e
// Address: 0049a89e
// XREFS: None
void __fastcall FUN_0049a89e(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(param_1 + 0x4c8);
  iVar3 = 0xc;
  do {
    piVar1 = (int *)*piVar2;
    if (piVar1[0xf4] == 0) {
      (**(code **)(*piVar1 + 0x14))(0);
      TButtonPanel::set_id((TButtonPanel *)*piVar2,0,0,-1);
      TPanel::set_help_info((TPanel *)*piVar2,-1,-1);
    }
    else {
      (**(code **)(*piVar1 + 0x14))(1);
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0049a8ea
// Address: 0049a8ea
// XREFS: None
// [HELPER] s____s___d: "  %s: %d"
// [HELPER] s___s_s_s_: "(%s%s%s)"
// [HELPER] s__s: "%s"
// [HELPER] s__s___d: "%s: %d"
// [HELPER] s__s__s: "%s\n%s"
undefined1 * FUN_0049a8ea(void)
{
  short sVar1;
  undefined4 uVar2;
  undefined4 in_stack_00000010;
  char acStack_a0c [512];
  char acStack_80c [512];
  char acStack_60c [512];
  char acStack_40c [512];
  char acStack_20c [12];
  undefined1 auStack_200 [504];
  undefined1 *puStack_8;
  int iStack_4;
  
  (**(code **)(rge_base_game->_padding_ + 0x20))(in_stack_00000010,auStack_200,0x200);
  acStack_60c[0] = '\0';
  if (iStack_4 != 0) {
    sVar1 = *(short *)(iStack_4 + 8);
    if ((sVar1 == -1) || (3 < sVar1)) {
      acStack_80c[0] = '\0';
    }
    else {
      (**(code **)(rge_base_game->_padding_ + 0x28))(100,(int)sVar1,0,&stack0xfffff3f4,0x200);
      uVar2 = __ftol();
      sprintf(acStack_80c,s__s___d,&stack0xfffff3f4,uVar2);
    }
    sVar1 = *(short *)(iStack_4 + 0x10);
    if ((sVar1 == -1) || (3 < sVar1)) {
      acStack_a0c[0] = '\0';
    }
    else {
      (**(code **)(rge_base_game->_padding_ + 0x28))(100,(int)sVar1,0,&stack0xfffff3f4,0x200);
      uVar2 = __ftol();
      sprintf(acStack_a0c,s____s___d,&stack0xfffff3f4,uVar2);
    }
    sVar1 = *(short *)(iStack_4 + 0x18);
    if ((sVar1 == -1) || (3 < sVar1)) {
      acStack_40c[0] = '\0';
    }
    else {
      (**(code **)(rge_base_game->_padding_ + 0x28))(100,(int)sVar1,0,&stack0xfffff3f4,0x200);
      uVar2 = __ftol();
      sprintf(acStack_40c,s____s___d,&stack0xfffff3f4,uVar2);
    }
    if (((acStack_80c[0] != '\0') || (acStack_a0c[0] != '\0')) || (acStack_40c[0] != '\0')) {
      sprintf(acStack_60c,s___s_s_s_,acStack_80c,acStack_a0c,acStack_40c);
    }
  }
  if (acStack_20c[0] != '\0') {
    if (acStack_60c[0] != '\0') {
      sprintf(puStack_8,s__s__s,acStack_20c,acStack_60c);
      return puStack_8;
    }
    if (acStack_20c[0] != '\0') {
      sprintf(puStack_8,s__s,acStack_20c);
      return puStack_8;
    }
  }
  *puStack_8 = 0;
  return puStack_8;
}

// --------------------------------------------------

// Function: FUN_0049ab0e
// Address: 0049ab0e
// XREFS: None
uint FUN_0049ab0e(byte param_1)
{
  if ((param_1 != 0) && (param_1 < 6)) {
    return param_1 - 1;
  }
  if ((5 < param_1) && (param_1 < 0xb)) {
    return (uint)param_1;
  }
  if ((10 < param_1) && (param_1 < 0x10)) {
    return param_1 - 0xb;
  }
  if ((0xf < param_1) && (param_1 < 0x15)) {
    return param_1 - 10;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0049ad3b
// Address: 0049ad3b
// XREFS: None
void __fastcall FUN_0049ad3b(int param_1,int param_2)
{
  uint *puVar1;
  TRIBE_Panel_Time *pTVar2;
  char cVar3;
  bool bVar4;
  uchar uVar5;
  undefined4 in_EAX;
  char *pcVar6;
  byte *pbVar7;
  int iVar8;
  int *piVar9;
  char cVar12;
  undefined4 unaff_EBX;
  int iVar11;
  int unaff_EBP;
  int iVar13;
  int unaff_ESI;
  undefined4 *puVar14;
  int iVar15;
  int iStack_50;
  undefined4 *puStack_4c;
  int aiStack_44 [17];
  char cVar10;
  
  puVar1 = (uint *)(param_1 * 3 + 0x49acd800);
  *puVar1 = *puVar1 >> 1;
  *(char *)(param_2 + -0x66ffb654) = *(char *)(param_2 + -0x66ffb654) + (char)param_2;
  cVar3 = (char)((uint)in_EAX >> 8);
  param_1 = param_1 + -1;
  iVar13 = CONCAT22((short)((uint)param_1 >> 0x10),
                    CONCAT11((char)((uint)param_1 >> 8) * '\x02',(char)param_1));
  pcVar6 = (char *)(CONCAT31((int3)((uint)in_EAX >> 8),*(undefined1 *)(unaff_ESI + 1)) + -0x58ffb654
                   );
  *pcVar6 = *pcVar6 + cVar3;
  *(char *)(unaff_ESI + -0x4affb651) =
       *(char *)(unaff_ESI + -0x4affb651) + (char)((uint)(iVar13 + -2) >> 8);
  cVar12 = (char)((uint)unaff_EBX >> 8);
  (&stack0xacc30049)[unaff_EBP * 4] = (&stack0xacc30049)[unaff_EBP * 4] + cVar12;
  cVar10 = (char)((uint)param_2 >> 8) + cVar3;
  piVar9 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),
                           CONCAT11(cVar10,(char)param_2 + (char)param_1 + -4));
  pcVar6 = (char *)CONCAT31(CONCAT21((short)((uint)in_EAX >> 0x10),cVar3 + cVar10),
                            *(char *)(unaff_ESI + 7));
  *pcVar6 = *pcVar6 + *(char *)(unaff_ESI + 7);
  *piVar9 = (int)(pcVar6 + *piVar9);
  pbVar7 = (byte *)(iVar13 + -8 + *(int *)(unaff_ESI + 8));
  *pbVar7 = *pbVar7 | (byte)pbVar7;
  iVar8 = CONCAT31((int3)((uint)pbVar7 >> 8),
                   (byte)pbVar7 |
                   *(byte *)CONCAT22((short)((uint)unaff_EBX >> 0x10),
                                     CONCAT11(cVar12 + (char)unaff_EBX,(char)unaff_EBX)));
  iVar13 = *(int *)(*(int *)(iVar8 + 0x5b4) + 0x108);
  if (iVar13 == 2) {
    TRIBE_Panel_Time::set_clock_type(*(TRIBE_Panel_Time **)(iVar8 + 0x518),3,0);
    return;
  }
  if (iVar13 == 0) {
    iVar15 = 1;
    iVar13 = 0;
    if (1 < *(short *)(*(int *)(iVar8 + 0x5b4) + 0x3c)) {
      puStack_4c = (undefined4 *)(iVar8 + 0x518);
      iStack_50 = 4;
      do {
        RGE_Base_Game::get_countdown_timer(rge_base_game,iVar15,aiStack_44);
        if (0 < aiStack_44[0]) {
          iVar13 = iVar13 + 1;
          pTVar2 = (TRIBE_Panel_Time *)*puStack_4c;
          puStack_4c = puStack_4c + 1;
          TRIBE_Panel_Time::set_clock_type(pTVar2,4,iVar15);
          if (9 < iVar13) break;
        }
        iVar11 = *(int *)(*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iStack_50);
        if (*(int *)(iVar11 + 0x844) != -0x40800000) {
          bVar4 = false;
          if ((*(char *)(iVar11 + 0x104) != '\0') && (iVar11 = 1, 4 < iStack_50)) {
            do {
              uVar5 = RGE_Player::relation
                                (*(RGE_Player **)
                                  (*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iStack_50),iVar11);
              if ((uVar5 == '\0') &&
                 ((uVar5 = RGE_Player::relation
                                     (*(RGE_Player **)
                                       (*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iVar11 * 4),
                                      iVar15), uVar5 == '\0' &&
                  (*(char *)(*(int *)(*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iVar11 * 4) + 0x104
                            ) != '\0')))) {
                bVar4 = true;
                break;
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 < iVar15);
          }
          if (!bVar4) {
            iVar13 = iVar13 + 1;
            pTVar2 = (TRIBE_Panel_Time *)*puStack_4c;
            puStack_4c = puStack_4c + 1;
            TRIBE_Panel_Time::set_clock_type(pTVar2,5,iVar15);
            if (9 < iVar13) break;
          }
        }
        iVar11 = *(int *)(*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iStack_50);
        if (*(int *)(iVar11 + 0x840) != -0x40800000) {
          bVar4 = false;
          if ((*(char *)(iVar11 + 0x104) != '\0') && (iVar11 = 1, 4 < iStack_50)) {
            do {
              uVar5 = RGE_Player::relation
                                (*(RGE_Player **)
                                  (*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iStack_50),iVar11);
              if ((uVar5 == '\0') &&
                 ((uVar5 = RGE_Player::relation
                                     (*(RGE_Player **)
                                       (*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iVar11 * 4),
                                      iVar15), uVar5 == '\0' &&
                  (*(char *)(*(int *)(*(int *)(*(int *)(iVar8 + 0x5b4) + 0x40) + iVar11 * 4) + 0x104
                            ) != '\0')))) {
                bVar4 = true;
                break;
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 < iVar15);
          }
          if (!bVar4) {
            iVar13 = iVar13 + 1;
            pTVar2 = (TRIBE_Panel_Time *)*puStack_4c;
            puStack_4c = puStack_4c + 1;
            TRIBE_Panel_Time::set_clock_type(pTVar2,6,iVar15);
            if (9 < iVar13) break;
          }
        }
        iStack_50 = iStack_50 + 4;
        iVar15 = iVar15 + 1;
      } while (iVar15 < *(short *)(*(int *)(iVar8 + 0x5b4) + 0x3c));
    }
    if (iVar13 < 10) {
      puVar14 = (undefined4 *)(iVar8 + 0x518 + iVar13 * 4);
      iVar13 = 10 - iVar13;
      do {
        pTVar2 = (TRIBE_Panel_Time *)*puVar14;
        puVar14 = puVar14 + 1;
        TRIBE_Panel_Time::set_clock_type(pTVar2,0,0);
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049aff2
// Address: 0049aff2
// XREFS: None
int FUN_0049aff2(int param_1,int param_2)
{
  UNK_0086bab9._3_4_ = param_2;
  UNK_0086bab9._7_4_ = param_1;
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    return 1;
  }
  if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
    return -1;
  }
  if (*(int *)(param_1 + 8) < *(int *)(param_2 + 8)) {
    return 1;
  }
  if (*(int *)(param_2 + 8) < *(int *)(param_1 + 8)) {
    return -1;
  }
  if (*(int *)(param_1 + 0xc) < *(int *)(param_2 + 0xc)) {
    return 1;
  }
  if (*(int *)(param_2 + 0xc) < *(int *)(param_1 + 0xc)) {
    return -1;
  }
  if (*(int *)(param_1 + 4) < *(int *)(param_2 + 4)) {
    return 1;
  }
  return (*(int *)(param_1 + 4) <= *(int *)(param_2 + 4)) - 1;
}

// --------------------------------------------------

// Function: scr_game_score_compare
// Address: 0049b000
// XREFS: reset_score_display
/* int __cdecl scr_game_score_compare(void const *,void const *) */

int __cdecl scr_game_score_compare(void *param_1,void *param_2)
{
  UNK_0086bab9._3_4_ = param_2;
  UNK_0086bab9._7_4_ = param_1;
  if (*(int *)((int)param_1 + 0x10) < *(int *)((int)param_2 + 0x10)) {
    return 1;
  }
  if (*(int *)((int)param_2 + 0x10) < *(int *)((int)param_1 + 0x10)) {
    return -1;
  }
  if (*(int *)((int)param_1 + 8) < *(int *)((int)param_2 + 8)) {
    return 1;
  }
  if (*(int *)((int)param_2 + 8) < *(int *)((int)param_1 + 8)) {
    return -1;
  }
  if (*(int *)((int)param_1 + 0xc) < *(int *)((int)param_2 + 0xc)) {
    return 1;
  }
  if (*(int *)((int)param_2 + 0xc) < *(int *)((int)param_1 + 0xc)) {
    return -1;
  }
  if (*(int *)((int)param_1 + 4) < *(int *)((int)param_2 + 4)) {
    return 1;
  }
  return (*(int *)((int)param_1 + 4) <= *(int *)((int)param_2 + 4)) - 1;
}

// --------------------------------------------------

// Function: FUN_0049b079
// Address: 0049b079
// XREFS: None
// [HELPER] s__s___d__d: "%s: %d/%d"
/* WARNING: Type propagation algorithm not settling */

void __fastcall FUN_0049b079(int param_1)
{
  int iVar1;
  bool bVar2;
  uchar uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  RGE_Font *pRVar11;
  ulong uVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  TShape *pTVar16;
  int iVar17;
  ulong uVar18;
  ulong uVar19;
  undefined4 uVar20;
  code *pcVar21;
  int iStack_2d4;
  int *piStack_2cc;
  int aiStack_2c8 [3];
  TShape *pTStack_2bc;
  uint uStack_2b8;
  undefined1 auStack_2b4 [4];
  undefined1 auStack_2b0 [176];
  char acStack_200 [512];
  
  puVar4 = (undefined4 *)auStack_2b0;
  iVar13 = 9;
  do {
    puVar4[-1] = 0;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4 = puVar4 + 5;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  aiStack_2c8[0] = 0;
  iVar13 = 1;
  aiStack_2c8[1] = 1;
  iVar5 = RGE_Base_Game::numberPlayers(rge_base_game);
  if (0 < iVar5) {
    iVar5 = 0x14;
    do {
      iVar6 = RGE_Base_Game::playerID(rge_base_game,iVar13);
      if ((iVar6 != 0) && (iVar8 = *(int *)(param_1 + 0x5b4), iVar6 < *(short *)(iVar8 + 0x3c))) {
        if (*(int *)((int)aiStack_2c8 + iVar5 + 8) == 0) {
          aiStack_2c8[0] = aiStack_2c8[0] + 1;
          *(int *)((int)aiStack_2c8 + iVar5 + 8) = aiStack_2c8[0];
        }
        *(int *)((int)aiStack_2c8 + iVar5) = iVar13;
        *(int *)((int)aiStack_2c8 + iVar5 + 4) = iVar6;
        lVar7 = RGE_Victory_Conditions::get_victory_points
                          (*(RGE_Victory_Conditions **)
                            (*(int *)(*(int *)(iVar8 + 0x40) + iVar6 * 4) + 0x34));
        iVar8 = *(int *)(param_1 + 0x5b4);
        *(long *)((int)&pTStack_2bc + iVar5) = lVar7;
        *(long *)((int)&uStack_2b8 + iVar5) = lVar7;
        iStack_2d4 = 1;
        if (*(char *)(*(int *)(*(int *)(iVar8 + 0x40) + iVar6 * 4) + 0x104) != '\0') {
          iVar17 = 1;
          iVar8 = RGE_Base_Game::numberPlayers(rge_base_game);
          if (0 < iVar8) {
            piStack_2cc = (int *)0x14;
            do {
              if ((((iVar17 != iVar13) &&
                   (iVar8 = RGE_Base_Game::playerID(rge_base_game,iVar17), iVar13 = aiStack_2c8[1],
                   iVar8 != 0)) && (iVar8 < *(short *)(*(int *)(param_1 + 0x5b4) + 0x3c))) &&
                 (uVar3 = RGE_Player::relation
                                    (*(RGE_Player **)
                                      (*(int *)(*(int *)(param_1 + 0x5b4) + 0x40) + iVar6 * 4),iVar8
                                    ), iVar13 = aiStack_2c8[1], uVar3 == '\0')) {
                iVar8 = iVar8 * 4;
                uVar3 = RGE_Player::relation
                                  (*(RGE_Player **)
                                    (*(int *)(*(int *)(param_1 + 0x5b4) + 0x40) + iVar8),iVar6);
                iVar13 = aiStack_2c8[1];
                if ((uVar3 == '\0') &&
                   (iVar1 = *(int *)(param_1 + 0x5b4),
                   *(char *)(*(int *)(*(int *)(iVar1 + 0x40) + iVar8) + 0x104) != '\0')) {
                  if (*(int *)((int)aiStack_2c8 + (int)piStack_2cc + 8) == 0) {
                    *(undefined4 *)((int)aiStack_2c8 + (int)piStack_2cc + 8) =
                         *(undefined4 *)((int)aiStack_2c8 + iVar5 + 8);
                  }
                  lVar7 = RGE_Victory_Conditions::get_victory_points
                                    (*(RGE_Victory_Conditions **)
                                      (*(int *)(*(int *)(iVar1 + 0x40) + iVar8) + 0x34));
                  iStack_2d4 = iStack_2d4 + 1;
                  *(int *)((int)&uStack_2b8 + iVar5) = *(int *)((int)&uStack_2b8 + iVar5) + lVar7;
                  iVar13 = aiStack_2c8[1];
                }
              }
              piStack_2cc = (int *)((int)piStack_2cc + 0x14);
              iVar17 = iVar17 + 1;
              iVar8 = RGE_Base_Game::numberPlayers(rge_base_game);
            } while (iVar17 <= iVar8);
          }
        }
        *(int *)((int)&uStack_2b8 + iVar5) = *(int *)((int)&uStack_2b8 + iVar5) / iStack_2d4;
      }
      iVar13 = iVar13 + 1;
      iVar5 = iVar5 + 0x14;
      aiStack_2c8[1] = iVar13;
      iVar6 = RGE_Base_Game::numberPlayers(rge_base_game);
    } while (iVar13 <= iVar6);
  }
  pcVar21 = scr_game_score_compare;
  uVar20 = 0x14;
  iVar13 = RGE_Base_Game::numberPlayers(rge_base_game);
  qsort(auStack_2b4,iVar13,uVar20,pcVar21);
  uStack_2b8 = 0;
  iVar13 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar13 != 0) {
    uVar14 = 0xb;
    puVar15 = (uint *)auStack_2b4;
    iVar13 = 8;
    do {
      if ((puVar15[1] != 0) &&
         (iVar5 = TCommunications_Handler::GetPlayerHumanity(comm,*puVar15), iVar5 == 2)) {
        uVar9 = comm->Speed->PlayerAvgFramesMsec[*puVar15];
        if (uVar9 < 1000) {
          if (uVar9 < 10) {
            uVar9 = 100;
          }
          else {
            uVar9 = (uint)(1000 / (ulonglong)uVar9);
          }
        }
        else {
          uVar9 = 1;
        }
        if (uVar9 < uVar14) {
          uStack_2b8 = *puVar15;
          uVar14 = uVar9;
        }
      }
      puVar15 = puVar15 + 5;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  puVar15 = (uint *)auStack_2b4;
  piStack_2cc = (int *)(param_1 + 0x58c);
  aiStack_2c8[1] = 0;
  do {
    if ((int *)*piStack_2cc == (int *)0x0) {
      return;
    }
    if (puVar15[1] == 0) {
      (**(code **)(*(int *)*piStack_2cc + 0x14))(0);
    }
    else {
      uVar14 = puVar15[4];
      uVar9 = puVar15[3];
      pcVar10 = TCommunications_Handler::GetPlayerName(comm,*puVar15);
      sprintf(acStack_200,s__s___d__d,pcVar10,uVar9,uVar14);
      iVar13 = *(int *)(*(int *)(*(int *)(param_1 + 0x5b4) + 0x40) + puVar15[1] * 4);
      switch(*(undefined2 *)(*(int *)(iVar13 + 0x108) + 0x26)) {
      case 0:
        uVar18 = 0xff0000;
        uVar19 = 0xb3b3b3;
        goto LAB_0049b3ea;
      case 1:
        uVar18 = 0x2139c6;
        break;
      case 2:
        uVar18 = 0xffff;
        break;
      case 3:
        uVar18 = 0x4f73a3;
        break;
      case 4:
        uVar18 = 0xf77f3;
        break;
      case 5:
        uVar18 = 0xc700;
        break;
      case 6:
        uVar18 = 0x7b90a2;
        break;
      case 7:
        uVar18 = 0xadad00;
        break;
      default:
        uVar18 = 0xffffff;
      }
      uVar19 = 0;
LAB_0049b3ea:
      bVar2 = false;
      if ((*(char *)(iVar13 + 0x80) == '\x02') ||
         (((iVar13 = RGE_Base_Game::multiplayerGame(rge_base_game), iVar13 != 0 &&
           (iVar13 = TCommunications_Handler::GetPlayerHumanity(comm,*puVar15), iVar13 != 2)) &&
          (iVar13 != 4)))) {
        bVar2 = true;
      }
      if (bVar2) {
        iVar13 = 8;
      }
      else {
        iVar13 = 0xb;
      }
      pRVar11 = RGE_Base_Game::get_font(rge_base_game,iVar13);
      pTVar16 = (TShape *)0x0;
      pTStack_2bc = (TShape *)0x0;
      aiStack_2c8[0] = 0;
      aiStack_2c8[2] = 0;
      iVar13 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if ((iVar13 != 0) &&
         (iVar13 = TCommunications_Handler::GetPlayerHumanity(comm,*puVar15), iVar13 == 2)) {
        uVar12 = RGE_Communications_Speed::GetPlayerLatency(comm->Speed,*puVar15);
        if (*puVar15 == uStack_2b8) {
          pTStack_2bc = *(TShape **)(param_1 + 0x448);
          aiStack_2c8[2] = 0x11;
        }
        if (299 < uVar12) {
          pTVar16 = *(TShape **)(param_1 + 0x448);
          aiStack_2c8[0] = 0x14;
          if (uVar12 < 0x3e9) {
            aiStack_2c8[0] = 0x13;
          }
        }
      }
      TMessagePanel::show_message2
                ((TMessagePanel *)*piStack_2cc,RightInfoMessage,acStack_200,uVar18,uVar19,
                 pRVar11->font,pRVar11->font_wid,pRVar11->font_hgt,pTVar16,aiStack_2c8[0],
                 pTStack_2bc,aiStack_2c8[2]);
    }
    aiStack_2c8[1] = aiStack_2c8[1] + 1;
    piStack_2cc = piStack_2cc + 1;
    puVar15 = puVar15 + 5;
    if (7 < aiStack_2c8[1]) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0049b536
// Address: 0049b536
// XREFS: None
// [HELPER] do_color_log: " "
// [HELPER] s_scr_game__draw2: "scr_game::draw2"
// [HELPER] s_scr_game__draw3: "scr_game::draw3"
// [HELPER] s_scr_game__draw: "scr_game::draw"
void __fastcall FUN_0049b536(undefined4 param_1,int param_2)
{
  tagRECT *ptVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  undefined4 in_EAX;
  uchar *puVar9;
  undefined4 uVar10;
  int *piVar11;
  undefined4 unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  TDrawArea *pTVar12;
  long lVar13;
  long lVar14;
  
  *(char *)(param_2 + -0x46ffb64d) = *(char *)(param_2 + -0x46ffb64d) + (char)((uint)param_2 >> 8);
  cVar8 = (char)in_EAX * '\x02';
  piVar11 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),
                            CONCAT11((char)((uint)param_1 >> 8) + (char)param_2,(char)param_1));
  pcVar2 = (char *)(CONCAT22((short)((uint)in_EAX >> 0x10),
                             CONCAT11((char)((uint)in_EAX >> 8) + 'I',cVar8)) + -0x6f6f6f70);
  *pcVar2 = *pcVar2 + (char)param_2;
  if (do_color_log != '\0') {
    ptVar1 = (tagRECT *)(piVar11 + 9);
    iVar3 = *piVar11;
    lVar14 = ptVar1->left;
    iVar4 = piVar11[10];
    iVar5 = piVar11[0xb];
    (**(code **)(iVar3 + 0x28))
              (0,CONCAT31(CONCAT21((short)((uint)unaff_EBX >> 0x10),
                                   (char)((uint)unaff_EBX >> 8) + cVar8),0x49));
    if (piVar11[0x130] != 0) {
      puVar9 = TDrawArea::Lock((TDrawArea *)piVar11[8],s_scr_game__draw,1);
      if (puVar9 != (uchar *)0x0) {
        iVar6 = piVar11[0x130];
        iVar7 = *(int *)(iVar6 + 0x98);
        TDrawArea::FillRect((TDrawArea *)piVar11[8],*(long *)(iVar6 + 0x8c),*(long *)(iVar6 + 0x90),
                            *(long *)(iVar6 + 0x94),iVar7,'t');
        TDrawArea::Unlock((TDrawArea *)piVar11[8],s_scr_game__draw);
        if (piVar11[10] < iVar7) {
          piVar11[10] = iVar7;
        }
        TDrawArea::SetClipRect((TDrawArea *)piVar11[8],ptVar1);
      }
    }
    if (piVar11[0x11e] != 0) {
      puVar9 = TDrawArea::Lock((TDrawArea *)piVar11[8],s_scr_game__draw2,1);
      if (puVar9 != (uchar *)0x0) {
        if ((piVar11[5] < 0x400) || (piVar11[6] < 0x300)) {
          if ((piVar11[5] < 800) || (piVar11[6] < 600)) {
            TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                               (uchar *)0x0);
            pTVar12 = (TDrawArea *)piVar11[8];
            lVar13 = 0x162;
          }
          else {
            TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                               (uchar *)0x0);
            pTVar12 = (TDrawArea *)piVar11[8];
            lVar13 = 0x1da;
          }
        }
        else {
          TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                             (uchar *)0x0);
          pTVar12 = (TDrawArea *)piVar11[8];
          lVar13 = 0x282;
        }
        TShape::shape_draw((TShape *)piVar11[0x11e],pTVar12,0,lVar13,1,'\0',(uchar *)0x0);
        TDrawArea::Unlock((TDrawArea *)piVar11[8],s_scr_game__draw2);
      }
    }
    (**(code **)(iVar3 + 0x2c))();
    ptVar1->left = unaff_ESI + 1;
    piVar11[10] = lVar14;
    piVar11[0xb] = iVar4;
    piVar11[0xc] = iVar5;
    TDrawArea::SetClipRect((TDrawArea *)piVar11[8],ptVar1);
    return;
  }
  if ((piVar11[0xe] == 2) || (piVar11[0x11e] == 0)) {
    uVar10 = 1;
  }
  else {
    uVar10 = 0;
  }
  iVar3 = *piVar11;
  (**(code **)(iVar3 + 0x28))(uVar10,unaff_EDI + 1);
  if (piVar11[0x11e] != 0) {
    puVar9 = TDrawArea::Lock((TDrawArea *)piVar11[8],s_scr_game__draw3,1);
    if (puVar9 != (uchar *)0x0) {
      if ((piVar11[5] < 0x400) || (piVar11[6] < 0x300)) {
        if ((piVar11[5] < 800) || (piVar11[6] < 600)) {
          TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                             (uchar *)0x0);
          pTVar12 = (TDrawArea *)piVar11[8];
          lVar14 = 0x162;
        }
        else {
          TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',
                             (uchar *)0x0);
          pTVar12 = (TDrawArea *)piVar11[8];
          lVar14 = 0x1da;
        }
      }
      else {
        TShape::shape_draw((TShape *)piVar11[0x11e],(TDrawArea *)piVar11[8],0,0,0,'\0',(uchar *)0x0)
        ;
        pTVar12 = (TDrawArea *)piVar11[8];
        lVar14 = 0x282;
      }
      TShape::shape_draw((TShape *)piVar11[0x11e],pTVar12,0,lVar14,1,'\0',(uchar *)0x0);
      TDrawArea::Unlock((TDrawArea *)piVar11[8],s_scr_game__draw3);
    }
  }
  (**(code **)(iVar3 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0049b823
// Address: 0049b823
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_game_c: "C:\msdev\work\age1_x1\scr_game.cpp"
void __fastcall FUN_0049b823(int param_1)
{
  ulong uVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_24;
  tagPALETTEENTRY atStack_1c [7];
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x11eb);
  if (*(uint *)(param_1 + 0x690) <= uVar1 - *(int *)(param_1 + 0x694)) {
    iVar4 = *(int *)(param_1 + 0x698);
    puVar2 = &atStack_1c[0].peGreen;
    iStack_24 = 7;
    do {
      iVar3 = (int)(short)iVar4;
      iVar5 = param_1 + iVar3 * 2 + iVar3;
      iVar4 = iVar4 + 1;
      ((tagPALETTEENTRY *)(puVar2 + -1))->peRed = *(uchar *)(iVar5 + 0x69e);
      *puVar2 = *(uchar *)(iVar3 + 0x235 + param_1 + (iVar3 + 0x235) * 2);
      puVar2[1] = *(uchar *)(iVar5 + 0x6a0);
      puVar2[2] = '\0';
      if ((short)iVar4 == 7) {
        iVar4 = 0;
      }
      puVar2 = puVar2 + 4;
      iStack_24 = iStack_24 + -1;
    } while (iStack_24 != 0);
    if (*(short *)(param_1 + 0x698) == 0) {
      *(undefined2 *)(param_1 + 0x698) = 6;
    }
    else {
      *(short *)(param_1 + 0x698) = *(short *)(param_1 + 0x698) + -1;
    }
    TDrawSystem::ModifyPalette((TDrawSystem *)**(undefined4 **)(param_1 + 0x20),0xf8,7,atStack_1c);
    *(ulong *)(param_1 + 0x694) = uVar1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049b904
// Address: 0049b904
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_game_c: "C:\msdev\work\age1_x1\scr_game.cpp"
void __fastcall FUN_0049b904(int param_1)
{
  int iVar1;
  short sVar2;
  ulong uVar3;
  char *pcVar4;
  byte *pbVar5;
  short sVar6;
  byte bVar7;
  
  color_log('T','\x16',4);
  bVar7 = 0;
  if (((rge_base_game->prog_info->use_sound != 0) &&
      (rge_base_game->sound_system != (TSound_Driver *)0x0)) && (disable_terrain_sounds == 0)) {
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x121d);
    if (*(int *)(param_1 + 0x684) != 0) {
      if (uVar3 - *(int *)(param_1 + 0x67c) < 1000) {
        return;
      }
      *(ulong *)(param_1 + 0x67c) = uVar3;
      if (_bPlaying != 0) {
        if (uVar3 - *(int *)(param_1 + 0x688) < 6000) goto LAB_0049bad0;
        TSound_Driver::stop_stream(rge_base_game->sound_system);
      }
      *(undefined4 *)(param_1 + 0x684) = 0;
      color_log('T','_',4);
      return;
    }
    if (uVar3 - *(int *)(param_1 + 0x67c) < *(uint *)(param_1 + 0x678)) {
      return;
    }
    *(ulong *)(param_1 + 0x67c) = uVar3;
    sVar6 = -1;
    sVar2 = 0;
    iVar1 = *(int *)(*(int *)(param_1 + 0x5b4) + 0x28);
    if (0 < *(short *)(iVar1 + 0x8d90)) {
      pbVar5 = (byte *)(iVar1 + 0xd1);
      do {
        if (((pbVar5[-0x45] != 0) && (bVar7 < *pbVar5)) && (*(int *)(pbVar5 + -0x21) != 0)) {
          sVar6 = sVar2;
          bVar7 = *pbVar5;
        }
        sVar2 = sVar2 + 1;
        pbVar5 = pbVar5 + 0x198;
      } while (sVar2 < *(short *)(iVar1 + 0x8d90));
    }
    if ((sVar6 != -1) &&
       (pcVar4 = RGE_Sound::get_file_name(*(RGE_Sound **)(iVar1 + 0xb0 + sVar6 * 0x198)),
       pcVar4 != (char *)0x0)) {
      color_log('T','L',4);
      debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x125b);
      TSound_Driver::stop_stream(rge_base_game->sound_system);
      TSound_Driver::stream_file(rge_base_game->sound_system,pcVar4,0,0);
      color_log('T','2',4);
      *(undefined4 *)(param_1 + 0x684) = 1;
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x1262);
      *(ulong *)(param_1 + 0x688) = uVar3;
    }
  }
LAB_0049bad0:
  color_log('T','_',4);
  return;
}

// --------------------------------------------------

// Function: FUN_0049bae4
// Address: 0049bae4
// XREFS: None
void __fastcall FUN_0049bae4(int param_1)
{
  void *pvVar1;
  TButtonPanel *this;
  void *pvVar2;
  int iVar3;
  TPanel *pTVar4;
  long lVar5;
  short sVar6;
  short sVar7;
  short sStack_10;
  short sStack_e;
  RGE_Tile *pRStack_c;
  tagPOINT tStack_8;
  
  pvVar1 = rge_base_game->prog_window;
  pvVar2 = (void *)GetForegroundWindow();
  if ((((pvVar2 == pvVar1) && (iVar3 = TPanel::get_focus(*(TPanel **)(param_1 + 0x4b8)), iVar3 != 0)
       ) && (pTVar4 = TPanelSystem::modalPanel(&panel_system), pTVar4 == (TPanel *)0x0)) &&
     ((RGE_Base_Game::get_mouse_pos(rge_base_game,&tStack_8),
      tStack_8.x != *(int *)(param_1 + 0x708) || (tStack_8.y != *(int *)(param_1 + 0x70c))))) {
    *(long *)(param_1 + 0x708) = tStack_8.x;
    *(long *)(param_1 + 0x70c) = tStack_8.y;
    if (*(int *)(*(int *)(param_1 + 0x4b8) + 0x33c) == 0) {
      TMessagePanel::remove_message(*(TMessagePanel **)(param_1 + 0x50c));
    }
    if (((-1 < tStack_8.x) && (tStack_8.x < *(int *)(param_1 + 0x14))) &&
       ((-1 < tStack_8.y &&
        ((tStack_8.y <= *(int *)(param_1 + 0x18) &&
         (iVar3 = RGE_Diamond_Map::pick_tile
                            (*(RGE_Diamond_Map **)(param_1 + 0x4bc),tStack_8.x,tStack_8.y,&sStack_e,
                             &sStack_10,&pRStack_c), iVar3 == 0)))))) {
      sVar6 = 0;
      do {
        this = *(TButtonPanel **)(param_1 + 0x4c8 + sVar6 * 4);
        if (((this->_padding_ != 0) && (lVar5 = TButtonPanel::get_id(this), lVar5 != -1)) &&
           (iVar3 = (**(code **)(**(int **)(param_1 + 0x4c8 + sVar6 * 4) + 0xe4))
                              (tStack_8.x,tStack_8.y), sVar7 = sVar6, iVar3 != 0)) break;
        sVar6 = sVar6 + 1;
        sVar7 = -1;
      } while (sVar6 < 0x11);
      if (sVar7 != -1) {
        TMessagePanel::show_message
                  (*(TMessagePanel **)(param_1 + 0x50c),InfoMessage,
                   (char *)(*(int *)(param_1 + 0x4c8 + sVar7 * 4) + 0x2d0),0xff,'\0',(void *)0x0,0,0
                  );
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049bc56
// Address: 0049bc56
// XREFS: None
void FUN_0049bc56(undefined4 param_1)
{
  int iVar1;
  RGE_Player *pRVar2;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    iVar1 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    if (iVar1 != 0) {
      pRVar2 = RGE_Base_Game::get_player(rge_base_game);
      (**(code **)(pRVar2->_padding_ + 0xb4))(param_1,0x447a0000);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049bd1e
// Address: 0049bd1e
// XREFS: None
void __fastcall FUN_0049bd1e(TPanel *param_1)
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
    pcVar2 = TPanel::get_string(param_1,0xbe2);
    TMessagePanel::show_message
              ((TMessagePanel *)param_1[5].handle_mouse_input,BadMessage,pcVar2,uVar3,(uchar)pvVar1,
               pvVar4,(long)pvVar5,(long)pvVar6);
    (**(code **)(rge_base_game->_padding_ + 0x10))(0x67,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049bd63
// Address: 0049bd63
// XREFS: None
void __fastcall FUN_0049bd63(TRIBE_Screen_Game *param_1)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    (**(code **)(rge_base_game->_padding_ + 0x10))(6,1);
    *(undefined2 *)((int)&param_1->last_item + 1) = 0;
    TRIBE_Screen_Game::setup_buttons(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049bda3
// Address: 0049bda3
// XREFS: None
void __thiscall FUN_0049bda3(int param_1,int param_2)
{
  uchar uVar1;
  int iVar2;
  TRIBE_Player *this;
  RGE_Player *pRVar3;
  int iVar4;
  short *psVar5;
  float fVar6;
  short asStack_202 [257];
  
  iVar2 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar2 == 0) {
    psVar5 = asStack_202;
    fVar6 = 1.0;
    iVar4 = param_2;
    this = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    uVar1 = TRIBE_Player::check_obj_cost(this,(short)iVar4,psVar5,fVar6,iVar2);
    if (uVar1 != '\0') {
      rge_base_game->master_obj_id = (short)param_2;
      pRVar3 = RGE_Base_Game::get_player(rge_base_game);
      if (*(char *)&pRVar3->master_objects[param_2][1].outline_radius_z != '\0') {
        (**(code **)(rge_base_game->_padding_ + 0x10))();
        return;
      }
      (**(code **)(rge_base_game->_padding_ + 0x10))();
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

// Function: FUN_0049be91
// Address: 0049be91
// XREFS: None
void __fastcall FUN_0049be91(TRIBE_Screen_Game *param_1)
{
  int iVar1;
  
  if (param_1->field_0x45c != '\0') {
    TEasy_Panel::clear_popup_help((TEasy_Panel *)param_1);
    return;
  }
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    if (rge_base_game->game_mode != 0) {
      if (rge_base_game->game_mode == 0x15) {
        (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0xf0))();
        RGE_View::set_selection_area(*(RGE_View **)((int)&param_1->main_view + 3),-1,-1,-1,-1);
      }
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
      return;
    }
    TRIBE_Screen_Game::command_unselect(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049bf13
// Address: 0049bf13
// XREFS: None
void FUN_0049bf13(void)
{
  int iVar1;
  TRIBE_Player *this;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    this = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    TRIBE_Player::command_building_cancel(this);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049bf42
// Address: 0049bf42
// XREFS: None
void __fastcall FUN_0049bf42(TRIBE_Screen_Game *param_1)
{
  int iVar1;
  char *pcVar2;
  TribeSendMessageDialog *this;
  undefined4 *unaff_FS_OFFSET;
  uchar uVar3;
  uchar uVar4;
  void *pvVar5;
  long lVar6;
  long lVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ee6b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar1 != 0) {
    TRIBE_Screen_Game::command_quick_chat(param_1);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  if ((*(int *)&param_1->field_0x7b4 == 0) && (rge_base_game->prog_mode == 5)) {
    lVar7 = 0;
    lVar6 = 0;
    pvVar5 = (void *)0x0;
    uVar4 = '\0';
    uVar3 = '2';
    pcVar2 = TPanel::get_string((TPanel *)param_1,0xbfe);
    TMessagePanel::show_message
              (*(TMessagePanel **)((int)&param_1->message_panel + 3),BadMessage,pcVar2,uVar3,uVar4,
               pvVar5,lVar6,lVar7);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  this = (TribeSendMessageDialog *)operator_new(0x54c);
  uStack_4 = 0;
  if (this != (TribeSendMessageDialog *)0x0) {
    TribeSendMessageDialog::TribeSendMessageDialog(this,(TScreenPanel *)param_1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049c0ac
// Address: 0049c0ac
// XREFS: None
void __fastcall FUN_0049c0ac(int param_1)
{
  rge_base_game->do_show_timings = 0;
  (**(code **)(**(int **)(param_1 + 0x588) + 0x14))(0);
  (**(code **)(**(int **)(param_1 + 0x4c0) + 0x14))(1);
  TMessagePanel::remove_message(*(TMessagePanel **)(param_1 + 0x544));
  TMessagePanel::remove_message(*(TMessagePanel **)(param_1 + 0x548));
  TMessagePanel::remove_message(*(TMessagePanel **)(param_1 + 0x54c));
  TMessagePanel::remove_message(*(TMessagePanel **)(param_1 + 0x550));
  TMessagePanel::remove_message(*(TMessagePanel **)(param_1 + 0x554));
  TMessagePanel::remove_message(*(TMessagePanel **)(param_1 + 0x558));
  if (rge_base_game->do_show_comm != 0) {
    rge_base_game->do_show_comm = 0;
    return;
  }
  rge_base_game->do_show_timings = 0;
  rge_base_game->do_show_ai = 0;
  rge_base_game->do_show_comm = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0049c155
// Address: 0049c155
// XREFS: None
void __fastcall FUN_0049c155(TPanel *param_1)
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
    pcVar2 = TPanel::get_string(param_1,0xbe4);
    TMessagePanel::show_message
              ((TMessagePanel *)param_1[5].handle_mouse_input,BadMessage,pcVar2,uVar3,(uchar)pvVar1,
               pvVar4,(long)pvVar5,(long)pvVar6);
    (**(code **)(rge_base_game->_padding_ + 0x10))(0x65,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c1a3
// Address: 0049c1a3
// XREFS: None
void __fastcall FUN_0049c1a3(TScreenPanel *param_1)
{
  int iVar1;
  TribeDiplomacyDialog *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055eeab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    iVar1 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if (iVar1 == 1) {
      RGE_Base_Game::set_paused(rge_base_game,1,1);
    }
    this = (TribeDiplomacyDialog *)operator_new(0x6b8);
    uStack_4 = 0;
    if (this != (TribeDiplomacyDialog *)0x0) {
      TribeDiplomacyDialog::TribeDiplomacyDialog(this,param_1);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049c22a
// Address: 0049c22a
// XREFS: None
void __fastcall FUN_0049c22a(int param_1)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::allowCheatCodes(rge_base_game);
  if (iVar1 != 0) {
    RGE_Base_Game::set_map_fog
              (rge_base_game,*(char *)(*(int *)(*(int *)(param_1 + 0x5b4) + 0x28) + 0x8db9) == '\0')
    ;
    (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c273
// Address: 0049c273
// XREFS: None
void __fastcall FUN_0049c273(int param_1)
{
  if (rge_base_game->do_show_timings == 0) {
    show_timing_max = 0;
    rge_base_game->do_show_timings = 1;
    (**(code **)(**(int **)(param_1 + 0x588) + 0x14))(1);
    (**(code **)(**(int **)(param_1 + 0x4c0) + 0x14))(0);
    return;
  }
  if (show_timing_max == 0) {
    show_timing_max = 1;
    return;
  }
  rge_base_game->do_show_timings = 0;
  (**(code **)(**(int **)(param_1 + 0x588) + 0x14))(0);
  (**(code **)(**(int **)(param_1 + 0x4c0) + 0x14))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0049c2fe
// Address: 0049c2fe
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_scr_game_c: "C:\msdev\work\age1_x1\scr_game.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0049c2fe(TPanel *param_1,int param_2)
{
  float fVar1;
  char *pcVar2;
  int iVar3;
  float fStack_108;
  char acStack_100 [256];
  
  pcVar2 = (char *)debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c,0x13fe);
  if (((uint)((int)pcVar2 - (int)param_1[8].panelNameValue) < 1000) &&
     (iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar3 == 0)) {
    return;
  }
  param_1[8].panelNameValue = pcVar2;
  if (rge_base_game->prog_mode != 5) {
    fStack_108 = 0.0;
    fVar1 = *(float *)(*(int *)&param_1[5].fill_in_background + 0x18);
    if (param_2 == 0) {
      if (fVar1 == _DAT_00572cf8) {
        fStack_108 = 8.0;
      }
      else if (fVar1 == _DAT_00572cf4) {
        fStack_108 = 4.0;
      }
      else if (fVar1 == _DAT_00572cf0) {
        fStack_108 = 2.0;
      }
      else if (fVar1 == _DAT_00572ce0) {
        fStack_108 = 1.5;
      }
      else if (fVar1 == _DAT_00572cec) {
        fStack_108 = 1.0;
      }
    }
    else if (fVar1 == _DAT_00572ce8) {
      fStack_108 = 1.5;
    }
    else if (fVar1 == _DAT_00572cec) {
      fStack_108 = 2.0;
    }
    else {
      iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar3 != 0) && (iVar3 = RGE_Base_Game::gameDeveloperMode(rge_base_game), iVar3 != 0)) {
        if (fVar1 == _DAT_00572ce0) {
          fStack_108 = 4.0;
        }
        else if (fVar1 == _DAT_00572cf0) {
          fStack_108 = 8.0;
        }
        else if (fVar1 == _DAT_00572cf4) {
          fStack_108 = 16.0;
        }
      }
    }
    if (fStack_108 != _DAT_00572ce4) {
      iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (iVar3 != 0) {
        pcVar2 = TPanel::get_string(param_1,0xbf3);
        sprintf(acStack_100,pcVar2);
        TCommunications_Handler::SendChatMsgAll(comm,acStack_100);
      }
      TRIBE_Command::command_game_speed
                (*(TRIBE_Command **)(*(int *)&param_1[5].fill_in_background + 0x58),fStack_108);
      iVar3 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if (iVar3 != 0) {
        RGE_Base_Game::set_game_speed(rge_base_game,fStack_108);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c53b
// Address: 0049c53b
// XREFS: None
void FUN_0049c53b(void)
{
  int iVar1;
  RGE_Player *this;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    iVar1 = -1;
    this = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::group_objects(this,iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c564
// Address: 0049c564
// XREFS: None
void FUN_0049c564(int param_1)
{
  int iVar1;
  RGE_Player *this;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    if (param_1 == 0) {
      param_1 = 10;
    }
    this = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::group_objects(this,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c5a2
// Address: 0049c5a2
// XREFS: None
void __fastcall FUN_0049c5a2(TPanel *param_1)
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
    pcVar2 = TPanel::get_string(param_1,0xbe3);
    TMessagePanel::show_message
              ((TMessagePanel *)param_1[5].handle_mouse_input,BadMessage,pcVar2,uVar3,(uchar)pvVar1,
               pvVar4,(long)pvVar5,(long)pvVar6);
    (**(code **)(rge_base_game->_padding_ + 0x10))(0x66,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c5f3
// Address: 0049c5f3
// XREFS: None
void __fastcall FUN_0049c5f3(TPanel *param_1)
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
    pcVar2 = TPanel::get_string(param_1,0xbec);
    TMessagePanel::show_message
              ((TMessagePanel *)param_1[5].handle_mouse_input,BadMessage,pcVar2,uVar3,(uchar)pvVar1,
               pvVar4,(long)pvVar5,(long)pvVar6);
    (**(code **)(rge_base_game->_padding_ + 0x10))(0x68,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c643
// Address: 0049c643
// XREFS: None
void __thiscall FUN_0049c643(TRIBE_Screen_Game *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 8;
  piVar2 = (int *)((int)param_1->score_panel + 3);
  *(char *)(*(int *)((int)&param_1->world + 3) + 0x11c) = (char)param_2;
  do {
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0x14))(param_2);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (param_2 != 0) {
    TRIBE_Screen_Game::reset_score_display(param_1);
  }
  piVar2 = *(int **)((int)&param_1->text_line_panel + 3);
  if (*(char *)(*(int *)((int)&param_1->world + 3) + 0x11c) != '\0') {
    (**(code **)(*piVar2 + 0x18))(8,4,0,0xb8,4,0,0,0x22,0x22,0,0,0,0);
    (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x20))(1);
    return;
  }
  (**(code **)(*piVar2 + 0x18))(8,4,0,4,4,0,0,0x22,0x22,0,0,0,0);
  (**(code **)(**(int **)((int)&param_1->main_view + 3) + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0049c70d
// Address: 0049c70d
// XREFS: None
void __thiscall FUN_0049c70d(int param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Player *pRVar2;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      pRVar2 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::unselect_object(pRVar2);
    }
    if (param_2 == 0) {
      param_2 = 10;
    }
    pRVar2 = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::select_group(pRVar2,param_2);
    (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c76d
// Address: 0049c76d
// XREFS: None
void __fastcall FUN_0049c76d(TScreenPanel *param_1)
{
  int iVar1;
  TribeMenuDialog *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055eecb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (rge_base_game->prog_mode == 6) {
    RGE_Command::do_commands(*(RGE_Command **)(*(int *)&param_1[1].field_0x13c + 0x58));
  }
  iVar1 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar1 == 1) {
    RGE_Base_Game::set_paused(rge_base_game,1,1);
  }
  this = (TribeMenuDialog *)operator_new(0x4bc);
  uStack_4 = 0;
  if (this != (TribeMenuDialog *)0x0) {
    TribeMenuDialog::TribeMenuDialog(this,param_1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049c7f7
// Address: 0049c7f7
// XREFS: None
void __fastcall FUN_0049c7f7(TRIBE_Screen_Game *param_1)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    if ((rge_base_game->game_mode == 6) && (rge_base_game->sub_game_mode == 1)) {
      *(ushort *)((int)&param_1->last_item + 1) =
           (-(ushort)(*(short *)((int)&param_1->last_item + 1) != 0) & 0xfff6) + 10;
      TRIBE_Screen_Game::setup_buttons(param_1);
      return;
    }
    if ((int)*(short *)&param_1->field_0x5e4 < *(short *)((int)&param_1->start_item + 1) + -1) {
      *(short *)((int)&param_1->last_item + 1) = *(short *)&param_1->field_0x5e4 + 1;
      TRIBE_Screen_Game::setup_buttons(param_1);
      return;
    }
    *(undefined2 *)((int)&param_1->last_item + 1) = 0;
    TRIBE_Screen_Game::setup_buttons(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c883
// Address: 0049c883
// XREFS: None
void __fastcall FUN_0049c883(TPanel *param_1)
{
  uchar uVar1;
  int iVar2;
  RGE_Player *this;
  char *pcVar3;
  RGE_Static_Object ***pppRVar4;
  short *psVar5;
  uchar uVar6;
  short sVar7;
  short sVar8;
  void *pvVar9;
  short sVar10;
  long lVar11;
  short sVar12;
  long lVar13;
  short sStack_6;
  RGE_Static_Object **ppRStack_4;
  
  iVar2 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar2 == 0) {
    sVar12 = -1;
    sVar10 = -1;
    sVar8 = -1;
    psVar5 = &sStack_6;
    sVar7 = -1;
    pppRVar4 = &ppRStack_4;
    this = RGE_Base_Game::get_player(rge_base_game);
    uVar1 = RGE_Player::get_selected_objects_to_command
                      (this,pppRVar4,psVar5,sVar7,sVar8,sVar10,sVar12);
    if (uVar1 != '\0') {
      free(ppRStack_4);
      lVar13 = 0;
      lVar11 = 0;
      pvVar9 = (void *)0x0;
      uVar6 = '\0';
      uVar1 = '2';
      pcVar3 = TPanel::get_string(param_1,0xbe0);
      TMessagePanel::show_message
                ((TMessagePanel *)param_1[5].handle_mouse_input,BadMessage,pcVar3,uVar1,uVar6,pvVar9
                 ,lVar11,lVar13);
      (**(code **)(rge_base_game->_padding_ + 0x10))(4,0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049c912
// Address: 0049c912
// XREFS: None
void FUN_0049c912(void)
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

// Function: FUN_0049ca08
// Address: 0049ca08
// XREFS: None
void __fastcall FUN_0049ca08(int param_1)
{
  int iVar1;
  RGE_Player *this;
  undefined4 unaff_retaddr;
  
  iVar1 = RGE_Base_Game::allowCheatCodes(rge_base_game);
  if (iVar1 != 0) {
    this = RGE_Base_Game::get_player(rge_base_game);
    RGE_Player::unselect_object(this);
    (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(1);
    if ((rge_base_game->game_mode == 6) && (rge_base_game->sub_game_mode == 1)) {
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    }
    (**(code **)(rge_base_game->_padding_ + 0x14))(unaff_retaddr);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049ca76
// Address: 0049ca76
// XREFS: None
void __fastcall FUN_0049ca76(int param_1)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::allowCheatCodes(rge_base_game);
  if (iVar1 != 0) {
    TRIBE_Command::command_quick_build
              (*(TRIBE_Command **)(*(int *)(param_1 + 0x5b4) + 0x58),
               (ushort)(rge_base_game->quick_build == 0));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0049cab6
// Address: 0049cab6
// XREFS: None
void FUN_0049cab6(void)
{
  TCommunications_Handler::SendIResignMsg(comm);
  TCommunications_Handler::GameOver(comm);
  TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
  return;
}

// --------------------------------------------------

// Function: FUN_0049cae1
// Address: 0049cae1
// XREFS: None
void __thiscall FUN_0049cae1(int param_1,short param_2)
{
  uchar uVar1;
  int iVar2;
  TRIBE_Player *pTVar3;
  short sVar4;
  short *psVar5;
  short asStack_202 [257];
  
  iVar2 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar2 == 0) {
    psVar5 = asStack_202;
    sVar4 = param_2;
    pTVar3 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    uVar1 = TRIBE_Player::check_tech_cost(pTVar3,sVar4,psVar5);
    if (uVar1 != '\0') {
      pTVar3 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
      TRIBE_Player::command_building_make_tech(pTVar3,param_2);
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

// Function: FUN_0049cc14
// Address: 0049cc14
// XREFS: None
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
void __fastcall FUN_0049cc14(int param_1)
{
  TribeSaveGameScreen *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ef0b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (rge_base_game->prog_mode == 6) {
    RGE_Command::do_commands(*(RGE_Command **)(*(int *)(param_1 + 0x5b4) + 0x58));
  }
  this = (TribeSaveGameScreen *)operator_new(0x6a4);
  uStack_4 = 0;
  if (this != (TribeSaveGameScreen *)0x0) {
    TribeSaveGameScreen::TribeSaveGameScreen(this,SaveScenario,(char *)0x0,0);
  }
  uStack_4 = 0xffffffff;
  TPanelSystem::setCurrentPanel(&panel_system,s_Save_Game_Screen,0);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0049cca4
// Address: 0049cca4
// XREFS: None
void __thiscall FUN_0049cca4(int param_1,undefined4 param_2)
{
  short sVar1;
  short sVar2;
  int iVar3;
  RGE_Player *pRVar4;
  TRIBE_Player *this;
  RGE_Static_Object *pRVar5;
  float fVar6;
  RGE_Static_Object *pRVar7;
  float fVar8;
  
  iVar3 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar3 == 0) {
    switch(param_2) {
    case 0:
      iVar3 = 0x6d;
      break;
    case 1:
      iVar3 = 0xc;
      break;
    case 2:
      iVar3 = 0x2d;
      break;
    case 3:
      iVar3 = 0x57;
      break;
    case 4:
      iVar3 = 0x31;
      break;
    case 5:
      iVar3 = 0x65;
      break;
    case 6:
      iVar3 = 0x68;
      break;
    case 7:
      iVar3 = 0;
      break;
    default:
      goto switchD_0049ccd4_default;
    }
    pRVar4 = RGE_Base_Game::get_player(rge_base_game);
    if ((pRVar4->selected_obj == (RGE_Static_Object *)0x0) ||
       (pRVar4 = RGE_Base_Game::get_player(rge_base_game),
       pRVar4->selected_obj->master_obj->id != iVar3)) {
      pRVar5 = (RGE_Static_Object *)0x0;
    }
    else {
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      pRVar5 = pRVar4->selected_obj;
    }
    this = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    pRVar5 = TRIBE_Player::find_obj(this,(short)iVar3,pRVar5);
    if (pRVar5 != (RGE_Static_Object *)0x0) {
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::unselect_object(pRVar4);
      pRVar7 = pRVar5;
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::select_object(pRVar4,pRVar7);
      fVar8 = pRVar5->world_y;
      fVar6 = pRVar5->world_x;
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::set_view_loc(pRVar4,fVar6,fVar8);
      sVar1 = __ftol();
      sVar2 = __ftol();
      pRVar4 = RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::set_map_loc(pRVar4,sVar2,sVar1);
      (**(code **)(**(int **)(param_1 + 0x4b8) + 0x20))(1);
    }
  }
switchD_0049ccd4_default:
  return;
}

// --------------------------------------------------

