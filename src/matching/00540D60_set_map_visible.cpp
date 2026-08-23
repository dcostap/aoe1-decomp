// VA: 00540D60 RGE_Game_World::set_map_visible (20 B)
// PDB-qualified owner/name: public: void __thiscall RGE_Game_World::set_map_visible(unsigned char)
// PDB source: World.cpp lines 379-382
// Original body boundary: 00540D60-00540D73; next symbol: 00540D80.
// BINARY NOTE: map is the +0x28 field. The null test precedes the direct
// RGE_Map::set_map_visible call, preserving its fault and call order.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::set_map_visible(unsigned char param) {
    if (this->map)
        this->map->set_map_visible(param);
}
