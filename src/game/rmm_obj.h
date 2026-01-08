#pragma once
#include "../common.h"

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module       {
public:
    char _pad_0x4[0x2C];
    RGE_Game_World* world;                   // 0x30
    RGE_Object_Info info;                    // 0x34
    uchar terrain_table[32];                 // 0x18FC
    uchar add_terrain;                       // 0x191C

    RGE_RMM_Object_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Game_World* param_3, RGE_Object_Info* param_4, uchar param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual uchar generate(); // Ghidra: generate

    // --- Non-Virtual Members ---
    void add_quick_obj(long param_1, long param_2, long param_3);
    void generate_objects(RGE_Object_Info_Line* param_1);
    void make_placement_stack(Map_Stack* param_1, long param_2, long param_3, long param_4, long param_5);
    uchar to_close(RGE_Object_Info_Line* param_1, long param_2, long param_3);
    void set_search_area(long param_1, long param_2, long param_3, uchar param_4);
    void remove_area_from_lists(long param_1, long param_2, long param_3);
    void place_avoid_objects(RGE_Object_Info_Line* param_1, long param_2);
    void place_objects(RGE_Object_Info_Line* param_1);
    void place_land_objects(RGE_Object_Info_Line* param_1, long param_2, long param_3, long param_4, long param_5, long param_6);
    void place_group(RGE_Object_Info_Line* param_1, long param_2, long param_3, RGE_Player* param_4);
    void place_cluster(RGE_Object_Info_Line* param_1, long param_2, long param_3, RGE_Player* param_4);
};

static_assert(sizeof(RGE_RMM_Object_Generator) == 0x1920, "RGE_RMM_Object_Generator Size Mismatch");
static_assert(offsetof(RGE_RMM_Object_Generator, add_terrain) == 0x191C, "RGE_RMM_Object_Generator Offset Mismatch");

