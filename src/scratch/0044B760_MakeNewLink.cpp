// PointMaker::MakeNewLink
// VA: 0044B760 - from Ghidra decomp

// Attempt log:
// - Reconstructed the natural signed-remainder parity gates, old-coordinate
//   accumulation, and the binary-observed dy = -dx lower-bound bug.
// - Added the proven max_x stack local and removed the upper vertical DirY
//   store present in the initial scaffold; this recovered exact size and
//   reduced the positional diff from 255 to 71 bytes.
// - Operand-order, max_y declaration, reusable/inline parity, and post-clamp
//   variants did not improve the 71-byte result.  The remaining drift is the
//   localized EBX/EDI direction coloring and max_x/max_y clamp compare shape;
//   retained the readable source rather than register-forcing scaffolding.
// - Fresh tu-fractal-44B760 pass: donor <stdlib.h>/<string.h> headers, moving
//   max_x/r declarations, and period-style top declarations were codegen
//   duplicates.  The exact-size source still has eight aligned calls and the
//   same CFG; remaining drift is the EBX/EDI direction swap and clamp compare.
// - Reverse top declaration order for dx/dy as a natural liveness probe; the
//   emitted code was unchanged.  Restored the clean source; the remaining
//   evidence-backed lead is the early direction register coloring and paired
//   clamp compare hunk.
// - Moved all coordinate and bound locals to one top declaration block as a
//   natural period-style lifetime probe; codegen was unchanged and the clean
//   source was restored.
// - A typed PtToPt local carrying the link coordinates was codegen-identical;
//   restored it and kept the simpler scalar coordinate source.
// - Spelled final coordinate clamps with the coordinate on the left; this
//   recovered the target compare polarity and reduced the diff to 69 bytes.
// - Replaced the raw Point integer array with the canonical typed PtToPt
//   array, and stored its fields from the updated x/y members.  This preserved
//   the natural ownership and reduced the diff to 44 bytes with 156 emitted
//   instructions.  The remaining drift is the early EBX/EDI direction swap;
//   the late store block is otherwise aligned except for that register role.
// - Fresh matching pass: reusable parity locals, declaration and initialization
//   order, update and store order, full PointMaker field types, and direct sum
//   expressions were duplicate or worse basins.  The protected declaration
//   restores the original IAEHXZ symbol without changing code bytes.
// - Fresh delegated revisit: direct Point.x and Point.y local stores, plus an
//   old-style top declaration order, were neutral or worse.  The clean typed
//   source remains at 44 differing bytes; the EBX/EDI direction map is still
//   unresolved without compiler steering.

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

protected:
    int MakeNewLink();
};

int PointMaker::MakeNewLink() {
    int max_x;
    int r;
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14a);
    dx = dx % BranchDistance + 1;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14a) % 2)
        dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14b);
    dy = dy % BranchDistance + 1;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14b) % 2)
        dy = -dy;

    int old_x = x;
    dx += DirX;
    dy += DirY;

    if (dx + old_x < 5) {
        dx = -dx;
        DirX = -DirX;
    }

    max_x = Width - 5;
    int sum_x = dx + old_x;
    if (sum_x >= max_x) {
        dx = -dx;
        DirX = -DirX;
    }

    int old_y = y;
    if (dy + old_y < 5) {
        dy = -dx;
        DirY = -DirY;
    }

    int max_y = Height - 5;
    if (dy + old_y >= max_y) {
        dy = -dy;
    }

    dx += old_x;
    dy += old_y;

    if (dx < 5) dx = 5;
    if (dx >= Width - 5) dx = Width - 5;
    if (dy < 5) dy = 5;
    if (dy >= Height - 5) dy = Height - 5;

    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15a);
    if (r % 2) {
        r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15a);
        DirX = DirX + r % 3 - 1;
    }

    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15b);
    if (r % 2) {
        r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15b);
        DirY = DirY + r % 3 - 1;
    }

    x = dx;
    y = dy;
    Point[NumNodes].x = x;
    Point[NumNodes].y = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}
