// Class: RGE_Action_Move_To
// Size:  0x44
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] setup
// [02] setup
// [03] create_action_list
// [04] rehook
// [05] save
// [06] type
// [07] first_in_stack
// [08] inside_obj_update
// [09] idle_update
// [10] update
// [11] stop
// [12] move_to
// [13] work
// [14] attack_response
// [15] relation_response
// [16] copy_obj
// [17] copy_obj_sprites
// [18] get_state_name
// [19] get_target_obj
// [20] get_target_obj2
// [21] set_target_obj
// [22] set_target_obj2
// [23] set_state
//
// Member Layout:
// [0x040] float range
// ----------------------------------------------------------------

// Function: RGE_Action_Move_To
// Address: 00405510
/* public: __thiscall RGE_Action_Move_To::RGE_Action_Move_To(int,class RGE_Action_Object *) */

RGE_Action_Move_To * __thiscall
RGE_Action_Move_To::RGE_Action_Move_To
          (RGE_Action_Move_To *this,int param_1,RGE_Action_Object *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c308;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 1;
  rge_read(param_1,&this->range,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00405580
/* public: virtual void * __thiscall RGE_Action_Move_To::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
RGE_Action_Move_To::_scalar_deleting_destructor_(RGE_Action_Move_To *this,uint param_1)
{
  ~RGE_Action_Move_To(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Action_Move_To
// Address: 004055a0
/* public: __thiscall RGE_Action_Move_To::RGE_Action_Move_To(class RGE_Action_Object
   *,float,float,float,float,class RGE_Sprite *) */

RGE_Action_Move_To * __thiscall
RGE_Action_Move_To::RGE_Action_Move_To
          (RGE_Action_Move_To *this,RGE_Action_Object *param_1,float param_2,float param_3,
          float param_4,float param_5,RGE_Sprite *param_6)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  uVar3 = DAT_0056e400._0_4_;
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)param_4;
  this->range = param_5;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 1;
  this->_padding_ = (int)param_3;
  this->_padding_ = (int)param_6;
  if (param_5 <= (float)uVar3) {
    this->range = 0.4;
  }
  if (param_6 == (RGE_Sprite *)0x0) {
    iVar1 = *(int *)(this->_padding_ + 8);
    iVar2 = *(int *)(iVar1 + 0xbc);
    if (iVar2 == 0) {
      this->_padding_ = *(int *)(iVar1 + 0x18);
      return this;
    }
    this->_padding_ = iVar2;
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Action_Move_To
// Address: 00405620
/* public: __thiscall RGE_Action_Move_To::RGE_Action_Move_To(class RGE_Action_Object *,class
   RGE_Static_Object *,float,class RGE_Sprite *) */

RGE_Action_Move_To * __thiscall
RGE_Action_Move_To::RGE_Action_Move_To
          (RGE_Action_Move_To *this,RGE_Action_Object *param_1,RGE_Static_Object *param_2,
          float param_3,RGE_Sprite *param_4)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c328;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 1;
  RGE_Action::set_target_obj((RGE_Action *)this,param_2);
  if (param_2 != (RGE_Static_Object *)0x0) {
    this->_padding_ = (int)param_2->world_x;
    this->_padding_ = (int)param_2->world_y;
    this->_padding_ = (int)param_2->world_z;
  }
  uVar3 = DAT_0056e400._0_4_;
  this->range = param_3;
  this->_padding_ = (int)param_4;
  if (param_3 <= (float)uVar3) {
    this->range = 0.4;
  }
  if (param_4 == (RGE_Sprite *)0x0) {
    iVar1 = *(int *)(this->_padding_ + 8);
    iVar2 = *(int *)(iVar1 + 0xbc);
    if (iVar2 == 0) {
      this->_padding_ = *(int *)(iVar1 + 0x18);
    }
    else {
      this->_padding_ = iVar2;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Move_To
// Address: 004056e0
/* public: virtual __thiscall RGE_Action_Move_To::~RGE_Action_Move_To(void) */

void __thiscall RGE_Action_Move_To::~RGE_Action_Move_To(RGE_Action_Move_To *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055c348;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  (**(code **)(*(int *)this->_padding_ + 0x1c0))(0);
  (**(code **)(*(int *)this->_padding_ + 0x1ec))();
  pcStack_8 = (code *)0xffffffff;
  RGE_Action::~RGE_Action((RGE_Action *)this);
  *unaff_FS_OFFSET = this;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00405750
/* public: virtual void __thiscall RGE_Action_Move_To::save(int) */

void __thiscall RGE_Action_Move_To::save(RGE_Action_Move_To *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->range,4);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 00405780
/* public: virtual void __thiscall RGE_Action_Move_To::first_in_stack(unsigned char) */

void __thiscall RGE_Action_Move_To::first_in_stack(RGE_Action_Move_To *this,uchar param_1)
{
  int iVar1;
  float10 fVar2;
  
  if ((RGE_Static_Object *)this->_padding_ != (RGE_Static_Object *)0x0) {
    iVar1 = RGE_Static_Object::inRange
                      ((RGE_Static_Object *)this->_padding_,(RGE_Static_Object *)this->_padding_,
                       this->range);
    if (iVar1 != 0) {
      (**(code **)(this->_padding_ + 0x5c))(1);
      return;
    }
  }
  fVar2 = (float10)(**(code **)(*(int *)this->_padding_ + 0xfc))();
  if (fVar2 == (float10)(double)DAT_0056e400._8_8_) {
    (**(code **)(this->_padding_ + 0x5c))(0xd);
    return;
  }
  (**(code **)(this->_padding_ + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004057e0
/* protected: virtual void __thiscall RGE_Action_Move_To::set_state(unsigned char) */

void __thiscall RGE_Action_Move_To::set_state(RGE_Action_Move_To *this,uchar param_1)
{
  *(uchar *)&this->_padding_ = param_1;
  switch(param_1) {
  case '\x01':
  case '\r':
  case '\x0e':
    if ((char)this->_padding_ == '\0') {
      (**(code **)(*(int *)this->_padding_ + 0x38))
                (*(undefined4 *)(((int *)this->_padding_)[2] + 0x18));
    }
    break;
  case '\x04':
    (**(code **)(*(int *)this->_padding_ + 0x38))(this->_padding_);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00405850
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Action_Move_To::update(void) */

uchar __thiscall RGE_Action_Move_To::update(RGE_Action_Move_To *this)
{
  code *pcVar1;
  undefined1 uVar2;
  RGE_Static_Object *pRVar3;
  PathResult PVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float yDiff_fffffff8;
  float fStack_4;
  
  if ((this->_padding_ != -1) &&
     (pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar3 == (RGE_Static_Object *)0x0)) {
    (**(code **)(this->_padding_ + 0x54))(0);
LAB_004058b5:
    if ((char)this->_padding_ == '\x01') {
      return '\x05';
    }
    iVar5 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar5,iVar5,0x1fb,0x262,this->_padding_,0);
    return '\x04';
  }
  if ((this->_padding_ != -1) &&
     (pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar3 == (RGE_Static_Object *)0x0)) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  pRVar3 = (RGE_Static_Object *)this->_padding_;
  if ((pRVar3 != (RGE_Static_Object *)0x0) && (6 < pRVar3->object_state)) {
    (**(code **)(this->_padding_ + 0x54))(0);
    goto LAB_004058b5;
  }
  switch((char)this->_padding_) {
  case '\x01':
    return '\x01';
  case '\x03':
    if ((pRVar3 != (RGE_Static_Object *)0x0) &&
       (iVar5 = RGE_Static_Object::inRange((RGE_Static_Object *)this->_padding_,pRVar3,this->range),
       iVar5 != 0)) {
      (**(code **)(this->_padding_ + 0x5c))(1);
      if ((char)this->_padding_ == '\0') {
        iVar5 = ((int *)this->_padding_)[1];
        (**(code **)(*(int *)this->_padding_ + 0x148))(iVar5,iVar5,0x1fa,0x262,0,0);
      }
      (**(code **)(*(int *)this->_padding_ + 300))(0);
      *(undefined4 *)(this->_padding_ + 0x58) = 0;
      return '\x02';
    }
    iVar5 = this->_padding_;
    if (iVar5 != 0) {
      this->_padding_ = *(int *)(iVar5 + 0x38);
      this->_padding_ = *(int *)(iVar5 + 0x3c);
      this->_padding_ = *(int *)(iVar5 + 0x40);
    }
    RGE_Moving_Object::setGoal
              ((RGE_Moving_Object *)this->_padding_,(float)this->_padding_,(float)this->_padding_,
               1.0);
    uVar2 = __ftol();
    yDiff_fffffff8 = (float)CONCAT31(yDiff_fffffff8._1_3_,uVar2);
    uVar2 = __ftol();
    yDiff_fffffff8._0_2_ = CONCAT11(uVar2,yDiff_fffffff8._0_1_);
    uVar2 = __ftol();
    yDiff_fffffff8._0_3_ = CONCAT12(uVar2,yDiff_fffffff8._0_2_);
    if ((char)((int *)this->_padding_)[0x5d] == '\0') {
      (**(code **)(*(int *)this->_padding_ + 0x1bc))(&yDiff_fffffff8,0);
      RGE_Moving_Object::setFinalUserDefinedWaypoint((RGE_Moving_Object *)this->_padding_);
    }
    RGE_Moving_Object::setActionRange((RGE_Moving_Object *)this->_padding_,this->range);
    if (this->_padding_ == 0) {
      RGE_Moving_Object::setTargetID((RGE_Moving_Object *)this->_padding_,-1);
      fVar7 = 0.0;
      fVar6 = 0.0;
    }
    else {
      RGE_Moving_Object::setTargetID
                ((RGE_Moving_Object *)this->_padding_,*(int *)(this->_padding_ + 4));
      iVar5 = *(int *)(this->_padding_ + 8);
      fVar7 = *(float *)(iVar5 + 0x34);
      fVar6 = *(float *)(iVar5 + 0x30);
    }
    RGE_Moving_Object::setTargetRadius((RGE_Moving_Object *)this->_padding_,fVar6,fVar7);
    PVar4 = RGE_Moving_Object::findPath((RGE_Moving_Object *)this->_padding_);
    if (PVar4 == PathFound) {
      (**(code **)(this->_padding_ + 0x5c))(4);
      return '\0';
    }
    break;
  case '\x04':
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      fVar7 = (float)this->_padding_ - pRVar3->world_x;
      yDiff_fffffff8 = (float)this->_padding_ - pRVar3->world_y;
      if ((((fVar7 < (float)ram0x0056e410) || ((float)_DAT_0056e418 < fVar7)) ||
          (yDiff_fffffff8 < (float)ram0x0056e410)) || ((float)_DAT_0056e418 < yDiff_fffffff8))
      goto LAB_00405b55;
    }
    iVar5 = RGE_Moving_Object::doMove((RGE_Moving_Object *)this->_padding_);
    if (iVar5 == 0) {
      (**(code **)(this->_padding_ + 0x5c))(1);
      goto switchD_00405902_caseD_d;
    }
    if (iVar5 == 2) {
      iVar5 = this->_padding_;
      if (iVar5 != 0) {
        fVar7 = (float)this->_padding_ - *(float *)(iVar5 + 0x38);
        fStack_4 = (float)this->_padding_ - *(float *)(iVar5 + 0x3c);
        if (((fVar7 < (float)ram0x0056e410) || ((float)_DAT_0056e418 < fVar7)) ||
           ((fStack_4 < (float)ram0x0056e410 || ((float)_DAT_0056e418 < fStack_4)))) {
LAB_00405b55:
          iVar5 = ((int *)this->_padding_)[1];
          (**(code **)(*(int *)this->_padding_ + 0x148))(iVar5,iVar5,0x1fc,0,0,0);
          iVar5 = this->_padding_;
          (**(code **)(iVar5 + 0x5c))(3);
          pcVar1 = *(code **)(iVar5 + 0x28);
          (*pcVar1)();
          (*pcVar1)();
          return '\0';
        }
      }
      if ((char)this->_padding_ == '\0') {
        iVar5 = ((int *)this->_padding_)[1];
        (**(code **)(*(int *)this->_padding_ + 0x148))(iVar5,iVar5,0x1fa,0x262,0,0);
      }
      (**(code **)(this->_padding_ + 0x5c))(1);
      return '\x02';
    }
    break;
  case '\r':
switchD_00405902_caseD_d:
    if ((char)this->_padding_ == '\0') {
      iVar5 = ((int *)this->_padding_)[1];
      (**(code **)(*(int *)this->_padding_ + 0x148))(iVar5,iVar5,0x1f9,0x262,0,0);
    }
    return '\x03';
  }
  return '\0';
}

// --------------------------------------------------

// Function: is_in_range
// Address: 00405bf0
/* protected: unsigned char __thiscall RGE_Action_Move_To::is_in_range(void) */

uchar __thiscall RGE_Action_Move_To::is_in_range(RGE_Action_Move_To *this)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  float fVar3;
  
  pRVar1 = (RGE_Static_Object *)this->_padding_;
  if (this->range <= (float)DAT_0056e400._0_4_) {
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      iVar2 = RGE_Static_Object::inRange((RGE_Static_Object *)this->_padding_,pRVar1,0.25);
      if (iVar2 != 0) {
        return '\x01';
      }
    }
  }
  else {
    if (pRVar1 == (RGE_Static_Object *)0x0) {
      fVar3 = RGE_Static_Object::distance_to_position
                        ((RGE_Static_Object *)this->_padding_,(float)this->_padding_,
                         (float)this->_padding_,(float)this->_padding_);
    }
    else {
      fVar3 = RGE_Static_Object::distance_to_object((RGE_Static_Object *)this->_padding_,pRVar1);
    }
    if (fVar3 <= this->range) {
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

