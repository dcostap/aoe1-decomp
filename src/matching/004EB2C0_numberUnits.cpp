class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[344];
    int numberUnits_;

    int numberUnits() const;
};
int TacticalAIGroup::numberUnits() const { return this->numberUnits_; }
