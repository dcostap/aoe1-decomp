// PointMaker::SetDefaultValues
// VA: 0044AB90
// Retry 2026-05-26 Boss pass: 18 probes on VA 0044AB90 only. Revalidated baseline:
// exact 178B, 16.8539% positional / 10.6742% edit, first mismatch byte 0. The
// remaining drift is the initial constant/register schedule: original saves ESI at
// entry, uses ESI=2, EAX=3, ECX=0x118, then later zeroes ESI before the 0x100C
// store; rebuilt uses EAX=2, delays push ESI until just before push EDI, then
// reloads EAX=3 and schedules the 0x100C store before xor ESI. Tried register/
// volatile/two-local variants for the `2` value, explicit two/three/width locals
// and declaration order changes, class-method surface, register self pointer,
// dummy value uses, manual zero loop instead of memset, and flags /G5 /Oa /Og
// /Ob0 /Oy- /O1. No variant produced the original ESI=2 entry basin; many either
// stayed identical to baseline, shrank to 176B, or regressed broadly. GIVEUP:
// not accepted_drift quality for promotion here; although behavior is identical,
// diff starts at byte 0 and includes prologue/register scheduling, not a single
// localized trailing hunk.
#include <string.h>

void __fastcall SetDefaultValues(void* _this, int _)
{
    int val = 2;
    ((int*)((char*)_this + 0xFC4))[0] = val;   // NumberOfSatellites
    ((int*)((char*)_this + 0xFFC))[0] = val;   // SatelliteRadius
    val = 3;
    ((int*)((char*)_this + 0xFC0))[0] = val;   // NumSplitsPerBranch
    ((int*)((char*)_this + 0xFD8))[0] = 0x118; // Height
    ((int*)((char*)_this + 0xFD4))[0] = 0x118; // Width
    ((int*)((char*)_this + 0xFF8))[0] = val;   // BranchRadius
    ((int*)((char*)_this + 0x100C))[0] = val;  // BranchDistance
    ((int*)((char*)_this + 0xFC8))[0] = 0x32;  // ChanceOfNextNode
    ((int*)((char*)_this + 0xFCC))[0] = 6;     // MaxNumberOfBranches
    ((int*)((char*)_this + 0x1000))[0] = 4;    // PrimaryRadius
    ((int*)((char*)_this + 0x1040))[0] = 0x0F; // BorderDepthPercentage
    val = 0;
    ((int*)((char*)_this + 0xFD0))[0] = val;   // MaxBranchFlag
    ((int*)((char*)_this + 0x1008))[0] = 1;    // SatelliteDistance
    ((int*)((char*)_this + 0x1018))[0] = 0x10; // MaxNumberOfBranchLevels
    ((int*)((char*)_this + 0xFDC))[0] = 0x7D0; // MinimumNumTiles
    memset((char*)_this + 8, 0, 0xFA0);        // zero Point array
    ((int*)((char*)_this + 0x1030))[0] = val;  // DoNotDrawOnFlag
    ((int*)((char*)_this + 0x1034))[0] = val;  // DrawOnOnlyFlag
    ((int*)((char*)_this + 0x103C))[0] = val;  // DrawToOneArrayFlag
    ((int*)((char*)_this + 0x1038))[0] = val;  // DrawOnlyInExternalArrayFlag
}
