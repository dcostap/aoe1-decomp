#include <stdlib.h>
#include "../../include/rge_zone_map_context.h"

RGE_Zone_Map::~RGE_Zone_Map() {
    free(this->zone_map);
    free(this->zone_map_rows);
    free(this->terrain_passability_rules);
}
