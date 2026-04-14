class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[352];
    int commander_;

    int commander() const;
};
int TacticalAIGroup::commander() const { return this->commander_; }
