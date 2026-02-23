#include "../include/RGE_Action_Missile.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Check_List.h"
#include "../include/RGE_Check_Node.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Missile_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Tile.h"
#include "../include/globals.h"

#include <cmath>
#include <new>

namespace {
// Source of truth: stat_obj.cpp.decomp @ 0x004C5860
static uchar rge_static_object_is_dying(RGE_Static_Object* obj) {
    if ((obj != nullptr) && (2 < obj->object_state) && (obj->object_state != 6)) {
        return 1;
    }
    return 0;
}

static void rge_check_list_add_node(RGE_Check_List* list, RGE_Static_Object* obj, float dx, float dy, uchar flag) {
    if (list == nullptr) {
        return;
    }

    RGE_Check_Node* node = new (std::nothrow) RGE_Check_Node();
    if (node == nullptr) {
        return;
    }

    node->node = obj;
    node->dx = dx;
    node->dy = dy;
    node->flag = flag;
    node->next = list->list;
    list->list = node;
}

static void rge_check_list_delete(RGE_Check_List* list) {
    if (list == nullptr) {
        return;
    }

    RGE_Check_Node* cur = list->list;
    while (cur != nullptr) {
        RGE_Check_Node* next = cur->next;
        delete cur;
        cur = next;
    }
    delete list;
}

// Source of truth: misl_obj.cpp.decomp @ 0x0045AA70
static uchar rge_missile_move(RGE_Missile_Object* obj) {
    if ((obj == nullptr) || (obj->owner == nullptr) || (obj->owner->world == nullptr) || (obj->owner->world->map == nullptr)) {
        return 0;
    }

    float new_x = obj->world_x + obj->velocity_x;
    float new_y = obj->world_y + obj->velocity_y;
    float new_z = obj->world_z + obj->velocity_z;

    RGE_Map* map = obj->owner->world->map;
    if (((new_x < 0.0f) || ((float)map->map_width <= new_x)) || ((new_y < 0.0f) || ((float)map->map_height <= new_y))) {
        obj->die_die_die();
    }

    float ground_z = obj->teleport(new_x, new_y, new_z);
    return (ground_z == new_z) ? 1 : 0;
}

// Source of truth: misl_obj.cpp.decomp @ 0x0045AB20
static RGE_Check_List* rge_make_object_collision_list(RGE_Missile_Object* obj, float extra) {
    if ((obj == nullptr) || (obj->owner == nullptr) || (obj->owner->world == nullptr) || (obj->owner->world->map == nullptr) ||
        (obj->master_obj == nullptr)) {
        return nullptr;
    }

    float radius_x = obj->master_obj->radius_x;
    float radius_y = obj->master_obj->radius_y;
    if ((radius_x <= 0.0f) || (radius_y <= 0.0f)) {
        return nullptr;
    }

    int col0 = (int)(obj->world_x - (radius_x + extra));
    int col1 = (int)(obj->world_x + (radius_x + extra));
    int row0 = (int)(obj->world_y - (radius_y + extra));
    int row1 = (int)(obj->world_y + (radius_y + extra));

    RGE_Map* map = obj->owner->world->map;
    if (col0 < 0) {
        col0 = 0;
    }
    if (col1 >= map->map_width) {
        col1 = map->map_width - 1;
    }
    if (row0 < 0) {
        row0 = 0;
    }
    if (row1 >= map->map_height) {
        row1 = map->map_height - 1;
    }

    RGE_Check_List* check_list = new (std::nothrow) RGE_Check_List();
    if (check_list == nullptr) {
        return nullptr;
    }
    check_list->list = nullptr;

    for (int row = row0; row <= row1; ++row) {
        for (int col = col0; col <= col1; ++col) {
            RGE_Tile* tile = &map->map_row_offset[row][col];
            for (RGE_Object_Node* node = tile->objects.list; node != nullptr; node = node->next) {
                RGE_Static_Object* other = node->node;
                if ((other == nullptr) || (other == obj) || (other->master_obj == nullptr)) {
                    continue;
                }

                float other_rx = other->master_obj->radius_x;
                float other_ry = other->master_obj->radius_y;
                if ((other_rx <= 0.0f) || (other_ry <= 0.0f)) {
                    continue;
                }

                float dz = other->world_z - obj->world_z;
                if ((dz < -(other->master_obj->radius_z + 0.1f)) || (dz > (obj->master_obj->radius_z + 0.1f))) {
                    continue;
                }

                float dx = other->world_x - obj->world_x;
                float dy = other->world_y - obj->world_y;
                if (dx < 0.0f) {
                    dx = -dx;
                }
                if (dy < 0.0f) {
                    dy = -dy;
                }

                dx = dx - (other_rx + radius_x + extra);
                dy = dy - (other_ry + radius_y + extra);
                if ((dx <= 0.0f) && (dy <= 0.0f)) {
                    rge_check_list_add_node(check_list, other, dx, dy, 0);
                }
            }
        }
    }

    if (check_list->list == nullptr) {
        rge_check_list_delete(check_list);
        return nullptr;
    }

    return check_list;
}
}

// Fully verified. Source of truth: act_misl.cpp.decomp @ 0x00404BB0
RGE_Action_Missile::RGE_Action_Missile(int param_1, RGE_Action_Object* param_2) {
    this->setup(param_1, param_2);
}

// Fully verified. Source of truth: act_misl.cpp.decomp @ 0x00404C90
RGE_Action_Missile::RGE_Action_Missile(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3, float param_4, float param_5, float param_6) {
    this->setup(param_1);

    this->target_x = param_4;
    this->target_y = param_5;
    this->target_z = param_6;

    this->set_target_obj(param_3);
    this->set_target_obj2(param_2);
}

// Fully verified. Source of truth: bucket_0404.decomp @ 0x00404C80
RGE_Action_Missile::~RGE_Action_Missile() = default;

int RGE_Action_Missile::setup(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 8;
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->ballistic_velocity = 0.0f;
    this->ballistic_acceleration = 0.0f;
    return 1;
}

int RGE_Action_Missile::setup(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 8;
    rge_read(param_1, &this->velocity_x, 4);
    rge_read(param_1, &this->velocity_y, 4);
    rge_read(param_1, &this->velocity_z, 4);
    rge_read(param_1, &this->ballistic_velocity, 4);
    rge_read(param_1, &this->ballistic_acceleration, 4);
    return 1;
}

RGE_Action_List* RGE_Action_Missile::create_action_list(RGE_Action_Object* param_1) {
    return RGE_Action::create_action_list(param_1);
}

void RGE_Action_Missile::rehook() { RGE_Action::rehook(); }

// Fully verified. Source of truth: act_misl.cpp.decomp @ 0x004054B0
void RGE_Action_Missile::save(int param_1) {
    RGE_Action::save(param_1);
    rge_write(param_1, &this->velocity_x, 4);
    rge_write(param_1, &this->velocity_y, 4);
    rge_write(param_1, &this->velocity_z, 4);
    rge_write(param_1, &this->ballistic_velocity, 4);
    rge_write(param_1, &this->ballistic_acceleration, 4);
}

short RGE_Action_Missile::type() { return this->action_type; }

// Fully verified. Source of truth: act_misl.cpp.decomp @ 0x00404D10
void RGE_Action_Missile::first_in_stack(uchar param_1) {
    if (param_1 == 0) {
        this->set_state(4);
        return;
    }

    if ((this->target_obj == nullptr) && ((this->target_x == -1.0f) || (this->target_y == -1.0f))) {
        this->set_state(1);
        return;
    }

    this->set_state(3);
}

// Fully verified. Source of truth: act_misl.cpp.decomp @ 0x00404D50
void RGE_Action_Missile::intercept(float& param_1, float& param_2, float& param_3) {
    if (this->target_obj == nullptr) {
        param_1 = this->target_x;
        param_2 = this->target_y;
        param_3 = this->target_z;
        return;
    }

    param_1 = this->target_obj->world_x;
    param_2 = this->target_obj->world_y;

    float radius_z = 0.0f;
    if (this->target_obj->master_obj != nullptr) {
        radius_z = this->target_obj->master_obj->radius_z;
    }
    param_3 = (radius_z * 0.5f) + this->target_obj->world_z;
}

// Fully verified. Source of truth: act_misl.cpp.decomp @ 0x00404DB0
void RGE_Action_Missile::set_state(uchar param_1) {
    this->state = param_1;

    if (param_1 == 1) {
        if (this->obj != nullptr) {
            this->obj->die_die_die();
        }
        return;
    }

    if ((param_1 != 3) || (this->obj == nullptr) || (this->obj->master_obj == nullptr)) {
        return;
    }

    float tx = 0.0f;
    float ty = 0.0f;
    float tz = 0.0f;
    this->intercept(tx, ty, tz);

    float dx = tx - this->obj->world_x;
    float dy = ty - this->obj->world_y;
    float dz = tz - this->obj->world_z;
    float dz_sq = dz * dz;
    float speed = sqrtf(dy * dy + dx * dx + dz_sq);

    RGE_Master_Missile_Object* master = (RGE_Master_Missile_Object*)this->obj->master_obj;
    if ((master->targetting_type == 1) && (this->target_obj != nullptr) && (this->target_obj->getSpeed() > 0.0f)) {
        float target_speed = this->target_obj->getSpeed();

        if ((this->target_obj2 != nullptr) &&
            (((this->target_obj2->master_obj->id == 0x23) || (this->target_obj2->master_obj->id == 0x24)) || (this->target_obj2->master_obj->id == 0x118)) &&
            (1.0f < target_speed)) {
            target_speed = 1.0f;
        }

        float c = cosf(this->target_obj->getAngle()) * target_speed;
        float s = sinf(this->target_obj->getAngle()) * target_speed;

        float new_dx = c + dx;
        float new_dy = s + dy;
        float tmp = (speed - sqrtf(new_dy * new_dy + new_dx * new_dx + dz_sq)) + master->speed;
        if ((master->speed * 0.5f) < tmp) {
            float f = speed / tmp;
            dx = (f * c) + dx;
            dy = (f * s) + dy;
            speed = sqrtf(dy * dy + dx * dx + dz_sq);
        }
    }

    switch (master->missile_type) {
    case 0: {
        this->velocity_x = dx / speed;
        this->velocity_y = dy / speed;
        this->velocity_z = dz / speed;
        if (this->obj != nullptr) {
            this->obj->new_angle(atan2f(this->velocity_y, this->velocity_x));
        }
        this->timer = 0.0f;
        break;
    }
    case 1:
        this->set_state(4);
        break;
    case 2:
        this->set_state(4);
        break;
    case 3:
        this->velocity_x = dx;
        this->velocity_y = dy;
        this->velocity_z = dz;
        if (this->obj != nullptr) {
            this->obj->new_angle(atan2f(this->velocity_y, this->velocity_x));
        }
        break;
    default:
        break;
    }

    if (master->ballistics_ratio <= 0.0f) {
        this->ballistic_velocity = 0.0f;
        this->ballistic_acceleration = 0.0f;
        this->set_state(4);
        return;
    }

    float t = (master->speed <= 0.0f) ? 0.0f : (speed / master->speed);
    t = t * 0.5f;

    float accel = -(speed * master->ballistics_ratio);
    accel = (accel + accel) / (t * t);
    this->ballistic_acceleration = accel;
    this->ballistic_velocity = -(t * accel);

    this->set_state(4);
}

// Fully verified. Source of truth: act_misl.cpp.decomp @ 0x004050F0
uchar RGE_Action_Missile::update() {
    float vx = 0.0f;
    float vy = 0.0f;
    float vz = 0.0f;
    uchar hit_ground = 0;
    RGE_Check_List* bounds = nullptr;

    if ((this->obj == nullptr) || (this->obj->owner == nullptr) || (this->obj->owner->world == nullptr) || (this->obj->master_obj == nullptr)) {
        return 0;
    }

    RGE_Game_World* world = this->obj->owner->world;
    float dt = world->world_time_delta_seconds;
    RGE_Master_Missile_Object* master = (RGE_Master_Missile_Object*)this->obj->master_obj;
    float speed_step = master->speed * dt;

    if ((this->targetID != -1) && (world->object(this->targetID) == nullptr)) {
        this->set_target_obj(nullptr);
    }
    if ((this->target2ID != -1) && (world->object(this->target2ID) == nullptr)) {
        this->set_target_obj2(nullptr);
    }

    if ((this->target_obj != nullptr) && (rge_static_object_is_dying(this->target_obj) != 0)) {
        this->set_target_obj(nullptr);
    }
    if ((this->target_obj2 != nullptr) && (rge_static_object_is_dying(this->target_obj2) != 0)) {
        this->set_target_obj2(nullptr);
    }

    if (this->state == 1) {
        return 1;
    }

    if (this->state != 4) {
        return 0;
    }

    RGE_Missile_Object* missile = (RGE_Missile_Object*)this->obj;

    if (master->missile_type == 0) {
        this->timer = this->timer + speed_step;
        vx = this->velocity_x * speed_step;
        vy = this->velocity_y * speed_step;
        vz = this->velocity_z * speed_step;

        if (missile->max_range <= this->timer) {
            this->set_state(1);
        }
    } else if (master->missile_type == 3) {
        vx = this->velocity_x;
        vy = this->velocity_y;
        vz = this->velocity_z;
    }

    if (0.0f < master->ballistics_ratio) {
        float dv = this->ballistic_acceleration * dt;
        float old_v = this->ballistic_velocity;
        this->ballistic_velocity = dv + this->ballistic_velocity;
        vz = (dv * 0.5f + old_v) * dt + vz;
    }

    this->obj->velocity_x = vx;
    this->obj->velocity_y = vy;
    this->obj->velocity_z = vz;

    hit_ground = rge_missile_move(missile);

    if (master->missile_type < 3) {
        bounds = rge_make_object_collision_list(missile, speed_step);
        if (bounds != nullptr) {
            for (RGE_Check_Node* p = bounds->list; p != nullptr; p = p->next) {
                RGE_Static_Object* hit = p->node;
                if (hit == nullptr) {
                    continue;
                }

                switch (master->missile_hit_info) {
                case 0:
                    if (hit == this->target_obj) {
                        this->set_state(1);
                    }
                    break;
                case 1:
                    if ((hit->owner != this->obj->owner) && (hit->owner != nullptr) && (hit->owner->id != 0)) {
                        this->set_state(1);
                    }
                    break;
                case 2:
                    if (hit == this->target_obj2) {
                        break;
                    }
                    this->set_state(1);
                    break;
                default:
                    break;
                }

                if (this->state == 1) {
                    break;
                }
            }
            rge_check_list_delete(bounds);
            bounds = nullptr;
        }
    } else if (master->missile_type == 3) {
        this->set_state(1);
    }

    if ((hit_ground != 0) && (this->state != 1)) {
        this->set_state(1);
    }

    return 0;
}

uchar RGE_Action_Missile::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Missile::idle_update() { return RGE_Action::idle_update(); }
int RGE_Action_Missile::stop() { return RGE_Action::stop(); }
int RGE_Action_Missile::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int RGE_Action_Missile::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar RGE_Action_Missile::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Missile::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Missile::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Missile::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Missile::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Missile::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Missile::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Missile::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Missile::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

