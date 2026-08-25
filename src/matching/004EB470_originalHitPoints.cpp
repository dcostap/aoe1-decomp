#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[356];
    int originalHitPoints_;

    int originalHitPoints() const;
};
#endif
int TacticalAIGroup::originalHitPoints() const { return this->originalHitPoints_; }
