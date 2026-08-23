#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x1010];
    char* description;
    char* Get_description();
};
#endif

char* RGE_Scenario::Get_description() { return this->description; }
