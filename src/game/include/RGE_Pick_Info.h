#pragma once
#include "common.h"

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};
static_assert(sizeof(RGE_Pick_Info) == 0x14, "Size mismatch");

// Size: 0xC (12 bytes). Source of truth: all_types_ground_truth.h
struct RGE_Pick_Obj_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};
static_assert(sizeof(RGE_Pick_Obj_Info) == 0xC, "Size mismatch");
