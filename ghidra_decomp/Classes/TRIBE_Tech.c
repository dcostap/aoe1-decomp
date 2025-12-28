// Class: TRIBE_Tech
// Size:  0xC
//
// Member Layout:
// [0x000] Tech_Tree * tech_tree
// [0x004] short tech_tree_num
// [0x008] TRIBE_World * world
// ----------------------------------------------------------------

// Function: TRIBE_Tech
// Address: 0050b840
/* public: __thiscall TRIBE_Tech::TRIBE_Tech(int,class TRIBE_World *) */

TRIBE_Tech * __thiscall TRIBE_Tech::TRIBE_Tech(TRIBE_Tech *this,int param_1,TRIBE_World *param_2)
{
  Tech_Tree *pTVar1;
  char *pcVar2;
  short local_10;
  short local_c [2];
  short local_8;
  
  this->world = param_2;
  rge_read(param_1,&this->tech_tree_num,2);
  if (this->tech_tree_num < 1) {
    this->tech_tree = (Tech_Tree *)0x0;
  }
  else {
    pTVar1 = (Tech_Tree *)calloc(0x3c,(int)this->tech_tree_num);
    this->tech_tree = pTVar1;
    for (local_8 = 0; local_8 < this->tech_tree_num; local_8 = local_8 + 1) {
      for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
        rge_read(param_1,this->tech_tree[local_8].pre_reqs + local_10,2);
      }
      for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
        rge_read(param_1,this->tech_tree[local_8].attribute + local_10,2);
        rge_read(param_1,this->tech_tree[local_8].attribute_cost + local_10,2);
        rge_read(param_1,this->tech_tree[local_8].attribute_used + local_10,1);
      }
      rge_read(param_1,&this->tech_tree[local_8].pre_reqs_required,2);
      rge_read(param_1,&this->tech_tree[local_8].build_obj_id,2);
      rge_read(param_1,&this->tech_tree[local_8].string_id,2);
      rge_read(param_1,&this->tech_tree[local_8].string_id2,2);
      rge_read(param_1,&this->tech_tree[local_8].research,2);
      rge_read(param_1,&this->tech_tree[local_8].effect,2);
      rge_read(param_1,&this->tech_tree[local_8].track,2);
      rge_read(param_1,&this->tech_tree[local_8].icon,2);
      rge_read(param_1,&this->tech_tree[local_8].button_location,1);
      rge_read(param_1,&this->tech_tree[local_8].help_string_id,4);
      rge_read(param_1,&this->tech_tree[local_8].help_page_id,4);
      rge_read(param_1,&this->tech_tree[local_8].hotkey_id,4);
      rge_read(param_1,local_c,2);
      if (local_c[0] < 1) {
        this->tech_tree[local_8].name = (char *)0x0;
      }
      else {
        pcVar2 = (char *)calloc(1,(int)local_c[0]);
        this->tech_tree[local_8].name = pcVar2;
        rge_read(param_1,this->tech_tree[local_8].name,(int)local_c[0]);
      }
    }
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Tech
// Address: 0050bb84
// [HELPER] s__d__d_00588f78: "%d %d"
// [HELPER] s__hd__hd__d__d__d_00588fb4: "%hd %hd %d %d %d"
// [HELPER] s__hd__hd__hd_00588fa8: "%hd %hd %hd"
// [HELPER] s__s__hd__hd__hd__hd__hd__hd__hd_00588f84: "%s %hd %hd %hd %hd %hd %hd %hd"
/* public: __thiscall TRIBE_Tech::TRIBE_Tech(char *) */

TRIBE_Tech * __thiscall TRIBE_Tech::TRIBE_Tech(TRIBE_Tech *this,char *param_1)
{
  int iVar1;
  Tech_Tree *pTVar2;
  short local_8c [2];
  short local_88;
  char local_84 [100];
  short local_20;
  int local_1c;
  uchar local_18 [4];
  int local_14;
  uchar local_10 [4];
  short local_c [2];
  int local_8;
  
  this->tech_tree = (Tech_Tree *)0x0;
  local_1c = fopen(param_1,&DAT_00588f74);
  if (local_1c != 0) {
    iVar1 = fscanf(local_1c,s__d__d_00588f78,&this->tech_tree_num,local_c);
    if ((iVar1 != -1) && (0 < this->tech_tree_num)) {
      pTVar2 = (Tech_Tree *)calloc(0x3c,(int)this->tech_tree_num);
      this->tech_tree = pTVar2;
      for (local_20 = 0; local_20 < local_c[0]; local_20 = local_20 + 1) {
        fscanf(local_1c,&DAT_00588f80,local_8c);
        fscanf(local_1c,s__s__hd__hd__hd__hd__hd__hd__hd_00588f84,local_84,
               &this->tech_tree[local_8c[0]].pre_reqs_required,
               &this->tech_tree[local_8c[0]].research,&this->tech_tree[local_8c[0]].effect,
               &this->tech_tree[local_8c[0]].track,&this->tech_tree[local_8c[0]].icon,local_18,
               &this->tech_tree[local_8c[0]].build_obj_id);
        this->tech_tree[local_8c[0]].button_location = local_18[0];
        local_8 = strlen(local_84);
        for (local_14 = 0; local_14 < local_8; local_14 = local_14 + 1) {
          if (local_84[local_14] == '_') {
            local_84[local_14] = ' ';
          }
        }
        this->tech_tree[local_8c[0]].name = (char *)0x0;
        getstring(&this->tech_tree[local_8c[0]].name,local_84);
        for (local_88 = 0; local_88 < 4; local_88 = local_88 + 1) {
          fscanf(local_1c,&PTR_aiPathSystem_MGP_costValue_29__208__1_00588fa4,
                 this->tech_tree[local_8c[0]].pre_reqs + local_88);
        }
        for (local_88 = 0; local_88 < 3; local_88 = local_88 + 1) {
          fscanf(local_1c,s__hd__hd__hd_00588fa8,this->tech_tree[local_8c[0]].attribute + local_88,
                 this->tech_tree[local_8c[0]].attribute_cost + local_88,local_10);
          this->tech_tree[local_8c[0]].attribute_used[local_88] = local_10[0];
        }
        fscanf(local_1c,s__hd__hd__d__d__d_00588fb4,&this->tech_tree[local_8c[0]].string_id,
               &this->tech_tree[local_8c[0]].string_id2,&this->tech_tree[local_8c[0]].help_string_id
               ,&this->tech_tree[local_8c[0]].help_page_id,&this->tech_tree[local_8c[0]].hotkey_id);
      }
    }
    fclose(local_1c);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Tech
// Address: 0050bf28
/* public: __thiscall TRIBE_Tech::~TRIBE_Tech(void) */

void __thiscall TRIBE_Tech::~TRIBE_Tech(TRIBE_Tech *this)
{
  int local_8;
  
  if (this->tech_tree != (Tech_Tree *)0x0) {
    for (local_8 = 0; local_8 < this->tech_tree_num; local_8 = local_8 + 1) {
      if (this->tech_tree[local_8].name != (char *)0x0) {
        free(this->tech_tree[local_8].name);
      }
    }
    free(this->tech_tree);
    this->tech_tree = (Tech_Tree *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: do_tech
// Address: 0050bf9c
/* public: unsigned char __thiscall TRIBE_Tech::do_tech(short,class RGE_Player *) */

uchar __thiscall TRIBE_Tech::do_tech(TRIBE_Tech *this,short param_1,RGE_Player *param_2)
{
  if (-1 < this->tech_tree[param_1].effect) {
    (**(code **)(*(int *)this->world->_padding_ + 8))
              (CONCAT22((short)((uint)(param_1 * 0x3c) >> 0x10),this->tech_tree[param_1].effect),
               param_2);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: save
// Address: 0050bfed
/* public: void __thiscall TRIBE_Tech::save(int) */

void __thiscall TRIBE_Tech::save(TRIBE_Tech *this,int param_1)
{
  short local_10;
  short local_c [2];
  short local_8;
  
  rge_write(param_1,&this->tech_tree_num,2);
  for (local_8 = 0; local_8 < this->tech_tree_num; local_8 = local_8 + 1) {
    if (this->tech_tree[local_8].name == (char *)0x0) {
      local_c[0] = 0;
    }
    else {
      local_c[0] = strlen(this->tech_tree[local_8].name);
      local_c[0] = local_c[0] + 1;
    }
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      rge_write(param_1,this->tech_tree[local_8].pre_reqs + local_10,2);
    }
    for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
      rge_write(param_1,this->tech_tree[local_8].attribute + local_10,2);
      rge_write(param_1,this->tech_tree[local_8].attribute_cost + local_10,2);
      rge_write(param_1,this->tech_tree[local_8].attribute_used + local_10,1);
    }
    rge_write(param_1,&this->tech_tree[local_8].pre_reqs_required,2);
    rge_write(param_1,&this->tech_tree[local_8].build_obj_id,2);
    rge_write(param_1,&this->tech_tree[local_8].string_id,2);
    rge_write(param_1,&this->tech_tree[local_8].string_id2,2);
    rge_write(param_1,&this->tech_tree[local_8].research,2);
    rge_write(param_1,&this->tech_tree[local_8].effect,2);
    rge_write(param_1,&this->tech_tree[local_8].track,2);
    rge_write(param_1,&this->tech_tree[local_8].icon,2);
    rge_write(param_1,&this->tech_tree[local_8].button_location,1);
    rge_write(param_1,&this->tech_tree[local_8].help_string_id,4);
    rge_write(param_1,&this->tech_tree[local_8].help_page_id,4);
    rge_write(param_1,&this->tech_tree[local_8].hotkey_id,4);
    rge_write(param_1,local_c,2);
    if (0 < local_c[0]) {
      rge_write(param_1,this->tech_tree[local_8].name,(int)local_c[0]);
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_help_message
// Address: 0050c2fa
/* public: long __thiscall TRIBE_Tech::get_help_message(short) */

long __thiscall TRIBE_Tech::get_help_message(TRIBE_Tech *this,short param_1)
{
  long lVar1;
  
  if ((param_1 < 0) || (this->tech_tree_num < param_1)) {
    lVar1 = -1;
  }
  else {
    lVar1 = this->tech_tree[param_1].help_string_id;
  }
  return lVar1;
}

// --------------------------------------------------

// Function: get_help_page
// Address: 0050c333
/* public: long __thiscall TRIBE_Tech::get_help_page(short) */

long __thiscall TRIBE_Tech::get_help_page(TRIBE_Tech *this,short param_1)
{
  long lVar1;
  
  if ((param_1 < 0) || (this->tech_tree_num < param_1)) {
    lVar1 = -1;
  }
  else {
    lVar1 = this->tech_tree[param_1].help_page_id;
  }
  return lVar1;
}

// --------------------------------------------------

// Function: get_hotkey
// Address: 0050c36c
/* public: long __thiscall TRIBE_Tech::get_hotkey(short) */

long __thiscall TRIBE_Tech::get_hotkey(TRIBE_Tech *this,short param_1)
{
  long lVar1;
  
  if ((param_1 < 0) || (this->tech_tree_num < param_1)) {
    lVar1 = -1;
  }
  else {
    lVar1 = this->tech_tree[param_1].hotkey_id;
  }
  return lVar1;
}

// --------------------------------------------------

