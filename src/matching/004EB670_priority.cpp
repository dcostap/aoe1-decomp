#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[440];
    int priority_;

    int priority() const;
};
#endif
int TacticalAIGroup::priority() const { return this->priority_; }
