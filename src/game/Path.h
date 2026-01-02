#pragma once
#include "../common.h"

class Path {
public:
    Waypoint startValue;                     // 0x4
    Waypoint goalValue;                      // 0x14
    Waypoint* pathValue;                     // 0x24
    int maxSizeValue;                        // 0x28
    int currentSizeValue;                    // 0x2C
    int currentWaypointValue;                // 0x30

    Path(int param_1);
    virtual ~Path();
    virtual Path* operator+(Path* __return_storage_ptr__, Path* param_1);
    virtual Path* operator=(Path* param_1);
    virtual int operator==(Path* param_1);
    virtual int insertAtCurrent(Waypoint* param_1);
    virtual int insertAtEnd(Waypoint param_1);
    virtual int contains(Waypoint* param_1);
    virtual void killPath();
    virtual int maxNumberOfWaypoints();
    virtual int numberOfWaypoints();
    virtual ulong timeStamp();
    virtual void setTimeStamp(ulong param_1);
    virtual float length();
    virtual Waypoint* start();
    virtual Waypoint* goal();
    virtual Waypoint* waypoint(int param_1);
    virtual Waypoint* currentWaypoint();
    virtual int currentWaypointNumber();
    virtual void setCurrentWaypointNumber(int param_1);
    virtual Waypoint* nextWaypoint();
    virtual Waypoint* previousWaypoint();
    virtual Waypoint* firstWaypoint();
    virtual Waypoint* lastWaypoint();
    virtual void initToStart();
    virtual void initToEnd();
    virtual int moveToNextWaypoint();
    virtual int moveToLastWaypoint();
    virtual float distanceToNextWaypoint();
};

static_assert(sizeof(Path) == 0x34, "Path Size Mismatch");
static_assert(offsetof(Path, currentWaypointValue) == 0x30, "Path Offset Mismatch");

