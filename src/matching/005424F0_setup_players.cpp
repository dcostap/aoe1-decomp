// RGE_Game_World::setup_players
// VA: 005424F0, World.cpp:1163-1169
// Status: active scratch
// FLAGS: config/flags/005424F0_setup_players.rsp

#include "../../include/world_scenario_context.h"

void RGE_Game_World::setup_players(RGE_Player_Info& info) {
    short index = 1;

    if (player_num > 1) {
        do {
            if (info.type[index - 1] != -1) {
                RGE_Player* player = new RGE_Player(this,
                    master_players[info.tribe[index - 1]],
                    index, info.name[index - 1],
                    info.tribe[index - 1], 1);
                players[index] = player;
            }
            index++;
        } while (index < player_num);
    }
}
