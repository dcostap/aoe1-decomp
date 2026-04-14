class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[444];
    int waitCode_;

    void setWaitCode(int);
};
void TacticalAIGroup::setWaitCode(int val) { this->waitCode_ = val; }
