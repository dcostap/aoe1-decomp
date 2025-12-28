// Class: RGE_Master_Static_Object
// Size:  0xB8
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
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
//
// Member Layout:
// [0x004] uchar master_type
// [0x008] char * name
// [0x00C] short string_id
// [0x00E] short string_id2
// [0x010] short id
// [0x012] short copy_id
// [0x014] short object_group
// [0x018] RGE_Sprite * sprite
// [0x01C] RGE_Sprite * death_sprite
// [0x020] RGE_Sprite * undead_sprite
// [0x024] uchar undead_flag
// [0x026] short hp
// [0x028] float los
// [0x02C] uchar obj_max
// [0x030] float radius_x
// [0x034] float radius_y
// [0x038] float radius_z
// [0x03C] RGE_Sound * selected_sound
// [0x040] RGE_Sound * created_sound
// [0x044] RGE_Sound * death_sound
// [0x048] short death_spawn_obj_id
// [0x04A] uchar sort_number
// [0x04B] uchar can_be_built_on
// [0x04C] short button_pict
// [0x04E] uchar hide_in_scenario_editor
// [0x050] short portrait_pict
// [0x052] uchar available
// [0x054] short tile_req1
// [0x056] short tile_req2
// [0x058] short center_tile_req1
// [0x05A] short center_tile_req2
// [0x05C] float construction_radius_x
// [0x060] float construction_radius_y
// [0x064] uchar elevation_flag
// [0x065] uchar fog_flag
// [0x066] short terrain
// [0x068] uchar movement_type
// [0x06A] short[3] attribute_type_held (sz: 0x6)
// [0x070] float[3] attribute_amount_held (sz: 0xC)
// [0x07C] short attribute_max_amount
// [0x080] float attribute_rot
// [0x084] float multiple_attribute_mod
// [0x088] uchar[3] attribute_flag
// [0x08B] uchar area_effect_object_level
// [0x08C] uchar combat_level
// [0x08D] uchar select_level
// [0x08E] uchar map_draw_level
// [0x08F] uchar unit_level
// [0x090] uchar map_color
// [0x091] uchar attack_reaction
// [0x092] uchar convert_terrain_flag
// [0x093] uchar damage_sprite_num
// [0x094] RGE_Damage_Sprite_Info * damage_sprites
// [0x098] long help_string_id
// [0x09C] long help_page_id
// [0x0A0] long hotkey_id
// [0x0A4] uchar recyclable
// [0x0A5] uchar track_as_resource
// [0x0A6] uchar create_doppleganger_on_death
// [0x0A7] uchar resource_group
// [0x0A8] uchar draw_flag
// [0x0A9] uchar draw_color
// [0x0AC] float outline_radius_x
// [0x0B0] float outline_radius_y
// [0x0B4] float outline_radius_z
// ----------------------------------------------------------------

// Function: play_command_sound
// Address: 0044fe20
/* public: virtual void __thiscall RGE_Master_Static_Object::play_command_sound(void) */

void __thiscall RGE_Master_Static_Object::play_command_sound(RGE_Master_Static_Object *this)
{
  return;
}

// --------------------------------------------------

// Function: play_move_sound
// Address: 0044fe30
/* public: virtual void __thiscall RGE_Master_Static_Object::play_move_sound(void) */

void __thiscall RGE_Master_Static_Object::play_move_sound(RGE_Master_Static_Object *this)
{
  return;
}

// --------------------------------------------------

// Function: RGE_Master_Static_Object
// Address: 00452120
/* public: __thiscall RGE_Master_Static_Object::RGE_Master_Static_Object(class
   RGE_Master_Static_Object *,int) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Static_Object::RGE_Master_Static_Object
          (RGE_Master_Static_Object *this,RGE_Master_Static_Object *param_1,int param_2)
{
  this->_padding_ = (int)&_vftable_;
  if (param_2 != 0) {
    setup(this,param_1);
  }
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00452150
/* public: virtual void * __thiscall RGE_Master_Static_Object::`scalar deleting destructor'(unsigned
   int) */

void * __thiscall
RGE_Master_Static_Object::_scalar_deleting_destructor_(RGE_Master_Static_Object *this,uint param_1)
{
  ~RGE_Master_Static_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Static_Object
// Address: 00452170
/* public: __thiscall RGE_Master_Static_Object::RGE_Master_Static_Object(int,class RGE_Sprite *
   *,class RGE_Sound * *,int) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Static_Object::RGE_Master_Static_Object
          (RGE_Master_Static_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  this->_padding_ = (int)&_vftable_;
  if (param_4 != 0) {
    setup(this,param_1,param_2,param_3);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Master_Static_Object
// Address: 004521a0
/* public: __thiscall RGE_Master_Static_Object::RGE_Master_Static_Object(struct _iobuf *,class
   RGE_Sprite * *,class RGE_Sound * *,short,int) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Static_Object::RGE_Master_Static_Object
          (RGE_Master_Static_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4,int param_5)
{
  this->_padding_ = (int)&_vftable_;
  if (param_5 != 0) {
    setup(this,param_1,param_2,param_3,param_4);
  }
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 004521e0
/* protected: int __thiscall RGE_Master_Static_Object::setup(class RGE_Master_Static_Object *) */

int __thiscall
RGE_Master_Static_Object::setup(RGE_Master_Static_Object *this,RGE_Master_Static_Object *param_1)
{
  uchar uVar1;
  RGE_Master_Static_Object *pRVar2;
  int iVar3;
  RGE_Damage_Sprite_Info *pRVar4;
  short sVar5;
  short sVar6;
  short *psVar7;
  uchar *puVar8;
  float *pfVar9;
  
  pRVar2 = param_1;
  this->master_type = '\n';
  this->recyclable = param_1->recyclable;
  this->string_id = param_1->string_id;
  this->string_id2 = param_1->string_id2;
  sVar5 = param_1->id;
  this->id = sVar5;
  this->copy_id = sVar5;
  this->object_group = param_1->object_group;
  this->sprite = param_1->sprite;
  this->death_sprite = param_1->death_sprite;
  this->undead_sprite = param_1->undead_sprite;
  this->undead_flag = param_1->undead_flag;
  this->hp = param_1->hp;
  this->los = param_1->los;
  this->obj_max = param_1->obj_max;
  this->radius_x = param_1->radius_x;
  this->radius_y = param_1->radius_y;
  this->radius_z = param_1->radius_z;
  this->created_sound = param_1->created_sound;
  this->death_spawn_obj_id = param_1->death_spawn_obj_id;
  this->sort_number = param_1->sort_number;
  this->can_be_built_on = param_1->can_be_built_on;
  this->button_pict = param_1->button_pict;
  this->hide_in_scenario_editor = param_1->hide_in_scenario_editor;
  this->portrait_pict = param_1->portrait_pict;
  this->available = param_1->available;
  this->tile_req1 = param_1->tile_req1;
  this->tile_req2 = param_1->tile_req2;
  this->center_tile_req1 = param_1->center_tile_req1;
  this->center_tile_req2 = param_1->center_tile_req2;
  this->construction_radius_x = param_1->construction_radius_x;
  this->construction_radius_y = param_1->construction_radius_y;
  this->elevation_flag = param_1->elevation_flag;
  this->fog_flag = param_1->fog_flag;
  this->terrain = param_1->terrain;
  this->movement_type = param_1->movement_type;
  this->attribute_max_amount = param_1->attribute_max_amount;
  this->attribute_rot = param_1->attribute_rot;
  this->area_effect_object_level = param_1->area_effect_object_level;
  this->combat_level = param_1->combat_level;
  this->select_level = param_1->select_level;
  this->map_draw_level = param_1->map_draw_level;
  this->unit_level = param_1->unit_level;
  this->multiple_attribute_mod = param_1->multiple_attribute_mod;
  this->selected_sound = param_1->selected_sound;
  this->death_sound = param_1->death_sound;
  this->attack_reaction = param_1->attack_reaction;
  this->convert_terrain_flag = param_1->convert_terrain_flag;
  this->map_color = param_1->map_color;
  this->help_string_id = param_1->help_string_id;
  this->help_page_id = param_1->help_page_id;
  this->hotkey_id = param_1->hotkey_id;
  this->track_as_resource = param_1->track_as_resource;
  this->create_doppleganger_on_death = param_1->create_doppleganger_on_death;
  this->resource_group = param_1->resource_group;
  this->draw_flag = param_1->draw_flag;
  this->draw_color = param_1->draw_color;
  this->outline_radius_x = param_1->outline_radius_x;
  this->outline_radius_y = param_1->outline_radius_y;
  this->outline_radius_z = param_1->outline_radius_z;
  puVar8 = this->attribute_flag;
  psVar7 = this->attribute_type_held;
  iVar3 = (int)param_1 - (int)this;
  param_1 = (RGE_Master_Static_Object *)&DAT_00000003;
  pfVar9 = this->attribute_amount_held;
  do {
    *psVar7 = *(short *)(iVar3 + (int)psVar7);
    *pfVar9 = *(float *)(iVar3 + -4 + (int)(pfVar9 + 1));
    *puVar8 = puVar8[iVar3];
    psVar7 = psVar7 + 1;
    puVar8 = puVar8 + 1;
    param_1 = (RGE_Master_Static_Object *)((int)&param_1[-1].outline_radius_z + 3);
    pfVar9 = pfVar9 + 1;
  } while (param_1 != (RGE_Master_Static_Object *)0x0);
  uVar1 = pRVar2->damage_sprite_num;
  this->damage_sprite_num = uVar1;
  if (uVar1 == '\0') {
    this->damage_sprites = (RGE_Damage_Sprite_Info *)0x0;
  }
  else {
    pRVar4 = (RGE_Damage_Sprite_Info *)calloc(uVar1,8);
    this->damage_sprites = pRVar4;
    sVar5 = 0;
    if (this->damage_sprite_num != '\0') {
      do {
        sVar6 = sVar5 + 1;
        this->damage_sprites[sVar5].sprite = pRVar2->damage_sprites[sVar5].sprite;
        this->damage_sprites[sVar5].damage_percent = pRVar2->damage_sprites[sVar5].damage_percent;
        this->damage_sprites[sVar5].flag = pRVar2->damage_sprites[sVar5].flag;
        sVar5 = sVar6;
      } while (sVar6 < (short)(ushort)this->damage_sprite_num);
    }
  }
  this->name = (char *)0x0;
  getstring(&this->name,pRVar2->name);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 004524e0
/* WARNING: Variable defined which should be unmapped: temp_damage_sprite */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: int __thiscall RGE_Master_Static_Object::setup(int,class RGE_Sprite * *,class
   RGE_Sound * *) */

int __thiscall
RGE_Master_Static_Object::setup
          (RGE_Master_Static_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  uchar *puVar1;
  int iVar2;
  RGE_Damage_Sprite_Info *pRVar3;
  char *pcVar4;
  RGE_Sound *pRVar5;
  RGE_Sprite *pRVar6;
  short sVar7;
  short sVar8;
  float *pfVar9;
  short *psVar10;
  short temp_damage_sprite;
  short selected_sound_num;
  short death_sound_num;
  short created_sound_num;
  short sprite_num;
  short death_sprite_num;
  short undead_sprite_num;
  short local_c;
  short local_a;
  uchar *local_8;
  int local_4;
  
  iVar2 = param_1;
  this->master_type = '\n';
  rge_read(param_1,&param_1,2);
  rge_read(iVar2,&this->id,2);
  rge_read(iVar2,&this->string_id,2);
  rge_read(iVar2,&this->string_id2,2);
  rge_read(iVar2,&this->object_group,2);
  rge_read(iVar2,&undead_sprite_num,2);
  rge_read(iVar2,&local_c,2);
  rge_read(iVar2,&local_a,2);
  rge_read(iVar2,&this->undead_flag,1);
  rge_read(iVar2,&this->hp,2);
  rge_read(iVar2,&this->los,4);
  rge_read(iVar2,&this->obj_max,1);
  rge_read(iVar2,&this->radius_x,4);
  rge_read(iVar2,&this->radius_y,4);
  rge_read(iVar2,&this->radius_z,4);
  rge_read(iVar2,&death_sprite_num,2);
  rge_read(iVar2,&this->death_spawn_obj_id,2);
  rge_read(iVar2,&this->sort_number,1);
  rge_read(iVar2,&this->can_be_built_on,1);
  rge_read(iVar2,&this->button_pict,2);
  rge_read(iVar2,&this->hide_in_scenario_editor,1);
  rge_read(iVar2,&this->portrait_pict,2);
  rge_read(iVar2,&this->available,1);
  rge_read(iVar2,&this->tile_req1,2);
  rge_read(iVar2,&this->tile_req2,2);
  rge_read(iVar2,&this->center_tile_req1,2);
  rge_read(iVar2,&this->center_tile_req2,2);
  rge_read(iVar2,&this->construction_radius_x,4);
  rge_read(iVar2,&this->construction_radius_y,4);
  rge_read(iVar2,&this->elevation_flag,1);
  rge_read(iVar2,&this->fog_flag,1);
  rge_read(iVar2,&this->terrain,2);
  rge_read(iVar2,&this->movement_type,1);
  rge_read(iVar2,&this->attribute_max_amount,2);
  rge_read(iVar2,&this->attribute_rot,4);
  rge_read(iVar2,&this->area_effect_object_level,1);
  rge_read(iVar2,&this->combat_level,1);
  rge_read(iVar2,&this->select_level,1);
  rge_read(iVar2,&this->map_draw_level,1);
  rge_read(iVar2,&this->unit_level,1);
  rge_read(iVar2,&this->multiple_attribute_mod,4);
  rge_read(iVar2,&this->map_color,1);
  rge_read(iVar2,&this->help_string_id,4);
  rge_read(iVar2,&this->help_page_id,4);
  rge_read(iVar2,&this->hotkey_id,4);
  rge_read(iVar2,&this->recyclable,1);
  rge_read(iVar2,&this->track_as_resource,1);
  rge_read(iVar2,&this->create_doppleganger_on_death,1);
  rge_read(iVar2,&this->resource_group,1);
  if (save_game_version < _DAT_00570610) {
    this->draw_flag = '\0';
    this->draw_color = '\0';
    this->outline_radius_x = this->radius_x;
    this->outline_radius_y = this->radius_y;
    this->outline_radius_z = this->radius_z;
  }
  else {
    rge_read(iVar2,&this->draw_flag,1);
    rge_read(iVar2,&this->draw_color,1);
    rge_read(iVar2,&this->outline_radius_x,4);
    rge_read(iVar2,&this->outline_radius_y,4);
    rge_read(iVar2,&this->outline_radius_z,4);
  }
  local_8 = this->attribute_flag;
  pfVar9 = this->attribute_amount_held;
  psVar10 = this->attribute_type_held;
  local_4 = 3;
  do {
    rge_read(iVar2,psVar10,2);
    rge_read(iVar2,pfVar9,4);
    rge_read(iVar2,local_8,1);
    psVar10 = psVar10 + 1;
    pfVar9 = pfVar9 + 1;
    local_8 = local_8 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  puVar1 = &this->damage_sprite_num;
  rge_read(iVar2,puVar1,1);
  if (*puVar1 == '\0') {
    this->damage_sprites = (RGE_Damage_Sprite_Info *)0x0;
  }
  else {
    pRVar3 = (RGE_Damage_Sprite_Info *)calloc(*puVar1,8);
    this->damage_sprites = pRVar3;
    sVar7 = 0;
    if (*puVar1 != '\0') {
      do {
        rge_read(iVar2,&death_sound_num,2);
        rge_read(iVar2,&this->damage_sprites[sVar7].damage_percent,2);
        rge_read(iVar2,&this->damage_sprites[sVar7].flag,1);
        if (death_sound_num < 0) {
          pRVar6 = (RGE_Sprite *)0x0;
        }
        else {
          pRVar6 = param_2[death_sound_num];
        }
        sVar8 = sVar7 + 1;
        this->damage_sprites[sVar7].sprite = pRVar6;
        sVar7 = sVar8;
      } while (sVar8 < (short)(ushort)this->damage_sprite_num);
    }
  }
  rge_read(iVar2,&created_sound_num,2);
  rge_read(iVar2,&sprite_num,2);
  rge_read(iVar2,&this->attack_reaction,1);
  rge_read(iVar2,&this->convert_terrain_flag,1);
  if ((short)param_1 < 1) {
    this->name = (char *)0x0;
  }
  else {
    pcVar4 = (char *)calloc((int)(short)param_1,1);
    this->name = pcVar4;
    rge_read(iVar2,pcVar4,(int)(short)param_1);
  }
  if (_DAT_00570614 <= save_game_version) {
    rge_read(iVar2,&this->copy_id,2);
  }
  if (created_sound_num < 0) {
    pRVar5 = (RGE_Sound *)0x0;
  }
  else {
    pRVar5 = param_3[created_sound_num];
  }
  this->selected_sound = pRVar5;
  if (sprite_num < 0) {
    pRVar5 = (RGE_Sound *)0x0;
  }
  else {
    pRVar5 = param_3[sprite_num];
  }
  this->death_sound = pRVar5;
  if (death_sprite_num < 0) {
    pRVar5 = (RGE_Sound *)0x0;
  }
  else {
    pRVar5 = param_3[death_sprite_num];
  }
  this->created_sound = pRVar5;
  if (undead_sprite_num < 0) {
    pRVar6 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar6 = param_2[undead_sprite_num];
  }
  this->sprite = pRVar6;
  if (local_c < 0) {
    pRVar6 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar6 = param_2[local_c];
  }
  this->death_sprite = pRVar6;
  if (local_a < 0) {
    this->undead_sprite = (RGE_Sprite *)0x0;
    return 1;
  }
  this->undead_sprite = param_2[local_a];
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 00452b00
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__f__hd: "%hd %f %hd"
// [HELPER] s__hd__hd__hd: "%hd %hd %hd"
// [HELPER] s__hd__hd__hd__hd: "%hd %hd %hd %hd"
// [HELPER] s__s__hd__hd__hd__hd__hd__hd__hd__: "%s %hd %hd %hd %hd %hd %hd %hd %hd %f %hd %f %f %f %hd %hd %hd %hd %hd %hd %h..."
/* WARNING: Variable defined which should be unmapped: temp_area_effect_object_level */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: int __thiscall RGE_Master_Static_Object::setup(struct _iobuf *,class RGE_Sprite *
   *,class RGE_Sound * *,short) */

int __thiscall
RGE_Master_Static_Object::setup
          (RGE_Master_Static_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4)
{
  char cVar1;
  bool bVar2;
  RGE_Damage_Sprite_Info *pRVar3;
  RGE_Sound *pRVar4;
  RGE_Sprite *pRVar5;
  int iVar6;
  short *psVar7;
  uchar *puVar8;
  short sVar9;
  short sVar10;
  float *pfVar11;
  char *pcVar12;
  short temp_area_effect_object_level;
  short temp_combat_level;
  short temp_damage_sprite;
  short temp_select_level;
  short temp_flag;
  short temp_map_draw_level;
  short temp_death_sound;
  short temp_command_level;
  short temp_sprite;
  short temp_terrain;
  short temp_undead_sprite;
  short temp_undead_flag;
  short temp_fog_flag;
  short temp_hide_in_scenario_editor;
  short temp_sort_number;
  short temp_attack_reaction;
  short temp_available;
  short temp_convert_terrain_flag;
  short temp_attribute_flag;
  short temp_map_color;
  short temp_selected_sound;
  short temp_track_as_resource;
  short temp_death_sprite;
  short temp_create_doppleganger_on_death;
  short temp_obj_max;
  short temp_resource_group;
  short temp_movement_type;
  short temp_draw_flag;
  short temp_created_sound;
  short temp_draw_color;
  short temp_can_be_built_on;
  short temp_elevation_flag;
  short temp_damage_percent;
  uchar local_84 [2];
  uchar local_82 [2];
  short temp_damage_sprite_num;
  char temp_name [120];
  
  this->master_type = '\n';
  this->id = param_4;
  fscanf(param_1,s__s__hd__hd__hd__hd__hd__hd__hd__,temp_name + 4,&this->string_id,&this->string_id2
         ,&this->object_group,&temp_undead_sprite,&temp_obj_max,&temp_fog_flag,
         &temp_hide_in_scenario_editor,&this->hp,&this->los,&temp_movement_type,&this->radius_x,
         &this->radius_y,&this->radius_z,&this->death_spawn_obj_id,&temp_available,
         &temp_damage_percent,&this->button_pict,&temp_attack_reaction,&this->portrait_pict,
         &temp_attribute_flag,&this->tile_req1,&this->tile_req2,&this->center_tile_req1,
         &this->center_tile_req2,&this->construction_radius_x,&this->construction_radius_y,local_84,
         &temp_sort_number,&temp_undead_flag,&temp_can_be_built_on,&temp_created_sound,
         &this->attribute_max_amount,&this->multiple_attribute_mod,&this->attribute_rot,
         &temp_damage_sprite,&temp_select_level,&temp_map_draw_level,&temp_command_level,
         &temp_terrain,&temp_track_as_resource,&this->help_string_id,&this->help_page_id,
         &this->hotkey_id,&temp_create_doppleganger_on_death,&temp_resource_group,&temp_draw_flag,
         &temp_draw_color,&temp_elevation_flag,&this->outline_radius_x,&this->outline_radius_y,
         &this->outline_radius_z);
  puVar8 = this->attribute_flag;
  psVar7 = this->attribute_type_held;
  pfVar11 = this->attribute_amount_held;
  _temp_damage_sprite_num = 3;
  do {
    fscanf(param_1,s__hd__f__hd,psVar7,pfVar11,&temp_selected_sound);
    *puVar8 = (uchar)temp_selected_sound;
    pfVar11 = pfVar11 + 1;
    psVar7 = psVar7 + 1;
    puVar8 = puVar8 + 1;
    _temp_damage_sprite_num = _temp_damage_sprite_num + -1;
  } while (_temp_damage_sprite_num != 0);
  fscanf(param_1,s__hd,temp_name);
  this->damage_sprite_num = (uchar)temp_name._0_4_;
  if ((uchar)temp_name._0_4_ == '\0') {
    this->damage_sprites = (RGE_Damage_Sprite_Info *)0x0;
  }
  else {
    pRVar3 = (RGE_Damage_Sprite_Info *)calloc(temp_name._0_4_ & 0xff,8);
    this->damage_sprites = pRVar3;
    sVar9 = 0;
    if (this->damage_sprite_num != '\0') {
      do {
        fscanf(param_1,s__hd__hd__hd,&temp_flag,local_82,&temp_death_sound);
        if (temp_flag < 0) {
          pRVar5 = (RGE_Sprite *)0x0;
        }
        else {
          pRVar5 = param_2[temp_flag];
        }
        sVar10 = sVar9 + 1;
        this->damage_sprites[sVar9].sprite = pRVar5;
        this->damage_sprites[sVar9].damage_percent = local_82[0];
        this->damage_sprites[sVar9].flag = (uchar)temp_death_sound;
        sVar9 = sVar10;
      } while (sVar10 < (short)(ushort)this->damage_sprite_num);
    }
  }
  fscanf(param_1,s__hd__hd__hd__hd,&temp_death_sprite,&temp_sprite,&temp_convert_terrain_flag,
         &temp_map_color);
  if (temp_death_sprite < 0) {
    pRVar4 = (RGE_Sound *)0x0;
  }
  else {
    pRVar4 = param_3[temp_death_sprite];
  }
  this->selected_sound = pRVar4;
  if (temp_sprite < 0) {
    pRVar4 = (RGE_Sound *)0x0;
  }
  else {
    pRVar4 = param_3[temp_sprite];
  }
  this->death_sound = pRVar4;
  if (temp_can_be_built_on < 0) {
    pRVar4 = (RGE_Sound *)0x0;
  }
  else {
    pRVar4 = param_3[temp_can_be_built_on];
  }
  this->created_sound = pRVar4;
  if (temp_undead_sprite < 0) {
    pRVar5 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar5 = param_2[temp_undead_sprite];
  }
  this->sprite = pRVar5;
  if (temp_obj_max < 0) {
    pRVar5 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar5 = param_2[temp_obj_max];
  }
  this->death_sprite = pRVar5;
  if (temp_fog_flag < 0) {
    pRVar5 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar5 = param_2[temp_fog_flag];
  }
  this->undead_sprite = pRVar5;
  this->elevation_flag = local_84[0];
  this->sort_number = (uchar)temp_available;
  this->movement_type = (uchar)temp_created_sound;
  this->fog_flag = (uchar)temp_sort_number;
  this->select_level = (uchar)temp_map_draw_level;
  this->obj_max = (uchar)temp_movement_type;
  bVar2 = this->outline_radius_x == _DAT_00570618;
  this->can_be_built_on = (uchar)temp_damage_percent;
  this->available = (uchar)temp_attribute_flag;
  this->area_effect_object_level = (uchar)temp_damage_sprite;
  this->terrain = (ushort)(byte)temp_undead_flag;
  this->combat_level = (uchar)temp_select_level;
  this->map_draw_level = (uchar)temp_command_level;
  this->attack_reaction = (uchar)temp_convert_terrain_flag;
  this->unit_level = (uchar)temp_terrain;
  this->undead_flag = (uchar)temp_hide_in_scenario_editor;
  this->track_as_resource = (uchar)temp_create_doppleganger_on_death;
  this->hide_in_scenario_editor = (uchar)temp_attack_reaction;
  this->convert_terrain_flag = (uchar)temp_map_color;
  this->draw_flag = (uchar)temp_draw_color;
  this->map_color = (uchar)temp_track_as_resource;
  this->create_doppleganger_on_death = (uchar)temp_resource_group;
  this->resource_group = (uchar)temp_draw_flag;
  this->draw_color = (uchar)temp_elevation_flag;
  if (bVar2) {
    this->outline_radius_x = this->radius_x;
  }
  if (this->outline_radius_y == _DAT_00570618) {
    this->outline_radius_y = this->radius_y;
  }
  if (this->outline_radius_z == _DAT_00570618) {
    this->outline_radius_z = this->radius_z;
  }
  this->recyclable = '\0';
  this->copy_id = this->id;
  if (this->object_group == 0xb) {
    this->recyclable = '\x01';
  }
  iVar6 = -1;
  pcVar12 = temp_name + 4;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  if (0 < (short)(~(ushort)iVar6 - 1)) {
    this->name = (char *)0x0;
    getstring(&this->name,temp_name + 4);
  }
  return 1;
}

// --------------------------------------------------

// Function: ~RGE_Master_Static_Object
// Address: 00452fa0
/* public: virtual __thiscall RGE_Master_Static_Object::~RGE_Master_Static_Object(void) */

void __thiscall RGE_Master_Static_Object::~RGE_Master_Static_Object(RGE_Master_Static_Object *this)
{
  this->_padding_ = (int)&_vftable_;
  if (this->name != (char *)0x0) {
    free(this->name);
    this->name = (char *)0x0;
  }
  if (this->damage_sprites != (RGE_Damage_Sprite_Info *)0x0) {
    free(this->damage_sprites);
    this->damage_sprites = (RGE_Damage_Sprite_Info *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 00452fe0
/* public: virtual class RGE_Static_Object * __thiscall RGE_Master_Static_Object::make_new_obj(class
   RGE_Player *,float,float,float) */

RGE_Static_Object * __thiscall
RGE_Master_Static_Object::make_new_obj
          (RGE_Master_Static_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  RGE_Static_Object *pRVar1;
  float *unaff_FS_OFFSET;
  float local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055da3b;
  *unaff_FS_OFFSET = (float)&local_c;
  if (this->recyclable != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_1->world,this->master_type);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(this,param_1,param_2,param_3,param_4);
      *unaff_FS_OFFSET = param_3;
      return pRVar1;
    }
  }
  pRVar1 = (RGE_Static_Object *)operator_new(0x88);
  local_4 = 0;
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Static_Object::RGE_Static_Object(pRVar1,this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 004530b0
/* public: virtual class RGE_Master_Static_Object * __thiscall
   RGE_Master_Static_Object::make_new_master(void) */

RGE_Master_Static_Object * __thiscall
RGE_Master_Static_Object::make_new_master(RGE_Master_Static_Object *this)
{
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055da5b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Master_Static_Object *)operator_new(0xb8);
  local_4 = 0;
  if (pRVar1 != (RGE_Master_Static_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)RGE_Master_Static_Object(pRVar1,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: copy_obj
// Address: 00453120
/* WARNING: Variable defined which should be unmapped: available2 */
/* public: virtual void __thiscall RGE_Master_Static_Object::copy_obj(class RGE_Master_Static_Object
   *) */

void __thiscall
RGE_Master_Static_Object::copy_obj(RGE_Master_Static_Object *this,RGE_Master_Static_Object *param_1)
{
  char **ppcVar1;
  uchar uVar2;
  uchar uVar3;
  short sVar4;
  short sVar5;
  short *psVar6;
  float *pfVar7;
  uchar *puVar8;
  RGE_Damage_Sprite_Info *pRVar9;
  int iVar10;
  int iVar11;
  uchar available2;
  short copy_id2;
  short hide_in_scenario_editor2;
  short object_type2;
  
  sVar4 = this->id;
  sVar5 = this->copy_id;
  uVar2 = this->available;
  uVar3 = this->hide_in_scenario_editor;
  ppcVar1 = &this->name;
  if (*ppcVar1 != (char *)0x0) {
    free(*ppcVar1);
  }
  this->master_type = param_1->master_type;
  *ppcVar1 = param_1->name;
  this->string_id = param_1->string_id;
  this->string_id2 = param_1->string_id2;
  this->id = param_1->id;
  this->copy_id = param_1->copy_id;
  this->object_group = param_1->object_group;
  this->sprite = param_1->sprite;
  this->death_sprite = param_1->death_sprite;
  this->undead_sprite = param_1->undead_sprite;
  this->undead_flag = param_1->undead_flag;
  this->hp = param_1->hp;
  this->los = param_1->los;
  this->obj_max = param_1->obj_max;
  this->radius_x = param_1->radius_x;
  this->radius_y = param_1->radius_y;
  this->radius_z = param_1->radius_z;
  this->selected_sound = param_1->selected_sound;
  this->created_sound = param_1->created_sound;
  this->death_sound = param_1->death_sound;
  this->death_spawn_obj_id = param_1->death_spawn_obj_id;
  this->sort_number = param_1->sort_number;
  this->can_be_built_on = param_1->can_be_built_on;
  this->button_pict = param_1->button_pict;
  this->hide_in_scenario_editor = param_1->hide_in_scenario_editor;
  this->portrait_pict = param_1->portrait_pict;
  this->available = param_1->available;
  this->tile_req1 = param_1->tile_req1;
  this->tile_req2 = param_1->tile_req2;
  this->center_tile_req1 = param_1->center_tile_req1;
  this->center_tile_req2 = param_1->center_tile_req2;
  this->construction_radius_x = param_1->construction_radius_x;
  this->construction_radius_y = param_1->construction_radius_y;
  this->elevation_flag = param_1->elevation_flag;
  this->fog_flag = param_1->fog_flag;
  this->terrain = param_1->terrain;
  this->movement_type = param_1->movement_type;
  psVar6 = this->attribute_type_held;
  iVar10 = (int)param_1 - (int)this;
  iVar11 = 3;
  do {
    *psVar6 = *(short *)(iVar10 + (int)psVar6);
    psVar6 = psVar6 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  pfVar7 = this->attribute_amount_held;
  iVar11 = 3;
  do {
    *pfVar7 = *(float *)((int)pfVar7 + iVar10);
    pfVar7 = pfVar7 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  this->attribute_max_amount = param_1->attribute_max_amount;
  this->attribute_rot = param_1->attribute_rot;
  this->multiple_attribute_mod = param_1->multiple_attribute_mod;
  puVar8 = this->attribute_flag;
  do {
    *puVar8 = puVar8[iVar10];
    puVar8 = puVar8 + 1;
  } while (puVar8 + (-0x88 - (int)this) < &DAT_00000003);
  this->area_effect_object_level = param_1->area_effect_object_level;
  this->combat_level = param_1->combat_level;
  this->select_level = param_1->select_level;
  this->map_draw_level = param_1->map_draw_level;
  this->unit_level = param_1->unit_level;
  this->map_color = param_1->map_color;
  this->attack_reaction = param_1->attack_reaction;
  this->convert_terrain_flag = param_1->convert_terrain_flag;
  this->damage_sprite_num = param_1->damage_sprite_num;
  this->damage_sprites = param_1->damage_sprites;
  this->help_string_id = param_1->help_string_id;
  this->help_page_id = param_1->help_page_id;
  this->hotkey_id = param_1->hotkey_id;
  this->recyclable = param_1->recyclable;
  this->track_as_resource = param_1->track_as_resource;
  this->create_doppleganger_on_death = param_1->create_doppleganger_on_death;
  this->resource_group = param_1->resource_group;
  this->draw_flag = param_1->draw_flag;
  this->draw_color = param_1->draw_color;
  this->outline_radius_x = param_1->outline_radius_x;
  this->outline_radius_y = param_1->outline_radius_y;
  this->outline_radius_z = param_1->outline_radius_z;
  if (param_1->hide_in_scenario_editor == '\x01') {
    this->copy_id = sVar5;
  }
  this->hide_in_scenario_editor = uVar3;
  param_1->hide_in_scenario_editor = '\x01';
  if (this->damage_sprite_num == '\0') {
    this->damage_sprites = (RGE_Damage_Sprite_Info *)0x0;
  }
  else {
    pRVar9 = (RGE_Damage_Sprite_Info *)calloc(this->damage_sprite_num,8);
    this->damage_sprites = pRVar9;
    iVar10 = 0;
    if (this->damage_sprite_num != '\0') {
      do {
        this->damage_sprites[iVar10].sprite = param_1->damage_sprites[iVar10].sprite;
        this->damage_sprites[iVar10].damage_percent = param_1->damage_sprites[iVar10].damage_percent
        ;
        this->damage_sprites[iVar10].flag = param_1->damage_sprites[iVar10].flag;
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)(uint)this->damage_sprite_num);
    }
  }
  *ppcVar1 = (char *)0x0;
  getstring(ppcVar1,param_1->name);
  this->id = sVar4;
  this->available = uVar2;
  return;
}

// --------------------------------------------------

// Function: modify
// Address: 004534a0
/* public: virtual void __thiscall RGE_Master_Static_Object::modify(float,unsigned char) */

void __thiscall
RGE_Master_Static_Object::modify(RGE_Master_Static_Object *this,float param_1,uchar param_2)
{
  uchar uVar1;
  short sVar2;
  
  switch(param_2) {
  case '\0':
    sVar2 = __ftol();
    this->hp = sVar2;
    return;
  case '\x01':
    this->los = param_1;
    return;
  case '\x02':
    uVar1 = __ftol();
    this->obj_max = uVar1;
    return;
  case '\x03':
    this->radius_x = param_1;
    return;
  case '\x04':
    this->radius_y = param_1;
    return;
  case '\x0e':
    sVar2 = __ftol();
    this->attribute_max_amount = sVar2;
  }
  return;
}

// --------------------------------------------------

// Function: modify_delta
// Address: 00453540
/* public: virtual void __thiscall RGE_Master_Static_Object::modify_delta(float,unsigned char) */

void __thiscall
RGE_Master_Static_Object::modify_delta(RGE_Master_Static_Object *this,float param_1,uchar param_2)
{
  char cVar1;
  short sVar2;
  
  switch(param_2) {
  case '\0':
    sVar2 = __ftol();
    this->hp = this->hp + sVar2;
    return;
  case '\x01':
    this->los = param_1 + this->los;
    return;
  case '\x02':
    cVar1 = __ftol();
    this->obj_max = this->obj_max + cVar1;
    return;
  case '\x03':
    this->radius_x = param_1 + this->radius_x;
    return;
  case '\x04':
    this->radius_y = param_1 + this->radius_y;
    return;
  case '\x0e':
    sVar2 = __ftol();
    this->attribute_max_amount = this->attribute_max_amount + sVar2;
  }
  return;
}

// --------------------------------------------------

// Function: modify_percent
// Address: 004535f0
/* public: virtual void __thiscall RGE_Master_Static_Object::modify_percent(float,unsigned char) */

void __thiscall
RGE_Master_Static_Object::modify_percent(RGE_Master_Static_Object *this,float param_1,uchar param_2)
{
  uchar uVar1;
  short sVar2;
  
  switch(param_2) {
  case '\0':
    sVar2 = __ftol();
    this->hp = sVar2;
    return;
  case '\x01':
    this->los = param_1 * this->los;
    return;
  case '\x02':
    uVar1 = __ftol();
    this->obj_max = uVar1;
    return;
  case '\x03':
    this->radius_x = param_1 * this->radius_x;
    return;
  case '\x04':
    this->radius_y = param_1 * this->radius_y;
    return;
  case '\x0e':
    sVar2 = __ftol();
    this->attribute_max_amount = sVar2;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004536d0
/* WARNING: Variable defined which should be unmapped: name_size */
/* public: virtual void __thiscall RGE_Master_Static_Object::save(int) */

void __thiscall RGE_Master_Static_Object::save(RGE_Master_Static_Object *this,int param_1)
{
  char cVar1;
  uchar uVar2;
  RGE_Sound *pRVar3;
  RGE_Sprite *pRVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_EDX;
  short sVar7;
  float *pfVar8;
  char *pcVar9;
  short *psVar10;
  short name_size;
  short temp_sprite;
  short temp_death_sprite;
  short temp_undead_sprite;
  short created_sound_num;
  undefined4 local_10;
  short selected_sound_num;
  short death_sound_num;
  undefined4 local_4;
  
  iVar5 = param_1;
  uVar6 = 0xffffffff;
  pRVar3 = this->created_sound;
  _temp_death_sprite = 0xffffffff;
  _temp_undead_sprite = 0xffffffff;
  _created_sound_num = 0xffffffff;
  local_10 = 0xffffffff;
  local_4 = 0xffffffff;
  _death_sound_num = 0xffffffff;
  if (pRVar3 != (RGE_Sound *)0x0) {
    local_10 = CONCAT22((short)((uint)pRVar3 >> 0x10),pRVar3->id);
  }
  if (this->selected_sound != (RGE_Sound *)0x0) {
    in_EDX = CONCAT22((short)((uint)in_EDX >> 0x10),this->selected_sound->id);
    _death_sound_num = in_EDX;
  }
  pRVar3 = this->death_sound;
  if (pRVar3 != (RGE_Sound *)0x0) {
    local_4 = CONCAT22((short)((uint)pRVar3 >> 0x10),pRVar3->id);
  }
  if (this->sprite != (RGE_Sprite *)0x0) {
    in_EDX = CONCAT22((short)((uint)in_EDX >> 0x10),this->sprite->id);
    _temp_death_sprite = in_EDX;
  }
  pRVar4 = this->death_sprite;
  if (pRVar4 != (RGE_Sprite *)0x0) {
    _temp_undead_sprite = CONCAT22((short)((uint)pRVar4 >> 0x10),pRVar4->id);
  }
  if (this->undead_sprite != (RGE_Sprite *)0x0) {
    _created_sound_num = CONCAT22((short)((uint)in_EDX >> 0x10),this->undead_sprite->id);
  }
  pcVar9 = this->name;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  _temp_sprite = ~uVar6 - 1;
  if (0 < (short)_temp_sprite) {
    _temp_sprite = ~uVar6;
  }
  rge_write(param_1,&this->master_type,1);
  rge_write(param_1,&temp_sprite,2);
  rge_write(param_1,&this->id,2);
  rge_write(param_1,&this->string_id,2);
  rge_write(param_1,&this->string_id2,2);
  rge_write(param_1,&this->object_group,2);
  rge_write(param_1,&temp_death_sprite,2);
  rge_write(param_1,&temp_undead_sprite,2);
  rge_write(param_1,&created_sound_num,2);
  rge_write(param_1,&this->undead_flag,1);
  rge_write(param_1,&this->hp,2);
  rge_write(param_1,&this->los,4);
  rge_write(param_1,&this->obj_max,1);
  rge_write(param_1,&this->radius_x,4);
  rge_write(param_1,&this->radius_y,4);
  rge_write(param_1,&this->radius_z,4);
  rge_write(param_1,&local_10,2);
  rge_write(param_1,&this->death_spawn_obj_id,2);
  rge_write(param_1,&this->sort_number,1);
  rge_write(param_1,&this->can_be_built_on,1);
  rge_write(param_1,&this->button_pict,2);
  rge_write(param_1,&this->hide_in_scenario_editor,1);
  rge_write(param_1,&this->portrait_pict,2);
  rge_write(param_1,&this->available,1);
  rge_write(param_1,&this->tile_req1,2);
  rge_write(param_1,&this->tile_req2,2);
  rge_write(param_1,&this->center_tile_req1,2);
  rge_write(param_1,&this->center_tile_req2,2);
  rge_write(param_1,&this->construction_radius_x,4);
  rge_write(param_1,&this->construction_radius_y,4);
  rge_write(param_1,&this->elevation_flag,1);
  rge_write(param_1,&this->fog_flag,1);
  rge_write(param_1,&this->terrain,2);
  rge_write(param_1,&this->movement_type,1);
  rge_write(param_1,&this->attribute_max_amount,2);
  rge_write(param_1,&this->attribute_rot,4);
  rge_write(param_1,&this->area_effect_object_level,1);
  rge_write(param_1,&this->combat_level,1);
  rge_write(param_1,&this->select_level,1);
  rge_write(param_1,&this->map_draw_level,1);
  rge_write(param_1,&this->unit_level,1);
  rge_write(param_1,&this->multiple_attribute_mod,4);
  rge_write(param_1,&this->map_color,1);
  rge_write(param_1,&this->help_string_id,4);
  rge_write(param_1,&this->help_page_id,4);
  rge_write(param_1,&this->hotkey_id,4);
  rge_write(param_1,&this->recyclable,1);
  rge_write(param_1,&this->track_as_resource,1);
  rge_write(param_1,&this->create_doppleganger_on_death,1);
  rge_write(param_1,&this->resource_group,1);
  rge_write(param_1,&this->draw_flag,1);
  rge_write(param_1,&this->draw_color,1);
  rge_write(param_1,&this->outline_radius_x,4);
  rge_write(param_1,&this->outline_radius_y,4);
  rge_write(param_1,&this->outline_radius_z,4);
  param_1 = (int)this->attribute_flag;
  pfVar8 = this->attribute_amount_held;
  psVar10 = this->attribute_type_held;
  _selected_sound_num = 3;
  do {
    rge_write(iVar5,psVar10,2);
    rge_write(iVar5,pfVar8,4);
    rge_write(iVar5,(void *)param_1,1);
    psVar10 = psVar10 + 1;
    pfVar8 = pfVar8 + 1;
    param_1 = param_1 + 1;
    _selected_sound_num = _selected_sound_num + -1;
  } while (_selected_sound_num != 0);
  rge_write(iVar5,&this->damage_sprite_num,1);
  uVar2 = this->damage_sprite_num;
  if (uVar2 != '\0') {
    sVar7 = 0;
    if (uVar2 != '\0') {
      do {
        rge_write(iVar5,&(this->damage_sprites[sVar7].sprite)->id,2);
        rge_write(iVar5,&this->damage_sprites[sVar7].damage_percent,2);
        rge_write(iVar5,&this->damage_sprites[sVar7].flag,1);
        sVar7 = sVar7 + 1;
      } while (sVar7 < (short)(ushort)this->damage_sprite_num);
    }
  }
  rge_write(iVar5,&death_sound_num,2);
  rge_write(iVar5,&local_4,2);
  rge_write(iVar5,&this->attack_reaction,1);
  rge_write(iVar5,&this->convert_terrain_flag,1);
  if ((short)_temp_sprite != 0) {
    rge_write(iVar5,this->name,(int)(short)_temp_sprite);
  }
  rge_write(iVar5,&this->copy_id,2);
  return;
}

// --------------------------------------------------

// Function: check_placement
// Address: 00453c40
/* WARNING: Variable defined which should be unmapped: req_terr2 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Master_Static_Object::check_placement(class
   RGE_Player *,float,float,int *,unsigned char,unsigned char,unsigned char,unsigned char,unsigned
   char,unsigned char) */

uchar __thiscall
RGE_Master_Static_Object::check_placement
          (RGE_Master_Static_Object *this,RGE_Player *param_1,float param_2,float param_3,
          int *param_4,uchar param_5,uchar param_6,uchar param_7,uchar param_8,uchar param_9,
          uchar param_10)
{
  ushort uVar1;
  RGE_Map *pRVar2;
  float *pfVar3;
  RGE_Object_Node *pRVar4;
  RGE_Static_Object *pRVar5;
  RGE_Master_Static_Object *pRVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  bool bVar10;
  uchar uVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  ushort uVar16;
  byte *pbVar17;
  int iVar18;
  short sVar19;
  RGE_Object_Node **ppRVar20;
  int iVar21;
  RGE_Tile **ppRVar22;
  int iVar23;
  float fVar24;
  uchar req_terr2;
  RGE_Map *map;
  short x2;
  short edge_y2;
  short edge_y1;
  short sStack_30;
  short sStack_2c;
  short x1;
  float rx;
  float ry;
  float fStack_1c;
  short edge_x1;
  short req_x1;
  float *terrain_table;
  
  pRVar2 = param_1->world->map;
  pfVar3 = param_1->world->terrains[this->terrain];
  if (param_8 == '\0') {
    ry = this->radius_x;
    fStack_1c = this->radius_y;
  }
  else {
    ry = this->construction_radius_x;
    fStack_1c = this->construction_radius_y;
  }
  if ((((param_2 - ry < (float)_DAT_00570620) ||
       (iVar23 = pRVar2->map_width, (float)iVar23 <= (ry + param_2) - _DAT_0057061c)) ||
      (param_3 - fStack_1c < (float)_DAT_00570620)) ||
     (iVar18 = pRVar2->map_height, (float)iVar18 <= (fStack_1c + param_3) - _DAT_0057061c)) {
    return '\a';
  }
  sVar12 = __ftol();
  sVar13 = __ftol();
  sVar14 = __ftol();
  sVar15 = __ftol();
  uVar1 = this->center_tile_req1;
  if ((-1 < (short)uVar1) ||
     (sStack_30 = sVar14, x1 = sVar13, edge_y1 = sVar15, sVar19 = sVar12,
     -1 < this->center_tile_req2)) {
    sStack_30 = __ftol();
    x1 = __ftol();
    uVar16 = (ushort)(pRVar2->map_row_offset[sStack_30][x1].field_0x5 & 0x1f);
    edge_y1 = sStack_30;
    sVar19 = x1;
    if ((uVar16 != uVar1) && (uVar16 != this->center_tile_req2)) {
      return '\x01';
    }
  }
  bVar7 = false;
  bVar10 = false;
  uVar1 = this->tile_req1;
  if ((-1 < (short)uVar1) || (-1 < this->tile_req2)) {
    terrain_table._0_2_ = sVar19 + -1;
    if ((-1 < (short)(sStack_30 + -1)) && (sVar19 <= x1)) {
      pbVar17 = &pRVar2->map_row_offset[(short)(sStack_30 + -1)][sVar19].field_0x5;
      iVar21 = ((int)x1 - (int)sVar19) + 1;
      do {
        if ((*pbVar17 & 0x1f) == uVar1) {
          bVar7 = true;
        }
        if ((ushort)(*pbVar17 & 0x1f) == this->tile_req2) {
          bVar10 = true;
        }
        pbVar17 = pbVar17 + 0x18;
        iVar21 = iVar21 + -1;
      } while (iVar21 != 0);
    }
    if (((short)(x1 + 1) < iVar23) && (sStack_30 <= edge_y1)) {
      ppRVar22 = pRVar2->map_row_offset + sStack_30;
      iVar23 = ((int)edge_y1 - (int)sStack_30) + 1;
      do {
        uVar16 = (ushort)((*ppRVar22)[(short)(x1 + 1)].field_0x5 & 0x1f);
        if (uVar16 == uVar1) {
          bVar7 = true;
        }
        if (uVar16 == this->tile_req2) {
          bVar10 = true;
        }
        ppRVar22 = ppRVar22 + 1;
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
    }
    if (((short)(edge_y1 + 1) < iVar18) && (sVar19 <= x1)) {
      pbVar17 = &pRVar2->map_row_offset[(short)(edge_y1 + 1)][x1].field_0x5;
      iVar23 = ((int)x1 - (int)sVar19) + 1;
      do {
        if ((*pbVar17 & 0x1f) == uVar1) {
          bVar7 = true;
        }
        if ((ushort)(*pbVar17 & 0x1f) == this->tile_req2) {
          bVar10 = true;
        }
        pbVar17 = pbVar17 + -0x18;
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
    }
    if ((-1 < (short)terrain_table) && (sStack_30 <= edge_y1)) {
      ppRVar22 = pRVar2->map_row_offset + edge_y1;
      iVar23 = ((int)edge_y1 - (int)sStack_30) + 1;
      do {
        uVar16 = (ushort)((*ppRVar22)[(short)terrain_table].field_0x5 & 0x1f);
        if (uVar16 == uVar1) {
          bVar7 = true;
        }
        if (uVar16 == this->tile_req2) {
          bVar10 = true;
        }
        ppRVar22 = ppRVar22 + -1;
        iVar23 = iVar23 + -1;
      } while (iVar23 != 0);
    }
    if ((!bVar7) && (!bVar10)) {
      return '\x01';
    }
  }
  bVar7 = false;
  for (; sVar12 <= sVar13; sVar12 = sVar12 + 1) {
    if (sVar14 <= sVar15) {
      iVar23 = (int)sVar12;
      sVar19 = sVar14;
      do {
        iVar18 = (int)sVar19;
        if (pfVar3[(byte)pRVar2->map_row_offset[iVar18][iVar23].field_0x5 & 0x1f] <= _DAT_00570618)
{
          return '\x02';
        }
        if ((param_5 != '\0') &&
           ((rge_base_game->prog_mode == 7 ||
            (uVar11 = RGE_Visible_Map::get_visible(param_1->visible,iVar23,iVar18), uVar11 != '\0'))
           )) {
          bVar7 = true;
        }
        if (param_6 != '\0') {
          uVar11 = pRVar2->map_row_offset[iVar18][iVar23].tile_type;
          if (this->elevation_flag == '\x01') {
            if ((((uVar11 != '\0') && (uVar11 != '\x05')) && (uVar11 != '\a')) &&
               ((uVar11 != '\x06' && (uVar11 != '\b')))) {
              return '\x03';
            }
          }
          else if ((this->elevation_flag == '\x02') && (uVar11 != '\0')) {
            return '\x03';
          }
        }
        sVar19 = sVar19 + 1;
      } while (sVar19 <= sVar15);
    }
  }
  if ((param_5 == '\x01') && (!bVar7)) {
    return '\x05';
  }
  if ((ry <= _DAT_00570618) && (fStack_1c <= _DAT_00570618)) {
    return '\0';
  }
  rx = (float)__ftol();
  sVar12 = __ftol();
  edge_y2 = __ftol();
  sStack_2c = __ftol();
  if (SUB42(rx,0) < 0) {
    rx = 0.0;
  }
  if (pRVar2->map_width <= (int)edge_y2) {
    edge_y2 = (short)pRVar2->map_width + -1;
  }
  if (sVar12 < 0) {
    sVar12 = 0;
  }
  if (pRVar2->map_height <= (int)sStack_2c) {
    sStack_2c = (short)pRVar2->map_height + -1;
  }
  if ((param_10 != '\0') &&
     (((param_9 != '\0' || ((float)_DAT_00570620 < this->radius_z)) && (sVar12 <= sStack_2c)))) {
    do {
      if (SUB42(rx,0) <= edge_y2) {
        ppRVar20 = &pRVar2->map_row_offset[sVar12][SUB42(rx,0)].objects.list;
        fVar24 = rx;
        do {
          for (pRVar4 = *ppRVar20; pRVar4 != (RGE_Object_Node *)0x0; pRVar4 = pRVar4->next) {
            pRVar5 = pRVar4->node;
            if ((pRVar5->object_state < 7) &&
               (((param_9 == '\0' || (pRVar5->master_obj->can_be_built_on != '\x01')) ||
                (this->can_be_built_on != '\0')))) {
              pRVar6 = pRVar5->master_obj;
              if ((((float)_DAT_00570620 < pRVar6->radius_x) &&
                  ((float)_DAT_00570620 < pRVar6->radius_y)) &&
                 ((((float)_DAT_00570620 < pRVar6->radius_z &&
                   ((float)_DAT_00570620 < this->radius_z)) ||
                  ((pRVar6->radius_z <= (float)_DAT_00570620 &&
                   (this->radius_z <= (float)_DAT_00570620)))))) {
                fVar8 = pRVar5->world_y - param_3;
                fVar9 = pRVar5->world_x - param_2;
                if (fVar8 < _DAT_00570618) {
                  fVar8 = -fVar8;
                }
                if (fVar9 < _DAT_00570618) {
                  fVar9 = -fVar9;
                }
                if ((fVar9 < pRVar6->radius_x + ry) && (fVar8 < pRVar6->radius_y + fStack_1c)) {
                  if (param_4 != (int *)0x0) {
                    *param_4 = pRVar5->id;
                  }
                  return '\x06';
                }
              }
            }
          }
          ppRVar20 = ppRVar20 + 6;
          fVar24 = (float)((int)fVar24 + 1);
        } while (SUB42(fVar24,0) <= edge_y2);
      }
      sVar12 = sVar12 + 1;
    } while (sVar12 <= sStack_2c);
  }
  return '\0';
}

// --------------------------------------------------

// Function: make_available
// Address: 004543c0
/* public: void __thiscall RGE_Master_Static_Object::make_available(unsigned char) */

void __thiscall
RGE_Master_Static_Object::make_available(RGE_Master_Static_Object *this,uchar param_1)
{
  this->available = param_1;
  return;
}

// --------------------------------------------------

// Function: alignment
// Address: 004543d0
/* WARNING: Variable defined which should be unmapped: map_w */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Master_Static_Object::alignment(float &,float
   &,class RGE_Game_World *,unsigned char) */

uchar __thiscall
RGE_Master_Static_Object::alignment
          (RGE_Master_Static_Object *this,float *param_1,float *param_2,RGE_Game_World *param_3,
          uchar param_4)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float map_w;
  float map_h;
  
  fVar3 = *param_1 - this->radius_x;
  fVar1 = *param_2 - this->radius_y;
  fVar2 = *param_1 + this->radius_x;
  fVar4 = *param_2 + this->radius_y;
  fVar5 = (float)param_3->map->map_width - _DAT_00570630;
  fVar6 = (float)param_3->map->map_height - _DAT_00570630;
  if (fVar3 < _DAT_00570618) {
    fVar3 = -fVar3;
    fVar2 = fVar2 + fVar3;
    *param_1 = *param_1 + fVar3;
  }
  if (fVar1 < _DAT_00570618) {
    fVar1 = -fVar1;
    fVar4 = fVar4 + fVar1;
    *param_2 = *param_2 + fVar1;
  }
  if (fVar5 <= fVar2) {
    *param_1 = *param_1 + (fVar5 - fVar2);
  }
  if (fVar6 <= fVar4) {
    *param_2 = *param_2 + (fVar6 - fVar4);
  }
  if (param_4 == '\0') {
    return '\x01';
  }
  sVar7 = __ftol();
  fVar1 = (float)(extraout_ST0 - (float10)(int)sVar7);
  sVar7 = __ftol();
  fVar2 = (float)(extraout_ST1 - (float10)(int)sVar7);
  sVar7 = __ftol();
  fVar3 = (float)((float10)_DAT_00570634 - (extraout_ST1_00 - (float10)(int)sVar7));
  sVar7 = __ftol();
  fVar4 = (float)((float10)_DAT_00570634 - (extraout_ST1_01 - (float10)(int)sVar7));
  if (fVar3 + fVar1 < _DAT_00570634) {
    fVar1 = *param_1;
  }
  else if (fVar1 <= fVar3) {
    fVar1 = *param_1 - (_DAT_00570634 - fVar3);
  }
  else {
    fVar1 = (_DAT_00570634 - fVar1) + *param_1;
  }
  if (_DAT_00570634 <= fVar4 + fVar2) {
    if (fVar4 < fVar2) {
      fVar2 = _DAT_00570634 - fVar2;
      fVar3 = *param_2;
      *param_1 = fVar1;
      *param_2 = fVar2 + fVar3;
      return '\x01';
    }
    fVar4 = _DAT_00570634 - fVar4;
    fVar2 = *param_2;
    *param_1 = fVar1;
    *param_2 = fVar2 - fVar4;
    return '\x01';
  }
  fVar2 = *param_2;
  *param_1 = fVar1;
  *param_2 = fVar2;
  return '\x01';
}

// --------------------------------------------------

// Function: alignment_box
// Address: 00454690
/* WARNING: Variable defined which should be unmapped: tx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: unsigned char __thiscall RGE_Master_Static_Object::alignment_box(class RGE_Game_World
   *,float,float,short &,short &,short &,short &,short &,short &,short &,short &) */

uchar __thiscall
RGE_Master_Static_Object::alignment_box
          (RGE_Master_Static_Object *this,RGE_Game_World *param_1,float param_2,float param_3,
          short *param_4,short *param_5,short *param_6,short *param_7,short *param_8,short *param_9,
          short *param_10,short *param_11)
{
  short sVar1;
  float tx;
  
  __ftol();
  __ftol();
  sVar1 = __ftol();
  *param_4 = sVar1;
  sVar1 = __ftol();
  *param_5 = sVar1;
  sVar1 = __ftol();
  *param_6 = sVar1;
  sVar1 = __ftol();
  *param_7 = sVar1;
  sVar1 = __ftol();
  *param_8 = sVar1;
  sVar1 = __ftol();
  *param_9 = sVar1;
  sVar1 = __ftol();
  *param_10 = sVar1;
  sVar1 = __ftol();
  *param_11 = sVar1;
  return '\x01';
}

// --------------------------------------------------

// Function: draw
// Address: 004547f0
/* WARNING: Variable defined which should be unmapped: x1 */
/* public: virtual void __thiscall RGE_Master_Static_Object::draw(class TDrawArea
   *,short,short,class RGE_Color_Table *,long,long,int,unsigned char) */

void __thiscall
RGE_Master_Static_Object::draw
          (RGE_Master_Static_Object *this,TDrawArea *param_1,short param_2,short param_3,
          RGE_Color_Table *param_4,long param_5,long param_6,int param_7,uchar param_8)
{
  RGE_Map *this_00;
  short sVar1;
  short sVar2;
  int iVar3;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  undefined3 in_stack_00000021;
  short x1;
  float rx1;
  float ry1;
  float local_8;
  RGE_Master_Static_Object *local_4;
  
  sVar2 = param_3;
  sVar1 = param_2;
  if (this->sprite != (RGE_Sprite *)0x0) {
    iVar3 = (int)param_3;
    local_4 = this;
    RGE_Sprite::draw(this->sprite,param_5,param_6,(int)param_2,iVar3,(int)param_2,iVar3,param_4,
                     param_1,'\n');
    if (param_7 != 0) {
      ry1 = local_4->outline_radius_x;
      local_8 = local_4->outline_radius_y;
      this_00 = rge_base_game->world->map;
      local_4 = (RGE_Master_Static_Object *)-local_8;
      RGE_Map::get_point(this_00,(short *)((int)&rx1 + 2),(short *)&param_7,ry1,(float)local_4,0.0,
                         sVar1,sVar2);
      RGE_Map::get_point(this_00,(short *)&param_5,(short *)&param_6,ry1,local_8,0.0,sVar1,sVar2);
      ry1 = -ry1;
      RGE_Map::get_point(this_00,(short *)&param_4,(short *)&param_1,ry1,local_8,0.0,sVar1,sVar2);
      RGE_Map::get_point(this_00,&param_2,&param_3,ry1,(float)local_4,0.0,sVar1,sVar2);
      DClipInfo_List::AddGDINode
                (SDI_List,1,iVar3,(int)rx1._2_2_,(int)(short)param_7,(int)(short)param_5,
                 (int)(short)param_6,(int)(short)param_4,(int)(short)param_1,(int)param_2,
                 (int)param_3,10,_param_8 & 0xff,SDI_Object_ID);
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_help_message
// Address: 00454950
/* public: long __thiscall RGE_Master_Static_Object::get_help_message(void) */

long __thiscall RGE_Master_Static_Object::get_help_message(RGE_Master_Static_Object *this)
{
  return this->help_string_id;
}

// --------------------------------------------------

// Function: get_help_page
// Address: 00454960
/* public: long __thiscall RGE_Master_Static_Object::get_help_page(void) */

long __thiscall RGE_Master_Static_Object::get_help_page(RGE_Master_Static_Object *this)
{
  return this->help_page_id;
}

// --------------------------------------------------

// Function: get_hotkey
// Address: 00454970
/* public: long __thiscall RGE_Master_Static_Object::get_hotkey(void) */

long __thiscall RGE_Master_Static_Object::get_hotkey(RGE_Master_Static_Object *this)
{
  return this->hotkey_id;
}

// --------------------------------------------------

// Function: calc_base_damage_ability
// Address: 00454980
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual long __thiscall RGE_Master_Static_Object::calc_base_damage_ability(class
   RGE_Master_Combat_Object *) */

long __thiscall
RGE_Master_Static_Object::calc_base_damage_ability
          (RGE_Master_Static_Object *this,RGE_Master_Combat_Object *param_1)
{
  long lVar1;
  int iVar2;
  
  iVar2 = (int)param_1->weapon_num;
  if (0 < iVar2) {
    do {
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  lVar1 = __ftol();
  return lVar1;
}

// --------------------------------------------------

