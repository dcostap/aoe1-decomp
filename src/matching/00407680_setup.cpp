#include "../../include/action_context.h"

int RGE_Action::setup(RGE_Action_Object* action_object) {
    this->action_type = 0;
    this->obj = action_object;
    this->state = 0;
    this->target_obj = 0;
    this->target_obj2 = 0;
    this->target_x = 0.0f;
    this->target_y = 0.0f;
    this->target_z = 0.0f;
    this->timer = 0.0f;
    this->task = 0;
    this->sub_actions = this->create_action_list(action_object);
    this->sprite = 0;
    this->subActionValue = 0;
    return 1;
}
