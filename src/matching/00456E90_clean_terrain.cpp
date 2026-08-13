// 00456E90 RGE_Map::clean_terrain
// map.cpp:1028-1190
// Attempt log:
// 1: Packet-grounded baseline modeled the clamp, two-pass neighborhood scan, and repeated cleanup, but used a fake set_terrain helper and a simplified predicate (936B vs 1127B; 9 calls vs 1).
// 2: Reconstruct the period map.cpp surface: 24-byte RGE_Tile, map_row_offset +0x8D8C, game_world +0x8DC0, direct member set_terrain call, short neighbor offsets, and the packet's natural two-pass predicate topology.
// 3: A local map alias was a codegen duplicate.
// 4: Replaced explicit next_col/guard plumbing with natural nested row/column loops; size moved to 1166B, frame 0x48, diff 1077.
// 5: Restoring direct this member expressions was a codegen duplicate.
// 6: Reused the incoming y2 parameter for the expanding last-row bound; diff improved to 888 and shape to 75.62%, but frame remained four bytes large.
// 7: Modeled fix as a byte/bool; diff 875, calls/CFG aligned, frame still 0x48 vs 0x44.
// 8: Separate target terrain capture was a codegen duplicate.
// 9: Reusing the terrain parameter home as changed made the frame exact but lost EBX/ESI/EDI lifetime and worsened diff to 1105; rolled back.
// 10: bool changed was a codegen duplicate of the best separate-flag source. Final blocker is the remaining four-byte VC5 local-home/register basin; direct set_terrain call and all 91 conditional signals now align.
// 11: Reordered neighbor flags to the compass order used by exact clean_elevation; shape rose but size and positional diff worsened, so restored.
// 12: Declared per-tile fix before the neighbor flags to test the original AL fix and terrain-home changed split; emitted code was unchanged.
// 13: Moved changed before width and offset declarations to match the clean_elevation lifetime order; emitted code was unchanged.
// 14: Delayed per-tile fix initialization until after all neighbor loads; this matched the original AL zeroing, exact frame, and 1127-byte size.
// 15: Ordered neighbor declarations NW,N,NE,E,SE,S,SW,W to match the original zero-store order; positional diff fell to 4 bytes.
// 16: Reversed the inner loop increments to advance tile before col; exact 1127-byte match.

struct RGE_Tile {
    char gap_00[5];
    unsigned char terrain_type;
    char gap_06[0x12];
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x30];
    void* game_world;

    void set_terrain(void* world, int x, int y, unsigned char terrain, int a, int b);
    void clean_terrain(int x1, int y1, int x2, int y2, unsigned char terrain);
};

void RGE_Map::clean_terrain(int x1, int y1, int x2, int y2, unsigned char terrain)
{
    short map_width = (short)this->map_width;
    short offset_nw = (short)(-1 - map_width);
    short offset_n = (short)-map_width;
    short offset_ne = (short)(1 - map_width);
    short offset_se = (short)(map_width + 1);
    short offset_sw = (short)(map_width - 1);

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

    bool changed;
    do {
        changed = 0;

        if (x1 > 0) {
            --x1;
        }
        if (y1 > 0) {
            --y1;
        }
        if (x2 < this->map_width - 1) {
            ++x2;
        }
        if (y2 < this->map_height - 1) {
            ++y2;
        }

        int pass = 0;
        do {
            for (int row = y1; row <= y2; ++row) {
                RGE_Tile* tile = this->map_row_offset[row] + x1;
                for (int col = x1; col <= x2; ++tile, ++col) {
                        if ((tile->terrain_type & 0x1f) != terrain) {
                            short north_west = 0;
                            short north = 0;
                            short north_east = 0;
                            short east = 0;
                            short south_east = 0;
                            short south = 0;
                            short south_west = 0;
                            short west = 0;
                            unsigned char fix;

                            if (row > 0 && (tile[offset_n].terrain_type & 0x1f) == terrain) {
                                north = 1;
                            }
                            if (row < this->map_height - 1 && (tile[map_width].terrain_type & 0x1f) == terrain) {
                                south = 1;
                            }
                            if (col > 0 && (tile[-1].terrain_type & 0x1f) == terrain) {
                                west = 1;
                            }
                            if (col < this->map_width - 1 && (tile[1].terrain_type & 0x1f) == terrain) {
                                east = 1;
                            }

                            if (pass == 1) {
                                if (row > 0) {
                                    if (col > 0 && (tile[offset_nw].terrain_type & 0x1f) == terrain) {
                                        north_west = 1;
                                    }
                                    if (col < this->map_width - 1 &&
                                        (tile[offset_ne].terrain_type & 0x1f) == terrain) {
                                        north_east = 1;
                                    }
                                }
                                if (row < this->map_height - 1) {
                                    if (col > 0 && (tile[offset_sw].terrain_type & 0x1f) == terrain) {
                                        south_west = 1;
                                    }
                                    if (col < this->map_width - 1 &&
                                        (tile[offset_se].terrain_type & 0x1f) == terrain) {
                                        south_east = 1;
                                    }
                                }
                            }

                            fix = 0;
                            if (pass == 0) {
                                if ((north && south) || (east && west)) {
                                    fix = 1;
                                }
                            } else {
                                if (north_west) {
                                    if ((north_east && !north) || (east && !north_east) ||
                                        (south_west && !west) || (south && !south_west) ||
                                        ((south_east && !south) && !east)) {
                                        fix = 1;
                                    }
                                }
                                if (north_east && !fix) {
                                    if ((north_west && !north) || (west && !north_west) ||
                                        (south_east && !east) || (south && !south_east) ||
                                        (south_west && !west && !south)) {
                                        fix = 1;
                                    }
                                }
                                if (south_east && !fix) {
                                    if ((north_east && !east) || (north && !north_east) ||
                                        (south_west && !south) || (west && !south_west) ||
                                        (north_west && !west && !north)) {
                                        fix = 1;
                                    }
                                }
                                if (south_west && !fix) {
                                    if ((north_west && !west) || (north && !north_west) ||
                                        (south_east && !south) || (east && !south_east) ||
                                        (north_east && !east && !north)) {
                                        fix = 1;
                                    }
                                }
                            }

                            if (fix) {
                                this->set_terrain(this->game_world, col, row, terrain, 0, 0);
                                changed = 1;
                            }
                        }
                }
            }
            ++pass;
        } while (pass < 2);

        if (!changed) {
            return;
        }
    } while (true);
}
