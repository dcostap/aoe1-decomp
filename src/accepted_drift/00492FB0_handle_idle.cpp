// ACCEPTED_DRIFT: reviewed 2026-05-26 by orchestrator. Exact behavior/calls/stack effects; nonzero diff is localized to equivalent x87 multiply encoding (`fild speed; fmulp` vs `fimul speed`) causing 2-byte shift and branch displacement/tail padding differences only.
// TScrollTextPanel::handle_idle
// VA: 00492FB0
// scr_cred.cpp
// Attempts: rebuilt natural member/virtual/IAT surfaces; fixed set_redraw slot +0x20 and parent action slot +0xB4.
// Tried FPU amount forms: inline int multiply, explicit (double)speed, named double val, val*=speed, swapped operands, (float)speed, volatile speed, and /Op,/Oi,/Og,/Ot,/O1 flags.
// Best remaining drift: VC5 emits `fimul dword [esi+190h]` (6B) for `elapsed*const*speed`; original emits equivalent `fild dword [esi+190h]; fmulp` (8B). This 2-byte arithmetic encoding difference shifts branch displacements/tail by 2; behavior/calls/stack effects otherwise match.

#include "../../include/scr_cred_context.h"

long TScrollTextPanel::handle_idle()
{
    if (this->last_time == 0) {
        this->last_time = debug_timeGetTime((char*)0x5862BC, 0x1DC);
    } else {
        unsigned long now = debug_timeGetTime((char*)0x5862BC, 0x1DF);
        __int64 elapsed = (unsigned long)(now - this->last_time);
        int amount = (long)(((double)elapsed * *(float*)0x572968) * this->speed);
        if (amount > 0) {
            this->scroll += amount;
            this->set_redraw(1);
            this->last_time = now;
        }
    }
    if (this->done != 0) {
        if (this->child != 0) {
            ((TPanelActionTarget*)this->child)->action(this, 1, 0, 0);
        }
    }
    return this->TPanel::handle_idle();
}
