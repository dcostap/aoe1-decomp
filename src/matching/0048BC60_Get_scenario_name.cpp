#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x100C];
    char* scenario_name;
    char* Get_scenario_name();
};
#endif

char* RGE_Scenario::Get_scenario_name() { return this->scenario_name; }
