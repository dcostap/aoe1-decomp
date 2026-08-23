#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x15E4];
    char Cine_Victory[1];
    char* Get_Cine_Victory();
};
#endif

char* RGE_Scenario::Get_Cine_Victory() { return this->Cine_Victory; }
