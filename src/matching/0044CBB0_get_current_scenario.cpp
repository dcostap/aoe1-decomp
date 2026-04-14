class RGE_Campaign_Info {
public:
    virtual ~RGE_Campaign_Info();
    char gap_0[0xFC];
    int field_100;
    int get_current_scenario();
};

int RGE_Campaign_Info::get_current_scenario() { return this->field_100; }
