// PointMaker::MakeNewLink
// VA: 0044B760 - from Ghidra decomp

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
    int dx = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14a);
    dx = dx % BranchDistance + 1;
    int r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14a);
    int abs_r = r < 0 ? -r : r;
    if (abs_r & 1) dx = -dx;

    int dy = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14b);
    dy = dy % BranchDistance + 1;
    r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14b);
    abs_r = r < 0 ? -r : r;
    if (abs_r & 1) dy = -dy;

    int ndx = dx + DirX;
    int ndy = dy + DirY;

    if (ndx + x < 5) {
        dx = -dx;
        DirX = -DirX;
    }

    if (Width - 5 <= ndx + x) {
        dx = -dx;
        DirX = -DirX;
    }

    if (ndy + y < 5) {
        dy = -dx;
        DirY = -DirY;
    }

    if (Height - 5 <= ndy + y) {
        dy = -dy;
        DirY = -DirY;
    }

    dx = ndx + x;
    dy = ndy + y;

    if (dx < 5) dx = 5;
    if (Width - 5 <= dx) dx = Width - 5;
    if (dy < 5) dy = 5;
    if (Height - 5 <= dy) dy = Height - 5;

    r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15a);
    abs_r = r < 0 ? -r : r;
    if (abs_r & 1) {
        r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15a);
        DirX = DirX + r % 3 - 1;
    }

    r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15b);
    abs_r = r < 0 ? -r : r;
    if (abs_r & 1) {
        r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15b);
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
