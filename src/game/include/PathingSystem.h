#pragma once
#include "common.h"

class PathingSystem {
public:
    // Virtuals (best-effort)
    virtual ~PathingSystem(); // vt[0] (0x0)

    int xSizeValue;
    int ySizeValue;
    uchar facetValue[255];
    int MGP_costValue[255];
    MGP_FloatHeap MGP_openPaths[65026];
    uchar obstructionValue[1020];
    uchar miscValue[255];
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
    int currentUnobstructibleGroupID;
    int currentUnobstructiblePlayerID;
    ManagedArray<int> currentUnobstructibles;
    int aiPS;
};
static_assert(sizeof(PathingSystem) == 0x11DCF8, "Size mismatch");
