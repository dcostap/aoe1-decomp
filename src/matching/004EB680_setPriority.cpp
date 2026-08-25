#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[440];
    int priority_;

    void setPriority(int);
};
#endif
void TacticalAIGroup::setPriority(int val) { this->priority_ = val; }
