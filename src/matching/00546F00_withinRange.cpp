#include <math.h>

// Source-gate audit:
// - BINARY NOTE: XYPoint is a two-int by-value parameter. The decorated target
//   symbol and direct callers use the 0x10-byte caller cleanup.
// - BINARY NOTE: RGE_Map is the polymorphic map class. Its canonical fields are
//   map_width and map_height at +0x8 and +0xC.
// - BINARY NOTE: RGE_Zone_Map owns zone_map_rows at +0x408 and map at +0x518.
// - The natural bounded scan preserves the proven call, bounds, and fault order.
// - BINARY NOTE: max.x is formed before max.y in the target.
// - Repeated direct casts let VC5 share one __ftol result. A named radius used
//   for all bounds selects a different register map.
// - The reduced source matches the 247-byte target exactly.

#ifndef ZONE_MAP_TU_BUILD
typedef unsigned char uchar;

struct XYPoint {
    int x;
    int y;
};

class RGE_Tile;

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    unsigned char _pad_0[3];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    int withinRange(uchar zone, XYPoint from, float range);
};
#endif

int RGE_Zone_Map::withinRange(uchar zone, XYPoint from, float range)
{
    int min_x = from.x - (int)range;
    int min_y = from.y - (int)range;

    if (min_x < 0)
        min_x = 0;
    if (min_y < 0)
        min_y = 0;

    XYPoint max;
    max.x = from.x + (int)range;
    max.y = from.y + (int)range;

    if (max.x > this->map->map_width - 1)
        max.x = this->map->map_width - 1;
    if (max.y > this->map->map_height - 1)
        max.y = this->map->map_height - 1;

    for (int x = min_x; x <= max.x; ++x) {
        int x_distance = from.x - x;
        int y = min_y;
        if (y <= max.y) {
            int x_squared = x_distance * x_distance;
            int y_distance = from.y - min_y;
            do {
                if (sqrtf((float)(x_squared + y_distance * y_distance)) <= range &&
                    this->zone_map_rows[y][x] == zone)
                    return 1;
                ++y;
                --y_distance;
            } while (y <= max.y);
        }
    }
    return 0;
}
