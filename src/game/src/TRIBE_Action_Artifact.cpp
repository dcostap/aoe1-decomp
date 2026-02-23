#include "../include/TRIBE_Action_Artifact.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Tile.h"

#include <cstdlib>
#include <cstring>
#include <new>

static float tact_art_read_master_float(RGE_Master_Static_Object* master, int offset) {
    float v = 0.0f;
    if (master != nullptr) {
        std::memcpy(&v, (char*)master + offset, sizeof(v));
    }
    return v;
}

TRIBE_Action_Artifact::TRIBE_Action_Artifact(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x6b;
}

TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->action_type = 0x6b;
    this->task = param_2;
    this->set_target_obj(param_3);
}

TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
    this->action_type = 0x6b;
}

TRIBE_Action_Artifact::~TRIBE_Action_Artifact() {}

int TRIBE_Action_Artifact::setup(RGE_Action_Object* param_1) { int r = RGE_Action::setup(param_1); this->action_type = 0x6b; return r; }
int TRIBE_Action_Artifact::setup(int param_1, RGE_Action_Object* param_2) { int r = RGE_Action::setup(param_1, param_2); this->action_type = 0x6b; return r; }
RGE_Action_List* TRIBE_Action_Artifact::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void TRIBE_Action_Artifact::rehook() { RGE_Action::rehook(); }
void TRIBE_Action_Artifact::save(int param_1) { RGE_Action::save(param_1); }
short TRIBE_Action_Artifact::type() { return this->action_type; }

void TRIBE_Action_Artifact::first_in_stack(uchar param_1) {
    if (param_1 == 0) return;
    if (this->target_obj != nullptr) {
        this->set_state(5);
        return;
    }
    if ((this->target_x != -1.0f) && (this->target_y != -1.0f)) {
        this->set_state(4);
        return;
    }
    this->set_state(6);
}

uchar TRIBE_Action_Artifact::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar TRIBE_Action_Artifact::idle_update() { return RGE_Action::idle_update(); }

void TRIBE_Action_Artifact::set_state(uchar param_1) {
    this->state = param_1;
    if (param_1 == 4) {
        if (this->sub_actions != nullptr) {
            this->sub_actions->delete_list();
            RGE_Action* move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f,
                                                                     (this->task != nullptr) ? this->task->move_sprite : nullptr);
            if (move != nullptr) {
                this->sub_actions->add_action(move);
                this->set_state(6);
            }
        }
        return;
    }
    if (param_1 == 5) {
        if (this->sub_actions != nullptr) {
            this->sub_actions->delete_list();
            if (this->target_obj != nullptr) {
                this->target_x = this->target_obj->world_x;
                this->target_y = this->target_obj->world_y;
                this->target_z = this->target_obj->world_z;
            }
            this->target_obj = nullptr;
            RGE_Action* move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f,
                                                                     (this->task != nullptr) ? this->task->move_sprite : nullptr);
            if (move != nullptr) {
                this->sub_actions->add_action(move);
                this->set_state(6);
            }
        }
        return;
    }
    if (param_1 == 10) {
        this->timer = 3.0f;
    }
}

uchar TRIBE_Action_Artifact::update() {
    if (this->sub_actions != nullptr) {
        uchar u = this->sub_actions->update();
        if ((u != 0) && (u < 4)) {
            this->sub_actions->delete_list();
        }
    }

    switch (this->state) {
    case 1:
        return 1;
    default:
        return 0;
    case 6: {
        RGE_Player* player = this->check_ownership();
        if (player == nullptr) {
            this->set_state(10);
            return 0;
        }
        if (this->sub_actions != nullptr) {
            this->sub_actions->delete_list();
        }
        if (this->obj != nullptr) {
            this->obj->change_ownership(player);
        }
        return 0;
    }
    case 10: {
        RGE_Game_World* world = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->world : nullptr;
        float delta = (world != nullptr) ? world->world_time_delta_seconds : 0.0f;
        this->timer -= delta;
        if (0.0f < this->timer) {
            return 0;
        }
        this->set_state(6);
        return 0;
    }
    case 100: {
        if (this->obj != nullptr && this->obj->owner != nullptr && this->obj->owner->world != nullptr) {
            RGE_Game_World* world = this->obj->owner->world;
            if (world->players != nullptr) {
                this->obj->change_ownership(world->players[0]);
            }
        }
        this->set_state(6);
        return 0;
    }
    }
}

int TRIBE_Action_Artifact::stop() { this->set_state(6); return 1; }

int TRIBE_Action_Artifact::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_state(4);
    return 1;
}

int TRIBE_Action_Artifact::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 != nullptr) {
        this->target_obj = param_1;
        this->set_state(5);
        return 1;
    }
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_state(4);
    return 1;
}

uchar TRIBE_Action_Artifact::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar TRIBE_Action_Artifact::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void TRIBE_Action_Artifact::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void TRIBE_Action_Artifact::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void TRIBE_Action_Artifact::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* TRIBE_Action_Artifact::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* TRIBE_Action_Artifact::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void TRIBE_Action_Artifact::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void TRIBE_Action_Artifact::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

RGE_Player* TRIBE_Action_Artifact::check_ownership() {
    if (this->obj == nullptr || this->obj->owner == nullptr || this->obj->owner->world == nullptr) {
        return nullptr;
    }

    RGE_Game_World* world = this->obj->owner->world;
    RGE_Map* map = world->map;
    if (map == nullptr || map->map_row_offset == nullptr) {
        return nullptr;
    }

    // Constants are referenced via DAT_00574f10/DAT_00574f14 in the original.
    const float kMinOffset = 0.5f;
    const float kMaxOffset = 0.5f;

    float radius_x = tact_art_read_master_float(this->obj->master_obj, 0x30);
    float radius_y = tact_art_read_master_float(this->obj->master_obj, 0x34);

    short x_min = (short)(long)((this->obj->world_x - kMinOffset) - radius_x);
    short y_min = (short)(long)((this->obj->world_y - kMinOffset) - radius_y);
    short x_max = (short)(long)((radius_x + this->obj->world_x) - kMaxOffset);
    short y_max = (short)(long)((radius_y + this->obj->world_y) - kMaxOffset);

    short player_num = world->player_num;
    uchar* counts = (uchar*)calloc((size_t)player_num, 1);
    if (counts == nullptr) {
        return nullptr;
    }

    if (x_min < 0) x_min = 0;
    if (y_min < 0) y_min = 0;
    if ((long)map->map_width <= (long)x_max) x_max = (short)(map->map_width - 1);
    if ((long)map->map_height <= (long)y_max) y_max = (short)(map->map_height - 1);

    if (y_min <= y_max) {
        for (short row = y_min; row <= y_max; ++row) {
            if (x_min <= x_max) {
                RGE_Tile* row_tiles = map->map_row_offset[row];
                if (row_tiles != nullptr) {
                    for (short col = x_min; col <= x_max; ++col) {
                        RGE_Object_Node* node = row_tiles[col].objects.list;
                        for (; node != nullptr; node = node->next) {
                            RGE_Static_Object* obj = node->node;
                            if (obj == nullptr || obj->master_obj == nullptr) continue;
                            short group = obj->master_obj->object_group;
                            if ((group != 1) && (group != 0xb) && (group != 0x1e) && (obj->object_state == 2) &&
                                (obj->owner != nullptr)) {
                                short pid = obj->owner->id;
                                if ((0 <= pid) && (pid < player_num)) {
                                    counts[pid] = (uchar)(counts[pid] + 1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int found = 0;
    short found_player = -1;
    for (short pid = 1; pid < player_num; ++pid) {
        if (counts[pid] != 0) {
            ++found;
            found_player = pid;
        }
    }
    free(counts);

    if ((found == 1) && (0 < found_player) && (this->obj->owner != nullptr) && (found_player != this->obj->owner->id)) {
        if (world->players != nullptr) {
            return world->players[found_player];
        }
    }
    return nullptr;
}

void TRIBE_Action_Artifact::reset_owner() {
    this->set_state(100);
}

