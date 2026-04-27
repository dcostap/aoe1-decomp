// VA: 0046AFE0
// Path::distanceToNextWaypoint() const
// Source: Path.cpp lines 358-367

// attempt log:
// 1. natural dx/dy/dz temps + sqrt(dx*dx+dy*dy+dz*dz) -> 97% diff (FPU codegen, sub esp vs push ecx)
// 2. local temps + Waypoint* path + early returns -> 87% diff (each exit loads own 0.0, sub esp)
// 3. shared return path with local result variable -> 87% diff (same prolog/epilog issue)
// 
// Left in scratch: persistent FPU codegen-family problem. Original has:
//   push ecx (1 temp slot) + fld [global_zero] BEFORE checks
//   then all 3 early exits + main path -> shared pop ecx; ret
// My code: sub esp,8 + each early exit fld zero + returns separately
// The FPU stack management for dx/dy/dz multiply-add chain is also in a different basin.
// Needs variant_lab for FPU expression-shape exploration.

#include <math.h>

struct Waypoint {
    float x;  // +0x00
    float y;  // +0x04
    float z;  // +0x08
    unsigned char facetToNextWaypoint;  // +0x0C
};

class Path {
public:
    unsigned long timeStampValue;       // +0x00
    Waypoint startValue;                // +0x04
    Waypoint goalValue;                 // +0x14
    Waypoint* pathValue;                // +0x24
    int maxSizeValue;                   // +0x28
    int currentSizeValue;               // +0x2C
    int currentWaypointValue;           // +0x30

    float distanceToNextWaypoint() const;
};

float Path::distanceToNextWaypoint() const {
    float result;
    Waypoint* path = this->pathValue;
    if (path == 0) {
        result = 0.0f;
    } else {
        int current = this->currentWaypointValue;
        if (current < 0) {
            result = 0.0f;
        } else if (current >= this->currentSizeValue - 1) {
            result = 0.0f;
        } else {
            float dx = path[current + 1].x - path[current].x;
            float dy = path[current + 1].y - path[current].y;
            float dz = path[current + 1].z - path[current].z;
            result = (float)sqrt(dx * dx + dy * dy + dz * dz);
        }
    }
    return result;
}
