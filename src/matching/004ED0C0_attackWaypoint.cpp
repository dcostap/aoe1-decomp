#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint {
    char data[16];
};
#endif
#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    char gap_00[0x1D4];
    unsigned char numberAttackWaypoints;
    char gap_1D5[0x03];
    Waypoint waypoints[10];

    Waypoint* attackWaypoint(unsigned char index);
};
#endif
Waypoint* TacticalAIGroup::attackWaypoint(unsigned char index) {
#ifdef TAITACMD_SHARED_CONTEXT
    if (index < this->numberAttackWaypointsValue)
#else
    if (index < this->numberAttackWaypoints)
#endif
 #ifdef TAITACMD_SHARED_CONTEXT
        return this->attackWaypoints + index;
 #else
        return this->waypoints + index;
 #endif
    return 0;
}
