#ifndef MOVE_OBJ_H
#define MOVE_OBJ_H

#include "ani_obj.h"
#include "path.h"
#include "zone_map.h"

class RGE_Game_World;
class RGE_Master_Moving_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
struct XYZBYTEPoint;
struct XYZPoint;

template<class T> class ManagedArray;

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
    unsigned char waitingToMoveValue;
    unsigned char numberWaitDelays;
    XYPoint minInitialPointValue;
    XYPoint maxInitialPointValue;
    XYZBYTEPoint* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    float closestDistanceToWaypoint;
    unsigned char lastFacet;
    unsigned char lastFacet2;

    enum PathResult {
        PathFound = 0,
        PathNoPath = 1,
        NoPathFound = 1,
        WaitingOnPathingCap = 2
    };

    virtual float teleport(float, float, float);
    RGE_Moving_Object(RGE_Master_Moving_Object*, RGE_Player*, float, float, float, int);
    RGE_Moving_Object(int, RGE_Game_World*, int);
    virtual ~RGE_Moving_Object();
    void destroy();
public:
    void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    void save(int);
    void new_sprite(RGE_Sprite*);
    RGE_Static_Object* spawn_death_obj();
    void transform(RGE_Master_Static_Object*);
    unsigned char is_moving();
    virtual void stop_moving();
    int movement_state() const;
    virtual unsigned char waitingToMove() const;
    float angle_to_object(RGE_Static_Object*, float, float);
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float);
protected:
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
public:
    void set_velocity(float, float, float);
    void new_angle(float);
    const Path& getPath() const;
    virtual unsigned char facetToNextWaypoint() const;
    void setGoal(float, float, float);
    void setActionRange(float);
    void setTargetID(int);
    void setTargetRadius(float, float);
    virtual void setWaitingToMove(unsigned char);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    void setFinalUserDefinedWaypoint();
    void setInitialPoints(XYPoint&, XYPoint&);
    void copy_obj(RGE_Master_Static_Object*);
    virtual void rotate(long);
    virtual long get_waypoint_checksum();
    void boundAngle(float*, int);
    void set_angle();
    int doTrivialMove(float, float);
    int doMove();
    PathResult findPath();
    virtual Path* findAvoidancePath(XYZPoint&, float, int);
    virtual int passableTile(float, float, int);
    virtual float maximumSpeed();
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>&);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(const XYPoint&, const XYPoint&, float, XYPoint&, int);
    virtual int firstTileAlongLine(const XYPoint&, const XYPoint&, XYPoint&, int, int, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    void setStart(float, float, float);
    void displayPath(int);
};

typedef char rge_moving_object_size_check[
    (sizeof(RGE_Moving_Object) == 0x180) ? 1 : -1];

#endif
