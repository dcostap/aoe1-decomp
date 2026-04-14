class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[380];
    int action_;

    int action() const;
};
int TacticalAIGroup::action() const { return this->action_; }
