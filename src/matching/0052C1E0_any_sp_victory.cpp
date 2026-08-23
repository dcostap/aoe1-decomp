#include "../../include/tscenaro_context.h"

#if 0
class RGE_Scenario {
public:
    int Get_player_Active(int player);
};
#endif

#if 0
class T_Scenario : public RGE_Scenario {
public:
    char gap_0[0x4BF0];
    int which_player;

    void SetSPWhich(int v);
    int GetSPVictoryType(int sp_index);
    int any_sp_victory();
};
#endif

int T_Scenario::any_sp_victory() {
    int player;
    int sp_index;

    for (player = 0; player < 16; player++) {
        if (this->Get_player_Active(player)) {
            this->SetSPWhich(player);
            for (sp_index = 0; sp_index < 12; sp_index++) {
                if (this->GetSPVictoryType(sp_index)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
