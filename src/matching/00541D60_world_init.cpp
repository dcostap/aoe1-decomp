// 00541D60 RGE_Game_World::world_init
// PDB: World.cpp:858-867, 76 bytes
// FLAGS: default
//
// Fixed: init_40/init_48 take TSound_Driver* (param_2), not TCommunications_Handler*.
// init_54 takes TCommunications_Handler* (param_3), not TSound_Driver*.
// The names init_3c/init_38 are slot numbers, not meaningful identifiers — the
// association between slot and argument type was wrong in the original scratch.
#include "../../include/world_scenario_context.h"

void RGE_Game_World::world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    this->terrain_tables_init(param_1);
    this->color_table_init(param_1);
    this->init_sounds(param_1, param_2);
    this->init_sprites(param_1);
    this->map_init(param_1, param_2);
    this->effects_init(param_1);
    this->master_player_init(param_1);
    this->command_init(param_1, param_3);
}
