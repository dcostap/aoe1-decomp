#pragma once
#include "common.h"

struct Waypoint {
    float x;
    float y;
    float z;
    uchar facetToNextWaypoint;
};
static_assert(sizeof(Waypoint) == 0x10, "Size mismatch");
