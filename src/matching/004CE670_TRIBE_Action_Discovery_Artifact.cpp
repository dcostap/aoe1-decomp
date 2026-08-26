// TRIBE_Action_Discovery_Artifact ctor 3: 004CE670, tact_dar.cpp:53-61
// The shipped constructor stores the three float arguments in the proven
// target-coordinate slots in the observed order.

#include <stdlib.h>
#ifndef TACT_DAR_SHARED_CONTEXT
#include "../../include/tact_dar_context.h"
#endif

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
    RGE_Action_Object* obj, RGE_Task* task, float fx, float fy, float fz)
    : RGE_Action(obj, 1)
{
    this->task = task;
    this->action_type = 0x6C;
    this->target_x = fz;
    this->target_y = fx;
    this->target_z = fy;
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)this->obj)->info->size_info->size, 1);
}
