// PointMaker::CreateShape — real pass
// VA: 0044B470
int __fastcall CreateShape_PointMaker(void* _this, int _, int param1, int param2)
{
    *(int*)((char*)_this + 0xFE0) = 0;  // NumNodes = 0
    ((void(__fastcall*)(void*,int))0x44B210)(_this, 0);  // ClearArrays
    ((void(__fastcall*)(void*,int))0x44C4B0)(_this, 0);  // PrepareLimits
    *(int*)((char*)_this + 0xFBC) = param2;  // y = param2
    *(int*)((char*)_this + 4) = param2;      // Prime.y = param2
    *(int*)((char*)_this + 0xFEC) = 0;       // ProbabilityTiles = 0
    *(int*)((char*)_this + 0xFE0) = 0;       // NumNodes = 0
    *(int*)((char*)_this + 0xFB8) = param1;  // x = param1
    *(int*)((char*)_this) = param1;          // Prime.x = param1
    ((void(__fastcall*)(void*,int))0x44BAA0)(_this, 0);  // DrawPrimaryIntoProbabilityArray
    ((void(__fastcall*)(void*,int))0x44C370)(_this, 0);  // ErrorCheckingAndCorrection
    int minTiles = *(int*)((char*)_this + 0xFDC);
    int probTiles = *(int*)((char*)_this + 0xFEC);
    *(int*)((char*)_this + 0xFE4) = 0;  // NumTilesActuallyChosen = 0
    for (int i = 0; probTiles < minTiles && i < 1500; i++) {
        *(int*)((char*)_this + 0xFB8) = *(int*)((char*)_this);      // x = Prime.x
        *(int*)((char*)_this + 0xFBC) = *(int*)((char*)_this + 4);  // y = Prime.y
        *(int*)((char*)_this + 0x101C) = *(int*)((char*)_this + 0x1018);  // CurrentNumBranchLevels = Max
        *(int*)((char*)_this + 0xFE0) = 0;  // NumNodes = 0
        int link = ((int(__fastcall*)(void*,int))0x44B610)(_this, 0);  // MakeFirstLink
        ((void(__fastcall*)(void*,int,int))0x44B540)(_this, 0, link);  // Branch
        probTiles = *(int*)((char*)_this + 0xFEC);
    }
    ((void(__fastcall*)(void*,int))0x44C1B0)(_this, 0);  // CreateMapBasedOnProbabilityArray
    ((void(__fastcall*)(void*,int))0x44C510)(_this, 0);  // MapCleanUpEliminatingSinglesOnly
    return *(int*)((char*)_this + 0xFEC);
}
