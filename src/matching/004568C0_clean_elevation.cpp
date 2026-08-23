// VA 004568C0 RGE_Map::clean_elevation
// map.cpp:854-1024
// Attempt log:
// 1: Broad reconstruction used the wrong short-layout class, helper tile/elevation calls, and an under-modeled max/min smoothing pass (1179B, 30 calls vs 1478B, 3 calls).
// 2: Reconstructed the binary-backed map.cpp owner and direct helper ABI: 24-byte RGE_Tile, dword map_width/map_height at +8/+C, map_row_offset +0x8D8C, direct preclean/postclean/set_elev calls, short width-derived tile offsets, and the full eight-neighbor predicate/update topology.
// 3: Widened the current elevation to short and reversed neighbor comparisons; this recovered the oracle's AX/CX word-compare topology and raised the best shape to 84.62% (1501B, diff 782).
// 4: Shortened fix lifetime to the aggregation phase; VC5 kept the transient predicate in CL and aligned the four diagonal decision CFGs substantially.
// 5: Moving change_flag or changing compass declaration order did not improve the canonical basin; the best form keeps short NW/N/NE/E/SE/S/SW/W flags and a byte fix.
// 6: A bool NW experiment caused a 0x44 frame and broad register drift; restored the short-flag reconstruction. Remaining drift is flag stack-home coloring/order, the change_flag store schedule, and update block layout.
// 7: Replaced row-plus-column traversal with the natural &map_row_offset[row][x1] form; VC5 emitted an identical 1501-byte function, so restored the validated pointer traversal.
// 8: Combined the NW five-term guard into one short-circuit predicate; this removed 24 bytes of duplicate CFG and reached exact size, 93.71% shape, and 305B diff.
// 9: Reset change_flag at loop entry before bound expansion; this matched the oracle's parameter-home schedule and improved to 255B diff and 83.04% exact blocks.
// 10: Declared current after the eight zeroed neighbor flags; this delayed the AL reload and improved the exact-block frontier without changing size or calls.
// 11: Inverted the fix update branch so neighbor propagation is fall-through; this matched the oracle's jl topology and improved the structural basin.
// 12: A swapped final SW compare order worsened the late update blocks; restored the east-then-north guard. Remaining drift starts at the loop branch displacement and a relocated two-instruction SW block.
// 13: Ordered the final south-east guard as north-then-west, matching the oracle's compare order; diff improved 255B to 253B and the cold block aligned.
// 14: The exact generator donor's *32 spelling was a codegen duplicate here; restored the shift form.
// 15: A local byte value temporary for the first neighbor write was also a duplicate; restored the direct typed assignment.
// 16: Modeling tile byte five as terrain/elevation bitfields broke the proven frame and CFG; restored the byte field.
// 17: Casting the shifted high term and inlining current+1 matched the update increment and reduced diff 253B to 121B.
// 18: Cast-after-product, cast-before-shift, split temporaries, reversed OR operands, and a shared shifted value were duplicates or worse.
// 19: Matching the preclean donor's pointer-add update spelling was a codegen duplicate; it remains a natural typed form.
// 20: A byte current local broke the exact word-compare topology; restored the short current reconstruction.
// 21: An NW-only low-bit temporary was a codegen duplicate.
// 22: The same-TU <stdlib.h> context used by exact map.cpp donors reduced the
// diff from 121B to 29B and aligned seven of eight update blocks; retain it.
// 23: SW tile[index] spelling was a codegen duplicate under the donor context.
// 24: Reversed SW OR operands were also a duplicate. The remaining 29B is one
// SW update block plus the current increment block.
// paused: 29B localized drift remains after the focused four-probe pass.
// Managed pass 2026-08-17:
// 25: Indexed SE update spelling was a codegen duplicate.
// 26: Reversed SE OR operands were a codegen duplicate.
// 27: A byte high temporary for the SE update reduced diff 29B to 11B.
// 28: Advancing tile before col reduced diff 11B to 7B.
// 29: High, low, cast, XOR, and byte-next forms for the current update were
//     duplicates or worse. Mutating current caused 146B drift.
// 30: Unsigned current changed signed word branches and caused 16B drift.
// 31: Added string.h caused 117B drift. Signed tile byte caused 1150B drift.
// 32: Indexed current tile and branch-local tile pointer were duplicates.
// 33: A wide SE high temporary caused 510B drift.
// Best clean result is 1478B, 0x48 frame, 3 calls, 99.78% shape, and 7B
// positional diff. The remaining drift is the current-tile increment block:
// original increments AL before masking BL; VC5 emits the reverse order and
// stores through BL. Keep the natural typed source and the two improvements.
// Translation-unit finish:
// 34: The exact preceding preclean_elevation owner and this function both match
// under the map.cpp Windows header context. windows.h alone is sufficient;
// stdlib.h before or after windows.h is incidental. Replacing stdlib.h with
// windows.h in this standalone owner also gives MATCH and removes the prior
// seven-byte partial-register scheduling drift.
// 35: A shared natural RGE_Tile union for the two names at byte +5 keeps both
// the exact preclean_elevation anchor and this target exact in source order.
// Exact result: 1478 bytes, 460 instructions, three ordered calls, 0.0000%.

#include <windows.h>

struct RGE_Tile {
    char gap_00[5];
    unsigned char terrain_elevation;
    char gap_06[0x12];
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;

    void preclean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation);
    unsigned char postclean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation);
    void set_elev(short x1, short y1, short x2, short y2, unsigned char elevation,
                  short amount, unsigned char relative);
    void clean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation);
};

void RGE_Map::clean_elevation(long x1, long y1, long x2, long y2,
                              unsigned char elevation)
{
    unsigned char change_flag;
    short width = (short)this->map_width;
    short offset_nw = (short)(-1 - width);
    short offset_n = (short)-width;
    short offset_ne = (short)(1 - width);
    short offset_se = (short)(width + 1);
    short offset_sw = (short)(width - 1);

    if (x1 < 0) {
        x1 = 0;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (x2 >= this->map_width) {
        x2 = this->map_width - 1;
    }
    if (y2 >= this->map_height) {
        y2 = this->map_height - 1;
    }

    do {
        change_flag = 0;
        x1 -= 2;
        y1 -= 2;
        x2 += 2;
        y2 += 2;

        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->map_width) {
            x2 = this->map_width - 1;
        }
        if (y2 >= this->map_height) {
            y2 = this->map_height - 1;
        }

        this->preclean_elevation(x1, y1, x2, y2, elevation);

        for (long row = y1; row <= y2; ++row) {
            RGE_Tile* tile = this->map_row_offset[row] + x1;
            for (long col = x1; col <= x2; ++tile, ++col) {
                short north_west = 0;
                short north = 0;
                short north_east = 0;
                short east = 0;
                short south_east = 0;
                short south = 0;
                short south_west = 0;
                short west = 0;
                short current = (short)(tile->terrain_elevation >> 5);

                if (row > 0 && (tile[offset_n].terrain_elevation >> 5) > current) {
                    north = 1;
                }
                if (row < this->map_height - 1 && (tile[width].terrain_elevation >> 5) > current) {
                    south = 1;
                }
                if (col > 0 && (tile[-1].terrain_elevation >> 5) > current) {
                    west = 1;
                }
                if (col < this->map_width - 1 && (tile[1].terrain_elevation >> 5) > current) {
                    east = 1;
                }
                if (row > 0) {
                    if (col > 0 && (tile[offset_nw].terrain_elevation >> 5) > current) {
                        north_west = 1;
                    }
                    if (col < this->map_width - 1 && (tile[offset_ne].terrain_elevation >> 5) > current) {
                        north_east = 1;
                    }
                }
                if (row < this->map_height - 1) {
                    if (col > 0 && (tile[offset_sw].terrain_elevation >> 5) > current) {
                        south_west = 1;
                    }
                    if (col < this->map_width - 1 && (tile[offset_se].terrain_elevation >> 5) > current) {
                        south_east = 1;
                    }
                }

                bool fix = false;
                if (north_west) {
                    if ((north_east && !north) || (east && !north_east) ||
                        (south_west && !west) || (south && !south_west) ||
                        ((south_east && !south) && !east)) {
                        fix = 1;
                    }
                }
                if (north_east && !fix) {
                    if ((south_east && !east) || (south && !south_east) ||
                        (north_west && !north) || (west && !north_west) ||
                        (south_west && !west && !south)) {
                        fix = 1;
                    }
                }
                if (south_east && !fix) {
                    if ((south_west && !south) || (west && !south_west) ||
                        (north_east && !east) || (north && !north_east) ||
                        (north_west && !north && !west)) {
                        fix = 1;
                    }
                }
                if (south_west && !fix) {
                    if (north_west && !west) {
                        fix = 1;
                    } else if (north && !north_west) {
                        fix = 1;
                    } else if (south_east && !south) {
                        fix = 1;
                    } else if (east && !south_east) {
                        fix = 1;
                    } else if (north_east && !east && !north) {
                        fix = 1;
                    }
                }

                if (fix) {
                    if (current >= elevation) {
                        if (north_west) {
                            (tile + offset_nw)->terrain_elevation =
                                (unsigned char)(current << 5) |
                                ((tile + offset_nw)->terrain_elevation & 0x1f);
                        }
                        if (north) {
                            (tile + offset_n)->terrain_elevation =
                                (unsigned char)(current << 5) |
                                ((tile + offset_n)->terrain_elevation & 0x1f);
                        }
                        if (north_east) {
                            (tile + offset_ne)->terrain_elevation =
                                (unsigned char)(current << 5) |
                                ((tile + offset_ne)->terrain_elevation & 0x1f);
                        }
                        if (east) {
                            tile[1].terrain_elevation =
                                (unsigned char)(current << 5) |
                                (tile[1].terrain_elevation & 0x1f);
                        }
                        if (south_east) {
                            unsigned char high = (unsigned char)(current << 5);
                            (tile + offset_se)->terrain_elevation =
                                high |
                                ((tile + offset_se)->terrain_elevation & 0x1f);
                        }
                        if (south) {
                            (tile + width)->terrain_elevation =
                                (unsigned char)(current << 5) |
                                ((tile + width)->terrain_elevation & 0x1f);
                        }
                        if (south_west) {
                            (tile + offset_sw)->terrain_elevation =
                                (unsigned char)(current << 5) |
                                ((tile + offset_sw)->terrain_elevation & 0x1f);
                        }
                        if (west) {
                            tile[-1].terrain_elevation =
                                (unsigned char)(current << 5) |
                                (tile[-1].terrain_elevation & 0x1f);
                        }
                    } else {
                        tile->terrain_elevation =
                            (unsigned char)((current + 1) << 5) ^
                            (tile->terrain_elevation & 0x1f);
                    }
                    change_flag = 1;
                }
            }
        }

        if (this->postclean_elevation(x1, y1, x2, y2, elevation) != 0) {
            change_flag = 1;
        }
        if (!change_flag) {
            this->set_elev((short)x1, (short)y1, (short)x2, (short)y2, 0, 0, 0);
            return;
        }
    } while (true);
}
