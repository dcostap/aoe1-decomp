#pragma once
#include "../common.h"

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module       {
public:
    char _pad_0x4[0x2C];
    RGE_Elevation_Info info;                 // 0x30

    RGE_RMM_Elevation_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Elevation_Info* param_3);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual uchar generate(); // Ghidra: generate

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void generate();

    // --- Non-Virtual Members ---
    uchar check_start_elevation(long param_1, long param_2, uchar param_3, uchar param_4, uchar param_5);
    uchar check_elevation(uchar param_1, long param_2, long param_3, long param_4, uchar param_5, uchar param_6);
    void generate_modifiers();
    float fig_chance(long param_1, long param_2, long param_3);
    long count_map_tiles(uchar param_1);
    void link_stack_randomly(Map_Stack* param_1);
    void remove_area_from_lists(long param_1, long param_2, long param_3);
    uchar base_elevation_generate(RGE_Elevation_Info_Line param_1);
};

static_assert(sizeof(RGE_RMM_Elevation_Generator) == 0xFB0, "RGE_RMM_Elevation_Generator Size Mismatch");
static_assert(offsetof(RGE_RMM_Elevation_Generator, info) == 0x30, "RGE_RMM_Elevation_Generator Offset Mismatch");

