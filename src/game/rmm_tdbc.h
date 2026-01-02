#pragma once
#include "../common.h"

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:

    TRIBE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4);
    TRIBE_RMM_Database_Controller(int param_1);
    virtual uchar init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5);
    virtual uchar de_init();
    virtual void add_land_module(uchar param_1);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
    virtual void add_shallows_module();
    virtual uchar generate();
};

static_assert(sizeof(TRIBE_RMM_Database_Controller) == 0x4F5C, "TRIBE_RMM_Database_Controller Size Mismatch");

