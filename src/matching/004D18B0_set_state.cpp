// VA: 004D18B0 TRIBE_Action_Repair::set_state
// FLAGS: config/flags/004D18B0_set_state.rsp (/nologo /c /O2 /Oy /GX)
// Attempt log:
// - Baseline natural /GX switch preserved the EH frame and broad action paths,
//   but used the wrong state-1 call and duplicated the notify site.
// - State 1 calls the inherited virtual set_target_obj(0) at vslot +54; states
//   1/2/3 then join the natural post-switch new_sprite tail.
// - The exact layout is RGE_Action_Move_To size 0x44, task sprites/sound at
//   +34/+38/+44, and action-object data sprite/range at +18/+114.
// - Exact: 713/713 bytes under the pinned VC5 /O2 /Oy /GX toolchain. No inline
//   asm or compiler-only source scaffolding.

#include "../../include/tact_rep_context.h"

void TRIBE_Action_Repair::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x26a, 0, 0);
        break;

    case 11: {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f, this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0d);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        if (this->target_obj != 0) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }
        RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_obj, this->obj->object_data->work_range, this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0d);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 10: {
        this->obj->new_sprite(this->obj->object_data->sprite);
        this->timer = 1.0f;
        RGE_Static_Object* target = this->target_obj;
        if (target == 0) return;
        short id = target->object_data->object_type;
        if (id != 2 && id != 0x14 && id != 0x15 && id != 0x16) return;
        if (target->command_flag != this->save_target_command_flag) return;
        target->moveTo(this->obj->world_x, this->obj->world_y, this->obj->world_z, 0, 1);
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
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
            return;
        }
        return;

    case 1:
        this->set_target_obj(0);
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1fa, 0x26a, 0, 0);
        }
        break;

    case 2:
        break;

    default:
        return;
    }

    this->obj->new_sprite(this->obj->object_data->sprite);
}
