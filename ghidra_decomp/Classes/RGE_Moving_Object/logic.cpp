// Class: RGE_Moving_Object
// Function: getAngle
// Address: 00405f50
/* public: virtual float __thiscall RGE_Moving_Object::getAngle(void)const  */

float __thiscall RGE_Moving_Object::getAngle(RGE_Moving_Object *this)
{
  return this->angle;
}

// --------------------------------------------------

// Function: numberUserDefinedWaypoints
// Address: 00405f60
/* public: virtual int __thiscall RGE_Moving_Object::numberUserDefinedWaypoints(void)const  */

int __thiscall RGE_Moving_Object::numberUserDefinedWaypoints(RGE_Moving_Object *this)
{
  return this->numberUserDefinedWaypointsValue;
}

// --------------------------------------------------

// Function: RGE_Moving_Object
// Address: 0045c450
/* public: __thiscall RGE_Moving_Object::RGE_Moving_Object(class RGE_Master_Moving_Object *,class
   RGE_Player *,float,float,float,int) */

RGE_Moving_Object * __thiscall
RGE_Moving_Object::RGE_Moving_Object
          (RGE_Moving_Object *this,RGE_Master_Moving_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dc84;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Animated_Object::RGE_Animated_Object
            ((RGE_Animated_Object *)this,(RGE_Master_Animated_Object *)param_1,param_2,param_3,
             param_4,param_5,0);
  local_4 = 0;
  Path::Path(&this->pathValue,10);
  local_4._0_1_ = 1;
  Path::Path(&this->exceptionPathValue,10);
  local_4 = CONCAT31(local_4._1_3_,2);
  this->rangeStatusValue = 2;
  this->currentTerrainException1 = -1;
  this->currentTerrainException2 = -1;
  this->storePathInExceptionPath = '\0';
  this->waitingToMoveValue = '\0';
  this->numberWaitDelays = '\0';
  this->userDefinedWaypoints = (XYZBYTEPoint *)0x0;
  this->numberUserDefinedWaypointsValue = 0;
  this->maxUserDefinedWaypointsValue = 0;
  this->finalUserDefinedWaypoint = '\0';
  this->_padding_ = (int)&_vftable_;
  (this->startValue).x = 0.0;
  (this->startValue).y = 0.0;
  (this->startValue).z = 0.0;
  setGoal(this,0.0,0.0,0.0);
  this->turnTimer = 0.0;
  this->lastFacet = 0xff;
  this->lastFacet2 = 0xff;
  this->collisionAvoidanceDistance = 0.0;
  this->actionRange = 0.0;
  this->targetIDValue = -1;
  this->targetRadiusX = 0.0;
  this->targetRadiusY = 0.0;
  this->continueCounter = 0;
  this->closestDistanceToWaypoint = 100000.0;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0045c5a0
/* public: virtual void * __thiscall RGE_Moving_Object::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
RGE_Moving_Object::_scalar_deleting_destructor_(RGE_Moving_Object *this,uint param_1)
{
  ~RGE_Moving_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Moving_Object
// Address: 0045c5c0
/* public: __thiscall RGE_Moving_Object::RGE_Moving_Object(int,class RGE_Game_World *,int) */

RGE_Moving_Object * __thiscall
RGE_Moving_Object::RGE_Moving_Object
          (RGE_Moving_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dcb4;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Animated_Object::RGE_Animated_Object((RGE_Animated_Object *)this,param_1,param_2,0);
  local_4 = 0;
  Path::Path(&this->pathValue,10);
  local_4._0_1_ = 1;
  Path::Path(&this->exceptionPathValue,10);
  local_4 = CONCAT31(local_4._1_3_,2);
  this->rangeStatusValue = 2;
  this->currentTerrainException1 = -1;
  this->currentTerrainException2 = -1;
  this->storePathInExceptionPath = '\0';
  this->waitingToMoveValue = '\0';
  this->numberWaitDelays = '\0';
  this->userDefinedWaypoints = (XYZBYTEPoint *)0x0;
  this->numberUserDefinedWaypointsValue = 0;
  this->maxUserDefinedWaypointsValue = 0;
  this->finalUserDefinedWaypoint = '\0';
  this->_padding_ = (int)&_vftable_;
  (this->startValue).x = 0.0;
  (this->startValue).y = 0.0;
  (this->startValue).z = 0.0;
  setGoal(this,0.0,0.0,0.0);
  this->turnTimer = 0.0;
  this->lastFacet = 0xff;
  this->lastFacet2 = 0xff;
  this->collisionAvoidanceDistance = 0.0;
  this->actionRange = 0.0;
  this->targetIDValue = -1;
  this->targetRadiusX = 0.0;
  this->targetRadiusY = 0.0;
  this->continueCounter = 0;
  this->closestDistanceToWaypoint = 100000.0;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Moving_Object
// Address: 0045c700
/* public: virtual __thiscall RGE_Moving_Object::~RGE_Moving_Object(void) */

void __thiscall RGE_Moving_Object::~RGE_Moving_Object(RGE_Moving_Object *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_0055dce4;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 2;
  if (this->userDefinedWaypoints != (XYZBYTEPoint *)0x0) {
    operator_delete(this->userDefinedWaypoints);
    this->userDefinedWaypoints = (XYZBYTEPoint *)0x0;
  }
  local_4._0_1_ = 1;
  Path::~Path(&this->exceptionPathValue);
  local_4 = (uint)local_4._1_3_ << 8;
  Path::~Path(&this->pathValue);
  local_4 = 0xffffffff;
  RGE_Static_Object::~RGE_Static_Object((RGE_Static_Object *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: recycle_in_to_game
// Address: 0045c790
// [HELPER] s_C__msdev_work_age1_x1_move_obj_c: "C:\msdev\work\age1_x1\move_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall RGE_Moving_Object::recycle_in_to_game(class
   RGE_Master_Static_Object *,class RGE_Player *,float,float,float) */

void __thiscall
RGE_Moving_Object::recycle_in_to_game
          (RGE_Moving_Object *this,RGE_Master_Static_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  short sVar1;
  float fVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  Path local_40;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dcf8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  Path::Path(&local_40,10);
  local_4 = 0;
  Path::operator=(&this->pathValue,&local_40);
  local_4 = 0xffffffff;
  Path::~Path(&local_40);
  this->rangeStatusValue = 2;
  this->currentTerrainException1 = -1;
  this->currentTerrainException2 = -1;
  this->storePathInExceptionPath = '\0';
  this->waitingToMoveValue = '\0';
  this->numberWaitDelays = '\0';
  (this->startValue).x = 0.0;
  (this->startValue).y = 0.0;
  (this->startValue).z = 0.0;
  setGoal(this,0.0,0.0,0.0);
  this->lastFacet = 0xff;
  this->lastFacet2 = 0xff;
  this->turnTimer = 0.0;
  this->collisionAvoidanceDistance = 0.0;
  this->actionRange = 0.0;
  this->targetIDValue = -1;
  this->targetRadiusX = 0.0;
  this->targetRadiusY = 0.0;
  this->continueCounter = 0;
  this->closestDistanceToWaypoint = 100000.0;
  RGE_Animated_Object::recycle_in_to_game
            ((RGE_Animated_Object *)this,param_1,param_2,param_3,param_4,param_5);
  iVar3 = this->_padding_;
  this->velocity_x = 0.0;
  this->velocity_y = 0.0;
  this->velocity_z = 0.0;
  this->angle = 0.0;
  this->turn_towards_time = 0.0;
  this->trail_remainder = 0.0;
  if (((iVar3 != 0) && ((*(byte *)(iVar3 + 0x70) & 2) != 0)) && (1 < *(short *)(iVar3 + 0x60))) {
    sVar1 = *(short *)(iVar3 + 0x60);
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0xc5);
    fVar2 = ((float)_DAT_00570b40 / (float)(int)sVar1) * (float)((iVar3 * sVar1) / 0x7fff);
    this->angle = fVar2;
    if (_DAT_00570b48 <= fVar2) {
      if (_DAT_00570b50 < fVar2) {
        this->angle = fVar2 - _DAT_00570b50;
      }
    }
    else {
      this->angle = fVar2 - _DAT_00570b4c;
    }
  }
  set_angle(this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0045c970
// [HELPER] s_C__msdev_work_age1_x1_move_obj_c: "C:\msdev\work\age1_x1\move_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall RGE_Moving_Object::setup(class RGE_Master_Moving_Object *,class
   RGE_Player *,float,float,float) */

int __thiscall
RGE_Moving_Object::setup
          (RGE_Moving_Object *this,RGE_Master_Moving_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  short sVar1;
  float fVar2;
  int iVar3;
  
  RGE_Animated_Object::setup
            ((RGE_Animated_Object *)this,(RGE_Master_Animated_Object *)param_1,param_2,param_3,
             param_4,param_5);
  iVar3 = this->_padding_;
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x1e;
  this->velocity_x = 0.0;
  this->velocity_y = 0.0;
  this->velocity_z = 0.0;
  this->angle = 0.0;
  this->turn_towards_time = 0.0;
  this->trail_remainder = 0.0;
  if (((iVar3 != 0) && ((*(byte *)(iVar3 + 0x70) & 2) != 0)) && (1 < *(short *)(iVar3 + 0x60))) {
    sVar1 = *(short *)(iVar3 + 0x60);
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0xde);
    fVar2 = ((float)_DAT_00570b40 / (float)(int)sVar1) * (float)((iVar3 * sVar1) / 0x7fff);
    this->angle = fVar2;
    if (fVar2 < _DAT_00570b48) {
      this->angle = fVar2 - _DAT_00570b4c;
      set_angle(this);
      return 1;
    }
    if (_DAT_00570b50 < fVar2) {
      this->angle = fVar2 - _DAT_00570b50;
      set_angle(this);
      return 1;
    }
  }
  set_angle(this);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0045caa0
/* WARNING: Variable defined which should be unmapped: currentWaypoint */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall RGE_Moving_Object::setup(int,class RGE_Game_World *) */

int __thiscall RGE_Moving_Object::setup(RGE_Moving_Object *this,int param_1,RGE_Game_World *param_2)
{
  int *piVar1;
  Waypoint WVar2;
  int iVar3;
  XYZBYTEPoint *pXVar4;
  int iVar5;
  int currentWaypoint;
  Waypoint temp;
  undefined4 local_4;
  
  iVar3 = param_1;
  RGE_Animated_Object::setup((RGE_Animated_Object *)this,param_1,param_2);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x1e;
  rge_read(iVar3,&this->trail_remainder,4);
  rge_read(iVar3,&this->velocity_x,4);
  rge_read(iVar3,&this->velocity_y,4);
  rge_read(iVar3,&this->velocity_z,4);
  rge_read(iVar3,&this->angle,4);
  rge_read(iVar3,&this->turn_towards_time,4);
  rge_read(iVar3,&param_1,4);
  iVar5 = 0;
  if (0 < param_1) {
    do {
      rge_read(iVar3,&temp.y,0x10);
      WVar2.y = temp.z;
      WVar2.x = temp.y;
      WVar2.z = (float)temp._12_4_;
      WVar2._12_4_ = local_4;
      Path::insertAtEnd(&this->pathValue,WVar2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1);
  }
  rge_read(iVar3,&temp,4);
  iVar5 = 0;
  Path::initToStart(&this->pathValue);
  if (0 < (int)temp.x) {
    do {
      Path::moveToNextWaypoint(&this->pathValue);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)temp.x);
  }
  rge_read(iVar3,&this->startValue,0x10);
  rge_read(iVar3,&this->goalValue,0x10);
  rge_read(iVar3,&this->turnTimer,4);
  rge_read(iVar3,&this->collisionAvoidanceDistance,4);
  rge_read(iVar3,&this->actionRange,4);
  rge_read(iVar3,&this->targetIDValue,4);
  rge_read(iVar3,&this->targetRadiusX,4);
  rge_read(iVar3,&this->targetRadiusY,4);
  rge_read(iVar3,&this->continueCounter,4);
  rge_read(iVar3,&this->rangeStatusValue,4);
  rge_read(iVar3,&this->waitingToMoveValue,1);
  rge_read(iVar3,&this->numberWaitDelays,1);
  piVar1 = &this->numberUserDefinedWaypointsValue;
  rge_read(iVar3,piVar1,4);
  rge_read(iVar3,&this->maxUserDefinedWaypointsValue,4);
  pXVar4 = (XYZBYTEPoint *)operator_new(this->maxUserDefinedWaypointsValue * 3);
  this->userDefinedWaypoints = pXVar4;
  iVar5 = 0;
  if (0 < *piVar1) {
    param_2 = (RGE_Game_World *)0x0;
    do {
      rge_read(iVar3,&this->userDefinedWaypoints->x + (int)&param_2->_padding_,3);
      iVar5 = iVar5 + 1;
      param_2 = (RGE_Game_World *)((int)&param_2->_padding_ + 3);
    } while (iVar5 < *piVar1);
  }
  rge_read(iVar3,&this->finalUserDefinedWaypoint,1);
  if (save_game_version < _DAT_00570b54) {
    (this->minInitialPointValue).x = -1;
    (this->minInitialPointValue).y = -1;
    (this->maxInitialPointValue).x = -1;
    (this->maxInitialPointValue).y = -1;
  }
  else {
    rge_read(iVar3,&this->minInitialPointValue,8);
    rge_read(iVar3,&this->maxInitialPointValue,8);
  }
  if (save_game_version < _DAT_00570b58) {
    this->closestDistanceToWaypoint = 100000.0;
    this->lastFacet = 0xff;
  }
  else {
    rge_read(iVar3,&this->closestDistanceToWaypoint,4);
    rge_read(iVar3,&this->lastFacet,1);
  }
  if (_DAT_00570b5c <= save_game_version) {
    rge_read(iVar3,&this->lastFacet2,1);
    return 1;
  }
  this->lastFacet2 = 0xff;
  return 1;
}

// --------------------------------------------------

// Function: save
// Address: 0045ce00
/* WARNING: Variable defined which should be unmapped: currentWaypoint */
/* public: virtual void __thiscall RGE_Moving_Object::save(int) */

void __thiscall RGE_Moving_Object::save(RGE_Moving_Object *this,int param_1)
{
  Path *this_00;
  int iVar1;
  Waypoint *pWVar2;
  int iVar3;
  int iVar4;
  int currentWaypoint;
  RGE_Moving_Object *local_4;
  
  iVar1 = param_1;
  local_4 = this;
  RGE_Animated_Object::save((RGE_Animated_Object *)this,param_1);
  rge_write(iVar1,&this->trail_remainder,4);
  rge_write(iVar1,&this->velocity_x,4);
  rge_write(iVar1,&this->velocity_y,4);
  rge_write(iVar1,&this->velocity_z,4);
  rge_write(iVar1,&this->angle,4);
  rge_write(iVar1,&this->turn_towards_time,4);
  this_00 = &this->pathValue;
  param_1 = Path::numberOfWaypoints(this_00);
  rge_write(iVar1,&param_1,4);
  iVar3 = 0;
  if (0 < param_1) {
    do {
      iVar4 = 0x10;
      pWVar2 = Path::waypoint(this_00,iVar3);
      rge_write(iVar1,pWVar2,iVar4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1);
  }
  local_4 = (RGE_Moving_Object *)Path::currentWaypointNumber(this_00);
  rge_write(iVar1,&local_4,4);
  rge_write(iVar1,&this->startValue,0x10);
  rge_write(iVar1,&this->goalValue,0x10);
  rge_write(iVar1,&this->turnTimer,4);
  rge_write(iVar1,&this->collisionAvoidanceDistance,4);
  rge_write(iVar1,&this->actionRange,4);
  rge_write(iVar1,&this->targetIDValue,4);
  rge_write(iVar1,&this->targetRadiusX,4);
  rge_write(iVar1,&this->targetRadiusY,4);
  rge_write(iVar1,&this->continueCounter,4);
  rge_write(iVar1,&this->rangeStatusValue,4);
  rge_write(iVar1,&this->waitingToMoveValue,1);
  rge_write(iVar1,&this->numberWaitDelays,1);
  rge_write(iVar1,&this->numberUserDefinedWaypointsValue,4);
  rge_write(iVar1,&this->maxUserDefinedWaypointsValue,4);
  iVar3 = 0;
  if (0 < this->numberUserDefinedWaypointsValue) {
    iVar4 = 0;
    do {
      rge_write(iVar1,&this->userDefinedWaypoints->x + iVar4,3);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 3;
    } while (iVar3 < this->numberUserDefinedWaypointsValue);
  }
  rge_write(iVar1,&this->finalUserDefinedWaypoint,1);
  rge_write(iVar1,&this->minInitialPointValue,8);
  rge_write(iVar1,&this->maxInitialPointValue,8);
  rge_write(iVar1,&this->closestDistanceToWaypoint,4);
  rge_write(iVar1,&this->lastFacet,1);
  rge_write(iVar1,&this->lastFacet2,1);
  return;
}

// --------------------------------------------------

// Function: new_sprite
// Address: 0045d080
/* public: virtual void __thiscall RGE_Moving_Object::new_sprite(class RGE_Sprite *) */

void __thiscall RGE_Moving_Object::new_sprite(RGE_Moving_Object *this,RGE_Sprite *param_1)
{
  if (param_1 == (RGE_Sprite *)0x0) {
    param_1 = *(RGE_Sprite **)(this->_padding_ + 0x18);
  }
  if ((RGE_Sprite *)this->_padding_ != param_1) {
    this->_padding_ = this->_padding_;
    RGE_Static_Object::new_sprite((RGE_Static_Object *)this,param_1);
    set_angle(this);
  }
  return;
}

// --------------------------------------------------

// Function: spawn_death_obj
// Address: 0045d0b0
/* public: virtual class RGE_Static_Object * __thiscall RGE_Moving_Object::spawn_death_obj(void) */

RGE_Static_Object * __thiscall RGE_Moving_Object::spawn_death_obj(RGE_Moving_Object *this)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = RGE_Static_Object::spawn_death_obj((RGE_Static_Object *)this);
  if ((pRVar1 != (RGE_Static_Object *)0x0) && (0x1d < pRVar1->master_obj->master_type)) {
    (**(code **)(pRVar1->_padding_ + 0xb4))(this->angle);
  }
  return pRVar1;
}

// --------------------------------------------------

// Function: transform
// Address: 0045d0e0
/* public: virtual void __thiscall RGE_Moving_Object::transform(class RGE_Master_Static_Object *) */

void __thiscall
RGE_Moving_Object::transform(RGE_Moving_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Animated_Object::transform((RGE_Animated_Object *)this,param_1);
  this->velocity_x = 0.0;
  this->velocity_y = 0.0;
  this->velocity_z = 0.0;
  this->collisionAvoidanceDistance = 0.0;
  this->turnTimer = 0.0;
  this->turn_towards_time = 0.0;
  set_angle(this);
  return;
}

// --------------------------------------------------

// Function: is_moving
// Address: 0045d120
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Moving_Object::is_moving(void) */

uchar __thiscall RGE_Moving_Object::is_moving(RGE_Moving_Object *this)
{
  if (_DAT_00570b48 < (float)this->_padding_) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: stop_moving
// Address: 0045d140
/* public: virtual void __thiscall RGE_Moving_Object::stop_moving(void) */

void __thiscall RGE_Moving_Object::stop_moving(RGE_Moving_Object *this)
{
  this->_padding_ = 0;
  return;
}

// --------------------------------------------------

// Function: angle_to_object
// Address: 0045d150
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall RGE_Moving_Object::angle_to_object(class RGE_Static_Object
   *,float,float) */

float __thiscall
RGE_Moving_Object::angle_to_object
          (RGE_Moving_Object *this,RGE_Static_Object *param_1,float param_2,float param_3)
{
  int iVar1;
  float10 fVar2;
  
  iVar1 = this->_padding_;
  if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x70) & 2) != 0)) && (0 < *(short *)(iVar1 + 0x60))) {
    if (param_1 != (RGE_Static_Object *)0x0) {
      param_3 = param_1->world_y;
      param_2 = param_1->world_x;
    }
    fVar2 = (float10)fpatan((float10)param_3 - (float10)(float)this->_padding_,
                            (float10)param_2 - (float10)(float)this->_padding_);
    if (fVar2 < (float10)_DAT_00570b48) {
      fVar2 = fVar2 - (float10)_DAT_00570b4c;
    }
    fVar2 = fVar2 - (float10)this->angle;
    if ((float10)_DAT_00570b68 < fVar2) {
      fVar2 = fVar2 - (float10)_DAT_00570b50;
    }
    if (fVar2 < (float10)_DAT_00570b70) {
      fVar2 = fVar2 - (float10)_DAT_00570b4c;
    }
    return (float)((float10)(int)*(short *)(iVar1 + 0x60) * (float10)_DAT_00570b78 * fVar2);
  }
  return _DAT_00570b48;
}

// --------------------------------------------------

// Function: turn_towards
// Address: 0045d1f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Moving_Object::turn_towards(class RGE_Static_Object
   *,float,float) */

uchar __thiscall
RGE_Moving_Object::turn_towards
          (RGE_Moving_Object *this,RGE_Static_Object *param_1,float param_2,float param_3)
{
  float fVar1;
  float fVar2;
  
  fVar2 = angle_to_object(this,param_1,param_2,param_3);
  if ((fVar2 <= _DAT_00570b7c) && (_DAT_00570b80 <= fVar2)) {
    return '\x01';
  }
  fVar1 = (float)*(uint *)(*(int *)(this->_padding_ + 0x3c) + 4) * _DAT_00570b84;
  if (fVar1 - this->turn_towards_time < *(float *)(this->_padding_ + 0xc4)) {
    return '\0';
  }
  if (_DAT_00570b48 <= fVar2) {
    fVar2 = (float)_DAT_00570b40 / (float)(int)*(short *)(this->_padding_ + 0x60) + this->angle;
  }
  else {
    fVar2 = this->angle - (float)_DAT_00570b40 / (float)(int)*(short *)(this->_padding_ + 0x60);
  }
  this->angle = fVar2;
  if (_DAT_00570b48 <= this->angle) {
    if (this->angle <= _DAT_00570b50) goto LAB_0045d307;
    fVar2 = this->angle - _DAT_00570b50;
  }
  else {
    fVar2 = this->angle - _DAT_00570b4c;
  }
  this->angle = fVar2;
LAB_0045d307:
  set_angle(this);
  this->turn_towards_time = fVar1;
  fVar2 = angle_to_object(this,param_1,param_2,param_3);
  if ((fVar2 < _DAT_00570b7c) && (_DAT_00570b80 <= fVar2)) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: set_angle
// Address: 0045d360
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Moving_Object::set_angle(void) */

void __thiscall RGE_Moving_Object::set_angle(RGE_Moving_Object *this)
{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = this->_padding_;
  if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x70) & 2) != 0)) && (0 < *(short *)(iVar1 + 0x60))) {
    uVar2 = __ftol();
    *(undefined1 *)((int)&this->_padding_ + 1) = uVar2;
    return;
  }
  *(undefined1 *)((int)&this->_padding_ + 1) = 0;
  return;
}

// --------------------------------------------------

// Function: teleport
// Address: 0045d3d0
/* WARNING: Variable defined which should be unmapped: dz */
/* public: virtual float __thiscall RGE_Moving_Object::teleport(float,float,float) */

float __thiscall
RGE_Moving_Object::teleport(RGE_Moving_Object *this,float param_1,float param_2,float param_3)
{
  char cVar1;
  code *pcVar2;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  int *piVar8;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float fVar9;
  float dz;
  float tx;
  float ty;
  float tz;
  float d;
  float dx;
  float dy;
  
  cVar1 = *(char *)(this->_padding_ + 0xcc);
  if ((cVar1 != '\0') && (this->_padding_ != 0)) {
    piVar8 = *(int **)(*(int *)(this->_padding_ + 0x24) + *(short *)(this->_padding_ + 0xca) * 4);
    if (piVar8 != (int *)0x0) {
      if (cVar1 == '\x01') {
        piVar8 = (int *)(**(code **)(*piVar8 + 0x18))
                                  (this->_padding_,this->_padding_,this->_padding_,this->_padding_);
        if (0x1e < *(short *)(piVar8[2] + 0x10)) {
          (**(code **)(*piVar8 + 0xb4))(this->angle);
        }
      }
      else if (cVar1 == '\x02') {
        fVar5 = param_1 - (float)this->_padding_;
        fVar9 = param_2 - (float)this->_padding_;
        fVar6 = param_3 - (float)this->_padding_;
        fVar9 = SQRT(fVar6 * fVar6 + fVar9 * fVar9 + fVar5 * fVar5) + this->trail_remainder;
        sVar7 = __ftol();
        if (sVar7 < 1) {
          this->trail_remainder = fVar9 + this->trail_remainder;
        }
        else {
          dx = (float)(int)sVar7;
          tz = (float)this->_padding_;
          fVar5 = (float)(int)dx;
          ty = (float)this->_padding_;
          fVar3 = (float10)(int)dx;
          d = (float)this->_padding_;
          fVar4 = (float10)(int)dx;
          if (0 < sVar7) {
            pcVar2 = *(code **)(*piVar8 + 0x18);
            do {
              piVar8 = (int *)(*pcVar2)(this->_padding_,ty,tz,d);
              if (0x1e < *(short *)(piVar8[2] + 0x10)) {
                (**(code **)(*piVar8 + 0xb4))(this->angle);
              }
              ty = ty + (float)(extraout_ST1 / fVar3);
              tz = tz + (float)(extraout_ST0 / fVar4);
              d = d + fVar6 / fVar5;
              dx = (float)((int)dx + -1);
            } while (dx != 0.0);
          }
          this->trail_remainder = fVar9 - *(float *)(this->_padding_ + 0xd0) * fVar5;
        }
      }
    }
  }
  fVar9 = RGE_Static_Object::teleport((RGE_Static_Object *)this,param_1,param_2,param_3);
  return fVar9;
}

// --------------------------------------------------

// Function: set_velocity
// Address: 0045d5c0
/* public: void __thiscall RGE_Moving_Object::set_velocity(float,float,float) */

void __thiscall
RGE_Moving_Object::set_velocity(RGE_Moving_Object *this,float param_1,float param_2,float param_3)
{
  this->velocity_x = param_1;
  this->velocity_y = param_2;
  this->velocity_z = param_3;
  return;
}

// --------------------------------------------------

// Function: new_angle
// Address: 0045d5f0
/* public: virtual void __thiscall RGE_Moving_Object::new_angle(float) */

void __thiscall RGE_Moving_Object::new_angle(RGE_Moving_Object *this,float param_1)
{
  this->angle = param_1;
  set_angle(this);
  return;
}

// --------------------------------------------------

// Function: getPath
// Address: 0045d610
/* public: class Path const & __thiscall RGE_Moving_Object::getPath(void)const  */

Path * __thiscall RGE_Moving_Object::getPath(RGE_Moving_Object *this)
{
  return &this->pathValue;
}

// --------------------------------------------------

// Function: facetToNextWaypoint
// Address: 0045d620
/* public: virtual unsigned char __thiscall RGE_Moving_Object::facetToNextWaypoint(void)const  */

uchar __thiscall RGE_Moving_Object::facetToNextWaypoint(RGE_Moving_Object *this)
{
  Waypoint *pWVar1;
  
  pWVar1 = Path::currentWaypoint(&this->pathValue);
  if (pWVar1 != (Waypoint *)0x0) {
    pWVar1 = Path::currentWaypoint(&this->pathValue);
    return pWVar1->facetToNextWaypoint;
  }
  return 0xff;
}

// --------------------------------------------------

// Function: setGoal
// Address: 0045d650
/* public: void __thiscall RGE_Moving_Object::setGoal(float,float,float) */

void __thiscall
RGE_Moving_Object::setGoal(RGE_Moving_Object *this,float param_1,float param_2,float param_3)
{
  (this->goalValue).x = param_1;
  (this->goalValue).y = param_2;
  (this->goalValue).z = param_3;
  return;
}

// --------------------------------------------------

// Function: setActionRange
// Address: 0045d680
/* public: void __thiscall RGE_Moving_Object::setActionRange(float) */

void __thiscall RGE_Moving_Object::setActionRange(RGE_Moving_Object *this,float param_1)
{
  this->actionRange = param_1;
  return;
}

// --------------------------------------------------

// Function: setTargetID
// Address: 0045d690
/* public: void __thiscall RGE_Moving_Object::setTargetID(int) */

void __thiscall RGE_Moving_Object::setTargetID(RGE_Moving_Object *this,int param_1)
{
  this->targetIDValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setTargetRadius
// Address: 0045d6a0
/* public: void __thiscall RGE_Moving_Object::setTargetRadius(float,float) */

void __thiscall
RGE_Moving_Object::setTargetRadius(RGE_Moving_Object *this,float param_1,float param_2)
{
  this->targetRadiusX = param_1;
  this->targetRadiusY = param_2;
  return;
}

// --------------------------------------------------

// Function: findPath
// Address: 0045d6c0
// [HELPER] s___: "]\n"
// [HELPER] s_t_ld_uID__d__fP1_s___6_2f__6_2f_: "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)"
/* WARNING: Removing unreachable block (ram,0x0045d774) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: enum RGE_Moving_Object::PathResult __thiscall RGE_Moving_Object::findPath(void) */

PathResult __thiscall RGE_Moving_Object::findPath(RGE_Moving_Object *this)
{
  Path *pPVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  Waypoint *pWVar8;
  int unaff_EBX;
  float10 fVar9;
  RGE_Moving_Object *pRVar10;
  float fVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  
  if (*(float *)(this->_padding_ + 0x38) <= _DAT_00570b48) {
    (**(code **)(this->_padding_ + 300))(0);
    pPVar1 = &this->pathValue;
    (this->startValue).x = (float)this->_padding_;
    (this->startValue).y = (float)this->_padding_;
    (this->startValue).z = (float)this->_padding_;
    this->_padding_ = 0;
    Path::setTimeStamp(pPVar1,*(ulong *)(*(int *)(this->_padding_ + 0x3c) + 4));
    Path::killPath(pPVar1);
    Path::insertAtCurrent(pPVar1,&this->goalValue);
    Path::insertAtCurrent(pPVar1,&this->startValue);
    Path::initToStart(pPVar1);
    Path::moveToNextWaypoint(pPVar1);
    this->closestDistanceToWaypoint = 100000.0;
    return PathFound;
  }
  iVar2 = RGE_Player::availablePathingAttempts
                    ((RGE_Player *)this->_padding_,(uint)this->numberWaitDelays);
  if (iVar2 == 0) {
    this->numberWaitDelays = this->numberWaitDelays + '\x01';
    return WaitingOnPathingCap;
  }
  RGE_Player::incrementPathingAttempts((RGE_Player *)this->_padding_);
  iVar2 = this->_padding_;
  this->numberWaitDelays = '\0';
  (**(code **)(iVar2 + 300))(0);
  iVar3 = RGE_Player::computerPlayer((RGE_Player *)this->_padding_);
  if (iVar3 == 0) {
    this->continueCounter = this->numberUserDefinedWaypointsValue + 0x19;
  }
  else {
    this->continueCounter = this->numberUserDefinedWaypointsValue + 0xf;
  }
  (this->startValue).x = (float)this->_padding_;
  (this->startValue).y = (float)this->_padding_;
  (this->startValue).z = (float)this->_padding_;
  this->closestDistanceToWaypoint = 100000.0;
  PathingSystem::incrementInitialPaths(&pathSystem);
  pRVar10 = this;
  if (this->numberUserDefinedWaypointsValue < 1) {
    iVar3 = this->targetIDValue;
    fVar11 = this->actionRange;
    iVar17 = -1;
    iVar16 = -1;
    iVar15 = 1;
    iVar14 = 1;
    uVar13 = 0x100000001;
    uVar12 = 1;
    uVar4 = __ftol();
    uVar5 = __ftol();
  }
  else {
    iVar3 = this->targetIDValue;
    fVar11 = this->actionRange;
    iVar17 = -1;
    iVar16 = -1;
    iVar15 = 1;
    iVar14 = 1;
    uVar13 = 0x100000001;
    uVar12 = 1;
    uVar4 = (uint)this->userDefinedWaypoints->y;
    uVar5 = (uint)this->userDefinedWaypoints->x;
  }
  iVar6 = __ftol();
  iVar7 = __ftol();
  iVar3 = PathingSystem::findTilePath
                    (&pathSystem,iVar7,iVar6,uVar5,uVar4,pRVar10,fVar11,iVar3,(int)uVar12,
                     (float *)((ulonglong)uVar12 >> 0x20),(int)uVar13,
                     (int)((ulonglong)uVar13 >> 0x20),iVar14,iVar15,iVar16,iVar17);
  if (actionFile != (_iobuf *)0x0) {
    fprintf(actionFile,s_t_ld_uID__d__fP1_s___6_2f__6_2f_,
            *(undefined4 *)(*(int *)(this->_padding_ + 0x3c) + 4),this->_padding_,
            (double)(this->startValue).x,(double)(this->startValue).y,(double)(this->goalValue).x,
            (double)(this->goalValue).y);
    pPVar1 = &this->pathValue;
    Path::initToStart(pPVar1);
    iVar14 = 0;
    iVar2 = Path::numberOfWaypoints(pPVar1);
    if (0 < iVar2) {
      do {
        Path::currentWaypoint(pPVar1);
        Path::currentWaypoint(pPVar1);
        fprintf();
        iVar14 = iVar14 + 1;
        Path::moveToNextWaypoint(pPVar1);
        iVar2 = Path::numberOfWaypoints(pPVar1);
      } while (iVar14 < iVar2);
    }
    fprintf(actionFile,s___);
    Path::initToStart(pPVar1);
    Path::moveToNextWaypoint(pPVar1);
    iVar2 = unaff_EBX;
  }
  if ((iVar3 == 0) && (iVar3 = Path::numberOfWaypoints(&this->pathValue), iVar3 == 1)) {
    fVar9 = (float10)floor((double)(float)this->_padding_);
    fVar11 = (float)(fVar9 - (float10)_DAT_00570b80);
    fVar9 = (float10)floor((double)(float)this->_padding_);
    iVar3 = PathingSystem::passable
                      (&pathSystem,this,(float)(fVar9 - (float10)_DAT_00570b80),fVar11,iVar3);
    if (iVar3 != 0) {
      fVar11 = (float)this->_padding_;
      fVar9 = (float10)floor((double)fVar11);
      if ((float10)fVar11 - fVar9 == (float10)_DAT_00570b90) {
        fVar11 = (float)this->_padding_;
        fVar9 = (float10)floor((double)fVar11);
        if ((float10)fVar11 - fVar9 == (float10)_DAT_00570b90) goto LAB_0045dab9;
      }
      fVar9 = (float10)floor((double)(float)this->_padding_,this->_padding_);
      fVar9 = (float10)floor((double)(float)this->_padding_,(float)(fVar9 - (float10)_DAT_00570b80))
      ;
      (**(code **)(iVar2 + 0x34))((float)(fVar9 - (float10)_DAT_00570b80));
      return WaitingOnPathingCap;
    }
  }
LAB_0045dab9:
  pPVar1 = &this->pathValue;
  Path::setTimeStamp(pPVar1,*(ulong *)(*(int *)(this->_padding_ + 0x3c) + 4));
  iVar2 = displayPathObjectID;
  if ((displayPathingFlags != 0) && ((this->_padding_ & 0x10000) != 0)) {
    Path::initToStart(pPVar1);
    iVar14 = 0;
    iVar3 = Path::numberOfWaypoints(pPVar1);
    if (0 < iVar3) {
      do {
        iVar3 = this->_padding_;
        uVar18 = 0x3f800000;
        iVar15 = **(int **)(*(int *)(iVar3 + 0x24) + iVar2 * 4);
        pWVar8 = Path::currentWaypoint(pPVar1);
        fVar11 = pWVar8->y;
        pWVar8 = Path::currentWaypoint(pPVar1);
        (**(code **)(iVar15 + 0x18))(iVar3,pWVar8->x,fVar11,uVar18);
        iVar14 = iVar14 + 1;
        Path::moveToNextWaypoint(pPVar1);
        iVar3 = Path::numberOfWaypoints(pPVar1);
      } while (iVar14 < iVar3);
    }
    Path::initToStart(pPVar1);
    Path::moveToNextWaypoint(pPVar1);
  }
  Path::initToStart(pPVar1);
  Path::moveToNextWaypoint(pPVar1);
  return PathFound;
}

// --------------------------------------------------

// Function: doMove
// Address: 0045db90
// [HELPER] s___: "]\n"
// [HELPER] s_t_ld_uID__d__fP1_s___6_2f__6_2f_: "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall RGE_Moving_Object::doMove(void) */

int __thiscall RGE_Moving_Object::doMove(RGE_Moving_Object *this)
{
  Path *pPVar1;
  float fVar2;
  code *pcVar3;
  bool bVar4;
  uchar uVar5;
  uchar uVar6;
  Waypoint *pWVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int unaff_EBX;
  float10 fVar14;
  RGE_Moving_Object *pRVar15;
  float fVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  int iVar19;
  float fVar20;
  float fVar21;
  int iVar22;
  int iVar23;
  undefined4 uVar24;
  float local_20;
  float distanceToGoal;
  float dY;
  float newDY;
  
  iVar9 = this->_padding_;
  (**(code **)(iVar9 + 300))(0);
  local_20 = (this->goalValue).x - (float)this->_padding_;
  fVar16 = (this->goalValue).y - (float)this->_padding_;
  if (local_20 < _DAT_00570b48) {
    local_20 = -local_20;
  }
  if (fVar16 < _DAT_00570b48) {
    fVar16 = -fVar16;
  }
  local_20 = local_20 - (this->targetRadiusX + *(float *)(this->_padding_ + 0x30));
  fVar16 = fVar16 - (this->targetRadiusY + *(float *)(this->_padding_ + 0x34));
  if (local_20 < _DAT_00570b48) {
    local_20 = 0.0;
  }
  if (fVar16 < _DAT_00570b48) {
    fVar16 = _DAT_00570b48;
  }
  fVar16 = SQRT(fVar16 * fVar16 + local_20 * local_20);
  if (((float)_DAT_00570b98 < this->actionRange) && (fVar16 <= this->actionRange)) {
    this->_padding_ = 0;
LAB_0045e3e3:
    this->rangeStatusValue = 1;
    (**(code **)(iVar9 + 0x1c0))(0);
    this->_padding_ = 0;
    return 2;
  }
  if (fVar16 < (float)_DAT_00570b90) {
    pPVar1 = &this->pathValue;
    pWVar7 = Path::currentWaypoint(pPVar1);
    fVar2 = fVar16;
    if (pWVar7 != (Waypoint *)0x0) {
      pWVar7 = Path::currentWaypoint(pPVar1);
      fVar2 = pWVar7->x - (float)this->_padding_;
      pWVar7 = Path::currentWaypoint(pPVar1);
      fVar20 = pWVar7->y - (float)this->_padding_;
      fVar2 = SQRT(fVar20 * fVar20 + fVar2 * fVar2);
    }
    if (fVar2 == _DAT_00570b48) {
      this->_padding_ = 0;
      return 2;
    }
    iVar8 = doTrivialMove(this,(this->goalValue).x,(this->goalValue).y);
    if (iVar8 == 5) goto LAB_0045e3e3;
    if (iVar8 == 0) {
      this->rangeStatusValue = 2;
      return 1;
    }
    if ((iVar8 == 1) || (iVar8 == 6)) goto LAB_0045e426;
    if ((iVar8 == 2) || ((iVar8 == 3 || (iVar8 == 4)))) {
      this->_padding_ = 0;
      goto LAB_0045e3e3;
    }
  }
  pPVar1 = &this->pathValue;
  iVar8 = 1;
  fVar20 = *(float *)(this->_padding_ + 0x30);
  fVar2 = *(float *)(this->_padding_ + 0x34);
  fVar2 = SQRT(fVar2 * fVar2 + fVar20 * fVar20);
  pWVar7 = Path::currentWaypoint(pPVar1);
  if (pWVar7 == (Waypoint *)0x0) {
    iVar8 = 0;
  }
  else {
    pWVar7 = Path::currentWaypoint(pPVar1);
    fVar20 = pWVar7->x - (float)this->_padding_;
    pWVar7 = Path::currentWaypoint(pPVar1);
    fVar21 = pWVar7->y - (float)this->_padding_;
    if (SQRT(fVar21 * fVar21 + fVar20 * fVar20) == _DAT_00570b48) {
      iVar8 = 1;
      pWVar7 = Path::currentWaypoint(pPVar1);
      fVar20 = pWVar7->y;
      pWVar7 = Path::currentWaypoint(pPVar1);
      iVar8 = PathingSystem::passable(&pathSystem,this,pWVar7->x,fVar20,iVar8);
      if (iVar8 != 0) {
        pWVar7 = Path::currentWaypoint(pPVar1);
        fVar20 = pWVar7->z;
        pWVar7 = Path::currentWaypoint(pPVar1);
        fVar21 = pWVar7->y;
        pWVar7 = Path::currentWaypoint(pPVar1);
        (**(code **)(iVar9 + 0x34))(pWVar7->x,fVar21,fVar20);
      }
      iVar8 = Path::moveToNextWaypoint(pPVar1);
      this->closestDistanceToWaypoint = 100000.0;
    }
  }
  distanceToGoal = 0.0;
  if ((1 < this->numberUserDefinedWaypointsValue) && (_DAT_00570ba0 < fVar16)) {
    uVar5 = RGE_Static_Object::lookupZone
                      ((RGE_Static_Object *)this,(uint)this->userDefinedWaypoints->x,
                       (uint)this->userDefinedWaypoints->y);
    uVar6 = RGE_Static_Object::lookupZone
                      ((RGE_Static_Object *)this,(uint)this->userDefinedWaypoints[1].x,
                       (uint)this->userDefinedWaypoints[1].y);
    iVar9 = unaff_EBX;
    if (uVar5 == uVar6) {
      distanceToGoal = 3.0;
    }
  }
  if (iVar8 == 0) {
    if (fVar16 <= distanceToGoal + fVar2 + this->actionRange) {
      this->_padding_ = 0;
      this->rangeStatusValue = 1;
      (**(code **)(iVar9 + 0x1c0))(0);
      this->_padding_ = 0;
      return 2;
    }
    pcVar3 = *(code **)(unaff_EBX + 0x1c4);
    bVar4 = false;
    do {
      (*pcVar3)(0);
      if (this->numberUserDefinedWaypointsValue < 1) {
        return 0;
      }
      fVar16 = (float)this->userDefinedWaypoints->x - (float)this->_padding_;
      fVar20 = (float)this->userDefinedWaypoints->y - (float)this->_padding_;
      if ((fVar2 + this->actionRange) - _DAT_00570ba8 < SQRT(fVar20 * fVar20 + fVar16 * fVar16)) {
        bVar4 = true;
      }
    } while (!bVar4);
    iVar9 = this->continueCounter;
    iVar8 = iVar9 + -1;
    this->continueCounter = iVar8;
    if (iVar8 < 1) {
      this->_padding_ = 0;
      this->rangeStatusValue = 2;
      if (this->numberUserDefinedWaypointsValue < 2) {
        return 0;
      }
      this->continueCounter = iVar9 + 4;
      return 1;
    }
    iVar9 = RGE_Player::availablePathingAttempts
                      ((RGE_Player *)this->_padding_,(uint)this->numberWaitDelays);
    if (iVar9 == 0) {
      this->_padding_ = 0;
      this->numberWaitDelays = this->numberWaitDelays + '\x01';
      return 1;
    }
    RGE_Player::incrementPathingAttempts((RGE_Player *)this->_padding_);
    (this->startValue).x = (float)this->_padding_;
    (this->startValue).y = (float)this->_padding_;
    (this->startValue).z = (float)this->_padding_;
    this->numberWaitDelays = '\0';
    PathingSystem::incrementContinuePaths(&pathSystem);
    pRVar15 = this;
    if (this->numberUserDefinedWaypointsValue < 1) {
      iVar9 = this->targetIDValue;
      fVar16 = this->actionRange;
      iVar23 = -1;
      iVar22 = -1;
      iVar19 = 1;
      iVar8 = 1;
      uVar18 = 0x100000001;
      uVar17 = 1;
      uVar12 = __ftol();
      uVar13 = __ftol();
    }
    else {
      iVar9 = this->targetIDValue;
      fVar16 = this->actionRange;
      iVar23 = -1;
      iVar22 = -1;
      iVar19 = 1;
      iVar8 = 1;
      uVar18 = 0x100000001;
      uVar17 = 1;
      uVar12 = (uint)this->userDefinedWaypoints->y;
      uVar13 = (uint)this->userDefinedWaypoints->x;
    }
    iVar10 = __ftol();
    iVar11 = __ftol();
    iVar9 = PathingSystem::findTilePath
                      (&pathSystem,iVar11,iVar10,uVar13,uVar12,pRVar15,fVar16,iVar9,(int)uVar17,
                       (float *)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                       (int)((ulonglong)uVar18 >> 0x20),iVar8,iVar19,iVar22,iVar23);
    this->_padding_ = 0;
    if (actionFile != (_iobuf *)0x0) {
      fprintf(actionFile,s_t_ld_uID__d__fP1_s___6_2f__6_2f_,
              *(undefined4 *)(*(int *)(this->_padding_ + 0x3c) + 4),this->_padding_,
              (double)(this->startValue).x,(double)(this->startValue).y,(double)(this->goalValue).x,
              (double)(this->goalValue).y);
      Path::initToStart(pPVar1);
      iVar19 = 0;
      iVar8 = Path::numberOfWaypoints(pPVar1);
      if (0 < iVar8) {
        do {
          Path::currentWaypoint(pPVar1);
          Path::currentWaypoint(pPVar1);
          fprintf();
          iVar19 = iVar19 + 1;
          Path::moveToNextWaypoint(pPVar1);
          iVar8 = Path::numberOfWaypoints(pPVar1);
        } while (iVar19 < iVar8);
      }
      fprintf(actionFile,s___);
      Path::initToStart(pPVar1);
      Path::moveToNextWaypoint(pPVar1);
    }
    if ((iVar9 == 0) && (iVar9 = Path::numberOfWaypoints(pPVar1), iVar9 == 1)) {
      iVar9 = 1;
      fVar14 = (float10)floor((double)(float)this->_padding_);
      fVar16 = (float)(fVar14 - (float10)_DAT_00570b80);
      fVar14 = (float10)floor((double)(float)this->_padding_);
      iVar9 = PathingSystem::passable
                        (&pathSystem,this,(float)(fVar14 - (float10)_DAT_00570b80),fVar16,iVar9);
      if ((iVar9 == 0) ||
         ((fVar16 = (float)this->_padding_, fVar14 = (float10)floor((double)fVar16),
          (float10)fVar16 - fVar14 == (float10)_DAT_00570b90 &&
          (fVar16 = (float)this->_padding_, fVar14 = (float10)floor((double)fVar16),
          (float10)fVar16 - fVar14 == (float10)_DAT_00570b90)))) {
        this->_padding_ = 0;
        this->rangeStatusValue = 2;
        if (this->numberUserDefinedWaypointsValue < 2) {
          return 0;
        }
        this->continueCounter = this->continueCounter + 5;
        return 1;
      }
      fVar14 = (float10)floor((double)(float)this->_padding_,this->_padding_);
      fVar14 = (float10)floor((double)(float)this->_padding_,
                              (float)(fVar14 - (float10)_DAT_00570b80));
      (**(code **)(unaff_EBX + 0x34))((float)(fVar14 - (float10)_DAT_00570b80));
    }
    iVar9 = displayPathObjectID;
    if ((displayPathingFlags != 0) && ((this->_padding_ & 0x10000) != 0)) {
      Path::initToStart(pPVar1);
      distanceToGoal = 0.0;
      iVar8 = Path::numberOfWaypoints(pPVar1);
      if (0 < iVar8) {
        do {
          iVar8 = this->_padding_;
          uVar24 = 0x3f800000;
          iVar19 = **(int **)(*(int *)(iVar8 + 0x24) + iVar9 * 4);
          pWVar7 = Path::currentWaypoint(pPVar1);
          fVar16 = pWVar7->y;
          pWVar7 = Path::currentWaypoint(pPVar1);
          (**(code **)(iVar19 + 0x18))(iVar8,pWVar7->x,fVar16,uVar24);
          distanceToGoal = (float)((int)distanceToGoal + 1);
          Path::moveToNextWaypoint(pPVar1);
          iVar8 = Path::numberOfWaypoints(pPVar1);
        } while ((int)distanceToGoal < iVar8);
      }
      Path::initToStart(pPVar1);
      Path::moveToNextWaypoint(pPVar1);
    }
    Path::initToStart(pPVar1);
    iVar9 = Path::moveToNextWaypoint(pPVar1);
    if (iVar9 == 0) {
      this->_padding_ = 0;
      this->rangeStatusValue = 2;
      if (this->numberUserDefinedWaypointsValue < 2) {
        return 0;
      }
      this->continueCounter = this->continueCounter + 5;
      return 1;
    }
    this->closestDistanceToWaypoint = 100000.0;
    iVar9 = unaff_EBX;
  }
  pWVar7 = Path::currentWaypoint(pPVar1);
  if (pWVar7 != (Waypoint *)0x0) {
    pWVar7 = Path::currentWaypoint(pPVar1);
    fVar16 = pWVar7->y;
    pWVar7 = Path::currentWaypoint(pPVar1);
    iVar8 = doTrivialMove(this,pWVar7->x,fVar16);
    if (iVar8 == 5) goto LAB_0045e3e3;
    if (iVar8 == 0) {
      this->rangeStatusValue = 2;
      return 1;
    }
    if (iVar8 == 1) {
LAB_0045e426:
      this->_padding_ = 0;
      this->rangeStatusValue = 2;
      return 1;
    }
    if (iVar8 == 2) {
      iVar9 = Path::moveToNextWaypoint(pPVar1);
      if (iVar9 == 0) {
        bVar4 = false;
        pcVar3 = *(code **)(unaff_EBX + 0x1c4);
        do {
          (*pcVar3)(0);
          if (this->numberUserDefinedWaypointsValue < 1) {
            return 0;
          }
          fVar16 = (float)this->userDefinedWaypoints->x - (float)this->_padding_;
          fVar20 = (float)this->userDefinedWaypoints->y - (float)this->_padding_;
          if ((fVar2 + this->actionRange) - _DAT_00570ba8 < SQRT(fVar20 * fVar20 + fVar16 * fVar16))
{
            bVar4 = true;
          }
        } while (!bVar4);
        iVar9 = RGE_Player::availablePathingAttempts
                          ((RGE_Player *)this->_padding_,(uint)this->numberWaitDelays);
        if (iVar9 == 0) {
          this->_padding_ = 0;
          this->numberWaitDelays = this->numberWaitDelays + '\x01';
          return 1;
        }
        RGE_Player::incrementPathingAttempts((RGE_Player *)this->_padding_);
        (this->startValue).x = (float)this->_padding_;
        (this->startValue).y = (float)this->_padding_;
        (this->startValue).z = (float)this->_padding_;
        this->numberWaitDelays = '\0';
        PathingSystem::incrementContinuePaths(&pathSystem);
        pRVar15 = this;
        if (this->numberUserDefinedWaypointsValue < 1) {
          iVar9 = this->targetIDValue;
          fVar16 = this->actionRange;
          iVar23 = -1;
          iVar22 = -1;
          iVar19 = 1;
          iVar8 = 1;
          uVar18 = 0x100000001;
          uVar17 = 1;
          uVar12 = __ftol();
          uVar13 = __ftol();
        }
        else {
          iVar9 = this->targetIDValue;
          fVar16 = this->actionRange;
          iVar23 = -1;
          iVar22 = -1;
          iVar19 = 1;
          iVar8 = 1;
          uVar18 = 0x100000001;
          uVar17 = 1;
          uVar12 = (uint)this->userDefinedWaypoints->y;
          uVar13 = (uint)this->userDefinedWaypoints->x;
        }
        iVar10 = __ftol();
        iVar11 = __ftol();
        iVar9 = PathingSystem::findTilePath
                          (&pathSystem,iVar11,iVar10,uVar13,uVar12,pRVar15,fVar16,iVar9,(int)uVar17,
                           (float *)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                           (int)((ulonglong)uVar18 >> 0x20),iVar8,iVar19,iVar22,iVar23);
        this->_padding_ = 0;
        if (actionFile != (_iobuf *)0x0) {
          fprintf(actionFile,s_t_ld_uID__d__fP1_s___6_2f__6_2f_,
                  *(undefined4 *)(*(int *)(this->_padding_ + 0x3c) + 4),this->_padding_,
                  (double)(this->startValue).x,(double)(this->startValue).y,
                  (double)(this->goalValue).x,(double)(this->goalValue).y);
          Path::initToStart(pPVar1);
          iVar19 = 0;
          iVar8 = Path::numberOfWaypoints(pPVar1);
          if (0 < iVar8) {
            do {
              Path::currentWaypoint(pPVar1);
              Path::currentWaypoint(pPVar1);
              fprintf();
              iVar19 = iVar19 + 1;
              Path::moveToNextWaypoint(pPVar1);
              iVar8 = Path::numberOfWaypoints(pPVar1);
            } while (iVar19 < iVar8);
          }
          fprintf(actionFile,s___);
          Path::initToStart(pPVar1);
          Path::moveToNextWaypoint(pPVar1);
        }
        if ((iVar9 == 0) && (iVar9 = Path::numberOfWaypoints(pPVar1), iVar9 == 1)) {
          fVar14 = (float10)floor((double)(float)this->_padding_);
          fVar16 = (float)(fVar14 - (float10)_DAT_00570b80);
          fVar14 = (float10)floor((double)(float)this->_padding_);
          iVar9 = PathingSystem::passable
                            (&pathSystem,this,(float)(fVar14 - (float10)_DAT_00570b80),fVar16,iVar9)
          ;
          if (iVar9 != 0) {
            fVar16 = (float)this->_padding_;
            fVar14 = (float10)floor((double)fVar16);
            if (((float10)fVar16 - fVar14 == (float10)_DAT_00570b90) &&
               (fVar16 = (float)this->_padding_, fVar14 = (float10)floor((double)fVar16),
               (float10)fVar16 - fVar14 == (float10)_DAT_00570b90)) {
              this->_padding_ = 0;
              this->rangeStatusValue = 2;
              if (this->numberUserDefinedWaypointsValue < 2) {
                return 0;
              }
              this->continueCounter = this->continueCounter + 5;
              return 1;
            }
            fVar14 = (float10)floor((double)(float)this->_padding_,this->_padding_);
            fVar14 = (float10)floor((double)(float)this->_padding_,
                                    (float)(fVar14 - (float10)_DAT_00570b80));
            (**(code **)(unaff_EBX + 0x34))((float)(fVar14 - (float10)_DAT_00570b80));
          }
        }
        iVar9 = displayPathObjectID;
        if ((displayPathingFlags != 0) && ((this->_padding_ & 0x10000) != 0)) {
          Path::initToStart(pPVar1);
          distanceToGoal = 0.0;
          iVar8 = Path::numberOfWaypoints(pPVar1);
          if (0 < iVar8) {
            do {
              iVar8 = this->_padding_;
              uVar24 = 0x3f800000;
              iVar19 = **(int **)(*(int *)(iVar8 + 0x24) + iVar9 * 4);
              pWVar7 = Path::currentWaypoint(pPVar1);
              fVar16 = pWVar7->y;
              pWVar7 = Path::currentWaypoint(pPVar1);
              (**(code **)(iVar19 + 0x18))(iVar8,pWVar7->x,fVar16,uVar24);
              distanceToGoal = (float)((int)distanceToGoal + 1);
              Path::moveToNextWaypoint(pPVar1);
              iVar8 = Path::numberOfWaypoints(pPVar1);
            } while ((int)distanceToGoal < iVar8);
          }
          Path::initToStart(pPVar1);
          Path::moveToNextWaypoint(pPVar1);
        }
        Path::initToStart(pPVar1);
        iVar9 = Path::moveToNextWaypoint(pPVar1);
        if (iVar9 == 0) {
          this->_padding_ = 0;
          this->rangeStatusValue = 2;
          if (this->numberUserDefinedWaypointsValue < 2) {
            return 0;
          }
          this->continueCounter = this->continueCounter + 5;
          return 1;
        }
      }
      this->rangeStatusValue = 2;
      return 1;
    }
  }
  this->_padding_ = 0;
  this->rangeStatusValue = 2;
  if (this->numberUserDefinedWaypointsValue < 2) {
    return 0;
  }
  this->continueCounter = this->continueCounter + 5;
  return 1;
}

// --------------------------------------------------

// Function: doTrivialMove
// Address: 0045e970
// [HELPER] s_C__msdev_work_age1_x1_move_obj_c: "C:\msdev\work\age1_x1\move_obj.cpp"
// [HELPER] s___: "]\n"
// [HELPER] s_t_ld_uID__d__fP1_s___6_2f__6_2f_: "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall RGE_Moving_Object::doTrivialMove(float,float) */

int __thiscall RGE_Moving_Object::doTrivialMove(RGE_Moving_Object *this,float param_1,float param_2)
{
  float *pfVar1;
  Path *pPVar2;
  uchar uVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  RGE_Static_Object *pRVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  Waypoint *pWVar12;
  int iVar13;
  float fVar14;
  int iVar15;
  float10 fVar16;
  float10 fVar17;
  float fVar18;
  RGE_Moving_Object *pRVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  undefined4 uVar26;
  int numberFacets;
  float targetDY;
  float newAngle;
  float distanceToCover;
  float dX;
  float newY;
  float curDistance;
  int alreadyMoving;
  float dY;
  undefined4 uStack_c;
  
  bVar4 = true;
  curDistance = 1.4013e-45;
  if ((float)this->_padding_ == (float)_DAT_00570b98) {
    iVar15 = this->_padding_;
    bVar4 = false;
    curDistance = 0.0;
    if ((iVar15 == 0) || (*(float *)(iVar15 + 100) <= (float)_DAT_00570b98)) {
      this->_padding_ = *(int *)(this->_padding_ + 0xb8);
    }
    else {
      this->_padding_ = (int)(*(float *)(this->_padding_ + 0xb8) * *(float *)(iVar15 + 100));
    }
  }
  newAngle = *(float *)(*(int *)(this->_padding_ + 0x3c) + 0x84) * (float)this->_padding_;
  if ((float)_DAT_00570b98 < this->collisionAvoidanceDistance) {
    fVar14 = this->collisionAvoidanceDistance - newAngle;
    fVar18 = (float)_DAT_00570b98;
    this->collisionAvoidanceDistance = fVar14;
    if (fVar18 < fVar14) {
      this->_padding_ = 0;
      return 0;
    }
    this->collisionAvoidanceDistance = -1.0;
  }
  if ((float)_DAT_00570b98 < *(float *)(this->_padding_ + 0xc4)) {
    if ((float)_DAT_00570b98 <= this->turnTimer) {
      this->turnTimer = this->turnTimer - *(float *)(*(int *)(this->_padding_ + 0x3c) + 0x84);
    }
    else {
      this->turnTimer = 0.0;
    }
  }
  if (this->_padding_ == 0) {
    iVar15 = 8;
  }
  else {
    iVar15 = (int)*(short *)(this->_padding_ + 0x60);
  }
  if (bVar4) {
    numberFacets = (int)(param_1 - (float)this->_padding_);
    fVar16 = (float10)param_2 - (float10)(float)this->_padding_;
  }
  else {
    fVar16 = (float10)floor((double)(float)this->_padding_);
    numberFacets = (int)(float)((float10)param_1 - (fVar16 - (float10)_DAT_00570b80));
    fVar16 = (float10)floor((double)(float)this->_padding_);
    fVar16 = (float10)param_2 - (fVar16 - (float10)_DAT_00570b80);
  }
  fVar16 = (float10)fpatan(fVar16,(float10)(float)numberFacets);
  targetDY = (float)fVar16;
  boundAngle(this,&targetDY,-1);
  numberFacets = (int)(targetDY - this->angle);
  if ((float)numberFacets < (float)_DAT_00570b70) {
    do {
      numberFacets = (int)((float)numberFacets - _DAT_00570b4c);
    } while ((float)numberFacets < (float)_DAT_00570b70);
  }
  if ((float)_DAT_00570b68 < (float)numberFacets) {
    do {
      numberFacets = (int)((float)numberFacets - _DAT_00570b50);
    } while ((float)_DAT_00570b68 < (float)numberFacets);
  }
  alreadyMoving = (int)(float)iVar15;
  pfVar1 = &this->angle;
  newY = (float)numberFacets * (float)alreadyMoving * _DAT_00570b78;
  boundAngle(this,pfVar1,iVar15);
  fVar14 = newY;
  if (this->turnTimer <= _DAT_00570b48) {
    do {
      if ((fVar14 <= (float)_DAT_00570bb0) && ((float)_DAT_00570bb8 <= fVar14)) break;
      bVar4 = _DAT_00570b48 <= (float)numberFacets;
      this->turnTimer = *(float *)(this->_padding_ + 0xc4) + this->turnTimer;
      if (bVar4) {
        fVar5 = (float)_DAT_00570b40 / (float)iVar15 + *pfVar1;
        fVar18 = _DAT_00570b60;
      }
      else {
        fVar5 = *pfVar1 - (float)_DAT_00570b40 / (float)iVar15;
        fVar18 = _DAT_00570b64;
      }
      *pfVar1 = fVar5;
      fVar14 = fVar14 - fVar18;
    } while (this->turnTimer <= _DAT_00570b48);
  }
  boundAngle(this,pfVar1,iVar15);
  set_angle(this);
  fVar16 = (float10)fcos((float10)*pfVar1);
  iVar13 = 1;
  fVar17 = (float10)fsin((float10)*pfVar1);
  distanceToCover = (float)(fVar17 * (float10)newAngle);
  this->velocity_x = (float)(fVar16 * (float10)newAngle);
  this->velocity_y = (float)(fVar17 * (float10)newAngle);
  fVar14 = (float)this->_padding_ + (float)(fVar16 * (float10)newAngle);
  dX = (float)this->_padding_ + distanceToCover;
  newY = fVar14;
  if (_DAT_00570b48 < *(float *)(this->_padding_ + 0x38)) {
    iVar13 = PathingSystem::passable(&pathSystem,this,fVar14,dX,1);
  }
  if (iVar13 == 0) {
    if (this->collisionAvoidanceDistance == _DAT_00570b48) {
      if ((float)this->_padding_ <= _DAT_00570b48) {
        iVar15 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0x6d1);
        this->_padding_ = 0;
        this->collisionAvoidanceDistance = (float)(iVar15 % 6) * _DAT_00570bc0 - _DAT_00570b80;
        return 0;
      }
      iVar15 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0x6cf);
      fVar14 = (float)(iVar15 % 6) * _DAT_00570bc0;
      fVar18 = _DAT_00570b80 / (float)this->_padding_;
      this->_padding_ = 0;
      this->collisionAvoidanceDistance = fVar14 - fVar18;
      return 0;
    }
    iVar13 = 1;
    this->collisionAvoidanceDistance = 0.0;
    fVar16 = (float10)floor((double)(float)this->_padding_);
    fVar14 = (float)(fVar16 - (float10)_DAT_00570b80);
    fVar16 = (float10)floor((double)(float)this->_padding_);
    iVar13 = PathingSystem::passable
                       (&pathSystem,this,(float)(fVar16 - (float10)_DAT_00570b80),fVar14,iVar13);
    if (iVar13 != 0) {
      iVar13 = this->_padding_;
      fVar16 = (float10)floor((double)(float)this->_padding_,this->_padding_);
      fVar16 = (float10)floor((double)(float)this->_padding_,
                              (float)(fVar16 - (float10)_DAT_00570b80));
      (**(code **)(iVar13 + 0x34))((float)(fVar16 - (float10)_DAT_00570b80));
    }
    if (((this->targetIDValue != -1) &&
        (pRVar7 = RGE_Game_World::object
                            (*(RGE_Game_World **)(this->_padding_ + 0x3c),this->targetIDValue),
        pRVar7 != (RGE_Static_Object *)0x0)) &&
       (fVar14 = *(float *)(this->_padding_ + 0x34), fVar18 = *(float *)(this->_padding_ + 0x30),
       fVar5 = pRVar7->world_x - (float)this->_padding_,
       fVar6 = pRVar7->world_y - (float)this->_padding_,
       distanceToCover = SQRT(fVar6 * fVar6 + fVar5 * fVar5),
       distanceToCover <
       (SQRT(fVar14 * fVar14 + fVar18 * fVar18) + this->actionRange) - _DAT_00570ba8)) {
      return 5;
    }
    iVar13 = PathingSystem::passable(&pathSystem,this,param_1,param_2,1);
    if (iVar13 == 0) {
      return 2;
    }
    iVar13 = this->continueCounter + -1;
    this->continueCounter = iVar13;
    if (iVar13 < 1) {
      return 4;
    }
    iVar13 = RGE_Player::availablePathingAttempts
                       ((RGE_Player *)this->_padding_,(uint)this->numberWaitDelays);
    if (iVar13 == 0) {
      this->numberWaitDelays = this->numberWaitDelays + '\x01';
      return 1;
    }
    RGE_Player::incrementPathingAttempts((RGE_Player *)this->_padding_);
    (this->startValue).x = (float)this->_padding_;
    (this->startValue).y = (float)this->_padding_;
    (this->startValue).z = (float)this->_padding_;
    this->numberWaitDelays = '\0';
    PathingSystem::incrementContinuePaths(&pathSystem);
    pRVar19 = this;
    if (this->numberUserDefinedWaypointsValue < 1) {
      iVar13 = this->targetIDValue;
      fVar14 = this->actionRange;
      iVar25 = -1;
      iVar24 = -1;
      iVar23 = 1;
      iVar22 = 1;
      uVar21 = 0x100000001;
      uVar20 = 1;
      uVar8 = __ftol();
      uVar9 = __ftol();
    }
    else {
      iVar13 = this->targetIDValue;
      fVar14 = this->actionRange;
      iVar25 = -1;
      iVar24 = -1;
      iVar23 = 1;
      iVar22 = 1;
      uVar21 = 0x100000001;
      uVar20 = 1;
      uVar8 = (uint)this->userDefinedWaypoints->y;
      uVar9 = (uint)this->userDefinedWaypoints->x;
    }
    iVar10 = __ftol();
    iVar11 = __ftol();
    distanceToCover =
         (float)PathingSystem::findTilePath
                          (&pathSystem,iVar11,iVar10,uVar9,uVar8,pRVar19,fVar14,iVar13,(int)uVar20,
                           (float *)((ulonglong)uVar20 >> 0x20),(int)uVar21,
                           (int)((ulonglong)uVar21 >> 0x20),iVar22,iVar23,iVar24,iVar25);
    if (actionFile != (_iobuf *)0x0) {
      fprintf(actionFile,s_t_ld_uID__d__fP1_s___6_2f__6_2f_,
              *(undefined4 *)(*(int *)(this->_padding_ + 0x3c) + 4),this->_padding_,
              (double)(this->startValue).x,(double)(this->startValue).y,(double)(this->goalValue).x,
              (double)(this->goalValue).y);
      pPVar2 = &this->pathValue;
      Path::initToStart(pPVar2);
      iVar22 = 0;
      iVar13 = Path::numberOfWaypoints(pPVar2);
      if (0 < iVar13) {
        do {
          Path::currentWaypoint(pPVar2);
          Path::currentWaypoint(pPVar2);
          fprintf();
          iVar22 = iVar22 + 1;
          Path::moveToNextWaypoint(pPVar2);
          iVar13 = Path::numberOfWaypoints(pPVar2);
        } while (iVar22 < iVar13);
      }
      fprintf(actionFile,s___);
      Path::initToStart(pPVar2);
      Path::moveToNextWaypoint(pPVar2);
    }
    if ((distanceToCover == 0.0) &&
       (iVar13 = Path::numberOfWaypoints(&this->pathValue), iVar13 == 1)) {
      fVar16 = (float10)floor((double)(float)this->_padding_);
      fVar14 = (float)(fVar16 - (float10)_DAT_00570b80);
      fVar16 = (float10)floor((double)(float)this->_padding_);
      iVar13 = PathingSystem::passable
                         (&pathSystem,this,(float)(fVar16 - (float10)_DAT_00570b80),fVar14,iVar13);
      if (iVar13 != 0) {
        _dY = (double)(float)this->_padding_;
        fVar16 = (float10)floor(_dY);
        if ((float10)_dY - fVar16 == (float10)_DAT_00570b90) {
          _dY = (double)(float)this->_padding_;
          fVar16 = (float10)floor(_dY);
          if ((float10)_dY - fVar16 == (float10)_DAT_00570b90) {
            return 4;
          }
        }
        iVar13 = this->_padding_;
        fVar16 = (float10)floor((double)(float)this->_padding_,this->_padding_);
        fVar16 = (float10)floor((double)(float)this->_padding_,
                                (float)(fVar16 - (float10)_DAT_00570b80));
        (**(code **)(iVar13 + 0x34))((float)(fVar16 - (float10)_DAT_00570b80));
      }
    }
    iVar13 = displayPathObjectID;
    if ((displayPathingFlags != 0) && ((this->_padding_ & 0x10000) != 0)) {
      pPVar2 = &this->pathValue;
      Path::initToStart(pPVar2);
      distanceToCover = 0.0;
      iVar22 = Path::numberOfWaypoints(pPVar2);
      if (0 < iVar22) {
        fVar14 = (float)(iVar13 << 2);
        _dY = (double)CONCAT44(uStack_c,fVar14);
        do {
          iVar13 = this->_padding_;
          uVar26 = 0x3f800000;
          iVar22 = **(int **)(*(int *)(iVar13 + 0x24) + (int)fVar14);
          pWVar12 = Path::currentWaypoint(pPVar2);
          fVar18 = pWVar12->y;
          pWVar12 = Path::currentWaypoint(pPVar2);
          fVar14 = dY;
          (**(code **)(iVar22 + 0x18))(iVar13,pWVar12->x,fVar18,uVar26);
          distanceToCover = (float)((int)distanceToCover + 1);
          Path::moveToNextWaypoint(pPVar2);
          iVar13 = Path::numberOfWaypoints(pPVar2);
        } while ((int)distanceToCover < iVar13);
      }
      Path::initToStart(pPVar2);
      Path::moveToNextWaypoint(pPVar2);
    }
    pPVar2 = &this->pathValue;
    Path::initToStart(pPVar2);
    iVar13 = Path::moveToNextWaypoint(pPVar2);
    if (iVar13 == 0) {
      return 4;
    }
    this->closestDistanceToWaypoint = 100000.0;
    if (curDistance == 1.4013e-45) {
      pWVar12 = Path::currentWaypoint(pPVar2);
      numberFacets = (int)(pWVar12->x - (float)this->_padding_);
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar16 = (float10)pWVar12->y - (float10)(float)this->_padding_;
    }
    else {
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar16 = (float10)floor((double)(float)this->_padding_);
      numberFacets = (int)(float)((float10)pWVar12->x - (fVar16 - (float10)_DAT_00570b80));
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar16 = (float10)floor((double)(float)this->_padding_);
      fVar16 = (float10)pWVar12->y - (fVar16 - (float10)_DAT_00570b80);
    }
    fVar16 = (float10)fpatan(fVar16,(float10)(float)numberFacets);
    targetDY = (float)fVar16;
    boundAngle(this,&targetDY,-1);
    fVar14 = targetDY - this->angle;
    pfVar1 = &this->angle;
    fVar18 = fVar14 * (float)alreadyMoving * _DAT_00570b78;
    if (_DAT_00570b48 < this->turnTimer) {
      this->_padding_ = 0;
      return 0;
    }
    do {
      if ((fVar18 <= (float)_DAT_00570bc8) && ((float)_DAT_00570bd0 <= fVar18)) break;
      bVar4 = _DAT_00570b48 <= fVar14;
      this->turnTimer = *(float *)(this->_padding_ + 0xc4) + this->turnTimer;
      if (bVar4) {
        fVar6 = (float)_DAT_00570b40 / (float)iVar15 + *pfVar1;
        fVar5 = _DAT_00570b60;
      }
      else {
        fVar6 = *pfVar1 - (float)_DAT_00570b40 / (float)iVar15;
        fVar5 = _DAT_00570b64;
      }
      fVar18 = fVar18 - fVar5;
      *pfVar1 = fVar6;
    } while (this->turnTimer <= _DAT_00570b48);
    boundAngle(this,pfVar1,iVar15);
    set_angle(this);
    fVar16 = (float10)fsin((float10)*pfVar1);
    fVar17 = (float10)fcos((float10)*pfVar1);
    _dY = (double)CONCAT44(uStack_c,(float)fVar17);
    distanceToCover = (float)(fVar16 * (float10)newAngle);
    dX = (float)this->_padding_ + distanceToCover;
    newY = (float)this->_padding_ + (float)(fVar17 * (float10)newAngle);
    this->velocity_x = (float)(fVar17 * (float10)newAngle);
    this->velocity_y = distanceToCover;
    alreadyMoving = (int)newY;
    iVar15 = PathingSystem::passable(&pathSystem,this,newY,dX,1);
    fVar14 = newY;
    if (iVar15 == 0) {
      iVar15 = RGE_Player::computerPlayer((RGE_Player *)this->_padding_);
      if (iVar15 != 1) {
        if ((float)this->_padding_ <= _DAT_00570b48) {
                    /* language.dll match for 0x7d5: "Could not initialize communications system.
                       Make sure that you have DirectX 5.0a or higher and that it is installed
                       properly." */
          iVar15 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0x7d5);
          fVar14 = (float)(iVar15 % 6) * _DAT_00570bc0 - _DAT_00570b80;
        }
        else {
                    /* language.dll match for 0x7d3: "Could not initialize graphics system. Make
                       sure that your video card and driver are compatible with DirectDraw." */
          iVar15 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0x7d3);
          fVar14 = (float)(iVar15 % 6) * _DAT_00570bc0 - _DAT_00570b80 / (float)this->_padding_;
        }
        this->collisionAvoidanceDistance = fVar14;
        this->_padding_ = 0;
        return 0;
      }
      return 4;
    }
  }
  curDistance = (float)this->_padding_;
  pPVar2 = &this->pathValue;
  pWVar12 = Path::currentWaypoint(pPVar2);
  if (pWVar12 == (Waypoint *)0x0) {
    fVar5 = param_1 - newY;
    alreadyMoving = (int)(param_2 - dX);
    _dY = (double)fVar5;
    fVar18 = this->velocity_z + (float)this->_padding_;
    iVar15 = this->_padding_;
    newY = SQRT((float)alreadyMoving * (float)alreadyMoving + fVar5 * fVar5);
  }
  else {
    pWVar12 = Path::currentWaypoint(pPVar2);
    distanceToCover = pWVar12->x - (float)this->_padding_;
    pWVar12 = Path::currentWaypoint(pPVar2);
    alreadyMoving = (int)(pWVar12->y - (float)this->_padding_);
    newY = SQRT((float)alreadyMoving * (float)alreadyMoving + distanceToCover * distanceToCover);
    pWVar12 = Path::currentWaypoint(pPVar2);
    distanceToCover = pWVar12->x - ((float)this->_padding_ + this->velocity_x);
    pWVar12 = Path::currentWaypoint(pPVar2);
    fVar18 = pWVar12->y - ((float)this->_padding_ + this->velocity_y);
    fVar18 = SQRT(fVar18 * fVar18 + distanceToCover * distanceToCover);
    uStack_c = (undefined4)((ulonglong)(double)distanceToCover >> 0x20);
    _dY = (double)CONCAT44(uStack_c,fVar18);
    if (((this->closestDistanceToWaypoint < fVar18) && (newY < _DAT_00570bd8)) ||
       ((this->lastFacet2 == *(uchar *)((int)&this->_padding_ + 1) &&
        ((this->lastFacet2 != this->lastFacet && (newY < _DAT_00570b7c)))))) {
      iVar15 = 1;
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar14 = pWVar12->y;
      pWVar12 = Path::currentWaypoint(pPVar2);
      iVar15 = PathingSystem::passable(&pathSystem,this,pWVar12->x,fVar14,iVar15);
      if (iVar15 == 0) {
        return 2;
      }
      iVar15 = this->_padding_;
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar14 = pWVar12->z;
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar18 = pWVar12->y;
      pWVar12 = Path::currentWaypoint(pPVar2);
      (**(code **)(iVar15 + 0x34))(pWVar12->x,fVar18,fVar14);
      goto LAB_0045f704;
    }
    fVar18 = this->velocity_z + (float)this->_padding_;
    iVar15 = this->_padding_;
  }
  (**(code **)(iVar15 + 0x34))(fVar14,dX,fVar18);
LAB_0045f704:
  fVar18 = distanceToCover - (float)this->_padding_;
  uVar3 = this->lastFacet;
  fVar5 = (float)_DAT_00570be0;
  fVar14 = 1.0;
  this->lastFacet = *(uchar *)((int)&this->_padding_ + 1);
  this->lastFacet2 = uVar3;
  this->closestDistanceToWaypoint = newAngle;
  if (fVar5 <= fVar18) {
    if (fVar18 <= (float)_DAT_00570bf0) {
      iVar15 = this->_padding_;
      if ((iVar15 == 0) || (*(float *)(iVar15 + 100) <= (float)_DAT_00570b98)) {
        this->_padding_ = *(int *)(this->_padding_ + 0xb8);
      }
      else {
        this->_padding_ = (int)(*(float *)(this->_padding_ + 0xb8) * *(float *)(iVar15 + 100));
      }
    }
    else {
      fVar14 = 1.03;
    }
  }
  else {
    fVar14 = 0.9;
  }
  if (this->_padding_ != 0) {
    fVar18 = RGE_Static_Object::get_terrain_speed
                       ((RGE_Static_Object *)this,*(byte *)(this->_padding_ + 5) & 0x1f);
    fVar14 = fVar18 * fVar14;
  }
  if (_DAT_00570b48 < fVar14) {
    this->_padding_ = (int)(fVar14 * (float)this->_padding_);
  }
  return 0;
}

// --------------------------------------------------

// Function: passableTile
// Address: 0045f7f0
/* public: virtual int __thiscall RGE_Moving_Object::passableTile(float,float,int) */

int __thiscall
RGE_Moving_Object::passableTile(RGE_Moving_Object *this,float param_1,float param_2,int param_3)
{
  int iVar1;
  PathingSystem *this_00;
  
  this_00 = &aiPathSystem;
  if (param_3 == 0) {
    this_00 = &pathSystem;
  }
  iVar1 = PathingSystem::passable(this_00,this,param_1,param_2,1);
  return iVar1;
}

// --------------------------------------------------

// Function: canPath
// Address: 0045f820
/* public: virtual int __thiscall RGE_Moving_Object::canPath(struct XYZPoint,float,int,float
   *,int,int,int) */

int __thiscall
RGE_Moving_Object::canPath
          (RGE_Moving_Object *this,XYZPoint param_1,float param_2,int param_3,float *param_4,
          int param_5,int param_6,int param_7)
{
  XYPoint XVar1;
  uchar uVar2;
  uchar uVar3;
  RGE_Zone_Map *this_00;
  long lVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if ((-1 < param_1.x) && (-1 < param_1.y)) {
    iVar6 = *(int *)(this->_padding_ + 0x3c);
    iVar7 = *(int *)(iVar6 + 0x28);
    if ((param_1.x < *(int *)(iVar7 + 8)) && (param_1.y < *(int *)(iVar7 + 0xc))) {
      if (this->_padding_ == -1) {
        RGE_Zone_Map_List::get_zone_map
                  (*(RGE_Zone_Map_List **)(iVar7 + 0x8dc4),
                   *(float **)(*(int *)(iVar6 + 0x54) + *(short *)(this->_padding_ + 0x66) * 4),
                   (int)*(short *)(iVar6 + 0x52),&this->_padding_);
      }
      this_00 = RGE_Zone_Map_List::get_zone_map
                          (*(RGE_Zone_Map_List **)
                            (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28) + 0x8dc4),
                           this->_padding_);
      if (this_00 != (RGE_Zone_Map *)0x0) {
        lVar4 = __ftol();
        lVar5 = __ftol();
        uVar2 = RGE_Zone_Map::get_zone_info(this_00,lVar5,lVar4);
        uVar3 = RGE_Zone_Map::get_zone_info(this_00,param_1.x,param_1.y);
        if (uVar3 != uVar2) {
          iVar6 = __ftol();
          iVar7 = __ftol();
          XVar1.y = iVar7;
          XVar1.x = iVar6;
          iVar6 = RGE_Zone_Map::withinRange(this_00,XVar1,param_1._0_8_,param_2);
          if (iVar6 == 0) {
            return 0;
          }
        }
        if (param_5 == 0) {
          PathingSystem::incrementCanPaths(&pathSystem);
          iVar12 = 1;
          iVar11 = 1;
          iVar10 = 1;
          iVar9 = 1;
          iVar8 = 0;
          iVar6 = __ftol();
          iVar7 = __ftol();
          iVar6 = PathingSystem::findTilePath
                            (&pathSystem,iVar7,iVar6,param_1.x,param_1.y,this,param_2,param_3,iVar8,
                             param_4,iVar9,iVar10,iVar11,iVar12,param_6,param_7);
          return iVar6;
        }
        PathingSystem::incrementCanPaths(&aiPathSystem);
        iVar12 = 1;
        iVar11 = 1;
        iVar10 = 1;
        iVar9 = 1;
        iVar8 = 0;
        iVar6 = __ftol();
        iVar7 = __ftol();
        iVar6 = PathingSystem::findTilePath
                          (&aiPathSystem,iVar7,iVar6,param_1.x,param_1.y,this,param_2,param_3,iVar8,
                           param_4,iVar9,iVar10,iVar11,iVar12,param_6,param_7);
        return iVar6;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: canPath
// Address: 0045f9d0
/* WARNING: Variable defined which should be unmapped: start */
/* public: virtual int __thiscall RGE_Moving_Object::canPath(int,float,float *,int,int,int) */

int __thiscall
RGE_Moving_Object::canPath
          (RGE_Moving_Object *this,int param_1,float param_2,float *param_3,int param_4,int param_5,
          int param_6)
{
  XYPoint XVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *pRVar5;
  RGE_Zone_Map *this_00;
  long lVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  XYPoint start;
  XYPoint goal;
  
  pRVar5 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  if (pRVar5 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  if (this->_padding_ == -1) {
    iVar8 = *(int *)(this->_padding_ + 0x3c);
    RGE_Zone_Map_List::get_zone_map
              (*(RGE_Zone_Map_List **)(*(int *)(iVar8 + 0x28) + 0x8dc4),
               *(float **)(*(int *)(iVar8 + 0x54) + *(short *)(this->_padding_ + 0x66) * 4),
               (int)*(short *)(iVar8 + 0x52),&this->_padding_);
  }
  this_00 = RGE_Zone_Map_List::get_zone_map
                      (*(RGE_Zone_Map_List **)
                        (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28) + 0x8dc4),this->_padding_
                      );
  if (this_00 == (RGE_Zone_Map *)0x0) {
    return 0;
  }
  lVar6 = __ftol();
  lVar7 = __ftol();
  uVar3 = RGE_Zone_Map::get_zone_info(this_00,lVar7,lVar6);
  lVar6 = __ftol();
  lVar7 = __ftol();
  uVar4 = RGE_Zone_Map::get_zone_info(this_00,lVar7,lVar6);
  if (uVar4 != uVar3) {
    iVar8 = __ftol();
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    XVar1.y = iVar9;
    XVar1.x = iVar8;
    XVar2.y = iVar11;
    XVar2.x = iVar10;
    iVar8 = RGE_Zone_Map::withinRange(this_00,XVar1,XVar2,param_2);
    if (iVar8 == 0) {
      return 0;
    }
  }
  if (param_4 != 0) {
    PathingSystem::incrementCanPaths(&aiPathSystem);
    iVar16 = 1;
    iVar15 = 1;
    iVar14 = 1;
    iVar13 = 1;
    iVar12 = 0;
    iVar8 = __ftol();
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    iVar8 = PathingSystem::findTilePath
                      (&aiPathSystem,iVar11,iVar10,iVar9,iVar8,this,param_2,param_1,iVar12,param_3,
                       iVar13,iVar14,iVar15,iVar16,param_5,param_6);
    return iVar8;
  }
  PathingSystem::incrementCanPaths(&pathSystem);
  iVar16 = 1;
  iVar15 = 1;
  iVar14 = 1;
  iVar13 = 1;
  iVar12 = 0;
  iVar8 = __ftol();
  iVar9 = __ftol();
  iVar10 = __ftol();
  iVar11 = __ftol();
  iVar8 = PathingSystem::findTilePath
                    (&pathSystem,iVar11,iVar10,iVar9,iVar8,this,param_2,param_1,iVar12,param_3,
                     iVar13,iVar14,iVar15,iVar16,param_5,param_6);
  return iVar8;
}

// --------------------------------------------------

// Function: canBidirectionPath
// Address: 0045fbc0
/* WARNING: Variable defined which should be unmapped: start */
/* public: virtual int __thiscall RGE_Moving_Object::canBidirectionPath(int,int,float,float
   *,int,int,int) */

int __thiscall
RGE_Moving_Object::canBidirectionPath
          (RGE_Moving_Object *this,int param_1,int param_2,float param_3,float *param_4,int param_5,
          int param_6,int param_7)
{
  XYPoint XVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *pRVar5;
  RGE_Static_Object *pRVar6;
  RGE_Zone_Map *this_00;
  long lVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  RGE_Moving_Object *pRVar15;
  float fVar16;
  int iVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  XYPoint start;
  RGE_Zone_Map *zoneMap;
  XYPoint goal;
  
  pRVar5 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  pRVar6 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_2);
  if ((pRVar5 != (RGE_Static_Object *)0x0) && (pRVar6 != (RGE_Static_Object *)0x0)) {
    if (this->_padding_ == -1) {
      iVar9 = *(int *)(this->_padding_ + 0x3c);
      RGE_Zone_Map_List::get_zone_map
                (*(RGE_Zone_Map_List **)(*(int *)(iVar9 + 0x28) + 0x8dc4),
                 *(float **)(*(int *)(iVar9 + 0x54) + *(short *)(this->_padding_ + 0x66) * 4),
                 (int)*(short *)(iVar9 + 0x52),&this->_padding_);
    }
    this_00 = RGE_Zone_Map_List::get_zone_map
                        (*(RGE_Zone_Map_List **)
                          (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28) + 0x8dc4),
                         this->_padding_);
    if (this_00 != (RGE_Zone_Map *)0x0) {
      lVar7 = __ftol();
      lVar8 = __ftol();
      uVar3 = RGE_Zone_Map::get_zone_info(this_00,lVar8,lVar7);
      lVar7 = __ftol();
      lVar8 = __ftol();
      uVar4 = RGE_Zone_Map::get_zone_info(this_00,lVar8,lVar7);
      if (uVar4 != uVar3) {
        iVar9 = __ftol();
        iVar10 = __ftol();
        iVar11 = __ftol();
        iVar12 = __ftol();
        XVar1.y = iVar10;
        XVar1.x = iVar9;
        XVar2.y = iVar12;
        XVar2.x = iVar11;
        iVar9 = RGE_Zone_Map::withinRange(this_00,XVar1,XVar2,param_3);
        if (iVar9 == 0) {
          return 0;
        }
      }
      this->storePathInExceptionPath = '\x01';
      if (param_5 != 0) {
        PathingSystem::incrementCanPaths(&aiPathSystem);
        iVar22 = 1;
        iVar21 = 1;
        iVar20 = 1;
        iVar19 = 1;
        iVar17 = 1;
        pRVar15 = this;
        fVar16 = param_3;
        pfVar18 = param_4;
        iVar9 = param_6;
        iVar10 = param_7;
        iVar11 = __ftol();
        iVar12 = __ftol();
        iVar13 = __ftol();
        iVar14 = __ftol();
        iVar9 = PathingSystem::findTilePath
                          (&aiPathSystem,iVar14,iVar13,iVar12,iVar11,pRVar15,fVar16,param_1,iVar17,
                           pfVar18,iVar19,iVar20,iVar21,iVar22,iVar9,iVar10);
        if (iVar9 != 0) {
          iVar20 = 1;
          iVar19 = 1;
          iVar17 = 1;
          iVar14 = 1;
          iVar13 = 0;
          pRVar15 = this;
          iVar9 = __ftol();
          iVar10 = __ftol();
          Path::lastWaypoint(&this->exceptionPathValue);
          iVar11 = __ftol();
          Path::lastWaypoint(&this->exceptionPathValue);
          iVar12 = __ftol();
          iVar9 = PathingSystem::findTilePath
                            (&aiPathSystem,iVar12,iVar11,iVar10,iVar9,pRVar15,param_3,param_2,iVar13
                             ,param_4,iVar14,iVar17,iVar19,iVar20,param_6,param_7);
          this->storePathInExceptionPath = '\0';
          return iVar9;
        }
        this->storePathInExceptionPath = '\0';
        return 0;
      }
      PathingSystem::incrementCanPaths(&pathSystem);
      iVar22 = 1;
      iVar21 = 1;
      iVar20 = 1;
      iVar19 = 1;
      iVar17 = 1;
      pRVar15 = this;
      fVar16 = param_3;
      pfVar18 = param_4;
      iVar9 = param_6;
      iVar10 = param_7;
      iVar11 = __ftol();
      iVar12 = __ftol();
      iVar13 = __ftol();
      iVar14 = __ftol();
      iVar9 = PathingSystem::findTilePath
                        (&pathSystem,iVar14,iVar13,iVar12,iVar11,pRVar15,fVar16,param_1,iVar17,
                         pfVar18,iVar19,iVar20,iVar21,iVar22,iVar9,iVar10);
      if (iVar9 != 0) {
        iVar20 = 1;
        iVar19 = 1;
        iVar17 = 1;
        iVar14 = 1;
        iVar13 = 0;
        pRVar15 = this;
        iVar9 = __ftol();
        iVar10 = __ftol();
        Path::lastWaypoint(&this->exceptionPathValue);
        iVar11 = __ftol();
        Path::lastWaypoint(&this->exceptionPathValue);
        iVar12 = __ftol();
        iVar9 = PathingSystem::findTilePath
                          (&pathSystem,iVar12,iVar11,iVar10,iVar9,pRVar15,param_3,param_2,iVar13,
                           param_4,iVar14,iVar17,iVar19,iVar20,param_6,param_7);
        this->storePathInExceptionPath = '\0';
        return iVar9;
      }
      this->storePathInExceptionPath = '\0';
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: canPathWithObstructions
// Address: 0045fed0
/* WARNING: Variable defined which should be unmapped: start */
/* public: virtual int __thiscall RGE_Moving_Object::canPathWithObstructions(int,float,float
   *,int,int,int,class ManagedArray<int> &) */

int __thiscall
RGE_Moving_Object::canPathWithObstructions
          (RGE_Moving_Object *this,int param_1,float param_2,float *param_3,int param_4,int param_5,
          int param_6,ManagedArray<int> *param_7)
{
  XYPoint XVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *pRVar5;
  RGE_Zone_Map *this_00;
  long lVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  PathingSystem *this_01;
  RGE_Moving_Object *pRVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  XYPoint start;
  XYPoint goal;
  
  pRVar5 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  if (pRVar5 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  if (this->_padding_ == -1) {
    iVar8 = *(int *)(this->_padding_ + 0x3c);
    RGE_Zone_Map_List::get_zone_map
              (*(RGE_Zone_Map_List **)(*(int *)(iVar8 + 0x28) + 0x8dc4),
               *(float **)(*(int *)(iVar8 + 0x54) + *(short *)(this->_padding_ + 0x66) * 4),
               (int)*(short *)(iVar8 + 0x52),&this->_padding_);
  }
  this_00 = RGE_Zone_Map_List::get_zone_map
                      (*(RGE_Zone_Map_List **)
                        (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28) + 0x8dc4),this->_padding_
                      );
  if (this_00 == (RGE_Zone_Map *)0x0) {
    return 0;
  }
  lVar6 = __ftol();
  lVar7 = __ftol();
  uVar3 = RGE_Zone_Map::get_zone_info(this_00,lVar7,lVar6);
  lVar6 = __ftol();
  lVar7 = __ftol();
  uVar4 = RGE_Zone_Map::get_zone_info(this_00,lVar7,lVar6);
  if (uVar4 != uVar3) {
    iVar8 = __ftol();
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    XVar1.y = iVar9;
    XVar1.x = iVar8;
    XVar2.y = iVar11;
    XVar2.x = iVar10;
    iVar8 = RGE_Zone_Map::withinRange(this_00,XVar1,XVar2,param_2);
    if (iVar8 == 0) {
      return 0;
    }
  }
  this->storePathInExceptionPath = '\x01';
  if (param_4 == 0) {
    PathingSystem::incrementCanPaths(&pathSystem);
    iVar18 = 1;
    iVar17 = 1;
    iVar16 = 1;
    iVar15 = 1;
    iVar14 = 1;
    pRVar13 = this;
    iVar8 = param_6;
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    iVar12 = __ftol();
    iVar8 = PathingSystem::findTilePath
                      (&pathSystem,iVar12,iVar11,iVar10,iVar9,pRVar13,param_2,param_1,iVar14,param_3
                       ,iVar15,iVar16,iVar17,iVar18,param_5,iVar8);
    if (param_6 == -1) goto LAB_004600d3;
    this_01 = &pathSystem;
  }
  else {
    PathingSystem::incrementCanPaths(&aiPathSystem);
    iVar18 = 1;
    iVar17 = 1;
    iVar16 = 1;
    iVar15 = 1;
    iVar14 = 1;
    pRVar13 = this;
    iVar8 = param_6;
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    iVar12 = __ftol();
    iVar8 = PathingSystem::findTilePath
                      (&aiPathSystem,iVar12,iVar11,iVar10,iVar9,pRVar13,param_2,param_1,iVar14,
                       param_3,iVar15,iVar16,iVar17,iVar18,param_5,iVar8);
    if (param_6 == -1) goto LAB_004600d3;
    this_01 = &aiPathSystem;
  }
  PathingSystem::copyUnobstructibles(this_01,param_7);
LAB_004600d3:
  this->storePathInExceptionPath = '\0';
  return iVar8;
}

// --------------------------------------------------

// Function: canPathWithAdditionalPassability
// Address: 004600f0
/* public: virtual int __thiscall RGE_Moving_Object::canPathWithAdditionalPassability(struct
   XYZPoint,float,int,float *,int,int,int,int,int) */

int __thiscall
RGE_Moving_Object::canPathWithAdditionalPassability
          (RGE_Moving_Object *this,XYZPoint param_1,float param_2,int param_3,float *param_4,
          int param_5,int param_6,int param_7,int param_8,int param_9)
{
  int iVar1;
  int iVar2;
  PathingSystem *this_00;
  RGE_Moving_Object *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((((-1 < param_1.x) && (-1 < param_1.y)) &&
      (iVar1 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28), param_1.x < *(int *)(iVar1 + 8)))
     && (param_1.y < *(int *)(iVar1 + 0xc))) {
    this->currentTerrainException2 = param_6;
    this->currentTerrainException1 = param_5;
    this->storePathInExceptionPath = '\x01';
    pRVar3 = this;
    if (param_7 == 0) {
      PathingSystem::incrementCanPaths(&pathSystem);
      iVar8 = 1;
      iVar7 = 1;
      iVar6 = 1;
      iVar5 = 1;
      iVar4 = 1;
      iVar1 = __ftol();
      iVar2 = __ftol();
      this_00 = &pathSystem;
    }
    else {
      PathingSystem::incrementCanPaths(&aiPathSystem);
      iVar8 = 1;
      iVar7 = 1;
      iVar6 = 1;
      iVar5 = 1;
      iVar4 = 1;
      iVar1 = __ftol();
      iVar2 = __ftol();
      this_00 = &aiPathSystem;
    }
    iVar1 = PathingSystem::findTilePath
                      (this_00,iVar2,iVar1,param_1.x,param_1.y,pRVar3,param_2,param_3,iVar4,param_4,
                       iVar5,iVar6,iVar7,iVar8,param_8,param_9);
    this->storePathInExceptionPath = '\0';
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: findFirstTerrainAlongExceptionPath
// Address: 00460210
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall RGE_Moving_Object::findFirstTerrainAlongExceptionPath(int,float
   *,float *) */

int __thiscall
RGE_Moving_Object::findFirstTerrainAlongExceptionPath
          (RGE_Moving_Object *this,int param_1,float *param_2,float *param_3)
{
  Path *this_00;
  code *pcVar1;
  float fVar2;
  int iVar3;
  Waypoint *pWVar4;
  int i;
  XYPoint p1;
  XYPoint p2;
  XYPoint rVal;
  
  this_00 = &this->exceptionPathValue;
  iVar3 = Path::numberOfWaypoints(this_00);
  if (1 < iVar3) {
    Path::initToStart(this_00);
    pWVar4 = Path::currentWaypoint(this_00);
    if (pWVar4 != (Waypoint *)0x0) {
      Path::currentWaypoint(this_00);
      p1.y = __ftol();
      Path::currentWaypoint(this_00);
      p2.x = __ftol();
      Path::moveToNextWaypoint(this_00);
      pWVar4 = Path::currentWaypoint(this_00);
      if (pWVar4 != (Waypoint *)0x0) {
        Path::currentWaypoint(this_00);
        p2.y = __ftol();
        Path::currentWaypoint(this_00);
        rVal.x = __ftol();
        p1.x = 1;
        iVar3 = Path::numberOfWaypoints(this_00);
        if (1 < iVar3) {
          pcVar1 = *(code **)(this->_padding_ + 0x1b4);
          do {
            iVar3 = (*pcVar1)(&p1.y,&p2.y,&rVal.y,param_1,param_1,1);
            if (iVar3 == 1) {
              fVar2 = (float)rVal.y - _DAT_00570b80;
              *param_2 = fVar2;
              *param_3 = fVar2;
              return 1;
            }
            Path::currentWaypoint(this_00);
            p1.y = __ftol();
            Path::currentWaypoint(this_00);
            p2.x = __ftol();
            Path::moveToNextWaypoint(this_00);
            pWVar4 = Path::currentWaypoint(this_00);
            if (pWVar4 == (Waypoint *)0x0) {
              return 0;
            }
            Path::currentWaypoint(this_00);
            p2.y = __ftol();
            Path::currentWaypoint(this_00);
            rVal.x = __ftol();
            p1.x = p1.x + 1;
            iVar3 = Path::numberOfWaypoints(this_00);
          } while (p1.x < iVar3);
        }
        *param_2 = -1.0;
        *param_3 = -1.0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: canLinePath
// Address: 004603b0
/* WARNING: Variable defined which should be unmapped: yTile */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall RGE_Moving_Object::canLinePath(struct XYPoint const &,struct
   XYPoint const &,float,struct XYPoint &,int) */

int __thiscall
RGE_Moving_Object::canLinePath
          (RGE_Moving_Object *this,XYPoint *param_1,XYPoint *param_2,float param_3,XYPoint *param_4,
          int param_5)
{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar8;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar9;
  float yTile;
  int numSteps;
  int priorY;
  int local_14;
  int i;
  float xStep;
  float yStep;
  
  iVar5 = param_1->x;
  iVar6 = param_1->y;
  fVar1 = (float)(param_2->x - iVar5);
  fVar2 = (float)(param_2->y - iVar6);
  if ((fVar1 == _DAT_00570b48) && (fVar2 == _DAT_00570b48)) {
    return 0;
  }
  if (ABS(fVar2) <= ABS(fVar1)) {
    uVar3 = __ftol();
    iVar4 = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
    fVar8 = extraout_ST0_00;
    fVar9 = extraout_ST1_00;
  }
  else {
    uVar3 = __ftol();
    iVar4 = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
    fVar8 = extraout_ST0;
    fVar9 = extraout_ST1;
  }
  iVar4 = iVar4 * 2;
  iVar7 = -999;
  xStep = 0.0;
  local_14 = -999;
  param_1 = (XYPoint *)(float)iVar5;
  numSteps = (int)(float)iVar6;
  if (iVar4 < 1) {
    return 1;
  }
  do {
    param_1 = (XYPoint *)((float)param_1 + (float)(fVar9 / (float10)iVar4));
    numSteps = (int)((float)numSteps + (float)(fVar8 / (float10)iVar4));
    iVar5 = __ftol();
    iVar6 = __ftol();
    if ((iVar5 != iVar7) || (iVar6 != local_14)) {
      iVar7 = (**(code **)(this->_padding_ + 0x114))(param_1,numSteps,param_5);
      if (iVar7 == 0) {
        param_4->x = iVar5;
        param_4->y = iVar6;
        return 0;
      }
      fVar1 = (float)param_2->x - (float)param_1;
      fVar2 = (float)param_2->y - (float)numSteps;
      iVar7 = iVar5;
      local_14 = iVar6;
      if (SQRT(fVar2 * fVar2 + fVar1 * fVar1) <= param_3) {
        return 1;
      }
    }
    xStep = (float)((int)xStep + 1);
    if (iVar4 <= (int)xStep) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: canLinePath
// Address: 00460570
/* WARNING: Variable defined which should be unmapped: numSteps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall RGE_Moving_Object::canLinePath(int,int,int,int,float,int) */

int __thiscall
RGE_Moving_Object::canLinePath
          (RGE_Moving_Object *this,int param_1,int param_2,int param_3,int param_4,float param_5,
          int param_6)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar7;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar8;
  int numSteps;
  int i;
  float xStep;
  float yStep;
  
  if (((float)(param_3 - param_1) == _DAT_00570b48) && ((float)(param_4 - param_2) == _DAT_00570b48)
     ) {
    return 0;
  }
  if (ABS((float)(param_4 - param_2)) <= ABS((float)(param_3 - param_1))) {
    uVar1 = __ftol();
    iVar2 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
    fVar7 = extraout_ST0_00;
    fVar8 = extraout_ST1_00;
  }
  else {
    uVar1 = __ftol();
    iVar2 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
    fVar7 = extraout_ST0;
    fVar8 = extraout_ST1;
  }
  iVar2 = iVar2 * 2;
  iVar6 = -999;
  xStep = 0.0;
  iVar5 = -999;
  param_1 = (int)(float)param_1;
  param_2 = (int)(float)param_2;
  if (iVar2 < 1) {
    return 1;
  }
  do {
    param_1 = (int)((float)param_1 + (float)(fVar8 / (float10)iVar2));
    param_2 = (int)((float)param_2 + (float)(fVar7 / (float10)iVar2));
    iVar3 = __ftol();
    iVar4 = __ftol();
    if ((iVar3 != iVar6) || (iVar4 != iVar5)) {
      iVar5 = (**(code **)(this->_padding_ + 0x114))(param_1,param_2,param_6);
      if (iVar5 == 0) {
        return 0;
      }
      iVar5 = iVar4;
      iVar6 = iVar3;
      if (SQRT(((float)param_4 - (float)param_2) * ((float)param_4 - (float)param_2) +
               ((float)param_3 - (float)param_1) * ((float)param_3 - (float)param_1)) <= param_5) {
        return 1;
      }
    }
    xStep = (float)((int)xStep + 1);
    if (iVar2 <= (int)xStep) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: firstTileAlongLine
// Address: 00460710
/* WARNING: Variable defined which should be unmapped: numSteps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall RGE_Moving_Object::firstTileAlongLine(struct XYPoint const
   &,struct XYPoint const &,struct XYPoint &,int,int,int) */

int __thiscall
RGE_Moving_Object::firstTileAlongLine
          (RGE_Moving_Object *this,XYPoint *param_1,XYPoint *param_2,XYPoint *param_3,int param_4,
          int param_5,int param_6)
{
  RGE_Map *this_00;
  float fVar1;
  float fVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar11;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar12;
  int numSteps;
  int i;
  float xStep;
  float yStep;
  RGE_Map *map;
  uchar tileType;
  
  iVar6 = param_1->x;
  iVar7 = param_1->y;
  fVar1 = (float)(param_2->x - iVar6);
  fVar2 = (float)(param_2->y - iVar7);
  if ((fVar1 == _DAT_00570b48) && (fVar2 == _DAT_00570b48)) {
    return 0;
  }
  if (ABS(fVar2) <= ABS(fVar1)) {
    uVar4 = __ftol();
    iVar5 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
    fVar11 = extraout_ST0_00;
    fVar12 = extraout_ST1_00;
  }
  else {
    uVar4 = __ftol();
    iVar5 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
    fVar11 = extraout_ST0;
    fVar12 = extraout_ST1;
  }
  iVar5 = iVar5 * 2;
  iVar9 = -999;
  iVar10 = -999;
  xStep = 0.0;
  this_00 = *(RGE_Map **)(*(int *)(this->_padding_ + 0x3c) + 0x28);
  param_2 = (XYPoint *)(float)iVar6;
  param_1 = (XYPoint *)(float)iVar7;
  if (0 < iVar5) {
    do {
      param_2 = (XYPoint *)((float)param_2 + (float)(fVar12 / (float10)iVar5));
      param_1 = (XYPoint *)((float)param_1 + (float)(fVar11 / (float10)iVar5));
      iVar6 = __ftol();
      iVar7 = __ftol();
      if ((iVar6 != iVar9) || (iVar7 != iVar10)) {
        bVar3 = RGE_Map::get_terrain(this_00,(short)iVar6,(short)iVar7);
        iVar9 = iVar6;
        iVar10 = iVar7;
        if ((((uint)bVar3 == param_4) || ((uint)bVar3 == param_5)) && (param_6 == 1)) {
          iVar8 = (**(code **)(this->_padding_ + 0x114))(param_2,param_1,0);
          if (iVar8 == 1) {
            param_3->x = iVar6;
            param_3->y = iVar7;
            return 1;
          }
        }
      }
      xStep = (float)((int)xStep + 1);
    } while ((int)xStep < iVar5);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: maximumSpeed
// Address: 004608d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall RGE_Moving_Object::maximumSpeed(void) */

float __thiscall RGE_Moving_Object::maximumSpeed(RGE_Moving_Object *this)
{
  int iVar1;
  
  iVar1 = this->_padding_;
  if ((iVar1 != 0) && ((float)_DAT_00570b98 < *(float *)(iVar1 + 100))) {
    return *(float *)(this->_padding_ + 0xb8) * *(float *)(iVar1 + 100);
  }
  return *(float *)(this->_padding_ + 0xb8);
}

// --------------------------------------------------

// Function: waitingToMove
// Address: 00460900
/* public: virtual unsigned char __thiscall RGE_Moving_Object::waitingToMove(void)const  */

uchar __thiscall RGE_Moving_Object::waitingToMove(RGE_Moving_Object *this)
{
  char cVar1;
  
  cVar1 = (**(code **)(this->_padding_ + 0x134))();
  if ((cVar1 != '\x06') && (cVar1 != '\a')) {
    return this->waitingToMoveValue;
  }
  return '\0';
}

// --------------------------------------------------

// Function: setWaitingToMove
// Address: 00460930
/* public: virtual void __thiscall RGE_Moving_Object::setWaitingToMove(unsigned char) */

void __thiscall RGE_Moving_Object::setWaitingToMove(RGE_Moving_Object *this,uchar param_1)
{
  this->waitingToMoveValue = param_1;
  return;
}

// --------------------------------------------------

// Function: userDefinedWaypoint
// Address: 00460940
/* public: virtual struct XYZBYTEPoint * __thiscall RGE_Moving_Object::userDefinedWaypoint(int) */

XYZBYTEPoint * __thiscall
RGE_Moving_Object::userDefinedWaypoint(RGE_Moving_Object *this,int param_1)
{
  if ((-1 < param_1) && (param_1 < this->numberUserDefinedWaypointsValue)) {
    return this->userDefinedWaypoints + param_1;
  }
  return (XYZBYTEPoint *)0x0;
}

// --------------------------------------------------

// Function: addUserDefinedWaypoint
// Address: 00460970
/* public: virtual int __thiscall RGE_Moving_Object::addUserDefinedWaypoint(struct XYZBYTEPoint
   *,int) */

int __thiscall
RGE_Moving_Object::addUserDefinedWaypoint(RGE_Moving_Object *this,XYZBYTEPoint *param_1,int param_2)
{
  XYZBYTEPoint *pXVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  
  if (this->finalUserDefinedWaypoint == '\x01') {
    (**(code **)(this->_padding_ + 0x1c0))(param_2);
    this->finalUserDefinedWaypoint = '\0';
  }
  iVar2 = this->maxUserDefinedWaypointsValue;
  if (this->numberUserDefinedWaypointsValue < iVar2) {
    this->userDefinedWaypoints[this->numberUserDefinedWaypointsValue].x = param_1->x;
    this->userDefinedWaypoints[this->numberUserDefinedWaypointsValue].y = param_1->y;
    this->userDefinedWaypoints[this->numberUserDefinedWaypointsValue].z = param_1->z;
  }
  else {
    if (iVar2 == 0) {
      pXVar1 = (XYZBYTEPoint *)operator_new(0xf);
      this->userDefinedWaypoints = pXVar1;
      this->maxUserDefinedWaypointsValue = 5;
      this->numberUserDefinedWaypointsValue = 0;
    }
    else {
      pXVar1 = (XYZBYTEPoint *)operator_new(iVar2 * 6);
      if (pXVar1 == (XYZBYTEPoint *)0x0) {
        return 0;
      }
      iVar2 = 0;
      if (0 < this->numberUserDefinedWaypointsValue) {
        iVar3 = 0;
        puVar4 = &pXVar1->z;
        do {
          iVar2 = iVar2 + 1;
          ((XYZBYTEPoint *)(puVar4 + -2))->x = (&this->userDefinedWaypoints->x)[iVar3];
          puVar4[-1] = (&this->userDefinedWaypoints->y)[iVar3];
          *puVar4 = (&this->userDefinedWaypoints->z)[iVar3];
          iVar3 = iVar3 + 3;
          puVar4 = puVar4 + 3;
        } while (iVar2 < this->numberUserDefinedWaypointsValue);
      }
      iVar3 = this->maxUserDefinedWaypointsValue * 2;
      this->maxUserDefinedWaypointsValue = iVar3;
      if (iVar2 < iVar3) {
        puVar4 = &pXVar1[iVar2].z;
        do {
          ((XYZBYTEPoint *)(puVar4 + -2))->x = '\0';
          puVar4[-1] = '\0';
          *puVar4 = '\0';
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 3;
        } while (iVar2 < this->maxUserDefinedWaypointsValue);
      }
      operator_delete(this->userDefinedWaypoints);
      this->userDefinedWaypoints = pXVar1;
    }
    this->userDefinedWaypoints[this->numberUserDefinedWaypointsValue].x = param_1->x;
    this->userDefinedWaypoints[this->numberUserDefinedWaypointsValue].y = param_1->y;
    this->userDefinedWaypoints[this->numberUserDefinedWaypointsValue].z = param_1->z;
  }
  this->numberUserDefinedWaypointsValue = this->numberUserDefinedWaypointsValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: removeAllUserDefinedWaypoints
// Address: 00460b20
// [HELPER] s_C__msdev_work_age1_x1_move_obj_c: "C:\msdev\work\age1_x1\move_obj.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* public: virtual void __thiscall RGE_Moving_Object::removeAllUserDefinedWaypoints(int) */

void __thiscall
RGE_Moving_Object::removeAllUserDefinedWaypoints(RGE_Moving_Object *this,int param_1)
{
  this->numberUserDefinedWaypointsValue = 0;
  if ((param_1 == 1) && (this->_padding_ != 0)) {
    if (actionFile != (_iobuf *)0x0) {
      fprintf(actionFile,s___d_call_stopObject__s__d_,this->_padding_,
              s_C__msdev_work_age1_x1_move_obj_c,0xb59);
    }
    (**(code **)(*(int *)this->_padding_ + 0x58))(0);
  }
  return;
}

// --------------------------------------------------

// Function: removeUserDefinedWaypoint
// Address: 00460b70
/* public: virtual void __thiscall RGE_Moving_Object::removeUserDefinedWaypoint(int) */

void __thiscall RGE_Moving_Object::removeUserDefinedWaypoint(RGE_Moving_Object *this,int param_1)
{
  int iVar1;
  int iVar2;
  
  if ((-1 < param_1) && (iVar1 = this->numberUserDefinedWaypointsValue, param_1 < iVar1)) {
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (param_1 <= iVar2) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    if (iVar2 < iVar1) {
      iVar1 = iVar2 * 3;
      do {
        if (iVar1 != 0) {
          (&this->userDefinedWaypoints[-1].x)[iVar1] = (&this->userDefinedWaypoints->x)[iVar1];
          *(uchar *)((int)this->userDefinedWaypoints + iVar1 + -2) =
               (&this->userDefinedWaypoints->y)[iVar1];
          *(uchar *)((int)this->userDefinedWaypoints + iVar1 + -1) =
               (&this->userDefinedWaypoints->z)[iVar1];
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 3;
      } while (iVar2 < this->numberUserDefinedWaypointsValue);
    }
    this->numberUserDefinedWaypointsValue = this->numberUserDefinedWaypointsValue + -1;
  }
  return;
}

// --------------------------------------------------

// Function: setFinalUserDefinedWaypoint
// Address: 00460bf0
/* public: void __thiscall RGE_Moving_Object::setFinalUserDefinedWaypoint(void) */

void __thiscall RGE_Moving_Object::setFinalUserDefinedWaypoint(RGE_Moving_Object *this)
{
  this->finalUserDefinedWaypoint = '\x01';
  return;
}

// --------------------------------------------------

// Function: findAvoidancePath
// Address: 00460c00
/* public: virtual class Path * __thiscall RGE_Moving_Object::findAvoidancePath(struct XYZPoint
   &,float,int) */

Path * __thiscall
RGE_Moving_Object::findAvoidancePath
          (RGE_Moving_Object *this,XYZPoint *param_1,float param_2,int param_3)
{
  XYPoint XVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Zone_Map *this_00;
  long lVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  RGE_Moving_Object *pRVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  
  if (this->_padding_ == -1) {
    iVar7 = *(int *)(this->_padding_ + 0x3c);
    RGE_Zone_Map_List::get_zone_map
              (*(RGE_Zone_Map_List **)(*(int *)(iVar7 + 0x28) + 0x8dc4),
               *(float **)(*(int *)(iVar7 + 0x54) + *(short *)(this->_padding_ + 0x66) * 4),
               (int)*(short *)(iVar7 + 0x52),&this->_padding_);
  }
  this_00 = RGE_Zone_Map_List::get_zone_map
                      (*(RGE_Zone_Map_List **)
                        (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28) + 0x8dc4),this->_padding_
                      );
  lVar5 = __ftol();
  lVar6 = __ftol();
  uVar3 = RGE_Zone_Map::get_zone_info(this_00,lVar6,lVar5);
  uVar4 = RGE_Zone_Map::get_zone_info(this_00,param_1->x,param_1->y);
  if (uVar4 != uVar3) {
    iVar7 = __ftol();
    iVar8 = __ftol();
    XVar2.x = param_1->x;
    XVar2.y = param_1->y;
    XVar1.y = iVar8;
    XVar1.x = iVar7;
    iVar7 = RGE_Zone_Map::withinRange(this_00,XVar1,XVar2,param_2);
    if (iVar7 == 0) {
      return (Path *)0x0;
    }
  }
  iVar19 = -1;
  iVar18 = -1;
  iVar17 = 1;
  iVar16 = 1;
  iVar15 = 1;
  iVar14 = 0;
  pfVar13 = (float *)0x0;
  iVar12 = 1;
  this->storePathInExceptionPath = '\x01';
  iVar7 = param_1->y;
  iVar8 = param_1->x;
  pRVar11 = this;
  iVar9 = __ftol();
  iVar10 = __ftol();
  PathingSystem::findTilePath
            (&aiPathSystem,iVar10,iVar9,iVar8,iVar7,pRVar11,param_2,param_3,iVar12,pfVar13,iVar14,
             iVar15,iVar16,iVar17,iVar18,iVar19);
  this->storePathInExceptionPath = '\0';
  PathingSystem::initMisc(&aiPathSystem,'\0');
  return &this->exceptionPathValue;
}

// --------------------------------------------------

// Function: setInitialPoints
// Address: 00460d30
/* public: void __thiscall RGE_Moving_Object::setInitialPoints(struct XYPoint &,struct XYPoint &) */

void __thiscall
RGE_Moving_Object::setInitialPoints(RGE_Moving_Object *this,XYPoint *param_1,XYPoint *param_2)
{
  (this->minInitialPointValue).x = param_1->x;
  (this->minInitialPointValue).y = param_1->y;
  (this->maxInitialPointValue).x = param_2->x;
  (this->maxInitialPointValue).y = param_2->y;
  return;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 00460d60
/* public: virtual void __thiscall RGE_Moving_Object::copy_obj(class RGE_Master_Static_Object *) */

void __thiscall
RGE_Moving_Object::copy_obj(RGE_Moving_Object *this,RGE_Master_Static_Object *param_1)
{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if (this->_padding_ == *(int *)(this->_padding_ + 0xbc)) {
    pcVar1 = *(char **)&param_1[1].master_type;
  }
  else if (this->_padding_ == *(int *)(this->_padding_ + 0xc0)) {
    pcVar1 = param_1[1].name;
  }
  if (pcVar1 != (char *)0x0) {
    (**(code **)(this->_padding_ + 0x38))(pcVar1);
  }
  RGE_Static_Object::copy_obj((RGE_Static_Object *)this,param_1);
  return;
}

// --------------------------------------------------

// Function: boundAngle
// Address: 00460db0
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall RGE_Moving_Object::boundAngle(float *,int) */

void __thiscall RGE_Moving_Object::boundAngle(RGE_Moving_Object *this,float *param_1,int param_2)
{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int i;
  int local_4;
  
  iVar5 = param_2;
  pfVar4 = param_1;
  fVar1 = *param_1;
  if (_DAT_00570b48 <= *param_1) {
    if (_DAT_00570b50 < fVar1) {
      do {
        fVar3 = _DAT_00570b50;
        fVar1 = *param_1 - _DAT_00570b50;
        *param_1 = fVar1;
      } while (fVar3 < fVar1);
    }
  }
  else {
    do {
      fVar1 = fVar1 - _DAT_00570b4c;
    } while (fVar1 < _DAT_00570b48);
    *param_1 = fVar1;
  }
  if (param_2 != -1) {
    param_1 = (float *)0x3f490fdb;
    if (param_2 != 8) {
      param_1 = (float *)0x3ec90fdb;
    }
    param_2 = -1;
    local_4 = 0;
    if (-1 < iVar5) {
      do {
        pfVar2 = (float *)(*pfVar4 - (float)local_4 * (float)param_1);
        if ((float)pfVar2 < (float)_DAT_00570b98) {
          pfVar2 = (float *)-(float)pfVar2;
        }
        if ((float)pfVar2 < (float)param_1) {
          param_1 = pfVar2;
          param_2 = local_4;
        }
      } while (((float)_DAT_00570c00 <= (float)param_1) && (local_4 = local_4 + 1, local_4 <= iVar5)
              );
    }
    if (iVar5 == 8) {
      *pfVar4 = (float)param_2 * _DAT_00570b88;
      return;
    }
    *pfVar4 = (float)param_2 * _DAT_00570bfc;
  }
  return;
}

// --------------------------------------------------

// Function: rotate
// Address: 00460eb0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall RGE_Moving_Object::rotate(long) */

void __thiscall RGE_Moving_Object::rotate(RGE_Moving_Object *this,long param_1)
{
  float fVar1;
  
  for (fVar1 = ((float)param_1 * (float)_DAT_00570b40) /
               (float)(int)*(short *)(this->_padding_ + 0x60) + this->angle; fVar1 < _DAT_00570b48;
      fVar1 = fVar1 - _DAT_00570b4c) {
  }
  if ((float)_DAT_00570b40 <= fVar1) {
    do {
      fVar1 = fVar1 - _DAT_00570b50;
    } while ((float)_DAT_00570b40 <= fVar1);
    (**(code **)(this->_padding_ + 0xb4))(fVar1);
    return;
  }
  (**(code **)(this->_padding_ + 0xb4))(fVar1);
  return;
}

// --------------------------------------------------

// Function: get_waypoint_checksum
// Address: 00460f40
/* WARNING: Variable defined which should be unmapped: temp */
/* public: virtual long __thiscall RGE_Moving_Object::get_waypoint_checksum(void) */

long __thiscall RGE_Moving_Object::get_waypoint_checksum(RGE_Moving_Object *this)
{
  Path *this_00;
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  float temp;
  
  this_00 = &this->pathValue;
  iVar1 = Path::currentWaypointNumber(this_00);
  Path::initToStart(this_00);
  iVar4 = 0;
  iVar2 = Path::numberOfWaypoints(this_00);
  if (0 < iVar2) {
    do {
      Path::currentWaypoint(this_00);
      Path::currentWaypoint(this_00);
      iVar4 = iVar4 + 1;
      Path::moveToNextWaypoint(this_00);
      iVar2 = Path::numberOfWaypoints(this_00);
    } while (iVar4 < iVar2);
  }
  Path::setCurrentWaypointNumber(this_00,iVar1);
  lVar3 = __ftol();
  return lVar3;
}

// --------------------------------------------------

