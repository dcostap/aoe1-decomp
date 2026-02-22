#pragma once
#include "common.h"

struct RGE_Unified_Visible_Map {
    int mapWidth;
    int mapHeight;
    ulong* UnifiedVisibleMap;

    // Non-virtual methods (visible.cpp.decomp)
    void load(int param_1);
    void save(int param_1);
    void reset();
    void Set_Map_Offsets(); // private in original
    void suppress_updates(int param_1);
};
static_assert(sizeof(RGE_Unified_Visible_Map) == 0xC, "Size mismatch");
