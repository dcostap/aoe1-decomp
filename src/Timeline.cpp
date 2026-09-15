#include "../include/Timeline.h"
#include "../include/obj_list.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/world.h"

#include <stdlib.h>


RGE_Timeline::RGE_Timeline(int infile, RGE_Game_World* gworld) {
    int index;
    RGE_Time_Entry** temp2;
    RGE_Time_Entry** old_link;
    short target_player_id;
    short this_player_id;

    rge_read(infile, &this->list_num, 2);
    rge_read(infile, &this->avail_id, 2);
    rge_read(infile, &this->old_time, 4);
    this->world = gworld;
    this->time_list = 0;

    temp2 = &this->time_list;
    index = 0;
    if (this->list_num > 0) {
        do {
            RGE_Time_Entry* entry = (RGE_Time_Entry*)calloc(1, 0x30);
            rge_read(infile, &entry->time, 4);
            rge_read(infile, &entry->command, 1);
            rge_read(infile, &entry->obj_type, 2);
            rge_read(infile, &entry->player, 1);
            rge_read(infile, &entry->x, 4);
            rge_read(infile, &entry->y, 4);
            rge_read(infile, &entry->z, 4);
            rge_read(infile, &entry->task, 2);
            rge_read(infile, &entry->this_obj_id, 2);
            rge_read(infile, &target_player_id, 2);
            rge_read(infile, &entry->target_obj_id, 2);
            rge_read(infile, &this_player_id, 2);

            if (target_player_id >= 0 && this->world != 0) {
                entry->this_obj = this->world->players[target_player_id]->objects->find_by_id(entry->this_obj_id);
            } else {
                entry->this_obj = 0;
            }

            if (this_player_id >= 0 && this->world != 0) {
                //! @bug The second lookup tests this_player_id but indexes target_player_id.
                entry->target_obj = this->world->players[target_player_id]->objects->find_by_id(entry->target_obj_id);
            } else {
                entry->target_obj = 0;
            }

            old_link = temp2;
            temp2 = &entry->next;
            entry->next = 0;
            *old_link = entry;
            ++index;
        } while (index < this->list_num);
    }
}

RGE_Timeline::RGE_Timeline(RGE_Game_World* gworld) {
    this->world = gworld;
    this->time_list = 0;
    this->list_num = 0;
    this->avail_id = 0;
    this->old_time = -1.0f;
}

RGE_Timeline::~RGE_Timeline() {
    while (this->time_list != 0) {
        RGE_Time_Entry* next = this->time_list->next;
        free(this->time_list);
        this->time_list = next;
    }
    this->avail_id = 0;
    this->old_time = -1.0f;
    this->world = 0;
    this->list_num = 0;
}

void RGE_Timeline::save(int outfile) {
    short this_player_id;
    short target_player_id;
    RGE_Time_Entry* entry;
    short* count_ptr;
    int i;
    int save_file;

    save_file = outfile;
    count_ptr = &this->list_num;
    rge_write(save_file, count_ptr, 2);
    rge_write(save_file, &this->avail_id, 2);
    rge_write(save_file, &this->old_time, 4);

    i = 0;
    if (*count_ptr > 0) {
        do {
            entry = &this->time_list[i];
            if (entry->this_obj != 0) {
                this_player_id = entry->this_obj->owner->id;
            } else {
                this_player_id = -1;
            }
            if (entry->target_obj != 0) {
                target_player_id = entry->target_obj->owner->id;
            } else {
                target_player_id = -1;
            }
            rge_write(save_file, entry, 4);
            rge_write(save_file, &entry->command, 1);
            rge_write(save_file, &entry->obj_type, 2);
            rge_write(save_file, &entry->player, 1);
            rge_write(save_file, &entry->x, 4);
            rge_write(save_file, &entry->y, 4);
            rge_write(save_file, &entry->z, 4);
            rge_write(save_file, &entry->task, 2);
            rge_write(save_file, &entry->this_obj_id, 2);
            rge_write(save_file, &this_player_id, 2);
            rge_write(save_file, &entry->target_obj_id, 2);
            rge_write(save_file, &target_player_id, 2);
            ++i;
        } while (i < *count_ptr);
    }
}

void RGE_Timeline::update() {
    RGE_Time_Entry* event = 0;
    RGE_Player* player;
    RGE_Master_Static_Object* master;
    RGE_Static_Object* object;
    RGE_Time_Entry* scan;
    float time = this->world->world_time * 0.001f;
    RGE_Time_Entry* entry = this->time_list;

    if (entry != 0) {
        do {
            if (event == 0 && entry->time > this->old_time)
                event = entry;

            if (entry->this_obj != 0 && entry->this_obj->object_state >= 8)
                entry->this_obj = 0;
            if (entry->target_obj != 0 && entry->target_obj->object_state >= 8)
                entry->target_obj = 0;
            entry = entry->next;
        } while (entry != 0);

        for (; event != 0 && event->time <= time; event = event->next) {
            switch (event->command) {
            case 0:
                if (event->this_obj != 0 && event->target_obj != 0)
                    event->this_obj->set_attack(event->target_obj);
                break;

            case 1:
                player = this->world->players[event->player];
                master = player->master_objects[event->obj_type];
                if (master != 0) {
                    object = master->make_new_obj(player, event->x, event->y, 0);
                    for (scan = this->time_list; scan != 0; scan = scan->next) {
                        if (event->this_obj_id == scan->this_obj_id)
                            scan->this_obj = object;
                        if (event->this_obj_id == scan->target_obj_id)
                            scan->target_obj = object;
                    }
                }
                break;

            case 2:
                if (event->this_obj != 0)
                    event->this_obj->move_to(0, event->x, event->y, event->z);
                break;

            case 4:
                if (event->this_obj != 0)
                    event->this_obj->destroy_obj();
                break;
            }
        }
    }
    this->old_time = time;
}

void RGE_Timeline::mock_update(float time) {
    RGE_Time_Entry* list;
    RGE_Time_Entry* entry;
    RGE_Time_Entry* next_entry;
    RGE_Static_Object* object;

    if (time < old_time) {
        list = time_list;
        entry = time_list;
        if (entry != 0) {
            while (entry != 0) {
                next_entry = entry->next;
                if (next_entry == 0)
                    break;
                if (next_entry->time > old_time)
                    break;
                entry = entry->next;
            }
            while (entry != 0) {
                if (entry->time <= time) break;
                if (!(entry->time > old_time)) {
                    switch (entry->command) {
                    case 1:
                        object = entry->this_obj;
                        if (object != 0) {
                            RGE_Time_Entry* scan_entry = time_list;
                            for (; scan_entry != 0; scan_entry = scan_entry->next) {
                                if (object == scan_entry->this_obj) scan_entry->this_obj = 0;
                                if (object == scan_entry->target_obj) scan_entry->target_obj = 0;
                            }
                        }
                        if (object != 0) delete object;
                        break;
                    case 4:
                        {
                            int player_index = entry->player;
                            RGE_Master_Static_Object* master = world->players[player_index]->master_objects[entry->obj_type];
                            if (master != 0) {
                                object = master->make_new_obj(world->players[player_index], entry->x, entry->y, 0);
                                for (next_entry = time_list; next_entry != 0; next_entry = next_entry->next) {
                                    if (entry->this_obj_id == next_entry->this_obj_id) next_entry->this_obj = object;
                                    if (entry->this_obj_id == next_entry->target_obj_id) next_entry->target_obj = object;
                                }
                            }
                        }
                        break;
                    }
                }
                list = time_list;
                if (entry == list) {
                    entry = 0;
                } else {
                    RGE_Time_Entry* previous_entry = time_list;
                    while (previous_entry != 0) {
                        if (previous_entry->next == entry) entry = previous_entry;
                        previous_entry = previous_entry->next;
                    }
                }
            }
        }
    }
    if (old_time < time) {
        entry = time_list;
        while (entry != 0) {
            if (entry->time > old_time && !(entry->time > time)) {
                switch (entry->command) {
                case 1:
                    {
                        int player_index = entry->player;
                        RGE_Master_Static_Object* master = world->players[player_index]->master_objects[entry->obj_type];
                        if (master != 0) {
                            object = master->make_new_obj(world->players[player_index], entry->x, entry->y, 0);
                            for (next_entry = time_list; next_entry != 0; next_entry = next_entry->next) {
                                if (entry->this_obj_id == next_entry->this_obj_id) next_entry->this_obj = object;
                                if (entry->this_obj_id == next_entry->target_obj_id) next_entry->target_obj = object;
                            }
                        }
                    }
                    break;
                case 4:
                    object = entry->this_obj;
                    if (object != 0) {
                        for (next_entry = time_list; next_entry != 0; next_entry = next_entry->next) {
                            if (object == next_entry->this_obj) next_entry->this_obj = 0;
                            if (object == next_entry->target_obj) next_entry->target_obj = 0;
                        }
                    }
                    if (object != 0) delete object;
                    break;
                }
            }
            entry = entry->next;
        }
    }
    old_time = time;
}

short RGE_Timeline::find_id(RGE_Static_Object* obj) {
    RGE_Time_Entry* entry = this->time_list;
    if (entry == 0) return -1;

    while (entry != 0) {
        if (entry->command == 1 && entry->this_obj == obj) {
            return entry->this_obj_id;
        }
        entry = entry->next;
    }
    return -1;
}

RGE_Time_Entry* RGE_Timeline::add(float time) {
    RGE_Time_Entry* node;
    RGE_Time_Entry** prev;

    node = this->time_list;
    prev = &this->time_list;
    if (node == 0) {
        node = (RGE_Time_Entry*)calloc(1, 0x30);
        *prev = node;
        node->time = time;
        this->list_num++;
        return *prev;
    }

    while (node != 0) {
        if (node->time > time) {
            RGE_Time_Entry* new_node = (RGE_Time_Entry*)calloc(1, 0x30);
            new_node->time = time;
            new_node->next = node;
            *prev = new_node;
            this->list_num++;
            return new_node;
        }
        prev = &node->next;
        node = node->next;
    }

    {
        node = (RGE_Time_Entry*)calloc(1, 0x30);
        RGE_Time_Entry** node_next = &node->next;
        node->time = time;
        *node_next = 0;
        *prev = node;
        this->list_num++;
        return node;
    }
}

RGE_Time_Entry* RGE_Timeline::add_attack(float time, RGE_Static_Object* obj,
                                          RGE_Static_Object* target) {
    RGE_Time_Entry* entry = this->add(time);
    if (entry != 0) {
        entry->this_obj = obj;
        entry->player = obj->owner->id;
        entry->this_obj_id = this->find_id(obj);
        entry->target_obj = target;
        //! @bug The target ID uses obj instead of target.
        entry->target_obj_id = this->find_id(obj);
        entry->command = 0;
    }
    return entry;
}

RGE_Time_Entry* RGE_Timeline::add_create(float time, short obj_id,
                                          unsigned char player, float x, float y, float z) {
    RGE_Static_Object* obj = 0;
    RGE_Time_Entry* node = this->add(time);
    RGE_Player* player_record = this->world->players[player];
    RGE_Master_Static_Object* master = player_record->master_objects[obj_id];
    if (master != 0)
        obj = master->make_new_obj(player_record, x, y, 0);

    if (node != 0 && master != 0) {
        node->player = player;
        node->obj_type = obj_id;
        node->this_obj = obj;
        node->this_obj_id = this->avail_id;
        this->avail_id++;
        node->x = x;
        node->y = y;
        node->z = z;
        node->command = 1;
    }
    return node;
}

RGE_Time_Entry* RGE_Timeline::add_move(float time, RGE_Static_Object* obj,
                                        float x, float y, float z) {
    RGE_Time_Entry* entry = this->add(time);
    if (entry != 0) {
        entry->player = obj->owner->id;
        entry->this_obj = obj;
        entry->this_obj_id = this->find_id(obj);
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->command = 2;
    }
    return entry;
}

RGE_Time_Entry* RGE_Timeline::add_delete(float time, RGE_Static_Object* obj) {
    if (obj == 0)
        return 0;

    RGE_Time_Entry* node = this->add(time);
    if (node != 0) {
        RGE_Time_Entry* entry = this->time_list;
        while (entry != 0) {
            if (obj == entry->this_obj) {
                unsigned char command = entry->command;
                entry->this_obj = 0;
                if (command == 1)
                    node->this_obj_id = entry->this_obj_id;
            }
            if (obj == entry->target_obj)
                entry->target_obj = 0;
            entry = entry->next;
        }

        node->player = obj->owner->id;
        node->obj_type = obj->master_obj->id;
        node->command = 4;
        node->x = obj->world_x;
        node->y = obj->world_y;
        delete obj;
    }
    return node;
}

void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry* current = this->time_list;
    RGE_Time_Entry** link = &this->time_list;

    if (current != 0) {
        while (current != 0) {
            if (current == entry) {
                *link = current->next;
                if (current->command == 1) {
                    entry = this->time_list;
                    while (entry != 0)
                        entry = entry->next;
                }
                this->sub(entry);
                free(current);
                this->list_num--;
                return;
            }

            link = &current->next;
            current = current->next;
        }
    }
}
