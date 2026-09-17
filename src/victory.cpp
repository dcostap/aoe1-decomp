#include "../include/victory.h"
#include "../include/rge_fio.h"
#include "../include/player.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/visible.h"
#include "../include/world.h"
#include "../include/obj_list.h"

extern "C" void* calloc(unsigned int count, unsigned int size);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern void __cdecl getstring(char** destination, char* source);
extern "C" void __cdecl free(void* block);




RGE_Victory_Conditions::RGE_Victory_Conditions(
    RGE_Player* in_player, int infile, long* player_id_hash, unsigned char version_control) {
    long index;
    long target_player;
    float version;
    long temp_num;
    long* list_num_ptr;
    RGE_Victory_Entry** temp2;
    int file_handle = infile;
    long target_obj;

    if (version_control == 1) {
        rge_read(file_handle, &version, 4);
    } else {
        version = 0.0f;
    }

    list_num_ptr = &this->list_num;
    rge_read(file_handle, list_num_ptr, 4);
    rge_read(file_handle, &this->victory, 1);

    temp2 = &this->victory_list;
    *temp2 = 0;
    this->player = in_player;
    index = 0;

    while (index < *list_num_ptr) {
        RGE_Victory_Entry* entry =
            (RGE_Victory_Entry*)calloc(1, sizeof(RGE_Victory_Entry));

        rge_read(file_handle, entry, 1);
        rge_read(file_handle, &entry->obj_type, 4);
        rge_read(file_handle, &target_player, 4);
        rge_read(file_handle, &entry->x0, 4);
        rge_read(file_handle, &entry->y0, 4);
        rge_read(file_handle, &entry->x1, 4);
        rge_read(file_handle, &entry->y1, 4);
        rge_read(file_handle, &entry->number, 4);
        rge_read(file_handle, &entry->count, 4);
        rge_read(file_handle, &infile, 4);
        rge_read(file_handle, &target_obj, 4);
        rge_read(file_handle, &entry->victory_group, 1);
        rge_read(file_handle, &entry->ally_flag, 1);
        rge_read(file_handle, &entry->state, 1);

        entry->target_obj = 0;
        entry->this_obj = 0;
        entry->target_player = 0;
        *temp2 = entry;
        temp2 = &entry->next;

        if (infile >= 0) {
            int player_index = 0;
            RGE_Game_World* world = this->player->world;
            while (player_index < world->player_num) {
                entry->this_obj =
                    world->players[player_index]->objects->find_by_id(infile);
                if (entry->this_obj != 0) {
                    break;
                }
                player_index++;
                world = this->player->world;
            }
            if (infile >= 0 && entry->this_obj == 0) {
                entry->state = 3;
            }
        }

        if (target_obj >= 0) {
            entry->target_obj = this->player->objects->find_by_id(target_obj);
        }

        if (target_player >= 0) {
            if (player_id_hash != 0) {
                target_player = player_id_hash[target_player];
            }
            if (target_player >= 0) {
                RGE_Player* reference_player =
                    this->player->world->players[target_player];
                entry->target_player = reference_player;
                if (reference_player != 0 && entry->target_obj == 0 &&
                    target_obj >= 0) {
                    entry->target_obj =
                        reference_player->objects->find_by_id(target_obj);
                }
            } else {
                entry->state = 3;
            }
        } else {
            entry->target_player = 0;
        }

        if (target_obj >= 0 && entry->target_obj == 0) {
            entry->state = 3;
        }

        index++;
    }

    this->victory_point_list = 0;
    this->point_list_num = 0;

    if (version >= 1.0) {
        long* total_points = &this->tot_victory_points;
        rge_read(file_handle, total_points, 4);
        rge_read(file_handle, &temp_num, 4);

        index = 0;
        while (index < temp_num) {
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


RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Player* in_Player) {
    this->player = in_Player;
    this->list_num = 0;
    this->victory_list = 0;
    this->victory_point_list = 0;
    this->victory = 0;
    this->point_list_num = 0;
    this->tot_victory_points = 0;
}


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


void RGE_Victory_Conditions::update_for_object(RGE_Static_Object* obj) {
    RGE_Victory_Entry* entry = this->victory_list;

    while (entry != 0) {
        RGE_Victory_Entry* next = entry->next;
        if ((entry->this_obj == obj) || (entry->target_obj == obj)) {
            this->sub(entry);
        }
        entry = next;
    }
}


void RGE_Victory_Conditions::handle_point_condition(RGE_Victory_Point_Entry* node) {
    switch (node->command) {
    case 0:
        this->handle_points_attribute_amount(node);
        return;
    case 1:
        this->handle_points_attribute_first(node);
        return;
    case 2:
        this->handle_points_highest_attribute(node);
        return;
    case 3:
        this->handle_points_high_attribute_once(node);
        return;
    case 4:
        this->handle_points_high_attribute_amount(node);
        return;
    }
}




void RGE_Victory_Conditions::handle_condition(RGE_Victory_Entry* node) {
    switch (node->command) {
    case 0:
        handle_capture(node);
        return;
    case 1:
        handle_create(node);
        return;
    case 8:
        handle_create_in_area(node);
        return;
    case 2:
        handle_destroy(node);
        return;
    case 3:
        handle_destroy_multiple(node);
        return;
    case 9:
        handle_destroy_all(node);
        return;
    case 10:
        handle_destroy_player(node);
        return;
    case 4:
        handle_bring_area(node);
        return;
    case 5:
        handle_bring_object(node);
        return;
    case 6:
        handle_attribute(node);
        return;
    case 7:
        handle_explore(node);
        return;
    case 12:
        handle_victory_points(node);
        return;
    }
}



void RGE_Victory_Conditions::handle_capture(RGE_Victory_Entry* node) {
    RGE_Static_Object* obj = (RGE_Static_Object*)node->target_obj;
    if (obj) {
        if (obj->object_state > 2) {
            node->target_obj = 0;
            if (node->state == 0) {
                node->state = 1;
                return;
            }
        } else {
            if (node->state == 0) {
                RGE_Player* owner = obj->owner;
                RGE_Player* self = this->player;
                if (owner == self ||
                    (node->ally_flag && self->allied_victory &&
                     self->relations[owner->id] == 0 &&
                     owner->relations[self->id] == 0 && owner->allied_victory)) {
                    node->state = 2;
                    return;
                }
            } else if (node->state == 2) {
                RGE_Player* owner = obj->owner;
                RGE_Player* self = this->player;
                if (owner != self && (!node->ally_flag || self->relations[owner->id] != 0)) {
                    node->state = 0;
                }
            }
        }
    }
}



void RGE_Victory_Conditions::handle_create(RGE_Victory_Entry* node) {
    RGE_Player* self = this->player;
    int count = 0;
    RGE_Object_Node* object_node = self->objects->list;

    while (object_node != 0) {
        if (object_node->node->master_obj->copy_id == node->obj_type &&
            object_node->node->object_state == 2) {
            count++;
        }
        object_node = object_node->next;
    }

    if (node->ally_flag != 0 && self->allied_victory != 0) {
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
                    RGE_Object_Node* object_node = players[i]->objects->list;
                    while (object_node != 0) {
                        if (object_node->node->master_obj->copy_id == node->obj_type &&
                            object_node->node->object_state == 2) {
                            count++;
                        }
                        object_node = object_node->next;
                    }
                }
                i++;
            } while (i < num);
        }
    }

    if (count >= node->number) {
        node->state = 2;
    } else {
        node->state = 0;
    }
}



void RGE_Victory_Conditions::handle_create_in_area(RGE_Victory_Entry* node) {
    int count = 0;
    RGE_Player* player = this->player;

    RGE_Object_Node* object_node = player->objects->list;
    while (object_node != 0) {
        RGE_Static_Object* obj = object_node->node;
        if (obj->master_obj->copy_id == node->obj_type &&
            obj->object_state == 2 &&
            obj->world_x >= node->x0 &&
            obj->world_x <= node->x1 &&
            obj->world_y >= node->y0 &&
            obj->world_y <= node->y1) {
            count++;
        }
        object_node = object_node->next;
    }

    if (node->ally_flag != 0 && player->allied_victory != 0) {
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
                        object_node = p->objects->list;
                        while (object_node != 0) {
                            RGE_Static_Object* obj = object_node->node;
                            if (obj->master_obj->copy_id == node->obj_type &&
                                obj->object_state == 2 &&
                                obj->world_x >= node->x0 &&
                                obj->world_x <= node->x1 &&
                                obj->world_y >= node->y0 &&
                                obj->world_y <= node->y1) {
                                count++;
                            }
                            object_node = object_node->next;
                        }
                    }
                }
                ++i;
                ++current;
            } while (i < num);
        }
    }

    if (count >= node->number) {
        node->state = 2;
    } else {
        node->state = 0;
    }
}


void RGE_Victory_Conditions::handle_destroy(RGE_Victory_Entry* node) {
    if (node->target_obj && node->target_obj->object_state == 7) {
        node->state = 2;
        node->target_obj = 0;
    }
}



void RGE_Victory_Conditions::handle_destroy_multiple(RGE_Victory_Entry* node) {
    if (node->state) return;

    if (node->target_player) {
        RGE_Object_Node* object_node = node->target_player->objects->list;
        while (object_node) {
            if (object_node->node->master_obj->copy_id == node->obj_type && object_node->node->object_state == 7)
                node->count++;
            object_node = object_node->next;
        }
    } else {
        RGE_Player* player = this->player;
        RGE_Player** players = player->world->players;
        int i = 0;
        if (i < player->world->player_num) {
            RGE_Player** current_players = players;
            do {
                if (player->relations[i]) {
                    RGE_Object_Node* object_node = current_players[0]->objects->list;
                    while (object_node) {
                        if (object_node->node->master_obj->copy_id == node->obj_type &&
                            object_node->node->object_state == 7)
                            node->count++;
                        object_node = object_node->next;
                    }
                }
                player = this->player;
                i++;
                current_players++;
            } while (i < player->world->player_num);
        }
    }

    if (node->count >= node->number) {
        node->state = 2;
    }
}




void RGE_Victory_Conditions::handle_destroy_all(RGE_Victory_Entry* node) {
    if (node->target_player != 0) {
        RGE_Object_Node* object_node = node->target_player->objects->list;
        while (object_node != 0) {
            if (object_node->node->master_obj->copy_id == node->obj_type) {
                node->state = 0;
                return;
            }
            object_node = object_node->next;
        }
        node->state = 2;
        return;
    }

    RGE_Player* player = this->player;
    int num = player->world->player_num;
    RGE_Player** players = player->world->players;

    for (int i = 0; i < num; i++) {
        if (player->relations[i] == 0 || i == player->id) {
            continue;
        }

        RGE_Object_Node* object_node = players[i]->objects->list;
        while (object_node != 0) {
            if (object_node->node->master_obj->copy_id == node->obj_type) {
                node->state = 0;
                return;
            }
            object_node = object_node->next;
        }
    }

    node->state = 2;
}


void RGE_Victory_Conditions::handle_destroy_player(RGE_Victory_Entry* node) {
    if (node->target_player) {
        if (node->target_player->game_status != 2)
            node->state = 0;
        else
            node->state = 2;
    }
}



void RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry* node) {
    RGE_Static_Object* obj = node->this_obj;

    if (obj) {
        if (obj->object_state >= 3) {
            if (node->state == 0) {
                node->state = 1;
            }
            node->this_obj = 0;
            return;
        }

        if (obj->world_x < node->x0 || obj->world_x > node->x1 ||
            obj->world_y < node->y0 || obj->world_y > node->y1) {
            node->state = 0;
        } else {
            node->state = 2;
        }
        return;
    } else {
        node->state = 3;
        return;
    }
}



void RGE_Victory_Conditions::handle_bring_object(RGE_Victory_Entry* node) {
    if (node->this_obj == 0 || node->target_obj == 0) {
        node->state = 3;
        return;
    }

    if (node->this_obj->object_state >= 3 || node->target_obj->object_state >= 3) {
        node->this_obj = 0;
        node->target_obj = 0;
        if (node->state == 0) {
            node->state = 1;
        }
        return;
    }

    float dx = node->this_obj->world_x - node->target_obj->world_x;
    float dy = node->this_obj->world_y - node->target_obj->world_y;

    if (dx < 0.0f) dx = -dx;
    if (dy < 0.0f) dy = -dy;

    RGE_Static_Object* this_object = node->this_obj;
    float range_x = node->target_obj->master_obj->radius_x + this_object->master_obj->radius_x + 1.0f;
    float range_y = node->target_obj->master_obj->radius_y + this_object->master_obj->radius_y + 1.0f;

    if (dx <= range_x && dy <= range_y) {
        node->state = 2;
    } else {
        node->state = 0;
    }
}



void RGE_Victory_Conditions::handle_attribute(RGE_Victory_Entry* node) {
    RGE_Player* p = this->player;
    RGE_Victory_Entry* e;
    int attribute_index;
    float total;

    if (p == 0)
        return;

    e = node;
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



void RGE_Victory_Conditions::handle_explore(RGE_Victory_Entry* node) {
    if (node->state != 0) return;

    if (this->player) {
        if (node->ally_flag != 0 && this->player->allied_victory != 0) {
            RGE_Game_World* world = this->player->world;
            int num = world->player_num;
            RGE_Player** players = world->players;
            int i = num - 1;
            if (i < 0) return;
            RGE_Player** pp = players + i;
            while (i >= 0) {
                if ((this->player->relations[i] == 0 &&
                     (*pp)->relations[this->player->id] == 0 &&
                     (*pp)->allied_victory != 0) || i == this->player->id) {
                    float explored = (*pp)->visible->percentExplored();
                    if (explored * 100.0f >= (float)node->count) {
                        node->state = 2;
                        return;
                    }
                }
                i--;
                pp--;
            }
        } else {
            float explored = this->player->visible->percentExplored();
            if (explored * 100.0f >= (float)node->count) {
                node->state = 2;
            }
        }
    }
}



void RGE_Victory_Conditions::handle_victory_points(RGE_Victory_Entry* node) {
    if (this->player != 0) {
        long total = this->tot_victory_points;
        int player_count = 1;

        if (node->ally_flag != 0 && this->player->allied_victory != 0) {
            RGE_Game_World* world = this->player->world;
            RGE_Player** players = world->players;
            int i = world->player_num - 1;
            if (i >= 0) {
                RGE_Player** pp = players + i;
                do {
                    if (this->player->relations[i] == 0) {
                        RGE_Player* other = *pp;
                        if (other->relations[this->player->id] == 0 &&
                            i != this->player->id && other->allied_victory != 0) {
                            total += other->victory_conditions->get_victory_points();
                            player_count++;
                        }
                    }
                    i--;
                    pp--;
                } while (i >= 0);
            }
        }

        if (total / player_count >= node->count) {
            node->state = 2;
        }
    }
}




RGE_Victory_Entry* RGE_Victory_Conditions::add(unsigned char v_group, unsigned char alliance) {
    RGE_Victory_Entry* entry = (RGE_Victory_Entry*)calloc(1, 52);
    if (entry != 0) {
        entry->state = 0;
        entry->victory_group = v_group;
        entry->ally_flag = alliance;
        entry->count = 0;
        entry->next = this->victory_list;
        this->victory_list = entry;
        this->list_num++;
    }
    return entry;
}


unsigned char RGE_Victory_Conditions::add_capture(unsigned char v_group, RGE_Static_Object* obj, unsigned char alliance) {
    RGE_Victory_Entry* entry = this->add(v_group, alliance);
    if (entry) {
        entry->command = 0;
        entry->target_obj = obj;
        entry->target_player = obj->owner;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_create(unsigned char v_group, long obj_type, long number, unsigned char alliance) {
    RGE_Victory_Entry* entry = this->add(v_group, alliance);
    if (entry) {
        entry->command = 1;
        entry->obj_type = obj_type;
        entry->number = number;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_create(unsigned char v_group, long obj_type, long number, float x0, float y0, float x1, float y1, unsigned char alliance) {
    RGE_Victory_Entry* entry = this->add(v_group, alliance);
    if (entry != 0) {
        entry->obj_type = obj_type;
        entry->number = number;
        entry->x0 = x0;
        entry->y0 = y0;
        entry->command = 8;
        entry->x1 = x1;
        entry->y1 = y1;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_destroy(unsigned char v_group, RGE_Static_Object* obj) {
    RGE_Victory_Entry* entry = this->add(v_group, 0);
    if (entry) {
        entry->command = 2;
        entry->target_obj = obj;
        entry->target_player = obj->owner;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_destroy(unsigned char v_group, long obj_type, long num, RGE_Player* player) {
    RGE_Victory_Entry* entry = this->add(v_group, 0);
    if (entry) {
        entry->obj_type = obj_type;
        entry->command = 3;
        entry->number = num;
        entry->target_player = player;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_destroy(unsigned char v_group, long obj_type, RGE_Player* player) {
    RGE_Victory_Entry* entry = this->add(v_group, 0);
    if (entry) {
        entry->command = 9;
        entry->obj_type = obj_type;
        entry->target_player = player;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_destroy(unsigned char v_group, RGE_Player* player) {
    RGE_Victory_Entry* entry = this->add(v_group, 0);
    if (entry) {
        entry->command = 0x0A;
        entry->target_player = player;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_bring(unsigned char v_group, RGE_Static_Object* obj, RGE_Static_Object* target) {
    RGE_Victory_Entry* entry = this->add(v_group, 0);
    if (entry) {
        entry->command = 5;
        entry->this_obj = obj;
        entry->target_obj = target;
        entry->target_player = target->owner;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_bring(unsigned char v_group, RGE_Static_Object* obj, float x0, float y0, float x1, float y1) {
    RGE_Victory_Entry* entry = this->add(v_group, 0);
    if (entry != 0) {
        entry->command = 4;
        entry->this_obj = obj;
        entry->x0 = x0;
        entry->y0 = y0;
        entry->x1 = x1;
        entry->y1 = y1;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_attributes(unsigned char v_group, long attribute, long count, unsigned char alliance) {
    RGE_Victory_Entry* entry = this->add(v_group, alliance);
    if (entry) {
        entry->command = 6;
        entry->number = attribute;
        entry->count = count;
        return 1;
    }
    return 0;
}



unsigned char RGE_Victory_Conditions::add_explore(unsigned char v_group, long count, unsigned char alliance) {
    RGE_Victory_Entry* entry = this->add(v_group, alliance);
    if (entry != 0) {
        entry->command = 7;
        if (count < 1) {
            count = 1;
        }
        if (100 < count) {
            count = 100;
        }
        entry->count = count;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_victory_points(unsigned char v_group, long count, unsigned char alliance) {
    RGE_Victory_Entry* entry = this->add(v_group, alliance);
    if (entry) {
        entry->command = 0x0C;
        entry->count = count;
        return 1;
    }
    return 0;
}




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


void RGE_Victory_Conditions::destroy_all() {
    RGE_Victory_Entry* entry;

    entry = this->victory_list;
    while (entry != 0) {
        sub(entry);
        entry = this->victory_list;
    }
}


unsigned char RGE_Victory_Conditions::condition_info(long condition, char** description, unsigned char& type) {
    RGE_Victory_Entry* entry = this->victory_list;
    int i = 0;
    char* text = 0;

    if (entry) {
        while (entry != 0) {
            if (i == condition) {
                text = this->condition_description(entry);
                *description = text;
                type = entry->command;
                return 1;
            }
            entry = entry->next;
            i++;
        }
    }
    *description = text;
    return 0;
}



char* RGE_Victory_Conditions::condition_description(RGE_Victory_Entry* node) {
    char* description = 0;
    char temp[200];

    switch (node->command) {
    case 0:
        sprintf(temp, "Capture %s", node->this_obj->master_obj->name);
        break;
    case 1:
        sprintf(temp, "Create %d %s", node->number,
            node->target_player->master_objects[node->obj_type]->name);
        break;
    case 8:
        sprintf(temp, "Create %d %s in area (%f, %f) - (%f, %f)",
            node->number,
            node->target_player->master_objects[node->obj_type]->name,
            (double)node->x0, (double)node->y0,
            (double)node->x1, (double)node->y1);
        break;
    case 2:
        sprintf(temp, "Destroy %s", node->this_obj->master_obj->name);
        break;
    case 3:
        sprintf(temp, "Destroy %d %s of player %d", node->number,
            node->target_player->master_objects[node->obj_type]->name,
            node->target_player->id);
        break;
    case 9:
        sprintf(temp, "Destroy all %s of player %d",
            node->target_player->master_objects[node->obj_type]->name,
            node->target_player->id);
        break;
    case 4:
        sprintf(temp, "Bring %s to area (%f, %f) - (%f, %f)",
            node->this_obj->master_obj->name,
            (double)node->x0, (double)node->y0,
            (double)node->x1, (double)node->y1);
        break;
    case 5:
        sprintf(temp, "Bring %s to %s",
            node->this_obj->master_obj->name,
            node->target_obj->master_obj->name);
        break;
    case 6:
        sprintf(temp, "aqquire %d of attribute %d", node->count,
            node->number);
        break;
    case 7:
        sprintf(temp, "explore %d percent of the map", node->count);
        break;
    }

    getstring(&description, temp);
    return description;
}



RGE_Victory_Entry* RGE_Victory_Conditions::condition_raw_info(long condition) {
    RGE_Victory_Entry* entry;
    long wanted;
    long count;

    entry = this->victory_list;
    wanted = condition;
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


long RGE_Victory_Conditions::condition_number(long condition) { return this->list_num; }


unsigned char RGE_Victory_Conditions::victory_achieved(void) {
    if (this->victory == 2) {
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::remove_condition(long condition) {
    int i = 0;
    RGE_Victory_Entry* entry = this->victory_list;
    while (entry) {
        if (i == condition) {
            this->sub(entry);
            return 1;
        }
        i++;
        entry = entry->next;
    }
    return 0;
}



RGE_Victory_Point_Entry* RGE_Victory_Conditions::add_point(unsigned char id, unsigned char group) {
    RGE_Victory_Point_Entry* entry = (RGE_Victory_Point_Entry*)calloc(1, 28);
    if (entry != 0) {
        entry->state = 0;
        entry->attribute = -1;
        entry->amount = 0;
        entry->command = 0xff;
        entry->points = 0;
        entry->curr_points = 0;
        entry->next = this->victory_point_list;
        entry->id = id;
        entry->group = group;
        this->victory_point_list = entry;
        this->point_list_num++;
    }
    return entry;
}




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


unsigned char RGE_Victory_Conditions::add_points_attribute_amount(unsigned char group, unsigned char id, long attribute, long count, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(id, group);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 0;
        entry->amount = count;
        entry->points = points;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_points_attribute_first(unsigned char group, unsigned char id, long attribute, long count, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(id, group);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 1;
        entry->amount = count;
        entry->points = points;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_points_highest_attribute(unsigned char group, unsigned char id, long attribute, long count, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(id, group);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 2;
        entry->amount = count;
        entry->points = points;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_points_high_attribute_once(unsigned char group, unsigned char id, long attribute, long count, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(id, group);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 3;
        entry->amount = count;
        entry->points = points;
        return 1;
    }
    return 0;
}


unsigned char RGE_Victory_Conditions::add_points_high_attribute_amount(unsigned char group, unsigned char id, long attribute, long count, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(id, group);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 4;
        entry->amount = count;
        entry->points = points;
        return 1;
    }
    return 0;
}


void RGE_Victory_Conditions::handle_points_attribute_amount(RGE_Victory_Point_Entry* node) {
    if (node->state == 0) {
        int amount = (int)this->player->attributes[node->attribute];
        int calculated_points = amount / node->amount;
        node->curr_attribute_amount = (float)amount;
        if (calculated_points < 0) {
            calculated_points = 0;
        }
        calculated_points = node->points * calculated_points;
        if (calculated_points != node->curr_points) {
            this->tot_victory_points += calculated_points - node->curr_points;
            node->curr_points = calculated_points;
        }
    }
}



void RGE_Victory_Conditions::handle_points_attribute_first(RGE_Victory_Point_Entry* node) {
    RGE_Player* player;
    RGE_Victory_Point_Entry* p;
    if (node->state == 0) {
        player = this->player;
        p = node;
        int amount = (int)player->attributes[p->attribute];
        int points = p->points;
        RGE_Player** players = player->world->players;
        p->curr_attribute_amount = (float)amount;
        if (amount < p->amount) return;

        amount = 0;
        int count = this->player->world->player_num;
        if (0 < count) {
            do {
                if (amount == this->player->id) {
                    amount = amount + 1;
                    players = players + 1;
                } else if ((float)p->amount > (*players)->attributes[p->attribute]) {
                    amount = amount + 1;
                    players = players + 1;
                } else {
                    p->state = 1;
                    return;
                }
            } while (amount < count);
        }
        this->tot_victory_points += points - p->curr_points;
        p->curr_points = points;
        p->state = 2;
    }
}




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


long RGE_Victory_Conditions::get_victory_points() { return this->tot_victory_points; }


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
