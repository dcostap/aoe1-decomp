// VA: 0045CAA0 RGE_Moving_Object::setup
// Attempt log:
// try 1: natural load/setup reconstruction from packet; models rge_read sequence,
// Path insertion/reset, user-defined waypoint allocation/load, and version-gated fields.
// Integration pass: PDB call evidence requires Path::insertAtEnd,
// Path::inittostart, and Path::movetonextwaypoint. The raw 0x47C35000 store
// stays an int bit pattern. The standalone owner now reports MATCH.

extern "C" void rge_read(int fd, void* dst, int size);
extern void* __cdecl operator new(unsigned int size);

extern float savegame_version;
extern float version_570B54;
extern float version_570B58;
extern float version_570B5C;

#ifndef MOVE_OBJ_CANONICAL_TU
struct Waypoint { int x; int y; int z; int w; };
struct UserWaypoint { char data[3]; };
typedef UserWaypoint XYZBYTEPoint;

class Path {
public:
    char data[0x34];
    Path();
    ~Path();
    void insertAtEnd(Waypoint wp);
    void inittostart();
    void movetonextwaypoint();
};

class RGE_Animated_Object {
public:
    virtual ~RGE_Animated_Object();
    int setup(int fd, void* world);
    char gap04[0x4a];
    unsigned char type;
    char gap04_tail[0x3d];
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    int trail_remainder;
    int velocity_x;
    int velocity_y;
    int velocity_z;
    int angle;
    int turn_towards_time;
    Path pathValue;              // +a4
    Path exceptionPathValue;     // +d8
    Waypoint startValue;         // +10c
    Waypoint goalValue;          // +11c
    int turnTimer;
    int collisionAvoidanceDistance;
    int actionRange;
    int targetIDValue;
    int targetRadiusX;
    int targetRadiusY;
    int continueCounter;
    int rangeStatusValue;
    char gap_14c[9];
    unsigned char waitingToMove;
    unsigned char numberWaitDelays;
    char gap_157;
    int minInitialPointX;
    int minInitialPointY;
    int maxInitialPointX;
    int maxInitialPointY;
    UserWaypoint* userDefinedWaypoints; // +168
    int numberUserDefinedWaypointsValue; // +16c
    int maxUserDefinedWaypointsValue; // +170
    unsigned char finalUserDefinedWaypoint;
    char gap_175[3];
    float closestDistanceToWaypoint; // +178
    unsigned char lastFacet;
    unsigned char lastFacet2;

    int setup(int fd, void* world);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define waitingToMove waitingToMoveValue
#endif

int RGE_Moving_Object::setup(int fd, void* world)
{
    RGE_Animated_Object::setup(fd, world);
    this->type = 0x1e;

    rge_read(fd, &this->trail_remainder, 4);
    rge_read(fd, &this->velocity_x, 4);
    rge_read(fd, &this->velocity_y, 4);
    rge_read(fd, &this->velocity_z, 4);
    rge_read(fd, &this->angle, 4);
    rge_read(fd, &this->turn_towards_time, 4);

    int count;
    rge_read(fd, &count, 4);
    for (int i = 0; i < count; ++i) {
        Waypoint wp;
        rge_read(fd, &wp, 0x10);
        this->pathValue.insertAtEnd(wp);
    }

    int reset_count;
    rge_read(fd, &reset_count, 4);
    int j = 0;
    this->pathValue.inittostart();
    for (; j < reset_count; ++j) {
        this->pathValue.movetonextwaypoint();
    }

    rge_read(fd, &this->startValue, 0x10);
    rge_read(fd, &this->goalValue, 0x10);
    rge_read(fd, &this->turnTimer, 4);
    rge_read(fd, &this->collisionAvoidanceDistance, 4);
    rge_read(fd, &this->actionRange, 4);
    rge_read(fd, &this->targetIDValue, 4);
    rge_read(fd, &this->targetRadiusX, 4);
    rge_read(fd, &this->targetRadiusY, 4);
    rge_read(fd, &this->continueCounter, 4);
    rge_read(fd, &this->rangeStatusValue, 4);
    rge_read(fd, &this->waitingToMove, 1);
    rge_read(fd, &this->numberWaitDelays, 1);

    rge_read(fd, &this->numberUserDefinedWaypointsValue, 4);
    rge_read(fd, &this->maxUserDefinedWaypointsValue, 4);
    this->userDefinedWaypoints = (XYZBYTEPoint*)operator new(this->maxUserDefinedWaypointsValue * 3);
    for (int k = 0; k < this->numberUserDefinedWaypointsValue; ++k) {
        rge_read(fd, &this->userDefinedWaypoints[k], 3);
    }

    rge_read(fd, &this->finalUserDefinedWaypoint, 1);

    if (!(savegame_version < version_570B54)) {
        rge_read(fd, &this->minInitialPointX, 8);
        rge_read(fd, &this->maxInitialPointX, 8);
    } else {
        this->minInitialPointX = -1;
        this->minInitialPointY = -1;
        this->maxInitialPointX = -1;
        this->maxInitialPointY = -1;
    }

    if (!(savegame_version < version_570B58)) {
        rge_read(fd, &this->closestDistanceToWaypoint, 4);
        rge_read(fd, &this->lastFacet, 1);
    } else {
        *(int*)&this->closestDistanceToWaypoint = 0x47c35000;
        this->lastFacet = 0xff;
    }

    if (!(savegame_version < version_570B5C)) {
        rge_read(fd, &this->lastFacet2, 1);
        return 1;
    }
    this->lastFacet2 = 0xff;
    return 1;
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef waitingToMove
#endif
