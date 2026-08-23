#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x16C4];
    char Cine_Loss[1];
    char* Get_Cine_Loss();
};
#endif

char* RGE_Scenario::Get_Cine_Loss() { return this->Cine_Loss; }
