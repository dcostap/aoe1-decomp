class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[20];
    int subType_;

    void setSubType(int);
};
void TacticalAIGroup::setSubType(int val) { this->subType_ = val; }
