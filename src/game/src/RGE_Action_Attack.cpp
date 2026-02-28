#include "../include/RGE_Action_Attack.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Active_Sprite_List.h"
#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Visible_Map.h"
#include "../include/UnitAIModule.h"

#include "../include/globals.h"

#include <math.h>
#include <new>

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401746
// ASM shows a switch jump-table shim (MOV EDI, EDI), not a standalone callable function body.
// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401A8E
// ASM shows a switch jump-table shim (MOV EDI, EDI), not a standalone callable function body.

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401000
RGE_Action_Attack::RGE_Action_Attack(int param_1, RGE_Action_Object* param_2) {
    this->setup(param_1, param_2);
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401170
RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Sprite* param_3, RGE_Sprite* param_4,
                                     RGE_Sprite* param_5, float param_6, float param_7, short param_8, short param_9) {
    this->setup(param_1);
    this->set_target_obj(param_2);
    this->wait_sprite = param_5;
    this->range = param_6;
    this->min_range = param_7;
    this->missile_id = param_8;
    this->target_x = -4.0f;
    this->target_y = -4.0f;
    this->target_z = -4.0f;
    this->move_sprite = param_3;
    this->fight_sprite = param_4;
    this->fire_missile_at_frame = param_9;
    this->need_to_attack = 0;
    this->indirect_fire_flag = 0;
    this->was_same_owner = ((param_2 != nullptr) && (param_2->owner == param_1->owner)) ? 1 : 0;

    RGE_Master_Combat_Object* master = (param_1 != nullptr) ? (RGE_Master_Combat_Object*)param_1->master_obj : nullptr;
    if ((this->move_sprite == nullptr) && (master != nullptr)) {
        this->move_sprite = (master->move_sprite != nullptr) ? master->move_sprite : master->sprite;
    }
    if ((this->fight_sprite == nullptr) && (master != nullptr)) {
        this->fight_sprite = master->fight_sprite;
    }
    if ((this->wait_sprite == nullptr) && (master != nullptr)) {
        this->wait_sprite = master->sprite;
    }

    if (this->range == 0.0f) {
        this->range = (master != nullptr) ? master->weapon_range : 0.0f;
        if (this->range == 0.0f) {
            this->range = 0.4f;
        }
    }
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x004012B0
RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, RGE_Sprite* param_5,
                                     RGE_Sprite* param_6, RGE_Sprite* param_7, float param_8, float param_9, short param_10, short param_11) {
    this->setup(param_1);
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->range = param_8;
    this->min_range = param_9;
    this->missile_id = param_10;
    this->move_sprite = param_5;
    this->fight_sprite = param_6;
    this->wait_sprite = param_7;
    this->fire_missile_at_frame = param_11;
    this->need_to_attack = 0;
    this->was_same_owner = 0;
    this->indirect_fire_flag = 2;

    RGE_Master_Combat_Object* master = (param_1 != nullptr) ? (RGE_Master_Combat_Object*)param_1->master_obj : nullptr;
    if ((this->move_sprite == nullptr) && (master != nullptr)) {
        this->move_sprite = (master->move_sprite != nullptr) ? master->move_sprite : master->sprite;
    }
    if ((this->fight_sprite == nullptr) && (master != nullptr)) {
        this->fight_sprite = master->fight_sprite;
    }
    if ((this->wait_sprite == nullptr) && (master != nullptr)) {
        this->wait_sprite = master->sprite;
    }

    if (this->range == 0.0f) {
        this->range = (master != nullptr) ? master->weapon_range : 0.0f;
        if (this->range == 0.0f) {
            this->range = 0.4f;
        }
    }
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x004013A0
RGE_Action_Attack::~RGE_Action_Attack() = default;

// Factory initialization path (used by RGE_Action_List); not present as a standalone function in act_atak.cpp.*.
int RGE_Action_Attack::setup(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 9;
    this->move_sprite = nullptr;
    this->fight_sprite = nullptr;
    this->wait_sprite = nullptr;
    this->range = 0.0f;
    this->min_range = 0.0f;
    this->missile_id = -1;
    this->fire_missile_at_frame = -1;
    this->need_to_attack = 0;
    this->was_same_owner = 0;
    this->indirect_fire_flag = 0;
    return 1;
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401000
int RGE_Action_Attack::setup(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 9;

    rge_read(param_1, &this->range, 4);
    rge_read(param_1, &this->min_range, 4);
    rge_read(param_1, &this->missile_id, 2);
    rge_read(param_1, &this->fire_missile_at_frame, 2);
    rge_read(param_1, &this->need_to_attack, 1);
    rge_read(param_1, &this->was_same_owner, 1);
    rge_read(param_1, &this->indirect_fire_flag, 1);

    short sprite_id = -1;
    rge_read(param_1, &sprite_id, 2);
    this->move_sprite = ((param_2 != nullptr) && (sprite_id >= 0)) ? param_2->get_sprite_pointer(sprite_id) : nullptr;

    rge_read(param_1, &sprite_id, 2);
    this->fight_sprite = ((param_2 != nullptr) && (sprite_id >= 0)) ? param_2->get_sprite_pointer(sprite_id) : nullptr;

    rge_read(param_1, &sprite_id, 2);
    this->wait_sprite = ((param_2 != nullptr) && (sprite_id >= 0)) ? param_2->get_sprite_pointer(sprite_id) : nullptr;

    return 1;
}

RGE_Action_List* RGE_Action_Attack::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Attack::rehook() { RGE_Action::rehook(); }
short RGE_Action_Attack::type() { return RGE_Action::type(); }
uchar RGE_Action_Attack::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Attack::idle_update() { return RGE_Action::idle_update(); }
int RGE_Action_Attack::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
uchar RGE_Action_Attack::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Attack::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Attack::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Attack::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Attack::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Attack::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Attack::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Attack::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x004013B0
void RGE_Action_Attack::save(int param_1) {
    RGE_Action::save(param_1);
    rge_write(param_1, &this->range, 4);
    rge_write(param_1, &this->min_range, 4);
    rge_write(param_1, &this->missile_id, 2);
    rge_write(param_1, &this->fire_missile_at_frame, 2);
    rge_write(param_1, &this->need_to_attack, 1);
    rge_write(param_1, &this->was_same_owner, 1);
    rge_write(param_1, &this->indirect_fire_flag, 1);

    short sprite_id = (this->move_sprite != nullptr) ? this->move_sprite->id : (short)-1;
    rge_write(param_1, &sprite_id, 2);
    sprite_id = (this->fight_sprite != nullptr) ? this->fight_sprite->id : (short)-1;
    rge_write(param_1, &sprite_id, 2);
    sprite_id = (this->wait_sprite != nullptr) ? this->wait_sprite->id : (short)-1;
    rge_write(param_1, &sprite_id, 2);
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x004014B0
void RGE_Action_Attack::first_in_stack(uchar /*param_1*/) {
    float max_speed = (this->obj != nullptr) ? this->obj->maximumSpeed() : 0.0f;
    if (max_speed != 0.0f) {
        UnitAIModule* unit_ai = (this->obj != nullptr) ? this->obj->unitAIValue : nullptr;
        if ((unit_ai == nullptr) || (unit_ai->currentOrderValue != 0x2d5)) {
            this->set_state(4);
            return;
        }
    }

    int rangeStatus = -1;
    int can_attack = this->ready_to_attack(rangeStatus);
    if ((can_attack == 0) && (rangeStatus != 1)) {
        this->set_state(0x0D);
        return;
    }
    this->set_state(6);
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401540
int RGE_Action_Attack::stop() {
    this->set_state(1);
    return 1;
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401550
void RGE_Action_Attack::set_state(uchar param_1) {
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 1:
    case 0x0D:
    case 0x0E:
        if (this->obj != nullptr) {
            this->obj->new_sprite(this->wait_sprite);
        }
        return;

    case 2:
        this->indirect_fire_flag = 0;
        return;

    case 4: {
        if (this->indirect_fire_flag != 0) {
            this->indirect_fire_flag = (uchar)(this->indirect_fire_flag - 1);
        }

        RGE_Action_Move_To* move_to = nullptr;
        if (this->target_obj == nullptr) {
            move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->range, this->move_sprite);
        } else {
            move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, this->range, this->move_sprite);
        }

        if (move_to == nullptr) {
            if (((char)this->subActionValue == '\0') && (this->obj != nullptr)) {
                int id = (int)this->obj->id;
                this->obj->notify(id, id, 0x1f9, 0x262, 0, 0);
            }
            this->set_state(1);
            return;
        }

        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        this->timer = 0.0f;
        return;
    }

    case 6: {
        if ((this->indirect_fire_flag != 0) && (this->target_obj != nullptr)) {
            this->indirect_fire_flag = 0;
        }

        int rangeStatus = -1;
        if (this->ready_to_attack(rangeStatus) != 0) {
            if (this->obj != nullptr) {
                ((RGE_Combat_Object*)this->obj)->reset_attack_timer();
            }
            this->set_state(7);
            return;
        }

        if (this->obj != nullptr) {
            RGE_Sprite* sprite = (this->missile_id != -1) ? this->wait_sprite : this->fight_sprite;
            this->obj->new_sprite(sprite);
        }
        return;
    }

    case 7:
        if (this->obj != nullptr) {
            this->obj->new_sprite(this->fight_sprite);
        }
        this->need_to_attack = 1;
        return;
    }
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401780
uchar RGE_Action_Attack::update() {
    RGE_Game_World* world = this->obj->owner->world;
    this->timer = this->timer + world->world_time_delta_seconds;

    if ((this->targetID != -1) && (world->object(this->targetID) == nullptr)) {
        this->set_target_obj(nullptr);
        this->set_state(2);
        return 5;
    }

    if ((this->target2ID != -1) && (world->object(this->target2ID) == nullptr)) {
        this->set_target_obj2(nullptr);
    }

    if (this->target_obj != nullptr) {
        if (2 < this->target_obj->object_state) {
            this->set_target_obj(nullptr);
            this->set_state(2);
            return 5;
        }

        if ((this->obj->owner != nullptr) && (this->obj->owner->id != 0) && (this->target_obj->owner != nullptr) &&
            (this->obj->owner->isAlly((int)this->target_obj->owner->id) != 0)) {
            this->set_state(1);
            if (((char)this->subActionValue == '\0') && (this->obj != nullptr)) {
                int id = (int)this->obj->id;
                this->obj->notify(id, id, 0x1fb, 600, this->targetID, 0);
            }
            return 4;
        }
    }

    if ((this->target_obj != nullptr) && (this->target_obj->inside_obj != nullptr)) {
        this->set_state(1);
        if (((char)this->subActionValue == '\0') && (this->obj != nullptr)) {
            int id = (int)this->obj->id;
            this->obj->notify(id, id, 0x1fb, 600, this->targetID, 0);
        }
        return 4;
    }

    switch (this->state) {
    case 1:
        return 1;

    case 2: {
        if (this->obj->sprite_list->looped(this->obj->sprite) == 1) {
            this->set_target_obj(nullptr);
            if (((char)this->subActionValue == '\0') && (this->obj != nullptr)) {
                int id = (int)this->obj->id;
                this->obj->notify(id, id, 0x1fa, 600, 0, 0);
            }
            this->set_state(1);

            // (subActionValue == 1) ? 5 : 2
            return (this->subActionValue == 1) ? 5 : 2;
        }
        break;
    }

    case 4: {
        uchar subResult = this->sub_actions->update();
        switch (subResult) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3:
            this->set_state(0x0D);
            if ((char)this->subActionValue != '\0') {
                return 3;
            }
            // fallthrough to state 0x0D notify
            break;
        case 4:
            this->set_state(0x0E);
            if (((char)this->subActionValue == '\0') && (this->obj != nullptr)) {
                int id = (int)this->obj->id;
                this->obj->notify(id, id, 0x1fb, 600, this->targetID, 0);
            }
            return 4;
        default:
            return 0;
        }
        // fallthrough for subResult == 3 and subActionValue == 0
    } break;

    case 6: {
        int rangeStatus = -1;
        if (this->ready_to_attack(rangeStatus) != 0) {
            ((RGE_Combat_Object*)this->obj)->reset_attack_timer();
            this->set_state(7);
        }
        return 0;
    }

    case 7: {
        if (this->need_to_attack == 0) {
            if (this->obj->can_attack() == 1) {
                if ((this->target_obj == nullptr) && (this->indirect_fire_flag == 0)) {
                    this->set_state(2);
                    return 0;
                }

                ((RGE_Combat_Object*)this->obj)->reset_attack_timer();

                this->set_state(6);
                if ((this->state == 0x0D) || (this->state == 4)) {
                    return 0;
                }
                this->set_state(7);
            }

            if (this->need_to_attack == 0) {
                if ((this->obj->sprite_list->looped(this->obj->sprite) != 1) && ((this->obj->sprite->flag & 1) != 0)) {
                    return 0;
                }

                if ((this->target_obj == nullptr) && (this->indirect_fire_flag == 0)) {
                    this->set_state(2);
                    return 0;
                }

                this->set_state(6);
                return 0;
            }
        }

        short fire_frame = this->fire_missile_at_frame;
        if (this->fire_missile_at_frame == 0) {
            short sprite_frames = (this->obj->sprite != nullptr) ? this->obj->sprite->frame_num : (short)0;
            fire_frame = (short)(int)((float)(int)sprite_frames * 0.5f);
        }

        if (this->obj->sprite_list->frame_passed(this->obj->sprite, fire_frame) != 0) {
            this->do_attack();
        }
        return 0;
    }

    case 0x0D:
        break;
    }

    if (this->state == 0x0D) {
        int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x1f9, 600, 0, 0);
        return 3;
    }

    return 0;
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401AD0
int RGE_Action_Attack::work(RGE_Static_Object* param_1, float /*param_2*/, float /*param_3*/, float /*param_4*/) {
    if (param_1 == nullptr) {
        return 0;
    }

    if (param_1 == this->target_obj) {
        if (this->state == 4 || this->state == 6 || this->state == 7) {
            return 1;
        }
    }

    this->indirect_fire_flag = 0;
    this->set_target_obj(param_1);
    this->set_state(4);
    return 1;
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401B30
int RGE_Action_Attack::ready_to_attack(int& rangeStatus) {
    if (this->obj->turn_towards(this->target_obj, this->target_x, this->target_y) == 0) {
        return 0;
    }

    // rangeStatus: 0 = too close (min_range), 1 = in range, 2 = out of range
    if (this->target_obj == nullptr) {
        float dist = this->obj->distance_to_position(this->target_x, this->target_y, this->target_z);
        if (dist < this->min_range) {
            rangeStatus = 0;
            goto too_close;
        }

        RGE_Master_Static_Object* master = (this->obj != nullptr) ? this->obj->master_obj : nullptr;
        float rx = (master != nullptr) ? master->radius_x : 0.0f;
        float ry = (master != nullptr) ? master->radius_y : 0.0f;
        float max_dist = sqrtf(rx * rx + ry * ry) + this->range + 0.3f;
        if (dist <= max_dist) {
            rangeStatus = 1;
            return (this->obj->can_attack() != 0) ? 1 : 0;
        }
        rangeStatus = 2;
    } else {
        RGE_Static_Object* target = this->target_obj;

        if ((target->owner != nullptr) && (target->owner->id > 0) && (target->master_obj != nullptr) &&
            (target->master_obj->object_group != 3) && (target->master_obj->object_group != 0x1b)) {
            int row = (int)target->world_y;
            int col = (int)target->world_x;
            RGE_Visible_Map* visible = (this->obj->owner != nullptr) ? this->obj->owner->visible : nullptr;
            uchar vis = (visible != nullptr) ? visible->get_visible(col, row) : 0;
            if (vis == 0) {
                this->set_state(0x0D);
                return 0;
            }
            if ((vis == 0x80) && (target->master_obj->fog_flag == 0)) {
                this->set_state(0x0D);
                return 0;
            }
        }

        if ((target->world_x == this->target_x) && (target->world_y == this->target_y) && (target->world_z == this->target_z)) {
            goto in_range;
        }

        float dx = target->world_x - this->target_x;
        float dy = target->world_y - this->target_y;
        float dz = target->world_z - this->target_z;
        if (((dx <= 0.5f) && (-0.5f <= dx)) && (dy <= 0.5f) && (-0.5f <= dy) && (dz <= 0.5f) && (-0.5f <= dz)) {
            goto in_range;
        }

        float dist = this->obj->distance_to_object(target);
        if (dist < this->min_range) {
            rangeStatus = 0;
            goto too_close;
        }

        RGE_Master_Static_Object* master = (this->obj != nullptr) ? this->obj->master_obj : nullptr;
        float rx = (master != nullptr) ? master->radius_x : 0.0f;
        float ry = (master != nullptr) ? master->radius_y : 0.0f;
        float max_dist = sqrtf(rx * rx + ry * ry) + this->range + 0.3f;
        if (dist <= max_dist) {
            this->target_x = target->world_x;
            this->target_y = target->world_y;
            this->target_z = target->world_z;
            goto in_range;
        }

        rangeStatus = 2;
    }

    if ((char)this->subActionValue == '\0') {
        int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x1fd, 0, 0, 0);
    }

    if (this->obj->maximumSpeed() == 0.0f) {
        this->set_state(0x0D);
        return 0;
    }

    if ((this->obj->unitAIValue != nullptr) && (this->obj->unitAIValue->currentOrderValue == 0x2d5)) {
        this->set_state(0x0D);
        return 0;
    }

    this->set_state(4);
    return 0;

too_close:
    if ((char)this->subActionValue == '\0') {
        int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x1fe, 0, 0, 0);
    }

    if (this->obj->maximumSpeed() != 0.0f) {
        UnitAIModule* unit_ai = this->obj->unitAIValue;
        if (unit_ai == nullptr) {
            return 0;
        }
        if (unit_ai->currentOrderValue != 0x2d5) {
            return 0;
        }
    }

    this->set_state(0x0D);
    return 0;

in_range:
    rangeStatus = 1;
    return (this->obj->can_attack() != 0) ? 1 : 0;
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401EC0
void RGE_Action_Attack::do_attack() {
    RGE_Combat_Object* combat = (RGE_Combat_Object*)this->obj;
    if (this->target_obj != nullptr) {
        combat->attack(this->target_obj, combat);
        this->need_to_attack = 0;
        return;
    }

    combat->attack(this->target_x, this->target_y, this->target_z, combat);
    this->need_to_attack = 0;
}

// Fully verified. Source of truth: act_atak.cpp.decomp @ 0x00401F00
void RGE_Action_Attack::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    if (this->move_sprite != nullptr) {
        if ((param_2 != nullptr) && (param_3 != nullptr) && (this->move_sprite == param_2->move_sprite)) {
            this->move_sprite = param_3->move_sprite;
        } else {
            RGE_Master_Moving_Object* master = (this->obj != nullptr) ? (RGE_Master_Moving_Object*)this->obj->master_obj : nullptr;
            if ((master != nullptr) && (this->move_sprite == master->move_sprite)) {
                this->move_sprite = param_1->move_sprite;
            }
        }
    }

    if (this->fight_sprite != nullptr) {
        if ((param_2 != nullptr) && (param_3 != nullptr) && (this->fight_sprite == param_2->work_sprite)) {
            this->fight_sprite = param_3->work_sprite;
        } else if ((param_2 != nullptr) && (param_3 != nullptr) && (this->fight_sprite == param_2->work_sprite2)) {
            this->fight_sprite = param_3->work_sprite2;
        } else {
            RGE_Master_Combat_Object* master = (this->obj != nullptr) ? (RGE_Master_Combat_Object*)this->obj->master_obj : nullptr;
            if ((master != nullptr) && (this->fight_sprite == master->fight_sprite)) {
                this->fight_sprite = ((RGE_Master_Combat_Object*)param_1)->fight_sprite;
            }
        }
    }

    if (this->wait_sprite != nullptr) {
        if ((param_2 != nullptr) && (param_3 != nullptr) && (this->wait_sprite == param_2->work_sprite)) {
            this->wait_sprite = param_3->work_sprite;
            return;
        }
        if ((param_2 != nullptr) && (param_3 != nullptr) && (this->wait_sprite == param_2->work_sprite2)) {
            this->wait_sprite = param_3->work_sprite2;
            return;
        }

        RGE_Master_Static_Object* master = (this->obj != nullptr) ? (RGE_Master_Static_Object*)this->obj->master_obj : nullptr;
        if ((master != nullptr) && (this->wait_sprite == master->sprite)) {
            this->wait_sprite = param_1->sprite;
        }
    }
}

