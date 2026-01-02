#pragma once
#include "../common.h"

class RGE_Unified_Visible_Map {
public:
    int mapHeight;                           // 0x4
    ulong* UnifiedVisibleMap;                // 0x8

    RGE_Unified_Visible_Map(int param_1, int param_2);
    RGE_Unified_Visible_Map(int param_1, RGE_Game_World* param_2);
    virtual void load(int param_1);
    virtual ~RGE_Unified_Visible_Map();
    virtual void save(int param_1);
    virtual void reset();
    virtual void Set_Map_Offsets();
    virtual void suppress_updates(int param_1);
};

static_assert(sizeof(RGE_Unified_Visible_Map) == 0xC, "RGE_Unified_Visible_Map Size Mismatch");
static_assert(offsetof(RGE_Unified_Visible_Map, UnifiedVisibleMap) == 0x8, "RGE_Unified_Visible_Map Offset Mismatch");

class RGE_Visible_Map {
public:
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
    virtual ~RGE_Visible_Map();
    virtual void save(int param_1);
    virtual uchar get_visible(int param_1, int param_2);
    virtual void set_all(uchar param_1);
    virtual void explore_all();
    virtual float percentExplored();
    virtual void recomputeExplored();
    virtual LOSTBL* get_los_table(int param_1, int param_2);
    virtual int explore_terrain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual void unexplore_terrain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual int explore_terrain_sq(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual void unexplore_terrain_sq(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual ulong checksum_visible_inputs();
    virtual long checksumVisible();
    virtual ulong checksumUnifiedVisible();
};

static_assert(sizeof(RGE_Visible_Map) == 0x38, "RGE_Visible_Map Size Mismatch");
static_assert(offsetof(RGE_Visible_Map, input_csum) == 0x34, "RGE_Visible_Map Offset Mismatch");

