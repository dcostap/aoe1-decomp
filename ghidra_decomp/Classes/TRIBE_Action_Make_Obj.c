// Class: TRIBE_Action_Make_Obj
// Size:  0x50
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
// [24] `vector_deleting_destructor'
// [25] setup
// [26] setup
// [27] create_action_list
// [28] rehook
// [29] save
// [30] type
// [31] first_in_stack
// [32] inside_obj_update
// [33] idle_update
// [34] update
// [35] stop
// [36] move_to
// [37] work
// [38] attack_response
// [39] relation_response
// [40] copy_obj
// [41] copy_obj_sprites
// [42] get_state_name
// [43] get_target_obj
// [44] get_target_obj2
// [45] set_target_obj
// [46] set_target_obj2
// [47] set_state
//
// Member Layout:
// [0x040] short obj_id
// [0x044] float work_done
// [0x048] int unique_id
// [0x04C] uchar pre_paid
// ----------------------------------------------------------------

// Function: TRIBE_Action_Make_Obj
// Address: 004d0dd0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(int,class RGE_Action_Object *) */

TRIBE_Action_Make_Obj * __thiscall
TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj
          (TRIBE_Action_Make_Obj *this,int param_1,RGE_Action_Object *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005600a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
  *(undefined2 *)&this->_padding_ = 0x66;
  rge_read(param_1,&this->obj_id,2);
  rge_read(param_1,&this->work_done,4);
  rge_read(param_1,&this->unique_id,4);
  if (_DAT_0057518c <= save_game_version) {
    rge_read(param_1,&this->pre_paid,1);
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  this->pre_paid = '\0';
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004d0e90
/* public: virtual void * __thiscall TRIBE_Action_Make_Obj::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Action_Make_Obj::_vector_deleting_destructor_(TRIBE_Action_Make_Obj *this,uint param_1)
{
  ~TRIBE_Action_Make_Obj(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Make_Obj
// Address: 004d0eb0
/* public: __thiscall TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(class RGE_Action_Object
   *,short,int,unsigned char) */

TRIBE_Action_Make_Obj * __thiscall
TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj
          (TRIBE_Action_Make_Obj *this,RGE_Action_Object *param_1,short param_2,int param_3,
          uchar param_4)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->pre_paid = param_4;
  this->unique_id = param_3;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x66;
  this->obj_id = param_2;
  this->work_done = 0.0;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Make_Obj
// Address: 004d0ef0
// [HELPER] s_WT__ld__MkObjDestructor__obj_id_: "WT=%ld, MkObjDestructor: obj_id=%d, obj->id=%d, uniqueID=%d."
/* public: virtual __thiscall TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj(void) */

void __thiscall TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj(TRIBE_Action_Make_Obj *this)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_005600c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  piVar1 = *(int **)(this->_padding_ + 0xc);
  (**(code **)(*piVar1 + 0xe4))
            (piVar1,s_WT__ld__MkObjDestructor__obj_id_,*(undefined4 *)(piVar1[0xf] + 4),
             (int)this->obj_id,*(undefined4 *)(this->_padding_ + 4),this->unique_id);
  local_4 = 0xffffffff;
  RGE_Action::~RGE_Action((RGE_Action *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004d0f70
/* public: virtual void __thiscall TRIBE_Action_Make_Obj::save(int) */

void __thiscall TRIBE_Action_Make_Obj::save(TRIBE_Action_Make_Obj *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->obj_id,2);
  rge_write(param_1,&this->work_done,4);
  rge_write(param_1,&this->unique_id,4);
  rge_write(param_1,&this->pre_paid,1);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004d0fc0
// [HELPER] s_Canceling_Train__1a___obj_id__d_: "Canceling Train #1a:  obj_id=%d, obj->id=%d, uniqueID=%d."
// [HELPER] s_Canceling_Train__1b___obj_id__d_: "Canceling Train #1b:  obj_id=%d, obj->id=%d, uniqueID=%d."
// [HELPER] s_Canceling_Train__1c___obj_id__d_: "Canceling Train #1c:  obj_id=%d, obj->id=%d, uniqueID=%d."
/* public: virtual void __thiscall TRIBE_Action_Make_Obj::first_in_stack(unsigned char) */

void __thiscall TRIBE_Action_Make_Obj::first_in_stack(TRIBE_Action_Make_Obj *this,uchar param_1)
{
  short sVar1;
  int *piVar2;
  TRIBE_Player *this_00;
  int iVar3;
  uchar uVar4;
  
  if (param_1 == '\0') {
    return;
  }
  sVar1 = this->obj_id;
  if (sVar1 < 0) {
    piVar2 = *(int **)(this->_padding_ + 0xc);
    (**(code **)(*piVar2 + 0xe4))
              (piVar2,s_Canceling_Train__1a___obj_id__d_,(int)sVar1,
               *(undefined4 *)(this->_padding_ + 4),this->unique_id);
  }
  else {
    this_00 = *(TRIBE_Player **)(this->_padding_ + 0xc);
    if (*(int *)(this_00->_padding_ + sVar1 * 4) != 0) {
      if ((this->pre_paid == '\0') &&
         (uVar4 = TRIBE_Player::pay_obj_cost(this_00,sVar1,1.0,0), uVar4 == '\0')) {
        piVar2 = *(int **)(this->_padding_ + 0xc);
        (**(code **)(*piVar2 + 0xe4))
                  (piVar2,s_Canceling_Train__1c___obj_id__d_,(int)this->obj_id,
                   *(undefined4 *)(this->_padding_ + 4),this->unique_id);
        (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x10c))
                  (0,(int)this->obj_id,*(undefined4 *)(this->_padding_ + 4),this->unique_id);
        iVar3 = ((int *)this->_padding_)[1];
        (**(code **)(*(int *)this->_padding_ + 0x148))(iVar3,iVar3,0x1f9,0x26b,0,0);
        (**(code **)(this->_padding_ + 0x5c))(1);
        return;
      }
      (**(code **)(this->_padding_ + 0x5c))(6);
      return;
    }
    (**(code **)(this_00->_padding_ + 0xe4))
              (this_00,s_Canceling_Train__1b___obj_id__d_,(int)sVar1,
               *(undefined4 *)(this->_padding_ + 4),this->unique_id);
  }
  (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x10c))
            (0,(int)this->obj_id,*(undefined4 *)(this->_padding_ + 4),this->unique_id);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004d10e0
/* protected: virtual void __thiscall TRIBE_Action_Make_Obj::set_state(unsigned char) */

void __thiscall TRIBE_Action_Make_Obj::set_state(TRIBE_Action_Make_Obj *this,uchar param_1)
{
  *(uchar *)&this->_padding_ = param_1;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004d10f0
// [HELPER] s_Canceling_Train__2___obj_id__d__: "Canceling Train #2:  obj_id=%d, obj->id=%d, uniqueID=%d."
/* WARNING: Variable defined which should be unmapped: newObject */
/* public: virtual unsigned char __thiscall TRIBE_Action_Make_Obj::update(void) */

uchar __thiscall TRIBE_Action_Make_Obj::update(TRIBE_Action_Make_Obj *this)
{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uchar uVar5;
  int iVar6;
  undefined4 uVar7;
  RGE_Static_Object *newObject;
  int local_4;
  
  cVar1 = (char)this->_padding_;
  if (cVar1 == '\x01') {
    return '\x01';
  }
  if (cVar1 == '\x06') {
    if (rge_base_game->quick_build == 0) {
      this->work_done =
           *(float *)(*(int *)(this->_padding_ + 8) + 0xe4) *
           *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84) + this->work_done;
    }
    else {
      this->work_done = 1000.0;
    }
    local_4 = (int)*(short *)(*(int *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x24) +
                                      this->obj_id * 4) + 0x15a);
    if ((float)local_4 <= this->work_done) {
      (**(code **)(this->_padding_ + 0x5c))(1);
      uVar5 = place_obj(this,&newObject);
      if (uVar5 == '\0') {
        TRIBE_Player::reimburse_obj_cost(*(TRIBE_Player **)(this->_padding_ + 0xc),this->obj_id);
                    /* language.dll match for 0x68: "Arial" */
        (**(code **)(rge_base_game->_padding_ + 0x40))
                  (0x68,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),(int)this->obj_id,0,
                   0);
        piVar2 = *(int **)(this->_padding_ + 0xc);
        (**(code **)(*piVar2 + 0xe4))
                  (piVar2,s_Canceling_Train__2___obj_id__d__,(int)this->obj_id,
                   *(undefined4 *)(this->_padding_ + 4),this->unique_id);
        (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x10c))
                  (0,(int)this->obj_id,*(undefined4 *)(this->_padding_ + 4),this->unique_id);
        iVar3 = ((int *)this->_padding_)[1];
        (**(code **)(*(int *)this->_padding_ + 0x148))(iVar3,iVar3,0x1f9,0x26b,0,0);
        return '\x01';
      }
      iVar3 = this->_padding_;
      iVar4 = rge_base_game->_padding_;
      iVar6 = __ftol();
      uVar7 = __ftol();
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
      (**(code **)(iVar4 + 0x40))
                (0x66,(int)*(short *)(*(int *)(iVar3 + 0xc) + 0x4a),(int)this->obj_id,uVar7);
      (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x110))
                ((int)this->obj_id,*(undefined4 *)(this->_padding_ + 4),this->unique_id,
                 *(undefined4 *)(iVar6 + 4));
      iVar3 = ((int *)this->_padding_)[1];
      (**(code **)(*(int *)this->_padding_ + 0x148))(iVar3,iVar3,0x1fa,0x26b,0,0);
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: place_obj
// Address: 004d12b0
// [HELPER] s_C__msdev_work_age1_x1_tact_mob_c: "C:\msdev\work\age1_x1\tact_mob.cpp"
/* WARNING: Variable defined which should be unmapped: radius_x */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: unsigned char __thiscall TRIBE_Action_Make_Obj::place_obj(class RGE_Static_Object * *)
    */

uchar __thiscall
TRIBE_Action_Make_Obj::place_obj(TRIBE_Action_Make_Obj *this,RGE_Static_Object **param_1)
{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  short sVar8;
  float radius_x;
  float radius_y;
  float radius_2x;
  float radius_2y;
  short index;
  int local_4;
  
  sVar4 = 0;
  iVar5 = *(int *)(this->_padding_ + 8);
  piVar1 = *(int **)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x24) + this->obj_id * 4);
  radius_y = (*(float *)(iVar5 + 0x30) + (float)piVar1[0xc]) - _DAT_00575190;
  pcVar2 = *(code **)(*piVar1 + 0x20);
  radius_2y = radius_y + radius_y;
  radius_2x = (*(float *)(iVar5 + 0x34) + (float)piVar1[0xd]) - _DAT_00575190;
  _index = (undefined4 *)(radius_2x + radius_2x);
  do {
    sVar8 = 0;
    do {
      if (sVar8 < 0x28) {
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xc0);
        iVar5 = iVar5 * 2;
        sVar7 = ((short)(iVar5 / 0x7fff) + (short)(iVar5 >> 0x1f)) -
                (short)((longlong)iVar5 * 0x80010003 >> 0x3f);
      }
      else {
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xc2);
        sVar7 = (short)((iVar5 * 2) / 0x7fff) + 2;
      }
      switch(sVar7) {
      case 0:
        this->_padding_ = (int)(*(float *)(this->_padding_ + 0x3c) + radius_2x);
        local_4 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,199);
        iVar5 = this->_padding_;
        goto LAB_004d1449;
      case 1:
        this->_padding_ = (int)(*(float *)(this->_padding_ + 0x38) - radius_y);
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xcb);
        this->_padding_ =
             (int)(((float)iVar5 * (float)_index * _DAT_00575198 - radius_2x) +
                  *(float *)(this->_padding_ + 0x3c));
        break;
      case 2:
        this->_padding_ = (int)(*(float *)(this->_padding_ + 0x38) + radius_y);
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xcf);
        this->_padding_ =
             (int)(((float)iVar5 * (float)_index * _DAT_00575198 - radius_2x) +
                  *(float *)(this->_padding_ + 0x3c));
        break;
      case 3:
        this->_padding_ = (int)(*(float *)(this->_padding_ + 0x3c) - radius_2x);
        local_4 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xd3);
        iVar5 = this->_padding_;
LAB_004d1449:
        this->_padding_ =
             (int)(((float)local_4 * radius_2y * _DAT_00575198 - radius_y) +
                  *(float *)(iVar5 + 0x38));
      }
      cVar3 = (*pcVar2)(*(undefined4 *)(this->_padding_ + 0xc),this->_padding_,this->_padding_,0,1,1
                        ,1,0,0,1);
      if (cVar3 == '\0') {
        iVar5 = *(int *)(this->_padding_ + 0xc);
        uVar6 = (**(code **)(**(int **)(*(int *)(iVar5 + 0x24) + this->obj_id * 4) + 0x18))
                          (iVar5,this->_padding_,this->_padding_,
                           *(undefined4 *)(this->_padding_ + 0x40));
        *_index = uVar6;
        return '\x01';
      }
      sVar8 = sVar8 + 1;
    } while (sVar8 < 0x3c);
    radius_y = (float)piVar1[0xc] + (float)piVar1[0xc] + radius_y;
    radius_2x = (float)piVar1[0xd] + (float)piVar1[0xd] + radius_2x;
    radius_2y = (float)piVar1[0xc] * _DAT_0057519c + radius_2y;
    _index = (undefined4 *)((float)piVar1[0xd] * _DAT_0057519c + (float)_index);
    sVar4 = sVar4 + 1;
    if (2 < sVar4) {
      return '\0';
    }
  } while( true );
}

// --------------------------------------------------

// Function: stop
// Address: 004d1550
// [HELPER] s_Stopping_Train__8___obj_id__d__o: "Stopping Train #8:  obj_id=%d, obj->id=%d, uniqueID=%d."
/* public: virtual int __thiscall TRIBE_Action_Make_Obj::stop(void) */

int __thiscall TRIBE_Action_Make_Obj::stop(TRIBE_Action_Make_Obj *this)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(this->_padding_ + 0xc);
  (**(code **)(*piVar1 + 0xe4))
            (piVar1,s_Stopping_Train__8___obj_id__d__o,(int)this->obj_id,
             *(undefined4 *)(this->_padding_ + 4),this->unique_id);
  if ((char)this->_padding_ != '\x01') {
    (**(code **)(this->_padding_ + 0x5c))(1);
    if (this->pre_paid == '\0') {
      TRIBE_Player::reimburse_obj_cost(*(TRIBE_Player **)(this->_padding_ + 0xc),this->obj_id);
    }
  }
                    /* language.dll match for 0x67: "Comic Sans MS" */
  (**(code **)(rge_base_game->_padding_ + 0x40))
            (0x67,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),(int)this->obj_id,0,0);
  iVar2 = ((int *)this->_padding_)[1];
  (**(code **)(*(int *)this->_padding_ + 0x148))(iVar2,iVar2,0x1f9,0x26b,0,0);
  return 1;
}

// --------------------------------------------------

// Function: get_info
// Address: 004d15f0
/* public: void __thiscall TRIBE_Action_Make_Obj::get_info(short &,short &,char *,short) */

void __thiscall
TRIBE_Action_Make_Obj::get_info
          (TRIBE_Action_Make_Obj *this,short *param_1,short *param_2,char *param_3,short param_4)
{
  short sVar1;
  
  *param_1 = this->obj_id;
  if ((char)this->_padding_ == '\x01') {
    *param_2 = 100;
  }
  else {
    sVar1 = __ftol();
    *param_2 = sVar1;
  }
  if (param_3 != (char *)0x0) {
    strncpy(param_3,*(undefined4 *)
                     (*(int *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x24) + this->obj_id * 4)
                     + 8),(int)param_4);
    param_3[param_4 + -1] = '\0';
  }
  return;
}

// --------------------------------------------------

