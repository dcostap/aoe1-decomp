// Class: RGE_Action_Bird
// Size:  0x40
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
// ----------------------------------------------------------------

// Function: RGE_Action_Bird
// Address: 00401fe0
/* public: __thiscall RGE_Action_Bird::RGE_Action_Bird(int,class RGE_Action_Object *) */

RGE_Action_Bird * __thiscall
RGE_Action_Bird::RGE_Action_Bird(RGE_Action_Bird *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 10;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00402010
/* public: virtual void * __thiscall RGE_Action_Bird::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_Action_Bird::_vector_deleting_destructor_(RGE_Action_Bird *this,uint param_1)
{
  ~RGE_Action_Bird(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Bird
// Address: 00402030
/* public: virtual __thiscall RGE_Action_Bird::~RGE_Action_Bird(void) */

void __thiscall RGE_Action_Bird::~RGE_Action_Bird(RGE_Action_Bird *this)
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

// Function: RGE_Action_Bird
// Address: 00402040
/* public: __thiscall RGE_Action_Bird::RGE_Action_Bird(class RGE_Action_Object *,class RGE_Task
   *,float,float,float) */

RGE_Action_Bird * __thiscall
RGE_Action_Bird::RGE_Action_Bird
          (RGE_Action_Bird *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  *(RGE_Task **)&this->field_0x30 = param_2;
  *(float *)&this->field_0x24 = param_4;
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 10;
  *(float *)&this->field_0x20 = param_3;
  *(float *)&this->field_0x28 = param_5;
  return this;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 00402080
/* public: virtual void __thiscall RGE_Action_Bird::first_in_stack(unsigned char) */

void __thiscall RGE_Action_Bird::first_in_stack(RGE_Action_Bird *this,uchar param_1)
{
  int *piVar1;
  
  if (param_1 != '\0') {
    piVar1 = *(int **)&this->field_0x8;
    (**(code **)(*piVar1 + 0x34))(piVar1[0xe],piVar1[0xf],0x40c00000);
    (**(code **)(*(int *)this + 0x5c))(3);
    return;
  }
  (**(code **)(*(int *)this + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004020c0
// [HELPER] s_C__msdev_work_age1_x1_act_bird_c: "C:\msdev\work\age1_x1\act_bird.cpp"
/* protected: virtual void __thiscall RGE_Action_Bird::set_state(unsigned char) */

void __thiscall RGE_Action_Bird::set_state(RGE_Action_Bird *this,uchar param_1)
{
  int *piVar1;
  int iVar2;
  
  this->field_0xc = param_1;
  if (param_1 == '\x04') {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_act_bird_c,0x44);
    *(float *)&this->field_0x2c = (float)((iVar2 * 10) / 0x7fff + 5);
    iVar2 = *(int *)(*(int *)&this->field_0x30 + 0x34);
  }
  else {
    if (param_1 != '\x06') {
      RGE_Action_List::delete_list(*(RGE_Action_List **)&this->field_0x34);
      return;
    }
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_act_bird_c,0x4c);
    *(float *)&this->field_0x2c = (float)((iVar2 * 10) / 0x7fff + 5);
    iVar2 = *(int *)(*(int *)&this->field_0x30 + 0x38);
  }
  piVar1 = *(int **)&this->field_0x8;
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x38))(iVar2);
    return;
  }
  (**(code **)(*piVar1 + 0x38))(*(undefined4 *)(piVar1[2] + 0x18));
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00402180
// [HELPER] s_C__msdev_work_age1_x1_act_bird_c: "C:\msdev\work\age1_x1\act_bird.cpp"
/* public: virtual unsigned char __thiscall RGE_Action_Bird::update(void) */

uchar __thiscall RGE_Action_Bird::update(RGE_Action_Bird *this)
{
  int iVar1;
  char cVar2;
  int iVar3;
  RGE_Action_Move_To *this_00;
  RGE_Action *pRVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c11b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if ((float)DAT_0056e138 < *(float *)&this->field_0x2c) {
    *(float *)&this->field_0x2c =
         *(float *)&this->field_0x2c -
         *(float *)(*(int *)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c) + 0x84);
  }
  switch(this->field_0xc) {
  case 1:
    *unaff_FS_OFFSET = local_c;
    return '\x01';
  case 3:
                    /* language.dll match for 0x84: "8" */
    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c) + 0x28);
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_act_bird_c,0x84);
                    /* language.dll match for 0x85: "N" */
    *(float *)&this->field_0x20 = (float)((iVar3 * *(int *)(iVar1 + 8)) / 0x7fff);
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_act_bird_c,0x85);
    *(float *)&this->field_0x24 = (float)((iVar3 * *(int *)(iVar1 + 0xc)) / 0x7fff);
    *(undefined4 *)&this->field_0x28 = *(undefined4 *)(*(int *)&this->field_0x8 + 0x40);
    this_00 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (this_00 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (this_00,*(RGE_Action_Object **)&this->field_0x8,
                          *(float *)&this->field_0x20,*(float *)&this->field_0x24,
                          *(float *)&this->field_0x28,*(float *)(*(int *)&this->field_0x30 + 0x24),
                          (RGE_Sprite *)(*(RGE_Action_Object **)&this->field_0x8)->_padding_);
    }
    local_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(*(int *)this + 0x5c))(3);
      *unaff_FS_OFFSET = this_00;
      return '\0';
    }
    RGE_Action_List::add_action(*(RGE_Action_List **)&this->field_0x34,pRVar4);
    (**(code **)(*(int *)this + 0x5c))(4);
    *unaff_FS_OFFSET = this_00;
    return '\0';
  case 4:
    if (*(float *)&this->field_0x2c <= (float)DAT_0056e138) {
      (**(code **)(*(int *)this + 0x5c))(6);
    }
    cVar2 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    if (cVar2 == '\x01') {
      (**(code **)(*(int *)this + 0x5c))(3);
      *unaff_FS_OFFSET = this;
      return '\0';
    }
    break;
  case 6:
    if (*(float *)&this->field_0x2c <= (float)DAT_0056e138) {
      (**(code **)(*(int *)this + 0x5c))(4);
    }
    cVar2 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    if (cVar2 == '\x01') {
      (**(code **)(*(int *)this + 0x5c))(3);
      *unaff_FS_OFFSET = this;
      return '\0';
    }
  }
  *unaff_FS_OFFSET = local_c;
  return '\0';
}

// --------------------------------------------------

