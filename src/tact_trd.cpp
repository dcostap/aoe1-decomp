// PDB source module: C:\\msdev\\work\\age1_x1\\tact_trd.cpp.
// Definitions follow the authentic PDB source order.
//
// The scalar deleting destructor at 004D26E0 is compiler-generated and has no
// handwritten source owner.  The ten exact owners, the accepted-drift
// set_state owner, and the scratch update owner share this source module.

#include "../include/tact_trd_context.h"

// PDB lines 42-47; VA 004D2660.
TRIBE_Action_Trade::TRIBE_Action_Trade(int file, RGE_Action_Object* obj)
    : RGE_Action(file, obj, 1)
{
    rge_read(file, &this->pick_up_x, 4);
    rge_read(file, &this->pick_up_y, 4);
    this->action_type = 0x6F;
}

// PDB lines 55-70; VA 004D2710.
TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* obj,
                                       RGE_Task* task,
                                       RGE_Static_Object* target)
    : RGE_Action(obj, 1)
{
    this->task = task;
    this->action_type = 0x6F;
    this->set_target_obj(target);
    this->target_x = target->world_x;
    this->target_y = target->world_y;
    this->target_z = target->world_z;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
}

// PDB lines 77-91; VA 004D27A0.
TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* obj,
                                       RGE_Task* task,
                                       float x, float y, float z)
    : RGE_Action(obj, 1)
{
    this->task = task;
    this->action_type = 0x6F;
    *(int*)&this->target_x = *(int*)&x;
    *(int*)&this->target_y = *(int*)&y;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
    *(int*)&this->target_z = *(int*)&z;
}

// PDB lines 98-103; VA 004D27F0.
void TRIBE_Action_Trade::save(int file)
{
    RGE_Action::save(file);
    rge_write(file, &this->pick_up_x, 4);
    rge_write(file, &this->pick_up_y, 4);
}

// PDB lines 109-128; VA 004D2830.
void TRIBE_Action_Trade::first_in_stack(unsigned char param_1)
{
    if (this->obj->facet != 0 && this->obj->facet != 2 && this->obj->facet != 1) {
        this->obj->facet = 1;
    }
    if (param_1 != 0) {
        if (this->target_obj != 0) {
            this->set_state(4);
            return;
        }
        this->set_state(2);
        return;
    }
    this->set_state(3);
}

// PDB lines 134-275; VA 004D2880.
// BINARY NOTE: The original is an EH-framed switch.  The high object slots
// are represented by the reviewed virtual surface in tact_trd_context.h.
// BINARY NOTE: Case-local Move_To results preserve the two constructor-result
// handoffs and the original action-list call order.
void TRIBE_Action_Trade::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x267, 0, 0);
        this->obj->new_sprite(this->get_wait_sprite());
        return;

    case 2:
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11: {
        RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            0.0f,
            this->get_move_sprite());
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }
        move_to->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;
    }

    case 4: {
        if (this->target_obj == 0) {
            this->set_state(0x0D);
            return;
        }
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;

        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            this->task->work_range,
            this->get_move_sprite());
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 6:
        this->obj->new_sprite(this->get_move_sprite());
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
        }
        if (this->target_obj != 0) {
            this->pick_up_x = this->target_obj->world_x;
            this->pick_up_y = this->target_obj->world_y;
        } else {
            this->pick_up_x = -1.0f;
            this->pick_up_y = -1.0f;
        }
        return;

    case 8:
        if (this->obj->attribute_amount_held > DAT_00575348) {
            if (this->target_obj2 == 0 ||
                this->target_obj2->master_obj->id != this->obj->master_obj->drop_site) {
                short drop_site = this->obj->master_obj->drop_site;
                if (drop_site != -1) {
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        drop_site,
                        this->obj->master_obj->backup_drop_site,
                        this->obj->world_x,
                        this->obj->world_y,
                        1,
                        2,
                        (RGE_Static_Object*)this->obj));
                } else {
                    this->set_target_obj2(0);
                }
            }

            if (this->target_obj2 != 0) {
                RGE_Action_Move_To* action = new RGE_Action_Move_To(
                    this->obj,
                    this->target_obj2,
                    0.0f,
                    this->get_move_sprite());
                if (action == 0) {
                    this->set_state(0x0D);
                    return;
                }
                this->sub_actions->add_action(action);
                action->setSubAction(1);
                return;
            }

            this->obj->notify(this->obj->id, this->obj->id, 0x203, 0x267, 0, 0);
            this->set_state(0x0D);
            return;
        }

        if (this->target_obj != 0 &&
            this->target_obj->attribute_amount_held <= DAT_00575348 &&
            this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) == 0) {
            this->set_target_obj(0);
            this->set_state(3);
        }
        return;

    default:
        return;
    }
}

// PDB lines 281-626; VA 004D2CB0.
// BINARY NOTE: The original frame is eight bytes plus ESI and EDI.
// BINARY NOTE: This complete body remains scratch.  Its exact anchors have
// matching boundaries and calls, but its source still has structural drift.
extern double DAT_00575350;

unsigned char TRIBE_Action_Trade::update()
{
    float max_hold;
    float take_amount;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
    }
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }
    if (this->target_obj != 0) {
        if (this->target_obj->object_state >= 7) {
            this->set_target_obj(0);
        }
    }
    if (this->target_obj2 != 0) {
        if (this->target_obj2->object_state >= 7) {
            this->set_target_obj2(0);
        }
    }

    if (this->target_obj != 0) {
        if (this->obj->owner->player_id == this->target_obj->owner->player_id) {
            this->set_target_obj(0);
            this->set_target_obj2(0);
            this->set_state(1);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->player_id, this->obj->player_id,
                                  0x1FB, 0x267, this->targetID, 0);
            }
            return 4;
        }
    }

    switch (this->state) {
    case 11:
        if (this->timer < DAT_00575350) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_00575350) {
                this->timer = 0.0f;
                if (this->target_obj != 0) {
                    this->set_state(4);
                    return 0;
                }
                this->set_state(3);
                return 0;
            }
            return 0;
        }
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
        case 4:
            this->timer = -0.5f;
            return 0;
        }
        return 0;

    case 4:
        if (this->timer < DAT_00575350) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_00575350) {
                this->timer = 0.0f;
                if (this->target_obj != 0) {
                    this->set_state(4);
                    return 0;
                }
                this->set_state(3);
                return 0;
            }
            return 0;
        }
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3:
        case 4:
            this->timer = -0.5f;
            return 0;
        case 5:
            goto update_state_6;
        }
        return 0;

    case 6:
    update_state_6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0.0f, 0.0f) != 0) {
            if (this->target_obj->trade_value > DAT_00575348 ||
                this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) != 0) {
                this->set_state(7);
                return 0;
            }
            this->set_target_obj(0);
            this->set_state(3);
        }
        return 0;

    case 7:
        if (this->target_obj == 0) {
            if (this->pick_up_y > DAT_00575350) {
                this->set_state(8);
                return 0;
            }
            this->set_state(3);
            return 0;
        }
        if (this->obj->facet != 0 && this->obj->facet != 2 && this->obj->facet != 1) {
            this->obj->facet = 1;
        }
        {
            float capacity = (float)this->obj->master_obj->capacity;
            max_hold = capacity - this->obj->amount;
            if (this->obj->owner->resource_store->max_resource[this->obj->facet] < max_hold) {
                max_hold = this->obj->owner->resource_store->max_resource[this->obj->facet];
            }
            if (this->target_obj->owner->resource_store->amount < max_hold) {
                max_hold = this->target_obj->owner->resource_store->amount;
            }
            this->target_obj->owner->add_attribute_num(this->obj->facet, -max_hold, 1);
            this->target_obj->owner->resource_store->amount -= max_hold;
            this->obj->amount += max_hold;
            if (this->obj->amount >= capacity) {
                goto update_state_8;
            }
            if (this->target_obj->owner->resource_store->amount <= DAT_00575348 &&
                this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) == 0) {
                this->set_state(8);
                return 0;
            }
        }
        return 0;

    case 8:
        if (this->timer < DAT_00575350) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_00575350) {
                this->timer = 0.0f;
                this->set_state(8);
                return 0;
            }
            return 0;
        }
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            if (this->target_obj2 == 0) {
                goto update_state_8;
            }
            if (this->pick_up_y > DAT_00575350) {
                RGE_Task* trade_task = (RGE_Task*)this->task;
                if (trade_task->work_sound != 0) {
                    trade_task->work_sound->play(1);
                }
                if (this->pick_up_x < DAT_00575350 || this->pick_up_y < DAT_00575350) {
                    take_amount = DAT_00575360;
                } else {
                    float dx = this->pick_up_x - this->target_obj2->world_x;
                    float dy = this->pick_up_y - this->target_obj2->world_y;
                    take_amount = (dy * dy + dx * dx) * DAT_00575358 * DAT_0057535c;
                }
                if (this->obj->owner->civilization == 0x0F) {
                    take_amount += take_amount;
                }
                if (take_amount < DAT_00575360) {
                    take_amount = DAT_00575360;
                }
                take_amount *= this->obj->amount;
                if (take_amount > DAT_00575370) {
                    take_amount = DAT_00575370;
                }
                this->obj->owner->add_attribute_num(3, take_amount, 1);
                this->obj->set_attribute(this->obj->facet, 0.0f);
            }
            if (this->target_obj != 0) {
                this->set_state(4);
                return 0;
            }
            this->set_state(3);
            return 0;
        case 3:
        case 4:
        case 5:
            this->timer = -0.5f;
            return 0;
        }
        return 0;

    update_state_8:
        this->set_state(8);
        return 0;

    case 1:
        return 1;

    case 13:
        this->obj->notify(this->obj->player_id, this->obj->player_id,
                          0x1F9, 0x267, 0, 0);
        this->set_state(2);
        return 3;
    }
    return 0;
}

// PDB lines 632-640; VA 004D32C0.
RGE_Sprite* TRIBE_Action_Trade::get_move_sprite(void)
{
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;

    if (task_facet != -1) {
        if (this->obj->facet == task_facet) {
            if ((int)this->obj->attribute_amount_held > 0) {
                if (task->carry_sprite != 0) {
                    return task->carry_sprite;
                }
            }
        }
    }
    return task->move_sprite;
}

// PDB lines 646-653; VA 004D32F0.
RGE_Sprite* TRIBE_Action_Trade::get_wait_sprite(void)
{
    TRIBE_Action_Trade* action = this;
    RGE_Task* task = action->task;
    short task_facet = task->attribute_type;

    if (task_facet != (short)0xFFFF && task_facet == action->obj->facet
        && (int)action->obj->attribute_amount_held > 0 && task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return action->obj->master_obj->sprite;
}

// PDB lines 659-662; VA 004D3330.
int TRIBE_Action_Trade::stop()
{
    this->set_state(2);
    return 1;
}

// PDB lines 669-690; VA 004D3340.
int TRIBE_Action_Trade::move_to(RGE_Static_Object* obj, float x, float y, float z)
{
    if (obj != 0) {
        if (obj->owner == this->obj->owner) {
            if (obj->master_obj->id == this->obj->master_obj->id2) {
                if (obj == this->target_obj2 && this->state == 8) {
                    return 1;
                }
                this->set_target_obj2(obj);
                this->set_state(8);
                return 1;
            }
        }
    }

    // Null path: store in field-offset order.
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0xB);
    return 1;
}

// PDB lines 697-727; VA 004D33C0.
int TRIBE_Action_Trade::work(RGE_Static_Object* obj, float x, float y, float z)
{
    if (obj != 0) {
        if (obj == this->target_obj) {
            if (this->state == 4 || this->state == 6 || this->state == 7) {
                return 1;
            }
        }

        // Check owner/id match.
        if (obj->owner == ((RGE_Static_Object*)this->action_obj)->owner) {
            if (obj->master_obj->id == this->obj->master_obj->id2) {
                this->set_target_obj2(obj);
                this->set_state(8);
                return 1;
            }
        }

        this->set_target_obj(obj);
        this->set_state(4);
        return 1;
    }

    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0xB);
    return 1;
}
