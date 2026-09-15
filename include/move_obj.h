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

    virtual float teleport(float x, float y, float z);
    RGE_Moving_Object(RGE_Master_Moving_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int do_setup);
    RGE_Moving_Object(int infile, RGE_Game_World* gworld, int do_setup);
    virtual ~RGE_Moving_Object();
    void destroy();
public:
    void recycle_in_to_game(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y, float z);
    void save(int outfile);
    void new_sprite(RGE_Sprite* nsprite);
    RGE_Static_Object* spawn_death_obj();
    void transform(RGE_Master_Static_Object* obj);
    unsigned char is_moving();
    virtual void stop_moving();
    int movement_state() const;
    virtual float getAngle() const { return this->angle; }
    virtual unsigned char waitingToMove() const;
    float angle_to_object(RGE_Static_Object* to_object, float x, float y);
    virtual unsigned char turn_towards(RGE_Static_Object* obj, float x, float y);
protected:
    virtual int setup(int infile, RGE_Game_World* gworld);
    virtual int setup(RGE_Master_Moving_Object* tobj, RGE_Player* obj_owner, float x, float y, float z);
public:
    void set_velocity(float x, float y, float z);
    void new_angle(float new_angle);
    const Path& getPath() const;
    virtual unsigned char facetToNextWaypoint() const;
    void setGoal(float gX, float gY, float gZ);
    void setActionRange(float r);
    void setTargetID(int tid);
    void setTargetRadius(float x, float y);
    virtual void setWaitingToMove(unsigned char w);
    virtual XYZBYTEPoint* userDefinedWaypoint(int v);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint* p, int stopObject);
    virtual void removeAllUserDefinedWaypoints(int stopObject);
    virtual void removeUserDefinedWaypoint(int v);
    virtual int numberUserDefinedWaypoints() const {
        return this->numberUserDefinedWaypointsValue;
    }
    void setFinalUserDefinedWaypoint();
    void setInitialPoints(XYPoint& min, XYPoint& max);
    void copy_obj(RGE_Master_Static_Object* source2);
    virtual void rotate(long amount);
    virtual long get_waypoint_checksum();
    void boundAngle(float* x, int numFacets);
    void set_angle();
    int doTrivialMove(float x, float y);
    int doMove();
    PathResult findPath();
    virtual Path* findAvoidancePath(XYZPoint& goalPoint, float aRange, int targetID);
    virtual int passableTile(float x, float y, int aiCheck);
    virtual float maximumSpeed();
    virtual int canPath(XYZPoint p, float aRange, int targetID, float* pathDistance, int aiCheck,
                        int unobstructiblePlayerID, int unobstructibleGroupID);
    virtual int canPath(int targetID, float aRange, float* pathDistance, int aiCheck,
                        int unobstructiblePlayerID, int unobstructibleGroupID);
    virtual int canBidirectionPath(int targetID, int targetID2, float aRange, float* pathDistance,
                                   int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID);
    virtual int canPathWithObstructions(int targetID, float aRange, float* pathDistance, int aiCheck,
                                        int unobstructiblePlayerID, int unobstructibleGroupID,
                                        ManagedArray<int>& obstructions);
    virtual int canPathWithAdditionalPassability(XYZPoint p, float aRange, int targetID,
                                                 float* pathDistance, int eTerrain1, int eTerrain2,
                                                 int aiCheck, int unobstructiblePlayerID,
                                                 int unobstructibleGroupID);
    virtual int findFirstTerrainAlongExceptionPath(int eTerrain, float* rX, float* rY);
    virtual int canLinePath(int sX, int sY, int dX, int dY, float range, int aiCheck);
    virtual int canLinePath(const XYPoint& s, const XYPoint& d, float range, XYPoint& rPoint, int aiCheck);
    virtual int firstTileAlongLine(const XYPoint& s, const XYPoint& d, XYPoint& rPoint,
                                   int tType1, int tType2, int checkPassability);
    void setStart(float x, float y, float z);
    void displayPath(int object_id);
};

typedef char rge_moving_object_size_check[
    (sizeof(RGE_Moving_Object) == 0x180) ? 1 : -1];

#endif
