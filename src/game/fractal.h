#pragma once
#include "common.h"

class PointMaker {
public:
    PrimaryPt Prime;                         // 0x0
    PtToPt Point[500];                       // 0x8
    char* Mask_2x2;                          // 0xFA8
    char* Mask_3x3;                          // 0xFAC
    char* Mask_4x4;                          // 0xFB0
    char* Mask_5x5;                          // 0xFB4
    int x;                                   // 0xFB8
    int y;                                   // 0xFBC
    int NumSplitsPerBranch;                  // 0xFC0
    int NumberOfSatellites;                  // 0xFC4
    int ChanceOfNextNode;                    // 0xFC8
    int MaxNumberOfBranches;                 // 0xFCC
    int MaxBranchFlag;                       // 0xFD0
    int Width;                               // 0xFD4
    int Height;                              // 0xFD8
    int MinimumNumTiles;                     // 0xFDC
    int NumNodes;                            // 0xFE0
    int NumTilesActuallyChosen;              // 0xFE4
    int CurrentPoint;                        // 0xFE8
    int ProbabilityTiles;                    // 0xFEC
    int TargetProbabilityCount;              // 0xFF0
    int ProbabilityAdd;                      // 0xFF4
    int BranchRadius;                        // 0xFF8
    int SatelliteRadius;                     // 0xFFC
    int PrimaryRadius;                       // 0x1000
    int SizeArrays;                          // 0x1004
    int SatelliteDistance;                   // 0x1008
    int BranchDistance;                      // 0x100C
    int DirX;                                // 0x1010
    int DirY;                                // 0x1014
    int MaxNumberOfBranchLevels;             // 0x1018
    int CurrentNumberOfBranchLevels;         // 0x101C
    char* ExternalArray;                     // 0x1020
    char* ProbArray;                         // 0x1024
    char* PlacementArray;                    // 0x1028
    char* WritableExternalArray;             // 0x102C
    int DoNotDrawOnFlag;                     // 0x1030
    int DrawOnOnlyFlag;                      // 0x1034
    int DrawOnlyInExternalArrayFlag;         // 0x1038
    int DrawToOneArrayFlag;                  // 0x103C
    int BorderDepthPercentage;               // 0x1040
    int LeftLimit;                           // 0x1044
    int RightLimit;                          // 0x1048
    int TopLimit;                            // 0x104C
    int BottomLimit;                         // 0x1050
    char SpecialLandType;                    // 0x1054

    void SetDefaultValues();
    PointMaker();
    ~PointMaker();
    void CreateMasks();
    void DeleteMasks();
    void DrawMask(int param_1, int param_2, int param_3);
    void ClearArrays();
    void DeleteArrays();
    void MakeArrays();
    int CreateShape();
    int CreateShape(int param_1, int param_2);
    void Branch(int param_1);
    int MakeFirstLink();
    int MakeNewLink();
    int MakeSatelliteLink();
    void DrawPrimaryIntoProbabilityArray();
    void DrawCurrentBranchIntoProbArray(int param_1);
    void DrawCurrentSatelliteIntoProbArray(int param_1);
    void AddingRect(int param_1, int param_2, int param_3, int param_4);
    void AddingCircle(int param_1, int param_2, int param_3);
    void CreateMapBasedOnProbabilityArray();
    void SetPoint(int param_1, int param_2);
    void SetMaxNumberOfBranches(int param_1);
    void SetChanceOfNextNode(int param_1);
    void SetNumberOfSatellites(int param_1);
    void SetSplitsPerBranch(int param_1);
    void SetWidthAndHeight(int param_1, int param_2);
    void SetStartPositionRadius(int param_1);
    void SetBranchsRadius(int param_1);
    void SetSatelliteRadius(int param_1);
    void SetMaxNumberOfBranchLevels(int param_1);
    void SetSatelliteDistance(int param_1);
    void SetBranchDistance(int param_1);
    void SetMinimumNumberOfTiles(int param_1);
    void SetDrawToOneArray();
    void SetBorderDepthPercentage(int param_1);
    char* RetrieveMap();
    char* RetrieveProbMap();
    void ErrorCheckingAndCorrection();
    void PrepareLimits();
    void MapCleanUpEliminatingSinglesOnly();
};

static_assert(sizeof(PointMaker) == 0x1058, "PointMaker Size Mismatch");

