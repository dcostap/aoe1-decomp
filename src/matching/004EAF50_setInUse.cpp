#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[12];
    int inUse_;

    void setInUse(int);
};
#endif
void TacticalAIGroup::setInUse(int val) { this->inUse_ = val; }
