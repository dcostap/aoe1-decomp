class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[12];
    int inUse_;

    void setInUse(int);
};
void TacticalAIGroup::setInUse(int val) { this->inUse_ = val; }
