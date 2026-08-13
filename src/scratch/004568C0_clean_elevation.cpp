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
            for (long col = x1; col <= x2; ++col, ++tile) {
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
                        (north_west && !west && !north)) {
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
                            tile[offset_nw].terrain_elevation =
                                (current << 5) | (tile[offset_nw].terrain_elevation & 0x1f);
                        }
                        if (north) {
                            tile[offset_n].terrain_elevation =
                                (current << 5) | (tile[offset_n].terrain_elevation & 0x1f);
                        }
                        if (north_east) {
                            tile[offset_ne].terrain_elevation =
                                (current << 5) | (tile[offset_ne].terrain_elevation & 0x1f);
                        }
                        if (east) {
                            tile[1].terrain_elevation =
                                (current << 5) | (tile[1].terrain_elevation & 0x1f);
                        }
                        if (south_east) {
                            tile[offset_se].terrain_elevation =
                                (current << 5) | (tile[offset_se].terrain_elevation & 0x1f);
                        }
                        if (south) {
                            tile[width].terrain_elevation =
                                (current << 5) | (tile[width].terrain_elevation & 0x1f);
                        }
                        if (south_west) {
                            tile[offset_sw].terrain_elevation =
                                (current << 5) | (tile[offset_sw].terrain_elevation & 0x1f);
                        }
                        if (west) {
                            tile[-1].terrain_elevation =
                                (current << 5) | (tile[-1].terrain_elevation & 0x1f);
                        }
                    } else {
                        ++current;
                        tile->terrain_elevation = (current << 5) ^
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
