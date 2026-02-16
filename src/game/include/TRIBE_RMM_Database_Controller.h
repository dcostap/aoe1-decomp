#pragma once
#include "common.h"
#include "RGE_RMM_Database_Controller.h"

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    TRIBE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4);
    TRIBE_RMM_Database_Controller(int param_1);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)
    virtual void add_land_module(uchar param_1); // vt[1] (0x4)
    virtual void add_terrain_module(); // vt[2] (0x8)
    virtual void add_object_module(); // vt[3] (0xC)
    virtual void add_elevation_module(); // vt[4] (0x10)
    virtual uchar init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5); // vt[5] (0x14)
    virtual uchar de_init(); // vt[6] (0x18)

    void add_shallows_module();

};
static_assert(sizeof(TRIBE_RMM_Database_Controller) == 0x4F5C, "Size mismatch");
