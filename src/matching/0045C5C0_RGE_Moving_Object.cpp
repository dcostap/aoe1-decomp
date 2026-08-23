// VA: 0045C5C0 RGE_Moving_Object ctor from game object (308B)
// move_obj.cpp lines 130-146
// FLAGS: config/flags/0045C5C0_RGE_Moving_Object.rsp (/GX)
// Attempt log:
// - Baseline scaffold only called two Path constructors through a fake cdecl
//   helper and omitted the base ctor, EH-owned members, and setup branch.
// - Reconstructing the period ABI: (int mode, RGE_Game_World*, int doSetup),
//   RGE_Animated_Object base construction with doSetup=0, two Path members,
//   named moving-object fields, setGoal(0,0,0), and conditional setup.
// - Member-initializing the range/sentinel fields (instead of assigning them
//   in the body) naturally delayed the derived-vptr store to the original
//   position; result is an exact 308-byte MATCH with no manual vptr code.

#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Game_World;

class RGE_Animated_Object {
public:
    virtual ~RGE_Animated_Object();
    char gap_04[0x88];

    RGE_Animated_Object(int mode, RGE_Game_World* world, int doSetup);
};

class Path {
public:
    Path(int maxSize);
    ~Path();
    char data[0x34];
};

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facet;
    unsigned char pad[3];
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
    unsigned char storePathInExceptionPath;
    unsigned char waitingToMove;
    unsigned char numberWaitDelays;
    unsigned char pad_157;
    int minInitialPointX;
    int minInitialPointY;
    int maxInitialPointX;
    int maxInitialPointY;
    void* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    unsigned char pad_175[3];
    float closestDistanceToWaypoint;
    unsigned char lastFacet;
    unsigned char lastFacet2;
    unsigned char pad_17e[2];

    virtual ~RGE_Moving_Object();
    RGE_Moving_Object(int mode, RGE_Game_World* world, int doSetup);
    void setGoal(float x, float y, float z);
    virtual int setup(int mode, RGE_Game_World* world);
};
#endif

RGE_Moving_Object::RGE_Moving_Object(int mode,
                                     RGE_Game_World* world,
                                     int doSetup)
    : RGE_Animated_Object(mode, world, 0),
      pathValue(10),
      exceptionPathValue(10),
      rangeStatusValue(2),
      currentTerrainException1(-1),
      currentTerrainException2(-1),
      storePathInExceptionPath(0),
      waitingToMove(0),
      numberWaitDelays(0),
      userDefinedWaypoints(0),
      numberUserDefinedWaypointsValue(0),
      maxUserDefinedWaypointsValue(0),
      finalUserDefinedWaypoint(0) {

    this->startValue.x = 0.0f;
    this->startValue.y = 0.0f;
    this->startValue.z = 0.0f;
    this->setGoal(0.0f, 0.0f, 0.0f);
    this->turnTimer = 0.0f;
    this->lastFacet = 0xFF;
    this->lastFacet2 = 0xFF;
    this->collisionAvoidanceDistance = 0.0f;
    this->actionRange = 0.0f;
    this->targetIDValue = -1;
    this->targetRadiusX = 0.0f;
    this->targetRadiusY = 0.0f;
    this->continueCounter = 0;
    this->closestDistanceToWaypoint = 100000.0f;

    if (doSetup != 0) {
        this->setup(mode, world);
    }
}
