#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_0[0x190C];
    int PlCivilization[16];
    int Get_player_Civ(int index);
};
#endif

int RGE_Scenario::Get_player_Civ(int index) {
    if (index < 0 || index >= 16) return 0;
    return this->PlCivilization[index];
}
