// PointMaker::MakeFirstLink
// VA: 0044B610 - from Ghidra decomp

// Attempt log:
// - Baseline explicit absolute-value ternaries produced a 320-byte function;
//   the source was structurally short because VC5 lowered the sign test as a
//   branch instead of the original branchless signed-remainder sequence.
// - Replaced each sign test with the natural signed remainder predicate
//   `r % 2`; this restored 332-byte size, 4/4 call-site parity, 89% exact-block
//   coverage, and the original branchless parity bytes.  The remaining 193
//   bytes are chiefly the dx/dy callee-save/register roles and the following
//   liveness schedule.
// - Register-qualified dx/dy probes were codegen duplicates.  Operand-order
//   (`dx + x`, `dy + y`) and canonical PrimaryPt/PtToPt array ownership probes
//   were also duplicates.  Restored the simplest typed/raw surface that keeps
//   the signed-remainder basin; no allocator-only scaffolding retained.
// - Inline parity calls (rather than a reusable `r` local) moved dx/dy into the
//   original EDI/EBX roles and reduced the positional diff from 193 to 187;
//   coordinate/store-order variants were duplicates.  Kept the inline calls as
//   the cleanest period-plausible source; remaining drift is the early
//   coordinate block's VC5 scheduling/liveness.

// orch-fractal-02 pass (2026-08-10):
// - Separate top-scoped coordinate declarations/loads, stored-direction
//   dependencies, assignment expressions, and a diagnostic volatile DirX
//   store all reproduced the same 332-byte/187-byte basin.
// - Coordinate-liveness lab #37 covered direction-seeded locals, field/self
//   aliases, local point aggregates, assignment-expression stores, and seeded
//   member updates; all 8 variants kept size/frame/call-set and no variant
//   improved the +0x86 coordinate hunk.
// - Long coordinate locals, explicit this-qualified direction-first additions,
//   the full same-TU PointMaker method declaration surface, and register-
//   qualified x/y snapshots were codegen duplicates.
// - Restored the clean signed-remainder source. Remaining drift starts at
//   +0x86/+0x0085 and is the x/y/direction coordinate register/liveness basin;
//   the parity block and late bound/store blocks remain aligned.
// - A focused period-header context lab found that the donor-era combination
//   of <stdlib.h> and <string.h> changes only the VC5 coordinate scheduling;
//   the exact winner restores the original 332-byte body and all 100
//   instructions. Single-header variants were not exact.
// - Replaced the flat decompiler Point/Prime view with the donor-proven
//   PrimaryPt/PtToPt ownership; emitted bytes stayed exact. Final source is
//   the typed, header-context reconstruction, with no custom flags or hacks.

extern int __cdecl debug_rand(char* param_1, int param_2);

#include <stdlib.h>
#include <string.h>

#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PrimaryPt {
public:
    int x;
    int y;
};

class PtToPt {
public:
    int x;
    int y;
};

// Main-agent audit confirmed canonical point/link ownership and signed random
// parity semantics.
class PointMaker {
public:
    PrimaryPt Prime;
    PtToPt Point[500];
    char gap_FA8[0x10];
    int x;
    int y;
    char gap_FC0[0x14];
    int Width;
    int Height;
    char gap_FDC[0x04];
    int NumNodes;
    char gap_FE4[0x08];
    int ProbabilityTiles;
    int TargetProbabilityCount;
    int ProbabilityAdd;
    int BranchRadius;
    int SatelliteRadius;
    int PrimaryRadius;
    int SizeArrays;
    int SatelliteDistance;
    int BranchDistance;
    int DirX;
    int DirY;
    int MaxNumberOfBranchLevels;
    int CurrentNumberOfBranchLevels;
    char gap_1020[0x24];
    int LeftLimit;
    int RightLimit;
    int TopLimit;
    int BottomLimit;

    int MakeFirstLink();
};
#endif

int PointMaker::MakeFirstLink() {
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x134);
    dx = dx % BranchDistance + 2;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x134) % 2)
        dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x135);
    dy = dy % BranchDistance + 2;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x135) % 2)
        dy = -dy;

    DirX = dx;
    int nx = x + dx;
    int ny = y + dy;
    DirY = dy;

    if (nx < LeftLimit) {
        nx = LeftLimit;
        if (dx < 0) DirX = -dx;
    }

    if (ny < TopLimit) {
        ny = TopLimit;
        if (dy < 0) DirY = -dy;
    }

    if (nx >= RightLimit) {
        nx = RightLimit - 1;
        if (DirX > 0) DirX = -DirX;
    }

    if (ny >= BottomLimit) {
        ny = BottomLimit - 1;
        if (DirY > 0) DirY = -DirY;
    }

    y = ny;
    x = nx;
    Point[NumNodes].x = nx;
    Point[NumNodes].y = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}
