#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[16];
    int type_;

    int type() const;
};
#endif
int TacticalAIGroup::type() const { return this->type_; }
