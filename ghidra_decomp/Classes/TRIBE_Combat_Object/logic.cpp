// Class: TRIBE_Combat_Object
// Function: TRIBE_Combat_Object
// Address: 004ca0f0
/* public: __thiscall TRIBE_Combat_Object::TRIBE_Combat_Object(class TRIBE_Master_Combat_Object
   *,class RGE_Player *,float,float,float,int) */

TRIBE_Combat_Object * __thiscall
TRIBE_Combat_Object::TRIBE_Combat_Object
          (TRIBE_Combat_Object *this,TRIBE_Master_Combat_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fb18;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Combat_Object::RGE_Combat_Object
            ((RGE_Combat_Object *)this,(RGE_Master_Combat_Object *)param_1,param_2,param_3,param_4,
             param_5,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004ca180
/* public: virtual void * __thiscall TRIBE_Combat_Object::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Combat_Object::_vector_deleting_destructor_(TRIBE_Combat_Object *this,uint param_1)
{
  ~TRIBE_Combat_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Combat_Object
// Address: 004ca1a0
/* public: __thiscall TRIBE_Combat_Object::TRIBE_Combat_Object(int,class RGE_Game_World *,int) */

TRIBE_Combat_Object * __thiscall
TRIBE_Combat_Object::TRIBE_Combat_Object
          (TRIBE_Combat_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fb38;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Combat_Object::RGE_Combat_Object((RGE_Combat_Object *)this,param_1,param_2,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Combat_Object
// Address: 004ca210
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual __thiscall TRIBE_Combat_Object::~TRIBE_Combat_Object(void) */

void __thiscall TRIBE_Combat_Object::~TRIBE_Combat_Object(TRIBE_Combat_Object *this)
{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055fb58;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->own_master != '\0') {
    puVar2 = (undefined4 *)this->_padding_;
    sVar1 = *(short *)(puVar2 + 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    this->_padding_ = *(int *)(*(int *)(this->_padding_ + 0x24) + sVar1 * 4);
  }
  iVar3 = this->_padding_;
  sVar1 = *(short *)(iVar3 + 0x14);
  if (((sVar1 == 4) || (sVar1 == 0x15)) || (sVar1 == 2)) {
    iVar3 = *(int *)(this->_padding_ + 0x50);
    *(float *)(iVar3 + 0x94) = *(float *)(iVar3 + 0x94) - _DAT_00574c78;
  }
  else if (((sVar1 != 0x12) && (*(char *)(iVar3 + 4) == 'F')) ||
          ((sVar1 = *(short *)(iVar3 + 0x10), sVar1 == 0x4f || ((sVar1 == 0x45 || (sVar1 == 199)))))
          ) {
    iVar3 = *(int *)(this->_padding_ + 0x50);
    *(float *)(iVar3 + 0xa0) = *(float *)(iVar3 + 0xa0) - _DAT_00574c78;
  }
  local_4 = 0xffffffff;
  RGE_Combat_Object::~RGE_Combat_Object((RGE_Combat_Object *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 004ca300
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual int __thiscall TRIBE_Combat_Object::setup(class TRIBE_Master_Combat_Object
   *,class RGE_Player *,float,float,float) */

int __thiscall
TRIBE_Combat_Object::setup
          (TRIBE_Combat_Object *this,TRIBE_Master_Combat_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5)
{
  short sVar1;
  int iVar2;
  
  RGE_Combat_Object::setup
            ((RGE_Combat_Object *)this,(RGE_Master_Combat_Object *)param_1,param_2,param_3,param_4,
             param_5);
  if (*(short *)(this->_padding_ + 0x4a) == 0) {
    *(undefined1 *)&this->_padding_ = 1;
  }
  iVar2 = this->_padding_;
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x46;
  (**(code **)(iVar2 + 0x250))();
  iVar2 = this->_padding_;
  this->own_master = '\0';
  sVar1 = *(short *)(iVar2 + 0x14);
  if (((sVar1 == 4) || (sVar1 == 0x15)) || (sVar1 == 2)) {
    iVar2 = *(int *)(this->_padding_ + 0x50);
    *(float *)(iVar2 + 0x94) = *(float *)(iVar2 + 0x94) - _DAT_00574c7c;
  }
  else if (((sVar1 != 0x12) && (*(char *)(iVar2 + 4) == 'F')) ||
          ((sVar1 = *(short *)(iVar2 + 0x10), sVar1 == 0x4f || ((sVar1 == 0x45 || (sVar1 == 199)))))
          ) {
    iVar2 = *(int *)(this->_padding_ + 0x50);
    *(float *)(iVar2 + 0xa0) = *(float *)(iVar2 + 0xa0) - _DAT_00574c7c;
  }
  if (*(short *)(this->_padding_ + 0x14) == 0x12) {
    this->_padding_ = 0x42c80000;
    *(undefined2 *)&this->_padding_ = 0x22;
  }
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 004ca3e0
/* protected: virtual int __thiscall TRIBE_Combat_Object::setup(int,class RGE_Game_World *) */

int __thiscall
TRIBE_Combat_Object::setup(TRIBE_Combat_Object *this,int param_1,RGE_Game_World *param_2)
{
  int iVar1;
  TRIBE_Master_Combat_Object *this_00;
  int iVar2;
  TRIBE_Master_Building_Object *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fb86;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Combat_Object::setup((RGE_Combat_Object *)this,param_1,param_2);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x46;
  rge_read(iVar1,&this->own_master,1);
  if (this->own_master == '\0') goto LAB_004ca4c1;
  rge_read(iVar1,&param_2,1);
  if ((char)param_2 == 'F') {
    this_00 = (TRIBE_Master_Combat_Object *)operator_new(0x164);
    local_4 = 0;
    if (this_00 == (TRIBE_Master_Combat_Object *)0x0) {
LAB_004ca4b4:
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(this->_padding_ + 0x3c);
      iVar2 = TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
                        (this_00,iVar1,*(RGE_Sprite ***)(iVar2 + 0x38),
                         *(RGE_Sound ***)(iVar2 + 0x30),1);
    }
  }
  else {
    if ((char)param_2 != 'P') goto LAB_004ca4c1;
    this_01 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
    local_4 = 1;
    if (this_01 == (TRIBE_Master_Building_Object *)0x0) goto LAB_004ca4b4;
    iVar2 = *(int *)(this->_padding_ + 0x3c);
    iVar2 = TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
                      (this_01,iVar1,*(RGE_Sprite ***)(iVar2 + 0x38),*(RGE_Sound ***)(iVar2 + 0x30),
                       1);
  }
  local_4 = 0xffffffff;
  this->_padding_ = iVar2;
LAB_004ca4c1:
  rge_read(iVar1,&param_1,4);
  if (param_1 == 1) {
    (**(code **)(this->_padding_ + 0x250))();
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 8))(iVar1);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: create_action_list
// Address: 004ca510
/* public: virtual class RGE_Action_List * __thiscall TRIBE_Combat_Object::create_action_list(void)
    */

RGE_Action_List * __thiscall TRIBE_Combat_Object::create_action_list(TRIBE_Combat_Object *this)
{
  TRIBE_Action_List *this_00;
  RGE_Action_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fb9b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Action_List *)operator_new(0xc);
  local_4 = 0;
  if (this_00 != (TRIBE_Action_List *)0x0) {
    pRVar1 = (RGE_Action_List *)
             TRIBE_Action_List::TRIBE_Action_List(this_00,(RGE_Action_Object *)this);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Action_List *)0x0;
}

// --------------------------------------------------

// Function: save
// Address: 004ca570
/* public: virtual void __thiscall TRIBE_Combat_Object::save(int) */

void __thiscall TRIBE_Combat_Object::save(TRIBE_Combat_Object *this,int param_1)
{
  int iVar1;
  
  iVar1 = param_1;
  RGE_Combat_Object::save((RGE_Combat_Object *)this,param_1);
  rge_write(iVar1,&this->own_master,1);
  if (this->own_master != '\0') {
    (**(code **)(*(int *)this->_padding_ + 0x14))(iVar1);
  }
  if (this->_padding_ != 0) {
    param_1 = 1;
    rge_write(iVar1,&param_1,4);
    (**(code **)(*(int *)this->_padding_ + 4))(iVar1);
    return;
  }
  param_1 = 0;
  rge_write(iVar1,&param_1,4);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004ca5f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall TRIBE_Combat_Object::update(void) */

uchar __thiscall TRIBE_Combat_Object::update(TRIBE_Combat_Object *this)
{
  bool bVar1;
  float fVar2;
  uchar uVar3;
  
  if ((*(short *)(this->_padding_ + 0x14) == 0x12) && ((char)this->_padding_ == '\x02')) {
    fVar2 = *(float *)(*(int *)(this->_padding_ + 0x50) + 0x8c) *
            *(float *)(*(int *)(this->_padding_ + 0x3c) + 0x84) + (float)this->_padding_;
    bVar1 = _DAT_00574c80 <= fVar2;
    this->_padding_ = (int)fVar2;
    if (bVar1) {
      this->_padding_ = 0x42c80000;
    }
    *(undefined2 *)&this->_padding_ = 0x22;
  }
  uVar3 = RGE_Combat_Object::update((RGE_Combat_Object *)this);
  return uVar3;
}

// --------------------------------------------------

// Function: modify
// Address: 004ca640
/* public: virtual void __thiscall TRIBE_Combat_Object::modify(float,unsigned char) */

void __thiscall TRIBE_Combat_Object::modify(TRIBE_Combat_Object *this,float param_1,uchar param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 'e') {
    iVar3 = 0x70;
    iVar2 = 0x6a;
    do {
      if (*(short *)(iVar2 + this->_padding_) == 4) {
        iVar1 = *(int *)(this->_padding_ + 0x50);
        *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) - *(float *)(iVar3 + this->_padding_);
        iVar1 = *(int *)(this->_padding_ + 0x50);
        *(float *)(iVar1 + 0x10) = param_1 + *(float *)(iVar1 + 0x10);
      }
      if (*(short *)(iVar2 + this->_padding_) == 0xb) {
        iVar1 = *(int *)(this->_padding_ + 0x50);
        *(float *)(iVar1 + 0x2c) = *(float *)(iVar1 + 0x2c) - *(float *)(iVar3 + this->_padding_);
        iVar1 = *(int *)(this->_padding_ + 0x50);
        *(float *)(iVar1 + 0x2c) = *(float *)(iVar1 + 0x2c) - param_1;
      }
      if (*(short *)(iVar2 + this->_padding_) == 0x13) {
        iVar1 = *(int *)(this->_padding_ + 0x50);
        *(float *)(iVar1 + 0x4c) = *(float *)(iVar1 + 0x4c) - *(float *)(iVar3 + this->_padding_);
        iVar1 = *(int *)(this->_padding_ + 0x50);
        *(float *)(iVar1 + 0x4c) = *(float *)(iVar1 + 0x4c) - param_1;
      }
      iVar2 = iVar2 + 2;
      iVar3 = iVar3 + 4;
    } while (iVar2 < 0x70);
  }
  RGE_Static_Object::modify((RGE_Static_Object *)this,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: transform
// Address: 004ca700
/* public: virtual void __thiscall TRIBE_Combat_Object::transform(class RGE_Master_Static_Object *)
    */

void __thiscall
TRIBE_Combat_Object::transform(TRIBE_Combat_Object *this,RGE_Master_Static_Object *param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)this->_padding_;
  RGE_Action_Object::transform((RGE_Action_Object *)this,param_1);
  if (this->own_master == '\x01') {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    this->own_master = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: set_object_state
// Address: 004ca740
/* public: virtual void __thiscall TRIBE_Combat_Object::set_object_state(unsigned char) */

void __thiscall TRIBE_Combat_Object::set_object_state(TRIBE_Combat_Object *this,uchar param_1)
{
  if ((((*(char *)(*(int *)(this->_padding_ + 0x3c) + 0x1d) == '\0') && (2 < param_1)) &&
      ((byte)this->_padding_ < 3)) && (*(short *)(this->_padding_ + 0x14) == 1)) {
    reposition_artifact(this);
    return;
  }
  RGE_Static_Object::set_object_state((RGE_Static_Object *)this,param_1);
  return;
}

// --------------------------------------------------

// Function: cancel_object
// Address: 004ca780
/* public: virtual void __thiscall TRIBE_Combat_Object::cancel_object(void) */

void __thiscall TRIBE_Combat_Object::cancel_object(TRIBE_Combat_Object *this)
{
                    /* WARNING: Could not recover jumptable at 0x004ca782. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(this->_padding_ + 0x6c))();
  return;
}

// --------------------------------------------------

// Function: die_die_die
// Address: 004ca790
// [HELPER] die_die_die: " "
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Combat_Object::die_die_die(void) */

void __thiscall TRIBE_Combat_Object::die_die_die(TRIBE_Combat_Object *this)
{
  short sVar1;
  TRIBE_Action_Convert *this_00;
  
  if (((char)this->_padding_ == '\x02') &&
     (_DAT_00574c78 <= *(float *)(*(int *)(this->_padding_ + 0x50) + 0xe4))) {
    this_00 = (TRIBE_Action_Convert *)
              RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    if (this_00 != (TRIBE_Action_Convert *)0x0) {
      sVar1 = (**(code **)(this_00->_padding_ + 0x18))();
      if (sVar1 == 0x68) {
        TRIBE_Action_Convert::martyrdom(this_00);
      }
    }
  }
  RGE_Static_Object::die_die_die((RGE_Static_Object *)this);
  return;
}

// --------------------------------------------------

// Function: damage
// Address: 004ca7f0
/* WARNING: Variable defined which should be unmapped: temp_hp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Combat_Object::damage(int,struct RGE_Armor_Weapon_Info
   *,float,class RGE_Player *,class RGE_Static_Object *) */

void __thiscall
TRIBE_Combat_Object::damage
          (TRIBE_Combat_Object *this,int param_1,RGE_Armor_Weapon_Info *param_2,float param_3,
          RGE_Player *param_4,RGE_Static_Object *param_5)
{
  float fVar1;
  int iVar2;
  char cVar3;
  float temp_hp;
  
  fVar1 = (float)this->_padding_;
  if ((float)_DAT_00574c88 <= (float)this->_padding_) {
    RGE_Combat_Object::damage((RGE_Combat_Object *)this,param_1,param_2,param_3,param_4,param_5);
    if ((float)this->_padding_ < (float)_DAT_00574c88) {
      iVar2 = this->_padding_;
      cVar3 = (**(code **)(iVar2 + 0x13c))((int)param_5->master_obj->object_group);
      if (cVar3 == '\0') {
        (**(code **)(iVar2 + 0x84))(0,0,1);
      }
    }
    if (fVar1 - (float)this->_padding_ < (float)_DAT_00574c88) {
      this->_padding_ = (int)(fVar1 - _DAT_00574c78);
    }
    if ((0 < *(short *)(this->_padding_ + 0x4a)) && ((float)this->_padding_ < _DAT_00574c78)) {
      (**(code **)(param_4->_padding_ + 0x78))(0x14,0x3f800000,0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: change_ownership
// Address: 004ca8c0
/* protected: virtual void __thiscall TRIBE_Combat_Object::change_ownership(class RGE_Player *) */

void __thiscall TRIBE_Combat_Object::change_ownership(TRIBE_Combat_Object *this,RGE_Player *param_1)
{
  int *piVar1;
  int iVar2;
  
  if (-1 < this->_padding_) {
    piVar1 = &this->_padding_;
    iVar2 = 9;
    do {
      if (*piVar1 != 0) {
        *(char *)(*piVar1 + 5) = (char)param_1->id;
      }
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (*(short *)(this->_padding_ + 0x14) == 1) {
    RGE_Action_Object::change_ownership((RGE_Action_Object *)this,param_1);
    return;
  }
  if (param_1->master_objects[*(short *)(this->_padding_ + 0x10)] != (RGE_Master_Static_Object *)0x0
     ) {
    if ((this->_padding_ & 0x10000) != 0) {
      RGE_Player::unselect_one_object((RGE_Player *)this->_padding_,(RGE_Static_Object *)this);
    }
    RGE_Static_Object::take_attribute_from_owner((RGE_Static_Object *)this);
    (**(code **)(*(int *)this->_padding_ + 0xe0))
              (this,*(undefined1 *)((int)&this->_padding_ + 1),
               *(undefined1 *)((int)&this->_padding_ + 2),this->_padding_);
    iVar2 = (**(code **)(param_1->_padding_ + 0xdc))
                      (this,*(undefined1 *)((int)&this->_padding_ + 1),
                       *(undefined1 *)((int)&this->_padding_ + 2));
    this->_padding_ = iVar2;
    if ((char)this->_padding_ == '\x02') {
      (**(code **)(this->_padding_ + 0xdc))(this->_padding_,0,0xffffffff);
    }
    this->_padding_ = (int)param_1;
    if (this->own_master == '\0') {
      iVar2 = (**(code **)(*(int *)this->_padding_ + 0x1c))();
      this->_padding_ = iVar2;
      this->own_master = '\x01';
    }
    if ((char)this->_padding_ == '\x02') {
      (**(code **)(this->_padding_ + 0xd8))(this->_padding_,0,0xffffffff);
    }
    RGE_Static_Object::give_attribute_to_owner((RGE_Static_Object *)this);
    if ((UnitAIModule *)this->_padding_ != (UnitAIModule *)0x0) {
      UnitAIModule::purgeNotifyQueue
                ((UnitAIModule *)this->_padding_,*(ulong *)(*(int *)(this->_padding_ + 0x3c) + 4));
    }
    (**(code **)(this->_padding_ + 0x148))
              (this->_padding_,this->_padding_,0x20b,(int)param_1->id,0,0);
  }
  return;
}

// --------------------------------------------------

// Function: calc_attack_modifier
// Address: 004caa00
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual float __thiscall TRIBE_Combat_Object::calc_attack_modifier(class
   RGE_Static_Object *) */

float __thiscall
TRIBE_Combat_Object::calc_attack_modifier(TRIBE_Combat_Object *this,RGE_Static_Object *param_1)
{
  int iVar1;
  
  if (*(short *)(this->_padding_ + 0x124) < 0) {
    if ((float)this->_padding_ < param_1->world_z) {
      return _DAT_00574c94;
    }
  }
  else {
    iVar1 = (**(code **)(this->_padding_ + 0x24c))(param_1);
    if (iVar1 != 0) {
      return _DAT_00574c90;
    }
  }
  return _DAT_00574c78;
}

// --------------------------------------------------

// Function: attack
// Address: 004caa50
/* public: virtual unsigned char __thiscall TRIBE_Combat_Object::attack(class RGE_Static_Object
   *,class RGE_Combat_Object *) */

uchar __thiscall
TRIBE_Combat_Object::attack
          (TRIBE_Combat_Object *this,RGE_Static_Object *param_1,RGE_Combat_Object *param_2)
{
  uchar uVar1;
  
  if (((-1 < *(short *)(this->_padding_ + 0x124)) && (param_1 != (RGE_Static_Object *)0x0)) &&
     (0 < param_1->owner->id)) {
                    /* language.dll match for 0x70: "B" */
    (**(code **)(param_1->owner->_padding_ + 0x94))
              (0x70,this->_padding_,this->_padding_,this->_padding_,0);
  }
  uVar1 = RGE_Combat_Object::attack((RGE_Combat_Object *)this,param_1,param_2);
  return uVar1;
}

// --------------------------------------------------

// Function: do_attack
// Address: 004caaa0
// [HELPER] s_C__msdev_work_age1_x1_t_c_obj_cp: "C:\msdev\work\age1_x1\t_c_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall TRIBE_Combat_Object::do_attack(class RGE_Static_Object
   *,class RGE_Combat_Object *,float,float,float) */

uchar __thiscall
TRIBE_Combat_Object::do_attack
          (TRIBE_Combat_Object *this,RGE_Static_Object *param_1,RGE_Combat_Object *param_2,
          float param_3,float param_4,float param_5)
{
  short sVar1;
  int iVar2;
  uchar uVar3;
  int iVar4;
  float10 fVar5;
  
  if (param_1 == (RGE_Static_Object *)0x0) {
    return '\0';
  }
  if ((rge_base_game->quick_build != 0) &&
     ((sVar1 = *(short *)(this->_padding_ + 0x10), sVar1 == 0x7a || (sVar1 == 0x7b)))) {
    (**(code **)(this->_padding_ + 0x148))(this->_padding_,this->_padding_,0x200,600,param_1->id,0);
    (**(code **)(param_1->_padding_ + 0x6c))();
    return '\x01';
  }
  if ((_DAT_00574c98 < *(float *)(this->_padding_ + 0x118)) &&
     (*(float *)(this->_padding_ + 0x114) < _DAT_00574c9c)) {
    iVar2 = this->_padding_;
    (**(code **)(iVar2 + 0x21c))(param_3,param_4,param_5,param_2,param_1);
    (**(code **)(iVar2 + 0x148))(this->_padding_,this->_padding_,0x200,600,param_1->id,0);
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_t_c_obj_cp,0x211);
    if ((iVar4 * 100) / 0x7fff <= (int)*(short *)(this->_padding_ + 0x126)) {
      fVar5 = (float10)(**(code **)(iVar2 + 0xf0))(param_1);
      (**(code **)(param_1->_padding_ + 0x70))
                ((int)*(short *)(this->_padding_ + 0x108),*(undefined4 *)(this->_padding_ + 0x10c),
                 (float)fVar5,this->_padding_,param_2);
    }
    return '\x01';
  }
  uVar3 = RGE_Combat_Object::do_attack
                    ((RGE_Combat_Object *)this,param_1,param_2,param_3,param_4,param_5);
  return uVar3;
}

// --------------------------------------------------

// Function: get_armor
// Address: 004cac10
/* public: virtual void __thiscall TRIBE_Combat_Object::get_armor(short &,short &) */

void __thiscall
TRIBE_Combat_Object::get_armor(TRIBE_Combat_Object *this,short *param_1,short *param_2)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  *param_1 = (ushort)*(byte *)(this->_padding_ + 0x100);
  iVar2 = this->_padding_;
  iVar3 = 0;
  if (0 < *(short *)(iVar2 + 0x102)) {
    do {
      if ((*(short *)(*(int *)(iVar2 + 0x104) + iVar3 * 4) == 4) &&
         (sVar1 = *(short *)(*(int *)(iVar2 + 0x104) + iVar3 * 4 + 2), *param_1 < sVar1)) {
        *param_1 = sVar1;
      }
      iVar2 = this->_padding_;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(iVar2 + 0x102));
  }
  *param_2 = *(short *)(this->_padding_ + 0x13c);
  return;
}

// --------------------------------------------------

// Function: get_pierce_armor
// Address: 004cac80
/* public: virtual void __thiscall TRIBE_Combat_Object::get_pierce_armor(short &,short &) */

void __thiscall
TRIBE_Combat_Object::get_pierce_armor(TRIBE_Combat_Object *this,short *param_1,short *param_2)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  *param_1 = 0;
  iVar2 = this->_padding_;
  if (0 < *(short *)(iVar2 + 0x102)) {
    do {
      if ((*(short *)(*(int *)(iVar2 + 0x104) + iVar3 * 4) == 3) &&
         (sVar1 = *(short *)(*(int *)(iVar2 + 0x104) + iVar3 * 4 + 2), *param_1 < sVar1)) {
        *param_1 = sVar1;
      }
      iVar2 = this->_padding_;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(iVar2 + 0x102));
  }
  *param_2 = *(short *)(this->_padding_ + 0x160);
  return;
}

// --------------------------------------------------

// Function: reposition_artifact
// Address: 004cace0
/* WARNING: Variable defined which should be unmapped: y_pos */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TRIBE_Combat_Object::reposition_artifact(void) */

void __thiscall TRIBE_Combat_Object::reposition_artifact(TRIBE_Combat_Object *this)
{
  int iVar1;
  RGE_Map *this_00;
  bool bVar2;
  uchar uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  float y_pos;
  float x_pos;
  int y1;
  int x2;
  int x1;
  int y2;
  int found_pos;
  int x;
  int map_max_x;
  int map_max_y;
  
  iVar1 = this->_padding_;
  if (iVar1 == 0) {
    y2 = __ftol();
    found_pos = __ftol();
    y1 = this->_padding_;
    x_pos = (float)this->_padding_;
  }
  else {
    y2 = __ftol();
    found_pos = __ftol();
    x_pos = *(float *)(iVar1 + 0x3c);
    y1 = *(int *)(iVar1 + 0x38);
  }
  x1 = y2;
  bVar2 = false;
  this_00 = *(RGE_Map **)(*(int *)(this->_padding_ + 0x3c) + 0x28);
  iVar5 = this_00->map_width + -1;
  iVar6 = this_00->map_height + -1;
  iVar1 = y2;
  x2 = found_pos;
  do {
    for (; iVar1 <= x1; iVar1 = iVar1 + 1) {
      uVar3 = RGE_Map::get_terrain(this_00,(short)iVar1,(short)x2);
      if ((uVar3 != '\x01') && (uVar3 != '\x02')) {
        y1 = (int)((float)iVar1 - _DAT_00574ca0);
        x_pos = (float)x2 - _DAT_00574ca0;
        cVar4 = (**(code **)(*(int *)this->_padding_ + 0x20))
                          (this->_padding_,y1,x_pos,0,1,1,1,0,1,1);
        if (cVar4 != '\0') goto LAB_004cade0;
LAB_004cae4c:
        bVar2 = true;
        break;
      }
LAB_004cade0:
      uVar3 = RGE_Map::get_terrain(this_00,(short)iVar1,(short)found_pos);
      if ((uVar3 != '\x01') && (uVar3 != '\x02')) {
        y1 = (int)((float)iVar1 - _DAT_00574ca0);
        x_pos = (float)found_pos - _DAT_00574ca0;
        cVar4 = (**(code **)(*(int *)this->_padding_ + 0x20))
                          (this->_padding_,y1,x_pos,0,1,1,1,0,1,1);
        if (cVar4 == '\0') goto LAB_004cae4c;
      }
    }
    if (bVar2) goto LAB_004cafd9;
    iVar1 = x2;
    do {
      do {
        iVar1 = iVar1 + 1;
        if (found_pos + -1 < iVar1) goto LAB_004caf3f;
        uVar3 = RGE_Map::get_terrain(this_00,(short)y2,(short)iVar1);
        if ((uVar3 != '\x01') && (uVar3 != '\x02')) {
          y1 = (int)((float)y2 - _DAT_00574ca0);
          x_pos = (float)iVar1 - _DAT_00574ca0;
          cVar4 = (**(code **)(*(int *)this->_padding_ + 0x20))
                            (this->_padding_,y1,x_pos,0,1,1,1,0,1,1);
          if (cVar4 == '\0') goto LAB_004caf37;
        }
        uVar3 = RGE_Map::get_terrain(this_00,(short)x1,(short)iVar1);
      } while ((uVar3 == '\x01') || (uVar3 == '\x02'));
      y1 = (int)((float)x1 - _DAT_00574ca0);
      x_pos = (float)iVar1 - _DAT_00574ca0;
      cVar4 = (**(code **)(*(int *)this->_padding_ + 0x20))(this->_padding_,y1,x_pos,0,0,1,1,0,1,1);
    } while (cVar4 != '\0');
LAB_004caf37:
    bVar2 = true;
LAB_004caf3f:
    if (bVar2) goto LAB_004cafd9;
    if ((((y2 == 0) && (x1 == iVar5)) && (x2 == 0)) && (found_pos == iVar6)) {
      iVar1 = this->_padding_;
      if (iVar1 == 0) {
        y1 = this->_padding_;
        x_pos = (float)this->_padding_;
      }
      else {
        y1 = *(int *)(iVar1 + 0x38);
        x_pos = *(float *)(iVar1 + 0x3c);
      }
LAB_004cafd9:
      RGE_Static_Object::set_location
                ((RGE_Static_Object *)this,(float)y1,x_pos,(float)this->_padding_);
      if (this->_padding_ != 0) {
        (**(code **)(this->_padding_ + 0xd4))();
      }
      iVar1 = this->_padding_;
      (**(code **)(iVar1 + 0x34))(y1,x_pos,this->_padding_);
      (**(code **)(iVar1 + 0x44))(**(undefined4 **)(*(int *)(this->_padding_ + 0x3c) + 0x40));
      (**(code **)(iVar1 + 0x9c))(0,y1,x_pos,this->_padding_);
      this->_padding_ = 0x3f800000;
      return;
    }
    if (0 < y2) {
      y2 = y2 + -1;
    }
    if (0 < x2) {
      x2 = x2 + -1;
    }
    if (x1 < iVar5) {
      x1 = x1 + 1;
    }
    iVar1 = y2;
    if (found_pos < iVar6) {
      found_pos = found_pos + 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: can_debark
// Address: 004cb040
/* public: int __thiscall TRIBE_Combat_Object::can_debark(void) */

int __thiscall TRIBE_Combat_Object::can_debark(TRIBE_Combat_Object *this)
{
  if (*(char *)(this->_padding_ + 0x8f) != '\a') {
    return 0;
  }
  return (uint)(*(short *)(this->_padding_ + 8) != 0);
}

// --------------------------------------------------

// Function: hunt
// Address: 004cb060
/* public: virtual int __thiscall TRIBE_Combat_Object::hunt(int,int) */

int __thiscall TRIBE_Combat_Object::hunt(TRIBE_Combat_Object *this,int param_1,int param_2)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Hunt *this_00;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fbbb;
  *unaff_FS_OFFSET = &local_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb196;
  if (param_2 == 0) {
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 != '\x01') goto LAB_004cb0de;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb0de;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x6e) goto LAB_004cb0de;
  }
  else {
LAB_004cb0de:
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x6e) {
        pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb191;
      }
    }
    iVar1 = this->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb196;
    this_00 = (TRIBE_Action_Hunt *)operator_new(0x44);
    uStack_4 = 0;
    if (this_00 == (TRIBE_Action_Hunt *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Hunt::TRIBE_Action_Hunt
                        (this_00,(RGE_Action_Object *)this,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb196;
    }
    RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb191:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb196:
  *unaff_FS_OFFSET = local_c;
  return (int)pRVar6;
}

// --------------------------------------------------

// Function: convert
// Address: 004cb1b0
/* public: virtual int __thiscall TRIBE_Combat_Object::convert(int,int) */

int __thiscall TRIBE_Combat_Object::convert(TRIBE_Combat_Object *this,int param_1,int param_2)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Convert *this_00;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fbdb;
  *unaff_FS_OFFSET = &local_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb2e6;
  if (param_2 == 0) {
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 != '\x01') goto LAB_004cb22e;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb22e;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x68) goto LAB_004cb22e;
  }
  else {
LAB_004cb22e:
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x68) {
        pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb2e1;
      }
    }
    iVar1 = this->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb2e6;
    this_00 = (TRIBE_Action_Convert *)operator_new(0x48);
    uStack_4 = 0;
    if (this_00 == (TRIBE_Action_Convert *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Convert::TRIBE_Action_Convert
                        (this_00,(RGE_Action_Object *)this,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb2e6;
    }
    RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb2e1:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb2e6:
  *unaff_FS_OFFSET = local_c;
  return (int)pRVar6;
}

// --------------------------------------------------

// Function: heal
// Address: 004cb300
/* public: virtual int __thiscall TRIBE_Combat_Object::heal(int,int) */

int __thiscall TRIBE_Combat_Object::heal(TRIBE_Combat_Object *this,int param_1,int param_2)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Heal *this_00;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fbfb;
  *unaff_FS_OFFSET = &local_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb436;
  if (param_2 == 0) {
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 != '\x01') goto LAB_004cb37e;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb37e;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x69) goto LAB_004cb37e;
  }
  else {
LAB_004cb37e:
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x69) {
        pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb431;
      }
    }
    iVar1 = this->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb436;
    this_00 = (TRIBE_Action_Heal *)operator_new(0x40);
    uStack_4 = 0;
    if (this_00 == (TRIBE_Action_Heal *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Heal::TRIBE_Action_Heal
                        (this_00,(RGE_Action_Object *)this,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb436;
    }
    RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb431:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb436:
  *unaff_FS_OFFSET = local_c;
  return (int)pRVar6;
}

// --------------------------------------------------

// Function: repair
// Address: 004cb450
/* public: virtual int __thiscall TRIBE_Combat_Object::repair(int,int) */

int __thiscall TRIBE_Combat_Object::repair(TRIBE_Combat_Object *this,int param_1,int param_2)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Repair *this_00;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fc1b;
  *unaff_FS_OFFSET = &local_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb5a1;
  if (param_2 == 0) {
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 != '\x01') goto LAB_004cb4ce;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb4ce;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x6a) goto LAB_004cb4ce;
  }
  else {
LAB_004cb4ce:
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x6a) {
        pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb59c;
      }
    }
    iVar1 = *(int *)(*(int *)(this->_padding_ + 0x24) + 0x270);
    if (iVar1 != 0) {
      (**(code **)(this->_padding_ + 0x54))(iVar1);
    }
    iVar1 = this->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb5a1;
    this_00 = (TRIBE_Action_Repair *)operator_new(0x44);
    uStack_4 = 0;
    if (this_00 == (TRIBE_Action_Repair *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Repair::TRIBE_Action_Repair
                        (this_00,(RGE_Action_Object *)this,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb5a1;
    }
    RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb59c:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb5a1:
  *unaff_FS_OFFSET = local_c;
  return (int)pRVar6;
}

// --------------------------------------------------

// Function: build
// Address: 004cb5c0
/* public: virtual int __thiscall TRIBE_Combat_Object::build(int,int) */

int __thiscall TRIBE_Combat_Object::build(TRIBE_Combat_Object *this,int param_1,int param_2)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Build *this_00;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fc3b;
  *unaff_FS_OFFSET = &local_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb6f6;
  if (param_2 == 0) {
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 != '\x01') goto LAB_004cb63e;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb63e;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x65) goto LAB_004cb63e;
  }
  else {
LAB_004cb63e:
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x65) {
        pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb6f1;
      }
    }
    iVar1 = this->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb6f6;
    this_00 = (TRIBE_Action_Build *)operator_new(0x40);
    uStack_4 = 0;
    if (this_00 == (TRIBE_Action_Build *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Build::TRIBE_Action_Build
                        (this_00,(RGE_Action_Object *)this,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb6f6;
    }
    RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb6f1:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb6f6:
  *unaff_FS_OFFSET = local_c;
  return (int)pRVar6;
}

// --------------------------------------------------

// Function: trade
// Address: 004cb710
/* public: virtual int __thiscall TRIBE_Combat_Object::trade(int,int) */

int __thiscall TRIBE_Combat_Object::trade(TRIBE_Combat_Object *this,int param_1,int param_2)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Trade *this_00;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fc5b;
  *unaff_FS_OFFSET = &local_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(this->_padding_ + 0x3c),param_1);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb846;
  if (param_2 == 0) {
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 != '\x01') goto LAB_004cb78e;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb78e;
    pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x6f) goto LAB_004cb78e;
  }
  else {
LAB_004cb78e:
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)this->_padding_);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x6f) {
        pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb841;
      }
    }
    iVar1 = this->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb846;
    this_00 = (TRIBE_Action_Trade *)operator_new(0x48);
    uStack_4 = 0;
    if (this_00 == (TRIBE_Action_Trade *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Trade::TRIBE_Action_Trade
                        (this_00,(RGE_Action_Object *)this,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb846;
    }
    RGE_Action_List::delete_list((RGE_Action_List *)this->_padding_);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb841:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb846:
  *unaff_FS_OFFSET = local_c;
  return (int)pRVar6;
}

// --------------------------------------------------

// Function: keepGatheringWhenObjectIsOut
// Address: 004cb860
/* public: virtual unsigned char __thiscall
   TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(int)const  */

uchar __thiscall
TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(TRIBE_Combat_Object *this,int param_1)
{
  if ((param_1 != 0x32) && (param_1 != 0x2d)) {
    return '\0';
  }
  return '\x01';
}

// --------------------------------------------------

// Function: produceWhenKilledBy
// Address: 004cb880
/* public: virtual unsigned char __thiscall TRIBE_Combat_Object::produceWhenKilledBy(int)const  */

uchar __thiscall TRIBE_Combat_Object::produceWhenKilledBy(TRIBE_Combat_Object *this,int param_1)
{
  short sVar1;
  
  sVar1 = *(short *)(this->_padding_ + 0x14);
  if ((sVar1 != 9) && (sVar1 != 10)) {
    return '\x01';
  }
  return param_1 == 4;
}

// --------------------------------------------------

// Function: useSameZoneDropsite
// Address: 004cb8b0
/* public: virtual unsigned char __thiscall TRIBE_Combat_Object::useSameZoneDropsite(void)const  */

uchar __thiscall TRIBE_Combat_Object::useSameZoneDropsite(TRIBE_Combat_Object *this)
{
  short sVar1;
  
  sVar1 = *(short *)(this->_padding_ + 0x14);
  if ((sVar1 != 0x15) && (sVar1 != 2)) {
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: initUnitAI
// Address: 004cb8d0
/* protected: virtual void __thiscall TRIBE_Combat_Object::initUnitAI(void) */

void __thiscall TRIBE_Combat_Object::initUnitAI(TRIBE_Combat_Object *this)
{
  short sVar1;
  TribeArtifactUnitAIModule *this_00;
  TribeCivilianUnitAIModule *this_01;
  TribePriestUnitAIModule *this_02;
  TribeHuntedAnimalUnitAIModule *pTVar2;
  TribeElephantUnitAIModule *this_03;
  TribeLionUnitAIModule *this_04;
  TribePreditorUnitAIModule *this_05;
  TribeFishingShipUnitAIModule *this_06;
  TribeTradeShipUnitAIModule *this_07;
  TribeTransportShipUnitAIModule *this_08;
  TribeBuildingUnitAIModule *this_09;
  TribeTowerUnitAIModule *this_10;
  TribeSoldierUnitAIModule *this_11;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd0a;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar3 = this->_padding_;
  switch(*(undefined2 *)(iVar3 + 0x14)) {
  case 1:
    if ((*(short *)(iVar3 + 0x10) == 99) || (*(short *)(iVar3 + 0x10) == 10))
    goto switchD_004cb902_caseD_5;
    this_00 = (TribeArtifactUnitAIModule *)operator_new(0x134);
    local_4 = 0;
    if (this_00 != (TribeArtifactUnitAIModule *)0x0) {
      iVar3 = TribeArtifactUnitAIModule::TribeArtifactUnitAIModule
                        (this_00,(RGE_Static_Object *)this,5);
      this->_padding_ = iVar3;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case 2:
    this_07 = (TribeTradeShipUnitAIModule *)operator_new(0x134);
    local_4 = 9;
    if (this_07 != (TribeTradeShipUnitAIModule *)0x0) {
      iVar3 = TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule
                        (this_07,(RGE_Static_Object *)this,10);
      this->_padding_ = iVar3;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case 3:
  case 0x1b:
    sVar1 = *(short *)(iVar3 + 0x10);
    if (((((sVar1 == 0x4f) || (sVar1 == 199)) || (sVar1 == 0x45)) ||
        ((sVar1 == 0x116 || (sVar1 == 0x17f)))) || (sVar1 == 0x17c)) {
      this_10 = (TribeTowerUnitAIModule *)operator_new(0x134);
      local_4 = 0xb;
      if (this_10 != (TribeTowerUnitAIModule *)0x0) {
        iVar3 = TribeTowerUnitAIModule::TribeTowerUnitAIModule(this_10,(RGE_Static_Object *)this,10)
        ;
        this->_padding_ = iVar3;
        *unaff_FS_OFFSET = local_c;
        return;
      }
    }
    else {
      this_09 = (TribeBuildingUnitAIModule *)operator_new(0x134);
      local_4 = 0xc;
      if (this_09 != (TribeBuildingUnitAIModule *)0x0) {
        iVar3 = TribeBuildingUnitAIModule::TribeBuildingUnitAIModule
                          (this_09,(RGE_Static_Object *)this,10);
        this->_padding_ = iVar3;
        *unaff_FS_OFFSET = local_c;
        return;
      }
    }
    break;
  case 4:
    this_01 = (TribeCivilianUnitAIModule *)operator_new(0x134);
    local_4 = 1;
    if (this_01 != (TribeCivilianUnitAIModule *)0x0) {
      iVar3 = TribeCivilianUnitAIModule::TribeCivilianUnitAIModule
                        (this_01,(RGE_Static_Object *)this,10);
      this->_padding_ = iVar3;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case 5:
  case 7:
  case 8:
  case 0xb:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
    goto switchD_004cb902_caseD_5;
  default:
    this_11 = (TribeSoldierUnitAIModule *)operator_new(0x134);
    local_4 = 0xd;
    if (this_11 != (TribeSoldierUnitAIModule *)0x0) {
      iVar3 = TribeSoldierUnitAIModule::TribeSoldierUnitAIModule
                        (this_11,(RGE_Static_Object *)this,10);
      this->_padding_ = iVar3;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case 9:
    pTVar2 = (TribeHuntedAnimalUnitAIModule *)operator_new(0x134);
    local_4 = 3;
    if (pTVar2 != (TribeHuntedAnimalUnitAIModule *)0x0) {
      iVar3 = TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule
                        (pTVar2,(RGE_Static_Object *)this,10);
      this->_padding_ = iVar3;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case 10:
    sVar1 = *(short *)(iVar3 + 0x10);
    if (sVar1 == 0x9d) {
      pTVar2 = (TribeHuntedAnimalUnitAIModule *)operator_new(0x134);
      local_4 = 4;
      if (pTVar2 != (TribeHuntedAnimalUnitAIModule *)0x0) {
        iVar3 = TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule
                          (pTVar2,(RGE_Static_Object *)this,10);
        this->_padding_ = iVar3;
        *unaff_FS_OFFSET = local_c;
        return;
      }
    }
    else if (sVar1 == 0x30) {
      this_03 = (TribeElephantUnitAIModule *)operator_new(0x134);
      local_4 = 5;
      if (this_03 != (TribeElephantUnitAIModule *)0x0) {
        iVar3 = TribeElephantUnitAIModule::TribeElephantUnitAIModule
                          (this_03,(RGE_Static_Object *)this,10);
        this->_padding_ = iVar3;
        *unaff_FS_OFFSET = local_c;
        return;
      }
    }
    else if (sVar1 == 0x7e) {
      this_04 = (TribeLionUnitAIModule *)operator_new(0x134);
      local_4 = 6;
      if (this_04 != (TribeLionUnitAIModule *)0x0) {
        iVar3 = TribeLionUnitAIModule::TribeLionUnitAIModule(this_04,(RGE_Static_Object *)this,10);
        this->_padding_ = iVar3;
        *unaff_FS_OFFSET = local_c;
        return;
      }
    }
    else {
      this_05 = (TribePreditorUnitAIModule *)operator_new(0x134);
      local_4 = 7;
      if (this_05 != (TribePreditorUnitAIModule *)0x0) {
        iVar3 = TribePreditorUnitAIModule::TribePreditorUnitAIModule
                          (this_05,(RGE_Static_Object *)this,10);
        this->_padding_ = iVar3;
        *unaff_FS_OFFSET = local_c;
        return;
      }
    }
    break;
  case 0x12:
    this_02 = (TribePriestUnitAIModule *)operator_new(0x134);
    local_4 = 2;
    if (this_02 != (TribePriestUnitAIModule *)0x0) {
      iVar3 = TribePriestUnitAIModule::TribePriestUnitAIModule(this_02,(RGE_Static_Object *)this,10)
      ;
      this->_padding_ = iVar3;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case 0x14:
    this_08 = (TribeTransportShipUnitAIModule *)operator_new(0x134);
    local_4 = 10;
    if (this_08 != (TribeTransportShipUnitAIModule *)0x0) {
      iVar3 = TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule
                        (this_08,(RGE_Static_Object *)this,10);
      this->_padding_ = iVar3;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case 0x15:
    this_06 = (TribeFishingShipUnitAIModule *)operator_new(0x134);
    local_4 = 8;
    if (this_06 != (TribeFishingShipUnitAIModule *)0x0) {
      iVar3 = TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule
                        (this_06,(RGE_Static_Object *)this,10);
      this->_padding_ = iVar3;
      *unaff_FS_OFFSET = local_c;
      return;
    }
  }
  this->_padding_ = 0;
switchD_004cb902_caseD_5:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: higher_check_for_cliff
// Address: 004cbd40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall TRIBE_Combat_Object::higher_check_for_cliff(class
   RGE_Static_Object *,int,int,float,float,float,float,class RGE_Map *,class RGE_Static_Object
   *,float &,int &) */

int __thiscall
TRIBE_Combat_Object::higher_check_for_cliff
          (TRIBE_Combat_Object *this,RGE_Static_Object *param_1,int param_2,int param_3,
          float param_4,float param_5,float param_6,float param_7,RGE_Map *param_8,
          RGE_Static_Object *param_9,float *param_10,int *param_11)
{
  byte bVar1;
  RGE_Static_Object *pRVar2;
  float10 fVar3;
  uint uVar4;
  int iVar5;
  RGE_Object_Node *pRVar6;
  float10 fVar7;
  
  if ((((param_3 < 0) || (param_8->map_height <= param_3)) || (param_2 < 0)) ||
     ((param_8->map_width <= param_2 ||
      (pRVar6 = param_8->map_row_offset[param_3][param_2].objects.list,
      pRVar6 == (RGE_Object_Node *)0x0)))) {
    return 0;
  }
  do {
    pRVar2 = pRVar6->node;
    if ((pRVar2->master_obj->object_group == 0x22) && (pRVar2 != param_9)) {
      if (*param_10 == -1.0) {
        fVar7 = (float10)fpatan((float10)param_1->world_y - (float10)(float)this->_padding_,
                                (float10)param_1->world_x - (float10)(float)this->_padding_);
        fVar3 = (float10)_DAT_00574c98;
        *param_10 = (float)fVar7;
        if (fVar7 < fVar3) {
          *param_10 = (float)(fVar7 - (float10)_DAT_00574ca4);
        }
      }
      bVar1 = pRVar2->facet;
      uVar4 = (uint)bVar1;
      iVar5 = uVar4 * 0x20;
      iVar5 = lines_intersect(param_4,param_5,param_6,param_7,
                              *(float *)(&DAT_00587268 + iVar5) + param_4,
                              *(float *)(&DAT_0058726c + iVar5) + param_5,
                              *(float *)(&DAT_00587270 + iVar5) + param_6,
                              *(float *)(&DAT_00587274 + iVar5) + param_7);
      param_9 = pRVar2;
      if (iVar5 != 0) {
        if ((((0x18 < bVar1) || (*param_10 < (float)(&TRIBE_Cliff_Higher_Check_Table)[uVar4 * 8]))
            || (*(float *)(&DAT_0058725c + uVar4 * 0x20) < *param_10)) &&
           ((*param_10 < *(float *)(&DAT_00587260 + uVar4 * 0x20) ||
            (*(float *)(&DAT_00587264 + uVar4 * 0x20) < *param_10)))) {
          *param_11 = *param_11 + -1;
          return 1;
        }
        *param_11 = *param_11 + 1;
        return 1;
      }
    }
    pRVar6 = pRVar6->next;
    if (pRVar6 == (RGE_Object_Node *)0x0) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: higher_than_target
// Address: 004cbef0
/* WARNING: Variable defined which should be unmapped: StartY */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall TRIBE_Combat_Object::higher_than_target(class RGE_Static_Object *)
    */

int __thiscall
TRIBE_Combat_Object::higher_than_target(TRIBE_Combat_Object *this,RGE_Static_Object *param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  code *pcVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  bool bVar13;
  float10 extraout_ST0;
  float10 fVar14;
  float10 extraout_ST1;
  float StartY;
  float StartX;
  float XStep;
  float YStep;
  float DestY;
  float DestX;
  int HigherCalc;
  float XTile;
  float YTile;
  float AngleToTarget;
  int NumSteps;
  int PriorX;
  int PriorY;
  int Tile_Dy1;
  int Tile_Dx1;
  int Tile_Dy2;
  int Tile_Dx2;
  uint local_8;
  int local_4;
  
  if (param_1->world_z < (float)this->_padding_) {
    return 1;
  }
  fVar3 = param_1->world_x;
  fVar4 = (float)this->_padding_;
  fVar5 = param_1->world_y;
  fVar6 = (float)this->_padding_;
  if ((fVar3 - fVar4 == _DAT_00574c98) && (fVar5 - fVar6 == _DAT_00574c98)) {
    return 0;
  }
  uVar8 = __ftol();
  local_4 = ((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)) * 2;
  fVar14 = extraout_ST1 / (float10)local_4;
  fVar1 = (float)fVar14;
  fVar2 = (float)(extraout_ST0 / (float10)local_4);
  fVar12 = fVar1;
  if (fVar14 < (float10)_DAT_00574c98) {
    fVar12 = -fVar1;
  }
  PriorX = (int)fVar2;
  if (fVar2 < _DAT_00574c98) {
    PriorX = (int)-fVar2;
  }
  bVar13 = fVar12 <= (float)PriorX;
  if (bVar13) {
    Tile_Dy2 = -1;
    Tile_Dx1 = 0;
  }
  else {
    Tile_Dx1 = -1;
    Tile_Dy2 = 0;
  }
  local_8 = (uint)bVar13;
  Tile_Dx2 = (int)!bVar13;
  PriorY = -999;
  Tile_Dy1 = -999;
  PriorX = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
  NumSteps = -0x40800000;
  XTile = 0.0;
  fVar12 = 0.0;
  YTile = fVar4;
  AngleToTarget = fVar6;
  if (0 < local_4) {
    do {
      YTile = YTile + fVar1;
      AngleToTarget = AngleToTarget + fVar2;
      iVar9 = __ftol();
      iVar10 = __ftol();
      if ((iVar9 != PriorY) || (iVar10 != Tile_Dy1)) {
        pcVar7 = *(code **)(this->_padding_ + 0x248);
        PriorY = iVar9;
        Tile_Dy1 = iVar10;
        iVar11 = (*pcVar7)(param_1,iVar9,iVar10,fVar4,fVar6,fVar3,fVar5,PriorX,0,&NumSteps,&XTile);
        if ((iVar11 == 0) &&
           (iVar11 = (*pcVar7)(param_1,Tile_Dy2 + iVar9,Tile_Dx1 + iVar10,fVar4,fVar6,fVar3,fVar5,
                               PriorX,0,&NumSteps,&XTile), iVar11 == 0)) {
          (*pcVar7)(param_1,local_8 + iVar9,Tile_Dx2 + iVar10,fVar4,fVar6,fVar3,fVar5,PriorX,0,
                    &NumSteps,&XTile);
        }
      }
      local_4 = local_4 + -1;
      fVar12 = XTile;
    } while (local_4 != 0);
  }
  if ((int)fVar12 < 1) {
    fVar12 = 0.0;
  }
  if (0 < (int)fVar12) {
    fVar12 = 1.4013e-45;
  }
  return (uint)(0 < (int)fVar12);
}

// --------------------------------------------------

// Function: area_attack
// Address: 004cc1b0
// [HELPER] s_C__msdev_work_age1_x1_t_c_obj_cp: "C:\msdev\work\age1_x1\t_c_obj.cpp"
/* WARNING: Variable defined which should be unmapped: attack_modifier */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: virtual unsigned char __thiscall
   TRIBE_Combat_Object::area_attack(float,float,float,class RGE_Combat_Object *,class
   RGE_Static_Object *) */

uchar __thiscall
TRIBE_Combat_Object::area_attack
          (TRIBE_Combat_Object *this,float param_1,float param_2,float param_3,
          RGE_Combat_Object *param_4,RGE_Static_Object *param_5)
{
  float fVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  TRIBE_Combat_Object *pTVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  float attack_modifier;
  short x0;
  short x1;
  short local_20;
  float ry;
  int local_10;
  RGE_Map *map;
  float r2;
  
  fVar1 = *(float *)(this->_padding_ + 0x118);
  iVar3 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
  sVar11 = *(short *)(iVar3 + 8);
  sVar2 = *(short *)(iVar3 + 0xc);
  if (fVar1 <= (float)_DAT_00574ca8) {
    return '\0';
  }
  sVar8 = __ftol();
  x1 = sVar8 + -2;
  sVar8 = __ftol();
  sVar9 = __ftol();
  sVar9 = sVar9 + -2;
  sVar10 = __ftol();
  if (x1 < 0) {
    x1 = 0;
  }
  local_20 = sVar8 + 2;
  if ((short)(sVar11 + -1) + 1 < (int)(short)(sVar8 + 2)) {
    local_20 = sVar11;
  }
  if (sVar9 < 0) {
    sVar9 = 0;
  }
  sVar11 = sVar10 + 2;
  if ((short)(sVar2 + -1) + 1 < (int)(short)(sVar10 + 2)) {
    sVar11 = sVar2;
  }
  if (sVar9 < sVar11) {
    ry = (float)(sVar9 * 4);
    map = (RGE_Map *)((int)sVar11 - (int)sVar9);
    do {
      if (x1 < local_20) {
        iVar13 = x1 * 0x18;
        local_10 = (int)local_20 - (int)x1;
        do {
          for (piVar4 = *(int **)(*(int *)((int)ry + *(int *)(iVar3 + 0x8d8c)) + 0x10 + iVar13);
              piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
            pTVar5 = (TRIBE_Combat_Object *)*piVar4;
            if (pTVar5 != (TRIBE_Combat_Object *)param_5) {
              sVar11 = *(short *)(this->_padding_ + 0x10);
              if ((((((sVar11 != 0x2e) && (sVar11 != 0x28)) && (sVar11 != 0x153)) &&
                   (sVar11 != 0x159)) || (pTVar5->_padding_ != this->_padding_)) &&
                 ((pTVar5 != this &&
                  (iVar12 = pTVar5->_padding_,
                  *(byte *)(this->_padding_ + 0x11c) <= *(byte *)(iVar12 + 0x8b))))) {
                fVar6 = (float)pTVar5->_padding_ - param_1;
                _x0 = (float)pTVar5->_padding_ - param_2;
                if (fVar6 < _DAT_00574c98) {
                  fVar6 = -fVar6;
                }
                if (_x0 < _DAT_00574c98) {
                  _x0 = -_x0;
                }
                fVar7 = _DAT_00574c98;
                if (*(float *)(iVar12 + 0x30) < fVar6) {
                  fVar7 = fVar6 - *(float *)(iVar12 + 0x30);
                }
                fVar6 = _DAT_00574c98;
                if (*(float *)(iVar12 + 0x34) < _x0) {
                  fVar6 = _x0 - *(float *)(iVar12 + 0x34);
                }
                if (fVar6 * fVar6 + fVar7 * fVar7 < fVar1 * fVar1) {
                  iVar12 = debug_rand(s_C__msdev_work_age1_x1_t_c_obj_cp,0x653);
                  iVar12 = iVar12 * 100;
                  if ((short)(((short)(iVar12 / 0x7fff) + (short)(iVar12 >> 0x1f)) -
                             (short)((longlong)iVar12 * 0x80010003 >> 0x3f)) <=
                      *(short *)(this->_padding_ + 0x126)) {
                    fVar14 = (float10)(**(code **)(this->_padding_ + 0xf0))(pTVar5);
                    iVar12 = pTVar5->_padding_;
                    (**(code **)(iVar12 + 0x70))
                              ((int)*(short *)(this->_padding_ + 0x108),
                               *(undefined4 *)(this->_padding_ + 0x10c),(float)fVar14,
                               this->_padding_,param_3);
                    if ((float)pTVar5->_padding_ < _DAT_00574c78) {
                      (**(code **)(iVar12 + 0x84))(0,0,1);
                    }
                  }
                }
              }
            }
          }
          iVar13 = iVar13 + 0x18;
          local_10 = local_10 + -1;
        } while (local_10 != 0);
      }
      ry = (float)((int)ry + 4);
      map = (RGE_Map *)((int)&map[-1].unit_manager + 3);
    } while (map != (RGE_Map *)0x0);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: heal
// Address: 004cc4c0
/* protected: virtual unsigned char __thiscall TRIBE_Combat_Object::heal(float) */

uchar __thiscall TRIBE_Combat_Object::heal(TRIBE_Combat_Object *this,float param_1)
{
  short sVar1;
  int iVar2;
  float fVar3;
  uchar uVar4;
  
  iVar2 = this->_padding_;
  sVar1 = *(short *)(iVar2 + 0x14);
  if ((((sVar1 != 2) && (sVar1 != 0x14)) && (sVar1 != 0x15)) && (sVar1 != 0x16)) {
    uVar4 = RGE_Static_Object::heal((RGE_Static_Object *)this,param_1);
    return uVar4;
  }
  fVar3 = (float)(int)*(short *)(iVar2 + 0x26);
  param_1 = (param_1 * fVar3) / (float)(int)*(short *)(iVar2 + 0x15a);
  if (fVar3 < param_1 + (float)this->_padding_) {
    param_1 = fVar3 - (float)this->_padding_;
  }
  uVar4 = TRIBE_Player::pay_obj_cost
                    ((TRIBE_Player *)this->_padding_,*(short *)(iVar2 + 0x10),
                     param_1 / (float)(*(short *)(iVar2 + 0x26) * 2),1);
  if (uVar4 == '\0') {
    return '\x02';
  }
  uVar4 = RGE_Static_Object::heal((RGE_Static_Object *)this,param_1);
  return uVar4;
}

// --------------------------------------------------

// Function: canRepair
// Address: 004cc570
/* protected: virtual int __thiscall TRIBE_Combat_Object::canRepair(void) */

int __thiscall TRIBE_Combat_Object::canRepair(TRIBE_Combat_Object *this)
{
  float fVar1;
  uchar uVar2;
  
  fVar1 = (float)(int)*(short *)(this->_padding_ + 0x26);
  uVar2 = TRIBE_Player::check_obj_cost
                    ((TRIBE_Player *)this->_padding_,*(short *)(this->_padding_ + 0x10),(short *)0x0
                     ,(fVar1 - (float)this->_padding_) / fVar1,0);
  return (uint)(uVar2 != '\0');
}

// --------------------------------------------------

// Function: do_repair
// Address: 004cc5b0
/* public: void __thiscall TRIBE_Combat_Object::do_repair(class RGE_Static_Object *) */

void __thiscall TRIBE_Combat_Object::do_repair(TRIBE_Combat_Object *this,RGE_Static_Object *param_1)
{
  bool bVar1;
  short sVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  RGE_Action *pRVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  RGE_Static_Object *pRVar9;
  
  if ((TRIBE_Combat_Object *)param_1 != this) {
    if (*(short *)(this->_padding_ + 0x10) != 0x9c) {
      (**(code **)(this->_padding_ + 0x54))
                (*(undefined4 *)(*(int *)(this->_padding_ + 0x24) + 0x270));
    }
    iVar4 = *(int *)(this->_padding_ + 0xd8);
    iVar7 = 0;
    iVar8 = (int)*(short *)(iVar4 + 8);
    pRVar9 = param_1;
    if (0 < iVar8) {
      piVar6 = *(int **)(iVar4 + 4);
      do {
        pRVar9 = (RGE_Static_Object *)*piVar6;
        if ((*(short *)((int)&pRVar9->id + 2) == 0x6a) &&
           (((param_1->master_obj->master_type == 'P' &&
             ((*(short *)&pRVar9->master_obj == -1 || (*(short *)&pRVar9->master_obj == 0)))) ||
            (*(short *)&pRVar9->master_obj == param_1->master_obj->object_group)))) break;
        pRVar9 = (RGE_Static_Object *)0x0;
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar7 < iVar8);
    }
    pRVar3 = (RGE_Static_Object *)RGE_Action_List::get_task((RGE_Action_List *)this->_padding_);
    sVar2 = 0;
    bVar1 = false;
    if (((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar9 == pRVar3)) &&
       (iVar4 = RGE_Action_List::action_work
                          ((RGE_Action_List *)this->_padding_,param_1,param_1->world_x,
                           param_1->world_y,param_1->world_z), iVar4 != 0)) {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)this->_padding_);
      sVar2 = (**(code **)(pRVar5->_padding_ + 0x18))();
      bVar1 = true;
    }
    if (!bVar1) {
      if (pRVar9 == (RGE_Static_Object *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)(**(code **)(*(int *)this->_padding_ + 4))
                                  (pRVar9,param_1,param_1->world_x,param_1->world_y,param_1->world_z
                                  );
      }
      if (piVar6 == (int *)0x0) {
        sVar2 = 0;
      }
      else {
        sVar2 = (**(code **)(*piVar6 + 0x18))();
        (**(code **)(this->_padding_ + 0x208))(piVar6);
      }
    }
    if ((UnitAIModule *)this->_padding_ != (UnitAIModule *)0x0) {
      iVar4 = -1;
      iVar7 = -1;
      if (sVar2 == 0x6a) {
        iVar7 = 0x26a;
        iVar4 = 0x2ce;
      }
      UnitAIModule::setCurrentOrder((UnitAIModule *)this->_padding_,iVar4);
      UnitAIModule::setCurrentAction((UnitAIModule *)this->_padding_,iVar7);
      UnitAIModule::setCurrentTarget
                ((UnitAIModule *)this->_padding_,param_1->id,(int)param_1->master_obj->object_group,
                 param_1->world_x,param_1->world_y,param_1->world_z);
      UnitAIModule::setTaskedByPlayer((UnitAIModule *)this->_padding_);
    }
  }
  return;
}

// --------------------------------------------------

