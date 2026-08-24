// VA: 0046B0F0 PathingSystem(int,int,int,RGE_Map*,RGE_Game_World*) (349B)
// pathsys.cpp lines 104-136
// EH frame (/GX)
//
// Attempt log:
// - Baseline: restored the complete binary-proven PathingSystem layout, real
//   helper calls, and a typed diagonal-distance pointer loop; the missing
//   nontrivial ManagedArray constructor surface caused the EH/zero-init drift.
// - An inline zeroing ManagedArray constructor plus its destructor declaration
//   restored the VC5 /GX registration and both four-dword member init groups.
// - Adding the complete named field set and matching the original independent
//   zero-store order reduced the candidate to four bytes; the average closest
//   distance field is initialized before the attempt counters in the period
//   source order.
// - The dead aiPS parameter home is naturally reused as the signed loop counter.
//   Reversing the ordinary counter/pointer increment statements recovered the
//   target's EDX coloring, signed branch, and exact 349-byte output.

#include "../../include/game_globals.h"

#ifndef PATHSYS_TU_CONTEXT
struct RGE_Map;
class RGE_Game_World;
class RGE_Moving_Object;

extern int DiagionalDistance[256];

// The three constants are the original pathsys.cpp literal pool entries.
// They are declared by game_globals.h and keep the period source expression's
// float widths and relocation identity.

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
    ~ManagedArray();
};

struct MGP_FloatHeap {
    unsigned char x;
    unsigned char y;
    unsigned short next;
    int total;
};

struct XYPoint {
    int x;
    int y;
};

class PathingSystem {
public:
    virtual ~PathingSystem();

    int xSizeValue;
    int ySizeValue;
    unsigned char facetValue[255][255];
    unsigned char pad_fe0d[3];
    int MGP_costValue[255][255];
    MGP_FloatHeap MGP_openPaths[65026];
    unsigned char obstructionValue[1020][255];
    unsigned char miscValue[255][255];
    unsigned char pad_11dc29[3];

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
    unsigned char CurrentFacetMask;
    unsigned char pad_11dcd9[3];
    int currentUnobstructibleGroupID;
    int currentUnobstructiblePlayerID;
    ManagedArray<int> currentUnobstructibles;
    int aiPS;

    PathingSystem(int xSize, int ySize, int aiPS, RGE_Map* map,
                  RGE_Game_World* world);
    int initialize(int xSize, int ySize, RGE_Map* map, RGE_Game_World* world);
    void initMisc(unsigned char value);
    void zeroObstructionMap();
};
#endif

PathingSystem::PathingSystem(int xSize, int ySize, int aiPS,
                             RGE_Map* map, RGE_Game_World* world)
{
    this->aiPS = aiPS;
    this->xSizeValue = -1;
    this->ySizeValue = -1;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;

    this->numberOpenPathsValue = 0;
    this->numberTraversedPathsValue = 0;
    this->mapValue = 0;
    this->worldValue = 0;
    this->currentObject = 0;
    this->averageNumWaypoints = 0.0f;
    this->averagePathLength = 0.0f;
    this->averagePathIterations = 0.0f;
    this->averageClosestTargetDistance = 0.0f;
    this->numAttempts = 0;
    this->numFails = 0;
    this->numSuccesses = 0;
    this->numInitialPathsValue = 0;
    this->numContinuePathsValue = 0;
    this->numCanPathsValue = 0;
    this->averageSuccessTime = 0.0f;
    this->averageFailTime = 0.0f;

    this->initialize(xSize, ySize, map, world);
    this->initMisc(0);
    this->zeroObstructionMap();

    aiPS = 0;
    int* distance = DiagionalDistance;
    do {
        *distance = (int)(DAT_00570e50 - (float)aiPS * DAT_00570e48 * DAT_00570e4c);
        ++aiPS;
        ++distance;
    } while ((int)distance < (int)(DiagionalDistance + 256));
}
