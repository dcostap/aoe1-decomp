class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[348];
    int desiredNumberUnits_;

    int desiredNumberUnits() const;
};
int TacticalAIGroup::desiredNumberUnits() const { return this->desiredNumberUnits_; }
