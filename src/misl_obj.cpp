
#include "../include/misl_obj.h"
#include "../include/act_list.h"
#include "../include/act_misl.h"
#include "../include/m_co_obj.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/world.h"

#include <stdlib.h>

extern float save_game_version;
extern float DAT_00570934;
extern float DAT_00570938;
extern float DAT_0057093c;
extern float DAT_00570940;

RGE_Missile_Object::RGE_Missile_Object(
    RGE_Master_Combat_Object* master, RGE_Player* player,
    float x, float y, float z, int do_setup)
    : RGE_Combat_Object(master, player, x, y, z, 0) {
    if (do_setup != 0) {
        this->setup(master, player, x, y, z);
    }
    this->type = 0x3C;
}

RGE_Missile_Object::RGE_Missile_Object(
    int mode, RGE_Game_World* world, int do_setup)
    : RGE_Combat_Object(mode, world, 0) {
    if (do_setup != 0) {
        this->setup(mode, world);
    }
    this->type = 0x3C;
}

int RGE_Missile_Object::setup(
    RGE_Master_Combat_Object* master, RGE_Player* player,
    float x, float y, float z) {
    RGE_Combat_Object::setup(master, player, x, y, z);
    this->type = 0x3C;
    return 1;
}

int RGE_Missile_Object::setup(int file, RGE_Game_World* world) {
    RGE_Combat_Object::setup(file, world);
    this->type = 0x3C;
    if (save_game_version > 7.09f) {
        rge_read(file, &this->max_range, 4);
    } else {
        this->max_range = static_cast<RGE_Master_Combat_Object*>(
            this->master_obj)->weapon_range;
    }
    return 1;
}

void RGE_Missile_Object::rehook() {
    RGE_Action_Object::rehook();
}

void RGE_Missile_Object::save(int file) {
    RGE_Combat_Object::save(file);
    rge_write(file, &this->max_range, 4);
}

unsigned char RGE_Missile_Object::update() {
    return RGE_Combat_Object::update();
}

void RGE_Missile_Object::init_missile(
    RGE_Combat_Object* target, RGE_Static_Object* source, float range) {
    RGE_Action_Missile* action = new RGE_Action_Missile(
        static_cast<RGE_Action_Object*>(this), target, source,
        source->world_x, source->world_y, source->world_z);
    if (action != 0) {
        this->actions->add_action(action);
    }
    this->max_range = range;
}

void RGE_Missile_Object::init_missile(
    RGE_Combat_Object* target, float x, float y, float z, float range) {
    RGE_Action_Missile* action = new RGE_Action_Missile(
        static_cast<RGE_Action_Object*>(this), target, 0, x, y, z);
    if (action != 0) {
        this->actions->add_action(action);
    }
    this->max_range = range;
}

unsigned char RGE_Missile_Object::missile_move() {
    float new_x;
    float new_y;
    float new_z;
    int result;

    new_x = this->world_x + this->velocity_x;
    new_y = this->world_y + this->velocity_y;
    new_z = this->world_z + this->velocity_z;

    if (new_x < 0.0f ||
        (float)this->owner->world->map->map_width <= new_x ||
        new_y < 0.0f ||
        (float)this->owner->world->map->map_height <= new_y) {
        this->die_die_die();
    }

    if (this->teleport(new_x, new_y, new_z) == this->world_z) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

RGE_Check_List* RGE_Missile_Object::make_object_collision_list(float extra) {
    float dx;
    float dy;
    float rx;
    float ry;
    float rx2;
    float ry2;
    short min_x;
    short min_y;
    short max_x;
    short max_y;
    RGE_Map* map;
    RGE_Check_List* list;

    rx = this->master_obj->radius_x;
    ry = this->master_obj->radius_y;
    if (rx <= DAT_00570934 || ry <= DAT_00570934) {
        return 0;
    }

    min_x = (short)(int)(this->world_x - DAT_00570938);
    min_y = (short)(int)(this->world_y - DAT_00570938);
    max_x = (short)(int)(this->world_x - DAT_0057093c);
    max_y = (short)(int)(this->world_y - DAT_0057093c);

    map = this->owner->world->map;
    list = new RGE_Check_List;

    if (min_x < 0) {
        min_x = 0;
    }
    if ((int)max_x >= map->map_width) {
        max_x = (short)(map->map_width - 1);
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if ((int)max_y >= map->map_height) {
        max_y = (short)(map->map_height - 1);
    }

    for (short row = min_y; row <= max_y; ++row) {
        for (short column = min_x; column <= max_x; ++column) {
            RGE_Tile* tile = &map->map_row_offset[row][column];
            RGE_Object_Node* node = tile->objects.list;

            while (node != 0) {
                RGE_Static_Object* object = node->node;
                if (object != this) {
                    RGE_Master_Static_Object* object_master = object->master_obj;
                    ry2 = object_master->radius_y;
                    rx2 = object_master->radius_x;
                    if (ry2 > 0.0f && rx2 > 0.0f) {
                        float dz = object->world_z - this->world_z;
                        if (dz >= -(object_master->radius_z - DAT_00570940) &&
                            dz <= this->master_obj->radius_z - DAT_00570940) {
                            dx = object->world_x - this->world_x;
                            dy = object->world_y - this->world_y;
                            if (dx < DAT_00570934) {
                                dx = -dx;
                            }
                            if (dy < DAT_00570934) {
                                dy = -dy;
                            }
                            dx = dx - (rx2 + rx + extra);
                            dy = dy - (ry2 + ry + extra);
                            if (dx <= DAT_00570934 && dy <= DAT_00570934) {
                                list->add_node(object, dx, dy, 0);
                            }
                        }
                    }
                }
                node = node->next;
            }
        }
    }

    if (list->list == 0) {
        delete list;
        list = 0;
    }
    return list;
}
