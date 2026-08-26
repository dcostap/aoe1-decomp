#ifndef AOE1_TACT_ART_TU_CONTEXT
#include "../../include/tact_art_context.h"
#endif

TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1) {
    this->task = task;
    this->action_type = 0x6B;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}
