class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[8];
    int id_;

    void setID(int);
};
void TacticalAIGroup::setID(int val) { this->id_ = val; }
