#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_0[0x18CC];
    int PlType[16];
    void Set_player_Type(int index, int val);
};
#endif

void RGE_Scenario::Set_player_Type(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->PlType[index] = val;
}
