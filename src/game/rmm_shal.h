#pragma once
#include "../common.h"

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module       {
public:
    char _pad_0x4[0x2C];
    RGE_Shallows_Info info;                  // 0x30

    RGE_RMM_Shallows_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Shallows_Info* param_3);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual uchar generate(); // Ghidra: generate

    // --- Non-Virtual Members ---
    void make_tribe_connections(long param_1, long param_2);
};

static_assert(sizeof(RGE_RMM_Shallows_Generator) == 0x34C, "RGE_RMM_Shallows_Generator Size Mismatch");
static_assert(offsetof(RGE_RMM_Shallows_Generator, info) == 0x30, "RGE_RMM_Shallows_Generator Offset Mismatch");

