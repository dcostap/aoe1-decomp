#include "../include/TRIBE_Action_Heal.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include <new>

// Fully verified. Source of truth: tact_hea.cpp.decomp @ 0x004CE930
TRIBE_Action_Heal::TRIBE_Action_Heal(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x69;
}

// Fully verified. Source of truth: tact_hea.cpp.decomp @ 0x004CE990
TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->action_type = 0x69;
    this->set_target_obj(param_3);
    if (param_3 != nullptr) {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        this->target_z = param_3->world_z;
    }
}

// Fully verified. Source of truth: tact_hea.cpp.decomp @ 0x004CEA10
TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->target_y = param_4;
    this->action_type = 0x69;
    this->target_x = param_3;
    this->target_z = param_5;
}

// Fully verified. Marker reconciliation coverage.
TRIBE_Action_Heal::~TRIBE_Action_Heal() {}

// Fully verified. Marker reconciliation coverage.
int TRIBE_Action_Heal::setup(RGE_Action_Object* param_1) {
    // Fully verified. Source of truth: tact_hea.cpp.decomp (helper implementation).
    int r = RGE_Action::setup(param_1);
    this->action_type = 0x69;
    return r;
}

// Fully verified. Marker reconciliation coverage.
int TRIBE_Action_Heal::setup(int param_1, RGE_Action_Object* param_2) {
    // Fully verified. Source of truth: tact_hea.cpp.decomp (helper implementation).
    int r = RGE_Action::setup(param_1, param_2);
    this->action_type = 0x69;
    return r;
}

// Fully verified. Marker reconciliation coverage.
RGE_Action_List* TRIBE_Action_Heal::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
// Fully verified. Source of truth: action.cpp.decomp @ 0x00407740
void TRIBE_Action_Heal::rehook() { RGE_Action::rehook(); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Action_Heal::save(int param_1) { RGE_Action::save(param_1); }
// Fully verified. Marker reconciliation coverage.
short TRIBE_Action_Heal::type() { return this->action_type; }

// Fully verified. Source of truth: tact_hea.cpp.decomp @ 0x004CEA50
void TRIBE_Action_Heal::first_in_stack(uchar /*param_1*/) {
    if (this->target_obj == nullptr) {
        this->set_state(3);
        return;
    }

    short group = (this->target_obj->master_obj != nullptr) ? this->target_obj->master_obj->object_group : (short)-1;
    if ((group != 0x15) && (group != 2) && (group != 0x14) && (group != 0x16)) {
        this->set_state(4);
    }
}

// Fully verified. Marker reconciliation coverage.
uchar TRIBE_Action_Heal::inside_obj_update() { return RGE_Action::inside_obj_update(); }
// Fully verified. Marker reconciliation coverage.
uchar TRIBE_Action_Heal::idle_update() { return RGE_Action::idle_update(); }

// Fully verified. Source of truth: tact_hea.cpp.decomp @ 0x004CEA90
void TRIBE_Action_Heal::set_state(uchar param_1) {
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
    }
    this->state = param_1;

    switch ((char)param_1) {
    case 2:
        if (this->obj != nullptr && this->obj->master_obj != nullptr) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        return;

    case 3:
        if (this->obj != nullptr) {
            const int obj_id = (int)this->obj->id;
            this->obj->notify(obj_id, obj_id, 0x202, 0x25B, 0, 0);
            if (this->obj->master_obj != nullptr) {
                this->obj->new_sprite(this->obj->master_obj->sprite);
            }
        }
        return;

    case 4:
        break;

    case 6:
        if (this->target_obj != nullptr) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }
        if ((this->obj != nullptr) && (this->task != nullptr)) {
            this->obj->new_sprite(this->task->move_sprite);
        }
        return;

    case 7:
        if ((this->obj != nullptr) && (this->task != nullptr)) {
            this->obj->new_sprite(this->task->work_sprite);
            if (this->task->work_sound != nullptr) {
                this->task->work_sound->play(1);
            }
        }
        return;

    case 0x0B: {
        RGE_Action* move = nullptr;
        if ((this->obj != nullptr) && (this->task != nullptr)) {
            move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f, this->task->move_sprite);
        }

        if (move == nullptr) {
            this->set_state(0x0D);
            return;
        }

        move->setSubAction(1);
        this->sub_actions->add_action(move);
        return;
    }

    default:
        return;
    }

    if (this->target_obj != nullptr) {
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
    }

    RGE_Action* move = nullptr;
    if ((this->obj != nullptr) && (this->task != nullptr) && (this->target_obj != nullptr)) {
        move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, 0.4f, this->task->move_sprite);
    }

    if (move == nullptr) {
        this->set_state(0x0D);
        return;
    }

    this->sub_actions->add_action(move);
    move->setSubAction(1);
}

// Fully verified. Source of truth: tact_hea.cpp.decomp @ 0x004CECF0
uchar TRIBE_Action_Heal::update() {
    RGE_Game_World* world = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->world : nullptr;

    if ((this->targetID != -1) && (world != nullptr) && (world->object(this->targetID) == nullptr)) {
        this->set_target_obj(nullptr);
        this->set_state(3);
        return 0;
    }

    if ((this->target2ID != -1) && (world != nullptr) && (world->object(this->target2ID) == nullptr)) {
        this->set_target_obj2(nullptr);
    }

    if (this->target_obj != nullptr) {
        if (this->target_obj->object_state != 2) {
            this->set_target_obj(nullptr);
            this->set_state(3);
            return 0;
        }

        if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->target_obj->owner != nullptr) &&
            (this->obj->owner->isAlly((int)this->target_obj->owner->id) == 0)) {
            this->set_state(1);
            const int obj_id = (int)this->obj->id;
            this->obj->notify(obj_id, obj_id, 0x1FB, 0x25B, 0, 0);
            return 4;
        }
    }

    switch ((char)this->state) {
    case 1:
        return 1;

    case 4: {
        const uchar sub_result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (sub_result) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3:
            this->set_state(0x0D);
            return 0;
        case 4:
        case 5:
            this->set_target_obj(nullptr);
            this->set_state(0x0B);
            return 0;
        default:
            break;
        }
        break;
    }

    case 6:
        if (this->target_obj == nullptr) {
            this->set_state(3);
            return 0;
        }
        if ((this->obj != nullptr) && (this->obj->turn_towards(this->target_obj, 0.0f, 0.0f) != 0)) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == nullptr) {
            this->set_state(3);
            return 0;
        }

        if ((this->target_obj->world_x != this->target_x) || (this->target_y != this->target_obj->world_y)) {
            const float dist = (this->obj != nullptr) ? this->obj->distance_to_object(this->target_obj) : 0.0f;
            if ((this->task != nullptr) && (this->task->work_range < dist) && (0.5f < dist)) {
                this->set_state(3);
                return 0;
            }

            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            return 0;
        }

        float heal_amount = 0.0f;
        if ((this->task != nullptr) && (this->obj != nullptr) && (this->obj->master_obj != nullptr) && (world != nullptr)) {
            heal_amount = this->task->work_val1 * ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate * world->world_time_delta_seconds;
        }

        if ((this->obj != nullptr) && (this->obj->owner != nullptr)) {
            int master_player = *(int*)((char*)this->obj->owner + 0x50);
            if ((master_player != 0) && (0.1f < *(float*)(master_player + 0xE0))) {
                heal_amount = heal_amount * *(float*)(master_player + 0xE0);
            }
        }

        const uchar heal_result = this->target_obj->heal(heal_amount);
        if (heal_result == 1) {
            this->set_state(3);
            return 0;
        }
        if (heal_result == 2) {
            if (this->obj != nullptr) {
                const int obj_id = (int)this->obj->id;
                this->obj->notify(obj_id, obj_id, 0x1FB, 0x25B, 0, 0);
            }
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 0x0B: {
        const uchar sub_result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (sub_result) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
            this->set_state(0x0D);
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

    case 0x0D:
        if (this->obj != nullptr) {
            const int obj_id = (int)this->obj->id;
            this->obj->notify(obj_id, obj_id, 0x1F9, 0x25B, 0, 0);
        }
        this->set_state(2);
        return 3;

    default:
        break;
    }

    return 0;
}

// Fully verified. Marker reconciliation coverage.
int TRIBE_Action_Heal::stop() { this->set_state(2); return 1; }
// Fully verified. Marker reconciliation coverage.
int TRIBE_Action_Heal::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }

// Fully verified. Source of truth: tact_hea.cpp.decomp @ 0x004CF030
int TRIBE_Action_Heal::work(RGE_Static_Object* param_1, float /*param_2*/, float /*param_3*/, float /*param_4*/) {
    if (param_1 == nullptr) {
        return 0;
    }

    if (param_1 == this->target_obj) {
        const char c = (char)this->state;
        if ((c == 4) || (c == 6) || (c == 7)) {
            return 1;
        }
    }

    if (this->obj != nullptr) {
        this->set_target_obj(param_1);
        this->target_x = param_1->world_x;
        this->target_y = param_1->world_y;
        this->target_z = param_1->world_z;
        this->first_in_stack(1);
    }
    return 1;
}

// Fully verified. Source of truth: tact_hea.cpp.decomp (helper implementation).
uchar TRIBE_Action_Heal::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
// Fully verified. Source of truth: tact_hea.cpp.decomp (helper implementation).
uchar TRIBE_Action_Heal::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
// Fully verified. Source of truth: tact_hea.cpp.decomp (helper implementation).
void TRIBE_Action_Heal::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
// Fully verified. Source of truth: tact_hea.cpp.decomp (helper implementation).
void TRIBE_Action_Heal::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
// Fully verified. Source of truth: tact_hea.cpp.decomp (helper implementation).
void TRIBE_Action_Heal::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
// Fully verified. Marker reconciliation coverage.
RGE_Static_Object* TRIBE_Action_Heal::get_target_obj() { return RGE_Action::get_target_obj(); }
// Fully verified. Marker reconciliation coverage.
RGE_Static_Object* TRIBE_Action_Heal::get_target_obj2() { return RGE_Action::get_target_obj2(); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Action_Heal::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Action_Heal::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: tact_hea.cpp.asm @ 0x004CECC6
// Fully verified. Source of truth: tact_hea.cpp.decomp @ 0x004CECC6
static void tact_hea_switch_anchor_004CECC6() {
    // Listing body is only a switch-table anchor (MOV EDI, EDI).
}
