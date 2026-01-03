#pragma once
#include "../common.h"
#include "ani_obj.h"

typedef enum PathResult : unsigned int {
    PathFound = 0,
    NoPathFound = 1,
    WaitingOnPathingCap = 2,
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;                   // 0x8C
    float velocity_x;                        // 0x90
    float velocity_y;                        // 0x94
    float velocity_z;                        // 0x98
    float angle;                             // 0x9C
    float turn_towards_time;                 // 0xA0
    Path pathValue;                          // 0xA4
    Path exceptionPathValue;                 // 0xD8
    Waypoint startValue;                     // 0x10C
    Waypoint goalValue;                      // 0x11C
    float turnTimer;                         // 0x12C
    float collisionAvoidanceDistance;        // 0x130
    float actionRange;                       // 0x134
    int targetIDValue;                       // 0x138
    float targetRadiusX;                     // 0x13C
    float targetRadiusY;                     // 0x140
    int continueCounter;                     // 0x144
    int rangeStatusValue;                    // 0x148
    int currentTerrainException1;            // 0x14C
    int currentTerrainException2;            // 0x150
    uchar storePathInExceptionPath;          // 0x154
    uchar waitingToMoveValue;                // 0x155
    uchar numberWaitDelays;                  // 0x156
    XYPoint minInitialPointValue;            // 0x158
    XYPoint maxInitialPointValue;            // 0x160
    XYZBYTEPoint* userDefinedWaypoints;      // 0x168
    int numberUserDefinedWaypointsValue;     // 0x16C
    int maxUserDefinedWaypointsValue;        // 0x170
    uchar finalUserDefinedWaypoint;          // 0x174
    float closestDistanceToWaypoint;         // 0x178
    uchar lastFacet;                         // 0x17C
    uchar lastFacet2;                        // 0x17D

    virtual float getAngle();
    virtual int numberUserDefinedWaypoints();
    RGE_Moving_Object(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Moving_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual ~RGE_Moving_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual void save(int param_1);
    virtual void new_sprite(RGE_Sprite* param_1);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void transform(RGE_Master_Static_Object* param_1);
    virtual uchar is_moving();
    virtual void stop_moving();
    virtual float angle_to_object(RGE_Static_Object* param_1, float param_2, float param_3);
    virtual uchar turn_towards(RGE_Static_Object* param_1, float param_2, float param_3);
    virtual void set_angle();
    virtual float teleport(float param_1, float param_2, float param_3);
    virtual void set_velocity(float param_1, float param_2, float param_3);
    virtual void new_angle(float param_1);
    virtual Path* getPath();
    virtual uchar facetToNextWaypoint();
    virtual void setGoal(float param_1, float param_2, float param_3);
    virtual void setActionRange(float param_1);
    virtual void setTargetID(int param_1);
    virtual void setTargetRadius(float param_1, float param_2);
    virtual PathResult findPath();
    virtual int doMove();
    virtual int doTrivialMove(float param_1, float param_2);
    virtual int passableTile(float param_1, float param_2, int param_3);
    virtual int canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7);
    virtual int canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6);
    virtual int canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7);
    virtual int canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray_int* param_7);
    virtual int canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9);
    virtual int findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3);
    virtual int canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5);
    virtual int canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6);
    virtual int firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6);
    virtual float maximumSpeed();
    virtual uchar waitingToMove();
    virtual void setWaitingToMove(uchar param_1);
    virtual XYZBYTEPoint* userDefinedWaypoint(int param_1);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2);
    virtual void removeAllUserDefinedWaypoints(int param_1);
    virtual void removeUserDefinedWaypoint(int param_1);
    virtual void setFinalUserDefinedWaypoint();
    virtual Path* findAvoidancePath(XYZPoint* param_1, float param_2, int param_3);
    virtual void setInitialPoints(XYPoint* param_1, XYPoint* param_2);
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual void boundAngle(float* param_1, int param_2);
    virtual void rotate(long param_1);
    virtual long get_waypoint_checksum();
};

static_assert(sizeof(RGE_Moving_Object) == 0x180, "RGE_Moving_Object Size Mismatch");
static_assert(offsetof(RGE_Moving_Object, lastFacet2) == 0x17D, "RGE_Moving_Object Offset Mismatch");

float RGE_Moving_Object::getAngle() {
    /* TODO: Stub */
//                              float __thiscall getAngle(RGE_Moving_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?getAngle@RGE_Moving_Object@@UBEMXZ                          XREF[6]:     0056e518(*), 0056f350(*),
//                               RGE_Moving_Object::getAngle                                               005707e8(*), 00570a40(*),
//                                                                                                         00574870(*), 00574b18(*)
//                              move_obj.h:122 (7)
//         00405f50     FLD        float ptr [ECX + this->angle]
//         00405f56     RET
//         00405f57     ??         90h
//         00405f58     NOP
//         00405f59     NOP
//         00405f5a     NOP
//         00405f5b     NOP
//         00405f5c     NOP
//         00405f5d     NOP
//         00405f5e     NOP
//         00405f5f     NOP
    return 0;
}

int RGE_Moving_Object::numberUserDefinedWaypoints() {
    /* TODO: Stub */
//                              int __thiscall numberUserDefinedWaypoints(RGE_Moving_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?numberUserDefinedWaypoints@RGE_Moving_Object@@UBEHXZ        XREF[6]:     0056e5e8(*), 0056f420(*),
//                               RGE_Moving_Object::numberUserDefinedWaypoints                             005708b8(*), 00570b10(*),
//                                                                                                         00574940(*), 00574be8(*)
//                              move_obj.h:131 (7)
//         00405f60     MOV        EAX,dword ptr [ECX + this->numberUserDefinedWa
//         00405f66     RET
//         00405f67     ??         90h
//         00405f68     NOP
//         00405f69     NOP
//         00405f6a     NOP
//         00405f6b     NOP
//         00405f6c     NOP
//         00405f6d     NOP
//         00405f6e     NOP
//         00405f6f     NOP
    return 0;
}

