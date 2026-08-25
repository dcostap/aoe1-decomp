#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[388];
    int targetType_;

    int targetType() const;
};
#endif
int TacticalAIGroup::targetType() const { return this->targetType_; }
