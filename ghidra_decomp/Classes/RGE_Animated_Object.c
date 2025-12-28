// Class: RGE_Animated_Object
// Size:  0x8C
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
//
// Member Layout:
// [0x088] float speed
// ----------------------------------------------------------------

// Function: getSpeed
// Address: 00405f40
/* public: virtual float __thiscall RGE_Animated_Object::getSpeed(void)const  */

float __thiscall RGE_Animated_Object::getSpeed(RGE_Animated_Object *this)
{
  return this->speed;
}

// --------------------------------------------------

// Function: RGE_Animated_Object
// Address: 0041a150
/* public: __thiscall RGE_Animated_Object::RGE_Animated_Object(class RGE_Master_Animated_Object
   *,class RGE_Player *,float,float,float,int) */

RGE_Animated_Object * __thiscall
RGE_Animated_Object::RGE_Animated_Object
          (RGE_Animated_Object *this,RGE_Master_Animated_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c928;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Static_Object::RGE_Static_Object
            ((RGE_Static_Object *)this,(RGE_Master_Static_Object *)param_1,param_2,param_3,param_4,
             param_5,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0041a1e0
/* public: virtual void * __thiscall RGE_Animated_Object::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
RGE_Animated_Object::_scalar_deleting_destructor_(RGE_Animated_Object *this,uint param_1)
{
  ~RGE_Animated_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Animated_Object
// Address: 0041a200
/* public: virtual __thiscall RGE_Animated_Object::~RGE_Animated_Object(void) */

void __thiscall RGE_Animated_Object::~RGE_Animated_Object(RGE_Animated_Object *this)
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
  this->_padding_ = (int)&RGE_Static_Object::_vftable_;
  uStack_4 = 1;
  RGE_Static_Object::remove_visible_resource((RGE_Static_Object *)this);
  if (this->_padding_ != 0) {
    if ((byte)this->_padding_ < 3) {
      RGE_Static_Object::take_attribute_from_owner((RGE_Static_Object *)this);
    }
    if ((byte)this->_padding_ < 7) {
      RGE_Victory_Conditions::update_for_object
                (*(RGE_Victory_Conditions **)(this->_padding_ + 0x34),(RGE_Static_Object *)this);
    }
  }
  if ((undefined4 *)this->_padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->_padding_)(1);
    this->_padding_ = 0;
  }
  if ((RGE_Player *)this->_padding_ != (RGE_Player *)0x0) {
    if ((this->_padding_ & 0x10000) != 0) {
      RGE_Player::unselect_one_object((RGE_Player *)this->_padding_,(RGE_Static_Object *)this);
    }
    (**(code **)(*(int *)this->_padding_ + 0xe0))
              (this,*(undefined1 *)((int)&this->_padding_ + 1),
               *(undefined1 *)((int)&this->_padding_ + 2),this->_padding_);
    this->_padding_ = 0;
  }
  if (this->_padding_ != 0) {
    RGE_Object_List::remove_node
              ((RGE_Object_List *)(this->_padding_ + 0xc),(RGE_Static_Object *)this,
               (RGE_Object_Node *)0x0);
    this->_padding_ = 0;
  }
  if ((this->_padding_ != 0) && ((float)(double)DAT_00574718 < *(float *)(this->_padding_ + 0x38)))
{
    RGE_Static_Object::removeFromObstructionMap((RGE_Static_Object *)this,2);
  }
  if (this->_padding_ != 0) {
    RGE_Object_List::remove_node
              (*(RGE_Object_List **)(this->_padding_ + 0x24),(RGE_Static_Object *)this,
               (RGE_Object_Node *)0x0);
    this->_padding_ = 0;
  }
  if (this->_padding_ != 0) {
    puVar2 = *(undefined4 **)(this->_padding_ + 4);
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar2[1];
      (**(code **)(*(int *)*puVar2 + 0xd4))();
      puVar2 = puVar1;
    }
    this_00 = (RGE_Object_List *)this->_padding_;
    if (this_00 != (RGE_Object_List *)0x0) {
      RGE_Object_List::~RGE_Object_List(this_00);
      operator_delete(this_00);
    }
  }
  if ((undefined4 *)this->_padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->_padding_)(1);
    this->_padding_ = 0;
  }
  uStack_4 = uStack_4 & 0xffffff00;
  if ((void *)this->_padding_ != (void *)0x0) {
    operator_delete((void *)this->_padding_);
    this->_padding_ = 0;
  }
  this->_padding_ = 0;
  this->_padding_ = 0;
  this->_padding_ = 0;
  uStack_4 = 0xffffffff;
  if ((void *)this->_padding_ != (void *)0x0) {
    operator_delete((void *)this->_padding_);
    this->_padding_ = 0;
  }
  this->_padding_ = 0;
  this->_padding_ = 0;
  this->_padding_ = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: RGE_Animated_Object
// Address: 0041a210
/* public: __thiscall RGE_Animated_Object::RGE_Animated_Object(int,class RGE_Game_World *,int) */

RGE_Animated_Object * __thiscall
RGE_Animated_Object::RGE_Animated_Object
          (RGE_Animated_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c948;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Static_Object::RGE_Static_Object((RGE_Static_Object *)this,param_1,param_2,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: recycle_in_to_game
// Address: 0041a280
/* public: virtual void __thiscall RGE_Animated_Object::recycle_in_to_game(class
   RGE_Master_Static_Object *,class RGE_Player *,float,float,float) */

void __thiscall
RGE_Animated_Object::recycle_in_to_game
          (RGE_Animated_Object *this,RGE_Master_Static_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  RGE_Static_Object::recycle_in_to_game
            ((RGE_Static_Object *)this,param_1,param_2,param_3,param_4,param_5);
  this->speed = 0.0;
  RGE_Static_Object::set_sleep_flag((RGE_Static_Object *)this,'\0');
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0041a2c0
/* protected: virtual int __thiscall RGE_Animated_Object::setup(class RGE_Master_Animated_Object
   *,class RGE_Player *,float,float,float) */

int __thiscall
RGE_Animated_Object::setup
          (RGE_Animated_Object *this,RGE_Master_Animated_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  RGE_Static_Object::setup
            ((RGE_Static_Object *)this,(RGE_Master_Static_Object *)param_1,param_2,param_3,param_4,
             param_5);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x14;
  this->speed = 0.0;
  RGE_Static_Object::set_sleep_flag((RGE_Static_Object *)this,'\0');
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0041a310
/* protected: virtual int __thiscall RGE_Animated_Object::setup(int,class RGE_Game_World *) */

int __thiscall
RGE_Animated_Object::setup(RGE_Animated_Object *this,int param_1,RGE_Game_World *param_2)
{
  RGE_Static_Object::setup((RGE_Static_Object *)this,param_1,param_2);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x14;
  rge_read(param_1,&this->speed,4);
  return 1;
}

// --------------------------------------------------

// Function: update
// Address: 0041a350
/* public: virtual unsigned char __thiscall RGE_Animated_Object::update(void) */

uchar __thiscall RGE_Animated_Object::update(RGE_Animated_Object *this)
{
  uchar uVar1;
  char cVar2;
  
  uVar1 = RGE_Static_Object::update((RGE_Static_Object *)this);
  cVar2 = (char)this->_padding_;
  if (cVar2 == '\x03') {
    if (*(int *)(this->_padding_ + 0x1c) == 0) {
      (**(code **)(this->_padding_ + 0x5c))(5);
    }
    else {
      (**(code **)(this->_padding_ + 0x5c))(4);
    }
  }
  else if (cVar2 == '\x04') {
    cVar2 = (**(code **)(*(int *)this->_padding_ + 0x18))(this->_padding_);
    if (cVar2 == '\0') {
      *(undefined1 *)&this->_padding_ = 5;
      this->speed = 0.0;
    }
  }
  (**(code **)(*(int *)this->_padding_ + 8))
            (*(undefined4 *)(*(int *)(this->_padding_ + 0x3c) + 0x84),this->speed);
  return uVar1;
}

// --------------------------------------------------

// Function: save
// Address: 0041a3d0
/* public: virtual void __thiscall RGE_Animated_Object::save(int) */

void __thiscall RGE_Animated_Object::save(RGE_Animated_Object *this,int param_1)
{
  RGE_Static_Object::save((RGE_Static_Object *)this,param_1);
  rge_write(param_1,&this->speed,4);
  return;
}

// --------------------------------------------------

// Function: transform
// Address: 0041a400
/* public: virtual void __thiscall RGE_Animated_Object::transform(class RGE_Master_Static_Object *)
    */

void __thiscall
RGE_Animated_Object::transform(RGE_Animated_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Static_Object::transform((RGE_Static_Object *)this,param_1);
  return;
}

// --------------------------------------------------

// Function: set_being_worked_on
// Address: 0041a410
/* public: virtual void __thiscall RGE_Animated_Object::set_being_worked_on(class RGE_Action_Object
   *,short,unsigned char) */

void __thiscall
RGE_Animated_Object::set_being_worked_on
          (RGE_Animated_Object *this,RGE_Action_Object *param_1,short param_2,uchar param_3)
{
  RGE_Static_Object::set_being_worked_on((RGE_Static_Object *)this,param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: release_being_worked_on
// Address: 0041a430
/* public: virtual void __thiscall RGE_Animated_Object::release_being_worked_on(class
   RGE_Static_Object *) */

void __thiscall
RGE_Animated_Object::release_being_worked_on(RGE_Animated_Object *this,RGE_Static_Object *param_1)
{
  RGE_Static_Object::release_being_worked_on((RGE_Static_Object *)this,param_1);
  RGE_Static_Object::set_sleep_flag((RGE_Static_Object *)this,'\0');
  return;
}

// --------------------------------------------------

