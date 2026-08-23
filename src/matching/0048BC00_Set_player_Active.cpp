#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_0[0x194C];
    int PlActive[16];
    void Set_player_Active(int index, int val);
};
#endif

void RGE_Scenario::Set_player_Active(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->PlActive[index] = val;
}
