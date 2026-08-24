// TRIBE_Action_Discovery_Artifact ctor 2: 004CE5F0, tact_dar.cpp:42-48
// FLAGS: /GX
// The natural constructor surface sets the task, action type, target, and
// allocation.  The compiler supplies the derived vptr store.

#ifndef TACT_DAR_SHARED_CONTEXT
#include "../../include/tact_dar_context.h"
#endif

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
    RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(obj, 1)
{
    this->task = task;
    this->action_type = 0x6C;
    RGE_Action::set_target_obj(target);
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)this->obj)->info->size_info->size, 1);
}
