#include "../../include/act_bird_context.h"

void RGE_Action_Bird::first_in_stack(unsigned char param_1) {
    if (param_1) {
        RGE_Action_Object* obj;

        obj = this->obj;
        obj->teleport(obj->world_x, obj->world_y, 6.0f);
        this->set_state(3);
        return;
    }

    this->set_state(3);
}
