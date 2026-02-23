#include "../include/TRIBE_Action_Make_Tech.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_Player_Tech.h"
#include "../include/globals.h"

#include <new>
#include <string.h>

namespace {
static void make_tech_init_base(TRIBE_Action_Make_Tech* action, RGE_Action_Object* obj) {
    action->action_type = 0x67;
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

    action->tech_id = -1;
    action->unique_id = -1;
}

static void make_tech_load_base(RGE_Action* action, int fd) {
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

static void make_tech_save_base(const RGE_Action* action, int fd) {
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

static long make_tech_coord_to_long(float value) {
    return (long)value;
}
} // namespace

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D21B0
TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(int param_1, RGE_Action_Object* param_2) {
    make_tech_init_base(this, param_2);
    make_tech_load_base(this, param_1);
    this->action_type = 0x67;
    rge_read(param_1, &this->tech_id, 2);
    rge_read(param_1, &this->unique_id, 4);
}

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D2250
TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(RGE_Action_Object* param_1, short param_2, int param_3) {
    make_tech_init_base(this, param_1);
    this->unique_id = param_3;
    this->action_type = 0x67;
    this->tech_id = param_2;
}

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D2290
TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech() {
    TRIBE_Player* player = nullptr;
    if (this->obj != nullptr) {
        player = (TRIBE_Player*)this->obj->owner;
    }

    if ((this->state != 1) && (player != nullptr) && (player->tech_tree != nullptr)) {
        player->tech_tree->cancel_research(this->tech_id, 0);
        if ((rge_base_game != nullptr) && (rge_base_game->world != nullptr) && (rge_base_game->world->game_state == 0)) {
            rge_base_game->notification(0x65, (long)player->id, (long)this->tech_id, 0, 0);
            int obj_runtime_id = (this->obj != nullptr) ? (int)this->obj->id : -1;
            player->cancelResearch((int)this->tech_id, obj_runtime_id, -1, this->unique_id);
            if (this->obj != nullptr) {
                this->obj->notify((int)this->obj, (int)this->obj, 0x1F9, 0x26C, 0, 0);
            }
        }
    }
}

int TRIBE_Action_Make_Tech::setup(RGE_Action_Object* param_1) {
    make_tech_init_base(this, param_1);
    return 1;
}

int TRIBE_Action_Make_Tech::setup(int param_1, RGE_Action_Object* param_2) {
    make_tech_init_base(this, param_2);
    make_tech_load_base(this, param_1);
    rge_read(param_1, &this->tech_id, 2);
    rge_read(param_1, &this->unique_id, 4);
    return 1;
}

RGE_Action_List* TRIBE_Action_Make_Tech::create_action_list(RGE_Action_Object* param_1) {
    return new (std::nothrow) RGE_Action_List(param_1);
}

void TRIBE_Action_Make_Tech::rehook() {}

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D2370
void TRIBE_Action_Make_Tech::save(int param_1) {
    make_tech_save_base(this, param_1);
    rge_write(param_1, &this->tech_id, 2);
    rge_write(param_1, &this->unique_id, 4);
}

short TRIBE_Action_Make_Tech::type() {
    return this->action_type;
}

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D23B0
void TRIBE_Action_Make_Tech::first_in_stack(uchar param_1) {
    if ((param_1 == 0) || (this->tech_id < 0)) {
        return;
    }

    TRIBE_Player* player = nullptr;
    if (this->obj != nullptr) {
        player = (TRIBE_Player*)this->obj->owner;
    }
    if ((player == nullptr) || (player->tech_tree == nullptr)) {
        return;
    }

    short need_attr = (short)param_1;
    uchar started = player->tech_tree->start_research(this->tech_id, 1, &need_attr);
    if (started == 1) {
        this->set_state(6);
        return;
    }

    int obj_runtime_id = (this->obj != nullptr) ? (int)this->obj->id : -1;
    player->cancelResearch((int)need_attr, (int)this->tech_id, obj_runtime_id, this->unique_id);
    if (this->obj != nullptr) {
        this->obj->notify((int)this->obj, (int)this->obj, 0x1F9, 0x26C, 0, 0);
    }
    this->set_state(1);
}

uchar TRIBE_Action_Make_Tech::inside_obj_update() {
    return 1;
}

uchar TRIBE_Action_Make_Tech::idle_update() {
    return 1;
}

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D2440
void TRIBE_Action_Make_Tech::set_state(uchar param_1) {
    this->state = param_1;
}

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D2450
uchar TRIBE_Action_Make_Tech::update() {
    if (this->state == 1) {
        return 1;
    }

    if (this->state == 6) {
        TRIBE_Player* player = nullptr;
        if (this->obj != nullptr) {
            player = (TRIBE_Player*)this->obj->owner;
        }
        if ((player == nullptr) || (player->tech_tree == nullptr)) {
            return 0;
        }

        float work = 0.0f;
        if ((rge_base_game != nullptr) && (rge_base_game->quick_build != 0)) {
            work = 1000.0f;
        } else if ((this->obj != nullptr) && (player->attributes != nullptr)) {
            RGE_Master_Action_Object* worker_master = (RGE_Master_Action_Object*)this->obj->master_obj;
            if (worker_master != nullptr) {
                work = player->attributes[0x21] * worker_master->work_rate;
            }
        }

        if (player->tech_tree->research(this->tech_id, work) == 0) {
            this->set_state(1);

            if ((rge_base_game != nullptr) && (this->obj != nullptr)) {
                rge_base_game->notification(
                    100,
                    (long)player->id,
                    (long)this->tech_id,
                    make_tech_coord_to_long(this->obj->world_y),
                    make_tech_coord_to_long(this->obj->world_x));
            }

            int obj_runtime_id = (this->obj != nullptr) ? (int)this->obj->id : -1;
            player->registerResearch((int)this->tech_id, obj_runtime_id, this->unique_id);
            if (this->obj != nullptr) {
                this->obj->notify((int)this->obj, (int)this->obj, 0x1FA, 0x26C, 0, 0);
            }
            return 1;
        }
    }

    return 0;
}

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D2550
int TRIBE_Action_Make_Tech::stop() {
    this->set_state(1);

    TRIBE_Player* player = nullptr;
    if (this->obj != nullptr) {
        player = (TRIBE_Player*)this->obj->owner;
    }

    if ((player != nullptr) && (player->tech_tree != nullptr)) {
        player->tech_tree->cancel_research(this->tech_id, 1);
    }
    if ((rge_base_game != nullptr) && (player != nullptr)) {
        rge_base_game->notification(0x65, (long)player->id, (long)this->tech_id, 0, 0);
    }
    if (player != nullptr) {
        int obj_runtime_id = (this->obj != nullptr) ? (int)this->obj->id : -1;
        player->cancelResearch((int)this->tech_id, obj_runtime_id, -1, this->unique_id);
    }
    if (this->obj != nullptr) {
        this->obj->notify((int)this->obj, (int)this->obj, 0x1F9, 0x26C, 0, 0);
    }
    return 1;
}

int TRIBE_Action_Make_Tech::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

int TRIBE_Action_Make_Tech::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

uchar TRIBE_Action_Make_Tech::attack_response(RGE_Static_Object* param_1) {
    (void)param_1;
    return 0;
}

uchar TRIBE_Action_Make_Tech::relation_response(long param_1, uchar param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

void TRIBE_Action_Make_Tech::copy_obj(RGE_Master_Action_Object* param_1) {
    (void)param_1;
}

void TRIBE_Action_Make_Tech::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
}

void TRIBE_Action_Make_Tech::get_state_name(char* param_1) {
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

RGE_Static_Object* TRIBE_Action_Make_Tech::get_target_obj() {
    return this->target_obj;
}

RGE_Static_Object* TRIBE_Action_Make_Tech::get_target_obj2() {
    return this->target_obj2;
}

void TRIBE_Action_Make_Tech::set_target_obj(RGE_Static_Object* param_1) {
    this->target_obj = param_1;
    this->targetID = (param_1 != nullptr) ? param_1->id : -1;
}

void TRIBE_Action_Make_Tech::set_target_obj2(RGE_Static_Object* param_1) {
    this->target_obj2 = param_1;
    this->target2ID = (param_1 != nullptr) ? param_1->id : -1;
}

// Fully verified. Source of truth: tact_tek.cpp.decomp @ 0x004D25E0
void TRIBE_Action_Make_Tech::get_info(short* param_1, short* param_2, char* param_3, short param_4) {
    if (param_1 != nullptr) {
        *param_1 = this->tech_id;
    }

    TRIBE_Player* player = nullptr;
    if (this->obj != nullptr) {
        player = (TRIBE_Player*)this->obj->owner;
    }

    if (param_2 != nullptr) {
        if (this->state == 1) {
            *param_2 = 100;
        } else if ((player != nullptr) && (player->tech_tree != nullptr)) {
            *param_2 = player->tech_tree->get_progress(this->tech_id);
        } else {
            *param_2 = 0;
        }
    }

    if ((param_3 != nullptr) && (param_4 > 0)) {
        param_3[0] = 0;
        if ((player != nullptr) && (player->tech_tree != nullptr)) {
            char* tech_name = player->tech_tree->get_name(this->tech_id);
            if (tech_name != nullptr) {
                strncpy(param_3, tech_name, (int)param_4);
            }
        }
        param_3[param_4 - 1] = 0;
    }
}
