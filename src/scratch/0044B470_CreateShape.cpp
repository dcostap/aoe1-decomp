// PointMaker::CreateShape (version at 0044B470)
// VA: 0044B470 - Full class with method declarations

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
    int CreateShape(int param_1, int param_2);
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

int PointMaker::CreateShape(int param_1, int param_2) {
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();
    y = param_2;
    Prime_y = param_2;
    ProbabilityTiles = 0;
    NumNodes = 0;
    x = param_1;
    Prime_x = param_1;
    DrawPrimaryIntoProbabilityArray();
    ErrorCheckingAndCorrection();
    int iVar1 = MinimumNumTiles;
    int iVar3 = ProbabilityTiles;
    NumTilesActuallyChosen = 0;
    int iVar2 = 0;
    while (iVar3 < iVar1 && iVar2 < 1500) {
        iVar3 = Prime_y;
        x = Prime_x;
        y = iVar3;
        CurrentNumberOfBranchLevels = MaxNumberOfBranchLevels;
        NumNodes = 0;
        iVar3 = MakeFirstLink();
        Branch(iVar3);
        iVar3 = ProbabilityTiles;
        iVar2++;
    }
    CreateMapBasedOnProbabilityArray();
    MapCleanUpEliminatingSinglesOnly();
    return ProbabilityTiles;
}
