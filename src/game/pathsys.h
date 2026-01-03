#pragma once
#include "../common.h"


// ----------------------------------------------------------------
// BYTEPoint
// Size: 0x2
struct BYTEPoint {
    uchar x; // 0x0
    uchar y; // 0x1
};

// ----------------------------------------------------------------
// FloatHeap
// Size: 0x8
struct FloatHeap {
    uchar x; // 0x0
    uchar y; // 0x1
    float total; // 0x4
};

// ----------------------------------------------------------------
// MGP_FloatHeap
// Size: 0x8
struct MGP_FloatHeap {
    uchar x; // 0x0
    uchar y; // 0x1
    ushort next; // 0x2
    int total; // 0x4
};

class PathingSystem {
public:
    int xSizeValue;                          // 0x4
    int ySizeValue;                          // 0x8
    uchar* facetValue[255];                  // 0xC
    int* MGP_costValue[255];                 // 0xFE10
    MGP_FloatHeap MGP_openPaths[65026];      // 0x4F614
    uchar* obstructionValue[1020];           // 0xCE624
    uchar* miscValue[255];                   // 0x10DE28
    int numberOpenPathsValue;                // 0x11DC2C
    MGP_FloatHeap MGP_bestTraversedPath;     // 0x11DC30
    int numberTraversedPathsValue;           // 0x11DC38
    RGE_Map* mapValue;                       // 0x11DC3C
    RGE_Game_World* worldValue;              // 0x11DC40
    RGE_Moving_Object* currentObject;        // 0x11DC44
    int currentObjectInObMap;                // 0x11DC48
    int currentTargetID;                     // 0x11DC4C
    float* currentTerrainTable;              // 0x11DC50
    float currentXOffset;                    // 0x11DC54
    float currentYOffset;                    // 0x11DC58
    int currentTerrainException1;            // 0x11DC5C
    int currentTerrainException2;            // 0x11DC60
    ManagedArray_int initialCollidingObjects; // 0x11DC64
    int startOfPath;                         // 0x11DC74
    int checkTerrainOnFirstPass;             // 0x11DC78
    XYPoint initialTile;                     // 0x11DC7C
    XYPoint minTarget;                       // 0x11DC84
    XYPoint maxTarget;                       // 0x11DC8C
    XYPoint minInitialPosition;              // 0x11DC94
    XYPoint maxInitialPosition;              // 0x11DC9C
    float averageNumWaypoints;               // 0x11DCA4
    float averagePathLength;                 // 0x11DCA8
    float averagePathIterations;             // 0x11DCAC
    int numAttempts;                         // 0x11DCB0
    int numFails;                            // 0x11DCB4
    int numSuccesses;                        // 0x11DCB8
    int numInitialPathsValue;                // 0x11DCBC
    int numContinuePathsValue;               // 0x11DCC0
    int numCanPathsValue;                    // 0x11DCC4
    int MGP_closestTargetDistance;           // 0x11DCC8
    float averageClosestTargetDistance;      // 0x11DCCC
    float averageSuccessTime;                // 0x11DCD0
    float averageFailTime;                   // 0x11DCD4
    uchar CurrentFacetMask;                  // 0x11DCD8
    int currentUnobstructibleGroupID;        // 0x11DCDC
    int currentUnobstructiblePlayerID;       // 0x11DCE0
    ManagedArray_int currentUnobstructibles; // 0x11DCE4
    int aiPS;                                // 0x11DCF4

    PathingSystem(int param_1, int param_2, int param_3, RGE_Map* param_4, RGE_Game_World* param_5);
    virtual ~PathingSystem();
    virtual int initialize(int param_1, int param_2, RGE_Map* param_3, RGE_Game_World* param_4);
    virtual void printToFile(char* param_1);
    virtual uchar lookupMisc(int param_1, int param_2);
    virtual void setMisc(int param_1, int param_2, uchar param_3);
    virtual void initMisc(uchar param_1);
    virtual void zeroObstructionMap();
    virtual uchar obstruction(int param_1, int param_2);
    virtual void incrementObstruction(int param_1, int param_2);
    virtual void decrementObstruction(int param_1, int param_2);
    virtual int findTilePath(int param_1, int param_2, int param_3, int param_4, RGE_Moving_Object* param_5, float param_6, int param_7, int param_8, float* param_9, int param_10, int param_11, int param_12, int param_13, int param_14, int param_15);
    virtual void incrementInitialPaths();
    virtual void incrementContinuePaths();
    virtual void incrementCanPaths();
    virtual int passable(RGE_Moving_Object* param_1, float param_2, float param_3, int param_4);
    virtual long checksum();
    virtual void printState(RGE_Moving_Object* param_1);
    virtual int copyPath(int param_1);
    virtual void copyUnobstructibles(ManagedArray_int* param_1);
};

static_assert(sizeof(PathingSystem) == 0x11DCF8, "PathingSystem Size Mismatch");
static_assert(offsetof(PathingSystem, aiPS) == 0x11DCF4, "PathingSystem Offset Mismatch");

