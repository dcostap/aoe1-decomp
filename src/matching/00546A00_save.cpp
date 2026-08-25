// VA: 00546A00 RGE_Zone_Map::save (129 B)
// PDB source: zone_map.cpp

extern "C" void rge_write(int file, void* data, int size);
#include "../../include/rge_zone_map_context.h"

void RGE_Zone_Map::save(int file)
{
    rge_write(file, this->zone_info, 0xFF);
    rge_write(file, this, 0x3FC);
    rge_write(file, this->zone_map,
              this->map->map_height * this->map->map_width);
    rge_write(file, &this->terrain_passability_rules_num, 4);
    if (this->terrain_passability_rules_num > 0) {
        rge_write(file, this->terrain_passability_rules,
                  this->terrain_passability_rules_num * 4);
    }
}
