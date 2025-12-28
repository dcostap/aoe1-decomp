// Class: TRIBE_Object_List
// Size:  0xC
//
// VTable Layout:
// [00] load
// [01] `vector_deleting_destructor'
// [02] set_game_status
// [03] do_resign
// [04] changeToHumanPlayer
// [05] changeToComputerPlayer
// [06] aiStatus
// [07] isEnemy
// [08] isAlly
// [09] isNeutral
// [10] isAllNeutral
// [11] setDiplomaticStance
// [12] loadAIInformation
// [13] sendUnitAIOrder
// [14] processAIOrder
// [15] kickAI
// [16] strategicNumber
// [17] sendGameOrder
// [18] sendAddWaypointCommand
// [19] processAddWaypointCommand
// [20] sendPlayCommand
// [21] sendPlayCommand
// [22] sendAICommand
// [23] objectCostByType
// [24] trackUnitGather
// [25] make_scenario_obj
// [26] scenario_save
// [27] scenario_load
// [28] scenario_postsave
// [29] scenario_postload
// [30] load
// [31] add_attribute_num
// [32] update
// [33] update_dopplegangers
// [34] save
// [35] save2
// [36] save_info
// [37] random_start
// [38] make_new_object
// [39] analyize_selected_objects
// [40] get_mouse_pointer_action_vars
// [41] command_make_move
// [42] command_make_work
// [43] command_make_do
// [44] command_stop
// [45] command_place_object
// [46] command_add_attribute
// [47] command_give_attribute
// [48] command_formation
// [49] command_stand_ground
// [50] command_create_group
// [51] command_add_to_group
// [52] command_remove_from_group
// [53] command_destroy_group
// [54] command_resign
// [55] command_add_waypoint
// [56] addObject
// [57] removeObject
// [58] logMessage
// [59] notify
// [60] logStatus
// [61] load_victory
// [62] new_victory
// [63] command_give_attribute
// [64] buildObject
// [65] cancelBuild
// [66] registerBuild
// [67] trainUnit
// [68] cancelTrain
// [69] registerTrain
// [70] research
// [71] cancelResearch
// [72] registerResearch
// [73] taskTrader
// [74] taskResourceGatherer
// [75] notifyAI
//
// Member Layout:
// ----------------------------------------------------------------

// Function: load
// Address: 00511b00
void __thiscall
TRIBE_Object_List::load(TRIBE_Object_List *this,uchar param_1,int param_2,RGE_Game_World *param_3)
{
  TRIBE_Building_Object *this_00;
  TRIBE_Combat_Object *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561116;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 == 'F') {
    this_01 = (TRIBE_Combat_Object *)operator_new(0x1c8);
    local_4 = 0;
    if (this_01 != (TRIBE_Combat_Object *)0x0) {
      TRIBE_Combat_Object::TRIBE_Combat_Object(this_01,param_2,param_3,1);
    }
  }
  else {
    if (param_1 != 'P') {
      RGE_Object_List::load((RGE_Object_List *)this,param_1,param_2,param_3);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    this_00 = (TRIBE_Building_Object *)operator_new(0x204);
    local_4 = 1;
    if (this_00 != (TRIBE_Building_Object *)0x0) {
      TRIBE_Building_Object::TRIBE_Building_Object(this_00,param_2,param_3,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

