#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_0[0x18CC];
    int PlType[16];
    int Get_player_Type(int index);
};
#endif

int RGE_Scenario::Get_player_Type(int index) {
    if (index < 0 || index >= 16) return 0;
    return this->PlType[index];
}
