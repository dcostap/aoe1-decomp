class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[388];
    int targetType_;

    int targetType() const;
};
int TacticalAIGroup::targetType() const { return this->targetType_; }
