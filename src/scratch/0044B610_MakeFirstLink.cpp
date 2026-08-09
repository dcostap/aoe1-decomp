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

extern int __cdecl debug_rand(char* param_1, int param_2);

// Main-agent audit confirmed canonical point/link ownership and signed random
// parity semantics.
class PointMaker {
public:
    int Prime_x;
    int Prime_y;
    int Point[1000];
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
    Point[NumNodes * 2] = nx;
    Point[NumNodes * 2 + 1] = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}
