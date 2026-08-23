// VA: 00543850 RGE_Game_World::base_save(int)
// PDB source: World.cpp lines 2108-2152
// attempt 1: natural decompiler-shaped save with exact field offsets and direct/member virtual save surfaces.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::base_save(int file) {
    int i;

    rge_write(file, (void*)0x58EC20, 8);
    rge_write(file, &this->terrain_num, 2);
    rge_write(file, &this->terrain_size, 2);

    if (this->terrain_num > 0 && this->terrain_size > 0) {
        rge_write(file, this->terrains, (int)this->terrain_num << 2);
        for (i = 0; i < this->terrain_num; i++) {
            if (this->terrains[i] != 0) {
                rge_write(file, this->terrains[i], (int)this->terrain_size << 2);
            }
        }
    }

    rge_write(file, &this->color_table_num, 2);
    for (i = 0; i < this->color_table_num; i++) {
        this->color_tables[i]->save(file);
    }

    rge_write(file, &this->sound_num, 2);
    for (i = 0; i < this->sound_num; i++) {
        this->sounds[i]->save(file);
    }

    rge_write(file, &this->sprite_num, 2);
    rge_write(file, this->sprites, (int)this->sprite_num << 2);
    for (i = 0; i < this->sprite_num; i++) {
        if (this->sprites[i] != 0) {
            this->sprites[i]->save(file);
        }
    }

    this->map->save(file);
    this->effects->save(file);

    rge_write(file, &this->master_player_num, 2);
    for (i = 0; i < this->master_player_num; i++) {
        this->master_players[i]->save(file);
    }
}
