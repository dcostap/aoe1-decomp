#include "../include/RGE_Missile_Object.h"
#include "../include/RGE_Action_Missile.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Check_List.h"
#include "../include/RGE_Check_Node.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Player.h"
#include "../include/globals.h"

#include <math.h>
#include <new>

// Default constructor
RGE_Missile_Object::RGE_Missile_Object()
    : RGE_Combat_Object()
{
    this->max_range = 0.0f;
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045A740
RGE_Missile_Object::RGE_Missile_Object(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4,
                                        float param_5, int param_6)
    : RGE_Combat_Object(param_1, param_2, param_3, param_4, param_5, 0)
{
    this->max_range = 0.0f;

    if (param_6 != 0) {
        this->setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);
    }

    this->type = 0x3C;
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045A800
RGE_Missile_Object::RGE_Missile_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Combat_Object(param_1, param_2, 0)
{
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
    this->type = 0x3C;
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045A8A0, misl_obj.cpp.asm @ 0x0045A8A0
int RGE_Missile_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Combat_Object::setup(param_1, param_2);
    this->type = 0x3C;

    if (save_game_version > 7.09f) {
        rge_read(param_1, &this->max_range, 4);
        return 1;
    }

    // Older save versions: get max_range from master_obj->weapon_range (offset 0x114)
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master != nullptr) {
        this->max_range = master->weapon_range;
    }

    return 1;
}

RGE_Missile_Object::~RGE_Missile_Object() {
}

// Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00463000, obj_list.cpp.asm @ 0x00463055
void RGE_Missile_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4) {
    RGE_Combat_Object::draw(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00463100, obj_list.cpp.asm @ 0x00463139
void RGE_Missile_Object::shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4) {
    RGE_Combat_Object::shadow_draw(param_1, param_2, param_3, param_4);
}

// Fully verified. Source of truth: obj_list.cpp.decomp @ 0x00463180, obj_list.cpp.asm @ 0x004631BA
void RGE_Missile_Object::normal_draw(TDrawArea* param_1, short param_2, short param_3) {
    RGE_Combat_Object::normal_draw(param_1, param_2, param_3);
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045A870
int RGE_Missile_Object::setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    RGE_Combat_Object::setup(param_1, param_2, param_3, param_4, param_5);
    this->type = 0x3C;
    return 1;
}

int RGE_Missile_Object::setup(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    // Forward to the canonical missile setup (typed by decomp as RGE_Master_Combat_Object*).
    return this->setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);
}

int RGE_Missile_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4,
                              float param_5) {
    // Keep behavior consistent regardless of which setup overload is used.
    RGE_Combat_Object::setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);
    this->type = 0x3C;
    return 1;
}

// Fully verified. Source of truth: misl_obj.cpp.asm @ 0x0045A900
void RGE_Missile_Object::rehook() {
    RGE_Action_Object::rehook();
}

// Fully verified. Source of truth: misl_obj.cpp.asm @ 0x0045A910
void RGE_Missile_Object::save(int param_1) {
    RGE_Combat_Object::save(param_1);
    rge_write(param_1, &this->max_range, 4);
}

// Fully verified. Source of truth: misl_obj.cpp.asm @ 0x0045A940
uchar RGE_Missile_Object::update() {
    return RGE_Combat_Object::update();
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045A950, misl_obj.cpp.asm @ 0x0045A950
void RGE_Missile_Object::init_missile(RGE_Combat_Object* param_1, RGE_Static_Object* param_2, float param_3) {
    RGE_Action_Missile* action = new (std::nothrow)
        RGE_Action_Missile((RGE_Action_Object*)this, (RGE_Static_Object*)param_1, param_2, param_2->world_x, param_2->world_y, param_2->world_z);
    if (action != nullptr) {
        this->actions->add_action(action);
    }
    this->max_range = param_3;
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045A9E0, misl_obj.cpp.asm @ 0x0045A9E0
void RGE_Missile_Object::init_missile(RGE_Combat_Object* param_1, float param_2, float param_3, float param_4, float param_5) {
    RGE_Action_Missile* action = new (std::nothrow)
        RGE_Action_Missile((RGE_Action_Object*)this, (RGE_Static_Object*)param_1, nullptr, param_2, param_3, param_4);
    if (action != nullptr) {
        this->actions->add_action(action);
    }
    this->max_range = param_5;
}

// Fully verified. Source of truth: misl_obj.cpp.asm @ 0x0045AA70
uchar RGE_Missile_Object::missile_move() {
    float new_x = this->world_x + this->velocity_x;
    float new_y = this->world_y + this->velocity_y;
    float new_z = this->world_z + this->velocity_z;

    RGE_Map* map = this->owner->world->map;
    if ((new_x < 0.0f) || ((float)map->map_width <= new_x) || (new_y < 0.0f) || ((float)map->map_height <= new_y)) {
        this->die_die_die();
    }

    float terrain_height = this->teleport(new_x, new_y, new_z);
    return (terrain_height == this->world_z) ? 1 : 0;
}

// Fully verified. Source of truth: misl_obj.cpp.decomp @ 0x0045AB20
RGE_Check_List* RGE_Missile_Object::make_object_collision_list(float param_1) {
    RGE_Master_Static_Object* master = this->master_obj;
    float my_rx = master->radius_x;
    float my_ry = master->radius_y;
    float my_rz = master->radius_z;
    if (my_rx <= 0.0f || my_ry <= 0.0f) {
        return nullptr;
    }

    RGE_Map* map = this->owner->world->map;

    float pad_x = my_rx + param_1;
    float pad_y = my_ry + param_1;

    int x0 = (int)(this->world_x - pad_x);
    int x1 = (int)(this->world_x + pad_x);
    int y0 = (int)(this->world_y - pad_y);
    int y1 = (int)(this->world_y + pad_y);

    if (x0 < 0) {
        x0 = 0;
    }
    if (x1 >= map->map_width) {
        x1 = map->map_width - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (y1 >= map->map_height) {
        y1 = map->map_height - 1;
    }

    RGE_Check_List* check_list = (RGE_Check_List*)operator new(sizeof(RGE_Check_List));
    if (check_list == nullptr) {
        return nullptr;
    }
    check_list->list = nullptr;

    for (int y = y0; y <= y1; ++y) {
        for (int x = x0; x <= x1; ++x) {
            RGE_Tile* tile = &map->map_row_offset[y][x];
            for (RGE_Object_Node* node = tile->objects.list; node != nullptr; node = node->next) {
                RGE_Static_Object* obj = node->node;
                if (obj == nullptr || obj == this) {
                    continue;
                }

                RGE_Master_Static_Object* obj_master = obj->master_obj;
                if (obj_master == nullptr || obj_master->radius_x <= 0.0f || obj_master->radius_y <= 0.0f) {
                    continue;
                }

                float dz = obj->world_z - this->world_z;
                if (dz < -(obj_master->radius_z + 0.1f) || dz > (my_rz + 0.1f)) {
                    continue;
                }

                float dx = obj->world_x - this->world_x;
                float dy = obj->world_y - this->world_y;
                float adx = (dx < 0.0f) ? -dx : dx;
                float ady = (dy < 0.0f) ? -dy : dy;

                float sep_x = adx - (obj_master->radius_x + my_rx + param_1);
                float sep_y = ady - (obj_master->radius_y + my_ry + param_1);
                if (sep_x <= 0.0f && sep_y <= 0.0f) {
                    RGE_Check_Node* new_node = (RGE_Check_Node*)operator new(sizeof(RGE_Check_Node));
                    if (new_node != nullptr) {
                        new_node->node = obj;
                        new_node->dx = sep_x;
                        new_node->dy = sep_y;
                        new_node->flag = 0;
                        new_node->next = check_list->list;
                        check_list->list = new_node;
                    }
                }
            }
        }
    }

    if (check_list->list == nullptr) {
        operator delete(check_list);
        return nullptr;
    }

    return check_list;
}
