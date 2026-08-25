#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[388];
    int targetType_;

    void setTargetType(int);
};
#endif
void TacticalAIGroup::setTargetType(int val) { this->targetType_ = val; }
