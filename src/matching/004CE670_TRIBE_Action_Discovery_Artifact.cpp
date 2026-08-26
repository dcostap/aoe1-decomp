// TRIBE_Action_Discovery_Artifact ctor 3: 004CE670, tact_dar.cpp:53-61
// The constructor stores each coordinate in its matching target slot.

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
    this->target_x = fx;
    this->target_y = fy;
    this->target_z = fz;
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)this->obj)->info->size_info->size, 1);
}
