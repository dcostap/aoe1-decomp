// VA: 0046AAE0 Path::operator==(const Path& other) const
// Path.cpp lines 99-108
// 122 bytes
// attempted direct compare with named i; close but not exact: remaining mismatch is setup load order.
// Additional tries: direct reversed compare, explicit myPath/otherPath locals, pointer-walk forms, decompiler delta style, other ref/local variants, volatile path local, no-op early pathValue expression, and flags /Oa /Ob0 /Og /Ot /G5 /O1 /Od. No exact; most variants disturb saved-register choice or FPU compare order. Best remains current direct compare: 9 positional bytes / 11 edit bytes, all in pre-loop load ordering while the loop body and epilogues are byte-identical.
// === ACCEPTED_DRIFT ===
// 9 positional bytes, all in pre-loop setup.
// Remaining 113 bytes (loop body + all three epilogues) byte-identical.
// Drift is VC5 swapping register allocation order for this->pathValue vs other.pathValue
// in the pre-loop setup; reversed delta/different edx base but comparison is symmetric
// for equality, so all memory effects and return values are equivalent.

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

    int operator==(const Path& other) const;
};
#endif

int Path::operator==(const Path& other) const {
    int i = 0;
    if (currentSizeValue <= 0) return 1;
    for (; i < currentSizeValue; i++) {
        if (other.pathValue[i].x != pathValue[i].x ||
            other.pathValue[i].y != pathValue[i].y ||
            other.pathValue[i].z != pathValue[i].z ||
            other.pathValue[i].facetToNextWaypoint != pathValue[i].facetToNextWaypoint) {
            return 0;
        }
    }
    return 1;
}
