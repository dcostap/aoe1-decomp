class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[360];
    int originalUnitNumber_;

    void setOriginalUnitNumber(int);
};
void TacticalAIGroup::setOriginalUnitNumber(int val) { this->originalUnitNumber_ = val; }
