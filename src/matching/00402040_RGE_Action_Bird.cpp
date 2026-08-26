#include "../../include/act_bird_context.h"

RGE_Action_Bird::RGE_Action_Bird(
    RGE_Action_Object* param_1,
    RGE_Task* param_2,
    float param_3,
    float param_4,
    float param_5)
    : RGE_Action(param_1, 1) {
    this->task = param_2;
    this->action_type = 10;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
}
