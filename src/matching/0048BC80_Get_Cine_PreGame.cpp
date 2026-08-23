#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x1504];
    char Cine_PreGame[1];
    char* Get_Cine_PreGame();
};
#endif

char* RGE_Scenario::Get_Cine_PreGame() { return this->Cine_PreGame; }
