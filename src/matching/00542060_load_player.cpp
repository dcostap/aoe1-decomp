// 00542060 RGE_Game_World::load_player
// Source: World.cpp lines 1005-1017. 137 bytes. __thiscall, ret 0Ch.
// Has EH registration — needs /GX.
// Retry 2026-05-19: fixed RGE_Player sizeof to 0x220 (explicit vptr + gap), then added a named self=this local and reloaded through self->players[param_3] for the virtual call. This forced VC5 into the original ESI=this / EDI=param_1 / EBX=param_3 register basin and preserved the post-store reload. check_function: MATCH 0.0000%.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::load_player(int param_1, unsigned char param_2, short param_3) {
    RGE_Game_World* self = this;
    if (param_2 != 0)
        return;

    RGE_Player* player = new RGE_Player(param_1, self, param_3);
    self->players[param_3] = player;
    self->players[param_3]->load(param_1);
}
