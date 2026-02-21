#pragma once
#include "common.h"
#include "Waypoint.h"

struct Path {
    Path();
    Path(int capacity);
    ~Path();

    int insertAtEnd(Waypoint wp);
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
