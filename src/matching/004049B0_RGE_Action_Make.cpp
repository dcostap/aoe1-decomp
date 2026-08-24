#include "../../include/act_make_context.h"

RGE_Action_Make::RGE_Action_Make(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    this->action_type = 0x15;
}
