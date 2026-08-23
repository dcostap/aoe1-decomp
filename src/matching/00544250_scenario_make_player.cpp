// 00544250 RGE_Game_World::scenario_make_player (World.cpp:2469-2479)
// Exact owner under the shared World.cpp scenario context. Requires /GX.
#include "../../include/world_scenario_context.h"

void RGE_Game_World::scenario_make_player(short param_1, unsigned char param_2,
    unsigned char param_3, unsigned char param_4, char* param_5) {
    if (param_3 != 0)
        return;

    this->players[param_1] = new RGE_Player(
        this,
        this->master_players[param_4],
        (unsigned char)param_1,
        param_5,
        param_4,
        1
    );
}
