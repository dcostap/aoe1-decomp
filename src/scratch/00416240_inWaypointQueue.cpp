// tried the direct float-compare scan with the queue starting at 0x70 and the size at 0xF0; the remaining gap moved around between the entry count test and the loop basin
// kept the FPU compare chain and the natural waypoint scan, but VC5 still prefers a different prolog/loop register shape here
// leaving in scratch as a paused near-match

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
    float* pfVar1;
    int iVar2;

    iVar2 = this->waypointQueueSizeValue;
    if (iVar2 < 1) {
        return 0;
    }
    pfVar1 = &this->waypointQueue[0].y;
    do {
        if (((Waypoint *)(pfVar1 + -1))->x == (float)x) {
            if ((float)y == *pfVar1) {
                return 1;
            }
        }
        iVar2 = iVar2 + -1;
        pfVar1 = pfVar1 + 4;
    } while (iVar2 != 0);
    return 0;
}
