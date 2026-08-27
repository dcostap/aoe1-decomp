// Authentic complete owner for C:\\msdev\\work\\age1_x1\\victory.cpp.
// Normal owners stay in PDB source order.
#include "../include/victory.h"
extern "C" void __cdecl free(void* block);


// VA: 00531750 RGE_Victory_Conditions


RGE_Victory_Conditions::RGE_Victory_Conditions(
    RGE_Player* player, int handle, long* version_map, unsigned char version_flag) {
    long index;
    long version;
    float save_version;
    long point_count;
    long* list_num_ptr;
    RGE_Victory_Entry** tail;
    int file_handle = handle;
    long target_object_id;

    if (version_flag == 1) {
        rge_read(file_handle, &save_version, 4);
    } else {
        save_version = 0.0f;
    }

    list_num_ptr = &this->list_num;
    rge_read(file_handle, list_num_ptr, 4);
    rge_read(file_handle, &this->victory, 1);

    tail = &this->victory_list;
    *tail = 0;
    this->player = player;
    index = 0;

    while (index < *list_num_ptr) {
        RGE_Victory_Entry* entry =
            (RGE_Victory_Entry*)calloc(1, sizeof(RGE_Victory_Entry));

        rge_read(file_handle, entry, 1);
        rge_read(file_handle, &entry->obj_type, 4);
        rge_read(file_handle, &version, 4);
        rge_read(file_handle, &entry->x0, 4);
        rge_read(file_handle, &entry->y0, 4);
        rge_read(file_handle, &entry->x1, 4);
        rge_read(file_handle, &entry->y1, 4);
        rge_read(file_handle, &entry->number, 4);
        rge_read(file_handle, &entry->count, 4);
        rge_read(file_handle, &handle, 4);
        rge_read(file_handle, &target_object_id, 4);
        rge_read(file_handle, &entry->victory_group, 1);
        rge_read(file_handle, &entry->ally_flag, 1);
        rge_read(file_handle, &entry->state, 1);

        entry->target_obj = 0;
        entry->this_obj = 0;
        entry->target_player = 0;
        *tail = entry;
        tail = &entry->next;

        if (handle >= 0) {
            int player_index = 0;
            RGE_Game_World* world = this->player->world;
            while (player_index < world->player_num) {
                entry->this_obj =
                    world->players[player_index]->objects->find_by_id(handle);
                if (entry->this_obj != 0) {
                    break;
                }
                player_index++;
                world = this->player->world;
            }
            if (handle >= 0 && entry->this_obj == 0) {
                entry->state = 3;
            }
        }

        if (target_object_id >= 0) {
            entry->target_obj = this->player->objects->find_by_id(target_object_id);
        }

        if (version >= 0) {
            if (version_map != 0) {
                version = version_map[version];
            }
            if (version >= 0) {
                RGE_Player* reference_player =
                    this->player->world->players[version];
                entry->target_player = reference_player;
                if (reference_player != 0 && entry->target_obj == 0 &&
                    target_object_id >= 0) {
                    entry->target_obj =
                        reference_player->objects->find_by_id(target_object_id);
                }
            } else {
                entry->state = 3;
            }
        } else {
            entry->target_player = 0;
        }

        if (target_object_id >= 0 && entry->target_obj == 0) {
            entry->state = 3;
        }

        index++;
    }

    this->victory_point_list = 0;
    this->point_list_num = 0;

    if (save_version >= 1.0) {
        long* total_points = &this->tot_victory_points;
        rge_read(file_handle, total_points, 4);
        rge_read(file_handle, &point_count, 4);

        index = 0;
        while (index < point_count) {
            RGE_Victory_Point_Entry* point = this->add_point(0, 0);
            rge_read(file_handle, point, 1);
            rge_read(file_handle, &point->state, 1);
            rge_read(file_handle, &point->attribute, 4);
            rge_read(file_handle, &point->amount, 4);
            rge_read(file_handle, &point->points, 4);
            rge_read(file_handle, &point->curr_points, 4);
            rge_read(file_handle, &point->id, 1);
            rge_read(file_handle, &point->group, 1);
            rge_read(file_handle, &point->curr_attribute_amount, 4);

            if (*total_points < 0) {
                point->points = 0;
            }
            index++;
        }

        if (*total_points < 0) {
            *total_points = 0;
        }
    } else {
        this->tot_victory_points = 0;
    }
}

// VA: 00531AF0 RGE_Victory_Conditions

RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Player* player) {
    this->player = player;
    this->list_num = 0;
    this->victory_list = 0;
    this->victory_point_list = 0;
    this->victory = 0;
    this->point_list_num = 0;
    this->tot_victory_points = 0;
}

// VA: 00531B20 ~RGE_Victory_Conditions

RGE_Victory_Conditions::~RGE_Victory_Conditions() {
    RGE_Victory_Entry* entry = this->victory_list;
    while (entry != 0) {
        this->sub(entry);
        entry = this->victory_list;
    }

    RGE_Victory_Point_Entry* point = this->victory_point_list;
    while (point != 0) {
        this->sub_point(point);
        point = this->victory_point_list;
    }

    this->list_num = 0;
    this->point_list_num = 0;
    this->victory = 0;
    this->player = 0;
}

// VA: 00531B70 save


void RGE_Victory_Conditions::save(int outfile) {
    long target_obj;
    float version = 1.0f;
    long this_obj;
    int file_handle = outfile;

    rge_write(file_handle, &version, 4);
    rge_write(file_handle, &this->list_num, 4);
    rge_write(file_handle, &this->victory, 1);

    for (RGE_Victory_Entry* entry = this->victory_list; entry != 0; entry = entry->next) {
        if (entry->target_player != 0) {
            outfile = entry->target_player->id;
        } else {
            outfile = -1;
        }

        if (entry->this_obj != 0) {
            this_obj = entry->this_obj->id;
        } else {
            this_obj = -1;
        }

        if (entry->target_obj != 0) {
            target_obj = entry->target_obj->id;
            outfile = entry->target_obj->owner->id;
        } else {
            target_obj = -1;
        }

        rge_write(file_handle, entry, 1);
        rge_write(file_handle, &entry->obj_type, 4);
        rge_write(file_handle, &outfile, 4);
        rge_write(file_handle, &entry->x0, 4);
        rge_write(file_handle, &entry->y0, 4);
        rge_write(file_handle, &entry->x1, 4);
        rge_write(file_handle, &entry->y1, 4);
        rge_write(file_handle, &entry->number, 4);
        rge_write(file_handle, &entry->count, 4);
        rge_write(file_handle, &this_obj, 4);
        rge_write(file_handle, &target_obj, 4);
        rge_write(file_handle, &entry->victory_group, 1);
        rge_write(file_handle, &entry->ally_flag, 1);
        rge_write(file_handle, &entry->state, 1);
    }

    rge_write(file_handle, &this->tot_victory_points, 4);
    rge_write(file_handle, &this->point_list_num, 4);

    for (RGE_Victory_Point_Entry* point = this->victory_point_list; point != 0; point = point->next) {
        rge_write(file_handle, point, 1);
        rge_write(file_handle, &point->state, 1);
        rge_write(file_handle, &point->attribute, 4);
        rge_write(file_handle, &point->amount, 4);
        rge_write(file_handle, &point->points, 4);
        rge_write(file_handle, &point->curr_points, 4);
        rge_write(file_handle, &point->id, 1);
        rge_write(file_handle, &point->group, 1);
        rge_write(file_handle, &point->curr_attribute_amount, 4);
    }
}

// VA: 00531DB0 check_for_victory


void RGE_Victory_Conditions::check_for_victory() {
    RGE_Victory_Entry* entry = this->victory_list;
    long failed_group_num = 0;
    long curr_victory_group = 0;
    long group_num = 0;

    if (entry != 0) {
        this->victory = 0;
        entry = this->victory_list;

        for (; entry != 0; entry = entry->next) {
            entry->checked_flag = 0;
        }

        while (true) {
            RGE_Victory_Entry* group_entry = this->victory_list;
            long target_group;

            while (group_entry != 0) {
                if (group_entry->checked_flag == 0) {
                    target_group = group_entry->victory_group;
                    curr_victory_group++;
                    break;
                }
                group_entry = group_entry->next;
            }

            if (group_entry == 0) break;

            long total_in_group = 0;
            long completed = 0;
            long has_success = 0;

            for (RGE_Victory_Entry* e = group_entry; e != 0; e = e->next) {
                if (e->victory_group == target_group) {
                    total_in_group++;
                    e->checked_flag = 1;

                    switch (e->state) {
                    case 1:
                        has_success = 1;
                        break;
                    case 2:
                        completed++;
                        break;
                    case 3:
                        failed_group_num++;
                        break;
                    }
                }
            }

            if (has_success == 1) {
                group_num++;
                continue;
            }

            if (completed > 0 && total_in_group == failed_group_num + completed) {
                this->victory = 2;
                break;
            }
        }

        if (curr_victory_group == group_num) {
            this->victory = 1;
        }
    }
}

// VA: 00531E90 update

unsigned char RGE_Victory_Conditions::update() {
    {
        for (RGE_Victory_Point_Entry* p = victory_point_list; p != 0; p = p->next) {
            if (p->state != 3 && p->state != 1) {
                this->handle_point_condition(p);
            }
        }
    }
    {
        for (RGE_Victory_Entry* p = victory_list; p != 0; p = p->next) {
            if (p->state != 3 && p->state != 1) {
                this->handle_condition(p);
            }
        }
    }
    check_for_victory();
    return victory;
}

// VA: 00531EF0 update_for_object

void RGE_Victory_Conditions::update_for_object(RGE_Static_Object* object) {
    RGE_Victory_Entry* entry = this->victory_list;

    while (entry != 0) {
        RGE_Victory_Entry* next = entry->next;
        if ((entry->this_obj == object) || (entry->target_obj == object)) {
            this->sub(entry);
        }
        entry = next;
    }
}

// VA: 00531F30 handle_point_condition

void RGE_Victory_Conditions::handle_point_condition(RGE_Victory_Point_Entry* param_1) {
    switch (param_1->command) {
    case 0:
        this->handle_points_attribute_amount(param_1);
        return;
    case 1:
        this->handle_points_attribute_first(param_1);
        return;
    case 2:
        this->handle_points_highest_attribute(param_1);
        return;
    case 3:
        this->handle_points_high_attribute_once(param_1);
        return;
    case 4:
        this->handle_points_high_attribute_amount(param_1);
        return;
    }
}

// VA: 00531F90 handle_condition



void RGE_Victory_Conditions::handle_condition(RGE_Victory_Entry* entry) {
    switch (entry->command) {
    case 0:
        handle_capture(entry);
        return;
    case 1:
        handle_create(entry);
        return;
    case 8:
        handle_create_in_area(entry);
        return;
    case 2:
        handle_destroy(entry);
        return;
    case 3:
        handle_destroy_multiple(entry);
        return;
    case 9:
        handle_destroy_all(entry);
        return;
    case 10:
        handle_destroy_player(entry);
        return;
    case 4:
        handle_bring_area(entry);
        return;
    case 5:
        handle_bring_object(entry);
        return;
    case 6:
        handle_attribute(entry);
        return;
    case 7:
        handle_explore(entry);
        return;
    case 12:
        handle_victory_points(entry);
        return;
    }
}

// VA: 00532050 handle_capture


void RGE_Victory_Conditions::handle_capture(RGE_Victory_Entry* entry) {
    RGE_Static_Object* obj = (RGE_Static_Object*)entry->target_obj;
    if (obj) {
        if (obj->object_state > 2) {
            entry->target_obj = 0;
            if (entry->state == 0) {
                entry->state = 1;
                return;
            }
        } else {
            if (entry->state == 0) {
                RGE_Player* owner = obj->owner;
                RGE_Player* self = this->player;
                if (owner == self ||
                    (entry->ally_flag && self->allied_victory &&
                     self->relations[owner->id] == 0 &&
                     owner->relations[self->id] == 0 && owner->allied_victory)) {
                    entry->state = 2;
                    return;
                }
            } else if (entry->state == 2) {
                RGE_Player* owner = obj->owner;
                RGE_Player* self = this->player;
                if (owner != self && (!entry->ally_flag || self->relations[owner->id] != 0)) {
                    entry->state = 0;
                }
            }
        }
    }
}

// VA: 00532110 handle_create


void RGE_Victory_Conditions::handle_create(RGE_Victory_Entry* entry) {
    RGE_Player* self = this->player;
    int count = 0;
    RGE_Object_Node* node = self->objects->list;

    while (node != 0) {
        if (node->node->master_obj->copy_id == entry->obj_type &&
            node->node->object_state == 2) {
            count++;
        }
        node = node->next;
    }

    if (entry->ally_flag != 0 && self->allied_victory != 0) {
        RGE_Game_World* world = self->world;
        RGE_Player** players = world->players;
        int i = 1;
        int num = world->player_num;

        if (i < num) {
            do {
                if (self->relations[i] == 0 &&
                    players[i]->relations[self->id] == 0 &&
                    i != self->id &&
                    players[i]->allied_victory != 0) {
                    RGE_Object_Node* n = players[i]->objects->list;
                    while (n != 0) {
                        if (n->node->master_obj->copy_id == entry->obj_type &&
                            n->node->object_state == 2) {
                            count++;
                        }
                        n = n->next;
                    }
                }
                i++;
            } while (i < num);
        }
    }

    if (count >= entry->number) {
        entry->state = 2;
    } else {
        entry->state = 0;
    }
}

// VA: 00532220 handle_create_in_area


void RGE_Victory_Conditions::handle_create_in_area(RGE_Victory_Entry* entry) {
    int count = 0;
    RGE_Player* player = this->player;

    RGE_Object_Node* node = player->objects->list;
    while (node != 0) {
        RGE_Static_Object* obj = node->node;
        if (obj->master_obj->copy_id == entry->obj_type &&
            obj->object_state == 2 &&
            obj->world_x >= entry->x0 &&
            obj->world_x <= entry->x1 &&
            obj->world_y >= entry->y0 &&
            obj->world_y <= entry->y1) {
            count++;
        }
        node = node->next;
    }

    if (entry->ally_flag != 0 && player->allied_victory != 0) {
        RGE_Game_World* world = player->world;
        int i = 1;
        RGE_Player** players = world->players;
        int num = world->player_num;
        if (i < num) {
            RGE_Player** current = players + 1;
            do {
                if (player->relations[i] == 0) {
                    RGE_Player* p = *current;
                    if (p->relations[player->id] == 0 &&
                        i != player->id &&
                        p->allied_victory != 0) {
                        node = p->objects->list;
                        while (node != 0) {
                            RGE_Static_Object* obj = node->node;
                            if (obj->master_obj->copy_id == entry->obj_type &&
                                obj->object_state == 2 &&
                                obj->world_x >= entry->x0 &&
                                obj->world_x <= entry->x1 &&
                                obj->world_y >= entry->y0 &&
                                obj->world_y <= entry->y1) {
                                count++;
                            }
                            node = node->next;
                        }
                    }
                }
                ++i;
                ++current;
            } while (i < num);
        }
    }

    if (count >= entry->number) {
        entry->state = 2;
    } else {
        entry->state = 0;
    }
}

// VA: 005323B0 handle_destroy

void RGE_Victory_Conditions::handle_destroy(RGE_Victory_Entry* entry) {
    if (entry->target_obj && entry->target_obj->object_state == 7) {
        entry->state = 2;
        entry->target_obj = 0;
    }
}

// VA: 005323D0 handle_destroy_multiple


void RGE_Victory_Conditions::handle_destroy_multiple(RGE_Victory_Entry* entry) {
    if (entry->state) return;

    if (entry->target_player) {
        RGE_Object_Node* node = entry->target_player->objects->list;
        while (node) {
            if (node->node->master_obj->copy_id == entry->obj_type && node->node->object_state == 7)
                entry->count++;
            node = node->next;
        }
    } else {
        RGE_Player* player = this->player;
        RGE_Player** players = player->world->players;
        int i = 0;
        if (i < player->world->player_num) {
            RGE_Player** current_players = players;
            do {
                if (player->relations[i]) {
                    RGE_Object_Node* node = current_players[0]->objects->list;
                    while (node) {
                        if (node->node->master_obj->copy_id == entry->obj_type &&
                            node->node->object_state == 7)
                            entry->count++;
                        node = node->next;
                    }
                }
                player = this->player;
                i++;
                current_players++;
            } while (i < player->world->player_num);
        }
    }

    if (entry->count >= entry->number) {
        entry->state = 2;
    }
}

// VA: 005324A0 handle_destroy_all



void RGE_Victory_Conditions::handle_destroy_all(RGE_Victory_Entry* entry) {
    if (entry->target_player != 0) {
        RGE_Object_Node* node = entry->target_player->objects->list;
        while (node != 0) {
            if (node->node->master_obj->copy_id == entry->obj_type) {
                entry->state = 0;
                return;
            }
            node = node->next;
        }
        entry->state = 2;
        return;
    }

    RGE_Player* player = this->player;
    int num = player->world->player_num;
    RGE_Player** players = player->world->players;

    for (int i = 0; i < num; i++) {
        if (player->relations[i] == 0 || i == player->id) {
            continue;
        }

        RGE_Object_Node* node = players[i]->objects->list;
        while (node != 0) {
            if (node->node->master_obj->copy_id == entry->obj_type) {
                entry->state = 0;
                return;
            }
            node = node->next;
        }
    }

    entry->state = 2;
}

// VA: 00532570 handle_destroy_player

void RGE_Victory_Conditions::handle_destroy_player(RGE_Victory_Entry* entry) {
    if (entry->target_player) {
        if (entry->target_player->game_status != 2)
            entry->state = 0;
        else
            entry->state = 2;
    }
}

// VA: 005325A0 handle_bring_area


void RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry* entry) {
    RGE_Static_Object* obj = entry->this_obj;

    if (obj) {
        if (obj->object_state >= 3) {
            if (entry->state == 0) {
                entry->state = 1;
            }
            entry->this_obj = 0;
            return;
        }

        if (obj->world_x < entry->x0 || obj->world_x > entry->x1 ||
            obj->world_y < entry->y0 || obj->world_y > entry->y1) {
            entry->state = 0;
        } else {
            entry->state = 2;
        }
        return;
    } else {
        entry->state = 3;
        return;
    }
}

// VA: 00532610 handle_bring_object


void RGE_Victory_Conditions::handle_bring_object(RGE_Victory_Entry* entry) {
    if (entry->this_obj == 0 || entry->target_obj == 0) {
        entry->state = 3;
        return;
    }

    if (entry->this_obj->object_state >= 3 || entry->target_obj->object_state >= 3) {
        entry->this_obj = 0;
        entry->target_obj = 0;
        if (entry->state == 0) {
            entry->state = 1;
        }
        return;
    }

    float dx = entry->this_obj->world_x - entry->target_obj->world_x;
    float dy = entry->this_obj->world_y - entry->target_obj->world_y;

    if (dx < 0.0f) dx = -dx;
    if (dy < 0.0f) dy = -dy;

    float range_x = entry->target_obj->master_obj->radius_x + entry->this_obj->master_obj->radius_x + 1.0f;
    float range_y = entry->target_obj->master_obj->radius_y + entry->this_obj->master_obj->radius_y + 1.0f;

    if (dx <= range_x && dy <= range_y) {
        entry->state = 2;
    } else {
        entry->state = 0;
    }
}

// VA: 005326F0 handle_attribute


void RGE_Victory_Conditions::handle_attribute(RGE_Victory_Entry* entry)
{
    RGE_Player* p = this->player;
    RGE_Victory_Entry* e;
    int attribute_index;
    float total;

    if (p == 0)
        return;

    e = entry;
    attribute_index = e->number;
    total = p->attributes[attribute_index];

    if (e->ally_flag && p->allied_victory) {
        RGE_Game_World* world = p->world;
        int i = world->player_num - 1;
        if (i >= 0) {
            RGE_Player** pp = world->players + i;
            do {
                if (p->relations[i] == 0) {
                    RGE_Player* other = *pp;
                    int my_id = p->id;
                    if (other->relations[my_id] == 0 && i != my_id && other->allied_victory) {
                        total += other->attributes[attribute_index];
                    }
                }
                --i;
                --pp;
            } while (i >= 0);
        }
    }

    if (total >= (float)e->count)
        e->state = 2;
    else
        e->state = 0;
}

// VA: 005327A0 handle_explore


void RGE_Victory_Conditions::handle_explore(RGE_Victory_Entry* entry) {
    RGE_Victory_Conditions* self = this;
    if (entry->state != 0) return;

    if (self->player) {
        if (entry->ally_flag != 0 && self->player->allied_victory != 0) {
            RGE_Game_World* world = self->player->world;
            int num = world->player_num;
            RGE_Player** players = world->players;
            int i = num - 1;
            if (i < 0) return;
            RGE_Player** pp = players + i;
            while (i >= 0) {
                if ((self->player->relations[i] == 0 &&
                     (*pp)->relations[self->player->id] == 0 &&
                     (*pp)->allied_victory != 0) || i == self->player->id) {
                    float explored = (*pp)->visible->percentExplored();
                    if (explored * 100.0f >= (float)entry->count) {
                        entry->state = 2;
                        return;
                    }
                }
                i--;
                pp--;
            }
        } else {
            float explored = self->player->visible->percentExplored();
            if (explored * 100.0f >= (float)entry->count) {
                entry->state = 2;
            }
        }
    }
}

// VA: 00532880 handle_victory_points


void RGE_Victory_Conditions::handle_victory_points(RGE_Victory_Entry* entry) {
    if (this->player != 0) {
        long total = this->tot_victory_points;
        int count = 1;

        if (entry->ally_flag != 0 && this->player->allied_victory != 0) {
            RGE_Game_World* world = this->player->world;
            int i = world->player_num - 1;
            while (i >= 0) {
                if (this->player->relations[i] == 0) {
                    RGE_Player* p = world->players[i];
                    if (p->relations[this->player->id] == 0 &&
                        i != this->player->id && p->allied_victory != 0) {
                        total += p->victory_condition->get_victory_points();
                        count++;
                    }
                }
                i--;
            }
        }

        if (total / count >= entry->count) {
            entry->state = 2;
        }
    }
}

// VA: 00532930 add



RGE_Victory_Entry* RGE_Victory_Conditions::add(unsigned char param_1, unsigned char param_2) {
    RGE_Victory_Entry* entry = (RGE_Victory_Entry*)calloc(1, 0x34);
    if (entry != 0) {
        entry->state = 0;
        entry->victory_group = param_1;
        entry->ally_flag = param_2;
        entry->count = 0;
        entry->next = this->victory_list;
        this->victory_list = entry;
        this->list_num++;
    }
    return entry;
}

// VA: 00532970 add_capture

unsigned char RGE_Victory_Conditions::add_capture(unsigned char param_1, RGE_Static_Object* param_2, unsigned char param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, param_3);
    if (entry) {
        entry->command = 0;
        entry->target_obj = param_2;
        entry->target_player = param_2->owner;
        return 1;
    }
    return 0;
}

// VA: 005329A0 add_create

unsigned char RGE_Victory_Conditions::add_create(unsigned char param_1, long param_2, long param_3, unsigned char param_4) {
    RGE_Victory_Entry* entry = this->add(param_1, param_4);
    if (entry) {
        entry->command = 1;
        entry->obj_type = param_2;
        entry->number = param_3;
        return 1;
    }
    return 0;
}

// VA: 005329D0 add_create

unsigned char RGE_Victory_Conditions::add_create(unsigned char param_1, long param_2, long param_3, float param_4, float param_5, float param_6, float param_7, unsigned char param_8) {
    RGE_Victory_Entry* entry = this->add(param_1, param_8);
    if (entry != 0) {
        entry->obj_type = param_2;
        entry->number = param_3;
        entry->x0 = param_4;
        entry->y0 = param_5;
        entry->command = 8;
        entry->x1 = param_6;
        entry->y1 = param_7;
        return 1;
    }
    return 0;
}

// VA: 00532A20 add_destroy

unsigned char RGE_Victory_Conditions::add_destroy(unsigned char param_1, RGE_Static_Object* param_2) {
    RGE_Victory_Entry* entry = this->add(param_1, 0);
    if (entry) {
        entry->command = 2;
        entry->target_obj = param_2;
        entry->target_player = param_2->owner;
        return 1;
    }
    return 0;
}

// VA: 00532A50 add_destroy

unsigned char RGE_Victory_Conditions::add_destroy(unsigned char param_1, long param_2, long param_3, RGE_Player* param_4) {
    RGE_Victory_Entry* entry = this->add(param_1, 0);
    if (entry) {
        entry->obj_type = param_2;
        entry->command = 3;
        entry->number = param_3;
        entry->target_player = param_4;
        return 1;
    }
    return 0;
}

// VA: 00532A90 add_destroy

unsigned char RGE_Victory_Conditions::add_destroy(unsigned char param_1, long param_2, RGE_Player* param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, 0);
    if (entry) {
        entry->command = 9;
        entry->obj_type = param_2;
        entry->target_player = param_3;
        return 1;
    }
    return 0;
}

// VA: 00532AC0 add_destroy

unsigned char RGE_Victory_Conditions::add_destroy(unsigned char param_1, RGE_Player* param_2) {
    RGE_Victory_Entry* entry = this->add(param_1, 0);
    if (entry) {
        entry->command = 0x0A;
        entry->target_player = param_2;
        return 1;
    }
    return 0;
}

// VA: 00532AF0 add_bring

unsigned char RGE_Victory_Conditions::add_bring(unsigned char param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, 0);
    if (entry) {
        entry->command = 5;
        entry->this_obj = param_2;
        entry->target_obj = param_3;
        entry->target_player = param_3->owner;
        return 1;
    }
    return 0;
}

// VA: 00532B30 add_bring

unsigned char RGE_Victory_Conditions::add_bring(unsigned char param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5, float param_6) {
    RGE_Victory_Entry* entry = this->add(param_1, 0);
    if (entry != 0) {
        entry->command = 4;
        entry->this_obj = param_2;
        entry->x0 = param_3;
        entry->y0 = param_4;
        entry->x1 = param_5;
        entry->y1 = param_6;
        return 1;
    }
    return 0;
}

// VA: 00532B70 add_attributes

unsigned char RGE_Victory_Conditions::add_attributes(unsigned char param_1, long param_2, long param_3, unsigned char param_4) {
    RGE_Victory_Entry* entry = this->add(param_1, param_4);
    if (entry) {
        entry->command = 6;
        entry->number = param_2;
        entry->count = param_3;
        return 1;
    }
    return 0;
}

// VA: 00532BA0 add_explore


unsigned char RGE_Victory_Conditions::add_explore(unsigned char param_1, long param_2, unsigned char param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, param_3);
    if (entry != 0) {
        entry->command = 7;
        if (param_2 < 1) {
            param_2 = 1;
        }
        if (100 < param_2) {
            param_2 = 100;
        }
        entry->count = param_2;
        return 1;
    }
    return 0;
}

// VA: 00532BE0 add_victory_points

unsigned char RGE_Victory_Conditions::add_victory_points(unsigned char param_1, long param_2, unsigned char param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, param_3);
    if (entry) {
        entry->command = 0x0C;
        entry->count = param_2;
        return 1;
    }
    return 0;
}

// VA: 00532C10 sub



void RGE_Victory_Conditions::sub(RGE_Victory_Entry* entry) {
    RGE_Victory_Entry* node = this->victory_list;
    RGE_Victory_Entry** link = &this->victory_list;
    if (node != 0) {
        for (;;) {
            if (node == entry) {
                break;
            }
            link = &node->next;
            node = node->next;
            if (node == 0) {
                return;
            }
        }
        *link = node->next;
        free(node);
        this->list_num--;
    }
}

// VA: 00532C50 destroy_all

void RGE_Victory_Conditions::destroy_all() {
    RGE_Victory_Entry* entry;

    entry = this->victory_list;
    while (entry != 0) {
        sub(entry);
        entry = this->victory_list;
    }
}

// VA: 00532C70 condition_info

unsigned char RGE_Victory_Conditions::condition_info(long index, char** outEntry, unsigned char& outCommand) {
    RGE_Victory_Entry* entry = this->victory_list;
    int i = 0;
    char* text = 0;

    if (entry) {
        while (entry != 0) {
            if (i == index) {
                text = this->condition_description(entry);
                *outEntry = text;
                outCommand = entry->command;
                return 1;
            }
            entry = entry->next;
            i++;
        }
    }
    *outEntry = text;
    return 0;
}

// VA: 00532CC0 condition_description


char* RGE_Victory_Conditions::condition_description(RGE_Victory_Entry* entry) {
    char* description = 0;
    char temp[200];

    switch (entry->command) {
    case 0:
        sprintf(temp, "Capture %s", entry->this_obj->master_obj->name);
        break;
    case 1:
        sprintf(temp, "Create %d %s", entry->number,
            entry->target_player->master_objects[entry->obj_type]->name);
        break;
    case 8:
        sprintf(temp, "Create %d %s in area (%f, %f) - (%f, %f)",
            entry->number,
            entry->target_player->master_objects[entry->obj_type]->name,
            (double)entry->x0, (double)entry->y0,
            (double)entry->x1, (double)entry->y1);
        break;
    case 2:
        sprintf(temp, "Destroy %s", entry->this_obj->master_obj->name);
        break;
    case 3:
        sprintf(temp, "Destroy %d %s of player %d", entry->number,
            entry->target_player->master_objects[entry->obj_type]->name,
            entry->target_player->id);
        break;
    case 9:
        sprintf(temp, "Destroy all %s of player %d",
            entry->target_player->master_objects[entry->obj_type]->name,
            entry->target_player->id);
        break;
    case 4:
        sprintf(temp, "Bring %s to area (%f, %f) - (%f, %f)",
            entry->this_obj->master_obj->name,
            (double)entry->x0, (double)entry->y0,
            (double)entry->x1, (double)entry->y1);
        break;
    case 5:
        sprintf(temp, "Bring %s to %s",
            entry->this_obj->master_obj->name,
            entry->target_obj->master_obj->name);
        break;
    case 6:
        sprintf(temp, "aqquire %d of attribute %d", entry->count,
            entry->number);
        break;
    case 7:
        sprintf(temp, "explore %d percent of the map", entry->count);
        break;
    }

    getstring(&description, temp);
    return description;
}

// VA: 00532ED0 condition_raw_info


RGE_Victory_Entry* RGE_Victory_Conditions::condition_raw_info(long index) {
    RGE_Victory_Entry* entry;
    long wanted;
    long count;

    entry = this->victory_list;
    wanted = index;
    count = 0;
    while (entry != 0) {
        if (count == wanted) {
            return entry;
        }
        entry = entry->next;
        count = count + 1;
    }
    return 0;
}

// VA: 00532EF0 condition_number

long RGE_Victory_Conditions::condition_number(long p0) { return this->list_num; }

// VA: 00532F00 victory_achieved

unsigned char RGE_Victory_Conditions::victory_achieved(void) {
    if (this->victory == 2) {
        return 1;
    }
    return 0;
}

// VA: 00532F10 remove_condition

unsigned char RGE_Victory_Conditions::remove_condition(long index) {
    int i = 0;
    RGE_Victory_Entry* entry = this->victory_list;
    while (entry) {
        if (i == index) {
            this->sub(entry);
            return 1;
        }
        i++;
        entry = entry->next;
    }
    return 0;
}

// VA: 00532F50 add_point


RGE_Victory_Point_Entry* RGE_Victory_Conditions::add_point(unsigned char p1, unsigned char p2) {
    RGE_Victory_Point_Entry* entry = (RGE_Victory_Point_Entry*)calloc(1, 0x1c);
    if (entry != 0) {
        entry->state = 0;
        entry->attribute = -1;
        entry->amount = 0;
        entry->command = 0xff;
        entry->points = 0;
        entry->curr_points = 0;
        entry->next = this->victory_point_list;
        entry->id = p1;
        entry->group = p2;
        this->victory_point_list = entry;
        this->point_list_num++;
    }
    return entry;
}

// VA: 00532FA0 sub_point



void RGE_Victory_Conditions::sub_point(RGE_Victory_Point_Entry* entry) {
    RGE_Victory_Point_Entry* node = this->victory_point_list;
    RGE_Victory_Point_Entry** link = &this->victory_point_list;
    if (node != 0) {
        while (node != entry) {
            link = &node->next;
            node = node->next;
            if (node == 0) {
                return;
            }
        }
        *link = node->next;
        free(node);
        this->point_list_num--;
    }
}

// VA: 00532FE0 add_points_attribute_amount

unsigned char RGE_Victory_Conditions::add_points_attribute_amount(unsigned char p1, unsigned char p2, long attribute, long amount, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(p2, p1);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 0;
        entry->amount = amount;
        entry->points = points;
        return 1;
    }
    return 0;
}

// VA: 00533020 add_points_attribute_first

unsigned char RGE_Victory_Conditions::add_points_attribute_first(unsigned char p1, unsigned char p2, long attribute, long amount, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(p2, p1);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 1;
        entry->amount = amount;
        entry->points = points;
        return 1;
    }
    return 0;
}

// VA: 00533060 add_points_highest_attribute

unsigned char RGE_Victory_Conditions::add_points_highest_attribute(unsigned char p1, unsigned char p2, long attribute, long amount, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(p2, p1);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 2;
        entry->amount = amount;
        entry->points = points;
        return 1;
    }
    return 0;
}

// VA: 005330A0 add_points_high_attribute_once

unsigned char RGE_Victory_Conditions::add_points_high_attribute_once(unsigned char p1, unsigned char p2, long attribute, long amount, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(p2, p1);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 3;
        entry->amount = amount;
        entry->points = points;
        return 1;
    }
    return 0;
}

// VA: 005330E0 add_points_high_attribute_amount

unsigned char RGE_Victory_Conditions::add_points_high_attribute_amount(unsigned char p1, unsigned char p2, long attribute, long amount, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(p2, p1);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 4;
        entry->amount = amount;
        entry->points = points;
        return 1;
    }
    return 0;
}

// VA: 00533120 handle_points_attribute_amount

void RGE_Victory_Conditions::handle_points_attribute_amount(RGE_Victory_Point_Entry* param_1) {
    if (param_1->state == 0) {
        int iVar1 = (int)this->player->attributes[param_1->attribute];
        int iVar2 = iVar1 / param_1->amount;
        param_1->curr_attribute_amount = (float)iVar1;
        if (iVar2 < 0) {
            iVar2 = 0;
        }
        iVar2 = param_1->points * iVar2;
        if (iVar2 != param_1->curr_points) {
            this->tot_victory_points += iVar2 - param_1->curr_points;
            param_1->curr_points = iVar2;
        }
    }
}

// VA: 00533180 handle_points_attribute_first


void RGE_Victory_Conditions::handle_points_attribute_first(RGE_Victory_Point_Entry* entry) {
    RGE_Player* player;
    RGE_Victory_Point_Entry* p;
    if (entry->state == 0) {
        player = this->player;
        p = entry;
        int val = (int)player->attributes[p->attribute];
        int points = p->points;
        RGE_Player** players = player->world->players;
        p->curr_attribute_amount = (float)val;
        if (val < p->amount) return;

        val = 0;
        int count = this->player->world->player_num;
        if (0 < count) {
            do {
                if (val == this->player->id) {
                    val = val + 1;
                    players = players + 1;
                } else if ((float)p->amount > (*players)->attributes[p->attribute]) {
                    val = val + 1;
                    players = players + 1;
                } else {
                    p->state = 1;
                    return;
                }
            } while (val < count);
        }
        this->tot_victory_points += points - p->curr_points;
        p->curr_points = points;
        p->state = 2;
    }
}

// VA: 00533240 handle_points_highest_attribute



void RGE_Victory_Conditions::handle_points_highest_attribute(RGE_Victory_Point_Entry* node) {
    long points;
    long amount;
    int num;
    float current;
    if (node->state == 0) {
        amount = (long)this->player->attributes[node->attribute];
        current = (float)amount;
        points = node->points;
        node->curr_attribute_amount = current;
        RGE_Player* player = this->player;
        RGE_Game_World* world = player->world;
        RGE_Player** players = world->players;
        if (amount < node->amount) {
            points = 0;
        } else {
            num = world->player_num;
            for (int i = 1; i < num; ++i) {
                if (i != player->id) {
                    float* score = &players[i]->attributes[node->attribute];
                    if (*score > current) {
                        points = 0;
                        break;
                    }
                    if (*score == current) {
                        points = node->curr_points;
                    }
                }
            }
        }
        if (points != node->curr_points) {
            this->tot_victory_points += points - node->curr_points;
            node->curr_points = points;
        }
    }
}

// VA: 00533330 handle_points_high_attribute_once


void RGE_Victory_Conditions::handle_points_high_attribute_once(RGE_Victory_Point_Entry* node) {
    if (node->state == 0) {
        long amount = this->player->attributes[node->attribute];
        if (node->curr_attribute_amount < (float)amount) {
            node->curr_attribute_amount = (float)amount;
        }

        int i = 1;
        RGE_Player** players = this->player->world->players;
        if (i < this->player->world->player_num) {
            do {
                if (i != this->player->id && (float)node->amount <= players[i]->attributes[node->attribute]) {
                    node->amount = (long)players[i]->attributes[node->attribute];
                }
                i++;
            } while (i < this->player->world->player_num);
        }

        int result;
        if (node->curr_attribute_amount >= (float)node->amount) {
            result = node->points;
        } else {
            result = (amount == node->amount) ? node->curr_points : 0;
        }

        if (result != node->curr_points) {
            this->tot_victory_points += result - node->curr_points;
            node->curr_points = result;
        }
    }
}

// VA: 00533410 handle_points_high_attribute_amount


void RGE_Victory_Conditions::handle_points_high_attribute_amount(RGE_Victory_Point_Entry* node) {
    if (node->state == 0) {
        long amount = (long)this->player->attributes[node->attribute];
        if (node->curr_attribute_amount < (float)amount) {
            node->curr_attribute_amount = (float)amount;
        }

        amount = (long)(node->curr_attribute_amount / (float)node->amount) * node->points;
        if (amount != node->curr_points) {
            this->tot_victory_points += amount - node->curr_points;
            node->curr_points = amount;
        }
    }
}

// VA: 00533480 get_victory_points

long RGE_Victory_Conditions::get_victory_points() { return this->tot_victory_points; }

// VA: 00533490 get_victory_points_group

long RGE_Victory_Conditions::get_victory_points_group(unsigned char group) {
    int total = 0;
    VP_Entry* entry = this->victory_point_list;
    while (entry) {
        if (entry->group == group || group == 0xFF)
            total += entry->curr_points;
        entry = entry->next;
    }
    return total;
}

// VA: 005334C0 get_victory_points_id

long RGE_Victory_Conditions::get_victory_points_id(unsigned char id) {
    int result = 0;
    VP_Entry* entry = this->victory_point_list;
    while (entry) {
        if (entry->id == id)
            result = entry->curr_points;
        entry = entry->next;
    }
    return result;
}

// VA: 005334E0 get_attribute_id

long RGE_Victory_Conditions::get_attribute_id(unsigned char id) {
    int result = 0;
    VP_Entry* entry = this->victory_point_list;
    while (entry) {
        if (entry->id == id)
            result = (int)entry->curr_attribute_amount;
        entry = entry->next;
    }
    return result;
}
