// PointMaker::MakeFirstLink
// VA: 0044B610

extern int __cdecl debug_rand(char* param_1, int param_2);

class PointMaker {
public:
    char gap_00[0x8];
    int Point[1000];                       // +0x08
    char gap_FA8[0x10];
    int x;                                 // +0xFB8
    int y;                                 // +0xFBC
    char gap_FC0[0x14];
    int Width;                             // +0xFD4
    int Height;                            // +0xFD8
    char gap_FDC[0x04];
    int NumNodes;                          // +0xFE0
    char gap_FE4[0x24];
    int BranchDistance;                    // +0x1008
    char gap_100C[0x04];
    int DirX;                              // +0x1010
    int DirY;                              // +0x1014
    char gap_1018[0x2C];
    int LeftLimit;                         // +0x1044
    int RightLimit;                        // +0x1048
    int TopLimit;                          // +0x104C
    int BottomLimit;                       // +0x1050

    int MakeFirstLink();
};

int PointMaker::MakeFirstLink() {
    int dx = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x134);
    dx = dx % BranchDistance + 2;
    int r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x134);
    if ((r & 0x80000001) == 1 || (r & 0x80000001) == 0x80000001) dx = -dx;

    int dy = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x135);
    dy = dy % BranchDistance + 2;
    r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x135);
    if ((r & 0x80000001) == 1 || (r & 0x80000001) == 0x80000001) dy = -dy;

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
