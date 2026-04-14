class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[380];
    int action_;

    void setAction(int);
};
void TacticalAIGroup::setAction(int val) { this->action_ = val; }
