// Class: TRIBE_Action_Hunt
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
// [0x040] int targetType
// ----------------------------------------------------------------

// Function: TRIBE_Action_Hunt
// Address: 004cf090
TRIBE_Action_Hunt * __thiscall
TRIBE_Action_Hunt::TRIBE_Action_Hunt(TRIBE_Action_Hunt *this,int param_1,RGE_Action_Object *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fea8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6e;
  rge_read(param_1,&this->targetType,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004cf100
void * __thiscall
TRIBE_Action_Hunt::_scalar_deleting_destructor_(TRIBE_Action_Hunt *this,uint param_1)
{
  ~TRIBE_Action_Hunt(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Hunt
// Address: 004cf120
void __thiscall TRIBE_Action_Hunt::~TRIBE_Action_Hunt(TRIBE_Action_Hunt *this)
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

// Function: TRIBE_Action_Hunt
// Address: 004cf130
TRIBE_Action_Hunt * __thiscall
TRIBE_Action_Hunt::TRIBE_Action_Hunt
          (TRIBE_Action_Hunt *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fec8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6e;
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  if ((param_3 != (RGE_Static_Object *)0x0) && (param_3->object_state < 7)) {
    this->_padding_ = (int)param_3->world_x;
    this->_padding_ = (int)param_3->world_y;
    this->_padding_ = (int)param_3->world_z;
    this->targetType = (int)param_3->master_obj->id;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Hunt
// Address: 004cf1c0
TRIBE_Action_Hunt * __thiscall
TRIBE_Action_Hunt::TRIBE_Action_Hunt
          (TRIBE_Action_Hunt *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)param_4;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x6e;
  this->_padding_ = (int)param_3;
  this->_padding_ = (int)param_5;
  this->targetType = -1;
  return this;
}

// --------------------------------------------------

// Function: save
// Address: 004cf210
void __thiscall TRIBE_Action_Hunt::save(TRIBE_Action_Hunt *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->targetType,4);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004cf240
void __thiscall TRIBE_Action_Hunt::first_in_stack(TRIBE_Action_Hunt *this,uchar param_1)
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
         ((float)DAT_00575150._0_4_ < *(float *)(iVar3 + 0x44))) {
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
// Address: 004cf300
void __thiscall TRIBE_Action_Hunt::set_state(TRIBE_Action_Hunt *this,uchar param_1)
{
  RGE_Sound *this_00;
  RGE_Action_Move_To *pRVar1;
  RGE_Sprite *pRVar2;
  RGE_Action *pRVar3;
  RGE_Action_Attack *this_01;
  RGE_Sprite *pRVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  undefined4 unaff_EBX;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  RGE_Sprite *pRVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  short sVar11;
  short sVar12;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ff0c;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
  *(uchar *)&this->_padding_ = param_1;
  switch(param_1 - 1) {
  case 0:
  case 0xc:
  case 0xd:
    this->_padding_ = 0;
    iVar6 = *(int *)this->_padding_;
    pRVar2 = get_wait_sprite(this);
    goto LAB_004cf805;
  case 1:
    iVar6 = *(int *)this->_padding_;
    pRVar2 = get_wait_sprite(this);
    (**(code **)(iVar6 + 0x38))(pRVar2);
    iVar6 = this->_padding_;
    (**(code **)(iVar6 + 0x54))(0);
    (**(code **)(iVar6 + 0x58))(0);
    this->_padding_ = 0;
    this->_padding_ = -0x40800000;
    this->_padding_ = -0x40800000;
    this->_padding_ = -0x40800000;
    *unaff_FS_OFFSET = unaff_EDI;
    return;
  case 2:
    iVar6 = ((int *)this->_padding_)[1];
    uVar9 = 0x202;
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar6,iVar6,0x202,0x265,this->targetType,0);
    iVar6 = *(int *)this->_padding_;
    pRVar2 = get_wait_sprite(this);
    (**(code **)(iVar6 + 0x38))(pRVar2);
    this->_padding_ = -0x3ee00000;
    *unaff_FS_OFFSET = uVar9;
    return;
  case 3:
    iVar6 = this->_padding_;
    this->_padding_ = 0;
    if (iVar6 == 0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    this->_padding_ = *(int *)(iVar6 + 0x38);
    this->_padding_ = *(int *)(iVar6 + 0x3c);
    this->_padding_ = *(int *)(iVar6 + 0x40);
    if (*(byte *)(iVar6 + 0x48) < 3) {
      (**(code **)(this->_padding_ + 0x5c))(0xc);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 1;
    if (pRVar1 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar2 = get_move_sprite(this);
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar1,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,*(float *)(this->_padding_ + 0x24),
                          pRVar2);
    }
    local_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    break;
  default:
    goto switchD_004cf338_caseD_4;
  case 5:
    this->_padding_ = 0;
    iVar6 = *(int *)this->_padding_;
    pRVar2 = get_move_sprite(this);
LAB_004cf805:
    (**(code **)(iVar6 + 0x38))(pRVar2);
switchD_004cf338_caseD_4:
    *unaff_FS_OFFSET = local_c;
    return;
  case 6:
    this->_padding_ = 0;
    sVar12 = *(short *)(this->_padding_ + 0x14);
    if ((short)((int *)this->_padding_)[0x13] != sVar12) {
      (**(code **)(*(int *)this->_padding_ + 0x80))(CONCAT22((short)(param_1 - 1 >> 0x10),sVar12),0)
      ;
    }
    (**(code **)(*(int *)this->_padding_ + 0x38))(*(undefined4 *)(this->_padding_ + 0x3c));
    this_00 = *(RGE_Sound **)(this->_padding_ + 0x44);
    if (this_00 != (RGE_Sound *)0x0) {
      RGE_Sound::play(this_00,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    goto switchD_004cf338_caseD_4;
  case 7:
    pRVar5 = (RGE_Static_Object *)this->_padding_;
    if (pRVar5->attribute_amount_held <= (float)DAT_00575150._0_4_) {
      if ((this->_padding_ != 0) &&
         (*(float *)(this->_padding_ + 0x44) <= (float)DAT_00575150._0_4_)) {
        (**(code **)(this->_padding_ + 0x54))(0);
      }
      (**(code **)(this->_padding_ + 0x5c))(3);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    if (this->_padding_ == 0) {
      sVar12 = *(short *)&pRVar5->master_obj[1].radius_x;
      if (sVar12 == -1) {
        (**(code **)(this->_padding_ + 0x58))(0);
      }
      else {
        iVar6 = this->_padding_;
        pRVar5 = RGE_Object_List::find_by_master_ids
                           (pRVar5->owner->objects,(int)sVar12,
                            (int)*(short *)((int)&pRVar5->master_obj[1].radius_x + 2),
                            pRVar5->world_x,pRVar5->world_y,'\x01','\x02',pRVar5);
        (**(code **)(iVar6 + 0x58))(pRVar5);
      }
      if (this->_padding_ == 0) {
        iVar6 = ((int *)this->_padding_)[1];
        uVar9 = 0x203;
        (**(code **)(*(int *)this->_padding_ + 0x148))(iVar6,iVar6,0x203,0x265,0,0);
        iVar6 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + 0xc));
        if (iVar6 == 0) {
          (**(code **)(this->_padding_ + 0x5c))(2);
          *unaff_FS_OFFSET = uVar9;
          return;
        }
        (**(code **)(this->_padding_ + 0x5c))(1);
        *unaff_FS_OFFSET = uVar9;
        return;
      }
    }
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 3;
    if (pRVar1 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar2 = get_move_sprite(this);
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar1,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,*(float *)(this->_padding_ + 0x24),
                          pRVar2);
    }
    local_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    break;
  case 10:
  case 0xe:
    this->_padding_ = 0;
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar1 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar2 = get_move_sprite(this);
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar1,(RGE_Action_Object *)this->_padding_,(float)this->_padding_,
                          (float)this->_padding_,(float)this->_padding_,
                          *(float *)(this->_padding_ + 0x24),pRVar2);
    }
    local_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    RGE_Action::setSubAction(pRVar3,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar3);
    *unaff_FS_OFFSET = local_c;
    return;
  case 0xb:
    this->_padding_ = 0;
    this_01 = (RGE_Action_Attack *)operator_new(0x5c);
    local_4 = 2;
    if (this_01 == (RGE_Action_Attack *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      iVar6 = *(int *)(this->_padding_ + 8);
      sVar12 = *(short *)(iVar6 + 0x12a);
      sVar11 = *(short *)(iVar6 + 0x124);
      fVar10 = *(float *)(iVar6 + 0x138);
      fVar8 = *(float *)(this->_padding_ + 0x24);
      pRVar2 = *(RGE_Sprite **)(this->_padding_ + 0x38);
      pRVar7 = (RGE_Sprite *)0x0;
      pRVar4 = get_move_sprite(this);
      pRVar3 = (RGE_Action *)
               RGE_Action_Attack::RGE_Action_Attack
                         (this_01,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,pRVar4,pRVar2,pRVar7,fVar8,fVar10,
                          sVar11,sVar12);
    }
    local_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
  }
  local_4 = 0xffffffff;
  RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar3);
  RGE_Action::setSubAction(pRVar3,'\x01');
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004cf860
uchar __thiscall TRIBE_Action_Hunt::update(TRIBE_Action_Hunt *this)
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
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar10;
  short unaff_BX;
  undefined4 unaff_ESI;
  float unaff_EDI;
  float fVar11;
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
  switch((char)this->_padding_) {
  case '\x01':
    iVar9 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + 0xc));
    if (iVar9 == 0) {
      (**(code **)(this->_padding_ + 0x5c))(2);
    }
    return '\x01';
  case '\x03':
    if ((float)this->_padding_ < (float)(double)DAT_00575150._8_8_) {
      piVar2 = (int *)this->_padding_;
      fVar11 = *(float *)(*(int *)(piVar2[3] + 0x3c) + 0x84) + (float)this->_padding_;
      fVar4 = (float)(double)DAT_00575150._8_8_;
      this->_padding_ = (int)fVar11;
      if (fVar4 < fVar11) {
        iVar9 = *piVar2;
        this->_padding_ = -0x3ee00000;
        (**(code **)(iVar9 + 0x148))(piVar2[1],piVar2[1],0x202,0x265,this->targetType,0);
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
      iVar9 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + 0xc));
      if (iVar9 == 1) {
        (**(code **)(this->_padding_ + 0x5c))(0xd);
        return '\0';
      }
      goto LAB_004cfb46;
    case 4:
    case 5:
switchD_004cfa5e_caseD_3:
      iVar9 = this->_padding_;
      (**(code **)(iVar9 + 0x54))(0);
      (**(code **)(iVar9 + 0x5c))(0xb);
      return '\0';
    }
    break;
  case '\x06':
    if (this->_padding_ == 0) {
      (**(code **)(this->_padding_ + 0x5c))(3);
      return '\0';
    }
    cVar6 = (**(code **)(*(int *)this->_padding_ + 0x1f0))(this->_padding_,0,0);
    if (cVar6 != '\0') {
      if (*(float *)(this->_padding_ + 0x44) <= (float)DAT_00575150._0_4_) {
        iVar9 = this->_padding_;
        (**(code **)(iVar9 + 0x54))(0);
        (**(code **)(iVar9 + 0x5c))(3);
        return '\0';
      }
      (**(code **)(this->_padding_ + 0x5c))(7);
      return '\0';
    }
LAB_004cfb46:
    (**(code **)(this->_padding_ + 0x5c))(3);
    return '\0';
  case '\a':
    piVar2 = (int *)this->_padding_;
    if (piVar2 == (int *)0x0) {
      if ((float)DAT_00575150._0_4_ < *(float *)(this->_padding_ + 0x44)) {
        (**(code **)(this->_padding_ + 0x5c))(8);
        return '\0';
      }
      goto LAB_004cfb46;
    }
    if (rge_base_game->quick_build == 0) {
      fVar11 = *(float *)(this->_padding_ + 0x1c) * *(float *)(*(int *)(this->_padding_ + 8) + 0xe4)
               * *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84);
    }
    else {
      fVar11 = (float)piVar2[0x11];
    }
    if ((float)piVar2[0x11] < fVar11) {
      fVar11 = (float)piVar2[0x11];
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
    if (fVar4 < fStack_8 * fVar11) {
      fVar11 = fVar11 - (fStack_8 * fVar11 - fVar4) / fStack_8;
    }
    (**(code **)(*piVar2 + 0x84))(-fVar11,1,1);
    (**(code **)(*(int *)this->_padding_ + 0x84))(unaff_ESI,1,0);
    if ((unaff_EDI <= *(float *)(this->_padding_ + 0x44)) ||
       (*(float *)(this->_padding_ + 0x44) <= (float)DAT_00575150._0_4_)) {
      (**(code **)(this->_padding_ + 0x5c))(8);
      return '\0';
    }
    break;
  case '\b':
    if ((float)(double)DAT_00575150._8_8_ <= (float)this->_padding_) {
      uVar5 = (**(code **)(*(int *)this->_padding_ + 0xc))();
      switch(uVar5) {
      case 1:
      case 2:
        if ((RGE_Static_Object *)this->_padding_ == (RGE_Static_Object *)0x0) {
          (**(code **)(this->_padding_ + 0x5c))(8);
          return '\0';
        }
        fVar11 = RGE_Static_Object::distance_to_object
                           ((RGE_Static_Object *)this->_padding_,
                            (RGE_Static_Object *)this->_padding_);
        if ((float)_DAT_00575168 < fVar11) {
          this->_padding_ = -0x3fc00000;
          (**(code **)(*(int *)this->_padding_ + 0x1ec))();
          return '\0';
        }
        this_00 = *(RGE_Sound **)(this->_padding_ + 0x48);
        uVar10 = extraout_var;
        if (this_00 != (RGE_Sound *)0x0) {
          RGE_Sound::play(this_00,1);
          uVar10 = extraout_var_00;
        }
        sVar1 = *(short *)(this->_padding_ + 0x18);
        uVar8 = CONCAT22(uVar10,sVar1);
        if (sVar1 == -1) {
          uVar8 = CONCAT22((short)((uint)this->_padding_ >> 0x10),
                           *(undefined2 *)(this->_padding_ + 0x4c));
        }
        (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x78))
                  (uVar8,*(undefined4 *)(this->_padding_ + 0x44),0);
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
        goto LAB_004cfdf5;
      case 3:
      case 4:
      case 5:
        this->_padding_ = -0x3fc00000;
        (**(code **)(*(int *)this->_padding_ + 0x1ec))();
        return '\0';
      }
    }
    else {
      fVar11 = *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84) +
               (float)this->_padding_;
      fVar4 = (float)(double)DAT_00575150._8_8_;
      this->_padding_ = (int)fVar11;
      if (fVar4 < fVar11) {
        iVar9 = this->_padding_;
        this->_padding_ = 0;
        (**(code **)(iVar9 + 0x58))(0);
        (**(code **)(iVar9 + 0x5c))(8);
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
LAB_004cfdf5:
      iVar9 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + 0xc));
      if (iVar9 == 0) {
        (**(code **)(this->_padding_ + 0x5c))(2);
        return '\0';
      }
      (**(code **)(this->_padding_ + 0x5c))(1);
      return '\0';
    case 3:
      iVar9 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + 0xc));
      if (iVar9 == 1) {
        (**(code **)(this->_padding_ + 0x5c))(0xd);
        return '\0';
      }
      goto LAB_004cfb46;
    case 4:
      iVar9 = this->_padding_;
      (**(code **)(iVar9 + 0x54))(0);
      if ((char)this->_padding_ == '\v') {
        (**(code **)(iVar9 + 0x5c))(0xb);
        return '\0';
      }
      (**(code **)(iVar9 + 0x5c))(0xf);
      return '\0';
    }
    break;
  case '\f':
    uVar5 = (**(code **)(*(int *)this->_padding_ + 0xc))();
    switch(uVar5) {
    case 1:
    case 2:
    case 5:
      if (this->_padding_ != 0) {
        (**(code **)(this->_padding_ + 0x5c))(4);
        return '\0';
      }
    case 3:
      (**(code **)(this->_padding_ + 0x5c))(3);
      return '\0';
    case 4:
      goto switchD_004cfa5e_caseD_3;
    }
    break;
  case '\r':
    iVar9 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar9,iVar9,0x1f9,0x265,0,0);
    return '\x03';
  }
  return '\0';
}

// --------------------------------------------------

// Function: get_move_sprite
// Address: 004cff20
RGE_Sprite * __thiscall TRIBE_Action_Hunt::get_move_sprite(TRIBE_Action_Hunt *this)
{
  int iVar1;
  int iVar2;
  
  iVar1 = this->_padding_;
  if ((((*(short *)(iVar1 + 0x14) != -1) &&
       (*(short *)(iVar1 + 0x14) == *(short *)(this->_padding_ + 0x4c))) &&
      (iVar2 = __ftol(), 0 < iVar2)) && (*(RGE_Sprite **)(iVar1 + 0x40) != (RGE_Sprite *)0x0)) {
    return *(RGE_Sprite **)(iVar1 + 0x40);
  }
  return *(RGE_Sprite **)(iVar1 + 0x34);
}

// --------------------------------------------------

// Function: get_wait_sprite
// Address: 004cff50
RGE_Sprite * __thiscall TRIBE_Action_Hunt::get_wait_sprite(TRIBE_Action_Hunt *this)
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
// Address: 004cff90
int __thiscall TRIBE_Action_Hunt::stop(TRIBE_Action_Hunt *this)
{
  int iVar1;
  
  iVar1 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + 0xc));
  if (iVar1 == 0) {
    (**(code **)(this->_padding_ + 0x5c))(2);
    return 1;
  }
  (**(code **)(this->_padding_ + 0x5c))(1);
  return 1;
}

// --------------------------------------------------

// Function: move_to
// Address: 004cffd0
int __thiscall
TRIBE_Action_Hunt::move_to
          (TRIBE_Action_Hunt *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  short sVar1;
  int iVar2;
  
  if ((param_1 != (RGE_Static_Object *)0x0) &&
     (iVar2 = this->_padding_, param_1->owner == *(RGE_Player **)(iVar2 + 0xc))) {
    sVar1 = param_1->master_obj->id;
    if (((sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xe8)) ||
        (sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xea))) &&
       ((float)DAT_00575150._0_4_ < *(float *)(iVar2 + 0x44))) {
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
// Address: 004d0080
int __thiscall
TRIBE_Action_Hunt::work
          (TRIBE_Action_Hunt *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  short sVar1;
  int iVar2;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    iVar2 = this->_padding_;
    this->_padding_ = (int)param_4;
    this->_padding_ = (int)param_2;
    this->_padding_ = (int)param_3;
    (**(code **)(iVar2 + 0x54))(0);
    (**(code **)(iVar2 + 0x5c))(0xf);
    return 1;
  }
  iVar2 = this->_padding_;
  if (param_1->owner == *(RGE_Player **)(iVar2 + 0xc)) {
    sVar1 = param_1->master_obj->id;
    if (((sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xe8)) ||
        (sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xea))) &&
       ((float)DAT_00575150._0_4_ < *(float *)(iVar2 + 0x44))) {
      iVar2 = this->_padding_;
      (**(code **)(iVar2 + 0x54))(0);
      this->_padding_ = 0;
      this->_padding_ = -0x40800000;
      this->_padding_ = -0x40800000;
      this->_padding_ = -0x40800000;
      (**(code **)(iVar2 + 0x58))(param_1);
      (**(code **)(iVar2 + 0x5c))(8);
      return 1;
    }
  }
  iVar2 = this->_padding_;
  (**(code **)(iVar2 + 0x54))(param_1);
  (**(code **)(iVar2 + 0x58))(0);
  (**(code **)(iVar2 + 0x5c))(4);
  return 1;
}

// --------------------------------------------------

