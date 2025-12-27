// Class: RGE_Master_Doppleganger_Object
// Function: RGE_Master_Doppleganger_Object
// Address: 004510c0
/* public: __thiscall RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(class
   RGE_Master_Doppleganger_Object *,int) */

RGE_Master_Doppleganger_Object * __thiscall
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object
          (RGE_Master_Doppleganger_Object *this,RGE_Master_Doppleganger_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d858;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)this,(RGE_Master_Animated_Object *)param_1,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_2 != 0) {
    setup(this,param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00451120
/* public: virtual void * __thiscall RGE_Master_Doppleganger_Object::`scalar deleting
   destructor'(unsigned int) */

void * __thiscall
RGE_Master_Doppleganger_Object::_scalar_deleting_destructor_
          (RGE_Master_Doppleganger_Object *this,uint param_1)
{
  ~RGE_Master_Doppleganger_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Doppleganger_Object
// Address: 00451140
/* public: __thiscall RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(int,class
   RGE_Sprite * *,class RGE_Sound * *,int) */

RGE_Master_Doppleganger_Object * __thiscall
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object
          (RGE_Master_Doppleganger_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3
          ,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d878;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Doppleganger_Object
// Address: 004511b0
/* public: __thiscall RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(struct _iobuf
   *,class RGE_Sprite * *,class RGE_Sound * *,short,int) */

RGE_Master_Doppleganger_Object * __thiscall
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object
          (RGE_Master_Doppleganger_Object *this,_iobuf *param_1,RGE_Sprite **param_2,
          RGE_Sound **param_3,short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d898;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)this,param_1,param_2,param_3,param_4,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_5 != 0) {
    setup(this,param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 00451230
/* protected: int __thiscall RGE_Master_Doppleganger_Object::setup(class
   RGE_Master_Doppleganger_Object *) */

int __thiscall
RGE_Master_Doppleganger_Object::setup
          (RGE_Master_Doppleganger_Object *this,RGE_Master_Doppleganger_Object *param_1)
{
  RGE_Master_Animated_Object::setup
            ((RGE_Master_Animated_Object *)this,(RGE_Master_Animated_Object *)param_1);
  this->field_0x4 = 0x19;
  this->field_0x65 = 3;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00451250
/* protected: int __thiscall RGE_Master_Doppleganger_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
RGE_Master_Doppleganger_Object::setup
          (RGE_Master_Doppleganger_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3
          )
{
  RGE_Master_Animated_Object::setup((RGE_Master_Animated_Object *)this,param_1,param_2,param_3);
  this->field_0x4 = 0x19;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00451280
/* protected: int __thiscall RGE_Master_Doppleganger_Object::setup(struct _iobuf *,class RGE_Sprite
   * *,class RGE_Sound * *,short) */

int __thiscall
RGE_Master_Doppleganger_Object::setup
          (RGE_Master_Doppleganger_Object *this,_iobuf *param_1,RGE_Sprite **param_2,
          RGE_Sound **param_3,short param_4)
{
  RGE_Master_Animated_Object::setup
            ((RGE_Master_Animated_Object *)this,param_1,param_2,param_3,param_4);
  this->field_0x4 = 0x19;
  this->field_0xa4 = 1;
  return 1;
}

// --------------------------------------------------

// Function: ~RGE_Master_Doppleganger_Object
// Address: 004512c0
/* public: virtual __thiscall RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object(void)
    */

void __thiscall
RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object
          (RGE_Master_Doppleganger_Object *this)
{
  *(undefined ***)this = &_vftable_;
  RGE_Master_Animated_Object::~RGE_Master_Animated_Object((RGE_Master_Animated_Object *)this);
  return;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 004512d0
/* public: virtual class RGE_Static_Object * __thiscall
   RGE_Master_Doppleganger_Object::make_new_obj(class RGE_Player *,float,float,float,class
   RGE_Static_Object *) */

RGE_Static_Object * __thiscall
RGE_Master_Doppleganger_Object::make_new_obj
          (RGE_Master_Doppleganger_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4,RGE_Static_Object *param_5)
{
  RGE_Static_Object *pRVar1;
  RGE_Doppleganger_Object *this_00;
  float *unaff_FS_OFFSET;
  float local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d8bb;
  *unaff_FS_OFFSET = (float)&local_c;
  if (this->field_0xa4 != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_1->world,this->field_0x4);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 0x1ec))(this,param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = param_3;
      return pRVar1;
    }
  }
  this_00 = (RGE_Doppleganger_Object *)operator_new(0xb0);
  local_4 = 0;
  if (this_00 != (RGE_Doppleganger_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Doppleganger_Object::RGE_Doppleganger_Object
                       (this_00,this,param_1,param_2,param_3,param_4,1,param_5);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 004513b0
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Master_Doppleganger_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Doppleganger_Object::make_new_master(RGE_Master_Doppleganger_Object *this)
{
  RGE_Master_Doppleganger_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d8db;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Master_Doppleganger_Object *)operator_new(0xbc);
  local_4 = 0;
  if (this_00 != (RGE_Master_Doppleganger_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)RGE_Master_Doppleganger_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 00451420
/* public: virtual void __thiscall RGE_Master_Doppleganger_Object::copy_obj(class
   RGE_Master_Static_Object *) */

void __thiscall
RGE_Master_Doppleganger_Object::copy_obj
          (RGE_Master_Doppleganger_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Master_Animated_Object::copy_obj((RGE_Master_Animated_Object *)this,param_1);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00451430
/* public: virtual void __thiscall RGE_Master_Doppleganger_Object::save(int) */

void __thiscall
RGE_Master_Doppleganger_Object::save(RGE_Master_Doppleganger_Object *this,int param_1)
{
  RGE_Master_Animated_Object::save((RGE_Master_Animated_Object *)this,param_1);
  return;
}

// --------------------------------------------------

