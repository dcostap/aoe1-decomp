#ifndef AOE1_TACT_ART_TU_CONTEXT
#include "../../include/tact_art_context.h"
#endif

// BINARY NOTE: tact_art.cpp lines 263-265 dispatch state 100 through vslot 0x5C.
void TRIBE_Action_Artifact::reset_owner() {
    this->set_state(100);
}
