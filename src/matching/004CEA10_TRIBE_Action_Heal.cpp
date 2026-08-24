#include "../../include/tact_hea_context.h"

TRIBE_Action_Heal::TRIBE_Action_Heal(int file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1) {
    this->task = task;
    this->action_type = 0x69;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}
