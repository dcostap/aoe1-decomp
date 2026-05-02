// PointMaker::SetDefaultValues
// VA: 0044AB90
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
