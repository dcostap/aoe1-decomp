// TRIBE_Action_Discovery_Artifact::set_state: 004CE720, tact_dar.cpp:80-92

#ifndef TACT_DAR_SHARED_CONTEXT
#include "../../include/tact_dar_context.h"
#endif

void TRIBE_Action_Discovery_Artifact::set_state(unsigned char v) {
    this->state = v;
    if (v == 10) {
        this->timer = 3.0f;
    }
}
