#include "../include/RGE_Timeline.h"
#include "../include/RGE_Time_Entry.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
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

void RGE_Timeline::update() {
    // Source of truth: timeline.cpp.decomp @ 0x0050D9A0
    RGE_Time_Entry* due_start = nullptr;
    RGE_Time_Entry* entry = this->time_list;
    const float current_time = (float)this->world->world_time * 0.001f;

    while (entry != nullptr) {
        if ((due_start == nullptr) && (this->old_time < entry->time)) {
            due_start = entry;
        }

        if ((entry->this_obj != nullptr) && (entry->this_obj->object_state > 7)) {
            entry->this_obj = nullptr;
        }
        if ((entry->target_obj != nullptr) && (entry->target_obj->object_state > 7)) {
            entry->target_obj = nullptr;
        }

        entry = entry->next;
    }

    while ((due_start != nullptr) && (due_start->time <= current_time)) {
        switch (due_start->command) {
        case 0:
            if ((due_start->this_obj != nullptr) && (due_start->target_obj != nullptr)) {
                void** vtable = *(void***)due_start->this_obj;
                typedef void(__thiscall* TimelineCommand0Fn)(RGE_Static_Object*, RGE_Static_Object*);
                TimelineCommand0Fn command0 = (TimelineCommand0Fn)vtable[42];
                command0(due_start->this_obj, due_start->target_obj);
            }
            break;
        case 1: {
            RGE_Player* player = this->world->players[due_start->player];
            if (player->master_objects[due_start->obj_type] != nullptr) {
                RGE_Static_Object* created =
                    player->make_new_object((long)due_start->obj_type, due_start->x, due_start->y, 0.0f, 0);
                for (RGE_Time_Entry* relink = this->time_list; relink != nullptr; relink = relink->next) {
                    if (due_start->this_obj_id == relink->this_obj_id) {
                        relink->this_obj = created;
                    }
                    if (due_start->this_obj_id == relink->target_obj_id) {
                        relink->target_obj = created;
                    }
                }
            }
            break;
        }
        case 2:
            if (due_start->this_obj != nullptr) {
                void** vtable = *(void***)due_start->this_obj;
                typedef void(__thiscall* TimelineCommand2Fn)(RGE_Static_Object*, int, float, float, float);
                TimelineCommand2Fn command2 = (TimelineCommand2Fn)vtable[39];
                command2(due_start->this_obj, 0, due_start->x, due_start->y, due_start->z);
            }
            break;
        case 4:
            if (due_start->this_obj != nullptr) {
                due_start->this_obj->destroy_obj();
            }
            break;
        default:
            break;
        }

        due_start = due_start->next;
    }

    this->old_time = current_time;
}
