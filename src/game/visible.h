#pragma once
#include "../common.h"
#include "map.h"

class RGE_Unified_Visible_Map       {
public:
    int mapWidth;                            // 0x0
    int mapHeight;                           // 0x4
    ulong* UnifiedVisibleMap;                // 0x8

    RGE_Unified_Visible_Map(int param_1, int param_2);
    RGE_Unified_Visible_Map(int param_1, RGE_Game_World* param_2);

    // --- Non-Virtual Members ---
    void load(int param_1);
    // --- Non-Virtual Destructor ---
    ~RGE_Unified_Visible_Map() noexcept(false);
    void save(int param_1);
    void reset();
    void Set_Map_Offsets();
    void suppress_updates(int param_1);
};

static_assert(sizeof(RGE_Unified_Visible_Map) == 0xC, "RGE_Unified_Visible_Map Size Mismatch");
static_assert(offsetof(RGE_Unified_Visible_Map, UnifiedVisibleMap) == 0x8, "RGE_Unified_Visible_Map Offset Mismatch");

class RGE_Visible_Map       {
public:
    uchar** map_offsets;                     // 0x0
    RGE_Game_World* world;                   // 0x4
    RGE_Player* player;                      // 0x8
    RGE_Map* map;                            // 0xC
    uchar* visible_map;                      // 0x10
    int widthValue;                          // 0x14
    int heightValue;                         // 0x18
    int numberTilesExploredValue;            // 0x1C
    int numberTotalTilesValue;               // 0x20
    ulong PlayerVisibleMaskValue;            // 0x24
    ulong PlayerVisibleMaskInvertValue;      // 0x28
    ulong PlayerExploredMaskValue;           // 0x2C
    ulong PlayerExploredMaskInvertValue;     // 0x30
    ulong input_csum;                        // 0x34

    RGE_Visible_Map(RGE_Map* param_1, RGE_Player* param_2);
    RGE_Visible_Map(int param_1, RGE_Game_World* param_2);

    // --- Non-Virtual Destructor ---
    ~RGE_Visible_Map() noexcept(false);
    // --- Non-Virtual Members ---
    void save(int param_1);
    uchar get_visible(int param_1, int param_2);
    void set_all(uchar param_1);
    void explore_all();
    float percentExplored();
    void recomputeExplored();
    LOSTBL* get_los_table(int param_1, int param_2);
    int explore_terrain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    void unexplore_terrain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    int explore_terrain_sq(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    void unexplore_terrain_sq(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    ulong checksum_visible_inputs();
    long checksumVisible();
    ulong checksumUnifiedVisible();
};

static_assert(sizeof(RGE_Visible_Map) == 0x38, "RGE_Visible_Map Size Mismatch");
static_assert(offsetof(RGE_Visible_Map, input_csum) == 0x34, "RGE_Visible_Map Offset Mismatch");

