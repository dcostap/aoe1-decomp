#include "../include/RGE_Victory_Conditions.h"

#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/RGE_Victory_Entry.h"
#include "../include/RGE_Victory_Point_Entry.h"
#include "../include/globals.h"
#include "../include/mystring.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int vc_ftol(float value) {
    return (int)value;
}

static float vc_player_attr(RGE_Player* player, long attr) {
    if (player == nullptr || player->attributes == nullptr) {
        return 0.0f;
    }
    if (attr < 0 || attr >= player->attribute_num) {
        return 0.0f;
    }
    return player->attributes[attr];
}

static RGE_Static_Object* vc_find_object_in_list(RGE_Object_List* list, long id) {
    if (list == nullptr) {
        return nullptr;
    }
    for (RGE_Object_Node* node = list->list; node != nullptr; node = node->next) {
        if (node->node != nullptr && node->node->id == id) {
            return node->node;
        }
    }
    return nullptr;
}

static RGE_Static_Object* vc_find_object_global(RGE_Game_World* world, long id) {
    if (world == nullptr || world->players == nullptr || id < 0) {
        return nullptr;
    }
    for (int i = 0; i < world->player_num; ++i) {
        RGE_Player* player = world->players[i];
        if (player == nullptr) {
            continue;
        }
        RGE_Static_Object* obj = vc_find_object_in_list(player->objects, id);
        if (obj != nullptr) {
            return obj;
        }
    }
    return nullptr;
}

static float vc_percent_explored(RGE_Player* player) {
    if (player == nullptr || player->visible == nullptr) {
        return 0.0f;
    }
    if (player->visible->numberTotalTilesValue <= 0) {
        return 0.0f;
    }
    return (float)player->visible->numberTilesExploredValue / (float)player->visible->numberTotalTilesValue;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531750
RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Player* param_1) {
    this->victory_list = nullptr;
    this->list_num = 0;
    this->player = param_1;
    this->victory = 0;
    this->victory_point_list = nullptr;
    this->point_list_num = 0;
    this->tot_victory_points = 0;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531AF0
RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4) {
    float save_version = 0.0f;
    this->victory_list = nullptr;
    this->list_num = 0;
    this->player = param_1;
    this->victory = 0;
    this->victory_point_list = nullptr;
    this->point_list_num = 0;
    this->tot_victory_points = 0;

    if (param_4 == '\x01') {
        rge_read(param_2, &save_version, 4);
    }

    rge_read(param_2, &this->list_num, 4);
    rge_read(param_2, &this->victory, 1);

    RGE_Victory_Entry** tail = &this->victory_list;
    for (long i = 0; i < this->list_num; ++i) {
        RGE_Victory_Entry* entry = (RGE_Victory_Entry*)calloc(1, sizeof(RGE_Victory_Entry));
        if (entry == nullptr) {
            continue;
        }

        float target_player_index = 0.0f;
        long this_obj_id = -1;
        long target_obj_id = -1;

        rge_read(param_2, &entry->command, 1);
        rge_read(param_2, &entry->obj_type, 4);
        rge_read(param_2, &target_player_index, 4);
        rge_read(param_2, &entry->x0, 4);
        rge_read(param_2, &entry->y0, 4);
        rge_read(param_2, &entry->x1, 4);
        rge_read(param_2, &entry->y1, 4);
        rge_read(param_2, &entry->number, 4);
        rge_read(param_2, &entry->count, 4);
        rge_read(param_2, &this_obj_id, 4);
        rge_read(param_2, &target_obj_id, 4);
        rge_read(param_2, &entry->victory_group, 1);
        rge_read(param_2, &entry->ally_flag, 1);
        rge_read(param_2, &entry->state, 1);

        entry->target_player = nullptr;
        entry->this_obj = nullptr;
        entry->target_obj = nullptr;
        entry->checked_flag = 0;
        entry->next = nullptr;
        *tail = entry;
        tail = &entry->next;

        if (this_obj_id >= 0) {
            entry->this_obj = vc_find_object_global(this->player != nullptr ? this->player->world : nullptr, this_obj_id);
            if (entry->this_obj == nullptr) {
                entry->state = '\x03';
            }
        }

        if ((int)target_player_index >= 0) {
            int idx = (int)target_player_index;
            if (param_3 != nullptr) {
                idx = (int)param_3[idx];
            }
            if (this->player != nullptr && this->player->world != nullptr &&
                this->player->world->players != nullptr && idx >= 0 && idx < this->player->world->player_num) {
                entry->target_player = this->player->world->players[idx];
            } else {
                entry->state = '\x03';
            }
        }

        if (target_obj_id >= 0) {
            if (this->player != nullptr) {
                entry->target_obj = vc_find_object_in_list(this->player->objects, target_obj_id);
            }
            if (entry->target_obj == nullptr && entry->target_player != nullptr) {
                entry->target_obj = vc_find_object_in_list(entry->target_player->objects, target_obj_id);
            }
            if (entry->target_obj == nullptr) {
                entry->state = '\x03';
            }
        }
    }

    if (save_version < 1.0f) {
        this->tot_victory_points = 0;
    } else {
        int point_count = 0;
        rge_read(param_2, &this->tot_victory_points, 4);
        rge_read(param_2, &point_count, 4);
        for (int i = 0; i < point_count; ++i) {
            RGE_Victory_Point_Entry* point = this->add_point('\0', '\0');
            if (point == nullptr) {
                continue;
            }
            rge_read(param_2, &point->command, 1);
            rge_read(param_2, &point->state, 1);
            rge_read(param_2, &point->attribute, 4);
            rge_read(param_2, &point->amount, 4);
            rge_read(param_2, &point->points, 4);
            rge_read(param_2, &point->curr_points, 4);
            rge_read(param_2, &point->id, 1);
            rge_read(param_2, &point->group, 1);
            rge_read(param_2, &point->curr_attribute_amount, 4);
            if (this->tot_victory_points < 0) {
                point->points = 0;
            }
        }
        if (this->tot_victory_points < 0) {
            this->tot_victory_points = 0;
        }
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531B20
RGE_Victory_Conditions::~RGE_Victory_Conditions() {
    while (this->victory_list != nullptr) {
        this->sub(this->victory_list);
    }
    while (this->victory_point_list != nullptr) {
        this->sub_point(this->victory_point_list);
    }
    this->list_num = 0;
    this->point_list_num = 0;
    this->victory = 0;
    this->player = nullptr;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531B70
void RGE_Victory_Conditions::save(int param_1) {
    float save_version = 1.0f;
    rge_write(param_1, &save_version, 4);
    rge_write(param_1, &this->list_num, 4);
    rge_write(param_1, &this->victory, 1);

    for (RGE_Victory_Entry* entry = this->victory_list; entry != nullptr; entry = entry->next) {
        int target_player = -1;
        long this_obj_id = -1;
        float target_obj_id = -NAN;

        if (entry->target_player != nullptr) {
            target_player = (int)entry->target_player->id;
        }
        if (entry->this_obj != nullptr) {
            this_obj_id = entry->this_obj->id;
        }
        if (entry->target_obj != nullptr) {
            target_obj_id = (float)entry->target_obj->id;
            if (entry->target_obj->owner != nullptr) {
                target_player = (int)entry->target_obj->owner->id;
            }
        }

        rge_write(param_1, &entry->command, 1);
        rge_write(param_1, &entry->obj_type, 4);
        rge_write(param_1, &target_player, 4);
        rge_write(param_1, &entry->x0, 4);
        rge_write(param_1, &entry->y0, 4);
        rge_write(param_1, &entry->x1, 4);
        rge_write(param_1, &entry->y1, 4);
        rge_write(param_1, &entry->number, 4);
        rge_write(param_1, &entry->count, 4);
        rge_write(param_1, &this_obj_id, 4);
        rge_write(param_1, &target_obj_id, 4);
        rge_write(param_1, &entry->victory_group, 1);
        rge_write(param_1, &entry->ally_flag, 1);
        rge_write(param_1, &entry->state, 1);
    }

    rge_write(param_1, &this->tot_victory_points, 4);
    rge_write(param_1, &this->point_list_num, 4);
    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != nullptr; point = point->next) {
        rge_write(param_1, &point->command, 1);
        rge_write(param_1, &point->state, 1);
        rge_write(param_1, &point->attribute, 4);
        rge_write(param_1, &point->amount, 4);
        rge_write(param_1, &point->points, 4);
        rge_write(param_1, &point->curr_points, 4);
        rge_write(param_1, &point->id, 1);
        rge_write(param_1, &point->group, 1);
        rge_write(param_1, &point->curr_attribute_amount, 4);
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532930
RGE_Victory_Entry* RGE_Victory_Conditions::add(uchar param_1, uchar param_2) {
    RGE_Victory_Entry* entry = (RGE_Victory_Entry*)calloc(1, sizeof(RGE_Victory_Entry));
    if (entry != nullptr) {
        entry->state = '\0';
        entry->victory_group = param_1;
        entry->ally_flag = param_2;
        entry->count = 0;
        entry->next = this->victory_list;
        this->victory_list = entry;
        this->list_num = this->list_num + 1;
    }
    return entry;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532C10
void RGE_Victory_Conditions::sub(RGE_Victory_Entry* param_1) {
    RGE_Victory_Entry* entry = this->victory_list;
    RGE_Victory_Entry** prev_next = &this->victory_list;
    while (entry != nullptr) {
        if (entry == param_1) {
            *prev_next = entry->next;
            free(entry);
            this->list_num = this->list_num - 1;
            return;
        }
        prev_next = &entry->next;
        entry = entry->next;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532F50
RGE_Victory_Point_Entry* RGE_Victory_Conditions::add_point(uchar param_1, uchar param_2) {
    RGE_Victory_Point_Entry* point = (RGE_Victory_Point_Entry*)calloc(1, sizeof(RGE_Victory_Point_Entry));
    if (point != nullptr) {
        point->state = '\0';
        point->attribute = -1;
        point->amount = 0;
        point->command = 0xff;
        point->points = 0;
        point->curr_points = 0;
        point->next = this->victory_point_list;
        point->id = param_1;
        point->group = param_2;
        this->victory_point_list = point;
        this->point_list_num = this->point_list_num + 1;
    }
    return point;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532FA0
void RGE_Victory_Conditions::sub_point(RGE_Victory_Point_Entry* param_1) {
    RGE_Victory_Point_Entry* point = this->victory_point_list;
    RGE_Victory_Point_Entry** prev_next = &this->victory_point_list;
    while (point != nullptr) {
        if (point == param_1) {
            *prev_next = point->next;
            free(point);
            this->point_list_num = this->point_list_num - 1;
            return;
        }
        prev_next = &point->next;
        point = point->next;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531DB0
void RGE_Victory_Conditions::check_for_victory() {
    long failed_group_num = 0;
    long curr_victory_group = 0;
    long group_num = 0;

    if (this->victory_list == nullptr) {
        return;
    }

    this->victory = '\0';
    for (RGE_Victory_Entry* entry = this->victory_list; entry != nullptr; entry = entry->next) {
        entry->checked_flag = '\0';
    }

    while (true) {
        RGE_Victory_Entry* start = this->victory_list;
        while (start != nullptr && start->checked_flag != '\0') {
            start = start->next;
        }
        if (start == nullptr) {
            break;
        }

        unsigned char group = start->victory_group;
        curr_victory_group = curr_victory_group + 1;

        int group_count = 0;
        int success_count = 0;
        bool has_void = false;
        for (RGE_Victory_Entry* entry = this->victory_list; entry != nullptr; entry = entry->next) {
            if (entry->victory_group == group) {
                group_count = group_count + 1;
                entry->checked_flag = '\x01';
                if (entry->state == '\x01') {
                    has_void = true;
                } else if (entry->state == '\x02') {
                    success_count = success_count + 1;
                } else if (entry->state == '\x03') {
                    failed_group_num = failed_group_num + 1;
                }
            }
        }

        if (has_void) {
            group_num = group_num + 1;
            continue;
        }
        if (success_count >= 1 && group_count == failed_group_num + success_count) {
            this->victory = '\x02';
        }
    }

    if (curr_victory_group == group_num) {
        this->victory = '\x01';
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531E90
uchar RGE_Victory_Conditions::update() {
    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != nullptr; point = point->next) {
        if (point->state != '\x03' && point->state != '\x01') {
            this->handle_point_condition(point);
        }
    }

    for (RGE_Victory_Entry* entry = this->victory_list; entry != nullptr; entry = entry->next) {
        if (entry->state != '\x03' && entry->state != '\x01') {
            this->handle_condition(entry);
        }
    }

    this->check_for_victory();
    return this->victory;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531EF0
void RGE_Victory_Conditions::update_for_object(RGE_Static_Object* param_1) {
    RGE_Victory_Entry* entry = this->victory_list;
    while (entry != nullptr) {
        RGE_Victory_Entry* next = entry->next;
        if (entry->this_obj == param_1 || entry->target_obj == param_1) {
            this->sub(entry);
        }
        entry = next;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531F30
void RGE_Victory_Conditions::handle_point_condition(RGE_Victory_Point_Entry* param_1) {
    switch (param_1->command) {
    case '\0':
        this->handle_points_attribute_amount(param_1);
        return;
    case '\x01':
        this->handle_points_attribute_first(param_1);
        return;
    case '\x02':
        this->handle_points_highest_attribute(param_1);
        return;
    case '\x03':
        this->handle_points_high_attribute_once(param_1);
        return;
    case '\x04':
        this->handle_points_high_attribute_amount(param_1);
        return;
    default:
        return;
    }
}

// TODO: STUB - decompiler split artifact block at 0x00531F71 is non-parity pseudo-code with undefined register state.
// Source of truth: victory.cpp.decomp @ 0x00531F71
void FUN_00531f71() {}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00531F90
void RGE_Victory_Conditions::handle_condition(RGE_Victory_Entry* param_1) {
    switch (param_1->command) {
    case '\0':
        this->handle_capture(param_1);
        return;
    case '\x01':
        this->handle_create(param_1);
        return;
    case '\x02':
        this->handle_destroy(param_1);
        return;
    case '\x03':
        this->handle_destroy_multiple(param_1);
        return;
    case '\x04':
        this->handle_bring_area(param_1);
        return;
    case '\x05':
        this->handle_bring_object(param_1);
        return;
    case '\x06':
        this->handle_attribute(param_1);
        return;
    case '\a':
        this->handle_explore(param_1);
        return;
    case '\b':
        this->handle_create_in_area(param_1);
        return;
    case '\t':
        this->handle_destroy_all(param_1);
        return;
    case '\n':
        this->handle_destroy_player(param_1);
        return;
    case '\f':
        this->handle_victory_points(param_1);
        return;
    default:
        return;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532050
void RGE_Victory_Conditions::handle_capture(RGE_Victory_Entry* param_1) {
    RGE_Static_Object* obj = param_1->target_obj;
    if (obj == nullptr) {
        return;
    }
    if (obj->object_state < 3) {
        if (param_1->state == '\0') {
            RGE_Player* owner = obj->owner;
            RGE_Player* self = this->player;
            if (owner != nullptr && self != nullptr &&
                (owner == self ||
                 (param_1->ally_flag != '\0' && self->allied_victory != '\0' &&
                  self->relations != nullptr && owner->relations != nullptr &&
                  self->relations[owner->id] == '\0' && owner->relations[self->id] == '\0' &&
                  owner->allied_victory != '\0'))) {
                param_1->state = '\x02';
            }
        } else if (param_1->state == '\x02') {
            if (this->player != nullptr && obj->owner != nullptr &&
                obj->owner != this->player &&
                (param_1->ally_flag == '\0' ||
                 (this->player->relations != nullptr && this->player->relations[obj->owner->id] != '\0'))) {
                param_1->state = '\0';
            }
        }
    } else {
        param_1->target_obj = nullptr;
        if (param_1->state == '\0') {
            param_1->state = '\x01';
        }
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532110
void RGE_Victory_Conditions::handle_create(RGE_Victory_Entry* param_1) {
    if (this->player == nullptr || this->player->objects == nullptr) {
        return;
    }

    int count = 0;
    for (RGE_Object_Node* node = this->player->objects->list; node != nullptr; node = node->next) {
        if (node->node != nullptr && node->node->master_obj != nullptr &&
            (int)node->node->master_obj->copy_id == param_1->obj_type &&
            node->node->object_state == '\x02') {
            count = count + 1;
        }
    }

    if (param_1->ally_flag != '\0' && this->player->allied_victory != '\0' &&
        this->player->world != nullptr && this->player->world->players != nullptr && this->player->relations != nullptr) {
        for (int i = 1; i < this->player->world->player_num; ++i) {
            if (this->player->relations[i] != '\0') {
                continue;
            }
            RGE_Player* other = this->player->world->players[i];
            if (other == nullptr || other->relations == nullptr || other->objects == nullptr) {
                continue;
            }
            if (i == this->player->id || other->relations[this->player->id] != '\0' || other->allied_victory == '\0') {
                continue;
            }
            for (RGE_Object_Node* node = other->objects->list; node != nullptr; node = node->next) {
                if (node->node != nullptr && node->node->master_obj != nullptr &&
                    (int)node->node->master_obj->copy_id == param_1->obj_type &&
                    node->node->object_state == '\x02') {
                    count = count + 1;
                }
            }
        }
    }

    param_1->state = (count < param_1->number) ? '\0' : '\x02';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532220
void RGE_Victory_Conditions::handle_create_in_area(RGE_Victory_Entry* param_1) {
    if (this->player == nullptr || this->player->objects == nullptr) {
        return;
    }

    int count = 0;
    for (RGE_Object_Node* node = this->player->objects->list; node != nullptr; node = node->next) {
        RGE_Static_Object* obj = node->node;
        if (obj != nullptr && obj->master_obj != nullptr &&
            (int)obj->master_obj->copy_id == param_1->obj_type && obj->object_state == '\x02' &&
            param_1->x0 <= obj->world_x && obj->world_x <= param_1->x1 &&
            param_1->y0 <= obj->world_y && obj->world_y <= param_1->y1) {
            count = count + 1;
        }
    }

    if (param_1->ally_flag != '\0' && this->player->allied_victory != '\0' &&
        this->player->world != nullptr && this->player->world->players != nullptr && this->player->relations != nullptr) {
        for (int i = 1; i < this->player->world->player_num; ++i) {
            if (this->player->relations[i] != '\0') {
                continue;
            }
            RGE_Player* other = this->player->world->players[i];
            if (other == nullptr || other->relations == nullptr || other->objects == nullptr) {
                continue;
            }
            if (i == this->player->id || other->relations[this->player->id] != '\0' || other->allied_victory == '\0') {
                continue;
            }
            for (RGE_Object_Node* node = other->objects->list; node != nullptr; node = node->next) {
                RGE_Static_Object* obj = node->node;
                if (obj != nullptr && obj->master_obj != nullptr &&
                    (int)obj->master_obj->copy_id == param_1->obj_type && obj->object_state == '\x02' &&
                    param_1->x0 <= obj->world_x && obj->world_x <= param_1->x1 &&
                    param_1->y0 <= obj->world_y && obj->world_y <= param_1->y1) {
                    count = count + 1;
                }
            }
        }
    }

    param_1->state = (count < param_1->number) ? '\0' : '\x02';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005323B0
void RGE_Victory_Conditions::handle_destroy(RGE_Victory_Entry* param_1) {
    if (param_1->target_obj != nullptr && param_1->target_obj->object_state == '\a') {
        param_1->state = '\x02';
        param_1->target_obj = nullptr;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005323D0
void RGE_Victory_Conditions::handle_destroy_multiple(RGE_Victory_Entry* param_1) {
    if (param_1->state != '\0' || this->player == nullptr) {
        return;
    }

    if (param_1->target_player == nullptr) {
        if (this->player->world == nullptr || this->player->world->players == nullptr || this->player->relations == nullptr) {
            return;
        }
        for (int i = 0; i < this->player->world->player_num; ++i) {
            if (this->player->relations[i] == '\0') {
                continue;
            }
            RGE_Player* other = this->player->world->players[i];
            if (other == nullptr || other->objects == nullptr) {
                continue;
            }
            for (RGE_Object_Node* node = other->objects->list; node != nullptr; node = node->next) {
                if (node->node != nullptr && node->node->master_obj != nullptr &&
                    (int)node->node->master_obj->copy_id == param_1->obj_type &&
                    node->node->object_state == '\a') {
                    param_1->count = param_1->count + 1;
                }
            }
        }
    } else if (param_1->target_player->objects != nullptr) {
        for (RGE_Object_Node* node = param_1->target_player->objects->list; node != nullptr; node = node->next) {
            if (node->node != nullptr && node->node->master_obj != nullptr &&
                (int)node->node->master_obj->copy_id == param_1->obj_type &&
                node->node->object_state == '\a') {
                param_1->count = param_1->count + 1;
            }
        }
    }

    if (param_1->number <= param_1->count) {
        param_1->state = '\x02';
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005324A0
void RGE_Victory_Conditions::handle_destroy_all(RGE_Victory_Entry* param_1) {
    if (this->player == nullptr) {
        return;
    }

    if (param_1->target_player == nullptr) {
        if (this->player->world == nullptr || this->player->world->players == nullptr || this->player->relations == nullptr) {
            return;
        }
        for (int i = 0; i < this->player->world->player_num; ++i) {
            if (this->player->relations[i] == '\0' || i == this->player->id) {
                continue;
            }
            RGE_Player* other = this->player->world->players[i];
            if (other == nullptr || other->objects == nullptr) {
                continue;
            }
            for (RGE_Object_Node* node = other->objects->list; node != nullptr; node = node->next) {
                if (node->node != nullptr && node->node->master_obj != nullptr &&
                    (int)node->node->master_obj->copy_id == param_1->obj_type) {
                    param_1->state = '\0';
                    return;
                }
            }
        }
        param_1->state = '\x02';
        return;
    }

    if (param_1->target_player->objects != nullptr) {
        for (RGE_Object_Node* node = param_1->target_player->objects->list; node != nullptr; node = node->next) {
            if (node->node != nullptr && node->node->master_obj != nullptr &&
                (int)node->node->master_obj->copy_id == param_1->obj_type) {
                param_1->state = '\0';
                return;
            }
        }
    }
    param_1->state = '\x02';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532570
void RGE_Victory_Conditions::handle_destroy_player(RGE_Victory_Entry* param_1) {
    if (param_1->target_player != nullptr) {
        param_1->state = (param_1->target_player->game_status == '\x02') ? '\x02' : '\0';
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005325A0
void RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry* param_1) {
    RGE_Static_Object* obj = param_1->this_obj;
    if (obj == nullptr) {
        param_1->state = '\x03';
        return;
    }
    if (obj->object_state > 2) {
        if (param_1->state == '\0') {
            param_1->state = '\x01';
        }
        param_1->this_obj = nullptr;
        return;
    }
    if (param_1->x0 <= obj->world_x && obj->world_x <= param_1->x1 &&
        param_1->y0 <= obj->world_y && obj->world_y <= param_1->y1) {
        param_1->state = '\x02';
    } else {
        param_1->state = '\0';
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532610
void RGE_Victory_Conditions::handle_bring_object(RGE_Victory_Entry* param_1) {
    RGE_Static_Object* obj = param_1->this_obj;
    RGE_Static_Object* target = param_1->target_obj;
    if (obj == nullptr || target == nullptr) {
        param_1->state = '\x03';
        return;
    }

    if (obj->object_state < 3 && target->object_state < 3) {
        float dx = obj->world_x - target->world_x;
        float dy = obj->world_y - target->world_y;
        if (dx < 0.0f) dx = -dx;
        if (dy < 0.0f) dy = -dy;
        if (obj->master_obj != nullptr && target->master_obj != nullptr &&
            dx <= (target->master_obj->radius_x + obj->master_obj->radius_x + 1.0f) &&
            dy <= (target->master_obj->radius_y + obj->master_obj->radius_y + 1.0f)) {
            param_1->state = '\x02';
        } else {
            param_1->state = '\0';
        }
        return;
    }

    param_1->this_obj = nullptr;
    param_1->target_obj = nullptr;
    if (param_1->state == '\0') {
        param_1->state = '\x01';
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005326F0
void RGE_Victory_Conditions::handle_attribute(RGE_Victory_Entry* param_1) {
    RGE_Player* self = this->player;
    if (self == nullptr) {
        return;
    }

    float total = vc_player_attr(self, param_1->number);
    if (param_1->ally_flag != '\0' && self->allied_victory != '\0' &&
        self->world != nullptr && self->world->players != nullptr && self->relations != nullptr) {
        for (int i = self->world->player_num - 1; i >= 0; --i) {
            if (self->relations[i] != '\0') {
                continue;
            }
            RGE_Player* other = self->world->players[i];
            if (other == nullptr || other->relations == nullptr) {
                continue;
            }
            if (i == self->id || other->relations[self->id] != '\0' || other->allied_victory == '\0') {
                continue;
            }
            total = total + vc_player_attr(other, param_1->number);
        }
    }
    param_1->state = ((float)param_1->count <= total) ? '\x02' : '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005327A0
void RGE_Victory_Conditions::handle_explore(RGE_Victory_Entry* param_1) {
    if (param_1->state != '\0' || this->player == nullptr) {
        return;
    }

    if (param_1->ally_flag == '\0' || this->player->allied_victory == '\0') {
        if ((float)param_1->count <= vc_percent_explored(this->player) * 100.0f) {
            param_1->state = '\x02';
        }
        return;
    }

    if (this->player->world == nullptr || this->player->world->players == nullptr || this->player->relations == nullptr) {
        return;
    }

    for (int i = this->player->world->player_num - 1; i >= 0; --i) {
        RGE_Player* other = this->player->world->players[i];
        if (other == nullptr || other->relations == nullptr) {
            continue;
        }
        if (((this->player->relations[i] == '\0' && other->relations[this->player->id] == '\0' && other->allied_victory != '\0') ||
             (i == this->player->id)) &&
            (float)param_1->count <= vc_percent_explored(other) * 100.0f) {
            param_1->state = '\x02';
            return;
        }
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532880
void RGE_Victory_Conditions::handle_victory_points(RGE_Victory_Entry* param_1) {
    if (this->player == nullptr) {
        return;
    }

    long total = this->tot_victory_points;
    int players = 1;
    if (param_1->ally_flag != '\0' && this->player->allied_victory != '\0' &&
        this->player->world != nullptr && this->player->world->players != nullptr && this->player->relations != nullptr) {
        for (int i = this->player->world->player_num - 1; i >= 0; --i) {
            if (this->player->relations[i] != '\0') {
                continue;
            }
            RGE_Player* other = this->player->world->players[i];
            if (other == nullptr || other->relations == nullptr) {
                continue;
            }
            if (i == this->player->id || other->relations[this->player->id] != '\0' || other->allied_victory == '\0') {
                continue;
            }
            if (other->victory_conditions != nullptr) {
                total = total + other->victory_conditions->get_victory_points();
                players = players + 1;
            }
        }
    }

    if (players > 0 && param_1->count <= total / players) {
        param_1->state = '\x02';
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532970
uchar RGE_Victory_Conditions::add_capture(uchar param_1, RGE_Static_Object* param_2, uchar param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, param_3);
    if (entry != nullptr && param_2 != nullptr) {
        entry->command = '\0';
        entry->target_obj = param_2;
        entry->target_player = param_2->owner;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005329A0
uchar RGE_Victory_Conditions::add_create(uchar param_1, long param_2, long param_3, uchar param_4) {
    RGE_Victory_Entry* entry = this->add(param_1, param_4);
    if (entry != nullptr) {
        entry->command = '\x01';
        entry->obj_type = param_2;
        entry->number = param_3;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005329D0
uchar RGE_Victory_Conditions::add_create(uchar param_1, long param_2, long param_3, float param_4, float param_5, float param_6, float param_7, uchar param_8) {
    RGE_Victory_Entry* entry = this->add(param_1, param_8);
    if (entry != nullptr) {
        entry->obj_type = param_2;
        entry->number = param_3;
        entry->x0 = param_4;
        entry->y0 = param_5;
        entry->command = '\b';
        entry->x1 = param_6;
        entry->y1 = param_7;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532A20
uchar RGE_Victory_Conditions::add_destroy(uchar param_1, RGE_Static_Object* param_2) {
    RGE_Victory_Entry* entry = this->add(param_1, '\0');
    if (entry != nullptr && param_2 != nullptr) {
        entry->command = '\x02';
        entry->target_obj = param_2;
        entry->target_player = param_2->owner;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532A50
uchar RGE_Victory_Conditions::add_destroy(uchar param_1, long param_2, long param_3, RGE_Player* param_4) {
    RGE_Victory_Entry* entry = this->add(param_1, '\0');
    if (entry != nullptr) {
        entry->obj_type = param_2;
        entry->command = '\x03';
        entry->number = param_3;
        entry->target_player = param_4;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532A90
uchar RGE_Victory_Conditions::add_destroy(uchar param_1, long param_2, RGE_Player* param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, '\0');
    if (entry != nullptr) {
        entry->command = '\t';
        entry->obj_type = param_2;
        entry->target_player = param_3;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532AC0
uchar RGE_Victory_Conditions::add_destroy(uchar param_1, RGE_Player* param_2) {
    RGE_Victory_Entry* entry = this->add(param_1, '\0');
    if (entry != nullptr) {
        entry->command = '\n';
        entry->target_player = param_2;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532AF0
uchar RGE_Victory_Conditions::add_bring(uchar param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, '\0');
    if (entry != nullptr && param_2 != nullptr && param_3 != nullptr) {
        entry->command = '\x05';
        entry->this_obj = param_2;
        entry->target_obj = param_3;
        entry->target_player = param_3->owner;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532B30
uchar RGE_Victory_Conditions::add_bring(uchar param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5, float param_6) {
    RGE_Victory_Entry* entry = this->add(param_1, '\0');
    if (entry != nullptr && param_2 != nullptr) {
        entry->this_obj = param_2;
        entry->x0 = param_3;
        entry->y0 = param_4;
        entry->command = '\x04';
        entry->x1 = param_5;
        entry->y1 = param_6;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532B70
uchar RGE_Victory_Conditions::add_attributes(uchar param_1, long param_2, long param_3, uchar param_4) {
    RGE_Victory_Entry* entry = this->add(param_1, param_4);
    if (entry != nullptr) {
        entry->command = '\x06';
        entry->number = param_2;
        entry->count = param_3;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532BA0
uchar RGE_Victory_Conditions::add_explore(uchar param_1, long param_2, uchar param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, param_3);
    if (entry != nullptr) {
        entry->command = '\a';
        if (param_2 < 1) {
            param_2 = 1;
        }
        if (param_2 > 100) {
            param_2 = 100;
        }
        entry->count = param_2;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532BE0
uchar RGE_Victory_Conditions::add_victory_points(uchar param_1, long param_2, uchar param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, param_3);
    if (entry != nullptr) {
        entry->command = '\f';
        entry->count = param_2;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532C50
void RGE_Victory_Conditions::destroy_all() {
    while (this->victory_list != nullptr) {
        this->sub(this->victory_list);
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532C70
uchar RGE_Victory_Conditions::condition_info(long param_1, char** param_2, uchar* param_3) {
    int index = 0;
    for (RGE_Victory_Entry* entry = this->victory_list; entry != nullptr; entry = entry->next) {
        if (index == param_1) {
            if (param_2 != nullptr) {
                *param_2 = this->condition_description(entry);
            }
            if (param_3 != nullptr) {
                *param_3 = entry->command;
            }
            return '\x01';
        }
        index = index + 1;
    }
    if (param_2 != nullptr) {
        *param_2 = nullptr;
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532CC0
char* RGE_Victory_Conditions::condition_description(RGE_Victory_Entry* param_1) {
    // Fully verified. Source of truth: victory.cpp.decomp @ 0x00532CC0
    char* description = nullptr;
    char temp[200];

    temp[0] = '\0';
    temp[1] = '\0';
    temp[2] = '\0';
    temp[3] = '\0';

    switch (param_1->command) {
    case '\0':
        sprintf(temp + 4, "Capture %s", param_1->this_obj->master_obj->name);
        break;
    case '\x01':
        sprintf(temp + 4, "Create %d %s", param_1->number, param_1->target_player->master_objects[param_1->obj_type]->name);
        break;
    case '\x02':
        sprintf(temp + 4, "Destroy %s", param_1->this_obj->master_obj->name);
        break;
    case '\x03':
        sprintf(temp + 4,
                "Destroy %d %s of player %d",
                param_1->number,
                param_1->target_player->master_objects[param_1->obj_type]->name,
                (int)param_1->target_player->id);
        break;
    case '\x04':
        sprintf(temp + 4,
                "Bring %s to area (%f, %f) - (%f, %f)",
                param_1->this_obj->master_obj->name,
                (double)param_1->x0,
                (double)param_1->y0,
                (double)param_1->x1,
                (double)param_1->y1);
        break;
    case '\x05':
        sprintf(temp + 4, "Bring %s to %s", param_1->this_obj->master_obj->name, param_1->target_obj->master_obj->name);
        break;
    case '\x06':
        sprintf(temp + 4, "aqquire %d of attribute %d", param_1->count, param_1->number);
        break;
    case '\a':
        sprintf(temp + 4, "explore %d percent of the map", param_1->count);
        break;
    case '\b':
        sprintf(temp + 4,
                "Create %d %s in area (%f, %f) - (%f, %f)",
                param_1->number,
                param_1->target_player->master_objects[param_1->obj_type]->name,
                (double)param_1->x0,
                (double)param_1->y0,
                (double)param_1->x1,
                (double)param_1->y1);
        break;
    case '\t':
        sprintf(temp + 4,
                "Destroy all %s of player %d",
                param_1->target_player->master_objects[param_1->obj_type]->name,
                (int)param_1->target_player->id);
        break;
    default:
        break;
    }

    getstring(&description, temp + 4);
    return description;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532ED0
RGE_Victory_Entry* RGE_Victory_Conditions::condition_raw_info(long param_1) {
    int index = 0;
    for (RGE_Victory_Entry* entry = this->victory_list; entry != nullptr; entry = entry->next) {
        if (index == param_1) {
            return entry;
        }
        index = index + 1;
    }
    return nullptr;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532EF0
long RGE_Victory_Conditions::condition_number(long param_1) {
    (void)param_1;
    return this->list_num;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532F00
uchar RGE_Victory_Conditions::victory_achieved() {
    return (this->victory == '\x02') ? '\x01' : '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532F10
uchar RGE_Victory_Conditions::remove_condition(long param_1) {
    int index = 0;
    for (RGE_Victory_Entry* entry = this->victory_list; entry != nullptr; entry = entry->next) {
        if (index == param_1) {
            this->sub(entry);
            return '\x01';
        }
        index = index + 1;
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00532FE0
uchar RGE_Victory_Conditions::add_points_attribute_amount(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    RGE_Victory_Point_Entry* point = this->add_point(param_2, param_1);
    if (point != nullptr) {
        point->attribute = param_3;
        point->command = '\0';
        point->amount = param_4;
        point->points = param_5;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533020
uchar RGE_Victory_Conditions::add_points_attribute_first(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    RGE_Victory_Point_Entry* point = this->add_point(param_2, param_1);
    if (point != nullptr) {
        point->attribute = param_3;
        point->command = '\x01';
        point->amount = param_4;
        point->points = param_5;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533060
uchar RGE_Victory_Conditions::add_points_highest_attribute(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    RGE_Victory_Point_Entry* point = this->add_point(param_2, param_1);
    if (point != nullptr) {
        point->attribute = param_3;
        point->command = '\x02';
        point->amount = param_4;
        point->points = param_5;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005330A0
uchar RGE_Victory_Conditions::add_points_high_attribute_once(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    RGE_Victory_Point_Entry* point = this->add_point(param_2, param_1);
    if (point != nullptr) {
        point->attribute = param_3;
        point->command = '\x03';
        point->amount = param_4;
        point->points = param_5;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005330E0
uchar RGE_Victory_Conditions::add_points_high_attribute_amount(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    RGE_Victory_Point_Entry* point = this->add_point(param_2, param_1);
    if (point != nullptr) {
        point->attribute = param_3;
        point->command = '\x04';
        point->amount = param_4;
        point->points = param_5;
        return '\x01';
    }
    return '\0';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533120
void RGE_Victory_Conditions::handle_points_attribute_amount(RGE_Victory_Point_Entry* param_1) {
    if (param_1->state != '\0') {
        return;
    }
    int amount = vc_ftol(vc_player_attr(this->player, param_1->attribute));
    param_1->curr_attribute_amount = (float)amount;
    int units = 0;
    if (param_1->amount != 0) {
        units = amount / param_1->amount;
    }
    if (units < 0) {
        units = 0;
    }
    int points = param_1->points * units;
    if (points != param_1->curr_points) {
        this->tot_victory_points = this->tot_victory_points + (points - param_1->curr_points);
        param_1->curr_points = points;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533180
void RGE_Victory_Conditions::handle_points_attribute_first(RGE_Victory_Point_Entry* param_1) {
    if (param_1->state != '\0' || this->player == nullptr || this->player->world == nullptr || this->player->world->players == nullptr) {
        return;
    }

    int attr = param_1->attribute;
    int mine = vc_ftol(vc_player_attr(this->player, attr));
    param_1->curr_attribute_amount = (float)mine;
    if (param_1->amount > mine) {
        return;
    }

    for (int i = 0; i < this->player->world->player_num; ++i) {
        if (i == this->player->id) {
            continue;
        }
        RGE_Player* other = this->player->world->players[i];
        if (other != nullptr && (float)param_1->amount <= vc_player_attr(other, attr)) {
            param_1->state = '\x01';
            return;
        }
    }

    this->tot_victory_points = this->tot_victory_points + (param_1->points - param_1->curr_points);
    param_1->curr_points = param_1->points;
    param_1->state = '\x02';
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533240
void RGE_Victory_Conditions::handle_points_highest_attribute(RGE_Victory_Point_Entry* param_1) {
    if (param_1->state != '\0' || this->player == nullptr || this->player->world == nullptr || this->player->world->players == nullptr) {
        return;
    }

    int attr = param_1->attribute;
    int mine_i = vc_ftol(vc_player_attr(this->player, attr));
    float mine = (float)mine_i;
    param_1->curr_attribute_amount = mine;

    int points = 0;
    if (mine_i >= param_1->amount) {
        points = param_1->points;
        for (int i = 1; i < this->player->world->player_num; ++i) {
            if (i == this->player->id) {
                continue;
            }
            RGE_Player* other = this->player->world->players[i];
            if (other == nullptr) {
                continue;
            }
            float other_amount = vc_player_attr(other, attr);
            if (mine < other_amount) {
                points = 0;
                break;
            }
            if (mine == other_amount) {
                points = param_1->curr_points;
            }
        }
    }

    if (points != param_1->curr_points) {
        this->tot_victory_points = this->tot_victory_points + (points - param_1->curr_points);
        param_1->curr_points = points;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533330
void RGE_Victory_Conditions::handle_points_high_attribute_once(RGE_Victory_Point_Entry* param_1) {
    if (param_1->state != '\0' || this->player == nullptr || this->player->world == nullptr || this->player->world->players == nullptr) {
        return;
    }

    int attr = param_1->attribute;
    int mine = vc_ftol(vc_player_attr(this->player, attr));
    if (param_1->curr_attribute_amount < (float)mine) {
        param_1->curr_attribute_amount = (float)mine;
    }

    for (int i = 1; i < this->player->world->player_num; ++i) {
        if (i == this->player->id) {
            continue;
        }
        RGE_Player* other = this->player->world->players[i];
        if (other != nullptr && (float)param_1->amount <= vc_player_attr(other, attr)) {
            param_1->amount = vc_ftol(vc_player_attr(other, attr));
        }
    }

    int points = 0;
    if (param_1->curr_attribute_amount < (float)param_1->amount) {
        points = (mine == param_1->amount) ? param_1->curr_points : 0;
    } else {
        points = param_1->points;
    }

    if (points != param_1->curr_points) {
        this->tot_victory_points = this->tot_victory_points + (points - param_1->curr_points);
        param_1->curr_points = points;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533410
void RGE_Victory_Conditions::handle_points_high_attribute_amount(RGE_Victory_Point_Entry* param_1) {
    if (param_1->state != '\0') {
        return;
    }
    int mine = vc_ftol(vc_player_attr(this->player, param_1->attribute));
    if (param_1->curr_attribute_amount < (float)mine) {
        param_1->curr_attribute_amount = (float)mine;
    }
    int units = 0;
    if (param_1->amount != 0) {
        units = vc_ftol(param_1->curr_attribute_amount) / param_1->amount;
    }
    if (units < 0) {
        units = 0;
    }
    int points = units * param_1->points;
    if (points != param_1->curr_points) {
        this->tot_victory_points = this->tot_victory_points + (points - param_1->curr_points);
        param_1->curr_points = points;
    }
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533480
long RGE_Victory_Conditions::get_victory_points() {
    return this->tot_victory_points;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x00533490
long RGE_Victory_Conditions::get_victory_points_group(uchar param_1) {
    int sum = 0;
    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != nullptr; point = point->next) {
        if (point->group == param_1 || param_1 == 0xff) {
            sum = sum + point->curr_points;
        }
    }
    return sum;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005334C0
long RGE_Victory_Conditions::get_victory_points_id(uchar param_1) {
    long value = 0;
    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != nullptr; point = point->next) {
        if (point->id == param_1) {
            value = point->curr_points;
        }
    }
    return value;
}

// Fully verified. Source of truth: victory.cpp.decomp @ 0x005334E0
long RGE_Victory_Conditions::get_attribute_id(uchar param_1) {
    long value = 0;
    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != nullptr; point = point->next) {
        if (point->id == param_1) {
            value = vc_ftol(point->curr_attribute_amount);
        }
    }
    return value;
}
