// Class: TRIBE_Action_Convert
// Size:  0x48
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
// [0x040] uchar was_same_owner
// [0x044] float requiredRange
// ----------------------------------------------------------------

// Function: TRIBE_Action_Convert
// Address: 004cd9e0
/* public: __thiscall TRIBE_Action_Convert::TRIBE_Action_Convert(int,class RGE_Action_Object *) */

TRIBE_Action_Convert * __thiscall
TRIBE_Action_Convert::TRIBE_Action_Convert
          (TRIBE_Action_Convert *this,int param_1,RGE_Action_Object *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fdc8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  local_4 = 0;
  this->requiredRange = 1.0;
  this->_padding_ = (int)&_vftable_;
                    /* language.dll match for 0x68: "Arial" */
  *(undefined2 *)&this->_padding_ = 0x68;
  rge_read(param_1,&this->was_same_owner,1);
  rge_read(param_1,&this->requiredRange,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004cda60
/* public: virtual void * __thiscall TRIBE_Action_Convert::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
TRIBE_Action_Convert::_vector_deleting_destructor_(TRIBE_Action_Convert *this,uint param_1)
{
  ~TRIBE_Action_Convert(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Convert
// Address: 004cda80
/* public: virtual __thiscall TRIBE_Action_Convert::~TRIBE_Action_Convert(void) */

void __thiscall TRIBE_Action_Convert::~TRIBE_Action_Convert(TRIBE_Action_Convert *this)
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

// Function: TRIBE_Action_Convert
// Address: 004cda90
/* public: __thiscall TRIBE_Action_Convert::TRIBE_Action_Convert(class RGE_Action_Object *,class
   RGE_Task *,class RGE_Static_Object *) */

TRIBE_Action_Convert * __thiscall
TRIBE_Action_Convert::TRIBE_Action_Convert
          (TRIBE_Action_Convert *this,RGE_Action_Object *param_1,RGE_Task *param_2,
          RGE_Static_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fde8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  local_4 = 0;
  this->requiredRange = 1.0;
  this->_padding_ = (int)&_vftable_;
                    /* language.dll match for 0x68: "Arial" */
  *(undefined2 *)&this->_padding_ = 0x68;
  RGE_Action::set_target_obj((RGE_Action *)this,param_3);
  if (param_3 != (RGE_Static_Object *)0x0) {
    this->_padding_ = (int)param_3->world_x;
    this->_padding_ = (int)param_3->world_y;
    this->_padding_ = (int)param_3->world_z;
  }
  this->was_same_owner = '\0';
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Convert
// Address: 004cdb20
/* public: __thiscall TRIBE_Action_Convert::TRIBE_Action_Convert(class RGE_Action_Object *,class
   RGE_Task *,float,float,float) */

TRIBE_Action_Convert * __thiscall
TRIBE_Action_Convert::TRIBE_Action_Convert
          (TRIBE_Action_Convert *this,RGE_Action_Object *param_1,RGE_Task *param_2,float param_3,
          float param_4,float param_5)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->_padding_ = (int)param_2;
  this->_padding_ = (int)param_4;
  this->requiredRange = 1.0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x68;
  this->_padding_ = (int)param_3;
  this->_padding_ = (int)param_5;
  this->was_same_owner = '\0';
  return this;
}

// --------------------------------------------------

// Function: save
// Address: 004cdb70
/* public: virtual void __thiscall TRIBE_Action_Convert::save(int) */

void __thiscall TRIBE_Action_Convert::save(TRIBE_Action_Convert *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->was_same_owner,1);
  rge_write(param_1,&this->requiredRange,4);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004cdbb0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Action_Convert::first_in_stack(unsigned char) */

void __thiscall TRIBE_Action_Convert::first_in_stack(TRIBE_Action_Convert *this,uchar param_1)
{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = this->_padding_;
  if (iVar4 != 0) {
    iVar3 = this->_padding_;
    sVar1 = *(short *)(*(int *)(iVar4 + 8) + 0x14);
    if (*(int *)(iVar4 + 0xc) == *(int *)(iVar3 + 0xc)) {
      this->was_same_owner = '\x01';
    }
    else {
      this->was_same_owner = '\0';
    }
    sVar2 = *(short *)(*(int *)(iVar4 + 8) + 0x10);
    if (((((sVar2 == 0x6d) || (sVar1 == 0x1b)) || (sVar2 == 0x9f)) ||
        ((sVar2 == 0x9e || (sVar2 == 0xa3)))) || (sVar2 == 0x114)) {
      iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(iVar3 + 0xc));
      if (iVar4 == 1) {
        (**(code **)(this->_padding_ + 0x5c))(0xb);
      }
      else {
        (**(code **)(this->_padding_ + 0x5c))(0xd);
      }
      sVar1 = *(short *)(*(int *)(this->_padding_ + 8) + 0x10);
      if (sVar1 != 0x6d) {
        if (sVar1 != 0x114) {
          return;
        }
                    /* language.dll match for 0x7a: "Arial" */
        (**(code **)(rge_base_game->_padding_ + 0x40))
                  (0x7a,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),0,0,0);
        return;
      }
                    /* language.dll match for 0x79: "N" */
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x79,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),0,0,0);
      return;
    }
    if (*(float *)(iVar3 + 0x44) < (float)_DAT_00574ff0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
                    /* language.dll match for 0x76: "B" */
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x76,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),0,0,0);
      return;
    }
    if (sVar1 == 3) {
      this->requiredRange = 1.0;
    }
    else {
      this->requiredRange = *(float *)(*(int *)(iVar3 + 8) + 0x114);
    }
    if (sVar1 == 0x1e) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      return;
    }
    if ((sVar1 == 0x12) && ((*(RGE_Player **)(iVar3 + 0xc))->attributes[0x1b] <= _DAT_00574ff8)) {
      iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(iVar3 + 0xc));
      if (iVar4 == 1) {
        (**(code **)(this->_padding_ + 0x5c))(0xb);
      }
      else {
        (**(code **)(this->_padding_ + 0x5c))(0xd);
      }
                    /* language.dll match for 0x77: "Arial" */
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x77,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),0,0,0);
      return;
    }
    if ((sVar1 == 3) && ((*(RGE_Player **)(iVar3 + 0xc))->attributes[0x1c] <= _DAT_00574ff8)) {
      iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(iVar3 + 0xc));
      if (iVar4 == 1) {
        (**(code **)(this->_padding_ + 0x5c))(0xb);
      }
      else {
        (**(code **)(this->_padding_ + 0x5c))(0xd);
      }
                    /* language.dll match for 0x78: "10" */
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x78,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),0,0,0);
      return;
    }
  }
  if (param_1 == '\0') {
    (**(code **)(this->_padding_ + 0x5c))(3);
    return;
  }
  if (iVar4 == 0) {
    (**(code **)(this->_padding_ + 0x5c))(3);
    return;
  }
  (**(code **)(this->_padding_ + 0x5c))(4);
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004cde10
/* protected: virtual void __thiscall TRIBE_Action_Convert::set_state(unsigned char) */

void __thiscall TRIBE_Action_Convert::set_state(TRIBE_Action_Convert *this,uchar param_1)
{
  RGE_Sound *this_00;
  int *piVar1;
  int iVar2;
  RGE_Action_Move_To *pRVar3;
  RGE_Action *pRVar4;
  undefined4 uVar5;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe16;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
  *(uchar *)&this->_padding_ = param_1;
  switch(param_1) {
  case '\x03':
    iVar2 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar2,iVar2,0x202,0x25c,0,0);
  case '\x01':
  case '\x02':
  case '\r':
  case '\x0e':
    iVar2 = *(int *)this->_padding_;
    uVar5 = *(undefined4 *)(((int *)this->_padding_)[2] + 0x18);
    break;
  case '\x04':
    iVar2 = this->_padding_;
    this->_padding_ = *(int *)(iVar2 + 0x38);
    this->_padding_ = *(int *)(iVar2 + 0x3c);
    this->_padding_ = *(int *)(iVar2 + 0x40);
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 1;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,(RGE_Action_Object *)this->_padding_,
                          (RGE_Static_Object *)this->_padding_,this->requiredRange,
                          *(RGE_Sprite **)(this->_padding_ + 0x34));
    }
    local_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar4);
    RGE_Action::setSubAction(pRVar4,'\x01');
    *unaff_FS_OFFSET = local_c;
    return;
  default:
    goto switchD_004cde43_caseD_5;
  case '\x06':
    iVar2 = *(int *)this->_padding_;
    uVar5 = *(undefined4 *)(this->_padding_ + 0x34);
    break;
  case '\a':
    (**(code **)(*(int *)this->_padding_ + 0x38))(*(undefined4 *)(this->_padding_ + 0x38));
    this_00 = *(RGE_Sound **)(this->_padding_ + 0x44);
    if (this_00 != (RGE_Sound *)0x0) {
      RGE_Sound::play(this_00,1);
    }
    if ((this->_padding_ != 0) &&
       (piVar1 = *(int **)(this->_padding_ + 0xc), 0 < *(short *)((int)piVar1 + 0x4a))) {
      iVar2 = this->_padding_;
                    /* language.dll match for 0x70: "B" */
      (**(code **)(*piVar1 + 0x94))
                (0x70,*(undefined4 *)(iVar2 + 0x38),*(undefined4 *)(iVar2 + 0x3c),
                 *(undefined4 *)(iVar2 + 0x40),0);
    }
    this->_padding_ = *(int *)(this->_padding_ + 0x20);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  case '\v':
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    local_4 = 0;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,(RGE_Action_Object *)this->_padding_,(float)this->_padding_,
                          (float)this->_padding_,(float)this->_padding_,this->requiredRange,
                          *(RGE_Sprite **)(this->_padding_ + 0x34));
    }
    local_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action::setSubAction(pRVar4,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)this->_padding_,pRVar4);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  (**(code **)(iVar2 + 0x38))(uVar5);
switchD_004cde43_caseD_5:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004ce070
// [HELPER] s_C__msdev_work_age1_x1_tact_cnv_c: "C:\msdev\work\age1_x1\tact_cnv.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall TRIBE_Action_Convert::update(void) */

uchar __thiscall TRIBE_Action_Convert::update(TRIBE_Action_Convert *this)
{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  float fVar4;
  undefined1 uVar5;
  char cVar6;
  RGE_Static_Object *pRVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  if ((this->_padding_ != -1) &&
     (pRVar7 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar7 == (RGE_Static_Object *)0x0)) {
LAB_004ce0c6:
    iVar8 = this->_padding_;
    (**(code **)(iVar8 + 0x54))(0);
    (**(code **)(iVar8 + 0x5c))(3);
    return '\0';
  }
  if ((this->_padding_ != -1) &&
     (pRVar7 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(this->_padding_ + 0xc) + 0x3c),
                          this->_padding_), pRVar7 == (RGE_Static_Object *)0x0)) {
    (**(code **)(this->_padding_ + 0x58))(0);
  }
  iVar8 = this->_padding_;
  if (iVar8 != 0) {
    if (*(char *)(iVar8 + 0x48) != '\x02') goto LAB_004ce0c6;
    if ((iVar8 != 0) &&
       (iVar8 = (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x1c))
                          ((int)*(short *)(*(int *)(iVar8 + 0xc) + 0x4a)), iVar8 == 1)) {
      cVar6 = (char)this->_padding_;
      if ((cVar6 == '\a') || ((cVar6 == '\x06' || (cVar6 == '\x04')))) {
        (**(code **)(*(int *)this->_padding_ + 0x80))(0x22,0);
      }
      (**(code **)(this->_padding_ + 0x5c))(1);
      iVar8 = ((int *)this->_padding_)[1];
      (**(code **)(*(int *)this->_padding_ + 0x148))(iVar8,iVar8,0x1fb,0x25c,0,0);
      return '\x04';
    }
  }
  switch((char)this->_padding_) {
  case '\x01':
    return '\x01';
  case '\x04':
    uVar5 = (**(code **)(*(int *)this->_padding_ + 0xc))();
    switch(uVar5) {
    case 1:
    case 2:
      (**(code **)(this->_padding_ + 0x5c))(6);
      return '\0';
    case 3:
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      return '\0';
    case 4:
    case 5:
switchD_004ce17c_caseD_3:
      iVar8 = this->_padding_;
      (**(code **)(iVar8 + 0x54))(0);
      (**(code **)(iVar8 + 0x5c))(0xb);
      return '\0';
    }
    break;
  case '\x06':
    if (this->_padding_ == 0) {
      (**(code **)(this->_padding_ + 0x5c))(3);
      return '\0';
    }
    cVar6 = (**(code **)(*(int *)this->_padding_ + 0x1f0))(this->_padding_,0,0);
    if (cVar6 != '\0') {
      (**(code **)(this->_padding_ + 0x5c))(7);
      return '\0';
    }
    break;
  case '\a':
    piVar2 = (int *)this->_padding_;
    if (piVar2 == (int *)0x0) {
switchD_004ce17c_caseD_0:
      (**(code **)(this->_padding_ + 0x5c))(3);
      return '\0';
    }
    uVar3 = *(undefined4 *)(this->_padding_ + 4);
    iVar8 = *piVar2;
    uVar9 = __ftol((int)*(short *)(piVar2[2] + 0x26));
    (**(code **)(iVar8 + 0x148))(uVar3,piVar2[1],500,uVar3,uVar9);
    iVar8 = this->_padding_;
    fVar4 = (float)this->_padding_ - *(float *)(*(int *)(*(int *)(iVar8 + 0xc) + 0x3c) + 0x84);
    this->_padding_ = (int)fVar4;
    if (fVar4 <= _DAT_00574ff8) {
      if ((this->_padding_ != 0) &&
         (piVar2 = *(int **)(this->_padding_ + 0xc), 0 < *(short *)((int)piVar2 + 0x4a))) {
                    /* language.dll match for 0x70: "B" */
        (**(code **)(*piVar2 + 0x94))
                  (0x70,*(undefined4 *)(iVar8 + 0x38),*(undefined4 *)(iVar8 + 0x3c),
                   *(undefined4 *)(iVar8 + 0x40),0);
      }
      iVar10 = debug_rand(s_C__msdev_work_age1_x1_tact_cnv_c,0x1d7);
      iVar8 = *(int *)(this->_padding_ + 0xc);
      fVar4 = (float)iVar10 * _DAT_00574ffc;
      if (*(char *)(iVar8 + 0x105) == '\x10') {
        fVar4 = fVar4 * _DAT_00575000;
      }
      else {
        sVar1 = *(short *)(*(int *)(this->_padding_ + 8) + 0x14);
        if ((((sVar1 == 0x15) || (sVar1 == 2)) || (sVar1 == 0x14)) ||
           ((sVar1 == 0x16 || (sVar1 == 0x12)))) {
          fVar4 = fVar4 + fVar4;
        }
        else if ((sVar1 == 0x23) || (sVar1 == 0x17)) {
          fVar4 = fVar4 * _DAT_00575004;
        }
      }
      if (fVar4 <= *(float *)(this->_padding_ + 0x1c) *
                   *(float *)(*(int *)(this->_padding_ + 8) + 0xe4)) {
                    /* language.dll match for 0x7b: "9" */
        (**(code **)(rge_base_game->_padding_ + 0x40))
                  (0x7b,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),
                   (int)*(short *)(iVar8 + 0x4a),0,0);
        (**(code **)(*(int *)this->_padding_ + 0x44))(*(undefined4 *)(this->_padding_ + 0xc));
        (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x78))(0x29,0x3f800000,0);
        (**(code **)(*(int *)this->_padding_ + 0x80))(0x22,0);
        (**(code **)(this->_padding_ + 0x5c))(3);
      }
      (**(code **)(this->_padding_ + 0x5c))(4);
      return '\0';
    }
    break;
  case '\v':
    uVar5 = (**(code **)(*(int *)this->_padding_ + 0xc))();
    switch(uVar5) {
    case 1:
    case 2:
    case 5:
      goto switchD_004ce17c_caseD_0;
    case 3:
      (**(code **)(this->_padding_ + 0x5c))(0xd);
      return '\0';
    case 4:
      goto switchD_004ce17c_caseD_3;
    }
    break;
  case '\r':
    iVar8 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar8,iVar8,0x1f9,0x25c,0,0);
    (**(code **)(this->_padding_ + 0x5c))(2);
    return '\x03';
  }
  return '\0';
}

// --------------------------------------------------

// Function: work
// Address: 004ce450
/* public: virtual int __thiscall TRIBE_Action_Convert::work(class RGE_Static_Object
   *,float,float,float) */

int __thiscall
TRIBE_Action_Convert::work
          (TRIBE_Action_Convert *this,RGE_Static_Object *param_1,float param_2,float param_3,
          float param_4)
{
  char cVar1;
  int iVar2;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  if (param_1 == (RGE_Static_Object *)this->_padding_) {
    cVar1 = (char)this->_padding_;
    if (cVar1 == '\x04') {
      return 1;
    }
    if (cVar1 == '\x06') {
      return 1;
    }
    if (cVar1 == '\a') {
      return 1;
    }
  }
  iVar2 = this->_padding_;
  (**(code **)(iVar2 + 0x54))(param_1);
  this->_padding_ = (int)param_1->world_x;
  this->_padding_ = (int)param_1->world_y;
  this->_padding_ = (int)param_1->world_z;
  (**(code **)(iVar2 + 0x1c))(1);
  return 1;
}

// --------------------------------------------------

// Function: martyrdom
// Address: 004ce4b0
/* public: void __thiscall TRIBE_Action_Convert::martyrdom(void) */

void __thiscall TRIBE_Action_Convert::martyrdom(TRIBE_Action_Convert *this)
{
  int iVar1;
  
  if ((((char)this->_padding_ == '\a') && (iVar1 = this->_padding_, iVar1 != 0)) &&
     (*(short *)(*(int *)(iVar1 + 8) + 0x14) != 0x12)) {
                    /* language.dll match for 0x7b: "9" */
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (0x7b,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),
               (int)*(short *)(*(int *)(iVar1 + 0xc) + 0x4a),0,0);
    (**(code **)(*(int *)this->_padding_ + 0x44))(*(undefined4 *)(this->_padding_ + 0xc));
    (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x78))(0x29,0x3f800000,0);
    (**(code **)(*(int *)this->_padding_ + 0x80))(0x22,0);
    (**(code **)(this->_padding_ + 0x5c))(3);
  }
  return;
}

// --------------------------------------------------

