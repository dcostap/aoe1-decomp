// PointMaker::MakeSatelliteLink
// VA: 0044B950 - from Ghidra decomp

// Attempt log:
// - Replaced explicit absolute-value sign tests with the natural signed
//   remainder predicate `r % 2`, restoring the original branchless parity
//   lowering and 336-byte size.
// - Capturing old_x across the horizontal bounds is binary-supported by the
//   original EBP lifetime and improved the reconstruction to 149 differing
//   bytes with all four calls and CFG/count parity aligned.  The vertical
//   source intentionally rereads y, and preserves the original lower-bound
//   bug `dy = -dx`.
// - Upper-bound predicates use the binary-supported sum >= limit-3 spelling.
//   Candidate temporary/compound scheduling, declaration order, and canonical
//   PrimaryPt/PtToPt point-array layout probes were duplicates or regressed;
//   retained the clean typed source rather than allocator-only scaffolding.
// - Inline parity calls, several candidate_x declaration/update orders, and a
//   focused four-variant schedule lab all emitted the same 336-byte result.
//   The remaining first hunk is the target's mov/add candidate-x schedule
//   versus VC5's equivalent LEA; restored the clean direct bound expressions.

extern int __cdecl debug_rand(char* param_1, int param_2);

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

// Main-agent audit confirmed canonical point/link ownership and preserved the
// binary-observed dy=-dx bug.
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

    int MakeSatelliteLink();
};

int PointMaker::MakeSatelliteLink() {
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x165);
    dx = dx % SatelliteDistance + 1;
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x165);
    if (r % 2) dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x166);
    dy = dy % SatelliteDistance + 1;
    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x166);
    if (r % 2) dy = -dy;

    int old_x = x;
    dx += DirX;
    dy += DirY;

    if (dx + old_x < 3) {
        dx = -dx;
        DirX = -DirX;
    }

    if (dx + old_x >= Width - 3) {
        dx = -dx;
        DirX = -DirX;
    }

    if (dy + y < 3) {
        dy = -dx;  // original bug: uses -dx not -dy
        DirY = -DirY;
    }

    if (dy + y >= Height - 3) {
        dy = -dy;
        DirY = -DirY;
    }

    x = dx + old_x;
    y = dy + y;
    Point[NumNodes].x = x;
    Point[NumNodes].y = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}
