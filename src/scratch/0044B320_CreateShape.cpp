// PointMaker::CreateShape (version 1)
// VA: 0044B320 - Uses random positioning

int __cdecl debug_rand(char* param_1, int param_2);

class PointMaker {
public:
    int Prime_x;
    int Prime_y;
    int Point[1000];
    char gap_FA8[0x10];
    int x;
    int y;
    char gap_FC0[0x14];
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
    char _pad_end[3];

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

void PointMaker::ClearArrays() {
    ((void(__fastcall*)(void*,int))0x44B210)(this, 0);
}

void PointMaker::PrepareLimits() {
    ((void(__fastcall*)(void*,int))0x44C4B0)(this, 0);
}

void PointMaker::ErrorCheckingAndCorrection() {
    ((void(__fastcall*)(void*,int))0x44C370)(this, 0);
}

void PointMaker::CreateMapBasedOnProbabilityArray() {
    ((void(__fastcall*)(void*,int))0x44C1B0)(this, 0);
}

void PointMaker::MapCleanUpEliminatingSinglesOnly() {
    ((void(__fastcall*)(void*,int))0x44C510)(this, 0);
}

void PointMaker::DrawPrimaryIntoProbabilityArray() {
    ((void(__fastcall*)(void*,int))0x44BAA0)(this, 0);
}

int PointMaker::MakeFirstLink() {
    return ((int(__fastcall*)(void*,int))0x44B610)(this, 0);
}

void PointMaker::Branch(int param_1) {
    ((void(__fastcall*)(void*,int,int))0x44B540)(this, 0, param_1);
}

int PointMaker::CreateShape() {
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();
    int left = LeftLimit;
    int iVar2 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0xD7);
    int top = TopLimit;
    x = iVar2 % ((Width * (50 - left) * 2) / 100) + left;
    iVar2 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0xD8);
    ProbabilityTiles = 0;
    NumNodes = 0;
    Prime_x = x;
    top = iVar2 % ((Height * (50 - top) * 2) / 100) + top;
    y = top;
    Prime_y = top;
    DrawPrimaryIntoProbabilityArray();
    ErrorCheckingAndCorrection();
    int iVar1 = MinimumNumTiles;
    int iVar3 = ProbabilityTiles;
    NumTilesActuallyChosen = 0;
    int iVar2b = 0;
    while (iVar3 < iVar1 && iVar2b < 1500) {
        iVar3 = Prime_x;
        y = Prime_y;
        x = iVar3;
        CurrentNumberOfBranchLevels = MaxNumberOfBranchLevels;
        NumNodes = 0;
        iVar3 = MakeFirstLink();
        Branch(iVar3);
        iVar3 = ProbabilityTiles;
        iVar2b++;
    }
    CreateMapBasedOnProbabilityArray();
    MapCleanUpEliminatingSinglesOnly();
    return ProbabilityTiles;
}
