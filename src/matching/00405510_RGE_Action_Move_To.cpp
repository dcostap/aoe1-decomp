// VA: 00405510 RGE_Action_Move_To::RGE_Action_Move_To(int, RGE_Action_Object*)
// PDB source: act_move.cpp lines 40-43 (103 bytes, 32 asm lines)
// FLAGS: config/flags/00405510_RGE_Action_Move_To.rsp keeps /GX for the original EH-framed constructor.
// MATCHED 2026-05-09: the EH frame appears when rge_read is declared as an ordinary C++ function, not extern "C".
// In a /GX constructor after a nontrivial base ctor, the C++ call surface is treated as potentially throwing and VC5
// emits the base-unwind state without adding fake cleanup locals/calls.

#ifndef ACT_MOVE_CANONICAL_TU
#include "../../include/act_move_context.h"
#endif

RGE_Action_Move_To::RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    *(void**)this = (void*)0x56E3A0;
    *(short*)((char*)this + 4) = 1;
    rge_read(param_1, &this->range, 4);
}
