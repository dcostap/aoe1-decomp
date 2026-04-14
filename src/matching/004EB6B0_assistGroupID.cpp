class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[448];
    int assistGroupID_;

    int assistGroupID() const;
};
int TacticalAIGroup::assistGroupID() const { return this->assistGroupID_; }
