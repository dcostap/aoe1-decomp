#pragma once
#include "../common.h"
#include "map.h"
#include "effects.h"
#include "Command.h"
#include "scenario.h"
#include "Sounddrv.h"
#include "Com_hand.h"

class RGE_Game_World       {
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual uchar data_load_world(_iobuf* param_1); // Ghidra: data_load_world

    // [Slot 01] Offset 0x04 (Override)
    virtual uchar data_load_terrain_tables(char* param_1); // Ghidra: data_load_terrain_tables

    // [Slot 02] Offset 0x08 (Override)
    virtual uchar data_load_players(char* param_1); // Ghidra: data_load_players

    // [Slot 03] Offset 0x0C (Override)
    virtual uchar data_load_objects(char* param_1); // Ghidra: data_load_objects

    // [Slot 04] Offset 0x10 (Override)
    virtual uchar data_load_sounds(char* param_1); // Ghidra: data_load_sounds

    // [Slot 05] Offset 0x14 (Override)
    virtual uchar data_load_color_tables(char* param_1); // Ghidra: data_load_color_tables

    // [Slot 06] Offset 0x18 (Override)
    virtual uchar data_load_sprites(char* param_1); // Ghidra: data_load_sprites

    // [Slot 07] Offset 0x1C (Override)
    virtual void data_load_players_type(short param_1, short param_2, _iobuf* param_3); // Ghidra: data_load_players_type

    // [Slot 08] Offset 0x20 (Override)
    virtual void data_load_effects(char* param_1); // Ghidra: data_load_effects

    // [Slot 09] Offset 0x24 (Override)
    virtual void data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9); // Ghidra: data_load_map

    // [Slot 10] Offset 0x28 (Override)
    virtual void data_load_random_map(char* param_1, char* param_2, char* param_3, char* param_4); // Ghidra: data_load_random_map

    // [Slot 11] Offset 0x2C (Override)
    virtual uchar init_player_type(int param_1, short param_2, uchar param_3); // Ghidra: init_player_type

    // [Slot 12] Offset 0x30 (Override)
    virtual uchar init_player(int param_1); // Ghidra: init_player

    // [Slot 13] Offset 0x34 (Override)
    virtual void load_player(int param_1, uchar param_2, short param_3); // Ghidra: load_player

    // [Slot 14] Offset 0x38 (Override)
    virtual void color_table_init(int param_1); // Ghidra: color_table_init

    // [Slot 15] Offset 0x3C (Override)
    virtual void terrain_tables_init(int param_1); // Ghidra: terrain_tables_init

    // [Slot 16] Offset 0x40 (Override)
    virtual void init_sounds(int param_1, TSound_Driver* param_2); // Ghidra: init_sounds

    // [Slot 17] Offset 0x44 (Override)
    virtual void init_sprites(int param_1); // Ghidra: init_sprites

    // [Slot 18] Offset 0x48 (Override)
    virtual void map_init(int param_1, TSound_Driver* param_2); // Ghidra: map_init

    // [Slot 19] Offset 0x4C (Override)
    virtual void effects_init(int param_1); // Ghidra: effects_init

    // [Slot 20] Offset 0x50 (Override)
    virtual void master_player_init(int param_1); // Ghidra: master_player_init

    // [Slot 21] Offset 0x54 (Override)
    virtual void command_init(int param_1, TCommunications_Handler* param_2); // Ghidra: command_init

    // [Slot 22] Offset 0x58 (Override)
    virtual void world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // Ghidra: world_init

    // [Slot 23] Offset 0x5C (Override)
    virtual void setup_gaia(); // Ghidra: setup_gaia

    // [Slot 24] Offset 0x60 (Override)
    virtual void setup_players(RGE_Player_Info* param_1); // Ghidra: setup_players

    // [Slot 25] Offset 0x64 (Override)
    virtual uchar new_random_game(RGE_Player_Info* param_1); // Ghidra: new_random_game

    // [Slot 26] Offset 0x68 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 27] Offset 0x6C (Override)
    virtual void scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5); // Ghidra: scenario_make_player

    // [Slot 28] Offset 0x70 (Override)
    virtual void scenario_make_map(int param_1); // Ghidra: scenario_make_map

    // [Slot 29] Offset 0x74 (Override)
    virtual uchar load_scenario(RGE_Player_Info* param_1); // Ghidra: load_scenario

    // [Slot 30] Offset 0x78 (Override)
    virtual uchar load_scenario(char* param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario

    // [Slot 31] Offset 0x7C (Override)
    virtual void load_scenario1(int param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario1

    // [Slot 32] Offset 0x80 (Override)
    virtual void load_scenario2(int param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario2

    // [Slot 33] Offset 0x84 (Override)
    virtual void load_scenario3(int param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario3

    // [Slot 34] Offset 0x88 (Override)
    virtual void load_scenario4(int param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario4

    // [Slot 35] Offset 0x8C (Override)
    virtual void load_scenario5(int param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario5

    // [Slot 36] Offset 0x90 (Override)
    virtual void load_scenario6(int param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario6

    // [Slot 37] Offset 0x94 (Override)
    virtual void load_scenario7(int param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario7

    // [Slot 38] Offset 0x98 (Override)
    virtual void load_scenario8(int param_1, RGE_Player_Info* param_2); // Ghidra: load_scenario8

    // [Slot 39] Offset 0x9C (Override)
    virtual void logStatus(_iobuf* param_1, int param_2); // Ghidra: logStatus

    // [Slot 40] Offset 0xA0 (Override)
    virtual  ~RGE_Game_World() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 41] Offset 0xA4 (Override)
    virtual void setup_player_colors(); // Ghidra: setup_player_colors

    // [Slot 42] Offset 0xA8 (Override)
    virtual void setup_player_colors(RGE_Player_Info* param_1); // Ghidra: setup_player_colors

    // [Slot 43] Offset 0xAC (Override)
    virtual uchar data_load(char* param_1, char* param_2); // Ghidra: data_load

    // [Slot 44] Offset 0xB0 (Override)
    virtual uchar init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // Ghidra: init

    // [Slot 45] Offset 0xB4 (Override)
    virtual void turn_sound_off(); // Ghidra: turn_sound_off

    // [Slot 46] Offset 0xB8 (Override)
    virtual void del_game_info(); // Ghidra: del_game_info

    // [Slot 47] Offset 0xBC (Override)
    virtual uchar update(); // Ghidra: update

    // [Slot 48] Offset 0xC0 (Override)
    virtual uchar get_game_state(); // Ghidra: get_game_state

    // [Slot 49] Offset 0xC4 (Override)
    virtual uchar check_game_state(); // Ghidra: check_game_state

    // [Slot 50] Offset 0xC8 (Override)
    virtual uchar load_world(int param_1); // Ghidra: load_world

    // [Slot 51] Offset 0xCC (Override)
    virtual uchar load_game(char* param_1); // Ghidra: load_game

    // [Slot 52] Offset 0xD0 (Override)
    virtual uchar new_game(RGE_Player_Info* param_1, int param_2); // Ghidra: new_game

    // [Slot 53] Offset 0xD4 (Override)
    virtual uchar new_scenario(RGE_Player_Info* param_1, int param_2); // Ghidra: new_scenario

    // [Slot 54] Offset 0xD8 (Override)
    virtual uchar save_game(char* param_1); // Ghidra: save_game

    // [Slot 55] Offset 0xDC (Override)
    virtual void base_save(char* param_1); // Ghidra: base_save

    // [Slot 56] Offset 0xE0 (Override)
    virtual void base_save(int param_1); // Ghidra: base_save

    // [Slot 57] Offset 0xE4 (Override)
    virtual uchar save_scenario(char* param_1); // Ghidra: save_scenario

    // [Slot 58] Offset 0xE8 (Override)
    virtual RGE_Scenario* get_scenario_info(char* param_1); // Ghidra: get_scenario_info

    // [Slot 59] Offset 0xEC (Override)
    virtual void pause(uchar param_1); // Ghidra: pause

    // [Slot 60] Offset 0xF0 (Override)
    virtual void scenario_init(RGE_Game_World* param_1); // Ghidra: scenario_init

    // [Slot 61] Offset 0xF4 (Override)
    virtual void scenario_init(int param_1, RGE_Game_World* param_2); // Ghidra: scenario_init

    // [Slot 62] Offset 0xF8 (Override)
    virtual int addObject(RGE_Static_Object* param_1); // Ghidra: addObject

    // [Slot 63] Offset 0xFC (Override)
    virtual int removeObject(int param_1); // Ghidra: removeObject

    // --- Non-Virtual Members ---
    void reset_object_count();
    void set_map_visible(uchar param_1);
    void set_map_fog(uchar param_1);
    void reset_communications(TCommunications_Handler* param_1);
    void reset_player_visible_maps();
    void set_game_speed(float param_1);
    void update_sounds(ulong param_1);
    void update_sprites(ulong param_1);
    int is_player_turn(int param_1);
    ulong get_accum_time_delta(int param_1);
    void selectNextComputerPlayer(int param_1);
    void useComputerPlayerUpdateTime(ulong param_1);
    int computerPlayerUpdateTimeAvailable();
    int objectGroupOnTile(int param_1, int param_2, int param_3, int param_4, int* param_5);
    int difficultyLevel();
    int maxNumberObjects();
    int maxNumberNegativeObjects();
    int numberObjects();
    int numberNegativeObjects();
    RGE_Static_Object* object(int param_1);
    RGE_Static_Object* object_ptr(int param_1);
    long get_next_object_id();
    long get_next_reusable_object_id();
    int initializePathingSystem();
    uchar recycle_object_out_of_game(uchar param_1, RGE_Static_Object* param_2);
    RGE_Static_Object* recycle_object_in_to_game(uchar param_1);
    void update_mutual_allies();
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

