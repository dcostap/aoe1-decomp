#include "../../include/act_expl_context.h"

RGE_Action_Explore::RGE_Action_Explore(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->action_type = 4;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}
