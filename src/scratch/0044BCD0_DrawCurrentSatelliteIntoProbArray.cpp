// PointMaker::DrawCurrentSatelliteIntoProbArray
// VA: 0044BCD0 - v3: goto-based branch structure matching original asm

int __cdecl debug_rand(char* param_1, int param_2);

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
    char* ExternalArray;
    char* ProbArray;
    char* PlacementArray;

    void AddingCircle(int param_1, int param_2, int param_3);
    void DrawCurrentSatelliteIntoProbArray(int param_1);
};

void PointMaker::DrawCurrentSatelliteIntoProbArray(int param_1) {
    int iVar4 = SatelliteRadius;
    ProbabilityAdd = 2;
    while (iVar4 >= 0) {
        AddingCircle(Point[param_1 * 2], Point[param_1 * 2 + 1], iVar4);
        ProbabilityAdd++;
        iVar4--;
    }
    
    iVar4 = Point[param_1 * 2 + 1] * Width + Point[param_1 * 2];
    int probAdd = ProbabilityAdd;
    if (iVar4 >= 1 && iVar4 < SizeArrays - 1) {
        char* p = ProbArray + iVar4;
        if (*p == 0) {
            *p = (char)probAdd;
            ProbabilityTiles++;
        } else {
            int total = probAdd + (int)*p;
            if (total < 0xFF) {
                *p = (char)total;
            } else {
                *p = (char)-1;
            }
        }
    }
}
