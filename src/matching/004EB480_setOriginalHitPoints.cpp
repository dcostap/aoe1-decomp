#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[356];
    int originalHitPoints_;

    void setOriginalHitPoints(int);
};
#endif
void TacticalAIGroup::setOriginalHitPoints(int val) { this->originalHitPoints_ = val; }
