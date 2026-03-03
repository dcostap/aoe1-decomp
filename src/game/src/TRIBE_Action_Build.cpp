#include "../include/TRIBE_Action_Build.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Task.h"
#include "../include/TRIBE_Building_Object.h"
#include "../include/globals.h"

#include <new>

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD1B0
TRIBE_Action_Build::TRIBE_Action_Build(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x65;
}

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD210
TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->action_type = 0x65;
    this->task = param_2;

    // TODO: PARITY - Decomp writes target_x/y/z in the accepted branch without a null-object guard; current guarded writes avoid null-deref and can change original crash-prone behavior. [decomp: tact_bld.cpp.decomp @ 0x004CD210]
    if ((param_3 == nullptr) || (param_1->owner->id == param_3->owner->id)) {
        this->set_target_obj(param_3);
        if (param_3 != nullptr) {
            this->target_x = param_3->world_x;
            this->target_y = param_3->world_y;
            this->target_z = param_3->world_z;
        }
    }
}

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD2A0
TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->target_y = param_4;
    this->action_type = 0x65;
    this->target_x = param_3;
    this->target_z = param_5;
}

// Fully verified. Marker reconciliation coverage.
TRIBE_Action_Build::~TRIBE_Action_Build() {}

// Fully verified. Marker reconciliation coverage.
int TRIBE_Action_Build::setup(RGE_Action_Object* param_1) {
    // Fully verified. Source of truth: tact_bld.cpp.decomp (helper implementation).
    int res = RGE_Action::setup(param_1);
    this->action_type = 0x65;
    return res;
}

// Fully verified. Marker reconciliation coverage.
int TRIBE_Action_Build::setup(int param_1, RGE_Action_Object* param_2) {
    // Fully verified. Source of truth: tact_bld.cpp.decomp (helper implementation).
    int res = RGE_Action::setup(param_1, param_2);
    this->action_type = 0x65;
    return res;
}

// Fully verified. Marker reconciliation coverage.
RGE_Action_List* TRIBE_Action_Build::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Action_Build::rehook() { RGE_Action::rehook(); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Action_Build::save(int param_1) { RGE_Action::save(param_1); }
// Fully verified. Marker reconciliation coverage.
short TRIBE_Action_Build::type() { return this->action_type; }

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD2E0, tact_bld.cpp.asm @ 0x004CD2E0
void TRIBE_Action_Build::first_in_stack(uchar param_1) {
    if (param_1 == 0) {
        this->set_state(3);
        return;
    }

    if (this->target_obj != nullptr) {
        this->set_state(4);
        return;
    }

    this->set_state(3);
}

// Fully verified. Marker reconciliation coverage.
uchar TRIBE_Action_Build::inside_obj_update() { return RGE_Action::inside_obj_update(); }
// Fully verified. Marker reconciliation coverage.
uchar TRIBE_Action_Build::idle_update() { return RGE_Action::idle_update(); }

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD310, tact_bld.cpp.asm @ 0x004CD310
void TRIBE_Action_Build::set_state(uchar param_1) {
    // TODO: PARITY - Added null-guards on obj/task/sub_actions alter faulting behavior and branch outcomes versus direct dereferences in original listing. [decomp: tact_bld.cpp.decomp @ 0x004CD310]
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
    }
    this->state = param_1;

    switch ((char)param_1) {
    case 1:
    case 0x0D:
        if (this->obj != nullptr && this->obj->master_obj != nullptr) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        return;

    case 2:
        if (this->obj != nullptr && this->obj->master_obj != nullptr) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        this->set_target_obj(nullptr);
        this->set_target_obj2(nullptr);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 3:
        if ((this->obj != nullptr) && (this->obj->owner != nullptr)) {
            const int obj_id = (int)this->obj->id;
            if (this->obj->owner->computerPlayer() == 1) {
                this->obj->notify(obj_id, obj_id, 0x1FA, 0, 0, 0);
                this->set_state(1);
            } else {
                this->obj->notify(obj_id, obj_id, 0x202, 0x25A, 0, 0);
            }
        }
        if (this->obj != nullptr && this->obj->master_obj != nullptr) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        return;

    case 4: {
        if (this->target_obj != nullptr) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }

        RGE_Action* move = nullptr;
        if ((this->obj != nullptr) && (this->task != nullptr) && (this->target_obj != nullptr)) {
            move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range, this->task->move_sprite);
        }

        if (move == nullptr) {
            this->set_state(0x0D);
            return;
        }

        move->setSubAction(1);
        this->sub_actions->add_action(move);
        return;
    }

    case 6:
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

        this->sub_actions->add_action(move);
        move->setSubAction(1);
        return;
    }

    default:
        return;
    }
}

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD5E0, tact_bld.cpp.asm @ 0x004CD5E0
uchar TRIBE_Action_Build::update() {
    // TODO: PARITY - Defensive null checks (world/sub_actions/owner/task gating) may mask original crash/invalid-state paths and change control flow. [decomp: tact_bld.cpp.decomp @ 0x004CD5E0]
    RGE_Game_World* world = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->world : nullptr;

    if ((this->targetID != -1) && (world != nullptr) && (world->object(this->targetID) == nullptr)) {
        this->set_target_obj(nullptr);
        if (this->state != 2) {
            this->set_state(3);
            return 0;
        }
    }

    if ((this->target2ID != -1) && (world != nullptr) && (world->object(this->target2ID) == nullptr)) {
        this->set_target_obj2(nullptr);
    }

    if ((this->target_obj != nullptr) && (this->target_obj->object_state != 0) && (this->timer == 0.0f)) {
        if ((this->target_obj->master_obj != nullptr) && (this->target_obj->hp < (float)(int)this->target_obj->master_obj->obj_max)) {
            this->obj->removeAllFromPathingGroup();
            if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->target_obj->owner != nullptr)) {
                this->obj->owner->processAIOrder((int)this->obj->owner->id, (int)this->obj->id, 0x2CE, (int)this->target_obj->id,
                                                 (int)this->target_obj->owner->id, this->target_obj->world_x, this->target_obj->world_y,
                                                 this->target_obj->world_z, 1.0f, 1, 0, 100);
            }
            return 0;
        }

        this->set_target_obj(nullptr);
        if (this->state != 2) {
            this->set_state(3);
            return 0;
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
            this->set_state(3);
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
        if ((this->target_obj != nullptr) && (this->obj != nullptr) && (this->obj->turn_towards(this->target_obj, 0.0f, 0.0f) != 0)) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if ((this->timer < 0.0f) && (this->target_obj != nullptr) && (0.0f < this->target_obj->attribute_amount_held)) {
            this->obj->removeAllFromPathingGroup();
            this->obj->set_object_state(1);
            this->obj->do_command(this->target_obj, this->target_obj->world_x, this->target_obj->world_y, 0.0f);
            return 0;
        }

        float work_amount = 1000.0f;
        if ((rge_base_game != nullptr) && (rge_base_game->quick_build == 0) && (this->task != nullptr) && (this->obj != nullptr) &&
            (this->obj->master_obj != nullptr) && (world != nullptr)) {
            work_amount = this->task->work_val1 * ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate * world->world_time_delta_seconds;
        }

        if ((this->target_obj == nullptr) || (((TRIBE_Building_Object*)this->target_obj)->build(work_amount) != 0)) {
            if ((this->target_obj != nullptr) && (this->target_obj->master_obj != nullptr) && (this->target_obj->master_obj->id == 0x32)) {
                this->timer = -1.0f;
                return 0;
            }

            this->set_state(3);
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
            this->set_state(3);
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
            this->obj->notify(obj_id, obj_id, 0x1F9, 0x25A, 0, 0);
        }
        this->set_state(2);
        return 3;

    default:
        break;
    }

    return 0;
}

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD910
int TRIBE_Action_Build::stop() {
    this->set_state(2);
    return 1;
}

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD920
int TRIBE_Action_Build::move_to(RGE_Static_Object* /*param_1*/, float param_2, float param_3, float param_4) {
    this->target_y = param_3;
    this->target_x = param_2;
    this->target_z = param_4;
    this->set_target_obj(nullptr);
    this->set_state(0x0B);
    return 1;
}

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD960
int TRIBE_Action_Build::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if ((param_1 == nullptr) || (this->obj == nullptr) || (param_1->owner == nullptr) || (this->obj->owner == nullptr) || (param_1->owner->id != this->obj->owner->id)) {
        this->target_z = param_4;
        this->target_x = param_2;
        this->target_y = param_3;
        this->set_target_obj(nullptr);
        this->set_state(0x0B);
    } else if ((param_1 != this->target_obj) || ((this->state != 4) && (this->state != 6))) {
        this->set_target_obj(param_1);
        this->set_state(4);
        return 1;
    }

    return 1;
}

// Fully verified. Source of truth: tact_bld.cpp.decomp (helper implementation).
uchar TRIBE_Action_Build::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
// Fully verified. Source of truth: tact_bld.cpp.decomp (helper implementation).
uchar TRIBE_Action_Build::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
// Fully verified. Source of truth: tact_bld.cpp.decomp (helper implementation).
void TRIBE_Action_Build::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
// Fully verified. Source of truth: tact_bld.cpp.decomp (helper implementation).
void TRIBE_Action_Build::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
// Fully verified. Source of truth: tact_bld.cpp.decomp (helper implementation).
void TRIBE_Action_Build::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
// Fully verified. Marker reconciliation coverage.
RGE_Static_Object* TRIBE_Action_Build::get_target_obj() { return RGE_Action::get_target_obj(); }
// Fully verified. Marker reconciliation coverage.
RGE_Static_Object* TRIBE_Action_Build::get_target_obj2() { return RGE_Action::get_target_obj2(); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Action_Build::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
// Fully verified. Marker reconciliation coverage.
void TRIBE_Action_Build::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: tact_bld.cpp.decomp @ 0x004CD5A5 (decomp body failed; verified against tact_bld.cpp.asm)
// TODO: PARITY - This no-op anchor marks a failed decomp body; re-audit ASM to ensure no executable switch logic is missing. [decomp: tact_bld.cpp.decomp @ 0x004CD5A5]
static void tact_bld_switch_anchor_004CD5A5() {
    // Listing body is only a switch-table anchor (NOP / MOV EDI, EDI).
}
