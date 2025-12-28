// Class: TRIBE_Action_Wonder
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
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Action_Wonder
// Address: 004d3470
/* public: __thiscall TRIBE_Action_Wonder::TRIBE_Action_Wonder(int,class RGE_Action_Object *) */

TRIBE_Action_Wonder * __thiscall
TRIBE_Action_Wonder::TRIBE_Action_Wonder
          (TRIBE_Action_Wonder *this,int param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,param_2,1);
  *(undefined ***)this = &_vftable_;
                    /* language.dll match for 0x78: "10" */
  *(undefined2 *)&this->field_0x4 = 0x78;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004d34a0
/* public: virtual void * __thiscall TRIBE_Action_Wonder::`vector deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Action_Wonder::_vector_deleting_destructor_(TRIBE_Action_Wonder *this,uint param_1)
{
  ~TRIBE_Action_Wonder(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Action_Wonder
// Address: 004d34c0
/* public: __thiscall TRIBE_Action_Wonder::TRIBE_Action_Wonder(class RGE_Action_Object *) */

TRIBE_Action_Wonder * __thiscall
TRIBE_Action_Wonder::TRIBE_Action_Wonder(TRIBE_Action_Wonder *this,RGE_Action_Object *param_1)
{
  RGE_Action::RGE_Action((RGE_Action *)this,param_1,1);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)&this->field_0x4 = 0x78;
  *(undefined4 *)&this->field_0x2c = 0;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Action_Wonder
// Address: 004d34f0
/* WARNING: Variable defined which should be unmapped: players */
/* public: virtual __thiscall TRIBE_Action_Wonder::~TRIBE_Action_Wonder(void) */

void __thiscall TRIBE_Action_Wonder::~TRIBE_Action_Wonder(TRIBE_Action_Wonder *this)
{
  RGE_Game_World *pRVar1;
  int *piVar2;
  RGE_Player **ppRVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  RGE_Player **ppRVar8;
  undefined4 *unaff_FS_OFFSET;
  RGE_Player **players;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_005601f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)this = &_vftable_;
  local_4 = 0;
  pRVar1 = rge_base_game->world;
  if (pRVar1->game_state == '\0') {
    ppRVar8 = pRVar1->players;
    iVar6 = (int)pRVar1->player_num;
    if ((this->field_0xc == '\x02') && (iVar7 = 1, ppRVar3 = ppRVar8, 1 < iVar6)) {
      do {
        if (iVar7 != *(short *)((*(int **)&this->field_0x8)[3] + 0x4a)) {
          (**(code **)(**(int **)&this->field_0x8 + 0xdc))(ppRVar3[1],1,0xffffffff);
        }
        iVar7 = iVar7 + 1;
        ppRVar3 = ppRVar3 + 1;
      } while (iVar7 < iVar6);
    }
    if (this->field_0xc == '\x06') {
      iVar7 = 1;
      if (1 < iVar6) {
        do {
          ppRVar8 = ppRVar8 + 1;
          if (iVar7 != *(short *)((*(int **)&this->field_0x8)[3] + 0x4a)) {
            (**(code **)(**(int **)&this->field_0x8 + 0xdc))(*ppRVar8,0,0xffffffff);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar6);
      }
      if (rge_base_game->world[1].world_time == 0) {
        bVar4 = false;
        iVar6 = *(int *)(*(int *)&this->field_0x8 + 0xc);
        for (piVar2 = *(int **)(*(int *)(iVar6 + 0x28) + 4); piVar2 != (int *)0x0;
            piVar2 = (int *)piVar2[1]) {
          iVar7 = *piVar2;
          if (((iVar7 != *(int *)&this->field_0x8) &&
              (*(short *)(*(int *)(iVar7 + 8) + 0x10) == 0x114)) && (1 < *(byte *)(iVar7 + 0x48))) {
            bVar4 = true;
            break;
          }
        }
        RGE_Base_Game::reset_countdown_timer(rge_base_game,(int)*(short *)(iVar6 + 0x4a));
        if (bVar4) {
                    /* language.dll match for 0x7d0: "place holder" */
          RGE_Base_Game::set_countdown_timer
                    (rge_base_game,(int)*(short *)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x4a),
                     2000);
        }
      }
    }
    iVar6 = *(int *)&this->field_0x8;
    iVar7 = rge_base_game->_padding_;
    uVar5 = __ftol(0);
    uVar5 = __ftol(uVar5);
                    /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    (**(code **)(iVar7 + 0x40))(0x6e,(int)*(short *)(*(int *)(iVar6 + 0xc) + 0x4a),uVar5);
  }
  local_4 = 0xffffffff;
  RGE_Action::~RGE_Action((RGE_Action *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: first_in_stack
// Address: 004d3690
/* public: virtual void __thiscall TRIBE_Action_Wonder::first_in_stack(unsigned char) */

void __thiscall TRIBE_Action_Wonder::first_in_stack(TRIBE_Action_Wonder *this,uchar param_1)
{
  if (param_1 != '\0') {
    (**(code **)(*(int *)this + 0x5c))(2);
  }
  return;
}

// --------------------------------------------------

// Function: set_state
// Address: 004d36b0
/* public: virtual void __thiscall TRIBE_Action_Wonder::set_state(unsigned char) */

void __thiscall TRIBE_Action_Wonder::set_state(TRIBE_Action_Wonder *this,uchar param_1)
{
  undefined4 uVar1;
  int iVar2;
  RGE_Player **ppRVar3;
  int iVar4;
  
  this->field_0xc = param_1;
  if (param_1 == '\x02') {
    iVar4 = 1;
    iVar2 = (int)rge_base_game->world->player_num;
    ppRVar3 = rge_base_game->world->players;
    if (1 < iVar2) {
      do {
        ppRVar3 = ppRVar3 + 1;
        if (iVar4 != *(short *)((*(int **)&this->field_0x8)[3] + 0x4a)) {
          (**(code **)(**(int **)&this->field_0x8 + 0xd8))(*ppRVar3,1,0xffffffff);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
    iVar2 = *(int *)&this->field_0x8;
    iVar4 = rge_base_game->_padding_;
    uVar1 = __ftol(0);
    uVar1 = __ftol(uVar1);
    (**(code **)(iVar4 + 0x40))(0x6c,(int)*(short *)(*(int *)(iVar2 + 0xc) + 0x4a),uVar1);
  }
  else if (param_1 == '\x06') {
    iVar4 = 1;
    iVar2 = (int)rge_base_game->world->player_num;
    ppRVar3 = rge_base_game->world->players;
    if (1 < iVar2) {
      do {
        ppRVar3 = ppRVar3 + 1;
        if (iVar4 != *(short *)((*(int **)&this->field_0x8)[3] + 0x4a)) {
          (**(code **)(**(int **)&this->field_0x8 + 0xdc))(*ppRVar3,1,0xffffffff);
          (**(code **)(**(int **)&this->field_0x8 + 0xd8))(*ppRVar3,0,0xffffffff);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
    if (rge_base_game->world[1].world_time == 0) {
                    /* language.dll match for 0x7d0: "place holder" */
      RGE_Base_Game::set_countdown_timer
                (rge_base_game,(int)*(short *)(*(int *)(*(int *)&this->field_0x8 + 0xc) + 0x4a),2000
                );
    }
    iVar2 = *(int *)&this->field_0x8;
    iVar4 = rge_base_game->_padding_;
    uVar1 = __ftol(0);
    uVar1 = __ftol(uVar1);
    (**(code **)(iVar4 + 0x40))(0x6d,(int)*(short *)(*(int *)(iVar2 + 0xc) + 0x4a),uVar1);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 004d3810
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall TRIBE_Action_Wonder::update(void) */

uchar __thiscall TRIBE_Action_Wonder::update(TRIBE_Action_Wonder *this)
{
  float fVar1;
  int iVar2;
  RGE_Base_Game *this_00;
  long lVar3;
  
  if (this->field_0xc == '\x02') {
    if (*(char *)(*(int *)&this->field_0x8 + 0x48) == '\x02') {
      (**(code **)(*(int *)this + 0x5c))(6);
      return '\0';
    }
  }
  else if ((this->field_0xc == '\x06') && (*(float *)&this->field_0x2c < _DAT_005753d8)) {
    iVar2 = *(int *)&this->field_0x8;
    fVar1 = *(float *)(*(int *)(*(int *)(iVar2 + 0xc) + 0x3c) + 0x84);
    *(float *)&this->field_0x2c = fVar1 + fVar1 + *(float *)&this->field_0x2c;
    this_00 = rge_base_game;
    if (rge_base_game->world[1].world_time == 0) {
      lVar3 = __ftol();
      RGE_Base_Game::set_countdown_timer
                (this_00,(int)*(short *)(*(int *)(iVar2 + 0xc) + 0x4a),lVar3);
      if (_DAT_005753d8 <= *(float *)&this->field_0x2c) {
        RGE_Player::win_game_now(*(RGE_Player **)(*(int *)&this->field_0x8 + 0xc));
        rge_base_game->world->game_end_condition = 'd';
        return '\0';
      }
    }
  }
  return '\0';
}

// --------------------------------------------------

