// Class: TRIBE_Player
// Function: TRIBE_Player
// Address: 00511bd0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall TRIBE_Player::TRIBE_Player(int,class TRIBE_World *,unsigned char) */

TRIBE_Player * __thiscall
TRIBE_Player::TRIBE_Player(TRIBE_Player *this,int param_1,TRIBE_World *param_2,uchar param_3)
{
  undefined1 uVar1;
  TRIBE_Player_Tech *pTVar2;
  TRIBE_History_Info *pTVar3;
  int iVar4;
  TribeMainDecisionAIModule *pTVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined3 in_stack_0000000d;
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561154;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Player::RGE_Player((RGE_Player *)this,param_1,(RGE_Game_World *)param_2,param_3);
  local_4 = 0;
  this->playerAI = (TribeMainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  rge_read(param_1,&this->_padding_,1);
  rge_read(param_1,&this->update_count,4);
  rge_read(param_1,&this->updateCountNeedHelp,4);
  rge_read(param_1,&this->fog_update,4);
  rge_read(param_1,&this->update_time,4);
  _param_3 = (TRIBE_History_Info *)operator_new(0x10);
  local_4._0_1_ = 1;
  if (_param_3 == (TRIBE_History_Info *)0x0) {
    pTVar2 = (TRIBE_Player_Tech *)0x0;
  }
  else {
    pTVar2 = (TRIBE_Player_Tech *)
             TRIBE_Player_Tech::TRIBE_Player_Tech
                       ((TRIBE_Player_Tech *)_param_3,param_1,param_2->tech,(RGE_Player *)this,'\0')
    ;
  }
  this->tech_tree = pTVar2;
  local_4._0_1_ = 0;
  uVar1 = (undefined1)local_4;
  local_4._0_1_ = 0;
  if (save_game_version <= _DAT_00576818) {
    this->update_history_count = 0;
    local_4._0_1_ = uVar1;
    _param_3 = (TRIBE_History_Info *)operator_new(0x14);
    local_4 = CONCAT31(local_4._1_3_,3);
    if (_param_3 != (TRIBE_History_Info *)0x0) {
      pTVar3 = (TRIBE_History_Info *)TRIBE_History_Info::TRIBE_History_Info(_param_3,-1);
      goto LAB_00511d13;
    }
  }
  else {
    rge_read(param_1,&this->update_history_count,4);
    _param_3 = (TRIBE_History_Info *)operator_new(0x14);
    local_4 = CONCAT31(local_4._1_3_,2);
    if (_param_3 != (TRIBE_History_Info *)0x0) {
      pTVar3 = (TRIBE_History_Info *)TRIBE_History_Info::TRIBE_History_Info(_param_3,param_1);
      goto LAB_00511d13;
    }
  }
  pTVar3 = (TRIBE_History_Info *)0x0;
LAB_00511d13:
  this->history = pTVar3;
  local_4 = local_4 & 0xffffff00;
  if (save_game_version < _DAT_0057681c) {
    this->ruin_held_time = -1.0;
    this->artifact_held_time = -1.0;
  }
  else {
    rge_read(param_1,&this->ruin_held_time,4);
    rge_read(param_1,&this->artifact_held_time,4);
  }
  if ((char)this->_padding_ == '\x03') {
    _param_3 = (TRIBE_History_Info *)0x1;
    if (_DAT_00576820 <= save_game_version) {
      rge_read(param_1,&param_3,4);
    }
    iVar4 = TCommunications_Handler::IsHost(comm);
    if ((iVar4 == 1) && (_param_3 == (TRIBE_History_Info *)0x1)) {
      pTVar5 = (TribeMainDecisionAIModule *)operator_new(0x125c8);
      local_4 = CONCAT31(local_4._1_3_,4);
      if (pTVar5 == (TribeMainDecisionAIModule *)0x0) {
        pTVar5 = (TribeMainDecisionAIModule *)0x0;
      }
      else {
        pTVar5 = (TribeMainDecisionAIModule *)
                 TribeMainDecisionAIModule::TribeMainDecisionAIModule
                           (pTVar5,(int)*(short *)((int)&this->_padding_ + 2),
                            (char *)this->_padding_,this,param_1);
      }
      this->playerAI = pTVar5;
    }
    this->_padding_ = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00511e00
/* public: virtual void * __thiscall TRIBE_Player::`vector deleting destructor'(unsigned int) */

void * __thiscall TRIBE_Player::_vector_deleting_destructor_(TRIBE_Player *this,uint param_1)
{
  ~TRIBE_Player(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TRIBE_Player
// Address: 00511e20
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
/* public: __thiscall TRIBE_Player::TRIBE_Player(class TRIBE_World *,class RGE_Master_Player
   *,unsigned char,char *,unsigned char,unsigned char,unsigned char,char *,char *,char *) */

TRIBE_Player * __thiscall
TRIBE_Player::TRIBE_Player
          (TRIBE_Player *this,TRIBE_World *param_1,RGE_Master_Player *param_2,uchar param_3,
          char *param_4,uchar param_5,uchar param_6,uchar param_7,char *param_8,char *param_9,
          char *param_10)
{
  undefined1 uVar1;
  Visible_Resource_Manager *this_00;
  int iVar2;
  TribeMainDecisionAIModule *pTVar3;
  RGE_Object_List *pRVar4;
  RGE_Visible_Map *this_01;
  TRIBE_History_Info *pTVar5;
  TRIBE_Player_Tech *pTVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005611c0;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Player::RGE_Player
            ((RGE_Player *)this,(RGE_Game_World *)param_1,param_2,param_3,param_4,param_5,'\0');
  local_4 = 0;
  this->playerAI = (TribeMainDecisionAIModule *)0x0;
  this->_padding_ = (int)&_vftable_;
  this_00 = (Visible_Resource_Manager *)operator_new(0x14);
  local_4._0_1_ = 1;
  if (this_00 == (Visible_Resource_Manager *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Visible_Resource_Manager::Visible_Resource_Manager(this_00,(RGE_Player *)this,5);
  }
  this->_padding_ = iVar2;
  local_4._0_1_ = 0;
  uVar1 = (undefined1)local_4;
  local_4._0_1_ = 0;
  if (param_6 == '\0') {
    *(undefined1 *)&this->_padding_ = 1;
    local_4._0_1_ = uVar1;
  }
  else {
    *(undefined1 *)&this->_padding_ = 3;
    this->_padding_ = 1;
    iVar2 = TCommunications_Handler::IsHost(comm);
    if (iVar2 == 1) {
      pTVar3 = (TribeMainDecisionAIModule *)operator_new(0x125c8);
      local_4._0_1_ = 2;
      if (pTVar3 == (TribeMainDecisionAIModule *)0x0) {
        pTVar3 = (TribeMainDecisionAIModule *)0x0;
      }
      else {
        pTVar3 = (TribeMainDecisionAIModule *)
                 TribeMainDecisionAIModule::TribeMainDecisionAIModule
                           (pTVar3,(void *)0x0,(int)*(short *)((int)&this->_padding_ + 2),
                            (char *)this->_padding_,this,param_8,param_9,param_10);
      }
      local_4._0_1_ = 0;
      this->playerAI = pTVar3;
    }
  }
  if (param_7 != '\0') {
    pRVar4 = (RGE_Object_List *)operator_new(0xc);
    local_4._0_1_ = 3;
    if (pRVar4 == (RGE_Object_List *)0x0) {
      pRVar4 = (RGE_Object_List *)0x0;
    }
    else {
      RGE_Object_List::RGE_Object_List(pRVar4);
      pRVar4->_padding_ = (int)&TRIBE_Object_List::_vftable_;
    }
    local_4._0_1_ = 0;
    this->_padding_ = (int)pRVar4;
    pRVar4 = (RGE_Object_List *)operator_new(0xc);
    local_4._0_1_ = 4;
    if (pRVar4 == (RGE_Object_List *)0x0) {
      pRVar4 = (RGE_Object_List *)0x0;
    }
    else {
      RGE_Object_List::RGE_Object_List(pRVar4);
      pRVar4->_padding_ = (int)&TRIBE_Object_List::_vftable_;
    }
    local_4._0_1_ = 0;
    this->_padding_ = (int)pRVar4;
    pRVar4 = (RGE_Object_List *)operator_new(0xc);
    local_4._0_1_ = 5;
    if (pRVar4 == (RGE_Object_List *)0x0) {
      pRVar4 = (RGE_Object_List *)0x0;
    }
    else {
      RGE_Object_List::RGE_Object_List(pRVar4);
      pRVar4->_padding_ = (int)&TRIBE_Object_List::_vftable_;
    }
    local_4._0_1_ = 0;
    this->_padding_ = (int)pRVar4;
    new_victory(this);
    this_01 = (RGE_Visible_Map *)operator_new(0x38);
    local_4._0_1_ = 6;
    if (this_01 == (RGE_Visible_Map *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = RGE_Visible_Map::RGE_Visible_Map
                        (this_01,(RGE_Map *)param_1->_padding_,(RGE_Player *)this);
    }
    local_4._0_1_ = 0;
    this->_padding_ = iVar2;
  }
  iVar2 = 1;
  if (1 < *(short *)(this->_padding_ + 0x3c)) {
    do {
      if (iVar2 != *(short *)((int)&this->_padding_ + 2)) {
        RGE_Player::set_relation((RGE_Player *)this,iVar2,'\x03');
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(short *)(this->_padding_ + 0x3c));
  }
  this->update_count = 0;
  this->update_history_count = 0;
  this->updateCountNeedHelp = 0;
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x140);
  this->update_time = 0.0;
  this->fog_update = (iVar2 * 3) / 0x7fff + 3;
  pTVar5 = (TRIBE_History_Info *)operator_new(0x14);
  local_4._0_1_ = 7;
  if (pTVar5 == (TRIBE_History_Info *)0x0) {
    pTVar5 = (TRIBE_History_Info *)0x0;
  }
  else {
    pTVar5 = (TRIBE_History_Info *)TRIBE_History_Info::TRIBE_History_Info(pTVar5,-1);
  }
  local_4._0_1_ = 0;
  this->history = pTVar5;
  pTVar6 = (TRIBE_Player_Tech *)operator_new(0x10);
  local_4 = CONCAT31(local_4._1_3_,8);
  if (pTVar6 == (TRIBE_Player_Tech *)0x0) {
    pTVar6 = (TRIBE_Player_Tech *)0x0;
  }
  else {
    pTVar6 = (TRIBE_Player_Tech *)
             TRIBE_Player_Tech::TRIBE_Player_Tech(pTVar6,param_1->tech,(RGE_Player *)this,'\x01');
  }
  this->tech_tree = pTVar6;
  this->ruin_held_time = -1.0;
  this->artifact_held_time = -1.0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Player
// Address: 005120f0
/* public: virtual __thiscall TRIBE_Player::~TRIBE_Player(void) */

void __thiscall TRIBE_Player::~TRIBE_Player(TRIBE_Player *this)
{
  TRIBE_Player_Tech *this_00;
  TRIBE_History_Info *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_005611d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  this_00 = this->tech_tree;
  local_4 = 0;
  if (this_00 != (TRIBE_Player_Tech *)0x0) {
    TRIBE_Player_Tech::~TRIBE_Player_Tech(this_00);
    operator_delete(this_00);
    this->tech_tree = (TRIBE_Player_Tech *)0x0;
  }
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    (**(code **)this->playerAI->_padding_)(1);
    this->playerAI = (TribeMainDecisionAIModule *)0x0;
  }
  this_01 = this->history;
  if (this_01 != (TRIBE_History_Info *)0x0) {
    TRIBE_History_Info::~TRIBE_History_Info(this_01);
    operator_delete(this_01);
    this->history = (TRIBE_History_Info *)0x0;
  }
  local_4 = 0xffffffff;
  RGE_Player::~RGE_Player((RGE_Player *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: make_scenario_obj
// Address: 005121a0
/* public: virtual class RGE_Static_Object * __thiscall
   TRIBE_Player::make_scenario_obj(float,float,float,short,unsigned char,float) */

RGE_Static_Object * __thiscall
TRIBE_Player::make_scenario_obj
          (TRIBE_Player *this,float param_1,float param_2,float param_3,short param_4,uchar param_5,
          float param_6)
{
  byte bVar1;
  int *piVar2;
  undefined1 uVar3;
  TRIBE_Building_Object *this_00;
  
  this_00 = (TRIBE_Building_Object *)0x0;
  piVar2 = *(int **)(this->_padding_ + param_4 * 4);
  if (piVar2 != (int *)0x0) {
    this_00 = (TRIBE_Building_Object *)(**(code **)(*piVar2 + 0x18))(this,param_1,param_2,param_3);
    if (param_1._0_1_ < 7) {
      if (param_1._0_1_ < 3) {
        bVar1 = *(byte *)(this_00->_padding_ + 4);
        if ((bVar1 < 0x1f) || (0x59 < bVar1)) {
          uVar3 = __ftol();
          *(undefined1 *)((int)&this_00->_padding_ + 1) = uVar3;
        }
        else {
          (**(code **)(this_00->_padding_ + 0xb4))(param_2);
        }
      }
      else {
        (**(code **)(this_00->_padding_ + 0x6c))();
      }
    }
    else {
      (**(code **)(this_00->_padding_ + 0x68))();
    }
    if ((*(char *)(*(int *)(this->_padding_ + param_4 * 4) + 4) == 'P') && (param_1._0_1_ == 2)) {
      TRIBE_Building_Object::build(this_00,10000.0);
    }
  }
  return (RGE_Static_Object *)this_00;
}

// --------------------------------------------------

// Function: save
// Address: 00512250
/* public: virtual void __thiscall TRIBE_Player::save(int) */

void __thiscall TRIBE_Player::save(TRIBE_Player *this,int param_1)
{
  int iVar1;
  
  color_log('\x16','\x16',2);
  iVar1 = param_1;
  RGE_Player::save((RGE_Player *)this,param_1);
  color_log('\x16','$',2);
  rge_write(iVar1,&this->_padding_,1);
  rge_write(iVar1,&this->update_count,4);
  rge_write(iVar1,&this->updateCountNeedHelp,4);
  rge_write(iVar1,&this->fog_update,4);
  rge_write(iVar1,&this->update_time,4);
  TRIBE_Player_Tech::save(this->tech_tree,iVar1);
  rge_write(iVar1,&this->update_history_count,4);
  TRIBE_History_Info::save(this->history,iVar1);
  rge_write(iVar1,&this->ruin_held_time,4);
  rge_write(iVar1,&this->artifact_held_time,4);
  color_log('\x16','L',2);
  if (this->_padding_ == 1) {
    if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
      param_1 = TCommunications_Handler::IsHost(comm);
      if (param_1 == 1) {
        rge_write(iVar1,&param_1,4);
        (**(code **)(this->playerAI->_padding_ + 0x3c))(iVar1);
        color_log('\x16','_',2);
        return;
      }
    }
    param_1 = 0;
    rge_write(iVar1,&param_1,4);
  }
  color_log('\x16','_',2);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 005123b0
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Player::update(void) */

void __thiscall TRIBE_Player::update(TRIBE_Player *this)
{
  short sVar1;
  float *pfVar2;
  uchar uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  float fVar8;
  
  fVar8 = *(float *)(this->_padding_ + 0x84) + this->update_time;
  this->update_time = fVar8;
  if (_DAT_00576824 < fVar8) {
    do {
      iVar4 = this->update_history_count;
      fVar8 = this->update_time - _DAT_00576824;
      iVar7 = iVar4 + 1;
      this->update_history_count = iVar7;
      this->update_time = fVar8;
      if (0xe < iVar7) {
        this->update_history_count = iVar4 + -0xe;
        if (_DAT_00576828 <= *(float *)(this->_padding_ + 0x2c)) {
          uVar3 = __ftol();
        }
        else {
          uVar3 = '\0';
        }
        TRIBE_History_Info::add_history_entry(this->history,'\0',uVar3);
      }
      iVar4 = RGE_Base_Game::fullVisibility(rge_base_game);
      if (iVar4 == 0) {
        fVar8 = RGE_Visible_Map::percentExplored((RGE_Visible_Map *)this->_padding_);
        *(float *)(this->_padding_ + 0x58) = fVar8 * _DAT_0057682c;
      }
      else {
        *(undefined4 *)(this->_padding_ + 0x58) = 0x42c80000;
      }
      iVar4 = this->_padding_;
      *(float *)(iVar4 + 0xb0) =
           *(float *)(iVar4 + 0x50) - (*(float *)(iVar4 + 0x4c) - *(float *)(iVar4 + 0x2c));
      if (*(float *)(this->_padding_ + 0xb0) < (float)_DAT_00576830) {
        *(undefined4 *)(this->_padding_ + 0xb0) = 0;
      }
      iVar4 = this->_padding_;
      *(float *)(iVar4 + 0x24) = *(float *)(iVar4 + 0x28) + *(float *)(iVar4 + 0x24);
      if ((float)_DAT_00576838 < *(float *)(this->_padding_ + 0x24)) {
        *(undefined4 *)(this->_padding_ + 0x24) = 0x42c80000;
      }
      if (0 < this->update_count) {
        this->update_count = this->update_count + -1;
      }
      if (0 < this->updateCountNeedHelp) {
        this->updateCountNeedHelp = this->updateCountNeedHelp + -1;
      }
      if (0 < *(short *)((int)&this->_padding_ + 2)) {
        piVar6 = *(int **)(this->_padding_ + 4);
        if (piVar6 != (int *)0x0) {
          do {
            sVar1 = *(short *)(*(int *)(*piVar6 + 8) + 0x14);
            if ((((((sVar1 != 0xb) && (sVar1 != 0x1e)) && (sVar1 != 0x1b)) &&
                 ((sVar1 != 1 && (sVar1 != 0x15)))) &&
                ((sVar1 != 0x14 && ((sVar1 != 2 && (sVar1 != 0x25)))))) &&
               (*(char *)(*piVar6 + 0x48) == '\x02')) break;
            piVar6 = (int *)piVar6[1];
          } while (piVar6 != (int *)0x0);
          if (piVar6 != (int *)0x0) goto LAB_00512540;
        }
        (**(code **)(this->_padding_ + 4))(2);
        *(undefined4 *)(this->_padding_ + 0xb4) = 0;
      }
LAB_00512540:
    } while (_DAT_00576824 < this->update_time);
  }
  RGE_Player::update((RGE_Player *)this);
  pfVar2 = (float *)this->_padding_;
  *pfVar2 = *pfVar2 - *(float *)(this->_padding_ + 0x84) * pfVar2[0x21] * pfVar2[0xb] *
                      _DAT_00576840;
  if (*(float *)this->_padding_ < (float)_DAT_00576830) {
    *(float *)this->_padding_ = 0.0;
  }
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x25f);
  iVar4 = debug_random_on;
  global_save_debug_random_on1 = debug_random_on;
  debug_random_on = 0;
  if ((this->playerAI != (TribeMainDecisionAIModule *)0x0) &&
     (iVar7 = TCommunications_Handler::ComputerPlayerGameStart(comm), iVar7 == 1)) {
    if (((RGE_Game_World *)this->_padding_)->currentUpdateComputerPlayer == -1) {
      RGE_Game_World::selectNextComputerPlayer((RGE_Game_World *)this->_padding_,3);
    }
    (**(code **)(this->playerAI->_padding_ + 0x30))(0);
  }
  debug_random_on = iVar4;
  debug_srand(s_C__msdev_work_age1_x1_tplayer_cp,0x277,uVar5);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  return;
}

// --------------------------------------------------

// Function: update_dopplegangers
// Address: 00512620
/* public: virtual void __thiscall TRIBE_Player::update_dopplegangers(void) */

void __thiscall TRIBE_Player::update_dopplegangers(TRIBE_Player *this)
{
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  RGE_Object_List::update((RGE_Object_List *)this->_padding_);
  RGE_Doppleganger_Creator::perform_doppleganger_checks((RGE_Doppleganger_Creator *)this->_padding_)
  ;
  return;
}

// --------------------------------------------------

// Function: scenario_save
// Address: 00512630
/* public: virtual void __thiscall TRIBE_Player::scenario_save(int) */

void __thiscall TRIBE_Player::scenario_save(TRIBE_Player *this,int param_1)
{
  RGE_Player::scenario_save((RGE_Player *)this,param_1);
  rge_write(param_1,(void *)this->_padding_,4);
  rge_write(param_1,(void *)(this->_padding_ + 4),4);
  rge_write(param_1,(void *)(this->_padding_ + 0xc),4);
  rge_write(param_1,(void *)(this->_padding_ + 8),4);
  return;
}

// --------------------------------------------------

// Function: scenario_load
// Address: 00512690
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Player::scenario_load(int,long *,float) */

void __thiscall
TRIBE_Player::scenario_load(TRIBE_Player *this,int param_1,long *param_2,float param_3)
{
  RGE_Master_Static_Object *this_00;
  float fVar1;
  TRIBE_Player_Tech *pTVar2;
  TRIBE_Effects *this_01;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  short sVar4;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561206;
  *unaff_FS_OFFSET = &local_c;
  RGE_Player::scenario_load((RGE_Player *)this,param_1,param_2,param_3);
  pTVar2 = this->tech_tree;
  if (pTVar2 != (TRIBE_Player_Tech *)0x0) {
    TRIBE_Player_Tech::~TRIBE_Player_Tech(pTVar2);
    operator_delete(pTVar2);
  }
  iVar3 = 0;
  if (0 < *(short *)((int)&this->_padding_ + 2)) {
    do {
      this_00 = *(RGE_Master_Static_Object **)(this->_padding_ + iVar3 * 4);
      if (this_00 != (RGE_Master_Static_Object *)0x0) {
        RGE_Master_Static_Object::make_available(this_00,'\0');
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)((int)&this->_padding_ + 2));
  }
  if ((float)_DAT_00576848 < param_3) {
    rge_read(param_1,(void *)this->_padding_,4);
    rge_read(param_1,(void *)(this->_padding_ + 4),4);
    rge_read(param_1,(void *)(this->_padding_ + 0xc),4);
    rge_read(param_1,(void *)(this->_padding_ + 8),4);
  }
  fVar1 = (float)_DAT_00576850;
  *(undefined4 *)(this->_padding_ + 0x78) = 0;
  *(undefined4 *)(this->_padding_ + 0x54) = 0;
  if (param_3 <= fVar1) {
    pTVar2 = (TRIBE_Player_Tech *)operator_new(0x10);
    local_4 = 0;
    if (pTVar2 != (TRIBE_Player_Tech *)0x0) {
      pTVar2 = (TRIBE_Player_Tech *)
               TRIBE_Player_Tech::TRIBE_Player_Tech
                         (pTVar2,param_1,*(TRIBE_Tech **)(this->_padding_ + 0x104),
                          (RGE_Player *)this,'\x01');
      this->tech_tree = pTVar2;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    this->tech_tree = (TRIBE_Player_Tech *)0x0;
    *unaff_FS_OFFSET = local_c;
    return;
  }
  pTVar2 = (TRIBE_Player_Tech *)operator_new(0x10);
  local_4 = 1;
  if (pTVar2 == (TRIBE_Player_Tech *)0x0) {
    pTVar2 = (TRIBE_Player_Tech *)0x0;
  }
  else {
    pTVar2 = (TRIBE_Player_Tech *)
             TRIBE_Player_Tech::TRIBE_Player_Tech
                       (pTVar2,*(TRIBE_Tech **)(this->_padding_ + 0x104),(RGE_Player *)this,'\0');
  }
  this->tech_tree = pTVar2;
  local_4 = 0xffffffff;
  if (-1 < this->_padding_) {
    iVar3 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
    if (iVar3 == 0) {
      iVar3 = T_Scenario::GetScenarioOption(*(T_Scenario **)(this->_padding_ + 0x5c),2);
      if (iVar3 == 0) {
        sVar4 = (short)this->_padding_;
        this_01 = *(TRIBE_Effects **)(this->_padding_ + 0x4c);
        goto LAB_00512861;
      }
    }
  }
  sVar4 = 0xd2;
  this_01 = *(TRIBE_Effects **)(this->_padding_ + 0x4c);
LAB_00512861:
  TRIBE_Effects::do_tech_effect(this_01,sVar4,(RGE_Player *)this);
  if (rge_base_game->game_mode != 7) {
    T_Scenario::set_player_tech(*(T_Scenario **)(this->_padding_ + 0x5c),this);
  }
  TRIBE_Player_Tech::check_for_new_tech(this->tech_tree);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load
// Address: 005128a0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Player::load(int) */

void __thiscall TRIBE_Player::load(TRIBE_Player *this,int param_1)
{
  short *psVar1;
  short sVar2;
  int iVar3;
  void *pvVar4;
  RGE_Visible_Map *this_00;
  int iVar5;
  Visible_Resource_Manager *this_01;
  RGE_Object_List *pRVar6;
  short sVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar3 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561247;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  psVar1 = (short *)((int)&this->_padding_ + 2);
  rge_read(param_1,psVar1,2);
  sVar7 = 0;
  if (*psVar1 < 1) {
    this->_padding_ = 0;
  }
  else {
    pvVar4 = (void *)calloc((int)*psVar1,4);
    sVar2 = *psVar1;
    this->_padding_ = (int)pvVar4;
    rge_read(iVar3,pvVar4,(int)sVar2 << 2);
    if (0 < *psVar1) {
      do {
        if (*(int *)(this->_padding_ + sVar7 * 4) != 0) {
          rge_read(iVar3,&param_1,1);
          load_master_object(this,iVar3,sVar7,(uchar)param_1,
                             *(RGE_Sprite ***)(this->_padding_ + 0x38),
                             *(RGE_Sound ***)(this->_padding_ + 0x30));
        }
        sVar7 = sVar7 + 1;
      } while (sVar7 < *psVar1);
    }
  }
  this_00 = (RGE_Visible_Map *)operator_new(0x38);
  local_4 = 0;
  if (this_00 == (RGE_Visible_Map *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = RGE_Visible_Map::RGE_Visible_Map(this_00,iVar3,(RGE_Game_World *)this->_padding_);
  }
  local_4 = 0xffffffff;
  this->_padding_ = iVar5;
  this_01 = (Visible_Resource_Manager *)operator_new(0x14);
  local_4 = 1;
  if (this_01 == (Visible_Resource_Manager *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = Visible_Resource_Manager::Visible_Resource_Manager(this_01,iVar3,(RGE_Player *)this);
  }
  local_4 = 0xffffffff;
  this->_padding_ = iVar5;
  pRVar6 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 2;
  if (pRVar6 == (RGE_Object_List *)0x0) {
    pRVar6 = (RGE_Object_List *)0x0;
  }
  else {
    RGE_Object_List::RGE_Object_List(pRVar6);
    pRVar6->_padding_ = (int)&TRIBE_Object_List::_vftable_;
  }
  local_4 = 0xffffffff;
  this->_padding_ = (int)pRVar6;
  RGE_Object_List::load_list(pRVar6,iVar3,(RGE_Game_World *)this->_padding_);
  pRVar6 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 3;
  if (pRVar6 == (RGE_Object_List *)0x0) {
    pRVar6 = (RGE_Object_List *)0x0;
  }
  else {
    RGE_Object_List::RGE_Object_List(pRVar6);
    pRVar6->_padding_ = (int)&TRIBE_Object_List::_vftable_;
  }
  local_4 = 0xffffffff;
  this->_padding_ = (int)pRVar6;
  RGE_Object_List::load_list(pRVar6,iVar3,(RGE_Game_World *)this->_padding_);
  pRVar6 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 4;
  if (pRVar6 == (RGE_Object_List *)0x0) {
    pRVar6 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar6 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar6);
  }
  this->_padding_ = (int)pRVar6;
  local_4 = 0xffffffff;
  if (_DAT_00576858 <= save_game_version) {
    RGE_Object_List::load_list(pRVar6,iVar3,(RGE_Game_World *)this->_padding_);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load_master_object
// Address: 00512a90
/* public: void __thiscall TRIBE_Player::load_master_object(int,short,unsigned char,class RGE_Sprite
   * *,class RGE_Sound * *) */

void __thiscall
TRIBE_Player::load_master_object
          (TRIBE_Player *this,int param_1,short param_2,uchar param_3,RGE_Sprite **param_4,
          RGE_Sound **param_5)
{
  TRIBE_Master_Tree_Object *this_00;
  undefined4 uVar1;
  TRIBE_Master_Building_Object *this_01;
  TRIBE_Master_Combat_Object *this_02;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561281;
  *unaff_FS_OFFSET = &local_c;
  if (param_3 == 'F') {
    this_02 = (TRIBE_Master_Combat_Object *)operator_new(0x164);
    local_4 = 0;
    if (this_02 != (TRIBE_Master_Combat_Object *)0x0) {
      uVar1 = TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
                        (this_02,param_1,param_4,param_5,1);
      goto LAB_00512bd2;
    }
  }
  else {
    if (param_3 == 'P') {
      this_01 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
      local_4 = 1;
      if (this_01 != (TRIBE_Master_Building_Object *)0x0) {
        uVar1 = TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
                          (this_01,param_1,param_4,param_5,1);
        *(undefined4 *)(this->_padding_ + param_2 * 4) = uVar1;
        *unaff_FS_OFFSET = local_c;
        return;
      }
      *(undefined4 *)(this->_padding_ + param_2 * 4) = 0;
      *unaff_FS_OFFSET = local_c;
      return;
    }
    if (param_3 != 'Z') {
      RGE_Player::load_master_object((RGE_Player *)this,param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    this_00 = (TRIBE_Master_Tree_Object *)operator_new(0xb8);
    local_4 = 2;
    if (this_00 != (TRIBE_Master_Tree_Object *)0x0) {
      uVar1 = TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(this_00,param_1,param_4,param_5,1);
      goto LAB_00512bd2;
    }
  }
  uVar1 = 0;
LAB_00512bd2:
  *(undefined4 *)(this->_padding_ + param_2 * 4) = uVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: tech_cost
// Address: 00512bf0
/* public: void __thiscall TRIBE_Player::tech_cost(short,short &,short &,short &,short &,short
   &,short &) */

void __thiscall
TRIBE_Player::tech_cost
          (TRIBE_Player *this,short param_1,short *param_2,short *param_3,short *param_4,
          short *param_5,short *param_6,short *param_7)
{
  TRIBE_Player_Tech::tech_cost
            (this->tech_tree,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

// --------------------------------------------------

// Function: obj_cost
// Address: 00512c30
/* public: void __thiscall TRIBE_Player::obj_cost(short,char * *,short &,short &,short &,short
   &,short &,short &,float) */

void __thiscall
TRIBE_Player::obj_cost
          (TRIBE_Player *this,short param_1,char **param_2,short *param_3,short *param_4,
          short *param_5,short *param_6,short *param_7,short *param_8,float param_9)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  short sVar4;
  short *psVar5;
  short sVar6;
  
  *param_3 = -1;
  *param_4 = 0;
  *param_5 = -1;
  *param_6 = 0;
  *param_7 = -1;
  *param_8 = 0;
  uVar2 = check_obj_cost(this,param_1,(short *)0x0,1.0,0);
  iVar1 = *(int *)(this->_padding_ + param_1 * 4);
  if (iVar1 == 0) {
    return;
  }
  if (*(byte *)(iVar1 + 4) < 0x46) {
    return;
  }
  if (param_2 != (char **)0x0) {
    *param_2 = *(char **)(iVar1 + 8);
  }
  sVar6 = 0;
  if ((*(char *)(iVar1 + 0x14c) != '\0') &&
     (sVar3 = *(short *)(iVar1 + 0x148), *param_3 = sVar3, -1 < sVar3)) {
    sVar3 = __ftol();
    *param_4 = sVar3;
    sVar6 = 0;
    if ((*(float *)(this->_padding_ + *param_3 * 4) < (float)(int)sVar3) && (uVar2 != '\0')) {
      sVar4 = __ftol();
      sVar6 = sVar3 - sVar4;
      *param_4 = sVar4;
    }
  }
  if ((*(char *)(iVar1 + 0x152) != '\0') &&
     (sVar3 = *(short *)(iVar1 + 0x14e), *param_5 = sVar3, -1 < sVar3)) {
    sVar3 = __ftol();
    *param_6 = sVar3;
    if ((*(float *)(this->_padding_ + *param_5 * 4) < (float)(int)sVar3) && (uVar2 != '\0')) {
      sVar4 = __ftol();
      sVar6 = sVar6 + (sVar3 - sVar4);
      *param_6 = sVar4;
    }
  }
  if ((*(char *)(iVar1 + 0x158) != '\0') &&
     (sVar3 = *(short *)(iVar1 + 0x154), *param_7 = sVar3, -1 < sVar3)) {
    sVar3 = __ftol();
    *param_8 = sVar3;
    if ((*(float *)(this->_padding_ + *param_7 * 4) < (float)(int)sVar3) && (uVar2 != '\0')) {
      sVar4 = __ftol();
      sVar6 = sVar6 + (sVar3 - sVar4);
      *param_8 = sVar4;
    }
  }
  if (0 < sVar6) {
    if ((*param_3 == 3) || (*param_3 == -1)) {
      *param_3 = 3;
      psVar5 = param_4;
    }
    else {
      if ((*param_5 != 3) && (*param_5 != -1)) {
        if ((*param_7 == 3) || (*param_7 == -1)) {
          *param_7 = 3;
          *param_8 = sVar6;
        }
        goto LAB_00512e79;
      }
      *param_5 = 3;
      psVar5 = param_6;
    }
    *psVar5 = *psVar5 + sVar6;
  }
LAB_00512e79:
  if (*param_4 < 1) {
    *param_3 = -1;
  }
  if (*param_6 < 1) {
    *param_5 = -1;
  }
  if (*param_8 < 1) {
    *param_7 = -1;
  }
  return;
}

// --------------------------------------------------

// Function: find_obj
// Address: 00512ec0
/* public: class RGE_Static_Object * __thiscall TRIBE_Player::find_obj(short,class RGE_Static_Object
   *) */

RGE_Static_Object * __thiscall
TRIBE_Player::find_obj(TRIBE_Player *this,short param_1,RGE_Static_Object *param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  
  if (param_2 != (RGE_Static_Object *)0x0) {
    bVar3 = false;
    for (piVar4 = *(int **)(this->_padding_ + 4); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
      pRVar1 = (RGE_Static_Object *)*piVar4;
      if (pRVar1 != (RGE_Static_Object *)0x0) {
        if (bVar3) {
          if ((pRVar1->master_obj->id == param_1) && (pRVar1->object_state < 3)) {
            return (RGE_Static_Object *)*piVar4;
          }
        }
        else if (pRVar1 == param_2) {
          bVar3 = true;
        }
      }
    }
  }
  piVar4 = *(int **)(this->_padding_ + 4);
  if (piVar4 == (int *)0x0) {
    return (RGE_Static_Object *)0x0;
  }
  while (((iVar2 = *piVar4, iVar2 == 0 || (*(short *)(*(int *)(iVar2 + 8) + 0x10) != param_1)) ||
         (*(char *)(iVar2 + 0x48) != '\x02'))) {
    piVar4 = (int *)piVar4[1];
    if (piVar4 == (int *)0x0) {
      return (RGE_Static_Object *)0x0;
    }
  }
  return (RGE_Static_Object *)*piVar4;
}

// --------------------------------------------------

// Function: make_new_object
// Address: 00512f60
/* public: virtual class RGE_Static_Object * __thiscall
   TRIBE_Player::make_new_object(long,float,float,float,int) */

RGE_Static_Object * __thiscall
TRIBE_Player::make_new_object
          (TRIBE_Player *this,long param_1,float param_2,float param_3,float param_4,int param_5)
{
  short sVar1;
  TRIBE_Building_Object *this_00;
  
  this_00 = (TRIBE_Building_Object *)
            RGE_Player::make_new_object((RGE_Player *)this,param_1,param_2,param_3,param_4,param_5);
  if (this_00 != (TRIBE_Building_Object *)0x0) {
    if (param_5 != 0) {
      TRIBE_World::check_destructables
                ((TRIBE_World *)this->_padding_,*(short *)((int)&this->_padding_ + 2),(short)param_1
                 ,param_2,param_3,'\0');
      if (*(char *)(this_00->_padding_ + 4) == 'P') {
        TRIBE_Building_Object::build(this_00,10000.0);
      }
    }
    if ((rge_base_game->prog_mode == 7) &&
       ((sVar1 = *(short *)(this_00->_padding_ + 0x14), sVar1 == 5 || (sVar1 == 0x21)))) {
      (**(code **)(*(int *)this_00->_padding_ + 0x1c))(this_00->_padding_,5);
    }
  }
  return (RGE_Static_Object *)this_00;
}

// --------------------------------------------------

// Function: interface_tech_avail
// Address: 00513000
/* WARNING: Variable defined which should be unmapped: inv_amt_1 */
/* public: void __thiscall TRIBE_Player::interface_tech_avail(struct Item_Avail * *,short *,short)
    */

void __thiscall
TRIBE_Player::interface_tech_avail
          (TRIBE_Player *this,Item_Avail **param_1,short *param_2,short param_3)
{
  undefined4 *puVar1;
  Item_Avail **ppIVar2;
  short *psVar3;
  Item_Avail *pIVar4;
  long lVar5;
  short *psVar6;
  TRIBE_Player_Tech *pTVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  short sVar11;
  short inv_amt_1;
  short inv_2;
  short inv_amt_2;
  short inv_3;
  short inv_amt_3;
  short local_c;
  short local_a;
  Tech_Tree *base_tech;
  int local_4;
  
  ppIVar2 = param_1;
  sVar10 = 0;
  sVar11 = this->tech_tree->tech_player_tree_num;
  iVar8 = **(int **)(this->_padding_ + 0x104);
  if (0 < sVar11) {
    psVar6 = (short *)(iVar8 + 0x28);
    psVar3 = &this->tech_tree->tech_player_tree->state;
    iVar9 = (int)sVar11;
    sVar10 = 0;
    do {
      if ((*psVar3 == 1) && (*psVar6 == param_3)) {
        sVar10 = sVar10 + 1;
      }
      psVar3 = psVar3 + 4;
      psVar6 = psVar6 + 0x1e;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_4 = iVar8;
  if (*param_1 != (Item_Avail *)0x0) {
    free(*param_1);
    *ppIVar2 = (Item_Avail *)0x0;
  }
  *param_2 = sVar10;
  if (sVar10 != 0) {
    pIVar4 = (Item_Avail *)calloc((int)sVar10,0x28);
    *ppIVar2 = pIVar4;
    pTVar7 = this->tech_tree;
    sVar11 = 0;
    param_2 = (short *)0x0;
    if (0 < pTVar7->tech_player_tree_num) {
      do {
        iVar9 = (int)sVar11;
        if ((pTVar7->tech_player_tree[iVar9].state == 1) &&
           (puVar1 = (undefined4 *)(iVar8 + iVar9 * 0x3c),
           *(short *)(iVar8 + 0x28 + iVar9 * 0x3c) == param_3)) {
          iVar8 = (int)(short)param_2;
          (*ppIVar2)[iVar8].id = sVar11;
          (*ppIVar2)[iVar8].pict = *(short *)(puVar1 + 9);
          (*ppIVar2)[iVar8].name = (char *)*puVar1;
          TRIBE_Player_Tech::tech_cost
                    (this->tech_tree,sVar11,(short *)&param_1,&inv_amt_2,&inv_3,&inv_amt_3,&local_c,
                     &local_a);
          (*ppIVar2)[iVar8].inventory_item_1 = (short)param_1;
          (*ppIVar2)[iVar8].inventory_cost_1 = (float)(int)inv_amt_2;
          (*ppIVar2)[iVar8].inventory_item_2 = inv_3;
          (*ppIVar2)[iVar8].inventory_cost_2 = (float)(int)inv_amt_3;
          (*ppIVar2)[iVar8].inventory_item_3 = local_c;
          base_tech = (Tech_Tree *)(int)local_a;
          (*ppIVar2)[iVar8].inventory_cost_3 = (float)(int)base_tech;
          lVar5 = TRIBE_Player_Tech::get_help_message(this->tech_tree,sVar11);
          (*ppIVar2)[iVar8].help_string_id = lVar5;
          lVar5 = TRIBE_Player_Tech::get_help_page(this->tech_tree,sVar11);
          (*ppIVar2)[iVar8].help_page_id = lVar5;
          param_2 = (short *)((int)param_2 + 1);
          iVar8 = local_4;
        }
        pTVar7 = this->tech_tree;
        sVar11 = sVar11 + 1;
      } while (sVar11 < pTVar7->tech_player_tree_num);
    }
  }
  return;
}

// --------------------------------------------------

// Function: interface_item_avail
// Address: 005131c0
/* WARNING: Variable defined which should be unmapped: inv_amt_1 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TRIBE_Player::interface_item_avail(struct Item_Avail * *,short *,short)
    */

void __thiscall
TRIBE_Player::interface_item_avail
          (TRIBE_Player *this,Item_Avail **param_1,short *param_2,short param_3)
{
  Item_Avail **ppIVar1;
  short sVar2;
  Item_Avail *pIVar3;
  long lVar4;
  int *piVar5;
  short sVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  undefined2 in_stack_0000000e;
  short inv_amt_1;
  short inv_2;
  short inv_amt_2;
  short inv_3;
  short inv_amt_3;
  short tribe_flag;
  short local_e;
  short index;
  int local_8;
  int local_4;
  
  ppIVar1 = param_1;
  sVar6 = 0;
  sVar2 = *(short *)((int)&this->_padding_ + 2);
  _index = 0;
  if (0 < sVar2) {
    piVar5 = (int *)this->_padding_;
    iVar7 = (int)sVar2;
    do {
      iVar9 = *piVar5;
      if ((((iVar9 != 0) && (0x45 < *(byte *)(iVar9 + 4))) && (*(char *)(iVar9 + 0x52) != '\0')) &&
         (*(short *)(iVar9 + 0x15c) == param_3)) {
        sVar6 = sVar6 + 1;
      }
      piVar5 = piVar5 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (((param_3 == 0x76) && (*(float *)(this->_padding_ + 0xc0) == _DAT_00576828)) &&
     (*(char *)(*(int *)(this->_padding_ + 0x1b4) + 0x52) == '\0')) {
    _index = 1;
    for (piVar5 = *(int **)(this->_padding_ + 4); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[1]) {
      if (*(short *)(*(int *)(*piVar5 + 8) + 0x10) == 0x6d) {
        _index = 0;
      }
    }
  }
  if (index != 0) {
    sVar6 = sVar6 + 1;
  }
  if (*param_1 != (Item_Avail *)0x0) {
    free(*param_1);
    *ppIVar1 = (Item_Avail *)0x0;
  }
  *param_2 = sVar6;
  if (sVar6 != 0) {
    pIVar3 = (Item_Avail *)calloc((int)sVar6,0x28);
    *ppIVar1 = pIVar3;
    psVar8 = (short *)0x0;
    sVar2 = 0;
    param_2 = (short *)0x0;
    local_8 = 0;
    if (0 < *(short *)((int)&this->_padding_ + 2)) {
      do {
        sVar2 = (short)local_8;
        iVar9 = sVar2 * 4;
        iVar7 = *(int *)(iVar9 + this->_padding_);
        if (((iVar7 != 0) && (0x45 < *(byte *)(iVar7 + 4))) &&
           ((*(char *)(iVar7 + 0x52) != '\0' && (*(short *)(iVar7 + 0x15c) == param_3)))) {
          sVar6 = (short)psVar8;
          (*ppIVar1)[sVar6].id = sVar2;
          (*ppIVar1)[sVar6].pict = *(short *)(*(int *)(iVar9 + this->_padding_) + 0x4c);
          (*ppIVar1)[sVar6].name = *(char **)(*(int *)(iVar9 + this->_padding_) + 8);
          obj_cost(this,sVar2,(char **)0x0,(short *)&param_1,&inv_amt_2,&inv_3,&inv_amt_3,
                   &tribe_flag,&local_e,1.0);
          (*ppIVar1)[sVar6].inventory_item_1 = (short)param_1;
          (*ppIVar1)[sVar6].inventory_cost_1 = (float)(int)inv_amt_2;
          (*ppIVar1)[sVar6].inventory_item_2 = inv_3;
          (*ppIVar1)[sVar6].inventory_cost_2 = (float)(int)inv_amt_3;
          (*ppIVar1)[sVar6].inventory_item_3 = tribe_flag;
          local_4 = (int)local_e;
          (*ppIVar1)[sVar6].inventory_cost_3 = (float)local_4;
          lVar4 = RGE_Master_Static_Object::get_help_message
                            (*(RGE_Master_Static_Object **)(iVar9 + this->_padding_));
          (*ppIVar1)[sVar6].help_string_id = lVar4;
          lVar4 = RGE_Master_Static_Object::get_help_page
                            (*(RGE_Master_Static_Object **)(iVar9 + this->_padding_));
          (*ppIVar1)[sVar6].help_page_id = lVar4;
          psVar8 = (short *)((int)param_2 + 1);
          param_2 = psVar8;
        }
        sVar2 = (short)psVar8;
        local_8 = local_8 + 1;
      } while ((short)local_8 < *(short *)((int)&this->_padding_ + 2));
    }
    if (index != 0) {
      (*ppIVar1)[sVar2].id = 0x6d;
      (*ppIVar1)[sVar2].pict = *(short *)(*(int *)(this->_padding_ + 0x1b4) + 0x4c);
      (*ppIVar1)[sVar2].name = *(char **)(*(int *)(this->_padding_ + 0x1b4) + 8);
      obj_cost(this,0x6d,(char **)0x0,(short *)&param_1,&inv_amt_2,&inv_3,&inv_amt_3,&tribe_flag,
               &local_e,1.0);
      (*ppIVar1)[sVar2].inventory_item_1 = (short)param_1;
      (*ppIVar1)[sVar2].inventory_cost_1 = (float)(int)inv_amt_2;
      (*ppIVar1)[sVar2].inventory_item_2 = inv_3;
      (*ppIVar1)[sVar2].inventory_cost_2 = (float)(int)inv_amt_3;
      (*ppIVar1)[sVar2].inventory_item_3 = tribe_flag;
      _param_3 = (int)local_e;
      (*ppIVar1)[sVar2].inventory_cost_3 = (float)_param_3;
      lVar4 = RGE_Master_Static_Object::get_help_message
                        (*(RGE_Master_Static_Object **)(this->_padding_ + 0x1b4));
      (*ppIVar1)[sVar2].help_string_id = lVar4;
      lVar4 = RGE_Master_Static_Object::get_help_page
                        (*(RGE_Master_Static_Object **)(this->_padding_ + 0x1b4));
      (*ppIVar1)[sVar2].help_page_id = lVar4;
    }
  }
  return;
}

// --------------------------------------------------

// Function: interface_trade_avail
// Address: 005134f0
/* WARNING: Variable defined which should be unmapped: i */
/* public: void __thiscall TRIBE_Player::interface_trade_avail(struct Trade_Avail * *,short *) */

void __thiscall
TRIBE_Player::interface_trade_avail(TRIBE_Player *this,Trade_Avail **param_1,short *param_2)
{
  RGE_Static_Object *pRVar1;
  RGE_Player *pRVar2;
  uchar uVar3;
  short sVar4;
  Trade_Avail *pTVar5;
  int iVar6;
  RGE_Static_Object **ppRVar7;
  int iVar8;
  int *piVar9;
  int i;
  int local_188;
  RGE_Static_Object *dock_list [96];
  
  iVar6 = this->_padding_;
  iVar8 = 0;
  local_188 = 1;
  dock_list[0] = (RGE_Static_Object *)this;
  if (1 < *(short *)(iVar6 + 0x3c)) {
    do {
      if ((local_188 != *(short *)((int)&this->_padding_ + 2)) &&
         (piVar9 = *(int **)(*(int *)(*(int *)(*(int *)(iVar6 + 0x40) + local_188 * 4) + 0x28) + 4),
         piVar9 != (int *)0x0)) {
        ppRVar7 = dock_list + iVar8 + 1;
        do {
          if (*(short *)(*(int *)(*piVar9 + 8) + 0x10) == 0x2d) {
            sVar4 = __ftol();
            iVar6 = (int)sVar4;
            sVar4 = __ftol();
            uVar3 = RGE_Visible_Map::get_visible
                              ((RGE_Visible_Map *)dock_list[0]->world_x,(int)sVar4,iVar6);
            if (uVar3 != '\0') {
              iVar8 = iVar8 + 1;
              *ppRVar7 = (RGE_Static_Object *)*piVar9;
              ppRVar7 = ppRVar7 + 1;
            }
          }
          piVar9 = (int *)piVar9[1];
          this = (TRIBE_Player *)dock_list[0];
        } while (piVar9 != (int *)0x0);
      }
      iVar6 = this->_padding_;
      local_188 = local_188 + 1;
    } while (local_188 < *(short *)(iVar6 + 0x3c));
  }
  if (*param_1 != (Trade_Avail *)0x0) {
    free(*param_1);
    *param_1 = (Trade_Avail *)0x0;
  }
  *param_2 = (short)iVar8;
  if (iVar8 != 0) {
    pTVar5 = (Trade_Avail *)calloc(iVar8,0xc);
    *param_1 = pTVar5;
    if (0 < iVar8) {
      ppRVar7 = dock_list;
      do {
        ppRVar7 = ppRVar7 + 1;
        pRVar1 = *ppRVar7;
        iVar8 = iVar8 + -1;
        pRVar2 = pRVar1->owner;
        pTVar5->dock = pRVar1;
        pTVar5->player = pRVar2;
        pTVar5->inventory = pRVar1->attribute_amount_held;
        pTVar5 = pTVar5 + 1;
      } while (iVar8 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_make_building
// Address: 00513600
/* WARNING: Variable defined which should be unmapped: list_num */
/* public: unsigned char __thiscall TRIBE_Player::command_make_building(short,float,float) */

uchar __thiscall
TRIBE_Player::command_make_building(TRIBE_Player *this,short param_1,float param_2,float param_3)
{
  int iVar1;
  short sVar2;
  uchar uVar3;
  undefined2 in_stack_00000006;
  short list_num;
  TRIBE_Player *local_4;
  
  sVar2 = param_1;
  iVar1 = *(int *)(this->_padding_ + param_1 * 4);
  if ((iVar1 != 0) && ((*(char *)(iVar1 + 0x52) != '\0' || (param_1 == 0x6d)))) {
    local_4 = this;
    uVar3 = RGE_Player::get_selected_objects_to_command
                      ((RGE_Player *)this,(RGE_Static_Object ***)&param_1,(short *)&local_4,4,4,-1,
                       -1);
    if (uVar3 != '\0') {
      (**(code **)(**(int **)(this->_padding_ + 0x1d8) + 0x2c))();
      TRIBE_Command::command_build
                (*(TRIBE_Command **)(this->_padding_ + 0x58),_param_1,(short)local_4,sVar2,param_2,
                 param_3);
      free(_param_1);
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_make_wall
// Address: 00513690
/* WARNING: Variable defined which should be unmapped: list_num */
/* public: unsigned char __thiscall TRIBE_Player::command_make_wall(short,long,long,long,long) */

uchar __thiscall
TRIBE_Player::command_make_wall
          (TRIBE_Player *this,short param_1,long param_2,long param_3,long param_4,long param_5)
{
  int iVar1;
  short sVar2;
  uchar uVar3;
  undefined2 in_stack_00000006;
  short list_num;
  TRIBE_Player *local_4;
  
  sVar2 = param_1;
  iVar1 = *(int *)(this->_padding_ + param_1 * 4);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x52) != '\0')) {
    local_4 = this;
    uVar3 = RGE_Player::get_selected_objects_to_command
                      ((RGE_Player *)this,(RGE_Static_Object ***)&param_1,(short *)&local_4,4,4,-1,
                       -1);
    if (uVar3 != '\0') {
      (**(code **)(**(int **)(this->_padding_ + 0x1d8) + 0x2c))();
      TRIBE_Command::command_build_wall
                (*(TRIBE_Command **)(this->_padding_ + 0x58),_param_1,(short)local_4,sVar2,param_2,
                 param_3,param_4,param_5);
      free(_param_1);
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_building_make_tech
// Address: 00513720
/* public: unsigned char __thiscall TRIBE_Player::command_building_make_tech(short) */

uchar __thiscall TRIBE_Player::command_building_make_tech(TRIBE_Player *this,short param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = (RGE_Static_Object *)this->_padding_;
  if ((pRVar1 != (RGE_Static_Object *)0x0) && (pRVar1->master_obj->master_type == 'P')) {
    TRIBE_Command::command_research(*(TRIBE_Command **)(this->_padding_ + 0x58),pRVar1,param_1);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_building_cancel
// Address: 00513750
/* public: unsigned char __thiscall TRIBE_Player::command_building_cancel(void) */

uchar __thiscall TRIBE_Player::command_building_cancel(TRIBE_Player *this)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = (RGE_Static_Object *)this->_padding_;
  if ((pRVar2 != (RGE_Static_Object *)0x0) && ((TRIBE_Player *)pRVar2->owner == this)) {
    uVar1 = pRVar2->master_obj->master_type;
    if (((uVar1 == 'P') || (uVar1 == 'F')) && (pRVar2->master_obj->object_group != 1)) {
      TRIBE_Command::command_cancel_build(*(TRIBE_Command **)(this->_padding_ + 0x58),pRVar2);
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_delete_object
// Address: 00513790
/* public: unsigned char __thiscall TRIBE_Player::command_delete_object(class RGE_Static_Object *)
    */

uchar __thiscall TRIBE_Player::command_delete_object(TRIBE_Player *this,RGE_Static_Object *param_1)
{
  uchar uVar1;
  
  if (((param_1 != (RGE_Static_Object *)0x0) && ((TRIBE_Player *)param_1->owner == this)) &&
     ((uVar1 = param_1->master_obj->master_type, uVar1 == 'P' || (uVar1 == 'F')))) {
    TRIBE_Command::command_cancel_build(*(TRIBE_Command **)(this->_padding_ + 0x58),param_1);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_trade_attribute
// Address: 005137d0
/* WARNING: Variable defined which should be unmapped: list */
/* public: unsigned char __thiscall TRIBE_Player::command_trade_attribute(long) */

uchar __thiscall TRIBE_Player::command_trade_attribute(TRIBE_Player *this,long param_1)
{
  uchar uVar1;
  RGE_Static_Object **list;
  short list_num;
  short local_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command
                    ((RGE_Player *)this,(RGE_Static_Object ***)&list_num,local_4,4,-1,-1,5);
  if (uVar1 != '\0') {
    (**(code **)((*_list_num)->_padding_ + 0xac))();
    TRIBE_Command::command_trade_attribute
              (*(TRIBE_Command **)(this->_padding_ + 0x58),_list_num,local_4[0],param_1);
    free(_list_num);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_trade_attribute
// Address: 00513840
/* public: unsigned char __thiscall TRIBE_Player::command_trade_attribute(int,long) */

uchar __thiscall TRIBE_Player::command_trade_attribute(TRIBE_Player *this,int param_1,long param_2)
{
  TRIBE_Command::command_trade_attribute
            (*(TRIBE_Command **)(this->_padding_ + 0x58),param_1,
             (int)*(short *)((int)&this->_padding_ + 2),param_2);
  return '\x01';
}

// --------------------------------------------------

// Function: command_attack_ground
// Address: 00513860
/* WARNING: Variable defined which should be unmapped: list */
/* public: unsigned char __thiscall TRIBE_Player::command_attack_ground(float,float) */

uchar __thiscall TRIBE_Player::command_attack_ground(TRIBE_Player *this,float param_1,float param_2)
{
  uchar uVar1;
  RGE_Static_Object **list;
  short list_num;
  short local_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command
                    ((RGE_Player *)this,(RGE_Static_Object ***)&list_num,local_4,4,-1,-1,4);
  if (uVar1 != '\0') {
    (**(code **)((*_list_num)->_padding_ + 0xac))();
    TRIBE_Command::command_attack_ground
              (*(TRIBE_Command **)(this->_padding_ + 0x58),_list_num,local_4[0],param_1,param_2);
    free(_list_num);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_give_attribute
// Address: 005138d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall
   TRIBE_Player::command_give_attribute(int,int,float,float) */

uchar __thiscall
TRIBE_Player::command_give_attribute
          (TRIBE_Player *this,int param_1,int param_2,float param_3,float param_4)
{
  if ((param_2 != -1) && (param_3 != _DAT_00576828)) {
    (**(code **)(**(int **)(this->_padding_ + 0x58) + 0x14))
              ((int)*(short *)((int)&this->_padding_ + 2),param_1,param_2,param_3,param_4);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_building_make_obj
// Address: 00513920
/* public: unsigned char __thiscall TRIBE_Player::command_building_make_obj(short) */

uchar __thiscall TRIBE_Player::command_building_make_obj(TRIBE_Player *this,short param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = (RGE_Static_Object *)this->_padding_;
  if ((pRVar1 != (RGE_Static_Object *)0x0) && (pRVar1->master_obj->master_type == 'P')) {
    TRIBE_Command::command_make(*(TRIBE_Command **)(this->_padding_ + 0x58),pRVar1,param_1);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: command_make_repair
// Address: 00513950
/* public: unsigned char __thiscall TRIBE_Player::command_make_repair(class RGE_Static_Object *) */

uchar __thiscall TRIBE_Player::command_make_repair(TRIBE_Player *this,RGE_Static_Object *param_1)
{
  RGE_Static_Object *pRVar1;
  uchar uVar2;
  int iVar3;
  int *piVar4;
  RGE_Static_Object **unaff_ESI;
  short sVar5;
  short list_num;
  short asStack_4 [2];
  
  pRVar1 = param_1;
  if (((((TRIBE_Player *)param_1->owner != this) &&
       (iVar3 = (**(code **)(this->_padding_ + 0x1c))
                          ((int)*(short *)((int)&((TRIBE_Player *)param_1->owner)->_padding_ + 2)),
       iVar3 == 0)) || (pRVar1->master_obj->master_type != 'P')) ||
     (((float)(int)pRVar1->master_obj->hp <= pRVar1->hp || (2 < pRVar1->object_state)))) {
    if ((TRIBE_Player *)pRVar1->owner != this) {
      iVar3 = (**(code **)(this->_padding_ + 0x1c))
                        ((int)*(short *)((int)&((TRIBE_Player *)pRVar1->owner)->_padding_ + 2));
      if (iVar3 == 0) {
        return '\0';
      }
      iVar3 = (**(code **)(pRVar1->owner->_padding_ + 0x1c))
                        ((int)*(short *)((int)&this->_padding_ + 2));
      if (iVar3 == 0) {
        return '\0';
      }
    }
    sVar5 = pRVar1->master_obj->object_group;
    if (((sVar5 != 2) && (sVar5 != 0x14)) && ((sVar5 != 0x15 && (sVar5 != 0x16)))) {
      return '\0';
    }
    if ((float)(int)pRVar1->master_obj->hp <= pRVar1->hp) {
      return '\0';
    }
    if (2 < pRVar1->object_state) {
      return '\0';
    }
  }
  uVar2 = RGE_Player::get_selected_objects_to_command
                    ((RGE_Player *)this,(RGE_Static_Object ***)&param_1,asStack_4,4,4,-1,-1);
  if (uVar2 == '\0') {
    return '\0';
  }
  sVar5 = 0;
  piVar4 = (int *)(**(code **)(*(int *)param_1->_padding_ + 0xbc))(pRVar1,0,0);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x2c))();
  }
  TRIBE_Command::command_repair(*(TRIBE_Command **)(this->_padding_ + 0x58),unaff_ESI,sVar5,pRVar1);
  free(unaff_ESI);
  return '\x01';
}

// --------------------------------------------------

// Function: command_make_unload
// Address: 00513a80
/* WARNING: Variable defined which should be unmapped: list */
/* public: unsigned char __thiscall TRIBE_Player::command_make_unload(float,float) */

uchar __thiscall TRIBE_Player::command_make_unload(TRIBE_Player *this,float param_1,float param_2)
{
  uchar uVar1;
  RGE_Static_Object **list;
  short list_num;
  short local_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command
                    ((RGE_Player *)this,(RGE_Static_Object ***)&list_num,local_4,4,-1,-1,7);
  if (uVar1 != '\0') {
    (**(code **)((*_list_num)->_padding_ + 0xac))();
    TRIBE_Command::command_unload
              (*(TRIBE_Command **)(this->_padding_ + 0x58),_list_num,local_4[0],param_1,param_2);
    free(_list_num);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: check_obj_cost
// Address: 00513af0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: unsigned char __thiscall TRIBE_Player::check_obj_cost(short,short *,float,int) */

uchar __thiscall
TRIBE_Player::check_obj_cost
          (TRIBE_Player *this,short param_1,short *param_2,float param_3,int param_4)
{
  float fVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  
  fVar1 = *(float *)(this->_padding_ + 0xc);
  if (param_2 != (short *)0x0) {
    *param_2 = -1;
  }
  iVar2 = this->_padding_;
  bVar3 = (float)_DAT_00576860 <= *(float *)(iVar2 + 0x74);
  if (!bVar3) {
    fVar1 = _DAT_00576828;
  }
  iVar5 = *(int *)(this->_padding_ + param_1 * 4);
  if ((iVar5 == 0) || (*(byte *)(iVar5 + 4) < 0x46)) {
    if (param_2 != (short *)0x0) {
      *param_2 = -1;
    }
    return '\0';
  }
  iVar7 = 0;
  psVar6 = (short *)(iVar5 + 0x14a);
  do {
    iVar5 = (int)psVar6[-1];
    if (-1 < iVar5) {
      fVar4 = (float)(int)*psVar6 * param_3;
      if (((iVar5 == 4) && (param_4 == 0)) && (*(float *)(iVar2 + 0x80) <= *(float *)(iVar2 + 0x2c))
         ) {
        if (param_2 == (short *)0x0) {
          return '\0';
        }
        *param_2 = 0x20;
        return '\0';
      }
      if (((bVar3) && (iVar5 == 3)) && (fVar1 = fVar1 - fVar4, fVar1 < _DAT_00576828)) {
        if (param_2 == (short *)0x0) {
          return '\0';
        }
        *param_2 = 3;
        return '\0';
      }
      if ((*(float *)(iVar2 + iVar5 * 4) < fVar4) && ((iVar5 != 4 || (param_4 == 0)))) {
        if (((char)psVar6[1] == '\0') || (fVar1 + *(float *)(iVar2 + iVar5 * 4) < fVar4)) {
          if (param_2 == (short *)0x0) {
            return '\0';
          }
          *param_2 = psVar6[-1];
          return '\0';
        }
        fVar1 = fVar1 - (fVar4 - *(float *)(iVar2 + iVar5 * 4));
      }
    }
    iVar7 = iVar7 + 1;
    psVar6 = psVar6 + 3;
    if (2 < iVar7) {
      return '\x01';
    }
  } while( true );
}

// --------------------------------------------------

// Function: pay_obj_cost
// Address: 00513c50
/* public: unsigned char __thiscall TRIBE_Player::pay_obj_cost(short,float,int) */

uchar __thiscall
TRIBE_Player::pay_obj_cost(TRIBE_Player *this,short param_1,float param_2,int param_3)
{
  int iVar1;
  float fVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  uVar3 = check_obj_cost(this,param_1,(short *)0x0,param_2,param_3);
  if (uVar3 != '\0') {
    iVar5 = 3;
    pcVar6 = (char *)(*(int *)(this->_padding_ + param_1 * 4) + 0x14c);
    do {
      iVar4 = (int)*(short *)(pcVar6 + -4);
      if (((-1 < iVar4) && (*pcVar6 != '\0')) && ((param_3 == 0 || (iVar4 != 4)))) {
        iVar1 = this->_padding_;
        iVar4 = iVar4 * 4;
        fVar2 = (float)(int)*(short *)(pcVar6 + -2) * param_2;
        if (fVar2 <= *(float *)(iVar1 + iVar4)) {
          *(float *)(iVar1 + iVar4) = *(float *)(iVar1 + iVar4) - fVar2;
        }
        else {
          *(float *)(iVar1 + 0xc) = *(float *)(iVar1 + 0xc) - (fVar2 - *(float *)(iVar1 + iVar4));
          *(undefined4 *)(this->_padding_ + iVar4) = 0;
        }
      }
      pcVar6 = pcVar6 + 6;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: reimburse_obj_cost
// Address: 00513d00
/* public: void __thiscall TRIBE_Player::reimburse_obj_cost(short) */

void __thiscall TRIBE_Player::reimburse_obj_cost(TRIBE_Player *this,short param_1)
{
  float *pfVar1;
  short *psVar2;
  int iVar3;
  
  iVar3 = *(int *)(this->_padding_ + param_1 * 4);
  if (0x45 < *(byte *)(iVar3 + 4)) {
    psVar2 = (short *)(iVar3 + 0x148);
    iVar3 = 3;
    do {
      if ((-1 < *psVar2) && ((char)psVar2[2] != '\0')) {
        pfVar1 = (float *)(this->_padding_ + *psVar2 * 4);
        *pfVar1 = (float)(int)psVar2[1] + *pfVar1;
      }
      psVar2 = psVar2 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: check_tech_cost
// Address: 00513d60
/* public: unsigned char __thiscall TRIBE_Player::check_tech_cost(short,short *) */

uchar __thiscall TRIBE_Player::check_tech_cost(TRIBE_Player *this,short param_1,short *param_2)
{
  uchar uVar1;
  
  uVar1 = TRIBE_Player_Tech::check_tech_cost(this->tech_tree,param_1,param_2);
  return uVar1;
}

// --------------------------------------------------

// Function: pay_tech_cost
// Address: 00513d80
/* public: unsigned char __thiscall TRIBE_Player::pay_tech_cost(short) */

uchar __thiscall TRIBE_Player::pay_tech_cost(TRIBE_Player *this,short param_1)
{
  uchar uVar1;
  
  uVar1 = TRIBE_Player_Tech::start_research(this->tech_tree,param_1,'\x01',(short *)0x0);
  return uVar1;
}

// --------------------------------------------------

// Function: tech_abling
// Address: 00513da0
/* public: void __thiscall TRIBE_Player::tech_abling(long,unsigned char) */

void __thiscall TRIBE_Player::tech_abling(TRIBE_Player *this,long param_1,uchar param_2)
{
  if (param_2 != '\0') {
    TRIBE_Player_Tech::enable(this->tech_tree,(short)param_1);
    return;
  }
  TRIBE_Player_Tech::disable(this->tech_tree,(short)param_1);
  return;
}

// --------------------------------------------------

// Function: rev_tech
// Address: 00513dd0
/* public: void __thiscall TRIBE_Player::rev_tech(long) */

void __thiscall TRIBE_Player::rev_tech(TRIBE_Player *this,long param_1)
{
  short sVar1;
  
  switch(param_1) {
  case 1:
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(this->tech_tree,sVar1);
  default:
    return;
  case 0x17:
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(this->tech_tree,sVar1);
    break;
  case 0x18:
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::disable(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::rev_tech(this->tech_tree,sVar1);
    sVar1 = __ftol();
    TRIBE_Player_Tech::enable(this->tech_tree,sVar1);
    break;
  case 0x19:
  }
  sVar1 = __ftol();
  TRIBE_Player_Tech::do_tech(this->tech_tree,sVar1);
  return;
}

// --------------------------------------------------

// Function: add_population_entry
// Address: 00513fd0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TRIBE_Player::add_population_entry(void) */

void __thiscall TRIBE_Player::add_population_entry(TRIBE_Player *this)
{
  uchar uVar1;
  
  if (*(float *)(this->_padding_ + 0x2c) < _DAT_00576828) {
    TRIBE_History_Info::add_history_entry(this->history,'\0','\0');
    return;
  }
  uVar1 = __ftol();
  TRIBE_History_Info::add_history_entry(this->history,'\0',uVar1);
  return;
}

// --------------------------------------------------

// Function: random_start
// Address: 00514010
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
/* WARNING: Variable defined which should be unmapped: found_ally */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Player::random_start(void) */

void __thiscall TRIBE_Player::random_start(TRIBE_Player *this)
{
  code *pcVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  char cVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  TRIBE_Building_Object *this_00;
  int iVar10;
  RGE_Static_Object *pRVar11;
  int iVar12;
  uchar found_ally;
  float h1;
  float w1;
  float h;
  float w;
  long w2;
  
  bVar5 = false;
  if (((RGE_Object_List *)this->_padding_)->list == (RGE_Object_Node *)0x0) {
    iVar9 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x631);
    w1 = (float)((iVar9 * (*(int *)(*(int *)(this->_padding_ + 0x28) + 0xc) + -0x1e)) / 0x7fff + 0xf
                ) - _DAT_00576868;
    iVar9 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x632);
    iVar12 = 1;
    h = (float)((iVar9 * (*(int *)(*(int *)(this->_padding_ + 0x28) + 8) + -0x1e)) / 0x7fff + 0xf) -
        _DAT_00576868;
    do {
      cVar6 = (**(code **)(**(int **)(this->_padding_ + 0x1b4) + 0x20))
                        (this,h - _DAT_00576868,w1 - _DAT_00576868,0,0,1,1,1,1,1);
      if (cVar6 == '\0') break;
      iVar9 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x631);
      w1 = (float)((iVar9 * (*(int *)(*(int *)(this->_padding_ + 0x28) + 0xc) + -0x1e)) / 0x7fff +
                  0xf) - _DAT_00576868;
      iVar9 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x632);
      iVar12 = iVar12 + 1;
      h = (float)((iVar9 * (*(int *)(*(int *)(this->_padding_ + 0x28) + 8) + -0x1e)) / 0x7fff + 0xf)
          - _DAT_00576868;
    } while (iVar12 < 5000);
    if (iVar12 < 5000) {
      this_00 = (TRIBE_Building_Object *)
                (**(code **)(**(int **)(this->_padding_ + 0x1b4) + 0x18))(this,h,w1,0);
      sVar7 = __ftol();
      sVar8 = __ftol();
      RGE_Player::set_map_loc((RGE_Player *)this,sVar8,sVar7);
      RGE_Player::set_view_loc((RGE_Player *)this,h,w1);
      TRIBE_Building_Object::build(this_00,10000.0);
      w2 = 3;
      do {
        bVar2 = true;
        do {
          iVar9 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x646);
          iVar12 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x647);
          iVar10 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x648);
          fVar3 = ((float)((iVar9 * 6) / 0x7fff + -3) - (float)iVar10 * _DAT_0057686c) + w1;
          iVar9 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x649);
          fVar4 = ((float)((iVar12 * 6) / 0x7fff + -3) - (float)iVar9 * _DAT_0057686c) + h;
          if ((((_DAT_00576828 <= fVar3) &&
               (iVar9 = *(int *)(this->_padding_ + 0x28), fVar3 < (float)*(int *)(iVar9 + 0xc))) &&
              (_DAT_00576828 <= fVar4)) &&
             ((fVar4 < (float)*(int *)(iVar9 + 8) &&
              (cVar6 = (**(code **)(**(int **)(this->_padding_ + 0x14c) + 0x20))
                                 (this,fVar4,fVar3,0,0,1,1,1,1,1), cVar6 == '\0')))) {
            (**(code **)(**(int **)(this->_padding_ + 0x14c) + 0x18))(this,fVar4,fVar3,0);
            bVar2 = false;
          }
        } while (bVar2);
        w2 = w2 + -1;
      } while (w2 != 0);
    }
  }
  else {
    pRVar11 = RGE_Object_List::find_by_master_id
                        ((RGE_Object_List *)this->_padding_,0x6d,0.0,0.0,'\0','\0',
                         (RGE_Static_Object *)0x0);
    if (pRVar11 == (RGE_Static_Object *)0x0) {
      pRVar11 = (RGE_Static_Object *)**(undefined4 **)(this->_padding_ + 4);
    }
    sVar7 = __ftol();
    sVar8 = __ftol();
    RGE_Player::set_map_loc((RGE_Player *)this,sVar8,sVar7);
    RGE_Player::set_view_loc((RGE_Player *)this,pRVar11->world_x,pRVar11->world_y);
  }
  iVar9 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (((iVar9 != 0) || (iVar9 = RGE_Base_Game::randomGame(rge_base_game), iVar9 != 0)) &&
     (iVar9 = 1, 1 < *(short *)(this->_padding_ + 0x3c))) {
    pcVar1 = *(code **)(this->_padding_ + 0x1c);
    do {
      iVar12 = (*pcVar1)(iVar9);
      if ((iVar12 != 0) && (iVar9 != *(short *)((int)&this->_padding_ + 2))) {
        pRVar11 = RGE_Object_List::find_by_master_id
                            ((RGE_Object_List *)this->_padding_,0x6d,0.0,0.0,'\0','\0',
                             (RGE_Static_Object *)0x0);
        if ((pRVar11 != (RGE_Static_Object *)0x0) ||
           (pRVar11 = (RGE_Static_Object *)**(int **)(this->_padding_ + 4),
           pRVar11 != (RGE_Static_Object *)0x0)) {
          iVar12 = pRVar11->_padding_;
          (**(code **)(iVar12 + 0xd8))
                    (*(undefined4 *)(*(int *)(this->_padding_ + 0x40) + iVar9 * 4),0,0xffffffff);
          (**(code **)(iVar12 + 0xdc))
                    (*(undefined4 *)(*(int *)(this->_padding_ + 0x40) + iVar9 * 4),0,0xffffffff);
        }
                    /* language.dll match for 0x70: "B" */
        (**(code **)(**(int **)(*(int *)(this->_padding_ + 0x40) + iVar9 * 4) + 0x94))
                  (0x70,this->_padding_,this->_padding_,0,0);
        bVar5 = true;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(short *)(this->_padding_ + 0x3c));
  }
  if (((*(short *)(this->_padding_ + 0x7c) == *(short *)((int)&this->_padding_ + 2)) && (bVar5)) &&
     (iVar9 = 1, 1 < *(short *)(this->_padding_ + 0x3c))) {
    do {
      if (iVar9 != *(short *)((int)&this->_padding_ + 2)) {
        iVar12 = 1;
        do {
          iVar10 = RGE_Base_Game::playerID(rge_base_game,iVar12);
          if (iVar10 == iVar9) {
            iVar10 = (**(code **)(this->_padding_ + 0x1c))(iVar9);
            TChat::setInChatGroup(chat,iVar12,iVar10);
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < 9);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(short *)(this->_padding_ + 0x3c));
  }
  return;
}

// --------------------------------------------------

// Function: objectCost
// Address: 00514510
/* WARNING: Variable defined which should be unmapped: inv_1 */
/* public: void __thiscall TRIBE_Player::objectCost(int,int,class ResourceItem *,int) */

void __thiscall
TRIBE_Player::objectCost
          (TRIBE_Player *this,int param_1,int param_2,ResourceItem *param_3,int param_4)
{
  ResourceItem *this_00;
  short inv_1;
  short inv_amt_2;
  short inv_2;
  short inv_amt_3;
  short inv_3;
  short local_4;
  short local_2;
  
  obj_cost(this,(short)param_1,(char **)0x0,&inv_2,(short *)&param_1,&inv_3,&inv_amt_3,&local_2,
           &local_4,1.0);
  this_00 = param_3;
  ResourceItem::incrementValue(param_3,(int)inv_2,(int)(short)param_1);
  ResourceItem::incrementValue(this_00,(int)inv_3,(int)inv_amt_3);
  ResourceItem::incrementValue(this_00,(int)local_2,(int)local_4);
  return;
}

// --------------------------------------------------

// Function: objectCostByType
// Address: 00514590
/* WARNING: Variable defined which should be unmapped: inv_amt_3 */
/* public: virtual int __thiscall TRIBE_Player::objectCostByType(int) */

int __thiscall TRIBE_Player::objectCostByType(TRIBE_Player *this,int param_1)
{
  short inv_amt_3;
  short inv_amt_2;
  short inv_3;
  short inv_2;
  short inv_1;
  short local_4;
  short local_2;
  
  obj_cost(this,(short)param_1,(char **)0x0,&local_2,(short *)&param_1,&local_4,&inv_2,&inv_1,&inv_3
           ,1.0);
  return (int)(short)param_1 + (int)inv_3 + (int)inv_2;
}

// --------------------------------------------------

// Function: researchCost
// Address: 005145e0
/* WARNING: Variable defined which should be unmapped: inv_1 */
/* public: void __thiscall TRIBE_Player::researchCost(int,int,class ResourceItem *,int) */

void __thiscall
TRIBE_Player::researchCost
          (TRIBE_Player *this,int param_1,int param_2,ResourceItem *param_3,int param_4)
{
  ResourceItem *this_00;
  short inv_1;
  short inv_amt_2;
  short inv_2;
  short inv_amt_3;
  short inv_3;
  short local_4;
  short local_2;
  
  TRIBE_Player_Tech::tech_cost
            (this->tech_tree,(short)param_1,&inv_2,(short *)&param_1,&inv_3,&inv_amt_3,&local_2,
             &local_4);
  this_00 = param_3;
  ResourceItem::incrementValue(param_3,(int)inv_2,(int)(short)param_1);
  ResourceItem::incrementValue(this_00,(int)inv_3,(int)inv_amt_3);
  ResourceItem::incrementValue(this_00,(int)local_2,(int)local_4);
  return;
}

// --------------------------------------------------

// Function: objectAvailable
// Address: 00514660
/* public: int __thiscall TRIBE_Player::objectAvailable(int) */

int __thiscall TRIBE_Player::objectAvailable(TRIBE_Player *this,int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(this->_padding_ + param_1 * 4);
  if (((iVar1 == 0) || (*(char *)(iVar1 + 0x52) == '\0')) && (param_1 != 0x6d)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: researchAvailable
// Address: 00514690
/* public: int __thiscall TRIBE_Player::researchAvailable(int) */

int __thiscall TRIBE_Player::researchAvailable(TRIBE_Player *this,int param_1)
{
  return (uint)(this->tech_tree->tech_player_tree[param_1].state == 1);
}

// --------------------------------------------------

// Function: researchEverAvailable
// Address: 005146b0
/* public: int __thiscall TRIBE_Player::researchEverAvailable(int) */

int __thiscall TRIBE_Player::researchEverAvailable(TRIBE_Player *this,int param_1)
{
  short sVar1;
  
  sVar1 = TRIBE_Player_Tech::get_tech_state(this->tech_tree,(short)param_1);
  if ((sVar1 != 3) && (sVar1 != -1)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: researchState
// Address: 005146e0
/* public: unsigned char __thiscall TRIBE_Player::researchState(int) */

uchar __thiscall TRIBE_Player::researchState(TRIBE_Player *this,int param_1)
{
  short sVar1;
  
  sVar1 = TRIBE_Player_Tech::get_tech_state(this->tech_tree,(short)param_1);
  return (uchar)sVar1;
}

// --------------------------------------------------

// Function: changeToHumanPlayer
// Address: 00514700
/* public: virtual void __thiscall TRIBE_Player::changeToHumanPlayer(void) */

void __thiscall TRIBE_Player::changeToHumanPlayer(TRIBE_Player *this)
{
  return;
}

// --------------------------------------------------

// Function: changeToComputerPlayer
// Address: 00514710
/* public: virtual void __thiscall TRIBE_Player::changeToComputerPlayer(void) */

void __thiscall TRIBE_Player::changeToComputerPlayer(TRIBE_Player *this)
{
  return;
}

// --------------------------------------------------

// Function: aiStatus
// Address: 00514720
// [HELPER] s_Build_List__s__City_Plan__s__Bui: "Build List:%s, City Plan:%s, BuildAI(C=%s, N=%s, L=%s, %d/%d)."
// [HELPER] s_ConCP__d__CurCP__d__AveUAms__3d_: "ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s."
// [HELPER] s_Dip__P1__d__d__d___P2__d__d__d__: "Dip: P1(%d/%d/%d), P2(%d/%d/%d), P3(%d/%d/%d), P4(%d/%d/%d), P5(%d/%d/%d), P6..."
// [HELPER] s_Gat_Act_Des____s___d__d____s___d: "Gat(Act/Des): %s=(%d/%d), %s=(%d/%d), %s=(%d/%d), %s=(%d/%d).  #Civs=%d, #Sol..."
// [HELPER] s_Invalid_currentUpdateComputerPla: "Invalid currentUpdateComputerPlayer..."
// [HELPER] s_Invalid_status_line_number_: "Invalid status line number."
// [HELPER] s_NeedRes___s__d___s__d___s__d___s: "NeedRes: %s=%d, %s=%d, %s=%d, %s=%d, ResDiff: %s=%d, %s=%d, %s=%d, %s=%d."
// [HELPER] s_Per___s__AttEnab__d__AttDly__d_M: "Per: %s, AttEnab=%d, AttDly=%d Min, ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms..."
// [HELPER] s_Pers__Spec_BL___Food___d__d___Wo: "Pers (Spec/BL): Food=(%d/%d), Wood=(%d/%d), Gold=(%d/%d), Stone=(%d/%d)."
/* public: virtual char * __thiscall TRIBE_Player::aiStatus(int) */

char * __thiscall TRIBE_Player::aiStatus(TRIBE_Player *this,int param_1)
{
  TribeMainDecisionAIModule *pTVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  pTVar1 = this->playerAI;
  if (pTVar1 == (TribeMainDecisionAIModule *)0x0) {
    iVar7 = *(int *)(this->_padding_ + 0xfc);
    if ((iVar7 != -1) &&
       (iVar7 = *(int *)(*(int *)(this->_padding_ + 0x40) + iVar7 * 4), iVar7 != 0)) {
      iVar7 = *(int *)(iVar7 + 0x238);
      iVar8 = this->_padding_;
      uVar15 = *(undefined4 *)(iVar7 + 0x12468);
      uVar14 = *(undefined4 *)(iVar7 + 0x1246c);
      pcVar2 = TribeTacticalAIModule::updateAreaName((TribeTacticalAIModule *)(iVar7 + 0x1146c));
      sprintf(this->aiStatusInformationValue,s_ConCP__d__CurCP__d__AveUAms__3d_,
              *(undefined1 *)(iVar8 + 0x11d),*(undefined4 *)(iVar8 + 0xfc),uVar14,uVar15,pcVar2);
      return this->aiStatusInformationValue;
    }
    return s_Invalid_currentUpdateComputerPla;
  }
  if (param_1 == 1) {
    BuildAIModule::buildListLength((BuildAIModule *)&pTVar1->buildAI);
    BuildAIModule::numberItemsIntoBuildList((BuildAIModule *)&this->playerAI->buildAI);
    pcVar2 = BuildAIModule::lastBuildItemRequested((BuildAIModule *)&this->playerAI->buildAI);
    pcVar3 = BuildAIModule::nextBuildItemRequested((BuildAIModule *)&this->playerAI->buildAI);
    pcVar4 = BuildAIModule::currentBuildItemRequested((BuildAIModule *)&this->playerAI->buildAI);
    pcVar5 = ConstructionAIModule::constructionPlanName
                       ((ConstructionAIModule *)&this->playerAI->constructionAI);
    pcVar6 = BuildAIModule::buildListName((BuildAIModule *)&this->playerAI->buildAI);
    sprintf(this->aiStatusInformationValue,s_Build_List__s__City_Plan__s__Bui,pcVar6,pcVar5,pcVar4,
            pcVar3,pcVar2);
    return this->aiStatusInformationValue;
  }
  if (param_1 == 2) {
    TribeTacticalAIModule::resourceDifference(&pTVar1->tacticalAI,3);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,3);
    TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    TribeTacticalAIModule::resourceDifference(&this->playerAI->tacticalAI,2);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,2);
    TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    TribeTacticalAIModule::resourceDifference(&this->playerAI->tacticalAI,1);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,1);
    TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    TribeTacticalAIModule::resourceDifference(&this->playerAI->tacticalAI,0);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,0);
    TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    TribeTacticalAIModule::neededResourceAmount(&this->playerAI->tacticalAI,3);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,3);
    TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    TribeTacticalAIModule::neededResourceAmount(&this->playerAI->tacticalAI,2);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,2);
    TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    TribeTacticalAIModule::neededResourceAmount(&this->playerAI->tacticalAI,1);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,1);
    pcVar2 = TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    iVar7 = TribeTacticalAIModule::neededResourceAmount(&this->playerAI->tacticalAI,0);
    iVar8 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,0);
    pcVar3 = TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar8);
    sprintf(this->aiStatusInformationValue2,s_NeedRes___s__d___s__d___s__d___s,pcVar3,iVar7,pcVar2);
    return this->aiStatusInformationValue2;
  }
  if (param_1 == 3) {
    TribeTacticalAIModule::numberBoats(&pTVar1->tacticalAI);
    TribeTacticalAIModule::numberSoldiers(&this->playerAI->tacticalAI);
    TribeTacticalAIModule::numberCivilians(&this->playerAI->tacticalAI);
    TribeTacticalAIModule::desiredGathererCount(&this->playerAI->tacticalAI,3);
    TribeTacticalAIModule::actualGathererCount(&this->playerAI->tacticalAI,3);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,3);
    TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    TribeTacticalAIModule::desiredGathererCount(&this->playerAI->tacticalAI,2);
    TribeTacticalAIModule::actualGathererCount(&this->playerAI->tacticalAI,2);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,2);
    TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    TribeTacticalAIModule::desiredGathererCount(&this->playerAI->tacticalAI,1);
    TribeTacticalAIModule::actualGathererCount(&this->playerAI->tacticalAI,1);
    iVar7 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,1);
    pcVar2 = TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar7);
    iVar7 = TribeTacticalAIModule::desiredGathererCount(&this->playerAI->tacticalAI,0);
    iVar8 = TribeTacticalAIModule::actualGathererCount(&this->playerAI->tacticalAI,0);
    iVar9 = TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,0);
    pcVar3 = TribeResourceAIModule::resourceName(&this->playerAI->resourceAI,iVar9);
    sprintf(this->aiStatusInformationValue3,s_Gat_Act_Des____s___d__d____s___d,pcVar3,iVar8,iVar7,
            pcVar2);
    return this->aiStatusInformationValue3;
  }
  if (param_1 == 4) {
    TribeTacticalAIModule::strategicNumber(&pTVar1->tacticalAI,0x9e);
                    /* language.dll match for 0x77: "Arial" */
    TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,0x77);
    TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,0x9f);
                    /* language.dll match for 0x76: "B" */
    iVar7 = TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,0x76);
    iVar8 = TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,0x9d);
                    /* language.dll match for 0x78: "10" */
    iVar9 = TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,0x78);
    iVar10 = TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,0x9c);
                    /* language.dll match for 0x75: "12" */
    iVar11 = TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,0x75);
    sprintf(this->aiStatusInformationValue4,s_Pers__Spec_BL___Food___d__d___Wo,iVar11,iVar10,iVar9,
            iVar8,iVar7);
    return this->aiStatusInformationValue4;
  }
  if (param_1 == 5) {
    DiplomacyAIModule::stance(&pTVar1->diplomacyAI,8,2);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,8,1);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,8,0);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,7,2);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,7,1);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,7,0);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,6,2);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,6,1);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,6,0);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,5,2);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,5,1);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,5,0);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,4,2);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,4,1);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,4,0);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,3,2);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,3,1);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,3,0);
    DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,2,2);
    iVar7 = DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,2,1);
    iVar8 = DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,2,0);
    iVar9 = DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,1,2);
    iVar10 = DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,1,1);
    iVar11 = DiplomacyAIModule::stance(&this->playerAI->diplomacyAI,1,0);
    sprintf(this->aiStatusInformationValue5,s_Dip__P1__d__d__d___P2__d__d__d__,iVar11,iVar10,iVar9,
            iVar8,iVar7);
    return this->aiStatusInformationValue5;
  }
  if (param_1 == 6) {
    iVar7 = (pTVar1->tacticalAI).attackEnabledValue;
    iVar8 = this->_padding_;
    iVar9 = *(int *)(*(int *)(*(int *)(this->_padding_ + 0x40) +
                             *(int *)(this->_padding_ + 0xfc) * 4) + 0x238);
    uVar15 = *(undefined4 *)(iVar9 + 0x12468);
    uVar14 = *(undefined4 *)(iVar9 + 0x1246c);
    pcVar2 = TribeTacticalAIModule::updateAreaName((TribeTacticalAIModule *)(iVar9 + 0x1146c));
    uVar13 = *(undefined4 *)(iVar8 + 0xfc);
    uVar12 = (uint)*(byte *)(iVar8 + 0x11d);
                    /* language.dll match for 0x68: "Arial" */
    iVar8 = TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,0x68);
    iVar8 = iVar8 / 0x3c;
    pcVar3 = TribeStrategyAIModule::ruleSetName(&this->playerAI->strategyAI);
    sprintf(this->aiStatusInformationValue6,s_Per___s__AttEnab__d__AttDly__d_M,pcVar3,iVar7,iVar8,
            uVar12,uVar13,uVar14,uVar15,pcVar2);
    return this->aiStatusInformationValue6;
  }
  return s_Invalid_status_line_number_;
}

// --------------------------------------------------

// Function: kickAI
// Address: 00514f90
/* public: virtual void __thiscall TRIBE_Player::kickAI(int) */

void __thiscall TRIBE_Player::kickAI(TRIBE_Player *this,int param_1)
{
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    TribeMainDecisionAIModule::kick(this->playerAI,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: strategicNumber
// Address: 00514fb0
/* public: virtual int __thiscall TRIBE_Player::strategicNumber(int) */

int __thiscall TRIBE_Player::strategicNumber(TRIBE_Player *this,int param_1)
{
  int iVar1;
  
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    iVar1 = TribeTacticalAIModule::strategicNumber(&this->playerAI->tacticalAI,param_1);
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: logMessage
// Address: 00514fe0
/* WARNING: Variable defined which should be unmapped: textOut */
/* public: virtual void __cdecl TRIBE_Player::logMessage(char *,...) */

void __thiscall TRIBE_Player::logMessage(TRIBE_Player *this,char *param_1,...)
{
  undefined4 in_stack_00000008;
  char textOut [1024];
  
  if (*(int *)(param_1 + 0x238) != 0) {
    vsprintf(textOut + 4,in_stack_00000008,&stack0x0000000c);
    AIModule::logCommonHistory
              (*(AIModule **)(param_1 + 0x238),(char *)*(AIModule **)(param_1 + 0x238),textOut + 4);
  }
  return;
}

// --------------------------------------------------

// Function: sendAICommand
// Address: 00515040
/* public: virtual int __thiscall TRIBE_Player::sendAICommand(int,int,int,int,int) */

int __thiscall
TRIBE_Player::sendAICommand
          (TRIBE_Player *this,int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  
  if (this->playerAI == (TribeMainDecisionAIModule *)0x0) {
    return 0;
  }
  iVar1 = TribeMainDecisionAIModule::processAICommand
                    (this->playerAI,param_1,param_2,param_3,param_4,param_5);
  return iVar1;
}

// --------------------------------------------------

// Function: addObject
// Address: 00515070
/* public: virtual struct RGE_Object_Node * __thiscall TRIBE_Player::addObject(class
   RGE_Static_Object *,int,int) */

RGE_Object_Node * __thiscall
TRIBE_Player::addObject(TRIBE_Player *this,RGE_Static_Object *param_1,int param_2,int param_3)
{
  RGE_Object_Node *pRVar1;
  
  pRVar1 = RGE_Player::addObject((RGE_Player *)this,param_1,param_2,param_3);
  if (((param_1->master_obj->object_group != 0xb) &&
      (this->playerAI != (TribeMainDecisionAIModule *)0x0)) && (-1 < param_1->id)) {
    (**(code **)(this->playerAI->_padding_ + 0x40))(param_1);
    TribeBuildAIModule::addItem
              (&this->playerAI->buildAI,param_1,(uint)(*(char *)(this->_padding_ + 0x1d) != '\x02'))
    ;
  }
  return pRVar1;
}

// --------------------------------------------------

// Function: removeObject
// Address: 005150e0
/* public: virtual void __thiscall TRIBE_Player::removeObject(class RGE_Static_Object
   *,int,int,struct RGE_Object_Node *) */

void __thiscall
TRIBE_Player::removeObject
          (TRIBE_Player *this,RGE_Static_Object *param_1,int param_2,int param_3,
          RGE_Object_Node *param_4)
{
  RGE_Player::removeObject((RGE_Player *)this,param_1,param_2,param_3,param_4);
  if (((this->playerAI != (TribeMainDecisionAIModule *)0x0) &&
      (param_1->master_obj->object_group != 0xb)) && (-1 < param_1->id)) {
    (**(code **)(this->playerAI->_padding_ + 0x44))(param_1->id);
  }
  return;
}

// --------------------------------------------------

// Function: buildObject
// Address: 00515130
/* public: virtual void __thiscall TRIBE_Player::buildObject(int,int,float,float,int) */

void __thiscall
TRIBE_Player::buildObject
          (TRIBE_Player *this,int param_1,int param_2,float param_3,float param_4,int param_5)
{
  int *piVar1;
  
  piVar1 = (int *)calloc(1,4);
  *piVar1 = param_1;
  TRIBE_Command::command_build
            (*(TRIBE_Command **)(this->_padding_ + 0x58),(int)*(short *)((int)&this->_padding_ + 2),
             piVar1,1,param_2,param_3,param_4,param_5);
  free(piVar1);
  return;
}

// --------------------------------------------------

// Function: cancelBuild
// Address: 00515180
/* public: virtual void __thiscall TRIBE_Player::cancelBuild(int,int,int,float,float,int,int) */

void __thiscall
TRIBE_Player::cancelBuild
          (TRIBE_Player *this,int param_1,int param_2,int param_3,float param_4,float param_5,
          int param_6,int param_7)
{
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    TribeBuildAIModule::cancelBuildItem
              (&this->playerAI->buildAI,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}

// --------------------------------------------------

// Function: registerBuild
// Address: 005151c0
/* public: virtual void __thiscall TRIBE_Player::registerBuild(class RGE_Static_Object *,int) */

void __thiscall
TRIBE_Player::registerBuild(TRIBE_Player *this,RGE_Static_Object *param_1,int param_2)
{
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    TribeBuildAIModule::addBuiltItem(&this->playerAI->buildAI,param_1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: trainUnit
// Address: 005151f0
/* public: virtual void __thiscall TRIBE_Player::trainUnit(int,int,int) */

void __thiscall TRIBE_Player::trainUnit(TRIBE_Player *this,int param_1,int param_2,int param_3)
{
  TRIBE_Command::command_make
            (*(TRIBE_Command **)(this->_padding_ + 0x58),(int)*(short *)((int)&this->_padding_ + 2),
             param_2,param_1,param_3);
  return;
}

// --------------------------------------------------

// Function: cancelTrain
// Address: 00515220
/* public: virtual void __thiscall TRIBE_Player::cancelTrain(int,int,int,int) */

void __thiscall
TRIBE_Player::cancelTrain(TRIBE_Player *this,int param_1,int param_2,int param_3,int param_4)
{
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    TribeBuildAIModule::cancelTrainUnit(&this->playerAI->buildAI,param_1,param_2,param_3,param_4);
  }
  return;
}

// --------------------------------------------------

// Function: registerTrain
// Address: 00515250
/* public: virtual void __thiscall TRIBE_Player::registerTrain(int,int,int,int) */

void __thiscall
TRIBE_Player::registerTrain(TRIBE_Player *this,int param_1,int param_2,int param_3,int param_4)
{
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    TribeBuildAIModule::addTrainedUnit(&this->playerAI->buildAI,param_1,param_2,param_3,param_4);
  }
  return;
}

// --------------------------------------------------

// Function: research
// Address: 00515280
/* public: virtual void __thiscall TRIBE_Player::research(int,int,int) */

void __thiscall TRIBE_Player::research(TRIBE_Player *this,int param_1,int param_2,int param_3)
{
  TRIBE_Command::command_research
            (*(TRIBE_Command **)(this->_padding_ + 0x58),(int)*(short *)((int)&this->_padding_ + 2),
             param_2,param_1,param_3);
  return;
}

// --------------------------------------------------

// Function: cancelResearch
// Address: 005152b0
/* public: virtual void __thiscall TRIBE_Player::cancelResearch(int,int,int,int) */

void __thiscall
TRIBE_Player::cancelResearch(TRIBE_Player *this,int param_1,int param_2,int param_3,int param_4)
{
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    TribeBuildAIModule::cancelResearch(&this->playerAI->buildAI,param_1,param_2,param_3,param_4);
  }
  return;
}

// --------------------------------------------------

// Function: registerResearch
// Address: 005152e0
/* public: virtual void __thiscall TRIBE_Player::registerResearch(int,int,int) */

void __thiscall
TRIBE_Player::registerResearch(TRIBE_Player *this,int param_1,int param_2,int param_3)
{
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    TribeBuildAIModule::addResearch(&this->playerAI->buildAI,param_1,param_2,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: taskTrader
// Address: 00515310
/* public: virtual void __thiscall TRIBE_Player::taskTrader(int,int,int,float,float) */

void __thiscall
TRIBE_Player::taskTrader
          (TRIBE_Player *this,int param_1,int param_2,int param_3,float param_4,float param_5)
{
  int *piVar1;
  
  piVar1 = (int *)calloc(1,4);
  *piVar1 = param_1;
  RGE_Command::command_work
            (*(RGE_Command **)(this->_padding_ + 0x58),(int)*(short *)((int)&this->_padding_ + 2),
             piVar1,1,param_2,param_3,param_4,param_5);
  free(piVar1);
  return;
}

// --------------------------------------------------

// Function: taskResourceGatherer
// Address: 00515360
/* public: virtual void __thiscall TRIBE_Player::taskResourceGatherer(int,int,int,float,float) */

void __thiscall
TRIBE_Player::taskResourceGatherer
          (TRIBE_Player *this,int param_1,int param_2,int param_3,float param_4,float param_5)
{
  int *piVar1;
  
  piVar1 = (int *)calloc(1,4);
  *piVar1 = param_1;
  RGE_Command::command_work
            (*(RGE_Command **)(this->_padding_ + 0x58),(int)*(short *)((int)&this->_padding_ + 2),
             piVar1,1,param_2,param_3,param_4,param_5);
  free(piVar1);
  return;
}

// --------------------------------------------------

// Function: setDiplomaticStance
// Address: 005153b0
/* public: virtual void __thiscall TRIBE_Player::setDiplomaticStance(int,int) */

void __thiscall TRIBE_Player::setDiplomaticStance(TRIBE_Player *this,int param_1,int param_2)
{
  TRIBE_Command::command_relation
            (*(TRIBE_Command **)(this->_padding_ + 0x58),*(short *)((int)&this->_padding_ + 2),
             (short)param_1,(short)param_2);
  return;
}

// --------------------------------------------------

// Function: loadAIInformation
// Address: 005153d0
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
// [HELPER] s_Loading_build_list__s_: "Loading build list=%s."
// [HELPER] s_Loading_city_plan__s_: "Loading city plan=%s."
// [HELPER] s_Loading_default_build_list__s_: "Loading default build list=%s."
// [HELPER] s_Loading_no_city_plan__influence_: "Loading no city plan (influence placement will be used)."
// [HELPER] s_Loading_random_game_selected_bui: "Loading random game selected build list=%s."
// [HELPER] s_Loading_random_game_selected_rul: "Loading random game selected rule set=%s."
// [HELPER] s_Loading_rule_set__s_: "Loading rule set=%s."
// [HELPER] s_NONE: "NONE"
// [HELPER] s_RandomGameSpecialized: "RandomGameSpecialized"
// [HELPER] s_Rule_set_has_been_initialized_wi: "Rule set has been initialized with code-controlled options."
// [HELPER] s_Setting_difficulty_level_to__d_: "Setting difficulty level to %d."
// [HELPER] s_We_don_t_have_a_specific_map_typ: "We don't have a specific map type (i.e. this is a scenario)."
// [HELPER] s_We_have_a_land_and_water_map_: "We have a land and water map."
// [HELPER] s_We_have_a_mostly_land_map_: "We have a mostly land map."
// [HELPER] s_We_have_a_mostly_water_map_: "We have a mostly water map."
// [HELPER] s_We_have_an_all_land_map_: "We have an all land map."
// [HELPER] s_We_have_an_all_water_map_: "We have an all water map."
/* WARNING: Variable defined which should be unmapped: save_debug_random_on */
/* public: virtual void __thiscall TRIBE_Player::loadAIInformation(char *,char *,char *,int,int) */

void __thiscall
TRIBE_Player::loadAIInformation
          (TRIBE_Player *this,char *param_1,char *param_2,char *param_3,int param_4,int param_5)
{
  char cVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  MapType MVar6;
  int iVar7;
  MapSize MVar8;
  VictoryType VVar9;
  int iVar10;
  TribeMainDecisionAIModule *extraout_ECX;
  uint uVar11;
  uint uVar12;
  AIModule *this_00;
  TribeMainDecisionAIModule *extraout_ECX_00;
  TribeMainDecisionAIModule *extraout_ECX_01;
  AIModule *this_01;
  TribeMainDecisionAIModule *extraout_ECX_02;
  TribeMainDecisionAIModule *pTVar13;
  AIModule *extraout_ECX_03;
  AIModule *this_02;
  byte *pbVar15;
  byte *pbVar16;
  char *pcVar17;
  bool bVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  TribeMainDecisionAIModule *pTVar21;
  uchar uVar22;
  char *pcVar23;
  int iVar24;
  int save_debug_random_on;
  int saveRand;
  char buildListName [256];
  char ruleSetName [256];
  char randomString [256];
  char noneString [256];
  undefined3 uVar14;
  
  buildListName._0_4_ = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x863);
  iVar5 = debug_random_on;
  global_save_debug_random_on2 = debug_random_on;
  debug_random_on = 0;
  if (this->playerAI == (TribeMainDecisionAIModule *)0x0) goto LAB_0051598d;
  MVar6 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
  pTVar13 = extraout_ECX;
  switch(MVar6) {
  case AllWater:
    pTVar21 = this->playerAI;
    pcVar23 = s_We_have_an_all_water_map_;
    break;
  case MostlyWater:
    pTVar13 = this->playerAI;
    pcVar23 = s_We_have_a_mostly_water_map_;
    pTVar21 = pTVar13;
    break;
  case WaterAndLand:
    pcVar23 = s_We_have_a_land_and_water_map_;
    goto LAB_00515473;
  case MostlyLand:
    pcVar23 = s_We_have_a_mostly_land_map_;
    pTVar21 = this->playerAI;
    break;
  case AllLand:
    pTVar13 = this->playerAI;
    pcVar23 = s_We_have_an_all_land_map_;
    pTVar21 = pTVar13;
    break;
  default:
    pcVar23 = s_We_don_t_have_a_specific_map_typ;
LAB_00515473:
    pTVar21 = this->playerAI;
  }
  AIModule::logCommonHistory((AIModule *)pTVar13,(char *)pTVar21,pcVar23);
                    /* language.dll match for 0x2775: " <None> " */
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x2775,noneString + 4,0x100);
                    /* language.dll match for 0x277b: "Random" */
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x277b,ruleSetName + 0xf8,0x100);
  uVar11 = 0xffffffff;
  pcVar23 = s_;
  do {
    pcVar17 = pcVar23;
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    pcVar17 = pcVar23 + 1;
    cVar1 = *pcVar23;
    pcVar23 = pcVar17;
  } while (cVar1 != '\0');
  uVar11 = ~uVar11;
  pcVar23 = pcVar17 + -uVar11;
  pcVar17 = &stack0xfffffbe8;
  for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar23;
    pcVar23 = pcVar23 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *pcVar17 = *pcVar23;
    pcVar23 = pcVar23 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar11 = 0xffffffff;
  pcVar23 = s_;
  do {
    pcVar17 = pcVar23;
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    pcVar17 = pcVar23 + 1;
    cVar1 = *pcVar23;
    pcVar23 = pcVar17;
  } while (cVar1 != '\0');
  uVar11 = ~uVar11;
  pcVar23 = pcVar17 + -uVar11;
  pcVar17 = buildListName + 0xec;
  for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar23;
    pcVar23 = pcVar23 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *pcVar17 = *pcVar23;
    pcVar23 = pcVar23 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (noneString._240_4_ == 0) {
    do {
      MVar8 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
      VVar9 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
      MVar6 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
      intelligentBuildListAndRulesSelection
                (this,&stack0xfffffbe8,buildListName + 0xec,MVar6,VVar9,MVar8);
      AIModule::logCommonHistory
                (this_01,(char *)this->playerAI,s_Loading_default_build_list__s_,&stack0xfffffbe8);
      iVar7 = (**(code **)((this->playerAI->buildAI)._padding_ + 0x44))(&stack0xfffffbe8,this);
      pTVar13 = extraout_ECX_02;
    } while (iVar7 == 0);
  }
  else {
    pbVar16 = (byte *)(ruleSetName + 0xec);
    pbVar15 = (byte *)noneString._240_4_;
    do {
      bVar2 = *pbVar15;
      bVar18 = bVar2 < *pbVar16;
      if (bVar2 != *pbVar16) {
LAB_0051554b:
        iVar7 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
        goto LAB_00515550;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar15[1];
      bVar18 = bVar2 < pbVar16[1];
      if (bVar2 != pbVar16[1]) goto LAB_0051554b;
      pbVar15 = pbVar15 + 2;
      pbVar16 = pbVar16 + 2;
    } while (bVar2 != 0);
    iVar7 = 0;
LAB_00515550:
    if (iVar7 == 0) {
      do {
        MVar8 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
        VVar9 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
        MVar6 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
        intelligentBuildListAndRulesSelection
                  (this,&stack0xfffffbe8,buildListName + 0xec,MVar6,VVar9,MVar8);
        AIModule::logCommonHistory
                  (this_00,(char *)this->playerAI,s_Loading_random_game_selected_bui,
                   &stack0xfffffbe8);
        iVar7 = (**(code **)((this->playerAI->buildAI)._padding_ + 0x44))(&stack0xfffffbe8,this);
        pTVar13 = extraout_ECX_00;
      } while (iVar7 == 0);
    }
    else {
      AIModule::logCommonHistory
                ((AIModule *)this->playerAI,(char *)this->playerAI,s_Loading_build_list__s_,
                 noneString._240_4_);
      (**(code **)((this->playerAI->buildAI)._padding_ + 0x44))(noneString._240_4_,this);
      pTVar13 = extraout_ECX_01;
    }
  }
  if (noneString._244_4_ == 0) {
    pTVar13 = this->playerAI;
    pTVar21 = pTVar13;
LAB_00515704:
    AIModule::logCommonHistory
              ((AIModule *)pTVar13,(char *)pTVar21,s_Loading_no_city_plan__influence_);
    iVar7 = *(int *)(this->_padding_ + 0x28);
    uVar20 = *(undefined4 *)(iVar7 + 0xc);
    uVar19 = *(undefined4 *)(iVar7 + 8);
    iVar7 = (this->playerAI->constructionAI)._padding_;
    noneString._244_4_ = &s_NONE;
  }
  else {
    pbVar16 = (byte *)(ruleSetName + 0xec);
    pbVar15 = (byte *)noneString._244_4_;
    do {
      bVar2 = *pbVar15;
      uVar14 = (undefined3)((uint)pTVar13 >> 8);
      pTVar13 = (TribeMainDecisionAIModule *)CONCAT31(uVar14,bVar2);
      bVar18 = bVar2 < *pbVar16;
      if (bVar2 != *pbVar16) {
LAB_005156a7:
        iVar7 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
        goto LAB_005156ac;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar15[1];
      bVar3 = pbVar16[1];
      pTVar13 = (TribeMainDecisionAIModule *)CONCAT31(uVar14,bVar3);
      bVar18 = bVar2 < bVar3;
      if (bVar2 != bVar3) goto LAB_005156a7;
      pbVar15 = pbVar15 + 2;
      pbVar16 = pbVar16 + 2;
    } while (bVar2 != 0);
    iVar7 = 0;
LAB_005156ac:
    if (iVar7 == 0) {
      pTVar21 = this->playerAI;
      goto LAB_00515704;
    }
    AIModule::logCommonHistory
              ((AIModule *)this->playerAI,(char *)this->playerAI,s_Loading_city_plan__s_,
               noneString._244_4_);
    iVar7 = *(int *)(this->_padding_ + 0x28);
    uVar20 = *(undefined4 *)(iVar7 + 0xc);
    uVar19 = *(undefined4 *)(iVar7 + 8);
    iVar7 = (this->playerAI->constructionAI)._padding_;
  }
  (**(code **)(iVar7 + 0x40))(noneString._244_4_,uVar19,uVar20,0,0,0);
  this_02 = extraout_ECX_03;
  if (param_3 == (char *)0x0) {
LAB_00515793:
    pbVar15 = &s_RandomGameSpecialized;
    pbVar16 = (byte *)(ruleSetName + 4);
    do {
      bVar2 = *pbVar16;
      uVar14 = (undefined3)((uint)this_02 >> 8);
      this_02 = (AIModule *)CONCAT31(uVar14,bVar2);
      bVar18 = bVar2 < *pbVar15;
      if (bVar2 != *pbVar15) {
LAB_005157c7:
        iVar7 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
        goto LAB_005157cc;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar16[1];
      bVar3 = pbVar15[1];
      this_02 = (AIModule *)CONCAT31(uVar14,bVar3);
      bVar18 = bVar2 < bVar3;
      if (bVar2 != bVar3) goto LAB_005157c7;
      pbVar16 = pbVar16 + 2;
      pbVar15 = pbVar15 + 2;
    } while (bVar2 != 0);
    iVar7 = 0;
LAB_005157cc:
    if (iVar7 != 0) {
      AIModule::logCommonHistory
                ((AIModule *)this->playerAI,(char *)this->playerAI,
                 s_Loading_random_game_selected_rul,ruleSetName + 4);
      param_3 = ruleSetName + 4;
      goto LAB_005157f4;
    }
    AIModule::logCommonHistory(this_02,(char *)this->playerAI,s_Rule_set_has_been_initialized_wi);
  }
  else {
    pbVar16 = (byte *)(randomString + 4);
    pbVar15 = (byte *)param_3;
    do {
      bVar2 = *pbVar15;
      uVar14 = (undefined3)((uint)this_02 >> 8);
      this_02 = (AIModule *)CONCAT31(uVar14,bVar2);
      bVar18 = bVar2 < *pbVar16;
      if (bVar2 != *pbVar16) {
LAB_00515772:
        iVar7 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
        goto LAB_00515777;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar15[1];
      bVar3 = pbVar16[1];
      this_02 = (AIModule *)CONCAT31(uVar14,bVar3);
      bVar18 = bVar2 < bVar3;
      if (bVar2 != bVar3) goto LAB_00515772;
      pbVar15 = pbVar15 + 2;
      pbVar16 = pbVar16 + 2;
    } while (bVar2 != 0);
    iVar7 = 0;
LAB_00515777:
    if (iVar7 == 0) goto LAB_00515793;
    AIModule::logCommonHistory(this_02,(char *)this->playerAI,s_Loading_rule_set__s_,param_3);
LAB_005157f4:
    TribeStrategyAIModule::loadRules(&this->playerAI->strategyAI,param_3);
  }
  iVar7 = RGE_Base_Game::difficulty(rge_base_game);
  AIModule::logCommonHistory
            ((AIModule *)this->playerAI,(char *)this->playerAI,s_Setting_difficulty_level_to__d_,
             iVar7);
  TribeStrategyAIModule::setDifficultyLevel(&this->playerAI->strategyAI,iVar7);
  TribeMainDecisionAIModule::updateBuildAIWithObjects(this->playerAI);
  iVar7 = 1;
  if (1 < *(short *)(this->_padding_ + 0x3c)) {
    do {
      if (iVar7 == *(short *)((int)&this->_padding_ + 2)) {
        DiplomacyAIModule::setStance(&this->playerAI->diplomacyAI,iVar7,0,0);
        iVar24 = 100;
LAB_005158d6:
        DiplomacyAIModule::setStance(&this->playerAI->diplomacyAI,iVar7,2,iVar24);
      }
      else {
        iVar24 = this->_padding_;
        iVar10 = (**(code **)(iVar24 + 0x18))(iVar7);
        if (iVar10 != 0) {
          DiplomacyAIModule::setStance(&this->playerAI->diplomacyAI,iVar7,0,0x4a);
          iVar24 = 0x18;
          goto LAB_005158d6;
        }
        iVar24 = (**(code **)(iVar24 + 0x1c))(iVar7);
        if (iVar24 != 0) {
          DiplomacyAIModule::setStance(&this->playerAI->diplomacyAI,iVar7,0,0x18);
          iVar24 = 0x4a;
          goto LAB_005158d6;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(short *)(this->_padding_ + 0x3c));
  }
  iVar7 = 1;
  if (1 < *(short *)(this->_padding_ + 0x3c)) {
    iVar24 = this->_padding_;
    pcVar4 = *(code **)(iVar24 + 0x18);
    do {
      iVar10 = (*pcVar4)(iVar7);
      if ((iVar10 == 0) && (iVar10 = (**(code **)(iVar24 + 0x1c))(iVar7), iVar10 == 0)) {
        uVar22 = '\x01';
      }
      else {
        uVar22 = '\0';
      }
      DiplomacyAIModule::setChangeable(&this->playerAI->diplomacyAI,iVar7,uVar22);
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(short *)(this->_padding_ + 0x3c));
  }
  EmotionalAIModule::setOverallState(&this->playerAI->emotionalAI,param_4);
  pcVar23 = *(char **)(*(int *)(this->_padding_ + 0x5c) + 0x1010);
  if (pcVar23 != (char *)0x0) {
    iVar7 = -1;
    pcVar17 = pcVar23;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar17 + 1;
    } while (cVar1 != '\0');
    if (iVar7 != -2) {
      TribeInformationAIModule::loadLearnInfo(&this->playerAI->informationAI,pcVar23);
    }
  }
LAB_0051598d:
  debug_random_on = iVar5;
                    /* language.dll match for 0x8fd: "You traitorous wretch! Vengeance will be
                       mine!" */
  debug_srand(s_C__msdev_work_age1_x1_tplayer_cp,0x8fd,buildListName._0_4_);
  return;
}

// --------------------------------------------------

// Function: notify
// Address: 005159d0
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
/* WARNING: Variable defined which should be unmapped: attackingObject */
/* public: virtual void __thiscall TRIBE_Player::notify(int,int,int,long,long,long) */

void __thiscall
TRIBE_Player::notify
          (TRIBE_Player *this,int param_1,int param_2,int param_3,long param_4,long param_5,
          long param_6)
{
  RGE_Sound *this_00;
  short sVar1;
  RGE_Static_Object *pRVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  RGE_Static_Object *attackingObject;
  
  switch(param_3) {
  case 0x201:
    if (this->update_count == 0) {
      this->update_count = 0x14;
      pRVar2 = RGE_Game_World::object((RGE_Game_World *)this->_padding_,param_4);
      if (pRVar2 != (RGE_Static_Object *)0x0) {
        uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x920);
        iVar5 = debug_random_on;
        debug_random_on = 0;
        global_save_debug_random_on3 = iVar5;
        iVar7 = this->_padding_;
        if (*(short *)(iVar7 + 0x7c) == *(short *)((int)&this->_padding_ + 2)) {
          sVar1 = __ftol();
          this_00 = *(RGE_Sound **)(*(int *)(iVar7 + 0x30) + sVar1 * 4);
          if (this_00 != (RGE_Sound *)0x0) {
            RGE_Sound::play(this_00,1);
          }
          lVar3 = __ftol();
          lVar4 = __ftol();
          TRIBE_Game::add_notification_loc((TRIBE_Game *)rge_base_game,lVar4,lVar3);
        }
        debug_random_on = iVar5;
        debug_srand(s_C__msdev_work_age1_x1_tplayer_cp,0x931,uVar6);
      }
    }
  default:
    goto switchD_005159f1_caseD_202;
  case 0x206:
    iVar5 = (int)*(short *)((int)&this->_padding_ + 2);
    iVar7 = rge_base_game->_padding_;
    uVar8 = 2;
    break;
  case 0x207:
    iVar5 = (int)*(short *)((int)&this->_padding_ + 2);
    iVar7 = rge_base_game->_padding_;
    uVar8 = 1;
    break;
  case 0x20c:
    if (param_4 != 0x267) goto switchD_005159f1_caseD_202;
    iVar5 = (int)*(short *)((int)&this->_padding_ + 2);
    iVar7 = rge_base_game->_padding_;
    uVar8 = 3;
  }
  (**(code **)(iVar7 + 0x40))(uVar8,iVar5,0,0,0);
switchD_005159f1_caseD_202:
  uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0x949);
  iVar7 = debug_random_on;
  global_save_debug_random_on4 = debug_random_on;
  debug_random_on = 0;
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    (**(code **)(this->_padding_ + 0x128))(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  debug_random_on = iVar7;
  debug_srand(s_C__msdev_work_age1_x1_tplayer_cp,0x956,uVar6);
  return;
}

// --------------------------------------------------

// Function: notifyAI
// Address: 00515bb0
/* public: virtual void __thiscall TRIBE_Player::notifyAI(int,int,int,long,long,long) */

void __thiscall
TRIBE_Player::notifyAI
          (TRIBE_Player *this,int param_1,int param_2,int param_3,long param_4,long param_5,
          long param_6)
{
  RGE_Static_Object *pRVar1;
  UnitAIModule *pUVar2;
  TacticalAIGroup *this_00;
  int iVar3;
  
  pRVar1 = RGE_Game_World::object((RGE_Game_World *)this->_padding_,param_1);
  if ((((param_3 == 0x20a) || (param_3 == 0x72)) || (param_3 == 0x74)) ||
     ((pRVar1 != (RGE_Static_Object *)0x0 &&
      (pUVar2 = RGE_Static_Object::unitAI(pRVar1), pUVar2 != (UnitAIModule *)0x0)))) {
    if (param_3 < 0x1fa) {
      if (param_3 != 0x1f9) {
        if ((param_3 != 0x72) && (param_3 != 0x74)) {
          return;
        }
switchD_00515c88_caseD_201:
        (**(code **)((this->playerAI->tacticalAI)._padding_ + 0x40))
                  (param_1,param_2,param_3,param_4,param_5,param_6);
        return;
      }
      if (((param_4 == 0x25d) &&
          (this_00 = TribeTacticalAIModule::groupUnitIsIn(&this->playerAI->tacticalAI,param_1),
          this_00 != (TacticalAIGroup *)0x0)) &&
         (iVar3 = TacticalAIGroup::type(this_00), iVar3 == 0x6b)) {
        iVar3 = TacticalAIGroup::id(this_00);
        TribeTacticalAIModule::removeGroup(&this->playerAI->tacticalAI,iVar3);
        return;
      }
    }
    else {
      switch(param_3) {
      case 0x201:
        goto switchD_00515c88_caseD_201;
      case 0x202:
        if ((param_4 == 0x25d) || (param_4 == 0x26f)) {
          iVar3 = TribeInformationAIModule::fullyExploredZone
                            (&this->playerAI->informationAI,param_1);
          if ((iVar3 != 0) &&
             (iVar3 = TribeInformationAIModule::closestUnexploredTile
                                (&this->playerAI->informationAI,param_1,pRVar1->world_x,
                                 pRVar1->world_y,(float *)&param_5,(float *)&param_4), iVar3 == 1))
{
            TribeTacticalAIModule::taskExplorer
                      (&this->playerAI->tacticalAI,param_1,(float)param_5,(float)param_4);
            return;
          }
          TribeTacticalAIModule::detask(&this->playerAI->tacticalAI,param_1);
          return;
        }
        break;
      case 0x209:
        pRVar1 = RGE_Game_World::object((RGE_Game_World *)this->_padding_,param_4);
        if (pRVar1 != (RGE_Static_Object *)0x0) {
          DiplomacyAIModule::changeStance(&this->playerAI->diplomacyAI,(int)pRVar1->owner->id,0,10);
          return;
        }
        break;
      case 0x20a:
        TribeMainDecisionAIModule::tributeNotify(this->playerAI,param_1,param_4,param_5);
        return;
      case 0x20d:
        TribeInformationAIModule::addImportantObject(&this->playerAI->informationAI,param_4);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: intelligentCivSelection
// Address: 00515df0
/* public: int __thiscall TRIBE_Player::intelligentCivSelection(int,int,int) */

int __thiscall
TRIBE_Player::intelligentCivSelection(TRIBE_Player *this,int param_1,int param_2,int param_3)
{
  return 0;
}

// --------------------------------------------------

// Function: intelligentBuildListAndRulesSelection
// Address: 00515e00
// [HELPER] s_C__msdev_work_age1_x1_tplayer_cp: "C:\msdev\work\age1_x1\tplayer.cpp"
// [HELPER] s_I_am_the__s_civ__culture___d__: "I am the %s civ (culture #%d):"
// [HELPER] s_RandomGameSpecialized: "RandomGameSpecialized"
// [HELPER] s_Selected_a_best_build_list_of___: "Selected a best build list of '%s'."
// [HELPER] s_Setting_AI_Personality_: "Setting AI Personality:"
/* WARNING: Variable defined which should be unmapped: mostBuiltUnit1 */
/* public: void __thiscall TRIBE_Player::intelligentBuildListAndRulesSelection(char *,char
   *,int,int,int) */

void __thiscall
TRIBE_Player::intelligentBuildListAndRulesSelection
          (TRIBE_Player *this,char *param_1,char *param_2,int param_3,int param_4,int param_5)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  AIModule *this_00;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  int *piVar13;
  char *pcVar14;
  int mostBuiltUnit1;
  int difficultyLevel;
  int buildLists [125];
  int mostBuiltUnit2;
  char tempString [256];
  int iStack_4;
  
  if (this->playerAI == (TribeMainDecisionAIModule *)0x0) {
    return;
  }
  buildLists[0] = RGE_Base_Game::difficulty(rge_base_game);
  piVar13 = buildLists;
  for (iVar5 = 0x7d; piVar13 = piVar13 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar13 = 0;
  }
  switch(*(undefined1 *)((int)&this->_padding_ + 1)) {
  case 1:
    setupEgyptian(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 2:
    setupGreek(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 3:
    setupBabylonian(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 4:
    setupAssyrian(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 5:
    setupMinoan(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 6:
    setupHittite(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 7:
    setupPhoenician(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 8:
    setupSumerian(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 9:
    setupPersian(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 10:
    setupShang(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 0xb:
    setupYamato(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 0xc:
    setupChoson(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 0xd:
    setupRoman(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 0xe:
    setupCarthaginian(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 0xf:
    setupPalmyran(this,buildLists + 1,param_3,param_4,param_5);
    break;
  case 0x10:
    setupMacedonian(this,buildLists + 1,param_3,param_4,param_5);
  }
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if ((uVar2 == '\0') &&
     ((((cVar1 = *(char *)((int)&this->_padding_ + 1), cVar1 == '\x04' || (cVar1 == '\x01')) ||
       (cVar1 == '\x02')) ||
      (((cVar1 == '\x05' || (cVar1 == '\t')) ||
       ((cVar1 == '\a' || ((cVar1 == '\b' || (cVar1 == '\v')))))))))) {
    if (param_3 == 0) {
      if (DAT_00886c44 < 1) {
        buildLists[0xe] = 0;
        buildLists[0xf] = 0;
      }
      else if (DAT_00886c48 == 0) {
        buildLists[0xe] = buildLists[0xe] + 300;
        buildLists[0xf] = buildLists[0xf] + 300;
      }
      else {
        buildLists[0xe] = buildLists[0xe] + 100;
        buildLists[0xf] = buildLists[0xf] + 100;
      }
    }
    if (param_3 == 1) {
      if (DAT_00886c44 < 1) {
        buildLists[0xe] = 0;
        buildLists[0xf] = 0;
      }
      else if (DAT_00886c48 == 0) {
        buildLists[0xe] = buildLists[0xe] + 0xfa;
        buildLists[0xf] = buildLists[0xf] + 0xfa;
      }
      else {
        buildLists[0xe] = buildLists[0xe] + 0x4b;
        buildLists[0xf] = buildLists[0xf] + 0x4b;
      }
    }
    if (((param_3 == 2) || (param_3 == 6)) || (param_3 == 8)) {
      if (DAT_00886c44 < 1) {
        buildLists[0xe] = 0;
        buildLists[0xf] = 0;
      }
      else if (DAT_00886c48 == 0) {
        buildLists[0xe] = buildLists[0xe] + 200;
        buildLists[0xf] = buildLists[0xf] + 200;
      }
      else {
        buildLists[0xe] = buildLists[0xe] + 0x32;
        buildLists[0xf] = buildLists[0xf] + 0x32;
      }
    }
  }
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xc9,1);
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar2 != '\0') goto LAB_005162af;
  difficultyLevel = -1;
  tempString[0] = -1;
  tempString[1] = -1;
  tempString[2] = -1;
  tempString[3] = -1;
  TribeInformationAIModule::loadUnitHistory(&this->playerAI->informationAI);
  TribeInformationAIModule::unitsThatAreMostBuilt
            (&this->playerAI->informationAI,&difficultyLevel,(int *)tempString);
  switch(difficultyLevel) {
  case 0:
    buildLists[7] = buildLists[7] + 0x19;
    buildLists[8] = buildLists[8] + 0x19;
    break;
  case 1:
    buildLists[7] = buildLists[7] + 0x1e;
    buildLists[8] = buildLists[8] + 0x1e;
    break;
  case 2:
    buildLists[0x13] = buildLists[0x13] + 0x14;
    buildLists[0x12] = buildLists[0x12] + 0x14;
    buildLists[4] = buildLists[4] + 0x28;
    buildLists[5] = buildLists[5] + 0x28;
    break;
  case 3:
    buildLists[1] = buildLists[1] + 0x28;
    buildLists[0x12] = buildLists[0x12] + -0x3c;
    buildLists[0x13] = buildLists[0x13] + -0x3c;
    buildLists[2] = buildLists[2] + 0x14;
    buildLists[0x14] = buildLists[0x14] + 0x14;
    buildLists[0x15] = buildLists[0x15] + 0x14;
    break;
  case 4:
    buildLists[7] = buildLists[7] + 0xf;
    buildLists[8] = buildLists[8] + 0xf;
    iVar5 = 0x14;
    goto LAB_00516297;
  case 5:
    buildLists[7] = buildLists[7] + 0xf;
    buildLists[8] = buildLists[8] + 0xf;
    buildLists[1] = buildLists[1] + 10;
    buildLists[2] = buildLists[2] + 10;
    break;
  case 6:
    buildLists[7] = buildLists[7] + 0xf;
    buildLists[8] = buildLists[8] + 0xf;
    break;
  case 7:
  case 10:
    buildLists[0x15] = buildLists[0x15] + -0x3c;
    buildLists[0x14] = buildLists[0x14] + -0x3c;
    goto LAB_005162a7;
  case 8:
    buildLists[0x14] = buildLists[0x14] + 0x28;
    buildLists[0x15] = buildLists[0x15] + 0x28;
    if (0 < DAT_00886c44) {
      buildLists[0xe] = buildLists[0xe] + 0x32;
      buildLists[0xf] = buildLists[0xf] + 0x32;
    }
    break;
  case 9:
    iVar5 = 100;
LAB_00516297:
    buildLists[0x15] = buildLists[0x15] + iVar5;
    buildLists[0x14] = buildLists[0x14] + iVar5;
LAB_005162a7:
  }
LAB_005162af:
  difficultyLevel = 0;
  do {
    switch(difficultyLevel) {
    case 0:
      if (0 < buildLists[0x14]) {
        buildLists[0x14] = buildLists[0x14] / 3;
      }
      if (0 < buildLists[0x15]) {
        buildLists[0x15] = buildLists[0x15] / 3;
      }
      if (0 < buildLists[0x16]) {
        buildLists[0x16] = buildLists[0x16] / 3;
      }
      break;
    case 1:
      if (0 < buildLists[7]) {
        buildLists[7] = buildLists[7] / 3;
      }
      if (0 < buildLists[8]) {
        buildLists[8] = buildLists[8] / 3;
      }
      if (0 < buildLists[9]) {
        buildLists[9] = buildLists[9] / 3;
      }
      if (0 < buildLists[0x3c]) {
        buildLists[0x3c] = buildLists[0x3c] / 3;
      }
      if (0 < buildLists[0x3b]) {
        buildLists[0x3b] = buildLists[0x3b] / 3;
      }
      if (0 < buildLists[0x37]) {
        buildLists[0x37] = buildLists[0x37] / 3;
      }
      if (0 < buildLists[0x38]) {
        buildLists[0x38] = buildLists[0x38] / 3;
      }
      if (0 < buildLists[0x69]) {
        buildLists[0x69] = buildLists[0x69] / 3;
      }
      break;
    case 2:
      if (0 < buildLists[0x11]) {
        buildLists[0x11] = buildLists[0x11] / 3;
      }
      if (0 < buildLists[0x32]) {
        buildLists[0x32] = buildLists[0x32] / 3;
      }
      if (0 < buildLists[0x6d]) {
        buildLists[0x6d] = buildLists[0x6d] / 3;
      }
      break;
    case 3:
      if (0 < buildLists[0x2f]) {
        buildLists[0x2f] = buildLists[0x2f] / 3;
      }
      if (0 < buildLists[0x36]) {
        buildLists[0x36] = buildLists[0x36] / 3;
      }
      if (0 < buildLists[0x12]) {
        buildLists[0x12] = buildLists[0x12] / 3;
      }
      if (0 < buildLists[0x13]) {
        buildLists[0x13] = buildLists[0x13] / 3;
      }
      if (0 < buildLists[100]) {
        buildLists[100] = buildLists[100] / 3;
      }
      if (0 < buildLists[0x67]) {
        buildLists[0x67] = buildLists[0x67] / 3;
      }
      if (0 < buildLists[0x6e]) {
        buildLists[0x6e] = buildLists[0x6e] / 3;
      }
      if (0 < buildLists[0x13]) {
        buildLists[0x13] = buildLists[0x13] / 3;
      }
      break;
    case 4:
      if (0 < buildLists[4]) {
        buildLists[4] = buildLists[4] / 3;
      }
      if (0 < buildLists[5]) {
        buildLists[5] = buildLists[5] / 3;
      }
      if (0 < buildLists[6]) {
        buildLists[6] = buildLists[6] / 3;
      }
      if (0 < buildLists[10]) {
        buildLists[10] = buildLists[10] / 3;
      }
      if (0 < buildLists[0xb]) {
        buildLists[0xb] = buildLists[0xb] / 3;
      }
      if (0 < buildLists[0xc]) {
        buildLists[0xc] = buildLists[0xc] / 3;
      }
      if (0 < buildLists[0xd]) {
        buildLists[0xd] = buildLists[0xd] / 3;
      }
      if (0 < buildLists[0x2b]) {
        buildLists[0x2b] = buildLists[0x2b] / 3;
      }
      if (0 < buildLists[0x2d]) {
        buildLists[0x2d] = buildLists[0x2d] / 3;
      }
      if (0 < buildLists[0x2e]) {
        buildLists[0x2e] = buildLists[0x2e] / 3;
      }
      if (0 < buildLists[0x30]) {
        buildLists[0x30] = buildLists[0x30] / 3;
      }
      if (0 < buildLists[0x31]) {
        buildLists[0x31] = buildLists[0x31] / 3;
      }
      if (0 < buildLists[0x39]) {
        buildLists[0x39] = buildLists[0x39] / 3;
      }
      if (0 < buildLists[0x4b]) {
        buildLists[0x4b] = buildLists[0x4b] / 3;
      }
      if (0 < buildLists[99]) {
        buildLists[99] = buildLists[99] / 3;
      }
      if (0 < buildLists[0x68]) {
        buildLists[0x68] = buildLists[0x68] / 3;
      }
      if (0 < buildLists[0x71]) {
        buildLists[0x71] = buildLists[0x71] / 3;
      }
      if (0 < buildLists[0x72]) {
        buildLists[0x72] = buildLists[0x72] / 3;
      }
      break;
    case 5:
      if (0 < buildLists[0x2a]) {
        buildLists[0x2a] = buildLists[0x2a] / 3;
      }
      if (0 < buildLists[1]) {
        buildLists[1] = buildLists[1] / 3;
      }
      if (0 < buildLists[2]) {
        buildLists[2] = buildLists[2] / 3;
      }
      if (0 < buildLists[3]) {
        buildLists[3] = buildLists[3] / 3;
      }
      if (0 < buildLists[0x2a]) {
        buildLists[0x2a] = buildLists[0x2a] / 3;
      }
      if (0 < buildLists[0x33]) {
        buildLists[0x33] = buildLists[0x33] / 3;
      }
      if (0 < buildLists[0x34]) {
        buildLists[0x34] = buildLists[0x34] / 3;
      }
      if (0 < buildLists[0x49]) {
        buildLists[0x49] = buildLists[0x49] / 3;
      }
      if (0 < buildLists[0x4a]) {
        buildLists[0x4a] = buildLists[0x4a] / 3;
      }
      if (0 < buildLists[0x33]) {
        buildLists[0x33] = buildLists[0x33] / 3;
      }
      if (0 < buildLists[0x34]) {
        buildLists[0x34] = buildLists[0x34] / 3;
      }
      if (0 < buildLists[0x51]) {
        buildLists[0x51] = buildLists[0x51] / 3;
      }
      if (0 < buildLists[0x52]) {
        buildLists[0x52] = buildLists[0x52] / 3;
      }
      if (0 < buildLists[0x53]) {
        buildLists[0x53] = buildLists[0x53] / 3;
      }
      if (0 < buildLists[0x6c]) {
        buildLists[0x6c] = buildLists[0x6c] / 3;
      }
      break;
    case 6:
      if (0 < buildLists[0x29]) {
        buildLists[0x29] = buildLists[0x29] / 3;
      }
      if (0 < buildLists[0x3a]) {
        buildLists[0x3a] = buildLists[0x3a] / 3;
      }
      if (0 < buildLists[0x73]) {
        buildLists[0x73] = buildLists[0x73] / 3;
      }
      if (0 < buildLists[0x55]) {
        buildLists[0x55] = buildLists[0x55] / 3;
      }
    }
    difficultyLevel = difficultyLevel + 1;
  } while (difficultyLevel < 7);
  piVar13 = buildLists;
  iVar5 = 0x7d;
  do {
    piVar13 = piVar13 + 1;
    if (*piVar13 < 0) {
      *piVar13 = 0;
    }
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar10 = 0;
  piVar13 = buildLists;
                    /* language.dll match for 0x7d: "Arial" */
  iVar5 = 0x7d;
  do {
    piVar13 = piVar13 + 1;
    iVar10 = iVar10 + *piVar13;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xc41);
  iVar11 = 0;
  iVar3 = 0;
  piVar13 = buildLists;
  do {
    piVar13 = piVar13 + 1;
    iVar11 = iVar11 + *piVar13;
    iVar4 = iVar3;
    if (iVar5 % iVar10 < iVar11) break;
    iVar3 = iVar3 + 1;
    iVar4 = 0;
  } while (iVar3 < 0x7d);
  iVar5 = 0x100;
  (**(code **)(rge_base_game->_padding_ + 0x20))(iVar4 + 0x26930,param_1);
  switch(iVar4) {
  case 0:
  case 1:
  case 2:
  case 0x29:
  case 0x32:
  case 0x33:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x6b:
    DAT_00886c2c = DAT_00886c2c + 1;
    break;
  default:
    DAT_00886c28 = DAT_00886c28 + 1;
    break;
  case 6:
  case 7:
  case 8:
  case 0x2b:
  case 0x36:
  case 0x37:
  case 0x3a:
  case 0x3b:
  case 0x68:
    DAT_00886c1c = DAT_00886c1c + 1;
    break;
  case 0xd:
  case 0xe:
  case 0xf:
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x3b,4);
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x3c,10);
    DAT_00886c34 = DAT_00886c34 + 1;
    DAT_00886c48 = DAT_00886c48 + 1;
    goto LAB_00516be6;
  case 0x10:
  case 0x31:
  case 0x6c:
    DAT_00886c20._0_4_ = (int)DAT_00886c20 + 1;
    break;
  case 0x11:
  case 0x12:
  case 0x2e:
  case 0x34:
  case 0x35:
  case 99:
  case 0x66:
  case 0x6d:
    DAT_00886c20._4_4_ = DAT_00886c20._4_4_ + 1;
    break;
  case 0x13:
  case 0x14:
  case 0x15:
    computerPlayerSetup = (int *)((int)computerPlayerSetup + 1);
    break;
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
    break;
  case 0x28:
  case 0x39:
  case 0x54:
  case 0x72:
    DAT_00886c30 = DAT_00886c30 + 1;
    break;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x53:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 100:
  case 0x65:
  case 0x69:
  case 0x6a:
  case 0x6e:
  case 0x6f:
  case 0x73:
  case 0x74:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
    DAT_00886c48 = DAT_00886c48 + 1;
    goto LAB_00516be6;
  case 0x48:
  case 0x49:
    DAT_00886c44 = DAT_00886c44 + 1;
    DAT_00886c2c = DAT_00886c2c + 1;
    goto LAB_00516be6;
  case 0x4a:
    DAT_00886c44 = DAT_00886c44 + 1;
    DAT_00886c28 = DAT_00886c28 + 1;
    goto LAB_00516be6;
  }
  DAT_00886c44 = DAT_00886c44 + 1;
LAB_00516be6:
  (**(code **)(rge_base_game->_padding_ + 0x20))
            (*(byte *)((int)&this->_padding_ + 1) + 0x27f6,buildLists + 0x7c,0x100);
  this_00 = (AIModule *)(*(byte *)((int)&this->_padding_ + 1) - 1);
  AIModule::logCommonHistory
            (this_00,(char *)this->playerAI,s_I_am_the__s_civ__culture___d__,buildLists + 0x79,
             this_00);
  AIModule::logCommonHistory
            ((AIModule *)this->playerAI,(char *)this->playerAI,s_Selected_a_best_build_list_of___,
             param_1);
  uVar6 = 0xffffffff;
  pcVar12 = &s_RandomGameSpecialized;
  do {
    pcVar14 = pcVar12;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar14 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar14;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar12 = pcVar14 + -uVar6;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)tempString._244_4_ = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    tempString._244_4_ = (char *)(tempString._244_4_ + 4);
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)tempString._244_4_ = *pcVar12;
    pcVar12 = pcVar12 + 1;
    tempString._244_4_ = (char *)(tempString._244_4_ + 1);
  }
  AIModule::logCommonHistory((AIModule *)0x0,(char *)this->playerAI,s_Setting_AI_Personality_);
  iVar10 = tempString._248_4_;
  switch(tempString._252_4_) {
  case 0:
  case 1:
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x36,5);
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x37,5);
    iVar10 = tempString._248_4_;
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    iVar10 = TribeStrategyAIModule::rule(&this->playerAI->strategyAI,1);
    if (iVar10 < 1) {
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0,0x32);
      iVar10 = 0x32;
    }
    else {
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0,0x32);
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,1,0x19);
      iVar10 = 0x19;
    }
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,2,iVar10);
    if (1 < (int)tempString._248_4_) {
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,3,5);
    }
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x2a,2);
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x3d,2);
    iVar10 = tempString._248_4_;
    if (tempString._252_4_ != 2) {
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x26,iStack_4 + 1);
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x24,1);
      if (tempString._252_4_ == 3) {
        iVar3 = 1;
      }
      else {
        iVar3 = 5;
      }
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x36,iVar3);
      if (tempString._252_4_ == 4) {
        iVar3 = 1;
      }
      else {
        iVar3 = 5;
      }
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x37,iVar3);
    }
  }
  uVar2 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar2 == '\x01') {
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,4,10);
  }
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe3a);
  iVar3 = (iVar3 % 0xc + 0x1c) * 0x3c;
  switch(iVar4) {
  case 0:
  case 3:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0x13:
  case 0x2f:
  case 0x30:
  case 0x33:
  case 0x37:
  case 0x39:
  case 0x48:
  case 0x4a:
  case 0x4b:
  case 0x4e:
  case 0x51:
  case 0x55:
  case 0x58:
  case 0x5a:
  case 0x5e:
  case 0x60:
  case 100:
  case 0x69:
  case 0x6e:
  case 0x73:
    DAT_00886c3c = DAT_00886c3c + 1;
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe58);
    iVar3 = (iVar3 % 6 + 0x14) * 0x3c;
    break;
  default:
    DAT_00886c40 = DAT_00886c40 + 1;
    break;
  case 9:
  case 0x38:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe69);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar3 = ((((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 5) * 0x3c;
    DAT_00886c38 = DAT_00886c38 + 1;
    break;
  case 10:
  case 0x29:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x32:
  case 0x3a:
  case 0x71:
    DAT_00886c38 = DAT_00886c38 + 1;
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe64);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar3 = ((((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7) + 0xb) * 0x3c;
  }
  iVar11 = iVar5;
  if ((iVar5 == 0) && (iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe73), iVar4 % 3 == 0)
     ) {
    iVar3 = iVar3 + -300;
  }
                    /* language.dll match for 0x68: "Arial" */
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x68,iVar3);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x10,2);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x1a,10);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x5d,1);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,99,4);
                    /* language.dll match for 0xe80: "Click to mine for gold." */
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe80);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xbc,(uint)(iVar3 % 3 != 0));
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe86);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xc3,iVar3 % 0x28 + 10);
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe8a);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xbd,iVar3 % 0x46 + 0x1e);
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe8e);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xc6,(iVar3 % 5 + 5) * iVar5);
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xe92);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,199,(iVar3 % 10 + 10) * iVar5);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xa1,4);
  if (iVar10 == 0) {
    iStack_4 = iStack_4 + -2;
  }
  else if (iVar10 == 1) {
    iStack_4 = iStack_4 + -1;
  }
  switch(iStack_4) {
  case 0:
                    /* language.dll match for 0xea7: "Click to convert this unit." */
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea7);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&this->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0xf);
    iVar3 = TribeStrategyAIModule::rule(&this->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea9);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar3 = iVar3 + 1 + (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  case 1:
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeac);
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x49,iVar3 % 3 + 0x10);
    iVar3 = TribeStrategyAIModule::rule(&this->playerAI->strategyAI,0x49);
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeae);
    iVar8 = 5;
    iVar9 = iVar4 >> 0x1f;
    break;
  case 2:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb1);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&this->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x11);
    iVar3 = TribeStrategyAIModule::rule(&this->playerAI->strategyAI,0x49);
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb3);
    iVar8 = 6;
    iVar9 = iVar4 >> 0x1f;
    break;
  case 3:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb6);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&this->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x12);
    iVar3 = TribeStrategyAIModule::rule(&this->playerAI->strategyAI,0x49);
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xeb8);
    iVar8 = 7;
    iVar9 = iVar4 >> 0x1f;
    break;
  case 4:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xebb);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&this->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7) + 0x12);
    iVar3 = TribeStrategyAIModule::rule(&this->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xebd);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar3 = iVar3 + 1 + (((uVar6 ^ uVar7) - uVar7 & 7 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  case -2:
  case -1:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea2);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&this->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0xe);
    iVar3 = TribeStrategyAIModule::rule(&this->playerAI->strategyAI,0x49);
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xea4);
    uVar7 = (int)uVar6 >> 0x1f;
    iVar3 = iVar3 + 1 + (((uVar6 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
    goto LAB_005172a1;
  default:
    uVar6 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xec1);
    uVar7 = (int)uVar6 >> 0x1f;
    TribeStrategyAIModule::setRule
              (&this->playerAI->strategyAI,0x49,
               (((uVar6 ^ uVar7) - uVar7 & 1 ^ uVar7) - uVar7) + 0x12);
    iVar3 = TribeStrategyAIModule::rule(&this->playerAI->strategyAI,0x49);
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xec3);
    iVar8 = 9;
    iVar9 = iVar4 >> 0x1f;
  }
  iVar3 = iVar3 + 1 + (int)(CONCAT44(iVar9,iVar4) % (longlong)iVar8);
LAB_005172a1:
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x4a,iVar3);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd0,1);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd1,1);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd2,1);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xdf,1);
  if (iVar10 == 0) {
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd4,3);
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd5,6);
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd6,2);
    iVar10 = 6;
LAB_00517478:
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xe0,iVar10);
  }
  else {
    if (iVar10 == 1) {
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd4,2);
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd5,5);
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd6,2);
      iVar10 = 4;
      goto LAB_00517478;
    }
    if (((iVar10 == 2) || (iVar10 == 6)) || ((iVar10 == 5 || (iVar10 == 8)))) {
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd4,1);
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd5,4);
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd6,1);
      iVar10 = 3;
      goto LAB_00517478;
    }
    if (((iVar10 == 3) || (iVar10 == 4)) || (iVar10 == 7)) {
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd4,0);
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd5,0);
      TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xd6,0);
      iVar10 = 0;
      goto LAB_00517478;
    }
  }
  if (allowAIToCheat != 0) {
    iVar5 = 0;
    iVar10 = 0;
    iVar3 = 0;
    iVar4 = 0;
    if (iVar11 == 0) {
                    /* language.dll match for 0x7d0: "place holder" */
      iVar5 = 2000;
      iVar3 = 2000;
      iVar4 = 2000;
      iVar10 = 2000;
    }
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x8a,iVar5);
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x8b,iVar3);
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x8c,iVar4);
    iVar5 = iVar11;
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x8d,iVar10);
  }
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xa8,0);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xa2,0);
  if (iVar5 < 3) {
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xc2,1);
    iVar10 = 2;
  }
  else {
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xc2,0);
    iVar10 = 1;
  }
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0x2f,iVar10);
  if (iVar5 == 0) {
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 200;
  }
  else if (iVar5 == 1) {
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 0x96;
  }
  else if (iVar5 == 2) {
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 100;
  }
  else {
    if (iVar5 != 3) goto LAB_00517639;
    TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xba,0xb4);
    iVar5 = 0x32;
  }
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xba,iVar5);
LAB_00517639:
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xf50);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xb5,(uint)(iVar5 % 6 < 5));
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_tplayer_cp,0xf56);
  TribeStrategyAIModule::setRule(&this->playerAI->strategyAI,0xb6,(uint)(iVar5 % 3 < 1));
  return;
}

// --------------------------------------------------

// Function: setupEgyptian
// Address: 00517b90
// [HELPER] s_Setting_up_as_Egyptians_: "Setting up as Egyptians."
/* public: void __thiscall TRIBE_Player::setupEgyptian(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupEgyptian(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Egyptians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      param_1[0x23] = 100;
      return;
    }
    param_1[3] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0x11] = 0x28;
    param_1[0x12] = 0x28;
    param_1[0x2e] = 100;
    param_1[0x13] = 0x32;
    param_1[0x14] = 0x32;
    param_1[0x2f] = 100;
    param_1[0x50] = 100;
    param_1[0x51] = 0x1e;
    param_1[0x52] = 0x14;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x53] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x53] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x3f] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x19] = 100;
      return;
    }
    param_1[0x19] = 0x50;
    param_1[0x3f] = 0x14;
    return;
  }
  param_1[0x19] = 0x3c;
  param_1[0x3f] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupGreek
// Address: 00517cd0
// [HELPER] s_Setting_up_as_Greeks_: "Setting up as Greeks."
/* public: void __thiscall TRIBE_Player::setupGreek(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupGreek(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Greeks_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      param_1[0x24] = 100;
      return;
    }
    param_1[6] = 0x1e;
    param_1[0xb] = 0x1e;
    param_1[0x14] = 0x1e;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[3] = 0x46;
    param_1[4] = 0x32;
    param_1[7] = 0x14;
    param_1[0x13] = 0x32;
    param_1[0x30] = 100;
    param_1[0x54] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x55] = 200;
      param_1[0x56] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x55] = 100;
      param_1[0x56] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x40] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x1a] = 100;
      return;
    }
    param_1[0x1a] = 0x50;
    param_1[0x40] = 0x14;
    return;
  }
  param_1[0x1a] = 0x3c;
  param_1[0x40] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupBabylonian
// Address: 00517e10
// [HELPER] s_Setting_up_as_Babylonians_: "Setting up as Babylonians."
/* public: void __thiscall TRIBE_Player::setupBabylonian(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupBabylonian(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Babylonians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_1[1] = 10;
    param_1[6] = 10;
    param_1[9] = 10;
    param_1[0xb] = 10;
    *param_1 = 0x14;
    param_1[0x13] = 0x28;
    param_1[0x14] = 0x28;
    param_1[0x10] = 0x1e;
    param_1[0x2a] = 100;
    param_1[0x2b] = 100;
    param_1[3] = 0x14;
    param_1[10] = 0x14;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x4d] = 0x3c;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x4d] = 0x1e;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x3d] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x17] = 100;
      return;
    }
    param_1[0x17] = 0x50;
    param_1[0x3d] = 0x14;
    return;
  }
  param_1[0x17] = 0x3c;
  param_1[0x3d] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupAssyrian
// Address: 00517f30
// [HELPER] s_Setting_up_as_Assyrians_: "Setting up as Assyrians."
/* public: void __thiscall TRIBE_Player::setupAssyrian(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupAssyrian(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Assyrians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      param_1[0x22] = 100;
      return;
    }
    param_1[3] = 10;
    param_1[7] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0x14] = 10;
    param_1[0x48] = 0x50;
    param_1[0x49] = 0x50;
    param_1[0x4a] = 0x50;
    param_1[0x10] = 0x28;
    param_1[0xb] = 0x28;
    param_1[6] = 0x14;
    param_1[0x13] = 0x14;
    param_1[0x28] = 100;
    param_1[0x29] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x4b] = 100;
      param_1[0x4c] = 100;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x4b] = 0x32;
      param_1[0x4c] = 0x32;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x3c] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x16] = 100;
      return;
    }
    param_1[0x16] = 0x50;
    param_1[0x3c] = 0x14;
    return;
  }
  param_1[0x16] = 0x3c;
  param_1[0x3c] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupMinoan
// Address: 00518090
// [HELPER] s_Setting_up_as_Minoans_: "Setting up as Minoans."
/* public: void __thiscall TRIBE_Player::setupMinoan(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupMinoan(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Minoans_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      param_1[0x25] = 100;
      return;
    }
    param_1[4] = 10;
    param_1[6] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0xb] = 10;
    *param_1 = 0x3c;
    param_1[1] = 0x50;
    param_1[3] = 0x14;
    param_1[0x33] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x58] = 200;
      param_1[0x59] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x58] = 100;
      param_1[0x59] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x42] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x1c] = 100;
      return;
    }
    param_1[0x1c] = 0x50;
    param_1[0x42] = 0x14;
    return;
  }
  param_1[0x1c] = 0x3c;
  param_1[0x42] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupHittite
// Address: 005181c0
// [HELPER] s_Setting_up_as_Hittites_: "Setting up as Hittites."
/* public: void __thiscall TRIBE_Player::setupHittite(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupHittite(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Hittites_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_1[4] = 0x28;
    param_1[0x12] = 0x28;
    param_1[0x10] = 0x50;
    param_1[0x31] = 100;
    param_1[0x32] = 100;
    param_1[3] = 0x1e;
    param_1[6] = 0x14;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0xb] = 10;
    param_1[0x11] = 0x14;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x57] = 0xa0;
      *param_1 = 0x14;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x57] = 0x50;
      *param_1 = 10;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x41] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x1b] = 100;
      return;
    }
    param_1[0x1b] = 0x50;
    param_1[0x41] = 0x14;
    return;
  }
  param_1[0x1b] = 0x3c;
  param_1[0x41] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupPhoenician
// Address: 005182e0
// [HELPER] s_Setting_up_as_Phoenicians_: "Setting up as Phoenicians."
/* public: void __thiscall TRIBE_Player::setupPhoenician(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupPhoenician(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Phoenicians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_1[3] = 10;
    param_1[4] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0xb] = 10;
    param_1[0x11] = 0x46;
    param_1[0x12] = 0x46;
    *param_1 = 0x14;
    param_1[6] = 0x14;
    param_1[0x13] = 0x14;
    param_1[1] = 0x28;
    param_1[0x14] = 0x1e;
    param_1[0x35] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x5c] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x5c] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x44] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x1e] = 100;
      return;
    }
    param_1[0x1e] = 0x50;
    param_1[0x44] = 0x14;
    return;
  }
  param_1[0x1e] = 0x3c;
  param_1[0x44] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupSumerian
// Address: 00518400
// [HELPER] s_Setting_up_as_Sumerians_: "Setting up as Sumerians."
/* public: void __thiscall TRIBE_Player::setupSumerian(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupSumerian(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Sumerians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      param_1[0x26] = 100;
      return;
    }
    param_1[3] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0xb] = 10;
    param_1[4] = 0x14;
    param_1[0x11] = 0x14;
    param_1[0x10] = 0x1e;
    param_1[0x39] = 100;
    param_1[0x3a] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x5e] = 200;
      param_1[0x5f] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x5e] = 100;
      param_1[0x5f] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x46] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x20] = 100;
      return;
    }
    param_1[0x20] = 0x50;
    param_1[0x46] = 0x14;
    return;
  }
  param_1[0x20] = 0x3c;
  param_1[0x46] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupPersian
// Address: 00518540
// [HELPER] s_Setting_up_as_Persians_: "Setting up as Persians."
/* public: void __thiscall TRIBE_Player::setupPersian(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupPersian(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Persians_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_1[6] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0x11] = 0x3c;
    param_1[0x12] = 0x3c;
    param_1[1] = 0x28;
    param_1[0xb] = 0x28;
    param_1[0x14] = 0x28;
    *param_1 = 0x14;
    param_1[0x10] = 0x14;
    param_1[7] = 0x32;
    param_1[0x13] = 0x14;
    param_1[0x34] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x5a] = 200;
      param_1[0x5b] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x5a] = 100;
      param_1[0x5b] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x43] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x1d] = 100;
      return;
    }
    param_1[0x1d] = 0x50;
    param_1[0x43] = 0x14;
    return;
  }
  param_1[0x1d] = 0x3c;
  param_1[0x43] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupShang
// Address: 00518670
// [HELPER] s_Setting_up_as_Shang_: "Setting up as Shang."
/* public: void __thiscall TRIBE_Player::setupShang(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupShang(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Shang_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    *param_1 = 10;
    param_1[3] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[6] = 0x32;
    param_1[7] = 0x32;
    param_1[0x38] = 0x32;
    param_1[0xb] = 0x1e;
    param_1[0x14] = 0x1e;
    param_1[1] = 0x14;
    param_1[0x10] = 0x14;
    param_1[0x13] = 0x14;
    param_1[0x36] = 100;
    param_1[0x37] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x5d] = 0xa0;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x5d] = 0x50;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x45] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x1f] = 100;
      return;
    }
    param_1[0x1f] = 0x50;
    param_1[0x45] = 0x14;
    return;
  }
  param_1[0x1f] = 0x3c;
  param_1[0x45] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupYamato
// Address: 005187a0
// [HELPER] s_Setting_up_as_Yamato_: "Setting up as Yamato."
/* public: void __thiscall TRIBE_Player::setupYamato(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupYamato(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  int iVar2;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Yamato_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    iVar2 = RGE_Base_Game::difficulty(rge_base_game);
    if (iVar2 < 1) {
      param_1[0x27] = 100;
      return;
    }
    param_1[3] = 10;
    param_1[4] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[6] = 0x32;
    param_1[7] = 0x32;
    *param_1 = 0x14;
    param_1[1] = 0x14;
    param_1[0x10] = 0x28;
    param_1[0xb] = 0x14;
    param_1[0x3b] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x60] = 200;
      param_1[0x61] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x60] = 100;
      param_1[0x61] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x47] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x21] = 100;
      return;
    }
    param_1[0x21] = 0x50;
    param_1[0x47] = 0x14;
    return;
  }
  param_1[0x21] = 0x3c;
  param_1[0x47] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupChoson
// Address: 005188f0
// [HELPER] s_Setting_up_as_Choson_: "Setting up as Choson."
/* public: void __thiscall TRIBE_Player::setupChoson(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupChoson(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Choson_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_1[1] = 10;
    param_1[0x10] = 10;
    param_1[3] = 10;
    param_1[7] = 0x1e;
    param_1[9] = 0x1e;
    param_1[10] = 0x1e;
    *param_1 = 0x14;
    param_1[6] = 0x14;
    param_1[0xb] = 0x46;
    param_1[0x13] = 0x32;
    param_1[0x14] = 0x5a;
    param_1[0x2c] = 100;
    param_1[0x2d] = 100;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x4e] = 200;
      param_1[0x4f] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x4e] = 100;
      param_1[0x4f] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x3e] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x18] = 100;
      return;
    }
    param_1[0x18] = 0x50;
    param_1[0x3e] = 0x14;
    return;
  }
  param_1[0x18] = 0x3c;
  param_1[0x3e] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupRoman
// Address: 00518a20
// [HELPER] s_Setting_up_as_Roman_: "Setting up as Roman."
/* public: void __thiscall TRIBE_Player::setupRoman(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupRoman(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Roman_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    *param_1 = 10;
    param_1[6] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0x13] = 10;
    param_1[0x14] = 10;
    param_1[3] = 0x14;
    param_1[4] = 0x14;
    param_1[0xb] = 0x50;
    param_1[0x70] = 100;
    param_1[0x71] = 0x3c;
    param_1[0x72] = 0x50;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x73] = 200;
      param_1[0x74] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x73] = 100;
      param_1[0x74] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x7c] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x78] = 100;
      return;
    }
    param_1[0x78] = 0x50;
    param_1[0x7c] = 0x14;
    return;
  }
  param_1[0x78] = 0x3c;
  param_1[0x7c] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupCarthaginian
// Address: 00518b50
// [HELPER] s_Setting_up_as_Carthaginian_: "Setting up as Carthaginian."
/* public: void __thiscall TRIBE_Player::setupCarthaginian(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupCarthaginian(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Carthaginian_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    *param_1 = 10;
    param_1[1] = 10;
    param_1[0x10] = 10;
    param_1[7] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0xb] = 10;
    param_1[0x11] = 0x3c;
    param_1[0x12] = 0x3c;
    param_1[3] = 0x46;
    param_1[0x62] = 0x50;
    param_1[99] = 0x50;
    param_1[4] = 0x32;
    param_1[6] = 0x1e;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[100] = 200;
      param_1[0x65] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[100] = 100;
      param_1[0x65] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x79] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x75] = 100;
      return;
    }
    param_1[0x75] = 0x50;
    param_1[0x79] = 0x14;
    return;
  }
  param_1[0x75] = 0x3c;
  param_1[0x79] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupPalmyran
// Address: 00518c90
// [HELPER] s_Setting_up_as_Palmyran_: "Setting up as Palmyran."
/* public: void __thiscall TRIBE_Player::setupPalmyran(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupPalmyran(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Palmyran_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_1[3] = 0x28;
    param_1[6] = 0x28;
    *param_1 = 0x1e;
    param_1[7] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0xb] = 10;
    param_1[1] = 0x1e;
    param_1[0x6b] = 0x50;
    param_1[0x6c] = 0x50;
    param_1[0x6d] = 0x50;
    param_1[0x10] = 0x3c;
    param_1[4] = 0x14;
    param_1[0x11] = 0x3c;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x6e] = 200;
      param_1[0x6f] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x6e] = 100;
      param_1[0x6f] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x7b] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x77] = 100;
      return;
    }
    param_1[0x77] = 0x50;
    param_1[0x7b] = 0x14;
    return;
  }
  param_1[0x77] = 0x3c;
  param_1[0x7b] = 0x28;
  return;
}

// --------------------------------------------------

// Function: setupMacedonian
// Address: 00518dd0
// [HELPER] s_Setting_up_as_Macedonian_: "Setting up as Macedonian."
/* public: void __thiscall TRIBE_Player::setupMacedonian(int *,int,int,int) */

void __thiscall
TRIBE_Player::setupMacedonian(TRIBE_Player *this,int *param_1,int param_2,int param_3,int param_4)
{
  uchar uVar1;
  
  AIModule::logCommonHistory((AIModule *)this,(char *)this->playerAI,s_Setting_up_as_Macedonian_);
  uVar1 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if (uVar1 != '\x01') {
    param_1[3] = 0x28;
    param_1[4] = 0x28;
    *param_1 = 10;
    param_1[6] = 0x1e;
    param_1[7] = 0x1e;
    param_1[0x11] = 0x1e;
    param_1[0x68] = 0x50;
    param_1[0x66] = 0x50;
    param_1[0x67] = 0x50;
    param_1[1] = 10;
    param_1[0x10] = 0x14;
    if ((param_2 == 0) || (param_2 == 1)) {
      param_1[0x69] = 200;
      param_1[0x6a] = 200;
    }
    else if ((((param_2 == 2) || (param_2 == 6)) || (param_2 == 8)) || (param_2 == 5)) {
      param_1[0x69] = 100;
      param_1[0x6a] = 100;
      return;
    }
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    param_1[0x7a] = 100;
    return;
  }
  if ((param_2 != 2) && (param_2 != 6)) {
    if ((param_2 != 5) && (param_2 != 8)) {
      param_1[0x76] = 100;
      return;
    }
    param_1[0x76] = 0x50;
    param_1[0x7a] = 0x14;
    return;
  }
  param_1[0x76] = 0x3c;
  param_1[0x7a] = 0x28;
  return;
}

// --------------------------------------------------

// Function: logStatus
// Address: 00518f00
// [HELPER] s_Build_AI__last__s__last2__s__Pro: "Build AI: last=%s, last2=%s, Progress=%d/%d.\n"
// [HELPER] s_Civilians__Total__d__Exp__d__d__: "Civilians: Total=%d, Exp(%d/%d), Gat(%d/%d).  NRes:%d%d%d%d.\n"
// [HELPER] s_Number_Soldiers__d__: "Number Soldiers=%d.\n"
// [HELPER] s_Player__d__: "Player %d:\n"
// [HELPER] s___Build_List________s__: "  Build List:      %s.\n"
// [HELPER] s___City_Plan_________s__: "  City Plan:       %s.\n"
// [HELPER] s___Computer_Player___s__: "  Computer Player, %s.\n"
// [HELPER] s___Exploration_______d__: "  Exploration:     %d.\n"
// [HELPER] s___Food______________d__: "  Food:            %d.\n"
// [HELPER] s___Gold______________d__: "  Gold:            %d.\n"
// [HELPER] s___Human_Player___s__: "  Human Player, %s.\n"
// [HELPER] s___Kill_Ratio________d__: "  Kill Ratio:      %d.\n"
// [HELPER] s___Kills_____________d__: "  Kills:           %d.\n"
// [HELPER] s___Points__: "  Points:\n"
// [HELPER] s___Population________d__: "  Population:      %d.\n"
// [HELPER] s___Razings___________d__: "  Razings:         %d.\n"
// [HELPER] s___Stone_____________d__: "  Stone:           %d.\n"
// [HELPER] s___Technology________d__: "  Technology:      %d.\n"
// [HELPER] s___VC_File___________s__: "  VC File:         %s.\n"
// [HELPER] s___Wood______________d__: "  Wood:            %d.\n"
// [HELPER] s_____Combat__________d__: "    Combat         %d.\n"
// [HELPER] s_____Economy_________d__: "    Economy        %d.\n"
// [HELPER] s_____Religion________d__: "    Religion       %d.\n"
// [HELPER] s_____Science_________d__: "    Science        %d.\n"
// [HELPER] s_____Survival________d__: "    Survival       %d.\n"
// [HELPER] s_____Wonder__________d__: "    Wonder         %d.\n"
// [HELPER] s_______Total_________d__: "      Total:       %d.\n"
/* WARNING: Variable defined which should be unmapped: tempString */
/* public: virtual void __thiscall TRIBE_Player::logStatus(struct _iobuf *,int) */

void __thiscall TRIBE_Player::logStatus(TRIBE_Player *this,_iobuf *param_1,int param_2)
{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char tempString [256];
  
  if (param_1 != (_iobuf *)0x0) {
    fprintf(param_1,s_Player__d__,(int)*(short *)((int)&this->_padding_ + 2));
    if (param_2 == 1) {
      (**(code **)(rge_base_game->_padding_ + 0x20))
                (*(byte *)((int)&this->_padding_ + 1) + 0x27f6,tempString + 4,0x100);
      if (this->playerAI == (TribeMainDecisionAIModule *)0x0) {
        pcVar5 = tempString + 4;
        pcVar9 = s___Human_Player___s__;
      }
      else {
        fprintf(param_1,s___Computer_Player___s__,tempString + 4);
        pcVar5 = BuildAIModule::buildListName((BuildAIModule *)&this->playerAI->buildAI);
        fprintf(param_1,s___Build_List________s__,pcVar5);
        pcVar5 = ConstructionAIModule::constructionPlanName
                           ((ConstructionAIModule *)&this->playerAI->constructionAI);
        fprintf(param_1,s___City_Plan_________s__,pcVar5);
        pcVar5 = TribeStrategyAIModule::ruleSetName(&this->playerAI->strategyAI);
        pcVar9 = s___VC_File___________s__;
      }
      fprintf(param_1,pcVar9,pcVar5);
    }
    fprintf(param_1,s___Points__);
    lVar1 = RGE_Victory_Conditions::get_victory_points_group
                      ((RGE_Victory_Conditions *)this->_padding_,'\0');
    fprintf(param_1,s_____Combat__________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_group
                      ((RGE_Victory_Conditions *)this->_padding_,'\x01');
    fprintf(param_1,s_____Economy_________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_group
                      ((RGE_Victory_Conditions *)this->_padding_,'\x02');
    fprintf(param_1,s_____Religion________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_group
                      ((RGE_Victory_Conditions *)this->_padding_,'\x03');
    fprintf(param_1,s_____Science_________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_id
                      ((RGE_Victory_Conditions *)this->_padding_,'\x16');
    fprintf(param_1,s_____Survival________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points_id
                      ((RGE_Victory_Conditions *)this->_padding_,'\x17');
    fprintf(param_1,s_____Wonder__________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_victory_points((RGE_Victory_Conditions *)this->_padding_);
    fprintf(param_1,s_______Total_________d__,lVar1);
    uVar2 = __ftol();
    fprintf(param_1,s___Population________d__,uVar2);
    lVar1 = RGE_Victory_Conditions::get_attribute_id((RGE_Victory_Conditions *)this->_padding_,'\0')
    ;
    fprintf(param_1,s___Kills_____________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_attribute_id
                      ((RGE_Victory_Conditions *)this->_padding_,'\x02');
    fprintf(param_1,s___Kill_Ratio________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_attribute_id
                      ((RGE_Victory_Conditions *)this->_padding_,'\x01');
    fprintf(param_1,s___Razings___________d__,lVar1);
    uVar2 = __ftol();
    fprintf(param_1,s___Food______________d__,uVar2);
    uVar2 = __ftol();
    fprintf(param_1,s___Gold______________d__,uVar2);
    uVar2 = __ftol();
    fprintf(param_1,s___Stone_____________d__,uVar2);
    uVar2 = __ftol();
    fprintf(param_1,s___Wood______________d__,uVar2);
    lVar1 = RGE_Victory_Conditions::get_attribute_id
                      ((RGE_Victory_Conditions *)this->_padding_,'\x11');
    fprintf(param_1,s___Technology________d__,lVar1);
    lVar1 = RGE_Victory_Conditions::get_attribute_id((RGE_Victory_Conditions *)this->_padding_,'\a')
    ;
    fprintf(param_1,s___Exploration_______d__,lVar1);
    if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
      iVar3 = BuildAIModule::buildListLength((BuildAIModule *)&this->playerAI->buildAI);
      iVar4 = BuildAIModule::numberItemsIntoBuildList((BuildAIModule *)&this->playerAI->buildAI);
      pcVar5 = BuildAIModule::lastBuildItemRequested((BuildAIModule *)&this->playerAI->buildAI);
      pcVar9 = BuildAIModule::currentBuildItemRequested((BuildAIModule *)&this->playerAI->buildAI);
      fprintf(param_1,s_Build_AI__last__s__last2__s__Pro,pcVar9,pcVar5,iVar4,iVar3);
      TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,3);
      TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,2);
      TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,1);
      TribeTacticalAIModule::neededResource(&this->playerAI->tacticalAI,0);
      iVar3 = TribeTacticalAIModule::desiredNumberGatherers(&this->playerAI->tacticalAI);
      iVar4 = TribeTacticalAIModule::numberGatherers(&this->playerAI->tacticalAI);
      iVar6 = TribeTacticalAIModule::desiredNumberCivilianExplorers(&this->playerAI->tacticalAI);
      iVar7 = TribeTacticalAIModule::numberCivilianExplorers(&this->playerAI->tacticalAI);
      iVar8 = TribeTacticalAIModule::numberCivilians(&this->playerAI->tacticalAI);
      fprintf(param_1,s_Civilians__Total__d__Exp__d__d__,iVar8,iVar7,iVar6,iVar4,iVar3);
      iVar3 = TribeTacticalAIModule::numberSoldiers(&this->playerAI->tacticalAI);
      fprintf(param_1,s_Number_Soldiers__d__,iVar3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: trackUnitGather
// Address: 005192f0
/* public: virtual void __thiscall TRIBE_Player::trackUnitGather(int,int,int) */

void __thiscall
TRIBE_Player::trackUnitGather(TRIBE_Player *this,int param_1,int param_2,int param_3)
{
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    TribeTacticalAIModule::trackUnitGather(&this->playerAI->tacticalAI,param_1,param_2,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: get_achievement
// Address: 00519320
// [HELPER] s__3_f__: "%3.f%%"
// [HELPER] s__4_f: "%4.f"
// [HELPER] s__4_f__4_f__4_f: "%4.f/%4.f/%4.f"
// [HELPER] s__5_f: "%5.f"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TRIBE_Player::get_achievement(unsigned char,char *) */

void __thiscall TRIBE_Player::get_achievement(TRIBE_Player *this,uchar param_1,char *param_2)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  float fVar7;
  
  switch(param_1) {
  case '\0':
    uVar3 = 0xffffffff;
    pcVar5 = (char *)this->_padding_;
    do {
      pcVar6 = pcVar5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar5 = pcVar6 + -uVar3;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)param_2 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      param_2 = param_2 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      param_2 = param_2 + 1;
    }
    return;
  case '\x01':
    fVar7 = *(float *)(this->_padding_ + 0x4c) - *(float *)(this->_padding_ + 0x2c);
    break;
  case '\x02':
    sprintf(param_2,s__4_f,(double)*(float *)(this->_padding_ + 0x50));
    return;
  case '\x03':
    sprintf(param_2,s__4_f,(double)*(float *)(this->_padding_ + 0x2c));
    return;
  case '\x04':
    sprintf(param_2,s__5_f,(double)*(float *)(this->_padding_ + 0xc));
    return;
  case '\x05':
    fVar7 = RGE_Visible_Map::percentExplored((RGE_Visible_Map *)this->_padding_);
    sprintf(param_2,s__3_f__,(double)(fVar7 * _DAT_0057682c));
    return;
  case '\x06':
    fVar7 = *(float *)(this->_padding_ + 0x4c);
    break;
  case '\a':
    iVar2 = this->_padding_;
    sprintf(param_2,s__4_f__4_f__4_f,(double)*(float *)(iVar2 + 0x1c),
            (double)*(float *)(iVar2 + 0x34),(double)*(float *)(iVar2 + 0x38));
    return;
  case '\b':
    fVar7 = *(float *)(this->_padding_ + 0x54);
    break;
  default:
    goto switchD_00519334_default;
  }
  sprintf(param_2,s__4_f,(double)fVar7);
switchD_00519334_default:
  return;
}

// --------------------------------------------------

// Function: load_victory
// Address: 00519490
/* public: virtual void __thiscall TRIBE_Player::load_victory(int,long *,unsigned char) */

void __thiscall
TRIBE_Player::load_victory(TRIBE_Player *this,int param_1,long *param_2,uchar param_3)
{
  TRIBE_Victory_Conditions *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056129b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Victory_Conditions *)operator_new(0x20);
  local_4 = 0;
  if (this_00 == (TRIBE_Victory_Conditions *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_Victory_Conditions::TRIBE_Victory_Conditions
                      (this_00,(RGE_Player *)this,param_1,param_2,param_3);
  }
  this->_padding_ = iVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: new_victory
// Address: 00519500
/* public: virtual void __thiscall TRIBE_Player::new_victory(void) */

void __thiscall TRIBE_Player::new_victory(TRIBE_Player *this)
{
  TRIBE_Victory_Conditions *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005612bb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Victory_Conditions *)operator_new(0x20);
  local_4 = 0;
  if (this_00 != (TRIBE_Victory_Conditions *)0x0) {
    iVar1 = TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(this_00,(RGE_Player *)this);
    this->_padding_ = iVar1;
    *unaff_FS_OFFSET = local_c;
    return;
  }
  this->_padding_ = 0;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: add_attribute_num
// Address: 00519570
/* public: virtual void __thiscall TRIBE_Player::add_attribute_num(short,float,unsigned char) */

void __thiscall
TRIBE_Player::add_attribute_num(TRIBE_Player *this,short param_1,float param_2,uchar param_3)
{
  if ((param_1 == 3) && (param_3 != '\0')) {
    *(float *)(this->_padding_ + 0xc4) = param_2 + *(float *)(this->_padding_ + 0xc4);
  }
  if (param_1 == 0x32) {
    this->_padding_ = 1;
    RGE_Game_World::update_mutual_allies((RGE_Game_World *)this->_padding_);
  }
  RGE_Player::add_attribute_num((RGE_Player *)this,param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: analyize_selected_objects
// Address: 005195d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Player::analyize_selected_objects(void) */

void __thiscall TRIBE_Player::analyize_selected_objects(TRIBE_Player *this)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  DAT_0086bc8c = 0;
  this->_padding_ = 0;
  if ((short)this->_padding_ != 0) {
    iVar5 = 0;
    piVar3 = &this->_padding_;
    do {
      if ((short)this->_padding_ <= iVar5) {
        return;
      }
      iVar2 = *piVar3;
      if (iVar2 != 0) {
        if (*(short *)(*(int *)(iVar2 + 0xc) + 0x4a) == *(short *)((int)&this->_padding_ + 2)) {
          iVar2 = (int)*(short *)(*(int *)(iVar2 + 8) + 0x14);
          if ((-1 < iVar2) && (iVar2 < tribe_group_properties_num)) {
            if (iVar2 == 0x12) {
              this->_padding_ = this->_padding_ | 0x16;
              DAT_0086bc8c = DAT_0086bc8c + 1;
              DAT_0086bc88 = *(undefined4 *)(*piVar3 + 4);
              if (_DAT_0057682c <= *(float *)(*piVar3 + 0x44)) {
                this->_padding_ = this->_padding_ | 0x80;
              }
            }
            else {
              this->_padding_ = this->_padding_ | (uint)(&tribe_group_properties)[iVar2];
            }
          }
          sVar1 = *(short *)(*(int *)(*piVar3 + 8) + 0x10);
          if ((((sVar1 == 0x4f) || (sVar1 == 199)) || (sVar1 == 0x45)) || (sVar1 == 0x116)) {
            this->_padding_ = this->_padding_ | 1;
          }
        }
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < 0x19);
  }
  return;
}

// --------------------------------------------------

// Function: get_mouse_pointer_action_vars
// Address: 005196e0
/* WARNING: Variable defined which should be unmapped: ObjectType */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual int __thiscall TRIBE_Player::get_mouse_pointer_action_vars(int,int &,int &) */

int __thiscall
TRIBE_Player::get_mouse_pointer_action_vars
          (TRIBE_Player *this,int param_1,int *param_2,int *param_3)
{
  short sVar1;
  short sVar2;
  short sVar3;
  RGE_Player *pRVar4;
  RGE_Master_Static_Object *pRVar5;
  bool bVar6;
  RGE_Static_Object *pRVar7;
  int iVar8;
  RGE_Prog_Info *pRVar9;
  RGE_Sprite *pRVar10;
  RGE_Scenario_File_Info *pRVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  RGE_Scenario_File_Info *pRVar15;
  int ObjectType;
  int ObjPlayer;
  RGE_Static_Object *thisObj;
  int MaxHp;
  int MstrObjId;
  int RtClickTable;
  
  pRVar7 = RGE_Game_World::object((RGE_Game_World *)this->_padding_,param_1);
  iVar12 = 0;
  *param_2 = 0;
  *param_3 = 0;
  if (pRVar7 != (RGE_Static_Object *)0x0) {
    if (pRVar7->type == '\x19') {
      pRVar4 = pRVar7[1].owner;
      pRVar10 = pRVar7[1].sprite;
      sVar2 = (short)pRVar4->checksum;
      sVar3 = (short)pRVar4->currentUpdatePathingAttemptsValue;
      sVar1 = *(short *)((int)&pRVar4->master_objects + 2);
    }
    else {
      pRVar5 = pRVar7->master_obj;
      sVar2 = pRVar5->object_group;
      pRVar10 = (RGE_Sprite *)(int)pRVar7->owner->id;
      sVar3 = pRVar5->id;
      sVar1 = pRVar5->hp;
    }
    RtClickTable = (int)sVar3;
    MstrObjId = (int)sVar1;
    ObjPlayer = (int)sVar2;
    if ((-1 < (int)pRVar10) && ((int)pRVar10 < (int)*(short *)(this->_padding_ + 0x3c))) {
      (**(code **)(this->_padding_ + 0x98))();
      if ((RtClickTable == 0x9e) || (RtClickTable == 0xa3)) {
        iVar12 = 0x32;
      }
LAB_005197aa:
      pcVar13 = (char *)0x0;
                    /* Symbol Ref: {@symbol retry_table} */
      if (((short)this->_padding_ == 0) || (this->_padding_ == 0)) {
        bVar6 = false;
        pRVar15 = rge_base_game[1].scenario_info;
        pRVar9 = rge_base_game[1].prog_info;
      }
      else {
        bVar6 = true;
        pRVar15 = (RGE_Scenario_File_Info *)rge_base_game[1]._padding_;
        pRVar9 = (RGE_Prog_Info *)rge_base_game[1].player_game_info;
      }
      if (((-1 < ObjPlayer) && (ObjPlayer < (int)pRVar9)) &&
         (*(int *)(pRVar15->filename + ObjPlayer * 0x2c) == ObjPlayer)) {
        pcVar13 = pRVar15->filename + ObjPlayer * 0x2c;
      }
      if (pcVar13 == (char *)0x0) {
        iVar8 = 0;
        pRVar11 = pRVar15;
        if (0 < (int)pRVar9) {
          do {
            if (*(int *)pRVar11->filename == ObjPlayer) {
              pcVar13 = pRVar15->filename + iVar8 * 0x2c;
              break;
            }
            iVar8 = iVar8 + 1;
            pRVar11 = (RGE_Scenario_File_Info *)(pRVar11->filename + 0x2c);
          } while (iVar8 < (int)pRVar9);
        }
        if (pcVar13 == (char *)0x0) {
          return 0;
        }
      }
      switch((&this->_padding_)[(int)pRVar10]) {
      case 0:
        iVar8 = *(int *)(pcVar13 + 0xc);
        iVar14 = *(int *)(pcVar13 + 0x10);
        break;
      case 1:
        iVar8 = *(int *)(pcVar13 + 4);
        iVar14 = *(int *)(pcVar13 + 8);
        break;
      case 2:
        iVar8 = *(int *)(pcVar13 + 0x14);
        iVar14 = *(int *)(pcVar13 + 0x18);
        break;
      case 3:
        iVar8 = *(int *)(pcVar13 + 0x1c);
        iVar14 = *(int *)(pcVar13 + 0x20);
        break;
      case 4:
        iVar8 = *(int *)(pcVar13 + 0x24);
        iVar14 = *(int *)(pcVar13 + 0x28);
        break;
      default:
        iVar8 = -1;
        iVar14 = -1;
      }
      if (iVar8 != -1) {
        do {
                    /* Symbol Ref: {@symbol redo_mouseFunc} */
          switch(iVar8) {
          case 0:
            goto switchD_0051989c_caseD_0;
          case 1:
          case 8:
            if (((this->_padding_ & 1) != 0) && (pRVar7->object_state < 3)) {
              *param_2 = 4;
              *param_3 = iVar12 + iVar14;
              goto LAB_005198fc;
            }
            if (iVar8 != 8) goto LAB_005198fc;
            iVar8 = 7;
            break;
          case 2:
            if ((this->_padding_ & 2) != 0) goto LAB_005199c6;
            goto LAB_005198fc;
          case 3:
            if ((this->_padding_ & 4) != 0) {
              *param_2 = 5;
              *param_3 = iVar12 + iVar14;
            }
            goto LAB_005198fc;
          case 4:
            if (((this->_padding_ & 0x10) != 0) &&
               ((((DAT_0086bc8c != 1 || (param_1 != DAT_0086bc88)) && (iVar8 = __ftol(), 0 < iVar8))
                && (iVar8 < MstrObjId)))) {
LAB_005199c6:
              *param_2 = 5;
              *param_3 = iVar12 + iVar14;
            }
            goto LAB_005198fc;
          case 5:
            if ((this->_padding_ & 0x20) != 0) {
              if (pRVar7->object_state == '\0') {
                iVar12 = 0x32;
              }
              iVar8 = __ftol();
              if ((0 < iVar8) && (iVar8 < MstrObjId)) {
                *param_2 = 3;
                *param_3 = iVar12 + iVar14;
              }
            }
            goto LAB_005198fc;
          case 6:
          case 9:
            if ((this->_padding_ & 0x40) != 0) {
              *param_2 = 3;
              *param_3 = iVar12 + iVar14;
              goto LAB_005198fc;
            }
            if (iVar8 != 9) goto LAB_005198fc;
            iVar8 = 1;
            break;
          case 7:
            if ((((this->_padding_ & 0x80) != 0) &&
                ((ObjPlayer != 0x12 || (*(float *)(this->_padding_ + 0x6c) != _DAT_00576828)))) &&
               ((ObjPlayer != 3 ||
                (((*(float *)(this->_padding_ + 0x70) != _DAT_00576828 && (RtClickTable != 0x6d)) &&
                 (RtClickTable != 0x114)))))) {
              *param_2 = 5;
              *param_3 = iVar12 + iVar14;
            }
            goto LAB_005198fc;
          default:
            *param_2 = 0;
            *param_3 = 0;
            goto LAB_005198fc;
          }
          iVar12 = 0x32;
        } while( true );
      }
    }
  }
  return 0;
switchD_0051989c_caseD_0:
  *param_2 = 0;
  *param_3 = iVar12 + iVar14;
LAB_005198fc:
  if (!bVar6) {
    return 1;
  }
  if (*param_2 != 0) {
    return 1;
  }
  if (*param_3 != 0) {
    return 1;
  }
  this->_padding_ = 0;
  goto LAB_005197aa;
}

// --------------------------------------------------

// Function: ~TRIBE_Player
// Address: 00519bbe
void __thiscall TRIBE_Player::~TRIBE_Player(TRIBE_Player *this)
{
  TRIBE_Player_Tech *this_00;
  TRIBE_History_Info *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_005611d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  this_00 = this->tech_tree;
  uStack_4 = 0;
  if (this_00 != (TRIBE_Player_Tech *)0x0) {
    TRIBE_Player_Tech::~TRIBE_Player_Tech(this_00);
    operator_delete(this_00);
    this->tech_tree = (TRIBE_Player_Tech *)0x0;
  }
  if (this->playerAI != (TribeMainDecisionAIModule *)0x0) {
    (**(code **)this->playerAI->_padding_)(1);
    this->playerAI = (TribeMainDecisionAIModule *)0x0;
  }
  this_01 = this->history;
  if (this_01 != (TRIBE_History_Info *)0x0) {
    TRIBE_History_Info::~TRIBE_History_Info(this_01);
    operator_delete(this_01);
    this->history = (TRIBE_History_Info *)0x0;
  }
  uStack_4 = 0xffffffff;
  RGE_Player::~RGE_Player((RGE_Player *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: scenario_postload
// Address: 00519d50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Player::scenario_postload(int,long *,float) */

void __thiscall
TRIBE_Player::scenario_postload(TRIBE_Player *this,int param_1,long *param_2,float param_3)
{
  RGE_Player::scenario_postload((RGE_Player *)this,param_1,param_2,param_3);
  if ((float)_DAT_00576830 < *(float *)(this->_padding_ + 200)) {
    this->_padding_ = 1;
    RGE_Game_World::update_mutual_allies((RGE_Game_World *)this->_padding_);
  }
  return;
}

// --------------------------------------------------

