#include "../include/obj_list.h"

#include <stdlib.h>

RGE_Object_List::RGE_Object_List() {
    list = 0;
    number_of_objects = 0;
}

RGE_Object_List::~RGE_Object_List() {
    RGE_Object_Node* node;

    node = this->list;
    while (node != 0) {
        RGE_Object_Node* next = node->next;
        if (node->object != 0) {
            node->object->destroy(1);
        }
        node = next;
    }

    node = this->list;
    while (node != 0) {
        node = this->list->next;
        free(node);
        this->list = node;
    }

    this->number_of_objects = 0;
}

void RGE_Object_List::removeAllObjects() {
    RGE_Object_Node* node = this->list;

    while (node != 0) {
        RGE_Object_Node* next = node->next;
        if (node->object != 0) {
            node->object->destroy(1);
        }
        node = next;
    }
    this->list = 0;
    this->number_of_objects = 0;
}

RGE_Object_Node* RGE_Object_List::add_node(RGE_Static_Object* object) {
    RGE_Object_Node* node;

    node = (RGE_Object_Node*)calloc(1, 0x10);
    node->next = this->list;
    node->prev = 0;
    if (this->list != 0) {
        this->list->prev = node;
    }
    node->node = object;
    this->number_of_objects++;
    this->list = node;
    return node;
}

void RGE_Object_List::remove_node(RGE_Static_Object* object,
                                  RGE_Object_Node* node) {
    RGE_Object_Node* current = this->list;
    if (current == 0) {
        return;
    }
    if (node == 0) {
        RGE_Static_Object* target = object;
        while (current->node != target) {
            current = current->next;
            if (current == 0) {
                return;
            }
        }
    } else {
        current = node;
    }
    if (current->prev != 0) {
        current->prev->next = current->next;
    } else {
        this->list = current->next;
    }
    if (current->next != 0) {
        current->next->prev = current->prev;
    }
    free(current);
    --this->number_of_objects;
}

void RGE_Object_List::invert() {
    RGE_Object_Node* prev = 0;
    RGE_Object_Node* node = this->list;

    while (node != 0) {
        this->list = node->next;
        node->next = prev;
        if (prev != 0) {
            prev->prev = node;
        }
        prev = node;
        node->prev = 0;
        node = this->list;
    }
    this->list = prev;
}

void RGE_Object_List::draw(TDrawArea* draw_area, short x, short y,
                           unsigned char fog) {
    RGE_Object_Node* node = list;
    if (!node) {
        return;
    }
    do {
        RGE_Object_Draw_View* object = (RGE_Object_Draw_View*)node->node;
        if (object) {
            RGE_Player* owner = object->owner;
            unsigned char should_draw = 1;
            void* color_table = owner->color_table;
            switch (object->master_obj->fog_flag) {
            case 0:
                if (fog) {
                    should_draw = 0;
                }
                break;
            case 1:
                break;
            case 2:
                if (fog && object->object_state > 2) {
                    should_draw = 0;
                }
                break;
            case 3:
                should_draw = 0;
                if (fog) {
                    RGE_Game_World* world = owner->world;
                    short player_id = owner->id;
                    short current_player = world->curr_player;
                    RGE_Player* current = world->players[current_player];
                    if (*(int*)((unsigned char*)current + player_id * 4 + 0xAC)) {
                        color_table = object->ally_color_table;
                        should_draw = 1;
                    }
                }
                break;
            case 4:
                if (fog && number_of_objects > 1) {
                    for (RGE_Object_Node* current = list; current;
                         current = current->next) {
                        if (current->node->type == 0x19) {
                            should_draw = 0;
                            break;
                        }
                    }
                }
                break;
            }
            if (should_draw) {
                object->draw(draw_area, x, y, color_table);
            }
        }
        node = node->next;
    } while (node);
}

void RGE_Object_List::shadow_draw(TDrawArea* draw_area, short x, short y,
                                  unsigned char parameter, unsigned char fog) {
    RGE_Object_Node* node = this->list;

    if (fog) {
        while (node) {
            RGE_Static_Object* object = node->node;
            if (object) {
                if (object->master_obj->fog_flag) {
                    object->shadow_draw(draw_area, x, y, parameter);
                }
            }
            node = node->next;
        }
    } else {
        while (node) {
            RGE_Static_Object* object = node->node;
            if (object) {
                object->shadow_draw(draw_area, x, y, parameter);
            }
            node = node->next;
        }
    }
}

void RGE_Object_List::normal_draw(TDrawArea* draw_area, short x, short y,
                                  unsigned char fog) {
    RGE_Object_Node* sorted = this->sort();
    RGE_Object_Node* node = sorted;

    if (fog) {
        while (node) {
            RGE_Static_Object* object = node->node;
            if (object && object->master_obj->fog_flag) {
                object->normal_draw(draw_area, x, y);
            }
            node = node->next;
        }
    } else {
        while (node) {
            RGE_Static_Object* object = node->node;
            if (object) {
                object->normal_draw(draw_area, x, y);
            }
            node = node->next;
        }
    }

    while (sorted) {
        RGE_Object_Node* next = sorted->next;
        free(sorted);
        sorted = next;
    }
}

class TMousePointer {
public:
    void Poll();
};

extern TMousePointer* MouseSystem;

void RGE_Object_List::update() {
    RGE_Object_Node* node = this->list;
    int count = 0;

    while (node != 0) {
        RGE_Object_Node* next = node->next;
        if (node->node != 0) {
            unsigned char update_result = node->node->update();
            if (update_result != 0) {
                node->node->recycle_out_of_game();
            }
            count = count + 1;
            if (9 < count) {
                count = 0;
                if (MouseSystem != 0) {
                    MouseSystem->Poll();
                }
            }
        }
        node = next;
    }
}

RGE_Object_Node* RGE_Object_List::sort() {
    register RGE_Object_Node* node;
    RGE_Object_Node* sorted;
    RGE_Object_Node** insertion;
    RGE_Object_Node* scan;

    sorted = 0;
    node = this->list;
    if (node != 0) {
        do {
            insertion = &sorted;
            RGE_Static_Object* current_object = node->node;
            short current_y = current_object->screen_y_offset;
            unsigned char current_sort = current_object->master_obj->sort_number;
            for (scan = sorted; scan != 0; scan = scan->next) {
                RGE_Static_Object* scanned_object = scan->node;
                unsigned char scanned_sort = scanned_object->master_obj->sort_number;
                if ((scanned_sort < current_sort) ||
                    (scanned_sort == current_sort &&
                     scanned_object->screen_y_offset > current_y)) {
                    break;
                }
                insertion = &scan->next;
            }

            scan = (RGE_Object_Node*)calloc(1, 0x10);
            scan->next = *insertion;
            if (*insertion != 0) {
                scan->prev = (*insertion)->prev;
                (*insertion)->prev = scan;
            }
            scan->node = node->node;
            *insertion = scan;

            node = node->next;
        } while (node != 0);
    }

    return sorted;
}

RGE_Static_Object* RGE_Object_List::find_by_group(long group) {
    RGE_Object_Node* node = this->list;
    if (node == 0) {
        return 0;
    }

    while (node != 0) {
        if (node->object != 0) {
            if ((long)node->object->master_obj->object_group == group) {
                return node->object;
            }
        }
        node = node->next;
    }
    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_group(
    long group, float x, float y, unsigned char check_player,
    unsigned char player_id, RGE_Static_Object* zone_object) {
    int zone;
    RGE_Object_Node* node;
    RGE_Static_Object* found;
    float best_distance;

    if (x > -1.0f && y > -1.0f && zone_object != 0) {
        zone = zone_object->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    node = this->first;
    found = 0;
    best_distance = -1.0f;
    while (node != 0) {
        RGE_Static_Object* object = node->object;
        if (object != 0) {
            if ((long)object->master_obj->object_group == group) {
                if (!check_player || object->player_id == player_id) {
                    if (x == -1.0f || y == -1.0f) {
                        return node->object;
                    }
                    if (zone > -1) {
                        if ((zone_object->lookupZone((int)object->x,
                                                    (int)object->y) & 0xff) != zone) {
                            goto next_group_node;
                        }
                    }
                    RGE_Static_Object* current = node->object;
                    float dx = x - current->x;
                    float dy = y - current->y;
                    float distance = dx * dx + dy * dy;
                    if (best_distance == -1.0f || best_distance > distance) {
                        best_distance = distance;
                        found = current;
                    }
                }
            }
        }
next_group_node:
        node = node->next;
    }

    return found;
}

RGE_Static_Object* RGE_Object_List::find_by_id(long target_id) {
    RGE_Object_Node* node = this->list;
    if (node == 0) {
        return 0;
    }

    while (node) {
        if (node->node != 0 && node->node->id == target_id) {
            return node->node;
        }
        node = node->next;
    }

    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_master_id(
    long master_id, float x, float y, unsigned char use_state,
    unsigned char state, RGE_Static_Object* zone_object) {
    int zone;
    RGE_Object_Node* node;
    RGE_Static_Object* found;
    float best_distance;

    if (x > -1.0f && y > -1.0f && zone_object != 0) {
        zone = zone_object->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    node = this->list;
    found = 0;
    best_distance = -1.0f;
    while (node != 0) {
        RGE_Static_Object* object = node->object;
        if (object != 0) {
            if (object->master->id == master_id) {
                if (!use_state || object->object_state == state) {
                    if (x == -1.0f || y == -1.0f) {
                        return node->object;
                    }
                    if (zone > -1) {
                        if ((zone_object->lookupZone((int)object->world_x,
                                                    (int)object->world_y) & 0xff) != zone) {
                            goto next_master_node;
                        }
                    }
                    RGE_Static_Object* current = node->object;
                    float dx = x - current->world_x;
                    float dy = y - current->world_y;
                    float distance = dx * dx + dy * dy;
                    if (best_distance == -1.0f || best_distance > distance) {
                        best_distance = distance;
                        found = current;
                    }
                }
            }
        }
next_master_node:
        node = node->next;
    }

    return found;
}

RGE_Static_Object* RGE_Object_List::find_by_master_ids(
    long first_id, long second_id, float x, float y,
    unsigned char check_player, unsigned char player_id,
    RGE_Static_Object* zone_object) {
    int zone;
    RGE_Object_Node* node;
    RGE_Static_Object* found;
    float best_distance;

    if (zone_object != 0 && x > -1.0f && y > -1.0f) {
        zone = zone_object->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    node = this->first;
    found = 0;
    best_distance = -1.0f;
    while (node != 0) {
        RGE_Static_Object* object = node->object;
        long master_id = object->master_obj->id;
        if (object != 0) {
            if (master_id == first_id || master_id == second_id) {
                if (!check_player || object->player_id == player_id) {
                    if (x == -1.0f && y == -1.0f) {
                        return node->object;
                    }
                    if (zone > -1) {
                        if ((zone_object->lookupZone((int)object->x,
                                                    (int)object->y) & 0xff) != zone) {
                            goto next_master_ids_node;
                        }
                    }
                    RGE_Static_Object* current = node->object;
                    float dx = x - current->x;
                    float dy = y - current->y;
                    float distance = dx * dx + dy * dy;
                    if (best_distance == -1.0f || best_distance > distance) {
                        best_distance = distance;
                        found = current;
                    }
                }
            }
        }
next_master_ids_node:
        node = node->next;
    }

    return found;
}

RGE_Static_Object* RGE_Object_List::find_by_type(
    unsigned char type, float x, float y, unsigned char check_state,
    unsigned char state) {
    float best_distance = -1.0f;
    RGE_Static_Object* best_object = 0;
    RGE_Object_Node* node = this->list;

    while (node != 0) {
        RGE_Static_Object* object = node->obj;
        if (object != 0 && object->type == type &&
            (!check_state || object->object_state == state)) {
            if (x == -1.0f && y == -1.0f) {
                return node->obj;
            }

            float dx = x - object->world_x;
            float dy = y - object->world_y;
            float distance = dx * dx + dy * dy;

            if (best_distance == -1.0f || best_distance > distance) {
                best_distance = distance;
                best_object = object;
            }
        }
        node = node->next;
    }

    return best_object;
}

extern void rge_write(int file, void* data, int size);

void RGE_Object_List::save(int file) {
    unsigned char finished;
    RGE_Object_Node* node = this->list;

    finished = 0;
    while (node != 0) {
        if (node->node != 0) {
            node->node->save(file);
        }
        node = node->next;
    }

    rge_write(file, &finished, 1);
}

extern void rge_read(int file, void* data, int size);

void RGE_Object_List::load_list(int file, RGE_Game_World* world) {
    unsigned char type;

    while (1) {
        rge_read(file, &type, 1);
        if (type == 0) {
            break;
        }
        this->load(type, file, world);
    }
    this->invert();
}

void RGE_Object_List::rehook_list() {
    RGE_Object_Node* node;

    node = this->list;
    while (node != 0) {
        node->node->rehook();
        node = node->next;
    }
}

void RGE_Object_List::load(unsigned char type, int mode,
                           RGE_Game_World* world) {
    switch (type) {
    case 10:
        new RGE_Static_Object(mode, world, 1);
        return;
    case 20:
        new RGE_Animated_Object(mode, world, 1);
        return;
    case 25:
        new RGE_Doppleganger_Object(mode, world, 1);
        return;
    case 30:
        new RGE_Moving_Object(mode, world, 1);
        return;
    case 60:
        new RGE_Missile_Object(mode, world, 1);
        return;
    case 40:
        new RGE_Action_Object(mode, world, 1);
        return;
    case 50:
        new RGE_Combat_Object(mode, world, 1);
        return;
    }
}
