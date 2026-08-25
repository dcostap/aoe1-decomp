#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[448];
    int assistGroupID_;

    void setAssistGroupID(int);
};
#endif
void TacticalAIGroup::setAssistGroupID(int val) { this->assistGroupID_ = val; }
