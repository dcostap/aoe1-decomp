// 00457510 RGE_Map::do_elevation_brush
// GIVEUP 2026-05-21: best retained source is behaviorally correct and exact-sized (171B) but broad mismatch remains.
// Best validation: 171B, 89.4737% positional / 41.5205% edit, first mismatch 12.
// Tried natural for-loop, char-pointer no-division loop, while/do outer forms, parameter-reuse for minY/maxY,
// row local vs per-iteration row reload, no elevation temp, unsigned-char row pointer surface, y-local-first,
// and flags /Ob0, /O2-no-/Oy, /Oa, /O1, /G5. Parameter-reuse recovers the original first two arg loads and
// exact size, but VC5 still orders the y load after saving EDI and keeps minY in ESI instead of EDX, causing
// broad register/topology drift through the loops. Not accepted_drift-safe.

struct MapCell {
    char gap[5];
    unsigned char elev;
    char rest[18];
};

struct RGE_Map {
    char gap[8];
    int map_width;
    int map_height;
    char gap2[0x8D7C];
    MapCell** map_row_offset;

    unsigned char do_elevation_brush(long x, long y, long radius, unsigned char elevation);
};

unsigned char RGE_Map::do_elevation_brush(long x, long y, long radius, unsigned char elevation)
{
    long minx = x - radius;
    long maxx = x + radius;
    x = y - radius;
    radius = radius + y;

    if (minx < 0)
        minx = 0;
    if (maxx >= this->map_width)
        maxx = this->map_width - 1;
    if (x < 0)
        x = 0;
    if (radius >= this->map_height)
        radius = this->map_height - 1;

    if (x <= radius) {
        do {
            if (minx <= maxx) {
                unsigned char elev = (unsigned char)(elevation << 5);
                int offset = minx * 24;
                int count = maxx - minx + 1;
                do {
                    unsigned char* row = (unsigned char*)this->map_row_offset[x];
                    unsigned char v = row[offset + 5];
                    row[offset + 5] = (v & 0x1f) | elev;
                    offset += 24;
                    count--;
                } while (count);
            }
            x++;
        } while (x <= radius);
    }
    return 1;
}
