// VA: 005433C0 RGE_Game_World::check_game_state
// Source: World.cpp lines 1932-2008
// Attempt log:
// 1: natural reconstruction from packet/decompiler and nearby player/basegame helpers; close frame/prologue but first victory-status dispatch used if-chain instead of original switch-like dec cascade.
// 2: use switch on widened check_victory result.

#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::check_game_state(void)
{
    long local_4 = 0;
    long games_lost = 0;
    long games_on = 0;
    long candidate = 0;
    long candidate_state = 0;

    for (long i = 1; i < this->player_num; ++i) {
        unsigned int state = this->players[i]->check_victory();
        switch (state) {
        case 0:
            ++local_4;
            if (candidate <= 0 || candidate_state == 0) {
                candidate = i;
                candidate_state = 1;
            }
            else if (this->players[i]->allied_victory == 0 ||
                     this->players[candidate]->relation(i) != 0 ||
                     this->players[i]->relation(candidate) != 0) {
                candidate_state = -1;
            }
            break;
        case 1:
            ++games_lost;
            break;
        case 2:
            ++games_on;
            break;
        }
    }

    if (games_lost > 0) {
        this->game_state = 1;
        for (long i = 1; i < this->player_num; ++i) {
            this->players[i]->loss_if_game_on();
        }
    }
    else if (this->scenario->Get_conquest_victory()) {
        if ((games_on > 0 && candidate_state > 0) || local_4 == 0) {
            this->game_state = 1;
            for (long i = 1; i < this->player_num; ++i) {
                this->players[i]->victory_if_game_on();
            }
            this->game_end_condition = 1;
        }
    }

    if (this->game_state == 1 && this->campaign >= 0) {
        if (rge_base_game->set_campaign_info(this->campaign, this->campaign_player, this->campaign_scenario)) {
            if (this->players[this->curr_player]->game_status == 1) {
                rge_base_game->set_campaign_win();
                return this->game_state;
            }
        }
        else {
            this->campaign = -1;
        }
    }

    return this->game_state;
}
