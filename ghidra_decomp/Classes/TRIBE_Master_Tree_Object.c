// Class: TRIBE_Master_Tree_Object
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
// [14] `scalar_deleting_destructor'
// [15] data_load_random_map
// [16] load_random_map
// [17] do_terrain_brush
// [18] do_terrain_brush_stroke
// [19] do_elevation_brush
// [20] do_elevation_brush_stroke
// [21] do_cliff_brush
// [22] do_cliff_brush_stroke
// [23] map_generate
// [24] map_generate2
// [25] save
// [26] delete_cliff
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Master_Tree_Object
// Address: 0050f180
TRIBE_Master_Tree_Object * __thiscall
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
          (TRIBE_Master_Tree_Object *this,TRIBE_Master_Tree_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560fa8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)this,(RGE_Master_Static_Object *)param_1,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_2 != 0) {
    RGE_Master_Static_Object::setup
              ((RGE_Master_Static_Object *)this,(RGE_Master_Static_Object *)param_1);
    this->field_0x4 = 0x5a;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0050f1f0
void * __thiscall
TRIBE_Master_Tree_Object::_scalar_deleting_destructor_(TRIBE_Master_Tree_Object *this,uint param_1)
{
  ~TRIBE_Master_Tree_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Master_Tree_Object
// Address: 0050f210
void __thiscall TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object *this)
{
  *(undefined ***)this = &RGE_Master_Static_Object::_vftable_;
  if (*(int *)&this->field_0x8 != 0) {
    free(*(int *)&this->field_0x8);
    *(undefined4 *)&this->field_0x8 = 0;
  }
  if (*(int *)&this->field_0x94 != 0) {
    free(*(int *)&this->field_0x94);
    *(undefined4 *)&this->field_0x94 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: TRIBE_Master_Tree_Object
// Address: 0050f220
TRIBE_Master_Tree_Object * __thiscall
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
          (TRIBE_Master_Tree_Object *this,int param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560fc8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)this,param_1,param_2,param_3,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_4 != 0) {
    RGE_Master_Static_Object::setup((RGE_Master_Static_Object *)this,param_1,param_2,param_3);
    this->field_0x4 = 0x5a;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Master_Tree_Object
// Address: 0050f2a0
TRIBE_Master_Tree_Object * __thiscall
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
          (TRIBE_Master_Tree_Object *this,_iobuf *param_1,RGE_Sprite **param_2,RGE_Sound **param_3,
          short param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560fe8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)this,param_1,param_2,param_3,param_4,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_5 != 0) {
    RGE_Master_Static_Object::setup
              ((RGE_Master_Static_Object *)this,param_1,param_2,param_3,param_4);
    this->field_0x4 = 0x5a;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: make_new_obj
// Address: 0050f320
RGE_Static_Object * __thiscall
TRIBE_Master_Tree_Object::make_new_obj
          (TRIBE_Master_Tree_Object *this,RGE_Player *param_1,float param_2,float param_3,
          float param_4)
{
  TRIBE_Tree_Object *this_00;
  RGE_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056100b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Tree_Object *)operator_new(0x88);
  local_4 = 0;
  if (this_00 != (TRIBE_Tree_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             TRIBE_Tree_Object::TRIBE_Tree_Object(this_00,this,param_1,param_2,param_3,param_4,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: make_new_master
// Address: 0050f3a0
RGE_Master_Static_Object * __thiscall
TRIBE_Master_Tree_Object::make_new_master(TRIBE_Master_Tree_Object *this)
{
  TRIBE_Master_Tree_Object *this_00;
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056102b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Master_Tree_Object *)operator_new(0xb8);
  local_4 = 0;
  if (this_00 != (TRIBE_Master_Tree_Object *)0x0) {
    pRVar1 = (RGE_Master_Static_Object *)TRIBE_Master_Tree_Object(this_00,this,1);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Master_Static_Object *)0x0;
}

// --------------------------------------------------

