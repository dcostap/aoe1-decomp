#include "../../include/act_bird_context.h"
extern int __cdecl debug_rand(char* param_1, int param_2);

static const double bird_update_zero = 0.0;

unsigned char RGE_Action_Bird::update(void) {
    RGE_Action_Move_To* move_to;
    Bird_Move_Random* move_random;

    if (bird_update_zero < this->timer) {
        this->timer = this->timer - this->obj->owner->bird_data->timer_step;
    }

    switch (this->state) {
    case 4:
        if (this->timer <= bird_update_zero) {
            this->set_state(6);
        }
        if ((((int)this->sub_actions->update()) & 0xFF) - 1 != 0) {
            return 0;
        }
        this->set_state(3);
        return 0;

    case 6:
        if (this->timer <= bird_update_zero) {
            this->set_state(4);
        }
        if ((((int)this->sub_actions->update()) & 0xFF) - 1 != 0) {
            return 0;
        }
        this->set_state(3);
        return 0;

    case 3:
        move_random = this->obj->owner->bird_data->move_random;
        this->target_x = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x84) * move_random->x) / 0x7FFF);
        this->target_y = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x85) * move_random->y) / 0x7FFF);
        this->target_z = this->obj->world_z;
        move_to = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->task->work_range, this->obj->sprite);
        if (move_to == 0) {
            this->set_state(3);
            return 0;
        }
        this->sub_actions->add_action(move_to);
        this->set_state(4);
        return 0;

    case 1:
        return 1;
    }

    return 0;
}
