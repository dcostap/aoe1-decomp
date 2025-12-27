// Class: RGE_Action_Object
// Function: RGE_Action_Object
// Address: 00405c60
/* public: __thiscall RGE_Action_Object::RGE_Action_Object(class RGE_Master_Action_Object *,class
   RGE_Player *,float,float,float,int) */

RGE_Action_Object * __thiscall
RGE_Action_Object::RGE_Action_Object
          (RGE_Action_Object *this,RGE_Master_Action_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c368;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Moving_Object::RGE_Moving_Object
            ((RGE_Moving_Object *)this,(RGE_Master_Moving_Object *)param_1,param_2,param_3,param_4,
             param_5,0);
  local_4 = 0;
  this->lastActionValue = -1;
  this->lastActionStateValue = -1;
  this->_padding_ = (int)&_vftable_;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00405f70
/* public: virtual void * __thiscall RGE_Action_Object::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
RGE_Action_Object::_vector_deleting_destructor_(RGE_Action_Object *this,uint param_1)
{
  ~RGE_Action_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Action_Object
// Address: 00405f90
/* public: __thiscall RGE_Action_Object::RGE_Action_Object(int,class RGE_Game_World *,int) */

RGE_Action_Object * __thiscall
RGE_Action_Object::RGE_Action_Object
          (RGE_Action_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c388;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Moving_Object::RGE_Moving_Object((RGE_Moving_Object *)this,param_1,param_2,0);
  local_4 = 0;
  this->lastActionValue = -1;
  this->lastActionStateValue = -1;
  this->_padding_ = (int)&_vftable_;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Object
// Address: 00406010
/* public: virtual __thiscall RGE_Action_Object::~RGE_Action_Object(void) */

void __thiscall RGE_Action_Object::~RGE_Action_Object(RGE_Action_Object *this)
{
  RGE_Action_List *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055c3a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  this_00 = this->actions;
  local_4 = 0;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->actions = (RGE_Action_List *)0x0;
  }
  local_4 = 0xffffffff;
  RGE_Moving_Object::~RGE_Moving_Object((RGE_Moving_Object *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: recycle_out_of_game
// Address: 00406080
/* public: virtual void __thiscall RGE_Action_Object::recycle_out_of_game(void) */

void __thiscall RGE_Action_Object::recycle_out_of_game(RGE_Action_Object *this)
{
  if (this->actions != (RGE_Action_List *)0x0) {
    RGE_Action_List::delete_list(this->actions);
  }
  RGE_Static_Object::recycle_out_of_game((RGE_Static_Object *)this);
  return;
}

// --------------------------------------------------

// Function: recycle_in_to_game
// Address: 004060a0
/* public: virtual void __thiscall RGE_Action_Object::recycle_in_to_game(class
   RGE_Master_Static_Object *,class RGE_Player *,float,float,float) */

void __thiscall
RGE_Action_Object::recycle_in_to_game
          (RGE_Action_Object *this,RGE_Master_Static_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  RGE_Moving_Object::recycle_in_to_game
            ((RGE_Moving_Object *)this,param_1,param_2,param_3,param_4,param_5);
  this->waiting = '\0';
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 004060d0
/* protected: virtual int __thiscall RGE_Action_Object::setup(class RGE_Master_Action_Object *,class
   RGE_Player *,float,float,float) */

int __thiscall
RGE_Action_Object::setup
          (RGE_Action_Object *this,RGE_Master_Action_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  int iVar1;
  RGE_Action_List *pRVar2;
  
  RGE_Moving_Object::setup
            ((RGE_Moving_Object *)this,(RGE_Master_Moving_Object *)param_1,param_2,param_3,param_4,
             param_5);
  iVar1 = this->_padding_;
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x28;
  this->waiting = '\0';
  pRVar2 = (RGE_Action_List *)(**(code **)(iVar1 + 0x218))();
  this->actions = pRVar2;
  this->command_flag = '\0';
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00406120
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall RGE_Action_Object::setup(int,class RGE_Game_World *) */

int __thiscall RGE_Action_Object::setup(RGE_Action_Object *this,int param_1,RGE_Game_World *param_2)
{
  RGE_Action_List *this_00;
  
  RGE_Moving_Object::setup((RGE_Moving_Object *)this,param_1,param_2);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x28;
  rge_read(param_1,&this->waiting,1);
  if (save_game_version < _DAT_0056e648) {
    this->command_flag = '\0';
  }
  else {
    rge_read(param_1,&this->command_flag,1);
  }
  this_00 = (RGE_Action_List *)(**(code **)(this->_padding_ + 0x218))();
  this->actions = this_00;
  RGE_Action_List::load(this_00,param_1);
  return 1;
}

// --------------------------------------------------

// Function: create_action_list
// Address: 004061a0
/* protected: virtual class RGE_Action_List * __thiscall RGE_Action_Object::create_action_list(void)
    */

RGE_Action_List * __thiscall RGE_Action_Object::create_action_list(RGE_Action_Object *this)
{
  RGE_Action_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c3cb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Action_List *)operator_new(0xc);
  local_4 = 0;
  if (pRVar1 != (RGE_Action_List *)0x0) {
    pRVar1 = (RGE_Action_List *)RGE_Action_List::RGE_Action_List(pRVar1,this);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Action_List *)0x0;
}

// --------------------------------------------------

// Function: rehook
// Address: 00406200
/* public: virtual void __thiscall RGE_Action_Object::rehook(void) */

void __thiscall RGE_Action_Object::rehook(RGE_Action_Object *this)
{
  RGE_Static_Object::rehook((RGE_Static_Object *)this);
  RGE_Action_List::rehook(this->actions);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00406220
/* public: virtual void __thiscall RGE_Action_Object::save(int) */

void __thiscall RGE_Action_Object::save(RGE_Action_Object *this,int param_1)
{
  RGE_Moving_Object::save((RGE_Moving_Object *)this,param_1);
  rge_write(param_1,&this->waiting,1);
  rge_write(param_1,&this->command_flag,1);
  RGE_Action_List::save(this->actions,param_1);
  return;
}

// --------------------------------------------------

// Function: transform
// Address: 00406270
/* public: virtual void __thiscall RGE_Action_Object::transform(class RGE_Master_Static_Object *) */

void __thiscall
RGE_Action_Object::transform(RGE_Action_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Moving_Object::transform((RGE_Moving_Object *)this,param_1);
  RGE_Action_List::delete_list(this->actions);
  return;
}

// --------------------------------------------------

// Function: destroy_obj
// Address: 00406290
/* public: virtual void __thiscall RGE_Action_Object::destroy_obj(void) */

void __thiscall RGE_Action_Object::destroy_obj(RGE_Action_Object *this)
{
  RGE_Action_List::delete_list(this->actions);
  RGE_Static_Object::destroy_obj((RGE_Static_Object *)this);
  return;
}

// --------------------------------------------------

// Function: notify_of_relation
// Address: 004062b0
/* public: virtual void __thiscall RGE_Action_Object::notify_of_relation(long,unsigned char) */

void __thiscall
RGE_Action_Object::notify_of_relation(RGE_Action_Object *this,long param_1,uchar param_2)
{
  return;
}

// --------------------------------------------------

// Function: do_command
// Address: 004062c0
/* public: virtual void __thiscall RGE_Action_Object::do_command(class RGE_Static_Object
   *,float,float,float) */

void __thiscall
RGE_Action_Object::do_command
          (RGE_Action_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  if ((RGE_Action_Object *)param_1 != this) {
    (**(code **)(this->_padding_ + 0x1f8))(param_1,param_2,param_3,param_4,0);
    this->command_flag = this->command_flag + '\x01';
  }
  return;
}

// --------------------------------------------------

// Function: move_to
// Address: 00406300
/* public: virtual void __thiscall RGE_Action_Object::move_to(class RGE_Static_Object
   *,float,float,float) */

void __thiscall
RGE_Action_Object::move_to
          (RGE_Action_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  int iVar1;
  RGE_Action_Move_To *pRVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  long lVar4;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c3f6;
  *unaff_FS_OFFSET = &local_c;
  if ((RGE_Action_Object *)param_1 == this) goto LAB_00406419;
  iVar1 = RGE_Action_List::action_move_to(this->actions,param_1,param_2,param_3,param_4);
  if (iVar1 != 0) goto LAB_00406419;
  if (param_1 == (RGE_Static_Object *)0x0) {
    pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 1;
    if (pRVar2 == (RGE_Action_Move_To *)0x0) goto LAB_004063aa;
    iVar1 = RGE_Action_Move_To::RGE_Action_Move_To
                      (pRVar2,this,param_2,param_3,param_4,0.4,(RGE_Sprite *)0x0);
  }
  else {
    pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar2 == (RGE_Action_Move_To *)0x0) {
LAB_004063aa:
      iVar1 = 0;
    }
    else {
      iVar1 = RGE_Action_Move_To::RGE_Action_Move_To(pRVar2,this,param_1,0.4,(RGE_Sprite *)0x0);
    }
  }
  local_4 = 0xffffffff;
  if ((UnitAIModule *)this->_padding_ != (UnitAIModule *)0x0) {
    UnitAIModule::setCurrentOrder((UnitAIModule *)this->_padding_,0x2c6);
    UnitAIModule::setCurrentAction((UnitAIModule *)this->_padding_,0x262);
    if (param_1 == (RGE_Static_Object *)0x0) {
      iVar3 = -1;
      lVar4 = -1;
    }
    else {
      lVar4 = param_1->id;
      iVar3 = (int)param_1->master_obj->object_group;
    }
    UnitAIModule::setCurrentTarget
              ((UnitAIModule *)this->_padding_,lVar4,iVar3,param_2,param_3,param_4);
  }
  if (iVar1 != 0) {
    (**(code **)(this->_padding_ + 0x208))(iVar1);
  }
  this->command_flag = this->command_flag + '\x01';
LAB_00406419:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: work
// Address: 00406430
/* public: virtual void __thiscall RGE_Action_Object::work(class RGE_Static_Object
   *,float,float,float) */

void __thiscall
RGE_Action_Object::work
          (RGE_Action_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  if ((RGE_Action_Object *)param_1 != this) {
    (**(code **)(this->_padding_ + 0x1f8))(param_1,param_2,param_3,param_4,1);
    this->command_flag = this->command_flag + '\x01';
  }
  return;
}

// --------------------------------------------------

// Function: work2
// Address: 00406470
/* WARNING: Variable defined which should be unmapped: skip */
/* public: virtual void __thiscall RGE_Action_Object::work2(class RGE_Static_Object
   *,float,float,float,unsigned char) */

void __thiscall
RGE_Action_Object::work2
          (RGE_Action_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4,uchar param_5)
{
  int iVar1;
  uchar uVar2;
  undefined2 uVar3;
  short sVar4;
  RGE_Task *pRVar5;
  RGE_Task *pRVar6;
  RGE_Action *pRVar7;
  RGE_Static_Object *pRVar8;
  int *piVar9;
  float unaff_EBX;
  float unaff_EBP;
  long lVar10;
  int iVar11;
  int iVar12;
  int skip;
  
  if ((RGE_Action_Object *)param_1 != this) {
    pRVar5 = (RGE_Task *)
             (**(code **)(**(int **)(this->_padding_ + 0xd8) + 4))
                       (this,param_1,param_2,param_3,param_4);
    if ((pRVar5 == (RGE_Task *)0x0) && (*(char *)(this->_padding_ + 0xec) != '\0')) {
      iVar11 = this->_padding_;
      iVar12 = 0;
      if (0 < *(short *)(iVar11 + 0x22)) {
        do {
          iVar11 = *(int *)(*(int *)(iVar11 + 0x24) + iVar12 * 4);
          param_4 = (float)this;
          if ((((iVar11 != 0) &&
               (iVar1 = this->_padding_, *(short *)(iVar11 + 0x14) == *(short *)(iVar1 + 0x14))) &&
              (*(char *)(iVar11 + 4) == *(char *)(iVar1 + 4))) &&
             ((*(char *)(iVar11 + 0xec) == *(char *)(iVar1 + 0xec) &&
              (pRVar5 = (RGE_Task *)
                        (**(code **)(**(int **)(iVar11 + 0xd8) + 4))
                                  (this,param_1,unaff_EBP,unaff_EBX,this), pRVar5 != (RGE_Task *)0x0
              )))) {
            (**(code **)(this->_padding_ + 0x54))(iVar11);
            break;
          }
          iVar11 = this->_padding_;
          iVar12 = iVar12 + 1;
        } while (iVar12 < *(short *)(iVar11 + 0x22));
      }
    }
    pRVar6 = RGE_Action_List::get_task(this->actions);
    iVar11 = 0;
    uVar3 = 0xffff;
    if (((pRVar6 != (RGE_Task *)0x0) && (pRVar5 == pRVar6)) &&
       (iVar12 = RGE_Action_List::action_work(this->actions,param_1,unaff_EBP,unaff_EBX,param_4),
       iVar12 != 0)) {
      pRVar7 = RGE_Action_List::get_action(this->actions);
      uVar3 = (**(code **)(pRVar7->_padding_ + 0x18))();
      iVar11 = 1;
    }
    uVar2 = RGE_Action_List::have_action(this->actions);
    if (uVar2 == '\x01') {
      pRVar7 = RGE_Action_List::get_action(this->actions);
      pRVar8 = (RGE_Static_Object *)(**(code **)(pRVar7->_padding_ + 0x4c))();
      if (pRVar8 == param_1) {
        pRVar7 = RGE_Action_List::get_action(this->actions);
        sVar4 = (**(code **)(pRVar7->_padding_ + 0x18))();
        if (sVar4 == 9) {
          pRVar7 = RGE_Action_List::get_action(this->actions);
          iVar12 = (**(code **)(pRVar7->_padding_ + 0x34))(param_1,unaff_EBP,unaff_EBX,param_4);
          if (iVar12 != 0) {
            pRVar7 = RGE_Action_List::get_action(this->actions);
            uVar3 = (**(code **)(pRVar7->_padding_ + 0x18))();
            iVar11 = 1;
          }
        }
      }
    }
    if (iVar11 == 0) {
      if (pRVar5 == (RGE_Task *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)(**(code **)(this->actions->_padding_ + 4))
                                  (pRVar5,param_1,unaff_EBP,unaff_EBX,param_4);
      }
      if (piVar9 == (int *)0x0) {
        uVar3 = 1;
        (**(code **)(this->_padding_ + 0x9c))(param_1,unaff_EBP,unaff_EBX,param_4);
      }
      else {
        uVar3 = (**(code **)(*piVar9 + 0x18))();
        (**(code **)(this->_padding_ + 0x208))(piVar9);
      }
    }
    if ((UnitAIModule *)this->_padding_ != (UnitAIModule *)0x0) {
      iVar11 = -1;
      iVar12 = -1;
      switch(uVar3) {
      case 1:
        iVar12 = 0x262;
        iVar11 = 0x2c6;
        break;
      case 3:
        iVar12 = 0x269;
        iVar11 = 0x2cd;
        break;
      case 4:
        iVar12 = 0x25d;
        iVar11 = 0x2c1;
        break;
      case 5:
        iVar12 = 0x261;
        iVar11 = 0x2c5;
        break;
      case 9:
        iVar12 = 600;
        iVar11 = 700;
        break;
      case 0xc:
        iVar12 = 0x266;
        iVar11 = 0x2ca;
        break;
      case 0x65:
        iVar12 = 0x25a;
        iVar11 = 0x2be;
        break;
      case 0x68:
        iVar12 = 0x25c;
        iVar11 = 0x2c0;
        break;
      case 0x69:
        iVar12 = 0x25b;
        iVar11 = 0x2bf;
        break;
      case 0x6a:
        iVar12 = 0x26a;
        iVar11 = 0x2ce;
        break;
      case 0x6e:
        iVar12 = 0x265;
        iVar11 = 0x2c9;
        break;
      case 0x6f:
        iVar12 = 0x267;
        iVar11 = 0x2cb;
      }
      UnitAIModule::setCurrentOrder((UnitAIModule *)this->_padding_,iVar11);
      UnitAIModule::setCurrentAction((UnitAIModule *)this->_padding_,iVar12);
      if (param_1 == (RGE_Static_Object *)0x0) {
        iVar11 = -1;
        lVar10 = -1;
      }
      else {
        lVar10 = param_1->id;
        iVar11 = (int)param_1->master_obj->object_group;
      }
      UnitAIModule::setCurrentTarget
                ((UnitAIModule *)this->_padding_,lVar10,iVar11,unaff_EBP,unaff_EBX,(float)this);
      UnitAIModule::setTaskedByPlayer((UnitAIModule *)this->_padding_);
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_attack
// Address: 00406830
/* public: virtual void __thiscall RGE_Action_Object::set_attack(class RGE_Static_Object *) */

void __thiscall RGE_Action_Object::set_attack(RGE_Action_Object *this,RGE_Static_Object *param_1)
{
  return;
}

// --------------------------------------------------

// Function: play_command_sound
// Address: 00406840
/* public: virtual void __thiscall RGE_Action_Object::play_command_sound(void) */

void __thiscall RGE_Action_Object::play_command_sound(RGE_Action_Object *this)
{
                    /* WARNING: Could not recover jumptable at 0x00406845. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_padding_ + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: play_move_sound
// Address: 00406850
/* public: virtual void __thiscall RGE_Action_Object::play_move_sound(void) */

void __thiscall RGE_Action_Object::play_move_sound(RGE_Action_Object *this)
{
                    /* WARNING: Could not recover jumptable at 0x00406855. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_padding_ + 0x30))();
  return;
}

// --------------------------------------------------

// Function: get_command_master
// Address: 00406860
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Action_Object::get_command_master(class RGE_Static_Object *,float,float,float) */

RGE_Master_Static_Object * __thiscall
RGE_Action_Object::get_command_master
          (RGE_Action_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  RGE_Master_Static_Object *pRVar1;
  int iVar2;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  int iVar3;
  
  if (((RGE_Action_Object *)param_1 != this) && (*(char *)(this->_padding_ + 0xec) != '\0')) {
    iVar2 = (**(code **)(**(int **)(this->_padding_ + 0xd8) + 4))
                      (this,param_1,param_2,param_3,param_4);
    if (iVar2 != 0) {
      return (RGE_Master_Static_Object *)this->_padding_;
    }
    if (*(char *)&((RGE_Master_Static_Object *)this->_padding_)[1].radius_y != '\0') {
      iVar2 = this->_padding_;
      iVar3 = 0;
      if (0 < *(short *)(iVar2 + 0x22)) {
        while ((((pRVar1 = *(RGE_Master_Static_Object **)(*(int *)(iVar2 + 0x24) + iVar3 * 4),
                 pRVar1 == (RGE_Master_Static_Object *)0x0 ||
                 (iVar2 = this->_padding_, pRVar1->object_group != *(short *)(iVar2 + 0x14))) ||
                (pRVar1->master_type != *(uchar *)(iVar2 + 4))) ||
               ((*(char *)&pRVar1[1].radius_y != *(char *)(iVar2 + 0xec) ||
                (iVar2 = (**(code **)(*(int *)(pRVar1[1].undead_sprite)->pict_name + 4))
                                   (this,param_1,unaff_ESI,unaff_EBP,param_4), iVar2 == 0))))) {
          iVar2 = this->_padding_;
          iVar3 = iVar3 + 1;
          if (*(short *)(iVar2 + 0x22) <= iVar3) {
            return (RGE_Master_Static_Object *)this->_padding_;
          }
        }
        return pRVar1;
      }
    }
  }
  return (RGE_Master_Static_Object *)this->_padding_;
}

// --------------------------------------------------

// Function: set_task
// Address: 00406940
/* public: virtual void __thiscall RGE_Action_Object::set_task(short) */

void __thiscall RGE_Action_Object::set_task(RGE_Action_Object *this,short param_1)
{
  RGE_Task *pRVar1;
  int iVar2;
  
  pRVar1 = RGE_Master_Action_Object::get_task((RGE_Master_Action_Object *)this->_padding_,param_1);
  if (pRVar1 != (RGE_Task *)0x0) {
    iVar2 = (**(code **)(this->actions->_padding_ + 4))(pRVar1,0,0xbf800000,0xbf800000,0xbf800000);
    if (iVar2 != 0) {
      (**(code **)(this->_padding_ + 0x208))(iVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: setTaskByTaskID
// Address: 00406990
/* public: virtual void __thiscall RGE_Action_Object::setTaskByTaskID(int) */

void __thiscall RGE_Action_Object::setTaskByTaskID(RGE_Action_Object *this,int param_1)
{
  RGE_Task *pRVar1;
  int iVar2;
  
  pRVar1 = RGE_Master_Action_Object::getTaskByTaskID
                     ((RGE_Master_Action_Object *)this->_padding_,param_1);
  if (pRVar1 != (RGE_Task *)0x0) {
    iVar2 = (**(code **)(this->actions->_padding_ + 4))(pRVar1,0,0xbf800000,0xbf800000,0xbf800000);
    if (iVar2 != 0) {
      (**(code **)(this->_padding_ + 0x208))(iVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_action
// Address: 004069e0
/* public: virtual void __thiscall RGE_Action_Object::set_action(class RGE_Action *) */

void __thiscall RGE_Action_Object::set_action(RGE_Action_Object *this,RGE_Action *param_1)
{
  if (param_1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action(this->actions,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: set_only_action
// Address: 00406a00
/* public: virtual void __thiscall RGE_Action_Object::set_only_action(class RGE_Action *) */

void __thiscall RGE_Action_Object::set_only_action(RGE_Action_Object *this,RGE_Action *param_1)
{
  RGE_Action_List::delete_list(this->actions);
  if (param_1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action(this->actions,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: set_end_action
// Address: 00406a30
/* public: virtual void __thiscall RGE_Action_Object::set_end_action(class RGE_Action *) */

void __thiscall RGE_Action_Object::set_end_action(RGE_Action_Object *this,RGE_Action *param_1)
{
  if (param_1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action_at_end(this->actions,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: stop
// Address: 00406a50
/* public: virtual void __thiscall RGE_Action_Object::stop(void) */

void __thiscall RGE_Action_Object::stop(RGE_Action_Object *this)
{
  int iVar1;
  
  iVar1 = RGE_Action_List::action_stop(this->actions);
  if (iVar1 == 0) {
    RGE_Action_List::delete_list(this->actions);
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00406a70
// [HELPER] s_t_d___d__d__d__d__d_: "t%d, %d,%d,%d,%d,%d\n"
/* public: virtual unsigned char __thiscall RGE_Action_Object::update(void) */

uchar __thiscall RGE_Action_Object::update(RGE_Action_Object *this)
{
  byte bVar1;
  RGE_Action_List *this_00;
  uchar uVar2;
  char cVar3;
  short sVar4;
  RGE_Action *pRVar5;
  undefined2 extraout_var;
  uint uVar6;
  int iVar7;
  
  if (actionFile != (_iobuf *)0x0) {
    uVar2 = RGE_Action_List::have_action(this->actions);
    if (uVar2 == '\0') {
      iVar7 = -1;
      uVar6 = 0xffffffff;
    }
    else {
      pRVar5 = RGE_Action_List::get_action(this->actions);
      sVar4 = (**(code **)(pRVar5->_padding_ + 0x18))();
      iVar7 = (int)sVar4;
      pRVar5 = RGE_Action_List::get_action(this->actions);
      uVar6 = (uint)pRVar5->state;
    }
    if ((this->lastActionValue != iVar7) || (this->lastActionStateValue != uVar6)) {
      fprintf(actionFile,s_t_d___d__d__d__d__d_,
              *(undefined4 *)(*(int *)(this->_padding_ + 0x3c) + 4),this->_padding_,
              this->lastActionValue,this->lastActionStateValue,iVar7,uVar6);
      this->lastActionValue = iVar7;
      this->lastActionStateValue = uVar6;
    }
  }
  uVar2 = RGE_Animated_Object::update((RGE_Animated_Object *)this);
  this_00 = this->actions;
  bVar1 = (byte)this->_padding_;
  if (bVar1 < 3) {
    if (this_00->list == (RGE_Action_Node *)0x0) {
      if ((bVar1 == 2) && (sVar4 = *(short *)(this->_padding_ + 0xdc), sVar4 != -1)) {
        (**(code **)(this->_padding_ + 0x1fc))(CONCAT22(extraout_var,sVar4));
        return uVar2;
      }
    }
    else {
      if (this->_padding_ != 0) {
        (**(code **)(this_00->_padding_ + 8))();
        return uVar2;
      }
      cVar3 = (**(code **)(this_00->_padding_ + 0xc))();
      if ((cVar3 == '\x03') || (cVar3 == '\x01')) {
        RGE_Action_List::remove_action(this->actions);
      }
    }
  }
  else if (this_00->list != (RGE_Action_Node *)0x0) {
    RGE_Action_List::delete_list(this_00);
    return uVar2;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: change_ownership
// Address: 00406b90
/* public: virtual void __thiscall RGE_Action_Object::change_ownership(class RGE_Player *) */

void __thiscall RGE_Action_Object::change_ownership(RGE_Action_Object *this,RGE_Player *param_1)
{
  int iVar1;
  
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0xa4))();
  RGE_Static_Object::change_ownership((RGE_Static_Object *)this,param_1);
  (**(code **)(iVar1 + 0x208))(0);
  return;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 00406bc0
/* public: virtual void __thiscall RGE_Action_Object::copy_obj(class RGE_Master_Static_Object *) */

void __thiscall
RGE_Action_Object::copy_obj(RGE_Action_Object *this,RGE_Master_Static_Object *param_1)
{
  (**(code **)(this->actions->_padding_ + 0x14))(param_1);
  RGE_Moving_Object::copy_obj((RGE_Moving_Object *)this,param_1);
  return;
}

// --------------------------------------------------

// Function: have_action
// Address: 00406bf0
/* public: unsigned char __thiscall RGE_Action_Object::have_action(void) */

uchar __thiscall RGE_Action_Object::have_action(RGE_Action_Object *this)
{
  uchar uVar1;
  
  uVar1 = RGE_Action_List::have_action(this->actions);
  return uVar1 != '\0';
}

// --------------------------------------------------

// Function: get_target_obj
// Address: 00406c10
/* public: virtual class RGE_Static_Object * __thiscall RGE_Action_Object::get_target_obj(void) */

RGE_Static_Object * __thiscall RGE_Action_Object::get_target_obj(RGE_Action_Object *this)
{
  RGE_Action *pRVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar1 = RGE_Action_List::get_action(this->actions);
  if (pRVar1 != (RGE_Action *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00406c23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pRVar2 = (RGE_Static_Object *)(**(code **)(pRVar1->_padding_ + 0x4c))();
    return pRVar2;
  }
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: getTask
// Address: 00406c30
/* public: virtual class RGE_Task * __thiscall RGE_Action_Object::getTask(class RGE_Static_Object
   *,float,float,float) */

RGE_Task * __thiscall
RGE_Action_Object::getTask
          (RGE_Action_Object *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  int iVar1;
  RGE_Task *pRVar2;
  int iVar3;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iVar4;
  
  pRVar2 = (RGE_Task *)
           (**(code **)(**(int **)(this->_padding_ + 0xd8) + 4))
                     (this,param_1,param_2,param_3,param_4);
  if ((pRVar2 == (RGE_Task *)0x0) && (*(char *)(this->_padding_ + 0xec) != '\0')) {
    iVar3 = this->_padding_;
    iVar4 = 0;
    if (0 < *(short *)(iVar3 + 0x22)) {
      while ((((iVar3 = *(int *)(*(int *)(iVar3 + 0x24) + iVar4 * 4), iVar3 == 0 ||
               (iVar1 = this->_padding_, *(short *)(iVar3 + 0x14) != *(short *)(iVar1 + 0x14))) ||
              (*(char *)(iVar3 + 4) != *(char *)(iVar1 + 4))) ||
             ((*(char *)(iVar3 + 0xec) != *(char *)(iVar1 + 0xec) ||
              (pRVar2 = (RGE_Task *)
                        (**(code **)(**(int **)(iVar3 + 0xd8) + 4))
                                  (this,unaff_EDI,unaff_ESI,unaff_EBP,param_4),
              pRVar2 == (RGE_Task *)0x0))))) {
        iVar3 = this->_padding_;
        iVar4 = iVar4 + 1;
        if (*(short *)(iVar3 + 0x22) <= iVar4) {
          return (RGE_Task *)0x0;
        }
      }
      (**(code **)(this->_padding_ + 0x54))(iVar3);
    }
  }
  return pRVar2;
}

// --------------------------------------------------

// Function: actionState
// Address: 00406d00
/* public: virtual unsigned char __thiscall RGE_Action_Object::actionState(void)const  */

uchar __thiscall RGE_Action_Object::actionState(RGE_Action_Object *this)
{
  uchar uVar1;
  RGE_Action *pRVar2;
  
  uVar1 = RGE_Action_List::have_action(this->actions);
  if (uVar1 == '\x01') {
    pRVar2 = RGE_Action_List::get_action(this->actions);
    return pRVar2->state;
  }
  return '\0';
}

// --------------------------------------------------

// Function: get_action_checksum
// Address: 00406d30
/* public: virtual long __thiscall RGE_Action_Object::get_action_checksum(void) */

long __thiscall RGE_Action_Object::get_action_checksum(RGE_Action_Object *this)
{
  RGE_Action *pRVar1;
  long lVar2;
  
  lVar2 = 0;
  if (this->actions != (RGE_Action_List *)0x0) {
    pRVar1 = RGE_Action_List::get_action(this->actions);
    if (pRVar1 != (RGE_Action *)0x0) {
      lVar2 = (int)pRVar1->action_type + (uint)pRVar1->state;
    }
  }
  return lVar2;
}

// --------------------------------------------------

// Function: rehook
// Address: 0045a8ff
void __thiscall RGE_Action_Object::rehook(RGE_Action_Object *this)
{
  RGE_Static_Object::rehook((RGE_Static_Object *)this);
  RGE_Action_List::rehook(this->actions);
  return;
}

// --------------------------------------------------

