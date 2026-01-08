#pragma once
#include "../common.h"

class Path       {
public:
    ulong timeStampValue;                    // 0x0
    Waypoint startValue;                     // 0x4
    Waypoint goalValue;                      // 0x14
    Waypoint* pathValue;                     // 0x24
    int maxSizeValue;                        // 0x28
    int currentSizeValue;                    // 0x2C
    int currentWaypointValue;                // 0x30

    Path(int param_1);

    // --- Non-Virtual Destructor ---
    ~Path() noexcept(false);
    // --- Non-Virtual Members ---
    Path* operator+(Path* __return_storage_ptr__, Path* param_1);
    Path* operator=(Path* param_1);
    int operator==(Path* param_1);
    int insertAtCurrent(Waypoint* param_1);
    int insertAtEnd(Waypoint param_1);
    int contains(Waypoint* param_1);
    void killPath();
    int maxNumberOfWaypoints();
    int numberOfWaypoints();
    ulong timeStamp();
    void setTimeStamp(ulong param_1);
    float length();
    Waypoint* start();
    Waypoint* goal();
    Waypoint* waypoint(int param_1);
    Waypoint* currentWaypoint();
    int currentWaypointNumber();
    void setCurrentWaypointNumber(int param_1);
    Waypoint* nextWaypoint();
    Waypoint* previousWaypoint();
    Waypoint* firstWaypoint();
    Waypoint* lastWaypoint();
    void initToStart();
    void initToEnd();
    int moveToNextWaypoint();
    int moveToLastWaypoint();
    float distanceToNextWaypoint();
};

static_assert(sizeof(Path) == 0x34, "Path Size Mismatch");
static_assert(offsetof(Path, currentWaypointValue) == 0x30, "Path Offset Mismatch");

