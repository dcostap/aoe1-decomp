// TRIBE_Action_Discovery_Artifact ctor 1: 004CE530, tact_dar.cpp:32-37
// FLAGS: /GX
// The module context supplies the canonical RGE_Action and discovery layouts.

#include <stdlib.h>
#ifndef TACT_DAR_SHARED_CONTEXT
#include "../../include/tact_dar_context.h"
#endif

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
    int file_id, RGE_Action_Object* obj)
    : RGE_Action(file_id, obj, 1)
{
    this->action_type = 0x6C;
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)this->obj)->info->size_info->size, 1);
    rge_read(file_id, this->flags,
             ((DiscoveryMaster*)this->obj)->info->size_info->size);
}
