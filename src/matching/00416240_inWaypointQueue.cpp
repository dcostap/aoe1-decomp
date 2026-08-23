// VA: 00416240 UnitAIModule::inWaypointQueue(int, int) const
// PDB source: aiuaimod.cpp lines 2971-2977 (80 bytes, 31 asm lines)
// Default flags
//
// __thiscall: this in ecx, 2 stack params (int x, int y). ret 8 cleanup.
// Exact with default flags after reshaping the loop tail.
// Key source shape: positive outer guard + `while (1)` loop with bottom
// `if (i < waypointQueueSize) continue; return 0;`, and y-match routed through
// `goto found;` so VC5 keeps the original `jl loop` backedge and places the
// loop-fail return before the success return while the early-empty return stays last.
// Tried first: natural do-while remained at 70/80 bytes equal with `jge exit; jmp loop` drift;
// direct `return 1` in the while/continue shape kept that same drift. The goto-found tail matched.
// Waypoint struct: 0x10 bytes (float x,y,z + 1 byte), array at this+0x70, size at this+0xF0.

#include "../../include/aiuaimod_context.h"

int UnitAIModule::inWaypointQueue(int x, int y) const {
    int i = 0;
    if (waypointQueueSizeValue > 0) {
        float fx = (float)x;
        while (1) {
            if (waypointQueue[i].x == fx) {
                if ((float)y == waypointQueue[i].y) goto found;
            }
            i++;
            if (i < waypointQueueSizeValue) continue;
            return 0;
        }
found:
        return 1;
    }
    return 0;
}
