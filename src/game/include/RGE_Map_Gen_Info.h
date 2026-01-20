#pragma once
#include "common.h"

struct RGE_Map_Gen_Info {
    short base_terrain;
    RGE_Info_Line land;
    RGE_Info_Line elevation[20];
    short elevation_num;
    RGE_Info_Line terrain[20];
    short terrain_num;
    RGE_Info_Line objects[20];
    short objects_num;
    short player_num;
    short player_x[9];
    short player_y[9];
    short player_connect[9];
    short player_base_land[9];
    short space_between_islands_or_edge;
};
static_assert(sizeof(RGE_Map_Gen_Info) == 0x520, "Size mismatch");
