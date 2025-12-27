// Class: RGE_Game_World
// Function: RGE_Game_World
// Address: 00540750
// [HELPER] s_c__aoeWVlog_txt: "c:\aoeWVlog.txt"
// [HELPER] s_w: "w"
/* public: __thiscall RGE_Game_World::RGE_Game_World(void) */

RGE_Game_World * __thiscall RGE_Game_World::RGE_Game_World(RGE_Game_World *this)
{
  RGE_Static_Object **ppRVar1;
  RGE_Object_List *pRVar2;
  int iVar3;
  ulong *puVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561c0d;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->objectsValue = (RGE_Static_Object **)0x0;
  this->numberObjectsValue = 0;
  this->maxNumberObjectsValue = 10000;
  this->negativeObjectsValue = (RGE_Static_Object **)0x0;
  this->numberNegativeObjectsValue = 0;
  this->maxNumberNegativeObjectsValue = 1000;
  this->maximumComputerPlayerUpdateTime = 2;
  this->availableComputerPlayerUpdateTime = 2;
  this->currentUpdateComputerPlayer = -1;
  this->difficultyLevelValue = -1;
  this->_padding_ = (int)&_vftable_;
  world_update_counter = 0;
  ppRVar1 = (RGE_Static_Object **)operator_new(this->maxNumberObjectsValue << 2);
  this->objectsValue = ppRVar1;
  ppRVar1 = (RGE_Static_Object **)operator_new(this->maxNumberNegativeObjectsValue << 2);
  this->negativeObjectsValue = ppRVar1;
  VIS_UNIT_objectsValue = this->objectsValue;
  this->playbook = (AIPlayBook *)0x0;
  this->sound_num = 0;
  this->sounds = (RGE_Sound **)0x0;
  this->sprite_num = 0;
  this->sprites = (RGE_Sprite **)0x0;
  this->player_num = 0;
  this->players = (RGE_Player **)0x0;
  this->master_player_num = 0;
  this->master_players = (RGE_Master_Player **)0x0;
  this->terrain_num = 0;
  this->terrains = (float **)0x0;
  this->color_table_num = 0;
  this->color_tables = (RGE_Color_Table **)0x0;
  this->commands = (RGE_Command *)0x0;
  this->scenario = (RGE_Scenario *)0x0;
  this->effects = (RGE_Effects *)0x0;
  this->map = (RGE_Map *)0x0;
  this->world_time = 0;
  this->old_world_time = 0;
  this->world_time_delta = 0;
  this->world_time_delta_seconds = 0.0;
  this->timer = 0.0;
  this->old_time = 0;
  this->game_speed = 0.0;
  this->temp_pause = '\0';
  this->next_object_id = 0;
  this->next_reusable_object_id = -1;
  this->random_seed = 0xe;
  this->curr_player = 1;
  this->sound_driver = (TSound_Driver *)0x0;
  this->game_state = '\x02';
  this->game_end_condition = '\0';
  this->sound_update_index = 0;
  this->sprite_update_index = 0;
  this->player_turn = 0;
  puVar4 = this->player_time_delta;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 0;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    pRVar2 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar2);
  }
  local_4 = 0xffffffff;
  this->reusable_static_objects = pRVar2;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 1;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    pRVar2 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar2);
  }
  local_4 = 0xffffffff;
  this->reusable_animated_objects = pRVar2;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 2;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    pRVar2 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar2);
  }
  local_4 = 0xffffffff;
  this->reusable_moving_objects = pRVar2;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 3;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    pRVar2 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar2);
  }
  local_4 = 0xffffffff;
  this->reusable_action_objects = pRVar2;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 4;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    pRVar2 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar2);
  }
  local_4 = 0xffffffff;
  this->reusable_combat_objects = pRVar2;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 5;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    pRVar2 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar2);
  }
  local_4 = 0xffffffff;
  this->reusable_missile_objects = pRVar2;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  local_4 = 6;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    pRVar2 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar2);
  }
  this->reusable_doppleganger_objects = pRVar2;
  this->scenario_object_flag = '\0';
  if (DVlogf == (_iobuf *)0x0) {
    DVlogf = (_iobuf *)fopen(s_c__aoeWVlog_txt,s_w);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: logStatus
// Address: 00540a10
/* protected: virtual void __thiscall RGE_Game_World::logStatus(struct _iobuf *,int) */

void __thiscall RGE_Game_World::logStatus(RGE_Game_World *this,_iobuf *param_1,int param_2)
{
  return;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00540a20
/* public: virtual void * __thiscall RGE_Game_World::`scalar deleting destructor'(unsigned int) */

void * __thiscall RGE_Game_World::_scalar_deleting_destructor_(RGE_Game_World *this,uint param_1)
{
  ~RGE_Game_World(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Game_World
// Address: 00540a40
/* public: virtual __thiscall RGE_Game_World::~RGE_Game_World(void) */

void __thiscall RGE_Game_World::~RGE_Game_World(RGE_Game_World *this)
{
  RGE_Object_List *pRVar1;
  RGE_Sprite *this_00;
  RGE_Sound *this_01;
  int iVar2;
  
  this->_padding_ = (int)&_vftable_;
  if (this->commands != (RGE_Command *)0x0) {
    (**(code **)(this->commands->_padding_ + 4))(1);
  }
  del_game_info(this);
  pRVar1 = this->reusable_static_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = this->reusable_animated_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = this->reusable_moving_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = this->reusable_action_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = this->reusable_combat_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = this->reusable_missile_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = this->reusable_doppleganger_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  if (this->master_players != (RGE_Master_Player **)0x0) {
    iVar2 = 0;
    if (0 < this->master_player_num) {
      do {
        if (this->master_players[iVar2] != (RGE_Master_Player *)0x0) {
          (**(code **)this->master_players[iVar2]->_padding_)(1);
          this->master_players[iVar2] = (RGE_Master_Player *)0x0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->master_player_num);
    }
    free(this->master_players);
    this->master_players = (RGE_Master_Player **)0x0;
  }
  if (this->effects != (RGE_Effects *)0x0) {
    (**(code **)this->effects->_padding_)(1);
    this->effects = (RGE_Effects *)0x0;
  }
  if (this->map != (RGE_Map *)0x0) {
    (**(code **)this->map->_padding_)(1);
    this->map = (RGE_Map *)0x0;
  }
  if (this->sprites != (RGE_Sprite **)0x0) {
    iVar2 = 0;
    if (0 < this->sprite_num) {
      do {
        this_00 = this->sprites[iVar2];
        if (this_00 != (RGE_Sprite *)0x0) {
          RGE_Sprite::~RGE_Sprite(this_00);
          operator_delete(this_00);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->sprite_num);
    }
    free(this->sprites);
    this->sprites = (RGE_Sprite **)0x0;
  }
  if (this->sounds != (RGE_Sound **)0x0) {
    iVar2 = 0;
    if (0 < this->sound_num) {
      do {
        this_01 = this->sounds[iVar2];
        if (this_01 != (RGE_Sound *)0x0) {
          RGE_Sound::~RGE_Sound(this_01);
          operator_delete(this_01);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->sound_num);
    }
    free(this->sounds);
    this->sounds = (RGE_Sound **)0x0;
  }
  if (this->terrains != (float **)0x0) {
    iVar2 = 0;
    if (0 < this->terrain_num) {
      do {
        if (this->terrains[iVar2] != (float *)0x0) {
          free(this->terrains[iVar2]);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->terrain_num);
    }
    free(this->terrains);
    this->terrains = (float **)0x0;
  }
  if (this->color_tables != (RGE_Color_Table **)0x0) {
    iVar2 = 0;
    if (0 < this->color_table_num) {
      do {
        if (this->color_tables[iVar2] != (RGE_Color_Table *)0x0) {
          (**(code **)this->color_tables[iVar2]->_padding_)(1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->color_table_num);
    }
    free(this->color_tables);
    this->color_tables = (RGE_Color_Table **)0x0;
  }
  if (this->objectsValue != (RGE_Static_Object **)0x0) {
    operator_delete(this->objectsValue);
    this->objectsValue = (RGE_Static_Object **)0x0;
    VIS_UNIT_objectsValue = (RGE_Static_Object **)0x0;
  }
  if (this->negativeObjectsValue != (RGE_Static_Object **)0x0) {
    operator_delete(this->negativeObjectsValue);
    this->negativeObjectsValue = (RGE_Static_Object **)0x0;
  }
  if (logStatusFile != (_iobuf *)0x0) {
    fclose(logStatusFile);
    logStatusFile = (_iobuf *)0x0;
  }
  if (this->playbook != (AIPlayBook *)0x0) {
    (**(code **)this->playbook->_padding_)(1);
    this->playbook = (AIPlayBook *)0x0;
  }
  if (DVlogf != (_iobuf *)0x0) {
    fclose(DVlogf);
    DVlogf = (_iobuf *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: reset_object_count
// Address: 00540cf0
/* public: void __thiscall RGE_Game_World::reset_object_count(void) */

void __thiscall RGE_Game_World::reset_object_count(RGE_Game_World *this)
{
  int iVar1;
  ulong *puVar2;
  
  this->world_time = 0;
  this->old_world_time = 0;
  this->world_time_delta = 0;
  this->world_time_delta_seconds = 0.0;
  this->timer = 0.0;
  this->old_time = 0;
  this->temp_pause = '\0';
  this->next_object_id = 0;
  this->player_turn = 0;
  puVar2 = this->player_time_delta;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: pause
// Address: 00540d30
/* public: virtual void __thiscall RGE_Game_World::pause(unsigned char) */

void __thiscall RGE_Game_World::pause(RGE_Game_World *this,uchar param_1)
{
  int iVar1;
  
  if ((param_1 != '\0') && (iVar1 = 0, 0 < this->sound_num)) {
    do {
      RGE_Sound::stop(this->sounds[iVar1]);
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->sound_num);
  }
  return;
}

// --------------------------------------------------

// Function: set_map_visible
// Address: 00540d60
/* public: void __thiscall RGE_Game_World::set_map_visible(unsigned char) */

void __thiscall RGE_Game_World::set_map_visible(RGE_Game_World *this,uchar param_1)
{
  if (this->map != (RGE_Map *)0x0) {
    RGE_Map::set_map_visible(this->map,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: set_map_fog
// Address: 00540d80
/* public: void __thiscall RGE_Game_World::set_map_fog(unsigned char) */

void __thiscall RGE_Game_World::set_map_fog(RGE_Game_World *this,uchar param_1)
{
  if (this->map != (RGE_Map *)0x0) {
    RGE_Map::set_map_fog(this->map,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: data_load_sounds
// Address: 00540da0
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: id */
/* protected: virtual unsigned char __thiscall RGE_Game_World::data_load_sounds(char *) */

uchar __thiscall RGE_Game_World::data_load_sounds(RGE_Game_World *this,char *param_1)
{
  short *psVar1;
  _iobuf *p_Var2;
  int iVar3;
  RGE_Sound **ppRVar4;
  RGE_Sound *pRVar5;
  undefined4 *unaff_FS_OFFSET;
  short id;
  short index;
  int local_14;
  RGE_Sound *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561c2b;
  *unaff_FS_OFFSET = &local_c;
  p_Var2 = (_iobuf *)fopen(param_1,s_r);
  if (p_Var2 != (_iobuf *)0x0) {
    psVar1 = &this->sound_num;
    iVar3 = fscanf(p_Var2,s__hd__hd,psVar1,&param_1);
    if (iVar3 == -1) {
      *psVar1 = 0;
      this->sounds = (RGE_Sound **)0x0;
    }
    else {
      ppRVar4 = (RGE_Sound **)calloc((int)*psVar1,4);
      this->sounds = ppRVar4;
      local_14 = 0;
      if (0 < (short)param_1) {
        do {
          iVar3 = fscanf(p_Var2,s__hd,&index);
          if (iVar3 != -1) {
            local_10 = (RGE_Sound *)operator_new(0x10);
            local_4 = 0;
            if (local_10 == (RGE_Sound *)0x0) {
              pRVar5 = (RGE_Sound *)0x0;
            }
            else {
              pRVar5 = (RGE_Sound *)RGE_Sound::RGE_Sound(local_10,p_Var2,(short)_index);
            }
            local_4 = 0xffffffff;
            this->sounds[index] = pRVar5;
          }
          local_14 = local_14 + 1;
        } while ((short)local_14 < (short)param_1);
      }
    }
    fclose(p_Var2);
  }
  *unaff_FS_OFFSET = local_c;
  return '\x01';
}

// --------------------------------------------------

// Function: data_load_terrain_tables
// Address: 00540eb0
// [HELPER] s__f: "%f"
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: count */
/* protected: virtual unsigned char __thiscall RGE_Game_World::data_load_terrain_tables(char *) */

uchar __thiscall RGE_Game_World::data_load_terrain_tables(RGE_Game_World *this,char *param_1)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  float **ppfVar4;
  float *pfVar5;
  short sVar6;
  short count;
  short index3;
  short index;
  short local_6;
  int local_4;
  
  iVar2 = fopen(param_1,s_r);
  if (iVar2 != 0) {
    psVar1 = &this->terrain_num;
    iVar3 = fscanf(iVar2,s__hd__hd,psVar1,&this->terrain_size);
    if (iVar3 == -1) {
      *psVar1 = 0;
      this->terrains = (float **)0x0;
    }
    else {
      ppfVar4 = (float **)calloc((int)*psVar1,4);
      this->terrains = ppfVar4;
      local_4 = 0;
      if (0 < *psVar1) {
        do {
          iVar3 = fscanf(iVar2,s__hd__hd,&param_1,&index);
          if (iVar3 != -1) {
            pfVar5 = (float *)calloc((int)this->terrain_size,4);
            sVar6 = 0;
            this->terrains[(short)param_1] = pfVar5;
            if (0 < index) {
              do {
                fscanf(iVar2,s__hd,&local_6);
                fscanf(iVar2,s__f,this->terrains[(short)param_1] + local_6);
                sVar6 = sVar6 + 1;
              } while (sVar6 < index);
            }
          }
          local_4 = local_4 + 1;
        } while ((short)local_4 < this->terrain_num);
      }
    }
    fclose(iVar2);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: data_load_color_tables
// Address: 00540fd0
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: id */
/* protected: virtual unsigned char __thiscall RGE_Game_World::data_load_color_tables(char *) */

uchar __thiscall RGE_Game_World::data_load_color_tables(RGE_Game_World *this,char *param_1)
{
  short *psVar1;
  _iobuf *p_Var2;
  int iVar3;
  RGE_Color_Table **ppRVar4;
  RGE_Color_Table *pRVar5;
  undefined4 *unaff_FS_OFFSET;
  short id;
  short index;
  int local_14;
  RGE_Color_Table *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561c4b;
  *unaff_FS_OFFSET = &local_c;
  p_Var2 = (_iobuf *)fopen(param_1,s_r);
  if (p_Var2 != (_iobuf *)0x0) {
    psVar1 = &this->color_table_num;
    iVar3 = fscanf(p_Var2,s__hd__hd,psVar1,&param_1);
    if (iVar3 == -1) {
      *psVar1 = 0;
      this->color_tables = (RGE_Color_Table **)0x0;
    }
    else {
      ppRVar4 = (RGE_Color_Table **)calloc((int)*psVar1,4);
      this->color_tables = ppRVar4;
      local_14 = 0;
      if (0 < (short)param_1) {
        do {
          iVar3 = fscanf(p_Var2,s__hd,&index);
          if (iVar3 != -1) {
            local_10 = (RGE_Color_Table *)operator_new(0x128);
            local_4 = 0;
            if (local_10 == (RGE_Color_Table *)0x0) {
              pRVar5 = (RGE_Color_Table *)0x0;
            }
            else {
              pRVar5 = (RGE_Color_Table *)
                       RGE_Color_Table::RGE_Color_Table(local_10,p_Var2,(short)_index);
            }
            local_4 = 0xffffffff;
            this->color_tables[index] = pRVar5;
          }
          local_14 = local_14 + 1;
        } while ((short)local_14 < (short)param_1);
      }
    }
    fclose(p_Var2);
  }
  *unaff_FS_OFFSET = local_c;
  return '\x01';
}

// --------------------------------------------------

// Function: data_load_sprites
// Address: 005410e0
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: id */
/* protected: virtual unsigned char __thiscall RGE_Game_World::data_load_sprites(char *) */

uchar __thiscall RGE_Game_World::data_load_sprites(RGE_Game_World *this,char *param_1)
{
  short *psVar1;
  short sVar2;
  _iobuf *p_Var3;
  int iVar4;
  RGE_Sprite **ppRVar5;
  RGE_Sprite *pRVar6;
  short sVar7;
  undefined4 *unaff_FS_OFFSET;
  short id;
  short local_14 [2];
  RGE_Sprite *local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561c76;
  *unaff_FS_OFFSET = &local_c;
  p_Var3 = (_iobuf *)fopen(param_1,s_r);
  if (p_Var3 != (_iobuf *)0x0) {
    psVar1 = &this->sprite_num;
    iVar4 = fscanf(p_Var3,s__hd__hd,psVar1,&param_1);
    if (iVar4 == -1) {
      *psVar1 = 0;
      this->sprites = (RGE_Sprite **)0x0;
    }
    else {
      ppRVar5 = (RGE_Sprite **)calloc((int)*psVar1,4);
      this->sprites = ppRVar5;
      sVar7 = 0;
      sVar2 = (short)param_1;
      if (0 < (short)param_1) {
        do {
          iVar4 = fscanf(p_Var3,s__hd,local_14);
          if (iVar4 != -1) {
                    /* language.dll match for 0x78: "10" */
            local_10 = (RGE_Sprite *)operator_new(0x78);
            local_4 = 0;
            if (local_10 == (RGE_Sprite *)0x0) {
              pRVar6 = (RGE_Sprite *)0x0;
            }
            else {
              pRVar6 = (RGE_Sprite *)
                       RGE_Sprite::RGE_Sprite(local_10,p_Var3,local_14[0],this->sounds);
            }
            local_4 = 0xffffffff;
            this->sprites[local_14[0]] = pRVar6;
          }
          sVar7 = sVar7 + 1;
          sVar2 = (short)param_1;
        } while (sVar7 < (short)param_1);
      }
      sVar7 = 0;
      if (0 < sVar2) {
        do {
          if (this->sprites[sVar7] == (RGE_Sprite *)0x0) {
                    /* language.dll match for 0x78: "10" */
            local_10 = (RGE_Sprite *)operator_new(0x78);
            local_4 = 1;
            if (local_10 == (RGE_Sprite *)0x0) {
              pRVar6 = (RGE_Sprite *)0x0;
            }
            else {
              pRVar6 = (RGE_Sprite *)RGE_Sprite::RGE_Sprite(local_10,sVar7);
            }
            local_4 = 0xffffffff;
            this->sprites[sVar7] = pRVar6;
            sVar2 = (short)param_1;
          }
          sVar7 = sVar7 + 1;
        } while (sVar7 < sVar2);
      }
    }
    fclose(p_Var3);
  }
  *unaff_FS_OFFSET = local_c;
  return '\x01';
}

// --------------------------------------------------

// Function: data_load_players_type
// Address: 00541240
/* protected: virtual void __thiscall RGE_Game_World::data_load_players_type(short,short,struct
   _iobuf *) */

void __thiscall
RGE_Game_World::data_load_players_type
          (RGE_Game_World *this,short param_1,short param_2,_iobuf *param_3)
{
  RGE_Master_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561c8b;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 == 0) {
    pRVar1 = (RGE_Master_Player *)operator_new(0x2c);
    local_4 = 0;
    if (pRVar1 == (RGE_Master_Player *)0x0) {
      pRVar1 = (RGE_Master_Player *)0x0;
    }
    else {
      pRVar1 = (RGE_Master_Player *)RGE_Master_Player::RGE_Master_Player(pRVar1,param_3);
    }
    this->master_players[param_1] = pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: data_load_players
// Address: 005412b0
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: type */
/* protected: virtual unsigned char __thiscall RGE_Game_World::data_load_players(char *) */

uchar __thiscall RGE_Game_World::data_load_players(RGE_Game_World *this,char *param_1)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  RGE_Master_Player **ppRVar4;
  short sVar5;
  short type;
  short id;
  undefined4 local_4;
  
  iVar2 = fopen(param_1,s_r);
  if (iVar2 != 0) {
    psVar1 = &this->master_player_num;
    iVar3 = fscanf(iVar2,s__hd__hd,psVar1,&param_1);
    if (iVar3 == -1) {
      *psVar1 = 0;
      this->master_players = (RGE_Master_Player **)0x0;
    }
    else {
      ppRVar4 = (RGE_Master_Player **)calloc((int)*psVar1,4);
      sVar5 = 0;
      this->master_players = ppRVar4;
      if (0 < (short)param_1) {
        do {
          iVar3 = fscanf(iVar2,s__hd__hd,&local_4,&id);
          if (iVar3 != -1) {
            (**(code **)(this->_padding_ + 0x1c))(local_4,_id,iVar2);
          }
          sVar5 = sVar5 + 1;
        } while (sVar5 < (short)param_1);
        fclose(iVar2);
        return '\x01';
      }
    }
    fclose(iVar2);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: data_load_objects
// Address: 00541380
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: player_count */
/* protected: virtual unsigned char __thiscall RGE_Game_World::data_load_objects(char *) */

uchar __thiscall RGE_Game_World::data_load_objects(RGE_Game_World *this,char *param_1)
{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  short player_count;
  short count;
  short local_e;
  short in_id;
  short type;
  undefined4 uStack_4;
  
  iVar1 = fopen(param_1,s_r);
  if (iVar1 != 0) {
    iVar2 = fscanf(iVar1,s__hd,&local_e);
    if ((iVar2 != -1) && (sVar4 = 0, 0 < local_e)) {
      do {
        iVar2 = fscanf(iVar1,s__hd,&param_1);
        if (iVar2 != -1) {
          fscanf(iVar1,s__hd,&in_id);
          (**(code **)(this->master_players[(short)param_1]->_padding_ + 0xc))(_in_id);
          fscanf(iVar1,s__hd,&in_id);
          sVar3 = 0;
          if (0 < in_id) {
            do {
              iVar2 = fscanf(iVar1,s__hd__hd,&uStack_4,&type);
              if (iVar2 != -1) {
                (**(code **)(this->master_players[(short)param_1]->_padding_ + 0x10))
                          (iVar1,uStack_4,this->sprites,this->sounds,_type);
              }
              sVar3 = sVar3 + 1;
            } while (sVar3 < in_id);
          }
        }
        sVar4 = sVar4 + 1;
      } while (sVar4 < local_e);
    }
    fclose(iVar1);
  }
  return '\x01';
}

// --------------------------------------------------

// Function: data_load_effects
// Address: 005414a0
/* protected: virtual void __thiscall RGE_Game_World::data_load_effects(char *) */

void __thiscall RGE_Game_World::data_load_effects(RGE_Game_World *this,char *param_1)
{
  RGE_Effects *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561cab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Effects *)operator_new(0xc);
  local_4 = 0;
  if (pRVar1 == (RGE_Effects *)0x0) {
    pRVar1 = (RGE_Effects *)0x0;
  }
  else {
    pRVar1 = (RGE_Effects *)RGE_Effects::RGE_Effects(pRVar1,param_1);
  }
  this->effects = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: data_load_map
// Address: 00541500
/* protected: virtual void __thiscall RGE_Game_World::data_load_map(char *,char *,char *,char
   *,short,short,short,class RGE_Sound * *,char *) */

void __thiscall
RGE_Game_World::data_load_map
          (RGE_Game_World *this,char *param_1,char *param_2,char *param_3,char *param_4,
          short param_5,short param_6,short param_7,RGE_Sound **param_8,char *param_9)
{
  RGE_Map *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561ccb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Map *)operator_new(0x8dd0);
  local_4 = 0;
  if (pRVar1 == (RGE_Map *)0x0) {
    pRVar1 = (RGE_Map *)0x0;
  }
  else {
    pRVar1 = (RGE_Map *)
             RGE_Map::RGE_Map(pRVar1,param_1,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  local_4 = 0xffffffff;
  this->map = pRVar1;
  RGE_Map::load_terrain_obj_types(pRVar1,param_9);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: data_load_random_map
// Address: 00541590
/* protected: virtual void __thiscall RGE_Game_World::data_load_random_map(char *,char *,char *,char
   *) */

void __thiscall
RGE_Game_World::data_load_random_map
          (RGE_Game_World *this,char *param_1,char *param_2,char *param_3,char *param_4)
{
  (**(code **)(this->map->_padding_ + 8))(param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: data_load_world
// Address: 005415b0
// [HELPER] s__s__s__s__s__s__s__s__s__s__s__s: "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %hd %hd %hd"
/* WARNING: Variable defined which should be unmapped: tile_height */
/* protected: virtual unsigned char __thiscall RGE_Game_World::data_load_world(struct _iobuf *) */

uchar __thiscall RGE_Game_World::data_load_world(RGE_Game_World *this,_iobuf *param_1)
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  short *psStack_198;
  short tile_height;
  short elev_height;
  short tile_width;
  char effects_file [23];
  char map_file [23];
  char color_file [23];
  char terrain_file [23];
  char sprite_file [23];
  char overlay_file [23];
  char obj_file [23];
  char border_file [23];
  char terr_obj_file [23];
  char rmm_obj_file [23];
  char player_file [23];
  char rmm_terr_file [23];
  char sound_file [23];
  char rmm_land_file [23];
  char terrain_table_file [23];
  char rmm_map_file [23];
  
  psStack_198 = &tile_width;
  fscanf(param_1,s__s__s__s__s__s__s__s__s__s__s__s,terrain_table_file + 4,color_file + 4,
         sound_file + 4,border_file + 4,overlay_file + 4,terrain_file + 4,map_file + 4,
         sprite_file + 4,player_file + 4,obj_file + 4,effects_file + 4,terr_obj_file + 4,
         rmm_map_file + 4,rmm_land_file + 4,rmm_terr_file + 4,rmm_obj_file + 4,effects_file,
         &elev_height);
  iVar1 = this->_padding_;
  psStack_198 = (short *)(terrain_table_file + 4);
  (**(code **)(iVar1 + 4))();
  (**(code **)(iVar1 + 0x14))(color_file);
  pcVar4 = rmm_terr_file + 0x14;
  (**(code **)(iVar1 + 0x10))(pcVar4);
  pcVar3 = terrain_file + 0x10;
  (**(code **)(iVar1 + 0x18))(pcVar3);
  pcVar2 = rmm_obj_file + 0xc;
  (**(code **)(iVar1 + 8))(pcVar2);
  (**(code **)(iVar1 + 0xc))(overlay_file + 8);
  (**(code **)(iVar1 + 0x20))(&psStack_198);
  (**(code **)(iVar1 + 0x24))
            (obj_file,sprite_file,color_file,effects_file,pcVar4,pcVar2,pcVar3,this->sounds,
             border_file);
  (**(code **)(iVar1 + 0x28))(sound_file + 0xc,player_file + 0xc,terr_obj_file + 0xc,obj_file + 0xc)
  ;
  return '\x01';
}

// --------------------------------------------------

// Function: data_load
// Address: 00541720
// [HELPER] s_r: "r"
/* public: virtual unsigned char __thiscall RGE_Game_World::data_load(char *,char *) */

uchar __thiscall RGE_Game_World::data_load(RGE_Game_World *this,char *param_1,char *param_2)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_retaddr;
  
  iVar2 = fopen(param_2,s_r);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)this->_padding_;
    (*(code *)*puVar1)(iVar2);
    fclose(iVar2);
    (*(code *)puVar1[0x37])(unaff_retaddr);
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: init_player_type
// Address: 00541770
/* protected: virtual unsigned char __thiscall RGE_Game_World::init_player_type(int,short,unsigned
   char) */

uchar __thiscall
RGE_Game_World::init_player_type(RGE_Game_World *this,int param_1,short param_2,uchar param_3)
{
  RGE_Master_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561ceb;
  *unaff_FS_OFFSET = &local_c;
  if (param_3 == '\0') {
    pRVar1 = (RGE_Master_Player *)operator_new(0x2c);
    local_4 = 0;
    if (pRVar1 == (RGE_Master_Player *)0x0) {
      pRVar1 = (RGE_Master_Player *)0x0;
    }
    else {
      pRVar1 = (RGE_Master_Player *)RGE_Master_Player::RGE_Master_Player(pRVar1,param_1);
    }
    local_4 = 0xffffffff;
    this->master_players[param_2] = pRVar1;
    (**(code **)(this->master_players[param_2]->_padding_ + 4))(param_1,this->sprites,this->sounds);
  }
  *unaff_FS_OFFSET = local_c;
  return '\x01';
}

// --------------------------------------------------

// Function: init_player
// Address: 00541800
/* protected: virtual unsigned char __thiscall RGE_Game_World::init_player(int) */

uchar __thiscall RGE_Game_World::init_player(RGE_Game_World *this,int param_1)
{
  short *psVar1;
  code *pcVar2;
  int iVar3;
  RGE_Master_Player **ppRVar4;
  int iVar5;
  
  iVar3 = param_1;
  psVar1 = &this->master_player_num;
  rge_read(param_1,psVar1,2);
  if (0 < *psVar1) {
    ppRVar4 = (RGE_Master_Player **)calloc((int)*psVar1,4);
    iVar5 = 0;
    this->master_players = ppRVar4;
    if (0 < *psVar1) {
      pcVar2 = *(code **)(this->_padding_ + 0x2c);
      do {
        rge_read(iVar3,&param_1,1);
        (*pcVar2)(iVar3,iVar5,param_1);
        iVar5 = iVar5 + 1;
      } while ((short)iVar5 < *psVar1);
    }
  }
  return '\x01';
}

// --------------------------------------------------

// Function: terrain_tables_init
// Address: 00541880
/* protected: virtual void __thiscall RGE_Game_World::terrain_tables_init(int) */

void __thiscall RGE_Game_World::terrain_tables_init(RGE_Game_World *this,int param_1)
{
  short *psVar1;
  short *psVar2;
  float **ppfVar3;
  float *pfVar4;
  int iVar5;
  
  psVar1 = &this->terrain_num;
  rge_read(param_1,psVar1,2);
  psVar2 = &this->terrain_size;
  rge_read(param_1,psVar2,2);
  if ((0 < *psVar1) && (0 < *psVar2)) {
    ppfVar3 = (float **)calloc((int)*psVar1,4);
    this->terrains = ppfVar3;
    rge_read(param_1,ppfVar3,(int)*psVar1 << 2);
    iVar5 = 0;
    if (0 < this->terrain_num) {
      do {
        if (this->terrains[iVar5] != (float *)0x0) {
          pfVar4 = (float *)calloc((int)*psVar2,4);
          this->terrains[iVar5] = pfVar4;
          rge_read(param_1,this->terrains[iVar5],(int)*psVar2 << 2);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < this->terrain_num);
    }
  }
  return;
}

// --------------------------------------------------

// Function: color_table_init
// Address: 00541930
/* protected: virtual void __thiscall RGE_Game_World::color_table_init(int) */

void __thiscall RGE_Game_World::color_table_init(RGE_Game_World *this,int param_1)
{
  short *psVar1;
  RGE_Color_Table **ppRVar2;
  RGE_Color_Table *pRVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561d0b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  psVar1 = &this->color_table_num;
  rge_read(param_1,psVar1,2);
  if (0 < *psVar1) {
    ppRVar2 = (RGE_Color_Table **)calloc((int)*psVar1,4);
    iVar4 = 0;
    this->color_tables = ppRVar2;
    if (0 < *psVar1) {
      do {
        pRVar3 = (RGE_Color_Table *)operator_new(0x128);
        local_4 = 0;
        if (pRVar3 == (RGE_Color_Table *)0x0) {
          pRVar3 = (RGE_Color_Table *)0x0;
        }
        else {
          pRVar3 = (RGE_Color_Table *)RGE_Color_Table::RGE_Color_Table(pRVar3,param_1);
        }
        iVar5 = iVar4 + 1;
        local_4 = 0xffffffff;
        this->color_tables[iVar4] = pRVar3;
        iVar4 = iVar5;
      } while (iVar5 < *psVar1);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: init_sounds
// Address: 005419e0
/* protected: virtual void __thiscall RGE_Game_World::init_sounds(int,class TSound_Driver *) */

void __thiscall RGE_Game_World::init_sounds(RGE_Game_World *this,int param_1,TSound_Driver *param_2)
{
  short *psVar1;
  RGE_Sound **ppRVar2;
  RGE_Sound *pRVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561d2b;
  *unaff_FS_OFFSET = &local_c;
  psVar1 = &this->sound_num;
  rge_read(param_1,psVar1,2);
  ppRVar2 = (RGE_Sound **)calloc((int)*psVar1,4);
  this->sounds = ppRVar2;
  iVar4 = 0;
  if (0 < *psVar1) {
    do {
      pRVar3 = (RGE_Sound *)operator_new(0x10);
      local_4 = 0;
      if (pRVar3 == (RGE_Sound *)0x0) {
        pRVar3 = (RGE_Sound *)0x0;
      }
      else {
        pRVar3 = (RGE_Sound *)RGE_Sound::RGE_Sound(pRVar3,param_1,this->sound_driver);
      }
      iVar5 = iVar4 + 1;
      local_4 = 0xffffffff;
      this->sounds[iVar4] = pRVar3;
      iVar4 = iVar5;
    } while (iVar5 < *psVar1);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: init_sprites
// Address: 00541a80
/* protected: virtual void __thiscall RGE_Game_World::init_sprites(int) */

void __thiscall RGE_Game_World::init_sprites(RGE_Game_World *this,int param_1)
{
  short *psVar1;
  RGE_Sprite **ppRVar2;
  RGE_Sprite *pRVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561d4b;
  *unaff_FS_OFFSET = &local_c;
  psVar1 = &this->sprite_num;
  rge_read(param_1,psVar1,2);
  ppRVar2 = (RGE_Sprite **)calloc((int)*psVar1,4);
  this->sprites = ppRVar2;
  rge_read(param_1,ppRVar2,(int)*psVar1 << 2);
  iVar4 = 0;
  if (0 < *psVar1) {
    do {
      if (this->sprites[iVar4] != (RGE_Sprite *)0x0) {
                    /* language.dll match for 0x78: "10" */
        pRVar3 = (RGE_Sprite *)operator_new(0x78);
        local_4 = 0;
        if (pRVar3 == (RGE_Sprite *)0x0) {
          pRVar3 = (RGE_Sprite *)0x0;
        }
        else {
          pRVar3 = (RGE_Sprite *)
                   RGE_Sprite::RGE_Sprite(pRVar3,param_1,this->sounds,this->color_tables);
        }
        local_4 = 0xffffffff;
        this->sprites[iVar4] = pRVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *psVar1);
  }
  iVar4 = 0;
  if (0 < *psVar1) {
    do {
      pRVar3 = this->sprites[iVar4];
      if (pRVar3 != (RGE_Sprite *)0x0) {
        RGE_Sprite::rehook(pRVar3,this->sprites);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *psVar1);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: scenario_init
// Address: 00541b60
/* public: virtual void __thiscall RGE_Game_World::scenario_init(int,class RGE_Game_World *) */

void __thiscall
RGE_Game_World::scenario_init(RGE_Game_World *this,int param_1,RGE_Game_World *param_2)
{
  RGE_Scenario *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561d6b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Scenario *)operator_new(0x1990);
  local_4 = 0;
  if (pRVar1 == (RGE_Scenario *)0x0) {
    pRVar1 = (RGE_Scenario *)0x0;
  }
  else {
    pRVar1 = (RGE_Scenario *)RGE_Scenario::RGE_Scenario(pRVar1,param_1,param_2);
  }
  this->scenario = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: scenario_init
// Address: 00541bc0
/* public: virtual void __thiscall RGE_Game_World::scenario_init(class RGE_Game_World *) */

void __thiscall RGE_Game_World::scenario_init(RGE_Game_World *this,RGE_Game_World *param_1)
{
  RGE_Scenario *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561d8b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Scenario *)operator_new(0x1990);
  local_4 = 0;
  if (pRVar1 == (RGE_Scenario *)0x0) {
    pRVar1 = (RGE_Scenario *)0x0;
  }
  else {
    pRVar1 = (RGE_Scenario *)RGE_Scenario::RGE_Scenario(pRVar1,param_1);
  }
  this->scenario = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: map_init
// Address: 00541c20
/* protected: virtual void __thiscall RGE_Game_World::map_init(int,class TSound_Driver *) */

void __thiscall RGE_Game_World::map_init(RGE_Game_World *this,int param_1,TSound_Driver *param_2)
{
  RGE_Map *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561dab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Map *)operator_new(0x8dd0);
  local_4 = 0;
  if (pRVar1 == (RGE_Map *)0x0) {
    pRVar1 = (RGE_Map *)0x0;
  }
  else {
    pRVar1 = (RGE_Map *)RGE_Map::RGE_Map(pRVar1,param_1,this->sounds,'\x01');
  }
  this->map = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: effects_init
// Address: 00541c90
/* protected: virtual void __thiscall RGE_Game_World::effects_init(int) */

void __thiscall RGE_Game_World::effects_init(RGE_Game_World *this,int param_1)
{
  RGE_Effects *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561dcb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Effects *)operator_new(0xc);
  local_4 = 0;
  if (pRVar1 == (RGE_Effects *)0x0) {
    pRVar1 = (RGE_Effects *)0x0;
  }
  else {
    pRVar1 = (RGE_Effects *)RGE_Effects::RGE_Effects(pRVar1,param_1);
  }
  this->effects = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: master_player_init
// Address: 00541cf0
/* protected: virtual void __thiscall RGE_Game_World::master_player_init(int) */

void __thiscall RGE_Game_World::master_player_init(RGE_Game_World *this,int param_1)
{
  (**(code **)(this->_padding_ + 0x30))(param_1);
  return;
}

// --------------------------------------------------

// Function: command_init
// Address: 00541d00
/* protected: virtual void __thiscall RGE_Game_World::command_init(int,class TCommunications_Handler
   *) */

void __thiscall
RGE_Game_World::command_init(RGE_Game_World *this,int param_1,TCommunications_Handler *param_2)
{
  RGE_Command *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561deb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Command *)operator_new(0x18);
  local_4 = 0;
  if (pRVar1 == (RGE_Command *)0x0) {
    pRVar1 = (RGE_Command *)0x0;
  }
  else {
    pRVar1 = (RGE_Command *)RGE_Command::RGE_Command(pRVar1,this,param_2);
  }
  this->commands = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: world_init
// Address: 00541d60
/* protected: virtual void __thiscall RGE_Game_World::world_init(int,class TSound_Driver *,class
   TCommunications_Handler *) */

void __thiscall
RGE_Game_World::world_init
          (RGE_Game_World *this,int param_1,TSound_Driver *param_2,TCommunications_Handler *param_3)
{
  int iVar1;
  undefined4 unaff_retaddr;
  int iVar2;
  
  iVar1 = this->_padding_;
  (**(code **)(iVar1 + 0x3c))(param_1);
  iVar2 = param_1;
  (**(code **)(iVar1 + 0x38))(param_1);
  (**(code **)(iVar1 + 0x40))(param_1,unaff_retaddr);
  (**(code **)(iVar1 + 0x44))(param_1);
  (**(code **)(iVar1 + 0x48))(param_1,unaff_retaddr);
  (**(code **)(iVar1 + 0x4c))(param_1);
  (**(code **)(iVar1 + 0x50))(param_1);
  (**(code **)(iVar1 + 0x54))(param_1,iVar2);
  return;
}

// --------------------------------------------------

// Function: init
// Address: 00541db0
// [HELPER] s_VER_3_7: "VER 3.7"
/* WARNING: Variable defined which should be unmapped: version */
/* public: virtual unsigned char __thiscall RGE_Game_World::init(char *,class TSound_Driver *,class
   TCommunications_Handler *) */

uchar __thiscall
RGE_Game_World::init
          (RGE_Game_World *this,char *param_1,TSound_Driver *param_2,
          TCommunications_Handler *param_3)
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  char version [8];
  
  this->sound_driver = param_2;
  this->next_object_id = 0;
  iVar2 = rge_open(param_1,0x8000);
  if (iVar2 == -1) {
    return '\0';
  }
  rge_read(iVar2,version + 4,8);
  pbVar5 = &s_VER_3_7;
  pbVar3 = (byte *)(version + 4);
  do {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_00541e20:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_00541e25;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_00541e20;
    pbVar3 = pbVar3 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_00541e25:
  if (iVar4 != 0) {
    rge_close(iVar2);
    return '\0';
  }
  (**(code **)(this->_padding_ + 0x58))(iVar2,param_2,param_3);
  rge_close(iVar2);
  return '\x01';
}

// --------------------------------------------------

// Function: turn_sound_off
// Address: 00541e70
/* public: virtual void __thiscall RGE_Game_World::turn_sound_off(void) */

void __thiscall RGE_Game_World::turn_sound_off(RGE_Game_World *this)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < this->sound_num) {
    do {
      RGE_Sound::stop(this->sounds[iVar1]);
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->sound_num);
  }
  return;
}

// --------------------------------------------------

// Function: reset_communications
// Address: 00541ea0
/* public: void __thiscall RGE_Game_World::reset_communications(class TCommunications_Handler *) */

void __thiscall
RGE_Game_World::reset_communications(RGE_Game_World *this,TCommunications_Handler *param_1)
{
  RGE_Command::reset_communications(this->commands,param_1);
  return;
}

// --------------------------------------------------

// Function: reset_player_visible_maps
// Address: 00541eb0
/* public: void __thiscall RGE_Game_World::reset_player_visible_maps(void) */

void __thiscall RGE_Game_World::reset_player_visible_maps(RGE_Game_World *this)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < this->player_num) {
    do {
      if (this->players[iVar1] != (RGE_Player *)0x0) {
        RGE_Player::remake_visible_map(this->players[iVar1]);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: del_game_info
// Address: 00541ee0
/* public: virtual void __thiscall RGE_Game_World::del_game_info(void) */

void __thiscall RGE_Game_World::del_game_info(RGE_Game_World *this)
{
  int iVar1;
  int iVar2;
  ulong *puVar3;
  
  world_update_counter = 0;
  this->game_state = '\x02';
  this->game_end_condition = '\0';
  RGE_Object_List::removeAllObjects(this->reusable_static_objects);
  RGE_Object_List::removeAllObjects(this->reusable_animated_objects);
  RGE_Object_List::removeAllObjects(this->reusable_moving_objects);
  RGE_Object_List::removeAllObjects(this->reusable_action_objects);
  RGE_Object_List::removeAllObjects(this->reusable_combat_objects);
  RGE_Object_List::removeAllObjects(this->reusable_missile_objects);
  RGE_Object_List::removeAllObjects(this->reusable_doppleganger_objects);
  this->next_reusable_object_id = -1;
  this->campaign = -1;
  this->campaign_player = -1;
  this->campaign_scenario = -1;
  this->difficultyLevelValue = -1;
  this->next_object_id = 0;
  iVar2 = 0;
  if (0 < this->maxNumberObjectsValue) {
    do {
      iVar1 = iVar2 + 1;
      this->objectsValue[iVar2] = (RGE_Static_Object *)0x0;
      iVar2 = iVar1;
    } while (iVar1 < this->maxNumberObjectsValue);
  }
  iVar2 = 0;
  if (0 < this->maxNumberNegativeObjectsValue) {
    do {
      iVar1 = iVar2 + 1;
      this->negativeObjectsValue[iVar2] = (RGE_Static_Object *)0x0;
      iVar2 = iVar1;
    } while (iVar1 < this->maxNumberNegativeObjectsValue);
  }
  (**(code **)(this->_padding_ + 0xb4))();
  if (this->scenario != (RGE_Scenario *)0x0) {
    (**(code **)(this->scenario->_padding_ + 4))(1);
    this->scenario = (RGE_Scenario *)0x0;
  }
  if (((0 < this->player_num) && (this->players != (RGE_Player **)0x0)) &&
     (iVar2 = 0, 0 < this->player_num)) {
    do {
      if (this->players[iVar2] != (RGE_Player *)0x0) {
        RGE_Player::destroy_objects(this->players[iVar2]);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < this->player_num);
  }
  if ((0 < this->player_num) && (this->players != (RGE_Player **)0x0)) {
    iVar2 = 0;
    if (0 < this->player_num) {
      do {
        if (this->players[iVar2] != (RGE_Player *)0x0) {
          (**(code **)this->players[iVar2]->_padding_)(1);
          this->players[iVar2] = (RGE_Player *)0x0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->player_num);
    }
    this->player_num = 0;
    free(this->players);
    this->players = (RGE_Player **)0x0;
  }
  this->next_object_id = 0;
  this->sound_update_index = 0;
  this->sprite_update_index = 0;
  this->player_turn = 0;
  puVar3 = this->player_time_delta;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: load_player
// Address: 00542060
/* protected: virtual void __thiscall RGE_Game_World::load_player(int,unsigned char,short) */

void __thiscall
RGE_Game_World::load_player(RGE_Game_World *this,int param_1,uchar param_2,short param_3)
{
  RGE_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561e0b;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 == '\0') {
    pRVar1 = (RGE_Player *)operator_new(0x220);
    local_4 = 0;
    if (pRVar1 == (RGE_Player *)0x0) {
      pRVar1 = (RGE_Player *)0x0;
    }
    else {
      pRVar1 = (RGE_Player *)RGE_Player::RGE_Player(pRVar1,param_1,this,(uchar)param_3);
    }
    local_4 = 0xffffffff;
    this->players[param_3] = pRVar1;
    (**(code **)(this->players[param_3]->_padding_ + 0x74))(param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load_world
// Address: 005420f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Game_World::load_world(int) */

uchar __thiscall RGE_Game_World::load_world(RGE_Game_World *this,int param_1)
{
  short *psVar1;
  code *pcVar2;
  RGE_Player **ppRVar3;
  int iVar4;
  ulong *puVar5;
  int iVar6;
  float fVar7;
  uchar type;
  undefined4 local_4;
  
  iVar4 = param_1;
  this->game_state = '\x02';
  this->game_end_condition = '\0';
  rge_read(param_1,&this->world_time,4);
  rge_read(iVar4,&this->old_world_time,4);
  rge_read(iVar4,&this->world_time_delta,4);
  rge_read(iVar4,&this->world_time_delta_seconds,4);
  rge_read(iVar4,&this->timer,4);
  rge_read(iVar4,&this->game_speed,4);
  rge_read(iVar4,&this->temp_pause,1);
  rge_read(iVar4,&this->next_object_id,4);
  rge_read(iVar4,&this->next_reusable_object_id,4);
  rge_read(iVar4,&this->random_seed,4);
  rge_read(iVar4,&this->curr_player,2);
  psVar1 = &this->player_num;
  rge_read(iVar4,psVar1,2);
  rge_read(iVar4,&param_1,1);
  rge_read(iVar4,&this->campaign,4);
  rge_read(iVar4,&this->campaign_player,4);
  rge_read(iVar4,&this->campaign_scenario,4);
  rge_read(iVar4,&this->player_turn,4);
  puVar5 = this->player_time_delta;
  _type = 9;
  do {
    rge_read(iVar4,puVar5,4);
    puVar5 = puVar5 + 1;
    _type = _type + -1;
  } while (_type != 0);
  iVar6 = 0;
  this->old_time = 0;
  RGE_Map::load_map(this->map,iVar4);
  initializePathingSystem(this);
  this->currentUpdateComputerPlayer = -1;
  if (0 < *psVar1) {
    ppRVar3 = (RGE_Player **)calloc(4,(int)*psVar1);
    this->players = ppRVar3;
    if (0 < *psVar1) {
      pcVar2 = *(code **)(this->_padding_ + 0x34);
      do {
        rge_read(iVar4,&local_4,1);
        (*pcVar2)(iVar4,local_4,iVar6);
        iVar6 = iVar6 + 1;
      } while (iVar6 < *psVar1);
    }
  }
  update_mutual_allies(this);
  RGE_Unified_Visible_Map::suppress_updates(this->map->unified_vis_map,1);
  iVar6 = 0;
  if (0 < *psVar1) {
    do {
      RGE_Player::load_info(this->players[iVar6],iVar4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *psVar1);
  }
  RGE_Unified_Visible_Map::suppress_updates(this->map->unified_vis_map,0);
  (**(code **)(this->_padding_ + 0xf4))(iVar4,this);
  if (save_game_version < _DAT_00577a10) {
    this->difficultyLevelValue = -1;
  }
  else {
    rge_read(iVar4,&this->difficultyLevelValue,4);
  }
  iVar4 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar4 != 0) {
    fVar7 = RGE_Base_Game::get_game_speed(rge_base_game);
    this->game_speed = fVar7;
  }
  this->game_state = (uchar)local_4;
  return '\x01';
}

// --------------------------------------------------

// Function: load_game
// Address: 00542360
// [HELPER] s_VER_8_6: "VER 8.6"
// [HELPER] s__s_s: "%s%s"
/* WARNING: Variable defined which should be unmapped: version */
/* public: virtual unsigned char __thiscall RGE_Game_World::load_game(char *) */

uchar __thiscall RGE_Game_World::load_game(RGE_Game_World *this,char *param_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  char version [8];
  char tempname [300];
  
  world_update_counter = 0;
  iVar2 = this->_padding_;
  (**(code **)(iVar2 + 0xb8))();
  sprintf(tempname + 4,s__s_s,rge_base_game->prog_info->save_dir,param_1);
  iVar3 = rge_open(tempname + 4,0x8000);
  if (iVar3 == -1) {
    return '\0';
  }
  rge_read(iVar3,version + 4,8);
  rge_read(iVar3,&save_game_version,4);
  pbVar6 = &s_VER_8_6;
  pbVar4 = (byte *)(version + 4);
  do {
    bVar1 = *pbVar4;
    bVar7 = bVar1 < *pbVar6;
    if (bVar1 != *pbVar6) {
LAB_00542413:
      iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_00542418;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar4[1];
    bVar7 = bVar1 < pbVar6[1];
    if (bVar1 != pbVar6[1]) goto LAB_00542413;
    pbVar4 = pbVar4 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar1 != 0);
  iVar5 = 0;
LAB_00542418:
  if (iVar5 != 0) {
    rge_close(iVar3);
    return '\0';
  }
  (**(code **)(iVar2 + 200))();
  rge_close(iVar3);
  return '\x01';
}

// --------------------------------------------------

// Function: set_game_speed
// Address: 00542470
/* public: void __thiscall RGE_Game_World::set_game_speed(float) */

void __thiscall RGE_Game_World::set_game_speed(RGE_Game_World *this,float param_1)
{
  this->game_speed = param_1;
  return;
}

// --------------------------------------------------

// Function: setup_gaia
// Address: 00542480
// [HELPER] s_GAIA: "GAIA"
/* protected: virtual void __thiscall RGE_Game_World::setup_gaia(void) */

void __thiscall RGE_Game_World::setup_gaia(RGE_Game_World *this)
{
  RGE_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561e2b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pRVar1 = (RGE_Player *)operator_new(0x220);
  local_4 = 0;
  if (pRVar1 == (RGE_Player *)0x0) {
    pRVar1 = (RGE_Player *)0x0;
  }
  else {
    pRVar1 = (RGE_Player *)
             RGE_Player::RGE_Player(pRVar1,this,*this->master_players,'\0',s_GAIA,'\0','\x01');
  }
  *this->players = pRVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setup_players
// Address: 005424f0
/* WARNING: Variable defined which should be unmapped: index */
/* protected: virtual void __thiscall RGE_Game_World::setup_players(struct RGE_Player_Info &) */

void __thiscall RGE_Game_World::setup_players(RGE_Game_World *this,RGE_Player_Info *param_1)
{
  RGE_Player *pRVar1;
  short sVar2;
  undefined4 *unaff_FS_OFFSET;
  short index;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00561e4b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  sVar2 = 1;
  if (1 < this->player_num) {
    do {
      local_4 = 0xffffffff;
      if (param_1->type[sVar2 + -1] != -1) {
        pRVar1 = (RGE_Player *)operator_new(0x220);
        local_4 = 0;
        if (pRVar1 == (RGE_Player *)0x0) {
          pRVar1 = (RGE_Player *)0x0;
        }
        else {
          pRVar1 = (RGE_Player *)
                   RGE_Player::RGE_Player
                             (pRVar1,this,this->master_players[param_1->type[sVar2 + 8]],
                              (uchar)sVar2,param_1->name[sVar2 + -1],param_1->type[sVar2 + 8],'\x01'
                             );
        }
        this->players[sVar2] = pRVar1;
      }
      sVar2 = sVar2 + 1;
    } while (sVar2 < this->player_num);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setup_player_colors
// Address: 005425b0
/* WARNING: Variable defined which should be unmapped: colors_used */
/* public: virtual void __thiscall RGE_Game_World::setup_player_colors(struct RGE_Player_Info &) */

void __thiscall RGE_Game_World::setup_player_colors(RGE_Game_World *this,RGE_Player_Info *param_1)
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  uchar *colors_used;
  uchar *players_done;
  long info_player_num;
  int local_4;
  
  iVar4 = -1;
  RGE_Player::set_color_table(*this->players,'\a');
  iVar2 = this->player_num + 1;
  local_4 = (int)param_1->player_num;
  if (iVar2 < param_1->player_num) {
    local_4 = iVar2;
  }
  iVar6 = 1;
  iVar2 = calloc((int)this->color_table_num,1);
  iVar3 = calloc((int)this->player_num,1);
  if (1 < this->player_num) {
    psVar5 = param_1->color;
    do {
      if (((iVar6 + -1 < local_4) && (-1 < *psVar5)) && (*(char *)(iVar2 + *psVar5) == '\0')) {
        RGE_Player::set_color_table(this->players[iVar6],(uchar)*psVar5);
        *(undefined1 *)(iVar2 + *psVar5) = 1;
        *(undefined1 *)(iVar3 + iVar6) = 1;
      }
      iVar6 = iVar6 + 1;
      psVar5 = psVar5 + 1;
    } while (iVar6 < this->player_num);
  }
  iVar6 = 1;
  if (1 < this->player_num) {
    do {
      if (*(char *)(iVar3 + iVar6) == '\0') {
        do {
          do {
            pcVar1 = (char *)(iVar2 + 1 + iVar4);
            iVar4 = iVar4 + 1;
          } while (*pcVar1 == '\x01');
        } while (this->color_tables[iVar4]->type != '\x01');
        RGE_Player::set_color_table(this->players[iVar6],(uchar)iVar4);
        *(undefined1 *)(iVar2 + iVar4) = 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < this->player_num);
  }
  free(iVar2);
  free(iVar3);
  return;
}

// --------------------------------------------------

// Function: setup_player_colors
// Address: 005426e0
/* public: virtual void __thiscall RGE_Game_World::setup_player_colors(void) */

void __thiscall RGE_Game_World::setup_player_colors(RGE_Game_World *this)
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -1;
  RGE_Player::set_color_table(*this->players,'\a');
  iVar2 = calloc((int)this->color_table_num,1);
  iVar3 = 1;
  if (1 < this->player_num) {
    do {
      do {
        do {
          pcVar1 = (char *)(iVar2 + 1 + iVar4);
          iVar4 = iVar4 + 1;
        } while (*pcVar1 == '\x01');
      } while (this->color_tables[iVar4]->type != '\x01');
      RGE_Player::set_color_table(this->players[iVar3],(uchar)iVar4);
      *(undefined1 *)(iVar2 + iVar4) = 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->player_num);
  }
  free(iVar2);
  return;
}

// --------------------------------------------------

// Function: new_game
// Address: 00542750
// [HELPER] s_C__msdev_work_age1_x1_World_cpp: "C:\msdev\work\age1_x1\World.cpp"
// [HELPER] s_World__new_game__rand__d_: "World: new_game (rand=%d)"
// [HELPER] s___World__after_gaia__rand__d_: "  World: after_gaia (rand=%d)"
// [HELPER] s___World__after_new_map__rand__d_: "  World: after_new_map (rand=%d)"
// [HELPER] s___World__after_players__rand__d_: "  World: after_players (rand=%d)"
// [HELPER] s___World__end_of_new_game__rand__: "  World: end_of_new_game (rand=%d)"
/* WARNING: Variable defined which should be unmapped: retval */
/* public: virtual unsigned char __thiscall RGE_Game_World::new_game(struct RGE_Player_Info &,int)
    */

uchar __thiscall RGE_Game_World::new_game(RGE_Game_World *this,RGE_Player_Info *param_1,int param_2)
{
  bool bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  RGE_Player **ppRVar6;
  int iVar7;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  TDebuggingLog *this_03;
  uint uVar8;
  int **ppiVar9;
  float fVar10;
  RGE_Player_Info *unaff_retaddr;
  uchar uVar11;
  undefined1 auStack_10c [3];
  uchar retval;
  int team;
  char randomString [256];
  
  world_update_counter = 0;
  PathingSystem::zeroObstructionMap(&pathSystem);
  PathingSystem::zeroObstructionMap(&aiPathSystem);
  this->currentUpdateComputerPlayer = -1;
  ppiVar9 = &computerPlayerSetup;
  for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppiVar9 = (int *)0x0;
    ppiVar9 = ppiVar9 + 1;
  }
  iVar7 = this->_padding_;
  (**(code **)(iVar7 + 0xb8))();
  debug_random_reset();
  debug_timeGetTime_cnt = 0;
  debug_timeGetTime_time = 0;
  this->game_state = '\x03';
  this->curr_player = (short)param_2;
  iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar4 == 0) {
    uVar5 = rge_base_game->random_game_seed;
    if (uVar5 == 0xffffffff) {
      uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x509);
    }
  }
  else {
    uVar5 = TCommunications_Handler::GetRandomSeed(this->commands->com_hand);
  }
  this->random_seed = uVar5;
  debug_srand(s_C__msdev_work_age1_x1_World_cpp,0x50c,uVar5);
  rge_base_game->save_random_game_seed = this->random_seed;
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x50f);
  this->random_seed = uVar5;
  TDebuggingLog::Log(this_00,(char *)L,s_World__new_game__rand__d_,uVar5);
  this->player_num = param_1->player_num + 1;
  RGE_Map::new_map(this->map,(int)param_1->map_width,(int)param_1->map_height);
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x516);
  this->random_seed = uVar5;
  TDebuggingLog::Log(this_01,(char *)L,s___World__after_new_map__rand__d_,uVar5);
  sVar3 = param_1->player_num + 1;
  this->player_num = sVar3;
  ppRVar6 = (RGE_Player **)calloc(4,(int)sVar3);
  this->players = ppRVar6;
  (**(code **)(iVar7 + 0x5c))();
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x520);
  this->random_seed = uVar5;
  TDebuggingLog::Log(this_02,(char *)L,s___World__after_gaia__rand__d_,uVar5);
  (**(code **)(iVar7 + 0x60))(param_1);
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x526);
  this->random_seed = uVar5;
  TDebuggingLog::Log(this_03,(char *)L,s___World__after_players__rand__d_,uVar5);
  uVar5 = 1;
  do {
    iVar7 = TCommunications_Handler::GetPlayerHumanity(this->commands->com_hand,uVar5);
    if (((iVar7 == 2) || (iVar7 == 4)) &&
       (team = RGE_Base_Game::playerTeam(rge_base_game,uVar5 - 1), 1 < team)) {
      uVar8 = 1;
      do {
        iVar7 = team;
        iVar4 = TCommunications_Handler::GetPlayerHumanity(this->commands->com_hand,uVar8);
        if (((iVar4 == 2) || (iVar4 == 4)) &&
           (iVar4 = RGE_Base_Game::playerTeam(rge_base_game,uVar8 - 1), iVar4 == iVar7)) {
          iVar7 = RGE_Base_Game::playerID(rge_base_game,uVar5);
          iVar4 = RGE_Base_Game::playerID(rge_base_game,uVar8);
          if (iVar7 != iVar4) {
            RGE_Player::set_relation(this->players[iVar7],iVar4,'\0');
            RGE_Player::set_allied_victory(this->players[iVar7],'\x01');
          }
        }
        uVar8 = uVar8 + 1;
        param_1 = unaff_retaddr;
      } while ((int)uVar8 < 9);
    }
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 9);
  iVar7 = RGE_Base_Game::randomGame(rge_base_game);
  if ((iVar7 != 0) && (iVar7 = RGE_Base_Game::campaignGame(rge_base_game), iVar7 == 0)) {
    uVar5 = 1;
    do {
      iVar7 = TCommunications_Handler::GetPlayerHumanity(this->commands->com_hand,uVar5);
      if ((((iVar7 == 4) || (all_cp == 1)) || ((all_cp == 2 && (1 < (int)uVar5)))) &&
         (iVar7 = RGE_Base_Game::playerTeam(rge_base_game,uVar5 - 1), iVar7 == 1)) {
        uVar8 = 1;
        do {
          iVar7 = TCommunications_Handler::GetPlayerHumanity(this->commands->com_hand,uVar8);
          if ((iVar7 == 4) || (iVar7 == 2)) {
            iVar7 = RGE_Base_Game::playerID(rge_base_game,uVar5);
            iVar4 = RGE_Base_Game::playerID(rge_base_game,uVar8);
            if (iVar7 != iVar4) {
              RGE_Player::set_relation(this->players[iVar7],iVar4,'\x01');
              RGE_Player::set_allied_victory(this->players[iVar7],'\x01');
            }
          }
          uVar8 = uVar8 + 1;
        } while ((int)uVar8 < 9);
      }
      uVar5 = uVar5 + 1;
      param_1 = unaff_retaddr;
    } while ((int)uVar5 < 9);
  }
  iVar4 = 0;
  this->world_time = 0;
  this->old_world_time = 0;
  this->world_time_delta = 0;
  this->old_time = 0;
  iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar7 == 0) {
    this->game_speed = 1.0;
  }
  else {
    fVar10 = RGE_Base_Game::get_game_speed(rge_base_game);
    this->game_speed = fVar10;
  }
  this->temp_pause = '\0';
  this->world_time_delta_seconds = 0.0;
  bVar1 = false;
  if (param_1->scenario == (char *)0x0) {
    if (param_1->campaign == '\0') {
      cVar2 = (**(code **)(this->_padding_ + 100))();
      bVar1 = true;
    }
    else {
      cVar2 = (**(code **)(this->_padding_ + 0x74))();
    }
  }
  else {
    cVar2 = (**(code **)(this->_padding_ + 0x78))(param_1->scenario);
  }
  initializePathingSystem(this);
  if (0 < this->player_num) {
    do {
      if (this->players[iVar4] != (RGE_Player *)0x0) {
        (**(code **)(this->players[iVar4]->_padding_ + 0x90))();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->player_num);
  }
  if (cVar2 != '\0') {
    this->game_state = '\0';
  }
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x5b2);
  this->random_seed = uVar5;
  TDebuggingLog::Log(L,(char *)L,s___World__end_of_new_game__rand__,uVar5);
                    /* language.dll match for 0x277b: "Random" */
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x277b,auStack_10c,0x100);
  uVar11 = (uchar)((uint)param_1 >> 0x18);
  iVar7 = 1;
  if ((bVar1) && (1 < this->player_num)) {
    do {
      if (this->players[iVar7] != (RGE_Player *)0x0) {
        (**(code **)(this->players[iVar7]->_padding_ + 0x2c))
                  (&stack0xfffffee8,&stack0xfffffee8,&stack0xfffffee8,0,
                   (int)*(short *)(randomString._240_4_ + 0x2a0));
      }
      uVar11 = (uchar)((uint)param_1 >> 0x18);
      iVar7 = iVar7 + 1;
    } while (iVar7 < this->player_num);
  }
  return uVar11;
}

// --------------------------------------------------

// Function: new_scenario
// Address: 00542bf0
// [HELPER] s_C__msdev_work_age1_x1_World_cpp: "C:\msdev\work\age1_x1\World.cpp"
/* public: virtual unsigned char __thiscall RGE_Game_World::new_scenario(struct RGE_Player_Info
   &,int) */

uchar __thiscall
RGE_Game_World::new_scenario(RGE_Game_World *this,RGE_Player_Info *param_1,int param_2)
{
  uchar uVar1;
  short sVar2;
  RGE_Player **ppRVar3;
  int iVar4;
  
  iVar4 = this->_padding_;
  world_update_counter = 0;
  (**(code **)(iVar4 + 0xb8))();
  this->curr_player = 0;
  if (param_2 == 0) {
    param_2 = TCommunications_Handler::GetRandomSeed(this->commands->com_hand);
  }
  this->random_seed = param_2;
  debug_srand(s_C__msdev_work_age1_x1_World_cpp,0x5d5,param_2);
  RGE_Map::new_map(this->map,(int)param_1->map_width,(int)param_1->map_height);
  RGE_Map::clear_map(this->map,(uchar)param_1->map_info->base_terrain,'\x01');
  sVar2 = param_1->player_num + 1;
  this->player_num = sVar2;
  ppRVar3 = (RGE_Player **)calloc(4,(int)sVar2);
  this->players = ppRVar3;
  (**(code **)(iVar4 + 0x5c))();
  (**(code **)(iVar4 + 0x60))(param_1);
  this->world_time = 0;
  this->old_world_time = 0;
  this->world_time_delta = 0;
  this->old_time = 0;
  this->game_speed = 1.0;
  this->temp_pause = '\0';
  this->world_time_delta_seconds = 0.0;
  if (param_1->scenario == (char *)0x0) {
    (**(code **)(iVar4 + 0xa8))(param_1);
    (**(code **)(iVar4 + 0xf0))(this);
    uVar1 = '\x01';
  }
  else {
    uVar1 = (**(code **)(iVar4 + 0x78))(param_1->scenario);
  }
  if ((uVar1 != '\0') && (iVar4 = 0, 0 < this->player_num)) {
    do {
      RGE_Player::set_map_visible(this->players[iVar4]);
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->player_num);
  }
  return uVar1;
}

// --------------------------------------------------

// Function: new_random_game
// Address: 00542d10
// [HELPER] s_C__msdev_work_age1_x1_World_cpp: "C:\msdev\work\age1_x1\World.cpp"
// [HELPER] s___World__after_map_gen__rand__d_: "  World: after_map_gen (rand=%d)"
// [HELPER] s___World__after_player_random_sta: "  World: after_player_random_start (rand=%d)"
// [HELPER] s___World__after_player_update__ra: "  World: after_player_update (rand=%d)"
// [HELPER] s___World__before_map_gen__rand__d: "  World: before_map_gen (rand=%d)"
/* protected: virtual unsigned char __thiscall RGE_Game_World::new_random_game(struct
   RGE_Player_Info &) */

uchar __thiscall RGE_Game_World::new_random_game(RGE_Game_World *this,RGE_Player_Info *param_1)
{
  short sVar1;
  uint uVar2;
  int iVar3;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  short sVar4;
  
  world_update_counter = 0;
  iVar3 = this->_padding_;
  (**(code **)(iVar3 + 0xa8))(param_1);
  (**(code **)(iVar3 + 0xf0))(this);
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x612);
  this->random_seed = uVar2;
  TDebuggingLog::Log(this_00,(char *)L,s___World__before_map_gen__rand__d,uVar2);
  iVar3 = this->player_num + -1;
  (**(code **)(this->map->_padding_ + 0x28))
            (this,0xffffffff,0xffffffff,CONCAT31((int3)((uint)iVar3 >> 8),(char)param_1->map_type),
             iVar3);
  initializePathingSystem(this);
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x61a);
  this->random_seed = uVar2;
  TDebuggingLog::Log(L,(char *)L,s___World__after_map_gen__rand__d_,uVar2);
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x622);
  this->random_seed = uVar2;
  TDebuggingLog::Log(this_01,(char *)L,s___World__after_player_random_sta,uVar2);
  sVar1 = this->curr_player;
  this->curr_player = -1;
  iVar3 = 3;
  do {
    sVar4 = 0;
    world_update_counter = world_update_counter + 1;
    if (0 < this->player_num) {
      do {
        if (this->players[sVar4] != (RGE_Player *)0x0) {
          (**(code **)(this->players[sVar4]->_padding_ + 0x7c))();
        }
        sVar4 = sVar4 + 1;
      } while (sVar4 < this->player_num);
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this->curr_player = sVar1;
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x631);
  this->random_seed = uVar2;
  TDebuggingLog::Log(this_02,(char *)L,s___World__after_player_update__ra,uVar2);
  return '\x01';
}

// --------------------------------------------------

// Function: update_sounds
// Address: 00542e50
/* public: void __thiscall RGE_Game_World::update_sounds(unsigned long) */

void __thiscall RGE_Game_World::update_sounds(RGE_Game_World *this,ulong param_1)
{
  if ((int)this->sound_num <= this->sound_update_index) {
    this->sound_update_index = 0;
  }
  RGE_Sound::update(this->sounds[this->sound_update_index],param_1);
  this->sound_update_index = this->sound_update_index + 1;
  return;
}

// --------------------------------------------------

// Function: update_sprites
// Address: 00542e90
/* public: void __thiscall RGE_Game_World::update_sprites(unsigned long) */

void __thiscall RGE_Game_World::update_sprites(RGE_Game_World *this,ulong param_1)
{
  if ((int)this->sprite_num <= this->sprite_update_index) {
    this->sprite_update_index = 0;
  }
  if (this->sprites[this->sprite_update_index] != (RGE_Sprite *)0x0) {
    RGE_Sprite::update(this->sprites[this->sprite_update_index],param_1);
  }
  this->sprite_update_index = this->sprite_update_index + 1;
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00542ed0
// [HELPER] s_AILog__s_log: "AILog\%s.log"
// [HELPER] s_C__msdev_work_age1_x1_World_cpp: "C:\msdev\work\age1_x1\World.cpp"
// [HELPER] s_GAME_OVER__: "GAME OVER!\n"
// [HELPER] s__Status_Log_at_GameTime__02ld__0: "\nStatus Log at GameTime %02ld:%02ld:%02ld:\n"
// [HELPER] s___Player___d_Lost__: "  Player #%d Lost.\n"
// [HELPER] s___Player___d_Won__: "  Player #%d Won.\n"
// [HELPER] s_a: "a"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned char __thiscall RGE_Game_World::update(void) */

uchar __thiscall RGE_Game_World::update(RGE_Game_World *this)
{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  bool bVar9;
  char fileName [256];
  
  bVar9 = false;
  this->availableComputerPlayerUpdateTime = this->maximumComputerPlayerUpdateTime;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_World_cpp,0x68e);
  iVar2 = TCommunications_Handler::DoCycle(this->commands->com_hand,this->world_time);
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_World_cpp,0x690);
  RGE_Base_Game::add_to_timing(rge_base_game,0xe,uVar3 - uVar1);
  if (iVar2 == 0) {
    this->world_time_delta = 0;
    return this->game_state;
  }
  visible_combats = 0;
  debug_random_on = 1;
  debug_timeGetTime_on = 1;
  if (do_fixed_update != 0) {
    iVar2 = fixed_update_time;
  }
  debug_srand(s_C__msdev_work_age1_x1_World_cpp,0x6a2,this->random_seed);
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_World_cpp,0x6a4);
  update_sounds(this,uVar1);
  update_sprites(this,uVar1);
  if (iVar2 == -1) {
    bVar9 = this->old_time == 0;
  }
  this->old_time = uVar1;
  uVar1 = this->world_time;
  this->old_world_time = uVar1;
  if (this->temp_pause == '\0') {
    fileName[0] = '\0';
    fileName[1] = '\0';
    fileName[2] = '\0';
    fileName[3] = '\0';
    iVar2 = __ftol();
    this->world_time = iVar2 + uVar1;
  }
  else {
    if (iVar2 != -1) {
      fileName[0] = '\0';
      fileName[1] = '\0';
      fileName[2] = '\0';
      fileName[3] = '\0';
      iVar2 = __ftol();
      this->world_time = iVar2 + uVar1;
    }
    this->temp_pause = '\0';
  }
  uVar1 = this->world_time - this->old_world_time;
  this->world_time_delta = uVar1;
  if ((uVar1 != 0) || (bVar9)) {
    RGE_Command::do_commands(this->commands);
    RGE_Scenario::update(this->scenario);
    fileName[0] = '\0';
    fileName[1] = '\0';
    fileName[2] = '\0';
    fileName[3] = '\0';
    iVar2 = 0;
    this->world_time_delta_seconds = (float)this->world_time_delta * _DAT_00577a14;
    world_update_counter = world_update_counter + 1;
    if (0 < this->player_num) {
      puVar8 = this->player_time_delta;
      do {
        if (this->players[iVar2] != (RGE_Player *)0x0) {
          *puVar8 = *puVar8 + this->world_time_delta;
          (**(code **)(this->players[iVar2]->_padding_ + 0x7c))();
          RGE_Tile_List::del_list(&this->players[iVar2]->tile_list);
        }
        iVar2 = iVar2 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar2 < this->player_num);
    }
    if (MouseSystem != (TMousePointer *)0x0) {
      TMousePointer::Poll(MouseSystem);
    }
    uVar4 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x6e2);
    iVar2 = 0;
    if (0 < this->player_num) {
      do {
        if (this->players[iVar2] != (RGE_Player *)0x0) {
          RGE_Object_List::update(this->players[iVar2]->doppleganger_objects);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->player_num);
    }
    iVar2 = 0;
    if (0 < this->player_num) {
      do {
        if (this->players[iVar2] != (RGE_Player *)0x0) {
          RGE_Doppleganger_Creator::perform_doppleganger_checks
                    (this->players[iVar2]->doppleganger_creator);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->player_num);
    }
    debug_srand(s_C__msdev_work_age1_x1_World_cpp,0x6f6,uVar4);
    this->player_time_delta[this->player_turn] = 0;
    iVar2 = this->player_turn + 1;
    this->player_turn = iVar2;
    if (this->player_num <= iVar2) {
      this->player_turn = 0;
    }
    (**(code **)(this->_padding_ + 0xc4))();
  }
  uVar4 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x71a);
  this->random_seed = uVar4;
  debug_random_on = 0;
  debug_timeGetTime_on = 0;
  TCommunications_Handler::LastWorldRandom(this->commands->com_hand,this->random_seed);
  if (logStatusOn == 1) {
    if (this->game_state != '\x01') {
      if ((30000 < this->world_time - lastStatusLogTime) || (lastStatusLogTime == 0)) {
        if (logStatusFile == (_iobuf *)0x0) {
          pcVar5 = RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info);
          sprintf(fileName + 4,s_AILog__s_log,pcVar5);
          logStatusFile = (_iobuf *)fopen(fileName + 4,s_a);
          if (logStatusFile == (_iobuf *)0x0) goto LAB_00543368;
        }
        uVar6 = 0;
        uVar7 = 0;
        uVar4 = this->world_time / 1000;
        if (0x3b < uVar4) {
          uVar6 = uVar4 / 0x3c;
          uVar4 = uVar4 % 0x3c;
          if (0x3b < uVar6) {
            uVar7 = uVar6 / 0x3c;
            uVar6 = uVar6 % 0x3c;
          }
        }
        if (lastStatusLogTime == 0) {
          (**(code **)(this->_padding_ + 0x9c))(logStatusFile,1);
        }
        else {
          fprintf(logStatusFile,s__Status_Log_at_GameTime__02ld__0,uVar7,uVar6,uVar4);
        }
        iVar2 = 1;
        if (1 < this->player_num) {
          do {
            if (this->players[iVar2] != (RGE_Player *)0x0) {
              (**(code **)(this->players[iVar2]->_padding_ + 0xec))
                        (logStatusFile,lastStatusLogTime == 0);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < this->player_num);
        }
        lastStatusLogTime = this->world_time + 1;
      }
      goto LAB_005432e7;
    }
  }
  else {
LAB_005432e7:
    if (this->game_state != '\x01') goto LAB_00543368;
  }
  iVar2 = 1;
  if ((logStatusOn == 1) && (logStatusFile != (_iobuf *)0x0)) {
    fprintf(logStatusFile,s_GAME_OVER__);
    if (1 < this->player_num) {
      do {
        if (this->players[iVar2] != (RGE_Player *)0x0) {
          if (this->players[iVar2]->game_status == '\x01') {
            pcVar5 = s___Player___d_Won__;
          }
          else {
            pcVar5 = s___Player___d_Lost__;
          }
          fprintf(logStatusFile,pcVar5,iVar2);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->player_num);
    }
    fclose(logStatusFile);
    logStatusFile = (_iobuf *)0x0;
  }
LAB_00543368:
  return this->game_state;
}

// --------------------------------------------------

// Function: is_player_turn
// Address: 00543380
/* public: int __thiscall RGE_Game_World::is_player_turn(int) */

int __thiscall RGE_Game_World::is_player_turn(RGE_Game_World *this,int param_1)
{
  return (uint)(this->player_turn == param_1);
}

// --------------------------------------------------

// Function: get_accum_time_delta
// Address: 005433a0
/* public: unsigned long __thiscall RGE_Game_World::get_accum_time_delta(int) */

ulong __thiscall RGE_Game_World::get_accum_time_delta(RGE_Game_World *this,int param_1)
{
  return this->player_time_delta[param_1];
}

// --------------------------------------------------

// Function: get_game_state
// Address: 005433b0
/* public: virtual unsigned char __thiscall RGE_Game_World::get_game_state(void) */

uchar __thiscall RGE_Game_World::get_game_state(RGE_Game_World *this)
{
  return this->game_state;
}

// --------------------------------------------------

// Function: check_game_state
// Address: 005433c0
/* WARNING: Variable defined which should be unmapped: games_won */
/* public: virtual unsigned char __thiscall RGE_Game_World::check_game_state(void) */

uchar __thiscall RGE_Game_World::check_game_state(RGE_Game_World *this)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long games_won;
  long games_lost;
  long games_on;
  int local_4;
  
  iVar4 = 1;
  iVar2 = 0;
  iVar3 = 0;
  local_4 = 0;
  games_lost = 0;
  games_on = 0;
  if (1 < this->player_num) {
    do {
      uVar1 = RGE_Player::check_victory(this->players[iVar4]);
      if (uVar1 == '\0') {
        local_4 = local_4 + 1;
        if ((iVar3 < 1) || (iVar2 == 0)) {
          iVar2 = 1;
          iVar3 = iVar4;
        }
        else if (((this->players[iVar4]->allied_victory == '\0') ||
                 (uVar1 = RGE_Player::relation(this->players[iVar3],iVar4), uVar1 != '\0')) ||
                (uVar1 = RGE_Player::relation(this->players[iVar4],iVar3), uVar1 != '\0')) {
          iVar2 = -1;
        }
      }
      else if (uVar1 == '\x01') {
        games_lost = games_lost + 1;
      }
      else if (uVar1 == '\x02') {
        games_on = games_on + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->player_num);
  }
  if (games_lost < 1) {
    uVar1 = RGE_Scenario::Get_conquest_victory(this->scenario);
    if ((uVar1 != '\0') && (((0 < games_on && (0 < iVar2)) || (local_4 == 0)))) {
      iVar3 = 1;
      this->game_state = '\x01';
      if (1 < this->player_num) {
        do {
          RGE_Player::victory_if_game_on(this->players[iVar3]);
          iVar3 = iVar3 + 1;
        } while (iVar3 < this->player_num);
      }
      this->game_end_condition = '\x01';
    }
  }
  else {
    iVar3 = 1;
    this->game_state = '\x01';
    if (1 < this->player_num) {
      do {
        RGE_Player::loss_if_game_on(this->players[iVar3]);
        iVar3 = iVar3 + 1;
      } while (iVar3 < this->player_num);
    }
  }
  if ((this->game_state == '\x01') && (-1 < this->campaign)) {
    uVar1 = RGE_Base_Game::set_campaign_info
                      (rge_base_game,this->campaign,this->campaign_player,this->campaign_scenario);
    if (uVar1 == '\0') {
      this->campaign = -1;
    }
    else if (this->players[this->curr_player]->game_status == '\x01') {
      RGE_Base_Game::set_campaign_win(rge_base_game);
      return this->game_state;
    }
  }
  return this->game_state;
}

// --------------------------------------------------

// Function: save
// Address: 00543540
/* protected: virtual void __thiscall RGE_Game_World::save(int) */

void __thiscall RGE_Game_World::save(RGE_Game_World *this,int param_1)
{
  short *psVar1;
  int iVar2;
  ulong *puVar3;
  int iVar4;
  
  iVar2 = param_1;
  color_log('$','$',1);
  save_game_version = 7.23;
  rge_write(param_1,&this->world_time,4);
  rge_write(param_1,&this->old_world_time,4);
  rge_write(param_1,&this->world_time_delta,4);
  rge_write(param_1,&this->world_time_delta_seconds,4);
  rge_write(param_1,&this->timer,4);
  rge_write(param_1,&this->game_speed,4);
  rge_write(param_1,&this->temp_pause,1);
  rge_write(param_1,&this->next_object_id,4);
  rge_write(param_1,&this->next_reusable_object_id,4);
  rge_write(param_1,&this->random_seed,4);
  rge_write(param_1,&this->curr_player,2);
  psVar1 = &this->player_num;
  rge_write(param_1,psVar1,2);
  rge_write(param_1,&this->game_state,1);
  rge_write(param_1,&this->campaign,4);
  rge_write(param_1,&this->campaign_player,4);
  rge_write(param_1,&this->campaign_scenario,4);
  rge_write(param_1,&this->player_turn,4);
  puVar3 = this->player_time_delta;
  param_1 = 9;
  do {
    rge_write(iVar2,puVar3,4);
    puVar3 = puVar3 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  RGE_Map::save_map(this->map,iVar2);
  iVar4 = 0;
  if (0 < *psVar1) {
    do {
      color_log('$','L',1);
      (**(code **)(this->players[iVar4]->_padding_ + 0x84))(iVar2);
      color_log('$','\x16',1);
      (**(code **)(this->players[iVar4]->_padding_ + 0x88))(iVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *psVar1);
  }
  color_log('$','2',1);
  iVar4 = 0;
  if (0 < *psVar1) {
    do {
      (**(code **)(this->players[iVar4]->_padding_ + 0x8c))(iVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *psVar1);
  }
  color_log('$','E',1);
  (**(code **)(this->scenario->_padding_ + 0xc))(iVar2);
  color_log('$','_',1);
  if (this->difficultyLevelValue == -1) {
    iVar4 = RGE_Base_Game::difficulty(rge_base_game);
    this->difficultyLevelValue = iVar4;
  }
  rge_write(iVar2,&this->difficultyLevelValue,4);
  return;
}

// --------------------------------------------------

// Function: save_game
// Address: 00543770
// [HELPER] s_VER_8_6: "VER 8.6"
// [HELPER] s__s_s: "%s%s"
/* WARNING: Variable defined which should be unmapped: tempname */
/* public: virtual unsigned char __thiscall RGE_Game_World::save_game(char *) */

uchar __thiscall RGE_Game_World::save_game(RGE_Game_World *this,char *param_1)
{
  int iVar1;
  char tempname [300];
  
  save_game_version = 7.23;
  sprintf(tempname + 4,s__s_s,rge_base_game->prog_info->save_dir,param_1);
  iVar1 = rge_open(tempname + 4,0x8309,0x180);
  if (iVar1 == -1) {
    return '\0';
  }
  rge_write_error = 0;
  rge_write(iVar1,&s_VER_8_6,8);
  rge_write(iVar1,&save_game_version,4);
  (**(code **)(this->_padding_ + 0x68))(iVar1);
  rge_close(iVar1);
  if (rge_write_error != 0) {
    __unlink(tempname);
    return '\0';
  }
  return '\x01';
}

// --------------------------------------------------

// Function: base_save
// Address: 00543850
// [HELPER] s_VER_3_7: "VER 3.7"
/* public: virtual void __thiscall RGE_Game_World::base_save(int) */

void __thiscall RGE_Game_World::base_save(RGE_Game_World *this,int param_1)
{
  short *psVar1;
  int iVar2;
  
  rge_write(param_1,&s_VER_3_7,8);
  psVar1 = &this->terrain_num;
  rge_write(param_1,psVar1,2);
  rge_write(param_1,&this->terrain_size,2);
  if ((0 < *psVar1) && (0 < this->terrain_size)) {
    rge_write(param_1,this->terrains,(int)*psVar1 << 2);
    iVar2 = 0;
    if (0 < *psVar1) {
      do {
        if (this->terrains[iVar2] != (float *)0x0) {
          rge_write(param_1,this->terrains[iVar2],(int)this->terrain_size << 2);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *psVar1);
    }
  }
  psVar1 = &this->color_table_num;
  rge_write(param_1,psVar1,2);
  iVar2 = 0;
  if (0 < *psVar1) {
    do {
      RGE_Color_Table::save(this->color_tables[iVar2],param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *psVar1);
  }
  psVar1 = &this->sound_num;
  rge_write(param_1,psVar1,2);
  iVar2 = 0;
  if (0 < *psVar1) {
    do {
      RGE_Sound::save(this->sounds[iVar2],param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *psVar1);
  }
  psVar1 = &this->sprite_num;
  rge_write(param_1,psVar1,2);
  rge_write(param_1,this->sprites,(int)*psVar1 << 2);
  iVar2 = 0;
  if (0 < *psVar1) {
    do {
      if (this->sprites[iVar2] != (RGE_Sprite *)0x0) {
        RGE_Sprite::save(this->sprites[iVar2],param_1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *psVar1);
  }
  (**(code **)(this->map->_padding_ + 0x2c))(param_1);
  (**(code **)(this->effects->_padding_ + 4))(param_1);
  psVar1 = &this->master_player_num;
  rge_write(param_1,psVar1,2);
  iVar2 = 0;
  if (0 < *psVar1) {
    do {
      (**(code **)(this->master_players[iVar2]->_padding_ + 0x14))(param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *psVar1);
  }
  return;
}

// --------------------------------------------------

// Function: base_save
// Address: 005439c0
/* public: virtual void __thiscall RGE_Game_World::base_save(char *) */

void __thiscall RGE_Game_World::base_save(RGE_Game_World *this,char *param_1)
{
  int iVar1;
  
  iVar1 = rge_open(param_1,0x8309,0x180);
  if (iVar1 != -1) {
    (**(code **)(this->_padding_ + 0xe0))(iVar1);
    rge_close(iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: save_scenario
// Address: 00543a00
// [HELPER] s_1_10: "1.10"
// [HELPER] s_1_11: "1.11"
// [HELPER] s_TRIAL: "TRIAL"
// [HELPER] s__s_s: "%s%s"
// [HELPER] s__s_s_scn: "%s%s.scn"
/* WARNING: Variable defined which should be unmapped: obj_angle */
/* public: virtual unsigned char __thiscall RGE_Game_World::save_scenario(char *) */

uchar __thiscall RGE_Game_World::save_scenario(RGE_Game_World *this,char *param_1)
{
  byte bVar1;
  RGE_Object_Node *pRVar2;
  RGE_Static_Object *pRVar3;
  long lVar4;
  uchar uVar5;
  char *pcVar6;
  int iVar7;
  char cVar8;
  float unaff_EBP;
  int iVar9;
  float obj_angle;
  long count;
  long index;
  long scenario_player_num;
  char scenario_name [300];
  char kill_name [300];
  
  scenario_name._0_4_ = SEXT24(this->player_num);
  cVar8 = *param_1;
  pcVar6 = param_1;
  iVar7 = 0;
  do {
    iVar9 = iVar7;
    pcVar6[(int)(kill_name + (4 - (int)param_1))] = cVar8;
    cVar8 = pcVar6[1];
    pcVar6 = pcVar6 + 1;
    iVar7 = iVar9 + 1;
  } while (cVar8 != '.');
  kill_name[iVar9 + 5] = '\0';
  obj_angle = unaff_EBP;
  sprintf(scenario_name + 4,s__s_s_scn,rge_base_game->prog_info->scenario_dir,kill_name + 4);
  __unlink(scenario_name + 4);
  sprintf(scenario_name + 4,s__s_s,rge_base_game->prog_info->scenario_dir,param_1);
  iVar7 = rge_open(scenario_name + 4,0x8301,0x180);
  if (iVar7 == -1) {
    return '\0';
  }
  rge_write_error = 0;
  uVar5 = RGE_Base_Game::check_prog_argument(rge_base_game,s_TRIAL);
  if (uVar5 == '\x01') {
    pcVar6 = s_1_10;
  }
  else {
    pcVar6 = s_1_11;
  }
  rge_write_uncompressed(iVar7,pcVar6,4);
  RGE_Base_Game::write_scenario_header(rge_base_game,iVar7);
  rge_write(iVar7,&this->next_object_id,4);
  (**(code **)(this->scenario->_padding_ + 0xc))(iVar7);
  RGE_Map::scenario_save(this->map,iVar7);
  rge_write(iVar7,&scenario_player_num,4);
  iVar9 = 1;
  if (1 < this->player_num) {
    do {
      (**(code **)(this->players[iVar9]->_padding_ + 100))(iVar7);
      iVar9 = iVar9 + 1;
    } while (iVar9 < this->player_num);
  }
  index = 0;
  if (0 < this->player_num) {
    do {
      lVar4 = index;
      count = 0;
      for (pRVar2 = this->players[index]->objects->list; pRVar2 != (RGE_Object_Node *)0x0;
          pRVar2 = pRVar2->next) {
        if (pRVar2->node->master_obj->master_type != '\x19') {
          count = count + 1;
        }
      }
      for (pRVar2 = this->players[index]->sleeping_objects->list; pRVar2 != (RGE_Object_Node *)0x0;
          pRVar2 = pRVar2->next) {
        if (pRVar2->node->master_obj->master_type != '\x19') {
          count = count + 1;
        }
      }
      rge_write(iVar7,&count,4);
      for (pRVar2 = this->players[lVar4]->objects->list; pRVar2 != (RGE_Object_Node *)0x0;
          pRVar2 = pRVar2->next) {
        if (pRVar2->node->master_obj->master_type != '\x19') {
          rge_write(iVar7,&pRVar2->node->world_x,4);
          rge_write(iVar7,&pRVar2->node->world_y,4);
          rge_write(iVar7,&pRVar2->node->world_z,4);
          rge_write(iVar7,&pRVar2->node->id,4);
          rge_write(iVar7,&pRVar2->node->master_obj->id,2);
          rge_write(iVar7,&pRVar2->node->object_state,1);
          pRVar3 = pRVar2->node;
          bVar1 = pRVar3->master_obj->master_type;
          if ((bVar1 < 0x1f) || (0x59 < bVar1)) {
            obj_angle = (float)pRVar3->facet;
          }
          else {
            obj_angle = (float)pRVar3[1].old_sprite;
          }
          rge_write(iVar7,&obj_angle,4);
        }
      }
      for (pRVar2 = this->players[index]->sleeping_objects->list; pRVar2 != (RGE_Object_Node *)0x0;
          pRVar2 = pRVar2->next) {
        if (pRVar2->node->master_obj->master_type != '\x19') {
          rge_write(iVar7,&pRVar2->node->world_x,4);
          rge_write(iVar7,&pRVar2->node->world_y,4);
          rge_write(iVar7,&pRVar2->node->world_z,4);
          rge_write(iVar7,&pRVar2->node->id,4);
          rge_write(iVar7,&pRVar2->node->master_obj->id,2);
          rge_write(iVar7,&pRVar2->node->object_state,1);
          pRVar3 = pRVar2->node;
          bVar1 = pRVar3->master_obj->master_type;
          if ((bVar1 < 0x1f) || (0x59 < bVar1)) {
            obj_angle = (float)pRVar3->facet;
          }
          else {
            obj_angle = (float)pRVar3[1].old_sprite;
          }
          rge_write(iVar7,&obj_angle,4);
        }
      }
      index = index + 1;
    } while (index < this->player_num);
  }
  rge_write(iVar7,&scenario_player_num,4);
  iVar9 = 1;
  if (1 < this->player_num) {
    do {
      (**(code **)(this->players[iVar9]->_padding_ + 0x6c))(iVar7);
      iVar9 = iVar9 + 1;
    } while (iVar9 < this->player_num);
  }
  rge_close(iVar7);
  if (rge_write_error != 0) {
    __unlink(scenario_name);
    return '\0';
  }
  return '\x01';
}

// --------------------------------------------------

// Function: load_scenario
// Address: 00543e00
// [HELPER] s_1_01: "1.01"
// [HELPER] s_1_02: "1.02"
// [HELPER] s_1_03: "1.03"
// [HELPER] s_1_04: "1.04"
// [HELPER] s_1_05: "1.05"
// [HELPER] s_1_06: "1.06"
// [HELPER] s_1_07: "1.07"
// [HELPER] s_1_08: "1.08"
// [HELPER] s_1_09: "1.09"
// [HELPER] s_1_10: "1.10"
// [HELPER] s_1_11: "1.11"
// [HELPER] s__s_s: "%s%s"
/* WARNING: Variable defined which should be unmapped: header_size */
/* protected: virtual unsigned char __thiscall RGE_Game_World::load_scenario(char *,struct
   RGE_Player_Info &) */

uchar __thiscall
RGE_Game_World::load_scenario(RGE_Game_World *this,char *param_1,RGE_Player_Info *param_2)
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  long header_size;
  long version;
  char scenario_name [300];
  
  world_update_counter = 0;
  sprintf(scenario_name + 4,s__s_s,rge_base_game->prog_info->scenario_dir,param_1);
  if (param_1 != (char *)0x0) {
    iVar2 = rge_open(scenario_name + 4,0x8000);
    if (iVar2 != -1) {
      rge_read_uncompressed(iVar2,scenario_name,4);
      if (scenario_name._0_4_ == s_1_01._0_4_) {
        iVar1 = this->_padding_;
        (**(code **)(iVar1 + 0x7c))(iVar2,param_2);
        (**(code **)(iVar1 + 0xa8))(param_2);
        return '\x01';
      }
      if (scenario_name._0_4_ == s_1_02._0_4_) goto LAB_00543efd;
      if (scenario_name._0_4_ == s_1_03._0_4_) {
        rge_read_uncompressed(iVar2,&version,4);
        if (version < 1) {
LAB_00543efd:
          iVar1 = this->_padding_;
          (**(code **)(iVar1 + 0x80))(iVar2,param_2);
          (**(code **)(iVar1 + 0xa8))(param_2);
          return '\x01';
        }
        pvVar3 = (void *)malloc(version);
        if (pvVar3 != (void *)0x0) {
          rge_read_uncompressed(iVar2,pvVar3,version);
          free(pvVar3);
          goto LAB_00543efd;
        }
      }
      else {
        if (scenario_name._0_4_ == s_1_04._0_4_) {
          iVar1 = this->_padding_;
          (**(code **)(iVar1 + 0x84))(iVar2,param_2);
          (**(code **)(iVar1 + 0xa8))(param_2);
          return '\x01';
        }
        if (scenario_name._0_4_ == s_1_05._0_4_) {
          iVar1 = this->_padding_;
          (**(code **)(iVar1 + 0x88))(iVar2,param_2);
          (**(code **)(iVar1 + 0xa8))(param_2);
          return '\x01';
        }
        if (scenario_name._0_4_ == s_1_06._0_4_) {
          iVar1 = this->_padding_;
          (**(code **)(iVar1 + 0x8c))(iVar2,param_2);
          (**(code **)(iVar1 + 0xa8))(param_2);
          return '\x01';
        }
        if (scenario_name._0_4_ == s_1_07._0_4_) {
          iVar1 = this->_padding_;
          (**(code **)(iVar1 + 0x90))(iVar2,param_2);
          (**(code **)(iVar1 + 0xa8))(param_2);
          return '\x01';
        }
        if (scenario_name._0_4_ == s_1_08._0_4_) {
          iVar1 = this->_padding_;
          (**(code **)(iVar1 + 0x94))(iVar2,param_2);
          (**(code **)(iVar1 + 0xa8))(param_2);
          return '\x01';
        }
        if (((scenario_name._0_4_ == s_1_09._0_4_) || (scenario_name._0_4_ == s_1_11._0_4_)) ||
           (scenario_name._0_4_ == s_1_10._0_4_)) {
          iVar1 = this->_padding_;
          (**(code **)(iVar1 + 0x98))(iVar2,param_2);
          (**(code **)(iVar1 + 0xa8))(param_2);
          return '\x01';
        }
      }
      rge_close(iVar2);
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: load_scenario
// Address: 00544090
// [HELPER] s_1_01: "1.01"
// [HELPER] s_1_02: "1.02"
// [HELPER] s_1_03: "1.03"
// [HELPER] s_1_04: "1.04"
// [HELPER] s_1_05: "1.05"
// [HELPER] s_1_06: "1.06"
// [HELPER] s_1_07: "1.07"
// [HELPER] s_1_08: "1.08"
// [HELPER] s_1_09: "1.09"
// [HELPER] s_1_10: "1.10"
// [HELPER] s_1_11: "1.11"
/* WARNING: Variable defined which should be unmapped: header_size */
/* protected: virtual unsigned char __thiscall RGE_Game_World::load_scenario(struct RGE_Player_Info
   &) */

uchar __thiscall RGE_Game_World::load_scenario(RGE_Game_World *this,RGE_Player_Info *param_1)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  long header_size;
  long version;
  int local_4;
  
  world_update_counter = 0;
  iVar1 = RGE_Base_Game::campaign_open_scenario(rge_base_game);
  if (iVar1 == -1) {
    return '\0';
  }
  rge_read_uncompressed(iVar1,&local_4,4);
  if (local_4 == s_1_01._0_4_) {
    iVar3 = this->_padding_;
    (**(code **)(iVar3 + 0x7c))(iVar1,param_1);
  }
  else {
    if (local_4 != s_1_02._0_4_) {
      if (local_4 != s_1_03._0_4_) {
        if (local_4 == s_1_04._0_4_) {
          iVar3 = this->_padding_;
          (**(code **)(iVar3 + 0x84))(iVar1,param_1);
        }
        else if (local_4 == s_1_05._0_4_) {
          iVar3 = this->_padding_;
          (**(code **)(iVar3 + 0x88))(iVar1,param_1);
        }
        else if (local_4 == s_1_06._0_4_) {
          iVar3 = this->_padding_;
          (**(code **)(iVar3 + 0x8c))(iVar1,param_1);
        }
        else if (local_4 == s_1_07._0_4_) {
          iVar3 = this->_padding_;
          (**(code **)(iVar3 + 0x90))(iVar1,param_1);
        }
        else if (local_4 == s_1_08._0_4_) {
          iVar3 = this->_padding_;
          (**(code **)(iVar3 + 0x94))(iVar1,param_1);
        }
        else {
          if (((local_4 != s_1_09._0_4_) && (local_4 != s_1_11._0_4_)) && (local_4 != s_1_10._0_4_))
          goto LAB_00544233;
          iVar3 = this->_padding_;
          (**(code **)(iVar3 + 0x98))(iVar1,param_1);
        }
        goto LAB_005441fe;
      }
      rge_read_uncompressed(iVar1,&version,4);
      if (0 < version) {
        pvVar2 = (void *)malloc(version);
        if (pvVar2 == (void *)0x0) {
LAB_00544233:
          rge_close(iVar1);
          return '\0';
        }
        rge_read_uncompressed(iVar1,pvVar2,version);
        free(pvVar2);
      }
    }
    iVar3 = this->_padding_;
    (**(code **)(iVar3 + 0x80))(iVar1,param_1);
  }
LAB_005441fe:
  (**(code **)(iVar3 + 0xa8))(param_1);
  RGE_Base_Game::get_campaign_info
            (rge_base_game,&this->campaign,&this->campaign_player,&this->campaign_scenario);
  return '\x01';
}

// --------------------------------------------------

// Function: scenario_make_player
// Address: 00544250
/* protected: virtual void __thiscall RGE_Game_World::scenario_make_player(short,unsigned
   char,unsigned char,unsigned char,char *) */

void __thiscall
RGE_Game_World::scenario_make_player
          (RGE_Game_World *this,short param_1,uchar param_2,uchar param_3,uchar param_4,
          char *param_5)
{
  RGE_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561e6b;
  *unaff_FS_OFFSET = &local_c;
  if (param_3 == '\0') {
    pRVar1 = (RGE_Player *)operator_new(0x220);
    local_4 = 0;
    if (pRVar1 == (RGE_Player *)0x0) {
      pRVar1 = (RGE_Player *)0x0;
    }
    else {
      pRVar1 = (RGE_Player *)
               RGE_Player::RGE_Player
                         (pRVar1,this,this->master_players[param_4],(uchar)param_1,param_5,param_4,
                          '\x01');
    }
    this->players[param_1] = pRVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: scenario_make_map
// Address: 005442e0
/* protected: virtual void __thiscall RGE_Game_World::scenario_make_map(int) */

void __thiscall RGE_Game_World::scenario_make_map(RGE_Game_World *this,int param_1)
{
  RGE_Map::scenario_load(this->map,param_1,(uchar *)0x0);
  return;
}

// --------------------------------------------------

// Function: load_scenario1
// Address: 00544300
/* WARNING: Variable defined which should be unmapped: master_player_id */
/* protected: virtual void __thiscall RGE_Game_World::load_scenario1(int,struct RGE_Player_Info &)
    */

void __thiscall
RGE_Game_World::load_scenario1(RGE_Game_World *this,int param_1,RGE_Player_Info *param_2)
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  RGE_Player *pRVar6;
  int iVar7;
  int unaff_EBX;
  int unaff_EBP;
  int iVar8;
  undefined4 uVar9;
  int iStack_64;
  uchar master_player_id;
  long scenario_player_num;
  long count;
  long id;
  float obj_angle;
  uchar obj_state;
  short master_id;
  float world_z;
  float world_y;
  float world_x;
  long obj_id;
  char rem [13];
  long player_id_hash [9];
  int iStack_4;
  
  iStack_64 = unaff_EBX;
  rge_read(param_1,rem,4);
  iVar7 = this->_padding_;
  (**(code **)(iVar7 + 0xf4))(param_1,this);
  (**(code **)(iVar7 + 0x70))(param_1);
  iVar7 = (int)this->player_num;
  if (0 < iVar7) {
    do {
      pcVar1 = rem + 8;
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        pcVar1[0] = -1;
        pcVar1[1] = -1;
        pcVar1[2] = -1;
        pcVar1[3] = -1;
        pcVar1 = pcVar1 + 4;
      }
    } while (10 < iVar7);
  }
  iVar4 = 0;
  if (0 < iVar7) {
    piVar5 = (int *)(iStack_4 + 0x270);
    do {
      iVar8 = *piVar5;
      piVar5 = piVar5 + 1;
      *(int *)(rem + iVar8 * 4 + 8) = iVar4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar7);
  }
  iVar4 = 0;
  if (0 < iVar7) {
    do {
      RGE_Player::remake_visible_map(this->players[iVar4]);
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->player_num);
  }
  rge_read(param_1,&stack0xffffff98,4);
  iVar7 = 0;
  if (0 < unaff_EBP) {
    do {
      rge_read(param_1,player_id_hash + 8,1);
      rge_read(param_1,&stack0xffffff97,1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < unaff_EBP);
  }
  iVar7 = 0;
  if (0 < unaff_EBP) {
    do {
      rge_read(param_1,&stack0xffffff9c,4);
      iVar4 = 0;
      if (0 < iStack_64) {
        do {
          rge_read(param_1,&world_z,4);
          rge_read(param_1,&master_id,4);
          rge_read(param_1,&obj_state,4);
          rge_read(param_1,&scenario_player_num,4);
          rge_read(param_1,&obj_angle,2);
          rge_read(param_1,&id,1);
          rge_read(param_1,&count,4);
          if (((iVar7 < this->player_num) && (iVar8 = *(int *)(rem + iVar7 * 4 + 8), -1 < iVar8)) &&
             (this->players[iVar7] != (RGE_Player *)0x0)) {
            this->scenario_object_flag = '\x01';
            this->scenario_object_id = scenario_player_num;
            (**(code **)(this->players[iVar8]->_padding_ + 0x60))
                      (world_z,_master_id,_obj_state,obj_angle,id,count);
            this->scenario_object_flag = '\0';
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iStack_64);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < unaff_EBP);
  }
  this->next_object_id = (long)world_y;
  rge_read(param_1,&world_x,0xd);
  iVar7 = 1;
  if (1 < unaff_EBP) {
    piVar5 = (int *)(rem + 0xc);
    do {
      if (((this->player_num <= iVar7) || (*piVar5 < 0)) ||
         (pRVar6 = this->players[*piVar5], pRVar6 == (RGE_Player *)0x0)) {
        pRVar6 = *this->players;
      }
      (**(code **)(pRVar6->_padding_ + 0x68))(param_1,rem + 8,0x3f800000);
      iVar7 = iVar7 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar7 < unaff_EBP);
  }
  rge_close(param_1);
  iStack_4 = 1;
  if (1 < this->player_num) {
    do {
      if (unaff_EBP <= iStack_4) {
        return;
      }
      if (this->players[iStack_4] != (RGE_Player *)0x0) {
        iVar8 = iStack_4 + -1;
        uVar9 = 0xffffffff;
        iVar7 = this->players[*(int *)(rem + iStack_4 * 4 + 8)]->_padding_;
        iVar4 = RGE_Scenario::GetPlayerPosture(this->scenario,iVar8);
        pcVar1 = RGE_Scenario::Get_player_AI(this->scenario,iVar8,1);
        pcVar2 = RGE_Scenario::Get_CityPlan(this->scenario,iVar8,1);
        pcVar3 = RGE_Scenario::Get_BuildList(this->scenario,iVar8,1);
        (**(code **)(iVar7 + 0x2c))(pcVar3,pcVar2,pcVar1,iVar4,uVar9);
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: load_scenario2
// Address: 005445c0
/* WARNING: Variable defined which should be unmapped: master_player_id */
/* protected: virtual void __thiscall RGE_Game_World::load_scenario2(int,struct RGE_Player_Info &)
    */

void __thiscall
RGE_Game_World::load_scenario2(RGE_Game_World *this,int param_1,RGE_Player_Info *param_2)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  RGE_Player *pRVar8;
  int iVar9;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 uVar10;
  int iStack_64;
  uchar master_player_id;
  long scenario_player_num;
  long count;
  long id;
  float obj_angle;
  uchar obj_state;
  short master_id;
  float world_z;
  float world_y;
  float world_x;
  long obj_id;
  char rem [13];
  long player_id_hash [9];
  int iStack_4;
  
  world_update_counter = 0;
  iStack_64 = unaff_EBX;
  rge_read(param_1,rem,4);
  iVar9 = this->_padding_;
  (**(code **)(iVar9 + 0xf4))(param_1,this);
  (**(code **)(iVar9 + 0x70))(param_1);
  iVar9 = (int)this->player_num;
  if (0 < iVar9) {
    do {
      pcVar3 = rem + 8;
      for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        pcVar3[0] = -1;
        pcVar3[1] = -1;
        pcVar3[2] = -1;
        pcVar3[3] = -1;
        pcVar3 = pcVar3 + 4;
      }
    } while (10 < iVar9);
  }
  iVar6 = 0;
  if (0 < iVar9) {
    piVar7 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar7;
      piVar7 = piVar7 + 1;
      *(int *)(rem + iVar1 * 4 + 8) = iVar6;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar9);
  }
  iVar6 = 0;
  if (0 < iVar9) {
    do {
      RGE_Player::remake_visible_map(this->players[iVar6]);
      iVar6 = iVar6 + 1;
    } while (iVar6 < this->player_num);
  }
  rge_read(param_1,&stack0xffffff98,4);
  iVar9 = 0;
  if (0 < unaff_EBP) {
    do {
      rge_read(param_1,player_id_hash + 8,1);
      rge_read(param_1,&stack0xffffff97,1);
      iVar9 = iVar9 + 1;
    } while (iVar9 < unaff_EBP);
  }
  iStack_4 = 0;
  if (0 < unaff_EBP) {
    piVar7 = (int *)(rem + 8);
    do {
      rge_read(param_1,&stack0xffffff9c,4);
      iVar9 = 0;
      if (0 < iStack_64) {
        do {
          rge_read(param_1,&world_z,4);
          rge_read(param_1,&master_id,4);
          rge_read(param_1,&obj_state,4);
          rge_read(param_1,&scenario_player_num,4);
          rge_read(param_1,&obj_angle,2);
          rge_read(param_1,&id,1);
          rge_read(param_1,&count,4);
          iVar6 = *piVar7;
          if ((-1 < iVar6) && (this->players[iVar6] != (RGE_Player *)0x0)) {
            this->scenario_object_flag = '\x01';
            this->scenario_object_id = scenario_player_num;
            (**(code **)(this->players[iVar6]->_padding_ + 0x60))
                      (world_z,_master_id,_obj_state,obj_angle,id,count);
            this->scenario_object_flag = '\0';
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iStack_64);
      }
      iStack_4 = iStack_4 + 1;
      piVar7 = piVar7 + 1;
    } while (iStack_4 < unaff_EBP);
  }
  this->next_object_id = (long)world_y;
  rge_read(param_1,&world_x,0xd);
  iVar9 = 1;
  if (1 < unaff_EBP) {
    piVar7 = (int *)(rem + 0xc);
    do {
      if (((this->player_num <= iVar9) || (*piVar7 < 0)) ||
         (pRVar8 = this->players[*piVar7], pRVar8 == (RGE_Player *)0x0)) {
        pRVar8 = *this->players;
      }
      (**(code **)(pRVar8->_padding_ + 0x68))(param_1,rem + 8,0x3f83d70a);
      iVar9 = iVar9 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar9 < unaff_EBP);
  }
  rge_close(param_1);
  iVar9 = 1;
  if (1 < this->player_num) {
    do {
      if (unaff_EBP <= iVar9) {
        return;
      }
      if ((this->players[iVar9] != (RGE_Player *)0x0) && (-1 < *(int *)(rem + iVar9 * 4 + 8))) {
        iVar6 = iVar9 + -1;
        uVar10 = 0xffffffff;
        iVar1 = this->players[*(int *)(rem + iVar9 * 4 + 8)]->_padding_;
        iVar2 = RGE_Scenario::GetPlayerPosture(this->scenario,iVar6);
        pcVar3 = RGE_Scenario::Get_player_AI(this->scenario,iVar6,1);
        pcVar4 = RGE_Scenario::Get_CityPlan(this->scenario,iVar6,1);
        pcVar5 = RGE_Scenario::Get_BuildList(this->scenario,iVar6,1);
        (**(code **)(iVar1 + 0x2c))(pcVar5,pcVar4,pcVar3,iVar2,uVar10);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: load_scenario3
// Address: 00544880
/* WARNING: Variable defined which should be unmapped: master_player_id */
/* protected: virtual void __thiscall RGE_Game_World::load_scenario3(int,struct RGE_Player_Info &)
    */

void __thiscall
RGE_Game_World::load_scenario3(RGE_Game_World *this,int param_1,RGE_Player_Info *param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  RGE_Player *pRVar9;
  int iVar10;
  int unaff_EBP;
  undefined4 uVar11;
  uchar master_player_id;
  long scenario_player_num;
  long header_size;
  long count;
  long id;
  float obj_angle;
  uchar obj_state;
  short master_id;
  float world_z;
  float world_y;
  float world_x;
  long obj_id;
  char rem [13];
  long player_id_hash [9];
  int iStack_4;
  
  world_update_counter = 0;
  rge_read_uncompressed(param_1,&count,4);
  if (0 < count) {
    pvVar2 = (void *)malloc(count);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_1);
      return;
    }
    rge_read_uncompressed(param_1,pvVar2,count);
    free(pvVar2);
  }
  rge_read(param_1,rem,4);
  iVar10 = this->_padding_;
  (**(code **)(iVar10 + 0xf4))(param_1,this);
  (**(code **)(iVar10 + 0x70))(param_1);
  iVar10 = (int)this->player_num;
  if (0 < iVar10) {
    do {
      pcVar4 = rem + 8;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        pcVar4[0] = -1;
        pcVar4[1] = -1;
        pcVar4[2] = -1;
        pcVar4[3] = -1;
        pcVar4 = pcVar4 + 4;
      }
    } while (10 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    piVar8 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      *(int *)(rem + iVar1 * 4 + 8) = iVar7;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    do {
      RGE_Player::remake_visible_map(this->players[iVar7]);
      iVar7 = iVar7 + 1;
    } while (iVar7 < this->player_num);
  }
  rge_read(param_1,&stack0xffffff94,4);
  iVar10 = 0;
  if (0 < unaff_EBP) {
    do {
      rge_read(param_1,player_id_hash + 8,1);
      rge_read(param_1,&stack0xffffff93,1);
      iVar10 = iVar10 + 1;
    } while (iVar10 < unaff_EBP);
  }
  iStack_4 = 0;
  if (0 < unaff_EBP) {
    piVar8 = (int *)(rem + 8);
    do {
      rge_read(param_1,&scenario_player_num,4);
      iVar10 = 0;
      if (0 < scenario_player_num) {
        do {
          rge_read(param_1,&world_z,4);
          rge_read(param_1,&master_id,4);
          rge_read(param_1,&obj_state,4);
          rge_read(param_1,&header_size,4);
          rge_read(param_1,&obj_angle,2);
          rge_read(param_1,&id,1);
          rge_read(param_1,&count,4);
          iVar7 = *piVar8;
          if ((-1 < iVar7) && (this->players[iVar7] != (RGE_Player *)0x0)) {
            this->scenario_object_flag = '\x01';
            this->scenario_object_id = header_size;
            (**(code **)(this->players[iVar7]->_padding_ + 0x60))
                      (world_z,_master_id,_obj_state,obj_angle,id,count);
            this->scenario_object_flag = '\0';
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < scenario_player_num);
      }
      iStack_4 = iStack_4 + 1;
      piVar8 = piVar8 + 1;
    } while (iStack_4 < unaff_EBP);
  }
  this->next_object_id = (long)world_y;
  rge_read(param_1,&world_x,0xd);
  iVar10 = 1;
  if (1 < unaff_EBP) {
    piVar8 = (int *)(rem + 0xc);
    do {
      if (((this->player_num <= iVar10) || (*piVar8 < 0)) ||
         (pRVar9 = this->players[*piVar8], pRVar9 == (RGE_Player *)0x0)) {
        pRVar9 = *this->players;
      }
      (**(code **)(pRVar9->_padding_ + 0x68))(param_1,rem + 8,0x3f851eb8);
      iVar10 = iVar10 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar10 < unaff_EBP);
  }
  rge_close(param_1);
  iVar10 = 1;
  if (1 < this->player_num) {
    do {
      if (unaff_EBP <= iVar10) {
        return;
      }
      if ((this->players[iVar10] != (RGE_Player *)0x0) && (-1 < *(int *)(rem + iVar10 * 4 + 8))) {
        iVar7 = iVar10 + -1;
        uVar11 = 0xffffffff;
        iVar1 = this->players[*(int *)(rem + iVar10 * 4 + 8)]->_padding_;
        iVar3 = RGE_Scenario::GetPlayerPosture(this->scenario,iVar7);
        pcVar4 = RGE_Scenario::Get_player_AI(this->scenario,iVar7,1);
        pcVar5 = RGE_Scenario::Get_CityPlan(this->scenario,iVar7,1);
        pcVar6 = RGE_Scenario::Get_BuildList(this->scenario,iVar7,1);
        (**(code **)(iVar1 + 0x2c))(pcVar6,pcVar5,pcVar4,iVar3,uVar11);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: load_scenario4
// Address: 00544b90
/* WARNING: Variable defined which should be unmapped: header_size */
/* protected: virtual void __thiscall RGE_Game_World::load_scenario4(int,struct RGE_Player_Info &)
    */

void __thiscall
RGE_Game_World::load_scenario4(RGE_Game_World *this,int param_1,RGE_Player_Info *param_2)
{
  int iVar1;
  void *pvVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  RGE_Player *pRVar10;
  int iVar11;
  long unaff_EBX;
  int unaff_EBP;
  float *pfVar12;
  undefined4 uVar13;
  long header_size;
  long count;
  long id;
  float obj_angle;
  uchar obj_state;
  short master_id;
  float world_z;
  float world_y;
  float world_x;
  long obj_id;
  long player_id_hash [9];
  int iStack_4;
  
  world_update_counter = 0;
  header_size = unaff_EBX;
  rge_read_uncompressed(param_1,&count,4);
  if (0 < count) {
    pvVar2 = (void *)malloc(count);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_1);
      return;
    }
    rge_read_uncompressed(param_1,pvVar2,count);
    free(pvVar2);
  }
  rge_read(param_1,player_id_hash,4);
  iVar11 = this->_padding_;
  (**(code **)(iVar11 + 0xf4))(param_1,this);
  (**(code **)(iVar11 + 0x70))(param_1);
  iVar11 = (int)this->player_num;
  if (0 < iVar11) {
    do {
      pfVar12 = &world_x;
      for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
        *pfVar12 = -NAN;
        pfVar12 = pfVar12 + 1;
      }
    } while (10 < iVar11);
  }
  fVar3 = 0.0;
  if (0 < iVar11) {
    piVar9 = (int *)(iStack_4 + 0x270);
    do {
      iVar8 = *piVar9;
      piVar9 = piVar9 + 1;
      (&world_x)[iVar8] = fVar3;
      fVar3 = (float)((int)fVar3 + 1);
    } while ((int)fVar3 < iVar11);
  }
  iVar8 = 0;
  if (0 < iVar11) {
    do {
      RGE_Player::remake_visible_map(this->players[iVar8]);
      iVar8 = iVar8 + 1;
    } while (iVar8 < this->player_num);
  }
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x68))(param_1,&world_x,0x3f851eb8);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  iStack_4 = 0;
  if (0 < player_id_hash[8]) {
    pfVar12 = &world_x;
    do {
      rge_read(param_1,&stack0xffffffac,4);
      iVar11 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_1,&world_z,4);
          rge_read(param_1,&master_id,4);
          rge_read(param_1,&obj_state,4);
          rge_read(param_1,&header_size,4);
          rge_read(param_1,&obj_angle,2);
          rge_read(param_1,&id,1);
          rge_read(param_1,&count,4);
          fVar3 = *pfVar12;
          if ((-1 < (int)fVar3) && (this->players[(int)fVar3] != (RGE_Player *)0x0)) {
            this->scenario_object_flag = '\x01';
            this->scenario_object_id = header_size;
            (**(code **)(this->players[(int)fVar3]->_padding_ + 0x60))
                      (world_z,_master_id,_obj_state,obj_angle,id,count);
            this->scenario_object_flag = '\0';
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      pfVar12 = pfVar12 + 1;
    } while (iStack_4 < player_id_hash[8]);
  }
  this->next_object_id = (long)world_y;
  rge_close(param_1);
  iVar11 = 1;
  if (1 < this->player_num) {
    do {
      if (player_id_hash[8] <= iVar11) {
        return;
      }
      if ((this->players[iVar11] != (RGE_Player *)0x0) && (-1 < (int)(&world_x)[iVar11])) {
        iVar8 = iVar11 + -1;
        uVar13 = 0xffffffff;
        iVar1 = this->players[(int)(&world_x)[iVar11]]->_padding_;
        iVar4 = RGE_Scenario::GetPlayerPosture(this->scenario,iVar8);
        pcVar5 = RGE_Scenario::Get_player_AI(this->scenario,iVar8,1);
        pcVar6 = RGE_Scenario::Get_CityPlan(this->scenario,iVar8,1);
        pcVar7 = RGE_Scenario::Get_BuildList(this->scenario,iVar8,1);
        (**(code **)(iVar1 + 0x2c))(pcVar7,pcVar6,pcVar5,iVar4,uVar13);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: load_scenario5
// Address: 00544e70
/* WARNING: Variable defined which should be unmapped: header_size */
/* protected: virtual void __thiscall RGE_Game_World::load_scenario5(int,struct RGE_Player_Info &)
    */

void __thiscall
RGE_Game_World::load_scenario5(RGE_Game_World *this,int param_1,RGE_Player_Info *param_2)
{
  int iVar1;
  void *pvVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  RGE_Player *pRVar10;
  int iVar11;
  long unaff_EBX;
  int unaff_EBP;
  float *pfVar12;
  undefined4 uVar13;
  long header_size;
  long count;
  long id;
  float obj_angle;
  uchar obj_state;
  short master_id;
  float world_z;
  float world_y;
  float world_x;
  long obj_id;
  long player_id_hash [9];
  int iStack_4;
  
  world_update_counter = 0;
  header_size = unaff_EBX;
  rge_read_uncompressed(param_1,&count,4);
  if (0 < count) {
    pvVar2 = (void *)malloc(count);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_1);
      return;
    }
    rge_read_uncompressed(param_1,pvVar2,count);
    free(pvVar2);
  }
  rge_read(param_1,player_id_hash,4);
  iVar11 = this->_padding_;
  (**(code **)(iVar11 + 0xf4))(param_1,this);
  (**(code **)(iVar11 + 0x70))(param_1);
  iVar11 = (int)this->player_num;
  if (0 < iVar11) {
    do {
      pfVar12 = &world_x;
      for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
        *pfVar12 = -NAN;
        pfVar12 = pfVar12 + 1;
      }
    } while (10 < iVar11);
  }
  fVar3 = 0.0;
  if (0 < iVar11) {
    piVar9 = (int *)(iStack_4 + 0x270);
    do {
      iVar8 = *piVar9;
      piVar9 = piVar9 + 1;
      (&world_x)[iVar8] = fVar3;
      fVar3 = (float)((int)fVar3 + 1);
    } while ((int)fVar3 < iVar11);
  }
  iVar8 = 0;
  if (0 < iVar11) {
    do {
      RGE_Player::remake_visible_map(this->players[iVar8]);
      iVar8 = iVar8 + 1;
    } while (iVar8 < this->player_num);
  }
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x68))(param_1,&world_x,0x3f87ae14);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  iStack_4 = 0;
  if (0 < player_id_hash[8]) {
    pfVar12 = &world_x;
    do {
      rge_read(param_1,&stack0xffffffac,4);
      iVar11 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_1,&world_z,4);
          rge_read(param_1,&master_id,4);
          rge_read(param_1,&obj_state,4);
          rge_read(param_1,&header_size,4);
          rge_read(param_1,&obj_angle,2);
          rge_read(param_1,&id,1);
          rge_read(param_1,&count,4);
          fVar3 = *pfVar12;
          if ((-1 < (int)fVar3) && (this->players[(int)fVar3] != (RGE_Player *)0x0)) {
            this->scenario_object_flag = '\x01';
            this->scenario_object_id = header_size;
            (**(code **)(this->players[(int)fVar3]->_padding_ + 0x60))
                      (world_z,_master_id,_obj_state,obj_angle,id,count);
            this->scenario_object_flag = '\0';
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      pfVar12 = pfVar12 + 1;
    } while (iStack_4 < player_id_hash[8]);
  }
  this->next_object_id = (long)world_y;
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x70))(param_1,&world_x,0x3f87ae14);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  rge_close(param_1);
  iVar11 = 1;
  if (1 < this->player_num) {
    do {
      if (player_id_hash[8] <= iVar11) {
        return;
      }
      if ((this->players[iVar11] != (RGE_Player *)0x0) && (-1 < (int)(&world_x)[iVar11])) {
        iVar8 = iVar11 + -1;
        uVar13 = 0xffffffff;
        iVar1 = this->players[(int)(&world_x)[iVar11]]->_padding_;
        iVar4 = RGE_Scenario::GetPlayerPosture(this->scenario,iVar8);
        pcVar5 = RGE_Scenario::Get_player_AI(this->scenario,iVar8,1);
        pcVar6 = RGE_Scenario::Get_CityPlan(this->scenario,iVar8,1);
        pcVar7 = RGE_Scenario::Get_BuildList(this->scenario,iVar8,1);
        (**(code **)(iVar1 + 0x2c))(pcVar7,pcVar6,pcVar5,iVar4,uVar13);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: load_scenario6
// Address: 005451a0
/* WARNING: Variable defined which should be unmapped: header_size */
/* protected: virtual void __thiscall RGE_Game_World::load_scenario6(int,struct RGE_Player_Info &)
    */

void __thiscall
RGE_Game_World::load_scenario6(RGE_Game_World *this,int param_1,RGE_Player_Info *param_2)
{
  int iVar1;
  void *pvVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  RGE_Player *pRVar10;
  int iVar11;
  long unaff_EBX;
  int unaff_EBP;
  float *pfVar12;
  undefined4 uVar13;
  long header_size;
  long count;
  long id;
  float obj_angle;
  uchar obj_state;
  short master_id;
  float world_z;
  float world_y;
  float world_x;
  long obj_id;
  long player_id_hash [9];
  int iStack_4;
  
  world_update_counter = 0;
  header_size = unaff_EBX;
  rge_read_uncompressed(param_1,&count,4);
  if (0 < count) {
    pvVar2 = (void *)malloc(count);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_1);
      return;
    }
    rge_read_uncompressed(param_1,pvVar2,count);
    free(pvVar2);
  }
  rge_read(param_1,player_id_hash,4);
  iVar11 = this->_padding_;
  (**(code **)(iVar11 + 0xf4))(param_1,this);
  (**(code **)(iVar11 + 0x70))(param_1);
  iVar11 = (int)this->player_num;
  if (0 < iVar11) {
    do {
      pfVar12 = &world_x;
      for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
        *pfVar12 = -NAN;
        pfVar12 = pfVar12 + 1;
      }
    } while (10 < iVar11);
  }
  fVar3 = 0.0;
  if (0 < iVar11) {
    piVar9 = (int *)(iStack_4 + 0x270);
    do {
      iVar8 = *piVar9;
      piVar9 = piVar9 + 1;
      (&world_x)[iVar8] = fVar3;
      fVar3 = (float)((int)fVar3 + 1);
    } while ((int)fVar3 < iVar11);
  }
  iVar8 = 0;
  if (0 < iVar11) {
    do {
      RGE_Player::remake_visible_map(this->players[iVar8]);
      iVar8 = iVar8 + 1;
    } while (iVar8 < this->player_num);
  }
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x68))(param_1,&world_x,0x3f88f5c3);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  iStack_4 = 0;
  if (0 < player_id_hash[8]) {
    pfVar12 = &world_x;
    do {
      rge_read(param_1,&stack0xffffffac,4);
      iVar11 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_1,&world_z,4);
          rge_read(param_1,&master_id,4);
          rge_read(param_1,&obj_state,4);
          rge_read(param_1,&header_size,4);
          rge_read(param_1,&obj_angle,2);
          rge_read(param_1,&id,1);
          rge_read(param_1,&count,4);
          fVar3 = *pfVar12;
          if ((-1 < (int)fVar3) && (this->players[(int)fVar3] != (RGE_Player *)0x0)) {
            this->scenario_object_flag = '\x01';
            this->scenario_object_id = header_size;
            (**(code **)(this->players[(int)fVar3]->_padding_ + 0x60))
                      (world_z,_master_id,_obj_state,obj_angle,id,count);
            this->scenario_object_flag = '\0';
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      pfVar12 = pfVar12 + 1;
    } while (iStack_4 < player_id_hash[8]);
  }
  this->next_object_id = (long)world_y;
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x70))(param_1,&world_x,0x3f88f5c3);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  rge_close(param_1);
  iVar11 = 1;
  if (1 < this->player_num) {
    do {
      if (player_id_hash[8] <= iVar11) {
        return;
      }
      if ((this->players[iVar11] != (RGE_Player *)0x0) && (-1 < (int)(&world_x)[iVar11])) {
        iVar8 = iVar11 + -1;
        uVar13 = 0xffffffff;
        iVar1 = this->players[(int)(&world_x)[iVar11]]->_padding_;
        iVar4 = RGE_Scenario::GetPlayerPosture(this->scenario,iVar8);
        pcVar5 = RGE_Scenario::Get_player_AI(this->scenario,iVar8,1);
        pcVar6 = RGE_Scenario::Get_CityPlan(this->scenario,iVar8,1);
        pcVar7 = RGE_Scenario::Get_BuildList(this->scenario,iVar8,1);
        (**(code **)(iVar1 + 0x2c))(pcVar7,pcVar6,pcVar5,iVar4,uVar13);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: load_scenario7
// Address: 005454d0
/* WARNING: Variable defined which should be unmapped: header_size */
/* protected: virtual void __thiscall RGE_Game_World::load_scenario7(int,struct RGE_Player_Info &)
    */

void __thiscall
RGE_Game_World::load_scenario7(RGE_Game_World *this,int param_1,RGE_Player_Info *param_2)
{
  int iVar1;
  void *pvVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  RGE_Player *pRVar10;
  int iVar11;
  long unaff_EBX;
  int unaff_EBP;
  float *pfVar12;
  undefined4 uVar13;
  long header_size;
  long count;
  long id;
  float obj_angle;
  uchar obj_state;
  short master_id;
  float world_z;
  float world_y;
  float world_x;
  long obj_id;
  long player_id_hash [9];
  int iStack_4;
  
  world_update_counter = 0;
  header_size = unaff_EBX;
  rge_read_uncompressed(param_1,&count,4);
  if (0 < count) {
    pvVar2 = (void *)malloc(count);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_1);
      return;
    }
    rge_read_uncompressed(param_1,pvVar2,count);
    free(pvVar2);
  }
  rge_read(param_1,player_id_hash,4);
  iVar11 = this->_padding_;
  (**(code **)(iVar11 + 0xf4))(param_1,this);
  (**(code **)(iVar11 + 0x70))(param_1);
  iVar11 = (int)this->player_num;
  if (0 < iVar11) {
    do {
      pfVar12 = &world_x;
      for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
        *pfVar12 = -NAN;
        pfVar12 = pfVar12 + 1;
      }
    } while (10 < iVar11);
  }
  fVar3 = 0.0;
  if (0 < iVar11) {
    piVar9 = (int *)(iStack_4 + 0x270);
    do {
      iVar8 = *piVar9;
      piVar9 = piVar9 + 1;
      (&world_x)[iVar8] = fVar3;
      fVar3 = (float)((int)fVar3 + 1);
    } while ((int)fVar3 < iVar11);
  }
  iVar8 = 0;
  if (0 < iVar11) {
    do {
      RGE_Player::remake_visible_map(this->players[iVar8]);
      iVar8 = iVar8 + 1;
    } while (iVar8 < this->player_num);
  }
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x68))(param_1,&world_x,0x3f8a3d71);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  iStack_4 = 0;
  if (0 < player_id_hash[8]) {
    pfVar12 = &world_x;
    do {
      rge_read(param_1,&stack0xffffffac,4);
      iVar11 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_1,&world_z,4);
          rge_read(param_1,&master_id,4);
          rge_read(param_1,&obj_state,4);
          rge_read(param_1,&header_size,4);
          rge_read(param_1,&obj_angle,2);
          rge_read(param_1,&id,1);
          rge_read(param_1,&count,4);
          fVar3 = *pfVar12;
          if ((-1 < (int)fVar3) && (this->players[(int)fVar3] != (RGE_Player *)0x0)) {
            this->scenario_object_flag = '\x01';
            this->scenario_object_id = header_size;
            (**(code **)(this->players[(int)fVar3]->_padding_ + 0x60))
                      (world_z,_master_id,_obj_state,obj_angle,id,count);
            this->scenario_object_flag = '\0';
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      pfVar12 = pfVar12 + 1;
    } while (iStack_4 < player_id_hash[8]);
  }
  this->next_object_id = (long)world_y;
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x70))(param_1,&world_x,0x3f8a3d71);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  rge_close(param_1);
  iVar11 = 1;
  if (1 < this->player_num) {
    do {
      if (player_id_hash[8] <= iVar11) {
        return;
      }
      if ((this->players[iVar11] != (RGE_Player *)0x0) && (-1 < (int)(&world_x)[iVar11])) {
        iVar8 = iVar11 + -1;
        uVar13 = 0xffffffff;
        iVar1 = this->players[(int)(&world_x)[iVar11]]->_padding_;
        iVar4 = RGE_Scenario::GetPlayerPosture(this->scenario,iVar8);
        pcVar5 = RGE_Scenario::Get_player_AI(this->scenario,iVar8,1);
        pcVar6 = RGE_Scenario::Get_CityPlan(this->scenario,iVar8,1);
        pcVar7 = RGE_Scenario::Get_BuildList(this->scenario,iVar8,1);
        (**(code **)(iVar1 + 0x2c))(pcVar7,pcVar6,pcVar5,iVar4,uVar13);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: load_scenario8
// Address: 00545800
/* WARNING: Variable defined which should be unmapped: header_size */
/* protected: virtual void __thiscall RGE_Game_World::load_scenario8(int,struct RGE_Player_Info &)
    */

void __thiscall
RGE_Game_World::load_scenario8(RGE_Game_World *this,int param_1,RGE_Player_Info *param_2)
{
  int iVar1;
  void *pvVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  RGE_Player *pRVar10;
  int iVar11;
  long unaff_EBX;
  int unaff_EBP;
  float *pfVar12;
  undefined4 uVar13;
  long header_size;
  long count;
  long id;
  float obj_angle;
  uchar obj_state;
  short master_id;
  float world_z;
  float world_y;
  float world_x;
  long obj_id;
  long player_id_hash [9];
  int iStack_4;
  
  world_update_counter = 0;
  header_size = unaff_EBX;
  rge_read_uncompressed(param_1,&count,4);
  if (0 < count) {
    pvVar2 = (void *)malloc(count);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_1);
      return;
    }
    rge_read_uncompressed(param_1,pvVar2,count);
    free(pvVar2);
  }
  rge_read(param_1,player_id_hash,4);
  iVar11 = this->_padding_;
  (**(code **)(iVar11 + 0xf4))(param_1,this);
  (**(code **)(iVar11 + 0x70))(param_1);
  iVar11 = (int)this->player_num;
  if (0 < iVar11) {
    do {
      pfVar12 = &world_x;
      for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
        *pfVar12 = -NAN;
        pfVar12 = pfVar12 + 1;
      }
    } while (10 < iVar11);
  }
  fVar3 = 0.0;
  if (0 < iVar11) {
    piVar9 = (int *)(iStack_4 + 0x270);
    do {
      iVar8 = *piVar9;
      piVar9 = piVar9 + 1;
      (&world_x)[iVar8] = fVar3;
      fVar3 = (float)((int)fVar3 + 1);
    } while ((int)fVar3 < iVar11);
  }
  iVar8 = 0;
  if (0 < iVar11) {
    do {
      RGE_Player::remake_visible_map(this->players[iVar8]);
      iVar8 = iVar8 + 1;
    } while (iVar8 < this->player_num);
  }
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x68))(param_1,&world_x,0x3f8e147b);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  iStack_4 = 0;
  if (0 < player_id_hash[8]) {
    pfVar12 = &world_x;
    do {
      rge_read(param_1,&stack0xffffffac,4);
      iVar11 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_1,&world_z,4);
          rge_read(param_1,&master_id,4);
          rge_read(param_1,&obj_state,4);
          rge_read(param_1,&header_size,4);
          rge_read(param_1,&obj_angle,2);
          rge_read(param_1,&id,1);
          rge_read(param_1,&count,4);
          fVar3 = *pfVar12;
          if ((-1 < (int)fVar3) && (this->players[(int)fVar3] != (RGE_Player *)0x0)) {
            this->scenario_object_flag = '\x01';
            this->scenario_object_id = header_size;
            (**(code **)(this->players[(int)fVar3]->_padding_ + 0x60))
                      (world_z,_master_id,_obj_state,obj_angle,id,count);
            this->scenario_object_flag = '\0';
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      pfVar12 = pfVar12 + 1;
    } while (iStack_4 < player_id_hash[8]);
  }
  this->next_object_id = (long)world_y;
  rge_read(param_1,player_id_hash + 8,4);
  iVar11 = 1;
  if (1 < player_id_hash[8]) {
    piVar9 = &obj_id;
    do {
      if (((this->player_num <= iVar11) || (*piVar9 < 0)) ||
         (pRVar10 = this->players[*piVar9], pRVar10 == (RGE_Player *)0x0)) {
        pRVar10 = *this->players;
      }
      (**(code **)(pRVar10->_padding_ + 0x70))(param_1,&world_x,0x3f8e147b);
      iVar11 = iVar11 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar11 < player_id_hash[8]);
  }
  rge_close(param_1);
  iVar11 = 1;
  if (1 < this->player_num) {
    do {
      if (player_id_hash[8] <= iVar11) {
        return;
      }
      if ((this->players[iVar11] != (RGE_Player *)0x0) && (-1 < (int)(&world_x)[iVar11])) {
        iVar8 = iVar11 + -1;
        uVar13 = 0xffffffff;
        iVar1 = this->players[(int)(&world_x)[iVar11]]->_padding_;
        iVar4 = RGE_Scenario::GetPlayerPosture(this->scenario,iVar8);
        pcVar5 = RGE_Scenario::Get_player_AI(this->scenario,iVar8,1);
        pcVar6 = RGE_Scenario::Get_CityPlan(this->scenario,iVar8,1);
        pcVar7 = RGE_Scenario::Get_BuildList(this->scenario,iVar8,1);
        (**(code **)(iVar1 + 0x2c))(pcVar7,pcVar6,pcVar5,iVar4,uVar13);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < this->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: selectNextComputerPlayer
// Address: 00545b30
/* public: void __thiscall RGE_Game_World::selectNextComputerPlayer(int) */

void __thiscall RGE_Game_World::selectNextComputerPlayer(RGE_Game_World *this,int param_1)
{
  int iVar1;
  RGE_Player **ppRVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = this->currentUpdateComputerPlayer;
  if (iVar1 == -1) {
    iVar1 = 0;
    if (0 < this->player_num) {
      ppRVar2 = this->players;
      do {
        if ((uint)(*ppRVar2)->type == param_1) {
          this->currentUpdateComputerPlayer = iVar1;
          return;
        }
        iVar1 = iVar1 + 1;
        ppRVar2 = ppRVar2 + 1;
      } while (iVar1 < this->player_num);
      return;
    }
  }
  else {
    iVar4 = (int)this->player_num;
    iVar5 = 0;
    iVar3 = iVar1;
    if (iVar1 < iVar4) {
      while (iVar5 < iVar4) {
        if (((uint)this->players[iVar3]->type == param_1) && (iVar3 != iVar1)) {
          this->currentUpdateComputerPlayer = iVar3;
          return;
        }
        iVar3 = (iVar3 + 1) % iVar4;
        iVar5 = iVar5 + 1;
        if (iVar4 <= iVar3) {
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: useComputerPlayerUpdateTime
// Address: 00545bc0
/* public: void __thiscall RGE_Game_World::useComputerPlayerUpdateTime(unsigned long) */

void __thiscall RGE_Game_World::useComputerPlayerUpdateTime(RGE_Game_World *this,ulong param_1)
{
  if (this->availableComputerPlayerUpdateTime < param_1) {
    this->availableComputerPlayerUpdateTime = 0;
    return;
  }
  this->availableComputerPlayerUpdateTime = this->availableComputerPlayerUpdateTime - param_1;
  return;
}

// --------------------------------------------------

// Function: computerPlayerUpdateTimeAvailable
// Address: 00545bf0
/* public: int __thiscall RGE_Game_World::computerPlayerUpdateTimeAvailable(void) */

int __thiscall RGE_Game_World::computerPlayerUpdateTimeAvailable(RGE_Game_World *this)
{
  return (uint)(this->availableComputerPlayerUpdateTime != 0);
}

// --------------------------------------------------

// Function: objectGroupOnTile
// Address: 00545c00
/* public: int __thiscall RGE_Game_World::objectGroupOnTile(int,int,int,int,int &) */

int __thiscall
RGE_Game_World::objectGroupOnTile
          (RGE_Game_World *this,int param_1,int param_2,int param_3,int param_4,int *param_5)
{
  RGE_Map *pRVar1;
  RGE_Static_Object *pRVar2;
  RGE_Object_Node *pRVar3;
  
  if ((((param_3 < 0) || (param_4 < 0)) || (pRVar1 = this->map, pRVar1->map_width <= param_3)) ||
     (pRVar1->map_height <= param_4)) {
    *param_5 = 0;
  }
  else {
    *param_5 = (int)pRVar1->map_row_offset[param_4][param_3].objects.number_of_objects;
    pRVar3 = this->map->map_row_offset[param_4][param_3].objects.list;
    if (pRVar3 != (RGE_Object_Node *)0x0) {
      while (pRVar2 = pRVar3->node, pRVar2 != (RGE_Static_Object *)0x0) {
        if (((param_1 == -1) || (pRVar2->owner->id == param_1)) &&
           (pRVar2->master_obj->object_group == param_2)) {
          return pRVar2->id;
        }
        pRVar3 = pRVar3->next;
        if (pRVar3 == (RGE_Object_Node *)0x0) {
          return -1;
        }
      }
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: difficultyLevel
// Address: 00545cb0
/* public: int __thiscall RGE_Game_World::difficultyLevel(void) */

int __thiscall RGE_Game_World::difficultyLevel(RGE_Game_World *this)
{
  int iVar1;
  
  if (this->difficultyLevelValue == -1) {
    iVar1 = RGE_Base_Game::difficulty(rge_base_game);
    this->difficultyLevelValue = iVar1;
  }
  return this->difficultyLevelValue;
}

// --------------------------------------------------

// Function: get_scenario_info
// Address: 00545ce0
/* public: virtual class RGE_Scenario * __thiscall RGE_Game_World::get_scenario_info(char *) */

RGE_Scenario * __thiscall RGE_Game_World::get_scenario_info(RGE_Game_World *this,char *param_1)
{
  return (RGE_Scenario *)0x0;
}

// --------------------------------------------------

// Function: maxNumberObjects
// Address: 00545cf0
/* public: int __thiscall RGE_Game_World::maxNumberObjects(void) */

int __thiscall RGE_Game_World::maxNumberObjects(RGE_Game_World *this)
{
  return this->maxNumberObjectsValue;
}

// --------------------------------------------------

// Function: maxNumberNegativeObjects
// Address: 00545d00
/* public: int __thiscall RGE_Game_World::maxNumberNegativeObjects(void) */

int __thiscall RGE_Game_World::maxNumberNegativeObjects(RGE_Game_World *this)
{
  return this->maxNumberNegativeObjectsValue;
}

// --------------------------------------------------

// Function: numberObjects
// Address: 00545d10
/* public: int __thiscall RGE_Game_World::numberObjects(void) */

int __thiscall RGE_Game_World::numberObjects(RGE_Game_World *this)
{
  return this->numberObjectsValue;
}

// --------------------------------------------------

// Function: numberNegativeObjects
// Address: 00545d20
/* public: int __thiscall RGE_Game_World::numberNegativeObjects(void) */

int __thiscall RGE_Game_World::numberNegativeObjects(RGE_Game_World *this)
{
  return this->numberNegativeObjectsValue;
}

// --------------------------------------------------

// Function: object
// Address: 00545d30
/* public: class RGE_Static_Object * __thiscall RGE_Game_World::object(int) */

RGE_Static_Object * __thiscall RGE_Game_World::object(RGE_Game_World *this,int param_1)
{
  if ((param_1 < 0) && (-param_1 < this->maxNumberNegativeObjectsValue)) {
    return this->negativeObjectsValue[-param_1];
  }
  if ((-1 < param_1) && (param_1 < this->maxNumberObjectsValue)) {
    return this->objectsValue[param_1];
  }
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: object_ptr
// Address: 00545d80
/* public: class RGE_Static_Object * __thiscall RGE_Game_World::object_ptr(int) */

RGE_Static_Object * __thiscall RGE_Game_World::object_ptr(RGE_Game_World *this,int param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = object(this,param_1);
  return pRVar1;
}

// --------------------------------------------------

// Function: get_next_object_id
// Address: 00545d90
/* public: long __thiscall RGE_Game_World::get_next_object_id(void) */

long __thiscall RGE_Game_World::get_next_object_id(RGE_Game_World *this)
{
  int iVar1;
  int iVar2;
  
  if (this->scenario_object_flag != '\0') {
    return this->scenario_object_id;
  }
  iVar1 = this->maxNumberObjectsValue + -1;
  if (this->next_object_id <= iVar1) {
    do {
      if (this->objectsValue[this->next_object_id] == (RGE_Static_Object *)0x0) break;
      iVar2 = this->next_object_id + 1;
      this->next_object_id = iVar2;
    } while (iVar2 <= iVar1);
  }
  iVar1 = this->next_object_id;
  this->next_object_id = iVar1 + 1;
  return iVar1;
}

// --------------------------------------------------

// Function: get_next_reusable_object_id
// Address: 00545dd0
/* public: long __thiscall RGE_Game_World::get_next_reusable_object_id(void) */

long __thiscall RGE_Game_World::get_next_reusable_object_id(RGE_Game_World *this)
{
  int iVar1;
  
  if (this->scenario_object_flag == '\0') {
    iVar1 = this->next_reusable_object_id;
    this->next_reusable_object_id = iVar1 + -1;
  }
  else {
    iVar1 = this->scenario_object_id;
    if (iVar1 < this->next_reusable_object_id) {
      this->next_reusable_object_id = iVar1 + -1;
      return iVar1;
    }
  }
  return iVar1;
}

// --------------------------------------------------

// Function: addObject
// Address: 00545e00
/* WARNING: Variable defined which should be unmapped: lookupSlot */
/* public: virtual int __thiscall RGE_Game_World::addObject(class RGE_Static_Object *) */

int __thiscall RGE_Game_World::addObject(RGE_Game_World *this,RGE_Static_Object *param_1)
{
  RGE_Static_Object *this_00;
  int iVar1;
  RGE_Static_Object **ppRVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  RGE_Static_Object **ppRVar6;
  int lookupSlot;
  
  iVar5 = param_1->id;
  if (iVar5 < 0) {
    iVar1 = this->maxNumberNegativeObjectsValue + -1;
    if (SBORROW4(iVar1,-iVar5) != iVar1 + iVar5 < 0) {
      iVar1 = this->maxNumberNegativeObjectsValue * 2;
      if (SBORROW4(iVar1,-iVar5) != iVar1 + iVar5 < 0) {
        iVar1 = __ftol();
      }
      ppRVar2 = (RGE_Static_Object **)operator_new(iVar1 * 4);
      if (ppRVar2 == (RGE_Static_Object **)0x0) {
        return 0;
      }
      iVar4 = 0;
      iVar3 = iVar4;
      if (0 < this->maxNumberNegativeObjectsValue) {
        do {
          iVar4 = iVar3 + 1;
          ppRVar2[iVar3] = this->negativeObjectsValue[iVar3];
          iVar3 = iVar4;
        } while (iVar4 < this->maxNumberNegativeObjectsValue);
      }
      if (iVar4 < iVar1) {
        ppRVar6 = ppRVar2 + iVar4;
        for (iVar3 = iVar1 - iVar4; iVar3 != 0; iVar3 = iVar3 + -1) {
          *ppRVar6 = (RGE_Static_Object *)0x0;
          ppRVar6 = ppRVar6 + 1;
        }
      }
      operator_delete(this->negativeObjectsValue);
      this->negativeObjectsValue = ppRVar2;
      this->maxNumberNegativeObjectsValue = iVar1;
    }
    this->negativeObjectsValue[-iVar5] = param_1;
    this->numberNegativeObjectsValue = this->numberNegativeObjectsValue + 1;
  }
  else {
    if (this->maxNumberObjectsValue + -1 < iVar5) {
      iVar1 = this->maxNumberObjectsValue * 2;
      if (iVar1 < iVar5) {
        iVar1 = __ftol();
      }
      ppRVar2 = (RGE_Static_Object **)operator_new(iVar1 * 4);
      if (ppRVar2 == (RGE_Static_Object **)0x0) {
        return 0;
      }
      iVar3 = 0;
      iVar5 = iVar3;
      if (0 < this->maxNumberObjectsValue) {
        do {
          iVar3 = iVar5 + 1;
          ppRVar2[iVar5] = this->objectsValue[iVar5];
          iVar5 = iVar3;
        } while (iVar3 < this->maxNumberObjectsValue);
      }
      if (iVar3 < iVar1) {
        ppRVar6 = ppRVar2 + iVar3;
        for (iVar5 = iVar1 - iVar3; iVar5 != 0; iVar5 = iVar5 + -1) {
          *ppRVar6 = (RGE_Static_Object *)0x0;
          ppRVar6 = ppRVar6 + 1;
        }
      }
      operator_delete(this->objectsValue);
      this->objectsValue = ppRVar2;
      VIS_UNIT_objectsValue = ppRVar2;
      this->maxNumberObjectsValue = iVar1;
    }
    this_00 = this->objectsValue[param_1->id];
    this->objectsValue[param_1->id] = param_1;
    this->numberObjectsValue = this->numberObjectsValue + 1;
    if ((this_00 != (RGE_Static_Object *)0x0) && (this->scenario_object_flag != '\0')) {
      this->scenario_object_flag = '\0';
      RGE_Static_Object::change_unique_id(this_00);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: removeObject
// Address: 00545fd0
/* public: virtual int __thiscall RGE_Game_World::removeObject(int) */

int __thiscall RGE_Game_World::removeObject(RGE_Game_World *this,int param_1)
{
  if ((param_1 < 0) && (-param_1 < this->maxNumberNegativeObjectsValue)) {
    this->negativeObjectsValue[-param_1] = (RGE_Static_Object *)0x0;
    return 1;
  }
  if ((-1 < param_1) && (param_1 < this->maxNumberObjectsValue)) {
    this->objectsValue[param_1] = (RGE_Static_Object *)0x0;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: initializePathingSystem
// Address: 00546030
/* public: int __thiscall RGE_Game_World::initializePathingSystem(void) */

int __thiscall RGE_Game_World::initializePathingSystem(RGE_Game_World *this)
{
  RGE_Map *pRVar1;
  
  pRVar1 = this->map;
  if (pRVar1 == (RGE_Map *)0x0) {
    return (int)pRVar1;
  }
  PathingSystem::initialize(&pathSystem,pRVar1->map_width,pRVar1->map_height,pRVar1,this);
  pRVar1 = this->map;
  PathingSystem::initialize(&aiPathSystem,pRVar1->map_width,pRVar1->map_height,pRVar1,this);
  return 1;
}

// --------------------------------------------------

// Function: recycle_object_out_of_game
// Address: 00546070
/* public: unsigned char __thiscall RGE_Game_World::recycle_object_out_of_game(unsigned char,class
   RGE_Static_Object *) */

uchar __thiscall
RGE_Game_World::recycle_object_out_of_game
          (RGE_Game_World *this,uchar param_1,RGE_Static_Object *param_2)
{
  switch(param_1) {
  case '\n':
    RGE_Object_List::add_node(this->reusable_static_objects,param_2);
    return '\x01';
  default:
    return '\0';
  case '\x14':
    RGE_Object_List::add_node(this->reusable_animated_objects,param_2);
    return '\x01';
  case '\x19':
    RGE_Object_List::add_node(this->reusable_doppleganger_objects,param_2);
    return '\x01';
  case '\x1e':
    RGE_Object_List::add_node(this->reusable_moving_objects,param_2);
    return '\x01';
  case '(':
    RGE_Object_List::add_node(this->reusable_action_objects,param_2);
    return '\x01';
  case '2':
    RGE_Object_List::add_node(this->reusable_combat_objects,param_2);
    return '\x01';
  case '<':
    RGE_Object_List::add_node(this->reusable_missile_objects,param_2);
    return '\x01';
  }
}

// --------------------------------------------------

// Function: recycle_object_in_to_game
// Address: 00546180
/* public: class RGE_Static_Object * __thiscall RGE_Game_World::recycle_object_in_to_game(unsigned
   char) */

RGE_Static_Object * __thiscall
RGE_Game_World::recycle_object_in_to_game(RGE_Game_World *this,uchar param_1)
{
  RGE_Object_Node *pRVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = (RGE_Static_Object *)0x0;
  switch(param_1) {
  case '\n':
    pRVar1 = this->reusable_static_objects->list;
    if (pRVar1 != (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      RGE_Object_List::remove_node(this->reusable_static_objects,pRVar2,(RGE_Object_Node *)0x0);
      return pRVar2;
    }
    break;
  case '\x14':
    pRVar1 = this->reusable_animated_objects->list;
    if (pRVar1 != (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      RGE_Object_List::remove_node(this->reusable_animated_objects,pRVar2,(RGE_Object_Node *)0x0);
      return pRVar2;
    }
    break;
  case '\x19':
    pRVar1 = this->reusable_doppleganger_objects->list;
    if (pRVar1 != (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      RGE_Object_List::remove_node
                (this->reusable_doppleganger_objects,pRVar2,(RGE_Object_Node *)0x0);
    }
    break;
  case '\x1e':
    pRVar1 = this->reusable_moving_objects->list;
    if (pRVar1 != (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      RGE_Object_List::remove_node(this->reusable_moving_objects,pRVar2,(RGE_Object_Node *)0x0);
      return pRVar2;
    }
    break;
  case '(':
    pRVar1 = this->reusable_action_objects->list;
    if (pRVar1 != (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      RGE_Object_List::remove_node(this->reusable_action_objects,pRVar2,(RGE_Object_Node *)0x0);
      return pRVar2;
    }
    break;
  case '2':
    pRVar1 = this->reusable_combat_objects->list;
    if (pRVar1 != (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      RGE_Object_List::remove_node(this->reusable_combat_objects,pRVar2,(RGE_Object_Node *)0x0);
      return pRVar2;
    }
    break;
  case '<':
    pRVar1 = this->reusable_missile_objects->list;
    if (pRVar1 != (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      RGE_Object_List::remove_node(this->reusable_missile_objects,pRVar2,(RGE_Object_Node *)0x0);
      return pRVar2;
    }
  }
  return pRVar2;
}

// --------------------------------------------------

// Function: update_mutual_allies
// Address: 005462d0
// [HELPER] s__8_8x: "%8.8x"
// [HELPER] s___: "]\n"
// [HELPER] s___RemoveVisibleBits____: "  RemoveVisibleBits = ["
// [HELPER] s___allied_LOS_Enable____d___allie: "  allied_LOS_Enable = %d   allied_victory = %d \n"
// [HELPER] s___mutualExploredMask____8_8x___m: "  mutualExploredMask = %8.8x   mutualVisibleMask = %8.8x   nonMutualVisibleMa..."
// [HELPER] s___mututalAlly____: "  mututalAlly = ["
// [HELPER] s___unitDiplomacy____: "  unitDiplomacy = ["
// [HELPER] s__d: "%d"
// [HELPER] s_player__d_: "player %d\n"
// [HELPER] s_updating_player_visibilites___wt: "updating player visibilites @ wt=%d\n"
/* WARNING: Variable defined which should be unmapped: index */
/* public: void __thiscall RGE_Game_World::update_mutual_allies(void) */

void __thiscall RGE_Game_World::update_mutual_allies(RGE_Game_World *this)
{
  ulong *puVar1;
  uint *puVar2;
  RGE_Player *pRVar3;
  RGE_Player **ppRVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int index;
  int pNum;
  int local_8;
  
  fprintf(DVlogf,s_updating_player_visibilites___wt,this->world_time);
  iVar7 = 0;
  if (0 < this->player_num) {
    do {
      this->players[iVar7]->mutualExploredMask = 0;
      this->players[iVar7]->mutualVisibleMask = 0;
      this->players[iVar7]->nonMutualVisibleMask = 0;
      iVar8 = 0xdc;
      do {
        iVar5 = iVar8 + 4;
        *(undefined4 *)((int)&this->players[iVar7]->_padding_ + iVar8) = 0;
        iVar8 = iVar5;
      } while (iVar5 < 0x100);
      piVar6 = this->players[iVar7]->mutualAlly;
      iVar8 = 0;
      do {
        if (iVar8 == iVar7) {
          *piVar6 = 1;
          this->players[iVar7]->mutualVisibleMask = 1 << ((byte)iVar7 & 0x1f);
          this->players[iVar7]->mutualExploredMask = 1 << ((byte)iVar7 + 0x10 & 0x1f);
        }
        else {
          *piVar6 = 0;
        }
        iVar8 = iVar8 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar8 < 9);
      iVar7 = iVar7 + 1;
    } while (iVar7 < this->player_num);
  }
  iVar7 = (int)this->player_num;
  iVar8 = 1;
  if (1 < iVar7) {
    do {
      if ((this->players[iVar8]->allied_LOS_Enable == 1) && (iVar5 = 1, 1 < iVar7)) {
        do {
          if (iVar5 != iVar8) {
            pRVar3 = this->players[iVar8];
            if ((pRVar3->relations[iVar5] == '\0') &&
               (this->players[iVar5]->relations[iVar8] == '\0')) {
              pRVar3->mutualAlly[iVar5] = 1;
              this->players[iVar8]->mutualVisibleMask =
                   this->players[iVar8]->mutualVisibleMask | 1 << ((byte)iVar5 & 0x1f);
              puVar1 = &this->players[iVar8]->mutualExploredMask;
              *puVar1 = *puVar1 | 1 << ((byte)iVar5 + 0x10 & 0x1f);
            }
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < this->player_num);
      }
      iVar7 = (int)this->player_num;
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar7);
  }
  iVar7 = (int)this->player_num;
  local_8 = 0;
  if (0 < iVar7) {
    iVar8 = 0;
    do {
      pNum = 1;
      if (1 < iVar7) {
        iVar5 = 0xe0;
        do {
          if (((pNum != local_8) &&
              (*(int *)(*(int *)(iVar8 + (int)this->players) + -0x30 + iVar5) == 0)) &&
             (iVar9 = 1, 1 < iVar7)) {
            do {
              ppRVar4 = this->players;
              if (((*(int *)(*(int *)(iVar8 + (int)ppRVar4) + 0xac + iVar9 * 4) == 0) &&
                  (*(int *)(iVar5 + -0x30 + (int)ppRVar4[iVar9]) == 1)) &&
                 (*(int *)((int)ppRVar4[iVar9]->mutualAlly + iVar8) == 1)) {
                *(uint *)(*(int *)(iVar8 + (int)ppRVar4) + 0xd8) =
                     *(uint *)(*(int *)(iVar8 + (int)ppRVar4) + 0xd8) | 1 << ((byte)pNum & 0x1f);
                puVar2 = (uint *)(*(int *)(iVar8 + (int)this->players) + iVar5);
                *puVar2 = *puVar2 | 1 << ((byte)iVar9 & 0x1f);
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < this->player_num);
          }
          iVar7 = (int)this->player_num;
          pNum = pNum + 1;
          iVar5 = iVar5 + 4;
        } while (pNum < iVar7);
      }
      iVar7 = (int)this->player_num;
      local_8 = local_8 + 1;
      iVar8 = iVar8 + 4;
    } while (local_8 < iVar7);
  }
  iVar7 = 0;
  if (0 < this->player_num) {
    iVar8 = 0;
    do {
      fprintf(DVlogf,s_player__d_,iVar7);
      iVar5 = *(int *)(iVar8 + (int)this->players);
      fprintf(DVlogf,s___mutualExploredMask____8_8x___m,*(undefined4 *)(iVar5 + 0xd0),
              *(undefined4 *)(iVar5 + 0xd4),*(undefined4 *)(iVar5 + 0xd8));
      iVar5 = *(int *)(iVar8 + (int)this->players);
      fprintf(DVlogf,s___allied_LOS_Enable____d___allie,*(undefined4 *)(iVar5 + 0x100),
              *(undefined1 *)(iVar5 + 0x104));
      fprintf(DVlogf,s___unitDiplomacy____);
      iVar5 = 0x88;
      do {
        fprintf(DVlogf,&s__d,*(undefined4 *)(*(int *)(iVar8 + (int)this->players) + iVar5));
        if (iVar5 < 0xa8) {
          pcVar10 = s___;
        }
        else {
          pcVar10 = s___;
        }
        fprintf(DVlogf,pcVar10);
        iVar5 = iVar5 + 4;
      } while (iVar5 < 0xac);
      fprintf(DVlogf,s___mututalAlly____);
      iVar5 = 0xac;
      do {
        fprintf(DVlogf,&s__d,*(undefined4 *)(*(int *)(iVar8 + (int)this->players) + iVar5));
        if (iVar5 < 0xcc) {
          pcVar10 = s___;
        }
        else {
          pcVar10 = s___;
        }
        fprintf(DVlogf,pcVar10);
        iVar5 = iVar5 + 4;
      } while (iVar5 < 0xd0);
      fprintf(DVlogf,s___RemoveVisibleBits____);
      iVar5 = 0xdc;
      do {
        fprintf(DVlogf,s__8_8x,*(undefined4 *)(*(int *)(iVar8 + (int)this->players) + iVar5));
        if (iVar5 < 0xfc) {
          pcVar10 = s___;
        }
        else {
          pcVar10 = s___;
        }
        fprintf(DVlogf,pcVar10);
        iVar5 = iVar5 + 4;
      } while (iVar5 < 0x100);
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 4;
    } while (iVar7 < this->player_num);
  }
  piVar6 = (int *)(**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x20))(2);
  }
  piVar6 = (int *)(**(code **)(rge_base_game->_padding_ + 0x30))();
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x20))(2);
  }
  return;
}

// --------------------------------------------------

