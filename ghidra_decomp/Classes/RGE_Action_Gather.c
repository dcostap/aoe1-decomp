// Class: RGE_Action_Gather
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
// [0x040] int targetType
// ----------------------------------------------------------------

// Function: RGE_Action_Gather
// Address: 00402ea0
RGE_Action_Gather * __thiscall
RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Gather *this,int param_1,RGE_Action_Object *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c198;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 5;
  rge_read(param_1,&this->targetType,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00402f10
void * __thiscall
RGE_Action_Gather::_vector_deleting_destructor_(RGE_Action_Gather *this,uint param_1)
{
  ~RGE_Action_Gather(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Gather
// Address: 00402f30
void __thiscall RGE_Action_Gather::~RGE_Action_Gather(RGE_Action_Gather *this)
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

// Function: RGE_Action_Gather
// Address: 00402f40
RGE_Action_Gather * __thiscall
RGE_Action_Gather::RGE_Action_Gather
          (RGE_Action_Gather *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c1b8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 5;
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  if (param_3 != (RGE_Static_Object *)0x0) {
    this->_padding_ = (int)param_3->world_x;
    this->_padding_ = (int)param_3->world_y;
    this->_padding_ = (int)param_3->world_z;
    this->targetType = (int)param_3->master_obj->id;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Action_Gather
// Address: 00402fd0
RGE_Action_Gather * __thiscall
RGE_Action_Gather::RGE_Action_Gather
          (RGE_Action_Gather *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)param_4;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 5;
  this->_padding_ = (int)param_3;
  this->_padding_ = (int)param_5;
  this->targetType = -1;
  return this;
}

// --------------------------------------------------

// Function: save
// Address: 00403020
void __thiscall RGE_Action_Gather::save(RGE_Action_Gather *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->targetType,4);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 00403050
void __thiscall RGE_Action_Gather::first_in_stack(RGE_Action_Gather *this,uchar param_1)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = *(short *)(this->_padding_ + 0x14);
  if ((short)((int *)this->_padding_)[0x13] != sVar1) {
    (**(code **)(*(int *)this->_padding_ + 0x80))
              (CONCAT22((short)((uint)this->_padding_ >> 0x10),sVar1),0);
  }
  if (param_1 != '\0') {
    iVar2 = this->_padding_;
    if (iVar2 == 0) {
      (**(code **)(this->_padding_ + 0x5c))(3);
      return;
    }
    iVar3 = this->_padding_;
    if (*(int *)(iVar2 + 0xc) == *(int *)(iVar3 + 0xc)) {
      sVar1 = *(short *)(*(int *)(iVar2 + 8) + 0x10);
      if (((sVar1 == *(short *)(*(int *)(iVar3 + 8) + 0xe8)) ||
          (sVar1 == *(short *)(*(int *)(iVar3 + 8) + 0xea))) &&
         ((float)DAT_0056e278._0_4_ < *(float *)(iVar3 + 0x44))) {
        iVar3 = this->_padding_;
        (**(code **)(iVar3 + 0x58))(iVar2);
        (**(code **)(iVar3 + 0x54))(0);
        this->_padding_ = -0x40800000;
        this->_padding_ = -0x40800000;
        this->_padding_ = -0x40800000;
        (**(code **)(iVar3 + 0x5c))(8);
        return;
      }
    }
    (**(code **)(this->_padding_ + 0x5c))(4);
    return;
  }
  (**(code **)(this->_padding_ + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 00403110
void __thiscall RGE_Action_Gather::set_state(RGE_Action_Gather *this,uchar param_1)
{
  short sVar1;
  RGE_Sound *this_00;
  int *piVar2;
  RGE_Master_Static_Object *pRVar3;
  char cVar4;
  RGE_Action_Move_To *pRVar5;
  RGE_Sprite *pRVar6;
  RGE_Action *pRVar7;
  RGE_Static_Object *pRVar8;
  int unaff_ESI;
  int iVar9;
  int *unaff_FS_OFFSET;
  int local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c1f1;
  *unaff_FS_OFFSET = (int)&local_c;
  RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
  *(uchar *)&this->_padding_ = param_1;
  switch(param_1 - 1) {
  case 0:
  case 0xc:
  case 0xd:
    this->_padding_ = 0;
    break;
  case 1:
    this->_padding_ = 0;
    iVar9 = *(int *)this->_padding_;
    pRVar6 = get_wait_sprite(this);
    (**(code **)(iVar9 + 0x38))();
    iVar9 = this->_padding_;
    (**(code **)(iVar9 + 0x54))(0);
    (**(code **)(iVar9 + 0x58))(0);
    this->_padding_ = -0x40800000;
    this->_padding_ = -0x40800000;
    this->_padding_ = -0x40800000;
    *unaff_FS_OFFSET = (int)pRVar6;
    return;
  case 2:
    iVar9 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar9,iVar9,0x202,0x261,this->targetType,0);
    this->_padding_ = -0x3ee00000;
    break;
  case 3:
    iVar9 = this->_padding_;
    this->_padding_ = 0;
    if (iVar9 == 0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    this->_padding_ = *(int *)(iVar9 + 0x38);
    this->_padding_ = *(int *)(iVar9 + 0x3c);
    this->_padding_ = *(int *)(iVar9 + 0x40);
    pRVar5 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 1;
    if (pRVar5 != (RGE_Action_Move_To *)0x0) {
      pRVar6 = get_move_sprite(this);
      pRVar7 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar5,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,*(float *)(this->_padding_ + 0x24),
                          pRVar6);
      goto LAB_0040344b;
    }
    goto LAB_00403449;
  default:
    goto switchD_00403147_caseD_4;
  case 5:
    this->_padding_ = 0;
    iVar9 = *(int *)this->_padding_;
    pRVar6 = get_move_sprite(this);
    goto LAB_00403535;
  case 6:
    this->_padding_ = 0;
    sVar1 = *(short *)(this->_padding_ + 0x14);
    if ((short)((int *)this->_padding_)[0x13] != sVar1) {
      (**(code **)(*(int *)this->_padding_ + 0x80))(CONCAT22((short)(param_1 - 1 >> 0x10),sVar1),0);
    }
    (**(code **)(*(int *)this->_padding_ + 0x38))(*(undefined4 *)(this->_padding_ + 0x38));
    this_00 = *(RGE_Sound **)(this->_padding_ + 0x44);
    if (this_00 != (RGE_Sound *)0x0) {
      RGE_Sound::play(this_00,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    goto switchD_00403147_caseD_4;
  case 7:
    piVar2 = (int *)this->_padding_;
    if ((float)piVar2[0x11] <= (float)DAT_0056e278._0_4_) {
      iVar9 = this->_padding_;
      if (((iVar9 != 0) && (*(float *)(iVar9 + 0x44) <= (float)DAT_0056e278._0_4_)) &&
         (cVar4 = (**(code **)(*piVar2 + 0x138))((int)*(short *)(*(int *)(iVar9 + 8) + 0x10)),
         cVar4 == '\0')) {
        (**(code **)(this->_padding_ + 0x54))(0);
      }
      (**(code **)(this->_padding_ + 0x5c))(3);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    if (this->_padding_ == 0) {
      if (*(short *)(piVar2[2] + 0xe8) == -1) {
        (**(code **)(this->_padding_ + 0x58))(0);
      }
      else {
        cVar4 = (**(code **)(*piVar2 + 0x140))();
        iVar9 = this->_padding_;
        pRVar8 = (RGE_Static_Object *)this->_padding_;
        pRVar3 = pRVar8->master_obj;
        if (cVar4 == '\x01') {
          pRVar8 = RGE_Object_List::find_by_master_ids
                             (pRVar8->owner->objects,(int)*(short *)&pRVar3[1].radius_x,
                              (int)*(short *)((int)&pRVar3[1].radius_x + 2),pRVar8->world_x,
                              pRVar8->world_y,'\x01','\x02',pRVar8);
          (**(code **)(iVar9 + 0x58))(pRVar8);
        }
        else {
          pRVar8 = RGE_Object_List::find_by_master_ids
                             (pRVar8->owner->objects,(int)*(short *)&pRVar3[1].radius_x,
                              (int)*(short *)((int)&pRVar3[1].radius_x + 2),pRVar8->world_x,
                              pRVar8->world_y,'\x01','\x02',(RGE_Static_Object *)0x0);
          (**(code **)(iVar9 + 0x58))(pRVar8);
        }
      }
      if (this->_padding_ == 0) {
        iVar9 = ((int *)this->_padding_)[1];
        (**(code **)(*(int *)this->_padding_ + 0x148))(iVar9,iVar9,0x203,0x261,0,0);
        (**(code **)(this->_padding_ + 0x5c))(0xd);
        *unaff_FS_OFFSET = iVar9;
        return;
      }
    }
    pRVar5 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 2;
    if (pRVar5 != (RGE_Action_Move_To *)0x0) {
      pRVar6 = get_move_sprite(this);
      pRVar7 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar5,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,*(float *)(this->_padding_ + 0x24),
                          pRVar6);
      goto LAB_0040344b;
    }
LAB_00403449:
    pRVar7 = (RGE_Action *)0x0;
LAB_0040344b:
    local_4 = 0xffffffff;
    if (pRVar7 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar7);
    RGE_Action::setSubAction(pRVar7,'\x01');
    *unaff_FS_OFFSET = local_c;
    return;
  case 10:
  case 0xe:
    this->_padding_ = 0;
    pRVar5 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar5 == (RGE_Action_Move_To *)0x0) {
      pRVar7 = (RGE_Action *)0x0;
    }
    else {
      pRVar6 = get_move_sprite(this);
      pRVar7 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar5,(RGE_Action_Object *)this->_padding_,(float)this->_padding_,
                          (float)this->_padding_,(float)this->_padding_,
                          *(float *)(this->_padding_ + 0x24),pRVar6);
    }
    local_4 = 0xffffffff;
    if (pRVar7 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action::setSubAction(pRVar7,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar7);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  iVar9 = *(int *)this->_padding_;
  pRVar6 = get_wait_sprite(this);
LAB_00403535:
  (**(code **)(iVar9 + 0x38))(pRVar6);
switchD_00403147_caseD_4:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00403590
uchar __thiscall RGE_Action_Gather::update(RGE_Action_Gather *this)
{
  short sVar1;
  int *piVar2;
  RGE_Sound *this_00;
  int iVar3;
  float fVar4;
  undefined1 uVar5;
  char cVar6;
  RGE_Static_Object *pRVar7;
  undefined4 uVar8;
  int iVar9;
  RGE_Player *this_01;
  short unaff_BX;
  undefined4 unaff_ESI;
  float unaff_EDI;
  float fVar10;
  float give_amount;
  float modifier;
  float fStack_8;
  
  if ((this->_padding_ != -1) &&
     (pRVar7 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar7 == (RGE_Static_Object *)0x0)) {
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if ((this->_padding_ != -1) &&
     (pRVar7 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar7 == (RGE_Static_Object *)0x0)) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  if ((this->_padding_ != 0) && (6 < *(byte *)(this->_padding_ + 0x48))) {
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if ((this->_padding_ != 0) && (6 < *(byte *)(this->_padding_ + 0x48))) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  piVar2 = (int *)this->_padding_;
  if (((piVar2 != (int *)0x0) && (*(short *)(piVar2[3] + 0x4a) != 0)) &&
     (*(short *)(piVar2[3] + 0x4a) != *(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a))) {
    (**(code **)(this->_padding_ + 0x5c))(1);
    iVar9 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar9,iVar9,0x1fb,0x261,0,0);
    return '\x04';
  }
  switch((char)this->_padding_) {
  case '\x01':
    return '\x01';
  case '\x03':
    if ((float)this->_padding_ < (float)(double)DAT_0056e278._8_8_) {
      piVar2 = (int *)this->_padding_;
      fVar10 = *(float *)(*(int *)(piVar2[3] + 0x3c) + 0x84) + (float)this->_padding_;
      fVar4 = (float)(double)DAT_0056e278._8_8_;
      this->_padding_ = (int)fVar10;
      if (fVar4 < fVar10) {
        iVar9 = *piVar2;
        this->_padding_ = -0x3ee00000;
        (**(code **)(iVar9 + 0x148))(piVar2[1],piVar2[1],0x202,0x261,this->targetType,0);
        return '\0';
      }
    }
    break;
  case '\x04':
    uVar5 = (**(code **)(*(int *)this->_padding_ + 0xc))();
    switch(uVar5) {
    case 1:
    case 2:
      (**(code **)(this->_padding_ + 0x5c))(6);
      return '\0';
    case 3:
      this_01 = *(RGE_Player **)(this->_padding_ + 0xc);
      break;
    case 4:
    case 5:
      iVar9 = this->_padding_;
      (**(code **)(iVar9 + 0x54))(0);
      (**(code **)(iVar9 + 0x5c))(0xb);
      return '\0';
    default:
      goto switchD_0040366f_caseD_1;
    }
    goto LAB_00403790;
  case '\x06':
    if (piVar2 == (int *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(3);
      return '\0';
    }
    cVar6 = (**(code **)(*(int *)this->_padding_ + 0x1f0))(piVar2,0,0);
    if (cVar6 != '\0') {
      if ((*(float *)(this->_padding_ + 0x44) <= (float)DAT_0056e278._0_4_) &&
         (cVar6 = (**(code **)(*(int *)this->_padding_ + 0x138))
                            ((int)*(short *)(*(int *)(this->_padding_ + 8) + 0x10)), cVar6 == '\0'))
{
        iVar9 = this->_padding_;
        (**(code **)(iVar9 + 0x54))(0);
        (**(code **)(iVar9 + 0x5c))(3);
        return '\0';
      }
      (**(code **)(this->_padding_ + 0x5c))(7);
      return '\0';
    }
    break;
  case '\a':
    if (piVar2 != (int *)0x0) {
      if (rge_base_game->quick_build == 0) {
        fVar10 = *(float *)(this->_padding_ + 0x1c) *
                 *(float *)(*(int *)(this->_padding_ + 8) + 0xe4) *
                 *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84);
      }
      else {
        fVar10 = (float)piVar2[0x11];
      }
      if ((float)piVar2[0x11] < fVar10) {
        fVar10 = (float)piVar2[0x11];
      }
      sVar1 = *(short *)(this->_padding_ + 0x16);
      if (sVar1 == -1) {
        fStack_8 = 1.0;
      }
      else {
        fStack_8 = *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x50) + sVar1 * 4);
      }
      fVar4 = (float)(int)*(short *)(*(int *)(this->_padding_ + 8) + 0x7c) * fStack_8 -
              *(float *)(this->_padding_ + 0x44);
      if (fVar4 < fStack_8 * fVar10) {
        fVar10 = fVar10 - (fStack_8 * fVar10 - fVar4) / fStack_8;
      }
      (**(code **)(*piVar2 + 0x84))(-fVar10,1,1);
      (**(code **)(*(int *)this->_padding_ + 0x84))(unaff_ESI,1,0);
      if ((float)((int *)this->_padding_)[0x11] < unaff_EDI) {
        if ((float)DAT_0056e278._0_4_ < *(float *)(this->_padding_ + 0x44)) {
          return '\0';
        }
        cVar6 = (**(code **)(*(int *)this->_padding_ + 0x138))
                          ((int)*(short *)(*(int *)(this->_padding_ + 8) + 0x10));
        if (cVar6 != '\0') {
          return '\0';
        }
      }
      (**(code **)(this->_padding_ + 0x5c))(8);
      return '\0';
    }
    if ((float)DAT_0056e278._0_4_ < *(float *)(this->_padding_ + 0x44)) {
      (**(code **)(this->_padding_ + 0x5c))(8);
      return '\0';
    }
    goto LAB_00403875;
  case '\b':
    if ((float)(double)DAT_0056e278._8_8_ <= (float)this->_padding_) {
      uVar5 = (**(code **)(*(int *)this->_padding_ + 0xc))();
      switch(uVar5) {
      case 1:
      case 2:
        if ((RGE_Static_Object *)this->_padding_ == (RGE_Static_Object *)0x0) {
          (**(code **)(this->_padding_ + 0x5c))(8);
          return '\0';
        }
        fVar10 = RGE_Static_Object::distance_to_object
                           ((RGE_Static_Object *)this->_padding_,
                            (RGE_Static_Object *)this->_padding_);
        if ((float)_DAT_0056e290 < fVar10) {
          this->_padding_ = -0x3fc00000;
          (**(code **)(*(int *)this->_padding_ + 0x1ec))();
          return '\0';
        }
        this_00 = *(RGE_Sound **)(this->_padding_ + 0x48);
        if (this_00 != (RGE_Sound *)0x0) {
          RGE_Sound::play(this_00,1);
        }
        sVar1 = *(short *)(this->_padding_ + 0x18);
        if (sVar1 == -1) {
          sVar1 = *(short *)(this->_padding_ + 0x4c);
        }
        (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x78))
                  (CONCAT22((short)((uint)this->_padding_ >> 0x10),sVar1),
                   *(undefined4 *)(this->_padding_ + 0x44),1);
        iVar9 = this->_padding_;
        iVar3 = **(int **)(iVar9 + 0xc);
        uVar8 = __ftol();
        (**(code **)(iVar3 + 0x5c))(*(undefined4 *)(iVar9 + 4),(int)unaff_BX,uVar8);
        (**(code **)(*(int *)this->_padding_ + 0x80))(0xffffffff,0);
        if (this->_padding_ != 0) {
          iVar9 = this->_padding_;
          (**(code **)(iVar9 + 0x58))(0);
          (**(code **)(iVar9 + 0x5c))(4);
          return '\0';
        }
        if ((this->_padding_ != -0x40800000) && (this->_padding_ != -0x40800000)) {
          (**(code **)(this->_padding_ + 0x5c))(0xb);
          return '\0';
        }
        goto LAB_00403b35;
      case 3:
      case 4:
      case 5:
        this->_padding_ = -0x3fc00000;
        (**(code **)(*(int *)this->_padding_ + 0x1ec))();
        return '\0';
      }
    }
    else {
      fVar10 = *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84) +
               (float)this->_padding_;
      fVar4 = (float)(double)DAT_0056e278._8_8_;
      this->_padding_ = (int)fVar10;
      if (fVar4 < fVar10) {
        this->_padding_ = 0;
        (**(code **)(this->_padding_ + 0x5c))(8);
        return '\0';
      }
    }
    break;
  case '\v':
  case '\x0f':
    uVar5 = (**(code **)(*(int *)this->_padding_ + 0xc))();
    switch(uVar5) {
    case 1:
    case 2:
    case 5:
      if ((char)this->_padding_ == '\v') {
        (**(code **)(this->_padding_ + 0x5c))(3);
        return '\0';
      }
LAB_00403b35:
      iVar9 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + 0xc));
      if (iVar9 != 1) {
        (**(code **)(this->_padding_ + 0x5c))(2);
        return '\0';
      }
      (**(code **)(this->_padding_ + 0x5c))(1);
      return '\0';
    case 3:
      this_01 = *(RGE_Player **)(this->_padding_ + 0xc);
      break;
    case 4:
      iVar9 = this->_padding_;
      (**(code **)(iVar9 + 0x54))(0);
      if ((char)this->_padding_ != '\v') {
        (**(code **)(iVar9 + 0x5c))(0xf);
        return '\0';
      }
      (**(code **)(iVar9 + 0x5c))(0xb);
      return '\0';
    default:
      goto switchD_0040366f_caseD_1;
    }
LAB_00403790:
    iVar9 = RGE_Player::computerPlayer(this_01);
    if (iVar9 == 1) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      return '\0';
    }
LAB_00403875:
    (**(code **)(this->_padding_ + 0x5c))(3);
    return '\0';
  case '\r':
    iVar9 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar9,iVar9,0x1f9,0x261,0,0);
    iVar9 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + 0xc));
    if (iVar9 != 1) {
      (**(code **)(this->_padding_ + 0x5c))(2);
      return '\x03';
    }
    (**(code **)(this->_padding_ + 0x5c))(1);
    return '\x03';
  }
switchD_0040366f_caseD_1:
  return '\0';
}

// --------------------------------------------------

// Function: get_move_sprite
// Address: 00403c60
RGE_Sprite * __thiscall RGE_Action_Gather::get_move_sprite(RGE_Action_Gather *this)
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
// Address: 00403c90
RGE_Sprite * __thiscall RGE_Action_Gather::get_wait_sprite(RGE_Action_Gather *this)
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
// Address: 00403cd0
int __thiscall RGE_Action_Gather::stop(RGE_Action_Gather *this)
{
  (**(code **)(this->_padding_ + 0x5c))(2);
  return 1;
}

// --------------------------------------------------

// Function: move_to
// Address: 00403ce0
int __thiscall
RGE_Action_Gather::move_to
          (RGE_Action_Gather *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  short sVar1;
  int iVar2;
  
  if ((param_1 != (RGE_Static_Object *)0x0) &&
     (iVar2 = this->_padding_, param_1->owner == *(RGE_Player **)(iVar2 + 0xc))) {
    sVar1 = param_1->master_obj->id;
    if (((sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xe8)) ||
        (sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xea))) &&
       ((float)DAT_0056e278._0_4_ < *(float *)(iVar2 + 0x44))) {
      if ((param_1 == (RGE_Static_Object *)this->_padding_) && ((char)this->_padding_ == '\b')) {
        return 1;
      }
      iVar2 = this->_padding_;
      (**(code **)(iVar2 + 0x54))(0);
      this->_padding_ = -0x40800000;
      this->_padding_ = -0x40800000;
      this->_padding_ = -0x40800000;
      (**(code **)(iVar2 + 0x58))(param_1);
      (**(code **)(iVar2 + 0x5c))(8);
      return 1;
    }
  }
  iVar2 = this->_padding_;
  this->_padding_ = (int)param_4;
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)param_3;
  (**(code **)(iVar2 + 0x54))(0);
  (**(code **)(iVar2 + 0x5c))(0xf);
  return 1;
}

// --------------------------------------------------

// Function: work
// Address: 00403d90
int __thiscall
RGE_Action_Gather::work
          (RGE_Action_Gather *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  char cVar1;
  short sVar2;
  int iVar3;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    iVar3 = this->_padding_;
    this->_padding_ = (int)param_4;
    this->_padding_ = (int)param_2;
    this->_padding_ = (int)param_3;
    (**(code **)(iVar3 + 0x54))(0);
    (**(code **)(iVar3 + 0x5c))(0xf);
  }
  else if ((param_1 != (RGE_Static_Object *)this->_padding_) ||
          (((cVar1 = (char)this->_padding_, cVar1 != '\x04' && (cVar1 != '\x06')) && (cVar1 != '\a')
           ))) {
    iVar3 = this->_padding_;
    if (param_1->owner == *(RGE_Player **)(iVar3 + 0xc)) {
      sVar2 = param_1->master_obj->id;
      if (((sVar2 == *(short *)(*(int *)(iVar3 + 8) + 0xe8)) ||
          (sVar2 == *(short *)(*(int *)(iVar3 + 8) + 0xea))) &&
         ((float)DAT_0056e278._0_4_ < *(float *)(iVar3 + 0x44))) {
        iVar3 = this->_padding_;
        this->_padding_ = 0;
        (**(code **)(iVar3 + 0x54))(0);
        this->_padding_ = -0x40800000;
        this->_padding_ = -0x40800000;
        this->_padding_ = -0x40800000;
        (**(code **)(iVar3 + 0x58))(param_1);
        (**(code **)(iVar3 + 0x5c))(8);
        return 1;
      }
    }
    iVar3 = this->_padding_;
    (**(code **)(iVar3 + 0x54))(param_1);
    this->_padding_ = (int)param_1->world_x;
    this->_padding_ = (int)param_1->world_y;
    this->_padding_ = (int)param_1->world_z;
    (**(code **)(iVar3 + 0x58))(0);
    (**(code **)(iVar3 + 0x5c))(4);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

