#pragma once
#include "common.h"

// Size: 0x14 (20 bytes)
struct RGE_Info_Line {
    float clump_num; // +0x0
    short percent_of_tiles_covered; // +0x4
    short percent_updown; // +0x6
    short min_elevation; // +0x8
    short max_elevation; // +0xA
    short terrain_type; // +0xC
    short terrain_base; // +0xE
    char obj_id; // +0x10
    unsigned char _pad_end[0x3]; // +0x11
};
static_assert(sizeof(RGE_Info_Line) == 0x14, "Size mismatch: RGE_Info_Line");

// Size: 0x520 (1312 bytes)
struct RGE_Map_Gen_Info {
    short base_terrain; // +0x0
    unsigned char _pad_0[0x2]; // +0x02
    RGE_Info_Line land; // +0x4
    RGE_Info_Line elevation[20]; // +0x18
    short elevation_num; // +0x1A8
    unsigned char _pad_1[0x2]; // +0x1AA
    RGE_Info_Line terrain[20]; // +0x1AC
    short terrain_num; // +0x33C
    unsigned char _pad_2[0x2]; // +0x33E
    RGE_Info_Line objects[20]; // +0x340
    short objects_num; // +0x4D0
    short player_num; // +0x4D2
    short player_x[9]; // +0x4D4
    short player_y[9]; // +0x4E6
    short player_connect[9]; // +0x4F8
    short player_base_land[9]; // +0x50A
    short space_between_islands_or_edge; // +0x51C
    unsigned char _pad_end[0x2]; // +0x51E
};
static_assert(sizeof(RGE_Map_Gen_Info) == 0x520, "Size mismatch: RGE_Map_Gen_Info");
