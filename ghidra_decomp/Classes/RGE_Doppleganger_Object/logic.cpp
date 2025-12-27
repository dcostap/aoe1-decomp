// Class: RGE_Doppleganger_Object
// Function: RGE_Doppleganger_Object
// Address: 004418a0
/* public: __thiscall RGE_Doppleganger_Object::RGE_Doppleganger_Object(class
   RGE_Master_Doppleganger_Object *,class RGE_Player *,float,float,float,int,class RGE_Static_Object
   *) */

RGE_Doppleganger_Object * __thiscall
RGE_Doppleganger_Object::RGE_Doppleganger_Object
          (RGE_Doppleganger_Object *this,RGE_Master_Doppleganger_Object *param_1,RGE_Player *param_2
          ,float param_3,float param_4,float param_5,int param_6,RGE_Static_Object *param_7)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  RGE_Active_Sprite_Node *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d298;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Animated_Object::RGE_Animated_Object
            ((RGE_Animated_Object *)this,(RGE_Master_Animated_Object *)param_1,param_2,param_3,
             param_4,param_5,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->doppled_object = (RGE_Static_Object *)0x0;
  this->draw_color = (RGE_Color_Table *)0x0;
  this->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
  this->doppled_player = 0;
  this->MapAddress = (ulong *)0x0;
  this->LastMapValue = 0;
  this->CantSeeBits = 0;
  this->map_draw_level = '\0';
  this->map_color = '\0';
  this->doppledObjectID = -1;
  if (param_6 != 0) {
    setup(this,param_1,param_2,param_3,param_4,param_5);
  }
  this->doppled_object = param_7;
  if (param_7 == (RGE_Static_Object *)0x0) {
    this->doppledObjectID = -1;
    this->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
    this->doppled_player = 0;
    RGE_Static_Object::destroy_obj((RGE_Static_Object *)this);
  }
  else {
    this->doppled_master_obj = param_7->master_obj;
    this->doppled_player = (int)param_7->owner->id;
    this->doppledObjectID = param_7->id;
    this->_padding_ = (int)param_7->sprite;
    pRVar3 = RGE_Active_Sprite_List::copy_sprite_list(param_7->sprite_list);
    RGE_Active_Sprite_List::use_sprite_list((RGE_Active_Sprite_List *)this->_padding_,pRVar3);
    pRVar2 = this->doppled_object;
    *(uchar *)((int)&this->_padding_ + 1) = pRVar2->facet;
    this->draw_color = pRVar2->owner->color_table;
    uVar1 = pRVar2->master_obj->map_draw_level;
    this->map_draw_level = uVar1;
    if (uVar1 == '\x03') {
      this->map_color = pRVar2->master_obj->map_color;
    }
    else {
      this->map_color = pRVar2->owner->color_table->map_color;
    }
    if (6 < pRVar2->object_state) {
      this->doppled_object = (RGE_Static_Object *)0x0;
      this->doppledObjectID = -1;
    }
  }
  validate(this);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00441a40
/* public: virtual void * __thiscall RGE_Doppleganger_Object::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
RGE_Doppleganger_Object::_scalar_deleting_destructor_(RGE_Doppleganger_Object *this,uint param_1)
{
  ~RGE_Doppleganger_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Doppleganger_Object
// Address: 00441a60
/* public: virtual __thiscall RGE_Doppleganger_Object::~RGE_Doppleganger_Object(void) */

void __thiscall RGE_Doppleganger_Object::~RGE_Doppleganger_Object(RGE_Doppleganger_Object *this)
{
  undefined4 *puVar1;
  RGE_Object_List *this_00;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  pcStack_8 = FUN_0055f9e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&RGE_Static_Object::_vftable_;
  uStack_4 = 1;
  RGE_Static_Object::remove_visible_resource((RGE_Static_Object *)this);
  if (this->_padding_ != 0) {
    if ((byte)this->_padding_ < 3) {
      RGE_Static_Object::take_attribute_from_owner((RGE_Static_Object *)this);
    }
    if ((byte)this->_padding_ < 7) {
      RGE_Victory_Conditions::update_for_object
                (*(RGE_Victory_Conditions **)(this->_padding_ + 0x34),(RGE_Static_Object *)this);
    }
  }
  if ((undefined4 *)this->_padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->_padding_)(1);
    this->_padding_ = 0;
  }
  if ((RGE_Player *)this->_padding_ != (RGE_Player *)0x0) {
    if ((this->_padding_ & 0x10000) != 0) {
      RGE_Player::unselect_one_object((RGE_Player *)this->_padding_,(RGE_Static_Object *)this);
    }
    (**(code **)(*(int *)this->_padding_ + 0xe0))
              (this,*(undefined1 *)((int)&this->_padding_ + 1),
               *(undefined1 *)((int)&this->_padding_ + 2),this->_padding_);
    this->_padding_ = 0;
  }
  if (this->_padding_ != 0) {
    RGE_Object_List::remove_node
              ((RGE_Object_List *)(this->_padding_ + 0xc),(RGE_Static_Object *)this,
               (RGE_Object_Node *)0x0);
    this->_padding_ = 0;
  }
  if ((this->_padding_ != 0) && ((float)(double)DAT_00574718 < *(float *)(this->_padding_ + 0x38)))
{
    RGE_Static_Object::removeFromObstructionMap((RGE_Static_Object *)this,2);
  }
  if (this->_padding_ != 0) {
    RGE_Object_List::remove_node
              (*(RGE_Object_List **)(this->_padding_ + 0x24),(RGE_Static_Object *)this,
               (RGE_Object_Node *)0x0);
    this->_padding_ = 0;
  }
  if (this->_padding_ != 0) {
    puVar2 = *(undefined4 **)(this->_padding_ + 4);
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar2[1];
      (**(code **)(*(int *)*puVar2 + 0xd4))();
      puVar2 = puVar1;
    }
    this_00 = (RGE_Object_List *)this->_padding_;
    if (this_00 != (RGE_Object_List *)0x0) {
      RGE_Object_List::~RGE_Object_List(this_00);
      operator_delete(this_00);
    }
  }
  if ((undefined4 *)this->_padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->_padding_)(1);
    this->_padding_ = 0;
  }
  uStack_4 = uStack_4 & 0xffffff00;
  if ((void *)this->_padding_ != (void *)0x0) {
    operator_delete((void *)this->_padding_);
    this->_padding_ = 0;
  }
  this->_padding_ = 0;
  this->_padding_ = 0;
  this->_padding_ = 0;
  uStack_4 = 0xffffffff;
  if ((void *)this->_padding_ != (void *)0x0) {
    operator_delete((void *)this->_padding_);
    this->_padding_ = 0;
  }
  this->_padding_ = 0;
  this->_padding_ = 0;
  this->_padding_ = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: RGE_Doppleganger_Object
// Address: 00441a70
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall RGE_Doppleganger_Object::RGE_Doppleganger_Object(int,class RGE_Game_World
   *,int) */

RGE_Doppleganger_Object * __thiscall
RGE_Doppleganger_Object::RGE_Doppleganger_Object
          (RGE_Doppleganger_Object *this,int param_1,RGE_Game_World *param_2,int param_3)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d2b8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Animated_Object::RGE_Animated_Object((RGE_Animated_Object *)this,param_1,param_2,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->doppled_object = (RGE_Static_Object *)0x0;
  this->draw_color = (RGE_Color_Table *)0x0;
  this->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
  this->doppled_player = 0;
  this->MapAddress = (ulong *)0x0;
  this->LastMapValue = 0;
  this->CantSeeBits = 0;
  this->map_draw_level = '\0';
  this->map_color = '\0';
  this->doppledObjectID = -1;
  if (param_3 != 0) {
    setup(this,iVar1,param_2);
  }
  rge_read(iVar1,&param_1,4);
  this->doppled_object = (RGE_Static_Object *)param_1;
  this->doppledObjectID = -1;
  rge_read(iVar1,&this->map_draw_level,1);
  rge_read(iVar1,&this->map_color,4);
  rge_read(iVar1,&param_1,4);
  this->doppled_master_obj = (RGE_Master_Static_Object *)param_1;
  rge_read(iVar1,&this->doppled_player,4);
  if (_DAT_00570418 <= save_game_version) {
    rge_read(iVar1,&this->CantSeeBits,4);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: recycle_in_to_game
// Address: 00441bb0
/* public: virtual void __thiscall RGE_Doppleganger_Object::recycle_in_to_game(class
   RGE_Master_Static_Object *,class RGE_Player *,float,float,float,class RGE_Static_Object *) */

void __thiscall
RGE_Doppleganger_Object::recycle_in_to_game
          (RGE_Doppleganger_Object *this,RGE_Master_Static_Object *param_1,RGE_Player *param_2,
          float param_3,float param_4,float param_5,RGE_Static_Object *param_6)
{
  RGE_Static_Object *pRVar1;
  ulong **ppuVar2;
  RGE_Active_Sprite_Node *pRVar3;
  int iVar4;
  int iVar5;
  uchar uVar6;
  
  this->doppled_object = (RGE_Static_Object *)0x0;
  this->draw_color = (RGE_Color_Table *)0x0;
  this->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
  this->doppled_player = 0;
  this->MapAddress = (ulong *)0x0;
  this->LastMapValue = 0;
  this->CantSeeBits = 0;
  this->map_draw_level = '\0';
  this->map_color = '\0';
  this->doppledObjectID = -1;
  RGE_Animated_Object::recycle_in_to_game
            ((RGE_Animated_Object *)this,param_1,param_2,param_3,param_4,param_5);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x19;
  this->doppled_object = param_6;
  if (param_6 == (RGE_Static_Object *)0x0) {
    this->doppledObjectID = -1;
    this->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
    this->doppled_player = 0;
    (**(code **)(this->_padding_ + 0x68))();
  }
  else {
    this->doppled_master_obj = param_6->master_obj;
    this->doppled_player = (int)param_6->owner->id;
    this->doppledObjectID = param_6->id;
    this->_padding_ = (int)param_6->sprite;
    pRVar3 = RGE_Active_Sprite_List::copy_sprite_list(param_6->sprite_list);
    RGE_Active_Sprite_List::use_sprite_list((RGE_Active_Sprite_List *)this->_padding_,pRVar3);
    pRVar1 = this->doppled_object;
    *(uchar *)((int)&this->_padding_ + 1) = pRVar1->facet;
    this->draw_color = pRVar1->owner->color_table;
    uVar6 = pRVar1->master_obj->map_draw_level;
    this->map_draw_level = uVar6;
    if (uVar6 == '\x03') {
      uVar6 = pRVar1->master_obj->map_color;
    }
    else {
      uVar6 = pRVar1->owner->color_table->map_color;
    }
    this->map_color = uVar6;
    iVar4 = __ftol();
    iVar5 = __ftol();
    ppuVar2 = (&unified_map_offsets)[iVar4];
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->MapAddress = (ulong *)(ppuVar2 + iVar5);
    if (6 < pRVar1->object_state) {
      this->doppled_object = (RGE_Static_Object *)0x0;
      this->doppledObjectID = -1;
      (**(code **)(this->_padding_ + 0x1f0))();
      return;
    }
  }
  (**(code **)(this->_padding_ + 0x1f0))();
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 00441d30
/* protected: virtual int __thiscall RGE_Doppleganger_Object::setup(class
   RGE_Master_Doppleganger_Object *,class RGE_Player *,float,float,float) */

int __thiscall
RGE_Doppleganger_Object::setup
          (RGE_Doppleganger_Object *this,RGE_Master_Doppleganger_Object *param_1,RGE_Player *param_2
          ,float param_3,float param_4,float param_5)
{
  int iVar1;
  int iVar2;
  
  RGE_Animated_Object::setup
            ((RGE_Animated_Object *)this,(RGE_Master_Animated_Object *)param_1,param_2,param_3,
             param_4,param_5);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x19;
  iVar1 = __ftol();
  iVar2 = __ftol();
  this->MapAddress = (ulong *)((&unified_map_offsets)[iVar1] + iVar2);
  this->LastMapValue = 0;
  this->CantSeeBits = 0;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00441da0
/* protected: virtual int __thiscall RGE_Doppleganger_Object::setup(int,class RGE_Game_World *) */

int __thiscall
RGE_Doppleganger_Object::setup(RGE_Doppleganger_Object *this,int param_1,RGE_Game_World *param_2)
{
  int iVar1;
  int iVar2;
  
  RGE_Animated_Object::setup((RGE_Animated_Object *)this,param_1,param_2);
  *(undefined1 *)((int)&this->_padding_ + 2) = 0x19;
  iVar1 = __ftol();
  iVar2 = __ftol();
  this->MapAddress = (ulong *)((&unified_map_offsets)[iVar1] + iVar2);
  this->LastMapValue = 0;
  this->CantSeeBits = 0;
  return 1;
}

// --------------------------------------------------

// Function: rehook
// Address: 00441e00
/* public: virtual void __thiscall RGE_Doppleganger_Object::rehook(void) */

void __thiscall RGE_Doppleganger_Object::rehook(RGE_Doppleganger_Object *this)
{
  RGE_Master_Static_Object *pRVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  RGE_Player *pRVar4;
  
  RGE_Static_Object::rehook((RGE_Static_Object *)this);
  pRVar3 = this->doppled_object;
  if ((int)pRVar3 < 0) {
    this->doppled_object = (RGE_Static_Object *)0x0;
    this->doppledObjectID = -1;
    pRVar4 = *(RGE_Player **)
              (*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x40) + (-1 - (int)pRVar3) * 4);
  }
  else {
    pRVar3 = RGE_Static_Object::get_object_pointer((RGE_Static_Object *)this,(long)pRVar3);
    this->doppled_object = pRVar3;
    if (pRVar3 == (RGE_Static_Object *)0x0) goto LAB_00441e63;
    this->doppledObjectID = pRVar3->id;
    pRVar4 = pRVar3->owner;
  }
  this->draw_color = pRVar4->color_table;
LAB_00441e63:
  pRVar1 = this->doppled_master_obj;
  if ((-1 < (int)pRVar1) &&
     (iVar2 = *(int *)(*(int *)(*(int *)(this->_padding_ + 0x3c) + 0x40) + this->doppled_player * 4)
     , (int)pRVar1 < (int)*(short *)(iVar2 + 0x22))) {
    this->doppled_master_obj =
         *(RGE_Master_Static_Object **)(*(int *)(iVar2 + 0x24) + (int)pRVar1 * 4);
    return;
  }
  this->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
  (**(code **)(this->_padding_ + 0x68))();
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00441eb0
// [HELPER] s_DIE_DOP____d__id__d_own__d_: "DIE DOP (@%d) id=%d own=%d\n"
/* public: virtual unsigned char __thiscall RGE_Doppleganger_Object::update(void) */

uchar __thiscall RGE_Doppleganger_Object::update(RGE_Doppleganger_Object *this)
{
  uint uVar1;
  int iVar2;
  uchar uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar3 = RGE_Animated_Object::update((RGE_Animated_Object *)this);
  if (this->doppled_object != (RGE_Static_Object *)0x0) {
    if (this->doppled_object->object_state < 7) goto LAB_00441ee1;
    this->doppled_object = (RGE_Static_Object *)0x0;
  }
  this->doppledObjectID = -1;
LAB_00441ee1:
  uVar1 = *this->MapAddress;
  if (uVar1 != this->LastMapValue) {
    iVar2 = this->_padding_;
    if (((*(uint *)(iVar2 + 0xd4) & uVar1) != 0) && ((byte)this->_padding_ < 3)) {
      if (DDlogf != (_iobuf *)0x0) {
        fprintf(DDlogf,s_DIE_DOP____d__id__d_own__d_,*(undefined4 *)(*(int *)(iVar2 + 0x3c) + 4),
                this->_padding_,(int)*(short *)(iVar2 + 0x4a));
      }
      (**(code **)(this->_padding_ + 0x68))();
    }
    uVar4 = *(uint *)(this->_padding_ + 0xd8) & uVar1;
    if (uVar4 != 0) {
      puVar5 = (uint *)(this->_padding_ + 0xdc);
      do {
        if (((byte)uVar4 & 1) == 1) {
          this->CantSeeBits = this->CantSeeBits | *puVar5;
        }
        puVar5 = puVar5 + 1;
        uVar4 = uVar4 >> 1;
      } while (uVar4 != 0);
    }
    this->LastMapValue = uVar1;
  }
  return uVar3;
}

// --------------------------------------------------

// Function: save
// Address: 00441f80
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall RGE_Doppleganger_Object::save(int) */

void __thiscall RGE_Doppleganger_Object::save(RGE_Doppleganger_Object *this,int param_1)
{
  int iVar1;
  
  iVar1 = param_1;
  RGE_Animated_Object::save((RGE_Animated_Object *)this,param_1);
  if (this->doppled_object == (RGE_Static_Object *)0x0) {
    param_1 = -1 - this->doppled_player;
  }
  else {
    param_1 = this->doppled_object->id;
  }
  rge_write(iVar1,&param_1,4);
  rge_write(iVar1,&this->map_draw_level,1);
  rge_write(iVar1,&this->map_color,4);
  if (this->doppled_master_obj == (RGE_Master_Static_Object *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = (int)this->doppled_master_obj->id;
  }
  rge_write(iVar1,&param_1,4);
  rge_write(iVar1,&this->doppled_player,4);
  if (_DAT_00570418 <= save_game_version) {
    rge_write(iVar1,&this->CantSeeBits,4);
  }
  return;
}

// --------------------------------------------------

// Function: validate
// Address: 00442050
/* public: virtual void __thiscall RGE_Doppleganger_Object::validate(void) */

void __thiscall RGE_Doppleganger_Object::validate(RGE_Doppleganger_Object *this)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(*(int *)(this->_padding_ + 0x3c) + 0x28);
  iVar5 = __ftol();
  iVar2 = *(int *)(iVar2 + 0x8d8c);
  iVar6 = __ftol();
  for (piVar3 = *(int **)(*(int *)(iVar2 + iVar5 * 4) + 0x10 + iVar6 * 0x18); piVar3 != (int *)0x0;
      piVar3 = (int *)piVar3[1]) {
    piVar4 = (int *)*piVar3;
    if ((((piVar4 != (int *)0x0) && (*(char *)((int)piVar4 + 0x4e) == '\x19')) &&
        (piVar4[1] != this->_padding_)) &&
       ((piVar4[0x2b] == this->doppledObjectID && ((char)piVar4[0x12] == '\x02')))) {
      sVar1 = *(short *)(this->_padding_ + 0x4a);
      if (*(short *)(piVar4[3] + 0x4a) == sVar1) {
        (**(code **)(*piVar4 + 0x68))();
      }
      else {
        piVar4[0x29] = piVar4[0x29] | 1 << ((byte)sVar1 & 0x1f);
        this->CantSeeBits = this->CantSeeBits | 1 << (*(byte *)(piVar4[3] + 0x4a) & 0x1f);
      }
    }
  }
  return;
}

// --------------------------------------------------

