// VA: 0046ACE0 Path::contains(const Waypoint& wp) const
// Path.cpp lines 158-166
// 182 bytes

#include <math.h>

#ifndef PATH_TU_CONTEXT
struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
};

struct Path {
    int timeStampValue;
    float startValue[3];
    int gap_10;
    float goalValue[3];
    int gap_20;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    int contains(const Waypoint& wp) const;
};
#endif

int Path::contains(const Waypoint& wp) const {
    for (int i = 0; i < currentSizeValue; i++) {
        if (floor(pathValue[i].x) == floor(wp.x) &&
            floor(pathValue[i].y) == floor(wp.y)) {
            return 1;
        }
    }
    return 0;
}
