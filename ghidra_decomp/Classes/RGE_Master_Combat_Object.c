// Class: RGE_Master_Combat_Object
// Size:  0x148
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
// [14] create_task_list
//
// Member Layout:
// [0x0FC] RGE_Sprite * fight_sprite
// [0x100] uchar base_armor
// [0x102] short armor_num
// [0x104] RGE_Armor_Weapon_Info * armor
// [0x108] short weapon_num
// [0x10C] RGE_Armor_Weapon_Info * weapon
// [0x110] short defense_terrain_bonus
// [0x114] float weapon_range
// [0x118] float area_effect_range
// [0x11C] uchar area_effect_level
// [0x120] float speed_of_attack
// [0x124] short missile_id
// [0x126] short base_hit_chance
// [0x128] uchar break_off_combat
// [0x12A] short fire_missile_at_frame
// [0x12C] float weapon_offset_x
// [0x130] float weapon_offset_y
// [0x134] float weapon_offset_z
// [0x138] float minimum_weapon_range
// [0x13C] short orig_armor
// [0x13E] short orig_weapon
// [0x140] float orig_weapon_range
// [0x144] float orig_speed_of_attack
// ----------------------------------------------------------------

// Function: RGE_Master_Combat_Object
// Address: 0044fe40
/* public: __thiscall RGE_Master_Combat_Object::RGE_Master_Combat_Object(class
   RGE_Master_Combat_Object *,int) */

RGE_Master_Combat_Object * __thiscall
RGE_Master_Combat_Object::RGE_Master_Combat_Object
          (RGE_Master_Combat_Object *this,RGE_Master_Combat_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d7b8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Action_Object::RGE_Master_Action_Object
            ((RGE_Master_Action_Object *)this,(RGE_Master_Action_Object *)param_1,0);
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
// Address: 0044fea0
/* public: virtual void * __thiscall RGE_Master_Combat_Object::`vector deleting destructor'(unsigned
   int) */

void * __thiscall
RGE_Master_Combat_Object::_vector_deleting_destructor_(RGE_Master_Combat_Object *this,uint param_1)
{
  ~RGE_Master_Combat_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Combat_Object
// Address: 0044fec0
/* public: __thiscall RGE_Master_Combat_Object::RGE_Master_Combat_Object(int,class RGE_Sprite *
   *,class RGE_Sound * *,int) */

RGE_Master_Combat_Object * __thiscall
RGE_Master_Combat_Object::RGE_Master_Combat_Object
          (RGE_Master_Combat_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d7d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Action_Object::RGE_Master_Action_Object
            ((RGE_Master_Action_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Combat_Object
// Address: 0044ff30
/* public: __thiscall RGE_Master_Combat_Object::RGE_Master_Combat_Object(struct _iobuf *,class
   RGE_Sprite * *,class RGE_Sound * *,short,int) */

RGE_Master_Combat_Object * __thiscall
RGE_Master_Combat_Object::RGE_Master_Combat_Object
          (RGE_Master_Combat_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d7f8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Action_Object::RGE_Master_Action_Object
            ((RGE_Master_Action_Object *)this,param_1,param_2,param_3,param_4,0);
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
// Address: 0044ffb0
/* protected: int __thiscall RGE_Master_Combat_Object::setup(class RGE_Master_Combat_Object *) */

int __thiscall
RGE_Master_Combat_Object::setup(RGE_Master_Combat_Object *this,RGE_Master_Combat_Object *param_1)
{
  short sVar1;
  RGE_Armor_Weapon_Info *pRVar2;
  uint uVar3;
  int iVar4;
  RGE_Armor_Weapon_Info *pRVar5;
  
  RGE_Master_Action_Object::setup
            ((RGE_Master_Action_Object *)this,(RGE_Master_Action_Object *)param_1);
  *(undefined1 *)&this->_padding_ = 0x32;
  this->fight_sprite = param_1->fight_sprite;
  this->base_armor = param_1->base_armor;
  sVar1 = param_1->weapon_num;
  this->weapon_num = sVar1;
  if (sVar1 < 1) {
    this->weapon = (RGE_Armor_Weapon_Info *)0x0;
  }
  else {
    pRVar2 = (RGE_Armor_Weapon_Info *)calloc((int)sVar1,4);
    this->weapon = pRVar2;
    pRVar5 = param_1->weapon;
    for (uVar3 = (int)this->weapon_num & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pRVar2 = *pRVar5;
      pRVar5 = pRVar5 + 1;
      pRVar2 = pRVar2 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(char *)&pRVar2->type = (char)pRVar5->type;
      pRVar5 = (RGE_Armor_Weapon_Info *)((int)&pRVar5->type + 1);
      pRVar2 = (RGE_Armor_Weapon_Info *)((int)&pRVar2->type + 1);
    }
  }
  sVar1 = param_1->armor_num;
  this->armor_num = sVar1;
  if (sVar1 < 1) {
    this->armor = (RGE_Armor_Weapon_Info *)0x0;
  }
  else {
    pRVar2 = (RGE_Armor_Weapon_Info *)calloc((int)sVar1,4);
    this->armor = pRVar2;
    pRVar5 = param_1->armor;
    for (uVar3 = (int)this->armor_num & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pRVar2 = *pRVar5;
      pRVar5 = pRVar5 + 1;
      pRVar2 = pRVar2 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(char *)&pRVar2->type = (char)pRVar5->type;
      pRVar5 = (RGE_Armor_Weapon_Info *)((int)&pRVar5->type + 1);
      pRVar2 = (RGE_Armor_Weapon_Info *)((int)&pRVar2->type + 1);
    }
  }
  this->defense_terrain_bonus = param_1->defense_terrain_bonus;
  this->weapon_range = param_1->weapon_range;
  this->area_effect_range = param_1->area_effect_range;
  this->speed_of_attack = param_1->speed_of_attack;
  this->missile_id = param_1->missile_id;
  this->base_hit_chance = param_1->base_hit_chance;
  this->break_off_combat = param_1->break_off_combat;
  this->fire_missile_at_frame = param_1->fire_missile_at_frame;
  this->weapon_offset_x = param_1->weapon_offset_x;
  this->weapon_offset_y = param_1->weapon_offset_y;
  this->weapon_offset_z = param_1->weapon_offset_z;
  this->area_effect_level = param_1->area_effect_level;
  this->minimum_weapon_range = param_1->minimum_weapon_range;
  this->orig_armor = param_1->orig_armor;
  this->orig_weapon = param_1->orig_weapon;
  this->orig_weapon_range = param_1->orig_weapon_range;
  this->orig_speed_of_attack = param_1->orig_speed_of_attack;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00450170
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: int __thiscall RGE_Master_Combat_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
RGE_Master_Combat_Object::setup
          (RGE_Master_Combat_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  RGE_Armor_Weapon_Info *pRVar1;
  RGE_Sprite *pRVar2;
  short *psVar3;
  int iVar4;
  
  RGE_Master_Action_Object::setup((RGE_Master_Action_Object *)this,param_1,param_2,param_3);
  *(undefined1 *)&this->_padding_ = 0x32;
  rge_read(param_1,&this->base_armor,1);
  psVar3 = &this->weapon_num;
  rge_read(param_1,psVar3,2);
  if (*psVar3 < 1) {
    this->weapon = (RGE_Armor_Weapon_Info *)0x0;
  }
  else {
    pRVar1 = (RGE_Armor_Weapon_Info *)calloc((int)*psVar3,4);
    this->weapon = pRVar1;
    rge_read(param_1,pRVar1,(int)*psVar3 << 2);
  }
  psVar3 = &this->armor_num;
  rge_read(param_1,psVar3,2);
  if (*psVar3 < 1) {
    this->armor = (RGE_Armor_Weapon_Info *)0x0;
  }
  else {
    pRVar1 = (RGE_Armor_Weapon_Info *)calloc((int)*psVar3,4);
    this->armor = pRVar1;
    rge_read(param_1,pRVar1,(int)*psVar3 << 2);
  }
  rge_read(param_1,&this->defense_terrain_bonus,2);
  rge_read(param_1,&this->weapon_range,4);
  rge_read(param_1,&this->area_effect_range,4);
  rge_read(param_1,&this->speed_of_attack,4);
  rge_read(param_1,&this->missile_id,2);
  rge_read(param_1,&this->base_hit_chance,2);
  rge_read(param_1,&this->break_off_combat,1);
  rge_read(param_1,&this->fire_missile_at_frame,2);
  rge_read(param_1,&this->weapon_offset_x,4);
  rge_read(param_1,&this->weapon_offset_y,4);
  rge_read(param_1,&this->weapon_offset_z,4);
  rge_read(param_1,&this->area_effect_level,1);
  rge_read(param_1,&this->minimum_weapon_range,4);
  rge_read(param_1,&param_3,2);
  if ((short)param_3 < 0) {
    pRVar2 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar2 = param_2[(short)param_3];
  }
  this->fight_sprite = pRVar2;
  if (_DAT_00570500 <= save_game_version) {
    rge_read(param_1,&this->orig_armor,2);
    rge_read(param_1,&this->orig_weapon,2);
    rge_read(param_1,&this->orig_weapon_range,4);
    rge_read(param_1,&this->orig_speed_of_attack,4);
    return 1;
  }
  this->orig_armor = (ushort)this->base_armor;
  iVar4 = (int)*psVar3;
  if (0 < iVar4) {
    psVar3 = &this->armor->value;
    do {
      if (this->orig_armor < *psVar3) {
        this->orig_armor = *psVar3;
      }
      psVar3 = psVar3 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  iVar4 = (int)this->weapon_num;
  this->orig_weapon = 0;
  if (0 < iVar4) {
    psVar3 = &this->weapon->value;
    do {
      if (this->orig_weapon < *psVar3) {
        this->orig_weapon = *psVar3;
      }
      psVar3 = psVar3 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  this->orig_weapon_range = this->weapon_range;
  this->orig_speed_of_attack = this->speed_of_attack;
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00450450
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s__hd__hd__hd__hd__hd__f__f__f__hd: "%hd %hd %hd %hd %hd %f %f %f %hd %hd %hd %hd %f %f %f %hd %f"
/* WARNING: Variable defined which should be unmapped: temp_break_off_combat */
/* protected: int __thiscall RGE_Master_Combat_Object::setup(struct _iobuf *,class RGE_Sprite *
   *,class RGE_Sound * *,short) */

int __thiscall
RGE_Master_Combat_Object::setup
          (RGE_Master_Combat_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4)
{
  _iobuf *p_Var1;
  RGE_Armor_Weapon_Info *pRVar2;
  RGE_Sprite *pRVar3;
  short *psVar4;
  int iVar5;
  short sVar6;
  undefined2 in_stack_00000012;
  short temp_break_off_combat;
  short temp_fire_missile_at_frame;
  undefined4 local_4;
  
  p_Var1 = param_1;
  local_4 = this;
  RGE_Master_Action_Object::setup((RGE_Master_Action_Object *)this,param_1,param_2,param_3,param_4);
  psVar4 = &this->armor_num;
  *(undefined1 *)&this->_padding_ = 0x32;
  fscanf(p_Var1,s__hd__hd__hd__hd__hd__f__f__f__hd,&param_4,&param_1,psVar4,&this->weapon_num,
         &this->defense_terrain_bonus,&this->weapon_range,&this->area_effect_range,
         &this->speed_of_attack,&this->missile_id,&this->base_hit_chance,&local_4,(int)&local_4 + 2,
         &this->weapon_offset_x,&this->weapon_offset_y,&this->weapon_offset_z,&param_3,
         &this->minimum_weapon_range);
  sVar6 = 0;
  if (*psVar4 < 1) {
    this->armor = (RGE_Armor_Weapon_Info *)0x0;
  }
  else {
    pRVar2 = (RGE_Armor_Weapon_Info *)calloc((int)*psVar4,4);
    this->armor = pRVar2;
    if (0 < *psVar4) {
      do {
        fscanf(p_Var1,s__hd__hd,this->armor + sVar6,&this->armor[sVar6].value);
        sVar6 = sVar6 + 1;
      } while (sVar6 < *psVar4);
    }
  }
  sVar6 = 0;
  if (this->weapon_num < 1) {
    this->weapon = (RGE_Armor_Weapon_Info *)0x0;
  }
  else {
    pRVar2 = (RGE_Armor_Weapon_Info *)calloc((int)this->weapon_num,4);
    this->weapon = pRVar2;
    if (0 < this->weapon_num) {
      do {
        fscanf(p_Var1,s__hd__hd,this->weapon + sVar6,&this->weapon[sVar6].value);
        sVar6 = sVar6 + 1;
      } while (sVar6 < this->weapon_num);
    }
  }
  if (param_4 < 0) {
    pRVar3 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar3 = param_2[param_4];
  }
  this->fight_sprite = pRVar3;
  this->break_off_combat = (uchar)local_4;
  this->area_effect_level = (uchar)param_3;
  iVar5 = (int)*psVar4;
  this->base_armor = (byte)param_1;
  this->fire_missile_at_frame = (ushort)local_4._2_1_;
  this->orig_armor = (ushort)(byte)param_1;
  if (0 < iVar5) {
    psVar4 = &this->armor->value;
    do {
      if (this->orig_armor < *psVar4) {
        this->orig_armor = *psVar4;
      }
      psVar4 = psVar4 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  iVar5 = (int)this->weapon_num;
  this->orig_weapon = 0;
  if (0 < iVar5) {
    psVar4 = &this->weapon->value;
    do {
      if (this->orig_weapon < *psVar4) {
        this->orig_weapon = *psVar4;
      }
      psVar4 = psVar4 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  this->orig_weapon_range = this->weapon_range;
  this->orig_speed_of_attack = this->speed_of_attack;
  return 1;
}

// --------------------------------------------------

// Function: ~RGE_Master_Combat_Object
// Address: 00450680
/* public: virtual __thiscall RGE_Master_Combat_Object::~RGE_Master_Combat_Object(void) */

void __thiscall RGE_Master_Combat_Object::~RGE_Master_Combat_Object(RGE_Master_Combat_Object *this)
{
  this->_padding_ = (int)&_vftable_;
  if (this->weapon != (RGE_Armor_Weapon_Info *)0x0) {
    free(this->weapon);
    this->weapon = (RGE_Armor_Weapon_Info *)0x0;
  }
  if (this->armor != (RGE_Armor_Weapon_Info *)0x0) {
    free(this->armor);
    this->armor = (RGE_Armor_Weapon_Info *)0x0;
  }
  RGE_Master_Action_Object::~RGE_Master_Action_Object((RGE_Master_Action_Object *)this);
  return;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 004506d0
/* public: virtual class RGE_Static_Object * __thiscall RGE_Master_Combat_Object::make_new_obj(class
   RGE_Player *,float,float,float) */

RGE_Static_Object * __thiscall
RGE_Master_Combat_Object::make_new_obj
          (RGE_Master_Combat_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  RGE_Static_Object *pRVar1;
  RGE_Combat_Object *this_00;
  float *unaff_FS_OFFSET;
  float local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d81b;
  *unaff_FS_OFFSET = (float)&local_c;
  if ((char)this->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_1->world,(uchar)this->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(this,param_1,param_2,param_3,param_4);
      *unaff_FS_OFFSET = param_3;
      return pRVar1;
    }
  }
  this_00 = (RGE_Combat_Object *)operator_new(0x1c4);
  local_4 = 0;
  if (this_00 != (RGE_Combat_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Combat_Object::RGE_Combat_Object(this_00,this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 004507a0
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Master_Combat_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Combat_Object::make_new_master(RGE_Master_Combat_Object *this)
{
  RGE_Master_Combat_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d83b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (RGE_Master_Combat_Object *)operator_new(0x148);
  local_4 = 0;
  if (this_00 != (RGE_Master_Combat_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)RGE_Master_Combat_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 00450810
/* public: virtual void __thiscall RGE_Master_Combat_Object::copy_obj(class RGE_Master_Static_Object
   *) */

void __thiscall
RGE_Master_Combat_Object::copy_obj(RGE_Master_Combat_Object *this,RGE_Master_Static_Object *param_1)
{
  RGE_Armor_Weapon_Info *pRVar1;
  uint uVar2;
  int iVar3;
  RGE_Armor_Weapon_Info *pRVar4;
  
  RGE_Master_Action_Object::copy_obj((RGE_Master_Action_Object *)this,param_1);
  this->fight_sprite = (RGE_Sprite *)param_1[1].death_sound;
  this->base_armor = (uchar)param_1[1].death_spawn_obj_id;
  this->weapon_num = param_1[1].portrait_pict;
  if (this->weapon != (RGE_Armor_Weapon_Info *)0x0) {
    free(this->weapon);
  }
  if (this->weapon_num < 1) {
    this->weapon = (RGE_Armor_Weapon_Info *)0x0;
  }
  else {
    pRVar1 = (RGE_Armor_Weapon_Info *)calloc((int)this->weapon_num,4);
    this->weapon = pRVar1;
    pRVar4 = *(RGE_Armor_Weapon_Info **)&param_1[1].tile_req1;
    for (uVar2 = (int)this->weapon_num & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pRVar1 = *pRVar4;
      pRVar4 = pRVar4 + 1;
      pRVar1 = pRVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(char *)&pRVar1->type = (char)pRVar4->type;
      pRVar4 = (RGE_Armor_Weapon_Info *)((int)&pRVar4->type + 1);
      pRVar1 = (RGE_Armor_Weapon_Info *)((int)&pRVar1->type + 1);
    }
  }
  this->armor_num = *(short *)&param_1[1].sort_number;
  if (this->armor != (RGE_Armor_Weapon_Info *)0x0) {
    free(this->armor);
  }
  if (this->armor_num < 1) {
    this->armor = (RGE_Armor_Weapon_Info *)0x0;
  }
  else {
    pRVar1 = (RGE_Armor_Weapon_Info *)calloc((int)this->armor_num,4);
    this->armor = pRVar1;
    pRVar4 = *(RGE_Armor_Weapon_Info **)&param_1[1].button_pict;
    for (uVar2 = (int)this->armor_num & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pRVar1 = *pRVar4;
      pRVar4 = pRVar4 + 1;
      pRVar1 = pRVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(char *)&pRVar1->type = (char)pRVar4->type;
      pRVar4 = (RGE_Armor_Weapon_Info *)((int)&pRVar4->type + 1);
      pRVar1 = (RGE_Armor_Weapon_Info *)((int)&pRVar1->type + 1);
    }
  }
  this->defense_terrain_bonus = param_1[1].center_tile_req1;
  this->weapon_range = param_1[1].construction_radius_x;
  this->area_effect_range = param_1[1].construction_radius_y;
  this->speed_of_attack = *(float *)&param_1[1].movement_type;
  this->missile_id = param_1[1].attribute_type_held[1];
  this->base_hit_chance = param_1[1].attribute_type_held[2];
  this->break_off_combat = *(uchar *)param_1[1].attribute_amount_held;
  this->fire_missile_at_frame = *(short *)((int)param_1[1].attribute_amount_held + 2);
  this->weapon_offset_x = param_1[1].attribute_amount_held[1];
  this->weapon_offset_y = param_1[1].attribute_amount_held[2];
  this->weapon_offset_z = *(float *)&param_1[1].attribute_max_amount;
  this->area_effect_level = param_1[1].elevation_flag;
  this->minimum_weapon_range = param_1[1].attribute_rot;
  this->orig_armor = *(short *)&param_1[1].multiple_attribute_mod;
  this->orig_weapon = *(short *)((int)&param_1[1].multiple_attribute_mod + 2);
  this->orig_weapon_range = *(float *)param_1[1].attribute_flag;
  this->orig_speed_of_attack = *(float *)&param_1[1].combat_level;
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 00450a00
/* public: virtual void __thiscall RGE_Master_Combat_Object::modify(float,unsigned char) */

void __thiscall
RGE_Master_Combat_Object::modify(RGE_Master_Combat_Object *this,float param_1,uchar param_2)
{
  uchar uVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  RGE_Armor_Weapon_Info *pRVar6;
  uint uVar5;
  
  switch(param_2) {
  case '\b':
    uVar5 = __ftol();
    uVar3 = (ushort)uVar5;
    pRVar6 = this->armor;
    if (pRVar6 == (RGE_Armor_Weapon_Info *)0x0) {
      return;
    }
    sVar4 = this->armor_num;
    break;
  case '\t':
    uVar5 = __ftol();
    uVar3 = (ushort)uVar5;
    pRVar6 = this->weapon;
    if (pRVar6 == (RGE_Armor_Weapon_Info *)0x0) {
      return;
    }
    sVar4 = this->weapon_num;
    break;
  case '\n':
    this->speed_of_attack = param_1;
    return;
  case '\v':
    sVar4 = __ftol();
    this->base_hit_chance = sVar4;
    return;
  case '\f':
    this->weapon_range = param_1;
    return;
  default:
    RGE_Master_Action_Object::modify((RGE_Master_Action_Object *)this,param_1,param_2);
    return;
  case '\x0f':
    uVar1 = __ftol();
    this->base_armor = uVar1;
    return;
  case '\x10':
    bVar2 = __ftol();
    this->missile_id = (ushort)bVar2;
    return;
  case '\x12':
    sVar4 = __ftol();
    this->defense_terrain_bonus = sVar4;
    return;
  }
  uVar5 = uVar5 >> 8 & 0xff;
  if ((int)sVar4 <= (int)uVar5) {
    return;
  }
  pRVar6[uVar5].value = uVar3 & 0xff;
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 00450b40
/* public: virtual void __thiscall RGE_Master_Combat_Object::modify_delta(float,unsigned char) */

void __thiscall
RGE_Master_Combat_Object::modify_delta(RGE_Master_Combat_Object *this,float param_1,uchar param_2)
{
  char cVar1;
  ushort uVar2;
  short sVar3;
  uint uVar5;
  uint uVar6;
  RGE_Armor_Weapon_Info *pRVar7;
  uint uVar4;
  
  switch(param_2) {
  case '\x06':
    this->_padding_ = (int)(param_1 + (float)this->_padding_);
    return;
  default:
    RGE_Master_Action_Object::modify_delta((RGE_Master_Action_Object *)this,param_1,param_2);
    break;
  case '\b':
    uVar4 = __ftol();
    uVar2 = (ushort)uVar4;
    pRVar7 = this->armor;
    if (pRVar7 != (RGE_Armor_Weapon_Info *)0x0) {
      uVar6 = 0;
      if (0 < this->armor_num) {
        uVar5 = 0;
        while ((int)pRVar7[uVar5].type != (uVar4 >> 8 & 0xff)) {
          uVar6 = uVar6 + 1;
          uVar5 = uVar6 & 0xffff;
          if ((int)this->armor_num <= (int)uVar5) {
            return;
          }
        }
LAB_00450c01:
        pRVar7[uVar6 & 0xffff].value = pRVar7[uVar6 & 0xffff].value + (uVar2 & 0xff);
        return;
      }
    }
    break;
  case '\t':
    uVar4 = __ftol();
    uVar2 = (ushort)uVar4;
    pRVar7 = this->weapon;
    if (pRVar7 != (RGE_Armor_Weapon_Info *)0x0) {
      uVar6 = 0;
      if (0 < this->weapon_num) {
        uVar5 = 0;
        while ((int)pRVar7[uVar5].type != (uVar4 >> 8 & 0xff)) {
          uVar6 = uVar6 + 1;
          uVar5 = uVar6 & 0xffff;
          if ((int)this->weapon_num <= (int)uVar5) {
            return;
          }
        }
        goto LAB_00450c01;
      }
    }
    break;
  case '\n':
    this->speed_of_attack = param_1 + this->speed_of_attack;
    return;
  case '\v':
    sVar3 = __ftol();
    this->base_hit_chance = this->base_hit_chance + sVar3;
    return;
  case '\f':
    this->weapon_range = param_1 + this->weapon_range;
    return;
  case '\x0f':
    cVar1 = __ftol();
    this->base_armor = this->base_armor + cVar1;
    return;
  case '\x10':
    sVar3 = __ftol();
    this->missile_id = this->missile_id + sVar3;
    return;
  case '\x12':
    sVar3 = __ftol();
    this->defense_terrain_bonus = sVar3;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 00450d00
/* public: virtual void __thiscall RGE_Master_Combat_Object::modify_percent(float,unsigned char) */

void __thiscall
RGE_Master_Combat_Object::modify_percent(RGE_Master_Combat_Object *this,float param_1,uchar param_2)
{
  uchar uVar1;
  short sVar2;
  
  switch(param_2) {
  case '\x06':
    this->_padding_ = (int)(param_1 * (float)this->_padding_);
    return;
  default:
    RGE_Master_Action_Object::modify_percent((RGE_Master_Action_Object *)this,param_1,param_2);
switchD_00450d1a_caseD_8:
    return;
  case '\b':
  case '\t':
    goto switchD_00450d1a_caseD_8;
  case '\n':
    this->speed_of_attack = param_1 * this->speed_of_attack;
    return;
  case '\v':
    sVar2 = __ftol();
    this->base_hit_chance = sVar2;
    return;
  case '\f':
    this->weapon_range = param_1 * this->weapon_range;
    return;
  case '\x0f':
    uVar1 = __ftol();
    this->base_armor = uVar1;
    return;
  case '\x10':
    sVar2 = __ftol();
    this->missile_id = sVar2;
    return;
  case '\x12':
    sVar2 = __ftol();
    this->defense_terrain_bonus = sVar2;
    return;
  }
}

// --------------------------------------------------

// Function: save
// Address: 00450e20
/* public: virtual void __thiscall RGE_Master_Combat_Object::save(int) */

void __thiscall RGE_Master_Combat_Object::save(RGE_Master_Combat_Object *this,int param_1)
{
  RGE_Sprite *pRVar1;
  int iVar2;
  
  iVar2 = param_1;
  RGE_Master_Action_Object::save((RGE_Master_Action_Object *)this,param_1);
  pRVar1 = this->fight_sprite;
  if (pRVar1 == (RGE_Sprite *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id);
  }
  rge_write(iVar2,&this->base_armor,1);
  rge_write(iVar2,&this->weapon_num,2);
  if (this->weapon != (RGE_Armor_Weapon_Info *)0x0) {
    rge_write(iVar2,this->weapon,(int)this->weapon_num << 2);
  }
  rge_write(iVar2,&this->armor_num,2);
  if (this->armor != (RGE_Armor_Weapon_Info *)0x0) {
    rge_write(iVar2,this->armor,(int)this->armor_num << 2);
  }
  rge_write(iVar2,&this->defense_terrain_bonus,2);
  rge_write(iVar2,&this->weapon_range,4);
  rge_write(iVar2,&this->area_effect_range,4);
  rge_write(iVar2,&this->speed_of_attack,4);
  rge_write(iVar2,&this->missile_id,2);
  rge_write(iVar2,&this->base_hit_chance,2);
  rge_write(iVar2,&this->break_off_combat,1);
  rge_write(iVar2,&this->fire_missile_at_frame,2);
  rge_write(iVar2,&this->weapon_offset_x,4);
  rge_write(iVar2,&this->weapon_offset_y,4);
  rge_write(iVar2,&this->weapon_offset_z,4);
  rge_write(iVar2,&this->area_effect_level,1);
  rge_write(iVar2,&this->minimum_weapon_range,4);
  rge_write(iVar2,&param_1,2);
  rge_write(iVar2,&this->orig_armor,2);
  rge_write(iVar2,&this->orig_weapon,2);
  rge_write(iVar2,&this->orig_weapon_range,4);
  rge_write(iVar2,&this->orig_speed_of_attack,4);
  return;
}

// --------------------------------------------------

// Function: calc_base_damage_ability
// Address: 00451000
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual long __thiscall RGE_Master_Combat_Object::calc_base_damage_ability(class
   RGE_Master_Combat_Object *) */

long __thiscall
RGE_Master_Combat_Object::calc_base_damage_ability
          (RGE_Master_Combat_Object *this,RGE_Master_Combat_Object *param_1)
{
  long lVar1;
  int iVar2;
  int local_8;
  
  local_8 = (int)param_1->weapon_num;
  if (0 < local_8) {
    do {
      iVar2 = (int)this->armor_num;
      if (0 < this->armor_num) {
        do {
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  lVar1 = __ftol();
  return lVar1;
}

// --------------------------------------------------

