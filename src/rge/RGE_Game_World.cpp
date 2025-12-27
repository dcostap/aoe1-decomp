#include "RGE_Game_World.h"
#include "RGE_Base_Game.h"
#include <string.h>
#include <stdio.h>

RGE_Game_World::RGE_Game_World() {
    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->timer = 0.0f;
    this->old_time = 0;
    this->game_speed = 1.0f;
    this->temp_pause = 0;
    this->game_state = 0;
    this->game_end_condition = 0;
    this->sound_update_index = 0;
    this->sprite_update_index = 0;
    this->map = nullptr;
    this->sound_num = 0;
    this->sounds = nullptr;
    this->sprite_num = 0;
    this->sprites = nullptr;
    this->player_num = 0;
    this->players = nullptr;
    this->master_player_num = 0;
    this->master_players = nullptr;
    this->effects = nullptr;
    this->terrain_num = 0;
    this->terrain_size = 0;
    this->terrains = nullptr;
    this->commands = nullptr;
    this->scenario = nullptr;
    this->color_table_num = 0;
    this->color_tables = nullptr;
    this->next_object_id = 1;
    this->next_reusable_object_id = 1;
    this->scenario_object_id = 0;
    this->scenario_object_flag = 0;
    this->random_seed = 0;
    this->curr_player = 0;
}

RGE_Game_World::~RGE_Game_World() {
    if (this->map) {
        delete this->map;
    }
}

void RGE_Game_World::draw() {
#ifdef _DEBUG
    static int world_draw_count = 0;
    if (world_draw_count % 1000 == 0) {
        printf("RGE_Game_World::draw: count=%d map=%p draw_area=%p\n", world_draw_count, this->map, rge_base_game ? rge_base_game->draw_area : nullptr);
    }
    world_draw_count++;
#endif
    if (this->map) {
        this->map->draw(rge_base_game->draw_area, 0, 0, 800, 600);
    }
}

void RGE_Game_World::update() {
    // Update logic...
}
