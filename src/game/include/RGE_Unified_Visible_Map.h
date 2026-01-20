#pragma once
#include "common.h"

struct RGE_Unified_Visible_Map {
    int mapWidth;
    int mapHeight;
    ulong* UnifiedVisibleMap;
};
static_assert(sizeof(RGE_Unified_Visible_Map) == 0xC, "Size mismatch");
