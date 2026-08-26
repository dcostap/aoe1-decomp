// ACCEPTED_DRIFT: VC5 inserts add esp,4 after virtual calls (cdecl-style)
// even with __thiscall-declared virtual member functions. The original has
// callee cleanup via ret 4. The FPU comparisons use relocated zero constant
// vs original's hardcoded 56E6B8h address (masked in comparison).
// VA: 00406E00 first_in_stack (70B, act_tran.cpp)

#ifndef ACT_TRAN_SHARED_CONTEXT
#include "../../include/act_tran_context.h"
#endif

void RGE_Action_Transport::first_in_stack(unsigned char param_1)
{
    if (param_1 != 0 && this->field_20 >= 0.0f && this->field_24 >= 0.0f) {
        this->set_state(0xB);
        return;
    }
    this->set_state(2);
}
