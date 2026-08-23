// RGE_Game_World::init_player_type
// VA: 00541770
// World.cpp:718-731
// 138 bytes
// FLAGS: /GX (EH frame for new expression)

#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::init_player_type(int param_1, short param_2, unsigned char param_3) {
    if (param_3 == 0) {
        this->master_players[param_2] = new RGE_Master_Player(param_1);
        this->master_players[param_2]->init(param_1, this->sprites, this->sounds);
    }
    return 1;
}
