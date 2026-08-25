#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[456];
    unsigned long consecutiveIdleUnitCount_;

    void setConsecutiveIdleUnitCount(unsigned long);
};
#endif
void TacticalAIGroup::setConsecutiveIdleUnitCount(unsigned long val) { this->consecutiveIdleUnitCount_ = val; }
