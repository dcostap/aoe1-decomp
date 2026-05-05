// attempt log:
// first pass: natural segment loop over consecutive waypoints with a running float total
// second pass: remove dx/dy/dz locals and inline the distance expression to chase the VC5 FPU basin
// third pass: swap to waypoint[1] - waypoint[0] spelling and sqrtf to better mirror the packet math
// fourth pass: restore the full Path surface, including currentWaypointValue, in case the TU context affects VC5 register use
// fifth pass: fall back to the smaller Path surface and a fully inlined segment-distance expression
// target shape: sum pairwise distances when currentSizeValue > 1, otherwise return 0.0f
// paused here: remaining mismatch is early prolog/FPU scheduling drift around the zero init and loop body
// 2026 retry: removing <math.h> and declaring sqrtf as extern forced a real call/prolog and regressed badly;
// restored <math.h>/intrinsic sqrtf basin. Remaining mismatch is still x87 expression scheduling in loop.


#include <math.h>

struct Waypoint {
    float x;
    float y;
    float z;
    float pad_0C;
};

class Path {
public:
    char gap_00[0x24];
    Waypoint* pathValue;
    char gap_28[0x04];
    int currentSizeValue;

    float length(void) const;
};

float Path::length(void) const {
    float total = 0.0f;
    if (this->currentSizeValue > 1) {
        Waypoint* waypoint = this->pathValue + 1;
        int remaining = this->currentSizeValue - 1;
        do {
            total += sqrtf((waypoint[0].x - waypoint[-1].x) * (waypoint[0].x - waypoint[-1].x)
                         + (waypoint[0].y - waypoint[-1].y) * (waypoint[0].y - waypoint[-1].y)
                         + (waypoint[0].z - waypoint[-1].z) * (waypoint[0].z - waypoint[-1].z));
            ++waypoint;
        } while (--remaining != 0);
    }
    return total;
}
