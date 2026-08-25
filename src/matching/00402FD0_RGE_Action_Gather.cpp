// VA: 00402FD0 RGE_Action_Gather::RGE_Action_Gather
// PDB source: ACT_GATH.cpp.  The shared module context owns the class ABI.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

RGE_Action_Gather::RGE_Action_Gather(int file, RGE_Task* task,
                                     float x, float y, float z)
    : RGE_Action(file, 1) {
    this->task = task;
    this->action_type = 5;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->targetType = -1;
}
