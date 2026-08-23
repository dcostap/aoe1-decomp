// VA: 00540CF0 RGE_Game_World::reset_object_count (51 B)
// PDB source: World.cpp lines 348-362
// Qualified owner: RGE_Game_World::reset_object_count; body boundary: 00540CF0-00540D22.
// Exact-finish: natural member stores and the nine-word reset loop are the reduced exact source.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::reset_object_count() {
    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->world_time_delta_seconds = 0.0f;
    this->timer = 0.0f;
    this->old_time = 0;
    this->temp_pause = 0;
    this->next_object_id = 0;
    this->player_turn = 0;

    for (int i = 0; i < 9; ++i) {
        this->player_time_delta[i] = 0;
    }
}
