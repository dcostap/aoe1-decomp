class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[16];
    int type_;

    int type() const;
};
int TacticalAIGroup::type() const { return this->type_; }
