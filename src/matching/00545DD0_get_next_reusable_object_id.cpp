// RGE_Game_World::get_next_reusable_object_id - manage reusable object ID counter
#include "../world_phase2_context.h"

long RGE_Game_World::get_next_reusable_object_id() {
    if (this->scenario_object_flag) {
        if (this->scenario_object_id < this->next_reusable_object_id) {
            this->next_reusable_object_id = this->scenario_object_id - 1;
        }
        return this->scenario_object_id;
    }

    return this->next_reusable_object_id--;
}
