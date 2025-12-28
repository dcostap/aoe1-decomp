// Class: RGE_Master_Animated_Object
// Size:  0xBC
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] copy_obj
// [02] modify
// [03] modify_delta
// [04] modify_percent
// [05] save
// [06] make_new_obj
// [07] make_new_master
// [08] check_placement
// [09] alignment
// [10] calc_base_damage_ability
// [11] play_command_sound
// [12] play_move_sound
// [13] draw
// [14] `vector_deleting_destructor'
// [15] copy_obj
// [16] modify
// [17] modify_delta
// [18] modify_percent
// [19] save
// [20] make_new_obj
// [21] make_new_master
// [22] check_placement
// [23] alignment
// [24] calc_base_damage_ability
// [25] play_command_sound
// [26] play_move_sound
// [27] draw
// [28] create_task_list
//
// Member Layout:
// [0x0B8] float speed
// ----------------------------------------------------------------

// Function: RGE_Master_Animated_Object
// Address: 0044f9c0
/* public: __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(class
   RGE_Master_Animated_Object *,int) */

RGE_Master_Animated_Object * __thiscall
RGE_Master_Animated_Object::RGE_Master_Animated_Object
          (RGE_Master_Animated_Object *this,RGE_Master_Animated_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d718;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)this,(RGE_Master_Static_Object *)param_1,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_2 != 0) {
    setup(this,param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0044fa20
/* public: virtual void * __thiscall RGE_Master_Animated_Object::`vector deleting
   destructor'(unsigned int) */

void * __thiscall
RGE_Master_Animated_Object::_vector_deleting_destructor_
          (RGE_Master_Animated_Object *this,uint param_1)
{
  ~RGE_Master_Animated_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Animated_Object
// Address: 0044fa40
/* public: __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(int,class RGE_Sprite *
   *,class RGE_Sound * *,int) */

RGE_Master_Animated_Object * __thiscall
RGE_Master_Animated_Object::RGE_Master_Animated_Object
          (RGE_Master_Animated_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d738;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Animated_Object
// Address: 0044fab0
/* public: __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(struct _iobuf *,class
   RGE_Sprite * *,class RGE_Sound * *,short,int) */

RGE_Master_Animated_Object * __thiscall
RGE_Master_Animated_Object::RGE_Master_Animated_Object
          (RGE_Master_Animated_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3
          ,short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d758;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)this,param_1,param_2,param_3,param_4,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_5 != 0) {
    setup(this,param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 0044fb30
/* protected: int __thiscall RGE_Master_Animated_Object::setup(class RGE_Master_Animated_Object *)
    */

int __thiscall
RGE_Master_Animated_Object::setup
          (RGE_Master_Animated_Object *this,RGE_Master_Animated_Object *param_1)
{
  RGE_Master_Static_Object::setup
            ((RGE_Master_Static_Object *)this,(RGE_Master_Static_Object *)param_1);
  *(undefined1 *)&this->_padding_ = 0x14;
  this->speed = param_1->speed;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0044fb60
/* protected: int __thiscall RGE_Master_Animated_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
RGE_Master_Animated_Object::setup
          (RGE_Master_Animated_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  RGE_Master_Static_Object::setup((RGE_Master_Static_Object *)this,param_1,param_2,param_3);
  *(undefined1 *)&this->_padding_ = 0x14;
  rge_read(param_1,&this->speed,4);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0044fba0
// [HELPER] s__f: "%f"
/* protected: int __thiscall RGE_Master_Animated_Object::setup(struct _iobuf *,class RGE_Sprite *
   *,class RGE_Sound * *,short) */

int __thiscall
RGE_Master_Animated_Object::setup
          (RGE_Master_Animated_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3
          ,short param_4)
{
  RGE_Master_Static_Object::setup((RGE_Master_Static_Object *)this,param_1,param_2,param_3,param_4);
  *(undefined1 *)&this->_padding_ = 0x14;
  fscanf(param_1,s__f,&this->speed);
  return 1;
}

// --------------------------------------------------

// Function: ~RGE_Master_Animated_Object
// Address: 0044fbf0
/* public: virtual __thiscall RGE_Master_Animated_Object::~RGE_Master_Animated_Object(void) */

void __thiscall
RGE_Master_Animated_Object::~RGE_Master_Animated_Object(RGE_Master_Animated_Object *this)
{
  this->_padding_ = (int)&_vftable_;
  RGE_Master_Static_Object::~RGE_Master_Static_Object((RGE_Master_Static_Object *)this);
  return;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 0044fc00
/* public: virtual class RGE_Static_Object * __thiscall
   RGE_Master_Animated_Object::make_new_obj(class RGE_Player *,float,float,float) */

RGE_Static_Object * __thiscall
RGE_Master_Animated_Object::make_new_obj
          (RGE_Master_Animated_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  RGE_Static_Object *pRVar1;
  RGE_Animated_Object *this_00;
  float *unaff_FS_OFFSET;
  float local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d77b;
  *unaff_FS_OFFSET = (float)&local_c;
  if ((char)this->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_1->world,(uchar)this->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(this,param_1,param_2,param_3,param_4);
      *unaff_FS_OFFSET = param_3;
      return pRVar1;
    }
  }
  this_00 = (RGE_Animated_Object *)operator_new(0x8c);
  local_4 = 0;
  if (this_00 != (RGE_Animated_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Animated_Object::RGE_Animated_Object
                       (this_00,this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 0044fcd0
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Master_Animated_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Animated_Object::make_new_master(RGE_Master_Animated_Object *this)
{
  RGE_Master_Animated_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d79b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Master_Animated_Object *)operator_new(0xbc);
  local_4 = 0;
  if (this_00 != (RGE_Master_Animated_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)RGE_Master_Animated_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 0044fd40
/* public: virtual void __thiscall RGE_Master_Animated_Object::copy_obj(class
   RGE_Master_Static_Object *) */

void __thiscall
RGE_Master_Animated_Object::copy_obj
          (RGE_Master_Animated_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Master_Static_Object::copy_obj((RGE_Master_Static_Object *)this,param_1);
  this->speed = (float)param_1[1]._padding_;
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 0044fd60
/* public: virtual void __thiscall RGE_Master_Animated_Object::modify(float,unsigned char) */

void __thiscall
RGE_Master_Animated_Object::modify(RGE_Master_Animated_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\x05') {
    RGE_Master_Static_Object::modify((RGE_Master_Static_Object *)this,param_1,param_2);
    return;
  }
  this->speed = param_1;
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 0044fd90
/* public: virtual void __thiscall RGE_Master_Animated_Object::modify_delta(float,unsigned char) */

void __thiscall
RGE_Master_Animated_Object::modify_delta
          (RGE_Master_Animated_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\x05') {
    RGE_Master_Static_Object::modify_delta((RGE_Master_Static_Object *)this,param_1,param_2);
    return;
  }
  this->speed = param_1 + this->speed;
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 0044fdc0
/* public: virtual void __thiscall RGE_Master_Animated_Object::modify_percent(float,unsigned char)
    */

void __thiscall
RGE_Master_Animated_Object::modify_percent
          (RGE_Master_Animated_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\x05') {
    RGE_Master_Static_Object::modify_percent((RGE_Master_Static_Object *)this,param_1,param_2);
    return;
  }
  this->speed = param_1 * this->speed;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0044fdf0
/* public: virtual void __thiscall RGE_Master_Animated_Object::save(int) */

void __thiscall RGE_Master_Animated_Object::save(RGE_Master_Animated_Object *this,int param_1)
{
  RGE_Master_Static_Object::save((RGE_Master_Static_Object *)this,param_1);
  rge_write(param_1,&this->speed,4);
  return;
}

// --------------------------------------------------

