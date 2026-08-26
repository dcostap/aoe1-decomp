#ifndef AOE1_TACT_ART_TU_CONTEXT
#include "../../include/tact_art_context.h"
#endif

int TRIBE_Action_Artifact::stop() {
    this->set_state(6);
    return 1;
}
