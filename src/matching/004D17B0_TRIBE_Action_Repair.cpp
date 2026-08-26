#include "../../include/tact_rep_context.h"

TRIBE_Action_Repair::TRIBE_Action_Repair(RGE_Action_Object* obj, RGE_Task* task,
                                         float x, float y, float z)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->action_type = 0x6A;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->repair_field_40 = 0;
}
