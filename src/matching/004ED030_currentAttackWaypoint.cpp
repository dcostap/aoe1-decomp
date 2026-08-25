#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[465];
    unsigned char currentAttackWaypoint_;

    unsigned char currentAttackWaypoint() const;
};
#endif
unsigned char TacticalAIGroup::currentAttackWaypoint() const { return this->currentAttackWaypoint_; }
