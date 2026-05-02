// PointMaker::DrawCurrentBranchIntoProbArray
// VA: 0044BB60 - class-based, rotated loop (384/357)

class PointMaker {
public:
    int Prime_x;                           // +0x00
    int Prime_y;                           // +0x04
    int Point[1000];                       // +0x08
    char gap_FA8[0x10];
    int x;                                 // +0xFB8
    int y;                                 // +0xFBC
    int NumSplitsPerBranch;                // +0xFC0
    int NumberOfSatellites;                // +0xFC4
    int ChanceOfNextNode;                  // +0xFC8
    int MaxNumberOfBranches;               // +0xFCC
    int MaxBranchFlag;                     // +0xFD0
    int Width;                             // +0xFD4
    int Height;                            // +0xFD8
    int MinimumNumTiles;                   // +0xFDC
    int NumNodes;                          // +0xFE0
    char gap_FE4[0x08];
    int ProbabilityTiles;                  // +0xFEC
    int TargetProbabilityCount;            // +0xFF0
    int ProbabilityAdd;                    // +0xFF4
    int BranchRadius;                      // +0xFF8
    int SatelliteRadius;                   // +0xFFC
    int PrimaryRadius;                     // +0x1000
    int SizeArrays;                        // +0x1004
    int SatelliteDistance;                 // +0x1008
    int BranchDistance;                    // +0x100C
    int DirX;                              // +0x1010
    int DirY;                              // +0x1014
    int MaxNumberOfBranchLevels;           // +0x1018
    int CurrentNumberOfBranchLevels;       // +0x101C
    char* ExternalArray;                   // +0x1020
    char* ProbArray;                       // +0x1024
    char* PlacementArray;                  // +0x1028
    char* WritableExternalArray;           // +0x102C
    int DoNotDrawOnFlag;                   // +0x1030
    int DrawOnOnlyFlag;                    // +0x1034
    int DrawOnlyInExternalArrayFlag;       // +0x1038
    int DrawToOneArrayFlag;                // +0x103C
    int BorderDepthPercentage;             // +0x1040
    int LeftLimit;                         // +0x1044
    int RightLimit;                        // +0x1048
    int TopLimit;                          // +0x104C
    int BottomLimit;                       // +0x1050
    char SpecialLandType;                  // +0x1054

    void AddingRect(int param1, int param2, int param3, int param4);
    void DrawCurrentBranchIntoProbArray(int param_1);
};

void PointMaker::DrawCurrentBranchIntoProbArray(int param_1) {
    int iVar8 = Point[param_1 * 2];
    int iVar2 = BranchRadius;
    int iVar3 = Point[param_1 * 2 + 1];
    int right = iVar2 + iVar8;
    iVar8 = iVar8 - iVar2;
    int iVar6 = iVar3 - iVar2;
    int bottom = iVar3 + iVar2;
    
    if ((((-1 < right) && (-1 < bottom)) && (iVar8 < Width)) && (iVar6 < Height)) {
        if (iVar8 < 0) iVar8 = 0;
        if (iVar6 < 0) iVar6 = 0;
        if (Width <= right) right = Width - 1;
        if (Height <= bottom) bottom = Height - 1;
        
        ProbabilityAdd = 1;
        int counter = 0;
        if (0 < iVar2) {
            goto entry;
            do {
                bottom = *(int*)((int)&bottom + 0); // dummy reload via self-ref
entry:
                AddingRect(iVar8, iVar6, right, bottom);
                if (Width <= ++iVar8 || (++iVar6, Height <= iVar6) || (--right, right < 0) || (--bottom, bottom < 0)) break;
                ProbabilityAdd++;
                counter++;
            } while (counter < iVar2);
        }
        
        int prob_idx = Width * Point[param_1 * 2 + 1] + Point[param_1 * 2];
        if ((0 < prob_idx) && (prob_idx < SizeArrays - 1)) {
            char* pcVar3 = ProbArray + prob_idx;
            char cVar1 = *pcVar3;
            char cVar5 = (char)ProbabilityAdd;
            if (cVar1 == 0) {
                *pcVar3 = cVar5;
                ProbabilityTiles++;
                return;
            }
            if (ProbabilityAdd + (int)cVar1 < 0xFF) {
                *pcVar3 = cVar5 + cVar1;
                return;
            }
            *pcVar3 = (char)-1;
        }
    }
}
