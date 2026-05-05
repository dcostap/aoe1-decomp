// 0046AFE0 Path::distanceToNextWaypoint() const
// Source: Path.cpp lines 358-367
// Size: 110 bytes, 46 asm lines
//
// Attempt log:
// 1-4 (previous session): natural dx/dy/dz + sqrt gave 87-97% diff (FPU basin)
// 5: float temp + float result=0.0f + nested ifs -> 85% (sub esp,8 not push ecx)
// 6: early returns + single temp -> 87% (separate fld zero per exit)
// 7: single return, dz*dz+dy*dy+dx*dx expr order -> 80%
// 8: compound condition, single local -> 85%
// 9: early returns, pw local, dz*dz+dy*dy+dx*dx -> 85%
//
// BLOCKER: persistent FPU codegen-family problem. The original uses:
//   - push ecx (1 byte, 4-byte slot) not sub esp,8
//   - fld [global_zero] PUSHED ONCE before all checks, shared by all exits
//   - fstp st0 (pop zero) + FPU expression with specific fxch/faddp pattern
//   - shared pop ecx; ret epilogue
// My code: sub esp,8 for 2 locals, each exit loads 0.0 separately,
// FPU expression (dx*dx+dy*dy+dz*dz) schedules differently despite
// trying multiple expression orders.
//
// Left in scratch — FPU scheduling basin.

#include <math.h>

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    float distanceToNextWaypoint() const;
};

float Path::distanceToNextWaypoint() const {
    int temp;
    Waypoint* path = this->pathValue;
    if (path == 0) {
        return 0.0f;
    }
    int current = this->currentWaypointValue;
    if (current < 0 || current >= this->currentSizeValue - 1) {
        return 0.0f;
    }
    Waypoint* pw = path + current;
    float dx = pw[1].x - pw->x;
    float dy = pw[1].y - pw->y;
    float dz = pw[1].z - pw->z;
    return (float)sqrt(dz*dz + dy*dy + dx*dx);
}
