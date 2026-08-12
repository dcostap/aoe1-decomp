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

extern int __cdecl debug_rand(char* param_1, int param_2);

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
    if (Width - 5 <= dx) dx = Width - 5;
    if (dy < 5) dy = 5;
    if (Height - 5 <= dy) dy = Height - 5;

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
    Point[NumNodes * 2] = dx;
    Point[NumNodes * 2 + 1] = dy;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}
