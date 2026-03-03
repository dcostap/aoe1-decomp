#include "../include/TRIBE_Action_Convert.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Task.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <new>

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CD9E0
TRIBE_Action_Convert::TRIBE_Action_Convert(int param_1, RGE_Action_Object* param_2) {
    this->requiredRange = 1.0f;
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x68;
    rge_read(param_1, &this->was_same_owner, 1);
    rge_read(param_1, &this->requiredRange, 4);
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CDA90
TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->requiredRange = 1.0f;
    this->action_type = 0x68;
    this->set_target_obj(param_3);
    if (param_3 != nullptr) {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        this->target_z = param_3->world_z;
    }
    this->was_same_owner = 0;
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CDB20
TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->target_y = param_4;
    this->requiredRange = 1.0f;
    this->action_type = 0x68;
    this->target_x = param_3;
    this->target_z = param_5;
    this->was_same_owner = 0;
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
TRIBE_Action_Convert::~TRIBE_Action_Convert() {}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
int TRIBE_Action_Convert::setup(RGE_Action_Object* param_1) {
    this->was_same_owner = 0;
    this->requiredRange = 1.0f;
    int res = RGE_Action::setup(param_1);
    this->action_type = 0x68;
    return res;
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
int TRIBE_Action_Convert::setup(int param_1, RGE_Action_Object* param_2) {
    this->was_same_owner = 0;
    this->requiredRange = 1.0f;
    int res = RGE_Action::setup(param_1, param_2);
    this->action_type = 0x68;
    rge_read(param_1, &this->was_same_owner, 1);
    rge_read(param_1, &this->requiredRange, 4);
    return res;
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
RGE_Action_List* TRIBE_Action_Convert::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
void TRIBE_Action_Convert::rehook() { RGE_Action::rehook(); }

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CDB70
void TRIBE_Action_Convert::save(int param_1) {
    RGE_Action::save(param_1);
    rge_write(param_1, &this->was_same_owner, 1);
    rge_write(param_1, &this->requiredRange, 4);
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
short TRIBE_Action_Convert::type() { return this->action_type; }

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CDBB0, tact_cnv.cpp.asm @ 0x004CDBB0
void TRIBE_Action_Convert::first_in_stack(uchar param_1) {
    if (this->target_obj != nullptr) {
        short target_group = (this->target_obj->master_obj != nullptr) ? this->target_obj->master_obj->object_group : (short)-1;
        short target_master_id = (this->target_obj->master_obj != nullptr) ? this->target_obj->master_obj->id : (short)-1;

        if ((this->obj != nullptr) && (this->obj->owner == this->target_obj->owner)) {
            this->was_same_owner = 1;
        } else {
            this->was_same_owner = 0;
        }

        if ((target_master_id == 0x6D) || (target_group == 0x1B) || (target_master_id == 0x9F) || (target_master_id == 0x9E) ||
            (target_master_id == 0xA3) || (target_master_id == 0x114)) {
            if ((this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->computerPlayer() == 1)) {
                this->set_state(0x0B);
            } else {
                this->set_state(0x0D);
            }

            if ((this->obj != nullptr) && (this->obj->master_obj != nullptr) && (this->obj->owner != nullptr) && (rge_base_game != nullptr)) {
                if (this->obj->master_obj->id == 0x6D) {
                    rge_base_game->notification(0x79, (long)this->obj->owner->id, 0, 0, 0);
                } else if (this->obj->master_obj->id == 0x114) {
                    rge_base_game->notification(0x7A, (long)this->obj->owner->id, 0, 0, 0);
                }
            }
            return;
        }

        if ((this->obj != nullptr) && (this->obj->attribute_amount_held < 100.0f)) {
            this->set_state(0x0D);
            if ((this->obj->owner != nullptr) && (rge_base_game != nullptr)) {
                rge_base_game->notification(0x76, (long)this->obj->owner->id, 0, 0, 0);
            }
            return;
        }

        if (target_group == 3) {
            this->requiredRange = 1.0f;
        } else if ((this->obj != nullptr) && (this->obj->master_obj != nullptr)) {
            this->requiredRange = ((RGE_Master_Combat_Object*)this->obj->master_obj)->weapon_range;
        }

        if (target_group == 0x1E) {
            this->set_state(0x0D);
            return;
        }

        if ((target_group == 0x12) && (this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->attributes[0x1B] <= 0.0f)) {
            if (this->obj->owner->computerPlayer() == 1) {
                this->set_state(0x0B);
            } else {
                this->set_state(0x0D);
            }
            if (rge_base_game != nullptr) {
                rge_base_game->notification(0x77, (long)this->obj->owner->id, 0, 0, 0);
            }
            return;
        }

        if ((target_group == 3) && (this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->attributes[0x1C] <= 0.0f)) {
            if (this->obj->owner->computerPlayer() == 1) {
                this->set_state(0x0B);
            } else {
                this->set_state(0x0D);
            }
            if (rge_base_game != nullptr) {
                rge_base_game->notification(0x78, (long)this->obj->owner->id, 0, 0, 0);
            }
            return;
        }
    }

    if (param_1 == 0) {
        this->set_state(3);
        return;
    }
    if (this->target_obj == nullptr) {
        this->set_state(3);
        return;
    }
    this->set_state(4);
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
uchar TRIBE_Action_Convert::inside_obj_update() { return RGE_Action::inside_obj_update(); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
uchar TRIBE_Action_Convert::idle_update() { return RGE_Action::idle_update(); }

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CDE10, tact_cnv.cpp.asm @ 0x004CDE10
void TRIBE_Action_Convert::set_state(uchar param_1) {
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
    }
    this->state = param_1;

    switch ((char)param_1) {
    case 3:
        if (this->obj != nullptr) {
            const int obj_id = (int)this->obj->id;
            this->obj->notify(obj_id, obj_id, 0x202, 0x25C, 0, 0);
        }
        [[fallthrough]];

    case 1:
    case 2:
    case 0x0D:
    case 0x0E:
        if ((this->obj != nullptr) && (this->obj->master_obj != nullptr)) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        return;

    case 4: {
        RGE_Action* move = nullptr;
        if ((this->obj != nullptr) && (this->target_obj != nullptr) && (this->task != nullptr)) {
            move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, this->requiredRange, this->task->move_sprite);
        }

        if (move == nullptr) {
            this->set_state(0x0D);
            return;
        }

        this->sub_actions->add_action(move);
        move->setSubAction(1);
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
        if ((this->target_obj != nullptr) && (this->target_obj->owner != nullptr) && (0 < this->target_obj->owner->id)) {
            this->target_obj->owner->notify(0x70, (int)this->obj->world_x, (int)this->obj->world_y, (long)this->obj->world_z, 0, 0);
        }
        this->timer = (this->task != nullptr) ? this->task->work_val2 : 0.0f;
        return;

    case 0x0B: {
        RGE_Action* move = nullptr;
        if ((this->obj != nullptr) && (this->task != nullptr)) {
            move = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->requiredRange, this->task->move_sprite);
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
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE070, tact_cnv.cpp.asm @ 0x004CE070
uchar TRIBE_Action_Convert::update() {
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
            (this->obj->owner->isAlly((int)this->target_obj->owner->id) == 1)) {
            const char st = (char)this->state;
            if ((st == 7) || (st == 6) || (st == 4)) {
                this->obj->set_attribute(0x22, 0.0f);
            }
            this->set_state(1);
            const int obj_id = (int)this->obj->id;
            this->obj->notify(obj_id, obj_id, 0x1FB, 0x25C, 0, 0);
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

        if (this->obj != nullptr) {
            const short obj_max = (this->target_obj->master_obj != nullptr) ? this->target_obj->master_obj->obj_max : (short)0;
            this->target_obj->notify((int)this->obj->id, (int)this->target_obj->id, 500, (long)this->obj->id, (long)obj_max, 0);
        }

        this->timer = this->timer - ((world != nullptr) ? world->world_time_delta_seconds : 0.0f);
        if (this->timer <= 0.0f) {
            if ((this->target_obj->owner != nullptr) && (0 < this->target_obj->owner->id)) {
                this->target_obj->owner->notify(0x70, (int)this->obj->world_x, (int)this->obj->world_y, (long)this->obj->world_z, 0, 0);
            }

            int rv = debug_rand("C:\\msdev\\work\\age1_x1\\tact_cnv.cpp", 0x1D7);
            float convert_chance = (float)rv * 3.051851e-05f;

            RGE_Player* target_owner = this->target_obj->owner;
            if ((target_owner != nullptr) && (*((char*)target_owner + 0x105) == 0x10)) {
                convert_chance = convert_chance * 4.0f;
            } else if (this->target_obj->master_obj != nullptr) {
                short group = this->target_obj->master_obj->object_group;
                if ((group == 0x15) || (group == 2) || (group == 0x14) || (group == 0x16) || (group == 0x12)) {
                    convert_chance = convert_chance * 2.0f;
                } else if ((group == 0x23) || (group == 0x17)) {
                    convert_chance = convert_chance * 8.0f;
                }
            }

            float threshold = 0.0f;
            if ((this->task != nullptr) && (this->obj != nullptr) && (this->obj->master_obj != nullptr)) {
                threshold = this->task->work_val1 * ((RGE_Master_Combat_Object*)this->obj->master_obj)->work_rate;
            }

            if (convert_chance <= threshold) {
                if ((rge_base_game != nullptr) && (this->obj != nullptr) && (this->obj->owner != nullptr) && (this->target_obj->owner != nullptr)) {
                    rge_base_game->notification(0x7B, (long)this->obj->owner->id, (long)this->target_obj->owner->id, 0, 0);
                }
                if ((this->obj != nullptr) && (this->obj->owner != nullptr)) {
                    this->target_obj->change_ownership(this->obj->owner);
                    this->obj->owner->add_attribute_num(0x29, 1.0f, 0);
                    this->obj->set_attribute(0x22, 0.0f);
                }
                this->set_state(3);
            }

            this->set_state(4);
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
            this->obj->notify(obj_id, obj_id, 0x1F9, 0x25C, 0, 0);
        }
        this->set_state(2);
        return 3;

    default:
        break;
    }

    return 0;
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
int TRIBE_Action_Convert::stop() { this->set_state(2); return 1; }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
int TRIBE_Action_Convert::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450
int TRIBE_Action_Convert::work(RGE_Static_Object* param_1, float /*param_2*/, float /*param_3*/, float /*param_4*/) {
    if (param_1 == nullptr) {
        return 0;
    }

    if (param_1 == this->target_obj) {
        char state = (char)this->state;
        if ((state == 4) || (state == 6) || (state == 7)) {
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

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE4B0
void TRIBE_Action_Convert::martyrdom() {
    if (((char)this->state == 7) && (this->target_obj != nullptr) && (this->target_obj->master_obj != nullptr) && (this->target_obj->master_obj->object_group != 0x12)) {
        if ((rge_base_game != nullptr) && (this->obj != nullptr) && (this->obj->owner != nullptr) && (this->target_obj->owner != nullptr)) {
            rge_base_game->notification(0x7B, (long)this->obj->owner->id, (long)this->target_obj->owner->id, 0, 0);
        }
        if ((this->obj != nullptr) && (this->obj->owner != nullptr)) {
            this->target_obj->change_ownership(this->obj->owner);
            this->obj->owner->add_attribute_num(0x29, 1.0f, 0);
            this->obj->set_attribute(0x22, 0.0f);
        }
        this->set_state(3);
    }
}

// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
uchar TRIBE_Action_Convert::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
uchar TRIBE_Action_Convert::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
void TRIBE_Action_Convert::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
void TRIBE_Action_Convert::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
void TRIBE_Action_Convert::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
RGE_Static_Object* TRIBE_Action_Convert::get_target_obj() { return RGE_Action::get_target_obj(); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
RGE_Static_Object* TRIBE_Action_Convert::get_target_obj2() { return RGE_Action::get_target_obj2(); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
void TRIBE_Action_Convert::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE450 (virtual forwarding coverage).
void TRIBE_Action_Convert::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }       

// Fully verified. Source of truth: tact_cnv.cpp.asm @ 0x004CE02D
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE02D
// TODO: PARITY [MODERATE] - No-op anchor from malformed decomp region; verify jump-table/case body is not missing from transliteration. [decomp: tact_cnv.cpp.decomp @ 0x004CE02D]
static void tact_cnv_switch_anchor_004CE02D() {
    // Listing body is only a switch-table anchor (NOP / MOV EDI, EDI).
}

// Fully verified. Source of truth: tact_cnv.cpp.asm @ 0x004CE3FA
// Fully verified. Source of truth: tact_cnv.cpp.decomp @ 0x004CE3FA
// TODO: PARITY [MODERATE] - No-op anchor from malformed decomp region; verify jump-table/case body is not missing from transliteration. [decomp: tact_cnv.cpp.decomp @ 0x004CE3FA]
static void tact_cnv_switch_anchor_004CE3FA() {
    // Listing body is only a switch-table anchor (MOV EDI, EDI).
}

