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
// 10: single result initialized from DAT_00570e40 + nested ifs restored push ecx,
//     shared fld-zero and shared epilogue; 83 equal bytes, first mismatch at branch
//     distances because no push esi/current+next pointer shape.
// 11: raw byte-offset current/next arithmetic improved zero/global and stack slot,
//     but VC5 kept next offset in ecx instead of original saving esi; branch targets
//     stay short by 3 bytes and address/FPU load order differs.
// 12: split off/next statements, register next, and expression-order swaps did not
//     force esi; best kept variant is raw-offset z/y/x expression, 83 equal bytes.
// 13: 2026-05-10 StarryZephyr pass: rechecked current baseline (110/110, first mismatch
//     at branch distance from missing push esi). Tried typed `pw/nw` pointer form with
//     y/x/z expression order; it removed next-offset arithmetic entirely, stayed no-ESI,
//     shortened the body further, and worsened edit diff. Restored raw-offset baseline.
// 14: 2026-05-10 FablePetal pass: tried typed cur/next, `path+i+1`, register pointer,
//     offset pointer, delayed next offset, explicit dx/dy/dz locals, y/x/z and z/y/x
//     expression order, char* path arithmetic, and dummy/register keep variants. None
//     forced the original `push esi; lea esi,[eax+1]; shl esi,4`; VC5 either uses ECX
//     for the next offset or removes the second offset entirely. Flag probes /Ob0,
//     /Oa, /Ow, /Og, /Ot, /Ox, /O2 without /Oy, /Oy-, /O1, and /Od worsened or wrong-sized.
//
// BLOCKER: persistent FPU/codegen-family problem. Behavior and checks are understood.
// Current source matches original prologue style (push ecx), single global-zero result,
// shared exit, and much of the FPU square/sum/fsqrt stack choreography. Remaining drift
// is broad: original pushes esi and computes current/next addresses as ecx/esi before
// popping zero, while isolated VC5 uses ecx only and schedules next-coordinate loads
// differently. Not an accepted_drift suggestion.

#include <math.h>
extern float DAT_00570e40;

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
    float result = DAT_00570e40;
    Waypoint* path = this->pathValue;
    int current;

    if (path != 0) {
        current = this->currentWaypointValue;
        if (current >= 0 && current < this->currentSizeValue - 1) {
            int off = current;
            register int next = current + 1;
            Waypoint* pw;
            off <<= 4;
            pw = (Waypoint*)((char*)path + off);
            next <<= 4;
            result = (float)sqrt((*(float*)((char*)path + next + 8) - pw->z) *
                                 (*(float*)((char*)path + next + 8) - pw->z) +
                                 (*(float*)((char*)path + next + 4) - pw->y) *
                                 (*(float*)((char*)path + next + 4) - pw->y) +
                                 (*(float*)((char*)path + next) - pw->x) *
                                 (*(float*)((char*)path + next) - pw->x));
        }
    }
    return result;
}
