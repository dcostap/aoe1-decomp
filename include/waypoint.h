#ifndef AOE1_WAYPOINT_H
#define AOE1_WAYPOINT_H

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
};

typedef char waypoint_size_check[(sizeof(Waypoint) == 0x10) ? 1 : -1];

#endif
