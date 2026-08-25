#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[12];
    int inUse_;

    int inUse() const;
};
#endif
int TacticalAIGroup::inUse() const { return this->inUse_; }
