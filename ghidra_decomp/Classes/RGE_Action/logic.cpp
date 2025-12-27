// Class: RGE_Action
// Function: get_target_obj
// Address: 00401130
/* public: virtual class RGE_Static_Object * __thiscall RGE_Action::get_target_obj(void) */

RGE_Static_Object * __thiscall RGE_Action::get_target_obj(RGE_Action *this)
{
  return this->target_obj;
}

// --------------------------------------------------

// Function: get_target_obj2
// Address: 00401140
/* public: virtual class RGE_Static_Object * __thiscall RGE_Action::get_target_obj2(void) */

RGE_Static_Object * __thiscall RGE_Action::get_target_obj2(RGE_Action *this)
{
  return this->target_obj2;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 0040202e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 00402b8e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 00402f2e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004049fe
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 00404c7e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 00406dae
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: RGE_Action
// Address: 00407460
/* public: __thiscall RGE_Action::RGE_Action(int,class RGE_Action_Object *,int) */

RGE_Action * __thiscall
RGE_Action::RGE_Action(RGE_Action *this,int param_1,RGE_Action_Object *param_2,int param_3)
{
  this->targetID = -1;
  this->target2ID = -1;
  this->_padding_ = (int)&_vftable_;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004074a0
/* public: virtual void * __thiscall RGE_Action::`vector deleting destructor'(unsigned int) */

void * __thiscall RGE_Action::_vector_deleting_destructor_(RGE_Action *this,uint param_1)
{
  ~RGE_Action(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Action
// Address: 004074c0
/* public: __thiscall RGE_Action::RGE_Action(class RGE_Action_Object *,int) */

RGE_Action * __thiscall
RGE_Action::RGE_Action(RGE_Action *this,RGE_Action_Object *param_1,int param_2)
{
  this->targetID = -1;
  this->target2ID = -1;
  this->_padding_ = (int)&_vftable_;
  if (param_2 != 0) {
    setup(this,param_1);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004074f0
/* public: virtual __thiscall RGE_Action::~RGE_Action(void) */

void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 00407530
/* WARNING: Variable defined which should be unmapped: short_val */
/* public: virtual int __thiscall RGE_Action::setup(int,class RGE_Action_Object *) */

int __thiscall RGE_Action::setup(RGE_Action *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action_List *pRVar1;
  RGE_Sprite *pRVar2;
  short unaff_BX;
  int unaff_retaddr;
  short short_val;
  RGE_Action *pRStack_4;
  
  this->action_type = 0;
  this->obj = param_2;
  pRStack_4 = this;
  short_val = unaff_BX;
  pRVar1 = (RGE_Action_List *)(**(code **)(this->_padding_ + 0xc))(param_2);
  this->sub_actions = pRVar1;
  rge_read(unaff_retaddr,&this->state,1);
  rge_read(unaff_retaddr,&param_1,4);
  if (param_1 == -1) {
    this->target_obj = (RGE_Static_Object *)0x0;
  }
  else {
    this->target_obj = (RGE_Static_Object *)param_1;
  }
  rge_read(unaff_retaddr,&param_1,4);
  if (param_1 == -1) {
    this->target_obj2 = (RGE_Static_Object *)0x0;
  }
  else {
    this->target_obj2 = (RGE_Static_Object *)param_1;
  }
  rge_read(unaff_retaddr,&this->targetID,4);
  rge_read(unaff_retaddr,&this->target2ID,4);
  rge_read(unaff_retaddr,&this->target_x,4);
  rge_read(unaff_retaddr,&this->target_y,4);
  rge_read(unaff_retaddr,&this->target_z,4);
  rge_read(unaff_retaddr,&this->timer,4);
  rge_read(unaff_retaddr,&short_val,2);
  if (short_val == -1) {
    this->task = (RGE_Task *)0x0;
  }
  else {
    this->task = *(RGE_Task **)(*(int *)(*(int *)(this->obj->_padding_ + 0xd8) + 4) + short_val * 4)
    ;
  }
  rge_read(unaff_retaddr,&this->subActionValue,1);
  RGE_Action_List::load(this->sub_actions,unaff_retaddr);
  rge_read(unaff_retaddr,&short_val,2);
  pRVar2 = RGE_Static_Object::get_sprite_pointer((RGE_Static_Object *)this->obj,short_val);
  this->sprite = pRVar2;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00407680
/* public: virtual int __thiscall RGE_Action::setup(class RGE_Action_Object *) */

int __thiscall RGE_Action::setup(RGE_Action *this,RGE_Action_Object *param_1)
{
  RGE_Action_List *pRVar1;
  
  this->action_type = 0;
  this->obj = param_1;
  this->state = '\0';
  this->target_obj = (RGE_Static_Object *)0x0;
  this->target_obj2 = (RGE_Static_Object *)0x0;
  this->target_x = 0.0;
  this->target_y = 0.0;
  this->target_z = 0.0;
  this->timer = 0.0;
  this->task = (RGE_Task *)0x0;
  pRVar1 = (RGE_Action_List *)(**(code **)(this->_padding_ + 0xc))(param_1);
  this->sub_actions = pRVar1;
  this->sprite = (RGE_Sprite *)0x0;
  this->subActionValue = '\0';
  return 1;
}

// --------------------------------------------------

// Function: create_action_list
// Address: 004076d0
/* public: virtual class RGE_Action_List * __thiscall RGE_Action::create_action_list(class
   RGE_Action_Object *) */

RGE_Action_List * __thiscall
RGE_Action::create_action_list(RGE_Action *this,RGE_Action_Object *param_1)
{
  RGE_Action_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c42b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Action_List *)operator_new(0xc);
  local_4 = 0;
  if (pRVar1 != (RGE_Action_List *)0x0) {
    pRVar1 = (RGE_Action_List *)RGE_Action_List::RGE_Action_List(pRVar1,this->obj);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Action_List *)0x0;
}

// --------------------------------------------------

// Function: rehook
// Address: 00407740
/* public: virtual void __thiscall RGE_Action::rehook(void) */

void __thiscall RGE_Action::rehook(RGE_Action *this)
{
  RGE_Static_Object *pRVar1;
  
  if (this->target_obj != (RGE_Static_Object *)0x0) {
    pRVar1 = RGE_Static_Object::get_object_pointer
                       ((RGE_Static_Object *)this->obj,(long)this->target_obj);
    this->target_obj = pRVar1;
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      this->targetID = pRVar1->id;
    }
  }
  if (this->target_obj2 != (RGE_Static_Object *)0x0) {
    pRVar1 = RGE_Static_Object::get_object_pointer
                       ((RGE_Static_Object *)this->obj,(long)this->target_obj2);
    this->target_obj2 = pRVar1;
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      this->target2ID = pRVar1->id;
    }
  }
  if (this->sub_actions != (RGE_Action_List *)0x0) {
    RGE_Action_List::rehook(this->sub_actions);
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00407790
/* WARNING: Variable defined which should be unmapped: short_val */
/* public: virtual void __thiscall RGE_Action::save(int) */

void __thiscall RGE_Action::save(RGE_Action *this,int param_1)
{
  RGE_Task *pRVar1;
  int iVar2;
  undefined2 extraout_var;
  short short_val;
  RGE_Action *local_4;
  
  iVar2 = param_1;
  local_4 = this;
  rge_write(param_1,&this->action_type,2);
  rge_write(iVar2,&this->state,1);
  if (this->target_obj == (RGE_Static_Object *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = this->target_obj->id;
  }
  rge_write(iVar2,&param_1,4);
  if (this->target_obj2 == (RGE_Static_Object *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = this->target_obj2->id;
  }
  rge_write(iVar2,&param_1,4);
  rge_write(iVar2,&this->targetID,4);
  rge_write(iVar2,&this->target2ID,4);
  rge_write(iVar2,&this->target_x,4);
  rge_write(iVar2,&this->target_y,4);
  rge_write(iVar2,&this->target_z,4);
  rge_write(iVar2,&this->timer,4);
  pRVar1 = this->task;
  if (pRVar1 == (RGE_Task *)0x0) {
    local_4 = (RGE_Action *)0xffffffff;
  }
  else {
    local_4 = (RGE_Action *)CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id);
  }
  rge_write(iVar2,&local_4,2);
  rge_write(iVar2,&this->subActionValue,1);
  RGE_Action_List::save(this->sub_actions,iVar2);
  if (this->sprite == (RGE_Sprite *)0x0) {
    local_4 = (RGE_Action *)0xffffffff;
  }
  else {
    local_4 = (RGE_Action *)CONCAT22(extraout_var,this->sprite->id);
  }
  rge_write(iVar2,&local_4,2);
  return;
}

// --------------------------------------------------

// Function: type
// Address: 004078d0
/* public: virtual short __thiscall RGE_Action::type(void) */

short __thiscall RGE_Action::type(RGE_Action *this)
{
  return this->action_type;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004078e0
/* public: virtual void __thiscall RGE_Action::first_in_stack(unsigned char) */

void __thiscall RGE_Action::first_in_stack(RGE_Action *this,uchar param_1)
{
  return;
}

// --------------------------------------------------

// Function: stop
// Address: 004078f0
/* public: virtual int __thiscall RGE_Action::stop(void) */

int __thiscall RGE_Action::stop(RGE_Action *this)
{
  return 0;
}

// --------------------------------------------------

// Function: move_to
// Address: 00407900
/* public: virtual int __thiscall RGE_Action::move_to(class RGE_Static_Object *,float,float,float)
    */

int __thiscall
RGE_Action::move_to(RGE_Action *this,RGE_Static_Object *param_1,float param_2,float param_3,
                   float param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: work
// Address: 00407910
/* public: virtual int __thiscall RGE_Action::work(class RGE_Static_Object *,float,float,float) */

int __thiscall
RGE_Action::work(RGE_Action *this,RGE_Static_Object *param_1,float param_2,float param_3,
                float param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: attack_response
// Address: 00407920
/* public: virtual unsigned char __thiscall RGE_Action::attack_response(class RGE_Static_Object *)
    */

uchar __thiscall RGE_Action::attack_response(RGE_Action *this,RGE_Static_Object *param_1)
{
  return '\0';
}

// --------------------------------------------------

// Function: relation_response
// Address: 00407930
/* public: virtual unsigned char __thiscall RGE_Action::relation_response(long,unsigned char) */

uchar __thiscall RGE_Action::relation_response(RGE_Action *this,long param_1,uchar param_2)
{
  return '\0';
}

// --------------------------------------------------

// Function: set_state
// Address: 00407940
/* protected: virtual void __thiscall RGE_Action::set_state(unsigned char) */

void __thiscall RGE_Action::set_state(RGE_Action *this,uchar param_1)
{
  this->state = param_1;
  return;
}

// --------------------------------------------------

// Function: inside_obj_update
// Address: 00407950
/* public: virtual unsigned char __thiscall RGE_Action::inside_obj_update(void) */

uchar __thiscall RGE_Action::inside_obj_update(RGE_Action *this)
{
  if ((this->target_obj != (RGE_Static_Object *)0x0) && (6 < this->target_obj->object_state)) {
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if ((this->target_obj2 != (RGE_Static_Object *)0x0) && (6 < this->target_obj2->object_state)) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: idle_update
// Address: 00407990
/* public: virtual unsigned char __thiscall RGE_Action::idle_update(void) */

uchar __thiscall RGE_Action::idle_update(RGE_Action *this)
{
  if ((this->target_obj != (RGE_Static_Object *)0x0) && (6 < this->target_obj->object_state)) {
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if ((this->target_obj2 != (RGE_Static_Object *)0x0) && (6 < this->target_obj2->object_state)) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: update
// Address: 004079d0
/* public: virtual unsigned char __thiscall RGE_Action::update(void) */

uchar __thiscall RGE_Action::update(RGE_Action *this)
{
  uchar uVar1;
  
  if ((this->target_obj != (RGE_Static_Object *)0x0) && (6 < this->target_obj->object_state)) {
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if ((this->target_obj2 != (RGE_Static_Object *)0x0) && (6 < this->target_obj2->object_state)) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  if (this->sub_actions->list != (RGE_Action_Node *)0x0) {
    uVar1 = (**(code **)(this->sub_actions->_padding_ + 0xc))();
    return uVar1;
  }
  return this->state == '\x01';
}

// --------------------------------------------------

// Function: set_target_obj
// Address: 00407a20
/* public: virtual void __thiscall RGE_Action::set_target_obj(class RGE_Static_Object *) */

void __thiscall RGE_Action::set_target_obj(RGE_Action *this,RGE_Static_Object *param_1)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((this->target_obj != (RGE_Static_Object *)0x0) && (this->target_obj != param_1)) {
    pRVar2 = RGE_Game_World::object
                       (*(RGE_Game_World **)(this->obj->_padding_ + 0x3c),this->targetID);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar2->_padding_ + 0xc4))(this->obj);
    }
  }
  if (this->target_obj != param_1) {
    this->target_obj = param_1;
    if (param_1 != (RGE_Static_Object *)0x0) {
      iVar1 = param_1->_padding_;
      this->targetID = param_1->id;
      (**(code **)(iVar1 + 0xc0))(this->obj,this->action_type,0);
      return;
    }
    this->targetID = -1;
  }
  return;
}

// --------------------------------------------------

// Function: set_target_obj2
// Address: 00407a90
/* public: virtual void __thiscall RGE_Action::set_target_obj2(class RGE_Static_Object *) */

void __thiscall RGE_Action::set_target_obj2(RGE_Action *this,RGE_Static_Object *param_1)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((this->target_obj2 != (RGE_Static_Object *)0x0) && (this->target_obj2 != param_1)) {
    pRVar2 = RGE_Game_World::object
                       (*(RGE_Game_World **)(this->obj->_padding_ + 0x3c),this->target2ID);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar2->_padding_ + 0xc4))(this->obj);
    }
  }
  if (this->target_obj2 != param_1) {
    this->target_obj2 = param_1;
    if (param_1 != (RGE_Static_Object *)0x0) {
      iVar1 = param_1->_padding_;
      this->target2ID = param_1->id;
      (**(code **)(iVar1 + 0xc0))(this->obj,this->action_type,0);
      return;
    }
    this->target2ID = -1;
  }
  return;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 00407b00
/* WARNING: Variable defined which should be unmapped: new_sprite */
/* public: virtual void __thiscall RGE_Action::copy_obj(class RGE_Master_Action_Object *) */

void __thiscall RGE_Action::copy_obj(RGE_Action *this,RGE_Master_Action_Object *param_1)
{
  RGE_Task_List *pRVar1;
  RGE_Task **ppRVar2;
  RGE_Task *pRVar3;
  RGE_Sprite *pRVar4;
  RGE_Sprite *pRVar5;
  RGE_Task **ppRVar6;
  int iVar7;
  RGE_Sprite *new_sprite;
  RGE_Sprite *local_4;
  
  local_4 = (RGE_Sprite *)0x0;
  if ((this->task == (RGE_Task *)0x0) || (pRVar1 = param_1->tasks, pRVar1 == (RGE_Task_List *)0x0))
{
    (**(code **)(this->_padding_ + 0x44))(param_1,0,0);
    (**(code **)(this->sub_actions->_padding_ + 0x18))(param_1,0,0);
  }
  else {
    ppRVar2 = pRVar1->list;
    iVar7 = pRVar1->list_num + -1;
    if (-1 < iVar7) {
      ppRVar6 = ppRVar2 + iVar7;
      do {
        if ((*ppRVar6)->action_type == this->task->action_type) break;
        iVar7 = iVar7 + -1;
        ppRVar6 = ppRVar6 + -1;
      } while (-1 < iVar7);
    }
    if (-1 < iVar7) {
      pRVar3 = ppRVar2[iVar7];
      pRVar4 = (RGE_Sprite *)this->obj->_padding_;
      pRVar5 = pRVar3->move_sprite;
      if ((((pRVar4 != pRVar3->move_sprite) &&
           (pRVar5 = pRVar3->work_sprite, pRVar4 != pRVar3->work_sprite)) &&
          (pRVar5 = pRVar3->work_sprite2, pRVar4 != pRVar3->work_sprite2)) &&
         (pRVar5 = local_4, pRVar4 == pRVar3->carry_sprite)) {
        pRVar5 = pRVar3->carry_sprite;
      }
      local_4 = pRVar5;
      if (local_4 != (RGE_Sprite *)0x0) {
        (**(code **)(this->obj->_padding_ + 0x38))(local_4);
      }
      (**(code **)(this->_padding_ + 0x44))(param_1,this->task,ppRVar2[iVar7]);
      (**(code **)(this->sub_actions->_padding_ + 0x18))(param_1,this->task,ppRVar2[iVar7]);
      this->task = ppRVar2[iVar7];
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: copy_obj_sprites
// Address: 00407c00
/* public: virtual void __thiscall RGE_Action::copy_obj_sprites(class RGE_Master_Action_Object
   *,class RGE_Task *,class RGE_Task *) */

void __thiscall
RGE_Action::copy_obj_sprites
          (RGE_Action *this,RGE_Master_Action_Object *param_1,RGE_Task *param_2,RGE_Task *param_3)
{
  return;
}

// --------------------------------------------------

// Function: get_state_name
// Address: 00407c10
// [HELPER] s_Attack: "Attack"
// [HELPER] s_Delay: "Delay"
// [HELPER] s_Done: "Done"
// [HELPER] s_Failed: "Failed"
// [HELPER] s_Goto2: "Goto2"
// [HELPER] s_Goto: "Goto"
// [HELPER] s_Invalidated: "Invalidated"
// [HELPER] s_Move: "Move"
// [HELPER] s_MoveNoSearch: "MoveNoSearch"
// [HELPER] s_None: "None"
// [HELPER] s_Return: "Return"
// [HELPER] s_Search: "Search"
// [HELPER] s_Turn: "Turn"
// [HELPER] s_Unknown: "Unknown"
// [HELPER] s_Wait: "Wait"
// [HELPER] s_Work2: "Work2"
// [HELPER] s_Work: "Work"
/* public: virtual void __thiscall RGE_Action::get_state_name(char *) */

void __thiscall RGE_Action::get_state_name(RGE_Action *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  switch(this->state) {
  case '\0':
    pcVar5 = &s_None;
    break;
  case '\x01':
    pcVar5 = s_Done;
    goto LAB_00407c9b;
  case '\x02':
    pcVar5 = &s_Wait;
    break;
  case '\x03':
    pcVar5 = s_Search;
    goto LAB_00407c9b;
  case '\x04':
    pcVar5 = s_Goto;
    break;
  case '\x05':
    pcVar5 = s_Goto2;
    goto LAB_00407c9b;
  case '\x06':
    pcVar5 = s_Work;
    break;
  case '\a':
    pcVar5 = s_Work2;
    goto LAB_00407c9b;
  case '\b':
    pcVar5 = s_Return;
    break;
  case '\t':
    pcVar5 = s_Turn;
    goto LAB_00407c9b;
  case '\n':
    pcVar5 = s_Delay;
    break;
  case '\v':
    pcVar5 = &s_Move;
    goto LAB_00407c9b;
  case '\f':
    pcVar5 = &s_Attack;
    break;
  case '\r':
    pcVar5 = s_Failed;
    goto LAB_00407c9b;
  case '\x0e':
    pcVar5 = &s_Invalidated;
    break;
  case '\x0f':
    pcVar5 = &s_MoveNoSearch;
LAB_00407c9b:
    uVar2 = 0xffffffff;
    do {
      pcVar4 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar4 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar4;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar4 + -uVar2;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      param_1 = param_1 + 1;
    }
    return;
  default:
    pcVar5 = &s_Unknown;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar4 + -uVar2;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: targetX
// Address: 00407d30
/* public: float __thiscall RGE_Action::targetX(void)const  */

float __thiscall RGE_Action::targetX(RGE_Action *this)
{
  return this->target_x;
}

// --------------------------------------------------

// Function: targetY
// Address: 00407d40
/* public: float __thiscall RGE_Action::targetY(void)const  */

float __thiscall RGE_Action::targetY(RGE_Action *this)
{
  return this->target_y;
}

// --------------------------------------------------

// Function: targetZ
// Address: 00407d50
/* public: float __thiscall RGE_Action::targetZ(void)const  */

float __thiscall RGE_Action::targetZ(RGE_Action *this)
{
  return this->target_z;
}

// --------------------------------------------------

// Function: subAction
// Address: 00407d60
/* public: unsigned char __thiscall RGE_Action::subAction(void)const  */

uchar __thiscall RGE_Action::subAction(RGE_Action *this)
{
  return this->subActionValue;
}

// --------------------------------------------------

// Function: setSubAction
// Address: 00407d70
/* public: void __thiscall RGE_Action::setSubAction(unsigned char) */

void __thiscall RGE_Action::setSubAction(RGE_Action *this,uchar param_1)
{
  this->subActionValue = param_1;
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004ccbee
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004cd1fe
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004cda7e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004ce5de
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004ce97e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004cf11e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004d170e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004d26fe
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action
// Address: 004d396e
void __thiscall RGE_Action::~RGE_Action(RGE_Action *this)
{
  RGE_Action_List *this_00;
  
  this->_padding_ = (int)&_vftable_;
  set_target_obj(this,(RGE_Static_Object *)0x0);
  set_target_obj2(this,(RGE_Static_Object *)0x0);
  this_00 = this->sub_actions;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    this->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

