#pragma once

#include "../types.h"

// Forward declarations
class RGE_Map;
struct RGE_Player;
struct RGE_Sound;
struct RGE_Sprite;
struct RGE_Master_Player;
struct RGE_Effects;
struct RGE_Command;
struct RGE_Scenario;
struct RGE_Color_Table;
struct TSound_Driver;
struct RGE_Static_Object;
struct AIPlayBook;
class RGE_Object_List;

// RGE_Game_World - 260 bytes per layout.json
class RGE_Game_World {
public:
    // ========================================================================
    // Virtual Table (64 entries per layout.json, destructor at [40])
    // ========================================================================
    virtual uchar data_load_world(void* file);
    virtual uchar data_load_terrain_tables(char* path);
    virtual uchar data_load_players(char* path);
    virtual uchar data_load_objects(char* path);
    virtual uchar data_load_sounds(char* path);
    virtual uchar data_load_color_tables(char* path);
    virtual uchar data_load_sprites(char* path);
    virtual void data_load_players_type(short a, short b, void* file);
    virtual void data_load_effects(char* path);
    virtual void data_load_map(char* a, char* b, char* c, char* d, short e, short f, short g, RGE_Sound** h, char* i);
    virtual void data_load_random_map(char* a, char* b, char* c, char* d);
    virtual uchar init_player_type(int a, short b, uchar c);
    virtual uchar init_player(int a);
    virtual void load_player(int a, uchar b, short c);
    virtual void color_table_init(int a);
    virtual void terrain_tables_init(int a);
    virtual void init_sounds(int a, TSound_Driver* b);
    virtual void init_sprites(int a);
    virtual void map_init(int a, TSound_Driver* b);
    virtual void effects_init(int a);
    virtual void master_player_init(int a);
    virtual void command_init(int a, void* b);
    virtual void world_init(int a, TSound_Driver* b, void* c);
    virtual void setup_gaia();
    virtual void setup_players(void* player_info);
    virtual uchar new_random_game(void* player_info);
    virtual void save(int a);
    virtual void scenario_make_player(short a, uchar b, uchar c, uchar d, char* e);
    virtual void scenario_make_map(int a);
    virtual uchar load_scenario(void* player_info);
    virtual uchar load_scenario(char* path, void* player_info);
    virtual void load_scenario1(int a, void* player_info);
    virtual void load_scenario2(int a, void* player_info);
    virtual void load_scenario3(int a, void* player_info);
    virtual void load_scenario4(int a, void* player_info);
    virtual void load_scenario5(int a, void* player_info);
    virtual void load_scenario6(int a, void* player_info);
    virtual void load_scenario7(int a, void* player_info);
    virtual void load_scenario8(int a, void* player_info);
    virtual void logStatus(void* file, int a);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(void* player_info);
    virtual uchar data_load(char* a, char* b);
    virtual uchar init(char* a, TSound_Driver* b, void* c);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual uchar update();
    virtual uchar get_game_state();
    virtual uchar check_game_state();
    virtual uchar load_world(int a);
    virtual uchar load_game(char* path);
    virtual uchar new_game(void* player_info, int a);
    virtual uchar new_scenario(void* player_info, int a);
    virtual uchar save_game(char* path);
    virtual void base_save(char* path);
    virtual void base_save(int a);
    virtual uchar save_scenario(char* path);
    virtual RGE_Scenario* get_scenario_info(char* path);
    virtual void pause(uchar a);
    virtual void scenario_init(RGE_Game_World* world);
    virtual void scenario_init(int a, RGE_Game_World* world);
    virtual int addObject(RGE_Static_Object* obj);
    virtual int removeObject(int id);

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
    // Compiler adds 1 byte padding here
    /* 0x0020 */ long sound_update_index;
    /* 0x0024 */ long sprite_update_index;
    /* 0x0028 */ RGE_Map* map;
    /* 0x002C */ short sound_num;
    // Compiler adds 2 bytes padding here
    /* 0x0030 */ RGE_Sound** sounds;
    /* 0x0034 */ short sprite_num;
    // Compiler adds 2 bytes padding here
    /* 0x0038 */ RGE_Sprite** sprites;
    /* 0x003C */ short player_num;
    // Compiler adds 2 bytes padding here
    /* 0x0040 */ RGE_Player** players;
    /* 0x0044 */ short master_player_num;
    // Compiler adds 2 bytes padding here
    /* 0x0048 */ RGE_Master_Player** master_players;
    /* 0x004C */ RGE_Effects* effects;
    /* 0x0050 */ short terrain_num;
    /* 0x0052 */ short terrain_size;
    /* 0x0054 */ float** terrains;
    /* 0x0058 */ RGE_Command* commands;
    /* 0x005C */ RGE_Scenario* scenario;
    /* 0x0060 */ short color_table_num;
    // Compiler adds 2 bytes padding here
    /* 0x0064 */ RGE_Color_Table** color_tables;
    /* 0x0068 */ long next_object_id;
    /* 0x006C */ long next_reusable_object_id;
    /* 0x0070 */ long scenario_object_id;
    /* 0x0074 */ uchar scenario_object_flag;
    // Compiler adds 3 bytes padding here
    /* 0x0078 */ uint random_seed;
    /* 0x007C */ short curr_player;
    // Compiler adds 2 bytes padding here
    /* 0x0080 */ TSound_Driver* sound_driver;
    /* 0x0084 */ float world_time_delta_seconds;
    /* 0x0088 */ RGE_Static_Object** objectsValue;
    /* 0x008C */ int numberObjectsValue;
    /* 0x0090 */ int maxNumberObjectsValue;
    /* 0x0094 */ RGE_Static_Object** negativeObjectsValue;
    /* 0x0098 */ int numberNegativeObjectsValue;
    /* 0x009C */ int maxNumberNegativeObjectsValue;
    /* 0x00A0 */ AIPlayBook* playbook;
    /* 0x00A4 */ long campaign;
    /* 0x00A8 */ long campaign_player;
    /* 0x00AC */ long campaign_scenario;
    /* 0x00B0 */ int player_turn;
    /* 0x00B4 */ ulong player_time_delta[9];
    /* 0x00D8 */ RGE_Object_List* reusable_static_objects;
    /* 0x00DC */ RGE_Object_List* reusable_animated_objects;
    /* 0x00E0 */ RGE_Object_List* reusable_moving_objects;
    /* 0x00E4 */ RGE_Object_List* reusable_action_objects;
    /* 0x00E8 */ RGE_Object_List* reusable_combat_objects;
    /* 0x00EC */ RGE_Object_List* reusable_missile_objects;
    /* 0x00F0 */ RGE_Object_List* reusable_doppleganger_objects;
    /* 0x00F4 */ ulong maximumComputerPlayerUpdateTime;
    /* 0x00F8 */ ulong availableComputerPlayerUpdateTime;
    /* 0x00FC */ int currentUpdateComputerPlayer;
    /* 0x0100 */ int difficultyLevelValue;
};

// MANDATORY VERIFICATION
static_assert(sizeof(RGE_Game_World) == 0x104, "RGE_Game_World size mismatch");
static_assert(offsetof(RGE_Game_World, players) == 0x40, "players offset");
static_assert(offsetof(RGE_Game_World, difficultyLevelValue) == 0x100, "difficultyLevelValue offset");
