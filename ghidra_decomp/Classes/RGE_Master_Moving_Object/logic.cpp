// Class: RGE_Master_Moving_Object
// Function: RGE_Master_Moving_Object
// Address: 00451a20
/* public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(class
   RGE_Master_Moving_Object *,int) */

RGE_Master_Moving_Object * __thiscall
RGE_Master_Moving_Object::RGE_Master_Moving_Object
          (RGE_Master_Moving_Object *this,RGE_Master_Moving_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d998;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)this,(RGE_Master_Animated_Object *)param_1,0);
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
// Address: 00451a80
/* public: virtual void * __thiscall RGE_Master_Moving_Object::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
RGE_Master_Moving_Object::_vector_deleting_destructor_(RGE_Master_Moving_Object *this,uint param_1)
{
  ~RGE_Master_Moving_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Moving_Object
// Address: 00451aa0
/* public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(int,class RGE_Sprite *
   *,class RGE_Sound * *,int) */

RGE_Master_Moving_Object * __thiscall
RGE_Master_Moving_Object::RGE_Master_Moving_Object
          (RGE_Master_Moving_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d9b8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Moving_Object
// Address: 00451b10
/* public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(struct _iobuf *,class
   RGE_Sprite * *,class RGE_Sound * *,short,int) */

RGE_Master_Moving_Object * __thiscall
RGE_Master_Moving_Object::RGE_Master_Moving_Object
          (RGE_Master_Moving_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d9d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)this,param_1,param_2,param_3,param_4,0);
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
// Address: 00451b90
/* protected: int __thiscall RGE_Master_Moving_Object::setup(class RGE_Master_Moving_Object *) */

int __thiscall
RGE_Master_Moving_Object::setup(RGE_Master_Moving_Object *this,RGE_Master_Moving_Object *param_1)
{
  RGE_Master_Animated_Object::setup
            ((RGE_Master_Animated_Object *)this,(RGE_Master_Animated_Object *)param_1);
  *(undefined1 *)&this->_padding_ = 0x1e;
  this->move_sprite = param_1->move_sprite;
  this->run_sprite = param_1->run_sprite;
  this->turn_speed = param_1->turn_speed;
  this->size_class = param_1->size_class;
  this->obj_trail_id = param_1->obj_trail_id;
  this->obj_trail_options = param_1->obj_trail_options;
  this->obj_trail_spacing = param_1->obj_trail_spacing;
  this->move_algorithem = param_1->move_algorithem;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00451c10
/* protected: int __thiscall RGE_Master_Moving_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
RGE_Master_Moving_Object::setup
          (RGE_Master_Moving_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  RGE_Sprite **ppRVar1;
  RGE_Sprite *pRVar2;
  
  ppRVar1 = param_2;
  RGE_Master_Animated_Object::setup((RGE_Master_Animated_Object *)this,param_1,param_2,param_3);
  *(undefined1 *)&this->_padding_ = 0x1e;
  rge_read(param_1,&param_3,2);
  rge_read(param_1,&param_2,2);
  rge_read(param_1,&this->turn_speed,4);
  rge_read(param_1,&this->size_class,1);
  rge_read(param_1,&this->obj_trail_id,2);
  rge_read(param_1,&this->obj_trail_options,1);
  rge_read(param_1,&this->obj_trail_spacing,4);
  rge_read(param_1,&this->move_algorithem,1);
  if ((short)param_3 < 0) {
    pRVar2 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar2 = ppRVar1[(short)param_3];
  }
  this->move_sprite = pRVar2;
  if (-1 < (short)param_2) {
    this->run_sprite = ppRVar1[(short)param_2];
    return 1;
  }
  this->run_sprite = (RGE_Sprite *)0x0;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00451d10
// [HELPER] s__hd__hd__f__hd__hd__hd__f__hd: "%hd %hd %f %hd %hd %hd %f %hd"
/* WARNING: Variable defined which should be unmapped: temp_run_sprite */
/* protected: int __thiscall RGE_Master_Moving_Object::setup(struct _iobuf *,class RGE_Sprite *
   *,class RGE_Sound * *,short) */

int __thiscall
RGE_Master_Moving_Object::setup
          (RGE_Master_Moving_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4)
{
  _iobuf *p_Var1;
  RGE_Sprite **ppRVar2;
  RGE_Sprite *pRVar3;
  undefined2 in_stack_00000012;
  short temp_run_sprite;
  undefined4 uStack_4;
  
  ppRVar2 = param_2;
  p_Var1 = param_1;
  uStack_4 = this;
  RGE_Master_Animated_Object::setup
            ((RGE_Master_Animated_Object *)this,param_1,param_2,param_3,param_4);
  *(undefined1 *)&this->_padding_ = 0x1e;
  fscanf(p_Var1,s__hd__hd__f__hd__hd__hd__f__hd,&param_1,(int)&uStack_4 + 2,&this->turn_speed,
         &param_4,&this->obj_trail_id,&param_2,&this->obj_trail_spacing,&param_3);
  this->obj_trail_options = (uchar)param_2;
  this->size_class = (uchar)param_4;
  this->move_algorithem = (uchar)param_3;
  if ((short)param_1 < 0) {
    pRVar3 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar3 = ppRVar2[(short)param_1];
  }
  this->move_sprite = pRVar3;
  if (-1 < (int)uStack_4) {
    this->run_sprite = ppRVar2[uStack_4._2_2_];
    return 1;
  }
  this->run_sprite = (RGE_Sprite *)0x0;
  return 1;
}

// --------------------------------------------------

// Function: ~RGE_Master_Moving_Object
// Address: 00451de0
/* public: virtual __thiscall RGE_Master_Moving_Object::~RGE_Master_Moving_Object(void) */

void __thiscall RGE_Master_Moving_Object::~RGE_Master_Moving_Object(RGE_Master_Moving_Object *this)
{
  this->_padding_ = (int)&_vftable_;
  RGE_Master_Animated_Object::~RGE_Master_Animated_Object((RGE_Master_Animated_Object *)this);
  return;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 00451df0
/* public: virtual class RGE_Static_Object * __thiscall RGE_Master_Moving_Object::make_new_obj(class
   RGE_Player *,float,float,float) */

RGE_Static_Object * __thiscall
RGE_Master_Moving_Object::make_new_obj
          (RGE_Master_Moving_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  RGE_Static_Object *pRVar1;
  RGE_Moving_Object *this_00;
  float *unaff_FS_OFFSET;
  float local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d9fb;
  *unaff_FS_OFFSET = (float)&local_c;
  if ((char)this->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_1->world,(uchar)this->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(this,param_1,param_2,param_3,param_4);
      *unaff_FS_OFFSET = param_3;
      return pRVar1;
    }
  }
  this_00 = (RGE_Moving_Object *)operator_new(0x180);
  local_4 = 0;
  if (this_00 != (RGE_Moving_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Moving_Object::RGE_Moving_Object(this_00,this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 00451ec0
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Master_Moving_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Moving_Object::make_new_master(RGE_Master_Moving_Object *this)
{
  RGE_Master_Moving_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055da1b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Master_Moving_Object *)operator_new(0xd8);
  local_4 = 0;
  if (this_00 != (RGE_Master_Moving_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)RGE_Master_Moving_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 00451f30
/* public: virtual void __thiscall RGE_Master_Moving_Object::copy_obj(class RGE_Master_Static_Object
   *) */

void __thiscall
RGE_Master_Moving_Object::copy_obj(RGE_Master_Moving_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Master_Animated_Object::copy_obj((RGE_Master_Animated_Object *)this,param_1);
  this->move_sprite = *(RGE_Sprite **)&param_1[1].master_type;
  this->run_sprite = (RGE_Sprite *)param_1[1].name;
  this->turn_speed = *(float *)&param_1[1].string_id;
  this->size_class = (uchar)param_1[1].id;
  this->obj_trail_id = param_1[1].copy_id;
  this->obj_trail_options = (uchar)param_1[1].object_group;
  this->obj_trail_spacing = (float)param_1[1].sprite;
  this->move_algorithem = *(uchar *)&param_1[1].death_sprite;
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 00451fb0
/* public: virtual void __thiscall RGE_Master_Moving_Object::modify(float,unsigned char) */

void __thiscall
RGE_Master_Moving_Object::modify(RGE_Master_Moving_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\x06') {
    RGE_Master_Animated_Object::modify((RGE_Master_Animated_Object *)this,param_1,param_2);
    return;
  }
  this->turn_speed = param_1;
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 00451fe0
/* public: virtual void __thiscall RGE_Master_Moving_Object::modify_delta(float,unsigned char) */

void __thiscall
RGE_Master_Moving_Object::modify_delta(RGE_Master_Moving_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\x06') {
    RGE_Master_Animated_Object::modify_delta((RGE_Master_Animated_Object *)this,param_1,param_2);
    return;
  }
  this->turn_speed = param_1 + this->turn_speed;
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 00452010
/* public: virtual void __thiscall RGE_Master_Moving_Object::modify_percent(float,unsigned char) */

void __thiscall
RGE_Master_Moving_Object::modify_percent(RGE_Master_Moving_Object *this,float param_1,uchar param_2)
{
  if (param_2 != '\x06') {
    RGE_Master_Animated_Object::modify_percent((RGE_Master_Animated_Object *)this,param_1,param_2);
    return;
  }
  this->turn_speed = param_1 * this->turn_speed;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00452040
/* WARNING: Variable defined which should be unmapped: temp_move_sprite */
/* public: virtual void __thiscall RGE_Master_Moving_Object::save(int) */

void __thiscall RGE_Master_Moving_Object::save(RGE_Master_Moving_Object *this,int param_1)
{
  RGE_Sprite *pRVar1;
  short temp_move_sprite;
  short temp_run_sprite;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pRVar1 = this->move_sprite;
  if (pRVar1 == (RGE_Sprite *)0x0) {
    _temp_run_sprite = 0xffffffff;
  }
  else {
    _temp_run_sprite = CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id);
  }
  if (this->run_sprite != (RGE_Sprite *)0x0) {
    local_4 = CONCAT22(0xffff,this->run_sprite->id);
  }
  RGE_Master_Animated_Object::save((RGE_Master_Animated_Object *)this,param_1);
  rge_write(param_1,&temp_run_sprite,2);
  rge_write(param_1,&local_4,2);
  rge_write(param_1,&this->turn_speed,4);
  rge_write(param_1,&this->size_class,1);
  rge_write(param_1,&this->obj_trail_id,2);
  rge_write(param_1,&this->obj_trail_options,1);
  rge_write(param_1,&this->obj_trail_spacing,4);
  rge_write(param_1,&this->move_algorithem,1);
  return;
}

// --------------------------------------------------

