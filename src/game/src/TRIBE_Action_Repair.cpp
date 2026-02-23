#include "../include/TRIBE_Action_Repair.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Task.h"
#include "../include/XYPoint.h"
#include "../include/globals.h"

#include <new>

TRIBE_Action_Repair::TRIBE_Action_Repair(int param_1, RGE_Action_Object* param_2, int param_3) {
    this->save_target_command_flag = 0;
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x6a;

    // The original ctor optionally calls setup(fd,obj) to read version-gated fields.
    if (param_3 != 0) {
        if (6.5f <= save_game_version) {
            rge_read(param_1, &this->save_target_command_flag, 1);
        } else {
            this->save_target_command_flag = 0;
        }
    }
}

TRIBE_Action_Repair::TRIBE_Action_Repair(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->action_type = 0x6a;
    this->task = param_2;
    this->save_target_command_flag = 0;
    this->set_target_obj(param_3);
    if (param_3 != nullptr) {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        this->target_z = param_3->world_z;
        this->meet_target();
    }
}

TRIBE_Action_Repair::TRIBE_Action_Repair(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->action_type = 0x6a;
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
    this->save_target_command_flag = 0;
}

TRIBE_Action_Repair::~TRIBE_Action_Repair() {}

int TRIBE_Action_Repair::setup(RGE_Action_Object* param_1) { this->save_target_command_flag = 0; int r = RGE_Action::setup(param_1); this->action_type = 0x6a; return r; }

int TRIBE_Action_Repair::setup(int param_1, RGE_Action_Object* param_2) {
    int r = RGE_Action::setup(param_1, param_2);
    this->action_type = 0x6a;
    if (6.5f <= save_game_version) {
        rge_read(param_1, &this->save_target_command_flag, 1);
    } else {
        this->save_target_command_flag = 0;
    }
    return r;
}

RGE_Action_List* TRIBE_Action_Repair::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void TRIBE_Action_Repair::rehook() { RGE_Action::rehook(); }
void TRIBE_Action_Repair::save(int param_1) {
    // Fully verified. Source of truth: tact_rep.cpp.decomp @ 0x004D1850
    RGE_Action::save(param_1);
    rge_write(param_1, &this->save_target_command_flag, 1);
}
short TRIBE_Action_Repair::type() { return this->action_type; }

void TRIBE_Action_Repair::first_in_stack(uchar param_1) {
    if ((param_1 != 0) && (this->target_obj != nullptr)) {
        this->set_state(4);
        return;
    }
    this->set_state(3);
}

uchar TRIBE_Action_Repair::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar TRIBE_Action_Repair::idle_update() { return RGE_Action::idle_update(); }

void TRIBE_Action_Repair::meet_target() {
    // Fully verified. Source of truth: tact_rep.cpp.asm @ 0x004D2020
    if (!this->obj || !this->target_obj) {
        return;
    }

    RGE_Master_Static_Object* target_master = this->target_obj->master_obj;
    if (!target_master) {
        return;
    }

    // Matches the original filter on a short field in the target's master object.
    const short v = *(short*)((char*)target_master + 0x14);
    if (v != 2 && v != 0x14 && v != 0x15 && v != 0x16) {
        return;
    }

    RGE_Object_Node* node = (this->obj->owner && this->obj->owner->objects) ? this->obj->owner->objects->list : nullptr;
    while (node) {
        RGE_Static_Object* other_raw = node->node;
        node = node->next;

        if (!other_raw || other_raw == this->obj) {
            continue;
        }

        // The original checks a short field in the other object's master object against 0x9C.
        if (!other_raw->master_obj || other_raw->master_obj->id != (short)0x9C) {
            continue;
        }

        RGE_Action_Object* other = (RGE_Action_Object*)other_raw;
        if (other->get_target_obj() != this->target_obj) {
            continue;
        }

        if (other->actionState() != 2) {
            if (this->obj->actionState() == 0x0B && this->obj->actions) {
                RGE_Action* act = this->obj->actions->get_action();
                if (act) {
                    this->target_x = act->target_x;
                    this->target_y = act->target_y;
                }
                return;
            }

            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            return;
        }
    }

    XYPoint start{};
    XYPoint dest{};
    XYPoint rVal{};
    start.x = (int)this->obj->world_x;
    start.y = (int)this->obj->world_y;
    dest.x = (int)this->target_obj->world_x;
    dest.y = (int)this->target_obj->world_y;

    if (this->obj->firstTileAlongLine(&start, &dest, &rVal, 2, 2, 1) == 1) {
        this->target_x = (float)rVal.x + 0.5f;
        this->target_y = (float)rVal.y + 0.5f;
        this->obj->moveTo(this->target_x, this->target_y, this->obj->world_z, 0.0f, 1);
        this->save_target_command_flag = this->obj->command_flag;
    }
}

void TRIBE_Action_Repair::set_state(uchar param_1) {
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
    }
    this->state = param_1;

    if (param_1 == 4) {
        if ((this->sub_actions != nullptr) && (this->task != nullptr) && (this->target_obj != nullptr)) {
            RGE_Action* move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range, this->task->move_sprite);
            if (move != nullptr) {
                move->setSubAction(1);
                this->sub_actions->add_action(move);
                return;
            }
        }
        this->state = 0x0d;
    }
}

uchar TRIBE_Action_Repair::update() {
    // Fully verified. Source of truth: tact_rep.cpp.asm @ 0x004D1BB0
    if (!this->obj) {
        return 0;
    }

    RGE_Game_World* world = (this->obj->owner != nullptr) ? this->obj->owner->world : nullptr;
    if (this->targetID != -1 && world != nullptr && world->object(this->targetID) == nullptr) {
        this->set_target_obj(nullptr);
        this->set_state(1);
        return 0;
    }

    if (this->target2ID != -1 && world != nullptr && world->object(this->target2ID) == nullptr) {
        this->set_target_obj2(nullptr);
    }

    if (this->target_obj != nullptr) {
        if (this->target_obj->object_state != 2) {
            this->set_target_obj(nullptr);
            this->set_state(1);
            return 0;
        }

        if (this->obj->owner != nullptr && this->target_obj->owner != nullptr) {
            if (this->obj->owner->isAlly((int)this->target_obj->owner->id) == 0) {
                this->set_target_obj(nullptr);
                this->set_state(1);
                return 0;
            }
        }
    }

    const float kDistBias = 2.0f;
    const float kDistThresh = 0.4f;

    switch ((char)this->state) {
    case 1:
        return 1;

    case 4: {
        const uchar sub_result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (sub_result) {
        case 1:
        case 2:
        case 3: {
            float dist = (this->target_obj != nullptr) ? this->obj->distance_to_object(this->target_obj) : 0.0f;
            if ((dist - kDistBias) <= kDistThresh) {
                this->set_state(6);
                return 0;
            }
            this->set_state(10);
            return 0;
        }
        case 4:
        case 5:
            this->set_target_obj(nullptr);
            this->set_state(1);
            return 0;
        default:
            break;
        }
        break;
    }

    case 6:
        if (this->target_obj == nullptr) {
            this->set_state(1);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0.0f, 0.0f) != 0) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == nullptr) {
            this->set_state(1);
            return 0;
        }

        if (this->target_obj->world_x != this->target_x || this->target_obj->world_y != this->target_y) {
            const float dist = this->obj->distance_to_object(this->target_obj);
            if (kDistThresh < (dist - kDistBias)) {
                this->set_state(3);
                return 0;
            }
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            return 0;
        }

        const float work_val1 = (this->task != nullptr) ? this->task->work_val1 : 0.0f;
        const float dt = (world != nullptr) ? world->world_time_delta_seconds : 0.0f;
        const float work_rate = (this->obj->master_obj != nullptr) ? ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate : 0.0f;
        const float repair_amount = work_val1 * dt * work_rate;

        RGE_Action_Object* target = (RGE_Action_Object*)this->target_obj;
        const uchar heal_result = target->heal(repair_amount);
        if (heal_result == 1) {
            this->set_state(1);
            return 0;
        }
        if (heal_result == 2) {
            const int id = (int)this->obj->id;
            this->obj->notify(id, id, 0x1FB, 0x26A, 0, 0);
            if (rge_base_game != nullptr && this->obj->master_obj != nullptr && this->target_obj != nullptr) {
                rge_base_game->notification(0x6B, (long)this->obj->master_obj->id, (long)this->target_obj->id, 0, 0);
            }
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 10:
        if (this->target_obj != nullptr) {
            this->timer = this->timer - ((world != nullptr) ? world->world_time_delta_seconds : 0.0f);
            if (this->timer <= 0.0f) {
                const float dist = this->obj->distance_to_object(this->target_obj);
                if ((dist - kDistBias) <= kDistThresh) {
                    this->set_state(6);
                    return 0;
                }
                this->timer = 1.0f;
                return 0;
            }
        }
        break;

    case 0x0B: {
        const uchar sub_result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (sub_result) {
        case 1:
        case 2:
        case 3:
        case 5:
            this->set_state(1);
            return 0;
        case 4:
            this->set_target_obj(nullptr);
            this->set_state(0x0B);
            return 0;
        default:
            break;
        }
        break;
    }

    case 0x0D: {
        const int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x1F9, 0x26A, 0, 0);
        this->set_state(2);
        return 3;
    }

    default:
        break;
    }

    return 0;
}

int TRIBE_Action_Repair::stop() {
    // Fully verified. Source of truth: tact_rep.cpp.decomp @ 0x004D1F50
    this->set_state(2);
    return 1;
}

int TRIBE_Action_Repair::move_to(RGE_Static_Object* /*param_1*/, float param_2, float param_3, float param_4) {
    // Fully verified. Source of truth: tact_rep.cpp.decomp @ 0x004D1F60
    this->target_y = param_3;
    this->target_x = param_2;
    this->target_z = param_4;
    this->set_target_obj(nullptr);
    this->set_state(0x0B);
    return 1;
}

int TRIBE_Action_Repair::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    // Fully verified. Source of truth: tact_rep.cpp.decomp @ 0x004D1FA0
    if (param_1 == nullptr) {
        this->target_y = param_3;
        this->target_x = param_2;
        this->target_z = param_4;
        this->set_target_obj(nullptr);
        this->set_state(0x0B);
        return 1;
    }

    const char st = (char)this->state;
    if (param_1 != this->target_obj || (st != 4 && st != 6)) {
        this->set_target_obj(param_1);
        this->target_x = param_1->world_x;
        this->target_y = param_1->world_y;
        this->target_z = param_1->world_z;
        this->meet_target();
        this->set_state(4);
        return 1;
    }

    return 1;
}
uchar TRIBE_Action_Repair::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar TRIBE_Action_Repair::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void TRIBE_Action_Repair::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void TRIBE_Action_Repair::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void TRIBE_Action_Repair::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* TRIBE_Action_Repair::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* TRIBE_Action_Repair::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void TRIBE_Action_Repair::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void TRIBE_Action_Repair::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

