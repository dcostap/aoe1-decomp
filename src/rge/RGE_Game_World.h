#pragma once

#include "../types.h"
#include "RGE_Map.h"
#include "RGE_Player.h"

#pragma pack(push, 1)

class RGE_Game_World {
public:
    // Virtual table alignment (vptr at 0x0000)
    virtual ~RGE_Game_World();

    /* 0x0004 */ ulong world_time;
    /* 0x0008 */ ulong old_world_time;
    /* 0x000c */ ulong world_time_delta;
    /* 0x0010 */ float timer;
    /* 0x0014 */ ulong old_time;
    /* 0x0018 */ float game_speed;
    /* 0x001c */ uchar temp_pause;
    /* 0x001d */ uchar game_state;
    /* 0x001e */ uchar game_end_condition;
    /* 0x001f */ uchar _pad_1f;
    /* 0x0020 */ long sound_update_index;
    /* 0x0024 */ long sprite_update_index;
    /* 0x0028 */ struct RGE_Map *map;
    /* 0x002c */ short sound_num;
    /* 0x002e */ struct RGE_Sound **sounds;
    /* 0x0032 */ short sprite_num;
    /* 0x0034 */ struct RGE_Sprite **sprites;
    /* 0x0038 */ short player_num;
    /* 0x003a */ struct RGE_Player **players;
    /* 0x003e */ short master_player_num;
    /* 0x0040 */ struct RGE_Master_Player **master_players;
    /* 0x0044 */ struct RGE_Effects *effects;
    /* 0x0048 */ short terrain_num;
    /* 0x004a */ short terrain_size;
    /* 0x004c */ float **terrains;
    /* 0x0050 */ struct RGE_Command *commands;
    /* 0x0054 */ struct RGE_Scenario *scenario;
    /* 0x0058 */ short color_table_num;
    /* 0x005a */ struct RGE_Color_Table **color_tables;
    /* 0x005e */ long next_object_id;
    /* 0x0062 */ long next_reusable_object_id;
    /* 0x0066 */ long scenario_object_id;
    /* 0x006a */ uchar scenario_object_flag;
    /* 0x006b */ uchar _pad_6b;
    /* 0x006c */ uint random_seed;
    /* 0x0070 */ short curr_player;
    /* 0x0072 */ uchar _pad_72[2];
    /* 0x0074 */ struct TSound_Driver *sound_driver;
    /* 0x0078 */ float world_time_delta_seconds;
    /* 0x007c */ struct RGE_Static_Object **objectsValue;
    /* 0x0080 */ int numberObjectsValue;
    /* 0x0084 */ int maxNumberObjectsValue;
    /* 0x0088 */ struct RGE_Static_Object **negativeObjectsValue;
    /* 0x008c */ int numberNegativeObjectsValue;
    /* 0x0090 */ int maxNumberNegativeObjectsValue;
    /* 0x0094 */ struct AIPlayBook *playbook;
    /* 0x0098 */ long campaign;
    /* 0x009c */ long campaign_player;
    /* 0x00a0 */ long campaign_scenario;
    /* 0x00a4 */ int player_turn;
    /* 0x00a8 */ ulong player_time_delta[9];
    /* 0x00cc */ struct RGE_Object_List *reusable_static_objects;
    /* 0x00d0 */ struct RGE_Object_List *reusable_animated_objects;
    /* 0x00d4 */ struct RGE_Object_List *reusable_moving_objects;
    /* 0x00d8 */ struct RGE_Object_List *reusable_action_objects;
    /* 0x00dc */ struct RGE_Object_List *reusable_combat_objects;
    /* 0x00e0 */ struct RGE_Object_List *reusable_missile_objects;
    /* 0x00e4 */ struct RGE_Object_List *reusable_doppleganger_objects;
    /* 0x00e8 */ ulong maximumComputerPlayerUpdateTime;
    /* 0x00ec */ ulong availableComputerPlayerUpdateTime;
    /* 0x00f0 */ int currentUpdateComputerPlayer;
    /* 0x00f4 */ int difficultyLevelValue;
};

#pragma pack(pop)
