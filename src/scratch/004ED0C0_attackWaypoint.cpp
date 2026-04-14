struct AttackWaypoint {
    char data[16];
};

struct TacticalAIGroup {
    char gap_0[0x1D4];
    int numberAttackWaypoints;
    AttackWaypoint waypoints[10];
};

AttackWaypoint* __fastcall attackWaypoint(TacticalAIGroup* self, int, int index) {
    if (index < 0)
        return 0;
    if (index >= self->numberAttackWaypoints)
        return 0;
    return &self->waypoints[index];
}
