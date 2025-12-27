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
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    /* 0x0020 */ uchar checksum_created_this_update;
    /* 0x0021 */ uchar _pad_21;
    /* 0x0022 */ short master_object_num;
    /* 0x0024 */ struct RGE_Master_Static_Object **master_objects;
    /* 0x0028 */ struct RGE_Object_List *objects;
    /* 0x002C */ struct RGE_Object_List *sleeping_objects;
    /* 0x0030 */ struct RGE_Object_List *doppleganger_objects;
    /* 0x0034 */ struct RGE_Victory_Conditions *victory_conditions;
    /* 0x0038 */ struct RGE_Visible_Map *visible;
    /* 0x003C */ struct RGE_Game_World *world;
    /* 0x0040 */ struct RGE_Doppleganger_Creator *doppleganger_creator;
    /* 0x0044 */ char *name;
    /* 0x0048 */ uchar type;
    /* 0x0049 */ uchar _pad_49;
    /* 0x004a */ short id;
    /* 0x004c */ short attribute_num;
    /* 0x004e */ short _pad_4e;
    /* 0x0050 */ float *attributes;
    /* 0x0054 */ uchar culture;
    /* 0x0055 */ uchar _pad_55[3];
    /* 0x0058 */ struct RGE_Tile_List tile_list;
    /* 0x006c */ struct RGE_Tile_List diam_tile_list;
    /* 0x0080 */ uchar game_status;
    /* 0x0081 */ uchar resigned;
    /* 0x0082 */ uchar _pad_82[2];
    /* 0x0084 */ uchar *relations;
    /* 0x0088 */ int unitDiplomacy[9];
    /* 0x00ac */ int mutualAlly[9];
    /* 0x00d0 */ ulong mutualExploredMask;
    /* 0x00d4 */ ulong mutualVisibleMask;
    /* 0x00d8 */ ulong nonMutualVisibleMask;
    /* 0x00dc */ ulong RemoveVisibleBits[9];
    /* 0x0100 */ int allied_LOS_Enable;
    /* 0x0104 */ uchar allied_victory;
    /* 0x0105 */ uchar master_player_id;
    /* 0x0106 */ uchar _pad_106[2];
    /* 0x0108 */ struct RGE_Color_Table *color_table;
    /* 0x010c */ long tribe_effect;
    /* 0x0110 */ struct Visible_Resource_Manager *VR_List;
    /* 0x0114 */ float view_x;
    /* 0x0118 */ float view_y;
    /* 0x011c */ short map_x;
    /* 0x011e */ short map_y;
    /* 0x0120 */ short selected_start_col;
    /* 0x0122 */ short selected_start_row;
    /* 0x0124 */ short selected_end_col;
    /* 0x0126 */ short selected_end_row;
    /* 0x0128 */ short replacement_terrain;
    /* 0x012a */ short replacement_overlay;
    /* 0x012c */ short replacement_overlay_shape;
    /* 0x012e */ uchar _pad_12e[2];
    /* 0x0130 */ struct RGE_Static_Object *selected_obj;
    /* 0x0134 */ struct RGE_Static_Object *sel_list[25];
    /* 0x0198 */ ulong sel_object_properties;
    /* 0x019c */ short sel_count;
    /* 0x019e */ uchar groups_used[127];
    /* 0x021d */ uchar _pad_end[3];

    RGE_Player();
    virtual ~RGE_Player();
};

static_assert(sizeof(RGE_Player) == 0x220, "RGE_Player size mismatch");

#pragma pack(pop)
