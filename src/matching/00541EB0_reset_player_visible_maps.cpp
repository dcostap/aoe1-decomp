#include "../../include/world_scenario_context.h"

void RGE_Game_World::reset_player_visible_maps(void) {
    int i = 0;

    if (i < this->player_num) {
        do {
            if (this->players[i] != 0) {
                this->players[i]->remake_visible_map();
            }
            i = i + 1;
        } while (i < this->player_num);
    }
}
