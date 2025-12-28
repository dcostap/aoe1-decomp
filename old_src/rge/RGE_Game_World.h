#pragma once
#include "../types.h"
#include "RGE_Object_List.h"

// Forward declarations
class RGE_Map;
class RGE_Player;
struct RGE_Sound;
struct RGE_Sprite;
struct RGE_Master_Player;
struct RGE_Effects;
struct RGE_Command;
struct RGE_Scenario;
struct RGE_Color_Table;
class TSound_Driver;
struct RGE_Static_Object;
class AIPlayBook;
class TCommunications_Handler;
struct RGE_Player_Info;
struct _iobuf;

// RGE_Game_World - 260 bytes per layout.json
class RGE_Game_World {
public:
    // ========================================================================
    // Virtual Table (64 entries per layout.json)
    // ========================================================================
    virtual uchar data_load_world(_iobuf *file);                                // 0
    virtual uchar data_load_terrain_tables(char *path);                        // 1
    virtual uchar data_load_players(char *path);                               // 2
    virtual uchar data_load_objects(char *path);                               // 3
    virtual uchar data_load_sounds(char *path);                                // 4
    virtual uchar data_load_color_tables(char *path);                        // 5
    virtual uchar data_load_sprites(char *path);                               // 6
    virtual void data_load_players_type(short a, short b, _iobuf *file);       // 7
    virtual void data_load_effects(char *path);                                // 8
    virtual void data_load_map(char *a, char *b, char *c, char *d, short e, short f, short g, RGE_Sound **h, char *i); // 9
    virtual void data_load_random_map(char *a, char *b, char *c, char *d);     // 10
    virtual uchar init_player_type(int a, short b, uchar c);                  // 11
    virtual uchar init_player(int a);                                         // 12
    virtual void load_player(int a, uchar b, short c);                        // 13
    virtual void color_table_init(int a);                                     // 14
    virtual void terrain_tables_init(int a);                                  // 15
    virtual void init_sounds(int a, TSound_Driver *b);                        // 16
    virtual void init_sprites(int a);                                         // 17
    virtual void map_init(int a, TSound_Driver *b);                           // 18
    virtual void effects_init(int a);                                         // 19
    virtual void master_player_init(int a);                                   // 20
    virtual void command_init(int a, TCommunications_Handler *b);             // 21
    virtual void world_init(int a, TSound_Driver *b, TCommunications_Handler *c); // 22
    virtual void setup_gaia();                                                // 23
    virtual void setup_players(RGE_Player_Info *player_info);                 // 24
    virtual uchar new_random_game(RGE_Player_Info *player_info);              // 25
    virtual void save(int a);                                                 // 26
    virtual void scenario_make_player(short a, uchar b, uchar c, uchar d, char *e); // 27
    virtual void scenario_make_map(int a);                                    // 28
    virtual uchar load_scenario(RGE_Player_Info *player_info);                // 29
    virtual uchar load_scenario(char *path, RGE_Player_Info *player_info);    // 30
    virtual void load_scenario1(int a, RGE_Player_Info *player_info);         // 31
    virtual void load_scenario2(int a, RGE_Player_Info *player_info);         // 32
    virtual void load_scenario3(int a, RGE_Player_Info *player_info);         // 33
    virtual void load_scenario4(int a, RGE_Player_Info *player_info);         // 34
    virtual void load_scenario5(int a, RGE_Player_Info *player_info);         // 35
    virtual void load_scenario6(int a, RGE_Player_Info *player_info);         // 36
    virtual void load_scenario7(int a, RGE_Player_Info *player_info);         // 37
    virtual void load_scenario8(int a, RGE_Player_Info *player_info);         // 38
    virtual void logStatus(_iobuf *file, int a);                               // 39
    virtual ~RGE_Game_World();                                                // 40
    virtual void setup_player_colors();                                       // 41
    virtual void setup_player_colors(RGE_Player_Info *player_info);            // 42
    virtual uchar data_load(char *a, char *b);                                // 43
    virtual uchar init(char *a, TSound_Driver *b, TCommunications_Handler *c); // 44
    virtual void turn_sound_off();                                            // 45
    virtual void del_game_info();                                             // 46
    virtual uchar update();                                                   // 47
    virtual uchar get_game_state();                                           // 48
    virtual uchar check_game_state();                                         // 49
    virtual uchar load_world(int a);                                          // 50
    virtual uchar load_game(char *path);                                      // 51
    virtual uchar new_game(RGE_Player_Info *player_info, int a);              // 52
    virtual uchar new_scenario(RGE_Player_Info *player_info, int a);           // 53
    virtual uchar save_game(char *path);                                      // 54
    virtual void base_save(char *path);                                       // 55
    virtual void base_save(int a);                                            // 56
    virtual uchar save_scenario(char *path);                                  // 57
    virtual RGE_Scenario *get_scenario_info(char *path);                      // 58
    virtual void pause(uchar a);                                              // 59
    virtual void scenario_init(RGE_Game_World *world);                        // 60
    virtual void scenario_init(int a, RGE_Game_World *world);                 // 61
    virtual int addObject(RGE_Static_Object *obj);                            // 62
    virtual int removeObject(int id);                                         // 63

    // Non-virtual methods
    RGE_Game_World();
    void draw();

    // ========================================================================
    // Members (Offsets MUST match layout.json exactly)
    // ========================================================================
    /* 0x0004 */ ulong world_time;
    /* 0x0008 */ ulong old_world_time;
    /* 0x000C */ ulong world_time_delta;
    /* 0x0010 */ float timer;
    /* 0x0014 */ ulong old_time;
    /* 0x0018 */ float game_speed;
    /* 0x001C */ uchar temp_pause;
    /* 0x001D */ uchar game_state;
    /* 0x001E */ uchar game_end_condition;
    // Padding 1 byte
    /* 0x0020 */ long sound_update_index;
    /* 0x0024 */ long sprite_update_index;
    /* 0x0028 */ RGE_Map *map;
    /* 0x002C */ short sound_num;
    // Padding 2 bytes
    /* 0x0030 */ RGE_Sound **sounds;
    /* 0x0034 */ short sprite_num;
    // Padding 2 bytes
    /* 0x0038 */ RGE_Sprite **sprites;
    /* 0x003C */ short player_num;
    // Padding 2 bytes
    /* 0x0040 */ RGE_Player **players;
    /* 0x0044 */ short master_player_num;
    // Padding 2 bytes
    /* 0x0048 */ RGE_Master_Player **master_players;
    /* 0x004C */ RGE_Effects *effects;
    /* 0x0050 */ short terrain_num;
    /* 0x0052 */ short terrain_size;
    /* 0x0054 */ float **terrains;
    /* 0x0058 */ RGE_Command *commands;
    /* 0x005C */ RGE_Scenario *scenario;
    /* 0x0060 */ short color_table_num;
    // Padding 2 bytes
    /* 0x0064 */ RGE_Color_Table **color_tables;
    /* 0x0068 */ long next_object_id;
    /* 0x006C */ long next_reusable_object_id;
    /* 0x0070 */ long scenario_object_id;
    /* 0x0074 */ uchar scenario_object_flag;
    // Padding 3 bytes
    /* 0x0078 */ uint random_seed;
    /* 0x007C */ short curr_player;
    // Padding 2 bytes
    /* 0x0080 */ void *sound_driver; // TSound_Driver*
    /* 0x0084 */ float world_time_delta_seconds;
    /* 0x0088 */ RGE_Static_Object **objectsValue;
    /* 0x008C */ int numberObjectsValue;
    /* 0x0090 */ int maxNumberObjectsValue;
    /* 0x0094 */ RGE_Static_Object **negativeObjectsValue;
    /* 0x0098 */ int numberNegativeObjectsValue;
    /* 0x009C */ int maxNumberNegativeObjectsValue;
    /* 0x00A0 */ AIPlayBook *playbook;
    /* 0x00A4 */ long campaign;
    /* 0x00A8 */ long campaign_player;
    /* 0x00AC */ long campaign_scenario;
    /* 0x00B0 */ int player_turn;
    /* 0x00B4 */ ulong player_time_delta[9];
    /* 0x00D8 */ RGE_Object_List *reusable_static_objects;
    /* 0x00DC */ RGE_Object_List *reusable_animated_objects;
    /* 0x00E0 */ RGE_Object_List *reusable_moving_objects;
    /* 0x00E4 */ RGE_Object_List *reusable_action_objects;
    /* 0x00E8 */ RGE_Object_List *reusable_combat_objects;
    /* 0x00EC */ RGE_Object_List *reusable_missile_objects;
    /* 0x00F0 */ RGE_Object_List *reusable_doppleganger_objects;
    /* 0x00F4 */ ulong maximumComputerPlayerUpdateTime;
    /* 0x00F8 */ ulong availableComputerPlayerUpdateTime;
    /* 0x00FC */ int currentUpdateComputerPlayer;
    /* 0x0100 */ int difficultyLevelValue;
};

// MANDATORY VERIFICATION
static_assert(sizeof(RGE_Game_World) == 0x104, "RGE_Game_World size mismatch");
static_assert(offsetof(RGE_Game_World, players) == 0x40, "players offset");
static_assert(offsetof(RGE_Game_World, difficultyLevelValue) == 0x100, "difficultyLevelValue offset");
