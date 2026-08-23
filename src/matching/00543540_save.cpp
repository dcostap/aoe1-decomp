// 00543540 RGE_Game_World::save
// Attempt log:
// initial source from packet/decompiler.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::save(int file)
{
    color_log('$', '$', 1);
    save_game_version = 7.23f;
    rge_write(file, &this->world_time, 4);
    rge_write(file, &this->old_world_time, 4);
    rge_write(file, &this->world_time_delta, 4);
    rge_write(file, &this->world_time_delta_seconds, 4);
    rge_write(file, &this->timer, 4);
    rge_write(file, &this->game_speed, 4);
    rge_write(file, &this->temp_pause, 1);
    rge_write(file, &this->next_object_id, 4);
    rge_write(file, &this->next_reusable_object_id, 4);
    rge_write(file, &this->random_seed, 4);
    rge_write(file, &this->curr_player, 2);
    rge_write(file, &this->player_num, 2);
    rge_write(file, &this->game_state, 1);
    rge_write(file, &this->campaign, 4);
    rge_write(file, &this->campaign_player, 4);
    rge_write(file, &this->campaign_scenario, 4);
    rge_write(file, &this->player_turn, 4);
    for (int i = 0; i < 9; i++) rge_write(file, &this->player_time_delta[i], 4);
    this->map->save_map(file);
    for (int j = 0; j < this->player_num; j++) {
        color_log('$', 'L', 1);
        this->players[j]->save(file);
        color_log('$', 0x16, 1);
        this->players[j]->save2(file);
    }
    color_log('$', '2', 1);
    for (int k = 0; k < this->player_num; k++) {
        this->players[k]->save_info(file);
    }
    color_log('$', 'E', 1);
    this->scenario->save(file);
    color_log('$', '_', 1);
    if (this->difficultyLevelValue == -1) {
        this->difficultyLevelValue = rge_base_game->difficulty();
    }
    rge_write(file, &this->difficultyLevelValue, 4);
}
