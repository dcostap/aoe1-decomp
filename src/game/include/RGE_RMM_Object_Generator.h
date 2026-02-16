#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Object_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Game_World* param_3, RGE_Object_Info* param_4, uchar param_5);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    RGE_Game_World* world;
    RGE_Object_Info info;
    unsigned char terrain_table[32];
    unsigned char add_terrain;
};
static_assert(sizeof(RGE_RMM_Object_Generator) == 0x1920, "Size mismatch");
