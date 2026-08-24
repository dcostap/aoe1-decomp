// 004D2CB0 TRIBE_Action_Trade::update
// Source: tact_trd.cpp lines 281-626
// No EH. The original frame is eight bytes plus ESI and EDI.
//
// The action, player, object, task, and virtual surfaces come from the
// tact_trd module context. The unresolved code shape remains observed.
// BINARY NOTE: the original frame is 0x8 with ESI and EDI only.

#ifndef TACT_TRD_SHARED_CONTEXT
#include "..\..\include\tact_trd_context.h"
#define TACT_TRD_SHARED_CONTEXT 1
#endif

extern float DAT_00575348;
extern float DAT_00575358;
extern float DAT_0057535c;
extern float DAT_00575360;
extern double DAT_00575350;
extern double DAT_00575368;
extern float DAT_00575370;

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
