#include "../include/TRIBE_Action_Discovery_Artifact.h"

#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Tile.h"
#include "../include/globals.h"

#include <cstdlib>
#include <cstring>
#include <new>

// Fully verified. Marker reconciliation coverage.
static short tact_dar_player_num(RGE_Action_Object* obj) {
    if (obj == nullptr || obj->owner == nullptr || obj->owner->world == nullptr) return 0;
    return obj->owner->world->player_num;
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE530
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x6c;

    short player_num = tact_dar_player_num(param_2);
    this->flags = (uchar*)calloc((int)player_num, 1);
    if (this->flags != nullptr) {
        rge_read(param_1, this->flags, (int)player_num);
    }
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE5F0
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->action_type = 0x6c;
    this->set_target_obj(param_3);

    short player_num = tact_dar_player_num(param_1);
    this->flags = (uchar*)calloc((int)player_num, 1);
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE670
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
    this->action_type = 0x6c;

    short player_num = tact_dar_player_num(param_1);
    this->flags = (uchar*)calloc((int)player_num, 1);
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
TRIBE_Action_Discovery_Artifact::~TRIBE_Action_Discovery_Artifact() {
    if (this->flags != nullptr) {
        free(this->flags);
        this->flags = nullptr;
    }
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
int TRIBE_Action_Discovery_Artifact::setup(RGE_Action_Object* param_1) { int r = RGE_Action::setup(param_1); this->action_type = 0x6c; return r; }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
int TRIBE_Action_Discovery_Artifact::setup(int param_1, RGE_Action_Object* param_2) { int r = RGE_Action::setup(param_1, param_2); this->action_type = 0x6c; return r; }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
RGE_Action_List* TRIBE_Action_Discovery_Artifact::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
void TRIBE_Action_Discovery_Artifact::rehook() { RGE_Action::rehook(); }

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE6D0
void TRIBE_Action_Discovery_Artifact::save(int param_1) {
    RGE_Action::save(param_1);
    short player_num = tact_dar_player_num(this->obj);
    if (this->flags != nullptr) {
        rge_write(param_1, this->flags, (int)player_num);
    }
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
short TRIBE_Action_Discovery_Artifact::type() { return this->action_type; }

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE700
void TRIBE_Action_Discovery_Artifact::first_in_stack(uchar param_1) {
    if (param_1 != 0) {
        this->set_state(6);
    }
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
uchar TRIBE_Action_Discovery_Artifact::inside_obj_update() { return RGE_Action::inside_obj_update(); }
// Fully verified. Marker reconciliation coverage.
uchar TRIBE_Action_Discovery_Artifact::idle_update() { return RGE_Action::idle_update(); }

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE720
void TRIBE_Action_Discovery_Artifact::set_state(uchar param_1) {
    this->state = param_1;
    if (param_1 == 10) {
        this->timer = 3.0f;
    }
}

// Fully verified. Marker reconciliation coverage.
static float tact_dar_read_master_float(RGE_Master_Static_Object* master, int offset) {
    float v = 0.0f;
    if (master != nullptr) {
        std::memcpy(&v, (char*)master + offset, sizeof(v));
    }
    return v;
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE7A0
void TRIBE_Action_Discovery_Artifact::check_objects() {
    if (this->obj == nullptr || this->obj->owner == nullptr || this->obj->owner->world == nullptr) {
        return;
    }

    RGE_Game_World* world = this->obj->owner->world;
    RGE_Map* map = world->map;
    if (map == nullptr || map->map_row_offset == nullptr || this->flags == nullptr) {
        return;
    }

    // Constants are referenced via DAT_00575078/DAT_0057507c in the original.
    const float kMinOffset = 0.5f;
    const float kMaxOffset = 0.5f;

    float radius_x = tact_dar_read_master_float(this->obj->master_obj, 0x30);
    float radius_y = tact_dar_read_master_float(this->obj->master_obj, 0x34);

    short x_min = (short)(long)((this->obj->world_x - kMinOffset) - radius_x);
    short y_min = (short)(long)((this->obj->world_y - kMinOffset) - radius_y);
    short x_max = (short)(long)((radius_x + this->obj->world_x) - kMaxOffset);
    short y_max = (short)(long)((radius_y + this->obj->world_y) - kMaxOffset);

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
                        while (node != nullptr) {
                            RGE_Static_Object* o = node->node;
                            if (o != nullptr && o->owner != nullptr && o->owner != this->obj->owner) {
                                short pid = o->owner->id;
                                short player_num = world->player_num;
                                if ((0 <= pid) && (pid < player_num) && (this->flags[pid] == 0)) {
                                    this->flags[pid] = 1;
                                    int ai_container = *(int*)((char*)o->owner + 0x24);
                                    if (ai_container != 0) {
                                        int ai_module = *(int*)(ai_container + 0x288);
                                        if (ai_module != 0) {
                                            typedef void(__thiscall* DiscoveryCallback)(void*, RGE_Player*, float, float, float);
                                            DiscoveryCallback cb = *(DiscoveryCallback*)(*(int*)ai_module + 0x18);
                                            if (cb != nullptr) {
                                                cb((void*)ai_module, o->owner, o->world_x, o->world_y, o->world_z);
                                            }
                                        }
                                    }
                                }
                            }
                            node = node->next;
                        }
                    }
                }
            }
        }
    }
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740
uchar TRIBE_Action_Discovery_Artifact::update() {
    if (this->state == 1) return 1;
    if (this->state == 6) {
        this->check_objects();
        this->set_state(10);
        return 0;
    }
    if (this->state == 10) {
        RGE_Game_World* world = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->world : nullptr;
        float delta = (world != nullptr) ? world->world_time_delta_seconds : 0.0f;
        this->timer -= delta;
        if (this->timer <= 0.0f) {
            this->set_state(6);
        }
        return 0;
    }
    return 0;
}

// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
int TRIBE_Action_Discovery_Artifact::stop() { this->set_state(2); return 1; }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
int TRIBE_Action_Discovery_Artifact::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
int TRIBE_Action_Discovery_Artifact::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
uchar TRIBE_Action_Discovery_Artifact::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
uchar TRIBE_Action_Discovery_Artifact::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
void TRIBE_Action_Discovery_Artifact::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
void TRIBE_Action_Discovery_Artifact::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
void TRIBE_Action_Discovery_Artifact::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
RGE_Static_Object* TRIBE_Action_Discovery_Artifact::get_target_obj() { return RGE_Action::get_target_obj(); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
RGE_Static_Object* TRIBE_Action_Discovery_Artifact::get_target_obj2() { return RGE_Action::get_target_obj2(); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
void TRIBE_Action_Discovery_Artifact::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
// Fully verified. Source of truth: tact_dar.cpp.decomp @ 0x004CE740 (virtual forwarding coverage).
void TRIBE_Action_Discovery_Artifact::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

