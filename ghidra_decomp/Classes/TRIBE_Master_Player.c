// Class: TRIBE_Master_Player
// Size:  0x2C
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] finish_init
// [02] load_master_object
// [03] create_master_object_space
// [04] load_object
// [05] save
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Master_Player
// Address: 005117c0
TRIBE_Master_Player * __thiscall
TRIBE_Master_Player::TRIBE_Master_Player(TRIBE_Master_Player *this,_iobuf *param_1)
{
  RGE_Master_Player::RGE_Master_Player((RGE_Master_Player *)this,param_1);
  *(undefined ***)this = &_vftable_;
  this->field_0x29 = 1;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 005117e0
void * __thiscall
TRIBE_Master_Player::_scalar_deleting_destructor_(TRIBE_Master_Player *this,uint param_1)
{
  ~TRIBE_Master_Player(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Master_Player
// Address: 00511800
TRIBE_Master_Player * __thiscall
TRIBE_Master_Player::TRIBE_Master_Player(TRIBE_Master_Player *this,int param_1)
{
  RGE_Master_Player::RGE_Master_Player((RGE_Master_Player *)this,param_1);
  *(undefined ***)this = &_vftable_;
  this->field_0x29 = 1;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Master_Player
// Address: 00511820
void __thiscall TRIBE_Master_Player::~TRIBE_Master_Player(TRIBE_Master_Player *this)
{
  *(undefined ***)this = &_vftable_;
  RGE_Master_Player::~RGE_Master_Player((RGE_Master_Player *)this);
  return;
}

// --------------------------------------------------

// Function: load_master_object
// Address: 00511830
void __thiscall
TRIBE_Master_Player::load_master_object
          (TRIBE_Master_Player *this,int param_1,uchar param_2,RGE_Sprite **param_3,
          RGE_Sound **param_4,short param_5)
{
  TRIBE_Master_Tree_Object *this_00;
  undefined4 uVar1;
  TRIBE_Master_Building_Object *this_01;
  TRIBE_Master_Combat_Object *this_02;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005610c1;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 == 'F') {
    this_02 = (TRIBE_Master_Combat_Object *)operator_new(0x164);
    local_4 = 0;
    if (this_02 != (TRIBE_Master_Combat_Object *)0x0) {
      uVar1 = TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
                        (this_02,param_1,param_3,param_4,1);
      goto LAB_00511972;
    }
  }
  else {
    if (param_2 == 'P') {
      this_01 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
      local_4 = 1;
      if (this_01 != (TRIBE_Master_Building_Object *)0x0) {
        uVar1 = TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
                          (this_01,param_1,param_3,param_4,1);
        *(undefined4 *)(*(int *)&this->field_0x1c + param_5 * 4) = uVar1;
        *unaff_FS_OFFSET = local_c;
        return;
      }
      *(undefined4 *)(*(int *)&this->field_0x1c + param_5 * 4) = 0;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    if (param_2 != 'Z') {
      RGE_Master_Player::load_master_object
                ((RGE_Master_Player *)this,param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    this_00 = (TRIBE_Master_Tree_Object *)operator_new(0xb8);
    local_4 = 2;
    if (this_00 != (TRIBE_Master_Tree_Object *)0x0) {
      uVar1 = TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(this_00,param_1,param_3,param_4,1);
      goto LAB_00511972;
    }
  }
  uVar1 = 0;
LAB_00511972:
  *(undefined4 *)(*(int *)&this->field_0x1c + param_5 * 4) = uVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load_object
// Address: 00511990
void __thiscall
TRIBE_Master_Player::load_object
          (TRIBE_Master_Player *this,_iobuf *param_1,uchar param_2,RGE_Sprite **param_3,
          RGE_Sound **param_4,short param_5)
{
  TRIBE_Master_Tree_Object *this_00;
  undefined4 uVar1;
  TRIBE_Master_Building_Object *this_01;
  TRIBE_Master_Combat_Object *this_02;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005610f1;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 == 'F') {
    this_02 = (TRIBE_Master_Combat_Object *)operator_new(0x164);
    local_4 = 0;
    if (this_02 != (TRIBE_Master_Combat_Object *)0x0) {
      uVar1 = TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
                        (this_02,param_1,param_3,param_4,param_5,1);
      goto LAB_00511ae1;
    }
  }
  else {
    if (param_2 == 'P') {
      this_01 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
      local_4 = 1;
      if (this_01 != (TRIBE_Master_Building_Object *)0x0) {
        uVar1 = TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
                          (this_01,param_1,param_3,param_4,param_5,1);
        *(undefined4 *)(*(int *)&this->field_0x1c + param_5 * 4) = uVar1;
        *unaff_FS_OFFSET = local_c;
        return;
      }
      *(undefined4 *)(*(int *)&this->field_0x1c + param_5 * 4) = 0;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    if (param_2 != 'Z') {
      RGE_Master_Player::load_object
                ((RGE_Master_Player *)this,param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    this_00 = (TRIBE_Master_Tree_Object *)operator_new(0xb8);
    local_4 = 2;
    if (this_00 != (TRIBE_Master_Tree_Object *)0x0) {
      uVar1 = TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
                        (this_00,param_1,param_3,param_4,param_5,1);
      goto LAB_00511ae1;
    }
  }
  uVar1 = 0;
LAB_00511ae1:
  *(undefined4 *)(*(int *)&this->field_0x1c + param_5 * 4) = uVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

