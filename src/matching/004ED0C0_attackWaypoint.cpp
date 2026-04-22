struct AttackWaypoint {
    char data[16];
};

class TacticalAIGroup {
public:
    char gap_00[0x1D4];
    unsigned char numberAttackWaypoints;
    char gap_1D5[0x03];
    AttackWaypoint waypoints[10];

    AttackWaypoint* attackWaypoint(unsigned char index);
};

AttackWaypoint* TacticalAIGroup::attackWaypoint(unsigned char index) {
    if (index < this->numberAttackWaypoints)
        return this->waypoints + index;
    return 0;
}
