
#include "../include/tact_hea.h"
#include "../include/game_globals.h"

// The owner header stays small. These canonical class surfaces belong to this
// translation unit because the bodies dereference their members and call them.
#include "../include/act_move.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/move_obj.h"
#include "../include/t_c_obj.h"
#include "../include/t_b_obj.h"
#include "../include/task.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/sound.h"

TRIBE_Action_Heal::TRIBE_Action_Heal(int infile, RGE_Action_Object* obj_in) : RGE_Action(infile, obj_in, 1) {
    this->action_type = TRIBE_ACTION_TYPE_HEAL;
}

//     RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)
TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in) :
    RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_HEAL;
    set_target_obj(target_obj_in);
    target_x = target_obj_in->world_x;
    target_y = target_obj_in->world_y;
    target_z = target_obj_in->world_z;
}

//     RGE_Action_Object*, RGE_Task*, float, float, float)
TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z) :
    RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_HEAL;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}

void TRIBE_Action_Heal::first_in_stack(unsigned char first_time) {
    if (this->target_obj != 0) {
        short kind = this->target_obj->master_obj->object_group;
        if (kind == OBJECT_GROUP_FISHING_BOAT || kind == OBJECT_GROUP_TRADE_BOAT || kind == OBJECT_GROUP_TRANSPORT_BOAT
            || kind == OBJECT_GROUP_WAR_BOAT) {
            return;
        }
        this->set_state(4);
        return;
    }
    this->set_state(3);
}

void TRIBE_Action_Heal::set_state(unsigned char new_state) {
    this->sub_actions->delete_list();
    this->state = new_state;

    switch (new_state) {
        case 3:
            this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_REQUEST_TASK, UNIT_AI_ACTION_HEAL, 0, 0);
            this->obj->new_sprite(this->obj->master_obj->sprite);
            return;

        case 2:
            this->obj->new_sprite(this->obj->master_obj->sprite);
            return;

        case 11: {
            RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
                this->obj, this->target_x, this->target_y, this->target_z, 0.0f, this->task->move_sprite
            );
            if (move_to == 0) {
                this->set_state(0x0D);
                return;
            }
            move_to->setSubAction(1);
            this->sub_actions->add_action(move_to);
            return;
        }

        case 4: {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            RGE_Action_Move_To* move_to =
                new RGE_Action_Move_To(this->obj, this->target_obj, 0.4f, this->task->move_sprite);
            if (move_to == 0) {
                this->set_state(0x0D);
                return;
            }
            this->sub_actions->add_action(move_to);
            move_to->setSubAction(1);
            return;
        }

        case 6:
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            this->obj->new_sprite(this->task->move_sprite);
            return;

        case 7:
            this->obj->new_sprite(this->task->work_sprite);
            if (this->task->work_sound != 0)
                this->task->work_sound->play(1);
            return;

        default:
            return;
    }
}

unsigned char TRIBE_Action_Heal::update() {
    float work;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        this->set_state(3);
        return RGE_ACTION_UPDATE_CONTINUE;
    }

    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state != RGE_OBJECT_STATE_ACTIVE) {
        this->set_target_obj(0);
        this->set_state(3);
        return RGE_ACTION_UPDATE_CONTINUE;
    }

    if (this->target_obj != 0 && this->obj->owner->isAlly(this->target_obj->owner->id) == 0) {
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_TARGET_INVALID, UNIT_AI_ACTION_HEAL, 0, 0);
        return RGE_ACTION_UPDATE_TARGET_INVALID;
    }

    switch (this->state) {
        case 0x0B:
            switch (this->sub_actions->update()) {
                case RGE_ACTION_UPDATE_REMOVE:
                case RGE_ACTION_UPDATE_COMPLETED:
                case RGE_ACTION_UPDATE_TARGET_LOST:
                    this->set_state(3);
                    return RGE_ACTION_UPDATE_CONTINUE;
                case RGE_ACTION_UPDATE_FAILED:
                    this->set_state(0x0D);
                    return RGE_ACTION_UPDATE_CONTINUE;
                case RGE_ACTION_UPDATE_TARGET_INVALID:
                    this->set_target_obj(0);
                    this->set_state(0x0B);
                    return RGE_ACTION_UPDATE_CONTINUE;
            }
            break;

        case 4:
            switch (this->sub_actions->update()) {
                case RGE_ACTION_UPDATE_TARGET_INVALID:
                case RGE_ACTION_UPDATE_TARGET_LOST:
                    this->set_target_obj(0);
                    this->set_state(0x0B);
                    return RGE_ACTION_UPDATE_CONTINUE;
                case RGE_ACTION_UPDATE_FAILED:
                    this->set_state(0x0D);
                    return RGE_ACTION_UPDATE_CONTINUE;
                case RGE_ACTION_UPDATE_REMOVE:
                case RGE_ACTION_UPDATE_COMPLETED:
                    this->set_state(6);
                    return RGE_ACTION_UPDATE_CONTINUE;
            }
            break;

        case 6:
            if (this->target_obj == 0) {
                this->set_state(3);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            if (this->obj->turn_towards(this->target_obj, 0.0f, 0.0f) != 0) {
                this->set_state(7);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            break;

        case 7: {
            if (this->target_obj == 0) {
                this->set_state(3);
                return RGE_ACTION_UPDATE_CONTINUE;
            }

            if (this->target_obj->world_x != this->target_x || this->target_y != this->target_obj->world_y) {
                float distance = this->obj->distance_to_object(this->target_obj);
                if (this->task->work_range < distance && g_heal_distance_threshold < distance) {
                    this->set_state(3);
                    return RGE_ACTION_UPDATE_CONTINUE;
                }
                this->target_x = this->target_obj->world_x;
                this->target_y = this->target_obj->world_y;
                this->target_z = this->target_obj->world_z;
                return RGE_ACTION_UPDATE_CONTINUE;
            }

            work = this->task->work_val1 * ((RGE_Master_Action_Object*) this->obj->master_obj)->work_rate;
            work *= this->obj->owner->world->world_time_delta_seconds;
            if (this->obj->owner->attributes[PLAYER_ATTRIBUTE_HEAL_RATE] > g_heal_attribute_threshold) {
                work *= this->obj->owner->attributes[PLAYER_ATTRIBUTE_HEAL_RATE];
            }

            unsigned char result = this->target_obj->heal(work);
            if (result == 1) {
                this->set_state(3);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            if (result == 2) {
                this->obj->notify(
                    this->obj->id, this->obj->id, UNIT_AI_NOTIFY_TARGET_INVALID, UNIT_AI_ACTION_HEAL, 0, 0
                );
                this->set_state(2);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            break;
        }

        case 1:
            return RGE_ACTION_UPDATE_REMOVE;

        case 0x0D:
            this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_ACTION_FAILED, UNIT_AI_ACTION_HEAL, 0, 0);
            this->set_state(2);
            return RGE_ACTION_UPDATE_FAILED;
    }

    return RGE_ACTION_UPDATE_CONTINUE;
}

//     RGE_Static_Object*, float, float, float)
int TRIBE_Action_Heal::work(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (obj_in != 0) {
        if (obj_in == this->target_obj) {
            unsigned char state = this->state;
            if (state == 4 || state == 6 || state == 7)
                return 1;
        }
        this->set_target_obj(obj_in);
        this->target_x = obj_in->world_x;
        this->target_y = obj_in->world_y;
        this->target_z = obj_in->world_z;
        this->first_in_stack(1);
        return 1;
    }
    return 0;
}
