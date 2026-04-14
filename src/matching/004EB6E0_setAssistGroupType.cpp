class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[452];
    int assistGroupType_;

    void setAssistGroupType(int);
};
void TacticalAIGroup::setAssistGroupType(int val) { this->assistGroupType_ = val; }
