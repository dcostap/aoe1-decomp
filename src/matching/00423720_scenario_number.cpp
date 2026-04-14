class RGE_Campaign {
public:
    virtual ~RGE_Campaign();
    char gap_0[0x100];
    int field_104;
    int scenario_number();
};

int RGE_Campaign::scenario_number() { return this->field_104; }
