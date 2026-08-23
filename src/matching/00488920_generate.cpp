// 00488920 RGE_RMM_Terrain_Generator::generate
// Source: rmm_terr.cpp lines 32-54
// Attempt log:
// Probe 1: packet-derived natural source with terrain table and by-value 0x20 struct call.

#include "../../include/rmm_terr_context.h"

unsigned char RGE_RMM_Terrain_Generator::generate()
{
    long index;
    float terrain_table[99];

    this->generate_modifiers();
    index = 0;
    do {
        terrain_table[index] = (float)index;
        index++;
    } while (index < 99);

    // The executable reloads the map's zone-list field for the second call.
    // Keep the direct map-relative loads: they preserve fault order and the
    // two original relocation anchors while using the canonical base field.
    RGE_Zone_Map_List* zml = *(RGE_Zone_Map_List**)((char*)this->map + 0x8DC4);
    long zid = zml->create_zone_map(terrain_table, 99);
    *(void**)((char*)this + 0x12C8) =
        (*(RGE_Zone_Map_List**)((char*)this->map + 0x8DC4))->get_zone_map(zid);

    index = 0;
    if (*(int*)((char*)this + 0xC90) > 0) {
        RGE_Terrain_Info_Line* p = (RGE_Terrain_Info_Line*)((char*)this + 0x30);
        do {
            this->base_terrain_generate(*p);
            index++;
            p++;
        } while (index < *(int*)((char*)this + 0xC90));
    }
    this->check_borders();
    return 1;
}
