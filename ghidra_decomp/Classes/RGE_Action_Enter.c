// Class: RGE_Action_Enter
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

// Function: RGE_Action_Enter
// Address: 004023c0
/* public: __thiscall RGE_Action_Enter::RGE_Action_Enter(int,class RGE_Action_Object *) */

RGE_Action_Enter * __thiscall
RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Enter *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 3;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 004023f0
/* public: virtual void * __thiscall RGE_Action_Enter::`scalar deleting destructor'(unsigned int) */

void * __thiscall
RGE_Action_Enter::_scalar_deleting_destructor_(RGE_Action_Enter *this,uint param_1)
{
  ~RGE_Action_Enter(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Action_Enter
// Address: 00402410
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall RGE_Action_Enter::RGE_Action_Enter(class RGE_Action_Object *,class RGE_Task
   *,class RGE_Static_Object *) */

RGE_Action_Enter * __thiscall
RGE_Action_Enter::RGE_Action_Enter
          (RGE_Action_Enter *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  code *pcVar1;
  char cVar2;
  uchar uVar3;
  int iVar4;
  RGE_Action *pRVar5;
  int unaff_EBX;
  int *unaff_FS_OFFSET;
  float fVar6;
  XYPoint dest;
  XYPoint start;
  XYPoint rVal;
  int local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c138;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_c;
  dest.x = (int)this;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 3;
  *(RGE_Task **)&this->field_0x30 = param_2;
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  if (param_3 == (RGE_Static_Object *)0x0) goto LAB_004025d6;
  *(float *)&this->field_0x20 = param_3->world_x;
  *(float *)&this->field_0x24 = param_3->world_y;
  *(float *)&this->field_0x28 = param_3->world_z;
  pcVar1 = *(code **)(param_3->_padding_ + 0x134);
  cVar2 = (*pcVar1)();
  if (cVar2 == '\x02') {
    uVar3 = RGE_Static_Object::more_room(param_3);
    if (uVar3 == '\x01') {
      iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x8 + 0xc));
      if (iVar4 != 0) goto LAB_004024ad;
    }
    else {
LAB_004024ad:
      iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)&this->field_0x8 + 0xc));
      if (iVar4 != 1) goto LAB_004024bd;
    }
LAB_004024df:
    start.y = __ftol();
    rVal.x = __ftol();
    dest.y = __ftol();
    start.x = __ftol();
    iVar4 = (**(code **)(param_1->_padding_ + 0x1b4))(&start.y,&dest.y,&rVal.y,2,2,1);
    if (iVar4 == 1) {
      *(float *)&this->field_0x20 = (float)unaff_EBX - _DAT_0056e1a0;
      rVal.y = (int)(float)dest.x;
      *(float *)&this->field_0x24 = (float)dest.x - _DAT_0056e1a0;
      (**(code **)(local_c + 0x154))((float)unaff_EBX,rVal.y,param_3->world_z,0x3f000000,1);
    }
    else {
      *(float *)&this->field_0x20 = param_3->world_x;
      *(float *)&this->field_0x24 = param_3->world_y;
      (**(code **)(local_c + 0x154))
                (param_1->_padding_,param_1->_padding_,param_3->world_z,0x3f000000,1);
    }
  }
  else {
LAB_004024bd:
    cVar2 = (*pcVar1)();
    if (cVar2 == '\v') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_3[2].unitAIValue);
      if (pRVar5->target2ID == 0) goto LAB_004024df;
    }
    cVar2 = (*pcVar1)();
    if (cVar2 == '\v') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_3[2].unitAIValue);
      fVar6 = RGE_Action::targetX(pRVar5);
      *(float *)&this->field_0x20 = fVar6;
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_3[2].unitAIValue);
      fVar6 = RGE_Action::targetY(pRVar5);
      *(float *)&this->field_0x24 = fVar6;
    }
  }
LAB_004025d6:
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Enter
// Address: 004025f0
/* public: virtual __thiscall RGE_Action_Enter::~RGE_Action_Enter(void) */

void __thiscall RGE_Action_Enter::~RGE_Action_Enter(RGE_Action_Enter *this)
{
  *(undefined ***)this = &_vftable_;
  RGE_Action::~RGE_Action((RGE_Action *)this);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 00402600
/* public: virtual void __thiscall RGE_Action_Enter::first_in_stack(unsigned char) */

void __thiscall RGE_Action_Enter::first_in_stack(RGE_Action_Enter *this,uchar param_1)
{
  (**(code **)(*(int *)this + 0x5c))(4);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 00402610
/* protected: virtual void __thiscall RGE_Action_Enter::set_state(unsigned char) */

void __thiscall RGE_Action_Enter::set_state(RGE_Action_Enter *this,uchar param_1)
{
  RGE_Action_Move_To *this_00;
  RGE_Action *this_01;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c15b;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action_List::delete_list(*(RGE_Action_List **)&this->field_0x34);
  this->field_0xc = param_1;
  switch(param_1) {
  case '\x02':
    *(undefined4 *)&this->field_0x2c = 0x3f800000;
  case '\x01':
  case '\r':
  case '\x0e':
    (**(code **)(**(int **)&this->field_0x8 + 0x38))
              (*(undefined4 *)((*(int **)&this->field_0x8)[2] + 0x18));
  default:
    *unaff_FS_OFFSET = local_c;
    return;
  case '\x04':
    break;
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
                         ,*(float *)&this->field_0x24,*(float *)&this->field_0x28,
                         *(float *)(*(int *)&this->field_0x30 + 0x24),
                         *(RGE_Sprite **)(*(int *)&this->field_0x30 + 0x34));
  }
  local_4 = 0xffffffff;
  if (this_01 == (RGE_Action *)0x0) {
    (**(code **)(*(int *)this + 0x5c))(0xd);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  RGE_Action_List::add_action(*(RGE_Action_List **)&this->field_0x34,this_01);
  RGE_Action::setSubAction(this_01,'\x01');
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00402740
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Action_Enter::update(void) */

uchar __thiscall RGE_Action_Enter::update(RGE_Action_Enter *this)
{
  int *piVar1;
  uchar uVar2;
  undefined1 uVar3;
  char cVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  RGE_Action *pRVar7;
  float fVar8;
  int iStack_20;
  XYPoint dest;
  XYPoint start;
  XYPoint rVal;
  
  if ((*(int *)&this->field_0x18 == -1) ||
     (pRVar5 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c),
                          *(int *)&this->field_0x18), pRVar5 != (RGE_Static_Object *)0x0)) {
    if ((*(int *)&this->field_0x1c != -1) &&
       (pRVar5 = RGE_Game_World::object
                           (*(RGE_Game_World **)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x3c),
                            *(int *)&this->field_0x1c), pRVar5 == (RGE_Static_Object *)0x0)) {
      (**(code **)(*(int *)this + 0x58))(0);
    }
    iVar6 = *(int *)&this->field_0x10;
    if ((iVar6 == 0) ||
       ((*(byte *)(iVar6 + 0x48) < 3 &&
        ((iVar6 == 0 ||
         (iVar6 = (**(code **)(**(int **)(*(int *)&this->field_0x8 + 0xc) + 0x1c))
                            ((int)*(short *)(*(int *)(iVar6 + 0xc) + 0x4a)), iVar6 != 0)))))) {
      switch(this->field_0xc) {
      case 1:
        return '\x01';
      case 2:
        fVar8 = *(float *)&this->field_0x2c -
                (*(RGE_Static_Object **)&this->field_0x8)->owner->world->world_time_delta_seconds;
        *(float *)&this->field_0x2c = fVar8;
        if (fVar8 <= _DAT_0056e1a8) {
          fVar8 = RGE_Static_Object::distance_to_object
                            (*(RGE_Static_Object **)&this->field_0x8,
                             *(RGE_Static_Object **)&this->field_0x10);
          if (*(float *)(*(int *)&this->field_0x30 + 0x24) < fVar8 - _DAT_0056e1a4) {
            cVar4 = (**(code **)(**(int **)&this->field_0x10 + 0x134))();
            if (cVar4 != '\x02') {
              cVar4 = (**(code **)(**(int **)&this->field_0x10 + 0x134))();
              if (cVar4 == '\v') {
                pRVar7 = RGE_Action_List::get_action
                                   (*(RGE_Action_List **)(*(int *)&this->field_0x10 + 0x184));
                fVar8 = RGE_Action::targetX(pRVar7);
                *(float *)&this->field_0x20 = fVar8;
                pRVar7 = RGE_Action_List::get_action
                                   (*(RGE_Action_List **)(*(int *)&this->field_0x10 + 0x184));
                fVar8 = RGE_Action::targetY(pRVar7);
                *(float *)&this->field_0x24 = fVar8;
              }
              (**(code **)(*(int *)this + 0x5c))(4);
              return '\0';
            }
            piVar1 = *(int **)&this->field_0x8;
            start.y = __ftol();
            rVal.x = __ftol();
            dest.y = __ftol();
            start.x = __ftol();
            iVar6 = (**(code **)(*piVar1 + 0x1b4))(&start.y,&dest.y,&rVal.y,2,2,1);
            if (iVar6 == 1) {
              fVar8 = (float)dest.x - _DAT_0056e1a0;
              if ((*(float *)&this->field_0x20 == (float)iStack_20 - _DAT_0056e1a0) &&
                 (fVar8 == *(float *)&this->field_0x24)) {
                *(undefined4 *)&this->field_0x20 = *(undefined4 *)(*(int *)&this->field_0x10 + 0x38)
                ;
                *(undefined4 *)&this->field_0x24 = *(undefined4 *)(*(int *)&this->field_0x10 + 0x3c)
                ;
                (**(code **)(*(int *)this + 0x5c))(4);
                return '\0';
              }
              *(float *)&this->field_0x20 = (float)iStack_20 - _DAT_0056e1a0;
              *(float *)&this->field_0x24 = fVar8;
              (**(code **)(**(int **)&this->field_0x10 + 0x154))
                        ((float)iStack_20,(float)dest.x,(*(int **)&this->field_0x10)[0x10],0,1);
              (**(code **)(*(int *)this + 0x5c))(4);
              return '\0';
            }
            piVar1 = *(int **)&this->field_0x10;
            *(int *)&this->field_0x20 = piVar1[0xe];
            iVar6 = *piVar1;
            *(int *)&this->field_0x24 = piVar1[0xf];
            (**(code **)(iVar6 + 0x154))
                      (*(undefined4 *)(*(int *)&this->field_0x8 + 0x38),
                       *(undefined4 *)(*(int *)&this->field_0x8 + 0x3c),piVar1[0x10],0x3f000000,1);
            (**(code **)(*(int *)this + 0x5c))(4);
            return '\0';
          }
          (**(code **)(**(int **)&this->field_0x8 + 0xd0))(*(undefined4 *)&this->field_0x10);
LAB_004028ef:
          if (this->field_0x3c == '\0') {
            iVar6 = (*(int **)&this->field_0x8)[1];
            (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar6,iVar6,0x1fa,0x269,0,0);
          }
          (**(code **)(*(int *)this + 0x5c))(1);
          return '\x02';
        }
      default:
switchD_004027fc_caseD_3:
        return '\0';
      case 4:
        goto switchD_004027fc_caseD_4;
      case 0xd:
        iVar6 = (*(int **)&this->field_0x8)[1];
        (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar6,iVar6,0x1f9,0x269,0,0);
        return '\x03';
      }
    }
  }
  iVar6 = *(int *)this;
  (**(code **)(iVar6 + 0x5c))(1);
  (**(code **)(iVar6 + 0x54))(0);
  iVar6 = (*(int **)&this->field_0x8)[1];
  (**(code **)(**(int **)&this->field_0x8 + 0x148))(iVar6,iVar6,0x1fb,0x269,0,0);
  return '\x04';
switchD_004027fc_caseD_4:
  if ((*(RGE_Static_Object **)&this->field_0x10 != (RGE_Static_Object *)0x0) &&
     (uVar2 = RGE_Static_Object::is_dying(*(RGE_Static_Object **)&this->field_0x10), uVar2 == '\0'))
{
    uVar3 = (**(code **)(**(int **)&this->field_0x34 + 0xc))();
    switch(uVar3) {
    case 1:
    case 2:
      fVar8 = RGE_Static_Object::distance_to_object
                        (*(RGE_Static_Object **)&this->field_0x8,
                         *(RGE_Static_Object **)&this->field_0x10);
      if (*(float *)(*(int *)&this->field_0x30 + 0x24) < fVar8 - _DAT_0056e1a4) {
        (**(code **)(*(int *)this + 0x5c))(2);
        return '\0';
      }
      (**(code **)(**(int **)&this->field_0x8 + 0xd0))(*(undefined4 *)&this->field_0x10);
      goto LAB_004028ef;
    case 3:
      (**(code **)(*(int *)this + 0x5c))(2);
      return '\0';
    case 4:
    case 5:
      break;
    default:
      goto switchD_004027fc_caseD_3;
    }
  }
  iVar6 = *(int *)this;
  (**(code **)(iVar6 + 0x54))(0);
  (**(code **)(iVar6 + 0x5c))(0xd);
  return '\0';
}

// --------------------------------------------------

