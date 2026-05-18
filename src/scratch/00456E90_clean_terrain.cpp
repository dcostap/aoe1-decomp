// 00456E90 RGE_Map::clean_terrain
// Attempt log:
// try 1: packet-grounded reconstruction. Models clamped rectangle expansion, two cleanup passes, 8-neighbor same-terrain tests, and set_terrain calls when edge/corner patterns need cleaning. Compiles too short (976B vs 1127B).
// try 2: modeled initial clamp of x1/y1 to >=0 and x2/y2 to width-1/height-1.
// try 3: modeled per-iteration rectangle expansion before each cleanup pass (decrement mins, increment maxes inside bounds).
// try 4: modeled outer repeat-until-no-change loop using changed/again byte equivalent.
// try 5: modeled two pass loop; pass 0 checks cardinal neighbors, pass 1 includes diagonals.
// try 6: modeled map row table at +0x8d8c and 24-byte tile stride with terrain byte at tile+5 masked by 0x1f.
// try 7: modeled north/south/east/west neighbor checks with edge guards.
// try 8: modeled diagonal checks in second pass and corner/edge cleanup predicates.
// try 9: modeled set_terrain call with terrain_system at +0x8dc0 and args (terrain,y/x,0,0) approximation.
// try 10: tried factoring neighbor test as a static helper first; still too short because original keeps all neighborhood tests inline and has specific stack-slot/word-test topology.
// GIVEUP blockers: exact original cleanup predicates for pass 0/pass 1, row-vs-linear neighbor addressing (original uses +/- width-derived stride constants and tile offsets), set_terrain signature/argument order, and preserving original stack-slot word-test topology. No inline asm used; no accepted_drift proposal.

struct MapTile { char gap[5]; unsigned char terrain; char rest[18]; };
extern void __cdecl set_terrain_00459900(void*, int, int, int, int, int);

class RGE_Map {
public:
    int vptr; short width; short height; char gap10[0x8d7c]; MapTile** rows; char gap8d90[0x30]; void* terrain_system;
    void clean_terrain(int x1, int y1, int x2, int y2, int terrain);
};

static int same(MapTile* t, int off, int terrain)
{
    return ((t[off].terrain & 0x1f) == (terrain & 0xff));
}

void RGE_Map::clean_terrain(int x1, int y1, int x2, int y2, int terrain)
{
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= this->width) x2 = this->width - 1;
    if (y2 >= this->height) y2 = this->height - 1;
    int again;
    do {
        again = 0;
        if (x1 > 0) --x1;
        if (y1 > 0) --y1;
        if (x2 < this->width - 1) ++x2;
        if (y2 < this->height - 1) ++y2;
        for (int pass = 0; pass < 2; ++pass) {
            for (int y = y1; y <= y2; ++y) {
                MapTile* tile = this->rows[y] + x1;
                for (int x = x1; x <= x2; ++x, ++tile) {
                    unsigned char cur = tile->terrain & 0x1f;
                    if (cur == (unsigned char)terrain) continue;
                    int n=0,s=0,w=0,e=0,nw=0,ne=0,sw=0,se=0;
                    if (y > 0) n = same(tile, -this->width, terrain);
                    if (y < this->height - 1) s = same(tile, this->width, terrain);
                    if (x > 0) w = same(tile, -1, terrain);
                    if (x < this->width - 1) e = same(tile, 1, terrain);
                    if (pass == 1) {
                        if (y > 0 && x > 0) nw = same(tile, -this->width-1, terrain);
                        if (y > 0 && x < this->width-1) ne = same(tile, -this->width+1, terrain);
                        if (y < this->height-1 && x > 0) sw = same(tile, this->width-1, terrain);
                        if (y < this->height-1 && x < this->width-1) se = same(tile, this->width+1, terrain);
                    }
                    int fix = 0;
                    if (pass == 0) {
                        if ((n && s) || (w && e)) fix = 1;
                    } else {
                        if (nw && (!n || !w)) fix = 1;
                        if (ne && (!n || !e)) fix = 1;
                        if (sw && (!s || !w)) fix = 1;
                        if (se && (!s || !e)) fix = 1;
                        if (n && e && !ne) fix = 1;
                        if (e && s && !se) fix = 1;
                        if (s && w && !sw) fix = 1;
                        if (w && n && !nw) fix = 1;
                    }
                    if (fix) {
                        set_terrain_00459900(this->terrain_system, x, y, terrain, 0, 0);
                        again = 1;
                    }
                }
            }
        }
    } while (again);
}
