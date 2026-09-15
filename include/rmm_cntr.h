#ifndef AOE1_RMM_CNTR_H
#define AOE1_RMM_CNTR_H

// This module owns the controller declaration only. Record and generator
// declarations stay with their canonical owners.

#include "rmm_base.h"

class RGE_Game_World;
struct RGE_Land_Info;
struct RGE_Terrain_Info;

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    RGE_RMM_Controller(RGE_Map* in_map, RGE_Game_World* world,
        uchar type, long player_num);
    virtual uchar generate();

protected:
    void add_land_module(RGE_Land_Info& info, long type, long player_num);
    void add_terrain_module(RGE_Terrain_Info& info,
        RGE_Land_Info& land_info, long type);
    void add_object_module(RGE_Game_World* world, RGE_Land_Info& land_info);
    long count_map_tiles(uchar terrain);
};

#endif
