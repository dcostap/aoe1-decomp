// VA: 005426E0
// RGE_Game_World::setup_player_colors()
// Source: World.cpp lines 1224-1250

// attempt 1: natural do-while loop -> 24% diff (SIB encoding + or esi, -1 scheduled late)
// attempt 2: moved 'int color = -1;' above set_color_table call -> EXACT MATCH (109/109, 0.0000%)
// default flags

#include "../../include/world_scenario_context.h"

void RGE_Game_World::setup_player_colors() {
    int color = -1;

    this->players[0]->set_color_table(7);

    unsigned char* used = (unsigned char*)calloc(this->color_table_num, 1);

    for (int p = 1; p < this->player_num; p++) {
        // Compact single-loop: find next unset color whose table type is 1
        do {
            color++;
        } while (used[color] == 1 || this->color_tables[color]->type != 1);

        this->players[p]->set_color_table((unsigned char)color);
        used[color] = 1;
    }

    free(used);
}
