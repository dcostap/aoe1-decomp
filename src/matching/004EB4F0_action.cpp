#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[380];
    int action_;

    int action() const;
};
#endif
int TacticalAIGroup::action() const { return this->action_; }
