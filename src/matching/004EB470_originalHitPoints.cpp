class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[356];
    int originalHitPoints_;

    int originalHitPoints() const;
};
int TacticalAIGroup::originalHitPoints() const { return this->originalHitPoints_; }
