// 004564E0 RGE_Map::preclean_elevation
// map.cpp
// Attempt log:
// try 1: reconstructed elevation preclean pass: clamp rectangle, scan tiles, compare 8 neighbors, raise/lower center or neighbors when slopes conflict.
// try 2: modeled RGE_Map fields: width +0x08, height +0x0C, row pointer table +0x8D8C, tile stride 0x18, elevation in byte +5 high 3 bits.
// try 3: modeled edge expansion/clamping of x1/y1/x2/y2 and repeated do-while until no change.
// try 4: modeled per-tile neighbor comparisons for N/S/E/W and diagonals against current elevation.
// try 5: modeled conflict detection when opposite high neighbors exist and maxElev threshold decides whether to raise current tile or lower neighbors.
// try 6: factored elevation get/set into local helpers; rebuild still exact size 985B but broad mismatch.
// try 7: reviewed first mismatch: original has 0x48 frame and precomputes signed neighbor offsets (`-width-1`, `-width`, `1-width`, `width+1`, etc.) before loops; rebuilt has 0x38 frame and recomputes via pointer arithmetic.
// try 8: original stores neighbor flags as stack dwords but tests them with word compares, and manually writes each neighbor byte with preserved low 5 bits; current source's int flags/helper calls produce different register/topology.
// try 9: behavior likely close for central smoothing, but exact source shape would need fully inlined per-neighbor checks/writes and original offset-local topology rather than helpers.
// try 10: validation after broad model: size matches 985B, but positional diff 884 / 89.75%, edit diff 1446 / 146.80%, first mismatch at frame size/local layout offset 2.
// left in scratch: size-matched broad reconstruction, but exact local layout, precomputed offsets, and inlined byte-write topology are unresolved. No accepted_drift: broad frame/control/data-layout drift.

struct MapTile { char b[24]; };
class RGE_Map {
public:
    char gap0[8];
    short width;
    short height;
    char gap0c[0x8D8C-0x0C];
    MapTile** rows;
    void preclean_elevation(long x1,long y1,long x2,long y2,unsigned char maxElev);
};

static unsigned char elev(MapTile* t) { return (unsigned char)(t->b[5] >> 5); }
static void set_elev(MapTile* t, unsigned char e) { t->b[5] = (unsigned char)((t->b[5] & 0x1f) | (e << 5)); }

void RGE_Map::preclean_elevation(long x1,long y1,long x2,long y2,unsigned char maxElev) {
    long oldx1;
    long changed;
    long x,y;
    unsigned char e;
    MapTile* row;

    do {
        changed = 0;
        if (x1 > 0) --x1;
        if (y1 > 0) --y1;
        if (x2 < width - 1) ++x2;
        if (y2 < height - 1) ++y2;

        for (y = y1; y <= y2; ++y) {
            row = rows[y] + x1;
            for (x = x1; x <= x2; ++x, ++row) {
                e = elev(row);
                int n=0,s=0,w=0,ee=0,nw=0,ne=0,sw=0,se=0;
                if (y > 0 && elev(row - width) > e) n=1;
                if (y < height-1 && elev(row + width) > e) s=1;
                if (x > 0 && elev(row - 1) > e) w=1;
                if (x < width-1 && elev(row + 1) > e) ee=1;
                if (y > 0 && x > 0 && elev(row - width - 1) > e) nw=1;
                if (y > 0 && x < width-1 && elev(row - width + 1) > e) ne=1;
                if (y < height-1 && x > 0 && elev(row + width - 1) > e) sw=1;
                if (y < height-1 && x < width-1 && elev(row + width + 1) > e) se=1;
                if ((n && s) || (w && ee)) {
                    if (e >= maxElev) {
                        set_elev(row, (unsigned char)(e + 1));
                    } else {
                        if (nw) set_elev(row-width-1, e);
                        if (n)  set_elev(row-width, e);
                        if (ne) set_elev(row-width+1, e);
                        if (w)  set_elev(row-1, e);
                        if (ee) set_elev(row+1, e);
                        if (sw) set_elev(row+width-1, e);
                        if (s)  set_elev(row+width, e);
                        if (se) set_elev(row+width+1, e);
                    }
                    changed = 1;
                }
            }
        }
    } while (changed);
}
