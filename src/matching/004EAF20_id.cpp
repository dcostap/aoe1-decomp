class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[8];
    int id_;

    int id() const;
};
int TacticalAIGroup::id() const { return this->id_; }
