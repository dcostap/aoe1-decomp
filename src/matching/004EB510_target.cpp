class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[384];
    int target_;

    int target() const;
};
int TacticalAIGroup::target() const { return this->target_; }
