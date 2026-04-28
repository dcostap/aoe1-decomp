// 004821A0 RGE_RMM_Controller::RGE_RMM_Controller
// Source: rmm_cntr.cpp lines 42-49, size 181 bytes
// Attempt log:
// first: no SEH (missing /GX). Alloc 0x26D8 vs 0x26D4.
// second: added /GX, SEH generated. Alloc 4 too large.
// third: _alloca generates EBP frame.
// fourth: buf[0x26D0] — alloca correct (0x26D4), param load order swapped, offsets off by 0x10.
// fifth: use proper struct typing for terrain_info/land_info.

struct RGE_Random_Map_Module {
    virtual ~RGE_Random_Map_Module();
    RGE_Random_Map_Module(void* map, int param2, int param3);
};

// Approximate struct sizes from original asm offsets
struct RGE_Terrain_Info {
    char data[0x1298];  // spans from +0x0C to +0x12A3
};

struct RGE_Land_Info {
    char data[0x1438];  // spans from +0x12A4 to +0x26DB
};

struct RGE_RMM_Controller : public RGE_Random_Map_Module {
    RGE_RMM_Controller(void* map, void* world, unsigned char param3, long param4);
    
    void add_land_module(char* land_info, unsigned char param3, long param4);
    void add_terrain_module(char* terrain_info, char* land_info, unsigned char param3);
    void add_object_module(void* world, char* land_info);
};

RGE_RMM_Controller::RGE_RMM_Controller(void* map, void* world, unsigned char param3, long param4)
    : RGE_Random_Map_Module(map, 0, 1)
{
    int p3 = (unsigned char)param3;
    RGE_Terrain_Info terrain_info;
    RGE_Land_Info land_info;

    this->add_land_module((char*)&land_info, p3, param4);
    this->add_terrain_module((char*)&terrain_info, (char*)&land_info, p3);
    this->add_object_module(world, (char*)&land_info);
}
