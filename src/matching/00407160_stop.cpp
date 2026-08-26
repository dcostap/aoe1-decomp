#ifndef ACT_TRAN_SHARED_CONTEXT
#include "../../include/act_tran_context.h"
#endif

int RGE_Action_Transport::stop() {
    this->set_state(2);
    return 1;
}
