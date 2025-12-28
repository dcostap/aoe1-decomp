// Class: TRIBE_Scenario_Header
// Size:  0x1C
//
// VTable Layout:
// [00] get_size
// [01] save
// [02] get_object_pointer
// [03] `vector_deleting_destructor'
// [04] rehook
// [05] save
//
// Member Layout:
// [0x014] int any_sp_victory
// [0x018] int active_player_count
// ----------------------------------------------------------------

// Function: TRIBE_Scenario_Header
// Address: 0052a990
/* public: __thiscall TRIBE_Scenario_Header::TRIBE_Scenario_Header(class T_Scenario *) */

TRIBE_Scenario_Header * __thiscall
TRIBE_Scenario_Header::TRIBE_Scenario_Header(TRIBE_Scenario_Header *this,T_Scenario *param_1)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561848;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Scenario_Header::RGE_Scenario_Header((RGE_Scenario_Header *)this,(RGE_Scenario *)param_1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  iVar1 = T_Scenario::any_sp_victory(param_1);
  this->any_sp_victory = iVar1;
  iVar1 = RGE_Scenario::active_player_count((RGE_Scenario *)param_1);
  this->active_player_count = iVar1;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Scenario_Header
// Address: 0052a9f0
/* public: __thiscall TRIBE_Scenario_Header::TRIBE_Scenario_Header(int) */

TRIBE_Scenario_Header * __thiscall
TRIBE_Scenario_Header::TRIBE_Scenario_Header(TRIBE_Scenario_Header *this,int param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561868;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Scenario_Header::RGE_Scenario_Header((RGE_Scenario_Header *)this,param_1);
  local_4 = 0;
  this->_padding_ = (int)&_vftable_;
  this->any_sp_victory = 0;
  this->active_player_count = 0;
  if (this->_padding_ == 0) {
    rge_read_uncompressed(param_1,&this->any_sp_victory,4);
    rge_read_uncompressed(param_1,&this->active_player_count,4);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: get_size
// Address: 0052aa70
/* public: virtual long __thiscall TRIBE_Scenario_Header::get_size(void) */

long __thiscall TRIBE_Scenario_Header::get_size(TRIBE_Scenario_Header *this)
{
  long lVar1;
  
  lVar1 = RGE_Scenario_Header::get_size((RGE_Scenario_Header *)this);
  return lVar1 + 8;
}

// --------------------------------------------------

// Function: save
// Address: 0052aa80
/* public: virtual void __thiscall TRIBE_Scenario_Header::save(int) */

void __thiscall TRIBE_Scenario_Header::save(TRIBE_Scenario_Header *this,int param_1)
{
  RGE_Scenario_Header::save((RGE_Scenario_Header *)this,param_1);
  rge_write_uncompressed(param_1,&this->any_sp_victory,4);
  rge_write_uncompressed(param_1,&this->active_player_count,4);
  return;
}

// --------------------------------------------------

