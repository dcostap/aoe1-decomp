// VA: 0046D830 PathingSystem::copyPath(int) (1114B)
// pathsys.cpp lines 2249-2421
//
// Attempt log:
// - Prior source was a raw PathSys/PathChecker scaffold and remained 10 bytes
//   short with mismatched helper surfaces.  This reconstruction restores the
//   named PathingSystem, RGE_Moving_Object, Path, Waypoint, and ManagedArray
//   ownership shown by the same-TU packet and exact donors.
// - The source keeps the executable's two-byte open-path coordinate, facet
//   mask/direction conversion, selected normal/exception Path, bounded neighbor
//   scan, inline ManagedArray::add, eight-way switch, and final insertion.
// - The typed candidate reaches the original 0x34 frame, 9/9 ordered calls,
//   33/33 conditional signals, and the original 1114-byte boundary.  The
//   remaining 46 bytes are structural/codegen drift around the waypoint
//   construction, initToStart path selection, and the first loop entry; no
//   call target or ownership mismatch remains.  The final source is kept as
//   the readable canonical reconstruction rather than a compiler-steering
//   variant.
// - Tested a natural typed facet-before-coordinate assignment order because
//   the target loads the facet before its floating-point coordinate stores;
//   it moved 25 positional bytes farther from the clean candidate and was
//   rolled back.  The clean x/y/z/facet order remains the best reconstruction.
// - Matched the neighbor-bound structure with incremented max and decremented
//   min values; this reduced the rebuilt size to the original 1114 bytes.
// - A declaration initializer for previousFacet preserves the original EBX
//   sentinel liveness and reduced the best strict diff to 229 bytes.
//   A currentObject local also matches the original pointer carry into the
//   waypoint and initToStart code.  Row-pointer and foo-order variants emitted
//   identical code and were rolled back to the direct natural expressions.

#include <stddef.h>

typedef unsigned char uchar;

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

struct XYPoint {
    int x;
    int y;
};

struct BYTEPoint {
    uchar x;
    uchar y;
};

struct Waypoint {
    float x;
    float y;
    float z;
    uchar facetToNextWaypoint;
    uchar pad[3];
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int add(T val) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == val)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int new_size = this->numberValue + 1;
            T* new_data = (T*)operator_new(new_size * sizeof(T));
            if (new_data != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= new_size)
                        break;
                    new_data[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }

        this->value[this->numberValue] = val;
        this->numberValue++;
        return 1;
    }
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    void killPath();
    void initToStart();
    int insertAtCurrent(const Waypoint& waypoint);
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    void* master_obj;
    void* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
    uchar sleep_flag;
    uchar dopple_flag;
    uchar goto_sleep_flag;
    short attribute_type_held;
    uchar type;
    uchar worker_num;
    void* player_object_node;
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;
    uchar pad_87;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    Path pathValue;
    Path exceptionPathValue;
    Waypoint startValue;
    Waypoint goalValue;
    float turnTimer;
    float collisionAvoidanceDistance;
    float actionRange;
    int targetIDValue;
    float targetRadiusX;
    float targetRadiusY;
    int continueCounter;
    int rangeStatusValue;
    int currentTerrainException1;
    int currentTerrainException2;
    uchar storePathInExceptionPath;
    uchar waitingToMoveValue;
    uchar numberWaitDelays;
    uchar pad_157;
};

class RGE_Game_World {
public:
    char gap_00[0x40];

    int objectGroupOnTile(int playerId, int objectGroup, int tileX, int tileY,
                          int* objectCountOnTile);
};

class PathingSystem {
public:
    void* vtable_ptr;
    int xSizeValue;
    int ySizeValue;
    uchar facetValue[255][255];
    uchar pad_fe0d[3];
    int MGP_costValue[255][255];

    struct MGP_FloatHeap {
        uchar x;
        uchar y;
        unsigned short next;
        int total;
    };

    MGP_FloatHeap MGP_openPaths[65026];
    uchar obstructionValue[1020][255];
    uchar miscValue[255][255];
    uchar pad_11dc29[3];
    int numberOpenPathsValue;
    MGP_FloatHeap MGP_bestTraversedPath;
    int numberTraversedPathsValue;
    void* mapValue;
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
    uchar pad_11dcd9[3];
    int currentUnobstructibleGroupID;
    int currentUnobstructiblePlayerID;
    ManagedArray<int> currentUnobstructibles;

    int copyPath(int step);
};

int PathingSystem::copyPath(int step)
{
    uchar previousFacet = 0xFF;

    {
        Path* path;
        if (this->currentObject->storePathInExceptionPath == 0)
            path = &this->currentObject->pathValue;
        else
            path = &this->currentObject->exceptionPathValue;
        path->killPath();
    }

    BYTEPoint currentPoint;
    currentPoint.x = this->MGP_openPaths[1].x;
    currentPoint.y = this->MGP_openPaths[1].y;
    uchar currentFacet = this->facetValue[currentPoint.x][currentPoint.y];
    int fooX = currentPoint.x;
    int fooY = currentPoint.y;
    if ((currentFacet & 0xF8) == this->CurrentFacetMask)
        currentFacet &= 7;
    else
        currentFacet = 0xFF;

    RGE_Moving_Object* object = this->currentObject;
    Waypoint waypoint;
    waypoint.x = (float)fooX + this->currentXOffset;
    waypoint.y = (float)fooY + this->currentYOffset;
    waypoint.z = object->world_z;
    waypoint.facetToNextWaypoint = currentFacet;

    {
        Path* path = object->storePathInExceptionPath == 0
            ? &object->pathValue
            : &object->exceptionPathValue;
        path->initToStart();
    }

    do {
        if (this->initialTile.x == fooX && this->initialTile.y == fooY) {
            if (this->currentObject->storePathInExceptionPath != 0) {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            } else {
                if (this->currentObject->pathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            }
            return 1;
        }

        if (currentFacet != previousFacet) {
            if (this->currentObject->storePathInExceptionPath != 0) {
                if (this->currentObject->exceptionPathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            } else {
                if (this->currentObject->pathValue.insertAtCurrent(waypoint) == 0)
                    return 0;
            }
        }

        if (this->currentUnobstructibleGroupID != -1) {
            int minX = fooX - 1;
            int maxX = fooX + 1;
            if (minX < 0) {
                minX = 0;
                ++maxX;
            } else if (this->xSizeValue <= maxX) {
                --minX;
                maxX = this->xSizeValue - 1;
            }

            int minY = fooY - 1;
            int maxY = fooY + 1;
            if (minY < 0) {
                minY = 0;
                ++maxY;
            } else if (this->ySizeValue <= maxY) {
                --minY;
                maxY = this->ySizeValue - 1;
            }

            for (int tileX = minX; tileX <= maxX; ++tileX) {
                for (int tileY = minY; tileY <= maxY; ++tileY) {
                    int objectCountOnTile = 0;
                    int id = this->worldValue->objectGroupOnTile(
                        this->currentUnobstructiblePlayerID,
                        this->currentUnobstructibleGroupID,
                        tileX, tileY, &objectCountOnTile);
                    if (id != -1)
                        this->currentUnobstructibles.add(id);
                }
            }
        }

        switch ((int)currentFacet) {
        case 0:
            currentPoint.x += (uchar)step;
            currentPoint.y += (uchar)step;
            break;
        case 1:
            currentPoint.y += (uchar)step;
            break;
        case 2:
            currentPoint.x -= (uchar)step;
            currentPoint.y += (uchar)step;
            break;
        case 3:
            currentPoint.x -= (uchar)step;
            break;
        case 4:
            currentPoint.x -= (uchar)step;
            currentPoint.y -= (uchar)step;
            break;
        case 5:
            currentPoint.y -= (uchar)step;
            break;
        case 6:
            currentPoint.x += (uchar)step;
            currentPoint.y -= (uchar)step;
            break;
        case 7:
            currentPoint.x += (uchar)step;
            break;
        }

        previousFacet = currentFacet;
        fooX = currentPoint.x;
        fooY = currentPoint.y;
        currentFacet = this->facetValue[fooX][fooY];
        if ((currentFacet & 0xF8) == this->CurrentFacetMask)
            currentFacet &= 7;
        else
            currentFacet = 0xFF;
        waypoint.x = (float)fooX + this->currentXOffset;
        waypoint.y = (float)fooY + this->currentYOffset;
        waypoint.facetToNextWaypoint = currentFacet;
    } while (true);
}
