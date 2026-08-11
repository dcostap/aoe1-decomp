#include <math.h>

// Attempt log:
// - Baseline: canonical RGE_Zone_Map layout with bounded XYPoint scan; 259B.
// - Recovered the binary's guarded do/while topology and live x/y indices; 247B.
// - sqrtf preserves the observed fsqrt/fcomp float-range comparison; remaining
//   drift is local register scheduling in max construction and the outer tail.
// - This assignment's probes swapped lower-bound declarations, split/rewrote
//   max additions, tried an outer do/while, and materialized x_distance squared;
//   the latter improved block alignment but widened the body, while the others
//   were duplicate or worse. Restored the simplest typed reconstruction.
// - Paused after the bounded 10-hypothesis matching assignment.
// - Follow-up control-flow probes found that a bounded for-body with
//   x_distance = from.x - x and an invariant x_squared reproduces the target
//   loop/tail topology; the direct max.y-then-max.x source order then reduced
//   the rebuilt function to 247 bytes and a 15-byte localized diff.
// - A late aggregate max initializer regressed the prologue and was rolled
//   back. Final best natural source retains named XYPoint ownership and the
//   bounded scan; remaining drift is the max-construction register/SIB shape.

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

// Main-agent audit confirmed canonical zone-map field ownership and retained
// the ordinary bounded range scan.
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

    max.y = from.y + radius;
    max.x = from.x + radius;

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
