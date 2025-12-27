// Class: RGE_Action_Explore
// Function: RGE_Action_Explore
// Address: 00402b40
/* public: __thiscall RGE_Action_Explore::RGE_Action_Explore(int,class RGE_Action_Object *) */

RGE_Action_Explore * __thiscall
RGE_Action_Explore::RGE_Action_Explore
          (RGE_Action_Explore *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 4;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00402b70
/* public: virtual void * __thiscall RGE_Action_Explore::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
RGE_Action_Explore::_scalar_deleting_destructor_(RGE_Action_Explore *this,uint param_1)
{
  ~RGE_Action_Explore(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Explore
// Address: 00402b90
/* public: virtual __thiscall RGE_Action_Explore::~RGE_Action_Explore(void) */

void __thiscall RGE_Action_Explore::~RGE_Action_Explore(RGE_Action_Explore *this)
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

// Function: RGE_Action_Explore
// Address: 00402ba0
/* public: __thiscall RGE_Action_Explore::RGE_Action_Explore(class RGE_Action_Object *,class
   RGE_Task *,float,float,float) */

RGE_Action_Explore * __thiscall
RGE_Action_Explore::RGE_Action_Explore
          (RGE_Action_Explore *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  *(RGE_Task **)&this->field_0x30 = param_2;
  *(float *)&this->field_0x24 = param_4;
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 4;
  *(float *)&this->field_0x20 = param_3;
  *(float *)&this->field_0x28 = param_5;
  return this;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 00402be0
/* public: virtual void __thiscall RGE_Action_Explore::first_in_stack(unsigned char) */

void __thiscall RGE_Action_Explore::first_in_stack(RGE_Action_Explore *this,uchar param_1)
{
  if (*(int *)&this->field_0x20 == -0x40800000) {
    (**(code **)(*(int *)this + 0x5c))(3);
    return;
  }
  (**(code **)(*(int *)this + 0x5c))(0xb);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 00402c00
/* protected: virtual void __thiscall RGE_Action_Explore::set_state(unsigned char) */

void __thiscall RGE_Action_Explore::set_state(RGE_Action_Explore *this,uchar param_1)
{
  int iVar1;
  RGE_Action_Move_To *this_00;
  RGE_Action *this_01;
  undefined4 unaff_ESI;
  RGE_Sprite *pRVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar3;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c17b;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action_List::delete_list(*(RGE_Action_List **)&this->field_0x34);
  this->field_0xc = param_1;
  switch(param_1) {
  case '\x02':
    uVar3 = *(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18);
    (**(code **)(**(int **)&this->field_0x8 + 0x38))();
    iVar1 = *(int *)this;
    (**(code **)(iVar1 + 0x54))(0);
    (**(code **)(iVar1 + 0x58))(0);
    *(undefined4 *)&this->field_0x20 = 0xbf800000;
    *(undefined4 *)&this->field_0x24 = 0xbf800000;
    *(undefined4 *)&this->field_0x28 = 0xbf800000;
    *unaff_FS_OFFSET = uVar3;
    return;
  case '\x03':
    iVar1 = (*(int **)&this->field_0x8)[1];
    (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar1,iVar1,0x202,0x25d,0,0);
  case '\x01':
  case '\r':
  case '\x0e':
    (**(code **)(**(int **)&this->field_0x8 + 0x38))
              (*(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18));
  default:
    *unaff_FS_OFFSET = local_c;
    return;
  case '\v':
    break;
  }
  if ((*(int *)&this->field_0x30 == 0) ||
     (pRVar2 = *(RGE_Sprite **)(*(int *)&this->field_0x30 + 0x34), pRVar2 == (RGE_Sprite *)0x0)) {
    pRVar2 = *(RGE_Sprite **)(*(int *)(*(int *)&this->field_0x8 + 8) + 0xbc);
  }
  this_00 = (RGE_Action_Move_To *)operator_new(0x44);
  local_4 = 0;
  if (this_00 == (RGE_Action_Move_To *)0x0) {
    this_01 = (RGE_Action *)0x0;
  }
  else {
    this_01 = (RGE_Action *)
              RGE_Action_Move_To::RGE_Action_Move_To
                        (this_00,*(RGE_Action_Object **)&this->field_0x8,*(float *)&this->field_0x20
                         ,*(float *)&this->field_0x24,*(float *)&this->field_0x28,0.0,pRVar2);
  }
  local_4 = 0xffffffff;
  if (this_01 == (RGE_Action *)0x0) {
    (**(code **)(*(int *)this + 0x5c))(0xd);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  RGE_Action::setSubAction(this_01,'\x01');
  RGE_Action_List::add_action(*(RGE_Action_List **)&this->field_0x34,this_01);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00402d90
/* public: virtual unsigned char __thiscall RGE_Action_Explore::update(void) */

uchar __thiscall RGE_Action_Explore::update(RGE_Action_Explore *this)
{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  
  cVar1 = this->field_0xc;
  if (cVar1 == '\x01') {
    return '\x01';
  }
  if (cVar1 == '\v') {
    uVar3 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    switch(uVar3) {
    case 1:
    case 2:
    case 5:
      (**(code **)(*(int *)this + 0x5c))(3);
      return '\0';
    case 3:
      (**(code **)(*(int *)this + 0x5c))(0xd);
      break;
    case 4:
      iVar2 = *(int *)this;
      (**(code **)(iVar2 + 0x54))(0);
      (**(code **)(iVar2 + 0x5c))(0xb);
      return '\0';
    }
  }
  else if (cVar1 == '\r') {
    iVar2 = (*(int **)&this->field_0x8)[1];
    (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar2,iVar2,0x1f9,0x25d,0,0);
    (**(code **)(*(int *)this + 0x5c))(2);
    return '\x03';
  }
  return '\0';
}

// --------------------------------------------------

// Function: work
// Address: 00402e40
/* public: virtual int __thiscall RGE_Action_Explore::work(class RGE_Static_Object
   *,float,float,float) */

int __thiscall
RGE_Action_Explore::work
          (RGE_Action_Explore *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  if (((float)DAT_0056e210 <= param_2) && ((float)DAT_0056e210 <= param_3)) {
    *(float *)&this->field_0x20 = param_2;
    *(float *)&this->field_0x24 = param_3;
    *(float *)&this->field_0x28 = param_4;
    (**(code **)(*(int *)this + 0x5c))(0xb);
    return 1;
  }
  (**(code **)(*(int *)this + 0x5c))(3);
  return 1;
}

// --------------------------------------------------

