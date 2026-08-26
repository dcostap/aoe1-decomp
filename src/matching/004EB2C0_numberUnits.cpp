#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[344];
    int numberUnits_;

    int numberUnits();
};
#endif
int TacticalAIGroup::numberUnits() { return this->numberUnits_; }
