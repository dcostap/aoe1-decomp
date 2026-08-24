#ifndef TACT_TRD_SHARED_CONTEXT
#include "..\..\include\tact_trd_context.h"
#define TACT_TRD_SHARED_CONTEXT 1
#endif

void TRIBE_Action_Trade::save(int file) {
    RGE_Action::save(file);
    rge_write(file, &this->pick_up_x, 4);
    rge_write(file, &this->pick_up_y, 4);
}
