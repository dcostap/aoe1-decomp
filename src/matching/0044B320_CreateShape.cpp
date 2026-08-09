// PointMaker::CreateShape (version 1)
// VA: 0044B320 - canonical fractal.cpp reconstruction

// Attempt log:
// - Replaced the initial absolute-address forwarding wrappers with direct
//   same-TU member declarations and the proven typed PointMaker surface.
// - Inlined the two random-position formulas and moved the y formula before
//   the probability/node resets; this restored the original 334-byte size and
//   the complete 71-instruction setup block.
// - The retry guard must be the natural post-increment form `iVar2++ < 1500`;
//   it recovered the original loop-entry mov/inc/cmp topology and reduced the
//   mismatch to six bytes.
// - Swapping/removing the Prime.x temporary and a short Prime.y local did not
//   alter VC5's final loop load schedule.  Retain ordinary typed assignments;
//   the remaining six bytes are the localized Prime.x/Prime.y load-order
//   choice, with all calls, size, frame, CFG, and other blocks aligned.
// - Reversed the natural source assignment order to `x = Prime.x; y = Prime.y;`;
//   VC5 then lowered the independent loads/stores in the original y-then-x
//   order and reached an exact 334-byte match.

extern int __cdecl debug_rand(char* param_1, int param_2);

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

// Main-agent audit confirmed canonical point-array ownership and retained the
// natural retry loop with post-increment guard.
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
    int NumSplitsPerBranch;             // +0x0FC0
    int NumberOfSatellites;             // +0x0FC4
    int ChanceOfNextNode;               // +0x0FC8
    int MaxNumberOfBranches;            // +0x0FCC
    int MaxBranchFlag;                  // +0x0FD0
    int Width;                           // +0x0FD4
    int Height;                          // +0x0FD8
    int MinimumNumTiles;                // +0x0FDC
    int NumNodes;                       // +0x0FE0
    int NumTilesActuallyChosen;         // +0x0FE4
    int CurrentPoint;                   // +0x0FE8
    int ProbabilityTiles;               // +0x0FEC
    int TargetProbabilityCount;         // +0x0FF0
    int ProbabilityAdd;                 // +0x0FF4
    int BranchRadius;                   // +0x0FF8
    int SatelliteRadius;                // +0x0FFC
    int PrimaryRadius;                  // +0x1000
    int SizeArrays;                     // +0x1004
    int SatelliteDistance;              // +0x1008
    int BranchDistance;                 // +0x100C
    int DirX;                           // +0x1010
    int DirY;                           // +0x1014
    int MaxNumberOfBranchLevels;        // +0x1018
    int CurrentNumberOfBranchLevels;    // +0x101C
    char* ExternalArray;                // +0x1020
    char* ProbArray;                    // +0x1024
    char* PlacementArray;               // +0x1028
    char* WritableExternalArray;        // +0x102C
    int DoNotDrawOnFlag;                // +0x1030
    int DrawOnOnlyFlag;                 // +0x1034
    int DrawOnlyInExternalArrayFlag;    // +0x1038
    int DrawToOneArrayFlag;             // +0x103C
    int BorderDepthPercentage;          // +0x1040
    int LeftLimit;                      // +0x1044
    int RightLimit;                     // +0x1048
    int TopLimit;                       // +0x104C
    int BottomLimit;                    // +0x1050
    char SpecialLandType;               // +0x1054
    char pad_end[3];                    // +0x1055

    void ClearArrays();
    void PrepareLimits();
    void ErrorCheckingAndCorrection();
    void CreateMapBasedOnProbabilityArray();
    void MapCleanUpEliminatingSinglesOnly();
    void DrawPrimaryIntoProbabilityArray();
    int MakeFirstLink();
    void Branch(int param_1);
    int CreateShape();
};

int PointMaker::CreateShape() {
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();

    x = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0xD7) %
        ((Width * (50 - LeftLimit) * 2) / 100) + LeftLimit;
    y = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0xD8) %
        ((Height * (50 - TopLimit) * 2) / 100) + TopLimit;
    ProbabilityTiles = 0;
    NumNodes = 0;
    Prime.x = x;
    Prime.y = y;

    DrawPrimaryIntoProbabilityArray();
    ErrorCheckingAndCorrection();

    int minimum_tiles = MinimumNumTiles;
    int probability_tiles = ProbabilityTiles;
    NumTilesActuallyChosen = 0;
    int attempts = 0;
    while (probability_tiles < minimum_tiles && attempts++ < 1500) {
        x = Prime.x;
        y = Prime.y;
        CurrentNumberOfBranchLevels = MaxNumberOfBranchLevels;
        NumNodes = 0;
        probability_tiles = MakeFirstLink();
        Branch(probability_tiles);
        probability_tiles = ProbabilityTiles;
    }

    CreateMapBasedOnProbabilityArray();
    MapCleanUpEliminatingSinglesOnly();
    return ProbabilityTiles;
}
