#include "../include/RGE_Action_Gather.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Sound.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include <new>

RGE_Action_Gather::~RGE_Action_Gather() = default;

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00402EA0
RGE_Action_Gather::RGE_Action_Gather(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 5;
    rge_read(param_1, &this->targetType, 4);
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00402F40
RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->action_type = 5;

    this->set_target_obj(param_3);
    if (param_3 != nullptr) {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        this->target_z = param_3->world_z;
        this->targetType = (param_3->master_obj != nullptr) ? (int)param_3->master_obj->id : -1;
    }
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00402FD0
RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    RGE_Action::setup(param_1);
    this->task = param_2;
    this->action_type = 5;

    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
    this->targetType = -1;
}

int RGE_Action_Gather::setup(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 5;
    this->targetType = -1;
    return 1;
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00402EA0
int RGE_Action_Gather::setup(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 5;
    rge_read(param_1, &this->targetType, 4);
    return 1;
}

RGE_Action_List* RGE_Action_Gather::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Gather::rehook() { RGE_Action::rehook(); }
short RGE_Action_Gather::type() { return RGE_Action::type(); }
uchar RGE_Action_Gather::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Gather::idle_update() { return RGE_Action::idle_update(); }
uchar RGE_Action_Gather::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Gather::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Gather::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Gather::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Gather::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Gather::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Gather::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Gather::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Gather::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403020
void RGE_Action_Gather::save(int param_1) {
    RGE_Action::save(param_1);
    rge_write(param_1, &this->targetType, 4);
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403C60
RGE_Sprite* RGE_Action_Gather::get_move_sprite() {
    RGE_Task* cur_task = this->task;
    if (cur_task == nullptr) {
        return nullptr;
    }

    if ((cur_task->attribute_type != -1) && (this->obj != nullptr) &&
        (this->obj->attribute_type_held == cur_task->attribute_type) &&
        ((int)this->obj->attribute_amount_held > 0) && (cur_task->carry_sprite != nullptr)) {
        return cur_task->carry_sprite;
    }

    return cur_task->move_sprite;
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403C90
RGE_Sprite* RGE_Action_Gather::get_wait_sprite() {
    RGE_Task* cur_task = this->task;
    if (cur_task != nullptr && (cur_task->attribute_type != -1) && (this->obj != nullptr) &&
        (this->obj->attribute_type_held == cur_task->attribute_type) &&
        ((int)this->obj->attribute_amount_held > 0) && (cur_task->carry_sprite != nullptr)) {
        return cur_task->carry_sprite;
    }

    RGE_Master_Static_Object* master = (this->obj != nullptr) ? this->obj->master_obj : nullptr;
    return (master != nullptr) ? master->sprite : nullptr;
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403050
void RGE_Action_Gather::first_in_stack(uchar param_1) {
    if ((this->task != nullptr) && (this->obj != nullptr) && (this->obj->attribute_type_held != this->task->attribute_type)) {
        this->obj->set_attribute(this->task->attribute_type, 0.0f);
    }

    if (param_1 != 0) {
        if (this->target_obj == nullptr) {
            this->set_state(3);
            return;
        }

        if ((this->obj != nullptr) && (this->target_obj->owner == this->obj->owner)) {
            RGE_Master_Action_Object* master = (this->obj->master_obj != nullptr) ? (RGE_Master_Action_Object*)this->obj->master_obj : nullptr;
            short target_id = (this->target_obj->master_obj != nullptr) ? this->target_obj->master_obj->id : (short)-1;
            if (master != nullptr &&
                ((target_id == master->drop_site) || (target_id == master->backup_drop_site)) &&
                (0.0f < this->obj->attribute_amount_held)) {
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

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403110
void RGE_Action_Gather::set_state(uchar param_1) {
    if (this->sub_actions != nullptr) {
        this->sub_actions->delete_list();
    }
    this->state = param_1;

    switch (param_1) {
    case 1:
    case 0x0D:
    case 0x0E:
        this->timer = 0.0f;
        break;

    case 2: {
        this->timer = 0.0f;
        if (this->obj != nullptr) {
            this->obj->new_sprite(this->get_wait_sprite());
        }
        this->set_target_obj(nullptr);
        this->set_target_obj2(nullptr);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;
    }

    case 3: {
        if (this->obj != nullptr) {
            int id = (int)this->obj->id;
            this->obj->notify(id, id, 0x202, 0x261, this->targetType, 0);
        }
        this->timer = -10.0f;
        break;
    }

    case 4: {
        this->timer = 0.0f;
        if (this->target_obj == nullptr) {
            this->set_state(0x0D);
            return;
        }

        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;

        float range = (this->task != nullptr) ? this->task->work_range : 0.0f;
        RGE_Action_Move_To* move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj, range, this->get_move_sprite());
        if (move_to == nullptr) {
            this->set_state(0x0D);
            return;
        }

        move_to->subActionValue = 1;
        if (this->sub_actions != nullptr) {
            this->sub_actions->add_action(move_to);
        }
        return;
    }

    case 6:
        this->timer = 0.0f;
        if (this->obj != nullptr) {
            this->obj->new_sprite(this->get_move_sprite());
        }
        return;

    case 7:
        this->timer = 0.0f;
        if (this->task != nullptr && this->obj != nullptr) {
            if (this->obj->attribute_type_held != this->task->attribute_type) {
                this->obj->set_attribute(this->task->attribute_type, 0.0f);
            }
            this->obj->new_sprite(this->task->work_sprite);
            if (this->task->work_sound != nullptr) {
                this->task->work_sound->play(1);
                return;
            }
        }
        return;

    case 8: {
        if (this->obj == nullptr) {
            this->set_state(0x0D);
            return;
        }

        if (0.0f < this->obj->attribute_amount_held) {
            if (this->target_obj2 == nullptr) {
                RGE_Master_Action_Object* master = (this->obj->master_obj != nullptr) ? (RGE_Master_Action_Object*)this->obj->master_obj : nullptr;
                if (master != nullptr && master->drop_site != -1) {
                    RGE_Static_Object* zone_obj = (this->obj->useSameZoneDropsite() == 1) ? (RGE_Static_Object*)this->obj : nullptr;
                    if (this->obj->owner != nullptr && this->obj->owner->objects != nullptr) {
                        this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                            (long)master->drop_site,
                            (long)master->backup_drop_site,
                            this->obj->world_x,
                            this->obj->world_y,
                            1,
                            2,
                            zone_obj));
                    }
                } else {
                    this->set_target_obj2(nullptr);
                }

                if (this->target_obj2 == nullptr) {
                    int id = (int)this->obj->id;
                    this->obj->notify(id, id, 0x203, 0x261, 0, 0);
                    this->set_state(0x0D);
                    return;
                }
            }

            float range = (this->task != nullptr) ? this->task->work_range : 0.0f;
            RGE_Action_Move_To* move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_obj2, range, this->get_move_sprite());
            if (move_to == nullptr) {
                this->set_state(0x0D);
                return;
            }

            move_to->subActionValue = 1;
            if (this->sub_actions != nullptr) {
                this->sub_actions->add_action(move_to);
            }
            return;
        }

        int target_master_id = (this->target_obj != nullptr && this->target_obj->master_obj != nullptr) ? (int)this->target_obj->master_obj->id : -1;
        if (this->target_obj != nullptr && this->target_obj->attribute_amount_held <= 0.0f &&
            this->obj->keepGatheringWhenObjectIsOut(target_master_id) == 0) {
            this->set_target_obj(nullptr);
        }
        this->set_state(3);
        return;
    }

    case 0x0B:
    case 0x0F: {
        this->timer = 0.0f;
        float range = (this->task != nullptr) ? this->task->work_range : 0.0f;
        RGE_Action_Move_To* move_to = new (std::nothrow) RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, range, this->get_move_sprite());
        if (move_to == nullptr) {
            this->set_state(0x0D);
            return;
        }

        move_to->subActionValue = 1;
        if (this->sub_actions != nullptr) {
            this->sub_actions->add_action(move_to);
        }
        return;
    }

    default:
        return;
    }

    if (this->obj != nullptr) {
        this->obj->new_sprite(this->get_wait_sprite());
    }
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403590
uchar RGE_Action_Gather::update() {
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

    if ((this->target_obj != nullptr) && (this->target_obj->master_obj != nullptr) && (this->obj != nullptr) && (this->obj->master_obj != nullptr) &&
        (this->target_obj->master_obj->terrain != 0) && (this->target_obj->master_obj->terrain != this->obj->master_obj->terrain)) {
        this->set_state(1);
        int id = (int)this->obj->id;
        this->obj->notify(id, id, 0x1FB, 0x261, 0, 0);
        return 4;
    }

    switch ((char)this->state) {
    case 1:
        return 1;

    case 3:
        if (this->timer < 0.0f && this->obj != nullptr && this->obj->owner != nullptr && this->obj->owner->world != nullptr) {
            this->timer = this->obj->owner->world->world_time_delta_seconds + this->timer;
            if (0.0f < this->timer) {
                this->timer = -10.0f;
                int id = (int)this->obj->id;
                this->obj->notify(id, id, 0x202, 0x261, this->targetType, 0);
                return 0;
            }
        }
        break;

    case 4: {
        uchar result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (result) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3: {
            RGE_Player* owner = (this->obj != nullptr) ? this->obj->owner : nullptr;
            if (owner != nullptr && owner->computerPlayer() == 1) {
                this->set_state(0x0D);
                return 0;
            }
            this->set_state(3);
            return 0;
        }
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
        if (this->obj != nullptr) {
            uchar turned = this->obj->turn_towards(this->target_obj, 0.0f, 0.0f);
            if (turned != 0) {
                int target_master_id = (this->target_obj->master_obj != nullptr) ? (int)this->target_obj->master_obj->id : -1;
                if ((this->target_obj->attribute_amount_held <= 0.0f) &&
                    (this->obj->keepGatheringWhenObjectIsOut(target_master_id) == 0)) {
                    this->set_target_obj(nullptr);
                    this->set_state(3);
                    return 0;
                }
                this->set_state(7);
                return 0;
            }
        }
        break;

    case 7: {
        if (this->target_obj != nullptr) {
            float give_amount = 0.0f;
            if (rge_base_game != nullptr && rge_base_game->quick_build != 0) {
                give_amount = this->target_obj->attribute_amount_held;
            } else if (this->obj != nullptr && this->obj->owner != nullptr && this->obj->owner->world != nullptr) {
                float dt = this->obj->owner->world->world_time_delta_seconds;
                float work_val1 = (this->task != nullptr) ? this->task->work_val1 : 0.0f;
                float work_rate = 0.0f;
                if (this->obj->master_obj != nullptr) {
                    work_rate = ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate;
                }
                give_amount = work_val1 * work_rate * dt;
            }

            if (this->target_obj->attribute_amount_held < give_amount) {
                give_amount = this->target_obj->attribute_amount_held;
            }

            float modifier = 1.0f;
            short attr_mod = (this->task != nullptr) ? this->task->attribute_type2 : (short)-1;
            if ((attr_mod != -1) && (this->obj != nullptr) && (this->obj->owner != nullptr) && (this->obj->owner->attributes != nullptr)) {
                modifier = this->obj->owner->attributes[attr_mod];
            }

            float max_hold = 0.0f;
            if (this->obj != nullptr && this->obj->master_obj != nullptr) {
                max_hold = (float)(int)this->obj->master_obj->attribute_max_amount * modifier;
            }

            float available = max_hold - ((this->obj != nullptr) ? this->obj->attribute_amount_held : 0.0f);
            if (available < modifier * give_amount) {
                give_amount = give_amount - (modifier * give_amount - available) / modifier;
            }

            this->target_obj->set_attribute_amount(-give_amount, 1, 1);
            if (this->obj != nullptr) {
                this->obj->set_attribute_amount(give_amount, 1, 0);
            }

            if ((this->obj != nullptr) && (this->obj->attribute_amount_held < max_hold)) {
                if (0.0f < this->target_obj->attribute_amount_held) {
                    return 0;
                }
                int target_master_id = (this->target_obj->master_obj != nullptr) ? (int)this->target_obj->master_obj->id : -1;
                if (this->obj->keepGatheringWhenObjectIsOut(target_master_id) != 0) {
                    return 0;
                }
            }

            this->set_state(8);
            return 0;
        }

        if (this->obj != nullptr && 0.0f < this->obj->attribute_amount_held) {
            this->set_state(8);
            return 0;
        }

        this->set_state(3);
        return 0;
    }

    case 8: {
        if (this->timer < 0.0f && this->obj != nullptr && this->obj->owner != nullptr && this->obj->owner->world != nullptr) {
            this->timer = this->obj->owner->world->world_time_delta_seconds + this->timer;
            if (0.0f < this->timer) {
                this->timer = 0.0f;
                this->set_state(8);
                return 0;
            }
            break;
        }

        uchar result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        if (result == 3 || result == 4 || result == 5) {
            this->timer = -3.0f;
            if (this->obj != nullptr) {
                this->obj->stop_moving();
            }
            return 0;
        }

        if (result == 1 || result == 2) {
            if (this->target_obj2 == nullptr) {
                this->set_state(8);
                return 0;
            }

            float dist = (this->obj != nullptr) ? this->obj->distance_to_object(this->target_obj2) : 0.0f;
            if (1.0f < dist) {
                this->timer = -3.0f;
                if (this->obj != nullptr) {
                    this->obj->stop_moving();
                }
                return 0;
            }

            if (this->task != nullptr && this->task->work_sound2 != nullptr) {
                this->task->work_sound2->play(1);
            }

            short attr = (this->task != nullptr) ? this->task->attribute_type3 : (short)-1;
            if (attr == -1 && this->obj != nullptr) {
                attr = this->obj->attribute_type_held;
            }

            if (this->obj != nullptr && this->obj->owner != nullptr) {
                this->obj->owner->add_attribute_num(attr, this->obj->attribute_amount_held, 1);
                this->obj->owner->trackUnitGather((int)this->obj->id, (int)attr, (int)this->obj->attribute_amount_held);
            }

            if (this->obj != nullptr) {
                this->obj->set_attribute(-1, 0.0f);
            }

            if (this->target_obj != nullptr) {
                this->set_target_obj2(nullptr);
                this->set_state(4);
                return 0;
            }

            if (this->target_x != -1.0f && this->target_y != -1.0f) {
                this->set_state(0x0B);
                return 0;
            }

            int is_computer = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->computerPlayer() : 0;
            this->set_state((is_computer == 1) ? (uchar)1 : (uchar)2);
            return 0;
        }

        break;
    }

    case 0x0B:
    case 0x0F: {
        uchar result = (this->sub_actions != nullptr) ? this->sub_actions->update() : 0;
        switch (result) {
        case 1:
        case 2:
        case 5:
            if (this->state == 0x0B) {
                this->set_state(3);
                return 0;
            } else {
                int is_computer = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->computerPlayer() : 0;
                this->set_state((is_computer == 1) ? (uchar)1 : (uchar)2);
                return 0;
            }
        case 3: {
            RGE_Player* owner = (this->obj != nullptr) ? this->obj->owner : nullptr;
            if (owner != nullptr && owner->computerPlayer() == 1) {
                this->set_state(0x0D);
                return 0;
            }
            this->set_state(3);
            return 0;
        }
        case 4:
            this->set_target_obj(nullptr);
            this->set_state((this->state == 0x0B) ? (uchar)0x0B : (uchar)0x0F);
            return 0;
        default:
            break;
        }
        break;
    }

    case 0x0D: {
        if (this->obj != nullptr) {
            int id = (int)this->obj->id;
            this->obj->notify(id, id, 0x1F9, 0x261, 0, 0);
        }

        int is_computer = (this->obj != nullptr && this->obj->owner != nullptr) ? this->obj->owner->computerPlayer() : 0;
        this->set_state((is_computer == 1) ? (uchar)1 : (uchar)2);
        return 3;
    }

    default:
        break;
    }

    return 0;
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403CD0
int RGE_Action_Gather::stop() {
    this->set_state(2);
    return 1;
}

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403CE0
int RGE_Action_Gather::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if ((param_1 != nullptr) && (this->obj != nullptr) && (param_1->owner == this->obj->owner)) {
        RGE_Master_Action_Object* master = (this->obj->master_obj != nullptr) ? (RGE_Master_Action_Object*)this->obj->master_obj : nullptr;
        short id = (param_1->master_obj != nullptr) ? param_1->master_obj->id : (short)-1;
        if (master != nullptr &&
            ((id == master->drop_site) || (id == master->backup_drop_site)) &&
            (0.0f < this->obj->attribute_amount_held)) {
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

// Fully verified. Source of truth: act_gath.cpp.decomp @ 0x00403D90
int RGE_Action_Gather::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 == nullptr) {
        this->target_z = param_4;
        this->target_x = param_2;
        this->target_y = param_3;
        this->set_target_obj(nullptr);
        this->set_state(0x0F);
        return 1;
    }

    if ((param_1 != this->target_obj) || (((char)this->state != '\x04') && ((char)this->state != '\x06') && ((char)this->state != '\a'))) {
        if ((this->obj != nullptr) && (param_1->owner == this->obj->owner)) {
            RGE_Master_Action_Object* master = (this->obj->master_obj != nullptr) ? (RGE_Master_Action_Object*)this->obj->master_obj : nullptr;
            short id = (param_1->master_obj != nullptr) ? param_1->master_obj->id : (short)-1;
            if (master != nullptr &&
                ((id == master->drop_site) || (id == master->backup_drop_site)) &&
                (0.0f < this->obj->attribute_amount_held)) {
                this->timer = 0.0f;
                this->set_target_obj(nullptr);
                this->target_x = -1.0f;
                this->target_y = -1.0f;
                this->target_z = -1.0f;
                this->set_target_obj2(param_1);
                this->set_state(8);
                return 1;
            }
        }

        this->set_target_obj(param_1);
        this->target_x = param_1->world_x;
        this->target_y = param_1->world_y;
        this->target_z = param_1->world_z;
        this->set_target_obj2(nullptr);
        this->set_state(4);
        return 1;
    }

    return 1;
}

