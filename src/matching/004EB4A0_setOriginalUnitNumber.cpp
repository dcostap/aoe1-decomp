#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[360];
    int originalUnitNumber_;

    void setOriginalUnitNumber(int);
};
#endif
void TacticalAIGroup::setOriginalUnitNumber(int val) { this->originalUnitNumber_ = val; }
