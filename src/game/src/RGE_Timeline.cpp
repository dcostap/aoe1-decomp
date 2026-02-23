#include "../include/RGE_Timeline.h"
#include "../include/RGE_Time_Entry.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"
#include <stdlib.h>

// Fully verified. Source of truth: timeline.cpp.decomp @ 0x0050D7B0
RGE_Timeline::RGE_Timeline(RGE_Game_World* param_1) {
    this->world = param_1;
    this->time_list = nullptr;
    this->list_num = 0;
    this->avail_id = 0;
    this->old_time = -1.0f;
}

// Source of truth: timeline.cpp.decomp @ 0x0050D5B0
RGE_Timeline::RGE_Timeline(int handle, RGE_Game_World* world) {
    this->world = world;
    this->time_list = nullptr;

    this->list_num = 0;
    this->avail_id = 0;
    this->old_time = -1.0f;

    rge_read(handle, &this->list_num, 2);
    rge_read(handle, &this->avail_id, 2);
    rge_read(handle, &this->old_time, 4);

    RGE_Time_Entry** insert = &this->time_list;
    for (int i = 0; i < this->list_num; ++i) {
        RGE_Time_Entry* entry = (RGE_Time_Entry*)calloc(1, 0x30);
        if (entry == nullptr) {
            break;
        }

        short this_player_id = -1;
        short target_player_id = -1;

        rge_read(handle, &entry->time, 4);
        rge_read(handle, &entry->command, 1);
        rge_read(handle, &entry->obj_type, 2);
        rge_read(handle, &entry->player, 1);
        rge_read(handle, &entry->x, 4);
        rge_read(handle, &entry->y, 4);
        rge_read(handle, &entry->z, 4);
        rge_read(handle, &entry->task, 2);
        rge_read(handle, &entry->this_obj_id, 2);
        rge_read(handle, &this_player_id, 2);
        rge_read(handle, &entry->target_obj_id, 2);
        rge_read(handle, &target_player_id, 2);

        if ((this_player_id < 0) || (this->world == nullptr) || (this->world->players[this_player_id] == nullptr) ||
            (this->world->players[this_player_id]->objects == nullptr)) {
            entry->this_obj = nullptr;
        } else {
            entry->this_obj = this->world->players[this_player_id]->objects->find_by_id(entry->this_obj_id);
        }

        // NOTE: Parity with decomp/ASM: `target_obj` is resolved using `this_player_id` (not `target_player_id`).
        if ((target_player_id < 0) || (this->world == nullptr) || (this->world->players[this_player_id] == nullptr) ||
            (this->world->players[this_player_id]->objects == nullptr)) {
            entry->target_obj = nullptr;
        } else {
            entry->target_obj = this->world->players[this_player_id]->objects->find_by_id(entry->target_obj_id);
        }

        entry->next = nullptr;
        *insert = entry;
        insert = &entry->next;
    }
}

// Fully verified. Source of truth: timeline.cpp.decomp @ 0x0050D7E0
RGE_Timeline::~RGE_Timeline() {
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

// Fully verified. Source of truth: timeline.cpp.decomp @ 0x0050D830
void RGE_Timeline::save(int param_1) {
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

// Fully verified. Source of truth: timeline.cpp.decomp @ 0x0050D9A0
void RGE_Timeline::update() {
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

// Source of truth: timeline.cpp.decomp @ 0x0050DB10
void RGE_Timeline::mock_update(float time) {
    if ((time < this->old_time) && (this->time_list != nullptr)) {
        RGE_Time_Entry* last = this->time_list;
        while (last->next != nullptr) {
            if (this->old_time < last->next->time) {
                break;
            }
            last = last->next;
        }

        while ((last != nullptr) && (time < last->time)) {
            if (last->time <= this->old_time) {
                if (last->command == 1) {
                    RGE_Static_Object* obj = last->this_obj;
                    if (obj != nullptr) {
                        for (RGE_Time_Entry* e = this->time_list; e != nullptr; e = e->next) {
                            if (obj == e->this_obj) e->this_obj = nullptr;
                            if (obj == e->target_obj) e->target_obj = nullptr;
                        }
                        obj->destroy_obj();
                    }
                } else if (last->command == 4) {
                    RGE_Player* player = this->world->players[last->player];
                    if (player != nullptr && player->master_objects[last->obj_type] != nullptr) {
                        RGE_Static_Object* created = player->make_new_object((long)last->obj_type, last->x, last->y, 0.0f, 0);
                        for (RGE_Time_Entry* e = this->time_list; e != nullptr; e = e->next) {
                            if (last->this_obj_id == e->this_obj_id) e->this_obj = created;
                            if (last->this_obj_id == e->target_obj_id) e->target_obj = created;
                        }
                    }
                }
            }

            if (last == this->time_list) {
                last = nullptr;
            } else {
                RGE_Time_Entry* prev = this->time_list;
                while (prev != nullptr) {
                    if (prev->next == last) {
                        last = prev;
                        break;
                    }
                    prev = prev->next;
                }
            }
        }
    }

    if (this->old_time < time) {
        for (RGE_Time_Entry* e = this->time_list; e != nullptr; e = e->next) {
            if ((this->old_time < e->time) && (e->time <= time)) {
                if (e->command == 1) {
                    RGE_Player* player = this->world->players[e->player];
                    if (player != nullptr && player->master_objects[e->obj_type] != nullptr) {
                        RGE_Static_Object* created = player->make_new_object((long)e->obj_type, e->x, e->y, 0.0f, 0);
                        for (RGE_Time_Entry* relink = this->time_list; relink != nullptr; relink = relink->next) {
                            if (e->this_obj_id == relink->this_obj_id) relink->this_obj = created;
                            if (e->this_obj_id == relink->target_obj_id) relink->target_obj = created;
                        }
                    }
                } else if (e->command == 4) {
                    RGE_Static_Object* obj = e->this_obj;
                    if (obj != nullptr) {
                        for (RGE_Time_Entry* relink = this->time_list; relink != nullptr; relink = relink->next) {
                            if (obj == relink->this_obj) relink->this_obj = nullptr;
                            if (obj == relink->target_obj) relink->target_obj = nullptr;
                        }
                        obj->destroy_obj();
                    }
                }
            }
        }
    }

    this->old_time = time;
}

// Source of truth: timeline.cpp.decomp @ 0x0050DD30
short RGE_Timeline::find_id(RGE_Static_Object* obj) {
    for (RGE_Time_Entry* e = this->time_list; e != nullptr; e = e->next) {
        if ((e->command == 1) && (e->this_obj == obj)) {
            return e->this_obj_id;
        }
    }
    return -1;
}

// Source of truth: timeline.cpp.decomp @ 0x0050DD70
RGE_Time_Entry* RGE_Timeline::add(float time) {
    RGE_Time_Entry** insert = &this->time_list;
    RGE_Time_Entry* cur = this->time_list;
    if (cur == nullptr) {
        cur = (RGE_Time_Entry*)calloc(1, 0x30);
        *insert = cur;
        if (cur != nullptr) {
            cur->time = time;
            this->list_num = this->list_num + 1;
        }
        return cur;
    }

    while (cur != nullptr) {
        if (time < cur->time) {
            RGE_Time_Entry* e = (RGE_Time_Entry*)calloc(1, 0x30);
            if (e != nullptr) {
                e->time = time;
                e->next = cur;
                *insert = e;
                this->list_num = this->list_num + 1;
            }
            return e;
        }
        insert = &cur->next;
        cur = cur->next;
    }

    RGE_Time_Entry* e = (RGE_Time_Entry*)calloc(1, 0x30);
    if (e != nullptr) {
        e->time = time;
        e->next = nullptr;
        *insert = e;
        this->list_num = this->list_num + 1;
    }
    return e;
}

// Source of truth: timeline.cpp.decomp @ 0x0050DE00
RGE_Time_Entry* RGE_Timeline::add_attack(float time, RGE_Static_Object* this_obj, RGE_Static_Object* target_obj) {
    RGE_Time_Entry* e = this->add(time);
    if (e != nullptr) {
        e->this_obj = this_obj;
        e->player = (uchar)this_obj->owner->id;
        e->this_obj_id = this->find_id(this_obj);
        e->target_obj = target_obj;
        // NOTE: Parity with decomp/ASM: original passes `this_obj` again for target_obj_id.
        e->target_obj_id = this->find_id(this_obj);
        e->command = 0;
    }
    return e;
}

// Source of truth: timeline.cpp.decomp @ 0x0050DE50
RGE_Time_Entry* RGE_Timeline::add_create(float time, short obj_type, uchar player_id, float x, float y, float z) {
    RGE_Static_Object* created = nullptr;
    RGE_Time_Entry* e = this->add(time);

    RGE_Player* player = this->world->players[player_id];
    if (player != nullptr && player->master_objects[obj_type] != nullptr) {
        created = player->make_new_object((long)obj_type, x, y, 0.0f, 0);
    }

    if (e != nullptr && player != nullptr && player->master_objects[obj_type] != nullptr) {
        e->player = player_id;
        e->obj_type = obj_type;
        e->this_obj = created;
        e->this_obj_id = this->avail_id;
        this->avail_id = this->avail_id + 1;
        e->x = x;
        e->y = y;
        e->z = z;
        e->command = 1;
    }
    return e;
}

// Source of truth: timeline.cpp.decomp @ 0x0050DEF0
RGE_Time_Entry* RGE_Timeline::add_move(float time, RGE_Static_Object* this_obj, float x, float y, float z) {
    RGE_Time_Entry* e = this->add(time);
    if (e != nullptr) {
        e->player = (uchar)this_obj->owner->id;
        e->this_obj = this_obj;
        e->this_obj_id = this->find_id(this_obj);
        e->x = x;
        e->y = y;
        e->z = z;
        e->command = 2;
    }
    return e;
}

// Source of truth: timeline.cpp.decomp @ 0x0050DF40
RGE_Time_Entry* RGE_Timeline::add_delete(float time, RGE_Static_Object* this_obj) {
    if (this_obj == nullptr) {
        return nullptr;
    }

    RGE_Time_Entry* e = this->add(time);
    if (e != nullptr) {
        for (RGE_Time_Entry* cur = this->time_list; cur != nullptr; cur = cur->next) {
            if (this_obj == cur->this_obj) {
                cur->this_obj = nullptr;
                if (cur->command == 1) {
                    e->this_obj_id = cur->this_obj_id;
                }
            }
            if (this_obj == cur->target_obj) {
                cur->target_obj = nullptr;
            }
        }

        e->player = (uchar)this_obj->owner->id;
        e->obj_type = this_obj->master_obj->id;
        e->command = 4;
        e->x = this_obj->world_x;
        e->y = this_obj->world_y;
        this_obj->destroy_obj();
    }
    return e;
}

// Source of truth: timeline.cpp.decomp @ 0x0050DFD0
void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry** pp = &this->time_list;
    RGE_Time_Entry* cur = this->time_list;
    while (cur != nullptr) {
        if (cur == entry) {
            *pp = cur->next;
            free(cur);
            this->list_num = this->list_num - 1;
            return;
        }
        pp = &cur->next;
        cur = cur->next;
    }
}
