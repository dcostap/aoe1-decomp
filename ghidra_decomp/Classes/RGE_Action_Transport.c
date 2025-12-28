// Class: RGE_Action_Transport
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
// [24] next_to_drop_off_terrain
//
// Member Layout:
// ----------------------------------------------------------------

// Function: RGE_Action_Transport
// Address: 00406d60
/* public: __thiscall RGE_Action_Transport::RGE_Action_Transport(int,class RGE_Action_Object *) */

RGE_Action_Transport * __thiscall
RGE_Action_Transport::RGE_Action_Transport
          (RGE_Action_Transport *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0xc;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00406d90
/* public: virtual void * __thiscall RGE_Action_Transport::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
RGE_Action_Transport::_vector_deleting_destructor_(RGE_Action_Transport *this,uint param_1)
{
  ~RGE_Action_Transport(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Transport
// Address: 00406db0
/* public: virtual __thiscall RGE_Action_Transport::~RGE_Action_Transport(void) */

void __thiscall RGE_Action_Transport::~RGE_Action_Transport(RGE_Action_Transport *this)
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

// Function: RGE_Action_Transport
// Address: 00406dc0
/* public: __thiscall RGE_Action_Transport::RGE_Action_Transport(class RGE_Action_Object *,class
   RGE_Task *,float,float,float) */

RGE_Action_Transport * __thiscall
RGE_Action_Transport::RGE_Action_Transport
          (RGE_Action_Transport *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  *(RGE_Task **)&this->field_0x30 = param_2;
  *(float *)&this->field_0x24 = param_4;
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0xc;
  *(float *)&this->field_0x20 = param_3;
  *(float *)&this->field_0x28 = param_5;
  return this;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 00406e00
/* public: virtual void __thiscall RGE_Action_Transport::first_in_stack(unsigned char) */

void __thiscall RGE_Action_Transport::first_in_stack(RGE_Action_Transport *this,uchar param_1)
{
  if (param_1 == '\0') {
    (**(code **)(*(int *)this + 0x5c))(2);
    return;
  }
  if ((UNK_0056e6b4._4_4_ <= *(float *)&this->field_0x20) &&
     (UNK_0056e6b4._4_4_ <= *(float *)&this->field_0x24)) {
    (**(code **)(*(int *)this + 0x5c))(0xb);
    return;
  }
  (**(code **)(*(int *)this + 0x5c))(2);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 00406e50
/* protected: virtual void __thiscall RGE_Action_Transport::set_state(unsigned char) */

void __thiscall RGE_Action_Transport::set_state(RGE_Action_Transport *this,uchar param_1)
{
  RGE_Action_Move_To *pRVar1;
  RGE_Action *this_00;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c416;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action_List::delete_list(*(RGE_Action_List **)&this->field_0x34);
  this->field_0xc = param_1;
  if (param_1 == '\x02') {
    (**(code **)(**(int **)&this->field_0x8 + 0x38))
              (*(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18));
LAB_00406f77:
    *unaff_FS_OFFSET = local_c;
    return;
  }
  if ((param_1 != '\x04') && (param_1 != '\v')) goto LAB_00406f77;
  if (*(int *)&this->field_0x30 == 0) {
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 1;
    if (pRVar1 != (RGE_Action_Move_To *)0x0) {
      this_00 = (RGE_Action *)
                RGE_Action_Move_To::RGE_Action_Move_To
                          (pRVar1,*(RGE_Action_Object **)&this->field_0x8,
                           *(float *)&this->field_0x20,*(float *)&this->field_0x24,
                           *(float *)&this->field_0x28,0.3,
                           *(RGE_Sprite **)
                            ((*(RGE_Action_Object **)&this->field_0x8)->_padding_ + 0x18));
      goto LAB_00406f19;
    }
  }
  else {
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar1 != (RGE_Action_Move_To *)0x0) {
      this_00 = (RGE_Action *)
                RGE_Action_Move_To::RGE_Action_Move_To
                          (pRVar1,*(RGE_Action_Object **)&this->field_0x8,
                           *(float *)&this->field_0x20,*(float *)&this->field_0x24,
                           *(float *)&this->field_0x28,0.3,
                           *(RGE_Sprite **)(*(int *)&this->field_0x30 + 0x34));
      goto LAB_00406f19;
    }
  }
  this_00 = (RGE_Action *)0x0;
LAB_00406f19:
  local_4 = 0xffffffff;
  if (this_00 == (RGE_Action *)0x0) {
    (**(code **)(*(int *)this + 0x5c))(2);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  RGE_Action_List::add_action(*(RGE_Action_List **)&this->field_0x34,this_00);
  RGE_Action::setSubAction(this_00,'\x01');
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00406f90
/* public: virtual unsigned char __thiscall RGE_Action_Transport::update(void) */

uchar __thiscall RGE_Action_Transport::update(RGE_Action_Transport *this)
{
  RGE_Map *this_00;
  byte bVar1;
  uchar uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  switch(this->field_0xc) {
  case 1:
    return '\x01';
  case 4:
    bVar1 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    if ((bVar1 != 0) && (bVar1 < 6)) {
      (**(code **)(*(int *)this + 0x5c))(6);
      return '\0';
    }
    break;
  case 6:
    iVar5 = targetZone(this);
    if ((iVar5 == -1) ||
       (iVar5 = RGE_Static_Object::withinRangeOfZone
                          (*(RGE_Static_Object **)&this->field_0x8,(uchar)iVar5,2.0), iVar5 != 0)) {
      if (*(short *)(*(int *)(*(int *)&this->field_0x8 + 0x24) + 8) < 1) goto LAB_004070ea;
      iVar5 = (**(code **)(*(int *)this + 0x60))();
      if (iVar5 == 0) {
        this_00 = *(RGE_Map **)(*(int *)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c) + 0x28);
        if (*(int *)&this->field_0x20 != -0x40800000) {
          sVar3 = __ftol();
          sVar4 = __ftol();
          uVar2 = RGE_Map::get_terrain(this_00,sVar4,sVar3);
          if (uVar2 == '\x01') goto LAB_004070ea;
          sVar3 = __ftol();
          sVar4 = __ftol();
          uVar2 = RGE_Map::get_terrain(this_00,sVar4,sVar3);
          if (uVar2 == '\x16') goto LAB_004070ea;
        }
        goto LAB_004070c9;
      }
      iVar5 = targetZone(this);
      uVar2 = RGE_Static_Object::drop_held_objects(*(RGE_Static_Object **)&this->field_0x8,iVar5);
      iVar5 = *(int *)&this->field_0x8;
      if (uVar2 == '\0') goto LAB_004070cc;
      if (*(short *)(*(int *)(iVar5 + 0x24) + 8) < 1) goto LAB_004070ea;
      uVar6 = *(undefined4 *)(iVar5 + 4);
      iVar5 = **(int **)(iVar5 + 0xc);
      uVar7 = 0x206;
    }
    else {
LAB_004070c9:
      iVar5 = *(int *)&this->field_0x8;
LAB_004070cc:
      uVar6 = *(undefined4 *)(iVar5 + 4);
      iVar5 = **(int **)(iVar5 + 0xc);
      uVar7 = 0x207;
    }
    (**(code **)(iVar5 + 0xe8))(uVar6,uVar6,uVar7,0x266,0,0);
LAB_004070ea:
    (**(code **)(*(int *)this + 0x5c))(2);
    return '\0';
  case 0xb:
    bVar1 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    if ((bVar1 != 0) && (bVar1 < 6)) {
      (**(code **)(*(int *)this + 0x5c))(2);
      return '\0';
    }
    break;
  case 0xd:
    iVar5 = (*(int **)&this->field_0x8)[1];
    (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar5,iVar5,0x1f9,0x266,0,0);
    (**(code **)(*(int *)this + 0x5c))(2);
    return '\x03';
  }
  return '\0';
}

// --------------------------------------------------

// Function: stop
// Address: 00407160
/* public: virtual int __thiscall RGE_Action_Transport::stop(void) */

int __thiscall RGE_Action_Transport::stop(RGE_Action_Transport *this)
{
  (**(code **)(*(int *)this + 0x5c))(2);
  return 1;
}

// --------------------------------------------------

// Function: move_to
// Address: 00407170
/* public: virtual int __thiscall RGE_Action_Transport::move_to(class RGE_Static_Object
   *,float,float,float) */

int __thiscall
RGE_Action_Transport::move_to
          (RGE_Action_Transport *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  *(float *)&this->field_0x20 = param_2;
  *(float *)&this->field_0x24 = param_3;
  *(undefined4 *)&this->field_0x1c = 0;
  *(float *)&this->field_0x28 = param_4;
  (**(code **)(*(int *)this + 0x5c))(0xb);
  return 1;
}

// --------------------------------------------------

// Function: work
// Address: 004071a0
/* WARNING: Variable defined which should be unmapped: distance */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall RGE_Action_Transport::work(class RGE_Static_Object
   *,float,float,float) */

int __thiscall
RGE_Action_Transport::work
          (RGE_Action_Transport *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float distance;
  
  *(undefined4 *)&this->field_0x1c = 1;
  iVar2 = __ftol();
  iVar3 = __ftol();
  bVar1 = RGE_Static_Object::lookupZone(*(RGE_Static_Object **)&this->field_0x8,iVar3,iVar2);
  fVar4 = RGE_Static_Object::distance_to_position
                    (*(RGE_Static_Object **)&this->field_0x8,param_2,param_3,
                     (*(RGE_Static_Object **)&this->field_0x8)->world_z);
  if (bVar1 != 0xffffffff) {
    iVar2 = RGE_Static_Object::withinRangeOfZone(*(RGE_Static_Object **)&this->field_0x8,bVar1,2.0);
    if ((iVar2 == 1) && (fVar4 <= ram0x0056e6bc)) {
      *(float *)&this->field_0x24 = param_3;
      *(float *)&this->field_0x20 = param_2;
      *(float *)&this->field_0x28 = param_4;
      (**(code **)(*(int *)this + 0x5c))(6);
      return 1;
    }
  }
  if (((float)_DAT_0056e6c0 <= param_2) && ((float)_DAT_0056e6c0 <= param_3)) {
    *(float *)&this->field_0x20 = param_2;
    *(float *)&this->field_0x24 = param_3;
    *(float *)&this->field_0x28 = param_4;
    if (param_1 != *(RGE_Static_Object **)&this->field_0x8) {
      (**(code **)(*(int *)this + 0x5c))(0xb);
      return 1;
    }
    (**(code **)(*(int *)this + 0x5c))(4);
  }
  return 1;
}

// --------------------------------------------------

// Function: next_to_drop_off_terrain
// Address: 004072b0
/* WARNING: Variable defined which should be unmapped: x2 */
/* public: virtual int __thiscall RGE_Action_Transport::next_to_drop_off_terrain(void) */

int __thiscall RGE_Action_Transport::next_to_drop_off_terrain(RGE_Action_Transport *this)
{
  RGE_Map *this_00;
  byte bVar1;
  uchar uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int x2;
  int local_10;
  int y2;
  int x1;
  int local_4;
  
  if ((*(int *)&this->field_0x30 != 0) && (*(short *)(*(int *)&this->field_0x30 + 0xe) == -1)) {
    return 1;
  }
  iVar5 = *(int *)&this->field_0x8;
  local_4 = __ftol();
  iVar3 = __ftol();
  local_10 = __ftol();
  x1 = __ftol();
  this_00 = *(RGE_Map **)(*(int *)(*(int *)(iVar5 + 0xc) + 0x3c) + 0x28);
  if (local_4 < 0) {
    local_4 = 0;
  }
  if (this_00->map_width <= local_10) {
    local_10 = this_00->map_width + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (this_00->map_height <= x1) {
    x1 = this_00->map_height + -1;
  }
  uVar4 = targetZone(this);
  if (*(int *)&this->field_0x20 != -0x40800000) {
    iVar5 = __ftol();
    iVar6 = __ftol();
    bVar1 = RGE_Static_Object::lookupZone(*(RGE_Static_Object **)&this->field_0x8,iVar6,iVar5);
    uVar4 = (uint)bVar1;
  }
  iVar5 = local_4;
  if (x1 < iVar3) {
    return 0;
  }
  do {
    while (local_10 < iVar5) {
      iVar3 = iVar3 + 1;
      iVar5 = local_4;
      if (x1 < iVar3) {
        return 0;
      }
    }
    if ((uVar4 == 0xffffffff) ||
       (bVar1 = RGE_Static_Object::lookupZone(*(RGE_Static_Object **)&this->field_0x8,iVar5,iVar3),
       bVar1 == uVar4)) {
      uVar2 = RGE_Map::get_terrain(this_00,(short)iVar5,(short)iVar3);
      if ((uVar2 == '\x02') ||
         (uVar2 = RGE_Map::get_terrain(this_00,(short)iVar5,(short)iVar3), uVar2 == '\x04')) {
        return 1;
      }
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: targetZone
// Address: 00407420
/* public: int __thiscall RGE_Action_Transport::targetZone(void) */

int __thiscall RGE_Action_Transport::targetZone(RGE_Action_Transport *this)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)&this->field_0x20 != -0x40800000) {
    iVar2 = __ftol();
    iVar3 = __ftol();
    bVar1 = RGE_Static_Object::lookupZone(*(RGE_Static_Object **)&this->field_0x8,iVar3,iVar2);
    return (uint)bVar1;
  }
  return -1;
}

// --------------------------------------------------

