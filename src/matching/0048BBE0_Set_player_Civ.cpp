#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_0[0x190C];
    int PlCivilization[16];
    void Set_player_Civ(int index, int val);
};
#endif

void RGE_Scenario::Set_player_Civ(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->PlCivilization[index] = val;
}
