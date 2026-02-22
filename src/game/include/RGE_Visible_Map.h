#pragma once
#include "common.h"

struct RGE_Visible_Map {
    RGE_Visible_Map(RGE_Map* param_1, RGE_Player* param_2);
    RGE_Visible_Map(int param_1, RGE_Game_World* param_2);
    ~RGE_Visible_Map();

    void save(int param_1);
    uchar get_visible(int col, int row);
    float percentExplored();

    uchar** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    uchar* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    ulong PlayerVisibleMaskValue;
    ulong PlayerVisibleMaskInvertValue;
    ulong PlayerExploredMaskValue;
    ulong PlayerExploredMaskInvertValue;
    ulong input_csum;
};
// static_assert(sizeof(RGE_Visible_Map) == 0x38, "Size mismatch");
