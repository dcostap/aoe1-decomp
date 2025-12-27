// GLOBAL FUNCTIONS PART 4800
// Function: FUN_00513dce
// Address: 00513dce
void __thiscall FUN_00513dce(int param_1,undefined4 param_2)
{
  short sVar1;
  
  switch(param_2) {
  case 1:
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
  default:
    return;
  case 0x17:
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    break;
  case 0x18:
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
    break;
  case 0x19:
  }
  sVar1 = __ftol();
  TRIBE_Player_Tech::do_tech(*(TRIBE_Player_Tech **)(param_1 + 0x220),sVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00513f95
// Address: 00513f95
/* WARNING: Control flow encountered bad instruction data */

void FUN_00513f95(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0051400f
// Address: 0051400f
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0051400f(RGE_Player *param_1)
{
  RGE_Map *pRVar1;
  code *pcVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  char cVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  TRIBE_Building_Object *this;
  int iVar11;
  RGE_Static_Object *pRVar12;
  int iVar13;
  float fStack_18;
  float fStack_14;
  int iStack_8;
  
  bVar6 = false;
  if (param_1->objects->list == (RGE_Object_Node *)0x0) {
    iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x631);
    fStack_18 = (float)((iVar10 * (param_1->world->map->map_height + -0x1e)) / 0x7fff + 0xf) -
                _DAT_00576868;
    iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x632);
    iVar13 = 1;
    fStack_14 = (float)((iVar10 * (param_1->world->map->map_width + -0x1e)) / 0x7fff + 0xf) -
                _DAT_00576868;
    do {
      cVar7 = (**(code **)(param_1->master_objects[0x6d]->_padding_ + 0x20))
                        (param_1,fStack_14 - _DAT_00576868,fStack_18 - _DAT_00576868,0,0,1,1,1,1,1);
      if (cVar7 == '\0') break;
      iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x631);
      fStack_18 = (float)((iVar10 * (param_1->world->map->map_height + -0x1e)) / 0x7fff + 0xf) -
                  _DAT_00576868;
      iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x632);
      iVar13 = iVar13 + 1;
      fStack_14 = (float)((iVar10 * (param_1->world->map->map_width + -0x1e)) / 0x7fff + 0xf) -
                  _DAT_00576868;
    } while (iVar13 < 5000);
    if (iVar13 < 5000) {
      this = (TRIBE_Building_Object *)
             (**(code **)(param_1->master_objects[0x6d]->_padding_ + 0x18))
                       (param_1,fStack_14,fStack_18,0);
      sVar8 = __ftol();
      sVar9 = __ftol();
      RGE_Player::set_map_loc(param_1,sVar9,sVar8);
      RGE_Player::set_view_loc(param_1,fStack_14,fStack_18);
      TRIBE_Building_Object::build(this,10000.0);
      iStack_8 = 3;
      do {
        bVar3 = true;
        do {
          iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x646);
          iVar13 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x647);
          iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x648);
          fVar4 = ((float)((iVar10 * 6) / 0x7fff + -3) - (float)iVar11 * _DAT_0057686c) + fStack_18;
          iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x649);
          fVar5 = ((float)((iVar13 * 6) / 0x7fff + -3) - (float)iVar10 * _DAT_0057686c) + fStack_14;
          if ((((_DAT_00576828 <= fVar4) &&
               (pRVar1 = param_1->world->map, fVar4 < (float)pRVar1->map_height)) &&
              (_DAT_00576828 <= fVar5)) &&
             ((fVar5 < (float)pRVar1->map_width &&
              (cVar7 = (**(code **)(param_1->master_objects[0x53]->_padding_ + 0x20))
                                 (param_1,fVar5,fVar4,0,0,1,1,1,1,1), cVar7 == '\0')))) {
            (**(code **)(param_1->master_objects[0x53]->_padding_ + 0x18))(param_1,fVar5,fVar4,0);
            bVar3 = false;
          }
        } while (bVar3);
        iStack_8 = iStack_8 + -1;
      } while (iStack_8 != 0);
    }
  }
  else {
    pRVar12 = RGE_Object_List::find_by_master_id
                        (param_1->objects,0x6d,0.0,0.0,'\0','\0',(RGE_Static_Object *)0x0);
    if (pRVar12 == (RGE_Static_Object *)0x0) {
      pRVar12 = param_1->objects->list->node;
    }
    sVar8 = __ftol();
    sVar9 = __ftol();
    RGE_Player::set_map_loc(param_1,sVar9,sVar8);
    RGE_Player::set_view_loc(param_1,pRVar12->world_x,pRVar12->world_y);
  }
  iVar10 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (((iVar10 != 0) || (iVar10 = RGE_Base_Game::randomGame(rge_base_game), iVar10 != 0)) &&
     (iVar10 = 1, 1 < param_1->world->player_num)) {
    pcVar2 = *(code **)(param_1->_padding_ + 0x1c);
    do {
      iVar13 = (*pcVar2)(iVar10);
      if ((iVar13 != 0) && (iVar10 != param_1->id)) {
        pRVar12 = RGE_Object_List::find_by_master_id
                            (param_1->objects,0x6d,0.0,0.0,'\0','\0',(RGE_Static_Object *)0x0);
        if ((pRVar12 != (RGE_Static_Object *)0x0) ||
           (pRVar12 = param_1->objects->list->node, pRVar12 != (RGE_Static_Object *)0x0)) {
          iVar13 = pRVar12->_padding_;
          (**(code **)(iVar13 + 0xd8))(param_1->world->players[iVar10],0,0xffffffff);
          (**(code **)(iVar13 + 0xdc))(param_1->world->players[iVar10],0,0xffffffff);
        }
        (**(code **)(param_1->world->players[iVar10]->_padding_ + 0x94))
                  (0x70,param_1->view_x,param_1->view_y,0,0);
        bVar6 = true;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_1->world->player_num);
  }
  if (((param_1->world->curr_player == param_1->id) && (bVar6)) &&
     (iVar10 = 1, 1 < param_1->world->player_num)) {
    do {
      if (iVar10 != param_1->id) {
        iVar13 = 1;
        do {
          iVar11 = RGE_Base_Game::playerID(rge_base_game,iVar13);
          if (iVar11 == iVar10) {
            iVar11 = (**(code **)(param_1->_padding_ + 0x1c))(iVar10);
            TChat::setInChatGroup(chat,iVar13,iVar11);
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < 9);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_1->world->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00514504
// Address: 00514504
void __thiscall
FUN_00514504(TRIBE_Player *param_1,undefined4 param_2,undefined4 param_3,ResourceItem *param_4)
{
  ResourceItem *this;
  short sStack_a;
  short sStack_8;
  short sStack_6;
  short sStack_4;
  short sStack_2;
  
  TRIBE_Player::obj_cost
            (param_1,(short)param_2,(char **)0x0,&sStack_a,(short *)&param_2,&sStack_6,&sStack_8,
             &sStack_2,&sStack_4,1.0);
  this = param_4;
  ResourceItem::incrementValue(param_4,(int)sStack_a,(int)(short)param_2);
  ResourceItem::incrementValue(this,(int)sStack_6,(int)sStack_8);
  ResourceItem::incrementValue(this,(int)sStack_2,(int)sStack_4);
  return;
}

// --------------------------------------------------

// Function: FUN_00514587
// Address: 00514587
int __thiscall FUN_00514587(TRIBE_Player *param_1,undefined4 param_2)
{
  short sStack_a;
  short sStack_8;
  short sStack_6;
  short sStack_4;
  short sStack_2;
  
  TRIBE_Player::obj_cost
            (param_1,(short)param_2,(char **)0x0,&sStack_2,(short *)&param_2,&sStack_4,&sStack_8,
             &sStack_6,&sStack_a,1.0);
  return (int)(short)param_2 + (int)sStack_a + (int)sStack_8;
}

// --------------------------------------------------

// Function: FUN_005145db
// Address: 005145db
void __thiscall
FUN_005145db(int param_1,undefined4 param_2,undefined4 param_3,ResourceItem *param_4)
{
  ResourceItem *this;
  short sStack_a;
  short sStack_8;
  short sStack_6;
  short sStack_4;
  short sStack_2;
  
  TRIBE_Player_Tech::tech_cost
            (*(TRIBE_Player_Tech **)(param_1 + 0x220),(short)param_2,&sStack_a,(short *)&param_2,
             &sStack_6,&sStack_8,&sStack_2,&sStack_4);
  this = param_4;
  ResourceItem::incrementValue(param_4,(int)sStack_a,(int)(short)param_2);
  ResourceItem::incrementValue(this,(int)sStack_6,(int)sStack_8);
  ResourceItem::incrementValue(this,(int)sStack_2,(int)sStack_4);
  return;
}

// --------------------------------------------------

// Function: FUN_00514656
// Address: 00514656
undefined4 __thiscall FUN_00514656(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + param_2 * 4);
  if (((iVar1 == 0) || (*(char *)(iVar1 + 0x52) == '\0')) && (param_2 != 0x6d)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00514687
// Address: 00514687
bool __thiscall FUN_00514687(int param_1,int param_2)
{
  return *(short *)(**(int **)(param_1 + 0x220) + 4 + param_2 * 8) == 1;
}

// --------------------------------------------------

// Function: FUN_005146aa
// Address: 005146aa
undefined4 __thiscall FUN_005146aa(int param_1,short param_2)
{
  short sVar1;
  
  sVar1 = TRIBE_Player_Tech::get_tech_state(*(TRIBE_Player_Tech **)(param_1 + 0x220),param_2);
  if ((sVar1 != 3) && (sVar1 != -1)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005146d9
// Address: 005146d9
void __thiscall FUN_005146d9(int param_1,short param_2)
{
  TRIBE_Player_Tech::get_tech_state(*(TRIBE_Player_Tech **)(param_1 + 0x220),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_005146f3
// Address: 005146f3
void FUN_005146f3(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00514701
// Address: 00514701
void FUN_00514701(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00514711
// Address: 00514711
// [HELPER] s_Build_List__s__City_Plan__s__Bui: "Build List:%s, City Plan:%s, BuildAI(C=%s, N=%s, L=%s, %d/%d)."
// [HELPER] s_ConCP__d__CurCP__d__AveUAms__3d_: "ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s."
// [HELPER] s_Dip__P1__d__d__d___P2__d__d__d__: "Dip: P1(%d/%d/%d), P2(%d/%d/%d), P3(%d/%d/%d), P4(%d/%d/%d), P5(%d/%d/%d), P6..."
// [HELPER] s_Gat_Act_Des____s___d__d____s___d: "Gat(Act/Des): %s=(%d/%d), %s=(%d/%d), %s=(%d/%d), %s=(%d/%d).  #Civs=%d, #Sol..."
// [HELPER] s_Invalid_currentUpdateComputerPla: "Invalid currentUpdateComputerPlayer..."
// [HELPER] s_Invalid_status_line_number_: "Invalid status line number."
// [HELPER] s_NeedRes___s__d___s__d___s__d___s: "NeedRes: %s=%d, %s=%d, %s=%d, %s=%d, ResDiff: %s=%d, %s=%d, %s=%d, %s=%d."
// [HELPER] s_Per___s__AttEnab__d__AttDly__d_M: "Per: %s, AttEnab=%d, AttDly=%d Min, ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms..."
// [HELPER] s_Pers__Spec_BL___Food___d__d___Wo: "Pers (Spec/BL): Food=(%d/%d), Wood=(%d/%d), Gold=(%d/%d), Stone=(%d/%d)."
char * __thiscall FUN_00514711(int param_1,int param_2)
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  iVar6 = *(int *)(param_1 + 0x238);
  if (iVar6 == 0) {
    iVar6 = *(int *)(*(int *)(param_1 + 0x3c) + 0xfc);
    if ((iVar6 != -1) &&
       (iVar6 = *(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x40) + iVar6 * 4), iVar6 != 0)) {
      iVar6 = *(int *)(iVar6 + 0x238);
      iVar7 = *(int *)(param_1 + 0x3c);
      uVar12 = *(undefined4 *)(iVar6 + 0x12468);
      uVar15 = *(undefined4 *)(iVar6 + 0x1246c);
      pcVar1 = TribeTacticalAIModule::updateAreaName((TribeTacticalAIModule *)(iVar6 + 0x1146c));
      sprintf((char *)(param_1 + 0x23c),s_ConCP__d__CurCP__d__AveUAms__3d_,
              *(undefined1 *)(iVar7 + 0x11d),*(undefined4 *)(iVar7 + 0xfc),uVar15,uVar12,pcVar1);
      return (char *)(param_1 + 0x23c);
    }
    return s_Invalid_currentUpdateComputerPla;
  }
  if (param_2 == 1) {
    BuildAIModule::buildListLength((BuildAIModule *)(iVar6 + 0x104));
    BuildAIModule::numberItemsIntoBuildList((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
    pcVar1 = BuildAIModule::lastBuildItemRequested
                       ((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
    pcVar2 = BuildAIModule::nextBuildItemRequested
                       ((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
    pcVar3 = BuildAIModule::currentBuildItemRequested
                       ((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
    pcVar4 = ConstructionAIModule::constructionPlanName
                       ((ConstructionAIModule *)(*(int *)(param_1 + 0x238) + 0x6c4));
    pcVar5 = BuildAIModule::buildListName((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
    sprintf((char *)(param_1 + 0x23c),s_Build_List__s__City_Plan__s__Bui,pcVar5,pcVar4,pcVar3,pcVar2
            ,pcVar1);
    return (char *)(param_1 + 0x23c);
  }
  if (param_2 == 2) {
    TribeTacticalAIModule::resourceDifference((TribeTacticalAIModule *)(iVar6 + 0x1146c),3);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),3);
    TribeResourceAIModule::resourceName
              ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    TribeTacticalAIModule::resourceDifference
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),2);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),2);
    TribeResourceAIModule::resourceName
              ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    TribeTacticalAIModule::resourceDifference
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),1);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),1);
    TribeResourceAIModule::resourceName
              ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    TribeTacticalAIModule::resourceDifference
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0);
    TribeResourceAIModule::resourceName
              ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    TribeTacticalAIModule::neededResourceAmount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),3);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),3);
    TribeResourceAIModule::resourceName
              ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    TribeTacticalAIModule::neededResourceAmount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),2);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),2);
    TribeResourceAIModule::resourceName
              ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    TribeTacticalAIModule::neededResourceAmount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),1);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),1);
    pcVar1 = TribeResourceAIModule::resourceName
                       ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    iVar6 = TribeTacticalAIModule::neededResourceAmount
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0);
    iVar7 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0);
    pcVar2 = TribeResourceAIModule::resourceName
                       ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar7);
    sprintf((char *)(param_1 + 0x33c),s_NeedRes___s__d___s__d___s__d___s,pcVar2,iVar6,pcVar1);
    return (char *)(param_1 + 0x33c);
  }
  if (param_2 == 3) {
    TribeTacticalAIModule::numberBoats((TribeTacticalAIModule *)(iVar6 + 0x1146c));
    TribeTacticalAIModule::numberSoldiers
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c));
    TribeTacticalAIModule::numberCivilians
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c));
    TribeTacticalAIModule::desiredGathererCount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),3);
    TribeTacticalAIModule::actualGathererCount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),3);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),3);
    TribeResourceAIModule::resourceName
              ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    TribeTacticalAIModule::desiredGathererCount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),2);
    TribeTacticalAIModule::actualGathererCount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),2);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),2);
    TribeResourceAIModule::resourceName
              ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    TribeTacticalAIModule::desiredGathererCount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),1);
    TribeTacticalAIModule::actualGathererCount
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),1);
    iVar6 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),1);
    pcVar1 = TribeResourceAIModule::resourceName
                       ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar6);
    iVar6 = TribeTacticalAIModule::desiredGathererCount
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0);
    iVar7 = TribeTacticalAIModule::actualGathererCount
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0);
    iVar8 = TribeTacticalAIModule::neededResource
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0);
    pcVar2 = TribeResourceAIModule::resourceName
                       ((TribeResourceAIModule *)(*(int *)(param_1 + 0x238) + 0x10d7c),iVar8);
    sprintf((char *)(param_1 + 0x43c),s_Gat_Act_Des____s___d__d____s___d,pcVar2,iVar7,iVar6,pcVar1);
    return (char *)(param_1 + 0x43c);
  }
  if (param_2 == 4) {
    TribeTacticalAIModule::strategicNumber((TribeTacticalAIModule *)(iVar6 + 0x1146c),0x9e);
    TribeTacticalAIModule::strategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0x77);
    TribeTacticalAIModule::strategicNumber
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0x9f);
    iVar6 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0x76);
    iVar7 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0x9d);
    iVar8 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0x78);
    iVar9 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0x9c);
    iVar10 = TribeTacticalAIModule::strategicNumber
                       ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0x75);
    sprintf((char *)(param_1 + 0x53c),s_Pers__Spec_BL___Food___d__d___Wo,iVar10,iVar9,iVar8,iVar7,
            iVar6);
    return (char *)(param_1 + 0x53c);
  }
  if (param_2 == 5) {
    DiplomacyAIModule::stance((DiplomacyAIModule *)(iVar6 + 0x9dc),8,2);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),8,1);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),8,0);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),7,2);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),7,1);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),7,0);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),6,2);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),6,1);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),6,0);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),5,2);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),5,1);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),5,0);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),4,2);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),4,1);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),4,0);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),3,2);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),3,1);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),3,0);
    DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),2,2);
    iVar6 = DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),2,1);
    iVar7 = DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),2,0);
    iVar8 = DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),1,2);
    iVar9 = DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),1,1);
    iVar10 = DiplomacyAIModule::stance((DiplomacyAIModule *)(*(int *)(param_1 + 0x238) + 0x9dc),1,0)
    ;
    sprintf((char *)(param_1 + 0x63c),s_Dip__P1__d__d__d___P2__d__d__d__,iVar10,iVar9,iVar8,iVar7,
            iVar6);
    return (char *)(param_1 + 0x63c);
  }
  if (param_2 == 6) {
    uVar12 = *(undefined4 *)(iVar6 + 0x12284);
    iVar6 = *(int *)(param_1 + 0x3c);
    iVar7 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x40) +
                             *(int *)(*(int *)(param_1 + 0x3c) + 0xfc) * 4) + 0x238);
    uVar15 = *(undefined4 *)(iVar7 + 0x12468);
    uVar14 = *(undefined4 *)(iVar7 + 0x1246c);
    pcVar1 = TribeTacticalAIModule::updateAreaName((TribeTacticalAIModule *)(iVar7 + 0x1146c));
    uVar13 = *(undefined4 *)(iVar6 + 0xfc);
    uVar11 = (uint)*(byte *)(iVar6 + 0x11d);
    iVar6 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0x68);
    iVar6 = iVar6 / 0x3c;
    pcVar2 = TribeStrategyAIModule::ruleSetName
                       ((TribeStrategyAIModule *)(*(int *)(param_1 + 0x238) + 0x10e74));
    sprintf((char *)(param_1 + 0x73c),s_Per___s__AttEnab__d__AttDly__d_M,pcVar2,uVar12,iVar6,uVar11,
            uVar13,uVar14,uVar15,pcVar1);
    return (char *)(param_1 + 0x73c);
  }
  return s_Invalid_status_line_number_;
}

// --------------------------------------------------

// Function: FUN_00514fa7
// Address: 00514fa7
int __thiscall FUN_00514fa7(int param_1,int param_2)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x238) != 0) {
    iVar1 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),param_2);
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00514fd3
// Address: 00514fd3
void FUN_00514fd3(int param_1,undefined4 param_2)
{
  undefined1 auStack_400 [1024];
  
  if (*(int *)(param_1 + 0x238) != 0) {
    vsprintf(auStack_400,param_2,&stack0x0000000c);
    AIModule::logCommonHistory
              (*(AIModule **)(param_1 + 0x238),(char *)*(AIModule **)(param_1 + 0x238),auStack_400);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00515031
// Address: 00515031
int __thiscall FUN_00515031(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)
{
  int iVar1;
  
  if (*(TribeMainDecisionAIModule **)(param_1 + 0x238) == (TribeMainDecisionAIModule *)0x0) {
    return 0;
  }
  iVar1 = TribeMainDecisionAIModule::processAICommand
                    (*(TribeMainDecisionAIModule **)(param_1 + 0x238),param_2,param_3,param_4,
                     param_5,param_6);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_005150d9
// Address: 005150d9
void __thiscall
FUN_005150d9(RGE_Player *param_1,RGE_Static_Object *param_2,int param_3,int param_4,
            RGE_Object_Node *param_5)
{
  RGE_Player::removeObject(param_1,param_2,param_3,param_4,param_5);
  if ((((int *)param_1[1].position_checksum != (int *)0x0) &&
      (param_2->master_obj->object_group != 0xb)) && (-1 < param_2->id)) {
    (**(code **)(*(int *)param_1[1].position_checksum + 0x44))(param_2->id);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00515125
// Address: 00515125
void __thiscall
FUN_00515125(int param_1,int param_2,int param_3,float param_4,float param_5,int param_6)
{
  int *piVar1;
  
  piVar1 = (int *)calloc(1,4);
  *piVar1 = param_2;
  TRIBE_Command::command_build
            (*(TRIBE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             piVar1,1,param_3,param_4,param_5,param_6);
  free(piVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051517d
// Address: 0051517d
void __thiscall
FUN_0051517d(int param_1,int param_2,int param_3,int param_4,float param_5,float param_6,int param_7
            ,int param_8)
{
  if (*(int *)(param_1 + 0x238) != 0) {
    TribeBuildAIModule::cancelBuildItem
              ((TribeBuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104),param_2,param_3,param_4,
               param_5,param_6,param_7,param_8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005151bb
// Address: 005151bb
void __thiscall FUN_005151bb(int param_1,RGE_Static_Object *param_2,int param_3)
{
  if (*(int *)(param_1 + 0x238) != 0) {
    TribeBuildAIModule::addBuiltItem
              ((TribeBuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104),param_2,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005151e2
// Address: 005151e2
void __thiscall FUN_005151e2(int param_1,int param_2,int param_3,int param_4)
{
  TRIBE_Command::command_make
            (*(TRIBE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             param_3,param_2,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_00515212
// Address: 00515212
void __thiscall FUN_00515212(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  if (*(int *)(param_1 + 0x238) != 0) {
    TribeBuildAIModule::cancelTrainUnit
              ((TribeBuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104),param_2,param_3,param_4,
               param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051524c
// Address: 0051524c
void __thiscall FUN_0051524c(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  if (*(int *)(param_1 + 0x238) != 0) {
    TribeBuildAIModule::addTrainedUnit
              ((TribeBuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104),param_2,param_3,param_4,
               param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051527c
// Address: 0051527c
void __thiscall FUN_0051527c(int param_1,int param_2,int param_3,int param_4)
{
  TRIBE_Command::command_research
            (*(TRIBE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             param_3,param_2,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_005152a2
// Address: 005152a2
void __thiscall FUN_005152a2(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  if (*(int *)(param_1 + 0x238) != 0) {
    TribeBuildAIModule::cancelResearch
              ((TribeBuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104),param_2,param_3,param_4,
               param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005152dc
// Address: 005152dc
void __thiscall FUN_005152dc(int param_1,int param_2,int param_3,int param_4)
{
  if (*(int *)(param_1 + 0x238) != 0) {
    TribeBuildAIModule::addResearch
              ((TribeBuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104),param_2,param_3,param_4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00515307
// Address: 00515307
void __thiscall
FUN_00515307(int param_1,int param_2,int param_3,int param_4,float param_5,float param_6)
{
  int *piVar1;
  
  piVar1 = (int *)calloc(1,4);
  *piVar1 = param_2;
  RGE_Command::command_work
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             piVar1,1,param_3,param_4,param_5,param_6);
  free(piVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051535d
// Address: 0051535d
void __thiscall
FUN_0051535d(int param_1,int param_2,int param_3,int param_4,float param_5,float param_6)
{
  int *piVar1;
  
  piVar1 = (int *)calloc(1,4);
  *piVar1 = param_2;
  RGE_Command::command_work
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             piVar1,1,param_3,param_4,param_5,param_6);
  free(piVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_005153ad
// Address: 005153ad
void __thiscall FUN_005153ad(int param_1,short param_2,short param_3)
{
  TRIBE_Command::command_relation
            (*(TRIBE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),*(short *)(param_1 + 0x4a),param_2
             ,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_005153cd
// Address: 005153cd
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
// [HELPER] s_Loading_build_list__s_: "Loading build list=%s."
// [HELPER] s_Loading_city_plan__s_: "Loading city plan=%s."
// [HELPER] s_Loading_default_build_list__s_: "Loading default build list=%s."
// [HELPER] s_Loading_no_city_plan__influence_: "Loading no city plan (influence placement will be used)."
// [HELPER] s_Loading_random_game_selected_bui: "Loading random game selected build list=%s."
// [HELPER] s_Loading_random_game_selected_rul: "Loading random game selected rule set=%s."
// [HELPER] s_Loading_rule_set__s_: "Loading rule set=%s."
// [HELPER] s_NONE: "NONE"
// [HELPER] s_RandomGameSpecialized: "RandomGameSpecialized"
// [HELPER] s_Rule_set_has_been_initialized_wi: "Rule set has been initialized with code-controlled options."
// [HELPER] s_Setting_difficulty_level_to__d_: "Setting difficulty level to %d."
// [HELPER] s_We_don_t_have_a_specific_map_typ: "We don't have a specific map type (i.e. this is a scenario)."
// [HELPER] s_We_have_a_land_and_water_map_: "We have a land and water map."
// [HELPER] s_We_have_a_mostly_land_map_: "We have a mostly land map."
// [HELPER] s_We_have_a_mostly_water_map_: "We have a mostly water map."
// [HELPER] s_We_have_an_all_land_map_: "We have an all land map."
// [HELPER] s_We_have_an_all_water_map_: "We have an all water map."
void __thiscall
FUN_005153cd(TRIBE_Player *param_1,undefined4 param_2,undefined4 param_3,byte *param_4,int param_5)
{
  char cVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  MapType MVar7;
  int iVar8;
  MapSize MVar9;
  VictoryType VVar10;
  int iVar11;
  TribeMainDecisionAIModule *extraout_ECX;
  uint uVar12;
  uint uVar13;
  AIModule *this;
  TribeMainDecisionAIModule *extraout_ECX_00;
  TribeMainDecisionAIModule *extraout_ECX_01;
  AIModule *this_00;
  TribeMainDecisionAIModule *extraout_ECX_02;
  TribeMainDecisionAIModule *pTVar14;
  AIModule *extraout_ECX_03;
  AIModule *this_01;
  byte *pbVar16;
  byte *pbVar17;
  char *pcVar18;
  bool bVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  TribeMainDecisionAIModule *pTVar22;
  uchar uVar23;
  char *pcVar24;
  int iVar25;
  char acStack_318 [24];
  byte abStack_300 [232];
  byte abStack_218 [12];
  undefined1 auStack_20c [12];
  byte abStack_200 [256];
  undefined1 auStack_100 [236];
  byte *pbStack_14;
  byte *pbStack_10;
  undefined3 uVar15;
  
  uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x863);
  iVar5 = debug_random_on;
  global_save_debug_random_on2 = debug_random_on;
  debug_random_on = 0;
  if (param_1->playerAI == (TribeMainDecisionAIModule *)0x0) goto LAB_0051598d;
  MVar7 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
  pTVar14 = extraout_ECX;
  switch(MVar7) {
  case AllWater:
    pTVar22 = param_1->playerAI;
    pcVar24 = s_We_have_an_all_water_map_;
    break;
  case MostlyWater:
    pTVar14 = param_1->playerAI;
    pcVar24 = s_We_have_a_mostly_water_map_;
    pTVar22 = pTVar14;
    break;
  case WaterAndLand:
    pcVar24 = s_We_have_a_land_and_water_map_;
    goto LAB_00515473;
  case MostlyLand:
    pcVar24 = s_We_have_a_mostly_land_map_;
    pTVar22 = param_1->playerAI;
    break;
  case AllLand:
    pTVar14 = param_1->playerAI;
    pcVar24 = s_We_have_an_all_land_map_;
    pTVar22 = pTVar14;
    break;
  default:
    pcVar24 = s_We_don_t_have_a_specific_map_typ;
LAB_00515473:
    pTVar22 = param_1->playerAI;
  }
  AIModule::logCommonHistory((AIModule *)pTVar14,(char *)pTVar22,pcVar24);
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,auStack_100,0x100);
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x277b,auStack_20c,0x100);
  uVar12 = 0xffffffff;
  pcVar24 = s_;
  do {
    pcVar18 = pcVar24;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar18 = pcVar24 + 1;
    cVar1 = *pcVar24;
    pcVar24 = pcVar18;
  } while (cVar1 != '\0');
  uVar12 = ~uVar12;
  pcVar24 = pcVar18 + -uVar12;
  pcVar18 = &stack0xfffffbe8;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(undefined4 *)pcVar18 = *(undefined4 *)pcVar24;
    pcVar24 = pcVar24 + 4;
    pcVar18 = pcVar18 + 4;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *pcVar18 = *pcVar24;
    pcVar24 = pcVar24 + 1;
    pcVar18 = pcVar18 + 1;
  }
  uVar12 = 0xffffffff;
  pcVar24 = s_;
  do {
    pcVar18 = pcVar24;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar18 = pcVar24 + 1;
    cVar1 = *pcVar24;
    pcVar24 = pcVar18;
  } while (cVar1 != '\0');
  uVar12 = ~uVar12;
  pcVar24 = pcVar18 + -uVar12;
  pcVar18 = acStack_318;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(undefined4 *)pcVar18 = *(undefined4 *)pcVar24;
    pcVar24 = pcVar24 + 4;
    pcVar18 = pcVar18 + 4;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *pcVar18 = *pcVar24;
    pcVar24 = pcVar24 + 1;
    pcVar18 = pcVar18 + 1;
  }
  if (pbStack_14 == (byte *)0x0) {
    do {
      MVar9 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
      VVar10 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
      MVar7 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
      TRIBE_Player::intelligentBuildListAndRulesSelection
                (param_1,&stack0xfffffbe8,acStack_318,MVar7,VVar10,MVar9);
      AIModule::logCommonHistory
                (this_00,(char *)param_1->playerAI,s_Loading_default_build_list__s_,&stack0xfffffbe8
                );
      iVar8 = (**(code **)((param_1->playerAI->buildAI)._padding_ + 0x44))(&stack0xfffffbe8,param_1)
      ;
      pTVar14 = extraout_ECX_02;
    } while (iVar8 == 0);
  }
  else {
    pbVar17 = abStack_218;
    pbVar16 = pbStack_14;
    do {
      bVar2 = *pbVar16;
      bVar19 = bVar2 < *pbVar17;
      if (bVar2 != *pbVar17) {
LAB_0051554b:
        iVar8 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_00515550;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar16[1];
      bVar19 = bVar2 < pbVar17[1];
      if (bVar2 != pbVar17[1]) goto LAB_0051554b;
      pbVar16 = pbVar16 + 2;
      pbVar17 = pbVar17 + 2;
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_00515550:
    if (iVar8 == 0) {
      do {
        MVar9 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
        VVar10 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
        MVar7 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
        TRIBE_Player::intelligentBuildListAndRulesSelection
                  (param_1,&stack0xfffffbe8,acStack_318,MVar7,VVar10,MVar9);
        AIModule::logCommonHistory
                  (this,(char *)param_1->playerAI,s_Loading_random_game_selected_bui,
                   &stack0xfffffbe8);
        iVar8 = (**(code **)((param_1->playerAI->buildAI)._padding_ + 0x44))
                          (&stack0xfffffbe8,param_1);
        pTVar14 = extraout_ECX_00;
      } while (iVar8 == 0);
    }
    else {
      AIModule::logCommonHistory
                ((AIModule *)param_1->playerAI,(char *)param_1->playerAI,s_Loading_build_list__s_,
                 pbStack_14);
      (**(code **)((param_1->playerAI->buildAI)._padding_ + 0x44))(pbStack_14,param_1);
      pTVar14 = extraout_ECX_01;
    }
  }
  if (pbStack_10 == (byte *)0x0) {
    pTVar14 = param_1->playerAI;
    pTVar22 = pTVar14;
LAB_00515704:
    AIModule::logCommonHistory
              ((AIModule *)pTVar14,(char *)pTVar22,s_Loading_no_city_plan__influence_);
    iVar8 = *(int *)(param_1->_padding_ + 0x28);
    uVar21 = *(undefined4 *)(iVar8 + 0xc);
    uVar20 = *(undefined4 *)(iVar8 + 8);
    iVar8 = (param_1->playerAI->constructionAI)._padding_;
    pbStack_10 = &s_NONE;
  }
  else {
    pbVar17 = abStack_218;
    pbVar16 = pbStack_10;
    do {
      bVar2 = *pbVar16;
      uVar15 = (undefined3)((uint)pTVar14 >> 8);
      pTVar14 = (TribeMainDecisionAIModule *)CONCAT31(uVar15,bVar2);
      bVar19 = bVar2 < *pbVar17;
      if (bVar2 != *pbVar17) {
LAB_005156a7:
        iVar8 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_005156ac;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar16[1];
      bVar3 = pbVar17[1];
      pTVar14 = (TribeMainDecisionAIModule *)CONCAT31(uVar15,bVar3);
      bVar19 = bVar2 < bVar3;
      if (bVar2 != bVar3) goto LAB_005156a7;
      pbVar16 = pbVar16 + 2;
      pbVar17 = pbVar17 + 2;
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_005156ac:
    if (iVar8 == 0) {
      pTVar22 = param_1->playerAI;
      goto LAB_00515704;
    }
    AIModule::logCommonHistory
              ((AIModule *)param_1->playerAI,(char *)param_1->playerAI,s_Loading_city_plan__s_,
               pbStack_10);
    iVar8 = *(int *)(param_1->_padding_ + 0x28);
    uVar21 = *(undefined4 *)(iVar8 + 0xc);
    uVar20 = *(undefined4 *)(iVar8 + 8);
    iVar8 = (param_1->playerAI->constructionAI)._padding_;
  }
  (**(code **)(iVar8 + 0x40))(pbStack_10,uVar20,uVar21,0,0,0);
  this_01 = extraout_ECX_03;
  if (param_4 == (byte *)0x0) {
LAB_00515793:
    pbVar16 = &s_RandomGameSpecialized;
    pbVar17 = abStack_300;
    do {
      bVar2 = *pbVar17;
      uVar15 = (undefined3)((uint)this_01 >> 8);
      this_01 = (AIModule *)CONCAT31(uVar15,bVar2);
      bVar19 = bVar2 < *pbVar16;
      if (bVar2 != *pbVar16) {
LAB_005157c7:
        iVar8 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_005157cc;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar17[1];
      bVar3 = pbVar16[1];
      this_01 = (AIModule *)CONCAT31(uVar15,bVar3);
      bVar19 = bVar2 < bVar3;
      if (bVar2 != bVar3) goto LAB_005157c7;
      pbVar17 = pbVar17 + 2;
      pbVar16 = pbVar16 + 2;
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_005157cc:
    if (iVar8 != 0) {
      AIModule::logCommonHistory
                ((AIModule *)param_1->playerAI,(char *)param_1->playerAI,
                 s_Loading_random_game_selected_rul,abStack_300);
      param_4 = abStack_300;
      goto LAB_005157f4;
    }
    AIModule::logCommonHistory(this_01,(char *)param_1->playerAI,s_Rule_set_has_been_initialized_wi)
    ;
  }
  else {
    pbVar17 = abStack_200;
    pbVar16 = param_4;
    do {
      bVar2 = *pbVar16;
      uVar15 = (undefined3)((uint)this_01 >> 8);
      this_01 = (AIModule *)CONCAT31(uVar15,bVar2);
      bVar19 = bVar2 < *pbVar17;
      if (bVar2 != *pbVar17) {
LAB_00515772:
        iVar8 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_00515777;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar16[1];
      bVar3 = pbVar17[1];
      this_01 = (AIModule *)CONCAT31(uVar15,bVar3);
      bVar19 = bVar2 < bVar3;
      if (bVar2 != bVar3) goto LAB_00515772;
      pbVar16 = pbVar16 + 2;
      pbVar17 = pbVar17 + 2;
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_00515777:
    if (iVar8 == 0) goto LAB_00515793;
    AIModule::logCommonHistory(this_01,(char *)param_1->playerAI,s_Loading_rule_set__s_,param_4);
LAB_005157f4:
    TribeStrategyAIModule::loadRules(&param_1->playerAI->strategyAI,(char *)param_4);
  }
  iVar8 = RGE_Base_Game::difficulty(rge_base_game);
  AIModule::logCommonHistory
            ((AIModule *)param_1->playerAI,(char *)param_1->playerAI,
             s_Setting_difficulty_level_to__d_,iVar8);
  TribeStrategyAIModule::setDifficultyLevel(&param_1->playerAI->strategyAI,iVar8);
  TribeMainDecisionAIModule::updateBuildAIWithObjects(param_1->playerAI);
  iVar8 = 1;
  if (1 < *(short *)(param_1->_padding_ + 0x3c)) {
    do {
      if (iVar8 == *(short *)((int)&param_1->_padding_ + 2)) {
        DiplomacyAIModule::setStance(&param_1->playerAI->diplomacyAI,iVar8,0,0);
        iVar25 = 100;
LAB_005158d6:
        DiplomacyAIModule::setStance(&param_1->playerAI->diplomacyAI,iVar8,2,iVar25);
      }
      else {
        iVar25 = param_1->_padding_;
        iVar11 = (**(code **)(iVar25 + 0x18))(iVar8);
        if (iVar11 != 0) {
          DiplomacyAIModule::setStance(&param_1->playerAI->diplomacyAI,iVar8,0,0x4a);
          iVar25 = 0x18;
          goto LAB_005158d6;
        }
        iVar25 = (**(code **)(iVar25 + 0x1c))(iVar8);
        if (iVar25 != 0) {
          DiplomacyAIModule::setStance(&param_1->playerAI->diplomacyAI,iVar8,0,0x18);
          iVar25 = 0x4a;
          goto LAB_005158d6;
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(short *)(param_1->_padding_ + 0x3c));
  }
  iVar8 = 1;
  if (1 < *(short *)(param_1->_padding_ + 0x3c)) {
    iVar25 = param_1->_padding_;
    pcVar4 = *(code **)(iVar25 + 0x18);
    do {
      iVar11 = (*pcVar4)(iVar8);
      if ((iVar11 == 0) && (iVar11 = (**(code **)(iVar25 + 0x1c))(iVar8), iVar11 == 0)) {
        uVar23 = '\x01';
      }
      else {
        uVar23 = '\0';
      }
      DiplomacyAIModule::setChangeable(&param_1->playerAI->diplomacyAI,iVar8,uVar23);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(short *)(param_1->_padding_ + 0x3c));
  }
  EmotionalAIModule::setOverallState(&param_1->playerAI->emotionalAI,param_5);
  pcVar24 = *(char **)(*(int *)(param_1->_padding_ + 0x5c) + 0x1010);
  if (pcVar24 != (char *)0x0) {
    iVar8 = -1;
    pcVar18 = pcVar24;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar1 = *pcVar18;
      pcVar18 = pcVar18 + 1;
    } while (cVar1 != '\0');
    if (iVar8 != -2) {
      TribeInformationAIModule::loadLearnInfo(&param_1->playerAI->informationAI,pcVar24);
    }
  }
LAB_0051598d:
  debug_random_on = iVar5;
  debug_srand(s_C__msdev_work_age1_x1_tplayer_cp,0x8fd,uVar6);
  return;
}

// --------------------------------------------------

// Function: FUN_005159ba
// Address: 005159ba
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
void __fastcall FUN_005159ba(int *param_1,int param_2)
{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  undefined4 in_EAX;
  undefined3 uVar7;
  uint uVar6;
  undefined4 unaff_EBX;
  byte in_CF;
  byte in_AF;
  undefined1 unaff_retaddr;
  undefined4 uStack00000005;
  undefined1 in_stack_00000001 [11];
  undefined3 uStack_f;
  undefined1 uStack_c;
  undefined3 uStack_b;
  int *piStack_8;
  char cVar5;
  
  bVar2 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar7 = (undefined3)((uint)in_EAX >> 8);
  bVar4 = (byte)in_EAX + bVar2 * -6;
  cVar5 = bVar4 + (0x9f < bVar4 | in_CF | bVar2 * (bVar4 < 6)) * -0x60;
  cRam4b005154 = cRam4b005154 + (char)((uint)unaff_EBX >> 8);
  *(char *)(param_2 + 0x54) = *(char *)(param_2 + 0x54) + (char)param_2;
  pcVar1 = (char *)(CONCAT31(uVar7,cVar5) + 0x54);
  *pcVar1 = *pcVar1 + (char)((uint)in_EAX >> 8);
  *(char *)((int)param_1 + -0x75) = *(char *)((int)param_1 + -0x75) + (char)param_2;
  uVar6 = CONCAT31(uVar7,cVar5) & 0xffffff10;
  piStack_8 = param_1;
  if (uVar6 - 0x201 < 0xc) {
                    /* WARNING: Jumptable with 0 entries at 0x005159f1 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_005159f1::switchdataD_00515b88)[*(byte *)(uVar6 + 0x51599b)])();
    return;
  }
  uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x949);
  iVar3 = debug_random_on;
  global_save_debug_random_on4 = debug_random_on;
  debug_random_on = 0;
  if (param_1[0x8e] != 0) {
    uStack_b = (undefined3)((uint)&piStack_8 >> 8);
    uStack_f = (undefined3)((uint)param_1 >> 8);
    uStack_c = SUB41(&piStack_8,0);
    (**(code **)(*param_1 + 0x128))
              (CONCAT13(uStack_c,uStack_f),CONCAT13(piStack_8._0_1_,uStack_b),(uint)piStack_8 >> 8,
               CONCAT13(unaff_retaddr,(int3)((uint)&stack0x00000000 >> 8)),in_stack_00000001._0_4_,
               uStack00000005);
  }
  debug_random_on = iVar3;
  debug_srand(s_C__msdev_work_age1_x1_tplayer_cp,0x956,uVar6);
  return;
}

// --------------------------------------------------

// Function: FUN_00515dc3
// Address: 00515dc3
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
// [HELPER] s_RandomGameSpecialized: "RandomGameSpecialized"
undefined4 __fastcall FUN_00515dc3(int param_1,char param_2)
{
  char cVar1;
  uchar uVar2;
  char *in_EAX;
  int *piVar3;
  int iVar4;
  undefined4 extraout_EAX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  TRIBE_Player *unaff_EBP;
  int unaff_ESI;
  int iVar10;
  int iVar11;
  char *pcVar12;
  int unaff_EDI;
  undefined4 *puVar13;
  char *pcVar14;
  bool in_ZF;
  int in_stack_00000010;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  int in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_000000b8;
  int in_stack_000000bc;
  int in_stack_000000c0;
  int in_stack_000000c8;
  int in_stack_000000cc;
  int in_stack_000000d0;
  int in_stack_000000d4;
  int in_stack_000000d8;
  int in_stack_000000dc;
  int in_stack_000000e0;
  int in_stack_000000e4;
  int in_stack_000000ec;
  int in_stack_000000f0;
  int in_stack_000000f4;
  int in_stack_000000f8;
  int in_stack_000000fc;
  int in_stack_00000100;
  int in_stack_00000104;
  int in_stack_00000138;
  int in_stack_0000013c;
  int in_stack_00000140;
  int in_stack_00000158;
  int in_stack_0000015c;
  int in_stack_00000160;
  int in_stack_00000168;
  int in_stack_000001a0;
  int in_stack_000001a4;
  int in_stack_000001b0;
  int in_stack_000001b4;
  int in_stack_000001b8;
  int in_stack_000001c4;
  int in_stack_000001c8;
  int in_stack_000001cc;
  int in_stack_000001d8;
  int in_stack_000001dc;
  int in_stack_000001e0;
  char *in_stack_00000300;
  int in_stack_00000304;
  int in_stack_00000308;
  int in_stack_0000030c;
  int in_stack_0000031c;
  int in_stack_00000320;
  int in_stack_00000324;
  
  if (!in_ZF) {
    *(char *)(unaff_EDI + 0x1e00515c) = *(char *)(unaff_EDI + 0x1e00515c) + (char)param_1;
    *(char *)(unaff_EDI + 0x5d) = *(char *)(unaff_EDI + 0x5d) + param_2;
    *(char *)(unaff_ESI + -0x43ffaea3) =
         *(char *)(unaff_ESI + -0x43ffaea3) + (char)((uint)in_EAX >> 8);
    *in_EAX = *in_EAX + (char)in_EAX;
    pcRam05050505 = in_EAX + (int)pcRam05050505;
    return 0;
  }
  LOCK();
  *(int *)(param_1 + -0x46ebdbbc) = *(int *)(param_1 + -0x46ebdbbc) + -1;
  UNLOCK();
  *in_EAX = *in_EAX + (char)in_EAX;
  puVar13 = &stack0x00000018;
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  switch(*(undefined1 *)((int)&unaff_EBP->_padding_ + 1)) {
  case 1:
    TRIBE_Player::setupEgyptian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 2:
    TRIBE_Player::setupGreek
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 3:
    TRIBE_Player::setupBabylonian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 4:
    TRIBE_Player::setupAssyrian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 5:
    TRIBE_Player::setupMinoan
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 6:
    TRIBE_Player::setupHittite
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 7:
    TRIBE_Player::setupPhoenician
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 8:
    TRIBE_Player::setupSumerian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 9:
    TRIBE_Player::setupPersian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 10:
    TRIBE_Player::setupShang
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xb:
    TRIBE_Player::setupYamato
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xc:
    TRIBE_Player::setupChoson
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xd:
    TRIBE_Player::setupRoman
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xe:
    TRIBE_Player::setupCarthaginian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0xf:
    TRIBE_Player::setupPalmyran
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
    break;
  case 0x10:
    TRIBE_Player::setupMacedonian
              (unaff_EBP,&stack0x00000018,in_stack_0000031c,in_stack_00000320,in_stack_00000324);
  }
  TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc9,1);
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  iVar5 = unaff_ESI;
  if (uVar2 != '\0') goto LAB_005162c8;
  in_stack_00000010 = -1;
  TribeInformationAIModule::loadUnitHistory(&unaff_EBP->playerAI->informationAI);
  TribeInformationAIModule::unitsThatAreMostBuilt
            (&unaff_EBP->playerAI->informationAI,&stack0x00000010,(int *)&stack0x0000020c);
  iVar5 = unaff_ESI;
  switch(in_stack_00000010) {
  case 0:
    in_stack_00000030 = in_stack_00000030 + 0x19;
    in_stack_00000034 = in_stack_00000034 + 0x19;
    iVar5 = unaff_ESI;
    break;
  case 1:
    in_stack_00000030 = in_stack_00000030 + 0x1e;
    in_stack_00000034 = in_stack_00000034 + 0x1e;
    iVar5 = unaff_ESI;
    break;
  case 2:
    in_stack_0000005c = in_stack_0000005c + 0x14;
    in_stack_00000060 = in_stack_00000060 + 0x14;
    in_stack_00000024 = in_stack_00000024 + 0x28;
    in_stack_00000028 = in_stack_00000028 + 0x28;
    iVar5 = unaff_ESI;
    break;
  case 3:
    in_stack_0000005c = in_stack_0000005c + -0x3c;
    in_stack_00000018 = in_stack_00000018 + 0x28;
    in_stack_00000064 = in_stack_00000064 + 0x14;
    in_stack_00000068 = in_stack_00000068 + 0x14;
    in_stack_00000060 = in_stack_00000060 + -0x3c;
    in_stack_0000001c = in_stack_0000001c + 0x14;
    iVar5 = unaff_ESI;
    break;
  case 4:
    in_stack_00000030 = in_stack_00000030 + 0xf;
    in_stack_00000034 = in_stack_00000034 + 0xf;
    iVar5 = 0x14;
    goto LAB_00516297;
  case 5:
    in_stack_00000030 = in_stack_00000030 + 0xf;
    in_stack_00000034 = in_stack_00000034 + 0xf;
    in_stack_00000018 = in_stack_00000018 + 10;
    in_stack_0000001c = in_stack_0000001c + 10;
    iVar5 = unaff_ESI;
    break;
  case 6:
    in_stack_00000030 = in_stack_00000030 + 0xf;
    in_stack_00000034 = in_stack_00000034 + 0xf;
    iVar5 = unaff_ESI;
    break;
  case 7:
  case 10:
    in_stack_00000064 = in_stack_00000064 + -0x3c;
    in_stack_00000068 = in_stack_00000068 + -0x3c;
    iVar5 = unaff_ESI;
    break;
  case 8:
    in_stack_00000064 = in_stack_00000064 + 0x28;
    in_stack_00000068 = in_stack_00000068 + 0x28;
    iVar5 = unaff_ESI;
    break;
  case 9:
    iVar5 = 100;
LAB_00516297:
    in_stack_00000064 = in_stack_00000064 + iVar5;
    in_stack_00000068 = in_stack_00000068 + iVar5;
    iVar5 = unaff_ESI;
  }
LAB_005162c8:
  do {
    in_stack_00000010 = iVar5;
    switch(in_stack_00000010) {
    case 0:
      if (0 < in_stack_00000064) {
        in_stack_00000064 = in_stack_00000064 / 3;
      }
      if (0 < in_stack_00000068) {
        in_stack_00000068 = in_stack_00000068 / 3;
      }
      if (0 < in_stack_0000006c) {
        in_stack_0000006c = in_stack_0000006c / 3;
      }
      break;
    case 1:
      if (0 < in_stack_00000030) {
        in_stack_00000030 = in_stack_00000030 / 3;
      }
      if (0 < in_stack_00000034) {
        in_stack_00000034 = in_stack_00000034 / 3;
      }
      if (0 < in_stack_00000038) {
        in_stack_00000038 = in_stack_00000038 / 3;
      }
      if (0 < in_stack_00000104) {
        in_stack_00000104 = in_stack_00000104 / 3;
      }
      if (0 < in_stack_00000100) {
        in_stack_00000100 = in_stack_00000100 / 3;
      }
      if (0 < in_stack_000000f0) {
        in_stack_000000f0 = in_stack_000000f0 / 3;
      }
      if (0 < in_stack_000000f4) {
        in_stack_000000f4 = in_stack_000000f4 / 3;
      }
      if (0 < in_stack_000001b8) {
        in_stack_000001b8 = in_stack_000001b8 / 3;
      }
      break;
    case 2:
      if (0 < in_stack_00000058) {
        in_stack_00000058 = in_stack_00000058 / 3;
      }
      if (0 < in_stack_000000dc) {
        in_stack_000000dc = in_stack_000000dc / 3;
      }
      if (0 < in_stack_000001c8) {
        in_stack_000001c8 = in_stack_000001c8 / 3;
      }
      break;
    case 3:
      if (0 < in_stack_000000d0) {
        in_stack_000000d0 = in_stack_000000d0 / 3;
      }
      if (0 < in_stack_000000ec) {
        in_stack_000000ec = in_stack_000000ec / 3;
      }
      if (0 < in_stack_0000005c) {
        in_stack_0000005c = in_stack_0000005c / 3;
      }
      if (0 < in_stack_00000060) {
        in_stack_00000060 = in_stack_00000060 / 3;
      }
      if (0 < in_stack_000001a4) {
        in_stack_000001a4 = in_stack_000001a4 / 3;
      }
      if (0 < in_stack_000001b0) {
        in_stack_000001b0 = in_stack_000001b0 / 3;
      }
      if (0 < in_stack_000001cc) {
        in_stack_000001cc = in_stack_000001cc / 3;
      }
      if (0 < in_stack_00000060) {
        in_stack_00000060 = in_stack_00000060 / 3;
      }
      break;
    case 4:
      if (0 < in_stack_00000024) {
        in_stack_00000024 = in_stack_00000024 / 3;
      }
      if (0 < in_stack_00000028) {
        in_stack_00000028 = in_stack_00000028 / 3;
      }
      if (0 < in_stack_0000002c) {
        in_stack_0000002c = in_stack_0000002c / 3;
      }
      if (0 < in_stack_0000003c) {
        in_stack_0000003c = in_stack_0000003c / 3;
      }
      if (0 < in_stack_00000040) {
        in_stack_00000040 = in_stack_00000040 / 3;
      }
      if (0 < in_stack_00000044) {
        in_stack_00000044 = in_stack_00000044 / 3;
      }
      if (0 < in_stack_00000048) {
        in_stack_00000048 = in_stack_00000048 / 3;
      }
      if (0 < in_stack_000000c0) {
        in_stack_000000c0 = in_stack_000000c0 / 3;
      }
      if (0 < in_stack_000000c8) {
        in_stack_000000c8 = in_stack_000000c8 / 3;
      }
      if (0 < in_stack_000000cc) {
        in_stack_000000cc = in_stack_000000cc / 3;
      }
      if (0 < in_stack_000000d4) {
        in_stack_000000d4 = in_stack_000000d4 / 3;
      }
      if (0 < in_stack_000000d8) {
        in_stack_000000d8 = in_stack_000000d8 / 3;
      }
      if (0 < in_stack_000000f8) {
        in_stack_000000f8 = in_stack_000000f8 / 3;
      }
      if (0 < in_stack_00000140) {
        in_stack_00000140 = in_stack_00000140 / 3;
      }
      if (0 < in_stack_000001a0) {
        in_stack_000001a0 = in_stack_000001a0 / 3;
      }
      if (0 < in_stack_000001b4) {
        in_stack_000001b4 = in_stack_000001b4 / 3;
      }
      if (0 < in_stack_000001d8) {
        in_stack_000001d8 = in_stack_000001d8 / 3;
      }
      if (0 < in_stack_000001dc) {
        in_stack_000001dc = in_stack_000001dc / 3;
      }
      break;
    case 5:
      if (0 < in_stack_000000bc) {
        in_stack_000000bc = in_stack_000000bc / 3;
      }
      if (0 < in_stack_00000018) {
        in_stack_00000018 = in_stack_00000018 / 3;
      }
      if (0 < in_stack_0000001c) {
        in_stack_0000001c = in_stack_0000001c / 3;
      }
      if (0 < in_stack_00000020) {
        in_stack_00000020 = in_stack_00000020 / 3;
      }
      if (0 < in_stack_000000bc) {
        in_stack_000000bc = in_stack_000000bc / 3;
      }
      if (0 < in_stack_000000e0) {
        in_stack_000000e0 = in_stack_000000e0 / 3;
      }
      if (0 < in_stack_000000e4) {
        in_stack_000000e4 = in_stack_000000e4 / 3;
      }
      if (0 < in_stack_00000138) {
        in_stack_00000138 = in_stack_00000138 / 3;
      }
      if (0 < in_stack_0000013c) {
        in_stack_0000013c = in_stack_0000013c / 3;
      }
      if (0 < in_stack_000000e0) {
        in_stack_000000e0 = in_stack_000000e0 / 3;
      }
      if (0 < in_stack_000000e4) {
        in_stack_000000e4 = in_stack_000000e4 / 3;
      }
      if (0 < in_stack_00000158) {
        in_stack_00000158 = in_stack_00000158 / 3;
      }
      if (0 < in_stack_0000015c) {
        in_stack_0000015c = in_stack_0000015c / 3;
      }
      if (0 < in_stack_00000160) {
        in_stack_00000160 = in_stack_00000160 / 3;
      }
      if (0 < in_stack_000001c4) {
        in_stack_000001c4 = in_stack_000001c4 / 3;
      }
      break;
    case 6:
      if (0 < in_stack_000000b8) {
        in_stack_000000b8 = in_stack_000000b8 / 3;
      }
      if (0 < in_stack_000000fc) {
        in_stack_000000fc = in_stack_000000fc / 3;
      }
      if (0 < in_stack_000001e0) {
        in_stack_000001e0 = in_stack_000001e0 / 3;
      }
      if (0 < in_stack_00000168) {
        in_stack_00000168 = in_stack_00000168 / 3;
      }
    }
    in_stack_00000010 = in_stack_00000010 + 1;
    iVar5 = in_stack_00000010;
  } while (in_stack_00000010 < 7);
  piVar3 = &stack0x00000018;
  iVar5 = 0x7d;
  do {
    if (*piVar3 < 0) {
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar10 = 0;
  piVar3 = &stack0x00000018;
  iVar5 = 0x7d;
  do {
    iVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    iVar10 = iVar10 + iVar4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xc41);
  iVar11 = 0;
  iVar4 = 0;
  piVar3 = &stack0x00000018;
  do {
    iVar11 = iVar11 + *piVar3;
    iVar8 = iVar4;
    if (iVar5 % iVar10 < iVar11) break;
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    iVar8 = 0;
  } while (iVar4 < 0x7d);
  iVar5 = 0x100;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  switch(iVar8) {
  case 0:
  case 1:
  case 2:
  case 0x29:
  case 0x32:
  case 0x33:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x6b:
    DAT_00886c2c = DAT_00886c2c + 1;
    break;
  default:
    DAT_00886c28 = DAT_00886c28 + 1;
    break;
  case 6:
  case 7:
  case 8:
  case 0x2b:
  case 0x36:
  case 0x37:
  case 0x3a:
  case 0x3b:
  case 0x68:
    DAT_00886c1c = DAT_00886c1c + 1;
    break;
  case 0xd:
  case 0xe:
  case 0xf:
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x3b,4);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x3c,10);
    DAT_00886c34 = DAT_00886c34 + 1;
    DAT_00886c48 = DAT_00886c48 + 1;
    goto LAB_00516be6;
  case 0x10:
  case 0x31:
  case 0x6c:
    DAT_00886c20._0_4_ = (int)DAT_00886c20 + 1;
    break;
  case 0x11:
  case 0x12:
  case 0x2e:
  case 0x34:
  case 0x35:
  case 99:
  case 0x66:
  case 0x6d:
    DAT_00886c20._4_4_ = DAT_00886c20._4_4_ + 1;
    break;
  case 0x13:
  case 0x14:
  case 0x15:
    computerPlayerSetup = (int *)((int)computerPlayerSetup + 1);
    break;
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
    break;
  case 0x28:
  case 0x39:
  case 0x54:
  case 0x72:
    DAT_00886c30 = DAT_00886c30 + 1;
    break;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x53:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 100:
  case 0x65:
  case 0x69:
  case 0x6a:
  case 0x6e:
  case 0x6f:
  case 0x73:
  case 0x74:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
    DAT_00886c48 = DAT_00886c48 + 1;
    goto LAB_00516be6;
  case 0x48:
  case 0x49:
    DAT_00886c44 = DAT_00886c44 + 1;
    DAT_00886c2c = DAT_00886c2c + 1;
    goto LAB_00516be6;
  case 0x4a:
    DAT_00886c44 = DAT_00886c44 + 1;
    DAT_00886c28 = DAT_00886c28 + 1;
    goto LAB_00516be6;
  }
  DAT_00886c44 = DAT_00886c44 + 1;
LAB_00516be6:
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  AIModule::logCommonHistory
            ((AIModule *)(*(byte *)((int)&unaff_EBP->_padding_ + 1) - 1),(char *)unaff_EBP->playerAI
            );
  AIModule::logCommonHistory((AIModule *)unaff_EBP->playerAI,(char *)unaff_EBP->playerAI);
  uVar6 = 0xffffffff;
  pcVar12 = &s_RandomGameSpecialized;
  do {
    pcVar14 = pcVar12;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar14 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar14;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar12 = pcVar14 + -uVar6;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)in_stack_00000300 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    in_stack_00000300 = in_stack_00000300 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *in_stack_00000300 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    in_stack_00000300 = in_stack_00000300 + 1;
  }
  AIModule::logCommonHistory((AIModule *)0x0,(char *)unaff_EBP->playerAI);
  switch(in_stack_00000308) {
  case 0:
  case 1:
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x36,5);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x37,5);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,1);
    if (iVar10 < 1) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0,0x32);
      iVar10 = 0x32;
    }
    else {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0,0x32);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,1,0x19);
      iVar10 = 0x19;
    }
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,2,iVar10);
    if (1 < in_stack_00000304) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,3,5);
    }
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x2a,2);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x3d,2);
    if (in_stack_00000308 != 2) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x26,in_stack_0000030c + 1);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x24,1);
      if (in_stack_00000308 == 3) {
        iVar10 = 1;
      }
      else {
        iVar10 = 5;
      }
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x36,iVar10);
      if (in_stack_00000308 == 4) {
        iVar10 = 1;
      }
      else {
        iVar10 = 5;
      }
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x37,iVar10);
    }
  }
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar2 == '\x01') {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,4,10);
  }
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe3a);
  iVar10 = (iVar10 % 0xc + 0x1c) * 0x3c;
  switch(iVar8) {
  case 0:
  case 3:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0x13:
  case 0x2f:
  case 0x30:
  case 0x33:
  case 0x37:
  case 0x39:
  case 0x48:
  case 0x4a:
  case 0x4b:
  case 0x4e:
  case 0x51:
  case 0x55:
  case 0x58:
  case 0x5a:
  case 0x5e:
  case 0x60:
  case 100:
  case 0x69:
  case 0x6e:
  case 0x73:
    DAT_00886c3c = DAT_00886c3c + 1;
    iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe58);
    iVar10 = (iVar10 % 6 + 0x14) * 0x3c;
    break;
  default:
    DAT_00886c40 = DAT_00886c40 + 1;
    break;
  case 9:
  case 0x38:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe69);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = ((((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 5) * 0x3c;
    DAT_00886c38 = DAT_00886c38 + 1;
    break;
  case 10:
  case 0x29:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x32:
  case 0x3a:
  case 0x71:
    DAT_00886c38 = DAT_00886c38 + 1;
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe64);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = ((((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7) + 0xb) * 0x3c;
  }
  iVar4 = iVar5;
  if ((iVar5 == 0) &&
     (iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe73), iVar11 % 3 == 0)) {
    iVar10 = iVar10 + -300;
  }
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x68,iVar10);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x10,2);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x1a,10);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x5d,1);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,99,4);
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe80);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xbc,(uint)(iVar10 % 3 != 0));
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe86);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc3,iVar10 % 0x28 + 10);
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe8a);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xbd,iVar10 % 0x46 + 0x1e);
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe8e);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc6,(iVar10 % 5 + 5) * iVar5);
  iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe92);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,199,(iVar10 % 10 + 10) * iVar5);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xa1,4);
  if (in_stack_00000304 == 0) {
    in_stack_0000030c = in_stack_0000030c + -2;
  }
  else if (in_stack_00000304 == 1) {
    in_stack_0000030c = in_stack_0000030c + -1;
  }
  switch(in_stack_0000030c) {
  case 0:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea7);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0xf);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea9);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = iVar10 + 1 + (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  case 1:
    iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeac);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x49,iVar10 % 3 + 0x10);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeae);
    iVar8 = 5;
    iVar9 = iVar11 >> 0x1f;
    break;
  case 2:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb1);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x11);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb3);
    iVar8 = 6;
    iVar9 = iVar11 >> 0x1f;
    break;
  case 3:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb6);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x12);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb8);
    iVar8 = 7;
    iVar9 = iVar11 >> 0x1f;
    break;
  case 4:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xebb);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7) + 0x12);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xebd);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = iVar10 + 1 + (((uVar6 ^ uVar7) - uVar7 & 7 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  case -2:
  case -1:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea2);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0xe);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea4);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar10 = iVar10 + 1 + (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  default:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xec1);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&unaff_EBP->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x12);
    iVar10 = TribeStrategyAIModule::rule(&unaff_EBP->playerAI->strategyAI,0x49);
    iVar11 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xec3);
    iVar8 = 9;
    iVar9 = iVar11 >> 0x1f;
  }
  iVar10 = iVar10 + 1 + (int)(CONCAT44(iVar9,iVar11) % (longlong)iVar8);
LAB_005172a1:
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x4a,iVar10);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd0,1);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd1,1);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd2,1);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xdf,1);
  if (in_stack_00000304 == 0) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd4,3);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd5,6);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd6,2);
    iVar10 = 6;
LAB_00517478:
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xe0,iVar10);
  }
  else {
    if (in_stack_00000304 == 1) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd4,2);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd5,5);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd6,2);
      iVar10 = 4;
      goto LAB_00517478;
    }
    if ((((in_stack_00000304 == 2) || (in_stack_00000304 == 6)) || (in_stack_00000304 == 5)) ||
       (in_stack_00000304 == 8)) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd4,1);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd5,4);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd6,1);
      iVar10 = 3;
      goto LAB_00517478;
    }
    if (((in_stack_00000304 == 3) || (in_stack_00000304 == 4)) || (in_stack_00000304 == 7)) {
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd4,0);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd5,0);
      TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xd6,0);
      iVar10 = 0;
      goto LAB_00517478;
    }
  }
  if (allowAIToCheat != 0) {
    iVar5 = 0;
    iVar10 = 0;
    iVar11 = 0;
    iVar8 = 0;
    if (iVar4 == 0) {
      iVar5 = 2000;
      iVar11 = 2000;
      iVar8 = 2000;
      iVar10 = 2000;
    }
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x8a,iVar5);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x8b,iVar11);
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x8c,iVar8);
    iVar5 = iVar4;
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x8d,iVar10);
  }
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xa8,0);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xa2,0);
  if (iVar5 < 3) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc2,1);
    iVar10 = 2;
  }
  else {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xc2,0);
    iVar10 = 1;
  }
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0x2f,iVar10);
  if (iVar5 == 0) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 200;
  }
  else if (iVar5 == 1) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 0x96;
  }
  else if (iVar5 == 2) {
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 100;
  }
  else {
    if (iVar5 != 3) goto LAB_00517639;
    TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 0x32;
  }
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xba,iVar5);
LAB_00517639:
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xf50);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xb5,(uint)(iVar5 % 6 < 5));
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xf56);
  TribeStrategyAIModule::setRule(&unaff_EBP->playerAI->strategyAI,0xb6,(uint)(iVar5 % 3 < 1));
  return extraout_EAX;
}

// --------------------------------------------------

// Function: FUN_00515df5
// Address: 00515df5
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
// [HELPER] s_I_am_the__s_civ__culture___d__: "I am the %s civ (culture #%d):"
// [HELPER] s_RandomGameSpecialized: "RandomGameSpecialized"
// [HELPER] s_Selected_a_best_build_list_of___: "Selected a best build list of '%s'."
// [HELPER] s_Setting_AI_Personality_: "Setting AI Personality:"
void __thiscall
FUN_00515df5(TRIBE_Player *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)
{
  char cVar1;
  uchar uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  AIModule *this;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  int iStack_300;
  int iStack_2fc;
  int aiStack_2f8 [4];
  int iStack_2e8;
  int iStack_2e4;
  int iStack_2e0;
  int iStack_2dc;
  int iStack_2d8;
  int iStack_2d4;
  int iStack_2d0;
  int iStack_2cc;
  int iStack_2c8;
  int iStack_2c4;
  int iStack_2c0;
  int iStack_2b8;
  int iStack_2b4;
  int iStack_2b0;
  int iStack_2ac;
  int iStack_2a8;
  int iStack_2a4;
  int iStack_258;
  int iStack_254;
  int iStack_250;
  int iStack_248;
  int iStack_244;
  int iStack_240;
  int iStack_23c;
  int iStack_238;
  int iStack_234;
  int iStack_230;
  int iStack_22c;
  int iStack_224;
  int iStack_220;
  int iStack_21c;
  int iStack_218;
  int iStack_214;
  int iStack_210;
  int iStack_20c;
  int iStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1b8;
  int iStack_1b4;
  int iStack_1b0;
  int iStack_1a8;
  int iStack_170;
  int iStack_16c;
  int iStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_14c;
  int iStack_148;
  int iStack_144;
  int iStack_138;
  int iStack_134;
  int iStack_130;
  undefined1 auStack_118 [12];
  undefined1 auStack_10c [8];
  int aiStack_104 [61];
  char *pcStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if (param_1->playerAI == (TribeMainDecisionAIModule *)0x0) {
    return;
  }
  iStack_2fc = RGE_Base_Game::difficulty(rge_base_game);
  piVar3 = aiStack_2f8;
  for (iVar6 = 0x7d; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  switch(*(undefined1 *)((int)&param_1->_padding_ + 1)) {
  case 1:
    TRIBE_Player::setupEgyptian(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 2:
    TRIBE_Player::setupGreek(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 3:
    TRIBE_Player::setupBabylonian(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 4:
    TRIBE_Player::setupAssyrian(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 5:
    TRIBE_Player::setupMinoan(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 6:
    TRIBE_Player::setupHittite(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 7:
    TRIBE_Player::setupPhoenician(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 8:
    TRIBE_Player::setupSumerian(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 9:
    TRIBE_Player::setupPersian(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 10:
    TRIBE_Player::setupShang(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 0xb:
    TRIBE_Player::setupYamato(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 0xc:
    TRIBE_Player::setupChoson(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 0xd:
    TRIBE_Player::setupRoman(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 0xe:
    TRIBE_Player::setupCarthaginian(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 0xf:
    TRIBE_Player::setupPalmyran(param_1,aiStack_2f8,param_4,param_5,param_6);
    break;
  case 0x10:
    TRIBE_Player::setupMacedonian(param_1,aiStack_2f8,param_4,param_5,param_6);
  }
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if ((uVar2 == '\0') &&
     ((((cVar1 = *(char *)((int)&param_1->_padding_ + 1), cVar1 == '\x04' || (cVar1 == '\x01')) ||
       (cVar1 == '\x02')) ||
      (((cVar1 == '\x05' || (cVar1 == '\t')) ||
       ((cVar1 == '\a' || ((cVar1 == '\b' || (cVar1 == '\v')))))))))) {
    if (param_4 == 0) {
      if (DAT_00886c44 < 1) {
        iStack_2c4 = 0;
        iStack_2c0 = 0;
      }
      else if (DAT_00886c48 == 0) {
        iStack_2c4 = iStack_2c4 + 300;
        iStack_2c0 = iStack_2c0 + 300;
      }
      else {
        iStack_2c4 = iStack_2c4 + 100;
        iStack_2c0 = iStack_2c0 + 100;
      }
    }
    if (param_4 == 1) {
      if (DAT_00886c44 < 1) {
        iStack_2c4 = 0;
        iStack_2c0 = 0;
      }
      else if (DAT_00886c48 == 0) {
        iStack_2c4 = iStack_2c4 + 0xfa;
        iStack_2c0 = iStack_2c0 + 0xfa;
      }
      else {
        iStack_2c4 = iStack_2c4 + 0x4b;
        iStack_2c0 = iStack_2c0 + 0x4b;
      }
    }
    if (((param_4 == 2) || (param_4 == 6)) || (param_4 == 8)) {
      if (DAT_00886c44 < 1) {
        iStack_2c4 = 0;
        iStack_2c0 = 0;
      }
      else if (DAT_00886c48 == 0) {
        iStack_2c4 = iStack_2c4 + 200;
        iStack_2c0 = iStack_2c0 + 200;
      }
      else {
        iStack_2c4 = iStack_2c4 + 0x32;
        iStack_2c0 = iStack_2c0 + 0x32;
      }
    }
  }
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xc9,1);
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar2 != '\0') goto LAB_005162af;
  iStack_300 = -1;
  aiStack_104[0] = -1;
  TribeInformationAIModule::loadUnitHistory(&param_1->playerAI->informationAI);
  TribeInformationAIModule::unitsThatAreMostBuilt
            (&param_1->playerAI->informationAI,&iStack_300,aiStack_104);
  switch(iStack_300) {
  case 0:
    iStack_2e0 = iStack_2e0 + 0x19;
    iStack_2dc = iStack_2dc + 0x19;
    break;
  case 1:
    iStack_2e0 = iStack_2e0 + 0x1e;
    iStack_2dc = iStack_2dc + 0x1e;
    break;
  case 2:
    iStack_2b0 = iStack_2b0 + 0x14;
    iStack_2b4 = iStack_2b4 + 0x14;
    aiStack_2f8[3] = aiStack_2f8[3] + 0x28;
    iStack_2e8 = iStack_2e8 + 0x28;
    break;
  case 3:
    aiStack_2f8[0] = aiStack_2f8[0] + 0x28;
    iStack_2b4 = iStack_2b4 + -0x3c;
    iStack_2b0 = iStack_2b0 + -0x3c;
    aiStack_2f8[1] = aiStack_2f8[1] + 0x14;
    iStack_2ac = iStack_2ac + 0x14;
    iStack_2a8 = iStack_2a8 + 0x14;
    break;
  case 4:
    iStack_2e0 = iStack_2e0 + 0xf;
    iStack_2dc = iStack_2dc + 0xf;
    iVar6 = 0x14;
    goto LAB_00516297;
  case 5:
    iStack_2e0 = iStack_2e0 + 0xf;
    iStack_2dc = iStack_2dc + 0xf;
    aiStack_2f8[0] = aiStack_2f8[0] + 10;
    aiStack_2f8[1] = aiStack_2f8[1] + 10;
    break;
  case 6:
    iStack_2e0 = iStack_2e0 + 0xf;
    iStack_2dc = iStack_2dc + 0xf;
    break;
  case 7:
  case 10:
    iStack_2a8 = iStack_2a8 + -0x3c;
    iStack_2ac = iStack_2ac + -0x3c;
    goto LAB_005162a7;
  case 8:
    iStack_2ac = iStack_2ac + 0x28;
    iStack_2a8 = iStack_2a8 + 0x28;
    if (0 < DAT_00886c44) {
      iStack_2c4 = iStack_2c4 + 0x32;
      iStack_2c0 = iStack_2c0 + 0x32;
    }
    break;
  case 9:
    iVar6 = 100;
LAB_00516297:
    iStack_2a8 = iStack_2a8 + iVar6;
    iStack_2ac = iStack_2ac + iVar6;
LAB_005162a7:
  }
LAB_005162af:
  iStack_300 = 0;
  do {
    switch(iStack_300) {
    case 0:
      if (0 < iStack_2ac) {
        iStack_2ac = iStack_2ac / 3;
      }
      if (0 < iStack_2a8) {
        iStack_2a8 = iStack_2a8 / 3;
      }
      if (0 < iStack_2a4) {
        iStack_2a4 = iStack_2a4 / 3;
      }
      break;
    case 1:
      if (0 < iStack_2e0) {
        iStack_2e0 = iStack_2e0 / 3;
      }
      if (0 < iStack_2dc) {
        iStack_2dc = iStack_2dc / 3;
      }
      if (0 < iStack_2d8) {
        iStack_2d8 = iStack_2d8 / 3;
      }
      if (0 < iStack_20c) {
        iStack_20c = iStack_20c / 3;
      }
      if (0 < iStack_210) {
        iStack_210 = iStack_210 / 3;
      }
      if (0 < iStack_220) {
        iStack_220 = iStack_220 / 3;
      }
      if (0 < iStack_21c) {
        iStack_21c = iStack_21c / 3;
      }
      if (0 < iStack_158) {
        iStack_158 = iStack_158 / 3;
      }
      break;
    case 2:
      if (0 < iStack_2b8) {
        iStack_2b8 = iStack_2b8 / 3;
      }
      if (0 < iStack_234) {
        iStack_234 = iStack_234 / 3;
      }
      if (0 < iStack_148) {
        iStack_148 = iStack_148 / 3;
      }
      break;
    case 3:
      if (0 < iStack_240) {
        iStack_240 = iStack_240 / 3;
      }
      if (0 < iStack_224) {
        iStack_224 = iStack_224 / 3;
      }
      if (0 < iStack_2b4) {
        iStack_2b4 = iStack_2b4 / 3;
      }
      if (0 < iStack_2b0) {
        iStack_2b0 = iStack_2b0 / 3;
      }
      if (0 < iStack_16c) {
        iStack_16c = iStack_16c / 3;
      }
      if (0 < iStack_160) {
        iStack_160 = iStack_160 / 3;
      }
      if (0 < iStack_144) {
        iStack_144 = iStack_144 / 3;
      }
      if (0 < iStack_2b0) {
        iStack_2b0 = iStack_2b0 / 3;
      }
      break;
    case 4:
      if (0 < aiStack_2f8[3]) {
        aiStack_2f8[3] = aiStack_2f8[3] / 3;
      }
      if (0 < iStack_2e8) {
        iStack_2e8 = iStack_2e8 / 3;
      }
      if (0 < iStack_2e4) {
        iStack_2e4 = iStack_2e4 / 3;
      }
      if (0 < iStack_2d4) {
        iStack_2d4 = iStack_2d4 / 3;
      }
      if (0 < iStack_2d0) {
        iStack_2d0 = iStack_2d0 / 3;
      }
      if (0 < iStack_2cc) {
        iStack_2cc = iStack_2cc / 3;
      }
      if (0 < iStack_2c8) {
        iStack_2c8 = iStack_2c8 / 3;
      }
      if (0 < iStack_250) {
        iStack_250 = iStack_250 / 3;
      }
      if (0 < iStack_248) {
        iStack_248 = iStack_248 / 3;
      }
      if (0 < iStack_244) {
        iStack_244 = iStack_244 / 3;
      }
      if (0 < iStack_23c) {
        iStack_23c = iStack_23c / 3;
      }
      if (0 < iStack_238) {
        iStack_238 = iStack_238 / 3;
      }
      if (0 < iStack_218) {
        iStack_218 = iStack_218 / 3;
      }
      if (0 < iStack_1d0) {
        iStack_1d0 = iStack_1d0 / 3;
      }
      if (0 < iStack_170) {
        iStack_170 = iStack_170 / 3;
      }
      if (0 < iStack_15c) {
        iStack_15c = iStack_15c / 3;
      }
      if (0 < iStack_138) {
        iStack_138 = iStack_138 / 3;
      }
      if (0 < iStack_134) {
        iStack_134 = iStack_134 / 3;
      }
      break;
    case 5:
      if (0 < iStack_254) {
        iStack_254 = iStack_254 / 3;
      }
      if (0 < aiStack_2f8[0]) {
        aiStack_2f8[0] = aiStack_2f8[0] / 3;
      }
      if (0 < aiStack_2f8[1]) {
        aiStack_2f8[1] = aiStack_2f8[1] / 3;
      }
      if (0 < aiStack_2f8[2]) {
        aiStack_2f8[2] = aiStack_2f8[2] / 3;
      }
      if (0 < iStack_254) {
        iStack_254 = iStack_254 / 3;
      }
      if (0 < iStack_230) {
        iStack_230 = iStack_230 / 3;
      }
      if (0 < iStack_22c) {
        iStack_22c = iStack_22c / 3;
      }
      if (0 < iStack_1d8) {
        iStack_1d8 = iStack_1d8 / 3;
      }
      if (0 < iStack_1d4) {
        iStack_1d4 = iStack_1d4 / 3;
      }
      if (0 < iStack_230) {
        iStack_230 = iStack_230 / 3;
      }
      if (0 < iStack_22c) {
        iStack_22c = iStack_22c / 3;
      }
      if (0 < iStack_1b8) {
        iStack_1b8 = iStack_1b8 / 3;
      }
      if (0 < iStack_1b4) {
        iStack_1b4 = iStack_1b4 / 3;
      }
      if (0 < iStack_1b0) {
        iStack_1b0 = iStack_1b0 / 3;
      }
      if (0 < iStack_14c) {
        iStack_14c = iStack_14c / 3;
      }
      break;
    case 6:
      if (0 < iStack_258) {
        iStack_258 = iStack_258 / 3;
      }
      if (0 < iStack_214) {
        iStack_214 = iStack_214 / 3;
      }
      if (0 < iStack_130) {
        iStack_130 = iStack_130 / 3;
      }
      if (0 < iStack_1a8) {
        iStack_1a8 = iStack_1a8 / 3;
      }
    }
    iStack_300 = iStack_300 + 1;
  } while (iStack_300 < 7);
  piVar3 = aiStack_2f8;
  iVar6 = 0x7d;
  do {
    if (*piVar3 < 0) {
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar11 = 0;
  piVar3 = aiStack_2f8;
  iVar6 = 0x7d;
  do {
    iVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    iVar11 = iVar11 + iVar4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xc41);
  iVar12 = 0;
  iVar4 = 0;
  piVar3 = aiStack_2f8;
  do {
    iVar12 = iVar12 + *piVar3;
    iVar5 = iVar4;
    if (iVar6 % iVar11 < iVar12) break;
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    iVar5 = 0;
  } while (iVar4 < 0x7d);
  iVar6 = 0x100;
  (**(code **)(rge_base_game->_padding_ + 0x20))(iVar5 + 0x26930,param_2);
  switch(iVar5) {
  case 0:
  case 1:
  case 2:
  case 0x29:
  case 0x32:
  case 0x33:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x6b:
    DAT_00886c2c = DAT_00886c2c + 1;
    break;
  default:
    DAT_00886c28 = DAT_00886c28 + 1;
    break;
  case 6:
  case 7:
  case 8:
  case 0x2b:
  case 0x36:
  case 0x37:
  case 0x3a:
  case 0x3b:
  case 0x68:
    DAT_00886c1c = DAT_00886c1c + 1;
    break;
  case 0xd:
  case 0xe:
  case 0xf:
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x3b,4);
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x3c,10);
    DAT_00886c34 = DAT_00886c34 + 1;
    DAT_00886c48 = DAT_00886c48 + 1;
    goto LAB_00516be6;
  case 0x10:
  case 0x31:
  case 0x6c:
    DAT_00886c20._0_4_ = (int)DAT_00886c20 + 1;
    break;
  case 0x11:
  case 0x12:
  case 0x2e:
  case 0x34:
  case 0x35:
  case 99:
  case 0x66:
  case 0x6d:
    DAT_00886c20._4_4_ = DAT_00886c20._4_4_ + 1;
    break;
  case 0x13:
  case 0x14:
  case 0x15:
    computerPlayerSetup = (int *)((int)computerPlayerSetup + 1);
    break;
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
    break;
  case 0x28:
  case 0x39:
  case 0x54:
  case 0x72:
    DAT_00886c30 = DAT_00886c30 + 1;
    break;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x53:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 100:
  case 0x65:
  case 0x69:
  case 0x6a:
  case 0x6e:
  case 0x6f:
  case 0x73:
  case 0x74:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
    DAT_00886c48 = DAT_00886c48 + 1;
    goto LAB_00516be6;
  case 0x48:
  case 0x49:
    DAT_00886c44 = DAT_00886c44 + 1;
    DAT_00886c2c = DAT_00886c2c + 1;
    goto LAB_00516be6;
  case 0x4a:
    DAT_00886c44 = DAT_00886c44 + 1;
    DAT_00886c28 = DAT_00886c28 + 1;
    goto LAB_00516be6;
  }
  DAT_00886c44 = DAT_00886c44 + 1;
LAB_00516be6:
  (**(code **)(rge_base_game->_padding_ + 0x20))
            (*(byte *)((int)&param_1->_padding_ + 1) + 0x27f6,auStack_10c,0x100);
  this = (AIModule *)(*(byte *)((int)&param_1->_padding_ + 1) - 1);
  AIModule::logCommonHistory
            (this,(char *)param_1->playerAI,s_I_am_the__s_civ__culture___d__,auStack_118,this);
  AIModule::logCommonHistory
            ((AIModule *)param_1->playerAI,(char *)param_1->playerAI,
             s_Selected_a_best_build_list_of___,param_2);
  uVar7 = 0xffffffff;
  pcVar13 = &s_RandomGameSpecialized;
  do {
    pcVar14 = pcVar13;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar14 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar14;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  pcVar13 = pcVar14 + -uVar7;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcStack_10 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcStack_10 = pcStack_10 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcStack_10 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcStack_10 = pcStack_10 + 1;
  }
  AIModule::logCommonHistory((AIModule *)0x0,(char *)param_1->playerAI,s_Setting_AI_Personality_);
  iVar11 = iStack_c;
  switch(iStack_8) {
  case 0:
  case 1:
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x36,5);
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x37,5);
    iVar11 = iStack_c;
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    iVar11 = TribeStrategyAIModule::rule(&param_1->playerAI->strategyAI,1);
    if (iVar11 < 1) {
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0,0x32);
      iVar11 = 0x32;
    }
    else {
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0,0x32);
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,1,0x19);
      iVar11 = 0x19;
    }
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,2,iVar11);
    if (1 < iStack_c) {
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,3,5);
    }
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x2a,2);
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x3d,2);
    iVar11 = iStack_c;
    if (iStack_8 != 2) {
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x26,iStack_4 + 1);
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x24,1);
      if (iStack_8 == 3) {
        iVar4 = 1;
      }
      else {
        iVar4 = 5;
      }
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x36,iVar4);
      if (iStack_8 == 4) {
        iVar4 = 1;
      }
      else {
        iVar4 = 5;
      }
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x37,iVar4);
    }
  }
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar2 == '\x01') {
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,4,10);
  }
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe3a);
  iVar4 = (iVar4 % 0xc + 0x1c) * 0x3c;
  switch(iVar5) {
  case 0:
  case 3:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0x13:
  case 0x2f:
  case 0x30:
  case 0x33:
  case 0x37:
  case 0x39:
  case 0x48:
  case 0x4a:
  case 0x4b:
  case 0x4e:
  case 0x51:
  case 0x55:
  case 0x58:
  case 0x5a:
  case 0x5e:
  case 0x60:
  case 100:
  case 0x69:
  case 0x6e:
  case 0x73:
    DAT_00886c3c = DAT_00886c3c + 1;
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe58);
    iVar4 = (iVar4 % 6 + 0x14) * 0x3c;
    break;
  default:
    DAT_00886c40 = DAT_00886c40 + 1;
    break;
  case 9:
  case 0x38:
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe69);
    uVar8 = (int)uVar7 >> 0x1f;
    iVar4 = ((((uVar7 ^ uVar8) - uVar8 & 1 ^ uVar8) - uVar8) + 5) * 0x3c;
    DAT_00886c38 = DAT_00886c38 + 1;
    break;
  case 10:
  case 0x29:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x32:
  case 0x3a:
  case 0x71:
    DAT_00886c38 = DAT_00886c38 + 1;
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe64);
    uVar8 = (int)uVar7 >> 0x1f;
    iVar4 = ((((uVar7 ^ uVar8) - uVar8 & 3 ^ uVar8) - uVar8) + 0xb) * 0x3c;
  }
  iVar12 = iVar6;
  if ((iVar6 == 0) && (iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe73), iVar5 % 3 == 0)
     ) {
    iVar4 = iVar4 + -300;
  }
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x68,iVar4);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x10,2);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x1a,10);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x5d,1);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,99,4);
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe80);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xbc,(uint)(iVar4 % 3 != 0));
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe86);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xc3,iVar4 % 0x28 + 10);
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe8a);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xbd,iVar4 % 0x46 + 0x1e);
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe8e);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xc6,(iVar4 % 5 + 5) * iVar6);
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe92);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,199,(iVar4 % 10 + 10) * iVar6);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xa1,4);
  if (iVar11 == 0) {
    iStack_4 = iStack_4 + -2;
  }
  else if (iVar11 == 1) {
    iStack_4 = iStack_4 + -1;
  }
  switch(iStack_4) {
  case 0:
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea7);
    uVar8 = (int)uVar7 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&param_1->playerAI->strategyAI,0x49,
               (((uVar7 ^ uVar8) - uVar8 & 1 ^ uVar8) - uVar8) + 0xf);
    iVar4 = TribeStrategyAIModule::rule(&param_1->playerAI->strategyAI,0x49);
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea9);
    uVar8 = (int)uVar7 >> 0x1f;
    iVar4 = iVar4 + 1 + (((uVar7 ^ uVar8) - uVar8 & 3 ^ uVar8) - uVar8);
    goto LAB_005172a1;
  case 1:
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeac);
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x49,iVar4 % 3 + 0x10);
    iVar4 = TribeStrategyAIModule::rule(&param_1->playerAI->strategyAI,0x49);
    iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeae);
    iVar9 = 5;
    iVar10 = iVar5 >> 0x1f;
    break;
  case 2:
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb1);
    uVar8 = (int)uVar7 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&param_1->playerAI->strategyAI,0x49,
               (((uVar7 ^ uVar8) - uVar8 & 1 ^ uVar8) - uVar8) + 0x11);
    iVar4 = TribeStrategyAIModule::rule(&param_1->playerAI->strategyAI,0x49);
    iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb3);
    iVar9 = 6;
    iVar10 = iVar5 >> 0x1f;
    break;
  case 3:
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb6);
    uVar8 = (int)uVar7 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&param_1->playerAI->strategyAI,0x49,
               (((uVar7 ^ uVar8) - uVar8 & 1 ^ uVar8) - uVar8) + 0x12);
    iVar4 = TribeStrategyAIModule::rule(&param_1->playerAI->strategyAI,0x49);
    iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb8);
    iVar9 = 7;
    iVar10 = iVar5 >> 0x1f;
    break;
  case 4:
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xebb);
    uVar8 = (int)uVar7 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&param_1->playerAI->strategyAI,0x49,
               (((uVar7 ^ uVar8) - uVar8 & 3 ^ uVar8) - uVar8) + 0x12);
    iVar4 = TribeStrategyAIModule::rule(&param_1->playerAI->strategyAI,0x49);
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xebd);
    uVar8 = (int)uVar7 >> 0x1f;
    iVar4 = iVar4 + 1 + (((uVar7 ^ uVar8) - uVar8 & 7 ^ uVar8) - uVar8);
    goto LAB_005172a1;
  case -2:
  case -1:
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea2);
    uVar8 = (int)uVar7 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&param_1->playerAI->strategyAI,0x49,
               (((uVar7 ^ uVar8) - uVar8 & 1 ^ uVar8) - uVar8) + 0xe);
    iVar4 = TribeStrategyAIModule::rule(&param_1->playerAI->strategyAI,0x49);
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea4);
    uVar8 = (int)uVar7 >> 0x1f;
    iVar4 = iVar4 + 1 + (((uVar7 ^ uVar8) - uVar8 & 3 ^ uVar8) - uVar8);
    goto LAB_005172a1;
  default:
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xec1);
    uVar8 = (int)uVar7 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&param_1->playerAI->strategyAI,0x49,
               (((uVar7 ^ uVar8) - uVar8 & 1 ^ uVar8) - uVar8) + 0x12);
    iVar4 = TribeStrategyAIModule::rule(&param_1->playerAI->strategyAI,0x49);
    iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xec3);
    iVar9 = 9;
    iVar10 = iVar5 >> 0x1f;
  }
  iVar4 = iVar4 + 1 + (int)(CONCAT44(iVar10,iVar5) % (longlong)iVar9);
LAB_005172a1:
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x4a,iVar4);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd0,1);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd1,1);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd2,1);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xdf,1);
  if (iVar11 == 0) {
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd4,3);
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd5,6);
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd6,2);
    iVar11 = 6;
LAB_00517478:
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xe0,iVar11);
  }
  else {
    if (iVar11 == 1) {
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd4,2);
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd5,5);
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd6,2);
      iVar11 = 4;
      goto LAB_00517478;
    }
    if (((iVar11 == 2) || (iVar11 == 6)) || ((iVar11 == 5 || (iVar11 == 8)))) {
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd4,1);
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd5,4);
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd6,1);
      iVar11 = 3;
      goto LAB_00517478;
    }
    if (((iVar11 == 3) || (iVar11 == 4)) || (iVar11 == 7)) {
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd4,0);
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd5,0);
      TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xd6,0);
      iVar11 = 0;
      goto LAB_00517478;
    }
  }
  if (allowAIToCheat != 0) {
    iVar6 = 0;
    iVar11 = 0;
    iVar4 = 0;
    iVar5 = 0;
    if (iVar12 == 0) {
      iVar6 = 2000;
      iVar4 = 2000;
      iVar5 = 2000;
      iVar11 = 2000;
    }
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x8a,iVar6);
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x8b,iVar4);
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x8c,iVar5);
    iVar6 = iVar12;
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x8d,iVar11);
  }
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xa8,0);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xa2,0);
  if (iVar6 < 3) {
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xc2,1);
    iVar11 = 2;
  }
  else {
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xc2,0);
    iVar11 = 1;
  }
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0x2f,iVar11);
  if (iVar6 == 0) {
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xba,0xb4);
    iVar6 = 200;
  }
  else if (iVar6 == 1) {
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xba,0xb4);
    iVar6 = 0x96;
  }
  else if (iVar6 == 2) {
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xba,0xb4);
    iVar6 = 100;
  }
  else {
    if (iVar6 != 3) goto LAB_00517639;
    TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xba,0xb4);
    iVar6 = 0x32;
  }
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xba,iVar6);
LAB_00517639:
  iVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xf50);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xb5,(uint)(iVar6 % 6 < 5));
  iVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xf56);
  TribeStrategyAIModule::setRule(&param_1->playerAI->strategyAI,0xb6,(uint)(iVar6 % 3 < 1));
  return;
}

// --------------------------------------------------

// Function: FUN_005177e7
// Address: 005177e7
// [HELPER] s_Setting_up_as_Egyptians_: "Setting up as Egyptians."
/* WARNING: Instruction at (ram,0x00517bcc) overlaps instruction at (ram,0x00517bca)
    */

ushort * __fastcall FUN_005177e7(char *param_1,int param_2,ushort *param_3)
{
  ushort *puVar1;
  char *pcVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  ushort uVar7;
  char cVar8;
  uchar uVar9;
  int in_EAX;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ushort *puVar13;
  int iVar14;
  ushort *puVar15;
  AIModule *this;
  char cVar16;
  byte bVar17;
  undefined2 uVar18;
  char cVar20;
  char *pcVar19;
  byte bVar21;
  byte bVar22;
  char *unaff_EBX;
  int unaff_ESI;
  bool bVar23;
  bool bVar24;
  undefined4 unaff_retaddr;
  ushort *puStack00000008;
  int in_stack_00000020;
  int in_stack_00000024;
  ushort *in_stack_0000003c;
  ushort *puStack00000040;
  undefined4 *in_stack_00000044;
  int in_stack_00000048;
  undefined4 uStack0000004c;
  char *in_stack_00000050;
  byte *in_stack_00000054;
  ushort *in_stack_00000058;
  int in_stack_0000005c;
  
  cVar20 = (char)((uint)param_2 >> 8);
  *(char *)(unaff_ESI + 0x5e) = *(char *)(unaff_ESI + 0x5e) + cVar20;
  *(char *)(param_2 + -0x61ffaea2) = *(char *)(param_2 + -0x61ffaea2) + (char)param_1;
  *(char *)(param_2 + -0x39ffaea2) = *(char *)(param_2 + -0x39ffaea2) + cVar20;
  cVar16 = (char)param_2 + (char)unaff_EBX;
  cVar8 = (char)((uint)param_1 >> 8);
  cVar20 = cVar20 + cVar8;
  pcVar19 = (char *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(cVar20,cVar16));
  *pcVar19 = *pcVar19 + (char)in_EAX;
  *unaff_EBX = *unaff_EBX + cVar16;
  param_1[(int)unaff_EBX * 2] = param_1[(int)unaff_EBX * 2] + (char)((uint)in_EAX >> 8);
  cRam4600515f = cRam4600515f + cVar20;
  param_1[0x5f] = param_1[0x5f] + cVar16;
  *(char *)(in_EAX + 0x5f) = *(char *)(in_EAX + 0x5f) + cVar8;
  param_1[0x5f] = param_1[0x5f] + (char)((uint)unaff_EBX >> 8);
  *pcVar19 = *pcVar19 + (char)unaff_EBX;
  puStack00000008 = param_3;
  *param_1 = *param_1 + (char)((uint)unaff_retaddr >> 8);
  *(char *)(in_stack_00000020 + 0x51) =
       *(char *)(in_stack_00000020 + 0x51) + (char)in_stack_00000020;
  *(char *)(in_stack_00000024 + -0x36ffae9f) =
       *(char *)(in_stack_00000024 + -0x36ffae9f) + (char)in_stack_00000024;
  puStack00000040 = in_stack_0000003c;
  *in_stack_00000050 = *in_stack_00000050 + (char)((uint)in_stack_0000005c >> 8);
  uVar7 = *in_stack_00000058;
  bVar22 = (byte)((uint)in_stack_00000050 >> 8);
  *(byte *)in_stack_00000058 = (byte)*in_stack_00000058 + bVar22;
  *in_stack_00000058 =
       *in_stack_00000058 +
       (ushort)CARRY1((byte)uVar7,bVar22) *
       (((ushort)in_stack_0000005c & 3) - (*in_stack_00000058 & 3));
  *(byte *)(in_stack_00000044 + -0xeffeba7) = *(char *)(in_stack_00000044 + -0xeffeba7) + bVar22;
  cVar8 = (char)((uint)in_stack_00000058 >> 8);
  *in_stack_00000054 = *in_stack_00000054 + cVar8;
  uStack0000004c = 0x69db0051;
  *(char *)(in_stack_0000005c + -0x45ffae95) = *(char *)(in_stack_0000005c + -0x45ffae95) + bVar22;
  pcVar19 = (char *)(*(int *)in_stack_00000058 * -0x69);
  uVar18 = SUB42(pcVar19,0);
  bVar17 = in(uVar18);
  *(byte *)((int)in_stack_0000003c + -1) = bVar17;
  puVar13 = in_stack_0000003c + -0x21ffd74a;
  uVar7 = *puVar13;
  bVar17 = (byte)pcVar19;
  *(byte *)puVar13 = (byte)*puVar13 + bVar17;
  bVar21 = (byte)in_stack_00000050;
  if (CARRY1((byte)uVar7,bVar17) || (byte)*puVar13 == 0) {
    in_stack_00000058 =
         (ushort *)
         CONCAT22((short)((uint)in_stack_00000058 >> 0x10),
                  CONCAT11(cVar8 - *(char *)(in_stack_00000048 + 0x51),(char)in_stack_00000058));
  }
  else {
    pcVar2 = (char *)((int)in_stack_00000044 * 3 + 0x76bc0051);
    *pcVar2 = *pcVar2 + bVar22;
    puStack00000040 = in_stack_00000058;
    pcVar2 = (char *)((int)in_stack_00000044 * 3 + 0x6d2a0051);
    *pcVar2 = *pcVar2 + bVar22;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)in_stack_0000003c = uVar3;
    *(char *)((int)in_stack_00000044 + 0x5d00516d) =
         *(char *)((int)in_stack_00000044 + 0x5d00516d) + bVar17;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 2) = uVar3;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 4) = uVar3;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 6) = uVar3;
    *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
    *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 8) = uVar3;
    *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 10) = uVar3;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 0xc) = uVar3;
    *(char *)((int)in_stack_00000044 + 0x2a00516d) =
         *(char *)((int)in_stack_00000044 + 0x2a00516d) + bVar17;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 0xe) = uVar3;
    *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
    *pcVar19 = *pcVar19 + cVar8;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 0x10) = uVar3;
    puStack00000008 = in_stack_00000058;
    *pcVar19 = *pcVar19 + cVar8;
    puVar13 = in_stack_0000003c + 0x14;
    uVar3 = in(uVar18);
    *(undefined4 *)(in_stack_0000003c + 0x12) = uVar3;
    *pcVar19 = *pcVar19 + cVar8;
    in_stack_0000003c = in_stack_0000003c + 0x16;
    uVar3 = in(uVar18);
    *(undefined4 *)puVar13 = uVar3;
  }
  cVar8 = (char)((uint)in_stack_00000058 >> 8);
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)in_stack_0000003c = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 2) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 4) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 6) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 8) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 10) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0xc) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0xe) = uVar3;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0x10) = uVar3;
  *(char *)(in_stack_00000048 + 0x6d) = *(char *)(in_stack_00000048 + 0x6d) + bVar21;
  *pcVar19 = *pcVar19 + cVar8;
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0x12) = uVar3;
  cVar16 = (char)in_stack_00000058;
  puVar15 = (ushort *)
            CONCAT22((short)((uint)in_stack_00000058 >> 0x10),CONCAT11(cVar8 + cVar16,cVar16));
  uVar3 = in(uVar18);
  *(undefined4 *)(in_stack_0000003c + 0x14) = uVar3;
  bVar22 = *in_stack_00000054;
  *in_stack_00000054 = *in_stack_00000054 + (byte)in_stack_00000054;
  pbVar4 = (byte *)(uint)CARRY1(bVar22,(byte)in_stack_00000054);
  pbVar5 = in_stack_00000054 + -0x1d1d011d;
  cVar8 = (char)(pbVar5 + ((-0x3021d1d - (int)pbVar4) -
                          (uint)(in_stack_00000054 < (byte *)0x1d1d011d || pbVar5 < pbVar4)));
  uVar11 = CONCAT31((int3)((uint)(pbVar5 + ((-0x3021d1d - (int)pbVar4) -
                                           (uint)(in_stack_00000054 < (byte *)0x1d1d011d ||
                                                 pbVar5 < pbVar4))) >> 8),cVar8 + '!');
  uVar12 = (uint)(0xe2 < (byte)(cVar8 + 4U));
  uVar6 = uVar11 + 0xfae2e2e3;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x51d1d1d || uVar6 < uVar12);
  uVar6 = uVar10 + 0xe2e2e2e3;
  uVar11 = uVar6 - uVar12;
  uVar12 = (uint)(uVar10 < 0x1d1d1d1d || uVar6 < uVar12);
  uVar6 = uVar11 + 0xe2e2e2e3;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x1d1d1d1d || uVar6 < uVar12);
  uVar6 = uVar10 + 0xe2e2e2e3;
  uVar11 = uVar6 - uVar12;
  uVar12 = (uint)(uVar10 < 0x1d1d1d1d || uVar6 < uVar12);
  uVar6 = uVar11 + 0xe2e2e2e3;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x1d1d1d1d || uVar6 < uVar12);
  uVar6 = uVar10 + 0xf8f8e2fa;
  bVar21 = bVar21 | bRam0c0b1d1d;
  uVar12 = ((uVar6 - uVar12) + -0x91d0808) - (uint)(uVar10 < 0x7071d06 || uVar6 < uVar12) |
           0x1d1d1d0e;
  bVar23 = uVar12 + 0xe2e2e2e3 < 0x1d1d1d1d || uVar12 + 0xc5c5c5c6 < (uint)(uVar12 < 0x1d1d1d1d);
  uVar11 = (uVar12 + 0xc5c5c5c6) - (uint)(uVar12 < 0x1d1d1d1d);
  bVar24 = CARRY1(bRam1d1d111d,bVar21) || CARRY1(bRam1d1d111d + bVar21,bVar23);
  bRam1d1d111d = bRam1d1d111d + bVar21 + bVar23;
  cVar20 = bVar21 + bRam1d131d1d + bVar24;
  uVar12 = (uint)(CARRY1(bVar21,bRam1d131d1d) || CARRY1(bVar21 + bRam1d131d1d,bVar24));
  uVar6 = uVar11 + 0xe2eae2ec;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x1d151d14 || uVar6 < uVar12);
  uVar6 = uVar10 + 0xe8e2e9e3;
  uVar11 = uVar6 - uVar12;
  uVar12 = (uint)(uVar10 < 0x171d161d || uVar6 < uVar12);
  uVar6 = uVar11 + 0xe2e7e2e3;
  uVar10 = uVar6 - uVar12;
  uVar12 = (uint)(uVar11 < 0x1d181d1d || uVar6 < uVar12);
  uVar6 = uVar10 + 0xe2e6e2e3;
  uVar11 = uVar6 - uVar12;
  uVar12 = (uint)(uVar10 < 0x1d191d1d || uVar6 < uVar12);
  uVar6 = uVar11 + 0xe2e5e2e3;
  puVar13 = (ushort *)
            (((uVar6 - uVar12) + 0x4ae3e2e5) - (uint)(uVar11 < 0x1d1a1d1d || uVar6 < uVar12));
  out(*in_stack_00000044,uVar18);
  pcVar2 = (char *)(in_stack_00000048 + 0x2600516f);
  cVar8 = *pcVar2;
  bVar21 = (byte)((uint)pcVar19 >> 8);
  *pcVar2 = *pcVar2 + bVar21;
  if (SCARRY1(cVar8,bVar21)) {
    puVar13 = (ushort *)((uint)puVar13 ^ 0x7406f883);
    pbVar4 = (byte *)(CONCAT31((int3)((uint)in_stack_00000050 >> 8),cVar20) + 0x137405f8);
    *pbVar4 = *pbVar4 ^ (byte)puVar13;
  }
  else {
    puVar1 = puVar13 + -0x27fd748;
    uVar7 = *puVar1;
    *(byte *)puVar1 = (byte)*puVar1 + cVar20;
    if (SCARRY1((byte)uVar7,cVar20)) {
      pbVar4 = (byte *)((int)in_stack_00000044 + -0x71 + (int)puVar15);
      *pbVar4 = *pbVar4 | bVar21;
      puVar13 = (ushort *)((uint)(puVar13 + -0x3be7646) & 0xffffff04);
      goto code_r0x00517bd4;
    }
    pcVar19[0x71] = pcVar19[0x71] + (char)((uint)puVar13 >> 8);
    this = (AIModule *)CONCAT31((int3)((uint)puVar15 >> 8),cVar16 * '\x02');
    if (!SCARRY1(cVar16,cVar16)) goto code_r0x00517bd4;
    *(byte *)(puVar13 + -0x37b7b7b8) = (byte)puVar13[-0x37b7b7b8] + bVar17;
    AIModule::logCommonHistory
              (this,*(char **)(this[2].playerNameValue + 8),s_Setting_up_as_Egyptians_,puVar15,
               puVar15,in_stack_00000058,in_stack_00000058,in_stack_00000058,in_stack_00000058,
               in_stack_00000058,in_stack_00000058,in_stack_00000058,in_stack_00000058,
               in_stack_00000058,in_stack_00000058,in_stack_00000058);
    puVar13 = in_stack_00000058;
    uVar9 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
    if (uVar9 != '\x01') {
      iVar14 = RGE_Base_Game::difficulty(rge_base_game);
      if (iVar14 < 1) {
        puVar15[0x46] = 100;
        puVar15[0x47] = 0;
        return puVar15;
      }
      puVar15[6] = 10;
      puVar15[7] = 0;
      puVar15[0x12] = 10;
      puVar15[0x13] = 0;
      puVar15[0x14] = 10;
      puVar15[0x15] = 0;
      puVar15[0x22] = 0x28;
      puVar15[0x23] = 0;
      puVar15[0x24] = 0x28;
      puVar15[0x25] = 0;
      puVar15[0x5c] = 100;
      puVar15[0x5d] = 0;
      puVar15[0x26] = 0x32;
      puVar15[0x27] = 0;
      puVar15[0x28] = 0x32;
      puVar15[0x29] = 0;
      puVar15[0x5e] = 100;
      puVar15[0x5f] = 0;
      puVar15[0xa0] = 100;
      puVar15[0xa1] = 0;
      puVar15[0xa2] = 0x1e;
      puVar15[0xa3] = 0;
      puVar15[0xa4] = 0x14;
      puVar15[0xa5] = 0;
      if ((puVar13 == (ushort *)0x0) || (puVar13 == (ushort *)0x1)) {
        puVar15[0xa6] = 200;
        puVar15[0xa7] = 0;
      }
      else if ((((puVar13 == (ushort *)0x2) || (puVar13 == (ushort *)0x6)) ||
               (puVar13 == (ushort *)0x8)) || (puVar13 == (ushort *)0x5)) {
        puVar15[0xa6] = 100;
        puVar15[0xa7] = 0;
        return puVar15;
      }
      return puVar15;
    }
    if ((puVar13 == (ushort *)0x0) || (puVar13 == (ushort *)0x1)) {
      puVar15[0x7e] = 100;
      puVar15[0x7f] = 0;
      return puVar13;
    }
    if ((puVar13 == (ushort *)0x2) || (puVar13 == (ushort *)0x6)) {
      puVar15[0x32] = 0x3c;
      puVar15[0x33] = 0;
      puVar15[0x7e] = 0x28;
      puVar15[0x7f] = 0;
      return puVar15;
    }
    in_stack_00000058 = puVar13;
    if (puVar13 == (ushort *)0x5) goto LAB_00517be2;
  }
  if (puVar13 == (ushort *)0x8) {
LAB_00517be2:
    puVar13 = (ushort *)CONCAT31((int3)in_stack_00000058,(char)((uint)puVar15 >> 0x18));
    puVar13[0x32] = 0x50;
    puVar13[0x33] = 0;
    puVar13[0x7e] = 0x14;
    puVar13[0x7f] = 0;
    return puVar13;
  }
code_r0x00517bd4:
  *(undefined4 *)(CONCAT31((int3)in_stack_00000058,(char)((uint)puVar15 >> 0x18)) + 100) = 100;
  return puVar13;
}

// --------------------------------------------------

// Function: FUN_00517cce
// Address: 00517cce
// [HELPER] s_Setting_up_as_Greeks_: "Setting up as Greeks."
void __thiscall FUN_00517cce(AIModule *param_1,int param_2,int param_3)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Greeks_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      *(undefined4 *)(param_2 + 0x90) = 100;
      return;
    }
    *(undefined4 *)(param_2 + 0x18) = 0x1e;
    *(undefined4 *)(param_2 + 0x2c) = 0x1e;
    *(undefined4 *)(param_2 + 0x50) = 0x1e;
    *(undefined4 *)(param_2 + 0x24) = 10;
    *(undefined4 *)(param_2 + 0x28) = 10;
    *(undefined4 *)(param_2 + 0xc) = 0x46;
    *(undefined4 *)(param_2 + 0x10) = 0x32;
    *(undefined4 *)(param_2 + 0x1c) = 0x14;
    *(undefined4 *)(param_2 + 0x4c) = 0x32;
    *(undefined4 *)(param_2 + 0xc0) = 100;
    *(undefined4 *)(param_2 + 0x150) = 100;
    if ((param_3 == 0) || (param_3 == 1)) {
      *(undefined4 *)(param_2 + 0x154) = 200;
      *(undefined4 *)(param_2 + 0x158) = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      *(undefined4 *)(param_2 + 0x154) = 100;
      *(undefined4 *)(param_2 + 0x158) = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    *(undefined4 *)(param_2 + 0x100) = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      *(undefined4 *)(param_2 + 0x68) = 100;
      return;
    }
    *(undefined4 *)(param_2 + 0x68) = 0x50;
    *(undefined4 *)(param_2 + 0x100) = 0x14;
    return;
  }
  *(undefined4 *)(param_2 + 0x68) = 0x3c;
  *(undefined4 *)(param_2 + 0x100) = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00517e0e
// Address: 00517e0e
// [HELPER] s_Setting_up_as_Babylonians_: "Setting up as Babylonians."
void __thiscall FUN_00517e0e(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Babylonians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_2[1] = 10;
    param_2[6] = 10;
    param_2[9] = 10;
    param_2[0xb] = 10;
    *param_2 = 0x14;
    param_2[0x13] = 0x28;
    param_2[0x14] = 0x28;
    param_2[0x10] = 0x1e;
    param_2[0x2a] = 100;
    param_2[0x2b] = 100;
    param_2[3] = 0x14;
    param_2[10] = 0x14;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x4d] = 0x3c;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x4d] = 0x1e;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x3d] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x17] = 100;
      return;
    }
    param_2[0x17] = 0x50;
    param_2[0x3d] = 0x14;
    return;
  }
  param_2[0x17] = 0x3c;
  param_2[0x3d] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00517f23
// Address: 00517f23
// [HELPER] s_Setting_up_as_Assyrians_: "Setting up as Assyrians."
void __thiscall FUN_00517f23(AIModule *param_1,int param_2,int param_3)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Assyrians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      *(undefined4 *)(param_2 + 0x88) = 100;
      return;
    }
    *(undefined4 *)(param_2 + 0xc) = 10;
    *(undefined4 *)(param_2 + 0x1c) = 10;
    *(undefined4 *)(param_2 + 0x24) = 10;
    *(undefined4 *)(param_2 + 0x28) = 10;
    *(undefined4 *)(param_2 + 0x50) = 10;
    *(undefined4 *)(param_2 + 0x120) = 0x50;
    *(undefined4 *)(param_2 + 0x124) = 0x50;
    *(undefined4 *)(param_2 + 0x128) = 0x50;
    *(undefined4 *)(param_2 + 0x40) = 0x28;
    *(undefined4 *)(param_2 + 0x2c) = 0x28;
    *(undefined4 *)(param_2 + 0x18) = 0x14;
    *(undefined4 *)(param_2 + 0x4c) = 0x14;
    *(undefined4 *)(param_2 + 0xa0) = 100;
    *(undefined4 *)(param_2 + 0xa4) = 100;
    if ((param_3 == 0) || (param_3 == 1)) {
      *(undefined4 *)(param_2 + 300) = 100;
      *(undefined4 *)(param_2 + 0x130) = 100;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      *(undefined4 *)(param_2 + 300) = 0x32;
      *(undefined4 *)(param_2 + 0x130) = 0x32;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    *(undefined4 *)(param_2 + 0xf0) = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      *(undefined4 *)(param_2 + 0x58) = 100;
      return;
    }
    *(undefined4 *)(param_2 + 0x58) = 0x50;
    *(undefined4 *)(param_2 + 0xf0) = 0x14;
    return;
  }
  *(undefined4 *)(param_2 + 0x58) = 0x3c;
  *(undefined4 *)(param_2 + 0xf0) = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518081
// Address: 00518081
// [HELPER] s_Setting_up_as_Minoans_: "Setting up as Minoans."
void __thiscall FUN_00518081(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Minoans_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      param_2[0x25] = 100;
      return;
    }
    param_2[4] = 10;
    param_2[6] = 10;
    param_2[9] = 10;
    param_2[10] = 10;
    param_2[0xb] = 10;
    *param_2 = 0x3c;
    param_2[1] = 0x50;
    param_2[3] = 0x14;
    param_2[0x33] = 100;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x58] = 200;
      param_2[0x59] = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x58] = 100;
      param_2[0x59] = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x42] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x1c] = 100;
      return;
    }
    param_2[0x1c] = 0x50;
    param_2[0x42] = 0x14;
    return;
  }
  param_2[0x1c] = 0x3c;
  param_2[0x42] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_005181bb
// Address: 005181bb
// [HELPER] s_Setting_up_as_Hittites_: "Setting up as Hittites."
void __thiscall FUN_005181bb(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Hittites_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_2[4] = 0x28;
    param_2[0x12] = 0x28;
    param_2[0x10] = 0x50;
    param_2[0x31] = 100;
    param_2[0x32] = 100;
    param_2[3] = 0x1e;
    param_2[6] = 0x14;
    param_2[9] = 10;
    param_2[10] = 10;
    param_2[0xb] = 10;
    param_2[0x11] = 0x14;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x57] = 0xa0;
      *param_2 = 0x14;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x57] = 0x50;
      *param_2 = 10;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x41] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x1b] = 100;
      return;
    }
    param_2[0x1b] = 0x50;
    param_2[0x41] = 0x14;
    return;
  }
  param_2[0x1b] = 0x3c;
  param_2[0x41] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_005183f3
// Address: 005183f3
// [HELPER] s_Setting_up_as_Sumerians_: "Setting up as Sumerians."
void __thiscall FUN_005183f3(AIModule *param_1,int param_2,int param_3)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Sumerians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      *(undefined4 *)(param_2 + 0x98) = 100;
      return;
    }
    *(undefined4 *)(param_2 + 0xc) = 10;
    *(undefined4 *)(param_2 + 0x24) = 10;
    *(undefined4 *)(param_2 + 0x28) = 10;
    *(undefined4 *)(param_2 + 0x2c) = 10;
    *(undefined4 *)(param_2 + 0x10) = 0x14;
    *(undefined4 *)(param_2 + 0x44) = 0x14;
    *(undefined4 *)(param_2 + 0x40) = 0x1e;
    *(undefined4 *)(param_2 + 0xe4) = 100;
    *(undefined4 *)(param_2 + 0xe8) = 100;
    if ((param_3 == 0) || (param_3 == 1)) {
      *(undefined4 *)(param_2 + 0x178) = 200;
      *(undefined4 *)(param_2 + 0x17c) = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      *(undefined4 *)(param_2 + 0x178) = 100;
      *(undefined4 *)(param_2 + 0x17c) = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    *(undefined4 *)(param_2 + 0x118) = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      *(undefined4 *)(param_2 + 0x80) = 100;
      return;
    }
    *(undefined4 *)(param_2 + 0x80) = 0x50;
    *(undefined4 *)(param_2 + 0x118) = 0x14;
    return;
  }
  *(undefined4 *)(param_2 + 0x80) = 0x3c;
  *(undefined4 *)(param_2 + 0x118) = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518535
// Address: 00518535
// [HELPER] s_Setting_up_as_Persians_: "Setting up as Persians."
void __thiscall FUN_00518535(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Persians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_2[6] = 10;
    param_2[9] = 10;
    param_2[10] = 10;
    param_2[0x11] = 0x3c;
    param_2[0x12] = 0x3c;
    param_2[1] = 0x28;
    param_2[0xb] = 0x28;
    param_2[0x14] = 0x28;
    *param_2 = 0x14;
    param_2[0x10] = 0x14;
    param_2[7] = 0x32;
    param_2[0x13] = 0x14;
    param_2[0x34] = 100;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x5a] = 200;
      param_2[0x5b] = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x5a] = 100;
      param_2[0x5b] = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x43] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x1d] = 100;
      return;
    }
    param_2[0x1d] = 0x50;
    param_2[0x43] = 0x14;
    return;
  }
  param_2[0x1d] = 0x3c;
  param_2[0x43] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518668
// Address: 00518668
// [HELPER] s_Setting_up_as_Shang_: "Setting up as Shang."
void __thiscall FUN_00518668(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Shang_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    *param_2 = 10;
    param_2[3] = 10;
    param_2[9] = 10;
    param_2[10] = 10;
    param_2[6] = 0x32;
    param_2[7] = 0x32;
    param_2[0x38] = 0x32;
    param_2[0xb] = 0x1e;
    param_2[0x14] = 0x1e;
    param_2[1] = 0x14;
    param_2[0x10] = 0x14;
    param_2[0x13] = 0x14;
    param_2[0x36] = 100;
    param_2[0x37] = 100;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x5d] = 0xa0;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x5d] = 0x50;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x45] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x1f] = 100;
      return;
    }
    param_2[0x1f] = 0x50;
    param_2[0x45] = 0x14;
    return;
  }
  param_2[0x1f] = 0x3c;
  param_2[0x45] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518794
// Address: 00518794
// [HELPER] s_Setting_up_as_Yamato_: "Setting up as Yamato."
void __thiscall FUN_00518794(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Yamato_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      param_2[0x27] = 100;
      return;
    }
    param_2[3] = 10;
    param_2[4] = 10;
    param_2[9] = 10;
    param_2[10] = 10;
    param_2[6] = 0x32;
    param_2[7] = 0x32;
    *param_2 = 0x14;
    param_2[1] = 0x14;
    param_2[0x10] = 0x28;
    param_2[0xb] = 0x14;
    param_2[0x3b] = 100;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x60] = 200;
      param_2[0x61] = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x60] = 100;
      param_2[0x61] = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x47] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x21] = 100;
      return;
    }
    param_2[0x21] = 0x50;
    param_2[0x47] = 0x14;
    return;
  }
  param_2[0x21] = 0x3c;
  param_2[0x47] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_005188e3
// Address: 005188e3
// [HELPER] s_Setting_up_as_Choson_: "Setting up as Choson."
void __thiscall FUN_005188e3(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Choson_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_2[1] = 10;
    param_2[0x10] = 10;
    param_2[3] = 10;
    param_2[7] = 0x1e;
    param_2[9] = 0x1e;
    param_2[10] = 0x1e;
    *param_2 = 0x14;
    param_2[6] = 0x14;
    param_2[0xb] = 0x46;
    param_2[0x13] = 0x32;
    param_2[0x14] = 0x5a;
    param_2[0x2c] = 100;
    param_2[0x2d] = 100;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x4e] = 200;
      param_2[0x4f] = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x4e] = 100;
      param_2[0x4f] = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x3e] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x18] = 100;
      return;
    }
    param_2[0x18] = 0x50;
    param_2[0x3e] = 0x14;
    return;
  }
  param_2[0x18] = 0x3c;
  param_2[0x3e] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518a1a
// Address: 00518a1a
// [HELPER] s_Setting_up_as_Roman_: "Setting up as Roman."
void __thiscall FUN_00518a1a(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Roman_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    *param_2 = 10;
    param_2[6] = 10;
    param_2[9] = 10;
    param_2[10] = 10;
    param_2[0x13] = 10;
    param_2[0x14] = 10;
    param_2[3] = 0x14;
    param_2[4] = 0x14;
    param_2[0xb] = 0x50;
    param_2[0x70] = 100;
    param_2[0x71] = 0x3c;
    param_2[0x72] = 0x50;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x73] = 200;
      param_2[0x74] = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x73] = 100;
      param_2[0x74] = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x7c] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x78] = 100;
      return;
    }
    param_2[0x78] = 0x50;
    param_2[0x7c] = 0x14;
    return;
  }
  param_2[0x78] = 0x3c;
  param_2[0x7c] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518b4f
// Address: 00518b4f
// [HELPER] s_Setting_up_as_Carthaginian_: "Setting up as Carthaginian."
void __thiscall FUN_00518b4f(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Carthaginian_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    *param_2 = 10;
    param_2[1] = 10;
    param_2[0x10] = 10;
    param_2[7] = 10;
    param_2[9] = 10;
    param_2[10] = 10;
    param_2[0xb] = 10;
    param_2[0x11] = 0x3c;
    param_2[0x12] = 0x3c;
    param_2[3] = 0x46;
    param_2[0x62] = 0x50;
    param_2[99] = 0x50;
    param_2[4] = 0x32;
    param_2[6] = 0x1e;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[100] = 200;
      param_2[0x65] = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[100] = 100;
      param_2[0x65] = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x79] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x75] = 100;
      return;
    }
    param_2[0x75] = 0x50;
    param_2[0x79] = 0x14;
    return;
  }
  param_2[0x75] = 0x3c;
  param_2[0x79] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518c83
// Address: 00518c83
// [HELPER] s_Setting_up_as_Palmyran_: "Setting up as Palmyran."
void __thiscall FUN_00518c83(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Palmyran_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_2[3] = 0x28;
    param_2[6] = 0x28;
    *param_2 = 0x1e;
    param_2[7] = 10;
    param_2[9] = 10;
    param_2[10] = 10;
    param_2[0xb] = 10;
    param_2[1] = 0x1e;
    param_2[0x6b] = 0x50;
    param_2[0x6c] = 0x50;
    param_2[0x6d] = 0x50;
    param_2[0x10] = 0x3c;
    param_2[4] = 0x14;
    param_2[0x11] = 0x3c;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x6e] = 200;
      param_2[0x6f] = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x6e] = 100;
      param_2[0x6f] = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x7b] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x77] = 100;
      return;
    }
    param_2[0x77] = 0x50;
    param_2[0x7b] = 0x14;
    return;
  }
  param_2[0x77] = 0x3c;
  param_2[0x7b] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518dcb
// Address: 00518dcb
// [HELPER] s_Setting_up_as_Macedonian_: "Setting up as Macedonian."
void __thiscall FUN_00518dcb(AIModule *param_1,undefined4 *param_2,int param_3)
{
  uchar uVar1;
  
  AIModule::logCommonHistory
            (param_1,*(char **)(param_1[2].playerNameValue + 8),s_Setting_up_as_Macedonian_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_2[3] = 0x28;
    param_2[4] = 0x28;
    *param_2 = 10;
    param_2[6] = 0x1e;
    param_2[7] = 0x1e;
    param_2[0x11] = 0x1e;
    param_2[0x68] = 0x50;
    param_2[0x66] = 0x50;
    param_2[0x67] = 0x50;
    param_2[1] = 10;
    param_2[0x10] = 0x14;
    if ((param_3 == 0) || (param_3 == 1)) {
      param_2[0x69] = 200;
      param_2[0x6a] = 200;
    }
    else if ((((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) || (param_3 == 5)) {
      param_2[0x69] = 100;
      param_2[0x6a] = 100;
      return;
    }
    return;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    param_2[0x7a] = 100;
    return;
  }
  if ((param_3 != 2) && (param_3 != 6)) {
    if ((param_3 != 5) && (param_3 != 8)) {
      param_2[0x76] = 100;
      return;
    }
    param_2[0x76] = 0x50;
    param_2[0x7a] = 0x14;
    return;
  }
  param_2[0x76] = 0x3c;
  param_2[0x7a] = 0x28;
  return;
}

// --------------------------------------------------

// Function: FUN_00518efd
// Address: 00518efd
// [HELPER] s_Build_AI__last__s__last2__s__Pro: "Build AI: last=%s, last2=%s, Progress=%d/%d.\n"
// [HELPER] s_Civilians__Total__d__Exp__d__d__: "Civilians: Total=%d, Exp(%d/%d), Gat(%d/%d).  NRes:%d%d%d%d.\n"
// [HELPER] s_Number_Soldiers__d__: "Number Soldiers=%d.\n"
// [HELPER] s_Player__d__: "Player %d:\n"
// [HELPER] s___Build_List________s__: "  Build List:      %s.\n"
// [HELPER] s___City_Plan_________s__: "  City Plan:       %s.\n"
// [HELPER] s___Computer_Player___s__: "  Computer Player, %s.\n"
// [HELPER] s___Exploration_______d__: "  Exploration:     %d.\n"
// [HELPER] s___Food______________d__: "  Food:            %d.\n"
// [HELPER] s___Gold______________d__: "  Gold:            %d.\n"
// [HELPER] s___Human_Player___s__: "  Human Player, %s.\n"
// [HELPER] s___Kill_Ratio________d__: "  Kill Ratio:      %d.\n"
// [HELPER] s___Kills_____________d__: "  Kills:           %d.\n"
// [HELPER] s___Points__: "  Points:\n"
// [HELPER] s___Population________d__: "  Population:      %d.\n"
// [HELPER] s___Razings___________d__: "  Razings:         %d.\n"
// [HELPER] s___Stone_____________d__: "  Stone:           %d.\n"
// [HELPER] s___Technology________d__: "  Technology:      %d.\n"
// [HELPER] s___VC_File___________s__: "  VC File:         %s.\n"
// [HELPER] s___Wood______________d__: "  Wood:            %d.\n"
// [HELPER] s_____Combat__________d__: "    Combat         %d.\n"
// [HELPER] s_____Economy_________d__: "    Economy        %d.\n"
// [HELPER] s_____Religion________d__: "    Religion       %d.\n"
// [HELPER] s_____Science_________d__: "    Science        %d.\n"
// [HELPER] s_____Survival________d__: "    Survival       %d.\n"
// [HELPER] s_____Wonder__________d__: "    Wonder         %d.\n"
// [HELPER] s_______Total_________d__: "      Total:       %d.\n"
void __thiscall FUN_00518efd(int param_1,int param_2,int param_3)
{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char acStack_100 [256];
  
  if (param_2 != 0) {
    fprintf(param_2,s_Player__d__,(int)*(short *)(param_1 + 0x4a));
    if (param_3 == 1) {
      (**(code **)(rge_base_game->_padding_ + 0x20))
                (*(byte *)(param_1 + 0x105) + 0x27f6,acStack_100,0x100);
      if (*(int *)(param_1 + 0x238) == 0) {
        pcVar5 = acStack_100;
        pcVar9 = s___Human_Player___s__;
      }
      else {
        fprintf(param_2,s___Computer_Player___s__,acStack_100);
        pcVar5 = BuildAIModule::buildListName((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
        fprintf(param_2,s___Build_List________s__,pcVar5);
        pcVar5 = ConstructionAIModule::constructionPlanName
                           ((ConstructionAIModule *)(*(int *)(param_1 + 0x238) + 0x6c4));
        fprintf(param_2,s___City_Plan_________s__,pcVar5);
        pcVar5 = TribeStrategyAIModule::ruleSetName
                           ((TribeStrategyAIModule *)(*(int *)(param_1 + 0x238) + 0x10e74));
        pcVar9 = s___VC_File___________s__;
      }
      fprintf(param_2,pcVar9,pcVar5);
    }
    fprintf(param_2,s___Points__);
    lVar1 = RGE_Victory_Conditions::get_victory_points_group
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\0');
    fprintf(param_2,s_____Combat__________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_group
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\x01');
    fprintf(param_2,s_____Economy_________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_group
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\x02');
    fprintf(param_2,s_____Religion________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_group
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\x03');
    fprintf(param_2,s_____Science_________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_id
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\x16');
    fprintf(param_2,s_____Survival________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_id
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\x17');
    fprintf(param_2,s_____Wonder__________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points(*(RGE_Victory_Conditions **)(param_1 + 0x34))
    ;
    fprintf(param_2,s_______Total_________d__,lVar1);
    uVar2 = __ftol();
    fprintf(param_2,s___Population________d__,uVar2);
    lVar1 = RGE_Victory_Conditions::get_attribute_id
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\0');
    fprintf(param_2,s___Kills_____________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_attribute_id
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\x02');
    fprintf(param_2,s___Kill_Ratio________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_attribute_id
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\x01');
    fprintf(param_2,s___Razings___________d__,lVar1);
    uVar2 = __ftol();
    fprintf(param_2,s___Food______________d__,uVar2);
    uVar2 = __ftol();
    fprintf(param_2,s___Gold______________d__,uVar2);
    uVar2 = __ftol();
    fprintf(param_2,s___Stone_____________d__,uVar2);
    uVar2 = __ftol();
    fprintf(param_2,s___Wood______________d__,uVar2);
    lVar1 = RGE_Victory_Conditions::get_attribute_id
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\x11');
    fprintf(param_2,s___Technology________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_attribute_id
                      (*(RGE_Victory_Conditions **)(param_1 + 0x34),'\a');
    fprintf(param_2,s___Exploration_______d__,lVar1);
    if (*(int *)(param_1 + 0x238) != 0) {
      iVar3 = BuildAIModule::buildListLength((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
      iVar4 = BuildAIModule::numberItemsIntoBuildList
                        ((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
      pcVar5 = BuildAIModule::lastBuildItemRequested
                         ((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
      pcVar9 = BuildAIModule::currentBuildItemRequested
                         ((BuildAIModule *)(*(int *)(param_1 + 0x238) + 0x104));
      fprintf(param_2,s_Build_AI__last__s__last2__s__Pro,pcVar9,pcVar5,iVar4,iVar3);
      TribeTacticalAIModule::neededResource
                ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),3);
      TribeTacticalAIModule::neededResource
                ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),2);
      TribeTacticalAIModule::neededResource
                ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),1);
      TribeTacticalAIModule::neededResource
                ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),0);
      iVar3 = TribeTacticalAIModule::desiredNumberGatherers
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c));
      iVar4 = TribeTacticalAIModule::numberGatherers
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c));
      iVar6 = TribeTacticalAIModule::desiredNumberCivilianExplorers
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c));
      iVar7 = TribeTacticalAIModule::numberCivilianExplorers
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c));
      iVar8 = TribeTacticalAIModule::numberCivilians
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c));
      fprintf(param_2,s_Civilians__Total__d__Exp__d__d__,iVar8,iVar7,iVar6,iVar4,iVar3);
      iVar3 = TribeTacticalAIModule::numberSoldiers
                        ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c));
      fprintf(param_2,s_Number_Soldiers__d__,iVar3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005192e2
// Address: 005192e2
void __thiscall FUN_005192e2(int param_1,int param_2,int param_3,int param_4)
{
  if (*(int *)(param_1 + 0x238) != 0) {
    TribeTacticalAIModule::trackUnitGather
              ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x238) + 0x1146c),param_2,param_3,
               param_4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00519317
// Address: 00519317
// [HELPER] s__3_f__: "%3.f%%"
// [HELPER] s__4_f: "%4.f"
// [HELPER] s__4_f__4_f__4_f: "%4.f/%4.f/%4.f"
// [HELPER] s__5_f: "%5.f"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00519317(int param_1,undefined1 param_2,char *param_3)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  float fVar7;
  
  switch(param_2) {
  case 0:
    uVar3 = 0xffffffff;
    pcVar5 = *(char **)(param_1 + 0x44);
    do {
      pcVar6 = pcVar5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar5 = pcVar6 + -uVar3;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)param_3 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      param_3 = param_3 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_3 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      param_3 = param_3 + 1;
    }
    return;
  case 1:
    fVar7 = *(float *)(*(int *)(param_1 + 0x50) + 0x4c) -
            *(float *)(*(int *)(param_1 + 0x50) + 0x2c);
    break;
  case 2:
    sprintf(param_3,s__4_f,(double)*(float *)(*(int *)(param_1 + 0x50) + 0x50));
    return;
  case 3:
    sprintf(param_3,s__4_f,(double)*(float *)(*(int *)(param_1 + 0x50) + 0x2c));
    return;
  case 4:
    sprintf(param_3,s__5_f,(double)*(float *)(*(int *)(param_1 + 0x50) + 0xc));
    return;
  case 5:
    fVar7 = RGE_Visible_Map::percentExplored(*(RGE_Visible_Map **)(param_1 + 0x38));
    sprintf(param_3,s__3_f__,(double)(fVar7 * _DAT_0057682c));
    return;
  case 6:
    fVar7 = *(float *)(*(int *)(param_1 + 0x50) + 0x4c);
    break;
  case 7:
    iVar2 = *(int *)(param_1 + 0x50);
    sprintf(param_3,s__4_f__4_f__4_f,(double)*(float *)(iVar2 + 0x1c),
            (double)*(float *)(iVar2 + 0x34),(double)*(float *)(iVar2 + 0x38));
    return;
  case 8:
    fVar7 = *(float *)(*(int *)(param_1 + 0x50) + 0x54);
    break;
  default:
    goto switchD_00519334_default;
  }
  sprintf(param_3,s__4_f,(double)fVar7);
switchD_00519334_default:
  return;
}

// --------------------------------------------------

// Function: FUN_00519465
// Address: 00519465
void __fastcall FUN_00519465(undefined4 param_1,int param_2)
{
  int in_EAX;
  char cVar1;
  char cVar3;
  int unaff_EBX;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  undefined4 uVar2;
  
  uStack_4 = param_1;
  *(char *)(in_EAX + -0x6d) = *(char *)(in_EAX + -0x6d) + (char)((uint)param_2 >> 8);
  uStack_8 = param_1;
  *(char *)(unaff_EBX + -0x49ffae6d) = *(char *)(unaff_EBX + -0x49ffae6d) + (char)param_2;
  uStack_c = param_1;
  cVar3 = (char)in_EAX;
  cVar1 = (char)param_1 + cVar3;
  uVar2 = CONCAT31((int3)((uint)param_1 >> 8),cVar1);
  uStack_10 = uVar2;
  *(char *)(&uStack_10 + param_2) = *(char *)(&uStack_10 + param_2) + cVar3;
  uStack_14 = uVar2;
  *(char *)(&uStack_14 + param_2) = *(char *)(&uStack_14 + param_2) + cVar1;
  *(char *)(param_2 + -0x6c) = *(char *)(param_2 + -0x6c) + cVar3;
  *(char *)(in_EAX + 0x6a909090) = *(char *)(in_EAX + 0x6a909090) + (char)param_2;
                    /* WARNING: Could not recover jumptable at 0x00519491. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_EAX + -0x65))(uVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_005194f3
// Address: 005194f3
void __fastcall FUN_005194f3(RGE_Player *param_1)
{
  TRIBE_Victory_Conditions *this;
  RGE_Victory_Conditions *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005612bb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Victory_Conditions *)operator_new(0x20);
  uStack_4 = 0;
  if (this != (TRIBE_Victory_Conditions *)0x0) {
    pRVar1 = (RGE_Victory_Conditions *)
             TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(this,param_1);
    param_1->victory_conditions = pRVar1;
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  param_1->victory_conditions = (RGE_Victory_Conditions *)0x0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00519563
// Address: 00519563
void __thiscall FUN_00519563(RGE_Player *param_1,short param_2,float param_3,uchar param_4)
{
  if ((param_2 == 3) && (param_4 != '\0')) {
    param_1->attributes[0x31] = param_3 + param_1->attributes[0x31];
  }
  if (param_2 == 0x32) {
    param_1->allied_LOS_Enable = 1;
    RGE_Game_World::update_mutual_allies(param_1->world);
  }
  RGE_Player::add_attribute_num(param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_005195c6
// Address: 005195c6
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005195c6(int param_1)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  DAT_0086bc8c = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  if (*(short *)(param_1 + 0x19c) != 0) {
    iVar5 = 0;
    piVar3 = (int *)(param_1 + 0x134);
    do {
      if (*(short *)(param_1 + 0x19c) <= iVar5) {
        return;
      }
      iVar2 = *piVar3;
      if (iVar2 != 0) {
        if (*(short *)(*(int *)(iVar2 + 0xc) + 0x4a) == *(short *)(param_1 + 0x4a)) {
          iVar2 = (int)*(short *)(*(int *)(iVar2 + 8) + 0x14);
          if ((-1 < iVar2) && (iVar2 < tribe_group_properties_num)) {
            if (iVar2 == 0x12) {
              *(uint *)(param_1 + 0x198) = *(uint *)(param_1 + 0x198) | 0x16;
              DAT_0086bc8c = DAT_0086bc8c + 1;
              DAT_0086bc88 = *(undefined4 *)(*piVar3 + 4);
              if (_DAT_0057682c <= *(float *)(*piVar3 + 0x44)) {
                *(uint *)(param_1 + 0x198) = *(uint *)(param_1 + 0x198) | 0x80;
              }
            }
            else {
              *(uint *)(param_1 + 0x198) =
                   *(uint *)(param_1 + 0x198) | (uint)(&tribe_group_properties)[iVar2];
            }
          }
          sVar1 = *(short *)(*(int *)(*piVar3 + 8) + 0x10);
          if ((((sVar1 == 0x4f) || (sVar1 == 199)) || (sVar1 == 0x45)) || (sVar1 == 0x116)) {
            *(uint *)(param_1 + 0x198) = *(uint *)(param_1 + 0x198) | 1;
          }
        }
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < 0x19);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005196da
// Address: 005196da
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005196da(int *param_1,int param_2,int *param_3,int *param_4)
{
  short sVar1;
  short sVar2;
  short sVar3;
  RGE_Player *pRVar4;
  RGE_Master_Static_Object *pRVar5;
  bool bVar6;
  RGE_Static_Object *pRVar7;
  int iVar8;
  RGE_Prog_Info *pRVar9;
  RGE_Sprite *pRVar10;
  RGE_Scenario_File_Info *pRVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  RGE_Scenario_File_Info *pRVar15;
  int iStack_1c;
  int iStack_10;
  
  pRVar7 = RGE_Game_World::object((RGE_Game_World *)param_1[0xf],param_2);
  iVar12 = 0;
  *param_3 = 0;
  *param_4 = 0;
  if (pRVar7 != (RGE_Static_Object *)0x0) {
    if (pRVar7->type == '\x19') {
      pRVar4 = pRVar7[1].owner;
      pRVar10 = pRVar7[1].sprite;
      sVar2 = (short)pRVar4->checksum;
      sVar3 = (short)pRVar4->currentUpdatePathingAttemptsValue;
      sVar1 = *(short *)((int)&pRVar4->master_objects + 2);
    }
    else {
      pRVar5 = pRVar7->master_obj;
      sVar2 = pRVar5->object_group;
      pRVar10 = (RGE_Sprite *)(int)pRVar7->owner->id;
      sVar3 = pRVar5->id;
      sVar1 = pRVar5->hp;
    }
    iStack_10 = (int)sVar1;
    iStack_1c = (int)sVar2;
    if ((-1 < (int)pRVar10) && ((int)pRVar10 < (int)*(short *)(param_1[0xf] + 0x3c))) {
      (**(code **)(*param_1 + 0x98))();
      if ((sVar3 == 0x9e) || (sVar3 == 0xa3)) {
        iVar12 = 0x32;
      }
LAB_005197aa:
      pcVar13 = (char *)0x0;
      if (((short)param_1[0x67] == 0) || (param_1[0x66] == 0)) {
        bVar6 = false;
        pRVar15 = rge_base_game[1].scenario_info;
        pRVar9 = rge_base_game[1].prog_info;
      }
      else {
        bVar6 = true;
        pRVar15 = (RGE_Scenario_File_Info *)rge_base_game[1]._padding_;
        pRVar9 = (RGE_Prog_Info *)rge_base_game[1].player_game_info;
      }
      if (((-1 < iStack_1c) && (iStack_1c < (int)pRVar9)) &&
         (*(int *)(pRVar15->filename + iStack_1c * 0x2c) == iStack_1c)) {
        pcVar13 = pRVar15->filename + iStack_1c * 0x2c;
      }
      if (pcVar13 == (char *)0x0) {
        iVar8 = 0;
        pRVar11 = pRVar15;
        if (0 < (int)pRVar9) {
          do {
            if (*(int *)pRVar11->filename == iStack_1c) {
              pcVar13 = pRVar15->filename + iVar8 * 0x2c;
              break;
            }
            iVar8 = iVar8 + 1;
            pRVar11 = (RGE_Scenario_File_Info *)(pRVar11->filename + 0x2c);
          } while (iVar8 < (int)pRVar9);
        }
        if (pcVar13 == (char *)0x0) {
          return 0;
        }
      }
      switch(param_1[(int)((int)&pRVar10->last_time + 2)]) {
      case 0:
        iVar8 = *(int *)(pcVar13 + 0xc);
        iVar14 = *(int *)(pcVar13 + 0x10);
        break;
      case 1:
        iVar8 = *(int *)(pcVar13 + 4);
        iVar14 = *(int *)(pcVar13 + 8);
        break;
      case 2:
        iVar8 = *(int *)(pcVar13 + 0x14);
        iVar14 = *(int *)(pcVar13 + 0x18);
        break;
      case 3:
        iVar8 = *(int *)(pcVar13 + 0x1c);
        iVar14 = *(int *)(pcVar13 + 0x20);
        break;
      case 4:
        iVar8 = *(int *)(pcVar13 + 0x24);
        iVar14 = *(int *)(pcVar13 + 0x28);
        break;
      default:
        iVar8 = -1;
        iVar14 = -1;
      }
      if (iVar8 != -1) {
        do {
          switch(iVar8) {
          case 0:
            goto switchD_0051989c_caseD_0;
          case 1:
          case 8:
            if (((*(byte *)(param_1 + 0x66) & 1) != 0) && (pRVar7->object_state < 3)) {
              *param_3 = 4;
              *param_4 = iVar12 + iVar14;
              goto LAB_005198fc;
            }
            if (iVar8 != 8) goto LAB_005198fc;
            iVar8 = 7;
            break;
          case 2:
            if ((*(byte *)(param_1 + 0x66) & 2) != 0) goto LAB_005199c6;
            goto LAB_005198fc;
          case 3:
            if ((*(byte *)(param_1 + 0x66) & 4) != 0) {
              *param_3 = 5;
              *param_4 = iVar12 + iVar14;
            }
            goto LAB_005198fc;
          case 4:
            if (((*(byte *)(param_1 + 0x66) & 0x10) != 0) &&
               ((((DAT_0086bc8c != 1 || (param_2 != DAT_0086bc88)) && (iVar8 = __ftol(), 0 < iVar8))
                && (iVar8 < iStack_10)))) {
LAB_005199c6:
              *param_3 = 5;
              *param_4 = iVar12 + iVar14;
            }
            goto LAB_005198fc;
          case 5:
            if ((*(byte *)(param_1 + 0x66) & 0x20) != 0) {
              if (pRVar7->object_state == '\0') {
                iVar12 = 0x32;
              }
              iVar8 = __ftol();
              if ((0 < iVar8) && (iVar8 < iStack_10)) {
                *param_3 = 3;
                *param_4 = iVar12 + iVar14;
              }
            }
            goto LAB_005198fc;
          case 6:
          case 9:
            if ((*(byte *)(param_1 + 0x66) & 0x40) != 0) {
              *param_3 = 3;
              *param_4 = iVar12 + iVar14;
              goto LAB_005198fc;
            }
            if (iVar8 != 9) goto LAB_005198fc;
            iVar8 = 1;
            break;
          case 7:
            if ((((*(byte *)(param_1 + 0x66) & 0x80) != 0) &&
                ((iStack_1c != 0x12 || (*(float *)(param_1[0x14] + 0x6c) != _DAT_00576828)))) &&
               ((iStack_1c != 3 ||
                (((*(float *)(param_1[0x14] + 0x70) != _DAT_00576828 && (sVar3 != 0x6d)) &&
                 (sVar3 != 0x114)))))) {
              *param_3 = 5;
              *param_4 = iVar12 + iVar14;
            }
            goto LAB_005198fc;
          default:
            *param_3 = 0;
            *param_4 = 0;
            goto LAB_005198fc;
          }
          iVar12 = 0x32;
        } while( true );
      }
    }
  }
  return 0;
switchD_0051989c_caseD_0:
  *param_3 = 0;
  *param_4 = iVar12 + iVar14;
LAB_005198fc:
  if (!bVar6) {
    return 1;
  }
  if (*param_3 != 0) {
    return 1;
  }
  if (*param_4 != 0) {
    return 1;
  }
  param_1[0x66] = 0;
  goto LAB_005197aa;
}

// --------------------------------------------------

// Function: FUN_00519ab2
// Address: 00519ab2
TRIBE_Player * __fastcall FUN_00519ab2(TRIBE_Player *param_1,undefined4 param_2)
{
  char *pcVar1;
  char cVar3;
  undefined4 in_EAX;
  int iVar2;
  char cVar4;
  char cVar6;
  int unaff_EBX;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_54;
  code *pcStack_50;
  TRIBE_Player *pTStack_4c;
  TRIBE_Player *pTStack_48;
  TRIBE_Player *pTStack_44;
  TRIBE_Player *pTStack_40;
  TRIBE_Player *pTStack_3c;
  TRIBE_Player *pTStack_38;
  TRIBE_Player *pTStack_34;
  TRIBE_Player *pTStack_30;
  TRIBE_Player *pTStack_2c;
  TRIBE_Player *pTStack_28;
  TRIBE_Player *pTStack_24;
  
  iVar2 = (int)(short)in_EAX;
  cVar4 = (char)((uint)param_1 >> 8);
  *(char *)(iVar2 + -0x68) = *(char *)(iVar2 + -0x68) + cVar4;
  *(char *)(iVar2 + -0x68) = *(char *)(iVar2 + -0x68) + (char)((uint)param_2 >> 8);
  cVar6 = (char)((uint)unaff_EBX >> 8);
  *(char *)(iVar2 + -0x68) = *(char *)(iVar2 + -0x68) + cVar6;
  *(char *)(iVar2 + 0x34005198) = *(char *)(iVar2 + 0x34005198) + (char)in_EAX;
  cVar3 = (char)((uint)in_EAX >> 8);
  *(char *)(unaff_EBX + 0x58005198) = *(char *)(unaff_EBX + 0x58005198) + cVar3;
  *(char *)(unaff_EBX + -0x67) = *(char *)(unaff_EBX + -0x67) + cVar3;
  param_1[-0x477c1].aiStatusInformationValue6[0xa5] =
       param_1[-0x477c1].aiStatusInformationValue6[0xa5] + (char)in_EAX;
  iVar5 = CONCAT31((int3)((uint)unaff_EBX >> 8),(char)unaff_EBX + (uchar)param_1);
  pcVar1 = (char *)((iVar2 >> 0x1f) + iVar5 * 4);
  *pcVar1 = *pcVar1 + cVar6;
  pcVar1 = (char *)(iVar5 + -0x34ffae68);
  *pcVar1 = *pcVar1 + cVar3;
  pcVar1 = (char *)((iVar2 >> 0x1f) + -1);
  *pcVar1 = *pcVar1 + cVar4;
  pcStack_50 = FUN_005612d8;
  uStack_54 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_54;
  pTStack_4c = param_1;
  pTStack_48 = param_1;
  pTStack_44 = param_1;
  pTStack_40 = param_1;
  pTStack_3c = param_1;
  pTStack_38 = param_1;
  pTStack_34 = param_1;
  pTStack_30 = param_1;
  pTStack_2c = param_1;
  pTStack_28 = param_1;
  pTStack_24 = param_1;
  TRIBE_Player::TRIBE_Player(param_1,(int)param_1,(TRIBE_World *)param_1,(uchar)param_1);
  pTStack_4c = (TRIBE_Player *)0x0;
  param_1->_padding_ = (int)&TRIBE_Gaia::_vftable_;
  *(undefined1 *)&param_1->_padding_ = 2;
  rge_read((int)param_1,param_1 + 1,4);
  rge_read((int)param_1,&param_1[1]._padding_,4);
  rge_read((int)param_1,&param_1[1]._padding_,4);
  rge_read((int)param_1,&param_1[1]._padding_,4);
  *unaff_FS_OFFSET = uStack_54;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00519b93
// Address: 00519b93
TRIBE_Gaia * __thiscall FUN_00519b93(TRIBE_Gaia *param_1,byte param_2)
{
  TRIBE_Gaia::~TRIBE_Gaia(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00519bc5
// Address: 00519bc5
TRIBE_Player * __thiscall
FUN_00519bc5(TRIBE_Player *param_1,TRIBE_World *param_2,RGE_Master_Player *param_3,uchar param_4,
            char *param_5,uchar param_6)
{
  TRIBE_Player::TRIBE_Player
            (param_1,param_2,param_3,param_4,param_5,param_6,'\0','\x01',(char *)0x0,(char *)0x0,
             (char *)0x0);
  param_1->_padding_ = (int)&TRIBE_Gaia::_vftable_;
  *(undefined1 *)&param_1->_padding_ = 2;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0x1d;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00519c35
// Address: 00519c35
void __thiscall FUN_00519c35(TRIBE_Player *param_1,int param_2)
{
  TRIBE_Player::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,4);
  return;
}

// --------------------------------------------------

// Function: FUN_00519c9b
// Address: 00519c9b
// [HELPER] groups_used: "00000000"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00519c9b(RGE_Player *param_1)
{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = _DAT_00576824;
  fVar1 = param_1->world->world_time_delta_seconds + *(float *)(param_1[3].groups_used + 0x4a);
  *(float *)(param_1[3].groups_used + 0x4a) = fVar1;
  if (fVar2 < fVar1) {
    do {
      fVar1 = *(float *)(param_1[3].groups_used + 0x4a) - _DAT_00576824;
      iVar3 = *(int *)(param_1[3].groups_used + 0x4e) + 1;
      *(int *)(param_1[3].groups_used + 0x4e) = iVar3;
      *(float *)(param_1[3].groups_used + 0x4a) = fVar1;
      if (iVar3 == 0x1e) {
        param_1[3].groups_used[0x4e] = '\0';
        param_1[3].groups_used[0x4f] = '\0';
        param_1[3].groups_used[0x50] = '\0';
        param_1[3].groups_used[0x51] = '\0';
      }
    } while (_DAT_00576824 < *(float *)(param_1[3].groups_used + 0x4a));
  }
  RGE_Player::update(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00519d06
// Address: 00519d06
void __thiscall
FUN_00519d06(TRIBE_Player *param_1,int param_2,short param_3,uchar param_4,RGE_Sprite **param_5,
            RGE_Sound **param_6)
{
  TRIBE_Player::load_master_object(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_00519d31
// Address: 00519d31
void FUN_00519d31(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00519d41
// Address: 00519d41
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00519d41(RGE_Player *param_1,int param_2,long *param_3,float param_4)
{
  RGE_Player::scenario_postload(param_1,param_2,param_3,param_4);
  if ((float)_DAT_00576830 < param_1->attributes[0x32]) {
    param_1->allied_LOS_Enable = 1;
    RGE_Game_World::update_mutual_allies(param_1->world);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00519d95
// Address: 00519d95
TButtonPanel * __thiscall
FUN_00519d95(TButtonPanel *param_1,TDrawArea *param_2,TPanel *param_3,TDigital *param_4,
            void *param_5,long param_6,long param_7,int param_8)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005612f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TButtonPanel::TButtonPanel(param_1);
  uStack_4 = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  param_1[1].id2[0] = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = param_8;
  param_1->_padding_ = (int)&TRIBE_Panel_Button::_vftable_;
  lVar1 = TButtonPanel::setup(param_1,param_2,param_3,0,0,0,0,DrawClear,param_4,NotifyAction,-1);
  if (lVar1 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TButtonPanel::set_font(param_1,param_5,param_6,param_7);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00519e6e
// Address: 00519e6e
TRIBE_Panel_Button * __thiscall FUN_00519e6e(TRIBE_Panel_Button *param_1,byte param_2)
{
  TRIBE_Panel_Button::~TRIBE_Panel_Button(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00519e95
// Address: 00519e95
void __thiscall FUN_00519e95(int param_1,int param_2)
{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x2d0) = 0;
    return;
  }
  strncpy(param_1 + 0x2d0,param_2,0x100);
  *(undefined1 *)(param_1 + 0x3cf) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00519ed5
// Address: 00519ed5
undefined4 __thiscall FUN_00519ed5(TPanel *param_1,long param_2,long param_3)
{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = TPanel::is_inside(param_1,param_2,param_3);
  if (iVar3 == 0) {
    return 0;
  }
  cVar1 = (char)param_1[2].error_code;
  if (((cVar1 == '\x02') || (cVar1 == '\x03')) &&
     (piVar2 = *(int **)&param_1->parent_panel[4].mouse_action, piVar2 != (int *)0x0)) {
    iVar3 = (**(code **)(*piVar2 + 0xbc))(param_2,param_3);
    if (iVar3 != 0) {
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00519f3a
// Address: 00519f3a
// [HELPER] s__d: "%d"
// [HELPER] s_tpnl_btn__draw2: "tpnl_btn::draw2"
// [HELPER] s_tpnl_btn__draw3: "tpnl_btn::draw3"
// [HELPER] s_tpnl_btn__draw: "tpnl_btn::draw"
// [HELPER] s_tpnl_inv__draw2: "tpnl_inv::draw2"
void __fastcall FUN_00519f3a(TButtonPanel *param_1)
{
  int *piVar1;
  char cVar2;
  uchar *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  RGE_Player *pRVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  char *pcVar16;
  bool bVar17;
  TDrawArea *pTVar18;
  int iStack_2c;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  char acStack_14 [20];
  
  if ((char)param_1[1]._padding_ == '\x03') {
    TButtonPanel::draw(param_1);
    return;
  }
  if (((param_1->_padding_ == 0) || (param_1->_padding_ == 0)) || (param_1->_padding_ == 0)) {
    param_1->_padding_ = 0;
    return;
  }
  iStack_18 = param_1->_padding_;
  (**(code **)(iStack_18 + 0x28))(0);
  piVar1 = &param_1->_padding_;
  (**(code **)(*(int *)param_1->_padding_ + 0x34))(piVar1);
  cVar2 = (char)param_1[1]._padding_;
  bVar17 = true;
  if (((cVar2 == '\0') || (cVar2 == '\x01')) &&
     ((param_1[1]._padding_ != 0 &&
      (puVar3 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_tpnl_btn__draw,1),
      puVar3 != (uchar *)0x0)))) {
    bVar17 = false;
    TShape::shape_draw((TShape *)param_1[1]._padding_,(TDrawArea *)param_1->_padding_,
                       param_1->_padding_,param_1->_padding_,
                       (uint)(param_1->is_down != 0) + param_1[1]._padding_,'\0',(uchar *)0x0);
    TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_tpnl_btn__draw);
  }
  if (bVar17) {
    (**(code **)(*(int *)param_1->_padding_ + 0x34))(piVar1);
  }
  cVar2 = (char)param_1[1]._padding_;
  if (((cVar2 != '\x01') && (cVar2 != '\x03')) || (param_1->text1[0] == (char *)0x0)) {
    if (((param_1->pic[0] != (TShape *)0x0) && (-1 < param_1->pic_index[0])) &&
       (puVar3 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_tpnl_btn__draw3,1),
       puVar3 != (uchar *)0x0)) {
      cVar2 = (char)param_1[1]._padding_;
      sVar9 = param_1->pic_index[0];
      if (cVar2 == '\0') {
        iVar6 = param_1->_padding_;
        if (param_1->is_down == 0) {
          iVar14 = param_1->_padding_ + 2;
          TDrawArea::SetClipRect
                    ((TDrawArea *)param_1->_padding_,*piVar1 + 2,param_1->_padding_ + 2,
                     param_1->_padding_ + -2,param_1->_padding_ + -2);
          iVar10 = iVar6 + 2;
        }
        else {
          iVar14 = param_1->_padding_ + 3;
          TDrawArea::SetClipRect
                    ((TDrawArea *)param_1->_padding_,*piVar1 + 3,param_1->_padding_ + 3,
                     param_1->_padding_ + -2,param_1->_padding_ + -3);
          iVar10 = iVar6 + 3;
        }
      }
      else {
        iVar6 = param_1->_padding_;
        if (cVar2 == '\x01') {
          iVar15 = param_1->_padding_;
          iVar14 = iVar15 + 1;
          TDrawArea::SetClipRect
                    ((TDrawArea *)param_1->_padding_,*piVar1 + 1,param_1->_padding_ + 1,
                     param_1->_padding_ + -1,param_1->_padding_ + -1);
          iVar10 = iVar6 + 1;
          if (param_1->is_down != 0) {
            iVar14 = iVar15 + 2;
            iVar10 = iVar6 + 2;
          }
        }
        else {
          iVar14 = param_1->_padding_;
          iVar10 = iVar6;
          if (param_1->is_down != 0) {
            sVar9 = sVar9 + 1;
          }
        }
      }
      if (param_1->disabled != 0) {
        fog_next_shape = 1;
        _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
      }
      bVar17 = param_1[1]._padding_ == 0;
      if (bVar17) {
        pTVar18 = (TDrawArea *)param_1->_padding_;
        puVar3 = (uchar *)0x0;
      }
      else {
        pRVar8 = RGE_Base_Game::get_player(rge_base_game);
        _ASMSet_Color_Xform((pRVar8->color_table->id + 1) * 0x10);
        puVar3 = (uchar *)param_1[1]._padding_;
        pTVar18 = (TDrawArea *)param_1->_padding_;
      }
      TShape::shape_draw(param_1->pic[0],pTVar18,iVar10,iVar14,(int)sVar9,!bVar17,puVar3);
      if (param_1->disabled != 0) {
        fog_next_shape = 0;
      }
      TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_tpnl_btn__draw3);
    }
    goto LAB_0051a46c;
  }
  pvVar4 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_tpnl_btn__draw);
  if (pvVar4 == (void *)0x0) goto LAB_0051a46c;
  SelectClipRgn(pvVar4,param_1->_padding_);
  uVar5 = SelectObject(pvVar4,param_1->font);
  SetBkMode(pvVar4,1);
  iVar6 = param_1->_padding_ / 2;
  pcVar12 = param_1->text1[param_1->cur_state];
  iVar14 = param_1->_padding_ / 2;
  if (pcVar12 == (char *)0x0) {
    pcVar12 = param_1->text1[0];
  }
  if (pcVar12 != (char *)0x0) {
    iVar10 = -1;
    pcVar16 = pcVar12;
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      cVar2 = *pcVar16;
      pcVar16 = pcVar16 + 1;
    } while (cVar2 != '\0');
    iVar10 = (int)(short)(~(ushort)iVar10 - 1);
    GetTextExtentPoint32A(pvVar4,pcVar12,iVar10,&iStack_1c);
    iVar15 = (iVar14 - iStack_1c / 2) + param_1->_padding_;
    if (param_1->text2[param_1->cur_state] == (char *)0x0) {
      iVar7 = (iVar6 - param_1->font_hgt / 2) + param_1->_padding_;
    }
    else {
      iVar7 = (iVar6 - param_1->font_hgt) + param_1->_padding_;
    }
    if (param_1->draw_reverse == 0) {
      if (param_1->is_down != 0) {
LAB_0051a150:
        iVar15 = iVar15 + 1;
        iVar7 = iVar7 + 1;
      }
    }
    else if (param_1->is_down == 0) goto LAB_0051a150;
    SetTextColor(pvVar4,param_1->text_color2[param_1->cur_state]);
    TextOutA(pvVar4,iVar15 + -1,iVar7 + 1,pcVar12,iVar10);
    SetTextColor(pvVar4,param_1->text_color1[param_1->cur_state]);
    TextOutA(pvVar4,iVar15,iVar7,pcVar12,iVar10);
    pcVar12 = param_1->text2[param_1->cur_state];
    if (pcVar12 == (char *)0x0) {
      pcVar12 = param_1->text2[0];
    }
    if (pcVar12 != (char *)0x0) {
      iVar10 = -1;
      pcVar16 = pcVar12;
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        cVar2 = *pcVar16;
        pcVar16 = pcVar16 + 1;
      } while (cVar2 != '\0');
      iVar10 = (int)(short)(~(ushort)iVar10 - 1);
      GetTextExtentPoint32A(pvVar4,pcVar12,iVar10,&iStack_1c);
      iStack_2c = (iVar14 - iStack_1c / 2) + param_1->_padding_;
      iVar6 = iVar6 + param_1->_padding_;
      if (param_1->draw_reverse == 0) {
        if (param_1->is_down != 0) {
LAB_0051a237:
          iStack_2c = iStack_2c + 1;
          iVar6 = iVar6 + 1;
        }
      }
      else if (param_1->is_down == 0) goto LAB_0051a237;
      SetTextColor(pvVar4,param_1->text_color2[param_1->cur_state]);
      TextOutA(pvVar4,iStack_2c + -1,iVar6 + 1,pcVar12,iVar10);
      SetTextColor(pvVar4,param_1->text_color1[param_1->cur_state]);
      TextOutA(pvVar4,iStack_2c,iVar6,pcVar12,iVar10);
    }
  }
  SelectObject(pvVar4,uVar5);
  SelectClipRgn(pvVar4,0);
  TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_tpnl_btn__draw);
LAB_0051a46c:
  if (((param_1[1]._padding_ != 0) && (0 < param_1[1]._padding_)) &&
     (pvVar4 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_tpnl_btn__draw2),
     pvVar4 != (void *)0x0)) {
    sprintf(acStack_14,&s__d,param_1[1]._padding_);
    SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_);
    SetBkMode(*(undefined4 *)(param_1->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),0xcccccc);
    uVar13 = (uint)(param_1->is_down != 0);
    uVar11 = 0xffffffff;
    pcVar12 = acStack_14;
    do {
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    TextOutA(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_ + 3 + uVar13,
             param_1->_padding_ + 2 + uVar13,acStack_14,~uVar11 - 1);
    SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),0);
    TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_tpnl_inv__draw2);
  }
  (**(code **)(iStack_20 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0051a565
// Address: 0051a565
void __thiscall FUN_0051a565(int *param_1,int param_2)
{
  param_1[0xae] = param_2;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051a584
// Address: 0051a584
void __thiscall FUN_0051a584(int *param_1,int param_2)
{
  param_1[0xaf] = param_2;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051a5a4
// Address: 0051a5a4
undefined4 __fastcall FUN_0051a5a4(int param_1)
{
  return *(undefined4 *)(param_1 + 700);
}

// --------------------------------------------------

// Function: FUN_0051a5b7
// Address: 0051a5b7
TRIBE_Panel_Inven * __thiscall
FUN_0051a5b7(TRIBE_Panel_Inven *param_1,TDrawArea *param_2,TPanel *param_3,void *param_4,
            TRIBE_Player *param_5)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561318;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel((TPanel *)param_1);
  param_1->font = param_4;
  uStack_4 = 0;
  param_1->save_attr_num = 0;
  param_1->save_attr = (short *)0x0;
  param_1->pics = (TShape *)0x0;
  param_1->idle_time = 0;
  param_1->player = (TRIBE_Player *)0x0;
  param_1->back_color = 0;
  param_1->_padding_ = (int)&TRIBE_Panel_Inven::_vftable_;
  param_1->idle_interval = 500;
  param_1->font_color = 0xffffff;
  lVar1 = TPanel::setup((TPanel *)param_1,param_2,param_3,0,0,0,0,'\0');
  if (lVar1 == 0) {
    param_1->_padding_ = 1;
    *unaff_FS_OFFSET = uStack_c;
    return param_1;
  }
  TRIBE_Panel_Inven::set_player(param_1,param_5);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051a689
// Address: 0051a689
TRIBE_Panel_Inven * __thiscall FUN_0051a689(TRIBE_Panel_Inven *param_1,byte param_2)
{
  TRIBE_Panel_Inven::~TRIBE_Panel_Inven(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051a6ae
// Address: 0051a6ae
void __thiscall FUN_0051a6ae(int *param_1,int param_2,int param_3)
{
  param_1[0x44] = param_2;
  param_1[0x45] = param_3;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051a6ce
// Address: 0051a6ce
void __fastcall FUN_0051a6ce(TPanel *param_1)
{
  TShape *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561338;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Panel_Inven::_vftable_;
  uStack_4 = 0;
  if (param_1[1].pnl_x != 0) {
    free(param_1[1].pnl_x);
    param_1[1].pnl_x = 0;
  }
  this = (TShape *)param_1[1]._padding_;
  if (this != (TShape *)0x0) {
    TShape::~TShape(this);
    operator_delete(this);
    param_1[1]._padding_ = 0;
  }
  TPanel::~TPanel(param_1);
  uStack_4 = 0xffffffff;
  TPanel::~TPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0051a764
// Address: 0051a764
// [HELPER] s__ld: "%ld"
// [HELPER] s_tpnl_inv__draw: "tpnl_inv::draw"
void __fastcall FUN_0051a764(int *param_1)
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iStack_1c;
  int aiStack_18 [6];
  
  if (((param_1[8] != 0) && (param_1[0x1c] != 0)) && (param_1[0x1b] != 0)) {
    if ((int *)param_1[0x10] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x10] + 0x34))(param_1 + 9);
    }
    if (param_1[0x3e] != 0) {
      iVar9 = *param_1;
      aiStack_18[0] = iVar9;
      (**(code **)(iVar9 + 0x28))(0);
      pvVar3 = TDrawArea::GetDc((TDrawArea *)param_1[8],s_tpnl_inv__draw);
      if (pvVar3 != (void *)0x0) {
        uVar4 = SelectObject(*(undefined4 *)(param_1[8] + 0x38),param_1[0x43]);
        SetBkMode(*(undefined4 *)(param_1[8] + 0x38),1);
        iVar1 = param_1[3];
        iVar9 = param_1[4];
        iVar7 = iVar9 + 2;
        uVar5 = __ftol();
        sprintf(aiStack_18,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(param_1[8] + 0x38),param_1[0x45]);
        uVar6 = 0xffffffff;
        iVar9 = iVar9 + 3;
        piVar8 = aiStack_18;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          iVar2 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar2 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),iVar1 + 0x1f,iVar9,aiStack_18,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(param_1[8] + 0x38),param_1[0x44]);
        uVar6 = 0xffffffff;
        piVar8 = aiStack_18;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          iVar2 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar2 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),iVar1 + 0x20,iVar7,aiStack_18,~uVar6 - 1);
        iVar1 = param_1[3];
        uVar5 = __ftol();
        sprintf(aiStack_18,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(param_1[8] + 0x38),param_1[0x45]);
        uVar6 = 0xffffffff;
        piVar8 = aiStack_18;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          iVar2 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar2 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),iVar1 + 0x62,iVar9,aiStack_18,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(param_1[8] + 0x38),param_1[0x44]);
        uVar6 = 0xffffffff;
        piVar8 = aiStack_18;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          iVar2 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar2 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),iVar1 + 99,iVar7,aiStack_18,~uVar6 - 1);
        iVar1 = param_1[3];
        uVar5 = __ftol();
        sprintf(aiStack_18,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(param_1[8] + 0x38),param_1[0x45]);
        uVar6 = 0xffffffff;
        piVar8 = aiStack_18;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          iVar2 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar2 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),iVar1 + 0xa5,iVar9,aiStack_18,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(param_1[8] + 0x38),param_1[0x44]);
        uVar6 = 0xffffffff;
        piVar8 = aiStack_18;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          iVar2 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar2 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),iVar1 + 0xa6,iVar7,aiStack_18,~uVar6 - 1);
        iVar1 = param_1[3];
        uVar5 = __ftol();
        sprintf(aiStack_18,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(param_1[8] + 0x38),param_1[0x45]);
        uVar6 = 0xffffffff;
        piVar8 = aiStack_18;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          iVar2 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar2 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),iVar1 + 0xe8,iVar9,aiStack_18,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(param_1[8] + 0x38),param_1[0x44]);
        uVar6 = 0xffffffff;
        piVar8 = aiStack_18;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          iVar9 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar9 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),iVar1 + 0xe9,iVar7,aiStack_18,~uVar6 - 1);
        SelectObject(*(undefined4 *)(param_1[8] + 0x38),uVar4);
        TDrawArea::ReleaseDc((TDrawArea *)param_1[8],s_tpnl_inv__draw);
        iVar9 = iStack_1c;
      }
      (**(code **)(iVar9 + 0x2c))();
      return;
    }
  }
  param_1[0xe] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0051aacb
// Address: 0051aacb
// [HELPER] s_C__msdev_work_age1_x1_tpnl_inv_c: "C:\msdev\work\age1_x1\tpnl_inv.cpp"
undefined4 __fastcall FUN_0051aacb(TRIBE_Panel_Inven *param_1)
{
  int iVar1;
  short *psVar2;
  bool bVar3;
  short sVar4;
  ulong uVar5;
  short sVar6;
  
  TPanel::handle_idle((TPanel *)param_1);
  iVar1 = rge_base_game->prog_mode;
  if (((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) &&
     (uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_tpnl_inv_c,0xad),
     param_1->idle_interval <= uVar5 - param_1->idle_time)) {
    color_log(0xba,0xba,5);
    sVar6 = 0;
    bVar3 = false;
    if (0 < param_1->save_attr_num) {
      psVar2 = param_1->save_attr;
      do {
        sVar4 = __ftol();
        if (sVar4 != psVar2[sVar6]) {
          bVar3 = true;
          break;
        }
        sVar6 = sVar6 + 1;
      } while (sVar6 < param_1->save_attr_num);
    }
    if (bVar3) {
      color_log(0xba,'\x16',5);
      TRIBE_Panel_Inven::save_info(param_1);
      (**(code **)(param_1->_padding_ + 0x20))(1);
    }
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_tpnl_inv_c,0xc2);
    param_1->idle_time = uVar5;
    color_log(0xba,'_',5);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051abe5
// Address: 0051abe5
void __thiscall FUN_0051abe5(TRIBE_Panel_Inven *param_1,TRIBE_Player *param_2)
{
  param_1->player = param_2;
  TRIBE_Panel_Inven::save_info(param_1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051ac0f
// Address: 0051ac0f
void __fastcall FUN_0051ac0f(int param_1)
{
  short sVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = *(int *)(param_1 + 0x100);
  if (iVar2 != 0) {
    if (*(short *)(param_1 + 0xfc) == *(short *)(*(int *)(param_1 + 0xf8) + 0x4c))
    goto LAB_0051ac6b;
    if (iVar2 != 0) {
      free(iVar2);
      *(undefined4 *)(param_1 + 0x100) = 0;
    }
  }
  sVar1 = *(short *)(*(int *)(param_1 + 0xf8) + 0x4c);
  *(short *)(param_1 + 0xfc) = sVar1;
  uVar4 = calloc((int)sVar1,2);
  *(undefined4 *)(param_1 + 0x100) = uVar4;
LAB_0051ac6b:
  if (0 < *(short *)(param_1 + 0xfc)) {
    do {
      uVar3 = __ftol();
      iVar5 = iVar5 + 1;
      *(undefined2 *)(*(int *)(param_1 + 0x100) + -2 + iVar5 * 2) = uVar3;
    } while (iVar5 < *(short *)(param_1 + 0xfc));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051ac9f
// Address: 0051ac9f
undefined4 __thiscall
FUN_0051ac9f(TPanel *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)
{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *unaff_ESI;
  undefined4 *unaff_retaddr;
  
  if (param_1->active == 0) {
    return 0;
  }
  iVar1 = (**(code **)(param_1->_padding_ + 0xbc))(param_4,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = param_1->pnl_x;
  if (param_4 < iVar1 + 0x37) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string(param_1,0x1d4ee);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return 1;
  }
  if (param_4 < iVar1 + 0x6e) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string(param_1,0x1d4ed);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return 1;
  }
  if (param_4 < iVar1 + 0xa5) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string(param_1,0x1d4ef);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return 1;
  }
  uVar2 = __ftol();
  pcVar3 = TPanel::get_string(param_1,0x1d4f0);
  sprintf(*unaff_ESI,pcVar3,uVar2);
  *unaff_retaddr = 0xffffffff;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0051ade6
// Address: 0051ade6
// [HELPER] s_health_shp: "health.shp"
// [HELPER] s_itemicon_shp: "itemicon.shp"
TRIBE_Panel_Object * __thiscall
FUN_0051ade6(TRIBE_Panel_Object *param_1,TDrawArea *param_2,TPanel *param_3,void *param_4,
            long param_5,long param_6,TShape *param_7,TShape **param_8,TRIBE_Player *param_9)
{
  long lVar1;
  TShape *pTVar2;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056136e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel((TPanel *)param_1);
  param_1->_padding_ = (int)&TRIBE_Panel_Object::_vftable_;
  param_1->font = param_4;
  param_1->font_wid = param_5;
  param_1->font_hgt = param_6;
  param_1->health_pic = (TShape *)0x0;
  param_1->item_pic = (TShape *)0x0;
  param_1->unit_pics = param_7;
  param_1->bldg_pics = param_8;
  param_1->player = (TRIBE_Player *)0x0;
  param_1->game_obj = (RGE_Static_Object *)0x0;
  param_1->idle_time = 0;
  param_1->idle_interval = 500;
  param_1->mode = '\x01';
  param_1->save_obj_type = (RGE_Master_Static_Object *)0x0;
  param_1->save_attr_type = -1;
  param_1->save_attr_amount = 0.0;
  param_1->save_object_state = '\0';
  param_1->save_build_pts = 0.0;
  param_1->save_list = (RGE_Object_Node *)0x0;
  param_1->save_hp = 0.0;
  param_1->save_armor = 0;
  param_1->save_pierce_armor = 0;
  param_1->save_weapon = 0;
  param_1->save_weapon_range = 0.0;
  param_1->save_speed_of_attack = 0.0;
  param_1->save_work_type = 0;
  param_1->save_work_target = 0;
  param_1->save_progress = 0;
  param_1->save_name[0] = '\0';
  param_1->save_facet = '\0';
  param_1->save_angle = 0.0;
  param_1->save_los = 0.0;
  param_1->save_pop = 0;
  param_1->save_max_pop = 0;
  param_1->save_selected_group = '\0';
  param_1->save_owner = (RGE_Player *)0x0;
  param_1->save_have_action = '\0';
  param_1->save_farm_amt = 0;
  piVar4 = param_1->save_score;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  iStack_4 = 0;
  lVar1 = TPanel::setup((TPanel *)param_1,param_2,param_3,0,0,0,0,'\0');
  if (lVar1 == 0) {
    param_1->_padding_ = 1;
  }
  else {
    TRIBE_Panel_Object::set_player(param_1,param_9);
    pTVar2 = (TShape *)operator_new(0x20);
    iStack_4._0_1_ = 1;
    if (pTVar2 == (TShape *)0x0) {
      pTVar2 = (TShape *)0x0;
    }
    else {
      pTVar2 = (TShape *)TShape::TShape(pTVar2,s_health_shp,0xc639);
    }
    iStack_4._0_1_ = 0;
    param_1->health_pic = pTVar2;
    if (pTVar2 != (TShape *)0x0) {
      iVar3 = TShape::is_loaded(pTVar2);
      if (iVar3 == 0) {
        pTVar2 = param_1->health_pic;
        if (pTVar2 != (TShape *)0x0) {
          TShape::~TShape(pTVar2);
          operator_delete(pTVar2);
        }
        param_1->health_pic = (TShape *)0x0;
      }
    }
    pTVar2 = (TShape *)operator_new(0x20);
    iStack_4._0_1_ = 2;
    if (pTVar2 == (TShape *)0x0) {
      pTVar2 = (TShape *)0x0;
    }
    else {
      pTVar2 = (TShape *)TShape::TShape(pTVar2,s_itemicon_shp,0xc62b);
    }
    iStack_4 = (uint)iStack_4._1_3_ << 8;
    param_1->item_pic = pTVar2;
    if (pTVar2 != (TShape *)0x0) {
      iVar3 = TShape::is_loaded(pTVar2);
      if (iVar3 == 0) {
        pTVar2 = param_1->item_pic;
        if (pTVar2 != (TShape *)0x0) {
          TShape::~TShape(pTVar2);
          operator_delete(pTVar2);
        }
        param_1->item_pic = (TShape *)0x0;
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051b044
// Address: 0051b044
TRIBE_Panel_Object * __thiscall FUN_0051b044(TRIBE_Panel_Object *param_1,byte param_2)
{
  TRIBE_Panel_Object::~TRIBE_Panel_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051b06e
// Address: 0051b06e
void __fastcall FUN_0051b06e(TPanel *param_1)
{
  TShape *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561388;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Panel_Object::_vftable_;
  pTVar1 = (TShape *)param_1[1].pnl_x;
  uStack_4 = 0;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    param_1[1].pnl_x = 0;
  }
  pTVar1 = (TShape *)param_1[1].pnl_y;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    param_1[1].pnl_y = 0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0051b104
// Address: 0051b104
void __thiscall FUN_0051b104(TRIBE_Panel_Object *param_1,TRIBE_Player *param_2)
{
  param_1->player = param_2;
  if (param_2 != (TRIBE_Player *)0x0) {
    TRIBE_Panel_Object::set_object(param_1,(RGE_Static_Object *)param_2->_padding_);
    return;
  }
  TRIBE_Panel_Object::set_object(param_1,(RGE_Static_Object *)0x0);
  return;
}

// --------------------------------------------------

// Function: FUN_0051b137
// Address: 0051b137
void __thiscall FUN_0051b137(TRIBE_Panel_Object *param_1,RGE_Static_Object *param_2)
{
  param_1->game_obj = param_2;
  TRIBE_Panel_Object::save_object_info(param_1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051b15f
// Address: 0051b15f
void __thiscall FUN_0051b15f(TRIBE_Panel_Object *param_1,uchar param_2)
{
  param_1->mode = param_2;
  TRIBE_Panel_Object::save_object_info(param_1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051b17f
// Address: 0051b17f
undefined1 __fastcall FUN_0051b17f(int param_1)
{
  return *(undefined1 *)(param_1 + 0x120);
}

// --------------------------------------------------

// Function: FUN_0051b187
// Address: 0051b187
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s__d__s: "%d-%s"
// [HELPER] s__s: "%s"
// [HELPER] s_tpnl_obj__draw: "tpnl_obj::draw"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0051b187(TRIBE_Panel_Object *param_1)
{
  char cVar1;
  byte bVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Color_Table *pRVar4;
  bool bVar5;
  short sVar6;
  uchar *puVar7;
  void *pvVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  int iVar12;
  RGE_Action *pRVar13;
  RGE_Player *pRVar14;
  RGE_Static_Object *pRVar15;
  uint uVar16;
  uint uVar17;
  undefined2 uVar18;
  int unaff_EBX;
  float fVar19;
  undefined4 unaff_EBP;
  char cVar20;
  short unaff_SI;
  int unaff_EDI;
  TShape *this;
  char *pcVar21;
  TRIBE_Building_Object *this_00;
  TDrawArea *pTVar22;
  long lVar23;
  float fVar24;
  uchar uVar25;
  undefined4 uVar26;
  uchar uVar27;
  short sStack_156;
  float fStack_154;
  float fStack_150;
  short asStack_14c [2];
  TRIBE_Building_Object *pTStack_148;
  float fStack_144;
  undefined4 uStack_140;
  short sStack_13a;
  undefined1 auStack_138 [4];
  undefined4 uStack_134;
  char acStack_130 [100];
  char acStack_cc [100];
  char acStack_68 [104];
  
  if (((param_1->_padding_ == 0) || (param_1->_padding_ == 0)) || (param_1->_padding_ == 0)) {
LAB_0051be7b:
    param_1->_padding_ = 0;
    return;
  }
  if (param_1->mode == '\x02') {
    TRIBE_Panel_Object::draw_score(param_1);
    return;
  }
  if (param_1->game_obj == (RGE_Static_Object *)0x0) {
    if ((int *)param_1->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1->_padding_ + 0x34))(&param_1->_padding_);
      param_1->_padding_ = 0;
      return;
    }
    goto LAB_0051be7b;
  }
  fVar19 = (float)param_1->_padding_;
  fStack_150 = fVar19;
  (**(code **)((int)fVar19 + 0x28))(0);
  TDrawArea::Clear((TDrawArea *)param_1->_padding_,(tagRECT *)&param_1->_padding_,0);
  puVar7 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_tpnl_obj__draw,1);
  if (puVar7 != (uchar *)0x0) {
    pRVar15 = param_1->game_obj;
    pRVar3 = pRVar15->master_obj;
    sVar6 = pRVar3->button_pict;
    if (sVar6 != -1) {
      if (pRVar3->unit_level == '\x02') {
        bVar2 = (byte)pRVar15[3].attribute_type_held;
        fStack_150 = (float)CONCAT31(fStack_150._1_3_,bVar2);
        sVar6 = sVar6 + *(short *)((int)&pRVar3[1].outline_radius_z + 2);
        this = param_1->bldg_pics[bVar2];
      }
      else {
        this = param_1->unit_pics;
      }
      pRVar4 = pRVar15->owner->color_table;
      if (pRVar4 == (RGE_Color_Table *)0x0) {
        iVar9 = param_1->_padding_;
        iVar12 = param_1->_padding_;
        puVar7 = (uchar *)0x0;
        pTVar22 = (TDrawArea *)param_1->_padding_;
      }
      else {
        _ASMSet_Color_Xform((pRVar4->id + 1) * 0x10);
        iVar9 = param_1->_padding_;
        puVar7 = param_1->game_obj->owner->color_table->table;
        iVar12 = param_1->_padding_;
        pTVar22 = (TDrawArea *)param_1->_padding_;
      }
      TShape::shape_draw(this,pTVar22,iVar12 + 3,iVar9 + 0x1e,(int)sVar6,
                         pRVar4 != (RGE_Color_Table *)0x0,puVar7);
    }
    pRVar15 = param_1->game_obj;
    if ((UNK_00576d7c._4_4_ < pRVar15->hp) && (param_1->health_pic != (TShape *)0x0)) {
      fStack_150 = (float)TShape::shape_count(param_1->health_pic);
      pTStack_148 = (TRIBE_Building_Object *)(float)(int)fStack_150;
      TShape::shape_count(param_1->health_pic);
      fStack_150 = (float)(int)pRVar15->master_obj->hp;
      sVar6 = __ftol();
      if (sVar6 < 0) {
        sVar6 = 0;
      }
      else {
        lVar23 = TShape::shape_count(param_1->health_pic);
        if (lVar23 + -1 < (int)sVar6) {
          lVar23 = TShape::shape_count(param_1->health_pic);
          sVar6 = (short)lVar23 + -1;
        }
      }
      TShape::shape_draw(param_1->health_pic,(TDrawArea *)param_1->_padding_,param_1->_padding_ + 3,
                         param_1->_padding_ + 0x54,(int)sVar6,'\0',(uchar *)0x0);
    }
    TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_tpnl_obj__draw);
  }
  pvVar8 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_tpnl_obj__draw);
  if (pvVar8 != (void *)0x0) {
    SetBkMode(*(undefined4 *)(param_1->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),0xffffff);
    SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_);
    pTStack_148 = (TRIBE_Building_Object *)
                  SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->font);
    if (param_1->game_obj->owner->id != 0) {
      iVar9 = RGE_Base_Game::campaignGame(rge_base_game);
      if (iVar9 == 0) {
        acStack_130[0] = '\0';
      }
      else {
        pRVar14 = param_1->game_obj->owner;
        pcVar10 = RGE_Scenario::GetPlayerName(pRVar14->world->scenario,pRVar14->id + -1);
        uVar16 = 0xffffffff;
        do {
          pcVar21 = pcVar10;
          if (uVar16 == 0) break;
          uVar16 = uVar16 - 1;
          pcVar21 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar21;
        } while (cVar1 != '\0');
        uVar16 = ~uVar16;
        pcVar10 = pcVar21 + -uVar16;
        pcVar21 = acStack_130;
        for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
          *(undefined4 *)pcVar21 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar21 = pcVar21 + 4;
        }
        for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
          *pcVar21 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar21 = pcVar21 + 1;
        }
      }
      if (acStack_130[0] == '\0') {
        (**(code **)(rge_base_game->_padding_ + 0x28))
                  (0x69,param_1->game_obj->owner->master_player_id,0,acStack_130,100);
      }
      uVar16 = 0xffffffff;
      pcVar10 = acStack_130;
      do {
        if (uVar16 == 0) break;
        uVar16 = uVar16 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      TextOutA(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_ + 3,
               param_1->_padding_ + -2,acStack_130,~uVar16 - 1);
    }
    sVar6 = param_1->game_obj->master_obj->string_id;
    if (sVar6 < 1) {
      acStack_cc[0] = '\0';
    }
    else {
      (**(code **)(rge_base_game->_padding_ + 0x20))((int)sVar6,acStack_cc,100);
    }
    if (acStack_cc[0] == '\0') {
      uVar16 = 0xffffffff;
      pcVar10 = param_1->game_obj->master_obj->name;
      do {
        pcVar21 = pcVar10;
        if (uVar16 == 0) break;
        uVar16 = uVar16 - 1;
        pcVar21 = pcVar10 + 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar21;
      } while (cVar1 != '\0');
      uVar16 = ~uVar16;
      pcVar10 = pcVar21 + -uVar16;
      pcVar21 = acStack_cc;
      for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
        *(undefined4 *)pcVar21 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar21 = pcVar21 + 4;
      }
      for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
        *pcVar21 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar21 = pcVar21 + 1;
      }
    }
    if (*(int *)(rge_base_game[1].work_dir + 0x14) == 0) {
      sprintf(acStack_130,s__s,acStack_cc);
    }
    else {
      sprintf(acStack_130,s__d__s,param_1->game_obj->id,acStack_cc);
    }
    uVar16 = 0xffffffff;
    pcVar10 = acStack_130;
    do {
      if (uVar16 == 0) break;
      uVar16 = uVar16 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    TextOutA(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_ + 3,
             param_1->_padding_ + 0xd,acStack_130,~uVar16 - 1);
    if (UNK_00576d7c._4_4_ < param_1->game_obj->hp) {
      uVar11 = __ftol((int)param_1->game_obj->master_obj->hp);
      sprintf(acStack_cc,s__d__d,uVar11);
      uVar16 = 0xffffffff;
      pcVar10 = acStack_cc;
      do {
        if (uVar16 == 0) break;
        uVar16 = uVar16 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      TextOutA(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_ + 3,
               param_1->_padding_ + 0x5c,acStack_cc,~uVar16 - 1);
    }
    SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),pTStack_148);
    SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),0);
    TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_tpnl_obj__draw);
    fVar19 = fStack_154;
  }
  this_00 = (TRIBE_Building_Object *)param_1->game_obj;
  cVar20 = '\0';
  cVar1 = *(char *)(this_00->_padding_ + 0x8f);
  sVar6 = (short)((uint)unaff_EBP >> 0x10);
  if (cVar1 == '\x03') {
LAB_0051bb21:
    (**(code **)(this_00->_padding_ + 0x230))(&stack0xfffffea4,&sStack_156);
    (**(code **)((int)fVar19 + 0xe0))(0,7,1,(int)sVar6,(int)unaff_SI);
    cVar20 = '\x01';
LAB_0051bb52:
    (**(code **)(param_1->game_obj->_padding_ + 0x22c))(&stack0xfffffea4,&sStack_156);
    if (((0 < unaff_SI) || (uVar25 = param_1->game_obj->master_obj->unit_level, uVar25 == '\x04'))
       || (uVar25 == '\x06')) {
      (**(code **)((int)fVar19 + 0xe0))(cVar20,8,1,(int)sVar6,(int)unaff_SI);
      cVar20 = cVar20 + '\x01';
    }
    (**(code **)(param_1->game_obj->_padding_ + 0x244))(&stack0xfffffe9c,&stack0xfffffea2);
    if (0 < (short)unaff_EBX) {
      (**(code **)((int)fVar19 + 0xe0))(cVar20,10,1,(int)sStack_156,(int)(short)unaff_EBX);
      cVar20 = cVar20 + '\x01';
    }
    uVar25 = param_1->game_obj->master_obj->unit_level;
    if (((uVar25 == '\x04') || (uVar25 == '\x06')) &&
       ((**(code **)(param_1->game_obj->_padding_ + 0x234))(&fStack_144,auStack_138),
       _DAT_00576dac < fStack_144)) {
      uVar11 = __ftol();
      uVar11 = __ftol(uVar11);
      (**(code **)((int)fVar19 + 0xe0))(cVar20,6,1,uVar11);
      cVar20 = cVar20 + '\x01';
    }
    if (param_1->game_obj->master_obj->unit_level == '\x06') {
      uVar11 = __ftol(0);
      (**(code **)((int)fVar19 + 0xe0))(cVar20,9,3,uVar11);
      cVar20 = cVar20 + '\x01';
    }
    pRVar15 = param_1->game_obj;
    if ((TRIBE_Player *)pRVar15->owner != param_1->player) goto LAB_0051be67;
    uVar25 = pRVar15->master_obj->unit_level;
    if (uVar25 == '\a') {
      (**(code **)((int)fVar19 + 0xe0))
                (cVar20,4,2,(int)pRVar15->objects->number_of_objects,pRVar15->master_obj->obj_max);
      (**(code **)(unaff_EDI + 0x2c))();
      return;
    }
    if (uVar25 == '\t') {
      if ((pRVar15->attribute_type_held == 0x11) || (pRVar15->attribute_type_held == 0)) {
        sVar6 = __ftol();
      }
      else {
        sVar6 = 0;
      }
      (**(code **)((int)fVar19 + 0xe0))(cVar20,2,0,(int)sVar6,0);
      (**(code **)(unaff_EDI + 0x2c))();
      return;
    }
    if (uVar25 == '\x05') {
      switch(pRVar15->attribute_type_held) {
      case 0:
      case 0xf:
      case 0x10:
      case 0x11:
        uVar18 = 2;
        break;
      case 1:
        uVar18 = 0;
        break;
      case 2:
        uVar18 = 1;
        break;
      case 3:
        uVar18 = 3;
        break;
      default:
switchD_0051b6bc_caseD_4:
        (**(code **)((int)fStack_154 + 0x2c))();
        return;
      case 9:
        uVar18 = 5;
      }
      if ((float)_DAT_00576db0 < pRVar15->attribute_amount_held) {
        uVar11 = __ftol(0);
        (**(code **)((int)fVar19 + 0xe0))(cVar20,3,0,uVar11);
        (**(code **)(unaff_EDI + 0x2c))();
        return;
      }
      (**(code **)((int)fVar19 + 0xe0))(cVar20,uVar18,4,0xffffffff,0);
      (**(code **)(unaff_EDI + 0x2c))();
      return;
    }
    iVar9 = __ftol();
    if (iVar9 < 1) goto LAB_0051be67;
    switch(pRVar15->attribute_type_held) {
    case 0:
    case 0xf:
    case 0x10:
    case 0x11:
      uVar18 = 2;
      break;
    case 1:
      uVar18 = 0;
      break;
    case 2:
      uVar18 = 1;
      break;
    case 3:
      uVar18 = 3;
      break;
    default:
      goto switchD_0051b6bc_caseD_4;
    case 9:
      uVar18 = 5;
    }
    uVar11 = __ftol(0);
    uVar26 = 0;
  }
  else {
    if (((cVar1 == '\t') || (cVar1 == '\x04')) ||
       ((cVar1 == '\x05' || ((cVar1 == '\x06' || (cVar1 == '\a')))))) {
      if ((cVar1 == '\x03') || (cVar1 == '\x04')) goto LAB_0051bb21;
      goto LAB_0051bb52;
    }
    if (cVar1 == '\x01') {
      switch((short)this_00->_padding_) {
      case 0:
      case 0xf:
      case 0x10:
      case 0x11:
        uVar18 = 2;
        break;
      case 1:
        uVar18 = 0;
        break;
      case 2:
        uVar18 = 1;
        break;
      case 3:
        uVar18 = 3;
        break;
      default:
        goto switchD_0051b6bc_caseD_4;
      case 9:
        uVar18 = 5;
      }
      uVar11 = __ftol(0);
      (**(code **)((int)fVar19 + 0xe0))(0,uVar18,0,uVar11);
      (**(code **)(unaff_EDI + 0x2c))();
      return;
    }
    if ((cVar1 != '\x02') && (cVar1 != '\b')) goto LAB_0051be67;
    if (*(char *)(this_00->_padding_ + 4) == 'P') {
      pTStack_148 = this_00;
      TRIBE_Building_Object::work_status
                (this_00,asStack_14c,&sStack_13a,(short *)&uStack_140,acStack_68,100);
      if (((asStack_14c[0] != 0x67) && (asStack_14c[0] != 0x66)) &&
         (iVar9 = TRIBE_Building_Object::production_queue_status
                            (this_00,&sStack_13a,(short *)&uStack_134), iVar9 != 0)) {
        asStack_14c[0] = 0x66;
        asStack_14c[1] = 0;
        uStack_140 = uStack_134;
      }
      if ((param_1->game_obj->object_state != '\0') &&
         (((TRIBE_Player *)param_1->game_obj->owner != param_1->player ||
          ((asStack_14c[0] != 0x67 && (asStack_14c[0] != 0x66)))))) {
        iVar9 = this_00->_padding_;
        (**(code **)(iVar9 + 0x230))(&stack0xfffffea4,&sStack_156);
        if (0 < unaff_SI) {
          (**(code **)(unaff_EBX + 0xe0))(0,7,1,(int)sVar6,(int)unaff_SI);
        }
        cVar20 = 0 < unaff_SI;
        (**(code **)(iVar9 + 0x234))(asStack_14c,&uStack_140);
        iVar9 = __ftol();
        if (0 < iVar9) {
          uVar11 = __ftol(iVar9);
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,6,1,uVar11);
          cVar20 = cVar20 + '\x01';
        }
      }
      if ((TRIBE_Player *)param_1->game_obj->owner == param_1->player) {
        if ((char)this_00->_padding_ == '\0') {
          uVar11 = 0;
          sVar6 = TRIBE_Building_Object::get_construction_progress(this_00);
LAB_0051b878:
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,9,3,(int)sVar6,uVar11);
        }
        else {
          if ((asStack_14c[0] == 0x67) || (asStack_14c[0] == 0x66)) {
            uVar11 = 0;
            sVar6 = (short)uStack_140;
            goto LAB_0051b878;
          }
          if (param_1->game_obj->master_obj->id == 0x46) {
            iVar12 = __ftol();
            iVar9 = __ftol();
            if (iVar12 <= iVar9) {
              iVar9 = iVar12;
            }
            uVar11 = __ftol(iVar9);
            (**(code **)((int)fStack_154 + 0xe0))(cVar20,4,2,uVar11);
            cVar20 = cVar20 + '\x01';
            this_00 = pTStack_148;
          }
          if ((param_1->game_obj->master_obj->id != 0x32) ||
             (pRVar13 = RGE_Action_List::get_action((RGE_Action_List *)this_00->_padding_),
             pRVar13 == (RGE_Action *)0x0)) goto LAB_0051b925;
          uVar11 = __ftol(0);
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,2,0,uVar11);
        }
        cVar20 = cVar20 + '\x01';
      }
    }
LAB_0051b925:
    pRVar15 = param_1->game_obj;
    if ((pRVar15->object_state != '\0') && (pRVar15->object_state == '\x02')) {
      bVar5 = false;
      if ((TRIBE_Player *)pRVar15->owner == param_1->player) {
LAB_0051b95b:
        if ((asStack_14c[0] != 0x67) && (asStack_14c[0] != 0x66)) {
          sVar6 = pRVar15->master_obj->id;
          if (sVar6 == 0x2d) {
LAB_0051b995:
            bVar5 = true;
          }
          else if (sVar6 == 0x32) {
            bVar5 = false;
          }
          else if ((pRVar15->attribute_type_held != -1) && (iVar9 = __ftol(), 0 < iVar9))
          goto LAB_0051b995;
        }
      }
      else {
        if (pRVar15->master_obj->id == 0x2d) goto LAB_0051b995;
        if ((TRIBE_Player *)pRVar15->owner == param_1->player) goto LAB_0051b95b;
      }
      if (bVar5) {
        switch(pRVar15->attribute_type_held) {
        case 0:
        case 0xf:
        case 0x10:
        case 0x11:
          uVar18 = 2;
          break;
        case 1:
          uVar18 = 0;
          break;
        case 2:
          uVar18 = 1;
          break;
        case 3:
          uVar18 = 3;
          break;
        default:
          goto LAB_0051ba3c;
        case 9:
          uVar18 = 5;
        }
        if (pRVar15->master_obj->id == 0x2d) {
          uVar11 = __ftol(0);
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,uVar18,0,uVar11);
        }
        else {
          uVar11 = __ftol(0);
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,uVar18,0,uVar11);
        }
        cVar20 = cVar20 + '\x01';
      }
    }
LAB_0051ba3c:
    pRVar15 = param_1->game_obj;
    if ((pRVar15->master_obj->id != 0x2d) || ((TRIBE_Player *)pRVar15->owner == param_1->player))
    goto LAB_0051be67;
    fVar19 = pRVar15->world_y;
    fVar24 = pRVar15->world_x;
    uVar27 = '\x02';
    uVar25 = '\x01';
    lVar23 = 0x2d;
    pRVar14 = RGE_Base_Game::get_player(rge_base_game);
    pRVar15 = RGE_Object_List::find_by_master_id
                        (pRVar14->objects,lVar23,fVar24,fVar19,uVar25,uVar27,pRVar15);
    if (pRVar15 == (RGE_Static_Object *)0x0) goto LAB_0051be67;
    fStack_150 = pRVar15->world_x - param_1->game_obj->world_x;
    uVar11 = __ftol(0x14);
    uVar26 = 2;
    uVar18 = 3;
  }
  (**(code **)((int)fStack_154 + 0xe0))(cVar20,uVar18,uVar26,uVar11);
LAB_0051be67:
  (**(code **)((int)fStack_154 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0051becb
// Address: 0051becb
void FUN_0051becb(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0051c1f6
// Address: 0051c1f6
// [HELPER] s__d: "%d"
// [HELPER] s__d__: "%d%%"
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s_tpnl_obj__draw_item: "tpnl_obj::draw_item"
void FUN_0051c1f6(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)
{
  char cVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  byte *in_EAX;
  uchar *puVar5;
  void *pvVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  undefined1 in_CF;
  char acStack_14 [20];
  
  uVar4 = CONCAT11(in_CF,*in_EAX) << 6 | CONCAT11(in_CF,*in_EAX) >> 3;
  *in_EAX = (byte)uVar4;
  bVar2 = *in_EAX;
  *in_EAX = bVar2 << 4 | (byte)(CONCAT11((uVar4 & 0x100) != 0,bVar2) >> 5);
  bVar3 = *in_EAX;
  *in_EAX = bVar3 << 6 | (byte)(CONCAT11((bVar2 & 0x10) != 0,bVar3) >> 3);
  bVar2 = *in_EAX;
  *in_EAX = bVar2 << 4 | (byte)(CONCAT11((bVar3 & 4) != 0,bVar2) >> 5);
  bVar3 = *in_EAX;
  *in_EAX = bVar3 << 2 | (byte)(CONCAT11((bVar2 & 0x10) != 0,bVar3) >> 7);
  *in_EAX = *in_EAX;
  bVar2 = *in_EAX;
  *in_EAX = bVar2 << 2 | (byte)(CONCAT11((bVar3 & 0x40) != 0,bVar2) >> 7);
  *in_EAX = *in_EAX << 7 | (byte)(CONCAT11((bVar2 & 0x40) != 0,*in_EAX) >> 2);
  if (((*(int *)(in_EAX + 0x104) != 0) && (param_2 != -1)) &&
     (puVar5 = TDrawArea::Lock(*(TDrawArea **)(in_EAX + 0x20),s_tpnl_obj__draw_item,1),
     puVar5 != (uchar *)0x0)) {
    TShape::shape_draw(*(TShape **)(in_EAX + 0x104),*(TDrawArea **)(in_EAX + 0x20),
                       *(int *)(in_EAX + 0xc) + 0x36,*(int *)(in_EAX + 0x10) + 0x1e + param_1 * 0x14
                       ,param_2,'\0',(uchar *)0x0);
    TDrawArea::Unlock(*(TDrawArea **)(in_EAX + 0x20),s_tpnl_obj__draw_item);
  }
  switch(param_3) {
  case 0:
    sprintf(acStack_14,&s__d,param_4);
    break;
  case 1:
    if (param_4 < param_5) {
      sprintf(acStack_14,s__d__d,param_4,param_5 - param_4);
    }
    else {
      sprintf(acStack_14,&s__d,param_4);
    }
    break;
  case 2:
    sprintf(acStack_14,s__d__d,param_4,param_5);
    break;
  case 3:
    sprintf(acStack_14,s__d__,param_4);
    break;
  default:
    acStack_14[0] = '\0';
  }
  if ((acStack_14[0] != '\0') &&
     (pvVar6 = TDrawArea::GetDc(*(TDrawArea **)(in_EAX + 0x20),s_tpnl_obj__draw_item),
     pvVar6 != (void *)0x0)) {
    SetBkMode(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),1);
    SetTextColor(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),0xffffff);
    uVar7 = SelectObject(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),
                         *(undefined4 *)(in_EAX + 0xf4));
    uVar8 = 0xffffffff;
    pcVar9 = acStack_14;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    TextOutA(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),*(int *)(in_EAX + 0xc) + 0x58,
             *(int *)(in_EAX + 0x10) + 0x21 + param_1 * 0x14,acStack_14,~uVar8 - 1);
    SelectObject(*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x38),uVar7);
    TDrawArea::ReleaseDc(*(TDrawArea **)(in_EAX + 0x20),s_tpnl_obj__draw_item);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051c3da
// Address: 0051c3da
void FUN_0051c3da(void)
{
  func_0xb30051c2();
  return;
}

// --------------------------------------------------

// Function: FUN_0051cc7c
// Address: 0051cc7c
undefined4 FUN_0051cc7c(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051cc85
// Address: 0051cc85
undefined4 FUN_0051cc85(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051cc95
// Address: 0051cc95
TPanel * __thiscall FUN_0051cc95(TPanel *param_1,TDrawArea *param_2,TPanel *param_3)
{
  RGE_Font *pRVar1;
  long lVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005613a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel(param_1);
  param_1->_padding_ = (int)&TRIBE_Panel_Pop::_vftable_;
  param_1->handle_mouse_input = 0;
  uStack_4 = 0;
  pRVar1 = RGE_Base_Game::get_font(rge_base_game,0xb);
  param_1[1]._padding_ = (int)pRVar1->font;
  param_1[1].previousPanelValue = (TPanel *)0xffffff;
  param_1[1].previousModalPanelValue = (TPanel *)0x0;
  param_1[1].pnl_x = 0xffff;
  param_1[1].pnl_y = 0;
  param_1[1].pnl_wid = 0;
  param_1[1].pnl_hgt = 0;
  param_1[1].panelNameValue = (char *)0x0;
  param_1[1].render_area = (TDrawArea *)0x0;
  *(undefined1 *)&param_1[1].clip_rect.left = 0;
  param_1[1].clip_rect.top = 0;
  param_1[1].clip_rect.bottom = 0;
  param_1[1].mouse_captured = -1;
  param_1[1].active = -1;
  param_1[1].tab_next_panel = (TPanel *)0x0;
  param_1[1].clip_rect.right = 0;
  lVar2 = TPanel::setup(param_1,param_2,param_3,0,0,0,0,'\0');
  if (lVar2 == 0) {
    param_1->error_code = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051cd88
// Address: 0051cd88
TRIBE_Panel_Pop * __thiscall FUN_0051cd88(TRIBE_Panel_Pop *param_1,byte param_2)
{
  TRIBE_Panel_Pop::~TRIBE_Panel_Pop(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051cdae
// Address: 0051cdae
void __fastcall FUN_0051cdae(TPanel *param_1)
{
  int iVar1;
  TDrawArea *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_005613c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Panel_Pop::_vftable_;
  iVar1 = param_1[1].clip_rect.right;
  uStack_4 = 0;
  if (iVar1 != 0) {
    DeleteObject(iVar1);
    param_1[1].clip_rect.right = 0;
  }
  this = (TDrawArea *)param_1[1].clip_rect.bottom;
  if (this != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this);
    operator_delete(this);
    param_1[1].clip_rect.bottom = 0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0051ce3b
// Address: 0051ce3b
// [HELPER] s_time_message_panel: "time message panel"
void __thiscall FUN_0051ce3b(TPanel *param_1,int param_2,long param_3,long param_4,long param_5)
{
  int iVar1;
  long lVar2;
  TDrawArea *pTVar3;
  int iVar4;
  TDrawArea *pTVar5;
  TPanel *pTVar6;
  long lVar7;
  TPanel *pTVar8;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005613eb;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::set_rect(param_1,param_2,param_3,param_4,param_5);
  if (((param_1[1].mouse_captured < param_1->pnl_wid) || (param_1[1].active < param_1->pnl_hgt)) ||
     (param_1->render_area->Width <= param_2 + param_1[1].mouse_captured)) {
    iVar1 = param_1[1].clip_rect.right;
    if (iVar1 != 0) {
      DeleteObject(iVar1);
      param_1[1].clip_rect.right = 0;
    }
    pTVar5 = (TDrawArea *)param_1[1].clip_rect.bottom;
    if (pTVar5 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar5);
      operator_delete(pTVar5);
      param_1[1].clip_rect.bottom = 0;
    }
    pTVar5 = (TDrawArea *)operator_new(0x100);
    uStack_4 = 0;
    if (pTVar5 == (TDrawArea *)0x0) {
      pTVar5 = (TDrawArea *)0x0;
    }
    else {
      pTVar5 = (TDrawArea *)TDrawArea::TDrawArea(pTVar5,s_time_message_panel,0);
    }
    lVar7 = param_1->pnl_hgt;
    lVar2 = param_1->pnl_wid;
    pTVar3 = param_1->render_area;
    param_1[1].clip_rect.bottom = (long)pTVar5;
    uStack_4 = 0xffffffff;
    TDrawArea::Init(pTVar5,pTVar3->DrawSystem,lVar2,lVar7,0,0);
    iVar1 = param_1->pnl_wid;
    iVar4 = param_1->pnl_hgt;
    param_1[1].mouse_captured = iVar1;
    param_1[1].active = iVar4;
    pTVar6 = (TPanel *)(iVar1 + -1);
    pTVar8 = (TPanel *)(iVar4 + -1);
    param_1[1].position_mode = PositionFixed;
    param_1[1].need_redraw = RedrawNone;
    param_1[1].curr_child = pTVar6;
    param_1[1].parent_panel = pTVar8;
    lVar7 = CreateRectRgn(0,0,pTVar6,pTVar8);
    param_1[1].clip_rect.right = lVar7;
  }
  if (param_1[1].clip_rect.bottom == 0) {
    param_1[1].mouse_captured = -1;
    param_1[1].active = -1;
  }
  else {
    param_1[1].left_panel = (TPanel *)param_1[1].position_mode;
    param_1[1].top_panel = (TPanel *)param_1[1].need_redraw;
    param_1[1].right_panel = param_1[1].curr_child;
    param_1[1].bottom_panel = param_1[1].parent_panel;
  }
  param_1->need_restore = '\x01';
  (**(code **)(param_1->_padding_ + 0x20))(1);
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}

// --------------------------------------------------

// Function: FUN_0051cfc5
// Address: 0051cfc5
void __fastcall FUN_0051cfc5(int param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  *(RGE_Game_World **)(param_1 + 0x108) = rge_base_game->world;
  pRVar1 = RGE_Base_Game::get_player(rge_base_game);
  *(RGE_Player **)(param_1 + 0x10c) = pRVar1;
  iVar2 = __ftol();
  *(int *)(param_1 + 0x110) = iVar2;
  iVar3 = __ftol();
  *(int *)(param_1 + 0x114) = iVar2 + iVar3;
  iVar4 = __ftol();
  if (iVar4 < iVar2 + iVar3) {
    *(int *)(param_1 + 0x114) = iVar4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051d03b
// Address: 0051d03b
int __fastcall FUN_0051d03b(int param_1)
{
  if (*(int *)(param_1 + 0x10c) != 0) {
    return (int)*(short *)(*(int *)(param_1 + 0x10c) + 0x4a);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051d052
// Address: 0051d052
// [HELPER] s__s_ld__ld: "%s%ld/%ld"
// [HELPER] s_tpnl_tim__draw: "tpnl_tim::draw"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0051d052(TRIBE_Panel_Pop *param_1)
{
  float fVar1;
  bool bVar2;
  float fVar3;
  byte bVar4;
  TRIBE_Player *pTVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  char *pcVar10;
  TDrawArea *pTVar11;
  int iVar12;
  ulong uVar13;
  undefined1 auStack_124 [16];
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  undefined4 uStack_108;
  undefined1 auStack_104 [260];
  
  if (((param_1->_padding_ != 0) && (param_1->_padding_ != 0)) && (param_1->_padding_ != 0)) {
    iStack_10c = param_1->_padding_;
    param_1->_padding_ = param_1->_padding_ + 1;
    (**(code **)(iStack_10c + 0x28))(0);
    pTVar5 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    param_1->player = pTVar5;
    bVar2 = false;
    if ((param_1->mode == '\0') &&
       (0 < *(int *)(rge_base_game[1].save_music_file +
                    *(short *)((int)&pTVar5->_padding_ + 2) * 4 + -0x70))) {
      param_1->mode = '\x01';
      param_1->timer = 0.0;
      bVar2 = true;
    }
    fVar3 = _DAT_00576ea0;
    if ((param_1->mode != '\0') &&
       (fVar1 = ((RGE_Game_World *)pTVar5->_padding_)->world_time_delta_seconds + param_1->timer,
       param_1->timer = fVar1, fVar3 < fVar1)) {
      bVar2 = true;
      bVar4 = param_1->mode + 1;
      param_1->timer = 0.0;
      param_1->mode = bVar4;
      if (2 < bVar4) {
        param_1->mode = '\0';
      }
    }
    iVar6 = __ftol();
    iVar7 = __ftol();
    iVar8 = __ftol();
    iVar12 = iVar7 + iVar6;
    if (iVar8 < iVar7 + iVar6) {
      iVar12 = iVar8;
    }
    if ((param_1->ImageBuffer != (TDrawArea *)0x0) &&
       ((((bVar2 || (*(char *)((int)&param_1->_padding_ + 3) != '\0')) || (param_1->pop != iVar6))
        || (param_1->max_pop != iVar12)))) {
      param_1->pop = iVar6;
      param_1->max_pop = iVar12;
      TRIBE_Panel_Pop::render_to_image_buffer(param_1);
      if (*(char *)((int)&param_1->_padding_ + 3) != '\0') {
        *(undefined1 *)((int)&param_1->_padding_ + 3) = 0;
        (**(code **)(iStack_110 + 0x2c))();
        return;
      }
    }
    if ((param_1->ImageTextActive != 0) && (param_1->ImageBuffer != (TDrawArea *)0x0)) {
      TDrawArea::SetTrans(param_1->ImageBuffer,1,'\x01');
      TDrawArea::Copy(param_1->ImageBuffer,(TDrawArea *)param_1->_padding_,
                      (param_1->UsedScreenRect).left,(param_1->UsedScreenRect).top,
                      &param_1->UsedImageRect,1);
      TDrawArea::SetTrans(param_1->ImageBuffer,0,'\x01');
      (**(code **)(iStack_110 + 0x2c))();
      return;
    }
    pvVar9 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_tpnl_tim__draw);
    if (pvVar9 != (void *)0x0) {
      SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_);
      uStack_108 = SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->font);
      SetBkMode(*(undefined4 *)(param_1->_padding_ + 0x38),1);
      iVar12 = param_1->max_pop;
      iVar6 = param_1->pop;
      pcVar10 = TPanel::get_string((TPanel *)param_1,0x2b2a);
      sprintf(auStack_104,s__s_ld__ld,pcVar10,iVar6,iVar12);
      SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->color2);
      iVar12 = param_1->_padding_;
      iVar6 = param_1->_padding_;
      iVar8 = param_1->_padding_ + -2 + iVar6 + 1;
      iVar7 = param_1->_padding_ + -2 + iVar12 + 1;
      iStack_10c = iVar7 + -2;
      SetRect(auStack_124,iVar12,iVar6,iStack_10c,iVar8 + -2);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_124,0x21);
      iStack_114 = iVar6 + 2;
      SetRect(auStack_124,iVar12,iStack_114,iStack_10c,iVar8);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_124,0x21);
      SetRect(auStack_124,iVar12 + 2,iVar6,iVar7,iVar8 + -2);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_124,0x21);
      SetRect(auStack_124,iVar12 + 2,iStack_114,iVar7,iVar8);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_124,0x21);
      if (param_1->mode == '\x01') {
        uVar13 = param_1->color3;
        pTVar11 = param_1->ImageBuffer;
      }
      else {
        uVar13 = param_1->color1;
        pTVar11 = (TDrawArea *)param_1->_padding_;
      }
      SetTextColor(pTVar11->DrawDc,uVar13);
      SetRect(auStack_124,iVar12 + 1,iVar6 + 1,iVar7 + -1,iVar8 + -1);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_124,0x21);
      SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),uStack_108);
      SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),0);
      TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_tpnl_tim__draw);
    }
    (**(code **)(iStack_110 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051d469
// Address: 0051d469
void __thiscall FUN_0051d469(int param_1,undefined4 *param_2)
{
  if ((((*(int *)(param_1 + 0x124) != 0) && (*(int *)(param_1 + 0x20) != 0)) &&
      (*(int *)(param_1 + 0x70) != 0)) && (*(int *)(param_1 + 0x6c) != 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x148);
    param_2[1] = *(undefined4 *)(param_1 + 0x14c);
    param_2[2] = *(undefined4 *)(param_1 + 0x150);
    param_2[3] = *(undefined4 *)(param_1 + 0x154);
    return;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x8c);
  param_2[1] = *(undefined4 *)(param_1 + 0x90);
  param_2[2] = *(undefined4 *)(param_1 + 0x94);
  param_2[3] = *(undefined4 *)(param_1 + 0x98);
  return;
}

// --------------------------------------------------

// Function: FUN_0051d4d5
// Address: 0051d4d5
undefined4 __fastcall FUN_0051d4d5(TPanel *param_1)
{
  TPanel::handle_idle(param_1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051d4e8
// Address: 0051d4e8
// [HELPER] s__s_ld__ld: "%s%ld/%ld"
// [HELPER] s_tpnl_tim__render_to_image_buffer: "tpnl_tim::render_to_image_buffer"
undefined4 __fastcall FUN_0051d4e8(TPanel *param_1)
{
  int iVar1;
  int iVar2;
  PanelNode *pPVar3;
  PanelNode *pPVar4;
  void *pvVar5;
  char *pcVar6;
  TPanel *pTVar7;
  TPanel *pTVar8;
  char *pcVar9;
  TDrawArea *pTVar10;
  undefined1 auStack_114 [16];
  undefined4 uStack_104;
  undefined1 auStack_100 [256];
  
  pTVar10 = (TDrawArea *)param_1[1].clip_rect.bottom;
  if (pTVar10 == (TDrawArea *)0x0) {
    return 0;
  }
  TDrawArea::PtrClear(pTVar10,(tagRECT *)&param_1[1].position_mode,1);
  pvVar5 = TDrawArea::GetDc((TDrawArea *)param_1[1].clip_rect.bottom,
                            s_tpnl_tim__render_to_image_buffer);
  if (pvVar5 == (void *)0x0) {
    return 0;
  }
  TDrawArea::SetClipRect
            ((TDrawArea *)param_1[1].clip_rect.bottom,(tagRECT *)&param_1[1].position_mode);
  SelectClipRgn(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),param_1[1].clip_rect.right);
  uStack_104 = SelectObject(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),param_1[1]._padding_
                           );
  SetBkMode(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),1);
  pTVar10 = param_1[1].render_area;
  pcVar9 = param_1[1].panelNameValue;
  pcVar6 = TPanel::get_string(param_1,0x2b2a);
  sprintf(auStack_100,s__s_ld__ld,pcVar6,pcVar9,pTVar10);
  SetTextColor(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),
               param_1[1].previousModalPanelValue);
  iVar1 = param_1->pnl_wid;
  iVar2 = param_1->pnl_hgt;
  SetRect(auStack_114,0,0,iVar1 + -3,iVar2 + -3);
  DrawTextA(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),auStack_100,0xffffffff,auStack_114,
            0x21);
  SetRect(auStack_114,0,2,iVar1 + -3,iVar2 + -1);
  DrawTextA(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),auStack_100,0xffffffff,auStack_114,
            0x21);
  SetRect(auStack_114,2,0,iVar1 + -1,iVar2 + -3);
  DrawTextA(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),auStack_100,0xffffffff,auStack_114,
            0x21);
  SetRect(auStack_114,2,2,iVar1 + -1,iVar2 + -1);
  DrawTextA(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),auStack_100,0xffffffff,auStack_114,
            0x21);
  if ((char)param_1[1].clip_rect.left == '\x01') {
    pTVar7 = (TPanel *)param_1[1].pnl_x;
  }
  else {
    pTVar7 = param_1[1].previousPanelValue;
  }
  SetTextColor(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),pTVar7);
  SetRect(auStack_114,1,1,iVar1 + -2,iVar2 + -2);
  DrawTextA(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),auStack_100,0xffffffff,auStack_114,
            0x21);
  SelectObject(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),uStack_104);
  SelectClipRgn(*(undefined4 *)(param_1[1].clip_rect.bottom + 0x38),0);
  TDrawArea::ReleaseDc((TDrawArea *)param_1[1].clip_rect.bottom,s_tpnl_tim__render_to_image_buffer);
  iVar1 = param_1->pnl_wid;
  iVar2 = param_1->pnl_hgt;
  pPVar3 = (PanelNode *)(param_1->render_rect).left;
  param_1[1].left_panel = (TPanel *)0x0;
  param_1[1].top_panel = (TPanel *)0x0;
  pPVar4 = (PanelNode *)(param_1->render_rect).top;
  pTVar7 = (TPanel *)(iVar1 + -1);
  pTVar8 = (TPanel *)(iVar2 + -1);
  param_1[1].node = pPVar3;
  param_1[1].first_child_node = pPVar4;
  param_1[1].tab_prev_panel = (TPanel *)((int)pPVar4 + (int)pTVar8);
  param_1[1].right_panel = pTVar7;
  param_1[1].bottom_panel = pTVar8;
  param_1[1].last_child_node = (PanelNode *)((int)pPVar3 + (int)pTVar7);
  param_1[1].tab_next_panel = (TPanel *)0x1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0051d78c
// Address: 0051d78c
TPanel * __thiscall FUN_0051d78c(TPanel *param_1,TDrawArea *param_2,TPanel *param_3)
{
  RGE_Font *pRVar1;
  long lVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561408;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel(param_1);
  param_1->_padding_ = (int)&TRIBE_Panel_Time::_vftable_;
  param_1->handle_mouse_input = 0;
  uStack_4 = 0;
  pRVar1 = RGE_Base_Game::get_font(rge_base_game,0xb);
  param_1[1]._padding_ = (int)pRVar1->font;
  param_1[1].previousPanelValue = (TPanel *)0xffffff;
  param_1[1].previousModalPanelValue = (TPanel *)0x0;
  param_1[1].pnl_x = 0;
  param_1[1].pnl_wid = 0;
  param_1[1].pnl_y = 0;
  param_1[1].pnl_hgt = 0;
  param_1[1].panelNameValue = (char *)0x0;
  param_1[1].render_area = (TDrawArea *)0x0;
  param_1[1].clip_rect.left = 0;
  param_1[1].clip_rect.top = 0;
  param_1[1].clip_rect.right = 0;
  param_1[1].clip_rect.bottom = 0;
  param_1[1].need_redraw = ~RedrawNone;
  param_1[1].parent_panel = (TPanel *)0x0;
  param_1[1].have_focus = -1;
  param_1[1].overlapping_children = -1;
  param_1[1].tab_stop = 0;
  param_1[1].curr_child = (TPanel *)0x0;
  lVar2 = TPanel::setup(param_1,param_2,param_3,0,0,0,0,'\0');
  if (lVar2 == 0) {
    param_1->error_code = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051d886
// Address: 0051d886
TRIBE_Panel_Time * __thiscall FUN_0051d886(TRIBE_Panel_Time *param_1,byte param_2)
{
  TRIBE_Panel_Time::~TRIBE_Panel_Time(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051d8ae
// Address: 0051d8ae
void __fastcall FUN_0051d8ae(TPanel *param_1)
{
  TDrawArea *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561428;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Panel_Time::_vftable_;
  uStack_4 = 0;
  if (param_1[1].curr_child != (TPanel *)0x0) {
    DeleteObject(param_1[1].curr_child);
    param_1[1].curr_child = (TPanel *)0x0;
  }
  this = (TDrawArea *)param_1[1].parent_panel;
  if (this != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this);
    operator_delete(this);
    param_1[1].parent_panel = (TPanel *)0x0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0051d93b
// Address: 0051d93b
// [HELPER] s_time_message_panel: "time message panel"
void __thiscall FUN_0051d93b(TPanel *param_1,int param_2,long param_3,long param_4,long param_5)
{
  long lVar1;
  long lVar2;
  TDrawArea *pTVar3;
  int iVar4;
  int iVar5;
  TDrawArea *pTVar6;
  TPanel *pTVar7;
  TPanel *pTVar8;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056144b;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::set_rect(param_1,param_2,param_3,param_4,param_5);
  if (((param_1[1].have_focus < param_1->pnl_wid) ||
      (param_1[1].overlapping_children < param_1->pnl_hgt)) ||
     (param_1->render_area->Width <= param_2 + param_1[1].have_focus)) {
    if (param_1[1].curr_child != (TPanel *)0x0) {
      DeleteObject(param_1[1].curr_child);
      param_1[1].curr_child = (TPanel *)0x0;
    }
    pTVar6 = (TDrawArea *)param_1[1].parent_panel;
    if (pTVar6 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar6);
      operator_delete(pTVar6);
      param_1[1].parent_panel = (TPanel *)0x0;
    }
    pTVar6 = (TDrawArea *)operator_new(0x100);
    uStack_4 = 0;
    if (pTVar6 == (TDrawArea *)0x0) {
      pTVar6 = (TDrawArea *)0x0;
    }
    else {
      pTVar6 = (TDrawArea *)TDrawArea::TDrawArea(pTVar6,s_time_message_panel,0);
    }
    lVar1 = param_1->pnl_hgt;
    lVar2 = param_1->pnl_wid;
    pTVar3 = param_1->render_area;
    param_1[1].parent_panel = (TPanel *)pTVar6;
    uStack_4 = 0xffffffff;
    TDrawArea::Init(pTVar6,pTVar3->DrawSystem,lVar2,lVar1,0,0);
    iVar4 = param_1->pnl_wid;
    iVar5 = param_1->pnl_hgt;
    param_1[1].have_focus = iVar4;
    param_1[1].overlapping_children = iVar5;
    pTVar7 = (TPanel *)(iVar4 + -1);
    pTVar8 = (TPanel *)(iVar5 + -1);
    param_1[1].left_panel = (TPanel *)0x0;
    param_1[1].top_panel = (TPanel *)0x0;
    param_1[1].right_panel = pTVar7;
    param_1[1].bottom_panel = pTVar8;
    pTVar7 = (TPanel *)CreateRectRgn(0,0,pTVar7,pTVar8);
    param_1[1].curr_child = pTVar7;
  }
  if (param_1[1].parent_panel == (TPanel *)0x0) {
    param_1[1].have_focus = -1;
    param_1[1].overlapping_children = -1;
  }
  else {
    param_1[1].node = (PanelNode *)param_1[1].left_panel;
    param_1[1].first_child_node = (PanelNode *)param_1[1].top_panel;
    param_1[1].last_child_node = (PanelNode *)param_1[1].right_panel;
    param_1[1].tab_prev_panel = param_1[1].bottom_panel;
  }
  param_1->need_restore = '\x01';
  (**(code **)(param_1->_padding_ + 0x20))(1);
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}

// --------------------------------------------------

// Function: FUN_0051dac5
// Address: 0051dac5
void __fastcall FUN_0051dac5(int param_1)
{
  ulong uVar1;
  
  *(RGE_Game_World **)(param_1 + 0x114) = rge_base_game->world;
  uVar1 = debug_timeGetTime(&s_C__msdev_work_age1_x1_tpnl_tim_c,0x92);
  *(ulong *)(param_1 + 0x11c) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0051dafe
// Address: 0051dafe
void __thiscall FUN_0051dafe(int *param_1,int param_2,int param_3)
{
  int iVar1;
  
  if (param_1[0x40] == param_2) {
    if (param_1[0x46] == 0) {
      return;
    }
    if (*(short *)(param_1[0x46] + 0x4a) == param_3) {
      return;
    }
  }
  param_1[0x40] = param_2;
  if (param_3 < 1) {
    param_1[0x46] = 0;
  }
  else {
    param_1[0x46] = *(int *)(*(int *)(param_1[0x45] + 0x40) + param_3 * 4);
  }
  if (param_1[0x46] == 0) {
switchD_0051db73_default:
    param_1[0x3e] = 0xffffff;
  }
  else {
    switch(*(undefined2 *)(*(int *)(param_1[0x46] + 0x108) + 0x26)) {
    case 0:
      param_1[0x3e] = 0xff0000;
      param_1[0x3f] = 0xb3b3b3;
      goto LAB_0051dbf4;
    case 1:
      param_1[0x3e] = 0x2139c6;
      break;
    case 2:
      param_1[0x3e] = 0xffff;
      break;
    case 3:
      param_1[0x3e] = 0x4f73a3;
      break;
    case 4:
      param_1[0x3e] = 0xf77f3;
      break;
    case 5:
      param_1[0x3e] = 0xc700;
      break;
    case 6:
      param_1[0x3e] = 0x7b90a2;
      break;
    case 7:
      param_1[0x3e] = 0xadad00;
      break;
    default:
      goto switchD_0051db73_default;
    }
  }
  param_1[0x3f] = 0;
LAB_0051dbf4:
  if ((param_2 == 1) || (param_2 == 2)) {
    param_1[0x42] = 1;
  }
  else {
    param_1[0x42] = 2;
  }
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0x14))(param_2 != 0);
  (**(code **)(iVar1 + 0x20))(1);
  (**(code **)(*(int *)param_1[0x10] + 0x20))(1);
  (**(code **)(iVar1 + 0x4c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0051dc3f
// Address: 0051dc3f
int __fastcall FUN_0051dc3f(int *param_1,undefined4 param_2)
{
  char *pcVar1;
  int iVar2;
  int in_EAX;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  bool in_PF;
  float10 in_ST0;
  
  if (in_PF) {
    (**(code **)(unaff_EDI + 0x14))(1);
    (**(code **)(unaff_EDI + 0x20))(1);
    (**(code **)(**(int **)(unaff_ESI + 0x40) + 0x20))(1);
    iVar2 = (**(code **)(unaff_EDI + 0x4c))();
    return iVar2;
  }
  *(char *)(in_EAX + -0x63ffae25) = *(char *)(in_EAX + -0x63ffae25) + (char)param_2;
  *param_1 = (int)ROUND(in_ST0);
  pcVar1 = (char *)(unaff_EBX * 9 + -0x243fffaf);
  *pcVar1 = *pcVar1 + (char)((uint)param_2 >> 8);
  *param_1 = (int)ROUND(in_ST0);
  *(char *)(unaff_EBX + 0x10081) = *(char *)(unaff_EBX + 0x10081) + (char)param_1;
  if (param_1[0x46] != 0) {
    return (int)*(short *)(param_1[0x46] + 0x4a);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051dc67
// Address: 0051dc67
int __fastcall FUN_0051dc67(int param_1)
{
  if (*(int *)(param_1 + 0x118) != 0) {
    return (int)*(short *)(*(int *)(param_1 + 0x118) + 0x4a);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051dc82
// Address: 0051dc82
// [HELPER] s__02ld__02ld__02ld___3_1f_: "%02ld:%02ld:%02ld (%3.1f)"
// [HELPER] s_tpnl_tim__draw: "tpnl_tim::draw"
void __fastcall FUN_0051dc82(TRIBE_Panel_Time *param_1)
{
  ulong uVar1;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined1 auStack_128 [16];
  int iStack_118;
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  undefined4 uStack_108;
  undefined1 auStack_104 [260];
  
  if (param_1->_padding_ == 0) {
    return;
  }
  if (param_1->_padding_ == 0) {
    return;
  }
  if (param_1->_padding_ == 0) {
    return;
  }
  iVar5 = param_1->_padding_;
  param_1->_padding_ = param_1->_padding_ + 1;
  iStack_110 = iVar5;
  (**(code **)(iVar5 + 0x28))(0);
  if (param_1->clock_format == 1) {
    uVar1 = param_1->game_time;
  }
  else {
    uVar1 = ((param_1->game_time + 4) / 5) * 5;
  }
  param_1->display_time = uVar1;
  if (((param_1->ImageBuffer != (TDrawArea *)0x0) &&
      ((((param_1->display_time != param_1->last_display_time ||
         (param_1->clock_type != param_1->old_clock_type)) ||
        (param_1->clock_format != param_1->old_clock_format)) ||
       (*(char *)((int)&param_1->_padding_ + 3) != '\0')))) &&
     (TRIBE_Panel_Time::render_to_image_buffer(param_1),
     *(char *)((int)&param_1->_padding_ + 3) != '\0')) {
    *(undefined1 *)((int)&param_1->_padding_ + 3) = 0;
    (**(code **)(iVar5 + 0x2c))();
    return;
  }
  if ((param_1->ImageTextActive != 0) && (param_1->ImageBuffer != (TDrawArea *)0x0)) {
    TDrawArea::SetTrans(param_1->ImageBuffer,1,'\x01');
    TDrawArea::Copy(param_1->ImageBuffer,(TDrawArea *)param_1->_padding_,
                    (param_1->UsedScreenRect).left,(param_1->UsedScreenRect).top,
                    &param_1->UsedImageRect,1);
    TDrawArea::SetTrans(param_1->ImageBuffer,0,'\x01');
    (**(code **)(iVar5 + 0x2c))();
    return;
  }
  pvVar2 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_tpnl_tim__draw);
  if (pvVar2 == (void *)0x0) goto LAB_0051e0ce;
  SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_);
  uStack_108 = SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->font);
  SetBkMode(*(undefined4 *)(param_1->_padding_ + 0x38),1);
  if (param_1->clock_format == 1) {
    uVar1 = param_1->game_time;
    iVar5 = 0;
    iVar7 = 0;
    if (0x3b < (int)uVar1) {
      iVar5 = (int)uVar1 / 0x3c;
      uVar1 = (int)uVar1 % 0x3c;
      if (0x3b < iVar5) {
        iVar7 = iVar5 / 0x3c;
        iVar5 = iVar5 % 0x3c;
      }
    }
    sprintf(auStack_104,s__02ld__02ld__02ld___3_1f_,iVar7,iVar5,uVar1,
            (double)rge_base_game->world->game_speed);
    uVar8 = 0x20;
  }
  else {
    iVar5 = param_1->clock_type;
    iVar7 = ((param_1->game_time + 4) / 5) * 5;
    if (iVar5 == 4) {
      iVar5 = 0x2c25;
LAB_0051df07:
      pcVar3 = TPanel::get_string((TPanel *)param_1,iVar5);
      uVar9 = CONCAT44(iVar7,pcVar3);
    }
    else if (iVar5 == 5) {
      pcVar3 = TPanel::get_string((TPanel *)param_1,0x2c26);
      uVar9 = CONCAT44(iVar7,pcVar3);
    }
    else {
      if (iVar5 != 6) {
        iVar5 = 0x2c24;
        goto LAB_0051df07;
      }
      pcVar3 = TPanel::get_string((TPanel *)param_1,0x2c27);
      uVar9 = CONCAT44(iVar7,pcVar3);
    }
    sprintf(auStack_104,uVar9);
    uVar8 = 0x22;
  }
  SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->color2);
  iVar5 = param_1->_padding_;
  iVar7 = param_1->_padding_;
  iVar6 = param_1->_padding_ + -2 + iVar7 + 1;
  iVar4 = param_1->_padding_ + -2 + iVar5 + 1;
  iStack_118 = iVar6 + -2;
  iStack_10c = iVar4 + -2;
  SetRect(auStack_128,iVar5,iVar7,iStack_10c,iStack_118);
  DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_128,uVar8);
  iStack_110 = iVar7 + 2;
  SetRect(auStack_128,iVar5,iStack_110,iStack_10c,iVar6);
  DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_128,uVar8);
  SetRect(auStack_128,iVar5 + 2,iVar7,iVar4,iStack_118);
  DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_128,uVar8);
  SetRect(auStack_128,iVar5 + 2,iStack_110,iVar4,iVar6);
  DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_128,uVar8);
  SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->color1);
  SetRect(auStack_128,iVar5 + 1,iVar7 + 1,iVar4 + -1,iVar6 + -1);
  DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),auStack_104,0xffffffff,auStack_128,uVar8);
  SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),uStack_108);
  SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),0);
  TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_tpnl_tim__draw);
  iVar5 = iStack_114;
LAB_0051e0ce:
  (**(code **)(iVar5 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0051e0de
// Address: 0051e0de
void __thiscall FUN_0051e0de(int param_1,undefined4 *param_2)
{
  if ((((*(int *)(param_1 + 0x134) != 0) && (*(int *)(param_1 + 0x20) != 0)) &&
      (*(int *)(param_1 + 0x70) != 0)) && (*(int *)(param_1 + 0x6c) != 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x158);
    param_2[1] = *(undefined4 *)(param_1 + 0x15c);
    param_2[2] = *(undefined4 *)(param_1 + 0x160);
    param_2[3] = *(undefined4 *)(param_1 + 0x164);
    return;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x8c);
  param_2[1] = *(undefined4 *)(param_1 + 0x90);
  param_2[2] = *(undefined4 *)(param_1 + 0x94);
  param_2[3] = *(undefined4 *)(param_1 + 0x98);
  return;
}

// --------------------------------------------------

// Function: FUN_0051e145
// Address: 0051e145
undefined4 __fastcall FUN_0051e145(TPanel *param_1)
{
  int iVar1;
  ulong uVar2;
  long lVar3;
  TPanel *pTStack_4;
  
  pTStack_4 = param_1;
  TPanel::handle_idle(param_1);
  switch(param_1[1].pnl_x) {
  case 0:
    goto switchD_0051e168_caseD_0;
  case 1:
    uVar2 = debug_timeGetTime(&s_C__msdev_work_age1_x1_tpnl_tim_c,0x18a);
    param_1[1].clip_rect.right = (uVar2 - param_1[1].clip_rect.top) / 1000;
    break;
  case 2:
    param_1[1].clip_rect.right = (uint)(param_1[1].render_area)->Wnd / 1000;
    break;
  case 3:
    lVar3 = __ftol();
    param_1[1].clip_rect.right = lVar3;
    break;
  case 4:
    iVar1 = param_1[1].clip_rect.left;
    if (iVar1 == 0) {
LAB_0051e255:
      param_1[1].clip_rect.right = 0;
    }
    else {
      RGE_Base_Game::get_countdown_timer
                (rge_base_game,(int)*(short *)(iVar1 + 0x4a),(long *)&pTStack_4);
      param_1[1].clip_rect.right = (long)pTStack_4;
    }
    break;
  case 5:
    iVar1 = param_1[1].clip_rect.left;
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x844) == -0x40800000)) goto LAB_0051e255;
    lVar3 = __ftol();
    param_1[1].clip_rect.right = lVar3;
    break;
  case 6:
    iVar1 = param_1[1].clip_rect.left;
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x840) == -0x40800000)) goto LAB_0051e255;
    lVar3 = __ftol();
    param_1[1].clip_rect.right = lVar3;
  }
  if (param_1[1].clip_rect.right != param_1[1].clip_rect.bottom) {
    (**(code **)(param_1->_padding_ + 0x20))(1);
    (**(code **)(param_1->parent_panel->_padding_ + 0x20))(1);
    param_1[1].clip_rect.bottom = param_1[1].clip_rect.right;
  }
switchD_0051e168_caseD_0:
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051e293
// Address: 0051e293
// [HELPER] s__02ld__02ld__02ld___3_1f_: "%02ld:%02ld:%02ld (%3.1f)"
// [HELPER] s_tpnl_tim__render_to_image_buffer: "tpnl_tim::render_to_image_buffer"
/* WARNING: Instruction at (ram,0x0051e2fc) overlaps instruction at (ram,0x0051e2f9)
    */

int * __fastcall FUN_0051e293(int param_1,undefined1 *param_2)
{
  TPanel *pTVar1;
  char cVar2;
  int *in_EAX;
  void *pvVar4;
  undefined4 uVar5;
  char *pcVar6;
  PanelNode *pPVar7;
  int iVar8;
  TPanel *pTVar9;
  char *unaff_EBX;
  int iVar10;
  TPanel *unaff_ESI;
  tagRECT *unaff_EDI;
  int iVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  int iStack_4;
  int *piVar3;
  
  pcVar6 = (char *)((int)&unaff_EDI[-2].left + 1);
  *pcVar6 = *pcVar6 + (char)((uint)param_1 >> 8);
  pcVar6 = (char *)((int)in_EAX + -0x43ffae1f);
  *pcVar6 = *pcVar6 + (char)((uint)in_EAX >> 8);
  if (param_1 != 1 && *pcVar6 == '\0') {
    return in_EAX;
  }
  cVar2 = (char)in_EAX + (char)unaff_EBX;
  piVar3 = (int *)CONCAT31((int3)((uint)in_EAX >> 8),cVar2);
  if (param_1 != 2 && cVar2 == '\0') {
    return piVar3;
  }
  *unaff_EBX = *unaff_EBX + cVar2;
  iStack_4 = param_1;
  if (param_1 == 3) {
    *param_2 = *param_2;
    cRam000114ec = cRam000114ec + cVar2;
    unaff_EBX[0x55] = unaff_EBX[0x55] + (char)param_2;
    if (pTRam00000134 == (TDrawArea *)0x0) {
      return (int *)0x0;
    }
    unaff_EDI = (tagRECT *)0x138;
    TDrawArea::PtrClear(pTRam00000134,(tagRECT *)0x138,1);
    pvVar4 = TDrawArea::GetDc(pTRam00000134,s_tpnl_tim__render_to_image_buffer);
    unaff_ESI = (TPanel *)0x0;
    if (pvVar4 == (void *)0x0) {
      return (int *)0x0;
    }
  }
  else {
    *piVar3 = *piVar3 + (int)piVar3;
  }
  TDrawArea::SetClipRect((TDrawArea *)unaff_ESI[1].parent_panel,unaff_EDI);
  SelectClipRgn((unaff_ESI[1].parent_panel)->need_redraw,unaff_ESI[1].curr_child);
  uVar5 = SelectObject((unaff_ESI[1].parent_panel)->need_redraw,unaff_ESI[1]._padding_);
  SetBkMode((unaff_ESI[1].parent_panel)->need_redraw,1);
  if (unaff_ESI[1].pnl_wid == 1) {
    iVar11 = unaff_ESI[1].clip_rect.right;
    iVar8 = 0;
    iVar10 = 0;
    if (0x3b < iVar11) {
      iVar8 = iVar11 / 0x3c;
      iVar11 = iVar11 % 0x3c;
      if (0x3b < iVar8) {
        iVar10 = iVar8 / 0x3c;
        iVar8 = iVar8 % 0x3c;
      }
    }
    sprintf(&stack0x00000010,s__02ld__02ld__02ld___3_1f_,iVar10,iVar8,iVar11,
            (double)rge_base_game->world->game_speed);
    uVar12 = 0x20;
    goto LAB_0051e459;
  }
  iVar11 = unaff_ESI[1].pnl_x;
  iVar8 = ((unaff_ESI[1].clip_rect.right + 4U) / 5) * 5;
  if (iVar11 == 4) {
    iVar11 = 0x2c25;
LAB_0051e43f:
    pcVar6 = TPanel::get_string(unaff_ESI,iVar11);
    uVar13 = CONCAT44(iVar8,pcVar6);
  }
  else if (iVar11 == 5) {
    pcVar6 = TPanel::get_string(unaff_ESI,0x2c26);
    uVar13 = CONCAT44(iVar8,pcVar6);
  }
  else {
    if (iVar11 != 6) {
      iVar11 = 0x2c24;
      goto LAB_0051e43f;
    }
    pcVar6 = TPanel::get_string(unaff_ESI,0x2c27);
    uVar13 = CONCAT44(iVar8,pcVar6);
  }
  sprintf(&stack0x00000010,uVar13);
  uVar12 = 0x22;
LAB_0051e459:
  SetTextColor((unaff_ESI[1].parent_panel)->need_redraw,unaff_ESI[1].previousModalPanelValue);
  iVar11 = unaff_ESI->pnl_wid;
  iVar8 = unaff_ESI->pnl_hgt;
  SetRect(&iStack_4,0,0,iVar11 + -3,iVar8 + -3);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SetRect(&iStack_4,0,2,iVar11 + -3,iVar8 + -1);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SetRect(&iStack_4,2,0,iVar11 + -1,iVar8 + -3);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SetRect(&iStack_4,2,2,iVar11 + -1,iVar8 + -1);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SetTextColor((unaff_ESI[1].parent_panel)->need_redraw,unaff_ESI[1].previousPanelValue);
  SetRect(&iStack_4,1,1,iVar11 + -2,iVar8 + -2);
  DrawTextA((unaff_ESI[1].parent_panel)->need_redraw,&stack0x00000010,0xffffffff,&iStack_4,uVar12);
  SelectObject((unaff_ESI[1].parent_panel)->need_redraw,uVar5);
  SelectClipRgn((unaff_ESI[1].parent_panel)->need_redraw,0);
  TDrawArea::ReleaseDc((TDrawArea *)unaff_ESI[1].parent_panel,s_tpnl_tim__render_to_image_buffer);
  iVar11 = unaff_ESI->pnl_wid;
  pTVar1 = (TPanel *)(unaff_ESI->render_rect).left;
  iVar8 = unaff_ESI->pnl_hgt;
  unaff_ESI[1].node = (PanelNode *)0x0;
  unaff_ESI[1].first_child_node = (PanelNode *)0x0;
  iVar10 = (unaff_ESI->render_rect).top;
  pPVar7 = (PanelNode *)(iVar11 + -1);
  unaff_ESI[1].tab_next_panel = pTVar1;
  pTVar9 = (TPanel *)(iVar8 + -1);
  unaff_ESI[1].mouse_captured = iVar10;
  unaff_ESI[1].last_child_node = pPVar7;
  unaff_ESI[1].tab_prev_panel = pTVar9;
  unaff_ESI[1].active = (int)pTVar1 + (int)pPVar7;
  unaff_ESI[1].visible = (int)&pTVar9->_padding_ + iVar10;
  unaff_ESI[1].need_redraw = unaff_ESI[1].position_mode;
  unaff_ESI[1].pnl_y = unaff_ESI[1].pnl_x;
  unaff_ESI[1].pnl_hgt = unaff_ESI[1].pnl_wid;
  unaff_ESI[1].tab_stop = 1;
  return (int *)0x1;
}

// --------------------------------------------------

// Function: FUN_0051e644
// Address: 0051e644
TEasy_Panel * __fastcall FUN_0051e644(TEasy_Panel *param_1)
{
  TEasy_Panel::TEasy_Panel(param_1);
  param_1[1]._padding_ = 2;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0xffffff;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0xffff;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *(undefined2 *)&param_1[1]._padding_ = 0;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0;
  param_1[1]._padding_ = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0xff;
  param_1[1]._padding_ = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  *(undefined1 *)((int)&param_1[1]._padding_ + 1) = 0;
  *(undefined1 *)((int)&param_1[1]._padding_ + 2) = 0;
  *(undefined1 *)((int)&param_1[1]._padding_ + 3) = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  *(undefined1 *)((int)&param_1[1]._padding_ + 1) = 0;
  param_1[1]._padding_ = 0;
  *(undefined2 *)&param_1[1]._padding_ = 0;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&Time_Line_Panel::_vftable_;
  param_1->_padding_ = 0;
  *(undefined1 *)&param_1[1]._padding_ = 1;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0xc;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051e764
// Address: 0051e764
Time_Line_Panel * __thiscall FUN_0051e764(Time_Line_Panel *param_1,byte param_2)
{
  Time_Line_Panel::~Time_Line_Panel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0051e78e
// Address: 0051e78e
void __fastcall FUN_0051e78e(TEasy_Panel *param_1)
{
  TShape *pTVar1;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561468;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&Time_Line_Panel::_vftable_;
  iVar2 = param_1[1]._padding_;
  uStack_4 = 0;
  while (iVar2 != 0) {
    param_1[1]._padding_ = *(int *)(iVar2 + 0xac);
    free(iVar2);
    iVar2 = param_1[1]._padding_;
  }
  pTVar1 = (TShape *)param_1[1]._padding_;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    param_1[1]._padding_ = 0;
  }
  pTVar1 = (TShape *)param_1[1]._padding_;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    param_1[1]._padding_ = 0;
  }
  piVar3 = &param_1[1]._padding_;
  iVar2 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar3);
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  uStack_4 = 0xffffffff;
  TEasy_Panel::~TEasy_Panel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0051e85e
// Address: 0051e85e
undefined4 __thiscall
FUN_0051e85e(int param_1,TPanel *param_2,int *param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10,int param_11)
{
  long lVar1;
  int iVar2;
  int iVar3;
  Time_Line_Panel *this;
  int iVar4;
  RGE_Font *pRVar5;
  RGE_Font *pRVar6;
  TDrawArea *pTVar7;
  undefined4 uVar8;
  undefined4 *unaff_FS_OFFSET;
  void *pvVar9;
  long lVar10;
  long lVar11;
  void *pvVar12;
  long lVar13;
  char *pcVar14;
  char *pcVar15;
  uchar uVar16;
  int iVar17;
  uchar uVar18;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056148b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  lVar1 = TPanel::width(param_2);
  iVar2 = (lVar1 * param_4) / param_10;
  lVar1 = TPanel::height(param_2);
  iVar3 = (lVar1 * param_5) / param_11;
  lVar1 = TPanel::width(param_2);
  param_10 = (lVar1 * param_6) / param_10;
  lVar1 = TPanel::height(param_2);
  param_11 = (lVar1 * param_7) / param_11;
  this = (Time_Line_Panel *)operator_new(0x52c);
  uStack_4 = 0;
  if (this == (Time_Line_Panel *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = Time_Line_Panel::Time_Line_Panel(this);
  }
  uStack_4 = 0xffffffff;
  *param_3 = iVar4;
  if ((iVar4 == 0) || (*(int *)(iVar4 + 0xd8) != 0)) {
    *(undefined4 *)(param_1 + 0xd8) = 1;
  }
  else {
    if (param_8 < 0) {
      param_8 = 0xb;
    }
    pRVar5 = RGE_Base_Game::get_font(rge_base_game,param_8);
    if (param_9 < 0) {
      param_9 = 0xb;
    }
    pRVar6 = RGE_Base_Game::get_font(rge_base_game,param_9);
    lVar1 = pRVar6->font_hgt;
    lVar13 = pRVar6->font_wid;
    uVar18 = '\0';
    iVar17 = 0;
    uVar16 = '\0';
    iVar4 = 0;
    pcVar15 = (char *)0x0;
    pcVar14 = (char *)0x0;
    pvVar12 = pRVar6->font;
    lVar11 = pRVar5->font_hgt;
    lVar10 = pRVar5->font_wid;
    pvVar9 = pRVar5->font;
    pTVar7 = TPanel::renderArea(param_2);
    lVar1 = Time_Line_Panel::setup
                      ((Time_Line_Panel *)*param_3,pTVar7,param_2,iVar2,iVar3,param_10,param_11,
                       pvVar9,lVar10,lVar11,pvVar12,lVar13,lVar1,pcVar14,pcVar15,iVar4,uVar16,iVar17
                       ,uVar18);
    if (lVar1 != 0) {
      Time_Line_Panel::init_timeline((Time_Line_Panel *)*param_3);
      uVar8 = 1;
      goto LAB_0051e9c4;
    }
    *(undefined4 *)(param_1 + 0xd8) = 1;
  }
  uVar8 = 0;
LAB_0051e9c4:
  *unaff_FS_OFFSET = uStack_c;
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_0051e9d9
// Address: 0051e9d9
undefined4 __thiscall
FUN_0051e9d9(Time_Line_Panel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,void *param_8,long param_9,long param_10,void *param_11,
            long param_12,long param_13,char *param_14,char *param_15,int param_16,uchar param_17,
            int param_18,uchar param_19)
{
  uchar uVar1;
  
  TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6,param_7,'\0');
  param_1->fill_back = param_16;
  param_1->back_color = param_17;
  param_1->outline = param_18;
  param_1->outline_color = param_19;
  if (param_18 != 0) {
    param_1->bevel_type = 1;
  }
  Time_Line_Panel::set_axis_font(param_1,param_8,param_9,param_10);
  Time_Line_Panel::set_body_font(param_1,param_11,param_12,param_13);
  Time_Line_Panel::set_background(param_1,param_14);
  Time_Line_Panel::set_special_events(param_1,param_15);
  uVar1 = GetNearestPaletteIndex(*(undefined4 *)(*(int *)param_1->_padding_ + 8),0);
  Time_Line_Panel::set_back_color(param_1,1,uVar1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0051eaf9
// Address: 0051eaf9
undefined4 __thiscall FUN_0051eaf9(int param_1,char *param_2)
{
  TShape *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  short asStack_1c [2];
  short asStack_18 [2];
  short asStack_14 [2];
  short asStack_10 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005614ab;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = *(TShape **)(param_1 + 0x4ac);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0x4ac) = 0;
    *(undefined2 *)(param_1 + 0x4b0) = 0;
    *(undefined2 *)(param_1 + 0x4b2) = 0;
  }
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    pTVar1 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTVar1 == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape(pTVar1,param_2,-1);
    }
    uStack_4 = 0xffffffff;
    *(TShape **)(param_1 + 0x4ac) = pTVar1;
    TShape::shape_minmax
              (pTVar1,(long *)asStack_18,(long *)asStack_10,(long *)asStack_1c,(long *)asStack_14,0)
    ;
    *(short *)(param_1 + 0x4b0) = (asStack_1c[0] - asStack_18[0]) + 1;
    *(short *)(param_1 + 0x4b2) = (asStack_14[0] - asStack_10[0]) + 1;
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051ec02
// Address: 0051ec02
// [HELPER] s_: ""
// [HELPER] s__s: "%s"
// [HELPER] s__s_shp: "%s.shp"
// [HELPER] s_none: "none"
bool __thiscall FUN_0051ec02(int param_1,char *param_2,int param_3)
{
  TShape *pTVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar4;
  short asStack_124 [2];
  short asStack_120 [2];
  short asStack_11c [2];
  TShape *pTStack_118;
  short asStack_114 [2];
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005614dc;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = *(TShape **)(param_1 + 0x4ac);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0x4ac) = 0;
    *(undefined2 *)(param_1 + 0x4b0) = 0;
    *(undefined2 *)(param_1 + 0x4b2) = 0;
  }
  if (((param_2 == (char *)0x0) || (*param_2 == '\0')) ||
     (iVar2 = stricmp(param_2,s_none), iVar2 == 0)) {
    if (param_3 == -1) goto LAB_0051ed29;
    pTStack_118 = (TShape *)operator_new(0x20);
    uStack_4 = 1;
    if (pTStack_118 == (TShape *)0x0) goto LAB_0051ed16;
    uVar3 = TShape::TShape(pTStack_118,s_,param_3);
  }
  else {
    iVar2 = strchr(param_2,0x2e);
    if (iVar2 == 0) {
      pcVar4 = s__s_shp;
    }
    else {
      pcVar4 = s__s;
    }
    sprintf(acStack_110,pcVar4,param_2);
    pTStack_118 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTStack_118 == (TShape *)0x0) {
LAB_0051ed16:
      uVar3 = 0;
    }
    else {
      uVar3 = TShape::TShape(pTStack_118,acStack_110,param_3);
    }
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x4ac) = uVar3;
LAB_0051ed29:
  if ((*(TShape **)(param_1 + 0x4ac) != (TShape *)0x0) &&
     (iVar2 = TShape::is_loaded(*(TShape **)(param_1 + 0x4ac)), iVar2 == 0)) {
    pTVar1 = *(TShape **)(param_1 + 0x4ac);
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
    }
    *(undefined4 *)(param_1 + 0x4ac) = 0;
  }
  pTVar1 = *(TShape **)(param_1 + 0x4ac);
  if (pTVar1 != (TShape *)0x0) {
    TShape::shape_minmax
              (pTVar1,(long *)asStack_11c,(long *)asStack_120,(long *)asStack_114,
               (long *)asStack_124,0);
    *(short *)(param_1 + 0x4b0) = (asStack_114[0] - asStack_11c[0]) + 1;
    *(short *)(param_1 + 0x4b2) = (asStack_124[0] - asStack_120[0]) + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return pTVar1 != (TShape *)0x0;
}

// --------------------------------------------------

// Function: FUN_0051edc7
// Address: 0051edc7
undefined4 __thiscall FUN_0051edc7(int param_1,char *param_2)
{
  TShape *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  short asStack_1c [2];
  short asStack_18 [2];
  short asStack_14 [2];
  short asStack_10 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005614fb;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = *(TShape **)(param_1 + 0x4d4);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0x4d4) = 0;
    *(undefined2 *)(param_1 + 0x4d8) = 0;
    *(undefined2 *)(param_1 + 0x4da) = 0;
  }
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    pTVar1 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTVar1 == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape(pTVar1,param_2,-1);
    }
    uStack_4 = 0xffffffff;
    *(TShape **)(param_1 + 0x4d4) = pTVar1;
    TShape::shape_minmax
              (pTVar1,(long *)asStack_18,(long *)asStack_10,(long *)asStack_1c,(long *)asStack_14,0)
    ;
    *(short *)(param_1 + 0x4d8) = (asStack_1c[0] - asStack_18[0]) + 1;
    *(short *)(param_1 + 0x4da) = (asStack_14[0] - asStack_10[0]) + 1;
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0051eed2
// Address: 0051eed2
// [HELPER] s_: ""
// [HELPER] s__s: "%s"
// [HELPER] s__s_shp: "%s.shp"
// [HELPER] s_none: "none"
bool __thiscall FUN_0051eed2(int param_1,char *param_2,int param_3)
{
  TShape *pTVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar4;
  short asStack_124 [2];
  short asStack_120 [2];
  short asStack_11c [2];
  TShape *pTStack_118;
  short asStack_114 [2];
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056152c;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = *(TShape **)(param_1 + 0x4d4);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0x4d4) = 0;
    *(undefined2 *)(param_1 + 0x4d8) = 0;
    *(undefined2 *)(param_1 + 0x4da) = 0;
  }
  if (((param_2 == (char *)0x0) || (*param_2 == '\0')) ||
     (iVar2 = stricmp(param_2,s_none), iVar2 == 0)) {
    if (param_3 == -1) goto LAB_0051eff9;
    pTStack_118 = (TShape *)operator_new(0x20);
    uStack_4 = 1;
    if (pTStack_118 == (TShape *)0x0) goto LAB_0051efe6;
    uVar3 = TShape::TShape(pTStack_118,s_,param_3);
  }
  else {
    iVar2 = strchr(param_2,0x2e);
    if (iVar2 == 0) {
      pcVar4 = s__s_shp;
    }
    else {
      pcVar4 = s__s;
    }
    sprintf(acStack_110,pcVar4,param_2);
    pTStack_118 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTStack_118 == (TShape *)0x0) {
LAB_0051efe6:
      uVar3 = 0;
    }
    else {
      uVar3 = TShape::TShape(pTStack_118,acStack_110,param_3);
    }
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x4d4) = uVar3;
LAB_0051eff9:
  if ((*(TShape **)(param_1 + 0x4d4) != (TShape *)0x0) &&
     (iVar2 = TShape::is_loaded(*(TShape **)(param_1 + 0x4d4)), iVar2 == 0)) {
    pTVar1 = *(TShape **)(param_1 + 0x4d4);
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
    }
    *(undefined4 *)(param_1 + 0x4d4) = 0;
  }
  pTVar1 = *(TShape **)(param_1 + 0x4d4);
  if (pTVar1 != (TShape *)0x0) {
    TShape::shape_minmax
              (pTVar1,(long *)asStack_11c,(long *)asStack_120,(long *)asStack_114,
               (long *)asStack_124,0);
    *(short *)(param_1 + 0x4d8) = (asStack_114[0] - asStack_11c[0]) + 1;
    *(short *)(param_1 + 0x4da) = (asStack_124[0] - asStack_120[0]) + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return pTVar1 != (TShape *)0x0;
}

// --------------------------------------------------

// Function: FUN_0051f097
// Address: 0051f097
void __thiscall FUN_0051f097(int *param_1,int param_2,int param_3,int param_4)
{
  param_1[0x11e] = param_2;
  param_1[0x11f] = param_3;
  param_1[0x120] = param_4;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051f0c8
// Address: 0051f0c8
void __thiscall FUN_0051f0c8(int *param_1,int param_2,int param_3,int param_4)
{
  param_1[0x121] = param_2;
  param_1[0x122] = param_3;
  param_1[0x123] = param_4;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0051f0f8
// Address: 0051f0f8
void __thiscall FUN_0051f0f8(int param_1,undefined4 param_2,undefined1 param_3)
{
  *(undefined4 *)(param_1 + 0x4b4) = param_2;
  *(undefined1 *)(param_1 + 0x4b8) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0051f117
// Address: 0051f117
// [HELPER] s_tpnl_tml__draw_border: "tpnl_tml::draw_border"
void __fastcall FUN_0051f117(int param_1)
{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uchar uVar6;
  uchar *puVar7;
  int iVar8;
  int iVar9;
  
  if (*(int *)(param_1 + 0x4c8) == 0) {
    return;
  }
  puVar7 = TDrawArea::Lock(*(TDrawArea **)(param_1 + 0x20),s_tpnl_tml__draw_border,1);
  if (puVar7 == (uchar *)0x0) goto switchD_0051f158_default;
  switch(*(undefined4 *)(param_1 + 0x4c8)) {
  case 1:
    TDrawArea::DrawRect(*(TDrawArea **)(param_1 + 0x20),*(int *)(param_1 + 0xc),
                        *(int *)(param_1 + 0x10),
                        *(int *)(param_1 + 0x14) + -1 + *(int *)(param_1 + 0xc),
                        *(int *)(param_1 + 0x18) + -1 + *(int *)(param_1 + 0x10),
                        *(uchar *)(param_1 + 0x4c0));
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_tpnl_tml__draw_border);
    return;
  case 2:
    uVar1 = *(uchar *)(param_1 + 0x4cc);
    iVar8 = *(int *)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar2 = *(uchar *)(param_1 + 0x4d1);
    goto LAB_0051f217;
  case 3:
    uVar1 = *(uchar *)(param_1 + 0x4cc);
    iVar8 = *(int *)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar2 = *(uchar *)(param_1 + 0x4cd);
    uVar3 = *(uchar *)(param_1 + 0x4d0);
    uVar4 = *(uchar *)(param_1 + 0x4d1);
    goto LAB_0051f262;
  case 4:
    uVar1 = *(uchar *)(param_1 + 0x4cc);
    iVar8 = *(int *)(param_1 + 0x10);
    uVar2 = *(uchar *)(param_1 + 0x4cd);
    uVar3 = *(uchar *)(param_1 + 0x4ce);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar4 = *(uchar *)(param_1 + 0x4cf);
    uVar5 = *(uchar *)(param_1 + 0x4d0);
    uVar6 = *(uchar *)(param_1 + 0x4d1);
    break;
  case 5:
    uVar1 = *(uchar *)(param_1 + 0x4d1);
    iVar8 = *(int *)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar2 = *(uchar *)(param_1 + 0x4cc);
LAB_0051f217:
    TDrawArea::DrawBevel
              (*(TDrawArea **)(param_1 + 0x20),iVar9,iVar8,*(int *)(param_1 + 0x14) + -1 + iVar9,
               *(int *)(param_1 + 0x18) + -1 + iVar8,uVar2,uVar1);
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_tpnl_tml__draw_border);
    return;
  case 6:
    uVar1 = *(uchar *)(param_1 + 0x4d1);
    iVar8 = *(int *)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar2 = *(uchar *)(param_1 + 0x4d0);
    uVar3 = *(uchar *)(param_1 + 0x4cd);
    uVar4 = *(uchar *)(param_1 + 0x4cc);
LAB_0051f262:
    TDrawArea::DrawBevel2
              (*(TDrawArea **)(param_1 + 0x20),iVar9,iVar8,*(int *)(param_1 + 0x14) + -1 + iVar9,
               *(int *)(param_1 + 0x18) + -1 + iVar8,uVar4,uVar3,uVar2,uVar1);
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_tpnl_tml__draw_border);
    return;
  case 7:
    uVar1 = *(uchar *)(param_1 + 0x4d1);
    iVar8 = *(int *)(param_1 + 0x10);
    uVar2 = *(uchar *)(param_1 + 0x4d0);
    uVar3 = *(uchar *)(param_1 + 0x4cf);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar4 = *(uchar *)(param_1 + 0x4ce);
    uVar5 = *(uchar *)(param_1 + 0x4cd);
    uVar6 = *(uchar *)(param_1 + 0x4cc);
    break;
  default:
    goto switchD_0051f158_default;
  }
  TDrawArea::DrawBevel3
            (*(TDrawArea **)(param_1 + 0x20),iVar9,iVar8,*(int *)(param_1 + 0x14) + -1 + iVar9,
             *(int *)(param_1 + 0x18) + -1 + iVar8,uVar6,uVar5,uVar4,uVar3,uVar2,uVar1);
switchD_0051f158_default:
  TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_tpnl_tml__draw_border);
  return;
}

// --------------------------------------------------

// Function: FUN_0051f2e5
// Address: 0051f2e5
void FUN_0051f2e5(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_0051f4d7
// Address: 0051f4d7
void __thiscall
FUN_0051f4d7(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)calloc(1,0xb0);
  *puVar1 = param_2;
  puVar1[1] = param_4;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  *(undefined1 *)(puVar1 + 0xf) = 0;
  puVar1[0x1c] = 0;
  *(undefined1 *)(puVar1 + 0x1d) = 0;
  *(undefined1 *)((int)puVar1 + 0x12) = 3;
  puVar1[5] = param_3;
  puVar1[0x2a] = param_5;
  puVar1[0x2b] = *(undefined4 *)(param_1 + 0x518);
  *(undefined4 **)(param_1 + 0x518) = puVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0051f55c
// Address: 0051f55c
void __thiscall
FUN_0051f55c(int param_1,undefined1 param_2,TRIBE_History_Info *param_3,undefined1 param_4,
            long param_5,long param_6,long param_7,long param_8)
{
  long lVar1;
  uchar uVar2;
  long *plVar3;
  
  lVar1 = param_5;
  uVar2 = TRIBE_History_Info::get_history_event(param_3,param_5,(uchar *)&param_5);
  if (uVar2 != '\0') {
    plVar3 = (long *)calloc(1,0xb0);
    plVar3[1] = param_6;
    plVar3[2] = param_7;
    plVar3[3] = param_8;
    *plVar3 = lVar1;
    *(undefined1 *)(plVar3 + 4) = param_2;
    *(undefined1 *)((int)plVar3 + 0x11) = param_4;
    *(uchar *)((int)plVar3 + 0x12) = (uchar)param_5;
    plVar3[5] = 0;
    plVar3[6] = 0;
    plVar3[7] = 0;
    plVar3[8] = 0;
    plVar3[9] = 0;
    plVar3[10] = 0;
    plVar3[0xb] = 0;
    plVar3[0xc] = 0;
    plVar3[0xd] = 0;
    plVar3[0xe] = 0;
    *(undefined1 *)(plVar3 + 0xf) = 0;
    plVar3[0x1c] = 0;
    *(undefined1 *)(plVar3 + 0x1d) = 0;
    plVar3[0x2a] = 0;
    plVar3[0x2b] = *(long *)(param_1 + 0x518);
    *(long **)(param_1 + 0x518) = plVar3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051f5fc
// Address: 0051f5fc
void __thiscall FUN_0051f5fc(int param_1,int param_2,undefined4 param_3)
{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  short sStack_12;
  uint uStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar2 = param_2;
  iVar8 = 0;
  *(undefined4 *)(param_2 + 0xa8) = 0;
  iStack_4 = 0;
  iStack_8 = 0;
  iStack_c = 0;
  uStack_10 = (uint)(*(TShape **)(param_1 + 0x4d4) != (TShape *)0x0);
  lVar3 = TShape::shape_count(*(TShape **)(param_1 + 0x4d4));
  if (lVar3 == 0) {
    uStack_10 = 0;
  }
  iVar6 = (int)(short)param_3;
  lVar3 = TShape::shape_count(*(TShape **)(param_1 + 0x4d4));
  if (lVar3 < iVar6) {
    uStack_10 = 0;
  }
  if (uStack_10 != 0) {
    TShape::shape_bounds(*(TShape **)(param_1 + 0x4d4),iVar6,(short *)&param_2,&sStack_12);
    if (0 < (short)param_2) {
      *(short *)(param_1 + 0x4d8) = (short)param_2;
    }
    if (0 < sStack_12) {
      *(short *)(param_1 + 0x4da) = sStack_12;
    }
    if (uStack_10 != 0) {
      if (*(int *)(iVar2 + 0xc) < (int)*(short *)(param_1 + 0x4da)) {
        uStack_10 = 0;
      }
      iVar6 = (int)*(short *)(param_1 + 0x4d8) / 2;
      if (*(int *)(param_1 + 0x4ec) + *(int *)(param_1 + 0x4dc) < *(int *)(iVar2 + 4) + iVar6) {
        uStack_10 = 0;
      }
      iVar6 = *(int *)(iVar2 + 4) - iVar6;
      if (iVar6 < *(int *)(param_1 + 0x4dc)) {
        uStack_10 = 0;
      }
      if (uStack_10 != 0) {
        iStack_8 = (*(int *)(iVar2 + 0xc) / 2 + *(int *)(iVar2 + 8) * 2) -
                   (int)*(short *)(param_1 + 0x4da) / 2;
        iStack_4 = iVar6;
      }
    }
  }
  switch(*(undefined1 *)(iVar2 + 0x12)) {
  case 0:
    uVar5 = 0xffffffff;
    pcVar9 = (char *)(iVar2 + 0x3c);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    *(uint *)(iVar2 + 0x38) = ~uVar5 - 1;
    iVar8 = *(int *)(param_1 + 0x488) * (~uVar5 - 1);
    if (iVar8 + 2 + *(int *)(iVar2 + 4) < *(int *)(param_1 + 0x4ec) + *(int *)(param_1 + 0x4dc)) {
      iStack_c = *(int *)(iVar2 + 4) + 2;
    }
    else {
      iStack_c = (*(int *)(param_1 + 0x4ec) - iVar8) + -3 + *(int *)(param_1 + 0x4dc);
    }
    iVar6 = *(int *)(param_1 + 0x48c);
    iVar8 = (*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc)) - iVar6;
    break;
  case 1:
    uVar5 = 0xffffffff;
    pcVar9 = (char *)(iVar2 + 0x3c);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    *(uint *)(iVar2 + 0x38) = ~uVar5 - 1;
    iVar8 = *(int *)(param_1 + 0x488) * (~uVar5 - 1);
    if (iVar8 + 2 + *(int *)(iVar2 + 4) < *(int *)(param_1 + 0x4ec) + *(int *)(param_1 + 0x4dc)) {
      iStack_c = *(int *)(iVar2 + 4) + 2;
    }
    else {
      iStack_c = (*(int *)(param_1 + 0x4ec) - iVar8) + -8 + *(int *)(param_1 + 0x4dc);
    }
    iVar4 = *(int *)(iVar2 + 8);
    iVar8 = *(int *)(param_1 + 0x4e0) + *(int *)(param_1 + 0x4f0);
    if (iVar8 <= *(int *)(param_1 + 0x48c) + 2 + iVar4) {
      iVar8 = (iVar8 - *(int *)(param_1 + 0x48c)) + -2;
      goto switchD_0051f73e_caseD_3;
    }
    goto LAB_0051f87c;
  case 2:
    uVar5 = 0xffffffff;
    pcVar9 = (char *)(iVar2 + 0x3c);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    *(uint *)(iVar2 + 0x38) = ~uVar5 - 1;
    iVar8 = *(int *)(param_1 + 0x488) * (~uVar5 - 1);
    if (iVar8 + 2 + *(int *)(iVar2 + 4) < *(int *)(param_1 + 0x4ec) + *(int *)(param_1 + 0x4dc)) {
      iStack_c = *(int *)(iVar2 + 4) + 2;
    }
    else {
      iStack_c = (*(int *)(param_1 + 0x4ec) - iVar8) + -3 + *(int *)(param_1 + 0x4dc);
    }
    iVar6 = *(int *)(param_1 + 0x48c);
    iVar8 = (*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc)) - iVar6;
    break;
  default:
    goto switchD_0051f73e_caseD_3;
  case 6:
    iVar8 = *(int *)(param_1 + 0x4dc) + *(int *)(param_1 + 0x4ec);
    uVar5 = 0xffffffff;
    pcVar9 = (char *)(iVar2 + 0x3c);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (iVar8 < (int)((~uVar5 - 1) * *(int *)(param_1 + 0x488) + *(int *)(iVar2 + 4))) {
      *(int *)(iVar2 + 0x38) = (iVar8 - *(int *)(iVar2 + 4)) / *(int *)(param_1 + 0x488);
    }
    else {
      uVar5 = 0xffffffff;
      pcVar9 = (char *)(iVar2 + 0x3c);
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      *(uint *)(iVar2 + 0x38) = ~uVar5 - 1;
    }
    if (2 < *(int *)(iVar2 + 0x38)) {
      *(undefined4 *)(iVar2 + 0x38) = 2;
    }
    iVar8 = (int)*(short *)(param_1 + 0x4da);
    iVar6 = *(int *)(param_1 + 0x48c);
    iVar4 = *(int *)(param_1 + 0x4f0);
    iVar7 = *(int *)(param_1 + 0x4e0);
    if (iVar4 + iVar7 < iStack_8 + iVar6 + 1 + iVar8) {
LAB_0051f9bc:
      iStack_8 = ((iVar4 - iVar6) - iVar8) + -1 + iVar7;
    }
    goto LAB_0051f9c8;
  case 8:
    iVar8 = *(int *)(param_1 + 0x4dc) + *(int *)(param_1 + 0x4ec);
    uVar5 = 0xffffffff;
    pcVar9 = (char *)(iVar2 + 0x3c);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (iVar8 < (int)((~uVar5 - 1) * *(int *)(param_1 + 0x488) + *(int *)(iVar2 + 4))) {
      *(int *)(iVar2 + 0x38) = (iVar8 - *(int *)(iVar2 + 4)) / *(int *)(param_1 + 0x488);
    }
    else {
      uVar5 = 0xffffffff;
      pcVar9 = (char *)(iVar2 + 0x3c);
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      *(uint *)(iVar2 + 0x38) = ~uVar5 - 1;
    }
    if (5 < *(int *)(iVar2 + 0x38)) {
      *(undefined4 *)(iVar2 + 0x38) = 5;
    }
    iVar8 = (int)*(short *)(param_1 + 0x4da);
    iVar6 = *(int *)(param_1 + 0x48c);
    iVar4 = *(int *)(param_1 + 0x4f0);
    iVar7 = *(int *)(param_1 + 0x4e0);
    if (iVar4 + iVar7 < iStack_8 + iVar6 + 1 + iVar8) goto LAB_0051f9bc;
LAB_0051f9c8:
    iStack_c = iStack_4;
    iVar8 = iStack_8 + 1 + iVar8;
    goto switchD_0051f73e_caseD_3;
  }
  iVar8 = iVar8 + -2;
  iVar4 = *(int *)(param_1 + 0x4e0);
  if (iVar4 < iVar8) {
    iVar4 = *(int *)(param_1 + 0x4f0) + iVar4;
    if (iVar4 <= iVar8) {
      iVar8 = (iVar4 - iVar6) + -3;
    }
  }
  else {
LAB_0051f87c:
    iVar8 = iVar4 + 2;
  }
switchD_0051f73e_caseD_3:
  *(int *)(iVar2 + 0x20) = iStack_4;
  *(int *)(iVar2 + 0x28) = iStack_c;
  *(int *)(iVar2 + 0x24) = iStack_8;
  *(int *)(iVar2 + 0x2c) = iVar8;
  if (uStack_10 != 0) {
    *(undefined4 *)(iVar2 + 0xa8) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0051fd88
// Address: 0051fd88
// [HELPER] s_tpnl_tml__draw_special_events: "tpnl_tml::draw_special_events"
void __fastcall FUN_0051fd88(Time_Line_Panel *param_1)
{
  char cVar1;
  Special_Events *pSVar2;
  uchar *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 uVar12;
  short sVar13;
  char *pcVar14;
  uchar uVar15;
  
  if (param_1->timeline_flag != '\0') {
    GetNearestPaletteIndex(*(undefined4 *)(*(int *)param_1->_padding_ + 8),0xffffff);
    GetNearestPaletteIndex(*(undefined4 *)(*(int *)param_1->_padding_ + 8),0);
    puVar3 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_tpnl_tml__draw_special_events,1);
    if (puVar3 != (uchar *)0x0) {
      for (pSVar2 = param_1->time_slice_events; pSVar2 != (Special_Events *)0x0;
          pSVar2 = pSVar2->next) {
        switch(pSVar2->event) {
        case '\0':
          uVar15 = '\0';
          goto LAB_0051fe22;
        case '\x01':
          uVar15 = '\x01';
          goto LAB_0051fe22;
        case '\x02':
          uVar15 = '\x02';
          goto LAB_0051fe22;
        case '\x03':
          uVar15 = '\x03';
LAB_0051fe22:
          sVar13 = -1;
          break;
        case '\x04':
          uVar15 = '\x04';
          sVar13 = 0;
          break;
        case '\x05':
          uVar15 = '\x05';
          sVar13 = 1;
          break;
        case '\x06':
          uVar15 = '\x06';
          sVar13 = 2;
          break;
        case '\a':
          uVar15 = '\a';
          sVar13 = 3;
          break;
        case '\b':
          uVar15 = '\b';
          sVar13 = 4;
          break;
        default:
          goto switchD_0051fdef_default;
        }
        Time_Line_Panel::draw_icon(param_1,pSVar2,sVar13,uVar15);
switchD_0051fdef_default:
      }
    }
    TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_tpnl_tml__draw_special_events);
    pvVar4 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_tpnl_tml__draw_special_events);
    if (pvVar4 != (void *)0x0) {
      SetBkMode(*(undefined4 *)(param_1->_padding_ + 0x38),1);
      uVar5 = SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->body_font);
      for (pSVar2 = param_1->time_slice_events; pSVar2 != (Special_Events *)0x0;
          pSVar2 = pSVar2->next) {
        switch(pSVar2->event) {
        case '\0':
          SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),0);
          iVar9 = pSVar2->text_length1;
          lVar6 = pSVar2->start_txt_y1;
          pcVar14 = pSVar2->text1;
          lVar7 = pSVar2->start_txt_x1;
          uVar12 = *(undefined4 *)(param_1->_padding_ + 0x38);
          break;
        case '\x01':
switchD_0051fe9b_caseD_1:
          SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),0);
          iVar9 = pSVar2->text_length1;
          lVar6 = pSVar2->start_txt_y1;
          pcVar14 = pSVar2->text1;
          lVar7 = pSVar2->start_txt_x1;
          uVar12 = *(undefined4 *)(param_1->_padding_ + 0x38);
          break;
        case '\x02':
switchD_0051fe9b_caseD_2:
          SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),0);
          iVar9 = pSVar2->text_length1;
          lVar6 = pSVar2->start_txt_y1;
          pcVar14 = pSVar2->text1;
          lVar7 = pSVar2->start_txt_x1;
          uVar12 = *(undefined4 *)(param_1->_padding_ + 0x38);
          break;
        case '\x03':
          iVar10 = (-(uint)(pSVar2->time_slice != 0) & 0xfffffffc) + 2;
          SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),0xffffff);
          pcVar14 = pSVar2->text1;
          uVar8 = 0xffffffff;
          pcVar11 = pcVar14;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          iVar9 = ~uVar8 - 1;
          lVar6 = TPanel::yPosition((TPanel *)param_1);
          uVar8 = 0xffffffff;
          pcVar11 = pSVar2->text1;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          TextOutA(*(undefined4 *)(param_1->_padding_ + 0x38),
                   (iVar10 - (~uVar8 - 1 >> 1) * param_1->axis_font_wid) + pSVar2->X_line_pos,
                   lVar6 + 8 + param_1->axis_font_hgt,pcVar14,iVar9);
          pcVar14 = pSVar2->text2;
          uVar8 = 0xffffffff;
          pcVar11 = pcVar14;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          iVar9 = ~uVar8 - 1;
          lVar6 = TPanel::yPosition((TPanel *)param_1);
          lVar7 = TPanel::height((TPanel *)param_1);
          lVar6 = lVar6 + lVar7 + param_1->axis_font_hgt * -2 + -7;
          uVar8 = 0xffffffff;
          pcVar11 = pSVar2->text2;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          uVar12 = *(undefined4 *)(param_1->_padding_ + 0x38);
          lVar7 = (iVar10 - (~uVar8 - 1 >> 1) * param_1->axis_font_wid) + pSVar2->X_line_pos;
          break;
        default:
          goto switchD_0051fe9b_caseD_4;
        case '\x06':
          if (pSVar2->icon_flag != 0) goto switchD_0051fe9b_caseD_1;
          goto switchD_0051fe9b_caseD_4;
        case '\b':
          if (pSVar2->icon_flag != 0) goto switchD_0051fe9b_caseD_2;
          goto switchD_0051fe9b_caseD_4;
        }
        TextOutA(uVar12,lVar7,lVar6,pcVar14,iVar9);
switchD_0051fe9b_caseD_4:
      }
      SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),uVar5);
      TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_tpnl_tml__draw_special_events);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00520032
// Address: 00520032
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_00520032(char *param_1,undefined4 param_2)
{
  byte bVar1;
  short sVar2;
  char cVar3;
  char cVar5;
  undefined4 in_EAX;
  undefined4 extraout_ECX;
  char *pcVar6;
  char unaff_BL;
  char unaff_BH;
  byte *pbVar4;
  
  sVar2 = (short)(char)((uint)param_1 >> 8);
  cVar3 = (char)((short)in_EAX / sVar2);
  cVar5 = (char)((short)in_EAX % sVar2);
  pbVar4 = (byte *)CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar5,cVar3));
  pcVar6 = (char *)CONCAT22((short)((uint)param_2 >> 0x10),
                            CONCAT11((char)((uint)param_2 >> 8) + unaff_BH,(char)param_2 + unaff_BH)
                           );
  *pbVar4 = *pbVar4 + cVar5;
  *param_1 = *param_1 + '\x01';
  bVar1 = *pbVar4;
  *pbVar4 = *pbVar4 + (byte)param_1;
  *param_1 = *param_1 + '\x01';
  *param_1 = *param_1 + '\x01';
  cRama10051fe = cVar3 + -2 + CARRY1(bVar1,(byte)param_1);
  *pcVar6 = *pcVar6 + unaff_BL;
  *param_1 = *param_1 + '\x01';
  (**(code **)param_1)(param_1);
  pcVar6 = (char *)CONCAT22((short)((uint)extraout_ECX >> 0x10),
                            CONCAT11((char)((uint)extraout_ECX >> 8) + (char)extraout_ECX,
                                     (char)extraout_ECX));
  *pcVar6 = *pcVar6 + '\x01';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0052021c
// Address: 0052021c
// [HELPER] s__s____s: "%s - %s"
// [HELPER] s_tpnl_tml__draw_civilization_name: "tpnl_tml::draw_civilization_names"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052021c(int param_1)
{
  char cVar1;
  byte bVar2;
  void *pvVar3;
  undefined4 uVar4;
  RGE_Game_World *pRVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  float fStack_144;
  int iStack_140;
  int iStack_138;
  char acStack_12c [100];
  undefined1 auStack_c8 [100];
  char acStack_64 [100];
  
  if (*(char *)(param_1 + 0x51c) != '\0') {
    SetTextColor(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),0);
    pvVar3 = TDrawArea::GetDc(*(TDrawArea **)(param_1 + 0x20),s_tpnl_tml__draw_civilization_name);
    if (pvVar3 != (void *)0x0) {
      SetBkMode(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),1);
      uVar4 = SelectObject(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),
                           *(undefined4 *)(param_1 + 0x484));
      iVar9 = 0;
      fStack_144 = 0.0;
      pRVar5 = rge_base_game->world;
      if (pRVar5->player_num != 1 && -1 < pRVar5->player_num + -1) {
        iVar11 = 4;
        do {
          bVar2 = TRIBE_History_Info::get_history_entry
                            (*(TRIBE_History_Info **)
                              (*(int *)((int)pRVar5->players + iVar11) + 0x83c),'\0',0);
          iVar9 = iVar9 + 1;
          pRVar5 = rge_base_game->world;
          iVar11 = iVar11 + 4;
          fStack_144 = (float)bVar2 + fStack_144;
        } while (iVar9 < pRVar5->player_num + -1);
      }
      if (fStack_144 != _DAT_005770b8) {
        iVar9 = *(int *)(param_1 + 0x4dc);
        iStack_138 = *(int *)(param_1 + 0x4e0);
        pRVar5 = rge_base_game->world;
        if (pRVar5->player_num != 1 && -1 < pRVar5->player_num + -1) {
          iStack_140 = 0;
          iVar11 = 4;
          do {
            TRIBE_History_Info::get_history_entry
                      (*(TRIBE_History_Info **)(*(int *)((int)pRVar5->players + iVar11) + 0x83c),
                       '\0',0);
            iVar6 = __ftol();
            (**(code **)(rge_base_game->_padding_ + 0x28))
                      (0x69,*(undefined1 *)
                             (*(int *)((int)rge_base_game->world->players + iVar11) + 0x105),0,
                       auStack_c8,100);
            uVar7 = 0xffffffff;
            pcVar10 = *(char **)(*(int *)((int)rge_base_game->world->players + iVar11) + 0x44);
            do {
              pcVar12 = pcVar10;
              if (uVar7 == 0) break;
              uVar7 = uVar7 - 1;
              pcVar12 = pcVar10 + 1;
              cVar1 = *pcVar10;
              pcVar10 = pcVar12;
            } while (cVar1 != '\0');
            uVar7 = ~uVar7;
            pcVar10 = pcVar12 + -uVar7;
            pcVar12 = acStack_64;
            for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
              pcVar10 = pcVar10 + 4;
              pcVar12 = pcVar12 + 4;
            }
            for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *pcVar12 = *pcVar10;
              pcVar10 = pcVar10 + 1;
              pcVar12 = pcVar12 + 1;
            }
            sprintf(acStack_12c,s__s____s,acStack_64,auStack_c8);
            uVar7 = 0xffffffff;
            pcVar10 = acStack_12c;
            do {
              if (uVar7 == 0) break;
              uVar7 = uVar7 - 1;
              cVar1 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar1 != '\0');
            TextOutA(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),iVar9 + 3,
                     (iVar6 / 2 - *(int *)(param_1 + 0x48c) / 2) + iStack_138,acStack_12c,~uVar7 - 1
                    );
            iStack_138 = iStack_138 + iVar6;
            iVar11 = iVar11 + 4;
            pRVar5 = rge_base_game->world;
            iStack_140 = iStack_140 + 1;
          } while (iStack_140 < pRVar5->player_num + -1);
        }
        SelectObject(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),uVar4);
        TDrawArea::ReleaseDc(*(TDrawArea **)(param_1 + 0x20),s_tpnl_tml__draw_civilization_name);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00520492
// Address: 00520492
// [HELPER] s_tpnl_tml__draw_timeline: "tpnl_tml::draw_timeline"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00520492(Time_Line_Panel *param_1)
{
  byte bVar1;
  uchar uVar2;
  undefined1 uVar3;
  uchar *puVar4;
  long lVar5;
  RGE_Game_World *pRVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  float10 extraout_ST0;
  long lVar13;
  uchar uStack_51;
  float fStack_50;
  float fStack_4c;
  int iStack_48;
  float fStack_44;
  float fStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  uint uStack_8;
  undefined1 uStack_4;
  undefined3 uStack_3;
  
  if (param_1->timeline_flag != '\0') {
    puVar4 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_tpnl_tml__draw_timeline,1);
    if (puVar4 != (uchar *)0x0) {
      param_1->X_line_pos = param_1->X_start_line_pos;
      iStack_38 = 0;
      iStack_10 = 0;
      iStack_2c = 0;
      iStack_3c = 0;
      iStack_28 = 0;
      iStack_48 = 0;
      if (0 < param_1->num_history_entries) {
        iStack_30 = 1;
        do {
          iVar8 = iStack_48;
          if (param_1->num_entries_page <= iStack_28) break;
          iVar9 = 0;
          fStack_50 = 0.0;
          iStack_14 = 0;
          pRVar6 = rge_base_game->world;
          if (pRVar6->player_num != 1 && -1 < pRVar6->player_num + -1) {
            iVar10 = 4;
            do {
              bVar1 = TRIBE_History_Info::get_history_entry
                                (*(TRIBE_History_Info **)
                                  (*(int *)((int)pRVar6->players + iVar10) + 0x83c),'\0',iVar8);
              uStack_8 = (uint)bVar1;
              fStack_4c = (float)uStack_8;
              uVar2 = TRIBE_History_Info::get_history_event
                                (*(TRIBE_History_Info **)
                                  (*(int *)((int)rge_base_game->world->players + iVar10) + 0x83c),
                                 iVar8,&uStack_51);
              if (uVar2 != '\0') {
                iStack_14 = 1;
              }
              iVar10 = iVar10 + 4;
              pRVar6 = rge_base_game->world;
              iVar9 = iVar9 + 1;
              fStack_50 = fStack_4c + fStack_50;
            } while (iVar9 < pRVar6->player_num + -1);
          }
          if (fStack_50 == _DAT_005770b8) {
            return;
          }
          iVar9 = __ftol();
          iVar10 = __ftol();
          iVar10 = (iVar10 + (1 - iStack_30) * iVar9) - iStack_2c;
          if ((((param_1->drop_flag == '\0') || (iStack_14 != 0)) || (iStack_3c < iVar10)) ||
             (param_1->total_slices_to_drop <= iStack_30 + -1)) {
            iStack_3c = iStack_3c + 1;
            iStack_28 = iStack_28 + 1;
            if (iVar8 == param_1->num_entries_page + -1) {
              fStack_44 = fStack_50;
            }
            else {
              iVar9 = 0;
              fStack_44 = 0.0;
              pRVar6 = rge_base_game->world;
              if (pRVar6->player_num != 1 && -1 < pRVar6->player_num + -1) {
                iVar10 = iVar8 + 1;
                iVar11 = 4;
                do {
                  bVar1 = TRIBE_History_Info::get_history_entry
                                    (*(TRIBE_History_Info **)
                                      (*(int *)((int)pRVar6->players + iVar11) + 0x83c),'\0',iVar10)
                  ;
                  uStack_8 = (uint)bVar1;
                  iVar9 = iVar9 + 1;
                  pRVar6 = rge_base_game->world;
                  iVar11 = iVar11 + 4;
                  fStack_44 = (float)uStack_8 + fStack_44;
                  iVar8 = iStack_48;
                } while (iVar9 < pRVar6->player_num + -1);
              }
              if (fStack_44 == _DAT_005770b8) {
                return;
              }
            }
            if ((iStack_38 == param_1->pop_reading_rate + -1) || (iVar8 == 0)) {
              lVar13 = param_1->X_line_pos;
              iVar9 = 1;
              lVar5 = __ftol();
              Time_Line_Panel::add_pop_total_special_event(param_1,iVar8,lVar5,lVar13,iVar9);
              iStack_38 = 0;
            }
            else {
              iStack_38 = iStack_38 + 1;
            }
            iStack_c = iVar8 + 1;
            iVar9 = __ftol();
            iStack_14 = __ftol();
            iVar10 = iStack_14 * (iVar8 + 1);
            if (iVar10 < iVar9 - iStack_10) {
              iStack_14 = ((iVar9 - iStack_10) - iVar10) + iStack_14;
              iStack_10 = iStack_10 + 1;
            }
            iStack_1c = 0;
            iStack_18 = 0;
            if (0 < iStack_14) {
              do {
                param_1->Y_line_pos = param_1->Y_start_line_pos;
                iStack_20 = 0;
                fStack_40 = 0.0;
                pRVar6 = rge_base_game->world;
                if (pRVar6->player_num != 1 && -1 < pRVar6->player_num + -1) {
                  iStack_34 = 0;
                  iVar9 = 4;
                  do {
                    switch(*(undefined2 *)
                            (*(int *)(*(int *)((int)pRVar6->players + iVar9) + 0x108) + 0x26)) {
                    case 0:
                      uVar7 = 0xc40000;
                      break;
                    case 1:
                      uVar7 = 200;
                      break;
                    case 2:
                      uVar7 = 0xeaea;
                      break;
                    case 3:
                      uVar7 = 0x215a8c;
                      break;
                    case 4:
                      uVar7 = 0x80ff;
                      break;
                    case 5:
                      uVar7 = 0x8000;
                      break;
                    case 6:
                      uVar7 = 0x808080;
                      break;
                    case 7:
                      uVar7 = 0x808040;
                      break;
                    default:
                      uVar7 = 0xffffff;
                    }
                    uVar3 = GetNearestPaletteIndex
                                      (*(undefined4 *)(*(int *)param_1->_padding_ + 8),uVar7);
                    _uStack_4 = CONCAT31(uStack_3,uVar3);
                    bVar1 = TRIBE_History_Info::get_history_entry
                                      (*(TRIBE_History_Info **)
                                        (*(int *)((int)rge_base_game->world->players + iVar9) +
                                        0x83c),'\0',iStack_48);
                    uStack_8 = (uint)bVar1;
                    iVar8 = param_1->Y_line_max_length;
                    fStack_4c = (float)uStack_8;
                    iStack_24 = iVar8;
                    uStack_8 = __ftol();
                    if ((_DAT_005770b0 <= fStack_4c) && ((int)uStack_8 < 1)) {
                      uStack_8 = 1;
                    }
                    uVar12 = uStack_8;
                    if (param_1->bar_thickness != 1.0) {
                      if (iStack_48 != param_1->num_entries_page + -1) {
                        TRIBE_History_Info::get_history_entry
                                  (*(TRIBE_History_Info **)
                                    (*(int *)((int)rge_base_game->world->players + iVar9) + 0x83c),
                                   '\0',iStack_c);
                      }
                      iVar8 = param_1->Y_line_max_length;
                      iStack_24 = iVar8;
                      iStack_24 = __ftol();
                      iStack_24 = iStack_24 - uVar12;
                      uStack_8 = __ftol();
                      if ((_DAT_005770b0 <= fStack_4c) && ((int)uStack_8 < 1)) {
                        uStack_8 = 1;
                      }
                      fStack_40 = (float)(((float10)fStack_40 + extraout_ST0) -
                                         (float10)(int)uStack_8);
                      uVar12 = uStack_8;
                      if ((float)_DAT_005770c0 < fStack_40) {
                        fStack_40 = fStack_40 - _DAT_005770b0;
                        uVar12 = uStack_8 + 1;
                      }
                    }
                    if (iStack_34 == rge_base_game->world->player_num + -2) {
                      if (iVar8 < (int)(uVar12 + iStack_20)) {
                        uVar12 = iVar8 - iStack_20;
                      }
                      if ((int)(uVar12 + iStack_20) < iVar8) {
                        uVar12 = iVar8 - iStack_20;
                      }
                    }
                    uVar2 = (uchar)_uStack_4;
                    TDrawArea::DrawVertLine
                              ((TDrawArea *)param_1->_padding_,param_1->X_line_pos,
                               param_1->Y_line_pos,uVar12,uVar2);
                    if (iStack_1c == 0) {
                      Time_Line_Panel::record_special_event
                                (param_1,(char)iStack_34 + '\x01',
                                 *(TRIBE_History_Info **)
                                  (*(int *)((int)rge_base_game->world->players + iVar9) + 0x83c),
                                 uVar2,iStack_48,param_1->X_line_pos,param_1->Y_line_pos,uVar12);
                    }
                    param_1->Y_line_pos = param_1->Y_line_pos + uVar12;
                    iStack_20 = iStack_20 + uVar12;
                    iVar9 = iVar9 + 4;
                    pRVar6 = rge_base_game->world;
                    iStack_34 = iStack_34 + 1;
                    iVar8 = iStack_48;
                  } while (iStack_34 < pRVar6->player_num + -1);
                }
                iStack_1c = iStack_1c + 1;
                iStack_18 = iStack_18 + 1;
                param_1->X_line_pos = param_1->X_line_pos + 1;
              } while (iStack_1c < iStack_14);
            }
          }
          else {
            iStack_30 = iStack_30 + 1;
            iStack_3c = 0;
            if (iVar9 < iVar10) {
              iStack_2c = iStack_2c + 1;
            }
          }
          iStack_48 = iVar8 + 1;
        } while (iStack_48 < param_1->num_history_entries);
      }
    }
    TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_tpnl_tml__draw_timeline);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00520abd
// Address: 00520abd
// [HELPER] s__1ld__02ld: "%1ld:%02ld"
// [HELPER] s__ld: "%ld"
// [HELPER] s__ld__1d: "%ld/%1d"
// [HELPER] s__s: "%s"
void __fastcall FUN_00520abd(int param_1,undefined4 param_2)
{
  uchar uVar1;
  int iVar2;
  Special_Events *pSVar3;
  uchar uVar4;
  int in_EAX;
  int iVar5;
  char cVar8;
  uint uVar6;
  int iVar7;
  byte *pbVar9;
  Time_Line_Panel *unaff_EBX;
  int unaff_EBP;
  char *pcVar10;
  char in_ZF;
  float10 in_ST0;
  Special_Events *in_stack_00000040;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  short sVar11;
  
  param_1 = param_1 + -1;
  cVar8 = (char)((uint)param_1 >> 8);
  if (param_1 == 0 || in_ZF == '\0') {
    in_EAX = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + cVar8);
    unaff_EBX = (Time_Line_Panel *)
                CONCAT22((short)((uint)unaff_EBX >> 0x10),
                         CONCAT11((char)((uint)unaff_EBX >> 8) + cVar8,(char)unaff_EBX));
  }
  pbVar9 = (byte *)CONCAT22((short)((uint)param_2 >> 0x10),
                            CONCAT11((char)((uint)param_2 >> 8) * '\x02',(byte)param_2));
  pcVar10 = (char *)(in_EAX + CONCAT22((short)((uint)param_1 >> 0x10),
                                       CONCAT11(cVar8 + (char)((uint)unaff_EBX >> 8),(char)param_1))
                    );
  *pcVar10 = *pcVar10 + (char)in_EAX;
  *(char *)&unaff_EBX->_padding_ = (char)unaff_EBX->_padding_ + (char)param_1;
  *pbVar9 = *pbVar9 | (byte)param_2;
  *(char *)&unaff_EBX[-0x168f3c]._padding_ = (char)unaff_EBX[-0x168f3c]._padding_ + (char)in_EAX;
  *(float *)(unaff_EBP + 0x56) = (float)in_ST0;
  GetNearestPaletteIndex(*(undefined4 *)(*(int *)unaff_EBX->_padding_ + 8),0xffffff);
  uVar4 = GetNearestPaletteIndex(*(undefined4 *)(*(int *)unaff_EBX->_padding_ + 8),0);
  pSVar3 = in_stack_00000040;
  switch(in_stack_00000040->event) {
  case '\0':
    iVar5 = TPanel::get_string((TPanel *)unaff_EBX,0x106a,&stack0x00000008,0x32);
    if (iVar5 == 0) goto switchD_00520b22_caseD_4;
    goto LAB_00520b72;
  case '\x01':
    iVar5 = TPanel::get_string((TPanel *)unaff_EBX,0x106b,&stack0x00000008,0x32);
    break;
  case '\x02':
    iVar5 = TPanel::get_string((TPanel *)unaff_EBX,0x106c,&stack0x00000008,0x32);
    break;
  case '\x03':
    goto switchD_00520b22_caseD_3;
  case '\x04':
  case '\x05':
  case '\a':
    goto switchD_00520b22_caseD_4;
  default:
    goto switchD_00520b22_caseD_6;
  case '\b':
    sprintf(&stack0x00000008,s__ld__1d,in_stack_00000040->interger_value_1,
            in_stack_00000040->interger_value_2);
    sprintf(pSVar3->text1,s__s,&stack0x00000008);
    goto switchD_00520b22_caseD_3;
  }
  if (iVar5 == 0) {
switchD_00520b22_caseD_4:
    pSVar3->text1[0] = '\0';
  }
  else {
LAB_00520b72:
    sprintf(pSVar3->text1,s__s,&stack0x00000008);
  }
switchD_00520b22_caseD_6:
  sVar11 = (short)in_stack_00000044;
  iVar5 = Time_Line_Panel::calculate_icon_location(unaff_EBX,pSVar3,sVar11,(uchar)in_stack_00000048)
  ;
  uVar1 = pSVar3->event;
  if (uVar1 == '\0') {
    TDrawArea::DrawVertLine
              ((TDrawArea *)unaff_EBX->_padding_,pSVar3->X_line_pos,pSVar3->Y_line_pos,
               pSVar3->intermediate_y_line_segment,uVar4);
  }
  else {
    if (uVar1 == '\x01') {
      TDrawArea::DrawVertLine
                ((TDrawArea *)unaff_EBX->_padding_,pSVar3->X_line_pos,pSVar3->Y_line_pos,
                 pSVar3->intermediate_y_line_segment,uVar4);
      return;
    }
    if (uVar1 == '\x02') {
      TDrawArea::DrawVertLine
                ((TDrawArea *)unaff_EBX->_padding_,pSVar3->X_line_pos,pSVar3->Y_line_pos,
                 pSVar3->intermediate_y_line_segment,uVar4);
      return;
    }
    if (iVar5 != 0) {
      TShape::shape_draw(unaff_EBX->special_events_pic,(TDrawArea *)unaff_EBX->_padding_,
                         pSVar3->start_x,pSVar3->start_y,(int)sVar11,'\0',(uchar *)0x0);
      return;
    }
  }
  return;
switchD_00520b22_caseD_3:
  sprintf(pSVar3->text1,s__ld,pSVar3->pop_total);
  uVar6 = 0xffffffff;
  iVar5 = 0;
  pcVar10 = pSVar3->text1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar8 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar8 != '\0');
  iVar2 = pSVar3->time_slice * 0xf;
  pSVar3->text_length1 = ~uVar6 - 1;
  iVar7 = 0;
  if ((0x3b < iVar2) && (iVar7 = iVar2 / 0x3c, 0x3b < iVar7)) {
    iVar5 = iVar7 / 0x3c;
    iVar7 = iVar7 % 0x3c;
  }
  sprintf(&stack0x00000008,s__1ld__02ld,iVar5,iVar7);
  sprintf(pSVar3->text2,s__s,&stack0x00000008);
  uVar6 = 0xffffffff;
  pcVar10 = pSVar3->text2;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar8 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar8 != '\0');
  pSVar3->text_length2 = ~uVar6 - 1;
  goto switchD_00520b22_caseD_6;
}

// --------------------------------------------------

// Function: FUN_00520d25
// Address: 00520d25
uint __fastcall FUN_00520d25(int param_1,int param_2)
{
  char *pcVar1;
  uint in_EAX;
  uint uVar2;
  char cVar3;
  TPanel *unaff_EBX;
  int unaff_EBP;
  
  unaff_EBX->_padding_ = unaff_EBX->_padding_ - param_1;
  *(char *)(param_2 + 0xb) = *(char *)(param_2 + 0xb) + (char)in_EAX;
  pcVar1 = (char *)((int)&unaff_EBX->previousModalPanelValue + 3);
  cVar3 = (char)unaff_EBX;
  *pcVar1 = *pcVar1 + cVar3;
  *(char *)(unaff_EBP + 0x6900520b) = *(char *)(unaff_EBP + 0x6900520b) + cVar3;
  uVar2 = in_EAX | 0x52;
  *(char *)(unaff_EBP + -0x69ffadf5) = *(char *)(unaff_EBP + -0x69ffadf5) + cVar3;
  if ((TShape *)unaff_EBX[5].pnl_y != (TShape *)0x0) {
    uVar2 = TShape::shape_count((TShape *)unaff_EBX[5].pnl_y);
    if (uVar2 != 0) {
      uVar2 = TPanel::width(unaff_EBX);
    }
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00520d6f
// Address: 00520d6f
TPanel * __thiscall FUN_00520d6f(TPanel *param_1,TDrawArea *param_2,TPanel *param_3,int param_4)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561548;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel(param_1);
  param_1[1]._padding_ = param_4;
  uStack_4 = 0;
  *(undefined1 *)&param_1[1].previousPanelValue = 0;
  *(undefined1 *)((int)&param_1[1].previousPanelValue + 1) = 0;
  param_1[1].mouse_down_shift = 0;
  param_1->_padding_ = (int)&TRIBE_Panel_Text_Line::_vftable_;
  lVar1 = TPanel::setup(param_1,param_2,param_3,0,0,0,0,'\0');
  if (lVar1 == 0) {
    param_1->error_code = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00520df2
// Address: 00520df2
TRIBE_Panel_Text_Line * __thiscall FUN_00520df2(TRIBE_Panel_Text_Line *param_1,byte param_2)
{
  TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00520e25
// Address: 00520e25
void __thiscall FUN_00520e25(int *param_1,char param_2,byte *param_3,int param_4)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  
  if (param_2 == (char)param_1[0x3e]) {
    pbVar6 = (byte *)((int)param_1 + 0xf9);
    pbVar2 = param_3;
    do {
      bVar1 = *pbVar2;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_00520e74:
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_00520e79;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_00520e74;
      pbVar2 = pbVar2 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_00520e79:
    if ((iVar3 == 0) && (param_4 == param_1[0x71])) {
      return;
    }
  }
  uVar4 = 0xffffffff;
  *(char *)(param_1 + 0x3e) = param_2;
  do {
    pbVar6 = param_3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pbVar6 = param_3 + 1;
    bVar1 = *param_3;
    param_3 = pbVar6;
  } while (bVar1 != 0);
  uVar4 = ~uVar4;
  iVar3 = *param_1;
  pbVar6 = pbVar6 + -uVar4;
  pbVar2 = (byte *)((int)param_1 + 0xf9);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pbVar2 = *(undefined4 *)pbVar6;
    pbVar6 = pbVar6 + 4;
    pbVar2 = pbVar2 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pbVar2 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    pbVar2 = pbVar2 + 1;
  }
  param_1[0x71] = param_4;
  (**(code **)(iVar3 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00520ecf
// Address: 00520ecf
// [HELPER] s_tpnl_txl__draw: "tpnl_txl::draw"
void __fastcall FUN_00520ecf(int *param_1)
{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_ESI;
  char *pcVar5;
  int iVar6;
  
  if (((param_1[8] != 0) && (param_1[0x1c] != 0)) && (param_1[0x1b] != 0)) {
    if ((int *)param_1[0x10] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x10] + 0x34))(param_1 + 9);
    }
    iVar6 = *param_1;
    (**(code **)(iVar6 + 0x28))(0);
    pvVar2 = TDrawArea::GetDc((TDrawArea *)param_1[8],s_tpnl_txl__draw);
    if (pvVar2 != (void *)0x0) {
      uVar3 = SelectObject(*(undefined4 *)(param_1[8] + 0x38),param_1[0x3d]);
      SetBkMode(*(undefined4 *)(param_1[8] + 0x38),1);
      SetTextColor(*(undefined4 *)(param_1[8] + 0x38),0);
      if (*(char *)((int)param_1 + 0xf9) != '\0') {
        uVar4 = 0xffffffff;
        pcVar5 = (char *)((int)param_1 + 0xf9);
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(param_1[8] + 0x38),param_1[3],param_1[4],
                 (char *)((int)param_1 + 0xf9),~uVar4 - 1);
        iVar6 = unaff_ESI;
      }
      SelectObject(*(undefined4 *)(param_1[8] + 0x38),uVar3);
      TDrawArea::ReleaseDc((TDrawArea *)param_1[8],s_tpnl_txl__draw);
    }
    (**(code **)(iVar6 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00520fb9
// Address: 00520fb9
// [HELPER] s_1_tpnl_tim_cpp_0058b760: "1\tpnl_tim.cpp"
void FUN_00520fb9(char *param_1,char *param_2,int param_3)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = *param_1;
  iVar3 = 0;
  while ((cVar1 != '\0' && (param_1 = param_1 + 1, iVar3 < param_3))) {
    if ((cVar1 < 'A') || ('_' < cVar1)) {
      *param_2 = cVar1;
      param_2 = param_2 + 1;
      iVar3 = iVar3 + 1;
    }
    else {
      uVar2 = *(undefined4 *)(s_1_tpnl_tim_cpp_0058b760 + cVar1 * 4);
      *param_2 = (char)((uint)uVar2 >> 8);
      param_2[1] = (char)uVar2;
      param_2 = param_2 + 2;
      iVar3 = iVar3 + 2;
    }
    cVar1 = *param_1;
  }
  *param_2 = '\0';
  return;
}

// --------------------------------------------------

// Function: encrypt_codes
// Address: 00520fc0
// [HELPER] s_1_tpnl_tim_cpp_0058b760: "1\tpnl_tim.cpp"
/* void __cdecl encrypt_codes(char *,char *,int) */

void __cdecl encrypt_codes(char *param_1,char *param_2,int param_3)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = *param_1;
  iVar3 = 0;
  while ((cVar1 != '\0' && (param_1 = param_1 + 1, iVar3 < param_3))) {
    if ((cVar1 < 'A') || ('_' < cVar1)) {
      *param_2 = cVar1;
      param_2 = param_2 + 1;
      iVar3 = iVar3 + 1;
    }
    else {
      uVar2 = *(undefined4 *)(s_1_tpnl_tim_cpp_0058b760 + cVar1 * 4);
      *param_2 = (char)((uint)uVar2 >> 8);
      param_2[1] = (char)uVar2;
      param_2 = param_2 + 2;
      iVar3 = iVar3 + 2;
    }
    cVar1 = *param_1;
  }
  *param_2 = '\0';
  return;
}

// --------------------------------------------------

// Function: FUN_00521014
// Address: 00521014
// [HELPER] s__s_: "%s\n"
// [HELPER] s__s____s_: "%s - %s\n"
// [HELPER] s_a: "a"
// [HELPER] s_c__aoerun_txt: "c:\aoerun.txt"
// [HELPER] s_w: "w"
void FUN_00521014(undefined4 param_1,int param_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_1c [7];
  
  if (do_run_log != 0) {
    if (run_log_created == 0) {
      run_log_file = (_iobuf *)fopen(s_c__aoerun_txt,s_w);
      run_log_created = 1;
    }
    else {
      run_log_file = (_iobuf *)fopen(s_c__aoerun_txt,s_a);
    }
    if (run_log_file != (_iobuf *)0x0) {
      if (param_2 != 0) {
        time(&param_2);
        puVar3 = auStack_1c;
        for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        *(undefined2 *)puVar3 = 0;
        uVar1 = ctime(&param_2,0x18);
        strncpy(auStack_1c,uVar1);
        fprintf(run_log_file,s__s____s_,auStack_1c,param_1);
        fclose(run_log_file);
        return;
      }
      fprintf(run_log_file,s__s_,param_1);
      fclose(run_log_file);
    }
  }
  return;
}

// --------------------------------------------------

// Function: run_log
// Address: 00521020
// [HELPER] s__s_: "%s\n"
// [HELPER] s__s____s_: "%s - %s\n"
// [HELPER] s_a: "a"
// [HELPER] s_c__aoerun_txt: "c:\aoerun.txt"
// [HELPER] s_w: "w"
/* WARNING: Variable defined which should be unmapped: stime */
/* void __cdecl run_log(char *,int) */

void __cdecl run_log(char *param_1,int param_2)
{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char stime [26];
  
  if (do_run_log != 0) {
    if (run_log_created == 0) {
      run_log_file = (_iobuf *)fopen(s_c__aoerun_txt,s_w);
      run_log_created = 1;
    }
    else {
      run_log_file = (_iobuf *)fopen(s_c__aoerun_txt,s_a);
    }
    if (run_log_file != (_iobuf *)0x0) {
      if (param_2 != 0) {
        time(&param_2);
        pcVar3 = stime;
        for (iVar2 = 6; pcVar3 = pcVar3 + 4, iVar2 != 0; iVar2 = iVar2 + -1) {
          pcVar3[0] = '\0';
          pcVar3[1] = '\0';
          pcVar3[2] = '\0';
          pcVar3[3] = '\0';
        }
        pcVar3[0] = '\0';
        pcVar3[1] = '\0';
        uVar1 = ctime(&param_2,0x18);
        strncpy(stime + 4,uVar1);
        fprintf(run_log_file,s__s____s_,stime + 4,param_1);
        fclose(run_log_file);
        return;
      }
      fprintf(run_log_file,s__s_,param_1);
      fclose(run_log_file);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00521116
// Address: 00521116
TRIBE_Game * __thiscall FUN_00521116(TRIBE_Game *param_1,RGE_Prog_Info *param_2,int param_3)
{
  long *plVar1;
  int iVar2;
  int **ppiVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561568;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Base_Game::RGE_Base_Game((RGE_Base_Game *)param_1,param_2,0);
  param_1->video_window = (void *)0x0;
  param_1->cur_video = -1;
  param_1->old_video_wnd_proc = (void *)0x0;
  param_1->video_paused = 0;
  param_1->last_video_time = 0;
  param_1->video_setup = 0;
  param_1->video_double_size = 0;
  param_1->video_changed_res = 0;
  param_1->video_hi_color = 0;
  param_1->video_save_res_wid = 0;
  param_1->video_save_res_hgt = 0;
  param_1->video_save_palette = (void *)0x0;
  param_1->started_menu_music = 0;
  param_1->show_object_id = 0;
  param_1->game_screen = (TRIBE_Screen_Game *)0x0;
  param_1->inHandleIdle = 0;
  param_1->_padding_ = (int)&TRIBE_Game::_vftable_;
  param_1->_padding_ = 1;
  param_1->_padding_ = 0;
  param_1->testing_scenario[0] = '\0';
  StringTableX = (void *)0x0;
  param_1->startup_scenario[0] = '\0';
  param_1->startup_game[0] = '\0';
  param_1->save_game_name[0] = '\0';
  param_1->load_game_name[0] = '\0';
  param_1->auto_exit_time = 0;
  param_1->timing_text2[0] = '\0';
  disable_terrain_sounds = 0;
  out_of_sync = 0;
  out_of_sync2 = 0;
  uStack_4 = 0;
  param_1->MouseRightClickTable = (MouseClickInfo *)0x0;
  param_1->MouseRightClickTableSize = 0;
  param_1->MouseLeftClickTable = (MouseClickInfo *)0x0;
  param_1->MouseLeftClickTableSize = 0;
  TRIBE_Game::setMapSize(param_1,Medium);
  TRIBE_Game::setMapType(param_1,WaterAndLand);
  TRIBE_Game::setAnimals(param_1,1);
  TRIBE_Game::setPredators(param_1,1);
  TRIBE_Game::setVictoryType(param_1,VictoryConquest,1);
  TRIBE_Game::setAllowTrading(param_1,1);
  TRIBE_Game::setLongCombat(param_1,0);
  TRIBE_Game::setRandomizePositions(param_1,0);
  TRIBE_Game::setFullTechTree(param_1,0);
  TRIBE_Game::setResourceLevel(param_1,DefaultResources);
  TRIBE_Game::setStartingAge(param_1,DefaultAge);
  TRIBE_Game::setStartingUnits(param_1,0);
  TRIBE_Game::setDeathMatch(param_1,'\0');
  TRIBE_Game::setPopLimit(param_1,'2');
  TRIBE_Game::setQuickStartGame(param_1,'\0');
  TRIBE_Game::setRandomStartValue(param_1,-1);
  plVar1 = param_1->notification_loc_y;
  iVar2 = 5;
  do {
    plVar1[-5] = -1;
    *plVar1 = -1;
    plVar1 = plVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1->current_notification_loc = -1;
  param_1->current_notification_recalled = -1;
  param_2 = (RGE_Prog_Info *)0x1;
  iVar2 = 0;
  ppiVar3 = &player_dropped;
  do {
    TRIBE_Game::setCivilization(param_1,iVar2,(int)param_2);
    param_2 = (RGE_Prog_Info *)((int)param_2 + 1);
    if (0x10 < (int)param_2) {
      param_2 = (RGE_Prog_Info *)0x1;
    }
    TRIBE_Game::setScenarioPlayer(param_1,iVar2,iVar2);
    TRIBE_Game::setPlayerColor(param_1,iVar2,1);
    TRIBE_Game::setComputerName(param_1,iVar2,0);
    *ppiVar3 = (int *)0x0;
    ppiVar3 = ppiVar3 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)ppiVar3 < 0x86bccc);
  piVar4 = param_1->save_humanity;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  RGE_Base_Game::setNumberPlayers((RGE_Base_Game *)param_1,4);
  TRIBE_Game::resetRandomComputerName(param_1);
  if (param_3 != 0) {
    iVar2 = TRIBE_Game::setup(param_1);
    if ((iVar2 == 0) && (param_1->_padding_ == 0)) {
      param_1->_padding_ = 1;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00521377
// Address: 00521377
TRIBE_Game * __thiscall FUN_00521377(TRIBE_Game *param_1,byte param_2)
{
  TRIBE_Game::~TRIBE_Game(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0052139e
// Address: 0052139e
// [HELPER] s_Border_drs: "Border.drs"
// [HELPER] s_Campaign_Editor_Screen: "Campaign Editor Screen"
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_Connecting_Screen: "Connecting Screen"
// [HELPER] s_Create_Dialog: "Create Dialog"
// [HELPER] s_End_Screen: "End Screen"
// [HELPER] s_FeaturesInfo: "FeaturesInfo"
// [HELPER] s_Game_Settings_Screen: "Game Settings Screen"
// [HELPER] s_Game_Setup_Screen: "Game Setup Screen"
// [HELPER] s_Interfac_drs: "Interfac.drs"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_Logo1Screen: "Logo1Screen"
// [HELPER] s_Logo2Screen: "Logo2Screen"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_MP_Startup_Screen: "MP Startup Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Name_Selection_Screen: "Name Selection Screen"
// [HELPER] s_New_Name_Dialog: "New Name Dialog"
// [HELPER] s_QuotesInfo: "QuotesInfo"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_ScenarioEditorInfo: "ScenarioEditorInfo"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Select_Scenario_Screen: "Select Scenario Screen"
// [HELPER] s_Single_Player_Menu: "Single Player Menu"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_Temp_Screen: "Temp Screen"
// [HELPER] s_Terrain_drs: "Terrain.drs"
// [HELPER] s_Video_Screen: "Video Screen"
// [HELPER] s_graphics_drs: "graphics.drs"
// [HELPER] s_sounds_drs: "sounds.drs"
void __fastcall FUN_0052139e(TRIBE_Game *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561588;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Game::_vftable_;
  uStack_4 = 0;
  param_1->inHandleIdle = 0;
  param_1->_padding_ = 0;
  if (param_1->_padding_ != 0) {
    DestroyWindow(param_1->_padding_);
    param_1->_padding_ = 0;
  }
  TRIBE_Game::close_game_screens(param_1,1);
  TPanelSystem::destroyPanel(&panel_system,s_Video_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Create_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Campaign_Editor_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Game_Setup_Screen);
  TPanelSystem::destroyPanel(&panel_system,&s_Game_Settings_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Select_Scenario_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Campaign_Selection_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Load_Saved_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_MP_Startup_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_MP_Setup_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Connecting_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Join_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Main_Menu);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_End_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Open);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Single_Player_Menu);
  TPanelSystem::destroyPanel(&panel_system,&s_New_Name_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Name_Selection_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Temp_Screen);
  TPanelSystem::destroyPanel(&panel_system,&s_ScenarioEditorInfo);
  TPanelSystem::destroyPanel(&panel_system,&s_FeaturesInfo);
  TPanelSystem::destroyPanel(&panel_system,s_QuotesInfo);
  TPanelSystem::destroyPanel(&panel_system,&s_Logo1Screen);
  TPanelSystem::destroyPanel(&panel_system,&s_Logo2Screen);
  RESFILE_close_new_resource_file(s_sounds_drs);
  RESFILE_close_new_resource_file(s_graphics_drs);
  RESFILE_close_new_resource_file(s_Terrain_drs);
  RESFILE_close_new_resource_file(s_Border_drs);
  RESFILE_close_new_resource_file(s_Interfac_drs);
  if (StringTableX != (void *)0x0) {
    FreeLibrary(StringTableX);
    StringTableX = (void *)0x0;
  }
  uStack_4 = 0xffffffff;
  RGE_Base_Game::~RGE_Base_Game((RGE_Base_Game *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00521611
// Address: 00521611
// [HELPER] s_About_Dialog: "About Dialog"
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_CloseProgramDialog: "CloseProgramDialog"
// [HELPER] s_Diplomacy_Dialog: "Diplomacy Dialog"
// [HELPER] s_End_Screen: "End Screen"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Help_Dialog: "Help Dialog"
// [HELPER] s_Load_Saved_Game_Screen: "Load Saved Game Screen"
// [HELPER] s_Menu_Dialog: "Menu Dialog"
// [HELPER] s_Mission_Dialog: "Mission Dialog"
// [HELPER] s_Multiplayer_Disconnect_Screen: "Multiplayer Disconnect Screen"
// [HELPER] s_Multiplayer_Wait_Screen: "Multiplayer Wait Screen"
// [HELPER] s_OKDialog: "OKDialog"
// [HELPER] s_Object_List_Dialog: "Object List Dialog"
// [HELPER] s_QuitAndLoadDialog: "QuitAndLoadDialog"
// [HELPER] s_QuitGameDialog: "QuitGameDialog"
// [HELPER] s_ResignDialog: "ResignDialog"
// [HELPER] s_RestartDialog: "RestartDialog"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Send_Message_Dialog: "Send Message Dialog"
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
// [HELPER] s_YesNoDialog: "YesNoDialog"
void __thiscall FUN_00521611(int param_1,int param_2)
{
  TPanelSystem::destroyPanel(&panel_system,&s_Object_List_Dialog);
  TPanelSystem::destroyPanel(&panel_system,&s_OKDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_YesNoDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_RestartDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_QuitGameDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_CloseProgramDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_QuitAndLoadDialog);
  TPanelSystem::destroyPanel(&panel_system,&s_ResignDialog);
  TPanelSystem::destroyPanel(&panel_system,s_Help_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_About_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Send_Quick_Message_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Mission_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Send_Message_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Diplomacy_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Load_Saved_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_End_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Achievements_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Wait_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Multiplayer_Disconnect_Screen);
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0xc24) = 0;
    TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00521783
// Address: 00521783
// [HELPER] s_: ""
// [HELPER] s_Border_drs: "Border.drs"
// [HELPER] s_InputDisabledWindow: "InputDisabledWindow"
// [HELPER] s_Interfac_drs: "Interfac.drs"
// [HELPER] s_LOBBY: "LOBBY"
// [HELPER] s_MAKERES: "MAKERES"
// [HELPER] s_MP_Setup_Screen: "MP Setup Screen"
// [HELPER] s_Main_Error_Screen: "Main Error Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Makeres: "Makeres"
// [HELPER] s_STATIC: "STATIC"
// [HELPER] s_STRING_: "STRING="
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_Terrain_drs: "Terrain.drs"
// [HELPER] s_______________________________: "------------------------------"
// [HELPER] s_data_: "data\"
// [HELPER] s_data__s__size__d__date__d__d__d_: "data=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d"
// [HELPER] s_graphics_drs: "graphics.drs"
// [HELPER] s_graphics_rm: "graphics.rm"
// [HELPER] s_interfac_rm: "interfac.rm"
// [HELPER] s_languagex_dll: "languagex.dll"
// [HELPER] s_logo1: "logo1"
// [HELPER] s_makeres: "makeres"
// [HELPER] s_options__s: "options=%s"
// [HELPER] s_program__s__size__d__date__d__d_: "program=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d"
// [HELPER] s_resource_: "resource\"
// [HELPER] s_scr1: "scr1"
// [HELPER] s_sounds_drs: "sounds.drs"
// [HELPER] s_sounds_rm: "sounds.rm"
// [HELPER] s_tribe: "tribe"
int __fastcall FUN_00521783(TRIBE_Game *param_1)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  char *pcVar4;
  TRIBE_Screen_Main_Error *this;
  TEasy_Panel *this_00;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  uint unaff_EDI;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined2 uStack_920;
  undefined2 uStack_91e;
  undefined2 uStack_91c;
  undefined2 uStack_91a;
  undefined2 uStack_918;
  undefined2 uStack_916;
  undefined2 uStack_914;
  undefined2 uStack_912;
  undefined4 uStack_910;
  undefined4 uStack_90c;
  undefined1 uStack_908;
  undefined1 uStack_907;
  undefined1 uStack_906;
  undefined1 uStack_905;
  undefined1 uStack_904;
  undefined1 uStack_903;
  undefined1 uStack_902;
  undefined1 uStack_901;
  undefined1 uStack_900;
  undefined1 uStack_8ff;
  undefined1 uStack_8fe;
  undefined1 uStack_8fd;
  undefined1 uStack_8fc;
  undefined1 uStack_8fb;
  undefined1 uStack_8fa;
  undefined1 uStack_8f9;
  undefined1 uStack_8f8;
  undefined1 uStack_8f7;
  undefined1 uStack_8f6;
  undefined1 uStack_8f5;
  undefined1 uStack_8f4;
  undefined1 uStack_8f3;
  undefined1 uStack_8f2;
  undefined1 uStack_8f1;
  undefined1 uStack_8f0;
  undefined1 uStack_8ef;
  undefined1 uStack_8ee;
  undefined1 uStack_8ed;
  TribeMPSetupScreen *pTStack_8ec;
  undefined4 uStack_8e8;
  undefined4 uStack_8e4;
  undefined2 uStack_8e0;
  undefined4 auStack_8de [20];
  undefined1 auStack_88c [8];
  undefined1 auStack_884 [12];
  undefined1 auStack_878 [4];
  undefined4 uStack_874;
  undefined1 auStack_870 [4];
  undefined4 uStack_86c;
  undefined1 auStack_748 [4];
  undefined1 auStack_744 [240];
  char acStack_654 [8];
  char acStack_64c [7];
  undefined1 uStack_645;
  char acStack_644 [1024];
  undefined1 auStack_244 [568];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005615d8;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_91c = (undefined2)unaff_EBX;
  uStack_91a = (undefined2)((uint)unaff_EBX >> 0x10);
  uStack_920 = (undefined2)unaff_EBP;
  uStack_91e = (undefined2)((uint)unaff_EBP >> 0x10);
  if (param_1->_padding_ != 0) {
    iVar3 = 0;
    goto LAB_00521e5b;
  }
  iVar3 = strstr(param_1->_padding_ + 0x518,s_makeres);
  if (((iVar3 != 0) || (iVar3 = strstr(param_1->_padding_ + 0x518,s_Makeres), iVar3 != 0)) ||
     (iVar3 = strstr(param_1->_padding_ + 0x518,s_MAKERES), iVar3 != 0)) {
    RESFILE_build_res_file(s_graphics_rm,s_resource_,(char *)(param_1->_padding_ + 0xf26));
    RESFILE_build_res_file(s_sounds_rm,s_resource_,(char *)(param_1->_padding_ + 0xf26));
    RESFILE_build_res_file(s_interfac_rm,s_resource_,(char *)(param_1->_padding_ + 0xf26));
  }
  RESFILE_open_new_resource_file(s_sounds_drs,s_tribe,(char *)(param_1->_padding_ + 0xf26),1);
  RESFILE_open_new_resource_file(s_graphics_drs,s_tribe,(char *)(param_1->_padding_ + 0xf26),0);
  RESFILE_open_new_resource_file(s_Interfac_drs,s_tribe,(char *)(param_1->_padding_ + 0xf26),0);
  RESFILE_open_new_resource_file(s_sounds_drs,s_tribe,s_data_,1);
  RESFILE_open_new_resource_file(s_graphics_drs,s_tribe,s_data_,0);
  RESFILE_open_new_resource_file(s_Terrain_drs,s_tribe,s_data_,0);
  RESFILE_open_new_resource_file(s_Border_drs,s_tribe,s_data_,0);
  RESFILE_open_new_resource_file(s_Interfac_drs,s_tribe,s_data_,0);
  iVar3 = RGE_Base_Game::setup((RGE_Base_Game *)param_1);
  if (iVar3 == 0) goto LAB_00521e5b;
  strncpy(auStack_744,param_1->_padding_ + 0x518,0xff);
  uStack_645 = 0;
  CharUpperA(auStack_744);
  pcVar4 = (char *)__mbsstr(auStack_748,s_STRING_);
  pTStack_8ec = s_languagex_dll;
  uStack_8e8 = DAT_0058ba38;
  uStack_8e4 = DAT_0058ba3c;
  uStack_8e0 = DAT_0058ba40;
  puVar5 = auStack_8de;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  if (pcVar4 != (char *)0x0) {
    cVar1 = *pcVar4;
    while (cVar1 != '=') {
      pcVar4 = (char *)__mbsninc(pcVar4,1);
      cVar1 = *pcVar4;
    }
    pcVar4 = (char *)__mbsninc(pcVar4,1);
    pTStack_8ec = (TribeMPSetupScreen *)((uint)pTStack_8ec & 0xffffff00);
    iVar3 = __ismbcspace(*pcVar4);
    while ((iVar3 == 0 && (*pcVar4 != '\0'))) {
      __mbsncat(&pTStack_8ec,pcVar4,1);
      pcVar4 = (char *)__mbsninc(pcVar4,1);
      iVar3 = __ismbcspace(*pcVar4);
    }
  }
  StringTableX = (void *)LoadLibraryA(&pTStack_8ec);
  if (StringTableX == (void *)0x0) {
    param_1->_padding_ = 1;
    iVar3 = 0;
    goto LAB_00521e5b;
  }
  uStack_8fb = 0x7b;
  uStack_8ee = 0x7b;
  uStack_903 = 0x3f;
  uStack_900 = 0x3f;
  uStack_8f8 = 0x3f;
  uStack_8f3 = 0x3f;
  uStack_908 = 0x17;
  uStack_907 = 0x27;
  uStack_906 = 0x7c;
  uStack_905 = 0;
  uStack_904 = 0x27;
  uStack_902 = 0x90;
  uStack_901 = 0;
  uStack_8ff = 0x5f;
  uStack_8fe = 0x9f;
  uStack_8fd = 0;
  uStack_8fc = 0x57;
  uStack_8fa = 0xb4;
  uStack_8f9 = 0;
  uStack_8f7 = 0x5f;
  uStack_8f6 = 0xa0;
  uStack_8f5 = 0;
  uStack_8f4 = 0x27;
  uStack_8f2 = 0x91;
  uStack_8f1 = 0;
  uStack_8f0 = 0x17;
  uStack_8ef = 0x27;
  uStack_8ed = 0;
  SetPaletteEntries(param_1->_padding_,0xf8,7,&uStack_908);
  iVar3 = CreateWindowExA(0,s_STATIC,s_InputDisabledWindow,0x40000000,0,0,1,1,param_1->_padding_,0,
                          *(undefined4 *)(param_1->_padding_ + 0x410),0);
  param_1->_padding_ = iVar3;
  video_codec_available = _ICInfo_12(0x63646976,0x31347669,auStack_244);
  uVar2 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)param_1,s_LOBBY);
  if (uVar2 == '\0') {
    iVar3 = TCommunications_Handler::LaunchLobbyGame((TCommunications_Handler *)param_1->_padding_);
    if (iVar3 == 1) {
      RGE_Base_Game::setMultiplayerGame((RGE_Base_Game *)param_1,1);
      pTStack_8ec = (TribeMPSetupScreen *)operator_new(0x890);
      uStack_4 = 3;
      if (pTStack_8ec != (TribeMPSetupScreen *)0x0) {
        TribeMPSetupScreen::TribeMPSetupScreen(pTStack_8ec);
      }
LAB_00521ec8:
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_MP_Setup_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
    }
    else {
      if (param_1->startup_scenario[0] == '\0') {
        if (param_1->startup_game[0] == '\0') {
          if (*(int *)(param_1->_padding_ + 0x890) == 0) {
            TRIBE_Game::start_video(param_1,0,s_logo1);
          }
          else {
            iVar3 = TRIBE_Game::start_menu(param_1);
            if (iVar3 == 0) goto LAB_00521f96;
          }
          goto LAB_00521c8a;
        }
        iVar3 = TRIBE_Game::load_game(param_1,param_1->startup_game);
      }
      else {
        iVar3 = TRIBE_Game::start_scenario(param_1,param_1->startup_scenario);
      }
      if (iVar3 == 0) {
        iVar3 = TRIBE_Game::start_menu(param_1);
        if (iVar3 == 0) goto LAB_00521e5b;
        this_00 = (TEasy_Panel *)TPanelSystem::panel(&panel_system,s_Main_Menu);
        if (this_00 != (TEasy_Panel *)0x0) {
          TEasy_Panel::popupOKDialog(this_00,0x961,(char *)0x0,0x1c2,100);
        }
      }
    }
LAB_00521c8a:
    (**(code **)(param_1->_padding_ + 0x140))();
    run_log(s_______________________________,0);
    run_log(s_,1);
    iVar3 = FindFirstFileA(__pgmptr,auStack_884);
    if (iVar3 != -1) {
      uStack_920 = 0;
      uStack_91e = 0;
      uStack_91c = 0;
      uStack_91a = 0;
      uStack_918 = 0;
      uStack_916 = 0;
      uStack_914 = 0;
      uStack_912 = 0;
      FileTimeToSystemTime(auStack_878,&uStack_920);
      sprintf(acStack_654,s_program__s__size__d__date__d__d_,__pgmptr,uStack_874,unaff_EDI >> 0x10,
              unaff_EDI >> 0x10,unaff_EDI & 0xffff,uStack_920,uStack_91e,uStack_91c);
      run_log(acStack_654,0);
      FindClose(iVar3);
    }
    iVar3 = FindFirstFileA(param_1->_padding_ + 0x1f8,auStack_88c);
    if (iVar3 != -1) {
      uStack_918 = 0;
      uStack_916 = 0;
      uStack_914 = 0;
      uStack_912 = 0;
      uStack_910 = 0;
      uStack_90c = 0;
      FileTimeToSystemTime(auStack_870,&uStack_918);
      sprintf(acStack_64c,s_data__s__size__d__date__d__d__d_,param_1->_padding_ + 0x1f8,uStack_86c,
              uStack_91e,uStack_91e,uStack_920,uStack_918,uStack_916,uStack_914);
      run_log(acStack_64c,0);
      FindClose(iVar3);
    }
    sprintf(acStack_644,s_options__s,param_1->_padding_ + 0x518);
    run_log(acStack_644,0);
    iVar3 = 1;
  }
  else {
    pTStack_8ec = (TribeMPSetupScreen *)operator_new(0x47c);
    uStack_4 = 0;
    if (pTStack_8ec != (TribeMPSetupScreen *)0x0) {
      TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
                ((TRIBE_Screen_Status_Message *)pTStack_8ec,s_Status_Screen,0x4bf,s_scr1,0xc383);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Status_Screen,0);
    iVar3 = TCommunications_Handler::LaunchLobbyGame((TCommunications_Handler *)param_1->_padding_);
    if (iVar3 == 1) {
      RGE_Base_Game::setMultiplayerGame((RGE_Base_Game *)param_1,1);
      pTStack_8ec = (TribeMPSetupScreen *)operator_new(0x890);
      uStack_4 = 1;
      if (pTStack_8ec == (TribeMPSetupScreen *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = TribeMPSetupScreen::TribeMPSetupScreen(pTStack_8ec);
      }
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0xd8) == 0)) goto LAB_00521ec8;
    }
    else {
      if (iVar3 != -1) {
        RGE_Base_Game::close((RGE_Base_Game *)param_1);
        iVar3 = 1;
        goto LAB_00521e5b;
      }
      pTStack_8ec = (TribeMPSetupScreen *)operator_new(0x484);
      uStack_4 = 2;
      if (pTStack_8ec == (TribeMPSetupScreen *)0x0) {
        this = (TRIBE_Screen_Main_Error *)0x0;
      }
      else {
        this = (TRIBE_Screen_Main_Error *)
               TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error
                         ((TRIBE_Screen_Main_Error *)pTStack_8ec);
      }
      uStack_4 = 0xffffffff;
      if ((this != (TRIBE_Screen_Main_Error *)0x0) && (this->_padding_ == 0)) {
        TRIBE_Screen_Main_Error::set_text(this,0x96a);
        TPanelSystem::setCurrentPanel(&panel_system,s_Main_Error_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
        goto LAB_00521c8a;
      }
    }
LAB_00521f96:
    iVar3 = 0;
  }
LAB_00521e5b:
  *unaff_FS_OFFSET = uStack_c;
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_00521f9d
// Address: 00521f9d
// [HELPER] s_EXIT_: "EXIT="
// [HELPER] s_GAM_: "GAM="
// [HELPER] s_NOTERRAINSOUND: "NOTERRAINSOUND"
// [HELPER] s_QUICK1: "QUICK1"
// [HELPER] s_SCN_: "SCN="
// [HELPER] s____L_c_L___: "+!#L%c#L ^="
// [HELPER] s__gmx: ".gmx"
void __fastcall FUN_00521f9d(TRIBE_Game *param_1)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 auStack_400 [252];
  char acStack_304 [256];
  char acStack_204 [516];
  
  strncpy(auStack_400,param_1->_padding_ + 0x518,0xff);
  acStack_304[3] = 0;
  CharUpperA(auStack_400);
  encrypt_codes(&stack0xfffffbfc,acStack_204,0x200);
  iVar2 = strstr(&stack0xfffffbfc,s_NOTERRAINSOUND);
  if (iVar2 != 0) {
    disable_terrain_sounds = 1;
  }
  pcVar3 = (char *)strstr(acStack_204,s____L_c_L___);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar8;
    }
    iVar2 = 0;
    cVar1 = pcVar3[1];
    while ((cVar1 != ' ' && (cVar1 != '\0'))) {
      acStack_304[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[2];
      pcVar3 = pcVar3 + 1;
    }
    acStack_304[iVar2] = '\0';
    iVar2 = atol(acStack_304);
    if (iVar2 < 0x1a) {
      iVar2 = 0x19;
    }
    else if (200 < iVar2) {
      iVar2 = 200;
    }
    TRIBE_Game::setPopLimit(param_1,(uchar)iVar2);
  }
  iVar2 = strstr(&stack0xfffffbfc,s_QUICK1);
  if (iVar2 != 0) {
    quick_start_game_mode = 1;
  }
  pcVar3 = (char *)strstr(&stack0xfffffbfc,s_SCN_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar8;
    }
    iVar2 = 0;
    cVar1 = pcVar3[1];
    while ((cVar1 != ' ' && (cVar1 != '\0'))) {
      param_1->startup_scenario[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[2];
      pcVar3 = pcVar3 + 1;
    }
    param_1->startup_scenario[iVar2] = '\0';
  }
  pcVar3 = (char *)strstr(&stack0xfffffbfc,s_EXIT_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar8;
    }
    iVar2 = 0;
    cVar1 = pcVar3[1];
    while ((cVar1 != ' ' && (cVar1 != '\0'))) {
      acStack_304[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[2];
      pcVar3 = pcVar3 + 1;
    }
    acStack_304[iVar2] = '\0';
    uVar4 = atol(acStack_304);
    param_1->auto_exit_time = uVar4;
  }
  pcVar3 = (char *)strstr(&stack0xfffffbfc,s_GAM_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar8;
    }
    iVar2 = 0;
    cVar1 = pcVar3[1];
    while ((cVar1 != ' ' && (cVar1 != '\0'))) {
      param_1->startup_game[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[2];
      pcVar3 = pcVar3 + 1;
    }
    param_1->startup_game[iVar2] = '\0';
    iVar2 = strchr(param_1->startup_game,0x2e);
    if (iVar2 == 0) {
      uVar5 = 0xffffffff;
      pcVar3 = &s__gmx;
      do {
        pcVar8 = pcVar3;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar8 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar8;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar2 = -1;
      pcVar3 = param_1->startup_game;
      do {
        pcVar7 = pcVar3;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar7 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar7;
      } while (cVar1 != '\0');
      pcVar3 = pcVar8 + -uVar5;
      pcVar8 = pcVar7 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar8 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
  }
  RGE_Base_Game::setup_cmd_options((RGE_Base_Game *)param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_005221f6
// Address: 005221f6
undefined4 __fastcall FUN_005221f6(RGE_Base_Game *param_1)
{
  int iVar1;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  iVar1 = RGE_Base_Game::setup_palette(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  uStack_19 = 0;
  uStack_15 = 0;
  uStack_11 = 0;
  uStack_d = 0;
  uStack_9 = 0;
  uStack_5 = 0;
  uStack_1 = 0;
  uStack_17 = 0x3f;
  uStack_14 = 0x3f;
  uStack_c = 0x3f;
  uStack_7 = 0x3f;
  uStack_1c = 0x17;
  uStack_1b = 0x27;
  uStack_1a = 0x7c;
  uStack_18 = 0x27;
  uStack_16 = 0x90;
  uStack_13 = 0x5f;
  uStack_12 = 0x9f;
  uStack_10 = 0x57;
  uStack_f = 0x7b;
  uStack_e = 0xb4;
  uStack_b = 0x5f;
  uStack_a = 0xa0;
  uStack_8 = 0x27;
  uStack_6 = 0x91;
  uStack_4 = 0x17;
  uStack_3 = 0x27;
  uStack_2 = 0x7b;
  SetPaletteEntries(param_1->prog_palette,0xf8,7,&uStack_1c);
  return 1;
}

// --------------------------------------------------

// Function: FUN_005222b7
// Address: 005222b7
// [HELPER] s_artheld_wav: "artheld.wav"
// [HELPER] s_artlost_wav: "artlost.wav"
// [HELPER] s_button1_wav: "button1.wav"
// [HELPER] s_button2_wav: "button2.wav"
// [HELPER] s_cantdo_wav: "cantdo.wav"
// [HELPER] s_chatrcvd_wav: "chatrcvd.wav"
// [HELPER] s_convdone_wav: "convdone.wav"
// [HELPER] s_convwarn_wav: "convwarn.wav"
// [HELPER] s_farmdie_wav: "farmdie.wav"
// [HELPER] s_mdone_wav: "mdone.wav"
// [HELPER] s_mkilled_wav: "mkilled.wav"
// [HELPER] s_mstart_wav: "mstart.wav"
// [HELPER] s_pdropped_wav: "pdropped.wav"
// [HELPER] s_pkilled_wav: "pkilled.wav"
// [HELPER] s_res_wav: "res.wav"
// [HELPER] s_resdone_wav: "resdone.wav"
// [HELPER] s_tribute_wav: "tribute.wav"
undefined4 __fastcall FUN_005222b7(int param_1)
{
  int iVar1;
  TDigital *pTVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005616ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined2 *)(param_1 + 0x68) = 0x11;
  iVar1 = calloc(0x11,4);
  *(int *)(param_1 + 0x6c) = iVar1;
  if (iVar1 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  iVar1 = 0;
  if (0 < *(short *)(param_1 + 0x68)) {
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x6c) + -4 + iVar1 * 4) = 0;
    } while (iVar1 < *(short *)(param_1 + 0x68));
  }
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 0;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_button1_wav,0xc47c);
  }
  uStack_4 = 0xffffffff;
  **(undefined4 **)(param_1 + 0x6c) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 1;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_button2_wav,0xc47d);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 4) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 2;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_chatrcvd_wav,0xc47e);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 8) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 3;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_cantdo_wav,0xc47f);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0xc) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 4;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_tribute_wav,0xc480);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x10) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 5;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_resdone_wav,0xc481);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x14) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 6;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_pkilled_wav,0xc482);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x18) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 7;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_pdropped_wav,0xc483);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x1c) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 8;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_mstart_wav,0xc484);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x20) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 9;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_mdone_wav,0xc485);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x24) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 10;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_mkilled_wav,0xc486);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x28) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 0xb;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_artheld_wav,0xc487);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x2c) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 0xc;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_artlost_wav,0xc488);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x30) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 0xd;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_convwarn_wav,0xc489);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x34) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 0xe;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_convdone_wav,0xc48a);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x38) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 0xf;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_res_wav,0xc48b);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x3c) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 0x10;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_farmdie_wav,0xc48c);
  }
  uStack_4 = 0xffffffff;
  iVar1 = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x40) = uVar3;
  do {
    pTVar2 = *(TDigital **)(iVar1 + *(int *)(param_1 + 0x6c));
    if (pTVar2 != (TDigital *)0x0) {
      TDigital::load(pTVar2,(char *)0x0,-1);
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0xc);
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00522762
// Address: 00522762
undefined4 FUN_00522762(void)
{
  TRIBE_World *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005616cb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_World *)operator_new(0x124);
  uStack_4 = 0;
  if (this != (TRIBE_World *)0x0) {
    uVar1 = TRIBE_World::TRIBE_World(this);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_005227ca
// Address: 005227ca
void __thiscall FUN_005227ca(RGE_Base_Game *param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = param_1->game_mode;
  RGE_Base_Game::set_game_mode(param_1,param_2,param_3);
  if (*(TRIBE_Screen_Game **)(param_1[1].work_dir + 0x18) != (TRIBE_Screen_Game *)0x0) {
    TRIBE_Screen_Game::game_mode_changed
              (*(TRIBE_Screen_Game **)(param_1[1].work_dir + 0x18),iVar1,param_1->game_mode);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00522807
// Address: 00522807
void __thiscall FUN_00522807(RGE_Base_Game *param_1,short param_2)
{
  short sVar1;
  
  if (param_1->world == (RGE_Game_World *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = param_1->world->curr_player;
  }
  RGE_Base_Game::set_player(param_1,param_2);
  if ((param_1->world != (RGE_Game_World *)0x0) &&
     (*(TRIBE_Screen_Game **)(param_1[1].work_dir + 0x18) != (TRIBE_Screen_Game *)0x0)) {
    TRIBE_Screen_Game::player_changed
              (*(TRIBE_Screen_Game **)(param_1[1].work_dir + 0x18),(int)sVar1,
               (int)param_1->world->curr_player);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00522859
// Address: 00522859
void __thiscall FUN_00522859(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0xe64) = 0;
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
  pcVar5 = (char *)(param_1 + 0xe64);
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

// Function: FUN_0052289d
// Address: 0052289d
void __thiscall FUN_0052289d(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0xf68) = 0;
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
  pcVar5 = (char *)(param_1 + 0xf68);
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

// Function: FUN_005228dd
// Address: 005228dd
char * __thiscall FUN_005228dd(RGE_Base_Game *param_1,long param_2,char *param_3,int param_4)
{
  int iVar1;
  char *pcVar2;
  
  iVar1 = LoadStringA(StringTableX,param_2,param_3,param_4);
  if (iVar1 == 0) {
    pcVar2 = RGE_Base_Game::get_string(param_1,param_2,param_3,param_4);
    return pcVar2;
  }
  param_3[param_4 + -1] = '\0';
  return param_3;
}

// --------------------------------------------------

// Function: FUN_00522924
// Address: 00522924
char * __thiscall
FUN_00522924(RGE_Base_Game *param_1,int param_2,int param_3,long param_4,char *param_5,int param_6)
{
  char *pcVar1;
  
  *param_5 = '\0';
  switch(param_2) {
  case 1:
    switch(param_3) {
    case 100:
    case 0x65:
    case 0x66:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x961,param_5,param_6);
      return pcVar1;
    case 0x67:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x962,param_5,param_6);
      return pcVar1;
    case 0x68:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x963,param_5,param_6);
      return pcVar1;
    case 0x69:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x964,param_5,param_6);
      return pcVar1;
    case 0x6a:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x965,param_5,param_6);
      return pcVar1;
    default:
      pcVar1 = RGE_Base_Game::get_string2(param_1,param_2,param_3,param_4,param_5,param_6);
      return pcVar1;
    }
  default:
    pcVar1 = RGE_Base_Game::get_string2(param_1,param_2,param_3,param_4,param_5,param_6);
    return pcVar1;
  case 100:
    switch(param_3) {
    case 0:
    case 0xf:
    case 0x10:
    case 0x11:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10cd,param_5,param_6);
      return pcVar1;
    case 1:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10ce,param_5,param_6);
      return pcVar1;
    case 2:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10cf,param_5,param_6);
      return pcVar1;
    case 3:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d0,param_5,param_6);
      return pcVar1;
    case 9:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10db,param_5,param_6);
      return pcVar1;
    }
    break;
  case 0x65:
    switch(param_3) {
    case 1:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1069,param_5,param_6);
      return pcVar1;
    case 2:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x106a,param_5,param_6);
      return pcVar1;
    case 3:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x106b,param_5,param_6);
      return pcVar1;
    case 4:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x106c,param_5,param_6);
      return pcVar1;
    }
    break;
  case 0x66:
    switch(param_3) {
    case 1:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1005,param_5,param_6);
      return pcVar1;
    case 2:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1006,param_5,param_6);
      return pcVar1;
    case 3:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1007,param_5,param_6);
      return pcVar1;
    case 4:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1008,param_5,param_6);
      return pcVar1;
    case 5:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1009,param_5,param_6);
      return pcVar1;
    case 6:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x100a,param_5,param_6);
      return pcVar1;
    case 7:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x100b,param_5,param_6);
      return pcVar1;
    case 8:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x100c,param_5,param_6);
      return pcVar1;
    case 9:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x100d,param_5,param_6);
      return pcVar1;
    case 10:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x100e,param_5,param_6);
      return pcVar1;
    case 0xb:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x100f,param_5,param_6);
      return pcVar1;
    case 0xc:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1010,param_5,param_6);
      return pcVar1;
    case 0xd:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1011,param_5,param_6);
      return pcVar1;
    case 0xe:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1012,param_5,param_6);
      return pcVar1;
    case 0xf:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1013,param_5,param_6);
      return pcVar1;
    case 0x10:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1014,param_5,param_6);
      return pcVar1;
    case 0x11:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1015,param_5,param_6);
      return pcVar1;
    case 0x12:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1016,param_5,param_6);
      return pcVar1;
    case 0x13:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1017,param_5,param_6);
      return pcVar1;
    case 0x14:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1018,param_5,param_6);
      return pcVar1;
    case 0x15:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1019,param_5,param_6);
      return pcVar1;
    case 0x16:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x101a,param_5,param_6);
      return pcVar1;
    case 0x17:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x101b,param_5,param_6);
      return pcVar1;
    case 0x19:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1020,param_5,param_6);
      return pcVar1;
    case 0x1a:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1021,param_5,param_6);
      return pcVar1;
    case 0x1b:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1022,param_5,param_6);
      return pcVar1;
    case 0x1c:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x101c,param_5,param_6);
      return pcVar1;
    case 0x1d:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x101d,param_5,param_6);
      return pcVar1;
    case 0x1e:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x101e,param_5,param_6);
      return pcVar1;
    case 0x1f:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x101f,param_5,param_6);
      return pcVar1;
    case 0x20:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1025,param_5,param_6);
      return pcVar1;
    case 0x21:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x1026,param_5,param_6);
      return pcVar1;
    }
    break;
  case 0x67:
    if (param_3 < 0x66) {
      if (param_3 == 0x65) {
        pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbbe,param_5,param_6);
        return pcVar1;
      }
      if (param_3 == 1) {
        switch(param_4) {
        case 0:
          pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbb9,param_5,param_6);
          return pcVar1;
        case 1:
          pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbba,param_5,param_6);
          return pcVar1;
        case 2:
          pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbbb,param_5,param_6);
          return pcVar1;
        case 3:
          pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbbc,param_5,param_6);
          return pcVar1;
        case 4:
          pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbbd,param_5,param_6);
          return pcVar1;
        case 0x20:
          pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbe6,param_5,param_6);
          return pcVar1;
        }
      }
    }
    else if (param_3 < 0x3e9) {
      if (param_3 == 1000) {
        pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbc2,param_5,param_6);
        return pcVar1;
      }
      switch(param_3) {
      case 0x66:
        pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbbf,param_5,param_6);
        return pcVar1;
      case 0x67:
        pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbc0,param_5,param_6);
        return pcVar1;
      case 0x68:
        pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbc1,param_5,param_6);
        return pcVar1;
      case 0x69:
        pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbc3,param_5,param_6);
        return pcVar1;
      case 0x6a:
        pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0xbca,param_5,param_6);
        return pcVar1;
      }
    }
    break;
  case 0x68:
    switch(param_3) {
    case 1:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d4,param_5,param_6);
      return pcVar1;
    case 2:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d1,param_5,param_6);
      return pcVar1;
    case 3:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d2,param_5,param_6);
      return pcVar1;
    case 4:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d3,param_5,param_6);
      return pcVar1;
    case 5:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d5,param_5,param_6);
      return pcVar1;
    case 6:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d6,param_5,param_6);
      return pcVar1;
    case 7:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d7,param_5,param_6);
      return pcVar1;
    case 8:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d8,param_5,param_6);
      return pcVar1;
    case 9:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10d9,param_5,param_6);
      return pcVar1;
    case 10:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10da,param_5,param_6);
      return pcVar1;
    case 0xb:
      pcVar1 = (char *)(**(code **)(param_1->_padding_ + 0x20))(0x10dc,param_5,param_6);
      return pcVar1;
    }
    break;
  case 0x69:
    switch(param_3) {
    case 1:
      (**(code **)(param_1->_padding_ + 0x20))(0x27f7,param_5,param_6);
      break;
    case 2:
      (**(code **)(param_1->_padding_ + 0x20))(0x27f8,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 3:
      (**(code **)(param_1->_padding_ + 0x20))(0x27f9,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 4:
      (**(code **)(param_1->_padding_ + 0x20))(0x27fa,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 5:
      (**(code **)(param_1->_padding_ + 0x20))(0x27fb,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 6:
      (**(code **)(param_1->_padding_ + 0x20))(0x27fc,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 7:
      (**(code **)(param_1->_padding_ + 0x20))(0x27fd,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 8:
      (**(code **)(param_1->_padding_ + 0x20))(0x27fe,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 9:
      (**(code **)(param_1->_padding_ + 0x20))(0x27ff,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 10:
      (**(code **)(param_1->_padding_ + 0x20))(0x2800,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 0xb:
      (**(code **)(param_1->_padding_ + 0x20))(0x2801,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 0xc:
      (**(code **)(param_1->_padding_ + 0x20))(0x2802,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 0xd:
      (**(code **)(param_1->_padding_ + 0x20))(0x2806,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 0xe:
      (**(code **)(param_1->_padding_ + 0x20))(0x2807,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 0xf:
      (**(code **)(param_1->_padding_ + 0x20))(0x2809,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    case 0x10:
      (**(code **)(param_1->_padding_ + 0x20))(0x2808,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    default:
      (**(code **)(param_1->_padding_ + 0x20))(0x2804,param_5,param_6);
      param_5[param_6 + -1] = '\0';
      return param_5;
    }
  }
  param_5[param_6 + -1] = '\0';
  return param_5;
}

// --------------------------------------------------

// Function: FUN_0052321f
// Address: 0052321f
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
/* WARNING: Instruction at (ram,0x00523467) overlaps instruction at (ram,0x00523465)
    */

TPanel * __fastcall FUN_0052321f(undefined4 param_1,int *param_2)
{
  char *pcVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar9;
  int in_EAX;
  char *pcVar6;
  int iVar7;
  TPanel *pTVar8;
  char cVar10;
  byte bVar12;
  undefined4 extraout_ECX;
  undefined2 uVar13;
  int *piVar11;
  char cVar14;
  byte bVar15;
  byte bVar18;
  undefined3 uVar19;
  uint *puVar16;
  int iVar17;
  undefined2 uVar20;
  byte bVar21;
  char *unaff_EBX;
  undefined4 *puVar22;
  int *unaff_ESI;
  char *unaff_EDI;
  int in_GS_OFFSET;
  byte in_AF;
  undefined8 uVar23;
  undefined4 uStack0000004f;
  undefined4 uStack00000057;
  byte *pbStack000000c7;
  byte *pbStack000000cb;
  byte *pbStack000000cf;
  byte *pbStack000000d3;
  byte *pbStack000000d7;
  byte *pbStack000000db;
  byte *pbStack000000df;
  byte *pbStack000000e3;
  undefined4 uStack000000e7;
  undefined4 uStack000000eb;
  int *piStack000000ef;
  int *piStack000000f3;
  int *piStack000000f7;
  int *piStack000000fb;
  int *piStack000000ff;
  int *piStack00000103;
  int *piStack00000107;
  int *piStack0000010b;
  int *piStack0000010f;
  int *piStack00000113;
  int *piStack00000117;
  int *piStack0000011b;
  int *piStack00000138;
  int *piStack0000013c;
  int *piStack00000140;
  
  *param_2 = *param_2 + in_EAX;
  pcVar6 = (char *)(in_EAX + *(int *)(in_EAX + -0x746ffa));
  cVar14 = (char)((uint)param_1 >> 8);
  cVar5 = (char)((uint)param_2 >> 8);
  if ((int)pcVar6 < 0) {
    unaff_EDI[-0x5affadd7] = unaff_EDI[-0x5affadd7] + (char)param_1;
    *param_2 = *param_2 - (int)param_2;
    unaff_EBX = (char *)0xd1005229;
    *param_2 = *param_2 - (int)param_2;
    if (*param_2 < 0) {
      unaff_EDI[0x2a] = unaff_EDI[0x2a] + cVar5;
      *pcVar6 = *pcVar6 + (char)pcVar6;
      *param_2 = (int)(pcVar6 + *param_2);
      pcVar6 = (char *)CONCAT31((int3)((uint)(pcVar6 + *unaff_ESI) >> 8),
                                (char)(pcVar6 + *unaff_ESI) + '\x06');
    }
    else {
      cRamd1005253 = cRamd1005253 + cVar14;
    }
  }
  pcVar6 = pcVar6 + -0x74fafb;
  piVar11 = (int *)*param_2;
  *param_2 = *param_2 - (int)param_2;
  *pcVar6 = *pcVar6 + cVar14 + (char)*param_2 + (piVar11 < param_2);
  uVar19 = (undefined3)((uint)param_2 >> 8);
  cVar14 = (char)param_2 - (char)*param_2;
  piStack0000013c = (int *)CONCAT31(uVar19,cVar14 - *(char *)CONCAT31(uVar19,cVar14));
  puVar22 = (undefined4 *)(*piStack0000013c * 0x52);
  pcVar1 = (char *)((int)piStack0000013c + 0x2a9d0052 + (int)puVar22);
  *pcVar1 = *pcVar1 + (char)pcVar6;
  *(char *)((int)unaff_ESI + -0x30ffadd6) = *(char *)((int)unaff_ESI + -0x30ffadd6) + cVar5;
  piStack00000138 = (int *)0x523305;
  piStack00000140 = param_2;
  uVar23 = func_0x0152852f();
  puVar16 = (uint *)((ulonglong)uVar23 >> 0x20);
  iVar7 = (int)uVar23;
  piStack00000138 = (int *)((int)puVar16 - *puVar16);
  uVar13 = (undefined2)((uint)extraout_ECX >> 0x10);
  cVar14 = ((char)((uint)extraout_ECX >> 8) - *unaff_EBX) - (puVar16 < (uint *)*puVar16);
  *unaff_EBX = *unaff_EBX + (char)((uint)piStack00000138 >> 8);
  iVar17 = ((int)piStack00000138 - *piStack00000138) -
           *(int *)((int)piStack00000138 - *piStack00000138);
  piStack000000ef = (int *)(iVar17 - *(int *)(in_GS_OFFSET + iVar17));
  if (piStack000000ef == (int *)0x0 || iVar17 < *(int *)(in_GS_OFFSET + iVar17)) {
    cVar5 = (char)uVar23 + -0x52;
    iVar7 = CONCAT31((int3)((ulonglong)uVar23 >> 8),cVar5);
    iVar17 = CONCAT22(uVar13,CONCAT11(cVar14 + cVar5,(char)extraout_ECX));
code_r0x0052332a:
    cVar5 = (char)((uint)iVar17 >> 8);
    *unaff_EBX = *unaff_EBX + cVar5;
    cVar14 = (char)iVar7 + -0x52;
    *(char *)(iVar17 + 0x2c) = *(char *)(iVar17 + 0x2c) + cVar14;
    unaff_EDI[0x2c] = unaff_EDI[0x2c] + (char)piStack000000ef;
    *(char *)(puVar22 + 0xb) = *(char *)(puVar22 + 0xb) + cVar5;
    unaff_EBX[-0x66ffadd4] = unaff_EBX[-0x66ffadd4] + cVar14;
    unaff_EDI[-0x3affadd4] = unaff_EDI[-0x3affadd4] + cVar5;
    unaff_EBX = (char *)CONCAT31((int3)((uint)unaff_EBX >> 8),(char)unaff_EBX * '\x02');
    iVar17 = CONCAT31((int3)((uint)iVar17 >> 8),(char)iVar17 + (char)((uint)piStack000000ef >> 8));
    cVar14 = (char)iVar7 + 'f';
    iVar7 = CONCAT31((int3)((uint)iVar7 >> 8),cVar14);
    *unaff_EDI = *unaff_EDI + cVar14;
  }
  else {
    unaff_EDI[-0x4fffadd5] = unaff_EDI[-0x4fffadd5] + (char)piStack000000ef;
    puVar22 = (undefined4 *)*puVar22;
    piStack000000ef =
         (int *)(((int)piStack000000ef - *piStack000000ef) -
                *(int *)((int)piStack000000ef - *piStack000000ef));
    iVar17 = CONCAT22(uVar13,CONCAT11(cVar14,(char)extraout_ECX)) + -1;
    if (iVar17 == 0) goto code_r0x0052332a;
  }
  cVar14 = (char)((uint)piStack000000ef >> 8);
  *unaff_EBX = *unaff_EBX + cVar14;
  unaff_EDI[0x2d] = unaff_EDI[0x2d] + (char)unaff_EBX;
  *(char *)((int)puVar22 + 0x2d) = *(char *)((int)puVar22 + 0x2d) + cVar14;
  cVar10 = (char)iVar17;
  unaff_EBX[-0x5effadd3] = unaff_EBX[-0x5effadd3] + cVar10;
  uVar13 = (undefined2)((uint)iVar17 >> 0x10);
  bVar12 = (char)((uint)iVar17 >> 8) + cVar10;
  bVar21 = (byte)((uint)unaff_EBX >> 8);
  piVar11 = (int *)CONCAT31((int3)(CONCAT22(uVar13,CONCAT11(bVar12,cVar10)) >> 8),cVar10 + bVar21);
  iVar7 = iVar7 + 0x1bf0fe66;
  unaff_EDI[0x2a] = unaff_EDI[0x2a] + cVar14;
  *(char *)((int)puVar22 + 0x2e) = *(char *)((int)puVar22 + 0x2e) + bVar21;
  bVar15 = (byte)piStack000000ef;
  unaff_EBX[-0x56ffadd2] = unaff_EBX[-0x56ffadd2] + bVar15;
  bVar9 = (byte)((uint)iVar7 >> 8);
  cRam3b00522e = cRam3b00522e + bVar9;
  *(char *)((int)piVar11 + 0x2e) = *(char *)((int)piVar11 + 0x2e) + bVar15;
  unaff_EDI[0x2e] = unaff_EDI[0x2e] + bVar9;
  unaff_EDI[-0x2affadd2] = unaff_EDI[-0x2affadd2] + bVar21;
  uVar20 = (undefined2)((uint)piStack000000ef >> 0x10);
  uStack000000eb = CONCAT22(uVar20,CONCAT11(cVar14 + bVar21,bVar15));
  cVar14 = cVar14 + bVar21 + bVar21;
  uStack000000e7 = CONCAT22(uVar20,CONCAT11(cVar14,bVar15));
  bVar18 = cVar14 + bVar21;
  pbStack000000cf = (byte *)CONCAT22(uVar20,CONCAT11(bVar18,bVar15));
  unaff_EDI[(int)puVar22] = unaff_EDI[(int)puVar22] + bVar15;
  bVar4 = *pbStack000000cf;
  *pbStack000000cf = *pbStack000000cf + bVar12;
  in_AF = 9 < ((byte)iVar7 & 0xf) | in_AF;
  bVar3 = (byte)iVar7 + in_AF * -6;
  bVar3 = bVar3 + (0x9f < bVar3 | CARRY1(bVar4,bVar12) | in_AF * (bVar3 < 6)) * -0x60;
  pcVar6 = (char *)(CONCAT31((int3)((uint)iVar7 >> 8),bVar3) + 0x2f);
  *pcVar6 = *pcVar6 + bVar3;
  *(char *)((int)unaff_ESI + 0x2f) = *(char *)((int)unaff_ESI + 0x2f) + bVar15;
  in_AF = 9 < (bVar3 + bVar15 & 0xf) | in_AF;
  bVar4 = bVar3 + bVar15 + in_AF * -6;
  bVar4 = bVar4 + (0x9f < bVar4 | CARRY1(bVar3,bVar15) | in_AF * (bVar4 < 6)) * -0x60;
  pbStack000000c7 = (byte *)CONCAT22(uVar20,CONCAT11(bVar18 + bVar9,bVar15));
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  bVar4 = bVar4 + in_AF * -6;
  bVar4 = bVar4 + (0x9f < bVar4 | CARRY1(bVar18,bVar9) | in_AF * (bVar4 < 6)) * -0x60;
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  bVar3 = bVar4 + in_AF * -6;
  cVar5 = bVar3 + (0x9f < bVar3 | CARRY1(bVar9,bVar21) | in_AF * (bVar3 < 6)) * -0x60;
  pcVar6 = (char *)CONCAT31((int3)(CONCAT22((short)((uint)iVar7 >> 0x10),
                                            CONCAT11(bVar9 + bVar21,bVar4)) >> 8),cVar5);
  *pbStack000000c7 = *pbStack000000c7 + bVar15;
  *pbStack000000c7 = *pbStack000000c7 ^ bVar15;
  cVar14 = (byte)uRam2800522f;
  uRam2800522f = uRam2800522f ^ 0x2f;
  if (cVar14 == '/') {
    *pcVar6 = *pcVar6 + cVar5;
    pcVar1 = pcVar6 + uRam2800522f;
    pcVar6 = pcVar6 + *(int *)((int)unaff_ESI + (int)pcVar6) + -0x71007470;
    uRam2800522f = (uint)pcVar1 ^ 0x2f;
  }
  *unaff_EDI = (char)*unaff_ESI;
  uVar2 = uRam2800522f;
  bVar4 = (byte)uRam2800522f ^ 0x2f;
  uRam2800522f = uRam2800522f ^ 0x2f;
  if ((char)bVar4 < '\0') {
    piVar11 = (int *)CONCAT22(uVar13,CONCAT11(bVar12 * '\x02',cVar10 + bVar21));
code_r0x00523449:
    uRam2800522f = uRam2800522f ^ 0x2800522f;
    pcVar6 = (char *)piVar11[0x6c];
    if (((pcVar6 != (char *)0x4) && (pcVar6 != (char *)0x6)) && (pcVar6 != (char *)0x5))
    goto LAB_00523476;
  }
  else {
    cRamf800a45f = cRamf800a45f + bVar21;
    uRam2800522f = uVar2 ^ 0x2800522f;
    *piVar11 = (int)((int)unaff_ESI + *piVar11 + 1);
    unaff_EDI[1] = unaff_EDI[1] + (char)((uint)pcVar6 >> 8);
    if ((int)uRam2800522f < 1) {
      *(char *)((int)puVar22 + -0x54ffadcf) = *(char *)((int)puVar22 + -0x54ffadcf) + '/';
      uRam2800522f = uRam2800522f ^ 0x2800522f;
      *piVar11 = *piVar11 << 0x12;
      uRam2800522f = uRam2800522f ^ 0x2800522f;
      in(0x522f);
      goto code_r0x00523449;
    }
    pcVar6 = (char *)((uint)pcVar6 & 0xffffff0c);
    *pcVar6 = *pcVar6 + (char)pcVar6;
  }
  if (piVar11[0x309] != 0) {
    return *(TPanel **)(piVar11[0x309] + 0x4b8);
  }
LAB_00523476:
  uStack00000057 = 0x2800522f;
  if (pcVar6 == &DAT_00000007) {
    uStack0000004f = 0x52348a;
    pbStack000000cb = pbStack000000c7;
    pbStack000000d3 = pbStack000000cf;
    pbStack000000d7 = pbStack000000cf;
    pbStack000000db = pbStack000000cf;
    pbStack000000df = pbStack000000cf;
    pbStack000000e3 = pbStack000000cf;
    piStack000000f3 = piStack000000ef;
    piStack000000f7 = piStack000000ef;
    piStack000000fb = piStack000000ef;
    piStack000000ff = piStack000000ef;
    piStack00000103 = piStack000000ef;
    piStack00000107 = piStack000000ef;
    piStack0000010b = piStack000000ef;
    piStack0000010f = piStack000000ef;
    piStack00000113 = piStack000000ef;
    piStack00000117 = piStack000000ef;
    piStack0000011b = piStack000000ef;
    pTVar8 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Screen);
    if (pTVar8 != (TPanel *)0x0) {
      return pTVar8[5].previousPanelValue;
    }
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: FUN_00523498
// Address: 00523498
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
TPanel * __fastcall FUN_00523498(int param_1)
{
  int iVar1;
  TPanel *pTVar2;
  
  iVar1 = *(int *)(param_1 + 0x1b0);
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 5)) && (*(int *)(param_1 + 0xc24) != 0)) {
    return *(TPanel **)(*(int *)(param_1 + 0xc24) + 0x4bc);
  }
  if (iVar1 == 7) {
    pTVar2 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Screen);
    if (pTVar2 != (TPanel *)0x0) {
      return pTVar2[5].previousModalPanelValue;
    }
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: FUN_005234e8
// Address: 005234e8
int __fastcall FUN_005234e8(int param_1)
{
  return param_1 + 0xe64;
}

// --------------------------------------------------

// Function: FUN_005234f7
// Address: 005234f7
int __fastcall FUN_005234f7(int param_1)
{
  return param_1 + 0xf68;
}

// --------------------------------------------------

// Function: FUN_00523507
// Address: 00523507
undefined4 FUN_00523507(int param_1)
{
  TRIBE_Scenario_Header *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005616eb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Scenario_Header *)operator_new(0x1c);
  uStack_4 = 0;
  if (this != (TRIBE_Scenario_Header *)0x0) {
    uVar1 = TRIBE_Scenario_Header::TRIBE_Scenario_Header(this,param_1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00523635
// Address: 00523635
void __fastcall FUN_00523635(int *param_1)
{
  int iVar1;
  undefined4 uStack_220;
  undefined1 *puStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined1 *puStack_210;
  undefined4 uStack_20c;
  undefined1 auStack_200 [224];
  undefined1 auStack_120 [20];
  undefined1 auStack_10c [260];
  undefined4 uStack_8;
  
  puStack_210 = auStack_200;
  uStack_20c = 0x100;
  iVar1 = *param_1;
  uStack_214 = 0xfa8;
  uStack_218 = 0x52365e;
  (**(code **)(iVar1 + 0x20))();
  puStack_21c = auStack_10c;
  uStack_218 = 0x100;
  uStack_220 = 0;
  (**(code **)(iVar1 + 0x28))(1,uStack_8);
  MessageBoxA(param_1[4],auStack_120,&uStack_220,0x10);
  return;
}

// --------------------------------------------------

// Function: FUN_00523744
// Address: 00523744
void __thiscall FUN_00523744(TRIBE_Game *param_1,undefined4 param_2)
{
  long unaff_retaddr;
  undefined1 *puStack_10c;
  undefined4 uStack_108;
  undefined1 auStack_100 [252];
  char *pcStack_4;
  
  puStack_10c = auStack_100;
  uStack_108 = 0x100;
  (**(code **)(param_1->_padding_ + 0x20))(param_2);
  TRIBE_Game::show_status_message(param_1,(char *)&puStack_10c,pcStack_4,unaff_retaddr);
  return;
}

// --------------------------------------------------

// Function: FUN_00523795
// Address: 00523795
void FUN_00523795(void)
{
  TPanelSystem::restorePreviousPanel(&panel_system,1);
  return;
}

// --------------------------------------------------

// Function: FUN_005237ad
// Address: 005237ad
// [HELPER] s_CDPath: "CDPath"
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
// [HELPER] s__s_s_avi: "%s%s.avi"
// [HELPER] s__sgame_avi__s_avi: "%sgame\avi\%s.avi"
// [HELPER] s_stopped: "stopped"
undefined4 __thiscall FUN_005237ad(TRIBE_Game *param_1,int param_2,char *param_3)
{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  void *pvVar6;
  ulong uVar7;
  byte *pbVar8;
  bool bVar9;
  undefined1 auStack_178 [8];
  int iStack_170;
  int iStack_16c;
  byte abStack_168 [100];
  undefined1 auStack_104 [260];
  
  if (param_1->video_window != (void *)0x0) {
    SendMessageA(param_1->video_window,0x46a,100,abStack_168);
    if (abStack_168[0] != 0) {
      pbVar8 = &s_stopped;
      pbVar3 = abStack_168;
      do {
        bVar1 = *pbVar3;
        bVar9 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_00523811:
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_00523816;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar9 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_00523811;
        pbVar3 = pbVar3 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00523816:
      if (iVar4 != 0) {
        SendMessageA(param_1->video_window,0x808,0,0);
      }
    }
    SendMessageA(param_1->video_window,0x10,0,0);
    param_1->video_window = (void *)0x0;
  }
  cVar2 = *(char *)((int)&param_1->_padding_ + 2);
  param_1->cur_video = param_2;
  if (((cVar2 != '\x01') && (param_3 != (char *)0x0)) && (*param_3 != '\0')) {
    sprintf(auStack_104,s__s_s_avi,param_1->_padding_ + 0x1130,param_3);
    iVar4 = __open(auStack_104,0,0x100);
    if (iVar4 == -1) {
      pcVar5 = TRegistry::RegGetAscii((TRegistry *)param_1->_padding_,0,s_CDPath);
      iVar4 = -1;
      if (pcVar5 != (char *)0x0) {
        sprintf(auStack_104,s__sgame_avi__s_avi,pcVar5,param_3);
        iVar4 = __open(auStack_104,0,0x100);
      }
      if (iVar4 == -1) goto LAB_00523abd;
    }
    if ((video_codec_available != 0) &&
       ((param_1->video_setup != 0 || (iVar4 = TRIBE_Game::setup_video_system(param_1), iVar4 != 0))
       )) {
      pvVar6 = (void *)_MCIWndCreateA(param_1->_padding_,*(undefined4 *)(param_1->_padding_ + 0x410)
                                      ,0x50001f0a,auStack_104);
      param_1->video_window = pvVar6;
      if (pvVar6 != (void *)0x0) {
        pvVar6 = (void *)GetWindowLongA(pvVar6,0xfffffffc);
        param_1->old_video_wnd_proc = pvVar6;
        SetWindowLongA(param_1->video_window,0xfffffffc,video_sub_wnd_proc);
        if (param_1->video_hi_color == 0) {
          pvVar6 = (void *)SendMessageA(param_1->video_window,0x47e,0,0);
          TDrawSystem::SetPalette((TDrawSystem *)param_1->_padding_,pvVar6);
        }
        GetClientRect(param_1->video_window,auStack_178);
        if (param_1->video_double_size != 0) {
          iStack_170 = iStack_170 * 2;
          iStack_16c = iStack_16c * 2;
        }
        MoveWindow(param_1->video_window,*(int *)(param_1->_padding_ + 0x8e0) / 2 - iStack_170 / 2,
                   *(int *)(param_1->_padding_ + 0x8e4) / 2 - iStack_16c / 2,iStack_170,iStack_16c,0
                  );
        RGE_Base_Game::set_render_all((RGE_Base_Game *)param_1);
        InvalidateRect(param_1->_padding_,0,1);
        SendMessageA(param_1->_padding_,0xf,0,0);
        TDrawSystem::ClearPrimarySurface((TDrawSystem *)param_1->_padding_);
        param_1->video_paused = 0;
        uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x598);
        param_1->last_video_time = uVar7;
        SendMessageA(param_1->video_window,0x806,0,0);
        RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
        SetCursor(0);
        SetClassLongA(param_1->_padding_,0xfffffff4,0);
        return 1;
      }
    }
  }
LAB_00523abd:
  TRIBE_Game::stop_video(param_1,'\x01');
  return 0;
}

// --------------------------------------------------

// Function: FUN_00523ad4
// Address: 00523ad4
void FUN_00523ad4(void *param_1,uint param_2,uint param_3,long param_4)
{
  TRIBE_Game::video_wnd_proc((TRIBE_Game *)rge_base_game,param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: video_sub_wnd_proc
// Address: 00523ae0
void video_sub_wnd_proc(void *param_1,uint param_2,uint param_3,long param_4)
{
  TRIBE_Game::video_wnd_proc((TRIBE_Game *)rge_base_game,param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_00523b02
// Address: 00523b02
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_Mission_Dialog: "Mission Dialog"
// [HELPER] s_introx: "introx"
// [HELPER] s_logo2: "logo2"
// [HELPER] s_lost_mid: "lost.mid"
// [HELPER] s_stopped: "stopped"
// [HELPER] s_won_mid: "won.mid"
void __thiscall FUN_00523b02(TRIBE_Game *param_1,char param_2)
{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  TRIBE_Mission_Screen *this;
  TribeAchievementsScreen *this_00;
  char *pcVar6;
  undefined4 *puVar7;
  RGE_Player *pRVar8;
  byte *pbVar9;
  undefined4 *unaff_FS_OFFSET;
  bool bVar10;
  byte abStack_70 [100];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561776;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = param_1->cur_video;
  param_1->cur_video = -1;
  if (param_1->video_window != (void *)0x0) {
    SendMessageA(param_1->video_window,0x46a,100,abStack_70);
    if (abStack_70[0] != 0) {
      pbVar9 = &s_stopped;
      pbVar3 = abStack_70;
      do {
        bVar1 = *pbVar3;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_00523b99:
          iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_00523b9e;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_00523b99;
        pbVar3 = pbVar3 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00523b9e:
      if (iVar4 != 0) {
        SendMessageA(param_1->video_window,0x808,0,0);
      }
    }
    SendMessageA(param_1->video_window,0x10,0,0);
    param_1->video_window = (void *)0x0;
    TDrawSystem::ClearPrimarySurface((TDrawSystem *)param_1->_padding_);
    TDrawSystem::SetPalette((TDrawSystem *)param_1->_padding_,(void *)param_1->_padding_);
    RGE_Base_Game::set_render_all((RGE_Base_Game *)param_1);
    InvalidateRect(param_1->_padding_,0,1);
    SendMessageA(param_1->_padding_,0xf,0,0);
    TDrawSystem::ClearPrimarySurface((TDrawSystem *)param_1->_padding_);
  }
  switch(iVar5) {
  case 0:
    if (param_2 != '\0') {
      TRIBE_Game::start_video(param_1,1,s_logo2);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 1:
    if (param_2 != '\0') {
      TRIBE_Game::start_video(param_1,2,s_introx);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 2:
  case 5:
    break;
  case 3:
    if (param_1->video_setup != 0) {
      TRIBE_Game::shutdown_video_system(param_1);
    }
    pcVar6 = RGE_Scenario::Get_description(*(RGE_Scenario **)(param_1->_padding_ + 0x5c));
    if ((((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) &&
        (iVar5 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)param_1), iVar5 == 0)) &&
       ((iVar5 = RGE_Base_Game::randomGame((RGE_Base_Game *)param_1), iVar5 == 0 ||
        (iVar5 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1), iVar5 != 0)))) {
      this = (TRIBE_Mission_Screen *)operator_new(0x49c);
      uStack_4 = 0;
      if (this != (TRIBE_Mission_Screen *)0x0) {
        TRIBE_Mission_Screen::TRIBE_Mission_Screen
                  (this,pcVar6,'\0',*(TPicture **)(*(int *)(param_1->_padding_ + 0x5c) + 0x198c));
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Mission_Dialog,0);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    TRIBE_Game::create_game_screen(param_1);
    *unaff_FS_OFFSET = uStack_c;
    return;
  case 4:
    if (param_1->video_setup != 0) {
      TRIBE_Game::shutdown_video_system(param_1);
    }
    if (param_1->_padding_ != 0) {
      TRIBE_Game::close_game_screens(param_1,0);
      this_00 = (TribeAchievementsScreen *)operator_new(0x5f8);
      uStack_4 = 1;
      if (this_00 == (TribeAchievementsScreen *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        iVar5 = 1;
        pcVar6 = TRIBE_Game::game_over_msg(param_1);
        puVar7 = (undefined4 *)
                 TribeAchievementsScreen::TribeAchievementsScreen(this_00,pcVar6,iVar5);
      }
      uStack_4 = 0xffffffff;
      if (puVar7 != (undefined4 *)0x0) {
        if (puVar7[0x36] == 0) {
          TPanelSystem::setCurrentPanel(&panel_system,s_Achievements_Screen,0);
          if (param_1->_padding_ != 0) {
            cVar2 = *(char *)(param_1->_padding_ + 0x104);
            if (cVar2 == '\x01') {
              pRVar8 = RGE_Base_Game::get_player((RGE_Base_Game *)param_1);
              if (pRVar8->game_status != '\x01') {
                TMusic_System::play_track((TMusic_System *)param_1->_padding_,4,0,0);
                *unaff_FS_OFFSET = uStack_c;
                return;
              }
              TMusic_System::play_track((TMusic_System *)param_1->_padding_,3,0,0);
              *unaff_FS_OFFSET = uStack_c;
              return;
            }
            if (cVar2 == '\x02') {
              pRVar8 = RGE_Base_Game::get_player((RGE_Base_Game *)param_1);
              if (pRVar8->game_status != '\x01') {
                TMusic_System::play_file((TMusic_System *)param_1->_padding_,s_lost_mid,0,0);
                *unaff_FS_OFFSET = uStack_c;
                return;
              }
              TMusic_System::play_file((TMusic_System *)param_1->_padding_,s_won_mid,0,0);
              *unaff_FS_OFFSET = uStack_c;
              return;
            }
          }
          goto switchD_00523c17_default;
        }
        if (puVar7 != (undefined4 *)0x0) {
          (**(code **)*puVar7)(1);
        }
      }
      TRIBE_Game::quit_game(param_1);
    }
  default:
    goto switchD_00523c17_default;
  }
  iVar5 = TRIBE_Game::start_menu(param_1);
  if (iVar5 == 0) {
    RGE_Base_Game::close((RGE_Base_Game *)param_1);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
switchD_00523c17_default:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00523ef6
// Address: 00523ef6
// [HELPER] s_Campaign_Selection_Screen: "Campaign Selection Screen"
// [HELPER] s_open_mid: "open.mid"
// [HELPER] s_open_wav: "open.wav"
undefined4 __fastcall FUN_00523ef6(TRIBE_Game *param_1,int param_2)
{
  uchar uVar1;
  TMusic_System *this;
  int in_EAX;
  TRIBE_Screen_Campaign_Selection *this_00;
  undefined4 *puVar2;
  int unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 uStack_18;
  code *pcStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  *(char *)(unaff_EBX + 0x3c) = *(char *)(unaff_EBX + 0x3c) + (char)param_1;
  *(char *)(in_EAX + 0x3c) = *(char *)(in_EAX + 0x3c) + (char)((uint)unaff_EBX >> 8);
  *(char *)(param_2 + 0x7e00523c) = *(char *)(param_2 + 0x7e00523c) + (char)((uint)in_EAX >> 8);
  *(char *)(param_2 + -1) = *(char *)(param_2 + -1) + (char)((uint)param_1 >> 8);
  pcStack_14 = FUN_0056178b;
  uStack_18 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_18;
  iStack_10 = param_2;
  iStack_c = param_2;
  iStack_8 = param_2;
  if (param_1->video_setup != 0) {
    TRIBE_Game::shutdown_video_system(param_1);
  }
  this_00 = (TRIBE_Screen_Campaign_Selection *)operator_new(0x4cc);
  iStack_10 = 0;
  if (this_00 == (TRIBE_Screen_Campaign_Selection *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(this_00)
    ;
  }
  iStack_10 = 0xffffffff;
  if (puVar2 == (undefined4 *)0x0) {
    *unaff_FS_OFFSET = uStack_18;
    return 0;
  }
  if (puVar2[0x36] != 0) {
    (**(code **)*puVar2)(1);
    *unaff_FS_OFFSET = this_00;
    return 0;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Campaign_Selection_Screen,0);
  (**(code **)(param_1->_padding_ + 0xc))(2);
  this = (TMusic_System *)param_1->_padding_;
  if ((this == (TMusic_System *)0x0) || (param_1->started_menu_music != 0)) goto LAB_0052400d;
  uVar1 = this->music_type;
  if (uVar1 == '\x01') {
    TMusic_System::play_track(this,2,0,0);
  }
  else {
    if (uVar1 == '\x02') {
      pcVar3 = s_open_mid;
    }
    else {
      if (uVar1 != '\x03') goto LAB_00524003;
      pcVar3 = s_open_wav;
    }
    TMusic_System::play_file(this,pcVar3,0,0);
  }
LAB_00524003:
  param_1->started_menu_music = 1;
LAB_0052400d:
  *unaff_FS_OFFSET = this_00;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00524022
// Address: 00524022
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_open_mid: "open.mid"
// [HELPER] s_open_wav: "open.wav"
undefined4 __fastcall FUN_00524022(TRIBE_Game *param_1)
{
  uchar uVar1;
  TMusic_System *this;
  TRIBE_Screen_Main_Menu *this_00;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005617ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_1->video_setup != 0) {
    TRIBE_Game::shutdown_video_system(param_1);
  }
  this_00 = (TRIBE_Screen_Main_Menu *)operator_new(0x4b0);
  uStack_4 = 0;
  if (this_00 == (TRIBE_Screen_Main_Menu *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(this_00);
  }
  uStack_4 = 0xffffffff;
  if (puVar2 == (undefined4 *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  if (puVar2[0x36] != 0) {
    (**(code **)*puVar2)(1);
    *unaff_FS_OFFSET = this_00;
    return 0;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
  (**(code **)(param_1->_padding_ + 0xc))(2);
  this = (TMusic_System *)param_1->_padding_;
  if ((this == (TMusic_System *)0x0) || (param_1->started_menu_music != 0)) goto LAB_0052412d;
  uVar1 = this->music_type;
  if (uVar1 == '\x01') {
    TMusic_System::play_track(this,2,0,0);
  }
  else {
    if (uVar1 == '\x02') {
      pcVar3 = s_open_mid;
    }
    else {
      if (uVar1 != '\x03') goto LAB_00524123;
      pcVar3 = s_open_wav;
    }
    TMusic_System::play_file(this,pcVar3,0,0);
  }
LAB_00524123:
  param_1->started_menu_music = 1;
LAB_0052412d:
  *unaff_FS_OFFSET = this_00;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00524142
// Address: 00524142
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Join_Screen: "Join Screen"
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
void __fastcall FUN_00524142(TRIBE_Game *param_1)
{
  char *pcVar1;
  bool bVar2;
  uchar uVar3;
  int iVar4;
  TribeJoinScreen *this;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar5;
  char acStack_228 [260];
  undefined1 auStack_124 [280];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005617ce;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  bVar2 = false;
  iVar4 = TCommunications_Handler::IsLobbyLaunched((TCommunications_Handler *)param_1->_padding_);
  if ((iVar4 != 0) && ((TRIBE_World *)param_1->_padding_ != (TRIBE_World *)0x0)) {
    TRIBE_World::send_zone_score_info((TRIBE_World *)param_1->_padding_);
  }
  TRIBE_Game::disconnect_multiplayer_game(param_1);
  param_1->_padding_ = 0;
  if (do_debug_random != 0) {
    debug_random_write();
    dump_vismap_log();
  }
  iVar4 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)param_1);
  if (((iVar4 == 1) && (iVar4 = param_1->_padding_, iVar4 != 0)) && (-1 < *(int *)(iVar4 + 0xa4))) {
    uVar3 = RGE_Game_Info::set_current_person
                      ((RGE_Game_Info *)param_1->_padding_,*(long *)(iVar4 + 0xa8));
    if (uVar3 != '\0') {
      uVar3 = RGE_Game_Info::set_current_campaign
                        ((RGE_Game_Info *)param_1->_padding_,*(long *)(param_1->_padding_ + 0xa4));
      if (uVar3 != '\0') {
        bVar2 = true;
      }
    }
  }
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0xb8))();
  }
  iVar4 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)param_1);
  if (iVar4 == 1) {
    if (bVar2) {
      iVar4 = TRIBE_Game::start_campaign_menu(param_1);
      if (iVar4 == 0) {
        RGE_Base_Game::close((RGE_Base_Game *)param_1);
      }
    }
    else {
      pcVar1 = param_1->testing_scenario;
      if (param_1->testing_scenario[0] != '\0') {
        TRIBE_Game::close_game_screens(param_1,0);
        param_1->game_screen = (TRIBE_Screen_Game *)0x0;
        TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
        sprintf(acStack_228,s__s_s_scn,param_1->_padding_ + 0xc17,pcVar1);
        iVar4 = __findfirst(acStack_228,auStack_124);
        if (iVar4 == -1) {
          pcVar5 = s__s_scx;
        }
        else {
          pcVar5 = s__s_scn;
        }
        sprintf(acStack_228,pcVar5,pcVar1);
        *pcVar1 = '\0';
        iVar4 = TRIBE_Game::start_scenario_editor(param_1,acStack_228,0);
        if (iVar4 != 0) {
          *pcVar1 = '\0';
          goto LAB_0052437e;
        }
      }
      iVar4 = TRIBE_Game::start_menu(param_1);
      if (iVar4 == 0) {
        RGE_Base_Game::close((RGE_Base_Game *)param_1);
      }
    }
  }
  else {
    iVar4 = TCommunications_Handler::IsLobbyLaunched((TCommunications_Handler *)param_1->_padding_);
    if (iVar4 != 0) {
      RGE_Base_Game::close((RGE_Base_Game *)param_1);
      goto LAB_0052437e;
    }
    this = (TribeJoinScreen *)operator_new(0x4b0);
    uStack_4 = 0;
    if (this != (TribeJoinScreen *)0x0) {
      TribeJoinScreen::TribeJoinScreen(this);
    }
    uStack_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Join_Screen,0);
    (**(code **)(param_1->_padding_ + 0xc))(2);
  }
  TRIBE_Game::close_game_screens(param_1,0);
  param_1->game_screen = (TRIBE_Screen_Game *)0x0;
  TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
  param_1->testing_scenario[0] = '\0';
LAB_0052437e:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00524396
// Address: 00524396
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s__s_gam: "%s.gam"
// [HELPER] s__s_gmx: "%s.gmx"
// [HELPER] s__s_s_gmx: "%s%s.gmx"
void __fastcall FUN_00524396(TRIBE_Game *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  TEasy_Panel *this;
  int *piVar4;
  uint uVar5;
  char *pcVar6;
  char acStack_21c [260];
  undefined1 auStack_118 [280];
  
  TRIBE_Game::show_status_message(param_1,0x451,(char *)0x0,-1);
  TRIBE_Game::close_game_screens(param_1,0);
  param_1->game_screen = (TRIBE_Screen_Game *)0x0;
  TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
  param_1->_padding_ = 0;
  (**(code **)(*(int *)param_1->_padding_ + 0xb8))();
  uVar5 = 1;
  piVar4 = param_1->save_humanity;
  do {
    piVar4 = piVar4 + 1;
    TCommunications_Handler::SetPlayerHumanity
              ((TCommunications_Handler *)param_1->_padding_,uVar5,*piVar4);
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 9);
  iVar1 = RGE_Base_Game::savedGame((RGE_Base_Game *)param_1);
  if (iVar1 == 0) {
    iVar1 = 0;
    iVar2 = RGE_Base_Game::randomGame((RGE_Base_Game *)param_1);
    if (iVar2 == 1) {
      iVar2 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
      if (iVar2 == 0) {
        iVar1 = param_1->_padding_;
        param_1->_padding_ = param_1->_padding_;
      }
    }
    iVar2 = TRIBE_Game::start_game(param_1,1);
    iVar3 = RGE_Base_Game::randomGame((RGE_Base_Game *)param_1);
    if (iVar3 != 0) {
      iVar3 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
      if (iVar3 == 0) {
        param_1->_padding_ = iVar1;
      }
    }
  }
  else {
    sprintf(acStack_21c,s__s_s_gmx,param_1->_padding_ + 0xb12,param_1->load_game_name);
    iVar1 = __findfirst(acStack_21c,auStack_118);
    if (iVar1 == -1) {
      pcVar6 = s__s_gam;
    }
    else {
      pcVar6 = s__s_gmx;
    }
    sprintf(acStack_21c,pcVar6,param_1->load_game_name);
    iVar2 = TRIBE_Game::load_game(param_1,acStack_21c);
  }
  if (iVar2 == 0) {
    iVar1 = TRIBE_Game::start_menu(param_1);
    if (iVar1 == 0) {
      RGE_Base_Game::close((RGE_Base_Game *)param_1);
      return;
    }
    this = (TEasy_Panel *)TPanelSystem::panel(&panel_system,s_Main_Menu);
    if (this != (TEasy_Panel *)0x0) {
      TEasy_Panel::popupOKDialog(this,0x961,(char *)0x0,0x1c2,100);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00524525
// Address: 00524525
bool __fastcall FUN_00524525(TRIBE_Game *param_1)
{
  char cVar1;
  int *piVar2;
  bool bVar3;
  
  RGE_Base_Game::disable_input((RGE_Base_Game *)param_1);
  TRIBE_Game::show_status_message(param_1,0x44d,(char *)0x0,-1);
  bVar3 = false;
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0xa0))(1);
    param_1->_padding_ = 0;
  }
  piVar2 = (int *)(**(code **)(param_1->_padding_ + 0xb4))();
  param_1->_padding_ = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0xac))(param_1->_padding_ + 0x1f8,param_1->_padding_ + 0xf3);
    bVar3 = cVar1 != '\0';
    if ((int *)param_1->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xa0))(1);
    }
    param_1->_padding_ = 0;
  }
  TRIBE_Game::close_status_message(param_1);
  RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
  return bVar3;
}

// --------------------------------------------------

// Function: FUN_0052463d
// Address: 0052463d
// [HELPER] s_DEBUGSAVEGAME: "DEBUGSAVEGAME"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Status_Screen: "Status Screen"
undefined4 __thiscall FUN_0052463d(TRIBE_Game *param_1,char *param_2)
{
  uchar uVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char acStack_108 [264];
  
  iVar4 = param_1->_padding_;
  if ((((iVar4 != 4) && (iVar4 != 6)) && (iVar4 != 7)) && (iVar4 != 5)) {
    return 0;
  }
  RGE_Base_Game::disable_input((RGE_Base_Game *)param_1);
  TRIBE_Game::show_status_message(param_1,0x453,(char *)0x0,-1);
  uVar1 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)param_1,s_DEBUGSAVEGAME);
  if (uVar1 != '\0') {
    ENABLE_COMPRESSION = 0;
  }
  cVar2 = (**(code **)(*(int *)param_1->_padding_ + 0xd8))(param_2);
  ENABLE_COMPRESSION = 1;
  if (cVar2 == '\0') {
    TRIBE_Game::close_status_message(param_1);
    RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
    return 0;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar7 = param_2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = param_2 + 1;
    cVar2 = *param_2;
    param_2 = pcVar7;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar7 + -uVar5;
  pcVar8 = acStack_108;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  puVar3 = (undefined1 *)strchr(acStack_108,0x2e);
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 0;
  }
  TRIBE_Game::set_save_game_name(param_1,acStack_108);
  iVar4 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)param_1);
  if (iVar4 == 1) {
    RGE_Base_Game::set_paused((RGE_Base_Game *)param_1,0,0);
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0052478c
// Address: 0052478c
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_Status_Screen: "Status Screen"
undefined4 __thiscall FUN_0052478c(TRIBE_Game *param_1,undefined4 param_2)
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1->_padding_;
  if ((((iVar2 != 4) && (iVar2 != 6)) && (iVar2 != 7)) && (iVar2 != 5)) {
    return 0;
  }
  RGE_Base_Game::disable_input((RGE_Base_Game *)param_1);
  TRIBE_Game::show_status_message(param_1,0x450,(char *)0x0,-1);
  iVar2 = param_1->_padding_;
  iVar3 = 1;
  if (1 < *(short *)(iVar2 + 0x3c)) {
    do {
      RGE_Scenario::Set_player_Active(*(RGE_Scenario **)(iVar2 + 0x5c),iVar3 + -1,1);
      iVar2 = param_1->_padding_;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(iVar2 + 0x3c));
  }
  cVar1 = (**(code **)(*(int *)param_1->_padding_ + 0xe4))(param_2);
  if (cVar1 == '\0') {
    RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
    return 0;
  }
  iVar2 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)param_1);
  if (iVar2 == 1) {
    RGE_Base_Game::set_paused((RGE_Base_Game *)param_1,0,0);
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
  TPanelSystem::destroyPanel(&panel_system,s_Save_Game_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00524874
// Address: 00524874
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
// [HELPER] s_avg_view_time____: "avg view time=???"
// [HELPER] s_avg_view_time__lu__count__lu: "avg view time=%lu, count=%lu"
// [HELPER] s_f_: "f?"
// [HELPER] s_t_lu_f_lu_avg_r_v_lu_m_lu_o_lu__: "t%lu,f%lu,avg(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,l%lu,p%lu,o%lu)"
// [HELPER] s_t_lu_f_lu_max_r_v_lu_m_lu_o_lu__: "t%lu,f%lu,max(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,ls%lu,lg%lu,p%lu,o%lu)"
void __fastcall FUN_00524874(int param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if ((DAT_0086bcd0 & 1) == 0) {
    DAT_0086bcd0 = DAT_0086bcd0 | 1;
    DAT_0086bcd8._0_4_ = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x7d4);
  }
  DAT_0086bcd8._0_4_ = debug_timeGetTime(s_C__msdev_work_age1_x1_tribegam_c,0x7d6);
  uVar2 = *(uint *)(param_1 + 0x508);
  if (uVar2 == 0) {
    uVar2 = 0xffffffff;
    pcVar4 = &s_f_;
    do {
      pcVar5 = pcVar4;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar5 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar5;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar4 = pcVar5 + -uVar2;
    pcVar5 = (char *)(param_1 + 0x106c);
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
  }
  else if (show_timing_max == 0) {
    sprintf(param_1 + 0x106c,s_t_lu_f_lu_avg_r_v_lu_m_lu_o_lu__,*(undefined4 *)(param_1 + 0x520),
            *(undefined4 *)(param_1 + 0x524),*(uint *)(param_1 + 0x5ec) / uVar2,
            *(uint *)(param_1 + 0x60c) / uVar2,*(uint *)(param_1 + 0x74c) / uVar2,
            *(uint *)(param_1 + 0x58c) / uVar2,*(uint *)(param_1 + 0x54c) / uVar2,
            *(uint *)(param_1 + 0x6ec) / uVar2,
            (uint)(*(int *)(param_1 + 0x66c) + *(int *)(param_1 + 0x6ac)) / uVar2,
            *(uint *)(param_1 + 0x6cc) / uVar2,*(uint *)(param_1 + 0x5ac) / uVar2);
  }
  else {
    sprintf(param_1 + 0x106c,s_t_lu_f_lu_max_r_v_lu_m_lu_o_lu__,*(undefined4 *)(param_1 + 0x520),
            *(undefined4 *)(param_1 + 0x524),*(undefined4 *)(param_1 + 0x604),
            *(undefined4 *)(param_1 + 0x624),*(undefined4 *)(param_1 + 0x764),
            *(undefined4 *)(param_1 + 0x5a4),*(undefined4 *)(param_1 + 0x564),
            *(undefined4 *)(param_1 + 0x704),*(undefined4 *)(param_1 + 0x684),
            *(undefined4 *)(param_1 + 0x6c4),*(undefined4 *)(param_1 + 0x6e4),
            *(undefined4 *)(param_1 + 0x5c4));
  }
  uVar2 = *(uint *)(param_1 + 0x50c);
  if (uVar2 != 0) {
    sprintf(param_1 + 0x404,s_avg_view_time__lu__count__lu,*(uint *)(param_1 + 0x5ec) / uVar2,uVar2)
    ;
    return;
  }
  uVar2 = 0xffffffff;
  pcVar4 = &s_avg_view_time____;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = (char *)(param_1 + 0x404);
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

// Function: FUN_00524a5c
// Address: 00524a5c
void __fastcall FUN_00524a5c(int param_1)
{
  if (*(TRIBE_Screen_Game **)(param_1 + 0xc24) != (TRIBE_Screen_Game *)0x0) {
    TRIBE_Screen_Game::show_timings
              (*(TRIBE_Screen_Game **)(param_1 + 0xc24),(char *)(param_1 + 0x404),
               (char *)(param_1 + 0x106c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00524a7f
// Address: 00524a7f
void __fastcall FUN_00524a7f(int param_1)
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (*(int *)(param_1 + 0xc24) != 0) {
    pcVar1 = TCommunications_Handler::GetCommInfo
                       (*(TCommunications_Handler **)(param_1 + 0x18c),'\x06');
    pcVar2 = TCommunications_Handler::GetCommInfo
                       (*(TCommunications_Handler **)(param_1 + 0x18c),'\x05');
    pcVar3 = TCommunications_Handler::GetCommInfo
                       (*(TCommunications_Handler **)(param_1 + 0x18c),'\x04');
    pcVar4 = TCommunications_Handler::GetCommInfo
                       (*(TCommunications_Handler **)(param_1 + 0x18c),'\x03');
    pcVar5 = TCommunications_Handler::GetCommInfo
                       (*(TCommunications_Handler **)(param_1 + 0x18c),'\x02');
    pcVar6 = TCommunications_Handler::GetCommInfo
                       (*(TCommunications_Handler **)(param_1 + 0x18c),'\x01');
    TRIBE_Screen_Game::show_comm
              (*(TRIBE_Screen_Game **)(param_1 + 0xc24),pcVar6,pcVar5,pcVar4,pcVar3,pcVar2,pcVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00524aee
// Address: 00524aee
// [HELPER] s_: ""
// [HELPER] s_Player___d__AI_is_not_functional: "Player #%d: AI is not functional."
// [HELPER] s_Player___d___s: "Player #%d: %s"
// [HELPER] s_Player___d_is_not_a_computer_pla: "Player #%d is not a computer player."
void __fastcall FUN_00524aee(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int unaff_EBX;
  char *pcVar9;
  int *piVar10;
  char *pcVar11;
  int aiStack_604 [64];
  char acStack_504 [256];
  char acStack_404 [256];
  char acStack_304 [256];
  char acStack_204 [256];
  int aiStack_104 [65];
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x3f4) + 0x40);
  if (iVar3 != 0) {
    aiStack_604[0] = param_1;
    iVar2 = RGE_Player::computerPlayer
                      (*(RGE_Player **)(iVar3 + *(short *)(*(int *)(param_1 + 0x3f4) + 0x7c) * 4));
    iVar3 = **(int **)(*(int *)(*(int *)(param_1 + 0x3f4) + 0x40) +
                      *(short *)(*(int *)(param_1 + 0x3f4) + 0x7c) * 4);
    if (iVar2 == 1) {
      iVar3 = (**(code **)(iVar3 + 0x14))(1);
      if (iVar3 == 0) {
        sprintf(aiStack_604,s_Player___d__AI_is_not_functional,
                (int)*(short *)(*(int *)(param_1 + 0x3f4) + 0x7c));
      }
      else {
        sprintf(aiStack_604,s_Player___d___s,(int)*(short *)(*(int *)(param_1 + 0x3f4) + 0x7c),iVar3
               );
      }
      iVar3 = 2;
      pcVar5 = acStack_404;
      do {
        pcVar4 = (char *)(**(code **)(**(int **)(*(int *)(*(int *)(unaff_EBX + 0x3f4) + 0x40) +
                                                *(short *)(*(int *)(unaff_EBX + 0x3f4) + 0x7c) * 4)
                                     + 0x14))(iVar3);
        pcVar11 = pcVar5 + -0x100;
        pcVar9 = s_;
        if (pcVar4 != (char *)0x0) {
          pcVar9 = pcVar4;
        }
        uVar6 = 0xffffffff;
        do {
          pcVar4 = pcVar9;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar4 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar4;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        pcVar5 = pcVar5 + 0x100;
        pcVar9 = pcVar4 + -uVar6;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar11 = pcVar11 + 4;
        }
        iVar3 = iVar3 + 1;
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar11 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar11 = pcVar11 + 1;
        }
      } while (iVar3 < 7);
    }
    else {
      pcVar5 = (char *)(**(code **)(iVar3 + 0x14))(0);
      uVar6 = 0xffffffff;
      do {
        pcVar11 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      piVar10 = (int *)(pcVar11 + -uVar6);
      piVar8 = aiStack_604;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *piVar8 = *piVar10;
        piVar10 = piVar10 + 1;
        piVar8 = piVar8 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)piVar8 = (char)*piVar10;
        piVar10 = (int *)((int)piVar10 + 1);
        piVar8 = (int *)((int)piVar8 + 1);
      }
      sprintf(acStack_504,s_Player___d_is_not_a_computer_pla,
              (int)*(short *)(*(int *)(param_1 + 0x3f4) + 0x7c));
      uVar6 = 0xffffffff;
      pcVar5 = s_;
      do {
        pcVar11 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar5 = pcVar11 + -uVar6;
      pcVar11 = acStack_404;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar5 = s_;
      do {
        pcVar11 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar5 = pcVar11 + -uVar6;
      pcVar11 = acStack_304;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar5 = s_;
      do {
        pcVar11 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar5 = pcVar11 + -uVar6;
      pcVar11 = acStack_204;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar5 = s_;
      do {
        pcVar11 = pcVar5;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      piVar10 = (int *)(pcVar11 + -uVar6);
      piVar8 = aiStack_104;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *piVar8 = *piVar10;
        piVar10 = piVar10 + 1;
        piVar8 = piVar8 + 1;
      }
      for (uVar6 = uVar6 & 3; unaff_EBX = param_1, uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)piVar8 = (char)*piVar10;
        piVar10 = (int *)((int)piVar10 + 1);
        piVar8 = (int *)((int)piVar8 + 1);
      }
    }
    if (*(int *)(unaff_EBX + 0xc24) != 0) {
      iVar3 = RGE_Player::computerPlayer
                        (*(RGE_Player **)
                          (*(int *)(*(int *)(unaff_EBX + 0x3f4) + 0x40) +
                          *(short *)(*(int *)(unaff_EBX + 0x3f4) + 0x7c) * 4));
      if (iVar3 == 1) {
        piVar10 = aiStack_604;
        pcVar5 = acStack_504;
        pcVar11 = acStack_404;
        pcVar9 = acStack_304;
        pcVar4 = acStack_204;
        piVar8 = aiStack_104;
      }
      else {
        piVar10 = aiStack_104;
        pcVar5 = acStack_204;
        pcVar11 = acStack_304;
        pcVar9 = acStack_404;
        pcVar4 = acStack_504;
        piVar8 = aiStack_604;
      }
      TRIBE_Screen_Game::show_ai
                (*(TRIBE_Screen_Game **)(unaff_EBX + 0xc24),(char *)piVar8,pcVar4,pcVar9,pcVar11,
                 pcVar5,(char *)piVar10);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00524d6c
// Address: 00524d6c
void __thiscall
FUN_00524d6c(TRIBE_Game *param_1,long param_2,int param_3,int param_4,int param_5,long param_6)
{
  RGE_Player *pRVar1;
  RGE_Player *pRVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  long unaff_retaddr;
  undefined4 uVar6;
  char *pcVar7;
  char acStack_200 [244];
  undefined1 auStack_10c [264];
  int iStack_4;
  
  switch(param_2) {
  case 1:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0x66;
LAB_005250a4:
      (**(code **)(iVar4 + 0x28))(0x67,uVar6,0);
      TRIBE_Screen_Game::show_message(param_1->game_screen,BadMessage,&stack0xfffffdec,'U','\0');
      return;
    }
    break;
  case 2:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0x67;
      goto LAB_005250a4;
    }
    break;
  case 3:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0x69;
      goto LAB_005250a4;
    }
    break;
  case 4:
    iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,param_3);
    if (((iVar4 != *(short *)(param_1->_padding_ + 0x7c)) &&
        (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) &&
       ((&player_dropped)[param_3] == (int *)0x0)) {
      (&player_dropped)[param_3] = (int *)0x1;
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,7);
      iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,param_3);
      if (0 < iVar4) {
        (**(code **)(param_1->_padding_ + 0x20))(0xbc4);
        iVar4 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,param_3);
        sprintf(&stack0xfffffdf4,auStack_10c,
                *(undefined4 *)(*(int *)(*(int *)(param_1->_padding_ + 0x40) + iVar4 * 4) + 0x44));
        TRIBE_Screen_Game::display_system_message(param_1->game_screen,&stack0xfffffdf4);
        return;
      }
    }
    break;
  case 5:
    if (((param_3 != *(short *)(param_1->_padding_ + 0x7c)) &&
        (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) && (0 < param_3)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,6);
      iVar4 = param_1->_padding_;
      if (param_4 == 0) {
        (**(code **)(iVar4 + 0x20))(0xbc5);
        sprintf(&stack0xfffffdf4,auStack_10c,
                *(undefined4 *)(*(int *)(*(int *)(param_1->_padding_ + 0x40) + param_3 * 4) + 0x44))
        ;
        TRIBE_Screen_Game::display_system_message(param_1->game_screen,&stack0xfffffdf4);
        return;
      }
      uVar6 = 0xbc4;
LAB_00525284:
      (**(code **)(iVar4 + 0x20))(uVar6);
      sprintf(&stack0xfffffdf4,auStack_10c,
              *(undefined4 *)(*(int *)(*(int *)(param_1->_padding_ + 0x40) + param_3 * 4) + 0x44));
      TRIBE_Screen_Game::display_system_message(param_1->game_screen,&stack0xfffffdf4);
      return;
    }
    break;
  case 6:
    if (((param_3 != *(short *)(param_1->_padding_ + 0x7c)) &&
        (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) &&
       (RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,6), 0 < param_3)) {
      iVar4 = param_1->_padding_;
      uVar6 = 0xbc6;
      goto LAB_00525284;
    }
    break;
  case 7:
    if ((param_4 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,4);
      if (param_5 == 0) {
        iVar4 = param_1->_padding_;
        uVar6 = 0xbc8;
      }
      else if (param_5 == 1) {
        iVar4 = param_1->_padding_;
        uVar6 = 0xbc7;
      }
      else {
        iVar4 = param_1->_padding_;
        if (param_5 == 3) {
          uVar6 = 0xbc1;
        }
        else {
          uVar6 = 0xbc9;
        }
      }
      (**(code **)(iVar4 + 0x20))(uVar6);
      sprintf(&stack0xfffffdf4,auStack_10c,
              *(undefined4 *)(*(int *)(*(int *)(param_1->_padding_ + 0x40) + iStack_4 * 4) + 0x44),
              param_3);
      TRIBE_Screen_Game::display_system_message(param_1->game_screen,&stack0xfffffdf4);
      return;
    }
    break;
  case 8:
    if (param_1->game_screen != (TRIBE_Screen_Game *)0x0) {
      TRIBE_Screen_Game::reset_clocks(param_1->game_screen);
    }
    if (param_4 != *(short *)(param_1->_padding_ + 0x7c)) {
      return;
    }
    if (param_1->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    if (param_5 == 0) {
      iVar4 = param_1->_padding_;
      uVar6 = 0xbd2;
    }
    else {
      if (param_5 != 1) {
        if (param_5 == 3) {
          (**(code **)(param_1->_padding_ + 0x20))(0xbd3);
        }
        goto LAB_0052543e;
      }
      iVar4 = param_1->_padding_;
      uVar6 = 0xbd1;
    }
    (**(code **)(iVar4 + 0x20))(uVar6);
LAB_0052543e:
    sprintf(acStack_200);
    TRIBE_Screen_Game::display_system_message(param_1->game_screen,acStack_200);
    return;
  case 100:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      if ((param_4 == 0x65) || ((param_4 == 0x66 || (param_4 == 0x67)))) {
        iVar4 = 5;
      }
      else {
        iVar4 = 0xf;
      }
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,iVar4);
      TRIBE_Screen_Game::setup_buttons(param_1->game_screen);
      TRIBE_Game::add_notification_loc(param_1,param_5,param_6);
      return;
    }
    break;
  case 0x66:
  case 0x69:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      TRIBE_Screen_Game::setup_buttons(param_1->game_screen);
      TRIBE_Game::add_notification_loc(param_1,param_5,param_6);
      return;
    }
    break;
  case 0x68:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 1000;
LAB_00524f71:
      (**(code **)(iVar4 + 0x28))(0x67,uVar6,param_4);
      TRIBE_Screen_Game::show_message(param_1->game_screen,BadMessage,&stack0xfffffdec,'U','\0');
      return;
    }
    break;
  case 0x6b:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0x6a;
      goto LAB_005250a4;
    }
    break;
  case 0x6c:
    if (param_1->game_screen != (TRIBE_Screen_Game *)0x0) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,8);
      if (param_3 == *(short *)(param_1->_padding_ + 0x7c)) {
        (**(code **)(param_1->_padding_ + 0x20))(0xbf2);
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1->_padding_ + 0x40) + param_3 * 4);
        (**(code **)(param_1->_padding_ + 0x20))(0xbcb);
        sprintf(&stack0xfffffdf4,auStack_10c,*(undefined4 *)(iVar4 + 0x44));
      }
      TRIBE_Screen_Game::display_system_message(param_1->game_screen,&stack0xfffffdf4);
      TRIBE_Game::add_notification_loc(param_1,unaff_retaddr,param_2);
      return;
    }
    break;
  case 0x6d:
    if (param_1->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,9);
    iVar4 = param_1->_padding_;
    pRVar1 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + param_3 * 4);
    pRVar2 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + *(short *)(iVar4 + 0x7c) * 4);
    if (pRVar1 == pRVar2) {
      if (*(int *)(iVar4 + 0x108) == 0) {
        (**(code **)(param_1->_padding_ + 0x20))(0xbcc);
      }
      else {
        (**(code **)(param_1->_padding_ + 0x20))(0xbee);
      }
    }
    else {
      if ((((pRVar1->allied_victory == '\0') ||
           (uVar3 = RGE_Player::relation(pRVar1,(int)pRVar2->id), uVar3 != '\0')) ||
          (pRVar2->allied_victory == '\0')) ||
         (uVar3 = RGE_Player::relation(pRVar2,(int)pRVar1->id), uVar3 != '\0')) {
        iVar4 = param_1->_padding_;
        if (*(int *)(param_1->_padding_ + 0x108) != 0) goto LAB_00525645;
        (**(code **)(iVar4 + 0x20))(0xbce);
        pcVar7 = pRVar1->name;
      }
      else {
        iVar4 = param_1->_padding_;
        if (*(int *)(param_1->_padding_ + 0x108) == 0) {
          (**(code **)(iVar4 + 0x20))(0xbcd);
          pcVar7 = pRVar1->name;
        }
        else {
LAB_00525645:
          (**(code **)(iVar4 + 0x20))(0xbef);
          pcVar7 = pRVar1->name;
        }
      }
LAB_00525745:
      sprintf(&stack0xfffffdf4,auStack_10c,pcVar7);
    }
    goto LAB_0052574d;
  case 0x6e:
    if (param_1->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    if (*(int *)(param_1->_padding_ + 0x108) != 0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,10);
    iVar4 = *(int *)(param_1->_padding_ + 0x40);
    pRVar1 = *(RGE_Player **)(iVar4 + param_3 * 4);
    pRVar2 = *(RGE_Player **)(iVar4 + *(short *)(param_1->_padding_ + 0x7c) * 4);
    if (pRVar1 != pRVar2) {
      if (((pRVar1->allied_victory == '\0') ||
          (uVar3 = RGE_Player::relation(pRVar1,(int)pRVar2->id), uVar3 != '\0')) ||
         ((pRVar2->allied_victory == '\0' ||
          (uVar3 = RGE_Player::relation(pRVar2,(int)pRVar1->id), uVar3 != '\0')))) {
        (**(code **)(param_1->_padding_ + 0x20))(0xbd0);
        pcVar7 = pRVar1->name;
      }
      else {
        (**(code **)(param_1->_padding_ + 0x20))(0xbd0);
        pcVar7 = pRVar1->name;
      }
      goto LAB_00525745;
    }
    (**(code **)(param_1->_padding_ + 0x20))(0xbcf);
LAB_0052574d:
    TRIBE_Game::add_notification_loc(param_1,unaff_retaddr,param_2);
LAB_00525a51:
    TRIBE_Screen_Game::display_system_message(param_1->game_screen,&stack0xfffffdf4);
    TRIBE_Screen_Game::reset_clocks(param_1->game_screen);
    return;
  case 0x72:
    if (param_1->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,0xb);
    iVar4 = param_1->_padding_;
    pRVar1 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + param_3 * 4);
    pRVar2 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + *(short *)(iVar4 + 0x7c) * 4);
    if (*(int *)(iVar4 + 0x108) == 0) {
      if (pRVar1 != pRVar2) {
        if (((pRVar1->allied_victory == '\0') ||
            (uVar3 = RGE_Player::relation(pRVar1,(int)pRVar2->id), uVar3 != '\0')) ||
           ((pRVar2->allied_victory == '\0' ||
            (uVar3 = RGE_Player::relation(pRVar2,(int)pRVar1->id), uVar3 != '\0')))) {
          iVar4 = param_1->_padding_;
          uVar6 = 0xbd5;
        }
        else {
          iVar4 = param_1->_padding_;
          uVar6 = 0xbd4;
        }
        goto LAB_00525830;
      }
      (**(code **)(param_1->_padding_ + 0x20))(0xbd4);
    }
    else {
      iVar4 = param_1->_padding_;
      uVar6 = 0xbf0;
LAB_00525830:
      (**(code **)(iVar4 + 0x20))(uVar6);
    }
    TRIBE_Screen_Game::display_system_message(param_1->game_screen,&stack0xfffffdf4);
    TRIBE_Screen_Game::reset_clocks(param_1->game_screen);
    iVar4 = param_1->_padding_;
    iVar5 = 1;
    if (1 < *(short *)(iVar4 + 0x3c)) {
      do {
        (**(code **)(**(int **)(*(int *)(iVar4 + 0x40) + iVar5 * 4) + 0xe8))
                  ((int)pRVar1->id,iVar5,0x72,0,0,0);
        iVar4 = param_1->_padding_;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(iVar4 + 0x3c));
      return;
    }
    break;
  case 0x73:
    if (param_1->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    if (*(int *)(param_1->_padding_ + 0x108) != 0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,0xc);
    iVar4 = param_1->_padding_;
    uVar6 = 0xbd6;
    goto LAB_00525a47;
  case 0x74:
    if (param_1->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,0xb);
    iVar4 = param_1->_padding_;
    pRVar1 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + param_3 * 4);
    pRVar2 = *(RGE_Player **)(*(int *)(iVar4 + 0x40) + *(short *)(iVar4 + 0x7c) * 4);
    if (*(int *)(iVar4 + 0x108) == 0) {
      if (pRVar1 != pRVar2) {
        if ((((pRVar1->allied_victory == '\0') ||
             (uVar3 = RGE_Player::relation(pRVar1,(int)pRVar2->id), uVar3 != '\0')) ||
            (pRVar2->allied_victory == '\0')) ||
           (uVar3 = RGE_Player::relation(pRVar2,(int)pRVar1->id), uVar3 != '\0')) {
          iVar4 = param_1->_padding_;
          uVar6 = 0xbda;
        }
        else {
          iVar4 = param_1->_padding_;
          uVar6 = 0xbd9;
        }
        goto LAB_0052599f;
      }
      (**(code **)(param_1->_padding_ + 0x20))(0xbd9);
    }
    else {
      iVar4 = param_1->_padding_;
      uVar6 = 0xbf1;
LAB_0052599f:
      (**(code **)(iVar4 + 0x20))(uVar6);
    }
    TRIBE_Screen_Game::display_system_message(param_1->game_screen,&stack0xfffffdf4);
    TRIBE_Screen_Game::reset_clocks(param_1->game_screen);
    iVar4 = param_1->_padding_;
    iVar5 = 1;
    if (1 < *(short *)(iVar4 + 0x3c)) {
      do {
        (**(code **)(**(int **)(*(int *)(iVar4 + 0x40) + iVar5 * 4) + 0xe8))
                  ((int)pRVar1->id,iVar5,0x74,0,0,0);
        iVar4 = param_1->_padding_;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(iVar4 + 0x3c));
      return;
    }
    break;
  case 0x75:
    if (param_1->game_screen == (TRIBE_Screen_Game *)0x0) {
      return;
    }
    if (*(int *)(param_1->_padding_ + 0x108) != 0) {
      return;
    }
    RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,0xc);
    iVar4 = param_1->_padding_;
    uVar6 = 0xbdb;
LAB_00525a47:
    (**(code **)(iVar4 + 0x20))(uVar6);
    goto LAB_00525a51;
  case 0x76:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0xbe7;
LAB_00525bbc:
      (**(code **)(iVar4 + 0x20))(uVar6);
      TRIBE_Screen_Game::show_message(param_1->game_screen,BadMessage,&stack0xfffffdf4,'U','\0');
      return;
    }
    break;
  case 0x77:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0xbe8;
      goto LAB_00525bbc;
    }
    break;
  case 0x78:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0xbe9;
      goto LAB_00525bbc;
    }
    break;
  case 0x79:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0xbea;
      goto LAB_00525bbc;
    }
    break;
  case 0x7a:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,3);
      iVar4 = param_1->_padding_;
      uVar6 = 0xbeb;
      goto LAB_00525bbc;
    }
    break;
  case 0x7b:
    if (((param_1->game_screen != (TRIBE_Screen_Game *)0x0) &&
        (iVar4 = (int)*(short *)(param_1->_padding_ + 0x7c), param_3 != iVar4)) &&
       (param_4 == iVar4)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,0xd);
    }
    break;
  case 0x7c:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      TRIBE_Screen_Game::setup_buttons(param_1->game_screen);
      return;
    }
    break;
  case 0x7d:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      iVar4 = param_1->_padding_;
      uVar6 = 1;
      goto LAB_00524f71;
    }
    break;
  case 0x7e:
    if ((param_3 == *(short *)(param_1->_padding_ + 0x7c)) &&
       (param_1->game_screen != (TRIBE_Screen_Game *)0x0)) {
      RGE_Base_Game::play_sound((RGE_Base_Game *)param_1,0x10);
      TRIBE_Game::add_notification_loc(param_1,param_5,param_6);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00525e4b
// Address: 00525e4b
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
undefined4 __thiscall FUN_00525e4b(TRIBE_Game *param_1,char *param_2)
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar4 = 0xffffffff;
  do {
    pcVar6 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_2 + 1;
    cVar2 = *param_2;
    param_2 = pcVar6;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  pcVar1 = param_1->testing_scenario;
  pcVar6 = pcVar6 + -uVar4;
  pcVar7 = pcVar1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  (**(code **)(param_1->_padding_ + 0xc))(0);
  iVar3 = TRIBE_Game::start_scenario(param_1,pcVar1);
  if (iVar3 != 0) {
    return 1;
  }
  iVar3 = TRIBE_Game::start_scenario_editor(param_1,pcVar1,0);
  if (iVar3 == 0) {
    iVar3 = TRIBE_Game::start_menu(param_1);
    if (iVar3 == 0) {
      RGE_Base_Game::close((RGE_Base_Game *)param_1);
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00525ed6
// Address: 00525ed6
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
int __thiscall FUN_00525ed6(TRIBE_Game *param_1,char *param_2)
{
  int iVar1;
  RGE_Scenario *this;
  int iVar2;
  int unaff_EBX;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iStack_220;
  char acStack_21c [260];
  undefined1 auStack_118 [280];
  
  RGE_Base_Game::disable_input((RGE_Base_Game *)param_1);
  RGE_Base_Game::setSinglePlayerGame((RGE_Base_Game *)param_1,1);
  RGE_Base_Game::setCampaignGame((RGE_Base_Game *)param_1,0);
  RGE_Base_Game::setSavedGame((RGE_Base_Game *)param_1,0);
  RGE_Base_Game::setScenarioGame((RGE_Base_Game *)param_1,1);
  RGE_Base_Game::setScenarioName((RGE_Base_Game *)param_1,param_2);
  TRIBE_Game::setVictoryType(param_1,VictoryDefault,0);
  RGE_Base_Game::setFullVisibility((RGE_Base_Game *)param_1,0);
  RGE_Base_Game::setFogOfWar((RGE_Base_Game *)param_1,1);
  RGE_Base_Game::setAllowCheatCodes((RGE_Base_Game *)param_1,1);
  TRIBE_Game::setRandomizePositions(param_1,0);
  TRIBE_Game::setLongCombat(param_1,0);
  TRIBE_Game::setAllowTrading(param_1,1);
  TRIBE_Game::setFullTechTree(param_1,0);
  TRIBE_Game::setResourceLevel(param_1,DefaultResources);
  TRIBE_Game::setStartingAge(param_1,DefaultAge);
  TRIBE_Game::setStartingUnits(param_1,0);
  TRIBE_Game::setDeathMatch(param_1,'\0');
  TRIBE_Game::setPopLimit(param_1,'2');
  iVar1 = RGE_Base_Game::get_single_player_difficulty((RGE_Base_Game *)param_1);
  RGE_Base_Game::setDifficulty((RGE_Base_Game *)param_1,iVar1);
  TRIBE_Game::setQuickStartGame(param_1,'\0');
  uVar3 = 0;
  iStack_220 = -1;
  sprintf(acStack_21c,s__s_s_scn,param_1->_padding_ + 0xc17,param_2);
  iVar1 = __findfirst(acStack_21c,auStack_118);
  if (iVar1 == -1) {
    pcVar5 = s__s_scx;
  }
  else {
    pcVar5 = s__s_scn;
  }
  sprintf(acStack_21c,pcVar5,param_2);
  this = RGE_Base_Game::get_scenario_info((RGE_Base_Game *)param_1,acStack_21c,0);
  if (this == (RGE_Scenario *)0x0) {
    RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
    return 0;
  }
  iVar1 = 0;
  do {
    iVar2 = RGE_Scenario::Get_player_Active(this,iVar1);
    if (iVar2 != 0) {
      TRIBE_Game::setScenarioPlayer(param_1,uVar3,iVar1);
      iVar2 = RGE_Scenario::Get_player_Civ(this,iVar1);
      TRIBE_Game::setCivilization(param_1,iVar1,iVar2);
      TRIBE_Game::setPlayerColor(param_1,iVar1,iVar1 + 1);
      RGE_Base_Game::setPlayerTeam((RGE_Base_Game *)param_1,iVar1,1);
      TRIBE_Game::setComputerName(param_1,iVar1,0);
      uVar3 = uVar3 + 1;
      if ((iStack_220 == -1) && (iVar2 = RGE_Scenario::Get_player_Type(this,iVar1), iVar2 == 1)) {
        iStack_220 = iVar1;
      }
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  (**(code **)(this->_padding_ + 4))(1);
  if (uVar3 == 0) {
    RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
    return 0;
  }
  RGE_Base_Game::setNumberPlayers((RGE_Base_Game *)param_1,uVar3);
  if (unaff_EBX != -1) {
    iVar1 = 1;
    if (1 < (int)uVar3) {
      do {
        iVar2 = TRIBE_Game::scenarioPlayer(param_1,iVar1);
        if (iVar2 == unaff_EBX) {
          iVar2 = TRIBE_Game::scenarioPlayer(param_1,0);
          TRIBE_Game::setScenarioPlayer(param_1,iVar1,iVar2);
          break;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)uVar3);
    }
    TRIBE_Game::setScenarioPlayer(param_1,0,unaff_EBX);
  }
  TCommunications_Handler::SetPlayerHumanity
            ((TCommunications_Handler *)param_1->_padding_,1,ME_HUMAN);
  uVar4 = 2;
  if (1 < (int)uVar3) {
    do {
      TCommunications_Handler::SetPlayerHumanity
                ((TCommunications_Handler *)param_1->_padding_,uVar4,ME_COMPUTER);
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 <= (int)uVar3);
  }
  while (uVar3 = uVar3 + 1, (int)uVar3 < 10) {
    TCommunications_Handler::SetPlayerHumanity
              ((TCommunications_Handler *)param_1->_padding_,uVar3,ME_ABSENT);
  }
  iVar1 = TRIBE_Game::start_game(param_1,1);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0052616d
// Address: 0052616d
// [HELPER] s_DEBUGLOAD: "DEBUGLOAD"
// [HELPER] s_DEBUGSAVEGAME: "DEBUGSAVEGAME"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s___Writing__f_: "  Writing=%f\n"
// [HELPER] s_____Doppled_master_obj____s___d_: "    Doppled master obj:  %s, %d.\n"
// [HELPER] s_____NULL_doppled_master_obj__: "    NULL doppled master obj.\n"
// [HELPER] s_________w_i__6_2f__6_2f__d_: "        w%i=%6.2f,%6.2f,%d\n"
// [HELPER] s_____path__s__6_2f__6_2f__6_2f_g_: "    path: s=%6.2f,%6.2f,%6.2f,g=%6.2f,%6.2f,%6.2f,cc=%d,wd=%d\n"
// [HELPER] s___num_dopple_obj__d_: "  num_dopple_obj=%d\n"
// [HELPER] s___num_sleep_obj__d_: "  num_sleep_obj=%d\n"
// [HELPER] s___p__d_attr__d___12_8f_: "  p#%d attr[%d]=%12.8f\n"
// [HELPER] s___p__d_checksum__d__1__d__2__d__: "  p#%d checksum=%d, 1=%d, 2=%d, 3=%d, 4=%d, act=%d\n"
// [HELPER] s___p__d_ob__d___s___st__d__at__8_: "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n"
// [HELPER] s_c___s_txt: "c:\%s.txt"
// [HELPER] s_game_speed__6_2f_: "game_speed=%6.2f\n"
// [HELPER] s_old_world_time__u_: "old_world_time=%u\n"
// [HELPER] s_player__d__civ__d__score__d___s_: "player %d, civ=%d, score=%d, %s\n"
// [HELPER] s_total_checksum__d__act__d_: "total checksum=%d, act=%d\n"
// [HELPER] s_w: "w"
// [HELPER] s_world_time__u_: "world_time=%u\n"
int __thiscall FUN_0052616d(TRIBE_Game *param_1,char *param_2)
{
  Path *pPVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  RGE_Action *pRVar6;
  uchar uVar7;
  char cVar8;
  TPanel *this;
  int iVar9;
  char *pcVar10;
  undefined1 *puVar11;
  int iVar12;
  long lVar13;
  int iVar14;
  int iVar15;
  Waypoint *pWVar16;
  uint uVar17;
  int iVar18;
  undefined4 uVar19;
  uint uVar20;
  int iVar21;
  char *pcVar22;
  double dVar23;
  PLAYERHUMANITY PVar24;
  int iStack_2e0;
  int iStack_2dc;
  int iStack_2d8;
  int iStack_2d0;
  int iStack_2cc;
  int iStack_2c8;
  int iStack_2c0;
  char acStack_2ac [52];
  char acStack_278 [52];
  char acStack_244 [52];
  char acStack_210 [260];
  undefined1 auStack_10c [264];
  
  param_1->inHandleIdle = 0;
  this = TPanelSystem::currentPanel(&panel_system);
  RGE_Base_Game::disable_input((RGE_Base_Game *)param_1);
  iVar9 = param_1->_padding_;
  if (((iVar9 == 4) || (iVar9 == 6)) || (iVar9 == 5)) {
    param_1->_padding_ = 0;
    (**(code **)(*(int *)param_1->_padding_ + 0xb8))();
    param_1->game_screen = (TRIBE_Screen_Game *)0x0;
    TPanelSystem::destroyPanel(&panel_system,s_Game_Screen);
  }
  TRIBE_Game::show_status_message(param_1,0x44d,(char *)0x0,-1);
  iVar9 = TRIBE_Game::load_game_data(param_1);
  if (iVar9 == 0) {
    if ((this == (TPanel *)0x0) || (pcVar10 = TPanel::panelName(this), pcVar10 == (char *)0x0))
    goto LAB_00526303;
    pcVar10 = TPanel::panelName(this);
    cVar8 = *pcVar10;
  }
  else {
    TRIBE_Game::show_status_message(param_1,0x452,(char *)0x0,-1);
    if (param_1->_padding_ != 0) {
      *(undefined1 *)(param_1->_padding_ + 1) = 1;
    }
    uVar7 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)param_1,s_DEBUGSAVEGAME);
    if (uVar7 != '\0') {
      ENABLE_COMPRESSION = 0;
    }
    cVar8 = (**(code **)(*(int *)param_1->_padding_ + 0xcc))(param_2);
    iVar9 = 0;
    if (0 < *(short *)(param_1->_padding_ + 0x3c)) {
      do {
        RGE_Base_Game::reset_countdown_timer((RGE_Base_Game *)param_1,iVar9);
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(short *)(param_1->_padding_ + 0x3c));
    }
    ENABLE_COMPRESSION = 1;
    if (param_1->_padding_ != 0) {
      *(undefined1 *)(param_1->_padding_ + 1) = 0;
    }
    if (cVar8 != '\0') {
      RGE_Base_Game::setFullVisibility
                ((RGE_Base_Game *)param_1,
                 (uint)*(byte *)(*(int *)(param_1->_padding_ + 0x28) + 0x8db8));
      RGE_Base_Game::setFogOfWar
                ((RGE_Base_Game *)param_1,
                 (uint)*(byte *)(*(int *)(param_1->_padding_ + 0x28) + 0x8db9));
      RGE_Base_Game::setAllowCheatCodes((RGE_Base_Game *)param_1,1);
      RGE_Base_Game::setSavedGame((RGE_Base_Game *)param_1,1);
      RGE_Base_Game::setNumberPlayers
                ((RGE_Base_Game *)param_1,*(short *)(param_1->_padding_ + 0x3c) + -1);
      uVar7 = RGE_Base_Game::pathFinding((RGE_Base_Game *)param_1);
      if (uVar7 == '\x01') {
        numberPathingIterations = 5000;
      }
      else if (uVar7 == '\x02') {
        numberPathingIterations = 0x1d4c;
      }
      else {
        numberPathingIterations = 0x9c4;
      }
      uVar20 = 0;
      do {
        if ((int)uVar20 < (int)*(short *)(param_1->_padding_ + 0x3c)) {
          RGE_Base_Game::setPlayerID((RGE_Base_Game *)param_1,uVar20,uVar20);
          if (0 < (int)uVar20) {
            TCommunications_Handler::SetPlayerName
                      ((TCommunications_Handler *)param_1->_padding_,uVar20,
                       *(char **)(*(int *)(*(int *)(param_1->_padding_ + 0x40) + uVar20 * 4) + 0x44)
                      );
            if (uVar20 == 1) {
              PVar24 = ME_HUMAN;
            }
            else {
              PVar24 = ME_COMPUTER;
            }
            goto LAB_005263fb;
          }
        }
        else {
          RGE_Base_Game::setPlayerID((RGE_Base_Game *)param_1,uVar20,0);
          PVar24 = ME_ABSENT;
LAB_005263fb:
          TCommunications_Handler::SetPlayerHumanity
                    ((TCommunications_Handler *)param_1->_padding_,uVar20,PVar24);
        }
        uVar20 = uVar20 + 1;
      } while ((int)uVar20 < 9);
      uVar20 = 0xffffffff;
      do {
        pcVar10 = param_2;
        if (uVar20 == 0) break;
        uVar20 = uVar20 - 1;
        pcVar10 = param_2 + 1;
        cVar8 = *param_2;
        param_2 = pcVar10;
      } while (cVar8 != '\0');
      uVar20 = ~uVar20;
      pcVar10 = pcVar10 + -uVar20;
      pcVar22 = acStack_210;
      for (uVar17 = uVar20 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
        *(undefined4 *)pcVar22 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar22 = pcVar22 + 4;
      }
      for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
        *pcVar22 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar22 = pcVar22 + 1;
      }
      puVar11 = (undefined1 *)__mbschr(acStack_210,0x2e);
      if (puVar11 != (undefined1 *)0x0) {
        *puVar11 = 0;
      }
      TRIBE_Game::set_save_game_name(param_1,acStack_210);
      TRIBE_Game::set_load_game_name(param_1,acStack_210);
      uVar7 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)param_1,s_DEBUGLOAD);
      if (uVar7 != '\0') {
        sprintf(auStack_10c,s_c___s_txt,acStack_210);
        iVar9 = fopen(auStack_10c,s_w);
        if (iVar9 != 0) {
          iStack_2c8 = 0;
          iStack_2cc = 0;
          fprintf(iVar9,s_world_time__u_,*(undefined4 *)(param_1->_padding_ + 4));
          fprintf(iVar9,s_old_world_time__u_,*(undefined4 *)(param_1->_padding_ + 8));
          fprintf(iVar9,s_game_speed__6_2f_,(double)*(float *)(param_1->_padding_ + 0x18));
          iVar12 = param_1->_padding_;
          iStack_2d0 = 0;
          if (0 < *(short *)(iVar12 + 0x3c)) {
            do {
              iVar12 = *(int *)(*(int *)(iVar12 + 0x40) + iStack_2d0 * 4);
              uVar19 = *(undefined4 *)(iVar12 + 0x44);
              lVar13 = RGE_Victory_Conditions::get_victory_points
                                 (*(RGE_Victory_Conditions **)(iVar12 + 0x34));
              fprintf(iVar9,s_player__d__civ__d__score__d___s_,iStack_2d0,
                      *(undefined1 *)(iVar12 + 0x105),lVar13,uVar19);
              fprintf(iVar9,s___Writing__f_,(double)*(float *)(*(int *)(iVar12 + 0x50) + 200));
              iVar21 = 0;
              iVar14 = (int)*(short *)(*(int *)(iVar12 + 0x2c) + 8);
              iVar18 = *(short *)(*(int *)(iVar12 + 0x30) + 8) + iVar14 +
                       (int)*(short *)(iVar12 + 0x4a);
              iStack_2c0 = 0;
              iStack_2dc = 0;
              iStack_2d8 = 0;
              iStack_2e0 = 0;
              fprintf(iVar9,s___num_sleep_obj__d_,iVar14);
              fprintf(iVar9,s___num_dopple_obj__d_,(int)*(short *)(*(int *)(iVar12 + 0x30) + 8));
              if (0 < *(short *)(iVar12 + 0x4c)) {
                do {
                  iVar14 = *(int *)(iVar12 + 0x50);
                  iVar15 = __ftol();
                  iStack_2c0 = iStack_2c0 + iVar15;
                  fprintf(iVar9,s___p__d_attr__d___12_8f_,(int)*(short *)(iVar12 + 0x4a),iVar21,
                          (double)*(float *)(iVar14 + iVar21 * 4));
                  iVar21 = iVar21 + 1;
                } while (iVar21 < *(short *)(iVar12 + 0x4c));
              }
              for (piVar3 = *(int **)(*(int *)(iVar12 + 0x28) + 4); piVar3 != (int *)0x0;
                  piVar3 = (int *)piVar3[1]) {
                piVar4 = (int *)*piVar3;
                bVar2 = *(byte *)(piVar4 + 0x12);
                iVar14 = __ftol();
                iStack_2dc = *(short *)(piVar4[2] + 0x10) + iStack_2dc + (uint)bVar2 + iVar14;
                iStack_2d8 = iStack_2d8 + 1;
                iVar14 = (**(code **)(*piVar4 + 0x1d0))();
                iStack_2e0 = iStack_2e0 + iVar14;
                iVar14 = (**(code **)(*(int *)*piVar3 + 0xcc))();
                if (iVar14 == 0) {
                  acStack_244[0] = '\0';
                  uVar19 = 0xffffffff;
                }
                else {
                  uVar20 = 0xffffffff;
                  pcVar10 = *(char **)(*(int *)(iVar14 + 8) + 8);
                  do {
                    pcVar22 = pcVar10;
                    if (uVar20 == 0) break;
                    uVar20 = uVar20 - 1;
                    pcVar22 = pcVar10 + 1;
                    cVar8 = *pcVar10;
                    pcVar10 = pcVar22;
                  } while (cVar8 != '\0');
                  uVar20 = ~uVar20;
                  pcVar10 = pcVar22 + -uVar20;
                  pcVar22 = acStack_244;
                  for (uVar17 = uVar20 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar10;
                    pcVar10 = pcVar10 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
                    *pcVar22 = *pcVar10;
                    pcVar10 = pcVar10 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  uVar19 = *(undefined4 *)(iVar14 + 4);
                }
                iVar14 = *piVar3;
                fprintf(iVar9,s___p__d_ob__d___s___st__d__at__8_,(int)*(short *)(iVar12 + 0x4a),
                        *(undefined4 *)(iVar14 + 4),*(undefined4 *)(*(int *)(iVar14 + 8) + 8),
                        *(undefined1 *)(iVar14 + 0x48),(double)*(float *)(iVar14 + 0x44),
                        (double)*(float *)(iVar14 + 0x38),(double)*(float *)(iVar14 + 0x3c),
                        (double)*(float *)(iVar14 + 0x40),uVar19,acStack_244);
                bVar2 = *(byte *)(*(int *)(*piVar3 + 8) + 4);
                if ((0x1d < bVar2) && (bVar2 != 0x5a)) {
                  pPVar1 = (Path *)(*piVar3 + 0xa4);
                  iVar14 = Path::numberOfWaypoints(pPVar1);
                  if (0 < iVar14) {
                    Path::initToStart(pPVar1);
                    fprintf(iVar9,s_____path__s__6_2f__6_2f__6_2f_g_);
                    iVar21 = 0;
                    iVar14 = Path::numberOfWaypoints(pPVar1);
                    if (0 < iVar14) {
                      do {
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        uVar20 = (uint)pWVar16->facetToNextWaypoint;
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        dVar23 = (double)pWVar16->y;
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        fprintf(iVar9,s_________w_i__6_2f__6_2f__d_,iVar21,(double)pWVar16->x,dVar23
                                ,uVar20);
                        iVar21 = iVar21 + 1;
                        Path::moveToNextWaypoint(pPVar1);
                        iVar14 = Path::numberOfWaypoints(pPVar1);
                      } while (iVar21 < iVar14);
                    }
                    Path::initToStart(pPVar1);
                    Path::moveToNextWaypoint(pPVar1);
                  }
                }
                bVar2 = *(byte *)(*(int *)(*piVar3 + 8) + 4);
                if ((0x27 < bVar2) && (bVar2 != 0x5a)) {
                  for (puVar5 = *(undefined4 **)(*(int *)(*piVar3 + 0x184) + 8);
                      puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)puVar5[1]) {
                    pRVar6 = (RGE_Action *)*puVar5;
                    if (pRVar6 != (RGE_Action *)0x0) {
                      RGE_Action::subAction(pRVar6);
                      RGE_Action::targetZ(pRVar6);
                      RGE_Action::targetY(pRVar6);
                      RGE_Action::targetX(pRVar6);
                      fprintf(iVar9);
                    }
                  }
                }
              }
              for (piVar3 = *(int **)(*(int *)(iVar12 + 0x30) + 4); piVar3 != (int *)0x0;
                  piVar3 = (int *)piVar3[1]) {
                piVar4 = (int *)*piVar3;
                bVar2 = *(byte *)(piVar4 + 0x12);
                iVar14 = __ftol();
                iStack_2dc = *(short *)(piVar4[2] + 0x10) + iStack_2dc + (uint)bVar2 + iVar14;
                iStack_2d8 = iStack_2d8 + 1;
                iVar14 = (**(code **)(*piVar4 + 0x1d0))();
                iStack_2e0 = iStack_2e0 + iVar14;
                iVar14 = (**(code **)(*(int *)*piVar3 + 0xcc))();
                if (iVar14 == 0) {
                  acStack_2ac[0] = '\0';
                  uVar19 = 0xffffffff;
                }
                else {
                  uVar20 = 0xffffffff;
                  pcVar10 = *(char **)(*(int *)(iVar14 + 8) + 8);
                  do {
                    pcVar22 = pcVar10;
                    if (uVar20 == 0) break;
                    uVar20 = uVar20 - 1;
                    pcVar22 = pcVar10 + 1;
                    cVar8 = *pcVar10;
                    pcVar10 = pcVar22;
                  } while (cVar8 != '\0');
                  uVar20 = ~uVar20;
                  pcVar10 = pcVar22 + -uVar20;
                  pcVar22 = acStack_2ac;
                  for (uVar17 = uVar20 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar10;
                    pcVar10 = pcVar10 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
                    *pcVar22 = *pcVar10;
                    pcVar10 = pcVar10 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  uVar19 = *(undefined4 *)(iVar14 + 4);
                }
                iVar14 = *piVar3;
                fprintf(iVar9,s___p__d_ob__d___s___st__d__at__8_,(int)*(short *)(iVar12 + 0x4a),
                        *(undefined4 *)(iVar14 + 4),*(undefined4 *)(*(int *)(iVar14 + 8) + 8),
                        *(undefined1 *)(iVar14 + 0x48),(double)*(float *)(iVar14 + 0x44),
                        (double)*(float *)(iVar14 + 0x38),(double)*(float *)(iVar14 + 0x3c),
                        (double)*(float *)(iVar14 + 0x40),uVar19,acStack_2ac);
                if (*piVar3 != 0) {
                  iVar14 = *(int *)(*piVar3 + 0x94);
                  if (iVar14 == 0) {
                    fprintf(iVar9,s_____NULL_doppled_master_obj__);
                  }
                  else {
                    fprintf(iVar9,s_____Doppled_master_obj____s___d_,*(undefined4 *)(iVar14 + 8),
                            (int)*(short *)(iVar14 + 0x10));
                  }
                }
                bVar2 = *(byte *)(*(int *)(*piVar3 + 8) + 4);
                if ((0x1d < bVar2) && (bVar2 != 0x5a)) {
                  pPVar1 = (Path *)(*piVar3 + 0xa4);
                  iVar14 = Path::numberOfWaypoints(pPVar1);
                  if (0 < iVar14) {
                    Path::initToStart(pPVar1);
                    fprintf(iVar9,s_____path__s__6_2f__6_2f__6_2f_g_);
                    iVar21 = 0;
                    iVar14 = Path::numberOfWaypoints(pPVar1);
                    if (0 < iVar14) {
                      do {
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        uVar20 = (uint)pWVar16->facetToNextWaypoint;
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        dVar23 = (double)pWVar16->y;
                        pWVar16 = Path::currentWaypoint(pPVar1);
                        fprintf(iVar9,s_________w_i__6_2f__6_2f__d_,iVar21,(double)pWVar16->x,dVar23
                                ,uVar20);
                        iVar21 = iVar21 + 1;
                        Path::moveToNextWaypoint(pPVar1);
                        iVar14 = Path::numberOfWaypoints(pPVar1);
                      } while (iVar21 < iVar14);
                    }
                    Path::initToStart(pPVar1);
                    Path::moveToNextWaypoint(pPVar1);
                  }
                }
                bVar2 = *(byte *)(*(int *)(*piVar3 + 8) + 4);
                if ((0x27 < bVar2) && (bVar2 != 0x5a)) {
                  for (puVar5 = *(undefined4 **)(*(int *)(*piVar3 + 0x184) + 8);
                      puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)puVar5[1]) {
                    pRVar6 = (RGE_Action *)*puVar5;
                    if (pRVar6 != (RGE_Action *)0x0) {
                      RGE_Action::subAction(pRVar6);
                      RGE_Action::targetZ(pRVar6);
                      RGE_Action::targetY(pRVar6);
                      RGE_Action::targetX(pRVar6);
                      fprintf(iVar9);
                    }
                  }
                }
              }
              for (piVar3 = *(int **)(*(int *)(iVar12 + 0x2c) + 4); piVar3 != (int *)0x0;
                  piVar3 = (int *)piVar3[1]) {
                iVar14 = (**(code **)(*(int *)*piVar3 + 0xcc))();
                if (iVar14 == 0) {
                  acStack_278[0] = '\0';
                  uVar19 = 0xffffffff;
                }
                else {
                  uVar20 = 0xffffffff;
                  pcVar10 = *(char **)(*(int *)(iVar14 + 8) + 8);
                  do {
                    pcVar22 = pcVar10;
                    if (uVar20 == 0) break;
                    uVar20 = uVar20 - 1;
                    pcVar22 = pcVar10 + 1;
                    cVar8 = *pcVar10;
                    pcVar10 = pcVar22;
                  } while (cVar8 != '\0');
                  uVar20 = ~uVar20;
                  pcVar10 = pcVar22 + -uVar20;
                  pcVar22 = acStack_278;
                  for (uVar17 = uVar20 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar10;
                    pcVar10 = pcVar10 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
                    *pcVar22 = *pcVar10;
                    pcVar10 = pcVar10 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  uVar19 = *(undefined4 *)(iVar14 + 4);
                }
                iVar14 = *piVar3;
                fprintf(iVar9,s___p__d_ob__d___s___st__d__at__8_,(int)*(short *)(iVar12 + 0x4a),
                        *(undefined4 *)(iVar14 + 4),*(undefined4 *)(*(int *)(iVar14 + 8) + 8),
                        *(undefined1 *)(iVar14 + 0x48),(double)*(float *)(iVar14 + 0x44),
                        (double)*(float *)(iVar14 + 0x38),(double)*(float *)(iVar14 + 0x3c),
                        (double)*(float *)(iVar14 + 0x40),uVar19,acStack_278);
              }
              iVar14 = ((iVar18 * 0x100 + iStack_2d8) * 0x100 + iStack_2dc) * 0x100 + iStack_2c0;
              iStack_2c8 = iStack_2c8 + iVar14;
              iStack_2cc = iStack_2cc + iStack_2e0;
              fprintf(iVar9,s___p__d_checksum__d__1__d__2__d__,(int)*(short *)(iVar12 + 0x4a),iVar14
                      ,iStack_2c0,iStack_2dc,iStack_2d8,iVar18,iStack_2e0);
              iStack_2d0 = iStack_2d0 + 1;
              iVar12 = param_1->_padding_;
            } while (iStack_2d0 < *(short *)(iVar12 + 0x3c));
          }
          fprintf(iVar9,s_total_checksum__d__act__d_,iStack_2c8,iStack_2cc);
          fclose(iVar9);
        }
      }
      TRIBE_Game::close_game_screens(param_1,0);
      iVar9 = TRIBE_Game::create_game_screen(param_1);
      return iVar9;
    }
    if ((this == (TPanel *)0x0) || (pcVar10 = TPanel::panelName(this), pcVar10 == (char *)0x0))
    goto LAB_00526303;
    pcVar10 = TPanel::panelName(this);
    cVar8 = *pcVar10;
  }
  if (cVar8 != '\0') {
    iVar9 = 0;
    pcVar10 = TPanel::panelName(this);
    TPanelSystem::setCurrentPanel(&panel_system,pcVar10,iVar9);
    TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
    RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
    return 0;
  }
LAB_00526303:
  TRIBE_Game::close_status_message(param_1);
  RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00526e55
// Address: 00526e55
// [HELPER] s_C__msdev_work_age1_x1_tribegam_c: "C:\msdev\work\age1_x1\tribegam.cpp"
// [HELPER] s_QUICKBUILD: "QUICKBUILD"
// [HELPER] s__s_s_scn: "%s%s.scn"
// [HELPER] s__s_scn: "%s.scn"
// [HELPER] s__s_scx: "%s.scx"
char __fastcall FUN_00526e55(TRIBE_Game *param_1)
{
  bool bVar1;
  uchar uVar2;
  char cVar3;
  long *plVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  undefined1 *puVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  char *pcVar19;
  MapType MVar20;
  undefined4 uVar21;
  int *piStack_a2c;
  RGE_Scenario *pRStack_a28;
  uint uStack_a24;
  int *piStack_a20;
  undefined2 *puStack_a1c;
  int *piStack_a0c;
  int aiStack_a08 [8];
  char acStack_9e8 [585];
  char acStack_79f [9];
  undefined1 auStack_796 [10];
  undefined2 auStack_78c [10];
  int iStack_778;
  int aiStack_774 [8];
  short sStack_754;
  char *pcStack_750;
  undefined4 *puStack_74c;
  undefined2 uStack_748;
  undefined2 uStack_746;
  undefined2 uStack_744;
  undefined1 uStack_740;
  char acStack_73c [260];
  undefined1 auStack_638 [280];
  undefined4 auStack_520 [328];
  
  iVar16 = 0;
  iVar12 = 5;
  param_1->inHandleIdle = 0;
  plVar4 = param_1->notification_loc_y;
  do {
    plVar4[-5] = -1;
    *plVar4 = -1;
    plVar4 = plVar4 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  param_1->current_notification_loc = -1;
  param_1->current_notification_recalled = -1;
  uVar2 = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)param_1,s_QUICKBUILD);
  if (uVar2 == '\0') {
    param_1->_padding_ = 0;
  }
  else {
    param_1->_padding_ = 1;
  }
  param_1->_padding_ = 0;
  param_1->_padding_ = 0;
  param_1->_padding_ = 0;
  RGE_Base_Game::set_map_visible((RGE_Base_Game *)param_1,'\0');
  RGE_Base_Game::set_map_fog((RGE_Base_Game *)param_1,'\0');
  puVar13 = (undefined1 *)((int)&param_1->_padding_ + 2);
  puVar5 = &DAT_0086bcac;
  plVar4 = param_1->queue_is_waiting_on_pop_counter;
  do {
    plVar4 = plVar4 + 1;
    *puVar13 = 0;
    *puVar5 = 0;
    *plVar4 = 0;
    puVar5 = puVar5 + 1;
    puVar13 = puVar13 + 1;
  } while ((int)puVar5 < 0x86bccc);
  out_of_sync = 0;
  out_of_sync2 = 0;
  no_other_humans_count = 0;
  uVar2 = TRIBE_Game::quickStartGame(param_1);
  if (uVar2 != '\0') {
    if (quick_start_game_mode == 1) {
      TRIBE_Game::setMapSize(param_1,Medium);
      MVar20 = AllLand;
    }
    else {
      TRIBE_Game::setMapSize(param_1,Large);
      iVar12 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0xcdd);
      MVar20 = iVar12 % 10;
      if ((int)MVar20 < 2) {
        MVar20 = AllLand;
      }
      else if (MVar20 == WaterAndLand) {
        MVar20 = MostlyLand;
      }
      else if (MVar20 == MostlyLand) {
        MVar20 = WaterAndLand;
      }
      else if (MVar20 == AllLand) {
        MVar20 = MostlyWater;
      }
      else if (((MVar20 != Continental) && (MVar20 != Lake)) && (MVar20 != Hilly)) {
        MVar20 = (MVar20 != Isthmas) - MostlyWater & Isthmas;
      }
    }
    TRIBE_Game::setMapType(param_1,MVar20);
    TRIBE_Game::resetRandomComputerName(param_1);
    iVar12 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)param_1);
    if (0 < iVar12) {
      do {
        uVar6 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0xcf8);
        uVar14 = (int)uVar6 >> 0x1f;
        iVar12 = (((uVar6 ^ uVar14) - uVar14 & 0xf ^ uVar14) - uVar14) + 1;
        TRIBE_Game::setCivilization(param_1,iVar16,iVar12);
        iVar12 = TRIBE_Game::randomComputerName(param_1,iVar12);
        TRIBE_Game::setComputerName(param_1,iVar16,iVar12);
        iVar16 = iVar16 + 1;
        iVar12 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)param_1);
      } while (iVar16 < iVar12);
    }
  }
  pcVar15 = acStack_9e8;
  for (iVar12 = 0xab; iVar12 != 0; iVar12 = iVar12 + -1) {
    pcVar15[0] = '\0';
    pcVar15[1] = '\0';
    pcVar15[2] = '\0';
    pcVar15[3] = '\0';
    pcVar15 = pcVar15 + 4;
  }
  puVar5 = auStack_520;
  for (iVar12 = 0x148; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar12 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
  if (iVar12 == 0) {
    iVar12 = RGE_Base_Game::scenarioGame((RGE_Base_Game *)param_1);
    if (iVar12 == 0) {
      puStack_74c = auStack_520;
      MVar20 = TRIBE_Game::mapType(param_1);
      uStack_748 = (undefined2)MVar20;
      iVar12 = RGE_Base_Game::mapXSize((RGE_Base_Game *)param_1);
      uStack_746 = (undefined2)iVar12;
      iVar12 = RGE_Base_Game::mapYSize((RGE_Base_Game *)param_1);
      uStack_744 = (undefined2)iVar12;
    }
    else {
      pcVar15 = RGE_Base_Game::scenarioName((RGE_Base_Game *)param_1);
      if (pcVar15 == (char *)0x0) {
        return '\0';
      }
      iVar12 = param_1->_padding_;
      pcVar15 = RGE_Base_Game::scenarioName((RGE_Base_Game *)param_1);
      sprintf(acStack_73c,s__s_s_scn,iVar12 + 0xc17,pcVar15);
      iVar12 = __findfirst(acStack_73c,auStack_638);
      if (iVar12 == -1) {
        pcVar15 = RGE_Base_Game::scenarioName((RGE_Base_Game *)param_1);
        pcVar10 = s__s_scx;
      }
      else {
        pcVar15 = RGE_Base_Game::scenarioName((RGE_Base_Game *)param_1);
        pcVar10 = s__s_scn;
      }
      sprintf(acStack_73c,pcVar10,pcVar15);
      pcStack_750 = acStack_73c;
    }
  }
  else {
    uStack_740 = 1;
  }
  iVar12 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)param_1);
  if (iVar12 == 0) {
    uVar6 = param_1->_padding_;
    if (uVar6 == 0xffffffff) {
      uVar6 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0xd2a);
      iVar12 = 0xd2a;
    }
    else {
      iVar12 = 0xd28;
    }
  }
  else {
    uVar6 = TCommunications_Handler::GetRandomSeed(comm);
    iVar12 = 0xd24;
  }
  debug_srand(s_C__msdev_work_age1_x1_tribegam_c,iVar12,uVar6);
  iVar12 = 0;
  pRStack_a28 = (RGE_Scenario *)auStack_78c;
  piStack_a2c = &iStack_778;
  sStack_754 = 0;
  pcVar15 = acStack_9e8;
  piVar17 = param_1->random_civ;
  do {
    acStack_79f[iVar12] = -1;
    *pcVar15 = '\0';
    *piStack_a2c = iVar12;
    auStack_796[iVar12] = 1;
    *(undefined2 *)pRStack_a28 = 0xffff;
    *piVar17 = 0;
    iVar16 = TRIBE_Game::civilization(param_1,iVar12);
    if ((0x10 < iVar16) || (iVar16 = TRIBE_Game::civilization(param_1,iVar12), iVar16 < 0)) {
      iVar16 = debug_rand(s_C__msdev_work_age1_x1_tribegam_c,0xd3b);
      TRIBE_Game::setCivilization(param_1,iVar12,(iVar16 * 0x10) / 0x7fff + 1);
      *piVar17 = 1;
    }
    iVar12 = iVar12 + 1;
    pcVar15 = pcVar15 + 0x41;
    piStack_a2c = piStack_a2c + 1;
    piVar17 = piVar17 + 1;
    pRStack_a28 = (RGE_Scenario *)((int)pRStack_a28 + 2);
  } while (iVar12 < 9);
  TRIBE_Game::resetRandomComputerName(param_1);
  iVar12 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)param_1);
  uVar6 = 0;
  if (0 < iVar12) {
    do {
      uVar14 = uVar6 + 1;
      iVar12 = TCommunications_Handler::GetPlayerHumanity(comm,uVar14);
      if (iVar12 == 4) {
        iVar12 = TRIBE_Game::civilization(param_1,uVar6);
        iVar12 = TRIBE_Game::randomComputerName(param_1,iVar12);
        TRIBE_Game::setComputerName(param_1,uVar6,iVar12);
      }
      iVar12 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)param_1);
      uVar6 = uVar14;
    } while ((int)uVar14 < iVar12);
  }
  iVar12 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
  if (iVar12 == 0) {
    iVar12 = RGE_Base_Game::scenarioGame((RGE_Base_Game *)param_1);
    if (iVar12 == 0) {
      pRStack_a28 = (RGE_Scenario *)0x0;
      goto LAB_005272dd;
    }
    iVar12 = 0;
    pcVar15 = pcStack_750;
  }
  else {
    iVar12 = 1;
    pcVar15 = (char *)0x0;
  }
  pRStack_a28 = RGE_Base_Game::get_scenario_info((RGE_Base_Game *)param_1,pcVar15,iVar12);
  if (pRStack_a28 == (RGE_Scenario *)0x0) {
    return '\0';
  }
LAB_005272dd:
  iVar16 = 0;
  piVar17 = aiStack_a08;
  for (iVar12 = 9; iVar12 != 0; iVar12 = iVar12 + -1) {
    *piVar17 = -1;
    piVar17 = piVar17 + 1;
  }
  do {
    RGE_Base_Game::setPlayerID((RGE_Base_Game *)param_1,iVar16,0);
    iVar16 = iVar16 + 1;
  } while (iVar16 < 9);
  uStack_a24 = 0;
  piStack_a2c = (int *)0x1;
  iVar12 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)param_1);
  if (0 < iVar12) {
    do {
      iVar12 = TCommunications_Handler::GetPlayerHumanity
                         ((TCommunications_Handler *)param_1->_padding_,(uint)piStack_a2c);
      if (iVar12 == 2) {
        iVar12 = TRIBE_Game::playerColor(param_1,(int)piStack_a2c - 1);
        if (aiStack_a08[iVar12 + -1] == -1) {
          aiStack_a08[iVar12 + -1] = uStack_a24;
          uStack_a24 = uStack_a24 + 1;
        }
        RGE_Base_Game::setPlayerID
                  ((RGE_Base_Game *)param_1,(int)piStack_a2c,aiStack_a08[iVar12 + -1] + 1);
      }
      else {
        iVar12 = TCommunications_Handler::GetPlayerHumanity
                           ((TCommunications_Handler *)param_1->_padding_,(uint)piStack_a2c);
        if (iVar12 == 4) {
          piStack_a20 = aiStack_a08;
          iVar12 = 0;
          do {
            if (*piStack_a20 == -1) {
              bVar1 = false;
              uVar6 = 1;
              do {
                iVar16 = TCommunications_Handler::GetPlayerHumanity
                                   ((TCommunications_Handler *)param_1->_padding_,uVar6);
                if ((iVar16 == 2) &&
                   (iVar16 = TRIBE_Game::playerColor(param_1,uVar6 - 1), iVar16 + -1 == iVar12)) {
                  bVar1 = true;
                  break;
                }
                uVar6 = uVar6 + 1;
              } while ((int)uVar6 < 9);
              if (!bVar1) {
                TRIBE_Game::setPlayerColor(param_1,(int)piStack_a2c - 1,iVar12 + 1);
                aiStack_a08[iVar12] = uStack_a24;
                uStack_a24 = uStack_a24 + 1;
                RGE_Base_Game::setPlayerID
                          ((RGE_Base_Game *)param_1,(int)piStack_a2c,aiStack_a08[iVar12] + 1);
                break;
              }
            }
            iVar12 = iVar12 + 1;
            piStack_a20 = piStack_a20 + 1;
          } while (iVar12 < 8);
        }
      }
      piStack_a2c = (int *)((int)piStack_a2c + 1);
      iVar12 = RGE_Base_Game::numberPlayers((RGE_Base_Game *)param_1);
    } while ((int)piStack_a2c <= iVar12);
  }
  TRIBE_Game::resetRandomComputerName(param_1);
  puStack_a1c = auStack_78c;
  piStack_a0c = aiStack_774;
  pcVar15 = acStack_9e8;
  iVar12 = 0;
  do {
    iVar16 = iVar12 + 1;
    uStack_a24 = 0;
    uVar6 = 1;
    do {
      iVar7 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,uVar6);
      uVar14 = uVar6;
      if (iVar7 == iVar16) break;
      uVar6 = uVar6 + 1;
      uVar14 = uStack_a24;
    } while ((int)uVar6 < 9);
    uStack_a24 = uVar14;
    if (uStack_a24 == 0) break;
    iVar8 = TCommunications_Handler::GetPlayerHumanity
                      ((TCommunications_Handler *)param_1->_padding_,uStack_a24);
    iVar7 = uStack_a24 - 1;
    iVar9 = TRIBE_Game::playerColor(param_1,iVar7);
    iVar18 = iVar9 + -1;
    if (((iVar8 == 4) || (all_cp == 1)) || ((all_cp == 2 && (0 < iVar12)))) {
      pcVar10 = acStack_79f + iVar12;
      *pcVar10 = '\x04';
    }
    else {
      pcVar10 = acStack_79f + iVar12;
      *pcVar10 = '\0';
    }
    iVar12 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
    if (iVar12 == 0) {
      iVar12 = TRIBE_Game::civilization(param_1,iVar7);
      cVar3 = (char)iVar12;
    }
    else {
      iVar12 = RGE_Scenario::Get_player_Civ(pRStack_a28,iVar18);
      cVar3 = (char)iVar12;
    }
    pcVar10[9] = cVar3;
    iVar12 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)param_1);
    if ((iVar12 == 0) || (iVar8 != 2)) {
      iVar12 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
      if ((iVar12 == 0) || (*pcVar10 != '\0')) {
        iVar12 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
        if (((iVar12 == 0) &&
            (iVar12 = RGE_Base_Game::randomGame((RGE_Base_Game *)param_1), iVar12 != 0)) &&
           (*pcVar10 == '\0')) {
          (**(code **)(param_1->_padding_ + 0x20))(0x286d,pcVar15,0x41);
        }
        else {
          iVar12 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
          if ((iVar12 != 0) ||
             (iVar12 = RGE_Base_Game::scenarioGame((RGE_Base_Game *)param_1), iVar12 != 0)) {
            pcVar11 = RGE_Scenario::GetPlayerName(pRStack_a28,iVar18);
            goto LAB_0052759b;
          }
        }
      }
      else {
        pcVar11 = RGE_Game_Info::get_current_player_name((RGE_Game_Info *)param_1->_padding_);
LAB_0052759b:
        uVar6 = 0xffffffff;
        do {
          pcVar19 = pcVar11;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar19 = pcVar11 + 1;
          cVar3 = *pcVar11;
          pcVar11 = pcVar19;
        } while (cVar3 != '\0');
        uVar6 = ~uVar6;
        pcVar11 = pcVar19 + -uVar6;
        pcVar19 = pcVar15;
        for (uVar14 = uVar6 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
          *(undefined4 *)pcVar19 = *(undefined4 *)pcVar11;
          pcVar11 = pcVar11 + 4;
          pcVar19 = pcVar19 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar19 = *pcVar11;
          pcVar11 = pcVar11 + 1;
          pcVar19 = pcVar19 + 1;
        }
      }
      if (*pcVar15 == '\0') {
        if (*pcVar10 == '\0') {
          (**(code **)(param_1->_padding_ + 0x20))(0x286d,pcVar15,0x41);
        }
        else {
          iVar12 = RGE_Base_Game::campaignGame((RGE_Base_Game *)param_1);
          if ((iVar12 == 0) && (iVar12 = TRIBE_Game::computerName(param_1,iVar7), iVar12 != 0)) {
            iVar12 = param_1->_padding_;
            uVar21 = 0x41;
            pcVar10 = pcVar15;
            iVar7 = TRIBE_Game::computerName(param_1,iVar7);
            (**(code **)(iVar12 + 0x20))(iVar7 + 0x1130,pcVar10,uVar21);
          }
          else {
            iVar12 = param_1->_padding_;
            uVar21 = 0x41;
            pcVar11 = pcVar15;
            iVar7 = TRIBE_Game::randomComputerName(param_1,(int)pcVar10[9]);
            (**(code **)(iVar12 + 0x20))(iVar7 + 0x1130,pcVar11,uVar21);
          }
        }
      }
      TCommunications_Handler::SetPlayerName
                ((TCommunications_Handler *)param_1->_padding_,uStack_a24,pcVar15);
    }
    else {
      uVar21 = 0x40;
      pcVar10 = TCommunications_Handler::GetPlayerName
                          ((TCommunications_Handler *)param_1->_padding_,uStack_a24);
      strncpy(pcVar15,pcVar10,uVar21);
    }
    pcVar15 = pcVar15 + 0x41;
    *piStack_a0c = iVar9;
    piStack_a0c = piStack_a0c + 1;
    *puStack_a1c = (short)iVar18;
    sStack_754 = sStack_754 + 1;
    puStack_a1c = puStack_a1c + 1;
    iVar12 = iVar16;
  } while (iVar16 < 8);
  if (pRStack_a28 != (RGE_Scenario *)0x0) {
    (**(code **)(pRStack_a28->_padding_ + 4))(1);
  }
  if (sStack_754 != 0) {
    if (param_1->_padding_ != 0) {
      *(undefined1 *)(param_1->_padding_ + 1) = 1;
    }
    iVar12 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)param_1);
    if (iVar12 == 0) {
      iVar12 = 1;
    }
    else {
      iVar12 = TCommunications_Handler::WhoAmI((TCommunications_Handler *)param_1->_padding_);
    }
    iVar12 = RGE_Base_Game::playerID((RGE_Base_Game *)param_1,iVar12);
    cVar3 = (**(code **)(*(int *)param_1->_padding_ + 0xd0))(acStack_9e8,iVar12);
    if ((cVar3 != '\0') && ((short)((int *)param_1->_padding_)[0xf] < 2)) {
      cVar3 = '\0';
      (**(code **)(*(int *)param_1->_padding_ + 0xb8))();
    }
    if (param_1->_padding_ != 0) {
      *(undefined1 *)(param_1->_padding_ + 1) = 0;
    }
    iVar12 = 0;
    if (0 < *(short *)(param_1->_padding_ + 0x3c)) {
      do {
        RGE_Base_Game::reset_countdown_timer((RGE_Base_Game *)param_1,iVar12);
        iVar12 = iVar12 + 1;
      } while (iVar12 < *(short *)(param_1->_padding_ + 0x3c));
    }
    RGE_Game_World::update_mutual_allies((RGE_Game_World *)param_1->_padding_);
    RGE_Base_Game::set_map_visible((RGE_Base_Game *)param_1,'\0');
    iVar12 = RGE_Base_Game::fullVisibility((RGE_Base_Game *)param_1);
    if (iVar12 != 0) {
      iVar12 = param_1->_padding_;
      iVar16 = 1;
      if (1 < *(short *)(iVar12 + 0x3c)) {
        do {
          iVar12 = RGE_Player::computerPlayer
                             (*(RGE_Player **)(*(int *)(iVar12 + 0x40) + iVar16 * 4));
          if (iVar12 == 0) {
            RGE_Visible_Map::explore_all
                      (*(RGE_Visible_Map **)
                        (*(int *)(*(int *)(param_1->_padding_ + 0x40) + iVar16 * 4) + 0x38));
          }
          iVar12 = param_1->_padding_;
          iVar16 = iVar16 + 1;
        } while (iVar16 < *(short *)(iVar12 + 0x3c));
      }
    }
    iVar12 = RGE_Base_Game::fogOfWar((RGE_Base_Game *)param_1);
    RGE_Base_Game::set_map_fog((RGE_Base_Game *)param_1,(uchar)iVar12);
    iVar12 = RGE_Base_Game::multiplayerGame((RGE_Base_Game *)param_1);
    if (iVar12 == 0) {
      uVar2 = RGE_Base_Game::pathFinding((RGE_Base_Game *)param_1);
    }
    else {
      uVar2 = RGE_Base_Game::mpPathFinding((RGE_Base_Game *)param_1);
    }
    if (uVar2 == '\x01') {
      numberPathingIterations = 5000;
    }
    else if (uVar2 == '\x02') {
      numberPathingIterations = 0x1d4c;
    }
    else {
      numberPathingIterations = 0x9c4;
    }
    uVar6 = 1;
    piVar17 = param_1->save_humanity;
    do {
      piVar17 = piVar17 + 1;
      iVar12 = TCommunications_Handler::GetPlayerHumanity
                         ((TCommunications_Handler *)param_1->_padding_,uVar6);
      *piVar17 = iVar12;
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 9);
    return cVar3;
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_0052866f
// Address: 0052866f
// [HELPER] s_Bronze: "Bronze"
// [HELPER] s_DeathMatch: "DeathMatch"
// [HELPER] s_Default: "Default"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_High: "High"
// [HELPER] s_Iron: "Iron"
// [HELPER] s_Low: "Low"
// [HELPER] s_Medium: "Medium"
// [HELPER] s_Multiplayer: "Multiplayer"
// [HELPER] s_Score__d_: "Score(%d)"
// [HELPER] s_Standard: "Standard"
// [HELPER] s_Status_Screen: "Status Screen"
// [HELPER] s_Stone: "Stone"
// [HELPER] s_Time__d_: "Time(%d)"
// [HELPER] s_Tool: "Tool"
// [HELPER] s_Unknown: "Unknown"
// [HELPER] s_____fulltech__d__revealmap__d: "    fulltech=%d, revealmap=%d"
// [HELPER] s_____numplayers__d: "    numplayers=%d"
// [HELPER] s_____randomgame__d__randommap__d_: "    randomgame=%d, randommap=%d, mapsize=%s, maptype=%s"
// [HELPER] s_____resources__s__age__s__victor: "    resources=%s, age=%s, victory=%s, difficulty=%s"
// [HELPER] s___civs_: ", civs="
// [HELPER] s___players_: ", players="
// [HELPER] s___teams_: ", teams="
// [HELPER] s__d: "%d"
// [HELPER] s__d_: "%d "
// [HELPER] s_game_started: "game started"
void __fastcall FUN_0052866f(TRIBE_Game *param_1)
{
  char cVar1;
  TMusic_System *this;
  uchar uVar2;
  MapType MVar3;
  MapSize MVar4;
  VictoryType VVar5;
  ResourceLevel RVar6;
  Age AVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  code *pcVar12;
  char *pcVar13;
  char *pcVar14;
  undefined1 **ppuVar15;
  undefined1 **ppuVar16;
  char *pcVar17;
  undefined4 uVar18;
  undefined1 *puStack_858;
  undefined4 uStack_854;
  undefined4 uStack_850;
  undefined1 auStack_82c [8];
  undefined1 auStack_824 [4];
  undefined1 auStack_820 [8];
  char acStack_818 [244];
  undefined1 auStack_724 [12];
  char acStack_718 [244];
  undefined1 auStack_624 [12];
  char acStack_618 [244];
  char acStack_524 [12];
  char acStack_518 [1012];
  undefined1 auStack_124 [12];
  char acStack_118 [280];
  
  uStack_850 = 0x52868d;
  TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Multiplayer);
  uStack_850 = 0x5286b7;
  run_log(s_game_started,1);
  MVar3 = TRIBE_Game::mapType(param_1);
  switch(MVar3) {
  case AllWater:
    pcVar12 = *(code **)(param_1->_padding_ + 0x20);
    uStack_850 = 0x296a;
    break;
  case MostlyWater:
    pcVar12 = *(code **)(param_1->_padding_ + 0x20);
    uStack_850 = 0x296b;
    break;
  case WaterAndLand:
    pcVar12 = *(code **)(param_1->_padding_ + 0x20);
    uStack_850 = 0x296c;
    break;
  case MostlyLand:
    pcVar12 = *(code **)(param_1->_padding_ + 0x20);
    uStack_850 = 0x296d;
    break;
  case AllLand:
    pcVar12 = *(code **)(param_1->_padding_ + 0x20);
    uStack_850 = 0x296e;
    break;
  case Continental:
    pcVar12 = *(code **)(param_1->_padding_ + 0x20);
    uStack_850 = 0x296f;
    break;
  case Lake:
    pcVar12 = *(code **)(param_1->_padding_ + 0x20);
    uStack_850 = 0x2970;
    break;
  default:
    pcVar12 = *(code **)(param_1->_padding_ + 0x20);
    uStack_850 = 0x2804;
  }
  uStack_854 = 0x528776;
  (*pcVar12)();
  uStack_854 = 0x52877d;
  MVar4 = TRIBE_Game::mapSize(param_1);
  switch(MVar4) {
  case Tiny:
    uVar18 = 0x2973;
    break;
  case Small:
    uVar18 = 0x2974;
    break;
  case Medium:
    uVar18 = 0x2975;
    break;
  case Large:
    uVar18 = 0x2976;
    break;
  case Huge:
    uVar18 = 0x2977;
    break;
  case Humongous:
    uVar18 = 0x2978;
    break;
  default:
    uVar18 = 0x2804;
  }
  puStack_858 = auStack_820;
  uStack_854 = 0x14;
  (*pcVar12)(uVar18);
  sprintf(acStack_518,s_____randomgame__d__randommap__d_,param_1->_padding_,param_1->_padding_,
          auStack_82c,&stack0xfffff7c0);
  run_log(acStack_518,0);
  VVar5 = TRIBE_Game::victoryType(param_1);
  switch(VVar5) {
  case VictoryDefault:
    pcVar13 = s_Default;
    break;
  default:
    pcVar13 = &s_Unknown;
    break;
  case VictoryTime:
    iVar8 = TRIBE_Game::victoryAmount(param_1);
    sprintf(acStack_618,s_Time__d_,iVar8);
    goto LAB_005288c4;
  case VictoryScore:
    iVar8 = TRIBE_Game::victoryAmount(param_1);
    sprintf(acStack_618,s_Score__d_,iVar8);
    goto LAB_005288c4;
  case VictoryStandard:
    pcVar13 = &s_Standard;
  }
  uVar10 = 0xffffffff;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = acStack_618;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
LAB_005288c4:
  uVar2 = TRIBE_Game::deathMatch(param_1);
  if (uVar2 == '\0') {
    RVar6 = TRIBE_Game::resourceLevel(param_1);
    switch(RVar6) {
    case DefaultResources:
      pcVar13 = s_Default;
      break;
    case LowResource:
      pcVar13 = s_Low;
      break;
    case MediumResources:
      pcVar13 = s_Medium;
      break;
    case HighResources:
      pcVar13 = s_High;
      break;
    default:
      pcVar13 = &s_Unknown;
    }
  }
  else {
    pcVar13 = &s_DeathMatch;
  }
  uVar10 = 0xffffffff;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = acStack_718;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  AVar7 = TRIBE_Game::startingAge(param_1);
  switch(AVar7) {
  case DefaultAge:
    pcVar13 = s_Default;
    break;
  default:
    pcVar13 = &s_Unknown;
    break;
  case StoneAge:
    pcVar13 = s_Stone;
    break;
  case ToolAge:
    pcVar13 = s_Tool;
    break;
  case BronzeAge:
    pcVar13 = s_Bronze;
    break;
  case IronAge:
    pcVar13 = &s_Iron;
  }
  uVar10 = 0xffffffff;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = acStack_818;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar10 = 0xffffffff;
  pcVar13 = &s_Unknown;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = acStack_118;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  pcVar13 = acStack_118;
  iVar8 = RGE_Base_Game::difficulty((RGE_Base_Game *)param_1);
  (*pcVar12)(iVar8 + 0x2bd0,pcVar13);
  sprintf(acStack_524,s_____resources__s__age__s__victor,auStack_724,auStack_824,auStack_624,
          auStack_124);
  run_log(acStack_524,0);
  iVar8 = RGE_Base_Game::fullVisibility((RGE_Base_Game *)param_1);
  iVar9 = TRIBE_Game::fullTechTree(param_1);
  sprintf(acStack_524,s_____fulltech__d__revealmap__d,iVar9,iVar8);
  run_log(acStack_524,0);
  sprintf(acStack_524,s_____numplayers__d,*(short *)(param_1->_padding_ + 0x3c) + -1);
  uVar10 = 0xffffffff;
  pcVar13 = &s___players_;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  iVar8 = -1;
  pcVar13 = acStack_524;
  do {
    pcVar14 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar14 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar14;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = pcVar14 + -1;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  iVar8 = param_1->_padding_;
  iVar9 = 1;
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (1 < *(short *)(iVar8 + 0x3c)) {
    do {
      iVar8 = TRIBE_Game::playerColor(param_1,iVar9 + -1);
      sprintf(&puStack_858,&s__d,iVar8);
      uVar10 = 0xffffffff;
      ppuVar15 = &puStack_858;
      do {
        ppuVar16 = ppuVar15;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        ppuVar16 = (undefined1 **)((int)ppuVar15 + 1);
        cVar1 = *(char *)ppuVar15;
        ppuVar15 = ppuVar16;
      } while (cVar1 != '\0');
      uVar10 = ~uVar10;
      iVar8 = -1;
      pcVar13 = acStack_524;
      do {
        pcVar17 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      pcVar13 = (char *)((int)ppuVar16 - uVar10);
      pcVar17 = pcVar17 + -1;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      iVar8 = param_1->_padding_;
      iVar9 = iVar9 + 1;
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    } while (iVar9 < *(short *)(iVar8 + 0x3c));
  }
  uVar10 = 0xffffffff;
  pcVar13 = &s___teams_;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  iVar8 = -1;
  pcVar13 = acStack_524;
  do {
    pcVar14 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar14 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar14;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = pcVar14 + -1;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  iVar8 = param_1->_padding_;
  iVar9 = 1;
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (1 < *(short *)(iVar8 + 0x3c)) {
    do {
      iVar8 = RGE_Base_Game::playerTeam((RGE_Base_Game *)param_1,iVar9 + -1);
      sprintf(&puStack_858,&s__d,iVar8 + -1);
      uVar10 = 0xffffffff;
      ppuVar15 = &puStack_858;
      do {
        ppuVar16 = ppuVar15;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        ppuVar16 = (undefined1 **)((int)ppuVar15 + 1);
        cVar1 = *(char *)ppuVar15;
        ppuVar15 = ppuVar16;
      } while (cVar1 != '\0');
      uVar10 = ~uVar10;
      iVar8 = -1;
      pcVar13 = acStack_524;
      do {
        pcVar17 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      pcVar13 = (char *)((int)ppuVar16 - uVar10);
      pcVar17 = pcVar17 + -1;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      iVar8 = param_1->_padding_;
      iVar9 = iVar9 + 1;
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    } while (iVar9 < *(short *)(iVar8 + 0x3c));
  }
  uVar10 = 0xffffffff;
  pcVar13 = &s___civs_;
  do {
    pcVar17 = pcVar13;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  iVar8 = -1;
  pcVar13 = acStack_524;
  do {
    pcVar14 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar14 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar14;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar10;
  pcVar17 = pcVar14 + -1;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  iVar8 = param_1->_padding_;
  iVar9 = 1;
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (1 < *(short *)(iVar8 + 0x3c)) {
    do {
      iVar8 = TRIBE_Game::civilization(param_1,iVar9 + -1);
      sprintf(&puStack_858,s__d_,iVar8);
      uVar10 = 0xffffffff;
      ppuVar15 = &puStack_858;
      do {
        ppuVar16 = ppuVar15;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        ppuVar16 = (undefined1 **)((int)ppuVar15 + 1);
        cVar1 = *(char *)ppuVar15;
        ppuVar15 = ppuVar16;
      } while (cVar1 != '\0');
      uVar10 = ~uVar10;
      iVar8 = -1;
      pcVar13 = acStack_524;
      do {
        pcVar17 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      pcVar13 = (char *)((int)ppuVar16 - uVar10);
      pcVar17 = pcVar17 + -1;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      iVar8 = param_1->_padding_;
      iVar9 = iVar9 + 1;
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    } while (iVar9 < *(short *)(iVar8 + 0x3c));
  }
  run_log(acStack_524,0);
  this = (TMusic_System *)param_1->_padding_;
  if (this != (TMusic_System *)0x0) {
    uVar2 = this->music_type;
    if (uVar2 == '\x01') {
      TMusic_System::play_tracks(this,5,0xe,1,0,0);
    }
    else if (uVar2 == '\x02') {
      TMusic_System::play_tracks(this,1,this->track_count,1,0,0);
    }
    else if (uVar2 == '\x03') {
      TMusic_System::stop_track(this);
    }
    param_1->started_menu_music = 0;
  }
  RGE_Base_Game::reset_timings((RGE_Base_Game *)param_1);
  (**(code **)(param_1->_padding_ + 0xc))(4);
  iVar8 = RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)param_1);
  if (iVar8 == 1) {
    RGE_Base_Game::set_paused((RGE_Base_Game *)param_1,0,0);
  }
  param_1->_padding_ = 0;
  TChat::ClearChat(chat);
  TChat::setInChatGroup(chat,(int)*(short *)(param_1->_padding_ + 0x7c),1);
  if (((param_1->_padding_ != 0) && (param_1->_padding_ != 0)) &&
     (iVar8 = IsIconic(param_1->_padding_), iVar8 == 0)) {
    TMousePointer::center((TMousePointer *)param_1->_padding_);
  }
  RGE_Base_Game::enable_input((RGE_Base_Game *)param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00528d63
// Address: 00528d63
// [HELPER] s_Blank_Screen: "Blank Screen"
// [HELPER] s_Scenario_Editor_Menu: "Scenario Editor Menu"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Status_Screen: "Status Screen"
undefined4 __fastcall FUN_00528d63(RGE_Base_Game *param_1,char *param_2)
{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  byte bVar5;
  char cVar8;
  byte *in_EAX;
  undefined3 uVar9;
  TRIBE_Screen_Sed *this;
  int iVar6;
  TPanel *pTVar7;
  char cVar10;
  undefined2 uVar11;
  byte bVar12;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar13;
  undefined4 uStack_2d;
  code *pcStack_29;
  undefined4 uStack_25;
  char *pcStack_21;
  char *pcStack_1d;
  int *piStack_19;
  int *piStack_15;
  int *piStack_11;
  undefined4 *puStack_d;
  undefined4 *puStack_8;
  char *pcStack_4;
  
  while( true ) {
    puVar1 = (uint *)((int)unaff_ESI + -0x7917ffae);
    *puVar1 = *puVar1 << 1 | (uint)((int)*puVar1 < 0);
    pcStack_4 = param_2;
    bVar5 = (byte)((uint)in_EAX >> 8);
    bVar12 = (byte)((uint)unaff_EBX >> 8);
    cVar4 = (char)in_EAX;
    cVar8 = bVar5 + bVar12;
    pcVar13 = (char *)CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar8,cVar4));
    LOCK();
    cVar10 = *param_2;
    *param_2 = (char)param_2;
    puStack_8 = (undefined4 *)CONCAT31((int3)((uint)param_2 >> 8),cVar10);
    UNLOCK();
    *(char *)(unaff_EDI + -0x78dbffae) =
         *(char *)(unaff_EDI + -0x78dbffae) + cVar4 + CARRY1(bVar5,bVar12);
    *pcVar13 = *pcVar13 + bVar12;
    LOCK();
    puVar2 = (undefined4 *)*puStack_8;
    *puStack_8 = puStack_8;
    UNLOCK();
    LOCK();
    puStack_d = (undefined4 *)*puVar2;
    *puVar2 = puVar2;
    UNLOCK();
    *(char **)(unaff_EDI + -0x7868ffae) = pcVar13;
    *(char *)(unaff_EBP + -0x4cffad79) = *(char *)(unaff_EBP + -0x4cffad79) + cVar8;
    LOCK();
    piVar3 = (int *)*puStack_d;
    *puStack_d = puStack_d;
    UNLOCK();
    puVar1 = (uint *)(unaff_EDI + -0x7830ffae);
    *puVar1 = *puVar1 << 0x12 | *puVar1 >> 0xe;
    *(char *)&param_1[-1].save_check_for_cd = (char)param_1[-1].save_check_for_cd + cVar4;
    piStack_11 = piVar3;
    *(char *)(unaff_EDI + -0x78) = *(char *)(unaff_EDI + -0x78) + (char)param_1;
    piStack_15 = piVar3;
    *(char *)(unaff_ESI + -0x1e) = *(char *)(unaff_ESI + -0x1e) + (char)((uint)param_1 >> 8);
    piStack_19 = piVar3;
    *(char *)(unaff_EBP + -0x64ffad78) = *(char *)(unaff_EBP + -0x64ffad78) + (char)param_1;
    cVar10 = (char)piVar3;
    *(char *)piVar3 = cVar10;
    *(char *)((int)&piStack_19 + (int)pcVar13) = *(char *)((int)&piStack_19 + (int)pcVar13) + cVar4;
    uVar9 = (undefined3)((uint)pcVar13 >> 8);
    bVar5 = cVar4 + 8;
    *piVar3 = *piVar3 + CONCAT31(uVar9,bVar5);
    param_1 = (RGE_Base_Game *)(param_1->save_music_file + *(int *)(unaff_EBX + 0x5288f0ff) + -0x80)
    ;
    uVar11 = CONCAT11((char)((uint)piVar3 >> 8) + bVar12,cVar10);
    param_2 = (char *)CONCAT22((short)((uint)piVar3 >> 0x10),uVar11);
    *param_2 = cVar10;
    in_EAX = (byte *)(CONCAT31(uVar9,bVar5) | 0x89);
    *param_2 = *param_2 + (char)unaff_EBX;
    cVar10 = *param_2;
    *(char **)param_2 = param_2;
    *(char **)((int)unaff_FS_OFFSET + (int)param_2) = param_2;
    *(char **)param_2 = param_2;
    out(*unaff_ESI,uVar11);
    *(char **)param_2 = param_2;
    if ((POPCOUNT(cVar10) & 1U) != 0) break;
    *in_EAX = *in_EAX | bVar5 | 0x89;
    unaff_EBX = CONCAT31((int3)((uint)unaff_EBX >> 8),(char)unaff_EBX + (bVar5 | 0x89));
    unaff_ESI = unaff_ESI + 1;
  }
  *(char *)(unaff_EBP + -0x6fffad77) = *(char *)(unaff_EBP + -0x6fffad77) + (char)in_EAX;
  *(char **)param_2 = param_2;
  uStack_25 = 0xffffffff;
  pcStack_29 = FUN_0056180b;
  uStack_2d = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_2d;
  pcStack_21 = param_2;
  RGE_Base_Game::disable_input(param_1);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  this = (TRIBE_Screen_Sed *)operator_new(0x948);
  uStack_25 = 0;
  if (this == (TRIBE_Screen_Sed *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = TRIBE_Screen_Sed::TRIBE_Screen_Sed(this,pcStack_1d,(int)piStack_19);
  }
  uStack_25 = 0xffffffff;
  if ((iVar6 != 0) && (*(int *)(iVar6 + 0xd8) == 0)) {
    if (param_1->music_system != (TMusic_System *)0x0) {
      TMusic_System::stop_track(param_1->music_system);
      param_1[1].work_dir[0x10] = '\0';
      param_1[1].work_dir[0x11] = '\0';
      param_1[1].work_dir[0x12] = '\0';
      param_1[1].work_dir[0x13] = '\0';
    }
    TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Open);
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Menu);
    TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
    TMousePointer::center(param_1->mouse_pointer);
    RGE_Base_Game::enable_input(param_1);
    *unaff_FS_OFFSET = uStack_2d;
    return 1;
  }
  pTVar7 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Open);
  if (pTVar7 == (TPanel *)0x0) {
    pTVar7 = TPanelSystem::panel(&panel_system,s_Scenario_Editor_Menu);
    if (pTVar7 == (TPanel *)0x0) {
      pcVar13 = s_Blank_Screen;
    }
    else {
      pcVar13 = s_Scenario_Editor_Menu;
    }
  }
  else {
    pcVar13 = s_Scenario_Editor_Open;
  }
  TPanelSystem::setCurrentPanel(&panel_system,pcVar13,0);
  TPanelSystem::destroyPanel(&panel_system,s_Scenario_Editor_Screen);
  TPanelSystem::destroyPanel(&panel_system,s_Status_Screen);
  RGE_Base_Game::enable_input(param_1);
  *unaff_FS_OFFSET = uStack_2d;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00528f56
// Address: 00528f56
void __fastcall FUN_00528f56(TRIBE_Game *param_1)
{
  RGE_Game_Options RStack_114;
  TRIBE_Game_Options TStack_6c;
  
  if (param_1->_padding_ != 0) {
    RGE_Base_Game::get_game_options((RGE_Base_Game *)param_1,&RStack_114);
    TRIBE_Game::get_tribe_options(param_1,&TStack_6c);
    TCommunications_Handler::SetMyGameOptions
              ((TCommunications_Handler *)param_1->_padding_,(char *)&RStack_114,0x114);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00528fa9
// Address: 00528fa9
void __fastcall FUN_00528fa9(TRIBE_Game *param_1)
{
  RGE_Game_Options *pRVar1;
  ulong uStack_4;
  
  if ((TCommunications_Handler *)param_1->_padding_ != (TCommunications_Handler *)0x0) {
    uStack_4 = 0;
    pRVar1 = (RGE_Game_Options *)
             TCommunications_Handler::GetMyGameOptions
                       ((TCommunications_Handler *)param_1->_padding_,&uStack_4);
    if ((pRVar1 != (RGE_Game_Options *)0x0) && (uStack_4 == 0x114)) {
      RGE_Base_Game::set_game_options((RGE_Base_Game *)param_1,pRVar1);
      TRIBE_Game::set_tribe_options(param_1,(TRIBE_Game_Options *)(pRVar1 + 1));
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00528ffb
// Address: 00528ffb
void __thiscall FUN_00528ffb(TRIBE_Game *param_1,MapSize *param_2)
{
  MapSize *pMVar1;
  int iVar2;
  
  TRIBE_Game::setMapSize(param_1,*param_2);
  TRIBE_Game::setMapType(param_1,param_2[1]);
  TRIBE_Game::setAnimals(param_1,param_2[2]);
  TRIBE_Game::setPredators(param_1,param_2[3]);
  TRIBE_Game::setVictoryType(param_1,param_2[4],param_2[5]);
  iVar2 = 0;
  pMVar1 = param_2 + 9;
  do {
    TRIBE_Game::setCivilization(param_1,iVar2,(uint)*(byte *)(iVar2 + 0x18 + (int)param_2));
    TRIBE_Game::setScenarioPlayer(param_1,iVar2,*pMVar1);
    TRIBE_Game::setPlayerColor(param_1,iVar2,(uint)*(byte *)(iVar2 + 0x48 + (int)param_2));
    TRIBE_Game::setComputerName(param_1,iVar2,(uint)*(byte *)(iVar2 + 0x51 + (int)param_2));
    iVar2 = iVar2 + 1;
    pMVar1 = pMVar1 + 1;
  } while (iVar2 < 9);
  TRIBE_Game::setAllowTrading(param_1,(uint)*(byte *)((int)param_2 + 0x5a));
  TRIBE_Game::setLongCombat(param_1,(uint)*(byte *)((int)param_2 + 0x5b));
  TRIBE_Game::setRandomizePositions(param_1,(uint)(byte)(char)param_2[0x17]);
  TRIBE_Game::setFullTechTree(param_1,(uint)*(byte *)((int)param_2 + 0x5d));
  TRIBE_Game::setResourceLevel(param_1,param_2[0x18]);
  TRIBE_Game::setStartingAge(param_1,param_2[0x19]);
  TRIBE_Game::setStartingUnits(param_1,(uint)(byte)(char)param_2[0x1a]);
  TRIBE_Game::setDeathMatch(param_1,*(byte *)((int)param_2 + 0x69));
  TRIBE_Game::setPopLimit(param_1,*(byte *)((int)param_2 + 0x6a));
  return;
}

// --------------------------------------------------

// Function: FUN_005290fd
// Address: 005290fd
void __thiscall FUN_005290fd(TRIBE_Game *param_1,MapSize *param_2)
{
  byte bVar1;
  MapSize MVar2;
  int iVar3;
  ResourceLevel RVar4;
  Age AVar5;
  MapSize *pMVar6;
  int iVar7;
  
  MVar2 = TRIBE_Game::mapSize(param_1);
  *param_2 = MVar2;
  MVar2 = TRIBE_Game::mapType(param_1);
  param_2[1] = MVar2;
  MVar2 = TRIBE_Game::animals(param_1);
  param_2[2] = MVar2;
  MVar2 = TRIBE_Game::predators(param_1);
  param_2[3] = MVar2;
  MVar2 = TRIBE_Game::victoryType(param_1);
  param_2[4] = MVar2;
  MVar2 = TRIBE_Game::victoryAmount(param_1);
  param_2[5] = MVar2;
  iVar7 = 0;
  pMVar6 = param_2 + 9;
  do {
    iVar3 = TRIBE_Game::civilization(param_1,iVar7);
    *(char *)(iVar7 + 0x18 + (int)param_2) = (char)iVar3;
    MVar2 = TRIBE_Game::scenarioPlayer(param_1,iVar7);
    *pMVar6 = MVar2;
    iVar3 = TRIBE_Game::playerColor(param_1,iVar7);
    *(char *)(iVar7 + 0x48 + (int)param_2) = (char)iVar3;
    iVar3 = TRIBE_Game::computerName(param_1,iVar7);
    *(char *)(iVar7 + 0x51 + (int)param_2) = (char)iVar3;
    iVar7 = iVar7 + 1;
    pMVar6 = pMVar6 + 1;
  } while (iVar7 < 9);
  iVar7 = TRIBE_Game::allowTrading(param_1);
  *(byte *)((int)param_2 + 0x5a) = (byte)iVar7;
  iVar7 = TRIBE_Game::longCombat(param_1);
  *(byte *)((int)param_2 + 0x5b) = (byte)iVar7;
  iVar7 = TRIBE_Game::randomizePositions(param_1);
  *(char *)(param_2 + 0x17) = (char)iVar7;
  iVar7 = TRIBE_Game::fullTechTree(param_1);
  *(byte *)((int)param_2 + 0x5d) = (byte)iVar7;
  RVar4 = TRIBE_Game::resourceLevel(param_1);
  param_2[0x18] = RVar4;
  AVar5 = TRIBE_Game::startingAge(param_1);
  param_2[0x19] = AVar5;
  iVar7 = TRIBE_Game::startingUnits(param_1);
  *(char *)(param_2 + 0x1a) = (char)iVar7;
  bVar1 = TRIBE_Game::deathMatch(param_1);
  *(byte *)((int)param_2 + 0x69) = bVar1;
  bVar1 = TRIBE_Game::popLimit(param_1);
  *(byte *)((int)param_2 + 0x6a) = bVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_005291e1
// Address: 005291e1
undefined4 __fastcall FUN_005291e1(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa7c);
}

// --------------------------------------------------

// Function: FUN_005291f7
// Address: 005291f7
void __thiscall FUN_005291f7(RGE_Base_Game *param_1,undefined4 param_2)
{
  *(undefined4 *)&param_1[1].shape_num = param_2;
  switch(param_2) {
  case 0:
    RGE_Base_Game::setMapSize(param_1,0x48,0x48,8);
    return;
  case 1:
    RGE_Base_Game::setMapSize(param_1,0x60,0x60,8);
    return;
  case 2:
    RGE_Base_Game::setMapSize(param_1,0x78,0x78,8);
    return;
  case 3:
    RGE_Base_Game::setMapSize(param_1,0x90,0x90,8);
    return;
  case 4:
    RGE_Base_Game::setMapSize(param_1,200,200,8);
    return;
  case 5:
    RGE_Base_Game::setMapSize(param_1,0xfa,0xfa,8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005292a7
// Address: 005292a7
void __thiscall FUN_005292a7(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xa80) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_005292bd
// Address: 005292bd
undefined4 __fastcall FUN_005292bd(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa84);
}

// --------------------------------------------------

