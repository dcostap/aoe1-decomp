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

// PDB lines 45-47; VA 004CD1B0.
TRIBE_Action_Build::TRIBE_Action_Build(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->action_type = 0x65;
}

// PDB lines 55-69; VA 004CD210.
// BINARY NOTE: Moving full owner includes into this direct source removes the
// prior four-byte comparison difference under the module flags. The module
// status remains accepted_drift pending owner-status review.
// BINARY NOTE: This constructor keeps the observed task, owner, target, and
// coordinate stores in the original action hierarchy.
TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* action_obj,
                                       RGE_Task* task,
                                       RGE_Static_Object* target)
    : RGE_Action(action_obj, 1)
{
    this->action_type = 0x65;
    this->task = task;

    if (!target || action_obj->owner->id == target->owner->id) {
        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
    }
}

// PDB lines 77-87; VA 004CD2A0.
TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* file,
                                       RGE_Task* task,
                                       float x, float y, float z)
    : RGE_Action(file, 1) {
    this->task = task;
    this->action_type = 0x65;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}

// PDB lines 93-103; VA 004CD2E0.
void TRIBE_Action_Build::first_in_stack(unsigned char value) {
    if (value != 0) {
        if (this->target_obj != 0) {
            this->set_state(4);
            return;
        }
        this->set_state(3);
        return;
    }
    this->set_state(3);
}

// PDB lines 109-198; VA 004CD310.
// BINARY NOTE: /GX is required for the original EH registration and unwind
// state stores around action construction.
void TRIBE_Action_Build::set_state(unsigned char param_1)
{
    RGE_Action_Move_To* move_to;

    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        if (this->obj->owner->computerPlayer() == 1) {
            this->obj->notify((int)this->obj->id, (int)this->obj->id,
                              (int)0x1FA, 0x25AL, 0L, 0L);
            this->set_state(1);
        } else {
            this->obj->notify((int)this->obj->id, (int)this->obj->id,
                              (int)0x202, 0x25AL, 0L, 0L);
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
        move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            0.0f,
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
        move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            this->task->work_range,
            this->task->move_sprite);
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

// PDB lines 204-424; VA 004CD5E0.
// BINARY NOTE: The direct checker reports four strict bytes. The rebuilt
// source selects vslot+0x1F8 where the original selects vslot+0x1F0.
unsigned char TRIBE_Action_Build::update()
{
    float work;

    if (this->targetID != -1) {
        if (this->obj->owner->world->object(this->targetID) == 0) {
            this->set_target_obj(0);
            if (this->state != 2) {
                this->set_state(3);
                return 0;
            }
        }
    }

    if (this->target2ID != -1) {
        if (this->obj->owner->world->object(this->target2ID) == 0) {
            this->set_target_obj2(0);
        }
    }

    if (this->target_obj != 0 && this->target_obj->object_state != 0 &&
        this->timer == 0.0f) {
        if (this->target_obj->hp <
            (float)(int)this->target_obj->master_obj->hp) {
            this->obj->removeAllFromPathingGroup();
            this->obj->owner->processAIOrder(
                this->obj->owner->id,
                this->obj->id,
                0x2CE,
                this->target_obj->id,
                this->target_obj->owner->id,
                this->target_obj->world_x,
                this->target_obj->world_y,
                this->target_obj->world_z,
                1.0f,
                1,
                0,
                100);
            return 0;
        }

        this->set_target_obj(0);
        if (this->state != 2) {
            this->set_state(3);
            return 0;
        }
    }

    switch (this->state) {
    case 0x0B:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
            goto state3_common;
        case 4:
            goto reset_common;
        }
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case 4:
        case 5:
            goto reset_common;
        case 3:
            goto state3_common;
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        }
        break;

    case 6:
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7:
        if (this->timer < 0.0f && this->target_obj != 0 &&
            this->target_obj->attribute_amount_held > 0.0f) {
            this->obj->removeAllFromPathingGroup();
            this->obj->setWaitingToMove(1);
            this->obj->do_command(this->target_obj,
                                  this->target_obj->world_x,
                                  this->target_obj->world_y,
                                  0);
            return 0;
        }

        if (rge_base_game->quick_build != 0) {
            work = 1000.0f;
        } else {
            work = this->task->work_val1 *
                ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate *
                this->obj->owner->world->world_time_delta_seconds;
        }

        if (this->target_obj == 0 ||
            ((TRIBE_Building_Object*)this->target_obj)->build(work) != 0) {
            if (this->target_obj != 0 &&
                this->target_obj->master_obj->id == 0x32) {
                this->timer = -1.0f;
                return 0;
            }
            goto state3_common;
        }
        break;

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify((int)this->obj->id, (int)this->obj->id,
                          (int)0x1F9, 0x25AL, 0L, 0L);
        this->set_state(2);
        return 3;
    }

return_zero:
    return 0;

state3_common:
    this->set_state(3);
    goto return_zero;

reset_common:
    this->set_target_obj(0);
    this->set_state(0x0B);
    goto return_zero;
}

// PDB lines 430-433; VA 004CD910.
int TRIBE_Action_Build::stop() {
    this->set_state(2);
    return 1;
}

// PDB lines 440-447; VA 004CD920.
int TRIBE_Action_Build::move_to(RGE_Static_Object* obj,
                                float x, float y, float z) {
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0x0B);
    return 1;
}

// PDB lines 454-483; VA 004CD960.
// BINARY NOTE: The direct checker reports nine strict bytes in the owner-id
// register map and fallback coordinate load order.
int TRIBE_Action_Build::work(RGE_Static_Object* target,
                             float param_2, float param_3, float param_4) {
    if (target != 0 && target->owner->id == this->obj->owner->id) {
        if (target == this->target_obj) {
            unsigned char action = this->state;
            if (action == 4 || action == 6) {
                return 1;
            }
        }
        this->set_target_obj(target);
        this->set_state(4);
        return 1;
    }

    int iz = *(int*)&param_4;
    int ix = *(int*)&param_2;
    int iy = *(int*)&param_3;
    *(int*)&this->target_z = iz;
    *(int*)&this->target_x = ix;
    *(int*)&this->target_y = iy;
    this->set_target_obj(0);
    this->set_state(11);
    return 1;
}
