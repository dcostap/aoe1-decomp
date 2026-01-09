#pragma once
#include "common.h"

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;                   // 0x30
    long map_type;                           // 0x34
    long number_of_players;                  // 0x38
    RGE_Land_Info land_info;                 // 0x3C
    RGE_Terrain_Info terrain_info;           // 0x1474
    RGE_Object_Info object_info;             // 0x270C
    RGE_Elevation_Info elevation_info;       // 0x3FD4
    RGE_Map_Data map_info;                   // 0x4F54

    virtual uchar generate();                               // vt0[0]+0x0=0x483430
    virtual void add_land_module(uchar param_1);            // vt0[1]+0x4=0x483A20
    virtual void add_terrain_module();                      // vt0[2]+0x8=0x484160
    virtual void add_object_module();                       // vt0[3]+0xC=0x484320
    virtual void add_elevation_module();                    // vt0[4]+0x10=0x484470
    virtual uchar init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5); // vt0[5]+0x14=0x483540
    virtual uchar de_init();                                // vt0[6]+0x18=0x4835A0
    RGE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4);
    RGE_RMM_Database_Controller(int param_1);
    ~RGE_RMM_Database_Controller();
    uchar save(int param_1);
    void calc_land_start(long param_1, long param_2, long param_3, RGE_Land_Data_Entry* param_4);
};

static_assert(sizeof(RGE_RMM_Database_Controller) == 0x4F5C, "RGE_RMM_Database_Controller Size Mismatch");

