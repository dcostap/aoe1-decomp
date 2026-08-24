#ifndef TACT_TRD_SHARED_CONTEXT
#include "..\..\include\tact_trd_context.h"
#define TACT_TRD_SHARED_CONTEXT 1
#endif

int TRIBE_Action_Trade::stop() {
    this->set_state(2);
    return 1;
}
