#pragma once
#include "common.h"

struct RGE_Visible_Map {
    RGE_Visible_Map(RGE_Map* param_1, RGE_Player* param_2);
    RGE_Visible_Map(int param_1, RGE_Game_World* param_2);
    ~RGE_Visible_Map();

    void save(int param_1);
    uchar get_visible(int col, int row);
    float percentExplored();
    LOSTBL* get_los_table(int param_1, int param_2);
    int explore_terrain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    void unexplore_terrain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    int explore_terrain_sq(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    void unexplore_terrain_sq(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);

    long checksumVisible();
    ulong checksumUnifiedVisible();

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
