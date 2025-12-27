// Class: TRIBE_Player_Tech
// Function: TRIBE_Player_Tech
// Address: 0050c3a5
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall TRIBE_Player_Tech::TRIBE_Player_Tech(int,class TRIBE_Tech *,class RGE_Player
   *,unsigned char) */

TRIBE_Player_Tech * __thiscall
TRIBE_Player_Tech::TRIBE_Player_Tech
          (TRIBE_Player_Tech *this,int param_1,TRIBE_Tech *param_2,RGE_Player *param_3,uchar param_4
          )
{
  Tech_Player_Tree *pTVar1;
  short local_8;
  
  rge_read(param_1,&this->tech_player_tree_num,2);
  this->base_tech = param_2;
  this->owner = param_3;
  if (0 < this->tech_player_tree_num) {
    pTVar1 = (Tech_Player_Tree *)calloc(8,(int)this->tech_player_tree_num);
    this->tech_player_tree = pTVar1;
    for (local_8 = 0; local_8 < this->tech_player_tree_num; local_8 = local_8 + 1) {
      if (_DAT_005766c0 < save_game_version) {
        rge_read(param_1,this->tech_player_tree + local_8,4);
      }
      else {
        rge_read(param_1,this->tech_player_tree + local_8,2);
      }
      rge_read(param_1,&this->tech_player_tree[local_8].state,2);
    }
    if (param_4 != '\0') {
      for (local_8 = 0; local_8 < this->tech_player_tree_num; local_8 = local_8 + 1) {
        if (this->tech_player_tree[local_8].state == 3) {
          this->tech_player_tree[local_8].state = 1;
          do_tech(this,local_8);
        }
      }
      check_for_new_tech(this);
    }
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Player_Tech
// Address: 0050c4fc
/* public: __thiscall TRIBE_Player_Tech::TRIBE_Player_Tech(class TRIBE_Tech *,class RGE_Player
   *,unsigned char) */

TRIBE_Player_Tech * __thiscall
TRIBE_Player_Tech::TRIBE_Player_Tech
          (TRIBE_Player_Tech *this,TRIBE_Tech *param_1,RGE_Player *param_2,uchar param_3)
{
  Tech_Player_Tree *pTVar1;
  
  this->base_tech = param_1;
  this->owner = param_2;
  this->tech_player_tree_num = param_1->tech_tree_num;
  if (0 < this->tech_player_tree_num) {
    pTVar1 = (Tech_Player_Tree *)calloc(8,(int)this->tech_player_tree_num);
    this->tech_player_tree = pTVar1;
  }
  if (param_3 != '\0') {
    check_for_new_tech(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Player_Tech
// Address: 0050c562
/* public: __thiscall TRIBE_Player_Tech::~TRIBE_Player_Tech(void) */

void __thiscall TRIBE_Player_Tech::~TRIBE_Player_Tech(TRIBE_Player_Tech *this)
{
  if (this->tech_player_tree != (Tech_Player_Tree *)0x0) {
    free(this->tech_player_tree);
    this->tech_player_tree = (Tech_Player_Tree *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: get_tech_state
// Address: 0050c58c
/* public: short __thiscall TRIBE_Player_Tech::get_tech_state(short) */

short __thiscall TRIBE_Player_Tech::get_tech_state(TRIBE_Player_Tech *this,short param_1)
{
  return this->tech_player_tree[param_1].state;
}

// --------------------------------------------------

// Function: undo_tech
// Address: 0050c5a7
/* public: unsigned char __thiscall TRIBE_Player_Tech::undo_tech(short) */

uchar __thiscall TRIBE_Player_Tech::undo_tech(TRIBE_Player_Tech *this,short param_1)
{
  bool bVar1;
  
  bVar1 = 0 < this->tech_player_tree[param_1].state;
  if (bVar1) {
    this->tech_player_tree[param_1].state = 0;
    check_for_new_tech(this);
  }
  return bVar1;
}

// --------------------------------------------------

// Function: do_tech
// Address: 0050c5e5
// [HELPER] groups_used: "00000000"
/* public: unsigned char __thiscall TRIBE_Player_Tech::do_tech(short) */

uchar __thiscall TRIBE_Player_Tech::do_tech(TRIBE_Player_Tech *this,short param_1)
{
  uchar uVar1;
  
  if ((this->tech_player_tree[param_1].state < 3) && (-1 < this->tech_player_tree[param_1].state)) {
    this->tech_player_tree[param_1].state = 3;
    TRIBE_Tech::do_tech(this->base_tech,param_1,this->owner);
    check_for_new_tech(this);
    if (param_1 == 0x65) {
      TRIBE_History_Info::add_history_event
                (*(TRIBE_History_Info **)(this->owner[3].groups_used + 0x3e),'\0');
    }
    else if (param_1 == 0x66) {
      TRIBE_History_Info::add_history_event
                (*(TRIBE_History_Info **)(this->owner[3].groups_used + 0x3e),'\x01');
    }
    else if (param_1 == 0x67) {
      TRIBE_History_Info::add_history_event
                (*(TRIBE_History_Info **)(this->owner[3].groups_used + 0x3e),'\x02');
    }
    uVar1 = '\x01';
  }
  else {
    uVar1 = '\0';
  }
  return uVar1;
}

// --------------------------------------------------

// Function: research
// Address: 0050c6ad
/* public: unsigned char __thiscall TRIBE_Player_Tech::research(short,float) */

uchar __thiscall TRIBE_Player_Tech::research(TRIBE_Player_Tech *this,short param_1,float param_2)
{
  uchar uVar1;
  
  if (this->tech_player_tree[param_1].state == 2) {
    this->tech_player_tree[param_1].research_done =
         this->tech_player_tree[param_1].research_done + param_2;
    if (this->tech_player_tree[param_1].research_done <
        (float)(int)this->base_tech->tech_tree[param_1].research) {
      uVar1 = '\x01';
    }
    else {
      do_tech(this,param_1);
      uVar1 = '\0';
    }
  }
  else {
    uVar1 = '\0';
  }
  return uVar1;
}

// --------------------------------------------------

// Function: tech_cost
// Address: 0050c730
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TRIBE_Player_Tech::tech_cost(short,short &,short &,short &,short &,short
   &,short &) */

void __thiscall
TRIBE_Player_Tech::tech_cost
          (TRIBE_Player_Tech *this,short param_1,short *param_2,short *param_3,short *param_4,
          short *param_5,short *param_6,short *param_7)
{
  Tech_Tree *pTVar1;
  short sVar2;
  short sVar3;
  short local_c;
  uchar local_8;
  
  pTVar1 = this->base_tech->tech_tree;
  local_c = 0;
  *param_2 = -1;
  *param_3 = 0;
  *param_4 = -1;
  *param_5 = 0;
  *param_6 = -1;
  *param_7 = 0;
  local_8 = check_tech_cost(this,param_1,(short *)0x0);
  if (this->owner->attributes[0x1d] < (float)_DAT_005766c8) {
    local_8 = '\0';
  }
  if ((pTVar1[param_1].attribute_used[0] != '\0') &&
     (*param_2 = pTVar1[param_1].attribute[0], -1 < *param_2)) {
    *param_3 = pTVar1[param_1].attribute_cost[0];
    if ((this->owner->attributes[*param_2] < (float)(int)*param_3) && (local_8 != '\0')) {
      local_c = *param_3;
      sVar2 = __ftol();
      local_c = local_c - sVar2;
      sVar2 = __ftol();
      *param_3 = sVar2;
    }
  }
  if ((pTVar1[param_1].attribute_used[1] != '\0') &&
     (*param_4 = pTVar1[param_1].attribute[1], -1 < *param_4)) {
    *param_5 = pTVar1[param_1].attribute_cost[1];
    if ((this->owner->attributes[*param_4] < (float)(int)*param_5) && (local_8 != '\0')) {
      sVar2 = *param_5;
      sVar3 = __ftol();
      local_c = local_c + (sVar2 - sVar3);
      sVar2 = __ftol();
      *param_5 = sVar2;
    }
  }
  if ((pTVar1[param_1].attribute_used[2] != '\0') &&
     (*param_6 = pTVar1[param_1].attribute[2], -1 < *param_6)) {
    *param_7 = pTVar1[param_1].attribute_cost[2];
    if ((this->owner->attributes[*param_6] < (float)(int)*param_7) && (local_8 != '\0')) {
      sVar2 = *param_7;
      sVar3 = __ftol();
      local_c = local_c + (sVar2 - sVar3);
      sVar2 = __ftol();
      *param_7 = sVar2;
    }
  }
  if (0 < local_c) {
    if ((*param_2 == 3) || (*param_2 == -1)) {
      *param_2 = 3;
      *param_3 = *param_3 + local_c;
    }
    else if ((*param_4 == 3) || (*param_4 == -1)) {
      *param_4 = 3;
      *param_5 = *param_5 + local_c;
    }
    else if ((*param_6 == 3) || (*param_6 == -1)) {
      *param_6 = 3;
      *param_7 = local_c;
    }
  }
  if (*param_3 < 1) {
    *param_2 = -1;
  }
  if (*param_5 < 1) {
    *param_4 = -1;
  }
  if (*param_7 < 1) {
    *param_6 = -1;
  }
  return;
}

// --------------------------------------------------

// Function: check_tech_cost
// Address: 0050ca9e
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: unsigned char __thiscall TRIBE_Player_Tech::check_tech_cost(short,short *) */

uchar __thiscall
TRIBE_Player_Tech::check_tech_cost(TRIBE_Player_Tech *this,short param_1,short *param_2)
{
  short sVar1;
  Tech_Tree *pTVar2;
  bool bVar3;
  float fVar4;
  uchar uVar5;
  int iVar6;
  int local_1c;
  float local_10;
  
  pTVar2 = this->base_tech->tech_tree;
  local_10 = this->owner->attributes[3];
  bVar3 = (float)_DAT_005766c8 <= this->owner->attributes[0x1d];
  if (!bVar3) {
    local_10 = 0.0;
  }
  if (this->tech_player_tree[param_1].state == 1) {
    for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
      sVar1 = pTVar2[param_1].attribute[local_1c];
      iVar6 = (int)sVar1;
      if ((-1 < iVar6) && (pTVar2[param_1].attribute_used[local_1c] != '\0')) {
        fVar4 = (float)(int)pTVar2[param_1].attribute_cost[local_1c];
        if ((bVar3) && ((iVar6 == 3 && (local_10 = local_10 - fVar4, local_10 < _DAT_005766d0)))) {
          if (param_2 != (short *)0x0) {
            *param_2 = sVar1;
          }
          return '\0';
        }
        if (this->owner->attributes[iVar6] < fVar4) {
          if (local_10 + this->owner->attributes[iVar6] < fVar4) {
            if (param_2 != (short *)0x0) {
              *param_2 = sVar1;
            }
            return '\0';
          }
          local_10 = local_10 - (fVar4 - this->owner->attributes[iVar6]);
        }
      }
    }
    uVar5 = '\x01';
  }
  else {
    if (param_2 != (short *)0x0) {
      *param_2 = -1;
    }
    uVar5 = '\0';
  }
  return uVar5;
}

// --------------------------------------------------

// Function: start_research
// Address: 0050cc25
/* public: unsigned char __thiscall TRIBE_Player_Tech::start_research(short,unsigned char,short *)
    */

uchar __thiscall
TRIBE_Player_Tech::start_research
          (TRIBE_Player_Tech *this,short param_1,uchar param_2,short *param_3)
{
  Tech_Tree *pTVar1;
  float fVar2;
  uchar uVar3;
  int iVar4;
  int local_14;
  
  pTVar1 = this->base_tech->tech_tree;
  uVar3 = check_tech_cost(this,param_1,param_3);
  if (uVar3 == '\0') {
    if (param_3 != (short *)0x0) {
      *param_3 = -1;
    }
    uVar3 = '\0';
  }
  else {
    if (param_2 != '\0') {
      for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
        iVar4 = (int)pTVar1[param_1].attribute[local_14];
        if ((-1 < iVar4) && (pTVar1[param_1].attribute_used[local_14] != '\0')) {
          fVar2 = (float)(int)pTVar1[param_1].attribute_cost[local_14];
          if (fVar2 <= this->owner->attributes[iVar4]) {
            this->owner->attributes[iVar4] = this->owner->attributes[iVar4] - fVar2;
          }
          else {
            this->owner->attributes[3] =
                 this->owner->attributes[3] - (fVar2 - this->owner->attributes[iVar4]);
            this->owner->attributes[iVar4] = 0.0;
          }
        }
      }
      this->tech_player_tree[param_1].state = 2;
    }
    uVar3 = '\x01';
  }
  return uVar3;
}

// --------------------------------------------------

// Function: cancel_research
// Address: 0050cd73
/* public: unsigned char __thiscall TRIBE_Player_Tech::cancel_research(short,unsigned char) */

uchar __thiscall
TRIBE_Player_Tech::cancel_research(TRIBE_Player_Tech *this,short param_1,uchar param_2)
{
  Tech_Tree *pTVar1;
  uchar uVar2;
  short local_c;
  
  pTVar1 = this->base_tech->tech_tree;
  if (this->tech_player_tree[param_1].state == 2) {
    if (param_2 != '\0') {
      for (local_c = 0; local_c < 3; local_c = local_c + 1) {
        if ((-1 < pTVar1[param_1].attribute[local_c]) &&
           (pTVar1[param_1].attribute_used[local_c] != '\0')) {
          this->owner->attributes[pTVar1[param_1].attribute[local_c]] =
               (float)(int)pTVar1[param_1].attribute_cost[local_c] +
               this->owner->attributes[pTVar1[param_1].attribute[local_c]];
        }
      }
    }
    this->tech_player_tree[param_1].state = 1;
    this->tech_player_tree[param_1].research_done = 0.0;
    uVar2 = '\x01';
  }
  else {
    uVar2 = '\0';
  }
  return uVar2;
}

// --------------------------------------------------

// Function: check_for_new_tech
// Address: 0050ce68
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: unsigned char __thiscall TRIBE_Player_Tech::check_for_new_tech(void) */

uchar __thiscall TRIBE_Player_Tech::check_for_new_tech(TRIBE_Player_Tech *this)
{
  Tech_Tree *pTVar1;
  byte bVar2;
  short sVar3;
  short local_1c;
  short local_18;
  short local_c;
  
  pTVar1 = this->base_tech->tech_tree;
  local_c = 0;
  for (local_1c = 0; local_1c < this->tech_player_tree_num; local_1c = local_1c + 1) {
    if ((this->tech_player_tree[local_1c].state < 2) &&
       (-1 < this->tech_player_tree[local_1c].state)) {
      sVar3 = local_c + 1;
      bVar2 = 0;
      for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
        if ((-1 < pTVar1[local_1c].pre_reqs[local_18]) &&
           (this->tech_player_tree[pTVar1[local_1c].pre_reqs[local_18]].state == 3)) {
          bVar2 = bVar2 + 1;
        }
      }
      if ((short)(ushort)bVar2 < pTVar1[local_1c].pre_reqs_required) {
        local_c = sVar3;
        if (0 < this->tech_player_tree[local_1c].state) {
          this->tech_player_tree[local_1c].state = 0;
        }
      }
      else if (this->tech_player_tree[local_1c].research_done <
               (float)(int)pTVar1[local_1c].research) {
        local_c = sVar3;
        if (this->tech_player_tree[local_1c].state < 1) {
          this->tech_player_tree[local_1c].state = 1;
        }
      }
      else {
        do_tech(this,local_1c);
      }
    }
    else if (this->tech_player_tree[local_1c].state == 2) {
      local_c = local_c + 1;
    }
  }
  if ((local_c == 0) && (this->owner->attributes[0x27] == (float)_DAT_005766d8)) {
    this->owner->attributes[0x27] = 1.0;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: save
// Address: 0050d07a
/* public: void __thiscall TRIBE_Player_Tech::save(int) */

void __thiscall TRIBE_Player_Tech::save(TRIBE_Player_Tech *this,int param_1)
{
  short local_8;
  
  rge_write(param_1,&this->tech_player_tree_num,2);
  for (local_8 = 0; local_8 < this->tech_player_tree_num; local_8 = local_8 + 1) {
    rge_write(param_1,this->tech_player_tree + local_8,4);
    rge_write(param_1,&this->tech_player_tree[local_8].state,2);
  }
  return;
}

// --------------------------------------------------

// Function: get_progress
// Address: 0050d0fa
/* public: short __thiscall TRIBE_Player_Tech::get_progress(short) */

short __thiscall TRIBE_Player_Tech::get_progress(TRIBE_Player_Tech *this,short param_1)
{
  short local_8;
  
  if (this->tech_player_tree[param_1].state == 2) {
    local_8 = __ftol((int)this->base_tech->tech_tree[param_1].research);
  }
  else if (this->tech_player_tree[param_1].state == 3) {
    local_8 = 100;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

// --------------------------------------------------

// Function: get_name
// Address: 0050d178
/* public: char * __thiscall TRIBE_Player_Tech::get_name(short) */

char * __thiscall TRIBE_Player_Tech::get_name(TRIBE_Player_Tech *this,short param_1)
{
  return this->base_tech->tech_tree[param_1].name;
}

// --------------------------------------------------

// Function: get_string_id
// Address: 0050d197
/* public: short __thiscall TRIBE_Player_Tech::get_string_id(short) */

short __thiscall TRIBE_Player_Tech::get_string_id(TRIBE_Player_Tech *this,short param_1)
{
  return this->base_tech->tech_tree[param_1].string_id;
}

// --------------------------------------------------

// Function: get_string_id2
// Address: 0050d1b8
/* public: short __thiscall TRIBE_Player_Tech::get_string_id2(short) */

short __thiscall TRIBE_Player_Tech::get_string_id2(TRIBE_Player_Tech *this,short param_1)
{
  return this->base_tech->tech_tree[param_1].string_id2;
}

// --------------------------------------------------

// Function: get_button_location
// Address: 0050d1d9
/* public: unsigned char __thiscall TRIBE_Player_Tech::get_button_location(short) */

uchar __thiscall TRIBE_Player_Tech::get_button_location(TRIBE_Player_Tech *this,short param_1)
{
  return this->base_tech->tech_tree[param_1].button_location;
}

// --------------------------------------------------

// Function: do_rev_tech
// Address: 0050d1f9
/* public: void __thiscall TRIBE_Player_Tech::do_rev_tech(short) */

void __thiscall TRIBE_Player_Tech::do_rev_tech(TRIBE_Player_Tech *this,short param_1)
{
  short sVar1;
  int iVar2;
  int local_c;
  
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    sVar1 = this->base_tech->tech_tree[param_1].pre_reqs[local_c];
    iVar2 = (int)sVar1;
    if ((-1 < iVar2) && (this->tech_player_tree[iVar2].state < 3)) {
      if (-1 < this->tech_player_tree[iVar2].state) {
        do_rev_tech(this,sVar1);
      }
    }
  }
  do_tech(this,param_1);
  return;
}

// --------------------------------------------------

// Function: rev_tech
// Address: 0050d281
/* public: unsigned char __thiscall TRIBE_Player_Tech::rev_tech(short) */

uchar __thiscall TRIBE_Player_Tech::rev_tech(TRIBE_Player_Tech *this,short param_1)
{
  int local_c;
  int local_8;
  
  do_tech(this,param_1);
  for (local_8 = 0; local_8 < this->tech_player_tree_num; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if (this->base_tech->tech_tree[local_8].pre_reqs[local_c] == param_1) {
        do_rev_tech(this,(short)local_8);
      }
    }
  }
  return '\x01';
}

// --------------------------------------------------

// Function: disable
// Address: 0050d306
/* public: void __thiscall TRIBE_Player_Tech::disable(short) */

void __thiscall TRIBE_Player_Tech::disable(TRIBE_Player_Tech *this,short param_1)
{
  int local_8;
  
  if (param_1 < 0) {
    for (local_8 = 0; local_8 < this->tech_player_tree_num; local_8 = local_8 + 1) {
      if (this->tech_player_tree[local_8].state != 3) {
        this->tech_player_tree[local_8].state = -1;
      }
    }
  }
  else if (this->tech_player_tree[param_1].state != 3) {
    this->tech_player_tree[param_1].state = -1;
  }
  return;
}

// --------------------------------------------------

// Function: enable
// Address: 0050d383
/* public: void __thiscall TRIBE_Player_Tech::enable(short) */

void __thiscall TRIBE_Player_Tech::enable(TRIBE_Player_Tech *this,short param_1)
{
  int local_8;
  
  if (param_1 < 0) {
    for (local_8 = 0; local_8 < this->tech_player_tree_num; local_8 = local_8 + 1) {
      if (this->tech_player_tree[local_8].state == -1) {
        this->tech_player_tree[local_8].state = 0;
      }
    }
  }
  else if (this->tech_player_tree[param_1].state == -1) {
    this->tech_player_tree[param_1].state = 0;
  }
  return;
}

// --------------------------------------------------

// Function: get_help_message
// Address: 0050d400
/* public: long __thiscall TRIBE_Player_Tech::get_help_message(short) */

long __thiscall TRIBE_Player_Tech::get_help_message(TRIBE_Player_Tech *this,short param_1)
{
  long lVar1;
  
  lVar1 = TRIBE_Tech::get_help_message(this->base_tech,param_1);
  return lVar1;
}

// --------------------------------------------------

// Function: get_help_page
// Address: 0050d41d
/* public: long __thiscall TRIBE_Player_Tech::get_help_page(short) */

long __thiscall TRIBE_Player_Tech::get_help_page(TRIBE_Player_Tech *this,short param_1)
{
  long lVar1;
  
  lVar1 = TRIBE_Tech::get_help_page(this->base_tech,param_1);
  return lVar1;
}

// --------------------------------------------------

// Function: get_hotkey
// Address: 0050d43a
/* public: long __thiscall TRIBE_Player_Tech::get_hotkey(short) */

long __thiscall TRIBE_Player_Tech::get_hotkey(TRIBE_Player_Tech *this,short param_1)
{
  long lVar1;
  
  lVar1 = TRIBE_Tech::get_hotkey(this->base_tech,param_1);
  return lVar1;
}

// --------------------------------------------------

