// PointMaker::SetDefaultValues — real pass
// VA: 0044AB90
void __fastcall SetDefaultValues_PointMaker(void* _this, int _)
{
    *(int*)((char*)_this + 0xFC4) = 2;     // NumberOfSatellites
    *(int*)((char*)_this + 0xFC0) = 3;     // NumSplitsPerBranch
    *(int*)((char*)_this + 0xFD8) = 0x118; // Height
    *(int*)((char*)_this + 0xFD4) = 0x118; // Width
    *(int*)((char*)_this + 0xFFC) = 2;     // SatelliteRadius
    *(int*)((char*)_this + 0xFF8) = 3;     // BranchRadius
    *(int*)((char*)_this + 0x100C) = 3;    // BranchDistance
    *(int*)((char*)_this + 0xFC8) = 0x32;  // ChanceOfNextNode
    *(int*)((char*)_this + 0xFCC) = 6;     // MaxNumberOfBranches
    *(int*)((char*)_this + 0x1000) = 4;    // PrimaryRadius
    *(int*)((char*)_this + 0x1040) = 0x0F; // BorderDepthPercentage
    *(int*)((char*)_this + 0xFD0) = 0;     // MaxBranchFlag
    *(int*)((char*)_this + 0x1008) = 1;    // SatelliteDistance
    *(int*)((char*)_this + 0x1018) = 0x10; // MaxNumberOfBranchLevels
    *(int*)((char*)_this + 0xFDC) = 0x7D0; // MinimumNumTiles
    // Clear Point[1000] (0x3E8 PtToPt entries = 0xFA0 bytes)
    for (int i = 0; i < 1000; i++) {
        *(int*)((char*)_this + 8 + i * 8) = 0;
        *(int*)((char*)_this + 8 + i * 8 + 4) = 0;
    }
    *(int*)((char*)_this + 0x1030) = 0; // DoNotDrawOnFlag
    *(int*)((char*)_this + 0x1034) = 0; // DrawOnOnlyFlag
    *(int*)((char*)_this + 0x103C) = 0; // DrawToOneArrayFlag
    *(int*)((char*)_this + 0x1038) = 0; // DrawOnlyInExternalArrayFlag
}
