#include "../include/RGE_Timeline.h"
#include "../include/RGE_Time_Entry.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/globals.h"
#include <stdlib.h>

RGE_Timeline::RGE_Timeline(RGE_Game_World* param_1) {
    // Source of truth: timeline.cpp.decomp @ 0x0050D7B0
    this->world = param_1;
    this->time_list = nullptr;
    this->list_num = 0;
    this->avail_id = 0;
    this->old_time = -1.0f;
}

RGE_Timeline::~RGE_Timeline() {
    // Source of truth: timeline.cpp.decomp @ 0x0050D7E0
    RGE_Time_Entry* entry = this->time_list;
    while (entry != nullptr) {
        RGE_Time_Entry* next = entry->next;
        free(entry);
        entry = next;
    }

    this->time_list = nullptr;
    this->avail_id = 0;
    this->old_time = -1.0f;
    this->world = nullptr;
    this->list_num = 0;
}

void RGE_Timeline::save(int param_1) {
    // Source of truth: timeline.cpp.decomp @ 0x0050D830
    rge_write(param_1, &this->list_num, 2);
    rge_write(param_1, &this->avail_id, 2);
    rge_write(param_1, &this->old_time, 4);

    RGE_Time_Entry* entry = this->time_list;
    int written = 0;
    while (entry != nullptr && written < this->list_num) {
        short this_player_id = -1;
        if (entry->this_obj != nullptr && entry->this_obj->owner != nullptr) {
            this_player_id = entry->this_obj->owner->id;
        }

        short target_player_id = -1;
        if (entry->target_obj != nullptr && entry->target_obj->owner != nullptr) {
            target_player_id = entry->target_obj->owner->id;
        }

        rge_write(param_1, &entry->time, 4);
        rge_write(param_1, &entry->command, 1);
        rge_write(param_1, &entry->obj_type, 2);
        rge_write(param_1, &entry->player, 1);
        rge_write(param_1, &entry->x, 4);
        rge_write(param_1, &entry->y, 4);
        rge_write(param_1, &entry->z, 4);
        rge_write(param_1, &entry->task, 2);
        rge_write(param_1, &entry->this_obj_id, 2);
        rge_write(param_1, &this_player_id, 2);
        rge_write(param_1, &entry->target_obj_id, 2);
        rge_write(param_1, &target_player_id, 2);

        entry = entry->next;
        written = written + 1;
    }
}
