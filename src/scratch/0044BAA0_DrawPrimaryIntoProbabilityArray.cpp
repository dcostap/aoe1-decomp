// PointMaker::DrawPrimaryIntoProbabilityArray
// VA: 0044BAA0

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
    char gap_FE4[0x0C];
    int ProbabilityTiles;                  // +0xFEC
    int TargetProbabilityCount;            // +0xFF0
    int ProbabilityAdd;                    // +0xFF4
    char gap_FF8[0x08];
    int PrimaryRadius;                     // +0x1000
    char gap_1004[0x1C];
    char* ProbArray;                       // +0x1024
    char* PlacementArray;                  // +0x1028

    void AddingRect(int param_1, int param_2, int param_3, int param_4);
    void DrawPrimaryIntoProbabilityArray();
};

void PointMaker::DrawPrimaryIntoProbabilityArray() {
    int iVar5 = Point[0];           // Prime.x
    int iVar2 = Point[1];           // Prime.y
    int iVar1 = PrimaryRadius;
    int iVar6 = iVar5 - iVar1;      // x1
    int iVar4 = iVar2 - iVar1;      // y1
    iVar2 = iVar2 + iVar1;          // y2
    iVar5 = iVar1 + iVar5;          // x2
    if (iVar6 < 0) iVar6 = 0;
    if (iVar4 < 0) iVar4 = 0;
    int iVar3 = Width - 1;
    if (iVar3 < iVar5) iVar5 = iVar3;
    iVar3 = Height - 1;
    if (iVar3 < iVar2) iVar2 = iVar3;
    ProbabilityAdd = 1;
    for (int local_c = 0; local_c < iVar1; local_c++) {
        AddingRect(iVar6, iVar4, iVar5, iVar2);
        ProbabilityAdd++;
        iVar2--;
        iVar4++;
        iVar5--;
        iVar6++;
    }
}
