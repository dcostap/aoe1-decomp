// Class: TRIBE_Building_Object
// Size:  0x204
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] recycle_in_to_game
// [02] recycle_out_of_game
// [03] draw
// [04] shadow_draw
// [05] normal_draw
// [06] draw_front_frame
// [07] draw_back_frame
// [08] draw_frame
// [09] update
// [10] check_damage_sprites
// [11] rehook
// [12] save
// [13] teleport
// [14] new_sprite
// [15] add_overlay_sprite
// [16] remove_overlay_sprite
// [17] change_ownership
// [18] modify
// [19] modify_delta
// [20] modify_percent
// [21] transform
// [22] copy_obj
// [23] set_object_state
// [24] remove_visible_resource
// [25] create_doppleganger_when_dying
// [26] destroy_obj
// [27] die_die_die
// [28] damage
// [29] calculateDamage
// [30] rotate
// [31] can_attack
// [32] set_attribute
// [33] set_attribute_amount
// [34] heal
// [35] heal
// [36] canRepair
// [37] notify_of_relation
// [38] do_command
// [39] move_to
// [40] work
// [41] stop
// [42] set_attack
// [43] play_command_sound
// [44] play_move_sound
// [45] new_angle
// [46] spawn_death_obj
// [47] get_command_master
// [48] set_being_worked_on
// [49] release_being_worked_on
// [50] is_moving
// [51] get_target_obj
// [52] enter_obj
// [53] exit_obj
// [54] explore_terrain
// [55] unexplore_terrain
// [56] get_los_table
// [57] inAttackRange
// [58] underAttack
// [59] setUnderAttack
// [60] calc_attack_modifier
// [61] getSpeed
// [62] getAngle
// [63] maximumSpeed
// [64] rateOfFire
// [65] damageCapability
// [66] damageCapability
// [67] weaponRange
// [68] minimumWeaponRange
// [69] passableTile
// [70] facetToNextWaypoint
// [71] currentTargetID
// [72] currentTargetX
// [73] currentTargetY
// [74] currentTargetZ
// [75] setWaitingToMove
// [76] waitingToMove
// [77] actionState
// [78] keepGatheringWhenObjectIsOut
// [79] produceWhenKilledBy
// [80] useSameZoneDropsite
// [81] logDebug
// [82] notify
// [83] attack
// [84] attack
// [85] moveTo
// [86] moveTo
// [87] moveTo
// [88] moveAwayFrom
// [89] hunt
// [90] gather
// [91] convert
// [92] repair
// [93] build
// [94] trade
// [95] explore
// [96] enter
// [97] unload
// [98] transport
// [99] stopAction
// [100] pause
// [101] canPath
// [102] canPath
// [103] canBidirectionPath
// [104] canPathWithObstructions
// [105] canPathWithAdditionalPassability
// [106] findFirstTerrainAlongExceptionPath
// [107] canLinePath
// [108] canLinePath
// [109] firstTileAlongLine
// [110] userDefinedWaypoint
// [111] addUserDefinedWaypoint
// [112] removeAllUserDefinedWaypoints
// [113] removeUserDefinedWaypoint
// [114] numberUserDefinedWaypoints
// [115] findAvoidancePath
// [116] get_action_checksum
// [117] get_waypoint_checksum
// [118] setup
// [119] setup
// [120] create_object_list
// [121] create_sprite_list
// [122] setup
// [123] stop_moving
// [124] turn_towards
// [125] setup
// [126] work2
// [127] set_task
// [128] setTaskByTaskID
// [129] set_action
// [130] set_only_action
// [131] set_end_action
// [132] getTask
// [133] setup
// [134] create_action_list
// [135] area_attack
// [136] attack
// [137] attack
// [138] do_attack
// [139] get_armor
// [140] get_weapon
// [141] get_weapon_range
// [142] get_speed_of_attack
// [143] setup
// [144] cancel_object
// [145] get_pierce_armor
// [146] higher_check_for_cliff
// [147] higher_than_target
// [148] initUnitAI
// [149] setup
// [150] take_building_attribute_from_owner
// [151] give_building_attribute_to_owner
// [152] setup
//
// Member Layout:
// [0x1C8] Production_Queue_Record * production_queue
// [0x1CC] short production_queue_size
// [0x1CE] short production_queue_count
// [0x1D0] uchar production_queue_enabled
// [0x1D4] RGE_Action_List * production_queue_actions
// [0x1D8] uchar production_queue_change_flag
// [0x1D9] uchar production_queue_auto_paused
// [0x1DA] short production_queue_need_attr
// [0x1DC] float build_pts
// [0x1E0] int unique_build_id
// [0x1E4] uchar culture
// [0x1E5] uchar built
// [0x1E8] int DoppleInstalled
// [0x1EC] ulong PriorMap1
// [0x1F0] ulong PriorMap2
// [0x1F4] ulong PriorMap3
// [0x1F8] long PriorTurn1
// [0x1FC] long PriorTurn2
// [0x200] long PriorTurn3
// ----------------------------------------------------------------

// Function: TRIBE_Building_Object
// Address: 004c7f50
TRIBE_Building_Object * __thiscall
TRIBE_Building_Object::TRIBE_Building_Object
          (TRIBE_Building_Object *this,TRIBE_Master_Building_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6,int param_7)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fa78;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TRIBE_Combat_Object::TRIBE_Combat_Object
            ((TRIBE_Combat_Object *)this,(TRIBE_Master_Combat_Object *)param_1,param_2,param_3,
             param_4,param_5,0);
  local_4 = 0;
  this->unique_build_id = param_6;
  this->production_queue = (Production_Queue_Record *)0x0;
  this->production_queue_size = 0;
  this->production_queue_count = 0;
  this->production_queue_enabled = '\x01';
  this->production_queue_actions = (RGE_Action_List *)0x0;
  this->production_queue_change_flag = '\0';
  this->production_queue_auto_paused = '\0';
  this->production_queue_need_attr = -1;
  this->DoppleInstalled = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_7 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  if (*(short *)(this->_padding_ + 0x10) == 0x114) {
    RGE_Action_Object::set_task((RGE_Action_Object *)this,*(short *)(this->_padding_ + 0xdc));
  }
  iVar1 = __ftol();
  iVar2 = __ftol();
  iVar1 = RGE_Doppleganger_Creator::add_doppleganger_check
                    (*(RGE_Doppleganger_Creator **)(this->_padding_ + 0x40),
                     (RGE_Static_Object *)this,(ulong *)((&unified_map_offsets)[iVar1] + iVar2));
  this->DoppleInstalled = iVar1;
  this->PriorMap1 = 0;
  this->PriorMap2 = 0;
  this->PriorMap3 = 0;
  this->PriorTurn1 = 0;
  this->PriorTurn2 = 0;
  this->PriorTurn3 = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004c8090
void * __thiscall
TRIBE_Building_Object::_scalar_deleting_destructor_(TRIBE_Building_Object *this,uint param_1)
{
  ~TRIBE_Building_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Building_Object
// Address: 004c80b0
TRIBE_Building_Object * __thiscall
TRIBE_Building_Object::TRIBE_Building_Object
          (TRIBE_Building_Object *this,TRIBE_Master_Building_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fa98;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TRIBE_Combat_Object::TRIBE_Combat_Object
            ((TRIBE_Combat_Object *)this,(TRIBE_Master_Combat_Object *)param_1,param_2,param_3,
             param_4,param_5,0);
  local_4 = 0;
  this->production_queue_need_attr = -1;
  this->unique_build_id = -1;
  this->production_queue = (Production_Queue_Record *)0x0;
  this->production_queue_size = 0;
  this->production_queue_count = 0;
  this->production_queue_enabled = '\x01';
  this->production_queue_actions = (RGE_Action_List *)0x0;
  this->production_queue_change_flag = '\0';
  this->production_queue_auto_paused = '\0';
  this->DoppleInstalled = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = __ftol();
  iVar2 = __ftol();
  iVar1 = RGE_Doppleganger_Creator::add_doppleganger_check
                    (*(RGE_Doppleganger_Creator **)(this->_padding_ + 0x40),
                     (RGE_Static_Object *)this,(ulong *)((&unified_map_offsets)[iVar1] + iVar2));
  this->DoppleInstalled = iVar1;
  this->PriorMap1 = 0;
  this->PriorMap2 = 0;
  this->PriorMap3 = 0;
  this->PriorTurn1 = 0;
  this->PriorTurn2 = 0;
  this->PriorTurn3 = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Building_Object
// Address: 004c81d0
TRIBE_Building_Object * __thiscall
TRIBE_Building_Object::TRIBE_Building_Object
          (TRIBE_Building_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fab8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TRIBE_Combat_Object::TRIBE_Combat_Object((TRIBE_Combat_Object *)this,param_1,param_2,0);
  local_4 = 0;
  this->production_queue = (Production_Queue_Record *)0x0;
  this->production_queue_size = 0;
  this->production_queue_count = 0;
  this->production_queue_enabled = '\x01';
  this->production_queue_actions = (RGE_Action_List *)0x0;
  this->production_queue_change_flag = '\0';
  this->production_queue_auto_paused = '\0';
  this->production_queue_need_attr = -1;
  this->DoppleInstalled = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  iVar1 = __ftol();
  iVar2 = __ftol();
  iVar1 = RGE_Doppleganger_Creator::add_doppleganger_check
                    (*(RGE_Doppleganger_Creator **)(this->_padding_ + 0x40),
                     (RGE_Static_Object *)this,(ulong *)((&unified_map_offsets)[iVar1] + iVar2));
  this->DoppleInstalled = iVar1;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Building_Object
// Address: 004c82a0
void __thiscall TRIBE_Building_Object::~TRIBE_Building_Object(TRIBE_Building_Object *this)
{
  RGE_Action_List *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055fad8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  RGE_Doppleganger_Creator::remove_doppleganger_check
            (*(RGE_Doppleganger_Creator **)(this->_padding_ + 0x40),(RGE_Static_Object *)this);
  this_00 = this->production_queue_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->production_queue_actions = (RGE_Action_List *)0x0;
  }
  if (this->production_queue != (Production_Queue_Record *)0x0) {
    free(this->production_queue);
    this->production_queue = (Production_Queue_Record *)0x0;
    if (this->production_queue_need_attr == 4) {
      this->production_queue_need_attr = -1;
      iVar1 = (int)*(short *)(this->_padding_ + 0x4a);
      *(int *)(rge_base_game[1].save_music_file + iVar1 * 4 + -0x70) =
           *(int *)(rge_base_game[1].save_music_file + iVar1 * 4 + -0x70) + -1;
    }
  }
  local_4 = 0xffffffff;
  TRIBE_Combat_Object::~TRIBE_Combat_Object((TRIBE_Combat_Object *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: recycle_out_of_game
// Address: 004c8370
void __thiscall TRIBE_Building_Object::recycle_out_of_game(TRIBE_Building_Object *this)
{
  if (this->production_queue_actions != (RGE_Action_List *)0x0) {
    RGE_Action_List::delete_list(this->production_queue_actions);
  }
  if (this->production_queue != (Production_Queue_Record *)0x0) {
    free(this->production_queue);
    this->production_queue = (Production_Queue_Record *)0x0;
    this->production_queue_size = 0;
    this->production_queue_count = 0;
    this->production_queue_enabled = '\x01';
    this->production_queue_change_flag = '\0';
    this->production_queue_auto_paused = '\0';
    this->production_queue_need_attr = -1;
  }
  RGE_Action_Object::recycle_out_of_game((RGE_Action_Object *)this);
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 004c83e0
int __thiscall
TRIBE_Building_Object::setup
          (TRIBE_Building_Object *this,TRIBE_Master_Building_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  int iVar1;
  int iVar2;
  RGE_Action_List *pRVar3;
  
  this->built = '\0';
  TRIBE_Combat_Object::setup
            ((TRIBE_Combat_Object *)this,(TRIBE_Master_Combat_Object *)param_1,param_2,param_3,
             param_4,param_5);
  iVar1 = this->_padding_;
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x50;
  (**(code **)(iVar1 + 0x5c))(0);
  if (0 < *(short *)(this->_padding_ + 0x15a)) {
    (**(code **)(iVar1 + 0x38))(*(undefined4 *)(this->_padding_ + 0x168));
  }
  iVar2 = this->_padding_;
  this->build_pts = 0.0;
  this->_padding_ = 0x3f800000;
  *(undefined1 *)((int)&this->_padding_ + 1) = *(undefined1 *)(iVar2 + 0x16e);
  this->culture = param_2->culture;
  TRIBE_World::check_destructables
            (*(TRIBE_World **)(this->_padding_ + 0x3c),*(short *)(this->_padding_ + 0x4a),
             *(short *)(iVar2 + 0x10),(float)this->_padding_,(float)this->_padding_,'\0');
  pRVar3 = (RGE_Action_List *)(**(code **)(iVar1 + 0x218))();
  this->production_queue_actions = pRVar3;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 004c8490
int __thiscall
TRIBE_Building_Object::setup(TRIBE_Building_Object *this,int param_1,RGE_Game_World *param_2)
{
  short *psVar1;
  RGE_Action_List *pRVar2;
  Production_Queue_Record *pPVar3;
  short sVar4;
  
  TRIBE_Combat_Object::setup((TRIBE_Combat_Object *)this,param_1,param_2);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x50;
  rge_read(param_1,&this->built,1);
  rge_read(param_1,&this->build_pts,4);
  rge_read(param_1,&this->unique_build_id,4);
  rge_read(param_1,&this->culture,1);
  pRVar2 = (RGE_Action_List *)(**(code **)(this->_padding_ + 0x218))();
  this->production_queue_actions = pRVar2;
  if (_DAT_005749e0 <= save_game_version) {
    psVar1 = &this->production_queue_size;
    rge_read(param_1,psVar1,2);
    if (0 < *psVar1) {
      pPVar3 = (Production_Queue_Record *)calloc((int)*psVar1,4);
      sVar4 = 0;
      this->production_queue = pPVar3;
      if (0 < *psVar1) {
        do {
          rge_read(param_1,this->production_queue + sVar4,2);
          rge_read(param_1,&this->production_queue[sVar4].unit_count,2);
          sVar4 = sVar4 + 1;
        } while (sVar4 < this->production_queue_size);
      }
    }
    rge_read(param_1,&this->production_queue_count,2);
    rge_read(param_1,&this->production_queue_enabled,1);
    RGE_Action_List::load(this->production_queue_actions,param_1);
  }
  return 1;
}

// --------------------------------------------------

// Function: take_building_attribute_from_owner
// Address: 004c85d0
void __thiscall
TRIBE_Building_Object::take_building_attribute_from_owner(TRIBE_Building_Object *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0x6a;
  iVar3 = 0x70;
  do {
    iVar1 = this->_padding_;
    if ((3 < *(byte *)(iVar4 + 0x88 + iVar1)) && (-1 < *(short *)(iVar2 + iVar1))) {
      (**(code **)(*(int *)this->_padding_ + 0x78))
                (*(short *)(iVar2 + iVar1),-*(float *)(iVar3 + iVar1),0);
    }
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 2;
  } while (iVar3 < 0x7c);
  return;
}

// --------------------------------------------------

// Function: give_building_attribute_to_owner
// Address: 004c8630
void __thiscall TRIBE_Building_Object::give_building_attribute_to_owner(TRIBE_Building_Object *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0x6a;
  iVar3 = 0x70;
  do {
    iVar1 = this->_padding_;
    if ((3 < *(byte *)(iVar4 + 0x88 + iVar1)) && (-1 < *(short *)(iVar2 + iVar1))) {
      (**(code **)(*(int *)this->_padding_ + 0x78))
                (*(short *)(iVar2 + iVar1),*(undefined4 *)(iVar3 + iVar1),0);
    }
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 2;
  } while (iVar3 < 0x7c);
  return;
}

// --------------------------------------------------

// Function: destroy_obj
// Address: 004c8690
void __thiscall TRIBE_Building_Object::destroy_obj(TRIBE_Building_Object *this)
{
  (**(code **)(this->_padding_ + 600))();
  RGE_Action_Object::destroy_obj((RGE_Action_Object *)this);
  RGE_Doppleganger_Creator::remove_doppleganger_check
            (*(RGE_Doppleganger_Creator **)(this->_padding_ + 0x40),(RGE_Static_Object *)this);
  this->DoppleInstalled = 0;
  return;
}

// --------------------------------------------------

// Function: heal
// Address: 004c86c0
uchar __thiscall TRIBE_Building_Object::heal(TRIBE_Building_Object *this,float param_1)
{
  int iVar1;
  float fVar2;
  uchar uVar3;
  
  iVar1 = this->_padding_;
  fVar2 = (float)(int)*(short *)(iVar1 + 0x26);
  param_1 = (param_1 * fVar2) / (float)(int)*(short *)(iVar1 + 0x15a);
  if (fVar2 < param_1 + (float)this->_padding_) {
    param_1 = fVar2 - (float)this->_padding_;
  }
  uVar3 = TRIBE_Player::pay_obj_cost
                    ((TRIBE_Player *)this->_padding_,*(short *)(iVar1 + 0x10),
                     param_1 / (float)(*(short *)(iVar1 + 0x26) * 2),0);
  if (uVar3 == '\0') {
    return '\x02';
  }
  uVar3 = TRIBE_Combat_Object::heal((TRIBE_Combat_Object *)this,param_1);
  return uVar3;
}

// --------------------------------------------------

// Function: set_object_state
// Address: 004c8740
// [HELPER] s_C__msdev_work_age1_x1_t_b_obj_cp: "C:\msdev\work\age1_x1\t_b_obj.cpp"
void __thiscall TRIBE_Building_Object::set_object_state(TRIBE_Building_Object *this,uchar param_1)
{
  RGE_Sound *this_00;
  RGE_Game_World *pRVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  uint uVar7;
  undefined4 uVar8;
  RGE_Static_Object *pRVar9;
  int iVar10;
  int iVar11;
  uchar uVar12;
  uchar uVar13;
  int iVar14;
  
  if (param_1 == '\x02') {
    this->build_pts = (float)(int)*(short *)(this->_padding_ + 0x15a);
    uVar7 = debug_rand(s_C__msdev_work_age1_x1_t_b_obj_cp,299);
    iVar14 = debug_random_on;
    debug_random_on = 0;
    this_00 = *(RGE_Sound **)(this->_padding_ + 0x164);
    if ((this_00 != (RGE_Sound *)0x0) &&
       (*(short *)(this->_padding_ + 0x4a) == *(short *)(*(int *)(this->_padding_ + 0x3c) + 0x7c)))
{
      RGE_Sound::play(this_00,1);
    }
    debug_random_on = iVar14;
    debug_srand(s_C__msdev_work_age1_x1_t_b_obj_cp,0x135,uVar7);
    iVar14 = this->_padding_;
    this->built = '\x01';
    (**(code **)(iVar14 + 0x25c))();
    if (*(char *)(this->_padding_ + 0x170) == '\0') {
      (**(code **)(iVar14 + 0xdc))(this->_padding_,1,0xffffffff);
      (**(code **)(iVar14 + 0xd8))(this->_padding_,0,0xffffffff);
      (**(code **)(iVar14 + 0x38))(*(undefined4 *)(this->_padding_ + 0x18));
      iVar14 = this->_padding_;
      *(undefined1 *)((int)&this->_padding_ + 1) = *(undefined1 *)(iVar14 + 0x16e);
      if (*(char *)(iVar14 + 0x16c) != '\0') {
        connect(this);
      }
    }
    else {
      (**(code **)(iVar14 + 0x6c))();
    }
    sVar3 = *(short *)(this->_padding_ + 0x172);
    if (-1 < sVar3) {
      (**(code **)(**(int **)(*(int *)(this->_padding_ + 0x24) + sVar3 * 4) + 0x18))
                (this->_padding_,this->_padding_,this->_padding_,this->_padding_);
    }
    if (-1 < *(short *)(this->_padding_ + 0x174)) {
      uVar12 = *(uchar *)(this->_padding_ + 0x174);
      iVar14 = 0;
      uVar13 = '\x01';
      pRVar1 = *(RGE_Game_World **)(this->_padding_ + 0x3c);
      sVar3 = __ftol();
      sVar4 = __ftol();
      sVar5 = __ftol();
      sVar6 = __ftol();
      RGE_Map::set_terrain
                (pRVar1->map,*pRVar1->players,pRVar1,sVar6,sVar5,sVar4,sVar3,uVar12,uVar13,iVar14);
      uVar12 = '\0';
      sVar3 = __ftol();
      iVar10 = sVar3 + 1;
      sVar3 = __ftol();
      iVar11 = sVar3 + 1;
      sVar3 = __ftol();
      iVar14 = sVar3 + -1;
      sVar3 = __ftol();
      RGE_Map::request_redraw
                (*(RGE_Map **)(*(int *)(this->_padding_ + 0x3c) + 0x28),sVar3 + -1,iVar14,iVar11,
                 iVar10,uVar12);
    }
    sVar3 = *(short *)(this->_padding_ + 0x178);
    if (-1 < sVar3) {
      TRIBE_Player_Tech::do_tech(*(TRIBE_Player_Tech **)(this->_padding_ + 0x220),sVar3);
    }
    iVar14 = rge_base_game->_padding_;
    uVar8 = __ftol();
    uVar8 = __ftol(uVar8);
    (**(code **)(iVar14 + 0x40))
              (0x69,(int)*(short *)(this->_padding_ + 0x4a),(int)*(short *)(this->_padding_ + 0x10),
               uVar8);
    (**(code **)(*(int *)this->_padding_ + 0x104))(this,this->unique_build_id);
  }
  if ((param_1 == '\x03') && ((char)this->_padding_ == '\x02')) {
    (**(code **)(this->_padding_ + 600))();
    RGE_Doppleganger_Creator::remove_doppleganger_check
              (*(RGE_Doppleganger_Creator **)(this->_padding_ + 0x40),(RGE_Static_Object *)this);
    this->DoppleInstalled = 0;
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  RGE_Static_Object::set_object_state((RGE_Static_Object *)this,param_1);
  if (bVar2) {
    pRVar9 = RGE_Object_List::find_by_master_id
                       (*(RGE_Object_List **)(this->_padding_ + 0x28),
                        (int)*(short *)(this->_padding_ + 0x10),-1.0,-1.0,'\x01','\x02',
                        (RGE_Static_Object *)0x0);
    if (pRVar9 == (RGE_Static_Object *)0x0) {
      sVar3 = *(short *)(this->_padding_ + 0x178);
      if (-1 < sVar3) {
        TRIBE_Player_Tech::undo_tech(*(TRIBE_Player_Tech **)(this->_padding_ + 0x220),sVar3);
      }
      TRIBE_Player_Tech::undo_tech(*(TRIBE_Player_Tech **)(this->_padding_ + 0x220),0x4a);
      TRIBE_Player_Tech::undo_tech(*(TRIBE_Player_Tech **)(this->_padding_ + 0x220),0x4b);
      TRIBE_Player_Tech::undo_tech(*(TRIBE_Player_Tech **)(this->_padding_ + 0x220),0x4c);
    }
  }
  return;
}

// --------------------------------------------------

// Function: rehook
// Address: 004c8a60
void __thiscall TRIBE_Building_Object::rehook(TRIBE_Building_Object *this)
{
  RGE_Action_Object::rehook((RGE_Action_Object *)this);
  RGE_Action_List::rehook(this->production_queue_actions);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004c8a80
uchar __thiscall TRIBE_Building_Object::update(TRIBE_Building_Object *this)
{
  short sVar1;
  int iVar2;
  byte bVar3;
  uchar uVar4;
  
  if ((char)this->_padding_ == '\0') {
    iVar2 = this->_padding_;
    sVar1 = *(short *)(this->_padding_ + 0x60);
    bVar3 = __ftol();
    if (((short)(ushort)bVar3 < sVar1) && (bVar3 != *(byte *)((int)&this->_padding_ + 1))) {
      *(byte *)((int)&this->_padding_ + 1) = bVar3;
    }
    if ((float)(int)*(short *)(iVar2 + 0x15a) <= this->build_pts) {
      (**(code **)(this->_padding_ + 0x5c))(2);
    }
  }
  this->PriorMap3 = this->PriorMap2;
  this->PriorMap2 = this->PriorMap1;
  this->PriorTurn3 = this->PriorTurn2;
  this->PriorTurn2 = this->PriorTurn1;
  this->PriorTurn1 = world_update_counter;
  uVar4 = TRIBE_Combat_Object::update((TRIBE_Combat_Object *)this);
  if (2 < (byte)this->_padding_) {
    empty_production_queue(this);
    this->PriorMap1 = this->_padding_;
    return uVar4;
  }
  update_production_queue(this);
  this->PriorMap1 = this->_padding_;
  return uVar4;
}

// --------------------------------------------------

// Function: explore_terrain
// Address: 004c8b80
int __thiscall
TRIBE_Building_Object::explore_terrain
          (TRIBE_Building_Object *this,RGE_Player *param_1,uchar param_2,int param_3)
{
  int iVar1;
  
  if (this->built != '\0') {
    iVar1 = RGE_Static_Object::explore_terrain((RGE_Static_Object *)this,param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = RGE_Static_Object::explore_terrain((RGE_Static_Object *)this,param_1,'\x01',param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: save
// Address: 004c8bc0
void __thiscall TRIBE_Building_Object::save(TRIBE_Building_Object *this,int param_1)
{
  short sVar1;
  short sVar2;
  
  TRIBE_Combat_Object::save((TRIBE_Combat_Object *)this,param_1);
  rge_write(param_1,&this->built,1);
  rge_write(param_1,&this->build_pts,4);
  rge_write(param_1,&this->unique_build_id,4);
  rge_write(param_1,&this->culture,1);
  rge_write(param_1,&this->production_queue_size,2);
  sVar1 = this->production_queue_size;
  if (0 < sVar1) {
    sVar2 = 0;
    if (0 < sVar1) {
      do {
        rge_write(param_1,this->production_queue + sVar2,2);
        rge_write(param_1,&this->production_queue[sVar2].unit_count,2);
        sVar2 = sVar2 + 1;
      } while (sVar2 < this->production_queue_size);
    }
  }
  rge_write(param_1,&this->production_queue_count,2);
  rge_write(param_1,&this->production_queue_enabled,1);
  RGE_Action_List::save(this->production_queue_actions,param_1);
  return;
}

// --------------------------------------------------

// Function: change_ownership
// Address: 004c8cb0
void __thiscall
TRIBE_Building_Object::change_ownership(TRIBE_Building_Object *this,RGE_Player *param_1)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  if ((char)this->_padding_ == '\x02') {
    iVar3 = 0;
    local_4 = 0x6a;
    iVar4 = 0x70;
    do {
      iVar2 = this->_padding_;
      if ((3 < *(byte *)(iVar3 + 0x88 + iVar2)) && (-1 < *(short *)(local_4 + iVar2))) {
        (**(code **)(*(int *)this->_padding_ + 0x78))
                  (*(short *)(local_4 + iVar2),-*(float *)(iVar4 + iVar2),0);
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar3 + 1;
      local_4 = local_4 + 2;
    } while (iVar4 < 0x7c);
  }
  if ((char)this->_padding_ == '\0') {
    (**(code **)(this->_padding_ + 0xdc))(this->_padding_,1,0xffffffff);
  }
  if (0 < this->production_queue_count) {
    if (this->production_queue_need_attr == 4) {
      this->production_queue_need_attr = -1;
      iVar3 = (int)*(short *)(this->_padding_ + 0x4a);
      *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) =
           *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) + -1;
    }
    this->production_queue_count = 1;
    this->production_queue->unit_count = 1;
  }
  RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
  TRIBE_Combat_Object::change_ownership((TRIBE_Combat_Object *)this,param_1);
  if ((char)this->_padding_ == '\0') {
    (**(code **)(this->_padding_ + 0xd8))(this->_padding_,1,0xffffffff);
  }
  if ((char)this->_padding_ == '\x02') {
    sVar1 = *(short *)(this->_padding_ + 0x172);
    if (-1 < sVar1) {
      (**(code **)(**(int **)(*(int *)(this->_padding_ + 0x24) + sVar1 * 4) + 0x18))
                (this->_padding_,this->_padding_,this->_padding_,this->_padding_);
    }
    sVar1 = *(short *)(this->_padding_ + 0x178);
    if (-1 < sVar1) {
      TRIBE_Player_Tech::do_tech(*(TRIBE_Player_Tech **)(this->_padding_ + 0x220),sVar1);
    }
    if ((char)this->_padding_ == '\x02') {
      iVar3 = 0;
      param_1 = (RGE_Player *)0x6a;
      iVar4 = 0x70;
      do {
        iVar2 = this->_padding_;
        if ((3 < *(byte *)(iVar3 + 0x88 + iVar2)) &&
           (sVar1 = *(short *)((int)&param_1->_padding_ + iVar2), -1 < sVar1)) {
          (**(code **)(*(int *)this->_padding_ + 0x78))
                    (CONCAT22((short)((uint)param_1 >> 0x10),sVar1),*(undefined4 *)(iVar4 + iVar2),0
                    );
        }
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
        param_1 = (RGE_Player *)((int)&param_1->_padding_ + 2);
      } while (iVar4 < 0x7c);
    }
  }
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 004c8e60
void __thiscall
TRIBE_Building_Object::modify(TRIBE_Building_Object *this,float param_1,uchar param_2)
{
  undefined1 uVar1;
  
  if (param_2 != '\x11') {
    TRIBE_Combat_Object::modify((TRIBE_Combat_Object *)this,param_1,param_2);
    return;
  }
  uVar1 = __ftol();
  *(undefined1 *)((int)&this->_padding_ + 1) = uVar1;
  return;
}

// --------------------------------------------------

// Function: transform
// Address: 004c8e90
void __thiscall
TRIBE_Building_Object::transform(TRIBE_Building_Object *this,TRIBE_Master_Building_Object *param_1)
{
  TRIBE_Combat_Object::transform((TRIBE_Combat_Object *)this,(RGE_Master_Static_Object *)param_1);
  *(undefined1 *)&this->_padding_ = 0;
  if (0 < *(short *)(this->_padding_ + 0x15a)) {
    (**(code **)(this->_padding_ + 0x38))(param_1->construction_sprite);
  }
  this->build_pts = 0.0;
  return;
}

// --------------------------------------------------

// Function: check
// Address: 004c8ed0
long __thiscall
TRIBE_Building_Object::check(TRIBE_Building_Object *this,TRIBE_Building_Object **param_1)
{
  short sVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  TRIBE_Building_Object *pTVar6;
  long counter;
  short x;
  short w;
  short h;
  
  iVar3 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
  sVar4 = __ftol();
  sVar5 = __ftol();
  sVar1 = *(short *)(iVar3 + 8);
  _x = 0;
  sVar2 = *(short *)(iVar3 + 0xc);
  if (sVar5 < 1) {
LAB_004c8f71:
    *param_1 = (TRIBE_Building_Object *)0x0;
  }
  else {
    pTVar6 = (TRIBE_Building_Object *)
             RGE_Object_List::find_by_master_id
                       ((RGE_Object_List *)
                        (*(int *)(*(int *)(iVar3 + 0x8d8c) + -4 + sVar5 * 4) + 0xc + sVar4 * 0x18),
                        (int)*(short *)(this->_padding_ + 0x10),-1.0,-1.0,'\0','\0',
                        (RGE_Static_Object *)0x0);
    *param_1 = pTVar6;
    if (pTVar6 != (TRIBE_Building_Object *)0x0) {
      if ((RGE_Player *)pTVar6->_padding_ != (RGE_Player *)this->_padding_) goto LAB_004c8f71;
      _x = 1;
    }
  }
  if (sVar4 < 1) {
LAB_004c8fca:
    param_1[1] = (TRIBE_Building_Object *)0x0;
  }
  else {
    pTVar6 = (TRIBE_Building_Object *)
             RGE_Object_List::find_by_master_id
                       ((RGE_Object_List *)
                        (*(int *)(*(int *)(iVar3 + 0x8d8c) + sVar5 * 4) + -0xc + sVar4 * 0x18),
                        (int)*(short *)(this->_padding_ + 0x10),-1.0,-1.0,'\0','\0',
                        (RGE_Static_Object *)0x0);
    param_1[1] = pTVar6;
    if (pTVar6 != (TRIBE_Building_Object *)0x0) {
      if ((RGE_Player *)pTVar6->_padding_ != (RGE_Player *)this->_padding_) goto LAB_004c8fca;
      _x = _x + 1;
    }
  }
  if (sVar4 < (short)(sVar1 + -1)) {
    pTVar6 = (TRIBE_Building_Object *)
             RGE_Object_List::find_by_master_id
                       ((RGE_Object_List *)
                        (*(int *)(*(int *)(iVar3 + 0x8d8c) + sVar5 * 4) + 0x24 + sVar4 * 0x18),
                        (int)*(short *)(this->_padding_ + 0x10),-1.0,-1.0,'\0','\0',
                        (RGE_Static_Object *)0x0);
    param_1[2] = pTVar6;
    if (pTVar6 == (TRIBE_Building_Object *)0x0) goto LAB_004c902d;
    if ((RGE_Player *)pTVar6->_padding_ == (RGE_Player *)this->_padding_) {
      _x = _x + 1;
      goto LAB_004c902d;
    }
  }
  param_1[2] = (TRIBE_Building_Object *)0x0;
LAB_004c902d:
  if (sVar5 < (short)(sVar2 + -1)) {
    pTVar6 = (TRIBE_Building_Object *)
             RGE_Object_List::find_by_master_id
                       ((RGE_Object_List *)
                        (*(int *)(*(int *)(iVar3 + 0x8d8c) + 4 + sVar5 * 4) + 0xc + sVar4 * 0x18),
                        (int)*(short *)(this->_padding_ + 0x10),-1.0,-1.0,'\0','\0',
                        (RGE_Static_Object *)0x0);
    param_1[3] = pTVar6;
    if (pTVar6 == (TRIBE_Building_Object *)0x0) {
      return _x;
    }
    if ((RGE_Player *)pTVar6->_padding_ == (RGE_Player *)this->_padding_) {
      return _x + 1;
    }
  }
  param_1[3] = (TRIBE_Building_Object *)0x0;
  return _x;
}

// --------------------------------------------------

// Function: connect
// Address: 004c90b0
void __thiscall TRIBE_Building_Object::connect(TRIBE_Building_Object *this)
{
  byte bVar1;
  int iVar2;
  TRIBE_Building_Object *checks [4];
  TRIBE_Building_Object *local_4;
  
  if (this->_padding_ == 0) {
    return;
  }
  if (*(short *)(this->_padding_ + 0x60) != 3) {
    *(undefined1 *)((int)&this->_padding_ + 1) = 0;
    return;
  }
  RGE_Moving_Object::set_angle((RGE_Moving_Object *)this);
  check(this,checks + 1);
  if ((checks[1] == (TRIBE_Building_Object *)0x0) || (local_4 == (TRIBE_Building_Object *)0x0)) {
LAB_004c9108:
    if (checks[2] != (TRIBE_Building_Object *)0x0) {
LAB_004c910c:
      if (((checks[3] != (TRIBE_Building_Object *)0x0) &&
          (checks[1] == (TRIBE_Building_Object *)0x0)) && (local_4 == (TRIBE_Building_Object *)0x0))
{
        iVar2 = -(uint)*(byte *)((int)&this->_padding_ + 1);
        goto LAB_004c912d;
      }
    }
    iVar2 = 2;
    bVar1 = *(byte *)((int)&this->_padding_ + 1);
  }
  else {
    if (checks[2] != (TRIBE_Building_Object *)0x0) goto LAB_004c910c;
    if (checks[3] != (TRIBE_Building_Object *)0x0) goto LAB_004c9108;
    bVar1 = *(byte *)((int)&this->_padding_ + 1);
    iVar2 = 1;
  }
  iVar2 = iVar2 - (uint)bVar1;
LAB_004c912d:
  RGE_Moving_Object::rotate((RGE_Moving_Object *)this,iVar2);
  if (checks[1] != (TRIBE_Building_Object *)0x0) {
    connect2(checks[1]);
  }
  if (checks[2] != (TRIBE_Building_Object *)0x0) {
    connect2(checks[2]);
  }
  if (checks[3] != (TRIBE_Building_Object *)0x0) {
    connect2(checks[3]);
  }
  if (local_4 == (TRIBE_Building_Object *)0x0) {
    return;
  }
  connect2(local_4);
  return;
}

// --------------------------------------------------

// Function: connect2
// Address: 004c9180
void __thiscall TRIBE_Building_Object::connect2(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *checks [4];
  int local_4;
  
  if (this->_padding_ == 0) {
    return;
  }
  if (*(short *)(this->_padding_ + 0x60) != 3) {
    *(undefined1 *)((int)&this->_padding_ + 1) = 0;
    return;
  }
  check(this,checks + 1);
  if ((checks[1] == (TRIBE_Building_Object *)0x0) || (local_4 == 0)) {
LAB_004c91db:
    if (checks[2] == (TRIBE_Building_Object *)0x0) goto LAB_004c91fe;
  }
  else if (checks[2] == (TRIBE_Building_Object *)0x0) {
    if (checks[3] == (TRIBE_Building_Object *)0x0) {
      RGE_Moving_Object::rotate
                ((RGE_Moving_Object *)this,1 - (uint)*(byte *)((int)&this->_padding_ + 1));
      return;
    }
    goto LAB_004c91db;
  }
  if (((checks[3] != (TRIBE_Building_Object *)0x0) && (checks[1] == (TRIBE_Building_Object *)0x0))
     && (local_4 == 0)) {
    RGE_Moving_Object::rotate((RGE_Moving_Object *)this,-(uint)*(byte *)((int)&this->_padding_ + 1))
    ;
    return;
  }
LAB_004c91fe:
  RGE_Moving_Object::rotate
            ((RGE_Moving_Object *)this,2 - (uint)*(byte *)((int)&this->_padding_ + 1));
  return;
}

// --------------------------------------------------

// Function: lay_down_impassable_terrain
// Address: 004c9230
void __thiscall TRIBE_Building_Object::lay_down_impassable_terrain(TRIBE_Building_Object *this)
{
  int iVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short tx2;
  short tx1;
  RGE_Map *map;
  
  iVar1 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
  if (0x7fff < *(ushort *)(this->_padding_ + 0x174)) {
    map._0_2_ = __ftol();
    tx1 = __ftol();
    sVar3 = __ftol();
    sVar4 = __ftol();
    if ((short)map < 0) {
      map._0_2_ = 0;
    }
    if (sVar3 < 0) {
      sVar3 = 0;
    }
    if (*(int *)(iVar1 + 8) <= (int)tx1) {
      tx1 = *(short *)(iVar1 + 8) + -1;
    }
    if (*(int *)(iVar1 + 0xc) <= (int)sVar4) {
      sVar4 = *(short *)(iVar1 + 0xc) + -1;
    }
    if (sVar3 <= sVar4) {
      iVar7 = sVar3 * 4;
      iVar6 = ((int)sVar4 - (int)sVar3) + 1;
      do {
        if ((short)map <= tx1) {
          iVar8 = (short)map * 0x18;
          iVar9 = ((int)tx1 - (int)(short)map) + 1;
          do {
            iVar5 = *(int *)(iVar7 + *(int *)(iVar1 + 0x8d8c)) + iVar8;
            bVar2 = *(byte *)(iVar5 + 5);
            if ((bVar2 & 0x1f) == 0) {
              bVar2 = bVar2 & 0xf0 | 0x10;
LAB_004c933d:
              *(byte *)(iVar5 + 5) = bVar2;
            }
            else {
              if ((bVar2 & 0x1f) == 1) {
                bVar2 = bVar2 & 0xef | 0xf;
                goto LAB_004c933d;
              }
              if ((bVar2 & 0x1f) == 6) {
                bVar2 = bVar2 & 0xee | 0xe;
                goto LAB_004c933d;
              }
            }
            iVar8 = iVar8 + 0x18;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        iVar7 = iVar7 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: lay_down_passable_terrain
// Address: 004c9360
void __thiscall TRIBE_Building_Object::lay_down_passable_terrain(TRIBE_Building_Object *this)
{
  int iVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short tx2;
  short tx1;
  RGE_Map *map;
  
  iVar1 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
  if (0x7fff < *(ushort *)(this->_padding_ + 0x174)) {
    map._0_2_ = __ftol();
    tx1 = __ftol();
    sVar3 = __ftol();
    sVar4 = __ftol();
    if ((short)map < 0) {
      map._0_2_ = 0;
    }
    if (sVar3 < 0) {
      sVar3 = 0;
    }
    if (*(int *)(iVar1 + 8) <= (int)tx1) {
      tx1 = *(short *)(iVar1 + 8) + -1;
    }
    if (*(int *)(iVar1 + 0xc) <= (int)sVar4) {
      sVar4 = *(short *)(iVar1 + 0xc) + -1;
    }
    if (sVar3 <= sVar4) {
      iVar8 = sVar3 * 4;
      iVar7 = ((int)sVar4 - (int)sVar3) + 1;
      do {
        if ((short)map <= tx1) {
          iVar9 = (short)map * 0x18;
          iVar10 = ((int)tx1 - (int)(short)map) + 1;
          do {
            iVar5 = *(int *)(iVar8 + *(int *)(iVar1 + 0x8d8c)) + iVar9;
            bVar2 = *(byte *)(iVar5 + 5);
            bVar6 = bVar2 & 0x1f;
            if (bVar6 == 0xe) {
              bVar2 = bVar2 & 0xe6 | 6;
LAB_004c9469:
              *(byte *)(iVar5 + 5) = bVar2;
            }
            else {
              if (bVar6 == 0xf) {
                bVar2 = bVar2 & 0xe1 | 1;
                goto LAB_004c9469;
              }
              if (bVar6 == 0x10) {
                bVar2 = bVar2 & 0xe0;
                goto LAB_004c9469;
              }
            }
            iVar9 = iVar9 + 0x18;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        iVar8 = iVar8 + 4;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: cancel_object
// Address: 004c9480
void __thiscall TRIBE_Building_Object::cancel_object(TRIBE_Building_Object *this)
{
  if ((byte)this->_padding_ < 2) {
    cancel_build(this);
    return;
  }
  TRIBE_Combat_Object::cancel_object((TRIBE_Combat_Object *)this);
  return;
}

// --------------------------------------------------

// Function: cancel_build
// Address: 004c9490
void __thiscall TRIBE_Building_Object::cancel_build(TRIBE_Building_Object *this)
{
  short sVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float percent;
  float local_8;
  
  if ((this->_padding_ & 0x10000) != 0) {
    RGE_Player::unselect_one_object((RGE_Player *)this->_padding_,(RGE_Static_Object *)this);
  }
  if ((1 < (byte)this->_padding_) || ((float)this->_padding_ <= _DAT_005749f4)) {
    local_8 = 0.0;
  }
  else {
    fVar3 = (float)(int)*(short *)(this->_padding_ + 0x15a);
    local_8 = ((fVar3 - this->build_pts) / fVar3) * (float)_DAT_005749f8;
  }
  if ((float)_DAT_00574a00 < local_8) {
    local_8 = 1.0;
  }
  iVar4 = 0;
  do {
    iVar2 = this->_padding_;
    sVar1 = *(short *)(iVar4 + 0x148 + iVar2);
    if ((-1 < sVar1) && (*(char *)(iVar4 + 0x14c + iVar2) != '\0')) {
      (**(code **)(*(int *)this->_padding_ + 0x78))
                (sVar1,(float)(int)*(short *)(iVar4 + 0x14a + iVar2) * local_8,0);
    }
    iVar4 = iVar4 + 6;
  } while (iVar4 < 0x12);
  this->_padding_ = 0;
  return;
}

// --------------------------------------------------

// Function: build
// Address: 004c9560
uchar __thiscall TRIBE_Building_Object::build(TRIBE_Building_Object *this,float param_1)
{
  int iVar1;
  float fVar2;
  
  if ((char)this->_padding_ != '\0') {
    return '\x01';
  }
  iVar1 = this->_padding_;
  fVar2 = (float)(int)*(short *)(iVar1 + 0x15a);
  if (fVar2 < param_1 + this->build_pts) {
    param_1 = fVar2 - this->build_pts;
  }
  fVar2 = ((float)(int)*(short *)(iVar1 + 0x26) * param_1) / fVar2 + (float)this->_padding_;
  this->_padding_ = (int)fVar2;
  if ((float)(int)*(short *)(iVar1 + 0x26) < fVar2) {
    this->_padding_ = (int)(float)(int)*(short *)(iVar1 + 0x26);
  }
  fVar2 = param_1 + this->build_pts;
  this->build_pts = fVar2;
  if (fVar2 < (float)(int)*(short *)(iVar1 + 0x15a)) {
    return '\0';
  }
  (**(code **)(this->_padding_ + 0x5c))(2);
  return '\x01';
}

// --------------------------------------------------

// Function: work_status
// Address: 004c9620
int __thiscall
TRIBE_Building_Object::work_status
          (TRIBE_Building_Object *this,short *param_1,short *param_2,short *param_3,char *param_4,
          short param_5)
{
  TRIBE_Action_Make_Obj *this_00;
  
  this_00 = (TRIBE_Action_Make_Obj *)RGE_Action_List::get_action((RGE_Action_List *)this->_padding_)
  ;
  if (this_00 == (TRIBE_Action_Make_Obj *)0x0) {
    *param_1 = 0;
  }
  else {
    *param_1 = (short)this_00->_padding_;
  }
  if (*param_1 != 0x66) {
    if (*param_1 != 0x67) {
      *param_2 = -1;
      *param_3 = 0;
      if (param_4 != (char *)0x0) {
        *param_4 = '\0';
      }
      return 0;
    }
    TRIBE_Action_Make_Tech::get_info
              ((TRIBE_Action_Make_Tech *)this_00,param_2,param_3,param_4,param_5);
    return 1;
  }
  TRIBE_Action_Make_Obj::get_info(this_00,param_2,param_3,param_4,param_5);
  return 1;
}

// --------------------------------------------------

// Function: get_construction_progress
// Address: 004c96c0
short __thiscall TRIBE_Building_Object::get_construction_progress(TRIBE_Building_Object *this)
{
  short sVar1;
  
  if ((char)this->_padding_ != '\0') {
    return 100;
  }
  sVar1 = *(short *)(this->_padding_ + 0x15a);
  if (sVar1 == 0) {
    return 100;
  }
  sVar1 = __ftol((int)sVar1);
  return sVar1;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 004c9710
void __thiscall
TRIBE_Building_Object::copy_obj(TRIBE_Building_Object *this,RGE_Master_Static_Object *param_1)
{
  if (this->_padding_ == *(int *)(this->_padding_ + 0x168)) {
    (**(code **)(this->_padding_ + 0x38))(param_1[1].outline_radius_y);
  }
  RGE_Combat_Object::copy_obj((RGE_Combat_Object *)this,param_1);
  if (*(char *)(this->_padding_ + 0x16c) != '\0') {
    connect(this);
  }
  return;
}

// --------------------------------------------------

// Function: rotate
// Address: 004c9760
void __thiscall TRIBE_Building_Object::rotate(TRIBE_Building_Object *this,long param_1)
{
  return;
}

// --------------------------------------------------

// Function: damage
// Address: 004c9770
void __thiscall
TRIBE_Building_Object::damage
          (TRIBE_Building_Object *this,int param_1,RGE_Armor_Weapon_Info *param_2,float param_3,
          RGE_Player *param_4,RGE_Static_Object *param_5)
{
  short sVar1;
  float fVar2;
  float fVar3;
  float temp_hp;
  
  fVar2 = (float)this->_padding_;
  if ((float)this->_padding_ <= _DAT_005749f4) {
    return;
  }
  RGE_Combat_Object::damage((RGE_Combat_Object *)this,param_1,param_2,param_3,param_4,param_5);
  sVar1 = param_5->master_obj->object_group;
  if ((((((sVar1 == 0) || (sVar1 == 0x17)) || (sVar1 == 0x24)) ||
       ((sVar1 == 0x1a || (sVar1 = param_5->master_obj->id, sVar1 == 0x4f)))) ||
      ((sVar1 == 0x45 || ((sVar1 == 199 || (sVar1 == 0x17f)))))) || (sVar1 == 0x17c)) {
    fVar3 = _DAT_00574a18;
    if ((float)_DAT_00574a10 <= fVar2 - (float)this->_padding_) goto LAB_004c9835;
  }
  else {
    fVar3 = _DAT_00574a08;
    if ((float)_DAT_00574a00 <= fVar2 - (float)this->_padding_) goto LAB_004c9835;
  }
  this->_padding_ = (int)(fVar2 - fVar3);
LAB_004c9835:
  if ((0 < *(short *)(this->_padding_ + 0x4a)) && ((float)this->_padding_ < (float)_DAT_00574a00)) {
    (**(code **)(param_4->_padding_ + 0x78))(0x2b,0x3f800000,0);
  }
  return;
}

// --------------------------------------------------

// Function: add_to_production_queue
// Address: 004c9870
void __thiscall
TRIBE_Building_Object::add_to_production_queue
          (TRIBE_Building_Object *this,short param_1,short param_2)
{
  short *psVar1;
  bool bVar2;
  short sVar3;
  uchar uVar4;
  Production_Queue_Record *pPVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  undefined2 in_stack_00000006;
  uchar queue_changed;
  
  sVar3 = param_1;
  sVar6 = this->production_queue_count;
  bVar2 = false;
  if ((sVar6 < 1) || (this->production_queue[sVar6 + -1].master_id != param_1)) {
    while (0 < sVar6) {
      remove_from_production_queue(this,this->production_queue->master_id,1);
      sVar6 = this->production_queue_count;
    }
    uVar4 = TRIBE_Player::check_obj_cost((TRIBE_Player *)this->_padding_,sVar3,&param_1,1.0,1);
    if (uVar4 == '\0') {
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x7d,(int)*(short *)(this->_padding_ + 0x4a),(int)param_1,0,0);
      return;
    }
    if (this->production_queue_count == this->production_queue_size) {
      pPVar5 = (Production_Queue_Record *)calloc(this->production_queue_size + 10,4);
      if (pPVar5 == (Production_Queue_Record *)0x0) {
        return;
      }
      if (this->production_queue != (Production_Queue_Record *)0x0) {
        sVar6 = 0;
        if (0 < this->production_queue_size) {
          do {
            sVar7 = sVar6 + 1;
            pPVar5[sVar6].master_id = this->production_queue[sVar6].master_id;
            pPVar5[sVar6].unit_count = this->production_queue[sVar6].unit_count;
            sVar6 = sVar7;
          } while (sVar7 < this->production_queue_size);
        }
        free(this->production_queue);
      }
      this->production_queue_size = this->production_queue_size + 10;
      this->production_queue = pPVar5;
    }
    iVar9 = (int)param_2;
    iVar8 = 0;
    this->production_queue[this->production_queue_count].unit_count = 0;
    if (0 < iVar9) {
      do {
        uVar4 = TRIBE_Player::check_obj_cost((TRIBE_Player *)this->_padding_,sVar3,&param_1,1.0,1);
        if (uVar4 == '\0') {
          (**(code **)(rge_base_game->_padding_ + 0x40))
                    (0x7d,(int)*(short *)(this->_padding_ + 0x4a),(int)param_1,0,0);
          break;
        }
        TRIBE_Player::pay_obj_cost((TRIBE_Player *)this->_padding_,sVar3,1.0,1);
        psVar1 = &this->production_queue[this->production_queue_count].unit_count;
        *psVar1 = *psVar1 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar9);
    }
    this->production_queue[this->production_queue_count].master_id = sVar3;
    this->production_queue_count = this->production_queue_count + 1;
    this->production_queue_change_flag = this->production_queue_change_flag + '\x01';
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (0x7c,(int)*(short *)(this->_padding_ + 0x4a),0,0,0);
  }
  else {
    iVar8 = (int)param_2;
    iVar9 = 0;
    if (0 < iVar8) {
      do {
        uVar4 = TRIBE_Player::check_obj_cost((TRIBE_Player *)this->_padding_,sVar3,&param_1,1.0,1);
        if (uVar4 == '\0') {
          (**(code **)(rge_base_game->_padding_ + 0x40))
                    (0x7d,(int)*(short *)(this->_padding_ + 0x4a),(int)param_1,0,0);
          break;
        }
        TRIBE_Player::pay_obj_cost((TRIBE_Player *)this->_padding_,sVar3,1.0,1);
        psVar1 = &this->production_queue[this->production_queue_count + -1].unit_count;
        *psVar1 = *psVar1 + 1;
        iVar9 = iVar9 + 1;
        bVar2 = true;
      } while (iVar9 < iVar8);
    }
    if (bVar2) {
      this->production_queue_change_flag = this->production_queue_change_flag + '\x01';
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x7c,(int)*(short *)(this->_padding_ + 0x4a),0,0,0);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: remove_from_production_queue
// Address: 004c9b10
void __thiscall
TRIBE_Building_Object::remove_from_production_queue
          (TRIBE_Building_Object *this,short param_1,short param_2)
{
  short *psVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  
  if (this->production_queue_count != 0) {
    sVar4 = this->production_queue_count + -1;
    if (-1 < sVar4) {
LAB_004c9b36:
      if (this->production_queue[sVar4].master_id != param_1) goto code_r0x004c9b44;
      sVar2 = this->production_queue[sVar4].unit_count;
      sVar3 = param_2;
      if (sVar2 <= param_2) {
        sVar3 = sVar2;
      }
      iVar5 = (int)sVar3;
      if (0 < iVar5) {
        do {
          TRIBE_Player::reimburse_obj_cost((TRIBE_Player *)this->_padding_,param_1);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      psVar1 = &this->production_queue[sVar4].unit_count;
      *psVar1 = *psVar1 - param_2;
      this->production_queue_change_flag = this->production_queue_change_flag + '\x01';
      if (this->production_queue[sVar4].unit_count < 1) {
        this->production_queue_count = this->production_queue_count + -1;
        sVar2 = sVar4;
        if (sVar4 < this->production_queue_count) {
          do {
            sVar3 = sVar2 + 1;
            this->production_queue[sVar2].master_id = this->production_queue[sVar2 + 1].master_id;
            this->production_queue[sVar2].unit_count = this->production_queue[sVar2 + 1].unit_count;
            sVar2 = sVar3;
          } while (sVar3 < this->production_queue_count);
        }
        if (sVar4 == 0) {
          if (this->production_queue_need_attr != -1) {
            if (this->production_queue_need_attr == 4) {
              iVar5 = (int)*(short *)(this->_padding_ + 0x4a);
              *(int *)(rge_base_game[1].save_music_file + iVar5 * 4 + -0x70) =
                   *(int *)(rge_base_game[1].save_music_file + iVar5 * 4 + -0x70) + -1;
            }
            this->production_queue_need_attr = -1;
          }
          RGE_Action_List::action_stop(this->production_queue_actions);
          RGE_Action_List::delete_list(this->production_queue_actions);
        }
      }
    }
LAB_004c9c51:
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (0x7c,(int)*(short *)(this->_padding_ + 0x4a),0,0,0);
  }
  return;
code_r0x004c9b44:
  sVar4 = sVar4 + -1;
  if (sVar4 < 0) goto LAB_004c9c51;
  goto LAB_004c9b36;
}

// --------------------------------------------------

// Function: advance_production_queue
// Address: 004c9c80
void __thiscall TRIBE_Building_Object::advance_production_queue(TRIBE_Building_Object *this)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  
  if (this->production_queue_count != 0) {
    psVar1 = &this->production_queue->unit_count;
    *psVar1 = *psVar1 + -1;
    this->production_queue_change_flag = this->production_queue_change_flag + '\x01';
    if (this->production_queue->unit_count < 1) {
      this->production_queue_count = this->production_queue_count + -1;
      iVar2 = 0;
      if (0 < this->production_queue_count) {
        do {
          this->production_queue[iVar2].master_id = this->production_queue[iVar2 + 1].master_id;
          iVar3 = iVar2 + 1;
          this->production_queue[iVar2].unit_count = this->production_queue[iVar2 + 1].unit_count;
          iVar2 = iVar3;
        } while (iVar3 < this->production_queue_count);
      }
    }
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (0x7c,(int)*(short *)(this->_padding_ + 0x4a),0,0,0);
  }
  return;
}

// --------------------------------------------------

// Function: empty_production_queue
// Address: 004c9d20
void __thiscall TRIBE_Building_Object::empty_production_queue(TRIBE_Building_Object *this)
{
  int iVar1;
  
  if (this->production_queue_need_attr != -1) {
    if (this->production_queue_need_attr == 4) {
      iVar1 = (int)*(short *)(this->_padding_ + 0x4a);
      *(int *)(rge_base_game[1].save_music_file + iVar1 * 4 + -0x70) =
           *(int *)(rge_base_game[1].save_music_file + iVar1 * 4 + -0x70) + -1;
    }
    this->production_queue_need_attr = -1;
  }
  this->production_queue_count = 0;
  RGE_Action_List::delete_list(this->production_queue_actions);
  this->production_queue_change_flag = this->production_queue_change_flag + '\x01';
  return;
}

// --------------------------------------------------

// Function: enable_production_queue
// Address: 004c9d90
void __thiscall
TRIBE_Building_Object::enable_production_queue(TRIBE_Building_Object *this,int param_1)
{
  this->production_queue_enabled = (uchar)param_1;
  return;
}

// --------------------------------------------------

// Function: update_production_queue
// Address: 004c9da0
void __thiscall TRIBE_Building_Object::update_production_queue(TRIBE_Building_Object *this)
{
  int iVar1;
  char cVar2;
  int iVar3;
  RGE_Action *pRVar4;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  short work_type;
  short progress;
  short work_target;
  short local_14;
  short local_12;
  TRIBE_Action_Make_Obj *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fafb;
  *unaff_FS_OFFSET = &local_c;
  if ((this->production_queue_enabled == '\0') || (this->production_queue_count == 0)) {
    if (this->production_queue_need_attr == 4) {
      this->production_queue_need_attr = -1;
      iVar3 = (int)*(short *)(this->_padding_ + 0x4a);
      *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) =
           *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) + -1;
    }
  }
  else {
    iVar3 = work_status(this,&work_target,&local_12,&local_14,(char *)0x0,0);
    if ((iVar3 == 0) || ((work_target != 0x66 && (work_target != 0x67)))) {
      if (this->production_queue_actions->list == (RGE_Action_Node *)0x0) {
        iVar3 = this->_padding_;
        iVar1 = *(int *)(iVar3 + 0x50);
        if (*(float *)(iVar1 + 0x80) <= *(float *)(iVar1 + 0x2c)) {
          if (this->production_queue_need_attr != 0x20) {
            this->production_queue_need_attr = 0x20;
            (**(code **)(rge_base_game->_padding_ + 0x40))
                      (0x7d,(int)*(short *)(iVar3 + 0x4a),0x20,0,0);
            iVar3 = (int)*(short *)(this->_padding_ + 0x4a);
            *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) =
                 *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) + 1;
            *unaff_FS_OFFSET = unaff_EDI;
            return;
          }
          goto LAB_004c9fc1;
        }
        if (*(float *)(iVar1 + 0x10) <= _DAT_005749f4) {
          if (this->production_queue_need_attr != 4) {
            this->production_queue_need_attr = 4;
            (**(code **)(rge_base_game->_padding_ + 0x40))(0x7d,(int)*(short *)(iVar3 + 0x4a),4,0,0)
            ;
            iVar3 = (int)*(short *)(this->_padding_ + 0x4a);
            *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) =
                 *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) + 1;
            *unaff_FS_OFFSET = unaff_EDI;
            return;
          }
          goto LAB_004c9fc1;
        }
        if (this->production_queue_need_attr == 4) {
          *(int *)(rge_base_game[1].save_music_file + *(short *)(iVar3 + 0x4a) * 4 + -0x70) =
               *(int *)(rge_base_game[1].save_music_file + *(short *)(iVar3 + 0x4a) * 4 + -0x70) +
               -1;
        }
        this->production_queue_need_attr = -1;
        local_10 = (TRIBE_Action_Make_Obj *)operator_new(0x50);
        local_4 = 0;
        if (local_10 == (TRIBE_Action_Make_Obj *)0x0) {
          pRVar4 = (RGE_Action *)0x0;
        }
        else {
          pRVar4 = (RGE_Action *)
                   TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj
                             (local_10,(RGE_Action_Object *)this,this->production_queue->master_id,
                              -1,'\x01');
        }
        local_4 = 0xffffffff;
        if (pRVar4 != (RGE_Action *)0x0) {
          RGE_Action_List::add_action(this->production_queue_actions,pRVar4);
        }
      }
      cVar2 = (**(code **)(this->production_queue_actions->_padding_ + 0xc))();
      if (((cVar2 == '\x03') || (cVar2 == '\x02')) || (cVar2 == '\x01')) {
        RGE_Action_List::remove_action(this->production_queue_actions);
        advance_production_queue(this);
        *unaff_FS_OFFSET = local_c;
        return;
      }
    }
    else if (0 < this->production_queue_count) {
      do {
        remove_from_production_queue(this,this->production_queue->master_id,-1);
      } while (0 < this->production_queue_count);
      *unaff_FS_OFFSET = local_c;
      return;
    }
  }
LAB_004c9fc1:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: production_queue_status
// Address: 004ca030
int __thiscall
TRIBE_Building_Object::production_queue_status
          (TRIBE_Building_Object *this,short *param_1,short *param_2)
{
  TRIBE_Action_Make_Obj *this_00;
  
  *param_1 = -1;
  *param_2 = 0;
  this_00 = (TRIBE_Action_Make_Obj *)RGE_Action_List::get_action(this->production_queue_actions);
  if ((this_00 != (TRIBE_Action_Make_Obj *)0x0) && ((short)this_00->_padding_ == 0x66)) {
    TRIBE_Action_Make_Obj::get_info(this_00,param_1,param_2,(char *)0x0,0);
    return 1;
  }
  if (0 < this->production_queue_count) {
    *param_1 = this->production_queue->master_id;
    *param_2 = 0;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: stop
// Address: 004ca0b0
void __thiscall TRIBE_Building_Object::stop(TRIBE_Building_Object *this)
{
  short sVar1;
  
  RGE_Combat_Object::stop((RGE_Combat_Object *)this);
  sVar1 = this->production_queue_count;
  while (0 < sVar1) {
    remove_from_production_queue(this,this->production_queue->master_id,1);
    sVar1 = this->production_queue_count;
  }
  return;
}

// --------------------------------------------------

