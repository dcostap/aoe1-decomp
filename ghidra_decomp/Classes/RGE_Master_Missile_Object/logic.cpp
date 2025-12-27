// Class: RGE_Master_Missile_Object
// Function: RGE_Master_Missile_Object
// Address: 00451440
/* public: __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(class
   RGE_Master_Missile_Object *,int) */

RGE_Master_Missile_Object * __thiscall
RGE_Master_Missile_Object::RGE_Master_Missile_Object
          (RGE_Master_Missile_Object *this,RGE_Master_Missile_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d8f8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)this,(RGE_Master_Combat_Object *)param_1,0);
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
// Address: 004514a0
/* public: virtual void * __thiscall RGE_Master_Missile_Object::`vector deleting
   destructor'(unsigned int) */

void * __thiscall
RGE_Master_Missile_Object::_vector_deleting_destructor_
          (RGE_Master_Missile_Object *this,uint param_1)
{
  ~RGE_Master_Missile_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Missile_Object
// Address: 004514c0
/* public: __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(int,class RGE_Sprite *
   *,class RGE_Sound * *,int) */

RGE_Master_Missile_Object * __thiscall
RGE_Master_Missile_Object::RGE_Master_Missile_Object
          (RGE_Master_Missile_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d918;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Missile_Object
// Address: 00451530
/* public: __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(struct _iobuf *,class
   RGE_Sprite * *,class RGE_Sound * *,short,int) */

RGE_Master_Missile_Object * __thiscall
RGE_Master_Missile_Object::RGE_Master_Missile_Object
          (RGE_Master_Missile_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d938;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)this,param_1,param_2,param_3,param_4,0);
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
// Address: 004515b0
/* protected: int __thiscall RGE_Master_Missile_Object::setup(class RGE_Master_Missile_Object *) */

int __thiscall
RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object *this,RGE_Master_Missile_Object *param_1)
{
  RGE_Master_Combat_Object::setup
            ((RGE_Master_Combat_Object *)this,(RGE_Master_Combat_Object *)param_1);
  *(undefined1 *)&this->_padding_ = 0x3c;
  this->missile_type = param_1->missile_type;
  this->targetting_type = param_1->targetting_type;
  this->missile_hit_info = param_1->missile_hit_info;
  this->missile_die_info = param_1->missile_die_info;
  this->area_effect_specials = param_1->area_effect_specials;
  this->ballistics_ratio = param_1->ballistics_ratio;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00451620
/* protected: int __thiscall RGE_Master_Missile_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
RGE_Master_Missile_Object::setup
          (RGE_Master_Missile_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object *)this,param_1,param_2,param_3);
  *(undefined1 *)&this->_padding_ = 0x3c;
  rge_read(param_1,&this->missile_type,1);
  rge_read(param_1,&this->targetting_type,1);
  rge_read(param_1,&this->missile_hit_info,1);
  rge_read(param_1,&this->missile_die_info,1);
  rge_read(param_1,&this->area_effect_specials,1);
  rge_read(param_1,&this->ballistics_ratio,4);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 004516c0
// [HELPER] s__hd__hd__hd__hd__hd__f: "%hd %hd %hd %hd %hd %f"
/* WARNING: Variable defined which should be unmapped: temp_missile_type */
/* protected: int __thiscall RGE_Master_Missile_Object::setup(struct _iobuf *,class RGE_Sprite *
   *,class RGE_Sound * *,short) */

int __thiscall
RGE_Master_Missile_Object::setup
          (RGE_Master_Missile_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4)
{
  _iobuf *p_Var1;
  undefined2 in_stack_00000012;
  short temp_missile_type;
  undefined4 uStack_4;
  
  p_Var1 = param_1;
  uStack_4 = this;
  RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object *)this,param_1,param_2,param_3,param_4);
  *(undefined1 *)&this->_padding_ = 1;
  *(undefined1 *)&this->_padding_ = 0x3c;
  fscanf(p_Var1,s__hd__hd__hd__hd__hd__f,(int)&uStack_4 + 2,&param_4,&param_3,&param_2,&param_1,
         &this->ballistics_ratio);
  this->targetting_type = (uchar)param_4;
  this->missile_hit_info = (uchar)param_3;
  this->missile_die_info = (uchar)param_2;
  this->area_effect_specials = (uchar)param_1;
  this->missile_type = uStack_4._2_1_;
  return 1;
}

// --------------------------------------------------

// Function: ~RGE_Master_Missile_Object
// Address: 00451760
/* public: virtual __thiscall RGE_Master_Missile_Object::~RGE_Master_Missile_Object(void) */

void __thiscall
RGE_Master_Missile_Object::~RGE_Master_Missile_Object(RGE_Master_Missile_Object *this)
{
  this->_padding_ = (int)&_vftable_;
  RGE_Master_Combat_Object::~RGE_Master_Combat_Object((RGE_Master_Combat_Object *)this);
  return;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 00451770
/* public: virtual class RGE_Static_Object * __thiscall
   RGE_Master_Missile_Object::make_new_obj(class RGE_Player *,float,float,float) */

RGE_Static_Object * __thiscall
RGE_Master_Missile_Object::make_new_obj
          (RGE_Master_Missile_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  RGE_Static_Object *pRVar1;
  RGE_Missile_Object *this_00;
  float *unaff_FS_OFFSET;
  float local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d95b;
  *unaff_FS_OFFSET = (float)&local_c;
  if ((char)this->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_1->world,(uchar)this->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(this,param_1,param_2,param_3,param_4);
      *unaff_FS_OFFSET = param_3;
      return pRVar1;
    }
  }
  this_00 = (RGE_Missile_Object *)operator_new(0x1c8);
  local_4 = 0;
  if (this_00 != (RGE_Missile_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Missile_Object::RGE_Missile_Object
                       (this_00,(RGE_Master_Combat_Object *)this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 00451840
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Master_Missile_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Missile_Object::make_new_master(RGE_Master_Missile_Object *this)
{
  RGE_Master_Missile_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d97b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Master_Missile_Object *)operator_new(0x154);
  local_4 = 0;
  if (this_00 != (RGE_Master_Missile_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)RGE_Master_Missile_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 004518b0
/* public: virtual void __thiscall RGE_Master_Missile_Object::copy_obj(class
   RGE_Master_Static_Object *) */

void __thiscall
RGE_Master_Missile_Object::copy_obj
          (RGE_Master_Missile_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Master_Combat_Object::copy_obj((RGE_Master_Combat_Object *)this,param_1);
  this->missile_type = param_1[1].map_color;
  this->targetting_type = param_1[1].attack_reaction;
  this->missile_hit_info = param_1[1].convert_terrain_flag;
  this->missile_die_info = param_1[1].damage_sprite_num;
  this->area_effect_specials = *(uchar *)&param_1[1].damage_sprites;
  this->ballistics_ratio = (float)param_1[1].help_string_id;
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 00451910
/* public: virtual void __thiscall RGE_Master_Missile_Object::modify(float,unsigned char) */

void __thiscall
RGE_Master_Missile_Object::modify(RGE_Master_Missile_Object *this,float param_1,uchar param_2)
{
  uchar uVar1;
  
  if (param_2 == '\x13') {
    uVar1 = __ftol();
    this->targetting_type = uVar1;
  }
  RGE_Master_Combat_Object::modify((RGE_Master_Combat_Object *)this,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 00451940
/* public: virtual void __thiscall RGE_Master_Missile_Object::modify_delta(float,unsigned char) */

void __thiscall
RGE_Master_Missile_Object::modify_delta(RGE_Master_Missile_Object *this,float param_1,uchar param_2)
{
  uchar uVar1;
  
  if (param_2 == '\x13') {
    uVar1 = __ftol();
    this->targetting_type = uVar1;
  }
  RGE_Master_Combat_Object::modify_delta((RGE_Master_Combat_Object *)this,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 00451970
/* public: virtual void __thiscall RGE_Master_Missile_Object::modify_percent(float,unsigned char) */

void __thiscall
RGE_Master_Missile_Object::modify_percent
          (RGE_Master_Missile_Object *this,float param_1,uchar param_2)
{
  uchar uVar1;
  
  if (param_2 == '\x13') {
    uVar1 = __ftol();
    this->targetting_type = uVar1;
  }
  RGE_Master_Combat_Object::modify_percent((RGE_Master_Combat_Object *)this,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004519a0
/* public: virtual void __thiscall RGE_Master_Missile_Object::save(int) */

void __thiscall RGE_Master_Missile_Object::save(RGE_Master_Missile_Object *this,int param_1)
{
  RGE_Master_Combat_Object::save((RGE_Master_Combat_Object *)this,param_1);
  rge_write(param_1,&this->missile_type,1);
  rge_write(param_1,&this->targetting_type,1);
  rge_write(param_1,&this->missile_hit_info,1);
  rge_write(param_1,&this->missile_die_info,1);
  rge_write(param_1,&this->area_effect_specials,1);
  rge_write(param_1,&this->ballistics_ratio,4);
  return;
}

// --------------------------------------------------

