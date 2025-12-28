// Class: RGE_Missile_Object
// Size:  0x1C8
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
//
// Member Layout:
// [0x1C4] float max_range
// ----------------------------------------------------------------

// Function: RGE_Missile_Object
// Address: 0045a740
RGE_Missile_Object * __thiscall
RGE_Missile_Object::RGE_Missile_Object
          (RGE_Missile_Object *this,RGE_Master_Combat_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055db68;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Combat_Object::RGE_Combat_Object
            ((RGE_Combat_Object *)this,param_1,param_2,param_3,param_4,param_5,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x3c;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0045a7d0
void * __thiscall
RGE_Missile_Object::_scalar_deleting_destructor_(RGE_Missile_Object *this,uint param_1)
{
  ~RGE_Missile_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Missile_Object
// Address: 0045a7f0
void __thiscall RGE_Missile_Object::~RGE_Missile_Object(RGE_Missile_Object *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  ulong uVar5;
  ulong uVar6;
  int *piVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055cd98;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&RGE_Combat_Object::_vftable_;
  iVar1 = this->_padding_;
  uStack_4 = 0;
  if (-1 < iVar1) {
    uVar5 = this->_padding_;
    piVar7 = &this->_padding_;
    uVar6 = 0;
    iVar2 = (int)*(short *)(this->_padding_ + 0x14);
    iVar3 = __ftol();
    iVar4 = __ftol();
    Visible_Unit_Manager::Update_Unit_Info
              (VisibleUnitManager,iVar1,(int)*(short *)(this->_padding_ + 0x4a),iVar4,iVar3,iVar2,
               uVar5,uVar6,(VISIBLE_UNIT_REC **)piVar7);
  }
  uStack_4 = 0xffffffff;
  RGE_Action_Object::~RGE_Action_Object((RGE_Action_Object *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: RGE_Missile_Object
// Address: 0045a800
RGE_Missile_Object * __thiscall
RGE_Missile_Object::RGE_Missile_Object
          (RGE_Missile_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055db88;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Combat_Object::RGE_Combat_Object((RGE_Combat_Object *)this,param_1,param_2,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x3c;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 0045a870
int __thiscall
RGE_Missile_Object::setup
          (RGE_Missile_Object *this,RGE_Master_Combat_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  RGE_Combat_Object::setup((RGE_Combat_Object *)this,param_1,param_2,param_3,param_4,param_5);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x3c;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0045a8a0
int __thiscall
RGE_Missile_Object::setup(RGE_Missile_Object *this,int param_1,RGE_Game_World *param_2)
{
  RGE_Combat_Object::setup((RGE_Combat_Object *)this,param_1,param_2);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x3c;
  if (_DAT_00570930 < save_game_version) {
    rge_read(param_1,&this->max_range,4);
    return 1;
  }
  this->max_range = *(float *)(this->_padding_ + 0x114);
  return 1;
}

// --------------------------------------------------

// Function: rehook
// Address: 0045a900
void __thiscall RGE_Missile_Object::rehook(RGE_Missile_Object *this)
{
  RGE_Static_Object::rehook((RGE_Static_Object *)this);
  RGE_Action_List::rehook((RGE_Action_List *)this->_padding_);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0045a910
void __thiscall RGE_Missile_Object::save(RGE_Missile_Object *this,int param_1)
{
  RGE_Combat_Object::save((RGE_Combat_Object *)this,param_1);
  rge_write(param_1,&this->max_range,4);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 0045a940
uchar __thiscall RGE_Missile_Object::update(RGE_Missile_Object *this)
{
  ulong *puVar1;
  ulong *puVar2;
  bool bVar3;
  float fVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  
  if ((_DAT_0056f4a8 < (float)this->_padding_) &&
     (fVar4 = (float)this->_padding_ - *(float *)(*(int *)(this->_padding_ + 0x3c) + 0x84),
     bVar3 = fVar4 < _DAT_0056f4a8, this->_padding_ = (int)fVar4, bVar3)) {
    this->_padding_ = 0;
  }
  uVar5 = RGE_Action_Object::update((RGE_Action_Object *)this);
  iVar8 = this->_padding_;
  if ((-1 < iVar8) && (this->_padding_ == 0)) {
    iVar6 = __ftol();
    iVar7 = __ftol();
    puVar1 = (ulong *)this->_padding_;
    puVar2 = (&unified_map_offsets)[iVar7][iVar6];
    this->_padding_ = (int)puVar2;
    if (puVar2 != puVar1) {
      Visible_Unit_Manager::Update_Unit_Info
                (VisibleUnitManager,iVar8,(int)*(short *)(this->_padding_ + 0x4a),iVar6,iVar7,
                 (int)*(short *)(this->_padding_ + 0x14),(ulong)puVar1,(ulong)puVar2,
                 (VISIBLE_UNIT_REC **)&this->_padding_);
      if ((char)this->_padding_ != '\0') {
        iVar6 = 1;
        iVar8 = *(int *)(this->_padding_ + 0x3c);
        iVar7 = (int)*(short *)(iVar8 + 0x3c);
        if (1 < iVar7) {
          do {
            if ((iVar6 != *(short *)(this->_padding_ + 0x4a)) &&
               (((uint)puVar2 & 1 << ((byte)iVar6 & 0x1f)) != 0)) goto LAB_00430784;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar7);
        }
        iVar6 = -1;
LAB_00430784:
        if (-1 < iVar6) {
          iVar8 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar8 + 0x40) + iVar6 * 4));
          if (iVar8 == 0) {
            (**(code **)(this->_padding_ + 0x44))
                      (*(undefined4 *)
                        (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x40) + iVar6 * 4));
            if ((char)this->_padding_ == '\x01') {
              *(undefined1 *)&this->_padding_ = 0;
            }
          }
        }
      }
    }
  }
  if (this->_padding_ != 0) {
    iVar8 = RGE_Game_World::is_player_turn
                      (*(RGE_Game_World **)(this->_padding_ + 0x3c),
                       (int)*(short *)(this->_padding_ + 0x4a));
    if (iVar8 != 0) {
      uVar9 = RGE_Game_World::get_accum_time_delta
                        (*(RGE_Game_World **)(this->_padding_ + 0x3c),
                         (int)*(short *)(this->_padding_ + 0x4a));
      UnitAIModule::update((UnitAIModule *)this->_padding_,uVar9);
    }
  }
  return uVar5;
}

// --------------------------------------------------

// Function: init_missile
// Address: 0045a950
void __thiscall
RGE_Missile_Object::init_missile
          (RGE_Missile_Object *this,RGE_Combat_Object *param_1,RGE_Static_Object *param_2,
          float param_3)
{
  RGE_Action_Missile *this_00;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Action_Missile *)operator_new(0x54);
  local_4 = 0;
  if (this_00 == (RGE_Action_Missile *)0x0) {
    pRVar1 = (RGE_Action *)0x0;
  }
  else {
    pRVar1 = (RGE_Action *)
             RGE_Action_Missile::RGE_Action_Missile
                       (this_00,(RGE_Action_Object *)this,(RGE_Static_Object *)param_1,param_2,
                        param_2->world_x,param_2->world_y,param_2->world_z);
  }
  local_4 = 0xffffffff;
  if (pRVar1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar1);
  }
  this->max_range = param_3;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: init_missile
// Address: 0045a9e0
void __thiscall
RGE_Missile_Object::init_missile
          (RGE_Missile_Object *this,RGE_Combat_Object *param_1,float param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action_Missile *this_00;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbcb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Action_Missile *)operator_new(0x54);
  local_4 = 0;
  if (this_00 == (RGE_Action_Missile *)0x0) {
    pRVar1 = (RGE_Action *)0x0;
  }
  else {
    pRVar1 = (RGE_Action *)
             RGE_Action_Missile::RGE_Action_Missile
                       (this_00,(RGE_Action_Object *)this,(RGE_Static_Object *)param_1,
                        (RGE_Static_Object *)0x0,param_2,param_3,param_4);
  }
  local_4 = 0xffffffff;
  if (pRVar1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar1);
  }
  this->max_range = param_5;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: missile_move
// Address: 0045aa70
uchar __thiscall RGE_Missile_Object::missile_move(RGE_Missile_Object *this)
{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float new_y;
  float new_x;
  float new_z;
  
  fVar5 = (float)this->_padding_ + (float)this->_padding_;
  fVar1 = (float)this->_padding_;
  fVar4 = (float)this->_padding_ + (float)this->_padding_;
  fVar2 = (float)this->_padding_;
  if ((((fVar5 < _DAT_00570934) ||
       (iVar3 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28),
       (float)*(int *)(iVar3 + 8) <= fVar5)) || (fVar4 < _DAT_00570934)) ||
     ((float)*(int *)(iVar3 + 0xc) <= fVar4)) {
    (**(code **)(this->_padding_ + 0x6c))();
  }
  fVar6 = (float10)(**(code **)(this->_padding_ + 0x34))(fVar5,fVar4,fVar1 + fVar2);
  if (fVar6 == (float10)(float)this->_padding_) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: make_object_collision_list
// Address: 0045ab20
RGE_Check_List * __thiscall
RGE_Missile_Object::make_object_collision_list(RGE_Missile_Object *this,float param_1)
{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  RGE_Missile_Object *pRVar5;
  RGE_Master_Static_Object *pRVar6;
  float fVar7;
  float fVar8;
  short sVar9;
  short sVar10;
  RGE_Check_List *this_00;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *unaff_FS_OFFSET;
  short x2;
  short x1;
  short local_40;
  float rx2;
  float ry2;
  float ry;
  float dy;
  RGE_Map *map;
  RGE_Check_List *check_list;
  RGE_Check_List *local_20;
  float rx;
  float dx;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbeb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  fVar1 = *(float *)(this->_padding_ + 0x30);
  fVar2 = *(float *)(this->_padding_ + 0x34);
  if ((fVar1 <= _DAT_00570934) || (fVar2 <= _DAT_00570934)) {
    _x2 = (RGE_Check_List *)0x0;
  }
  else {
    local_40 = __ftol();
    sVar9 = __ftol();
    x1 = __ftol();
    sVar10 = __ftol();
    iVar3 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
    this_00 = (RGE_Check_List *)operator_new(4);
    local_4 = 0;
    if (this_00 == (RGE_Check_List *)0x0) {
      _x2 = (RGE_Check_List *)0x0;
    }
    else {
      _x2 = (RGE_Check_List *)RGE_Check_List::RGE_Check_List(this_00);
    }
    local_4 = 0xffffffff;
    if (local_40 < 0) {
      local_40 = 0;
    }
    if (*(int *)(iVar3 + 8) <= (int)x1) {
      x1 = *(short *)(iVar3 + 8) + -1;
    }
    if (sVar9 < 0) {
      sVar9 = 0;
    }
    if (*(int *)(iVar3 + 0xc) <= (int)sVar10) {
      sVar10 = *(short *)(iVar3 + 0xc) + -1;
    }
    if (sVar9 <= sVar10) {
      rx2 = (float)(sVar9 * 4);
      check_list = (RGE_Check_List *)(((int)sVar10 - (int)sVar9) + 1);
      do {
        if (local_40 <= x1) {
          puVar12 = (undefined4 *)
                    (*(int *)((int)rx2 + *(int *)(iVar3 + 0x8d8c)) + local_40 * 0x18 + 0x10);
          iVar11 = ((int)x1 - (int)local_40) + 1;
          do {
            for (puVar4 = (undefined4 *)*puVar12; puVar4 != (undefined4 *)0x0;
                puVar4 = (undefined4 *)puVar4[1]) {
              pRVar5 = (RGE_Missile_Object *)*puVar4;
              if (pRVar5 != this) {
                pRVar6 = (RGE_Master_Static_Object *)pRVar5->_padding_;
                if ((((_DAT_00570934 < pRVar6->radius_y) && (_DAT_00570934 < pRVar6->radius_x)) &&
                    (fVar7 = (float)pRVar5->_padding_ - (float)this->_padding_,
                    -(pRVar6->radius_z - _DAT_00570940) <= fVar7)) &&
                   (fVar7 <= *(float *)(this->_padding_ + 0x38) - _DAT_00570940)) {
                  fVar7 = (float)pRVar5->_padding_ - (float)this->_padding_;
                  fVar8 = (float)pRVar5->_padding_ - (float)this->_padding_;
                  if (fVar7 < _DAT_00570934) {
                    fVar7 = -fVar7;
                  }
                  if (fVar8 < _DAT_00570934) {
                    fVar8 = -fVar8;
                  }
                  fVar7 = fVar7 - (pRVar6->radius_x + fVar1 + param_1);
                  fVar8 = fVar8 - (pRVar6->radius_y + fVar2 + param_1);
                  if ((fVar7 <= _DAT_00570934) && (fVar8 <= _DAT_00570934)) {
                    RGE_Check_List::add_node(_x2,(RGE_Static_Object *)pRVar5,fVar7,fVar8,'\0');
                  }
                }
              }
            }
            puVar12 = puVar12 + 6;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        rx2 = (float)((int)rx2 + 4);
        check_list = (RGE_Check_List *)((int)&check_list[-1].list + 3);
      } while (check_list != (RGE_Check_List *)0x0);
    }
    if (_x2->list == (RGE_Check_Node *)0x0) {
      if (_x2 != (RGE_Check_List *)0x0) {
        RGE_Check_List::~RGE_Check_List(_x2);
        operator_delete(_x2);
      }
      local_20 = (RGE_Check_List *)0x0;
      _x2 = local_20;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return _x2;
}

// --------------------------------------------------

