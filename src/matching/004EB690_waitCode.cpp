#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[444];
    int waitCode_;

    int waitCode() const;
};
#endif
int TacticalAIGroup::waitCode() const { return this->waitCode_; }
