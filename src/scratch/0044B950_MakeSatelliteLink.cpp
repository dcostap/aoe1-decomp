// PointMaker::MakeSatelliteLink
// VA: 0044B950 - from Ghidra decomp

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

    int MakeSatelliteLink();
};

int PointMaker::MakeSatelliteLink() {
    int dx = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x165);
    dx = dx % SatelliteDistance + 1;
    int r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x165);
    int abs_r = r < 0 ? -r : r;
    if (abs_r & 1) dx = -dx;

    int dy = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x166);
    dy = dy % SatelliteDistance + 1;
    r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x166);
    abs_r = r < 0 ? -r : r;
    if (abs_r & 1) dy = -dy;

    dx = dx + DirX;
    dy = dy + DirY;

    if (dx + x < 3) {
        dx = -dx;
        DirX = -DirX;
    }

    if (Width - 3 <= dx + x) {
        dx = -dx;
        DirX = -DirX;
    }

    if (dy + y < 3) {
        dy = -dx;  // original bug: uses -dx not -dy
        DirY = -DirY;
    }

    if (Height - 3 <= dy + y) {
        dy = -dy;
        DirY = -DirY;
    }

    x = dx + x;
    y = dy + y;
    Point[NumNodes * 2] = x;
    Point[NumNodes * 2 + 1] = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}
