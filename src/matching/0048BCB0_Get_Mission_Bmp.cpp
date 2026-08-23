#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x17A4];
    char Mission_Bmp[1];
    char* Get_Mission_Bmp();
};
#endif

char* RGE_Scenario::Get_Mission_Bmp() { return this->Mission_Bmp; }
