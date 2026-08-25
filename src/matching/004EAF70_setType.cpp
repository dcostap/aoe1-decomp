#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[16];
    int type_;

    void setType(int);
};
#endif
void TacticalAIGroup::setType(int val) { this->type_ = val; }
