#pragma once
#include "common.h"
#include "Waypoint.h"
#include <iosfwd>

struct Path {
    Path();
    Path(int capacity);
    ~Path();

    Path operator+(const Path& other) const;
    Path& operator=(const Path& other);
    int operator==(const Path& other) const;

    int insertAtCurrent(const Waypoint& wp);
    int insertAtEnd(Waypoint wp);
    int contains(const Waypoint& wp) const;
    void killPath();

    int maxNumberOfWaypoints() const;
    int numberOfWaypoints() const;

    ulong timeStamp() const;
    void setTimeStamp(ulong ts);

    float length() const;

    const Waypoint& start() const;
    const Waypoint& goal() const;

    const Waypoint* waypoint(int idx) const;
    Waypoint* currentWaypoint() const;
    int currentWaypointNumber() const;
    void setCurrentWaypointNumber(int idx);

    const Waypoint* nextWaypoint() const;
    const Waypoint* previousWaypoint() const;
    const Waypoint* firstWaypoint() const;
    const Waypoint* lastWaypoint() const;

    void initToStart();
    void initToEnd();
    int moveToNextWaypoint();
    int moveToLastWaypoint();

    float distanceToNextWaypoint() const;

    ulong timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
};
static_assert(sizeof(Path) == 0x34, "Size mismatch");

std::ostream& operator<<(std::ostream& os, const Path& path);
