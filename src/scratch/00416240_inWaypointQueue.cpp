// tried the direct float-compare scan with the queue starting at 0x70 and the size at 0xF0; the remaining gap moved around between the entry count test and the loop basin
// kept the FPU compare chain and the natural waypoint scan, but VC5 still prefers a different prolog/loop register shape here
// 2026-05-04 retry: switching from a decrementing-count scan to a count local + running index fixed the prologue/FPU surface and improved to 23/80 diff,
// but the remaining drift stays in block layout: `jle 39` vs original `jle 3D`, `jne 0A` vs `jne 0E`, and `jge + jmp` instead of the original bottom `jl` loopback.
// tried/rolled back: explicit loop/found/empty tails, for-loop form, empty-path `return i`, focused 32-variant lab around loop/tail shapes, and flag probes (/O1,/Od,/Og-,/Ob0).
// 2026-05-04 resumed pass: a 72-variant tail-order/return-shape sweep (top exit spelling, bottom exit spelling, label order, plain-vs-zero local returns) all collapsed to the exact same 23/80 basin; VC5 keeps merging the two zero-return tails.
// 2026-05-04 follow-up resumed pass: do/while vs while(1) vs while(i<count), separate zero-expression spellings, and a result-local sweep all collapsed to the same 23/80 basin too.
// best current source is below; latest check_function is 28.7500% positional / 17.5000% edit diff with no custom flags kept.
// leaving in scratch after >10 total attempts because the remaining gap is localized VC5 branch-layout drift, not a behavior mismatch.

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
};

class UnitAIModule {
public:
    char gap_00[0x70];
    Waypoint waypointQueue[8];
    int waypointQueueSizeValue;

    int inWaypointQueue(int x, int y);
};

int UnitAIModule::inWaypointQueue(int x, int y) {
    float* waypoint;
    int i;
    int count;

    count = this->waypointQueueSizeValue;
    i = 0;
    if (count <= 0) {
        goto ret0_empty;
    }
    waypoint = &this->waypointQueue[0].y;

loop:
    if (((Waypoint*)(waypoint - 1))->x == (float)x) {
        if ((float)y == *waypoint) {
            goto ret1;
        }
    }
    i = i + 1;
    waypoint = waypoint + 4;
    if (i < count) {
        goto loop;
    }

ret0_loop:
    return 0;

ret1:
    return 1;

ret0_empty:
    return 0;
}
