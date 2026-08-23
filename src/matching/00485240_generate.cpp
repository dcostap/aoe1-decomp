// VA: 00485240 RGE_RMM_Land_Generator::generate
// PDB: rmm_land.cpp lines 33-51 (133 bytes, 53 asm lines)
// Default flags. No inline asm/hacks.
// MATCHED 2026-05-19: use int fill with only low byte assigned to avoid movsx/xor
// before VC5's inline memset; spelling area as height*width makes VC5 emit
// load width then imul height.

#include "../../include/rmm_land_context.h"

extern "C" void* memset(void* dst, int val, unsigned int size);

unsigned char RGE_RMM_Land_Generator::generate() {
    this->clear_stack();

    int area = this->map_height;
    int fill;
    *(char*)&fill = (char)this->info.land_num;
    void* buf = this->search_map;
    area *= this->map_width;
    memset(buf, fill, area);

    this->map->set_terrain(
        0, 0, 0, 0,
        this->map_width - 1,
        this->map_height - 1,
        this->info.base_terrain,
        1,
        0);

    this->base_land_generate();

    this->map->clean_terrain(
        0, 0,
        this->map_width,
        this->map_height,
        this->info.base_terrain);

    return 1;
}
