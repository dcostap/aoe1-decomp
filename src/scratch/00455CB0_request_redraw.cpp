// RGE_Map::request_redraw
// VA: 00455CB0
// map.cpp
// Attempt log:
// try 1: natural member implementation with x0/y0/x1/y1 locals; correct size but broad drift, compiler uses EBP/EDI differently and hoists inner loop shape.
// try 2: decompiler-style iVar locals and param mutation; worsened prologue/register allocation.
// try 3: free __fastcall surface matching ECX + 5 stack args; worsened with early parameter preloads.
// try 4: /Ob1 flag probe on fastcall surface; no improvement.
// try 5: no self local / direct this access; no improvement.
// try 6: register self local; no improvement.
// try 7: predeclared shared swap temp; no improvement.
// try 8: while loop with explicit y0 increment instead of for; no improvement.
// try 9: positive nested bounds gates; no improvement.
// try 10: /O1 produced too-small wrong-family object; /O2 without /Oy and /Gs matched baseline; /Od wrong family.
// GIVEUP: left in scratch. Behavior is understood, but current best remains broad codegen/register-allocation drift: original uses push ecx and stores this in EBX/[esp+10], keeps x0 in ESI, x1 in EDI, y0 in EAX/EBP, y1 in ECX/stack, and precomputes x0*24 once outside the row loop. VC5 variants keep choosing EBP/EDI differently, preload parameters too early, or recompute row/x offsets in a shorter different loop family. Not proposing accepted_drift because the mismatch is broad, not localized harmless drift.

class RGE_Map {
public:
    char gap_00[0x08];
    int map_width;   // +0x08
    int map_height;  // +0x0C
    char gap_10[0x8D7C];
    unsigned char** map_row_offset; // +0x8D8C

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
        if (x0 < 0) {
            x0 = 0;
        }
        if (y0 < 0) {
            y0 = 0;
        }
        if (x1 >= self->map_width) {
            x1 = self->map_width - 1;
        }
        if (y1 >= self->map_height) {
            y1 = self->map_height - 1;
        }

        for (; y0 <= y1; ++y0) {
            if (x0 <= x1) {
                unsigned char* p = self->map_row_offset[y0] + x0 * 0x18 + 0x0A;
                int count = x1 - x0 + 1;
                do {
                    p[-3] = 0xCC;
                    *p = val;
                    p += 0x18;
                    --count;
                } while (count != 0);
            }
        }
    }
}
