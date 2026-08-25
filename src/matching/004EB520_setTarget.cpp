#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[384];
    int target_;

    void setTarget(int);
};
#endif
void TacticalAIGroup::setTarget(int val) { this->target_ = val; }
