// 004BE090 TSpan_List_Manager::AddLine_Align (spanlist.cpp:961-1053, 337B)
//
// Attempt log:
// - Initial Bresenham impl: 320 bytes, prologue misses early x1->eax load
// - int x1v = x1; forces eax load before push ebx, prologue matches first 13 bytes
//   but extra mov edi,eax; mov esi,[esp+18h] add 5 bytes, rest is ~12 bytes shorter
// - Full class + a/b at function scope: 336 bytes (missing push ecx due to inherit)
// - TODO: eliminate extra mov edi,eax by not saving x1v in vertical case
// - A direct parameter-mutating reconstruction from the binary's stack-home
//   topology added a call site and widened the function; restored x1v source.
// - Removing /GX was a codegen duplicate; full manager context, function-scope
//   a/b, and direct-x1 nonvertical variants were also duplicates or worse.
// - Spanlist stdlib/string header context, split x1v assignment, scoped y
//   copies, early-return guards, for-loop rewrites, and a Ghidra-shaped
//   parameter-mutation source were tested; none improved the retained basin.
// - Session sa9f8966ac_r1: direct parameter-home mutation reached 334 bytes
//   with the same five calls but a worse positional/resync basin; restored.
// - The same-TU DrawLine donor loop family emitted six AddSpan calls, while a
//   Ghidra-local-order variant emitted 332 bytes but the same 324-byte diff;
//   x1v declaration-order changes were codegen duplicates. A 256-variant
//   local/parameter lab found no exact or structurally useful group.
// - Retained natural x1v Bresenham source: exact call set/CFG and 316-byte
//   output remain, with structural drift concentrated in prologue liveness and
//   later induction scheduling.
// FLAGS: /nologo /c /O2 /Oy /GX

// Main-agent audit confirmed canonical span-manager ownership and retained the
// natural aligned Bresenham construction.
#include <stdlib.h>

class TSpan_List_Manager {
public:
    void AddSpan(int left, int right, int line);

    void AddLine_Align(int x1, int y1, int x2, int y2);
};

void TSpan_List_Manager::AddLine_Align(int x1, int y1, int x2, int y2)
{
    int x1v = x1;
    if (x1v == x2) {
        if (y1 > y2) { int t = y1; y1 = y2; y2 = t; }
        int a = x1v & ~3;
        int b = x1v | 3;
        while (y1 <= y2) { AddSpan(a, b, y1); y1++; }
    } else if (y1 == y2) {
        AddSpan(x1v & ~3, x2 | 3, y1);
    } else {
        if (x2 < x1v) {
            int tx = x1v; x1v = x2; x2 = tx;
            int ty = y1; y1 = y2; y2 = ty;
        }
        int dy = x2 - x1v + 1;
        int dx, step_y;
        if (y1 < y2) { dx = y2 - y1 + 1; step_y = 1; }
        else { dx = y1 - y2 + 1; step_y = -1; }
        if (dx >= dy) {
            int err = 0;
            int span_x = x1v;
            int cur_x = x1v;
            while (cur_x < x2) {
                err += dx;
                if (err >= dy) {
                    AddSpan(span_x & ~3, cur_x | 3, y1);
                    y1 += step_y;
                    err -= dy;
                    span_x = cur_x + 1;
                }
                cur_x++;
            }
            AddSpan(span_x & ~3, cur_x | 3, y1);
        } else {
            int err = 0;
            while (1) {
                AddSpan(x1v & ~3, x1v | 3, y1);
                if (x1v == x2) break;
                err += dy;
                if (err >= dx) { y1 += step_y; err -= dx; }
                x1v++;
            }
        }
    }
}
