
#include "../include/act_entr.h"
#include "../include/act_list.h"
#include "../include/act_move.h"
#include "../include/act_obj.h"
#include "../include/game_globals.h"
#include "../include/player.h"
#include "../include/task.h"
#include "../include/world.h"

RGE_Action_Enter::RGE_Action_Enter(int infile, RGE_Action_Object* obj_in)
    : RGE_Action(infile, obj_in, 1) {
    this->action_type = RGE_ACTION_TYPE_ENTER;
}

RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in)
    : RGE_Action(obj_in, 1) {
    XYPoint start;
    XYPoint dest;
    XYPoint rVal;
    RGE_Action* action;

    this->action_type = RGE_ACTION_TYPE_ENTER;
    this->task = task_in;
    this->set_target_obj(target_obj_in);
    if (target_obj_in == 0) {
        return;
    }

    this->target_x = target_obj_in->world_x;
    this->target_y = target_obj_in->world_y;
    this->target_z = target_obj_in->world_z;

    if (target_obj_in->actionState() == 2) {
        if (target_obj_in->more_room() == 1) {
            if (this->obj->owner->computerPlayer() == 0) {
                goto line_path;
            }
        }

        if (this->obj->owner->computerPlayer() == 1) {
            goto line_path;
        }
    }

    if (target_obj_in->actionState() == 11) {
        RGE_Action_Object* target_action =
            static_cast<RGE_Action_Object*>(target_obj_in);
        action = target_action->actions->get_action();
        if (action->target2ID == 0) {
            goto line_path;
        }
    }

    if (target_obj_in->actionState() == 11) {
        RGE_Action_Object* target_action =
            static_cast<RGE_Action_Object*>(target_obj_in);
        action = target_action->actions->get_action();
        this->target_x = action->targetX();
        action = target_action->actions->get_action();
        this->target_y = action->targetY();
    }

    return;

line_path:
    dest.x = (int)obj_in->world_x;
    dest.y = (int)obj_in->world_y;
    start.x = (int)target_obj_in->world_x;
    start.y = (int)target_obj_in->world_y;

    if (obj_in->firstTileAlongLine(dest, start, rVal, 2, 2, 1) == 1) {
        this->target_x = (float)rVal.x + 0.5f;
        this->target_y = (float)rVal.y + 0.5f;
        target_obj_in->moveTo((float)rVal.x, (float)rVal.y, target_obj_in->world_z, 0.5f, 1);
    } else {
        this->target_x = target_obj_in->world_x;
        this->target_y = target_obj_in->world_y;
        target_obj_in->moveTo(obj_in->world_x, obj_in->world_y, target_obj_in->world_z, 0.5f, 1);
    }
}

RGE_Action_Enter::~RGE_Action_Enter() {
}

void RGE_Action_Enter::first_in_stack(unsigned char first_time) {
    this->set_state(4);
}

void RGE_Action_Enter::set_state(unsigned char new_state) {
    RGE_Action_Move_To* move_to;

    this->sub_actions->delete_list();
    this->state = new_state;

    switch (new_state) {
    case 4:
        move_to = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->task->work_range,
                                         this->task->move_sprite);
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }

        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;

    case 2:
        this->timer = 1.0f;
        // Fall through to the common wait-state sprite update.
    case 1:
    case 0x0D:
    case 0x0E:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    default:
        return;
    }
}

unsigned char RGE_Action_Enter::update() {
    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        goto target_lost;
    }

    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0) {
        if (this->target_obj->object_state >= RGE_OBJECT_STATE_DYING) {
            goto target_lost;
        }
        if (this->obj->owner->isAlly(this->target_obj->owner->id) == 0) {
            goto target_lost;
        }
    }

    switch (this->state) {
    case 4:
        if (this->target_obj != 0 && !this->target_obj->is_dying()) {
            unsigned char result = this->sub_actions->update();

            switch (result) {
            case RGE_ACTION_UPDATE_REMOVE:
            case RGE_ACTION_UPDATE_COMPLETED:
                if (this->obj->distance_to_object(this->target_obj) - 1.0f > this->task->work_range) {
                    this->set_state(2);
                    return RGE_ACTION_UPDATE_CONTINUE;
                }
                this->obj->enter_obj(this->target_obj);
                goto entered;

            case RGE_ACTION_UPDATE_FAILED:
                this->set_state(2);
                return RGE_ACTION_UPDATE_CONTINUE;

            case RGE_ACTION_UPDATE_TARGET_INVALID:
            case RGE_ACTION_UPDATE_TARGET_LOST:
                break;

            default:
                return RGE_ACTION_UPDATE_CONTINUE;
            }
        }

        this->set_target_obj(0);
        this->set_state(0x0D);
        return RGE_ACTION_UPDATE_CONTINUE;

    case 2:
        this->timer -= this->obj->owner->world->world_time_delta_seconds;
        if (this->timer > 0.0f) {
            return RGE_ACTION_UPDATE_CONTINUE;
        }

        if (this->obj->distance_to_object(this->target_obj) - 1.0f > this->task->work_range) {
            if (this->target_obj->actionState() == 2) {
                XYPoint dest;
                XYPoint start;
                XYPoint rVal;

                dest.x = (int)this->obj->world_x;
                dest.y = (int)this->obj->world_y;
                start.x = (int)this->target_obj->world_x;
                start.y = (int)this->target_obj->world_y;

                if (this->obj->firstTileAlongLine(dest, start, rVal, 2, 2, 1) == 1) {
                    float x = (float)rVal.x + 0.5f;
                    float y = (float)rVal.y + 0.5f;

                    if (this->target_x == x && this->target_y == y) {
                        this->target_x = this->target_obj->world_x;
                        this->target_y = this->target_obj->world_y;
                        this->set_state(4);
                        return RGE_ACTION_UPDATE_CONTINUE;
                    }

                    this->target_x = x;
                    this->target_y = y;
                    this->target_obj->moveTo((float)rVal.x, (float)rVal.y, this->target_obj->world_z, 0.0f, 1);
                } else {
                    this->target_x = this->target_obj->world_x;
                    this->target_y = this->target_obj->world_y;
                    this->target_obj->moveTo(this->obj->world_x, this->obj->world_y, this->target_obj->world_z, 0.5f, 1);
                }
            } else if (this->target_obj->actionState() == 11) {
                RGE_Action_Object* target_action =
                    static_cast<RGE_Action_Object*>(this->target_obj);
                RGE_Action* action = target_action->actions->get_action();
                this->target_x = action->targetX();
                action = target_action->actions->get_action();
                this->target_y = action->targetY();
            }
        } else {
            this->obj->enter_obj(this->target_obj);
            goto entered;
        }

        this->set_state(4);
        return RGE_ACTION_UPDATE_CONTINUE;

    case 1:
        return RGE_ACTION_UPDATE_REMOVE;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_ACTION_FAILED, UNIT_AI_ACTION_ENTER, 0, 0);
        return RGE_ACTION_UPDATE_FAILED;

    default:
        return RGE_ACTION_UPDATE_CONTINUE;
    }

entered:
    if (this->subActionValue == 0) {
        this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_ACTION_COMPLETED, UNIT_AI_ACTION_ENTER, 0, 0);
    }
    this->set_state(1);
    return RGE_ACTION_UPDATE_COMPLETED;

target_lost:
    this->set_state(1);
    this->set_target_obj(0);
    this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_TARGET_INVALID, UNIT_AI_ACTION_ENTER, 0, 0);
    return RGE_ACTION_UPDATE_TARGET_INVALID;
}
