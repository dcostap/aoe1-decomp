// VA: 00416240 UnitAIModule::inWaypointQueue(int, int) const
// PDB source: aiuaimod.cpp lines 2971-2977 (80 bytes, 31 asm lines)
// Default flags
//
// __thiscall: this in ecx, 2 stack params (int x, int y). ret 8 cleanup.
// 70/80 edit-match bytes, 13-byte edit diff. Left in scratch.
//
// Stable VC5-version differences:
//
// 1. Loop back pattern: Original uses `jl loop` (2 bytes, natural direction).
//    VC5 generates `jge exit; jmp loop` (4 bytes, inverted direction) for the
//    same `do { ... } while (++i < size)` structure. All combinations of
//    for/while/do-while/goto produce the same inverted pattern.
//
// Everything else matches perfectly:
// - xor edx,edx at 00416247 (before test/jle) ✓
// - add ecx,74h (modifying this to point to waypoint[0].y) ✓
// - fld [ecx-4] for waypoint[0].x, fcomp [ecx] for waypoint[0].y ✓
// - jne short found for return 1 on y match ✓
// - je for skip-on-x-mismatch ✓
// - inc edx; add ecx,10h for loop increment ✓
// - Return 0 early path ✓
//
// Waypoint struct: 0x10 bytes (float x,y,z + 1 byte), array at this+0x70, size at this+0xF0.

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facet;
};

class UnitAIModule {
public:
    char gap_00[0x70];
    Waypoint waypointQueue[8];
    int waypointQueueSize;

    int inWaypointQueue(int x, int y) const;
};

int UnitAIModule::inWaypointQueue(int x, int y) const {
    int i = 0;
    if (waypointQueueSize <= 0) return 0;

    float fx = (float)x;

    do {
        if (waypointQueue[i].x == fx) {
            if ((float)y == waypointQueue[i].y) return 1;
        }
    } while (++i < waypointQueueSize);

    return 0;
}
