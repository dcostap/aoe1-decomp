// PointMaker::ErrorCheckingAndCorrection
// VA: 0044C370

#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    char gap_00[0xFC0];
    int NumSplitsPerBranch;                // +0xFC0
    int NumberOfSatellites;                // +0xFC4
    int ChanceOfNextNode;                  // +0xFC8
    char gap_FCC[0x4];
    int MaxBranchFlag;                     // +0xFD0
    int Width;                             // +0xFD4
    int Height;                            // +0xFD8
    int MinimumNumTiles;                   // +0xFDC
    char gap_FE0[0x18];
    int BranchRadius;                      // +0xFF8
    int SatelliteRadius;                   // +0xFFC
    int PrimaryRadius;                     // +0x1000
    int SizeArrays;                        // +0x1004
    char gap_1008[0x10];
    int MaxNumberOfBranchLevels;           // +0x1018
    char gap_101C[0x20];
    int DrawToOneArrayFlag;                // +0x103C

    void ErrorCheckingAndCorrection();
};
#endif

void PointMaker::ErrorCheckingAndCorrection() {
    int w = Width;
    int size = Height * w;
    SizeArrays = size;

    if (BranchRadius > w) {
        BranchRadius = (w * 2) / 3;
    }
    if (SatelliteRadius > w) {
        SatelliteRadius = (w * 2) / 3;
    }
    if (PrimaryRadius > w) {
        PrimaryRadius = (w * 2) / 3;
    }

    if (NumSplitsPerBranch > 4) {
        NumSplitsPerBranch = 4;
    }
    if (NumberOfSatellites > 4) {
        NumberOfSatellites = 4;
    }

    size = size / MinimumNumTiles;
    DrawToOneArrayFlag = 0;

    int chance = (10 - size) * 10;
    ChanceOfNextNode = chance;
    if (chance < 0x23) {
        ChanceOfNextNode = 0x23;
    }
    if (ChanceOfNextNode > 0x50) {
        ChanceOfNextNode = 0x50;
    }

    if (MaxBranchFlag == 0) {
        MaxNumberOfBranchLevels = size - ChanceOfNextNode / 5;
    }
    if (MaxNumberOfBranchLevels < 10) {
        MaxNumberOfBranchLevels = 10;
    }
    if (MaxNumberOfBranchLevels > 0x1E) {
        MaxNumberOfBranchLevels = 0x1E;
    }

    MaxBranchFlag = 0;
}
