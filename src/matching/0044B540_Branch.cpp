// PointMaker::Branch
// VA: 0044B540 - from Ghidra decomp

extern int __cdecl debug_rand(char* param_1, int param_2);

#ifndef FRACTAL_ARRAYS_CONTEXT_H
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

    int MakeNewLink();
    int MakeSatelliteLink();
    void DrawCurrentBranchIntoProbArray(int param_1);
    void DrawCurrentSatelliteIntoProbArray(int param_1);
    void Branch(int param_1);
};
#endif

#ifdef FRACTAL_ARRAYS_CONTEXT_H
#define FRACTAL_POINT_VALUES PointValues
#else
#define FRACTAL_POINT_VALUES Point
#endif

void PointMaker::Branch(int param_1) {
    if (((1 < CurrentNumberOfBranchLevels) &&
        (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x116) % 100 < ChanceOfNextNode * 10)) &&
       (ProbabilityTiles < MinimumNumTiles * 2)) {
        CurrentNumberOfBranchLevels--;
        for (int i = 0; i < NumSplitsPerBranch; i++) {
            x = FRACTAL_POINT_VALUES[param_1 * 2];
            y = FRACTAL_POINT_VALUES[param_1 * 2 + 1];
            int iVar2 = MakeNewLink();
            DrawCurrentBranchIntoProbArray(iVar2);
            Branch(iVar2);
        }
    }
    for (int i = 0; i < NumberOfSatellites; i++) {
        int iVar2 = MakeSatelliteLink();
        DrawCurrentSatelliteIntoProbArray(iVar2);
    }
}

#undef FRACTAL_POINT_VALUES
