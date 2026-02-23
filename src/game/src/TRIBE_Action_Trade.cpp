#include "../include/TRIBE_Action_Trade.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include <new>

TRIBE_Action_Trade::TRIBE_Action_Trade(int param_1, RGE_Action_Object* param_2) {
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
    RGE_Action::setup(param_1, param_2);
    rge_read(param_1, &this->pick_up_x, 4);
    rge_read(param_1, &this->pick_up_y, 4);
    this->action_type = 0x6f;
}

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->action_type = 0x6f;
    this->task = param_2;
    this->set_target_obj(param_3);
    this->target_x = param_3->world_x;
    this->target_y = param_3->world_y;
    this->target_z = param_3->world_z;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
}

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->action_type = 0x6f;
    this->task = param_2;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
}

TRIBE_Action_Trade::~TRIBE_Action_Trade() {}

int TRIBE_Action_Trade::setup(RGE_Action_Object* param_1) { int r = RGE_Action::setup(param_1); this->action_type = 0x6f; this->pick_up_x = -1.0f; this->pick_up_y = -1.0f; return r; }
int TRIBE_Action_Trade::setup(int param_1, RGE_Action_Object* param_2) { int r = RGE_Action::setup(param_1, param_2); rge_read(param_1, &this->pick_up_x, 4); rge_read(param_1, &this->pick_up_y, 4); this->action_type = 0x6f; return r; }
RGE_Action_List* TRIBE_Action_Trade::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void TRIBE_Action_Trade::rehook() { RGE_Action::rehook(); }

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D27F0
void TRIBE_Action_Trade::save(int param_1) {
    RGE_Action::save(param_1);
    rge_write(param_1, &this->pick_up_x, 4);
    rge_write(param_1, &this->pick_up_y, 4);
}

short TRIBE_Action_Trade::type() { return this->action_type; }

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D2830
void TRIBE_Action_Trade::first_in_stack(uchar param_1) {
    // Attribute type sanity for this unit (matches original behavior).
    short attr_type = this->obj->attribute_type_held;
    if ((attr_type != 0) && (attr_type != 2) && (attr_type != 1)) {
        this->obj->attribute_type_held = 1;
    }

    if (param_1 != 0) {
        if (this->target_obj != nullptr) {
            this->set_state(4);
            return;
        }
        this->set_state(2);
        return;
    }
    this->set_state(3);
}

uchar TRIBE_Action_Trade::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar TRIBE_Action_Trade::idle_update() { return RGE_Action::idle_update(); }

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D2880
void TRIBE_Action_Trade::set_state(uchar param_1) {
    this->sub_actions->delete_list();
    this->state = param_1;

    switch ((char)param_1) {
    case 2: {
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(nullptr);
        this->set_target_obj2(nullptr);
        this->target_x = -4.0f;
        this->target_y = -4.0f;
        this->target_z = -4.0f;
        return;
    }

    case 3: {
        int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x202, 0x267, 0, 0);
        this->obj->new_sprite(this->get_wait_sprite());
        return;
    }

    case 4: {
        if (this->target_obj == nullptr) {
            this->set_state(0x0D);
            return;
        }

        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;

        RGE_Action_Move_To* move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range, this->get_move_sprite());
        if (move_to == nullptr) {
            this->set_state(0x0D);
            return;
        }

        move_to->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;
    }

    case 6:
        this->obj->new_sprite(this->get_move_sprite());
        return;

    case 7: {
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != nullptr) {
            this->task->work_sound->play(1);
        }

        if (this->target_obj != nullptr) {
            this->pick_up_x = this->target_obj->world_x;
            this->pick_up_y = this->target_obj->world_y;
        } else {
            this->pick_up_x = -1.0f;
            this->pick_up_y = -1.0f;
        }
        return;
    }

    case 8: {
        // No cargo: maybe invalidate the target and go back to searching.
        if (this->obj->attribute_amount_held <= 0.0f) {
            if ((this->target_obj != nullptr) && (this->target_obj->attribute_amount_held <= 0.0f)) {
                int target_master_id = (this->target_obj->master_obj != nullptr) ? (int)this->target_obj->master_obj->id : -1;
                if (this->obj->keepGatheringWhenObjectIsOut(target_master_id) == 0) {
                    this->set_target_obj(nullptr);
                    this->set_state(3);
                }
            }
            return;
        }

        // Has cargo: go to dropsite (target_obj2), selecting one if needed.
        RGE_Master_Action_Object* master = (this->obj->master_obj != nullptr) ? (RGE_Master_Action_Object*)this->obj->master_obj : nullptr;
        if (master != nullptr) {
            if ((this->target_obj2 == nullptr) ||
                (this->target_obj2->master_obj == nullptr) ||
                (this->target_obj2->master_obj->id != master->drop_site)) {
                if (master->drop_site == -1) {
                    this->set_target_obj2(nullptr);
                } else if ((this->obj->owner != nullptr) && (this->obj->owner->objects != nullptr)) {
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        (long)master->drop_site,
                        (long)master->backup_drop_site,
                        this->obj->world_x,
                        this->obj->world_y,
                        1,
                        2,
                        (RGE_Static_Object*)this->obj));
                }
            }
        }

        if (this->target_obj2 == nullptr) {
            int id = (int)this->obj->id;
            this->obj->notify(id, id, 0x203, 0x267, 0, 0);
            this->set_state(0x0D);
            return;
        }

        RGE_Action_Move_To* move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj2, 0.0f, this->get_move_sprite());
        if (move_to == nullptr) {
            this->set_state(0x0D);
            return;
        }

        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;
    }

    case 0x0B: {
        RGE_Action_Move_To* move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f, this->get_move_sprite());
        if (move_to == nullptr) {
            this->set_state(0x0D);
            return;
        }

        move_to->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;
    }

    default:
        return;
    }
}

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D2CB0
uchar TRIBE_Action_Trade::update() {
    if ((this->targetID != -1) && (this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->world != nullptr) &&
        (this->obj->owner->world->object(this->targetID) == nullptr)) {
        this->set_target_obj(nullptr);
    }

    if ((this->target2ID != -1) && (this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->world != nullptr) &&
        (this->obj->owner->world->object(this->target2ID) == nullptr)) {
        this->set_target_obj2(nullptr);
    }

    if ((this->target_obj != nullptr) && (6 < this->target_obj->object_state)) {
        this->set_target_obj(nullptr);
    }

    if ((this->target_obj2 != nullptr) && (6 < this->target_obj2->object_state)) {
        this->set_target_obj2(nullptr);
    }

    if ((this->target_obj != nullptr) && (this->obj != nullptr) && (this->obj->owner != nullptr) && (this->target_obj->owner != nullptr) &&
        (this->obj->owner->id == this->target_obj->owner->id)) {
        this->set_target_obj(nullptr);
        this->set_target_obj2(nullptr);
        this->set_state(1);

        if ((char)this->subActionValue == 0) {
            int id = (int)this->obj->id;
            this->obj->notify(id, id, 0x1FB, 0x267, this->targetID, 0);
        }

        return 4;
    }

    switch ((char)this->state) {
    case 1:
        return 1;

    case 4: {
        if (this->timer < 0.0f) {
            if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->world != nullptr)) {
                this->timer = this->obj->owner->world->world_time_delta_seconds + this->timer;
                if (0.0f < this->timer) {
                    this->timer = 0.0f;
                    if (this->target_obj != nullptr) {
                        this->set_state(4);
                        return 0;
                    }
                    this->set_state(3);
                    return 0;
                }
            }
            break;
        }

        uchar result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (result) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;

        case 3:
        case 4:
            this->timer = -8.0f;
            return 0;

        case 5:
            this->set_target_obj(nullptr);
            this->set_state(3);
            return 0;

        default:
            break;
        }
        break;
    }

    case 6: {
        if (this->target_obj == nullptr) {
            this->set_state(3);
            return 0;
        }

        if (this->obj != nullptr) {
            uchar turned = this->obj->turn_towards(this->target_obj, 0.0f, 0.0f);
            if (turned != 0) {
                int target_master_id = (this->target_obj->master_obj != nullptr) ? (int)this->target_obj->master_obj->id : -1;
                if ((0.0f < this->target_obj->attribute_amount_held) ||
                    (this->obj->keepGatheringWhenObjectIsOut(target_master_id) != 0)) {
                    this->set_state(7);
                    return 0;
                }

                this->set_target_obj(nullptr);
                this->set_state(3);
                return 0;
            }
        }
        break;
    }

    case 7: {
        if (this->target_obj == nullptr) {
            if ((this->obj != nullptr) && (0.0f < this->obj->attribute_amount_held)) {
                this->set_state(8);
                return 0;
            }
            this->set_state(3);
            return 0;
        }

        // Ensure we have a supported attribute type.
        short attr_type = this->obj->attribute_type_held;
        if ((attr_type != 0) && (attr_type != 2) && (attr_type != 1)) {
            this->obj->attribute_type_held = 1;
            attr_type = 1;
        }

        short carry_max_short = (this->obj->master_obj != nullptr) ? this->obj->master_obj->attribute_max_amount : (short)0;
        float carry_max = (float)(int)carry_max_short;

        float max_hold = carry_max - this->obj->attribute_amount_held;
        if ((this->obj->owner != nullptr) && (this->obj->owner->attributes != nullptr)) {
            float avail_attr = this->obj->owner->attributes[(int)attr_type];
            if (avail_attr < max_hold) {
                max_hold = avail_attr;
            }

            float avail_trade = this->obj->owner->attributes[9];
            if (avail_trade < max_hold) {
                max_hold = avail_trade;
            }
        }

        float take_amount = max_hold;
        if ((this->obj->owner != nullptr) && (this->obj->owner->attributes != nullptr)) {
            this->obj->owner->add_attribute_num(attr_type, -take_amount, 1);
            this->obj->owner->attributes[9] = this->obj->owner->attributes[9] - take_amount;
        }
        this->obj->attribute_amount_held = take_amount + this->obj->attribute_amount_held;

        if (!(this->obj->attribute_amount_held < carry_max)) {
            this->set_state(8);
            return 0;
        }

        if ((this->obj->owner != nullptr) && (this->obj->owner->attributes != nullptr) && (this->obj->owner->attributes[9] <= 0.0f)) {
            int target_master_id = (this->target_obj->master_obj != nullptr) ? (int)this->target_obj->master_obj->id : -1;
            if (this->obj->keepGatheringWhenObjectIsOut(target_master_id) == 0) {
                this->set_state(8);
                return 0;
            }
        }
        break;
    }

    case 8: {
        if (this->timer < 0.0f) {
            if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->world != nullptr)) {
                this->timer = this->obj->owner->world->world_time_delta_seconds + this->timer;
                if (0.0f < this->timer) {
                    this->timer = 0.0f;
                    this->set_state(8);
                    return 0;
                }
            }
            break;
        }

        uchar result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (result) {
        case 1:
        case 2:
            if (this->target_obj2 != nullptr) {
                if ((this->obj != nullptr) && (0.0f < this->obj->attribute_amount_held)) {
                    if (this->task->work_sound2 != nullptr) {
                        this->task->work_sound2->play(1);
                    }

                    float distance_mod = 0.35f;
                    if ((this->pick_up_x >= 0.0f) && (this->pick_up_y >= 0.0f)) {
                        float dx = this->pick_up_x - this->target_obj2->world_x;
                        float dy = this->pick_up_y - this->target_obj2->world_y;
                        distance_mod = (dy * dy + dx * dx) * 0.00025125628f * 0.7f;
                    }

                    // NOTE: Uses a raw player field offset per original codegen (checked in tact_trd.cpp.asm).
                    if ((this->obj->owner != nullptr) && (((uchar*)this->obj->owner)[0x105] == 0x0F)) {
                        distance_mod = distance_mod + distance_mod;
                    }

                    if (distance_mod < 0.35f) {
                        distance_mod = 0.35f;
                    }

                    float gold = this->obj->attribute_amount_held * distance_mod;
                    if (75.0f < gold) {
                        gold = 75.0f;
                    }

                    if (this->obj->owner != nullptr) {
                        this->obj->owner->add_attribute_num(3, gold, 1);
                    }

                    this->obj->set_attribute(this->obj->attribute_type_held, 0.0f);
                }

                if (this->target_obj != nullptr) {
                    this->set_state(4);
                    return 0;
                }
                this->set_state(3);
                return 0;
            }
            this->set_state(8);
            return 0;

        case 3:
        case 4:
        case 5:
            this->timer = -0.5f;
            return 0;

        default:
            break;
        }
        break;
    }

    case 0x0B: {
        if (this->timer < 0.0f) {
            if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->world != nullptr)) {
                this->timer = this->obj->owner->world->world_time_delta_seconds + this->timer;
                if (0.0f < this->timer) {
                    this->timer = 0.0f;
                    if (this->target_obj != nullptr) {
                        this->set_state(4);
                        return 0;
                    }
                    this->set_state(3);
                    return 0;
                }
            }
            break;
        }

        uchar result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (result) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;

        case 3:
        case 4:
            this->timer = -8.0f;
            return 0;

        default:
            break;
        }
        break;
    }

    case 0x0D: {
        if (this->obj != nullptr) {
            int id = (int)this->obj->id;
            this->obj->notify(id, id, 0x1F9, 0x267, 0, 0);
        }
        this->set_state(2);
        return 3;
    }

    default:
        break;
    }

    return 0;
}

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D3330
int TRIBE_Action_Trade::stop() {
    this->set_state(2);
    return 1;
}

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D3340
int TRIBE_Action_Trade::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if ((param_1 == nullptr) ||
        (this->obj == nullptr) ||
        (param_1->owner != this->obj->owner) ||
        (param_1->master_obj == nullptr) ||
        (this->obj->master_obj == nullptr) ||
        (param_1->master_obj->id != ((RGE_Master_Action_Object*)this->obj->master_obj)->drop_site)) {
        this->target_x = param_2;
        this->target_y = param_3;
        this->target_z = param_4;
        this->set_target_obj(nullptr);
        this->set_state(0x0B);
    } else if ((param_1 != this->target_obj2) || ((char)this->state != 8)) {
        this->set_target_obj2(param_1);
        this->set_state(8);
        return 1;
    }
    return 1;
}

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D33C0
int TRIBE_Action_Trade::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 != nullptr) {
        if ((param_1 == this->target_obj) && ((this->state == 4) || (this->state == 6) || (this->state == 7))) {
            return 1;
        }

        if ((this->obj != nullptr) && (param_1->owner == this->obj->owner) &&
            (param_1->master_obj != nullptr) && (this->obj->master_obj != nullptr) &&
            (param_1->master_obj->id == ((RGE_Master_Action_Object*)this->obj->master_obj)->drop_site)) {
            this->set_target_obj2(param_1);
            this->set_state(8);
            return 1;
        }

        this->set_target_obj(param_1);
        this->set_state(4);
        return 1;
    }

    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_target_obj(nullptr);
    this->set_state(0x0B);
    return 1;
}
uchar TRIBE_Action_Trade::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar TRIBE_Action_Trade::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void TRIBE_Action_Trade::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void TRIBE_Action_Trade::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void TRIBE_Action_Trade::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* TRIBE_Action_Trade::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* TRIBE_Action_Trade::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void TRIBE_Action_Trade::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void TRIBE_Action_Trade::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D32C0
RGE_Sprite* TRIBE_Action_Trade::get_move_sprite() {
    RGE_Task* cur_task = this->task;

    if ((cur_task->attribute_type != -1) && (this->obj != nullptr) &&
        (this->obj->attribute_type_held == cur_task->attribute_type) &&
        ((int)this->obj->attribute_amount_held > 0) && (cur_task->carry_sprite != nullptr)) {
        return cur_task->carry_sprite;
    }

    return cur_task->move_sprite;
}

// Fully verified. Source of truth: tact_trd.cpp.decomp @ 0x004D32F0
RGE_Sprite* TRIBE_Action_Trade::get_wait_sprite() {
    RGE_Task* cur_task = this->task;
    if ((cur_task->attribute_type != -1) && (this->obj != nullptr) &&
        (this->obj->attribute_type_held == cur_task->attribute_type) &&
        ((int)this->obj->attribute_amount_held > 0) && (cur_task->carry_sprite != nullptr)) {
        return cur_task->carry_sprite;
    }

    RGE_Master_Static_Object* master = (this->obj != nullptr) ? this->obj->master_obj : nullptr;
    return (master != nullptr) ? master->sprite : nullptr;
}

