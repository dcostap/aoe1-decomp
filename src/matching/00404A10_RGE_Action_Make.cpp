#include "../../include/act_make_context.h"

RGE_Action_Make::RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2)
    : RGE_Action(param_1, 1) {
    this->action_type = 0x15;
    this->task = param_2;
}
