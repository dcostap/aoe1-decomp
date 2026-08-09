// VA: 00547080 RGE_Zone_Map::findClosestPointInTerrainType
// PDB source: zone_map.cpp, lines 390-436
// Attempt log:
// - baseline: natural bounded terrain scan reconstructed from the original CFG;
//   canonical ownership is RGE_Zone_Map::map -> RGE_Map and XYPoint is two ints.
// - deferred best-distance initialization until after the map bounds; this
//   improved the structural diff and preserved the late sentinel assignment.
// - y-first lower-bound declarations were closer than x-first; the exact
//   RGE_Zone_Map field surface did not change emitted code.
// - named point aliases and XYPoint bound aggregates were rolled back: the
//   aliases were codegen-duplicate and aggregates increased the frame to 0x18.
// - variant lab tried scalar declaration/initialization orders and aggregates;
//   no invariant-eligible exact candidate was found.
// - Final TU-aware probe widened the terrain temporary to int and reversed the
//   upper-bound comparisons to match the observed cmp direction; this removes
//   the byte spill and is the best natural source, but local-slot/prologue drift
//   remains. No asm or raw-layout scaffolding retained.

struct XYPoint {
    int x;
    int y;
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
    unsigned char get_terrain(short x, short y);
};

// Main-agent audit confirmed canonical terrain/zone ownership and retained the
// natural closest-point scan.
class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    unsigned char* zone_map;
    unsigned char** zone_map_rows;
    unsigned char zone_info[257];
    char gap_50D[3];
    float* terrain_passability_rules;
    int terrain_passability_rules_num;
    RGE_Map* map;

    int findClosestPointInTerrainType(XYPoint point, XYPoint* out, int a, int b, int c);
};

int RGE_Zone_Map::findClosestPointInTerrainType(XYPoint point, XYPoint* out, int a, int b, int c)
{
    int y_min = point.y - c;
    int x_min = point.x - c;
    int x_max;
    int y_max;

    if (x_min < 0) {
        x_min = 0;
    }
    if (y_min < 0) {
        y_min = 0;
    }

    x_max = point.x + c;
    if (x_max > this->map->map_width - 1) {
        x_max = this->map->map_width - 1;
    }
    y_max = point.y + c;
    if (y_max > this->map->map_height - 1) {
        y_max = this->map->map_height - 1;
    }

    int best = -1;
    if (x_min <= x_max) {
        c = point.x - x_min;
        do {
            if (y_min <= y_max) {
                int y_distance = point.y - y_min;
                int y = y_min;
                do {
                    int terrain = this->map->get_terrain((short)x_min, (short)y);
                    if (terrain == a || terrain == b) {
                        int distance = c * c + y_distance * y_distance;
                        if (best == -1 || distance < best) {
                            best = distance;
                            out->x = x_min;
                            out->y = y;
                        }
                    }
                    ++y;
                    --y_distance;
                } while (y <= y_max);
            }
            ++x_min;
            --c;
        } while (x_min <= x_max);
    }

    return best != -1;
}
