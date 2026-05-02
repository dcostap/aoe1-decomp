// PointMaker::MakeFirstLink
// VA: 0044B610 - from Ghidra decomp

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
    char gap_1020[0x24];
    int LeftLimit;
    int RightLimit;
    int TopLimit;
    int BottomLimit;

    int MakeFirstLink();
};

int PointMaker::MakeFirstLink() {
    int dx = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x134);
    dx = dx % BranchDistance + 2;
    int r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x134);
    int abs_r = r < 0 ? -r : r;
    if (abs_r & 1) dx = -dx;

    int dy = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x135);
    dy = dy % BranchDistance + 2;
    r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x135);
    abs_r = r < 0 ? -r : r;
    if (abs_r & 1) dy = -dy;

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
