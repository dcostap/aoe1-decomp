// PointMaker::SetDefaultValues
// VA: 0044AB90
// ACCEPTED_DRIFT: reviewed localized VC5 scheduling drift only. Original clears
// ESI immediately before the BranchDistance store; rebuilt performs the identical
// store and then clears ESI. Size, frame, all other bytes, stores, values, and
// subsequent behavior agree (176/178 bytes are equal). If `this` is invalid or
// protected, both fault on the same store/address, but the exception context has
// ESI=0 in the original and ESI=2 in the rebuild. This register-only fault-context
// difference is accepted as low-risk codegen drift; no call, predicate, cleanup,
// or program-memory effect differs.
//
// Attempt log:
// - Baseline raw-offset source was 178 bytes, 30 positional bytes different (16.8539%).
// - Reconstructed the proven PointMaker layout and reordered SatelliteRadius after
//   Width/Height, as suggested by the fractal.cpp line-38 record; this moved the
//   first mismatch to the zero/BranchDistance schedule and reached 8 differing
//   bytes (4.4944%). This is retained as the best clean source reconstruction.
// - Separate constant locals, register-qualified locals, explicit zero assignment,
//   arithmetic/comma sequencing, and a direct early MaxBranchFlag assignment were
//   tested as diagnostic liveness probes. They either emitted the same 8-byte basin
//   or regressed to 34 bytes; none reproduced the original xor-then-BranchDistance
//   order. No custom flags or shared declarations were kept.
// - Fractal-context lab (36 variants) added the union of exact fractal.cpp donor
//   declarations, class-versus-struct point records, and likely VC5 headers
//   (<memory.h>, <stdlib.h>, and game_types.h) without changing the emitted group:
//   all 36 remained 178 bytes with the same 8-byte hunk. No context surface won.
// - Fault-state audit: the original copies entry `this` to EDX, clears ESI, then
//   performs the BranchDistance store; the candidate faults on that same store
//   before clearing ESI (ESI is 2 instead of 0), while EDX/ECX/EAX are otherwise
//   the same. Valid-object state is identical, but invalid/protected-this fault
//   register context is a real caveat for any behavior-equivalence decision.
// - Paused after the ten-hypothesis budget. Remaining drift is the localized
//   xor esi,esi / BranchDistance store order at 0044ABC7, not a behavior or layout gap.
#include <string.h>

struct PrimaryPt {
    int x;
    int y;
};

struct PtToPt {
    int x;
    int y;
};

class PointMaker {
public:
    PrimaryPt Prime;
    PtToPt Point[500];
    char* Mask_2x2;
    char* Mask_3x3;
    char* Mask_4x4;
    char* Mask_5x5;
    int x;
    int y;
    int NumSplitsPerBranch;
    int NumberOfSatellites;
    int ChanceOfNextNode;
    int MaxNumberOfBranches;
    int MaxBranchFlag;
    int Width;
    int Height;
    int MinimumNumTiles;
    int NumNodes;
    int NumTilesActuallyChosen;
    int CurrentPoint;
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
    char* WritableExternalArray;
    int DoNotDrawOnFlag;
    int DrawOnOnlyFlag;
    int DrawOnlyInExternalArrayFlag;
    int DrawToOneArrayFlag;
    int BorderDepthPercentage;
    int LeftLimit;
    int RightLimit;
    int TopLimit;
    int BottomLimit;
    char SpecialLandType;

    void SetDefaultValues(void);
};

void PointMaker::SetDefaultValues(void)
{
    this->NumberOfSatellites = 2;
    this->NumSplitsPerBranch = 3;
    this->Height = 0x118;
    this->Width = 0x118;
    this->SatelliteRadius = 2;
    this->BranchRadius = 3;
    this->BranchDistance = 3;
    this->ChanceOfNextNode = 0x32;
    this->MaxNumberOfBranches = 6;
    this->PrimaryRadius = 4;
    this->BorderDepthPercentage = 0x0F;
    this->MaxBranchFlag = 0;
    this->SatelliteDistance = 1;
    this->MaxNumberOfBranchLevels = 0x10;
    this->MinimumNumTiles = 0x7D0;
    memset(this->Point, 0, sizeof(this->Point));
    this->DoNotDrawOnFlag = 0;
    this->DrawOnOnlyFlag = 0;
    this->DrawToOneArrayFlag = 0;
    this->DrawOnlyInExternalArrayFlag = 0;
}
