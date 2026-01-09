#pragma once
#include "common.h"

enum PathResult : unsigned int {
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

    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[1]+0x4=0x45C790
    virtual void save(int param_1);                         // vt0[12]+0x30=0x45CE00
    virtual float teleport(float param_1, float param_2, float param_3); // vt0[13]+0x34=0x45D3D0
    virtual void new_sprite(RGE_Sprite* param_1);           // vt0[14]+0x38=0x45D080
    virtual void transform(RGE_Master_Static_Object* param_1); // vt0[21]+0x54=0x45D0E0
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[22]+0x58=0x460D60
    virtual void rotate(long param_1);                      // vt0[30]+0x78=0x460EB0
    virtual void new_angle(float param_1);                  // vt0[45]+0xB4=0x45D5F0
    virtual RGE_Static_Object* spawn_death_obj();           // vt0[46]+0xB8=0x45D0B0
    virtual uchar is_moving();                              // vt0[50]+0xC8=0x45D120
    virtual float getAngle();                               // vt0[62]+0xF8=0x405F50
    virtual float maximumSpeed();                           // vt0[63]+0xFC=0x4608D0
    virtual int passableTile(float param_1, float param_2, int param_3); // vt0[69]+0x114=0x45F7F0
    virtual uchar facetToNextWaypoint();                    // vt0[70]+0x118=0x45D620
    virtual void setWaitingToMove(uchar param_1);           // vt0[75]+0x12C=0x460930
    virtual uchar waitingToMove();                          // vt0[76]+0x130=0x460900
    virtual int canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6); // vt0[101]+0x194=0x45F9D0
    virtual int canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7); // vt0[102]+0x198=0x45F820
    virtual int canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7); // vt0[103]+0x19C=0x45FBC0
    virtual int canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray<int>* param_7); // vt0[104]+0x1A0=0x45FED0
    virtual int canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9); // vt0[105]+0x1A4=0x4600F0
    virtual int findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3); // vt0[106]+0x1A8=0x460210
    virtual int canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6); // vt0[107]+0x1AC=0x460570
    virtual int canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5); // vt0[108]+0x1B0=0x4603B0
    virtual int firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6); // vt0[109]+0x1B4=0x460710
    virtual XYZBYTEPoint* userDefinedWaypoint(int param_1); // vt0[110]+0x1B8=0x460940
    virtual int addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2); // vt0[111]+0x1BC=0x460970
    virtual void removeAllUserDefinedWaypoints(int param_1); // vt0[112]+0x1C0=0x460B20
    virtual void removeUserDefinedWaypoint(int param_1);    // vt0[113]+0x1C4=0x460B70
    virtual int numberUserDefinedWaypoints();               // vt0[114]+0x1C8=0x405F60
    virtual Path* findAvoidancePath(XYZPoint* param_1, float param_2, int param_3); // vt0[115]+0x1CC=0x460C00
    virtual long get_waypoint_checksum();                   // vt0[117]+0x1D4=0x460F40
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x45CAA0
    virtual void stop_moving();                             // vt0[123]+0x1EC=0x45D140
    virtual uchar turn_towards(RGE_Static_Object* param_1, float param_2, float param_3); // vt0[124]+0x1F0=0x45D1F0
    virtual int setup(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[125]+0x1F4=0x45C970
    RGE_Moving_Object(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Moving_Object(int param_1, RGE_Game_World* param_2, int param_3);
    ~RGE_Moving_Object();
    float angle_to_object(RGE_Static_Object* param_1, float param_2, float param_3);
    void set_angle();
    void set_velocity(float param_1, float param_2, float param_3);
    Path* getPath();
    void setGoal(float param_1, float param_2, float param_3);
    void setActionRange(float param_1);
    void setTargetID(int param_1);
    void setTargetRadius(float param_1, float param_2);
    PathResult findPath();
    int doMove();
    int doTrivialMove(float param_1, float param_2);
    void setFinalUserDefinedWaypoint();
    void setInitialPoints(XYPoint* param_1, XYPoint* param_2);
    void boundAngle(float* param_1, int param_2);
};

static_assert(sizeof(RGE_Moving_Object) == 0x180, "RGE_Moving_Object Size Mismatch");

