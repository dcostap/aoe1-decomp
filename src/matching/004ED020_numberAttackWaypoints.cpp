class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[464];
    unsigned char numberAttackWaypoints_;

    unsigned char numberAttackWaypoints() const;
};
unsigned char TacticalAIGroup::numberAttackWaypoints() const { return this->numberAttackWaypoints_; }
