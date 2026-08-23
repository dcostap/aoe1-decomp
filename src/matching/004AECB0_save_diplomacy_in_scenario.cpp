// 004AECB0 TRIBE_Screen_Sed::save_diplomacy_in_scenario (155B)
// scr_sed2.cpp:913-940
// Default flags

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::save_diplomacy_in_scenario(int param_1)
{
    if (param_1 < 0) return;

    for (int i = 0; i < 8; i++) {
        int st = Diplomacy_friend_box[i][0]->get_state();
        if (st == 1) {
            world->scenario->Set_player_attitude(param_1, i, 0);
        } else {
            st = Diplomacy_friend_box[i][1]->get_state();
            if (st == 1) {
                world->scenario->Set_player_attitude(param_1, i, 1);
            } else {
                st = Diplomacy_friend_box[i][2]->get_state();
                if (st == 1) {
                    world->scenario->Set_player_attitude(param_1, i, 3);
                }
            }
        }
    }

    int av = Diplomacy_AlliedVictory[param_1]->get_state();
    world->scenario->SetPlayerAlliedVictory(param_1, av);
}
