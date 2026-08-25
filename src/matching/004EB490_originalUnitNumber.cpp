#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[360];
    int originalUnitNumber_;

    int originalUnitNumber() const;
};
#endif
int TacticalAIGroup::originalUnitNumber() const { return this->originalUnitNumber_; }
