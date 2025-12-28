// Class: TRIBE_Action_Repair
// Size:  0x44
//
// VTable Layout:
// [00] `vector_deleting_destructor'
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
// [0x040] uchar save_target_command_flag
// ----------------------------------------------------------------

// Function: TRIBE_Action_Repair
// Address: 004d1680
TRIBE_Action_Repair * __thiscall
TRIBE_Action_Repair::TRIBE_Action_Repair
          (TRIBE_Action_Repair *this,int param_1,RGE_Action_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005600e8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6a;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004d16f0
void * __thiscall
TRIBE_Action_Repair::_vector_deleting_destructor_(TRIBE_Action_Repair *this,uint param_1)
{
  ~TRIBE_Action_Repair(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Repair
// Address: 004d1710
void __thiscall TRIBE_Action_Repair::~TRIBE_Action_Repair(TRIBE_Action_Repair *this)
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

// Function: TRIBE_Action_Repair
// Address: 004d1720
TRIBE_Action_Repair * __thiscall
TRIBE_Action_Repair::TRIBE_Action_Repair
          (TRIBE_Action_Repair *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560108;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6a;
  this->save_target_command_flag = '\0';
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  if (param_3 != (RGE_Static_Object *)0x0) {
    this->_padding_ = (int)param_3->world_x;
    this->_padding_ = (int)param_3->world_y;
    this->_padding_ = (int)param_3->world_z;
    meet_target(this);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Repair
// Address: 004d17b0
TRIBE_Action_Repair * __thiscall
TRIBE_Action_Repair::TRIBE_Action_Repair
          (TRIBE_Action_Repair *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)param_4;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6a;
  this->_padding_ = (int)param_3;
  this->_padding_ = (int)param_5;
  this->save_target_command_flag = '\0';
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 004d1800
int __thiscall
TRIBE_Action_Repair::setup(TRIBE_Action_Repair *this,int param_1,RGE_Action_Object *param_2)
{
  int iVar1;
  
  iVar1 = RGE_Action::setup((RGE_Action *)this,param_1,param_2);
  if (_DAT_00575268 <= save_game_version) {
    rge_read(param_1,&this->save_target_command_flag,1);
    return iVar1;
  }
  this->save_target_command_flag = '\0';
  return iVar1;
}

// --------------------------------------------------

// Function: save
// Address: 004d1850
void __thiscall TRIBE_Action_Repair::save(TRIBE_Action_Repair *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->save_target_command_flag,1);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004d1880
void __thiscall TRIBE_Action_Repair::first_in_stack(TRIBE_Action_Repair *this,uchar param_1)
{
  if ((param_1 != '\0') && (this->_padding_ != 0)) {
    (**(code **)(this->_padding_ + 0x5c))(4);
    return;
  }
  (**(code **)(this->_padding_ + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004d18b0
void __thiscall TRIBE_Action_Repair::set_state(TRIBE_Action_Repair *this,uchar param_1)
{
  short sVar1;
  int *piVar2;
  RGE_Sound *this_00;
  RGE_Action_Move_To *pRVar3;
  RGE_Action *pRVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar7;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560136;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
  *(uchar *)&this->_padding_ = param_1;
  switch(param_1) {
  case '\x01':
    (**(code **)(this->_padding_ + 0x54))(0);
    if ((char)this->_padding_ == '\0') {
      iVar5 = ((int *)this->_padding_)[1];
      iVar6 = *(int *)this->_padding_;
      uVar7 = 0x1fa;
      goto LAB_004d1b4f;
    }
    break;
  case '\x02':
    break;
  case '\x03':
    iVar5 = ((int *)this->_padding_)[1];
    iVar6 = *(int *)this->_padding_;
    uVar7 = 0x202;
LAB_004d1b4f:
    (**(code **)(iVar6 + 0x148))(iVar5,iVar5,uVar7,0x26a,0,0);
    break;
  case '\x04':
    iVar5 = this->_padding_;
    if (iVar5 != 0) {
      this->_padding_ = *(int *)(iVar5 + 0x38);
      this->_padding_ = *(int *)(iVar5 + 0x3c);
      this->_padding_ = *(int *)(iVar5 + 0x40);
    }
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 1;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,
                          *(float *)(((RGE_Action_Object *)this->_padding_)->_padding_ + 0x114),
                          *(RGE_Sprite **)(this->_padding_ + 0x34));
    }
    local_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar4);
    RGE_Action::setSubAction(pRVar4,'\x01');
    *unaff_FS_OFFSET = local_c;
    return;
  default:
    goto switchD_004d18e7_caseD_5;
  case '\x06':
    iVar5 = this->_padding_;
    this->_padding_ = *(int *)(iVar5 + 0x38);
    this->_padding_ = *(int *)(iVar5 + 0x3c);
    iVar6 = *(int *)this->_padding_;
    this->_padding_ = *(int *)(iVar5 + 0x40);
    (**(code **)(iVar6 + 0x38))(*(undefined4 *)(this->_padding_ + 0x34));
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  case '\a':
    (**(code **)(*(int *)this->_padding_ + 0x38))(*(undefined4 *)(this->_padding_ + 0x38));
    this_00 = *(RGE_Sound **)(this->_padding_ + 0x44);
    if (this_00 != (RGE_Sound *)0x0) {
      RGE_Sound::play(this_00,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    goto switchD_004d18e7_caseD_5;
  case '\n':
    (**(code **)(*(int *)this->_padding_ + 0x38))
              (*(undefined4 *)(((int *)this->_padding_)[2] + 0x18));
    piVar2 = (int *)this->_padding_;
    this->_padding_ = 0x3f800000;
    if (((piVar2 != (int *)0x0) &&
        ((((sVar1 = *(short *)(piVar2[2] + 0x14), sVar1 == 2 || (sVar1 == 0x14)) || (sVar1 == 0x15))
         || (sVar1 == 0x16)))) && ((uchar)piVar2[0x62] == this->save_target_command_flag)) {
      iVar5 = this->_padding_;
      uVar7 = *(undefined4 *)(iVar5 + 0x40);
      (**(code **)(*piVar2 + 0x154))
                (*(undefined4 *)(iVar5 + 0x38),*(undefined4 *)(iVar5 + 0x3c),uVar7,0,1);
      *unaff_FS_OFFSET = uVar7;
      return;
    }
    goto switchD_004d18e7_caseD_5;
  case '\v':
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,(RGE_Action_Object *)this->_padding_,(float)this->_padding_,
                          (float)this->_padding_,(float)this->_padding_,0.0,
                          *(RGE_Sprite **)(this->_padding_ + 0x34));
    }
    local_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action::setSubAction(pRVar4,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar4);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  (**(code **)(*(int *)this->_padding_ + 0x38))(*(undefined4 *)(((int *)this->_padding_)[2] + 0x18))
  ;
switchD_004d18e7_caseD_5:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004d1bb0
uchar __thiscall TRIBE_Action_Repair::update(TRIBE_Action_Repair *this)
{
  float fVar1;
  undefined1 uVar2;
  char cVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  float fVar6;
  
  if ((this->_padding_ == -1) ||
     (pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar4 != (RGE_Static_Object *)0x0)) {
    if ((this->_padding_ != -1) &&
       (pRVar4 = RGE_Game_World::object
                           (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                            this->_padding_), pRVar4 == (RGE_Static_Object *)0x0)) {
      (**(code **)(this->_padding_ + 0x58))(0);
    }
    iVar5 = this->_padding_;
    if ((iVar5 == 0) ||
       ((*(char *)(iVar5 + 0x48) == '\x02' &&
        ((iVar5 == 0 ||
         (iVar5 = (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x1c))
                            ((int)*(short *)(*(int *)(iVar5 + 0xc) + 0x4a)), iVar5 != 0)))))) {
      fVar6 = _DAT_00575278;
      switch((char)this->_padding_) {
      case '\x01':
        return '\x01';
      case '\x04':
        uVar2 = (**(code **)(*(int *)this->_padding_ + 0xc))();
        switch(uVar2) {
        case 1:
        case 2:
        case 3:
          fVar6 = RGE_Static_Object::distance_to_object
                            ((RGE_Static_Object *)this->_padding_,
                             (RGE_Static_Object *)this->_padding_);
          DAT_0086bc08._0_4_ = fVar6 - _DAT_0057526c;
          if ((float)DAT_0086bc08 <= (float)_DAT_00575270) {
            (**(code **)(this->_padding_ + 0x5c))(6);
            return '\0';
          }
          (**(code **)(this->_padding_ + 0x5c))(10);
          return '\0';
        case 4:
        case 5:
          goto switchD_004d1c93_caseD_3;
        }
        break;
      case '\x06':
        if (this->_padding_ == 0) {
          (**(code **)(this->_padding_ + 0x5c))(1);
          return '\0';
        }
        cVar3 = (**(code **)(*(int *)this->_padding_ + 0x1f0))(this->_padding_,0,0);
        if (cVar3 != '\0') {
          (**(code **)(this->_padding_ + 0x5c))(7);
          return '\0';
        }
        break;
      case '\a':
        pRVar4 = (RGE_Static_Object *)this->_padding_;
        if (pRVar4 == (RGE_Static_Object *)0x0) {
          (**(code **)(this->_padding_ + 0x5c))(1);
          return '\0';
        }
        if ((pRVar4->world_x != (float)this->_padding_) ||
           ((float)this->_padding_ != pRVar4->world_y)) {
          fVar6 = RGE_Static_Object::distance_to_object((RGE_Static_Object *)this->_padding_,pRVar4)
          ;
          DAT_0086bc08._0_4_ = fVar6 - _DAT_0057526c;
          if ((float)_DAT_00575270 < (float)DAT_0086bc08) {
            (**(code **)(this->_padding_ + 0x5c))(3);
            return '\0';
          }
          iVar5 = this->_padding_;
          this->_padding_ = *(int *)(iVar5 + 0x38);
          this->_padding_ = *(int *)(iVar5 + 0x3c);
          this->_padding_ = *(int *)(iVar5 + 0x40);
          return '\0';
        }
        cVar3 = (**(code **)(pRVar4->_padding_ + 0x8c))
                          (*(float *)(this->_padding_ + 0x1c) *
                           *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84) *
                           *(float *)(*(int *)(this->_padding_ + 8) + 0xe4));
        if (cVar3 == '\x01') {
          (**(code **)(this->_padding_ + 0x5c))(1);
          return '\0';
        }
        if (cVar3 == '\x02') {
          iVar5 = ((int *)this->_padding_)[1];
          (**(code **)(*(int *)this->_padding_ + 0x148))(iVar5,iVar5,0x1fb,0x26a,0,0);
          (**(code **)(rge_base_game->_padding_ + 0x40))
                    (0x6b,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),
                     *(undefined4 *)(this->_padding_ + 4),0,0);
          (**(code **)(this->_padding_ + 0x5c))(2);
          return '\0';
        }
        break;
      case '\n':
        if ((RGE_Static_Object *)this->_padding_ != (RGE_Static_Object *)0x0) {
          fVar1 = (float)this->_padding_ -
                  ((RGE_Static_Object *)this->_padding_)->owner->world->world_time_delta_seconds;
          this->_padding_ = (int)fVar1;
          if (fVar1 <= fVar6) {
            fVar6 = RGE_Static_Object::distance_to_object
                              ((RGE_Static_Object *)this->_padding_,
                               (RGE_Static_Object *)this->_padding_);
            DAT_0086bc08._0_4_ = fVar6 - _DAT_0057526c;
            if ((float)DAT_0086bc08 <= (float)_DAT_00575270) {
              (**(code **)(this->_padding_ + 0x5c))(6);
              return '\0';
            }
            this->_padding_ = 0x3f800000;
            return '\0';
          }
        }
        break;
      case '\v':
        uVar2 = (**(code **)(*(int *)this->_padding_ + 0xc))();
        switch(uVar2) {
        case 1:
        case 2:
        case 3:
        case 5:
          (**(code **)(this->_padding_ + 0x5c))(1);
          return '\0';
        case 4:
          iVar5 = this->_padding_;
          (**(code **)(iVar5 + 0x54))(0);
          (**(code **)(iVar5 + 0x5c))(0xb);
          return '\0';
        }
        break;
      case '\r':
        iVar5 = ((int *)this->_padding_)[1];
        (**(code **)(*(int *)this->_padding_ + 0x148))(iVar5,iVar5,0x1f9,0x26a,0,0);
        (**(code **)(this->_padding_ + 0x5c))(2);
        return '\x03';
      }
      return '\0';
    }
  }
switchD_004d1c93_caseD_3:
  iVar5 = this->_padding_;
  (**(code **)(iVar5 + 0x54))(0);
  (**(code **)(iVar5 + 0x5c))(1);
  return '\0';
}

// --------------------------------------------------

// Function: stop
// Address: 004d1f50
int __thiscall TRIBE_Action_Repair::stop(TRIBE_Action_Repair *this)
{
  (**(code **)(this->_padding_ + 0x5c))(2);
  return 1;
}

// --------------------------------------------------

// Function: move_to
// Address: 004d1f60
int __thiscall
TRIBE_Action_Repair::move_to
          (TRIBE_Action_Repair *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  int iVar1;
  
  iVar1 = this->_padding_;
  this->_padding_ = (int)param_3;
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)param_4;
  (**(code **)(iVar1 + 0x54))(0);
  (**(code **)(iVar1 + 0x5c))(0xb);
  return 1;
}

// --------------------------------------------------

// Function: work
// Address: 004d1fa0
int __thiscall
TRIBE_Action_Repair::work
          (TRIBE_Action_Repair *this,RGE_Static_Object *param_1,float param_2,float param_3,
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
          ((cVar1 = (char)this->_padding_, cVar1 != '\x04' && (cVar1 != '\x06')))) {
    iVar2 = this->_padding_;
    (**(code **)(iVar2 + 0x54))(param_1);
    this->_padding_ = (int)param_1->world_x;
    this->_padding_ = (int)param_1->world_y;
    this->_padding_ = (int)param_1->world_z;
    meet_target(this);
    (**(code **)(iVar2 + 0x5c))(4);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: meet_target
// Address: 004d2020
void __thiscall TRIBE_Action_Repair::meet_target(TRIBE_Action_Repair *this)
{
  short sVar1;
  int *piVar2;
  int *piVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  RGE_Action *pRVar8;
  float fVar9;
  int iStack_20;
  XYPoint dest;
  XYPoint start;
  XYPoint rVal;
  
  sVar1 = *(short *)(*(int *)(this->_padding_ + 8) + 0x14);
  if ((((sVar1 == 2) || (sVar1 == 0x14)) || (sVar1 == 0x15)) || (sVar1 == 0x16)) {
    for (piVar2 = *(int **)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x28) + 4);
        piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
      piVar3 = (int *)*piVar2;
      if ((piVar3 != (int *)this->_padding_) && (*(short *)(piVar3[2] + 0x10) == 0x9c)) {
        iVar7 = *piVar3;
        iVar6 = (**(code **)(iVar7 + 0xcc))();
        if ((iVar6 == this->_padding_) && (cVar5 = (**(code **)(iVar7 + 0x134))(), cVar5 != '\x02'))
{
          cVar5 = (**(code **)(*(int *)this->_padding_ + 0x134))();
          if (cVar5 != '\v') {
            this->_padding_ = *(int *)(this->_padding_ + 0x38);
            this->_padding_ = *(int *)(this->_padding_ + 0x3c);
            return;
          }
          pRVar8 = RGE_Action_List::get_action(*(RGE_Action_List **)(this->_padding_ + 0x184));
          fVar9 = RGE_Action::targetX(pRVar8);
          this->_padding_ = (int)fVar9;
          pRVar8 = RGE_Action_List::get_action(*(RGE_Action_List **)(this->_padding_ + 0x184));
          fVar9 = RGE_Action::targetY(pRVar8);
          this->_padding_ = (int)fVar9;
          return;
        }
      }
    }
    piVar2 = (int *)this->_padding_;
    start.y = __ftol();
    rVal.x = __ftol();
    dest.y = __ftol();
    start.x = __ftol();
    iVar7 = (**(code **)(*piVar2 + 0x1b4))(&start.y,&dest.y,&rVal.y,2,2,1);
    if (iVar7 == 1) {
      fVar9 = (float)iStack_20 - _DAT_0057527c;
      iVar7 = *(int *)this->_padding_;
      this->_padding_ = (int)fVar9;
      fVar4 = (float)dest.x - _DAT_0057527c;
      this->_padding_ = (int)fVar4;
      (**(code **)(iVar7 + 0x154))(fVar9,fVar4,((int *)this->_padding_)[0x10],0,1);
      this->save_target_command_flag = *(uchar *)(this->_padding_ + 0x188);
    }
  }
  return;
}

// --------------------------------------------------

