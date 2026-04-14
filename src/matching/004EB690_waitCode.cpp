class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[444];
    int waitCode_;

    int waitCode() const;
};
int TacticalAIGroup::waitCode() const { return this->waitCode_; }
