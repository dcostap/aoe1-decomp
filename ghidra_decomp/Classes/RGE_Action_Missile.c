// Class: RGE_Action_Missile
// Size:  0x54
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
// [0x040] float velocity_x
// [0x044] float velocity_y
// [0x048] float velocity_z
// [0x04C] float ballistic_velocity
// [0x050] float ballistic_acceleration
// ----------------------------------------------------------------

// Function: RGE_Action_Missile
// Address: 00404bb0
RGE_Action_Missile * __thiscall
RGE_Action_Missile::RGE_Action_Missile
          (RGE_Action_Missile *this,int param_1,RGE_Action_Object *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c2c8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 8;
  rge_read(param_1,&this->velocity_x,4);
  rge_read(param_1,&this->velocity_y,4);
  rge_read(param_1,&this->velocity_z,4);
  rge_read(param_1,&this->ballistic_velocity,4);
  rge_read(param_1,&this->ballistic_acceleration,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00404c60
void * __thiscall
RGE_Action_Missile::_vector_deleting_destructor_(RGE_Action_Missile *this,uint param_1)
{
  ~RGE_Action_Missile(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Action_Missile
// Address: 00404c80
void __thiscall RGE_Action_Missile::~RGE_Action_Missile(RGE_Action_Missile *this)
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

// Function: RGE_Action_Missile
// Address: 00404c90
RGE_Action_Missile * __thiscall
RGE_Action_Missile::RGE_Action_Missile
          (RGE_Action_Missile *this,RGE_Action_Object *param_1,RGE_Static_Object *param_2,
          RGE_Static_Object *param_3,float param_4,float param_5,float param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c2e8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_4;
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 8;
  this->_padding_ = (int)param_5;
  this->_padding_ = (int)param_6;
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  RGE_Action::set_target_obj2((RGE_Action *)this,param_2);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 00404d10
void __thiscall RGE_Action_Missile::first_in_stack(RGE_Action_Missile *this,uchar param_1)
{
  if (param_1 == '\0') {
    (**(code **)(this->_padding_ + 0x5c))(4);
    return;
  }
  if ((this->_padding_ == 0) &&
     ((this->_padding_ == -0x40800000 || (this->_padding_ == -0x40800000)))) {
    (**(code **)(this->_padding_ + 0x5c))(1);
    return;
  }
  (**(code **)(this->_padding_ + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: intercept
// Address: 00404d50
void __thiscall
RGE_Action_Missile::intercept(RGE_Action_Missile *this,float *param_1,float *param_2,float *param_3)
{
  if (this->_padding_ == 0) {
    *param_1 = (float)this->_padding_;
    *param_2 = (float)this->_padding_;
    *param_3 = (float)this->_padding_;
    return;
  }
  *param_1 = *(float *)(this->_padding_ + 0x38);
  *param_2 = *(float *)(this->_padding_ + 0x3c);
  *param_3 = *(float *)(*(int *)(this->_padding_ + 8) + 0x38) * _DAT_0056e380 +
             *(float *)(this->_padding_ + 0x40);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 00404db0
void __thiscall RGE_Action_Missile::set_state(RGE_Action_Missile *this,uchar param_1)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float10 fVar7;
  unkbyte10 Var8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float dx;
  float d;
  float speed;
  float dz;
  float target_vx;
  float target_vy;
  float tx;
  float ty;
  float tz;
  float local_4;
  
  *(uchar *)&this->_padding_ = param_1;
  if (param_1 == '\x01') {
    (**(code **)(*(int *)this->_padding_ + 0x6c))();
  }
  else if (param_1 == '\x03') {
    intercept(this,&ty,&tz,&local_4);
    iVar2 = this->_padding_;
    d = ty - *(float *)(iVar2 + 0x38);
    _param_1 = tz - *(float *)(iVar2 + 0x3c);
    fVar4 = local_4 - *(float *)(iVar2 + 0x40);
    fVar5 = fVar4 * fVar4;
    speed = SQRT(_param_1 * _param_1 + d * d + fVar5);
    if (((*(char *)(*(int *)(iVar2 + 8) + 0x149) == '\x01') &&
        ((int *)this->_padding_ != (int *)0x0)) &&
       (fVar7 = (float10)(**(code **)(*(int *)this->_padding_ + 0xf4))(),
       (float10)_DAT_0056e388 < fVar7)) {
      fVar7 = (float10)(**(code **)(*(int *)this->_padding_ + 0xf4))();
      dz = (float)fVar7;
      if (((this->_padding_ != 0) &&
          (((sVar1 = *(short *)(*(int *)(this->_padding_ + 8) + 0x10), sVar1 == 0x23 ||
            (sVar1 == 0x24)) || (sVar1 == 0x118)))) && (_DAT_0056e390 < dz)) {
        dz = 1.0;
      }
      Var8 = (**(code **)(*(int *)this->_padding_ + 0xf8))();
      fVar7 = (float10)fcos(Var8);
      Var8 = (**(code **)(*(int *)this->_padding_ + 0xf8))();
      fVar9 = (float10)fsin(Var8);
      iVar2 = *(int *)(this->_padding_ + 8);
      fVar10 = (float10)(float)(fVar7 * (float10)dz) + (float10)d;
      fVar11 = fVar9 * (float10)dz + (float10)_param_1;
      fVar10 = ((float10)speed -
               SQRT(fVar11 * (float10)(float)fVar11 + fVar10 * (float10)(float)fVar10 +
                    (float10)fVar5)) + (float10)*(float *)(iVar2 + 0xb8);
      if ((float10)*(float *)(iVar2 + 0xb8) * (float10)_DAT_0056e380 < fVar10) {
        fVar6 = speed / (float)fVar10;
        d = fVar6 * (float)(fVar7 * (float10)dz) + d;
        _param_1 = fVar6 * (float)(fVar9 * (float10)dz) + _param_1;
        speed = SQRT(_param_1 * _param_1 + d * d + fVar5);
      }
    }
    piVar3 = (int *)this->_padding_;
    switch(*(undefined1 *)(piVar3[2] + 0x148)) {
    case 0:
      iVar2 = *piVar3;
      this->velocity_x = (float)((float10)d / (float10)speed);
      this->velocity_y = (float)((float10)_param_1 / (float10)speed);
      this->velocity_z = fVar4 / speed;
      fVar7 = (float10)fpatan((float10)_param_1 / (float10)speed,(float10)d / (float10)speed);
      (**(code **)(iVar2 + 0xb4))((float)fVar7);
      this->_padding_ = 0;
      break;
    case 1:
      (**(code **)(this->_padding_ + 0x5c))(4);
      break;
    case 2:
      (**(code **)(this->_padding_ + 0x5c))(4);
      break;
    case 3:
      fVar7 = (float10)fpatan((float10)_param_1,(float10)d);
      this->velocity_x = d;
      this->velocity_y = _param_1;
      iVar2 = *piVar3;
      this->velocity_z = fVar4;
      (**(code **)(iVar2 + 0xb4))((float)fVar7);
    }
    iVar2 = *(int *)(this->_padding_ + 8);
    if (*(float *)(iVar2 + 0x150) <= (float)_DAT_0056e388) {
      this->ballistic_velocity = 0.0;
      this->ballistic_acceleration = 0.0;
      (**(code **)(this->_padding_ + 0x5c))(4);
      return;
    }
    fVar4 = _DAT_0056e394;
    if (_DAT_0056e394 < *(float *)(iVar2 + 0xb8)) {
      fVar4 = speed / *(float *)(iVar2 + 0xb8);
    }
    fVar4 = fVar4 * _DAT_0056e380;
    fVar5 = -(speed * *(float *)(iVar2 + 0x150));
    fVar5 = (fVar5 + fVar5) / (fVar4 * fVar4);
    this->ballistic_acceleration = fVar5;
    this->ballistic_velocity = -(fVar4 * fVar5);
    (**(code **)(this->_padding_ + 0x5c))(4);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004050f0
uchar __thiscall RGE_Action_Missile::update(RGE_Action_Missile *this)
{
  char cVar1;
  byte bVar2;
  uchar uVar3;
  RGE_Game_World *this_00;
  RGE_Missile_Object *this_01;
  RGE_Check_Node *pRVar4;
  float fVar5;
  float fVar6;
  uchar uVar7;
  RGE_Static_Object *pRVar8;
  RGE_Check_List *this_02;
  int iVar9;
  RGE_Static_Object *pRVar10;
  RGE_Static_Object *pRVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  int iVar15;
  float fVar16;
  int *piVar17;
  float fVar18;
  uchar hit_ground;
  float vz;
  float s;
  float t;
  float vy;
  RGE_Check_List *bounds;
  float local_4;
  
  local_4 = 0.0;
  bounds = (RGE_Check_List *)0x0;
  s = 0.0;
  this_00 = *(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c);
  fVar18 = this_00->world_time_delta_seconds;
  fVar16 = *(float *)(*(int *)(this->_padding_ + 8) + 0xb8) * fVar18;
  if ((this->_padding_ != -1) &&
     (pRVar8 = RGE_Game_World::object(this_00,this->_padding_), pRVar8 == (RGE_Static_Object *)0x0))
{
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if ((this->_padding_ != -1) &&
     (pRVar8 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar8 == (RGE_Static_Object *)0x0)) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  if (((RGE_Static_Object *)this->_padding_ != (RGE_Static_Object *)0x0) &&
     (uVar7 = RGE_Static_Object::is_dying((RGE_Static_Object *)this->_padding_), uVar7 != '\0')) {
    (**(code **)(this->_padding_ + 0x54))(0);
  }
  if (((RGE_Static_Object *)this->_padding_ != (RGE_Static_Object *)0x0) &&
     (uVar7 = RGE_Static_Object::is_dying((RGE_Static_Object *)this->_padding_), uVar7 != '\0')) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  cVar1 = (char)this->_padding_;
  if (cVar1 == '\x01') {
    return '\x01';
  }
  if (cVar1 == '\x04') {
    cVar1 = *(char *)(*(int *)(this->_padding_ + 8) + 0x148);
    if (cVar1 == '\0') {
      fVar14 = fVar16 + (float)this->_padding_;
      this->_padding_ = (int)fVar14;
      local_4 = this->velocity_x * fVar16;
      bounds = (RGE_Check_List *)(this->velocity_y * fVar16);
      s = this->velocity_z * fVar16;
      if (*(float *)(this->_padding_ + 0x1c4) <= fVar14) {
        (**(code **)(this->_padding_ + 0x5c))(1);
      }
    }
    else if (cVar1 == '\x03') {
      local_4 = this->velocity_x;
      bounds = (RGE_Check_List *)this->velocity_y;
      s = this->velocity_z;
    }
    if ((float)_DAT_0056e388 < *(float *)(((RGE_Moving_Object *)this->_padding_)->_padding_ + 0x150)
       ) {
      fVar5 = this->ballistic_acceleration * fVar18;
      fVar6 = fVar5 * _DAT_0056e380;
      fVar14 = this->ballistic_velocity;
      this->ballistic_velocity = fVar5 + this->ballistic_velocity;
      s = (fVar6 + fVar14) * fVar18 + s;
    }
    RGE_Moving_Object::set_velocity((RGE_Moving_Object *)this->_padding_,local_4,(float)bounds,s);
    uVar7 = RGE_Missile_Object::missile_move((RGE_Missile_Object *)this->_padding_);
    this_01 = (RGE_Missile_Object *)this->_padding_;
    bVar2 = *(byte *)(this_01->_padding_ + 0x148);
    if (bVar2 < 3) {
      this_02 = RGE_Missile_Object::make_object_collision_list(this_01,fVar16);
      if (this_02 != (RGE_Check_List *)0x0) {
        for (pRVar4 = this_02->list; pRVar4 != (RGE_Check_Node *)0x0; pRVar4 = pRVar4->next) {
          pRVar8 = (RGE_Static_Object *)this->_padding_;
          uVar3 = pRVar8->master_obj[1].convert_terrain_flag;
          if (uVar3 == '\0') {
            pRVar11 = (RGE_Static_Object *)this->_padding_;
            if (pRVar4->node == pRVar11) {
              pRVar10 = (RGE_Static_Object *)this->_padding_;
              if (pRVar10 == (RGE_Static_Object *)0x0) {
LAB_0040540a:
                fVar18 = pRVar8->world_z;
                iVar12 = pRVar8->_padding_;
                fVar16 = pRVar8->world_y;
                fVar14 = pRVar8->world_x;
                pRVar10 = pRVar8;
              }
              else {
LAB_004053f8:
                fVar18 = pRVar8->world_z;
                iVar12 = pRVar10->_padding_;
                fVar16 = pRVar8->world_y;
                fVar14 = pRVar8->world_x;
              }
LAB_0040541c:
              (**(code **)(iVar12 + 0x228))(pRVar11,pRVar10,fVar14,fVar16,fVar18);
              goto LAB_00405422;
            }
          }
          else if (uVar3 == '\x01') {
            pRVar11 = pRVar4->node;
            if ((pRVar11->owner != pRVar8->owner) && (pRVar11->owner->id != 0)) {
              pRVar10 = (RGE_Static_Object *)this->_padding_;
              if (pRVar10 == (RGE_Static_Object *)0x0) goto LAB_0040540a;
              fVar18 = pRVar8->world_z;
              iVar12 = pRVar10->_padding_;
              fVar16 = pRVar8->world_y;
              fVar14 = pRVar8->world_x;
              goto LAB_0040541c;
            }
          }
          else if (uVar3 == '\x02') {
            pRVar10 = (RGE_Static_Object *)this->_padding_;
            pRVar11 = pRVar4->node;
            if (pRVar10 == (RGE_Static_Object *)0x0) {
              if ((pRVar11->owner != pRVar8->owner) && (pRVar11->owner->id != 0)) goto LAB_0040540a;
              (**(code **)(pRVar8->_padding_ + 0x21c))
                        (pRVar8->world_x,pRVar8->world_y,pRVar8->world_z,pRVar8,0);
            }
            else {
              if (pRVar11 == pRVar10) goto LAB_0040542b;
              if ((pRVar11->owner != pRVar8->owner) && (pRVar11->owner->id != 0)) goto LAB_004053f8;
              (**(code **)(pRVar10->_padding_ + 0x21c))
                        (pRVar8->world_x,pRVar8->world_y,pRVar8->world_z,pRVar10,0);
            }
LAB_00405422:
            (**(code **)(this->_padding_ + 0x5c))(1);
          }
LAB_0040542b:
        }
        RGE_Check_List::~RGE_Check_List(this_02);
        operator_delete(this_02);
      }
    }
    else if (bVar2 == 3) {
      piVar17 = (int *)this->_padding_;
      if (piVar17 == (int *)0x0) {
        (**(code **)(this_01->_padding_ + 0x228))
                  (this->_padding_,this_01,this_01->_padding_,this_01->_padding_,this_01->_padding_)
        ;
        (**(code **)(this->_padding_ + 0x5c))(1);
      }
      else {
        (**(code **)(*piVar17 + 0x228))
                  (this->_padding_,piVar17,this_01->_padding_,this_01->_padding_,this_01->_padding_)
        ;
        (**(code **)(this->_padding_ + 0x5c))(1);
      }
    }
    if ((uVar7 != '\0') && ((char)this->_padding_ != '\x01')) {
      piVar17 = (int *)this->_padding_;
      if (piVar17 == (int *)0x0) {
        piVar17 = (int *)this->_padding_;
        iVar15 = piVar17[0x10];
        iVar12 = *piVar17;
        iVar13 = piVar17[0xf];
        iVar9 = piVar17[0xe];
      }
      else {
        iVar9 = this->_padding_;
        iVar12 = *piVar17;
        iVar15 = *(int *)(iVar9 + 0x40);
        iVar13 = *(int *)(iVar9 + 0x3c);
        iVar9 = *(int *)(iVar9 + 0x38);
      }
      (**(code **)(iVar12 + 0x21c))(iVar9,iVar13,iVar15,piVar17,0);
      (**(code **)(this->_padding_ + 0x5c))(1);
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: save
// Address: 004054b0
void __thiscall RGE_Action_Missile::save(RGE_Action_Missile *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->velocity_x,4);
  rge_write(param_1,&this->velocity_y,4);
  rge_write(param_1,&this->velocity_z,4);
  rge_write(param_1,&this->ballistic_velocity,4);
  rge_write(param_1,&this->ballistic_acceleration,4);
  return;
}

// --------------------------------------------------

