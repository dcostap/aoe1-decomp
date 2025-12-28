// Class: TRIBE_Action_Make_Tech
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
// [0x040] short tech_id
// [0x044] int unique_id
// ----------------------------------------------------------------

// Function: TRIBE_Action_Make_Tech
// Address: 004d21b0
TRIBE_Action_Make_Tech * __thiscall
TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech
          (TRIBE_Action_Make_Tech *this,int param_1,RGE_Action_Object *param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560148;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x67;
  rge_read(param_1,&this->tech_id,2);
  rge_read(param_1,&this->unique_id,4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004d2230
void * __thiscall
TRIBE_Action_Make_Tech::_vector_deleting_destructor_(TRIBE_Action_Make_Tech *this,uint param_1)
{
  ~TRIBE_Action_Make_Tech(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Make_Tech
// Address: 004d2250
TRIBE_Action_Make_Tech * __thiscall
TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech
          (TRIBE_Action_Make_Tech *this,RGE_Action_Object *param_1,short param_2,int param_3)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  this->unique_id = param_3;
  this->_padding_ = (int)&_vftable_;
  *(undefined2 *)&this->_padding_ = 0x67;
  this->tech_id = param_2;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Make_Tech
// Address: 004d2290
void __thiscall TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech(TRIBE_Action_Make_Tech *this)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00560168;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if ((char)this->_padding_ != '\x01') {
    TRIBE_Player_Tech::cancel_research
              (*(TRIBE_Player_Tech **)(*(int *)(this->_padding_ + 0xc) + 0x220),this->tech_id,'\0');
    if (rge_base_game->world->game_state == '\0') {
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x65,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),(int)this->tech_id,0,0
                );
      (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x118))
                ((int)this->tech_id,*(undefined4 *)(this->_padding_ + 4),0xffffffff,this->unique_id)
      ;
      iVar1 = ((int *)this->_padding_)[1];
      (**(code **)(*(int *)this->_padding_ + 0x148))(iVar1,iVar1,0x1f9,0x26c,0,0);
    }
  }
  local_4 = 0xffffffff;
  RGE_Action::~RGE_Action((RGE_Action *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004d2370
void __thiscall TRIBE_Action_Make_Tech::save(TRIBE_Action_Make_Tech *this,int param_1)
{
  RGE_Action::save((RGE_Action *)this,param_1);
  rge_write(param_1,&this->tech_id,2);
  rge_write(param_1,&this->unique_id,4);
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004d23b0
void __thiscall TRIBE_Action_Make_Tech::first_in_stack(TRIBE_Action_Make_Tech *this,uchar param_1)
{
  int iVar1;
  uchar uVar2;
  undefined1 in_stack_00000005;
  
  if ((param_1 != '\0') && (-1 < this->tech_id)) {
    uVar2 = TRIBE_Player_Tech::start_research
                      (*(TRIBE_Player_Tech **)(*(int *)(this->_padding_ + 0xc) + 0x220),
                       this->tech_id,'\x01',(short *)&param_1);
    if (uVar2 == '\x01') {
      (**(code **)(this->_padding_ + 0x5c))(6);
      return;
    }
    (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x118))
              ((int)_param_1,(int)this->tech_id,*(undefined4 *)(this->_padding_ + 4),this->unique_id
              );
    iVar1 = ((int *)this->_padding_)[1];
    (**(code **)(*(int *)this->_padding_ + 0x148))(iVar1,iVar1,0x1f9,0x26c,0,0);
    (**(code **)(this->_padding_ + 0x5c))(1);
  }
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004d2440
void __thiscall TRIBE_Action_Make_Tech::set_state(TRIBE_Action_Make_Tech *this,uchar param_1)
{
  *(uchar *)&this->_padding_ = param_1;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004d2450
uchar __thiscall TRIBE_Action_Make_Tech::update(TRIBE_Action_Make_Tech *this)
{
  char cVar1;
  int iVar2;
  int iVar3;
  uchar uVar4;
  undefined4 uVar5;
  float work;
  float local_4;
  
  cVar1 = (char)this->_padding_;
  if (cVar1 == '\x01') {
    return '\x01';
  }
  if (cVar1 == '\x06') {
    if (rge_base_game->quick_build == 0) {
      local_4 = *(float *)(*(int *)(*(int *)(this->_padding_ + 0xc) + 0x3c) + 0x84) *
                *(float *)(*(int *)(this->_padding_ + 8) + 0xe4);
    }
    else {
      local_4 = 1000.0;
    }
    uVar4 = TRIBE_Player_Tech::research
                      (*(TRIBE_Player_Tech **)(*(int *)(this->_padding_ + 0xc) + 0x220),
                       this->tech_id,local_4);
    if (uVar4 == '\0') {
      (**(code **)(this->_padding_ + 0x5c))(1);
      iVar2 = this->_padding_;
      iVar3 = rge_base_game->_padding_;
      uVar5 = __ftol();
      uVar5 = __ftol(uVar5);
      (**(code **)(iVar3 + 0x40))
                (100,(int)*(short *)(*(int *)(iVar2 + 0xc) + 0x4a),(int)this->tech_id,uVar5);
      (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x11c))
                ((int)this->tech_id,*(undefined4 *)(this->_padding_ + 4),this->unique_id);
      iVar2 = ((int *)this->_padding_)[1];
      (**(code **)(*(int *)this->_padding_ + 0x148))(iVar2,iVar2,0x1fa,0x26c,0,0);
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: stop
// Address: 004d2550
int __thiscall TRIBE_Action_Make_Tech::stop(TRIBE_Action_Make_Tech *this)
{
  int iVar1;
  
  (**(code **)(this->_padding_ + 0x5c))(1);
  TRIBE_Player_Tech::cancel_research
            (*(TRIBE_Player_Tech **)(*(int *)(this->_padding_ + 0xc) + 0x220),this->tech_id,'\x01');
  (**(code **)(rge_base_game->_padding_ + 0x40))
            (0x65,(int)*(short *)(*(int *)(this->_padding_ + 0xc) + 0x4a),(int)this->tech_id,0,0);
  (**(code **)(**(int **)(this->_padding_ + 0xc) + 0x118))
            ((int)this->tech_id,*(undefined4 *)(this->_padding_ + 4),0xffffffff,this->unique_id);
  iVar1 = ((int *)this->_padding_)[1];
  (**(code **)(*(int *)this->_padding_ + 0x148))(iVar1,iVar1,0x1f9,0x26c,0,0);
  return 1;
}

// --------------------------------------------------

// Function: get_info
// Address: 004d25e0
void __thiscall
TRIBE_Action_Make_Tech::get_info
          (TRIBE_Action_Make_Tech *this,short *param_1,short *param_2,char *param_3,short param_4)
{
  short sVar1;
  char *pcVar2;
  int iVar3;
  
  *param_1 = this->tech_id;
  if ((char)this->_padding_ == '\x01') {
    *param_2 = 100;
  }
  else {
    sVar1 = TRIBE_Player_Tech::get_progress
                      (*(TRIBE_Player_Tech **)(*(int *)(this->_padding_ + 0xc) + 0x220),
                       this->tech_id);
    *param_2 = sVar1;
  }
  if (param_3 != (char *)0x0) {
    iVar3 = (int)param_4;
    pcVar2 = TRIBE_Player_Tech::get_name
                       (*(TRIBE_Player_Tech **)(*(int *)(this->_padding_ + 0xc) + 0x220),
                        this->tech_id);
    strncpy(param_3,pcVar2,iVar3);
    param_3[param_4 + -1] = '\0';
  }
  return;
}

// --------------------------------------------------

