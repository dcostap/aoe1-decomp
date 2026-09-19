
#include "../include/misl_obj.h"
#include "../include/game_globals.h"
#include "../include/act_list.h"
#include "../include/act_misl.h"
#include "../include/m_co_obj.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/world.h"

#include <stdlib.h>


RGE_Missile_Object::RGE_Missile_Object(
    RGE_Master_Combat_Object* tobj, RGE_Player* obj_owner,
    float x, float y, float z, int do_setup)
    : RGE_Combat_Object(tobj, obj_owner, x, y, z, 0) {
    if (do_setup != 0) {
        this->setup(tobj, obj_owner, x, y, z);
    }
    this->type = 0x3C;
}

RGE_Missile_Object::RGE_Missile_Object(
    int infile, RGE_Game_World* gworld, int do_setup)
    : RGE_Combat_Object(infile, gworld, 0) {
    if (do_setup != 0) {
        this->setup(infile, gworld);
    }
    this->type = 0x3C;
}

int RGE_Missile_Object::setup(
    RGE_Master_Combat_Object* tobj, RGE_Player* obj_owner,
    float x, float y, float z) {
    RGE_Combat_Object::setup(tobj, obj_owner, x, y, z);
    this->type = 0x3C;
    return 1;
}

int RGE_Missile_Object::setup(int infile, RGE_Game_World* gworld) {
    RGE_Combat_Object::setup(infile, gworld);
    this->type = 0x3C;
    if (save_game_version > 7.09f) {
        rge_read(infile, &this->max_range, 4);
    } else {
        this->max_range = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_range;
    }
    return 1;
}

void RGE_Missile_Object::rehook() {
    RGE_Action_Object::rehook();
}

void RGE_Missile_Object::save(int outfile) {
    RGE_Combat_Object::save(outfile);
    rge_write(outfile, &this->max_range, 4);
}

unsigned char RGE_Missile_Object::update() {
    return RGE_Combat_Object::update();
}

void RGE_Missile_Object::init_missile(
    RGE_Combat_Object* launcher, RGE_Static_Object* target, float in_range) {
    RGE_Action_Missile* action = new RGE_Action_Missile(static_cast<RGE_Action_Object*>(this), launcher, target,
                                                        target->world_x, target->world_y, target->world_z);
    if (action != 0) {
        this->actions->add_action(action);
    }
    this->max_range = in_range;
}

void RGE_Missile_Object::init_missile(
    RGE_Combat_Object* launcher, float x, float y, float z, float in_range) {
    RGE_Action_Missile* action = new RGE_Action_Missile(static_cast<RGE_Action_Object*>(this), launcher, 0, x, y, z);
    if (action != 0) {
        this->actions->add_action(action);
    }
    this->max_range = in_range;
}

unsigned char RGE_Missile_Object::missile_move() {
    float new_x;
    float new_y;
    float new_z;

    new_x = this->world_x + this->velocity_x;
    new_y = this->world_y + this->velocity_y;
    new_z = this->world_z + this->velocity_z;

    if (new_x < g_missile_zero_float || new_x >= (float)this->owner->world->map->map_width || new_y < g_missile_zero_float ||
        new_y >= (float)this->owner->world->map->map_height) {
        this->die_die_die();
    }

    return this->teleport(new_x, new_y, new_z) == this->world_z;
}

RGE_Check_List* RGE_Missile_Object::make_object_collision_list(float delta) {
    float dx;
    float dy;
    float rx;
    float ry;
    float rx2;
    float ry2;
    short min_x;
    short min_y;
    short x1;
    short max_y;
    RGE_Map* map;
    RGE_Check_List* check_list;

    rx = this->master_obj->radius_x;
    ry = this->master_obj->radius_y;
    if (rx <= g_missile_zero_float || ry <= g_missile_zero_float) {
        return 0;
    }

    min_x = (short)(int)(this->world_x - g_missile_bounds_min_adjustment);
    min_y = (short)(int)(this->world_y - g_missile_bounds_min_adjustment);
    x1 = (short)(int)(this->world_x - g_missile_bounds_max_adjustment);
    max_y = (short)(int)(this->world_y - g_missile_bounds_max_adjustment);

    map = this->owner->world->map;
    check_list = new RGE_Check_List;

    if (min_x < 0) {
        min_x = 0;
    }
    if ((int)x1 >= map->map_width) {
        x1 = (short)(map->map_width - 1);
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if ((int)max_y >= map->map_height) {
        max_y = (short)(map->map_height - 1);
    }

    for (short row = min_y; row <= max_y; ++row) {
        RGE_Tile* tile = map->map_row_offset[row] + min_x;
        for (short column = min_x; column <= x1; ++column) {
            RGE_Object_Node* node = tile->objects.list;

            while (node != 0) {
                RGE_Static_Object* object = node->node;
                if (object != this) {
                    RGE_Master_Static_Object* object_master = object->master_obj;
                    ry2 = object_master->radius_y;
                    rx2 = object_master->radius_x;
                    if (ry2 > 0.0f && rx2 > 0.0f) {
                        float dz = object->world_z - this->world_z;
                        if (dz >= -(object_master->radius_z - g_missile_vertical_adjustment) &&
                            dz <= this->master_obj->radius_z - g_missile_vertical_adjustment) {
                            dx = object->world_x - this->world_x;
                            dy = object->world_y - this->world_y;
                            if (dx < g_missile_zero_float) {
                                dx = -dx;
                            }
                            if (dy < g_missile_zero_float) {
                                dy = -dy;
                            }
                            dx = dx - (rx2 + rx + delta);
                            dy = dy - (ry2 + ry + delta);
                            if (dx <= g_missile_zero_float && dy <= g_missile_zero_float) {
                                check_list->add_node(object, dx, dy, 0);
                            }
                        }
                    }
                }
                node = node->next;
            }
            ++tile;
        }
    }

    if (check_list->list == 0) {
        delete check_list;
        check_list = 0;
    }
    return check_list;
}
