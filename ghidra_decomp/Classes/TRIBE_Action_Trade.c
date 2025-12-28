// Class: TRIBE_Action_Trade
// Size:  0x48
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
// [0x040] float pick_up_x
// [0x044] float pick_up_y
// ----------------------------------------------------------------

// Function: TRIBE_Action_Trade
// Address: 004d2660
/* public: __thiscall TRIBE_Action_Trade::TRIBE_Action_Trade(int,class RGE_Action_Object *) */

TRIBE_Action_Trade * __thiscall
TRIBE_Action_Trade::TRIBE_Action_Trade
          (TRIBE_Action_Trade *this,int param_1,RGE_Action_Object *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560188;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  rge_read(param_1,&this->pick_up_x,4);
  rge_read(param_1,&this->pick_up_y,4);
  *(undefined2 *)&this->_padding_ = 0x6f;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004d26e0
/* public: virtual void * __thiscall TRIBE_Action_Trade::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Action_Trade::_scalar_deleting_destructor_(TRIBE_Action_Trade *this,uint param_1)
{
  ~TRIBE_Action_Trade(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Trade
// Address: 004d2700
/* public: virtual __thiscall TRIBE_Action_Trade::~TRIBE_Action_Trade(void) */

void __thiscall TRIBE_Action_Trade::~TRIBE_Action_Trade(TRIBE_Action_Trade *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&RGE_Action::_vftable_;
  RGE_Action::set_target_obj((RGE_Action *)this,(RGE_Static_Object *)0x0);
  RGE_Action::set_target_obj2((RGE_Action *)this,(RGE_Static_Object *)0x0);
  this_00 = (RGE_Action_List *)this->_padding_;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->_padding_ = 0;
  }
  return;
}

// --------------------------------------------------

// Function: TRIBE_Action_Trade
// Address: 004d2710
/* public: __thiscall TRIBE_Action_Trade::TRIBE_Action_Trade(class RGE_Action_Object *,class
   RGE_Task *,class RGE_Static_Object *) */

TRIBE_Action_Trade * __thiscall
TRIBE_Action_Trade::TRIBE_Action_Trade
          (TRIBE_Action_Trade *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005601a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
                    /* language.dll match for 0x6f: "12" */
  *(undefined2 *)&this->_padding_ = 0x6f;
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  this->_padding_ = (int)param_3->world_x;
  this->_padding_ = (int)param_3->world_y;
  this->_padding_ = (int)param_3->world_z;
  this->pick_up_x = -1.0;
  this->pick_up_y = -1.0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Trade
// Address: 004d27a0
/* public: __thiscall TRIBE_Action_Trade::TRIBE_Action_Trade(class RGE_Action_Object *,class
   RGE_Task *,float,float,float) */

TRIBE_Action_Trade * __thiscall
TRIBE_Action_Trade::TRIBE_Action_Trade
          (TRIBE_Action_Trade *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_4;
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)&_vftable_;
  this->pick_up_x = -1.0;
  this->pick_up_y = -1.0;
  *(undefined2 *)&this->_padding_ = 0x6f;
  this->_padding_ = (int)param_3;
  this->_padding_ = (int)param_5;
  return this;
}

// --------------------------------------------------

// Function: save
// Address: 004d27f0
/* public: virtual void __thiscall TRIBE_Action_Trade::save(int) */

void __thiscall TRIBE_Action_Trade::save(TRIBE_Action_Trade *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->pick_up_x,4);
  rge_write(param_1,&this->pick_up_y,4);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004d2830
/* public: virtual void __thiscall TRIBE_Action_Trade::first_in_stack(unsigned char) */

void __thiscall TRIBE_Action_Trade::first_in_stack(TRIBE_Action_Trade *this,uchar param_1)
{
  short sVar1;
  
  sVar1 = *(short *)(this->_padding_ + 0x4c);
  if (((sVar1 != 0) && (sVar1 != 2)) && (sVar1 != 1)) {
    *(undefined2 *)(this->_padding_ + 0x4c) = 1;
  }
  if (param_1 != '\0') {
    if (this->_padding_ != 0) {
      (**(code **)(this->_padding_ + 0x5c))(4);
      return;
    }
    (**(code **)(this->_padding_ + 0x5c))(2);
    return;
  }
  (**(code **)(this->_padding_ + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004d2880
/* protected: virtual void __thiscall TRIBE_Action_Trade::set_state(unsigned char) */

void __thiscall TRIBE_Action_Trade::set_state(TRIBE_Action_Trade *this,uchar param_1)
{
  short sVar1;
  RGE_Sound *this_00;
  int iVar2;
  char cVar3;
  RGE_Action_Move_To *pRVar4;
  RGE_Sprite *pRVar5;
  RGE_Action *pRVar6;
  RGE_Static_Object *pRVar7;
  undefined4 unaff_EBX;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar8;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005601e1;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
  *(uchar *)&this->_padding_ = param_1;
  switch(param_1) {
  case '\x02':
    iVar2 = *(int *)this->_padding_;
    pRVar5 = get_wait_sprite(this);
    (**(code **)(iVar2 + 0x38))(pRVar5);
    iVar2 = this->_padding_;
    (**(code **)(iVar2 + 0x54))(0);
    (**(code **)(iVar2 + 0x58))(0);
    this->_padding_ = -0x40800000;
    this->_padding_ = -0x40800000;
    this->_padding_ = -0x40800000;
    *unaff_FS_OFFSET = unaff_EDI;
    return;
  case '\x03':
    iVar2 = ((int *)this->_padding_)[1];
    uVar8 = 0x202;
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar2,iVar2,0x202,0x267,0,0);
    iVar2 = *(int *)this->_padding_;
    pRVar5 = get_wait_sprite(this);
    (**(code **)(iVar2 + 0x38))(pRVar5);
    *unaff_FS_OFFSET = uVar8;
    return;
  case '\x04':
    iVar2 = this->_padding_;
    if (iVar2 == 0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    this->_padding_ = *(int *)(iVar2 + 0x38);
    this->_padding_ = *(int *)(iVar2 + 0x3c);
    this->_padding_ = *(int *)(iVar2 + 0x40);
    pRVar4 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 1;
    if (pRVar4 != (RGE_Action_Move_To *)0x0) {
      pRVar5 = get_move_sprite(this);
      pRVar6 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar4,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,*(float *)(this->_padding_ + 0x24),
                          pRVar5);
      goto LAB_004d2ba3;
    }
    break;
  default:
switchD_004d28ba_caseD_5:
    *unaff_FS_OFFSET = local_c;
    return;
  case '\x06':
    iVar2 = *(int *)this->_padding_;
    pRVar5 = get_move_sprite(this);
    (**(code **)(iVar2 + 0x38))(pRVar5);
    *unaff_FS_OFFSET = unaff_EBX;
    return;
  case '\a':
    (**(code **)(*(int *)this->_padding_ + 0x38))(*(undefined4 *)(this->_padding_ + 0x38));
    this_00 = *(RGE_Sound **)(this->_padding_ + 0x44);
    if (this_00 != (RGE_Sound *)0x0) {
      RGE_Sound::play(this_00,1);
    }
    iVar2 = this->_padding_;
    if (iVar2 != 0) {
      this->pick_up_x = *(float *)(iVar2 + 0x38);
      this->pick_up_y = *(float *)(iVar2 + 0x3c);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    this->pick_up_x = -1.0;
    this->pick_up_y = -1.0;
    *unaff_FS_OFFSET = unaff_EBX;
    return;
  case '\b':
    pRVar7 = (RGE_Static_Object *)this->_padding_;
    if (pRVar7->attribute_amount_held <= (float)DAT_00575348._0_4_) {
      iVar2 = this->_padding_;
      if (((iVar2 != 0) && (*(float *)(iVar2 + 0x44) <= (float)DAT_00575348._0_4_)) &&
         (cVar3 = (**(code **)(pRVar7->_padding_ + 0x138))
                            ((int)*(short *)(*(int *)(iVar2 + 8) + 0x10)), cVar3 == '\0')) {
        iVar2 = this->_padding_;
        (**(code **)(iVar2 + 0x54))(0);
        (**(code **)(iVar2 + 0x5c))(3);
      }
      goto switchD_004d28ba_caseD_5;
    }
    if ((this->_padding_ == 0) ||
       (*(short *)(*(int *)(this->_padding_ + 8) + 0x10) !=
        *(short *)&pRVar7->master_obj[1].radius_x)) {
      sVar1 = *(short *)&pRVar7->master_obj[1].radius_x;
      if (sVar1 == -1) {
        (**(code **)(this->_padding_ + 0x58))(0);
      }
      else {
        iVar2 = this->_padding_;
        pRVar7 = RGE_Object_List::find_by_master_ids
                           (pRVar7->owner->objects,(int)sVar1,
                            (int)*(short *)((int)&pRVar7->master_obj[1].radius_x + 2),
                            pRVar7->world_x,pRVar7->world_y,'\x01','\x02',pRVar7);
        (**(code **)(iVar2 + 0x58))(pRVar7);
      }
    }
    if (this->_padding_ == 0) {
      iVar2 = ((int *)this->_padding_)[1];
      uVar8 = 0x203;
      (**(code **)(*(int *)this->_padding_ + 0x148))(iVar2,iVar2,0x203,0x267,0,0);
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = uVar8;
      return;
    }
    pRVar4 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 2;
    if (pRVar4 != (RGE_Action_Move_To *)0x0) {
      pRVar5 = get_move_sprite(this);
      pRVar6 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar4,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,0.0,pRVar5);
      goto LAB_004d2ba3;
    }
    break;
  case '\v':
    pRVar4 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar4 == (RGE_Action_Move_To *)0x0) {
      pRVar6 = (RGE_Action *)0x0;
    }
    else {
      pRVar5 = get_move_sprite(this);
      pRVar6 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar4,(RGE_Action_Object *)this->_padding_,(float)this->_padding_,
                          (float)this->_padding_,(float)this->_padding_,0.0,pRVar5);
    }
    local_4 = 0xffffffff;
    if (pRVar6 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    RGE_Action::setSubAction(pRVar6,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar6);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  pRVar6 = (RGE_Action *)0x0;
LAB_004d2ba3:
  local_4 = 0xffffffff;
  if (pRVar6 == (RGE_Action *)0x0) {
    (**(code **)(this->_padding_ + 0x5c))(0xd);
    *unaff_FS_OFFSET = unaff_EBX;
    return;
  }
  RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar6);
  RGE_Action::setSubAction(pRVar6,'\x01');
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004d2cb0
/* WARNING: Variable defined which should be unmapped: take_amount */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall TRIBE_Action_Trade::update(void) */

uchar __thiscall TRIBE_Action_Trade::update(TRIBE_Action_Trade *this)
{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  RGE_Sound *this_00;
  int *piVar5;
  float fVar6;
  undefined1 uVar7;
  char cVar8;
  RGE_Static_Object *pRVar9;
  undefined2 extraout_var;
  float unaff_EDI;
  float fVar10;
  float take_amount;
  float max_hold;
  
  if ((this->_padding_ != -1) &&
     (pRVar9 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar9 == (RGE_Static_Object *)0x0)) {
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if ((this->_padding_ != -1) &&
     (pRVar9 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar9 == (RGE_Static_Object *)0x0)) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  if ((this->_padding_ != 0) && (6 < *(byte *)(this->_padding_ + 0x48))) {
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if ((this->_padding_ != 0) && (6 < *(byte *)(this->_padding_ + 0x48))) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  iVar3 = this->_padding_;
  if ((iVar3 != 0) &&
     (*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a) == *(short *)(*(int *)(iVar3 + 0xc) + 0x4a)
     )) {
    iVar3 = this->_padding_;
    (**(code **)(iVar3 + 0x54))(0);
    (**(code **)(iVar3 + 0x58))(0);
    (**(code **)(iVar3 + 0x5c))(1);
    if ((char)this->_padding_ == '\0') {
      iVar3 = ((int *)this->_padding_)[1];
      (**(code **)(*(int *)this->_padding_ + 0x148))(iVar3,iVar3,0x1fb,0x267,this->_padding_,0);
    }
    return '\x04';
  }
  switch((char)this->_padding_) {
  case '\x01':
    return '\x01';
  case '\x04':
    if ((float)(double)DAT_00575348._8_8_ <= (float)this->_padding_) {
      uVar7 = (**(code **)(*(int *)this->_padding_ + 0xc))();
      switch(uVar7) {
      case 1:
      case 2:
        (**(code **)(this->_padding_ + 0x5c))(6);
        return '\0';
      case 3:
      case 4:
switchD_004d2e0c_caseD_2:
        this->_padding_ = -0x41000000;
        return '\0';
      case 5:
        goto switchD_004d2e80_caseD_4;
      }
    }
    else {
      fVar10 = *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84) +
               (float)this->_padding_;
      fVar6 = (float)(double)DAT_00575348._8_8_;
      this->_padding_ = (int)fVar10;
      if (fVar6 < fVar10) {
        this->_padding_ = 0;
        if (iVar3 != 0) {
          (**(code **)(this->_padding_ + 0x5c))(4);
          return '\0';
        }
        goto switchD_004d2e0c_caseD_0;
      }
    }
    break;
  case '\x06':
    if (iVar3 == 0) {
      (**(code **)(this->_padding_ + 0x5c))(3);
      return '\0';
    }
    cVar8 = (**(code **)(*(int *)this->_padding_ + 0x1f0))(iVar3,0,0);
    if (cVar8 != '\0') {
      if (((float)DAT_00575348._0_4_ < *(float *)(this->_padding_ + 0x44)) ||
         (cVar8 = (**(code **)(*(int *)this->_padding_ + 0x138))
                            ((int)*(short *)(*(int *)(this->_padding_ + 8) + 0x10)), cVar8 != '\0'))
{
        (**(code **)(this->_padding_ + 0x5c))(7);
        return '\0';
      }
switchD_004d2e80_caseD_4:
      iVar3 = this->_padding_;
      (**(code **)(iVar3 + 0x54))(0);
      (**(code **)(iVar3 + 0x5c))(3);
      return '\0';
    }
    break;
  case '\a':
    iVar4 = this->_padding_;
    if (iVar3 == 0) {
      if ((float)DAT_00575348._0_4_ < *(float *)(iVar4 + 0x44)) {
        (**(code **)(this->_padding_ + 0x5c))(8);
        return '\0';
      }
      goto switchD_004d2e0c_caseD_0;
    }
    sVar1 = *(short *)(iVar4 + 0x4c);
    if (((sVar1 != 0) && (sVar1 != 2)) && (sVar1 != 1)) {
      *(undefined2 *)(iVar4 + 0x4c) = 1;
    }
    iVar3 = this->_padding_;
    sVar1 = *(short *)(*(int *)(iVar3 + 8) + 0x7c);
    sVar2 = *(short *)(iVar3 + 0x4c);
    iVar4 = (*(int **)(iVar3 + 0xc))[0x14];
    max_hold = (float)(int)sVar1 - *(float *)(iVar3 + 0x44);
    if (*(float *)(iVar4 + sVar2 * 4) < max_hold) {
      max_hold = *(float *)(iVar4 + sVar2 * 4);
    }
    iVar4 = *(int *)(*(int *)(this->_padding_ + 0xc) + 0x50);
    if (*(float *)(iVar4 + 0x24) < max_hold) {
      max_hold = *(float *)(iVar4 + 0x24);
    }
    fVar10 = 1.4013e-45;
    (**(code **)(**(int **)(iVar3 + 0xc) + 0x78))(CONCAT22(sVar1 >> 0xf,sVar2),-max_hold);
    iVar3 = *(int *)(*(int *)(this->_padding_ + 0xc) + 0x50);
    *(float *)(iVar3 + 0x24) = *(float *)(iVar3 + 0x24) - fVar10;
    *(float *)(this->_padding_ + 0x44) = fVar10 + *(float *)(this->_padding_ + 0x44);
    if (unaff_EDI <= (float)((int *)this->_padding_)[0x11]) {
LAB_004d31f4:
      (**(code **)(this->_padding_ + 0x5c))(8);
      return '\0';
    }
    if ((*(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x50) + 0x24) <=
         (float)DAT_00575348._0_4_) &&
       (cVar8 = (**(code **)(*(int *)this->_padding_ + 0x138))
                          ((int)*(short *)(*(int *)(this->_padding_ + 8) + 0x10)), cVar8 == '\0')) {
      (**(code **)(this->_padding_ + 0x5c))(8);
      return '\0';
    }
    break;
  case '\b':
    if ((float)(double)DAT_00575348._8_8_ <= (float)this->_padding_) {
      uVar7 = (**(code **)(*(int *)this->_padding_ + 0xc))();
      switch(uVar7) {
      case 1:
      case 2:
        if (this->_padding_ != 0) {
          if ((float)(double)DAT_00575348._8_8_ < *(float *)(this->_padding_ + 0x44)) {
            this_00 = *(RGE_Sound **)(this->_padding_ + 0x48);
            if (this_00 != (RGE_Sound *)0x0) {
              RGE_Sound::play(this_00,1);
            }
            fVar10 = _DAT_00575360;
            if (((float)(double)DAT_00575348._8_8_ <= this->pick_up_x) &&
               ((float)(double)DAT_00575348._8_8_ <= this->pick_up_y)) {
              fVar6 = this->pick_up_x - *(float *)(this->_padding_ + 0x38);
              fVar10 = this->pick_up_y - *(float *)(this->_padding_ + 0x3c);
              fVar10 = (fVar10 * fVar10 + fVar6 * fVar6) * _DAT_00575358 * _DAT_0057535c;
            }
            piVar5 = *(int **)(this->_padding_ + 0xc);
            if (*(char *)((int)piVar5 + 0x105) == '\x0f') {
              fVar10 = fVar10 + fVar10;
            }
            if (fVar10 < (float)_DAT_00575368) {
              fVar10 = _DAT_00575360;
            }
            fVar10 = *(float *)(this->_padding_ + 0x44) * fVar10;
            if (_DAT_00575370 < fVar10) {
              fVar10 = 75.0;
            }
            (**(code **)(*piVar5 + 0x78))(3,fVar10,1);
            (**(code **)(*(int *)this->_padding_ + 0x80))
                      (CONCAT22(extraout_var,(short)((int *)this->_padding_)[0x13]),0);
          }
          if (this->_padding_ != 0) {
            (**(code **)(this->_padding_ + 0x5c))(4);
            return '\0';
          }
          (**(code **)(this->_padding_ + 0x5c))(3);
          return '\0';
        }
        goto LAB_004d31f4;
      case 3:
      case 4:
      case 5:
        goto switchD_004d2e0c_caseD_2;
      }
    }
    else {
      fVar10 = *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84) +
               (float)this->_padding_;
      fVar6 = (float)(double)DAT_00575348._8_8_;
      this->_padding_ = (int)fVar10;
      if (fVar6 < fVar10) {
        this->_padding_ = 0;
        (**(code **)(this->_padding_ + 0x5c))(8);
        return '\0';
      }
    }
    break;
  case '\v':
    if ((float)(double)DAT_00575348._8_8_ <= (float)this->_padding_) {
      uVar7 = (**(code **)(*(int *)this->_padding_ + 0xc))();
      switch(uVar7) {
      case 1:
      case 2:
      case 5:
        goto switchD_004d2e0c_caseD_0;
      case 3:
      case 4:
        goto switchD_004d2e0c_caseD_2;
      }
    }
    else {
      fVar10 = *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84) +
               (float)this->_padding_;
      fVar6 = (float)(double)DAT_00575348._8_8_;
      this->_padding_ = (int)fVar10;
      if (fVar6 < fVar10) {
        this->_padding_ = 0;
        if (iVar3 != 0) {
          (**(code **)(this->_padding_ + 0x5c))(4);
          return '\0';
        }
switchD_004d2e0c_caseD_0:
        (**(code **)(this->_padding_ + 0x5c))(3);
        return '\0';
      }
    }
    break;
  case '\r':
    iVar3 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar3,iVar3,0x1f9,0x267,0,0);
    (**(code **)(this->_padding_ + 0x5c))(2);
    return '\x03';
  }
  return '\0';
}

// --------------------------------------------------

// Function: get_move_sprite
// Address: 004d32c0
/* protected: class RGE_Sprite * __thiscall TRIBE_Action_Trade::get_move_sprite(void) */

RGE_Sprite * __thiscall TRIBE_Action_Trade::get_move_sprite(TRIBE_Action_Trade *this)
{
  int iVar1;
  int iVar2;
  
  iVar1 = this->_padding_;
  if ((((*(short *)(iVar1 + 0x14) != -1) &&
       (*(short *)(this->_padding_ + 0x4c) == *(short *)(iVar1 + 0x14))) &&
      (iVar2 = __ftol(), 0 < iVar2)) && (*(RGE_Sprite **)(iVar1 + 0x40) != (RGE_Sprite *)0x0)) {
    return *(RGE_Sprite **)(iVar1 + 0x40);
  }
  return *(RGE_Sprite **)(iVar1 + 0x34);
}

// --------------------------------------------------

// Function: get_wait_sprite
// Address: 004d32f0
/* protected: class RGE_Sprite * __thiscall TRIBE_Action_Trade::get_wait_sprite(void) */

RGE_Sprite * __thiscall TRIBE_Action_Trade::get_wait_sprite(TRIBE_Action_Trade *this)
{
  short sVar1;
  int iVar2;
  RGE_Sprite *pRVar3;
  int iVar4;
  
  iVar2 = this->_padding_;
  sVar1 = *(short *)(iVar2 + 0x14);
  if ((((sVar1 != -1) && (sVar1 == *(short *)(this->_padding_ + 0x4c))) &&
      (iVar4 = __ftol(), 0 < iVar4)) &&
     (pRVar3 = *(RGE_Sprite **)(iVar2 + 0x40), pRVar3 != (RGE_Sprite *)0x0)) {
    return pRVar3;
  }
  return *(RGE_Sprite **)(*(int *)(this->_padding_ + 8) + 0x18);
}

// --------------------------------------------------

// Function: stop
// Address: 004d3330
/* public: virtual int __thiscall TRIBE_Action_Trade::stop(void) */

int __thiscall TRIBE_Action_Trade::stop(TRIBE_Action_Trade *this)
{
  (**(code **)(this->_padding_ + 0x5c))(2);
  return 1;
}

// --------------------------------------------------

// Function: move_to
// Address: 004d3340
/* public: virtual int __thiscall TRIBE_Action_Trade::move_to(class RGE_Static_Object
   *,float,float,float) */

int __thiscall
TRIBE_Action_Trade::move_to
          (TRIBE_Action_Trade *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  int iVar1;
  
  if (((param_1 == (RGE_Static_Object *)0x0) ||
      (param_1->owner != *(RGE_Player **)(this->_padding_ + 0xc))) ||
     (param_1->master_obj->id != *(short *)(*(int *)(this->_padding_ + 8) + 0xe8))) {
    iVar1 = this->_padding_;
    this->_padding_ = (int)param_3;
    this->_padding_ = (int)param_2;
    this->_padding_ = (int)param_4;
    (**(code **)(iVar1 + 0x54))(0);
    (**(code **)(iVar1 + 0x5c))(0xb);
  }
  else if ((param_1 != (RGE_Static_Object *)this->_padding_) || ((char)this->_padding_ != '\b')) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0x58))(param_1);
    (**(code **)(iVar1 + 0x5c))(8);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: work
// Address: 004d33c0
/* public: virtual int __thiscall TRIBE_Action_Trade::work(class RGE_Static_Object
   *,float,float,float) */

int __thiscall
TRIBE_Action_Trade::work
          (TRIBE_Action_Trade *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  char cVar1;
  int iVar2;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    iVar2 = this->_padding_;
    this->_padding_ = (int)param_3;
    this->_padding_ = (int)param_2;
    this->_padding_ = (int)param_4;
    (**(code **)(iVar2 + 0x54))(0);
    (**(code **)(iVar2 + 0x5c))(0xb);
  }
  else if ((param_1 != (RGE_Static_Object *)this->_padding_) ||
          (((cVar1 = (char)this->_padding_, cVar1 != '\x04' && (cVar1 != '\x06')) && (cVar1 != '\a')
           ))) {
    if ((param_1->owner == *(RGE_Player **)(this->_padding_ + 0xc)) &&
       (param_1->master_obj->id == *(short *)(*(int *)(this->_padding_ + 8) + 0xe8))) {
      iVar2 = this->_padding_;
      (**(code **)(iVar2 + 0x58))(param_1);
      (**(code **)(iVar2 + 0x5c))(8);
      return 1;
    }
    iVar2 = this->_padding_;
    (**(code **)(iVar2 + 0x54))(param_1);
    (**(code **)(iVar2 + 0x5c))(4);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

