#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[464];
    unsigned char numberAttackWaypoints_;

    unsigned char numberAttackWaypoints() const;
};
#endif
unsigned char TacticalAIGroup::numberAttackWaypoints() const { return this->numberAttackWaypoints_; }
