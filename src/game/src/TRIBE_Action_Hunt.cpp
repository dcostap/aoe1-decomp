#include "../include/TRIBE_Action_Hunt.h"

#include "../include/RGE_Action_Attack.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include <new>

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CF090
TRIBE_Action_Hunt::TRIBE_Action_Hunt(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x6E;
    rge_read(param_1, &this->targetType, 4);
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CF130
TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->action_type = 0x6E;
    this->set_target_obj(param_3);
    if ((param_3 != nullptr) && (param_3->object_state < 7)) {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        this->target_z = param_3->world_z;
        this->targetType = (int)param_3->master_obj->id;
    }
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CF1C0, tact_hnt.cpp.asm @ 0x004CF1C0
TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->target_y = param_4;
    this->action_type = 0x6E;
    this->target_x = param_3;
    this->target_z = param_5;
    this->targetType = -1;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
TRIBE_Action_Hunt::~TRIBE_Action_Hunt() {}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
int TRIBE_Action_Hunt::setup(RGE_Action_Object* param_1) {
    int r = RGE_Action::setup(param_1);
    this->action_type = 0x6E;
    this->targetType = -1;
    return r;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
int TRIBE_Action_Hunt::setup(int param_1, RGE_Action_Object* param_2) {
    int r = RGE_Action::setup(param_1, param_2);
    this->action_type = 0x6E;
    rge_read(param_1, &this->targetType, 4);
    return r;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
RGE_Action_List* TRIBE_Action_Hunt::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
void TRIBE_Action_Hunt::rehook() { RGE_Action::rehook(); }

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CF210
void TRIBE_Action_Hunt::save(int param_1) {
    RGE_Action::save(param_1);
    rge_write(param_1, &this->targetType, 4);
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
short TRIBE_Action_Hunt::type() { return this->action_type; }

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CF240
void TRIBE_Action_Hunt::first_in_stack(uchar param_1) {
    if ((this->task != nullptr) && (this->obj != nullptr) && (this->task->attribute_type != this->obj->attribute_type_held)) {
        this->obj->set_attribute(this->task->attribute_type, 0.0f);
    }

    if (param_1 != 0) {
        if (this->target_obj == nullptr) {
            this->set_state(3);
            return;
        }

        if ((this->obj != nullptr) && (this->target_obj->owner == this->obj->owner) && (this->obj->master_obj != nullptr)) {
            RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->obj->master_obj;
            short target_master_id = (this->target_obj->master_obj != nullptr) ? this->target_obj->master_obj->id : (short)-1;
            if (((target_master_id == master->drop_site) || (target_master_id == master->backup_drop_site)) && (0.0f < this->obj->attribute_amount_held)) {
                this->set_target_obj2(this->target_obj);
                this->set_target_obj(nullptr);
                this->target_x = -1.0f;
                this->target_y = -1.0f;
                this->target_z = -1.0f;
                this->set_state(8);
                return;
            }
        }

        this->set_state(4);
        return;
    }

    this->set_state(3);
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
uchar TRIBE_Action_Hunt::inside_obj_update() { return RGE_Action::inside_obj_update(); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
uchar TRIBE_Action_Hunt::idle_update() { return RGE_Action::idle_update(); }

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CF300, tact_hnt.cpp.asm @ 0x004CF300
void TRIBE_Action_Hunt::set_state(uchar param_1) {
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
    }
    this->state = param_1;

    RGE_Action* action = nullptr;

    switch ((char)param_1) {
    case 1:
    case 0x0D:
    case 0x0E:
        this->set_target_obj2(nullptr);
        if (this->obj != nullptr) {
            this->obj->new_sprite(this->get_wait_sprite());
        }
        return;

    case 2:
        if (this->obj != nullptr) {
            this->obj->new_sprite(this->get_wait_sprite());
        }
        this->set_target_obj(nullptr);
        this->set_target_obj2(nullptr);
        this->timer = 0.0f;
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 3:
        if (this->obj != nullptr) {
            const int obj_id = (int)this->obj->id;
            this->obj->notify(obj_id, obj_id, 0x202, 0x265, this->targetType, 0);
            this->obj->new_sprite(this->get_wait_sprite());
        }
        this->timer = -0.4375f;
        return;

    case 4:
        this->set_target_obj2(nullptr);
        if (this->target_obj == nullptr) {
            this->set_state(0x0D);
            return;
        }
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        if (this->target_obj->object_state < 3) {
            this->set_state(0x0C);
            return;
        }
        if ((this->obj != nullptr) && (this->task != nullptr)) {
            action = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range, this->get_move_sprite());
        }
        break;

    case 5:
        this->set_target_obj2(nullptr);
        if (this->obj != nullptr) {
            this->obj->new_sprite(this->get_move_sprite());
        }
        return;

    case 6:
        this->set_target_obj2(nullptr);
        if ((this->task != nullptr) && (this->obj != nullptr) && (this->task->attribute_type != this->obj->attribute_type_held)) {
            this->obj->set_attribute(this->task->attribute_type, 0.0f);
        }
        if ((this->obj != nullptr) && (this->task != nullptr)) {
            this->obj->new_sprite(this->task->work_sprite2);
            if (this->task->work_sound != nullptr) {
                this->task->work_sound->play(1);
            }
        }
        return;

    case 7: {
        if ((this->target_obj != nullptr) && (this->target_obj->attribute_amount_held <= 0.0f)) {
            if ((this->target_obj2 != nullptr) && (this->target_obj2->attribute_amount_held <= 0.0f)) {
                this->set_target_obj(nullptr);
            }
            this->set_state(3);
            return;
        }

        if (this->target_obj2 == nullptr) {
            RGE_Master_Action_Object* master = (this->obj != nullptr && this->obj->master_obj != nullptr) ? (RGE_Master_Action_Object*)this->obj->master_obj : nullptr;
            if ((master == nullptr) || (master->drop_site == -1)) {
                this->set_target_obj2(nullptr);
            } else if ((this->target_obj != nullptr) && (this->target_obj->owner != nullptr) && (this->target_obj->owner->objects != nullptr)) {
                this->set_target_obj2(this->target_obj->owner->objects->find_by_master_ids((long)master->drop_site, (long)master->backup_drop_site,
                                                                                            this->target_obj->world_x, this->target_obj->world_y, 1, 2, this->target_obj));
            }

            if (this->target_obj2 == nullptr) {
                if (this->obj != nullptr) {
                    const int obj_id = (int)this->obj->id;
                    this->obj->notify(obj_id, obj_id, 0x203, 0x265, 0, 0);
                    if ((this->obj->owner != nullptr) && (this->obj->owner->computerPlayer() == 0)) {
                        this->set_state(2);
                    } else {
                        this->set_state(1);
                    }
                }
                return;
            }
        }

        if ((this->obj != nullptr) && (this->task != nullptr)) {
            action = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj2, this->task->work_range, this->get_move_sprite());
        }
        break;
    }

    case 0x0B:
    case 0x0F:
        this->set_target_obj2(nullptr);
        if ((this->obj != nullptr) && (this->task != nullptr)) {
            action = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->task->work_range, this->get_move_sprite());
        }
        if (action == nullptr) {
            this->set_state(0x0D);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;

    case 0x0C: {
        this->set_target_obj2(nullptr);
        if ((this->obj != nullptr) && (this->target_obj != nullptr) && (this->task != nullptr) && (this->obj->master_obj != nullptr)) {
            RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->obj->master_obj;
            action = new (std::nothrow) RGE_Action_Attack(this->obj, this->target_obj, this->get_move_sprite(), this->task->work_sprite, nullptr,
                                                          this->task->work_range, master->weapon_range, master->missile_id, master->fire_missile_at_frame);
        }
        break;
    }

    default:
        return;
    }

    if (action == nullptr) {
        this->set_state(0x0D);
        return;
    }

    this->sub_actions->add_action(action);
    action->setSubAction(1);
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CF860, tact_hnt.cpp.asm @ 0x004CF860
uchar TRIBE_Action_Hunt::update() {
    RGE_Game_World* world = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->world : nullptr;

    if ((this->targetID != -1) && (world != nullptr) && (world->object(this->targetID) == nullptr)) {
        this->set_target_obj(nullptr);
    }
    if ((this->target2ID != -1) && (world != nullptr) && (world->object(this->target2ID) == nullptr)) {
        this->set_target_obj2(nullptr);
    }

    if ((this->target_obj != nullptr) && (6 < this->target_obj->object_state)) {
        this->set_target_obj(nullptr);
    }
    if ((this->target_obj2 != nullptr) && (6 < this->target_obj2->object_state)) {
        this->set_target_obj2(nullptr);
    }

    switch ((char)this->state) {
    case 1:
        if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->computerPlayer() == 0)) {
            this->set_state(2);
        }
        return 1;

    case 3:
        if (this->timer < 0.0f) {
            this->timer = this->timer + ((world != nullptr) ? world->world_time_delta_seconds : 0.0f);
            if (0.0f < this->timer) {
                this->timer = -10.0f;
                if (this->obj != nullptr) {
                    const int obj_id = (int)this->obj->id;
                    this->obj->notify(obj_id, obj_id, 0x202, 0x265, this->targetType, 0);
                }
                return 0;
            }
        }
        break;

    case 4: {
        const uchar sub_result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (sub_result) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3:
            if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->computerPlayer() == 1)) {
                this->set_state(0x0D);
            } else {
                this->set_state(3);
            }
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
            if (this->target_obj->attribute_amount_held <= 0.0f) {
                this->set_target_obj(nullptr);
                this->set_state(3);
                return 0;
            }
            this->set_state(7);
            return 0;
        }
        this->set_state(3);
        return 0;

    case 7: {
        if (this->target_obj == nullptr) {
            if ((this->obj != nullptr) && (0.0f < this->obj->attribute_amount_held)) {
                this->set_state(8);
            } else {
                this->set_state(3);
            }
            return 0;
        }

        float give_amount = 0.0f;
        if ((rge_base_game != nullptr) && (rge_base_game->quick_build == 0) && (this->task != nullptr) && (this->obj != nullptr) &&
            (this->obj->master_obj != nullptr) && (world != nullptr)) {
            give_amount = this->task->work_val1 * ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate * world->world_time_delta_seconds;
        } else {
            give_amount = this->target_obj->attribute_amount_held;
        }
        if (this->target_obj->attribute_amount_held < give_amount) {
            give_amount = this->target_obj->attribute_amount_held;
        }

        float modifier = 1.0f;
        if ((this->obj != nullptr) && (this->task != nullptr) && (this->task->attribute_type2 != -1) && (this->obj->owner != nullptr)) {
            float* mods = *(float**)((char*)this->obj->owner + 0x50);
            if (mods != nullptr) {
                modifier = mods[this->task->attribute_type2];
            }
        }

        float max_hold = 0.0f;
        if ((this->obj != nullptr) && (this->obj->master_obj != nullptr)) {
            max_hold = (float)(int)this->obj->master_obj->attribute_max_amount * modifier;
            const float cap = max_hold - this->obj->attribute_amount_held;
            const float scaled = modifier * give_amount;
            if (cap < scaled) {
                give_amount = give_amount - (scaled - cap) / modifier;
            }
        }

        this->target_obj->set_attribute_amount(-give_amount, 1, 1);
        if (this->obj != nullptr) {
            this->obj->set_attribute_amount(give_amount, 1, 0);
            if ((max_hold <= this->obj->attribute_amount_held) || (this->target_obj->attribute_amount_held <= 0.0f)) {
                this->set_state(8);
                return 0;
            }
        }
        break;
    }

    case 8: {
        if (this->timer < 0.0f) {
            this->timer = this->timer + ((world != nullptr) ? world->world_time_delta_seconds : 0.0f);
            if (0.0f < this->timer) {
                this->timer = 0.0f;
                this->set_target_obj2(nullptr);
                this->set_state(8);
                return 0;
            }
            break;
        }

        const uchar sub_result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (sub_result) {
        case 1:
        case 2:
            if (this->target_obj2 == nullptr) {
                this->set_state(8);
                return 0;
            }
            if (this->obj == nullptr) {
                this->set_state(8);
                return 0;
            }

            if (1.0f < this->obj->distance_to_object(this->target_obj2)) {
                this->timer = -3.0f;
                this->obj->stop_moving();
                return 0;
            }

            if ((this->task != nullptr) && (this->task->work_sound2 != nullptr)) {
                this->task->work_sound2->play(1);
            }

            if (this->obj->owner != nullptr) {
                short attr = (this->task != nullptr) ? this->task->attribute_type3 : (short)-1;
                if (attr == -1) {
                    attr = this->obj->attribute_type_held;
                }
                this->obj->owner->add_attribute_num(attr, this->obj->attribute_amount_held, 0);
                this->obj->owner->trackUnitGather((int)this->obj->id, (int)attr, (int)this->obj->attribute_amount_held);
            }
            this->obj->set_attribute(-1, 0.0f);

            if (this->target_obj != nullptr) {
                this->set_target_obj2(nullptr);
                this->set_state(4);
                return 0;
            }
            if ((this->target_x != -1.0f) && (this->target_y != -1.0f)) {
                this->set_state(0x0B);
                return 0;
            }
            if ((this->obj->owner != nullptr) && (this->obj->owner->computerPlayer() == 0)) {
                this->set_state(2);
            } else {
                this->set_state(1);
            }
            return 0;

        case 3:
        case 4:
        case 5:
            this->timer = -3.0f;
            if (this->obj != nullptr) {
                this->obj->stop_moving();
            }
            return 0;

        default:
            break;
        }
        break;
    }

    case 0x0B:
    case 0x0F: {
        const uchar sub_result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (sub_result) {
        case 1:
        case 2:
        case 5:
            if (this->state == 0x0B) {
                this->set_state(3);
                return 0;
            }
            if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->computerPlayer() == 0)) {
                this->set_state(2);
            } else {
                this->set_state(1);
            }
            return 0;
        case 3:
            if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->computerPlayer() == 1)) {
                this->set_state(0x0D);
            } else {
                this->set_state(3);
            }
            return 0;
        case 4:
            this->set_target_obj(nullptr);
            if (this->state == 0x0B) {
                this->set_state(0x0B);
            } else {
                this->set_state(0x0F);
            }
            return 0;
        default:
            break;
        }
        break;
    }

    case 0x0C: {
        const uchar sub_result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (sub_result) {
        case 1:
        case 2:
        case 5:
            if (this->target_obj != nullptr) {
                this->set_state(4);
                return 0;
            }
            [[fallthrough]];
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
            this->obj->notify(obj_id, obj_id, 0x1F9, 0x265, 0, 0);
        }
        return 3;

    default:
        break;
    }

    return 0;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CFF20
RGE_Sprite* TRIBE_Action_Hunt::get_move_sprite() {
    if ((this->task != nullptr) && (this->obj != nullptr) && (this->task->attribute_type != -1) && (this->task->attribute_type == this->obj->attribute_type_held) &&
        ((int)this->obj->attribute_amount_held > 0) && (this->task->carry_sprite != nullptr)) {
        return this->task->carry_sprite;
    }
    return (this->task != nullptr) ? this->task->move_sprite : nullptr;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CFF50
RGE_Sprite* TRIBE_Action_Hunt::get_wait_sprite() {
    if ((this->task != nullptr) && (this->obj != nullptr) && (this->task->attribute_type != -1) && (this->task->attribute_type == this->obj->attribute_type_held) &&
        ((int)this->obj->attribute_amount_held > 0) && (this->task->carry_sprite != nullptr)) {
        return this->task->carry_sprite;
    }
    return (this->obj != nullptr && this->obj->master_obj != nullptr) ? this->obj->master_obj->sprite : nullptr;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CFF90
int TRIBE_Action_Hunt::stop() {
    if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->computerPlayer() == 0)) {
        this->set_state(2);
        return 1;
    }
    this->set_state(1);
    return 1;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004CFFD0
int TRIBE_Action_Hunt::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if ((param_1 != nullptr) && (this->obj != nullptr) && (param_1->owner == this->obj->owner) && (this->obj->master_obj != nullptr)) {
        RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->obj->master_obj;
        short target_master_id = (param_1->master_obj != nullptr) ? param_1->master_obj->id : (short)-1;
        if (((target_master_id == master->drop_site) || (target_master_id == master->backup_drop_site)) && (0.0f < this->obj->attribute_amount_held)) {
            if ((param_1 == this->target_obj2) && ((char)this->state == '\b')) {
                return 1;
            }
            this->set_target_obj(nullptr);
            this->target_x = -1.0f;
            this->target_y = -1.0f;
            this->target_z = -1.0f;
            this->set_target_obj2(param_1);
            this->set_state(8);
            return 1;
        }
    }

    this->target_z = param_4;
    this->target_x = param_2;
    this->target_y = param_3;
    this->set_target_obj(nullptr);
    this->set_state(0x0F);
    return 1;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080
int TRIBE_Action_Hunt::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 == nullptr) {
        this->target_z = param_4;
        this->target_x = param_2;
        this->target_y = param_3;
        this->set_target_obj(nullptr);
        this->set_state(0x0F);
        return 1;
    }

    if ((this->obj != nullptr) && (param_1->owner == this->obj->owner) && (this->obj->master_obj != nullptr)) {
        RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->obj->master_obj;
        short target_master_id = (param_1->master_obj != nullptr) ? param_1->master_obj->id : (short)-1;
        if (((target_master_id == master->drop_site) || (target_master_id == master->backup_drop_site)) && (0.0f < this->obj->attribute_amount_held)) {
            this->set_target_obj(nullptr);
            this->set_target_obj2(param_1);
            this->target_x = -1.0f;
            this->target_y = -1.0f;
            this->target_z = -1.0f;
            this->set_state(8);
            return 1;
        }
    }

    this->set_target_obj(param_1);
    this->set_target_obj2(nullptr);
    this->set_state(4);
    return 1;
}

// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
uchar TRIBE_Action_Hunt::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
uchar TRIBE_Action_Hunt::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
void TRIBE_Action_Hunt::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
void TRIBE_Action_Hunt::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
void TRIBE_Action_Hunt::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
RGE_Static_Object* TRIBE_Action_Hunt::get_target_obj() { return RGE_Action::get_target_obj(); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
RGE_Static_Object* TRIBE_Action_Hunt::get_target_obj2() { return RGE_Action::get_target_obj2(); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
void TRIBE_Action_Hunt::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
// Fully verified. Source of truth: tact_hnt.cpp.decomp @ 0x004D0080 (virtual forwarding coverage).
void TRIBE_Action_Hunt::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }
