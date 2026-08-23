#include "../../include/tscenaro_context.h"

#if 0
struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};

class T_Scenario {
public:
    char gap_0[0x1990];
    Player_Start_Info player_info[16];

    Player_Start_Info* Get_player_Info(int param_1);
};
#endif

Player_Start_Info* T_Scenario::Get_player_Info(int param_1) {
    if (param_1 < 0 || param_1 >= 16)
        return 0;
    return &this->player_info[param_1];
}
