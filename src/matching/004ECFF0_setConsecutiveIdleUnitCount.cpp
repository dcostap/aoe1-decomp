class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[456];
    unsigned long consecutiveIdleUnitCount_;

    void setConsecutiveIdleUnitCount(unsigned long);
};
void TacticalAIGroup::setConsecutiveIdleUnitCount(unsigned long val) { this->consecutiveIdleUnitCount_ = val; }
