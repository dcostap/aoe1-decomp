// TRIBE_Action_Discovery_Artifact::save: 004CE6D0, tact_dar.cpp:65-69

#ifndef TACT_DAR_SHARED_CONTEXT
#include "../../include/tact_dar_context.h"
#endif

void TRIBE_Action_Discovery_Artifact::save(int file) {
    int size;

    RGE_Action::save(file);
    size = ((DiscoveryMaster*)this->obj)->info->size_info->size;
    rge_write(file, this->flags, size);
}
