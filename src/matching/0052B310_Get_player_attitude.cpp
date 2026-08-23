#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0x47A8];
    int attitude[16][16];

    int Get_player_attitude(int param_1, int param_2);
};
#endif

int T_Scenario::Get_player_attitude(int param_1, int param_2) {
    if (param_1 < 0 || param_1 >= 16)
        return -1;
    if (param_2 < 0 || param_2 >= 16)
        return -1;
    return this->Opponent[param_1].Attitude[param_2];
}
