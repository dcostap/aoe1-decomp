// Class: TRIBE_World
// Size:  0x124
//
// VTable Layout:
// [00] data_load_world
// [01] data_load_terrain_tables
// [02] data_load_players
// [03] data_load_objects
// [04] data_load_sounds
// [05] data_load_color_tables
// [06] data_load_sprites
// [07] data_load_players_type
// [08] data_load_effects
// [09] data_load_map
// [10] data_load_random_map
// [11] init_player_type
// [12] init_player
// [13] load_player
// [14] color_table_init
// [15] terrain_tables_init
// [16] init_sounds
// [17] init_sprites
// [18] map_init
// [19] effects_init
// [20] master_player_init
// [21] command_init
// [22] world_init
// [23] setup_gaia
// [24] setup_players
// [25] new_random_game
// [26] save
// [27] scenario_make_player
// [28] scenario_make_map
// [29] load_scenario
// [30] load_scenario
// [31] load_scenario1
// [32] load_scenario2
// [33] load_scenario3
// [34] load_scenario4
// [35] load_scenario5
// [36] load_scenario6
// [37] load_scenario7
// [38] load_scenario8
// [39] logStatus
// [40] `scalar_deleting_destructor'
// [41] setup_player_colors
// [42] setup_player_colors
// [43] data_load
// [44] init
// [45] turn_sound_off
// [46] del_game_info
// [47] update
// [48] get_game_state
// [49] check_game_state
// [50] load_world
// [51] load_game
// [52] new_game
// [53] new_scenario
// [54] save_game
// [55] base_save
// [56] base_save
// [57] save_scenario
// [58] get_scenario_info
// [59] pause
// [60] scenario_init
// [61] scenario_init
// [62] addObject
// [63] removeObject
//
// Member Layout:
// [0x104] TRIBE_Tech * tech
// [0x108] int victory_type
// [0x10C] int artifact_count
// [0x110] int ruin_count
// [0x114] uchar countdown_victory
// [0x118] float countdown_clock
// [0x11C] uchar score_displayed
// [0x11D] uchar controllingComputerPlayer
// [0x120] int sent_zone_score
// ----------------------------------------------------------------

// Function: TRIBE_World
// Address: 0052df60
// [HELPER] s_data_aoe_ply: "data\aoe.ply"
TRIBE_World * __thiscall TRIBE_World::TRIBE_World(TRIBE_World *this)
{
  TribeAIPlayBook *this_00;
  AIPlayBook *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005618d3;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Game_World::RGE_Game_World((RGE_Game_World *)this);
  local_4 = 0;
  this->controllingComputerPlayer = 0xff;
  this->_padding_ = (int)&_vftable_;
  this->tech = (TRIBE_Tech *)0x0;
  this->victory_type = 0;
  this->artifact_count = 0;
  this->ruin_count = 0;
  this->sent_zone_score = 0;
  this->countdown_victory = '\0';
  this->countdown_clock = 0.0;
  this->score_displayed = '\0';
  this_00 = (TribeAIPlayBook *)operator_new(0x50);
  local_4._0_1_ = 1;
  if (this_00 == (TribeAIPlayBook *)0x0) {
    this_01 = (AIPlayBook *)0x0;
  }
  else {
    this_01 = (AIPlayBook *)TribeAIPlayBook::TribeAIPlayBook(this_00);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  this->_padding_ = (int)this_01;
  if (this_01 != (AIPlayBook *)0x0) {
    AIPlayBook::loadPlays(this_01,s_data_aoe_ply);
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0052e020
void * __thiscall TRIBE_World::_scalar_deleting_destructor_(TRIBE_World *this,uint param_1)
{
  ~TRIBE_World(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_World
// Address: 0052e040
void __thiscall TRIBE_World::~TRIBE_World(TRIBE_World *this)
{
  TRIBE_Tech *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_005618e8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  this_00 = this->tech;
  local_4 = 0;
  if (this_00 != (TRIBE_Tech *)0x0) {
    TRIBE_Tech::~TRIBE_Tech(this_00);
    operator_delete(this_00);
    this->tech = (TRIBE_Tech *)0x0;
  }
  local_4 = 0xffffffff;
  RGE_Game_World::~RGE_Game_World((RGE_Game_World *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: logStatus
// Address: 0052e0b0
// [HELPER] s_AI_Log_file_for_Game_Started__s: "AI Log file for Game Started %s"
// [HELPER] s_Map_Size__________________s_: "Map Size:                %s\n"
// [HELPER] s_Map_Type__________________s_: "Map Type:                %s\n"
// [HELPER] s_Number_Players____________d_: "Number Players:          %d\n"
// [HELPER] s_Scenario__________________s_: "Scenario:                %s\n"
// [HELPER] s_Victory_Condition_________s_: "Victory Condition:       %s\n"
// [HELPER] s_________________________________: "\n\n\n*****************************************************\n"
void __thiscall TRIBE_World::logStatus(TRIBE_World *this,_iobuf *param_1,int param_2)
{
  char cVar1;
  MapSize MVar2;
  MapType MVar3;
  VictoryType VVar4;
  int iVar5;
  char *pcVar6;
  _iobuf **pp_Var7;
  undefined4 uVar8;
  _iobuf *p_Stack_124;
  char *pcStack_120;
  undefined1 *puStack_11c;
  _iobuf *p_Stack_118;
  _iobuf *p_Stack_114;
  char *pcStack_110;
  long clock;
  char tempString [256];
  
  if ((param_1 != (_iobuf *)0x0) && (param_2 == 1)) {
    pcStack_110 = s_________________________________;
    p_Stack_114 = param_1;
    p_Stack_118 = (_iobuf *)0x52e0e2;
    fprintf();
    pcStack_110 = tempString;
    p_Stack_114 = (_iobuf *)0x52e0ef;
    time();
    pcStack_110 = tempString;
    p_Stack_114 = (_iobuf *)0x52e0fc;
    pcStack_110 = (char *)localtime();
    p_Stack_114 = (_iobuf *)0x52e105;
    pcStack_110 = (char *)asctime();
    p_Stack_114 = (_iobuf *)s_AI_Log_file_for_Game_Started__s;
    p_Stack_118 = param_1;
    puStack_11c = (undefined1 *)0x52e114;
    fprintf();
    pcStack_110 = (char *)((short)this->_padding_ + -1);
    p_Stack_114 = (_iobuf *)s_Number_Players____________d_;
    p_Stack_118 = param_1;
    puStack_11c = (undefined1 *)0x52e128;
    fprintf();
    pcStack_110 = *(char **)(this->_padding_ + 0x1010);
    if (pcStack_110 != (char *)0x0) {
      iVar5 = -1;
      pcVar6 = pcStack_110;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      if (iVar5 != -2) {
        p_Stack_114 = (_iobuf *)s_Scenario__________________s_;
        p_Stack_118 = param_1;
        puStack_11c = (undefined1 *)0x52e152;
        fprintf();
        return;
      }
    }
    p_Stack_114 = (_iobuf *)(tempString + 4);
    pcStack_110 = (char *)0x100;
    iVar5 = rge_base_game->_padding_;
    p_Stack_118 = (_iobuf *)0x52e177;
    MVar2 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
    p_Stack_118 = (_iobuf *)(MVar2 + 0x2973);
    puStack_11c = (undefined1 *)0x52e186;
    (**(code **)(iVar5 + 0x20))();
    puStack_11c = &stack0xfffffef4;
    pcStack_120 = s_Map_Size__________________s_;
    p_Stack_124 = param_1;
    fprintf();
    pcStack_120 = &stack0xfffffef4;
    iVar5 = rge_base_game->_padding_;
    puStack_11c = (undefined1 *)0x100;
    p_Stack_124 = (_iobuf *)0x52e1b0;
    MVar3 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
    p_Stack_124 = (_iobuf *)(MVar3 + 0x296a);
    (**(code **)(iVar5 + 0x20))();
    fprintf(param_1,s_Map_Type__________________s_,&p_Stack_118);
    pp_Var7 = &p_Stack_118;
    iVar5 = rge_base_game->_padding_;
    uVar8 = 0x100;
    VVar4 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
    (**(code **)(iVar5 + 0x20))(VVar4 + 0x28a6,pp_Var7,uVar8);
    fprintf(param_1,s_Victory_Condition_________s_,&p_Stack_124);
  }
  return;
}

// --------------------------------------------------

// Function: data_load_players_type
// Address: 0052e220
void __thiscall
TRIBE_World::data_load_players_type(TRIBE_World *this,short param_1,short param_2,_iobuf *param_3)
{
  TRIBE_Master_Player *this_00;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056190b;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 != 1) {
    RGE_Game_World::data_load_players_type((RGE_Game_World *)this,param_1,param_2,param_3);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  this_00 = (TRIBE_Master_Player *)operator_new(0x2c);
  local_4 = 0;
  if (this_00 == (TRIBE_Master_Player *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = TRIBE_Master_Player::TRIBE_Master_Player(this_00,param_3);
  }
  *(undefined4 *)(this->_padding_ + param_1 * 4) = uVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: data_load_map
// Address: 0052e2b0
void __thiscall
TRIBE_World::data_load_map
          (TRIBE_World *this,char *param_1,char *param_2,char *param_3,char *param_4,short param_5,
          short param_6,short param_7,RGE_Sound **param_8,char *param_9)
{
  TRIBE_Map *this_00;
  RGE_Map *this_01;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056192b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Map *)operator_new(0xb5f8);
  local_4 = 0;
  if (this_00 == (TRIBE_Map *)0x0) {
    this_01 = (RGE_Map *)0x0;
  }
  else {
    this_01 = (RGE_Map *)
              TRIBE_Map::TRIBE_Map
                        (this_00,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  local_4 = 0xffffffff;
  this->_padding_ = (int)this_01;
  RGE_Map::load_terrain_obj_types(this_01,param_9);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: data_load_world
// Address: 0052e350
// [HELPER] s__s_: "%s\n"
uchar __thiscall TRIBE_World::data_load_world(TRIBE_World *this,_iobuf *param_1)
{
  TRIBE_Tech *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  char tech_file [23];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056194b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  RGE_Game_World::data_load_world((RGE_Game_World *)this,param_1);
  fscanf(param_1,s__s_,tech_file + 4);
  pTVar1 = (TRIBE_Tech *)operator_new(0xc);
  local_4 = 0;
  if (pTVar1 == (TRIBE_Tech *)0x0) {
    pTVar1 = (TRIBE_Tech *)0x0;
  }
  else {
    pTVar1 = (TRIBE_Tech *)TRIBE_Tech::TRIBE_Tech(pTVar1,tech_file + 4);
  }
  this->tech = pTVar1;
  this->victory_type = 0;
  this->artifact_count = 0;
  this->ruin_count = 0;
  this->countdown_victory = '\0';
  this->countdown_clock = 0.0;
  this->score_displayed = '\0';
  *unaff_FS_OFFSET = local_c;
  return '\x01';
}

// --------------------------------------------------

// Function: init_player_type
// Address: 0052e400
uchar __thiscall
TRIBE_World::init_player_type(TRIBE_World *this,int param_1,short param_2,uchar param_3)
{
  uchar uVar1;
  TRIBE_Master_Player *this_00;
  undefined4 uVar2;
  int *unaff_FS_OFFSET;
  int iVar3;
  int local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056196b;
  *unaff_FS_OFFSET = (int)&local_c;
  if (param_3 != '\x01') {
    uVar1 = RGE_Game_World::init_player_type((RGE_Game_World *)this,param_1,param_2,param_3);
    *unaff_FS_OFFSET = local_c;
    return uVar1;
  }
  this_00 = (TRIBE_Master_Player *)operator_new(0x2c);
  local_4 = 0;
  if (this_00 == (TRIBE_Master_Player *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = TRIBE_Master_Player::TRIBE_Master_Player(this_00,param_1);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + param_2 * 4) = uVar2;
  iVar3 = this->_padding_;
  (**(code **)(**(int **)(this->_padding_ + param_2 * 4) + 4))(param_1,this->_padding_);
  *unaff_FS_OFFSET = iVar3;
  return '\x01';
}

// --------------------------------------------------

// Function: map_init
// Address: 0052e4c0
void __thiscall TRIBE_World::map_init(TRIBE_World *this,int param_1,TSound_Driver *param_2)
{
  TRIBE_Map *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056198b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Map *)operator_new(0xb5f8);
  local_4 = 0;
  if (this_00 == (TRIBE_Map *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_Map::TRIBE_Map(this_00,param_1,(RGE_Sound **)this->_padding_,'\x01');
  }
  this->_padding_ = iVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: command_init
// Address: 0052e530
void __thiscall
TRIBE_World::command_init(TRIBE_World *this,int param_1,TCommunications_Handler *param_2)
{
  TRIBE_Command *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005619ab;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Command *)operator_new(0x18);
  local_4 = 0;
  if (this_00 == (TRIBE_Command *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_Command::TRIBE_Command(this_00,this,param_2);
  }
  this->_padding_ = iVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: scenario_init
// Address: 0052e590
void __thiscall TRIBE_World::scenario_init(TRIBE_World *this,int param_1,RGE_Game_World *param_2)
{
  T_Scenario *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005619cb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (T_Scenario *)operator_new(0x514c);
  local_4 = 0;
  if (this_00 == (T_Scenario *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = T_Scenario::T_Scenario(this_00,param_1,param_2);
  }
  this->_padding_ = iVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: scenario_init
// Address: 0052e5f0
void __thiscall TRIBE_World::scenario_init(TRIBE_World *this,RGE_Game_World *param_1)
{
  T_Scenario *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_005619eb;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (T_Scenario *)operator_new(0x514c);
  local_4 = 0;
  if (this_00 == (T_Scenario *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = T_Scenario::T_Scenario(this_00,param_1);
  }
  this->_padding_ = iVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: effects_init
// Address: 0052e650
void __thiscall TRIBE_World::effects_init(TRIBE_World *this,int param_1)
{
  TRIBE_Effects *this_00;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561a0b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Effects *)operator_new(0xc);
  local_4 = 0;
  if (this_00 == (TRIBE_Effects *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRIBE_Effects::TRIBE_Effects(this_00,param_1);
  }
  this->_padding_ = iVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: world_init
// Address: 0052e6b0
void __thiscall
TRIBE_World::world_init
          (TRIBE_World *this,int param_1,TSound_Driver *param_2,TCommunications_Handler *param_3)
{
  TRIBE_Tech *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561a2b;
  *unaff_FS_OFFSET = &local_c;
  RGE_Game_World::world_init((RGE_Game_World *)this,param_1,param_2,param_3);
  pTVar1 = (TRIBE_Tech *)operator_new(0xc);
  local_4 = 0;
  if (pTVar1 == (TRIBE_Tech *)0x0) {
    pTVar1 = (TRIBE_Tech *)0x0;
  }
  else {
    pTVar1 = (TRIBE_Tech *)TRIBE_Tech::TRIBE_Tech(pTVar1,param_1,this);
  }
  this->tech = pTVar1;
  this->victory_type = 0;
  this->artifact_count = 0;
  this->ruin_count = 0;
  this->countdown_victory = '\0';
  this->countdown_clock = 0.0;
  this->score_displayed = '\0';
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: init
// Address: 0052e750
uchar __thiscall
TRIBE_World::init(TRIBE_World *this,char *param_1,TSound_Driver *param_2,
                 TCommunications_Handler *param_3)
{
  uchar uVar1;
  
  uVar1 = RGE_Game_World::init((RGE_Game_World *)this,param_1,param_2,param_3);
  return uVar1;
}

// --------------------------------------------------

// Function: base_save
// Address: 0052e770
void __thiscall TRIBE_World::base_save(TRIBE_World *this,int param_1)
{
  RGE_Game_World::base_save((RGE_Game_World *)this,param_1);
  TRIBE_Tech::save(this->tech,param_1);
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0052e790
void __thiscall TRIBE_World::save(TRIBE_World *this,int param_1)
{
  RGE_Game_World::save((RGE_Game_World *)this,param_1);
  rge_write(param_1,&this->victory_type,4);
  rge_write(param_1,&this->artifact_count,4);
  rge_write(param_1,&this->ruin_count,4);
  rge_write(param_1,&this->countdown_victory,1);
  rge_write(param_1,&this->countdown_clock,4);
  rge_write(param_1,&this->score_displayed,1);
  rge_write(param_1,&this->controllingComputerPlayer,1);
  return;
}

// --------------------------------------------------

// Function: load_player
// Address: 0052e830
void __thiscall TRIBE_World::load_player(TRIBE_World *this,int param_1,uchar param_2,short param_3)
{
  TRIBE_Gaia *this_00;
  TRIBE_Player *this_01;
  undefined4 uVar1;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561a56;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 == '\x01') {
LAB_0052e8b5:
    this_01 = (TRIBE_Player *)operator_new(0x848);
    local_4 = 0;
    if (this_01 != (TRIBE_Player *)0x0) {
      uVar1 = TRIBE_Player::TRIBE_Player(this_01,param_1,this,(uchar)param_3);
      goto LAB_0052e8e8;
    }
  }
  else {
    if (param_2 != '\x02') {
      if (param_2 != '\x03') {
        RGE_Game_World::load_player((RGE_Game_World *)this,param_1,param_2,param_3);
        *unaff_FS_OFFSET = local_c;
        return;
      }
      goto LAB_0052e8b5;
    }
    this_00 = (TRIBE_Gaia *)operator_new(0x858);
    local_4 = 1;
    if (this_00 != (TRIBE_Gaia *)0x0) {
      uVar1 = TRIBE_Gaia::TRIBE_Gaia(this_00,param_1,this,(uchar)param_3);
      goto LAB_0052e8e8;
    }
  }
  uVar1 = 0;
LAB_0052e8e8:
  local_4 = 0xffffffff;
  *(undefined4 *)(this->_padding_ + param_3 * 4) = uVar1;
  (**(code **)(**(int **)(this->_padding_ + param_3 * 4) + 0x74))(param_1);
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}

// --------------------------------------------------

// Function: setup_gaia
// Address: 0052e920
// [HELPER] s_GAIA: "GAIA"
void __thiscall TRIBE_World::setup_gaia(TRIBE_World *this)
{
  TRIBE_Gaia *this_00;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561a6b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Gaia *)operator_new(0x858);
  local_4 = 0;
  if (this_00 == (TRIBE_Gaia *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = TRIBE_Gaia::TRIBE_Gaia
                      (this_00,this,*(RGE_Master_Player **)this->_padding_,'\0',s_GAIA,'\0');
  }
  *(undefined4 *)this->_padding_ = uVar1;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setup_players
// Address: 0052e990
void __thiscall TRIBE_World::setup_players(TRIBE_World *this,RGE_Player_Info *param_1)
{
  RGE_Player_Info *pRVar1;
  TRIBE_Player *pTVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_00561aa1;
  *unaff_FS_OFFSET = &local_c;
  iVar4 = 1;
  pRVar1 = param_1;
  if (1 < (short)this->_padding_) {
    do {
      local_4 = 0xffffffff;
      if (param_1->type[iVar4 + -1] == '\0') {
        pTVar2 = (TRIBE_Player *)operator_new(0x848);
        local_4 = 0;
        if (pTVar2 == (TRIBE_Player *)0x0) goto LAB_0052ea8b;
LAB_0052ea60:
        uVar3 = TRIBE_Player::TRIBE_Player
                          (pTVar2,this,
                           *(RGE_Master_Player **)(this->_padding_ + param_1->type[iVar4 + 8] * 4),
                           (uchar)iVar4,(char *)pRVar1,param_1->type[iVar4 + 8],'\0','\x01',
                           (char *)0x0,(char *)0x0,(char *)0x0);
LAB_0052ea8d:
        *(undefined4 *)(this->_padding_ + iVar4 * 4) = uVar3;
      }
      else if (param_1->type[iVar4 + -1] == '\x04') {
        if (useComputerPlayers == 0) {
          pTVar2 = (TRIBE_Player *)operator_new(0x848);
          local_4 = 1;
          if (pTVar2 != (TRIBE_Player *)0x0) goto LAB_0052ea60;
        }
        else {
          pTVar2 = (TRIBE_Player *)operator_new(0x848);
          local_4 = 2;
          if (pTVar2 != (TRIBE_Player *)0x0) {
            uVar3 = TRIBE_Player::TRIBE_Player
                              (pTVar2,this,
                               *(RGE_Master_Player **)
                                (this->_padding_ + param_1->type[iVar4 + 8] * 4),(uchar)iVar4,
                               (char *)pRVar1,param_1->type[iVar4 + 8],'\x01','\x01',(char *)0x0,
                               (char *)0x0,(char *)0x0);
            goto LAB_0052ea8d;
          }
        }
LAB_0052ea8b:
        uVar3 = 0;
        goto LAB_0052ea8d;
      }
      iVar4 = iVar4 + 1;
      pRVar1 = (RGE_Player_Info *)(pRVar1->name + 1);
    } while (iVar4 < (short)this->_padding_);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: check_destructables
// Address: 0052eac0
void __thiscall
TRIBE_World::check_destructables
          (TRIBE_World *this,short param_1,short param_2,float param_3,float param_4,uchar param_5)
{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  undefined4 *puVar11;
  int iVar12;
  int local_20;
  float rx;
  float ry;
  int local_10;
  float ry2;
  
  iVar12 = *(int *)(*(int *)(*(int *)(this->_padding_ + param_1 * 4) + 0x24) + param_2 * 4);
  if (iVar12 != 0) {
    fVar1 = *(float *)(iVar12 + 0x30);
    fVar2 = *(float *)(iVar12 + 0x34);
    if (((float)DAT_00577558 < fVar1) || ((float)DAT_00577558 < fVar2)) {
      param_1 = __ftol();
      sVar8 = __ftol();
      sVar9 = __ftol();
      sVar10 = __ftol();
      if (param_1 < 0) {
        param_1 = 0;
      }
      iVar12 = this->_padding_;
      if (*(int *)(iVar12 + 8) <= (int)sVar9) {
        sVar9 = *(short *)(iVar12 + 8) + -1;
      }
      if (sVar8 < 0) {
        sVar8 = 0;
      }
      if (*(int *)(iVar12 + 0xc) <= (int)sVar10) {
        sVar10 = *(short *)(iVar12 + 0xc) + -1;
      }
      if (sVar8 <= sVar10) {
        local_20 = sVar8 * 4;
        local_10 = ((int)sVar10 - (int)sVar8) + 1;
        do {
          if (param_1 <= sVar9) {
            puVar11 = (undefined4 *)
                      (*(int *)(*(int *)(this->_padding_ + 0x8d8c) + local_20) + param_1 * 0x18 +
                      0x10);
            iVar12 = ((int)sVar9 - (int)param_1) + 1;
            do {
              piVar3 = (int *)*puVar11;
              while (piVar3 != (int *)0x0) {
                piVar4 = (int *)*piVar3;
                piVar3 = (int *)piVar3[1];
                iVar5 = piVar4[2];
                if ((*(short *)(iVar5 + 0x10) != param_2) && (*(char *)(iVar5 + 0x4b) != '\0')) {
                  fVar6 = (float)piVar4[0xf] - param_4;
                  fVar7 = (float)piVar4[0xe] - param_3;
                  if (fVar6 < (float)DAT_00577558) {
                    fVar6 = -fVar6;
                  }
                  if (fVar7 < (float)DAT_00577558) {
                    fVar7 = -fVar7;
                  }
                  if ((fVar7 < *(float *)(iVar5 + 0x30) + fVar1) &&
                     (fVar6 < *(float *)(iVar5 + 0x34) + fVar2)) {
                    if (param_5 == '\0') {
                      (**(code **)(*piVar4 + 0x68))();
                    }
                    else if (piVar4 != (int *)0x0) {
                      (**(code **)*piVar4)(1);
                    }
                  }
                }
              }
              puVar11 = puVar11 + 6;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
          }
          local_20 = local_20 + 4;
          local_10 = local_10 + -1;
        } while (local_10 != 0);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: scenario_make_player
// Address: 0052ecf0
void __thiscall
TRIBE_World::scenario_make_player
          (TRIBE_World *this,short param_1,uchar param_2,uchar param_3,uchar param_4,char *param_5)
{
  TRIBE_Player *pTVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561ad1;
  *unaff_FS_OFFSET = &local_c;
  if (param_3 == '\0') {
    pTVar1 = (TRIBE_Player *)operator_new(0x848);
    local_4 = 0;
joined_r0x0052eda3:
    if (pTVar1 != (TRIBE_Player *)0x0) {
      uVar2 = TRIBE_Player::TRIBE_Player
                        (pTVar1,this,*(RGE_Master_Player **)(this->_padding_ + (uint)param_2 * 4),
                         (uchar)param_1,param_5,param_2,'\0','\x01',(char *)0x0,(char *)0x0,
                         (char *)0x0);
      goto LAB_0052edd3;
    }
  }
  else {
    if (param_3 != '\x04') {
      pTVar1 = (TRIBE_Player *)operator_new(0x848);
      local_4 = 2;
      goto joined_r0x0052eda3;
    }
    pTVar1 = (TRIBE_Player *)operator_new(0x848);
    local_4 = 1;
    if (pTVar1 != (TRIBE_Player *)0x0) {
      uVar2 = TRIBE_Player::TRIBE_Player
                        (pTVar1,this,*(RGE_Master_Player **)(this->_padding_ + (uint)param_2 * 4),
                         (uchar)param_1,param_5,param_2,'\x01','\x01',(char *)0x0,(char *)0x0,
                         (char *)0x0);
      goto LAB_0052edd3;
    }
  }
  uVar2 = 0;
LAB_0052edd3:
  *(undefined4 *)(this->_padding_ + param_1 * 4) = uVar2;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: load_world
// Address: 0052edf0
uchar __thiscall TRIBE_World::load_world(TRIBE_World *this,int param_1)
{
  uchar uVar1;
  
  uVar1 = RGE_Game_World::load_world((RGE_Game_World *)this,param_1);
  if (uVar1 == '\0') {
    return '\0';
  }
  if (save_game_version < _DAT_00577564) {
    this->victory_type = 0;
  }
  else {
    rge_read(param_1,&this->victory_type,4);
  }
  if (save_game_version < _DAT_00577568) {
    this->artifact_count = 0;
    this->ruin_count = 0;
  }
  else {
    rge_read(param_1,&this->artifact_count,4);
    rge_read(param_1,&this->ruin_count,4);
  }
  if (save_game_version < _DAT_0057756c) {
    this->countdown_victory = '\0';
    this->countdown_clock = 0.0;
  }
  else {
    rge_read(param_1,&this->countdown_victory,1);
    rge_read(param_1,&this->countdown_clock,4);
  }
  if (save_game_version < _DAT_00577570) {
    this->score_displayed = '\0';
  }
  else {
    rge_read(param_1,&this->score_displayed,1);
  }
  if (_DAT_00577574 <= save_game_version) {
    rge_read(param_1,&this->controllingComputerPlayer,1);
    return '\x01';
  }
  this->controllingComputerPlayer = '\x02';
  return '\x01';
}

// --------------------------------------------------

// Function: new_game
// Address: 0052ef30
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_tworld_cpp: "C:\msdev\work\age1_x1\tworld.cpp"
// [HELPER] s_NOFOODCAP: "NOFOODCAP"
// [HELPER] s_SYSTEM2: "SYSTEM2"
// [HELPER] s__s__s: "%s\n%s"
uchar __thiscall TRIBE_World::new_game(TRIBE_World *this,RGE_Player_Info *param_1,int param_2)
{
  char cVar1;
  short sVar2;
  int *piVar3;
  uchar uVar4;
  byte bVar5;
  uchar uVar6;
  VictoryType VVar7;
  MapSize MVar8;
  MapType MVar9;
  Age AVar10;
  ResourceLevel RVar11;
  int iVar12;
  char *pcVar13;
  undefined4 uVar14;
  RGE_RMM_Object_Generator *this_00;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  int iVar19;
  char *pcVar20;
  char *pcVar21;
  char **ppcVar22;
  undefined4 *unaff_FS_OFFSET;
  char ***pppcVar23;
  char *pcStack_137c;
  char **ppcStack_1378;
  char *pcStack_1374;
  char **ppcStack_1370;
  char *pcStack_136c;
  char **ppcStack_1368;
  char **ppcStack_1364;
  undefined4 uStack_1360;
  char *apcStack_135c [6];
  int iStack_1344;
  char *pcStack_1340;
  char *pcStack_133c;
  int victoryAmount;
  RGE_RMM_Object_Generator *pRStack_1314;
  uchar ret_num;
  char str1 [256];
  char str2 [256];
  char str3 [256];
  char description [4096];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_00561aee;
  *unaff_FS_OFFSET = &uStack_c;
  this->score_displayed = '\0';
  this->controllingComputerPlayer = 0xff;
  uVar4 = RGE_Game_World::new_game((RGE_Game_World *)this,param_1,param_2);
  iVar19 = 0;
  str1[3] = uVar4;
  if (0 < (short)this->_padding_) {
    do {
      RGE_Base_Game::reset_countdown_timer(rge_base_game,iVar19);
      iVar19 = iVar19 + 1;
    } while (iVar19 < (short)this->_padding_);
  }
  iVar19 = RGE_Base_Game::campaignGame(rge_base_game);
  if (((iVar19 != 0) || (iVar19 = RGE_Base_Game::randomGame(rge_base_game), iVar19 == 0)) &&
     (VVar7 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game), VVar7 == VictoryDefault))
  goto LAB_0052f765;
  iVar19 = RGE_Base_Game::campaignGame(rge_base_game);
  if ((iVar19 == 0) && (iVar19 = RGE_Base_Game::randomGame(rge_base_game), iVar19 != 0)) {
    RGE_Scenario::Set_scenario_name((RGE_Scenario *)this->_padding_,s_);
  }
  VVar7 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  switch(VVar7) {
  case VictoryDefault:
  case VictoryStandard:
    iVar19 = rge_base_game->_padding_;
    break;
  case VictoryConquest:
    iVar19 = rge_base_game->_padding_;
    break;
  default:
    goto switchD_0052f009_caseD_2;
  case VictoryTime:
    iVar19 = rge_base_game->_padding_;
    break;
  case VictoryScore:
    iVar19 = rge_base_game->_padding_;
  }
  (**(code **)(iVar19 + 0x20))();
switchD_0052f009_caseD_2:
  MVar8 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
  switch(MVar8) {
  case Tiny:
    pcVar13 = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))();
    goto LAB_0052f0fa;
  case Small:
    iVar19 = rge_base_game->_padding_;
    break;
  case Medium:
    iVar19 = rge_base_game->_padding_;
    break;
  case Large:
    iVar19 = rge_base_game->_padding_;
    break;
  case Huge:
    iVar19 = rge_base_game->_padding_;
    break;
  case Humongous:
    iVar19 = rge_base_game->_padding_;
    break;
  default:
    goto switchD_0052f095_default;
  }
  pcVar13 = (char *)(**(code **)(iVar19 + 0x24))();
LAB_0052f0fa:
  uVar15 = 0xffffffff;
  pcVar21 = str1;
  do {
    pcVar20 = pcVar13;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar20 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar20;
  } while (cVar1 != '\0');
  uVar15 = ~uVar15;
  pcVar13 = pcVar20 + -uVar15;
  for (uVar16 = uVar15 >> 2; pcVar21 = pcVar21 + 4, uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)pcVar21 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *pcVar21 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar21 = pcVar21 + 1;
  }
switchD_0052f095_default:
  (**(code **)(rge_base_game->_padding_ + 0x24))();
  sprintf();
  pcStack_133c = (char *)0x52f165;
  sprintf();
  iVar19 = RGE_Base_Game::randomGame(rge_base_game);
  if (iVar19 != 0) {
    MVar9 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
    switch(MVar9) {
    case AllWater:
      iVar19 = rge_base_game->_padding_;
      break;
    case MostlyWater:
      iVar19 = rge_base_game->_padding_;
      break;
    case WaterAndLand:
      iVar19 = rge_base_game->_padding_;
      break;
    case MostlyLand:
      iVar19 = rge_base_game->_padding_;
      break;
    case AllLand:
      iVar19 = rge_base_game->_padding_;
      break;
    case Continental:
      iVar19 = rge_base_game->_padding_;
      break;
    case Lake:
      iVar19 = rge_base_game->_padding_;
      break;
    case Hilly:
      iVar19 = rge_base_game->_padding_;
      break;
    case Isthmas:
      iVar19 = rge_base_game->_padding_;
      break;
    default:
      goto switchD_0052f18f_default;
    }
    pcVar13 = (char *)(**(code **)(iVar19 + 0x24))();
    uVar15 = 0xffffffff;
    do {
      pcVar21 = pcVar13;
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      pcVar21 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar21;
    } while (cVar1 != '\0');
    uVar15 = ~uVar15;
    pcVar13 = pcVar21 + -uVar15;
    pcVar21 = str1;
    for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(undefined4 *)pcVar21 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar21 = pcVar21 + 4;
    }
    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *pcVar21 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar21 = pcVar21 + 1;
    }
switchD_0052f18f_default:
    (**(code **)(rge_base_game->_padding_ + 0x24))();
    sprintf();
    pcStack_133c = (char *)0x52f289;
    sprintf();
  }
  AVar10 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar10 == DefaultAge) {
    iVar19 = rge_base_game->_padding_;
  }
  else {
    iVar19 = rge_base_game->_padding_;
  }
  (**(code **)(iVar19 + 0x20))();
  pcStack_133c = (char *)0x25e4;
  pcStack_1340 = (char *)0x52f2f5;
  pcStack_1340 = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))();
  iStack_1344 = (int)(str1 + 0xf0);
  apcStack_135c[5] = (char *)0x52f303;
  sprintf();
  pcStack_133c = str1 + 0xf0;
  pcStack_1340 = str3 + 0xf0;
  apcStack_135c[5] = str3 + 0xf0;
  iStack_1344 = (int)s__s__s;
  apcStack_135c[4] = (char *)0x52f328;
  sprintf();
  pcStack_133c = (char *)0x52f336;
  RVar11 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  pcStack_133c = (char *)0x100;
  if (RVar11 == DefaultResources) {
    iStack_1344 = 0x10e7;
  }
  else {
    iStack_1344 = RVar11 + 0x25e5;
  }
  pcStack_1340 = &stack0xffffece0;
  apcStack_135c[5] = (char *)0x52f361;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  apcStack_135c[5] = &stack0xffffecd4;
  apcStack_135c[4] = (char *)0x25e5;
  apcStack_135c[3] = (char *)0x52f376;
  apcStack_135c[3] = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))();
  apcStack_135c[2] = str1 + 0xe0;
  apcStack_135c[1] = (char *)0x52f384;
  sprintf();
  apcStack_135c[4] = str1 + 0xe0;
  apcStack_135c[3] = str3 + 0xe0;
  apcStack_135c[1] = str3 + 0xe0;
  apcStack_135c[2] = s__s__s;
  apcStack_135c[0] = (char *)0x52f3a9;
  sprintf();
  apcStack_135c[4] = (char *)0x52f3b7;
  RGE_Base_Game::difficulty(rge_base_game);
  apcStack_135c[3] = &stack0xffffecd0;
  apcStack_135c[4] = (char *)0x100;
  iVar19 = rge_base_game->_padding_;
  apcStack_135c[2] = (char *)0x52f3ce;
  iVar12 = RGE_Base_Game::difficulty(rge_base_game);
  apcStack_135c[2] = (char *)(iVar12 + 0x2bd0);
  apcStack_135c[1] = (char *)0x52f3dd;
  (**(code **)(iVar19 + 0x20))();
  apcStack_135c[0] = str1 + 0xd4;
  apcStack_135c[1] = (char *)0x100;
  uStack_1360 = 0x25e0;
  ppcStack_1364 = (char **)0x52f3fa;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  ppcStack_1364 = apcStack_135c + 5;
  ppcStack_1368 = (char **)(str1 + 200);
  pcStack_136c = str2 + 200;
  ppcStack_1370 = (char **)0x52f414;
  sprintf();
  ppcStack_1364 = (char **)(str2 + 200);
  ppcStack_1368 = (char **)(str3 + 200);
  ppcStack_1370 = (char **)(str3 + 200);
  pcStack_136c = s__s__s;
  pcStack_1374 = (char *)0x52f439;
  sprintf();
  ppcStack_1364 = (char **)0x52f447;
  iVar19 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  ppcStack_1368 = apcStack_135c + 5;
  ppcStack_1364 = (char **)0x100;
  if (iVar19 == 0) {
    pcStack_136c = (char *)0xfa3;
  }
  else {
    pcStack_136c = (char *)0xfa4;
  }
  ppcStack_1370 = (char **)0x52f46c;
  (**(code **)(rge_base_game->_padding_ + 0x20))();
  ppcStack_1370 = apcStack_135c + 2;
  pcStack_1374 = (char *)0x25e9;
  ppcStack_1378 = (char **)0x52f481;
  ppcStack_1378 = (char **)(**(code **)(rge_base_game->_padding_ + 0x24))();
  pcStack_137c = str1 + 0xb8;
  sprintf();
  pcStack_1374 = str1 + 0xb8;
  ppcStack_1378 = (char **)(str3 + 0xb8);
  pcStack_137c = s__s__s;
  sprintf(str3 + 0xb8);
  pcStack_1374 = (char *)0x52f4c2;
  iVar19 = RGE_Base_Game::fullVisibility(rge_base_game);
  if (iVar19 == 0) {
    pcStack_1374 = (char *)0xfa4;
  }
  else {
    pcStack_1374 = (char *)0xfa3;
  }
  ppcStack_1378 = (char **)0x52f4dd;
  pcVar13 = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))();
  uVar15 = 0xffffffff;
  do {
    pcVar21 = pcVar13;
    if (uVar15 == 0) break;
    uVar15 = uVar15 - 1;
    pcVar21 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar21;
  } while (cVar1 != '\0');
  uVar15 = ~uVar15;
  pcVar13 = pcVar21 + -uVar15;
  ppcVar22 = apcStack_135c;
  for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
    *ppcVar22 = *(char **)pcVar13;
    pcVar13 = pcVar13 + 4;
    ppcVar22 = ppcVar22 + 1;
  }
  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
    *(char *)ppcVar22 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    ppcVar22 = (char **)((int)ppcVar22 + 1);
  }
  ppcStack_1378 = apcStack_135c;
  pcStack_137c = (char *)0x25b8;
  uVar14 = (**(code **)(rge_base_game->_padding_ + 0x24))();
  sprintf(str1 + 0xb0,uVar14);
  pcStack_137c = str1 + 0xb0;
  sprintf(str3 + 0xb0,s__s__s,str3 + 0xb0);
  pcStack_137c = (char *)0x52f556;
  iVar19 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  pcStack_137c = (char *)0x100;
  if (iVar19 == 0) {
    uVar14 = 0xfa4;
  }
  else {
    uVar14 = 0xfa3;
  }
  (**(code **)(rge_base_game->_padding_ + 0x20))(uVar14,&uStack_1360);
  uVar14 = (**(code **)(rge_base_game->_padding_ + 0x24))(0x25ec,&pcStack_136c);
  sprintf(str1 + 0xa0,uVar14);
  sprintf(str3 + 0xa0,s__s__s,str3 + 0xa0,str1 + 0xa0);
  iVar19 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar19 != 0) {
    iVar19 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    if (iVar19 == 0) {
      uVar14 = 0xfa4;
    }
    else {
      uVar14 = 0xfa3;
    }
    pcVar13 = (char *)(**(code **)(rge_base_game->_padding_ + 0x24))(uVar14);
    uVar15 = 0xffffffff;
    do {
      pcVar21 = pcVar13;
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      pcVar21 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar21;
    } while (cVar1 != '\0');
    uVar15 = ~uVar15;
    pcVar13 = pcVar21 + -uVar15;
    ppcVar22 = &pcStack_1374;
    for (uVar16 = uVar15 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
      *ppcVar22 = *(char **)pcVar13;
      pcVar13 = pcVar13 + 4;
      ppcVar22 = ppcVar22 + 1;
    }
    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
      *(char *)ppcVar22 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      ppcVar22 = (char **)((int)ppcVar22 + 1);
    }
    uVar14 = (**(code **)(rge_base_game->_padding_ + 0x24))(0x25bb,&pcStack_1374);
    sprintf(str1 + 0xa0,uVar14);
    sprintf(str3 + 0xa0,s__s__s,str3 + 0xa0,str1 + 0xa0);
  }
  iVar12 = RGE_Base_Game::multiplayerGame(rge_base_game);
  uVar14 = 0x100;
  iVar19 = rge_base_game->_padding_;
  if (iVar12 == 0) {
    pppcVar23 = &ppcStack_1370;
    bVar5 = RGE_Base_Game::pathFinding(rge_base_game);
  }
  else {
    pppcVar23 = &ppcStack_1370;
    bVar5 = RGE_Base_Game::mpPathFinding(rge_base_game);
  }
  (**(code **)(iVar19 + 0x20))(bVar5 + 0x260e,pppcVar23,uVar14);
  uVar14 = (**(code **)(rge_base_game->_padding_ + 0x24))(0x25f1,&pcStack_137c);
  sprintf(str1 + 0x90,uVar14);
  sprintf(str3 + 0x90,s__s__s,str3 + 0x90,str1 + 0x90);
  uVar6 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
  (**(code **)(rge_base_game->_padding_ + 0x24))(0x25f0,uVar6);
  sprintf();
  sprintf();
  RGE_Scenario::add_description((RGE_Scenario *)this->_padding_,description + 4);
LAB_0052f765:
  if (uVar4 != '\0') {
    this->victory_type = 4;
    this->countdown_victory = '\0';
    this->countdown_clock = 0.0;
    iVar19 = RGE_Base_Game::campaignGame(rge_base_game);
    if (((iVar19 == 0) && (iVar19 = RGE_Base_Game::randomGame(rge_base_game), iVar19 != 0)) ||
       (VVar7 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game), VVar7 != VictoryDefault)) {
      T_Scenario::Set_victory_all_flag((T_Scenario *)this->_padding_,0);
      T_Scenario::Set_Multi_Conquest((T_Scenario *)this->_padding_,0);
      T_Scenario::Set_Multi_Ruins((T_Scenario *)this->_padding_,0);
      T_Scenario::Set_Multi_Artifacts((T_Scenario *)this->_padding_,0);
      T_Scenario::Set_Multi_Discoveries((T_Scenario *)this->_padding_,0);
      T_Scenario::Set_Multi_Exploration((T_Scenario *)this->_padding_,0);
      T_Scenario::Set_Multi_Gold((T_Scenario *)this->_padding_,0);
      iVar19 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
      VVar7 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
      switch(VVar7) {
      case VictoryDefault:
      case VictoryStandard:
        this->victory_type = 0;
        T_Scenario::Set_Multi_Conquest((T_Scenario *)this->_padding_,1);
        break;
      case VictoryConquest:
        this->victory_type = 1;
        T_Scenario::Set_Multi_Conquest((T_Scenario *)this->_padding_,1);
        break;
      case VictoryExplore:
        T_Scenario::Set_Multi_Exploration((T_Scenario *)this->_padding_,iVar19);
        break;
      case VictoryRuins:
        T_Scenario::Set_Multi_Ruins((T_Scenario *)this->_padding_,iVar19);
        break;
      case VictoryArtifacts:
        T_Scenario::Set_Multi_Artifacts((T_Scenario *)this->_padding_,iVar19);
        break;
      case VictoryDiscoveries:
        T_Scenario::Set_Multi_Discoveries((T_Scenario *)this->_padding_,iVar19);
        break;
      case VictoryGold:
        T_Scenario::Set_Multi_Gold((T_Scenario *)this->_padding_,iVar19);
        break;
      case VictoryTime:
        this->victory_type = 2;
        T_Scenario::Set_Multi_Conquest((T_Scenario *)this->_padding_,1);
        break;
      case VictoryScore:
        this->victory_type = 3;
        T_Scenario::Set_Multi_Conquest((T_Scenario *)this->_padding_,1);
      }
      T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->_padding_,0);
      VVar7 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
      if (VVar7 == VictoryTime) {
        this->countdown_victory = '\x01';
        this->countdown_clock = (float)iVar19;
      }
      else if ((VVar7 == VictoryScore) && (iVar12 = 1, 1 < (short)this->_padding_)) {
        do {
          RGE_Victory_Conditions::add_victory_points
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar12 * 4) + 0x34),
                     '\0',iVar19,'\x01');
          iVar12 = iVar12 + 1;
        } while (iVar12 < (short)this->_padding_);
      }
    }
    else {
      iVar19 = RGE_Base_Game::campaignGame(rge_base_game);
      if ((iVar19 != 0) || (iVar19 = RGE_Base_Game::scenarioGame(rge_base_game), iVar19 != 0)) {
        iVar19 = T_Scenario::GetMPVictory((T_Scenario *)this->_padding_);
        switch(iVar19) {
        case 0:
          this->victory_type = 0;
          break;
        case 1:
          this->victory_type = 1;
          break;
        case 2:
          this->victory_type = 3;
          iVar19 = T_Scenario::GetVictoryScore((T_Scenario *)this->_padding_);
          iVar12 = 1;
          if (1 < (short)this->_padding_) {
            do {
              RGE_Victory_Conditions::add_victory_points
                        (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar12 * 4) + 0x34)
                         ,'\0',iVar19,'\x01');
              iVar12 = iVar12 + 1;
            } while (iVar12 < (short)this->_padding_);
          }
          break;
        case 3:
          this->victory_type = 2;
          this->countdown_victory = '\x01';
          iVar19 = T_Scenario::GetVictoryTime((T_Scenario *)this->_padding_);
          this->countdown_clock = (float)iVar19;
        }
      }
    }
    this_00 = (RGE_RMM_Object_Generator *)operator_new(0x1920);
    uStack_4 = 0;
    if (this_00 == (RGE_RMM_Object_Generator *)0x0) {
      pRStack_1314 = (RGE_RMM_Object_Generator *)0x0;
    }
    else {
      pcStack_133c = (char *)0x52f9e8;
      pRStack_1314 = (RGE_RMM_Object_Generator *)
                     RGE_RMM_Object_Generator::RGE_RMM_Object_Generator
                               (this_00,(RGE_Map *)this->_padding_,(RGE_Random_Map_Module *)0x0,
                                (RGE_Game_World *)this,(RGE_Object_Info *)0x0,'\0');
    }
    uStack_4 = 0xffffffff;
    iVar19 = T_Scenario::Get_Multi_Artifacts((T_Scenario *)this->_padding_);
    if (0 < iVar19) {
      iVar17 = (int)(short)this->_padding_;
      iVar12 = 0;
      if (0 < iVar17) {
        piVar18 = (int *)this->_padding_;
        do {
          for (piVar3 = *(int **)(*(int *)(*piVar18 + 0x28) + 4); piVar3 != (int *)0x0;
              piVar3 = (int *)piVar3[1]) {
            if (*(short *)(*(int *)(*piVar3 + 8) + 0x10) == 0x9f) {
              iVar12 = iVar12 + 1;
            }
          }
          piVar18 = piVar18 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      if (0 < iVar19 - iVar12) {
        RGE_RMM_Object_Generator::add_quick_obj(pRStack_1314,0x9f,iVar19 - iVar12,0);
      }
    }
    iVar19 = T_Scenario::Get_Multi_Discoveries((T_Scenario *)this->_padding_);
    if (0 < iVar19) {
      iVar17 = (int)(short)this->_padding_;
      iVar12 = 0;
      if (0 < iVar17) {
        piVar18 = (int *)this->_padding_;
        do {
          for (piVar3 = *(int **)(*(int *)(*piVar18 + 0x28) + 4); piVar3 != (int *)0x0;
              piVar3 = (int *)piVar3[1]) {
            if (*(short *)(*(int *)(*piVar3 + 8) + 0x10) == 10) {
              iVar12 = iVar12 + 1;
            }
          }
          piVar18 = piVar18 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      if (0 < iVar19 - iVar12) {
        RGE_RMM_Object_Generator::add_quick_obj(pRStack_1314,10,iVar19 - iVar12,0);
      }
    }
    iVar19 = T_Scenario::Get_Multi_Ruins((T_Scenario *)this->_padding_);
    if (0 < iVar19) {
      iVar17 = (int)(short)this->_padding_;
      iVar12 = 0;
      if (0 < iVar17) {
        piVar18 = (int *)this->_padding_;
        do {
          for (piVar3 = *(int **)(*(int *)(*piVar18 + 0x28) + 4); piVar3 != (int *)0x0;
              piVar3 = (int *)piVar3[1]) {
            sVar2 = *(short *)(*(int *)(*piVar3 + 8) + 0x10);
            if ((sVar2 == 0x9e) || (sVar2 == 0xa3)) {
              iVar12 = iVar12 + 1;
            }
          }
          piVar18 = piVar18 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      if (0 < iVar19 - iVar12) {
        RGE_RMM_Object_Generator::add_quick_obj(pRStack_1314,0x9e,iVar19 - iVar12,0);
      }
    }
    iVar19 = RGE_Base_Game::campaignGame(rge_base_game);
    if ((iVar19 == 0) && (iVar19 = RGE_Base_Game::randomGame(rge_base_game), iVar19 != 0)) {
      if ((this->victory_type == 3) ||
         (iVar19 = debug_rand(s_C__msdev_work_age1_x1_tworld_cpp,0x38d), iVar19 % 100 < 0x32)) {
        RGE_RMM_Object_Generator::add_quick_obj
                  (pRStack_1314,0x9f,5,*(int *)(this->_padding_ + 8) / 5);
        this->artifact_count = 5;
      }
      iVar19 = debug_rand(s_C__msdev_work_age1_x1_tworld_cpp,0x394);
      if (iVar19 % 100 < 0x32) {
        RGE_RMM_Object_Generator::add_quick_obj
                  (pRStack_1314,0x9e,5,*(int *)(this->_padding_ + 8) / 5);
        this->ruin_count = 5;
      }
    }
    else {
      iVar19 = (int)(short)this->_padding_;
      this->artifact_count = 0;
      if (0 < iVar19) {
        piVar18 = (int *)this->_padding_;
        iVar12 = iVar19;
        do {
          for (piVar3 = *(int **)(*(int *)(*piVar18 + 0x28) + 4); piVar3 != (int *)0x0;
              piVar3 = (int *)piVar3[1]) {
            if (*(short *)(*(int *)(*piVar3 + 8) + 0x10) == 0x9f) {
              this->artifact_count = this->artifact_count + 1;
            }
          }
          piVar18 = piVar18 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      this->ruin_count = 0;
      if (0 < iVar19) {
        piVar18 = (int *)this->_padding_;
        do {
          for (piVar3 = *(int **)(*(int *)(*piVar18 + 0x28) + 4); piVar3 != (int *)0x0;
              piVar3 = (int *)piVar3[1]) {
            sVar2 = *(short *)(*(int *)(*piVar3 + 8) + 0x10);
            if ((sVar2 == 0x9e) || (sVar2 == 0xa3)) {
              this->ruin_count = this->ruin_count + 1;
            }
          }
          piVar18 = piVar18 + 1;
          iVar19 = iVar19 + -1;
        } while (iVar19 != 0);
      }
    }
    (**(code **)pRStack_1314->_padding_)();
    if (pRStack_1314 != (RGE_RMM_Object_Generator *)0x0) {
      RGE_Random_Map_Module::~RGE_Random_Map_Module((RGE_Random_Map_Module *)pRStack_1314);
      operator_delete(pRStack_1314);
    }
  }
  iVar19 = TRIBE_Game::allowTrading((TRIBE_Game *)rge_base_game);
  if ((iVar19 == 0) && (iVar19 = 1, 1 < (short)this->_padding_)) {
    do {
      (**(code **)(*(int *)this->_padding_ + 8))();
      iVar19 = iVar19 + 1;
    } while (iVar19 < (short)this->_padding_);
  }
  iVar19 = TRIBE_Game::longCombat((TRIBE_Game *)rge_base_game);
  if ((iVar19 == 1) && (iVar19 = 1, 1 < (short)this->_padding_)) {
    do {
      (**(code **)(*(int *)this->_padding_ + 8))();
      iVar19 = iVar19 + 1;
    } while (iVar19 < (short)this->_padding_);
  }
  iVar19 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  if ((iVar19 == 0) &&
     (iVar19 = T_Scenario::GetScenarioOption((T_Scenario *)this->_padding_,2), iVar19 == 0)) {
    iVar19 = 1;
    if (1 < (short)this->_padding_) {
      do {
        (**(code **)(*(int *)this->_padding_ + 8))();
        iVar19 = iVar19 + 1;
      } while (iVar19 < (short)this->_padding_);
    }
  }
  else {
    iVar19 = 1;
    if (1 < (short)this->_padding_) {
      do {
        (**(code **)(*(int *)this->_padding_ + 8))();
        iVar19 = iVar19 + 1;
      } while (iVar19 < (short)this->_padding_);
    }
  }
  RVar11 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  if (RVar11 == LowResource) {
    iVar19 = 1;
    if (1 < (short)this->_padding_) {
      do {
        iVar19 = iVar19 + 1;
        **(undefined4 **)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) = 0x43480000;
        *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 4) =
             0x43480000;
        *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 0xc) = 0;
        *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 8) =
             0x42c80000;
      } while (iVar19 < (short)this->_padding_);
    }
  }
  else if (RVar11 == MediumResources) {
    iVar19 = 1;
    if (1 < (short)this->_padding_) {
      do {
        iVar19 = iVar19 + 1;
        **(undefined4 **)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) = 0x43fa0000;
        *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 4) =
             0x43fa0000;
        *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 0xc) = 0;
        *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 8) =
             0x437a0000;
      } while (iVar19 < (short)this->_padding_);
    }
  }
  else if ((RVar11 == HighResources) && (iVar19 = 1, 1 < (short)this->_padding_)) {
    do {
      iVar19 = iVar19 + 1;
      **(undefined4 **)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) = 0x447a0000;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 4) = 0x447a0000
      ;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 0xc) = 0;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 8) = 0x443b8000
      ;
    } while (iVar19 < (short)this->_padding_);
  }
  uVar4 = TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game);
  if ((uVar4 != '\0') && (iVar19 = 1, 1 < (short)this->_padding_)) {
    do {
      iVar19 = iVar19 + 1;
      **(undefined4 **)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) = 0x469c4000;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 4) = 0x469c4000
      ;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 0xc) =
           0x461c4000;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar19 * 4) + 0x50) + 8) = 0x459c4000
      ;
    } while (iVar19 < (short)this->_padding_);
  }
  AVar10 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if (AVar10 == ToolAge) {
    iVar19 = 1;
    if (1 < (short)this->_padding_) {
      do {
        TRIBE_Player::rev_tech(*(TRIBE_Player **)(this->_padding_ + iVar19 * 4),0x19);
        iVar19 = iVar19 + 1;
      } while (iVar19 < (short)this->_padding_);
    }
  }
  else if (AVar10 == BronzeAge) {
    iVar19 = 1;
    if (1 < (short)this->_padding_) {
      do {
        TRIBE_Player::rev_tech(*(TRIBE_Player **)(this->_padding_ + iVar19 * 4),0x17);
        iVar19 = iVar19 + 1;
      } while (iVar19 < (short)this->_padding_);
    }
  }
  else if ((AVar10 == IronAge) && (iVar19 = 1, 1 < (short)this->_padding_)) {
    do {
      TRIBE_Player::rev_tech(*(TRIBE_Player **)(this->_padding_ + iVar19 * 4),0x18);
      iVar19 = iVar19 + 1;
    } while (iVar19 < (short)this->_padding_);
  }
  uVar4 = RGE_Base_Game::check_prog_argument(rge_base_game,s_NOFOODCAP);
  if (uVar4 == '\0') {
    uVar4 = RGE_Base_Game::check_prog_argument(rge_base_game,s_SYSTEM2);
    iVar19 = 1;
    if (uVar4 == '\0') {
      if (1 < (short)this->_padding_) {
        do {
          bVar5 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
          RGE_Player::new_attribute_num
                    (*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x20,(float)bVar5);
          RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x21,0.0);
          RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x1e,500.0);
          RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x2d,1.0);
          pcStack_133c = (char *)0x53009c;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\0','\0',0x14,2,1);
          pcStack_133c = (char *)0x5300b1;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\0','\x01',0x2b,1,1);
          pcStack_133c = (char *)0x5300c7;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\0','\x02',0x2c,1,1);
          pcStack_133c = (char *)0x5300de;
          RGE_Victory_Conditions::add_points_high_attribute_once
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\0','\x03',0x28,1,0x19);
          pcStack_133c = (char *)0x5300f4;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x01','\x04',0x31,100,1);
          pcStack_133c = (char *)0x53010a;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x01','\t',0x35,0x3c,1);
          pcStack_133c = (char *)0x53011f;
          RGE_Victory_Conditions::add_points_high_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x01','\x05',0x25,1,1);
          pcStack_133c = (char *)0x530135;
          RGE_Victory_Conditions::add_points_high_attribute_once
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x01','\x06',0x25,1,0x19);
          pcStack_133c = (char *)0x53014b;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x01','\a',0x16,3,1);
          iVar12 = RGE_Base_Game::fullVisibility(rge_base_game);
          if (iVar12 == 0) {
            pcStack_133c = (char *)0x530170;
            RGE_Victory_Conditions::add_points_highest_attribute
                      (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                       '\x01','\b',0x16,1,0x19);
          }
          pcStack_133c = (char *)0x530187;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x02','\n',0x29,1,2);
          pcStack_133c = (char *)0x53019e;
          RGE_Victory_Conditions::add_points_highest_attribute
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x02','\v',0x29,1,0x19);
          pcStack_133c = (char *)0x5301b5;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x02','\f',0xe,1,10);
          pcStack_133c = (char *)0x5301cc;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x02','\r',7,1,10);
          pcStack_133c = (char *)0x5301e3;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x02','\x0e',0x34,1,3);
          pcStack_133c = (char *)0x5301fa;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x02','\x10',0x37,1,0x32);
          pcStack_133c = (char *)0x530211;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x02','\x0f',0x36,1,0x32);
          pcStack_133c = (char *)0x530228;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x03','\x11',0x15,1,2);
          pcStack_133c = (char *)0x53023f;
          RGE_Victory_Conditions::add_points_highest_attribute
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x03','\x12',0x15,1,0x32);
          pcStack_133c = (char *)0x530257;
          RGE_Victory_Conditions::add_points_attribute_first
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x03','\x13',6,3,0x19);
          pcStack_133c = (char *)0x53026f;
          RGE_Victory_Conditions::add_points_attribute_first
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x03','\x14',6,4,0x19);
          pcStack_133c = (char *)0x530286;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x04','\x16',0x2d,1,100);
          pcStack_133c = (char *)0x53029d;
          RGE_Victory_Conditions::add_points_attribute_amount
                    (*(RGE_Victory_Conditions **)(*(int *)(this->_padding_ + iVar19 * 4) + 0x34),
                     '\x04','\x17',0x2a,1,100);
          TRIBE_Player::add_population_entry(*(TRIBE_Player **)(this->_padding_ + iVar19 * 4));
          iVar19 = iVar19 + 1;
        } while (iVar19 < (short)this->_padding_);
      }
    }
    else if (1 < (short)this->_padding_) {
      do {
        RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x20,50.0);
        RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x21,0.0);
        iVar19 = iVar19 + 1;
      } while (iVar19 < (short)this->_padding_);
    }
  }
  else {
    iVar19 = 1;
    if (1 < (short)this->_padding_) {
      do {
        RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x20,50.0);
        RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x21,0.0);
        RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x1e,500.0);
        RGE_Player::new_attribute_num(*(RGE_Player **)(this->_padding_ + iVar19 * 4),0x1f,5000.0);
        iVar19 = iVar19 + 1;
      } while (iVar19 < (short)this->_padding_);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return str1[3];
}

// --------------------------------------------------

// Function: new_scenario
// Address: 00530370
uchar __thiscall TRIBE_World::new_scenario(TRIBE_World *this,RGE_Player_Info *param_1,int param_2)
{
  uchar uVar1;
  int iVar2;
  
  uVar1 = RGE_Game_World::new_scenario((RGE_Game_World *)this,param_1,param_2);
  iVar2 = 1;
  if (1 < (short)this->_padding_) {
    do {
      iVar2 = iVar2 + 1;
      **(undefined4 **)(*(int *)(this->_padding_ + -4 + iVar2 * 4) + 0x50) = 0x43480000;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar2 * 4) + 0x50) + 4) = 0x43480000;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar2 * 4) + 0x50) + 0xc) = 0;
      *(undefined4 *)(*(int *)(*(int *)(this->_padding_ + -4 + iVar2 * 4) + 0x50) + 8) = 0x42c80000;
    } while (iVar2 < (short)this->_padding_);
  }
  return uVar1;
}

// --------------------------------------------------

// Function: check_game_state
// Address: 005303f0
uchar __thiscall TRIBE_World::check_game_state(TRIBE_World *this)
{
  TRIBE_Player *pTVar1;
  float fVar2;
  bool bVar3;
  uchar uVar4;
  long lVar5;
  int iVar6;
  TRIBE_Player **ppTVar7;
  int iVar8;
  RGE_Player *this_00;
  uint uVar9;
  uint uVar10;
  int iVar11;
  TRIBE_Player **ppTVar12;
  int iVar13;
  int *piVar14;
  int i;
  float held_time;
  int local_1a0;
  int team_count;
  int local_198;
  int team_size [9];
  int player_team [9];
  TRIBE_Player *team_player [9] [9];
  
  if (*(char *)((int)&this->_padding_ + 1) == '\0') {
    if ((((this->victory_type == 2) && (this->countdown_victory != '\0')) &&
        (_DAT_00577578 <= this->countdown_clock)) &&
       (fVar2 = this->countdown_clock - ((float)this->_padding_ + (float)this->_padding_),
       bVar3 = fVar2 < _DAT_00577578, this->countdown_clock = fVar2, bVar3)) {
      iVar11 = 1;
      iVar13 = this->_padding_;
      piVar14 = team_size;
      for (iVar8 = 9; piVar14 = piVar14 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
        *piVar14 = -1;
      }
      if (1 < (short)iVar13) {
        do {
          piVar14 = team_size + iVar11 + 1;
          lVar5 = RGE_Victory_Conditions::get_victory_points
                            (*(RGE_Victory_Conditions **)
                              (*(int *)(this->_padding_ + iVar11 * 4) + 0x34));
          iVar13 = this->_padding_;
          *piVar14 = lVar5;
          held_time = 1.4013e-45;
          if ((*(char *)(*(int *)(iVar13 + iVar11 * 4) + 0x104) != '\0') &&
             (iVar13 = 1, 1 < (short)this->_padding_)) {
            do {
              if (((iVar13 != iVar11) &&
                  ((uVar4 = RGE_Player::relation
                                      (*(RGE_Player **)(this->_padding_ + iVar11 * 4),iVar13),
                   uVar4 == '\0' &&
                   (uVar4 = RGE_Player::relation
                                      (*(RGE_Player **)(this->_padding_ + iVar13 * 4),iVar11),
                   uVar4 == '\0')))) &&
                 (iVar8 = *(int *)(this->_padding_ + iVar13 * 4), *(char *)(iVar8 + 0x104) != '\0'))
{
                lVar5 = RGE_Victory_Conditions::get_victory_points
                                  (*(RGE_Victory_Conditions **)(iVar8 + 0x34));
                held_time = (float)((int)held_time + 1);
                *piVar14 = *piVar14 + lVar5;
              }
              iVar13 = iVar13 + 1;
            } while (iVar13 < (short)this->_padding_);
          }
          iVar13 = this->_padding_;
          iVar11 = iVar11 + 1;
          *piVar14 = *piVar14 / (int)held_time;
        } while (iVar11 < (short)iVar13);
      }
      iVar11 = (int)(short)this->_padding_;
      iVar8 = 1;
      this_00 = (RGE_Player *)0x0;
      iVar13 = -1;
      if (1 < iVar11) {
        do {
          if (iVar13 < team_size[iVar8 + 1]) {
            this_00 = *(RGE_Player **)(this->_padding_ + iVar8 * 4);
            iVar13 = team_size[iVar8 + 1];
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar11);
      }
      if (this_00 != (RGE_Player *)0x0) {
        RGE_Player::win_game_now(this_00);
        *(undefined1 *)((int)&this->_padding_ + 2) = 0x67;
      }
    }
    if ((0 < this->artifact_count) || (0 < this->ruin_count)) {
      uVar10 = (uint)(short)this->_padding_;
      if (0 < (int)uVar10) {
        piVar14 = team_size;
        for (uVar9 = uVar10 & 0x3fffffff; piVar14 = piVar14 + 1, uVar9 != 0; uVar9 = uVar9 - 1) {
          *piVar14 = 0;
        }
        piVar14 = player_team;
        for (uVar9 = uVar10 & 0x3fffffff; piVar14 = piVar14 + 1, uVar9 != 0; uVar9 = uVar9 - 1) {
          *piVar14 = -1;
        }
      }
      local_198 = 0;
      held_time = 1.4013e-45;
      if (1 < (int)uVar10) {
        team_count = 0;
        piVar14 = team_size + 1;
        do {
          if (player_team[(int)held_time + 1] == -1) {
            player_team[(int)held_time + 1] = local_198;
            iVar8 = *piVar14;
            pTVar1 = *(TRIBE_Player **)(this->_padding_ + (int)held_time * 4);
            team_player[0][iVar8 + team_count + 1] = pTVar1;
            iVar13 = iVar8 + 1;
            iVar11 = pTVar1->_padding_;
            *piVar14 = iVar13;
            if (((char)iVar11 != '\0') && (local_1a0 = 1, 1 < (int)uVar10)) {
              ppTVar12 = team_player[0] + iVar8 + team_count + 2;
              do {
                ppTVar7 = ppTVar12;
                if ((((player_team[local_1a0 + 1] == -1) &&
                     (*(char *)(*(int *)(this->_padding_ + local_1a0 * 4) + 0x104) != '\0')) &&
                    (uVar4 = RGE_Player::relation
                                       (*(RGE_Player **)(this->_padding_ + (int)held_time * 4),
                                        local_1a0), uVar4 == '\0')) &&
                   (uVar4 = RGE_Player::relation
                                      (*(RGE_Player **)(this->_padding_ + local_1a0 * 4),
                                       (long)held_time), uVar4 == '\0')) {
                  iVar8 = this->_padding_;
                  iVar13 = iVar13 + 1;
                  player_team[local_1a0 + 1] = local_198;
                  ppTVar7 = ppTVar12 + 1;
                  pTVar1 = *(TRIBE_Player **)(iVar8 + local_1a0 * 4);
                  *piVar14 = iVar13;
                  *ppTVar12 = pTVar1;
                }
                local_1a0 = local_1a0 + 1;
                ppTVar12 = ppTVar7;
              } while (local_1a0 < (short)this->_padding_);
            }
            local_198 = local_198 + 1;
            team_count = team_count + 9;
            piVar14 = piVar14 + 1;
          }
          uVar10 = (uint)(short)this->_padding_;
          held_time = (float)((int)held_time + 1);
        } while ((int)held_time < (int)uVar10);
      }
      if ((0 < this->artifact_count) && (0 < local_198)) {
        ppTVar12 = team_player[0] + 1;
        team_count = (int)team_size;
        team_size[0] = local_198;
        do {
          team_count = team_count + 4;
          iVar11 = 0;
          iVar13 = *(int *)team_count;
          iVar8 = iVar13;
          if (0 < iVar13) {
            do {
              iVar6 = __ftol();
              iVar11 = iVar11 + iVar6;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          if (iVar11 == this->artifact_count) {
            pTVar1 = *ppTVar12;
            fVar2 = pTVar1->artifact_held_time;
            if (fVar2 == _DAT_00577580) {
              ppTVar7 = ppTVar12;
              iVar8 = iVar13;
              if (0 < iVar13) {
                do {
                  iVar8 = iVar8 + -1;
                  *(undefined4 *)((*ppTVar7)->_padding_ + 0xdc) = 0x3f800000;
                  ppTVar7 = ppTVar7 + 1;
                } while (iVar8 != 0);
              }
              if (this->victory_type == 0) {
                ppTVar7 = ppTVar12;
                if (0 < iVar13) {
                  do {
                    iVar13 = iVar13 + -1;
                    (*ppTVar7)->artifact_held_time = 2000.0;
                    ppTVar7 = ppTVar7 + 1;
                  } while (iVar13 != 0);
                }
                (**(code **)(rge_base_game->_padding_ + 0x40))
                          (0x72,(int)*(short *)((int)&pTVar1->_padding_ + 2),0,0,0);
              }
            }
            else if ((_DAT_00577578 <= fVar2) && (this->victory_type == 0)) {
              fVar2 = fVar2 - ((float)this->_padding_ + (float)this->_padding_);
              ppTVar7 = ppTVar12;
              if (0 < iVar13) {
                do {
                  iVar13 = iVar13 + -1;
                  (*ppTVar7)->artifact_held_time = fVar2;
                  ppTVar7 = ppTVar7 + 1;
                } while (iVar13 != 0);
              }
              if (fVar2 < _DAT_00577578) {
                RGE_Player::win_game_now((RGE_Player *)pTVar1);
                *(undefined1 *)((int)&this->_padding_ + 2) = 0x65;
              }
            }
          }
          else {
            pTVar1 = *ppTVar12;
            if (pTVar1->artifact_held_time != -1.0) {
              ppTVar7 = ppTVar12;
              iVar8 = iVar13;
              if (0 < iVar13) {
                do {
                  iVar8 = iVar8 + -1;
                  *(undefined4 *)((*ppTVar7)->_padding_ + 0xdc) = 0;
                  ppTVar7 = ppTVar7 + 1;
                } while (iVar8 != 0);
              }
              if (this->victory_type == 0) {
                ppTVar7 = ppTVar12;
                if (0 < iVar13) {
                  do {
                    iVar13 = iVar13 + -1;
                    (*ppTVar7)->artifact_held_time = -1.0;
                    ppTVar7 = ppTVar7 + 1;
                  } while (iVar13 != 0);
                }
                (**(code **)(rge_base_game->_padding_ + 0x40))
                          (0x73,(int)*(short *)((int)&pTVar1->_padding_ + 2),0,0,0);
              }
            }
          }
          ppTVar12 = ppTVar12 + 9;
          team_size[0] = team_size[0] + -1;
        } while (team_size[0] != 0);
      }
      if ((0 < this->ruin_count) && (0 < local_198)) {
        ppTVar12 = team_player[0] + 1;
        team_count = (int)team_size;
        team_size[0] = local_198;
        do {
          team_count = team_count + 4;
          iVar11 = 0;
          iVar13 = *(int *)team_count;
          iVar8 = iVar13;
          if (0 < iVar13) {
            do {
              iVar6 = __ftol();
              iVar11 = iVar11 + iVar6;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          if (iVar11 == this->ruin_count) {
            pTVar1 = *ppTVar12;
            fVar2 = pTVar1->ruin_held_time;
            if (fVar2 == _DAT_00577580) {
              ppTVar7 = ppTVar12;
              iVar8 = iVar13;
              if (0 < iVar13) {
                do {
                  iVar8 = iVar8 + -1;
                  *(undefined4 *)((*ppTVar7)->_padding_ + 0xd8) = 0x3f800000;
                  ppTVar7 = ppTVar7 + 1;
                } while (iVar8 != 0);
              }
              if (this->victory_type == 0) {
                ppTVar7 = ppTVar12;
                if (0 < iVar13) {
                  do {
                    iVar13 = iVar13 + -1;
                    (*ppTVar7)->ruin_held_time = 2000.0;
                    ppTVar7 = ppTVar7 + 1;
                  } while (iVar13 != 0);
                }
                (**(code **)(rge_base_game->_padding_ + 0x40))
                          (0x74,(int)*(short *)((int)&pTVar1->_padding_ + 2),0,0,0);
              }
            }
            else if ((_DAT_00577578 <= fVar2) && (this->victory_type == 0)) {
              fVar2 = fVar2 - ((float)this->_padding_ + (float)this->_padding_);
              ppTVar7 = ppTVar12;
              if (0 < iVar13) {
                do {
                  iVar13 = iVar13 + -1;
                  (*ppTVar7)->ruin_held_time = fVar2;
                  ppTVar7 = ppTVar7 + 1;
                } while (iVar13 != 0);
              }
              if (fVar2 < _DAT_00577578) {
                RGE_Player::win_game_now((RGE_Player *)pTVar1);
                *(undefined1 *)((int)&this->_padding_ + 2) = 0x66;
              }
            }
          }
          else {
            pTVar1 = *ppTVar12;
            if (pTVar1->ruin_held_time != -1.0) {
              ppTVar7 = ppTVar12;
              iVar8 = iVar13;
              if (0 < iVar13) {
                do {
                  iVar8 = iVar8 + -1;
                  *(undefined4 *)((*ppTVar7)->_padding_ + 0xd8) = 0;
                  ppTVar7 = ppTVar7 + 1;
                } while (iVar8 != 0);
              }
              if (this->victory_type == 0) {
                ppTVar7 = ppTVar12;
                if (0 < iVar13) {
                  do {
                    iVar13 = iVar13 + -1;
                    (*ppTVar7)->ruin_held_time = -1.0;
                    ppTVar7 = ppTVar7 + 1;
                  } while (iVar13 != 0);
                }
                (**(code **)(rge_base_game->_padding_ + 0x40))
                          (0x75,(int)*(short *)((int)&pTVar1->_padding_ + 2),0,0,0);
              }
            }
          }
          ppTVar12 = ppTVar12 + 9;
          team_size[0] = team_size[0] + -1;
        } while (team_size[0] != 0);
        team_size[0] = 0;
      }
    }
  }
  uVar4 = RGE_Game_World::check_game_state((RGE_Game_World *)this);
  return uVar4;
}

// --------------------------------------------------

// Function: get_achievement
// Address: 00530a70
long __thiscall TRIBE_World::get_achievement(TRIBE_World *this,uchar param_1,char **param_2)
{
  TRIBE_Player *this_00;
  int iVar1;
  
  iVar1 = 1;
  if (1 < (short)this->_padding_) {
    do {
      this_00 = *(TRIBE_Player **)(this->_padding_ + iVar1 * 4);
      if (this_00 != (TRIBE_Player *)0x0) {
        TRIBE_Player::get_achievement(this_00,param_1,param_2[iVar1]);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < (short)this->_padding_);
  }
  return (int)(short)this->_padding_;
}

// --------------------------------------------------

// Function: send_cheat
// Address: 00530ac0
void __thiscall TRIBE_World::send_cheat(TRIBE_World *this,short param_1)
{
  TRIBE_Command::command_cheat((TRIBE_Command *)this->_padding_,(short)this->_padding_,param_1);
  return;
}

// --------------------------------------------------

// Function: cheat
// Address: 00530ae0
// [HELPER] die_die_die: " "
void __thiscall TRIBE_World::cheat(TRIBE_World *this,short param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int *piVar5;
  int iVar6;
  
  iVar2 = RGE_Base_Game::allowCheatCodes(rge_base_game);
  if (iVar2 != 0) {
    switch((int)param_2) {
    case 0:
      if ((0 < param_1) &&
         (pRVar4 = RGE_Object_List::find_by_master_id
                             (*(RGE_Object_List **)(*(int *)(this->_padding_ + param_1 * 4) + 0x28),
                              0x6d,-1.0,-1.0,'\x01','\x02',(RGE_Static_Object *)0x0),
         pRVar4 != (RGE_Static_Object *)0x0)) {
        TRIBE_Command::command_make((TRIBE_Command *)this->_padding_,pRVar4,0x112);
        return;
      }
      break;
    case 1:
      if ((0 < param_1) &&
         (pRVar4 = RGE_Object_List::find_by_master_id
                             (*(RGE_Object_List **)(*(int *)(this->_padding_ + param_1 * 4) + 0x28),
                              0x6d,-1.0,-1.0,'\x01','\x02',(RGE_Static_Object *)0x0),
         pRVar4 != (RGE_Static_Object *)0x0)) {
        TRIBE_Command::command_make((TRIBE_Command *)this->_padding_,pRVar4,0xf8);
        return;
      }
      break;
    case 2:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x7f,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 3:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x80,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 4:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x81,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 5:
      (**(code **)(*(int *)this->_padding_ + 8))(0x82,*(undefined4 *)this->_padding_);
      return;
    case 6:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x83,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 7:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x84,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 8:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x85,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 9:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x86,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 10:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x87,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 0xb:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x88,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 0xc:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x89,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 0xd:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0x8a,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 0xe:
      if ((0 < param_1) &&
         (pRVar4 = RGE_Object_List::find_by_master_id
                             (*(RGE_Object_List **)(*(int *)(this->_padding_ + param_1 * 4) + 0x28),
                              0x6d,-1.0,-1.0,'\x01','\x02',(RGE_Static_Object *)0x0),
         pRVar4 != (RGE_Static_Object *)0x0)) {
        TRIBE_Command::command_make((TRIBE_Command *)this->_padding_,pRVar4,0x182);
        return;
      }
      break;
    case 0xf:
      if (0 < param_1) {
        (**(code **)(*(int *)this->_padding_ + 8))
                  (0xd7,*(undefined4 *)(this->_padding_ + param_1 * 4));
        return;
      }
      break;
    case 0x10:
      if ((0 < param_1) &&
         (pRVar4 = RGE_Object_List::find_by_master_id
                             (*(RGE_Object_List **)(*(int *)(this->_padding_ + param_1 * 4) + 0x28),
                              0x6d,-1.0,-1.0,'\x01','\x02',(RGE_Static_Object *)0x0),
         pRVar4 != (RGE_Static_Object *)0x0)) {
        TRIBE_Command::command_make((TRIBE_Command *)this->_padding_,pRVar4,0x18d);
        return;
      }
      break;
    case 0x11:
      if (0 < param_1) {
        RGE_Object_List::find_by_master_id
                  (*(RGE_Object_List **)(*(int *)(this->_padding_ + param_1 * 4) + 0x28),0x6d,-1.0,
                   -1.0,'\x01','\x02',(RGE_Static_Object *)0x0);
        return;
      }
      break;
    case 0x12:
      (**(code **)(*(int *)this->_padding_ + 8))(0xd8,*(undefined4 *)this->_padding_);
      return;
    case 0x13:
      (**(code **)(*(int *)this->_padding_ + 8))(0xd9,*(undefined4 *)this->_padding_);
      return;
    case 100:
      iVar2 = 1;
      die_die_die = '\x01';
      if (1 < (short)this->_padding_) {
        iVar6 = (int)param_1;
        do {
          if (((iVar2 != iVar6) ||
              (iVar3 = (**(code **)(**(int **)(this->_padding_ + iVar6 * 4) + 0x1c))(iVar2),
              iVar3 == 0)) ||
             (iVar3 = (**(code **)(**(int **)(this->_padding_ + iVar2 * 4) + 0x1c))(iVar6),
             iVar3 == 0)) {
            for (piVar5 = *(int **)(*(int *)(*(int *)(this->_padding_ + iVar2 * 4) + 0x28) + 4);
                piVar5 != (int *)0x0; piVar5 = (int *)piVar5[1]) {
              piVar1 = (int *)*piVar5;
              if ((*(byte *)(piVar1 + 0x12) < 3) && (*(short *)(piVar1[2] + 0x14) != 1)) {
                (**(code **)(*piVar1 + 0x6c))();
              }
            }
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < (short)this->_padding_);
        return;
      }
      break;
    case 0x65:
      piVar5 = *(int **)(*(int *)(*(int *)(this->_padding_ + param_1 * 4) + 0x28) + 4);
      if (piVar5 != (int *)0x0) {
        do {
          piVar1 = (int *)*piVar5;
          if ((*(byte *)(piVar1 + 0x12) < 3) && (*(short *)(piVar1[2] + 0x14) != 1)) {
            (**(code **)(*piVar1 + 0x6c))();
          }
          piVar5 = (int *)piVar5[1];
        } while (piVar5 != (int *)0x0);
        return;
      }
      break;
    case 0x66:
      RGE_Player::win_game_now(*(RGE_Player **)(this->_padding_ + param_1 * 4));
      *(undefined1 *)((int)&this->_padding_ + 2) = 0x68;
      return;
    case 0x67:
      RGE_Player::loss_if_game_on(*(RGE_Player **)(this->_padding_ + param_1 * 4));
      return;
    case 200:
    case 0xc9:
    case 0xca:
    case 0xcb:
    case 0xcc:
    case 0xcd:
    case 0xce:
    case 0xcf:
    case 0xd0:
    case 0xd1:
      iVar6 = (int)param_1;
      iVar2 = param_2 + -200;
      if ((((iVar2 != iVar6) ||
           (iVar3 = (**(code **)(**(int **)(this->_padding_ + iVar6 * 4) + 0x1c))(iVar2), iVar3 == 0
           )) || (iVar6 = (**(code **)(**(int **)(this->_padding_ + iVar2 * 4) + 0x1c))(iVar6),
                 iVar6 == 0)) &&
         (piVar5 = *(int **)(*(int *)(*(int *)(this->_padding_ + iVar2 * 4) + 0x28) + 4),
         piVar5 != (int *)0x0)) {
        do {
          piVar1 = (int *)*piVar5;
          if ((*(byte *)(piVar1 + 0x12) < 3) && (*(short *)(piVar1[2] + 0x14) != 1)) {
            (**(code **)(*piVar1 + 0x6c))();
          }
          piVar5 = (int *)piVar5[1];
        } while (piVar5 != (int *)0x0);
        return;
      }
      break;
    case 0xdc:
      pRVar4 = RGE_Object_List::find_by_master_id
                         (*(RGE_Object_List **)(*(int *)(this->_padding_ + param_1 * 4) + 0x28),0x6d
                          ,-1.0,-1.0,'\x01','\x02',(RGE_Static_Object *)0x0);
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        TRIBE_Command::command_make((TRIBE_Command *)this->_padding_,pRVar4,0x174);
        return;
      }
      break;
    case 0xe6:
      RGE_Base_Game::set_map_visible(rge_base_game,'\x01');
      piVar5 = (int *)(**(code **)(rge_base_game->_padding_ + 0x2c))();
      (**(code **)(*piVar5 + 0x20))(2);
      piVar5 = (int *)(**(code **)(rge_base_game->_padding_ + 0x30))();
      (**(code **)(*piVar5 + 0x20))(2);
      return;
    case 0xe7:
      RGE_Base_Game::set_map_fog(rge_base_game,'\0');
      piVar5 = (int *)(**(code **)(rge_base_game->_padding_ + 0x2c))();
      (**(code **)(*piVar5 + 0x20))(2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: fill_in_score
// Address: 00531240
void __thiscall
TRIBE_World::fill_in_score(TRIBE_World *this,TRIBE_Zone_High_Score_Info *param_1,long param_2)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  long lVar9;
  char *pcVar10;
  long hi_player;
  int local_4;
  
  iVar7 = 1;
  lVar9 = 0;
  local_4 = 1;
  if (1 < (short)this->_padding_) {
    do {
      iVar3 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + iVar7 * 4));
      if (iVar3 == 0) {
        lVar4 = RGE_Victory_Conditions::get_victory_points_group
                          (*(RGE_Victory_Conditions **)
                            (*(int *)(this->_padding_ + iVar7 * 4) + 0x34),(uchar)param_2);
        if (lVar9 < lVar4) {
          lVar9 = RGE_Victory_Conditions::get_victory_points_group
                            (*(RGE_Victory_Conditions **)
                              (*(int *)(this->_padding_ + iVar7 * 4) + 0x34),(uchar)param_2);
          local_4 = iVar7;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (short)this->_padding_);
  }
  param_1->score = lVar9;
  iVar7 = local_4 * 4;
  param_1->civ = *(uchar *)(*(int *)(this->_padding_ + iVar7) + 0x54);
  uVar5 = 0xffffffff;
  pcVar8 = *(char **)(*(int *)(this->_padding_ + iVar7) + 0x44);
  do {
    pcVar10 = pcVar8;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar10 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar10;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  param_2 = 0;
  param_2._0_1_ = '\0';
  pcVar8 = pcVar10 + -uVar5;
  pcVar10 = param_1->player_name;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  iVar3 = 1;
  if (1 < (short)this->_padding_) {
    do {
      if (((iVar3 != local_4) &&
          (uVar2 = RGE_Player::relation(*(RGE_Player **)(this->_padding_ + iVar3 * 4),local_4),
          uVar2 == '\0')) &&
         (uVar2 = RGE_Player::relation(*(RGE_Player **)(this->_padding_ + iVar7),iVar3),
         uVar2 == '\0')) {
        param_2 = param_2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (short)this->_padding_);
  }
  param_1->num_allies = (uchar)param_2;
  return;
}

// --------------------------------------------------

// Function: send_zone_score_info
// Address: 00531350
void __thiscall TRIBE_World::send_zone_score_info(TRIBE_World *this)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  uchar *puVar7;
  int iVar8;
  long *plVar9;
  char *pcVar10;
  char *pcVar11;
  long count;
  int local_270;
  TRIBE_Game_Options options;
  TRIBE_Zone_Info info;
  
  if (this->sent_zone_score == 0) {
    this->sent_zone_score = 1;
    info.scenario_name[2] = '\0';
    local_270._0_1_ = '\0';
    iVar8 = 1;
    cVar1 = '\0';
    if (1 < (short)this->_padding_) {
      do {
        local_270._0_1_ = cVar1;
        iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(this->_padding_ + iVar8 * 4));
        if (iVar2 == 0) {
          info.scenario_name[2] = info.scenario_name[2] + '\x01';
        }
        else {
          local_270._0_1_ = (char)local_270 + '\x01';
        }
        iVar8 = iVar8 + 1;
        cVar1 = (char)local_270;
      } while (iVar8 < (short)this->_padding_);
    }
    info.scenario_name[3] = (char)local_270;
    pcVar3 = RGE_Scenario::Get_scenario_name((RGE_Scenario *)this->_padding_);
    uVar5 = 0xffffffff;
    pcVar11 = info.scenario_name;
    do {
      pcVar10 = pcVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar10 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar10;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar3 = pcVar10 + -uVar5;
    for (uVar6 = uVar5 >> 2; pcVar11 = pcVar11 + 4, uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
    }
    uVar6 = this->_padding_;
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar11 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar11 = pcVar11 + 1;
    }
    info.total_score.score = uVar6 / 1000;
    fill_in_score(this,(TRIBE_Zone_High_Score_Info *)&info.total_score.civ,0xff);
    fill_in_score(this,(TRIBE_Zone_High_Score_Info *)&info.religion_score.civ,2);
    fill_in_score(this,(TRIBE_Zone_High_Score_Info *)&info.economy_score.civ,1);
    fill_in_score(this,(TRIBE_Zone_High_Score_Info *)&info.combat_score.civ,0);
    fill_in_score(this,(TRIBE_Zone_High_Score_Info *)&info.research_score.civ,3);
    local_270 = 1;
    if (1 < (short)this->_padding_) {
      iVar8 = this->_padding_;
      puVar7 = &info.player_info[0].winner;
      do {
        options.mapSizeValue = (MapSize)(puVar7 + -0x10);
        uVar5 = 0xffffffff;
        pcVar11 = *(char **)(*(int *)(iVar8 + local_270 * 4) + 0x44);
        do {
          pcVar3 = pcVar11;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar3 = pcVar11 + 1;
          cVar1 = *pcVar11;
          pcVar11 = pcVar3;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        plVar9 = (long *)(pcVar3 + -uVar5);
        pcVar11 = (char *)options.mapSizeValue;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(long *)pcVar11 = *plVar9;
          plVar9 = plVar9 + 1;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar11 = (char)*plVar9;
          plVar9 = (long *)((int)plVar9 + 1);
          pcVar11 = pcVar11 + 1;
        }
        lVar4 = RGE_Victory_Conditions::get_victory_points
                          (*(RGE_Victory_Conditions **)(*(int *)(iVar8 + local_270 * 4) + 0x34));
        *(long *)puVar7 = lVar4;
        iVar8 = local_270 + -1;
        puVar7[4] = *(char *)(*(int *)(this->_padding_ + local_270 * 4) + 0x80) == '\x01';
        iVar2 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game,iVar8);
        puVar7[5] = (uchar)iVar2;
        puVar7[6] = rge_base_game[1].save_music_file[local_270 * 4 + -0x50];
        iVar2 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game,iVar8);
        puVar7[7] = (char)iVar2;
        iVar2 = RGE_Base_Game::playerTeam(rge_base_game,iVar8);
        iVar8 = this->_padding_;
        puVar7[8] = (char)iVar2;
        puVar7[9] = (char)comm->WasKicked[local_270 + -1];
        *(long *)(puVar7 + 0xc) = -1;
        *(long *)(puVar7 + 0x10) = -1;
        *(long *)(puVar7 + 0x14) = -1;
        for (pcVar11 = *(char **)(*(int *)(*(int *)(iVar8 + local_270 * 4) + 0x83c) + 4);
            pcVar11 != (char *)0x0; pcVar11 = *(char **)(pcVar11 + 0xc)) {
          cVar1 = *pcVar11;
          if (cVar1 == '\0') {
            *(long *)(puVar7 + 0xc) = *(long *)(pcVar11 + 8);
          }
          else if (cVar1 == '\x01') {
            *(long *)(puVar7 + 0x10) = *(long *)(pcVar11 + 8);
          }
          else if (cVar1 == '\x02') {
            *(long *)(puVar7 + 0x14) = *(long *)(pcVar11 + 8);
          }
        }
        local_270 = local_270 + 1;
        puVar7 = puVar7 + 0x28;
      } while (local_270 < (short)this->_padding_);
    }
    iVar8 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    info.database_checksum._0_1_ = (undefined1)iVar8;
    switch(*(undefined1 *)((int)&this->_padding_ + 2)) {
    case 0:
      info.database_checksum._1_1_ = 0;
      break;
    case 1:
      info.database_checksum._1_1_ = 1;
      break;
    case 2:
      info.database_checksum._1_1_ = 6;
      break;
    default:
      info.database_checksum._1_1_ = 8;
      break;
    case 100:
      info.database_checksum._1_1_ = 2;
      break;
    case 0x65:
      info.database_checksum._1_1_ = 3;
      break;
    case 0x66:
      info.database_checksum._1_1_ = 4;
      break;
    case 0x67:
      info.database_checksum._1_1_ = 5;
      break;
    case 0x68:
      info.database_checksum._1_1_ = 7;
    }
    TRIBE_Game::get_tribe_options
              ((TRIBE_Game *)rge_base_game,(TRIBE_Game_Options *)&options.mapTypeValue);
    info.map_info.Victory_Condition = (undefined1)options.mapTypeValue;
    info.map_info.Start_Age = (uchar)options.animalsValue;
    info.map_info.Fixed_Pos = (uchar)options.victoryAmountValue;
    info.map_info.Reveal_Map = options.startingUnitsValue;
    info.map_info.Death_Match = (undefined1)options.startingAgeValue;
    info.map_info._11_1_ = options.resourceLevelValue._1_1_;
    info.cheats_enabled = (undefined1)options.resourceLevelValue;
    iVar8 = RGE_Base_Game::fullVisibility(rge_base_game);
    info.game_end_condition_code = (uchar)iVar8;
    info._494_1_ = info.number_of_computer_players;
    info.map_info._6_2_ = ZEXT12((byte)info.scenario_name[0]);
    info.code_checksum = 0;
    info.program_version = 0;
    TCommunications_Handler::SendZoneMessage
              (*(TCommunications_Handler **)(this->_padding_ + 0x14),info.scenario_name + 2,0x1fc);
  }
  return;
}

// --------------------------------------------------

