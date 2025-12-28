// Class: TRIBE_Tree_Object
// Size:  0x88
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
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Tree_Object
// Address: 004cca60
/* public: __thiscall TRIBE_Tree_Object::TRIBE_Tree_Object(class TRIBE_Master_Tree_Object *,class
   RGE_Player *,float,float,float,int) */

TRIBE_Tree_Object * __thiscall
TRIBE_Tree_Object::TRIBE_Tree_Object
          (TRIBE_Tree_Object *this,TRIBE_Master_Tree_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Static_Object::RGE_Static_Object
            ((RGE_Static_Object *)this,(RGE_Master_Static_Object *)param_1,param_2,param_3,param_4,
             param_5,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_6 != 0) {
    RGE_Static_Object::setup
              ((RGE_Static_Object *)this,(RGE_Master_Static_Object *)param_1,param_2,param_3,param_4
               ,param_5);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004ccaf0
/* public: virtual void * __thiscall TRIBE_Tree_Object::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Tree_Object::_scalar_deleting_destructor_(TRIBE_Tree_Object *this,uint param_1)
{
  ~TRIBE_Tree_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Tree_Object
// Address: 004ccb10
/* public: virtual __thiscall TRIBE_Tree_Object::~TRIBE_Tree_Object(void) */

void __thiscall TRIBE_Tree_Object::~TRIBE_Tree_Object(TRIBE_Tree_Object *this)
{
  undefined4 *puVar1;
  RGE_Object_List *this_00;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  pcStack_8 = FUN_0055f9e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)this = &RGE_Static_Object::_vftable_;
  uStack_4 = 1;
  RGE_Static_Object::remove_visible_resource((RGE_Static_Object *)this);
  if (*(int *)&this->field_0xc != 0) {
    if ((byte)this->field_0x48 < 3) {
      RGE_Static_Object::take_attribute_from_owner((RGE_Static_Object *)this);
    }
    if ((byte)this->field_0x48 < 7) {
      RGE_Victory_Conditions::update_for_object
                (*(RGE_Victory_Conditions **)(*(int *)&this->field_0xc + 0x34),
                 (RGE_Static_Object *)this);
    }
  }
  if (*(undefined4 **)&this->field_0x18 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&this->field_0x18)(1);
    *(undefined4 *)&this->field_0x18 = 0;
  }
  if (*(RGE_Player **)&this->field_0xc != (RGE_Player *)0x0) {
    if ((this->field_0x36 & 1) != 0) {
      RGE_Player::unselect_one_object(*(RGE_Player **)&this->field_0xc,(RGE_Static_Object *)this);
    }
    (**(code **)(**(int **)&this->field_0xc + 0xe0))
              (this,this->field_0x49,this->field_0x4a,*(undefined4 *)&this->field_0x50);
    *(undefined4 *)&this->field_0xc = 0;
  }
  if (*(int *)&this->field_0x1c != 0) {
    RGE_Object_List::remove_node
              ((RGE_Object_List *)(*(int *)&this->field_0x1c + 0xc),(RGE_Static_Object *)this,
               (RGE_Object_Node *)0x0);
    *(undefined4 *)&this->field_0x1c = 0;
  }
  if ((*(int *)&this->field_0x8 != 0) &&
     ((float)(double)DAT_00574718 < *(float *)(*(int *)&this->field_0x8 + 0x38))) {
    RGE_Static_Object::removeFromObstructionMap((RGE_Static_Object *)this,2);
  }
  if (*(int *)&this->field_0x20 != 0) {
    RGE_Object_List::remove_node
              (*(RGE_Object_List **)(*(int *)&this->field_0x20 + 0x24),(RGE_Static_Object *)this,
               (RGE_Object_Node *)0x0);
    *(undefined4 *)&this->field_0x20 = 0;
  }
  if (*(int *)&this->field_0x24 != 0) {
    puVar2 = *(undefined4 **)(*(int *)&this->field_0x24 + 4);
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar2[1];
      (**(code **)(*(int *)*puVar2 + 0xd4))();
      puVar2 = puVar1;
    }
    this_00 = *(RGE_Object_List **)&this->field_0x24;
    if (this_00 != (RGE_Object_List *)0x0) {
      RGE_Object_List::~RGE_Object_List(this_00);
      operator_delete(this_00);
    }
  }
  if (*(undefined4 **)&this->field_0x74 != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)&this->field_0x74)(1);
    *(undefined4 *)&this->field_0x74 = 0;
  }
  uStack_4 = uStack_4 & 0xffffff00;
  if (*(void **)&this->field_0x64 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x64);
    *(undefined4 *)&this->field_0x64 = 0;
  }
  *(undefined4 *)&this->field_0x68 = 0;
  *(undefined4 *)&this->field_0x6c = 0;
  *(undefined4 *)&this->field_0x70 = 0;
  uStack_4 = 0xffffffff;
  if (*(void **)&this->field_0x54 != (void *)0x0) {
    operator_delete(*(void **)&this->field_0x54);
    *(undefined4 *)&this->field_0x54 = 0;
  }
  *(undefined4 *)&this->field_0x58 = 0;
  *(undefined4 *)&this->field_0x5c = 0;
  *(undefined4 *)&this->field_0x60 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: TRIBE_Tree_Object
// Address: 004ccb20
/* public: __thiscall TRIBE_Tree_Object::TRIBE_Tree_Object(int,class RGE_Game_World *,int) */

TRIBE_Tree_Object * __thiscall
TRIBE_Tree_Object::TRIBE_Tree_Object
          (TRIBE_Tree_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd48;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Static_Object::RGE_Static_Object((RGE_Static_Object *)this,param_1,param_2,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_3 != 0) {
    RGE_Static_Object::setup((RGE_Static_Object *)this,param_1,param_2);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: set_object_state
// Address: 004ccb90
/* public: virtual void __thiscall TRIBE_Tree_Object::set_object_state(unsigned char) */

void __thiscall TRIBE_Tree_Object::set_object_state(TRIBE_Tree_Object *this,uchar param_1)
{
  RGE_Static_Object::set_object_state((RGE_Static_Object *)this,param_1);
  return;
}

// --------------------------------------------------

