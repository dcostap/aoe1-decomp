#ifndef ACT_TRAN_SHARED_CONTEXT
#include "../../include/act_tran_context.h"
#endif

RGE_Action_Transport::RGE_Action_Transport(RGE_Action_Object* object,
                                           RGE_Task* task,
                                           float x, float y, float z)
    : RGE_Action(object, 1) {
    this->task = task;
    this->action_type = 0x0C;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}
