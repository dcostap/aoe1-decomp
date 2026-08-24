#include "../../include/Timeline_context.h"

RGE_Timeline::RGE_Timeline(RGE_Game_World* world_arg) {
    this->world = world_arg;
    this->time_list = 0;
    this->list_num = 0;
    this->avail_id = 0;
    this->old_time = -1.0f;
}
