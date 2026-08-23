// 004821A0 RGE_RMM_Controller::RGE_RMM_Controller
// Source: rmm_cntr.cpp lines 42-49, size 181 bytes
// Attempt log:
// first: no SEH (missing /GX). Alloc 0x26D8 vs 0x26D4.
// second: added /GX, SEH generated. Alloc 4 too large.
// third: _alloca generates EBP frame.
// fourth: buf[0x26D0] — alloca correct (0x26D4), param load order swapped, offsets off by 0x10.
// fifth: use proper struct typing for terrain_info/land_info.

#include "../../include/rmm_cntr_context.h"

RGE_RMM_Controller::RGE_RMM_Controller(RGE_Map* map, RGE_Game_World* world,
                                       unsigned char param3, long param4)
    : RGE_Random_Map_Module(map, 0, 1)
{
    int p3 = (unsigned char)param3;
    RGE_Terrain_Info terrain_info;
    RGE_Land_Info land_info;

    this->add_land_module(land_info, p3, param4);
    this->add_terrain_module(terrain_info, land_info, p3);
    this->add_object_module(world, &land_info);
}
