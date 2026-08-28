#ifndef AOE1_RMM_CNTR_H
#define AOE1_RMM_CNTR_H

// PDB source: C:\msdev\work\age1_x1\rmm_cntr.cpp.
// This module owns the controller declaration only. Record and generator
// declarations stay with their canonical owners.

#include "rmm_base.h"

class RGE_Game_World;
struct RGE_Land_Info;
struct RGE_Terrain_Info;

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    RGE_RMM_Controller(RGE_Map* map, RGE_Game_World* world,
        uchar map_type, long number_of_players);
    virtual uchar generate();

protected:
    void add_land_module(RGE_Land_Info& land_info,
        long map_type, long number_of_players);
    void add_terrain_module(RGE_Terrain_Info& terrain_info,
        RGE_Land_Info& land_info, long map_type);
    void add_object_module(RGE_Game_World* world, RGE_Land_Info* land_info);
    long count_map_tiles(uchar ignored);
};

#endif
