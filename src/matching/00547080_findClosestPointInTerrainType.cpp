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
// - Reconstructed the binary-backed lower/upper bounds as named XYPoint pairs;
//   initializing both upper fields before the map clamps restored the target
//   block topology. Reversed best-distance operands then closed the final
//   cmp/jcc byte pair. Exact under default flags.

#ifndef ZONE_MAP_TU_BUILD
struct XYPoint {
    int x;
    int y;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
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

    int findClosestPointInTerrainType(XYPoint point, XYPoint& out, int a, int b, int c);
};
#endif

int RGE_Zone_Map::findClosestPointInTerrainType(XYPoint point, XYPoint& out, int a, int b, int c)
{
    int x_value = point.x;
    int y_value = point.y;
    XYPoint max;
    XYPoint min;

    min.x = x_value - c;
    min.y = y_value - c;

    if (min.x < 0) {
        min.x = 0;
    }
    if (min.y < 0) {
        min.y = 0;
    }

    max.x = x_value + c;
    max.y = y_value + c;
    if (max.x > this->map->map_width - 1) {
        max.x = this->map->map_width - 1;
    }
    if (max.y > this->map->map_height - 1) {
        max.y = this->map->map_height - 1;
    }

    int best = -1;
    if (min.x <= max.x) {
        c = x_value - min.x;
        do {
            if (min.y <= max.y) {
                int y_distance = y_value - min.y;
                int y = min.y;
                do {
                    int terrain = this->map->get_terrain((short)min.x, (short)y);
                    if (terrain == a || terrain == b) {
                        int distance = c * c + y_distance * y_distance;
                        if (best == -1 || best > distance) {
                            best = distance;
                            out.x = min.x;
                            out.y = y;
                        }
                    }
                    ++y;
                    --y_distance;
                } while (y <= max.y);
            }
            ++min.x;
            --c;
        } while (min.x <= max.x);
    }

    return best != -1;
}
