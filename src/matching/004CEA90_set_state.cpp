// 004CEA90 TRIBE_Action_Heal::set_state
// Source: tact_hea.cpp lines 98-169
// Size: 566 bytes, EH-framed
//
// Attempt log:
// Previous worker left only an experiment note after a noncanonical constructor
// definition.  The clean reconstruction below restores the period source shape:
// typed action/task ownership, source-order switch cases, and declaration-only
// Move_To constructors so VC5 emits operator new plus the existing ctor calls.
//
// Probe 1 (baseline): natural typed switch and declaration-only Move_To
// constructors; exact 566/566-byte match under the pinned VC5 toolchain.
// FLAGS: /nologo /c /O2 /Oy /GX
// Canonical-owner cleanup candidate: 566-byte output with 456 positional
// differences. The prior exact result depended on the legacy context.

#include "../../include/tact_hea.h"

void TRIBE_Action_Heal::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x25B, 0, 0);
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 2:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 11: {
        RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
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
    }

    case 4: {
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            0.4f,
            this->task->move_sprite);
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
