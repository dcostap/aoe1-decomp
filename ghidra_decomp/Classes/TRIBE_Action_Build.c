// Class: TRIBE_Action_Build
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

// Function: TRIBE_Action_Build
// Address: 004cd1b0
/* public: __thiscall TRIBE_Action_Build::TRIBE_Action_Build(int,class RGE_Action_Object *) */

TRIBE_Action_Build * __thiscall
TRIBE_Action_Build::TRIBE_Action_Build
          (TRIBE_Action_Build *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  *(undefined ***)this = &_vftable_;
                    /* language.dll match for 0x65: "1" */
  *(undefined2 *)&this->field_0x4 = 0x65;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004cd1e0
/* public: virtual void * __thiscall TRIBE_Action_Build::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Action_Build::_vector_deleting_destructor_(TRIBE_Action_Build *this,uint param_1)
{
  ~TRIBE_Action_Build(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Build
// Address: 004cd200
/* public: virtual __thiscall TRIBE_Action_Build::~TRIBE_Action_Build(void) */

void __thiscall TRIBE_Action_Build::~TRIBE_Action_Build(TRIBE_Action_Build *this)
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

// Function: TRIBE_Action_Build
// Address: 004cd210
/* public: __thiscall TRIBE_Action_Build::TRIBE_Action_Build(class RGE_Action_Object *,class
   RGE_Task *,class RGE_Static_Object *) */

TRIBE_Action_Build * __thiscall
TRIBE_Action_Build::TRIBE_Action_Build
          (TRIBE_Action_Build *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd88;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
                    /* language.dll match for 0x65: "1" */
  *(undefined2 *)&this->field_0x4 = 0x65;
  *(RGE_Task **)&this->field_0x30 = param_2;
  if ((param_3 == (RGE_Static_Object *)0x0) ||
     (*(short *)(param_1->_padding_ + 0x4a) == param_3->owner->id)) {
    RGE_Action::set_target_obj((RGE_Action *)this,param_3);
    *(float *)&this->field_0x20 = param_3->world_x;
    *(float *)&this->field_0x24 = param_3->world_y;
    *(float *)&this->field_0x28 = param_3->world_z;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Build
// Address: 004cd2a0
/* public: __thiscall TRIBE_Action_Build::TRIBE_Action_Build(class RGE_Action_Object *,class
   RGE_Task *,float,float,float) */

TRIBE_Action_Build * __thiscall
TRIBE_Action_Build::TRIBE_Action_Build
          (TRIBE_Action_Build *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  *(RGE_Task **)&this->field_0x30 = param_2;
  *(float *)&this->field_0x24 = param_4;
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0x65;
  *(float *)&this->field_0x20 = param_3;
  *(float *)&this->field_0x28 = param_5;
  return this;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004cd2e0
/* public: virtual void __thiscall TRIBE_Action_Build::first_in_stack(unsigned char) */

void __thiscall TRIBE_Action_Build::first_in_stack(TRIBE_Action_Build *this,uchar param_1)
{
  if (param_1 == '\0') {
    (**(code **)(*(int *)this + 0x5c))(3);
    return;
  }
  if (*(int *)&this->field_0x10 != 0) {
    (**(code **)(*(int *)this + 0x5c))(4);
    return;
  }
  (**(code **)(*(int *)this + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004cd310
/* protected: virtual void __thiscall TRIBE_Action_Build::set_state(unsigned char) */

void __thiscall TRIBE_Action_Build::set_state(TRIBE_Action_Build *this,uchar param_1)
{
  int iVar1;
  RGE_Sound *this_00;
  int iVar2;
  RGE_Action_Move_To *pRVar3;
  RGE_Action *pRVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_ESI;
  int *unaff_FS_OFFSET;
  int local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fdb6;
  *unaff_FS_OFFSET = (int)&local_c;
  RGE_Action_List::delete_list(*(RGE_Action_List **)&this->field_0x34);
  this->field_0xc = param_1;
  switch(param_1) {
  case '\x01':
  case '\r':
    iVar6 = **(int **)&this->field_0x8;
    uVar5 = *(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18);
    break;
  case '\x02':
    iVar6 = *(int *)((*(int **)&this->field_0x8)[2] + 0x18);
    (**(code **)(**(int **)&this->field_0x8 + 0x38))();
    iVar1 = *(int *)this;
    (**(code **)(iVar1 + 0x54))(0);
    (**(code **)(iVar1 + 0x58))(0);
    *(undefined4 *)&this->field_0x20 = 0xbf800000;
    *(undefined4 *)&this->field_0x24 = 0xbf800000;
    *(undefined4 *)&this->field_0x28 = 0xbf800000;
    *unaff_FS_OFFSET = iVar6;
    return;
  case '\x03':
    iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x8 + 0xc));
    iVar6 = (*(int **)&this->field_0x8)[1];
    iVar1 = **(int **)&this->field_0x8;
    if (iVar2 == 1) {
      (**(code **)(iVar1 + 0x148))(iVar6,iVar6,0x1fa);
      (**(code **)(*(int *)this + 0x5c))(1);
      (**(code **)(**(int **)&this->field_0x8 + 0x38))
                (*(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18));
      *unaff_FS_OFFSET = iVar6;
      return;
    }
    (**(code **)(iVar1 + 0x148))(iVar6,iVar6,0x202,0x25a,0,0);
    (**(code **)(**(int **)&this->field_0x8 + 0x38))
              (*(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18));
    *unaff_FS_OFFSET = iVar6;
    return;
  case '\x04':
    iVar6 = *(int *)&this->field_0x10;
    if (iVar6 != 0) {
      *(undefined4 *)&this->field_0x20 = *(undefined4 *)(iVar6 + 0x38);
      *(undefined4 *)&this->field_0x24 = *(undefined4 *)(iVar6 + 0x3c);
      *(undefined4 *)&this->field_0x28 = *(undefined4 *)(iVar6 + 0x40);
    }
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 1;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,*(RGE_Action_Object **)&this->field_0x8,
                          *(RGE_Static_Object **)&this->field_0x10,
                          *(float *)(*(int *)&this->field_0x30 + 0x24),
                          *(RGE_Sprite **)(*(int *)&this->field_0x30 + 0x34));
    }
    local_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(*(int *)this + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action_List::add_action(*(RGE_Action_List **)&this->field_0x34,pRVar4);
    RGE_Action::setSubAction(pRVar4,'\x01');
    *unaff_FS_OFFSET = local_c;
    return;
  default:
    goto switchD_004cd347_caseD_5;
  case '\x06':
    iVar6 = **(int **)&this->field_0x8;
    uVar5 = *(undefined4 *)(*(int *)&this->field_0x30 + 0x34);
    break;
  case '\a':
    (**(code **)(**(int **)&this->field_0x8 + 0x38))
              (*(undefined4 *)(*(int *)&this->field_0x30 + 0x38));
    this_00 = *(RGE_Sound **)(*(int *)&this->field_0x30 + 0x44);
    if (this_00 != (RGE_Sound *)0x0) {
      RGE_Sound::play(this_00,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    goto switchD_004cd347_caseD_5;
  case '\v':
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,*(RGE_Action_Object **)&this->field_0x8,*(float *)&this->field_0x20
                          ,*(float *)&this->field_0x24,*(float *)&this->field_0x28,0.0,
                          *(RGE_Sprite **)(*(int *)&this->field_0x30 + 0x34));
    }
    local_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(*(int *)this + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action::setSubAction(pRVar4,'\x01');
    RGE_Action_List::add_action(*(RGE_Action_List **)&this->field_0x34,pRVar4);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  (**(code **)(iVar6 + 0x38))(uVar5);
switchD_004cd347_caseD_5:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004cd5e0
/* WARNING: Variable defined which should be unmapped: work */
/* public: virtual unsigned char __thiscall TRIBE_Action_Build::update(void) */

uchar __thiscall TRIBE_Action_Build::update(TRIBE_Action_Build *this)
{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  char cVar4;
  uchar uVar5;
  RGE_Static_Object *pRVar6;
  float work;
  float fStack_4;
  
  if ((*(int *)&this->field_0x18 != -1) &&
     (pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c),
                          *(int *)&this->field_0x18), pRVar6 == (RGE_Static_Object *)0x0)) {
    iVar1 = *(int *)this;
    (**(code **)(iVar1 + 0x54))(0);
    if (this->field_0xc != '\x02') {
      (**(code **)(iVar1 + 0x5c))(3);
      return '\0';
    }
  }
  if ((*(int *)&this->field_0x1c != -1) &&
     (pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c),
                          *(int *)&this->field_0x1c), pRVar6 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*(int *)this + 0x58))(0);
  }
  iVar1 = *(int *)&this->field_0x10;
  if (((iVar1 != 0) && (*(char *)(iVar1 + 0x48) != '\0')) &&
     (*(float *)&this->field_0x2c == (float)DAT_00574f78._0_4_)) {
    if (*(float *)(iVar1 + 0x30) < (float)(int)*(short *)(*(int *)(iVar1 + 8) + 0x26)) {
      RGE_Static_Object::removeAllFromPathingGroup(*(RGE_Static_Object **)&this->field_0x8);
      iVar1 = *(int *)&this->field_0x10;
      piVar2 = *(int **)(*(int *)&this->field_0x8 + 0xc);
      (**(code **)(*piVar2 + 0x34))
                ((int)*(short *)((int)piVar2 + 0x4a),*(undefined4 *)(*(int *)&this->field_0x8 + 4),
                 0x2ce,*(undefined4 *)(iVar1 + 4),(int)*(short *)(*(int *)(iVar1 + 0xc) + 0x4a),
                 *(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
                 *(undefined4 *)(iVar1 + 0x40),0x3f800000,1,0,100);
      return '\0';
    }
    iVar1 = *(int *)this;
    (**(code **)(iVar1 + 0x54))(0);
    if (this->field_0xc != '\x02') {
      (**(code **)(iVar1 + 0x5c))(3);
      return '\0';
    }
  }
  switch(this->field_0xc) {
  case 1:
    return '\x01';
  case 4:
    uVar3 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    switch(uVar3) {
    case 1:
    case 2:
      (**(code **)(*(int *)this + 0x5c))(6);
      return '\0';
    case 3:
switchD_004cd71f_caseD_2:
      (**(code **)(*(int *)this + 0x5c))(3);
      return '\0';
    case 4:
    case 5:
switchD_004cd71f_caseD_3:
      iVar1 = *(int *)this;
      (**(code **)(iVar1 + 0x54))(0);
      (**(code **)(iVar1 + 0x5c))(0xb);
      return '\0';
    }
    break;
  case 6:
    cVar4 = (**(code **)(**(int **)&this->field_0x8 + 0x1f0))(*(undefined4 *)&this->field_0x10,0,0);
    if (cVar4 != '\0') {
      (**(code **)(*(int *)this + 0x5c))(7);
      return '\0';
    }
    break;
  case 7:
    if (((*(float *)&this->field_0x2c < (float)(double)DAT_00574f78._8_8_) &&
        (*(int *)&this->field_0x10 != 0)) &&
       ((float)DAT_00574f78._0_4_ < *(float *)(*(int *)&this->field_0x10 + 0x44))) {
      RGE_Static_Object::removeAllFromPathingGroup(*(RGE_Static_Object **)&this->field_0x8);
      (**(code **)(**(int **)&this->field_0x8 + 300))(1);
      iVar1 = *(int *)&this->field_0x10;
      (**(code **)(**(int **)&this->field_0x8 + 0x98))
                (iVar1,*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),0);
      return '\0';
    }
    if (rge_base_game->quick_build == 0) {
      fStack_4 = *(float *)(*(int *)&this->field_0x30 + 0x1c) *
                 *(float *)(*(int *)(*(int *)&this->field_0x8 + 8) + 0xe4) *
                 *(float *)(*(int *)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c) + 0x84);
    }
    else {
      fStack_4 = 1000.0;
    }
    if ((*(TRIBE_Building_Object **)&this->field_0x10 == (TRIBE_Building_Object *)0x0) ||
       (uVar5 = TRIBE_Building_Object::build(*(TRIBE_Building_Object **)&this->field_0x10,fStack_4),
       uVar5 != '\0')) {
      if ((*(int *)&this->field_0x10 != 0) &&
         (*(short *)(*(int *)(*(int *)&this->field_0x10 + 8) + 0x10) == 0x32)) {
        *(undefined4 *)&this->field_0x2c = 0xbf800000;
        return '\0';
      }
      goto switchD_004cd71f_caseD_2;
    }
    break;
  case 0xb:
    uVar3 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    switch(uVar3) {
    case 1:
    case 2:
    case 5:
      (**(code **)(*(int *)this + 0x5c))(3);
      return '\0';
    case 3:
      goto switchD_004cd71f_caseD_2;
    case 4:
      goto switchD_004cd71f_caseD_3;
    }
    break;
  case 0xd:
    iVar1 = (*(int **)&this->field_0x8)[1];
    (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar1,iVar1,0x1f9,0x25a,0,0);
    (**(code **)(*(int *)this + 0x5c))(2);
    return '\x03';
  }
  return '\0';
}

// --------------------------------------------------

// Function: stop
// Address: 004cd910
/* public: virtual int __thiscall TRIBE_Action_Build::stop(void) */

int __thiscall TRIBE_Action_Build::stop(TRIBE_Action_Build *this)
{
  (**(code **)(*(int *)this + 0x5c))(2);
  return 1;
}

// --------------------------------------------------

// Function: move_to
// Address: 004cd920
/* public: virtual int __thiscall TRIBE_Action_Build::move_to(class RGE_Static_Object
   *,float,float,float) */

int __thiscall
TRIBE_Action_Build::move_to
          (TRIBE_Action_Build *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  int iVar1;
  
  iVar1 = *(int *)this;
  *(float *)&this->field_0x24 = param_3;
  *(float *)&this->field_0x20 = param_2;
  *(float *)&this->field_0x28 = param_4;
  (**(code **)(iVar1 + 0x54))(0);
  (**(code **)(iVar1 + 0x5c))(0xb);
  return 1;
}

// --------------------------------------------------

// Function: work
// Address: 004cd960
/* public: virtual int __thiscall TRIBE_Action_Build::work(class RGE_Static_Object
   *,float,float,float) */

int __thiscall
TRIBE_Action_Build::work
          (TRIBE_Action_Build *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  int iVar1;
  
  if ((param_1 == (RGE_Static_Object *)0x0) ||
     (param_1->owner->id != *(short *)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x4a))) {
    iVar1 = *(int *)this;
    *(float *)&this->field_0x28 = param_4;
    *(float *)&this->field_0x20 = param_2;
    *(float *)&this->field_0x24 = param_3;
    (**(code **)(iVar1 + 0x54))(0);
    (**(code **)(iVar1 + 0x5c))(0xb);
  }
  else if ((param_1 != *(RGE_Static_Object **)&this->field_0x10) ||
          ((this->field_0xc != '\x04' && (this->field_0xc != '\x06')))) {
    iVar1 = *(int *)this;
    (**(code **)(iVar1 + 0x54))(param_1);
    (**(code **)(iVar1 + 0x5c))(4);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

