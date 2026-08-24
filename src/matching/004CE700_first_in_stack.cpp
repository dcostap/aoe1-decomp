// TRIBE_Action_Discovery_Artifact::first_in_stack: 004CE700, tact_dar.cpp:73-76

#ifndef TACT_DAR_SHARED_CONTEXT
#include "../../include/tact_dar_context.h"
#endif

void TRIBE_Action_Discovery_Artifact::first_in_stack(unsigned char v) {
    if (v) {
        this->set_state(6);
    }
}
