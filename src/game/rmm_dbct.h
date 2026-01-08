#pragma once
#include "../common.h"
#include "rmm_base.h"
#include "World.h"

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module       {
public:
    char _pad_0x4[0x2C];
    RGE_Game_World* world;                   // 0x30
    long map_type;                           // 0x34
    long number_of_players;                  // 0x38
    RGE_Land_Info land_info;                 // 0x3C
    RGE_Terrain_Info terrain_info;           // 0x1474
    RGE_Object_Info object_info;             // 0x270C
    RGE_Elevation_Info elevation_info;       // 0x3FD4
    RGE_Map_Data map_info;                   // 0x4F54

    RGE_RMM_Database_Controller(char* param_1, char* param_2, char* param_3, char* param_4);
    RGE_RMM_Database_Controller(int param_1);

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

    // --- Non-Virtual Destructor ---
    ~RGE_RMM_Database_Controller() noexcept(false);
    // --- Non-Virtual Members ---
    uchar save(int param_1);
    void calc_land_start(long param_1, long param_2, long param_3, RGE_Land_Data_Entry* param_4);
};

static_assert(sizeof(RGE_RMM_Database_Controller) == 0x4F5C, "RGE_RMM_Database_Controller Size Mismatch");
static_assert(offsetof(RGE_RMM_Database_Controller, map_info) == 0x4F54, "RGE_RMM_Database_Controller Offset Mismatch");

