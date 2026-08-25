#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[348];
    int desiredNumberUnits_;

    void setDesiredNumberUnits(int);
};
#endif
void TacticalAIGroup::setDesiredNumberUnits(int val) { this->desiredNumberUnits_ = val; }
