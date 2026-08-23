#include "../../include/world_scenario_context.h"

void RGE_Game_World::update_sounds(unsigned long value) {
    if (this->sound_update_index >= (int)this->sound_num) {
        this->sound_update_index = 0;
    }
    this->sounds[this->sound_update_index]->update(value);
    this->sound_update_index = this->sound_update_index + 1;
}
