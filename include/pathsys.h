#ifndef AOE1_PATHSYS_H
#define AOE1_PATHSYS_H

#include "utmarray.h"
#include "zone_map.h"

class RGE_Game_World;
class RGE_Map;
class RGE_Moving_Object;

typedef unsigned char uchar;
typedef unsigned int uint;

extern int MapPathsDisplay;
extern int numberPathingIterations;

struct PathTileWork {
    XYPoint current;
    XYPoint next;
    XYPoint copied;
};

typedef char pathsys_tile_work_size_check[(sizeof(PathTileWork) == 0x18) ? 1 : -1];
typedef char pathsys_managed_array_size_check[(sizeof(ManagedArray<int>) == 0x10) ? 1 : -1];

class PathingSystem {
  public:
    class MGP_FloatHeap {
      public:
        uchar x;
        uchar y;
        unsigned short next;
        int total;
    };

    virtual ~PathingSystem();

    int xSizeValue;
    int ySizeValue;
    uchar facetValue[255][255];
    int MGP_costValue[255][255];
    MGP_FloatHeap MGP_openPaths[65026];
    uchar obstructionValue[1020][255];
    uchar miscValue[255][255];

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

    PathingSystem(int x, int y, int aiPS, RGE_Map* map, RGE_Game_World* world);
    int initialize(int x, int y, RGE_Map* map, RGE_Game_World* world);
    void initMisc(unsigned char v);
    void zeroObstructionMap();
    unsigned char lookupMisc(int x, int y);
    void setMisc(int x, int y, unsigned char v);
    unsigned char obstruction(int x, int y);
    void incrementObstruction(int x, int y);
    void decrementObstruction(int x, int y);
    int findTilePath(
        int startX, int startY, int goalX, int goalY, RGE_Moving_Object* unit, float actionRange, int cTargetID,
        int copyPathWhenDone, float* pathLength, int checkPathingIterations, int checkTerrainFirstTime,
        int checkCollisions, int stepSize, int unobstructiblePlayerID, int unobstructibleGroupID
    );
    void incrementInitialPaths();
    void incrementContinuePaths();
    void incrementCanPaths();
    int passable(RGE_Moving_Object* obj, float newX, float newY, int checkTerrain);
    long checksum(void);

  protected:
    void printState(RGE_Moving_Object* unit);
    int copyPath(int stepSize);

  public:
    void copyUnobstructibles(ManagedArray<int>& d);
    void printToFile(char* filename);
};

typedef char pathsys_size_check[(sizeof(PathingSystem) == 0x11DCF8) ? 1 : -1];
typedef char pathsys_mgp_float_heap_size_check[(sizeof(PathingSystem::MGP_FloatHeap) == 0x08) ? 1 : -1];

#endif
