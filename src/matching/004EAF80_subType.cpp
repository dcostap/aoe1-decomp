class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[20];
    int subType_;

    int subType() const;
};
int TacticalAIGroup::subType() const { return this->subType_; }
