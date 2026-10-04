#include "../include/tact_bld.h"
#include "../include/act_move.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/move_obj.h"
#include "../include/t_c_obj.h"
#include "../include/t_b_obj.h"
#include "../include/basegame.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/sound.h"
#include "../include/task.h"
#include "../include/world.h"

TRIBE_Action_Build::TRIBE_Action_Build(int infile, RGE_Action_Object* obj_in)
    : RGE_Action(infile, obj_in, 1) {
    this->action_type = TRIBE_ACTION_TYPE_BUILD;
}

TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in)
    : RGE_Action(obj_in, 1) {
    this->action_type = TRIBE_ACTION_TYPE_BUILD;
    this->task = task_in;

    if (!target_obj_in || obj_in->owner->id == target_obj_in->owner->id) {
        this->set_target_obj(target_obj_in);
        this->target_x = target_obj_in->world_x;
        this->target_y = target_obj_in->world_y;
        this->target_z = target_obj_in->world_z;
    }
}

TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z)
    : RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_BUILD;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}

void TRIBE_Action_Build::first_in_stack(unsigned char first_time) {
    if (first_time != 0) {
        if (this->target_obj != 0) {
            this->set_state(4);
            return;
        }
        this->set_state(3);
        return;
    }
    this->set_state(3);
}

void TRIBE_Action_Build::set_state(unsigned char new_state) {
    RGE_Action_Move_To* move_to;

    this->sub_actions->delete_list();
    this->state = new_state;

    switch (new_state) {
    case 3:
        if (this->obj->owner->computerPlayer() == 1) {
            this->obj->notify((int)this->obj->id, (int)this->obj->id, (int)UNIT_AI_NOTIFY_ACTION_COMPLETED, (long)UNIT_AI_ACTION_BUILD, 0L, 0L);
            this->set_state(1);
        } else {
            this->obj->notify((int)this->obj->id, (int)this->obj->id, (int)UNIT_AI_NOTIFY_REQUEST_TASK, (long)UNIT_AI_ACTION_BUILD, 0L, 0L);
        }
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 2:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 0x0B:
        move_to = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f,
                                         this->task->move_sprite);
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }
        move_to->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;

    case 4:
        if (this->target_obj != 0) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }
        move_to = new RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range, this->task->move_sprite);
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;

    case 6:
        this->obj->new_sprite(this->task->move_sprite);
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
            return;
        }
        return;

    case 1:
    case 0x0D:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    default:
        return;
    }
}

unsigned char TRIBE_Action_Build::update() {
    float work;

    if (this->targetID != -1) {
        if (this->obj->owner->world->object(this->targetID) == 0) {
            this->set_target_obj(0);
            if (this->state != 2) {
                this->set_state(3);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
        }
    }

    if (this->target2ID != -1) {
        if (this->obj->owner->world->object(this->target2ID) == 0) {
            this->set_target_obj2(0);
        }
    }

    if (this->target_obj != 0 && this->target_obj->object_state != RGE_OBJECT_STATE_UNBUILT && this->timer == 0.0f) {
        if (this->target_obj->hp < (float)(int)this->target_obj->master_obj->hp) {
            this->obj->removeAllFromPathingGroup();
            this->obj->owner->processAIOrder(this->obj->owner->id, this->obj->id, UNIT_AI_ORDER_REPAIR, this->target_obj->id,
                                             this->target_obj->owner->id, this->target_obj->world_x, this->target_obj->world_y,
                                             this->target_obj->world_z, 1.0f, 1, 0, 100);
            return RGE_ACTION_UPDATE_CONTINUE;
        }

        this->set_target_obj(0);
        if (this->state != 2) {
            this->set_state(3);
            return RGE_ACTION_UPDATE_CONTINUE;
        }
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
            goto state3_common;
        case RGE_ACTION_UPDATE_TARGET_INVALID:
            goto reset_common;
        }
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case RGE_ACTION_UPDATE_TARGET_INVALID:
        case RGE_ACTION_UPDATE_TARGET_LOST:
            goto reset_common;
        case RGE_ACTION_UPDATE_FAILED:
            goto state3_common;
        case RGE_ACTION_UPDATE_REMOVE:
        case RGE_ACTION_UPDATE_COMPLETED:
            this->set_state(6);
            return RGE_ACTION_UPDATE_CONTINUE;
        }
        break;

    case 6:
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            this->set_state(7);
            return RGE_ACTION_UPDATE_CONTINUE;
        }
        break;

    case 7:
        if (this->timer < 0.0 && this->target_obj != 0 && this->target_obj->attribute_amount_held > 0.0f) {
            this->obj->removeAllFromPathingGroup();
            this->obj->setWaitingToMove(1);
            this->obj->do_command(this->target_obj, this->target_obj->world_x, this->target_obj->world_y, 0);
            return RGE_ACTION_UPDATE_CONTINUE;
        }

        if (rge_base_game->quick_build != 0) {
            work = 1000.0f;
        } else {
            work = this->task->work_val1 *
                ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate *
                this->obj->owner->world->world_time_delta_seconds;
        }

        if (this->target_obj == 0 || ((TRIBE_Building_Object*)this->target_obj)->build(work) != 0) {
            //! @bug The farm completion branch arms timer = -1 instead of finishing the build.
            //! The next update then forces the builder to work the farm before any deposit.
            //! If the carry is not food, the gather start discards it with no owner credit.
            if (this->target_obj != 0 && this->target_obj->master_obj->id == 0x32) {
                this->timer = -1.0f;
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            goto state3_common;
        }
        break;

    case 1:
        return RGE_ACTION_UPDATE_REMOVE;

    case 0x0D:
        this->obj->notify((int)this->obj->id, (int)this->obj->id, (int)UNIT_AI_NOTIFY_ACTION_FAILED, (long)UNIT_AI_ACTION_BUILD, 0L, 0L);
        this->set_state(2);
        return RGE_ACTION_UPDATE_FAILED;
    }

return_zero:
    return RGE_ACTION_UPDATE_CONTINUE;

state3_common:
    this->set_state(3);
    goto return_zero;

reset_common:
    this->set_target_obj(0);
    this->set_state(0x0B);
    goto return_zero;
}

int TRIBE_Action_Build::stop() {
    this->set_state(2);
    return 1;
}

int TRIBE_Action_Build::move_to(RGE_Static_Object* obj_in, float x, float y, float z) {
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0x0B);
    return 1;
}

int TRIBE_Action_Build::work(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (obj_in != 0) {
        RGE_Player* target_owner = obj_in->owner;
        if (target_owner == obj_in->owner && target_owner->id == this->obj->owner->id) {
            if (obj_in == this->target_obj) {
                unsigned char action = this->state;
                if (action == 4 || action == 6) {
                    return 1;
                }
            }
            this->set_target_obj(obj_in);
            this->set_state(4);
            return 1;
        }
    }

    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(11);
    return 1;
}
