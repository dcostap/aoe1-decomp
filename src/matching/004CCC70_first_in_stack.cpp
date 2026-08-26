#ifndef AOE1_TACT_ART_TU_CONTEXT
#include "../../include/tact_art_context.h"
#endif

void TRIBE_Action_Artifact::first_in_stack(unsigned char value) {
    if (value == 0) {
        return;
    }
    if (this->field_10 != 0) {
        this->set_state(5);
        return;
    }
    if ((this->field_20 != (int)0xBF800000) && (this->field_24 != (int)0xBF800000)) {
        this->set_state(4);
        return;
    }
    this->set_state(6);
}
