#pragma once
#include "../types.h"

class RGE_Visible_Map {
public:
    uchar **map_offsets;
    class RGE_Game_World *world;
    class RGE_Player *player;
    class RGE_Map *map;
    uchar *visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    ulong PlayerVisibleMaskValue;
    ulong PlayerVisibleMaskInvertValue;
    ulong PlayerExploredMaskValue;
    ulong PlayerExploredMaskInvertValue;
    ulong input_csum;

    RGE_Visible_Map(class RGE_Map *map, class RGE_Player *player);
    ~RGE_Visible_Map();
};

static_assert(sizeof(RGE_Visible_Map) == 56, "RGE_Visible_Map size mismatch");
