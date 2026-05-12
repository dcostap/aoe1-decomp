// 0046AFE0 Path::distanceToNextWaypoint() const
// Source: Path.cpp lines 358-367
// Size: 110 bytes, 46 asm lines
// Default flags
//
// MATCHED 2026-05-12
// Key lessons:
// - Using `path[current+1].x/y/z` (array-style) for ALL three coordinate
//   terms forced VC5 to compute next*16 into esi with `push esi; lea esi,[eax+1]`.
// - Inlining all expressions directly in the sqrt() parameter prevented named
//   float locals dx/dy/dz from forcing `sub esp,8`; instead VC5 used `push ecx`.
// - Expression order `dx^2 + dy^2 + dz^2` (natural, left-to-right) produced the
//   correct load order: next.y (via pw[1].y), then next.x (via next*16 offset),
//   then next.z (via pw[1].z).

#include <math.h>

extern float DAT_00570e40;

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

    float distanceToNextWaypoint() const;
};

float Path::distanceToNextWaypoint() const {
    float result = DAT_00570e40;
    Waypoint* path = this->pathValue;

    if (path != 0) {
        int current = this->currentWaypointValue;
        if (current >= 0 && current < this->currentSizeValue - 1) {
            result = sqrt((path[current + 1].x - path[current].x) *
                          (path[current + 1].x - path[current].x) +
                          (path[current + 1].y - path[current].y) *
                          (path[current + 1].y - path[current].y) +
                          (path[current + 1].z - path[current].z) *
                          (path[current + 1].z - path[current].z));
        }
    }
    return result;
}
