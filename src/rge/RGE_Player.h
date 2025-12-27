#pragma once

#include "../types.h"
#include "RGE_Object_List.h"

#pragma pack(push, 1)

struct RGE_Tile_List_Node {
    int col;
    int row;
};

struct RGE_Tile_List {
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    struct RGE_Tile_List_Node *list;
};

struct RGE_Player {
    void *vfptr;
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    uchar checksum_created_this_update;
    short master_object_num;
    struct RGE_Master_Static_Object **master_objects;
    struct RGE_Object_List *objects;
    struct RGE_Object_List *sleeping_objects;
    struct RGE_Object_List *doppleganger_objects;
    struct RGE_Victory_Conditions *victory_conditions;
    struct RGE_Visible_Map *visible;
    struct RGE_Game_World *world;
    struct RGE_Doppleganger_Creator *doppleganger_creator;
    char *name;
    uchar type;
    short id;
    short attribute_num;
    float *attributes;
    uchar culture;
    struct RGE_Tile_List tile_list;
    struct RGE_Tile_List diam_tile_list;
    uchar game_status;
    uchar resigned;
    uchar *relations;
    int unitDiplomacy[9];
    int mutualAlly[9];
    ulong mutualExploredMask;
    ulong mutualVisibleMask;
    ulong nonMutualVisibleMask;
    ulong RemoveVisibleBits[9];
    int allied_LOS_Enable;
    uchar allied_victory;
    uchar master_player_id;
    struct RGE_Color_Table *color_table;
    long tribe_effect;
    struct Visible_Resource_Manager *VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;
    short replacement_terrain;
    short replacement_overlay;
    short replacement_overlay_shape;
    struct RGE_Static_Object *selected_obj;
    struct RGE_Static_Object *sel_list[10];
    ulong sel_object_properties;
    short sel_count;
    uchar groups_used[127];

    RGE_Player();
    virtual ~RGE_Player();
};

#pragma pack(pop)
