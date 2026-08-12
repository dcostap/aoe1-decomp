// VA: 00456170 RGE_Map::postclean_elevation
// Attempt log:
// baseline: direct typed tile neighborhood repair with canonical map ownership;
// frame and local topology remain smaller than the original.
// probe 2: long map fields plus short width/neighbor levels reached exact size;
// probe 3: long changed accumulator reached the best 775-byte positional diff.
// probes 4-6: direct -width, shifted elevation, and offset declaration variants
// were worse or codegen duplicates.
// probe 7: separate row/column cursors increased the frame and regressed shape.
// probes 8-9: long column and uchar result forms were duplicate or worse.
// probe 10: named width copy reproduced a worse duplicate basin.
// Final blocker: VC5 register coloring and local-home reuse differ in the typed
// candidate. Original reuses the y parameter home for old tile bytes and spills
// the changed byte at an unaligned local slot; no natural typed variant matched.
//
// The original uses the map row table and 24-byte RGE_Tile stride.  Elevation
// occupies the upper three bits of tile byte five.  A tile moves one level
// toward the requested elevation when a surrounding tile blocks its slope.

struct RGE_Tile {
    char gap_00[5];
    unsigned char terrain_elev;
    char gap_06[0x12];
};

class RGE_Map {
public:
    char gap_00[8];
    long map_width;
    long map_height;
    char gap_10[0x8d7c];
    RGE_Tile** map_row_offset;

    unsigned char postclean_elevation(long x0, long y0, long x1, long y1,
                                      unsigned char elevation);
};

unsigned char RGE_Map::postclean_elevation(long x0, long y0, long x1, long y1,
                                            unsigned char elevation)
{
    int last_row;
    int last_col;
    short width;
    bool bad;
    bool neighbor_bad;
    int x;
    unsigned char tile_byte;
    unsigned short next_elevation;
    RGE_Tile* tile;
    long changed;
    short offset1;
    short offset3;
    short offset2;

    width = (short)this->map_width;
    offset3 = (short)(-1 - width);
    offset1 = (short)(-width);
    offset2 = (short)(1 - width);
    changed = 0;

    if (x0 > 0)
        --x0;
    if (y0 > 0)
        --y0;
    if (x1 < this->map_width - 1)
        ++x1;
    if (y1 < this->map_height - 1)
        ++y1;

    do {
        if (y1 < y0)
            return (unsigned char)changed;

        tile = this->map_row_offset[y0] + x0;
        for (x = (int)x0; x <= x1; ++x) {
            neighbor_bad = false;
            bad = false;
            tile_byte = tile->terrain_elev;
            next_elevation = (unsigned short)(tile_byte >> 5);

            if (next_elevation < elevation) {
                ++next_elevation;
                if (y0 > 0 && next_elevation < (unsigned short)(tile[offset1].terrain_elev >> 5))
                    neighbor_bad = true;
                last_row = this->map_height - 1;
                if (y0 < last_row && next_elevation < (unsigned short)(tile[width].terrain_elev >> 5))
                    neighbor_bad = true;
                if (x > 0 && next_elevation < (unsigned short)(tile[-1].terrain_elev >> 5))
                    neighbor_bad = true;
                last_col = this->map_width - 1;
                if (x < last_col && next_elevation < (unsigned short)(tile[1].terrain_elev >> 5))
                    neighbor_bad = true;
                bad = neighbor_bad;
                if (y0 > 0) {
                    if (x > 0 && next_elevation < (unsigned short)(tile[offset3].terrain_elev >> 5))
                        neighbor_bad = true;
                    bad = neighbor_bad;
                    if (x < last_col && next_elevation < (unsigned short)(tile[offset2].terrain_elev >> 5))
                        bad = true;
                }
                if (y0 < last_row) {
                    if (x > 0 && next_elevation < (unsigned short)(tile[width - 1].terrain_elev >> 5))
                        bad = true;
                    if (x < last_col && next_elevation < (unsigned short)(tile[width + 1].terrain_elev >> 5))
                        bad = true;
                }
            } else if (elevation < next_elevation) {
                next_elevation = (unsigned short)(next_elevation - 1);
                if (y0 > 0 && (short)(unsigned short)(tile[offset1].terrain_elev >> 5) < (short)next_elevation)
                    bad = true;
                last_row = this->map_height - 1;
                if (y0 < last_row && (short)(unsigned short)(tile[width].terrain_elev >> 5) < (short)next_elevation)
                    bad = true;
                if (x > 0 && (short)(unsigned short)(tile[-1].terrain_elev >> 5) < (short)next_elevation)
                    bad = true;
                last_col = this->map_width - 1;
                if (x < last_col && (short)(unsigned short)(tile[1].terrain_elev >> 5) < (short)next_elevation)
                    bad = true;
                if (y0 > 0) {
                    if (x > 0 && (short)(unsigned short)(tile[offset3].terrain_elev >> 5) < (short)next_elevation)
                        bad = true;
                    if (x < last_col && (short)(unsigned short)(tile[offset2].terrain_elev >> 5) < (short)next_elevation)
                        bad = true;
                }
                if (y0 < last_row) {
                    if (x > 0 && (short)(unsigned short)(tile[width - 1].terrain_elev >> 5) < (short)next_elevation)
                        bad = true;
                    if (x < last_col && (short)(unsigned short)(tile[width + 1].terrain_elev >> 5) < (short)next_elevation)
                        bad = true;
                }
            }

            if (bad) {
                changed = 1;
                tile->terrain_elev = (unsigned char)((next_elevation << 5) |
                                                     (tile->terrain_elev & 0x1f));
            }
            ++tile;
        }
        ++y0;
    } while (true);
}
