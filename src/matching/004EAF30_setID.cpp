#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[8];
    int id_;

    void setID(int);
};
#endif
void TacticalAIGroup::setID(int val) { this->id_ = val; }
