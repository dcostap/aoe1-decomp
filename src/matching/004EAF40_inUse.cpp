class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[12];
    int inUse_;

    int inUse() const;
};
int TacticalAIGroup::inUse() const { return this->inUse_; }
