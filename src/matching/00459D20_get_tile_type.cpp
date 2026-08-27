// 00459D20 RGE_Map::get_tile_type
// Attempt log:
// try 1: reconstructed 3x3 terrain area-neighbor classification from asm.
// try 2: removed area_at helper and cached width/height/rows to stop VC5 saving this; improved to exact size with edit diff 3.10%.
// try 3: split initial bounds checks to match original load/test/order; prologue now matches through saved registers.
// try 4: modeled row table at +0x8d8c and tile stride as (x+x*2)<<3; matched original LEA/SHL family.
// try 5: used unsigned short locals for center/neighbors to get word stack stores and word compares.
// try 6: ordered neighbor loads as original line map: NW,N,E,SW,W,S,NE,SE; most body now resyncs.
// try 7: tried pre-biased current row pointer (rows[y]+xo); worsened edit diff to 6.7%, rolled back.
// try 8: kept direct row[xo+offset] form for center/east/west to preserve original longer addressing family.
// try 9: decision tree return order mirrors original constants 0x0e/0x0d/0x10/0x0f/6/8/5/7/diagonal cases.
// try 10: remaining mismatch is localized codegen/addressing and width/height store order, but positional shifts are broad; not accepted_drift-safe.
// try 16: used the direct map_width member in the first bound check, then cached width for the later neighbor guards.
// try 17: modeled the two original typed current-row/current-tile locals while keeping the center as a direct indexed row expression.
// try 18: removed the obsolete raw byte-offset local from the typed candidate; verify that the compiler derives the same tile stride naturally.

typedef unsigned char uchar;

#ifndef MAP_CONTEXT_H
struct RGE_Tile {
    char gap0[5];
    uchar terrain_type : 5;
    uchar height : 3;
    char rest[0x12];
};

class RGE_Map {
public:
    char gap0[8];
    long map_width;
    long map_height;
    char gap10[0x8d8c-0x10];
    RGE_Tile** map_rows;
    uchar get_tile_type(short x, short y);
};

#endif

uchar RGE_Map::get_tile_type(short x, short y)
{
    long width;
    long height;
    RGE_Tile** rows;
    RGE_Tile* row;
    RGE_Tile* tile;
    unsigned short c, cp1, cm1;
    unsigned short nw, n, ne, w, e, sw, s, se;

    if (x < 0) return 0;
    if ((long)x >= this->map_width) return 0;
    width = this->map_width;
    if (y < 0) return 0;
    height = this->map_height;
    if ((long)y >= height) return 0;

    rows = this->map_rows;
    row = rows[y];
    tile = row + x;
    c = (unsigned short)rows[y][x].height;
    cp1 = c + 1;
    cm1 = c - 1;

    if (y > 0 && (long)x < width - 1) nw = (unsigned short)rows[y - 1][x + 1].height; else nw = c;
    if (y > 0) n = (unsigned short)rows[y - 1][x].height; else n = c;
    if ((long)x < width - 1) e = (unsigned short)tile[1].height; else e = c;
    if (x > 0 && (long)y < height - 1) sw = (unsigned short)rows[y + 1][x - 1].height; else sw = c;
    if (x > 0) w = (unsigned short)tile[-1].height; else w = c;
    if ((long)y < height - 1) s = (unsigned short)rows[y + 1][x].height; else s = c;
    if (y > 0 && x > 0) ne = (unsigned short)rows[y - 1][x - 1].height; else ne = c;
    if ((long)y < height - 1 && (long)x < width - 1) se = (unsigned short)rows[y + 1][x + 1].height; else se = c;

    if (n == cp1 && e == cp1) return 0x0e;
    if (w == cp1 && s == cp1) return 0x0d;
    if (n == cp1 && w == cp1) return 0x10;
    if (e == cp1 && s == cp1) return 0x0f;
    if (n == cp1) return 6;
    if (e == cp1) return 8;
    if (w == cp1) return 5;
    if (s == cp1) return 7;
    if (nw == cp1) {
        if (w == cm1 && s == cm1) return 2;
        return 0x0a;
    }
    if (sw == cp1) {
        if (n == cm1 && e == cm1) return 1;
        return 9;
    }
    if (ne == cp1) {
        if (e == cm1 && s == cm1) return 3;
        return 0x0b;
    }
    if (se == cp1) {
        if (n == cm1 && w == cm1) return 4;
        return 0x0c;
    }
    return 0;
}
