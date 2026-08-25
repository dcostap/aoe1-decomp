#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[452];
    int assistGroupType_;

    int assistGroupType() const;
};
#endif
int TacticalAIGroup::assistGroupType() const { return this->assistGroupType_; }
