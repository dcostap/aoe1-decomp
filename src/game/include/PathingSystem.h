#pragma once
#include "common.h"
#include "MGP_FloatHeap.h"
#include "XYPoint.h"

class PathingSystem {
public:
    PathingSystem(int param_1, int param_2, int param_3, RGE_Map* param_4, RGE_Game_World* param_5);

    // Virtuals (best-effort)
    virtual ~PathingSystem(); // vt[0] (0x0)

    int initialize(int param_1, int param_2, RGE_Map* param_3, RGE_Game_World* param_4);
    void initMisc(uchar param_1);
    void zeroObstructionMap();
    void incrementObstruction(int param_1, int param_2);
    void decrementObstruction(int param_1, int param_2);

    int xSizeValue;
    int ySizeValue;
    uchar facetValue[255][255];
    uchar _pad_0[0x3];
    int MGP_costValue[255][255];
    MGP_FloatHeap MGP_openPaths[65026];
    uchar obstructionValue[1020][255];
    uchar miscValue[255][255];
    uchar _pad_1[0x3];
    int numberOpenPathsValue;
    MGP_FloatHeap MGP_bestTraversedPath;
    int numberTraversedPathsValue;
    RGE_Map* mapValue;
    RGE_Game_World* worldValue;
    RGE_Moving_Object* currentObject;
    int currentObjectInObMap;
    int currentTargetID;
    float* currentTerrainTable;
    float currentXOffset;
    float currentYOffset;
    int currentTerrainException1;
    int currentTerrainException2;
    ManagedArray<int> initialCollidingObjects;
    int startOfPath;
    int checkTerrainOnFirstPass;
    XYPoint initialTile;
    XYPoint minTarget;
    XYPoint maxTarget;
    XYPoint minInitialPosition;
    XYPoint maxInitialPosition;
    float averageNumWaypoints;
    float averagePathLength;
    float averagePathIterations;
    int numAttempts;
    int numFails;
    int numSuccesses;
    int numInitialPathsValue;
    int numContinuePathsValue;
    int numCanPathsValue;
    int MGP_closestTargetDistance;
    float averageClosestTargetDistance;
    float averageSuccessTime;
    float averageFailTime;
    uchar CurrentFacetMask;
    uchar _pad_2[0x3];
    int currentUnobstructibleGroupID;
    int currentUnobstructiblePlayerID;
    ManagedArray<int> currentUnobstructibles;
    int aiPS;
};
static_assert(sizeof(PathingSystem) == 0x11DCF8, "Size mismatch");

extern PathingSystem pathSystem;
extern PathingSystem aiPathSystem;
