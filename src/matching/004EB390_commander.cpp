#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[352];
    int commander_;

    int commander() const;
};
#endif
int TacticalAIGroup::commander() const { return this->commander_; }
