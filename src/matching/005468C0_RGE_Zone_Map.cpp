// VA: 005468C0 RGE_Zone_Map::RGE_Zone_Map(RGE_Map *, float *, long)
// PDB source: zone_map.cpp, lines 117-144
// Attempt log:
// - baseline: natural typed constructor with direct member loops and memcpy was 216 B;
//   it omitted the binary-proven 0xFF fill of the allocated zone_map.
// - behavior: restoring the binary-proven zone_map memset produced an exact
//   248-byte match; no custom flags or compiler-steering scaffolding needed.

#include <stdlib.h>
#include <string.h>
#include "../../include/rge_zone_map_context.h"

typedef unsigned char uchar;

RGE_Zone_Map::RGE_Zone_Map(RGE_Map* map, float* rules, long rule_count)
{
    int i;

    this->map = map;
    this->zone_map = (uchar*)calloc(this->map->map_width * this->map->map_height, 1);
    memset(this->zone_map, 0xFF, this->map->map_width * this->map->map_height);
    this->zone_map_rows = (uchar**)calloc(this->map->map_height, 4);

    for (i = 0; i < this->map->map_height; i++) {
        this->zone_map_rows[i] = this->zone_map + this->map->map_width * i;
    }

    for (i = 0; i < 0xFF; i++) {
        this->zone_info[i] = 0xFF;
        this->numberTilesInZoneValue[i] = 0;
    }

    this->terrain_passability_rules_num = rule_count;
    this->terrain_passability_rules = (float*)calloc(this->terrain_passability_rules_num, 4);
    memcpy(this->terrain_passability_rules, rules, this->terrain_passability_rules_num * 4);
    this->do_zone_map();
}
