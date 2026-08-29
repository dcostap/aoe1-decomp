#include "../include/Timeline.h"
#include "../include/obj_list.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/world.h"

#include <stdlib.h>

// PDB source order: Timeline.cpp lines 25-530.

// 0050D5B0 RGE_Timeline::RGE_Timeline(int, RGE_Game_World*)
RGE_Timeline::RGE_Timeline(int fd, RGE_Game_World* world_arg)
{
    int index;
    RGE_Time_Entry** link;
    RGE_Time_Entry** old_link;
    short target_player_id;
    short player_id;

    rge_read(fd, &this->list_num, 2);
    rge_read(fd, &this->avail_id, 2);
    rge_read(fd, &this->old_time, 4);
    this->world = world_arg;
    this->time_list = 0;

    link = &this->time_list;
    index = 0;
    if (this->list_num > 0) {
        do {
            RGE_Time_Entry* entry = (RGE_Time_Entry*)calloc(1, 0x30);
            rge_read(fd, &entry->time, 4);
            rge_read(fd, &entry->command, 1);
            rge_read(fd, &entry->obj_type, 2);
            rge_read(fd, &entry->player, 1);
            rge_read(fd, &entry->x, 4);
            rge_read(fd, &entry->y, 4);
            rge_read(fd, &entry->z, 4);
            rge_read(fd, &entry->task, 2);
            rge_read(fd, &entry->this_obj_id, 2);
            rge_read(fd, &target_player_id, 2);
            rge_read(fd, &entry->target_obj_id, 2);
            rge_read(fd, &player_id, 2);

            if (target_player_id >= 0 && this->world != 0) {
                entry->this_obj = this->world->players[target_player_id]->objects->find_by_id(entry->this_obj_id);
            } else {
                entry->this_obj = 0;
            }

            if (player_id >= 0 && this->world != 0) {
                // ORIGINAL BUG: the shipped code uses target_player_id for
                // this lookup, although player_id was read for this object.
                entry->target_obj = this->world->players[target_player_id]->objects->find_by_id(entry->target_obj_id);
            } else {
                entry->target_obj = 0;
            }

            old_link = link;
            link = &entry->next;
            entry->next = 0;
            *old_link = entry;
            ++index;
        } while (index < this->list_num);
    }
}

// 0050D7B0 RGE_Timeline::RGE_Timeline(RGE_Game_World*)
RGE_Timeline::RGE_Timeline(RGE_Game_World* world_arg) {
    this->world = world_arg;
    this->time_list = 0;
    this->list_num = 0;
    this->avail_id = 0;
    this->old_time = -1.0f;
}

// 0050D7E0 RGE_Timeline::~RGE_Timeline()
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

// 0050D830 RGE_Timeline::save(int)
void RGE_Timeline::save(int file) {
    short source_player_id;
    short target_player_id;
    RGE_Time_Entry* entry;
    short* count_ptr;
    int i;
    int save_file;

    save_file = file;
    count_ptr = &this->list_num;
    rge_write(save_file, count_ptr, 2);
    rge_write(save_file, &this->avail_id, 2);
    rge_write(save_file, &this->old_time, 4);

    i = 0;
    if (*count_ptr > 0) {
        do {
            entry = &this->time_list[i];
            if (entry->this_obj != 0) {
                source_player_id = entry->this_obj->owner->id;
            } else {
                source_player_id = -1;
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
            rge_write(save_file, &source_player_id, 2);
            rge_write(save_file, &entry->target_obj_id, 2);
            rge_write(save_file, &target_player_id, 2);
            ++i;
        } while (i < *count_ptr);
    }
}

// 0050D9A0 RGE_Timeline::update()
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

// 0050DB10 RGE_Timeline::mock_update(float)
void RGE_Timeline::mock_update(float t)
{
    RGE_Time_Entry* list;
    RGE_Time_Entry* e;
    RGE_Time_Entry* n;
    RGE_Static_Object* obj;

    if (t < old_time) {
        list = time_list;
        e = time_list;
        if (e != 0) {
            while (e != 0) {
                n = e->next;
                if (n == 0)
                    break;
                if (n->time > old_time)
                    break;
                e = e->next;
            }
            while (e != 0) {
                if (e->time <= t) break;
                if (!(e->time > old_time)) {
                    switch (e->command) {
                    case 1:
                        obj = e->this_obj;
                        if (obj != 0) {
                            RGE_Time_Entry* p = time_list;
                            for (; p != 0; p = p->next) {
                                if (obj == p->this_obj) p->this_obj = 0;
                                if (obj == p->target_obj) p->target_obj = 0;
                            }
                        }
                        if (obj != 0) delete obj;
                        break;
                    case 4:
                        {
                            int player_index = e->player;
                            RGE_Master_Static_Object* mo = world->players[player_index]->master_objects[e->obj_type];
                            if (mo != 0) {
                                obj = mo->make_new_obj(world->players[player_index], e->x, e->y, 0);
                                for (n = time_list; n != 0; n = n->next) {
                                    if (e->this_obj_id == n->this_obj_id) n->this_obj = obj;
                                    if (e->this_obj_id == n->target_obj_id) n->target_obj = obj;
                                }
                            }
                        }
                        break;
                    }
                }
                list = time_list;
                if (e == list) {
                    e = 0;
                } else {
                    RGE_Time_Entry* p = time_list;
                    while (p != 0) {
                        if (p->next == e) e = p;
                        p = p->next;
                    }
                }
            }
        }
    }
    if (old_time < t) {
        e = time_list;
        while (e != 0) {
            if (e->time > old_time && !(e->time > t)) {
                switch (e->command) {
                case 1:
                    {
                        int player_index = e->player;
                        RGE_Master_Static_Object* mo = world->players[player_index]->master_objects[e->obj_type];
                        if (mo != 0) {
                            obj = mo->make_new_obj(world->players[player_index], e->x, e->y, 0);
                            for (n = time_list; n != 0; n = n->next) {
                                if (e->this_obj_id == n->this_obj_id) n->this_obj = obj;
                                if (e->this_obj_id == n->target_obj_id) n->target_obj = obj;
                            }
                        }
                    }
                    break;
                case 4:
                    obj = e->this_obj;
                    if (obj != 0) {
                        for (n = time_list; n != 0; n = n->next) {
                            if (obj == n->this_obj) n->this_obj = 0;
                            if (obj == n->target_obj) n->target_obj = 0;
                        }
                    }
                    if (obj != 0) delete obj;
                    break;
                }
            }
            e = e->next;
        }
    }
    old_time = t;
}

// 0050DD30 RGE_Timeline::find_id(RGE_Static_Object*)
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

// 0050DD70 RGE_Timeline::add(float)
RGE_Time_Entry* RGE_Timeline::add(float time)
{
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
        RGE_Time_Entry* new_node = (RGE_Time_Entry*)calloc(1, 0x30);
        new_node->time = time;
        new_node->next = 0;
        *prev = new_node;
        this->list_num++;
        return new_node;
    }
}

// 0050DE00 RGE_Timeline::add_attack(float, RGE_Static_Object*, RGE_Static_Object*)
RGE_Time_Entry* RGE_Timeline::add_attack(float time,
                                          RGE_Static_Object* object,
                                          RGE_Static_Object* target) {
    RGE_Time_Entry* entry = this->add(time);
    if (entry != 0) {
        entry->this_obj = object;
        entry->player = object->owner->id;
        entry->this_obj_id = this->find_id(object);
        entry->target_obj = target;
        // ORIGINAL BUG: the shipped code looks up the source object again.
        entry->target_obj_id = this->find_id(object);
        entry->command = 0;
    }
    return entry;
}

// 0050DE50 RGE_Timeline::add_create(float, short, unsigned char, float, float, float)
RGE_Time_Entry* RGE_Timeline::add_create(float time, short type,
                                          unsigned char player, float x,
                                          float y, float z)
{
    RGE_Static_Object* obj = 0;
    RGE_Time_Entry* node = this->add(time);
    RGE_Player* p = this->world->players[player];
    RGE_Master_Static_Object* master = p->master_objects[type];
    if (master != 0)
        obj = master->make_new_obj(p, x, y, 0);

    if (node != 0 && master != 0) {
        node->player = player;
        node->obj_type = type;
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

// 0050DEF0 RGE_Timeline::add_move(float, RGE_Static_Object*, float, float, float)
RGE_Time_Entry* RGE_Timeline::add_move(float time,
                                        RGE_Static_Object* object,
                                        float x, float y, float z) {
    RGE_Time_Entry* entry = this->add(time);
    if (entry != 0) {
        entry->player = object->owner->id;
        entry->this_obj = object;
        entry->this_obj_id = this->find_id(object);
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->command = 2;
    }
    return entry;
}

// 0050DF40 RGE_Timeline::add_delete(float, RGE_Static_Object*)
RGE_Time_Entry* RGE_Timeline::add_delete(float time,
                                          RGE_Static_Object* obj)
{
    if (obj == 0)
        return 0;

    RGE_Time_Entry* node = this->add(time);
    if (node != 0) {
        RGE_Time_Entry* cur = this->time_list;
        while (cur != 0) {
            if (obj == cur->this_obj) {
                unsigned char cmd = cur->command;
                cur->this_obj = 0;
                if (cmd == 1)
                    node->this_obj_id = cur->this_obj_id;
            }
            if (obj == cur->target_obj)
                cur->target_obj = 0;
            cur = cur->next;
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

// 0050DFD0 RGE_Timeline::sub(RGE_Time_Entry*)
void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry* p = this->time_list;
    RGE_Time_Entry** link = &this->time_list;
    if (p != 0) {
        for (; p != 0 && p != entry; ) {
            link = &p->next;
            p = p->next;
            if (p == 0)
                return;
        }
        *link = p->next;
        if (p->command == 1) {
            entry = this->time_list;
            while (entry != 0)
                entry = entry->next;
        }
        this->sub(entry);
        free(p);
        this->list_num--;
    }
}
