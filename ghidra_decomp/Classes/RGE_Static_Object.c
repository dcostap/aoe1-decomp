// Class: RGE_Static_Object
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
// [0x004] long id
// [0x008] RGE_Master_Static_Object * master_obj
// [0x00C] RGE_Player * owner
// [0x010] RGE_Sprite * sprite
// [0x014] RGE_Sprite * old_sprite
// [0x018] RGE_Active_Sprite_List * sprite_list
// [0x01C] RGE_Tile * tile
// [0x020] RGE_Static_Object * inside_obj
// [0x024] RGE_Object_List * objects
// [0x028] short screen_x_offset
// [0x02A] short screen_y_offset
// [0x02C] short shadow_x_offset
// [0x02E] short shadow_y_offset
// [0x030] float hp
// [0x034] uchar curr_damage_percent
// [0x035] uchar facet
// [0x036] uchar selected
// [0x037] uchar selected_group
// [0x038] float world_x
// [0x03C] float world_y
// [0x040] float world_z
// [0x044] float attribute_amount_held
// [0x048] uchar object_state
// [0x049] uchar sleep_flag
// [0x04A] uchar dopple_flag
// [0x04B] uchar goto_sleep_flag
// [0x04C] short attribute_type_held
// [0x04E] uchar type
// [0x04F] uchar worker_num
// [0x050] RGE_Object_Node * player_object_node
// [0x054] ManagedArray<int> pathingGroupMembers (sz: 0x10)
// [0x064] ManagedArray<int> groupMembers (sz: 0x10)
// [0x074] UnitAIModule * unitAIValue
// [0x078] int groupCommanderValue
// [0x07C] int zoneMapIndex
// [0x080] float groupRangeValue
// [0x084] uchar inObstructionMapValue
// [0x085] uchar lastInObstructionMapValue
// [0x086] uchar underAttackValue
// ----------------------------------------------------------------

// Function: can_attack
// Address: 00405d00
/* public: virtual unsigned char __thiscall RGE_Static_Object::can_attack(void) */

uchar __thiscall RGE_Static_Object::can_attack(RGE_Static_Object *this)
{
  return '\0';
}

// --------------------------------------------------

// Function: canRepair
// Address: 00405d10
/* public: virtual int __thiscall RGE_Static_Object::canRepair(void) */

int __thiscall RGE_Static_Object::canRepair(RGE_Static_Object *this)
{
  return 0;
}

// --------------------------------------------------

// Function: inAttackRange
// Address: 00405d20
/* public: virtual int __thiscall RGE_Static_Object::inAttackRange(class RGE_Static_Object *) */

int __thiscall RGE_Static_Object::inAttackRange(RGE_Static_Object *this,RGE_Static_Object *param_1)
{
  return 0;
}

// --------------------------------------------------

// Function: calc_attack_modifier
// Address: 00405d30
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::calc_attack_modifier(class RGE_Static_Object
   *) */

float __thiscall
RGE_Static_Object::calc_attack_modifier(RGE_Static_Object *this,RGE_Static_Object *param_1)
{
  return _DAT_0056e63c;
}

// --------------------------------------------------

// Function: rateOfFire
// Address: 00405d40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::rateOfFire(void) */

float __thiscall RGE_Static_Object::rateOfFire(RGE_Static_Object *this)
{
  return _DAT_0056e640;
}

// --------------------------------------------------

// Function: damageCapability
// Address: 00405d50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::damageCapability(void) */

float __thiscall RGE_Static_Object::damageCapability(RGE_Static_Object *this)
{
  return _DAT_0056e640;
}

// --------------------------------------------------

// Function: damageCapability
// Address: 00405d60
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::damageCapability(class RGE_Static_Object *)
    */

float __thiscall
RGE_Static_Object::damageCapability(RGE_Static_Object *this,RGE_Static_Object *param_1)
{
  return _DAT_0056e640;
}

// --------------------------------------------------

// Function: weaponRange
// Address: 00405d70
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::weaponRange(void) */

float __thiscall RGE_Static_Object::weaponRange(RGE_Static_Object *this)
{
  return _DAT_0056e640;
}

// --------------------------------------------------

// Function: minimumWeaponRange
// Address: 00405d80
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::minimumWeaponRange(void) */

float __thiscall RGE_Static_Object::minimumWeaponRange(RGE_Static_Object *this)
{
  return _DAT_0056e640;
}

// --------------------------------------------------

// Function: currentTargetID
// Address: 00405d90
/* public: virtual int __thiscall RGE_Static_Object::currentTargetID(void)const  */

int __thiscall RGE_Static_Object::currentTargetID(RGE_Static_Object *this)
{
  return -1;
}

// --------------------------------------------------

// Function: currentTargetX
// Address: 00405da0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::currentTargetX(void)const  */

float __thiscall RGE_Static_Object::currentTargetX(RGE_Static_Object *this)
{
  return _DAT_0056e644;
}

// --------------------------------------------------

// Function: currentTargetY
// Address: 00405db0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::currentTargetY(void)const  */

float __thiscall RGE_Static_Object::currentTargetY(RGE_Static_Object *this)
{
  return _DAT_0056e644;
}

// --------------------------------------------------

// Function: currentTargetZ
// Address: 00405dc0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::currentTargetZ(void)const  */

float __thiscall RGE_Static_Object::currentTargetZ(RGE_Static_Object *this)
{
  return _DAT_0056e644;
}

// --------------------------------------------------

// Function: keepGatheringWhenObjectIsOut
// Address: 00405dd0
/* public: virtual unsigned char __thiscall
   RGE_Static_Object::keepGatheringWhenObjectIsOut(int)const  */

uchar __thiscall
RGE_Static_Object::keepGatheringWhenObjectIsOut(RGE_Static_Object *this,int param_1)
{
  return '\0';
}

// --------------------------------------------------

// Function: produceWhenKilledBy
// Address: 00405de0
/* public: virtual unsigned char __thiscall RGE_Static_Object::produceWhenKilledBy(int)const  */

uchar __thiscall RGE_Static_Object::produceWhenKilledBy(RGE_Static_Object *this,int param_1)
{
  return '\x01';
}

// --------------------------------------------------

// Function: useSameZoneDropsite
// Address: 00405df0
/* public: virtual unsigned char __thiscall RGE_Static_Object::useSameZoneDropsite(void)const  */

uchar __thiscall RGE_Static_Object::useSameZoneDropsite(RGE_Static_Object *this)
{
  return '\x01';
}

// --------------------------------------------------

// Function: notify
// Address: 00405e00
/* public: virtual void __thiscall RGE_Static_Object::notify(int,int,int,long,long,long) */

void __thiscall
RGE_Static_Object::notify
          (RGE_Static_Object *this,int param_1,int param_2,int param_3,long param_4,long param_5,
          long param_6)
{
  return;
}

// --------------------------------------------------

// Function: attack
// Address: 00405e10
/* public: virtual int __thiscall RGE_Static_Object::attack(int,int) */

int __thiscall RGE_Static_Object::attack(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: attack
// Address: 00405e20
/* public: virtual int __thiscall RGE_Static_Object::attack(float,float,float,int) */

int __thiscall
RGE_Static_Object::attack
          (RGE_Static_Object *this,float param_1,float param_2,float param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: moveTo
// Address: 00405e30
/* public: virtual int __thiscall RGE_Static_Object::moveTo(int,int) */

int __thiscall RGE_Static_Object::moveTo(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: moveTo
// Address: 00405e40
/* public: virtual int __thiscall RGE_Static_Object::moveTo(int,float,int) */

int __thiscall
RGE_Static_Object::moveTo(RGE_Static_Object *this,int param_1,float param_2,int param_3)
{
  return 0;
}

// --------------------------------------------------

// Function: moveTo
// Address: 00405e50
/* public: virtual int __thiscall RGE_Static_Object::moveTo(float,float,float,float,int) */

int __thiscall
RGE_Static_Object::moveTo
          (RGE_Static_Object *this,float param_1,float param_2,float param_3,float param_4,
          int param_5)
{
  return 0;
}

// --------------------------------------------------

// Function: moveAwayFrom
// Address: 00405e60
/* public: virtual int __thiscall RGE_Static_Object::moveAwayFrom(int,int) */

int __thiscall RGE_Static_Object::moveAwayFrom(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: hunt
// Address: 00405e70
/* public: virtual int __thiscall RGE_Static_Object::hunt(int,int) */

int __thiscall RGE_Static_Object::hunt(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: gather
// Address: 00405e80
/* public: virtual int __thiscall RGE_Static_Object::gather(int,int) */

int __thiscall RGE_Static_Object::gather(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: convert
// Address: 00405e90
/* public: virtual int __thiscall RGE_Static_Object::convert(int,int) */

int __thiscall RGE_Static_Object::convert(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: heal
// Address: 00405ea0
/* public: virtual int __thiscall RGE_Static_Object::heal(int,int) */

int __thiscall RGE_Static_Object::heal(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: repair
// Address: 00405eb0
/* public: virtual int __thiscall RGE_Static_Object::repair(int,int) */

int __thiscall RGE_Static_Object::repair(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: build
// Address: 00405ec0
/* public: virtual int __thiscall RGE_Static_Object::build(int,int) */

int __thiscall RGE_Static_Object::build(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: trade
// Address: 00405ed0
/* public: virtual int __thiscall RGE_Static_Object::trade(int,int) */

int __thiscall RGE_Static_Object::trade(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: explore
// Address: 00405ee0
/* public: virtual int __thiscall RGE_Static_Object::explore(int,int,int) */

int __thiscall
RGE_Static_Object::explore(RGE_Static_Object *this,int param_1,int param_2,int param_3)
{
  return 0;
}

// --------------------------------------------------

// Function: enter
// Address: 00405ef0
/* public: virtual int __thiscall RGE_Static_Object::enter(int,int) */

int __thiscall RGE_Static_Object::enter(RGE_Static_Object *this,int param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: unload
// Address: 00405f00
/* public: virtual int __thiscall RGE_Static_Object::unload(int,float,float,float) */

int __thiscall
RGE_Static_Object::unload
          (RGE_Static_Object *this,int param_1,float param_2,float param_3,float param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: transport
// Address: 00405f10
/* public: virtual int __thiscall RGE_Static_Object::transport(float,float,float,int) */

int __thiscall
RGE_Static_Object::transport
          (RGE_Static_Object *this,float param_1,float param_2,float param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: stopAction
// Address: 00405f20
/* public: virtual int __thiscall RGE_Static_Object::stopAction(void) */

int __thiscall RGE_Static_Object::stopAction(RGE_Static_Object *this)
{
  return 0;
}

// --------------------------------------------------

// Function: pause
// Address: 00405f30
/* public: virtual int __thiscall RGE_Static_Object::pause(void) */

int __thiscall RGE_Static_Object::pause(RGE_Static_Object *this)
{
  return 0;
}

// --------------------------------------------------

// Function: ~RGE_Static_Object
// Address: 0041a1fe
void __thiscall RGE_Static_Object::~RGE_Static_Object(RGE_Static_Object *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_List *this_00;
  int *piVar2;
  RGE_Object_Node *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  pcStack_8 = FUN_0055f9e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  uStack_4 = 1;
  remove_visible_resource(this);
  if (this->owner != (RGE_Player *)0x0) {
    if (this->object_state < 3) {
      take_attribute_from_owner(this);
    }
    if (this->object_state < 7) {
      RGE_Victory_Conditions::update_for_object(this->owner->victory_conditions,this);
    }
  }
  if (this->sprite_list != (RGE_Active_Sprite_List *)0x0) {
    (**(code **)this->sprite_list->_padding_)(1);
    this->sprite_list = (RGE_Active_Sprite_List *)0x0;
  }
  if (this->owner != (RGE_Player *)0x0) {
    if ((this->selected & 1) != 0) {
      RGE_Player::unselect_one_object(this->owner,this);
    }
    (**(code **)(this->owner->_padding_ + 0xe0))
              (this,this->sleep_flag,this->dopple_flag,this->player_object_node);
    this->owner = (RGE_Player *)0x0;
  }
  if (this->tile != (RGE_Tile *)0x0) {
    RGE_Object_List::remove_node(&this->tile->objects,this,(RGE_Object_Node *)0x0);
    this->tile = (RGE_Tile *)0x0;
  }
  if ((this->master_obj != (RGE_Master_Static_Object *)0x0) &&
     ((float)(double)DAT_00574718 < this->master_obj->radius_z)) {
    removeFromObstructionMap(this,2);
  }
  if (this->inside_obj != (RGE_Static_Object *)0x0) {
    RGE_Object_List::remove_node(this->inside_obj->objects,this,(RGE_Object_Node *)0x0);
    this->inside_obj = (RGE_Static_Object *)0x0;
  }
  if (this->objects != (RGE_Object_List *)0x0) {
    pRVar3 = this->objects->list;
    while (pRVar3 != (RGE_Object_Node *)0x0) {
      pRVar1 = pRVar3->next;
      (**(code **)(pRVar3->node->_padding_ + 0xd4))();
      pRVar3 = pRVar1;
    }
    this_00 = this->objects;
    if (this_00 != (RGE_Object_List *)0x0) {
      RGE_Object_List::~RGE_Object_List(this_00);
      operator_delete(this_00);
    }
  }
  if (this->unitAIValue != (UnitAIModule *)0x0) {
    (**(code **)this->unitAIValue->_padding_)(1);
    this->unitAIValue = (UnitAIModule *)0x0;
  }
  piVar2 = (this->groupMembers).value;
  uStack_4 = uStack_4 & 0xffffff00;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (this->groupMembers).value = (int *)0x0;
  }
  (this->groupMembers).numberValue = 0;
  (this->groupMembers).desiredNumberValue = 0;
  (this->groupMembers).maximumSizeValue = 0;
  piVar2 = (this->pathingGroupMembers).value;
  uStack_4 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (this->pathingGroupMembers).value = (int *)0x0;
  }
  (this->pathingGroupMembers).numberValue = 0;
  (this->pathingGroupMembers).desiredNumberValue = 0;
  (this->pathingGroupMembers).maximumSizeValue = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: do_command
// Address: 0041a450
/* public: virtual void __thiscall RGE_Static_Object::do_command(class RGE_Static_Object
   *,float,float,float) */

void __thiscall
RGE_Static_Object::do_command
          (RGE_Static_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  return;
}

// --------------------------------------------------

// Function: move_to
// Address: 0041a460
/* public: virtual void __thiscall RGE_Static_Object::move_to(class RGE_Static_Object
   *,float,float,float) */

void __thiscall
RGE_Static_Object::move_to
          (RGE_Static_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  return;
}

// --------------------------------------------------

// Function: work
// Address: 0041a470
/* public: virtual void __thiscall RGE_Static_Object::work(class RGE_Static_Object
   *,float,float,float) */

void __thiscall
RGE_Static_Object::work
          (RGE_Static_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  return;
}

// --------------------------------------------------

// Function: stop
// Address: 0041a480
/* public: virtual void __thiscall RGE_Static_Object::stop(void) */

void __thiscall RGE_Static_Object::stop(RGE_Static_Object *this)
{
  return;
}

// --------------------------------------------------

// Function: set_attack
// Address: 0041a490
/* public: virtual void __thiscall RGE_Static_Object::set_attack(class RGE_Static_Object *) */

void __thiscall RGE_Static_Object::set_attack(RGE_Static_Object *this,RGE_Static_Object *param_1)
{
  return;
}

// --------------------------------------------------

// Function: play_command_sound
// Address: 0041a4a0
/* public: virtual void __thiscall RGE_Static_Object::play_command_sound(void) */

void __thiscall RGE_Static_Object::play_command_sound(RGE_Static_Object *this)
{
  return;
}

// --------------------------------------------------

// Function: play_move_sound
// Address: 0041a4b0
/* public: virtual void __thiscall RGE_Static_Object::play_move_sound(void) */

void __thiscall RGE_Static_Object::play_move_sound(RGE_Static_Object *this)
{
  return;
}

// --------------------------------------------------

// Function: get_command_master
// Address: 0041a4c0
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Static_Object::get_command_master(class RGE_Static_Object *,float,float,float) */

RGE_Master_Static_Object * __thiscall
RGE_Static_Object::get_command_master
          (RGE_Static_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  return this->master_obj;
}

// --------------------------------------------------

// Function: get_target_obj
// Address: 0041a4d0
/* public: virtual class RGE_Static_Object * __thiscall RGE_Static_Object::get_target_obj(void) */

RGE_Static_Object * __thiscall RGE_Static_Object::get_target_obj(RGE_Static_Object *this)
{
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: getAngle
// Address: 0041a4e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::getAngle(void)const  */

float __thiscall RGE_Static_Object::getAngle(RGE_Static_Object *this)
{
  return _DAT_0056ee00;
}

// --------------------------------------------------

// Function: maximumSpeed
// Address: 0041a4f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::maximumSpeed(void) */

float __thiscall RGE_Static_Object::maximumSpeed(RGE_Static_Object *this)
{
  return _DAT_0056ee00;
}

// --------------------------------------------------

// Function: passableTile
// Address: 0041a500
/* public: virtual int __thiscall RGE_Static_Object::passableTile(float,float,int) */

int __thiscall
RGE_Static_Object::passableTile(RGE_Static_Object *this,float param_1,float param_2,int param_3)
{
  return 0;
}

// --------------------------------------------------

// Function: facetToNextWaypoint
// Address: 0041a510
/* public: virtual unsigned char __thiscall RGE_Static_Object::facetToNextWaypoint(void)const  */

uchar __thiscall RGE_Static_Object::facetToNextWaypoint(RGE_Static_Object *this)
{
  return 0xff;
}

// --------------------------------------------------

// Function: setWaitingToMove
// Address: 0041a520
/* public: virtual void __thiscall RGE_Static_Object::setWaitingToMove(unsigned char) */

void __thiscall RGE_Static_Object::setWaitingToMove(RGE_Static_Object *this,uchar param_1)
{
  return;
}

// --------------------------------------------------

// Function: waitingToMove
// Address: 0041a530
/* public: virtual unsigned char __thiscall RGE_Static_Object::waitingToMove(void)const  */

uchar __thiscall RGE_Static_Object::waitingToMove(RGE_Static_Object *this)
{
  return '\0';
}

// --------------------------------------------------

// Function: actionState
// Address: 0041a540
/* public: virtual unsigned char __thiscall RGE_Static_Object::actionState(void)const  */

uchar __thiscall RGE_Static_Object::actionState(RGE_Static_Object *this)
{
  return '\0';
}

// --------------------------------------------------

// Function: canPath
// Address: 0041a550
/* public: virtual int __thiscall RGE_Static_Object::canPath(struct XYZPoint,float,int,float
   *,int,int,int) */

int __thiscall
RGE_Static_Object::canPath
          (RGE_Static_Object *this,XYZPoint param_1,float param_2,int param_3,float *param_4,
          int param_5,int param_6,int param_7)
{
  return 0;
}

// --------------------------------------------------

// Function: canPath
// Address: 0041a560
/* public: virtual int __thiscall RGE_Static_Object::canPath(int,float,float *,int,int,int) */

int __thiscall
RGE_Static_Object::canPath
          (RGE_Static_Object *this,int param_1,float param_2,float *param_3,int param_4,int param_5,
          int param_6)
{
  return 0;
}

// --------------------------------------------------

// Function: canBidirectionPath
// Address: 0041a570
/* public: virtual int __thiscall RGE_Static_Object::canBidirectionPath(int,int,float,float
   *,int,int,int) */

int __thiscall
RGE_Static_Object::canBidirectionPath
          (RGE_Static_Object *this,int param_1,int param_2,float param_3,float *param_4,int param_5,
          int param_6,int param_7)
{
  return 0;
}

// --------------------------------------------------

// Function: canPathWithObstructions
// Address: 0041a580
/* public: virtual int __thiscall RGE_Static_Object::canPathWithObstructions(int,float,float
   *,int,int,int,class ManagedArray<int> &) */

int __thiscall
RGE_Static_Object::canPathWithObstructions
          (RGE_Static_Object *this,int param_1,float param_2,float *param_3,int param_4,int param_5,
          int param_6,ManagedArray<int> *param_7)
{
  return 0;
}

// --------------------------------------------------

// Function: canPathWithAdditionalPassability
// Address: 0041a590
/* public: virtual int __thiscall RGE_Static_Object::canPathWithAdditionalPassability(struct
   XYZPoint,float,int,float *,int,int,int,int,int) */

int __thiscall
RGE_Static_Object::canPathWithAdditionalPassability
          (RGE_Static_Object *this,XYZPoint param_1,float param_2,int param_3,float *param_4,
          int param_5,int param_6,int param_7,int param_8,int param_9)
{
  return 0;
}

// --------------------------------------------------

// Function: findFirstTerrainAlongExceptionPath
// Address: 0041a5a0
/* public: virtual int __thiscall RGE_Static_Object::findFirstTerrainAlongExceptionPath(int,float
   *,float *) */

int __thiscall
RGE_Static_Object::findFirstTerrainAlongExceptionPath
          (RGE_Static_Object *this,int param_1,float *param_2,float *param_3)
{
  return 0;
}

// --------------------------------------------------

// Function: canLinePath
// Address: 0041a5b0
/* public: virtual int __thiscall RGE_Static_Object::canLinePath(struct XYPoint const &,struct
   XYPoint const &,float,struct XYPoint &,int) */

int __thiscall
RGE_Static_Object::canLinePath
          (RGE_Static_Object *this,XYPoint *param_1,XYPoint *param_2,float param_3,XYPoint *param_4,
          int param_5)
{
  return 0;
}

// --------------------------------------------------

// Function: canLinePath
// Address: 0041a5c0
/* public: virtual int __thiscall RGE_Static_Object::canLinePath(int,int,int,int,float,int) */

int __thiscall
RGE_Static_Object::canLinePath
          (RGE_Static_Object *this,int param_1,int param_2,int param_3,int param_4,float param_5,
          int param_6)
{
  return 0;
}

// --------------------------------------------------

// Function: firstTileAlongLine
// Address: 0041a5d0
/* public: virtual int __thiscall RGE_Static_Object::firstTileAlongLine(struct XYPoint const
   &,struct XYPoint const &,struct XYPoint &,int,int,int) */

int __thiscall
RGE_Static_Object::firstTileAlongLine
          (RGE_Static_Object *this,XYPoint *param_1,XYPoint *param_2,XYPoint *param_3,int param_4,
          int param_5,int param_6)
{
  return 0;
}

// --------------------------------------------------

// Function: userDefinedWaypoint
// Address: 0041a5e0
/* public: virtual struct XYZBYTEPoint * __thiscall RGE_Static_Object::userDefinedWaypoint(int) */

XYZBYTEPoint * __thiscall
RGE_Static_Object::userDefinedWaypoint(RGE_Static_Object *this,int param_1)
{
  return (XYZBYTEPoint *)0x0;
}

// --------------------------------------------------

// Function: addUserDefinedWaypoint
// Address: 0041a5f0
/* public: virtual int __thiscall RGE_Static_Object::addUserDefinedWaypoint(struct XYZBYTEPoint
   *,int) */

int __thiscall
RGE_Static_Object::addUserDefinedWaypoint(RGE_Static_Object *this,XYZBYTEPoint *param_1,int param_2)
{
  return 0;
}

// --------------------------------------------------

// Function: removeAllUserDefinedWaypoints
// Address: 0041a600
/* public: virtual void __thiscall RGE_Static_Object::removeAllUserDefinedWaypoints(int) */

void __thiscall
RGE_Static_Object::removeAllUserDefinedWaypoints(RGE_Static_Object *this,int param_1)
{
  return;
}

// --------------------------------------------------

// Function: removeUserDefinedWaypoint
// Address: 0041a610
/* public: virtual void __thiscall RGE_Static_Object::removeUserDefinedWaypoint(int) */

void __thiscall RGE_Static_Object::removeUserDefinedWaypoint(RGE_Static_Object *this,int param_1)
{
  return;
}

// --------------------------------------------------

// Function: numberUserDefinedWaypoints
// Address: 0041a620
/* public: virtual int __thiscall RGE_Static_Object::numberUserDefinedWaypoints(void)const  */

int __thiscall RGE_Static_Object::numberUserDefinedWaypoints(RGE_Static_Object *this)
{
  return 0;
}

// --------------------------------------------------

// Function: findAvoidancePath
// Address: 0041a630
/* public: virtual class Path * __thiscall RGE_Static_Object::findAvoidancePath(struct XYZPoint
   &,float,int) */

Path * __thiscall
RGE_Static_Object::findAvoidancePath
          (RGE_Static_Object *this,XYZPoint *param_1,float param_2,int param_3)
{
  return (Path *)0x0;
}

// --------------------------------------------------

// Function: ~RGE_Static_Object
// Address: 00441a5e
void __thiscall RGE_Static_Object::~RGE_Static_Object(RGE_Static_Object *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_List *this_00;
  int *piVar2;
  RGE_Object_Node *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  pcStack_8 = FUN_0055f9e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  uStack_4 = 1;
  remove_visible_resource(this);
  if (this->owner != (RGE_Player *)0x0) {
    if (this->object_state < 3) {
      take_attribute_from_owner(this);
    }
    if (this->object_state < 7) {
      RGE_Victory_Conditions::update_for_object(this->owner->victory_conditions,this);
    }
  }
  if (this->sprite_list != (RGE_Active_Sprite_List *)0x0) {
    (**(code **)this->sprite_list->_padding_)(1);
    this->sprite_list = (RGE_Active_Sprite_List *)0x0;
  }
  if (this->owner != (RGE_Player *)0x0) {
    if ((this->selected & 1) != 0) {
      RGE_Player::unselect_one_object(this->owner,this);
    }
    (**(code **)(this->owner->_padding_ + 0xe0))
              (this,this->sleep_flag,this->dopple_flag,this->player_object_node);
    this->owner = (RGE_Player *)0x0;
  }
  if (this->tile != (RGE_Tile *)0x0) {
    RGE_Object_List::remove_node(&this->tile->objects,this,(RGE_Object_Node *)0x0);
    this->tile = (RGE_Tile *)0x0;
  }
  if ((this->master_obj != (RGE_Master_Static_Object *)0x0) &&
     ((float)(double)DAT_00574718 < this->master_obj->radius_z)) {
    removeFromObstructionMap(this,2);
  }
  if (this->inside_obj != (RGE_Static_Object *)0x0) {
    RGE_Object_List::remove_node(this->inside_obj->objects,this,(RGE_Object_Node *)0x0);
    this->inside_obj = (RGE_Static_Object *)0x0;
  }
  if (this->objects != (RGE_Object_List *)0x0) {
    pRVar3 = this->objects->list;
    while (pRVar3 != (RGE_Object_Node *)0x0) {
      pRVar1 = pRVar3->next;
      (**(code **)(pRVar3->node->_padding_ + 0xd4))();
      pRVar3 = pRVar1;
    }
    this_00 = this->objects;
    if (this_00 != (RGE_Object_List *)0x0) {
      RGE_Object_List::~RGE_Object_List(this_00);
      operator_delete(this_00);
    }
  }
  if (this->unitAIValue != (UnitAIModule *)0x0) {
    (**(code **)this->unitAIValue->_padding_)(1);
    this->unitAIValue = (UnitAIModule *)0x0;
  }
  piVar2 = (this->groupMembers).value;
  uStack_4 = uStack_4 & 0xffffff00;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (this->groupMembers).value = (int *)0x0;
  }
  (this->groupMembers).numberValue = 0;
  (this->groupMembers).desiredNumberValue = 0;
  (this->groupMembers).maximumSizeValue = 0;
  piVar2 = (this->pathingGroupMembers).value;
  uStack_4 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (this->pathingGroupMembers).value = (int *)0x0;
  }
  (this->pathingGroupMembers).numberValue = 0;
  (this->pathingGroupMembers).desiredNumberValue = 0;
  (this->pathingGroupMembers).maximumSizeValue = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: RGE_Static_Object
// Address: 004c1100
/* public: __thiscall RGE_Static_Object::RGE_Static_Object(class RGE_Master_Static_Object *,class
   RGE_Player *,float,float,float,int) */

RGE_Static_Object * __thiscall
RGE_Static_Object::RGE_Static_Object
          (RGE_Static_Object *this,RGE_Master_Static_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f9a6;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->sprite = (RGE_Sprite *)0x0;
  this->old_sprite = (RGE_Sprite *)0x0;
  (this->pathingGroupMembers).value = (int *)0x0;
  (this->pathingGroupMembers).numberValue = 0;
  (this->pathingGroupMembers).desiredNumberValue = 0;
  (this->pathingGroupMembers).maximumSizeValue = 0;
  (this->groupMembers).value = (int *)0x0;
  (this->groupMembers).numberValue = 0;
  (this->groupMembers).desiredNumberValue = 0;
  (this->groupMembers).maximumSizeValue = 0;
  local_4 = 1;
  this->groupCommanderValue = -1;
  this->zoneMapIndex = -1;
  this->unitAIValue = (UnitAIModule *)0x0;
  this->groupRangeValue = 5.0;
  this->inObstructionMapValue = '\0';
  this->lastInObstructionMapValue = '\0';
  this->underAttackValue = '\0';
  this->_padding_ = (int)&_vftable_;
  this->player_object_node = (RGE_Object_Node *)0x0;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004c11c0
/* public: virtual void * __thiscall RGE_Static_Object::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
RGE_Static_Object::_scalar_deleting_destructor_(RGE_Static_Object *this,uint param_1)
{
  ~RGE_Static_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Static_Object
// Address: 004c11e0
/* public: __thiscall RGE_Static_Object::RGE_Static_Object(int,class RGE_Game_World *,int) */

RGE_Static_Object * __thiscall
RGE_Static_Object::RGE_Static_Object
          (RGE_Static_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055f9c6;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->sprite = (RGE_Sprite *)0x0;
  this->old_sprite = (RGE_Sprite *)0x0;
  (this->pathingGroupMembers).value = (int *)0x0;
  (this->pathingGroupMembers).numberValue = 0;
  (this->pathingGroupMembers).desiredNumberValue = 0;
  (this->pathingGroupMembers).maximumSizeValue = 0;
  (this->groupMembers).value = (int *)0x0;
  (this->groupMembers).numberValue = 0;
  (this->groupMembers).desiredNumberValue = 0;
  (this->groupMembers).maximumSizeValue = 0;
  local_4 = 1;
  this->groupCommanderValue = -1;
  this->zoneMapIndex = -1;
  this->unitAIValue = (UnitAIModule *)0x0;
  this->groupRangeValue = 5.0;
  this->inObstructionMapValue = '\0';
  this->lastInObstructionMapValue = '\0';
  this->underAttackValue = '\0';
  this->_padding_ = (int)&_vftable_;
  this->player_object_node = (RGE_Object_Node *)0x0;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Static_Object
// Address: 004c1290
/* public: virtual __thiscall RGE_Static_Object::~RGE_Static_Object(void) */

void __thiscall RGE_Static_Object::~RGE_Static_Object(RGE_Static_Object *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_List *this_00;
  int *piVar2;
  RGE_Object_Node *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_0055f9e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 1;
  remove_visible_resource(this);
  if (this->owner != (RGE_Player *)0x0) {
    if (this->object_state < 3) {
      take_attribute_from_owner(this);
    }
    if (this->object_state < 7) {
      RGE_Victory_Conditions::update_for_object(this->owner->victory_conditions,this);
    }
  }
  if (this->sprite_list != (RGE_Active_Sprite_List *)0x0) {
    (**(code **)this->sprite_list->_padding_)(1);
    this->sprite_list = (RGE_Active_Sprite_List *)0x0;
  }
  if (this->owner != (RGE_Player *)0x0) {
    if ((this->selected & 1) != 0) {
      RGE_Player::unselect_one_object(this->owner,this);
    }
    (**(code **)(this->owner->_padding_ + 0xe0))
              (this,this->sleep_flag,this->dopple_flag,this->player_object_node);
    this->owner = (RGE_Player *)0x0;
  }
  if (this->tile != (RGE_Tile *)0x0) {
    RGE_Object_List::remove_node(&this->tile->objects,this,(RGE_Object_Node *)0x0);
    this->tile = (RGE_Tile *)0x0;
  }
  if ((this->master_obj != (RGE_Master_Static_Object *)0x0) &&
     ((float)(double)DAT_00574718 < this->master_obj->radius_z)) {
    removeFromObstructionMap(this,2);
  }
  if (this->inside_obj != (RGE_Static_Object *)0x0) {
    RGE_Object_List::remove_node(this->inside_obj->objects,this,(RGE_Object_Node *)0x0);
    this->inside_obj = (RGE_Static_Object *)0x0;
  }
  if (this->objects != (RGE_Object_List *)0x0) {
    pRVar3 = this->objects->list;
    while (pRVar3 != (RGE_Object_Node *)0x0) {
      pRVar1 = pRVar3->next;
      (**(code **)(pRVar3->node->_padding_ + 0xd4))();
      pRVar3 = pRVar1;
    }
    this_00 = this->objects;
    if (this_00 != (RGE_Object_List *)0x0) {
      RGE_Object_List::~RGE_Object_List(this_00);
      operator_delete(this_00);
    }
  }
  if (this->unitAIValue != (UnitAIModule *)0x0) {
    (**(code **)this->unitAIValue->_padding_)(1);
    this->unitAIValue = (UnitAIModule *)0x0;
  }
  piVar2 = (this->groupMembers).value;
  local_4 = local_4 & 0xffffff00;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (this->groupMembers).value = (int *)0x0;
  }
  (this->groupMembers).numberValue = 0;
  (this->groupMembers).desiredNumberValue = 0;
  (this->groupMembers).maximumSizeValue = 0;
  piVar2 = (this->pathingGroupMembers).value;
  local_4 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (this->pathingGroupMembers).value = (int *)0x0;
  }
  (this->pathingGroupMembers).numberValue = 0;
  (this->pathingGroupMembers).desiredNumberValue = 0;
  (this->pathingGroupMembers).maximumSizeValue = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: recycle_in_to_game
// Address: 004c1420
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
/* public: virtual void __thiscall RGE_Static_Object::recycle_in_to_game(class
   RGE_Master_Static_Object *,class RGE_Player *,float,float,float) */

void __thiscall
RGE_Static_Object::recycle_in_to_game
          (RGE_Static_Object *this,RGE_Master_Static_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  int iVar1;
  RGE_Sound *this_00;
  RGE_Object_Node *pRVar2;
  uint uVar3;
  float fVar4;
  
  this->old_sprite = (RGE_Sprite *)0x0;
  this->unitAIValue = (UnitAIModule *)0x0;
  this->underAttackValue = '\0';
  this->sprite = (RGE_Sprite *)0x0;
  this->groupCommanderValue = -1;
  this->groupRangeValue = 5.0;
  this->owner = param_2;
  this->master_obj = param_1;
  this->tile = (RGE_Tile *)0x0;
  this->inside_obj = (RGE_Static_Object *)0x0;
  fVar4 = (float)(int)param_1->hp;
  this->hp = (float)(int)fVar4;
  this->sleep_flag = DAT_00574718._8_4_ < (float)(int)fVar4;
  this->dopple_flag = param_1->master_type == '\x19';
  this->facet = '\0';
  this->world_x = -999.0;
  this->world_y = -999.0;
  this->world_z = 0.0;
  this->screen_x_offset = 0;
  this->screen_y_offset = 0;
  this->shadow_x_offset = 0;
  this->shadow_y_offset = 0;
  this->selected = '\0';
  this->selected_group = '\0';
  this->worker_num = '\0';
  this->object_state = '\x02';
  this->curr_damage_percent = '\0';
  this->goto_sleep_flag = '\0';
  this->player_object_node = (RGE_Object_Node *)0x0;
  get_starting_attribute(this);
  give_attribute_to_owner(this);
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0x38))(this->master_obj->sprite);
  this->world_x = fVar4;
  this->world_z = param_4;
  this->world_y = param_3;
  this->old_sprite = (RGE_Sprite *)0x0;
  (**(code **)(iVar1 + 0x34))(fVar4,param_3,param_4);
  pRVar2 = (RGE_Object_Node *)
           (**(code **)(this->owner->_padding_ + 0xdc))(this,this->sleep_flag,this->dopple_flag);
  this->player_object_node = pRVar2;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x183);
  iVar1 = debug_random_on;
  debug_random_on = 0;
  this_00 = this->master_obj->created_sound;
  if ((this_00 != (RGE_Sound *)0x0) && (this->owner->id == this->owner->world->curr_player)) {
    RGE_Sound::play(this_00,1);
  }
  debug_random_on = iVar1;
  debug_srand(s_C__msdev_work_age1_x1_stat_obj_c,0x18d,uVar3);
  return;
}

// --------------------------------------------------

// Function: recycle_out_of_game
// Address: 004c1590
/* public: virtual void __thiscall RGE_Static_Object::recycle_out_of_game(void) */

void __thiscall RGE_Static_Object::recycle_out_of_game(RGE_Static_Object *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_Node *pRVar2;
  uchar uVar3;
  
  if ((this->master_obj->recyclable != '\0') &&
     (uVar3 = RGE_Game_World::recycle_object_out_of_game
                        (this->owner->world,this->master_obj->master_type,this), uVar3 != '\0')) {
    if (this->object_state < 3) {
      take_attribute_from_owner(this);
    }
    if (this->object_state < 7) {
      RGE_Victory_Conditions::update_for_object(this->owner->victory_conditions,this);
    }
    if (this->sprite_list != (RGE_Active_Sprite_List *)0x0) {
      RGE_Active_Sprite_List::delete_list(this->sprite_list);
    }
    if (this->owner != (RGE_Player *)0x0) {
      if ((this->selected & 1) != 0) {
        RGE_Player::unselect_one_object(this->owner,this);
      }
      (**(code **)(this->owner->_padding_ + 0xe0))
                (this,this->sleep_flag,this->dopple_flag,this->player_object_node);
      this->owner = (RGE_Player *)0x0;
    }
    if (this->tile != (RGE_Tile *)0x0) {
      RGE_Object_List::remove_node(&this->tile->objects,this,(RGE_Object_Node *)0x0);
      this->tile = (RGE_Tile *)0x0;
    }
    if (this->inside_obj != (RGE_Static_Object *)0x0) {
      RGE_Object_List::remove_node(this->inside_obj->objects,this,(RGE_Object_Node *)0x0);
      this->inside_obj = (RGE_Static_Object *)0x0;
    }
    if (this->objects != (RGE_Object_List *)0x0) {
      pRVar2 = this->objects->list;
      while (pRVar2 != (RGE_Object_Node *)0x0) {
        pRVar1 = pRVar2->next;
        (**(code **)(pRVar2->node->_padding_ + 0xd4))();
        pRVar2 = pRVar1;
      }
    }
    if (this->unitAIValue != (UnitAIModule *)0x0) {
      (**(code **)this->unitAIValue->_padding_)(1);
      this->unitAIValue = (UnitAIModule *)0x0;
    }
    if ((this->master_obj != (RGE_Master_Static_Object *)0x0) &&
       ((float)(double)DAT_00574718 < this->master_obj->radius_z)) {
      removeFromObstructionMap(this,2);
    }
    this->master_obj = (RGE_Master_Static_Object *)0x0;
    return;
  }
  if (this != (RGE_Static_Object *)0x0) {
    (**(code **)this->_padding_)(1);
  }
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 004c16b0
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
/* protected: virtual int __thiscall RGE_Static_Object::setup(class RGE_Master_Static_Object *,class
   RGE_Player *,float,float,float) */

int __thiscall
RGE_Static_Object::setup
          (RGE_Static_Object *this,RGE_Master_Static_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  int iVar1;
  RGE_Sound *this_00;
  RGE_Object_List *pRVar2;
  long lVar3;
  RGE_Active_Sprite_List *pRVar4;
  RGE_Object_Node *pRVar5;
  uint uVar6;
  float fVar7;
  
  iVar1 = this->_padding_;
  this->master_obj = param_1;
  this->type = '\n';
  this->owner = param_2;
  this->tile = (RGE_Tile *)0x0;
  this->inside_obj = (RGE_Static_Object *)0x0;
  pRVar2 = (RGE_Object_List *)(**(code **)(iVar1 + 0x1e0))();
  this->objects = pRVar2;
  fVar7 = (float)(int)this->master_obj->hp;
  this->hp = (float)(int)fVar7;
  this->sleep_flag = DAT_00574718._8_4_ < (float)(int)fVar7;
  this->dopple_flag = this->master_obj->master_type == '\x19';
  this->facet = '\0';
  this->world_x = -999.0;
  this->world_y = -999.0;
  this->world_z = 0.0;
  this->screen_x_offset = 0;
  this->screen_y_offset = 0;
  this->shadow_x_offset = 0;
  this->shadow_y_offset = 0;
  this->selected = '\0';
  this->selected_group = '\0';
  this->worker_num = '\0';
  this->object_state = '\x02';
  this->curr_damage_percent = '\0';
  this->goto_sleep_flag = '\0';
  get_starting_attribute(this);
  give_attribute_to_owner(this);
  if (this->master_obj->recyclable == '\0') {
    lVar3 = RGE_Game_World::get_next_object_id(this->owner->world);
  }
  else {
    lVar3 = RGE_Game_World::get_next_reusable_object_id(this->owner->world);
  }
  this->id = lVar3;
  pRVar4 = (RGE_Active_Sprite_List *)(**(code **)(iVar1 + 0x1e4))();
  this->sprite_list = pRVar4;
  (**(code **)(iVar1 + 0x38))(this->master_obj->sprite);
  this->world_x = fVar7;
  this->world_z = param_4;
  this->world_y = param_3;
  this->old_sprite = (RGE_Sprite *)0x0;
  (**(code **)(iVar1 + 0x34))(fVar7,param_3,param_4);
  pRVar5 = (RGE_Object_Node *)
           (**(code **)(this->owner->_padding_ + 0xdc))(this,this->sleep_flag,this->dopple_flag);
  this->player_object_node = pRVar5;
  uVar6 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x22a);
  iVar1 = debug_random_on;
  debug_random_on = 0;
  this_00 = this->master_obj->created_sound;
  if ((this_00 != (RGE_Sound *)0x0) && (this->owner->id == this->owner->world->curr_player)) {
    RGE_Sound::play(this_00,1);
  }
  debug_random_on = iVar1;
  debug_srand(s_C__msdev_work_age1_x1_stat_obj_c,0x235,uVar6);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 004c1840
/* WARNING: Variable defined which should be unmapped: temp_float */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall RGE_Static_Object::setup(int,class RGE_Game_World *) */

int __thiscall RGE_Static_Object::setup(RGE_Static_Object *this,int param_1,RGE_Game_World *param_2)
{
  int iVar1;
  int iVar2;
  RGE_Game_World *pRVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  RGE_Active_Sprite_List *this_00;
  RGE_Object_List *pRVar7;
  float temp_float;
  int numberUnits;
  uchar byte_val;
  long long_val;
  int tempInt;
  int tempInt_fffffff8;
  int local_4;
  
  iVar2 = param_1;
  this->type = '\n';
  rge_read(param_1,&long_val,1);
  pRVar3 = param_2;
  this->owner = param_2->players[long_val & 0xff];
  rge_read(iVar2,&param_1,2);
  this->master_obj = this->owner->master_objects[(short)param_1];
  rge_read(iVar2,&param_1,2);
  if ((short)param_1 < 0) {
    this->sprite = (RGE_Sprite *)0x0;
  }
  else {
    this->sprite = pRVar3->sprites[(short)param_1];
  }
  this->old_sprite = (RGE_Sprite *)0x0;
  rge_read(iVar2,&tempInt,4);
  if (tempInt == -1) {
    this->inside_obj = (RGE_Static_Object *)0x0;
  }
  else {
    this->inside_obj = (RGE_Static_Object *)tempInt;
  }
  rge_read(iVar2,&this->hp,4);
  rge_read(iVar2,&this->object_state,1);
  rge_read(iVar2,&this->sleep_flag,1);
  if (_DAT_00574724 <= save_game_version) {
    rge_read(iVar2,&this->dopple_flag,1);
  }
  rge_read(iVar2,&this->goto_sleep_flag,1);
  rge_read(iVar2,&this->id,4);
  rge_read(iVar2,&this->facet,1);
  rge_read(iVar2,&this->world_x,4);
  rge_read(iVar2,&this->world_y,4);
  rge_read(iVar2,&this->world_z,4);
  rge_read(iVar2,&this->screen_x_offset,2);
  rge_read(iVar2,&this->screen_y_offset,2);
  rge_read(iVar2,&this->shadow_x_offset,2);
  rge_read(iVar2,&this->shadow_y_offset,2);
  rge_read(iVar2,&this->selected_group,1);
  rge_read(iVar2,&this->attribute_type_held,2);
  rge_read(iVar2,&this->attribute_amount_held,4);
  rge_read(iVar2,&this->worker_num,1);
  rge_read(iVar2,&this->curr_damage_percent,1);
  rge_read(iVar2,&this->underAttackValue,1);
  this->tile = (RGE_Tile *)0x0;
  rge_read(iVar2,&this->groupCommanderValue,4);
  rge_read(iVar2,&this->groupRangeValue,4);
  if (save_game_version == _DAT_00574728) {
    rge_read(iVar2,&numberUnits,4);
    rge_read(iVar2,&numberUnits,4);
    rge_read(iVar2,&numberUnits,4);
    rge_read(iVar2,&local_4,4);
    rge_read(iVar2,&tempInt_fffffff8,4);
    rge_read(iVar2,&tempInt_fffffff8,4);
  }
  rge_read(iVar2,&byte_val,4);
  numberUnits = 0;
  if (0 < _byte_val) {
    do {
      rge_read(iVar2,&tempInt_fffffff8,4);
      iVar1 = (this->groupMembers).numberValue;
      iVar4 = 0;
      local_4 = tempInt_fffffff8;
      if (0 < iVar1) {
        do {
          if ((this->groupMembers).maximumSizeValue <= iVar4) break;
          if ((this->groupMembers).value[iVar4] == tempInt_fffffff8) goto LAB_004c1b80;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
      }
      if ((this->groupMembers).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar5 = (int *)operator_new(iVar1 * 4);
        if (piVar5 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->groupMembers).maximumSizeValue) {
            do {
              if (iVar1 <= iVar4) break;
              iVar6 = iVar4 + 1;
              piVar5[iVar4] = (this->groupMembers).value[iVar4];
              iVar4 = iVar6;
            } while (iVar6 < (this->groupMembers).maximumSizeValue);
          }
          operator_delete((this->groupMembers).value);
          (this->groupMembers).value = piVar5;
          (this->groupMembers).maximumSizeValue = iVar1;
        }
      }
      (this->groupMembers).value[(this->groupMembers).numberValue] = local_4;
      (this->groupMembers).numberValue = (this->groupMembers).numberValue + 1;
LAB_004c1b80:
      numberUnits = numberUnits + 1;
    } while (numberUnits < _byte_val);
  }
  rge_read(iVar2,&byte_val,4);
  numberUnits = 0;
  if (0 < _byte_val) {
    do {
      rge_read(iVar2,&local_4,4);
      iVar1 = (this->pathingGroupMembers).numberValue;
      iVar4 = 0;
      tempInt_fffffff8 = local_4;
      if (0 < iVar1) {
        do {
          if ((this->pathingGroupMembers).maximumSizeValue <= iVar4) break;
          if ((this->pathingGroupMembers).value[iVar4] == local_4) goto LAB_004c1c56;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
      }
      if ((this->pathingGroupMembers).maximumSizeValue + -1 < iVar1) {
        iVar1 = iVar1 + 1;
        piVar5 = (int *)operator_new(iVar1 * 4);
        if (piVar5 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (this->pathingGroupMembers).maximumSizeValue) {
            do {
              if (iVar1 <= iVar4) break;
              iVar6 = iVar4 + 1;
              piVar5[iVar4] = (this->pathingGroupMembers).value[iVar4];
              iVar4 = iVar6;
            } while (iVar6 < (this->pathingGroupMembers).maximumSizeValue);
          }
          operator_delete((this->pathingGroupMembers).value);
          (this->pathingGroupMembers).value = piVar5;
          (this->pathingGroupMembers).maximumSizeValue = iVar1;
        }
      }
      (this->pathingGroupMembers).value[(this->pathingGroupMembers).numberValue] = tempInt_fffffff8;
      (this->pathingGroupMembers).numberValue = (this->pathingGroupMembers).numberValue + 1;
LAB_004c1c56:
      numberUnits = numberUnits + 1;
    } while (numberUnits < _byte_val);
  }
  iVar1 = this->_padding_;
  this_00 = (RGE_Active_Sprite_List *)(**(code **)(iVar1 + 0x1e4))();
  this->sprite_list = this_00;
  RGE_Active_Sprite_List::load(this_00,iVar2,param_2->sprites);
  (**(code **)(this->owner->world->_padding_ + 0xf8))(this);
  if (this->sleep_flag == '\0') {
    if (this->dopple_flag == '\0') {
      pRVar7 = this->owner->objects;
    }
    else {
      pRVar7 = this->owner->doppleganger_objects;
    }
  }
  else {
    pRVar7 = this->owner->sleeping_objects;
  }
  RGE_Object_List::add_node(pRVar7,this);
  pRVar7 = (RGE_Object_List *)(**(code **)(iVar1 + 0x1e0))();
  this->objects = pRVar7;
  this->selected = '\0';
  return 1;
}

// --------------------------------------------------

// Function: getSpeed
// Address: 004c1ce0
/* public: virtual float __thiscall RGE_Static_Object::getSpeed(void)const  */

float __thiscall RGE_Static_Object::getSpeed(RGE_Static_Object *this)
{
  return DAT_00574718._8_4_;
}

// --------------------------------------------------

// Function: change_unique_id
// Address: 004c1cf0
/* public: void __thiscall RGE_Static_Object::change_unique_id(void) */

void __thiscall RGE_Static_Object::change_unique_id(RGE_Static_Object *this)
{
  long lVar1;
  RGE_Object_Node *pRVar2;
  
  (**(code **)(this->owner->_padding_ + 0xe0))
            (this,this->sleep_flag,this->dopple_flag,this->player_object_node);
  if (this->master_obj->recyclable == '\0') {
    lVar1 = RGE_Game_World::get_next_object_id(this->owner->world);
  }
  else {
    lVar1 = RGE_Game_World::get_next_reusable_object_id(this->owner->world);
  }
  this->id = lVar1;
  pRVar2 = (RGE_Object_Node *)
           (**(code **)(this->owner->_padding_ + 0xdc))(this,this->sleep_flag,this->dopple_flag);
  this->player_object_node = pRVar2;
  return;
}

// --------------------------------------------------

// Function: create_object_list
// Address: 004c1d60
/* protected: virtual class RGE_Object_List * __thiscall RGE_Static_Object::create_object_list(void)
    */

RGE_Object_List * __thiscall RGE_Static_Object::create_object_list(RGE_Static_Object *this)
{
  RGE_Object_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f9fb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 0;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    pRVar1 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Object_List *)0x0;
}

// --------------------------------------------------

// Function: create_sprite_list
// Address: 004c1dc0
/* protected: virtual class RGE_Active_Sprite_List * __thiscall
   RGE_Static_Object::create_sprite_list(void) */

RGE_Active_Sprite_List * __thiscall RGE_Static_Object::create_sprite_list(RGE_Static_Object *this)
{
  RGE_Active_Sprite_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fa1b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Active_Sprite_List *)operator_new(0xc);
  local_4 = 0;
  if (pRVar1 != (RGE_Active_Sprite_List *)0x0) {
    pRVar1 = (RGE_Active_Sprite_List *)RGE_Active_Sprite_List::RGE_Active_Sprite_List(pRVar1,this);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Active_Sprite_List *)0x0;
}

// --------------------------------------------------

// Function: get_starting_attribute
// Address: 004c1e20
/* public: void __thiscall RGE_Static_Object::get_starting_attribute(void) */

void __thiscall RGE_Static_Object::get_starting_attribute(RGE_Static_Object *this)
{
  RGE_Master_Static_Object *pRVar1;
  short *psVar2;
  int iVar3;
  float *pfVar4;
  uchar *puVar5;
  
  pRVar1 = this->master_obj;
  this->attribute_type_held = -1;
  this->attribute_amount_held = 0.0;
  puVar5 = pRVar1->attribute_flag;
  pfVar4 = pRVar1->attribute_amount_held;
  psVar2 = pRVar1->attribute_type_held;
  iVar3 = 3;
  do {
    if ((*puVar5 == '\0') && (*psVar2 != -1)) {
      this->attribute_type_held = *psVar2;
      this->attribute_amount_held = *pfVar4;
    }
    psVar2 = psVar2 + 1;
    pfVar4 = pfVar4 + 1;
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// --------------------------------------------------

// Function: give_attribute_to_owner
// Address: 004c1e70
/* public: void __thiscall RGE_Static_Object::give_attribute_to_owner(void) */

void __thiscall RGE_Static_Object::give_attribute_to_owner(RGE_Static_Object *this)
{
  short sVar1;
  RGE_Master_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar4 = 0;
  local_4 = 0x6a;
  iVar3 = 0x70;
  do {
    pRVar2 = this->master_obj;
    if (((pRVar2->attribute_flag[iVar4] != 0) && (pRVar2->attribute_flag[iVar4] < 3)) &&
       (sVar1 = *(short *)((int)pRVar2->attribute_type_held + local_4 + -0x6a), -1 < sVar1)) {
      (**(code **)(this->owner->_padding_ + 0x78))
                (sVar1,*(undefined4 *)((int)pRVar2->attribute_type_held + iVar3 + -0x6a),0);
    }
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
    local_4 = local_4 + 2;
  } while (iVar3 < 0x7c);
  return;
}

// --------------------------------------------------

// Function: take_attribute_from_owner
// Address: 004c1ed0
/* public: void __thiscall RGE_Static_Object::take_attribute_from_owner(void) */

void __thiscall RGE_Static_Object::take_attribute_from_owner(RGE_Static_Object *this)
{
  short sVar1;
  RGE_Master_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = 0x6a;
                    /* language.dll match for 0x70: "B" */
  iVar4 = 0x70;
  do {
    pRVar2 = this->master_obj;
    if ((pRVar2->attribute_flag[iVar5] == '\x02') &&
       (sVar1 = *(short *)((int)pRVar2->attribute_type_held + iVar3 + -0x6a), -1 < sVar1)) {
      (**(code **)(this->owner->_padding_ + 0x78))
                (sVar1,-*(float *)((int)pRVar2->attribute_type_held + iVar4 + -0x6a),0);
    }
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + 1;
    iVar3 = iVar3 + 2;
  } while (iVar4 < 0x7c);
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 004c1f30
/* public: virtual void __thiscall RGE_Static_Object::draw(class TDrawArea *,short,short,class
   RGE_Color_Table *) */

void __thiscall
RGE_Static_Object::draw
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3,
          RGE_Color_Table *param_4)
{
  SDI_Object_ID = this->id;
  if (this->type == '\x19') {
    if (((uint)this[1].tile & 1 << ((byte)this->owner->world->curr_player & 0x1f)) != 0) {
      SDI_Object_ID = -1;
      return;
    }
    if (this[1].id == 0) {
      SDI_Object_ID = -1;
    }
    else {
      SDI_Object_ID = *(long *)(this[1].id + 4);
    }
  }
  if ((this->tile != (RGE_Tile *)0x0) && (this->object_state < 7)) {
    if (((this->selected != '\0') || (rge_base_game->outline_type == '\x03')) ||
       (((this->master_obj->draw_flag & 1) == 1 && (rge_base_game->prog_mode == 7)))) {
      capture_frame(this,param_1,param_2,param_3);
    }
    SDI_Draw_Line = (int)param_3 + (int)this->shadow_y_offset;
    (**(code **)(this->sprite_list->_padding_ + 0xc))
              (this->facet,this->screen_x_offset + param_2,this->screen_y_offset + param_3,
               this->shadow_x_offset + param_2,param_3 + this->shadow_y_offset,param_4,param_1);
  }
                    /* Symbol Ref: {@symbol sod_exit} */
  SDI_Object_ID = -1;
  return;
}

// --------------------------------------------------

// Function: shadow_draw
// Address: 004c2030
/* public: virtual void __thiscall RGE_Static_Object::shadow_draw(class TDrawArea
   *,short,short,unsigned char) */

void __thiscall
RGE_Static_Object::shadow_draw
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3,uchar param_4)
{
  RGE_Color_Table *pRVar1;
  undefined2 uVar2;
  undefined3 in_stack_00000011;
  
  if ((this->tile != (RGE_Tile *)0x0) && (this->object_state < 7)) {
    pRVar1 = this->owner->color_table;
    uVar2 = (undefined2)((uint)pRVar1 >> 0x10);
    (**(code **)(this->sprite_list->_padding_ + 0x14))
              (this->facet,CONCAT22(uVar2,this->shadow_x_offset + param_2),
               CONCAT22(uVar2,this->shadow_y_offset + param_3),pRVar1,param_1,_param_4);
  }
  return;
}

// --------------------------------------------------

// Function: normal_draw
// Address: 004c2080
/* public: virtual void __thiscall RGE_Static_Object::normal_draw(class TDrawArea *,short,short) */

void __thiscall
RGE_Static_Object::normal_draw
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  RGE_Color_Table *pRVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined4 unaff_EBP;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  if ((this->tile != (RGE_Tile *)0x0) && (this->object_state < 7)) {
    if ((this->selected == '\0') && (rge_base_game->outline_type != '\x03')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      (**(code **)(this->_padding_ + 0x1c))(param_1,_param_2,_param_3);
    }
    pRVar1 = this->owner->color_table;
    uVar3 = (undefined2)((uint)pRVar1 >> 0x10);
    (**(code **)(this->sprite_list->_padding_ + 0x10))
              (CONCAT22(uVar3,(ushort)this->facet),CONCAT22(uVar3,this->screen_x_offset + param_2),
               CONCAT22(uVar3,this->screen_y_offset + param_3),pRVar1,param_1);
    if (bVar2) {
      (**(code **)(this->_padding_ + 0x18))(param_1,_param_2,unaff_EBP);
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw_front_frame
// Address: 004c2110
/* public: virtual void __thiscall RGE_Static_Object::draw_front_frame(class TDrawArea
   *,short,short) */

void __thiscall
RGE_Static_Object::draw_front_frame
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  if (rge_base_game->game_mode != 1) {
    switch(rge_base_game->outline_type) {
    case '\0':
      (**(code **)(this->_padding_ + 0x20))(param_1,_param_2,_param_3);
      return;
    case '\x01':
      draw_frame_3d_cube_front(this,param_1,param_2,param_3);
      return;
    case '\x02':
    case '\x03':
      draw_frame_3d_square_front(this,param_1,param_2,param_3);
    }
    return;
  }
  draw_frame_3d_cube_front(this,param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: draw_back_frame
// Address: 004c21a0
/* public: virtual void __thiscall RGE_Static_Object::draw_back_frame(class TDrawArea *,short,short)
    */

void __thiscall
RGE_Static_Object::draw_back_frame
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  if (rge_base_game->game_mode == 1) {
    draw_frame_3d_cube_back(this,param_1,param_2,param_3);
    return;
  }
  switch(rge_base_game->outline_type) {
  case '\x01':
    draw_frame_3d_cube_back(this,param_1,param_2,param_3);
    return;
  case '\x02':
  case '\x03':
    draw_frame_3d_square_back(this,param_1,param_2,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: capture_frame
// Address: 004c2220
/* public: void __thiscall RGE_Static_Object::capture_frame(class TDrawArea *,short,short) */

void __thiscall
RGE_Static_Object::capture_frame
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  if (SDI_Capture_Info != 0) {
    if (rge_base_game->game_mode == 1) {
      capture_frame_3d_cube(this,param_1,param_2,param_3);
      return;
    }
    switch(rge_base_game->outline_type) {
    case '\0':
      capture_square_frame(this,param_1,param_2,param_3);
      return;
    case '\x01':
      capture_frame_3d_cube(this,param_1,param_2,param_3);
      return;
    case '\x02':
    case '\x03':
      capture_frame_3d_square(this,param_1,param_2,param_3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: capture_square_frame
// Address: 004c22c0
/* WARNING: Variable defined which should be unmapped: min_x */
/* public: void __thiscall RGE_Static_Object::capture_square_frame(class TDrawArea *,short,short) */

void __thiscall
RGE_Static_Object::capture_square_frame
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar5;
  short unaff_retaddr;
  short min_x;
  short min_y;
  short max_y;
  short max_x;
  
  if ((this->sprite != (RGE_Sprite *)0x0) && (this->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    _min_x = unaff_EBX;
    (**(code **)(this->sprite_list->_padding_ + 0x28))(this->sprite,this->facet);
    iVar3 = get_frame(this,(short *)&stack0xfffffff0,(short *)&stack0xfffffff2,&min_y,&min_x);
    if (iVar3 != 0) {
      iVar3 = (int)(short)unaff_EBP + (int)unaff_retaddr + -1 + (int)this->screen_x_offset;
      iVar1 = (int)(short)((uint)unaff_EBP >> 0x10) + (int)(short)param_1 + -1 +
              (int)this->screen_y_offset;
      iVar2 = (int)min_x + (int)(short)param_1 + 1 + (int)this->screen_y_offset;
      DClipInfo_List::AddGDINode
                (SDI_List,4,iVar2,iVar3,iVar1,
                 (int)min_y + (int)unaff_retaddr + 1 + (int)this->screen_x_offset,iVar2,0,0,0,0,10,
                 0xff,SDI_Object_ID);
      if (this->object_state < 3) {
        iVar4 = __ftol();
        if (iVar4 < 1) {
          iVar4 = 0;
        }
        iVar5 = (int)this->master_obj->hp;
        if (0 < iVar5) {
          iVar4 = (iVar4 * 0x19) / iVar5 + iVar3;
          if (iVar3 + 0x1a <= iVar4) {
            iVar4 = iVar3 + 0x19;
          }
          DClipInfo_List::AddGDINode
                    (SDI_List,2,iVar2,iVar3,iVar1 + -6,iVar3 + 0x1a,iVar1 + -1,iVar4,0,iVar4 + 1,0,
                     0x14,0xff,SDI_Object_ID);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: capture_frame_3d_cube
// Address: 004c23f0
/* public: void __thiscall RGE_Static_Object::capture_frame_3d_cube(class TDrawArea *,short,short)
    */

void __thiscall
RGE_Static_Object::capture_frame_3d_cube
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  return;
}

// --------------------------------------------------

// Function: capture_frame_3d_square
// Address: 004c2400
/* WARNING: Variable defined which should be unmapped: draw_color */
/* public: void __thiscall RGE_Static_Object::capture_frame_3d_square(class TDrawArea *,short,short)
    */

void __thiscall
RGE_Static_Object::capture_frame_3d_square
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Map *this_00;
  TShape *pTVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  short sVar8;
  short sVar9;
  uchar draw_color;
  short y2;
  float rx1;
  short x3;
  short x4;
  short y3;
  float ry1;
  float local_3c;
  short y1;
  int local_34;
  int tot_hp;
  short x1;
  TShape *group_num_shape;
  short x0;
  short y0;
  int idv [6];
  
  pRVar1 = this->master_obj;
  this_00 = this->owner->world->map;
  if (rge_base_game->outline_type == '\x03') {
    _x3 = pRVar1->radius_x;
    local_3c = pRVar1->radius_y;
    _x1 = pRVar1->radius_z;
  }
  else {
    _x3 = pRVar1->outline_radius_x;
    local_3c = pRVar1->outline_radius_y;
    _x1 = pRVar1->outline_radius_z;
  }
  if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (-1 < this->id)) {
    _y2 = 0;
    goto LAB_004c24b2;
  }
  if ((this->selected & 1) == 0) {
    if (rge_base_game->outline_type == '\x03') {
      _y2 = 0x74;
      goto LAB_004c24b2;
    }
    if (((pRVar1->draw_flag & 1) == 1) && (rge_base_game->prog_mode == 7)) {
      _y2 = (uint)pRVar1->draw_color;
      goto LAB_004c24b2;
    }
  }
  _y2 = 0xff;
LAB_004c24b2:
  if ((this->selected & 2) != 0) {
    _y2 = 0x4a;
  }
  if ((this->selected & 4) != 0) {
    _y2 = 0x97;
  }
  _y1 = -local_3c;
  sVar9 = param_3 + this->screen_y_offset;
  sVar8 = param_2 + this->screen_x_offset;
  _x0 = this_00;
  RGE_Map::get_point(this_00,(short *)&group_num_shape,(short *)&local_34,_x3,_y1,0.0,sVar8,sVar9);
  RGE_Map::get_point(this_00,&param_3,(short *)&rx1,_x3,local_3c,0.0,sVar8,sVar9);
  tot_hp = (int)-_x3;
  RGE_Map::get_point(this_00,&x4,(short *)&ry1,(float)tot_hp,local_3c,0.0,sVar8,sVar9);
  RGE_Map::get_point(this_00,&y3,&param_2,(float)tot_hp,_y1,0.0,sVar8,sVar9);
  tot_hp = _y2;
  iVar4 = (int)sVar9;
  DClipInfo_List::AddGDINode
            (SDI_List,1,iVar4,(int)(short)group_num_shape,(int)(short)local_34,(int)param_3,
             (int)rx1._0_2_,(int)x4,(int)ry1._0_2_,(int)y3,(int)param_2,10,_y2,SDI_Object_ID);
  if (((this->selected != '\0') && (this->selected_group != 0)) &&
     ((this->selected_group < 10 &&
      ((this->owner->id == this->owner->world->curr_player &&
       (pTVar2 = RGE_Base_Game::get_shape(rge_base_game,0), pTVar2 != (TShape *)0x0)))))) {
    DClipInfo_List::AddDrawNode
              (SDI_List,pTVar2->FShape,(Shape_Info *)(pTVar2->FShape + this->selected_group),iVar4,
               y3 + -6,param_2 + -8,0,(uchar *)0x0,0,0x1e,SDI_Object_ID);
  }
  if ((((this->selected & 1) == 1) && ((this->master_obj->draw_flag & 2) == 0)) &&
     (local_3c = (float)__ftol(), 0 < (int)local_3c)) {
    RGE_Map::get_point(_x0,&y0,(short *)idv,_x3,_y1,_x1,sVar8,sVar9);
    if ((int)local_3c < 1) {
      local_3c = 0.0;
    }
    _x1 = (float)(int)this->master_obj->hp;
    if (0 < (int)_x1) {
      group_num_shape = (TShape *)(_y0 + -0xc);
      rx1 = (float)(idv[0] + -1);
      _param_3 = _y0 + 0xb;
      local_34 = idv[0] + -2;
      if (local_3c == _x1) {
        ry1 = 1.4013e-45;
        _y3 = (TShape *)0xffffffff;
        _param_2 = 0;
        _x4 = _param_3;
      }
      else {
        if (local_3c == 0.0) {
          _x4 = -1;
          ry1 = 0.0;
          _y3 = group_num_shape;
        }
        else {
          ry1 = 1.4013e-45;
          _x4 = (int)&group_num_shape->shape + ((int)local_3c * 0x18) / (int)_x1;
          if ((short)_param_3 <= (short)_x4) {
            _x4 = _y0 + 10;
          }
          _y3 = (TShape *)(_x4 + 1);
        }
        _param_2 = 1;
      }
      DClipInfo_List::AddGDINode
                (SDI_List,2,iVar4,(int)(short)group_num_shape,(int)(short)local_34,
                 (int)(short)_param_3,(int)rx1._0_2_,(int)(short)_x4,(int)ry1._0_2_,(int)(short)_y3,
                 (int)param_2,0x1e,tot_hp,SDI_Object_ID);
    }
  }
  if (rge_base_game->display_selected_ids != 0) {
    _x0 = (RGE_Map *)RGE_Base_Game::get_shape(rge_base_game,0);
    iVar7 = this->id;
    iVar3 = iVar7;
    if (iVar7 < 0) {
      iVar3 = -iVar7;
    }
    idv[1] = iVar3 / 10000;
    idv[2] = (iVar3 % 10000) / 1000;
    iVar3 = (iVar3 % 10000) % 1000;
    idv[3] = iVar3 / 100;
    iVar3 = iVar3 % 100;
    idv[4] = iVar3 / 10;
    idv[5] = iVar3 % 10;
    uVar6 = (uint)(iVar7 < 10000);
    if (iVar7 < 1000) {
      uVar6 = 2;
    }
    if (iVar7 < 100) {
      uVar6 = 3;
    }
    if (iVar7 < 10) {
      uVar6 = 4;
    }
    if (iVar7 < 0) {
      _param_3 = _param_3 + 7;
      DClipInfo_List::AddGDINode
                (SDI_List,4,iVar4,(short)_param_3 + 1,rx1._0_2_ + 3,(short)_param_3 + 5,
                 rx1._0_2_ + 3,0,0,0,0,0x1e,0x97,SDI_Object_ID);
    }
    if (uVar6 < 5) {
      piVar5 = idv + uVar6 + 1;
      iVar7 = 5 - uVar6;
      do {
        _param_3 = _param_3 + 7;
        sVar8 = (short)_param_3;
        if (*piVar5 == 0) {
          DClipInfo_List::AddGDINode
                    (SDI_List,4,iVar4,sVar8 + 1,(int)rx1._0_2_,sVar8 + 5,rx1._0_2_ + 5,0,0,0,0,0x1e,
                     0xff,SDI_Object_ID);
        }
        else {
          DClipInfo_List::AddDrawNode
                    (SDI_List,((TShape *)_x0)->FShape,
                     (Shape_Info *)(((TShape *)_x0)->FShape + *piVar5),iVar4,(int)sVar8,
                     (int)rx1._0_2_,0,(uchar *)0x0,0,0x1e,SDI_Object_ID);
        }
        piVar5 = piVar5 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw_frame_3d_square_back
// Address: 004c2970
// [HELPER] s_stat_obj__draw_frame_3d_square_b: "stat_obj::draw_frame_3d_square_back"
/* WARNING: Variable defined which should be unmapped: y1 */
/* public: void __thiscall RGE_Static_Object::draw_frame_3d_square_back(class TDrawArea
   *,short,short) */

void __thiscall
RGE_Static_Object::draw_frame_3d_square_back
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  RGE_Map *this_00;
  float fVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  short sVar5;
  short sVar6;
  short y1;
  short x1;
  short y2;
  short x2;
  float rx1;
  float ry1;
  float local_4;
  
  this_00 = this->owner->world->map;
  ry1 = this->master_obj->outline_radius_x;
  local_4 = this->master_obj->outline_radius_y;
  iVar2 = (**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (iVar2 != 0) {
    TDrawArea::Unlock(param_1,s_stat_obj__draw_frame_3d_square_b);
    pvVar3 = TDrawArea::GetDc(param_1,s_stat_obj__draw_frame_3d_square_b);
    if (pvVar3 != (void *)0x0) {
      SelectClipRgn(param_1->DrawDc,*(undefined4 *)(iVar2 + 0x88));
      if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (-1 < this->id)) {
        uVar4 = GetStockObject(7);
        pvVar3 = param_1->DrawDc;
      }
      else {
        uVar4 = GetStockObject(6);
        pvVar3 = param_1->DrawDc;
      }
      SelectObject(pvVar3,uVar4);
      fVar1 = -local_4;
      sVar6 = param_3 + this->screen_y_offset;
      sVar5 = param_2 + this->screen_x_offset;
      RGE_Map::get_point(this_00,&x2,&y2,ry1,fVar1,0.0,sVar5,sVar6);
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,ry1,local_4,0.0,sVar5,sVar6)
      ;
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)rx1._2_2_,(int)rx1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,ry1,fVar1,0.0,sVar5,sVar6);
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,-ry1,fVar1,0.0,sVar5,sVar6);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)rx1._2_2_,(int)rx1._0_2_);
      SelectClipRgn(param_1->DrawDc,0);
      TDrawArea::ReleaseDc(param_1,s_stat_obj__draw_frame_3d_square_b);
    }
    TDrawArea::Lock(param_1,s_stat_obj__draw_frame_3d_square_b,1);
  }
  return;
}

// --------------------------------------------------

// Function: draw_frame_3d_square_front
// Address: 004c2b50
// [HELPER] s_stat_obj__draw_frame_3d_square_f: "stat_obj::draw_frame_3d_square_front"
/* WARNING: Variable defined which should be unmapped: y1 */
/* public: void __thiscall RGE_Static_Object::draw_frame_3d_square_front(class TDrawArea
   *,short,short) */

void __thiscall
RGE_Static_Object::draw_frame_3d_square_front
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Map *this_00;
  float fVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  short sVar8;
  short y1;
  short x1;
  short y2;
  short x2;
  float ry1;
  float rx1;
  float local_10;
  TPanel *view_panel;
  float rz2;
  float local_4;
  
  pRVar1 = this->master_obj;
  this_00 = this->owner->world->map;
  rx1 = pRVar1->outline_radius_y;
  local_10 = pRVar1->outline_radius_x;
  local_4 = pRVar1->radius_z;
  view_panel = (TPanel *)this;
  rz2 = (float)(**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (rz2 != 0.0) {
    TDrawArea::Unlock(param_1,s_stat_obj__draw_frame_3d_square_f);
    sVar7 = param_2 + this->screen_x_offset;
    sVar8 = param_3 + this->screen_y_offset;
    pvVar3 = TDrawArea::GetDc(param_1,s_stat_obj__draw_frame_3d_square_f);
    if (pvVar3 != (void *)0x0) {
      SelectClipRgn(param_1->DrawDc,*(undefined4 *)((int)rz2 + 0x88));
      if (((startLoggingAI == 1) &&
          ((TPanel *)view_panel->have_focus == view_panel->previousPanelValue)) &&
         (-1 < (int)view_panel->previousPanelValue)) {
        uVar4 = GetStockObject(7);
        pvVar3 = param_1->DrawDc;
      }
      else {
        uVar4 = GetStockObject(6);
        pvVar3 = param_1->DrawDc;
      }
      SelectObject(pvVar3,uVar4);
      fVar2 = -local_10;
      RGE_Map::get_point(this_00,&x2,&y2,fVar2,-rx1,0.0,sVar7,sVar8);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar2,rx1,0.0,sVar7,sVar8);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,local_10,rx1,0.0,sVar7,sVar8);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar2,rx1,0.0,sVar7,sVar8);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      SelectClipRgn(param_1->DrawDc,0);
      TDrawArea::ReleaseDc(param_1,s_stat_obj__draw_frame_3d_square_f);
    }
    TDrawArea::Lock(param_1,s_stat_obj__draw_frame_3d_square_f,1);
    iVar5 = __ftol();
    if (0 < iVar5) {
      RGE_Map::get_point(this_00,&x2,&y2,local_10,-rx1,local_4,sVar7,sVar8);
      if (iVar5 < 1) {
        iVar5 = 0;
      }
      iVar6 = (int)*(short *)((int)&(view_panel->previousModalPanelValue->clip_rect).left + 2);
      if (0 < iVar6) {
        TDrawArea::FillRect(param_1,x2 + -0xc,y2 + -2,x2 + 0xc,y2 + -1,0x97);
        TDrawArea::FillRect(param_1,x2 + -0xc,y2 + -2,(iVar5 * 0x18) / iVar6 + -0xc + (int)x2,
                            y2 + -1,'J');
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw_frame_3d_cube_back
// Address: 004c2df0
/* WARNING: Variable defined which should be unmapped: y1 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Static_Object::draw_frame_3d_cube_back(class TDrawArea *,short,short)
    */

void __thiscall
RGE_Static_Object::draw_frame_3d_cube_back
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Map *this_00;
  float fVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  short sVar6;
  short sVar7;
  short y1;
  short x1;
  short y2;
  short x2;
  float rx1;
  float rx2;
  float ry1;
  float ry2;
  float rz2;
  float rz3;
  float rz4;
  float local_4;
  
  pRVar1 = this->master_obj;
  ry1 = pRVar1->outline_radius_x * _DAT_00574734;
  rz2 = pRVar1->outline_radius_y * _DAT_00574734;
  rz3 = pRVar1->outline_radius_z * _DAT_00574734;
  rz4 = pRVar1->outline_radius_z * _DAT_00574738;
  rx2 = pRVar1->outline_radius_x;
  this_00 = this->owner->world->map;
  ry2 = pRVar1->outline_radius_y;
  local_4 = pRVar1->outline_radius_z;
  iVar3 = (**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (iVar3 != 0) {
    TDrawArea::Unlock(param_1,(char *)0x0);
    pvVar4 = TDrawArea::GetDc(param_1,(char *)0x0);
    if (pvVar4 != (void *)0x0) {
      SelectClipRgn(param_1->DrawDc,*(undefined4 *)(iVar3 + 0x88));
      if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (-1 < this->id)) {
        uVar5 = GetStockObject(7);
        pvVar4 = param_1->DrawDc;
      }
      else {
        uVar5 = GetStockObject(6);
        pvVar4 = param_1->DrawDc;
      }
      SelectObject(pvVar4,uVar5);
      fVar2 = -ry2;
      sVar7 = param_3 + this->screen_y_offset;
      sVar6 = param_2 + this->screen_x_offset;
      RGE_Map::get_point(this_00,&x2,&y2,rx2,fVar2,0.0,sVar6,sVar7);
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,rx2,fVar2,rz3,sVar6,sVar7);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)rx1._2_2_,(int)rx1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,rx2,fVar2,rz4,sVar6,sVar7);
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,rx2,fVar2,local_4,sVar6,
                         sVar7);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)rx1._2_2_,(int)rx1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,rx2,fVar2,0.0,sVar6,sVar7);
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,ry1,fVar2,0.0,sVar6,sVar7);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)rx1._2_2_,(int)rx1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,-rx2,fVar2,0.0,sVar6,sVar7);
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,-ry1,fVar2,0.0,sVar6,sVar7);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)rx1._2_2_,(int)rx1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,rx2,fVar2,0.0,sVar6,sVar7);
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,rx2,-rz2,0.0,sVar6,sVar7);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)rx1._2_2_,(int)rx1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,rx2,ry2,0.0,sVar6,sVar7);
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,rx2,rz2,0.0,sVar6,sVar7);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)rx1._2_2_,(int)rx1._0_2_);
      SelectClipRgn(param_1->DrawDc,0);
      TDrawArea::ReleaseDc(param_1,(char *)0x0);
    }
    TDrawArea::Lock(param_1,(char *)0x0,1);
  }
  return;
}

// --------------------------------------------------

// Function: draw_frame_3d_cube_front
// Address: 004c31e0
/* WARNING: Variable defined which should be unmapped: y1 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Static_Object::draw_frame_3d_cube_front(class TDrawArea
   *,short,short) */

void __thiscall
RGE_Static_Object::draw_frame_3d_cube_front
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Map *this_00;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  short sVar8;
  short sVar9;
  short y1;
  short x1;
  short y2;
  short x2;
  float ry1;
  float rz4;
  float rx1;
  float ry2;
  float rx2;
  float local_10;
  float rz2;
  float rz3;
  float local_4;
  
  pRVar1 = this->master_obj;
  local_10 = pRVar1->outline_radius_x * _DAT_00574734;
  rx2 = pRVar1->outline_radius_y * _DAT_00574734;
  rz3 = pRVar1->outline_radius_z * _DAT_00574734;
  local_4 = pRVar1->outline_radius_z * _DAT_00574738;
  ry2 = pRVar1->outline_radius_x;
  this_00 = this->owner->world->map;
  rz4 = pRVar1->outline_radius_y;
  rx1 = pRVar1->outline_radius_z;
  iVar5 = (**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (iVar5 != 0) {
    TDrawArea::Unlock(param_1,(char *)0x0);
    pvVar6 = TDrawArea::GetDc(param_1,(char *)0x0);
    if (pvVar6 != (void *)0x0) {
      SelectClipRgn(param_1->DrawDc,*(undefined4 *)(iVar5 + 0x88));
      if (((startLoggingAI == 1) && (this->groupCommanderValue == this->id)) && (-1 < this->id)) {
        uVar7 = GetStockObject(7);
        pvVar6 = param_1->DrawDc;
      }
      else {
        uVar7 = GetStockObject(6);
        pvVar6 = param_1->DrawDc;
      }
      SelectObject(pvVar6,uVar7);
      fVar2 = -rz4;
      sVar9 = param_3 + this->screen_y_offset + -0x10;
      sVar8 = param_2 + this->screen_x_offset;
      RGE_Map::get_point(this_00,&x2,&y2,ry2,fVar2,rx1,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,local_10,fVar2,rx1,sVar8,
                         sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      fVar3 = -ry2;
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,fVar2,rx1,sVar8,sVar9);
      rz2 = -local_10;
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,rz2,fVar2,rx1,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,ry2,rz4,rx1,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,local_10,rz4,rx1,sVar8,sVar9
                        );
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,rz4,rx1,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,rz2,rz4,rx1,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,ry2,rz4,rx1,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,ry2,rx2,rx1,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,ry2,fVar2,rx1,sVar8,sVar9);
      fVar4 = -rx2;
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,ry2,fVar4,rx1,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,rz4,rx1,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar3,rx2,rx1,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,fVar2,rx1,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar3,fVar4,rx1,sVar8,sVar9)
      ;
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,fVar2,0.0,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar3,fVar4,0.0,sVar8,sVar9)
      ;
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,rz4,0.0,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar3,rx2,0.0,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,ry2,rz4,0.0,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,local_10,rz4,0.0,sVar8,sVar9
                        );
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,rz4,0.0,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,rz2,rz4,0.0,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,rz4,0.0,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar3,rz4,rz3,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,rz4,local_4,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar3,rz4,rx1,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,fVar2,0.0,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar3,fVar2,rz3,sVar8,sVar9)
      ;
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,fVar3,fVar2,local_4,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,fVar3,fVar2,rx1,sVar8,sVar9)
      ;
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,ry2,rz4,0.0,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,ry2,rz4,rz3,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      RGE_Map::get_point(this_00,&x2,&y2,ry2,rz4,local_4,sVar8,sVar9);
      RGE_Map::get_point(this_00,(short *)((int)&ry1 + 2),(short *)&ry1,ry2,rz4,rx1,sVar8,sVar9);
      MoveToEx(param_1->DrawDc,(int)x2,(int)y2,0);
      LineTo(param_1->DrawDc,(int)ry1._2_2_,(int)ry1._0_2_);
      SelectClipRgn(param_1->DrawDc,0);
      TDrawArea::ReleaseDc(param_1,(char *)0x0);
    }
    TDrawArea::Lock(param_1,(char *)0x0,1);
  }
  return;
}

// --------------------------------------------------

// Function: draw_frame
// Address: 004c3b30
/* WARNING: Variable defined which should be unmapped: min_x */
/* public: virtual void __thiscall RGE_Static_Object::draw_frame(class TDrawArea *,short,short) */

void __thiscall
RGE_Static_Object::draw_frame
          (RGE_Static_Object *this,TDrawArea *param_1,short param_2,short param_3)
{
  int iVar1;
  TDrawArea *this_00;
  int iVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar4;
  short unaff_retaddr;
  short min_x;
  short min_y;
  short max_y;
  short max_x;
  TDrawArea *pTStack_4;
  
  if ((this->sprite != (RGE_Sprite *)0x0) && (this->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    _min_x = unaff_EBX;
    (**(code **)(this->sprite_list->_padding_ + 0x28))(this->sprite,this->facet);
    iVar2 = get_frame(this,(short *)&stack0xfffffff0,(short *)&stack0xfffffff2,&min_y,&min_x);
    this_00 = pTStack_4;
    if (iVar2 != 0) {
      iVar2 = (int)(short)unaff_EBP + (int)unaff_retaddr + -1 + (int)this->screen_x_offset;
      iVar1 = (int)(short)((uint)unaff_EBP >> 0x10) + (int)(short)param_1 + -1 +
              (int)this->screen_y_offset;
      TDrawArea::DrawRect(pTStack_4,iVar2,iVar1,
                          (int)min_y + (int)unaff_retaddr + 1 + (int)this->screen_x_offset,
                          (int)min_x + (int)(short)param_1 + 1 + (int)this->screen_y_offset,0xff);
      if (this->object_state < 3) {
        iVar3 = __ftol();
        if (iVar3 < 1) {
          iVar3 = 0;
        }
        pTStack_4 = (TDrawArea *)(int)this->master_obj->hp;
        if (0 < (int)pTStack_4) {
          TDrawArea::DrawRect(this_00,iVar2,iVar1 + -6,iVar2 + 0x1a,iVar1 + -1,0xff);
          iVar4 = iVar2 + 1;
          TDrawArea::FillRect(this_00,iVar4,iVar1 + -5,iVar2 + 0x18,iVar1 + -3,'U');
          TDrawArea::FillRect(this_00,iVar4,iVar1 + -5,(iVar3 * 0x19) / (int)pTStack_4 + -1 + iVar4,
                              iVar1 + -2,'%');
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004c3c70
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
/* WARNING: Variable defined which should be unmapped: r_num */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Static_Object::update(void) */

uchar __thiscall RGE_Static_Object::update(RGE_Static_Object *this)
{
  RGE_Sound *this_00;
  bool bVar1;
  float fVar2;
  RGE_Object_Node *pRVar3;
  int *piVar4;
  int iVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  int iVar8;
  undefined3 uVar10;
  uint uVar9;
  int iVar11;
  undefined4 unaff_ESI;
  uchar uVar12;
  undefined4 unaff_EDI;
  uchar uVar13;
  uchar r_num;
  uint local_4;
  
  uVar13 = (uchar)((uint)unaff_EDI >> 0x18);
  uVar12 = (uchar)((uint)unaff_ESI >> 0x18);
  if (this->goto_sleep_flag != '\0') {
    iVar8 = this->owner->_padding_;
    this->goto_sleep_flag = '\0';
    (**(code **)(iVar8 + 0xe0))(this,0,this->dopple_flag,this->player_object_node);
    pRVar3 = (RGE_Object_Node *)
             (**(code **)(this->owner->_padding_ + 0xdc))(this,1,this->dopple_flag);
    this->player_object_node = pRVar3;
    return '\0';
  }
  iVar8 = (this->groupMembers).numberValue;
  if ((0 < iVar8) && (iVar11 = 0, 0 < iVar8)) {
    local_4 = 4;
    do {
      if ((this->groupMembers).maximumSizeValue + -1 < iVar11) {
        piVar4 = (int *)operator_new(local_4);
        if (piVar4 != (int *)0x0) {
          iVar8 = 0;
          if (0 < (this->groupMembers).maximumSizeValue) {
            do {
              if (iVar11 + 1 <= iVar8) break;
              iVar5 = iVar8 + 1;
              piVar4[iVar8] = (this->groupMembers).value[iVar8];
              iVar8 = iVar5;
            } while (iVar5 < (this->groupMembers).maximumSizeValue);
          }
          operator_delete((this->groupMembers).value);
          (this->groupMembers).value = piVar4;
          (this->groupMembers).maximumSizeValue = iVar11 + 1;
        }
      }
      iVar8 = (this->groupMembers).value[iVar11];
      pRVar6 = RGE_Game_World::object(this->owner->world,iVar8);
      uVar13 = (uchar)((uint)unaff_EDI >> 0x18);
      if ((pRVar6 == (RGE_Static_Object *)0x0) || (2 < pRVar6->object_state)) {
        iVar5 = (this->groupMembers).maximumSizeValue;
        iVar7 = 0;
        if (0 < iVar5) {
          piVar4 = (this->groupMembers).value;
          do {
            if (*piVar4 == iVar8) break;
            iVar7 = iVar7 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar7 < iVar5);
        }
        if (iVar7 < iVar5) {
          if (iVar7 < iVar5 + -1) {
            do {
              piVar4 = (this->groupMembers).value;
              iVar8 = iVar7 + 1;
              piVar4[iVar7] = piVar4[iVar8];
              iVar7 = iVar8;
            } while (iVar8 < (this->groupMembers).maximumSizeValue + -1);
          }
          iVar8 = (this->groupMembers).numberValue + -1;
          (this->groupMembers).numberValue = iVar8;
          if (iVar8 < 0) {
            (this->groupMembers).numberValue = 0;
          }
        }
        iVar11 = iVar11 + -1;
        local_4 = local_4 - 4;
      }
      iVar11 = iVar11 + 1;
      local_4 = local_4 + 4;
    } while (iVar11 < (this->groupMembers).numberValue);
  }
  pRVar6 = this->inside_obj;
  uVar10 = (undefined3)((uint)pRVar6 >> 8);
  if (pRVar6 == (RGE_Static_Object *)0x0) {
    switch(CONCAT31(uVar10,this->object_state)) {
    case 2:
      (**(code **)(this->_padding_ + 0x28))();
    case 0:
      if (this->hp < _DAT_0057472c) {
        iVar8 = this->_padding_;
        (**(code **)(iVar8 + 0x5c))(3);
        (**(code **)(iVar8 + 0x38))(this->master_obj->death_sprite);
        uVar9 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x704);
        iVar8 = debug_random_on;
        debug_random_on = 0;
        this_00 = this->master_obj->death_sound;
        if ((this_00 != (RGE_Sound *)0x0) && (this->owner->id == this->owner->world->curr_player)) {
          RGE_Sound::play(this_00,1);
        }
        debug_random_on = iVar8;
        debug_srand(s_C__msdev_work_age1_x1_stat_obj_c,0x70e,uVar9);
        return uVar13;
      }
      break;
    case 3:
    case 5:
      if ((this->attribute_type_held == -1) || (this->attribute_amount_held <= DAT_00574718._8_4_))
{
        iVar8 = this->_padding_;
        if (this->master_obj->undead_flag != '\0') {
          (**(code **)(iVar8 + 0x5c))(6);
          (**(code **)(iVar8 + 0x38))(this->master_obj->undead_sprite);
          return uVar13;
        }
        (**(code **)(iVar8 + 0x5c))(7);
        (**(code **)(iVar8 + 0xb8))();
        return uVar12;
      }
      if ((DAT_00574718._8_4_ < this->master_obj->attribute_rot) &&
         (fVar2 = this->attribute_amount_held -
                  this->owner->world->world_time_delta_seconds * this->master_obj->attribute_rot,
         bVar1 = fVar2 < DAT_00574718._8_4_, this->attribute_amount_held = fVar2, bVar1)) {
        this->attribute_amount_held = 0.0;
        return '\0';
      }
      break;
    case 7:
      (**(code **)(this->_padding_ + 0x5c))(8);
      return uVar12;
    case 8:
      return (this->master_obj->recyclable != '\0') + '\x01';
    }
  }
  else if (2 < pRVar6->object_state) {
    (**(code **)(this->_padding_ + 0x5c))(CONCAT31(uVar10,pRVar6->object_state));
  }
  return '\0';
}

// --------------------------------------------------

// Function: check_damage_sprites
// Address: 004c3f90
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
/* WARNING: Variable defined which should be unmapped: new_damage_percent */
/* public: virtual void __thiscall RGE_Static_Object::check_damage_sprites(void) */

void __thiscall RGE_Static_Object::check_damage_sprites(RGE_Static_Object *this)
{
  byte bVar1;
  uchar uVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Damage_Sprite_Info *pRVar4;
  char cVar5;
  short sVar6;
  uchar *puVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  undefined4 unaff_EBX;
  uint uVar11;
  float fVar12;
  float fVar13;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  RGE_Sprite *pRVar14;
  uchar new_damage_percent;
  short y;
  short x;
  short local_16;
  long curr_damage_loc;
  long new_damage_loc;
  float rand_y;
  float rand_x;
  float local_4;
  
  pRVar3 = this->master_obj;
  rand_y = -NAN;
  new_damage_loc = -1;
  if (pRVar3->hp < 1) {
    return;
  }
  bVar1 = pRVar3->damage_sprite_num;
  if (bVar1 == 0) {
    return;
  }
  curr_damage_loc = (long)pRVar3->hp;
  cVar5 = __ftol();
  bVar9 = 100 - cVar5;
  if (bVar9 == this->curr_damage_percent) {
    return;
  }
  fVar13 = -NAN;
  if ((bVar9 < 100) && (bVar1 != 0)) {
    fVar12 = 0.0;
    puVar7 = &pRVar3->damage_sprites->damage_percent;
    uVar11 = (uint)bVar1;
    do {
      if (*puVar7 < bVar9) {
        rand_y = fVar12;
      }
      if (*puVar7 < this->curr_damage_percent) {
        new_damage_loc = (long)fVar12;
      }
      fVar12 = (float)((int)fVar12 + 1);
      puVar7 = puVar7 + 8;
      uVar11 = uVar11 - 1;
      fVar13 = rand_y;
    } while (uVar11 != 0);
  }
  if (fVar13 == (float)new_damage_loc) goto LAB_004c41b6;
  if (-1 < (int)fVar13) {
    pRVar4 = this->master_obj->damage_sprites + (int)fVar13;
    uVar2 = pRVar4->flag;
    if (uVar2 == '\0') {
      pRVar14 = pRVar4->sprite;
      iVar8 = 0;
      iVar10 = 0;
    }
    else {
      if (uVar2 != '\x01') {
        if (uVar2 == '\x02') {
          (**(code **)(this->_padding_ + 0x38))(pRVar4->sprite);
        }
        goto LAB_004c415b;
      }
      rand_x = (float)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x774);
      sVar6 = __ftol();
      rand_x = (float)(int)sVar6;
      local_4 = (float)(((float10)this->world_x - (float10)(int)rand_x) + extraout_ST0);
      rand_x = (float)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0x775);
      sVar6 = __ftol();
      rand_x = (float)(((float10)this->world_y - (float10)(int)sVar6) + extraout_ST0_00);
      RGE_Map::get_point(this->owner->world->map,(short *)&curr_damage_loc,&local_16,local_4,rand_x,
                         this->world_z,0,0);
      iVar8 = (int)local_16;
      iVar10 = (int)(short)curr_damage_loc;
      pRVar14 = this->master_obj->damage_sprites[(int)fVar13].sprite;
    }
    RGE_Active_Sprite_List::add_sprite(this->sprite_list,pRVar14,'Z',iVar10,iVar8);
  }
LAB_004c415b:
  if (-1 < new_damage_loc) {
    pRVar4 = this->master_obj->damage_sprites;
    if (pRVar4[new_damage_loc].flag < 2) {
      RGE_Active_Sprite_List::remove_sprite(this->sprite_list,pRVar4[new_damage_loc].sprite);
    }
    else if ((pRVar4[new_damage_loc].flag == 2) &&
            (((int)rand_y < 0 || (pRVar4[(int)rand_y].flag != '\x02')))) {
      (**(code **)(this->_padding_ + 0x38))(this->master_obj->sprite);
      new_damage_percent = (uchar)((uint)unaff_EBX >> 8);
      this->curr_damage_percent = new_damage_percent;
      return;
    }
  }
LAB_004c41b6:
  this->curr_damage_percent = bVar9;
  return;
}

// --------------------------------------------------

// Function: spawn_death_obj
// Address: 004c41d0
/* public: virtual class RGE_Static_Object * __thiscall RGE_Static_Object::spawn_death_obj(void) */

RGE_Static_Object * __thiscall RGE_Static_Object::spawn_death_obj(RGE_Static_Object *this)
{
  short sVar1;
  RGE_Master_Static_Object *pRVar2;
  RGE_Static_Object *pRVar3;
  
  sVar1 = this->master_obj->death_spawn_obj_id;
  if (-1 < sVar1) {
    pRVar2 = this->owner->master_objects[sVar1];
    if (pRVar2 != (RGE_Master_Static_Object *)0x0) {
      pRVar3 = (RGE_Static_Object *)
               (**(code **)(pRVar2->_padding_ + 0x18))
                         (this->owner,this->world_x,this->world_y,this->world_z);
      return pRVar3;
    }
  }
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: rehook
// Address: 004c4210
/* public: virtual void __thiscall RGE_Static_Object::rehook(void) */

void __thiscall RGE_Static_Object::rehook(RGE_Static_Object *this)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0x34))(this->world_x,this->world_y,this->world_z);
  pRVar2 = this->inside_obj;
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    this->inside_obj = (RGE_Static_Object *)0x0;
    pRVar2 = get_object_pointer(this,(long)pRVar2);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      (**(code **)(iVar1 + 0xd0))(pRVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_object_pointer
// Address: 004c4250
/* public: class RGE_Static_Object * __thiscall RGE_Static_Object::get_object_pointer(long) */

RGE_Static_Object * __thiscall
RGE_Static_Object::get_object_pointer(RGE_Static_Object *this,long param_1)
{
  long lVar1;
  RGE_Static_Object *pRVar2;
  RGE_Game_World *pRVar3;
  ushort uVar4;
  byte bVar5;
  RGE_Player *pRVar6;
  
  lVar1 = param_1;
  pRVar2 = (RGE_Static_Object *)0x0;
  if ((((-1 < param_1) &&
       (pRVar2 = RGE_Object_List::find_by_id(this->owner->objects,param_1),
       pRVar2 == (RGE_Static_Object *)0x0)) &&
      (pRVar2 = RGE_Object_List::find_by_id(this->owner->sleeping_objects,param_1),
      pRVar2 == (RGE_Static_Object *)0x0)) &&
     (pRVar2 = RGE_Object_List::find_by_id(this->owner->doppleganger_objects,param_1),
     pRVar2 == (RGE_Static_Object *)0x0)) {
    pRVar6 = this->owner;
    bVar5 = 0;
    param_1 = 0;
    pRVar3 = pRVar6->world;
    if (0 < pRVar3->player_num) {
      uVar4 = 0;
      do {
        if (uVar4 != pRVar6->id) {
          pRVar2 = RGE_Object_List::find_by_id(pRVar3->players[param_1]->objects,lVar1);
          if (pRVar2 != (RGE_Static_Object *)0x0) {
            return pRVar2;
          }
          pRVar2 = RGE_Object_List::find_by_id
                             (this->owner->world->players[param_1]->sleeping_objects,lVar1);
          if (pRVar2 != (RGE_Static_Object *)0x0) {
            return pRVar2;
          }
          pRVar2 = RGE_Object_List::find_by_id
                             (this->owner->world->players[param_1]->doppleganger_objects,lVar1);
          if (pRVar2 != (RGE_Static_Object *)0x0) {
            return pRVar2;
          }
        }
        pRVar6 = this->owner;
        bVar5 = bVar5 + 1;
        param_1 = (long)bVar5;
        pRVar3 = pRVar6->world;
        uVar4 = (ushort)bVar5;
      } while ((short)(ushort)bVar5 < pRVar3->player_num);
    }
  }
  return pRVar2;
}

// --------------------------------------------------

// Function: get_sprite_pointer
// Address: 004c4330
/* public: class RGE_Sprite * __thiscall RGE_Static_Object::get_sprite_pointer(short) */

RGE_Sprite * __thiscall RGE_Static_Object::get_sprite_pointer(RGE_Static_Object *this,short param_1)
{
  RGE_Game_World *pRVar1;
  
  if ((-1 < param_1) && (pRVar1 = this->owner->world, param_1 < pRVar1->sprite_num)) {
    return pRVar1->sprites[param_1];
  }
  return (RGE_Sprite *)0x0;
}

// --------------------------------------------------

// Function: save
// Address: 004c4360
/* WARNING: Variable defined which should be unmapped: short_val */
/* public: virtual void __thiscall RGE_Static_Object::save(int) */

void __thiscall RGE_Static_Object::save(RGE_Static_Object *this,int param_1)
{
  RGE_Sprite *pRVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short short_val;
  long long_val;
  long local_4;
  
  iVar2 = param_1;
  rge_write(param_1,&this->type,1);
  rge_write(iVar2,&this->owner->id,1);
  rge_write(iVar2,&this->master_obj->id,2);
  pRVar1 = this->sprite;
  if (pRVar1 == (RGE_Sprite *)0x0) {
    long_val = -1;
  }
  else {
    long_val = CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id);
  }
  rge_write(iVar2,&long_val,2);
  if (this->inside_obj == (RGE_Static_Object *)0x0) {
    local_4 = -1;
  }
  else {
    local_4 = this->inside_obj->id;
  }
  rge_write(iVar2,&local_4,4);
  rge_write(iVar2,&this->hp,4);
  rge_write(iVar2,&this->object_state,1);
  rge_write(iVar2,&this->sleep_flag,1);
  rge_write(iVar2,&this->dopple_flag,1);
  rge_write(iVar2,&this->goto_sleep_flag,1);
  rge_write(iVar2,&this->id,4);
  rge_write(iVar2,&this->facet,1);
  rge_write(iVar2,&this->world_x,4);
  rge_write(iVar2,&this->world_y,4);
  rge_write(iVar2,&this->world_z,4);
  rge_write(iVar2,&this->screen_x_offset,2);
  rge_write(iVar2,&this->screen_y_offset,2);
  rge_write(iVar2,&this->shadow_x_offset,2);
  rge_write(iVar2,&this->shadow_y_offset,2);
  rge_write(iVar2,&this->selected_group,1);
  rge_write(iVar2,&this->attribute_type_held,2);
  rge_write(iVar2,&this->attribute_amount_held,4);
  rge_write(iVar2,&this->worker_num,1);
  rge_write(iVar2,&this->curr_damage_percent,1);
  rge_write(iVar2,&this->underAttackValue,1);
  rge_write(iVar2,&this->groupCommanderValue,4);
  rge_write(iVar2,&this->groupRangeValue,4);
  param_1 = (this->groupMembers).numberValue;
  rge_write(iVar2,&param_1,4);
  iVar6 = 0;
  if (0 < (this->groupMembers).numberValue) {
    do {
      if ((this->groupMembers).maximumSizeValue + -1 < iVar6) {
        piVar3 = (int *)operator_new(iVar6 * 4 + 4);
        if (piVar3 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->groupMembers).maximumSizeValue) {
            do {
              if (iVar6 + 1 <= iVar5) break;
              iVar4 = iVar5 + 1;
              piVar3[iVar5] = (this->groupMembers).value[iVar5];
              iVar5 = iVar4;
            } while (iVar4 < (this->groupMembers).maximumSizeValue);
          }
          operator_delete((this->groupMembers).value);
          (this->groupMembers).value = piVar3;
          (this->groupMembers).maximumSizeValue = iVar6 + 1;
        }
      }
      param_1 = (this->groupMembers).value[iVar6];
      rge_write(iVar2,&param_1,4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < (this->groupMembers).numberValue);
  }
  param_1 = (this->pathingGroupMembers).numberValue;
  rge_write(iVar2,&param_1,4);
  iVar6 = 0;
  if (0 < (this->pathingGroupMembers).numberValue) {
    do {
      if ((this->pathingGroupMembers).maximumSizeValue + -1 < iVar6) {
        piVar3 = (int *)operator_new(iVar6 * 4 + 4);
        if (piVar3 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->pathingGroupMembers).maximumSizeValue) {
            do {
              if (iVar6 + 1 <= iVar5) break;
              iVar4 = iVar5 + 1;
              piVar3[iVar5] = (this->pathingGroupMembers).value[iVar5];
              iVar5 = iVar4;
            } while (iVar4 < (this->pathingGroupMembers).maximumSizeValue);
          }
          operator_delete((this->pathingGroupMembers).value);
          (this->pathingGroupMembers).value = piVar3;
          (this->pathingGroupMembers).maximumSizeValue = iVar6 + 1;
        }
      }
      param_1 = (this->pathingGroupMembers).value[iVar6];
      rge_write(iVar2,&param_1,4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < (this->pathingGroupMembers).numberValue);
  }
  RGE_Active_Sprite_List::save(this->sprite_list,iVar2);
  return;
}

// --------------------------------------------------

// Function: teleport
// Address: 004c4680
/* WARNING: Variable defined which should be unmapped: ty */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Static_Object::teleport(float,float,float) */

float __thiscall
RGE_Static_Object::teleport(RGE_Static_Object *this,float param_1,float param_2,float param_3)
{
  RGE_Tile *pRVar1;
  uchar uVar2;
  RGE_Map *pRVar3;
  int iVar4;
  int iVar5;
  RGE_Tile *pRVar6;
  RGE_Master_Static_Object *pRVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  float10 extraout_ST0;
  float10 fVar14;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  int ty;
  float rx;
  float rz;
  RGE_Map *map;
  
  fVar10 = DAT_00574718._8_4_;
  pRVar3 = this->owner->world->map;
  if (this->inside_obj != (RGE_Static_Object *)0x0) {
    return DAT_00574718._8_4_;
  }
  if ((float)(double)DAT_00574718 < this->master_obj->radius_z) {
    removeFromObstructionMap(this,2);
  }
  if (param_1 < DAT_00574718._8_4_) {
    param_1 = 0.0;
  }
  iVar4 = pRVar3->map_width;
  if ((float)iVar4 <= param_1) {
    param_1 = (float)iVar4 - _DAT_00574744;
  }
  if (param_2 < DAT_00574718._8_4_) {
    param_2 = 0.0;
  }
  iVar5 = pRVar3->map_height;
  if ((float)iVar5 <= param_2) {
    param_2 = (float)iVar5 - _DAT_00574744;
  }
  iVar12 = __ftol();
  iVar13 = __ftol();
  fVar8 = param_1 - (float)iVar12;
  fVar9 = param_2 - (float)iVar13;
  if (iVar12 < iVar4) {
    if (iVar12 < 0) {
      iVar12 = 0;
    }
  }
  else {
    iVar12 = iVar4 + -1;
  }
  if (iVar13 < iVar5) {
    if (iVar13 < 0) {
      iVar13 = 0;
    }
  }
  else {
    iVar13 = iVar5 + -1;
  }
  pRVar1 = pRVar3->map_row_offset[iVar13] + iVar12;
  pRVar6 = this->tile;
  if ((pRVar1 == pRVar6) || (this->inside_obj != (RGE_Static_Object *)0x0)) {
    this->world_x = param_1;
    this->world_y = param_2;
    this->world_z = param_3;
    fVar14 = extraout_ST0;
  }
  else {
    if (pRVar6 != (RGE_Tile *)0x0) {
      RGE_Object_List::remove_node(&pRVar6->objects,this,(RGE_Object_Node *)0x0);
    }
    RGE_Object_List::add_node(&pRVar1->objects,this);
    if (this->tile != (RGE_Tile *)0x0) {
      (**(code **)(this->_padding_ + 0xdc))(this->owner,0,0xffffffff);
    }
    this->world_z = param_3;
    this->world_x = param_1;
    this->world_y = param_2;
    this->tile = pRVar1;
    if (this->object_state == '\x02') {
      (**(code **)(this->_padding_ + 0xd8))(this->owner,0,0xffffffff);
    }
    fVar14 = (float10)fVar10;
  }
  if ((float)(double)DAT_00574718 < this->master_obj->radius_z) {
    addToObstructionMap(this,2);
    fVar14 = (float10)fVar10;
  }
  switch(pRVar1->tile_type) {
  case '\0':
    goto switchD_004c4876_caseD_0;
  case '\x01':
    if (fVar9 + fVar8 < _DAT_0057472c) {
      fVar14 = (float10)fVar9;
      break;
    }
    goto LAB_004c49f3;
  case '\x02':
    if (fVar9 + fVar8 < _DAT_0057472c) {
      fVar14 = (float10)fVar8;
      break;
    }
    goto LAB_004c4920;
  case '\x03':
    if (fVar8 <= fVar9) {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar9;
    }
    else {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar8;
    }
    break;
  case '\x04':
    if (fVar8 <= fVar9) {
      fVar14 = (float10)fVar8;
    }
    else {
      fVar14 = (float10)fVar9;
    }
    break;
  case '\x05':
    fVar14 = (float10)_DAT_0057472c - (float10)fVar8;
    break;
  case '\x06':
LAB_004c4920:
    fVar14 = (float10)_DAT_0057472c - (float10)fVar9;
    break;
  case '\a':
    fVar14 = (float10)fVar9;
    break;
  case '\b':
    fVar14 = (float10)fVar8;
    break;
  case '\t':
    if ((float10)fVar8 - (float10)fVar9 < (float10)DAT_00574718._8_4_) {
      fVar14 = -((float10)fVar8 - (float10)fVar9);
      break;
    }
    goto switchD_004c4876_caseD_0;
  case '\n':
    fVar14 = (float10)fVar8 - (float10)fVar9;
    if (fVar14 <= (float10)DAT_00574718._8_4_) {
      fVar14 = (float10)DAT_00574718._8_4_;
    }
    break;
  case '\v':
    if ((float10)fVar9 + (float10)fVar8 < (float10)_DAT_0057472c) {
      fVar14 = (float10)_DAT_0057472c - ((float10)fVar9 + (float10)fVar8);
      break;
    }
    goto switchD_004c4876_caseD_0;
  case '\f':
    if ((float10)_DAT_0057472c < (float10)fVar9 + (float10)fVar8) {
      fVar14 = ((float10)fVar9 + (float10)fVar8) - (float10)_DAT_0057472c;
      break;
    }
switchD_004c4876_caseD_0:
    fVar14 = (float10)DAT_00574718._8_4_;
    break;
  case '\r':
    if (_DAT_0057472c <= fVar9 + fVar8) {
      fVar14 = (float10)fVar9;
      break;
    }
LAB_004c49f3:
    fVar14 = (float10)_DAT_0057472c - (float10)fVar8;
    break;
  case '\x0e':
    if (_DAT_0057472c <= fVar9 + fVar8) {
      fVar14 = (float10)fVar8;
    }
    else {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar9;
    }
    break;
  case '\x0f':
    if (fVar8 <= fVar9) {
      fVar14 = (float10)fVar9;
    }
    else {
      fVar14 = (float10)fVar8;
    }
    break;
  case '\x10':
    if (fVar8 <= fVar9) {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar8;
    }
    else {
      fVar14 = (float10)_DAT_0057472c - (float10)fVar9;
    }
  }
  pRVar7 = this->master_obj;
  uVar2 = pRVar7->movement_type;
  fVar14 = fVar14 + (float10)((byte)this->tile->field_0x5 >> 5);
  if ((uVar2 == '\0') || ((uVar2 == '\x01' && ((float10)this->world_z < fVar14)))) {
    this->world_z = (float)fVar14;
  }
  sVar11 = __ftol();
  this->screen_x_offset = sVar11;
  sVar11 = __ftol();
  this->screen_y_offset = sVar11;
  uVar2 = pRVar7->movement_type;
  if (uVar2 == '\0') {
    this->shadow_x_offset = this->screen_x_offset;
    this->shadow_y_offset = this->screen_y_offset;
  }
  else if (uVar2 == '\x01') {
    sVar11 = __ftol();
    this->shadow_x_offset = sVar11;
    sVar11 = __ftol();
    this->shadow_y_offset = sVar11;
    return (float)extraout_ST0_01;
  }
  return (float)extraout_ST0_00;
}

// --------------------------------------------------

// Function: new_sprite
// Address: 004c4bd0
/* public: virtual void __thiscall RGE_Static_Object::new_sprite(class RGE_Sprite *) */

void __thiscall RGE_Static_Object::new_sprite(RGE_Static_Object *this,RGE_Sprite *param_1)
{
  RGE_Sprite *pRVar1;
  RGE_Sprite *pRVar2;
  
  if (param_1 == (RGE_Sprite *)0x0) {
    param_1 = this->master_obj->sprite;
  }
  pRVar1 = this->sprite;
  if ((pRVar1 != param_1) &&
     ((pRVar2 = this->master_obj->death_sprite, pRVar1 != pRVar2 || (pRVar2 == (RGE_Sprite *)0x0))))
{
    this->old_sprite = pRVar1;
    RGE_Active_Sprite_List::remove_sprite(this->sprite_list,pRVar1);
    this->sprite = param_1;
    RGE_Active_Sprite_List::add_sprite(this->sprite_list,param_1,'<',0,0);
    this->facet = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: add_overlay_sprite
// Address: 004c4c20
/* public: virtual void __thiscall RGE_Static_Object::add_overlay_sprite(class RGE_Sprite *,unsigned
   char) */

void __thiscall
RGE_Static_Object::add_overlay_sprite(RGE_Static_Object *this,RGE_Sprite *param_1,uchar param_2)
{
  RGE_Active_Sprite_List::add_sprite(this->sprite_list,param_1,param_2,0,0);
  return;
}

// --------------------------------------------------

// Function: remove_overlay_sprite
// Address: 004c4c40
/* public: virtual void __thiscall RGE_Static_Object::remove_overlay_sprite(class RGE_Sprite *) */

void __thiscall
RGE_Static_Object::remove_overlay_sprite(RGE_Static_Object *this,RGE_Sprite *param_1)
{
  RGE_Active_Sprite_List::remove_sprite(this->sprite_list,param_1);
  return;
}

// --------------------------------------------------

// Function: change_ownership
// Address: 004c4c50
/* WARNING: Variable defined which should be unmapped: hp_num */
/* public: virtual void __thiscall RGE_Static_Object::change_ownership(class RGE_Player *) */

void __thiscall RGE_Static_Object::change_ownership(RGE_Static_Object *this,RGE_Player *param_1)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Master_Static_Object *pRVar2;
  RGE_Object_Node *pRVar3;
  RGE_Sprite *pRVar4;
  RGE_Static_Object *pRVar5;
  float hp_num;
  
  if (param_1->master_objects[this->master_obj->id] == (RGE_Master_Static_Object *)0x0) {
    return;
  }
  if ((this->selected & 1) != 0) {
    RGE_Player::unselect_one_object(this->owner,this);
  }
  take_attribute_from_owner(this);
  if (this->object_state == '\x02') {
    (**(code **)(this->_padding_ + 0xdc))(this->owner,0,0xffffffff);
  }
  pRVar5 = this;
  (**(code **)(this->owner->_padding_ + 0xe0))
            (this,this->sleep_flag,this->dopple_flag,this->player_object_node);
  pRVar3 = (RGE_Object_Node *)
           (**(code **)(param_1->_padding_ + 0xdc))(this,this->sleep_flag,this->dopple_flag);
  pRVar1 = this->master_obj;
  this->player_object_node = pRVar3;
  pRVar2 = param_1->master_objects[pRVar1->id];
  pRVar4 = this->sprite;
  if (pRVar4 != pRVar1->sprite) {
    if (pRVar4 == pRVar1->death_sprite) {
      pRVar4 = pRVar2->death_sprite;
      goto LAB_004c4d17;
    }
    if (pRVar4 == pRVar1->undead_sprite) {
      pRVar4 = pRVar2->undead_sprite;
      goto LAB_004c4d17;
    }
  }
  pRVar4 = pRVar2->sprite;
LAB_004c4d17:
  if (pRVar4 != (RGE_Sprite *)0x0) {
    (**(code **)(this->_padding_ + 0x38))(pRVar4);
  }
  this->owner = param_1;
  this->master_obj = pRVar2;
  this->hp = (float)(int)pRVar2->hp * (float)pRVar5;
  if (this->object_state == '\x02') {
    (**(code **)(this->_padding_ + 0xd8))(param_1,0,0xffffffff);
  }
  give_attribute_to_owner(this);
  (**(code **)(this->_padding_ + 0x148))(this->id,this->id,0x20b,(int)param_1->id,0,0);
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 004c4d80
/* public: virtual void __thiscall RGE_Static_Object::modify(float,unsigned char) */

void __thiscall RGE_Static_Object::modify(RGE_Static_Object *this,float param_1,uchar param_2)
{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  
  if (param_2 == '\0') {
    sVar2 = __ftol();
    this->hp = (float)(int)sVar2;
  }
  else if (((param_2 == '\x01') && (this->tile != (RGE_Tile *)0x0)) &&
          (this->object_state == '\x02')) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0xdc))(this->owner,0,0xffffffff);
    uVar3 = __ftol();
    (**(code **)(iVar1 + 0xd8))(this->owner,0,uVar3);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 004c4e00
/* public: virtual void __thiscall RGE_Static_Object::modify_delta(float,unsigned char) */

void __thiscall RGE_Static_Object::modify_delta(RGE_Static_Object *this,float param_1,uchar param_2)
{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  
  if (param_2 == '\0') {
    sVar2 = __ftol();
    this->hp = (float)(int)sVar2;
  }
  else if (((param_2 == '\x01') && (this->tile != (RGE_Tile *)0x0)) &&
          (this->object_state == '\x02')) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0xdc))(this->owner,0,0xffffffff);
    uVar3 = __ftol();
    (**(code **)(iVar1 + 0xd8))(this->owner,0,uVar3);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 004c4e90
/* public: virtual void __thiscall RGE_Static_Object::modify_percent(float,unsigned char) */

void __thiscall
RGE_Static_Object::modify_percent(RGE_Static_Object *this,float param_1,uchar param_2)
{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  
  if (param_2 == '\0') {
    sVar2 = __ftol();
    this->hp = (float)(int)sVar2;
  }
  else if (((param_2 == '\x01') && (this->tile != (RGE_Tile *)0x0)) &&
          (this->object_state == '\x02')) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0xdc))(this->owner,0,0xffffffff);
    uVar3 = __ftol();
    (**(code **)(iVar1 + 0xd8))(this->owner,0,uVar3);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: transform
// Address: 004c4f10
/* WARNING: Variable defined which should be unmapped: hp_num */
/* public: virtual void __thiscall RGE_Static_Object::transform(class RGE_Master_Static_Object *) */

void __thiscall
RGE_Static_Object::transform(RGE_Static_Object *this,RGE_Master_Static_Object *param_1)
{
  short sVar1;
  int iVar2;
  float unaff_EBX;
  float hp_num;
  
  if (this->tile != (RGE_Tile *)0x0) {
    (**(code **)(this->_padding_ + 0xdc))(this->owner,0,0xffffffff);
  }
  removeFromObstructionMap(this,2);
  this->master_obj = param_1;
  if (this->tile != (RGE_Tile *)0x0) {
    (**(code **)(this->_padding_ + 0xd8))(this->owner,0,0xffffffff);
  }
  addToObstructionMap(this,2);
  iVar2 = this->_padding_;
  (**(code **)(iVar2 + 0x38))(param_1->sprite);
  sVar1 = param_1->hp;
  this->object_state = '\0';
  this->hp = (float)(int)sVar1 * unaff_EBX;
  (**(code **)(iVar2 + 0x5c))(2);
  return;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 004c4fb0
/* WARNING: Variable defined which should be unmapped: hp_num */
/* public: virtual void __thiscall RGE_Static_Object::copy_obj(class RGE_Master_Static_Object *) */

void __thiscall
RGE_Static_Object::copy_obj(RGE_Static_Object *this,RGE_Master_Static_Object *param_1)
{
  float fVar1;
  short sVar2;
  int iVar3;
  RGE_Master_Static_Object *pRVar4;
  RGE_Sprite *pRVar5;
  float fVar6;
  undefined4 uVar7;
  RGE_Sprite *pRVar8;
  float hp_num;
  
  pRVar8 = (RGE_Sprite *)0x0;
  if ((this->tile != (RGE_Tile *)0x0) && (this->object_state == '\x02')) {
    iVar3 = this->_padding_;
    (**(code **)(iVar3 + 0xdc))(this->owner,0,0xffffffff);
    uVar7 = __ftol();
    (**(code **)(iVar3 + 0xd8))(this->owner,0,uVar7);
  }
  fVar6 = (float)(int)this->master_obj->hp;
  fVar1 = this->hp;
  this->hp = fVar6;
  if (this->object_state == '\x02') {
    (**(code **)(this->_padding_ + 0x28))();
  }
  pRVar4 = this->master_obj;
  pRVar5 = this->sprite;
  if (pRVar5 == pRVar4->sprite) {
    pRVar8 = param_1->sprite;
  }
  else if (pRVar5 == pRVar4->death_sprite) {
    pRVar8 = param_1->death_sprite;
  }
  else if (pRVar5 == pRVar4->undead_sprite) {
    pRVar8 = param_1->undead_sprite;
  }
  sVar2 = param_1->hp;
  this->master_obj = param_1;
  this->hp = (float)(int)sVar2 * (fVar1 / fVar6);
  if (this->object_state == '\x02') {
    (**(code **)(this->_padding_ + 0x28))();
  }
  this->master_obj = pRVar4;
  if (pRVar8 != (RGE_Sprite *)0x0) {
    (**(code **)(this->_padding_ + 0x38))(pRVar8);
  }
  return;
}

// --------------------------------------------------

// Function: destroy_obj
// Address: 004c5080
/* public: virtual void __thiscall RGE_Static_Object::destroy_obj(void) */

void __thiscall RGE_Static_Object::destroy_obj(RGE_Static_Object *this)
{
  if (this->object_state < 7) {
    if (this->inside_obj != (RGE_Static_Object *)0x0) {
      (**(code **)(this->_padding_ + 0xd4))();
    }
    if ((this->selected & 1) != 0) {
      RGE_Player::unselect_one_object(this->owner,this);
    }
    set_sleep_flag(this,'\0');
    (**(code **)(this->_padding_ + 0x5c))(7);
  }
  return;
}

// --------------------------------------------------

// Function: die_die_die
// Address: 004c50c0
// [HELPER] die_die_die: " "
/* public: virtual void __thiscall RGE_Static_Object::die_die_die(void) */

void __thiscall RGE_Static_Object::die_die_die(RGE_Static_Object *this)
{
  if ((this->selected & 1) != 0) {
    RGE_Player::unselect_one_object(this->owner,this);
  }
  set_sleep_flag(this,'\0');
  this->hp = 0.0;
  return;
}

// --------------------------------------------------

// Function: remove_visible_resource
// Address: 004c50f0
/* WARNING: Variable defined which should be unmapped: ExploredVal */
/* public: virtual void __thiscall RGE_Static_Object::remove_visible_resource(void) */

void __thiscall RGE_Static_Object::remove_visible_resource(RGE_Static_Object *this)
{
  RGE_Master_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong ExploredVal;
  
  if ((((-1 < this->id) && (this->owner != (RGE_Player *)0x0)) &&
      (pRVar1 = this->master_obj, pRVar1 != (RGE_Master_Static_Object *)0x0)) &&
     ((pRVar1->create_doppleganger_on_death != '\0' || (pRVar1->track_as_resource != '\0')))) {
    iVar2 = __ftol();
    iVar3 = __ftol();
    uVar4 = (uint)(&unified_map_offsets)[iVar2][iVar3] & 0xffff;
    uVar5 = (uint)(&unified_map_offsets)[iVar2][iVar3] >> 0x10;
    if (uVar5 != 0) {
      iVar2 = 0;
      do {
        if (((byte)uVar5 & 1) == 1) {
          if (this->master_obj->track_as_resource != '\0') {
            Visible_Resource_Manager::Remove_Resource
                      (*(Visible_Resource_Manager **)
                        (*(int *)((int)this->owner->world->players + iVar2) + 0x110),this->id,
                       (uint)this->master_obj->resource_group);
          }
          if (((this->master_obj->create_doppleganger_on_death == '\x01') && ((uVar4 & 1) == 0)) &&
             (0 < iVar2)) {
            iVar3 = *(int *)((int)this->owner->world->players + iVar2);
            (**(code **)(**(int **)(*(int *)(iVar3 + 0x24) + 0x3cc) + 0x38))
                      (iVar3,this->world_x,this->world_y,this->world_z,this);
          }
        }
        iVar2 = iVar2 + 4;
        uVar4 = uVar4 >> 1;
        uVar5 = uVar5 >> 1;
      } while (uVar5 != 0);
    }
    if (this->master_obj->create_doppleganger_on_death == '\x02') {
      RGE_Doppleganger_Creator::remove_doppleganger_check(this->owner->doppleganger_creator,this);
    }
  }
  return;
}

// --------------------------------------------------

// Function: create_doppleganger_when_dying
// Address: 004c5210
/* WARNING: Variable defined which should be unmapped: ExploredVal */
/* public: virtual void __thiscall RGE_Static_Object::create_doppleganger_when_dying(void) */

void __thiscall RGE_Static_Object::create_doppleganger_when_dying(RGE_Static_Object *this)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulong ExploredVal;
  
  if ((((-1 < this->id) && (this->owner != (RGE_Player *)0x0)) &&
      (this->master_obj != (RGE_Master_Static_Object *)0x0)) &&
     (this->master_obj->create_doppleganger_on_death == '\x02')) {
    iVar1 = __ftol();
    iVar2 = __ftol();
    uVar3 = (uint)(&unified_map_offsets)[iVar1][iVar2] & 0xffff;
    uVar4 = (uint)(&unified_map_offsets)[iVar1][iVar2] >> 0x10;
    if (uVar4 != 0) {
      iVar1 = 0;
      do {
        if (((((byte)uVar4 & 1) == 1) && ((uVar3 & 1) == 0)) && (0 < iVar1)) {
          iVar2 = *(int *)((int)this->owner->world->players + iVar1);
          (**(code **)(**(int **)(*(int *)(iVar2 + 0x24) + 0x3cc) + 0x38))
                    (iVar2,this->world_x,this->world_y,this->world_z,this);
        }
        iVar1 = iVar1 + 4;
        uVar3 = uVar3 >> 1;
        uVar4 = uVar4 >> 1;
      } while (uVar4 != 0);
    }
    iVar1 = __ftol();
    iVar2 = __ftol();
    RGE_Doppleganger_Creator::add_doppleganger_check
              (this->owner->doppleganger_creator,this,
               (ulong *)((&unified_map_offsets)[iVar1] + iVar2));
  }
  return;
}

// --------------------------------------------------

// Function: set_object_state
// Address: 004c52f0
/* WARNING: Variable defined which should be unmapped: newCommander */
/* public: virtual void __thiscall RGE_Static_Object::set_object_state(unsigned char) */

void __thiscall RGE_Static_Object::set_object_state(RGE_Static_Object *this,uchar param_1)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  UnitAIModule *pUVar3;
  int iVar4;
  int iVar5;
  AIPlayStatus *pAVar6;
  int newCommander;
  int iStack_4;
  
  if (this->object_state != param_1) {
    if (((2 < param_1) && (this->object_state < 3)) &&
       (take_attribute_from_owner(this), this->master_obj->create_doppleganger_on_death == '\x02'))
{
      (**(code **)(this->_padding_ + 100))();
    }
    if ((this->object_state < 4) && (6 < param_1)) {
      (**(code **)(this->_padding_ + 0x60))();
    }
    if (((2 < param_1) && (this->object_state == '\x02')) && (this->tile != (RGE_Tile *)0x0)) {
      iVar4 = this->_padding_;
      (**(code **)(iVar4 + 0xdc))(this->owner,0,0xffffffff);
      if ((float)(double)DAT_00574718 < this->master_obj->los) {
        (**(code **)(iVar4 + 0xd8))(this->owner,1,0xffffffff);
      }
    }
    if ((((this->object_state < 7) && (param_1 == '\a')) && (this->tile != (RGE_Tile *)0x0)) &&
       ((float)(double)DAT_00574718 < this->master_obj->los)) {
      (**(code **)(this->_padding_ + 0xdc))(this->owner,1,0xffffffff);
    }
    this->object_state = param_1;
    if (((param_1 == '\x03') && (this->groupCommanderValue == this->id)) &&
       ((this->unitAIValue != (UnitAIModule *)0x0 &&
        (iVar4 = (this->groupMembers).numberValue, 1 < iVar4)))) {
      iVar5 = 0;
      iStack_4 = -1;
      if (0 < iVar4) {
        do {
          if ((this->groupMembers).maximumSizeValue + -1 < iVar5) {
            piVar1 = (int *)operator_new(iVar5 * 4 + 4);
            if (piVar1 != (int *)0x0) {
              iVar4 = 0;
              if (0 < (this->groupMembers).maximumSizeValue) {
                do {
                  if (iVar5 + 1 <= iVar4) break;
                  iVar2 = iVar4 + 1;
                  piVar1[iVar4] = (this->groupMembers).value[iVar4];
                  iVar4 = iVar2;
                } while (iVar2 < (this->groupMembers).maximumSizeValue);
              }
              operator_delete((this->groupMembers).value);
              (this->groupMembers).value = piVar1;
              (this->groupMembers).maximumSizeValue = iVar5 + 1;
            }
          }
          if ((this->groupMembers).value[iVar5] != this->id) {
            if ((this->groupMembers).maximumSizeValue + -1 < iVar5) {
              piVar1 = (int *)operator_new(iVar5 * 4 + 4);
              if (piVar1 != (int *)0x0) {
                iVar4 = 0;
                if (0 < (this->groupMembers).maximumSizeValue) {
                  do {
                    if (iVar5 + 1 <= iVar4) break;
                    iVar2 = iVar4 + 1;
                    piVar1[iVar4] = (this->groupMembers).value[iVar4];
                    iVar4 = iVar2;
                  } while (iVar2 < (this->groupMembers).maximumSizeValue);
                }
                operator_delete((this->groupMembers).value);
                (this->groupMembers).value = piVar1;
                (this->groupMembers).maximumSizeValue = iVar5 + 1;
              }
            }
            this_00 = RGE_Game_World::object(this->owner->world,(this->groupMembers).value[iVar5]);
            if (((this_00 != (RGE_Static_Object *)0x0) && (this_00->object_state < 3)) &&
               (pUVar3 = unitAI(this_00), pUVar3 != (UnitAIModule *)0x0)) {
              if (iStack_4 == -1) {
                if ((this->groupMembers).maximumSizeValue + -1 < iVar5) {
                  piVar1 = (int *)operator_new(iVar5 * 4 + 4);
                  if (piVar1 != (int *)0x0) {
                    iVar4 = 0;
                    if (0 < (this->groupMembers).maximumSizeValue) {
                      do {
                        if (iVar5 + 1 <= iVar4) break;
                        iVar2 = iVar4 + 1;
                        piVar1[iVar4] = (this->groupMembers).value[iVar4];
                        iVar4 = iVar2;
                      } while (iVar2 < (this->groupMembers).maximumSizeValue);
                    }
                    operator_delete((this->groupMembers).value);
                    (this->groupMembers).value = piVar1;
                    (this->groupMembers).maximumSizeValue = iVar5 + 1;
                  }
                }
                iStack_4 = (this->groupMembers).value[iVar5];
              }
              this_00->groupCommanderValue = iStack_4;
              if ((this->groupMembers).maximumSizeValue + -1 < iVar5) {
                piVar1 = (int *)operator_new(iVar5 * 4 + 4);
                if (piVar1 != (int *)0x0) {
                  iVar4 = 0;
                  if (0 < (this->groupMembers).maximumSizeValue) {
                    do {
                      if (iVar5 + 1 <= iVar4) break;
                      iVar2 = iVar4 + 1;
                      piVar1[iVar4] = (this->groupMembers).value[iVar4];
                      iVar4 = iVar2;
                    } while (iVar2 < (this->groupMembers).maximumSizeValue);
                  }
                  operator_delete((this->groupMembers).value);
                  (this->groupMembers).value = piVar1;
                  (this->groupMembers).maximumSizeValue = iVar5 + 1;
                }
              }
              if ((this->groupMembers).value[iVar5] == iStack_4) {
                pAVar6 = this->unitAIValue->playStatus;
                pUVar3 = unitAI(this_00);
                UnitAIModule::setPlayStatus(pUVar3,pAVar6);
              }
            }
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (this->groupMembers).numberValue);
      }
    }
    if (((this->sleep_flag != '\0') && (this->object_state != '\x02')) &&
       (this->object_state != '\x06')) {
      set_sleep_flag(this,'\0');
    }
  }
  return;
}

// --------------------------------------------------

// Function: check_object_bounds
// Address: 004c5610
/* WARNING: Variable defined which should be unmapped: dx */
/* public: class RGE_Static_Object * __thiscall RGE_Static_Object::check_object_bounds(void) */

RGE_Static_Object * __thiscall RGE_Static_Object::check_object_bounds(RGE_Static_Object *this)
{
  float fVar1;
  float fVar2;
  RGE_Map *pRVar3;
  RGE_Object_Node *pRVar4;
  RGE_Static_Object *pRVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  float fVar12;
  RGE_Object_Node **ppRVar13;
  float dx;
  short x1;
  float ry2;
  float ry;
  float rx2;
  float rx;
  short x2;
  short y2;
  short y_index;
  
  fVar1 = this->master_obj->radius_x;
  fVar2 = this->master_obj->radius_y;
  if ((DAT_00574718._8_4_ < fVar1) || (DAT_00574718._8_4_ < fVar2)) {
    ry2 = (float)__ftol();
    sVar9 = __ftol();
    sVar10 = __ftol();
    sVar11 = __ftol();
    pRVar3 = this->owner->world->map;
    if (SUB42(ry2,0) < 0) {
      ry2 = 0.0;
    }
    if (pRVar3->map_width <= (int)sVar10) {
      sVar10 = (short)pRVar3->map_width + -1;
    }
    if (sVar9 < 0) {
      sVar9 = 0;
    }
    if (pRVar3->map_height <= (int)sVar11) {
      sVar11 = (short)pRVar3->map_height + -1;
    }
    if (sVar9 <= sVar11) {
      do {
        if (SUB42(ry2,0) <= sVar10) {
          ppRVar13 = &pRVar3->map_row_offset[sVar9][SUB42(ry2,0)].objects.list;
          fVar12 = ry2;
          do {
            for (pRVar4 = *ppRVar13; pRVar4 != (RGE_Object_Node *)0x0; pRVar4 = pRVar4->next) {
              pRVar5 = pRVar4->node;
              fVar6 = pRVar5->master_obj->radius_x;
              fVar7 = pRVar5->master_obj->radius_y;
              if ((DAT_00574718._8_4_ < fVar6) && (DAT_00574718._8_4_ < fVar7)) {
                fVar8 = pRVar5->world_y - this->world_y;
                _x1 = pRVar5->world_x - this->world_x;
                if (fVar8 < DAT_00574718._8_4_) {
                  fVar8 = -fVar8;
                }
                if (_x1 < DAT_00574718._8_4_) {
                  _x1 = -_x1;
                }
                if ((fVar8 <= fVar7 + fVar2) && (_x1 <= fVar6 + fVar1)) {
                  return pRVar5;
                }
              }
            }
            ppRVar13 = ppRVar13 + 6;
            fVar12 = (float)((int)fVar12 + 1);
          } while (SUB42(fVar12,0) <= sVar10);
        }
        sVar9 = sVar9 + 1;
        if (sVar11 < sVar9) {
          return (RGE_Static_Object *)0x0;
        }
      } while( true );
    }
  }
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: get_terrain_speed
// Address: 004c5820
/* public: float __thiscall RGE_Static_Object::get_terrain_speed(unsigned char) */

float __thiscall RGE_Static_Object::get_terrain_speed(RGE_Static_Object *this,uchar param_1)
{
  return this->owner->world->terrains[this->master_obj->terrain][param_1];
}

// --------------------------------------------------

// Function: is_moving
// Address: 004c5850
/* public: virtual unsigned char __thiscall RGE_Static_Object::is_moving(void) */

uchar __thiscall RGE_Static_Object::is_moving(RGE_Static_Object *this)
{
  return '\0';
}

// --------------------------------------------------

// Function: is_dying
// Address: 004c5860
/* public: unsigned char __thiscall RGE_Static_Object::is_dying(void) */

uchar __thiscall RGE_Static_Object::is_dying(RGE_Static_Object *this)
{
  if ((2 < this->object_state) && (this->object_state != 6)) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: get_frame
// Address: 004c5880
/* public: int __thiscall RGE_Static_Object::get_frame(short &,short &,short &,short &) */

int __thiscall
RGE_Static_Object::get_frame
          (RGE_Static_Object *this,short *param_1,short *param_2,short *param_3,short *param_4)
{
  byte bVar1;
  
  if ((this->sprite != (RGE_Sprite *)0x0) && (this->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    bVar1 = RGE_Active_Sprite_List::get_frame
                      (this->sprite_list,param_1,param_2,param_3,param_4,this->sprite,
                       (uint)this->facet);
    return (uint)bVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: more_room
// Address: 004c58c0
/* public: unsigned char __thiscall RGE_Static_Object::more_room(void) */

uchar __thiscall RGE_Static_Object::more_room(RGE_Static_Object *this)
{
  return this->objects->number_of_objects < (short)(ushort)this->master_obj->obj_max;
}

// --------------------------------------------------

// Function: enter_obj
// Address: 004c58e0
/* public: virtual void __thiscall RGE_Static_Object::enter_obj(class RGE_Static_Object *) */

void __thiscall RGE_Static_Object::enter_obj(RGE_Static_Object *this,RGE_Static_Object *param_1)
{
  uchar uVar1;
  
  uVar1 = more_room(param_1);
  if (uVar1 != '\0') {
    if (this->inside_obj != (RGE_Static_Object *)0x0) {
      (**(code **)(this->inside_obj->_padding_ + 0xd4))();
    }
    if (this->tile != (RGE_Tile *)0x0) {
      (**(code **)(this->_padding_ + 0xdc))(this->owner,0,0xffffffff);
      RGE_Object_List::remove_node(&this->tile->objects,this,(RGE_Object_Node *)0x0);
      this->tile = (RGE_Tile *)0x0;
    }
    removeFromObstructionMap(this,2);
    RGE_Object_List::add_node(param_1->objects,this);
    this->inside_obj = param_1;
    this->world_x = param_1->world_x;
    this->world_y = param_1->world_y;
  }
  return;
}

// --------------------------------------------------

// Function: exit_obj
// Address: 004c5960
/* public: virtual void __thiscall RGE_Static_Object::exit_obj(void) */

void __thiscall RGE_Static_Object::exit_obj(RGE_Static_Object *this)
{
  if (this->inside_obj != (RGE_Static_Object *)0x0) {
    RGE_Object_List::remove_node(this->inside_obj->objects,this,(RGE_Object_Node *)0x0);
    this->inside_obj = (RGE_Static_Object *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: get_los_table
// Address: 004c5980
/* public: virtual struct LOSTBL * __thiscall RGE_Static_Object::get_los_table(void) */

LOSTBL * __thiscall RGE_Static_Object::get_los_table(RGE_Static_Object *this)
{
  RGE_Player *pRVar1;
  int iVar2;
  LOSTBL *pLVar3;
  int iVar4;
  
  pRVar1 = this->owner;
  if (pRVar1 == (RGE_Player *)0x0) {
    return (LOSTBL *)0x0;
  }
  iVar4 = 0;
  iVar2 = __ftol();
  pLVar3 = RGE_Visible_Map::get_los_table(pRVar1->visible,iVar2,iVar4);
  return pLVar3;
}

// --------------------------------------------------

// Function: explore_terrain
// Address: 004c59b0
/* public: virtual int __thiscall RGE_Static_Object::explore_terrain(class RGE_Player *,unsigned
   char,int) */

int __thiscall
RGE_Static_Object::explore_terrain
          (RGE_Static_Object *this,RGE_Player *param_1,uchar param_2,int param_3)
{
  RGE_Visible_Map *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  
  if (param_1 != (RGE_Player *)0x0) {
    if (param_3 == -1) {
      param_3 = __ftol();
    }
    if (0 < param_3) {
      this_00 = param_1->visible;
      uVar4 = (uint)(param_1->id == param_1->world->curr_player);
      if (param_2 == '\0') {
        lVar6 = this->id;
        iVar5 = 0;
        iVar1 = __ftol();
        iVar2 = __ftol();
        iVar1 = RGE_Visible_Map::explore_terrain(this_00,iVar2,iVar1,param_3,iVar5,uVar4,lVar6);
        return iVar1;
      }
      if (((float)(double)DAT_00574718 < this->master_obj->radius_x) &&
         ((float)(double)DAT_00574718 < this->master_obj->radius_y)) {
        lVar6 = this->id;
        iVar1 = __ftol();
        iVar2 = __ftol();
        iVar5 = __ftol();
        iVar3 = __ftol();
        iVar1 = RGE_Visible_Map::explore_terrain_sq(this_00,iVar3,iVar5,iVar2,iVar1,uVar4,lVar6);
        return iVar1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: unexplore_terrain
// Address: 004c5aa0
/* public: virtual void __thiscall RGE_Static_Object::unexplore_terrain(class RGE_Player *,unsigned
   char,int) */

void __thiscall
RGE_Static_Object::unexplore_terrain
          (RGE_Static_Object *this,RGE_Player *param_1,uchar param_2,int param_3)
{
  RGE_Visible_Map *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  
  if (param_1 != (RGE_Player *)0x0) {
    if (param_3 == -1) {
      param_3 = __ftol();
    }
    if (0 < param_3) {
      this_00 = param_1->visible;
      uVar4 = (uint)(param_1->id == param_1->world->curr_player);
      if (param_2 == '\0') {
        lVar6 = this->id;
        iVar5 = 0;
        iVar1 = __ftol();
        iVar2 = __ftol();
        RGE_Visible_Map::unexplore_terrain(this_00,iVar2,iVar1,param_3,iVar5,uVar4,lVar6);
        return;
      }
      if (((float)(double)DAT_00574718 < this->master_obj->radius_x) &&
         ((float)(double)DAT_00574718 < this->master_obj->radius_y)) {
        lVar6 = this->id;
        iVar1 = __ftol();
        iVar2 = __ftol();
        iVar5 = __ftol();
        iVar3 = __ftol();
        RGE_Visible_Map::unexplore_terrain_sq(this_00,iVar3,iVar5,iVar2,iVar1,uVar4,lVar6);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: damage
// Address: 004c5b90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall RGE_Static_Object::damage(int,struct RGE_Armor_Weapon_Info
   *,float,class RGE_Player *,class RGE_Static_Object *) */

void __thiscall
RGE_Static_Object::damage
          (RGE_Static_Object *this,int param_1,RGE_Armor_Weapon_Info *param_2,float param_3,
          RGE_Player *param_4,RGE_Static_Object *param_5)
{
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(this->_padding_ + 0x74))(param_1,param_2,param_3,param_4,param_5);
  fVar1 = (float10)this->hp - fVar1;
  this->hp = (float)fVar1;
  if (fVar1 < (float10)_DAT_00574758) {
    this->hp = 0.0;
    set_sleep_flag(this,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: calculateDamage
// Address: 004c5be0
/* public: virtual float __thiscall RGE_Static_Object::calculateDamage(int,struct
   RGE_Armor_Weapon_Info *,float,class RGE_Player *,class RGE_Static_Object *) */

float __thiscall
RGE_Static_Object::calculateDamage
          (RGE_Static_Object *this,int param_1,RGE_Armor_Weapon_Info *param_2,float param_3,
          RGE_Player *param_4,RGE_Static_Object *param_5)
{
  short sVar1;
  float fVar2;
  short *psVar3;
  
  fVar2 = DAT_00574718._8_4_;
  if (0 < param_1) {
    psVar3 = &param_2->value;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 2;
      param_1 = param_1 + -1;
      fVar2 = (float)(int)sVar1 * param_3 + fVar2;
    } while (param_1 != 0);
  }
  return fVar2;
}

// --------------------------------------------------

// Function: rotate
// Address: 004c5c10
/* public: virtual void __thiscall RGE_Static_Object::rotate(long) */

void __thiscall RGE_Static_Object::rotate(RGE_Static_Object *this,long param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)this->sprite->facet_num;
  for (iVar1 = param_1 + (uint)this->facet; iVar1 < 0; iVar1 = iVar1 + iVar2) {
  }
  for (; iVar2 <= iVar1; iVar1 = iVar1 - iVar2) {
  }
  this->facet = (uchar)iVar1;
  return;
}

// --------------------------------------------------

// Function: set_attribute
// Address: 004c5c40
/* public: virtual void __thiscall RGE_Static_Object::set_attribute(short,float) */

void __thiscall
RGE_Static_Object::set_attribute(RGE_Static_Object *this,short param_1,float param_2)
{
  this->attribute_type_held = param_1;
  this->attribute_amount_held = param_2;
  return;
}

// --------------------------------------------------

// Function: set_attribute_amount
// Address: 004c5c60
/* public: virtual void __thiscall RGE_Static_Object::set_attribute_amount(float,unsigned
   char,unsigned char) */

void __thiscall
RGE_Static_Object::set_attribute_amount
          (RGE_Static_Object *this,float param_1,uchar param_2,uchar param_3)
{
  float fVar1;
  
  if (param_2 == '\0') {
    this->attribute_amount_held = param_1;
  }
  else {
    this->attribute_amount_held = param_1 + this->attribute_amount_held;
  }
  if ((param_3 != '\0') &&
     (fVar1 = (float)(int)this->master_obj->attribute_max_amount,
     fVar1 < this->attribute_amount_held)) {
    this->attribute_amount_held = fVar1;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: heal
// Address: 004c5cb0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Static_Object::heal(float) */

uchar __thiscall RGE_Static_Object::heal(RGE_Static_Object *this,float param_1)
{
  bool bVar1;
  float fVar2;
  
  bVar1 = param_1 < DAT_00574718._8_4_;
  fVar2 = param_1 + this->hp;
  this->hp = fVar2;
  if ((bVar1) && (fVar2 < _DAT_0057472c)) {
    this->hp = 1.0;
  }
  fVar2 = (float)(int)this->master_obj->hp;
  if (this->hp < fVar2) {
    return '\0';
  }
  this->hp = fVar2;
  return '\x01';
}

// --------------------------------------------------

// Function: notify_of_relation
// Address: 004c5d10
/* public: virtual void __thiscall RGE_Static_Object::notify_of_relation(long,unsigned char) */

void __thiscall
RGE_Static_Object::notify_of_relation(RGE_Static_Object *this,long param_1,uchar param_2)
{
  return;
}

// --------------------------------------------------

// Function: set_being_worked_on
// Address: 004c5d20
/* public: virtual void __thiscall RGE_Static_Object::set_being_worked_on(class RGE_Action_Object
   *,short,unsigned char) */

void __thiscall
RGE_Static_Object::set_being_worked_on
          (RGE_Static_Object *this,RGE_Action_Object *param_1,short param_2,uchar param_3)
{
  if (this->worker_num < 0xfa) {
    this->worker_num = this->worker_num + 1;
  }
  set_sleep_flag(this,'\0');
  return;
}

// --------------------------------------------------

// Function: release_being_worked_on
// Address: 004c5d40
/* public: virtual void __thiscall RGE_Static_Object::release_being_worked_on(class
   RGE_Static_Object *) */

void __thiscall
RGE_Static_Object::release_being_worked_on(RGE_Static_Object *this,RGE_Static_Object *param_1)
{
  if (this->worker_num != '\0') {
    this->worker_num = this->worker_num + 0xff;
  }
  if ((this->worker_num == '\0') &&
     (((this->object_state == '\x02' && (DAT_00574718._8_4_ <= this->hp)) ||
      (this->object_state == '\x06')))) {
    set_sleep_flag(this,'\x01');
  }
  return;
}

// --------------------------------------------------

// Function: inRange
// Address: 004c5d80
/* public: int __thiscall RGE_Static_Object::inRange(class RGE_Static_Object *,float) */

int __thiscall
RGE_Static_Object::inRange(RGE_Static_Object *this,RGE_Static_Object *param_1,float param_2)
{
  float fVar1;
  RGE_Static_Object *pRVar2;
  float dX;
  float local_4;
  
  pRVar2 = param_1;
  fVar1 = param_1->world_x - this->world_x;
  param_1 = (RGE_Static_Object *)(param_1->world_y - this->world_y);
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = -fVar1;
  }
  if ((float)param_1 < DAT_00574718._8_4_) {
    param_1 = (RGE_Static_Object *)-(float)param_1;
  }
  local_4 = (fVar1 - this->master_obj->radius_x) - pRVar2->master_obj->radius_x;
  fVar1 = ((float)param_1 - this->master_obj->radius_y) - pRVar2->master_obj->radius_y;
  if (local_4 < DAT_00574718._8_4_) {
    local_4 = 0.0;
  }
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = DAT_00574718._8_4_;
  }
  if (fVar1 * fVar1 + local_4 * local_4 < param_2 * param_2) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: distance_to_object
// Address: 004c5e50
/* public: float __thiscall RGE_Static_Object::distance_to_object(class RGE_Static_Object *) */

float __thiscall
RGE_Static_Object::distance_to_object(RGE_Static_Object *this,RGE_Static_Object *param_1)
{
  float fVar1;
  RGE_Static_Object *pRVar2;
  float dX;
  float local_4;
  
  pRVar2 = param_1;
  fVar1 = param_1->world_x - this->world_x;
  param_1 = (RGE_Static_Object *)(param_1->world_y - this->world_y);
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = -fVar1;
  }
  if ((float)param_1 < DAT_00574718._8_4_) {
    param_1 = (RGE_Static_Object *)-(float)param_1;
  }
  local_4 = (fVar1 - this->master_obj->radius_x) - pRVar2->master_obj->radius_x;
  fVar1 = ((float)param_1 - this->master_obj->radius_y) - pRVar2->master_obj->radius_y;
  if (local_4 < DAT_00574718._8_4_) {
    local_4 = 0.0;
  }
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = DAT_00574718._8_4_;
  }
  return SQRT(fVar1 * fVar1 + local_4 * local_4);
}

// --------------------------------------------------

// Function: distance_to_position
// Address: 004c5f00
/* public: float __thiscall RGE_Static_Object::distance_to_position(float,float,float) */

float __thiscall
RGE_Static_Object::distance_to_position
          (RGE_Static_Object *this,float param_1,float param_2,float param_3)
{
  float fVar1;
  
  fVar1 = this->world_x - param_1;
  param_1 = this->world_y - param_2;
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = -fVar1;
  }
  if (param_1 < DAT_00574718._8_4_) {
    param_1 = -param_1;
  }
  param_2 = fVar1 - this->master_obj->radius_x;
  fVar1 = param_1 - this->master_obj->radius_y;
  if (param_2 < DAT_00574718._8_4_) {
    param_2 = 0.0;
  }
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = DAT_00574718._8_4_;
  }
  return SQRT(fVar1 * fVar1 + param_2 * param_2);
}

// --------------------------------------------------

// Function: hit_test
// Address: 004c5fa0
/* public: unsigned char __thiscall RGE_Static_Object::hit_test(short,short,short,short,short) */

uchar __thiscall
RGE_Static_Object::hit_test
          (RGE_Static_Object *this,short param_1,short param_2,short param_3,short param_4,
          short param_5)
{
  uchar uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short unaff_retaddr;
  
  if ((this->sprite != (RGE_Sprite *)0x0) && (this->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    sVar2 = (**(code **)(this->sprite_list->_padding_ + 4))(this->sprite);
    sVar7 = (param_3 - this->screen_y_offset) - param_1;
    sVar4 = (param_2 - this->screen_x_offset) - unaff_retaddr;
    uVar1 = RGE_Sprite::hit_test(this->sprite,sVar4,sVar7,(uint)this->facet,(int)sVar2);
    if (uVar1 != '\0') {
      return '\x01';
    }
    if ((param_4 != 0) && (sVar5 = -param_4, sVar3 = sVar5, sVar5 < param_4)) {
      do {
        if (sVar5 < param_4) {
          sVar8 = sVar7 + sVar5;
          sVar6 = sVar5;
          do {
            uVar1 = RGE_Sprite::hit_test
                              (this->sprite,sVar4 + sVar3,sVar8,(uint)this->facet,(int)sVar2);
            if (uVar1 != '\0') {
              return '\x01';
            }
            sVar6 = sVar6 + 1;
            sVar8 = sVar8 + 1;
          } while (sVar6 < param_4);
        }
        sVar3 = sVar3 + 1;
      } while (sVar3 < param_4);
      return '\0';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: box_hit_test
// Address: 004c60a0
/* WARNING: Variable defined which should be unmapped: min_x */
/* public: unsigned char __thiscall
   RGE_Static_Object::box_hit_test(short,short,short,short,short,short) */

uchar __thiscall
RGE_Static_Object::box_hit_test
          (RGE_Static_Object *this,short param_1,short param_2,short param_3,short param_4,
          short param_5,short param_6)
{
  short sVar1;
  int iVar2;
  short sVar3;
  short unaff_BX;
  short sVar4;
  short unaff_BP;
  short sVar5;
  short unaff_retaddr;
  short min_x;
  short min_y;
  short max_x;
  short max_y;
  short sStack_4;
  
  if ((this->sprite != (RGE_Sprite *)0x0) && (this->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    min_x = unaff_BX;
    (**(code **)(this->sprite_list->_padding_ + 0x28))(this->sprite,this->facet);
    iVar2 = get_frame(this,(short *)&stack0xffffffe8,&min_x,&min_y,&max_x);
    if (iVar2 == 0) {
      return '\0';
    }
    sVar5 = unaff_BP + sStack_4 + this->screen_x_offset;
    sVar3 = min_y + this->screen_x_offset + sStack_4;
    sVar1 = max_x + unaff_retaddr + this->screen_y_offset;
    sVar4 = min_x + unaff_retaddr + this->screen_y_offset;
    if ((((param_1 <= sVar5) && (sVar5 <= param_3)) && (param_2 <= sVar4)) && (sVar4 <= param_4)) {
      return '\x01';
    }
    if (((param_1 <= sVar3) && (sVar3 <= param_3)) && ((param_2 <= sVar1 && (sVar1 <= param_4)))) {
      return '\x01';
    }
    if (((sVar5 <= param_1) && (param_1 <= sVar3)) && ((sVar4 <= param_2 && (param_2 <= sVar1)))) {
      return '\x01';
    }
    if ((((sVar5 <= param_3) && (param_3 <= sVar3)) && (sVar4 <= param_4)) && (param_4 <= sVar1)) {
      return '\x01';
    }
    if ((param_1 < sVar5) && (sVar3 < param_3)) {
      if ((sVar4 < param_2) && (param_2 < sVar1)) {
        return '\x01';
      }
      if ((sVar4 < param_4) && (param_4 < sVar1)) {
        return '\x01';
      }
    }
    if (((param_2 < sVar4) && (sVar1 < param_4)) &&
       (((sVar5 < param_1 && (param_1 < sVar3)) || ((sVar5 < param_3 && (param_3 < sVar3)))))) {
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: set_location
// Address: 004c6240
/* public: void __thiscall RGE_Static_Object::set_location(float,float,float) */

void __thiscall
RGE_Static_Object::set_location(RGE_Static_Object *this,float param_1,float param_2,float param_3)
{
  this->world_x = param_1;
  this->world_y = param_2;
  this->world_z = param_3;
  return;
}

// --------------------------------------------------

// Function: new_angle
// Address: 004c6260
/* public: virtual void __thiscall RGE_Static_Object::new_angle(float) */

void __thiscall RGE_Static_Object::new_angle(RGE_Static_Object *this,float param_1)
{
  return;
}

// --------------------------------------------------

// Function: drop_held_objects
// Address: 004c6270
/* WARNING: Variable defined which should be unmapped: count */
/* public: unsigned char __thiscall RGE_Static_Object::drop_held_objects(int) */

uchar __thiscall RGE_Static_Object::drop_held_objects(RGE_Static_Object *this,int param_1)
{
  float fVar1;
  float fVar2;
  RGE_Static_Object *this_00;
  RGE_Object_Node *pRVar3;
  uchar uVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  uchar count;
  RGE_Object_Node *temp;
  float x;
  float y;
  RGE_Object_Node *next;
  float drop_y [10];
  float radius_x [10];
  float drop_x [10];
  float radius_y [10];
  
  drop_x[1] = this->world_x;
  drop_y[1] = this->world_y;
  temp._3_1_ = '\0';
  fVar1 = this->master_obj->radius_x;
  radius_x[1] = fVar1 + fVar1;
  fVar1 = this->master_obj->radius_y;
  radius_y[1] = fVar1 + fVar1;
  iVar7 = 1;
  drop_y[0] = (float)this->objects->list;
  do {
    do {
      pRVar3 = (RGE_Object_Node *)drop_y[0];
      if (pRVar3 == (RGE_Object_Node *)0x0) {
        return temp._3_1_;
      }
      drop_y[0] = (float)pRVar3->next;
    } while (iVar7 < 1);
    pfVar5 = radius_y + iVar7 + 1;
    iVar6 = iVar7;
    pfVar8 = radius_x + iVar7 + 1;
    do {
      uVar4 = find_drop_location(this,param_1,&y,(float *)&next,pRVar3->node->master_obj,
                                 pRVar3->node,drop_x[1],drop_y[1],radius_x[1],radius_y[1]);
      if (uVar4 != '\0') {
        this_00 = pRVar3->node;
        set_location(this_00,this->world_x,this->world_y,this->world_z);
        iVar7 = this_00->_padding_;
        (**(code **)(iVar7 + 0xd4))();
        (**(code **)(iVar7 + 0x34))(y,next,this->world_z);
        temp._3_1_ = temp._3_1_ + '\x01';
        iVar7 = iVar6;
        if (iVar6 < 9) {
          iVar7 = iVar6 + 1;
          fVar1 = this_00->master_obj->radius_y;
          fVar2 = this_00->master_obj->radius_x;
          drop_x[iVar6 + 1] = y;
          drop_y[iVar6 + 1] = (float)next;
          radius_x[iVar6 + 1] = fVar2 + fVar2;
          radius_y[iVar6 + 1] = fVar1 + fVar1;
        }
        break;
      }
      iVar7 = iVar6 + -1;
      if (iVar7 < 1) break;
      fVar1 = drop_y[iVar6];
      drop_x[iVar7] = drop_x[iVar6];
      pfVar5[-2] = pfVar5[-1];
      drop_y[iVar7] = fVar1;
      pfVar8[-2] = pfVar8[-1];
      pfVar5 = pfVar5 + -1;
      iVar6 = iVar7;
      pfVar8 = pfVar8 + -1;
    } while (0 < iVar7);
  } while( true );
}

// --------------------------------------------------

// Function: find_drop_location
// Address: 004c6400
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
/* WARNING: Variable defined which should be unmapped: radius_2y */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: unsigned char __thiscall RGE_Static_Object::find_drop_location(int,float &,float &,class
   RGE_Master_Static_Object *,class RGE_Static_Object *,float,float,float,float) */

uchar __thiscall
RGE_Static_Object::find_drop_location
          (RGE_Static_Object *this,int param_1,float *param_2,float *param_3,
          RGE_Master_Static_Object *param_4,RGE_Static_Object *param_5,float param_6,float param_7,
          float param_8,float param_9)
{
  RGE_Map *pRVar1;
  float *pfVar2;
  float *pfVar3;
  RGE_Master_Static_Object *pRVar4;
  byte bVar5;
  char cVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  float radius_2y;
  short index;
  
  pRVar4 = param_4;
  pfVar3 = param_3;
  pfVar2 = param_2;
  param_8 = param_8 + param_4->radius_x;
  param_9 = param_9 + param_4->radius_y;
  param_4 = (RGE_Master_Static_Object *)(param_8 + param_8);
  _index = param_9 + param_9;
  sVar7 = 1;
  do {
    param_3 = (float *)0x0;
    do {
      iVar8 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf3a);
      switch((iVar8 * 4) / 0x7fff) {
      case 0:
                    /* language.dll match for 0xf3e: "Right-click to attack this building." */
        *pfVar2 = param_8 + param_6;
        iVar8 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf3e);
        *pfVar3 = ((float)iVar8 * _index * _DAT_00574764 - param_9) + param_7;
        break;
      case 1:
                    /* language.dll match for 0xf42: "Right-click to board this transport." */
        *pfVar2 = param_6 - param_8;
        iVar8 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf42);
        *pfVar3 = ((float)iVar8 * _index * _DAT_00574764 - param_9) + param_7;
        break;
      case 2:
                    /* language.dll match for 0xf46: "Right-click to hunt this animal." */
        *pfVar3 = param_9 + param_7;
        param_2 = (float *)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf46);
        goto LAB_004c654e;
      case 3:
        *pfVar3 = param_7 - param_9;
        param_2 = (float *)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf4a);
LAB_004c654e:
        *pfVar2 = ((float)(int)param_2 * (float)param_4 * _DAT_00574764 - param_8) + param_6;
      }
      if ((((DAT_00574718._8_4_ <= *pfVar2) && (DAT_00574718._8_4_ <= *pfVar3)) &&
          (pRVar1 = this->owner->world->map, *pfVar2 < (float)pRVar1->map_width)) &&
         (*pfVar3 < (float)pRVar1->map_height)) {
        if (param_1 != -1) {
          iVar8 = __ftol();
          iVar9 = __ftol();
          bVar5 = lookupZone(this,iVar9,iVar8);
          if (param_1 != (uint)bVar5) goto LAB_004c6614;
        }
        cVar6 = (**(code **)(pRVar4->_padding_ + 0x20))(this->owner,*pfVar2,*pfVar3,0,1,1,1,0,1,1);
        if ((cVar6 == '\0') &&
           (iVar8 = (**(code **)(param_5->_padding_ + 0x114))(*pfVar2,*pfVar3,0), iVar8 == 1)) {
          return '\x01';
        }
      }
LAB_004c6614:
      param_3 = (float *)((int)param_3 + 1);
    } while ((short)param_3 < 0x32);
    param_8 = pRVar4->radius_x + pRVar4->radius_x + param_8;
    param_9 = pRVar4->radius_y + pRVar4->radius_y + param_9;
    param_4 = (RGE_Master_Static_Object *)(pRVar4->radius_x * _DAT_00574768 + (float)param_4);
    _index = pRVar4->radius_y * _DAT_00574768 + _index;
    sVar7 = sVar7 + 1;
    if (1 < sVar7) {
      return '\0';
    }
  } while( true );
}

// --------------------------------------------------

// Function: make_object_bounds_list
// Address: 004c6740
/* public: class RGE_Check_List * __thiscall RGE_Static_Object::make_object_bounds_list(float) */

RGE_Check_List * __thiscall
RGE_Static_Object::make_object_bounds_list(RGE_Static_Object *this,float param_1)
{
  float fVar1;
  RGE_Master_Static_Object *pRVar2;
  float fVar3;
  RGE_Map *pRVar4;
  undefined4 *puVar5;
  RGE_Static_Object *pRVar6;
  float fVar7;
  float fVar8;
  uchar uVar9;
  short sVar10;
  short sVar11;
  RGE_Check_List *this_00;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *unaff_FS_OFFSET;
  short x2;
  uchar flag;
  float dy;
  float dx;
  short x1;
  short local_38;
  float rx2;
  float ry2;
  float ry;
  RGE_Map *map;
  RGE_Check_List *check_list;
  RGE_Check_List *local_1c;
  float rx;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fa3b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar2 = this->master_obj;
  fVar1 = pRVar2->radius_x;
  fVar3 = pRVar2->radius_y;
  if (((fVar1 <= DAT_00574718._8_4_) || (fVar3 <= DAT_00574718._8_4_)) ||
     (pRVar2->radius_z <= (float)(double)DAT_00574718)) {
    _x2 = (RGE_Check_List *)0x0;
  }
  else {
    local_38 = __ftol();
    sVar10 = __ftol();
    _flag = __ftol();
    sVar11 = __ftol();
    pRVar4 = this->owner->world->map;
    this_00 = (RGE_Check_List *)operator_new(4);
    local_4 = 0;
    if (this_00 == (RGE_Check_List *)0x0) {
      _x2 = (RGE_Check_List *)0x0;
    }
    else {
      _x2 = (RGE_Check_List *)RGE_Check_List::RGE_Check_List(this_00);
    }
    local_4 = 0xffffffff;
    if (local_38 < 0) {
      local_38 = 0;
    }
    if (pRVar4->map_width <= (int)_flag) {
      _flag = (short)pRVar4->map_width + -1;
    }
    if (sVar10 < 0) {
      sVar10 = 0;
    }
    if (pRVar4->map_height <= (int)sVar11) {
      sVar11 = (short)pRVar4->map_height + -1;
    }
    if (sVar10 <= sVar11) {
      rx2 = (float)(sVar10 * 4);
      check_list = (RGE_Check_List *)(((int)sVar11 - (int)sVar10) + 1);
      do {
        if (local_38 <= _flag) {
          puVar13 = (undefined4 *)
                    (*(int *)((int)rx2 + (int)pRVar4->map_row_offset) + local_38 * 0x18 + 0x10);
          iVar12 = ((int)_flag - (int)local_38) + 1;
          do {
            for (puVar5 = (undefined4 *)*puVar13; puVar5 != (undefined4 *)0x0;
                puVar5 = (undefined4 *)puVar5[1]) {
              pRVar6 = (RGE_Static_Object *)*puVar5;
              if (pRVar6 != this) {
                pRVar2 = pRVar6->master_obj;
                if (((DAT_00574718._8_4_ < pRVar2->radius_y) &&
                    (DAT_00574718._8_4_ < pRVar2->radius_x)) &&
                   ((fVar7 = pRVar6->world_z - this->world_z, -pRVar2->radius_z <= fVar7 &&
                    (fVar7 <= this->master_obj->radius_z)))) {
                  fVar7 = pRVar6->world_x - this->world_x;
                  uVar9 = fVar7 < DAT_00574718._8_4_;
                  fVar8 = pRVar6->world_y - this->world_y;
                  if ((bool)uVar9) {
                    fVar7 = -fVar7;
                  }
                  if (fVar8 < DAT_00574718._8_4_) {
                    uVar9 = uVar9 + '\x02';
                    fVar8 = -fVar8;
                  }
                  fVar7 = fVar7 - (pRVar2->radius_x + fVar1);
                  fVar8 = fVar8 - (pRVar2->radius_y + fVar3);
                  if (((fVar7 < param_1) && (fVar8 < param_1)) &&
                     ((DAT_00574718._8_4_ <= fVar8 || (DAT_00574718._8_4_ <= fVar7)))) {
                    RGE_Check_List::add_node(_x2,pRVar6,fVar7,fVar8,uVar9);
                  }
                }
              }
            }
            puVar13 = puVar13 + 6;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
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
      local_1c = (RGE_Check_List *)0x0;
      _x2 = local_1c;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return _x2;
}

// --------------------------------------------------

// Function: boundToFacet
// Address: 004c6aa0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall RGE_Static_Object::boundToFacet(float,float,int) */

int __thiscall
RGE_Static_Object::boundToFacet(RGE_Static_Object *this,float param_1,float param_2,int param_3)
{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar5 = (float10)param_2;
  iVar2 = -1;
  param_2 = 0.0;
  fVar5 = (float10)fpatan((float10)this->world_y - fVar5,(float10)this->world_x - (float10)param_1);
  if (fVar5 < (float10)DAT_00574718._8_4_) {
    fVar5 = fVar5 - (float10)_DAT_0057476c;
  }
  fVar3 = (float10)DAT_00574718._8_4_;
  if (param_3 == -1) {
    param_3 = (int)this->sprite->facet_num;
  }
  iVar1 = 0;
  if (0 < param_3) {
    do {
      fVar4 = fVar5 - fVar3;
      if (fVar4 < (float10)DAT_00574718._8_4_) {
        fVar4 = -fVar4;
      }
      if ((iVar2 == -1) || (fVar4 < (float10)param_2)) {
        param_2 = (float)fVar4;
        iVar2 = iVar1;
      }
      fVar3 = fVar3 + (float10)(_DAT_00574770 / (float)param_3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_3);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: numberFacets
// Address: 004c6b50
/* public: int __thiscall RGE_Static_Object::numberFacets(void) */

int __thiscall RGE_Static_Object::numberFacets(RGE_Static_Object *this)
{
  if (this->sprite != (RGE_Sprite *)0x0) {
    return (int)this->sprite->facet_num;
  }
  return 0;
}

// --------------------------------------------------

// Function: underAttack
// Address: 004c6b60
/* public: virtual unsigned char __thiscall RGE_Static_Object::underAttack(void)const  */

uchar __thiscall RGE_Static_Object::underAttack(RGE_Static_Object *this)
{
  return this->underAttackValue;
}

// --------------------------------------------------

// Function: setUnderAttack
// Address: 004c6b70
/* public: virtual void __thiscall RGE_Static_Object::setUnderAttack(unsigned char) */

void __thiscall RGE_Static_Object::setUnderAttack(RGE_Static_Object *this,uchar param_1)
{
  this->underAttackValue = param_1;
  return;
}

// --------------------------------------------------

// Function: addToObstructionMap
// Address: 004c6b80
/* WARNING: Variable defined which should be unmapped: obMapMinY */
/* public: int __thiscall RGE_Static_Object::addToObstructionMap(int) */

int __thiscall RGE_Static_Object::addToObstructionMap(RGE_Static_Object *this,int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int obMapMinY;
  int obMapMaxX;
  
  if (this->master_obj->radius_z <= DAT_00574718._8_4_) {
    return 0;
  }
  if (this->inObstructionMapValue != '\x01') {
    iVar2 = __ftol();
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    obMapMaxX = __ftol();
    if (obMapMaxX < 0) {
      obMapMaxX = 0;
    }
    iVar3 = __ftol();
    iVar4 = __ftol();
    for (; iVar1 = obMapMaxX, iVar2 < iVar3; iVar2 = iVar2 + 1) {
      for (; iVar1 < iVar4; iVar1 = iVar1 + 1) {
        if (param_1 != 1) {
          PathingSystem::incrementObstruction(&pathSystem,iVar2,iVar1);
        }
        if (param_1 != 0) {
          PathingSystem::incrementObstruction(&aiPathSystem,iVar2,iVar1);
        }
      }
    }
    this->lastInObstructionMapValue = this->inObstructionMapValue;
    this->inObstructionMapValue = '\x01';
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: removeFromObstructionMap
// Address: 004c6c90
/* WARNING: Variable defined which should be unmapped: obMapMinY */
/* public: int __thiscall RGE_Static_Object::removeFromObstructionMap(int) */

int __thiscall RGE_Static_Object::removeFromObstructionMap(RGE_Static_Object *this,int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int obMapMinY;
  int obMapMaxX;
  
  if (this->master_obj->radius_z <= DAT_00574718._8_4_) {
    return 0;
  }
  if (this->inObstructionMapValue != '\0') {
    iVar2 = __ftol();
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    obMapMaxX = __ftol();
    if (obMapMaxX < 0) {
      obMapMaxX = 0;
    }
    iVar3 = __ftol();
    iVar4 = __ftol();
    for (; iVar1 = obMapMaxX, iVar2 < iVar3; iVar2 = iVar2 + 1) {
      for (; iVar1 < iVar4; iVar1 = iVar1 + 1) {
        if (param_1 != 1) {
          PathingSystem::decrementObstruction(&pathSystem,iVar2,iVar1);
        }
        if (param_1 != 0) {
          PathingSystem::decrementObstruction(&aiPathSystem,iVar2,iVar1);
        }
      }
    }
    this->lastInObstructionMapValue = this->inObstructionMapValue;
    this->inObstructionMapValue = '\0';
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: changeInfluenceMap
// Address: 004c6da0
/* WARNING: Variable defined which should be unmapped: objectMaxX */
/* public: void __thiscall RGE_Static_Object::changeInfluenceMap(class InfluenceMap *,int,int,int)
    */

void __thiscall
RGE_Static_Object::changeInfluenceMap
          (RGE_Static_Object *this,InfluenceMap *param_1,int param_2,int param_3,int param_4)
{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  float objectMaxX;
  float objectMinY;
  float objectMaxY;
  int maxXTile;
  int maxYTile;
  int minXTile;
  int y;
  
  fVar1 = this->world_x - this->master_obj->radius_x;
  if (param_4 == 0) {
    floor((double)fVar1);
    y = __ftol();
    ceil((double)(this->master_obj->radius_x + this->world_x));
    maxYTile = __ftol();
    floor((double)(this->world_y - this->master_obj->radius_y));
    iVar3 = __ftol();
    fVar1 = this->master_obj->radius_y;
  }
  else {
    floor((double)(fVar1 - this->master_obj->los));
    y = __ftol();
    ceil((double)(this->master_obj->radius_x + this->master_obj->los + this->world_x));
    maxYTile = __ftol();
    floor((double)((this->world_y - this->master_obj->radius_y) - this->master_obj->los));
    iVar3 = __ftol();
    fVar1 = this->master_obj->radius_y + this->master_obj->los;
  }
  ceil((double)(fVar1 + this->world_y));
  iVar4 = __ftol();
  do {
    iVar2 = y;
    if (iVar4 <= iVar3) {
      return;
    }
    for (; iVar2 < maxYTile; iVar2 = iVar2 + 1) {
      if (param_3 == 0) {
        uVar6 = CONCAT44(0xff,iVar3);
        if (param_2 != 1) goto LAB_004c6ff6;
        InfluenceMap::incrementValue(param_1,iVar2,iVar3,0xff);
      }
      else {
        uVar5 = __ftol();
        uVar6 = CONCAT44(uVar5,iVar3);
        if (param_2 == 1) {
          InfluenceMap::incrementValue(param_1,iVar2,iVar3,(uchar)uVar5);
        }
        else {
LAB_004c6ff6:
          InfluenceMap::decrementValue(param_1,iVar2,(int)uVar6,(uchar)((ulonglong)uVar6 >> 0x20));
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: objectCollisionList
// Address: 004c7030
/* WARNING: Variable defined which should be unmapped: dz */
/* public: class RGE_Check_List * __thiscall RGE_Static_Object::objectCollisionList(float) */

RGE_Check_List * __thiscall
RGE_Static_Object::objectCollisionList(RGE_Static_Object *this,float param_1)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Map *pRVar2;
  undefined4 *puVar3;
  RGE_Static_Object *pRVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  RGE_Check_List *this_00;
  RGE_Check_List *this_01;
  undefined4 *unaff_FS_OFFSET;
  float dz;
  float tempRX;
  float tempRY;
  int minXTile;
  int local_2c;
  int maxXTile;
  int maxYTile;
  int local_20;
  int yIndex;
  RGE_Map *map;
  undefined4 local_c;
  code *pcStack_8;
  RGE_Check_List *local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = (RGE_Check_List *)0xffffffff;
  pcStack_8 = FUN_0055fa5b;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = this->master_obj;
  if (((pRVar1->radius_x <= DAT_00574718._8_4_) || (pRVar1->radius_y <= DAT_00574718._8_4_)) ||
     (pRVar1->radius_z <= (float)(double)DAT_00574718)) {
    this_01 = (RGE_Check_List *)0x0;
  }
  else {
    pRVar2 = this->owner->world->map;
    iVar8 = __ftol();
    local_2c = iVar8 + -3;
    iVar8 = iVar8 + 3;
    iVar9 = __ftol();
    local_20 = iVar9 + 3;
    iVar9 = iVar9 + -3;
    if (local_2c < 0) {
      local_2c = 0;
    }
    if (pRVar2->map_width <= iVar8) {
      iVar8 = pRVar2->map_width + -1;
    }
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    if (pRVar2->map_height <= local_20) {
      local_20 = pRVar2->map_height + -1;
    }
    this_01 = (RGE_Check_List *)0x0;
    for (; iVar9 <= local_20; iVar9 = iVar9 + 1) {
      if (local_2c <= iVar8) {
        maxXTile = (int)&pRVar2->map_row_offset[iVar9][local_2c].objects.list;
        iVar10 = (iVar8 - local_2c) + 1;
        do {
          for (puVar3 = *(undefined4 **)maxXTile; puVar3 != (undefined4 *)0x0;
              puVar3 = (undefined4 *)puVar3[1]) {
            pRVar4 = (RGE_Static_Object *)*puVar3;
            if ((pRVar4 != this) &&
               (pRVar1 = pRVar4->master_obj, (float)(double)DAT_00574718 < pRVar1->radius_z)) {
              fVar5 = pRVar1->radius_x;
              fVar6 = pRVar1->radius_y;
              if ((((DAT_00574718._8_4_ < fVar5) && (DAT_00574718._8_4_ < fVar6)) &&
                  ((fVar7 = pRVar4->world_z - this->world_z, fVar7 <= DAT_00574718._8_4_ ||
                   (fVar7 <= this->master_obj->radius_z)))) &&
                 ((DAT_00574718._8_4_ <= fVar7 || (-pRVar1->radius_z <= fVar7)))) {
                pRVar1 = this->master_obj;
                if (pRVar4->world_x <= this->world_x) {
                  if (-param_1 <= (fVar5 + pRVar4->world_x) - (this->world_x - pRVar1->radius_x))
                  goto LAB_004c724b;
                }
                else if ((pRVar4->world_x - fVar5) - (pRVar1->radius_x + this->world_x) <= param_1)
{
LAB_004c724b:
                  if (pRVar4->world_y <= this->world_y) {
                    if (-param_1 <= (fVar6 + pRVar4->world_y) - (this->world_y - pRVar1->radius_y))
                    goto LAB_004c7298;
                  }
                  else if ((pRVar4->world_y - fVar6) - (pRVar1->radius_y + this->world_y) <= param_1
                          ) {
LAB_004c7298:
                    if (this_01 == (RGE_Check_List *)0x0) {
                      this_00 = (RGE_Check_List *)operator_new(4);
                      if (this_00 == (RGE_Check_List *)0x0) {
                        this_01 = (RGE_Check_List *)0x0;
                      }
                      else {
                        local_4 = this_01;
                        this_01 = (RGE_Check_List *)RGE_Check_List::RGE_Check_List(this_00);
                      }
                      local_4 = (RGE_Check_List *)0xffffffff;
                    }
                    RGE_Check_List::add_node(this_01,pRVar4,0.0,0.0,'\0');
                  }
                }
              }
            }
          }
          maxXTile = maxXTile + 0x18;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this_01;
}

// --------------------------------------------------

// Function: logDebug
// Address: 004c7340
// [HELPER] s_UNIT___5d_: "UNIT #%5d\n"
// [HELPER] s_UNIT___5d___s_: "UNIT #%5d: %s\n"
// [HELPER] s_WORLD_TIME___ld_: "WORLD TIME: %ld\n"
// [HELPER] s_c__aoeunit_txt: "c:\aoeunit.txt"
// [HELPER] s_w: "w"
/* WARNING: Variable defined which should be unmapped: textOut */
/* public: virtual void __cdecl RGE_Static_Object::logDebug(char *,...) */

void __thiscall RGE_Static_Object::logDebug(RGE_Static_Object *this,char *param_1,...)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 in_stack_00000008;
  char textOut [1024];
  
  if ((logDebugID == -1) || (logDebugID == *(int *)(param_1 + 4))) {
    if (debugOut == (_iobuf *)0x0) {
      debugOut = (_iobuf *)fopen(s_c__aoeunit_txt,s_w);
      if (debugOut == (_iobuf *)0x0) {
        return;
      }
      fprintf(debugOut,s_WORLD_TIME___ld_,
              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 4));
    }
    vsprintf(textOut + 4,in_stack_00000008,&stack0x0000000c);
    iVar2 = -1;
    pcVar3 = textOut + 4;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      fprintf(debugOut,s_UNIT___5d___s_,*(undefined4 *)(param_1 + 4),textOut + 4);
      return;
    }
    fprintf(debugOut,s_UNIT___5d_,*(undefined4 *)(param_1 + 4));
  }
  return;
}

// --------------------------------------------------

// Function: unitAI
// Address: 004c7420
/* public: class UnitAIModule * __thiscall RGE_Static_Object::unitAI(void) */

UnitAIModule * __thiscall RGE_Static_Object::unitAI(RGE_Static_Object *this)
{
  return this->unitAIValue;
}

// --------------------------------------------------

// Function: lookupZone
// Address: 004c7430
/* public: unsigned char __thiscall RGE_Static_Object::lookupZone(struct XYPoint) */

uchar __thiscall RGE_Static_Object::lookupZone(RGE_Static_Object *this,XYPoint param_1)
{
  RGE_Game_World *pRVar1;
  uchar uVar2;
  RGE_Zone_Map *this_00;
  
  if ((-1 < param_1.x) && (-1 < (longlong)param_1)) {
    if (this->zoneMapIndex == -1) {
      pRVar1 = this->owner->world;
      this_00 = RGE_Zone_Map_List::get_zone_map
                          (pRVar1->map->map_zones,pRVar1->terrains[this->master_obj->terrain],
                           (int)pRVar1->terrain_size,&this->zoneMapIndex);
    }
    else {
      this_00 = RGE_Zone_Map_List::get_zone_map
                          (this->owner->world->map->map_zones,this->zoneMapIndex);
    }
    if (this_00 != (RGE_Zone_Map *)0x0) {
      uVar2 = RGE_Zone_Map::get_zone_info(this_00,param_1.x,param_1.y);
      return uVar2;
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: lookupZone
// Address: 004c74b0
/* public: unsigned char __thiscall RGE_Static_Object::lookupZone(int,int) */

uchar __thiscall RGE_Static_Object::lookupZone(RGE_Static_Object *this,int param_1,int param_2)
{
  RGE_Game_World *pRVar1;
  uchar uVar2;
  RGE_Zone_Map *this_00;
  
  if ((-1 < param_1) && (-1 < param_2)) {
    if (this->zoneMapIndex == -1) {
      pRVar1 = this->owner->world;
      this_00 = RGE_Zone_Map_List::get_zone_map
                          (pRVar1->map->map_zones,pRVar1->terrains[this->master_obj->terrain],
                           (int)pRVar1->terrain_size,&this->zoneMapIndex);
    }
    else {
      this_00 = RGE_Zone_Map_List::get_zone_map
                          (this->owner->world->map->map_zones,this->zoneMapIndex);
    }
    if (this_00 != (RGE_Zone_Map *)0x0) {
      uVar2 = RGE_Zone_Map::get_zone_info(this_00,param_1,param_2);
      return uVar2;
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: currentZone
// Address: 004c7530
/* public: unsigned char __thiscall RGE_Static_Object::currentZone(void) */

uchar __thiscall RGE_Static_Object::currentZone(RGE_Static_Object *this)
{
  RGE_Game_World *pRVar1;
  uchar uVar2;
  RGE_Zone_Map *this_00;
  long lVar3;
  long lVar4;
  
  if (this->zoneMapIndex == -1) {
    pRVar1 = this->owner->world;
    this_00 = RGE_Zone_Map_List::get_zone_map
                        (pRVar1->map->map_zones,pRVar1->terrains[this->master_obj->terrain],
                         (int)pRVar1->terrain_size,&this->zoneMapIndex);
  }
  else {
    this_00 = RGE_Zone_Map_List::get_zone_map(this->owner->world->map->map_zones,this->zoneMapIndex)
    ;
  }
  if (this_00 != (RGE_Zone_Map *)0x0) {
    lVar3 = __ftol();
    lVar4 = __ftol();
    uVar2 = RGE_Zone_Map::get_zone_info(this_00,lVar4,lVar3);
    return uVar2;
  }
  return '\0';
}

// --------------------------------------------------

// Function: withinRangeOfZoneAtPoint
// Address: 004c75b0
/* public: int __thiscall RGE_Static_Object::withinRangeOfZoneAtPoint(unsigned char,float,struct
   XYPoint &) */

int __thiscall
RGE_Static_Object::withinRangeOfZoneAtPoint
          (RGE_Static_Object *this,uchar param_1,float param_2,XYPoint *param_3)
{
  RGE_Game_World *pRVar1;
  RGE_Zone_Map *this_00;
  int iVar2;
  
  if (this->zoneMapIndex == -1) {
    pRVar1 = this->owner->world;
    this_00 = RGE_Zone_Map_List::get_zone_map
                        (pRVar1->map->map_zones,pRVar1->terrains[this->master_obj->terrain],
                         (int)pRVar1->terrain_size,&this->zoneMapIndex);
  }
  else {
    this_00 = RGE_Zone_Map_List::get_zone_map(this->owner->world->map->map_zones,this->zoneMapIndex)
    ;
  }
  if (this_00 != (RGE_Zone_Map *)0x0) {
    iVar2 = RGE_Zone_Map::withinRange(this_00,param_1,*param_3,param_2);
    return iVar2;
  }
  return 0;
}

// --------------------------------------------------

// Function: withinRangeOfZone
// Address: 004c7630
/* public: int __thiscall RGE_Static_Object::withinRangeOfZone(unsigned char,float) */

int __thiscall
RGE_Static_Object::withinRangeOfZone(RGE_Static_Object *this,uchar param_1,float param_2)
{
  RGE_Game_World *pRVar1;
  XYPoint XVar2;
  int iVar3;
  int iVar4;
  RGE_Zone_Map *this_00;
  int iVar5;
  
  iVar3 = __ftol();
  iVar4 = __ftol();
  iVar5 = this->zoneMapIndex;
  if (iVar5 == -1) {
    pRVar1 = this->owner->world;
    this_00 = RGE_Zone_Map_List::get_zone_map
                        (pRVar1->map->map_zones,pRVar1->terrains[this->master_obj->terrain],
                         (int)pRVar1->terrain_size,&this->zoneMapIndex);
  }
  else {
    this_00 = RGE_Zone_Map_List::get_zone_map(this->owner->world->map->map_zones,iVar5);
  }
  if (this_00 != (RGE_Zone_Map *)0x0) {
    XVar2.y = iVar4;
    XVar2.x = iVar3;
    iVar5 = RGE_Zone_Map::withinRange(this_00,param_1,XVar2,param_2);
    return iVar5;
  }
  return 0;
}

// --------------------------------------------------

// Function: findClosestPointInTerrainType
// Address: 004c76c0
/* public: int __thiscall RGE_Static_Object::findClosestPointInTerrainType(struct XYPoint,struct
   XYPoint &,int,int,int) */

int __thiscall
RGE_Static_Object::findClosestPointInTerrainType
          (RGE_Static_Object *this,XYPoint param_1,XYPoint *param_2,int param_3,int param_4,
          int param_5)
{
  RGE_Game_World *pRVar1;
  RGE_Zone_Map *this_00;
  int iVar2;
  
  if (this->zoneMapIndex == -1) {
    pRVar1 = this->owner->world;
    this_00 = RGE_Zone_Map_List::get_zone_map
                        (pRVar1->map->map_zones,pRVar1->terrains[this->master_obj->terrain],
                         (int)pRVar1->terrain_size,&this->zoneMapIndex);
  }
  else {
    this_00 = RGE_Zone_Map_List::get_zone_map(this->owner->world->map->map_zones,this->zoneMapIndex)
    ;
  }
  if (this_00 != (RGE_Zone_Map *)0x0) {
    iVar2 = RGE_Zone_Map::findClosestPointInTerrainType
                      (this_00,param_1,param_2,param_3,param_4,param_5);
    return iVar2;
  }
  return 0;
}

// --------------------------------------------------

// Function: isGroupCommander
// Address: 004c7740
/* public: int __thiscall RGE_Static_Object::isGroupCommander(void) */

int __thiscall RGE_Static_Object::isGroupCommander(RGE_Static_Object *this)
{
  return (uint)(this->id == this->groupCommanderValue);
}

// --------------------------------------------------

// Function: inGroup
// Address: 004c7760
/* public: int __thiscall RGE_Static_Object::inGroup(void) */

int __thiscall RGE_Static_Object::inGroup(RGE_Static_Object *this)
{
  return (uint)(0 < (this->groupMembers).numberValue);
}

// --------------------------------------------------

// Function: unitIsInGroup
// Address: 004c7770
/* public: int __thiscall RGE_Static_Object::unitIsInGroup(int) */

int __thiscall RGE_Static_Object::unitIsInGroup(RGE_Static_Object *this,int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = (this->groupMembers).numberValue;
  iVar2 = 0;
  if (0 < iVar1) {
    while (iVar2 < (this->groupMembers).maximumSizeValue) {
      if ((this->groupMembers).value[iVar2] == param_1) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      if (iVar1 <= iVar2) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: createGroup
// Address: 004c77b0
/* public: int __thiscall RGE_Static_Object::createGroup(int *,int,int,float) */

int __thiscall
RGE_Static_Object::createGroup
          (RGE_Static_Object *this,int *param_1,int param_2,int param_3,float param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    return 0;
  }
  (this->groupMembers).numberValue = 0;
  if (0 < param_2) {
    do {
      iVar1 = *param_1;
      if (-1 < iVar1) {
        iVar2 = (this->groupMembers).numberValue;
        iVar3 = 0;
        if (0 < iVar2) {
          do {
            if ((this->groupMembers).maximumSizeValue <= iVar3) break;
            if ((this->groupMembers).value[iVar3] == iVar1) goto LAB_004c786f;
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar2);
        }
        if ((this->groupMembers).maximumSizeValue + -1 < iVar2) {
          iVar2 = iVar2 + 1;
          piVar4 = (int *)operator_new(iVar2 * 4);
          if (piVar4 != (int *)0x0) {
            iVar3 = 0;
            if (0 < (this->groupMembers).maximumSizeValue) {
              do {
                if (iVar2 <= iVar3) break;
                iVar5 = iVar3 + 1;
                piVar4[iVar3] = (this->groupMembers).value[iVar3];
                iVar3 = iVar5;
              } while (iVar5 < (this->groupMembers).maximumSizeValue);
            }
            operator_delete((this->groupMembers).value);
            (this->groupMembers).value = piVar4;
            (this->groupMembers).maximumSizeValue = iVar2;
          }
        }
        (this->groupMembers).value[(this->groupMembers).numberValue] = iVar1;
        (this->groupMembers).numberValue = (this->groupMembers).numberValue + 1;
      }
LAB_004c786f:
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  this->groupRangeValue = param_4;
  this->groupCommanderValue = param_3;
  return 1;
}

// --------------------------------------------------

// Function: commanderCreateGroup
// Address: 004c78b0
/* public: int __thiscall RGE_Static_Object::commanderCreateGroup(int *,int,int,float) */

int __thiscall
RGE_Static_Object::commanderCreateGroup
          (RGE_Static_Object *this,int *param_1,int param_2,int param_3,float param_4)
{
  int *piVar1;
  RGE_Static_Object *this_00;
  int *piVar2;
  
  piVar1 = param_1;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    if (0 < param_2) {
      param_1 = (int *)param_2;
      piVar2 = piVar1;
      do {
        this_00 = RGE_Game_World::object(this->owner->world,*piVar2);
        if (this_00 != (RGE_Static_Object *)0x0) {
          createGroup(this_00,piVar1,param_2,param_3,param_4);
        }
        piVar2 = piVar2 + 1;
        param_1 = (int *)((int)param_1 + -1);
      } while (param_1 != (int *)0x0);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: addToGroup
// Address: 004c7920
/* public: int __thiscall RGE_Static_Object::addToGroup(int,float) */

int __thiscall RGE_Static_Object::addToGroup(RGE_Static_Object *this,int param_1,float param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (0x18 < (this->groupMembers).numberValue) {
    return 0;
  }
  iVar1 = (this->groupMembers).numberValue;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if ((this->groupMembers).maximumSizeValue <= iVar2) break;
      if ((this->groupMembers).value[iVar2] == param_1) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((this->groupMembers).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (this->groupMembers).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (this->groupMembers).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (this->groupMembers).maximumSizeValue);
      }
      operator_delete((this->groupMembers).value);
      (this->groupMembers).value = piVar3;
      (this->groupMembers).maximumSizeValue = iVar1;
    }
  }
  (this->groupMembers).value[(this->groupMembers).numberValue] = param_1;
  (this->groupMembers).numberValue = (this->groupMembers).numberValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: commanderAddToGroup
// Address: 004c79d0
/* WARNING: Variable defined which should be unmapped: i */
/* public: int __thiscall RGE_Static_Object::commanderAddToGroup(int,float) */

int __thiscall
RGE_Static_Object::commanderAddToGroup(RGE_Static_Object *this,int param_1,float param_2)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this_00;
  int iVar3;
  uint uVar4;
  int i;
  int local_70;
  RGE_Static_Object *unitObj;
  int temp [25];
  
  temp[0] = (int)RGE_Game_World::object(this->owner->world,param_1);
  if ((RGE_Static_Object *)temp[0] == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iVar2 = (this->groupMembers).numberValue;
  if (0x18 < iVar2) {
    return 0;
  }
  iVar3 = 0;
  local_70 = 0;
  if (0 < iVar2) {
    uVar4 = 4;
    do {
      if ((this->groupMembers).maximumSizeValue + -1 < local_70) {
        piVar1 = (int *)operator_new(uVar4);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->groupMembers).maximumSizeValue) {
            do {
              if (local_70 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar1[iVar2] = (this->groupMembers).value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < (this->groupMembers).maximumSizeValue);
          }
          operator_delete((this->groupMembers).value);
          (this->groupMembers).value = piVar1;
          (this->groupMembers).maximumSizeValue = local_70 + 1;
        }
      }
      iVar2 = *(int *)((int)(this->groupMembers).value + (uVar4 - 4));
      iVar3 = this->id;
      *(int *)((int)temp + uVar4) = iVar2;
      if (iVar2 != iVar3) {
        if ((this->groupMembers).maximumSizeValue + -1 < local_70) {
          piVar1 = (int *)operator_new(uVar4);
          if (piVar1 != (int *)0x0) {
            iVar2 = 0;
            if (0 < (this->groupMembers).maximumSizeValue) {
              do {
                if (local_70 + 1 <= iVar2) break;
                iVar3 = iVar2 + 1;
                piVar1[iVar2] = (this->groupMembers).value[iVar2];
                iVar2 = iVar3;
              } while (iVar3 < (this->groupMembers).maximumSizeValue);
            }
            operator_delete((this->groupMembers).value);
            (this->groupMembers).value = piVar1;
            (this->groupMembers).maximumSizeValue = local_70 + 1;
          }
        }
        this_00 = RGE_Game_World::object
                            (this->owner->world,
                             *(int *)((int)(this->groupMembers).value + (uVar4 - 4)));
        if (this_00 != (RGE_Static_Object *)0x0) {
          addToGroup(this_00,param_1,param_2);
        }
      }
      iVar3 = local_70 + 1;
      uVar4 = uVar4 + 4;
      local_70 = iVar3;
    } while (iVar3 < (this->groupMembers).numberValue);
  }
  temp[iVar3 + 1] = param_1;
  addToGroup(this,param_1,param_2);
  createGroup((RGE_Static_Object *)temp[0],temp + 1,iVar3 + 1,this->id,param_2);
  return 1;
}

// --------------------------------------------------

// Function: removeFromGroup
// Address: 004c7b60
/* public: int __thiscall RGE_Static_Object::removeFromGroup(int) */

int __thiscall RGE_Static_Object::removeFromGroup(RGE_Static_Object *this,int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (this->groupMembers).maximumSizeValue;
  iVar1 = 0;
  if (0 < iVar2) {
    piVar3 = (this->groupMembers).value;
    do {
      if (*piVar3 == param_1) break;
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar3 = (this->groupMembers).value;
        iVar2 = iVar1 + 1;
        piVar3[iVar1] = piVar3[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (this->groupMembers).maximumSizeValue + -1);
    }
    iVar2 = (this->groupMembers).numberValue + -1;
    (this->groupMembers).numberValue = iVar2;
    if (iVar2 < 0) {
      (this->groupMembers).numberValue = 0;
    }
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  if ((this->groupMembers).numberValue < 1) {
    this->groupCommanderValue = -1;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: commanderRemoveFromGroup
// Address: 004c7bd0
/* public: int __thiscall RGE_Static_Object::commanderRemoveFromGroup(int) */

int __thiscall RGE_Static_Object::commanderRemoveFromGroup(RGE_Static_Object *this,int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  
  if ((param_1 == this->id) && (this->id == this->groupCommanderValue)) {
    iVar1 = commanderDestroyGroup(this);
    return iVar1;
  }
  iVar1 = 0;
  if (0 < (this->groupMembers).numberValue) {
    do {
      if ((this->groupMembers).maximumSizeValue + -1 < iVar1) {
        piVar2 = (int *)operator_new(iVar1 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (this->groupMembers).maximumSizeValue) {
            do {
              if (iVar1 + 1 <= iVar5) break;
              iVar3 = iVar5 + 1;
              piVar2[iVar5] = (this->groupMembers).value[iVar5];
              iVar5 = iVar3;
            } while (iVar3 < (this->groupMembers).maximumSizeValue);
          }
          operator_delete((this->groupMembers).value);
          (this->groupMembers).value = piVar2;
          (this->groupMembers).maximumSizeValue = iVar1 + 1;
        }
      }
      pRVar4 = RGE_Game_World::object(this->owner->world,(this->groupMembers).value[iVar1]);
      if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->id != this->id)) {
        iVar5 = (pRVar4->groupMembers).maximumSizeValue;
        iVar3 = 0;
        if (0 < iVar5) {
          piVar2 = (pRVar4->groupMembers).value;
          do {
            if (*piVar2 == param_1) break;
            iVar3 = iVar3 + 1;
            piVar2 = piVar2 + 1;
          } while (iVar3 < iVar5);
        }
        if (iVar3 < iVar5) {
          if (iVar3 < iVar5 + -1) {
            do {
              piVar2 = (pRVar4->groupMembers).value;
              iVar5 = iVar3 + 1;
              piVar2[iVar3] = piVar2[iVar5];
              iVar3 = iVar5;
            } while (iVar5 < (pRVar4->groupMembers).maximumSizeValue + -1);
          }
          iVar5 = (pRVar4->groupMembers).numberValue + -1;
          (pRVar4->groupMembers).numberValue = iVar5;
          if (iVar5 < 0) {
            (pRVar4->groupMembers).numberValue = 0;
          }
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < (this->groupMembers).numberValue);
  }
  removeFromGroup(this,param_1);
  return 1;
}

// --------------------------------------------------

// Function: destroyGroup
// Address: 004c7ce0
/* public: int __thiscall RGE_Static_Object::destroyGroup(void) */

int __thiscall RGE_Static_Object::destroyGroup(RGE_Static_Object *this)
{
  (this->groupMembers).numberValue = 0;
  this->groupCommanderValue = -1;
  return 1;
}

// --------------------------------------------------

// Function: commanderDestroyGroup
// Address: 004c7d00
/* public: int __thiscall RGE_Static_Object::commanderDestroyGroup(void) */

int __thiscall RGE_Static_Object::commanderDestroyGroup(RGE_Static_Object *this)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *this_00;
  int iVar4;
  
  iVar4 = 0;
  if (0 < (this->groupMembers).numberValue) {
    do {
      if ((this->groupMembers).maximumSizeValue + -1 < iVar4) {
        piVar1 = (int *)operator_new(iVar4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (this->groupMembers).maximumSizeValue) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar1[iVar2] = (this->groupMembers).value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < (this->groupMembers).maximumSizeValue);
          }
          operator_delete((this->groupMembers).value);
          (this->groupMembers).value = piVar1;
          (this->groupMembers).maximumSizeValue = iVar4 + 1;
        }
      }
      this_00 = RGE_Game_World::object(this->owner->world,(this->groupMembers).value[iVar4]);
      if ((this_00 != (RGE_Static_Object *)0x0) && (this_00->id != this->id)) {
        destroyGroup(this_00);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (this->groupMembers).numberValue);
  }
  destroyGroup(this);
  return 1;
}

// --------------------------------------------------

// Function: addToPathingGroup
// Address: 004c7db0
/* public: void __thiscall RGE_Static_Object::addToPathingGroup(int) */

void __thiscall RGE_Static_Object::addToPathingGroup(RGE_Static_Object *this,int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar1 = (this->pathingGroupMembers).numberValue;
  if (0 < iVar1) {
    do {
      if ((this->pathingGroupMembers).maximumSizeValue <= iVar2) break;
      if ((this->pathingGroupMembers).value[iVar2] == param_1) {
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((this->pathingGroupMembers).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (this->pathingGroupMembers).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (this->pathingGroupMembers).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (this->pathingGroupMembers).maximumSizeValue);
      }
      operator_delete((this->pathingGroupMembers).value);
      (this->pathingGroupMembers).value = piVar3;
      (this->pathingGroupMembers).maximumSizeValue = iVar1;
    }
  }
  (this->pathingGroupMembers).value[(this->pathingGroupMembers).numberValue] = param_1;
  (this->pathingGroupMembers).numberValue = (this->pathingGroupMembers).numberValue + 1;
  return;
}

// --------------------------------------------------

// Function: removeAllFromPathingGroup
// Address: 004c7e50
/* public: void __thiscall RGE_Static_Object::removeAllFromPathingGroup(void) */

void __thiscall RGE_Static_Object::removeAllFromPathingGroup(RGE_Static_Object *this)
{
  int iVar1;
  
  iVar1 = RGE_Player::computerPlayer(this->owner);
  if (iVar1 == 1) {
    (this->pathingGroupMembers).numberValue = 0;
  }
  return;
}

// --------------------------------------------------

// Function: remove_shadows
// Address: 004c7e70
/* public: void __thiscall RGE_Static_Object::remove_shadows(void) */

void __thiscall RGE_Static_Object::remove_shadows(RGE_Static_Object *this)
{
  int iVar1;
  int iVar2;
  
  iVar1 = __ftol();
  iVar2 = __ftol();
  RGE_Map::request_redraw(this->owner->world->map,iVar1 + -2,iVar2 + -2,iVar1 + 1,iVar2 + 1,'\0');
  return;
}

// --------------------------------------------------

// Function: set_sleep_flag
// Address: 004c7eb0
/* public: void __thiscall RGE_Static_Object::set_sleep_flag(unsigned char) */

void __thiscall RGE_Static_Object::set_sleep_flag(RGE_Static_Object *this,uchar param_1)
{
  RGE_Object_Node *pRVar1;
  
  if (this->sleep_flag != param_1) {
    if (param_1 == '\0') {
      if (this->goto_sleep_flag != '\0') {
        this->sleep_flag = '\0';
        this->goto_sleep_flag = '\0';
        return;
      }
      (**(code **)(this->owner->_padding_ + 0xe0))
                (this,this->sleep_flag,this->dopple_flag,this->player_object_node);
      this->sleep_flag = '\0';
      pRVar1 = (RGE_Object_Node *)
               (**(code **)(this->owner->_padding_ + 0xdc))(this,0,this->dopple_flag);
      this->player_object_node = pRVar1;
      return;
    }
    this->goto_sleep_flag = '\x01';
    this->sleep_flag = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: get_action_checksum
// Address: 004c7f30
/* public: virtual long __thiscall RGE_Static_Object::get_action_checksum(void) */

long __thiscall RGE_Static_Object::get_action_checksum(RGE_Static_Object *this)
{
  return 0;
}

// --------------------------------------------------

// Function: get_waypoint_checksum
// Address: 004c7f40
/* public: virtual long __thiscall RGE_Static_Object::get_waypoint_checksum(void) */

long __thiscall RGE_Static_Object::get_waypoint_checksum(RGE_Static_Object *this)
{
  return 0;
}

// --------------------------------------------------

// Function: ~RGE_Static_Object
// Address: 004ccb0e
void __thiscall RGE_Static_Object::~RGE_Static_Object(RGE_Static_Object *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_List *this_00;
  int *piVar2;
  RGE_Object_Node *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  pcStack_8 = FUN_0055f9e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  uStack_4 = 1;
  remove_visible_resource(this);
  if (this->owner != (RGE_Player *)0x0) {
    if (this->object_state < 3) {
      take_attribute_from_owner(this);
    }
    if (this->object_state < 7) {
      RGE_Victory_Conditions::update_for_object(this->owner->victory_conditions,this);
    }
  }
  if (this->sprite_list != (RGE_Active_Sprite_List *)0x0) {
    (**(code **)this->sprite_list->_padding_)(1);
    this->sprite_list = (RGE_Active_Sprite_List *)0x0;
  }
  if (this->owner != (RGE_Player *)0x0) {
    if ((this->selected & 1) != 0) {
      RGE_Player::unselect_one_object(this->owner,this);
    }
    (**(code **)(this->owner->_padding_ + 0xe0))
              (this,this->sleep_flag,this->dopple_flag,this->player_object_node);
    this->owner = (RGE_Player *)0x0;
  }
  if (this->tile != (RGE_Tile *)0x0) {
    RGE_Object_List::remove_node(&this->tile->objects,this,(RGE_Object_Node *)0x0);
    this->tile = (RGE_Tile *)0x0;
  }
  if ((this->master_obj != (RGE_Master_Static_Object *)0x0) &&
     ((float)(double)DAT_00574718 < this->master_obj->radius_z)) {
    removeFromObstructionMap(this,2);
  }
  if (this->inside_obj != (RGE_Static_Object *)0x0) {
    RGE_Object_List::remove_node(this->inside_obj->objects,this,(RGE_Object_Node *)0x0);
    this->inside_obj = (RGE_Static_Object *)0x0;
  }
  if (this->objects != (RGE_Object_List *)0x0) {
    pRVar3 = this->objects->list;
    while (pRVar3 != (RGE_Object_Node *)0x0) {
      pRVar1 = pRVar3->next;
      (**(code **)(pRVar3->node->_padding_ + 0xd4))();
      pRVar3 = pRVar1;
    }
    this_00 = this->objects;
    if (this_00 != (RGE_Object_List *)0x0) {
      RGE_Object_List::~RGE_Object_List(this_00);
      operator_delete(this_00);
    }
  }
  if (this->unitAIValue != (UnitAIModule *)0x0) {
    (**(code **)this->unitAIValue->_padding_)(1);
    this->unitAIValue = (UnitAIModule *)0x0;
  }
  piVar2 = (this->groupMembers).value;
  uStack_4 = uStack_4 & 0xffffff00;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (this->groupMembers).value = (int *)0x0;
  }
  (this->groupMembers).numberValue = 0;
  (this->groupMembers).desiredNumberValue = 0;
  (this->groupMembers).maximumSizeValue = 0;
  piVar2 = (this->pathingGroupMembers).value;
  uStack_4 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    operator_delete(piVar2);
    (this->pathingGroupMembers).value = (int *)0x0;
  }
  (this->pathingGroupMembers).numberValue = 0;
  (this->pathingGroupMembers).desiredNumberValue = 0;
  (this->pathingGroupMembers).maximumSizeValue = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

