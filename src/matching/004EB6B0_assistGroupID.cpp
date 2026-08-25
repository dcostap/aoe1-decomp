#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[448];
    int assistGroupID_;

    int assistGroupID() const;
};
#endif
int TacticalAIGroup::assistGroupID() const { return this->assistGroupID_; }
