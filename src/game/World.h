#pragma once
#include "../common.h"

class RGE_Game_World {
public:
    ulong world_time;                        // 0x4
    ulong old_world_time;                    // 0x8
    ulong world_time_delta;                  // 0xC
    float timer;                             // 0x10
    ulong old_time;                          // 0x14
    float game_speed;                        // 0x18
    uchar temp_pause;                        // 0x1C
    uchar game_state;                        // 0x1D
    uchar game_end_condition;                // 0x1E
    long sound_update_index;                 // 0x20
    long sprite_update_index;                // 0x24
    RGE_Map* map;                            // 0x28
    short sound_num;                         // 0x2C
    RGE_Sound** sounds;                      // 0x30
    short sprite_num;                        // 0x34
    RGE_Sprite** sprites;                    // 0x38
    short player_num;                        // 0x3C
    RGE_Player** players;                    // 0x40
    short master_player_num;                 // 0x44
    RGE_Master_Player** master_players;      // 0x48
    RGE_Effects* effects;                    // 0x4C
    short terrain_num;                       // 0x50
    short terrain_size;                      // 0x52
    float** terrains;                        // 0x54
    RGE_Command* commands;                   // 0x58
    RGE_Scenario* scenario;                  // 0x5C
    short color_table_num;                   // 0x60
    RGE_Color_Table** color_tables;          // 0x64
    long next_object_id;                     // 0x68
    long next_reusable_object_id;            // 0x6C
    long scenario_object_id;                 // 0x70
    uchar scenario_object_flag;              // 0x74
    uint random_seed;                        // 0x78
    short curr_player;                       // 0x7C
    TSound_Driver* sound_driver;             // 0x80
    float world_time_delta_seconds;          // 0x84
    RGE_Static_Object** objectsValue;        // 0x88
    int numberObjectsValue;                  // 0x8C
    int maxNumberObjectsValue;               // 0x90
    RGE_Static_Object** negativeObjectsValue; // 0x94
    int numberNegativeObjectsValue;          // 0x98
    int maxNumberNegativeObjectsValue;       // 0x9C
    AIPlayBook* playbook;                    // 0xA0
    long campaign;                           // 0xA4
    long campaign_player;                    // 0xA8
    long campaign_scenario;                  // 0xAC
    int player_turn;                         // 0xB0
    ulong player_time_delta[9];              // 0xB4
    RGE_Object_List* reusable_static_objects; // 0xD8
    RGE_Object_List* reusable_animated_objects; // 0xDC
    RGE_Object_List* reusable_moving_objects; // 0xE0
    RGE_Object_List* reusable_action_objects; // 0xE4
    RGE_Object_List* reusable_combat_objects; // 0xE8
    RGE_Object_List* reusable_missile_objects; // 0xEC
    RGE_Object_List* reusable_doppleganger_objects; // 0xF0
    ulong maximumComputerPlayerUpdateTime;   // 0xF4
    ulong availableComputerPlayerUpdateTime; // 0xF8
    int currentUpdateComputerPlayer;         // 0xFC
    int difficultyLevelValue;                // 0x100

    RGE_Game_World();
    virtual void logStatus(_iobuf* param_1, int param_2);
    virtual ~RGE_Game_World();
    virtual void reset_object_count();
    virtual void pause(uchar param_1);
    virtual void set_map_visible(uchar param_1);
    virtual void set_map_fog(uchar param_1);
    virtual uchar data_load_sounds(char* param_1);
    virtual uchar data_load_terrain_tables(char* param_1);
    virtual uchar data_load_color_tables(char* param_1);
    virtual uchar data_load_sprites(char* param_1);
    virtual void data_load_players_type(short param_1, short param_2, _iobuf* param_3);
    virtual uchar data_load_players(char* param_1);
    virtual uchar data_load_objects(char* param_1);
    virtual void data_load_effects(char* param_1);
    virtual void data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9);
    virtual void data_load_random_map(char* param_1, char* param_2, char* param_3, char* param_4);
    virtual uchar data_load_world(_iobuf* param_1);
    virtual uchar data_load(char* param_1, char* param_2);
    virtual uchar init_player_type(int param_1, short param_2, uchar param_3);
    virtual uchar init_player(int param_1);
    virtual void terrain_tables_init(int param_1);
    virtual void color_table_init(int param_1);
    virtual void init_sounds(int param_1, TSound_Driver* param_2);
    virtual void init_sprites(int param_1);
    virtual void scenario_init(int param_1, RGE_Game_World* param_2);
    virtual void scenario_init(RGE_Game_World* param_1);
    virtual void map_init(int param_1, TSound_Driver* param_2);
    virtual void effects_init(int param_1);
    virtual void master_player_init(int param_1);
    virtual void command_init(int param_1, TCommunications_Handler* param_2);
    virtual void world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3);
    virtual uchar init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3);
    virtual void turn_sound_off();
    virtual void reset_communications(TCommunications_Handler* param_1);
    virtual void reset_player_visible_maps();
    virtual void del_game_info();
    virtual void load_player(int param_1, uchar param_2, short param_3);
    virtual uchar load_world(int param_1);
    virtual uchar load_game(char* param_1);
    virtual void set_game_speed(float param_1);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info* param_1);
    virtual void setup_player_colors(RGE_Player_Info* param_1);
    virtual void setup_player_colors();
    virtual uchar new_game(RGE_Player_Info* param_1, int param_2);
    virtual uchar new_scenario(RGE_Player_Info* param_1, int param_2);
    virtual uchar new_random_game(RGE_Player_Info* param_1);
    virtual void update_sounds(ulong param_1);
    virtual void update_sprites(ulong param_1);
    virtual uchar update();
    virtual int is_player_turn(int param_1);
    virtual ulong get_accum_time_delta(int param_1);
    virtual uchar get_game_state();
    virtual uchar check_game_state();
    virtual void save(int param_1);
    virtual uchar save_game(char* param_1);
    virtual void base_save(int param_1);
    virtual void base_save(char* param_1);
    virtual uchar save_scenario(char* param_1);
    virtual uchar load_scenario(char* param_1, RGE_Player_Info* param_2);
    virtual uchar load_scenario(RGE_Player_Info* param_1);
    virtual void scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5);
    virtual void scenario_make_map(int param_1);
    virtual void load_scenario1(int param_1, RGE_Player_Info* param_2);
    virtual void load_scenario2(int param_1, RGE_Player_Info* param_2);
    virtual void load_scenario3(int param_1, RGE_Player_Info* param_2);
    virtual void load_scenario4(int param_1, RGE_Player_Info* param_2);
    virtual void load_scenario5(int param_1, RGE_Player_Info* param_2);
    virtual void load_scenario6(int param_1, RGE_Player_Info* param_2);
    virtual void load_scenario7(int param_1, RGE_Player_Info* param_2);
    virtual void load_scenario8(int param_1, RGE_Player_Info* param_2);
    virtual void selectNextComputerPlayer(int param_1);
    virtual void useComputerPlayerUpdateTime(ulong param_1);
    virtual int computerPlayerUpdateTimeAvailable();
    virtual int objectGroupOnTile(int param_1, int param_2, int param_3, int param_4, int* param_5);
    virtual int difficultyLevel();
    virtual RGE_Scenario* get_scenario_info(char* param_1);
    virtual int maxNumberObjects();
    virtual int maxNumberNegativeObjects();
    virtual int numberObjects();
    virtual int numberNegativeObjects();
    virtual RGE_Static_Object* object(int param_1);
    virtual RGE_Static_Object* object_ptr(int param_1);
    virtual long get_next_object_id();
    virtual long get_next_reusable_object_id();
    virtual int addObject(RGE_Static_Object* param_1);
    virtual int removeObject(int param_1);
    virtual int initializePathingSystem();
    virtual uchar recycle_object_out_of_game(uchar param_1, RGE_Static_Object* param_2);
    virtual RGE_Static_Object* recycle_object_in_to_game(uchar param_1);
    virtual void update_mutual_allies();
};

static_assert(sizeof(RGE_Game_World) == 0x104, "RGE_Game_World Size Mismatch");
static_assert(offsetof(RGE_Game_World, difficultyLevelValue) == 0x100, "RGE_Game_World Offset Mismatch");

void RGE_Game_World::logStatus(_iobuf* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall logStatus(RGE_Game_World * this, _iobuf * param_1, i
//              void              <VOID>         <RETURN>
//              RGE_Game_World    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?logStatus@RGE_Game_World@@MAEXPAU_iobuf@@H@Z                XREF[1]:     005779ac(*)
//                               RGE_Game_World::logStatus
//                              world.h:107 (3)
//         00540a10     RET        0x8
//         00540a13     ??         90h
//         00540a14     NOP
//         00540a15     NOP
//         00540a16     NOP
//         00540a17     NOP
//         00540a18     NOP
//         00540a19     NOP
//         00540a1a     NOP
//         00540a1b     NOP
//         00540a1c     NOP
//         00540a1d     NOP
//         00540a1e     NOP
//         00540a1f     NOP
    return;
}

