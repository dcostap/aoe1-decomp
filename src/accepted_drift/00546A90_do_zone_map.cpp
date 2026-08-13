// VA: 00546A90, RGE_Zone_Map::do_zone_map, 287 bytes
// Source: zone_map.cpp lines 172-208
// ACCEPTED_DRIFT: VC5 optimizes `cmp edx, esi` (esi=0 after xor) to
// `test edx, edx` at offset 0x6A-0x6B. The two instructions are
// equivalent for the jle check that follows (both set CF/ZF identically
// when comparing against zero). Also, the `mov [esp+10h], esi` (y=0) is
// hoisted before the conditional jump instead of after it — another
// benign scheduling difference. All 285 other bytes match perfectly.
//
// Attempt log:
// - v1-v6: tried various loop structures (for, do-while, if-block,
//   goto-based) to force cmp edx,esi and y=0 placement after jle.
//   VC5 consistently optimizes to test edx,edx and hoists y=0 store.
// - Conclusion: VC5 peephole optimizer replaces `cmp reg, 0` with
//   `test reg, reg` regardless of source structure. No C++ source
//   change can prevent this without larger structural changes that
//   would cascade into other mismatches.
// - control-flow probe: natural outer and inner for loops worsened the
//   hunk by 10 bytes, so the nested do-while form remains the clean source.
// - guard probes: reversed comparison, widened x, and group-group x all
//   emitted the same 2-byte drift.
// - variant labs: five guard spellings and five zero-valued x initializers
//   all formed one 287-byte group with the same cmp/test mismatch.
// FLAGS: /nologo /c /O2 /Oy

#include <stddef.h>
#include <string.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

struct RGE_Map {
    char pad_00[8];
    long map_width;          // +0x08
    long map_height;         // +0x0C
    char pad_10[0x8D7C];     // +0x10 to +0x8D8B
    char** map_row_offset;   // +0x8D8C
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];       // +0x000 (0x404 bytes)
    uchar* zone_map;                       // +0x404
    uchar** zone_map_rows;                 // +0x408
    uchar zone_info[257];                  // +0x40C
    char pad_50D[3];                       // +0x50D
    float* terrain_passability_rules;      // +0x510
    long terrain_passability_rules_num;    // +0x514
    RGE_Map* map;                          // +0x518

    uchar do_zone_map();
    void do_zone_map_area(long param_1, long param_2, uchar param_3, uchar param_4);
};

uchar RGE_Zone_Map::do_zone_map()
{
    int map_width;
    int map_height;
    int group;
    uchar visible;
    int y;
    int group_counter;
    int row;
    int col;

    // Phase 1: Initialize zone_info with 0xFF (255 bytes = 63 dwords + 1 word + 1 byte)
    map_width = this->map->map_width;
    map_height = this->map->map_height;
    group_counter = 0;

    memset(this->zone_info, 0xFF, 255);

    // Phase 2: Initialize zone_map_rows with 0xFF
    for (row = 0; row < map_width; row++) {
        for (col = 0; col < map_height; col++) {
            this->zone_map_rows[row][col] = 0xFF;
        }
    }

    // Phase 3: Flood fill zone assignment
    group = 0;
    if (map_width > 0) {
        do {
            int x = 0;
            if (x < map_height) {
                y = 0;
                do {
                    // Check if this cell is unassigned
                    if (this->zone_map_rows[group][x] == 0xFF) {
                        // Reset group_counter if it wraps
                        if (group_counter >= 255)
                            group_counter = 0;

                        // Check passability: terrain byte at offset y+5
                        int terrainByte = this->map->map_row_offset[group][y + 5] & 0x1F;
                        float passability = this->terrain_passability_rules[terrainByte];
                        visible = 1;
                        // Compare with double 0.0 (passability > 0.0)
                        if (!(passability > 0.0))
                            visible = 0;

                        this->zone_map_rows[group][x] = (uchar)group_counter;
                        do_zone_map_area(x, group, visible, (uchar)group_counter);
                        group_counter++;
                    }
                    x++;
                    y += 0x18;
                } while (x < map_height);
            }
            group++;
        } while (group < map_width);
    }

    return 1;
}
