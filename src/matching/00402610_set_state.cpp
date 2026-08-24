#include "../../include/act_entr_context.h"

void RGE_Action_Enter::set_state(unsigned char param_1) {
    RGE_Action_Move_To* move_to;

    this->sub_actions->delete_list();
    this->state = param_1;
    switch (param_1) {
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
            ((RGE_Action*)this)->set_state(0x0D);
            return;
        }

        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;
    case 2:
        this->timer = 1.0f;
    case 1:
    case 0x0D:
    case 0x0E:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;
    default:
        return;
    }
}
