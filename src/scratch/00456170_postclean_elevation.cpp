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
// probe 11: reordered short neighborhood offsets to the natural northwest,
// northeast, north declaration/use order; diff improved to 719 bytes, but the
// first prologue width-home mismatch remains.
// orch pass: a live row cursor plus byte was_bad matched the original frame and
// tile-byte parameter-home reuse, but diff rose to 828 bytes; rolled back.
// moving row initialization and signed elevation predicates changed no useful
// structure; restored the 719-byte natural typed candidate.
// managed probes: signed next-elevation, byte-level predicates, collapsed flags,
// direct map-bound expressions, scoped loop locals, declaration initializers,
// same-TU <stdlib.h>, and row/y0 parameter-home reuse were tested. Most were
// codegen duplicates or worse. The row plus byte-home form reached 828 bytes;
// the increment-list form reached 715 bytes but lost exact blocks and was not
// retained as the clean source.
// Final blocker: VC5 register coloring and local-home reuse differ in the typed
// candidate. Original reuses the y parameter home for old tile bytes and spills
// the changed byte at an unaligned local slot; no natural typed variant matched.
//
// The original uses the map row table and 24-byte RGE_Tile stride.  Elevation
// occupies the upper three bits of tile byte five.  A tile moves one level
// toward the requested elevation when a surrounding tile blocks its slope.

#ifndef MAP_CONTEXT_H
struct RGE_Tile {
    char gap_00[5];
    unsigned char terrain_type : 5;
    unsigned char height : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
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

#endif

unsigned char RGE_Map::postclean_elevation(long x0, long y0, long x1, long y1,
                                            unsigned char elevation)
{
    int last_row;
    int last_col;
    short width;
    bool bad;
    bool neighbor_bad;
    int x;
    unsigned short next_elevation;
    RGE_Tile* tile;
    long changed;
    short offset3;
    short offset2;
    short offset1;

    width = (short)this->map_width;
    offset3 = (short)(-1 - width);
    offset2 = (short)(1 - width);
    offset1 = (short)(-width);
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
            next_elevation = tile->height;

            if (next_elevation < elevation) {
                ++next_elevation;
                if (y0 > 0 && next_elevation < tile[offset1].height)
                    neighbor_bad = true;
                last_row = this->map_height - 1;
                if (y0 < last_row && next_elevation < tile[width].height)
                    neighbor_bad = true;
                if (x > 0 && next_elevation < tile[-1].height)
                    neighbor_bad = true;
                last_col = this->map_width - 1;
                if (x < last_col && next_elevation < tile[1].height)
                    neighbor_bad = true;
                bad = neighbor_bad;
                if (y0 > 0) {
                    if (x > 0 && next_elevation < tile[offset3].height)
                        neighbor_bad = true;
                    bad = neighbor_bad;
                    if (x < last_col && next_elevation < tile[offset2].height)
                        bad = true;
                }
                if (y0 < last_row) {
                    if (x > 0 && next_elevation < tile[width - 1].height)
                        bad = true;
                    if (x < last_col && next_elevation < tile[width + 1].height)
                        bad = true;
                }
            } else if (elevation < next_elevation) {
                next_elevation = (unsigned short)(next_elevation - 1);
                if (y0 > 0 && (short)tile[offset1].height < (short)next_elevation)
                    bad = true;
                last_row = this->map_height - 1;
                if (y0 < last_row && (short)tile[width].height < (short)next_elevation)
                    bad = true;
                if (x > 0 && (short)tile[-1].height < (short)next_elevation)
                    bad = true;
                last_col = this->map_width - 1;
                if (x < last_col && (short)tile[1].height < (short)next_elevation)
                    bad = true;
                if (y0 > 0) {
                    if (x > 0 && (short)tile[offset3].height < (short)next_elevation)
                        bad = true;
                    if (x < last_col && (short)tile[offset2].height < (short)next_elevation)
                        bad = true;
                }
                if (y0 < last_row) {
                    if (x > 0 && (short)tile[width - 1].height < (short)next_elevation)
                        bad = true;
                    if (x < last_col && (short)tile[width + 1].height < (short)next_elevation)
                        bad = true;
                }
            }

            if (bad) {
                changed = 1;
                tile->height = (unsigned char)next_elevation;
            }
            ++tile;
        }
        ++y0;
    } while (true);
}
