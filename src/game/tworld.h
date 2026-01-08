#pragma once
#include "../common.h"

class TRIBE_World : public RGE_Game_World       {
public:
    char _pad_0x4[0x100];
    TRIBE_Tech* tech;                        // 0x104
    int victory_type;                        // 0x108
    int artifact_count;                      // 0x10C
    int ruin_count;                          // 0x110
    uchar countdown_victory;                 // 0x114
    float countdown_clock;                   // 0x118
    uchar score_displayed;                   // 0x11C
    uchar controllingComputerPlayer;         // 0x11D
    int sent_zone_score;                     // 0x120

    TRIBE_World();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual uchar data_load_world(_iobuf* param_1); // Ghidra: data_load_world

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void data_load_terrain_tables();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void data_load_players();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void data_load_objects();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void data_load_sounds();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void data_load_color_tables();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void data_load_sprites();

    // [Slot 07] Offset 0x1C (Override)
    virtual void data_load_players_type(short param_1, short param_2, _iobuf* param_3); // Ghidra: data_load_players_type

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void data_load_effects();

    // [Slot 09] Offset 0x24 (Override)
    virtual void data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9); // Ghidra: data_load_map

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void data_load_random_map();

    // [Slot 11] Offset 0x2C (Override)
    virtual uchar init_player_type(int param_1, short param_2, uchar param_3); // Ghidra: init_player_type

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void init_player();

    // [Slot 13] Offset 0x34 (Override)
    virtual void load_player(int param_1, uchar param_2, short param_3); // Ghidra: load_player

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void color_table_init();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void terrain_tables_init();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void init_sounds();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void init_sprites();

    // [Slot 18] Offset 0x48 (Override)
    virtual void map_init(int param_1, TSound_Driver* param_2); // Ghidra: map_init

    // [Slot 19] Offset 0x4C (Override)
    virtual void effects_init(int param_1); // Ghidra: effects_init

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void master_player_init();

    // [Slot 21] Offset 0x54 (Override)
    virtual void command_init(int param_1, TCommunications_Handler* param_2); // Ghidra: command_init

    // [Slot 22] Offset 0x58 (Override)
    virtual void world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // Ghidra: world_init

    // [Slot 23] Offset 0x5C (Override)
    virtual void setup_gaia(); // Ghidra: setup_gaia

    // [Slot 24] Offset 0x60 (Override)
    virtual void setup_players(RGE_Player_Info* param_1); // Ghidra: setup_players

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void new_random_game();

    // [Slot 26] Offset 0x68 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 27] Offset 0x6C (Override)
    virtual void scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5); // Ghidra: scenario_make_player

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void scenario_make_map();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void load_scenario();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void load_scenario();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void load_scenario1();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void load_scenario2();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void load_scenario3();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void load_scenario4();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void load_scenario5();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void load_scenario6();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void load_scenario7();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void load_scenario8();

    // [Slot 39] Offset 0x9C (Override)
    virtual void logStatus(_iobuf* param_1, int param_2); // Ghidra: logStatus

    // [Slot 40] Offset 0xA0 (Override)
    virtual  ~TRIBE_World() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void setup_player_colors();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void setup_player_colors();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void data_load();

    // [Slot 44] Offset 0xB0 (Override)
    virtual uchar init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // Ghidra: init

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void turn_sound_off();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void del_game_info();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void get_game_state();

    // [Slot 49] Offset 0xC4 (Override)
    virtual uchar check_game_state(); // Ghidra: check_game_state

    // [Slot 50] Offset 0xC8 (Override)
    virtual uchar load_world(int param_1); // Ghidra: load_world

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void load_game();

    // [Slot 52] Offset 0xD0 (Override)
    virtual uchar new_game(RGE_Player_Info* param_1, int param_2); // Ghidra: new_game

    // [Slot 53] Offset 0xD4 (Override)
    virtual uchar new_scenario(RGE_Player_Info* param_1, int param_2); // Ghidra: new_scenario

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void save_game();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void base_save();

    // [Slot 56] Offset 0xE0 (Override)
    virtual void base_save(int param_1); // Ghidra: base_save

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save_scenario();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void get_scenario_info();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void pause();

    // [Slot 60] Offset 0xF0 (Override)
    virtual void scenario_init(RGE_Game_World* param_1); // Ghidra: scenario_init

    // [Slot 61] Offset 0xF4 (Override)
    virtual void scenario_init(int param_1, RGE_Game_World* param_2); // Ghidra: scenario_init

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void addObject();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void removeObject();

    // --- Non-Virtual Members ---
    void check_destructables(short param_1, short param_2, float param_3, float param_4, uchar param_5);
    long get_achievement(uchar param_1, char** param_2);
    void send_cheat(short param_1);
    void cheat(short param_1, short param_2);
    void fill_in_score(TRIBE_Zone_High_Score_Info* param_1, long param_2);
    void send_zone_score_info();
};

static_assert(sizeof(TRIBE_World) == 0x124, "TRIBE_World Size Mismatch");
static_assert(offsetof(TRIBE_World, sent_zone_score) == 0x120, "TRIBE_World Offset Mismatch");

