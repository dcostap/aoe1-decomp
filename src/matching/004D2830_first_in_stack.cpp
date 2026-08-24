#ifndef TACT_TRD_SHARED_CONTEXT
#include "..\..\include\tact_trd_context.h"
#define TACT_TRD_SHARED_CONTEXT 1
#endif

void TRIBE_Action_Trade::first_in_stack(unsigned char param_1) {
    if (this->obj->facet != 0 && this->obj->facet != 2 && this->obj->facet != 1) {
        this->obj->facet = 1;
    }
    if (param_1 != 0) {
        if (this->target_obj != 0) {
            this->set_state(4);
            return;
        }
        this->set_state(2);
        return;
    }
    this->set_state(3);
}
