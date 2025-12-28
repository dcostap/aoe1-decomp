// Class: TRIBE_Action
// Size:  0x40
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] setup
// [02] setup
// [03] create_action_list
// [04] rehook
// [05] save
// [06] type
// [07] first_in_stack
// [08] inside_obj_update
// [09] idle_update
// [10] update
// [11] stop
// [12] move_to
// [13] work
// [14] attack_response
// [15] relation_response
// [16] copy_obj
// [17] copy_obj_sprites
// [18] get_state_name
// [19] get_target_obj
// [20] get_target_obj2
// [21] set_target_obj
// [22] set_target_obj2
// [23] set_state
// [24] `vector_deleting_destructor'
// [25] loggingHistory
// [26] setLogHistory
// [27] toggleLogHistory
// [28] setHistoryFilename
// [29] loggingCommonHistory
// [30] setLogCommonHistory
// [31] toggleLogCommonHistory
// [32] loadState
// [33] saveState
// [34] gleanState
// [35] processMessage
// [36] update
// [37] setCallbackMessage
// [38] filterOutMessage
// [39] save
// [40] displayBuildList
// [41] loadBuildList
// [42] numberBuiltOrInProgressItemsOfType
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Action
// Address: 004d38e0
TRIBE_Action * __thiscall
TRIBE_Action::TRIBE_Action(TRIBE_Action *this,int param_1,RGE_Action_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560218;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_3 != 0) {
    setup(this,param_1,param_2);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004d3950
void * __thiscall TRIBE_Action::_vector_deleting_destructor_(TRIBE_Action *this,uint param_1)
{
  ~TRIBE_Action(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action
// Address: 004d3970
void __thiscall TRIBE_Action::~TRIBE_Action(TRIBE_Action *this)
{
  RGE_Action_List *this_00;
  
  *(undefined ***)this = &RGE_Action::_vftable_;
  RGE_Action::set_target_obj((RGE_Action *)this,(RGE_Static_Object *)0x0);
  RGE_Action::set_target_obj2((RGE_Action *)this,(RGE_Static_Object *)0x0);
  this_00 = *(RGE_Action_List **)&this->field_0x34;
  if (this_00 != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this_00);
    operator_delete(this_00);
    *(undefined4 *)&this->field_0x34 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: TRIBE_Action
// Address: 004d3980
TRIBE_Action * __thiscall
TRIBE_Action::TRIBE_Action(TRIBE_Action *this,RGE_Action_Object *param_1,int param_2)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560238;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,0);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  if (param_2 != 0) {
    setup(this,param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: setup
// Address: 004d39e0
int __thiscall TRIBE_Action::setup(TRIBE_Action *this,int param_1,RGE_Action_Object *param_2)
{
  int iVar1;
  
  iVar1 = RGE_Action::setup((RGE_Action *)this,param_1,param_2);
  return iVar1;
}

// --------------------------------------------------

// Function: setup
// Address: 004d3a00
int __thiscall TRIBE_Action::setup(TRIBE_Action *this,RGE_Action_Object *param_1)
{
  int iVar1;
  
  iVar1 = RGE_Action::setup((RGE_Action *)this,param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: create_action_list
// Address: 004d3a10
RGE_Action_List * __thiscall
TRIBE_Action::create_action_list(TRIBE_Action *this,RGE_Action_Object *param_1)
{
  TRIBE_Action_List *this_00;
  RGE_Action_List *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056025b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Action_List *)operator_new(0xc);
  local_4 = 0;
  if (this_00 != (TRIBE_Action_List *)0x0) {
    pRVar1 = (RGE_Action_List *)
             TRIBE_Action_List::TRIBE_Action_List(this_00,*(RGE_Action_Object **)&this->field_0x8);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Action_List *)0x0;
}

// --------------------------------------------------

