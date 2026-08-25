// 004056E0 RGE_Action_Move_To::~RGE_Action_Move_To
// FLAGS: /GX
// Attempt log:
// 1. Existing wide virtual surface gets exact +0x1C0/+0x1EC virtual offsets, but VC5 reorders vptr store after object load/EH state and routes base dtor through local thunk basin.
// 2. Declared base destructor only + volatile vtable_ptr: no improvement; vptr store still after object load/state.
// 3. Natural virtual destructor surface, let VC5 emit derived vptr restore.
// Canonical owner pass maps the observed +0x1C0 and +0x1EC calls to
// removeAllUserDefinedWaypoints(0) and stop_moving().

#ifndef ACT_MOVE_CANONICAL_TU
#include "../../include/act_move_context.h"
#endif

RGE_Action_Move_To::~RGE_Action_Move_To() {
    this->obj->removeAllUserDefinedWaypoints(0);
    this->obj->stop_moving();
}
