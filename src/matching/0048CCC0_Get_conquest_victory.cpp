#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x8];
    unsigned char victory_conquest;
    unsigned char Get_conquest_victory();
};
#endif

unsigned char RGE_Scenario::Get_conquest_victory() { return this->victory_conquest; }
