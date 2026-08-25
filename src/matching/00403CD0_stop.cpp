// VA: 00403CD0 RGE_Action_Gather::stop
// PDB source: ACT_GATH.cpp.  The inherited action surface owns set_state.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

int RGE_Action_Gather::stop() {
    this->set_state(2);
    return 1;
}
