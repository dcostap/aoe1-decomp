// TRIBE_Map::do_terrain_brush_stroke
// VA: 0050FD40
// tmap.cpp:356-396
// 133 bytes, not yet matched (parked)
// Complex function: 6 params + thiscall, base class call, conditional swap/adjust,
// final function call with adjusted coords. 5 callee-saved regs used.
// Attempt log:
// v0: direct function pointer call → wrong indirect call + superfluous param
// v1: RGE_Map base class call + temp locals → 144 bytes (casts + reg pressure)
// v2: RGE_Map base class call, no temps → 144 bytes
// v3: same but more explicit → still 144 bytes
// 2026-05-10 StarryZephyr pass: tried typed member `tribe_clean_terrain` and long-param natural rectangle source; produced
// 128-byte too-short text window. Restored comparable baseline. Remaining drift is broad parameter/register ordering and final
// call cleanup; no accepted_drift.

#include "../../include/game_globals.h"

class RGE_Map {
public:
    unsigned char do_terrain_brush_stroke(int p1, int p2, int p3, int p4, int p5, unsigned char p6);
};

class TRIBE_Map : public RGE_Map {
public:
    unsigned char do_terrain_brush_stroke(int p1, int p2, int p3, int p4, int p5, unsigned char p6);
};

extern void tribe_clean_terrain(TRIBE_Map* map, int x1, int y1, int x2, int y2, int flag, unsigned char terrain);

unsigned char TRIBE_Map::do_terrain_brush_stroke(int p1, int p2, int p3, int p4, int p5, unsigned char p6) {
    RGE_Map::do_terrain_brush_stroke(p1, p2, p3, p4, p5, p6);

    int brush = p5;
    int left, right;

    if (p1 < p3) {
        left = p1 - brush;
        right = p3 + brush;
    } else {
        left = p3 - brush;
        right = p1 + brush;
    }

    int top, bottom;

    if (p2 < p4) {
        top = p2 - brush;
        bottom = p4 + brush;
    } else {
        top = p4 - brush;
        bottom = p2 + brush;
    }

    tribe_clean_terrain(this, left - 2, top - 2, right + 2, bottom + 2, 1, p6);
    return 1;
}
