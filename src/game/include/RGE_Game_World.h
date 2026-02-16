#pragma once
#include "common.h"
#include "RGE_Sound.h"
#include <cstddef>

class RGE_Game_World {
public:
    RGE_Game_World();

    // Virtuals (best-effort)
    virtual uchar data_load_world(FILE* param_1); // vt[0] (0x0)
    virtual uchar data_load_terrain_tables(char* param_1); // vt[1] (0x4)
    virtual uchar data_load_players(char* param_1); // vt[2] (0x8)
    virtual uchar data_load_objects(char* param_1); // vt[3] (0xC)
    virtual uchar data_load_sounds(char* param_1); // vt[4] (0x10)
    virtual uchar data_load_color_tables(char* param_1); // vt[5] (0x14)
    virtual uchar data_load_sprites(char* param_1); // vt[6] (0x18)
    virtual void data_load_players_type(short param_1, short param_2, FILE* param_3); // vt[7] (0x1C)
    virtual void data_load_effects(char* param_1); // vt[8] (0x20)
    virtual void data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9); // vt[9] (0x24)
    virtual void data_load_random_map(char* param_1, char* param_2, char* param_3, char* param_4); // vt[10] (0x28)
    virtual uchar init_player_type(int param_1, short param_2, uchar param_3); // vt[11] (0x2C)
    virtual uchar init_player(int param_1); // vt[12] (0x30)
    virtual void load_player(int param_1, uchar param_2, short param_3); // vt[13] (0x34)
    virtual void color_table_init(int param_1); // vt[14] (0x38)
    virtual void terrain_tables_init(int param_1); // vt[15] (0x3C)
    virtual void init_sounds(int param_1, TSound_Driver* param_2); // vt[16] (0x40)
    virtual void init_sprites(int param_1); // vt[17] (0x44)
    virtual void map_init(int param_1, TSound_Driver* param_2); // vt[18] (0x48)
    virtual void effects_init(int param_1); // vt[19] (0x4C)
    virtual void master_player_init(int param_1); // vt[20] (0x50)
    virtual void command_init(int param_1, TCommunications_Handler* param_2); // vt[21] (0x54)
    virtual void world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // vt[22] (0x58)
    virtual void setup_gaia(); // vt[23] (0x5C)
    virtual void setup_players(RGE_Player_Info* param_1); // vt[24] (0x60)
    virtual uchar new_random_game(RGE_Player_Info* param_1); // vt[25] (0x64)
    virtual void save(int param_1); // vt[26] (0x68)
    virtual void scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5); // vt[27] (0x6C)
    virtual void scenario_make_map(int param_1); // vt[28] (0x70)
    virtual uchar load_scenario(RGE_Player_Info* param_1); // vt[29] (0x74)
    virtual uchar load_scenario(char* param_1, RGE_Player_Info* param_2); // vt[30] (0x78)
    virtual void load_scenario1(int param_1, RGE_Player_Info* param_2); // vt[31] (0x7C)
    virtual void load_scenario2(int param_1, RGE_Player_Info* param_2); // vt[32] (0x80)
    virtual void load_scenario3(int param_1, RGE_Player_Info* param_2); // vt[33] (0x84)
    virtual void load_scenario4(int param_1, RGE_Player_Info* param_2); // vt[34] (0x88)
    virtual void load_scenario5(int param_1, RGE_Player_Info* param_2); // vt[35] (0x8C)
    virtual void load_scenario6(int param_1, RGE_Player_Info* param_2); // vt[36] (0x90)
    virtual void load_scenario7(int param_1, RGE_Player_Info* param_2); // vt[37] (0x94)
    virtual void load_scenario8(int param_1, RGE_Player_Info* param_2); // vt[38] (0x98)
    virtual void logStatus(FILE* param_1, int param_2); // vt[39] (0x9C)
    virtual ~RGE_Game_World(); // vt[40] (0xA0)
    virtual void setup_player_colors(); // vt[41] (0xA4)
    virtual void setup_player_colors(RGE_Player_Info* param_1); // vt[42] (0xA8)
    virtual uchar data_load(char* param_1, char* param_2); // vt[43] (0xAC)
    virtual uchar init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // vt[44] (0xB0)
    virtual void turn_sound_off(); // vt[45] (0xB4)
    virtual void del_game_info(); // vt[46] (0xB8)
    virtual uchar update(); // vt[47] (0xBC)
    virtual uchar get_game_state(); // vt[48] (0xC0)
    virtual uchar check_game_state(); // vt[49] (0xC4)
    virtual uchar load_world(int param_1); // vt[50] (0xC8)
    virtual uchar load_game(char* param_1); // vt[51] (0xCC)
    virtual uchar new_game(RGE_Player_Info* param_1, int param_2); // vt[52] (0xD0)
    virtual uchar new_scenario(RGE_Player_Info* param_1, int param_2); // vt[53] (0xD4)
    virtual uchar save_game(char* param_1); // vt[54] (0xD8)
    virtual void base_save(char* param_1); // vt[55] (0xDC)
    virtual void base_save(int param_1); // vt[56] (0xE0)
    virtual uchar save_scenario(char* param_1); // vt[57] (0xE4)
    virtual RGE_Scenario* get_scenario_info(char* param_1); // vt[58] (0xE8)
    virtual void pause(uchar param_1); // vt[59] (0xEC)
    virtual void scenario_init(RGE_Game_World* param_1); // vt[60] (0xF0)
    virtual void scenario_init(int param_1, RGE_Game_World* param_2); // vt[61] (0xF4)
    virtual int addObject(RGE_Static_Object* param_1); // vt[62] (0xF8)
    virtual int removeObject(int param_1); // vt[63] (0xFC)

    // Non-virtual methods
    void reset_object_count();
    void reset_player_visible_maps();
    void set_map_visible(uchar param_1);
    void set_map_fog(uchar param_1);
    int initializePathingSystem();
    int numberObjects();
    int numberNegativeObjects();
    RGE_Static_Object* object(int param_1);
    RGE_Static_Object* object_ptr(int param_1);

    unsigned long world_time; // +0x4
    unsigned long old_world_time; // +0x8
    unsigned long world_time_delta; // +0xC
    float timer; // +0x10
    unsigned long old_time; // +0x14
    float game_speed; // +0x18
    unsigned char temp_pause; // +0x1C
    unsigned char game_state; // +0x1D
    unsigned char game_end_condition; // +0x1E
    unsigned char _pad_0[0x1]; // +0x1F
    long sound_update_index; // +0x20
    long sprite_update_index; // +0x24
    RGE_Map* map; // +0x28
    short sound_num; // +0x2C
    unsigned char _pad_1[0x2]; // +0x2E
    RGE_Sound** sounds; // +0x30
    short sprite_num; // +0x34
    unsigned char _pad_2[0x2]; // +0x36
    RGE_Sprite** sprites; // +0x38
    short player_num; // +0x3C
    unsigned char _pad_3[0x2]; // +0x3E
    RGE_Player** players; // +0x40
    short master_player_num; // +0x44
    unsigned char _pad_4[0x2]; // +0x46
    RGE_Master_Player** master_players; // +0x48
    RGE_Effects* effects; // +0x4C
    short terrain_num; // +0x50
    short terrain_size; // +0x52
    float** terrains; // +0x54
    RGE_Command* commands; // +0x58
    RGE_Scenario* scenario; // +0x5C
    short color_table_num; // +0x60
    unsigned char _pad_5[0x2]; // +0x62
    RGE_Color_Table** color_tables; // +0x64
    long next_object_id; // +0x68
    long next_reusable_object_id; // +0x6C
    long scenario_object_id; // +0x70
    unsigned char scenario_object_flag; // +0x74
    unsigned char _pad_6[0x3]; // +0x75
    unsigned int random_seed; // +0x78
    short curr_player; // +0x7C
    unsigned char _pad_7[0x2]; // +0x7E
    TSound_Driver* sound_driver; // +0x80
    float world_time_delta_seconds; // +0x84
    RGE_Static_Object** objectsValue; // +0x88
    int numberObjectsValue; // +0x8C
    int maxNumberObjectsValue; // +0x90
    RGE_Static_Object** negativeObjectsValue; // +0x94
    int numberNegativeObjectsValue; // +0x98
    int maxNumberNegativeObjectsValue; // +0x9C
    AIPlayBook* playbook; // +0xA0
    long campaign; // +0xA4
    long campaign_player; // +0xA8
    long campaign_scenario; // +0xAC
    int player_turn; // +0xB0
    unsigned long player_time_delta[9]; // +0xB4
    RGE_Object_List* reusable_static_objects; // +0xD8
    RGE_Object_List* reusable_animated_objects; // +0xDC
    RGE_Object_List* reusable_moving_objects; // +0xE0
    RGE_Object_List* reusable_action_objects; // +0xE4
    RGE_Object_List* reusable_combat_objects; // +0xE8
    RGE_Object_List* reusable_missile_objects; // +0xEC
    RGE_Object_List* reusable_doppleganger_objects; // +0xF0
    unsigned long maximumComputerPlayerUpdateTime; // +0xF4
    unsigned long availableComputerPlayerUpdateTime; // +0xF8
    int currentUpdateComputerPlayer; // +0xFC
    int difficultyLevelValue; // +0x100
};
static_assert(offsetof(RGE_Game_World, world_time) == 0x4, "Offset mismatch: world_time");
static_assert(offsetof(RGE_Game_World, map) == 0x28, "Offset mismatch: map");
static_assert(offsetof(RGE_Game_World, sound_driver) == 0x80, "Offset mismatch: sound_driver");
static_assert(offsetof(RGE_Game_World, playbook) == 0xA0, "Offset mismatch: playbook");
static_assert(offsetof(RGE_Game_World, reusable_static_objects) == 0xD8, "Offset mismatch: reusable_static_objects");
static_assert(offsetof(RGE_Game_World, maximumComputerPlayerUpdateTime) == 0xF4, "Offset mismatch: maximumComputerPlayerUpdateTime");
static_assert(sizeof(RGE_Game_World) == 0x104, "Size mismatch: RGE_Game_World");
