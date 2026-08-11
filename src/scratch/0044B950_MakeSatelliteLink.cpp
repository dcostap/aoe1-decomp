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
// - Fresh orch-fractal-fresh-03 probes confirmed direct x reloads, no cached
//   x, delayed dy accumulation, full PointMaker field declarations, and a
//   named direct-x candidate either regressed or duplicated the clean 149-byte
//   result. A 27-variant natural schedule lab likewise found no exact basin.
// - Moving the old_x snapshot after coordinate updates with direct x guards
//   changed the first candidate to mov/add and improved shape to 75.73% block
//   coverage, but left a 152-byte mismatch at the second horizontal guard;
//   reversing the commutative operands was a codegen duplicate. Restored the
//   cleaner old_x-before-update source; remaining drift is localized VC5
//   candidate/second-bound scheduling, not a proven ownership or ABI issue.
// - Fresh sa-7af9de30-r1-0044B950 pass: complete same-TU method declarations,
//   candidate_x copy/compound and expanded forms, old_x declaration placement,
//   and direct-x reread hybrids were duplicates or regressed (best retained
//   source remains 149 differing bytes).  A 7-variant candidate-sum lab also
//   collapsed to the same 149-byte emitted group; no exact natural basin found.

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
