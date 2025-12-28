// Class: TRIBE_Gaia
// Size:  0x858
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] set_game_status
// [02] do_resign
// [03] changeToHumanPlayer
// [04] changeToComputerPlayer
// [05] aiStatus
// [06] isEnemy
// [07] isAlly
// [08] isNeutral
// [09] isAllNeutral
// [10] setDiplomaticStance
// [11] loadAIInformation
// [12] sendUnitAIOrder
// [13] processAIOrder
// [14] kickAI
// [15] strategicNumber
// [16] sendGameOrder
// [17] sendAddWaypointCommand
// [18] processAddWaypointCommand
// [19] sendPlayCommand
// [20] sendPlayCommand
// [21] sendAICommand
// [22] objectCostByType
// [23] trackUnitGather
// [24] make_scenario_obj
// [25] scenario_save
// [26] scenario_load
// [27] scenario_postsave
// [28] scenario_postload
// [29] load
// [30] add_attribute_num
// [31] update
// [32] update_dopplegangers
// [33] save
// [34] save2
// [35] save_info
// [36] random_start
// [37] make_new_object
// [38] analyize_selected_objects
// [39] get_mouse_pointer_action_vars
// [40] command_make_move
// [41] command_make_work
// [42] command_make_do
// [43] command_stop
// [44] command_place_object
// [45] command_add_attribute
// [46] command_give_attribute
// [47] command_formation
// [48] command_stand_ground
// [49] command_create_group
// [50] command_add_to_group
// [51] command_remove_from_group
// [52] command_destroy_group
// [53] command_resign
// [54] command_add_waypoint
// [55] addObject
// [56] removeObject
// [57] logMessage
// [58] notify
// [59] logStatus
// [60] load_victory
// [61] new_victory
// [62] command_give_attribute
// [63] buildObject
// [64] cancelBuild
// [65] registerBuild
// [66] trainUnit
// [67] cancelTrain
// [68] registerTrain
// [69] research
// [70] cancelResearch
// [71] registerResearch
// [72] taskTrader
// [73] taskResourceGatherer
// [74] notifyAI
//
// Member Layout:
// [0x848] float update_time
// [0x84C] long update_nature
// [0x850] long last_count
// [0x854] long animal_max
// ----------------------------------------------------------------

// Function: TRIBE_Gaia
// Address: 00519af0
TRIBE_Gaia * __thiscall
TRIBE_Gaia::TRIBE_Gaia(TRIBE_Gaia *this,int param_1,TRIBE_World *param_2,uchar param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005612d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TRIBE_Player::TRIBE_Player((TRIBE_Player *)this,param_1,param_2,param_3);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)&this->_padding_ = 2;
  rge_read(param_1,&this->update_time,4);
  rge_read(param_1,&this->update_nature,4);
  rge_read(param_1,&this->animal_max,4);
  rge_read(param_1,&this->last_count,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00519ba0
void * __thiscall TRIBE_Gaia::_vector_deleting_destructor_(TRIBE_Gaia *this,uint param_1)
{
  ~TRIBE_Gaia(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Gaia
// Address: 00519bc0
void __thiscall TRIBE_Gaia::~TRIBE_Gaia(TRIBE_Gaia *this)
{
  TRIBE_Player_Tech *this_00;
  TRIBE_History_Info *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_005611d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&TRIBE_Player::_vftable_;
  this_00 = (TRIBE_Player_Tech *)this->_padding_;
  uStack_4 = 0;
  if (this_00 != (TRIBE_Player_Tech *)0x0) {
    TRIBE_Player_Tech::~TRIBE_Player_Tech(this_00);
    operator_delete(this_00);
    this->_padding_ = 0;
  }
  if ((undefined4 *)this->_padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->_padding_)(1);
    this->_padding_ = 0;
  }
  this_01 = (TRIBE_History_Info *)this->_padding_;
  if (this_01 != (TRIBE_History_Info *)0x0) {
    TRIBE_History_Info::~TRIBE_History_Info(this_01);
    operator_delete(this_01);
    this->_padding_ = 0;
  }
  uStack_4 = 0xffffffff;
  RGE_Player::~RGE_Player((RGE_Player *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: TRIBE_Gaia
// Address: 00519bd0
TRIBE_Gaia * __thiscall
TRIBE_Gaia::TRIBE_Gaia
          (TRIBE_Gaia *this,TRIBE_World *param_1,RGE_Master_Player *param_2,uchar param_3,
          char *param_4,uchar param_5)
{
  TRIBE_Player::TRIBE_Player
            ((TRIBE_Player *)this,param_1,param_2,param_3,param_4,param_5,'\0','\x01',(char *)0x0,
             (char *)0x0,(char *)0x0);
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)&this->_padding_ = 2;
  this->update_time = 0.0;
  this->update_nature = 0x1d;
  this->animal_max = 0;
  this->last_count = 0;
  return this;
}

// --------------------------------------------------

// Function: save
// Address: 00519c40
void __thiscall TRIBE_Gaia::save(TRIBE_Gaia *this,int param_1)
{
  TRIBE_Player::save((TRIBE_Player *)this,param_1);
  rge_write(param_1,&this->update_time,4);
  rge_write(param_1,&this->update_nature,4);
  rge_write(param_1,&this->animal_max,4);
  rge_write(param_1,&this->last_count,4);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00519ca0
void __thiscall TRIBE_Gaia::update(TRIBE_Gaia *this)
{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = _DAT_00576824;
  fVar1 = *(float *)(this->_padding_ + 0x84) + this->update_time;
  this->update_time = fVar1;
  if (fVar2 < fVar1) {
    do {
      fVar1 = this->update_time - _DAT_00576824;
      iVar3 = this->update_nature + 1;
      this->update_nature = iVar3;
      this->update_time = fVar1;
      if (iVar3 == 0x1e) {
        this->update_nature = 0;
      }
    } while (_DAT_00576824 < this->update_time);
  }
  RGE_Player::update((RGE_Player *)this);
  return;
}

// --------------------------------------------------

// Function: load_master_object
// Address: 00519d10
void __thiscall
TRIBE_Gaia::load_master_object
          (TRIBE_Gaia *this,int param_1,short param_2,uchar param_3,RGE_Sprite **param_4,
          RGE_Sound **param_5)
{
  TRIBE_Player::load_master_object((TRIBE_Player *)this,param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: random_start
// Address: 00519d40
void __thiscall TRIBE_Gaia::random_start(TRIBE_Gaia *this)
{
  return;
}

// --------------------------------------------------

