#ifndef TAITACMD_SHARED_CONTEXT
struct AttackWaypoint {
    char data[16];
};
#endif
#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    char gap_00[0x1D4];
    unsigned char numberAttackWaypoints;
    char gap_1D5[0x03];
    AttackWaypoint waypoints[10];

    AttackWaypoint* attackWaypoint(unsigned char index);
};
#endif
AttackWaypoint* TacticalAIGroup::attackWaypoint(unsigned char index) {
#ifdef TAITACMD_SHARED_CONTEXT
    if (index < this->numberAttackWaypointsValue)
#else
    if (index < this->numberAttackWaypoints)
#endif
        return this->waypoints + index;
    return 0;
}
