// PointMaker::CreateShape (0044B470)
//
// The PointMaker layout below follows the proven fractal.cpp class layout.  The
// called methods are declarations only: they are separately owned functions in
// the original translation unit, so defining local forwarding wrappers would
// create the wrong call relocations and extra COMDATs.
//
// Attempt log:
// - Removed local forwarding wrappers and kept separately-owned method declarations;
//   this fixed call relocation identity and reduced the initial 113-byte mismatch.
// - A post-incremented attempt guard (`iVar2++ < 1500`) reproduced the rotated
//   VC5 loop topology, bringing the function to 196 bytes and a 15-byte mismatch.
// - Canonical PrimaryPt/PtToPt and the full proven PointMaker surface, local-value
//   and register-qualified parameter probes, and a focused setup variant lab did
//   not change the emitted best code.
// - Final validated state remains scratch: all calls, loop blocks, frame, size,
//   and 189/196 bytes match. Remaining drift is localized to +0x1A..+0x2B:
//   rebuilt loads param_2 into EAX and sets ECX=this before the first stores,
//   while the original loads param_2 into ECX and param_1 into EAX first.

class PrimaryPt {
public:
    int x;
    int y;
};

class PtToPt {
public:
    int x;
    int y;
};

class PointMaker {
public:
    PrimaryPt Prime;                     // +0x0000
    PtToPt Point[500];                   // +0x0008
    char* Mask_2x2;                      // +0x0FA8
    char* Mask_3x3;                      // +0x0FAC
    char* Mask_4x4;                      // +0x0FB0
    char* Mask_5x5;                      // +0x0FB4
    int x;                               // +0x0FB8
    int y;                               // +0x0FBC
    int NumSplitsPerBranch;              // +0x0FC0
    int NumberOfSatellites;              // +0x0FC4
    int ChanceOfNextNode;                // +0x0FC8
    int MaxNumberOfBranches;             // +0x0FCC
    int MaxBranchFlag;                   // +0x0FD0
    int Width;                            // +0x0FD4
    int Height;                           // +0x0FD8
    int MinimumNumTiles;                 // +0x0FDC
    int NumNodes;                        // +0x0FE0
    int NumTilesActuallyChosen;          // +0x0FE4
    int CurrentPoint;                    // +0x0FE8
    int ProbabilityTiles;                // +0x0FEC
    int TargetProbabilityCount;          // +0x0FF0
    int ProbabilityAdd;                  // +0x0FF4
    int BranchRadius;                    // +0x0FF8
    int SatelliteRadius;                 // +0x0FFC
    int PrimaryRadius;                   // +0x1000
    int SizeArrays;                      // +0x1004
    int SatelliteDistance;               // +0x1008
    int BranchDistance;                  // +0x100C
    int DirX;                            // +0x1010
    int DirY;                            // +0x1014
    int MaxNumberOfBranchLevels;         // +0x1018
    int CurrentNumberOfBranchLevels;     // +0x101C
    char* ExternalArray;                 // +0x1020
    char* ProbArray;                     // +0x1024
    char* PlacementArray;                // +0x1028
    char* WritableExternalArray;         // +0x102C
    int DoNotDrawOnFlag;                 // +0x1030
    int DrawOnOnlyFlag;                  // +0x1034
    int DrawOnlyInExternalArrayFlag;     // +0x1038
    int DrawToOneArrayFlag;              // +0x103C
    int BorderDepthPercentage;           // +0x1040
    int LeftLimit;                       // +0x1044
    int RightLimit;                      // +0x1048
    int TopLimit;                        // +0x104C
    int BottomLimit;                     // +0x1050
    char SpecialLandType;                // +0x1054
    char pad_end[3];                     // +0x1055

    void ClearArrays();
    void PrepareLimits();
    void ErrorCheckingAndCorrection();
    void CreateMapBasedOnProbabilityArray();
    void MapCleanUpEliminatingSinglesOnly();
    void DrawPrimaryIntoProbabilityArray();
    int MakeFirstLink();
    void Branch(int param_1);
    int CreateShape(int param_1, int param_2);
};

int PointMaker::CreateShape(int param_1, int param_2) {
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();
    y = param_2;
    Prime.y = param_2;
    ProbabilityTiles = 0;
    NumNodes = 0;
    x = param_1;
    Prime.x = param_1;
    DrawPrimaryIntoProbabilityArray();
    ErrorCheckingAndCorrection();

    int minimum = MinimumNumTiles;
    int probability = ProbabilityTiles;
    NumTilesActuallyChosen = 0;
    int attempts = 0;
    while (probability < minimum && attempts++ < 1500) {
        probability = Prime.y;
        x = Prime.x;
        y = probability;
        CurrentNumberOfBranchLevels = MaxNumberOfBranchLevels;
        NumNodes = 0;
        probability = MakeFirstLink();
        Branch(probability);
        probability = ProbabilityTiles;
    }
    CreateMapBasedOnProbabilityArray();
    MapCleanUpEliminatingSinglesOnly();
    return ProbabilityTiles;
}
