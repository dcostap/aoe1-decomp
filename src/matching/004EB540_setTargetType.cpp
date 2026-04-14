class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[388];
    int targetType_;

    void setTargetType(int);
};
void TacticalAIGroup::setTargetType(int val) { this->targetType_ = val; }
