class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[456];
    unsigned long consecutiveIdleUnitCount_;

    unsigned long consecutiveIdleUnitCount() const;
};
unsigned long TacticalAIGroup::consecutiveIdleUnitCount() const { return this->consecutiveIdleUnitCount_; }
