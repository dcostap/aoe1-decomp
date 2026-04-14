class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[440];
    int priority_;

    void setPriority(int);
};
void TacticalAIGroup::setPriority(int val) { this->priority_ = val; }
