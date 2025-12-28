// Class: RGE_Action_List
// Size:  0xC
//
// VTable Layout:
// [00] create_action
// [01] create_task_action
// [02] inside_obj_update
// [03] update
// [04] get_action_name
// [05] copy_obj
// [06] copy_obj_sprites
//
// Member Layout:
// [0x004] RGE_Action_Object * obj
// [0x008] RGE_Action_Node * list
// ----------------------------------------------------------------

// Function: RGE_Action_List
// Address: 00403ea0
void __thiscall RGE_Action_List::RGE_Action_List(RGE_Action_List *this,RGE_Action_Object *param_1)
{
  this->_padding_ = (int)&_vftable_;
  this->obj = param_1;
  this->list = (RGE_Action_Node *)0x0;
  return;
}

// --------------------------------------------------

// Function: ~RGE_Action_List
// Address: 00403ec0
void __thiscall RGE_Action_List::~RGE_Action_List(RGE_Action_List *this)
{
  this->_padding_ = (int)&_vftable_;
  delete_list(this);
  return;
}

// --------------------------------------------------

// Function: load
// Address: 00403ed0
void __thiscall RGE_Action_List::load(RGE_Action_List *this,int param_1)
{
  RGE_Action *pRVar1;
  RGE_Action_Node *pRVar2;
  RGE_Action_Node *pRVar3;
  short action_type;
  RGE_Action_List *local_4;
  
  local_4 = this;
  if (this->list != (RGE_Action_Node *)0x0) {
    delete_list(this);
  }
  pRVar3 = (RGE_Action_Node *)0x0;
  while( true ) {
    rge_read(param_1,&local_4,2);
    if ((short)local_4 == 0) break;
    pRVar1 = (RGE_Action *)(**(code **)this->_padding_)(param_1,local_4);
    pRVar2 = (RGE_Action_Node *)calloc(1,8);
    pRVar2->action = pRVar1;
    pRVar2->next = (RGE_Action_Node *)0x0;
    if (pRVar3 == (RGE_Action_Node *)0x0) {
      this->list = pRVar2;
      pRVar3 = pRVar2;
    }
    else {
      pRVar3->next = pRVar2;
      pRVar3 = pRVar2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: rehook
// Address: 00403f40
void __thiscall RGE_Action_List::rehook(RGE_Action_List *this)
{
  RGE_Action_Node *pRVar1;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Action_Node *)0x0; pRVar1 = pRVar1->next) {
    (**(code **)(pRVar1->action->_padding_ + 0x10))();
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00403f60
void __thiscall RGE_Action_List::save(RGE_Action_List *this,int param_1)
{
  RGE_Action_Node *pRVar1;
  int iVar2;
  
  iVar2 = param_1;
  for (pRVar1 = this->list; pRVar1 != (RGE_Action_Node *)0x0; pRVar1 = pRVar1->next) {
    (**(code **)(pRVar1->action->_padding_ + 0x14))(iVar2);
  }
  param_1 = 0;
  rge_write(iVar2,&param_1,2);
  return;
}

// --------------------------------------------------

// Function: delete_list
// Address: 00403fa0
void __thiscall RGE_Action_List::delete_list(RGE_Action_List *this)
{
  RGE_Action_Node *pRVar1;
  
  pRVar1 = this->list;
  while (pRVar1 != (RGE_Action_Node *)0x0) {
    remove_action(this);
    pRVar1 = this->list;
  }
  return;
}

// --------------------------------------------------

// Function: create_action
// Address: 00403fc0
RGE_Action * __thiscall
RGE_Action_List::create_action(RGE_Action_List *this,int param_1,short param_2)
{
  RGE_Action_Attack *this_00;
  RGE_Action_Bird *this_01;
  RGE_Action_Explore *this_02;
  RGE_Action_Gather *this_03;
  RGE_Action_Missile *this_04;
  RGE_Action_Move_To *this_05;
  RGE_Action_Make *this_06;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c24d;
  *unaff_FS_OFFSET = &local_c;
  switch(param_2) {
  case 1:
    this_05 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 5;
    if (this_05 != (RGE_Action_Move_To *)0x0) {
      pRVar1 = (RGE_Action *)RGE_Action_Move_To::RGE_Action_Move_To(this_05,param_1,this->obj);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 4:
    this_02 = (RGE_Action_Explore *)operator_new(0x40);
    local_4 = 2;
    if (this_02 != (RGE_Action_Explore *)0x0) {
      pRVar1 = (RGE_Action *)RGE_Action_Explore::RGE_Action_Explore(this_02,param_1,this->obj);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 5:
    this_03 = (RGE_Action_Gather *)operator_new(0x44);
    local_4 = 3;
    if (this_03 != (RGE_Action_Gather *)0x0) {
      pRVar1 = (RGE_Action *)RGE_Action_Gather::RGE_Action_Gather(this_03,param_1,this->obj);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 8:
    this_04 = (RGE_Action_Missile *)operator_new(0x54);
    local_4 = 4;
    if (this_04 != (RGE_Action_Missile *)0x0) {
      pRVar1 = (RGE_Action *)RGE_Action_Missile::RGE_Action_Missile(this_04,param_1,this->obj);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 9:
    this_00 = (RGE_Action_Attack *)operator_new(0x5c);
    local_4 = 0;
    if (this_00 != (RGE_Action_Attack *)0x0) {
      pRVar1 = (RGE_Action *)RGE_Action_Attack::RGE_Action_Attack(this_00,param_1,this->obj);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 10:
    this_01 = (RGE_Action_Bird *)operator_new(0x40);
    local_4 = 1;
    if (this_01 != (RGE_Action_Bird *)0x0) {
      pRVar1 = (RGE_Action *)RGE_Action_Bird::RGE_Action_Bird(this_01,param_1,this->obj);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x15:
    this_06 = (RGE_Action_Make *)operator_new(0x40);
    local_4 = 6;
    if (this_06 != (RGE_Action_Make *)0x0) {
      pRVar1 = (RGE_Action *)RGE_Action_Make::RGE_Action_Make(this_06,param_1,this->obj);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Action *)0x0;
}

// --------------------------------------------------

// Function: create_task_action
// Address: 00404200
RGE_Action * __thiscall
RGE_Action_List::create_task_action
          (RGE_Action_List *this,RGE_Task *param_1,RGE_Static_Object *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action_Bird *this_00;
  UnitAIModule *pUVar1;
  RGE_Action_Attack *pRVar2;
  RGE_Action_Explore *this_01;
  RGE_Action_Gather *pRVar3;
  RGE_Action_Make *this_02;
  RGE_Action *pRVar4;
  undefined4 *unaff_FS_OFFSET;
  long lVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float fVar9;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c2ad;
  *unaff_FS_OFFSET = &local_c;
  switch(param_1->action_type) {
  case 4:
    this_01 = (RGE_Action_Explore *)operator_new(0x40);
    local_4 = 3;
    if (this_01 != (RGE_Action_Explore *)0x0) {
      pRVar4 = (RGE_Action *)
               RGE_Action_Explore::RGE_Action_Explore
                         (this_01,this->obj,param_1,param_3,param_4,param_5);
      goto LAB_0040445e;
    }
    break;
  case 5:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pRVar3 = (RGE_Action_Gather *)operator_new(0x44);
      local_4 = 5;
      if (pRVar3 != (RGE_Action_Gather *)0x0) {
        pRVar4 = (RGE_Action *)
                 RGE_Action_Gather::RGE_Action_Gather
                           (pRVar3,this->obj,param_1,param_3,param_4,param_5);
        goto LAB_0040445e;
      }
    }
    else {
      pRVar3 = (RGE_Action_Gather *)operator_new(0x44);
      local_4 = 4;
      if (pRVar3 != (RGE_Action_Gather *)0x0) {
        pRVar4 = (RGE_Action *)
                 RGE_Action_Gather::RGE_Action_Gather(pRVar3,this->obj,param_1,param_2);
        goto LAB_0040445e;
      }
    }
    break;
  case 7:
    pUVar1 = RGE_Static_Object::unitAI((RGE_Static_Object *)this->obj);
    if (pUVar1 != (UnitAIModule *)0x0) {
      iVar8 = 600;
      pUVar1 = RGE_Static_Object::unitAI((RGE_Static_Object *)this->obj);
      UnitAIModule::setCurrentAction(pUVar1,iVar8);
      if (param_2 == (RGE_Static_Object *)0x0) {
        lVar5 = -1;
        fVar6 = param_3;
        fVar7 = param_4;
        fVar9 = param_5;
      }
      else {
        lVar5 = param_2->id;
        fVar6 = param_2->world_x;
        fVar7 = param_2->world_y;
        fVar9 = param_2->world_z;
      }
      pUVar1 = RGE_Static_Object::unitAI((RGE_Static_Object *)this->obj);
      UnitAIModule::setCurrentTarget(pUVar1,lVar5,fVar6,fVar7,fVar9);
    }
    if (param_2 == (RGE_Static_Object *)0x0) {
      pRVar2 = (RGE_Action_Attack *)operator_new(0x5c);
      local_4 = 2;
      if (pRVar2 != (RGE_Action_Attack *)0x0) {
        iVar8 = this->obj->_padding_;
        pRVar4 = (RGE_Action *)
                 RGE_Action_Attack::RGE_Action_Attack
                           (pRVar2,this->obj,param_3,param_4,param_5,param_1->move_sprite,
                            param_1->work_sprite,(RGE_Sprite *)0x0,param_1->work_range,
                            *(float *)(iVar8 + 0x138),*(short *)(iVar8 + 0x124),
                            *(short *)(iVar8 + 0x12a));
        goto LAB_0040445e;
      }
    }
    else {
      pRVar2 = (RGE_Action_Attack *)operator_new(0x5c);
      local_4 = 1;
      if (pRVar2 != (RGE_Action_Attack *)0x0) {
        iVar8 = this->obj->_padding_;
        pRVar4 = (RGE_Action *)
                 RGE_Action_Attack::RGE_Action_Attack
                           (pRVar2,this->obj,param_2,param_1->move_sprite,param_1->work_sprite,
                            (RGE_Sprite *)0x0,param_1->work_range,*(float *)(iVar8 + 0x138),
                            *(short *)(iVar8 + 0x124),*(short *)(iVar8 + 0x12a));
        goto LAB_0040445e;
      }
    }
    break;
  case 10:
    this_00 = (RGE_Action_Bird *)operator_new(0x40);
    local_4 = 0;
    if (this_00 != (RGE_Action_Bird *)0x0) {
      pRVar4 = (RGE_Action *)
               RGE_Action_Bird::RGE_Action_Bird(this_00,this->obj,param_1,param_3,param_4,param_5);
      goto LAB_0040445e;
    }
    break;
  case 0x15:
    this_02 = (RGE_Action_Make *)operator_new(0x40);
    local_4 = 6;
    if (this_02 != (RGE_Action_Make *)0x0) {
      pRVar4 = (RGE_Action *)RGE_Action_Make::RGE_Action_Make(this_02,this->obj,param_1);
      goto LAB_0040445e;
    }
  }
  pRVar4 = (RGE_Action *)0x0;
LAB_0040445e:
  *unaff_FS_OFFSET = local_c;
  return pRVar4;
}

// --------------------------------------------------

// Function: inside_obj_update
// Address: 004044a0
uchar __thiscall RGE_Action_List::inside_obj_update(RGE_Action_List *this)
{
  RGE_Action_Node *pRVar1;
  uchar uVar2;
  
  if (this->list != (RGE_Action_Node *)0x0) {
    uVar2 = (**(code **)(this->list->action->_padding_ + 0x20))();
    for (pRVar1 = this->list->next; pRVar1 != (RGE_Action_Node *)0x0; pRVar1 = pRVar1->next) {
      (**(code **)(pRVar1->action->_padding_ + 0x24))();
    }
    if (uVar2 == '\x01') {
      remove_action(this);
    }
    return uVar2;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: update
// Address: 004044f0
uchar __thiscall RGE_Action_List::update(RGE_Action_List *this)
{
  RGE_Action_Node *pRVar1;
  uchar uVar2;
  
  if (this->list != (RGE_Action_Node *)0x0) {
    uVar2 = (**(code **)(this->list->action->_padding_ + 0x28))();
    if (this->list != (RGE_Action_Node *)0x0) {
      for (pRVar1 = this->list->next; pRVar1 != (RGE_Action_Node *)0x0; pRVar1 = pRVar1->next) {
        (**(code **)(pRVar1->action->_padding_ + 0x24))();
      }
      if (uVar2 == '\x01') {
        remove_action(this);
      }
    }
    return uVar2;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: add_action
// Address: 00404540
void __thiscall RGE_Action_List::add_action(RGE_Action_List *this,RGE_Action *param_1)
{
  RGE_Action_Node *pRVar1;
  
  if ((byte)this->obj->_padding_ < 3) {
    pRVar1 = (RGE_Action_Node *)calloc(1,8);
    pRVar1->action = param_1;
    pRVar1->next = this->list;
    this->list = pRVar1;
    (**(code **)(param_1->_padding_ + 0x1c))(1);
  }
  else if (param_1 != (RGE_Action *)0x0) {
    (**(code **)param_1->_padding_)(1);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: add_action_at_end
// Address: 00404590
void __thiscall RGE_Action_List::add_action_at_end(RGE_Action_List *this,RGE_Action *param_1)
{
  RGE_Action_Node *pRVar1;
  RGE_Action_Node *pRVar2;
  RGE_Action_Node *pRVar3;
  
  if ((byte)this->obj->_padding_ < 3) {
    pRVar2 = (RGE_Action_Node *)calloc(1,8);
    pRVar2->next = (RGE_Action_Node *)0x0;
    pRVar2->action = param_1;
    pRVar3 = this->list;
    if (this->list != (RGE_Action_Node *)0x0) {
      do {
        pRVar1 = pRVar3->next;
        if (pRVar1 == (RGE_Action_Node *)0x0) {
          pRVar3->next = pRVar2;
          (**(code **)(param_1->_padding_ + 0x1c))(1);
          return;
        }
        pRVar3 = pRVar1;
      } while (pRVar1 != (RGE_Action_Node *)0x0);
      (**(code **)(param_1->_padding_ + 0x1c))(1);
      return;
    }
    this->list = pRVar2;
    (**(code **)(param_1->_padding_ + 0x1c))(1);
  }
  else if (param_1 != (RGE_Action *)0x0) {
    (**(code **)param_1->_padding_)(1);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: add_action_at_end_of_action_queue
// Address: 00404610
void __thiscall
RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action_List *this,RGE_Action *param_1)
{
  RGE_Action *pRVar1;
  code *pcVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  RGE_Action_Node *pRVar6;
  RGE_Action_Node *pRVar7;
  RGE_Action_Node *node;
  
  if (2 < (byte)this->obj->_padding_) {
    if (param_1 == (RGE_Action *)0x0) {
      return;
    }
    (**(code **)param_1->_padding_)(1);
    return;
  }
  pRVar6 = (RGE_Action_Node *)calloc(1,8);
  pRVar6->action = param_1;
  if (this->list != (RGE_Action_Node *)0x0) {
    pRVar1 = this->list->action;
    pcVar2 = *(code **)(param_1->_padding_ + 0x18);
    sVar4 = (*pcVar2)();
    sVar5 = (**(code **)(pRVar1->_padding_ + 0x18))();
    if (sVar5 == sVar4) {
      pRVar7 = this->list;
      if (pRVar7 != (RGE_Action_Node *)0x0) {
        while (pRVar7->next != (RGE_Action_Node *)0x0) {
          pRVar1 = pRVar7->next->action;
          sVar4 = (*pcVar2)();
          sVar5 = (**(code **)(pRVar1->_padding_ + 0x18))();
          if (sVar5 != sVar4) break;
          pRVar7 = pRVar7->next;
          if (pRVar7 == (RGE_Action_Node *)0x0) {
            (**(code **)(param_1->_padding_ + 0x1c))(1);
            return;
          }
        }
        pRVar6->next = pRVar7->next;
        iVar3 = param_1->_padding_;
        pRVar7->next = pRVar6;
        (**(code **)(iVar3 + 0x1c))(1);
        return;
      }
      goto LAB_004046f1;
    }
  }
  pRVar6->next = this->list;
  this->list = pRVar6;
LAB_004046f1:
  (**(code **)(param_1->_padding_ + 0x1c))(1);
  return;
}

// --------------------------------------------------

// Function: remove_action
// Address: 00404710
void __thiscall RGE_Action_List::remove_action(RGE_Action_List *this)
{
  RGE_Action_Node *pRVar1;
  
  pRVar1 = this->list;
  if (pRVar1 != (RGE_Action_Node *)0x0) {
    this->list = pRVar1->next;
    if (pRVar1->action != (RGE_Action *)0x0) {
      (**(code **)pRVar1->action->_padding_)(1);
    }
    free(pRVar1);
    if ((this->list != (RGE_Action_Node *)0x0) && ((byte)this->obj->_padding_ < 3)) {
      (**(code **)(this->list->action->_padding_ + 0x1c))(0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: have_action
// Address: 00404760
uchar __thiscall RGE_Action_List::have_action(RGE_Action_List *this)
{
  return this->list != (RGE_Action_Node *)0x0;
}

// --------------------------------------------------

// Function: action_stop
// Address: 00404770
int __thiscall RGE_Action_List::action_stop(RGE_Action_List *this)
{
  int iVar1;
  
  if (this->list != (RGE_Action_Node *)0x0) {
    iVar1 = (**(code **)(this->list->action->_padding_ + 0x2c))();
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: action_move_to
// Address: 00404790
int __thiscall
RGE_Action_List::action_move_to
          (RGE_Action_List *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  int iVar1;
  
  if (this->list != (RGE_Action_Node *)0x0) {
    iVar1 = (**(code **)(this->list->action->_padding_ + 0x30))(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: action_work
// Address: 004047c0
int __thiscall
RGE_Action_List::action_work
          (RGE_Action_List *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  int iVar1;
  
  if (this->list != (RGE_Action_Node *)0x0) {
    iVar1 = (**(code **)(this->list->action->_padding_ + 0x34))(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: attack_response
// Address: 004047f0
int __thiscall RGE_Action_List::attack_response(RGE_Action_List *this,RGE_Static_Object *param_1)
{
  uint uVar1;
  
  if (this->list != (RGE_Action_Node *)0x0) {
    uVar1 = (**(code **)(this->list->action->_padding_ + 0x38))(param_1);
    return uVar1 & 0xff;
  }
  return 0;
}

// --------------------------------------------------

// Function: relation_response
// Address: 00404810
int __thiscall RGE_Action_List::relation_response(RGE_Action_List *this,long param_1,uchar param_2)
{
  uint uVar1;
  undefined3 in_stack_00000009;
  
  if (this->list != (RGE_Action_Node *)0x0) {
    uVar1 = (**(code **)(this->list->action->_padding_ + 0x3c))(param_1,_param_2);
    return uVar1 & 0xff;
  }
  return 0;
}

// --------------------------------------------------

// Function: get_action
// Address: 00404840
RGE_Action * __thiscall RGE_Action_List::get_action(RGE_Action_List *this)
{
  if (this->list != (RGE_Action_Node *)0x0) {
    return this->list->action;
  }
  return (RGE_Action *)0x0;
}

// --------------------------------------------------

// Function: get_task
// Address: 00404850
RGE_Task * __thiscall RGE_Action_List::get_task(RGE_Action_List *this)
{
  if (this->list != (RGE_Action_Node *)0x0) {
    return this->list->action->task;
  }
  return (RGE_Task *)0x0;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 00404860
void __thiscall RGE_Action_List::copy_obj(RGE_Action_List *this,RGE_Master_Action_Object *param_1)
{
  RGE_Action_Node *pRVar1;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Action_Node *)0x0; pRVar1 = pRVar1->next) {
    (**(code **)(pRVar1->action->_padding_ + 0x40))(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: copy_obj_sprites
// Address: 00404890
void __thiscall
RGE_Action_List::copy_obj_sprites
          (RGE_Action_List *this,RGE_Master_Action_Object *param_1,RGE_Task *param_2,
          RGE_Task *param_3)
{
  RGE_Action_Node *pRVar1;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Action_Node *)0x0; pRVar1 = pRVar1->next) {
    (**(code **)(pRVar1->action->_padding_ + 0x44))(param_1,param_2,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: get_action_name
// Address: 004048c0
// [HELPER] s_Attack: "Attack"
// [HELPER] s_Bird: "Bird"
// [HELPER] s_Explore: "Explore"
// [HELPER] s_Gather: "Gather"
// [HELPER] s_Make: "Make"
// [HELPER] s_Missile: "Missile"
// [HELPER] s_MoveTo: "MoveTo"
// [HELPER] s_None: "None"
// [HELPER] s_RunAway: "RunAway"
// [HELPER] s_Unknown: "Unknown"
void __thiscall RGE_Action_List::get_action_name(RGE_Action_List *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (this->list == (RGE_Action_Node *)0x0) {
    pcVar4 = &s_None;
    goto LAB_0040494a;
  }
  switch(this->list->action->action_type) {
  case 1:
    pcVar4 = s_MoveTo;
    goto LAB_00404921;
  default:
    pcVar4 = &s_Unknown;
    break;
  case 4:
    pcVar4 = s_Explore;
    break;
  case 5:
    pcVar4 = &s_Gather;
    goto LAB_00404921;
  case 8:
    pcVar4 = s_Missile;
    break;
  case 9:
    pcVar4 = &s_Attack;
    break;
  case 10:
    pcVar4 = s_Bird;
    goto LAB_00404921;
  case 0x14:
    pcVar4 = s_RunAway;
    break;
  case 0x15:
    pcVar4 = &s_Make;
LAB_00404921:
    uVar2 = 0xffffffff;
    do {
      pcVar5 = pcVar4;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar5 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar5;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar4 = pcVar5 + -uVar2;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      param_1 = param_1 + 1;
    }
    return;
  }
LAB_0040494a:
  uVar2 = 0xffffffff;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

// --------------------------------------------------

