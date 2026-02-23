#include "../include/RGE_Action_Transport.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/debug_helpers.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"

#include <new>

namespace {
static const char s_stat_obj_cpp[] = "C:\\msdev\\work\\age1_x1\\stat_obj.cpp";

// Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C6210
static void rge_static_set_location(RGE_Static_Object* obj, float x, float y, float z) {
    obj->world_x = x;
    obj->world_y = y;
    obj->world_z = z;
}

// Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C6400
// ASM-verified lookupZone arg order (x,y) at stat_obj.cpp.asm @ 0x004C65B0.
static uchar rge_static_find_drop_location(RGE_Static_Object* self,
                                          int zone,
                                          float* out_x,
                                          float* out_y,
                                          RGE_Master_Static_Object* drop_master,
                                          RGE_Static_Object* drop_obj,
                                          float base_x,
                                          float base_y,
                                          float base_radius_2x,
                                          float base_radius_2y) {
    float radius_x = base_radius_2x + drop_master->radius_x;
    float radius_y = base_radius_2y + drop_master->radius_y;
    float radius_2x = radius_x + radius_x;
    float radius_2y = radius_y + radius_y;

    short ring = 1;
    do {
        short tries = 0;
        do {
            long side = ((long)debug_rand(s_stat_obj_cpp, 0xF3A) * 4) / 0x7FFF;
            switch (side) {
            case 0: {
                *out_x = radius_x + base_x;
                long r = debug_rand(s_stat_obj_cpp, 0xF3E);
                *out_y = ((float)r * radius_2y * 3.051851e-05f - radius_y) + base_y;
                break;
            }
            case 1: {
                *out_x = base_x - radius_x;
                long r = debug_rand(s_stat_obj_cpp, 0xF42);
                *out_y = ((float)r * radius_2y * 3.051851e-05f - radius_y) + base_y;
                break;
            }
            case 2: {
                *out_y = radius_y + base_y;
                long r = debug_rand(s_stat_obj_cpp, 0xF46);
                *out_x = ((float)r * radius_2x * 3.051851e-05f - radius_x) + base_x;
                break;
            }
            case 3: {
                *out_y = base_y - radius_y;
                long r = debug_rand(s_stat_obj_cpp, 0xF4A);
                *out_x = ((float)r * radius_2x * 3.051851e-05f - radius_x) + base_x;
                break;
            }
            default:
                break;
            }

            if ((*out_x >= 0.0f) && (*out_y >= 0.0f) && self->owner != nullptr && self->owner->world != nullptr &&
                self->owner->world->map != nullptr && (*out_x < (float)self->owner->world->map->map_width) &&
                (*out_y < (float)self->owner->world->map->map_height)) {
                if (zone != -1) {
                    uchar lookup = self->lookupZone((int)*out_x, (int)*out_y);
                    if (zone != (int)lookup) {
                        goto next_try;
                    }
                }

                int placement = 0;
                uchar blocked = drop_master->check_placement(self->owner, *out_x, *out_y, &placement, 1, 1, 1, 0, 1, 1);
                if ((blocked == 0) && (drop_obj->passableTile(*out_x, *out_y, 0) == 1)) {
                    return 1;
                }
            }

        next_try:
            tries = tries + 1;
        } while (tries < 0x32);

        radius_x = drop_master->radius_x + drop_master->radius_x + radius_x;
        radius_y = drop_master->radius_y + drop_master->radius_y + radius_y;
        radius_2x = drop_master->radius_x * 4.0f + radius_2x;
        radius_2y = drop_master->radius_y * 4.0f + radius_2y;

        ring = ring + 1;
        if (ring > 1) {
            return 0;
        }
    } while (true);
}

// Fully verified. Source of truth: stat_obj.cpp.decomp @ 0x004C6270
static uchar rge_static_drop_held_objects(RGE_Static_Object* self, int zone) {
    uchar dropped_count = 0;

    float drop_x[10] = {};
    float drop_y[10] = {};
    float radius_x[10] = {};
    float radius_y[10] = {};

    drop_x[1] = self->world_x;
    drop_y[1] = self->world_y;
    radius_x[1] = self->master_obj->radius_x + self->master_obj->radius_x;
    radius_y[1] = self->master_obj->radius_y + self->master_obj->radius_y;

    int constraint_count = 1;
    RGE_Object_Node* cur = (self->objects != nullptr) ? self->objects->list : nullptr;
    while (cur != nullptr) {
        RGE_Object_Node* next = cur->next;

        if (constraint_count < 1) {
            return dropped_count;
        }

        RGE_Static_Object* held = cur->node;
        int iVar6 = constraint_count;
        while (iVar6 > 0) {
            float x = 0.0f;
            float y = 0.0f;
            if (rge_static_find_drop_location(self, zone, &x, &y, held->master_obj, held, drop_x[1], drop_y[1], radius_x[1], radius_y[1]) != 0) {
                rge_static_set_location(held, self->world_x, self->world_y, self->world_z);
                held->exit_obj();
                held->teleport(x, y, self->world_z);

                dropped_count = (uchar)(dropped_count + 1);
                constraint_count = iVar6;
                if (iVar6 < 9) {
                    constraint_count = iVar6 + 1;
                    drop_x[iVar6 + 1] = x;
                    drop_y[iVar6 + 1] = y;
                    radius_x[iVar6 + 1] = held->master_obj->radius_x + held->master_obj->radius_x;
                    radius_y[iVar6 + 1] = held->master_obj->radius_y + held->master_obj->radius_y;
                }
                break;
            }

            int new_count = iVar6 - 1;
            if (new_count < 1) {
                break;
            }

            drop_x[new_count] = drop_x[iVar6];
            drop_y[new_count] = drop_y[iVar6];
            radius_x[new_count] = radius_x[iVar6];
            radius_y[new_count] = radius_y[iVar6];
            iVar6 = new_count;
        }

        cur = next;
    }

    return dropped_count;
}
}

RGE_Action_Transport::RGE_Action_Transport(int param_1, RGE_Action_Object* param_2) {
    // Fully verified. Source of truth: act_tran.cpp.decomp @ 0x00406D60
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x0c;
}

RGE_Action_Transport::RGE_Action_Transport(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    // Fully verified. Source of truth: act_tran.cpp.decomp @ 0x00406DC0
    RGE_Action::setup(param_1);
    this->action_type = 0x0c;
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
}

RGE_Action_Transport::~RGE_Action_Transport() {}

int RGE_Action_Transport::setup(RGE_Action_Object* param_1) { return RGE_Action::setup(param_1); }
int RGE_Action_Transport::setup(int param_1, RGE_Action_Object* param_2) { return RGE_Action::setup(param_1, param_2); }
RGE_Action_List* RGE_Action_Transport::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Transport::rehook() { RGE_Action::rehook(); }
void RGE_Action_Transport::save(int param_1) { RGE_Action::save(param_1); }
short RGE_Action_Transport::type() { return this->action_type; }

// Fully verified. Source of truth: act_tran.cpp.decomp @ 0x00406E00
void RGE_Action_Transport::first_in_stack(uchar param_1) {
    if (param_1 == 0) {
        this->set_state(2);
        return;
    }

    if ((0.0f <= this->target_x) && (0.0f <= this->target_y)) {
        this->set_state(0x0B);
        return;
    }

    this->set_state(2);
}

uchar RGE_Action_Transport::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Transport::idle_update() { return RGE_Action::idle_update(); }

// Fully verified. Source of truth: act_tran.cpp.decomp @ 0x00406E50
void RGE_Action_Transport::set_state(uchar param_1) {
    this->sub_actions->delete_list();

    this->state = param_1;

    if (param_1 == 2) {
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;
    }

    if ((param_1 != 4) && (param_1 != 0x0B)) {
        return;
    }

    RGE_Sprite* move_sprite = nullptr;
    if (this->task == nullptr) {
        move_sprite = this->obj->master_obj->sprite;
    } else {
        move_sprite = this->task->move_sprite;
    }

    RGE_Action* move_action = new (std::nothrow)
        RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.3f, move_sprite);
    if (move_action == nullptr) {
        this->set_state(2);
        return;
    }

    this->sub_actions->add_action(move_action);
    move_action->setSubAction(1);
}

// Fully verified. Source of truth: act_tran.cpp.decomp @ 0x00406F90
uchar RGE_Action_Transport::update() {
    switch (this->state) {
    case 1:
        return 1;

    case 4: {
        uchar result = this->sub_actions->update();
        if ((result != 0) && (result < 6)) {
            this->set_state(6);
            return 0;
        }
        break;
    }

    case 6: {
        int zone = this->targetZone();
        if ((zone == -1) || (this->obj->withinRangeOfZone((uchar)zone, 2.0f) != 0)) {
            if (this->obj->objects->number_of_objects < 1) {
                goto done;
            }

            int has_drop_terrain = this->next_to_drop_off_terrain();
            if (has_drop_terrain == 0) {
                RGE_Map* map = this->obj->owner->world->map;
                if (this->target_x != -1.0f) {
                    short col = (short)(int)this->target_x;
                    short row = (short)(int)this->target_y;
                    uchar terrain = map->get_terrain(col, row);
                    if (terrain == 1) {
                        goto done;
                    }
                    terrain = map->get_terrain(col, row);
                    if (terrain == 0x16) {
                        goto done;
                    }
                }
                goto notify_207;
            }

            zone = this->targetZone();
            uchar dropped = rge_static_drop_held_objects(this->obj, zone);
            if (dropped == 0) {
                goto notify_207;
            }
            if (this->obj->objects->number_of_objects < 1) {
                goto done;
            }

            int id = (int)this->obj->id;
            this->obj->owner->notify(id, id, 0x206, 0x266, 0, 0);
            goto done;
        }

    notify_207: {
        int id = (int)this->obj->id;
        this->obj->owner->notify(id, id, 0x207, 0x266, 0, 0);
    }

    done:
        this->set_state(2);
        return 0;
    }

    case 0x0B: {
        uchar result = this->sub_actions->update();
        if ((result != 0) && (result < 6)) {
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 0x0D: {
        int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x1F9, 0x266, 0, 0);
        this->set_state(2);
        return 3;
    }
    }

    return 0;
}

// Fully verified. Source of truth: act_tran.cpp.decomp @ 0x00407160
int RGE_Action_Transport::stop() {
    this->set_state(2);
    return 1;
}

// Fully verified. Source of truth: act_tran.cpp.decomp @ 0x00407170
int RGE_Action_Transport::move_to(RGE_Static_Object* /*param_1*/, float param_2, float param_3, float param_4) {
    this->target_x = param_2;
    this->target_y = param_3;
    this->target2ID = 0;
    this->target_z = param_4;
    this->set_state(0x0B);
    return 1;
}

// Fully verified. Source of truth: act_tran.cpp.decomp @ 0x004071A0
int RGE_Action_Transport::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    this->target2ID = 1;

    int zone_x = (int)param_2;
    int zone_y = (int)param_3;
    uchar zone = this->obj->lookupZone(zone_x, zone_y);

    float dist = this->obj->distance_to_position(param_2, param_3, this->obj->world_z);
    if ((this->obj->withinRangeOfZone(zone, 2.0f) == 1) && (dist <= 2.0f)) {
        this->target_y = param_3;
        this->target_x = param_2;
        this->target_z = param_4;
        this->set_state(6);
        return 1;
    }

    if ((0.0f <= param_2) && (0.0f <= param_3)) {
        this->target_x = param_2;
        this->target_y = param_3;
        this->target_z = param_4;

        if (param_1 != this->obj) {
            this->set_state(0x0B);
            return 1;
        }
        this->set_state(4);
    }

    return 1;
}

uchar RGE_Action_Transport::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Transport::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Transport::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Transport::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Transport::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Transport::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Transport::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Transport::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Transport::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: act_tran.cpp.decomp @ 0x004072B0
int RGE_Action_Transport::next_to_drop_off_terrain() {
    if ((this->task != nullptr) && (this->task->terrain_id == -1)) {
        return 1;
    }

    RGE_Static_Object* obj = this->obj;
    RGE_Map* map = obj->owner->world->map;
    RGE_Master_Static_Object* master = obj->master_obj;

    int min_col = (int)(obj->world_x - master->radius_x - 1.0f);
    int min_row = (int)(obj->world_y - master->radius_y - 1.0f);
    int max_col = (int)(obj->world_x + master->radius_x + 1.0f);
    int max_row = (int)(obj->world_y + master->radius_y + 1.0f);

    if (min_col < 0) {
        min_col = 0;
    }
    if (map->map_width <= max_col) {
        max_col = (int)map->map_width - 1;
    }
    if (min_row < 0) {
        min_row = 0;
    }
    if (map->map_height <= max_row) {
        max_row = (int)map->map_height - 1;
    }

    int zone = this->targetZone();
    if (this->target_x != -1.0f) {
        zone = (int)obj->lookupZone((int)this->target_x, (int)this->target_y);
    }

    for (int row = min_row; row <= max_row; row = row + 1) {
        for (int col = min_col; col <= max_col; col = col + 1) {
            if ((zone == -1) || (obj->lookupZone(col, row) == (uchar)zone)) {
                uchar terrain = map->get_terrain((short)col, (short)row);
                if (terrain == 2) {
                    return 1;
                }
                terrain = map->get_terrain((short)col, (short)row);
                if (terrain == 4) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Fully verified. Source of truth: act_tran.cpp.decomp @ 0x00407420
// ASM-verified lookupZone arg order (x,y) at act_tran.cpp.asm @ 0x0040742C.
int RGE_Action_Transport::targetZone() {
    if (this->target_x != -1.0f) {
        return (int)this->obj->lookupZone((int)this->target_x, (int)this->target_y);
    }
    return -1;
}

