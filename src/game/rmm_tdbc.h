#pragma once
#include "common.h"

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:

    virtual uchar generate();                               // vt0[0]+0x0=0x488870
    virtual void add_land_module(uchar param_1);            // vt0[1]+0x4=0x487940
    virtual void add_terrain_module();                      // vt0[2]+0x8=0x487DD0
    virtual void add_object_module();                       // vt0[3]+0xC=0x487FA0
    virtual void add_elevation_module();                    // vt0[4]+0x10=0x488700
    virtual uchar init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5); // vt0[5]+0x14=0x487710
    virtual uchar de_init();                                // vt0[6]+0x18=0x487930
    TRIBE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4);
    TRIBE_RMM_Database_Controller(int param_1);
    void add_shallows_module();
};

static_assert(sizeof(TRIBE_RMM_Database_Controller) == 0x4F5C, "TRIBE_RMM_Database_Controller Size Mismatch");

