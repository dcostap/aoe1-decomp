#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    RGE_RMM_Object_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Game_World* param_3, RGE_Object_Info* param_4, uchar param_5);

    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    void add_quick_obj(long param_1, long param_2, long param_3);
    void generate_objects(RGE_Object_Info_Line& param_1);
    void make_placement_stack(Map_Stack& param_1, long param_2, long param_3, long param_4, long param_5);
    uchar to_close(RGE_Object_Info_Line& param_1, long param_2, long param_3);
    void set_search_area(long param_1, long param_2, long param_3, uchar param_4);
    void remove_area_from_lists(long param_1, long param_2, long param_3);
    void place_avoid_objects(RGE_Object_Info_Line& param_1, long param_2);
    void place_objects(RGE_Object_Info_Line& param_1);
    void place_land_objects(RGE_Object_Info_Line& param_1, long param_2, long param_3, long param_4, long param_5, long param_6);
    void place_group(RGE_Object_Info_Line& param_1, long param_2, long param_3, RGE_Player* param_4);
    void place_cluster(RGE_Object_Info_Line& param_1, long param_2, long param_3, RGE_Player* param_4);

    RGE_Game_World* world;
    RGE_Object_Info info;
    unsigned char terrain_table[32];
    unsigned char add_terrain;
};
static_assert(sizeof(RGE_RMM_Object_Generator) == 0x1920, "Size mismatch");
