// Class: TRIBE_Master_Building_Object
// Function: TRIBE_Master_Building_Object
// Address: 0050e040
/* public: __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(class
   TRIBE_Master_Building_Object *,int) */

TRIBE_Master_Building_Object * __thiscall
TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
          (TRIBE_Master_Building_Object *this,TRIBE_Master_Building_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560e28;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
            ((TRIBE_Master_Combat_Object *)this,(TRIBE_Master_Combat_Object *)param_1,0);
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
// Address: 0050e0a0
/* public: virtual void * __thiscall TRIBE_Master_Building_Object::`vector deleting
   destructor'(unsigned int) */

void * __thiscall
TRIBE_Master_Building_Object::_vector_deleting_destructor_
          (TRIBE_Master_Building_Object *this,uint param_1)
{
  ~TRIBE_Master_Building_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Master_Building_Object
// Address: 0050e0c0
/* public: __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(int,class
   RGE_Sprite * *,class RGE_Sound * *,int) */

TRIBE_Master_Building_Object * __thiscall
TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
          (TRIBE_Master_Building_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560e48;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
            ((TRIBE_Master_Combat_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Master_Building_Object
// Address: 0050e130
/* public: __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(struct _iobuf
   *,class RGE_Sprite * *,class RGE_Sound * *,short,int) */

TRIBE_Master_Building_Object * __thiscall
TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
          (TRIBE_Master_Building_Object *this,_iobuf *param_1,RGE_Sprite **param_2,
          RGE_Sound **param_3,short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560e68;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
            ((TRIBE_Master_Combat_Object *)this,param_1,param_2,param_3,param_4,0);
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
// Address: 0050e1b0
/* protected: int __thiscall TRIBE_Master_Building_Object::setup(class TRIBE_Master_Building_Object
   *) */

int __thiscall
TRIBE_Master_Building_Object::setup
          (TRIBE_Master_Building_Object *this,TRIBE_Master_Building_Object *param_1)
{
  TRIBE_Master_Combat_Object::setup
            ((TRIBE_Master_Combat_Object *)this,(TRIBE_Master_Combat_Object *)param_1);
  *(undefined1 *)&this->_padding_ = 0x50;
  this->construction_sprite = param_1->construction_sprite;
  this->building_connect_flag = param_1->building_connect_flag;
  this->building_facet = param_1->building_facet;
  this->build_and_go_away = param_1->build_and_go_away;
  this->on_build_make_obj = param_1->on_build_make_obj;
  this->on_build_make_tile = param_1->on_build_make_tile;
  this->on_build_make_overlay = param_1->on_build_make_overlay;
  this->on_build_make_tech = param_1->on_build_make_tech;
  this->construction_sound = param_1->construction_sound;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0050e250
/* protected: int __thiscall TRIBE_Master_Building_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
TRIBE_Master_Building_Object::setup
          (TRIBE_Master_Building_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  RGE_Sprite **ppRVar1;
  RGE_Sound **ppRVar2;
  RGE_Sprite *pRVar3;
  
  ppRVar2 = param_3;
  ppRVar1 = param_2;
  TRIBE_Master_Combat_Object::setup((TRIBE_Master_Combat_Object *)this,param_1,param_2,param_3);
  *(undefined1 *)&this->_padding_ = 0x50;
  rge_read(param_1,&param_3,2);
  rge_read(param_1,&this->building_connect_flag,1);
  rge_read(param_1,&this->building_facet,2);
  rge_read(param_1,&this->build_and_go_away,1);
  rge_read(param_1,&this->on_build_make_obj,2);
  rge_read(param_1,&this->on_build_make_tile,2);
  rge_read(param_1,&this->on_build_make_overlay,2);
  rge_read(param_1,&this->on_build_make_tech,2);
  rge_read(param_1,&param_2,2);
  if ((short)param_3 < 0) {
    pRVar3 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar3 = ppRVar1[(short)param_3];
  }
  this->construction_sprite = pRVar3;
  if (-1 < (short)param_2) {
    this->construction_sound = ppRVar2[(short)param_2];
    return 1;
  }
  this->construction_sound = (RGE_Sound *)0x0;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0050e360
// [HELPER] s__hd__hd__hd__hd__hd__hd__hd__hd_: "%hd %hd %hd %hd %hd %hd %hd %hd %hd"
/* protected: int __thiscall TRIBE_Master_Building_Object::setup(struct _iobuf *,class RGE_Sprite *
   *,class RGE_Sound * *,short) */

int __thiscall
TRIBE_Master_Building_Object::setup
          (TRIBE_Master_Building_Object *this,_iobuf *param_1,RGE_Sprite **param_2,
          RGE_Sound **param_3,short param_4)
{
  _iobuf *p_Var1;
  RGE_Sprite **ppRVar2;
  RGE_Sound **ppRVar3;
  RGE_Sprite *pRVar4;
  undefined2 in_stack_00000012;
  
  ppRVar3 = param_3;
  ppRVar2 = param_2;
  p_Var1 = param_1;
  TRIBE_Master_Combat_Object::setup
            ((TRIBE_Master_Combat_Object *)this,param_1,param_2,param_3,param_4);
  *(undefined1 *)&this->_padding_ = 0x50;
  fscanf(p_Var1,s__hd__hd__hd__hd__hd__hd__hd__hd_,&param_2,&param_4,&this->building_facet,&param_3,
         &this->on_build_make_obj,&this->on_build_make_tile,&this->on_build_make_overlay,
         &this->on_build_make_tech,&param_1);
  this->building_connect_flag = (uchar)param_4;
  this->build_and_go_away = (uchar)param_3;
  if ((short)param_2 < 0) {
    pRVar4 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar4 = ppRVar2[(short)param_2];
  }
  this->construction_sprite = pRVar4;
  if (-1 < (short)param_1) {
    this->construction_sound = ppRVar3[(short)param_1];
    return 1;
  }
  this->construction_sound = (RGE_Sound *)0x0;
  return 1;
}

// --------------------------------------------------

// Function: ~TRIBE_Master_Building_Object
// Address: 0050e430
/* public: virtual __thiscall TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object(void) */

void __thiscall
TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object(TRIBE_Master_Building_Object *this)
{
  this->_padding_ = (int)&_vftable_;
  TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object((TRIBE_Master_Combat_Object *)this);
  return;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 0050e440
/* public: virtual void __thiscall TRIBE_Master_Building_Object::copy_obj(class
   RGE_Master_Static_Object *) */

void __thiscall
TRIBE_Master_Building_Object::copy_obj
          (TRIBE_Master_Building_Object *this,RGE_Master_Static_Object *param_1)
{
  TRIBE_Master_Combat_Object::copy_obj((TRIBE_Master_Combat_Object *)this,param_1);
  this->construction_sprite = (RGE_Sprite *)param_1[1].outline_radius_y;
  this->construction_sound = (RGE_Sound *)param_1[1].outline_radius_x;
  this->building_connect_flag = *(uchar *)&param_1[1].outline_radius_z;
  this->building_facet = *(short *)((int)&param_1[1].outline_radius_z + 2);
  this->build_and_go_away = (uchar)param_1[2]._padding_;
  this->on_build_make_obj = *(short *)((int)&param_1[2]._padding_ + 2);
  this->on_build_make_tile = *(short *)&param_1[2].master_type;
  this->on_build_make_overlay = *(short *)&param_1[2].field_0x6;
  this->on_build_make_tech = *(short *)&param_1[2].name;
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 0050e4d0
/* public: virtual void __thiscall TRIBE_Master_Building_Object::modify(float,unsigned char) */

void __thiscall
TRIBE_Master_Building_Object::modify(TRIBE_Master_Building_Object *this,float param_1,uchar param_2)
{
  short sVar1;
  
  if (param_2 != '\x11') {
    TRIBE_Master_Combat_Object::modify((TRIBE_Master_Combat_Object *)this,param_1,param_2);
    return;
  }
  sVar1 = __ftol();
  this->building_facet = sVar1;
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 0050e500
/* public: virtual void __thiscall TRIBE_Master_Building_Object::modify_delta(float,unsigned char)
    */

void __thiscall
TRIBE_Master_Building_Object::modify_delta
          (TRIBE_Master_Building_Object *this,float param_1,uchar param_2)
{
  short sVar1;
  
  if (param_2 != '\x11') {
    TRIBE_Master_Combat_Object::modify_delta((TRIBE_Master_Combat_Object *)this,param_1,param_2);
    return;
  }
  sVar1 = __ftol();
  this->building_facet = this->building_facet + sVar1;
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 0050e530
/* public: virtual void __thiscall TRIBE_Master_Building_Object::modify_percent(float,unsigned char)
    */

void __thiscall
TRIBE_Master_Building_Object::modify_percent
          (TRIBE_Master_Building_Object *this,float param_1,uchar param_2)
{
  TRIBE_Master_Combat_Object::modify_percent((TRIBE_Master_Combat_Object *)this,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0050e550
/* WARNING: Variable defined which should be unmapped: sound_num */
/* public: virtual void __thiscall TRIBE_Master_Building_Object::save(int) */

void __thiscall TRIBE_Master_Building_Object::save(TRIBE_Master_Building_Object *this,int param_1)
{
  RGE_Sprite *pRVar1;
  int iVar2;
  short sound_num;
  TRIBE_Master_Building_Object *local_4;
  
  iVar2 = param_1;
  local_4 = this;
  TRIBE_Master_Combat_Object::save((TRIBE_Master_Combat_Object *)this,param_1);
  pRVar1 = this->construction_sprite;
  local_4 = (TRIBE_Master_Building_Object *)0xffffffff;
  if (pRVar1 == (RGE_Sprite *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id);
  }
  if (this->construction_sound != (RGE_Sound *)0x0) {
    local_4 = (TRIBE_Master_Building_Object *)CONCAT22(0xffff,this->construction_sound->id);
  }
  rge_write(iVar2,&param_1,2);
  rge_write(iVar2,&this->building_connect_flag,1);
  rge_write(iVar2,&this->building_facet,2);
  rge_write(iVar2,&this->build_and_go_away,1);
  rge_write(iVar2,&this->on_build_make_obj,2);
  rge_write(iVar2,&this->on_build_make_tile,2);
  rge_write(iVar2,&this->on_build_make_overlay,2);
  rge_write(iVar2,&this->on_build_make_tech,2);
  rge_write(iVar2,&local_4,2);
  return;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 0050e630
/* public: virtual class RGE_Static_Object * __thiscall
   TRIBE_Master_Building_Object::make_new_obj(class RGE_Player *,float,float,float,int) */

RGE_Static_Object * __thiscall
TRIBE_Master_Building_Object::make_new_obj
          (TRIBE_Master_Building_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4,int param_5)
{
  TRIBE_Building_Object *this_00;
  RGE_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560e8b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Building_Object *)operator_new(0x204);
  local_4 = 0;
  if (this_00 != (TRIBE_Building_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             TRIBE_Building_Object::TRIBE_Building_Object
                       (this_00,this,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 0050e6b0
/* public: virtual class RGE_Static_Object * __thiscall
   TRIBE_Master_Building_Object::make_new_obj(class RGE_Player *,float,float,float) */

RGE_Static_Object * __thiscall
TRIBE_Master_Building_Object::make_new_obj
          (TRIBE_Master_Building_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  TRIBE_Building_Object *this_00;
  RGE_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560eab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Building_Object *)operator_new(0x204);
  local_4 = 0;
  if (this_00 != (TRIBE_Building_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             TRIBE_Building_Object::TRIBE_Building_Object
                       (this_00,this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 0050e730
/* public: virtual class RGE_Master_Static_Object * __thiscall
   TRIBE_Master_Building_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
TRIBE_Master_Building_Object::make_new_master(TRIBE_Master_Building_Object *this)
{
  TRIBE_Master_Building_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560ecb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
  local_4 = 0;
  if (this_00 != (TRIBE_Master_Building_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)TRIBE_Master_Building_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: draw
// Address: 0050e7a0
/* WARNING: Variable defined which should be unmapped: y1 */
/* public: virtual void __thiscall TRIBE_Master_Building_Object::draw(class TDrawArea
   *,short,short,class RGE_Color_Table *,long,long,int,unsigned char) */

void __thiscall
TRIBE_Master_Building_Object::draw
          (TRIBE_Master_Building_Object *this,TDrawArea *param_1,short param_2,short param_3,
          RGE_Color_Table *param_4,long param_5,long param_6,int param_7,uchar param_8)
{
  RGE_Map *this_00;
  short sVar1;
  short sVar2;
  int iVar3;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  undefined3 in_stack_00000021;
  int iVar4;
  short y1;
  short x1;
  float rx1;
  float ry1;
  float local_8;
  TRIBE_Master_Building_Object *local_4;
  
  sVar2 = param_3;
  sVar1 = param_2;
  if ((RGE_Sprite *)this->_padding_ != (RGE_Sprite *)0x0) {
    if (this->building_connect_flag == '\0') {
      iVar4 = (int)this->building_facet;
    }
    else if (param_5 == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = param_5 + -1;
    }
    iVar3 = (int)param_3;
    local_4 = this;
    RGE_Sprite::draw((RGE_Sprite *)this->_padding_,iVar4,0,(int)param_2,iVar3,(int)param_2,iVar3,
                     param_4,param_1,'\0');
    if (param_7 != 0) {
      ry1 = (float)local_4->_padding_;
      this_00 = rge_base_game->world->map;
      local_8 = (float)local_4->_padding_;
      local_4 = (TRIBE_Master_Building_Object *)-local_8;
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&rx1,ry1,(float)local_4,0.0,sVar1
                         ,sVar2);
      RGE_Map::get_point(this_00,(short *)&param_7,(short *)&param_5,ry1,local_8,0.0,sVar1,sVar2);
      ry1 = -ry1;
      RGE_Map::get_point(this_00,(short *)&param_4,(short *)&param_1,ry1,local_8,0.0,sVar1,sVar2);
      RGE_Map::get_point(this_00,&param_2,&param_3,ry1,(float)local_4,0.0,sVar1,sVar2);
      DClipInfo_List::AddGDINode
                (SDI_List,1,iVar3,(int)rx1._2_2_,(int)rx1._0_2_,(int)(short)param_7,
                 (int)(short)param_5,(int)(short)param_4,(int)(short)param_1,(int)param_2,
                 (int)param_3,10,_param_8 & 0xff,SDI_Object_ID);
    }
  }
  return;
}

// --------------------------------------------------

// Function: alignment
// Address: 0050e950
/* public: virtual unsigned char __thiscall TRIBE_Master_Building_Object::alignment(float &,float
   &,class RGE_Game_World *,unsigned char) */

uchar __thiscall
TRIBE_Master_Building_Object::alignment
          (TRIBE_Master_Building_Object *this,float *param_1,float *param_2,RGE_Game_World *param_3,
          uchar param_4)
{
  uchar uVar1;
  
  uVar1 = RGE_Master_Static_Object::alignment
                    ((RGE_Master_Static_Object *)this,param_1,param_2,param_3,'\x01');
  return uVar1;
}

// --------------------------------------------------

