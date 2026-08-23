#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x8];
    unsigned char victory_conquest;
    void Set_conquest_victory(unsigned char v);
};
#endif

void RGE_Scenario::Set_conquest_victory(unsigned char v) { this->victory_conquest = v; }
