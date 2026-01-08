#pragma once
#include "../common.h"

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller       {
public:
    char _pad_0x4[0x4F58];

    TRIBE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4);
    TRIBE_RMM_Database_Controller(int param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual uchar generate(); // Ghidra: generate

    // [Slot 01] Offset 0x04 (Override)
    virtual void add_land_module(uchar param_1); // Ghidra: add_land_module

    // [Slot 02] Offset 0x08 (Override)
    virtual void add_terrain_module(); // Ghidra: add_terrain_module

    // [Slot 03] Offset 0x0C (Override)
    virtual void add_object_module(); // Ghidra: add_object_module

    // [Slot 04] Offset 0x10 (Override)
    virtual void add_elevation_module(); // Ghidra: add_elevation_module

    // [Slot 05] Offset 0x14 (Override)
    virtual uchar init(RGE_Map* param_1, RGE_Game_World* param_2, uchar param_3, long param_4, uchar param_5); // Ghidra: init

    // [Slot 06] Offset 0x18 (Override)
    virtual uchar de_init(); // Ghidra: de_init

    // --- Non-Virtual Members ---
    void add_shallows_module();
};

static_assert(sizeof(TRIBE_RMM_Database_Controller) == 0x4F5C, "TRIBE_RMM_Database_Controller Size Mismatch");

