#ifndef FRACTAL_ARRAYS_CONTEXT_H
#define FRACTAL_ARRAYS_CONTEXT_H

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
    union {
        PrimaryPt Prime;
        struct { int Prime_x; int Prime_y; };
    };
    union {
        // B610 and later typed owners use pairs; B540/BCD0 prove scalar views.
        PtToPt Point[500];
        int PointValues[1000];
    };
    char* Mask_2x2;
    char* Mask_3x3;
    char* Mask_4x4;
    char* Mask_5x5;
    union { int x; int field_FB8; };
    union { int y; int field_FBC; };
    union { int NumSplitsPerBranch; int field_FC0; };
    union { int NumberOfSatellites; int field_FC4; };
    union { int ChanceOfNextNode; int field_FC8; };
    union { int MaxNumberOfBranches; int field_FCC; };
    int MaxBranchFlag;
    union { int Width; int field_FD4; };
    union { int Height; int field_FD8; };
    union { int MinimumNumTiles; int field_FDC; };
    int NumNodes;
    int NumTilesActuallyChosen;
    int CurrentPoint;
    int ProbabilityTiles;
    int TargetProbabilityCount;
    int ProbabilityAdd;
    union { int BranchRadius; int field_FF8; };
    union { int SatelliteRadius; int field_FFC; };
    union { int PrimaryRadius; int field_1000; };
    int SizeArrays;
    union { int SatelliteDistance; int field_1008; };
    union { int BranchDistance; int field_100C; };
    int DirX;
    int DirY;
    int MaxNumberOfBranchLevels;
    int CurrentNumberOfBranchLevels;
    char* ExternalArray;
    union { char* ProbArray; int field_1024; };
    union { char* PlacementArray; int field_1028; };
    char* WritableExternalArray;
    int DoNotDrawOnFlag;
    int DrawOnOnlyFlag;
    int DrawOnlyInExternalArrayFlag;
    union { int DrawToOneArrayFlag; int field_103C; };
    int BorderDepthPercentage;
    int LeftLimit;
    int RightLimit;
    int TopLimit;
    int BottomLimit;
    char SpecialLandType;
    char pad_end[3];

    void ClearArrays();
    void DeleteArrays();
    void MakeArrays();
    int CreateShape();
    int CreateShape(int, int);

protected:
    void CreateMasks();
    void DeleteMasks();
    void PrepareLimits();
    void ErrorCheckingAndCorrection();
    void CreateMapBasedOnProbabilityArray();
    void MapCleanUpEliminatingSinglesOnly();
    void DrawPrimaryIntoProbabilityArray();
    int MakeFirstLink();
    void Branch(int);
    int MakeNewLink();
    int MakeSatelliteLink();
    void DrawCurrentBranchIntoProbArray(int);
    void DrawCurrentSatelliteIntoProbArray(int);
    void AddingRect(int, int, int, int);
    void AddingCircle(int, int, int);
    void DrawMask(int, int, int);

public:
    void SetPoint(int, int);
    void SetMaxNumberOfBranches(int);
    void SetChanceOfNextNode(int);
    void SetNumberOfSatellites(int);
    void SetSplitsPerBranch(int);
    void SetWidthAndHeight(int, int);
    void SetStartPositionRadius(int);
    void SetBranchsRadius(int);
    void SetSatelliteRadius(int);
    void SetMaxNumberOfBranchLevels(int);
    void SetSatelliteDistance(int);
    void SetBranchDistance(int);
    void SetMinimumNumberOfTiles(int);
    void SetDrawToOneArray();
    void SetBorderDepthPercentage(int);
    char* RetrieveMap();
    char* RetrieveProbMap();
    void SetDefaultValues();
    PointMaker();
    ~PointMaker();
};

#endif
