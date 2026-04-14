class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x100C];
    int field_1010;
    int Get_scenario_name();
};

int RGE_Scenario::Get_scenario_name() { return this->field_1010; }
