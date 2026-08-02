// RGE_Map::request_redraw
// VA: 00455CB0
// map.cpp
// Attempt log:
// Prior pass tried natural member implementation with x0/y0/x1/y1 locals, decompiler-style
// param mutation, free __fastcall surface, /Ob1, no self local/direct this, register self,
// shared swap temp, while loop, positive nested bounds gates, and flags /O1 /O2-no-/Oy /Gs /Od.
// Best remained exact-sized but broad register/topology drift.
// Current Boss retry:
// 1: Revalidated best scratch: 175B, 95.4286% positional / 46.8571% edit, first mismatch +3.
// 2: Natural independent min/max locals like matched do_elevation_brush: worsened first mismatch +1,
//    because VC5 preloads parameters before saved-register setup.
// 3: Added separate y loop local with for; no change from best.
// 4: Changed outer y loop to guarded do/while; no change from best.
// 5: register x0/x1 formals; no change from best.
// 6: maxx/minx declaration-order probe; worsened first mismatch +1.
// 7: Swapped-predicate spelling (`x1 < x0`, nested positive bounds): better positional (74.8571%)
//    but much worse edit/control flow and still wrong early EBP/ESI coloring.
// 8: Removed self local/direct this; no change from best.
// 2026-05-26 Boss retry: 10 more probes. Revalidated baseline; tried swapped/min locals with x1<x0,
// register x1 parameter, volatile x1 parameter/local, precomputed x-offset outside the row loop,
// direct-this/no-self, while outer loop, row pointer local, explicit `(x+x*2)<<3` tile offset,
// register self, and alternate y swap predicate/order. None matched; precomputed x-offset improved
// positional to 62.2857% but destroyed edit/control-flow shape, while alternate y swap reached
// 74.8571% positional / 49.7143% edit but kept wrong EBP/EDI roles. Best kept is still baseline.
// GIVEUP: not accepted_drift-worthy. Behavior is understood, but mismatch is broad: original pushes
// ecx/ebx/ebp/esi before loading x0/x1, uses ESI=x0, EDI=x1, EBX=this/height, EBP=y0, ECX/y1 stack,
// and precomputes x0*24 once outside the row loop. VC5 variants either preload x1 into EBP before
// `push esi`, use EBP as maxx instead of EDI, or choose a shorter/nested branch family.
// Luna455CB0 pass (2026-08-02, 10/10 meaningful probes): dossier confirms map_width +08,
// map_height +0C, map_row_offset +8D8C, tile stride 0x18, draw_attribute +0A. Typed tile
// ownership/decompiler-local forms and register-qualified y parameters did not recover the
// target prologue. A 64-variant source-shape lab found no exact; explicit x0*24 outside the
// row loop was the metric best (109 positional bytes / 85.90% shape) but is not the cleanest
// source and moved the loop topology. The final clean candidate below is exact-sized, with
// remaining drift broad in register coloring, row/offset scheduling, and early block layout.
// Luna455CB0b sequential pass (2026-08-02):
// 1: Full ground-truth RGE_Map/RGE_Tile declaration surface from exact map.cpp donors; no emitted change.
// 2: register-qualified early row cursor moved to 160 positional bytes and recovered ESI=x0/EDI=x1,
//    EBP=row, but loaded y0 too early and retained the wrong y1/map-width/map-height roles.
// 3: register row declared then assigned after clipping was a codegen duplicate of clean source.
// 4: explicit post-swap min/max aliases introduced a +10-byte structural tail; rolled back.
// 5-7: combined register self/row, direct-this/row, and zero-initialized late row assignment either
//    duplicated the 160-byte basin or clean baseline; no new lead.
// 8: register-qualified y1 with early row was also a duplicate.
// 9: focused 8-variant lab over y1/self/row surfaces produced only two groups (160/167 positional),
//    no exact. Clean typed source restored; remaining issue is broad VC5 register coloring and loop layout.

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char gap_0C[0x0C];
};

class RGE_Map {
public:
    char gap_00[0x08];
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
    void request_redraw(int x0, int y0, int x1, int y1, unsigned char val);
};

void RGE_Map::request_redraw(int x0, int y0, int x1, int y1, unsigned char val)
{
    RGE_Map* self = this;

    if (x0 > x1) {
        int t = x0;
        x0 = x1;
        x1 = t;
    }
    if (y0 > y1) {
        int t = y0;
        y0 = y1;
        y1 = t;
    }

    if (x1 >= 0 && y1 >= 0 && x0 < self->map_width && y0 < self->map_height) {
        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 >= self->map_width) x1 = self->map_width - 1;
        if (y1 >= self->map_height) y1 = self->map_height - 1;

        while (y0 <= y1) {
            if (x0 <= x1) {
                unsigned char* p = &self->map_row_offset[y0][x0].draw_attribute;
                int count = x1 - x0 + 1;
                do {
                    p[-3] = 0xCC;
                    *p = val;
                    p += 0x18;
                    --count;
                } while (count != 0);
            }
            ++y0;
        }
    }
}
