// PointMaker::DrawCurrentBranchIntoProbArray
// VA: 0044BB60 - natural typed reconstruction

// Attempt log:
// - Replaced the rotated-loop dummy self-reload/raw cursor scaffold with a
//   natural typed PointMaker/Point-array reconstruction and a direct
//   AddingRect member call.
// - A guarded `for` loop with direct BranchRadius bounds (rather than keeping
//   radius live as a local loop bound) recovered the original 357-byte size,
//   0x8 frame, one call, and 0x8 stack-local topology.  The natural do/while
//   form peeled an extra AddingRect call and was discarded.
// - Remaining drift is broad register/source scheduling from the initial
//   point/radius locals and saturation tail; parameter capture and raw/typed
//   array/register probes did not move it.  Retained readable typed source,
//   not fake volatility, raw offsets, or register-only scaffolding.

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

// Main-agent audit confirmed canonical probability/branch ownership and retained
// the natural typed draw loop.
class PointMaker {
public:
    PrimaryPt Prime;                     // +0x00
    PtToPt Point[500];                   // +0x08
    char* Mask_2x2;                      // +0xFA8
    char* Mask_3x3;                      // +0xFAC
    char* Mask_4x4;                      // +0xFB0
    char* Mask_5x5;                      // +0xFB4
    int x;                               // +0xFB8
    int y;                               // +0xFBC
    int NumSplitsPerBranch;              // +0xFC0
    int NumberOfSatellites;              // +0xFC4
    int ChanceOfNextNode;                // +0xFC8
    int MaxNumberOfBranches;             // +0xFCC
    int MaxBranchFlag;                   // +0xFD0
    int Width;                           // +0xFD4
    int Height;                          // +0xFD8
    int MinimumNumTiles;                 // +0xFDC
    int NumNodes;                        // +0xFE0
    int NumTilesActuallyChosen;          // +0xFE4
    int CurrentPoint;                    // +0xFE8
    int ProbabilityTiles;                // +0xFEC
    int TargetProbabilityCount;          // +0xFF0
    int ProbabilityAdd;                  // +0xFF4
    int BranchRadius;                    // +0xFF8
    int SatelliteRadius;                 // +0xFFC
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

    void AddingRect(int param1, int param2, int param3, int param4);
    void DrawCurrentBranchIntoProbArray(int param_1);
};

void PointMaker::DrawCurrentBranchIntoProbArray(int param_1) {
    int iVar2;
    int iVar3;
    int iVar6;
    int iVar7;
    int iVar8;
    int i;
    int local_4;

    iVar8 = Point[param_1].x;
    iVar2 = BranchRadius;
    iVar3 = Point[param_1].y;
    iVar7 = iVar2 + iVar8;
    iVar8 = iVar8 - iVar2;
    iVar6 = iVar3 - iVar2;
    i = iVar3 + iVar2;

    if (iVar7 >= 0 && i >= 0 && iVar8 < Width && iVar6 < Height) {
        if (iVar8 < 0) iVar8 = 0;
        if (iVar6 < 0) iVar6 = 0;
        if (iVar7 >= Width) iVar7 = Width - 1;
        if (i >= Height) i = Height - 1;

        ProbabilityAdd = 1;
        local_4 = 0;
        if (BranchRadius > 0) {
            for (; local_4 < BranchRadius; ++local_4) {
                AddingRect(iVar8, iVar6, iVar7, i);
                ++iVar8;
                if (iVar8 >= Width || ++iVar6 >= Height || --iVar7 < 0 || --i < 0) {
                    break;
                }
                ++ProbabilityAdd;
            }
        }

        int prob_idx = Width * Point[param_1].y + Point[param_1].x;
        if (prob_idx > 0 && prob_idx < SizeArrays - 1) {
            char* p = ProbArray + prob_idx;
            char old = *p;
            char add = (char)ProbabilityAdd;
            if (old == 0) {
                *p = add;
                ProbabilityTiles++;
                return;
            }
            if (ProbabilityAdd + (int)old < 0xFF) {
                *p = add + old;
                return;
            }
            *p = (char)-1;
        }
    }
}
