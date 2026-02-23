#pragma once
#include "common.h"
#include "Waypoint.h"

struct Path {
    Path();
    Path(int capacity);
    ~Path();

    Path& operator=(const Path& other);

    int insertAtCurrent(const Waypoint& wp);
    int insertAtEnd(Waypoint wp);
    void killPath();
    int numberOfWaypoints() const;
    void setTimeStamp(ulong ts);
    Waypoint* waypoint(int index) const;
    Waypoint* currentWaypoint() const;
    int currentWaypointNumber() const;
    void setCurrentWaypointNumber(int index);
    void initToStart();
    int moveToNextWaypoint();

    ulong timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
};
static_assert(sizeof(Path) == 0x34, "Size mismatch");
