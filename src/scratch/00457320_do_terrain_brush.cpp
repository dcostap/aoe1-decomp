// do_terrain_brush
// VA: 00457320
// map.cpp lines 1205-1230
// Retry 2026-05-19/20 assigned pass:
// - Replaced stub with natural RGE_Map::do_terrain_brush(long x,long y,long radius,uchar terrain) and set_terrain member call; reached exact size 145B.
// - Initial natural bounds/loops: 62.7586% positional / 68.9655% edit; first mismatch +4 because compiler preloads x/y before saving registers and assigns y1/x2 to EBX/EBP instead of original EBP/EBX.
// - Reordered radius arithmetic to keep source `radius += y`/stack-slot style closer to original; edit diff improved to 39.3103% but same broad register allocation mismatch.
// - Tried `register long r = radius` and /Ob0 flag probe: no change; flag removed.
// GIVEUP: behavior, call signature, bounds, loop structure, and offsets are understood, but remaining mismatch is broad early parameter-load/register-allocation drift (original loads radius first then saves regs; rebuilt preloads y and swaps EBX/EBP roles). No accepted_drift: broad loop/register topology drift, not localized.

#include "../../include/game_globals.h"

class RGE_Map {
public:
    char gap_00[8];
    int map_width;      // +0x08
    int map_height;     // +0x0C
    char gap_10[0x8DC0 - 0x10];
    void* game_world;   // +0x8DC0

    void set_terrain(void* world, int x, int y, unsigned char terrain, int a, int b);
    unsigned char do_terrain_brush(long x, long y, long radius, unsigned char terrain);
};

unsigned char RGE_Map::do_terrain_brush(long x, long y, long radius, unsigned char terrain)
{
    register long r = radius;
    long x2 = r + x;
    long x1 = x;
    long y1 = y;
    x1 -= r;
    y1 -= r;
    r += y;

    if (x1 < 0)
        x1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y1 < 0)
        y1 = 0;
    if (r >= this->map_height)
        r = this->map_height - 1;

    for (; y1 <= r; y1++) {
        for (long i = x1; i <= x2; i++) {
            this->set_terrain(this->game_world, i, y1, terrain, 0, 0);
        }
    }
    return 1;
}
