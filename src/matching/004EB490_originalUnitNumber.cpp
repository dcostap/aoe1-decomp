class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[360];
    int originalUnitNumber_;

    int originalUnitNumber() const;
};
int TacticalAIGroup::originalUnitNumber() const { return this->originalUnitNumber_; }
