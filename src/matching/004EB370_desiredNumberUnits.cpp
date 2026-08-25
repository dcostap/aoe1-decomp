#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[348];
    int desiredNumberUnits_;

    int desiredNumberUnits() const;
};
#endif
int TacticalAIGroup::desiredNumberUnits() const { return this->desiredNumberUnits_; }
