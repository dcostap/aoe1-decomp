// VA: 004CD310 TRIBE_Action_Build::set_state
// Attempt log:
// try 1-10: prior decompiler-shaped source reached the original 661-byte size,
// but used fabricated action classes, wrong task states, and misnamed virtual
// calls; its broad switch drift was not a useful source reconstruction.
// baseline candidate: restore the tact_bld.cpp action hierarchy and natural
// state switch, with RGE_Task sprite/range ownership and real action helpers.
// layout probe: declaring target_obj/target_obj2 and target IDs in the base
// gap restored target_x/task/sub_actions to +20/+30/+34 and matched all 661B.
// exact under /GX; source remains typed/natural with no compiler-only hacks.
// FLAGS: config/flags/004CD310_set_state.rsp uses /GX because the original has
// EH registration/unwind-state stores around new/action construction.

void TRIBE_Action_Build::set_state(unsigned char param_1)
{
    RGE_Action_Move_To* move_to;

    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        if (this->obj->owner->computerPlayer() == 1) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x25A, 0, 0);
            this->set_state(1);
        } else {
            this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x25A, 0, 0);
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
