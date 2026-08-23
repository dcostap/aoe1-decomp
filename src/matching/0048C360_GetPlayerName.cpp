#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_0[0x0D];
    char player_name[1][256];
    char *GetPlayerName(int index);
};
#endif

char *RGE_Scenario::GetPlayerName(int index) {
    return &this->player_name[index][0];
}
