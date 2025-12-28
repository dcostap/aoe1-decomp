// Class: TRIBE_Action_Heal
// Size:  0x40
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
// ----------------------------------------------------------------

// Function: TRIBE_Action_Heal
// Address: 004ce930
TRIBE_Action_Heal * __thiscall
TRIBE_Action_Heal::TRIBE_Action_Heal(TRIBE_Action_Heal *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0x69;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004ce960
void * __thiscall
TRIBE_Action_Heal::_scalar_deleting_destructor_(TRIBE_Action_Heal *this,uint param_1)
{
  ~TRIBE_Action_Heal(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Heal
// Address: 004ce980
void __thiscall TRIBE_Action_Heal::~TRIBE_Action_Heal(TRIBE_Action_Heal *this)
{
  RGE_Action_List *this_00;
  
  *(undefined ***)this = &RGE_Action::_vftable_;
  RGE_Action::set_target_obj((RGE_Action *)this,(RGE_Static_Object *)0x0);
  RGE_Action::set_target_obj2((RGE_Action *)this,(RGE_Static_Object *)0x0);
  this_00 = *(RGE_Action_List **)&this->field_0x34;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    *(undefined4 *)&this->field_0x34 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: TRIBE_Action_Heal
// Address: 004ce990
TRIBE_Action_Heal * __thiscall
TRIBE_Action_Heal::TRIBE_Action_Heal
          (TRIBE_Action_Heal *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe68;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  *(RGE_Task **)&this->field_0x30 = param_2;
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0x69;
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  *(float *)&this->field_0x20 = param_3->world_x;
  *(float *)&this->field_0x24 = param_3->world_y;
  *(float *)&this->field_0x28 = param_3->world_z;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Heal
// Address: 004cea10
TRIBE_Action_Heal * __thiscall
TRIBE_Action_Heal::TRIBE_Action_Heal
          (TRIBE_Action_Heal *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  *(RGE_Task **)&this->field_0x30 = param_2;
  *(float *)&this->field_0x24 = param_4;
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0x69;
  *(float *)&this->field_0x20 = param_3;
  *(float *)&this->field_0x28 = param_5;
  return this;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004cea50
void __thiscall TRIBE_Action_Heal::first_in_stack(TRIBE_Action_Heal *this,uchar param_1)
{
  short sVar1;
  
  if (*(int *)&this->field_0x10 == 0) {
    (**(code **)(*(int *)this + 0x5c))(3);
  }
  else {
    sVar1 = *(short *)(*(int *)(*(int *)&this->field_0x10 + 8) + 0x14);
    if ((((sVar1 != 0x15) && (sVar1 != 2)) && (sVar1 != 0x14)) && (sVar1 != 0x16)) {
      (**(code **)(*(int *)this + 0x5c))(4);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004cea90
void __thiscall TRIBE_Action_Heal::set_state(TRIBE_Action_Heal *this,uchar param_1)
{
  int iVar1;
  RGE_Sound *this_00;
  RGE_Action_Move_To *pRVar2;
  RGE_Action *pRVar3;
  int unaff_ESI;
  int *unaff_FS_OFFSET;
  int iVar4;
  int local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe96;
  *unaff_FS_OFFSET = (int)&local_c;
  RGE_Action_List::delete_list(*(RGE_Action_List **)&this->field_0x34);
  this->field_0xc = param_1;
  switch(param_1) {
  case '\x02':
    (**(code **)(**(int **)&this->field_0x8 + 0x38))
              (*(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18));
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  case '\x03':
    iVar4 = (*(int **)&this->field_0x8)[1];
    (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar4,iVar4,0x202,0x25b,0,0);
    (**(code **)(**(int **)&this->field_0x8 + 0x38))
              (*(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18));
    *unaff_FS_OFFSET = iVar4;
    return;
  case '\x04':
    break;
  case '\x06':
    iVar4 = *(int *)&this->field_0x10;
    *(undefined4 *)&this->field_0x20 = *(undefined4 *)(iVar4 + 0x38);
    *(undefined4 *)&this->field_0x24 = *(undefined4 *)(iVar4 + 0x3c);
    iVar1 = **(int **)&this->field_0x8;
    *(undefined4 *)&this->field_0x28 = *(undefined4 *)(iVar4 + 0x40);
    (**(code **)(iVar1 + 0x38))(*(undefined4 *)(*(int *)&this->field_0x30 + 0x34));
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  case '\a':
    (**(code **)(**(int **)&this->field_0x8 + 0x38))
              (*(undefined4 *)(*(int *)&this->field_0x30 + 0x38));
    this_00 = *(RGE_Sound **)(*(int *)&this->field_0x30 + 0x44);
    if (this_00 != (RGE_Sound *)0x0) {
      RGE_Sound::play(this_00,1);
    }
  default:
    *unaff_FS_OFFSET = local_c;
    return;
  case '\v':
    pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar2 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar2,*(RGE_Action_Object **)&this->field_0x8,*(float *)&this->field_0x20
                          ,*(float *)&this->field_0x24,*(float *)&this->field_0x28,0.0,
                          *(RGE_Sprite **)(*(int *)&this->field_0x30 + 0x34));
    }
    local_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(*(int *)this + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action::setSubAction(pRVar3,'\x01');
    RGE_Action_List::add_action(*(RGE_Action_List **)&this->field_0x34,pRVar3);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  iVar4 = *(int *)&this->field_0x10;
  *(undefined4 *)&this->field_0x20 = *(undefined4 *)(iVar4 + 0x38);
  *(undefined4 *)&this->field_0x24 = *(undefined4 *)(iVar4 + 0x3c);
  *(undefined4 *)&this->field_0x28 = *(undefined4 *)(iVar4 + 0x40);
  pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
  local_4 = 1;
  if (pRVar2 == (RGE_Action_Move_To *)0x0) {
    pRVar3 = (RGE_Action *)0x0;
  }
  else {
    pRVar3 = (RGE_Action *)
             RGE_Action_Move_To::RGE_Action_Move_To
                       (pRVar2,*(RGE_Action_Object **)&this->field_0x8,
                        *(RGE_Static_Object **)&this->field_0x10,0.4,
                        *(RGE_Sprite **)(*(int *)&this->field_0x30 + 0x34));
  }
  local_4 = 0xffffffff;
  if (pRVar3 == (RGE_Action *)0x0) {
    (**(code **)(*(int *)this + 0x5c))(0xd);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  RGE_Action_List::add_action(*(RGE_Action_List **)&this->field_0x34,pRVar3);
  RGE_Action::setSubAction(pRVar3,'\x01');
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004cecf0
uchar __thiscall TRIBE_Action_Heal::update(TRIBE_Action_Heal *this)
{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  float fVar6;
  float work;
  float fStack_4;
  
  if ((*(int *)&this->field_0x18 != -1) &&
     (pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c),
                          *(int *)&this->field_0x18), pRVar4 == (RGE_Static_Object *)0x0)) {
LAB_004ced40:
    iVar5 = *(int *)this;
    (**(code **)(iVar5 + 0x54))(0);
    (**(code **)(iVar5 + 0x5c))(3);
    return '\0';
  }
  if ((*(int *)&this->field_0x1c != -1) &&
     (pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c),
                          *(int *)&this->field_0x1c), pRVar4 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*(int *)this + 0x58))(0);
  }
  iVar5 = *(int *)&this->field_0x10;
  if (iVar5 != 0) {
    if (*(char *)(iVar5 + 0x48) != '\x02') goto LAB_004ced40;
    if ((iVar5 != 0) &&
       (iVar5 = (**(code **)(**(int **)(*(int *)&this->field_0x8 + 0xc) + 0x1c))
                          ((int)*(short *)(*(int *)(iVar5 + 0xc) + 0x4a)), iVar5 == 0)) {
      (**(code **)(*(int *)this + 0x5c))(1);
      iVar5 = (*(int **)&this->field_0x8)[1];
      (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar5,iVar5,0x1fb,0x25b,0,0);
      return '\x04';
    }
  }
  switch(this->field_0xc) {
  case 1:
    return '\x01';
  case 4:
    uVar2 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    switch(uVar2) {
    case 1:
    case 2:
      (**(code **)(*(int *)this + 0x5c))(6);
      return '\0';
    case 3:
switchD_004cedd3_caseD_2:
      (**(code **)(*(int *)this + 0x5c))(0xd);
      return '\0';
    case 4:
    case 5:
switchD_004cedd3_caseD_3:
      iVar5 = *(int *)this;
      (**(code **)(iVar5 + 0x54))(0);
      (**(code **)(iVar5 + 0x5c))(0xb);
      return '\0';
    }
    break;
  case 6:
    if (*(int *)&this->field_0x10 == 0) {
      (**(code **)(*(int *)this + 0x5c))(3);
      return '\0';
    }
    cVar3 = (**(code **)(**(int **)&this->field_0x8 + 0x1f0))(*(int *)&this->field_0x10,0,0);
    if (cVar3 != '\0') {
      (**(code **)(*(int *)this + 0x5c))(7);
      return '\0';
    }
    break;
  case 7:
    pRVar4 = *(RGE_Static_Object **)&this->field_0x10;
    if (pRVar4 == (RGE_Static_Object *)0x0) {
      (**(code **)(*(int *)this + 0x5c))(3);
      return '\0';
    }
    if ((pRVar4->world_x != *(float *)&this->field_0x20) ||
       (*(float *)&this->field_0x24 != pRVar4->world_y)) {
      fVar6 = RGE_Static_Object::distance_to_object(*(RGE_Static_Object **)&this->field_0x8,pRVar4);
      if ((*(float *)(*(int *)&this->field_0x30 + 0x24) < fVar6) && ((float)_DAT_005750e8 < fVar6))
{
        (**(code **)(*(int *)this + 0x5c))(3);
        return '\0';
      }
      iVar5 = *(int *)&this->field_0x10;
      *(undefined4 *)&this->field_0x20 = *(undefined4 *)(iVar5 + 0x38);
      *(undefined4 *)&this->field_0x24 = *(undefined4 *)(iVar5 + 0x3c);
      *(undefined4 *)&this->field_0x28 = *(undefined4 *)(iVar5 + 0x40);
      return '\0';
    }
    iVar5 = *(int *)(*(int *)&this->field_0x8 + 0xc);
    iVar1 = *(int *)(iVar5 + 0x50);
    fStack_4 = *(float *)(*(int *)&this->field_0x30 + 0x1c) *
               *(float *)(*(int *)(*(int *)&this->field_0x8 + 8) + 0xe4) *
               *(float *)(*(int *)(iVar5 + 0x3c) + 0x84);
    if (_DAT_005750e0 < *(float *)(iVar1 + 0xe0)) {
      fStack_4 = fStack_4 * *(float *)(iVar1 + 0xe0);
    }
    cVar3 = (**(code **)(pRVar4->_padding_ + 0x8c))(fStack_4);
    if (cVar3 == '\x01') {
      (**(code **)(*(int *)this + 0x5c))(3);
      return '\0';
    }
    if (cVar3 == '\x02') {
      iVar5 = (*(int **)&this->field_0x8)[1];
      (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar5,iVar5,0x1fb,0x25b,0,0);
      (**(code **)(*(int *)this + 0x5c))(2);
      return '\0';
    }
    break;
  case 0xb:
    uVar2 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    switch(uVar2) {
    case 1:
    case 2:
    case 5:
      (**(code **)(*(int *)this + 0x5c))(3);
      return '\0';
    case 3:
      goto switchD_004cedd3_caseD_2;
    case 4:
      goto switchD_004cedd3_caseD_3;
    }
    break;
  case 0xd:
    iVar5 = (*(int **)&this->field_0x8)[1];
    (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar5,iVar5,0x1f9,0x25b,0,0);
    (**(code **)(*(int *)this + 0x5c))(2);
    return '\x03';
  }
  return '\0';
}

// --------------------------------------------------

// Function: work
// Address: 004cf030
int __thiscall
TRIBE_Action_Heal::work
          (TRIBE_Action_Heal *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  char cVar1;
  int iVar2;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  if (param_1 == *(RGE_Static_Object **)&this->field_0x10) {
    cVar1 = this->field_0xc;
    if (cVar1 == '\x04') {
      return 1;
    }
    if (cVar1 == '\x06') {
      return 1;
    }
    if (cVar1 == '\a') {
      return 1;
    }
  }
  iVar2 = *(int *)this;
  (**(code **)(iVar2 + 0x54))(param_1);
  *(float *)&this->field_0x20 = param_1->world_x;
  *(float *)&this->field_0x24 = param_1->world_y;
  *(float *)&this->field_0x28 = param_1->world_z;
  (**(code **)(iVar2 + 0x1c))(1);
  return 1;
}

// --------------------------------------------------

