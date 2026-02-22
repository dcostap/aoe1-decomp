#include "../include/TRIBE_Action_Make_Obj.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"
#include "../include/TRIBE_Building_Object.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/TRIBE_Player.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <string.h>

namespace {
static void make_obj_init_base(TRIBE_Action_Make_Obj* action, RGE_Action_Object* obj) {
    action->action_type = 0x66;
    action->obj = obj;
    action->state = 0;
    action->target_obj = nullptr;
    action->target_obj2 = nullptr;
    action->targetID = -1;
    action->target2ID = -1;
    action->target_x = 0.0f;
    action->target_y = 0.0f;
    action->target_z = 0.0f;
    action->timer = 0.0f;
    action->task = nullptr;
    action->sub_actions = nullptr;
    action->sprite = nullptr;
    action->subActionValue = 0;

    action->obj_id = -1;
    action->work_done = 0.0f;
    action->unique_id = -1;
    action->pre_paid = 0;
}

static void make_obj_load_base(RGE_Action* action, int fd) {
    int id_or_ptr = -1;
    short task_id = -1;
    short sub_action_terminator = 0;
    short sprite_id = -1;

    rge_read(fd, &action->state, 1);
    rge_read(fd, &id_or_ptr, 4);
    action->target_obj = nullptr;
    rge_read(fd, &id_or_ptr, 4);
    action->target_obj2 = nullptr;
    rge_read(fd, &action->targetID, 4);
    rge_read(fd, &action->target2ID, 4);
    rge_read(fd, &action->target_x, 4);
    rge_read(fd, &action->target_y, 4);
    rge_read(fd, &action->target_z, 4);
    rge_read(fd, &action->timer, 4);
    rge_read(fd, &task_id, 2);
    action->task = nullptr;
    rge_read(fd, &action->subActionValue, 1);
    rge_read(fd, &sub_action_terminator, 2);
    rge_read(fd, &sprite_id, 2);
    action->sprite = nullptr;
}

static void make_obj_save_base(const RGE_Action* action, int fd) {
    int target_obj_id = -1;
    int target_obj2_id = -1;
    short task_id = -1;
    short sub_action_terminator = 0;
    short sprite_id = -1;

    if (action->target_obj != nullptr) {
        target_obj_id = action->target_obj->id;
    }
    if (action->target_obj2 != nullptr) {
        target_obj2_id = action->target_obj2->id;
    }
    if (action->task != nullptr) {
        task_id = action->task->id;
    }
    if (action->sprite != nullptr) {
        sprite_id = action->sprite->id;
    }

    rge_write(fd, (void*)&action->action_type, 2);
    rge_write(fd, (void*)&action->state, 1);
    rge_write(fd, &target_obj_id, 4);
    rge_write(fd, &target_obj2_id, 4);
    rge_write(fd, (void*)&action->targetID, 4);
    rge_write(fd, (void*)&action->target2ID, 4);
    rge_write(fd, (void*)&action->target_x, 4);
    rge_write(fd, (void*)&action->target_y, 4);
    rge_write(fd, (void*)&action->target_z, 4);
    rge_write(fd, (void*)&action->timer, 4);
    rge_write(fd, &task_id, 2);
    rge_write(fd, (void*)&action->subActionValue, 1);
    rge_write(fd, &sub_action_terminator, 2);
    rge_write(fd, &sprite_id, 2);
}

static long make_obj_coord_to_long(float value) {
    return (long)value;
}
} // namespace

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D0DD0
TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(int param_1, RGE_Action_Object* param_2) {
    make_obj_init_base(this, param_2);
    make_obj_load_base(this, param_1);
    this->action_type = 0x66;
    rge_read(param_1, &this->obj_id, 2);
    rge_read(param_1, &this->work_done, 4);
    rge_read(param_1, &this->unique_id, 4);
    if (7.23f <= save_game_version) {
        rge_read(param_1, &this->pre_paid, 1);
    } else {
        this->pre_paid = 0;
    }
}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D0EB0
TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* param_1, short param_2, int param_3, uchar param_4) {
    make_obj_init_base(this, param_1);
    this->pre_paid = param_4;
    this->unique_id = param_3;
    this->action_type = 0x66;
    this->obj_id = param_2;
    this->work_done = 0.0f;
}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D0EF0
TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj() {}

int TRIBE_Action_Make_Obj::setup(RGE_Action_Object* param_1) {
    make_obj_init_base(this, param_1);
    return 1;
}

int TRIBE_Action_Make_Obj::setup(int param_1, RGE_Action_Object* param_2) {
    make_obj_init_base(this, param_2);
    make_obj_load_base(this, param_1);
    rge_read(param_1, &this->obj_id, 2);
    rge_read(param_1, &this->work_done, 4);
    rge_read(param_1, &this->unique_id, 4);
    if (7.23f <= save_game_version) {
        rge_read(param_1, &this->pre_paid, 1);
    } else {
        this->pre_paid = 0;
    }
    return 1;
}

RGE_Action_List* TRIBE_Action_Make_Obj::create_action_list(RGE_Action_Object* param_1) {
    RGE_Action_List* p_list = (RGE_Action_List*)operator new(sizeof(RGE_Action_List));
    if (p_list != nullptr) {
        memset(p_list, 0, sizeof(RGE_Action_List));
        p_list->obj = param_1;
    }
    return p_list;
}

void TRIBE_Action_Make_Obj::rehook() {}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D0F70
void TRIBE_Action_Make_Obj::save(int param_1) {
    make_obj_save_base(this, param_1);
    rge_write(param_1, &this->obj_id, 2);
    rge_write(param_1, &this->work_done, 4);
    rge_write(param_1, &this->unique_id, 4);
    rge_write(param_1, &this->pre_paid, 1);
}

short TRIBE_Action_Make_Obj::type() {
    return this->action_type;
}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D0FC0
void TRIBE_Action_Make_Obj::first_in_stack(uchar param_1) {
    if (param_1 == 0) {
        return;
    }

    TRIBE_Player* player = nullptr;
    if (this->obj != nullptr) {
        player = (TRIBE_Player*)this->obj->owner;
    }
    int obj_runtime_id = -1;
    if (this->obj != nullptr) {
        obj_runtime_id = (int)this->obj->id;
    }

    if (this->obj_id < 0) {
        if (player != nullptr) {
            player->cancelTrain(0, (int)this->obj_id, obj_runtime_id, this->unique_id);
        }
        return;
    }

    if ((player != nullptr) && (player->master_objects != nullptr) && (player->master_objects[this->obj_id] != nullptr)) {
        if ((this->pre_paid == 0) && (player->pay_obj_cost(this->obj_id, 1.0f, 0) == 0)) {
            player->cancelTrain(0, (int)this->obj_id, obj_runtime_id, this->unique_id);
            if (this->obj != nullptr) {
                this->obj->notify((int)this->obj, (int)this->obj, 0x1F9, 0x26B, 0, 0);
            }
            this->set_state(1);
            return;
        }

        this->set_state(6);
        return;
    }

    if (player != nullptr) {
        player->cancelTrain(0, (int)this->obj_id, obj_runtime_id, this->unique_id);
    }
}

uchar TRIBE_Action_Make_Obj::inside_obj_update() {
    return 1;
}

uchar TRIBE_Action_Make_Obj::idle_update() {
    return 1;
}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D10E0
void TRIBE_Action_Make_Obj::set_state(uchar param_1) {
    this->state = param_1;
}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D10F0
uchar TRIBE_Action_Make_Obj::update() {
    if (this->state == 1) {
        return 1;
    }

    if (this->state == 6) {
        TRIBE_Player* player = nullptr;
        if (this->obj != nullptr) {
            player = (TRIBE_Player*)this->obj->owner;
        }

        if ((rge_base_game != nullptr) && (rge_base_game->quick_build != 0)) {
            this->work_done = 1000.0f;
        } else if ((this->obj != nullptr) && (player != nullptr) && (player->attributes != nullptr)) {
            RGE_Master_Action_Object* worker_master = (RGE_Master_Action_Object*)this->obj->master_obj;
            if (worker_master != nullptr) {
                this->work_done = this->work_done + (worker_master->work_rate * player->attributes[0x21]);
            }
        }

        int required_work = 0;
        if ((player != nullptr) && (player->master_objects != nullptr) && (this->obj_id >= 0)) {
            TRIBE_Master_Combat_Object* produced_master = (TRIBE_Master_Combat_Object*)player->master_objects[this->obj_id];
            if (produced_master != nullptr) {
                required_work = (int)produced_master->build_pts_required;
            }
        }

        if ((float)required_work <= this->work_done) {
            this->set_state(1);

            RGE_Static_Object* new_object = nullptr;
            if (this->place_obj(&new_object) == 0) {
                if (player != nullptr) {
                    player->reimburse_obj_cost(this->obj_id);
                }
                if ((rge_base_game != nullptr) && (player != nullptr)) {
                    rge_base_game->notification(0x68, (long)player->id, (long)this->obj_id, 0, 0);
                }
                if (player != nullptr) {
                    int obj_runtime_id = (this->obj != nullptr) ? (int)this->obj->id : -1;
                    player->cancelTrain(0, (int)this->obj_id, obj_runtime_id, this->unique_id);
                }
                if (this->obj != nullptr) {
                    this->obj->notify((int)this->obj, (int)this->obj, 0x1F9, 0x26B, 0, 0);
                }
                return 1;
            }

            if ((rge_base_game != nullptr) && (player != nullptr) && (this->obj != nullptr)) {
                rge_base_game->notification(
                    0x66,
                    (long)player->id,
                    (long)this->obj_id,
                    make_obj_coord_to_long(this->obj->world_y),
                    make_obj_coord_to_long(this->obj->world_x));
            }

            if (player != nullptr) {
                int obj_runtime_id = (this->obj != nullptr) ? (int)this->obj->id : -1;
                int created_runtime_id = (new_object != nullptr) ? (int)new_object->id : -1;
                player->registerTrain((int)this->obj_id, obj_runtime_id, this->unique_id, created_runtime_id);
            }
            if (this->obj != nullptr) {
                this->obj->notify((int)this->obj, (int)this->obj, 0x1FA, 0x26B, 0, 0);
            }
            return 1;
        }
    }

    return 0;
}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D12B0
uchar TRIBE_Action_Make_Obj::place_obj(RGE_Static_Object** param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    *param_1 = nullptr;

    if ((this->obj == nullptr) || (this->obj->owner == nullptr) || (this->obj_id < 0)) {
        return 0;
    }

    TRIBE_Player* player = (TRIBE_Player*)this->obj->owner;
    if ((player == nullptr) || (player->master_objects == nullptr)) {
        return 0;
    }

    RGE_Master_Static_Object* produced_master = player->master_objects[this->obj_id];
    if (produced_master == nullptr) {
        return 0;
    }

    RGE_Master_Static_Object* producer_master = this->obj->master_obj;
    if (producer_master == nullptr) {
        return 0;
    }

    float radius_y = producer_master->radius_x + produced_master->radius_x + 0.01f;
    float radius_2y = radius_y + radius_y;
    float radius_2x = producer_master->radius_y + produced_master->radius_y + 0.01f;
    float radius_span_x = radius_2x + radius_2x;

    for (int ring = 0; ring < 3; ++ring) {
        for (int attempt = 0; attempt < 0x3C; ++attempt) {
            int side = 0;
            if (attempt < 0x28) {
                side = debug_rand("C:\\msdev\\work\\age1_x1\\tact_mob.cpp", 0xC0) % 4;
            } else {
                side = debug_rand("C:\\msdev\\work\\age1_x1\\tact_mob.cpp", 0xC2) % 4;
            }

            float candidate_x = this->obj->world_x;
            float candidate_y = this->obj->world_y;
            switch (side) {
            case 0: {
                candidate_y = this->obj->world_y + radius_2x;
                int r = debug_rand("C:\\msdev\\work\\age1_x1\\tact_mob.cpp", 0xC7);
                candidate_x = (((float)r * radius_2y * 3.051851e-05f) - radius_y) + this->obj->world_x;
                break;
            }
            case 1: {
                candidate_x = this->obj->world_x - radius_y;
                int r = debug_rand("C:\\msdev\\work\\age1_x1\\tact_mob.cpp", 0xCB);
                candidate_y = (((float)r * radius_span_x * 3.051851e-05f) - radius_2x) + this->obj->world_y;
                break;
            }
            case 2: {
                candidate_x = this->obj->world_x + radius_y;
                int r = debug_rand("C:\\msdev\\work\\age1_x1\\tact_mob.cpp", 0xCF);
                candidate_y = (((float)r * radius_span_x * 3.051851e-05f) - radius_2x) + this->obj->world_y;
                break;
            }
            default: {
                candidate_y = this->obj->world_y - radius_2x;
                int r = debug_rand("C:\\msdev\\work\\age1_x1\\tact_mob.cpp", 0xD3);
                candidate_x = (((float)r * radius_2y * 3.051851e-05f) - radius_y) + this->obj->world_x;
                break;
            }
            }

            if (produced_master->check_placement(player, candidate_x, candidate_y, nullptr, 1, 1, 1, 0, 0, 1) == 0) {
                *param_1 = produced_master->make_new_obj(player, candidate_x, candidate_y, this->target_z);
                return (*param_1 != nullptr) ? 1 : 0;
            }
        }

        radius_y = radius_y + (produced_master->radius_x + produced_master->radius_x);
        radius_2x = radius_2x + (produced_master->radius_y + produced_master->radius_y);
        radius_2y = radius_2y + (produced_master->radius_x * 4.0f);
        radius_span_x = radius_span_x + (produced_master->radius_y * 4.0f);
    }

    return 0;
}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D1550
int TRIBE_Action_Make_Obj::stop() {
    TRIBE_Player* player = nullptr;
    if (this->obj != nullptr) {
        player = (TRIBE_Player*)this->obj->owner;
    }

    if (this->state != 1) {
        this->set_state(1);
        if ((this->pre_paid == 0) && (player != nullptr)) {
            player->reimburse_obj_cost(this->obj_id);
        }
    }

    if ((rge_base_game != nullptr) && (player != nullptr)) {
        rge_base_game->notification(0x67, (long)player->id, (long)this->obj_id, 0, 0);
    }
    if (this->obj != nullptr) {
        this->obj->notify((int)this->obj, (int)this->obj, 0x1F9, 0x26B, 0, 0);
    }
    return 1;
}

int TRIBE_Action_Make_Obj::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

int TRIBE_Action_Make_Obj::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

uchar TRIBE_Action_Make_Obj::attack_response(RGE_Static_Object* param_1) {
    (void)param_1;
    return 0;
}

uchar TRIBE_Action_Make_Obj::relation_response(long param_1, uchar param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

void TRIBE_Action_Make_Obj::copy_obj(RGE_Master_Action_Object* param_1) {
    (void)param_1;
}

void TRIBE_Action_Make_Obj::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
}

void TRIBE_Action_Make_Obj::get_state_name(char* param_1) {
    if (param_1 == nullptr) {
        return;
    }
    switch (this->state) {
    case 0: strncpy(param_1, "None", 5); break;
    case 1: strncpy(param_1, "Done", 5); break;
    case 2: strncpy(param_1, "Wait", 5); break;
    case 3: strncpy(param_1, "Search", 7); break;
    case 4: strncpy(param_1, "Goto", 5); break;
    case 5: strncpy(param_1, "Goto2", 6); break;
    case 6: strncpy(param_1, "Work", 5); break;
    default: strncpy(param_1, "Unknown", 8); break;
    }
    param_1[31] = 0;
}

RGE_Static_Object* TRIBE_Action_Make_Obj::get_target_obj() {
    return this->target_obj;
}

RGE_Static_Object* TRIBE_Action_Make_Obj::get_target_obj2() {
    return this->target_obj2;
}

void TRIBE_Action_Make_Obj::set_target_obj(RGE_Static_Object* param_1) {
    this->target_obj = param_1;
    this->targetID = (param_1 != nullptr) ? param_1->id : -1;
}

void TRIBE_Action_Make_Obj::set_target_obj2(RGE_Static_Object* param_1) {
    this->target_obj2 = param_1;
    this->target2ID = (param_1 != nullptr) ? param_1->id : -1;
}

// Fully verified. Source of truth: tact_mob.cpp.decomp @ 0x004D15F0
void TRIBE_Action_Make_Obj::get_info(short* param_1, short* param_2, char* param_3, short param_4) {
    if (param_1 != nullptr) {
        *param_1 = this->obj_id;
    }

    if (param_2 != nullptr) {
        if (this->state == 1) {
            *param_2 = 100;
        } else {
            short progress = 0;
            TRIBE_Player* player = nullptr;
            if (this->obj != nullptr) {
                player = (TRIBE_Player*)this->obj->owner;
            }
            if ((player != nullptr) && (player->master_objects != nullptr) && (this->obj_id >= 0)) {
                TRIBE_Master_Combat_Object* produced_master = (TRIBE_Master_Combat_Object*)player->master_objects[this->obj_id];
                if ((produced_master != nullptr) && (produced_master->build_pts_required > 0)) {
                    progress = (short)((this->work_done * 100.0f) / (float)produced_master->build_pts_required);
                }
            }
            *param_2 = progress;
        }
    }

    if ((param_3 != nullptr) && (param_4 > 0)) {
        param_3[0] = 0;
        TRIBE_Player* player = nullptr;
        if (this->obj != nullptr) {
            player = (TRIBE_Player*)this->obj->owner;
        }
        if ((player != nullptr) && (player->master_objects != nullptr) && (this->obj_id >= 0)) {
            RGE_Master_Static_Object* produced_master = player->master_objects[this->obj_id];
            if ((produced_master != nullptr) && (produced_master->name != nullptr)) {
                strncpy(param_3, produced_master->name, (int)param_4);
            }
        }
        param_3[param_4 - 1] = 0;
    }
}
