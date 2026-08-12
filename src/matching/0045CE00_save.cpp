// VA: 0045CE00 save (639B)
// move_obj.cpp:307-349
// Attempt log:
// baseline: natural typed save reconstruction. The call order is base save,
// six float fields, Path count and records, current index, object fields, and
// user-waypoint fields. The binary has no save error branch.
// explicit byte-offset user-waypoint loop: 642B, three bytes too large; the
// index and byte-offset registers were reversed. Rolled back.
// count-field pointer and declaration-order liveness probes: no movement.
// typed XYZBYTEPoint indexing: exact 639B match with direct count access.
// Width audit: 4-byte scalars and records use 4/0x10, points use 8, and byte
// flags use 1. Final source keeps named fields and natural typed loops.

extern "C" void __cdecl rge_write(int handle, const void* buffer, int size);

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char pad[3];
};

class Path {
public:
    virtual ~Path();
    char gap_04[0x28];
    int currentSizeValue;
    int currentWaypointValue;

    int numberOfWaypoints();
    const Waypoint* waypoint(int index) const;
    int currentWaypointNumber();
};

class RGE_Animated_Object {
public:
    virtual void save(int handle);
    char gap_04[0x88];
};

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

struct XYPoint {
    int x;
    int y;
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
    unsigned char storePathInExceptionPath;
    unsigned char gap_14d[8];
    unsigned char waitingToMoveValue;
    unsigned char numberWaitDelays;
    unsigned char gap_157;
    XYPoint minInitialPointValue;
    XYPoint maxInitialPointValue;
    XYZBYTEPoint* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    unsigned char gap_175[3];
    float closestDistanceToWaypoint;
    unsigned char lastFacet;
    unsigned char lastFacet2;

    virtual void save(int handle);
};

void RGE_Moving_Object::save(int handle) {
    RGE_Animated_Object::save(handle);

    rge_write(handle, &this->trail_remainder, 4);
    rge_write(handle, &this->velocity_x, 4);
    rge_write(handle, &this->velocity_y, 4);
    rge_write(handle, &this->velocity_z, 4);
    rge_write(handle, &this->angle, 4);
    rge_write(handle, &this->turn_towards_time, 4);

    Path* path = &this->pathValue;
    int numberOfWaypoints = path->numberOfWaypoints();
    rge_write(handle, &numberOfWaypoints, 4);

    for (int iWaypoint = 0; iWaypoint < numberOfWaypoints; ++iWaypoint) {
        rge_write(handle, path->waypoint(iWaypoint), 0x10);
    }

    int currentWaypoint = path->currentWaypointNumber();
    rge_write(handle, &currentWaypoint, 4);

    rge_write(handle, &this->startValue, 0x10);
    rge_write(handle, &this->goalValue, 0x10);
    rge_write(handle, &this->turnTimer, 4);
    rge_write(handle, &this->collisionAvoidanceDistance, 4);
    rge_write(handle, &this->actionRange, 4);
    rge_write(handle, &this->targetIDValue, 4);
    rge_write(handle, &this->targetRadiusX, 4);
    rge_write(handle, &this->targetRadiusY, 4);
    rge_write(handle, &this->continueCounter, 4);
    rge_write(handle, &this->rangeStatusValue, 4);
    rge_write(handle, &this->waitingToMoveValue, 1);
    rge_write(handle, &this->numberWaitDelays, 1);

    rge_write(handle, &this->numberUserDefinedWaypointsValue, 4);
    rge_write(handle, &this->maxUserDefinedWaypointsValue, 4);

    for (int iUser = 0; iUser < this->numberUserDefinedWaypointsValue; ++iUser) {
        rge_write(handle, &this->userDefinedWaypoints[iUser], 3);
    }

    rge_write(handle, &this->finalUserDefinedWaypoint, 1);
    rge_write(handle, &this->minInitialPointValue, 8);
    rge_write(handle, &this->maxInitialPointValue, 8);
    rge_write(handle, &this->closestDistanceToWaypoint, 4);
    rge_write(handle, &this->lastFacet, 1);
    rge_write(handle, &this->lastFacet2, 1);
}
