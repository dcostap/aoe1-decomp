#ifndef AOE1_TWORLD_PREFIX_CONTEXT_H
#define AOE1_TWORLD_PREFIX_CONTEXT_H

// Canonical tworld.cpp reconstruction context.
// Layout facts come from inventory/types/all_types_reference.h.
typedef unsigned char uchar;
typedef void FILE;

class AIPlayBook;
class RGE_Map;
class RGE_Sound;
class RGE_Player;
class RGE_Player_Info;
class RGE_Master_Player;
class RGE_Effects;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Scenario;
class RGE_Static_Object;
class RGE_Command;
class RGE_Sprite;
class TSound_Driver;
class TCommunications_Handler;
class TRIBE_Tech;
class TRIBE_Player;

class RGE_Game_World {
public:
    virtual uchar data_load_world(FILE*);
    virtual uchar data_load_terrain_tables(char*);
    virtual uchar data_load_players(char*);
    virtual uchar data_load_objects(char*);
    virtual uchar data_load_sounds(char*);
    virtual uchar data_load_color_tables(char*);
    virtual uchar data_load_sprites(char*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual uchar init_player_type(int, short, uchar);
    virtual uchar init_player(int);
    virtual void load_player(int, uchar, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual uchar new_random_game(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual void scenario_make_map(int);
    virtual uchar load_scenario(char*, RGE_Player_Info*);
protected:
    virtual uchar load_scenario(RGE_Player_Info&);
    virtual void load_scenario1(int, RGE_Player_Info&);
    virtual void load_scenario2(int, RGE_Player_Info&);
    virtual void load_scenario3(int, RGE_Player_Info&);
    virtual void load_scenario4(int, RGE_Player_Info&);
    virtual void load_scenario5(int, RGE_Player_Info&);
    virtual void load_scenario6(int, RGE_Player_Info&);
    virtual void load_scenario7(int, RGE_Player_Info&);
    virtual void load_scenario8(int, RGE_Player_Info&);
public:
    virtual void logStatus(FILE*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual void setup_player_colors();
    virtual uchar data_load(char*, char*);
    virtual uchar init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual uchar update();
    virtual uchar get_game_state();
    virtual uchar check_game_state();
    virtual uchar load_world(int);
    virtual uchar load_game(char*);
    virtual uchar new_game(RGE_Player_Info*, int);
    virtual uchar new_scenario(RGE_Player_Info&, int);
    virtual uchar save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual uchar save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(uchar);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    uchar temp_pause;
    uchar game_state;
    uchar game_end_condition;
    uchar gap_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    uchar gap_2E[2];
    RGE_Sound** sounds;
    short sprite_num;
    uchar gap_36[2];
    RGE_Sprite** sprites;
    short player_num;
    uchar gap_3E[2];
    RGE_Player** players;
    short master_player_num;
    uchar gap_46[2];
    RGE_Master_Player** master_players;
    RGE_Effects* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    RGE_Command* commands;
    RGE_Scenario* scenario;
    short color_table_num;
    uchar gap_62[2];
    RGE_Color_Table** color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    uchar scenario_object_flag;
    uchar gap_75[3];
    unsigned int random_seed;
    short curr_player;
    uchar gap_7E[2];
    TSound_Driver* sound_driver;
    float world_time_delta_seconds;
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    AIPlayBook* playbook;
    long campaign;
    long campaign_player;
    long campaign_scenario;
    int player_turn;
    unsigned long player_time_delta[9];
    RGE_Object_List* reusable_static_objects;
    RGE_Object_List* reusable_animated_objects;
    RGE_Object_List* reusable_moving_objects;
    RGE_Object_List* reusable_action_objects;
    RGE_Object_List* reusable_combat_objects;
    RGE_Object_List* reusable_missile_objects;
    RGE_Object_List* reusable_doppleganger_objects;
    unsigned long maximumComputerPlayerUpdateTime;
    unsigned long availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;
};

class TRIBE_World : public RGE_Game_World {
public:
    virtual uchar data_load_world(FILE*);
    virtual uchar data_load_terrain_tables(char*);
    virtual uchar data_load_players(char*);
    virtual uchar data_load_objects(char*);
    virtual uchar data_load_sounds(char*);
    virtual uchar data_load_color_tables(char*);
    virtual uchar data_load_sprites(char*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual uchar init_player_type(int, short, uchar);
    virtual uchar init_player(int);
    virtual void load_player(int, uchar, short);
    virtual void color_table_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual uchar new_random_game(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual void scenario_make_map(int);
    virtual uchar load_scenario(char*, RGE_Player_Info*);
protected:
    virtual uchar load_scenario(RGE_Player_Info&);
    virtual void load_scenario1(int, RGE_Player_Info&);
    virtual void load_scenario2(int, RGE_Player_Info&);
    virtual void load_scenario3(int, RGE_Player_Info&);
    virtual void load_scenario4(int, RGE_Player_Info&);
    virtual void load_scenario5(int, RGE_Player_Info&);
    virtual void load_scenario6(int, RGE_Player_Info&);
    virtual void load_scenario7(int, RGE_Player_Info&);
    virtual void load_scenario8(int, RGE_Player_Info&);
public:
    virtual void logStatus(FILE*, int);
    virtual ~TRIBE_World();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual void setup_player_colors();
    virtual uchar data_load(char*, char*);
    virtual uchar init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual uchar update();
    virtual uchar get_game_state();
    virtual uchar check_game_state();
    virtual uchar load_world(int);
    virtual uchar load_game(char*);
    virtual uchar new_game(RGE_Player_Info*, int);
    virtual uchar new_scenario(RGE_Player_Info&, int);
    virtual uchar save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual uchar save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(uchar);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);

    TRIBE_Tech* tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    uchar countdown_victory;
    uchar gap_115[3];
    float countdown_clock;
    uchar score_displayed;
    uchar controllingComputerPlayer;
    uchar gap_11E[2];
    int sent_zone_score;
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void load(int);
    char gap_04[0x844];
    TRIBE_Player(int, TRIBE_World*, uchar);
};

class TRIBE_Gaia : public TRIBE_Player {
public:
    char gap_848[0x10];
    TRIBE_Gaia(int, TRIBE_World*, uchar);
};

// The 0xC-byte tech object is shared by world_init and base_save.
class TRIBE_Tech {
public:
    char gap_00[0x0C];
    TRIBE_Tech(int, TRIBE_World*);
    void save(int);
};

void* operator new(unsigned int);
extern "C" void rge_write(int, void*, int);

#endif
