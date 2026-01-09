#pragma once
#include "common.h"

class RGE_Game_World {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
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

    virtual uchar data_load_world(_iobuf* param_1);         // vt0[0]+0x0=0x5415B0
    virtual uchar data_load_terrain_tables(char* param_1);  // vt0[1]+0x4=0x540EB0
    virtual uchar data_load_players(char* param_1);         // vt0[2]+0x8=0x5412B0
    virtual uchar data_load_objects(char* param_1);         // vt0[3]+0xC=0x541380
    virtual uchar data_load_sounds(char* param_1);          // vt0[4]+0x10=0x540DA0
    virtual uchar data_load_color_tables(char* param_1);    // vt0[5]+0x14=0x540FD0
    virtual uchar data_load_sprites(char* param_1);         // vt0[6]+0x18=0x5410E0
    virtual void data_load_players_type(short param_1, short param_2, _iobuf* param_3); // vt0[7]+0x1C=0x541240
    virtual void data_load_effects(char* param_1);          // vt0[8]+0x20=0x5414A0
    virtual void data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9); // vt0[9]+0x24=0x541500
    virtual void data_load_random_map(char* param_1, char* param_2, char* param_3, char* param_4); // vt0[10]+0x28=0x541590
    virtual uchar init_player_type(int param_1, short param_2, uchar param_3); // vt0[11]+0x2C=0x541770
    virtual uchar init_player(int param_1);                 // vt0[12]+0x30=0x541800
    virtual void load_player(int param_1, uchar param_2, short param_3); // vt0[13]+0x34=0x542060
    virtual void color_table_init(int param_1);             // vt0[14]+0x38=0x541930
    virtual void terrain_tables_init(int param_1);          // vt0[15]+0x3C=0x541880
    virtual void init_sounds(int param_1, TSound_Driver* param_2); // vt0[16]+0x40=0x5419E0
    virtual void init_sprites(int param_1);                 // vt0[17]+0x44=0x541A80
    virtual void map_init(int param_1, TSound_Driver* param_2); // vt0[18]+0x48=0x541C20
    virtual void effects_init(int param_1);                 // vt0[19]+0x4C=0x541C90
    virtual void master_player_init(int param_1);           // vt0[20]+0x50=0x541CF0
    virtual void command_init(int param_1, TCommunications_Handler* param_2); // vt0[21]+0x54=0x541D00
    virtual void world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // vt0[22]+0x58=0x541D60
    virtual void setup_gaia();                              // vt0[23]+0x5C=0x542480
    virtual void setup_players(RGE_Player_Info* param_1);   // vt0[24]+0x60=0x5424F0
    virtual uchar new_random_game(RGE_Player_Info* param_1); // vt0[25]+0x64=0x542D10
    virtual void save(int param_1);                         // vt0[26]+0x68=0x543540
    virtual void scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5); // vt0[27]+0x6C=0x544250
    virtual void scenario_make_map(int param_1);            // vt0[28]+0x70=0x5442E0
    virtual uchar load_scenario(RGE_Player_Info* param_1);  // vt0[29]+0x74=0x544090
    virtual uchar load_scenario(char* param_1, RGE_Player_Info* param_2); // vt0[30]+0x78=0x543E00
    virtual void load_scenario1(int param_1, RGE_Player_Info* param_2); // vt0[31]+0x7C=0x544300
    virtual void load_scenario2(int param_1, RGE_Player_Info* param_2); // vt0[32]+0x80=0x5445C0
    virtual void load_scenario3(int param_1, RGE_Player_Info* param_2); // vt0[33]+0x84=0x544880
    virtual void load_scenario4(int param_1, RGE_Player_Info* param_2); // vt0[34]+0x88=0x544B90
    virtual void load_scenario5(int param_1, RGE_Player_Info* param_2); // vt0[35]+0x8C=0x544E70
    virtual void load_scenario6(int param_1, RGE_Player_Info* param_2); // vt0[36]+0x90=0x5451A0
    virtual void load_scenario7(int param_1, RGE_Player_Info* param_2); // vt0[37]+0x94=0x5454D0
    virtual void load_scenario8(int param_1, RGE_Player_Info* param_2); // vt0[38]+0x98=0x545800
    virtual void logStatus(_iobuf* param_1, int param_2);   // vt0[39]+0x9C=0x540A10
    virtual void setup_player_colors();                     // vt0[41]+0xA4=0x5426E0
    virtual void setup_player_colors(RGE_Player_Info* param_1); // vt0[42]+0xA8=0x5425B0
    virtual uchar data_load(char* param_1, char* param_2);  // vt0[43]+0xAC=0x541720
    virtual uchar init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // vt0[44]+0xB0=0x541DB0
    virtual void turn_sound_off();                          // vt0[45]+0xB4=0x541E70
    virtual void del_game_info();                           // vt0[46]+0xB8=0x541EE0
    virtual uchar update();                                 // vt0[47]+0xBC=0x542ED0
    virtual uchar get_game_state();                         // vt0[48]+0xC0=0x5433B0
    virtual uchar check_game_state();                       // vt0[49]+0xC4=0x5433C0
    virtual uchar load_world(int param_1);                  // vt0[50]+0xC8=0x5420F0
    virtual uchar load_game(char* param_1);                 // vt0[51]+0xCC=0x542360
    virtual uchar new_game(RGE_Player_Info* param_1, int param_2); // vt0[52]+0xD0=0x542750
    virtual uchar new_scenario(RGE_Player_Info* param_1, int param_2); // vt0[53]+0xD4=0x542BF0
    virtual uchar save_game(char* param_1);                 // vt0[54]+0xD8=0x543770
    virtual void base_save(char* param_1);                  // vt0[55]+0xDC=0x5439C0
    virtual void base_save(int param_1);                    // vt0[56]+0xE0=0x543850
    virtual uchar save_scenario(char* param_1);             // vt0[57]+0xE4=0x543A00
    virtual RGE_Scenario* get_scenario_info(char* param_1); // vt0[58]+0xE8=0x545CE0
    virtual void pause(uchar param_1);                      // vt0[59]+0xEC=0x540D30
    virtual void scenario_init(RGE_Game_World* param_1);    // vt0[60]+0xF0=0x541BC0
    virtual void scenario_init(int param_1, RGE_Game_World* param_2); // vt0[61]+0xF4=0x541B60
    virtual int addObject(RGE_Static_Object* param_1);      // vt0[62]+0xF8=0x545E00
    virtual int removeObject(int param_1);                  // vt0[63]+0xFC=0x545FD0
    RGE_Game_World();
    ~RGE_Game_World();
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

