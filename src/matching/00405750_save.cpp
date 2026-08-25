#ifndef ACT_MOVE_CANONICAL_TU
#include "../../include/act_move_context.h"
#endif

void __cdecl rge_write(int outfile, void* data, int size);

void RGE_Action_Move_To::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->range, 4);
}
