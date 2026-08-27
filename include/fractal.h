#ifndef AOE1_FRACTAL_H
#define AOE1_FRACTAL_H

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
    PrimaryPt Prime;                 // +0x0000
    PtToPt Point[500];               // +0x0008
    char* Mask_2x2;                  // +0x0FA8
    char* Mask_3x3;                  // +0x0FAC
    char* Mask_4x4;                  // +0x0FB0
    char* Mask_5x5;                  // +0x0FB4
    int x;                           // +0x0FB8
    int y;                           // +0x0FBC
    int NumSplitsPerBranch;          // +0x0FC0
    int NumberOfSatellites;          // +0x0FC4
    int ChanceOfNextNode;            // +0x0FC8
    int MaxNumberOfBranches;         // +0x0FCC
    int MaxBranchFlag;               // +0x0FD0
    int Width;                       // +0x0FD4
    int Height;                      // +0x0FD8
    int MinimumNumTiles;             // +0x0FDC
    int NumNodes;                    // +0x0FE0
    int NumTilesActuallyChosen;      // +0x0FE4
    int CurrentPoint;                // +0x0FE8
    int ProbabilityTiles;            // +0x0FEC
    int TargetProbabilityCount;      // +0x0FF0
    int ProbabilityAdd;              // +0x0FF4
    int BranchRadius;                // +0x0FF8
    int SatelliteRadius;             // +0x0FFC
    int PrimaryRadius;               // +0x1000
    int SizeArrays;                  // +0x1004
    int SatelliteDistance;           // +0x1008
    int BranchDistance;              // +0x100C
    int DirX;                        // +0x1010
    int DirY;                        // +0x1014
    int MaxNumberOfBranchLevels;     // +0x1018
    int CurrentNumberOfBranchLevels; // +0x101C
    char* ExternalArray;             // +0x1020
    char* ProbArray;                 // +0x1024
    char* PlacementArray;            // +0x1028
    char* WritableExternalArray;     // +0x102C
    int DoNotDrawOnFlag;             // +0x1030
    int DrawOnOnlyFlag;              // +0x1034
    int DrawOnlyInExternalArrayFlag; // +0x1038
    int DrawToOneArrayFlag;          // +0x103C
    int BorderDepthPercentage;       // +0x1040
    int LeftLimit;                   // +0x1044
    int RightLimit;                  // +0x1048
    int TopLimit;                    // +0x104C
    int BottomLimit;                 // +0x1050
    char SpecialLandType;            // +0x1054
    char pad_end[3];                 // +0x1055

    PointMaker();
    ~PointMaker();

    void SetDefaultValues();
    void ClearArrays();
    void DeleteArrays();
    void MakeArrays();
    int CreateShape();
    int CreateShape(int x, int y);

    void SetPoint(int x, int y);
    void SetMaxNumberOfBranches(int value);
    void SetChanceOfNextNode(int value);
    void SetNumberOfSatellites(int value);
    void SetSplitsPerBranch(int value);
    void SetWidthAndHeight(int width, int height);
    void SetStartPositionRadius(int value);
    void SetBranchsRadius(int value);
    void SetSatelliteRadius(int value);
    void SetMaxNumberOfBranchLevels(int value);
    void SetSatelliteDistance(int value);
    void SetBranchDistance(int value);
    void SetMinimumNumberOfTiles(int value);
    void SetDrawToOneArray();
    void SetBorderDepthPercentage(int value);
    char* RetrieveMap();
    char* RetrieveProbMap();

protected:
    void CreateMasks();
    void DeleteMasks();
    void DrawMask(int x, int y, int size);
    void Branch(int point);
    int MakeFirstLink();
    int MakeNewLink();
    int MakeSatelliteLink();
    void DrawPrimaryIntoProbabilityArray();
    void DrawCurrentBranchIntoProbArray(int point);
    void DrawCurrentSatelliteIntoProbArray(int point);
    void AddingRect(int left, int top, int right, int bottom);
    void AddingCircle(int x, int y, int radius);
    void CreateMapBasedOnProbabilityArray();
    void ErrorCheckingAndCorrection();
    void PrepareLimits();
    void MapCleanUpEliminatingSinglesOnly();
};

typedef char point_maker_size_check[(sizeof(PointMaker) == 0x1058) ? 1 : -1];

#endif  // AOE1_FRACTAL_H
