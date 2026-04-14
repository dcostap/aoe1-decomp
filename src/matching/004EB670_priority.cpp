class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[440];
    int priority_;

    int priority() const;
};
int TacticalAIGroup::priority() const { return this->priority_; }
