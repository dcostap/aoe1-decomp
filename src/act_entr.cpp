// PDB source module: C:\\msdev\\work\\age1_x1\\act_entr.cpp.
// Definitions follow the original source and address order.

#include "../include/act_entr.h"
#include "../include/act_list.h"
#include "../include/act_move.h"
#include "../include/act_obj.h"
#include "../include/game_globals.h"
#include "../include/player.h"
#include "../include/task.h"
#include "../include/world.h"

// VA: 004023C0.
RGE_Action_Enter::RGE_Action_Enter(int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1)
{
    this->action_type = 3;
}

// VA: 00402410.
RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Object* object,
                                   RGE_Task* task,
                                   RGE_Static_Object* target)
    : RGE_Action(object, 1)
{
    XYPoint start;
    XYPoint dest;
    XYPoint result;
    RGE_Action* action;

    this->action_type = 3;
    this->task = task;
    this->set_target_obj(target);
    if (target == 0) {
        return;
    }

    this->target_x = target->world_x;
    this->target_y = target->world_y;
    this->target_z = target->world_z;

    if (target->actionState() == 2) {
        if (target->more_room() == 1) {
            if (this->obj->owner->computerPlayer() == 0) {
                goto line_path;
            }
        }

        if (this->obj->owner->computerPlayer() == 1) {
            goto line_path;
        }
    }

    if (target->actionState() == 11) {
        RGE_Action_Object* target_action =
            static_cast<RGE_Action_Object*>(target);
        action = target_action->actions->get_action();
        if (action->target2ID == 0) {
            goto line_path;
        }
    }

    if (target->actionState() == 11) {
        RGE_Action_Object* target_action =
            static_cast<RGE_Action_Object*>(target);
        action = target_action->actions->get_action();
        this->target_x = action->targetX();
        action = target_action->actions->get_action();
        this->target_y = action->targetY();
    }

    return;

line_path:
    dest.x = (int)object->world_x;
    dest.y = (int)object->world_y;
    start.x = (int)target->world_x;
    start.y = (int)target->world_y;

    if (object->firstTileAlongLine(dest, start, result, 2, 2, 1) == 1) {
        this->target_x = (float)result.x + 0.5f;
        this->target_y = (float)result.y + 0.5f;
        target->moveTo((float)result.x, (float)result.y, target->world_z,
                       0.5f, 1);
    } else {
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        target->moveTo(object->world_x, object->world_y, target->world_z,
                       0.5f, 1);
    }
}

// VA: 004025F0.
RGE_Action_Enter::~RGE_Action_Enter()
{
}

// VA: 00402600.
void RGE_Action_Enter::first_in_stack(unsigned char value)
{
    this->set_state(4);
}

// VA: 00402610.
void RGE_Action_Enter::set_state(unsigned char value)
{
    RGE_Action_Move_To* move_to;

    this->sub_actions->delete_list();
    this->state = value;

    switch (value) {
    case 4:
        move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            this->task->work_range,
            this->task->move_sprite
        );
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

// VA: 00402740.
unsigned char RGE_Action_Enter::update()
{
    RGE_Action* action;
    XYPoint start;
    XYPoint dest;
    XYPoint result;
    int target_valid;

    target_valid = 1;
    if (this->targetID != -1 &&
        this->obj->owner->world->object(this->targetID) == 0) {
        target_valid = 0;
    }

    if (target_valid != 0 && this->target2ID != -1 &&
        this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
        target_valid = 0;
    }

    if (target_valid != 0 && this->target_obj != 0 &&
        (this->target_obj->object_state >= 3 ||
         this->obj->owner->isAlly(
             (int)(short)this->target_obj->owner->id) == 0)) {
        target_valid = 0;
    }

    if (target_valid == 0) {
        this->set_state(1);
        this->set_target_obj(0);
        this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x269, 0, 0);
        return 4;
    }

    switch (this->state) {
    case 4:
        if (this->target_obj != 0 && this->target_obj->is_dying() == 0) {
            switch (this->sub_actions->update()) {
            case 3:
                this->set_state(2);
                return 0;

            case 1:
            case 2:
                if (this->task->work_range >=
                    this->obj->distance_to_object(this->target_obj) -
                        DAT_0056e1a4) {
                    // enter_obj is the inherited RGE_Static_Object vslot +0xD0.
                    this->obj->enter_obj(this->target_obj);
                    goto entered_target;
                }
                this->set_state(2);
                return 0;

            case 4:
            case 5:
                break;

            default:
                return 0;
            }
        }

        this->set_target_obj(0);
        this->set_state(0x0D);
        return 0;

    case 2:
        this->timer = this->timer -
                      this->obj->owner->world->world_time_delta_seconds;
        if (this->timer > DAT_0056e1a8) {
            return 0;
        }

        if (this->task->work_range >=
            this->obj->distance_to_object(this->target_obj) - DAT_0056e1a4) {
            this->obj->enter_obj(this->target_obj);
            goto entered_target;
        }

        if (this->target_obj->actionState() == 2) {
            dest.x = (int)this->obj->world_x;
            dest.y = (int)this->obj->world_y;
            start.x = (int)this->target_obj->world_x;
            start.y = (int)this->target_obj->world_y;
            if (this->obj->firstTileAlongLine(&dest, &start, &result, 2, 2,
                                              1) == 1) {
                float tile_x;
                float tile_y;

                tile_x = (float)result.x - DAT_0056e1a0;
                tile_y = (float)result.y - DAT_0056e1a0;
                if (this->target_x == tile_x &&
                    tile_y == this->target_y) {
                    this->target_x = this->target_obj->world_x;
                    this->target_y = this->target_obj->world_y;
                    this->set_state(4);
                    return 0;
                }

                this->target_x = tile_x;
                this->target_y = tile_y;
                this->target_obj->moveTo(
                    (float)result.x, (float)result.y,
                    this->target_obj->world_z, 0, 1);
            } else {
                this->target_x = this->target_obj->world_x;
                this->target_y = this->target_obj->world_y;
                this->target_obj->moveTo(
                    this->obj->world_x, this->obj->world_y,
                    this->target_obj->world_z, 0.5f, 1);
            }
        } else if (this->target_obj->actionState() == 0x0B) {
            RGE_Action_Object* target_action =
                static_cast<RGE_Action_Object*>(this->target_obj);
            action = target_action->actions->get_action();
            this->target_x = action->targetX();
            action = target_action->actions->get_action();
            this->target_y = action->targetY();
        }

        this->set_state(4);
        return 0;

entered_target:
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x269, 0,
                              0);
        }
        this->set_state(1);
        return 2;

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x269, 0, 0);
        return 3;

    default:
        return 0;
    }
}
