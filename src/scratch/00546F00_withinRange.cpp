#include <math.h>

// Attempt log:
// - Baseline: canonical RGE_Zone_Map layout with bounded XYPoint scan; 259B.
// - Recovered the binary's guarded do/while topology and live x/y indices; 247B.
// - sqrtf preserves the observed fsqrt/fcomp float-range comparison; remaining
//   drift is local register scheduling in max construction and the outer tail.
// - Paused after the bounded 10-hypothesis matching assignment.

typedef unsigned char uchar;

struct XYPoint {
    int x;
    int y;
};

struct RGE_Map {
    char gap_00[0x08];
    long map_width;
    long map_height;
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    char gap_50D[3];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    int withinRange(uchar zone, XYPoint from, float range);
};

int RGE_Zone_Map::withinRange(uchar zone, XYPoint from, float range)
{
    XYPoint max;
    int radius = (int)range;
    int min_x = from.x - radius;
    int min_y = from.y - radius;

    if (min_x < 0)
        min_x = 0;
    if (min_y < 0)
        min_y = 0;

    max.x = from.x + radius;
    max.y = from.y + radius;

    if (max.x > this->map->map_width - 1)
        max.x = this->map->map_width - 1;
    if (max.y > this->map->map_height - 1)
        max.y = this->map->map_height - 1;

    int x = min_x;
    if (x > max.x)
        return 0;

    int x_distance = from.x - min_x;
    for (;;) {
        int y = min_y;
        if (y <= max.y) {
            int y_distance = from.y - min_y;
            do {
                if (sqrtf((float)(x_distance * x_distance + y_distance * y_distance)) <= range &&
                    this->zone_map_rows[y][x] == zone)
                    return 1;
                ++y;
                --y_distance;
            } while (y <= max.y);
        }
        ++x;
        --x_distance;
        if (x > max.x)
            return 0;
    }
}
