#include "../../include/world_scenario_context.h"

void RGE_Game_World::turn_sound_off(void) {
    int i = 0;
    if (0 < this->sound_num) {
        do {
            this->sounds[i]->stop();
            ++i;
        } while (i < this->sound_num);
    }
}
