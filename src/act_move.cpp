//
// The scalar deleting destructor at 00405580 is compiler generated. It has no
// standalone source owner. The non-deleting destructor at 004056E0 is the
// handwritten virtual destructor.

#include "../include/act_move.h"
#include "../include/action.h"
#include "../include/act_obj.h"
#include "../include/move_obj.h"
#include "../include/ani_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/rge_fio.h"
#include "../include/command_waypoint.h"

RGE_Action_Move_To::RGE_Action_Move_To(int handle, RGE_Action_Object* object)
    : RGE_Action(handle, object, 1) {
    action_type = 1;
    rge_read(handle, &range, 4);
}

//     RGE_Action_Object*, float, float, float, float, RGE_Sprite*)
RGE_Action_Move_To::RGE_Action_Move_To(
    RGE_Action_Object* object, float x, float y, float z, float range_value,
    RGE_Sprite* sprite_value)
    : RGE_Action(object, 1) {
    action_type = 1;
    target_x = x;
    target_y = y;
    target_z = z;
    range = range_value;
    sprite = sprite_value;

    if (range_value <= 0.0f) {
        range = 0.4f;
    }

    if (sprite_value == 0) {
        RGE_Master_Action_Object* master =
            static_cast<RGE_Master_Action_Object*>(this->obj->master_obj);
        if (master->move_sprite == 0) {
            sprite = master->sprite;
        } else {
            sprite = master->move_sprite;
        }
    }
}

//     RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*)
RGE_Action_Move_To::RGE_Action_Move_To(
    RGE_Action_Object* object, RGE_Static_Object* target,
    float range_value, RGE_Sprite* sprite_value)
    : RGE_Action(object, 1) {
    action_type = 1;
    set_target_obj(target);

    if (target != 0) {
        target_x = target->world_x;
        target_y = target->world_y;
        target_z = target->world_z;
    }

    range = range_value;
    sprite = sprite_value;

    if (range_value <= 0.0f) {
        range = 0.4f;
    }

    if (sprite_value == 0) {
        RGE_Master_Action_Object* master =
            static_cast<RGE_Master_Action_Object*>(this->obj->master_obj);
        if (master->move_sprite == 0) {
            sprite = master->sprite;
        } else {
            sprite = master->move_sprite;
        }
    }
}

RGE_Action_Move_To::~RGE_Action_Move_To() {
    this->obj->removeAllUserDefinedWaypoints(0);
    this->obj->stop_moving();
}

void RGE_Action_Move_To::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->range, 4);
}

void RGE_Action_Move_To::first_in_stack(unsigned char param_1) {
    if (this->target_obj != 0) {
        if (this->obj->inRange(this->target_obj, this->range) != 0) {
            this->set_state(1);
            return;
        }
    }

    if (this->obj->maximumSpeed() == 0.0) {
        this->set_state(0x0D);
        return;
    }

    this->set_state(3);
}

void RGE_Action_Move_To::set_state(unsigned char param_1) {
    this->state = param_1;

    switch (param_1) {
    case 4:
        this->obj->new_sprite(this->sprite);
        return;
    case 1:
    case 13:
    case 14:
        if (this->subActionValue == 0) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        return;
    default:
        return;
    }
}

// state transitions, and return values. Its current result has a broad CFG
// difference with one missing cold block.
unsigned char RGE_Action_Move_To::update() {
    XYZBYTEPoint waypoint;
    int move_result;

    if (this->targetID != -1 &&
        this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        goto target_lost;
    }

    if (this->target2ID != -1 &&
        this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj(0);
        goto target_lost;
    }

    switch (this->state) {
    case 3:
        if (this->target_obj != 0 &&
            this->obj->inRange(this->target_obj, this->range) != 0) {
            this->set_state(1);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x262,
                                  0, 0);
            }
            this->obj->setWaitingToMove(0);
            this->obj->pathingGroupMembers.zeroNumber();
            return 2;
        }

        if (this->target_obj != 0) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }

        this->obj->setGoal(this->target_x, this->target_y, 1.0f);
        waypoint.x = (unsigned char)this->target_x;
        waypoint.y = (unsigned char)this->target_y;
        waypoint.z = (unsigned char)this->target_z;
        if (this->obj->finalUserDefinedWaypoint == 0) {
            this->obj->addUserDefinedWaypoint(&waypoint, 0);
            this->obj->setFinalUserDefinedWaypoint();
        }
        this->obj->setActionRange(this->range);

        if (this->target_obj != 0) {
            this->obj->setTargetID(this->target_obj->id);
            this->obj->setTargetRadius(this->target_obj->master_obj->radius_x,
                                       this->target_obj->master_obj->radius_y);
        } else {
            this->obj->setTargetID(-1);
            this->obj->setTargetRadius(0.0f, 0.0f);
        }

        if (this->obj->findPath() == 0) {
            this->set_state(4);
            return 0;
        }
        break;

    case 4:
        if (this->target_obj != 0) {
            float x_diff = this->target_x - this->target_obj->world_x;
            float y_diff = this->target_y - this->target_obj->world_y;
            if (x_diff < -1.0 || x_diff > 1.0 || y_diff < -1.0 ||
                y_diff > 1.0) {
                goto reached_target;
            }
        }

        move_result = this->obj->doMove();
        if (move_result == 0) {
            this->set_state(1);
            goto state_done;
        }
        if (move_result == 2) {
            if (this->target_obj != 0) {
                float x_diff = this->target_x - this->target_obj->world_x;
                float y_diff = this->target_y - this->target_obj->world_y;
                if (x_diff < -1.0 || x_diff > 1.0 || y_diff < -1.0 ||
                    y_diff > 1.0) {
                    goto reached_target;
                }
            }
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x262,
                                  0, 0);
            }
            this->set_state(1);
            return 2;
        }
        break;

    case 13:
        goto state_done;

    default:
        return 0;

    reached_target:
        this->obj->notify(this->obj->id, this->obj->id, 0x1FC, 0, 0, 0);
        this->set_state(3);
        this->update();
        this->update();
        return 0;

    state_done:
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x262,
                              0, 0);
        }
        return 3;

    case 1:
        return 1;
    }

    return 0;

target_lost:
    if (this->subActionValue == 1) {
        return 5;
    }
    this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x262,
                      this->targetID, 0);
    return 4;
}

unsigned char RGE_Action_Move_To::is_in_range() {
    float distance;

    if (this->range > 0.0f) {
        if (this->target_obj != 0) {
            distance = this->obj->distance_to_object(this->target_obj);
        } else {
            distance = this->obj->distance_to_position(
                this->target_x, this->target_y, this->target_z);
        }
        if (distance <= this->range) {
            return 1;
        }
    } else {
        if (this->target_obj != 0 &&
            this->obj->inRange(this->target_obj, 0.25f) != 0) {
            return 1;
        }
    }
    return 0;
}
