#include "../../include/world_scenario_context.h"

void RGE_Game_World::update_sprites(unsigned long param) {
    if (this->sprite_update_index >= this->sprite_num) {
        this->sprite_update_index = 0;
    }
    if (this->sprites[this->sprite_update_index] != 0) {
        this->sprites[this->sprite_update_index]->update(param);
    }
    this->sprite_update_index++;
}
