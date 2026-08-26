#ifndef AOE1_TACT_ART_TU_CONTEXT
#include "../../include/tact_art_context.h"
#endif

#include <string.h>

void TRIBE_Action_Artifact::first_in_stack(unsigned char value) {
    if (value == 0) {
        return;
    }
    if (this->field_10 != 0) {
        this->set_state(5);
        return;
    }
    // BINARY NOTE: the executable compares raw four-byte field representations.
    // memcpy preserves that comparison without a wrong-type pointer cast.
    int field_20_bits;
    memcpy(&field_20_bits, &this->field_20, sizeof(field_20_bits));
    if (field_20_bits != 0xBF800000) {
        int field_24_bits;
        memcpy(&field_24_bits, &this->field_24, sizeof(field_24_bits));
        if (field_24_bits != 0xBF800000) {
            this->set_state(4);
            return;
        }
    }
    this->set_state(6);
}
