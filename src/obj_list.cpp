#include "../include/act_obj.h"
#include "../include/ani_obj.h"
#include "../include/dpl_obj.h"
#include "../include/m_s_obj.h"
#include "../include/misl_obj.h"
#include "../include/Mouseptr.h"
#include "../include/obj_list.h"
#include "../include/player.h"
#include "../include/stat_obj.h"
#include "../include/world.h"

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
        RGE_Static_Object* object = node->node;
        if (object != 0) {
            delete object;
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
        RGE_Static_Object* object = node->node;
        if (object != 0) {
            delete object;
        }
        node = next;
    }
    this->list = 0;
    this->number_of_objects = 0;
}

RGE_Object_Node* RGE_Object_List::add_node(RGE_Static_Object* obj) {
    RGE_Object_Node* node;

    node = (RGE_Object_Node*)calloc(1, 16);
    node->next = this->list;
    node->prev = 0;
    if (this->list != 0) {
        this->list->prev = node;
    }
    node->node = obj;
    this->number_of_objects++;
    this->list = node;
    return node;
}

void RGE_Object_List::remove_node(RGE_Static_Object* obj,
                                  RGE_Object_Node* node) {
    RGE_Object_Node* current = this->list;
    if (current == 0) {
        return;
    }
    if (node == 0) {
        RGE_Static_Object* target = obj;
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

void RGE_Object_List::draw(TDrawArea* render_area, short x, short y,
                           unsigned char fogged_tile) {
    RGE_Object_Node* node = list;
    if (!node) {
        return;
    }
    do {
        RGE_Static_Object* object = node->node;
        if (object) {
            RGE_Player* owner = object->owner;
            unsigned char should_draw = 1;
            RGE_Color_Table* color_table = owner->color_table;
            switch (object->master_obj->fog_flag) {
            case 0:
                if (fogged_tile) {
                    should_draw = 0;
                }
                break;
            case 1:
                break;
            case 2:
                if (fogged_tile && object->object_state > 2) {
                    should_draw = 0;
                }
                break;
            case 3:
                should_draw = 0;
                if (fogged_tile) {
                    RGE_Game_World* world = owner->world;
                    short player_id = owner->id;
                    short current_player = world->curr_player;
                    RGE_Player* current = world->players[current_player];
                    if (current->mutualAlly[player_id]) {
                        color_table =
                            ((RGE_Doppleganger_Object*)object)->draw_color;
                        should_draw = 1;
                    }
                }
                break;
            case 4:
                if (fogged_tile && number_of_objects > 1) {
                    for (RGE_Object_Node* current = list; current; current = current->next) {
                        if (current->node->type == 0x19) {
                            should_draw = 0;
                            break;
                        }
                    }
                }
                break;
            }
            if (should_draw) {
                object->draw(render_area, x, y, color_table);
            }
        }
        node = node->next;
    } while (node);
}

void RGE_Object_List::shadow_draw(TDrawArea* render_area, short x, short y,
                                  unsigned char flag, unsigned char fog_flag) {
    RGE_Object_Node* node = this->list;

    if (fog_flag) {
        while (node) {
            RGE_Static_Object* object = node->node;
            if (object) {
                if (object->master_obj->fog_flag) {
                    object->shadow_draw(render_area, x, y, flag);
                }
            }
            node = node->next;
        }
    } else {
        while (node) {
            RGE_Static_Object* object = node->node;
            if (object) {
                object->shadow_draw(render_area, x, y, flag);
            }
            node = node->next;
        }
    }
}

void RGE_Object_List::normal_draw(TDrawArea* render_area, short x, short y,
                                  unsigned char fog_flag) {
    RGE_Object_Node* sorted = this->sort();
    RGE_Object_Node* node = sorted;

    if (fog_flag) {
        while (node) {
            RGE_Static_Object* object = node->node;
            if (object && object->master_obj->fog_flag) {
                object->normal_draw(render_area, x, y);
            }
            node = node->next;
        }
    } else {
        while (node) {
            RGE_Static_Object* object = node->node;
            if (object) {
                object->normal_draw(render_area, x, y);
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
                if ((scanned_sort < current_sort) || (scanned_sort == current_sort &&
                     scanned_object->screen_y_offset > current_y)) {
                    break;
                }
                insertion = &scan->next;
            }

            scan = (RGE_Object_Node*)calloc(1, 16);
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

RGE_Static_Object* RGE_Object_List::find_by_group(long id) {
    RGE_Object_Node* node = this->list;
    if (node == 0) {
        return 0;
    }

    while (node != 0) {
        if (node->node != 0) {
            if ((long)node->node->master_obj->object_group == id) {
                return node->node;
            }
        }
        node = node->next;
    }
    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_group(
    long id, float x, float y, unsigned char certain_state,
    unsigned char object_state, RGE_Static_Object* zone_obj) {
    int zone;
    RGE_Object_Node* node;
    RGE_Static_Object* found_obj;
    float dist;

    if (x > -1.0f && y > -1.0f && zone_obj != 0) {
        zone = zone_obj->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    node = this->list;
    found_obj = 0;
    dist = -1.0f;
    while (node != 0) {
        RGE_Static_Object* object = node->node;
        if (object != 0) {
            if ((long)object->master_obj->object_group == id) {
                if (!certain_state || object->object_state == object_state) {
                    if (x == -1.0f || y == -1.0f) {
                        return node->node;
                    }
                    if (zone > -1) {
                        if ((zone_obj->lookupZone((int)object->world_x, (int)object->world_y) & 0xff) != zone) {
                            goto next_group_node;
                        }
                    }
                    RGE_Static_Object* current = node->node;
                    float diff_x = x - current->world_x;
                    float dy = y - current->world_y;
                    float distance = diff_x * diff_x + dy * dy;
                    if (dist == -1.0f || dist > distance) {
                        dist = distance;
                        found_obj = current;
                    }
                }
            }
        }
next_group_node:
        node = node->next;
    }

    return found_obj;
}

RGE_Static_Object* RGE_Object_List::find_by_id(long id) {
    RGE_Object_Node* node = this->list;
    if (node == 0) {
        return 0;
    }

    while (node) {
        if (node->node != 0 && node->node->id == id) {
            return node->node;
        }
        node = node->next;
    }

    return 0;
}

RGE_Static_Object* RGE_Object_List::find_by_master_id(
    long id, float x, float y, unsigned char certain_state,
    unsigned char object_state, RGE_Static_Object* zone_obj) {
    int zone;
    RGE_Object_Node* node;
    RGE_Static_Object* found_obj;
    float dist;

    if (x > -1.0f && y > -1.0f && zone_obj != 0) {
        zone = zone_obj->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    node = this->list;
    found_obj = 0;
    dist = -1.0f;
    while (node != 0) {
        RGE_Static_Object* object = node->node;
        if (object != 0) {
            if (object->master_obj->id == id) {
                if (!certain_state || object->object_state == object_state) {
                    if (x == -1.0f || y == -1.0f) {
                        return node->node;
                    }
                    if (zone > -1) {
                        if ((zone_obj->lookupZone((int)object->world_x, (int)object->world_y) & 0xff) != zone) {
                            goto next_master_node;
                        }
                    }
                    RGE_Static_Object* current = node->node;
                    float diff_x = x - current->world_x;
                    float dy = y - current->world_y;
                    float distance = diff_x * diff_x + dy * dy;
                    if (dist == -1.0f || dist > distance) {
                        dist = distance;
                        found_obj = current;
                    }
                }
            }
        }
next_master_node:
        node = node->next;
    }

    return found_obj;
}

RGE_Static_Object* RGE_Object_List::find_by_master_ids(
    long id1, long id2, float x, float y,
    unsigned char certain_state, unsigned char object_state,
    RGE_Static_Object* zone_obj) {
    int zone;
    RGE_Object_Node* node;
    RGE_Static_Object* found_obj;
    float dist;

    if (zone_obj != 0 && x > -1.0f && y > -1.0f) {
        zone = zone_obj->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    node = this->list;
    found_obj = 0;
    dist = -1.0f;
    while (node != 0) {
        RGE_Static_Object* object = node->node;
        long master_id = object->master_obj->id;
        if (object != 0) {
            if (master_id == id1 || master_id == id2) {
                if (!certain_state || object->object_state == object_state) {
                    if (x == -1.0f && y == -1.0f) {
                        return node->node;
                    }
                    if (zone > -1) {
                        if ((zone_obj->lookupZone((int)object->world_x, (int)object->world_y) & 0xff) != zone) {
                            goto next_master_ids_node;
                        }
                    }
                    RGE_Static_Object* current = node->node;
                    float diff_x = x - current->world_x;
                    float dy = y - current->world_y;
                    float distance = diff_x * diff_x + dy * dy;
                    if (dist == -1.0f || dist > distance) {
                        dist = distance;
                        found_obj = current;
                    }
                }
            }
        }
next_master_ids_node:
        node = node->next;
    }

    return found_obj;
}

RGE_Static_Object* RGE_Object_List::find_by_type(
    unsigned char type, float x, float y, unsigned char certain_state,
    unsigned char object_state) {
    float dist = -1.0f;
    RGE_Static_Object* best_object = 0;
    RGE_Object_Node* node = this->list;

    while (node != 0) {
        RGE_Static_Object* object = node->node;
        if (object != 0 && object->type == type && (!certain_state || object->object_state == object_state)) {
            if (x == -1.0f && y == -1.0f) {
                return node->node;
            }

            float diff_x = x - object->world_x;
            float dy = y - object->world_y;
            float distance = diff_x * diff_x + dy * dy;

            if (dist == -1.0f || dist > distance) {
                dist = distance;
                best_object = object;
            }
        }
        node = node->next;
    }

    return best_object;
}

extern void rge_write(int file, void* data, int size);

void RGE_Object_List::save(int outfile) {
    unsigned char finished;
    RGE_Object_Node* node = this->list;

    finished = 0;
    while (node != 0) {
        if (node->node != 0) {
            node->node->save(outfile);
        }
        node = node->next;
    }

    rge_write(outfile, &finished, 1);
}

extern void rge_read(int file, void* data, int size);

void RGE_Object_List::load_list(int infile, RGE_Game_World* world) {
    unsigned char object_type;

    while (1) {
        rge_read(infile, &object_type, 1);
        if (object_type == 0) {
            break;
        }
        this->load(object_type, infile, world);
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

void RGE_Object_List::load(unsigned char object_type, int infile,
                           RGE_Game_World* world) {
    switch (object_type) {
    case 10:
        new RGE_Static_Object(infile, world, 1);
        return;
    case 20:
        new RGE_Animated_Object(infile, world, 1);
        return;
    case 25:
        new RGE_Doppleganger_Object(infile, world, 1);
        return;
    case 30:
        new RGE_Moving_Object(infile, world, 1);
        return;
    case 60:
        new RGE_Missile_Object(infile, world, 1);
        return;
    case 40:
        new RGE_Action_Object(infile, world, 1);
        return;
    case 50:
        new RGE_Combat_Object(infile, world, 1);
        return;
    }
}
