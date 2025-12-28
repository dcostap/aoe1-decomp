// Class: RGE_Task
// Size:  0x4C
//
// Member Layout:
// [0x000] short task_type
// [0x002] short id
// [0x004] uchar is_default
// [0x006] short action_type
// [0x008] short object_group
// [0x00A] short object_id
// [0x00C] uchar combat_level
// [0x00D] uchar combat_level_flag
// [0x00E] short terrain_id
// [0x010] uchar owner_type
// [0x011] uchar holding_attr
// [0x012] uchar state_building
// [0x014] short attribute_type
// [0x016] short attribute_type2
// [0x018] short attribute_type3
// [0x01A] short attribute_type4
// [0x01C] float work_val1
// [0x020] float work_val2
// [0x024] float work_range
// [0x028] uchar search_flag
// [0x02C] float search_wait_time
// [0x030] short work_flag
// [0x032] short work_flag2
// [0x034] RGE_Sprite * move_sprite
// [0x038] RGE_Sprite * work_sprite
// [0x03C] RGE_Sprite * work_sprite2
// [0x040] RGE_Sprite * carry_sprite
// [0x044] RGE_Sound * work_sound
// [0x048] RGE_Sound * work_sound2
// ----------------------------------------------------------------

// Function: RGE_Task
// Address: 00508670
void __thiscall RGE_Task::RGE_Task(RGE_Task *this,short param_1)
{
  this->id = param_1;
  this->task_type = 1;
  this->is_default = '\0';
  this->action_type = 0;
  this->object_group = 0;
  this->object_id = 0;
  this->terrain_id = -1;
  this->attribute_type = -1;
  this->attribute_type2 = -1;
  this->attribute_type3 = -1;
  this->attribute_type4 = -1;
  this->work_val1 = 0.0;
  this->work_val2 = 0.0;
  this->work_range = 0.0;
  this->search_flag = '\0';
  this->search_wait_time = 0.0;
  this->combat_level = '\0';
  this->combat_level_flag = '\0';
  this->work_flag = 0;
  this->work_flag2 = 0;
  this->owner_type = '\0';
  this->holding_attr = '\0';
  this->state_building = '\0';
  this->move_sprite = (RGE_Sprite *)0x0;
  this->work_sprite = (RGE_Sprite *)0x0;
  this->work_sprite2 = (RGE_Sprite *)0x0;
  this->carry_sprite = (RGE_Sprite *)0x0;
  this->work_sound = (RGE_Sound *)0x0;
  this->work_sound2 = (RGE_Sound *)0x0;
  return;
}

// --------------------------------------------------

// Function: ~RGE_Task
// Address: 005086f0
void __thiscall RGE_Task::~RGE_Task(RGE_Task *this)
{
  return;
}

// --------------------------------------------------

// Function: copy
// Address: 00508700
void __thiscall RGE_Task::copy(RGE_Task *this,RGE_Task *param_1)
{
  this->is_default = param_1->is_default;
  this->action_type = param_1->action_type;
  this->object_group = param_1->object_group;
  this->object_id = param_1->object_id;
  this->terrain_id = param_1->terrain_id;
  this->attribute_type = param_1->attribute_type;
  this->attribute_type2 = param_1->attribute_type2;
  this->attribute_type3 = param_1->attribute_type3;
  this->attribute_type4 = param_1->attribute_type4;
  this->work_val1 = param_1->work_val1;
  this->work_val2 = param_1->work_val2;
  this->work_range = param_1->work_range;
  this->search_flag = param_1->search_flag;
  this->search_wait_time = param_1->search_wait_time;
  this->combat_level = param_1->combat_level;
  this->combat_level_flag = param_1->combat_level_flag;
  this->work_flag = param_1->work_flag;
  this->work_flag2 = param_1->work_flag2;
  this->owner_type = param_1->owner_type;
  this->holding_attr = param_1->holding_attr;
  this->state_building = param_1->state_building;
  this->move_sprite = param_1->move_sprite;
  this->work_sprite = param_1->work_sprite;
  this->work_sprite2 = param_1->work_sprite2;
  this->carry_sprite = param_1->carry_sprite;
  this->work_sound = param_1->work_sound;
  this->work_sound2 = param_1->work_sound2;
  return;
}

// --------------------------------------------------

// Function: load
// Address: 005087c0
void __thiscall RGE_Task::load(RGE_Task *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  int iVar1;
  RGE_Sprite **ppRVar2;
  RGE_Sound **ppRVar3;
  RGE_Sprite *pRVar4;
  RGE_Sound *pRVar5;
  
  iVar1 = param_1;
  rge_read(param_1,&this->id,2);
  rge_read(iVar1,&this->is_default,1);
  rge_read(iVar1,&this->action_type,2);
  rge_read(iVar1,&this->object_group,2);
  rge_read(iVar1,&this->object_id,2);
  rge_read(iVar1,&this->terrain_id,2);
  rge_read(iVar1,&this->attribute_type,2);
  rge_read(iVar1,&this->attribute_type2,2);
  rge_read(iVar1,&this->attribute_type3,2);
  rge_read(iVar1,&this->attribute_type4,2);
  rge_read(iVar1,&this->work_val1,4);
  rge_read(iVar1,&this->work_val2,4);
  rge_read(iVar1,&this->work_range,4);
  rge_read(iVar1,&this->search_flag,1);
  rge_read(iVar1,&this->search_wait_time,4);
  rge_read(iVar1,&this->combat_level,1);
  rge_read(iVar1,&this->combat_level_flag,1);
  rge_read(iVar1,&this->work_flag,2);
  rge_read(iVar1,&this->work_flag2,2);
  rge_read(iVar1,&this->owner_type,1);
  rge_read(iVar1,&this->holding_attr,1);
  rge_read(iVar1,&this->state_building,1);
  rge_read(iVar1,&param_1,2);
  ppRVar2 = param_2;
  if ((short)param_1 == -1) {
    pRVar4 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar4 = param_2[(short)param_1];
  }
  this->move_sprite = pRVar4;
  rge_read(iVar1,&param_1,2);
  if ((short)param_1 == -1) {
    pRVar4 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar4 = ppRVar2[(short)param_1];
  }
  this->work_sprite = pRVar4;
  rge_read(iVar1,&param_1,2);
  if ((short)param_1 == -1) {
    pRVar4 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar4 = ppRVar2[(short)param_1];
  }
  this->work_sprite2 = pRVar4;
  rge_read(iVar1,&param_1,2);
  if ((short)param_1 == -1) {
    pRVar4 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar4 = ppRVar2[(short)param_1];
  }
  this->carry_sprite = pRVar4;
  rge_read(iVar1,&param_1,2);
  ppRVar3 = param_3;
  if ((short)param_1 == -1) {
    pRVar5 = (RGE_Sound *)0x0;
  }
  else {
    pRVar5 = param_3[(short)param_1];
  }
  this->work_sound = pRVar5;
  rge_read(iVar1,&param_1,2);
  if ((short)param_1 == -1) {
    this->work_sound2 = (RGE_Sound *)0x0;
    return;
  }
  this->work_sound2 = ppRVar3[(short)param_1];
  return;
}

// --------------------------------------------------

// Function: load
// Address: 00508a20
// [HELPER] s__hd__hd__hd__hd__hd__hd__hd__hd_: "%hd %hd %hd %hd %hd %hd %hd %hd %hd"
void __thiscall
RGE_Task::load(RGE_Task *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3)
{
  RGE_Sprite *pRVar1;
  RGE_Sound *pRVar2;
  short temp_combat_level;
  short temp_combat_level_flag;
  short temp_search_flag;
  short temp_owner_type;
  short temp_holding_attr;
  short temp_state_building;
  short move_sprite_id;
  short work_sprite_id;
  short work_sprite2_id;
  short carry_sprite_id;
  short work_sound_id;
  short work_sound2_id;
  short local_4;
  short local_2;
  
  fscanf(param_1,s__hd__hd__hd__hd__hd__hd__hd__hd_,&this->id,&param_1,&this->action_type,
         &this->object_group,&this->object_id,&this->terrain_id,&this->attribute_type,
         &this->attribute_type2,&this->attribute_type3,&this->attribute_type4,&this->work_val1,
         &this->work_val2,&this->work_range,&temp_holding_attr,&this->search_wait_time,
         &temp_search_flag,&temp_owner_type,&this->work_flag,&this->work_flag2,&temp_state_building,
         &move_sprite_id,&work_sprite_id,&work_sprite2_id,&carry_sprite_id,&work_sound_id,
         &work_sound2_id,&local_4,&local_2);
  this->is_default = (uchar)param_1;
  this->combat_level = (uchar)temp_search_flag;
  this->combat_level_flag = (uchar)temp_owner_type;
  this->search_flag = (uchar)temp_holding_attr;
  this->owner_type = (uchar)temp_state_building;
  this->holding_attr = (uchar)move_sprite_id;
  this->state_building = (uchar)work_sprite_id;
  if (work_sprite2_id == -1) {
    pRVar1 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar1 = param_2[work_sprite2_id];
  }
  this->move_sprite = pRVar1;
  if (carry_sprite_id == -1) {
    pRVar1 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar1 = param_2[carry_sprite_id];
  }
  this->work_sprite = pRVar1;
  if (work_sound_id == -1) {
    pRVar1 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar1 = param_2[work_sound_id];
  }
  this->work_sprite2 = pRVar1;
  if (work_sound2_id == -1) {
    pRVar1 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar1 = param_2[work_sound2_id];
  }
  this->carry_sprite = pRVar1;
  if (local_4 == -1) {
    pRVar2 = (RGE_Sound *)0x0;
  }
  else {
    pRVar2 = param_3[local_4];
  }
  this->work_sound = pRVar2;
  if (local_2 == -1) {
    this->work_sound2 = (RGE_Sound *)0x0;
    return;
  }
  this->work_sound2 = param_3[local_2];
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00508bb0
void __thiscall RGE_Task::save(RGE_Task *this,int param_1)
{
  RGE_Sprite *pRVar1;
  RGE_Sound *pRVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  
  iVar3 = param_1;
  rge_write(param_1,this,2);
  rge_write(iVar3,&this->id,2);
  rge_write(iVar3,&this->is_default,1);
  rge_write(iVar3,&this->action_type,2);
  rge_write(iVar3,&this->object_group,2);
  rge_write(iVar3,&this->object_id,2);
  rge_write(iVar3,&this->terrain_id,2);
  rge_write(iVar3,&this->attribute_type,2);
  rge_write(iVar3,&this->attribute_type2,2);
  rge_write(iVar3,&this->attribute_type3,2);
  rge_write(iVar3,&this->attribute_type4,2);
  rge_write(iVar3,&this->work_val1,4);
  rge_write(iVar3,&this->work_val2,4);
  rge_write(iVar3,&this->work_range,4);
  rge_write(iVar3,&this->search_flag,1);
  rge_write(iVar3,&this->search_wait_time,4);
  rge_write(iVar3,&this->combat_level,1);
  rge_write(iVar3,&this->combat_level_flag,1);
  rge_write(iVar3,&this->work_flag,2);
  rge_write(iVar3,&this->work_flag2,2);
  rge_write(iVar3,&this->owner_type,1);
  rge_write(iVar3,&this->holding_attr,1);
  rge_write(iVar3,&this->state_building,1);
  if (this->move_sprite == (RGE_Sprite *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = CONCAT22(extraout_var,this->move_sprite->id);
  }
  rge_write(iVar3,&param_1,2);
  pRVar1 = this->work_sprite;
  if (pRVar1 == (RGE_Sprite *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = CONCAT22((short)((uint)pRVar1 >> 0x10),pRVar1->id);
  }
  rge_write(iVar3,&param_1,2);
  if (this->work_sprite2 == (RGE_Sprite *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = CONCAT22(extraout_var_01,this->work_sprite2->id);
  }
  rge_write(iVar3,&param_1,2);
  if (this->carry_sprite == (RGE_Sprite *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = CONCAT22(extraout_var_00,this->carry_sprite->id);
  }
  rge_write(iVar3,&param_1,2);
  pRVar2 = this->work_sound;
  if (pRVar2 == (RGE_Sound *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = CONCAT22((short)((uint)pRVar2 >> 0x10),pRVar2->id);
  }
  rge_write(iVar3,&param_1,2);
  if (this->work_sound2 == (RGE_Sound *)0x0) {
    param_1 = -1;
  }
  else {
    param_1 = CONCAT22(extraout_var_02,this->work_sound2->id);
  }
  rge_write(iVar3,&param_1,2);
  return;
}

// --------------------------------------------------

